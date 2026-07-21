require 'babeltrace2'
require 'ze_library'
require 'set'
require 'ze_validator_zemodel'
require 'ze_validator_function_entry_exit_callbacks'
require 'ze_validator_state_object'
require 'yaml'
require 'json'

class StateObject
  attr_reader :state
  attr_reader :ze_thread_safety
  attr_reader :lock_shared_object_on_entry
  attr_reader :unlock_shared_object_on_exit
  attr_accessor :print_tracker
  attr_accessor :device_agnostic
  attr_accessor :performance
  attr_accessor :memory_in_transit
  attr_reader :device_properties
  def initialize(**opts)
    @deprecated = JSON.parse(File.read(File.join(DATADIR, 'ze_deprecated.json')))
    # Per-device command queue group topology (ordinal -> engine type + numQueues),
    # generated on a real device by the ze_device_property helper binary and
    # installed alongside the other data files. Loaded if present; validation that
    # does not depend on it still runs when the file is absent.
    @device_properties = load_device_properties

    #for supressing redundant error outputs
    @print_tracker = Hash.new { |h, k| h[k] = 0 }

    @deprecated.each do |api, (version, replacement)|
      @deprecated[api] = [version, replacement, false]
    end
    @performance = opts[:performance]
    @device_agnostic = opts[:device_agnostic]
    @state = Hash.new { |h, k| h[k] = ZEModel::Node.new(k) }
    @ze_thread_safety = YAML::load_file(File.join(DATADIR, 'ze_thread_safety.yaml'))
    @lock_shared_object_on_entry = Hash.new { |h, k| h[k] = [] }
    @unlock_shared_object_on_exit = Hash.new { |h, k| h[k] = [] }
    @init_called = Hash.new { |h, k| h[k] = false } #pid : init called status
    @memory_in_transit = Hash.new {|h,k| h[k] = []} #pid : [[mem, (src|dst)]] list of memories being transferred
    # @openend_command_lists = Hash.new {|h,k| h[k] = []} #command_list_handle : command_list_class
    @printed_init_error = false
    # ADDED: deferred command-list executions awaiting event completion.
    # zeCommandQueueExecuteCommandLists is asynchronous, so we do not check a
    # list's memory copies at execute time (the destination may only be allocated
    # later by another unit that then signals a wait-event). Instead each
    # submitted list becomes a ZEModel::DeferredUnit here and is advanced by
    # pump_deferred as events get signaled -- NO Ruby threads/fibers; it is a
    # plain cursor-based worklist driven by the single trace-consumption loop.
    @deferred_units = []
    # ADDED: bumped whenever an event transitions to signaled, so pump_deferred
    # knows something may have become unblocked and is worth another sweep.
    @signal_epoch = 0
    @ze_thread_safety.each { |api, objects|
      objects.each { |o|
        @lock_shared_object_on_entry[api].push( lambda { |state, ctx, defi|
                                    handle = defi[o.first]
                                    if handle.kind_of? Array
                                      handle.each { |h|
                                        # CHANGED: nil-guard -- find_object may
                                        # return nil for an unknown handle (e.g.
                                        # tracing started mid-stream); do not crash
                                        obj = state.find_object(ctx, o.last, h)
                                        obj.lock(state, ctx) if obj
                                      }
                                    else
                                      obj = state.find_object(ctx, o.last, handle)
                                      obj.lock(state, ctx) if obj
                                    end
                                  })
        @unlock_shared_object_on_exit[api].push( lambda { |state, ctx, defi|
                                   handle = state.find_param(ctx, o.first)
                                   if handle.kind_of? Array
                                     handle.each { |h|
                                       # CHANGED: nil-guard as above
                                       obj = state.find_object(ctx, o.last, h)
                                       obj.unlock(ctx) if obj
                                     }
                                   else
                                     obj = state.find_object(ctx, o.last, handle)
                                     obj.unlock(ctx) if obj
                                   end
                                 })
      }
    }

  end

  # Reads ze_device_property.json from DATADIR. Returns the parsed hash, or nil
  # if the file is missing or unparseable so the validator degrades gracefully.
  def load_device_properties
    path = File.join(DATADIR, 'ze_device_property.json')
    return nil unless File.file?(path)
    JSON.parse(File.read(path))
  rescue JSON::ParserError => e
    $stderr.puts "Warning: could not parse #{path}: #{e.message}"
    nil
  end

  # Look up a command queue group by ordinal. Without a device index it returns
  # the matching group from the first device (sufficient for homogeneous nodes).
  # Returns a hash like {"ordinal"=>1, "type"=>"copy", "numQueues"=>8} or nil.
  def command_queue_group(ordinal, device_index: nil)
    return nil unless @device_properties
    devices = @device_properties['devices'] || []
    devices = devices.select { |d| d['device_index'] == device_index } if device_index
    devices.each do |dev|
      group = (dev['command_queue_groups'] || []).find { |g| g['ordinal'] == ordinal }
      return group if group
    end
    nil
  end


  def get_last_entry(context)
    @state[context['hostname']].processes[context['vpid']].threads[context['vtid']].last_entry
  end

  def get_thread(context)
    @state[context['hostname']].processes[context['vpid']].threads[context['vtid']]
  end

  def get_process(context)
    @state[context['hostname']].processes[context['vpid']]
  end

  def check_last_entry(context)
    last_entry = get_last_entry(context)
    unless last_entry && last_entry.name == context['api']
      raise "Invalid State in #{context['api']}"
    end
  end


  # CHANGED: push a new call frame instead of overwriting a single slot, so a
  # traced API that calls another traced API on the same thread nests correctly.
  def set_last_entry(state, context, defi)
    get_thread(context).call_stack.push(ZEModel::ApiCall.new(context['api'], defi))
  end

  # CHANGED: pop the innermost frame on return, exposing the caller's frame (if
  # any) rather than clearing everything.
  def reset_last_entry(context)
    get_thread(context).call_stack.pop
  end

  def validate_result(defi)
    ZE::ZEResult.from_native(defi["zeResult"], nil) == :ZE_RESULT_SUCCESS
  end

  def get_handle_str(handle)
    '0x%016x' % handle
  end

  def get_proc_context_str(context)
    "#{context['hostname']} - #{context['vpid']}"
  end

  def get_api_context(context)
    "#{context['vtid']} in #{context['api']}"
  end

  def get_context_str(context)
    "#{get_proc_context_str(context)} - #{get_api_context(context)}"
  end

  def print_deprecation_warning(old_api)
    if @deprecated.include?(old_api) and @deprecated[old_api][2]
      deprecated_since = @deprecated[old_api][0]
      new_api = @deprecated[old_api][1]
      if deprecated_since == ""
        puts "#{old_api} is deprecated. Please use #{new_api} instead."
      else
        puts "#{old_api} is deprecated since #{deprecated_since}. Please use #{new_api} instead."
      end
    end
  end

  def print_portability_error(context,str)
    $stderr.puts "Level Zero Portability Error: on #{get_context_str(context)}: #{str}\n\n"
  end
  def print_performance_issue(context,str)
     $stderr.puts "Level Zero Performance Issue: on #{get_context_str(context)}: #{str}\n\n"
  end
  def print_usage_error(context, str)
    $stderr.puts "Level Zero Usage Error: on #{get_context_str(context)}: #{str}\n\n"
  end

  def print_crash_error(context, str)
    $stderr.puts "Level Zero Crash Error: on #{get_context_str(context)}: #{str}\n\n"
  end

  # ADDED: reporting channel for circular event dependency (deadlock). Uses the
  # process-level context because a deadlock spans multiple command lists/threads
  # rather than a single api call.
  def print_deadlock_error(context, str)
    $stderr.puts "Level Zero Deadlock: on #{get_proc_context_str(context)}: #{str}\n\n"
  end



  def print_leak_error(context, type, handle, memtypestr="")
    if memtypestr.empty?
      $stderr.puts "Level Zero Leak: on #{get_proc_context_str(context)}: #{type} #{get_handle_str(handle)}\n\n"
    else
      $stderr.puts "Level Zero Leak #{memtypestr}-memory: on #{get_proc_context_str(context)}: #{type} #{get_handle_str(handle)}\n\n"
    end
  end

  def raise_internal_error(context, str)
    raise "Invalid state #{get_context_str(context)}: #{str}"
  end

  def print_race_condition(context, other_context, type, handle)
    if @print_tracker["#{type}-#{get_handle_str(handle)}-#{get_api_context(other_context)}"] == 0
      @print_tracker["#{type}-#{get_handle_str(handle)}-#{get_api_context(other_context)}"] = 1
      print_usage_error(context, "concurrent acces to #{type} #{get_handle_str(handle)}, already held by #{get_api_context(other_context)}")
    end
  end

  def object_not_found(context, type, handle, sub_context = nil)
    raise_internal_error(context, "event_pool #{get_handle_str(handle)} not found#{sub_context ? " in #{sub_context}" : ""}")
  end

  def find_param(context, name)
    get_last_entry(context).params[name]
  end

  def find_objects(context, type)
    get_process(context).instance_variable_get("@#{type}s")
  end

  def find_object(context, type, handle)
    handle = find_param(context, handle) if handle.kind_of? String
    find_objects(context, type)[handle]
  end

  def to_struct(memory, klass)
    memory.size > 0 ? klass.new(FFI::MemoryPointer.from_string(memory)) : nil
  end

  # ============================================================================
  # ADDED: Event semantics + non-concurrent deferred-execution scheduler.
  #
  # zeCommandQueueExecuteCommandLists is asynchronous. Checking a list's memory
  # copies against the memory model at execute time gives false positives,
  # because a copy's destination may only be allocated by another unit that
  # signals a wait-event later. So each submitted command list is turned into a
  # ZEModel::DeferredUnit and its ops are replayed only as their wait-events
  # actually become signaled.
  #
  # There are NO Ruby threads or fibers. Each unit keeps an integer cursor into
  # its op list. pump_deferred repeatedly sweeps all units, advancing any unit
  # whose current op has all wait-events satisfied, and loops until a full sweep
  # makes no progress. A unit left parked on an unsatisfied op is simply waiting
  # for a future event (which arrives as later trace events are consumed).
  # ============================================================================

  # ADDED: look up an Event model object by raw handle. nil for a null/unknown
  # handle (nothing to track).
  def event_by_handle(context, handle)
    return nil if handle.nil? || handle == 0
    find_objects(context, 'event')[handle]
  end

  # ADDED: signal an event and note progress so pump_deferred re-sweeps. `by`
  # records who signaled it, for diagnostics.
  def signal_event(context, handle, by = nil)
    ev = event_by_handle(context, handle)
    if ev
      ev.signal(by)
      @signal_epoch += 1
    end
    ev
  end

  # ADDED: return an event to the unsignaled state.
  def reset_event(context, handle)
    event_by_handle(context, handle)&.reset
  end

  # ADDED: record that the host observed an event's signaled state.
  def observe_event(context, handle)
    event_by_handle(context, handle)&.observe
  end

  # ADDED: a device-wide host synchronization (zeCommandQueueSynchronize, or for
  # immediate lists zeCommandListHostSynchronize) means the host waited for all
  # submitted work -- so every currently-signaled event has been consumed. Mark
  # them observed so a later signal without a reset reads as reuse-without-reset
  # rather than a concurrent double-signal.
  def observe_all_signaled_events(context)
    find_objects(context, 'event').each_value { |ev| ev.observe if ev.signaled? }
  end

  # ADDED: true once every wait handle is signaled (or is null/unknown, which we
  # treat as satisfied: we cannot track it, and any unit may signal an event, so
  # we must not invent a deadlock).
  def waits_satisfied?(context, waits)
    return true if waits.nil? || waits.empty?
    waits.all? { |h| ev = event_by_handle(context, h); ev.nil? || ev.signaled? }
  end

  # ADDED: execute one op of a unit (the op is known to be runnable). Runs the
  # deferred checks, then applies the op's reset/signal side effects, and
  # advances the cursor. Returns true if it signaled an event (progress that may
  # unblock other units).
  def run_deferred_op(unit)
    context = unit.context
    op = unit.current_op
    check_oob_copy(self, context, op.params) if op.kind == :copy
    #a reset takes effect before this op signals its own completion event
    reset_event(context, op.params[:reset_handle]) if op.kind == :reset
    signaled = false
    if op.signal
      #the completion event must be unsignaled here: reuse without an intervening
      #reset (or a concurrent double-signal) is a misuse
      check_event_signal_reuse(self, context, op.signal, op.api || 'a command list append')
      signal_event(context, op.signal, op.api)
      unit.pending_signals.delete(op.signal)
      signaled = true
    end
    unit.cursor += 1
    unit.blocked_on = []
    signaled
  end

  # ADDED: advance every deferred unit as far as its wait-events allow. Sweeps
  # repeatedly until a whole pass makes no progress (completed an op or signaled
  # an event), then drops finished units. Units still parked on an unmet wait
  # stay queued for a future event or the end-of-trace flush.
  def pump_deferred
    progress = true
    while progress
      progress = false
      @deferred_units.each do |unit|
        until unit.done?
          op = unit.current_op
          if waits_satisfied?(unit.context, op.waits)
            run_deferred_op(unit)
            progress = true
          else
            #park the unit on this op and record what it is blocked on so the
            #deadlock detector can see the wait-for edges
            unit.blocked_on = op.waits.reject { |h|
              ev = event_by_handle(unit.context, h); ev.nil? || ev.signaled?
            }
            break
          end
        end
      end
      @deferred_units.reject!(&:done?)
    end
  end

  # ADDED: register a command list's ops as a deferred unit and pump. `ops` is a
  # snapshot (dup) taken by the caller so a later reset+re-append on the same
  # list cannot mutate an in-flight execution.
  def run_deferred_list(context, ops, label, in_order: false)
    @deferred_units << ZEModel::DeferredUnit.new(ops, context, label, in_order: in_order)
    pump_deferred
  end

  # ADDED: deferred execution of the lists submitted to
  # zeCommandQueueExecuteCommandLists. Each list becomes its OWN unit: lists in
  # one submit are ordered only by events, not by list order, so a circular
  # event dependency across two lists in one submit is a real deadlock we must be
  # able to see.
  def enqueue_deferred_execution(context, command_lists)
    command_lists.each do |cl|
      next unless cl
      run_deferred_list(context, cl.ops.dup, "command_list (#{get_handle_str(cl.handle)})",
                        in_order: cl.in_order)
    end
  end

  # ADDED: immediate command lists execute each op as it is appended, so we
  # schedule the single op immediately. It still honors wait-events and goes
  # through the same machinery, giving immediate lists the same OOB-copy and
  # event-reuse checks as regular lists.
  def enqueue_immediate_op(context, op, handle = nil)
    label = handle ? "immediate command list (#{get_handle_str(handle)})" \
                   : 'immediate command list'
    run_deferred_list(context, [op], label)
  end

  # ADDED: end-of-trace drain. First pump normally in case ordering left work
  # runnable. Whatever is still parked cannot progress on its own -- report any
  # circular event dependency (deadlock) among the stuck units, then force each
  # remaining unit's blocked op (reporting the never-signaled wait) so the
  # deferred checks still run against the final memory state.
  def flush_deferred
    pump_deferred
    return if @deferred_units.empty?
    check_circular_deadlock(self, @deferred_units)
    #ADDED: an in-order list where an earlier op waits on an event only a later op
    #in the SAME list signals is a self-deadlock the cross-list check cannot see
    check_in_order_self_deadlock(self, @deferred_units)
    until @deferred_units.empty?
      unit = @deferred_units.first
      #force the op the unit is stuck on: report its unsignaled waits, then run it
      report_unsignaled_waits(self, unit.context, unit.current_op.waits) if unit.current_op
      run_deferred_op(unit) unless unit.done?
      @deferred_units.reject!(&:done?)
      #a forced completion may unblock others cleanly
      pump_deferred
    end
  end

  def check_issues()
    #ADDED: drain deferred command-list executions (and detect deadlocks) before
    #reporting leaks/crashes
    flush_deferred
    crash = false
    @state.each { |hostname, node|
      node.processes.each { |pid, process|
        process.threads.each { |tid, thread|
          # CHANGED: iterate the whole call stack instead of a single slot. Any
          # frame still on the stack is a traced call that never returned (a
          # crash); a clean run pops every frame back to empty.
          thread.call_stack.each { |frame|
            ctx = {'hostname' => hostname, 'vpid'=> pid, 'vtid' => tid, 'api' => frame.name}
            print_crash_error(ctx, 'command did not finish execution')
            crash = true
          }
        }
      }
    }

    #if !crash || true
    unless crash && false
      @state.each { |hostname, node|
        node.processes.each { |pid, process|
          ctx = {'hostname' => hostname, 'vpid'=> pid}
          [ 'context',
            'event_pool',
            'command_queue',
            'fence',
            'command_list',
            'module',
            'module_build_log',
            'kernel',
            'memory_allocation',  #what type of memory allocation?
          ].each { |t|
            #objects that were created will be deleted upon successful exits.
            #So, only the ones that didn't get deleted will be reported
            process.objects(t).each { |h, c|
              if t == 'memory_allocation'
                #puts "mem alloc type = #{c.instance_variable_get(:@memtypestr)}"
                print_leak_error(ctx, t, h, c.instance_variable_get(:@memtypestr))
              else
                print_leak_error(ctx, t, h) #it prints the type as well
              end
            }
          }
        }
      }
    end
  end


  def check_initialization(context,m)
	if ZEModel::INIT_API_NAMES.include?(m[1])
        @init_called[context['vpid']] = true
    end

	if !@init_called[context['vpid']] && !@printed_init_error
		self.print_usage_error(context, "zeInit or zeDriversInit wasn't called before #{m[1]}")
		@printed_init_error = true
	end
  end


  def on_entry(m,hostname, context,defi)
    set_last_entry(self, context, defi) #sets the per-thread callstack of the APIs
      @lock_shared_object_on_entry[m[1]].each { |l|
                  l.call(self, context, defi)
      }
    #modifies the satate based on entry fields. Needed because some fields are easier to access it from the entry
    l = $upon_entry[m[1]]
    l.call(self,context,defi) if l
  end

  def on_exit(m,hostname,context,defi)
    #unlock the shared object if the api name matches the predefined in ze_thread_safety.yaml
    @unlock_shared_object_on_exit[m[1]].reverse_each { |l|
      l.call(self, context, defi)
    }

    #check if the return code indicates successful return from the API call
    if validate_result(defi)
      l = $on_successful_exit[m[1]] #This might be a problem for tracking erroneous exits.
      l.call(self, context, defi) if l
    else
      #puts "failed: #{m[1]}"
      l = $on_erroneous_exit[m[1]]
      l.call(self, context, defi) if l
    end

    check_last_entry(context)  #When we return from _exit, we need to see what we saw in _entry for the current thread_id
    reset_last_entry(context)  #Reset the callstack for current thread_id
  end

  def consume = lambda { |iterator, _|
        iterator.next_messages.each do |m|
          next unless m.type == :BT_MESSAGE_TYPE_EVENT
          e = m.event
          m = e.name.match(/:(z.*)_(entry|exit)/)
          if m
            hostname = e.stream.trace.get_environment_entry_value_by_name('hostname').value
            context = e.get_common_context_field.value
            defi = e.payload_field.value
            context['hostname'] = hostname
            context['api'] = m[1]
			      #zeDriversInit or zeInit must be the first one to be called before any api calls
            check_initialization(context,m)
            #print the known deprecated APIs
            print_deprecation_warning(m[1]) if @deprecated[m[1]]

            if m[2] == 'entry'
              on_entry(m, hostname, context, defi)
            elsif m[2] == 'exit'
              #puts "#{m[1]}"
              on_exit(m, hostname, context, defi)
            end
            #ADDED: this event may have signaled something a deferred command list
            #was waiting on, so advance the deferred worklist now
            pump_deferred
          end
        end
      }

end #end of StateObject
