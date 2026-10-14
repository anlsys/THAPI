require 'mpi/validator/mpi_validator_function_entry_exit_callbacks'
require 'mpi/validator/mpi_objects'
MPI_SUCCESS = 0

Entry = Struct.new(:name, :params, :timestamp, :api)

class ThreadState
  attr_accessor :stack
  attr_reader :rank
  def initialize
    @stack = []
    @rank = -1
  end
  
  def set_rank(rank)
    @rank = rank
  end
end


class ProcessState
  attr_reader :threads
  attr_reader :inflight
  attr_reader :user_buffer_size
  attr_reader :user_buffer_addr
  def initialize
    @threads = Hash.new { |h, k| h[k] = ThreadState.new }
    @inflight = {}
    @user_buffer_size = -1
    @user_buffer_addr = nil
  end
  
  def set_user_buffer(addr, size)
    @user_buffer_addr = addr
    @user_buffer_size = size
  end
  def free_user_buffer(addr)
    if addr == @user_buffer_addr
      @user_buffer_addr = nil
      @user_buffer_size = -1
    end
  end
end

class HostState
  attr_reader :processes
  def initialize
    @processes = Hash.new {|h, k| h[k] = ProcessState.new}
  end

  def num_procs
    @processes.size
  end

end

class StateObject
  attr_reader :issues
  attr_accessor :communicators
  attr_accessor :partitioned_sends
  def initialize(**opts)
    @communicators = Hash.new {}
    @options = opts
    @partitioned_messages = {}
    @state = Hash.new { |h, k| h[k] = HostState.new }
    @issues = []
    @api_counts = Hash.new(0)
    @total_calls = 0
    @error_count = 0
    @unmatched_exits = 0
    @temp_counter=0
  end


  def get_thread(context)
    @state[context['hostname']]
      .processes[context['vpid']]
      .threads[context['vtid']]
  end

  def get_host(contex)
    @state[context['hostname']]
  end

  def get_process(context)
    @state[context['hostname']].processes[context['vpid']]
  end


  def add_inflight(context, record)
    get_process(context).inflight[record.request] = record
  end

  def delete_inflight(context, request)
    return nil unless request
    get_process(context).inflight.delete(request)
  end

  def inflight_buffers(context)
    get_process(context).inflight.values
  end

  def print_race(context, str) = report(context, 'BUFFER RACE', str)

  def get_stack_top(context)
    stack = get_thread(context).stack
    stack.last
  end

  # The erroneous-exit callbacks reach for the frame of the call that just
  # failed under this name; it is the same thing as the top of the stack,
  # since the exit has not been popped yet when the callback runs.
  alias get_last_entry get_stack_top

  def push_to_stack(context, payload, name)
    get_thread(context).stack << Entry.new(context['api'], payload, context['timestamp'], name)
    @temp_counter += 1
  end

  def pop_stack(context)
    get_thread(context).stack.pop
    @temp_counter -= 1
  end

  # Reads an argument of the call currently executing. Valid in _entry and in
  # _exit too, since the entry payload is still on the stack.
  def find_param(context, name)
    entry = get_stack_top(context)
    entry ? entry.params[name] : nil
  end
  
  def get_all_params(context)
    entry = get_stack_top(context) 
    entry ? entry.params : nil
  end 
  # --- reporting ------------------------------------------------------------

  def get_context_str(context)
    "#{context['hostname']}:#{context['vpid']}:#{context['vtid']}"
  end

  def report(context, kind, str)
    msg = "#{kind} [#{get_context_str(context)}] #{str}"
    @issues << msg
    warn msg
  end

  def print_usage_error(context, str)    = report(context, 'USAGE ERROR', str)
  def print_error_return(context, str)   = report(context, 'ERROR', str)
 

  # Decides whether on_exit runs the success or the error callback.
  def validate_result(payload)
    payload['mpiResult'].nil? || payload['mpiResult'] == MPI_SUCCESS
  end

  # --- dispatch -------------------------------------------------------------

  def on_entry(api, context, payload)
    push_to_stack(context, payload, api)
    @api_counts[api] += 1
    @total_calls += 1
    if @options[:verbose]
      puts "[#{get_context_str(context)}] #{api} entry: #{payload.inspect}"
    end

    l = $upon_entry[api]
    l&.call(self, context, payload)
  end

  def on_exit(api, context, payload)
    if @options[:verbose]
      entry = get_stack_top(context)
      elapsed = if entry&.timestamp && context['timestamp']
                  format(' (%d ns)', context['timestamp'] - entry.timestamp)
                else
                  ''
                end
      puts "[#{get_context_str(context)}] #{api} exit: #{payload.inspect}#{elapsed}"
    end

    if validate_result(payload)
      l = $on_successful_exit[api]
      l&.call(self, context, payload)
    else
      @error_count += 1
      l = $on_erroneous_exit[api]
      l&.call(self, context, payload)
    end
    pop_stack(context)
  end

  # Events that are neither _entry nor _exit (e.g. lttng_ust_mpi_type:property,
  # lttng_ust_tracegrind:mem_accesses).
  def on_other_event(name, context, payload)
    if @options[:verbose]
      # A mem_accesses payload holds up to 16384 addresses; inspecting it
      # verbatim would bury the rest of the output. Summarize those instead.
      summary = if payload.key?('n_loads') || payload.key?('n_stores')
                  format('{seq=%s chunk=%s n_loads=%s n_stores=%s}',
                         payload['seq'], payload['chunk'],
                         payload['n_loads'], payload['n_stores'])
                else
                  payload.inspect
                end
      puts "[#{get_context_str(context)}] #{name}: #{summary}"
    end
    l = $on_other_event[name]
    l&.call(self, context, payload)
  end

  def consume
    lambda { |iterator, _|
      iterator.next_messages.each do |m|
        next unless m.type == :BT_MESSAGE_TYPE_EVENT
        e = m.event
        match = e.name.match(/\Alttng_ust_mpi:(.*)_(entry|exit)\z/)
        hostname = e.stream.trace
                    .get_environment_entry_value_by_name('hostname').value
        context = e.get_common_context_field&.value || {}
        context['hostname'] = hostname
        context['timestamp'] = begin
          m.get_default_clock_snapshot.ns_from_origin
        rescue StandardError
          nil
        end
        payload = e.payload_field&.value || {}
        if match
          context['api'] = match[1]
          if match[2] == 'entry'
            on_entry(match[1], context, payload)
          else
            on_exit(match[1], context, payload)
          end
        else
          on_other_event(e.name, context, payload)
        end
      end
    }
  end

  # --- end of trace ---------------------------------------------------------

  # Entry frames still on a stack when the trace ends: calls that never returned.
  def dangling_entries
    result = []
    @state.each do |hostname, host|
      host.processes.each do |vpid, process|
        process.threads.each do |vtid, thread|
          next unless thread.stack
          thread.stack.each do |stack_entry|
            result << { 'hostname' => hostname, 'vpid' => vpid, 'vtid' => vtid,
                        'entry' => stack_entry}
          end
        end
      end
    end
    result
  end

  # Called once after the graph drains. Returns the process exit code.
  def check_issues
    puts "my counter = #{@temp_counter}"
    dangling_entries.each do |d|
      ctx = d.slice('hostname', 'vpid', 'vtid')
      print_usage_error(ctx,
                           "#{d['entry']['api']} entered but never returned")
    end

    # Requests still in flight when the trace ends: never waited on, so the
    # buffer was never returned to the application and the request leaked.
    @state.each do |hostname, host|
      host.processes.each do |vpid, process|
        process.inflight.each_value do |b|
          ctx = { 'hostname' => hostname, 'vpid' => vpid, 'vtid' => vpid }
          print_usage_error(ctx,
                            "#{b.api} request 0x#{b.request.to_s(16)} " \
                            "(buffer 0x#{b.lo.to_s(16)}, #{b.size} bytes) " \
                            'was never completed: no matching MPI_Wait/MPI_Test')
        end
      end
    end

    communicators.each do |k, comm|
      comm.sends.each do |key, record|
        puts "MPI_Send at rank #{record[:from]} to dst=#{record[:to]} with tag=#{:tag}"
        print_usage_error(record[:context], "MPI_Send from rank #{record[:from]} to dst=#{record[:to]} with tag=#{:tag} doesn't have a matching MPI_Recv") unless comm.recvs[key]
      end

      comm.recvs.each do |key, record|
        puts "MPI_Recv at rank #{record[:to]} from dst=#{record[:from]} with tag=#{:tag}"
        print_usage_error(record[:context], "MPI_Recv at rank #{record[:to]} from dst=#{record[:from]} with tag=#{:tag} doesn't have a matching MPI_Send") unless comm.sends[key]
      end
      comm.bcasts.each do |key, record|
        ctx = record[record.keys.sample] 
        print_usage_error(ctx, "MPI_Bcast has only #{record.size} participating ranks. System expects #{comm.participating_ranks.size} ranks to properly broadcast the message") if record.size < comm.participating_ranks.size
      end   
    end
    puts "\n--- summary ---"
    puts format('%d MPI calls across %d distinct APIs',
                @total_calls, @api_counts.size)
    @api_counts.sort.each { |api, count| puts format('  %-32s %d', api, count) }
    puts format('%d erroneous return%s', @error_count,
                @error_count == 1 ? '' : 's')
    puts format('%d issue%s', @issues.size, @issues.size == 1 ? '' : 's')

    @issues.empty? ? 0 : 1
  end
end
