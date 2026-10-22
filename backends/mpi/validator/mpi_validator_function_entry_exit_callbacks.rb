require 'mpi/validator/mpi_objects'

$upon_entry = {}
$on_successful_exit = {}
$on_erroneous_exit = {}
# Events that are neither _entry nor _exit, keyed by full event name.
$on_other_event = {}

make_scatter_gather_key = lambda {|state|
  sendcount = state.find_param(context, 'sendcount')
  sendtype = state.find_param(context, 'sendtype')
  recvcount = state.find_param(context, 'recvcount')
  recvtype = state.find_param(context, 'recvtype')
  root = state.find_param(context, 'root')
  comm = state.find_param(context, 'comm')
  bag_id = state.comm_to_bag_map[comm]
  "#{sendcount}-#{sendtype}-#{recvcount}-#{recvtype}-#{root}-#{bag_id}"
}

register_inflight = lambda { |state, context, payload, api, _exit|
  key = nil
  if payload['request_val']
    key = payload['request_val']
  elsif !payload
    key = payload.to_s
  end
  
  next if key == "{}"

  buf = state.find_param(context, 'buf')
  count = state.find_param(context, 'count')
  dtype = state.find_param(context, 'datatype')
  next unless buf && count

  elem_size = MPIDatatype.size(dtype)
  next if elem_size.nil? || elem_size.zero?
  
  peer = nil
  tag = nil
  if _exit 
    peer = state.find_param(context, api.match?(/.*[sS]end/) ? 'dest' : 'source')
    tag = state.find_param(context, 'tag')
  else
    peer = api.match?(/.*[sS]end/) ? payload['dest'] : payload['source']
    tag = payload['tag']
  end
  
  state.add_inflight(context,
                     InflightBuffer.new(context, api, key,
                                        buf, buf + (count * elem_size),
                                        count, dtype, context['timestamp'],
                                        peer, tag))
}

# Entry checks run before the call could crash: validate arguments here.
$upon_entry['MPI_Send'] = lambda { |state, context, payload|
  comm = state.communicators[payload['comm']]
  dest_rank = payload['dest']
  unless comm
    state.print_usage_error(context, "Unknown communicator: #{payload['comm']} at MPI_Send")
    next
  end
  state.print_usage_error(context, "Rank out-of-bounds for MPI_Send. Communicator #{comm} must be [0,#{comm.num_ranks-1}]") if comm.num_ranks <= dest_rank
  register_inflight.call(state, context, payload, 'MPI_Send')
}


$on_successful_exit['MPI_Gather'] = lambda { |state, context, payload|
  send_count = state.find_param(context, 'sendcount')
  recv_count = state.find_param(context, 'recvcount')
  comm = state.find_param(context, 'comm')
  root = state.find_param(context, 'root')
  
  gather_key = make_scatter_gather_key.call(state)
  state.gather_map[gather_key][0] += 1
  state.gather_map[gather_key] += [context, comm] if state.gather_map[gather_key].size < 2

  sendtype = state.find_param(context, 'sendtype')
  recvtype = state.find_param(context, 'recvtype')
  rank = state.communicators[comm].participating_ranks[context['vpid']]
  if rank && rank == root && recv_count != send_count && sendtype == recvtype 
    state.print_usage_error(context,"Receive count differs from the send count at MPI_Gather using the communicator #{comm}")
  end 
}


$on_successful_exit['MPI_Allgather'] = lambda { |state, context, payload|
  send_count = state.find_param(context, 'sendcount')
  recv_count = state.find_param(context, 'recvcount')
  comm = state.find_param(context, 'comm')

  sendtype = state.find_param(context, 'sendtype')
  recvtype = state.find_param(context, 'recvtype')
  if recv_count != send_count && sendtype == recvtype 
    state.print_usage_error(context,"Receive count differs from the send count at MPI_Allgather using the communicator #{comm}")
  end 
}

$on_successful_exit['MPI_Scatter'] = lambda { |state, context, payload|
  send_count = state.find_param(context, 'sendcount')
  recv_count = state.find_param(context, 'recvcount')
  comm = state.find_param(context, 'comm')
  sendtype = state.find_param(context, 'sendtype')
  recvtype = state.find_param(context, 'recvtype')
  scatter_key = make_scatter_gather_key.call(state)
  state.scatter_map[scatter_key][0] += 1
  state.scatter_map[scatter_key] += [context,comm] if state.scatter_map[scatter_key].size < 2
  if recv_count > send_count && sendtype == recvtype
    state.print_usage_error(context,"Receive count cannot be larger than the send count at MPI_Scatter using the communicator #{comm}")
  end 
}

$on_successful_exit['MPI_Psend_init'] = lambda { |state, context, payload|
  buf = state.find_param(context, 'buf')
  partitions = state.find_param(context, 'partitions')
  count = state.find_param(context, 'count')
  dest = state.find_param(context, 'dest')
  request = state.find_param(context, 'request')
  comm = state.communicators[state.find_param(context, 'comm')]
  state.persistent_messages[request] = PersistentMessage.new(buf,dest, comm, request, partitions, count,context)  
}


$on_successful_exit['MPI_Send_init'] = lambda { |state, context, payload|
  buf = state.find_param(context, 'buf')
  #partitions = state.find_param(context, 'partitions')
  count = state.find_param(context, 'count')
  dest = state.find_param(context, 'dest')
  request = state.find_param(context, 'request')
  comm = state.communicators[state.find_param(context, 'comm')]
  state.persistent_messages[request] = PersistentMessage.new(buf,dest, comm, request, 0, count,context)  
}


$on_successful_exit['MPI_Recv_init'] = lambda { |state, context, payload|
  comm_ptr = state.find_param(context, 'comm')
  bag_map = nil
  state.communicator_bags.each do |key, bag|
    if bag.key?(comm_ptr)
      bag_map = bag
      break
    end
  end
  state.persistent_messages.each do |key, pm|
    if bag_map.key?(pm.comm.base)
      pm.recv_initialized = true
      break
    end 
  end
}

$on_successful_exit['MPI_Precv_init'] = lambda { |state, context, payload|
  comm_ptr = state.find_param(context, 'comm')
  bag_map = nil
  state.communicator_bags.each do |key, bag|
    if bag.key?(comm_ptr)
      bag_map = bag
      break
    end
  end
  state.persistent_messages.each do |key, pm|
    if bag_map.key?(pm.comm.base)
      pm.recv_initialized = true
      break
    end 
  end
}

$on_successful_exit['MPI_Test'] = lambda { |state, context, payload|
  request = state.find_param(context, 'request')
  pm = state.persistent_messages[request]
  pm.test_called = true if pm
}


$upon_entry['MPI_Ssend'] = lambda { |state, context, payload|
  comm = state.communicators[payload['comm']]
  dest_rank = payload['dest']
  unless comm
    state.print_usage_error(context, "Unknown communicator: #{payload['comm']} at MPI_Send")
    next
  end
  state.print_usage_error(context, "Rank out-of-bounds for MPI_Ssend. Communicator #{comm} must be [0,#{comm.num_ranks-1}]") if comm.num_ranks <= dest_rank
  register_inflight.call(state, context, payload, 'MPI_Ssend')
}

$on_successful_exit['MPI_Ssend'] = lambda { |state, context, payload|
  comm = state.communicators[state.find_param(context, 'comm')]
  next unless comm # unknown communicator already reported at entry
  src_rank = state.get_thread(context).rank
  dest_rank = state.find_param(context, 'dest')
  buf_ptr = state.find_param(context, 'buf')
  tag = state.find_param(context, 'tag')
  dtype = state.find_param(context, 'datatype')
  key = state.get_all_params(context).to_s
  state.delete_inflight(context, key)
}

$on_successful_exit['MPI_Send'] = lambda { |state, context, payload|
  comm = state.communicators[state.find_param(context, 'comm')]
  next unless comm # unknown communicator already reported at entry
  src_rank = state.get_thread(context).rank
  dest_rank = state.find_param(context, 'dest')
  buf_ptr = state.find_param(context, 'buf')
  tag = state.find_param(context, 'tag')
  dtype = state.find_param(context, 'datatype')
  key = state.get_all_params(context).to_s
  state.delete_inflight(context, key)
  comm.send(context,src_rank,dest_rank,tag,buf_ptr,dtype)
  
}

# Is data race possible with just the Strong memory operations?? (get precise definition of strong in ptx)
# Unless Comm_create is called, they are all the same communicator
$on_successful_exit['MPI_Comm_rank']=lambda { |state, context, payload|
  comm_ptr = state.find_param(context, 'comm')
  rank_val = payload['rank_val']
  unless state.communicators.key?(comm_ptr)
    state.communicators[comm_ptr] = Communicator.new(comm_ptr)
  end
  state.communicator_bags[state.bag_id][comm_ptr] = nil #make sure the comm create reflects the new bag_id
  state.comm_to_bag_map[comm_ptr] = state.bag_id
  state.communicators[comm_ptr].participating_ranks[context['vpid']] = rank_val
  
}


$on_successful_exit['MPI_Bcast']=lambda { |state, context, payload|
  comm_ptr = state.find_param(context, 'comm')
  comm = state.communicators[comm_ptr]
  root = state.find_param(context, 'root')
  buffer_count = state.find_param(context, 'count')
  buffer_type = state.find_param(context, 'datatype')

  comm.record_bcast(context, context['vpid'], root, buffer_count, buffer_type)
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





$on_successful_exit['MPI_Isend'] = lambda {|state, context, payload|
  register_inflight.call(state, context, payload, 'MPI_Isend', true)
}
$on_successful_exit['MPI_Irecv'] = lambda {|state, context, payload|
  register_inflight.call(state, context, payload, 'MPI_Irecv',true)
}

$on_successful_exit['MPI_Issend'] = lambda {|state, context, payload|
  register_inflight.call(state, context, payload, 'MPI_Iseend', true)
}

$on_successful_exit['MPI_Irsend'] = lambda {|state, context, payload|
  register_inflight.call(state, context, payload, 'MPI_Irsend', true)
}

$on_successful_exit['MPI_Ibsend'] = lambda {|state, context, payload|
  register_inflight.call(state, context, payload, 'MPI_Ibsend', true)
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

#Write a test for this as well
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
