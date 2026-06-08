require 'ze_validator_zemodel'
require 'ze_library'

$success_exit_lambdas = {}
$error_exit_lambdas = {}

$success_exit_lambdas['zeDriverGet'] = lambda { |state, ctx, defi|
  drivers = state.get_process(ctx).drivers
  defi['phDrivers_vals'].each { |h|
    drivers[h] = ZEModel::Driver.new(h) unless drivers[h]
  }
}

#TODO: warn about redundant kernel launches
# $success_exit_lambdas['zeCommandListAppendMemoryCopy'] = lambda { |state, ctx, defi|
# puts "mem copy called"
# }

$success_exit_lambdas['zeDeviceGet'] = lambda { |state, ctx, defi|
  devices = state.find_objects(ctx, 'device')
  driver = state.find_object(ctx, 'driver', 'hDriver')
  defi['phDevices_vals'].each { |h|
    unless devices[h]
      devices[h] = ZEModel::Device.new(h)
      driver.devices.push devices[h]
    end
  }
}

$success_exit_lambdas['zeDeviceGetSubDevices'] = lambda { |state, ctx, defi|
  devices = state.find_objects(ctx, 'device')
  device = state.find_object(ctx, 'device', 'hDevice')
  defi['phSubdevices_vals'].each { |h|
    unless devices[h]
      devices[h] = ZEModel::SubDevice.new(h, device)
      device.sub_devices.push devices[h]
    end
  }
}

$success_exit_lambdas['zeContextCreate'] = lambda { |state, ctx, defi|
  contexts = state.find_objects(ctx, 'context')
  driver = state.find_object(ctx, 'driver', 'hDriver')
  desc_val = state.find_param(ctx, 'desc_val')
  desc = state.to_struct(desc_val, ZE::ZEContextDesc)
  handle = defi['phContext_val']
  contexts[handle] = ZEModel::Context.new(handle, driver, desc)
}

$success_exit_lambdas['zeContextCreateEx'] = lambda { |state, ctx, defi|
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

$success_exit_lambdas['zeContextDestroy'] = lambda { |state, ctx, defi|
  contexts = state.find_objects(ctx, 'context')
  contexts.delete(state.find_param(ctx, 'hContext')) { |h|
    raise_internal_error(ctx, "context #{get_handle_str(h)} does not exist")
  }
}

$success_exit_lambdas['zeEventPoolCreate'] = lambda { |state, ctx, defi|
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

$success_exit_lambdas['zeEventPoolDestroy'] = lambda { |state, ctx, defi|
  event_pools = state.find_objects(ctx, 'event_pool')
  handle = state.find_param(ctx, 'hEventPool')
  event_pool = event_pools.delete(handle) {
    state.object_not_found(ctx, 'event_pool', handle)
  }
  event_pool.context.event_pools.delete(handle) {
    state.object_not_found(ctx, 'event_pool', handle, 'context')
  }
  event_pool.events.each { |h, _|
    state.print_usage_error(ctx, "event #{get_handle_str(h)} was not destroyed prior to event_pool #{get_handle_str(handle)} destruction")
  }
}

$success_exit_lambdas['zeEventCreate'] = lambda { |state, ctx, defi|
  events = state.find_objects(ctx, 'event')
  event_pool = state.find_object(ctx, 'event_pool', 'hEventPool')
  desc_val = state.find_param(ctx, 'desc_val')
  desc = state.to_struct(desc_val, ZE::ZEEventDesc)
  handle = defi['phEvent_val']
  events[handle] = ZEModel::Event.new(handle, event_pool, desc)
  if !event_pool.indices.delete?(desc[:index])
    print_usage_error(ctx, "event_pool #{get_handle_str(event_pool.handle)} index #{desc['index']} is already used")
  end
  event_pool.events[handle] = events[handle]
}

$success_exit_lambdas['zeEventDestroy'] = lambda { |state, ctx, defi|
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
     state.print_usage_error(ctx, "event_pool #{get_handle_str(event_pool.handle)} index #{event.desc[:index]} is already freed")
  end
}

$success_exit_lambdas['zeCommandQueueCreate'] = lambda { |state, ctx, defi|
  command_queues = state.find_objects(ctx, 'command_queue')
  context = state.find_object(ctx, 'context', 'hContext')
  device = state.find_object(ctx, 'device', 'hDevice')
  desc_val = state.find_param(ctx, 'desc_val')
  desc = state.to_struct(desc_val, ZE::ZECommandQueueDesc)
  handle = defi['phCommandQueue_val']
  command_queues[handle] = ZEModel::CommandQueue.new(handle, context, device, desc)
  context.command_queues[handle] = command_queues[handle]
}

$success_exit_lambdas['zeCommandQueueDestroy'] = lambda { |state, ctx, defi|
  command_queues = state.find_objects(ctx, 'command_queue')
  handle = state.find_param(ctx, 'hCommandQueue')
  command_queue = command_queues.delete(handle) {
    state.object_not_found(ctx, 'command_queue', handle)
  }
  command_queue.context.command_queues.delete(handle) {
    state.object_not_found(ctx, 'command_queue', handle, 'context')
  }
  command_queue.fences.each { |h, _|
    state.print_usage_error(ctx, "fence #{get_handle_str(h)} was not destroyed prior to command_queue #{get_handle_str(handle)} destruction")
  }
}



$success_exit_lambdas['zeFenceCreate'] = lambda { |state, ctx, defi|
  fences = state.find_objects(ctx, 'fence')
  command_queue = state.find_object(ctx, 'command_queue', 'hCommandQueue')
  desc_val = state.find_param(ctx, 'desc_val')
  desc = state.to_struct(desc_val, ZE::ZEFenceDesc)
  handle = defi['phFence_val']
  fence = ZEModel::Fence.new(handle, command_queue, desc)
  fences[handle] = fence
  command_queue.fences[handle] = fence
}


$success_exit_lambdas['zeFenceReset'] = lambda { |state, ctx, defi|
  fences = state.find_objects(ctx, 'fence')
}

$success_exit_lambdas['zeFenceDestroy'] = lambda { |state, ctx, defi|
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

$success_exit_lambdas['zeCommandListCreate'] = lambda { |state, ctx, defi|
  command_lists = state.find_objects(ctx, 'command_list')
  context = state.find_object(ctx, 'context', 'hContext')
  device = state.find_object(ctx, 'device', 'hDevice')
  desc_val = state.find_param(ctx, 'desc_val')
  desc = state.to_struct(desc_val, ZE::ZECommandListDesc)
  handle = defi['phCommandList_val']
  command_lists[handle] = ZEModel::CommandList.new(handle, context, device, desc, nil)
  context.command_lists[handle] = command_lists[handle]
}

$success_exit_lambdas['zeCommandListCreateImmediate'] = lambda { |state, ctx, defi|
  command_lists = state.find_objects(ctx, 'command_list')
  context = state.find_object(ctx, 'context', 'hContext')
  device = state.find_object(ctx, 'device', 'hDevice')
  altdesc_val = state.find_param(ctx, 'altdesc_val')
  altdesc = state.to_struct(altdesc_val, ZE::ZECommandQueueDesc)
  handle = defi['phCommandList_val']
  command_lists[handle] = ZEModel::CommandList.new(handle, context, device, nil, altdesc)
  context.command_lists[handle] = command_lists[handle]
}

$success_exit_lambdas['zeCommandListDestroy'] = lambda { |state, ctx, defi|
  command_lists = state.find_objects(ctx, 'command_list')
  handle = state.find_param(ctx, 'hCommandList')
  command_list = command_lists.delete(handle) {
    state.object_not_found(ctx, 'command_list', handle)
  }
  command_list.context.command_lists.delete(handle) {
    state.object_not_found(ctx, 'command_list', handle, 'context')
  }
}

$success_exit_lambdas['zeModuleCreate'] = lambda { |state, ctx, defi|
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

$error_exit_lambdas['zeModuleCreate'] = lambda { |state, ctx, defi|
  build_log_handle = defi['phBuildLog_val']
  if build_log_handle != 0
    module_build_logs = state.find_objects(ctx, 'module_build_log')
    build_log = ZEModel::Module::BuildLog.new(build_log_handle)
    module_build_logs[build_log_handle] = build_log
    context.module_build_logs[build_log_handle] = build_log
  end
}

$success_exit_lambdas['zeModuleDestroy'] = lambda { |state, ctx, defi|
  modules = state.find_objects(ctx, 'module')
  handle = state.find_param(ctx, 'hModule')
  mod = modules.delete(handle) {
    state.object_not_found(ctx, 'module', handle)
  }
  mod.context.modules.delete(handle) {
    state.object_not_found(ctx, 'module', handle, 'context')
  }
  mod.kernels.each { |h, _|
    state.print_usage_error(ctx, "kernel #{get_handle_str(h)} was not destroyed prior to module #{get_handle_str(handle)} destruction")
  }
}

$error_exit_lambdas['zeModuleDynamicLink'] = $success_exit_lambdas['zeModuleDynamicLink'] = lambda { |state, ctx, defi|
  build_log_handle = defi['phLinkLog_val']
  if build_log_handle != 0
    module_build_logs = state.find_objects(ctx, 'module_build_log')
    build_log = ZEModel::Module::BuildLog.new(build_log_handle)
    module_build_logs[build_log_handle] = build_log
    context.module_build_logs[build_log_handle] = build_log
  end
}

$success_exit_lambdas['zeModuleBuildLogDestroy'] = lambda { |state, ctx, defi|
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

$success_exit_lambdas['zeKernelCreate'] = lambda { |state, ctx, defi|
  kernels = state.find_objects(ctx, 'kernel')
  mod = state.find_object(ctx, 'module', 'hModule')
  desc_val = state.find_param(ctx, 'desc_val')
  desc = state.to_struct(desc_val, ZE::ZEKernelDesc)
  handle = defi['phKernel_val']
  kernel = ZEModel::Kernel.new(handle, mod, desc)
  kernels[handle] = kernel
  mod.kernels[handle] = kernel
}

$success_exit_lambdas['zeKernelDestroy'] = lambda { |state, ctx, defi|
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

$success_exit_lambdas['zeMemAllocDevice'] = lambda { |state, ctx, defi|
  # memory is associated with devices
  memory_allocations =  state.find_objects(ctx, 'memory_allocation')
  context = state.find_object(ctx, 'context', 'hContext')
  device = state.find_object(ctx, 'device','hDevice')
  size = state.find_param(ctx,"size")
  handle = defi['pptr_val']
  memory_allocation =  ZEModel::DeviceMemory.new(handle, context, size, device)
  memory_allocations[handle] = memory_allocation
  device.memory_allocations[handle] = memory_allocation
}

$success_exit_lambdas['zeMemAllocShared'] = lambda { |state, ctx, defi|
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
  memory_allocation =  ZEModel::DeviceMemory.new(handle, context, size, device)
  memory_allocations[handle] = memory_allocation
  device.memory_allocations[handle] = memory_allocation if device
}

$success_exit_lambdas['zeMemAllocHost'] = lambda { |state, ctx, defi|
  # Host allocations are accessible by the host and all devices within the driver’s context.
  # TODO: add this memory allocation to all devices in the context
  memory_allocations =  state.find_objects(ctx, 'memory_allocation')
  context = state.find_object(ctx, 'context', 'hContext')
  size = state.find_param(ctx,"size")
  handle = defi['pptr_val']
  memory_allocation =  ZEModel::DeviceMemory.new(handle, context, size, nil)
  memory_allocations[handle] = memory_allocation
}

$success_exit_lambdas['zeMemFree'] = lambda { |state, ctx, defi|
  memory_allocations =  state.find_objects(ctx, 'memory_allocation')
  handle = state.find_param(ctx, "ptr")
  memory_allocation = memory_allocations.delete(handle) {
    state.object_not_found(ctx, 'memory_allocation', handle)
  }
  dev = memory_allocation.device
  if dev
    dev.memory_allocations.delete(handle) {
      state.object_not_found(ctx, 'memory_allocation', handle, 'device')
    }
  end
}