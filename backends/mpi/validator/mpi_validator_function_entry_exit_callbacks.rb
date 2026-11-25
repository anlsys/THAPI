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


# Entry checks run before the call could crash: validate arguments here.
$upon_entry['MPI_Send'] = lambda { |state, context, payload|
  comm = state.communicators[payload['comm']]
  dest_rank = payload['dest']
  unless comm
    state.print_usage_error(context, "Unknown communicator: #{payload['comm']} at MPI_Send")
    next
  end
  state.print_usage_error(context, "Rank out-of-bounds for MPI_Send. Communicator #{comm} must be [0,#{comm.num_ranks-1}]") if comm.num_ranks <= dest_rank
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
  state.persistent_messages[request] = PersistentMessage.new(context: context, buffer_ptr: buf, dest: dest, comm: comm,
                                                             request: request, count: count, partitions: partitions)  
}


$on_successful_exit['MPI_Send_init'] = lambda { |state, context, payload|
  buf = state.find_param(context, 'buf')
  #partitions = state.find_param(context, 'partitions')
  count = state.find_param(context, 'count')
  dest = state.find_param(context, 'dest')
  request = state.find_param(context, 'request')
  comm = state.communicators[state.find_param(context, 'comm')]
  state.persistent_messages[request] = PersistentMessage.new(context: context, buffer_ptr: buf, dest: dest, comm: comm,
                                                             request: request, count: count)  
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
    if bag_map.key?(pm.comm.handle)
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
    if bag_map.key?(pm.comm.handle)
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
}

$on_successful_exit['MPI_Ssend'] = lambda { |state, context, payload|
  comm = state.communicators[state.find_param(context, 'comm')]
  next unless comm # unknown communicator already reported at entry
  src_rank = state.get_thread(context).rank
  dest_rank = state.find_param(context, 'dest')
  buf_ptr = state.find_param(context, 'buf')
  tag = state.find_param(context, 'tag')
  dtype = state.find_param(context, 'datatype')
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

# Is data race possible with just the Strong memory operations?? (get precise definition of strong in ptx)
# Unless Comm_create is called, they are all the same communicator
$on_successful_exit['MPI_Comm_rank']=lambda { |state, context, payload|
  comm_ptr = state.find_param(context, 'comm')
  rank_val = payload['rank_val']
  unless state.communicators.key?(comm_ptr)
    state.communicators[comm_ptr] = Communicator.new(comm_ptr, context: context)
  end
  state.communicator_bags[state.bag_id][comm_ptr] = nil #make sure the comm create reflects the new bag_id
  state.comm_to_bag_map[comm_ptr] = state.bag_id
  state.communicators[comm_ptr].participating_ranks[context['vpid']] = rank_val
  
}


$on_successful_exit['MPI_Comm_size'] = lambda { |state, context, payload|
  comm_ptr = state.find_param(context, 'comm')
  state.communicators[comm_ptr] ||= Communicator.new(comm_ptr, context: context)
  state.communicators[comm_ptr].size = payload['size_val']
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





# Nonblocking request lifecycle (Isend/Irecv/..., Wait*/Test*, Start, Request_free):
# see the "Nonblocking requests" section at the end of this file.

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
  if  Datatype.predefined?(dtype)
    per_element_size = Datatype.size(dtype)
    count = payload['count']
    size = per_element_size*count
    buffer_size = state.get_process(context).user_buffer_size    
    buffer_addr = state.get_process(context).user_buffer_addr    
    state.print_usage_error(context, "Bsend size (#{size} bytes) exceeds the attached buffer (#{buffer_addr})'s size #{buffer_size}") if size > buffer_size

  end
}


# The tracegrind mem_accesses buffer-race check is in the "Nonblocking requests"
# section at the end of this file.

$on_erroneous_exit.default = lambda { |state, context, payload|
  args = state.get_last_entry(context)&.params
  detail = args && !args.empty? ? " (args: #{args.inspect})" : ''
  state.print_error_return(
    context, "#{context['api']} returned #{payload['mpiResult']}#{detail}"
  )
}

# ==============================================================================
# Nonblocking requests
#
# Nonblocking-communication validation: follows every MPI_Request from the call
# that creates it to the call that completes or frees it, and checks the user
# buffers attached to it while it is in flight. The objects involved (Request,
# NonblockingRequest, PersistentRequest, Buffer) are in mpi_objects.rb;
# the per-process RequestTable is in mpi_validator_state_object.rb.
#
# What is checked
#   * request leaks      -- a nonblocking request never completed by
#                           MPI_Wait*/MPI_Test* (or freed) before MPI_Finalize
#                           or the end of the trace; persistent requests never
#                           freed
#   * buffer overlap     -- a nonblocking (or blocking) call whose buffer
#                           overlaps the buffer of a request still in flight,
#                           when at least one side receives into it
#   * buffer race        -- the application touches an in-flight buffer
#                           (tracegrind mem_accesses): any access to a receive
#                           buffer, a store into a send buffer
#   * double completion  -- MPI_Wait/MPI_Test/MPI_Request_free on a handle that
#                           was already completed or freed
#   * persistent misuse  -- MPI_Start on an active request, or on a request
#                           that is not persistent
#   * questionable use   -- MPI_Request_free / MPI_Cancel on an active request,
#                           a request handle overwritten while still active
#                           (reported as warnings)
#
# How requests are matched
#   MPI_Wait, MPI_Test, MPI_Request_free, MPI_Cancel and MPI_Start record the
#   request handle itself (request_val), so those match exactly. The array
#   variants (Waitall, Testall, Waitany, Waitsome, Testany, Testsome, Startall)
#   record only the array's address, so a request is matched by the address it
#   was *stored* at (Request#slot). Waitany/Testany and Waitsome/Testsome
#   additionally need the completed index(es) (indx_val /
#   array_of_indices_vals); traces taken without them fall back to marking the
#   candidates uncertain, which silences reports about them rather than
#   guessing.
#
#   The request array itself is deliberately not recorded by the tracer: it is
#   compiled against the standard-ABI mpi.h (MPI_Request is a pointer, 8 bytes)
#   while Aurora runs classic-ABI MPICH (MPI_Request is an int, 4 bytes), so
#   reading count * 8 bytes would overrun the application's array.

MPI_UNDEFINED_VALUE = -32_766 # MPICH; returned in indx/outcount when nothing to do

module NonblockingValidation
  module_function

  # How to find the user buffers and the peer of a call:
  # [buffer param, count param, datatype param, mode, options] per buffer.
  # Options (collectives):
  #   root_only:  the buffer is only significant at the root
  #   times_size: count is per rank, so the buffer holds count * comm size
  LAYOUTS = {
    send: { buffers: [%w[buf count datatype send]], peer: 'dest', tag: 'tag' },
    recv: { buffers: [%w[buf count datatype recv]], peer: 'source', tag: 'tag' },
    mrecv: { buffers: [%w[buf count datatype recv]], peer: nil, tag: nil },
    sendrecv: { buffers: [%w[sendbuf sendcount sendtype send],
                          %w[recvbuf recvcount recvtype recv]],
                peer: 'dest', tag: 'sendtag' },
    # The single buffer is both sent from and received into: treat it as a
    # receive buffer, the stricter of the two.
    sendrecv_replace: { buffers: [%w[buf count datatype recv]], peer: 'dest', tag: 'sendtag' },
    psend: { buffers: [%w[buf count datatype send]], peer: 'dest', tag: 'tag', partitioned: true },
    precv: { buffers: [%w[buf count datatype recv]], peer: 'source', tag: 'tag', partitioned: true },
    # Gather: every rank sends sendcount; the root receives recvcount from each.
    gather: { buffers: [['sendbuf', 'sendcount', 'sendtype', 'send'],
                        ['recvbuf', 'recvcount', 'recvtype', 'recv', { root_only: true, times_size: true }]],
              peer: 'root', tag: nil },
    # Scatter: the root sends sendcount to each; every rank receives recvcount.
    scatter: { buffers: [['sendbuf', 'sendcount', 'sendtype', 'send', { root_only: true, times_size: true }],
                         ['recvbuf', 'recvcount', 'recvtype', 'recv']],
               peer: 'root', tag: nil }
  }.freeze

  NONBLOCKING_CALLS = {
    'MPI_Isend' => :send, 'MPI_Ibsend' => :send, 'MPI_Issend' => :send,
    'MPI_Irsend' => :send, 'MPI_Irecv' => :recv, 'MPI_Imrecv' => :mrecv,
    'MPI_Isendrecv' => :sendrecv, 'MPI_Isendrecv_replace' => :sendrecv_replace,
    'MPI_Igather' => :gather, 'MPI_Iscatter' => :scatter
  }.freeze

  PERSISTENT_CALLS = {
    'MPI_Send_init' => :send, 'MPI_Bsend_init' => :send, 'MPI_Ssend_init' => :send,
    'MPI_Rsend_init' => :send, 'MPI_Recv_init' => :recv,
    'MPI_Psend_init' => :psend, 'MPI_Precv_init' => :precv,
    'MPI_Gather_init' => :gather, 'MPI_Scatter_init' => :scatter
  }.freeze

  # Blocking calls whose buffers must not collide with in-flight requests.
  BLOCKING_CALLS = {
    'MPI_Send' => :send, 'MPI_Bsend' => :send, 'MPI_Ssend' => :send,
    'MPI_Rsend' => :send, 'MPI_Recv' => :recv, 'MPI_Mrecv' => :mrecv,
    'MPI_Sendrecv' => :sendrecv, 'MPI_Sendrecv_replace' => :sendrecv_replace,
    'MPI_Gather' => :gather, 'MPI_Scatter' => :scatter
  }.freeze

  # MPI_IN_PLACE as the application passes it: (void*)-1 in classic MPICH,
  # (void*)1 in the standard ABI.
  IN_PLACE = [0xffffffffffffffff, 1].freeze

  EXPLICIT = Set.new(NONBLOCKING_CALLS.keys + PERSISTENT_CALLS.keys).freeze

  def buffers_for(state, context, layout, api)
    params = state.get_all_params(context) || {}
    comm = state.communicators[params['comm']]
    layout[:buffers].filter_map do |buf_p, count_p, type_p, mode, opts|
      opts ||= {}
      addr = params[buf_p]
      next if addr.nil? || IN_PLACE.include?(addr)
      # Root-only buffers are skipped off the root, and when this process's
      # rank in the communicator is unknown (no MPI_Comm_rank on it).
      next if opts[:root_only] && !(comm && params['root'] &&
                                    comm.rank_of(context['vpid']) == params['root'])

      count = params[count_p]
      count *= params['partitions'] if count && layout[:partitioned] && params['partitions']
      if count && opts[:times_size]
        next unless comm&.size # unknown size: cannot bound the buffer

        count *= comm.size
      end
      Buffer.for_elements(addr, count, params[type_p], mode: mode, api: api, context: context)
    end
  end

  # Called on the successful exit of any call that hands back a request.
  # `request_class` is NonblockingRequest or PersistentRequest.
  def register(state, context, payload, api, request_class, layout = nil)
    handle = Request.normalize(payload['request_val'])
    return if Request.null?(handle)

    params = state.get_all_params(context) || {}
    slot = params['request']
    slot = nil if slot&.zero?
    table = state.requests(context)

    # The creating call is about to write the new handle into `slot`. If that
    # variable still held a live request, the old handle is gone unless the
    # application copied it somewhere first.
    if slot && (old = table.at_slot(slot)) && old.handle != handle && old.live?
      old.overwritten_by = "#{api} at #{context['timestamp']}"
    end

    # MPICH only reuses a handle once it is free, so an old entry under the
    # same handle is stale (completed by a call we could not resolve).
    if (stale = table[handle])
      table.remove(stale, 'reused')
    end

    req = request_class.new(
      handle, api: api, context: context, slot: slot,
              buffers: layout ? buffers_for(state, context, layout, api) : [],
              peer: layout && layout[:peer] ? params[layout[:peer]] : nil,
              tag: layout && layout[:tag] ? params[layout[:tag]] : nil,
              comm: params['comm']
    )
    check_overlap(state, context, req.in_flight_buffers, "#{api} request #{req.hex_handle}")
    table.insert(req)
  end

  # Report every in-flight buffer that `buffers` (about to be handed to MPI by
  # `who`) conflicts with.
  def check_overlap(state, context, buffers, who, exclude: nil)
    return if buffers.empty?

    state.inflight_buffers(context).each do |other|
      next if exclude && other.request.equal?(exclude)

      buffers.each do |b|
        next unless b.conflicts_with?(other)

        lo, hi = b.intersection(other.base_addr, other.upper_bound)
        state.print_race(
          context,
          "#{who} #{b.mode} buffer #{b.range_str} overlaps #{hi - lo} byte(s) of the " \
          "#{other.mode} buffer of in-flight #{other.api} request #{other.request.hex_handle} " \
          "#{other.range_str} -- the buffer belongs to MPI until that request completes"
        )
      end
    end
  end

  # A request completed by MPI_Wait*/MPI_Test*.
  def complete(state, context, req, how)
    state.requests(context).remove(req, "#{how} at #{context['timestamp']}") if req.complete!
  end

  def report_stale(state, context, handle, how)
    prev = state.requests(context).retired_reason(handle)
    return false unless prev

    state.print_usage_error(
      context,
      "#{how} on request #{MPIObject.hex(handle)}, which was already completed or freed " \
      "(#{prev}): the handle is stale and may now name another request"
    )
    true
  end

  def complete_handle(state, context, raw, how)
    handle = Request.normalize(raw)
    return if Request.null?(handle)

    req = state.requests(context)[handle]
    complete(state, context, req, how) if req
  end

  # Entry check for calls taking one request handle. Done at entry because
  # MPICH validates handles too: an erroneous call returns an error code, and
  # its exit takes the erroneous path where the success callbacks never run.
  def check_handle_at_entry(state, context, raw, how)
    handle = Request.normalize(raw)
    return nil if Request.null?(handle)

    req = state.requests(context)[handle]
    report_stale(state, context, handle, how) unless req
    req
  end

  def complete_range(state, context, base, count, how)
    state.requests(context).in_range(base, count).each do |req|
      complete(state, context, req, how) if req.active?
    end
  end

  # Index-reporting calls (Waitany, Waitsome, ...): complete the requests at
  # the given indices, or flag every candidate when the indices were not traced.
  def complete_indices(state, context, base, count, indices, how)
    candidates = state.requests(context).in_range(base, count)
    if indices
      indices.each do |i|
        next if i.nil? || i.negative? || i >= count

        req = candidates.find { |r| r.slot_index(base) == i }
        complete(state, context, req, how) if req
      end
    else
      candidates.each { |r| r.uncertain = true if r.active? }
    end
  end

  # Entry: may this request be started? (see check_handle_at_entry)
  def check_start(state, context, req, how)
    return true unless (why = req.start_error)

    state.print_usage_error(context, "#{how} on #{req}, #{why}")
    false
  end

  # Successful exit: the request is now active.
  def start(state, context, req, how)
    return unless req.persistent?

    req.start!(context)
    check_overlap(state, context, req.in_flight_buffers, "#{how} of #{req}", exclude: req)
  end

  # Requests a process still holds when it finalizes (or the trace ends).
  def report_outstanding(state, context, table, where)
    table.each do |req|
      next if req.uncertain

      overwritten = req.overwritten_by ? "; its MPI_Request variable was overwritten by #{req.overwritten_by}" : ''
      if req.active?
        buffer_note = req.buffers.empty? ? '' : ' and its buffer was never safely returned to the application'
        state.print_usage_error(
          context,
          "#{req} created at #{req.timestamp} was never completed: still active #{where} " \
          "with no matching MPI_Wait*/MPI_Test* -- the request leaked#{buffer_note}#{overwritten}"
        )
      elsif req.live?
        state.print_warning(context,
                            "persistent #{req} was never freed with MPI_Request_free " \
                            "(#{where})#{overwritten}")
      end
    end
  end
end

# ------------------------------------------------------------------------------
# Callbacks. Composed with whatever is already registered above for the same
# API, so the cross-rank checks keep working.

def chain_callback(table, api, &blk)
  prev = table[api]
  table[api] = if prev
                 lambda { |state, context, payload|
                   prev.call(state, context, payload)
                   blk.call(state, context, payload)
                 }
               else
                 blk
               end
end

NonblockingValidation::NONBLOCKING_CALLS.each do |api, layout|
  chain_callback($on_successful_exit, api) do |state, context, payload|
    NonblockingValidation.register(state, context, payload, api, NonblockingRequest,
                                   NonblockingValidation::LAYOUTS[layout])
  end
end

NonblockingValidation::PERSISTENT_CALLS.each do |api, layout|
  chain_callback($on_successful_exit, api) do |state, context, payload|
    NonblockingValidation.register(state, context, payload, api, PersistentRequest,
                                   NonblockingValidation::LAYOUTS[layout])
  end
end

NonblockingValidation::BLOCKING_CALLS.each do |api, layout|
  chain_callback($upon_entry, api) do |state, context, _payload|
    bufs = NonblockingValidation.buffers_for(state, context,
                                             NonblockingValidation::LAYOUTS[layout], api)
    NonblockingValidation.check_overlap(state, context, bufs, api)
  end
end

# Every other call that returns a request (nonblocking and persistent
# collectives, MPI_Comm_idup, MPI_File_i*, ...) is tracked without buffers, so
# leaks and double completion are still caught.
$on_request_created = lambda { |state, context, payload, api|
  next if NonblockingValidation::EXPLICIT.include?(api)

  klass = api.end_with?('_init') ? PersistentRequest : NonblockingRequest
  NonblockingValidation.register(state, context, payload, api, klass)
}

%w[MPI_Wait MPI_Test MPI_Cancel].each do |api|
  chain_callback($upon_entry, api) do |state, context, payload|
    NonblockingValidation.check_handle_at_entry(state, context, payload['request_val'], api)
  end
end

chain_callback($on_successful_exit, 'MPI_Wait') do |state, context, _payload|
  NonblockingValidation.complete_handle(state, context,
                                        state.find_param(context, 'request_val'), 'MPI_Wait')
end

chain_callback($on_successful_exit, 'MPI_Test') do |state, context, payload|
  next if payload['flag_val'].to_i.zero?

  NonblockingValidation.complete_handle(state, context,
                                        state.find_param(context, 'request_val'), 'MPI_Test')
end

chain_callback($on_successful_exit, 'MPI_Waitall') do |state, context, _payload|
  NonblockingValidation.complete_range(state, context,
                                       state.find_param(context, 'array_of_requests'),
                                       state.find_param(context, 'count'), 'MPI_Waitall')
end

chain_callback($on_successful_exit, 'MPI_Testall') do |state, context, payload|
  next if payload['flag_val'].to_i.zero? # nothing is completed unless all are

  NonblockingValidation.complete_range(state, context,
                                       state.find_param(context, 'array_of_requests'),
                                       state.find_param(context, 'count'), 'MPI_Testall')
end

any_handler = lambda { |api, needs_flag|
  lambda { |state, context, payload|
    next if needs_flag && payload['flag_val'].to_i.zero?

    indices = if payload.key?('indx_val')
                payload['indx_val'] == MPI_UNDEFINED_VALUE ? [] : [payload['indx_val']]
              end
    NonblockingValidation.complete_indices(state, context,
                                           state.find_param(context, 'array_of_requests'),
                                           state.find_param(context, 'count'), indices, api)
  }
}
chain_callback($on_successful_exit, 'MPI_Waitany', &any_handler.call('MPI_Waitany', false))
chain_callback($on_successful_exit, 'MPI_Testany', &any_handler.call('MPI_Testany', true))

some_handler = lambda { |api|
  lambda { |state, context, payload|
    outcount = payload['outcount_val']
    next if outcount.nil? || outcount == MPI_UNDEFINED_VALUE || outcount <= 0

    base = state.find_param(context, 'array_of_requests')
    incount = state.find_param(context, 'incount')
    indices = payload['array_of_indices_vals']
    if indices.nil?
      # Without the indices we still know the answer when every candidate
      # finished.
      active = state.requests(context).in_range(base, incount).select(&:active?)
      indices = active.map { |r| r.slot_index(base) } if active.size == outcount
    end
    NonblockingValidation.complete_indices(state, context, base, incount, indices, api)
  }
}
chain_callback($on_successful_exit, 'MPI_Waitsome', &some_handler.call('MPI_Waitsome'))
chain_callback($on_successful_exit, 'MPI_Testsome', &some_handler.call('MPI_Testsome'))

# Freeing is checked at entry: the handle is still valid then.
chain_callback($upon_entry, 'MPI_Request_free') do |state, context, payload|
  req = NonblockingValidation.check_handle_at_entry(state, context, payload['request_val'],
                                                    'MPI_Request_free')
  if req&.in_flight?
    state.print_warning(
      context,
      "MPI_Request_free on active #{req}: the operation still runs, but the " \
      'application can no longer tell when its buffer may be reused'
    )
  end
end

chain_callback($on_successful_exit, 'MPI_Request_free') do |state, context, _payload|
  h = Request.normalize(state.find_param(context, 'request_val'))
  table = state.requests(context)
  req = table[h]
  table.remove(req, "MPI_Request_free at #{context['timestamp']}") if req
end

chain_callback($on_successful_exit, 'MPI_Cancel') do |state, context, _payload|
  h = Request.normalize(state.find_param(context, 'request_val'))
  req = state.requests(context)[h]
  next unless req

  req.cancelled = true
  if req.sends?
    state.print_warning(context,
                        "MPI_Cancel on send #{req}: cancelling sends is " \
                        'deprecated in MPI-4 and may not succeed')
  end
end

chain_callback($upon_entry, 'MPI_Start') do |state, context, payload|
  req = NonblockingValidation.check_handle_at_entry(state, context, payload['request_val'],
                                                    'MPI_Start')
  NonblockingValidation.check_start(state, context, req, 'MPI_Start') if req
end

chain_callback($on_successful_exit, 'MPI_Start') do |state, context, _payload|
  req = state.requests(context)[Request.normalize(state.find_param(context, 'request_val'))]
  NonblockingValidation.start(state, context, req, 'MPI_Start') if req
end

chain_callback($upon_entry, 'MPI_Startall') do |state, context, payload|
  state.requests(context).in_range(payload['array_of_requests'], payload['count']).each do |req|
    NonblockingValidation.check_start(state, context, req, 'MPI_Startall')
  end
end

chain_callback($on_successful_exit, 'MPI_Startall') do |state, context, _payload|
  state.requests(context).in_range(state.find_param(context, 'array_of_requests'),
                                   state.find_param(context, 'count')).each do |req|
    NonblockingValidation.start(state, context, req, 'MPI_Startall')
  end
end

chain_callback($upon_entry, 'MPI_Finalize') do |state, context, _payload|
  table = state.requests(context)
  NonblockingValidation.report_outstanding(state, context, table, 'at MPI_Finalize')
  table.clear
  state.finalized_processes << [context['hostname'], context['vpid']]
end

# Tracegrind reports the memory the application touched between MPI calls, as
# flat [start, end) pairs. Buffer#races_with_access? decides what is a race.
$on_other_event['lttng_ust_tracegrind:mem_accesses'] = lambda { |state, context, payload|
  buffers = state.inflight_buffers(context)
  next if buffers.empty?

  table = state.requests(context)
  { 'stores' => 'wrote', 'loads' => 'read' }.each do |field, verb|
    addrs = payload[field]
    next if addrs.nil? || addrs.empty?

    addrs.each_slice(2) do |start, stop|
      next if start.nil? || stop.nil? || stop <= start

      buffers.each do |b|
        next unless b.races_with_access?(start, stop, write: verb == 'wrote')
        next unless table.first_race?(b.request, verb)

        lo, hi = b.intersection(start, stop)
        state.print_race(
          context,
          "application #{verb} #{hi - lo} byte(s) at #{MPIObject.hex(lo)} " \
          "(#{b.position_of(lo)} of the #{b.size}-byte #{b.mode} buffer at #{b.hex_handle}) " \
          "while #{b.api} request #{b.request.hex_handle} is still in flight " \
          '-- the buffer belongs to MPI until the request completes'
        )
      end
    end
  end
}
