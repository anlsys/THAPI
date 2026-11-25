# frozen_string_literal: true

require 'ze/validator/semantics'
require 'ze/validator/model'
require 'ze_library'

require 'ze/validator/framework'

module ZEValidator
  HANDLERS = Registry.new
end

def register_level_zero_handler(*names, handler)
  names.each do |name|
    ZEValidator::HANDLERS.register(:action, name) do |env, _args|
      handler.call(env[:state], env[:context], env[:payload])
    end
  end
end

# these two record only that the app asked, for the portability checks
register_level_zero_handler('level_zero.zeDeviceGetProperties.success', lambda { |state, ctx, _payload|
  device_ptr = state.find_param(ctx, 'hDevice')
  devices = state.find_objects(ctx, 'device')
  devices[device_ptr].property_fetched = true
})
# Mark that the queue group property was queried.
register_level_zero_handler('level_zero.zeDeviceGetCommandQueueGroupProperties.success', lambda { |state, ctx, _payload|
  device_ptr = state.find_param(ctx, 'hDevice')
  devices = state.find_objects(ctx, 'device')
  devices[device_ptr].cmd_queue_group_properties_queried = true
})

# For every append API below: validation at entry (the call may crash),
# recording at exit (only a successful append will ever execute).
register_level_zero_handler('level_zero.zeCommandListAppendLaunchKernel.entry', lambda { |state, ctx, payload|
  # Retrieve the compute ordinal from the command list
  command_lists = state.find_objects(ctx, 'command_list')
  cmd_list = command_lists[payload['hCommandList']]
  cqg_ordinal = cmd_list ? cmd_list.queue_group_ordinal : 0
  # both checks must run even if the launch later aborts
  check_valid_ordinal(state, ctx, payload, cqg_ordinal, cmd_list)
  check_kernel_created(state, ctx, payload)
  # the kernel's module must be on the same context as the command list
  check_kernel_list_context_match(state, ctx, payload)
})

register_level_zero_handler('level_zero.zeCommandListAppendLaunchKernel.success', lambda { |state, ctx, _payload|
  record_op(state, ctx, state.find_param(ctx, 'hCommandList'),
            ZEModel::RecordedOp.new(:launch,
                                    signal: state.find_param(ctx, 'hSignalEvent'),
                                    waits: wait_event_handles(state, ctx),
                                    api: 'zeCommandListAppendLaunchKernel'))
})

register_level_zero_handler('level_zero.zeCommandListReset.entry', lambda { |state, ctx, payload|
  check_command_list_reset(state, ctx, payload)
})

# on success the list is empty and open again, so clear the recorded ops.
# In-flight executions are unaffected: they snapshotted the ops at submit time.
register_level_zero_handler('level_zero.zeCommandListReset.success', lambda { |state, ctx, _payload|
  command_lists = state.find_objects(ctx, 'command_list')
  cmd_list = command_lists[state.find_param(ctx, 'hCommandList')]
  if cmd_list
    cmd_list.ops.clear
    cmd_list.status = ZEModel::CommandList.class_variable_get(:@@INITIALIZED)
  end
})

# check_command_list_closed later verifies this happened before any submission
register_level_zero_handler('level_zero.zeCommandListClose.success', lambda { |state, ctx, _payload|
  command_lists = state.find_objects(ctx, 'command_list')
  command_list_handle = state.find_param(ctx, 'hCommandList')
  cmd_list = command_lists[command_list_handle]
  cmd_list.status = ZEModel::CommandList.class_variable_get(:@@CLOSED)
})

register_level_zero_handler('level_zero.zeCommandListAppendLaunchCooperativeKernel.entry', lambda { |state, ctx, payload|
  command_lists = state.find_objects(ctx, 'command_list')
  cmd_list = command_lists[payload['hCommandList']]
  check_group_property_queued(state, ctx, payload, cmd_list.device) if cmd_list
  # the kernel's module must be on the same context as the command list
  check_kernel_list_context_match(state, ctx, payload)
})

register_level_zero_handler('level_zero.zeCommandListAppendLaunchCooperativeKernel.success', lambda { |state, ctx, _payload|
  record_op(state, ctx, state.find_param(ctx, 'hCommandList'),
            ZEModel::RecordedOp.new(:launch,
                                    signal: state.find_param(ctx, 'hSignalEvent'),
                                    waits: wait_event_handles(state, ctx),
                                    api: 'zeCommandListAppendLaunchCooperativeKernel'))
})

# Copy/event ops are recorded in list order for deferred replay. The
# out-of-bounds check waits until the op's wait-events are satisfied.
register_level_zero_handler('level_zero.zeCommandListAppendMemoryCopy.entry', lambda { |state, ctx, payload|
  params = { api: 'zeCommandListAppendMemoryCopy',
             ctx_handle: cmd_list_ctx_handle(state, ctx, payload['hCommandList']),
             dst: payload['dstptr'], src: payload['srcptr'], size: payload['size'] }
  waits = wait_event_handles(state, ctx)
  check_null_copy_ptr(state, ctx, 'zeCommandListAppendMemoryCopy',
                      { 'destination' => payload['dstptr'], 'source' => payload['srcptr'] })
  check_use_after_free_on_append(state, ctx, params, waits)
  # an out-of-bounds copy can crash the driver, which emits no _exit
  check_oob_copy_on_append(state, ctx, params, waits)
  # known memory endpoints must be allocated on the command list's context
  check_copy_ptr_list_context(state, ctx, 'zeCommandListAppendMemoryCopy', payload['hCommandList'],
                              { 'destination' => payload['dstptr'], 'source' => payload['srcptr'] })
})

register_level_zero_handler('level_zero.zeCommandListAppendMemoryFill.entry', lambda { |state, ctx, payload|
  params = { api: 'zeCommandListAppendMemoryFill',
             ctx_handle: cmd_list_ctx_handle(state, ctx, payload['hCommandList']),
             dst: payload['ptr'], src: nil, size: payload['size'] }
  waits = wait_event_handles(state, ctx)
  check_null_copy_ptr(state, ctx, 'zeCommandListAppendMemoryFill',
                      { 'destination' => payload['ptr'] })
  check_use_after_free_on_append(state, ctx, params, waits)
  # an out-of-bounds fill can crash the driver, which emits no _exit
  check_oob_copy_on_append(state, ctx, params, waits)
  # known memory endpoint must be allocated on the command list's context
  check_copy_ptr_list_context(state, ctx, 'zeCommandListAppendMemoryFill', payload['hCommandList'],
                              { 'destination' => payload['ptr'] })
})

register_level_zero_handler('level_zero.zeCommandListAppendMemoryCopy.success', lambda { |state, ctx, _payload|
  record_copy_op(state, ctx, 'zeCommandListAppendMemoryCopy', 'dstptr', 'srcptr')
})

register_level_zero_handler('level_zero.zeCommandListAppendMemoryFill.success', lambda { |state, ctx, _payload|
  # a fill only touches the destination; model it as a copy with no source
  record_copy_op(state, ctx, 'zeCommandListAppendMemoryFill', 'ptr', nil)
})

# A failed append is never recorded, so the deferred check would never see it,
# but the copy is out-of-bounds regardless of the error code. Check it here.
register_level_zero_handler('level_zero.zeCommandListAppendMemoryCopy.error', lambda { |state, ctx, _payload|
  params = { api: 'zeCommandListAppendMemoryCopy',
             ctx_handle: cmd_list_ctx_handle(state, ctx, state.find_param(ctx, 'hCommandList')),
             dst: state.find_param(ctx, 'dstptr'),
             src: state.find_param(ctx, 'srcptr'),
             size: state.find_param(ctx, 'size') }
  check_oob_copy(state, ctx, params)
  check_use_after_free(state, ctx, params)
})

register_level_zero_handler('level_zero.zeCommandListAppendMemoryFill.error', lambda { |state, ctx, _payload|
  params = { api: 'zeCommandListAppendMemoryFill',
             ctx_handle: cmd_list_ctx_handle(state, ctx, state.find_param(ctx, 'hCommandList')),
             dst: state.find_param(ctx, 'ptr'),
             src: nil,
             size: state.find_param(ctx, 'size') }
  check_oob_copy(state, ctx, params)
  check_use_after_free(state, ctx, params)
})

# region copies carry 2D/3D extents, so `size` is not a flat byte count; we only
# record ordering + event effects and skip the flat OOB comparison
register_level_zero_handler('level_zero.zeCommandListAppendMemoryCopyRegion.success', lambda { |state, ctx, _payload|
  record_op(state, ctx, state.find_param(ctx, 'hCommandList'),
            ZEModel::RecordedOp.new(:launch,
                                    signal: state.find_param(ctx, 'hSignalEvent'),
                                    waits: wait_event_handles(state, ctx),
                                    api: 'zeCommandListAppendMemoryCopyRegion'))
})

# A device-side signal: the event is signaled when this op executes (after waits).
register_level_zero_handler('level_zero.zeCommandListAppendSignalEvent.success', lambda { |state, ctx, _payload|
  record_op(state, ctx, state.find_param(ctx, 'hCommandList'),
            ZEModel::RecordedOp.new(:signal, signal: state.find_param(ctx, 'hEvent'),
                                             api: 'zeCommandListAppendSignalEvent'))
})

# A device-side wait: this op blocks the list until phEvents are signaled.
register_level_zero_handler('level_zero.zeCommandListAppendWaitOnEvents.success', lambda { |state, ctx, _payload|
  record_op(state, ctx, state.find_param(ctx, 'hCommandList'),
            ZEModel::RecordedOp.new(:wait, waits: wait_event_handles(state, ctx),
                                           api: 'zeCommandListAppendWaitOnEvents'))
})

# A device-side reset: returns the event to unsignaled when this op executes.
register_level_zero_handler('level_zero.zeCommandListAppendEventReset.success', lambda { |state, ctx, _payload|
  record_op(state, ctx, state.find_param(ctx, 'hCommandList'),
            ZEModel::RecordedOp.new(:reset, params: { reset_handle: state.find_param(ctx, 'hEvent') }))
})

# A barrier waits on its events and signals its completion event.
register_level_zero_handler('level_zero.zeCommandListAppendBarrier.success', lambda { |state, ctx, _payload|
  record_op(state, ctx, state.find_param(ctx, 'hCommandList'),
            ZEModel::RecordedOp.new(:barrier,
                                    signal: state.find_param(ctx, 'hSignalEvent'),
                                    waits: wait_event_handles(state, ctx),
                                    api: 'zeCommandListAppendBarrier'))
})

# Same event semantics as a plain barrier, plus the memory ranges it names,
# which are validated when the barrier executes (check_uaf_ranges_barrier).
register_level_zero_handler('level_zero.zeCommandListAppendMemoryRangesBarrier.success', lambda { |state, ctx, _payload|
  record_ranges_barrier_op(state, ctx)
})

# host-side event operations, effective immediately in trace order
register_level_zero_handler('level_zero.zeEventHostSignal.success', lambda { |state, ctx, _payload|
  handle = state.find_param(ctx, 'hEvent')
  check_event_signal_reuse(state, ctx, handle, 'zeEventHostSignal')
  state.signal_event(ctx, handle, 'zeEventHostSignal')
})

register_level_zero_handler('level_zero.zeEventHostReset.success', lambda { |state, ctx, _payload|
  state.reset_event(ctx, state.find_param(ctx, 'hEvent'))
})

# does not signal the event, only records that the signaled state was consumed
register_level_zero_handler('level_zero.zeEventHostSynchronize.success', lambda { |state, ctx, _payload|
  state.observe_event(ctx, state.find_param(ctx, 'hEvent'))
})

# A successful status query also observes the signaled state.
register_level_zero_handler('level_zero.zeEventQueryStatus.success', lambda { |state, ctx, _payload|
  state.observe_event(ctx, state.find_param(ctx, 'hEvent'))
})

# the host waited for all submitted work, so every signaled event was consumed
register_level_zero_handler('level_zero.zeCommandQueueSynchronize.success', lambda { |state, ctx, _payload|
  state.observe_all_signaled_events(ctx)
})

register_level_zero_handler('level_zero.zeCommandListHostSynchronize.success', lambda { |state, ctx, _payload|
  state.observe_all_signaled_events(ctx)
})

# Submission is where the queue, the lists, their events and the fence are
# So the same context checkings between those objects are called here.
register_level_zero_handler('level_zero.zeCommandQueueExecuteCommandLists.entry', lambda { |state, ctx, payload|
  command_queues = state.find_objects(ctx, 'command_queue')
  command_queue_handle = payload['hCommandQueue']
  command_queue = command_queues[command_queue_handle]

  # check if any command list is null
  check_valid_command_lists(state, ctx, payload)
  check_valid_command_queue(state, ctx, payload, command_queues, command_queue_handle)
  # Check if command list was closed before executing it on the queue
  # ignore if it is the first execute call
  check_command_list_closed(state, ctx, payload)
  check_fence_misuse(state, ctx, payload)

  known_command_lists = state.find_objects(ctx, 'command_list')
  command_list_handles = payload['phCommandLists_vals'] || []

  fences = state.find_objects(ctx, 'fence')
  fence_handle = payload['hFence']
  fence = fences[fence_handle]

  if fence
    fence.status = fence.in_use # set this at the entry so that other command lists can view it
  end

  if command_queue
    puts "queue at execution #{command_queue}"
    check_group_property_queued(state, ctx, payload, command_queue.device)
    check_fence_and_queue_compatibility(state, ctx, payload, command_queue, fence)
    command_list_handles.each do |command_list_handle|
      check_list_and_queue_have_matching_context(state, ctx, payload, known_command_lists[command_list_handle], command_queue)
      check_list_and_fence_have_matching_context(state, ctx, payload, known_command_lists[command_list_handle], fence)
      # a list with a compute kernel launch must not go to a copy-only queue
      check_copy_only_queue_submission(state, ctx, command_queue, known_command_lists[command_list_handle])
      # events used by the list must come from a pool on the queue's context
      check_event_pool_list_context_match(state, ctx, known_command_lists[command_list_handle])
    end
  end
  # an unknown queue was already reported by check_valid_command_queue above;
  # the deferred execution below still runs so the lists get their checks
})

# Execute is asynchronous, so each submitted list becomes a deferred unit and
# its copies are checked when their wait-events are signaled, not here.
register_level_zero_handler('level_zero.zeCommandQueueExecuteCommandLists.success', lambda { |state, ctx, _payload|
  known_command_lists = state.find_objects(ctx, 'command_list')
  command_list_handles = state.find_param(ctx, 'phCommandLists_vals') || []
  command_lists = command_list_handles.map { |h| known_command_lists[h] }
  state.enqueue_deferred_execution(ctx, command_lists)
})

# When a fence signals the host, set the fence's status to signaled
register_level_zero_handler('level_zero.zeFenceHostSynchronize.success', lambda { |state, ctx, _payload|
  fence_handle = state.find_param(ctx, 'hFence')
  fence = get_fence(state, ctx, fence_handle)
  if fence
    check_fence_sync_without_reset(state, ctx, fence_handle, fence)
    fence.status = fence.signaled
  else
    state.report(:null_fence_handle, ctx, 'a null fence was used for zeFenceHostSynchronize')
  end
})

# should a double reset be considered as a usage error?
# Also, a fence can be shared throughout the threads and is modeled correctly (if you are wondering about whether the model treats fence associated with different thread-id differently).
register_level_zero_handler('level_zero.zeFenceReset.entry', lambda { |state, ctx, payload|
  curr_fence = get_fence(state, ctx, payload['hFence'])
  curr_fence.status = curr_fence.not_signaled if curr_fence
})

# Set the driver for the current context
register_level_zero_handler('level_zero.zeDriverGet.success', lambda { |state, ctx, payload|
  drivers = state.get_process(ctx).drivers
  payload['phDrivers_vals'].each do |h|
    drivers[h] = ZEModel::Driver.new(h) unless drivers[h]
  end
})

register_level_zero_handler('level_zero.zeDeviceGet.success', lambda { |state, ctx, payload|
  devices = state.find_objects(ctx, 'device')
  driver = state.find_object(ctx, 'driver', 'hDriver')
  if driver
    payload['phDevices_vals'].each do |h|
      unless devices[h]
        devices[h] = ZEModel::Device.new(h)
        driver.devices.push devices[h]
      end
    end
  end
})

register_level_zero_handler('level_zero.zeDeviceGetSubDevices.success', lambda { |state, ctx, payload|
  devices = state.find_objects(ctx, 'device')
  device = state.find_object(ctx, 'device', 'hDevice')
  payload['phSubdevices_vals'].each do |h|
    unless devices[h]
      devices[h] = ZEModel::SubDevice.new(h, device)
      device.sub_devices.push devices[h]
    end
  end
})

register_level_zero_handler('level_zero.zeContextCreate.success', lambda { |state, ctx, payload|
  contexts = state.find_objects(ctx, 'context')
  driver = state.find_object(ctx, 'driver', 'hDriver')
  desc_val = state.find_param(ctx, 'desc_val')
  desc = state.to_struct(desc_val, ZE::ZEContextDesc)
  handle = payload['phContext_val']
  contexts[handle] = ZEModel::Context.new(handle, driver, desc)
  driver.contexts[handle] = contexts[handle] if driver
  check_struct_stype_misuse(state, ctx, payload, :ZE_STRUCTURE_TYPE_CONTEXT_DESC, desc[:stype])
})

# Experimental API, it practically serves the same purpose as zeContextCreate
register_level_zero_handler('level_zero.zeContextCreateEx.success', lambda { |state, ctx, payload|
  contexts = state.find_objects(ctx, 'context')
  devices = state.find_objects(ctx, 'device')
  driver = state.find_object(ctx, 'driver', 'hDriver')
  desc_val = state.find_param(ctx, 'desc_val')
  desc = state.to_struct(desc_val, ZE::ZEContextDesc)
  devs = state.find_param(ctx, 'phDevices_vals').collect { |h| devices[h] }
  devs = nil unless state.find_param(ctx, 'phDevices') != 0
  handle = payload['phContext_val']
  contexts[handle] = ZEModel::Context.new(handle, driver, desc, devs)
  driver.contexts[handle] = contexts[handle] if driver
})

# A context owns everything created from it, so its destruction is where
# whatever the program did not clean up first gets reported.
register_level_zero_handler('level_zero.zeContextDestroy.success', lambda { |state, ctx, _payload|
  contexts = state.find_objects(ctx, 'context')
  handle = state.find_param(ctx, 'hContext')
  context_obj = contexts.delete(handle) do
    state.object_not_found(ctx, 'context', handle)
  end
  context_obj.driver&.contexts&.delete(handle)
  state.report_orphans(ctx, context_obj)
})

register_level_zero_handler('level_zero.zeEventPoolCreate.success', lambda { |state, ctx, payload|
  context_obj = state.find_object(ctx, 'context', 'hContext')
  devices = state.find_objects(ctx, 'device')
  event_pools = state.find_objects(ctx, 'event_pool')
  desc_val = state.find_param(ctx, 'desc_val')
  desc = state.to_struct(desc_val, ZE::ZEEventPoolDesc)
  devs = state.find_param(ctx, 'phDevices_vals').collect { |h| devices[h] }
  devs = nil unless state.find_param(ctx, 'phDevices') != 0
  handle = payload['phEventPool_val']
  event_pools[handle] = ZEModel::EventPool.new(handle, context_obj, desc, devs)
  context_obj.event_pools[handle] = event_pools[handle]
  check_struct_stype_misuse(state, ctx, payload, :ZE_STRUCTURE_TYPE_EVENT_POOL_DESC, desc[:stype])
})

# Destroying a pool while events are being used should not occur
register_level_zero_handler('level_zero.zeEventPoolDestroy.success', lambda { |state, ctx, _payload|
  event_pools = state.find_objects(ctx, 'event_pool')
  handle = state.find_param(ctx, 'hEventPool')
  event_pool = event_pools.delete(handle) do
    state.object_not_found(ctx, 'event_pool', handle)
  end
  event_pool.context.event_pools.delete(handle) do
    state.object_not_found(ctx, 'event_pool', handle, 'context')
  end
  state.report_orphans(ctx, event_pool)
})

register_level_zero_handler('level_zero.zeEventCreate.entry', lambda { |state, ctx, payload|
  check_valid_event_pool(state, ctx, payload)
})

register_level_zero_handler('level_zero.zeEventCreate.success', lambda { |state, ctx, payload|
  events = state.find_objects(ctx, 'event')
  event_pool = state.find_object(ctx, 'event_pool', 'hEventPool')
  desc_val = state.find_param(ctx, 'desc_val')
  desc = state.to_struct(desc_val, ZE::ZEEventDesc)
  handle = payload['phEvent_val']
  events[handle] = ZEModel::Event.new(handle, event_pool, desc)
  unless event_pool.indices.delete?(desc[:index])
    state.report(:event_pool_index_in_use, ctx,
                 "event_pool #{state.get_handle_str(event_pool.handle)} index #{desc[:index]} is already used",
                 key: "pool-index-used-#{state.get_handle_str(event_pool.handle)}-#{desc[:index]}")
  end
  event_pool.events[handle] = events[handle]
  check_struct_stype_misuse(state, ctx, payload, :ZE_STRUCTURE_TYPE_EVENT_DESC, desc[:stype])
})

register_level_zero_handler('level_zero.zeEventDestroy.success', lambda { |state, ctx, _payload|
  events = state.find_objects(ctx, 'event')
  handle = state.find_param(ctx, 'hEvent')
  event = events.delete(handle) do
    state.object_not_found(ctx, 'event', handle)
  end
  event_pool = event.event_pool
  event_pool.events.delete(handle) do
    state.object_not_found(ctx, 'event', handle, 'event_pool')
  end
  unless event_pool.indices.add?(event.desc[:index])
    state.report(:event_pool_index_already_free, ctx,
                 "event_pool #{state.get_handle_str(event_pool.handle)} index #{event.desc[:index]} is already freed",
                 key: "pool-index-freed-#{state.get_handle_str(event_pool.handle)}-#{event.desc[:index]}")
  end
})

register_level_zero_handler('level_zero.zeCommandQueueCreate.success', lambda { |state, ctx, payload|
  command_queues = state.find_objects(ctx, 'command_queue')
  context_obj = state.find_object(ctx, 'context', 'hContext')
  device = state.find_object(ctx, 'device', 'hDevice')
  desc_val = state.find_param(ctx, 'desc_val')
  desc = state.to_struct(desc_val, ZE::ZECommandQueueDesc)
  handle = payload['phCommandQueue_val']
  puts "q create #{handle}, and device = #{device}"
  command_queues[handle] = ZEModel::CommandQueue.new(handle, context_obj, device, desc)
  context_obj.command_queues[handle] = command_queues[handle]
  check_struct_stype_misuse(state, ctx, payload, :ZE_STRUCTURE_TYPE_COMMAND_QUEUE_DESC, desc[:stype])
})

# A failed creation is likely an (ordinal, index) the device does not have, so
# check the index against the real topology to explain the failure.
register_level_zero_handler('level_zero.zeCommandQueueCreate.error', lambda { |state, ctx, _payload|
  desc_val = state.find_param(ctx, 'desc_val')
  desc = state.to_struct(desc_val, ZE::ZECommandQueueDesc)
  device_handle = state.find_param(ctx, 'hDevice')
  cmd_queue_handle = state.find_param(ctx, 'phCommandQueue')
  check_valid_index_for_ordinal(state, ctx, device_handle, cmd_queue_handle, desc[:ordinal], desc[:index])
})

register_level_zero_handler('level_zero.zeCommandQueueDestroy.success', lambda { |state, ctx, _payload|
  command_queues = state.find_objects(ctx, 'command_queue')
  handle = state.find_param(ctx, 'hCommandQueue')
  command_queue = command_queues.delete(handle) do
    state.object_not_found(ctx, 'command_queue', handle)
  end
  command_queue.context.command_queues.delete(handle) do
    state.object_not_found(ctx, 'command_queue', handle, 'context')
  end
  state.report_orphans(ctx, command_queue)
})

register_level_zero_handler('level_zero.zeFenceCreate.success', lambda { |state, ctx, payload|
  fences = state.find_objects(ctx, 'fence')
  command_queue = state.find_object(ctx, 'command_queue', 'hCommandQueue')
  desc_val = state.find_param(ctx, 'desc_val')
  desc = state.to_struct(desc_val, ZE::ZEFenceDesc)
  handle = payload['phFence_val']
  fence = ZEModel::Fence.new(handle, command_queue, desc)
  fences[handle] = fence
  command_queue.fences[handle] = fence
  check_struct_stype_misuse(state, ctx, payload, :ZE_STRUCTURE_TYPE_FENCE_DESC, desc[:stype])
})

register_level_zero_handler('level_zero.zeFenceDestroy.success', lambda { |state, ctx, _payload|
  fences = state.find_objects(ctx, 'fence')
  handle = state.find_param(ctx, 'hFence')
  fence = fences.delete(handle) do
    state.object_not_found(ctx, 'fence', handle)
  end
  command_queue = fence.command_queue
  command_queue.fences.delete(handle) do
    state.object_not_found(ctx, 'fence', handle, 'command_queue')
  end
})

register_level_zero_handler('level_zero.zeCommandListCreate.success', lambda { |state, ctx, payload|
  command_lists = state.find_objects(ctx, 'command_list')
  context_obj = state.find_object(ctx, 'context', 'hContext')
  device = state.find_object(ctx, 'device', 'hDevice')
  desc_val = state.find_param(ctx, 'desc_val')
  desc = state.to_struct(desc_val, ZE::ZECommandListDesc)
  handle = payload['phCommandList_val']
  command_lists[handle] = ZEModel::CommandList.new(handle, context_obj, device, desc, nil)
  command_lists[handle].in_order = desc[:flags].include?(:ZE_COMMAND_LIST_FLAG_IN_ORDER)
  context_obj.command_lists[handle] = command_lists[handle]
  check_struct_stype_misuse(state, ctx, payload, :ZE_STRUCTURE_TYPE_COMMAND_LIST_DESC, desc[:stype])
})

register_level_zero_handler('level_zero.zeCommandListCreateImmediate.success', lambda { |state, ctx, payload|
  command_lists = state.find_objects(ctx, 'command_list')
  context_obj = state.find_object(ctx, 'context', 'hContext')
  device = state.find_object(ctx, 'device', 'hDevice')
  altdesc_val = state.find_param(ctx, 'altdesc_val')
  altdesc = state.to_struct(altdesc_val, ZE::ZECommandQueueDesc)
  handle = payload['phCommandList_val']
  check_group_property_queued(state, ctx, payload, device)
  command_lists[handle] = ZEModel::CommandList.new(handle, context_obj, device, nil, altdesc)
  command_lists[handle].immediate = true
  command_lists[handle].in_order = altdesc[:flags].include?(:ZE_COMMAND_QUEUE_FLAG_IN_ORDER)
  context_obj.command_lists[handle] = command_lists[handle]

  # immediate command list does not take in the list descriptor as an input
  check_struct_stype_misuse(state, ctx, payload, :ZE_STRUCTURE_TYPE_COMMAND_QUEUE_DESC, altdesc[:stype])
})

register_level_zero_handler('level_zero.zeCommandListDestroy.success', lambda { |state, ctx, _payload|
  command_lists = state.find_objects(ctx, 'command_list')
  handle = state.find_param(ctx, 'hCommandList')
  command_list = command_lists.delete(handle) do
    state.object_not_found(ctx, 'command_list', handle)
  end
  command_list.context.command_lists.delete(handle) do
    state.object_not_found(ctx, 'command_list', handle, 'context')
  end
})

register_level_zero_handler('level_zero.zeModuleCreate.success', lambda { |state, ctx, payload|
  modules = state.find_objects(ctx, 'module')
  context_obj = state.find_object(ctx, 'context', 'hContext')
  device = state.find_object(ctx, 'device', 'hDevice')
  desc_val = state.find_param(ctx, 'desc_val')
  desc = state.to_struct(desc_val, ZE::ZEModuleDesc)
  handle = payload['phModule_val']
  mod = ZEModel::Module.new(handle, context_obj, device, desc)
  modules[handle] = mod
  context_obj.modules[handle] = mod
  build_log_handle = payload['phBuildLog_val']
  if build_log_handle != 0
    module_build_logs = state.find_objects(ctx, 'module_build_log')
    build_log = ZEModel::Module::BuildLog.new(build_log_handle, context_obj, mod)
    module_build_logs[build_log_handle] = build_log
    context_obj.module_build_logs[build_log_handle] = build_log
    modules[handle].build_log = build_log
  end
  check_struct_stype_misuse(state, ctx, payload, :ZE_STRUCTURE_TYPE_MODULE_DESC, desc[:stype])
})

# Runs diagnoistics on why the module crete failed
register_level_zero_handler('level_zero.zeModuleCreate.error', lambda { |state, ctx, payload|
  build_log_handle = payload['phBuildLog_val']
  if build_log_handle != 0
    context_obj = state.find_object(ctx, 'context', 'hContext')
    module_build_logs = state.find_objects(ctx, 'module_build_log')
    build_log = ZEModel::Module::BuildLog.new(build_log_handle, context_obj)
    module_build_logs[build_log_handle] = build_log
    context_obj.module_build_logs[build_log_handle] = build_log
  end
})

# Kernel must be destroyed first before module
register_level_zero_handler('level_zero.zeModuleDestroy.success', lambda { |state, ctx, _payload|
  modules = state.find_objects(ctx, 'module')
  handle = state.find_param(ctx, 'hModule')
  mod = modules.delete(handle) do
    state.object_not_found(ctx, 'module', handle)
  end
  mod.context.modules.delete(handle) do
    state.object_not_found(ctx, 'module', handle, 'context')
  end
  state.report_orphans(ctx, mod)
})

register_level_zero_handler('level_zero.zeModuleDynamicLink.error', 'level_zero.zeModuleDynamicLink.success', lambda { |state, ctx, payload|
  build_log_handle = payload['phLinkLog_val']
  if build_log_handle != 0
    context_obj = state.find_object(ctx, 'context', 'hContext')
    module_build_logs = state.find_objects(ctx, 'module_build_log')
    build_log = ZEModel::Module::BuildLog.new(build_log_handle, context_obj)
    module_build_logs[build_log_handle] = build_log
    context_obj.module_build_logs[build_log_handle] = build_log
  end
})

register_level_zero_handler('level_zero.zeModuleBuildLogDestroy.success', lambda { |state, ctx, _payload|
  module_build_logs = state.find_objects(ctx, 'module_build_log')
  handle = state.find_param(ctx, 'hModuleBuildLog')
  module_build_log = module_build_logs.delete(handle) do
    state.object_not_found(ctx, 'module_build_log', handle)
  end
  if module_build_log.module
    module_build_log.module.context.module_build_logs.delete(handle) do
      state.object_not_found(ctx, 'module_build_log', handle, 'context')
    end
    module_build_log.module.build_log = nil
  end
})

# upon entering, check if a valid module was passed
register_level_zero_handler('level_zero.zeKernelCreate.entry', lambda { |state, ctx, payload|
  check_valid_module(state, ctx, payload)
})

register_level_zero_handler('level_zero.zeKernelCreate.success', lambda { |state, ctx, payload|
  kernels = state.find_objects(ctx, 'kernel')
  mod = state.find_object(ctx, 'module', 'hModule')
  desc_val = state.find_param(ctx, 'desc_val')
  desc = state.to_struct(desc_val, ZE::ZEKernelDesc)
  handle = payload['phKernel_val']
  kernelName = state.find_param(ctx, 'desc__pKernelName_val')
  kernel = ZEModel::Kernel.new(handle, mod, desc, kernelName)
  kernels[handle] = kernel
  mod.kernels[handle] = kernel
  check_struct_stype_misuse(state, ctx, payload, :ZE_STRUCTURE_TYPE_KERNEL_DESC, desc[:stype])
})

register_level_zero_handler('level_zero.zeKernelDestroy.success', lambda { |state, ctx, _payload|
  kernels = state.find_objects(ctx, 'kernel')
  handle = state.find_param(ctx, 'hKernel')
  kernel = kernels.delete(handle) do
    state.object_not_found(ctx, 'kernel', handle)
  end
  mod = kernel.module
  mod.kernels.delete(handle) do
    state.object_not_found(ctx, 'kernel', handle, 'module')
  end
})

register_level_zero_handler('level_zero.zeMemAllocDevice.success', lambda { |state, ctx, payload|
  # memory is associated with devices
  ze_context = state.find_param(ctx, 'hContext')
  context_obj = state.context_from_handle(ctx, ze_context)
  device = state.find_object(ctx, 'device', 'hDevice')
  size = state.find_param(ctx, 'size')
  device_desc_val = state.find_param(ctx, 'device_desc_val')
  handle = payload['pptr_val']
  if context_obj
    mark_reallocated(context_obj.freed_memory_allocations, handle, size)
    memory_allocation = ZEModel::MemoryAllocation.new(handle, context_obj, size, device, 'device')
    track_allocation(state, ctx, context_obj.memory_allocations, memory_allocation)
  end
  device_desc = state.to_struct(device_desc_val, ZE::ZEDeviceMemAllocDesc)
  check_struct_stype_misuse(state, ctx, payload, :ZE_STRUCTURE_TYPE_DEVICE_MEM_ALLOC_DESC, device_desc[:stype])
})

register_level_zero_handler('level_zero.zeMemAllocShared.success', lambda { |state, ctx, payload|
  ze_context = state.find_param(ctx, 'hContext')
  # finds the device and context objects associated with the params
  context_obj = state.context_from_handle(ctx, ze_context)
  device = state.find_object(ctx, 'device', 'hDevice')
  # A nullptr device handle shares ownership between the host and all devices
  # supporting cross-device shared access.
  size = state.find_param(ctx, 'size')
  handle = payload['pptr_val']
  return unless context_obj

  mark_reallocated(context_obj.freed_memory_allocations, handle, size)
  memory_allocation = ZEModel::MemoryAllocation.new(handle, context_obj, size, device, 'shared')
  track_allocation(state, ctx, context_obj.memory_allocations, memory_allocation)
})

register_level_zero_handler('level_zero.zeMemAllocHost.success', lambda { |state, ctx, payload|
  # Host allocations are accessible by the host and all devices within the driver’s context.
  ze_context = state.find_param(ctx, 'hContext')
  context_obj = state.context_from_handle(ctx, ze_context)
  size = state.find_param(ctx, 'size')
  handle = payload['pptr_val']
  return unless context_obj

  mark_reallocated(context_obj.freed_memory_allocations, handle, size)
  memory_allocation = ZEModel::MemoryAllocation.new(handle, context_obj, size, nil, 'host')
  track_allocation(state, ctx, context_obj.memory_allocations, memory_allocation)
})

# The free is applied at entry: zeMemFree may block until the buffer is idle, so
# by _exit a gated copy could have drained and the in-flight check would miss it.
register_level_zero_handler('level_zero.zeMemFree.entry', lambda { |state, ctx, payload|
  context_obj = state.context_from_handle(ctx, payload['hContext'])
  return unless context_obj

  memory_allocations = context_obj.memory_allocations
  handle = payload['ptr']
  memory_allocation = find_allocation(memory_allocations, handle)
  return unless memory_allocation&.base == handle

  # flag if this buffer is still referenced by a copy/fill that has been
  # submitted but not yet completed (in-flight device work would touch freed mem)
  check_free_in_flight(state, ctx, memory_allocation)
  untrack_allocation(memory_allocations, memory_allocation)
  # keep the freed allocation in this context's freed registry so a later
  # copy/fill/kernel referencing this address is caught as use-after-free
  memory_allocation.freed_by = state.get_api_context(ctx)
  track_freed_allocation(context_obj.freed_memory_allocations, memory_allocation)
})

# the free was applied at entry, so restore the allocation if it actually failed.
# The unknown-context case was already reported at entry, hence the plain lookup.
register_level_zero_handler('level_zero.zeMemFree.error', lambda { |state, ctx, _payload|
  context_obj = state.find_object(ctx, 'context', 'hContext')
  handle = state.find_param(ctx, 'ptr')
  return unless context_obj

  freed = context_obj.freed_memory_allocations
  mem = find_allocation(freed, handle)
  if mem&.base == handle
    untrack_allocation(freed, mem)
    mem.freed_by = nil
    track_allocation(state, ctx, context_obj.memory_allocations, mem)
  end
})

register_level_zero_handler('level_zero.zeMemGetAddressRange.entry', lambda { |state, ctx, payload|
  context_obj = state.context_from_handle(ctx, payload['hContext'])
  return unless context_obj

  handle = payload['ptr']
  memory_allocation = find_allocation(context_obj.memory_allocations, handle)
  if !memory_allocation || memory_allocation.base != handle
    state.report(:unallocated_address_range, ctx,
                 "ptr #{state.get_handle_str(handle)} is either out-of-bounds or never got allocated",
                 key: "addr-range-#{state.get_handle_str(handle)}")
  end
})

# Export semantic checks as reusable, explicitly registered operations. Parameter
# names are validated at load time; no configuration text is evaluated as Ruby.
private_methods.grep(/^check_/).select { |name|
  method(name).source_location&.first == File.join(__dir__, 'semantics.rb')
}.each do |name|
  implementation = method(name)
  parameters = implementation.parameters.drop(2)
  required = parameters.select { |kind, _| kind == :req }.map { |_, n| n.to_s }
  optional = parameters.select { |kind, _| kind == :opt }.map { |_, n| n.to_s }
  # These arguments already belong to the rule's execution context. Keep
  # explicit values optional for compatibility with existing configurations.
  automatic = parameters.map { |_, key| key.to_s } & %w[payload _payload api]
  ZEValidator::HANDLERS.register(:check, name.to_s, required: required - automatic,
                                 optional: optional | automatic) do |env, args|
    values = parameters.map do |kind, key|
      key = key.to_s
      if args.key?(key)
        args[key]
      elsif key == 'payload' || key == '_payload'
        env[:payload]
      elsif key == 'api'
        env[:context].fetch('api')
      elsif kind == :opt
        nil
      end
    end
    implementation.call(env[:state], env[:context], *values)
  end
end

ZEValidator::HANDLERS.register(:predicate, 'events.waits_satisfied', required: %w[waits]) do |env, args|
  env[:state].waits_satisfied?(env[:context], args['waits'])
end

ZEValidator::HANDLERS.register(:action, 'commands.flush_pending') { |env, _| env[:state].flush_deferred }
ZEValidator::HANDLERS.register(:check, 'calls.finished') { |env, _| env[:state].report_unfinished_calls }
ZEValidator::HANDLERS.register(:check, 'objects.no_leaks') do |env, _|
  state = env[:state]
  state.report_leaks if state.instance_variable_get(:@report_leaks)
end
