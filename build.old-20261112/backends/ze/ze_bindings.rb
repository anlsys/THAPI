require_relative 'ze_library.rb'
require_relative 'ze_refinements.rb'
require_relative 'ze_bindings_base.rb'

module ZE

  begin
    attach_function :zeInit,
                    [ :ze_init_flags_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeInit in libze_loader.so"
  end

  begin
    attach_function :zeDriverGet,
                    [ :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeDriverGet in libze_loader.so"
  end

  begin
    attach_function :zeInitDrivers,
                    [ :pointer,
                    :pointer,
                    ZEInitDriverTypeDesc.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeInitDrivers in libze_loader.so"
  end

  begin
    attach_function :zeDriverGetApiVersion,
                    [ :ze_driver_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeDriverGetApiVersion in libze_loader.so"
  end

  begin
    attach_function :zeDriverGetProperties,
                    [ :ze_driver_handle_t,
                    ZEDriverProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeDriverGetProperties in libze_loader.so"
  end

  begin
    attach_function :zeDriverGetIpcProperties,
                    [ :ze_driver_handle_t,
                    ZEDriverIpcProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeDriverGetIpcProperties in libze_loader.so"
  end

  begin
    attach_function :zeDriverGetExtensionProperties,
                    [ :ze_driver_handle_t,
                    :pointer,
                    ZEDriverExtensionProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeDriverGetExtensionProperties in libze_loader.so"
  end

  begin
    attach_function :zeDriverGetExtensionFunctionAddress,
                    [ :ze_driver_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeDriverGetExtensionFunctionAddress in libze_loader.so"
  end

  begin
    attach_function :zeDriverGetLastErrorDescription,
                    [ :ze_driver_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeDriverGetLastErrorDescription in libze_loader.so"
  end

  begin
    attach_function :zeDeviceGet,
                    [ :ze_driver_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeDeviceGet in libze_loader.so"
  end

  begin
    attach_function :zeDeviceGetRootDevice,
                    [ :ze_device_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeDeviceGetRootDevice in libze_loader.so"
  end

  begin
    attach_function :zeDeviceGetSubDevices,
                    [ :ze_device_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeDeviceGetSubDevices in libze_loader.so"
  end

  begin
    attach_function :zeDeviceGetProperties,
                    [ :ze_device_handle_t,
                    ZEDeviceProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeDeviceGetProperties in libze_loader.so"
  end

  begin
    attach_function :zeDeviceGetComputeProperties,
                    [ :ze_device_handle_t,
                    ZEDeviceComputeProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeDeviceGetComputeProperties in libze_loader.so"
  end

  begin
    attach_function :zeDeviceGetModuleProperties,
                    [ :ze_device_handle_t,
                    ZEDeviceModuleProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeDeviceGetModuleProperties in libze_loader.so"
  end

  begin
    attach_function :zeDeviceGetCommandQueueGroupProperties,
                    [ :ze_device_handle_t,
                    :pointer,
                    ZECommandQueueGroupProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeDeviceGetCommandQueueGroupProperties in libze_loader.so"
  end

  begin
    attach_function :zeDeviceGetMemoryProperties,
                    [ :ze_device_handle_t,
                    :pointer,
                    ZEDeviceMemoryProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeDeviceGetMemoryProperties in libze_loader.so"
  end

  begin
    attach_function :zeDeviceGetMemoryAccessProperties,
                    [ :ze_device_handle_t,
                    ZEDeviceMemoryAccessProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeDeviceGetMemoryAccessProperties in libze_loader.so"
  end

  begin
    attach_function :zeDeviceGetCacheProperties,
                    [ :ze_device_handle_t,
                    :pointer,
                    ZEDeviceCacheProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeDeviceGetCacheProperties in libze_loader.so"
  end

  begin
    attach_function :zeDeviceGetImageProperties,
                    [ :ze_device_handle_t,
                    ZEDeviceImageProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeDeviceGetImageProperties in libze_loader.so"
  end

  begin
    attach_function :zeDeviceGetExternalMemoryProperties,
                    [ :ze_device_handle_t,
                    ZEDeviceExternalMemoryProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeDeviceGetExternalMemoryProperties in libze_loader.so"
  end

  begin
    attach_function :zeDeviceGetP2PProperties,
                    [ :ze_device_handle_t,
                    :ze_device_handle_t,
                    ZEDeviceP2PProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeDeviceGetP2PProperties in libze_loader.so"
  end

  begin
    attach_function :zeDeviceCanAccessPeer,
                    [ :ze_device_handle_t,
                    :ze_device_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeDeviceCanAccessPeer in libze_loader.so"
  end

  begin
    attach_function :zeDeviceGetStatus,
                    [ :ze_device_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeDeviceGetStatus in libze_loader.so"
  end

  begin
    attach_function :zeDeviceGetGlobalTimestamps,
                    [ :ze_device_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeDeviceGetGlobalTimestamps in libze_loader.so"
  end

  begin
    attach_function :zeContextCreate,
                    [ :ze_driver_handle_t,
                    ZEContextDesc.ptr,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeContextCreate in libze_loader.so"
  end

  begin
    attach_function :zeContextCreateEx,
                    [ :ze_driver_handle_t,
                    ZEContextDesc.ptr,
                    :uint32,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeContextCreateEx in libze_loader.so"
  end

  begin
    attach_function :zeContextDestroy,
                    [ :ze_context_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeContextDestroy in libze_loader.so"
  end

  begin
    attach_function :zeContextGetStatus,
                    [ :ze_context_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeContextGetStatus in libze_loader.so"
  end

  begin
    attach_function :zeCommandQueueCreate,
                    [ :ze_context_handle_t,
                    :ze_device_handle_t,
                    ZECommandQueueDesc.ptr,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandQueueCreate in libze_loader.so"
  end

  begin
    attach_function :zeCommandQueueDestroy,
                    [ :ze_command_queue_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandQueueDestroy in libze_loader.so"
  end

  begin
    attach_function :zeCommandQueueExecuteCommandLists,
                    [ :ze_command_queue_handle_t,
                    :uint32,
                    :pointer,
                    :ze_fence_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandQueueExecuteCommandLists in libze_loader.so"
  end

  begin
    attach_function :zeCommandQueueSynchronize,
                    [ :ze_command_queue_handle_t,
                    :uint64 ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandQueueSynchronize in libze_loader.so"
  end

  begin
    attach_function :zeCommandQueueGetOrdinal,
                    [ :ze_command_queue_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandQueueGetOrdinal in libze_loader.so"
  end

  begin
    attach_function :zeCommandQueueGetIndex,
                    [ :ze_command_queue_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandQueueGetIndex in libze_loader.so"
  end

  begin
    attach_function :zeCommandListCreate,
                    [ :ze_context_handle_t,
                    :ze_device_handle_t,
                    ZECommandListDesc.ptr,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListCreate in libze_loader.so"
  end

  begin
    attach_function :zeCommandListCreateImmediate,
                    [ :ze_context_handle_t,
                    :ze_device_handle_t,
                    ZECommandQueueDesc.ptr,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListCreateImmediate in libze_loader.so"
  end

  begin
    attach_function :zeCommandListDestroy,
                    [ :ze_command_list_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListDestroy in libze_loader.so"
  end

  begin
    attach_function :zeCommandListClose,
                    [ :ze_command_list_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListClose in libze_loader.so"
  end

  begin
    attach_function :zeCommandListReset,
                    [ :ze_command_list_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListReset in libze_loader.so"
  end

  begin
    attach_function :zeCommandListAppendWriteGlobalTimestamp,
                    [ :ze_command_list_handle_t,
                    :pointer,
                    :ze_event_handle_t,
                    :uint32,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListAppendWriteGlobalTimestamp in libze_loader.so"
  end

  begin
    attach_function :zeCommandListHostSynchronize,
                    [ :ze_command_list_handle_t,
                    :uint64 ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListHostSynchronize in libze_loader.so"
  end

  begin
    attach_function :zeCommandListGetDeviceHandle,
                    [ :ze_command_list_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListGetDeviceHandle in libze_loader.so"
  end

  begin
    attach_function :zeCommandListGetContextHandle,
                    [ :ze_command_list_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListGetContextHandle in libze_loader.so"
  end

  begin
    attach_function :zeCommandListGetOrdinal,
                    [ :ze_command_list_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListGetOrdinal in libze_loader.so"
  end

  begin
    attach_function :zeCommandListImmediateGetIndex,
                    [ :ze_command_list_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListImmediateGetIndex in libze_loader.so"
  end

  begin
    attach_function :zeCommandListIsImmediate,
                    [ :ze_command_list_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListIsImmediate in libze_loader.so"
  end

  begin
    attach_function :zeCommandListAppendBarrier,
                    [ :ze_command_list_handle_t,
                    :ze_event_handle_t,
                    :uint32,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListAppendBarrier in libze_loader.so"
  end

  begin
    attach_function :zeCommandListAppendMemoryRangesBarrier,
                    [ :ze_command_list_handle_t,
                    :uint32,
                    :pointer,
                    :pointer,
                    :ze_event_handle_t,
                    :uint32,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListAppendMemoryRangesBarrier in libze_loader.so"
  end

  begin
    attach_function :zeContextSystemBarrier,
                    [ :ze_context_handle_t,
                    :ze_device_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeContextSystemBarrier in libze_loader.so"
  end

  begin
    attach_function :zeCommandListAppendMemoryCopy,
                    [ :ze_command_list_handle_t,
                    :pointer,
                    :pointer,
                    :size_t,
                    :ze_event_handle_t,
                    :uint32,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListAppendMemoryCopy in libze_loader.so"
  end

  begin
    attach_function :zeCommandListAppendMemoryFill,
                    [ :ze_command_list_handle_t,
                    :pointer,
                    :pointer,
                    :size_t,
                    :size_t,
                    :ze_event_handle_t,
                    :uint32,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListAppendMemoryFill in libze_loader.so"
  end

  begin
    attach_function :zeCommandListAppendMemoryCopyRegion,
                    [ :ze_command_list_handle_t,
                    :pointer,
                    ZECopyRegion.ptr,
                    :uint32,
                    :uint32,
                    :pointer,
                    ZECopyRegion.ptr,
                    :uint32,
                    :uint32,
                    :ze_event_handle_t,
                    :uint32,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListAppendMemoryCopyRegion in libze_loader.so"
  end

  begin
    attach_function :zeCommandListAppendMemoryCopyFromContext,
                    [ :ze_command_list_handle_t,
                    :pointer,
                    :ze_context_handle_t,
                    :pointer,
                    :size_t,
                    :ze_event_handle_t,
                    :uint32,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListAppendMemoryCopyFromContext in libze_loader.so"
  end

  begin
    attach_function :zeCommandListAppendImageCopy,
                    [ :ze_command_list_handle_t,
                    :ze_image_handle_t,
                    :ze_image_handle_t,
                    :ze_event_handle_t,
                    :uint32,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListAppendImageCopy in libze_loader.so"
  end

  begin
    attach_function :zeCommandListAppendImageCopyRegion,
                    [ :ze_command_list_handle_t,
                    :ze_image_handle_t,
                    :ze_image_handle_t,
                    ZEImageRegion.ptr,
                    ZEImageRegion.ptr,
                    :ze_event_handle_t,
                    :uint32,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListAppendImageCopyRegion in libze_loader.so"
  end

  begin
    attach_function :zeCommandListAppendImageCopyToMemory,
                    [ :ze_command_list_handle_t,
                    :pointer,
                    :ze_image_handle_t,
                    ZEImageRegion.ptr,
                    :ze_event_handle_t,
                    :uint32,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListAppendImageCopyToMemory in libze_loader.so"
  end

  begin
    attach_function :zeCommandListAppendImageCopyFromMemory,
                    [ :ze_command_list_handle_t,
                    :ze_image_handle_t,
                    :pointer,
                    ZEImageRegion.ptr,
                    :ze_event_handle_t,
                    :uint32,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListAppendImageCopyFromMemory in libze_loader.so"
  end

  begin
    attach_function :zeCommandListAppendMemoryPrefetch,
                    [ :ze_command_list_handle_t,
                    :pointer,
                    :size_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListAppendMemoryPrefetch in libze_loader.so"
  end

  begin
    attach_function :zeCommandListAppendMemAdvise,
                    [ :ze_command_list_handle_t,
                    :ze_device_handle_t,
                    :pointer,
                    :size_t,
                    :ze_memory_advice_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListAppendMemAdvise in libze_loader.so"
  end

  begin
    attach_function :zeEventPoolCreate,
                    [ :ze_context_handle_t,
                    ZEEventPoolDesc.ptr,
                    :uint32,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeEventPoolCreate in libze_loader.so"
  end

  begin
    attach_function :zeEventPoolDestroy,
                    [ :ze_event_pool_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeEventPoolDestroy in libze_loader.so"
  end

  begin
    attach_function :zeEventCreate,
                    [ :ze_event_pool_handle_t,
                    ZEEventDesc.ptr,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeEventCreate in libze_loader.so"
  end

  begin
    attach_function :zeEventDestroy,
                    [ :ze_event_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeEventDestroy in libze_loader.so"
  end

  begin
    attach_function :zeEventPoolGetIpcHandle,
                    [ :ze_event_pool_handle_t,
                    ZEIpcEventPoolHandle.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeEventPoolGetIpcHandle in libze_loader.so"
  end

  begin
    attach_function :zeEventPoolPutIpcHandle,
                    [ :ze_context_handle_t,
                    :ze_ipc_event_pool_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeEventPoolPutIpcHandle in libze_loader.so"
  end

  begin
    attach_function :zeEventPoolOpenIpcHandle,
                    [ :ze_context_handle_t,
                    :ze_ipc_event_pool_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeEventPoolOpenIpcHandle in libze_loader.so"
  end

  begin
    attach_function :zeEventPoolCloseIpcHandle,
                    [ :ze_event_pool_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeEventPoolCloseIpcHandle in libze_loader.so"
  end

  begin
    attach_function :zeCommandListAppendSignalEvent,
                    [ :ze_command_list_handle_t,
                    :ze_event_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListAppendSignalEvent in libze_loader.so"
  end

  begin
    attach_function :zeCommandListAppendWaitOnEvents,
                    [ :ze_command_list_handle_t,
                    :uint32,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListAppendWaitOnEvents in libze_loader.so"
  end

  begin
    attach_function :zeEventHostSignal,
                    [ :ze_event_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeEventHostSignal in libze_loader.so"
  end

  begin
    attach_function :zeEventHostSynchronize,
                    [ :ze_event_handle_t,
                    :uint64 ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeEventHostSynchronize in libze_loader.so"
  end

  begin
    attach_function :zeEventQueryStatus,
                    [ :ze_event_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeEventQueryStatus in libze_loader.so"
  end

  begin
    attach_function :zeCommandListAppendEventReset,
                    [ :ze_command_list_handle_t,
                    :ze_event_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListAppendEventReset in libze_loader.so"
  end

  begin
    attach_function :zeEventHostReset,
                    [ :ze_event_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeEventHostReset in libze_loader.so"
  end

  begin
    attach_function :zeEventQueryKernelTimestamp,
                    [ :ze_event_handle_t,
                    ZEKernelTimestampResult.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeEventQueryKernelTimestamp in libze_loader.so"
  end

  begin
    attach_function :zeCommandListAppendQueryKernelTimestamps,
                    [ :ze_command_list_handle_t,
                    :uint32,
                    :pointer,
                    :pointer,
                    :pointer,
                    :ze_event_handle_t,
                    :uint32,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListAppendQueryKernelTimestamps in libze_loader.so"
  end

  begin
    attach_function :zeEventGetEventPool,
                    [ :ze_event_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeEventGetEventPool in libze_loader.so"
  end

  begin
    attach_function :zeEventGetSignalScope,
                    [ :ze_event_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeEventGetSignalScope in libze_loader.so"
  end

  begin
    attach_function :zeEventGetWaitScope,
                    [ :ze_event_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeEventGetWaitScope in libze_loader.so"
  end

  begin
    attach_function :zeEventPoolGetContextHandle,
                    [ :ze_event_pool_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeEventPoolGetContextHandle in libze_loader.so"
  end

  begin
    attach_function :zeEventPoolGetFlags,
                    [ :ze_event_pool_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeEventPoolGetFlags in libze_loader.so"
  end

  begin
    attach_function :zeFenceCreate,
                    [ :ze_command_queue_handle_t,
                    ZEFenceDesc.ptr,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeFenceCreate in libze_loader.so"
  end

  begin
    attach_function :zeFenceDestroy,
                    [ :ze_fence_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeFenceDestroy in libze_loader.so"
  end

  begin
    attach_function :zeFenceHostSynchronize,
                    [ :ze_fence_handle_t,
                    :uint64 ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeFenceHostSynchronize in libze_loader.so"
  end

  begin
    attach_function :zeFenceQueryStatus,
                    [ :ze_fence_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeFenceQueryStatus in libze_loader.so"
  end

  begin
    attach_function :zeFenceReset,
                    [ :ze_fence_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeFenceReset in libze_loader.so"
  end

  begin
    attach_function :zeImageGetProperties,
                    [ :ze_device_handle_t,
                    ZEImageDesc.ptr,
                    ZEImageProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeImageGetProperties in libze_loader.so"
  end

  begin
    attach_function :zeImageCreate,
                    [ :ze_context_handle_t,
                    :ze_device_handle_t,
                    ZEImageDesc.ptr,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeImageCreate in libze_loader.so"
  end

  begin
    attach_function :zeImageDestroy,
                    [ :ze_image_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeImageDestroy in libze_loader.so"
  end

  begin
    attach_function :zeMemAllocShared,
                    [ :ze_context_handle_t,
                    ZEDeviceMemAllocDesc.ptr,
                    ZEHostMemAllocDesc.ptr,
                    :size_t,
                    :size_t,
                    :ze_device_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeMemAllocShared in libze_loader.so"
  end

  begin
    attach_function :zeMemAllocDevice,
                    [ :ze_context_handle_t,
                    ZEDeviceMemAllocDesc.ptr,
                    :size_t,
                    :size_t,
                    :ze_device_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeMemAllocDevice in libze_loader.so"
  end

  begin
    attach_function :zeMemAllocHost,
                    [ :ze_context_handle_t,
                    ZEHostMemAllocDesc.ptr,
                    :size_t,
                    :size_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeMemAllocHost in libze_loader.so"
  end

  begin
    attach_function :zeMemFree,
                    [ :ze_context_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeMemFree in libze_loader.so"
  end

  begin
    attach_function :zeMemGetAllocProperties,
                    [ :ze_context_handle_t,
                    :pointer,
                    ZEMemoryAllocationProperties.ptr,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeMemGetAllocProperties in libze_loader.so"
  end

  begin
    attach_function :zeMemGetAddressRange,
                    [ :ze_context_handle_t,
                    :pointer,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeMemGetAddressRange in libze_loader.so"
  end

  begin
    attach_function :zeMemGetIpcHandle,
                    [ :ze_context_handle_t,
                    :pointer,
                    ZEIpcMemHandle.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeMemGetIpcHandle in libze_loader.so"
  end

  begin
    attach_function :zeMemGetIpcHandleFromFileDescriptorExp,
                    [ :ze_context_handle_t,
                    :uint64,
                    ZEIpcMemHandle.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeMemGetIpcHandleFromFileDescriptorExp in libze_loader.so"
  end

  begin
    attach_function :zeMemGetFileDescriptorFromIpcHandleExp,
                    [ :ze_context_handle_t,
                    :ze_ipc_mem_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeMemGetFileDescriptorFromIpcHandleExp in libze_loader.so"
  end

  begin
    attach_function :zeMemPutIpcHandle,
                    [ :ze_context_handle_t,
                    :ze_ipc_mem_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeMemPutIpcHandle in libze_loader.so"
  end

  begin
    attach_function :zeMemOpenIpcHandle,
                    [ :ze_context_handle_t,
                    :ze_device_handle_t,
                    :ze_ipc_mem_handle_t,
                    :ze_ipc_memory_flags_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeMemOpenIpcHandle in libze_loader.so"
  end

  begin
    attach_function :zeMemCloseIpcHandle,
                    [ :ze_context_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeMemCloseIpcHandle in libze_loader.so"
  end

  begin
    attach_function :zeMemSetAtomicAccessAttributeExp,
                    [ :ze_context_handle_t,
                    :ze_device_handle_t,
                    :pointer,
                    :size_t,
                    :ze_memory_atomic_attr_exp_flags_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeMemSetAtomicAccessAttributeExp in libze_loader.so"
  end

  begin
    attach_function :zeMemGetAtomicAccessAttributeExp,
                    [ :ze_context_handle_t,
                    :ze_device_handle_t,
                    :pointer,
                    :size_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeMemGetAtomicAccessAttributeExp in libze_loader.so"
  end

  begin
    attach_function :zeModuleCreate,
                    [ :ze_context_handle_t,
                    :ze_device_handle_t,
                    ZEModuleDesc.ptr,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeModuleCreate in libze_loader.so"
  end

  begin
    attach_function :zeModuleDestroy,
                    [ :ze_module_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeModuleDestroy in libze_loader.so"
  end

  begin
    attach_function :zeModuleDynamicLink,
                    [ :uint32,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeModuleDynamicLink in libze_loader.so"
  end

  begin
    attach_function :zeModuleBuildLogDestroy,
                    [ :ze_module_build_log_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeModuleBuildLogDestroy in libze_loader.so"
  end

  begin
    attach_function :zeModuleBuildLogGetString,
                    [ :ze_module_build_log_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeModuleBuildLogGetString in libze_loader.so"
  end

  begin
    attach_function :zeModuleGetNativeBinary,
                    [ :ze_module_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeModuleGetNativeBinary in libze_loader.so"
  end

  begin
    attach_function :zeModuleGetGlobalPointer,
                    [ :ze_module_handle_t,
                    :pointer,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeModuleGetGlobalPointer in libze_loader.so"
  end

  begin
    attach_function :zeModuleGetKernelNames,
                    [ :ze_module_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeModuleGetKernelNames in libze_loader.so"
  end

  begin
    attach_function :zeModuleGetProperties,
                    [ :ze_module_handle_t,
                    ZEModuleProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeModuleGetProperties in libze_loader.so"
  end

  begin
    attach_function :zeKernelCreate,
                    [ :ze_module_handle_t,
                    ZEKernelDesc.ptr,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeKernelCreate in libze_loader.so"
  end

  begin
    attach_function :zeKernelDestroy,
                    [ :ze_kernel_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeKernelDestroy in libze_loader.so"
  end

  begin
    attach_function :zeModuleGetFunctionPointer,
                    [ :ze_module_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeModuleGetFunctionPointer in libze_loader.so"
  end

  begin
    attach_function :zeKernelSetGroupSize,
                    [ :ze_kernel_handle_t,
                    :uint32,
                    :uint32,
                    :uint32 ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeKernelSetGroupSize in libze_loader.so"
  end

  begin
    attach_function :zeKernelSuggestGroupSize,
                    [ :ze_kernel_handle_t,
                    :uint32,
                    :uint32,
                    :uint32,
                    :pointer,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeKernelSuggestGroupSize in libze_loader.so"
  end

  begin
    attach_function :zeKernelSuggestMaxCooperativeGroupCount,
                    [ :ze_kernel_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeKernelSuggestMaxCooperativeGroupCount in libze_loader.so"
  end

  begin
    attach_function :zeKernelSetArgumentValue,
                    [ :ze_kernel_handle_t,
                    :uint32,
                    :size_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeKernelSetArgumentValue in libze_loader.so"
  end

  begin
    attach_function :zeKernelSetIndirectAccess,
                    [ :ze_kernel_handle_t,
                    :ze_kernel_indirect_access_flags_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeKernelSetIndirectAccess in libze_loader.so"
  end

  begin
    attach_function :zeKernelGetIndirectAccess,
                    [ :ze_kernel_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeKernelGetIndirectAccess in libze_loader.so"
  end

  begin
    attach_function :zeKernelGetSourceAttributes,
                    [ :ze_kernel_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeKernelGetSourceAttributes in libze_loader.so"
  end

  begin
    attach_function :zeKernelSetCacheConfig,
                    [ :ze_kernel_handle_t,
                    :ze_cache_config_flags_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeKernelSetCacheConfig in libze_loader.so"
  end

  begin
    attach_function :zeKernelGetProperties,
                    [ :ze_kernel_handle_t,
                    ZEKernelProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeKernelGetProperties in libze_loader.so"
  end

  begin
    attach_function :zeKernelGetName,
                    [ :ze_kernel_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeKernelGetName in libze_loader.so"
  end

  begin
    attach_function :zeCommandListAppendLaunchKernel,
                    [ :ze_command_list_handle_t,
                    :ze_kernel_handle_t,
                    ZEGroupCount.ptr,
                    :ze_event_handle_t,
                    :uint32,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListAppendLaunchKernel in libze_loader.so"
  end

  begin
    attach_function :zeCommandListAppendLaunchCooperativeKernel,
                    [ :ze_command_list_handle_t,
                    :ze_kernel_handle_t,
                    ZEGroupCount.ptr,
                    :ze_event_handle_t,
                    :uint32,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListAppendLaunchCooperativeKernel in libze_loader.so"
  end

  begin
    attach_function :zeCommandListAppendLaunchKernelIndirect,
                    [ :ze_command_list_handle_t,
                    :ze_kernel_handle_t,
                    ZEGroupCount.ptr,
                    :ze_event_handle_t,
                    :uint32,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListAppendLaunchKernelIndirect in libze_loader.so"
  end

  begin
    attach_function :zeCommandListAppendLaunchMultipleKernelsIndirect,
                    [ :ze_command_list_handle_t,
                    :uint32,
                    :pointer,
                    :pointer,
                    ZEGroupCount.ptr,
                    :ze_event_handle_t,
                    :uint32,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListAppendLaunchMultipleKernelsIndirect in libze_loader.so"
  end

  begin
    attach_function :zeContextMakeMemoryResident,
                    [ :ze_context_handle_t,
                    :ze_device_handle_t,
                    :pointer,
                    :size_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeContextMakeMemoryResident in libze_loader.so"
  end

  begin
    attach_function :zeContextEvictMemory,
                    [ :ze_context_handle_t,
                    :ze_device_handle_t,
                    :pointer,
                    :size_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeContextEvictMemory in libze_loader.so"
  end

  begin
    attach_function :zeContextMakeImageResident,
                    [ :ze_context_handle_t,
                    :ze_device_handle_t,
                    :ze_image_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeContextMakeImageResident in libze_loader.so"
  end

  begin
    attach_function :zeContextEvictImage,
                    [ :ze_context_handle_t,
                    :ze_device_handle_t,
                    :ze_image_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeContextEvictImage in libze_loader.so"
  end

  begin
    attach_function :zeSamplerCreate,
                    [ :ze_context_handle_t,
                    :ze_device_handle_t,
                    ZESamplerDesc.ptr,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeSamplerCreate in libze_loader.so"
  end

  begin
    attach_function :zeSamplerDestroy,
                    [ :ze_sampler_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeSamplerDestroy in libze_loader.so"
  end

  begin
    attach_function :zeVirtualMemReserve,
                    [ :ze_context_handle_t,
                    :pointer,
                    :size_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeVirtualMemReserve in libze_loader.so"
  end

  begin
    attach_function :zeVirtualMemFree,
                    [ :ze_context_handle_t,
                    :pointer,
                    :size_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeVirtualMemFree in libze_loader.so"
  end

  begin
    attach_function :zeVirtualMemQueryPageSize,
                    [ :ze_context_handle_t,
                    :ze_device_handle_t,
                    :size_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeVirtualMemQueryPageSize in libze_loader.so"
  end

  begin
    attach_function :zePhysicalMemCreate,
                    [ :ze_context_handle_t,
                    :ze_device_handle_t,
                    ZEPhysicalMemDesc.ptr,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zePhysicalMemCreate in libze_loader.so"
  end

  begin
    attach_function :zePhysicalMemDestroy,
                    [ :ze_context_handle_t,
                    :ze_physical_mem_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zePhysicalMemDestroy in libze_loader.so"
  end

  begin
    attach_function :zeVirtualMemMap,
                    [ :ze_context_handle_t,
                    :pointer,
                    :size_t,
                    :ze_physical_mem_handle_t,
                    :size_t,
                    :ze_memory_access_attribute_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeVirtualMemMap in libze_loader.so"
  end

  begin
    attach_function :zeVirtualMemUnmap,
                    [ :ze_context_handle_t,
                    :pointer,
                    :size_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeVirtualMemUnmap in libze_loader.so"
  end

  begin
    attach_function :zeVirtualMemSetAccessAttribute,
                    [ :ze_context_handle_t,
                    :pointer,
                    :size_t,
                    :ze_memory_access_attribute_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeVirtualMemSetAccessAttribute in libze_loader.so"
  end

  begin
    attach_function :zeVirtualMemGetAccessAttribute,
                    [ :ze_context_handle_t,
                    :pointer,
                    :size_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeVirtualMemGetAccessAttribute in libze_loader.so"
  end

  begin
    attach_function :zeKernelSetGlobalOffsetExp,
                    [ :ze_kernel_handle_t,
                    :uint32,
                    :uint32,
                    :uint32 ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeKernelSetGlobalOffsetExp in libze_loader.so"
  end

  begin
    attach_function :zeKernelGetBinaryExp,
                    [ :ze_kernel_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeKernelGetBinaryExp in libze_loader.so"
  end

  begin
    attach_function :zeDeviceImportExternalSemaphoreExt,
                    [ :ze_device_handle_t,
                    ZEExternalSemaphoreExtDesc.ptr,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeDeviceImportExternalSemaphoreExt in libze_loader.so"
  end

  begin
    attach_function :zeDeviceReleaseExternalSemaphoreExt,
                    [ :ze_external_semaphore_ext_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeDeviceReleaseExternalSemaphoreExt in libze_loader.so"
  end

  begin
    attach_function :zeCommandListAppendSignalExternalSemaphoreExt,
                    [ :ze_command_list_handle_t,
                    :uint32,
                    :pointer,
                    ZEExternalSemaphoreSignalParamsExt.ptr,
                    :ze_event_handle_t,
                    :uint32,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListAppendSignalExternalSemaphoreExt in libze_loader.so"
  end

  begin
    attach_function :zeCommandListAppendWaitExternalSemaphoreExt,
                    [ :ze_command_list_handle_t,
                    :uint32,
                    :pointer,
                    ZEExternalSemaphoreWaitParamsExt.ptr,
                    :ze_event_handle_t,
                    :uint32,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListAppendWaitExternalSemaphoreExt in libze_loader.so"
  end

  begin
    attach_function :zeRTASBuilderCreateExt,
                    [ :ze_driver_handle_t,
                    ZERtasBuilderExtDesc.ptr,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeRTASBuilderCreateExt in libze_loader.so"
  end

  begin
    attach_function :zeRTASBuilderGetBuildPropertiesExt,
                    [ :ze_rtas_builder_ext_handle_t,
                    ZERtasBuilderBuildOpExtDesc.ptr,
                    ZERtasBuilderExtProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeRTASBuilderGetBuildPropertiesExt in libze_loader.so"
  end

  begin
    attach_function :zeDriverRTASFormatCompatibilityCheckExt,
                    [ :ze_driver_handle_t,
                    :ze_rtas_format_ext_t,
                    :ze_rtas_format_ext_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeDriverRTASFormatCompatibilityCheckExt in libze_loader.so"
  end

  begin
    attach_function :zeRTASBuilderBuildExt,
                    [ :ze_rtas_builder_ext_handle_t,
                    ZERtasBuilderBuildOpExtDesc.ptr,
                    :pointer,
                    :size_t,
                    :pointer,
                    :size_t,
                    :ze_rtas_parallel_operation_ext_handle_t,
                    :pointer,
                    ZERtasAabbExt.ptr,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeRTASBuilderBuildExt in libze_loader.so"
  end

  begin
    attach_function :zeRTASBuilderCommandListAppendCopyExt,
                    [ :ze_command_list_handle_t,
                    :pointer,
                    :pointer,
                    :size_t,
                    :ze_event_handle_t,
                    :uint32,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeRTASBuilderCommandListAppendCopyExt in libze_loader.so"
  end

  begin
    attach_function :zeRTASBuilderDestroyExt,
                    [ :ze_rtas_builder_ext_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeRTASBuilderDestroyExt in libze_loader.so"
  end

  begin
    attach_function :zeRTASParallelOperationCreateExt,
                    [ :ze_driver_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeRTASParallelOperationCreateExt in libze_loader.so"
  end

  begin
    attach_function :zeRTASParallelOperationGetPropertiesExt,
                    [ :ze_rtas_parallel_operation_ext_handle_t,
                    ZERtasParallelOperationExtProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeRTASParallelOperationGetPropertiesExt in libze_loader.so"
  end

  begin
    attach_function :zeRTASParallelOperationJoinExt,
                    [ :ze_rtas_parallel_operation_ext_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeRTASParallelOperationJoinExt in libze_loader.so"
  end

  begin
    attach_function :zeRTASParallelOperationDestroyExt,
                    [ :ze_rtas_parallel_operation_ext_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeRTASParallelOperationDestroyExt in libze_loader.so"
  end

  begin
    attach_function :zeDeviceGetVectorWidthPropertiesExt,
                    [ :ze_device_handle_t,
                    :pointer,
                    ZEDeviceVectorWidthPropertiesExt.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeDeviceGetVectorWidthPropertiesExt in libze_loader.so"
  end

  begin
    attach_function :zeDeviceReserveCacheExt,
                    [ :ze_device_handle_t,
                    :size_t,
                    :size_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeDeviceReserveCacheExt in libze_loader.so"
  end

  begin
    attach_function :zeDeviceSetCacheAdviceExt,
                    [ :ze_device_handle_t,
                    :pointer,
                    :size_t,
                    :ze_cache_ext_region_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeDeviceSetCacheAdviceExt in libze_loader.so"
  end

  begin
    attach_function :zeEventQueryTimestampsExp,
                    [ :ze_event_handle_t,
                    :ze_device_handle_t,
                    :pointer,
                    ZEKernelTimestampResult.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeEventQueryTimestampsExp in libze_loader.so"
  end

  begin
    attach_function :zeImageGetMemoryPropertiesExp,
                    [ :ze_image_handle_t,
                    ZEImageMemoryPropertiesExp.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeImageGetMemoryPropertiesExp in libze_loader.so"
  end

  begin
    attach_function :zeImageViewCreateExt,
                    [ :ze_context_handle_t,
                    :ze_device_handle_t,
                    ZEImageDesc.ptr,
                    :ze_image_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeImageViewCreateExt in libze_loader.so"
  end

  begin
    attach_function :zeImageViewCreateExp,
                    [ :ze_context_handle_t,
                    :ze_device_handle_t,
                    ZEImageDesc.ptr,
                    :ze_image_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeImageViewCreateExp in libze_loader.so"
  end

  begin
    attach_function :zeKernelSchedulingHintExp,
                    [ :ze_kernel_handle_t,
                    ZESchedulingHintExpDesc.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeKernelSchedulingHintExp in libze_loader.so"
  end

  begin
    attach_function :zeDevicePciGetPropertiesExt,
                    [ :ze_device_handle_t,
                    ZEPciExtProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeDevicePciGetPropertiesExt in libze_loader.so"
  end

  begin
    attach_function :zeCommandListAppendImageCopyToMemoryExt,
                    [ :ze_command_list_handle_t,
                    :pointer,
                    :ze_image_handle_t,
                    ZEImageRegion.ptr,
                    :uint32,
                    :uint32,
                    :ze_event_handle_t,
                    :uint32,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListAppendImageCopyToMemoryExt in libze_loader.so"
  end

  begin
    attach_function :zeCommandListAppendImageCopyFromMemoryExt,
                    [ :ze_command_list_handle_t,
                    :ze_image_handle_t,
                    :pointer,
                    ZEImageRegion.ptr,
                    :uint32,
                    :uint32,
                    :ze_event_handle_t,
                    :uint32,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListAppendImageCopyFromMemoryExt in libze_loader.so"
  end

  begin
    attach_function :zeImageGetAllocPropertiesExt,
                    [ :ze_context_handle_t,
                    :ze_image_handle_t,
                    ZEImageAllocationExtProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeImageGetAllocPropertiesExt in libze_loader.so"
  end

  begin
    attach_function :zeModuleInspectLinkageExt,
                    [ ZELinkageInspectionExtDesc.ptr,
                    :uint32,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeModuleInspectLinkageExt in libze_loader.so"
  end

  begin
    attach_function :zeMemFreeExt,
                    [ :ze_context_handle_t,
                    ZEMemoryFreeExtDesc.ptr,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeMemFreeExt in libze_loader.so"
  end

  begin
    attach_function :zeFabricVertexGetExp,
                    [ :ze_driver_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeFabricVertexGetExp in libze_loader.so"
  end

  begin
    attach_function :zeFabricVertexGetSubVerticesExp,
                    [ :ze_fabric_vertex_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeFabricVertexGetSubVerticesExp in libze_loader.so"
  end

  begin
    attach_function :zeFabricVertexGetPropertiesExp,
                    [ :ze_fabric_vertex_handle_t,
                    ZEFabricVertexExpProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeFabricVertexGetPropertiesExp in libze_loader.so"
  end

  begin
    attach_function :zeFabricVertexGetDeviceExp,
                    [ :ze_fabric_vertex_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeFabricVertexGetDeviceExp in libze_loader.so"
  end

  begin
    attach_function :zeDeviceGetFabricVertexExp,
                    [ :ze_device_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeDeviceGetFabricVertexExp in libze_loader.so"
  end

  begin
    attach_function :zeFabricEdgeGetExp,
                    [ :ze_fabric_vertex_handle_t,
                    :ze_fabric_vertex_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeFabricEdgeGetExp in libze_loader.so"
  end

  begin
    attach_function :zeFabricEdgeGetVerticesExp,
                    [ :ze_fabric_edge_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeFabricEdgeGetVerticesExp in libze_loader.so"
  end

  begin
    attach_function :zeFabricEdgeGetPropertiesExp,
                    [ :ze_fabric_edge_handle_t,
                    ZEFabricEdgeExpProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeFabricEdgeGetPropertiesExp in libze_loader.so"
  end

  begin
    attach_function :zeEventQueryKernelTimestampsExt,
                    [ :ze_event_handle_t,
                    :ze_device_handle_t,
                    :pointer,
                    ZEEventQueryKernelTimestampsResultsExtProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeEventQueryKernelTimestampsExt in libze_loader.so"
  end

  begin
    attach_function :zeRTASBuilderCreateExp,
                    [ :ze_driver_handle_t,
                    ZERtasBuilderExpDesc.ptr,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeRTASBuilderCreateExp in libze_loader.so"
  end

  begin
    attach_function :zeRTASBuilderGetBuildPropertiesExp,
                    [ :ze_rtas_builder_exp_handle_t,
                    ZERtasBuilderBuildOpExpDesc.ptr,
                    ZERtasBuilderExpProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeRTASBuilderGetBuildPropertiesExp in libze_loader.so"
  end

  begin
    attach_function :zeDriverRTASFormatCompatibilityCheckExp,
                    [ :ze_driver_handle_t,
                    :ze_rtas_format_exp_t,
                    :ze_rtas_format_exp_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeDriverRTASFormatCompatibilityCheckExp in libze_loader.so"
  end

  begin
    attach_function :zeRTASBuilderBuildExp,
                    [ :ze_rtas_builder_exp_handle_t,
                    ZERtasBuilderBuildOpExpDesc.ptr,
                    :pointer,
                    :size_t,
                    :pointer,
                    :size_t,
                    :ze_rtas_parallel_operation_exp_handle_t,
                    :pointer,
                    ZERtasAabbExp.ptr,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeRTASBuilderBuildExp in libze_loader.so"
  end

  begin
    attach_function :zeRTASBuilderDestroyExp,
                    [ :ze_rtas_builder_exp_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeRTASBuilderDestroyExp in libze_loader.so"
  end

  begin
    attach_function :zeRTASParallelOperationCreateExp,
                    [ :ze_driver_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeRTASParallelOperationCreateExp in libze_loader.so"
  end

  begin
    attach_function :zeRTASParallelOperationGetPropertiesExp,
                    [ :ze_rtas_parallel_operation_exp_handle_t,
                    ZERtasParallelOperationExpProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeRTASParallelOperationGetPropertiesExp in libze_loader.so"
  end

  begin
    attach_function :zeRTASParallelOperationJoinExp,
                    [ :ze_rtas_parallel_operation_exp_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeRTASParallelOperationJoinExp in libze_loader.so"
  end

  begin
    attach_function :zeRTASParallelOperationDestroyExp,
                    [ :ze_rtas_parallel_operation_exp_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeRTASParallelOperationDestroyExp in libze_loader.so"
  end

  begin
    attach_function :zeMemGetPitchFor2dImage,
                    [ :ze_context_handle_t,
                    :ze_device_handle_t,
                    :size_t,
                    :size_t,
                    :uint,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeMemGetPitchFor2dImage in libze_loader.so"
  end

  begin
    attach_function :zeImageGetDeviceOffsetExp,
                    [ :ze_image_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeImageGetDeviceOffsetExp in libze_loader.so"
  end

  begin
    attach_function :zeCommandListCreateCloneExp,
                    [ :ze_command_list_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListCreateCloneExp in libze_loader.so"
  end

  begin
    attach_function :zeCommandListImmediateAppendCommandListsExp,
                    [ :ze_command_list_handle_t,
                    :uint32,
                    :pointer,
                    :ze_event_handle_t,
                    :uint32,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListImmediateAppendCommandListsExp in libze_loader.so"
  end

  begin
    attach_function :zeCommandListGetNextCommandIdExp,
                    [ :ze_command_list_handle_t,
                    ZEMutableCommandIdExpDesc.ptr,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListGetNextCommandIdExp in libze_loader.so"
  end

  begin
    attach_function :zeCommandListGetNextCommandIdWithKernelsExp,
                    [ :ze_command_list_handle_t,
                    ZEMutableCommandIdExpDesc.ptr,
                    :uint32,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListGetNextCommandIdWithKernelsExp in libze_loader.so"
  end

  begin
    attach_function :zeCommandListUpdateMutableCommandsExp,
                    [ :ze_command_list_handle_t,
                    ZEMutableCommandsExpDesc.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListUpdateMutableCommandsExp in libze_loader.so"
  end

  begin
    attach_function :zeCommandListUpdateMutableCommandSignalEventExp,
                    [ :ze_command_list_handle_t,
                    :uint64,
                    :ze_event_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListUpdateMutableCommandSignalEventExp in libze_loader.so"
  end

  begin
    attach_function :zeCommandListUpdateMutableCommandWaitEventsExp,
                    [ :ze_command_list_handle_t,
                    :uint64,
                    :uint32,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListUpdateMutableCommandWaitEventsExp in libze_loader.so"
  end

  begin
    attach_function :zeCommandListUpdateMutableCommandKernelsExp,
                    [ :ze_command_list_handle_t,
                    :uint32,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeCommandListUpdateMutableCommandKernelsExp in libze_loader.so"
  end

  begin
    attach_function :zeLoaderInit,
                    [  ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeLoaderInit in libze_loader.so"
  end

  begin
    attach_function :zeGetRTASBuilderProcAddrTable,
                    [ :ze_api_version_t,
                    ZERtasBuilderDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeGetRTASBuilderProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zeGetRTASBuilderExpProcAddrTable,
                    [ :ze_api_version_t,
                    ZERtasBuilderExpDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeGetRTASBuilderExpProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zeGetRTASParallelOperationProcAddrTable,
                    [ :ze_api_version_t,
                    ZERtasParallelOperationDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeGetRTASParallelOperationProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zeGetRTASParallelOperationExpProcAddrTable,
                    [ :ze_api_version_t,
                    ZERtasParallelOperationExpDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeGetRTASParallelOperationExpProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zeGetGlobalProcAddrTable,
                    [ :ze_api_version_t,
                    ZEGlobalDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeGetGlobalProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zeGetDriverProcAddrTable,
                    [ :ze_api_version_t,
                    ZEDriverDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeGetDriverProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zeGetDriverExpProcAddrTable,
                    [ :ze_api_version_t,
                    ZEDriverExpDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeGetDriverExpProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zeGetDeviceProcAddrTable,
                    [ :ze_api_version_t,
                    ZEDeviceDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeGetDeviceProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zeGetDeviceExpProcAddrTable,
                    [ :ze_api_version_t,
                    ZEDeviceExpDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeGetDeviceExpProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zeGetContextProcAddrTable,
                    [ :ze_api_version_t,
                    ZEContextDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeGetContextProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zeGetCommandQueueProcAddrTable,
                    [ :ze_api_version_t,
                    ZECommandQueueDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeGetCommandQueueProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zeGetCommandListProcAddrTable,
                    [ :ze_api_version_t,
                    ZECommandListDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeGetCommandListProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zeGetCommandListExpProcAddrTable,
                    [ :ze_api_version_t,
                    ZECommandListExpDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeGetCommandListExpProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zeGetImageProcAddrTable,
                    [ :ze_api_version_t,
                    ZEImageDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeGetImageProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zeGetImageExpProcAddrTable,
                    [ :ze_api_version_t,
                    ZEImageExpDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeGetImageExpProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zeGetMemProcAddrTable,
                    [ :ze_api_version_t,
                    ZEMemDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeGetMemProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zeGetMemExpProcAddrTable,
                    [ :ze_api_version_t,
                    ZEMemExpDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeGetMemExpProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zeGetFenceProcAddrTable,
                    [ :ze_api_version_t,
                    ZEFenceDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeGetFenceProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zeGetEventPoolProcAddrTable,
                    [ :ze_api_version_t,
                    ZEEventPoolDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeGetEventPoolProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zeGetEventProcAddrTable,
                    [ :ze_api_version_t,
                    ZEEventDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeGetEventProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zeGetEventExpProcAddrTable,
                    [ :ze_api_version_t,
                    ZEEventExpDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeGetEventExpProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zeGetModuleProcAddrTable,
                    [ :ze_api_version_t,
                    ZEModuleDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeGetModuleProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zeGetModuleBuildLogProcAddrTable,
                    [ :ze_api_version_t,
                    ZEModuleBuildLogDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeGetModuleBuildLogProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zeGetKernelProcAddrTable,
                    [ :ze_api_version_t,
                    ZEKernelDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeGetKernelProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zeGetKernelExpProcAddrTable,
                    [ :ze_api_version_t,
                    ZEKernelExpDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeGetKernelExpProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zeGetSamplerProcAddrTable,
                    [ :ze_api_version_t,
                    ZESamplerDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeGetSamplerProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zeGetPhysicalMemProcAddrTable,
                    [ :ze_api_version_t,
                    ZEPhysicalMemDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeGetPhysicalMemProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zeGetVirtualMemProcAddrTable,
                    [ :ze_api_version_t,
                    ZEVirtualMemDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeGetVirtualMemProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zeGetFabricVertexExpProcAddrTable,
                    [ :ze_api_version_t,
                    ZEFabricVertexExpDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeGetFabricVertexExpProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zeGetFabricEdgeExpProcAddrTable,
                    [ :ze_api_version_t,
                    ZEFabricEdgeExpDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zeGetFabricEdgeExpProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zetModuleGetDebugInfo,
                    [ :zet_module_handle_t,
                    :zet_module_debug_info_format_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetModuleGetDebugInfo in libze_loader.so"
  end

  begin
    attach_function :zetDeviceGetDebugProperties,
                    [ :zet_device_handle_t,
                    ZETDeviceDebugProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetDeviceGetDebugProperties in libze_loader.so"
  end

  begin
    attach_function :zetDebugAttach,
                    [ :zet_device_handle_t,
                    ZETDebugConfig.ptr,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetDebugAttach in libze_loader.so"
  end

  begin
    attach_function :zetDebugDetach,
                    [ :zet_debug_session_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetDebugDetach in libze_loader.so"
  end

  begin
    attach_function :zetDebugReadEvent,
                    [ :zet_debug_session_handle_t,
                    :uint64,
                    ZETDebugEvent.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetDebugReadEvent in libze_loader.so"
  end

  begin
    attach_function :zetDebugAcknowledgeEvent,
                    [ :zet_debug_session_handle_t,
                    ZETDebugEvent.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetDebugAcknowledgeEvent in libze_loader.so"
  end

  begin
    attach_function :zetDebugInterrupt,
                    [ :zet_debug_session_handle_t,
                    :ze_device_thread_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetDebugInterrupt in libze_loader.so"
  end

  begin
    attach_function :zetDebugResume,
                    [ :zet_debug_session_handle_t,
                    :ze_device_thread_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetDebugResume in libze_loader.so"
  end

  begin
    attach_function :zetDebugReadMemory,
                    [ :zet_debug_session_handle_t,
                    :ze_device_thread_t,
                    ZETDebugMemorySpaceDesc.ptr,
                    :size_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetDebugReadMemory in libze_loader.so"
  end

  begin
    attach_function :zetDebugWriteMemory,
                    [ :zet_debug_session_handle_t,
                    :ze_device_thread_t,
                    ZETDebugMemorySpaceDesc.ptr,
                    :size_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetDebugWriteMemory in libze_loader.so"
  end

  begin
    attach_function :zetDebugGetRegisterSetProperties,
                    [ :zet_device_handle_t,
                    :pointer,
                    ZETDebugRegsetProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetDebugGetRegisterSetProperties in libze_loader.so"
  end

  begin
    attach_function :zetDebugGetThreadRegisterSetProperties,
                    [ :zet_debug_session_handle_t,
                    :ze_device_thread_t,
                    :pointer,
                    ZETDebugRegsetProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetDebugGetThreadRegisterSetProperties in libze_loader.so"
  end

  begin
    attach_function :zetDebugReadRegisters,
                    [ :zet_debug_session_handle_t,
                    :ze_device_thread_t,
                    :uint32,
                    :uint32,
                    :uint32,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetDebugReadRegisters in libze_loader.so"
  end

  begin
    attach_function :zetDebugWriteRegisters,
                    [ :zet_debug_session_handle_t,
                    :ze_device_thread_t,
                    :uint32,
                    :uint32,
                    :uint32,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetDebugWriteRegisters in libze_loader.so"
  end

  begin
    attach_function :zetMetricGroupGet,
                    [ :zet_device_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricGroupGet in libze_loader.so"
  end

  begin
    attach_function :zetMetricGroupGetProperties,
                    [ :zet_metric_group_handle_t,
                    ZETMetricGroupProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricGroupGetProperties in libze_loader.so"
  end

  begin
    attach_function :zetMetricGroupCalculateMetricValues,
                    [ :zet_metric_group_handle_t,
                    :zet_metric_group_calculation_type_t,
                    :size_t,
                    :pointer,
                    :pointer,
                    ZETTypedValue.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricGroupCalculateMetricValues in libze_loader.so"
  end

  begin
    attach_function :zetMetricGet,
                    [ :zet_metric_group_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricGet in libze_loader.so"
  end

  begin
    attach_function :zetMetricGetProperties,
                    [ :zet_metric_handle_t,
                    ZETMetricProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricGetProperties in libze_loader.so"
  end

  begin
    attach_function :zetContextActivateMetricGroups,
                    [ :zet_context_handle_t,
                    :zet_device_handle_t,
                    :uint32,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetContextActivateMetricGroups in libze_loader.so"
  end

  begin
    attach_function :zetMetricStreamerOpen,
                    [ :zet_context_handle_t,
                    :zet_device_handle_t,
                    :zet_metric_group_handle_t,
                    ZETMetricStreamerDesc.ptr,
                    :ze_event_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricStreamerOpen in libze_loader.so"
  end

  begin
    attach_function :zetCommandListAppendMetricStreamerMarker,
                    [ :zet_command_list_handle_t,
                    :zet_metric_streamer_handle_t,
                    :uint32 ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetCommandListAppendMetricStreamerMarker in libze_loader.so"
  end

  begin
    attach_function :zetMetricStreamerClose,
                    [ :zet_metric_streamer_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricStreamerClose in libze_loader.so"
  end

  begin
    attach_function :zetMetricStreamerReadData,
                    [ :zet_metric_streamer_handle_t,
                    :uint32,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricStreamerReadData in libze_loader.so"
  end

  begin
    attach_function :zetMetricQueryPoolCreate,
                    [ :zet_context_handle_t,
                    :zet_device_handle_t,
                    :zet_metric_group_handle_t,
                    ZETMetricQueryPoolDesc.ptr,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricQueryPoolCreate in libze_loader.so"
  end

  begin
    attach_function :zetMetricQueryPoolDestroy,
                    [ :zet_metric_query_pool_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricQueryPoolDestroy in libze_loader.so"
  end

  begin
    attach_function :zetMetricQueryCreate,
                    [ :zet_metric_query_pool_handle_t,
                    :uint32,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricQueryCreate in libze_loader.so"
  end

  begin
    attach_function :zetMetricQueryDestroy,
                    [ :zet_metric_query_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricQueryDestroy in libze_loader.so"
  end

  begin
    attach_function :zetMetricQueryReset,
                    [ :zet_metric_query_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricQueryReset in libze_loader.so"
  end

  begin
    attach_function :zetCommandListAppendMetricQueryBegin,
                    [ :zet_command_list_handle_t,
                    :zet_metric_query_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetCommandListAppendMetricQueryBegin in libze_loader.so"
  end

  begin
    attach_function :zetCommandListAppendMetricQueryEnd,
                    [ :zet_command_list_handle_t,
                    :zet_metric_query_handle_t,
                    :ze_event_handle_t,
                    :uint32,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetCommandListAppendMetricQueryEnd in libze_loader.so"
  end

  begin
    attach_function :zetCommandListAppendMetricMemoryBarrier,
                    [ :zet_command_list_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetCommandListAppendMetricMemoryBarrier in libze_loader.so"
  end

  begin
    attach_function :zetMetricQueryGetData,
                    [ :zet_metric_query_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricQueryGetData in libze_loader.so"
  end

  begin
    attach_function :zetKernelGetProfileInfo,
                    [ :zet_kernel_handle_t,
                    ZETProfileProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetKernelGetProfileInfo in libze_loader.so"
  end

  begin
    attach_function :zetTracerExpCreate,
                    [ :zet_context_handle_t,
                    ZETTracerExpDesc.ptr,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetTracerExpCreate in libze_loader.so"
  end

  begin
    attach_function :zetTracerExpDestroy,
                    [ :zet_tracer_exp_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetTracerExpDestroy in libze_loader.so"
  end

  begin
    attach_function :zetTracerExpSetPrologues,
                    [ :zet_tracer_exp_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetTracerExpSetPrologues in libze_loader.so"
  end

  begin
    attach_function :zetTracerExpSetEpilogues,
                    [ :zet_tracer_exp_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetTracerExpSetEpilogues in libze_loader.so"
  end

  begin
    attach_function :zetTracerExpSetEnabled,
                    [ :zet_tracer_exp_handle_t,
                    :ze_bool_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetTracerExpSetEnabled in libze_loader.so"
  end

  begin
    attach_function :zetDeviceGetConcurrentMetricGroupsExp,
                    [ :zet_device_handle_t,
                    :uint32,
                    :pointer,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetDeviceGetConcurrentMetricGroupsExp in libze_loader.so"
  end

  begin
    attach_function :zetMetricTracerCreateExp,
                    [ :zet_context_handle_t,
                    :zet_device_handle_t,
                    :uint32,
                    :pointer,
                    ZETMetricTracerExpDesc.ptr,
                    :ze_event_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricTracerCreateExp in libze_loader.so"
  end

  begin
    attach_function :zetMetricTracerDestroyExp,
                    [ :zet_metric_tracer_exp_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricTracerDestroyExp in libze_loader.so"
  end

  begin
    attach_function :zetMetricTracerEnableExp,
                    [ :zet_metric_tracer_exp_handle_t,
                    :ze_bool_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricTracerEnableExp in libze_loader.so"
  end

  begin
    attach_function :zetMetricTracerDisableExp,
                    [ :zet_metric_tracer_exp_handle_t,
                    :ze_bool_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricTracerDisableExp in libze_loader.so"
  end

  begin
    attach_function :zetMetricTracerReadDataExp,
                    [ :zet_metric_tracer_exp_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricTracerReadDataExp in libze_loader.so"
  end

  begin
    attach_function :zetMetricDecoderCreateExp,
                    [ :zet_metric_tracer_exp_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricDecoderCreateExp in libze_loader.so"
  end

  begin
    attach_function :zetMetricDecoderDestroyExp,
                    [ :zet_metric_decoder_exp_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricDecoderDestroyExp in libze_loader.so"
  end

  begin
    attach_function :zetMetricDecoderGetDecodableMetricsExp,
                    [ :zet_metric_decoder_exp_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricDecoderGetDecodableMetricsExp in libze_loader.so"
  end

  begin
    attach_function :zetMetricTracerDecodeExp,
                    [ :zet_metric_decoder_exp_handle_t,
                    :pointer,
                    :pointer,
                    :uint32,
                    :pointer,
                    :pointer,
                    :pointer,
                    :pointer,
                    ZETMetricEntryExp.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricTracerDecodeExp in libze_loader.so"
  end

  begin
    attach_function :zetCommandListAppendMarkerExp,
                    [ :zet_command_list_handle_t,
                    :zet_metric_group_handle_t,
                    :uint32 ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetCommandListAppendMarkerExp in libze_loader.so"
  end

  begin
    attach_function :zetDeviceEnableMetricsExp,
                    [ :zet_device_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetDeviceEnableMetricsExp in libze_loader.so"
  end

  begin
    attach_function :zetDeviceDisableMetricsExp,
                    [ :zet_device_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetDeviceDisableMetricsExp in libze_loader.so"
  end

  begin
    attach_function :zetMetricGroupCalculateMultipleMetricValuesExp,
                    [ :zet_metric_group_handle_t,
                    :zet_metric_group_calculation_type_t,
                    :size_t,
                    :pointer,
                    :pointer,
                    :pointer,
                    :pointer,
                    ZETTypedValue.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricGroupCalculateMultipleMetricValuesExp in libze_loader.so"
  end

  begin
    attach_function :zetMetricGroupGetGlobalTimestampsExp,
                    [ :zet_metric_group_handle_t,
                    :ze_bool_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricGroupGetGlobalTimestampsExp in libze_loader.so"
  end

  begin
    attach_function :zetMetricGroupGetExportDataExp,
                    [ :zet_metric_group_handle_t,
                    :pointer,
                    :size_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricGroupGetExportDataExp in libze_loader.so"
  end

  begin
    attach_function :zetMetricGroupCalculateMetricExportDataExp,
                    [ :ze_driver_handle_t,
                    :zet_metric_group_calculation_type_t,
                    :size_t,
                    :pointer,
                    ZETMetricCalculateExpDesc.ptr,
                    :pointer,
                    :pointer,
                    :pointer,
                    ZETTypedValue.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricGroupCalculateMetricExportDataExp in libze_loader.so"
  end

  begin
    attach_function :zetMetricProgrammableGetExp,
                    [ :zet_device_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricProgrammableGetExp in libze_loader.so"
  end

  begin
    attach_function :zetMetricProgrammableGetPropertiesExp,
                    [ :zet_metric_programmable_exp_handle_t,
                    ZETMetricProgrammableExpProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricProgrammableGetPropertiesExp in libze_loader.so"
  end

  begin
    attach_function :zetMetricProgrammableGetParamInfoExp,
                    [ :zet_metric_programmable_exp_handle_t,
                    :pointer,
                    ZETMetricProgrammableParamInfoExp.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricProgrammableGetParamInfoExp in libze_loader.so"
  end

  begin
    attach_function :zetMetricProgrammableGetParamValueInfoExp,
                    [ :zet_metric_programmable_exp_handle_t,
                    :uint32,
                    :pointer,
                    ZETMetricProgrammableParamValueInfoExp.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricProgrammableGetParamValueInfoExp in libze_loader.so"
  end

  begin
    attach_function :zetMetricCreateFromProgrammableExp2,
                    [ :zet_metric_programmable_exp_handle_t,
                    :uint32,
                    ZETMetricProgrammableParamValueExp.ptr,
                    :pointer,
                    :pointer,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricCreateFromProgrammableExp2 in libze_loader.so"
  end

  begin
    attach_function :zetMetricCreateFromProgrammableExp,
                    [ :zet_metric_programmable_exp_handle_t,
                    ZETMetricProgrammableParamValueExp.ptr,
                    :uint32,
                    :pointer,
                    :pointer,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricCreateFromProgrammableExp in libze_loader.so"
  end

  begin
    attach_function :zetDeviceCreateMetricGroupsFromMetricsExp,
                    [ :zet_device_handle_t,
                    :uint32,
                    :pointer,
                    :pointer,
                    :pointer,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetDeviceCreateMetricGroupsFromMetricsExp in libze_loader.so"
  end

  begin
    attach_function :zetMetricGroupCreateExp,
                    [ :zet_device_handle_t,
                    :pointer,
                    :pointer,
                    :zet_metric_group_sampling_type_flags_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricGroupCreateExp in libze_loader.so"
  end

  begin
    attach_function :zetMetricGroupAddMetricExp,
                    [ :zet_metric_group_handle_t,
                    :zet_metric_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricGroupAddMetricExp in libze_loader.so"
  end

  begin
    attach_function :zetMetricGroupRemoveMetricExp,
                    [ :zet_metric_group_handle_t,
                    :zet_metric_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricGroupRemoveMetricExp in libze_loader.so"
  end

  begin
    attach_function :zetMetricGroupCloseExp,
                    [ :zet_metric_group_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricGroupCloseExp in libze_loader.so"
  end

  begin
    attach_function :zetMetricGroupDestroyExp,
                    [ :zet_metric_group_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricGroupDestroyExp in libze_loader.so"
  end

  begin
    attach_function :zetMetricDestroyExp,
                    [ :zet_metric_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetMetricDestroyExp in libze_loader.so"
  end

  begin
    attach_function :zetGetMetricProgrammableExpProcAddrTable,
                    [ :ze_api_version_t,
                    ZETMetricProgrammableExpDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetGetMetricProgrammableExpProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zetGetMetricTracerExpProcAddrTable,
                    [ :ze_api_version_t,
                    ZETMetricTracerExpDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetGetMetricTracerExpProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zetGetMetricDecoderExpProcAddrTable,
                    [ :ze_api_version_t,
                    ZETMetricDecoderExpDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetGetMetricDecoderExpProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zetGetDeviceProcAddrTable,
                    [ :ze_api_version_t,
                    ZETDeviceDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetGetDeviceProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zetGetDeviceExpProcAddrTable,
                    [ :ze_api_version_t,
                    ZETDeviceExpDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetGetDeviceExpProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zetGetContextProcAddrTable,
                    [ :ze_api_version_t,
                    ZETContextDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetGetContextProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zetGetCommandListProcAddrTable,
                    [ :ze_api_version_t,
                    ZETCommandListDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetGetCommandListProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zetGetCommandListExpProcAddrTable,
                    [ :ze_api_version_t,
                    ZETCommandListExpDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetGetCommandListExpProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zetGetModuleProcAddrTable,
                    [ :ze_api_version_t,
                    ZETModuleDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetGetModuleProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zetGetKernelProcAddrTable,
                    [ :ze_api_version_t,
                    ZETKernelDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetGetKernelProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zetGetMetricProcAddrTable,
                    [ :ze_api_version_t,
                    ZETMetricDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetGetMetricProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zetGetMetricExpProcAddrTable,
                    [ :ze_api_version_t,
                    ZETMetricExpDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetGetMetricExpProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zetGetMetricGroupProcAddrTable,
                    [ :ze_api_version_t,
                    ZETMetricGroupDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetGetMetricGroupProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zetGetMetricGroupExpProcAddrTable,
                    [ :ze_api_version_t,
                    ZETMetricGroupExpDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetGetMetricGroupExpProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zetGetMetricStreamerProcAddrTable,
                    [ :ze_api_version_t,
                    ZETMetricStreamerDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetGetMetricStreamerProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zetGetMetricQueryPoolProcAddrTable,
                    [ :ze_api_version_t,
                    ZETMetricQueryPoolDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetGetMetricQueryPoolProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zetGetMetricQueryProcAddrTable,
                    [ :ze_api_version_t,
                    ZETMetricQueryDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetGetMetricQueryProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zetGetTracerExpProcAddrTable,
                    [ :ze_api_version_t,
                    ZETTracerExpDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetGetTracerExpProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zetGetDebugProcAddrTable,
                    [ :ze_api_version_t,
                    ZETDebugDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zetGetDebugProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zesInit,
                    [ :zes_init_flags_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesInit in libze_loader.so"
  end

  begin
    attach_function :zesDriverGet,
                    [ :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDriverGet in libze_loader.so"
  end

  begin
    attach_function :zesDriverGetExtensionProperties,
                    [ :zes_driver_handle_t,
                    :pointer,
                    ZESDriverExtensionProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDriverGetExtensionProperties in libze_loader.so"
  end

  begin
    attach_function :zesDriverGetExtensionFunctionAddress,
                    [ :zes_driver_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDriverGetExtensionFunctionAddress in libze_loader.so"
  end

  begin
    attach_function :zesDeviceGet,
                    [ :zes_driver_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDeviceGet in libze_loader.so"
  end

  begin
    attach_function :zesDeviceGetProperties,
                    [ :zes_device_handle_t,
                    ZESDeviceProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDeviceGetProperties in libze_loader.so"
  end

  begin
    attach_function :zesDeviceGetState,
                    [ :zes_device_handle_t,
                    ZESDeviceState.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDeviceGetState in libze_loader.so"
  end

  begin
    attach_function :zesDeviceReset,
                    [ :zes_device_handle_t,
                    :ze_bool_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDeviceReset in libze_loader.so"
  end

  begin
    attach_function :zesDeviceResetExt,
                    [ :zes_device_handle_t,
                    ZESResetProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDeviceResetExt in libze_loader.so"
  end

  begin
    attach_function :zesDeviceProcessesGetState,
                    [ :zes_device_handle_t,
                    :pointer,
                    ZESProcessState.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDeviceProcessesGetState in libze_loader.so"
  end

  begin
    attach_function :zesDevicePciGetProperties,
                    [ :zes_device_handle_t,
                    ZESPciProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDevicePciGetProperties in libze_loader.so"
  end

  begin
    attach_function :zesDevicePciGetState,
                    [ :zes_device_handle_t,
                    ZESPciState.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDevicePciGetState in libze_loader.so"
  end

  begin
    attach_function :zesDevicePciGetBars,
                    [ :zes_device_handle_t,
                    :pointer,
                    ZESPciBarProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDevicePciGetBars in libze_loader.so"
  end

  begin
    attach_function :zesDevicePciGetStats,
                    [ :zes_device_handle_t,
                    ZESPciStats.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDevicePciGetStats in libze_loader.so"
  end

  begin
    attach_function :zesDeviceSetOverclockWaiver,
                    [ :zes_device_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDeviceSetOverclockWaiver in libze_loader.so"
  end

  begin
    attach_function :zesDeviceGetOverclockDomains,
                    [ :zes_device_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDeviceGetOverclockDomains in libze_loader.so"
  end

  begin
    attach_function :zesDeviceGetOverclockControls,
                    [ :zes_device_handle_t,
                    :zes_overclock_domain_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDeviceGetOverclockControls in libze_loader.so"
  end

  begin
    attach_function :zesDeviceResetOverclockSettings,
                    [ :zes_device_handle_t,
                    :ze_bool_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDeviceResetOverclockSettings in libze_loader.so"
  end

  begin
    attach_function :zesDeviceReadOverclockState,
                    [ :zes_device_handle_t,
                    :pointer,
                    :pointer,
                    :pointer,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDeviceReadOverclockState in libze_loader.so"
  end

  begin
    attach_function :zesDeviceEnumOverclockDomains,
                    [ :zes_device_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDeviceEnumOverclockDomains in libze_loader.so"
  end

  begin
    attach_function :zesOverclockGetDomainProperties,
                    [ :zes_overclock_handle_t,
                    ZESOverclockProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesOverclockGetDomainProperties in libze_loader.so"
  end

  begin
    attach_function :zesOverclockGetDomainVFProperties,
                    [ :zes_overclock_handle_t,
                    ZESVfProperty.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesOverclockGetDomainVFProperties in libze_loader.so"
  end

  begin
    attach_function :zesOverclockGetDomainControlProperties,
                    [ :zes_overclock_handle_t,
                    :zes_overclock_control_t,
                    ZESControlProperty.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesOverclockGetDomainControlProperties in libze_loader.so"
  end

  begin
    attach_function :zesOverclockGetControlCurrentValue,
                    [ :zes_overclock_handle_t,
                    :zes_overclock_control_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesOverclockGetControlCurrentValue in libze_loader.so"
  end

  begin
    attach_function :zesOverclockGetControlPendingValue,
                    [ :zes_overclock_handle_t,
                    :zes_overclock_control_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesOverclockGetControlPendingValue in libze_loader.so"
  end

  begin
    attach_function :zesOverclockSetControlUserValue,
                    [ :zes_overclock_handle_t,
                    :zes_overclock_control_t,
                    :double,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesOverclockSetControlUserValue in libze_loader.so"
  end

  begin
    attach_function :zesOverclockGetControlState,
                    [ :zes_overclock_handle_t,
                    :zes_overclock_control_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesOverclockGetControlState in libze_loader.so"
  end

  begin
    attach_function :zesOverclockGetVFPointValues,
                    [ :zes_overclock_handle_t,
                    :zes_vf_type_t,
                    :zes_vf_array_type_t,
                    :uint32,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesOverclockGetVFPointValues in libze_loader.so"
  end

  begin
    attach_function :zesOverclockSetVFPointValues,
                    [ :zes_overclock_handle_t,
                    :zes_vf_type_t,
                    :uint32,
                    :uint32 ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesOverclockSetVFPointValues in libze_loader.so"
  end

  begin
    attach_function :zesDeviceEnumDiagnosticTestSuites,
                    [ :zes_device_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDeviceEnumDiagnosticTestSuites in libze_loader.so"
  end

  begin
    attach_function :zesDiagnosticsGetProperties,
                    [ :zes_diag_handle_t,
                    ZESDiagProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDiagnosticsGetProperties in libze_loader.so"
  end

  begin
    attach_function :zesDiagnosticsGetTests,
                    [ :zes_diag_handle_t,
                    :pointer,
                    ZESDiagTest.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDiagnosticsGetTests in libze_loader.so"
  end

  begin
    attach_function :zesDiagnosticsRunTests,
                    [ :zes_diag_handle_t,
                    :uint32,
                    :uint32,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDiagnosticsRunTests in libze_loader.so"
  end

  begin
    attach_function :zesDeviceEccAvailable,
                    [ :zes_device_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDeviceEccAvailable in libze_loader.so"
  end

  begin
    attach_function :zesDeviceEccConfigurable,
                    [ :zes_device_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDeviceEccConfigurable in libze_loader.so"
  end

  begin
    attach_function :zesDeviceGetEccState,
                    [ :zes_device_handle_t,
                    ZESDeviceEccProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDeviceGetEccState in libze_loader.so"
  end

  begin
    attach_function :zesDeviceSetEccState,
                    [ :zes_device_handle_t,
                    ZESDeviceEccDesc.ptr,
                    ZESDeviceEccProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDeviceSetEccState in libze_loader.so"
  end

  begin
    attach_function :zesDeviceEnumEngineGroups,
                    [ :zes_device_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDeviceEnumEngineGroups in libze_loader.so"
  end

  begin
    attach_function :zesEngineGetProperties,
                    [ :zes_engine_handle_t,
                    ZESEngineProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesEngineGetProperties in libze_loader.so"
  end

  begin
    attach_function :zesEngineGetActivity,
                    [ :zes_engine_handle_t,
                    ZESEngineStats.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesEngineGetActivity in libze_loader.so"
  end

  begin
    attach_function :zesDeviceEventRegister,
                    [ :zes_device_handle_t,
                    :zes_event_type_flags_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDeviceEventRegister in libze_loader.so"
  end

  begin
    attach_function :zesDriverEventListen,
                    [ :ze_driver_handle_t,
                    :uint32,
                    :uint32,
                    :pointer,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDriverEventListen in libze_loader.so"
  end

  begin
    attach_function :zesDriverEventListenEx,
                    [ :ze_driver_handle_t,
                    :uint64,
                    :uint32,
                    :pointer,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDriverEventListenEx in libze_loader.so"
  end

  begin
    attach_function :zesDeviceEnumFabricPorts,
                    [ :zes_device_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDeviceEnumFabricPorts in libze_loader.so"
  end

  begin
    attach_function :zesFabricPortGetProperties,
                    [ :zes_fabric_port_handle_t,
                    ZESFabricPortProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFabricPortGetProperties in libze_loader.so"
  end

  begin
    attach_function :zesFabricPortGetLinkType,
                    [ :zes_fabric_port_handle_t,
                    ZESFabricLinkType.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFabricPortGetLinkType in libze_loader.so"
  end

  begin
    attach_function :zesFabricPortGetConfig,
                    [ :zes_fabric_port_handle_t,
                    ZESFabricPortConfig.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFabricPortGetConfig in libze_loader.so"
  end

  begin
    attach_function :zesFabricPortSetConfig,
                    [ :zes_fabric_port_handle_t,
                    ZESFabricPortConfig.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFabricPortSetConfig in libze_loader.so"
  end

  begin
    attach_function :zesFabricPortGetState,
                    [ :zes_fabric_port_handle_t,
                    ZESFabricPortState.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFabricPortGetState in libze_loader.so"
  end

  begin
    attach_function :zesFabricPortGetThroughput,
                    [ :zes_fabric_port_handle_t,
                    ZESFabricPortThroughput.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFabricPortGetThroughput in libze_loader.so"
  end

  begin
    attach_function :zesFabricPortGetFabricErrorCounters,
                    [ :zes_fabric_port_handle_t,
                    ZESFabricPortErrorCounters.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFabricPortGetFabricErrorCounters in libze_loader.so"
  end

  begin
    attach_function :zesFabricPortGetMultiPortThroughput,
                    [ :zes_device_handle_t,
                    :uint32,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFabricPortGetMultiPortThroughput in libze_loader.so"
  end

  begin
    attach_function :zesDeviceEnumFans,
                    [ :zes_device_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDeviceEnumFans in libze_loader.so"
  end

  begin
    attach_function :zesFanGetProperties,
                    [ :zes_fan_handle_t,
                    ZESFanProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFanGetProperties in libze_loader.so"
  end

  begin
    attach_function :zesFanGetConfig,
                    [ :zes_fan_handle_t,
                    ZESFanConfig.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFanGetConfig in libze_loader.so"
  end

  begin
    attach_function :zesFanSetDefaultMode,
                    [ :zes_fan_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFanSetDefaultMode in libze_loader.so"
  end

  begin
    attach_function :zesFanSetFixedSpeedMode,
                    [ :zes_fan_handle_t,
                    ZESFanSpeed.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFanSetFixedSpeedMode in libze_loader.so"
  end

  begin
    attach_function :zesFanSetSpeedTableMode,
                    [ :zes_fan_handle_t,
                    ZESFanSpeedTable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFanSetSpeedTableMode in libze_loader.so"
  end

  begin
    attach_function :zesFanGetState,
                    [ :zes_fan_handle_t,
                    :zes_fan_speed_units_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFanGetState in libze_loader.so"
  end

  begin
    attach_function :zesDeviceEnumFirmwares,
                    [ :zes_device_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDeviceEnumFirmwares in libze_loader.so"
  end

  begin
    attach_function :zesFirmwareGetProperties,
                    [ :zes_firmware_handle_t,
                    ZESFirmwareProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFirmwareGetProperties in libze_loader.so"
  end

  begin
    attach_function :zesFirmwareFlash,
                    [ :zes_firmware_handle_t,
                    :pointer,
                    :uint32 ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFirmwareFlash in libze_loader.so"
  end

  begin
    attach_function :zesFirmwareGetFlashProgress,
                    [ :zes_firmware_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFirmwareGetFlashProgress in libze_loader.so"
  end

  begin
    attach_function :zesFirmwareGetConsoleLogs,
                    [ :zes_firmware_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFirmwareGetConsoleLogs in libze_loader.so"
  end

  begin
    attach_function :zesDeviceEnumFrequencyDomains,
                    [ :zes_device_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDeviceEnumFrequencyDomains in libze_loader.so"
  end

  begin
    attach_function :zesFrequencyGetProperties,
                    [ :zes_freq_handle_t,
                    ZESFreqProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFrequencyGetProperties in libze_loader.so"
  end

  begin
    attach_function :zesFrequencyGetAvailableClocks,
                    [ :zes_freq_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFrequencyGetAvailableClocks in libze_loader.so"
  end

  begin
    attach_function :zesFrequencyGetRange,
                    [ :zes_freq_handle_t,
                    ZESFreqRange.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFrequencyGetRange in libze_loader.so"
  end

  begin
    attach_function :zesFrequencySetRange,
                    [ :zes_freq_handle_t,
                    ZESFreqRange.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFrequencySetRange in libze_loader.so"
  end

  begin
    attach_function :zesFrequencyGetState,
                    [ :zes_freq_handle_t,
                    ZESFreqState.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFrequencyGetState in libze_loader.so"
  end

  begin
    attach_function :zesFrequencyGetThrottleTime,
                    [ :zes_freq_handle_t,
                    ZESFreqThrottleTime.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFrequencyGetThrottleTime in libze_loader.so"
  end

  begin
    attach_function :zesFrequencyOcGetCapabilities,
                    [ :zes_freq_handle_t,
                    ZESOcCapabilities.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFrequencyOcGetCapabilities in libze_loader.so"
  end

  begin
    attach_function :zesFrequencyOcGetFrequencyTarget,
                    [ :zes_freq_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFrequencyOcGetFrequencyTarget in libze_loader.so"
  end

  begin
    attach_function :zesFrequencyOcSetFrequencyTarget,
                    [ :zes_freq_handle_t,
                    :double ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFrequencyOcSetFrequencyTarget in libze_loader.so"
  end

  begin
    attach_function :zesFrequencyOcGetVoltageTarget,
                    [ :zes_freq_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFrequencyOcGetVoltageTarget in libze_loader.so"
  end

  begin
    attach_function :zesFrequencyOcSetVoltageTarget,
                    [ :zes_freq_handle_t,
                    :double,
                    :double ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFrequencyOcSetVoltageTarget in libze_loader.so"
  end

  begin
    attach_function :zesFrequencyOcSetMode,
                    [ :zes_freq_handle_t,
                    :zes_oc_mode_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFrequencyOcSetMode in libze_loader.so"
  end

  begin
    attach_function :zesFrequencyOcGetMode,
                    [ :zes_freq_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFrequencyOcGetMode in libze_loader.so"
  end

  begin
    attach_function :zesFrequencyOcGetIccMax,
                    [ :zes_freq_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFrequencyOcGetIccMax in libze_loader.so"
  end

  begin
    attach_function :zesFrequencyOcSetIccMax,
                    [ :zes_freq_handle_t,
                    :double ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFrequencyOcSetIccMax in libze_loader.so"
  end

  begin
    attach_function :zesFrequencyOcGetTjMax,
                    [ :zes_freq_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFrequencyOcGetTjMax in libze_loader.so"
  end

  begin
    attach_function :zesFrequencyOcSetTjMax,
                    [ :zes_freq_handle_t,
                    :double ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFrequencyOcSetTjMax in libze_loader.so"
  end

  begin
    attach_function :zesDeviceEnumLeds,
                    [ :zes_device_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDeviceEnumLeds in libze_loader.so"
  end

  begin
    attach_function :zesLedGetProperties,
                    [ :zes_led_handle_t,
                    ZESLedProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesLedGetProperties in libze_loader.so"
  end

  begin
    attach_function :zesLedGetState,
                    [ :zes_led_handle_t,
                    ZESLedState.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesLedGetState in libze_loader.so"
  end

  begin
    attach_function :zesLedSetState,
                    [ :zes_led_handle_t,
                    :ze_bool_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesLedSetState in libze_loader.so"
  end

  begin
    attach_function :zesLedSetColor,
                    [ :zes_led_handle_t,
                    ZESLedColor.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesLedSetColor in libze_loader.so"
  end

  begin
    attach_function :zesDeviceEnumMemoryModules,
                    [ :zes_device_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDeviceEnumMemoryModules in libze_loader.so"
  end

  begin
    attach_function :zesMemoryGetProperties,
                    [ :zes_mem_handle_t,
                    ZESMemProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesMemoryGetProperties in libze_loader.so"
  end

  begin
    attach_function :zesMemoryGetState,
                    [ :zes_mem_handle_t,
                    ZESMemState.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesMemoryGetState in libze_loader.so"
  end

  begin
    attach_function :zesMemoryGetBandwidth,
                    [ :zes_mem_handle_t,
                    ZESMemBandwidth.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesMemoryGetBandwidth in libze_loader.so"
  end

  begin
    attach_function :zesDeviceEnumPerformanceFactorDomains,
                    [ :zes_device_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDeviceEnumPerformanceFactorDomains in libze_loader.so"
  end

  begin
    attach_function :zesPerformanceFactorGetProperties,
                    [ :zes_perf_handle_t,
                    ZESPerfProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesPerformanceFactorGetProperties in libze_loader.so"
  end

  begin
    attach_function :zesPerformanceFactorGetConfig,
                    [ :zes_perf_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesPerformanceFactorGetConfig in libze_loader.so"
  end

  begin
    attach_function :zesPerformanceFactorSetConfig,
                    [ :zes_perf_handle_t,
                    :double ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesPerformanceFactorSetConfig in libze_loader.so"
  end

  begin
    attach_function :zesDeviceEnumPowerDomains,
                    [ :zes_device_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDeviceEnumPowerDomains in libze_loader.so"
  end

  begin
    attach_function :zesDeviceGetCardPowerDomain,
                    [ :zes_device_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDeviceGetCardPowerDomain in libze_loader.so"
  end

  begin
    attach_function :zesPowerGetProperties,
                    [ :zes_pwr_handle_t,
                    ZESPowerProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesPowerGetProperties in libze_loader.so"
  end

  begin
    attach_function :zesPowerGetEnergyCounter,
                    [ :zes_pwr_handle_t,
                    ZESPowerEnergyCounter.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesPowerGetEnergyCounter in libze_loader.so"
  end

  begin
    attach_function :zesPowerGetLimits,
                    [ :zes_pwr_handle_t,
                    ZESPowerSustainedLimit.ptr,
                    ZESPowerBurstLimit.ptr,
                    ZESPowerPeakLimit.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesPowerGetLimits in libze_loader.so"
  end

  begin
    attach_function :zesPowerSetLimits,
                    [ :zes_pwr_handle_t,
                    ZESPowerSustainedLimit.ptr,
                    ZESPowerBurstLimit.ptr,
                    ZESPowerPeakLimit.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesPowerSetLimits in libze_loader.so"
  end

  begin
    attach_function :zesPowerGetEnergyThreshold,
                    [ :zes_pwr_handle_t,
                    ZESEnergyThreshold.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesPowerGetEnergyThreshold in libze_loader.so"
  end

  begin
    attach_function :zesPowerSetEnergyThreshold,
                    [ :zes_pwr_handle_t,
                    :double ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesPowerSetEnergyThreshold in libze_loader.so"
  end

  begin
    attach_function :zesDeviceEnumPsus,
                    [ :zes_device_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDeviceEnumPsus in libze_loader.so"
  end

  begin
    attach_function :zesPsuGetProperties,
                    [ :zes_psu_handle_t,
                    ZESPsuProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesPsuGetProperties in libze_loader.so"
  end

  begin
    attach_function :zesPsuGetState,
                    [ :zes_psu_handle_t,
                    ZESPsuState.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesPsuGetState in libze_loader.so"
  end

  begin
    attach_function :zesDeviceEnumRasErrorSets,
                    [ :zes_device_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDeviceEnumRasErrorSets in libze_loader.so"
  end

  begin
    attach_function :zesRasGetProperties,
                    [ :zes_ras_handle_t,
                    ZESRasProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesRasGetProperties in libze_loader.so"
  end

  begin
    attach_function :zesRasGetConfig,
                    [ :zes_ras_handle_t,
                    ZESRasConfig.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesRasGetConfig in libze_loader.so"
  end

  begin
    attach_function :zesRasSetConfig,
                    [ :zes_ras_handle_t,
                    ZESRasConfig.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesRasSetConfig in libze_loader.so"
  end

  begin
    attach_function :zesRasGetState,
                    [ :zes_ras_handle_t,
                    :ze_bool_t,
                    ZESRasState.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesRasGetState in libze_loader.so"
  end

  begin
    attach_function :zesDeviceEnumSchedulers,
                    [ :zes_device_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDeviceEnumSchedulers in libze_loader.so"
  end

  begin
    attach_function :zesSchedulerGetProperties,
                    [ :zes_sched_handle_t,
                    ZESSchedProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesSchedulerGetProperties in libze_loader.so"
  end

  begin
    attach_function :zesSchedulerGetCurrentMode,
                    [ :zes_sched_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesSchedulerGetCurrentMode in libze_loader.so"
  end

  begin
    attach_function :zesSchedulerGetTimeoutModeProperties,
                    [ :zes_sched_handle_t,
                    :ze_bool_t,
                    ZESSchedTimeoutProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesSchedulerGetTimeoutModeProperties in libze_loader.so"
  end

  begin
    attach_function :zesSchedulerGetTimesliceModeProperties,
                    [ :zes_sched_handle_t,
                    :ze_bool_t,
                    ZESSchedTimesliceProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesSchedulerGetTimesliceModeProperties in libze_loader.so"
  end

  begin
    attach_function :zesSchedulerSetTimeoutMode,
                    [ :zes_sched_handle_t,
                    ZESSchedTimeoutProperties.ptr,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesSchedulerSetTimeoutMode in libze_loader.so"
  end

  begin
    attach_function :zesSchedulerSetTimesliceMode,
                    [ :zes_sched_handle_t,
                    ZESSchedTimesliceProperties.ptr,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesSchedulerSetTimesliceMode in libze_loader.so"
  end

  begin
    attach_function :zesSchedulerSetExclusiveMode,
                    [ :zes_sched_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesSchedulerSetExclusiveMode in libze_loader.so"
  end

  begin
    attach_function :zesSchedulerSetComputeUnitDebugMode,
                    [ :zes_sched_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesSchedulerSetComputeUnitDebugMode in libze_loader.so"
  end

  begin
    attach_function :zesDeviceEnumStandbyDomains,
                    [ :zes_device_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDeviceEnumStandbyDomains in libze_loader.so"
  end

  begin
    attach_function :zesStandbyGetProperties,
                    [ :zes_standby_handle_t,
                    ZESStandbyProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesStandbyGetProperties in libze_loader.so"
  end

  begin
    attach_function :zesStandbyGetMode,
                    [ :zes_standby_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesStandbyGetMode in libze_loader.so"
  end

  begin
    attach_function :zesStandbySetMode,
                    [ :zes_standby_handle_t,
                    :zes_standby_promo_mode_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesStandbySetMode in libze_loader.so"
  end

  begin
    attach_function :zesDeviceEnumTemperatureSensors,
                    [ :zes_device_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDeviceEnumTemperatureSensors in libze_loader.so"
  end

  begin
    attach_function :zesTemperatureGetProperties,
                    [ :zes_temp_handle_t,
                    ZESTempProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesTemperatureGetProperties in libze_loader.so"
  end

  begin
    attach_function :zesTemperatureGetConfig,
                    [ :zes_temp_handle_t,
                    ZESTempConfig.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesTemperatureGetConfig in libze_loader.so"
  end

  begin
    attach_function :zesTemperatureSetConfig,
                    [ :zes_temp_handle_t,
                    ZESTempConfig.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesTemperatureSetConfig in libze_loader.so"
  end

  begin
    attach_function :zesTemperatureGetState,
                    [ :zes_temp_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesTemperatureGetState in libze_loader.so"
  end

  begin
    attach_function :zesPowerGetLimitsExt,
                    [ :zes_pwr_handle_t,
                    :pointer,
                    ZESPowerLimitExtDesc.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesPowerGetLimitsExt in libze_loader.so"
  end

  begin
    attach_function :zesPowerSetLimitsExt,
                    [ :zes_pwr_handle_t,
                    :pointer,
                    ZESPowerLimitExtDesc.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesPowerSetLimitsExt in libze_loader.so"
  end

  begin
    attach_function :zesEngineGetActivityExt,
                    [ :zes_engine_handle_t,
                    :pointer,
                    ZESEngineStats.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesEngineGetActivityExt in libze_loader.so"
  end

  begin
    attach_function :zesRasGetStateExp,
                    [ :zes_ras_handle_t,
                    :pointer,
                    ZESRasStateExp.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesRasGetStateExp in libze_loader.so"
  end

  begin
    attach_function :zesRasClearStateExp,
                    [ :zes_ras_handle_t,
                    :zes_ras_error_category_exp_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesRasClearStateExp in libze_loader.so"
  end

  begin
    attach_function :zesFirmwareGetSecurityVersionExp,
                    [ :zes_firmware_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFirmwareGetSecurityVersionExp in libze_loader.so"
  end

  begin
    attach_function :zesFirmwareSetSecurityVersionExp,
                    [ :zes_firmware_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesFirmwareSetSecurityVersionExp in libze_loader.so"
  end

  begin
    attach_function :zesDeviceGetSubDevicePropertiesExp,
                    [ :zes_device_handle_t,
                    :pointer,
                    ZESSubdeviceExpProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDeviceGetSubDevicePropertiesExp in libze_loader.so"
  end

  begin
    attach_function :zesDriverGetDeviceByUuidExp,
                    [ :zes_driver_handle_t,
                    :zes_uuid_t,
                    :pointer,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDriverGetDeviceByUuidExp in libze_loader.so"
  end

  begin
    attach_function :zesDeviceEnumActiveVFExp,
                    [ :zes_device_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDeviceEnumActiveVFExp in libze_loader.so"
  end

  begin
    attach_function :zesVFManagementGetVFPropertiesExp,
                    [ :zes_vf_handle_t,
                    ZESVfExpProperties.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesVFManagementGetVFPropertiesExp in libze_loader.so"
  end

  begin
    attach_function :zesVFManagementGetVFMemoryUtilizationExp,
                    [ :zes_vf_handle_t,
                    :pointer,
                    ZESVfUtilMemExp.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesVFManagementGetVFMemoryUtilizationExp in libze_loader.so"
  end

  begin
    attach_function :zesVFManagementGetVFEngineUtilizationExp,
                    [ :zes_vf_handle_t,
                    :pointer,
                    ZESVfUtilEngineExp.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesVFManagementGetVFEngineUtilizationExp in libze_loader.so"
  end

  begin
    attach_function :zesVFManagementSetVFTelemetryModeExp,
                    [ :zes_vf_handle_t,
                    :zes_vf_info_util_exp_flags_t,
                    :ze_bool_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesVFManagementSetVFTelemetryModeExp in libze_loader.so"
  end

  begin
    attach_function :zesVFManagementSetVFTelemetrySamplingIntervalExp,
                    [ :zes_vf_handle_t,
                    :zes_vf_info_util_exp_flags_t,
                    :uint64 ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesVFManagementSetVFTelemetrySamplingIntervalExp in libze_loader.so"
  end

  begin
    attach_function :zesDeviceEnumEnabledVFExp,
                    [ :zes_device_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesDeviceEnumEnabledVFExp in libze_loader.so"
  end

  begin
    attach_function :zesVFManagementGetVFCapabilitiesExp,
                    [ :zes_vf_handle_t,
                    ZESVfExpCapabilities.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesVFManagementGetVFCapabilitiesExp in libze_loader.so"
  end

  begin
    attach_function :zesVFManagementGetVFMemoryUtilizationExp2,
                    [ :zes_vf_handle_t,
                    :pointer,
                    ZESVfUtilMemExp2.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesVFManagementGetVFMemoryUtilizationExp2 in libze_loader.so"
  end

  begin
    attach_function :zesVFManagementGetVFEngineUtilizationExp2,
                    [ :zes_vf_handle_t,
                    :pointer,
                    ZESVfUtilEngineExp2.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesVFManagementGetVFEngineUtilizationExp2 in libze_loader.so"
  end

  begin
    attach_function :zesVFManagementGetVFCapabilitiesExp2,
                    [ :zes_vf_handle_t,
                    ZESVfExp2Capabilities.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesVFManagementGetVFCapabilitiesExp2 in libze_loader.so"
  end

  begin
    attach_function :zesGetGlobalProcAddrTable,
                    [ :ze_api_version_t,
                    ZESGlobalDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesGetGlobalProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zesGetDeviceProcAddrTable,
                    [ :ze_api_version_t,
                    ZESDeviceDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesGetDeviceProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zesGetDeviceExpProcAddrTable,
                    [ :ze_api_version_t,
                    ZESDeviceExpDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesGetDeviceExpProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zesGetDriverProcAddrTable,
                    [ :ze_api_version_t,
                    ZESDriverDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesGetDriverProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zesGetDriverExpProcAddrTable,
                    [ :ze_api_version_t,
                    ZESDriverExpDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesGetDriverExpProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zesGetOverclockProcAddrTable,
                    [ :ze_api_version_t,
                    ZESOverclockDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesGetOverclockProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zesGetSchedulerProcAddrTable,
                    [ :ze_api_version_t,
                    ZESSchedulerDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesGetSchedulerProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zesGetPerformanceFactorProcAddrTable,
                    [ :ze_api_version_t,
                    ZESPerformanceFactorDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesGetPerformanceFactorProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zesGetPowerProcAddrTable,
                    [ :ze_api_version_t,
                    ZESPowerDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesGetPowerProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zesGetFrequencyProcAddrTable,
                    [ :ze_api_version_t,
                    ZESFrequencyDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesGetFrequencyProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zesGetEngineProcAddrTable,
                    [ :ze_api_version_t,
                    ZESEngineDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesGetEngineProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zesGetStandbyProcAddrTable,
                    [ :ze_api_version_t,
                    ZESStandbyDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesGetStandbyProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zesGetFirmwareProcAddrTable,
                    [ :ze_api_version_t,
                    ZESFirmwareDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesGetFirmwareProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zesGetFirmwareExpProcAddrTable,
                    [ :ze_api_version_t,
                    ZESFirmwareExpDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesGetFirmwareExpProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zesGetMemoryProcAddrTable,
                    [ :ze_api_version_t,
                    ZESMemoryDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesGetMemoryProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zesGetFabricPortProcAddrTable,
                    [ :ze_api_version_t,
                    ZESFabricPortDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesGetFabricPortProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zesGetTemperatureProcAddrTable,
                    [ :ze_api_version_t,
                    ZESTemperatureDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesGetTemperatureProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zesGetPsuProcAddrTable,
                    [ :ze_api_version_t,
                    ZESPsuDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesGetPsuProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zesGetFanProcAddrTable,
                    [ :ze_api_version_t,
                    ZESFanDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesGetFanProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zesGetLedProcAddrTable,
                    [ :ze_api_version_t,
                    ZESLedDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesGetLedProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zesGetRasProcAddrTable,
                    [ :ze_api_version_t,
                    ZESRasDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesGetRasProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zesGetRasExpProcAddrTable,
                    [ :ze_api_version_t,
                    ZESRasExpDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesGetRasExpProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zesGetDiagnosticsProcAddrTable,
                    [ :ze_api_version_t,
                    ZESDiagnosticsDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesGetDiagnosticsProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zesGetVFManagementExpProcAddrTable,
                    [ :ze_api_version_t,
                    ZESVfManagementExpDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zesGetVFManagementExpProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zelTracerCreate,
                    [ ZELTracerDesc.ptr,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCreate in libze_loader.so"
  end

  begin
    attach_function :zelTracerDestroy,
                    [ :zel_tracer_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerDestroy in libze_loader.so"
  end

  begin
    attach_function :zelTracerSetPrologues,
                    [ :zel_tracer_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerSetPrologues in libze_loader.so"
  end

  begin
    attach_function :zelTracerSetEpilogues,
                    [ :zel_tracer_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerSetEpilogues in libze_loader.so"
  end

  begin
    attach_function :zelTracerSetEnabled,
                    [ :zel_tracer_handle_t,
                    :ze_bool_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerSetEnabled in libze_loader.so"
  end

  begin
    attach_function :zelGetTracerApiProcAddrTable,
                    [ :ze_api_version_t,
                    ZELTracerDDITable.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelGetTracerApiProcAddrTable in libze_loader.so"
  end

  begin
    attach_function :zelTracerInitRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnInitCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerInitRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerDriverGetRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnDriverGetCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerDriverGetRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerInitDriversRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnInitDriversCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerInitDriversRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerDriverGetApiVersionRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnDriverGetApiVersionCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerDriverGetApiVersionRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerDriverGetPropertiesRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnDriverGetPropertiesCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerDriverGetPropertiesRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerDriverGetIpcPropertiesRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnDriverGetIpcPropertiesCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerDriverGetIpcPropertiesRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerDriverGetExtensionPropertiesRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnDriverGetExtensionPropertiesCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerDriverGetExtensionPropertiesRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerDriverGetExtensionFunctionAddressRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnDriverGetExtensionFunctionAddressCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerDriverGetExtensionFunctionAddressRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerDriverGetLastErrorDescriptionRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnDriverGetLastErrorDescriptionCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerDriverGetLastErrorDescriptionRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerDeviceGetRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnDeviceGetCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerDeviceGetRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerDeviceGetRootDeviceRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnDeviceGetRootDeviceCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerDeviceGetRootDeviceRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerDeviceGetSubDevicesRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnDeviceGetSubDevicesCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerDeviceGetSubDevicesRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerDeviceGetPropertiesRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnDeviceGetPropertiesCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerDeviceGetPropertiesRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerDeviceGetComputePropertiesRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnDeviceGetComputePropertiesCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerDeviceGetComputePropertiesRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerDeviceGetModulePropertiesRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnDeviceGetModulePropertiesCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerDeviceGetModulePropertiesRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerDeviceGetCommandQueueGroupPropertiesRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnDeviceGetCommandQueueGroupPropertiesCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerDeviceGetCommandQueueGroupPropertiesRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerDeviceGetMemoryPropertiesRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnDeviceGetMemoryPropertiesCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerDeviceGetMemoryPropertiesRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerDeviceGetMemoryAccessPropertiesRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnDeviceGetMemoryAccessPropertiesCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerDeviceGetMemoryAccessPropertiesRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerDeviceGetCachePropertiesRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnDeviceGetCachePropertiesCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerDeviceGetCachePropertiesRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerDeviceGetImagePropertiesRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnDeviceGetImagePropertiesCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerDeviceGetImagePropertiesRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerDeviceGetExternalMemoryPropertiesRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnDeviceGetExternalMemoryPropertiesCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerDeviceGetExternalMemoryPropertiesRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerDeviceGetP2PPropertiesRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnDeviceGetP2PPropertiesCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerDeviceGetP2PPropertiesRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerDeviceCanAccessPeerRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnDeviceCanAccessPeerCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerDeviceCanAccessPeerRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerDeviceGetStatusRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnDeviceGetStatusCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerDeviceGetStatusRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerDeviceGetGlobalTimestampsRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnDeviceGetGlobalTimestampsCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerDeviceGetGlobalTimestampsRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerContextCreateRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnContextCreateCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerContextCreateRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerContextCreateExRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnContextCreateExCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerContextCreateExRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerContextDestroyRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnContextDestroyCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerContextDestroyRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerContextGetStatusRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnContextGetStatusCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerContextGetStatusRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandQueueCreateRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandQueueCreateCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandQueueCreateRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandQueueDestroyRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandQueueDestroyCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandQueueDestroyRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandQueueExecuteCommandListsRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandQueueExecuteCommandListsCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandQueueExecuteCommandListsRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandQueueSynchronizeRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandQueueSynchronizeCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandQueueSynchronizeRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandQueueGetOrdinalRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandQueueGetOrdinalCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandQueueGetOrdinalRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandQueueGetIndexRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandQueueGetIndexCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandQueueGetIndexRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListCreateRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListCreateCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListCreateRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListCreateImmediateRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListCreateImmediateCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListCreateImmediateRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListDestroyRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListDestroyCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListDestroyRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListCloseRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListCloseCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListCloseRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListResetRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListResetCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListResetRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListAppendWriteGlobalTimestampRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListAppendWriteGlobalTimestampCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListAppendWriteGlobalTimestampRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListHostSynchronizeRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListHostSynchronizeCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListHostSynchronizeRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListGetDeviceHandleRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListGetDeviceHandleCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListGetDeviceHandleRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListGetContextHandleRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListGetContextHandleCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListGetContextHandleRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListGetOrdinalRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListGetOrdinalCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListGetOrdinalRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListImmediateGetIndexRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListImmediateGetIndexCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListImmediateGetIndexRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListIsImmediateRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListIsImmediateCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListIsImmediateRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListAppendBarrierRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListAppendBarrierCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListAppendBarrierRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListAppendMemoryRangesBarrierRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListAppendMemoryRangesBarrierCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListAppendMemoryRangesBarrierRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerContextSystemBarrierRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnContextSystemBarrierCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerContextSystemBarrierRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListAppendMemoryCopyRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListAppendMemoryCopyCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListAppendMemoryCopyRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListAppendMemoryFillRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListAppendMemoryFillCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListAppendMemoryFillRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListAppendMemoryCopyRegionRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListAppendMemoryCopyRegionCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListAppendMemoryCopyRegionRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListAppendMemoryCopyFromContextRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListAppendMemoryCopyFromContextCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListAppendMemoryCopyFromContextRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListAppendImageCopyRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListAppendImageCopyCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListAppendImageCopyRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListAppendImageCopyRegionRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListAppendImageCopyRegionCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListAppendImageCopyRegionRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListAppendImageCopyToMemoryRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListAppendImageCopyToMemoryCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListAppendImageCopyToMemoryRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListAppendImageCopyFromMemoryRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListAppendImageCopyFromMemoryCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListAppendImageCopyFromMemoryRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListAppendMemoryPrefetchRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListAppendMemoryPrefetchCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListAppendMemoryPrefetchRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListAppendMemAdviseRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListAppendMemAdviseCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListAppendMemAdviseRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerEventPoolCreateRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnEventPoolCreateCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerEventPoolCreateRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerEventPoolDestroyRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnEventPoolDestroyCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerEventPoolDestroyRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerEventCreateRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnEventCreateCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerEventCreateRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerEventDestroyRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnEventDestroyCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerEventDestroyRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerEventPoolGetIpcHandleRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnEventPoolGetIpcHandleCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerEventPoolGetIpcHandleRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerEventPoolPutIpcHandleRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnEventPoolPutIpcHandleCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerEventPoolPutIpcHandleRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerEventPoolOpenIpcHandleRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnEventPoolOpenIpcHandleCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerEventPoolOpenIpcHandleRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerEventPoolCloseIpcHandleRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnEventPoolCloseIpcHandleCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerEventPoolCloseIpcHandleRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListAppendSignalEventRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListAppendSignalEventCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListAppendSignalEventRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListAppendWaitOnEventsRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListAppendWaitOnEventsCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListAppendWaitOnEventsRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerEventHostSignalRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnEventHostSignalCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerEventHostSignalRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerEventHostSynchronizeRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnEventHostSynchronizeCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerEventHostSynchronizeRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerEventQueryStatusRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnEventQueryStatusCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerEventQueryStatusRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListAppendEventResetRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListAppendEventResetCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListAppendEventResetRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerEventHostResetRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnEventHostResetCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerEventHostResetRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerEventQueryKernelTimestampRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnEventQueryKernelTimestampCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerEventQueryKernelTimestampRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListAppendQueryKernelTimestampsRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListAppendQueryKernelTimestampsCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListAppendQueryKernelTimestampsRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerEventGetEventPoolRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnEventGetEventPoolCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerEventGetEventPoolRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerEventGetSignalScopeRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnEventGetSignalScopeCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerEventGetSignalScopeRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerEventGetWaitScopeRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnEventGetWaitScopeCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerEventGetWaitScopeRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerEventPoolGetContextHandleRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnEventPoolGetContextHandleCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerEventPoolGetContextHandleRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerEventPoolGetFlagsRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnEventPoolGetFlagsCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerEventPoolGetFlagsRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerFenceCreateRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnFenceCreateCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerFenceCreateRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerFenceDestroyRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnFenceDestroyCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerFenceDestroyRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerFenceHostSynchronizeRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnFenceHostSynchronizeCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerFenceHostSynchronizeRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerFenceQueryStatusRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnFenceQueryStatusCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerFenceQueryStatusRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerFenceResetRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnFenceResetCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerFenceResetRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerImageGetPropertiesRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnImageGetPropertiesCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerImageGetPropertiesRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerImageCreateRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnImageCreateCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerImageCreateRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerImageDestroyRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnImageDestroyCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerImageDestroyRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerMemAllocSharedRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnMemAllocSharedCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerMemAllocSharedRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerMemAllocDeviceRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnMemAllocDeviceCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerMemAllocDeviceRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerMemAllocHostRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnMemAllocHostCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerMemAllocHostRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerMemFreeRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnMemFreeCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerMemFreeRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerMemGetAllocPropertiesRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnMemGetAllocPropertiesCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerMemGetAllocPropertiesRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerMemGetAddressRangeRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnMemGetAddressRangeCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerMemGetAddressRangeRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerMemGetIpcHandleRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnMemGetIpcHandleCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerMemGetIpcHandleRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerMemGetIpcHandleFromFileDescriptorExpRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnMemGetIpcHandleFromFileDescriptorExpCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerMemGetIpcHandleFromFileDescriptorExpRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerMemGetFileDescriptorFromIpcHandleExpRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnMemGetFileDescriptorFromIpcHandleExpCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerMemGetFileDescriptorFromIpcHandleExpRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerMemPutIpcHandleRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnMemPutIpcHandleCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerMemPutIpcHandleRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerMemOpenIpcHandleRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnMemOpenIpcHandleCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerMemOpenIpcHandleRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerMemCloseIpcHandleRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnMemCloseIpcHandleCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerMemCloseIpcHandleRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerMemSetAtomicAccessAttributeExpRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnMemSetAtomicAccessAttributeExpCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerMemSetAtomicAccessAttributeExpRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerMemGetAtomicAccessAttributeExpRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnMemGetAtomicAccessAttributeExpCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerMemGetAtomicAccessAttributeExpRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerModuleCreateRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnModuleCreateCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerModuleCreateRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerModuleDestroyRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnModuleDestroyCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerModuleDestroyRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerModuleDynamicLinkRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnModuleDynamicLinkCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerModuleDynamicLinkRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerModuleBuildLogDestroyRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnModuleBuildLogDestroyCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerModuleBuildLogDestroyRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerModuleBuildLogGetStringRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnModuleBuildLogGetStringCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerModuleBuildLogGetStringRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerModuleGetNativeBinaryRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnModuleGetNativeBinaryCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerModuleGetNativeBinaryRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerModuleGetGlobalPointerRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnModuleGetGlobalPointerCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerModuleGetGlobalPointerRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerModuleGetKernelNamesRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnModuleGetKernelNamesCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerModuleGetKernelNamesRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerModuleGetPropertiesRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnModuleGetPropertiesCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerModuleGetPropertiesRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerKernelCreateRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnKernelCreateCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerKernelCreateRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerKernelDestroyRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnKernelDestroyCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerKernelDestroyRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerModuleGetFunctionPointerRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnModuleGetFunctionPointerCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerModuleGetFunctionPointerRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerKernelSetGroupSizeRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnKernelSetGroupSizeCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerKernelSetGroupSizeRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerKernelSuggestGroupSizeRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnKernelSuggestGroupSizeCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerKernelSuggestGroupSizeRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerKernelSuggestMaxCooperativeGroupCountRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnKernelSuggestMaxCooperativeGroupCountCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerKernelSuggestMaxCooperativeGroupCountRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerKernelSetArgumentValueRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnKernelSetArgumentValueCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerKernelSetArgumentValueRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerKernelSetIndirectAccessRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnKernelSetIndirectAccessCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerKernelSetIndirectAccessRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerKernelGetIndirectAccessRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnKernelGetIndirectAccessCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerKernelGetIndirectAccessRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerKernelGetSourceAttributesRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnKernelGetSourceAttributesCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerKernelGetSourceAttributesRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerKernelSetCacheConfigRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnKernelSetCacheConfigCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerKernelSetCacheConfigRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerKernelGetPropertiesRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnKernelGetPropertiesCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerKernelGetPropertiesRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerKernelGetNameRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnKernelGetNameCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerKernelGetNameRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListAppendLaunchKernelRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListAppendLaunchKernelCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListAppendLaunchKernelRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListAppendLaunchCooperativeKernelRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListAppendLaunchCooperativeKernelCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListAppendLaunchCooperativeKernelRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListAppendLaunchKernelIndirectRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListAppendLaunchKernelIndirectCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListAppendLaunchKernelIndirectRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListAppendLaunchMultipleKernelsIndirectRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListAppendLaunchMultipleKernelsIndirectCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListAppendLaunchMultipleKernelsIndirectRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerContextMakeMemoryResidentRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnContextMakeMemoryResidentCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerContextMakeMemoryResidentRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerContextEvictMemoryRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnContextEvictMemoryCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerContextEvictMemoryRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerContextMakeImageResidentRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnContextMakeImageResidentCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerContextMakeImageResidentRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerContextEvictImageRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnContextEvictImageCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerContextEvictImageRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerSamplerCreateRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnSamplerCreateCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerSamplerCreateRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerSamplerDestroyRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnSamplerDestroyCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerSamplerDestroyRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerVirtualMemReserveRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnVirtualMemReserveCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerVirtualMemReserveRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerVirtualMemFreeRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnVirtualMemFreeCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerVirtualMemFreeRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerVirtualMemQueryPageSizeRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnVirtualMemQueryPageSizeCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerVirtualMemQueryPageSizeRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerPhysicalMemCreateRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnPhysicalMemCreateCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerPhysicalMemCreateRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerPhysicalMemDestroyRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnPhysicalMemDestroyCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerPhysicalMemDestroyRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerVirtualMemMapRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnVirtualMemMapCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerVirtualMemMapRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerVirtualMemUnmapRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnVirtualMemUnmapCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerVirtualMemUnmapRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerVirtualMemSetAccessAttributeRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnVirtualMemSetAccessAttributeCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerVirtualMemSetAccessAttributeRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerVirtualMemGetAccessAttributeRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnVirtualMemGetAccessAttributeCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerVirtualMemGetAccessAttributeRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerKernelSetGlobalOffsetExpRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnKernelSetGlobalOffsetExpCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerKernelSetGlobalOffsetExpRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerKernelGetBinaryExpRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnKernelGetBinaryExpCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerKernelGetBinaryExpRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerDeviceImportExternalSemaphoreExtRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnDeviceImportExternalSemaphoreExtCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerDeviceImportExternalSemaphoreExtRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerDeviceReleaseExternalSemaphoreExtRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnDeviceReleaseExternalSemaphoreExtCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerDeviceReleaseExternalSemaphoreExtRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListAppendSignalExternalSemaphoreExtRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListAppendSignalExternalSemaphoreExtCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListAppendSignalExternalSemaphoreExtRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListAppendWaitExternalSemaphoreExtRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListAppendWaitExternalSemaphoreExtCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListAppendWaitExternalSemaphoreExtRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerRTASBuilderCreateExtRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnRTASBuilderCreateExtCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerRTASBuilderCreateExtRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerRTASBuilderGetBuildPropertiesExtRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnRTASBuilderGetBuildPropertiesExtCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerRTASBuilderGetBuildPropertiesExtRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerDriverRTASFormatCompatibilityCheckExtRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnDriverRTASFormatCompatibilityCheckExtCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerDriverRTASFormatCompatibilityCheckExtRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerRTASBuilderBuildExtRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnRTASBuilderBuildExtCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerRTASBuilderBuildExtRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerRTASBuilderCommandListAppendCopyExtRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnRTASBuilderCommandListAppendCopyExtCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerRTASBuilderCommandListAppendCopyExtRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerRTASBuilderDestroyExtRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnRTASBuilderDestroyExtCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerRTASBuilderDestroyExtRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerRTASParallelOperationCreateExtRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnRTASParallelOperationCreateExtCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerRTASParallelOperationCreateExtRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerRTASParallelOperationGetPropertiesExtRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnRTASParallelOperationGetPropertiesExtCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerRTASParallelOperationGetPropertiesExtRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerRTASParallelOperationJoinExtRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnRTASParallelOperationJoinExtCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerRTASParallelOperationJoinExtRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerRTASParallelOperationDestroyExtRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnRTASParallelOperationDestroyExtCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerRTASParallelOperationDestroyExtRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerDeviceGetVectorWidthPropertiesExtRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnDeviceGetVectorWidthPropertiesExtCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerDeviceGetVectorWidthPropertiesExtRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerDeviceReserveCacheExtRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnDeviceReserveCacheExtCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerDeviceReserveCacheExtRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerDeviceSetCacheAdviceExtRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnDeviceSetCacheAdviceExtCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerDeviceSetCacheAdviceExtRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerEventQueryTimestampsExpRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnEventQueryTimestampsExpCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerEventQueryTimestampsExpRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerImageGetMemoryPropertiesExpRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnImageGetMemoryPropertiesExpCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerImageGetMemoryPropertiesExpRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerImageViewCreateExtRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnImageViewCreateExtCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerImageViewCreateExtRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerImageViewCreateExpRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnImageViewCreateExpCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerImageViewCreateExpRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerKernelSchedulingHintExpRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnKernelSchedulingHintExpCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerKernelSchedulingHintExpRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerDevicePciGetPropertiesExtRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnDevicePciGetPropertiesExtCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerDevicePciGetPropertiesExtRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListAppendImageCopyToMemoryExtRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListAppendImageCopyToMemoryExtCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListAppendImageCopyToMemoryExtRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListAppendImageCopyFromMemoryExtRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListAppendImageCopyFromMemoryExtCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListAppendImageCopyFromMemoryExtRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerImageGetAllocPropertiesExtRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnImageGetAllocPropertiesExtCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerImageGetAllocPropertiesExtRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerModuleInspectLinkageExtRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnModuleInspectLinkageExtCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerModuleInspectLinkageExtRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerMemFreeExtRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnMemFreeExtCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerMemFreeExtRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerFabricVertexGetExpRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnFabricVertexGetExpCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerFabricVertexGetExpRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerFabricVertexGetSubVerticesExpRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnFabricVertexGetSubVerticesExpCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerFabricVertexGetSubVerticesExpRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerFabricVertexGetPropertiesExpRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnFabricVertexGetPropertiesExpCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerFabricVertexGetPropertiesExpRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerFabricVertexGetDeviceExpRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnFabricVertexGetDeviceExpCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerFabricVertexGetDeviceExpRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerDeviceGetFabricVertexExpRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnDeviceGetFabricVertexExpCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerDeviceGetFabricVertexExpRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerFabricEdgeGetExpRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnFabricEdgeGetExpCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerFabricEdgeGetExpRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerFabricEdgeGetVerticesExpRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnFabricEdgeGetVerticesExpCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerFabricEdgeGetVerticesExpRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerFabricEdgeGetPropertiesExpRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnFabricEdgeGetPropertiesExpCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerFabricEdgeGetPropertiesExpRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerEventQueryKernelTimestampsExtRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnEventQueryKernelTimestampsExtCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerEventQueryKernelTimestampsExtRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerRTASBuilderCreateExpRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnRTASBuilderCreateExpCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerRTASBuilderCreateExpRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerRTASBuilderGetBuildPropertiesExpRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnRTASBuilderGetBuildPropertiesExpCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerRTASBuilderGetBuildPropertiesExpRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerDriverRTASFormatCompatibilityCheckExpRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnDriverRTASFormatCompatibilityCheckExpCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerDriverRTASFormatCompatibilityCheckExpRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerRTASBuilderBuildExpRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnRTASBuilderBuildExpCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerRTASBuilderBuildExpRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerRTASBuilderDestroyExpRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnRTASBuilderDestroyExpCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerRTASBuilderDestroyExpRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerRTASParallelOperationCreateExpRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnRTASParallelOperationCreateExpCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerRTASParallelOperationCreateExpRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerRTASParallelOperationGetPropertiesExpRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnRTASParallelOperationGetPropertiesExpCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerRTASParallelOperationGetPropertiesExpRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerRTASParallelOperationJoinExpRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnRTASParallelOperationJoinExpCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerRTASParallelOperationJoinExpRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerRTASParallelOperationDestroyExpRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnRTASParallelOperationDestroyExpCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerRTASParallelOperationDestroyExpRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerMemGetPitchFor2dImageRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnMemGetPitchFor2dImageCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerMemGetPitchFor2dImageRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerImageGetDeviceOffsetExpRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnImageGetDeviceOffsetExpCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerImageGetDeviceOffsetExpRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListCreateCloneExpRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListCreateCloneExpCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListCreateCloneExpRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListImmediateAppendCommandListsExpRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListImmediateAppendCommandListsExpCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListImmediateAppendCommandListsExpRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListGetNextCommandIdExpRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListGetNextCommandIdExpCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListGetNextCommandIdExpRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListGetNextCommandIdWithKernelsExpRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListGetNextCommandIdWithKernelsExpCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListGetNextCommandIdWithKernelsExpRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListUpdateMutableCommandsExpRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListUpdateMutableCommandsExpCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListUpdateMutableCommandsExpRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListUpdateMutableCommandSignalEventExpRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListUpdateMutableCommandSignalEventExpCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListUpdateMutableCommandSignalEventExpRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListUpdateMutableCommandWaitEventsExpRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListUpdateMutableCommandWaitEventsExpCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListUpdateMutableCommandWaitEventsExpRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelTracerCommandListUpdateMutableCommandKernelsExpRegisterCallback,
                    [ :zel_tracer_handle_t,
                    :zel_tracer_reg_t,
                    :ze_pfnCommandListUpdateMutableCommandKernelsExpCb_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelTracerCommandListUpdateMutableCommandKernelsExpRegisterCallback in libze_loader.so"
  end

  begin
    attach_function :zelLoaderGetVersions,
                    [ :pointer,
                    ZELComponentVersion.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelLoaderGetVersions in libze_loader.so"
  end

  begin
    attach_function :zelLoaderTranslateHandle,
                    [ :zel_handle_type_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelLoaderTranslateHandle in libze_loader.so"
  end

  begin
    attach_function :zelSetDriverTeardown,
                    [  ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelSetDriverTeardown in libze_loader.so"
  end

  begin
    attach_function :zelSetDelayLoaderContextTeardown,
                    [  ],
                    :void
  rescue FFI::NotFoundError
    warn "Missing zelSetDelayLoaderContextTeardown in libze_loader.so"
  end

  begin
    attach_function :zelLoaderContextTeardown,
                    [  ],
                    :void
  rescue FFI::NotFoundError
    warn "Missing zelLoaderContextTeardown in libze_loader.so"
  end

  begin
    attach_function :zelEnableTracingLayer,
                    [  ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelEnableTracingLayer in libze_loader.so"
  end

  begin
    attach_function :zelCheckIsLoaderInTearDown,
                    [  ],
                    :bool
  rescue FFI::NotFoundError
    warn "Missing zelCheckIsLoaderInTearDown in libze_loader.so"
  end

  begin
    attach_function :zelRegisterTeardownCallback,
                    [ :zel_loader_teardown_callback_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelRegisterTeardownCallback in libze_loader.so"
  end

  begin
    attach_function :zelDisableTracingLayer,
                    [  ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelDisableTracingLayer in libze_loader.so"
  end

  begin
    attach_function :zelLoaderDriverCheck,
                    [ :ze_init_flags_t,
                    ZEInitDriverTypeDesc.ptr,
                    ZEGlobalDDITable.ptr,
                    :pointer,
                    :pointer,
                    :bool ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelLoaderDriverCheck in libze_loader.so"
  end

  begin
    attach_function :zelLoaderTracingLayerInit,
                    [ :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelLoaderTracingLayerInit in libze_loader.so"
  end

  begin
    attach_function :zeLoaderGetTracingHandle,
                    [  ],
                    :pointer
  rescue FFI::NotFoundError
    warn "Missing zeLoaderGetTracingHandle in libze_loader.so"
  end

  begin
    attach_function :zelLoaderGetContext,
                    [  ],
                    :pointer
  rescue FFI::NotFoundError
    warn "Missing zelLoaderGetContext in libze_loader.so"
  end

  begin
    attach_function :zelLoaderGetVersionsInternal,
                    [ :pointer,
                    ZELComponentVersion.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelLoaderGetVersionsInternal in libze_loader.so"
  end

  begin
    attach_function :zelLoaderTranslateHandleInternal,
                    [ :zel_handle_type_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zelLoaderTranslateHandleInternal in libze_loader.so"
  end

  begin
    attach_function :zexKernelGetBaseAddress,
                    [ :ze_kernel_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zexKernelGetBaseAddress in libze_loader.so"
  end

  begin
    attach_function :zexKernelGetArgumentSize,
                    [ :ze_kernel_handle_t,
                    :uint32,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zexKernelGetArgumentSize in libze_loader.so"
  end

  begin
    attach_function :zexKernelGetArgumentType,
                    [ :ze_kernel_handle_t,
                    :uint32,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zexKernelGetArgumentType in libze_loader.so"
  end

  begin
    attach_function :zexDriverImportExternalPointer,
                    [ :ze_driver_handle_t,
                    :pointer,
                    :size_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zexDriverImportExternalPointer in libze_loader.so"
  end

  begin
    attach_function :zexDriverReleaseImportedPointer,
                    [ :ze_driver_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zexDriverReleaseImportedPointer in libze_loader.so"
  end

  begin
    attach_function :zexDriverGetHostPointerBaseAddress,
                    [ :ze_driver_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zexDriverGetHostPointerBaseAddress in libze_loader.so"
  end

  begin
    attach_function :zexMemGetIpcHandles,
                    [ :ze_context_handle_t,
                    :pointer,
                    :pointer,
                    ZEIpcMemHandle.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zexMemGetIpcHandles in libze_loader.so"
  end

  begin
    attach_function :zexMemOpenIpcHandles,
                    [ :ze_context_handle_t,
                    :ze_device_handle_t,
                    :uint32,
                    ZEIpcMemHandle.ptr,
                    :ze_ipc_memory_flags_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zexMemOpenIpcHandles in libze_loader.so"
  end

  begin
    attach_function :zexCommandListAppendWaitOnMemory,
                    [ :ze_command_list_handle_t,
                    ZEXWaitOnMemDesc.ptr,
                    :pointer,
                    :uint32,
                    :ze_event_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zexCommandListAppendWaitOnMemory in libze_loader.so"
  end

  begin
    attach_function :zexCommandListAppendWriteToMemory,
                    [ :ze_command_list_handle_t,
                    ZEXWriteToMemDesc.ptr,
                    :pointer,
                    :uint64 ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zexCommandListAppendWriteToMemory in libze_loader.so"
  end

  begin
    attach_function :zexEventGetDeviceAddress,
                    [ :ze_event_handle_t,
                    :pointer,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zexEventGetDeviceAddress in libze_loader.so"
  end

  begin
    attach_function :zexCounterBasedEventCreate,
                    [ :ze_context_handle_t,
                    :ze_device_handle_t,
                    :pointer,
                    :pointer,
                    :uint64,
                    ZEEventDesc.ptr,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zexCounterBasedEventCreate in libze_loader.so"
  end

  begin
    attach_function :zexCounterBasedEventGetIpcHandle,
                    [ :ze_event_handle_t,
                    ZEXIpcCounterBasedEventHandle.ptr ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zexCounterBasedEventGetIpcHandle in libze_loader.so"
  end

  begin
    attach_function :zexCounterBasedEventCloseIpcHandle,
                    [ :ze_event_handle_t ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zexCounterBasedEventCloseIpcHandle in libze_loader.so"
  end

  begin
    attach_function :zexIntelAllocateNetworkInterrupt,
                    [ :ze_context_handle_t,
                    :pointer ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zexIntelAllocateNetworkInterrupt in libze_loader.so"
  end

  begin
    attach_function :zexIntelReleaseNetworkInterrupt,
                    [ :ze_context_handle_t,
                    :uint32 ],
                    :ze_result_t
  rescue FFI::NotFoundError
    warn "Missing zexIntelReleaseNetworkInterrupt in libze_loader.so"
  end

  ZE.init

  at_exit {
    ZE::ZE_OBJECTS_MUTEX.synchronize {
      ZE::ZE_OBJECTS.to_a.reverse.each do |h, d|
        result = method(d).call(h)
        ZE.error_check(result)
      end
      ZE::ZE_OBJECTS.clear
    }
  }

end
