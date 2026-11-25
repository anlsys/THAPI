require 'mpi/validator/mpi_validator_function_entry_exit_callbacks'
require 'mpi/validator/mpi_objects'
require 'set'
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


# The live requests of one process, indexed by handle and by the address of
# the MPI_Request variable holding them.
class RequestTable
  include Enumerable

  # A completed handle is remembered so that a second completion through a
  # copy of the handle can be reported; MPICH recycles handles, so this is
  # bounded and a re-issued handle simply replaces the stale entry.
  RETIRED_LIMIT = 4096

  attr_reader :suppressed_races

  def initialize
    @requests = {}            # handle -> Request
    @slots = {}               # slot address -> handle
    @retired = {}             # handle -> "MPI_Wait at <ts>"
    @reported_races = Set.new
    @suppressed_races = 0
  end

  def [](handle) = @requests[handle]

  def each(&) = @requests.each_value(&)

  def in_flight_buffers = flat_map(&:in_flight_buffers)

  def insert(req)
    @retired.delete(req.handle)
    @requests[req.handle] = req
    @slots[req.slot] = req.handle if req.slot
  end

  # Request whose handle currently lives at `slot`, if we know of one.
  def at_slot(slot)
    h = @slots[slot]
    h && @requests[h]
  end

  # Requests whose MPI_Request variable is still inside [base, base + count).
  def in_range(base, count)
    select { |r| r.in_slot_range?(base, count) && @slots[r.slot] == r.handle }
  end

  def remove(req, why)
    @requests.delete(req.handle)
    @slots.delete(req.slot) if req.slot && @slots[req.slot] == req.handle
    @retired.shift while @retired.size >= RETIRED_LIMIT
    @retired[req.handle] = why
  end

  def retired_reason(handle) = @retired[handle]

  # True the first time a (request, mode of access) race is seen.
  def first_race?(req, verb)
    return true if @reported_races.add?([req.handle, verb])

    @suppressed_races += 1
    false
  end

  def clear
    @requests.clear
    @slots.clear
  end
end

# A process can have a buffer attached with MPI_Buffer_attach (see
# AttachedBufferOwner, shared with Communicator) and owns its requests.
class ProcessState
  include AttachedBufferOwner

  attr_reader :threads, :requests

  def initialize
    @threads = Hash.new { |h, k| h[k] = ThreadState.new }
    @requests = RequestTable.new
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
  attr_reader :issues, :warnings, :finalized_processes
  attr_accessor :bag_id
  attr_accessor :communicator_bags
  attr_accessor :communicators
  attr_accessor :persistent_messages
  attr_accessor :scatter_map
  attr_accessor :gather_map
  attr_accessor :comm_to_bag_map
  def initialize(**opts)
    @communicators = Hash.new {}
    @options = opts
    @persistent_messages = {}
    @state = Hash.new { |h, k| h[k] = HostState.new }
    @issues = []
    @warnings = []
    @finalized_processes = Set.new
    @api_counts = Hash.new(0)
    @total_calls = 0
    @error_count = 0
    @unmatched_exits = 0
    @temp_counter = 0
    @bag_id = 0
    @comm_to_bag_map = {}
    @scatter_map = Hash.new {|h,k| h[k] = [0]}
    @gather_map = Hash.new {|h,k| h[k] = [0]}
    @communicator_bags = Hash.new {|h,k| h[k] = {}}
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


  def requests(context) = get_process(context).requests

  # Buffers MPI owns right now in this process.
  def inflight_buffers(context) = requests(context).in_flight_buffers

  def each_process
    @state.each do |hostname, host|
      host.processes.each { |vpid, process| yield hostname, vpid, process }
    end
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

  # Printed, but not counted as an issue: does not change the exit code.
  def print_warning(context, str)
    msg = "WARNING [#{get_context_str(context)}] #{str}"
    @warnings << msg
    warn msg
  end
 

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
      # Any call that hands back a request (OutScalar request -> request_val)
      $on_request_created&.call(self, context, payload, api) if payload.key?('request_val')
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

    # Requests still held when the trace ends (processes that reached
    # MPI_Finalize were already checked there).
    each_process do |hostname, vpid, process|
      next if finalized_processes.include?([hostname, vpid])

      ctx = { 'hostname' => hostname, 'vpid' => vpid, 'vtid' => vpid }
      NonblockingValidation.report_outstanding(self, ctx, process.requests,
                                               'at the end of the trace')
    end
    persistent_messages.each do |request, msg|
      print_usage_error(msg.context, "MPI_Test was not called for a persistent message") unless msg.test_called
      print_usage_error(msg.context, "Corresponding receiver was not initialized for a persistent message") unless msg.recv_initialized
    end
    scatter_map.each do |k,arr|
      sl = k.split("-")
      signature = "sendcount(#{sl[0]})-sendtype(#{sl[1]})-recvcount(#{sl[2]})-recvtype(#{sl[3]})-root(#{sl[4]})-comm(#{arr[2]})"
      print_usage_error(arr[1], "At most 1 rank sent MPI_Scatter with signature #{signature}")if arr[0] <= 1
    end

    
    gather_map.each do |k,arr|
      sl = k.split("-")
      signature = "sendcount(#{sl[0]})-sendtype(#{sl[1]})-recvcount(#{sl[2]})-recvtype(#{sl[3]})-root(#{sl[4]})-comm(#{arr[2]})"
      print_usage_error(arr[1], "At most 1 rank sent MPI_Gather with signature #{signature}")if arr[0] <= 1
    end
    
    communicators.each do |k, comm|
      comm.sends.each do |key, record|
        print_usage_error(record.context, "MPI_Send from rank #{record.from} to dst=#{record.to} with tag=#{record.tag} doesn't have a matching MPI_Recv in the #{comm}") unless comm.recvs[key]
      end

      comm.recvs.each do |key, record|
        puts "MPI_Recv at rank #{record.to} from dst=#{record.from} with tag=#{record.tag}"
        print_usage_error(record.context, "MPI_Recv at rank #{record.to} from dst=#{record.from} with tag=#{record.tag} doesn't have a matching MPI_Send in the #{comm}") unless comm.sends[key]
      end
      comm.bcasts.each do |key, record|
        ctx = record[record.keys.sample] 
        print_usage_error(ctx, "MPI_Bcast has only #{record.size} participating ranks. System expects #{comm.participating_ranks.size} ranks to properly broadcast the message in the #{comm}") if record.size < comm.participating_ranks.size
      end   
    end
    puts "\n--- summary ---"
    puts format('%d MPI calls across %d distinct APIs',
                @total_calls, @api_counts.size)
    @api_counts.sort.each { |api, count| puts format('  %-32s %d', api, count) }
    puts format('%d erroneous return%s', @error_count,
                @error_count == 1 ? '' : 's')
    puts format('%d issue%s', @issues.size, @issues.size == 1 ? '' : 's')
    puts format('%d warning%s', @warnings.size, @warnings.size == 1 ? '' : 's')
    suppressed = 0
    each_process { |_h, _p, process| suppressed += process.requests.suppressed_races }
    puts format('%d repeated buffer race%s on already-reported requests not shown',
                suppressed, suppressed == 1 ? '' : 's') if suppressed.positive?

    @issues.empty? ? 0 : 1
  end
end
