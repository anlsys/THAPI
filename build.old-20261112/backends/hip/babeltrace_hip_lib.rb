require_relative 'hip_library.rb'
$event_lambdas["lttng_ust_hip:hipCreateChannelDesc_entry"] = lambda { |defi|
  s = "{ "
  s << "x: #{defi["x"]}"
  s << ', '
  s << "y: #{defi["y"]}"
  s << ', '
  s << "z: #{defi["z"]}"
  s << ', '
  s << "w: #{defi["w"]}"
  s << ', '
  s << "f: #{defi["f"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipCreateChannelDesc_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{defi["hipResult"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:__hipGetPCH_entry"] = lambda { |defi|
  s = "{ "
  s << "pch: #{"0x%016x" % defi["pch"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:__hipGetPCH_exit"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipInit_entry"] = lambda { |defi|
  s = "{ "
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipInit_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDriverGetVersion_entry"] = lambda { |defi|
  s = "{ "
  s << "driverVersion: #{"0x%016x" % defi["driverVersion"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDriverGetVersion_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "driverVersion_val: #{defi["driverVersion_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipRuntimeGetVersion_entry"] = lambda { |defi|
  s = "{ "
  s << "runtimeVersion: #{"0x%016x" % defi["runtimeVersion"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipRuntimeGetVersion_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "runtimeVersion_val: #{defi["runtimeVersion_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceGet_entry"] = lambda { |defi|
  s = "{ "
  s << "device: #{"0x%016x" % defi["device"]}"
  s << ', '
  s << "ordinal: #{defi["ordinal"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceGet_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "device_val: #{defi["device_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceComputeCapability_entry"] = lambda { |defi|
  s = "{ "
  s << "major: #{"0x%016x" % defi["major"]}"
  s << ', '
  s << "minor: #{"0x%016x" % defi["minor"]}"
  s << ', '
  s << "device: #{defi["device"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceComputeCapability_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "major_val: #{defi["major_val"]}"
  s << ', '
  s << "minor_val: #{defi["minor_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceGetName_entry"] = lambda { |defi|
  s = "{ "
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "len: #{defi["len"]}"
  s << ', '
  s << "device: #{defi["device"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceGetName_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "name_val: #{defi["name_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceGetUuid_entry"] = lambda { |defi|
  s = "{ "
  s << "uuid: #{"0x%016x" % defi["uuid"]}"
  s << ', '
  s << "device: #{defi["device"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceGetUuid_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "uuid_val: #{defi["uuid_val"].size > 0 ? HIP::HipUUID.new(FFI::MemoryPointer.from_string(defi["uuid_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceGetP2PAttribute_entry"] = lambda { |defi|
  s = "{ "
  s << "value: #{"0x%016x" % defi["value"]}"
  s << ', '
  s << "attr: #{HIP::HipDeviceP2PAttr.from_native(defi["attr"], nil)}"
  s << ', '
  s << "srcDevice: #{defi["srcDevice"]}"
  s << ', '
  s << "dstDevice: #{defi["dstDevice"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceGetP2PAttribute_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "value_val: #{defi["value_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceGetPCIBusId_entry"] = lambda { |defi|
  s = "{ "
  s << "pciBusId: #{"0x%016x" % defi["pciBusId"]}"
  s << ', '
  s << "len: #{defi["len"]}"
  s << ', '
  s << "device: #{defi["device"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceGetPCIBusId_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pciBusId_val: #{defi["pciBusId_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceGetByPCIBusId_entry"] = lambda { |defi|
  s = "{ "
  s << "device: #{"0x%016x" % defi["device"]}"
  s << ', '
  s << "pciBusId: #{"0x%016x" % defi["pciBusId"]}"
  s << ', '
  s << "pciBusId_val: #{defi["pciBusId_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceGetByPCIBusId_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "device_val: #{defi["device_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceTotalMem_entry"] = lambda { |defi|
  s = "{ "
  s << "bytes: #{"0x%016x" % defi["bytes"]}"
  s << ', '
  s << "device: #{defi["device"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceTotalMem_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "bytes_val: #{defi["bytes_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceSynchronize_entry"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceSynchronize_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceReset_entry"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceReset_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipSetDevice_entry"] = lambda { |defi|
  s = "{ "
  s << "deviceId: #{defi["deviceId"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipSetDevice_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGetDevice_entry"] = lambda { |defi|
  s = "{ "
  s << "deviceId: #{"0x%016x" % defi["deviceId"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGetDevice_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "deviceId_val: #{defi["deviceId_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGetDeviceCount_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{"0x%016x" % defi["count"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGetDeviceCount_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "count_val: #{defi["count_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceGetAttribute_entry"] = lambda { |defi|
  s = "{ "
  s << "pi: #{"0x%016x" % defi["pi"]}"
  s << ', '
  s << "attr: #{HIP::HipDeviceAttribute_t.from_native(defi["attr"], nil)}"
  s << ', '
  s << "deviceId: #{defi["deviceId"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceGetAttribute_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pi_val: #{defi["pi_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceGetDefaultMemPool_entry"] = lambda { |defi|
  s = "{ "
  s << "mem_pool: #{"0x%016x" % defi["mem_pool"]}"
  s << ', '
  s << "device: #{defi["device"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceGetDefaultMemPool_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "mem_pool_val: #{"0x%016x" % defi["mem_pool_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceSetMemPool_entry"] = lambda { |defi|
  s = "{ "
  s << "device: #{defi["device"]}"
  s << ', '
  s << "mem_pool: #{"0x%016x" % defi["mem_pool"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceSetMemPool_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceGetMemPool_entry"] = lambda { |defi|
  s = "{ "
  s << "mem_pool: #{"0x%016x" % defi["mem_pool"]}"
  s << ', '
  s << "device: #{defi["device"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceGetMemPool_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "mem_pool_val: #{"0x%016x" % defi["mem_pool_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGetDeviceProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "prop: #{"0x%016x" % defi["prop"]}"
  s << ', '
  s << "deviceId: #{defi["deviceId"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGetDeviceProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "prop_val: #{defi["prop_val"].size > 0 ? HIP::HipDeviceProp_t.new(FFI::MemoryPointer.from_string(defi["prop_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceSetCacheConfig_entry"] = lambda { |defi|
  s = "{ "
  s << "cacheConfig: #{HIP::HipFuncCache_t.from_native(defi["cacheConfig"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceSetCacheConfig_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceGetCacheConfig_entry"] = lambda { |defi|
  s = "{ "
  s << "cacheConfig: #{"0x%016x" % defi["cacheConfig"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceGetCacheConfig_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "cacheConfig_val: #{HIP::HipFuncCache_t.from_native(defi["cacheConfig_val"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceGetLimit_entry"] = lambda { |defi|
  s = "{ "
  s << "pValue: #{"0x%016x" % defi["pValue"]}"
  s << ', '
  s << "limit: #{defi["limit"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceGetLimit_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pValue_val: #{defi["pValue_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceSetLimit_entry"] = lambda { |defi|
  s = "{ "
  s << "limit: #{defi["limit"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceSetLimit_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceGetSharedMemConfig_entry"] = lambda { |defi|
  s = "{ "
  s << "pConfig: #{"0x%016x" % defi["pConfig"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceGetSharedMemConfig_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pConfig_val: #{HIP::HipSharedMemConfig.from_native(defi["pConfig_val"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGetDeviceFlags_entry"] = lambda { |defi|
  s = "{ "
  s << "flags: #{"0x%016x" % defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGetDeviceFlags_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "flags_val: #{defi["flags_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceSetSharedMemConfig_entry"] = lambda { |defi|
  s = "{ "
  s << "config: #{HIP::HipSharedMemConfig.from_native(defi["config"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceSetSharedMemConfig_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipSetDeviceFlags_entry"] = lambda { |defi|
  s = "{ "
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipSetDeviceFlags_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipChooseDevice_entry"] = lambda { |defi|
  s = "{ "
  s << "device: #{"0x%016x" % defi["device"]}"
  s << ', '
  s << "prop: #{"0x%016x" % defi["prop"]}"
  s << ', '
  s << "prop_val: #{defi["prop_val"].size > 0 ? HIP::HipDeviceProp_t.new(FFI::MemoryPointer.from_string(defi["prop_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipChooseDevice_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "device_val: #{defi["device_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipExtGetLinkTypeAndHopCount_entry"] = lambda { |defi|
  s = "{ "
  s << "device1: #{defi["device1"]}"
  s << ', '
  s << "device2: #{defi["device2"]}"
  s << ', '
  s << "linktype: #{"0x%016x" % defi["linktype"]}"
  s << ', '
  s << "hopcount: #{"0x%016x" % defi["hopcount"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipExtGetLinkTypeAndHopCount_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "linktype_val: #{defi["linktype_val"]}"
  s << ', '
  s << "hopcount_val: #{defi["hopcount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipIpcGetMemHandle_entry"] = lambda { |defi|
  s = "{ "
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << ', '
  s << "devPtr: #{"0x%016x" % defi["devPtr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipIpcGetMemHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "handle_val: #{defi["handle_val"].size > 0 ? HIP::HipIpcMemHandle_t.new(FFI::MemoryPointer.from_string(defi["handle_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipIpcOpenMemHandle_entry"] = lambda { |defi|
  s = "{ "
  s << "devPtr: #{"0x%016x" % defi["devPtr"]}"
  s << ', '
  s << "handle: #{defi["handle"].size > 0 ? HIP::HipIpcMemHandle_t.new(FFI::MemoryPointer.from_string(defi["handle"])) : nil}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipIpcOpenMemHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "devPtr_val: #{"0x%016x" % defi["devPtr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipIpcCloseMemHandle_entry"] = lambda { |defi|
  s = "{ "
  s << "devPtr: #{"0x%016x" % defi["devPtr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipIpcCloseMemHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipIpcGetEventHandle_entry"] = lambda { |defi|
  s = "{ "
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << ', '
  s << "event: #{"0x%016x" % defi["event"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipIpcGetEventHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "handle_val: #{defi["handle_val"].size > 0 ? HIP::HipIpcEventHandle_t.new(FFI::MemoryPointer.from_string(defi["handle_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipIpcOpenEventHandle_entry"] = lambda { |defi|
  s = "{ "
  s << "event: #{"0x%016x" % defi["event"]}"
  s << ', '
  s << "handle: #{defi["handle"].size > 0 ? HIP::HipIpcEventHandle_t.new(FFI::MemoryPointer.from_string(defi["handle"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipIpcOpenEventHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "event_val: #{"0x%016x" % defi["event_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipFuncSetAttribute_entry"] = lambda { |defi|
  s = "{ "
  s << "func: #{"0x%016x" % defi["func"]}"
  s << ', '
  s << "attr: #{HIP::HipFuncAttribute.from_native(defi["attr"], nil)}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipFuncSetAttribute_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipFuncSetCacheConfig_entry"] = lambda { |defi|
  s = "{ "
  s << "func: #{"0x%016x" % defi["func"]}"
  s << ', '
  s << "config: #{HIP::HipFuncCache_t.from_native(defi["config"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipFuncSetCacheConfig_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipFuncSetSharedMemConfig_entry"] = lambda { |defi|
  s = "{ "
  s << "func: #{"0x%016x" % defi["func"]}"
  s << ', '
  s << "config: #{HIP::HipSharedMemConfig.from_native(defi["config"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipFuncSetSharedMemConfig_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGetLastError_entry"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGetLastError_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipPeekAtLastError_entry"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipPeekAtLastError_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGetErrorName_entry"] = lambda { |defi|
  s = "{ "
  s << "hip_error: #{HIP::HipError_t.from_native(defi["hip_error"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGetErrorName_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{"0x%016x" % defi["hipResult"]}"
  s << ', '
  s << "hipResult_val: #{defi["hipResult_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGetErrorString_entry"] = lambda { |defi|
  s = "{ "
  s << "hipError: #{HIP::HipError_t.from_native(defi["hipError"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGetErrorString_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{"0x%016x" % defi["hipResult"]}"
  s << ', '
  s << "hipResult_val: #{defi["hipResult_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDrvGetErrorName_entry"] = lambda { |defi|
  s = "{ "
  s << "hipError: #{HIP::HipError_t.from_native(defi["hipError"], nil)}"
  s << ', '
  s << "errorString: #{"0x%016x" % defi["errorString"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDrvGetErrorName_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "errorString_val: #{"0x%016x" % defi["errorString_val"]}"
  s << ', '
  s << "errorString_val_val: #{defi["errorString_val_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDrvGetErrorString_entry"] = lambda { |defi|
  s = "{ "
  s << "hipError: #{HIP::HipError_t.from_native(defi["hipError"], nil)}"
  s << ', '
  s << "errorString: #{"0x%016x" % defi["errorString"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDrvGetErrorString_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "errorString_val: #{"0x%016x" % defi["errorString_val"]}"
  s << ', '
  s << "errorString_val_val: #{defi["errorString_val_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "stream_val: #{"0x%016x" % defi["stream_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamCreateWithFlags_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamCreateWithFlags_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "stream_val: #{"0x%016x" % defi["stream_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamCreateWithPriority_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "priority: #{defi["priority"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamCreateWithPriority_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "stream_val: #{"0x%016x" % defi["stream_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceGetStreamPriorityRange_entry"] = lambda { |defi|
  s = "{ "
  s << "leastPriority: #{"0x%016x" % defi["leastPriority"]}"
  s << ', '
  s << "greatestPriority: #{"0x%016x" % defi["greatestPriority"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceGetStreamPriorityRange_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "leastPriority_val: #{defi["leastPriority_val"]}"
  s << ', '
  s << "greatestPriority_val: #{defi["greatestPriority_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamQuery_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamQuery_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamSynchronize_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamSynchronize_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamWaitEvent_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "event: #{"0x%016x" % defi["event"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamWaitEvent_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamGetFlags_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "flags: #{"0x%016x" % defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamGetFlags_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "flags_val: #{defi["flags_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamGetPriority_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "priority: #{"0x%016x" % defi["priority"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamGetPriority_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "priority_val: #{defi["priority_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipExtStreamCreateWithCUMask_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "cuMaskSize: #{defi["cuMaskSize"]}"
  s << ', '
  s << "cuMask: #{"0x%016x" % defi["cuMask"]}"
  s << ', '
  s << "cuMask_vals: #{defi["cuMask_vals"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipExtStreamCreateWithCUMask_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "stream_val: #{"0x%016x" % defi["stream_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipExtStreamGetCUMask_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "cuMaskSize: #{defi["cuMaskSize"]}"
  s << ', '
  s << "cuMask: #{"0x%016x" % defi["cuMask"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipExtStreamGetCUMask_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "cuMask_vals: #{defi["cuMask_vals"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamAddCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "callback: #{"0x%016x" % defi["callback"]}"
  s << ', '
  s << "userData: #{"0x%016x" % defi["userData"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamAddCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamWaitValue32_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "mask: #{defi["mask"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamWaitValue32_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamWaitValue64_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "mask: #{defi["mask"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamWaitValue64_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamWriteValue32_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamWriteValue32_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamWriteValue64_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamWriteValue64_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipEventCreateWithFlags_entry"] = lambda { |defi|
  s = "{ "
  s << "event: #{"0x%016x" % defi["event"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipEventCreateWithFlags_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "event_val: #{"0x%016x" % defi["event_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipEventCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "event: #{"0x%016x" % defi["event"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipEventCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "event_val: #{"0x%016x" % defi["event_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipEventRecord_entry"] = lambda { |defi|
  s = "{ "
  s << "event: #{"0x%016x" % defi["event"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipEventRecord_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipEventDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "event: #{"0x%016x" % defi["event"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipEventDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipEventSynchronize_entry"] = lambda { |defi|
  s = "{ "
  s << "event: #{"0x%016x" % defi["event"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipEventSynchronize_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipEventElapsedTime_entry"] = lambda { |defi|
  s = "{ "
  s << "ms: #{"0x%016x" % defi["ms"]}"
  s << ', '
  s << "start: #{"0x%016x" % defi["start"]}"
  s << ', '
  s << "stop: #{"0x%016x" % defi["stop"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipEventElapsedTime_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "ms_val: #{defi["ms_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipEventQuery_entry"] = lambda { |defi|
  s = "{ "
  s << "event: #{"0x%016x" % defi["event"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipEventQuery_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipPointerGetAttributes_entry"] = lambda { |defi|
  s = "{ "
  s << "attributes: #{"0x%016x" % defi["attributes"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipPointerGetAttributes_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "attributes_val: #{defi["attributes_val"].size > 0 ? HIP::HipPointerAttribute_t.new(FFI::MemoryPointer.from_string(defi["attributes_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipPointerGetAttribute_entry"] = lambda { |defi|
  s = "{ "
  s << "data: #{"0x%016x" % defi["data"]}"
  s << ', '
  s << "attribute: #{HIP::HipPointer_attribute.from_native(defi["attribute"], nil)}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipPointerGetAttribute_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "data_val: #{defi["data_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDrvPointerGetAttributes_entry"] = lambda { |defi|
  s = "{ "
  s << "numAttributes: #{defi["numAttributes"]}"
  s << ', '
  s << "attributes: #{"0x%016x" % defi["attributes"]}"
  s << ', '
  s << "data: #{"0x%016x" % defi["data"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDrvPointerGetAttributes_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipImportExternalSemaphore_entry"] = lambda { |defi|
  s = "{ "
  s << "extSem_out: #{"0x%016x" % defi["extSem_out"]}"
  s << ', '
  s << "semHandleDesc: #{"0x%016x" % defi["semHandleDesc"]}"
  s << ', '
  s << "semHandleDesc_val: #{defi["semHandleDesc_val"].size > 0 ? HIP::HipExternalSemaphoreHandleDesc.new(FFI::MemoryPointer.from_string(defi["semHandleDesc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipImportExternalSemaphore_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "extSem_out_val: #{"0x%016x" % defi["extSem_out_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipSignalExternalSemaphoresAsync_entry"] = lambda { |defi|
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
  s << "paramsArray_vals: [ #{p = FFI::MemoryPointer.from_string(defi["paramsArray_vals"]); sz = HIP::HipExternalSemaphoreSignalParams.size; n = p.size / sz; (0...n).collect { |i| HIP::HipExternalSemaphoreSignalParams.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipSignalExternalSemaphoresAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipWaitExternalSemaphoresAsync_entry"] = lambda { |defi|
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
  s << "paramsArray_vals: [ #{p = FFI::MemoryPointer.from_string(defi["paramsArray_vals"]); sz = HIP::HipExternalSemaphoreWaitParams.size; n = p.size / sz; (0...n).collect { |i| HIP::HipExternalSemaphoreWaitParams.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipWaitExternalSemaphoresAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDestroyExternalSemaphore_entry"] = lambda { |defi|
  s = "{ "
  s << "extSem: #{"0x%016x" % defi["extSem"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDestroyExternalSemaphore_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipImportExternalMemory_entry"] = lambda { |defi|
  s = "{ "
  s << "extMem_out: #{"0x%016x" % defi["extMem_out"]}"
  s << ', '
  s << "memHandleDesc: #{"0x%016x" % defi["memHandleDesc"]}"
  s << ', '
  s << "memHandleDesc_val: #{defi["memHandleDesc_val"].size > 0 ? HIP::HipExternalMemoryHandleDesc.new(FFI::MemoryPointer.from_string(defi["memHandleDesc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipImportExternalMemory_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "extMem_out_val: #{"0x%016x" % defi["extMem_out_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipExternalMemoryGetMappedBuffer_entry"] = lambda { |defi|
  s = "{ "
  s << "devPtr: #{"0x%016x" % defi["devPtr"]}"
  s << ', '
  s << "extMem: #{"0x%016x" % defi["extMem"]}"
  s << ', '
  s << "bufferDesc: #{"0x%016x" % defi["bufferDesc"]}"
  s << ', '
  s << "bufferDesc_val: #{defi["bufferDesc_val"].size > 0 ? HIP::HipExternalMemoryBufferDesc.new(FFI::MemoryPointer.from_string(defi["bufferDesc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipExternalMemoryGetMappedBuffer_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "devPtr_val: #{"0x%016x" % defi["devPtr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDestroyExternalMemory_entry"] = lambda { |defi|
  s = "{ "
  s << "extMem: #{"0x%016x" % defi["extMem"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDestroyExternalMemory_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMalloc_entry"] = lambda { |defi|
  s = "{ "
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMalloc_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "ptr_val: #{"0x%016x" % defi["ptr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipExtMallocWithFlags_entry"] = lambda { |defi|
  s = "{ "
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "sizeBytes: #{defi["sizeBytes"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipExtMallocWithFlags_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "ptr_val: #{"0x%016x" % defi["ptr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMallocHost_entry"] = lambda { |defi|
  s = "{ "
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMallocHost_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "ptr_val: #{"0x%016x" % defi["ptr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemAllocHost_entry"] = lambda { |defi|
  s = "{ "
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemAllocHost_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "ptr_val: #{"0x%016x" % defi["ptr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipHostMalloc_entry"] = lambda { |defi|
  s = "{ "
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipHostMalloc_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "ptr_val: #{"0x%016x" % defi["ptr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMallocManaged_entry"] = lambda { |defi|
  s = "{ "
  s << "dev_ptr: #{"0x%016x" % defi["dev_ptr"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMallocManaged_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "dev_ptr_val: #{"0x%016x" % defi["dev_ptr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemPrefetchAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "dev_ptr: #{"0x%016x" % defi["dev_ptr"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "device: #{defi["device"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemPrefetchAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemAdvise_entry"] = lambda { |defi|
  s = "{ "
  s << "dev_ptr: #{"0x%016x" % defi["dev_ptr"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "advice: #{HIP::HipMemoryAdvise.from_native(defi["advice"], nil)}"
  s << ', '
  s << "device: #{defi["device"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemAdvise_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemRangeGetAttribute_entry"] = lambda { |defi|
  s = "{ "
  s << "data: #{"0x%016x" % defi["data"]}"
  s << ', '
  s << "data_size: #{defi["data_size"]}"
  s << ', '
  s << "attribute: #{HIP::HipMemRangeAttribute.from_native(defi["attribute"], nil)}"
  s << ', '
  s << "dev_ptr: #{"0x%016x" % defi["dev_ptr"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemRangeGetAttribute_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "data_vals: #{defi["data_vals"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemRangeGetAttributes_entry"] = lambda { |defi|
  s = "{ "
  s << "data: #{"0x%016x" % defi["data"]}"
  s << ', '
  s << "data_sizes: #{"0x%016x" % defi["data_sizes"]}"
  s << ', '
  s << "attributes: #{"0x%016x" % defi["attributes"]}"
  s << ', '
  s << "num_attributes: #{defi["num_attributes"]}"
  s << ', '
  s << "dev_ptr: #{"0x%016x" % defi["dev_ptr"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "attributes_vals: #{defi["attributes_vals"]}"
  s << ', '
  s << "data_sizes_vals: #{defi["data_sizes_vals"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemRangeGetAttributes_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamAttachMemAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "dev_ptr: #{"0x%016x" % defi["dev_ptr"]}"
  s << ', '
  s << "length: #{defi["length"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamAttachMemAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMallocAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "dev_ptr: #{"0x%016x" % defi["dev_ptr"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMallocAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "dev_ptr_val: #{"0x%016x" % defi["dev_ptr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipFreeAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "dev_ptr: #{"0x%016x" % defi["dev_ptr"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipFreeAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemPoolTrimTo_entry"] = lambda { |defi|
  s = "{ "
  s << "mem_pool: #{"0x%016x" % defi["mem_pool"]}"
  s << ', '
  s << "min_bytes_to_hold: #{defi["min_bytes_to_hold"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemPoolTrimTo_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemPoolSetAttribute_entry"] = lambda { |defi|
  s = "{ "
  s << "mem_pool: #{"0x%016x" % defi["mem_pool"]}"
  s << ', '
  s << "attr: #{HIP::HipMemPoolAttr.from_native(defi["attr"], nil)}"
  s << ', '
  s << "value: #{"0x%016x" % defi["value"]}"
  s << ', '
  s << "value_val: #{defi["value_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemPoolSetAttribute_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemPoolGetAttribute_entry"] = lambda { |defi|
  s = "{ "
  s << "mem_pool: #{"0x%016x" % defi["mem_pool"]}"
  s << ', '
  s << "attr: #{HIP::HipMemPoolAttr.from_native(defi["attr"], nil)}"
  s << ', '
  s << "value: #{"0x%016x" % defi["value"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemPoolGetAttribute_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "value_val: #{defi["value_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemPoolSetAccess_entry"] = lambda { |defi|
  s = "{ "
  s << "mem_pool: #{"0x%016x" % defi["mem_pool"]}"
  s << ', '
  s << "desc_list: #{"0x%016x" % defi["desc_list"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "desc_list_vals: [ #{p = FFI::MemoryPointer.from_string(defi["desc_list_vals"]); sz = HIP::HipMemAccessDesc.size; n = p.size / sz; (0...n).collect { |i| HIP::HipMemAccessDesc.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemPoolSetAccess_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemPoolGetAccess_entry"] = lambda { |defi|
  s = "{ "
  s << "flags: #{"0x%016x" % defi["flags"]}"
  s << ', '
  s << "mem_pool: #{"0x%016x" % defi["mem_pool"]}"
  s << ', '
  s << "location: #{"0x%016x" % defi["location"]}"
  s << ', '
  s << "location_val: #{defi["location_val"].size > 0 ? HIP::HipMemLocation.new(FFI::MemoryPointer.from_string(defi["location_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemPoolGetAccess_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "flags_val: #{HIP::HipMemAccessFlags.from_native(defi["flags_val"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemPoolCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "mem_pool: #{"0x%016x" % defi["mem_pool"]}"
  s << ', '
  s << "pool_props: #{"0x%016x" % defi["pool_props"]}"
  s << ', '
  s << "pool_props_val: #{defi["pool_props_val"].size > 0 ? HIP::HipMemPoolProps.new(FFI::MemoryPointer.from_string(defi["pool_props_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemPoolCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "mem_pool_val: #{"0x%016x" % defi["mem_pool_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemPoolDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "mem_pool: #{"0x%016x" % defi["mem_pool"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemPoolDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMallocFromPoolAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "dev_ptr: #{"0x%016x" % defi["dev_ptr"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "mem_pool: #{"0x%016x" % defi["mem_pool"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMallocFromPoolAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "dev_ptr_val: #{"0x%016x" % defi["dev_ptr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemPoolExportToShareableHandle_entry"] = lambda { |defi|
  s = "{ "
  s << "shared_handle: #{"0x%016x" % defi["shared_handle"]}"
  s << ', '
  s << "mem_pool: #{"0x%016x" % defi["mem_pool"]}"
  s << ', '
  s << "handle_type: #{HIP::HipMemAllocationHandleType.from_native(defi["handle_type"], nil)}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemPoolExportToShareableHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "shared_handle_val: #{defi["shared_handle_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemPoolImportFromShareableHandle_entry"] = lambda { |defi|
  s = "{ "
  s << "mem_pool: #{"0x%016x" % defi["mem_pool"]}"
  s << ', '
  s << "shared_handle: #{"0x%016x" % defi["shared_handle"]}"
  s << ', '
  s << "handle_type: #{HIP::HipMemAllocationHandleType.from_native(defi["handle_type"], nil)}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "shared_handle_val: #{defi["shared_handle_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemPoolImportFromShareableHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "mem_pool_val: #{"0x%016x" % defi["mem_pool_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemPoolExportPointer_entry"] = lambda { |defi|
  s = "{ "
  s << "export_data: #{"0x%016x" % defi["export_data"]}"
  s << ', '
  s << "dev_ptr: #{"0x%016x" % defi["dev_ptr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemPoolExportPointer_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "export_data_val: #{defi["export_data_val"].size > 0 ? HIP::HipMemPoolPtrExportData.new(FFI::MemoryPointer.from_string(defi["export_data_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemPoolImportPointer_entry"] = lambda { |defi|
  s = "{ "
  s << "dev_ptr: #{"0x%016x" % defi["dev_ptr"]}"
  s << ', '
  s << "mem_pool: #{"0x%016x" % defi["mem_pool"]}"
  s << ', '
  s << "export_data: #{"0x%016x" % defi["export_data"]}"
  s << ', '
  s << "export_data_val: #{defi["export_data_val"].size > 0 ? HIP::HipMemPoolPtrExportData.new(FFI::MemoryPointer.from_string(defi["export_data_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemPoolImportPointer_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "dev_ptr_val: #{"0x%016x" % defi["dev_ptr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipHostAlloc_entry"] = lambda { |defi|
  s = "{ "
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipHostAlloc_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "ptr_val: #{"0x%016x" % defi["ptr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipHostGetDevicePointer_entry"] = lambda { |defi|
  s = "{ "
  s << "devPtr: #{"0x%016x" % defi["devPtr"]}"
  s << ', '
  s << "hstPtr: #{"0x%016x" % defi["hstPtr"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipHostGetDevicePointer_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "devPtr_val: #{"0x%016x" % defi["devPtr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipHostGetFlags_entry"] = lambda { |defi|
  s = "{ "
  s << "flagsPtr: #{"0x%016x" % defi["flagsPtr"]}"
  s << ', '
  s << "hostPtr: #{"0x%016x" % defi["hostPtr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipHostGetFlags_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "flagsPtr_val: #{defi["flagsPtr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipHostRegister_entry"] = lambda { |defi|
  s = "{ "
  s << "hostPtr: #{"0x%016x" % defi["hostPtr"]}"
  s << ', '
  s << "sizeBytes: #{defi["sizeBytes"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipHostRegister_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipHostUnregister_entry"] = lambda { |defi|
  s = "{ "
  s << "hostPtr: #{"0x%016x" % defi["hostPtr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipHostUnregister_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMallocPitch_entry"] = lambda { |defi|
  s = "{ "
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "pitch: #{"0x%016x" % defi["pitch"]}"
  s << ', '
  s << "width: #{defi["width"]}"
  s << ', '
  s << "height: #{defi["height"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMallocPitch_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "ptr_val: #{"0x%016x" % defi["ptr_val"]}"
  s << ', '
  s << "pitch_val: #{defi["pitch_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemAllocPitch_entry"] = lambda { |defi|
  s = "{ "
  s << "dptr: #{"0x%016x" % defi["dptr"]}"
  s << ', '
  s << "pitch: #{"0x%016x" % defi["pitch"]}"
  s << ', '
  s << "widthInBytes: #{defi["widthInBytes"]}"
  s << ', '
  s << "height: #{defi["height"]}"
  s << ', '
  s << "elementSizeBytes: #{defi["elementSizeBytes"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemAllocPitch_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "dptr_val: #{"0x%016x" % defi["dptr_val"]}"
  s << ', '
  s << "pitch_val: #{defi["pitch_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipFree_entry"] = lambda { |defi|
  s = "{ "
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipFree_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipFreeHost_entry"] = lambda { |defi|
  s = "{ "
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipFreeHost_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipHostFree_entry"] = lambda { |defi|
  s = "{ "
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipHostFree_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpy_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "sizeBytes: #{defi["sizeBytes"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpy_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyWithStream_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "sizeBytes: #{defi["sizeBytes"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyWithStream_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyHtoD_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "sizeBytes: #{defi["sizeBytes"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyHtoD_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyDtoH_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "sizeBytes: #{defi["sizeBytes"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyDtoH_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyDtoD_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "sizeBytes: #{defi["sizeBytes"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyDtoD_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyHtoDAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "sizeBytes: #{defi["sizeBytes"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyHtoDAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyDtoHAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "sizeBytes: #{defi["sizeBytes"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyDtoHAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyDtoDAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "sizeBytes: #{defi["sizeBytes"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyDtoDAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipModuleGetGlobal_entry"] = lambda { |defi|
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
$event_lambdas["lttng_ust_hip:hipModuleGetGlobal_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "dptr_val: #{"0x%016x" % defi["dptr_val"]}"
  s << ', '
  s << "bytes_val: #{defi["bytes_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGetSymbolAddress_entry"] = lambda { |defi|
  s = "{ "
  s << "devPtr: #{"0x%016x" % defi["devPtr"]}"
  s << ', '
  s << "symbol: #{"0x%016x" % defi["symbol"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGetSymbolAddress_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "devPtr_val: #{"0x%016x" % defi["devPtr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGetSymbolSize_entry"] = lambda { |defi|
  s = "{ "
  s << "size: #{"0x%016x" % defi["size"]}"
  s << ', '
  s << "symbol: #{"0x%016x" % defi["symbol"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGetSymbolSize_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "size_val: #{defi["size_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyToSymbol_entry"] = lambda { |defi|
  s = "{ "
  s << "symbol: #{"0x%016x" % defi["symbol"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "sizeBytes: #{defi["sizeBytes"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyToSymbol_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyToSymbolAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "symbol: #{"0x%016x" % defi["symbol"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "sizeBytes: #{defi["sizeBytes"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyToSymbolAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyFromSymbol_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "symbol: #{"0x%016x" % defi["symbol"]}"
  s << ', '
  s << "sizeBytes: #{defi["sizeBytes"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyFromSymbol_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyFromSymbolAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "symbol: #{"0x%016x" % defi["symbol"]}"
  s << ', '
  s << "sizeBytes: #{defi["sizeBytes"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyFromSymbolAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "sizeBytes: #{defi["sizeBytes"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemset_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "sizeBytes: #{defi["sizeBytes"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemset_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemsetD8_entry"] = lambda { |defi|
  s = "{ "
  s << "dest: #{"0x%016x" % defi["dest"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemsetD8_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemsetD8Async_entry"] = lambda { |defi|
  s = "{ "
  s << "dest: #{"0x%016x" % defi["dest"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemsetD8Async_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemsetD16_entry"] = lambda { |defi|
  s = "{ "
  s << "dest: #{"0x%016x" % defi["dest"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemsetD16_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemsetD16Async_entry"] = lambda { |defi|
  s = "{ "
  s << "dest: #{"0x%016x" % defi["dest"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemsetD16Async_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemsetD32_entry"] = lambda { |defi|
  s = "{ "
  s << "dest: #{"0x%016x" % defi["dest"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemsetD32_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemsetAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "sizeBytes: #{defi["sizeBytes"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemsetAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemsetD32Async_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemsetD32Async_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemset2D_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "pitch: #{defi["pitch"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "width: #{defi["width"]}"
  s << ', '
  s << "height: #{defi["height"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemset2D_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemset2DAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "pitch: #{defi["pitch"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "width: #{defi["width"]}"
  s << ', '
  s << "height: #{defi["height"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemset2DAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemset3D_entry"] = lambda { |defi|
  s = "{ "
  s << "pitchedDevPtr: #{defi["pitchedDevPtr"].size > 0 ? HIP::HipPitchedPtr.new(FFI::MemoryPointer.from_string(defi["pitchedDevPtr"])) : nil}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "extent: #{defi["extent"].size > 0 ? HIP::HipExtent.new(FFI::MemoryPointer.from_string(defi["extent"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemset3D_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemset3DAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "pitchedDevPtr: #{defi["pitchedDevPtr"].size > 0 ? HIP::HipPitchedPtr.new(FFI::MemoryPointer.from_string(defi["pitchedDevPtr"])) : nil}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "extent: #{defi["extent"].size > 0 ? HIP::HipExtent.new(FFI::MemoryPointer.from_string(defi["extent"])) : nil}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemset3DAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemGetInfo_entry"] = lambda { |defi|
  s = "{ "
  s << "free: #{"0x%016x" % defi["free"]}"
  s << ', '
  s << "total: #{"0x%016x" % defi["total"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemGetInfo_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "free_val: #{defi["free_val"]}"
  s << ', '
  s << "total_val: #{defi["total_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemPtrGetInfo_entry"] = lambda { |defi|
  s = "{ "
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemPtrGetInfo_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "size_val: #{defi["size_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMallocArray_entry"] = lambda { |defi|
  s = "{ "
  s << "array: #{"0x%016x" % defi["array"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "width: #{defi["width"]}"
  s << ', '
  s << "height: #{defi["height"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].size > 0 ? HIP::HipChannelFormatDesc.new(FFI::MemoryPointer.from_string(defi["desc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMallocArray_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "array_val: #{"0x%016x" % defi["array_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipArrayCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "pHandle: #{"0x%016x" % defi["pHandle"]}"
  s << ', '
  s << "pAllocateArray: #{"0x%016x" % defi["pAllocateArray"]}"
  s << ', '
  s << "pAllocateArray_val: #{defi["pAllocateArray_val"].size > 0 ? HIP::HIP_ARRAY_DESCRIPTOR.new(FFI::MemoryPointer.from_string(defi["pAllocateArray_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipArrayCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pHandle_val: #{"0x%016x" % defi["pHandle_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipArrayDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "array: #{"0x%016x" % defi["array"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipArrayDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipArray3DCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "array: #{"0x%016x" % defi["array"]}"
  s << ', '
  s << "pAllocateArray: #{"0x%016x" % defi["pAllocateArray"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipArray3DCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMalloc3D_entry"] = lambda { |defi|
  s = "{ "
  s << "pitchedDevPtr: #{"0x%016x" % defi["pitchedDevPtr"]}"
  s << ', '
  s << "extent: #{defi["extent"].size > 0 ? HIP::HipExtent.new(FFI::MemoryPointer.from_string(defi["extent"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMalloc3D_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pitchedDevPtr_val: #{defi["pitchedDevPtr_val"].size > 0 ? HIP::HipPitchedPtr.new(FFI::MemoryPointer.from_string(defi["pitchedDevPtr_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipFreeArray_entry"] = lambda { |defi|
  s = "{ "
  s << "array: #{"0x%016x" % defi["array"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipFreeArray_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipFreeMipmappedArray_entry"] = lambda { |defi|
  s = "{ "
  s << "mipmappedArray: #{"0x%016x" % defi["mipmappedArray"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipFreeMipmappedArray_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMalloc3DArray_entry"] = lambda { |defi|
  s = "{ "
  s << "array: #{"0x%016x" % defi["array"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "extent: #{defi["extent"].inspect}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMalloc3DArray_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "array_val: #{"0x%016x" % defi["array_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMallocMipmappedArray_entry"] = lambda { |defi|
  s = "{ "
  s << "mipmappedArray: #{"0x%016x" % defi["mipmappedArray"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "extent: #{defi["extent"].inspect}"
  s << ', '
  s << "numLevels: #{defi["numLevels"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMallocMipmappedArray_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "mipmappedArray_val: #{"0x%016x" % defi["mipmappedArray_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGetMipmappedArrayLevel_entry"] = lambda { |defi|
  s = "{ "
  s << "levelArray: #{"0x%016x" % defi["levelArray"]}"
  s << ', '
  s << "mipmappedArray: #{"0x%016x" % defi["mipmappedArray"]}"
  s << ', '
  s << "level: #{defi["level"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGetMipmappedArrayLevel_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "levelArray_val: #{"0x%016x" % defi["levelArray_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpy2D_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "dpitch: #{defi["dpitch"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "spitch: #{defi["spitch"]}"
  s << ', '
  s << "width: #{defi["width"]}"
  s << ', '
  s << "height: #{defi["height"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpy2D_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyParam2D_entry"] = lambda { |defi|
  s = "{ "
  s << "pCopy: #{"0x%016x" % defi["pCopy"]}"
  s << ', '
  s << "pCopy_val: #{defi["pCopy_val"].size > 0 ? HIP::Hip_Memcpy2D.new(FFI::MemoryPointer.from_string(defi["pCopy_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyParam2D_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyParam2DAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "pCopy: #{"0x%016x" % defi["pCopy"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "pCopy_val: #{defi["pCopy_val"].size > 0 ? HIP::Hip_Memcpy2D.new(FFI::MemoryPointer.from_string(defi["pCopy_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyParam2DAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpy2DAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "dpitch: #{defi["dpitch"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "spitch: #{defi["spitch"]}"
  s << ', '
  s << "width: #{defi["width"]}"
  s << ', '
  s << "height: #{defi["height"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpy2DAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpy2DToArray_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "wOffset: #{defi["wOffset"]}"
  s << ', '
  s << "hOffset: #{defi["hOffset"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "spitch: #{defi["spitch"]}"
  s << ', '
  s << "width: #{defi["width"]}"
  s << ', '
  s << "height: #{defi["height"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpy2DToArray_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpy2DToArrayAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "wOffset: #{defi["wOffset"]}"
  s << ', '
  s << "hOffset: #{defi["hOffset"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "spitch: #{defi["spitch"]}"
  s << ', '
  s << "width: #{defi["width"]}"
  s << ', '
  s << "height: #{defi["height"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpy2DToArrayAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyToArray_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "wOffset: #{defi["wOffset"]}"
  s << ', '
  s << "hOffset: #{defi["hOffset"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyToArray_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyFromArray_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "srcArray: #{"0x%016x" % defi["srcArray"]}"
  s << ', '
  s << "wOffset: #{defi["wOffset"]}"
  s << ', '
  s << "hOffset: #{defi["hOffset"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyFromArray_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpy2DFromArray_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "dpitch: #{defi["dpitch"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "wOffset: #{defi["wOffset"]}"
  s << ', '
  s << "hOffset: #{defi["hOffset"]}"
  s << ', '
  s << "width: #{defi["width"]}"
  s << ', '
  s << "height: #{defi["height"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpy2DFromArray_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpy2DFromArrayAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "dpitch: #{defi["dpitch"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "wOffset: #{defi["wOffset"]}"
  s << ', '
  s << "hOffset: #{defi["hOffset"]}"
  s << ', '
  s << "width: #{defi["width"]}"
  s << ', '
  s << "height: #{defi["height"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpy2DFromArrayAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyAtoH_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "srcArray: #{"0x%016x" % defi["srcArray"]}"
  s << ', '
  s << "srcOffset: #{defi["srcOffset"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyAtoH_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyHtoA_entry"] = lambda { |defi|
  s = "{ "
  s << "dstArray: #{"0x%016x" % defi["dstArray"]}"
  s << ', '
  s << "dstOffset: #{defi["dstOffset"]}"
  s << ', '
  s << "srcHost: #{"0x%016x" % defi["srcHost"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyHtoA_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpy3D_entry"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpy3D_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpy3DAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpy3DAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDrvMemcpy3D_entry"] = lambda { |defi|
  s = "{ "
  s << "pCopy: #{"0x%016x" % defi["pCopy"]}"
  s << ', '
  s << "pCopy_val: #{defi["pCopy_val"].size > 0 ? HIP::HIP_MEMCPY3D.new(FFI::MemoryPointer.from_string(defi["pCopy_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDrvMemcpy3D_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDrvMemcpy3DAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "pCopy: #{"0x%016x" % defi["pCopy"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "pCopy_val: #{defi["pCopy_val"].size > 0 ? HIP::HIP_MEMCPY3D.new(FFI::MemoryPointer.from_string(defi["pCopy_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDrvMemcpy3DAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceCanAccessPeer_entry"] = lambda { |defi|
  s = "{ "
  s << "canAccessPeer: #{"0x%016x" % defi["canAccessPeer"]}"
  s << ', '
  s << "deviceId: #{defi["deviceId"]}"
  s << ', '
  s << "peerDeviceId: #{defi["peerDeviceId"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceCanAccessPeer_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "canAccessPeer_val: #{defi["canAccessPeer_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceEnablePeerAccess_entry"] = lambda { |defi|
  s = "{ "
  s << "peerDeviceId: #{defi["peerDeviceId"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceEnablePeerAccess_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceDisablePeerAccess_entry"] = lambda { |defi|
  s = "{ "
  s << "peerDeviceId: #{defi["peerDeviceId"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceDisablePeerAccess_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemGetAddressRange_entry"] = lambda { |defi|
  s = "{ "
  s << "pbase: #{"0x%016x" % defi["pbase"]}"
  s << ', '
  s << "psize: #{"0x%016x" % defi["psize"]}"
  s << ', '
  s << "dptr: #{"0x%016x" % defi["dptr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemGetAddressRange_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pbase_val: #{"0x%016x" % defi["pbase_val"]}"
  s << ', '
  s << "psize_val: #{defi["psize_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyPeer_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "dstDeviceId: #{defi["dstDeviceId"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "srcDeviceId: #{defi["srcDeviceId"]}"
  s << ', '
  s << "sizeBytes: #{defi["sizeBytes"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyPeer_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyPeerAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "dstDeviceId: #{defi["dstDeviceId"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "srcDevice: #{defi["srcDevice"]}"
  s << ', '
  s << "sizeBytes: #{defi["sizeBytes"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyPeerAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipCtxCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "ctx: #{"0x%016x" % defi["ctx"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "device: #{defi["device"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipCtxCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "ctx_val: #{"0x%016x" % defi["ctx_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipCtxDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "ctx: #{"0x%016x" % defi["ctx"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipCtxDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipCtxPopCurrent_entry"] = lambda { |defi|
  s = "{ "
  s << "ctx: #{"0x%016x" % defi["ctx"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipCtxPopCurrent_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "ctx_val: #{"0x%016x" % defi["ctx_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipCtxPushCurrent_entry"] = lambda { |defi|
  s = "{ "
  s << "ctx: #{"0x%016x" % defi["ctx"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipCtxPushCurrent_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipCtxSetCurrent_entry"] = lambda { |defi|
  s = "{ "
  s << "ctx: #{"0x%016x" % defi["ctx"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipCtxSetCurrent_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipCtxGetCurrent_entry"] = lambda { |defi|
  s = "{ "
  s << "ctx: #{"0x%016x" % defi["ctx"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipCtxGetCurrent_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "ctx_val: #{"0x%016x" % defi["ctx_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipCtxGetDevice_entry"] = lambda { |defi|
  s = "{ "
  s << "device: #{"0x%016x" % defi["device"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipCtxGetDevice_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "device_val: #{defi["device_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipCtxGetApiVersion_entry"] = lambda { |defi|
  s = "{ "
  s << "ctx: #{"0x%016x" % defi["ctx"]}"
  s << ', '
  s << "apiVersion: #{"0x%016x" % defi["apiVersion"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipCtxGetApiVersion_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "apiVersion_val: #{defi["apiVersion_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipCtxGetCacheConfig_entry"] = lambda { |defi|
  s = "{ "
  s << "cacheConfig: #{"0x%016x" % defi["cacheConfig"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipCtxGetCacheConfig_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "cacheConfig_val: #{HIP::HipFuncCache_t.from_native(defi["cacheConfig_val"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipCtxSetCacheConfig_entry"] = lambda { |defi|
  s = "{ "
  s << "cacheConfig: #{HIP::HipFuncCache_t.from_native(defi["cacheConfig"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipCtxSetCacheConfig_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipCtxSetSharedMemConfig_entry"] = lambda { |defi|
  s = "{ "
  s << "config: #{HIP::HipSharedMemConfig.from_native(defi["config"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipCtxSetSharedMemConfig_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipCtxGetSharedMemConfig_entry"] = lambda { |defi|
  s = "{ "
  s << "pConfig: #{"0x%016x" % defi["pConfig"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipCtxGetSharedMemConfig_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pConfig_val: #{HIP::HipSharedMemConfig.from_native(defi["pConfig_val"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipCtxSynchronize_entry"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipCtxSynchronize_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipCtxGetFlags_entry"] = lambda { |defi|
  s = "{ "
  s << "flags: #{"0x%016x" % defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipCtxGetFlags_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "flags_val: #{defi["flags_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipCtxEnablePeerAccess_entry"] = lambda { |defi|
  s = "{ "
  s << "peerCtx: #{"0x%016x" % defi["peerCtx"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipCtxEnablePeerAccess_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipCtxDisablePeerAccess_entry"] = lambda { |defi|
  s = "{ "
  s << "peerCtx: #{"0x%016x" % defi["peerCtx"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipCtxDisablePeerAccess_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDevicePrimaryCtxGetState_entry"] = lambda { |defi|
  s = "{ "
  s << "dev: #{defi["dev"]}"
  s << ', '
  s << "flags: #{"0x%016x" % defi["flags"]}"
  s << ', '
  s << "active: #{"0x%016x" % defi["active"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDevicePrimaryCtxGetState_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "flags_val: #{defi["flags_val"]}"
  s << ', '
  s << "active_val: #{defi["active_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDevicePrimaryCtxRelease_entry"] = lambda { |defi|
  s = "{ "
  s << "dev: #{defi["dev"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDevicePrimaryCtxRelease_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDevicePrimaryCtxRetain_entry"] = lambda { |defi|
  s = "{ "
  s << "pctx: #{"0x%016x" % defi["pctx"]}"
  s << ', '
  s << "dev: #{defi["dev"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDevicePrimaryCtxRetain_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pctx_val: #{"0x%016x" % defi["pctx_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDevicePrimaryCtxReset_entry"] = lambda { |defi|
  s = "{ "
  s << "dev: #{defi["dev"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDevicePrimaryCtxReset_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDevicePrimaryCtxSetFlags_entry"] = lambda { |defi|
  s = "{ "
  s << "dev: #{defi["dev"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDevicePrimaryCtxSetFlags_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipModuleLoad_entry"] = lambda { |defi|
  s = "{ "
  s << "module: #{"0x%016x" % defi["module"]}"
  s << ', '
  s << "fname: #{"0x%016x" % defi["fname"]}"
  s << ', '
  s << "fname_val: #{defi["fname_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipModuleLoad_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "module_val: #{"0x%016x" % defi["module_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipModuleUnload_entry"] = lambda { |defi|
  s = "{ "
  s << "module: #{"0x%016x" % defi["module"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipModuleUnload_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipModuleGetFunction_entry"] = lambda { |defi|
  s = "{ "
  s << "function: #{"0x%016x" % defi["function"]}"
  s << ', '
  s << "module: #{"0x%016x" % defi["module"]}"
  s << ', '
  s << "kname: #{"0x%016x" % defi["kname"]}"
  s << ', '
  s << "kname_val: #{defi["kname_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipModuleGetFunction_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "function_val: #{"0x%016x" % defi["function_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipFuncGetAttributes_entry"] = lambda { |defi|
  s = "{ "
  s << "attr: #{"0x%016x" % defi["attr"]}"
  s << ', '
  s << "func: #{"0x%016x" % defi["func"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipFuncGetAttributes_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "attr_val: #{defi["attr_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipFuncGetAttribute_entry"] = lambda { |defi|
  s = "{ "
  s << "value: #{"0x%016x" % defi["value"]}"
  s << ', '
  s << "attrib: #{HIP::HipFunction_attribute.from_native(defi["attrib"], nil)}"
  s << ', '
  s << "hfunc: #{"0x%016x" % defi["hfunc"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipFuncGetAttribute_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "value_val: #{defi["value_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipModuleGetTexRef_entry"] = lambda { |defi|
  s = "{ "
  s << "texRef: #{"0x%016x" % defi["texRef"]}"
  s << ', '
  s << "hmod: #{"0x%016x" % defi["hmod"]}"
  s << ', '
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "name_val: #{defi["name_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipModuleGetTexRef_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "texRef_val: #{"0x%016x" % defi["texRef_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipModuleLoadData_entry"] = lambda { |defi|
  s = "{ "
  s << "module: #{"0x%016x" % defi["module"]}"
  s << ', '
  s << "image: #{"0x%016x" % defi["image"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipModuleLoadData_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "module_val: #{"0x%016x" % defi["module_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipModuleLoadDataEx_entry"] = lambda { |defi|
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
$event_lambdas["lttng_ust_hip:hipModuleLoadDataEx_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "module_val: #{"0x%016x" % defi["module_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipModuleLaunchKernel_entry"] = lambda { |defi|
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
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "kernelParams: #{"0x%016x" % defi["kernelParams"]}"
  s << ', '
  s << "extra: #{"0x%016x" % defi["extra"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipModuleLaunchKernel_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipLaunchCooperativeKernel_entry"] = lambda { |defi|
  s = "{ "
  s << "f: #{"0x%016x" % defi["f"]}"
  s << ', '
  s << "gridDim: #{defi["gridDim"].size > 0 ? HIP::Dim3.new(FFI::MemoryPointer.from_string(defi["gridDim"])) : nil}"
  s << ', '
  s << "blockDimX: #{defi["blockDimX"].size > 0 ? HIP::Dim3.new(FFI::MemoryPointer.from_string(defi["blockDimX"])) : nil}"
  s << ', '
  s << "kernelParams: #{"0x%016x" % defi["kernelParams"]}"
  s << ', '
  s << "sharedMemBytes: #{defi["sharedMemBytes"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipLaunchCooperativeKernel_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipLaunchCooperativeKernelMultiDevice_entry"] = lambda { |defi|
  s = "{ "
  s << "launchParamsList: #{"0x%016x" % defi["launchParamsList"]}"
  s << ', '
  s << "numDevices: #{defi["numDevices"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "launchParamsList_vals: [ #{p = FFI::MemoryPointer.from_string(defi["launchParamsList_vals"]); sz = HIP::HipLaunchParams.size; n = p.size / sz; (0...n).collect { |i| HIP::HipLaunchParams.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipLaunchCooperativeKernelMultiDevice_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipExtLaunchMultiKernelMultiDevice_entry"] = lambda { |defi|
  s = "{ "
  s << "launchParamsList: #{"0x%016x" % defi["launchParamsList"]}"
  s << ', '
  s << "numDevices: #{defi["numDevices"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "launchParamsList_vals: [ #{p = FFI::MemoryPointer.from_string(defi["launchParamsList_vals"]); sz = HIP::HipLaunchParams.size; n = p.size / sz; (0...n).collect { |i| HIP::HipLaunchParams.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipExtLaunchMultiKernelMultiDevice_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipModuleOccupancyMaxPotentialBlockSize_entry"] = lambda { |defi|
  s = "{ "
  s << "gridSize: #{"0x%016x" % defi["gridSize"]}"
  s << ', '
  s << "blockSize: #{"0x%016x" % defi["blockSize"]}"
  s << ', '
  s << "f: #{"0x%016x" % defi["f"]}"
  s << ', '
  s << "dynSharedMemPerBlk: #{defi["dynSharedMemPerBlk"]}"
  s << ', '
  s << "blockSizeLimit: #{defi["blockSizeLimit"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipModuleOccupancyMaxPotentialBlockSize_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "gridSize_val: #{defi["gridSize_val"]}"
  s << ', '
  s << "blockSize_val: #{defi["blockSize_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipModuleOccupancyMaxPotentialBlockSizeWithFlags_entry"] = lambda { |defi|
  s = "{ "
  s << "gridSize: #{"0x%016x" % defi["gridSize"]}"
  s << ', '
  s << "blockSize: #{"0x%016x" % defi["blockSize"]}"
  s << ', '
  s << "f: #{"0x%016x" % defi["f"]}"
  s << ', '
  s << "dynSharedMemPerBlk: #{defi["dynSharedMemPerBlk"]}"
  s << ', '
  s << "blockSizeLimit: #{defi["blockSizeLimit"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipModuleOccupancyMaxPotentialBlockSizeWithFlags_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "gridSize_val: #{defi["gridSize_val"]}"
  s << ', '
  s << "blockSize_val: #{defi["blockSize_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipModuleOccupancyMaxActiveBlocksPerMultiprocessor_entry"] = lambda { |defi|
  s = "{ "
  s << "numBlocks: #{"0x%016x" % defi["numBlocks"]}"
  s << ', '
  s << "f: #{"0x%016x" % defi["f"]}"
  s << ', '
  s << "blockSize: #{defi["blockSize"]}"
  s << ', '
  s << "dynSharedMemPerBlk: #{defi["dynSharedMemPerBlk"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipModuleOccupancyMaxActiveBlocksPerMultiprocessor_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "numBlocks_val: #{defi["numBlocks_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_entry"] = lambda { |defi|
  s = "{ "
  s << "numBlocks: #{"0x%016x" % defi["numBlocks"]}"
  s << ', '
  s << "f: #{"0x%016x" % defi["f"]}"
  s << ', '
  s << "blockSize: #{defi["blockSize"]}"
  s << ', '
  s << "dynSharedMemPerBlk: #{defi["dynSharedMemPerBlk"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "numBlocks_val: #{defi["numBlocks_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipOccupancyMaxActiveBlocksPerMultiprocessor_entry"] = lambda { |defi|
  s = "{ "
  s << "numBlocks: #{"0x%016x" % defi["numBlocks"]}"
  s << ', '
  s << "f: #{"0x%016x" % defi["f"]}"
  s << ', '
  s << "blockSize: #{defi["blockSize"]}"
  s << ', '
  s << "dynSharedMemPerBlk: #{defi["dynSharedMemPerBlk"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipOccupancyMaxActiveBlocksPerMultiprocessor_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "numBlocks_val: #{defi["numBlocks_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_entry"] = lambda { |defi|
  s = "{ "
  s << "numBlocks: #{"0x%016x" % defi["numBlocks"]}"
  s << ', '
  s << "f: #{"0x%016x" % defi["f"]}"
  s << ', '
  s << "blockSize: #{defi["blockSize"]}"
  s << ', '
  s << "dynSharedMemPerBlk: #{defi["dynSharedMemPerBlk"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "numBlocks_val: #{defi["numBlocks_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipOccupancyMaxPotentialBlockSize_entry"] = lambda { |defi|
  s = "{ "
  s << "gridSize: #{"0x%016x" % defi["gridSize"]}"
  s << ', '
  s << "blockSize: #{"0x%016x" % defi["blockSize"]}"
  s << ', '
  s << "f: #{"0x%016x" % defi["f"]}"
  s << ', '
  s << "dynSharedMemPerBlk: #{defi["dynSharedMemPerBlk"]}"
  s << ', '
  s << "blockSizeLimit: #{defi["blockSizeLimit"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipOccupancyMaxPotentialBlockSize_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "gridSize_val: #{defi["gridSize_val"]}"
  s << ', '
  s << "blockSize_val: #{defi["blockSize_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipProfilerStart_entry"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipProfilerStart_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipProfilerStop_entry"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipProfilerStop_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipConfigureCall_entry"] = lambda { |defi|
  s = "{ "
  s << "gridDim: #{defi["gridDim"].size > 0 ? HIP::Dim3.new(FFI::MemoryPointer.from_string(defi["gridDim"])) : nil}"
  s << ', '
  s << "blockDim: #{defi["blockDim"].size > 0 ? HIP::Dim3.new(FFI::MemoryPointer.from_string(defi["blockDim"])) : nil}"
  s << ', '
  s << "sharedMem: #{defi["sharedMem"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipConfigureCall_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipSetupArgument_entry"] = lambda { |defi|
  s = "{ "
  s << "arg: #{"0x%016x" % defi["arg"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "arg_vals: #{defi["arg_vals"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipSetupArgument_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipLaunchByPtr_entry"] = lambda { |defi|
  s = "{ "
  s << "func: #{"0x%016x" % defi["func"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipLaunchByPtr_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:__hipPushCallConfiguration_entry"] = lambda { |defi|
  s = "{ "
  s << "gridDim: #{defi["gridDim"].size > 0 ? HIP::Dim3.new(FFI::MemoryPointer.from_string(defi["gridDim"])) : nil}"
  s << ', '
  s << "blockDim: #{defi["blockDim"].size > 0 ? HIP::Dim3.new(FFI::MemoryPointer.from_string(defi["blockDim"])) : nil}"
  s << ', '
  s << "sharedMem: #{defi["sharedMem"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:__hipPushCallConfiguration_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:__hipPopCallConfiguration_entry"] = lambda { |defi|
  s = "{ "
  s << "gridDim: #{"0x%016x" % defi["gridDim"]}"
  s << ', '
  s << "blockDim: #{"0x%016x" % defi["blockDim"]}"
  s << ', '
  s << "sharedMem: #{"0x%016x" % defi["sharedMem"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:__hipPopCallConfiguration_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "gridDim_val: #{defi["gridDim_val"].size > 0 ? HIP::Dim3.new(FFI::MemoryPointer.from_string(defi["gridDim_val"])) : nil}"
  s << ', '
  s << "blockDim_val: #{defi["blockDim_val"].size > 0 ? HIP::Dim3.new(FFI::MemoryPointer.from_string(defi["blockDim_val"])) : nil}"
  s << ', '
  s << "sharedMem_val: #{defi["sharedMem_val"]}"
  s << ', '
  s << "stream_val: #{"0x%016x" % defi["stream_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipLaunchKernel_entry"] = lambda { |defi|
  s = "{ "
  s << "function_address: #{"0x%016x" % defi["function_address"]}"
  s << ', '
  s << "numBlocks: #{defi["numBlocks"].size > 0 ? HIP::Dim3.new(FFI::MemoryPointer.from_string(defi["numBlocks"])) : nil}"
  s << ', '
  s << "dimBlocks: #{defi["dimBlocks"].size > 0 ? HIP::Dim3.new(FFI::MemoryPointer.from_string(defi["dimBlocks"])) : nil}"
  s << ', '
  s << "args: #{"0x%016x" % defi["args"]}"
  s << ', '
  s << "sharedMemBytes: #{defi["sharedMemBytes"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipLaunchKernel_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDrvMemcpy2DUnaligned_entry"] = lambda { |defi|
  s = "{ "
  s << "pCopy: #{"0x%016x" % defi["pCopy"]}"
  s << ', '
  s << "pCopy_val: #{defi["pCopy_val"].size > 0 ? HIP::Hip_Memcpy2D.new(FFI::MemoryPointer.from_string(defi["pCopy_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDrvMemcpy2DUnaligned_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipExtLaunchKernel_entry"] = lambda { |defi|
  s = "{ "
  s << "function_address: #{"0x%016x" % defi["function_address"]}"
  s << ', '
  s << "numBlocks: #{defi["numBlocks"].size > 0 ? HIP::Dim3.new(FFI::MemoryPointer.from_string(defi["numBlocks"])) : nil}"
  s << ', '
  s << "dimBlocks: #{defi["dimBlocks"].size > 0 ? HIP::Dim3.new(FFI::MemoryPointer.from_string(defi["dimBlocks"])) : nil}"
  s << ', '
  s << "args: #{"0x%016x" % defi["args"]}"
  s << ', '
  s << "sharedMemBytes: #{defi["sharedMemBytes"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "startEvent: #{"0x%016x" % defi["startEvent"]}"
  s << ', '
  s << "stopEvent: #{"0x%016x" % defi["stopEvent"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipExtLaunchKernel_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipBindTextureToMipmappedArray_entry"] = lambda { |defi|
  s = "{ "
  s << "tex: #{"0x%016x" % defi["tex"]}"
  s << ', '
  s << "mipmappedArray: #{"0x%016x" % defi["mipmappedArray"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].size > 0 ? HIP::HipChannelFormatDesc.new(FFI::MemoryPointer.from_string(defi["desc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipBindTextureToMipmappedArray_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipCreateTextureObject_entry"] = lambda { |defi|
  s = "{ "
  s << "pTexObject: #{"0x%016x" % defi["pTexObject"]}"
  s << ', '
  s << "pResDesc: #{"0x%016x" % defi["pResDesc"]}"
  s << ', '
  s << "pTexDesc: #{"0x%016x" % defi["pTexDesc"]}"
  s << ', '
  s << "pResViewDesc: #{"0x%016x" % defi["pResViewDesc"]}"
  s << ', '
  s << "pResDesc_val: #{defi["pResDesc_val"].size > 0 ? HIP::HipResourceDesc.new(FFI::MemoryPointer.from_string(defi["pResDesc_val"])) : nil}"
  s << ', '
  s << "pTexDesc_val: #{defi["pTexDesc_val"].size > 0 ? HIP::HipTextureDesc.new(FFI::MemoryPointer.from_string(defi["pTexDesc_val"])) : nil}"
  s << ', '
  s << "pResViewDesc_val: #{defi["pResViewDesc_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipCreateTextureObject_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pTexObject_val: #{"0x%016x" % defi["pTexObject_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDestroyTextureObject_entry"] = lambda { |defi|
  s = "{ "
  s << "textureObject: #{"0x%016x" % defi["textureObject"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDestroyTextureObject_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGetChannelDesc_entry"] = lambda { |defi|
  s = "{ "
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "array: #{"0x%016x" % defi["array"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGetChannelDesc_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].size > 0 ? HIP::HipChannelFormatDesc.new(FFI::MemoryPointer.from_string(defi["desc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGetTextureObjectResourceDesc_entry"] = lambda { |defi|
  s = "{ "
  s << "pResDesc: #{"0x%016x" % defi["pResDesc"]}"
  s << ', '
  s << "textureObject: #{"0x%016x" % defi["textureObject"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGetTextureObjectResourceDesc_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pResDesc_val: #{defi["pResDesc_val"].size > 0 ? HIP::HipResourceDesc.new(FFI::MemoryPointer.from_string(defi["pResDesc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGetTextureObjectResourceViewDesc_entry"] = lambda { |defi|
  s = "{ "
  s << "pResViewDesc: #{"0x%016x" % defi["pResViewDesc"]}"
  s << ', '
  s << "textureObject: #{"0x%016x" % defi["textureObject"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGetTextureObjectResourceViewDesc_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pResViewDesc_val: #{defi["pResViewDesc_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGetTextureObjectTextureDesc_entry"] = lambda { |defi|
  s = "{ "
  s << "pTexDesc: #{"0x%016x" % defi["pTexDesc"]}"
  s << ', '
  s << "textureObject: #{"0x%016x" % defi["textureObject"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGetTextureObjectTextureDesc_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pTexDesc_val: #{defi["pTexDesc_val"].size > 0 ? HIP::HipTextureDesc.new(FFI::MemoryPointer.from_string(defi["pTexDesc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexObjectCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "pTexObject: #{"0x%016x" % defi["pTexObject"]}"
  s << ', '
  s << "pResDesc: #{"0x%016x" % defi["pResDesc"]}"
  s << ', '
  s << "pTexDesc: #{"0x%016x" % defi["pTexDesc"]}"
  s << ', '
  s << "pResViewDesc: #{"0x%016x" % defi["pResViewDesc"]}"
  s << ', '
  s << "pResDesc_val: #{defi["pResDesc_val"].size > 0 ? HIP::HIP_RESOURCE_DESC.new(FFI::MemoryPointer.from_string(defi["pResDesc_val"])) : nil}"
  s << ', '
  s << "pTexDesc_val: #{defi["pTexDesc_val"].size > 0 ? HIP::HIP_TEXTURE_DESC.new(FFI::MemoryPointer.from_string(defi["pTexDesc_val"])) : nil}"
  s << ', '
  s << "pResViewDesc_val: #{defi["pResViewDesc_val"].size > 0 ? HIP::HIP_RESOURCE_VIEW_DESC.new(FFI::MemoryPointer.from_string(defi["pResViewDesc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexObjectCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pTexObject_val: #{"0x%016x" % defi["pTexObject_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexObjectDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "texObject: #{"0x%016x" % defi["texObject"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexObjectDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexObjectGetResourceDesc_entry"] = lambda { |defi|
  s = "{ "
  s << "pResDesc: #{"0x%016x" % defi["pResDesc"]}"
  s << ', '
  s << "texObject: #{"0x%016x" % defi["texObject"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexObjectGetResourceDesc_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pResDesc_val: #{defi["pResDesc_val"].size > 0 ? HIP::HIP_RESOURCE_DESC.new(FFI::MemoryPointer.from_string(defi["pResDesc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexObjectGetResourceViewDesc_entry"] = lambda { |defi|
  s = "{ "
  s << "pResViewDesc: #{"0x%016x" % defi["pResViewDesc"]}"
  s << ', '
  s << "texObject: #{"0x%016x" % defi["texObject"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexObjectGetResourceViewDesc_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pResViewDesc_val: #{defi["pResViewDesc_val"].size > 0 ? HIP::HIP_RESOURCE_VIEW_DESC.new(FFI::MemoryPointer.from_string(defi["pResViewDesc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexObjectGetTextureDesc_entry"] = lambda { |defi|
  s = "{ "
  s << "pTexDesc: #{"0x%016x" % defi["pTexDesc"]}"
  s << ', '
  s << "texObject: #{"0x%016x" % defi["texObject"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexObjectGetTextureDesc_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pTexDesc_val: #{defi["pTexDesc_val"].size > 0 ? HIP::HIP_TEXTURE_DESC.new(FFI::MemoryPointer.from_string(defi["pTexDesc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGetTextureReference_entry"] = lambda { |defi|
  s = "{ "
  s << "texref: #{"0x%016x" % defi["texref"]}"
  s << ', '
  s << "symbol: #{"0x%016x" % defi["symbol"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGetTextureReference_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "texref_val: #{"0x%016x" % defi["texref_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefSetAddressMode_entry"] = lambda { |defi|
  s = "{ "
  s << "texRef: #{"0x%016x" % defi["texRef"]}"
  s << ', '
  s << "dim: #{defi["dim"]}"
  s << ', '
  s << "am: #{defi["am"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefSetAddressMode_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefSetArray_entry"] = lambda { |defi|
  s = "{ "
  s << "tex: #{"0x%016x" % defi["tex"]}"
  s << ', '
  s << "array: #{"0x%016x" % defi["array"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefSetArray_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefSetFilterMode_entry"] = lambda { |defi|
  s = "{ "
  s << "texRef: #{"0x%016x" % defi["texRef"]}"
  s << ', '
  s << "fm: #{defi["fm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefSetFilterMode_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefSetFlags_entry"] = lambda { |defi|
  s = "{ "
  s << "texRef: #{"0x%016x" % defi["texRef"]}"
  s << ', '
  s << "Flags: #{defi["Flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefSetFlags_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefSetFormat_entry"] = lambda { |defi|
  s = "{ "
  s << "texRef: #{"0x%016x" % defi["texRef"]}"
  s << ', '
  s << "fmt: #{HIP::HipArray_Format.from_native(defi["fmt"], nil)}"
  s << ', '
  s << "NumPackedComponents: #{defi["NumPackedComponents"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefSetFormat_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipBindTexture_entry"] = lambda { |defi|
  s = "{ "
  s << "offset: #{"0x%016x" % defi["offset"]}"
  s << ', '
  s << "tex: #{"0x%016x" % defi["tex"]}"
  s << ', '
  s << "devPtr: #{"0x%016x" % defi["devPtr"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].size > 0 ? HIP::HipChannelFormatDesc.new(FFI::MemoryPointer.from_string(defi["desc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipBindTexture_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "offset_val: #{defi["offset_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipBindTexture2D_entry"] = lambda { |defi|
  s = "{ "
  s << "offset: #{"0x%016x" % defi["offset"]}"
  s << ', '
  s << "tex: #{"0x%016x" % defi["tex"]}"
  s << ', '
  s << "devPtr: #{"0x%016x" % defi["devPtr"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "width: #{defi["width"]}"
  s << ', '
  s << "height: #{defi["height"]}"
  s << ', '
  s << "pitch: #{defi["pitch"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].size > 0 ? HIP::HipChannelFormatDesc.new(FFI::MemoryPointer.from_string(defi["desc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipBindTexture2D_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "offset_val: #{defi["offset_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipBindTextureToArray_entry"] = lambda { |defi|
  s = "{ "
  s << "tex: #{"0x%016x" % defi["tex"]}"
  s << ', '
  s << "array: #{"0x%016x" % defi["array"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].size > 0 ? HIP::HipChannelFormatDesc.new(FFI::MemoryPointer.from_string(defi["desc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipBindTextureToArray_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGetTextureAlignmentOffset_entry"] = lambda { |defi|
  s = "{ "
  s << "offset: #{"0x%016x" % defi["offset"]}"
  s << ', '
  s << "texref: #{"0x%016x" % defi["texref"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGetTextureAlignmentOffset_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "offset_val: #{defi["offset_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipUnbindTexture_entry"] = lambda { |defi|
  s = "{ "
  s << "tex: #{"0x%016x" % defi["tex"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipUnbindTexture_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefGetAddress_entry"] = lambda { |defi|
  s = "{ "
  s << "dev_ptr: #{"0x%016x" % defi["dev_ptr"]}"
  s << ', '
  s << "texRef: #{"0x%016x" % defi["texRef"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefGetAddress_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "dev_ptr_val: #{"0x%016x" % defi["dev_ptr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefGetAddressMode_entry"] = lambda { |defi|
  s = "{ "
  s << "pam: #{"0x%016x" % defi["pam"]}"
  s << ', '
  s << "texRef: #{"0x%016x" % defi["texRef"]}"
  s << ', '
  s << "dim: #{defi["dim"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefGetAddressMode_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pam_val: #{defi["pam_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefGetFilterMode_entry"] = lambda { |defi|
  s = "{ "
  s << "pfm: #{"0x%016x" % defi["pfm"]}"
  s << ', '
  s << "texRef: #{"0x%016x" % defi["texRef"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefGetFilterMode_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pfm_val: #{defi["pfm_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefGetFlags_entry"] = lambda { |defi|
  s = "{ "
  s << "pFlags: #{"0x%016x" % defi["pFlags"]}"
  s << ', '
  s << "texRef: #{"0x%016x" % defi["texRef"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefGetFlags_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pFlags_val: #{defi["pFlags_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefGetFormat_entry"] = lambda { |defi|
  s = "{ "
  s << "pFormat: #{"0x%016x" % defi["pFormat"]}"
  s << ', '
  s << "pNumChannels: #{"0x%016x" % defi["pNumChannels"]}"
  s << ', '
  s << "texRef: #{"0x%016x" % defi["texRef"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefGetFormat_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pFormat_val: #{HIP::HipArray_Format.from_native(defi["pFormat_val"], nil)}"
  s << ', '
  s << "pNumChannels_val: #{defi["pNumChannels_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefGetMaxAnisotropy_entry"] = lambda { |defi|
  s = "{ "
  s << "pmaxAnsio: #{"0x%016x" % defi["pmaxAnsio"]}"
  s << ', '
  s << "texRef: #{"0x%016x" % defi["texRef"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefGetMaxAnisotropy_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pmaxAnsio_val: #{defi["pmaxAnsio_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefGetMipmapFilterMode_entry"] = lambda { |defi|
  s = "{ "
  s << "pfm: #{"0x%016x" % defi["pfm"]}"
  s << ', '
  s << "texRef: #{"0x%016x" % defi["texRef"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefGetMipmapFilterMode_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pfm_val: #{defi["pfm_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefGetMipmapLevelBias_entry"] = lambda { |defi|
  s = "{ "
  s << "pbias: #{"0x%016x" % defi["pbias"]}"
  s << ', '
  s << "texRef: #{"0x%016x" % defi["texRef"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefGetMipmapLevelBias_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pbias_val: #{defi["pbias_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefGetMipmapLevelClamp_entry"] = lambda { |defi|
  s = "{ "
  s << "pminMipmapLevelClamp: #{"0x%016x" % defi["pminMipmapLevelClamp"]}"
  s << ', '
  s << "pmaxMipmapLevelClamp: #{"0x%016x" % defi["pmaxMipmapLevelClamp"]}"
  s << ', '
  s << "texRef: #{"0x%016x" % defi["texRef"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefGetMipmapLevelClamp_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pminMipmapLevelClamp_val: #{defi["pminMipmapLevelClamp_val"]}"
  s << ', '
  s << "pmaxMipmapLevelClamp_val: #{defi["pmaxMipmapLevelClamp_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefGetMipMappedArray_entry"] = lambda { |defi|
  s = "{ "
  s << "pArray: #{"0x%016x" % defi["pArray"]}"
  s << ', '
  s << "texRef: #{"0x%016x" % defi["texRef"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefGetMipMappedArray_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pArray_val: #{"0x%016x" % defi["pArray_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefSetAddress_entry"] = lambda { |defi|
  s = "{ "
  s << "ByteOffset: #{"0x%016x" % defi["ByteOffset"]}"
  s << ', '
  s << "texRef: #{"0x%016x" % defi["texRef"]}"
  s << ', '
  s << "dptr: #{"0x%016x" % defi["dptr"]}"
  s << ', '
  s << "bytes: #{defi["bytes"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefSetAddress_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "ByteOffset_val: #{defi["ByteOffset_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefSetAddress2D_entry"] = lambda { |defi|
  s = "{ "
  s << "texRef: #{"0x%016x" % defi["texRef"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "dptr: #{"0x%016x" % defi["dptr"]}"
  s << ', '
  s << "Pitch: #{defi["Pitch"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].size > 0 ? HIP::HIP_ARRAY_DESCRIPTOR.new(FFI::MemoryPointer.from_string(defi["desc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefSetAddress2D_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefSetMaxAnisotropy_entry"] = lambda { |defi|
  s = "{ "
  s << "texRef: #{"0x%016x" % defi["texRef"]}"
  s << ', '
  s << "maxAniso: #{defi["maxAniso"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefSetMaxAnisotropy_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefSetBorderColor_entry"] = lambda { |defi|
  s = "{ "
  s << "texRef: #{"0x%016x" % defi["texRef"]}"
  s << ', '
  s << "pBorderColor: #{"0x%016x" % defi["pBorderColor"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefSetBorderColor_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefSetMipmapFilterMode_entry"] = lambda { |defi|
  s = "{ "
  s << "texRef: #{"0x%016x" % defi["texRef"]}"
  s << ', '
  s << "fm: #{defi["fm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefSetMipmapFilterMode_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefSetMipmapLevelBias_entry"] = lambda { |defi|
  s = "{ "
  s << "texRef: #{"0x%016x" % defi["texRef"]}"
  s << ', '
  s << "bias: #{defi["bias"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefSetMipmapLevelBias_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefSetMipmapLevelClamp_entry"] = lambda { |defi|
  s = "{ "
  s << "texRef: #{"0x%016x" % defi["texRef"]}"
  s << ', '
  s << "minMipMapLevelClamp: #{defi["minMipMapLevelClamp"]}"
  s << ', '
  s << "maxMipMapLevelClamp: #{defi["maxMipMapLevelClamp"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefSetMipmapLevelClamp_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefSetMipmappedArray_entry"] = lambda { |defi|
  s = "{ "
  s << "texRef: #{"0x%016x" % defi["texRef"]}"
  s << ', '
  s << "mipmappedArray: #{"0x%016x" % defi["mipmappedArray"]}"
  s << ', '
  s << "Flags: #{defi["Flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipTexRefSetMipmappedArray_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMipmappedArrayCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "pHandle: #{"0x%016x" % defi["pHandle"]}"
  s << ', '
  s << "pMipmappedArrayDesc: #{"0x%016x" % defi["pMipmappedArrayDesc"]}"
  s << ', '
  s << "numMipmapLevels: #{defi["numMipmapLevels"]}"
  s << ', '
  s << "pMipmappedArrayDesc_val: #{defi["pMipmappedArrayDesc_val"].size > 0 ? HIP::HIP_ARRAY3D_DESCRIPTOR.new(FFI::MemoryPointer.from_string(defi["pMipmappedArrayDesc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMipmappedArrayCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pHandle_val: #{"0x%016x" % defi["pHandle_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMipmappedArrayDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "hMipmappedArray: #{"0x%016x" % defi["hMipmappedArray"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMipmappedArrayDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMipmappedArrayGetLevel_entry"] = lambda { |defi|
  s = "{ "
  s << "pLevelArray: #{"0x%016x" % defi["pLevelArray"]}"
  s << ', '
  s << "hMipMappedArray: #{"0x%016x" % defi["hMipMappedArray"]}"
  s << ', '
  s << "level: #{defi["level"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMipmappedArrayGetLevel_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pLevelArray_val: #{"0x%016x" % defi["pLevelArray_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipApiName_entry"] = lambda { |defi|
  s = "{ "
  s << "id: #{defi["id"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipApiName_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{"0x%016x" % defi["hipResult"]}"
  s << ', '
  s << "hipResult_val: #{defi["hipResult_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipKernelNameRef_entry"] = lambda { |defi|
  s = "{ "
  s << "f: #{"0x%016x" % defi["f"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipKernelNameRef_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{"0x%016x" % defi["hipResult"]}"
  s << ', '
  s << "hipResult_val: #{defi["hipResult_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipKernelNameRefByPtr_entry"] = lambda { |defi|
  s = "{ "
  s << "hostFunction: #{"0x%016x" % defi["hostFunction"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipKernelNameRefByPtr_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{"0x%016x" % defi["hipResult"]}"
  s << ', '
  s << "hipResult_val: #{defi["hipResult_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGetStreamDeviceId_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGetStreamDeviceId_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{defi["hipResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamBeginCapture_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "mode: #{HIP::HipStreamCaptureMode.from_native(defi["mode"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamBeginCapture_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamEndCapture_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "pGraph: #{"0x%016x" % defi["pGraph"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamEndCapture_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pGraph_val: #{"0x%016x" % defi["pGraph_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamGetCaptureInfo_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "pCaptureStatus: #{"0x%016x" % defi["pCaptureStatus"]}"
  s << ', '
  s << "pId: #{"0x%016x" % defi["pId"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamGetCaptureInfo_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pCaptureStatus_val: #{HIP::HipStreamCaptureStatus.from_native(defi["pCaptureStatus_val"], nil)}"
  s << ', '
  s << "pId_val: #{defi["pId_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamGetCaptureInfo_v2_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
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
$event_lambdas["lttng_ust_hip:hipStreamGetCaptureInfo_v2_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "captureStatus_out_val: #{HIP::HipStreamCaptureStatus.from_native(defi["captureStatus_out_val"], nil)}"
  s << ', '
  s << "id_out_val: #{defi["id_out_val"]}"
  s << ', '
  s << "graph_out_val: #{"0x%016x" % defi["graph_out_val"]}"
  s << ', '
  s << "numDependencies_out_val: #{defi["numDependencies_out_val"]}"
  s << ', '
  s << "dependencies_out_vals: [ #{defi["dependencies_out_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamIsCapturing_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "pCaptureStatus: #{"0x%016x" % defi["pCaptureStatus"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamIsCapturing_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pCaptureStatus_val: #{HIP::HipStreamCaptureStatus.from_native(defi["pCaptureStatus_val"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamUpdateCaptureDependencies_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
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
$event_lambdas["lttng_ust_hip:hipStreamUpdateCaptureDependencies_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipLaunchHostFunc_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "fn: #{"0x%016x" % defi["fn"]}"
  s << ', '
  s << "userData: #{"0x%016x" % defi["userData"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipLaunchHostFunc_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipThreadExchangeStreamCaptureMode_entry"] = lambda { |defi|
  s = "{ "
  s << "mode: #{"0x%016x" % defi["mode"]}"
  s << ', '
  s << "mode_val: #{HIP::HipStreamCaptureMode.from_native(defi["mode_val"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipThreadExchangeStreamCaptureMode_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "mode_val: #{HIP::HipStreamCaptureMode.from_native(defi["mode_val"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "pGraph: #{"0x%016x" % defi["pGraph"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pGraph_val: #{"0x%016x" % defi["pGraph_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "graph: #{"0x%016x" % defi["graph"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphAddDependencies_entry"] = lambda { |defi|
  s = "{ "
  s << "graph: #{"0x%016x" % defi["graph"]}"
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
$event_lambdas["lttng_ust_hip:hipGraphAddDependencies_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphRemoveDependencies_entry"] = lambda { |defi|
  s = "{ "
  s << "graph: #{"0x%016x" % defi["graph"]}"
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
$event_lambdas["lttng_ust_hip:hipGraphRemoveDependencies_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphGetEdges_entry"] = lambda { |defi|
  s = "{ "
  s << "graph: #{"0x%016x" % defi["graph"]}"
  s << ', '
  s << "from: #{"0x%016x" % defi["from"]}"
  s << ', '
  s << "to: #{"0x%016x" % defi["to"]}"
  s << ', '
  s << "numEdges: #{"0x%016x" % defi["numEdges"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphGetEdges_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "numEdges_val: #{defi["numEdges_val"]}"
  s << ', '
  s << "from_vals: [ #{defi["from_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "to_vals: [ #{defi["to_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphGetNodes_entry"] = lambda { |defi|
  s = "{ "
  s << "graph: #{"0x%016x" % defi["graph"]}"
  s << ', '
  s << "nodes: #{"0x%016x" % defi["nodes"]}"
  s << ', '
  s << "numNodes: #{"0x%016x" % defi["numNodes"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphGetNodes_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "numNodes_val: #{defi["numNodes_val"]}"
  s << ', '
  s << "nodes_vals: [ #{defi["nodes_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphGetRootNodes_entry"] = lambda { |defi|
  s = "{ "
  s << "graph: #{"0x%016x" % defi["graph"]}"
  s << ', '
  s << "pRootNodes: #{"0x%016x" % defi["pRootNodes"]}"
  s << ', '
  s << "pNumRootNodes: #{"0x%016x" % defi["pNumRootNodes"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphGetRootNodes_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pNumRootNodes_val: #{defi["pNumRootNodes_val"]}"
  s << ', '
  s << "pRootNodes_vals: [ #{defi["pRootNodes_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphNodeGetDependencies_entry"] = lambda { |defi|
  s = "{ "
  s << "node: #{"0x%016x" % defi["node"]}"
  s << ', '
  s << "pDependencies: #{"0x%016x" % defi["pDependencies"]}"
  s << ', '
  s << "pNumDependencies: #{"0x%016x" % defi["pNumDependencies"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphNodeGetDependencies_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pNumDependencies_val: #{defi["pNumDependencies_val"]}"
  s << ', '
  s << "pDependencies_vals: [ #{defi["pDependencies_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphNodeGetDependentNodes_entry"] = lambda { |defi|
  s = "{ "
  s << "node: #{"0x%016x" % defi["node"]}"
  s << ', '
  s << "pDependentNodes: #{"0x%016x" % defi["pDependentNodes"]}"
  s << ', '
  s << "pNumDependentNodes: #{"0x%016x" % defi["pNumDependentNodes"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphNodeGetDependentNodes_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pNumDependentNodes_val: #{defi["pNumDependentNodes_val"]}"
  s << ', '
  s << "pDependentNodes_vals: [ #{defi["pDependentNodes_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphNodeGetType_entry"] = lambda { |defi|
  s = "{ "
  s << "node: #{"0x%016x" % defi["node"]}"
  s << ', '
  s << "pType: #{"0x%016x" % defi["pType"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphNodeGetType_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pType_val: #{HIP::HipGraphNodeType.from_native(defi["pType_val"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphDestroyNode_entry"] = lambda { |defi|
  s = "{ "
  s << "node: #{"0x%016x" % defi["node"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphDestroyNode_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphClone_entry"] = lambda { |defi|
  s = "{ "
  s << "pGraphClone: #{"0x%016x" % defi["pGraphClone"]}"
  s << ', '
  s << "originalGraph: #{"0x%016x" % defi["originalGraph"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphClone_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pGraphClone_val: #{"0x%016x" % defi["pGraphClone_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphNodeFindInClone_entry"] = lambda { |defi|
  s = "{ "
  s << "pNode: #{"0x%016x" % defi["pNode"]}"
  s << ', '
  s << "originalNode: #{"0x%016x" % defi["originalNode"]}"
  s << ', '
  s << "clonedGraph: #{"0x%016x" % defi["clonedGraph"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphNodeFindInClone_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pNode_val: #{"0x%016x" % defi["pNode_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphInstantiate_entry"] = lambda { |defi|
  s = "{ "
  s << "pGraphExec: #{"0x%016x" % defi["pGraphExec"]}"
  s << ', '
  s << "graph: #{"0x%016x" % defi["graph"]}"
  s << ', '
  s << "pErrorNode: #{"0x%016x" % defi["pErrorNode"]}"
  s << ', '
  s << "pLogBuffer: #{"0x%016x" % defi["pLogBuffer"]}"
  s << ', '
  s << "bufferSize: #{defi["bufferSize"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphInstantiate_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pGraphExec_val: #{"0x%016x" % defi["pGraphExec_val"]}"
  s << ', '
  s << "pErrorNode_val: #{"0x%016x" % defi["pErrorNode_val"]}"
  s << ', '
  s << "pLogBuffer_vals: #{defi["pLogBuffer_vals"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphInstantiateWithFlags_entry"] = lambda { |defi|
  s = "{ "
  s << "pGraphExec: #{"0x%016x" % defi["pGraphExec"]}"
  s << ', '
  s << "graph: #{"0x%016x" % defi["graph"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphInstantiateWithFlags_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pGraphExec_val: #{"0x%016x" % defi["pGraphExec_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphLaunch_entry"] = lambda { |defi|
  s = "{ "
  s << "graphExec: #{"0x%016x" % defi["graphExec"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphLaunch_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphUpload_entry"] = lambda { |defi|
  s = "{ "
  s << "graphExec: #{"0x%016x" % defi["graphExec"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphUpload_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphExecDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "graphExec: #{"0x%016x" % defi["graphExec"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphExecDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphExecUpdate_entry"] = lambda { |defi|
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
$event_lambdas["lttng_ust_hip:hipGraphExecUpdate_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "hErrorNode_out_val: #{"0x%016x" % defi["hErrorNode_out_val"]}"
  s << ', '
  s << "updateResult_out_val: #{HIP::HipGraphExecUpdateResult.from_native(defi["updateResult_out_val"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphAddKernelNode_entry"] = lambda { |defi|
  s = "{ "
  s << "pGraphNode: #{"0x%016x" % defi["pGraphNode"]}"
  s << ', '
  s << "graph: #{"0x%016x" % defi["graph"]}"
  s << ', '
  s << "pDependencies: #{"0x%016x" % defi["pDependencies"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "pNodeParams: #{"0x%016x" % defi["pNodeParams"]}"
  s << ', '
  s << "pDependencies_vals: [ #{defi["pDependencies_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "pNodeParams_val: #{defi["pNodeParams_val"].size > 0 ? HIP::HipKernelNodeParams.new(FFI::MemoryPointer.from_string(defi["pNodeParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphAddKernelNode_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pGraphNode_val: #{"0x%016x" % defi["pGraphNode_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphKernelNodeGetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "node: #{"0x%016x" % defi["node"]}"
  s << ', '
  s << "pNodeParams: #{"0x%016x" % defi["pNodeParams"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphKernelNodeGetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pNodeParams_val: #{defi["pNodeParams_val"].size > 0 ? HIP::HipKernelNodeParams.new(FFI::MemoryPointer.from_string(defi["pNodeParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphKernelNodeSetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "node: #{"0x%016x" % defi["node"]}"
  s << ', '
  s << "pNodeParams: #{"0x%016x" % defi["pNodeParams"]}"
  s << ', '
  s << "pNodeParams_val: #{defi["pNodeParams_val"].size > 0 ? HIP::HipKernelNodeParams.new(FFI::MemoryPointer.from_string(defi["pNodeParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphKernelNodeSetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphExecKernelNodeSetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraphExec: #{"0x%016x" % defi["hGraphExec"]}"
  s << ', '
  s << "node: #{"0x%016x" % defi["node"]}"
  s << ', '
  s << "pNodeParams: #{"0x%016x" % defi["pNodeParams"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphExecKernelNodeSetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphAddMemcpyNode_entry"] = lambda { |defi|
  s = "{ "
  s << "pGraphNode: #{"0x%016x" % defi["pGraphNode"]}"
  s << ', '
  s << "graph: #{"0x%016x" % defi["graph"]}"
  s << ', '
  s << "pDependencies: #{"0x%016x" % defi["pDependencies"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "pCopyParams: #{"0x%016x" % defi["pCopyParams"]}"
  s << ', '
  s << "pDependencies_vals: [ #{defi["pDependencies_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "pCopyParams_val: #{defi["pCopyParams_val"].size > 0 ? HIP::HipMemcpy3DParms.new(FFI::MemoryPointer.from_string(defi["pCopyParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphAddMemcpyNode_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pGraphNode_val: #{"0x%016x" % defi["pGraphNode_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphMemcpyNodeGetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "node: #{"0x%016x" % defi["node"]}"
  s << ', '
  s << "pNodeParams: #{"0x%016x" % defi["pNodeParams"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphMemcpyNodeGetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pNodeParams_val: #{defi["pNodeParams_val"].size > 0 ? HIP::HipMemcpy3DParms.new(FFI::MemoryPointer.from_string(defi["pNodeParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphMemcpyNodeSetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "node: #{"0x%016x" % defi["node"]}"
  s << ', '
  s << "pNodeParams: #{"0x%016x" % defi["pNodeParams"]}"
  s << ', '
  s << "pNodeParams_val: #{defi["pNodeParams_val"].size > 0 ? HIP::HipMemcpy3DParms.new(FFI::MemoryPointer.from_string(defi["pNodeParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphMemcpyNodeSetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphKernelNodeSetAttribute_entry"] = lambda { |defi|
  s = "{ "
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "attr: #{HIP::HipKernelNodeAttrID.from_native(defi["attr"], nil)}"
  s << ', '
  s << "value: #{"0x%016x" % defi["value"]}"
  s << ', '
  s << "value_val: #{defi["value_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphKernelNodeSetAttribute_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphKernelNodeGetAttribute_entry"] = lambda { |defi|
  s = "{ "
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "attr: #{HIP::HipKernelNodeAttrID.from_native(defi["attr"], nil)}"
  s << ', '
  s << "value: #{"0x%016x" % defi["value"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphKernelNodeGetAttribute_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "value_val: #{defi["value_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphExecMemcpyNodeSetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraphExec: #{"0x%016x" % defi["hGraphExec"]}"
  s << ', '
  s << "node: #{"0x%016x" % defi["node"]}"
  s << ', '
  s << "pNodeParams: #{"0x%016x" % defi["pNodeParams"]}"
  s << ', '
  s << "pNodeParams_val: #{defi["pNodeParams_val"].size > 0 ? HIP::HipMemcpy3DParms.new(FFI::MemoryPointer.from_string(defi["pNodeParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphExecMemcpyNodeSetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphAddMemcpyNode1D_entry"] = lambda { |defi|
  s = "{ "
  s << "pGraphNode: #{"0x%016x" % defi["pGraphNode"]}"
  s << ', '
  s << "graph: #{"0x%016x" % defi["graph"]}"
  s << ', '
  s << "pDependencies: #{"0x%016x" % defi["pDependencies"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << ', '
  s << "pDependencies_vals: [ #{defi["pDependencies_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphAddMemcpyNode1D_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pGraphNode_val: #{"0x%016x" % defi["pGraphNode_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphMemcpyNodeSetParams1D_entry"] = lambda { |defi|
  s = "{ "
  s << "node: #{"0x%016x" % defi["node"]}"
  s << ', '
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphMemcpyNodeSetParams1D_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphExecMemcpyNodeSetParams1D_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraphExec: #{"0x%016x" % defi["hGraphExec"]}"
  s << ', '
  s << "node: #{"0x%016x" % defi["node"]}"
  s << ', '
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphExecMemcpyNodeSetParams1D_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphAddMemcpyNodeFromSymbol_entry"] = lambda { |defi|
  s = "{ "
  s << "pGraphNode: #{"0x%016x" % defi["pGraphNode"]}"
  s << ', '
  s << "graph: #{"0x%016x" % defi["graph"]}"
  s << ', '
  s << "pDependencies: #{"0x%016x" % defi["pDependencies"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "symbol: #{"0x%016x" % defi["symbol"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << ', '
  s << "pDependencies_vals: [ #{defi["pDependencies_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphAddMemcpyNodeFromSymbol_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pGraphNode_val: #{"0x%016x" % defi["pGraphNode_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphMemcpyNodeSetParamsFromSymbol_entry"] = lambda { |defi|
  s = "{ "
  s << "node: #{"0x%016x" % defi["node"]}"
  s << ', '
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "symbol: #{"0x%016x" % defi["symbol"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphMemcpyNodeSetParamsFromSymbol_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphExecMemcpyNodeSetParamsFromSymbol_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraphExec: #{"0x%016x" % defi["hGraphExec"]}"
  s << ', '
  s << "node: #{"0x%016x" % defi["node"]}"
  s << ', '
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "symbol: #{"0x%016x" % defi["symbol"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphExecMemcpyNodeSetParamsFromSymbol_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphAddMemcpyNodeToSymbol_entry"] = lambda { |defi|
  s = "{ "
  s << "pGraphNode: #{"0x%016x" % defi["pGraphNode"]}"
  s << ', '
  s << "graph: #{"0x%016x" % defi["graph"]}"
  s << ', '
  s << "pDependencies: #{"0x%016x" % defi["pDependencies"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "symbol: #{"0x%016x" % defi["symbol"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << ', '
  s << "pDependencies_vals: [ #{defi["pDependencies_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphAddMemcpyNodeToSymbol_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pGraphNode_val: #{"0x%016x" % defi["pGraphNode_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphMemcpyNodeSetParamsToSymbol_entry"] = lambda { |defi|
  s = "{ "
  s << "node: #{"0x%016x" % defi["node"]}"
  s << ', '
  s << "symbol: #{"0x%016x" % defi["symbol"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphMemcpyNodeSetParamsToSymbol_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphExecMemcpyNodeSetParamsToSymbol_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraphExec: #{"0x%016x" % defi["hGraphExec"]}"
  s << ', '
  s << "node: #{"0x%016x" % defi["node"]}"
  s << ', '
  s << "symbol: #{"0x%016x" % defi["symbol"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphExecMemcpyNodeSetParamsToSymbol_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphAddMemsetNode_entry"] = lambda { |defi|
  s = "{ "
  s << "pGraphNode: #{"0x%016x" % defi["pGraphNode"]}"
  s << ', '
  s << "graph: #{"0x%016x" % defi["graph"]}"
  s << ', '
  s << "pDependencies: #{"0x%016x" % defi["pDependencies"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "pMemsetParams: #{"0x%016x" % defi["pMemsetParams"]}"
  s << ', '
  s << "pDependencies_vals: [ #{defi["pDependencies_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "pMemsetParams_val: #{defi["pMemsetParams_val"].size > 0 ? HIP::HipMemsetParams.new(FFI::MemoryPointer.from_string(defi["pMemsetParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphAddMemsetNode_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pGraphNode_val: #{"0x%016x" % defi["pGraphNode_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphMemsetNodeGetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "node: #{"0x%016x" % defi["node"]}"
  s << ', '
  s << "pNodeParams: #{"0x%016x" % defi["pNodeParams"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphMemsetNodeGetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pNodeParams_val: #{defi["pNodeParams_val"].size > 0 ? HIP::HipMemsetParams.new(FFI::MemoryPointer.from_string(defi["pNodeParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphMemsetNodeSetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "node: #{"0x%016x" % defi["node"]}"
  s << ', '
  s << "pNodeParams: #{"0x%016x" % defi["pNodeParams"]}"
  s << ', '
  s << "pNodeParams_val: #{defi["pNodeParams_val"].size > 0 ? HIP::HipMemsetParams.new(FFI::MemoryPointer.from_string(defi["pNodeParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphMemsetNodeSetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphExecMemsetNodeSetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraphExec: #{"0x%016x" % defi["hGraphExec"]}"
  s << ', '
  s << "node: #{"0x%016x" % defi["node"]}"
  s << ', '
  s << "pNodeParams: #{"0x%016x" % defi["pNodeParams"]}"
  s << ', '
  s << "pNodeParams_val: #{defi["pNodeParams_val"].size > 0 ? HIP::HipMemsetParams.new(FFI::MemoryPointer.from_string(defi["pNodeParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphExecMemsetNodeSetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphAddHostNode_entry"] = lambda { |defi|
  s = "{ "
  s << "pGraphNode: #{"0x%016x" % defi["pGraphNode"]}"
  s << ', '
  s << "graph: #{"0x%016x" % defi["graph"]}"
  s << ', '
  s << "pDependencies: #{"0x%016x" % defi["pDependencies"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "pNodeParams: #{"0x%016x" % defi["pNodeParams"]}"
  s << ', '
  s << "pDependencies_vals: [ #{defi["pDependencies_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "pNodeParams_val: #{defi["pNodeParams_val"].size > 0 ? HIP::HipHostNodeParams.new(FFI::MemoryPointer.from_string(defi["pNodeParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphAddHostNode_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pGraphNode_val: #{"0x%016x" % defi["pGraphNode_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphHostNodeGetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "node: #{"0x%016x" % defi["node"]}"
  s << ', '
  s << "pNodeParams: #{"0x%016x" % defi["pNodeParams"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphHostNodeGetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pNodeParams_val: #{defi["pNodeParams_val"].size > 0 ? HIP::HipHostNodeParams.new(FFI::MemoryPointer.from_string(defi["pNodeParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphHostNodeSetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "node: #{"0x%016x" % defi["node"]}"
  s << ', '
  s << "pNodeParams: #{"0x%016x" % defi["pNodeParams"]}"
  s << ', '
  s << "pNodeParams_val: #{defi["pNodeParams_val"].size > 0 ? HIP::HipHostNodeParams.new(FFI::MemoryPointer.from_string(defi["pNodeParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphHostNodeSetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphExecHostNodeSetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraphExec: #{"0x%016x" % defi["hGraphExec"]}"
  s << ', '
  s << "node: #{"0x%016x" % defi["node"]}"
  s << ', '
  s << "pNodeParams: #{"0x%016x" % defi["pNodeParams"]}"
  s << ', '
  s << "pNodeParams_val: #{defi["pNodeParams_val"].size > 0 ? HIP::HipHostNodeParams.new(FFI::MemoryPointer.from_string(defi["pNodeParams_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphExecHostNodeSetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphAddChildGraphNode_entry"] = lambda { |defi|
  s = "{ "
  s << "pGraphNode: #{"0x%016x" % defi["pGraphNode"]}"
  s << ', '
  s << "graph: #{"0x%016x" % defi["graph"]}"
  s << ', '
  s << "pDependencies: #{"0x%016x" % defi["pDependencies"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "childGraph: #{"0x%016x" % defi["childGraph"]}"
  s << ', '
  s << "pDependencies_vals: [ #{defi["pDependencies_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphAddChildGraphNode_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pGraphNode_val: #{"0x%016x" % defi["pGraphNode_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphChildGraphNodeGetGraph_entry"] = lambda { |defi|
  s = "{ "
  s << "node: #{"0x%016x" % defi["node"]}"
  s << ', '
  s << "pGraph: #{"0x%016x" % defi["pGraph"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphChildGraphNodeGetGraph_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pGraph_val: #{"0x%016x" % defi["pGraph_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphExecChildGraphNodeSetParams_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraphExec: #{"0x%016x" % defi["hGraphExec"]}"
  s << ', '
  s << "node: #{"0x%016x" % defi["node"]}"
  s << ', '
  s << "childGraph: #{"0x%016x" % defi["childGraph"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphExecChildGraphNodeSetParams_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphAddEmptyNode_entry"] = lambda { |defi|
  s = "{ "
  s << "pGraphNode: #{"0x%016x" % defi["pGraphNode"]}"
  s << ', '
  s << "graph: #{"0x%016x" % defi["graph"]}"
  s << ', '
  s << "pDependencies: #{"0x%016x" % defi["pDependencies"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "pDependencies_vals: [ #{defi["pDependencies_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphAddEmptyNode_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pGraphNode_val: #{"0x%016x" % defi["pGraphNode_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphAddEventRecordNode_entry"] = lambda { |defi|
  s = "{ "
  s << "pGraphNode: #{"0x%016x" % defi["pGraphNode"]}"
  s << ', '
  s << "graph: #{"0x%016x" % defi["graph"]}"
  s << ', '
  s << "pDependencies: #{"0x%016x" % defi["pDependencies"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "event: #{"0x%016x" % defi["event"]}"
  s << ', '
  s << "pDependencies_vals: [ #{defi["pDependencies_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphAddEventRecordNode_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pGraphNode_val: #{"0x%016x" % defi["pGraphNode_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphEventRecordNodeGetEvent_entry"] = lambda { |defi|
  s = "{ "
  s << "node: #{"0x%016x" % defi["node"]}"
  s << ', '
  s << "event_out: #{"0x%016x" % defi["event_out"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphEventRecordNodeGetEvent_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "event_out_val: #{"0x%016x" % defi["event_out_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphEventRecordNodeSetEvent_entry"] = lambda { |defi|
  s = "{ "
  s << "node: #{"0x%016x" % defi["node"]}"
  s << ', '
  s << "event: #{"0x%016x" % defi["event"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphEventRecordNodeSetEvent_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphExecEventRecordNodeSetEvent_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraphExec: #{"0x%016x" % defi["hGraphExec"]}"
  s << ', '
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "event: #{"0x%016x" % defi["event"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphExecEventRecordNodeSetEvent_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphAddEventWaitNode_entry"] = lambda { |defi|
  s = "{ "
  s << "pGraphNode: #{"0x%016x" % defi["pGraphNode"]}"
  s << ', '
  s << "graph: #{"0x%016x" % defi["graph"]}"
  s << ', '
  s << "pDependencies: #{"0x%016x" % defi["pDependencies"]}"
  s << ', '
  s << "numDependencies: #{defi["numDependencies"]}"
  s << ', '
  s << "event: #{"0x%016x" % defi["event"]}"
  s << ', '
  s << "pDependencies_vals: [ #{defi["pDependencies_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphAddEventWaitNode_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pGraphNode_val: #{"0x%016x" % defi["pGraphNode_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphEventWaitNodeGetEvent_entry"] = lambda { |defi|
  s = "{ "
  s << "node: #{"0x%016x" % defi["node"]}"
  s << ', '
  s << "event_out: #{"0x%016x" % defi["event_out"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphEventWaitNodeGetEvent_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "event_out_val: #{"0x%016x" % defi["event_out_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphEventWaitNodeSetEvent_entry"] = lambda { |defi|
  s = "{ "
  s << "node: #{"0x%016x" % defi["node"]}"
  s << ', '
  s << "event: #{"0x%016x" % defi["event"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphEventWaitNodeSetEvent_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphExecEventWaitNodeSetEvent_entry"] = lambda { |defi|
  s = "{ "
  s << "hGraphExec: #{"0x%016x" % defi["hGraphExec"]}"
  s << ', '
  s << "hNode: #{"0x%016x" % defi["hNode"]}"
  s << ', '
  s << "event: #{"0x%016x" % defi["event"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphExecEventWaitNodeSetEvent_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceGetGraphMemAttribute_entry"] = lambda { |defi|
  s = "{ "
  s << "device: #{defi["device"]}"
  s << ', '
  s << "attr: #{HIP::HipGraphMemAttributeType.from_native(defi["attr"], nil)}"
  s << ', '
  s << "value: #{"0x%016x" % defi["value"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceGetGraphMemAttribute_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "value_val: #{defi["value_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceSetGraphMemAttribute_entry"] = lambda { |defi|
  s = "{ "
  s << "device: #{defi["device"]}"
  s << ', '
  s << "attr: #{HIP::HipGraphMemAttributeType.from_native(defi["attr"], nil)}"
  s << ', '
  s << "value: #{"0x%016x" % defi["value"]}"
  s << ', '
  s << "value_val: #{defi["value_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceSetGraphMemAttribute_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceGraphMemTrim_entry"] = lambda { |defi|
  s = "{ "
  s << "device: #{defi["device"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipDeviceGraphMemTrim_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipUserObjectCreate_entry"] = lambda { |defi|
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
$event_lambdas["lttng_ust_hip:hipUserObjectCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "object_out_val: #{"0x%016x" % defi["object_out_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipUserObjectRelease_entry"] = lambda { |defi|
  s = "{ "
  s << "object: #{"0x%016x" % defi["object"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipUserObjectRelease_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipUserObjectRetain_entry"] = lambda { |defi|
  s = "{ "
  s << "object: #{"0x%016x" % defi["object"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipUserObjectRetain_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphRetainUserObject_entry"] = lambda { |defi|
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
$event_lambdas["lttng_ust_hip:hipGraphRetainUserObject_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphReleaseUserObject_entry"] = lambda { |defi|
  s = "{ "
  s << "graph: #{"0x%016x" % defi["graph"]}"
  s << ', '
  s << "object: #{"0x%016x" % defi["object"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphReleaseUserObject_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemAddressFree_entry"] = lambda { |defi|
  s = "{ "
  s << "devPtr: #{"0x%016x" % defi["devPtr"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemAddressFree_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemAddressReserve_entry"] = lambda { |defi|
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
$event_lambdas["lttng_ust_hip:hipMemAddressReserve_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "ptr_val: #{"0x%016x" % defi["ptr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "prop: #{"0x%016x" % defi["prop"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << ', '
  s << "prop_val: #{defi["prop_val"].size > 0 ? HIP::HipMemAllocationProp.new(FFI::MemoryPointer.from_string(defi["prop_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "handle_val: #{"0x%016x" % defi["handle_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemExportToShareableHandle_entry"] = lambda { |defi|
  s = "{ "
  s << "shareableHandle: #{"0x%016x" % defi["shareableHandle"]}"
  s << ', '
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << ', '
  s << "handleType: #{HIP::HipMemAllocationHandleType.from_native(defi["handleType"], nil)}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemExportToShareableHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "shareableHandle_val: #{defi["shareableHandle_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemGetAccess_entry"] = lambda { |defi|
  s = "{ "
  s << "flags: #{"0x%016x" % defi["flags"]}"
  s << ', '
  s << "location: #{"0x%016x" % defi["location"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "location_val: #{defi["location_val"].size > 0 ? HIP::HipMemLocation.new(FFI::MemoryPointer.from_string(defi["location_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemGetAccess_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "flags_val: #{defi["flags_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemGetAllocationGranularity_entry"] = lambda { |defi|
  s = "{ "
  s << "granularity: #{"0x%016x" % defi["granularity"]}"
  s << ', '
  s << "prop: #{"0x%016x" % defi["prop"]}"
  s << ', '
  s << "option: #{HIP::HipMemAllocationGranularity_flags.from_native(defi["option"], nil)}"
  s << ', '
  s << "prop_val: #{defi["prop_val"].size > 0 ? HIP::HipMemAllocationProp.new(FFI::MemoryPointer.from_string(defi["prop_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemGetAllocationGranularity_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "granularity_val: #{defi["granularity_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemGetAllocationPropertiesFromHandle_entry"] = lambda { |defi|
  s = "{ "
  s << "prop: #{"0x%016x" % defi["prop"]}"
  s << ', '
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemGetAllocationPropertiesFromHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "prop_val: #{defi["prop_val"].size > 0 ? HIP::HipMemAllocationProp.new(FFI::MemoryPointer.from_string(defi["prop_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemImportFromShareableHandle_entry"] = lambda { |defi|
  s = "{ "
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << ', '
  s << "osHandle: #{"0x%016x" % defi["osHandle"]}"
  s << ', '
  s << "shHandleType: #{HIP::HipMemAllocationHandleType.from_native(defi["shHandleType"], nil)}"
  s << ', '
  s << "osHandle_val: #{defi["osHandle_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemImportFromShareableHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "handle_val: #{"0x%016x" % defi["handle_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemMap_entry"] = lambda { |defi|
  s = "{ "
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemMap_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemMapArrayAsync_entry"] = lambda { |defi|
  s = "{ "
  s << "mapInfoList: #{"0x%016x" % defi["mapInfoList"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "mapInfoList_val: #{defi["mapInfoList_val"].size > 0 ? HIP::HipArrayMapInfo.new(FFI::MemoryPointer.from_string(defi["mapInfoList_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemMapArrayAsync_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemRelease_entry"] = lambda { |defi|
  s = "{ "
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemRelease_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemRetainAllocationHandle_entry"] = lambda { |defi|
  s = "{ "
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << ', '
  s << "addr: #{"0x%016x" % defi["addr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemRetainAllocationHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "handle_val: #{"0x%016x" % defi["handle_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemSetAccess_entry"] = lambda { |defi|
  s = "{ "
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "desc_vals: [ #{p = FFI::MemoryPointer.from_string(defi["desc_vals"]); sz = HIP::HipMemAccessDesc.size; n = p.size / sz; (0...n).collect { |i| HIP::HipMemAccessDesc.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemSetAccess_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemUnmap_entry"] = lambda { |defi|
  s = "{ "
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemUnmap_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGLGetDevices_entry"] = lambda { |defi|
  s = "{ "
  s << "pHipDeviceCount: #{"0x%016x" % defi["pHipDeviceCount"]}"
  s << ', '
  s << "pHipDevices: #{"0x%016x" % defi["pHipDevices"]}"
  s << ', '
  s << "hipDeviceCount: #{defi["hipDeviceCount"]}"
  s << ', '
  s << "deviceList: #{HIP::HipGLDeviceList.from_native(defi["deviceList"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGLGetDevices_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pHipDeviceCount_val: #{defi["pHipDeviceCount_val"]}"
  s << ', '
  s << "pHipDevices_vals: #{defi["pHipDevices_vals"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphicsGLRegisterBuffer_entry"] = lambda { |defi|
  s = "{ "
  s << "resource: #{"0x%016x" % defi["resource"]}"
  s << ', '
  s << "buffer: #{defi["buffer"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphicsGLRegisterBuffer_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "resource_val: #{"0x%016x" % defi["resource_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphicsGLRegisterImage_entry"] = lambda { |defi|
  s = "{ "
  s << "resource: #{"0x%016x" % defi["resource"]}"
  s << ', '
  s << "image: #{defi["image"]}"
  s << ', '
  s << "target: #{defi["target"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphicsGLRegisterImage_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "resource_val: #{"0x%016x" % defi["resource_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphicsMapResources_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "resources: #{"0x%016x" % defi["resources"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "resources_vals: [ #{defi["resources_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphicsMapResources_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphicsSubResourceGetMappedArray_entry"] = lambda { |defi|
  s = "{ "
  s << "array: #{"0x%016x" % defi["array"]}"
  s << ', '
  s << "resource: #{"0x%016x" % defi["resource"]}"
  s << ', '
  s << "arrayIndex: #{defi["arrayIndex"]}"
  s << ', '
  s << "mipLevel: #{defi["mipLevel"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphicsSubResourceGetMappedArray_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "array_val: #{"0x%016x" % defi["array_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphicsResourceGetMappedPointer_entry"] = lambda { |defi|
  s = "{ "
  s << "devPtr: #{"0x%016x" % defi["devPtr"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << ', '
  s << "resource: #{"0x%016x" % defi["resource"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphicsResourceGetMappedPointer_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "devPtr_val: #{"0x%016x" % defi["devPtr_val"]}"
  s << ', '
  s << "size_val: #{defi["size_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphicsUnmapResources_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "resources: #{"0x%016x" % defi["resources"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "resources_vals: [ #{defi["resources_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphicsUnmapResources_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphicsUnregisterResource_entry"] = lambda { |defi|
  s = "{ "
  s << "resource: #{"0x%016x" % defi["resource"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphicsUnregisterResource_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpy_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "sizeBytes: #{defi["sizeBytes"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpy_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyToSymbol_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "symbol: #{"0x%016x" % defi["symbol"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "sizeBytes: #{defi["sizeBytes"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyToSymbol_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyFromSymbol_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "symbol: #{"0x%016x" % defi["symbol"]}"
  s << ', '
  s << "sizeBytes: #{defi["sizeBytes"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyFromSymbol_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpy2D_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "dpitch: #{defi["dpitch"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "spitch: #{defi["spitch"]}"
  s << ', '
  s << "width: #{defi["width"]}"
  s << ', '
  s << "height: #{defi["height"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpy2D_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpy2DFromArray_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "dpitch: #{defi["dpitch"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "wOffset: #{defi["wOffset"]}"
  s << ', '
  s << "hOffset: #{defi["hOffset"]}"
  s << ', '
  s << "width: #{defi["width"]}"
  s << ', '
  s << "height: #{defi["height"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpy2DFromArray_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpy3D_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpy3D_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemset_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "sizeBytes: #{defi["sizeBytes"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemset_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemsetAsync_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "sizeBytes: #{defi["sizeBytes"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemsetAsync_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemset2D_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "pitch: #{defi["pitch"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "width: #{defi["width"]}"
  s << ', '
  s << "height: #{defi["height"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemset2D_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemset2DAsync_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "pitch: #{defi["pitch"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "width: #{defi["width"]}"
  s << ', '
  s << "height: #{defi["height"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemset2DAsync_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemset3DAsync_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "pitchedDevPtr: #{defi["pitchedDevPtr"].size > 0 ? HIP::HipPitchedPtr.new(FFI::MemoryPointer.from_string(defi["pitchedDevPtr"])) : nil}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "extent: #{defi["extent"].size > 0 ? HIP::HipExtent.new(FFI::MemoryPointer.from_string(defi["extent"])) : nil}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemset3DAsync_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemset3D_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "pitchedDevPtr: #{defi["pitchedDevPtr"].size > 0 ? HIP::HipPitchedPtr.new(FFI::MemoryPointer.from_string(defi["pitchedDevPtr"])) : nil}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << ', '
  s << "extent: #{defi["extent"].size > 0 ? HIP::HipExtent.new(FFI::MemoryPointer.from_string(defi["extent"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemset3D_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyAsync_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "sizeBytes: #{defi["sizeBytes"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyAsync_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpy3DAsync_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpy3DAsync_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpy2DAsync_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "dpitch: #{defi["dpitch"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "spitch: #{defi["spitch"]}"
  s << ', '
  s << "width: #{defi["width"]}"
  s << ', '
  s << "height: #{defi["height"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpy2DAsync_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyFromSymbolAsync_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "symbol: #{"0x%016x" % defi["symbol"]}"
  s << ', '
  s << "sizeBytes: #{defi["sizeBytes"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyFromSymbolAsync_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyToSymbolAsync_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "symbol: #{"0x%016x" % defi["symbol"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "sizeBytes: #{defi["sizeBytes"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyToSymbolAsync_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyFromArray_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "wOffsetSrc: #{defi["wOffsetSrc"]}"
  s << ', '
  s << "hOffset: #{defi["hOffset"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpyFromArray_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpy2DToArray_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "wOffset: #{defi["wOffset"]}"
  s << ', '
  s << "hOffset: #{defi["hOffset"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "spitch: #{defi["spitch"]}"
  s << ', '
  s << "width: #{defi["width"]}"
  s << ', '
  s << "height: #{defi["height"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpy2DToArray_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpy2DFromArrayAsync_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "dpitch: #{defi["dpitch"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "wOffsetSrc: #{defi["wOffsetSrc"]}"
  s << ', '
  s << "hOffsetSrc: #{defi["hOffsetSrc"]}"
  s << ', '
  s << "width: #{defi["width"]}"
  s << ', '
  s << "height: #{defi["height"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpy2DFromArrayAsync_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpy2DToArrayAsync_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "dst: #{"0x%016x" % defi["dst"]}"
  s << ', '
  s << "wOffset: #{defi["wOffset"]}"
  s << ', '
  s << "hOffset: #{defi["hOffset"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "spitch: #{defi["spitch"]}"
  s << ', '
  s << "width: #{defi["width"]}"
  s << ', '
  s << "height: #{defi["height"]}"
  s << ', '
  s << "kind: #{HIP::HipMemcpyKind.from_native(defi["kind"], nil)}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipMemcpy2DToArrayAsync_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamQuery_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamQuery_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamSynchronize_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamSynchronize_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamGetPriority_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "priority: #{"0x%016x" % defi["priority"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamGetPriority_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamWaitEvent_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "event: #{"0x%016x" % defi["event"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamWaitEvent_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamGetFlags_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "flags: #{"0x%016x" % defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamGetFlags_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamAddCallback_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "callback: #{"0x%016x" % defi["callback"]}"
  s << ', '
  s << "userData: #{"0x%016x" % defi["userData"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamAddCallback_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipEventRecord_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "event: #{"0x%016x" % defi["event"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipEventRecord_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipLaunchCooperativeKernel_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "f: #{"0x%016x" % defi["f"]}"
  s << ', '
  s << "gridDim: #{defi["gridDim"].size > 0 ? HIP::Dim3.new(FFI::MemoryPointer.from_string(defi["gridDim"])) : nil}"
  s << ', '
  s << "blockDim: #{defi["blockDim"].size > 0 ? HIP::Dim3.new(FFI::MemoryPointer.from_string(defi["blockDim"])) : nil}"
  s << ', '
  s << "kernelParams: #{"0x%016x" % defi["kernelParams"]}"
  s << ', '
  s << "sharedMemBytes: #{defi["sharedMemBytes"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipLaunchCooperativeKernel_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipLaunchKernel_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "function_address: #{"0x%016x" % defi["function_address"]}"
  s << ', '
  s << "numBlocks: #{defi["numBlocks"].size > 0 ? HIP::Dim3.new(FFI::MemoryPointer.from_string(defi["numBlocks"])) : nil}"
  s << ', '
  s << "dimBlocks: #{defi["dimBlocks"].size > 0 ? HIP::Dim3.new(FFI::MemoryPointer.from_string(defi["dimBlocks"])) : nil}"
  s << ', '
  s << "args: #{"0x%016x" % defi["args"]}"
  s << ', '
  s << "sharedMemBytes: #{defi["sharedMemBytes"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipLaunchKernel_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphLaunch_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "graphExec: #{"0x%016x" % defi["graphExec"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphLaunch_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamBeginCapture_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "mode: #{HIP::HipStreamCaptureMode.from_native(defi["mode"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamBeginCapture_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamEndCapture_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "pGraph: #{"0x%016x" % defi["pGraph"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamEndCapture_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamIsCapturing_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "pCaptureStatus: #{"0x%016x" % defi["pCaptureStatus"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamIsCapturing_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamGetCaptureInfo_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "pCaptureStatus: #{"0x%016x" % defi["pCaptureStatus"]}"
  s << ', '
  s << "pId: #{"0x%016x" % defi["pId"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamGetCaptureInfo_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipStreamGetCaptureInfo_v2_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
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
$event_lambdas["lttng_ust_hip:hipStreamGetCaptureInfo_v2_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipLaunchHostFunc_spt_entry"] = lambda { |defi|
  s = "{ "
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "fn: #{"0x%016x" % defi["fn"]}"
  s << ', '
  s << "userData: #{"0x%016x" % defi["userData"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipLaunchHostFunc_spt_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hiprtcGetErrorString_entry"] = lambda { |defi|
  s = "{ "
  s << "result: #{HIP::HiprtcResult.from_native(defi["result"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hiprtcGetErrorString_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{"0x%016x" % defi["hipResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hiprtcVersion_entry"] = lambda { |defi|
  s = "{ "
  s << "major: #{"0x%016x" % defi["major"]}"
  s << ', '
  s << "minor: #{"0x%016x" % defi["minor"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hiprtcVersion_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HiprtcResult.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hiprtcAddNameExpression_entry"] = lambda { |defi|
  s = "{ "
  s << "prog: #{"0x%016x" % defi["prog"]}"
  s << ', '
  s << "name_expression: #{"0x%016x" % defi["name_expression"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hiprtcAddNameExpression_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HiprtcResult.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hiprtcCompileProgram_entry"] = lambda { |defi|
  s = "{ "
  s << "prog: #{"0x%016x" % defi["prog"]}"
  s << ', '
  s << "numOptions: #{defi["numOptions"]}"
  s << ', '
  s << "options: #{"0x%016x" % defi["options"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hiprtcCompileProgram_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HiprtcResult.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hiprtcCreateProgram_entry"] = lambda { |defi|
  s = "{ "
  s << "prog: #{"0x%016x" % defi["prog"]}"
  s << ', '
  s << "src: #{"0x%016x" % defi["src"]}"
  s << ', '
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "numHeaders: #{defi["numHeaders"]}"
  s << ', '
  s << "headers: #{"0x%016x" % defi["headers"]}"
  s << ', '
  s << "includeNames: #{"0x%016x" % defi["includeNames"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hiprtcCreateProgram_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HiprtcResult.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hiprtcDestroyProgram_entry"] = lambda { |defi|
  s = "{ "
  s << "prog: #{"0x%016x" % defi["prog"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hiprtcDestroyProgram_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HiprtcResult.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hiprtcGetLoweredName_entry"] = lambda { |defi|
  s = "{ "
  s << "prog: #{"0x%016x" % defi["prog"]}"
  s << ', '
  s << "name_expression: #{"0x%016x" % defi["name_expression"]}"
  s << ', '
  s << "lowered_name: #{"0x%016x" % defi["lowered_name"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hiprtcGetLoweredName_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HiprtcResult.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hiprtcGetProgramLog_entry"] = lambda { |defi|
  s = "{ "
  s << "prog: #{"0x%016x" % defi["prog"]}"
  s << ', '
  s << "log: #{"0x%016x" % defi["log"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hiprtcGetProgramLog_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HiprtcResult.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hiprtcGetProgramLogSize_entry"] = lambda { |defi|
  s = "{ "
  s << "prog: #{"0x%016x" % defi["prog"]}"
  s << ', '
  s << "logSizeRet: #{"0x%016x" % defi["logSizeRet"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hiprtcGetProgramLogSize_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HiprtcResult.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hiprtcGetCode_entry"] = lambda { |defi|
  s = "{ "
  s << "prog: #{"0x%016x" % defi["prog"]}"
  s << ', '
  s << "code: #{"0x%016x" % defi["code"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hiprtcGetCode_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HiprtcResult.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hiprtcGetCodeSize_entry"] = lambda { |defi|
  s = "{ "
  s << "prog: #{"0x%016x" % defi["prog"]}"
  s << ', '
  s << "codeSizeRet: #{"0x%016x" % defi["codeSizeRet"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hiprtcGetCodeSize_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HiprtcResult.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hiprtcGetBitcode_entry"] = lambda { |defi|
  s = "{ "
  s << "prog: #{"0x%016x" % defi["prog"]}"
  s << ', '
  s << "bitcode: #{"0x%016x" % defi["bitcode"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hiprtcGetBitcode_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HiprtcResult.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hiprtcGetBitcodeSize_entry"] = lambda { |defi|
  s = "{ "
  s << "prog: #{"0x%016x" % defi["prog"]}"
  s << ', '
  s << "bitcode_size: #{"0x%016x" % defi["bitcode_size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hiprtcGetBitcodeSize_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HiprtcResult.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hiprtcLinkCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "num_options: #{defi["num_options"]}"
  s << ', '
  s << "option_ptr: #{"0x%016x" % defi["option_ptr"]}"
  s << ', '
  s << "option_vals_pptr: #{"0x%016x" % defi["option_vals_pptr"]}"
  s << ', '
  s << "hip_link_state_ptr: #{"0x%016x" % defi["hip_link_state_ptr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hiprtcLinkCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HiprtcResult.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hiprtcLinkAddFile_entry"] = lambda { |defi|
  s = "{ "
  s << "hip_link_state: #{"0x%016x" % defi["hip_link_state"]}"
  s << ', '
  s << "input_type: #{HIP::HiprtcJITInputType.from_native(defi["input_type"], nil)}"
  s << ', '
  s << "file_path: #{"0x%016x" % defi["file_path"]}"
  s << ', '
  s << "num_options: #{defi["num_options"]}"
  s << ', '
  s << "options_ptr: #{"0x%016x" % defi["options_ptr"]}"
  s << ', '
  s << "option_values: #{"0x%016x" % defi["option_values"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hiprtcLinkAddFile_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HiprtcResult.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hiprtcLinkAddData_entry"] = lambda { |defi|
  s = "{ "
  s << "hip_link_state: #{"0x%016x" % defi["hip_link_state"]}"
  s << ', '
  s << "input_type: #{HIP::HiprtcJITInputType.from_native(defi["input_type"], nil)}"
  s << ', '
  s << "image: #{"0x%016x" % defi["image"]}"
  s << ', '
  s << "image_size: #{defi["image_size"]}"
  s << ', '
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "num_options: #{defi["num_options"]}"
  s << ', '
  s << "options_ptr: #{"0x%016x" % defi["options_ptr"]}"
  s << ', '
  s << "option_values: #{"0x%016x" % defi["option_values"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hiprtcLinkAddData_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HiprtcResult.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hiprtcLinkComplete_entry"] = lambda { |defi|
  s = "{ "
  s << "hip_link_state: #{"0x%016x" % defi["hip_link_state"]}"
  s << ', '
  s << "bin_out: #{"0x%016x" % defi["bin_out"]}"
  s << ', '
  s << "size_out: #{"0x%016x" % defi["size_out"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hiprtcLinkComplete_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HiprtcResult.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hiprtcLinkDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "hip_link_state: #{"0x%016x" % defi["hip_link_state"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hiprtcLinkDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HiprtcResult.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:amd_dbgapi_get_build_name_entry"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_hip:amd_dbgapi_get_build_name_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{"0x%016x" % defi["hipResult"]}"
  s << ', '
  s << "hipResult_val: #{defi["hipResult_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:amd_dbgapi_get_git_hash_entry"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_hip:amd_dbgapi_get_git_hash_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{"0x%016x" % defi["hipResult"]}"
  s << ', '
  s << "hipResult_val: #{defi["hipResult_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:amd_dbgapi_get_build_id_entry"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_hip:amd_dbgapi_get_build_id_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{defi["hipResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipExtModuleLaunchKernel_entry"] = lambda { |defi|
  s = "{ "
  s << "f: #{"0x%016x" % defi["f"]}"
  s << ', '
  s << "globalWorkSizeX: #{defi["globalWorkSizeX"]}"
  s << ', '
  s << "globalWorkSizeY: #{defi["globalWorkSizeY"]}"
  s << ', '
  s << "globalWorkSizeZ: #{defi["globalWorkSizeZ"]}"
  s << ', '
  s << "localWorkSizeX: #{defi["localWorkSizeX"]}"
  s << ', '
  s << "localWorkSizeY: #{defi["localWorkSizeY"]}"
  s << ', '
  s << "localWorkSizeZ: #{defi["localWorkSizeZ"]}"
  s << ', '
  s << "sharedMemBytes: #{defi["sharedMemBytes"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "kernelParams: #{"0x%016x" % defi["kernelParams"]}"
  s << ', '
  s << "extra: #{"0x%016x" % defi["extra"]}"
  s << ', '
  s << "startEvent: #{"0x%016x" % defi["startEvent"]}"
  s << ', '
  s << "stopEvent: #{"0x%016x" % defi["stopEvent"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipExtModuleLaunchKernel_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipHccModuleLaunchKernel_entry"] = lambda { |defi|
  s = "{ "
  s << "f: #{"0x%016x" % defi["f"]}"
  s << ', '
  s << "globalWorkSizeX: #{defi["globalWorkSizeX"]}"
  s << ', '
  s << "globalWorkSizeY: #{defi["globalWorkSizeY"]}"
  s << ', '
  s << "globalWorkSizeZ: #{defi["globalWorkSizeZ"]}"
  s << ', '
  s << "localWorkSizeX: #{defi["localWorkSizeX"]}"
  s << ', '
  s << "localWorkSizeY: #{defi["localWorkSizeY"]}"
  s << ', '
  s << "localWorkSizeZ: #{defi["localWorkSizeZ"]}"
  s << ', '
  s << "sharedMemBytes: #{defi["sharedMemBytes"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "kernelParams: #{"0x%016x" % defi["kernelParams"]}"
  s << ', '
  s << "extra: #{"0x%016x" % defi["extra"]}"
  s << ', '
  s << "startEvent: #{"0x%016x" % defi["startEvent"]}"
  s << ', '
  s << "stopEvent: #{"0x%016x" % defi["stopEvent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipHccModuleLaunchKernel_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:_ZN8hip_impl22hipLaunchKernelGGLImplEmRK4dim3S2_jP12ihipStream_tPPv_entry"] = lambda { |defi|
  s = "{ "
  s << "function_address: #{"0x%016x" % defi["function_address"]}"
  s << ', '
  s << "numBlocks: #{"0x%016x" % defi["numBlocks"]}"
  s << ', '
  s << "dimBlocks: #{"0x%016x" % defi["dimBlocks"]}"
  s << ', '
  s << "sharedMemBytes: #{defi["sharedMemBytes"]}"
  s << ', '
  s << "stream: #{"0x%016x" % defi["stream"]}"
  s << ', '
  s << "kernarg: #{"0x%016x" % defi["kernarg"]}"
  s << ', '
  s << "numBlocks_val: #{defi["numBlocks_val"].size > 0 ? HIP::Dim3.new(FFI::MemoryPointer.from_string(defi["numBlocks_val"])) : nil}"
  s << ', '
  s << "dimBlocks_val: #{defi["dimBlocks_val"].size > 0 ? HIP::Dim3.new(FFI::MemoryPointer.from_string(defi["dimBlocks_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:_ZN8hip_impl22hipLaunchKernelGGLImplEmRK4dim3S2_jP12ihipStream_tPPv_exit"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_hip:_Z22hipCreateSurfaceObjectPP13__hip_surfacePK15hipResourceDesc_entry"] = lambda { |defi|
  s = "{ "
  s << "pSurfObject: #{"0x%016x" % defi["pSurfObject"]}"
  s << ', '
  s << "pResDesc: #{"0x%016x" % defi["pResDesc"]}"
  s << ', '
  s << "pResDesc_val: #{defi["pResDesc_val"].size > 0 ? HIP::HipResourceDesc.new(FFI::MemoryPointer.from_string(defi["pResDesc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:_Z22hipCreateSurfaceObjectPP13__hip_surfacePK15hipResourceDesc_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << ', '
  s << "pSurfObject_val: #{"0x%016x" % defi["pSurfObject_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:_Z23hipDestroySurfaceObjectP13__hip_surface_entry"] = lambda { |defi|
  s = "{ "
  s << "surfaceObject: #{"0x%016x" % defi["surfaceObject"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:_Z23hipDestroySurfaceObjectP13__hip_surface_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:_Z24hipHccModuleLaunchKernelP18ihipModuleSymbol_tjjjjjjmP12ihipStream_tPPvS4_P11ihipEvent_tS6__entry"] = lambda { |defi|
  s = "{ "
  s << "f: #{"0x%016x" % defi["f"]}"
  s << ', '
  s << "globalWorkSizeX: #{defi["globalWorkSizeX"]}"
  s << ', '
  s << "globalWorkSizeY: #{defi["globalWorkSizeY"]}"
  s << ', '
  s << "globalWorkSizeZ: #{defi["globalWorkSizeZ"]}"
  s << ', '
  s << "localWorkSizeX: #{defi["localWorkSizeX"]}"
  s << ', '
  s << "localWorkSizeY: #{defi["localWorkSizeY"]}"
  s << ', '
  s << "localWorkSizeZ: #{defi["localWorkSizeZ"]}"
  s << ', '
  s << "sharedMemBytes: #{defi["sharedMemBytes"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "kernelParams: #{"0x%016x" % defi["kernelParams"]}"
  s << ', '
  s << "extra: #{"0x%016x" % defi["extra"]}"
  s << ', '
  s << "startEvent: #{"0x%016x" % defi["startEvent"]}"
  s << ', '
  s << "stopEvent: #{"0x%016x" % defi["stopEvent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:_Z24hipHccModuleLaunchKernelP18ihipModuleSymbol_tjjjjjjmP12ihipStream_tPPvS4_P11ihipEvent_tS6__exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:_Z24hipExtModuleLaunchKernelP18ihipModuleSymbol_tjjjjjjmP12ihipStream_tPPvS4_P11ihipEvent_tS6_j_entry"] = lambda { |defi|
  s = "{ "
  s << "f: #{"0x%016x" % defi["f"]}"
  s << ', '
  s << "globalWorkSizeX: #{defi["globalWorkSizeX"]}"
  s << ', '
  s << "globalWorkSizeY: #{defi["globalWorkSizeY"]}"
  s << ', '
  s << "globalWorkSizeZ: #{defi["globalWorkSizeZ"]}"
  s << ', '
  s << "localWorkSizeX: #{defi["localWorkSizeX"]}"
  s << ', '
  s << "localWorkSizeY: #{defi["localWorkSizeY"]}"
  s << ', '
  s << "localWorkSizeZ: #{defi["localWorkSizeZ"]}"
  s << ', '
  s << "sharedMemBytes: #{defi["sharedMemBytes"]}"
  s << ', '
  s << "hStream: #{"0x%016x" % defi["hStream"]}"
  s << ', '
  s << "kernelParams: #{"0x%016x" % defi["kernelParams"]}"
  s << ', '
  s << "extra: #{"0x%016x" % defi["extra"]}"
  s << ', '
  s << "startEvent: #{"0x%016x" % defi["startEvent"]}"
  s << ', '
  s << "stopEvent: #{"0x%016x" % defi["stopEvent"]}"
  s << ', '
  s << "flags: #{defi["flags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:_Z24hipExtModuleLaunchKernelP18ihipModuleSymbol_tjjjjjjmP12ihipStream_tPPvS4_P11ihipEvent_tS6_j_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphDebugDotPrint_entry"] = lambda { |defi|
  s = "{ "
  s << "graph: #{"0x%016x" % defi["graph"]}"
  s << ', '
  s << "fName: #{"0x%016x" % defi["fName"]}"
  s << ', '
  s << "flag: #{defi["flag"]}"
  s << ', '
  s << "fName_val: #{defi["fName_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGraphDebugDotPrint_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{HIP::HipError_t.from_native(defi["hipResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:__hipRegisterFatBinary_entry"] = lambda { |defi|
  s = "{ "
  s << "data: #{"0x%016x" % defi["data"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:__hipRegisterFatBinary_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{"0x%016x" % defi["hipResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:__hipRegisterFunction_entry"] = lambda { |defi|
  s = "{ "
  s << "modules: #{"0x%016x" % defi["modules"]}"
  s << ', '
  s << "hostFunction: #{"0x%016x" % defi["hostFunction"]}"
  s << ', '
  s << "deviceFunction: #{"0x%016x" % defi["deviceFunction"]}"
  s << ', '
  s << "deviceName: #{"0x%016x" % defi["deviceName"]}"
  s << ', '
  s << "threadLimit: #{defi["threadLimit"]}"
  s << ', '
  s << "tid: #{"0x%016x" % defi["tid"]}"
  s << ', '
  s << "bid: #{"0x%016x" % defi["bid"]}"
  s << ', '
  s << "blockDim: #{"0x%016x" % defi["blockDim"]}"
  s << ', '
  s << "gridDim: #{"0x%016x" % defi["gridDim"]}"
  s << ', '
  s << "wSize: #{"0x%016x" % defi["wSize"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:__hipRegisterFunction_exit"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_hip:__hipRegisterManagedVar_entry"] = lambda { |defi|
  s = "{ "
  s << "modules: #{"0x%016x" % defi["modules"]}"
  s << ', '
  s << "pointer: #{"0x%016x" % defi["pointer"]}"
  s << ', '
  s << "init_value: #{"0x%016x" % defi["init_value"]}"
  s << ', '
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "align: #{defi["align"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:__hipRegisterManagedVar_exit"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_hip:__hipRegisterSurface_entry"] = lambda { |defi|
  s = "{ "
  s << "modules: #{"0x%016x" % defi["modules"]}"
  s << ', '
  s << "var: #{"0x%016x" % defi["var"]}"
  s << ', '
  s << "hostVar: #{"0x%016x" % defi["hostVar"]}"
  s << ', '
  s << "deviceVar: #{"0x%016x" % defi["deviceVar"]}"
  s << ', '
  s << "type: #{defi["type"]}"
  s << ', '
  s << "ext: #{defi["ext"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:__hipRegisterSurface_exit"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_hip:__hipRegisterTexture_entry"] = lambda { |defi|
  s = "{ "
  s << "modules: #{"0x%016x" % defi["modules"]}"
  s << ', '
  s << "var: #{"0x%016x" % defi["var"]}"
  s << ', '
  s << "hostVar: #{"0x%016x" % defi["hostVar"]}"
  s << ', '
  s << "deviceVar: #{"0x%016x" % defi["deviceVar"]}"
  s << ', '
  s << "type: #{defi["type"]}"
  s << ', '
  s << "norm: #{defi["norm"]}"
  s << ', '
  s << "ext: #{defi["ext"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:__hipRegisterTexture_exit"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_hip:__hipRegisterVar_entry"] = lambda { |defi|
  s = "{ "
  s << "modules: #{"0x%016x" % defi["modules"]}"
  s << ', '
  s << "var: #{"0x%016x" % defi["var"]}"
  s << ', '
  s << "hostVar: #{"0x%016x" % defi["hostVar"]}"
  s << ', '
  s << "deviceVar: #{"0x%016x" % defi["deviceVar"]}"
  s << ', '
  s << "ext: #{defi["ext"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "constant: #{defi["constant"]}"
  s << ', '
  s << "global: #{defi["global"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:__hipRegisterVar_exit"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_hip:__hipUnregisterFatBinary_entry"] = lambda { |defi|
  s = "{ "
  s << "modules: #{"0x%016x" % defi["modules"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:__hipUnregisterFatBinary_exit"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGetCmdName_entry"] = lambda { |defi|
  s = "{ "
  s << "id: #{defi["id"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipGetCmdName_exit"] = lambda { |defi|
  s = "{ "
  s << "hipResult: #{"0x%016x" % defi["hipResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipRegisterTracerCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "function: #{"0x%016x" % defi["function"]}"
  s << " }"
}
$event_lambdas["lttng_ust_hip:hipRegisterTracerCallback_exit"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
