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
  def initialize(**opts)
    @deprecated = JSON.parse(File.read(File.join(DATADIR, 'ze_deprecated.json')))
    #@print_once = opts[:print_once]
    @print_tracker = Hash.new { |h, k| h[k] = 0 }
    #add a third field to indicate whether the deprecation warning has been printed or not
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
    @printed_init_error = false
    @ze_thread_safety.each { |api, objects|
      objects.each { |o|
        @lock_shared_object_on_entry[api].push( lambda { |state, ctx, defi|
                                    handle = defi[o.first]
                                    if handle.kind_of? Array
                                      handle.each { |h|
                                        state.find_object(ctx, o.last, h).lock(state, ctx)
                                      }
                                    else
                                      state.find_object(ctx, o.last, handle).lock(state, ctx)
                                    end
                                  })
        @unlock_shared_object_on_exit[api].push( lambda { |state, ctx, defi|
                                   handle = state.find_param(ctx, o.first)
                                   if handle.kind_of? Array
                                     handle.each { |h|
                                       state.find_object(ctx, o.last, h).unlock(ctx)
                                     }
                                   else
                                     state.find_object(ctx, o.last, handle).unlock(ctx)
                                   end
                                 })
      }
    }

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


  def set_last_entry(state, context, defi)
    get_thread(context).last_entry = ZEModel::ApiCall.new(context['api'], defi)
  end
  
  def reset_last_entry(context)
    get_thread(context).last_entry = nil
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
    print_usage_error(context, "concurent acces to #{type} #{get_handle_str(handle)}, already held by #{get_api_context(other_context)}")
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

  def check_issues()
    crash = false
    @state.each { |hostname, node|
      node.processes.each { |pid, process|
        process.threads.each { |tid, thread|
          if thread.last_entry #because successful return from the call stack should have set this field to nil
            ctx = {'hostname' => hostname, 'vpid'=> pid, 'vtid' => tid, 'api' => thread.last_entry.name}
            print_crash_error(ctx, 'command did not finish execution') #typo?
            crash = true
          end
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
		l = $on_successful_exit[m[1]]
		l.call(self, context, defi) if l
	else
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
            if  m[2] == 'entry'
              on_entry(m, hostname, context, defi)
            else
              on_exit(m, hostname, context, defi)
            end
          end
        end
      }
    
end #end of StateObject
