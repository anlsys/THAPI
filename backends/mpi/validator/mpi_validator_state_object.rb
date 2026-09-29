# frozen_string_literal: true

# Per-thread call-stack tracking and callback dispatch, mirroring the structure
# of THAPI's ze_validator_state_object.rb.
#
# An _exit event carries only the return code, not the call's arguments, so we
# keep the matching _entry payload on a per-thread stack. Exit callbacks read it
# through find_param.

require 'mpi/validator/mpi_validator_function_entry_exit_callbacks'
require 'mpi/validator/mpi_objects'
MPI_SUCCESS = 0

# One frame of a thread's call stack: an _entry seen but not yet matched.
Entry = Struct.new(:name, :params, :timestamp, :api)

# Per-thread state: the call stack of APIs currently executing.
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
  def initialize
    @threads = Hash.new { |h, k| h[k] = ThreadState.new }
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
  def initialize(**opts)
    @communicators = Hash.new {}
    @options = opts
    @state = Hash.new { |h, k| h[k] = HostState.new }
    @issues = []
    @api_counts = Hash.new(0)
    @total_calls = 0
    @error_count = 0
    @unmatched_exits = 0
    @temp_counter=0
  end

  # --- per-thread call stack -----------------------------------------------

  def get_thread(context)
    @state[context['hostname']]
      .processes[context['vpid']]
      .threads[context['vtid']]
  end

  def get_host(contex)
    @state[context['hostname']]
  end

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
    entry && entry.params[name]
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

  # Events that are neither _entry nor _exit (e.g. lttng_ust_mpi_type:property).
  def on_other_event(name, context, payload)
    puts "[#{get_context_str(context)}] #{name}: #{payload.inspect}" if @options[:verbose]
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
    puts "counter = #{@temp_counter}"
    dangling_entries.each do |d|
      ctx = d.slice('hostname', 'vpid', 'vtid')
      print_usage_error(ctx,
                           "#{d['entry']['api']} entered but never returned")
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
