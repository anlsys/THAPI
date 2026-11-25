require_relative 'cuda_library.rb'
$event_lambdas["lttng_ust_cuda:cuGetErrorString_entry"] = lambda { |defi|
  s = "{ "
  s << "error: #{CUDA::CUResult.from_native(defi["error"], nil)}"
  s << ', '
  s << "pStr: #{"0x%016x" % defi["pStr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGetErrorString_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pStr_val: #{"0x%016x" % defi["pStr_val"]}"
  s << ', '
  s << "pStr_val_val: #{defi["pStr_val_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGetErrorName_entry"] = lambda { |defi|
  s = "{ "
  s << "error: #{CUDA::CUResult.from_native(defi["error"], nil)}"
  s << ', '
  s << "pStr: #{"0x%016x" % defi["pStr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGetErrorName_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pStr_val: #{"0x%016x" % defi["pStr_val"]}"
  s << ', '
  s << "pStr_val_val: #{defi["pStr_val_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuInit_entry"] = lambda { |defi|
  s = "{ "
  s << "Flags: #{defi["Flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuInit_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDriverGetVersion_entry"] = lambda { |defi|
  s = "{ "
  s << "driverVersion: #{"0x%016x" % defi["driverVersion"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDriverGetVersion_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "driverVersion_val: #{defi["driverVersion_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGet_entry"] = lambda { |defi|
  s = "{ "
  s << "device: #{"0x%016x" % defi["device"]}"
  s << ', '
  s << "ordinal: #{defi["ordinal"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGet_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "device_val: #{defi["device_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetCount_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{"0x%016x" % defi["count"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetCount_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "count_val: #{defi["count_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetName_entry"] = lambda { |defi|
  s = "{ "
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "len: #{defi["len"]}"
  s << ', '
  s << "dev: #{defi["dev"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetName_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "name_val: #{defi["name_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetUuid_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "uuid: #{"0x%016x" % defi["uuid"]}"
  s << ', '
  s << "dev: #{defi["dev"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetUuid_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "uuid_val: #{defi["uuid_val"].size > 0 ? CUDA::CUUUID.new(FFI::MemoryPointer.from_string(defi["uuid_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetLuid_entry"] = lambda { |defi|
  s = "{ "
  s << "luid: #{"0x%016x" % defi["luid"]}"
  s << ', '
  s << "deviceNodeMask: #{"0x%016x" % defi["deviceNodeMask"]}"
  s << ', '
  s << "dev: #{defi["dev"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetLuid_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "luid_vals: #{defi["luid_vals"].inspect}"
  s << ', '
  s << "deviceNodeMask_val: #{defi["deviceNodeMask_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceTotalMem_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "bytes: #{"0x%016x" % defi["bytes"]}"
  s << ', '
  s << "dev: #{defi["dev"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceTotalMem_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "bytes_val: #{defi["bytes_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetTexture1DLinearMaxWidth_entry"] = lambda { |defi|
  s = "{ "
  s << "maxWidthInElements: #{"0x%016x" % defi["maxWidthInElements"]}"
  s << ', '
  s << "format: #{CUDA::CUArrayFormat.from_native(defi["format"], nil)}"
  s << ', '
  s << "numChannels: #{defi["numChannels"]}"
  s << ', '
  s << "dev: #{defi["dev"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetTexture1DLinearMaxWidth_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "maxWidthInElements_val: #{defi["maxWidthInElements_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetAttribute_entry"] = lambda { |defi|
  s = "{ "
  s << "pi: #{"0x%016x" % defi["pi"]}"
  s << ', '
  s << "attrib: #{CUDA::CUDeviceAttribute.from_native(defi["attrib"], nil)}"
  s << ', '
  s << "dev: #{defi["dev"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetAttribute_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pi_val: #{defi["pi_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetHostAtomicCapabilities_entry"] = lambda { |defi|
  s = "{ "
  s << "capabilities: #{"0x%016x" % defi["capabilities"]}"
  s << ', '
  s << "operations: #{"0x%016x" % defi["operations"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "dev: #{defi["dev"]}"
  s << ', '
  s << "operations_vals: #{defi["operations_vals"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetHostAtomicCapabilities_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "capabilities_vals: #{defi["capabilities_vals"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetNvSciSyncAttributes_entry"] = lambda { |defi|
  s = "{ "
  s << "nvSciSyncAttrList: #{"0x%016x" % defi["nvSciSyncAttrList"]}"
  s << ', '
  s << "dev: #{defi["dev"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetNvSciSyncAttributes_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceSetMemPool_entry"] = lambda { |defi|
  s = "{ "
  s << "dev: #{defi["dev"]}"
  s << ', '
  s << "pool: #{"0x%016x" % defi["pool"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceSetMemPool_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetMemPool_entry"] = lambda { |defi|
  s = "{ "
  s << "pool: #{"0x%016x" % defi["pool"]}"
  s << ', '
  s << "dev: #{defi["dev"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetMemPool_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pool_val: #{"0x%016x" % defi["pool_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetDefaultMemPool_entry"] = lambda { |defi|
  s = "{ "
  s << "pool_out: #{"0x%016x" % defi["pool_out"]}"
  s << ', '
  s << "dev: #{defi["dev"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetDefaultMemPool_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pool_out_val: #{"0x%016x" % defi["pool_out_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetExecAffinitySupport_entry"] = lambda { |defi|
  s = "{ "
  s << "pi: #{"0x%016x" % defi["pi"]}"
  s << ', '
  s << "type: #{CUDA::CUExecAffinityType.from_native(defi["type"], nil)}"
  s << ', '
  s << "dev: #{defi["dev"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetExecAffinitySupport_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pi_val: #{defi["pi_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuFlushGPUDirectRDMAWrites_entry"] = lambda { |defi|
  s = "{ "
  s << "target: #{CUDA::CUFlushGPUDirectRDMAWritesTarget.from_native(defi["target"], nil)}"
  s << ', '
  s << "scope: #{CUDA::CUFlushGPUDirectRDMAWritesScope.from_native(defi["scope"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuFlushGPUDirectRDMAWrites_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "prop: #{"0x%016x" % defi["prop"]}"
  s << ', '
  s << "dev: #{defi["dev"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "prop_val: #{defi["prop_val"].size > 0 ? CUDA::CUDevpropV1.new(FFI::MemoryPointer.from_string(defi["prop_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceComputeCapability_entry"] = lambda { |defi|
  s = "{ "
  s << "major: #{"0x%016x" % defi["major"]}"
  s << ', '
  s << "minor: #{"0x%016x" % defi["minor"]}"
  s << ', '
  s << "dev: #{defi["dev"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceComputeCapability_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "major_val: #{defi["major_val"]}"
  s << ', '
  s << "minor_val: #{defi["minor_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDevicePrimaryCtxRetain_entry"] = lambda { |defi|
  s = "{ "
  s << "pctx: #{"0x%016x" % defi["pctx"]}"
  s << ', '
  s << "dev: #{defi["dev"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDevicePrimaryCtxRetain_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pctx_val: #{"0x%016x" % defi["pctx_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDevicePrimaryCtxRelease_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "dev: #{defi["dev"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDevicePrimaryCtxRelease_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDevicePrimaryCtxSetFlags_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "dev: #{defi["dev"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDevicePrimaryCtxSetFlags_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDevicePrimaryCtxGetState_entry"] = lambda { |defi|
  s = "{ "
  s << "dev: #{defi["dev"]}"
  s << ', '
  s << "flags: #{"0x%016x" % defi["flags"]}"
  s << ', '
  s << "active: #{"0x%016x" % defi["active"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDevicePrimaryCtxGetState_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "flags_val: #{defi["flags_val"]}"
  s << ', '
  s << "active_val: #{defi["active_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDevicePrimaryCtxReset_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "dev: #{defi["dev"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDevicePrimaryCtxReset_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxCreate_v4_entry"] = lambda { |defi|
  s = "{ "
  s << "pctx: #{"0x%016x" % defi["pctx"]}"
  s << ', '
  s << "ctxCreateParams: #{"0x%016x" % defi["ctxCreateParams"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "dev: #{defi["dev"]}"
  s << ', '
  s << "ctxCreateParams_val: #{defi["ctxCreateParams_val"].size > 0 ? CUDA::CUCtxCreateParams.new(FFI::MemoryPointer.from_string(defi["ctxCreateParams_val"])) : nil}"
  s << ', '
  s << "ctxCreateParams__execAffinityParams_vals: [ #{p = FFI::MemoryPointer.from_string(defi["ctxCreateParams__execAffinityParams_vals"]); sz = CUDA::CUExecAffinityParamV1.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUExecAffinityParamV1.new(p + i*sz).to_s}.join(", ")} ]"
  s << ', '
  s << "ctxCreateParams__cigParams_val: #{defi["ctxCreateParams__cigParams_val"].size > 0 ? CUDA::CUCtxCigParam.new(FFI::MemoryPointer.from_string(defi["ctxCreateParams__cigParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxCreate_v4_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pctx_val: #{"0x%016x" % defi["pctx_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxDestroy_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "ctx: #{"0x%016x" % defi["ctx"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxDestroy_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxPushCurrent_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "ctx: #{"0x%016x" % defi["ctx"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxPushCurrent_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxPopCurrent_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "pctx: #{"0x%016x" % defi["pctx"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxPopCurrent_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pctx_val: #{"0x%016x" % defi["pctx_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxSetCurrent_entry"] = lambda { |defi|
  s = "{ "
  s << "ctx: #{"0x%016x" % defi["ctx"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxSetCurrent_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxGetCurrent_entry"] = lambda { |defi|
  s = "{ "
  s << "pctx: #{"0x%016x" % defi["pctx"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxGetCurrent_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pctx_val: #{"0x%016x" % defi["pctx_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxGetDevice_entry"] = lambda { |defi|
  s = "{ "
  s << "device: #{"0x%016x" % defi["device"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxGetDevice_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "device_val: #{defi["device_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxGetDevice_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "device: #{"0x%016x" % defi["device"]}"
  s << ', '
  s << "ctx: #{"0x%016x" % defi["ctx"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxGetDevice_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "device_val: #{defi["device_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxGetFlags_entry"] = lambda { |defi|
  s = "{ "
  s << "flags: #{"0x%016x" % defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxGetFlags_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "flags_val: #{defi["flags_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxSetFlags_entry"] = lambda { |defi|
  s = "{ "
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxSetFlags_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxGetId_entry"] = lambda { |defi|
  s = "{ "
  s << "ctx: #{"0x%016x" % defi["ctx"]}"
  s << ', '
  s << "ctxId: #{"0x%016x" % defi["ctxId"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxGetId_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "ctxId_val: #{defi["ctxId_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxSynchronize_entry"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxSynchronize_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxSynchronize_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "ctx: #{"0x%016x" % defi["ctx"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxSynchronize_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxSetLimit_entry"] = lambda { |defi|
  s = "{ "
  s << "limit: #{CUDA::CULimit.from_native(defi["limit"], nil)}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxSetLimit_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxGetLimit_entry"] = lambda { |defi|
  s = "{ "
  s << "pvalue: #{"0x%016x" % defi["pvalue"]}"
  s << ', '
  s << "limit: #{CUDA::CULimit.from_native(defi["limit"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxGetLimit_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pvalue_val: #{defi["pvalue_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxGetCacheConfig_entry"] = lambda { |defi|
  s = "{ "
  s << "pconfig: #{"0x%016x" % defi["pconfig"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxGetCacheConfig_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pconfig_val: #{CUDA::CUFuncCache.from_native(defi["pconfig_val"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxSetCacheConfig_entry"] = lambda { |defi|
  s = "{ "
  s << "config: #{CUDA::CUFuncCache.from_native(defi["config"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxSetCacheConfig_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxGetApiVersion_entry"] = lambda { |defi|
  s = "{ "
  s << "ctx: #{"0x%016x" % defi["ctx"]}"
  s << ', '
  s << "version: #{"0x%016x" % defi["version"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxGetApiVersion_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "version_val: #{defi["version_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxGetStreamPriorityRange_entry"] = lambda { |defi|
  s = "{ "
  s << "leastPriority: #{"0x%016x" % defi["leastPriority"]}"
  s << ', '
  s << "greatestPriority: #{"0x%016x" % defi["greatestPriority"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxGetStreamPriorityRange_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "leastPriority_val: #{defi["leastPriority_val"]}"
  s << ', '
  s << "greatestPriority_val: #{defi["greatestPriority_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxResetPersistingL2Cache_entry"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxResetPersistingL2Cache_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxGetExecAffinity_entry"] = lambda { |defi|
  s = "{ "
  s << "pExecAffinity: #{"0x%016x" % defi["pExecAffinity"]}"
  s << ', '
  s << "type: #{CUDA::CUExecAffinityType.from_native(defi["type"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxGetExecAffinity_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pExecAffinity_val: #{defi["pExecAffinity_val"].size > 0 ? CUDA::CUExecAffinityParamV1.new(FFI::MemoryPointer.from_string(defi["pExecAffinity_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxRecordEvent_entry"] = lambda { |defi|
  s = "{ "
  s << "hCtx: #{"0x%016x" % defi["hCtx"]}"
  s << ', '
  s << "hEvent: #{"0x%016x" % defi["hEvent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxRecordEvent_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxWaitEvent_entry"] = lambda { |defi|
  s = "{ "
  s << "hCtx: #{"0x%016x" % defi["hCtx"]}"
  s << ', '
  s << "hEvent: #{"0x%016x" % defi["hEvent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxWaitEvent_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxAttach_entry"] = lambda { |defi|
  s = "{ "
  s << "pctx: #{"0x%016x" % defi["pctx"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxAttach_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pctx_val: #{"0x%016x" % defi["pctx_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxDetach_entry"] = lambda { |defi|
  s = "{ "
  s << "ctx: #{"0x%016x" % defi["ctx"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxDetach_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxGetSharedMemConfig_entry"] = lambda { |defi|
  s = "{ "
  s << "pConfig: #{"0x%016x" % defi["pConfig"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxGetSharedMemConfig_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pConfig_val: #{CUDA::CUSharedconfig.from_native(defi["pConfig_val"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxSetSharedMemConfig_entry"] = lambda { |defi|
  s = "{ "
  s << "config: #{CUDA::CUSharedconfig.from_native(defi["config"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxSetSharedMemConfig_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuModuleLoad_entry"] = lambda { |defi|
  s = "{ "
  s << "module: #{"0x%016x" % defi["module"]}"
  s << ', '
  s << "fname: #{"0x%016x" % defi["fname"]}"
  s << ', '
  s << "fname_val: #{defi["fname_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuModuleLoad_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "module_val: #{"0x%016x" % defi["module_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuModuleLoadData_entry"] = lambda { |defi|
  s = "{ "
  s << "module: #{"0x%016x" % defi["module"]}"
  s << ', '
  s << "image: #{"0x%016x" % defi["image"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuModuleLoadData_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "module_val: #{"0x%016x" % defi["module_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuModuleLoadDataEx_entry"] = lambda { |defi|
  s = "{ "
  s << "module: #{"0x%016x" % defi["module"]}"
  s << ', '
  s << "image: #{"0x%016x" % defi["image"]}"
  s << ', '
  s << "numOptions: #{defi["numOptions"]}"
  s << ', '
  s << "options: #{"0x%016x" % defi["options"]}"
  s << ', '
  s << "optionValues: #{"0x%016x" % defi["optionValues"]}"
  s << ', '
  s << "options_vals: #{defi["options_vals"]}"
  s << ', '
  s << "optionValues_vals: [ #{defi["optionValues_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuModuleLoadDataEx_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "module_val: #{"0x%016x" % defi["module_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuModuleLoadFatBinary_entry"] = lambda { |defi|
  s = "{ "
  s << "module: #{"0x%016x" % defi["module"]}"
  s << ', '
  s << "fatCubin: #{"0x%016x" % defi["fatCubin"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuModuleLoadFatBinary_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "module_val: #{"0x%016x" % defi["module_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuModuleUnload_entry"] = lambda { |defi|
  s = "{ "
  s << "hmod: #{"0x%016x" % defi["hmod"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuModuleUnload_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuModuleGetLoadingMode_entry"] = lambda { |defi|
  s = "{ "
  s << "mode: #{"0x%016x" % defi["mode"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuModuleGetLoadingMode_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "mode_val: #{CUDA::CUModuleLoadingMode.from_native(defi["mode_val"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuModuleGetFunction_entry"] = lambda { |defi|
  s = "{ "
  s << "hfunc: #{"0x%016x" % defi["hfunc"]}"
  s << ', '
  s << "hmod: #{"0x%016x" % defi["hmod"]}"
  s << ', '
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "name_val: #{defi["name_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuModuleGetFunction_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "hfunc_val: #{"0x%016x" % defi["hfunc_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuModuleGetFunctionCount_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{"0x%016x" % defi["count"]}"
  s << ', '
  s << "mod: #{"0x%016x" % defi["mod"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuModuleGetFunctionCount_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "count_val: #{defi["count_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuModuleEnumerateFunctions_entry"] = lambda { |defi|
  s = "{ "
  s << "functions: #{"0x%016x" % defi["functions"]}"
  s << ', '
  s << "numFunctions: #{defi["numFunctions"]}"
  s << ', '
  s << "mod: #{"0x%016x" % defi["mod"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuModuleEnumerateFunctions_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "functions_vals: [ #{defi["functions_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuModuleGetGlobal_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "dptr: #{"0x%016x" % defi["dptr"]}"
  s << ', '
  s << "bytes: #{"0x%016x" % defi["bytes"]}"
  s << ', '
  s << "hmod: #{"0x%016x" % defi["hmod"]}"
  s << ', '
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "name_val: #{defi["name_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuModuleGetGlobal_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "dptr_val: #{"0x%016x" % defi["dptr_val"]}"
  s << ', '
  s << "bytes_val: #{defi["bytes_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLinkCreate_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "numOptions: #{defi["numOptions"]}"
  s << ', '
  s << "options: #{"0x%016x" % defi["options"]}"
  s << ', '
  s << "optionValues: #{"0x%016x" % defi["optionValues"]}"
  s << ', '
  s << "stateOut: #{"0x%016x" % defi["stateOut"]}"
  s << ', '
  s << "options_vals: #{defi["options_vals"]}"
  s << ', '
  s << "optionValues_vals: [ #{defi["optionValues_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLinkCreate_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "stateOut_val: #{"0x%016x" % defi["stateOut_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLinkAddData_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "state: #{"0x%016x" % defi["state"]}"
  s << ', '
  s << "type: #{CUDA::CUJitInputType.from_native(defi["type"], nil)}"
  s << ', '
  s << "data: #{"0x%016x" % defi["data"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "numOptions: #{defi["numOptions"]}"
  s << ', '
  s << "options: #{"0x%016x" % defi["options"]}"
  s << ', '
  s << "optionValues: #{"0x%016x" % defi["optionValues"]}"
  s << ', '
  s << "name_val: #{defi["name_val"].inspect}"
  s << ', '
  s << "options_vals: #{defi["options_vals"]}"
  s << ', '
  s << "optionValues_vals: [ #{defi["optionValues_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLinkAddData_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLinkAddFile_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "state: #{"0x%016x" % defi["state"]}"
  s << ', '
  s << "type: #{CUDA::CUJitInputType.from_native(defi["type"], nil)}"
  s << ', '
  s << "path: #{"0x%016x" % defi["path"]}"
  s << ', '
  s << "numOptions: #{defi["numOptions"]}"
  s << ', '
  s << "options: #{"0x%016x" % defi["options"]}"
  s << ', '
  s << "optionValues: #{"0x%016x" % defi["optionValues"]}"
  s << ', '
  s << "path_val: #{defi["path_val"].inspect}"
  s << ', '
  s << "options_vals: #{defi["options_vals"]}"
  s << ', '
  s << "optionValues_vals: [ #{defi["optionValues_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLinkAddFile_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLinkComplete_entry"] = lambda { |defi|
  s = "{ "
  s << "state: #{"0x%016x" % defi["state"]}"
  s << ', '
  s << "cubinOut: #{"0x%016x" % defi["cubinOut"]}"
  s << ', '
  s << "sizeOut: #{"0x%016x" % defi["sizeOut"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLinkComplete_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "cubinOut_val: #{"0x%016x" % defi["cubinOut_val"]}"
  s << ', '
  s << "sizeOut_val: #{defi["sizeOut_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLinkDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "state: #{"0x%016x" % defi["state"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLinkDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuModuleGetTexRef_entry"] = lambda { |defi|
  s = "{ "
  s << "pTexRef: #{"0x%016x" % defi["pTexRef"]}"
  s << ', '
  s << "hmod: #{"0x%016x" % defi["hmod"]}"
  s << ', '
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "name_val: #{defi["name_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuModuleGetTexRef_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pTexRef_val: #{"0x%016x" % defi["pTexRef_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuModuleGetSurfRef_entry"] = lambda { |defi|
  s = "{ "
  s << "pSurfRef: #{"0x%016x" % defi["pSurfRef"]}"
  s << ', '
  s << "hmod: #{"0x%016x" % defi["hmod"]}"
  s << ', '
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "name_val: #{defi["name_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuModuleGetSurfRef_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pSurfRef_val: #{"0x%016x" % defi["pSurfRef_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLibraryLoadData_entry"] = lambda { |defi|
  s = "{ "
  s << "library: #{"0x%016x" % defi["library"]}"
  s << ', '
  s << "code: #{"0x%016x" % defi["code"]}"
  s << ', '
  s << "jitOptions: #{"0x%016x" % defi["jitOptions"]}"
  s << ', '
  s << "jitOptionsValues: #{"0x%016x" % defi["jitOptionsValues"]}"
  s << ', '
  s << "numJitOptions: #{defi["numJitOptions"]}"
  s << ', '
  s << "libraryOptions: #{"0x%016x" % defi["libraryOptions"]}"
  s << ', '
  s << "libraryOptionValues: #{"0x%016x" % defi["libraryOptionValues"]}"
  s << ', '
  s << "numLibraryOptions: #{defi["numLibraryOptions"]}"
  s << ', '
  s << "jitOptions_vals: #{defi["jitOptions_vals"]}"
  s << ', '
  s << "jitOptionsValues_vals: [ #{defi["jitOptionsValues_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "libraryOptions_vals: #{defi["libraryOptions_vals"]}"
  s << ', '
  s << "libraryOptionValues_vals: [ #{defi["libraryOptionValues_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLibraryLoadData_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "library_val: #{"0x%016x" % defi["library_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLibraryLoadFromFile_entry"] = lambda { |defi|
  s = "{ "
  s << "library: #{"0x%016x" % defi["library"]}"
  s << ', '
  s << "fileName: #{"0x%016x" % defi["fileName"]}"
  s << ', '
  s << "jitOptions: #{"0x%016x" % defi["jitOptions"]}"
  s << ', '
  s << "jitOptionsValues: #{"0x%016x" % defi["jitOptionsValues"]}"
  s << ', '
  s << "numJitOptions: #{defi["numJitOptions"]}"
  s << ', '
  s << "libraryOptions: #{"0x%016x" % defi["libraryOptions"]}"
  s << ', '
  s << "libraryOptionValues: #{"0x%016x" % defi["libraryOptionValues"]}"
  s << ', '
  s << "numLibraryOptions: #{defi["numLibraryOptions"]}"
  s << ', '
  s << "fileName_val: #{defi["fileName_val"].inspect}"
  s << ', '
  s << "jitOptions_vals: #{defi["jitOptions_vals"]}"
  s << ', '
  s << "jitOptionsValues_vals: [ #{defi["jitOptionsValues_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "libraryOptions_vals: #{defi["libraryOptions_vals"]}"
  s << ', '
  s << "libraryOptionValues_vals: [ #{defi["libraryOptionValues_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLibraryLoadFromFile_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "library_val: #{"0x%016x" % defi["library_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLibraryUnload_entry"] = lambda { |defi|
  s = "{ "
  s << "library: #{"0x%016x" % defi["library"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLibraryUnload_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLibraryGetKernel_entry"] = lambda { |defi|
  s = "{ "
  s << "pKernel: #{"0x%016x" % defi["pKernel"]}"
  s << ', '
  s << "library: #{"0x%016x" % defi["library"]}"
  s << ', '
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "name_val: #{defi["name_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLibraryGetKernel_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pKernel_val: #{"0x%016x" % defi["pKernel_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLibraryGetKernelCount_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{"0x%016x" % defi["count"]}"
  s << ', '
  s << "lib: #{"0x%016x" % defi["lib"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLibraryGetKernelCount_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "count_val: #{defi["count_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLibraryEnumerateKernels_entry"] = lambda { |defi|
  s = "{ "
  s << "kernels: #{"0x%016x" % defi["kernels"]}"
  s << ', '
  s << "numKernels: #{defi["numKernels"]}"
  s << ', '
  s << "lib: #{"0x%016x" % defi["lib"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLibraryEnumerateKernels_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "kernels_vals: [ #{defi["kernels_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLibraryGetModule_entry"] = lambda { |defi|
  s = "{ "
  s << "pMod: #{"0x%016x" % defi["pMod"]}"
  s << ', '
  s << "library: #{"0x%016x" % defi["library"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLibraryGetModule_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pMod_val: #{"0x%016x" % defi["pMod_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuKernelGetFunction_entry"] = lambda { |defi|
  s = "{ "
  s << "pFunc: #{"0x%016x" % defi["pFunc"]}"
  s << ', '
  s << "kernel: #{"0x%016x" % defi["kernel"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuKernelGetFunction_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pFunc_val: #{"0x%016x" % defi["pFunc_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuKernelGetLibrary_entry"] = lambda { |defi|
  s = "{ "
  s << "pLib: #{"0x%016x" % defi["pLib"]}"
  s << ', '
  s << "kernel: #{"0x%016x" % defi["kernel"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuKernelGetLibrary_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pLib_val: #{"0x%016x" % defi["pLib_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLibraryGetGlobal_entry"] = lambda { |defi|
  s = "{ "
  s << "dptr: #{"0x%016x" % defi["dptr"]}"
  s << ', '
  s << "bytes: #{"0x%016x" % defi["bytes"]}"
  s << ', '
  s << "library: #{"0x%016x" % defi["library"]}"
  s << ', '
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "name_val: #{defi["name_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLibraryGetGlobal_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "dptr_val: #{"0x%016x" % defi["dptr_val"]}"
  s << ', '
  s << "bytes_val: #{defi["bytes_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLibraryGetManaged_entry"] = lambda { |defi|
  s = "{ "
  s << "dptr: #{"0x%016x" % defi["dptr"]}"
  s << ', '
  s << "bytes: #{"0x%016x" % defi["bytes"]}"
  s << ', '
  s << "library: #{"0x%016x" % defi["library"]}"
  s << ', '
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "name_val: #{defi["name_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLibraryGetManaged_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "dptr_val: #{"0x%016x" % defi["dptr_val"]}"
  s << ', '
  s << "bytes_val: #{defi["bytes_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLibraryGetUnifiedFunction_entry"] = lambda { |defi|
  s = "{ "
  s << "fptr: #{"0x%016x" % defi["fptr"]}"
  s << ', '
  s << "library: #{"0x%016x" % defi["library"]}"
  s << ', '
  s << "symbol: #{"0x%016x" % defi["symbol"]}"
  s << ', '
  s << "symbol_val: #{defi["symbol_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLibraryGetUnifiedFunction_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "fptr_val: #{"0x%016x" % defi["fptr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuKernelGetAttribute_entry"] = lambda { |defi|
  s = "{ "
  s << "pi: #{"0x%016x" % defi["pi"]}"
  s << ', '
  s << "attrib: #{CUDA::CUFunctionAttribute.from_native(defi["attrib"], nil)}"
  s << ', '
  s << "kernel: #{"0x%016x" % defi["kernel"]}"
  s << ', '
  s << "dev: #{defi["dev"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuKernelGetAttribute_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pi_val: #{defi["pi_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuKernelSetAttribute_entry"] = lambda { |defi|
  s = "{ "
  s << "attrib: #{CUDA::CUFunctionAttribute.from_native(defi["attrib"], nil)}"
  s << ', '
  s << "val: #{defi["val"]}"
  s << ', '
  s << "kernel: #{"0x%016x" % defi["kernel"]}"
  s << ', '
  s << "dev: #{defi["dev"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuKernelSetAttribute_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuKernelSetCacheConfig_entry"] = lambda { |defi|
  s = "{ "
  s << "kernel: #{"0x%016x" % defi["kernel"]}"
  s << ', '
  s << "config: #{CUDA::CUFuncCache.from_native(defi["config"], nil)}"
  s << ', '
  s << "dev: #{defi["dev"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuKernelSetCacheConfig_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuKernelGetName_entry"] = lambda { |defi|
  s = "{ "
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "hfunc: #{"0x%016x" % defi["hfunc"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuKernelGetName_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "name_val_val: #{defi["name_val_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuKernelGetParamInfo_entry"] = lambda { |defi|
  s = "{ "
  s << "kernel: #{"0x%016x" % defi["kernel"]}"
  s << ', '
  s << "paramIndex: #{defi["paramIndex"]}"
  s << ', '
  s << "paramOffset: #{"0x%016x" % defi["paramOffset"]}"
  s << ', '
  s << "paramSize: #{"0x%016x" % defi["paramSize"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuKernelGetParamInfo_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "paramOffset_val: #{defi["paramOffset_val"]}"
  s << ', '
  s << "paramSize_val: #{defi["paramSize_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemGetInfo_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "free: #{"0x%016x" % defi["free"]}"
  s << ', '
  s << "total: #{"0x%016x" % defi["total"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemGetInfo_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "free_val: #{defi["free_val"]}"
  s << ', '
  s << "total_val: #{defi["total_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemAlloc_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "dptr: #{"0x%016x" % defi["dptr"]}"
  s << ', '
  s << "bytesize: #{defi["bytesize"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemAlloc_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "dptr_val: #{"0x%016x" % defi["dptr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemAllocPitch_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "dptr: #{"0x%016x" % defi["dptr"]}"
  s << ', '
  s << "pPitch: #{"0x%016x" % defi["pPitch"]}"
  s << ', '
  s << "WidthInBytes: #{defi["WidthInBytes"]}"
  s << ', '
  s << "Height: #{defi["Height"]}"
  s << ', '
  s << "ElementSizeBytes: #{defi["ElementSizeBytes"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemAllocPitch_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "dptr_val: #{"0x%016x" % defi["dptr_val"]}"
  s << ', '
  s << "pPitch_val: #{defi["pPitch_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemFree_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "dptr: #{"0x%016x" % defi["dptr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemFree_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemGetAddressRange_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "pbase: #{"0x%016x" % defi["pbase"]}"
  s << ', '
  s << "psize: #{"0x%016x" % defi["psize"]}"
  s << ', '
  s << "dptr: #{"0x%016x" % defi["dptr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemGetAddressRange_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pbase_val: #{"0x%016x" % defi["pbase_val"]}"
  s << ', '
  s << "psize_val: #{defi["psize_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemAllocHost_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "pp: #{"0x%016x" % defi["pp"]}"
  s << ', '
  s << "bytesize: #{defi["bytesize"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemAllocHost_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pp_val: #{"0x%016x" % defi["pp_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemFreeHost_entry"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemFreeHost_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemHostAlloc_entry"] = lambda { |defi|
  s = "{ "
  s << "pp: #{"0x%016x" % defi["pp"]}"
  s << ', '
  s << "bytesize: #{defi["bytesize"]}"
  s << ', '
  s << "Flags: #{defi["Flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemHostAlloc_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pp_val: #{"0x%016x" % defi["pp_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemHostGetDevicePointer_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "pdptr: #{"0x%016x" % defi["pdptr"]}"
  s << ', '
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "Flags: #{defi["Flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemHostGetDevicePointer_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pdptr_val: #{"0x%016x" % defi["pdptr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemHostGetFlags_entry"] = lambda { |defi|
  s = "{ "
  s << "pFlags: #{"0x%016x" % defi["pFlags"]}"
  s << ', '
  s << "p: #{"0x%016x" % defi["p"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemHostGetFlags_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pFlags_val: #{defi["pFlags_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemAllocManaged_entry"] = lambda { |defi|
  s = "{ "
  s << "dptr: #{"0x%016x" % defi["dptr"]}"
  s << ', '
  s << "bytesize: #{defi["bytesize"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemAllocManaged_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "dptr_val: #{"0x%016x" % defi["dptr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceRegisterAsyncNotification_entry"] = lambda { |defi|
  s = "{ "
  s << "device: #{defi["device"]}"
  s << ', '
  s << "callbackFunc: #{"0x%016x" % defi["callbackFunc"]}"
  s << ', '
  s << "userData: #{"0x%016x" % defi["userData"]}"
  s << ', '
  s << "callback: #{"0x%016x" % defi["callback"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceRegisterAsyncNotification_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "callback_val: #{"0x%016x" % defi["callback_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceUnregisterAsyncNotification_entry"] = lambda { |defi|
  s = "{ "
  s << "device: #{defi["device"]}"
  s << ', '
  s << "callback: #{"0x%016x" % defi["callback"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceUnregisterAsyncNotification_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetByPCIBusId_entry"] = lambda { |defi|
  s = "{ "
  s << "dev: #{"0x%016x" % defi["dev"]}"
  s << ', '
  s << "pciBusId: #{"0x%016x" % defi["pciBusId"]}"
  s << ', '
  s << "pciBusId_val: #{defi["pciBusId_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetByPCIBusId_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "dev_val: #{defi["dev_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetPCIBusId_entry"] = lambda { |defi|
  s = "{ "
  s << "pciBusId: #{"0x%016x" % defi["pciBusId"]}"
  s << ', '
  s << "len: #{defi["len"]}"
  s << ', '
  s << "dev: #{defi["dev"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetPCIBusId_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pciBusId_val: #{defi["pciBusId_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuIpcGetEventHandle_entry"] = lambda { |defi|
  s = "{ "
  s << "pHandle: #{"0x%016x" % defi["pHandle"]}"
  s << ', '
  s << "event: #{"0x%016x" % defi["event"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuIpcGetEventHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pHandle_val: #{defi["pHandle_val"].size > 0 ? CUDA::CUIPCEventHandleV1.new(FFI::MemoryPointer.from_string(defi["pHandle_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuIpcOpenEventHandle_entry"] = lambda { |defi|
  s = "{ "
  s << "phEvent: #{"0x%016x" % defi["phEvent"]}"
  s << ', '
  s << "handle: #{defi["handle"].size > 0 ? CUDA::CUIPCEventHandleV1.new(FFI::MemoryPointer.from_string(defi["handle"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuIpcOpenEventHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phEvent_val: #{"0x%016x" % defi["phEvent_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuIpcGetMemHandle_entry"] = lambda { |defi|
  s = "{ "
  s << "pHandle: #{"0x%016x" % defi["pHandle"]}"
  s << ', '
  s << "dptr: #{"0x%016x" % defi["dptr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuIpcGetMemHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pHandle_val: #{defi["pHandle_val"].size > 0 ? CUDA::CUIPCMemHandleV1.new(FFI::MemoryPointer.from_string(defi["pHandle_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuIpcOpenMemHandle_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "pdptr: #{"0x%016x" % defi["pdptr"]}"
  s << ', '
  s << "handle: #{defi["handle"].size > 0 ? CUDA::CUIPCMemHandleV1.new(FFI::MemoryPointer.from_string(defi["handle"])) : nil}"
  s << ', '
  s << "Flags: #{defi["Flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuIpcOpenMemHandle_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pdptr_val: #{"0x%016x" % defi["pdptr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuIpcCloseMemHandle_entry"] = lambda { |defi|
  s = "{ "
  s << "dptr: #{"0x%016x" % defi["dptr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuIpcCloseMemHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemHostRegister_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "bytesize: #{defi["bytesize"]}"
  s << ', '
  s << "Flags: #{defi["Flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemHostRegister_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemHostUnregister_entry"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemHostUnregister_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy_ptds_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy_ptds_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyPeer_ptds_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "dstContext: #{"0x%016x" % defi["dstContext"]}"
  s << ', '
  s << "srcDevice: #{"0x%016x" % defi["srcDevice"]}"
  s << ', '
  s << "srcContext: #{"0x%016x" % defi["srcContext"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyPeer_ptds_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyHtoD_v2_ptds_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "srcHost: #{"0x%016x" % defi["srcHost"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyHtoD_v2_ptds_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyDtoH_v2_ptds_entry"] = lambda { |defi|
  s = "{ "
  s << "dstHost: #{"0x%016x" % defi["dstHost"]}"
  s << ', '
  s << "srcDevice: #{"0x%016x" % defi["srcDevice"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyDtoH_v2_ptds_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyDtoD_v2_ptds_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "srcDevice: #{"0x%016x" % defi["srcDevice"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyDtoD_v2_ptds_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyDtoA_v2_ptds_entry"] = lambda { |defi|
  s = "{ "
  s << "dstArray: #{"0x%016x" % defi["dstArray"]}"
  s << ', '
  s << "dstOffset: #{defi["dstOffset"]}"
  s << ', '
  s << "srcDevice: #{"0x%016x" % defi["srcDevice"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyDtoA_v2_ptds_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyAtoD_v2_ptds_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "srcArray: #{"0x%016x" % defi["srcArray"]}"
  s << ', '
  s << "srcOffset: #{defi["srcOffset"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyAtoD_v2_ptds_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyHtoA_v2_ptds_entry"] = lambda { |defi|
  s = "{ "
  s << "dstArray: #{"0x%016x" % defi["dstArray"]}"
  s << ', '
  s << "dstOffset: #{defi["dstOffset"]}"
  s << ', '
  s << "srcHost: #{"0x%016x" % defi["srcHost"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyHtoA_v2_ptds_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyAtoH_v2_ptds_entry"] = lambda { |defi|
  s = "{ "
  s << "dstHost: #{"0x%016x" % defi["dstHost"]}"
  s << ', '
  s << "srcArray: #{"0x%016x" % defi["srcArray"]}"
  s << ', '
  s << "srcOffset: #{defi["srcOffset"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyAtoH_v2_ptds_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyAtoA_v2_ptds_entry"] = lambda { |defi|
  s = "{ "
  s << "dstArray: #{"0x%016x" % defi["dstArray"]}"
  s << ', '
  s << "dstOffset: #{defi["dstOffset"]}"
  s << ', '
  s << "srcArray: #{"0x%016x" % defi["srcArray"]}"
  s << ', '
  s << "srcOffset: #{defi["srcOffset"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyAtoA_v2_ptds_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy2D_v2_ptds_entry"] = lambda { |defi|
  s = "{ "
  s << "pCopy: #{"0x%016x" % defi["pCopy"]}"
  s << ', '
  s << "pCopy_val: #{defi["pCopy_val"].size > 0 ? CUDA::CUDAMEMCPY2DV2.new(FFI::MemoryPointer.from_string(defi["pCopy_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy2D_v2_ptds_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy2DUnaligned_v2_ptds_entry"] = lambda { |defi|
  s = "{ "
  s << "pCopy: #{"0x%016x" % defi["pCopy"]}"
  s << ', '
  s << "pCopy_val: #{defi["pCopy_val"].size > 0 ? CUDA::CUDAMEMCPY2DV2.new(FFI::MemoryPointer.from_string(defi["pCopy_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy2DUnaligned_v2_ptds_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy3D_v2_ptds_entry"] = lambda { |defi|
  s = "{ "
  s << "pCopy: #{"0x%016x" % defi["pCopy"]}"
  s << ', '
  s << "pCopy_val: #{defi["pCopy_val"].size > 0 ? CUDA::CUDAMEMCPY3DV2.new(FFI::MemoryPointer.from_string(defi["pCopy_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy3D_v2_ptds_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy3DPeer_ptds_entry"] = lambda { |defi|
  s = "{ "
  s << "pCopy: #{"0x%016x" % defi["pCopy"]}"
  s << ', '
  s << "pCopy_val: #{defi["pCopy_val"].size > 0 ? CUDA::CUDAMEMCPY3DPEERV1.new(FFI::MemoryPointer.from_string(defi["pCopy_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy3DPeer_ptds_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyAsync_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyAsync_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyPeerAsync_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "dstContext: #{"0x%016x" % defi["dstContext"]}"
  s << ', '
  s << "srcDevice: #{"0x%016x" % defi["srcDevice"]}"
  s << ', '
  s << "srcContext: #{"0x%016x" % defi["srcContext"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyPeerAsync_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyHtoDAsync_v2_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "srcHost: #{"0x%016x" % defi["srcHost"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyHtoDAsync_v2_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyDtoHAsync_v2_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "dstHost: #{"0x%016x" % defi["dstHost"]}"
  s << ', '
  s << "srcDevice: #{"0x%016x" % defi["srcDevice"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyDtoHAsync_v2_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyDtoDAsync_v2_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "srcDevice: #{"0x%016x" % defi["srcDevice"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyDtoDAsync_v2_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyHtoAAsync_v2_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "dstArray: #{"0x%016x" % defi["dstArray"]}"
  s << ', '
  s << "dstOffset: #{defi["dstOffset"]}"
  s << ', '
  s << "srcHost: #{"0x%016x" % defi["srcHost"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyHtoAAsync_v2_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyAtoHAsync_v2_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "dstHost: #{"0x%016x" % defi["dstHost"]}"
  s << ', '
  s << "srcArray: #{"0x%016x" % defi["srcArray"]}"
  s << ', '
  s << "srcOffset: #{defi["srcOffset"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyAtoHAsync_v2_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy2DAsync_v2_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "pCopy: #{"0x%016x" % defi["pCopy"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "pCopy_val: #{defi["pCopy_val"].size > 0 ? CUDA::CUDAMEMCPY2DV2.new(FFI::MemoryPointer.from_string(defi["pCopy_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy2DAsync_v2_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy3DAsync_v2_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "pCopy: #{"0x%016x" % defi["pCopy"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "pCopy_val: #{defi["pCopy_val"].size > 0 ? CUDA::CUDAMEMCPY3DV2.new(FFI::MemoryPointer.from_string(defi["pCopy_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy3DAsync_v2_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy3DPeerAsync_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "pCopy: #{"0x%016x" % defi["pCopy"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "pCopy_val: #{defi["pCopy_val"].size > 0 ? CUDA::CUDAMEMCPY3DPEERV1.new(FFI::MemoryPointer.from_string(defi["pCopy_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy3DPeerAsync_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyBatchAsync_v2_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "dsts: #{"0x%016x" % defi["dsts"]}"
  s << ', '
  s << "srcs: #{"0x%016x" % defi["srcs"]}"
  s << ', '
  s << "sizes: #{"0x%016x" % defi["sizes"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "attrs: #{"0x%016x" % defi["attrs"]}"
  s << ', '
  s << "attrsIdxs: #{"0x%016x" % defi["attrsIdxs"]}"
  s << ', '
  s << "numAttrs: #{defi["numAttrs"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "dsts_vals: [ #{defi["dsts_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "srcs_vals: [ #{defi["srcs_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "sizes_vals: #{defi["sizes_vals"]}"
  s << ', '
  s << "attrs_vals: [ #{p = FFI::MemoryPointer.from_string(defi["attrs_vals"]); sz = CUDA::CUMemcpyAttributesV1.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUMemcpyAttributesV1.new(p + i*sz).to_s}.join(", ")} ]"
  s << ', '
  s << "attrsIdxs_vals: #{defi["attrsIdxs_vals"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyBatchAsync_v2_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy3DBatchAsync_v2_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "numOps: #{defi["numOps"]}"
  s << ', '
  s << "opList: #{"0x%016x" % defi["opList"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "opList_vals: [ #{p = FFI::MemoryPointer.from_string(defi["opList_vals"]); sz = CUDA::CUDAMEMCPY3DBATCHOPV1.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUDAMEMCPY3DBATCHOPV1.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy3DBatchAsync_v2_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD8_v2_ptds_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "uc: #{defi["uc"]}"
  s << ', '
  s << "N: #{defi["N"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD8_v2_ptds_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD16_v2_ptds_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "us: #{defi["us"]}"
  s << ', '
  s << "N: #{defi["N"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD16_v2_ptds_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD32_v2_ptds_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "ui: #{defi["ui"]}"
  s << ', '
  s << "N: #{defi["N"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD32_v2_ptds_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD2D8_v2_ptds_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "dstPitch: #{defi["dstPitch"]}"
  s << ', '
  s << "uc: #{defi["uc"]}"
  s << ', '
  s << "Width: #{defi["Width"]}"
  s << ', '
  s << "Height: #{defi["Height"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD2D8_v2_ptds_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD2D16_v2_ptds_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "dstPitch: #{defi["dstPitch"]}"
  s << ', '
  s << "us: #{defi["us"]}"
  s << ', '
  s << "Width: #{defi["Width"]}"
  s << ', '
  s << "Height: #{defi["Height"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD2D16_v2_ptds_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD2D32_v2_ptds_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "dstPitch: #{defi["dstPitch"]}"
  s << ', '
  s << "ui: #{defi["ui"]}"
  s << ', '
  s << "Width: #{defi["Width"]}"
  s << ', '
  s << "Height: #{defi["Height"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD2D32_v2_ptds_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD8Async_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "uc: #{defi["uc"]}"
  s << ', '
  s << "N: #{defi["N"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD8Async_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD16Async_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "us: #{defi["us"]}"
  s << ', '
  s << "N: #{defi["N"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD16Async_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD32Async_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "ui: #{defi["ui"]}"
  s << ', '
  s << "N: #{defi["N"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD32Async_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD2D8Async_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "dstPitch: #{defi["dstPitch"]}"
  s << ', '
  s << "uc: #{defi["uc"]}"
  s << ', '
  s << "Width: #{defi["Width"]}"
  s << ', '
  s << "Height: #{defi["Height"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD2D8Async_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD2D16Async_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "dstPitch: #{defi["dstPitch"]}"
  s << ', '
  s << "us: #{defi["us"]}"
  s << ', '
  s << "Width: #{defi["Width"]}"
  s << ', '
  s << "Height: #{defi["Height"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD2D16Async_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD2D32Async_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "dstPitch: #{defi["dstPitch"]}"
  s << ', '
  s << "ui: #{defi["ui"]}"
  s << ', '
  s << "Width: #{defi["Width"]}"
  s << ', '
  s << "Height: #{defi["Height"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD2D32Async_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuArrayCreate_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "pHandle: #{"0x%016x" % defi["pHandle"]}"
  s << ', '
  s << "pAllocateArray: #{"0x%016x" % defi["pAllocateArray"]}"
  s << ', '
  s << "pAllocateArray_val: #{defi["pAllocateArray_val"].size > 0 ? CUDA::CUDAARRAYDESCRIPTORV2.new(FFI::MemoryPointer.from_string(defi["pAllocateArray_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuArrayCreate_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pHandle_val: #{"0x%016x" % defi["pHandle_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuArrayGetDescriptor_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "pArrayDescriptor: #{"0x%016x" % defi["pArrayDescriptor"]}"
  s << ', '
  s << "hArray: #{"0x%016x" % defi["hArray"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuArrayGetDescriptor_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pArrayDescriptor_val: #{defi["pArrayDescriptor_val"].size > 0 ? CUDA::CUDAARRAYDESCRIPTORV2.new(FFI::MemoryPointer.from_string(defi["pArrayDescriptor_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuArrayGetSparseProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "sparseProperties: #{"0x%016x" % defi["sparseProperties"]}"
  s << ', '
  s << "array: #{"0x%016x" % defi["array"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuArrayGetSparseProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "sparseProperties_val: #{defi["sparseProperties_val"].size > 0 ? CUDA::CUDAARRAYSPARSEPROPERTIESV1.new(FFI::MemoryPointer.from_string(defi["sparseProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMipmappedArrayGetSparseProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "sparseProperties: #{"0x%016x" % defi["sparseProperties"]}"
  s << ', '
  s << "mipmap: #{"0x%016x" % defi["mipmap"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMipmappedArrayGetSparseProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "sparseProperties_val: #{defi["sparseProperties_val"].size > 0 ? CUDA::CUDAARRAYSPARSEPROPERTIESV1.new(FFI::MemoryPointer.from_string(defi["sparseProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuArrayGetMemoryRequirements_entry"] = lambda { |defi|
  s = "{ "
  s << "memoryRequirements: #{"0x%016x" % defi["memoryRequirements"]}"
  s << ', '
  s << "array: #{"0x%016x" % defi["array"]}"
  s << ', '
  s << "device: #{defi["device"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuArrayGetMemoryRequirements_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "memoryRequirements_val: #{defi["memoryRequirements_val"].size > 0 ? CUDA::CUDAARRAYMEMORYREQUIREMENTSV1.new(FFI::MemoryPointer.from_string(defi["memoryRequirements_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMipmappedArrayGetMemoryRequirements_entry"] = lambda { |defi|
  s = "{ "
  s << "memoryRequirements: #{"0x%016x" % defi["memoryRequirements"]}"
  s << ', '
  s << "mipmap: #{"0x%016x" % defi["mipmap"]}"
  s << ', '
  s << "device: #{defi["device"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMipmappedArrayGetMemoryRequirements_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "memoryRequirements_val: #{defi["memoryRequirements_val"].size > 0 ? CUDA::CUDAARRAYMEMORYREQUIREMENTSV1.new(FFI::MemoryPointer.from_string(defi["memoryRequirements_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuArrayGetPlane_entry"] = lambda { |defi|
  s = "{ "
  s << "pPlaneArray: #{"0x%016x" % defi["pPlaneArray"]}"
  s << ', '
  s << "hArray: #{"0x%016x" % defi["hArray"]}"
  s << ', '
  s << "planeIdx: #{defi["planeIdx"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuArrayGetPlane_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pPlaneArray_val: #{"0x%016x" % defi["pPlaneArray_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuArrayDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "hArray: #{"0x%016x" % defi["hArray"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuArrayDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuArray3DCreate_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "pHandle: #{"0x%016x" % defi["pHandle"]}"
  s << ', '
  s << "pAllocateArray: #{"0x%016x" % defi["pAllocateArray"]}"
  s << ', '
  s << "pAllocateArray_val: #{defi["pAllocateArray_val"].size > 0 ? CUDA::CUDAARRAY3DDESCRIPTORV2.new(FFI::MemoryPointer.from_string(defi["pAllocateArray_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuArray3DCreate_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pHandle_val: #{"0x%016x" % defi["pHandle_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuArray3DGetDescriptor_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "pArrayDescriptor: #{"0x%016x" % defi["pArrayDescriptor"]}"
  s << ', '
  s << "hArray: #{"0x%016x" % defi["hArray"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuArray3DGetDescriptor_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pArrayDescriptor_val: #{defi["pArrayDescriptor_val"].size > 0 ? CUDA::CUDAARRAY3DDESCRIPTORV2.new(FFI::MemoryPointer.from_string(defi["pArrayDescriptor_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMipmappedArrayCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "pHandle: #{"0x%016x" % defi["pHandle"]}"
  s << ', '
  s << "pMipmappedArrayDesc: #{"0x%016x" % defi["pMipmappedArrayDesc"]}"
  s << ', '
  s << "numMipmapLevels: #{defi["numMipmapLevels"]}"
  s << ', '
  s << "pMipmappedArrayDesc_val: #{defi["pMipmappedArrayDesc_val"].size > 0 ? CUDA::CUDAARRAY3DDESCRIPTORV2.new(FFI::MemoryPointer.from_string(defi["pMipmappedArrayDesc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMipmappedArrayCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pHandle_val: #{"0x%016x" % defi["pHandle_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMipmappedArrayGetLevel_entry"] = lambda { |defi|
  s = "{ "
  s << "pLevelArray: #{"0x%016x" % defi["pLevelArray"]}"
  s << ', '
  s << "hMipmappedArray: #{"0x%016x" % defi["hMipmappedArray"]}"
  s << ', '
  s << "level: #{defi["level"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMipmappedArrayGetLevel_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pLevelArray_val: #{"0x%016x" % defi["pLevelArray_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMipmappedArrayDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "hMipmappedArray: #{"0x%016x" % defi["hMipmappedArray"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMipmappedArrayDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemGetHandleForAddressRange_entry"] = lambda { |defi|
  s = "{ "
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << ', '
  s << "dptr: #{"0x%016x" % defi["dptr"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "handleType: #{CUDA::CUMemRangeHandleType.from_native(defi["handleType"], nil)}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemGetHandleForAddressRange_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "handle_val: #{defi["handle_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemBatchDecompressAsync_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "paramsArray: #{"0x%016x" % defi["paramsArray"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "errorIndex: #{"0x%016x" % defi["errorIndex"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "paramsArray_vals: [ #{p = FFI::MemoryPointer.from_string(defi["paramsArray_vals"]); sz = CUDA::CUMemDecompressParams.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUMemDecompressParams.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemBatchDecompressAsync_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "errorIndex_val: #{defi["errorIndex_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemAddressReserve_entry"] = lambda { |defi|
  s = "{ "
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "alignment: #{defi["alignment"]}"
  s << ', '
  s << "addr: #{"0x%016x" % defi["addr"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemAddressReserve_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "ptr_val: #{"0x%016x" % defi["ptr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemAddressFree_entry"] = lambda { |defi|
  s = "{ "
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemAddressFree_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "prop: #{"0x%016x" % defi["prop"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "prop_val: #{defi["prop_val"].size > 0 ? CUDA::CUMemAllocationPropV1.new(FFI::MemoryPointer.from_string(defi["prop_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "handle_val: #{defi["handle_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemRelease_entry"] = lambda { |defi|
  s = "{ "
  s << "handle: #{defi["handle"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemRelease_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemMap_entry"] = lambda { |defi|
  s = "{ "
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "handle: #{defi["handle"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemMap_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemMapArrayAsync_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "mapInfoList: #{"0x%016x" % defi["mapInfoList"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "mapInfoList_vals: [ #{p = FFI::MemoryPointer.from_string(defi["mapInfoList_vals"]); sz = CUDA::CUArrayMapInfoV1.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUArrayMapInfoV1.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemMapArrayAsync_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemUnmap_entry"] = lambda { |defi|
  s = "{ "
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemUnmap_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemSetAccess_entry"] = lambda { |defi|
  s = "{ "
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].size > 0 ? CUDA::CUMemAccessDescV1.new(FFI::MemoryPointer.from_string(defi["desc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemSetAccess_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemGetAccess_entry"] = lambda { |defi|
  s = "{ "
  s << "flags: #{"0x%016x" % defi["flags"]}"
  s << ', '
  s << "location: #{"0x%016x" % defi["location"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "location_val: #{defi["location_val"].size > 0 ? CUDA::CUMemLocationV1.new(FFI::MemoryPointer.from_string(defi["location_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemGetAccess_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "flags_val: #{defi["flags_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemExportToShareableHandle_entry"] = lambda { |defi|
  s = "{ "
  s << "shareableHandle: #{"0x%016x" % defi["shareableHandle"]}"
  s << ', '
  s << "handle: #{defi["handle"]}"
  s << ', '
  s << "handleType: #{CUDA::CUMemAllocationHandleType.from_native(defi["handleType"], nil)}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemExportToShareableHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "shareableHandle_val: #{defi["shareableHandle_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemImportFromShareableHandle_entry"] = lambda { |defi|
  s = "{ "
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << ', '
  s << "osHandle: #{"0x%016x" % defi["osHandle"]}"
  s << ', '
  s << "shHandleType: #{CUDA::CUMemAllocationHandleType.from_native(defi["shHandleType"], nil)}"
  s << ', '
  s << "osHandle_val: #{defi["osHandle_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemImportFromShareableHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "handle_val: #{defi["handle_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemGetAllocationGranularity_entry"] = lambda { |defi|
  s = "{ "
  s << "granularity: #{"0x%016x" % defi["granularity"]}"
  s << ', '
  s << "prop: #{"0x%016x" % defi["prop"]}"
  s << ', '
  s << "option: #{CUDA::CUMemAllocationGranularityFlags.from_native(defi["option"], nil)}"
  s << ', '
  s << "prop_val: #{defi["prop_val"].size > 0 ? CUDA::CUMemAllocationPropV1.new(FFI::MemoryPointer.from_string(defi["prop_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemGetAllocationGranularity_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "granularity_val: #{defi["granularity_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemGetAllocationPropertiesFromHandle_entry"] = lambda { |defi|
  s = "{ "
  s << "prop: #{"0x%016x" % defi["prop"]}"
  s << ', '
  s << "handle: #{defi["handle"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemGetAllocationPropertiesFromHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "prop_val: #{defi["prop_val"].size > 0 ? CUDA::CUMemAllocationPropV1.new(FFI::MemoryPointer.from_string(defi["prop_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemRetainAllocationHandle_entry"] = lambda { |defi|
  s = "{ "
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << ', '
  s << "addr: #{"0x%016x" % defi["addr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemRetainAllocationHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "handle_val: #{defi["handle_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemFreeAsync_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "dptr: #{"0x%016x" % defi["dptr"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemFreeAsync_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemAllocAsync_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "dptr: #{"0x%016x" % defi["dptr"]}"
  s << ', '
  s << "bytesize: #{defi["bytesize"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemAllocAsync_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "dptr_val: #{"0x%016x" % defi["dptr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemPoolTrimTo_entry"] = lambda { |defi|
  s = "{ "
  s << "pool: #{"0x%016x" % defi["pool"]}"
  s << ', '
  s << "minBytesToKeep: #{defi["minBytesToKeep"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemPoolTrimTo_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemPoolSetAttribute_entry"] = lambda { |defi|
  s = "{ "
  s << "pool: #{"0x%016x" % defi["pool"]}"
  s << ', '
  s << "attr: #{CUDA::CUMemPoolAttribute.from_native(defi["attr"], nil)}"
  s << ', '
  s << "value: #{"0x%016x" % defi["value"]}"
  s << ', '
  s << "value_val: #{defi["value_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemPoolSetAttribute_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemPoolGetAttribute_entry"] = lambda { |defi|
  s = "{ "
  s << "pool: #{"0x%016x" % defi["pool"]}"
  s << ', '
  s << "attr: #{CUDA::CUMemPoolAttribute.from_native(defi["attr"], nil)}"
  s << ', '
  s << "value: #{"0x%016x" % defi["value"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemPoolGetAttribute_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "value_val: #{defi["value_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemPoolSetAccess_entry"] = lambda { |defi|
  s = "{ "
  s << "pool: #{"0x%016x" % defi["pool"]}"
  s << ', '
  s << "map: #{"0x%016x" % defi["map"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "map_vals: [ #{p = FFI::MemoryPointer.from_string(defi["map_vals"]); sz = CUDA::CUMemAccessDescV1.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUMemAccessDescV1.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemPoolSetAccess_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemPoolGetAccess_entry"] = lambda { |defi|
  s = "{ "
  s << "flags: #{"0x%016x" % defi["flags"]}"
  s << ', '
  s << "memPool: #{"0x%016x" % defi["memPool"]}"
  s << ', '
  s << "location: #{"0x%016x" % defi["location"]}"
  s << ', '
  s << "location_val: #{defi["location_val"].size > 0 ? CUDA::CUMemLocationV1.new(FFI::MemoryPointer.from_string(defi["location_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemPoolGetAccess_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "flags_val: #{CUDA::CUMemAccessFlags.from_native(defi["flags_val"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemPoolCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "pool: #{"0x%016x" % defi["pool"]}"
  s << ', '
  s << "poolProps: #{"0x%016x" % defi["poolProps"]}"
  s << ', '
  s << "poolProps_val: #{defi["poolProps_val"].size > 0 ? CUDA::CUMemPoolPropsV1.new(FFI::MemoryPointer.from_string(defi["poolProps_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemPoolCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pool_val: #{"0x%016x" % defi["pool_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemPoolDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "pool: #{"0x%016x" % defi["pool"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemPoolDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemGetDefaultMemPool_entry"] = lambda { |defi|
  s = "{ "
  s << "pool_out: #{"0x%016x" % defi["pool_out"]}"
  s << ', '
  s << "location: #{"0x%016x" % defi["location"]}"
  s << ', '
  s << "type: #{CUDA::CUMemAllocationType.from_native(defi["type"], nil)}"
  s << ', '
  s << "location_val: #{defi["location_val"].size > 0 ? CUDA::CUMemLocationV1.new(FFI::MemoryPointer.from_string(defi["location_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemGetDefaultMemPool_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pool_out_val: #{"0x%016x" % defi["pool_out_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemGetMemPool_entry"] = lambda { |defi|
  s = "{ "
  s << "pool: #{"0x%016x" % defi["pool"]}"
  s << ', '
  s << "location: #{"0x%016x" % defi["location"]}"
  s << ', '
  s << "type: #{CUDA::CUMemAllocationType.from_native(defi["type"], nil)}"
  s << ', '
  s << "location_val: #{defi["location_val"].size > 0 ? CUDA::CUMemLocationV1.new(FFI::MemoryPointer.from_string(defi["location_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemGetMemPool_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pool_val: #{"0x%016x" % defi["pool_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemSetMemPool_entry"] = lambda { |defi|
  s = "{ "
  s << "location: #{"0x%016x" % defi["location"]}"
  s << ', '
  s << "type: #{CUDA::CUMemAllocationType.from_native(defi["type"], nil)}"
  s << ', '
  s << "pool: #{"0x%016x" % defi["pool"]}"
  s << ', '
  s << "location_val: #{defi["location_val"].size > 0 ? CUDA::CUMemLocationV1.new(FFI::MemoryPointer.from_string(defi["location_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemSetMemPool_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemAllocFromPoolAsync_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "dptr: #{"0x%016x" % defi["dptr"]}"
  s << ', '
  s << "bytesize: #{defi["bytesize"]}"
  s << ', '
  s << "pool: #{"0x%016x" % defi["pool"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemAllocFromPoolAsync_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "dptr_val: #{"0x%016x" % defi["dptr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemPoolExportToShareableHandle_entry"] = lambda { |defi|
  s = "{ "
  s << "handle_out: #{"0x%016x" % defi["handle_out"]}"
  s << ', '
  s << "pool: #{"0x%016x" % defi["pool"]}"
  s << ', '
  s << "handleType: #{CUDA::CUMemAllocationHandleType.from_native(defi["handleType"], nil)}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemPoolExportToShareableHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "handle_out_val: #{defi["handle_out_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemPoolImportFromShareableHandle_entry"] = lambda { |defi|
  s = "{ "
  s << "pool_out: #{"0x%016x" % defi["pool_out"]}"
  s << ', '
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << ', '
  s << "handleType: #{CUDA::CUMemAllocationHandleType.from_native(defi["handleType"], nil)}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "handle_val: #{defi["handle_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemPoolImportFromShareableHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pool_out_val: #{"0x%016x" % defi["pool_out_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemPoolExportPointer_entry"] = lambda { |defi|
  s = "{ "
  s << "shareData_out: #{"0x%016x" % defi["shareData_out"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemPoolExportPointer_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "shareData_out_val: #{defi["shareData_out_val"].size > 0 ? CUDA::CUMemPoolPtrExportDataV1.new(FFI::MemoryPointer.from_string(defi["shareData_out_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemPoolImportPointer_entry"] = lambda { |defi|
  s = "{ "
  s << "ptr_out: #{"0x%016x" % defi["ptr_out"]}"
  s << ', '
  s << "pool: #{"0x%016x" % defi["pool"]}"
  s << ', '
  s << "shareData: #{"0x%016x" % defi["shareData"]}"
  s << ', '
  s << "shareData_val: #{defi["shareData_val"].size > 0 ? CUDA::CUMemPoolPtrExportDataV1.new(FFI::MemoryPointer.from_string(defi["shareData_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemPoolImportPointer_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "ptr_out_val: #{"0x%016x" % defi["ptr_out_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMulticastCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "mcHandle: #{"0x%016x" % defi["mcHandle"]}"
  s << ', '
  s << "prop: #{"0x%016x" % defi["prop"]}"
  s << ', '
  s << "prop_val: #{defi["prop_val"].size > 0 ? CUDA::CUMulticastObjectPropV1.new(FFI::MemoryPointer.from_string(defi["prop_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMulticastCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "mcHandle_val: #{defi["mcHandle_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMulticastAddDevice_entry"] = lambda { |defi|
  s = "{ "
  s << "mcHandle: #{defi["mcHandle"]}"
  s << ', '
  s << "dev: #{defi["dev"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMulticastAddDevice_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMulticastBindMem_entry"] = lambda { |defi|
  s = "{ "
  s << "mcHandle: #{defi["mcHandle"]}"
  s << ', '
  s << "mcOffset: #{defi["mcOffset"]}"
  s << ', '
  s << "memHandle: #{defi["memHandle"]}"
  s << ', '
  s << "memOffset: #{defi["memOffset"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMulticastBindMem_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMulticastBindAddr_entry"] = lambda { |defi|
  s = "{ "
  s << "mcHandle: #{defi["mcHandle"]}"
  s << ', '
  s << "mcOffset: #{defi["mcOffset"]}"
  s << ', '
  s << "memptr: #{"0x%016x" % defi["memptr"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMulticastBindAddr_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMulticastUnbind_entry"] = lambda { |defi|
  s = "{ "
  s << "mcHandle: #{defi["mcHandle"]}"
  s << ', '
  s << "dev: #{defi["dev"]}"
  s << ', '
  s << "mcOffset: #{defi["mcOffset"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMulticastUnbind_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMulticastGetGranularity_entry"] = lambda { |defi|
  s = "{ "
  s << "granularity: #{"0x%016x" % defi["granularity"]}"
  s << ', '
  s << "prop: #{"0x%016x" % defi["prop"]}"
  s << ', '
  s << "option: #{CUDA::CUMulticastGranularityFlags.from_native(defi["option"], nil)}"
  s << ', '
  s << "prop_val: #{defi["prop_val"].size > 0 ? CUDA::CUMulticastObjectPropV1.new(FFI::MemoryPointer.from_string(defi["prop_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMulticastGetGranularity_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "granularity_val: #{defi["granularity_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuPointerGetAttribute_entry"] = lambda { |defi|
  s = "{ "
  s << "data: #{"0x%016x" % defi["data"]}"
  s << ', '
  s << "attribute: #{CUDA::CUPointerAttribute.from_native(defi["attribute"], nil)}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuPointerGetAttribute_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "data_val: #{defi["data_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemPrefetchAsync_v2_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "devPtr: #{"0x%016x" % defi["devPtr"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "location: #{defi["location"].size > 0 ? CUDA::CUMemLocationV1.new(FFI::MemoryPointer.from_string(defi["location"])) : nil}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemPrefetchAsync_v2_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemAdvise_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "devPtr: #{"0x%016x" % defi["devPtr"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "advice: #{CUDA::CUMemAdvise.from_native(defi["advice"], nil)}"
  s << ', '
  s << "location: #{defi["location"].size > 0 ? CUDA::CUMemLocationV1.new(FFI::MemoryPointer.from_string(defi["location"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemAdvise_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemPrefetchBatchAsync_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "dptrs: #{"0x%016x" % defi["dptrs"]}"
  s << ', '
  s << "sizes: #{"0x%016x" % defi["sizes"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "prefetchLocs: #{"0x%016x" % defi["prefetchLocs"]}"
  s << ', '
  s << "prefetchLocIdxs: #{"0x%016x" % defi["prefetchLocIdxs"]}"
  s << ', '
  s << "numPrefetchLocs: #{defi["numPrefetchLocs"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "dptrs_vals: [ #{defi["dptrs_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "sizes_vals: #{defi["sizes_vals"]}"
  s << ', '
  s << "prefetchLocs_vals: [ #{p = FFI::MemoryPointer.from_string(defi["prefetchLocs_vals"]); sz = CUDA::CUMemLocationV1.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUMemLocationV1.new(p + i*sz).to_s}.join(", ")} ]"
  s << ', '
  s << "prefetchLocIdxs_vals: #{defi["prefetchLocIdxs_vals"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemPrefetchBatchAsync_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemDiscardBatchAsync_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "dptrs: #{"0x%016x" % defi["dptrs"]}"
  s << ', '
  s << "sizes: #{"0x%016x" % defi["sizes"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "dptrs_vals: [ #{defi["dptrs_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "sizes_vals: #{defi["sizes_vals"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemDiscardBatchAsync_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemDiscardAndPrefetchBatchAsync_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "dptrs: #{"0x%016x" % defi["dptrs"]}"
  s << ', '
  s << "sizes: #{"0x%016x" % defi["sizes"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "prefetchLocs: #{"0x%016x" % defi["prefetchLocs"]}"
  s << ', '
  s << "prefetchLocIdxs: #{"0x%016x" % defi["prefetchLocIdxs"]}"
  s << ', '
  s << "numPrefetchLocs: #{defi["numPrefetchLocs"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "dptrs_vals: [ #{defi["dptrs_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "sizes_vals: #{defi["sizes_vals"]}"
  s << ', '
  s << "prefetchLocs_vals: [ #{p = FFI::MemoryPointer.from_string(defi["prefetchLocs_vals"]); sz = CUDA::CUMemLocationV1.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUMemLocationV1.new(p + i*sz).to_s}.join(", ")} ]"
  s << ', '
  s << "prefetchLocIdxs_vals: #{defi["prefetchLocIdxs_vals"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemDiscardAndPrefetchBatchAsync_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemRangeGetAttribute_entry"] = lambda { |defi|
  s = "{ "
  s << "data: #{"0x%016x" % defi["data"]}"
  s << ', '
  s << "dataSize: #{defi["dataSize"]}"
  s << ', '
  s << "attribute: #{CUDA::CUMemRangeAttribute.from_native(defi["attribute"], nil)}"
  s << ', '
  s << "devPtr: #{"0x%016x" % defi["devPtr"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemRangeGetAttribute_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "data_vals: #{defi["data_vals"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemRangeGetAttributes_entry"] = lambda { |defi|
  s = "{ "
  s << "data: #{"0x%016x" % defi["data"]}"
  s << ', '
  s << "dataSizes: #{"0x%016x" % defi["dataSizes"]}"
  s << ', '
  s << "attributes: #{"0x%016x" % defi["attributes"]}"
  s << ', '
  s << "numAttributes: #{defi["numAttributes"]}"
  s << ', '
  s << "devPtr: #{"0x%016x" % defi["devPtr"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "attributes_vals: #{defi["attributes_vals"]}"
  s << ', '
  s << "dataSizes_vals: #{defi["dataSizes_vals"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemRangeGetAttributes_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuPointerSetAttribute_entry"] = lambda { |defi|
  s = "{ "
  s << "value: #{"0x%016x" % defi["value"]}"
  s << ', '
  s << "attribute: #{CUDA::CUPointerAttribute.from_native(defi["attribute"], nil)}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "value_val: #{defi["value_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuPointerSetAttribute_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuPointerGetAttributes_entry"] = lambda { |defi|
  s = "{ "
  s << "numAttributes: #{defi["numAttributes"]}"
  s << ', '
  s << "attributes: #{"0x%016x" % defi["attributes"]}"
  s << ', '
  s << "data: #{"0x%016x" % defi["data"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "attributes_vals: #{defi["attributes_vals"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuPointerGetAttributes_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "data_vals: [ #{defi["data_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "phStream: #{"0x%016x" % defi["phStream"]}"
  s << ', '
  s << "Flags: #{defi["Flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phStream_val: #{"0x%016x" % defi["phStream_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamCreateWithPriority_entry"] = lambda { |defi|
  s = "{ "
  s << "phStream: #{"0x%016x" % defi["phStream"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "priority: #{defi["priority"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamCreateWithPriority_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phStream_val: #{"0x%016x" % defi["phStream_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetPriority_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "priority: #{"0x%016x" % defi["priority"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetPriority_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "priority_val: #{defi["priority_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetDevice_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "device: #{"0x%016x" % defi["device"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetDevice_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "device_val: #{defi["device_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetFlags_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "flags: #{"0x%016x" % defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetFlags_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "flags_val: #{defi["flags_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetId_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "streamId: #{"0x%016x" % defi["streamId"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetId_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "streamId_val: #{defi["streamId_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetCtx_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "pctx: #{"0x%016x" % defi["pctx"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetCtx_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pctx_val: #{"0x%016x" % defi["pctx_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetCtx_v2_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "pCtx: #{"0x%016x" % defi["pCtx"]}"
  s << ', '
  s << "pGreenCtx: #{"0x%016x" % defi["pGreenCtx"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetCtx_v2_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pCtx_val: #{"0x%016x" % defi["pCtx_val"]}"
  s << ', '
  s << "pGreenCtx_val: #{"0x%016x" % defi["pGreenCtx_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamWaitEvent_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "hEvent: #{"0x%016x" % defi["hEvent"]}"
  s << ', '
  s << "Flags: #{defi["Flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamWaitEvent_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamAddCallback_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "callback: #{"0x%016x" % defi["callback"]}"
  s << ', '
  s << "userData: #{"0x%016x" % defi["userData"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamAddCallback_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamBeginCapture_v2_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "mode: #{CUDA::CUStreamCaptureMode.from_native(defi["mode"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamBeginCapture_v2_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamBeginCaptureToGraph_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "dependencies: #{"0x%016x" % defi["dependencies"]}"
  s << ', '
  s << "dependencyData: #{"0x%016x" % defi["dependencyData"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "mode: #{CUDA::CUStreamCaptureMode.from_native(defi["mode"], nil)}"
  s << ', '
  s << "dependencies_vals: [ #{defi["dependencies_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "dependencyData_vals: [ #{p = FFI::MemoryPointer.from_string(defi["dependencyData_vals"]); sz = CUDA::CUGraphEdgeData.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUGraphEdgeData.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamBeginCaptureToGraph_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuThreadExchangeStreamCaptureMode_entry"] = lambda { |defi|
  s = "{ "
  s << "mode: #{"0x%016x" % defi["mode"]}"
  s << ', '
  s << "mode_val: #{CUDA::CUStreamCaptureMode.from_native(defi["mode_val"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuThreadExchangeStreamCaptureMode_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "mode_val: #{CUDA::CUStreamCaptureMode.from_native(defi["mode_val"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamEndCapture_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "phGraph: #{"0x%016x" % defi["phGraph"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamEndCapture_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phGraph_val: #{"0x%016x" % defi["phGraph_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamIsCapturing_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "captureStatus: #{"0x%016x" % defi["captureStatus"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamIsCapturing_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "captureStatus_val: #{CUDA::CUStreamCaptureStatus.from_native(defi["captureStatus_val"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetCaptureInfo_v3_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "captureStatus_out: #{"0x%016x" % defi["captureStatus_out"]}"
  s << ', '
  s << "id_out: #{"0x%016x" % defi["id_out"]}"
  s << ', '
  s << "graph_out: #{"0x%016x" % defi["graph_out"]}"
  s << ', '
  s << "dependencies_out: #{"0x%016x" % defi["dependencies_out"]}"
  s << ', '
  s << "edgeData_out: #{"0x%016x" % defi["edgeData_out"]}"
  s << ', '
  s << "numDependencies_out: #{"0x%016x" % defi["numDependencies_out"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetCaptureInfo_v3_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "captureStatus_out_val: #{CUDA::CUStreamCaptureStatus.from_native(defi["captureStatus_out_val"], nil)}"
  s << ', '
  s << "id_out_val: #{defi["id_out_val"]}"
  s << ', '
  s << "graph_out_val: #{"0x%016x" % defi["graph_out_val"]}"
  s << ', '
  s << "numDependencies_out_val: #{defi["numDependencies_out_val"]}"
  s << ', '
  s << "dependencies_out_val_vals: [ #{defi["dependencies_out_val_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "edgeData_out_val_vals: [ #{p = FFI::MemoryPointer.from_string(defi["edgeData_out_val_vals"]); sz = CUDA::CUGraphEdgeData.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUGraphEdgeData.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamUpdateCaptureDependencies_v2_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "dependencies: #{"0x%016x" % defi["dependencies"]}"
  s << ', '
  s << "dependencyData: #{"0x%016x" % defi["dependencyData"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "dependencies_vals: [ #{defi["dependencies_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "dependencyData_vals: [ #{p = FFI::MemoryPointer.from_string(defi["dependencyData_vals"]); sz = CUDA::CUGraphEdgeData.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUGraphEdgeData.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamUpdateCaptureDependencies_v2_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamAttachMemAsync_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "dptr: #{"0x%016x" % defi["dptr"]}"
  s << ', '
  s << "length: #{defi["length"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamAttachMemAsync_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamQuery_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamQuery_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamSynchronize_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamSynchronize_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamDestroy_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamDestroy_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamCopyAttributes_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamCopyAttributes_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetAttribute_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "attr: #{defi["attr"]}"
  s << ', '
  s << "value_out: #{"0x%016x" % defi["value_out"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetAttribute_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "value_out_val: #{defi["value_out_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamSetAttribute_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "attr: #{defi["attr"]}"
  s << ', '
  s << "value: #{"0x%016x" % defi["value"]}"
  s << ', '
  s << "value_val: #{defi["value_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamSetAttribute_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuEventCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "phEvent: #{"0x%016x" % defi["phEvent"]}"
  s << ', '
  s << "Flags: #{defi["Flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuEventCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phEvent_val: #{"0x%016x" % defi["phEvent_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuEventRecord_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "hEvent: #{"0x%016x" % defi["hEvent"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuEventRecord_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuEventRecordWithFlags_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "hEvent: #{"0x%016x" % defi["hEvent"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuEventRecordWithFlags_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuEventQuery_entry"] = lambda { |defi|
  s = "{ "
  s << "hEvent: #{"0x%016x" % defi["hEvent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuEventQuery_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuEventSynchronize_entry"] = lambda { |defi|
  s = "{ "
  s << "hEvent: #{"0x%016x" % defi["hEvent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuEventSynchronize_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuEventDestroy_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "hEvent: #{"0x%016x" % defi["hEvent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuEventDestroy_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuEventElapsedTime_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "pMilliseconds: #{"0x%016x" % defi["pMilliseconds"]}"
  s << ', '
  s << "hStart: #{"0x%016x" % defi["hStart"]}"
  s << ', '
  s << "hEnd: #{"0x%016x" % defi["hEnd"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuEventElapsedTime_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pMilliseconds_val: #{defi["pMilliseconds_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuImportExternalMemory_entry"] = lambda { |defi|
  s = "{ "
  s << "extMem_out: #{"0x%016x" % defi["extMem_out"]}"
  s << ', '
  s << "memHandleDesc: #{"0x%016x" % defi["memHandleDesc"]}"
  s << ', '
  s << "memHandleDesc_val: #{defi["memHandleDesc_val"].size > 0 ? CUDA::CUDAEXTERNALMEMORYHANDLEDESCV1.new(FFI::MemoryPointer.from_string(defi["memHandleDesc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuImportExternalMemory_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "extMem_out_val: #{"0x%016x" % defi["extMem_out_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuExternalMemoryGetMappedBuffer_entry"] = lambda { |defi|
  s = "{ "
  s << "devPtr: #{"0x%016x" % defi["devPtr"]}"
  s << ', '
  s << "extMem: #{"0x%016x" % defi["extMem"]}"
  s << ', '
  s << "bufferDesc: #{"0x%016x" % defi["bufferDesc"]}"
  s << ', '
  s << "bufferDesc_val: #{defi["bufferDesc_val"].size > 0 ? CUDA::CUDAEXTERNALMEMORYBUFFERDESCV1.new(FFI::MemoryPointer.from_string(defi["bufferDesc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuExternalMemoryGetMappedBuffer_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "devPtr_val: #{"0x%016x" % defi["devPtr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuExternalMemoryGetMappedMipmappedArray_entry"] = lambda { |defi|
  s = "{ "
  s << "mipmap: #{"0x%016x" % defi["mipmap"]}"
  s << ', '
  s << "extMem: #{"0x%016x" % defi["extMem"]}"
  s << ', '
  s << "mipmapDesc: #{"0x%016x" % defi["mipmapDesc"]}"
  s << ', '
  s << "mipmapDesc_val: #{defi["mipmapDesc_val"].size > 0 ? CUDA::CUDAEXTERNALMEMORYMIPMAPPEDARRAYDESCV1.new(FFI::MemoryPointer.from_string(defi["mipmapDesc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuExternalMemoryGetMappedMipmappedArray_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "mipmap_val: #{"0x%016x" % defi["mipmap_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDestroyExternalMemory_entry"] = lambda { |defi|
  s = "{ "
  s << "extMem: #{"0x%016x" % defi["extMem"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDestroyExternalMemory_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuImportExternalSemaphore_entry"] = lambda { |defi|
  s = "{ "
  s << "extSem_out: #{"0x%016x" % defi["extSem_out"]}"
  s << ', '
  s << "semHandleDesc: #{"0x%016x" % defi["semHandleDesc"]}"
  s << ', '
  s << "semHandleDesc_val: #{defi["semHandleDesc_val"].size > 0 ? CUDA::CUDAEXTERNALSEMAPHOREHANDLEDESCV1.new(FFI::MemoryPointer.from_string(defi["semHandleDesc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuImportExternalSemaphore_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "extSem_out_val: #{"0x%016x" % defi["extSem_out_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuSignalExternalSemaphoresAsync_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "extSemArray: #{"0x%016x" % defi["extSemArray"]}"
  s << ', '
  s << "paramsArray: #{"0x%016x" % defi["paramsArray"]}"
  s << ', '
  s << "numExtSems: #{defi["numExtSems"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "extSemArray_vals: [ #{defi["extSemArray_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "paramsArray_vals: [ #{p = FFI::MemoryPointer.from_string(defi["paramsArray_vals"]); sz = CUDA::CUDAEXTERNALSEMAPHORESIGNALPARAMSV1.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUDAEXTERNALSEMAPHORESIGNALPARAMSV1.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuSignalExternalSemaphoresAsync_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuWaitExternalSemaphoresAsync_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "extSemArray: #{"0x%016x" % defi["extSemArray"]}"
  s << ', '
  s << "paramsArray: #{"0x%016x" % defi["paramsArray"]}"
  s << ', '
  s << "numExtSems: #{defi["numExtSems"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "extSemArray_vals: [ #{defi["extSemArray_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "paramsArray_vals: [ #{p = FFI::MemoryPointer.from_string(defi["paramsArray_vals"]); sz = CUDA::CUDAEXTERNALSEMAPHOREWAITPARAMSV1.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUDAEXTERNALSEMAPHOREWAITPARAMSV1.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuWaitExternalSemaphoresAsync_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDestroyExternalSemaphore_entry"] = lambda { |defi|
  s = "{ "
  s << "extSem: #{"0x%016x" % defi["extSem"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDestroyExternalSemaphore_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamWaitValue32_v2_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "addr: #{"0x%016x" % defi["addr"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamWaitValue32_v2_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamWaitValue64_v2_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "addr: #{"0x%016x" % defi["addr"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamWaitValue64_v2_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamWriteValue32_v2_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "addr: #{"0x%016x" % defi["addr"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamWriteValue32_v2_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamWriteValue64_v2_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "addr: #{"0x%016x" % defi["addr"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamWriteValue64_v2_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamBatchMemOp_v2_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "paramArray: #{"0x%016x" % defi["paramArray"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "paramArray_vals: #{defi["paramArray_vals"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamBatchMemOp_v2_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuFuncGetAttribute_entry"] = lambda { |defi|
  s = "{ "
  s << "pi: #{"0x%016x" % defi["pi"]}"
  s << ', '
  s << "attrib: #{CUDA::CUFunctionAttribute.from_native(defi["attrib"], nil)}"
  s << ', '
  s << "hfunc: #{"0x%016x" % defi["hfunc"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuFuncGetAttribute_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pi_val: #{defi["pi_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuFuncSetAttribute_entry"] = lambda { |defi|
  s = "{ "
  s << "hfunc: #{"0x%016x" % defi["hfunc"]}"
  s << ', '
  s << "attrib: #{CUDA::CUFunctionAttribute.from_native(defi["attrib"], nil)}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuFuncSetAttribute_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuFuncSetCacheConfig_entry"] = lambda { |defi|
  s = "{ "
  s << "hfunc: #{"0x%016x" % defi["hfunc"]}"
  s << ', '
  s << "config: #{CUDA::CUFuncCache.from_native(defi["config"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuFuncSetCacheConfig_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuFuncGetModule_entry"] = lambda { |defi|
  s = "{ "
  s << "hmod: #{"0x%016x" % defi["hmod"]}"
  s << ', '
  s << "hfunc: #{"0x%016x" % defi["hfunc"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuFuncGetModule_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "hmod_val: #{"0x%016x" % defi["hmod_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuFuncGetName_entry"] = lambda { |defi|
  s = "{ "
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "hfunc: #{"0x%016x" % defi["hfunc"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuFuncGetName_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "name_val_val: #{defi["name_val_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuFuncGetParamInfo_entry"] = lambda { |defi|
  s = "{ "
  s << "func: #{"0x%016x" % defi["func"]}"
  s << ', '
  s << "paramIndex: #{defi["paramIndex"]}"
  s << ', '
  s << "paramOffset: #{"0x%016x" % defi["paramOffset"]}"
  s << ', '
  s << "paramSize: #{"0x%016x" % defi["paramSize"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuFuncGetParamInfo_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "paramOffset_val: #{defi["paramOffset_val"]}"
  s << ', '
  s << "paramSize_val: #{defi["paramSize_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuFuncIsLoaded_entry"] = lambda { |defi|
  s = "{ "
  s << "state: #{"0x%016x" % defi["state"]}"
  s << ', '
  s << "function: #{"0x%016x" % defi["function"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuFuncIsLoaded_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "state_val: #{CUDA::CUFunctionLoadingState.from_native(defi["state_val"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuFuncLoad_entry"] = lambda { |defi|
  s = "{ "
  s << "function: #{"0x%016x" % defi["function"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuFuncLoad_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLaunchKernel_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "f: #{"0x%016x" % defi["f"]}"
  s << ', '
  s << "gridDimX: #{defi["gridDimX"]}"
  s << ', '
  s << "gridDimY: #{defi["gridDimY"]}"
  s << ', '
  s << "gridDimZ: #{defi["gridDimZ"]}"
  s << ', '
  s << "blockDimX: #{defi["blockDimX"]}"
  s << ', '
  s << "blockDimY: #{defi["blockDimY"]}"
  s << ', '
  s << "blockDimZ: #{defi["blockDimZ"]}"
  s << ', '
  s << "sharedMemBytes: #{defi["sharedMemBytes"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "kernelParams: #{"0x%016x" % defi["kernelParams"]}"
  s << ', '
  s << "extra: #{"0x%016x" % defi["extra"]}"
  s << ', '
  s << "extra_vals: [ #{defi["extra_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLaunchKernel_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLaunchKernelEx_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "config: #{"0x%016x" % defi["config"]}"
  s << ', '
  s << "f: #{"0x%016x" % defi["f"]}"
  s << ', '
  s << "kernelParams: #{"0x%016x" % defi["kernelParams"]}"
  s << ', '
  s << "extra: #{"0x%016x" % defi["extra"]}"
  s << ', '
  s << "config_val: #{defi["config_val"].size > 0 ? CUDA::CULaunchConfig.new(FFI::MemoryPointer.from_string(defi["config_val"])) : nil}"
  s << ', '
  s << "config__attrs_vals: [ #{p = FFI::MemoryPointer.from_string(defi["config__attrs_vals"]); sz = CUDA::CULaunchAttribute.size; n = p.size / sz; (0...n).collect { |i| CUDA::CULaunchAttribute.new(p + i*sz).to_s}.join(", ")} ]"
  s << ', '
  s << "extra_vals: [ #{defi["extra_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLaunchKernelEx_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLaunchCooperativeKernel_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "f: #{"0x%016x" % defi["f"]}"
  s << ', '
  s << "gridDimX: #{defi["gridDimX"]}"
  s << ', '
  s << "gridDimY: #{defi["gridDimY"]}"
  s << ', '
  s << "gridDimZ: #{defi["gridDimZ"]}"
  s << ', '
  s << "blockDimX: #{defi["blockDimX"]}"
  s << ', '
  s << "blockDimY: #{defi["blockDimY"]}"
  s << ', '
  s << "blockDimZ: #{defi["blockDimZ"]}"
  s << ', '
  s << "sharedMemBytes: #{defi["sharedMemBytes"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "kernelParams: #{"0x%016x" % defi["kernelParams"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLaunchCooperativeKernel_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLaunchCooperativeKernelMultiDevice_entry"] = lambda { |defi|
  s = "{ "
  s << "launchParamsList: #{"0x%016x" % defi["launchParamsList"]}"
  s << ', '
  s << "numDevices: #{defi["numDevices"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "launchParamsList_vals: [ #{p = FFI::MemoryPointer.from_string(defi["launchParamsList_vals"]); sz = CUDA::CUDALAUNCHPARAMSV1.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUDALAUNCHPARAMSV1.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLaunchCooperativeKernelMultiDevice_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLaunchHostFunc_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "fn: #{"0x%016x" % defi["fn"]}"
  s << ', '
  s << "userData: #{"0x%016x" % defi["userData"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLaunchHostFunc_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuFuncSetBlockShape_entry"] = lambda { |defi|
  s = "{ "
  s << "hfunc: #{"0x%016x" % defi["hfunc"]}"
  s << ', '
  s << "x: #{defi["x"]}"
  s << ', '
  s << "y: #{defi["y"]}"
  s << ', '
  s << "z: #{defi["z"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuFuncSetBlockShape_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuFuncSetSharedSize_entry"] = lambda { |defi|
  s = "{ "
  s << "hfunc: #{"0x%016x" % defi["hfunc"]}"
  s << ', '
  s << "bytes: #{defi["bytes"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuFuncSetSharedSize_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuParamSetSize_entry"] = lambda { |defi|
  s = "{ "
  s << "hfunc: #{"0x%016x" % defi["hfunc"]}"
  s << ', '
  s << "numbytes: #{defi["numbytes"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuParamSetSize_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuParamSeti_entry"] = lambda { |defi|
  s = "{ "
  s << "hfunc: #{"0x%016x" % defi["hfunc"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuParamSeti_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuParamSetf_entry"] = lambda { |defi|
  s = "{ "
  s << "hfunc: #{"0x%016x" % defi["hfunc"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuParamSetf_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuParamSetv_entry"] = lambda { |defi|
  s = "{ "
  s << "hfunc: #{"0x%016x" % defi["hfunc"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "numbytes: #{defi["numbytes"]}"
  s << ', '
  s << "ptr_vals: #{defi["ptr_vals"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuParamSetv_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLaunch_entry"] = lambda { |defi|
  s = "{ "
  s << "f: #{"0x%016x" % defi["f"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLaunch_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLaunchGrid_entry"] = lambda { |defi|
  s = "{ "
  s << "f: #{"0x%016x" % defi["f"]}"
  s << ', '
  s << "grid_width: #{defi["grid_width"]}"
  s << ', '
  s << "grid_height: #{defi["grid_height"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLaunchGrid_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLaunchGridAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "f: #{"0x%016x" % defi["f"]}"
  s << ', '
  s << "grid_width: #{defi["grid_width"]}"
  s << ', '
  s << "grid_height: #{defi["grid_height"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLaunchGridAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuParamSetTexRef_entry"] = lambda { |defi|
  s = "{ "
  s << "hfunc: #{"0x%016x" % defi["hfunc"]}"
  s << ', '
  s << "texunit: #{defi["texunit"]}"
  s << ', '
  s << "hTexRef: #{"0x%016x" % defi["hTexRef"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuParamSetTexRef_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuFuncSetSharedMemConfig_entry"] = lambda { |defi|
  s = "{ "
  s << "hfunc: #{"0x%016x" % defi["hfunc"]}"
  s << ', '
  s << "config: #{CUDA::CUSharedconfig.from_native(defi["config"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuFuncSetSharedMemConfig_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "phGraph: #{"0x%016x" % defi["phGraph"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phGraph_val: #{"0x%016x" % defi["phGraph_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphAddKernelNode_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "phGraphNode: #{"0x%016x" % defi["phGraphNode"]}"
  s << ', '
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "dependencies: #{"0x%016x" % defi["dependencies"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "nodeParams: #{"0x%016x" % defi["nodeParams"]}"
  s << ', '
  s << "dependencies_vals: [ #{defi["dependencies_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "nodeParams_val: #{defi["nodeParams_val"].size > 0 ? CUDA::CUDAKERNELNODEPARAMSV2.new(FFI::MemoryPointer.from_string(defi["nodeParams_val"])) : nil}"
  s << ', '
  s << "nodeParams__extra_vals: [ #{defi["nodeParams__extra_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphAddKernelNode_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phGraphNode_val: #{"0x%016x" % defi["phGraphNode_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphKernelNodeGetParams_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "nodeParams: #{"0x%016x" % defi["nodeParams"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphKernelNodeGetParams_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "nodeParams_val: #{defi["nodeParams_val"].size > 0 ? CUDA::CUDAKERNELNODEPARAMSV2.new(FFI::MemoryPointer.from_string(defi["nodeParams_val"])) : nil}"
  s << ', '
  s << "nodeParams__extra_vals: [ #{defi["nodeParams__extra_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphKernelNodeSetParams_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "nodeParams: #{"0x%016x" % defi["nodeParams"]}"
  s << ', '
  s << "nodeParams_val: #{defi["nodeParams_val"].size > 0 ? CUDA::CUDAKERNELNODEPARAMSV2.new(FFI::MemoryPointer.from_string(defi["nodeParams_val"])) : nil}"
  s << ', '
  s << "nodeParams__extra_vals: [ #{defi["nodeParams__extra_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphKernelNodeSetParams_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphAddMemcpyNode_entry"] = lambda { |defi|
  s = "{ "
  s << "phGraphNode: #{"0x%016x" % defi["phGraphNode"]}"
  s << ', '
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "dependencies: #{"0x%016x" % defi["dependencies"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "copyParams: #{"0x%016x" % defi["copyParams"]}"
  s << ', '
  s << "ctx: #{"0x%016x" % defi["ctx"]}"
  s << ', '
  s << "dependencies_vals: [ #{defi["dependencies_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "copyParams_val: #{defi["copyParams_val"].size > 0 ? CUDA::CUDAMEMCPY3DV2.new(FFI::MemoryPointer.from_string(defi["copyParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphAddMemcpyNode_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phGraphNode_val: #{"0x%016x" % defi["phGraphNode_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphMemcpyNodeGetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "nodeParams: #{"0x%016x" % defi["nodeParams"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphMemcpyNodeGetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "nodeParams_val: #{defi["nodeParams_val"].size > 0 ? CUDA::CUDAMEMCPY3DV2.new(FFI::MemoryPointer.from_string(defi["nodeParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphMemcpyNodeSetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "nodeParams: #{"0x%016x" % defi["nodeParams"]}"
  s << ', '
  s << "nodeParams_val: #{defi["nodeParams_val"].size > 0 ? CUDA::CUDAMEMCPY3DV2.new(FFI::MemoryPointer.from_string(defi["nodeParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphMemcpyNodeSetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphAddMemsetNode_entry"] = lambda { |defi|
  s = "{ "
  s << "phGraphNode: #{"0x%016x" % defi["phGraphNode"]}"
  s << ', '
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "dependencies: #{"0x%016x" % defi["dependencies"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "memsetParams: #{"0x%016x" % defi["memsetParams"]}"
  s << ', '
  s << "ctx: #{"0x%016x" % defi["ctx"]}"
  s << ', '
  s << "dependencies_vals: [ #{defi["dependencies_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "memsetParams_val: #{defi["memsetParams_val"].size > 0 ? CUDA::CUDAMEMSETNODEPARAMSV1.new(FFI::MemoryPointer.from_string(defi["memsetParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphAddMemsetNode_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phGraphNode_val: #{"0x%016x" % defi["phGraphNode_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphMemsetNodeGetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "nodeParams: #{"0x%016x" % defi["nodeParams"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphMemsetNodeGetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "nodeParams_val: #{defi["nodeParams_val"].size > 0 ? CUDA::CUDAMEMSETNODEPARAMSV1.new(FFI::MemoryPointer.from_string(defi["nodeParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphMemsetNodeSetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "nodeParams: #{"0x%016x" % defi["nodeParams"]}"
  s << ', '
  s << "nodeParams_val: #{defi["nodeParams_val"].size > 0 ? CUDA::CUDAMEMSETNODEPARAMSV1.new(FFI::MemoryPointer.from_string(defi["nodeParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphMemsetNodeSetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphAddHostNode_entry"] = lambda { |defi|
  s = "{ "
  s << "phGraphNode: #{"0x%016x" % defi["phGraphNode"]}"
  s << ', '
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "dependencies: #{"0x%016x" % defi["dependencies"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "nodeParams: #{"0x%016x" % defi["nodeParams"]}"
  s << ', '
  s << "dependencies_vals: [ #{defi["dependencies_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "nodeParams_val: #{defi["nodeParams_val"].size > 0 ? CUDA::CUDAHOSTNODEPARAMSV1.new(FFI::MemoryPointer.from_string(defi["nodeParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphAddHostNode_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phGraphNode_val: #{"0x%016x" % defi["phGraphNode_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphHostNodeGetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "nodeParams: #{"0x%016x" % defi["nodeParams"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphHostNodeGetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "nodeParams_val: #{defi["nodeParams_val"].size > 0 ? CUDA::CUDAHOSTNODEPARAMSV1.new(FFI::MemoryPointer.from_string(defi["nodeParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphHostNodeSetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "nodeParams: #{"0x%016x" % defi["nodeParams"]}"
  s << ', '
  s << "nodeParams_val: #{defi["nodeParams_val"].size > 0 ? CUDA::CUDAHOSTNODEPARAMSV1.new(FFI::MemoryPointer.from_string(defi["nodeParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphHostNodeSetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphAddChildGraphNode_entry"] = lambda { |defi|
  s = "{ "
  s << "phGraphNode: #{"0x%016x" % defi["phGraphNode"]}"
  s << ', '
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "dependencies: #{"0x%016x" % defi["dependencies"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "childGraph: #{"0x%016x" % defi["childGraph"]}"
  s << ', '
  s << "dependencies_vals: [ #{defi["dependencies_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphAddChildGraphNode_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphChildGraphNodeGetGraph_entry"] = lambda { |defi|
  s = "{ "
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "phGraph: #{"0x%016x" % defi["phGraph"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphChildGraphNodeGetGraph_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phGraph_val: #{"0x%016x" % defi["phGraph_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphAddEmptyNode_entry"] = lambda { |defi|
  s = "{ "
  s << "phGraphNode: #{"0x%016x" % defi["phGraphNode"]}"
  s << ', '
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "dependencies: #{"0x%016x" % defi["dependencies"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "dependencies_vals: [ #{defi["dependencies_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphAddEmptyNode_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phGraphNode_val: #{"0x%016x" % defi["phGraphNode_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphAddEventRecordNode_entry"] = lambda { |defi|
  s = "{ "
  s << "phGraphNode: #{"0x%016x" % defi["phGraphNode"]}"
  s << ', '
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "dependencies: #{"0x%016x" % defi["dependencies"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "event: #{"0x%016x" % defi["event"]}"
  s << ', '
  s << "dependencies_vals: [ #{defi["dependencies_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphAddEventRecordNode_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phGraphNode_val: #{"0x%016x" % defi["phGraphNode_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphEventRecordNodeGetEvent_entry"] = lambda { |defi|
  s = "{ "
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "event_out: #{"0x%016x" % defi["event_out"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphEventRecordNodeGetEvent_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "event_out_val: #{"0x%016x" % defi["event_out_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphEventRecordNodeSetEvent_entry"] = lambda { |defi|
  s = "{ "
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "event: #{"0x%016x" % defi["event"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphEventRecordNodeSetEvent_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphAddEventWaitNode_entry"] = lambda { |defi|
  s = "{ "
  s << "phGraphNode: #{"0x%016x" % defi["phGraphNode"]}"
  s << ', '
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "dependencies: #{"0x%016x" % defi["dependencies"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "event: #{"0x%016x" % defi["event"]}"
  s << ', '
  s << "dependencies_vals: [ #{defi["dependencies_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphAddEventWaitNode_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phGraphNode_val: #{"0x%016x" % defi["phGraphNode_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphEventWaitNodeGetEvent_entry"] = lambda { |defi|
  s = "{ "
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "event_out: #{"0x%016x" % defi["event_out"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphEventWaitNodeGetEvent_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "event_out_val: #{"0x%016x" % defi["event_out_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphEventWaitNodeSetEvent_entry"] = lambda { |defi|
  s = "{ "
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "event: #{"0x%016x" % defi["event"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphEventWaitNodeSetEvent_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphAddExternalSemaphoresSignalNode_entry"] = lambda { |defi|
  s = "{ "
  s << "phGraphNode: #{"0x%016x" % defi["phGraphNode"]}"
  s << ', '
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "dependencies: #{"0x%016x" % defi["dependencies"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "nodeParams: #{"0x%016x" % defi["nodeParams"]}"
  s << ', '
  s << "dependencies_vals: [ #{defi["dependencies_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "nodeParams_val: #{defi["nodeParams_val"].size > 0 ? CUDA::CUDAEXTSEMSIGNALNODEPARAMSV1.new(FFI::MemoryPointer.from_string(defi["nodeParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphAddExternalSemaphoresSignalNode_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phGraphNode_val: #{"0x%016x" % defi["phGraphNode_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExternalSemaphoresSignalNodeGetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "params_out: #{"0x%016x" % defi["params_out"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExternalSemaphoresSignalNodeGetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "params_out_val: #{defi["params_out_val"].size > 0 ? CUDA::CUDAEXTSEMSIGNALNODEPARAMSV1.new(FFI::MemoryPointer.from_string(defi["params_out_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExternalSemaphoresSignalNodeSetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "nodeParams: #{"0x%016x" % defi["nodeParams"]}"
  s << ', '
  s << "nodeParams_val: #{defi["nodeParams_val"].size > 0 ? CUDA::CUDAEXTSEMSIGNALNODEPARAMSV1.new(FFI::MemoryPointer.from_string(defi["nodeParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExternalSemaphoresSignalNodeSetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphAddExternalSemaphoresWaitNode_entry"] = lambda { |defi|
  s = "{ "
  s << "phGraphNode: #{"0x%016x" % defi["phGraphNode"]}"
  s << ', '
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "dependencies: #{"0x%016x" % defi["dependencies"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "nodeParams: #{"0x%016x" % defi["nodeParams"]}"
  s << ', '
  s << "dependencies_vals: [ #{defi["dependencies_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "nodeParams_val: #{defi["nodeParams_val"].size > 0 ? CUDA::CUDAEXTSEMWAITNODEPARAMSV1.new(FFI::MemoryPointer.from_string(defi["nodeParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphAddExternalSemaphoresWaitNode_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phGraphNode_val: #{"0x%016x" % defi["phGraphNode_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExternalSemaphoresWaitNodeGetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "params_out: #{"0x%016x" % defi["params_out"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExternalSemaphoresWaitNodeGetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "params_out_val: #{defi["params_out_val"].size > 0 ? CUDA::CUDAEXTSEMWAITNODEPARAMSV1.new(FFI::MemoryPointer.from_string(defi["params_out_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExternalSemaphoresWaitNodeSetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "nodeParams: #{"0x%016x" % defi["nodeParams"]}"
  s << ', '
  s << "nodeParams_val: #{defi["nodeParams_val"].size > 0 ? CUDA::CUDAEXTSEMWAITNODEPARAMSV1.new(FFI::MemoryPointer.from_string(defi["nodeParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExternalSemaphoresWaitNodeSetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphAddBatchMemOpNode_entry"] = lambda { |defi|
  s = "{ "
  s << "phGraphNode: #{"0x%016x" % defi["phGraphNode"]}"
  s << ', '
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "dependencies: #{"0x%016x" % defi["dependencies"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "nodeParams: #{"0x%016x" % defi["nodeParams"]}"
  s << ', '
  s << "dependencies_vals: [ #{defi["dependencies_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "nodeParams_val: #{defi["nodeParams_val"].size > 0 ? CUDA::CUDABATCHMEMOPNODEPARAMSV1.new(FFI::MemoryPointer.from_string(defi["nodeParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphAddBatchMemOpNode_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phGraphNode_val: #{"0x%016x" % defi["phGraphNode_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphBatchMemOpNodeGetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "nodeParams_out: #{"0x%016x" % defi["nodeParams_out"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphBatchMemOpNodeGetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "nodeParams_out_val: #{defi["nodeParams_out_val"].size > 0 ? CUDA::CUDABATCHMEMOPNODEPARAMSV1.new(FFI::MemoryPointer.from_string(defi["nodeParams_out_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphBatchMemOpNodeSetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "nodeParams: #{"0x%016x" % defi["nodeParams"]}"
  s << ', '
  s << "nodeParams_val: #{defi["nodeParams_val"].size > 0 ? CUDA::CUDABATCHMEMOPNODEPARAMSV1.new(FFI::MemoryPointer.from_string(defi["nodeParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphBatchMemOpNodeSetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExecBatchMemOpNodeSetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraphExec: #{"0x%016x" % defi["hGraphExec"]}"
  s << ', '
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "nodeParams: #{"0x%016x" % defi["nodeParams"]}"
  s << ', '
  s << "nodeParams_val: #{defi["nodeParams_val"].size > 0 ? CUDA::CUDABATCHMEMOPNODEPARAMSV1.new(FFI::MemoryPointer.from_string(defi["nodeParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExecBatchMemOpNodeSetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphAddMemAllocNode_entry"] = lambda { |defi|
  s = "{ "
  s << "phGraphNode: #{"0x%016x" % defi["phGraphNode"]}"
  s << ', '
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "dependencies: #{"0x%016x" % defi["dependencies"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "nodeParams: #{"0x%016x" % defi["nodeParams"]}"
  s << ', '
  s << "dependencies_vals: [ #{defi["dependencies_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "nodeParams_val: #{defi["nodeParams_val"].size > 0 ? CUDA::CUDAMEMALLOCNODEPARAMSV1.new(FFI::MemoryPointer.from_string(defi["nodeParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphAddMemAllocNode_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phGraphNode_val: #{"0x%016x" % defi["phGraphNode_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphMemAllocNodeGetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "params_out: #{"0x%016x" % defi["params_out"]}"
  s << ', '
  s << "params_out_val: #{defi["params_out_val"].size > 0 ? CUDA::CUDAMEMALLOCNODEPARAMSV1.new(FFI::MemoryPointer.from_string(defi["params_out_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphMemAllocNodeGetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphAddMemFreeNode_entry"] = lambda { |defi|
  s = "{ "
  s << "phGraphNode: #{"0x%016x" % defi["phGraphNode"]}"
  s << ', '
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "dependencies: #{"0x%016x" % defi["dependencies"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "dptr: #{"0x%016x" % defi["dptr"]}"
  s << ', '
  s << "dependencies_vals: [ #{defi["dependencies_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphAddMemFreeNode_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phGraphNode_val: #{"0x%016x" % defi["phGraphNode_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphMemFreeNodeGetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "dptr_out: #{"0x%016x" % defi["dptr_out"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphMemFreeNodeGetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "dptr_out_val: #{"0x%016x" % defi["dptr_out_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGraphMemTrim_entry"] = lambda { |defi|
  s = "{ "
  s << "device: #{defi["device"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGraphMemTrim_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetGraphMemAttribute_entry"] = lambda { |defi|
  s = "{ "
  s << "device: #{defi["device"]}"
  s << ', '
  s << "attr: #{CUDA::CUGraphMemAttribute.from_native(defi["attr"], nil)}"
  s << ', '
  s << "value: #{"0x%016x" % defi["value"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetGraphMemAttribute_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "value_val: #{defi["value_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceSetGraphMemAttribute_entry"] = lambda { |defi|
  s = "{ "
  s << "device: #{defi["device"]}"
  s << ', '
  s << "attr: #{CUDA::CUGraphMemAttribute.from_native(defi["attr"], nil)}"
  s << ', '
  s << "value: #{"0x%016x" % defi["value"]}"
  s << ', '
  s << "value_val: #{defi["value_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceSetGraphMemAttribute_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphClone_entry"] = lambda { |defi|
  s = "{ "
  s << "phGraphClone: #{"0x%016x" % defi["phGraphClone"]}"
  s << ', '
  s << "originalGraph: #{"0x%016x" % defi["originalGraph"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphClone_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phGraphClone_val: #{"0x%016x" % defi["phGraphClone_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphNodeFindInClone_entry"] = lambda { |defi|
  s = "{ "
  s << "phNode: #{"0x%016x" % defi["phNode"]}"
  s << ', '
  s << "hOriginalNode: #{"0x%016x" % defi["hOriginalNode"]}"
  s << ', '
  s << "hClonedGraph: #{"0x%016x" % defi["hClonedGraph"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphNodeFindInClone_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phNode_val: #{"0x%016x" % defi["phNode_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphNodeGetType_entry"] = lambda { |defi|
  s = "{ "
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "type: #{"0x%016x" % defi["type"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphNodeGetType_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "type_val: #{CUDA::CUGraphNodeType.from_native(defi["type_val"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphGetNodes_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "nodes: #{"0x%016x" % defi["nodes"]}"
  s << ', '
  s << "numNodes: #{"0x%016x" % defi["numNodes"]}"
  s << ', '
  s << "numNodes_val: #{defi["numNodes_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphGetNodes_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "numNodes_val: #{defi["numNodes_val"]}"
  s << ', '
  s << "nodes_vals: [ #{defi["nodes_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphGetRootNodes_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "rootNodes: #{"0x%016x" % defi["rootNodes"]}"
  s << ', '
  s << "numRootNodes: #{"0x%016x" % defi["numRootNodes"]}"
  s << ', '
  s << "numRootNodes_val: #{defi["numRootNodes_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphGetRootNodes_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "numRootNodes_val: #{defi["numRootNodes_val"]}"
  s << ', '
  s << "rootNodes_vals: [ #{defi["rootNodes_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphGetEdges_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "from: #{"0x%016x" % defi["from"]}"
  s << ', '
  s << "to: #{"0x%016x" % defi["to"]}"
  s << ', '
  s << "edgeData: #{"0x%016x" % defi["edgeData"]}"
  s << ', '
  s << "numEdges: #{"0x%016x" % defi["numEdges"]}"
  s << ', '
  s << "numEdges_val: #{defi["numEdges_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphGetEdges_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "numEdges_val: #{defi["numEdges_val"]}"
  s << ', '
  s << "from_vals: [ #{defi["from_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "to_vals: [ #{defi["to_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "edgeData_vals: [ #{p = FFI::MemoryPointer.from_string(defi["edgeData_vals"]); sz = CUDA::CUGraphEdgeData.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUGraphEdgeData.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphNodeGetDependencies_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "dependencies: #{"0x%016x" % defi["dependencies"]}"
  s << ', '
  s << "edgeData: #{"0x%016x" % defi["edgeData"]}"
  s << ', '
  s << "numDependencies: #{"0x%016x" % defi["numDependencies"]}"
  s << ', '
  s << "numDependencies_val: #{defi["numDependencies_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphNodeGetDependencies_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "numDependencies_val: #{defi["numDependencies_val"]}"
  s << ', '
  s << "dependencies_vals: [ #{defi["dependencies_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "edgeData_vals: [ #{p = FFI::MemoryPointer.from_string(defi["edgeData_vals"]); sz = CUDA::CUGraphEdgeData.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUGraphEdgeData.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphNodeGetDependentNodes_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "dependentNodes: #{"0x%016x" % defi["dependentNodes"]}"
  s << ', '
  s << "edgeData: #{"0x%016x" % defi["edgeData"]}"
  s << ', '
  s << "numDependentNodes: #{"0x%016x" % defi["numDependentNodes"]}"
  s << ', '
  s << "numDependentNodes_val: #{defi["numDependentNodes_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphNodeGetDependentNodes_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "numDependentNodes_val: #{defi["numDependentNodes_val"]}"
  s << ', '
  s << "dependentNodes_vals: [ #{defi["dependentNodes_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "edgeData_vals: [ #{p = FFI::MemoryPointer.from_string(defi["edgeData_vals"]); sz = CUDA::CUGraphEdgeData.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUGraphEdgeData.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphAddDependencies_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "from: #{"0x%016x" % defi["from"]}"
  s << ', '
  s << "to: #{"0x%016x" % defi["to"]}"
  s << ', '
  s << "edgeData: #{"0x%016x" % defi["edgeData"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "from_vals: [ #{defi["from_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "to_vals: [ #{defi["to_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "edgeData_vals: [ #{p = FFI::MemoryPointer.from_string(defi["edgeData_vals"]); sz = CUDA::CUGraphEdgeData.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUGraphEdgeData.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphAddDependencies_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphRemoveDependencies_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "from: #{"0x%016x" % defi["from"]}"
  s << ', '
  s << "to: #{"0x%016x" % defi["to"]}"
  s << ', '
  s << "edgeData: #{"0x%016x" % defi["edgeData"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "from_vals: [ #{defi["from_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "to_vals: [ #{defi["to_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "edgeData_vals: [ #{p = FFI::MemoryPointer.from_string(defi["edgeData_vals"]); sz = CUDA::CUGraphEdgeData.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUGraphEdgeData.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphRemoveDependencies_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphDestroyNode_entry"] = lambda { |defi|
  s = "{ "
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphDestroyNode_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphInstantiateWithFlags_entry"] = lambda { |defi|
  s = "{ "
  s << "phGraphExec: #{"0x%016x" % defi["phGraphExec"]}"
  s << ', '
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphInstantiateWithFlags_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phGraphExec_val: #{"0x%016x" % defi["phGraphExec_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphInstantiateWithParams_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "phGraphExec: #{"0x%016x" % defi["phGraphExec"]}"
  s << ', '
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "instantiateParams: #{"0x%016x" % defi["instantiateParams"]}"
  s << ', '
  s << "instantiateParams_val: #{defi["instantiateParams_val"].size > 0 ? CUDA::CUDAGRAPHINSTANTIATEPARAMS.new(FFI::MemoryPointer.from_string(defi["instantiateParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphInstantiateWithParams_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phGraphExec_val: #{"0x%016x" % defi["phGraphExec_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExecGetFlags_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraphExec: #{"0x%016x" % defi["hGraphExec"]}"
  s << ', '
  s << "flags: #{"0x%016x" % defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExecGetFlags_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "flags_val: #{defi["flags_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExecKernelNodeSetParams_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraphExec: #{"0x%016x" % defi["hGraphExec"]}"
  s << ', '
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "nodeParams: #{"0x%016x" % defi["nodeParams"]}"
  s << ', '
  s << "nodeParams_val: #{defi["nodeParams_val"].size > 0 ? CUDA::CUDAKERNELNODEPARAMSV2.new(FFI::MemoryPointer.from_string(defi["nodeParams_val"])) : nil}"
  s << ', '
  s << "nodeParams__extra_vals: [ #{defi["nodeParams__extra_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExecKernelNodeSetParams_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExecMemcpyNodeSetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraphExec: #{"0x%016x" % defi["hGraphExec"]}"
  s << ', '
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "copyParams: #{"0x%016x" % defi["copyParams"]}"
  s << ', '
  s << "ctx: #{"0x%016x" % defi["ctx"]}"
  s << ', '
  s << "copyParams_val: #{defi["copyParams_val"].size > 0 ? CUDA::CUDAMEMCPY3DV2.new(FFI::MemoryPointer.from_string(defi["copyParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExecMemcpyNodeSetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExecMemsetNodeSetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraphExec: #{"0x%016x" % defi["hGraphExec"]}"
  s << ', '
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "memsetParams: #{"0x%016x" % defi["memsetParams"]}"
  s << ', '
  s << "ctx: #{"0x%016x" % defi["ctx"]}"
  s << ', '
  s << "memsetParams_val: #{defi["memsetParams_val"].size > 0 ? CUDA::CUDAMEMSETNODEPARAMSV1.new(FFI::MemoryPointer.from_string(defi["memsetParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExecMemsetNodeSetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExecHostNodeSetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraphExec: #{"0x%016x" % defi["hGraphExec"]}"
  s << ', '
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "nodeParams: #{"0x%016x" % defi["nodeParams"]}"
  s << ', '
  s << "nodeParams_val: #{defi["nodeParams_val"].size > 0 ? CUDA::CUDAHOSTNODEPARAMSV1.new(FFI::MemoryPointer.from_string(defi["nodeParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExecHostNodeSetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExecChildGraphNodeSetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraphExec: #{"0x%016x" % defi["hGraphExec"]}"
  s << ', '
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "childGraph: #{"0x%016x" % defi["childGraph"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExecChildGraphNodeSetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExecEventRecordNodeSetEvent_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraphExec: #{"0x%016x" % defi["hGraphExec"]}"
  s << ', '
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "event: #{"0x%016x" % defi["event"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExecEventRecordNodeSetEvent_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExecEventWaitNodeSetEvent_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraphExec: #{"0x%016x" % defi["hGraphExec"]}"
  s << ', '
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "event: #{"0x%016x" % defi["event"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExecEventWaitNodeSetEvent_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExecExternalSemaphoresSignalNodeSetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraphExec: #{"0x%016x" % defi["hGraphExec"]}"
  s << ', '
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "nodeParams: #{"0x%016x" % defi["nodeParams"]}"
  s << ', '
  s << "nodeParams_val: #{defi["nodeParams_val"].size > 0 ? CUDA::CUDAEXTSEMSIGNALNODEPARAMSV1.new(FFI::MemoryPointer.from_string(defi["nodeParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExecExternalSemaphoresSignalNodeSetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExecExternalSemaphoresWaitNodeSetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraphExec: #{"0x%016x" % defi["hGraphExec"]}"
  s << ', '
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "nodeParams: #{"0x%016x" % defi["nodeParams"]}"
  s << ', '
  s << "nodeParams_val: #{defi["nodeParams_val"].size > 0 ? CUDA::CUDAEXTSEMWAITNODEPARAMSV1.new(FFI::MemoryPointer.from_string(defi["nodeParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExecExternalSemaphoresWaitNodeSetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphNodeSetEnabled_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraphExec: #{"0x%016x" % defi["hGraphExec"]}"
  s << ', '
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "isEnabled: #{defi["isEnabled"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphNodeSetEnabled_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphNodeGetEnabled_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraphExec: #{"0x%016x" % defi["hGraphExec"]}"
  s << ', '
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "isEnabled: #{"0x%016x" % defi["isEnabled"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphNodeGetEnabled_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "isEnabled_val: #{defi["isEnabled_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphUpload_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraphExec: #{"0x%016x" % defi["hGraphExec"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphUpload_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphLaunch_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraphExec: #{"0x%016x" % defi["hGraphExec"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphLaunch_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExecDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraphExec: #{"0x%016x" % defi["hGraphExec"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExecDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExecUpdate_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraphExec: #{"0x%016x" % defi["hGraphExec"]}"
  s << ', '
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "resultInfo: #{"0x%016x" % defi["resultInfo"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExecUpdate_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "resultInfo_val: #{defi["resultInfo_val"].size > 0 ? CUDA::CUGraphExecUpdateResultInfoV1.new(FFI::MemoryPointer.from_string(defi["resultInfo_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphKernelNodeCopyAttributes_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphKernelNodeCopyAttributes_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphKernelNodeGetAttribute_entry"] = lambda { |defi|
  s = "{ "
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "attr: #{defi["attr"]}"
  s << ', '
  s << "value_out: #{"0x%016x" % defi["value_out"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphKernelNodeGetAttribute_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "value_out_val: #{defi["value_out_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphKernelNodeSetAttribute_entry"] = lambda { |defi|
  s = "{ "
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "attr: #{defi["attr"]}"
  s << ', '
  s << "value: #{"0x%016x" % defi["value"]}"
  s << ', '
  s << "value_val: #{defi["value_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphKernelNodeSetAttribute_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphDebugDotPrint_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "path: #{"0x%016x" % defi["path"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "path_val: #{defi["path_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphDebugDotPrint_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuUserObjectCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "object_out: #{"0x%016x" % defi["object_out"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "destroy: #{"0x%016x" % defi["destroy"]}"
  s << ', '
  s << "initialRefcount: #{defi["initialRefcount"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuUserObjectCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "object_out_val: #{"0x%016x" % defi["object_out_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuUserObjectRetain_entry"] = lambda { |defi|
  s = "{ "
  s << "object: #{"0x%016x" % defi["object"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuUserObjectRetain_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuUserObjectRelease_entry"] = lambda { |defi|
  s = "{ "
  s << "object: #{"0x%016x" % defi["object"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuUserObjectRelease_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphRetainUserObject_entry"] = lambda { |defi|
  s = "{ "
  s << "graph: #{"0x%016x" % defi["graph"]}"
  s << ', '
  s << "object: #{"0x%016x" % defi["object"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphRetainUserObject_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphReleaseUserObject_entry"] = lambda { |defi|
  s = "{ "
  s << "graph: #{"0x%016x" % defi["graph"]}"
  s << ', '
  s << "object: #{"0x%016x" % defi["object"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphReleaseUserObject_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphAddNode_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "phGraphNode: #{"0x%016x" % defi["phGraphNode"]}"
  s << ', '
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "dependencies: #{"0x%016x" % defi["dependencies"]}"
  s << ', '
  s << "dependencyData: #{"0x%016x" % defi["dependencyData"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "nodeParams: #{"0x%016x" % defi["nodeParams"]}"
  s << ', '
  s << "dependencies_vals: [ #{defi["dependencies_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "dependencyData_vals: [ #{p = FFI::MemoryPointer.from_string(defi["dependencyData_vals"]); sz = CUDA::CUGraphEdgeData.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUGraphEdgeData.new(p + i*sz).to_s}.join(", ")} ]"
  s << ', '
  s << "nodeParams_val: #{defi["nodeParams_val"].size > 0 ? CUDA::CUGraphNodeParams.new(FFI::MemoryPointer.from_string(defi["nodeParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphAddNode_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phGraphNode_val: #{"0x%016x" % defi["phGraphNode_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphNodeSetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "nodeParams: #{"0x%016x" % defi["nodeParams"]}"
  s << ', '
  s << "nodeParams_val: #{defi["nodeParams_val"].size > 0 ? CUDA::CUGraphNodeParams.new(FFI::MemoryPointer.from_string(defi["nodeParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphNodeSetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExecNodeSetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraphExec: #{"0x%016x" % defi["hGraphExec"]}"
  s << ', '
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "nodeParams: #{"0x%016x" % defi["nodeParams"]}"
  s << ', '
  s << "nodeParams_val: #{defi["nodeParams_val"].size > 0 ? CUDA::CUGraphNodeParams.new(FFI::MemoryPointer.from_string(defi["nodeParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExecNodeSetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphConditionalHandleCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "pHandle_out: #{"0x%016x" % defi["pHandle_out"]}"
  s << ', '
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "ctx: #{"0x%016x" % defi["ctx"]}"
  s << ', '
  s << "defaultLaunchValue: #{defi["defaultLaunchValue"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphConditionalHandleCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pHandle_out_val: #{defi["pHandle_out_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuOccupancyMaxActiveBlocksPerMultiprocessor_entry"] = lambda { |defi|
  s = "{ "
  s << "numBlocks: #{"0x%016x" % defi["numBlocks"]}"
  s << ', '
  s << "func: #{"0x%016x" % defi["func"]}"
  s << ', '
  s << "blockSize: #{defi["blockSize"]}"
  s << ', '
  s << "dynamicSMemSize: #{defi["dynamicSMemSize"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuOccupancyMaxActiveBlocksPerMultiprocessor_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "numBlocks_val: #{defi["numBlocks_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_entry"] = lambda { |defi|
  s = "{ "
  s << "numBlocks: #{"0x%016x" % defi["numBlocks"]}"
  s << ', '
  s << "func: #{"0x%016x" % defi["func"]}"
  s << ', '
  s << "blockSize: #{defi["blockSize"]}"
  s << ', '
  s << "dynamicSMemSize: #{defi["dynamicSMemSize"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "numBlocks_val: #{defi["numBlocks_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuOccupancyMaxPotentialBlockSize_entry"] = lambda { |defi|
  s = "{ "
  s << "minGridSize: #{"0x%016x" % defi["minGridSize"]}"
  s << ', '
  s << "blockSize: #{"0x%016x" % defi["blockSize"]}"
  s << ', '
  s << "func: #{"0x%016x" % defi["func"]}"
  s << ', '
  s << "blockSizeToDynamicSMemSize: #{"0x%016x" % defi["blockSizeToDynamicSMemSize"]}"
  s << ', '
  s << "dynamicSMemSize: #{defi["dynamicSMemSize"]}"
  s << ', '
  s << "blockSizeLimit: #{defi["blockSizeLimit"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuOccupancyMaxPotentialBlockSize_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "minGridSize_val: #{defi["minGridSize_val"]}"
  s << ', '
  s << "blockSize_val: #{defi["blockSize_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuOccupancyMaxPotentialBlockSizeWithFlags_entry"] = lambda { |defi|
  s = "{ "
  s << "minGridSize: #{"0x%016x" % defi["minGridSize"]}"
  s << ', '
  s << "blockSize: #{"0x%016x" % defi["blockSize"]}"
  s << ', '
  s << "func: #{"0x%016x" % defi["func"]}"
  s << ', '
  s << "blockSizeToDynamicSMemSize: #{"0x%016x" % defi["blockSizeToDynamicSMemSize"]}"
  s << ', '
  s << "dynamicSMemSize: #{defi["dynamicSMemSize"]}"
  s << ', '
  s << "blockSizeLimit: #{defi["blockSizeLimit"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuOccupancyMaxPotentialBlockSizeWithFlags_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "minGridSize_val: #{defi["minGridSize_val"]}"
  s << ', '
  s << "blockSize_val: #{defi["blockSize_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuOccupancyAvailableDynamicSMemPerBlock_entry"] = lambda { |defi|
  s = "{ "
  s << "dynamicSmemSize: #{"0x%016x" % defi["dynamicSmemSize"]}"
  s << ', '
  s << "func: #{"0x%016x" % defi["func"]}"
  s << ', '
  s << "numBlocks: #{defi["numBlocks"]}"
  s << ', '
  s << "blockSize: #{defi["blockSize"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuOccupancyAvailableDynamicSMemPerBlock_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "dynamicSmemSize_val: #{defi["dynamicSmemSize_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuOccupancyMaxPotentialClusterSize_entry"] = lambda { |defi|
  s = "{ "
  s << "clusterSize: #{"0x%016x" % defi["clusterSize"]}"
  s << ', '
  s << "func: #{"0x%016x" % defi["func"]}"
  s << ', '
  s << "config: #{"0x%016x" % defi["config"]}"
  s << ', '
  s << "config_val: #{defi["config_val"].size > 0 ? CUDA::CULaunchConfig.new(FFI::MemoryPointer.from_string(defi["config_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuOccupancyMaxPotentialClusterSize_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "clusterSize_val: #{defi["clusterSize_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuOccupancyMaxActiveClusters_entry"] = lambda { |defi|
  s = "{ "
  s << "numClusters: #{"0x%016x" % defi["numClusters"]}"
  s << ', '
  s << "func: #{"0x%016x" % defi["func"]}"
  s << ', '
  s << "config: #{"0x%016x" % defi["config"]}"
  s << ', '
  s << "config_val: #{defi["config_val"].size > 0 ? CUDA::CULaunchConfig.new(FFI::MemoryPointer.from_string(defi["config_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuOccupancyMaxActiveClusters_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "numClusters_val: #{defi["numClusters_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefSetArray_entry"] = lambda { |defi|
  s = "{ "
  s << "hTexRef: #{"0x%016x" % defi["hTexRef"]}"
  s << ', '
  s << "hArray: #{"0x%016x" % defi["hArray"]}"
  s << ', '
  s << "Flags: #{defi["Flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefSetArray_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefSetMipmappedArray_entry"] = lambda { |defi|
  s = "{ "
  s << "hTexRef: #{"0x%016x" % defi["hTexRef"]}"
  s << ', '
  s << "hMipmappedArray: #{"0x%016x" % defi["hMipmappedArray"]}"
  s << ', '
  s << "Flags: #{defi["Flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefSetMipmappedArray_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefSetAddress_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "ByteOffset: #{"0x%016x" % defi["ByteOffset"]}"
  s << ', '
  s << "hTexRef: #{"0x%016x" % defi["hTexRef"]}"
  s << ', '
  s << "dptr: #{"0x%016x" % defi["dptr"]}"
  s << ', '
  s << "bytes: #{defi["bytes"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefSetAddress_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefSetAddress2D_v3_entry"] = lambda { |defi|
  s = "{ "
  s << "hTexRef: #{"0x%016x" % defi["hTexRef"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "dptr: #{"0x%016x" % defi["dptr"]}"
  s << ', '
  s << "Pitch: #{defi["Pitch"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefSetAddress2D_v3_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefSetFormat_entry"] = lambda { |defi|
  s = "{ "
  s << "hTexRef: #{"0x%016x" % defi["hTexRef"]}"
  s << ', '
  s << "fmt: #{CUDA::CUArrayFormat.from_native(defi["fmt"], nil)}"
  s << ', '
  s << "NumPackedComponents: #{defi["NumPackedComponents"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefSetFormat_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefSetAddressMode_entry"] = lambda { |defi|
  s = "{ "
  s << "hTexRef: #{"0x%016x" % defi["hTexRef"]}"
  s << ', '
  s << "dim: #{defi["dim"]}"
  s << ', '
  s << "am: #{CUDA::CUAddressMode.from_native(defi["am"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefSetAddressMode_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefSetFilterMode_entry"] = lambda { |defi|
  s = "{ "
  s << "hTexRef: #{"0x%016x" % defi["hTexRef"]}"
  s << ', '
  s << "fm: #{CUDA::CUFilterMode.from_native(defi["fm"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefSetFilterMode_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefSetMipmapFilterMode_entry"] = lambda { |defi|
  s = "{ "
  s << "hTexRef: #{"0x%016x" % defi["hTexRef"]}"
  s << ', '
  s << "fm: #{CUDA::CUFilterMode.from_native(defi["fm"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefSetMipmapFilterMode_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefSetMipmapLevelBias_entry"] = lambda { |defi|
  s = "{ "
  s << "hTexRef: #{"0x%016x" % defi["hTexRef"]}"
  s << ', '
  s << "bias: #{defi["bias"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefSetMipmapLevelBias_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefSetMipmapLevelClamp_entry"] = lambda { |defi|
  s = "{ "
  s << "hTexRef: #{"0x%016x" % defi["hTexRef"]}"
  s << ', '
  s << "minMipmapLevelClamp: #{defi["minMipmapLevelClamp"]}"
  s << ', '
  s << "maxMipmapLevelClamp: #{defi["maxMipmapLevelClamp"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefSetMipmapLevelClamp_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefSetMaxAnisotropy_entry"] = lambda { |defi|
  s = "{ "
  s << "hTexRef: #{"0x%016x" % defi["hTexRef"]}"
  s << ', '
  s << "maxAniso: #{defi["maxAniso"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefSetMaxAnisotropy_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefSetBorderColor_entry"] = lambda { |defi|
  s = "{ "
  s << "hTexRef: #{"0x%016x" % defi["hTexRef"]}"
  s << ', '
  s << "pBorderColor: #{"0x%016x" % defi["pBorderColor"]}"
  s << ', '
  s << "pBorderColor_vals: [ #{defi["pBorderColor_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefSetBorderColor_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefSetFlags_entry"] = lambda { |defi|
  s = "{ "
  s << "hTexRef: #{"0x%016x" % defi["hTexRef"]}"
  s << ', '
  s << "Flags: #{defi["Flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefSetFlags_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefGetAddress_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "pdptr: #{"0x%016x" % defi["pdptr"]}"
  s << ', '
  s << "hTexRef: #{"0x%016x" % defi["hTexRef"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefGetAddress_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pdptr_val: #{"0x%016x" % defi["pdptr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefGetArray_entry"] = lambda { |defi|
  s = "{ "
  s << "phArray: #{"0x%016x" % defi["phArray"]}"
  s << ', '
  s << "hTexRef: #{"0x%016x" % defi["hTexRef"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefGetArray_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phArray_val: #{"0x%016x" % defi["phArray_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefGetMipmappedArray_entry"] = lambda { |defi|
  s = "{ "
  s << "phMipmappedArray: #{"0x%016x" % defi["phMipmappedArray"]}"
  s << ', '
  s << "hTexRef: #{"0x%016x" % defi["hTexRef"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefGetMipmappedArray_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phMipmappedArray_val: #{"0x%016x" % defi["phMipmappedArray_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefGetAddressMode_entry"] = lambda { |defi|
  s = "{ "
  s << "pam: #{"0x%016x" % defi["pam"]}"
  s << ', '
  s << "hTexRef: #{"0x%016x" % defi["hTexRef"]}"
  s << ', '
  s << "dim: #{defi["dim"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefGetAddressMode_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pam_val: #{CUDA::CUAddressMode.from_native(defi["pam_val"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefGetFilterMode_entry"] = lambda { |defi|
  s = "{ "
  s << "pfm: #{"0x%016x" % defi["pfm"]}"
  s << ', '
  s << "hTexRef: #{"0x%016x" % defi["hTexRef"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefGetFilterMode_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pfm_val: #{CUDA::CUFilterMode.from_native(defi["pfm_val"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefGetFormat_entry"] = lambda { |defi|
  s = "{ "
  s << "pFormat: #{"0x%016x" % defi["pFormat"]}"
  s << ', '
  s << "pNumChannels: #{"0x%016x" % defi["pNumChannels"]}"
  s << ', '
  s << "hTexRef: #{"0x%016x" % defi["hTexRef"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefGetFormat_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pFormat_val: #{CUDA::CUArrayFormat.from_native(defi["pFormat_val"], nil)}"
  s << ', '
  s << "pNumChannels_val: #{defi["pNumChannels_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefGetMipmapFilterMode_entry"] = lambda { |defi|
  s = "{ "
  s << "pfm: #{"0x%016x" % defi["pfm"]}"
  s << ', '
  s << "hTexRef: #{"0x%016x" % defi["hTexRef"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefGetMipmapFilterMode_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pfm_val: #{CUDA::CUFilterMode.from_native(defi["pfm_val"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefGetMipmapLevelBias_entry"] = lambda { |defi|
  s = "{ "
  s << "pbias: #{"0x%016x" % defi["pbias"]}"
  s << ', '
  s << "hTexRef: #{"0x%016x" % defi["hTexRef"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefGetMipmapLevelBias_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pbias_val: #{defi["pbias_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefGetMipmapLevelClamp_entry"] = lambda { |defi|
  s = "{ "
  s << "pminMipmapLevelClamp: #{"0x%016x" % defi["pminMipmapLevelClamp"]}"
  s << ', '
  s << "pmaxMipmapLevelClamp: #{"0x%016x" % defi["pmaxMipmapLevelClamp"]}"
  s << ', '
  s << "hTexRef: #{"0x%016x" % defi["hTexRef"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefGetMipmapLevelClamp_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pminMipmapLevelClamp_val: #{defi["pminMipmapLevelClamp_val"]}"
  s << ', '
  s << "pmaxMipmapLevelClamp_val: #{defi["pmaxMipmapLevelClamp_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefGetMaxAnisotropy_entry"] = lambda { |defi|
  s = "{ "
  s << "pmaxAniso: #{"0x%016x" % defi["pmaxAniso"]}"
  s << ', '
  s << "hTexRef: #{"0x%016x" % defi["hTexRef"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefGetMaxAnisotropy_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pmaxAniso_val: #{defi["pmaxAniso_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefGetBorderColor_entry"] = lambda { |defi|
  s = "{ "
  s << "pBorderColor: #{"0x%016x" % defi["pBorderColor"]}"
  s << ', '
  s << "hTexRef: #{"0x%016x" % defi["hTexRef"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefGetBorderColor_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pBorderColor_val: #{defi["pBorderColor_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefGetFlags_entry"] = lambda { |defi|
  s = "{ "
  s << "pFlags: #{"0x%016x" % defi["pFlags"]}"
  s << ', '
  s << "hTexRef: #{"0x%016x" % defi["hTexRef"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefGetFlags_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pFlags_val: #{defi["pFlags_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "pTexRef: #{"0x%016x" % defi["pTexRef"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pTexRef_val: #{"0x%016x" % defi["pTexRef_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "hTexRef: #{"0x%016x" % defi["hTexRef"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuSurfRefSetArray_entry"] = lambda { |defi|
  s = "{ "
  s << "hSurfRef: #{"0x%016x" % defi["hSurfRef"]}"
  s << ', '
  s << "hArray: #{"0x%016x" % defi["hArray"]}"
  s << ', '
  s << "Flags: #{defi["Flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuSurfRefSetArray_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuSurfRefGetArray_entry"] = lambda { |defi|
  s = "{ "
  s << "phArray: #{"0x%016x" % defi["phArray"]}"
  s << ', '
  s << "hSurfRef: #{"0x%016x" % defi["hSurfRef"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuSurfRefGetArray_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phArray_val: #{"0x%016x" % defi["phArray_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexObjectCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "pTexObject: #{"0x%016x" % defi["pTexObject"]}"
  s << ', '
  s << "pResDesc: #{"0x%016x" % defi["pResDesc"]}"
  s << ', '
  s << "pTexDesc: #{"0x%016x" % defi["pTexDesc"]}"
  s << ', '
  s << "pResViewDesc: #{"0x%016x" % defi["pResViewDesc"]}"
  s << ', '
  s << "pResDesc_val: #{defi["pResDesc_val"].size > 0 ? CUDA::CUDARESOURCEDESCV1.new(FFI::MemoryPointer.from_string(defi["pResDesc_val"])) : nil}"
  s << ', '
  s << "pTexDesc_val: #{defi["pTexDesc_val"].size > 0 ? CUDA::CUDATEXTUREDESCV1.new(FFI::MemoryPointer.from_string(defi["pTexDesc_val"])) : nil}"
  s << ', '
  s << "pResViewDesc_val: #{defi["pResViewDesc_val"].size > 0 ? CUDA::CUDARESOURCEVIEWDESCV1.new(FFI::MemoryPointer.from_string(defi["pResViewDesc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexObjectCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pTexObject_val: #{defi["pTexObject_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexObjectDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "texObject: #{defi["texObject"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexObjectDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexObjectGetResourceDesc_entry"] = lambda { |defi|
  s = "{ "
  s << "pResDesc: #{"0x%016x" % defi["pResDesc"]}"
  s << ', '
  s << "texObject: #{defi["texObject"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexObjectGetResourceDesc_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pResDesc_val: #{defi["pResDesc_val"].size > 0 ? CUDA::CUDARESOURCEDESCV1.new(FFI::MemoryPointer.from_string(defi["pResDesc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexObjectGetTextureDesc_entry"] = lambda { |defi|
  s = "{ "
  s << "pTexDesc: #{"0x%016x" % defi["pTexDesc"]}"
  s << ', '
  s << "texObject: #{defi["texObject"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexObjectGetTextureDesc_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pTexDesc_val: #{defi["pTexDesc_val"].size > 0 ? CUDA::CUDATEXTUREDESCV1.new(FFI::MemoryPointer.from_string(defi["pTexDesc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexObjectGetResourceViewDesc_entry"] = lambda { |defi|
  s = "{ "
  s << "pResViewDesc: #{"0x%016x" % defi["pResViewDesc"]}"
  s << ', '
  s << "texObject: #{defi["texObject"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexObjectGetResourceViewDesc_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pResViewDesc_val: #{defi["pResViewDesc_val"].size > 0 ? CUDA::CUDARESOURCEVIEWDESCV1.new(FFI::MemoryPointer.from_string(defi["pResViewDesc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuSurfObjectCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "pSurfObject: #{"0x%016x" % defi["pSurfObject"]}"
  s << ', '
  s << "pResDesc: #{"0x%016x" % defi["pResDesc"]}"
  s << ', '
  s << "pResDesc_val: #{defi["pResDesc_val"].size > 0 ? CUDA::CUDARESOURCEDESCV1.new(FFI::MemoryPointer.from_string(defi["pResDesc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuSurfObjectCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pSurfObject_val: #{defi["pSurfObject_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuSurfObjectDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "surfObject: #{defi["surfObject"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuSurfObjectDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuSurfObjectGetResourceDesc_entry"] = lambda { |defi|
  s = "{ "
  s << "pResDesc: #{"0x%016x" % defi["pResDesc"]}"
  s << ', '
  s << "surfObject: #{defi["surfObject"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuSurfObjectGetResourceDesc_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pResDesc_val: #{defi["pResDesc_val"].size > 0 ? CUDA::CUDARESOURCEDESCV1.new(FFI::MemoryPointer.from_string(defi["pResDesc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTensorMapEncodeTiled_entry"] = lambda { |defi|
  s = "{ "
  s << "tensorMap: #{"0x%016x" % defi["tensorMap"]}"
  s << ', '
  s << "tensorDataType: #{CUDA::CUTensorMapDataType.from_native(defi["tensorDataType"], nil)}"
  s << ', '
  s << "tensorRank: #{defi["tensorRank"]}"
  s << ', '
  s << "globalAddress: #{"0x%016x" % defi["globalAddress"]}"
  s << ', '
  s << "globalDim: #{"0x%016x" % defi["globalDim"]}"
  s << ', '
  s << "globalStrides: #{"0x%016x" % defi["globalStrides"]}"
  s << ', '
  s << "boxDim: #{"0x%016x" % defi["boxDim"]}"
  s << ', '
  s << "elementStrides: #{"0x%016x" % defi["elementStrides"]}"
  s << ', '
  s << "interleave: #{CUDA::CUTensorMapInterleave.from_native(defi["interleave"], nil)}"
  s << ', '
  s << "swizzle: #{CUDA::CUTensorMapSwizzle.from_native(defi["swizzle"], nil)}"
  s << ', '
  s << "l2Promotion: #{CUDA::CUTensorMapL2promotion.from_native(defi["l2Promotion"], nil)}"
  s << ', '
  s << "oobFill: #{CUDA::CUTensorMapFloatOOBfill.from_native(defi["oobFill"], nil)}"
  s << ', '
  s << "globalDim_vals: #{defi["globalDim_vals"]}"
  s << ', '
  s << "globalStrides_val: #{defi["globalStrides_val"]}"
  s << ', '
  s << "boxDim_vals: #{defi["boxDim_vals"]}"
  s << ', '
  s << "elementStrides_vals: #{defi["elementStrides_vals"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTensorMapEncodeTiled_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "tensorMap_val: #{defi["tensorMap_val"].size > 0 ? CUDA::CUTensorMap.new(FFI::MemoryPointer.from_string(defi["tensorMap_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTensorMapEncodeIm2col_entry"] = lambda { |defi|
  s = "{ "
  s << "tensorMap: #{"0x%016x" % defi["tensorMap"]}"
  s << ', '
  s << "tensorDataType: #{CUDA::CUTensorMapDataType.from_native(defi["tensorDataType"], nil)}"
  s << ', '
  s << "tensorRank: #{defi["tensorRank"]}"
  s << ', '
  s << "globalAddress: #{"0x%016x" % defi["globalAddress"]}"
  s << ', '
  s << "globalDim: #{"0x%016x" % defi["globalDim"]}"
  s << ', '
  s << "globalStrides: #{"0x%016x" % defi["globalStrides"]}"
  s << ', '
  s << "pixelBoxLowerCorner: #{"0x%016x" % defi["pixelBoxLowerCorner"]}"
  s << ', '
  s << "pixelBoxUpperCorner: #{"0x%016x" % defi["pixelBoxUpperCorner"]}"
  s << ', '
  s << "channelsPerPixel: #{defi["channelsPerPixel"]}"
  s << ', '
  s << "pixelsPerColumn: #{defi["pixelsPerColumn"]}"
  s << ', '
  s << "elementStrides: #{"0x%016x" % defi["elementStrides"]}"
  s << ', '
  s << "interleave: #{CUDA::CUTensorMapInterleave.from_native(defi["interleave"], nil)}"
  s << ', '
  s << "swizzle: #{CUDA::CUTensorMapSwizzle.from_native(defi["swizzle"], nil)}"
  s << ', '
  s << "l2Promotion: #{CUDA::CUTensorMapL2promotion.from_native(defi["l2Promotion"], nil)}"
  s << ', '
  s << "oobFill: #{CUDA::CUTensorMapFloatOOBfill.from_native(defi["oobFill"], nil)}"
  s << ', '
  s << "globalDim_vals: #{defi["globalDim_vals"]}"
  s << ', '
  s << "globalStrides_val: #{defi["globalStrides_val"]}"
  s << ', '
  s << "pixelBoxLowerCorner_vals: #{defi["pixelBoxLowerCorner_vals"]}"
  s << ', '
  s << "pixelBoxUpperCorner_vals: #{defi["pixelBoxUpperCorner_vals"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTensorMapEncodeIm2col_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "tensorMap_val: #{defi["tensorMap_val"].size > 0 ? CUDA::CUTensorMap.new(FFI::MemoryPointer.from_string(defi["tensorMap_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTensorMapEncodeIm2colWide_entry"] = lambda { |defi|
  s = "{ "
  s << "tensorMap: #{"0x%016x" % defi["tensorMap"]}"
  s << ', '
  s << "tensorDataType: #{CUDA::CUTensorMapDataType.from_native(defi["tensorDataType"], nil)}"
  s << ', '
  s << "tensorRank: #{defi["tensorRank"]}"
  s << ', '
  s << "globalAddress: #{"0x%016x" % defi["globalAddress"]}"
  s << ', '
  s << "globalDim: #{"0x%016x" % defi["globalDim"]}"
  s << ', '
  s << "globalStrides: #{"0x%016x" % defi["globalStrides"]}"
  s << ', '
  s << "pixelBoxLowerCornerWidth: #{defi["pixelBoxLowerCornerWidth"]}"
  s << ', '
  s << "pixelBoxUpperCornerWidth: #{defi["pixelBoxUpperCornerWidth"]}"
  s << ', '
  s << "channelsPerPixel: #{defi["channelsPerPixel"]}"
  s << ', '
  s << "pixelsPerColumn: #{defi["pixelsPerColumn"]}"
  s << ', '
  s << "elementStrides: #{"0x%016x" % defi["elementStrides"]}"
  s << ', '
  s << "interleave: #{CUDA::CUTensorMapInterleave.from_native(defi["interleave"], nil)}"
  s << ', '
  s << "mode: #{CUDA::CUTensorMapIm2ColWideMode.from_native(defi["mode"], nil)}"
  s << ', '
  s << "swizzle: #{CUDA::CUTensorMapSwizzle.from_native(defi["swizzle"], nil)}"
  s << ', '
  s << "l2Promotion: #{CUDA::CUTensorMapL2promotion.from_native(defi["l2Promotion"], nil)}"
  s << ', '
  s << "oobFill: #{CUDA::CUTensorMapFloatOOBfill.from_native(defi["oobFill"], nil)}"
  s << ', '
  s << "globalDim_vals: #{defi["globalDim_vals"]}"
  s << ', '
  s << "globalStrides_vals: #{defi["globalStrides_vals"]}"
  s << ', '
  s << "elementStrides_vals: #{defi["elementStrides_vals"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTensorMapEncodeIm2colWide_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "tensorMap_val: #{defi["tensorMap_val"].size > 0 ? CUDA::CUTensorMap.new(FFI::MemoryPointer.from_string(defi["tensorMap_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTensorMapReplaceAddress_entry"] = lambda { |defi|
  s = "{ "
  s << "tensorMap: #{"0x%016x" % defi["tensorMap"]}"
  s << ', '
  s << "globalAddress: #{"0x%016x" % defi["globalAddress"]}"
  s << ', '
  s << "tensorMap_val: #{defi["tensorMap_val"].size > 0 ? CUDA::CUTensorMap.new(FFI::MemoryPointer.from_string(defi["tensorMap_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTensorMapReplaceAddress_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceCanAccessPeer_entry"] = lambda { |defi|
  s = "{ "
  s << "canAccessPeer: #{"0x%016x" % defi["canAccessPeer"]}"
  s << ', '
  s << "dev: #{defi["dev"]}"
  s << ', '
  s << "peerDev: #{defi["peerDev"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceCanAccessPeer_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "canAccessPeer_val: #{defi["canAccessPeer_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxEnablePeerAccess_entry"] = lambda { |defi|
  s = "{ "
  s << "peerContext: #{"0x%016x" % defi["peerContext"]}"
  s << ', '
  s << "Flags: #{defi["Flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxEnablePeerAccess_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxDisablePeerAccess_entry"] = lambda { |defi|
  s = "{ "
  s << "peerContext: #{"0x%016x" % defi["peerContext"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxDisablePeerAccess_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetP2PAttribute_entry"] = lambda { |defi|
  s = "{ "
  s << "value: #{"0x%016x" % defi["value"]}"
  s << ', '
  s << "attrib: #{CUDA::CUDeviceP2PAttribute.from_native(defi["attrib"], nil)}"
  s << ', '
  s << "srcDevice: #{defi["srcDevice"]}"
  s << ', '
  s << "dstDevice: #{defi["dstDevice"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetP2PAttribute_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "value_val: #{defi["value_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetP2PAtomicCapabilities_entry"] = lambda { |defi|
  s = "{ "
  s << "capabilities: #{"0x%016x" % defi["capabilities"]}"
  s << ', '
  s << "operations: #{"0x%016x" % defi["operations"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "srcDevice: #{defi["srcDevice"]}"
  s << ', '
  s << "dstDevice: #{defi["dstDevice"]}"
  s << ', '
  s << "operations_vals: #{defi["operations_vals"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetP2PAtomicCapabilities_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "capabilities_vals: #{defi["capabilities_vals"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphicsUnregisterResource_entry"] = lambda { |defi|
  s = "{ "
  s << "resource: #{"0x%016x" % defi["resource"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphicsUnregisterResource_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphicsSubResourceGetMappedArray_entry"] = lambda { |defi|
  s = "{ "
  s << "pArray: #{"0x%016x" % defi["pArray"]}"
  s << ', '
  s << "resource: #{"0x%016x" % defi["resource"]}"
  s << ', '
  s << "arrayIndex: #{defi["arrayIndex"]}"
  s << ', '
  s << "mipLevel: #{defi["mipLevel"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphicsSubResourceGetMappedArray_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pArray_val: #{"0x%016x" % defi["pArray_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphicsResourceGetMappedMipmappedArray_entry"] = lambda { |defi|
  s = "{ "
  s << "pMipmappedArray: #{"0x%016x" % defi["pMipmappedArray"]}"
  s << ', '
  s << "resource: #{"0x%016x" % defi["resource"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphicsResourceGetMappedMipmappedArray_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pMipmappedArray_val: #{"0x%016x" % defi["pMipmappedArray_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphicsResourceGetMappedPointer_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "pDevPtr: #{"0x%016x" % defi["pDevPtr"]}"
  s << ', '
  s << "pSize: #{"0x%016x" % defi["pSize"]}"
  s << ', '
  s << "resource: #{"0x%016x" % defi["resource"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphicsResourceGetMappedPointer_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pDevPtr_val: #{"0x%016x" % defi["pDevPtr_val"]}"
  s << ', '
  s << "pSize_val: #{defi["pSize_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphicsResourceSetMapFlags_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "resource: #{"0x%016x" % defi["resource"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphicsResourceSetMapFlags_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphicsMapResources_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "resources: #{"0x%016x" % defi["resources"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphicsMapResources_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphicsUnmapResources_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "resources: #{"0x%016x" % defi["resources"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphicsUnmapResources_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGetProcAddress_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "symbol: #{"0x%016x" % defi["symbol"]}"
  s << ', '
  s << "pfn: #{"0x%016x" % defi["pfn"]}"
  s << ', '
  s << "cudaVersion: #{defi["cudaVersion"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "symbolStatus: #{"0x%016x" % defi["symbolStatus"]}"
  s << ', '
  s << "symbol_val: #{defi["symbol_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGetProcAddress_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pfn_val: #{"0x%016x" % defi["pfn_val"]}"
  s << ', '
  s << "symbolStatus_val: #{CUDA::CUDriverProcAddressQueryResult.from_native(defi["symbolStatus_val"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCoredumpGetAttribute_entry"] = lambda { |defi|
  s = "{ "
  s << "attrib: #{CUDA::CUCoredumpSettings.from_native(defi["attrib"], nil)}"
  s << ', '
  s << "value: #{"0x%016x" % defi["value"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << ', '
  s << "size_val: #{defi["size_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCoredumpGetAttribute_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "size_val: #{defi["size_val"]}"
  s << ', '
  s << "value_vals: #{defi["value_vals"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCoredumpGetAttributeGlobal_entry"] = lambda { |defi|
  s = "{ "
  s << "attrib: #{CUDA::CUCoredumpSettings.from_native(defi["attrib"], nil)}"
  s << ', '
  s << "value: #{"0x%016x" % defi["value"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << ', '
  s << "size_val: #{defi["size_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCoredumpGetAttributeGlobal_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "size_val: #{defi["size_val"]}"
  s << ', '
  s << "value_vals: #{defi["value_vals"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCoredumpSetAttribute_entry"] = lambda { |defi|
  s = "{ "
  s << "attrib: #{CUDA::CUCoredumpSettings.from_native(defi["attrib"], nil)}"
  s << ', '
  s << "value: #{"0x%016x" % defi["value"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << ', '
  s << "size_val: #{defi["size_val"]}"
  s << ', '
  s << "value_vals: #{defi["value_vals"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCoredumpSetAttribute_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "size_val: #{defi["size_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCoredumpSetAttributeGlobal_entry"] = lambda { |defi|
  s = "{ "
  s << "attrib: #{CUDA::CUCoredumpSettings.from_native(defi["attrib"], nil)}"
  s << ', '
  s << "value: #{"0x%016x" % defi["value"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << ', '
  s << "size_val: #{defi["size_val"]}"
  s << ', '
  s << "value_vals: #{defi["value_vals"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCoredumpSetAttributeGlobal_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "size_val: #{defi["size_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGetExportTable_entry"] = lambda { |defi|
  s = "{ "
  s << "ppExportTable: #{"0x%016x" % defi["ppExportTable"]}"
  s << ', '
  s << "pExportTableId: #{"0x%016x" % defi["pExportTableId"]}"
  s << ', '
  s << "pExportTableId_val: #{defi["pExportTableId_val"].size > 0 ? CUDA::CUUUID.new(FFI::MemoryPointer.from_string(defi["pExportTableId_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGetExportTable_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "ppExportTable_val: #{"0x%016x" % defi["ppExportTable_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGreenCtxCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "phCtx: #{"0x%016x" % defi["phCtx"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "dev: #{defi["dev"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGreenCtxCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phCtx_val: #{"0x%016x" % defi["phCtx_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGreenCtxDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "hCtx: #{"0x%016x" % defi["hCtx"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGreenCtxDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxFromGreenCtx_entry"] = lambda { |defi|
  s = "{ "
  s << "pContext: #{"0x%016x" % defi["pContext"]}"
  s << ', '
  s << "hCtx: #{"0x%016x" % defi["hCtx"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxFromGreenCtx_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pContext_val: #{"0x%016x" % defi["pContext_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetDevResource_entry"] = lambda { |defi|
  s = "{ "
  s << "device: #{defi["device"]}"
  s << ', '
  s << "resource: #{"0x%016x" % defi["resource"]}"
  s << ', '
  s << "type: #{CUDA::CUDevResourceType.from_native(defi["type"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetDevResource_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "resource_val: #{defi["resource_val"].size > 0 ? CUDA::CUDevResourceV1.new(FFI::MemoryPointer.from_string(defi["resource_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxGetDevResource_entry"] = lambda { |defi|
  s = "{ "
  s << "hCtx: #{"0x%016x" % defi["hCtx"]}"
  s << ', '
  s << "resource: #{"0x%016x" % defi["resource"]}"
  s << ', '
  s << "type: #{CUDA::CUDevResourceType.from_native(defi["type"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxGetDevResource_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "resource_val: #{defi["resource_val"].size > 0 ? CUDA::CUDevResourceV1.new(FFI::MemoryPointer.from_string(defi["resource_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGreenCtxGetDevResource_entry"] = lambda { |defi|
  s = "{ "
  s << "hCtx: #{"0x%016x" % defi["hCtx"]}"
  s << ', '
  s << "resource: #{"0x%016x" % defi["resource"]}"
  s << ', '
  s << "type: #{CUDA::CUDevResourceType.from_native(defi["type"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGreenCtxGetDevResource_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "resource_val: #{defi["resource_val"].size > 0 ? CUDA::CUDevResourceV1.new(FFI::MemoryPointer.from_string(defi["resource_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDevSmResourceSplitByCount_entry"] = lambda { |defi|
  s = "{ "
  s << "result: #{"0x%016x" % defi["result"]}"
  s << ', '
  s << "nbGroups: #{"0x%016x" % defi["nbGroups"]}"
  s << ', '
  s << "input: #{"0x%016x" % defi["input"]}"
  s << ', '
  s << "remaining: #{"0x%016x" % defi["remaining"]}"
  s << ', '
  s << "useFlags: #{defi["useFlags"]}"
  s << ', '
  s << "minCount: #{defi["minCount"]}"
  s << ', '
  s << "nbGroups_val: #{defi["nbGroups_val"]}"
  s << ', '
  s << "input_val: #{defi["input_val"].size > 0 ? CUDA::CUDevResourceV1.new(FFI::MemoryPointer.from_string(defi["input_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDevSmResourceSplitByCount_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "nbGroups_val: #{defi["nbGroups_val"]}"
  s << ', '
  s << "result_vals: [ #{p = FFI::MemoryPointer.from_string(defi["result_vals"]); sz = CUDA::CUDevResourceV1.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUDevResourceV1.new(p + i*sz).to_s}.join(", ")} ]"
  s << ', '
  s << "remaining_val: #{defi["remaining_val"].size > 0 ? CUDA::CUDevResourceV1.new(FFI::MemoryPointer.from_string(defi["remaining_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDevResourceGenerateDesc_entry"] = lambda { |defi|
  s = "{ "
  s << "phDesc: #{"0x%016x" % defi["phDesc"]}"
  s << ', '
  s << "resources: #{"0x%016x" % defi["resources"]}"
  s << ', '
  s << "nbResources: #{defi["nbResources"]}"
  s << ', '
  s << "resources_vals: [ #{p = FFI::MemoryPointer.from_string(defi["resources_vals"]); sz = CUDA::CUDevResourceV1.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUDevResourceV1.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDevResourceGenerateDesc_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phDesc_val: #{"0x%016x" % defi["phDesc_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGreenCtxRecordEvent_entry"] = lambda { |defi|
  s = "{ "
  s << "hCtx: #{"0x%016x" % defi["hCtx"]}"
  s << ', '
  s << "hEvent: #{"0x%016x" % defi["hEvent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGreenCtxRecordEvent_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGreenCtxWaitEvent_entry"] = lambda { |defi|
  s = "{ "
  s << "hCtx: #{"0x%016x" % defi["hCtx"]}"
  s << ', '
  s << "hEvent: #{"0x%016x" % defi["hEvent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGreenCtxWaitEvent_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetGreenCtx_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "phCtx: #{"0x%016x" % defi["phCtx"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetGreenCtx_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phCtx_val: #{"0x%016x" % defi["phCtx_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGreenCtxStreamCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "phStream: #{"0x%016x" % defi["phStream"]}"
  s << ', '
  s << "greenCtx: #{"0x%016x" % defi["greenCtx"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "priority: #{defi["priority"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGreenCtxStreamCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phStream_val: #{"0x%016x" % defi["phStream_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGreenCtxGetId_entry"] = lambda { |defi|
  s = "{ "
  s << "greenCtx: #{"0x%016x" % defi["greenCtx"]}"
  s << ', '
  s << "greenCtxId: #{"0x%016x" % defi["greenCtxId"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGreenCtxGetId_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "greenCtxId_val: #{defi["greenCtxId_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLogsRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "callbackFunc: #{"0x%016x" % defi["callbackFunc"]}"
  s << ', '
  s << "userData: #{"0x%016x" % defi["userData"]}"
  s << ', '
  s << "callback_out: #{"0x%016x" % defi["callback_out"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLogsRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "callback_out_val: #{"0x%016x" % defi["callback_out_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLogsUnregisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "callback: #{"0x%016x" % defi["callback"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLogsUnregisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLogsCurrent_entry"] = lambda { |defi|
  s = "{ "
  s << "iterator_out: #{"0x%016x" % defi["iterator_out"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLogsCurrent_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "iterator_out_val: #{defi["iterator_out_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLogsDumpToFile_entry"] = lambda { |defi|
  s = "{ "
  s << "iterator: #{"0x%016x" % defi["iterator"]}"
  s << ', '
  s << "pathToFile: #{"0x%016x" % defi["pathToFile"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "iterator_val: #{defi["iterator_val"]}"
  s << ', '
  s << "pathToFile_val: #{defi["pathToFile_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLogsDumpToFile_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLogsDumpToMemory_entry"] = lambda { |defi|
  s = "{ "
  s << "iterator: #{"0x%016x" % defi["iterator"]}"
  s << ', '
  s << "buffer: #{"0x%016x" % defi["buffer"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "iterator_val: #{defi["iterator_val"]}"
  s << ', '
  s << "size_val: #{defi["size_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLogsDumpToMemory_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "size_val: #{defi["size_val"]}"
  s << ', '
  s << "buffer_vals: #{defi["buffer_vals"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemHostRegister_entry"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "bytesize: #{defi["bytesize"]}"
  s << ', '
  s << "Flags: #{defi["Flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemHostRegister_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphicsResourceSetMapFlags_entry"] = lambda { |defi|
  s = "{ "
  s << "resource: #{"0x%016x" % defi["resource"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphicsResourceSetMapFlags_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLinkCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "numOptions: #{defi["numOptions"]}"
  s << ', '
  s << "options: #{"0x%016x" % defi["options"]}"
  s << ', '
  s << "optionValues: #{"0x%016x" % defi["optionValues"]}"
  s << ', '
  s << "stateOut: #{"0x%016x" % defi["stateOut"]}"
  s << ', '
  s << "options_vals: #{defi["options_vals"]}"
  s << ', '
  s << "optionValues_vals: [ #{defi["optionValues_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLinkCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "stateOut_val: #{"0x%016x" % defi["stateOut_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLinkAddData_entry"] = lambda { |defi|
  s = "{ "
  s << "state: #{"0x%016x" % defi["state"]}"
  s << ', '
  s << "type: #{CUDA::CUJitInputType.from_native(defi["type"], nil)}"
  s << ', '
  s << "data: #{"0x%016x" % defi["data"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "numOptions: #{defi["numOptions"]}"
  s << ', '
  s << "options: #{"0x%016x" % defi["options"]}"
  s << ', '
  s << "optionValues: #{"0x%016x" % defi["optionValues"]}"
  s << ', '
  s << "name_val: #{defi["name_val"].inspect}"
  s << ', '
  s << "options_vals: #{defi["options_vals"]}"
  s << ', '
  s << "optionValues_vals: [ #{defi["optionValues_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLinkAddData_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLinkAddFile_entry"] = lambda { |defi|
  s = "{ "
  s << "state: #{"0x%016x" % defi["state"]}"
  s << ', '
  s << "type: #{CUDA::CUJitInputType.from_native(defi["type"], nil)}"
  s << ', '
  s << "path: #{"0x%016x" % defi["path"]}"
  s << ', '
  s << "numOptions: #{defi["numOptions"]}"
  s << ', '
  s << "options: #{"0x%016x" % defi["options"]}"
  s << ', '
  s << "optionValues: #{"0x%016x" % defi["optionValues"]}"
  s << ', '
  s << "path_val: #{defi["path_val"].inspect}"
  s << ', '
  s << "options_vals: #{defi["options_vals"]}"
  s << ', '
  s << "optionValues_vals: [ #{defi["optionValues_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLinkAddFile_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefSetAddress2D_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "hTexRef: #{"0x%016x" % defi["hTexRef"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "dptr: #{"0x%016x" % defi["dptr"]}"
  s << ', '
  s << "Pitch: #{defi["Pitch"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefSetAddress2D_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceTotalMem_entry"] = lambda { |defi|
  s = "{ "
  s << "bytes: #{"0x%016x" % defi["bytes"]}"
  s << ', '
  s << "dev: #{defi["dev"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceTotalMem_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "bytes_val: #{defi["bytes_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "pctx: #{"0x%016x" % defi["pctx"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "dev: #{defi["dev"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pctx_val: #{"0x%016x" % defi["pctx_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxCreate_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "pctx: #{"0x%016x" % defi["pctx"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "dev: #{defi["dev"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxCreate_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pctx_val: #{"0x%016x" % defi["pctx_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxCreate_v3_entry"] = lambda { |defi|
  s = "{ "
  s << "pctx: #{"0x%016x" % defi["pctx"]}"
  s << ', '
  s << "paramsArray: #{"0x%016x" % defi["paramsArray"]}"
  s << ', '
  s << "numParams: #{defi["numParams"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "dev: #{defi["dev"]}"
  s << ', '
  s << "paramsArray_vals: [ #{p = FFI::MemoryPointer.from_string(defi["paramsArray_vals"]); sz = CUDA::CUExecAffinityParamV1.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUExecAffinityParamV1.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxCreate_v3_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pctx_val: #{"0x%016x" % defi["pctx_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuModuleGetGlobal_entry"] = lambda { |defi|
  s = "{ "
  s << "dptr: #{"0x%016x" % defi["dptr"]}"
  s << ', '
  s << "bytes: #{"0x%016x" % defi["bytes"]}"
  s << ', '
  s << "hmod: #{"0x%016x" % defi["hmod"]}"
  s << ', '
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "name_val: #{defi["name_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuModuleGetGlobal_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "dptr_val: #{defi["dptr_val"]}"
  s << ', '
  s << "bytes_val: #{defi["bytes_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemGetInfo_entry"] = lambda { |defi|
  s = "{ "
  s << "free: #{"0x%016x" % defi["free"]}"
  s << ', '
  s << "total: #{"0x%016x" % defi["total"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemGetInfo_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "free_val: #{defi["free_val"]}"
  s << ', '
  s << "total_val: #{defi["total_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemAlloc_entry"] = lambda { |defi|
  s = "{ "
  s << "dptr: #{"0x%016x" % defi["dptr"]}"
  s << ', '
  s << "bytesize: #{defi["bytesize"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemAlloc_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "dptr_val: #{defi["dptr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemAllocPitch_entry"] = lambda { |defi|
  s = "{ "
  s << "dptr: #{"0x%016x" % defi["dptr"]}"
  s << ', '
  s << "pPitch: #{"0x%016x" % defi["pPitch"]}"
  s << ', '
  s << "WidthInBytes: #{defi["WidthInBytes"]}"
  s << ', '
  s << "Height: #{defi["Height"]}"
  s << ', '
  s << "ElementSizeBytes: #{defi["ElementSizeBytes"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemAllocPitch_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "dptr_val: #{defi["dptr_val"]}"
  s << ', '
  s << "pPitch_val: #{defi["pPitch_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemFree_entry"] = lambda { |defi|
  s = "{ "
  s << "dptr: #{defi["dptr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemFree_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemGetAddressRange_entry"] = lambda { |defi|
  s = "{ "
  s << "pbase: #{"0x%016x" % defi["pbase"]}"
  s << ', '
  s << "psize: #{"0x%016x" % defi["psize"]}"
  s << ', '
  s << "dptr: #{defi["dptr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemGetAddressRange_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pbase_val: #{defi["pbase_val"]}"
  s << ', '
  s << "psize_val: #{defi["psize_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemAllocHost_entry"] = lambda { |defi|
  s = "{ "
  s << "pp: #{"0x%016x" % defi["pp"]}"
  s << ', '
  s << "bytesize: #{defi["bytesize"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemAllocHost_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pp_val: #{"0x%016x" % defi["pp_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemHostGetDevicePointer_entry"] = lambda { |defi|
  s = "{ "
  s << "pdptr: #{"0x%016x" % defi["pdptr"]}"
  s << ', '
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "Flags: #{defi["Flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemHostGetDevicePointer_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pdptr_val: #{defi["pdptr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyHtoD_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{defi["dstDevice"]}"
  s << ', '
  s << "srcHost: #{"0x%016x" % defi["srcHost"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyHtoD_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyDtoH_entry"] = lambda { |defi|
  s = "{ "
  s << "dstHost: #{"0x%016x" % defi["dstHost"]}"
  s << ', '
  s << "srcDevice: #{defi["srcDevice"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyDtoH_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyDtoD_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{defi["dstDevice"]}"
  s << ', '
  s << "srcDevice: #{defi["srcDevice"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyDtoD_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyDtoA_entry"] = lambda { |defi|
  s = "{ "
  s << "dstArray: #{"0x%016x" % defi["dstArray"]}"
  s << ', '
  s << "dstOffset: #{defi["dstOffset"]}"
  s << ', '
  s << "srcDevice: #{defi["srcDevice"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyDtoA_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyAtoD_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{defi["dstDevice"]}"
  s << ', '
  s << "srcArray: #{"0x%016x" % defi["srcArray"]}"
  s << ', '
  s << "srcOffset: #{defi["srcOffset"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyAtoD_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyHtoA_entry"] = lambda { |defi|
  s = "{ "
  s << "dstArray: #{"0x%016x" % defi["dstArray"]}"
  s << ', '
  s << "dstOffset: #{defi["dstOffset"]}"
  s << ', '
  s << "srcHost: #{"0x%016x" % defi["srcHost"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyHtoA_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyAtoH_entry"] = lambda { |defi|
  s = "{ "
  s << "dstHost: #{"0x%016x" % defi["dstHost"]}"
  s << ', '
  s << "srcArray: #{"0x%016x" % defi["srcArray"]}"
  s << ', '
  s << "srcOffset: #{defi["srcOffset"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyAtoH_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyAtoA_entry"] = lambda { |defi|
  s = "{ "
  s << "dstArray: #{"0x%016x" % defi["dstArray"]}"
  s << ', '
  s << "dstOffset: #{defi["dstOffset"]}"
  s << ', '
  s << "srcArray: #{"0x%016x" % defi["srcArray"]}"
  s << ', '
  s << "srcOffset: #{defi["srcOffset"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyAtoA_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyHtoAAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "dstArray: #{"0x%016x" % defi["dstArray"]}"
  s << ', '
  s << "dstOffset: #{defi["dstOffset"]}"
  s << ', '
  s << "srcHost: #{"0x%016x" % defi["srcHost"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyHtoAAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyAtoHAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "dstHost: #{"0x%016x" % defi["dstHost"]}"
  s << ', '
  s << "srcArray: #{"0x%016x" % defi["srcArray"]}"
  s << ', '
  s << "srcOffset: #{defi["srcOffset"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyAtoHAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy2D_entry"] = lambda { |defi|
  s = "{ "
  s << "pCopy: #{"0x%016x" % defi["pCopy"]}"
  s << ', '
  s << "pCopy_val: #{defi["pCopy_val"].size > 0 ? CUDA::CUDAMEMCPY2DV1.new(FFI::MemoryPointer.from_string(defi["pCopy_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy2D_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy2DUnaligned_entry"] = lambda { |defi|
  s = "{ "
  s << "pCopy: #{"0x%016x" % defi["pCopy"]}"
  s << ', '
  s << "pCopy_val: #{defi["pCopy_val"].size > 0 ? CUDA::CUDAMEMCPY2DV1.new(FFI::MemoryPointer.from_string(defi["pCopy_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy2DUnaligned_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy3D_entry"] = lambda { |defi|
  s = "{ "
  s << "pCopy: #{"0x%016x" % defi["pCopy"]}"
  s << ', '
  s << "pCopy_val: #{defi["pCopy_val"].size > 0 ? CUDA::CUDAMEMCPY3DV1.new(FFI::MemoryPointer.from_string(defi["pCopy_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy3D_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyHtoDAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{defi["dstDevice"]}"
  s << ', '
  s << "srcHost: #{"0x%016x" % defi["srcHost"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyHtoDAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyDtoHAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "dstHost: #{"0x%016x" % defi["dstHost"]}"
  s << ', '
  s << "srcDevice: #{defi["srcDevice"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyDtoHAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyDtoDAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{defi["dstDevice"]}"
  s << ', '
  s << "srcDevice: #{defi["srcDevice"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyDtoDAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy2DAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "pCopy: #{"0x%016x" % defi["pCopy"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "pCopy_val: #{defi["pCopy_val"].size > 0 ? CUDA::CUDAMEMCPY2DV1.new(FFI::MemoryPointer.from_string(defi["pCopy_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy2DAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy3DAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "pCopy: #{"0x%016x" % defi["pCopy"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "pCopy_val: #{defi["pCopy_val"].size > 0 ? CUDA::CUDAMEMCPY3DV1.new(FFI::MemoryPointer.from_string(defi["pCopy_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy3DAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD8_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{defi["dstDevice"]}"
  s << ', '
  s << "uc: #{defi["uc"]}"
  s << ', '
  s << "N: #{defi["N"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD8_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD16_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{defi["dstDevice"]}"
  s << ', '
  s << "us: #{defi["us"]}"
  s << ', '
  s << "N: #{defi["N"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD16_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD32_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{defi["dstDevice"]}"
  s << ', '
  s << "ui: #{defi["ui"]}"
  s << ', '
  s << "N: #{defi["N"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD32_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD2D8_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{defi["dstDevice"]}"
  s << ', '
  s << "dstPitch: #{defi["dstPitch"]}"
  s << ', '
  s << "uc: #{defi["uc"]}"
  s << ', '
  s << "Width: #{defi["Width"]}"
  s << ', '
  s << "Height: #{defi["Height"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD2D8_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD2D16_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{defi["dstDevice"]}"
  s << ', '
  s << "dstPitch: #{defi["dstPitch"]}"
  s << ', '
  s << "us: #{defi["us"]}"
  s << ', '
  s << "Width: #{defi["Width"]}"
  s << ', '
  s << "Height: #{defi["Height"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD2D16_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD2D32_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{defi["dstDevice"]}"
  s << ', '
  s << "dstPitch: #{defi["dstPitch"]}"
  s << ', '
  s << "ui: #{defi["ui"]}"
  s << ', '
  s << "Width: #{defi["Width"]}"
  s << ', '
  s << "Height: #{defi["Height"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD2D32_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuArrayCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "pHandle: #{"0x%016x" % defi["pHandle"]}"
  s << ', '
  s << "pAllocateArray: #{"0x%016x" % defi["pAllocateArray"]}"
  s << ', '
  s << "pAllocateArray_val: #{defi["pAllocateArray_val"].size > 0 ? CUDA::CUDAARRAYDESCRIPTORV1.new(FFI::MemoryPointer.from_string(defi["pAllocateArray_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuArrayCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pHandle_val: #{"0x%016x" % defi["pHandle_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuArrayGetDescriptor_entry"] = lambda { |defi|
  s = "{ "
  s << "pArrayDescriptor: #{"0x%016x" % defi["pArrayDescriptor"]}"
  s << ', '
  s << "hArray: #{"0x%016x" % defi["hArray"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuArrayGetDescriptor_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pArrayDescriptor_val: #{defi["pArrayDescriptor_val"].size > 0 ? CUDA::CUDAARRAYDESCRIPTORV1.new(FFI::MemoryPointer.from_string(defi["pArrayDescriptor_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuArray3DCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "pHandle: #{"0x%016x" % defi["pHandle"]}"
  s << ', '
  s << "pAllocateArray: #{"0x%016x" % defi["pAllocateArray"]}"
  s << ', '
  s << "pAllocateArray_val: #{defi["pAllocateArray_val"].size > 0 ? CUDA::CUDAARRAY3DDESCRIPTORV1.new(FFI::MemoryPointer.from_string(defi["pAllocateArray_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuArray3DCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pHandle_val: #{"0x%016x" % defi["pHandle_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuArray3DGetDescriptor_entry"] = lambda { |defi|
  s = "{ "
  s << "pArrayDescriptor: #{"0x%016x" % defi["pArrayDescriptor"]}"
  s << ', '
  s << "hArray: #{"0x%016x" % defi["hArray"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuArray3DGetDescriptor_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pArrayDescriptor_val: #{defi["pArrayDescriptor_val"].size > 0 ? CUDA::CUDAARRAY3DDESCRIPTORV1.new(FFI::MemoryPointer.from_string(defi["pArrayDescriptor_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefSetAddress_entry"] = lambda { |defi|
  s = "{ "
  s << "ByteOffset: #{"0x%016x" % defi["ByteOffset"]}"
  s << ', '
  s << "hTexRef: #{"0x%016x" % defi["hTexRef"]}"
  s << ', '
  s << "dptr: #{defi["dptr"]}"
  s << ', '
  s << "bytes: #{defi["bytes"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefSetAddress_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "ByteOffset_val: #{defi["ByteOffset_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefSetAddress2D_entry"] = lambda { |defi|
  s = "{ "
  s << "hTexRef: #{"0x%016x" % defi["hTexRef"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "dptr: #{defi["dptr"]}"
  s << ', '
  s << "Pitch: #{defi["Pitch"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].size > 0 ? CUDA::CUDAARRAYDESCRIPTORV1.new(FFI::MemoryPointer.from_string(defi["desc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefSetAddress2D_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefGetAddress_entry"] = lambda { |defi|
  s = "{ "
  s << "pdptr: #{"0x%016x" % defi["pdptr"]}"
  s << ', '
  s << "hTexRef: #{"0x%016x" % defi["hTexRef"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuTexRefGetAddress_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pdptr_val: #{defi["pdptr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphicsResourceGetMappedPointer_entry"] = lambda { |defi|
  s = "{ "
  s << "pDevPtr: #{"0x%016x" % defi["pDevPtr"]}"
  s << ', '
  s << "pSize: #{"0x%016x" % defi["pSize"]}"
  s << ', '
  s << "resource: #{"0x%016x" % defi["resource"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphicsResourceGetMappedPointer_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pDevPtr_val: #{defi["pDevPtr_val"]}"
  s << ', '
  s << "pSize_val: #{defi["pSize_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "ctx: #{"0x%016x" % defi["ctx"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxPopCurrent_entry"] = lambda { |defi|
  s = "{ "
  s << "pctx: #{"0x%016x" % defi["pctx"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxPopCurrent_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pctx_val: #{"0x%016x" % defi["pctx_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxPushCurrent_entry"] = lambda { |defi|
  s = "{ "
  s << "ctx: #{"0x%016x" % defi["ctx"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCtxPushCurrent_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuEventDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "hEvent: #{"0x%016x" % defi["hEvent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuEventDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuEventElapsedTime_entry"] = lambda { |defi|
  s = "{ "
  s << "pMilliseconds: #{"0x%016x" % defi["pMilliseconds"]}"
  s << ', '
  s << "hStart: #{"0x%016x" % defi["hStart"]}"
  s << ', '
  s << "hEnd: #{"0x%016x" % defi["hEnd"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuEventElapsedTime_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pMilliseconds_val: #{defi["pMilliseconds_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDevicePrimaryCtxRelease_entry"] = lambda { |defi|
  s = "{ "
  s << "dev: #{defi["dev"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDevicePrimaryCtxRelease_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDevicePrimaryCtxReset_entry"] = lambda { |defi|
  s = "{ "
  s << "dev: #{defi["dev"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDevicePrimaryCtxReset_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDevicePrimaryCtxSetFlags_entry"] = lambda { |defi|
  s = "{ "
  s << "dev: #{defi["dev"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDevicePrimaryCtxSetFlags_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetUuid_entry"] = lambda { |defi|
  s = "{ "
  s << "uuid: #{"0x%016x" % defi["uuid"]}"
  s << ', '
  s << "dev: #{defi["dev"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuDeviceGetUuid_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "uuid_val: #{defi["uuid_val"].size > 0 ? CUDA::CUUUID.new(FFI::MemoryPointer.from_string(defi["uuid_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyHtoD_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "srcHost: #{"0x%016x" % defi["srcHost"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyHtoD_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyDtoH_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "dstHost: #{"0x%016x" % defi["dstHost"]}"
  s << ', '
  s << "srcDevice: #{"0x%016x" % defi["srcDevice"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyDtoH_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyDtoD_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "srcDevice: #{"0x%016x" % defi["srcDevice"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyDtoD_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyDtoA_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "dstArray: #{"0x%016x" % defi["dstArray"]}"
  s << ', '
  s << "dstOffset: #{defi["dstOffset"]}"
  s << ', '
  s << "srcDevice: #{"0x%016x" % defi["srcDevice"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyDtoA_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyAtoD_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "srcArray: #{"0x%016x" % defi["srcArray"]}"
  s << ', '
  s << "srcOffset: #{defi["srcOffset"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyAtoD_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyHtoA_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "dstArray: #{"0x%016x" % defi["dstArray"]}"
  s << ', '
  s << "dstOffset: #{defi["dstOffset"]}"
  s << ', '
  s << "srcHost: #{"0x%016x" % defi["srcHost"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyHtoA_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyAtoH_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "dstHost: #{"0x%016x" % defi["dstHost"]}"
  s << ', '
  s << "srcArray: #{"0x%016x" % defi["srcArray"]}"
  s << ', '
  s << "srcOffset: #{defi["srcOffset"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyAtoH_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyAtoA_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "dstArray: #{"0x%016x" % defi["dstArray"]}"
  s << ', '
  s << "dstOffset: #{defi["dstOffset"]}"
  s << ', '
  s << "srcArray: #{"0x%016x" % defi["srcArray"]}"
  s << ', '
  s << "srcOffset: #{defi["srcOffset"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyAtoA_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyHtoAAsync_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "dstArray: #{"0x%016x" % defi["dstArray"]}"
  s << ', '
  s << "dstOffset: #{defi["dstOffset"]}"
  s << ', '
  s << "srcHost: #{"0x%016x" % defi["srcHost"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyHtoAAsync_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyAtoHAsync_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "dstHost: #{"0x%016x" % defi["dstHost"]}"
  s << ', '
  s << "srcArray: #{"0x%016x" % defi["srcArray"]}"
  s << ', '
  s << "srcOffset: #{defi["srcOffset"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyAtoHAsync_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy2D_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "pCopy: #{"0x%016x" % defi["pCopy"]}"
  s << ', '
  s << "pCopy_val: #{defi["pCopy_val"].size > 0 ? CUDA::CUDAMEMCPY2DV2.new(FFI::MemoryPointer.from_string(defi["pCopy_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy2D_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy2DUnaligned_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "pCopy: #{"0x%016x" % defi["pCopy"]}"
  s << ', '
  s << "pCopy_val: #{defi["pCopy_val"].size > 0 ? CUDA::CUDAMEMCPY2DV2.new(FFI::MemoryPointer.from_string(defi["pCopy_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy2DUnaligned_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy3D_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "pCopy: #{"0x%016x" % defi["pCopy"]}"
  s << ', '
  s << "pCopy_val: #{defi["pCopy_val"].size > 0 ? CUDA::CUDAMEMCPY3DV2.new(FFI::MemoryPointer.from_string(defi["pCopy_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy3D_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyHtoDAsync_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "srcHost: #{"0x%016x" % defi["srcHost"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyHtoDAsync_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyDtoHAsync_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "dstHost: #{"0x%016x" % defi["dstHost"]}"
  s << ', '
  s << "srcDevice: #{"0x%016x" % defi["srcDevice"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyDtoHAsync_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyDtoDAsync_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "srcDevice: #{"0x%016x" % defi["srcDevice"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyDtoDAsync_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy2DAsync_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "pCopy: #{"0x%016x" % defi["pCopy"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "pCopy_val: #{defi["pCopy_val"].size > 0 ? CUDA::CUDAMEMCPY2DV2.new(FFI::MemoryPointer.from_string(defi["pCopy_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy2DAsync_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy3DAsync_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "pCopy: #{"0x%016x" % defi["pCopy"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "pCopy_val: #{defi["pCopy_val"].size > 0 ? CUDA::CUDAMEMCPY3DV2.new(FFI::MemoryPointer.from_string(defi["pCopy_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy3DAsync_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD8_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "uc: #{defi["uc"]}"
  s << ', '
  s << "N: #{defi["N"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD8_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD16_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "us: #{defi["us"]}"
  s << ', '
  s << "N: #{defi["N"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD16_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD32_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "ui: #{defi["ui"]}"
  s << ', '
  s << "N: #{defi["N"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD32_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD2D8_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "dstPitch: #{defi["dstPitch"]}"
  s << ', '
  s << "uc: #{defi["uc"]}"
  s << ', '
  s << "Width: #{defi["Width"]}"
  s << ', '
  s << "Height: #{defi["Height"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD2D8_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD2D16_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "dstPitch: #{defi["dstPitch"]}"
  s << ', '
  s << "us: #{defi["us"]}"
  s << ', '
  s << "Width: #{defi["Width"]}"
  s << ', '
  s << "Height: #{defi["Height"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD2D16_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD2D32_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "dstPitch: #{defi["dstPitch"]}"
  s << ', '
  s << "ui: #{defi["ui"]}"
  s << ', '
  s << "Width: #{defi["Width"]}"
  s << ', '
  s << "Height: #{defi["Height"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD2D32_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyPeer_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "dstContext: #{"0x%016x" % defi["dstContext"]}"
  s << ', '
  s << "srcDevice: #{"0x%016x" % defi["srcDevice"]}"
  s << ', '
  s << "srcContext: #{"0x%016x" % defi["srcContext"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyPeer_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyPeerAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "dstContext: #{"0x%016x" % defi["dstContext"]}"
  s << ', '
  s << "srcDevice: #{"0x%016x" % defi["srcDevice"]}"
  s << ', '
  s << "srcContext: #{"0x%016x" % defi["srcContext"]}"
  s << ', '
  s << "ByteCount: #{defi["ByteCount"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyPeerAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy3DPeer_entry"] = lambda { |defi|
  s = "{ "
  s << "pCopy: #{"0x%016x" % defi["pCopy"]}"
  s << ', '
  s << "pCopy_val: #{defi["pCopy_val"].size > 0 ? CUDA::CUDAMEMCPY3DPEERV1.new(FFI::MemoryPointer.from_string(defi["pCopy_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy3DPeer_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy3DPeerAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "pCopy: #{"0x%016x" % defi["pCopy"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "pCopy_val: #{defi["pCopy_val"].size > 0 ? CUDA::CUDAMEMCPY3DPEERV1.new(FFI::MemoryPointer.from_string(defi["pCopy_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy3DPeerAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyBatchAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "dsts: #{"0x%016x" % defi["dsts"]}"
  s << ', '
  s << "srcs: #{"0x%016x" % defi["srcs"]}"
  s << ', '
  s << "sizes: #{"0x%016x" % defi["sizes"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "attrs: #{"0x%016x" % defi["attrs"]}"
  s << ', '
  s << "attrsIdxs: #{"0x%016x" % defi["attrsIdxs"]}"
  s << ', '
  s << "numAttrs: #{defi["numAttrs"]}"
  s << ', '
  s << "failIdx: #{"0x%016x" % defi["failIdx"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "dsts_vals: [ #{defi["dsts_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "srcs_vals: [ #{defi["srcs_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "sizes_vals: #{defi["sizes_vals"]}"
  s << ', '
  s << "attrs_vals: [ #{p = FFI::MemoryPointer.from_string(defi["attrs_vals"]); sz = CUDA::CUMemcpyAttributesV1.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUMemcpyAttributesV1.new(p + i*sz).to_s}.join(", ")} ]"
  s << ', '
  s << "attrsIdxs_vals: #{defi["attrsIdxs_vals"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyBatchAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "failIdx_val: #{defi["failIdx_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy3DBatchAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "numOps: #{defi["numOps"]}"
  s << ', '
  s << "opList: #{"0x%016x" % defi["opList"]}"
  s << ', '
  s << "failIdx: #{"0x%016x" % defi["failIdx"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "opList_vals: [ #{p = FFI::MemoryPointer.from_string(defi["opList_vals"]); sz = CUDA::CUDAMEMCPY3DBATCHOPV1.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUDAMEMCPY3DBATCHOPV1.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy3DBatchAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "failIdx_val: #{defi["failIdx_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyBatchAsync_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "dsts: #{"0x%016x" % defi["dsts"]}"
  s << ', '
  s << "srcs: #{"0x%016x" % defi["srcs"]}"
  s << ', '
  s << "sizes: #{"0x%016x" % defi["sizes"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "attrs: #{"0x%016x" % defi["attrs"]}"
  s << ', '
  s << "attrsIdxs: #{"0x%016x" % defi["attrsIdxs"]}"
  s << ', '
  s << "numAttrs: #{defi["numAttrs"]}"
  s << ', '
  s << "failIdx: #{"0x%016x" % defi["failIdx"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "dsts_vals: [ #{defi["dsts_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "srcs_vals: [ #{defi["srcs_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "sizes_vals: #{defi["sizes_vals"]}"
  s << ', '
  s << "attrs_vals: [ #{p = FFI::MemoryPointer.from_string(defi["attrs_vals"]); sz = CUDA::CUMemcpyAttributesV1.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUMemcpyAttributesV1.new(p + i*sz).to_s}.join(", ")} ]"
  s << ', '
  s << "attrsIdxs_vals: #{defi["attrsIdxs_vals"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyBatchAsync_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "failIdx_val: #{defi["failIdx_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy3DBatchAsync_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "numOps: #{defi["numOps"]}"
  s << ', '
  s << "opList: #{"0x%016x" % defi["opList"]}"
  s << ', '
  s << "failIdx: #{"0x%016x" % defi["failIdx"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "opList_vals: [ #{p = FFI::MemoryPointer.from_string(defi["opList_vals"]); sz = CUDA::CUDAMEMCPY3DBATCHOPV1.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUDAMEMCPY3DBATCHOPV1.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy3DBatchAsync_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "failIdx_val: #{defi["failIdx_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyBatchAsync_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "dsts: #{"0x%016x" % defi["dsts"]}"
  s << ', '
  s << "srcs: #{"0x%016x" % defi["srcs"]}"
  s << ', '
  s << "sizes: #{"0x%016x" % defi["sizes"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "attrs: #{"0x%016x" % defi["attrs"]}"
  s << ', '
  s << "attrsIdxs: #{"0x%016x" % defi["attrsIdxs"]}"
  s << ', '
  s << "numAttrs: #{defi["numAttrs"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "dsts_vals: [ #{defi["dsts_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "srcs_vals: [ #{defi["srcs_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "sizes_vals: #{defi["sizes_vals"]}"
  s << ', '
  s << "attrs_vals: [ #{p = FFI::MemoryPointer.from_string(defi["attrs_vals"]); sz = CUDA::CUMemcpyAttributesV1.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUMemcpyAttributesV1.new(p + i*sz).to_s}.join(", ")} ]"
  s << ', '
  s << "attrsIdxs_vals: #{defi["attrsIdxs_vals"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpyBatchAsync_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy3DBatchAsync_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "numOps: #{defi["numOps"]}"
  s << ', '
  s << "opList: #{"0x%016x" % defi["opList"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "opList_vals: [ #{p = FFI::MemoryPointer.from_string(defi["opList_vals"]); sz = CUDA::CUDAMEMCPY3DBATCHOPV1.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUDAMEMCPY3DBATCHOPV1.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemcpy3DBatchAsync_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD8Async_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "uc: #{defi["uc"]}"
  s << ', '
  s << "N: #{defi["N"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD8Async_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD16Async_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "us: #{defi["us"]}"
  s << ', '
  s << "N: #{defi["N"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD16Async_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD32Async_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "ui: #{defi["ui"]}"
  s << ', '
  s << "N: #{defi["N"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD32Async_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD2D8Async_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "dstPitch: #{defi["dstPitch"]}"
  s << ', '
  s << "uc: #{defi["uc"]}"
  s << ', '
  s << "Width: #{defi["Width"]}"
  s << ', '
  s << "Height: #{defi["Height"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD2D8Async_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD2D16Async_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "dstPitch: #{defi["dstPitch"]}"
  s << ', '
  s << "us: #{defi["us"]}"
  s << ', '
  s << "Width: #{defi["Width"]}"
  s << ', '
  s << "Height: #{defi["Height"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD2D16Async_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD2D32Async_entry"] = lambda { |defi|
  s = "{ "
  s << "dstDevice: #{"0x%016x" % defi["dstDevice"]}"
  s << ', '
  s << "dstPitch: #{defi["dstPitch"]}"
  s << ', '
  s << "ui: #{defi["ui"]}"
  s << ', '
  s << "Width: #{defi["Width"]}"
  s << ', '
  s << "Height: #{defi["Height"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemsetD2D32Async_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetPriority_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "priority: #{"0x%016x" % defi["priority"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetPriority_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "priority_val: #{defi["priority_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetId_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "streamId: #{"0x%016x" % defi["streamId"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetId_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "streamId_val: #{defi["streamId_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetFlags_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "flags: #{"0x%016x" % defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetFlags_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "flags_val: #{defi["flags_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetDevice_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "device: #{"0x%016x" % defi["device"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetDevice_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "device_val: #{defi["device_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetCtx_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "pctx: #{"0x%016x" % defi["pctx"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetCtx_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pctx_val: #{"0x%016x" % defi["pctx_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetCtx_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "pCtx: #{"0x%016x" % defi["pCtx"]}"
  s << ', '
  s << "pGreenCtx: #{"0x%016x" % defi["pGreenCtx"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetCtx_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pCtx_val: #{"0x%016x" % defi["pCtx_val"]}"
  s << ', '
  s << "pGreenCtx_val: #{"0x%016x" % defi["pGreenCtx_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamWaitEvent_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "hEvent: #{"0x%016x" % defi["hEvent"]}"
  s << ', '
  s << "Flags: #{defi["Flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamWaitEvent_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamAddCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "callback: #{"0x%016x" % defi["callback"]}"
  s << ', '
  s << "userData: #{"0x%016x" % defi["userData"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamAddCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamAttachMemAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "dptr: #{"0x%016x" % defi["dptr"]}"
  s << ', '
  s << "length: #{defi["length"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamAttachMemAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamQuery_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamQuery_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamSynchronize_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamSynchronize_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuEventRecord_entry"] = lambda { |defi|
  s = "{ "
  s << "hEvent: #{"0x%016x" % defi["hEvent"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuEventRecord_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuEventRecordWithFlags_entry"] = lambda { |defi|
  s = "{ "
  s << "hEvent: #{"0x%016x" % defi["hEvent"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuEventRecordWithFlags_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLaunchKernel_entry"] = lambda { |defi|
  s = "{ "
  s << "f: #{"0x%016x" % defi["f"]}"
  s << ', '
  s << "gridDimX: #{defi["gridDimX"]}"
  s << ', '
  s << "gridDimY: #{defi["gridDimY"]}"
  s << ', '
  s << "gridDimZ: #{defi["gridDimZ"]}"
  s << ', '
  s << "blockDimX: #{defi["blockDimX"]}"
  s << ', '
  s << "blockDimY: #{defi["blockDimY"]}"
  s << ', '
  s << "blockDimZ: #{defi["blockDimZ"]}"
  s << ', '
  s << "sharedMemBytes: #{defi["sharedMemBytes"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "kernelParams: #{"0x%016x" % defi["kernelParams"]}"
  s << ', '
  s << "extra: #{"0x%016x" % defi["extra"]}"
  s << ', '
  s << "extra_vals: [ #{defi["extra_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLaunchKernel_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLaunchKernelEx_entry"] = lambda { |defi|
  s = "{ "
  s << "config: #{"0x%016x" % defi["config"]}"
  s << ', '
  s << "f: #{"0x%016x" % defi["f"]}"
  s << ', '
  s << "kernelParams: #{"0x%016x" % defi["kernelParams"]}"
  s << ', '
  s << "extra: #{"0x%016x" % defi["extra"]}"
  s << ', '
  s << "config_val: #{defi["config_val"].size > 0 ? CUDA::CULaunchConfig.new(FFI::MemoryPointer.from_string(defi["config_val"])) : nil}"
  s << ', '
  s << "config__attrs_vals: [ #{p = FFI::MemoryPointer.from_string(defi["config__attrs_vals"]); sz = CUDA::CULaunchAttribute.size; n = p.size / sz; (0...n).collect { |i| CUDA::CULaunchAttribute.new(p + i*sz).to_s}.join(", ")} ]"
  s << ', '
  s << "extra_vals: [ #{defi["extra_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLaunchKernelEx_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLaunchHostFunc_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "fn: #{"0x%016x" % defi["fn"]}"
  s << ', '
  s << "userData: #{"0x%016x" % defi["userData"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLaunchHostFunc_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphicsMapResources_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "resources: #{"0x%016x" % defi["resources"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "resources_vals: [ #{defi["resources_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphicsMapResources_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphicsUnmapResources_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "resources: #{"0x%016x" % defi["resources"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "resources_vals: [ #{defi["resources_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphicsUnmapResources_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamWriteValue32_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "addr: #{"0x%016x" % defi["addr"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamWriteValue32_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamWaitValue32_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "addr: #{"0x%016x" % defi["addr"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamWaitValue32_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamWriteValue64_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "addr: #{"0x%016x" % defi["addr"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamWriteValue64_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamWaitValue64_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "addr: #{"0x%016x" % defi["addr"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamWaitValue64_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamBatchMemOp_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "paramArray: #{"0x%016x" % defi["paramArray"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "paramArray_vals: #{defi["paramArray_vals"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamBatchMemOp_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamWriteValue32_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "addr: #{"0x%016x" % defi["addr"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamWriteValue32_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamWaitValue32_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "addr: #{"0x%016x" % defi["addr"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamWaitValue32_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamWriteValue64_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "addr: #{"0x%016x" % defi["addr"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamWriteValue64_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamWaitValue64_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "addr: #{"0x%016x" % defi["addr"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamWaitValue64_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamBatchMemOp_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "paramArray: #{"0x%016x" % defi["paramArray"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "paramArray_vals: #{defi["paramArray_vals"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamBatchMemOp_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamWriteValue32_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "addr: #{"0x%016x" % defi["addr"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamWriteValue32_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamWaitValue32_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "addr: #{"0x%016x" % defi["addr"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamWaitValue32_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamWriteValue64_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "addr: #{"0x%016x" % defi["addr"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamWriteValue64_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamWaitValue64_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "addr: #{"0x%016x" % defi["addr"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamWaitValue64_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamBatchMemOp_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "paramArray: #{"0x%016x" % defi["paramArray"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "paramArray_vals: #{defi["paramArray_vals"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamBatchMemOp_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemPrefetchAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "devPtr: #{"0x%016x" % defi["devPtr"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "dstDevice: #{defi["dstDevice"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemPrefetchAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemPrefetchAsync_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "devPtr: #{"0x%016x" % defi["devPtr"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "dstDevice: #{defi["dstDevice"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemPrefetchAsync_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemPrefetchAsync_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "devPtr: #{"0x%016x" % defi["devPtr"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "location: #{defi["location"].size > 0 ? CUDA::CUMemLocationV1.new(FFI::MemoryPointer.from_string(defi["location"])) : nil}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemPrefetchAsync_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemAdvise_entry"] = lambda { |defi|
  s = "{ "
  s << "devPtr: #{"0x%016x" % defi["devPtr"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "advice: #{CUDA::CUMemAdvise.from_native(defi["advice"], nil)}"
  s << ', '
  s << "device: #{defi["device"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemAdvise_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemPrefetchBatchAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "dptrs: #{"0x%016x" % defi["dptrs"]}"
  s << ', '
  s << "sizes: #{"0x%016x" % defi["sizes"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "prefetchLocs: #{"0x%016x" % defi["prefetchLocs"]}"
  s << ', '
  s << "prefetchLocIdxs: #{"0x%016x" % defi["prefetchLocIdxs"]}"
  s << ', '
  s << "numPrefetchLocs: #{defi["numPrefetchLocs"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "dptrs_vals: [ #{defi["dptrs_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "sizes_vals: #{defi["sizes_vals"]}"
  s << ', '
  s << "prefetchLocs_vals: [ #{p = FFI::MemoryPointer.from_string(defi["prefetchLocs_vals"]); sz = CUDA::CUMemLocationV1.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUMemLocationV1.new(p + i*sz).to_s}.join(", ")} ]"
  s << ', '
  s << "prefetchLocIdxs_vals: #{defi["prefetchLocIdxs_vals"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemPrefetchBatchAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemDiscardBatchAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "dptrs: #{"0x%016x" % defi["dptrs"]}"
  s << ', '
  s << "sizes: #{"0x%016x" % defi["sizes"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "dptrs_vals: [ #{defi["dptrs_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "sizes_vals: #{defi["sizes_vals"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemDiscardBatchAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemDiscardAndPrefetchBatchAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "dptrs: #{"0x%016x" % defi["dptrs"]}"
  s << ', '
  s << "sizes: #{"0x%016x" % defi["sizes"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "prefetchLocs: #{"0x%016x" % defi["prefetchLocs"]}"
  s << ', '
  s << "prefetchLocIdxs: #{"0x%016x" % defi["prefetchLocIdxs"]}"
  s << ', '
  s << "numPrefetchLocs: #{defi["numPrefetchLocs"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "dptrs_vals: [ #{defi["dptrs_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "sizes_vals: #{defi["sizes_vals"]}"
  s << ', '
  s << "prefetchLocs_vals: [ #{p = FFI::MemoryPointer.from_string(defi["prefetchLocs_vals"]); sz = CUDA::CUMemLocationV1.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUMemLocationV1.new(p + i*sz).to_s}.join(", ")} ]"
  s << ', '
  s << "prefetchLocIdxs_vals: #{defi["prefetchLocIdxs_vals"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemDiscardAndPrefetchBatchAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLaunchCooperativeKernel_entry"] = lambda { |defi|
  s = "{ "
  s << "f: #{"0x%016x" % defi["f"]}"
  s << ', '
  s << "gridDimX: #{defi["gridDimX"]}"
  s << ', '
  s << "gridDimY: #{defi["gridDimY"]}"
  s << ', '
  s << "gridDimZ: #{defi["gridDimZ"]}"
  s << ', '
  s << "blockDimX: #{defi["blockDimX"]}"
  s << ', '
  s << "blockDimY: #{defi["blockDimY"]}"
  s << ', '
  s << "blockDimZ: #{defi["blockDimZ"]}"
  s << ', '
  s << "sharedMemBytes: #{defi["sharedMemBytes"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "kernelParams: #{"0x%016x" % defi["kernelParams"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuLaunchCooperativeKernel_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuSignalExternalSemaphoresAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "extSemArray: #{"0x%016x" % defi["extSemArray"]}"
  s << ', '
  s << "paramsArray: #{"0x%016x" % defi["paramsArray"]}"
  s << ', '
  s << "numExtSems: #{defi["numExtSems"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "extSemArray_vals: [ #{defi["extSemArray_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "paramsArray_vals: [ #{p = FFI::MemoryPointer.from_string(defi["paramsArray_vals"]); sz = CUDA::CUDAEXTERNALSEMAPHORESIGNALPARAMSV1.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUDAEXTERNALSEMAPHORESIGNALPARAMSV1.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuSignalExternalSemaphoresAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuWaitExternalSemaphoresAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "extSemArray: #{"0x%016x" % defi["extSemArray"]}"
  s << ', '
  s << "paramsArray: #{"0x%016x" % defi["paramsArray"]}"
  s << ', '
  s << "numExtSems: #{defi["numExtSems"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "extSemArray_vals: [ #{defi["extSemArray_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "paramsArray_vals: [ #{p = FFI::MemoryPointer.from_string(defi["paramsArray_vals"]); sz = CUDA::CUDAEXTERNALSEMAPHOREWAITPARAMSV1.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUDAEXTERNALSEMAPHOREWAITPARAMSV1.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuWaitExternalSemaphoresAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamBeginCapture_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamBeginCapture_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamBeginCapture_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamBeginCapture_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamBeginCapture_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "mode: #{CUDA::CUStreamCaptureMode.from_native(defi["mode"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamBeginCapture_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamBeginCaptureToGraph_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "dependencies: #{"0x%016x" % defi["dependencies"]}"
  s << ', '
  s << "dependencyData: #{"0x%016x" % defi["dependencyData"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "mode: #{CUDA::CUStreamCaptureMode.from_native(defi["mode"], nil)}"
  s << ', '
  s << "dependencies_vals: [ #{defi["dependencies_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "dependencyData_vals: [ #{p = FFI::MemoryPointer.from_string(defi["dependencyData_vals"]); sz = CUDA::CUGraphEdgeData.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUGraphEdgeData.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamBeginCaptureToGraph_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamEndCapture_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "phGraph: #{"0x%016x" % defi["phGraph"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamEndCapture_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phGraph_val: #{"0x%016x" % defi["phGraph_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamIsCapturing_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "captureStatus: #{"0x%016x" % defi["captureStatus"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamIsCapturing_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "captureStatus_val: #{CUDA::CUStreamCaptureStatus.from_native(defi["captureStatus_val"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetCaptureInfo_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "captureStatus_out: #{"0x%016x" % defi["captureStatus_out"]}"
  s << ', '
  s << "id_out: #{"0x%016x" % defi["id_out"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetCaptureInfo_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "captureStatus_out_val: #{CUDA::CUStreamCaptureStatus.from_native(defi["captureStatus_out_val"], nil)}"
  s << ', '
  s << "id_out_val: #{defi["id_out_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetCaptureInfo_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "captureStatus_out: #{"0x%016x" % defi["captureStatus_out"]}"
  s << ', '
  s << "id_out: #{"0x%016x" % defi["id_out"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetCaptureInfo_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "captureStatus_out_val: #{CUDA::CUStreamCaptureStatus.from_native(defi["captureStatus_out_val"], nil)}"
  s << ', '
  s << "id_out_val: #{defi["id_out_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetCaptureInfo_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "captureStatus_out: #{"0x%016x" % defi["captureStatus_out"]}"
  s << ', '
  s << "id_out: #{"0x%016x" % defi["id_out"]}"
  s << ', '
  s << "graph_out: #{"0x%016x" % defi["graph_out"]}"
  s << ', '
  s << "dependencies_out: #{"0x%016x" % defi["dependencies_out"]}"
  s << ', '
  s << "numDependencies_out: #{"0x%016x" % defi["numDependencies_out"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetCaptureInfo_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "captureStatus_out_val: #{CUDA::CUStreamCaptureStatus.from_native(defi["captureStatus_out_val"], nil)}"
  s << ', '
  s << "id_out_val: #{defi["id_out_val"]}"
  s << ', '
  s << "graph_out_val: #{"0x%016x" % defi["graph_out_val"]}"
  s << ', '
  s << "dependencies_out_val: #{"0x%016x" % defi["dependencies_out_val"]}"
  s << ', '
  s << "numDependencies_out_val: #{defi["numDependencies_out_val"]}"
  s << ', '
  s << "dependencies_out_val_vals: [ #{defi["dependencies_out_val_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetCaptureInfo_v2_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "captureStatus_out: #{"0x%016x" % defi["captureStatus_out"]}"
  s << ', '
  s << "id_out: #{"0x%016x" % defi["id_out"]}"
  s << ', '
  s << "graph_out: #{"0x%016x" % defi["graph_out"]}"
  s << ', '
  s << "dependencies_out: #{"0x%016x" % defi["dependencies_out"]}"
  s << ', '
  s << "numDependencies_out: #{"0x%016x" % defi["numDependencies_out"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetCaptureInfo_v2_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "captureStatus_out_val: #{CUDA::CUStreamCaptureStatus.from_native(defi["captureStatus_out_val"], nil)}"
  s << ', '
  s << "id_out_val: #{defi["id_out_val"]}"
  s << ', '
  s << "graph_out_val: #{"0x%016x" % defi["graph_out_val"]}"
  s << ', '
  s << "dependencies_out_val: #{"0x%016x" % defi["dependencies_out_val"]}"
  s << ', '
  s << "numDependencies_out_val: #{defi["numDependencies_out_val"]}"
  s << ', '
  s << "dependencies_out_val_vals: [ #{defi["dependencies_out_val_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetCaptureInfo_v3_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "captureStatus_out: #{"0x%016x" % defi["captureStatus_out"]}"
  s << ', '
  s << "id_out: #{"0x%016x" % defi["id_out"]}"
  s << ', '
  s << "graph_out: #{"0x%016x" % defi["graph_out"]}"
  s << ', '
  s << "dependencies_out: #{"0x%016x" % defi["dependencies_out"]}"
  s << ', '
  s << "edgeData_out: #{"0x%016x" % defi["edgeData_out"]}"
  s << ', '
  s << "numDependencies_out: #{"0x%016x" % defi["numDependencies_out"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetCaptureInfo_v3_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "captureStatus_out_val: #{CUDA::CUStreamCaptureStatus.from_native(defi["captureStatus_out_val"], nil)}"
  s << ', '
  s << "id_out_val: #{defi["id_out_val"]}"
  s << ', '
  s << "graph_out_val: #{"0x%016x" % defi["graph_out_val"]}"
  s << ', '
  s << "numDependencies_out_val: #{defi["numDependencies_out_val"]}"
  s << ', '
  s << "dependencies_out_val_vals: [ #{defi["dependencies_out_val_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "edgeData_out_val_vals: [ #{p = FFI::MemoryPointer.from_string(defi["edgeData_out_val_vals"]); sz = CUDA::CUGraphEdgeData.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUGraphEdgeData.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphAddKernelNode_entry"] = lambda { |defi|
  s = "{ "
  s << "phGraphNode: #{"0x%016x" % defi["phGraphNode"]}"
  s << ', '
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "dependencies: #{"0x%016x" % defi["dependencies"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "nodeParams: #{"0x%016x" % defi["nodeParams"]}"
  s << ', '
  s << "dependencies_vals: [ #{defi["dependencies_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "nodeParams_val: #{defi["nodeParams_val"].size > 0 ? CUDA::CUDAKERNELNODEPARAMSV1.new(FFI::MemoryPointer.from_string(defi["nodeParams_val"])) : nil}"
  s << ', '
  s << "nodeParams__extra_vals: [ #{defi["nodeParams__extra_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphAddKernelNode_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phGraphNode_val: #{"0x%016x" % defi["phGraphNode_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphKernelNodeGetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "nodeParams: #{"0x%016x" % defi["nodeParams"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphKernelNodeGetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "nodeParams_val: #{defi["nodeParams_val"].size > 0 ? CUDA::CUDAKERNELNODEPARAMSV1.new(FFI::MemoryPointer.from_string(defi["nodeParams_val"])) : nil}"
  s << ', '
  s << "nodeParams__extra_vals: [ #{defi["nodeParams__extra_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphKernelNodeSetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "nodeParams: #{"0x%016x" % defi["nodeParams"]}"
  s << ', '
  s << "nodeParams_val: #{defi["nodeParams_val"].size > 0 ? CUDA::CUDAKERNELNODEPARAMSV1.new(FFI::MemoryPointer.from_string(defi["nodeParams_val"])) : nil}"
  s << ', '
  s << "nodeParams__extra_vals: [ #{defi["nodeParams__extra_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphKernelNodeSetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExecKernelNodeSetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraphExec: #{"0x%016x" % defi["hGraphExec"]}"
  s << ', '
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "nodeParams: #{"0x%016x" % defi["nodeParams"]}"
  s << ', '
  s << "nodeParams_val: #{defi["nodeParams_val"].size > 0 ? CUDA::CUDAKERNELNODEPARAMSV1.new(FFI::MemoryPointer.from_string(defi["nodeParams_val"])) : nil}"
  s << ', '
  s << "nodeParams__extra_vals: [ #{defi["nodeParams__extra_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExecKernelNodeSetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphInstantiateWithParams_entry"] = lambda { |defi|
  s = "{ "
  s << "phGraphExec: #{"0x%016x" % defi["phGraphExec"]}"
  s << ', '
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "instantiateParams: #{"0x%016x" % defi["instantiateParams"]}"
  s << ', '
  s << "instantiateParams_val: #{defi["instantiateParams_val"].size > 0 ? CUDA::CUDAGRAPHINSTANTIATEPARAMS.new(FFI::MemoryPointer.from_string(defi["instantiateParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphInstantiateWithParams_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phGraphExec_val: #{"0x%016x" % defi["phGraphExec_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExecUpdate_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraphExec: #{"0x%016x" % defi["hGraphExec"]}"
  s << ', '
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "hErrorNode_out: #{"0x%016x" % defi["hErrorNode_out"]}"
  s << ', '
  s << "updateResult_out: #{"0x%016x" % defi["updateResult_out"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphExecUpdate_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "hErrorNode_out_val: #{"0x%016x" % defi["hErrorNode_out_val"]}"
  s << ', '
  s << "updateResult_out_val: #{CUDA::CUGraphExecUpdateResult.from_native(defi["updateResult_out_val"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphUpload_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphUpload_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphLaunch_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphLaunch_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphGetEdges_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "from: #{"0x%016x" % defi["from"]}"
  s << ', '
  s << "to: #{"0x%016x" % defi["to"]}"
  s << ', '
  s << "numEdges: #{"0x%016x" % defi["numEdges"]}"
  s << ', '
  s << "numEdges_val: #{defi["numEdges_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphGetEdges_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "numEdges_val: #{defi["numEdges_val"]}"
  s << ', '
  s << "from_vals: [ #{defi["from_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "to_vals: [ #{defi["to_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphNodeGetDependencies_entry"] = lambda { |defi|
  s = "{ "
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "dependencies: #{"0x%016x" % defi["dependencies"]}"
  s << ', '
  s << "numDependencies: #{"0x%016x" % defi["numDependencies"]}"
  s << ', '
  s << "numDependencies_val: #{defi["numDependencies_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphNodeGetDependencies_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "numDependencies_val: #{defi["numDependencies_val"]}"
  s << ', '
  s << "dependencies_vals: [ #{defi["dependencies_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphNodeGetDependentNodes_entry"] = lambda { |defi|
  s = "{ "
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "dependentNodes: #{"0x%016x" % defi["dependentNodes"]}"
  s << ', '
  s << "numDependentNodes: #{"0x%016x" % defi["numDependentNodes"]}"
  s << ', '
  s << "numDependentNodes_val: #{defi["numDependentNodes_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphNodeGetDependentNodes_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "numDependentNodes_val: #{defi["numDependentNodes_val"]}"
  s << ', '
  s << "dependentNodes_vals: [ #{defi["dependentNodes_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphAddDependencies_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "from: #{"0x%016x" % defi["from"]}"
  s << ', '
  s << "to: #{"0x%016x" % defi["to"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "from_vals: [ #{defi["from_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "to_vals: [ #{defi["to_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphAddDependencies_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphRemoveDependencies_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "from: #{"0x%016x" % defi["from"]}"
  s << ', '
  s << "to: #{"0x%016x" % defi["to"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "from_vals: [ #{defi["from_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "to_vals: [ #{defi["to_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphRemoveDependencies_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphAddNode_entry"] = lambda { |defi|
  s = "{ "
  s << "phGraphNode: #{"0x%016x" % defi["phGraphNode"]}"
  s << ', '
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "dependencies: #{"0x%016x" % defi["dependencies"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "nodeParams: #{"0x%016x" % defi["nodeParams"]}"
  s << ', '
  s << "dependencies_vals: [ #{defi["dependencies_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "nodeParams_val: #{defi["nodeParams_val"].size > 0 ? CUDA::CUGraphNodeParams.new(FFI::MemoryPointer.from_string(defi["nodeParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphAddNode_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phGraphNode_val: #{"0x%016x" % defi["phGraphNode_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamCopyAttributes_entry"] = lambda { |defi|
  s = "{ "
  s << "dstStream: #{"0x%016x" % defi["dstStream"]}"
  s << ', '
  s << "srcStream: #{"0x%016x" % defi["srcStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamCopyAttributes_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetAttribute_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "attr: #{defi["attr"]}"
  s << ', '
  s << "value: #{"0x%016x" % defi["value"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamGetAttribute_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "value_val: #{defi["value_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamSetAttribute_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "attr: #{defi["attr"]}"
  s << ', '
  s << "param: #{"0x%016x" % defi["param"]}"
  s << ', '
  s << "param_val: #{defi["param_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamSetAttribute_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuIpcOpenMemHandle_entry"] = lambda { |defi|
  s = "{ "
  s << "pdptr: #{"0x%016x" % defi["pdptr"]}"
  s << ', '
  s << "handle: #{defi["handle"].size > 0 ? CUDA::CUIPCMemHandleV1.new(FFI::MemoryPointer.from_string(defi["handle"])) : nil}"
  s << ', '
  s << "Flags: #{defi["Flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuIpcOpenMemHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pdptr_val: #{"0x%016x" % defi["pdptr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphInstantiate_entry"] = lambda { |defi|
  s = "{ "
  s << "phGraphExec: #{"0x%016x" % defi["phGraphExec"]}"
  s << ', '
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "phErrorNode: #{"0x%016x" % defi["phErrorNode"]}"
  s << ', '
  s << "logBuffer: #{"0x%016x" % defi["logBuffer"]}"
  s << ', '
  s << "bufferSize: #{defi["bufferSize"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphInstantiate_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phGraphExec_val: #{"0x%016x" % defi["phGraphExec_val"]}"
  s << ', '
  s << "phErrorNode_val: #{"0x%016x" % defi["phErrorNode_val"]}"
  s << ', '
  s << "logBuffer_vals: #{defi["logBuffer_vals"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphInstantiate_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "phGraphExec: #{"0x%016x" % defi["phGraphExec"]}"
  s << ', '
  s << "hGraph: #{"0x%016x" % defi["hGraph"]}"
  s << ', '
  s << "phErrorNode: #{"0x%016x" % defi["phErrorNode"]}"
  s << ', '
  s << "logBuffer: #{"0x%016x" % defi["logBuffer"]}"
  s << ', '
  s << "bufferSize: #{defi["bufferSize"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphInstantiate_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phGraphExec_val: #{"0x%016x" % defi["phGraphExec_val"]}"
  s << ', '
  s << "phErrorNode_val: #{"0x%016x" % defi["phErrorNode_val"]}"
  s << ', '
  s << "logBuffer_vals: #{defi["logBuffer_vals"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemMapArrayAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "mapInfoList: #{"0x%016x" % defi["mapInfoList"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "mapInfoList_vals: [ #{p = FFI::MemoryPointer.from_string(defi["mapInfoList_vals"]); sz = CUDA::CUArrayMapInfoV1.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUArrayMapInfoV1.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemMapArrayAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemFreeAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "dptr: #{"0x%016x" % defi["dptr"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemFreeAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemAllocAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "dptr: #{"0x%016x" % defi["dptr"]}"
  s << ', '
  s << "bytesize: #{defi["bytesize"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemAllocAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "dptr_val: #{"0x%016x" % defi["dptr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemAllocFromPoolAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "dptr: #{"0x%016x" % defi["dptr"]}"
  s << ', '
  s << "bytesize: #{defi["bytesize"]}"
  s << ', '
  s << "pool: #{"0x%016x" % defi["pool"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemAllocFromPoolAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "dptr_val: #{"0x%016x" % defi["dptr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamUpdateCaptureDependencies_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "dependencies: #{"0x%016x" % defi["dependencies"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "dependencies_vals: [ #{defi["dependencies_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamUpdateCaptureDependencies_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamUpdateCaptureDependencies_ptsz_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "dependencies: #{"0x%016x" % defi["dependencies"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "dependencies_vals: [ #{defi["dependencies_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamUpdateCaptureDependencies_ptsz_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamUpdateCaptureDependencies_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "dependencies: #{"0x%016x" % defi["dependencies"]}"
  s << ', '
  s << "dependencyData: #{"0x%016x" % defi["dependencyData"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "dependencies_vals: [ #{defi["dependencies_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "dependencyData_vals: [ #{p = FFI::MemoryPointer.from_string(defi["dependencyData_vals"]); sz = CUDA::CUGraphEdgeData.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUGraphEdgeData.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuStreamUpdateCaptureDependencies_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemBatchDecompressAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "paramsArray: #{"0x%016x" % defi["paramsArray"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "errorIndex: #{"0x%016x" % defi["errorIndex"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "paramsArray_vals: [ #{p = FFI::MemoryPointer.from_string(defi["paramsArray_vals"]); sz = CUDA::CUMemDecompressParams.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUMemDecompressParams.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuMemBatchDecompressAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "errorIndex_val: #{defi["errorIndex_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGetProcAddress_entry"] = lambda { |defi|
  s = "{ "
  s << "symbol: #{"0x%016x" % defi["symbol"]}"
  s << ', '
  s << "pfn: #{"0x%016x" % defi["pfn"]}"
  s << ', '
  s << "cudaVersion: #{defi["cudaVersion"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "symbol_val: #{defi["symbol_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGetProcAddress_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pfn_val: #{"0x%016x" % defi["pfn_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCheckpointProcessGetRestoreThreadId_entry"] = lambda { |defi|
  s = "{ "
  s << "pid: #{defi["pid"]}"
  s << ', '
  s << "tid: #{"0x%016x" % defi["tid"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCheckpointProcessGetRestoreThreadId_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "tid_val: #{defi["tid_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCheckpointProcessGetState_entry"] = lambda { |defi|
  s = "{ "
  s << "pid: #{defi["pid"]}"
  s << ', '
  s << "state: #{"0x%016x" % defi["state"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCheckpointProcessGetState_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "state_val: #{CUDA::CUProcessState.from_native(defi["state_val"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCheckpointProcessLock_entry"] = lambda { |defi|
  s = "{ "
  s << "pid: #{defi["pid"]}"
  s << ', '
  s << "args: #{"0x%016x" % defi["args"]}"
  s << ', '
  s << "args_val: #{defi["args_val"].size > 0 ? CUDA::CUCheckpointLockArgs.new(FFI::MemoryPointer.from_string(defi["args_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCheckpointProcessLock_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCheckpointProcessCheckpoint_entry"] = lambda { |defi|
  s = "{ "
  s << "pid: #{defi["pid"]}"
  s << ', '
  s << "args: #{"0x%016x" % defi["args"]}"
  s << ', '
  s << "args_val: #{defi["args_val"].size > 0 ? CUDA::CUCheckpointCheckpointArgs.new(FFI::MemoryPointer.from_string(defi["args_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCheckpointProcessCheckpoint_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCheckpointProcessRestore_entry"] = lambda { |defi|
  s = "{ "
  s << "pid: #{defi["pid"]}"
  s << ', '
  s << "args: #{"0x%016x" % defi["args"]}"
  s << ', '
  s << "args_val: #{defi["args_val"].size > 0 ? CUDA::CUCheckpointRestoreArgs.new(FFI::MemoryPointer.from_string(defi["args_val"])) : nil}"
  s << ', '
  s << "args__gpuPairs_vals: [ #{p = FFI::MemoryPointer.from_string(defi["args__gpuPairs_vals"]); sz = CUDA::CUCheckpointGpuPair.size; n = p.size / sz; (0...n).collect { |i| CUDA::CUCheckpointGpuPair.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCheckpointProcessRestore_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCheckpointProcessUnlock_entry"] = lambda { |defi|
  s = "{ "
  s << "pid: #{defi["pid"]}"
  s << ', '
  s << "args: #{"0x%016x" % defi["args"]}"
  s << ', '
  s << "args_val: #{defi["args_val"].size > 0 ? CUDA::CUCheckpointUnlockArgs.new(FFI::MemoryPointer.from_string(defi["args_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuCheckpointProcessUnlock_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuVDPAUGetDevice_entry"] = lambda { |defi|
  s = "{ "
  s << "pDevice: #{"0x%016x" % defi["pDevice"]}"
  s << ', '
  s << "vdpDevice: #{defi["vdpDevice"]}"
  s << ', '
  s << "vdpGetProcAddress: #{"0x%016x" % defi["vdpGetProcAddress"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuVDPAUGetDevice_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuVDPAUCtxCreate_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "pCtx: #{"0x%016x" % defi["pCtx"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "device: #{defi["device"]}"
  s << ', '
  s << "vdpDevice: #{defi["vdpDevice"]}"
  s << ', '
  s << "vdpGetProcAddress: #{"0x%016x" % defi["vdpGetProcAddress"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuVDPAUCtxCreate_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphicsVDPAURegisterVideoSurface_entry"] = lambda { |defi|
  s = "{ "
  s << "pCudaResource: #{"0x%016x" % defi["pCudaResource"]}"
  s << ', '
  s << "vdpSurface: #{defi["vdpSurface"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphicsVDPAURegisterVideoSurface_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphicsVDPAURegisterOutputSurface_entry"] = lambda { |defi|
  s = "{ "
  s << "pCudaResource: #{"0x%016x" % defi["pCudaResource"]}"
  s << ', '
  s << "vdpSurface: #{defi["vdpSurface"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuGraphicsVDPAURegisterOutputSurface_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuVDPAUCtxCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "pCtx: #{"0x%016x" % defi["pCtx"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "device: #{defi["device"]}"
  s << ', '
  s << "vdpDevice: #{defi["vdpDevice"]}"
  s << ', '
  s << "vdpGetProcAddress: #{"0x%016x" % defi["vdpGetProcAddress"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuVDPAUCtxCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuProfilerInitialize_entry"] = lambda { |defi|
  s = "{ "
  s << "configFile: #{"0x%016x" % defi["configFile"]}"
  s << ', '
  s << "outputFile: #{"0x%016x" % defi["outputFile"]}"
  s << ', '
  s << "outputMode: #{CUDA::CUOutputMode.from_native(defi["outputMode"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuProfilerInitialize_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuProfilerStart_entry"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuProfilerStart_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuProfilerStop_entry"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_cuda:cuProfilerStop_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_function_get_name_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "hFunction: #{"0x%016x" % defi["hFunction"]}"
  s << ', '
  s << "pName: #{"0x%016x" % defi["pName"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_function_get_name_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pName_val: #{"0x%016x" % defi["pName_val"]}"
  s << ', '
  s << "pName_val_val: #{defi["pName_val_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexpFunction_setCacheConfig_entry"] = lambda { |defi|
  s = "{ "
  s << "hFunction: #{"0x%016x" % defi["hFunction"]}"
  s << ', '
  s << "config: #{CUDA::CUFuncCache.from_native(defi["config"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexpFunction_setCacheConfig_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_6e163fbe_d8_entry"] = lambda { |defi|
  s = "{ "
  s << "hModule: #{"0x%016x" % defi["hModule"]}"
  s << ', '
  s << "pB: #{"0x%016x" % defi["pB"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_6e163fbe_d8_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pB_val: #{defi["pB_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexpFunction_get_arg_count_entry"] = lambda { |defi|
  s = "{ "
  s << "hFunction: #{"0x%016x" % defi["hFunction"]}"
  s << ', '
  s << "pArgCount: #{"0x%016x" % defi["pArgCount"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexpFunction_get_arg_count_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pArgCount_val: #{defi["pArgCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexpFunction_get_arg_descriptor_entry"] = lambda { |defi|
  s = "{ "
  s << "hFunction: #{"0x%016x" % defi["hFunction"]}"
  s << ', '
  s << "argIndex: #{defi["argIndex"]}"
  s << ', '
  s << "pArgDescQuery: #{"0x%016x" % defi["pArgDescQuery"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexpFunction_get_arg_descriptor_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pArgDescQuery_val: #{defi["pArgDescQuery_val"].size > 0 ? CUDA::CuexpFunctionArgDescQuery.new(FFI::MemoryPointer.from_string(defi["pArgDescQuery_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_6e163fbe_130_entry"] = lambda { |defi|
  s = "{ "
  s << "pA: #{"0x%016x" % defi["pA"]}"
  s << ', '
  s << "hFunction: #{"0x%016x" % defi["hFunction"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_6e163fbe_130_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pA_val: #{"0x%016x" % defi["pA_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_module_iterate_on_functions_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "hModule: #{"0x%016x" % defi["hModule"]}"
  s << ', '
  s << "pFunc: #{"0x%016x" % defi["pFunc"]}"
  s << ', '
  s << "userData: #{"0x%016x" % defi["userData"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_module_iterate_on_functions_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_6e163fbe_1a8_entry"] = lambda { |defi|
  s = "{ "
  s << "hFunction: #{"0x%016x" % defi["hFunction"]}"
  s << ', '
  s << "pB: #{"0x%016x" % defi["pB"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_6e163fbe_1a8_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pB_val: #{defi["pB_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_6e163fbe_1b8_entry"] = lambda { |defi|
  s = "{ "
  s << "hFunction: #{"0x%016x" % defi["hFunction"]}"
  s << ', '
  s << "pB: #{"0x%016x" % defi["pB"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_6e163fbe_1b8_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pB_val: #{defi["pB_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexpDevice_get_primary_context_refcount_entry"] = lambda { |defi|
  s = "{ "
  s << "device: #{defi["device"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexpDevice_get_primary_context_refcount_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{defi["cuResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_get_thread_context_entry"] = lambda { |defi|
  s = "{ "
  s << "phContext: #{"0x%016x" % defi["phContext"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_get_thread_context_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phContext_val: #{"0x%016x" % defi["phContext_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_a094798c_08_entry"] = lambda { |defi|
  s = "{ "
  s << "a: #{defi["a"]}"
  s << ', '
  s << "b: #{"0x%016x" % defi["b"]}"
  s << ', '
  s << "b_val: #{"0x%016x" % defi["b_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_a094798c_08_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "b_val: #{"0x%016x" % defi["b_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_a094798c_10_entry"] = lambda { |defi|
  s = "{ "
  s << "a: #{"0x%016x" % defi["a"]}"
  s << ', '
  s << "b: #{"0x%016x" % defi["b"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_a094798c_10_exit"] = lambda { |defi|
  s = "{ "
  s << "a_val: #{"0x%016x" % defi["a_val"]}"
  s << ', '
  s << "b_val: #{defi["b_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_a094798c_18_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "a: #{"0x%016x" % defi["a"]}"
  s << ', '
  s << "b: #{"0x%016x" % defi["b"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_a094798c_18_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "b_val: #{"0x%016x" % defi["b_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_a094798c_20_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "b: #{"0x%016x" % defi["b"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_a094798c_20_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "b_val: #{defi["b_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_a094798c_28_entry"] = lambda { |defi|
  s = "{ "
  s << "a: #{defi["a"]}"
  s << ', '
  s << "b: #{"0x%016x" % defi["b"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_a094798c_28_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_a094798c_30_entry"] = lambda { |defi|
  s = "{ "
  s << "a: #{"0x%016x" % defi["a"]}"
  s << ', '
  s << "b: #{"0x%016x" % defi["b"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_a094798c_30_exit"] = lambda { |defi|
  s = "{ "
  s << "a_val: #{"0x%016x" % defi["a_val"]}"
  s << ', '
  s << "b_val: #{defi["b_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexpContext_kvstore_add_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << ', '
  s << "value: #{"0x%016x" % defi["value"]}"
  s << ', '
  s << "unknown: #{"0x%016x" % defi["unknown"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexpContext_kvstore_add_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexpContext_kvstore_delete_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexpContext_kvstore_delete_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexpContext_kvstore_get_entry"] = lambda { |defi|
  s = "{ "
  s << "value: #{"0x%016x" % defi["value"]}"
  s << ', '
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexpContext_kvstore_get_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "value_val: #{"0x%016x" % defi["value_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_get_primary_context_entry"] = lambda { |defi|
  s = "{ "
  s << "phContext: #{"0x%016x" % defi["phContext"]}"
  s << ', '
  s << "ordinal: #{defi["ordinal"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_get_primary_context_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phContext_val: #{"0x%016x" % defi["phContext_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_register_module_entry"] = lambda { |defi|
  s = "{ "
  s << "phModule: #{"0x%016x" % defi["phModule"]}"
  s << ', '
  s << "fatBinary: #{"0x%016x" % defi["fatBinary"]}"
  s << ', '
  s << "a: #{"0x%016x" % defi["a"]}"
  s << ', '
  s << "b: #{"0x%016x" % defi["b"]}"
  s << ', '
  s << "ordinal: #{defi["ordinal"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_register_module_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "phModule_val: #{"0x%016x" % defi["phModule_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_unregister_module_entry"] = lambda { |defi|
  s = "{ "
  s << "fatBinary: #{"0x%016x" % defi["fatBinary"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_unregister_module_exit"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexpContext_getDevice_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "pDevice: #{"0x%016x" % defi["pDevice"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexpContext_getDevice_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pDevice_val: #{defi["pDevice_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexpContext_getContextNumber_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "contextNumber: #{"0x%016x" % defi["contextNumber"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexpContext_getContextNumber_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "contextNumber_val: #{defi["contextNumber_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_21318c60_80_entry"] = lambda { |defi|
  s = "{ "
  s << "a: #{"0x%016x" % defi["a"]}"
  s << ', '
  s << "pB: #{"0x%016x" % defi["pB"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_21318c60_80_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pB_val: #{"0x%016x" % defi["pB_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_21318c60_138_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "b: #{"0x%016x" % defi["b"]}"
  s << ', '
  s << "pC: #{"0x%016x" % defi["pC"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_21318c60_138_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pC_val: #{"0x%016x" % defi["pC_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexpDevice_get_entry"] = lambda { |defi|
  s = "{ "
  s << "pDevice: #{"0x%016x" % defi["pDevice"]}"
  s << ', '
  s << "ordinal: #{defi["ordinal"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexpDevice_get_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pDevice_val: #{defi["pDevice_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexpDevice_getCount_entry"] = lambda { |defi|
  s = "{ "
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexpDevice_getCount_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexpDevice_getAttribute_entry"] = lambda { |defi|
  s = "{ "
  s << "ordinal: #{defi["ordinal"]}"
  s << ', '
  s << "attrib: #{CUDA::CUDeviceAttribute.from_native(defi["attrib"], nil)}"
  s << ', '
  s << "flag: #{defi["flag"]}"
  s << ', '
  s << "pl: #{"0x%016x" % defi["pl"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexpDevice_getAttribute_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pl_val: #{defi["pl_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_b10541e1_30_entry"] = lambda { |defi|
  s = "{ "
  s << "device: #{defi["device"]}"
  s << ', '
  s << "pB: #{"0x%016x" % defi["pB"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_b10541e1_30_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pB_val: #{"0x%016x" % defi["pB_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_b10541e1_40_entry"] = lambda { |defi|
  s = "{ "
  s << "pRes: #{"0x%016x" % defi["pRes"]}"
  s << ', '
  s << "device: #{defi["device"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_b10541e1_40_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pRes_val: #{defi["pRes_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_a6b1ff99_28_entry"] = lambda { |defi|
  s = "{ "
  s << "a: #{"0x%016x" % defi["a"]}"
  s << ', '
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_a6b1ff99_28_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "a_val: #{"0x%016x" % defi["a_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_127d4831_28_entry"] = lambda { |defi|
  s = "{ "
  s << "h: #{"0x%016x" % defi["h"]}"
  s << ', '
  s << "a: #{defi["a"]}"
  s << ', '
  s << "pB: #{"0x%016x" % defi["pB"]}"
  s << ', '
  s << "param_4: #{"0x%016x" % defi["param_4"]}"
  s << ', '
  s << "pB_val: #{"0x%016x" % defi["pB_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_127d4831_28_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pB_val: #{"0x%016x" % defi["pB_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_127d4831_30_entry"] = lambda { |defi|
  s = "{ "
  s << "h: #{"0x%016x" % defi["h"]}"
  s << ', '
  s << "a: #{defi["a"]}"
  s << ', '
  s << "pB: #{"0x%016x" % defi["pB"]}"
  s << ', '
  s << "pB_val: #{"0x%016x" % defi["pB_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_127d4831_30_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pB_val: #{"0x%016x" % defi["pB_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexpCUPTI_init_entry"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexpCUPTI_init_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_7cb63f9b_1e0_entry"] = lambda { |defi|
  s = "{ "
  s << "device: #{defi["device"]}"
  s << ', '
  s << "b: #{"0x%016x" % defi["b"]}"
  s << ', '
  s << "b_val: #{defi["b_val"].size > 0 ? CUDA::Cuexp7cb63f9b1e0Struct.new(FFI::MemoryPointer.from_string(defi["b_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_7cb63f9b_1e0_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "b_val: #{defi["b_val"].size > 0 ? CUDA::Cuexp7cb63f9b1e0Struct.new(FFI::MemoryPointer.from_string(defi["b_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_2c8e0ad8_18_entry"] = lambda { |defi|
  s = "{ "
  s << "pRes: #{"0x%016x" % defi["pRes"]}"
  s << ', '
  s << "a: #{"0x%016x" % defi["a"]}"
  s << ', '
  s << "b: #{"0x%016x" % defi["b"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_2c8e0ad8_18_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pRes_val: #{defi["pRes_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_2c8e0ad8_38_entry"] = lambda { |defi|
  s = "{ "
  s << "a: #{defi["a"]}"
  s << ', '
  s << "b: #{defi["b"]}"
  s << ', '
  s << "c: #{defi["c"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_2c8e0ad8_38_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_getCudaState_entry"] = lambda { |defi|
  s = "{ "
  s << "pState: #{"0x%016x" % defi["pState"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:cuexp_getCudaState_exit"] = lambda { |defi|
  s = "{ "
  s << "cuResult: #{CUDA::CUResult.from_native(defi["cuResult"], nil)}"
  s << ', '
  s << "pState_val: #{defi["pState_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_args:arg_count"] = lambda { |defi|
  s = "{ "
  s << "f: #{"0x%016x" % defi["f"]}"
  s << ', '
  s << "argCount: #{defi["argCount"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_args:arg_value"] = lambda { |defi|
  s = "{ "
  s << "f: #{"0x%016x" % defi["f"]}"
  s << ', '
  s << "argIndex: #{defi["argIndex"]}"
  s << ', '
  s << "kernelParam: #{"0x%016x" % defi["kernelParam"]}"
  s << ', '
  s << "kernelParam_val: #{defi["kernelParam_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_profiling:event_profiling"] = lambda { |defi|
  s = "{ "
  s << "hStart: #{"0x%016x" % defi["hStart"]}"
  s << ', '
  s << "hStop: #{"0x%016x" % defi["hStop"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_profiling:event_profiling_results"] = lambda { |defi|
  s = "{ "
  s << "hStart: #{"0x%016x" % defi["hStart"]}"
  s << ', '
  s << "hStop: #{"0x%016x" % defi["hStop"]}"
  s << ', '
  s << "startStatus: #{CUDA::CUResult.from_native(defi["startStatus"], nil)}"
  s << ', '
  s << "stopStatus: #{CUDA::CUResult.from_native(defi["stopStatus"], nil)}"
  s << ', '
  s << "status: #{CUDA::CUResult.from_native(defi["status"], nil)}"
  s << ', '
  s << "milliseconds: #{defi["milliseconds"]}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_exports:export_called"] = lambda { |defi|
  s = "{ "
  s << "pExportTableId: #{"0x%016x" % defi["pExportTableId"]}"
  s << ', '
  s << "exportOffset: #{"0x%016x" % defi["exportOffset"]}"
  s << ', '
  s << "pExportTableId_val: #{defi["pExportTableId_val"].size > 0 ? CUDA::CUUUID.new(FFI::MemoryPointer.from_string(defi["pExportTableId_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_cuda_properties:device"] = lambda { |defi|
  s = "{ "
  s << "ordinal: #{defi["ordinal"]}"
  s << ', '
  s << "device: #{"0x%016x" % defi["device"]}"
  s << ', '
  s << "name: #{defi["name"].inspect}"
  s << ', '
  s << "uuid: #{defi["uuid"].size > 0 ? CUDA::CUUUID.new(FFI::MemoryPointer.from_string(defi["uuid"])) : nil}"
  s << " }"
}
