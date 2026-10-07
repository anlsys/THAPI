require 'mpi/validator/mpi_objects'

$upon_entry = {}
$on_successful_exit = {}
$on_erroneous_exit = {}
# Events that are neither _entry nor _exit, keyed by full event name.
$on_other_event = {}


# Entry checks run before the call could crash: validate arguments here.
$upon_entry['MPI_Send'] = lambda { |state, context, payload|
  comm = state.communicators[payload['comm']]
  dest_rank = payload['dest']
  # An unknown communicator is already an error; without this `next` the
  # following line dereferences nil and takes the whole run down with
  # "undefined method `num_ranks' for nil".
  unless comm
    state.print_usage_error(context, "Unknown communicator: #{payload['comm']} at MPI_Send")
    next
  end
  state.print_usage_error(context, "Rank out-of-bounds for MPI_Send. Communicator #{comm} must be [0,#{comm.num_ranks-1}]") if comm.num_ranks <= dest_rank
}

$on_successful_exit['MPI_Send'] = lambda { |state, context, payload|
  comm = state.communicators[state.find_param(context, 'comm')]
  next unless comm # unknown communicator already reported at entry
  src_rank = state.get_thread(context).rank
  dest_rank = state.find_param(context, 'dest')
  buf_ptr = state.find_param(context, 'buf')
  tag = state.find_param(context, 'tag')
  dtype = state.find_param(context, 'datatype')
  comm.send(context,src_rank,dest_rank,tag,buf_ptr,dtype)
}

# Careful with differentiating ranks/processes
# TODO: try to kill the process responsible for the application it self
# Is data race possible with just the Strong memory operations?? (get precise definition of strong in ptx)
# Create a tag for the ze_validator for AE  
$on_successful_exit['MPI_Comm_size']= lambda { |state, context, payload|
  size = payload['size_val']
  comm = state.find_param(context, 'comm')
  state.communicators[comm]= Communicator.new(payload['comm'], size)
  puts "size = #{size}"
}

$on_successful_exit['MPI_Comm_rank']=lambda { |state, context, payload|
  thread = state.get_thread(context)
  puts "payload for rank = #{payload}"
  thread.set_rank(payload['rank_val']) if payload['rank_val']
}

$upon_entry['MPI_Comm_rank']=lambda { |state, context, payload|
  puts "payload for rank (entry) = #{payload}"
}


$on_successful_exit['MPI_Recv'] = lambda { |state, context, payload|
  comm = state.communicators[state.find_param(context, 'comm')]
  next unless comm # unknown communicator already reported at entry
  src_rank = state.find_param(context, 'source')
  dest_rank = state.get_thread(context).rank
  buf_ptr = state.find_param(context, 'buf')
  tag = state.find_param(context, 'tag')
  dtype = state.find_param(context, 'datatype')
  comm.recv(context,src_rank,dest_rank,tag,buf_ptr,dtype)
}



register_inflight = lambda { |state, context, payload, api|
  request = payload['request_val']
  next if request.nil? || request.zero?

  buf = state.find_param(context, 'buf')
  count = state.find_param(context, 'count')
  dtype = state.find_param(context, 'datatype')
  next unless buf && count

  elem_size = MPIDatatype.size(dtype)
  next if elem_size.nil? || elem_size.zero?
  state.add_inflight(context,
                     InflightBuffer.new(context, api, request,
                                        buf, buf + (count * elem_size),
                                        count, dtype, context['timestamp'],
                                        state.find_param(context, api == 'MPI_Isend' ? 'dest' : 'source'),
                                        state.find_param(context, 'tag')))
}


$on_successful_exit['MPI_Isend'] = lambda {|state, context, payload|
  register_inflight.call(state, context, payload, 'MPI_Isend')
}
$on_successful_exit['MPI_Irecv'] = lambda {|state, context, payload|
  register_inflight.call(state, context, payload, 'MPI_Irecv')
}

$on_successful_exit['MPI_Issend'] = lambda {|state, context, payload|
  register_inflight.call(state, context, payload, 'MPI_Iseend')
}

$on_successful_exit['MPI_Irsend'] = lambda {|state, context, payload|
  register_inflight.call(state, context, payload, 'MPI_Irsend')
}

$on_successful_exit['MPI_Ibsend'] = lambda {|state, context, payload|
  register_inflight.call(state, context, payload, 'MPI_Ibsend')
}


$on_successful_exit['MPI_Wait'] = lambda {|state, context, payload|
  state.delete_inflight(context, state.find_param(context,'request_val')) if payload['flag_val'] != 0
}

$on_successful_exit['MPI_Request_free'] = lambda {|state, context, payload|
  state.delete_inflight(context, state.find_param(context,'request_val')) if payload['flag_val'] != 0
}


$on_successful_exit['MPI_Waitall'] = lambda {|state, context, payload|
  state.get_process(context).inflight.clear if payload['flag_val'] != 0
}

$on_successful_exit['MPI_Testall'] = lambda {|state, context, payload|
  state.get_process(context).inflight.clear if payload['flag_val'] != 0
}

$on_successful_exit['MPI_Buffer_detach'] = lambda {|state, context, payload|
  buffer = state.find_param(context, 'buffer_addr')
  process = state.get_process(context)
  process.free_user_buffer(buffer)
}


$on_successful_exit['MPI_Comm_attach_buffer'] = lambda {|state, context, payload|
  comm_ptr = state.find_param(context, 'comm')
  buffer = state.find_param(context, 'buffer')
  buffer_size= state.find_param(context, 'size')
  communicator = state.communicators[comm_ptr]
  communicator.set_user_buffer(buffer,buffer_size) if comm_ptr && buffer && buffer_size
}

$on_successful_exit['MPI_Comm_detach_buffer'] = lambda {|state, context, payload|
  buffer = state.find_param(context, 'buffer_addr')
  comm_ptr = state.find_param(context, 'comm')
  communicator = state.communicators[comm_ptr]
  communicator.free_user_buffer(buffer) if buffer && comm_ptr && communicator
}

$on_successful_exit['MPI_Buffer_attach'] = lambda{|state, context, payload|
  buffer = state.find_param(context,'buffer')
  buffer_size = state.find_param(context,'size')
  state.get_process(context).set_user_buffer(buffer, buffer_size) if buffer && buffer_size
  puts "process buffer = #{state.get_process(context).user_buffer_size}"
}


$upon_entry['MPI_Bsend'] = lambda{|state, context, payload|
  #only the primitive data types are supported
  dtype = payload['datatype']
  if  MPIDatatype.predefined?(dtype)
    per_element_size = MPIDatatype.size(dtype)
    count = payload['count']
    size = per_element_size*count
    buffer_size = state.get_process(context).user_buffer_size    
    buffer_addr = state.get_process(context).user_buffer_addr    
    state.print_usage_error(context, "Bsend size (#{size} bytes) exceeds the attached buffer (#{buffer_addr})'s size #{buffer_size}") if size > buffer_size

  end
}


# Tracegrind reports the memory touched between MPI calls, as flat [start, end)
$on_other_event['lttng_ust_tracegrind:mem_accesses'] = lambda { |state, context, payload|
  buffers = state.inflight_buffers(context)
  next if buffers.empty?

  { 'stores' => 'wrote', 'loads' => 'read' }.each do |field, verb|
    addrs = payload[field]
    next if addrs.nil? || addrs.empty?

    # Flat array of alternating start/end addresses.
    addrs.each_slice(2) do |start, _end|
      next if start && _end
      buffers.each do |b|
        next unless b.overlaps?(start, _end)
        next if verb == 'read' && b.api != 'MPI_Irecv'
        elem_size = MPIDatatype.size(b.dtype)
        idx = b.element_index(start, elem_size)
        where = idx ? "element [#{idx}]" : "offset +#{start - b.base_addr}"
        state.print_race(
          context,
          "application #{verb} #{_end - start} byte(s) at 0x#{from.to_s(16)} " \
          "(#{where} of the #{b.size}-byte buffer at 0x#{b.base_addr.to_s(16)}) " \
          "while #{b.api} request 0x#{b.request.to_s(16)} is still in flight " \
          '-- the buffer belongs to MPI until the request completes'
        )
      end
    end
  end
}

$on_erroneous_exit.default = lambda { |state, context, payload|
  args = state.get_last_entry(context)&.params
  detail = args && !args.empty? ? " (args: #{args.inspect})" : ''
  state.print_error_return(
    context, "#{context['api']} returned #{payload['mpiResult']}#{detail}"
  )
}
