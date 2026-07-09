require 'ze_validator_entry_exit_helpers'
require 'ze_validator_zemodel'
require 'ze_library'

$upon_entry = {} #called to modify program state on entry
$on_successful_exit = {} #called upon seeing exit functions with a successful return code
$on_erroneous_exit = {} #called upon seeing exit functions with a non-successful return code



#What happens if we try to evict memory that wasn't allocated?
#UB if a device is currently referring to the memory?
$upon_entry["zeContextEvictMemory"] = lambda{|state, ctx, defi|
  mem_addr = defi['ptr']
  memory_allocations =  state.find_objects(ctx, 'memory_allocation')
  mem = memory_allocations[mem_addr]
  mem.resident = false
}

$on_successful_exit["zeContextEvictMemory"] = lambda{|state, ctx, defi|
  mem_addr = defi['ptr']
  memory_allocations =  state.find_objects(ctx, 'memory_allocation')
  mem = memory_allocations[mem_addr]
  mem.resident = false
}

#Check whether that memory is accessible by device?
$upon_entry["zeContextMakeMemoryResident"] = lambda {|state, ctx, defi|
  mem_addr = defi['ptr']
  memory_allocations =  state.find_objects(ctx, 'memory_allocation')
  mem = memory_allocations[mem_addr]
  mem.resident = true #Does the driver automatically evict memory if the virtual mem exceeds the physical mem?
}

$upon_entry["zeCommandListAppendMemoryCopyRegion"] = lambda{|state, ctx, defi|
  #src cannot become a dst from another simultaneous thread
  #dst cannot become a src from another simultaneous thread and also a dst
  dst_ptr = defi['dstptr']
  src_ptr = defi['srcptr']
  record_copy_over(state,ctx,src_ptr,dst_ptr)
  check_memory_residency(state,ctx,defi,src_ptr,dst_ptr,"zeCommandListAppendMemoryCopyRegion")
  check_copy_over_data_race(state,ctx,defi,src_ptr,dst_ptr)
}

#remove the elements from state.memory_in_transit
$on_successful_exit["zeCommandListAppendMemoryCopyRegion"] = lambda{|state, ctx, defi|
  memory_allocations =  state.find_objects(ctx, 'memory_allocation')
  context = state.find_object(ctx, 'context', 'hContext')
  device = state.find_object(ctx, 'device','hDevice')
  size = state.find_param(ctx,"size")
  handle = defi['pptr_val']
  
}

$upon_entry["zeDeviceGetProperties"] = lambda{|state, ctx, defi|
  device_ptr = defi['hDevice']
  devices = state.find_objects(ctx, 'device')
  devices[device_ptr].property_fetched = true
}

$upon_entry["zeDeviceGetCommandQueueGroupProperties"] = lambda{|state, ctx, defi|
  device_ptr = defi['hDevice']
  devices = state.find_objects(ctx, 'device')
  devices[device_ptr].cmd_queue_group_properties_queried = true
}

#Checks for appending a kernel to a copy engine.
#Compute ordinal is 0 on 1550 MAX GPUs but this is device specific.
$upon_entry["zeCommandListAppendLaunchKernel"] = lambda { |state, ctx, defi|
  #Retrieve the compute ordinal from the command list
  command_lists = state.find_objects(ctx, 'command_list')
  cmd_list = command_lists[defi['hCommandList']]
  cqg_ordinal = cmd_list.desc[:commandQueueGroupOrdinal]
  #puts "cqg_ordinal = #{cqg_ordinal}"
  check_valid_ordinal(state,ctx,defi,cqg_ordinal)
  check_kernel_created(state,ctx,defi)
}

#when command queue is executed, the associated fence's status is set to IN_USE
$upon_entry["zeCommandListClose"] = lambda { |state, ctx, defi|
  command_lists = state.find_objects(ctx, 'command_list')
  cmd_list = command_lists[defi['hCommandList']]
  cmd_list.status = ZEModel::CommandList.class_variable_get(:@@CLOSED)
}

#TODO: check if reset or close was called before this if a different call with the same cmd list was observed previously
$upon_entry["zeCommandListAppendLaunchCooperativeKernel"] = lambda { |state, ctx, defi|
  command_lists = state.find_objects(ctx, 'command_list')
  cmd_list = command_lists[defi['hCommandList']]
  check_group_property_queued(stte,ctx,defi,cmd_list.device)
}

#when command queue is executed, the associated fence's status is set to IN_USE
$upon_entry["zeCommandQueueExecuteCommandLists"] = lambda { |state, ctx, defi|
  #check if command list is null
  check_valid_command_list(state,ctx,defi)
  #Check if command list was closed before executing it on the queue
  check_command_list_closed(state, ctx, defi) #ignore if it is the first execute call
  check_fence_misuse(state,ctx,defi)
  #check if the group property was hardcoded
  command_queues = state.find_objects(ctx, 'command_queue')
  command_queue = command_queues[defi['hCommandQueue']]
  check_group_property_queued(state,ctx,defi,command_queue.device)
}

#When a fence signals the host, set the fence's status to signaled 
$upon_entry["zeFenceHostSynchronize"] =  lambda { |state, ctx, defi|
  fences = nil
  curr_fence = ZEModel::Fence.get_fence(state,ctx,defi)
  return unless curr_fence
  if curr_fence.status == ZEModel::Fence.class_variable_get(:@@SIGNALED)
  state.print_usage_error(ctx, "Used fence: #{state.get_handle_str(defi['hFence'])} twice without resetting it")
  end
  curr_fence.status = ZEModel::Fence.class_variable_get(:@@SIGNALED)
}

#should a double reset be considered as a usage error?
#Also, a fence can be shared throughout the threads and is modeled correctly (if you are wondering about whether the model treats fence associated with different thread-id differently).
$upon_entry["zeFenceReset"] =  lambda { |state, ctx, defi|
  fences = nil
  curr_fence = ZEModel::Fence.get_fence(state,ctx,defi)
  return unless curr_fence
  curr_fence.status = ZEModel::Fence.class_variable_get(:@@INITIALIZED)
}

#Set the driver for the current context
$on_successful_exit['zeDriverGet'] = lambda { |state, ctx, defi|
  drivers = state.get_process(ctx).drivers
  defi['phDrivers_vals'].each { |h|
    drivers[h] = ZEModel::Driver.new(h) unless drivers[h]
  }
}

#Set device
$on_successful_exit['zeDeviceGet'] = lambda { |state, ctx, defi|
  devices = state.find_objects(ctx, 'device')
  driver = state.find_object(ctx, 'driver', 'hDriver')
  if driver
    defi['phDevices_vals'].each { |h|
      unless devices[h]
        devices[h] = ZEModel::Device.new(h)
        driver.devices.push devices[h]
      end
    }
  end
}



$on_successful_exit['zeDeviceGetSubDevices'] = lambda { |state, ctx, defi|
  devices = state.find_objects(ctx, 'device')
  device = state.find_object(ctx, 'device', 'hDevice')
  defi['phSubdevices_vals'].each { |h|
    unless devices[h]
      devices[h] = ZEModel::SubDevice.new(h, device)
      device.sub_devices.push devices[h]
    end
  }
}

$on_successful_exit['zeContextCreate'] = lambda { |state, ctx, defi|
  contexts = state.find_objects(ctx, 'context')
  driver = state.find_object(ctx, 'driver', 'hDriver')
  desc_val = state.find_param(ctx, 'desc_val')
  desc = state.to_struct(desc_val, ZE::ZEContextDesc)
  handle = defi['phContext_val']
  contexts[handle] = ZEModel::Context.new(handle, driver, desc)
}

$on_successful_exit['zeContextCreateEx'] = lambda { |state, ctx, defi|
  contexts = state.find_objects(ctx, 'context')
  devices = state.find_objects(ctx, 'device')
  driver = state.find_object(ctx, 'driver', 'hDriver')
  desc_val = state.find_param(ctx, 'desc_val')
  desc = state.to_struct(desc_val, ZE::ZEContextDesc)
  devs = state.find_param(ctx, 'phDevices_vals').collect { |h| devices[h] }
  devs = nil unless state.find_param(ctx, 'phDevices') != 0
  handle = defi['phContext_val']
  contexts[handle] = ZEModel::Context.new(handle, driver, desc, devs)
}

$on_successful_exit['zeContextDestroy'] = lambda { |state, ctx, defi|
  contexts = state.find_objects(ctx, 'context')
  contexts.delete(state.find_param(ctx, 'hContext')) { |h|
    raise_internal_error(ctx, "context #{state.get_handle_str(h)} does not exist")
  }
}

$on_successful_exit['zeEventPoolCreate'] = lambda { |state, ctx, defi|
  context = state.find_object(ctx, 'context', 'hContext')
  devices = state.find_objects(ctx, 'device')
  event_pools = state.find_objects(ctx, 'event_pool')
  desc_val = state.find_param(ctx, 'desc_val')
  desc = state.to_struct(desc_val, ZE::ZEEventPoolDesc)
  devs = state.find_param(ctx, 'phDevices_vals').collect { |h| devices[h] }
  devs = nil unless state.find_param(ctx, 'phDevices') != 0
  handle = defi['phEventPool_val']
  event_pools[handle] = ZEModel::EventPool.new(handle, context, desc, devs)
  context.event_pools[handle] = event_pools[handle]
}

$on_successful_exit['zeEventPoolDestroy'] = lambda { |state, ctx, defi|
  event_pools = state.find_objects(ctx, 'event_pool')
  handle = state.find_param(ctx, 'hEventPool')
  event_pool = event_pools.delete(handle) {
    state.object_not_found(ctx, 'event_pool', handle)
  }
  event_pool.context.event_pools.delete(handle) {
    state.object_not_found(ctx, 'event_pool', handle, 'context')
  }
  event_pool.events.each { |h, _|
    state.print_usage_error(ctx, "event #{state.get_handle_str(h)} was not destroyed prior to event_pool #{state.get_handle_str(handle)} destruction")
  }
}

$on_successful_exit['zeEventCreate'] = lambda { |state, ctx, defi|
  events = state.find_objects(ctx, 'event')
  event_pool = state.find_object(ctx, 'event_pool', 'hEventPool')
  desc_val = state.find_param(ctx, 'desc_val')
  desc = state.to_struct(desc_val, ZE::ZEEventDesc)
  handle = defi['phEvent_val']
  events[handle] = ZEModel::Event.new(handle, event_pool, desc)
  if !event_pool.indices.delete?(desc[:index])
    state.print_usage_error(ctx, "event_pool #{state.get_handle_str(event_pool.handle)} index #{desc[:index]} is already used")
  end
  event_pool.events[handle] = events[handle]
}

$on_successful_exit['zeEventDestroy'] = lambda { |state, ctx, defi|
  events = state.find_objects(ctx, 'event')
  handle = state.find_param(ctx, 'hEvent')
  event = events.delete(handle) {
    state.object_not_found(ctx, 'event', handle)
  }
  event_pool = event.event_pool
  event_pool.events.delete(handle) {
    state.object_not_found(ctx, 'event', handle, 'event_pool')
  }
  if !event_pool.indices.add?(event.desc[:index])
     state.print_usage_error(ctx, "event_pool #{state.get_handle_str(event_pool.handle)} index #{event.desc[:index]} is already freed")
  end
}

$on_successful_exit['zeCommandQueueCreate'] = lambda { |state, ctx, defi|
  command_queues = state.find_objects(ctx, 'command_queue')
  context = state.find_object(ctx, 'context', 'hContext')
  device = state.find_object(ctx, 'device', 'hDevice')
  desc_val = state.find_param(ctx, 'desc_val')
  desc = state.to_struct(desc_val, ZE::ZECommandQueueDesc)
  handle = defi['phCommandQueue_val']
  #puts "ordinal = #{desc[:ordinal]}"
  command_queues[handle] = ZEModel::CommandQueue.new(handle, context, device, desc)
  context.command_queues[handle] = command_queues[handle]
}

$on_successful_exit['zeCommandQueueDestroy'] = lambda { |state, ctx, defi|
  command_queues = state.find_objects(ctx, 'command_queue')
  handle = state.find_param(ctx, 'hCommandQueue')
  command_queue = command_queues.delete(handle) {
    state.object_not_found(ctx, 'command_queue', handle)
  }
  command_queue.context.command_queues.delete(handle) {
    state.object_not_found(ctx, 'command_queue', handle, 'context')
  }
  command_queue.fences.each { |h, _|
    state.print_usage_error(ctx, "fence #{state.get_handle_str(h)} was not destroyed prior to command_queue #{state.get_handle_str(handle)} destruction")
  }
}

$on_successful_exit['zeFenceCreate'] = lambda { |state, ctx, defi|
  fences = state.find_objects(ctx, 'fence')
  command_queue = state.find_object(ctx, 'command_queue', 'hCommandQueue')
  desc_val = state.find_param(ctx, 'desc_val')
  desc = state.to_struct(desc_val, ZE::ZEFenceDesc)
  handle = defi['phFence_val']
  fence = ZEModel::Fence.new(handle, command_queue, desc)
  fences[handle] = fence
  command_queue.fences[handle] = fence
}

$on_successful_exit['zeFenceDestroy'] = lambda { |state, ctx, defi|
  fences = state.find_objects(ctx, 'fence')
  handle = state.find_param(ctx, 'hFence')
  fence = fences.delete(handle) {
    state.object_not_found(ctx, 'fence', handle)
  }
  command_queue = fence.command_queue
  command_queue.fences.delete(handle) {
    state.object_not_found(ctx, 'fence', handle, 'command_queue')
  }
}

$on_successful_exit['zeCommandListCreate'] = lambda { |state, ctx, defi|
  command_lists = state.find_objects(ctx, 'command_list')
  context = state.find_object(ctx, 'context', 'hContext')
  device = state.find_object(ctx, 'device', 'hDevice')
  desc_val = state.find_param(ctx, 'desc_val')
  desc = state.to_struct(desc_val, ZE::ZECommandListDesc)
  handle = defi['phCommandList_val']
  command_lists[handle] = ZEModel::CommandList.new(handle, context, device, desc, nil)
  context.command_lists[handle] = command_lists[handle]
}

$on_successful_exit['zeCommandListCreateImmediate'] = lambda { |state, ctx, defi|
  command_lists = state.find_objects(ctx, 'command_list')
  context = state.find_object(ctx, 'context', 'hContext')
  device = state.find_object(ctx, 'device', 'hDevice')
  altdesc_val = state.find_param(ctx, 'altdesc_val')
  altdesc = state.to_struct(altdesc_val, ZE::ZECommandQueueDesc)
  handle = defi['phCommandList_val']
  check_group_property_queued(state,ctx,defi,device)
  command_lists[handle] = ZEModel::CommandList.new(handle, context, device, nil, altdesc)
  command_lists[handle].immediate = true #immdediate command lists cannot be passed to the execute command lists
  #puts "altdesc = #{altdesc}"
  command_lists[handle].associated_ordinal = altdesc[:ordinal]
  context.command_lists[handle] = command_lists[handle]
}

$on_successful_exit['zeCommandListDestroy'] = lambda { |state, ctx, defi|
  command_lists = state.find_objects(ctx, 'command_list')
  handle = state.find_param(ctx, 'hCommandList')
  command_list = command_lists.delete(handle) {
    state.object_not_found(ctx, 'command_list', handle)
  }
  command_list.context.command_lists.delete(handle) {
    state.object_not_found(ctx, 'command_list', handle, 'context')
  }
}

$on_successful_exit['zeModuleCreate'] = lambda { |state, ctx, defi|
  modules = state.find_objects(ctx, 'module')
  context = state.find_object(ctx, 'context', 'hContext')
  device = state.find_object(ctx, 'device', 'hDevice')
  desc_val = state.find_param(ctx, 'desc_val')
  desc = state.to_struct(desc_val, ZE::ZEModuleDesc)
  handle = defi['phModule_val']
  mod = ZEModel::Module.new(handle, context, device, desc)
  modules[handle] = mod
  context.modules[handle] = mod
  build_log_handle = defi['phBuildLog_val']
  if build_log_handle != 0
    module_build_logs = state.find_objects(ctx, 'module_build_log')
    build_log = ZEModel::Module::BuildLog.new(build_log_handle, mod)
    module_build_logs[build_log_handle] = build_log
    context.module_build_logs[build_log_handle] = build_log
    modules[handle].build_log = build_log
  end
}

$on_erroneous_exit['zeModuleCreate'] = lambda { |state, ctx, defi|
  build_log_handle = defi['phBuildLog_val']
  if build_log_handle != 0
    module_build_logs = state.find_objects(ctx, 'module_build_log')
    build_log = ZEModel::Module::BuildLog.new(build_log_handle)
    module_build_logs[build_log_handle] = build_log
    context.module_build_logs[build_log_handle] = build_log
  end
}

$on_successful_exit['zeModuleDestroy'] = lambda { |state, ctx, defi|
  modules = state.find_objects(ctx, 'module')
  handle = state.find_param(ctx, 'hModule')
  mod = modules.delete(handle) {
    state.object_not_found(ctx, 'module', handle)
  }
  mod.context.modules.delete(handle) {
    state.object_not_found(ctx, 'module', handle, 'context')
  }
  mod.kernels.each { |h, _|
    state.print_usage_error(ctx, "kernel #{state.get_handle_str(h)} was not destroyed prior to module #{state.get_handle_str(handle)} destruction")
  }
}

$on_erroneous_exit['zeModuleDynamicLink'] = $on_successful_exit['zeModuleDynamicLink'] = lambda { |state, ctx, defi|
  build_log_handle = defi['phLinkLog_val']
  if build_log_handle != 0
    module_build_logs = state.find_objects(ctx, 'module_build_log')
    build_log = ZEModel::Module::BuildLog.new(build_log_handle)
    module_build_logs[build_log_handle] = build_log
    context.module_build_logs[build_log_handle] = build_log
  end
}

$on_successful_exit['zeModuleBuildLogDestroy'] = lambda { |state, ctx, defi|
  module_build_logs = state.find_objects(ctx, 'module_build_log')
  handle = state.find_param(ctx, 'hModuleBuildLog')
  module_build_log = module_build_logs.delete(handle) {
    state.object_not_found(ctx, 'module_build_log', handle)
  }
  if module_build_log.module
    module_build_log.module.context.module_build_logs.delete(handle) {
      state.object_not_found(ctx, 'module_build_log', handle, 'context')
    }
    module_build_log.module.build_log = nil
  end
}

$upon_entry['zeKernelCreate'] = lambda {|state, ctx, defi|
  check_valid_module(state,ctx, defi)
}

$on_successful_exit['zeKernelCreate'] = lambda { |state, ctx, defi|
  kernels = state.find_objects(ctx, 'kernel')
  mod = state.find_object(ctx, 'module', 'hModule')
  desc_val = state.find_param(ctx, 'desc_val')
  desc = state.to_struct(desc_val, ZE::ZEKernelDesc)
  handle = defi['phKernel_val']
  kernelName = state.find_param(ctx, 'desc__pKernelName_val')
  kernel = ZEModel::Kernel.new(handle, mod, desc, kernelName)
  #puts "kernelName = #{state.find_param(ctx, 'desc__pKernelName_val')}"
  kernels[handle] = kernel
  mod.kernels[handle] = kernel
}

$on_successful_exit['zeKernelDestroy'] = lambda { |state, ctx, defi|
  kernels = state.find_objects(ctx, 'kernel')
  handle = state.find_param(ctx, 'hKernel')
  kernel = kernels.delete(handle) {
    state.object_not_found(ctx, 'kernel', handle)
  }
  mod = kernel.module
  mod.kernels.delete(handle) {
    state.object_not_found(ctx, 'kernel', handle, 'module')
  }
}

$upon_entry['zeCommandListAppendMemoryCopy'] = lambda { |state, ctx, defi|
  check_oob_memory_copy(state,ctx,defi)
}

$upon_entry['zeMemAllocDevice'] = lambda {|state, ctx, defi|
  device_desc_val = defi['device_desc_val']
  device_desc = state.to_struct(device_desc_val, ZE::ZEDeviceMemAllocDesc)
  
  if state.print_tracker["zeMemAllocDevice::StypeMisuse"] == 0
    state.print_tracker["zeMemAllocDevice::StypeMisuse"] = 1
    check_struct_stype_misuse(state,ctx,defi,:ZE_STRUCTURE_TYPE_DEVICE_MEM_ALLOC_DESC, device_desc[:stype].to_sym)
  end
}

#The implementation of this (zeMemAllocDevice) function must be thread-safe
$on_successful_exit['zeMemAllocDevice'] = lambda { |state, ctx, defi|
  # memory is associated with devices
  memory_allocations =  state.find_objects(ctx, 'memory_allocation')
  context = state.find_object(ctx, 'context', 'hContext')
  device = state.find_object(ctx, 'device','hDevice')
  size = state.find_param(ctx,"size")
  handle = defi['pptr_val']
  memory_allocation =  ZEModel::Memory.new(handle, context, size, device, "device")
  memory_allocations[handle] = memory_allocation
  device.memory_allocations[handle] = memory_allocation
}
#remove the transit info when the copy region returns
$on_successful_exit["zeCommandListAppendMemoryCopyRegion"] = lambda { |state, ctx, defi|
  src_ptr = state.find_param(ctx,"srcptr")
  dst_ptr = state.find_param(ctx,"dstptr")
  state.memory_in_transit[ctx['vpid']] -= [[src_ptr, "src"]]
  state.memory_in_transit[ctx['vpid']] -= [[dst_ptr, "dst"]]
}

$on_successful_exit['zeMemAllocShared'] = lambda { |state, ctx, defi|
  memory_allocations =  state.find_objects(ctx, 'memory_allocation')
  # finds the device and context objects associated with the params
  context = state.find_object(ctx, 'context', 'hContext')
  device = state.find_object(ctx, 'device','hDevice')
  # Passing nullptr as the device handle does not associate the shared allocation with any device.
  # For allocations with no associated device, ownership of the allocation is shared between the
  # host and all devices supporting cross-device shared access capabilities.
  # TODO: should add in code to add this mme allocation to all devices with that property
  size = state.find_param(ctx,"size")
  handle = defi['pptr_val']
  memory_allocation =  ZEModel::Memory.new(handle, context, size, device)
  memory_allocations[handle] = memory_allocation
  device.memory_allocations[handle] = memory_allocation if device
}

$on_successful_exit['zeMemAllocHost'] = lambda { |state, ctx, defi|
  # Host allocations are accessible by the host and all devices within the driver’s context.
  # TODO: add this memory allocation to all devices in the context
  memory_allocations =  state.find_objects(ctx, 'memory_allocation')
  context = state.find_object(ctx, 'context', 'hContext')
  size = state.find_param(ctx,"size")
  handle = defi['pptr_val']
  memory_allocation =  ZEModel::Memory.new(handle, context, size, nil, "host")
  memory_allocations[handle] = memory_allocation
}

$on_successful_exit['zeMemFree'] = lambda { |state, ctx, defi|
  memory_allocations =  state.find_objects(ctx, 'memory_allocation')
  handle = state.find_param(ctx, "ptr")
  memory_allocation = memory_allocations.delete(handle) {
    state.object_not_found(ctx, 'memory_allocation', handle)
  }
  if memory_allocation
    mem = memory_allocation.owned_by
    mem.memory_allocations.delete(handle) {
      state.object_not_found(ctx, 'memory_allocation', handle, 'device')
    } if mem
  end
}