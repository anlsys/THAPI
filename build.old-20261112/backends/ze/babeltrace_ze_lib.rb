require_relative 'ze_library.rb'
$event_lambdas["lttng_ust_ze:zeInit_entry"] = lambda { |defi|
  s = "{ "
  s << "flags: [ #{ZE::ZEInitFlags.from_native(defi["flags"], nil).join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeInit_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDriverGet_entry"] = lambda { |defi|
  s = "{ "
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "phDrivers: #{"0x%016x" % defi["phDrivers"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDriverGet_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "phDrivers_vals: [ #{defi["phDrivers_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeInitDrivers_entry"] = lambda { |defi|
  s = "{ "
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "phDrivers: #{"0x%016x" % defi["phDrivers"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].size > 0 ? ZE::ZEInitDriverTypeDesc.new(FFI::MemoryPointer.from_string(defi["desc_val"])) : nil}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeInitDrivers_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "phDrivers_vals: [ #{defi["phDrivers_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDriverGetApiVersion_entry"] = lambda { |defi|
  s = "{ "
  s << "hDriver: #{"0x%016x" % defi["hDriver"]}"
  s << ', '
  s << "version: #{"0x%016x" % defi["version"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDriverGetApiVersion_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "version_val: #{ZE::ZEApiVersion.from_native(defi["version_val"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDriverGetProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hDriver: #{"0x%016x" % defi["hDriver"]}"
  s << ', '
  s << "pDriverProperties: #{"0x%016x" % defi["pDriverProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDriverGetProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pDriverProperties_val: #{defi["pDriverProperties_val"].size > 0 ? ZE::ZEDriverProperties.new(FFI::MemoryPointer.from_string(defi["pDriverProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDriverGetIpcProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hDriver: #{"0x%016x" % defi["hDriver"]}"
  s << ', '
  s << "pIpcProperties: #{"0x%016x" % defi["pIpcProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDriverGetIpcProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pIpcProperties_val: #{defi["pIpcProperties_val"].size > 0 ? ZE::ZEDriverIpcProperties.new(FFI::MemoryPointer.from_string(defi["pIpcProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDriverGetExtensionProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hDriver: #{"0x%016x" % defi["hDriver"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "pExtensionProperties: #{"0x%016x" % defi["pExtensionProperties"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDriverGetExtensionProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "pExtensionProperties_vals: [ #{p = FFI::MemoryPointer.from_string(defi["pExtensionProperties_vals"]); sz = ZE::ZEDriverExtensionProperties.size; n = p.size / sz; (0...n).collect { |i| ZE::ZEDriverExtensionProperties.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDriverGetExtensionFunctionAddress_entry"] = lambda { |defi|
  s = "{ "
  s << "hDriver: #{"0x%016x" % defi["hDriver"]}"
  s << ', '
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "ppFunctionAddress: #{"0x%016x" % defi["ppFunctionAddress"]}"
  s << ', '
  s << "name_val: #{defi["name_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDriverGetExtensionFunctionAddress_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "ppFunctionAddress_val: #{"0x%016x" % defi["ppFunctionAddress_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDriverGetLastErrorDescription_entry"] = lambda { |defi|
  s = "{ "
  s << "hDriver: #{"0x%016x" % defi["hDriver"]}"
  s << ', '
  s << "ppString: #{"0x%016x" % defi["ppString"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDriverGetLastErrorDescription_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "ppString_val_val: #{defi["ppString_val_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceGet_entry"] = lambda { |defi|
  s = "{ "
  s << "hDriver: #{"0x%016x" % defi["hDriver"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "phDevices: #{"0x%016x" % defi["phDevices"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceGet_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "phDevices_vals: [ #{defi["phDevices_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceGetRootDevice_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "phRootDevice: #{"0x%016x" % defi["phRootDevice"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceGetRootDevice_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phRootDevice_val: #{"0x%016x" % defi["phRootDevice_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceGetSubDevices_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "phSubdevices: #{"0x%016x" % defi["phSubdevices"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceGetSubDevices_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "phSubdevices_vals: [ #{defi["phSubdevices_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceGetProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pDeviceProperties: #{"0x%016x" % defi["pDeviceProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceGetProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pDeviceProperties_val: #{defi["pDeviceProperties_val"].size > 0 ? ZE::ZEDeviceProperties.new(FFI::MemoryPointer.from_string(defi["pDeviceProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceGetComputeProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pComputeProperties: #{"0x%016x" % defi["pComputeProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceGetComputeProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pComputeProperties_val: #{defi["pComputeProperties_val"].size > 0 ? ZE::ZEDeviceComputeProperties.new(FFI::MemoryPointer.from_string(defi["pComputeProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceGetModuleProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pModuleProperties: #{"0x%016x" % defi["pModuleProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceGetModuleProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pModuleProperties_val: #{defi["pModuleProperties_val"].size > 0 ? ZE::ZEDeviceModuleProperties.new(FFI::MemoryPointer.from_string(defi["pModuleProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceGetCommandQueueGroupProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "pCommandQueueGroupProperties: #{"0x%016x" % defi["pCommandQueueGroupProperties"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceGetCommandQueueGroupProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "pCommandQueueGroupProperties_vals: [ #{p = FFI::MemoryPointer.from_string(defi["pCommandQueueGroupProperties_vals"]); sz = ZE::ZECommandQueueGroupProperties.size; n = p.size / sz; (0...n).collect { |i| ZE::ZECommandQueueGroupProperties.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceGetMemoryProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "pMemProperties: #{"0x%016x" % defi["pMemProperties"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceGetMemoryProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "pMemProperties_vals: [ #{p = FFI::MemoryPointer.from_string(defi["pMemProperties_vals"]); sz = ZE::ZEDeviceMemoryProperties.size; n = p.size / sz; (0...n).collect { |i| ZE::ZEDeviceMemoryProperties.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceGetMemoryAccessProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pMemAccessProperties: #{"0x%016x" % defi["pMemAccessProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceGetMemoryAccessProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pMemAccessProperties_val: #{defi["pMemAccessProperties_val"].size > 0 ? ZE::ZEDeviceMemoryAccessProperties.new(FFI::MemoryPointer.from_string(defi["pMemAccessProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceGetCacheProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "pCacheProperties: #{"0x%016x" % defi["pCacheProperties"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceGetCacheProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "pCacheProperties_vals: [ #{p = FFI::MemoryPointer.from_string(defi["pCacheProperties_vals"]); sz = ZE::ZEDeviceCacheProperties.size; n = p.size / sz; (0...n).collect { |i| ZE::ZEDeviceCacheProperties.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceGetImageProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pImageProperties: #{"0x%016x" % defi["pImageProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceGetImageProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pImageProperties_val: #{defi["pImageProperties_val"].size > 0 ? ZE::ZEDeviceImageProperties.new(FFI::MemoryPointer.from_string(defi["pImageProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceGetExternalMemoryProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pExternalMemoryProperties: #{"0x%016x" % defi["pExternalMemoryProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceGetExternalMemoryProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pExternalMemoryProperties_val: #{defi["pExternalMemoryProperties_val"].size > 0 ? ZE::ZEDeviceExternalMemoryProperties.new(FFI::MemoryPointer.from_string(defi["pExternalMemoryProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceGetP2PProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "hPeerDevice: #{"0x%016x" % defi["hPeerDevice"]}"
  s << ', '
  s << "pP2PProperties: #{"0x%016x" % defi["pP2PProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceGetP2PProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pP2PProperties_val: #{defi["pP2PProperties_val"].size > 0 ? ZE::ZEDeviceP2PProperties.new(FFI::MemoryPointer.from_string(defi["pP2PProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceCanAccessPeer_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "hPeerDevice: #{"0x%016x" % defi["hPeerDevice"]}"
  s << ', '
  s << "value: #{"0x%016x" % defi["value"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceCanAccessPeer_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "value_val: #{defi["value_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceGetStatus_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceGetStatus_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceGetGlobalTimestamps_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "hostTimestamp: #{"0x%016x" % defi["hostTimestamp"]}"
  s << ', '
  s << "deviceTimestamp: #{"0x%016x" % defi["deviceTimestamp"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceGetGlobalTimestamps_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "hostTimestamp_val: #{defi["hostTimestamp_val"]}"
  s << ', '
  s << "deviceTimestamp_val: #{defi["deviceTimestamp_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeContextCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "hDriver: #{"0x%016x" % defi["hDriver"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "phContext: #{"0x%016x" % defi["phContext"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].size > 0 ? ZE::ZEContextDesc.new(FFI::MemoryPointer.from_string(defi["desc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeContextCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phContext_val: #{"0x%016x" % defi["phContext_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeContextCreateEx_entry"] = lambda { |defi|
  s = "{ "
  s << "hDriver: #{"0x%016x" % defi["hDriver"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "numDevices: #{defi["numDevices"]}"
  s << ', '
  s << "phDevices: #{"0x%016x" % defi["phDevices"]}"
  s << ', '
  s << "phContext: #{"0x%016x" % defi["phContext"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].size > 0 ? ZE::ZEContextDesc.new(FFI::MemoryPointer.from_string(defi["desc_val"])) : nil}"
  s << ', '
  s << "phDevices_vals: [ #{defi["phDevices_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeContextCreateEx_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phContext_val: #{"0x%016x" % defi["phContext_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeContextDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeContextDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeContextGetStatus_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeContextGetStatus_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandQueueCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "phCommandQueue: #{"0x%016x" % defi["phCommandQueue"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].size > 0 ? ZE::ZECommandQueueDesc.new(FFI::MemoryPointer.from_string(defi["desc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandQueueCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phCommandQueue_val: #{"0x%016x" % defi["phCommandQueue_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandQueueDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandQueue: #{"0x%016x" % defi["hCommandQueue"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandQueueDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandQueueExecuteCommandLists_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandQueue: #{"0x%016x" % defi["hCommandQueue"]}"
  s << ', '
  s << "numCommandLists: #{defi["numCommandLists"]}"
  s << ', '
  s << "phCommandLists: #{"0x%016x" % defi["phCommandLists"]}"
  s << ', '
  s << "hFence: #{"0x%016x" % defi["hFence"]}"
  s << ', '
  s << "phCommandLists_vals: [ #{defi["phCommandLists_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandQueueExecuteCommandLists_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandQueueSynchronize_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandQueue: #{"0x%016x" % defi["hCommandQueue"]}"
  s << ', '
  s << "timeout: #{defi["timeout"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandQueueSynchronize_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandQueueGetOrdinal_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandQueue: #{"0x%016x" % defi["hCommandQueue"]}"
  s << ', '
  s << "pOrdinal: #{"0x%016x" % defi["pOrdinal"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandQueueGetOrdinal_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pOrdinal_val: #{defi["pOrdinal_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandQueueGetIndex_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandQueue: #{"0x%016x" % defi["hCommandQueue"]}"
  s << ', '
  s << "pIndex: #{"0x%016x" % defi["pIndex"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandQueueGetIndex_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pIndex_val: #{defi["pIndex_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "phCommandList: #{"0x%016x" % defi["phCommandList"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].size > 0 ? ZE::ZECommandListDesc.new(FFI::MemoryPointer.from_string(defi["desc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phCommandList_val: #{"0x%016x" % defi["phCommandList_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListCreateImmediate_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "altdesc: #{"0x%016x" % defi["altdesc"]}"
  s << ', '
  s << "phCommandList: #{"0x%016x" % defi["phCommandList"]}"
  s << ', '
  s << "altdesc_val: #{defi["altdesc_val"].size > 0 ? ZE::ZECommandQueueDesc.new(FFI::MemoryPointer.from_string(defi["altdesc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListCreateImmediate_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phCommandList_val: #{"0x%016x" % defi["phCommandList_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListClose_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListClose_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListReset_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListReset_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendWriteGlobalTimestamp_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "dstptr: #{"0x%016x" % defi["dstptr"]}"
  s << ', '
  s << "hSignalEvent: #{"0x%016x" % defi["hSignalEvent"]}"
  s << ', '
  s << "numWaitEvents: #{defi["numWaitEvents"]}"
  s << ', '
  s << "phWaitEvents: #{"0x%016x" % defi["phWaitEvents"]}"
  s << ', '
  s << "phWaitEvents_vals: [ #{defi["phWaitEvents_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendWriteGlobalTimestamp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListHostSynchronize_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "timeout: #{defi["timeout"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListHostSynchronize_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListGetDeviceHandle_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "phDevice: #{"0x%016x" % defi["phDevice"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListGetDeviceHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phDevice_val: #{"0x%016x" % defi["phDevice_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListGetContextHandle_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "phContext: #{"0x%016x" % defi["phContext"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListGetContextHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phContext_val: #{"0x%016x" % defi["phContext_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListGetOrdinal_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "pOrdinal: #{"0x%016x" % defi["pOrdinal"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListGetOrdinal_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pOrdinal_val: #{defi["pOrdinal_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListImmediateGetIndex_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandListImmediate: #{"0x%016x" % defi["hCommandListImmediate"]}"
  s << ', '
  s << "pIndex: #{"0x%016x" % defi["pIndex"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListImmediateGetIndex_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pIndex_val: #{defi["pIndex_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListIsImmediate_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "pIsImmediate: #{"0x%016x" % defi["pIsImmediate"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListIsImmediate_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pIsImmediate_val: #{defi["pIsImmediate_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendBarrier_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "hSignalEvent: #{"0x%016x" % defi["hSignalEvent"]}"
  s << ', '
  s << "numWaitEvents: #{defi["numWaitEvents"]}"
  s << ', '
  s << "phWaitEvents: #{"0x%016x" % defi["phWaitEvents"]}"
  s << ', '
  s << "phWaitEvents_vals: [ #{defi["phWaitEvents_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendBarrier_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendMemoryRangesBarrier_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "numRanges: #{defi["numRanges"]}"
  s << ', '
  s << "pRangeSizes: #{"0x%016x" % defi["pRangeSizes"]}"
  s << ', '
  s << "pRanges: #{"0x%016x" % defi["pRanges"]}"
  s << ', '
  s << "hSignalEvent: #{"0x%016x" % defi["hSignalEvent"]}"
  s << ', '
  s << "numWaitEvents: #{defi["numWaitEvents"]}"
  s << ', '
  s << "phWaitEvents: #{"0x%016x" % defi["phWaitEvents"]}"
  s << ', '
  s << "pRangeSizes_vals: #{defi["pRangeSizes_vals"]}"
  s << ', '
  s << "pRanges_vals: [ #{defi["pRanges_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "phWaitEvents_vals: [ #{defi["phWaitEvents_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendMemoryRangesBarrier_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeContextSystemBarrier_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeContextSystemBarrier_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendMemoryCopy_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "dstptr: #{"0x%016x" % defi["dstptr"]}"
  s << ', '
  s << "srcptr: #{"0x%016x" % defi["srcptr"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "hSignalEvent: #{"0x%016x" % defi["hSignalEvent"]}"
  s << ', '
  s << "numWaitEvents: #{defi["numWaitEvents"]}"
  s << ', '
  s << "phWaitEvents: #{"0x%016x" % defi["phWaitEvents"]}"
  s << ', '
  s << "phWaitEvents_vals: [ #{defi["phWaitEvents_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendMemoryCopy_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendMemoryFill_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "pattern: #{"0x%016x" % defi["pattern"]}"
  s << ', '
  s << "pattern_size: #{defi["pattern_size"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "hSignalEvent: #{"0x%016x" % defi["hSignalEvent"]}"
  s << ', '
  s << "numWaitEvents: #{defi["numWaitEvents"]}"
  s << ', '
  s << "phWaitEvents: #{"0x%016x" % defi["phWaitEvents"]}"
  s << ', '
  s << "pattern_vals: #{defi["pattern_vals"].inspect}"
  s << ', '
  s << "phWaitEvents_vals: [ #{defi["phWaitEvents_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendMemoryFill_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendMemoryCopyRegion_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "dstptr: #{"0x%016x" % defi["dstptr"]}"
  s << ', '
  s << "dstRegion: #{"0x%016x" % defi["dstRegion"]}"
  s << ', '
  s << "dstPitch: #{defi["dstPitch"]}"
  s << ', '
  s << "dstSlicePitch: #{defi["dstSlicePitch"]}"
  s << ', '
  s << "srcptr: #{"0x%016x" % defi["srcptr"]}"
  s << ', '
  s << "srcRegion: #{"0x%016x" % defi["srcRegion"]}"
  s << ', '
  s << "srcPitch: #{defi["srcPitch"]}"
  s << ', '
  s << "srcSlicePitch: #{defi["srcSlicePitch"]}"
  s << ', '
  s << "hSignalEvent: #{"0x%016x" % defi["hSignalEvent"]}"
  s << ', '
  s << "numWaitEvents: #{defi["numWaitEvents"]}"
  s << ', '
  s << "phWaitEvents: #{"0x%016x" % defi["phWaitEvents"]}"
  s << ', '
  s << "dstRegion_val: #{defi["dstRegion_val"].size > 0 ? ZE::ZECopyRegion.new(FFI::MemoryPointer.from_string(defi["dstRegion_val"])) : nil}"
  s << ', '
  s << "srcRegion_val: #{defi["srcRegion_val"].size > 0 ? ZE::ZECopyRegion.new(FFI::MemoryPointer.from_string(defi["srcRegion_val"])) : nil}"
  s << ', '
  s << "phWaitEvents_vals: [ #{defi["phWaitEvents_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendMemoryCopyRegion_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendMemoryCopyFromContext_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "dstptr: #{"0x%016x" % defi["dstptr"]}"
  s << ', '
  s << "hContextSrc: #{"0x%016x" % defi["hContextSrc"]}"
  s << ', '
  s << "srcptr: #{"0x%016x" % defi["srcptr"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "hSignalEvent: #{"0x%016x" % defi["hSignalEvent"]}"
  s << ', '
  s << "numWaitEvents: #{defi["numWaitEvents"]}"
  s << ', '
  s << "phWaitEvents: #{"0x%016x" % defi["phWaitEvents"]}"
  s << ', '
  s << "phWaitEvents_vals: [ #{defi["phWaitEvents_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendMemoryCopyFromContext_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendImageCopy_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "hDstImage: #{"0x%016x" % defi["hDstImage"]}"
  s << ', '
  s << "hSrcImage: #{"0x%016x" % defi["hSrcImage"]}"
  s << ', '
  s << "hSignalEvent: #{"0x%016x" % defi["hSignalEvent"]}"
  s << ', '
  s << "numWaitEvents: #{defi["numWaitEvents"]}"
  s << ', '
  s << "phWaitEvents: #{"0x%016x" % defi["phWaitEvents"]}"
  s << ', '
  s << "phWaitEvents_vals: [ #{defi["phWaitEvents_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendImageCopy_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendImageCopyRegion_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "hDstImage: #{"0x%016x" % defi["hDstImage"]}"
  s << ', '
  s << "hSrcImage: #{"0x%016x" % defi["hSrcImage"]}"
  s << ', '
  s << "pDstRegion: #{"0x%016x" % defi["pDstRegion"]}"
  s << ', '
  s << "pSrcRegion: #{"0x%016x" % defi["pSrcRegion"]}"
  s << ', '
  s << "hSignalEvent: #{"0x%016x" % defi["hSignalEvent"]}"
  s << ', '
  s << "numWaitEvents: #{defi["numWaitEvents"]}"
  s << ', '
  s << "phWaitEvents: #{"0x%016x" % defi["phWaitEvents"]}"
  s << ', '
  s << "pDstRegion_val: #{defi["pDstRegion_val"].size > 0 ? ZE::ZEImageRegion.new(FFI::MemoryPointer.from_string(defi["pDstRegion_val"])) : nil}"
  s << ', '
  s << "pSrcRegion_val: #{defi["pSrcRegion_val"].size > 0 ? ZE::ZEImageRegion.new(FFI::MemoryPointer.from_string(defi["pSrcRegion_val"])) : nil}"
  s << ', '
  s << "phWaitEvents_vals: [ #{defi["phWaitEvents_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendImageCopyRegion_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendImageCopyToMemory_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "dstptr: #{"0x%016x" % defi["dstptr"]}"
  s << ', '
  s << "hSrcImage: #{"0x%016x" % defi["hSrcImage"]}"
  s << ', '
  s << "pSrcRegion: #{"0x%016x" % defi["pSrcRegion"]}"
  s << ', '
  s << "hSignalEvent: #{"0x%016x" % defi["hSignalEvent"]}"
  s << ', '
  s << "numWaitEvents: #{defi["numWaitEvents"]}"
  s << ', '
  s << "phWaitEvents: #{"0x%016x" % defi["phWaitEvents"]}"
  s << ', '
  s << "pSrcRegion_val: #{defi["pSrcRegion_val"].size > 0 ? ZE::ZEImageRegion.new(FFI::MemoryPointer.from_string(defi["pSrcRegion_val"])) : nil}"
  s << ', '
  s << "phWaitEvents_vals: [ #{defi["phWaitEvents_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendImageCopyToMemory_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendImageCopyFromMemory_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "hDstImage: #{"0x%016x" % defi["hDstImage"]}"
  s << ', '
  s << "srcptr: #{"0x%016x" % defi["srcptr"]}"
  s << ', '
  s << "pDstRegion: #{"0x%016x" % defi["pDstRegion"]}"
  s << ', '
  s << "hSignalEvent: #{"0x%016x" % defi["hSignalEvent"]}"
  s << ', '
  s << "numWaitEvents: #{defi["numWaitEvents"]}"
  s << ', '
  s << "phWaitEvents: #{"0x%016x" % defi["phWaitEvents"]}"
  s << ', '
  s << "pDstRegion_val: #{defi["pDstRegion_val"].size > 0 ? ZE::ZEImageRegion.new(FFI::MemoryPointer.from_string(defi["pDstRegion_val"])) : nil}"
  s << ', '
  s << "phWaitEvents_vals: [ #{defi["phWaitEvents_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendImageCopyFromMemory_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendMemoryPrefetch_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendMemoryPrefetch_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendMemAdvise_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "advice: #{ZE::ZEMemoryAdvice.from_native(defi["advice"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendMemAdvise_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventPoolCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "numDevices: #{defi["numDevices"]}"
  s << ', '
  s << "phDevices: #{"0x%016x" % defi["phDevices"]}"
  s << ', '
  s << "phEventPool: #{"0x%016x" % defi["phEventPool"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].size > 0 ? ZE::ZEEventPoolDesc.new(FFI::MemoryPointer.from_string(defi["desc_val"])) : nil}"
  s << ', '
  s << "phDevices_vals: [ #{defi["phDevices_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventPoolCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phEventPool_val: #{"0x%016x" % defi["phEventPool_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventPoolDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "hEventPool: #{"0x%016x" % defi["hEventPool"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventPoolDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "hEventPool: #{"0x%016x" % defi["hEventPool"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "phEvent: #{"0x%016x" % defi["phEvent"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].size > 0 ? ZE::ZEEventDesc.new(FFI::MemoryPointer.from_string(defi["desc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phEvent_val: #{"0x%016x" % defi["phEvent_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "hEvent: #{"0x%016x" % defi["hEvent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventPoolGetIpcHandle_entry"] = lambda { |defi|
  s = "{ "
  s << "hEventPool: #{"0x%016x" % defi["hEventPool"]}"
  s << ', '
  s << "phIpc: #{"0x%016x" % defi["phIpc"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventPoolGetIpcHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phIpc_val: #{defi["phIpc_val"].size > 0 ? ZE::ZEIpcEventPoolHandle.new(FFI::MemoryPointer.from_string(defi["phIpc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventPoolPutIpcHandle_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "hIpc: #{defi["hIpc"].size > 0 ? ZE::ZEIpcEventPoolHandle.new(FFI::MemoryPointer.from_string(defi["hIpc"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventPoolPutIpcHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventPoolOpenIpcHandle_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "hIpc: #{defi["hIpc"].size > 0 ? ZE::ZEIpcEventPoolHandle.new(FFI::MemoryPointer.from_string(defi["hIpc"])) : nil}"
  s << ', '
  s << "phEventPool: #{"0x%016x" % defi["phEventPool"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventPoolOpenIpcHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phEventPool_val: #{"0x%016x" % defi["phEventPool_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventPoolCloseIpcHandle_entry"] = lambda { |defi|
  s = "{ "
  s << "hEventPool: #{"0x%016x" % defi["hEventPool"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventPoolCloseIpcHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendSignalEvent_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "hEvent: #{"0x%016x" % defi["hEvent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendSignalEvent_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendWaitOnEvents_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "numEvents: #{defi["numEvents"]}"
  s << ', '
  s << "phEvents: #{"0x%016x" % defi["phEvents"]}"
  s << ', '
  s << "phEvents_vals: [ #{defi["phEvents_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendWaitOnEvents_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventHostSignal_entry"] = lambda { |defi|
  s = "{ "
  s << "hEvent: #{"0x%016x" % defi["hEvent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventHostSignal_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventHostSynchronize_entry"] = lambda { |defi|
  s = "{ "
  s << "hEvent: #{"0x%016x" % defi["hEvent"]}"
  s << ', '
  s << "timeout: #{defi["timeout"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventHostSynchronize_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventQueryStatus_entry"] = lambda { |defi|
  s = "{ "
  s << "hEvent: #{"0x%016x" % defi["hEvent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventQueryStatus_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendEventReset_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "hEvent: #{"0x%016x" % defi["hEvent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendEventReset_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventHostReset_entry"] = lambda { |defi|
  s = "{ "
  s << "hEvent: #{"0x%016x" % defi["hEvent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventHostReset_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventQueryKernelTimestamp_entry"] = lambda { |defi|
  s = "{ "
  s << "hEvent: #{"0x%016x" % defi["hEvent"]}"
  s << ', '
  s << "dstptr: #{"0x%016x" % defi["dstptr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventQueryKernelTimestamp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "dstptr_val: #{defi["dstptr_val"].size > 0 ? ZE::ZEKernelTimestampResult.new(FFI::MemoryPointer.from_string(defi["dstptr_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendQueryKernelTimestamps_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "numEvents: #{defi["numEvents"]}"
  s << ', '
  s << "phEvents: #{"0x%016x" % defi["phEvents"]}"
  s << ', '
  s << "dstptr: #{"0x%016x" % defi["dstptr"]}"
  s << ', '
  s << "pOffsets: #{"0x%016x" % defi["pOffsets"]}"
  s << ', '
  s << "hSignalEvent: #{"0x%016x" % defi["hSignalEvent"]}"
  s << ', '
  s << "numWaitEvents: #{defi["numWaitEvents"]}"
  s << ', '
  s << "phWaitEvents: #{"0x%016x" % defi["phWaitEvents"]}"
  s << ', '
  s << "phEvents_vals: [ #{defi["phEvents_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "pOffsets_vals: #{defi["pOffsets_vals"]}"
  s << ', '
  s << "phWaitEvents_vals: [ #{defi["phWaitEvents_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendQueryKernelTimestamps_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventGetEventPool_entry"] = lambda { |defi|
  s = "{ "
  s << "hEvent: #{"0x%016x" % defi["hEvent"]}"
  s << ', '
  s << "phEventPool: #{"0x%016x" % defi["phEventPool"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventGetEventPool_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phEventPool_val: #{"0x%016x" % defi["phEventPool_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventGetSignalScope_entry"] = lambda { |defi|
  s = "{ "
  s << "hEvent: #{"0x%016x" % defi["hEvent"]}"
  s << ', '
  s << "pSignalScope: #{"0x%016x" % defi["pSignalScope"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventGetSignalScope_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pSignalScope_val: [ #{ZE::ZEEventScopeFlags.from_native(defi["pSignalScope_val"], nil).join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventGetWaitScope_entry"] = lambda { |defi|
  s = "{ "
  s << "hEvent: #{"0x%016x" % defi["hEvent"]}"
  s << ', '
  s << "pWaitScope: #{"0x%016x" % defi["pWaitScope"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventGetWaitScope_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pWaitScope_val: [ #{ZE::ZEEventScopeFlags.from_native(defi["pWaitScope_val"], nil).join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventPoolGetContextHandle_entry"] = lambda { |defi|
  s = "{ "
  s << "hEventPool: #{"0x%016x" % defi["hEventPool"]}"
  s << ', '
  s << "phContext: #{"0x%016x" % defi["phContext"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventPoolGetContextHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phContext_val: #{"0x%016x" % defi["phContext_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventPoolGetFlags_entry"] = lambda { |defi|
  s = "{ "
  s << "hEventPool: #{"0x%016x" % defi["hEventPool"]}"
  s << ', '
  s << "pFlags: #{"0x%016x" % defi["pFlags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventPoolGetFlags_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pFlags_val: [ #{ZE::ZEEventPoolFlags.from_native(defi["pFlags_val"], nil).join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeFenceCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandQueue: #{"0x%016x" % defi["hCommandQueue"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "phFence: #{"0x%016x" % defi["phFence"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].size > 0 ? ZE::ZEFenceDesc.new(FFI::MemoryPointer.from_string(defi["desc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeFenceCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phFence_val: #{"0x%016x" % defi["phFence_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeFenceDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "hFence: #{"0x%016x" % defi["hFence"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeFenceDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeFenceHostSynchronize_entry"] = lambda { |defi|
  s = "{ "
  s << "hFence: #{"0x%016x" % defi["hFence"]}"
  s << ', '
  s << "timeout: #{defi["timeout"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeFenceHostSynchronize_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeFenceQueryStatus_entry"] = lambda { |defi|
  s = "{ "
  s << "hFence: #{"0x%016x" % defi["hFence"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeFenceQueryStatus_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeFenceReset_entry"] = lambda { |defi|
  s = "{ "
  s << "hFence: #{"0x%016x" % defi["hFence"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeFenceReset_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeImageGetProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "pImageProperties: #{"0x%016x" % defi["pImageProperties"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].size > 0 ? ZE::ZEImageDesc.new(FFI::MemoryPointer.from_string(defi["desc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeImageGetProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pImageProperties_val: #{defi["pImageProperties_val"].size > 0 ? ZE::ZEImageProperties.new(FFI::MemoryPointer.from_string(defi["pImageProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeImageCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "phImage: #{"0x%016x" % defi["phImage"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].size > 0 ? ZE::ZEImageDesc.new(FFI::MemoryPointer.from_string(defi["desc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeImageCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phImage_val: #{"0x%016x" % defi["phImage_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeImageDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "hImage: #{"0x%016x" % defi["hImage"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeImageDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeMemAllocShared_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "device_desc: #{"0x%016x" % defi["device_desc"]}"
  s << ', '
  s << "host_desc: #{"0x%016x" % defi["host_desc"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "alignment: #{defi["alignment"]}"
  s << ', '
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pptr: #{"0x%016x" % defi["pptr"]}"
  s << ', '
  s << "device_desc_val: #{defi["device_desc_val"].size > 0 ? ZE::ZEDeviceMemAllocDesc.new(FFI::MemoryPointer.from_string(defi["device_desc_val"])) : nil}"
  s << ', '
  s << "host_desc_val: #{defi["host_desc_val"].size > 0 ? ZE::ZEHostMemAllocDesc.new(FFI::MemoryPointer.from_string(defi["host_desc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeMemAllocShared_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pptr_val: #{"0x%016x" % defi["pptr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeMemAllocDevice_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "device_desc: #{"0x%016x" % defi["device_desc"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "alignment: #{defi["alignment"]}"
  s << ', '
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pptr: #{"0x%016x" % defi["pptr"]}"
  s << ', '
  s << "device_desc_val: #{defi["device_desc_val"].size > 0 ? ZE::ZEDeviceMemAllocDesc.new(FFI::MemoryPointer.from_string(defi["device_desc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeMemAllocDevice_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pptr_val: #{"0x%016x" % defi["pptr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeMemAllocHost_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "host_desc: #{"0x%016x" % defi["host_desc"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "alignment: #{defi["alignment"]}"
  s << ', '
  s << "pptr: #{"0x%016x" % defi["pptr"]}"
  s << ', '
  s << "host_desc_val: #{defi["host_desc_val"].size > 0 ? ZE::ZEHostMemAllocDesc.new(FFI::MemoryPointer.from_string(defi["host_desc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeMemAllocHost_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pptr_val: #{"0x%016x" % defi["pptr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeMemFree_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeMemFree_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeMemGetAllocProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "pMemAllocProperties: #{"0x%016x" % defi["pMemAllocProperties"]}"
  s << ', '
  s << "phDevice: #{"0x%016x" % defi["phDevice"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeMemGetAllocProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pMemAllocProperties_val: #{defi["pMemAllocProperties_val"].size > 0 ? ZE::ZEMemoryAllocationProperties.new(FFI::MemoryPointer.from_string(defi["pMemAllocProperties_val"])) : nil}"
  s << ', '
  s << "phDevice_val: #{"0x%016x" % defi["phDevice_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeMemGetAddressRange_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "pBase: #{"0x%016x" % defi["pBase"]}"
  s << ', '
  s << "pSize: #{"0x%016x" % defi["pSize"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeMemGetAddressRange_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pBase_val: #{"0x%016x" % defi["pBase_val"]}"
  s << ', '
  s << "pSize_val: #{defi["pSize_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeMemGetIpcHandle_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "pIpcHandle: #{"0x%016x" % defi["pIpcHandle"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeMemGetIpcHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pIpcHandle_val: #{defi["pIpcHandle_val"].size > 0 ? ZE::ZEIpcMemHandle.new(FFI::MemoryPointer.from_string(defi["pIpcHandle_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeMemGetIpcHandleFromFileDescriptorExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "handle: #{defi["handle"]}"
  s << ', '
  s << "pIpcHandle: #{"0x%016x" % defi["pIpcHandle"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeMemGetIpcHandleFromFileDescriptorExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pIpcHandle_val: #{defi["pIpcHandle_val"].size > 0 ? ZE::ZEIpcMemHandle.new(FFI::MemoryPointer.from_string(defi["pIpcHandle_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeMemGetFileDescriptorFromIpcHandleExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "ipcHandle: #{defi["ipcHandle"].size > 0 ? ZE::ZEIpcMemHandle.new(FFI::MemoryPointer.from_string(defi["ipcHandle"])) : nil}"
  s << ', '
  s << "pHandle: #{"0x%016x" % defi["pHandle"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeMemGetFileDescriptorFromIpcHandleExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pHandle_val: #{defi["pHandle_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeMemPutIpcHandle_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "handle: #{defi["handle"].size > 0 ? ZE::ZEIpcMemHandle.new(FFI::MemoryPointer.from_string(defi["handle"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeMemPutIpcHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeMemOpenIpcHandle_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "handle: #{defi["handle"].size > 0 ? ZE::ZEIpcMemHandle.new(FFI::MemoryPointer.from_string(defi["handle"])) : nil}"
  s << ', '
  s << "flags: [ #{ZE::ZEIpcMemoryFlags.from_native(defi["flags"], nil).join(", ")} ]"
  s << ', '
  s << "pptr: #{"0x%016x" % defi["pptr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeMemOpenIpcHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pptr_val: #{"0x%016x" % defi["pptr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeMemCloseIpcHandle_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeMemCloseIpcHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeMemSetAtomicAccessAttributeExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "attr: [ #{ZE::ZEMemoryAtomicAttrExpFlags.from_native(defi["attr"], nil).join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeMemSetAtomicAccessAttributeExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeMemGetAtomicAccessAttributeExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "pAttr: #{"0x%016x" % defi["pAttr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeMemGetAtomicAccessAttributeExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pAttr_val: [ #{ZE::ZEMemoryAtomicAttrExpFlags.from_native(defi["pAttr_val"], nil).join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeModuleCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "phModule: #{"0x%016x" % defi["phModule"]}"
  s << ', '
  s << "phBuildLog: #{"0x%016x" % defi["phBuildLog"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].size > 0 ? ZE::ZEModuleDesc.new(FFI::MemoryPointer.from_string(defi["desc_val"])) : nil}"
  s << ', '
  s << "desc__pBuildFlags_val: #{defi["desc__pBuildFlags_val"].inspect}"
  s << ', '
  s << "desc__pConstants_val: #{defi["desc__pConstants_val"].size > 0 ? ZE::ZEModuleConstants.new(FFI::MemoryPointer.from_string(defi["desc__pConstants_val"])) : nil}"
  s << ', '
  s << "desc__pConstants__pConstantIds_vals: #{defi["desc__pConstants__pConstantIds_vals"]}"
  s << ', '
  s << "desc__pConstants__pConstantValues_vals: [ #{defi["desc__pConstants__pConstantValues_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeModuleCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phModule_val: #{"0x%016x" % defi["phModule_val"]}"
  s << ', '
  s << "phBuildLog_val: #{"0x%016x" % defi["phBuildLog_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeModuleDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "hModule: #{"0x%016x" % defi["hModule"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeModuleDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeModuleDynamicLink_entry"] = lambda { |defi|
  s = "{ "
  s << "numModules: #{defi["numModules"]}"
  s << ', '
  s << "phModules: #{"0x%016x" % defi["phModules"]}"
  s << ', '
  s << "phLinkLog: #{"0x%016x" % defi["phLinkLog"]}"
  s << ', '
  s << "phModules_vals: [ #{defi["phModules_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeModuleDynamicLink_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phLinkLog_val: #{"0x%016x" % defi["phLinkLog_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeModuleBuildLogDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "hModuleBuildLog: #{"0x%016x" % defi["hModuleBuildLog"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeModuleBuildLogDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeModuleBuildLogGetString_entry"] = lambda { |defi|
  s = "{ "
  s << "hModuleBuildLog: #{"0x%016x" % defi["hModuleBuildLog"]}"
  s << ', '
  s << "pSize: #{"0x%016x" % defi["pSize"]}"
  s << ', '
  s << "pBuildLog: #{"0x%016x" % defi["pBuildLog"]}"
  s << ', '
  s << "pSize_val: #{defi["pSize_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeModuleBuildLogGetString_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pSize_val: #{defi["pSize_val"]}"
  s << ', '
  s << "pBuildLog_vals: #{defi["pBuildLog_vals"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeModuleGetNativeBinary_entry"] = lambda { |defi|
  s = "{ "
  s << "hModule: #{"0x%016x" % defi["hModule"]}"
  s << ', '
  s << "pSize: #{"0x%016x" % defi["pSize"]}"
  s << ', '
  s << "pModuleNativeBinary: #{"0x%016x" % defi["pModuleNativeBinary"]}"
  s << ', '
  s << "pSize_val: #{defi["pSize_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeModuleGetNativeBinary_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pSize_val: #{defi["pSize_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeModuleGetGlobalPointer_entry"] = lambda { |defi|
  s = "{ "
  s << "hModule: #{"0x%016x" % defi["hModule"]}"
  s << ', '
  s << "pGlobalName: #{"0x%016x" % defi["pGlobalName"]}"
  s << ', '
  s << "pSize: #{"0x%016x" % defi["pSize"]}"
  s << ', '
  s << "pptr: #{"0x%016x" % defi["pptr"]}"
  s << ', '
  s << "pGlobalName_val: #{defi["pGlobalName_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeModuleGetGlobalPointer_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pSize_val: #{defi["pSize_val"]}"
  s << ', '
  s << "pptr_val: #{"0x%016x" % defi["pptr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeModuleGetKernelNames_entry"] = lambda { |defi|
  s = "{ "
  s << "hModule: #{"0x%016x" % defi["hModule"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "pNames: #{"0x%016x" % defi["pNames"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeModuleGetKernelNames_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "pNames_vals: [ #{defi["pNames_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeModuleGetProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hModule: #{"0x%016x" % defi["hModule"]}"
  s << ', '
  s << "pModuleProperties: #{"0x%016x" % defi["pModuleProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeModuleGetProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pModuleProperties_val: #{defi["pModuleProperties_val"].size > 0 ? ZE::ZEModuleProperties.new(FFI::MemoryPointer.from_string(defi["pModuleProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeKernelCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "hModule: #{"0x%016x" % defi["hModule"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "phKernel: #{"0x%016x" % defi["phKernel"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].size > 0 ? ZE::ZEKernelDesc.new(FFI::MemoryPointer.from_string(defi["desc_val"])) : nil}"
  s << ', '
  s << "desc__pKernelName_val: #{defi["desc__pKernelName_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeKernelCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phKernel_val: #{"0x%016x" % defi["phKernel_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeKernelDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "hKernel: #{"0x%016x" % defi["hKernel"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeKernelDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeModuleGetFunctionPointer_entry"] = lambda { |defi|
  s = "{ "
  s << "hModule: #{"0x%016x" % defi["hModule"]}"
  s << ', '
  s << "pFunctionName: #{"0x%016x" % defi["pFunctionName"]}"
  s << ', '
  s << "pfnFunction: #{"0x%016x" % defi["pfnFunction"]}"
  s << ', '
  s << "pFunctionName_val: #{defi["pFunctionName_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeModuleGetFunctionPointer_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pfnFunction_val: #{"0x%016x" % defi["pfnFunction_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeKernelSetGroupSize_entry"] = lambda { |defi|
  s = "{ "
  s << "hKernel: #{"0x%016x" % defi["hKernel"]}"
  s << ', '
  s << "groupSizeX: #{defi["groupSizeX"]}"
  s << ', '
  s << "groupSizeY: #{defi["groupSizeY"]}"
  s << ', '
  s << "groupSizeZ: #{defi["groupSizeZ"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeKernelSetGroupSize_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeKernelSuggestGroupSize_entry"] = lambda { |defi|
  s = "{ "
  s << "hKernel: #{"0x%016x" % defi["hKernel"]}"
  s << ', '
  s << "globalSizeX: #{defi["globalSizeX"]}"
  s << ', '
  s << "globalSizeY: #{defi["globalSizeY"]}"
  s << ', '
  s << "globalSizeZ: #{defi["globalSizeZ"]}"
  s << ', '
  s << "groupSizeX: #{"0x%016x" % defi["groupSizeX"]}"
  s << ', '
  s << "groupSizeY: #{"0x%016x" % defi["groupSizeY"]}"
  s << ', '
  s << "groupSizeZ: #{"0x%016x" % defi["groupSizeZ"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeKernelSuggestGroupSize_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "groupSizeX_val: #{defi["groupSizeX_val"]}"
  s << ', '
  s << "groupSizeY_val: #{defi["groupSizeY_val"]}"
  s << ', '
  s << "groupSizeZ_val: #{defi["groupSizeZ_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeKernelSuggestMaxCooperativeGroupCount_entry"] = lambda { |defi|
  s = "{ "
  s << "hKernel: #{"0x%016x" % defi["hKernel"]}"
  s << ', '
  s << "totalGroupCount: #{"0x%016x" % defi["totalGroupCount"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeKernelSuggestMaxCooperativeGroupCount_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "totalGroupCount_val: #{defi["totalGroupCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeKernelSetArgumentValue_entry"] = lambda { |defi|
  s = "{ "
  s << "hKernel: #{"0x%016x" % defi["hKernel"]}"
  s << ', '
  s << "argIndex: #{defi["argIndex"]}"
  s << ', '
  s << "argSize: #{defi["argSize"]}"
  s << ', '
  s << "pArgValue: #{"0x%016x" % defi["pArgValue"]}"
  s << ', '
  s << "pArgValue_vals: #{defi["pArgValue_vals"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeKernelSetArgumentValue_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeKernelSetIndirectAccess_entry"] = lambda { |defi|
  s = "{ "
  s << "hKernel: #{"0x%016x" % defi["hKernel"]}"
  s << ', '
  s << "flags: [ #{ZE::ZEKernelIndirectAccessFlags.from_native(defi["flags"], nil).join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeKernelSetIndirectAccess_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeKernelGetIndirectAccess_entry"] = lambda { |defi|
  s = "{ "
  s << "hKernel: #{"0x%016x" % defi["hKernel"]}"
  s << ', '
  s << "pFlags: #{"0x%016x" % defi["pFlags"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeKernelGetIndirectAccess_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pFlags_val: [ #{ZE::ZEKernelIndirectAccessFlags.from_native(defi["pFlags_val"], nil).join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeKernelGetSourceAttributes_entry"] = lambda { |defi|
  s = "{ "
  s << "hKernel: #{"0x%016x" % defi["hKernel"]}"
  s << ', '
  s << "pSize: #{"0x%016x" % defi["pSize"]}"
  s << ', '
  s << "pString: #{"0x%016x" % defi["pString"]}"
  s << ', '
  s << "pSize_val: #{defi["pSize_val"]}"
  s << ', '
  s << "pString_val: #{"0x%016x" % defi["pString_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeKernelGetSourceAttributes_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pSize_val: #{defi["pSize_val"]}"
  s << ', '
  s << "pString_val: #{"0x%016x" % defi["pString_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeKernelSetCacheConfig_entry"] = lambda { |defi|
  s = "{ "
  s << "hKernel: #{"0x%016x" % defi["hKernel"]}"
  s << ', '
  s << "flags: [ #{ZE::ZECacheConfigFlags.from_native(defi["flags"], nil).join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeKernelSetCacheConfig_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeKernelGetProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hKernel: #{"0x%016x" % defi["hKernel"]}"
  s << ', '
  s << "pKernelProperties: #{"0x%016x" % defi["pKernelProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeKernelGetProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pKernelProperties_val: #{defi["pKernelProperties_val"].size > 0 ? ZE::ZEKernelProperties.new(FFI::MemoryPointer.from_string(defi["pKernelProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeKernelGetName_entry"] = lambda { |defi|
  s = "{ "
  s << "hKernel: #{"0x%016x" % defi["hKernel"]}"
  s << ', '
  s << "pSize: #{"0x%016x" % defi["pSize"]}"
  s << ', '
  s << "pName: #{"0x%016x" % defi["pName"]}"
  s << ', '
  s << "pSize_val: #{defi["pSize_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeKernelGetName_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pSize_val: #{defi["pSize_val"]}"
  s << ', '
  s << "pName_val: #{defi["pName_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendLaunchKernel_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "hKernel: #{"0x%016x" % defi["hKernel"]}"
  s << ', '
  s << "pLaunchFuncArgs: #{"0x%016x" % defi["pLaunchFuncArgs"]}"
  s << ', '
  s << "hSignalEvent: #{"0x%016x" % defi["hSignalEvent"]}"
  s << ', '
  s << "numWaitEvents: #{defi["numWaitEvents"]}"
  s << ', '
  s << "phWaitEvents: #{"0x%016x" % defi["phWaitEvents"]}"
  s << ', '
  s << "pLaunchFuncArgs_val: #{defi["pLaunchFuncArgs_val"].size > 0 ? ZE::ZEGroupCount.new(FFI::MemoryPointer.from_string(defi["pLaunchFuncArgs_val"])) : nil}"
  s << ', '
  s << "phWaitEvents_vals: [ #{defi["phWaitEvents_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendLaunchKernel_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendLaunchCooperativeKernel_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "hKernel: #{"0x%016x" % defi["hKernel"]}"
  s << ', '
  s << "pLaunchFuncArgs: #{"0x%016x" % defi["pLaunchFuncArgs"]}"
  s << ', '
  s << "hSignalEvent: #{"0x%016x" % defi["hSignalEvent"]}"
  s << ', '
  s << "numWaitEvents: #{defi["numWaitEvents"]}"
  s << ', '
  s << "phWaitEvents: #{"0x%016x" % defi["phWaitEvents"]}"
  s << ', '
  s << "pLaunchFuncArgs_val: #{defi["pLaunchFuncArgs_val"].size > 0 ? ZE::ZEGroupCount.new(FFI::MemoryPointer.from_string(defi["pLaunchFuncArgs_val"])) : nil}"
  s << ', '
  s << "phWaitEvents_vals: [ #{defi["phWaitEvents_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendLaunchCooperativeKernel_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendLaunchKernelIndirect_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "hKernel: #{"0x%016x" % defi["hKernel"]}"
  s << ', '
  s << "pLaunchArgumentsBuffer: #{"0x%016x" % defi["pLaunchArgumentsBuffer"]}"
  s << ', '
  s << "hSignalEvent: #{"0x%016x" % defi["hSignalEvent"]}"
  s << ', '
  s << "numWaitEvents: #{defi["numWaitEvents"]}"
  s << ', '
  s << "phWaitEvents: #{"0x%016x" % defi["phWaitEvents"]}"
  s << ', '
  s << "phWaitEvents_vals: [ #{defi["phWaitEvents_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendLaunchKernelIndirect_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendLaunchMultipleKernelsIndirect_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "numKernels: #{defi["numKernels"]}"
  s << ', '
  s << "phKernels: #{"0x%016x" % defi["phKernels"]}"
  s << ', '
  s << "pCountBuffer: #{"0x%016x" % defi["pCountBuffer"]}"
  s << ', '
  s << "pLaunchArgumentsBuffer: #{"0x%016x" % defi["pLaunchArgumentsBuffer"]}"
  s << ', '
  s << "hSignalEvent: #{"0x%016x" % defi["hSignalEvent"]}"
  s << ', '
  s << "numWaitEvents: #{defi["numWaitEvents"]}"
  s << ', '
  s << "phWaitEvents: #{"0x%016x" % defi["phWaitEvents"]}"
  s << ', '
  s << "phKernels_vals: [ #{defi["phKernels_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "phWaitEvents_vals: [ #{defi["phWaitEvents_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendLaunchMultipleKernelsIndirect_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeContextMakeMemoryResident_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeContextMakeMemoryResident_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeContextEvictMemory_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeContextEvictMemory_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeContextMakeImageResident_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "hImage: #{"0x%016x" % defi["hImage"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeContextMakeImageResident_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeContextEvictImage_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "hImage: #{"0x%016x" % defi["hImage"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeContextEvictImage_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeSamplerCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "phSampler: #{"0x%016x" % defi["phSampler"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].size > 0 ? ZE::ZESamplerDesc.new(FFI::MemoryPointer.from_string(defi["desc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeSamplerCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phSampler_val: #{"0x%016x" % defi["phSampler_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeSamplerDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "hSampler: #{"0x%016x" % defi["hSampler"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeSamplerDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeVirtualMemReserve_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "pStart: #{"0x%016x" % defi["pStart"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "pptr: #{"0x%016x" % defi["pptr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeVirtualMemReserve_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pptr_val: #{"0x%016x" % defi["pptr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeVirtualMemFree_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeVirtualMemFree_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeVirtualMemQueryPageSize_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "pagesize: #{"0x%016x" % defi["pagesize"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeVirtualMemQueryPageSize_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pagesize_val: #{defi["pagesize_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zePhysicalMemCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "phPhysicalMemory: #{"0x%016x" % defi["phPhysicalMemory"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].size > 0 ? ZE::ZEPhysicalMemDesc.new(FFI::MemoryPointer.from_string(defi["desc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zePhysicalMemCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phPhysicalMemory_val: #{"0x%016x" % defi["phPhysicalMemory_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zePhysicalMemDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "hPhysicalMemory: #{"0x%016x" % defi["hPhysicalMemory"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zePhysicalMemDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeVirtualMemMap_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "hPhysicalMemory: #{"0x%016x" % defi["hPhysicalMemory"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "access: #{ZE::ZEMemoryAccessAttribute.from_native(defi["access"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeVirtualMemMap_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeVirtualMemUnmap_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeVirtualMemUnmap_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeVirtualMemSetAccessAttribute_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "access: #{ZE::ZEMemoryAccessAttribute.from_native(defi["access"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeVirtualMemSetAccessAttribute_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeVirtualMemGetAccessAttribute_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "access: #{"0x%016x" % defi["access"]}"
  s << ', '
  s << "outSize: #{"0x%016x" % defi["outSize"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeVirtualMemGetAccessAttribute_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "access_val: #{ZE::ZEMemoryAccessAttribute.from_native(defi["access_val"], nil)}"
  s << ', '
  s << "outSize_val: #{defi["outSize_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeKernelSetGlobalOffsetExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hKernel: #{"0x%016x" % defi["hKernel"]}"
  s << ', '
  s << "offsetX: #{defi["offsetX"]}"
  s << ', '
  s << "offsetY: #{defi["offsetY"]}"
  s << ', '
  s << "offsetZ: #{defi["offsetZ"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeKernelSetGlobalOffsetExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeKernelGetBinaryExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hKernel: #{"0x%016x" % defi["hKernel"]}"
  s << ', '
  s << "pSize: #{"0x%016x" % defi["pSize"]}"
  s << ', '
  s << "pKernelBinary: #{"0x%016x" % defi["pKernelBinary"]}"
  s << ', '
  s << "pSize_val: #{defi["pSize_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeKernelGetBinaryExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pSize_val: #{defi["pSize_val"]}"
  s << ', '
  s << "pKernelBinary_vals: #{defi["pKernelBinary_vals"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceImportExternalSemaphoreExt_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "phSemaphore: #{"0x%016x" % defi["phSemaphore"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].size > 0 ? ZE::ZEExternalSemaphoreExtDesc.new(FFI::MemoryPointer.from_string(defi["desc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceImportExternalSemaphoreExt_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phSemaphore_val: #{"0x%016x" % defi["phSemaphore_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceReleaseExternalSemaphoreExt_entry"] = lambda { |defi|
  s = "{ "
  s << "hSemaphore: #{"0x%016x" % defi["hSemaphore"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceReleaseExternalSemaphoreExt_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendSignalExternalSemaphoreExt_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "numSemaphores: #{defi["numSemaphores"]}"
  s << ', '
  s << "phSemaphores: #{"0x%016x" % defi["phSemaphores"]}"
  s << ', '
  s << "signalParams: #{"0x%016x" % defi["signalParams"]}"
  s << ', '
  s << "hSignalEvent: #{"0x%016x" % defi["hSignalEvent"]}"
  s << ', '
  s << "numWaitEvents: #{defi["numWaitEvents"]}"
  s << ', '
  s << "phWaitEvents: #{"0x%016x" % defi["phWaitEvents"]}"
  s << ', '
  s << "phSemaphores_vals: [ #{defi["phSemaphores_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "signalParams_vals: [ #{p = FFI::MemoryPointer.from_string(defi["signalParams_vals"]); sz = ZE::ZEExternalSemaphoreSignalParamsExt.size; n = p.size / sz; (0...n).collect { |i| ZE::ZEExternalSemaphoreSignalParamsExt.new(p + i*sz).to_s}.join(", ")} ]"
  s << ', '
  s << "phWaitEvents_vals: [ #{defi["phWaitEvents_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendSignalExternalSemaphoreExt_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendWaitExternalSemaphoreExt_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "numSemaphores: #{defi["numSemaphores"]}"
  s << ', '
  s << "phSemaphores: #{"0x%016x" % defi["phSemaphores"]}"
  s << ', '
  s << "waitParams: #{"0x%016x" % defi["waitParams"]}"
  s << ', '
  s << "hSignalEvent: #{"0x%016x" % defi["hSignalEvent"]}"
  s << ', '
  s << "numWaitEvents: #{defi["numWaitEvents"]}"
  s << ', '
  s << "phWaitEvents: #{"0x%016x" % defi["phWaitEvents"]}"
  s << ', '
  s << "phSemaphores_vals: [ #{defi["phSemaphores_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "waitParams_vals: [ #{p = FFI::MemoryPointer.from_string(defi["waitParams_vals"]); sz = ZE::ZEExternalSemaphoreWaitParamsExt.size; n = p.size / sz; (0...n).collect { |i| ZE::ZEExternalSemaphoreWaitParamsExt.new(p + i*sz).to_s}.join(", ")} ]"
  s << ', '
  s << "phWaitEvents_vals: [ #{defi["phWaitEvents_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendWaitExternalSemaphoreExt_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeRTASBuilderCreateExt_entry"] = lambda { |defi|
  s = "{ "
  s << "hDriver: #{"0x%016x" % defi["hDriver"]}"
  s << ', '
  s << "pDescriptor: #{"0x%016x" % defi["pDescriptor"]}"
  s << ', '
  s << "phBuilder: #{"0x%016x" % defi["phBuilder"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeRTASBuilderCreateExt_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeRTASBuilderGetBuildPropertiesExt_entry"] = lambda { |defi|
  s = "{ "
  s << "hBuilder: #{"0x%016x" % defi["hBuilder"]}"
  s << ', '
  s << "pBuildOpDescriptor: #{"0x%016x" % defi["pBuildOpDescriptor"]}"
  s << ', '
  s << "pProperties: #{"0x%016x" % defi["pProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeRTASBuilderGetBuildPropertiesExt_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDriverRTASFormatCompatibilityCheckExt_entry"] = lambda { |defi|
  s = "{ "
  s << "hDriver: #{"0x%016x" % defi["hDriver"]}"
  s << ', '
  s << "rtasFormatA: #{ZE::ZERtasFormatExt.from_native(defi["rtasFormatA"], nil)}"
  s << ', '
  s << "rtasFormatB: #{ZE::ZERtasFormatExt.from_native(defi["rtasFormatB"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDriverRTASFormatCompatibilityCheckExt_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeRTASBuilderBuildExt_entry"] = lambda { |defi|
  s = "{ "
  s << "hBuilder: #{"0x%016x" % defi["hBuilder"]}"
  s << ', '
  s << "pBuildOpDescriptor: #{"0x%016x" % defi["pBuildOpDescriptor"]}"
  s << ', '
  s << "pScratchBuffer: #{"0x%016x" % defi["pScratchBuffer"]}"
  s << ', '
  s << "scratchBufferSizeBytes: #{defi["scratchBufferSizeBytes"]}"
  s << ', '
  s << "pRtasBuffer: #{"0x%016x" % defi["pRtasBuffer"]}"
  s << ', '
  s << "rtasBufferSizeBytes: #{defi["rtasBufferSizeBytes"]}"
  s << ', '
  s << "hParallelOperation: #{"0x%016x" % defi["hParallelOperation"]}"
  s << ', '
  s << "pBuildUserPtr: #{"0x%016x" % defi["pBuildUserPtr"]}"
  s << ', '
  s << "pBounds: #{"0x%016x" % defi["pBounds"]}"
  s << ', '
  s << "pRtasBufferSizeBytes: #{"0x%016x" % defi["pRtasBufferSizeBytes"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeRTASBuilderBuildExt_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeRTASBuilderCommandListAppendCopyExt_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "dstptr: #{"0x%016x" % defi["dstptr"]}"
  s << ', '
  s << "srcptr: #{"0x%016x" % defi["srcptr"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "hSignalEvent: #{"0x%016x" % defi["hSignalEvent"]}"
  s << ', '
  s << "numWaitEvents: #{defi["numWaitEvents"]}"
  s << ', '
  s << "phWaitEvents: #{"0x%016x" % defi["phWaitEvents"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeRTASBuilderCommandListAppendCopyExt_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeRTASBuilderDestroyExt_entry"] = lambda { |defi|
  s = "{ "
  s << "hBuilder: #{"0x%016x" % defi["hBuilder"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeRTASBuilderDestroyExt_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeRTASParallelOperationCreateExt_entry"] = lambda { |defi|
  s = "{ "
  s << "hDriver: #{"0x%016x" % defi["hDriver"]}"
  s << ', '
  s << "phParallelOperation: #{"0x%016x" % defi["phParallelOperation"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeRTASParallelOperationCreateExt_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeRTASParallelOperationGetPropertiesExt_entry"] = lambda { |defi|
  s = "{ "
  s << "hParallelOperation: #{"0x%016x" % defi["hParallelOperation"]}"
  s << ', '
  s << "pProperties: #{"0x%016x" % defi["pProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeRTASParallelOperationGetPropertiesExt_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeRTASParallelOperationJoinExt_entry"] = lambda { |defi|
  s = "{ "
  s << "hParallelOperation: #{"0x%016x" % defi["hParallelOperation"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeRTASParallelOperationJoinExt_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeRTASParallelOperationDestroyExt_entry"] = lambda { |defi|
  s = "{ "
  s << "hParallelOperation: #{"0x%016x" % defi["hParallelOperation"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeRTASParallelOperationDestroyExt_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceGetVectorWidthPropertiesExt_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "pVectorWidthProperties: #{"0x%016x" % defi["pVectorWidthProperties"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceGetVectorWidthPropertiesExt_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "pVectorWidthProperties_vals: [ #{p = FFI::MemoryPointer.from_string(defi["pVectorWidthProperties_vals"]); sz = ZE::ZEDeviceVectorWidthPropertiesExt.size; n = p.size / sz; (0...n).collect { |i| ZE::ZEDeviceVectorWidthPropertiesExt.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceReserveCacheExt_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "cacheLevel: #{defi["cacheLevel"]}"
  s << ', '
  s << "cacheReservationSize: #{defi["cacheReservationSize"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceReserveCacheExt_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceSetCacheAdviceExt_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "regionSize: #{defi["regionSize"]}"
  s << ', '
  s << "cacheRegion: #{ZE::ZECacheExtRegion.from_native(defi["cacheRegion"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceSetCacheAdviceExt_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventQueryTimestampsExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hEvent: #{"0x%016x" % defi["hEvent"]}"
  s << ', '
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "pTimestamps: #{"0x%016x" % defi["pTimestamps"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventQueryTimestampsExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "pTimestamps_vals: [ #{p = FFI::MemoryPointer.from_string(defi["pTimestamps_vals"]); sz = ZE::ZEKernelTimestampResult.size; n = p.size / sz; (0...n).collect { |i| ZE::ZEKernelTimestampResult.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeImageGetMemoryPropertiesExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hImage: #{"0x%016x" % defi["hImage"]}"
  s << ', '
  s << "pMemoryProperties: #{"0x%016x" % defi["pMemoryProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeImageGetMemoryPropertiesExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pMemoryProperties_val: #{defi["pMemoryProperties_val"].size > 0 ? ZE::ZEImageMemoryPropertiesExp.new(FFI::MemoryPointer.from_string(defi["pMemoryProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeImageViewCreateExt_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "hImage: #{"0x%016x" % defi["hImage"]}"
  s << ', '
  s << "phImageView: #{"0x%016x" % defi["phImageView"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].size > 0 ? ZE::ZEImageDesc.new(FFI::MemoryPointer.from_string(defi["desc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeImageViewCreateExt_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phImageView_val: #{"0x%016x" % defi["phImageView_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeImageViewCreateExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "hImage: #{"0x%016x" % defi["hImage"]}"
  s << ', '
  s << "phImageView: #{"0x%016x" % defi["phImageView"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].size > 0 ? ZE::ZEImageDesc.new(FFI::MemoryPointer.from_string(defi["desc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeImageViewCreateExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phImageView_val: #{"0x%016x" % defi["phImageView_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeKernelSchedulingHintExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hKernel: #{"0x%016x" % defi["hKernel"]}"
  s << ', '
  s << "pHint: #{"0x%016x" % defi["pHint"]}"
  s << ', '
  s << "pHint_val: #{defi["pHint_val"].size > 0 ? ZE::ZESchedulingHintExpDesc.new(FFI::MemoryPointer.from_string(defi["pHint_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeKernelSchedulingHintExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDevicePciGetPropertiesExt_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pPciProperties: #{"0x%016x" % defi["pPciProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDevicePciGetPropertiesExt_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pPciProperties_val: #{defi["pPciProperties_val"].size > 0 ? ZE::ZEPciExtProperties.new(FFI::MemoryPointer.from_string(defi["pPciProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendImageCopyToMemoryExt_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "dstptr: #{"0x%016x" % defi["dstptr"]}"
  s << ', '
  s << "hSrcImage: #{"0x%016x" % defi["hSrcImage"]}"
  s << ', '
  s << "pSrcRegion: #{"0x%016x" % defi["pSrcRegion"]}"
  s << ', '
  s << "destRowPitch: #{defi["destRowPitch"]}"
  s << ', '
  s << "destSlicePitch: #{defi["destSlicePitch"]}"
  s << ', '
  s << "hSignalEvent: #{"0x%016x" % defi["hSignalEvent"]}"
  s << ', '
  s << "numWaitEvents: #{defi["numWaitEvents"]}"
  s << ', '
  s << "phWaitEvents: #{"0x%016x" % defi["phWaitEvents"]}"
  s << ', '
  s << "pSrcRegion_val: #{defi["pSrcRegion_val"].size > 0 ? ZE::ZEImageRegion.new(FFI::MemoryPointer.from_string(defi["pSrcRegion_val"])) : nil}"
  s << ', '
  s << "phWaitEvents_vals: [ #{defi["phWaitEvents_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendImageCopyToMemoryExt_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendImageCopyFromMemoryExt_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "hDstImage: #{"0x%016x" % defi["hDstImage"]}"
  s << ', '
  s << "srcptr: #{"0x%016x" % defi["srcptr"]}"
  s << ', '
  s << "pDstRegion: #{"0x%016x" % defi["pDstRegion"]}"
  s << ', '
  s << "srcRowPitch: #{defi["srcRowPitch"]}"
  s << ', '
  s << "srcSlicePitch: #{defi["srcSlicePitch"]}"
  s << ', '
  s << "hSignalEvent: #{"0x%016x" % defi["hSignalEvent"]}"
  s << ', '
  s << "numWaitEvents: #{defi["numWaitEvents"]}"
  s << ', '
  s << "phWaitEvents: #{"0x%016x" % defi["phWaitEvents"]}"
  s << ', '
  s << "pDstRegion_val: #{defi["pDstRegion_val"].size > 0 ? ZE::ZEImageRegion.new(FFI::MemoryPointer.from_string(defi["pDstRegion_val"])) : nil}"
  s << ', '
  s << "phWaitEvents_vals: [ #{defi["phWaitEvents_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListAppendImageCopyFromMemoryExt_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeImageGetAllocPropertiesExt_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "hImage: #{"0x%016x" % defi["hImage"]}"
  s << ', '
  s << "pImageAllocProperties: #{"0x%016x" % defi["pImageAllocProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeImageGetAllocPropertiesExt_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pImageAllocProperties_val: #{defi["pImageAllocProperties_val"].size > 0 ? ZE::ZEImageAllocationExtProperties.new(FFI::MemoryPointer.from_string(defi["pImageAllocProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeModuleInspectLinkageExt_entry"] = lambda { |defi|
  s = "{ "
  s << "pInspectDesc: #{"0x%016x" % defi["pInspectDesc"]}"
  s << ', '
  s << "numModules: #{defi["numModules"]}"
  s << ', '
  s << "phModules: #{"0x%016x" % defi["phModules"]}"
  s << ', '
  s << "phLog: #{"0x%016x" % defi["phLog"]}"
  s << ', '
  s << "pInspectDesc_val: #{defi["pInspectDesc_val"].size > 0 ? ZE::ZELinkageInspectionExtDesc.new(FFI::MemoryPointer.from_string(defi["pInspectDesc_val"])) : nil}"
  s << ', '
  s << "phModules_vals: [ #{defi["phModules_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeModuleInspectLinkageExt_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phLog_val: #{"0x%016x" % defi["phLog_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeMemFreeExt_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "pMemFreeDesc: #{"0x%016x" % defi["pMemFreeDesc"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "pMemFreeDesc_val: #{defi["pMemFreeDesc_val"].size > 0 ? ZE::ZEMemoryFreeExtDesc.new(FFI::MemoryPointer.from_string(defi["pMemFreeDesc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeMemFreeExt_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeFabricVertexGetExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hDriver: #{"0x%016x" % defi["hDriver"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "phVertices: #{"0x%016x" % defi["phVertices"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeFabricVertexGetExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "phVertices_vals: [ #{defi["phVertices_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeFabricVertexGetSubVerticesExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hVertex: #{"0x%016x" % defi["hVertex"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "phSubvertices: #{"0x%016x" % defi["phSubvertices"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeFabricVertexGetSubVerticesExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "phSubvertices_vals: [ #{defi["phSubvertices_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeFabricVertexGetPropertiesExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hVertex: #{"0x%016x" % defi["hVertex"]}"
  s << ', '
  s << "pVertexProperties: #{"0x%016x" % defi["pVertexProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeFabricVertexGetPropertiesExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pVertexProperties_val: #{defi["pVertexProperties_val"].size > 0 ? ZE::ZEFabricVertexExpProperties.new(FFI::MemoryPointer.from_string(defi["pVertexProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeFabricVertexGetDeviceExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hVertex: #{"0x%016x" % defi["hVertex"]}"
  s << ', '
  s << "phDevice: #{"0x%016x" % defi["phDevice"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeFabricVertexGetDeviceExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phDevice_val: #{"0x%016x" % defi["phDevice_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceGetFabricVertexExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "phVertex: #{"0x%016x" % defi["phVertex"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDeviceGetFabricVertexExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phVertex_val: #{"0x%016x" % defi["phVertex_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeFabricEdgeGetExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hVertexA: #{"0x%016x" % defi["hVertexA"]}"
  s << ', '
  s << "hVertexB: #{"0x%016x" % defi["hVertexB"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "phEdges: #{"0x%016x" % defi["phEdges"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeFabricEdgeGetExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "phEdges_vals: [ #{defi["phEdges_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeFabricEdgeGetVerticesExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hEdge: #{"0x%016x" % defi["hEdge"]}"
  s << ', '
  s << "phVertexA: #{"0x%016x" % defi["phVertexA"]}"
  s << ', '
  s << "phVertexB: #{"0x%016x" % defi["phVertexB"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeFabricEdgeGetVerticesExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phVertexA_val: #{"0x%016x" % defi["phVertexA_val"]}"
  s << ', '
  s << "phVertexB_val: #{"0x%016x" % defi["phVertexB_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeFabricEdgeGetPropertiesExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hEdge: #{"0x%016x" % defi["hEdge"]}"
  s << ', '
  s << "pEdgeProperties: #{"0x%016x" % defi["pEdgeProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeFabricEdgeGetPropertiesExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pEdgeProperties_val: #{defi["pEdgeProperties_val"].size > 0 ? ZE::ZEFabricEdgeExpProperties.new(FFI::MemoryPointer.from_string(defi["pEdgeProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventQueryKernelTimestampsExt_entry"] = lambda { |defi|
  s = "{ "
  s << "hEvent: #{"0x%016x" % defi["hEvent"]}"
  s << ', '
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "pResults: #{"0x%016x" % defi["pResults"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeEventQueryKernelTimestampsExt_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "pResults_vals: [ #{p = FFI::MemoryPointer.from_string(defi["pResults_vals"]); sz = ZE::ZEEventQueryKernelTimestampsResultsExtProperties.size; n = p.size / sz; (0...n).collect { |i| ZE::ZEEventQueryKernelTimestampsResultsExtProperties.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeRTASBuilderCreateExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hDriver: #{"0x%016x" % defi["hDriver"]}"
  s << ', '
  s << "pDescriptor: #{"0x%016x" % defi["pDescriptor"]}"
  s << ', '
  s << "phBuilder: #{"0x%016x" % defi["phBuilder"]}"
  s << ', '
  s << "pDescriptor_val: #{defi["pDescriptor_val"].size > 0 ? ZE::ZERtasBuilderExpDesc.new(FFI::MemoryPointer.from_string(defi["pDescriptor_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeRTASBuilderCreateExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phBuilder_val: #{"0x%016x" % defi["phBuilder_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeRTASBuilderGetBuildPropertiesExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hBuilder: #{"0x%016x" % defi["hBuilder"]}"
  s << ', '
  s << "pBuildOpDescriptor: #{"0x%016x" % defi["pBuildOpDescriptor"]}"
  s << ', '
  s << "pProperties: #{"0x%016x" % defi["pProperties"]}"
  s << ', '
  s << "pBuildOpDescriptor_val: #{defi["pBuildOpDescriptor_val"].size > 0 ? ZE::ZERtasBuilderBuildOpExpDesc.new(FFI::MemoryPointer.from_string(defi["pBuildOpDescriptor_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeRTASBuilderGetBuildPropertiesExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pProperties_val: #{defi["pProperties_val"].size > 0 ? ZE::ZERtasBuilderExpProperties.new(FFI::MemoryPointer.from_string(defi["pProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDriverRTASFormatCompatibilityCheckExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hDriver: #{"0x%016x" % defi["hDriver"]}"
  s << ', '
  s << "rtasFormatA: #{ZE::ZERtasFormatExp.from_native(defi["rtasFormatA"], nil)}"
  s << ', '
  s << "rtasFormatB: #{ZE::ZERtasFormatExp.from_native(defi["rtasFormatB"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeDriverRTASFormatCompatibilityCheckExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeRTASBuilderBuildExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hBuilder: #{"0x%016x" % defi["hBuilder"]}"
  s << ', '
  s << "pBuildOpDescriptor: #{"0x%016x" % defi["pBuildOpDescriptor"]}"
  s << ', '
  s << "pScratchBuffer: #{"0x%016x" % defi["pScratchBuffer"]}"
  s << ', '
  s << "scratchBufferSizeBytes: #{defi["scratchBufferSizeBytes"]}"
  s << ', '
  s << "pRtasBuffer: #{"0x%016x" % defi["pRtasBuffer"]}"
  s << ', '
  s << "rtasBufferSizeBytes: #{defi["rtasBufferSizeBytes"]}"
  s << ', '
  s << "hParallelOperation: #{"0x%016x" % defi["hParallelOperation"]}"
  s << ', '
  s << "pBuildUserPtr: #{"0x%016x" % defi["pBuildUserPtr"]}"
  s << ', '
  s << "pBounds: #{"0x%016x" % defi["pBounds"]}"
  s << ', '
  s << "pRtasBufferSizeBytes: #{"0x%016x" % defi["pRtasBufferSizeBytes"]}"
  s << ', '
  s << "pBuildOpDescriptor_val: #{defi["pBuildOpDescriptor_val"].size > 0 ? ZE::ZERtasBuilderBuildOpExpDesc.new(FFI::MemoryPointer.from_string(defi["pBuildOpDescriptor_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeRTASBuilderBuildExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pBounds_val: #{defi["pBounds_val"].size > 0 ? ZE::ZERtasAabbExp.new(FFI::MemoryPointer.from_string(defi["pBounds_val"])) : nil}"
  s << ', '
  s << "pRtasBufferSizeBytes_val: #{defi["pRtasBufferSizeBytes_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeRTASBuilderDestroyExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hBuilder: #{"0x%016x" % defi["hBuilder"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeRTASBuilderDestroyExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeRTASParallelOperationCreateExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hDriver: #{"0x%016x" % defi["hDriver"]}"
  s << ', '
  s << "phParallelOperation: #{"0x%016x" % defi["phParallelOperation"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeRTASParallelOperationCreateExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phParallelOperation_val: #{"0x%016x" % defi["phParallelOperation_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeRTASParallelOperationGetPropertiesExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hParallelOperation: #{"0x%016x" % defi["hParallelOperation"]}"
  s << ', '
  s << "pProperties: #{"0x%016x" % defi["pProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeRTASParallelOperationGetPropertiesExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pProperties_val: #{defi["pProperties_val"].size > 0 ? ZE::ZERtasParallelOperationExpProperties.new(FFI::MemoryPointer.from_string(defi["pProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeRTASParallelOperationJoinExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hParallelOperation: #{"0x%016x" % defi["hParallelOperation"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeRTASParallelOperationJoinExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeRTASParallelOperationDestroyExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hParallelOperation: #{"0x%016x" % defi["hParallelOperation"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeRTASParallelOperationDestroyExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeMemGetPitchFor2dImage_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "imageWidth: #{defi["imageWidth"]}"
  s << ', '
  s << "imageHeight: #{defi["imageHeight"]}"
  s << ', '
  s << "elementSizeInBytes: #{defi["elementSizeInBytes"]}"
  s << ', '
  s << "rowPitch: #{"0x%016x" % defi["rowPitch"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeMemGetPitchFor2dImage_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "rowPitch_val: #{defi["rowPitch_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeImageGetDeviceOffsetExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hImage: #{"0x%016x" % defi["hImage"]}"
  s << ', '
  s << "pDeviceOffset: #{"0x%016x" % defi["pDeviceOffset"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeImageGetDeviceOffsetExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pDeviceOffset_val: #{defi["pDeviceOffset_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListCreateCloneExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "phClonedCommandList: #{"0x%016x" % defi["phClonedCommandList"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListCreateCloneExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phClonedCommandList_val: #{"0x%016x" % defi["phClonedCommandList_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListImmediateAppendCommandListsExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandListImmediate: #{"0x%016x" % defi["hCommandListImmediate"]}"
  s << ', '
  s << "numCommandLists: #{defi["numCommandLists"]}"
  s << ', '
  s << "phCommandLists: #{"0x%016x" % defi["phCommandLists"]}"
  s << ', '
  s << "hSignalEvent: #{"0x%016x" % defi["hSignalEvent"]}"
  s << ', '
  s << "numWaitEvents: #{defi["numWaitEvents"]}"
  s << ', '
  s << "phWaitEvents: #{"0x%016x" % defi["phWaitEvents"]}"
  s << ', '
  s << "phCommandLists_vals: [ #{defi["phCommandLists_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "phWaitEvents_vals: [ #{defi["phWaitEvents_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListImmediateAppendCommandListsExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListGetNextCommandIdExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "pCommandId: #{"0x%016x" % defi["pCommandId"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].size > 0 ? ZE::ZEMutableCommandIdExpDesc.new(FFI::MemoryPointer.from_string(defi["desc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListGetNextCommandIdExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCommandId_val: #{defi["pCommandId_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListGetNextCommandIdWithKernelsExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "numKernels: #{defi["numKernels"]}"
  s << ', '
  s << "phKernels: #{"0x%016x" % defi["phKernels"]}"
  s << ', '
  s << "pCommandId: #{"0x%016x" % defi["pCommandId"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].size > 0 ? ZE::ZEMutableCommandIdExpDesc.new(FFI::MemoryPointer.from_string(defi["desc_val"])) : nil}"
  s << ', '
  s << "phKernels_vals: [ #{defi["phKernels_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListGetNextCommandIdWithKernelsExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].size > 0 ? ZE::ZEMutableCommandIdExpDesc.new(FFI::MemoryPointer.from_string(defi["desc_val"])) : nil}"
  s << ', '
  s << "pCommandId_val: #{defi["pCommandId_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListUpdateMutableCommandsExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].size > 0 ? ZE::ZEMutableCommandsExpDesc.new(FFI::MemoryPointer.from_string(defi["desc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListUpdateMutableCommandsExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListUpdateMutableCommandSignalEventExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "commandId: #{defi["commandId"]}"
  s << ', '
  s << "hSignalEvent: #{"0x%016x" % defi["hSignalEvent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListUpdateMutableCommandSignalEventExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListUpdateMutableCommandWaitEventsExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "commandId: #{defi["commandId"]}"
  s << ', '
  s << "numWaitEvents: #{defi["numWaitEvents"]}"
  s << ', '
  s << "phWaitEvents: #{"0x%016x" % defi["phWaitEvents"]}"
  s << ', '
  s << "phWaitEvents_vals: [ #{defi["phWaitEvents_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListUpdateMutableCommandWaitEventsExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListUpdateMutableCommandKernelsExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "numKernels: #{defi["numKernels"]}"
  s << ', '
  s << "pCommandId: #{"0x%016x" % defi["pCommandId"]}"
  s << ', '
  s << "phKernels: #{"0x%016x" % defi["phKernels"]}"
  s << ', '
  s << "pCommandId_vals: #{defi["pCommandId_vals"]}"
  s << ', '
  s << "phKernels_vals: [ #{defi["phKernels_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeCommandListUpdateMutableCommandKernelsExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeLoaderInit_entry"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeLoaderInit_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetRTASBuilderProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetRTASBuilderProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetRTASBuilderExpProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetRTASBuilderExpProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetRTASParallelOperationProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetRTASParallelOperationProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetRTASParallelOperationExpProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetRTASParallelOperationExpProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetGlobalProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetGlobalProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetDriverProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetDriverProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetDriverExpProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetDriverExpProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetDeviceProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetDeviceProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetDeviceExpProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetDeviceExpProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetContextProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetContextProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetCommandQueueProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetCommandQueueProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetCommandListProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetCommandListProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetCommandListExpProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetCommandListExpProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetImageProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetImageProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetImageExpProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetImageExpProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetMemProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetMemProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetMemExpProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetMemExpProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetFenceProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetFenceProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetEventPoolProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetEventPoolProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetEventProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetEventProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetEventExpProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetEventExpProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetModuleProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetModuleProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetModuleBuildLogProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetModuleBuildLogProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetKernelProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetKernelProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetKernelExpProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetKernelExpProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetSamplerProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetSamplerProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetPhysicalMemProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetPhysicalMemProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetVirtualMemProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetVirtualMemProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetFabricVertexExpProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetFabricVertexExpProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetFabricEdgeExpProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze:zeGetFabricEdgeExpProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetModuleGetDebugInfo_entry"] = lambda { |defi|
  s = "{ "
  s << "hModule: #{"0x%016x" % defi["hModule"]}"
  s << ', '
  s << "format: #{ZE::ZETModuleDebugInfoFormat.from_native(defi["format"], nil)}"
  s << ', '
  s << "pSize: #{"0x%016x" % defi["pSize"]}"
  s << ', '
  s << "pDebugInfo: #{"0x%016x" % defi["pDebugInfo"]}"
  s << ', '
  s << "pSize_val: #{defi["pSize_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetModuleGetDebugInfo_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pSize_val: #{defi["pSize_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetDeviceGetDebugProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pDebugProperties: #{"0x%016x" % defi["pDebugProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetDeviceGetDebugProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pDebugProperties_val: #{defi["pDebugProperties_val"].size > 0 ? ZE::ZETDeviceDebugProperties.new(FFI::MemoryPointer.from_string(defi["pDebugProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetDebugAttach_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "config: #{"0x%016x" % defi["config"]}"
  s << ', '
  s << "phDebug: #{"0x%016x" % defi["phDebug"]}"
  s << ', '
  s << "config_val: #{defi["config_val"].size > 0 ? ZE::ZETDebugConfig.new(FFI::MemoryPointer.from_string(defi["config_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetDebugAttach_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phDebug_val: #{"0x%016x" % defi["phDebug_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetDebugDetach_entry"] = lambda { |defi|
  s = "{ "
  s << "hDebug: #{"0x%016x" % defi["hDebug"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetDebugDetach_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetDebugReadEvent_entry"] = lambda { |defi|
  s = "{ "
  s << "hDebug: #{"0x%016x" % defi["hDebug"]}"
  s << ', '
  s << "timeout: #{defi["timeout"]}"
  s << ', '
  s << "event: #{"0x%016x" % defi["event"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetDebugReadEvent_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "event_val: #{defi["event_val"].size > 0 ? ZE::ZETDebugEvent.new(FFI::MemoryPointer.from_string(defi["event_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetDebugAcknowledgeEvent_entry"] = lambda { |defi|
  s = "{ "
  s << "hDebug: #{"0x%016x" % defi["hDebug"]}"
  s << ', '
  s << "event: #{"0x%016x" % defi["event"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetDebugAcknowledgeEvent_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetDebugInterrupt_entry"] = lambda { |defi|
  s = "{ "
  s << "hDebug: #{"0x%016x" % defi["hDebug"]}"
  s << ', '
  s << "thread: #{defi["thread"].size > 0 ? ZE::ZEDeviceThread.new(FFI::MemoryPointer.from_string(defi["thread"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetDebugInterrupt_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetDebugResume_entry"] = lambda { |defi|
  s = "{ "
  s << "hDebug: #{"0x%016x" % defi["hDebug"]}"
  s << ', '
  s << "thread: #{defi["thread"].size > 0 ? ZE::ZEDeviceThread.new(FFI::MemoryPointer.from_string(defi["thread"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetDebugResume_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetDebugReadMemory_entry"] = lambda { |defi|
  s = "{ "
  s << "hDebug: #{"0x%016x" % defi["hDebug"]}"
  s << ', '
  s << "thread: #{defi["thread"].size > 0 ? ZE::ZEDeviceThread.new(FFI::MemoryPointer.from_string(defi["thread"])) : nil}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "buffer: #{"0x%016x" % defi["buffer"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].size > 0 ? ZE::ZETDebugMemorySpaceDesc.new(FFI::MemoryPointer.from_string(defi["desc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetDebugReadMemory_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetDebugWriteMemory_entry"] = lambda { |defi|
  s = "{ "
  s << "hDebug: #{"0x%016x" % defi["hDebug"]}"
  s << ', '
  s << "thread: #{defi["thread"].size > 0 ? ZE::ZEDeviceThread.new(FFI::MemoryPointer.from_string(defi["thread"])) : nil}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "buffer: #{"0x%016x" % defi["buffer"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].size > 0 ? ZE::ZETDebugMemorySpaceDesc.new(FFI::MemoryPointer.from_string(defi["desc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetDebugWriteMemory_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetDebugGetRegisterSetProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "pRegisterSetProperties: #{"0x%016x" % defi["pRegisterSetProperties"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetDebugGetRegisterSetProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "pRegisterSetProperties_vals: [ #{p = FFI::MemoryPointer.from_string(defi["pRegisterSetProperties_vals"]); sz = ZE::ZETDebugRegsetProperties.size; n = p.size / sz; (0...n).collect { |i| ZE::ZETDebugRegsetProperties.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetDebugGetThreadRegisterSetProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hDebug: #{"0x%016x" % defi["hDebug"]}"
  s << ', '
  s << "thread: #{defi["thread"].size > 0 ? ZE::ZEDeviceThread.new(FFI::MemoryPointer.from_string(defi["thread"])) : nil}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "pRegisterSetProperties: #{"0x%016x" % defi["pRegisterSetProperties"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetDebugGetThreadRegisterSetProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "pRegisterSetProperties_vals: [ #{p = FFI::MemoryPointer.from_string(defi["pRegisterSetProperties_vals"]); sz = ZE::ZETDebugRegsetProperties.size; n = p.size / sz; (0...n).collect { |i| ZE::ZETDebugRegsetProperties.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetDebugReadRegisters_entry"] = lambda { |defi|
  s = "{ "
  s << "hDebug: #{"0x%016x" % defi["hDebug"]}"
  s << ', '
  s << "thread: #{defi["thread"].size > 0 ? ZE::ZEDeviceThread.new(FFI::MemoryPointer.from_string(defi["thread"])) : nil}"
  s << ', '
  s << "type: #{defi["type"]}"
  s << ', '
  s << "start: #{defi["start"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "pRegisterValues: #{"0x%016x" % defi["pRegisterValues"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetDebugReadRegisters_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetDebugWriteRegisters_entry"] = lambda { |defi|
  s = "{ "
  s << "hDebug: #{"0x%016x" % defi["hDebug"]}"
  s << ', '
  s << "thread: #{defi["thread"].size > 0 ? ZE::ZEDeviceThread.new(FFI::MemoryPointer.from_string(defi["thread"])) : nil}"
  s << ', '
  s << "type: #{defi["type"]}"
  s << ', '
  s << "start: #{defi["start"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "pRegisterValues: #{"0x%016x" % defi["pRegisterValues"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetDebugWriteRegisters_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricGroupGet_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "phMetricGroups: #{"0x%016x" % defi["phMetricGroups"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricGroupGet_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "phMetricGroups_vals: [ #{defi["phMetricGroups_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricGroupGetProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hMetricGroup: #{"0x%016x" % defi["hMetricGroup"]}"
  s << ', '
  s << "pProperties: #{"0x%016x" % defi["pProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricGroupGetProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pProperties_val: #{defi["pProperties_val"].size > 0 ? ZE::ZETMetricGroupProperties.new(FFI::MemoryPointer.from_string(defi["pProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricGroupCalculateMetricValues_entry"] = lambda { |defi|
  s = "{ "
  s << "hMetricGroup: #{"0x%016x" % defi["hMetricGroup"]}"
  s << ', '
  s << "type: #{ZE::ZETMetricGroupCalculationType.from_native(defi["type"], nil)}"
  s << ', '
  s << "rawDataSize: #{defi["rawDataSize"]}"
  s << ', '
  s << "pRawData: #{"0x%016x" % defi["pRawData"]}"
  s << ', '
  s << "pMetricValueCount: #{"0x%016x" % defi["pMetricValueCount"]}"
  s << ', '
  s << "pMetricValues: #{"0x%016x" % defi["pMetricValues"]}"
  s << ', '
  s << "pRawData_vals: #{defi["pRawData_vals"].inspect}"
  s << ', '
  s << "pMetricValueCount_val: #{defi["pMetricValueCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricGroupCalculateMetricValues_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pMetricValueCount_val: #{defi["pMetricValueCount_val"]}"
  s << ', '
  s << "pMetricValues_vals: [ #{p = FFI::MemoryPointer.from_string(defi["pMetricValues_vals"]); sz = ZE::ZETTypedValue.size; n = p.size / sz; (0...n).collect { |i| ZE::ZETTypedValue.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricGet_entry"] = lambda { |defi|
  s = "{ "
  s << "hMetricGroup: #{"0x%016x" % defi["hMetricGroup"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "phMetrics: #{"0x%016x" % defi["phMetrics"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricGet_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "phMetrics_vals: [ #{defi["phMetrics_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricGetProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hMetric: #{"0x%016x" % defi["hMetric"]}"
  s << ', '
  s << "pProperties: #{"0x%016x" % defi["pProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricGetProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pProperties_val: #{defi["pProperties_val"].size > 0 ? ZE::ZETMetricProperties.new(FFI::MemoryPointer.from_string(defi["pProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetContextActivateMetricGroups_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "phMetricGroups: #{"0x%016x" % defi["phMetricGroups"]}"
  s << ', '
  s << "phMetricGroups_vals: [ #{defi["phMetricGroups_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetContextActivateMetricGroups_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricStreamerOpen_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "hMetricGroup: #{"0x%016x" % defi["hMetricGroup"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "hNotificationEvent: #{"0x%016x" % defi["hNotificationEvent"]}"
  s << ', '
  s << "phMetricStreamer: #{"0x%016x" % defi["phMetricStreamer"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].size > 0 ? ZE::ZETMetricStreamerDesc.new(FFI::MemoryPointer.from_string(defi["desc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricStreamerOpen_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phMetricStreamer_val: #{"0x%016x" % defi["phMetricStreamer_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetCommandListAppendMetricStreamerMarker_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "hMetricStreamer: #{"0x%016x" % defi["hMetricStreamer"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetCommandListAppendMetricStreamerMarker_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricStreamerClose_entry"] = lambda { |defi|
  s = "{ "
  s << "hMetricStreamer: #{"0x%016x" % defi["hMetricStreamer"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricStreamerClose_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricStreamerReadData_entry"] = lambda { |defi|
  s = "{ "
  s << "hMetricStreamer: #{"0x%016x" % defi["hMetricStreamer"]}"
  s << ', '
  s << "maxReportCount: #{defi["maxReportCount"]}"
  s << ', '
  s << "pRawDataSize: #{"0x%016x" % defi["pRawDataSize"]}"
  s << ', '
  s << "pRawData: #{"0x%016x" % defi["pRawData"]}"
  s << ', '
  s << "pRawDataSize_val: #{defi["pRawDataSize_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricStreamerReadData_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pRawDataSize_val: #{defi["pRawDataSize_val"]}"
  s << ', '
  s << "pRawData_vals: #{defi["pRawData_vals"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricQueryPoolCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "hMetricGroup: #{"0x%016x" % defi["hMetricGroup"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "phMetricQueryPool: #{"0x%016x" % defi["phMetricQueryPool"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].size > 0 ? ZE::ZETMetricQueryPoolDesc.new(FFI::MemoryPointer.from_string(defi["desc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricQueryPoolCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phMetricQueryPool_val: #{"0x%016x" % defi["phMetricQueryPool_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricQueryPoolDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "hMetricQueryPool: #{"0x%016x" % defi["hMetricQueryPool"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricQueryPoolDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricQueryCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "hMetricQueryPool: #{"0x%016x" % defi["hMetricQueryPool"]}"
  s << ', '
  s << "index: #{defi["index"]}"
  s << ', '
  s << "phMetricQuery: #{"0x%016x" % defi["phMetricQuery"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricQueryCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phMetricQuery_val: #{"0x%016x" % defi["phMetricQuery_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricQueryDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "hMetricQuery: #{"0x%016x" % defi["hMetricQuery"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricQueryDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricQueryReset_entry"] = lambda { |defi|
  s = "{ "
  s << "hMetricQuery: #{"0x%016x" % defi["hMetricQuery"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricQueryReset_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetCommandListAppendMetricQueryBegin_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "hMetricQuery: #{"0x%016x" % defi["hMetricQuery"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetCommandListAppendMetricQueryBegin_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetCommandListAppendMetricQueryEnd_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "hMetricQuery: #{"0x%016x" % defi["hMetricQuery"]}"
  s << ', '
  s << "hSignalEvent: #{"0x%016x" % defi["hSignalEvent"]}"
  s << ', '
  s << "numWaitEvents: #{defi["numWaitEvents"]}"
  s << ', '
  s << "phWaitEvents: #{"0x%016x" % defi["phWaitEvents"]}"
  s << ', '
  s << "phWaitEvents_vals: [ #{defi["phWaitEvents_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetCommandListAppendMetricQueryEnd_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetCommandListAppendMetricMemoryBarrier_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetCommandListAppendMetricMemoryBarrier_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricQueryGetData_entry"] = lambda { |defi|
  s = "{ "
  s << "hMetricQuery: #{"0x%016x" % defi["hMetricQuery"]}"
  s << ', '
  s << "pRawDataSize: #{"0x%016x" % defi["pRawDataSize"]}"
  s << ', '
  s << "pRawData: #{"0x%016x" % defi["pRawData"]}"
  s << ', '
  s << "pRawDataSize_val: #{defi["pRawDataSize_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricQueryGetData_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pRawDataSize_val: #{defi["pRawDataSize_val"]}"
  s << ', '
  s << "pRawData_vals: #{defi["pRawData_vals"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetKernelGetProfileInfo_entry"] = lambda { |defi|
  s = "{ "
  s << "hKernel: #{"0x%016x" % defi["hKernel"]}"
  s << ', '
  s << "pProfileProperties: #{"0x%016x" % defi["pProfileProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetKernelGetProfileInfo_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pProfileProperties_val: #{defi["pProfileProperties_val"].size > 0 ? ZE::ZETProfileProperties.new(FFI::MemoryPointer.from_string(defi["pProfileProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetTracerExpCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "phTracer: #{"0x%016x" % defi["phTracer"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].size > 0 ? ZE::ZETTracerExpDesc.new(FFI::MemoryPointer.from_string(defi["desc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetTracerExpCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phTracer_val: #{"0x%016x" % defi["phTracer_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetTracerExpDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetTracerExpDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetTracerExpSetPrologues_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "pCoreCbs: #{"0x%016x" % defi["pCoreCbs"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetTracerExpSetPrologues_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetTracerExpSetEpilogues_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "pCoreCbs: #{"0x%016x" % defi["pCoreCbs"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetTracerExpSetEpilogues_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetTracerExpSetEnabled_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "enable: #{defi["enable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetTracerExpSetEnabled_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetDeviceGetConcurrentMetricGroupsExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "metricGroupCount: #{defi["metricGroupCount"]}"
  s << ', '
  s << "phMetricGroups: #{"0x%016x" % defi["phMetricGroups"]}"
  s << ', '
  s << "pMetricGroupsCountPerConcurrentGroup: #{"0x%016x" % defi["pMetricGroupsCountPerConcurrentGroup"]}"
  s << ', '
  s << "pConcurrentGroupCount: #{"0x%016x" % defi["pConcurrentGroupCount"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetDeviceGetConcurrentMetricGroupsExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricTracerCreateExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "metricGroupCount: #{defi["metricGroupCount"]}"
  s << ', '
  s << "phMetricGroups: #{"0x%016x" % defi["phMetricGroups"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "hNotificationEvent: #{"0x%016x" % defi["hNotificationEvent"]}"
  s << ', '
  s << "phMetricTracer: #{"0x%016x" % defi["phMetricTracer"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricTracerCreateExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricTracerDestroyExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hMetricTracer: #{"0x%016x" % defi["hMetricTracer"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricTracerDestroyExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricTracerEnableExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hMetricTracer: #{"0x%016x" % defi["hMetricTracer"]}"
  s << ', '
  s << "synchronous: #{defi["synchronous"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricTracerEnableExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricTracerDisableExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hMetricTracer: #{"0x%016x" % defi["hMetricTracer"]}"
  s << ', '
  s << "synchronous: #{defi["synchronous"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricTracerDisableExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricTracerReadDataExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hMetricTracer: #{"0x%016x" % defi["hMetricTracer"]}"
  s << ', '
  s << "pRawDataSize: #{"0x%016x" % defi["pRawDataSize"]}"
  s << ', '
  s << "pRawData: #{"0x%016x" % defi["pRawData"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricTracerReadDataExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricDecoderCreateExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hMetricTracer: #{"0x%016x" % defi["hMetricTracer"]}"
  s << ', '
  s << "phMetricDecoder: #{"0x%016x" % defi["phMetricDecoder"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricDecoderCreateExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricDecoderDestroyExp_entry"] = lambda { |defi|
  s = "{ "
  s << "phMetricDecoder: #{"0x%016x" % defi["phMetricDecoder"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricDecoderDestroyExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricDecoderGetDecodableMetricsExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hMetricDecoder: #{"0x%016x" % defi["hMetricDecoder"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "phMetrics: #{"0x%016x" % defi["phMetrics"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricDecoderGetDecodableMetricsExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricTracerDecodeExp_entry"] = lambda { |defi|
  s = "{ "
  s << "phMetricDecoder: #{"0x%016x" % defi["phMetricDecoder"]}"
  s << ', '
  s << "pRawDataSize: #{"0x%016x" % defi["pRawDataSize"]}"
  s << ', '
  s << "pRawData: #{"0x%016x" % defi["pRawData"]}"
  s << ', '
  s << "metricsCount: #{defi["metricsCount"]}"
  s << ', '
  s << "phMetrics: #{"0x%016x" % defi["phMetrics"]}"
  s << ', '
  s << "pSetCount: #{"0x%016x" % defi["pSetCount"]}"
  s << ', '
  s << "pMetricEntriesCountPerSet: #{"0x%016x" % defi["pMetricEntriesCountPerSet"]}"
  s << ', '
  s << "pMetricEntriesCount: #{"0x%016x" % defi["pMetricEntriesCount"]}"
  s << ', '
  s << "pMetricEntries: #{"0x%016x" % defi["pMetricEntries"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricTracerDecodeExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetCommandListAppendMarkerExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "hMetricGroup: #{"0x%016x" % defi["hMetricGroup"]}"
  s << ', '
  s << "value: #{defi["value"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetCommandListAppendMarkerExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetDeviceEnableMetricsExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetDeviceEnableMetricsExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetDeviceDisableMetricsExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetDeviceDisableMetricsExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricGroupCalculateMultipleMetricValuesExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hMetricGroup: #{"0x%016x" % defi["hMetricGroup"]}"
  s << ', '
  s << "type: #{ZE::ZETMetricGroupCalculationType.from_native(defi["type"], nil)}"
  s << ', '
  s << "rawDataSize: #{defi["rawDataSize"]}"
  s << ', '
  s << "pRawData: #{"0x%016x" % defi["pRawData"]}"
  s << ', '
  s << "pSetCount: #{"0x%016x" % defi["pSetCount"]}"
  s << ', '
  s << "pTotalMetricValueCount: #{"0x%016x" % defi["pTotalMetricValueCount"]}"
  s << ', '
  s << "pMetricCounts: #{"0x%016x" % defi["pMetricCounts"]}"
  s << ', '
  s << "pMetricValues: #{"0x%016x" % defi["pMetricValues"]}"
  s << ', '
  s << "pRawData_vals: #{defi["pRawData_vals"].inspect}"
  s << ', '
  s << "pSetCount_val: #{defi["pSetCount_val"]}"
  s << ', '
  s << "pTotalMetricValueCount_val: #{defi["pTotalMetricValueCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricGroupCalculateMultipleMetricValuesExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pSetCount_val: #{defi["pSetCount_val"]}"
  s << ', '
  s << "pTotalMetricValueCount_val: #{defi["pTotalMetricValueCount_val"]}"
  s << ', '
  s << "pMetricCounts_vals: #{defi["pMetricCounts_vals"]}"
  s << ', '
  s << "pMetricValues_vals: [ #{p = FFI::MemoryPointer.from_string(defi["pMetricValues_vals"]); sz = ZE::ZETTypedValue.size; n = p.size / sz; (0...n).collect { |i| ZE::ZETTypedValue.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricGroupGetGlobalTimestampsExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hMetricGroup: #{"0x%016x" % defi["hMetricGroup"]}"
  s << ', '
  s << "synchronizedWithHost: #{defi["synchronizedWithHost"]}"
  s << ', '
  s << "globalTimestamp: #{"0x%016x" % defi["globalTimestamp"]}"
  s << ', '
  s << "metricTimestamp: #{"0x%016x" % defi["metricTimestamp"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricGroupGetGlobalTimestampsExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "globalTimestamp_val: #{defi["globalTimestamp_val"]}"
  s << ', '
  s << "metricTimestamp_val: #{defi["metricTimestamp_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricGroupGetExportDataExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hMetricGroup: #{"0x%016x" % defi["hMetricGroup"]}"
  s << ', '
  s << "pRawData: #{"0x%016x" % defi["pRawData"]}"
  s << ', '
  s << "rawDataSize: #{defi["rawDataSize"]}"
  s << ', '
  s << "pExportDataSize: #{"0x%016x" % defi["pExportDataSize"]}"
  s << ', '
  s << "pExportData: #{"0x%016x" % defi["pExportData"]}"
  s << ', '
  s << "pExportDataSize_val: #{defi["pExportDataSize_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricGroupGetExportDataExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pExportDataSize_val: #{defi["pExportDataSize_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricGroupCalculateMetricExportDataExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hDriver: #{"0x%016x" % defi["hDriver"]}"
  s << ', '
  s << "type: #{ZE::ZETMetricGroupCalculationType.from_native(defi["type"], nil)}"
  s << ', '
  s << "exportDataSize: #{defi["exportDataSize"]}"
  s << ', '
  s << "pExportData: #{"0x%016x" % defi["pExportData"]}"
  s << ', '
  s << "pCalculateDescriptor: #{"0x%016x" % defi["pCalculateDescriptor"]}"
  s << ', '
  s << "pSetCount: #{"0x%016x" % defi["pSetCount"]}"
  s << ', '
  s << "pTotalMetricValueCount: #{"0x%016x" % defi["pTotalMetricValueCount"]}"
  s << ', '
  s << "pMetricCounts: #{"0x%016x" % defi["pMetricCounts"]}"
  s << ', '
  s << "pMetricValues: #{"0x%016x" % defi["pMetricValues"]}"
  s << ', '
  s << "pCalculateDescriptor_val: #{defi["pCalculateDescriptor_val"].size > 0 ? ZE::ZETMetricCalculateExpDesc.new(FFI::MemoryPointer.from_string(defi["pCalculateDescriptor_val"])) : nil}"
  s << ', '
  s << "pSetCount_val: #{defi["pSetCount_val"]}"
  s << ', '
  s << "pTotalMetricValueCount_val: #{defi["pTotalMetricValueCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricGroupCalculateMetricExportDataExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pSetCount_val: #{defi["pSetCount_val"]}"
  s << ', '
  s << "pTotalMetricValueCount_val: #{defi["pTotalMetricValueCount_val"]}"
  s << ', '
  s << "pMetricCounts_vals: #{defi["pMetricCounts_vals"]}"
  s << ', '
  s << "pMetricValues_vals: [ #{p = FFI::MemoryPointer.from_string(defi["pMetricValues_vals"]); sz = ZE::ZETTypedValue.size; n = p.size / sz; (0...n).collect { |i| ZE::ZETTypedValue.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricProgrammableGetExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "phMetricProgrammables: #{"0x%016x" % defi["phMetricProgrammables"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricProgrammableGetExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "phMetricProgrammables_vals: [ #{defi["phMetricProgrammables_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricProgrammableGetPropertiesExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hMetricProgrammable: #{"0x%016x" % defi["hMetricProgrammable"]}"
  s << ', '
  s << "pProperties: #{"0x%016x" % defi["pProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricProgrammableGetPropertiesExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pProperties_val: #{defi["pProperties_val"].size > 0 ? ZE::ZETMetricProgrammableExpProperties.new(FFI::MemoryPointer.from_string(defi["pProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricProgrammableGetParamInfoExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hMetricProgrammable: #{"0x%016x" % defi["hMetricProgrammable"]}"
  s << ', '
  s << "pParameterCount: #{"0x%016x" % defi["pParameterCount"]}"
  s << ', '
  s << "pParameterInfo: #{"0x%016x" % defi["pParameterInfo"]}"
  s << ', '
  s << "pParameterCount_val: #{defi["pParameterCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricProgrammableGetParamInfoExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pParameterCount_val: #{defi["pParameterCount_val"]}"
  s << ', '
  s << "pParameterInfo_vals: [ #{p = FFI::MemoryPointer.from_string(defi["pParameterInfo_vals"]); sz = ZE::ZETMetricProgrammableParamInfoExp.size; n = p.size / sz; (0...n).collect { |i| ZE::ZETMetricProgrammableParamInfoExp.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricProgrammableGetParamValueInfoExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hMetricProgrammable: #{"0x%016x" % defi["hMetricProgrammable"]}"
  s << ', '
  s << "parameterOrdinal: #{defi["parameterOrdinal"]}"
  s << ', '
  s << "pValueInfoCount: #{"0x%016x" % defi["pValueInfoCount"]}"
  s << ', '
  s << "pValueInfo: #{"0x%016x" % defi["pValueInfo"]}"
  s << ', '
  s << "pValueInfoCount_val: #{defi["pValueInfoCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricProgrammableGetParamValueInfoExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pValueInfoCount_val: #{defi["pValueInfoCount_val"]}"
  s << ', '
  s << "pValueInfo_vals: [ #{p = FFI::MemoryPointer.from_string(defi["pValueInfo_vals"]); sz = ZE::ZETMetricProgrammableParamValueInfoExp.size; n = p.size / sz; (0...n).collect { |i| ZE::ZETMetricProgrammableParamValueInfoExp.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricCreateFromProgrammableExp2_entry"] = lambda { |defi|
  s = "{ "
  s << "hMetricProgrammable: #{"0x%016x" % defi["hMetricProgrammable"]}"
  s << ', '
  s << "parameterCount: #{defi["parameterCount"]}"
  s << ', '
  s << "pParameterValues: #{"0x%016x" % defi["pParameterValues"]}"
  s << ', '
  s << "pName: #{"0x%016x" % defi["pName"]}"
  s << ', '
  s << "pDescription: #{"0x%016x" % defi["pDescription"]}"
  s << ', '
  s << "pMetricHandleCount: #{"0x%016x" % defi["pMetricHandleCount"]}"
  s << ', '
  s << "phMetricHandles: #{"0x%016x" % defi["phMetricHandles"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricCreateFromProgrammableExp2_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricCreateFromProgrammableExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hMetricProgrammable: #{"0x%016x" % defi["hMetricProgrammable"]}"
  s << ', '
  s << "pParameterValues: #{"0x%016x" % defi["pParameterValues"]}"
  s << ', '
  s << "parameterCount: #{defi["parameterCount"]}"
  s << ', '
  s << "pName: #{"0x%016x" % defi["pName"]}"
  s << ', '
  s << "pDescription: #{"0x%016x" % defi["pDescription"]}"
  s << ', '
  s << "pMetricHandleCount: #{"0x%016x" % defi["pMetricHandleCount"]}"
  s << ', '
  s << "phMetricHandles: #{"0x%016x" % defi["phMetricHandles"]}"
  s << ', '
  s << "pParameterValues_vals: [ #{p = FFI::MemoryPointer.from_string(defi["pParameterValues_vals"]); sz = ZE::ZETMetricProgrammableParamValueExp.size; n = p.size / sz; (0...n).collect { |i| ZE::ZETMetricProgrammableParamValueExp.new(p + i*sz).to_s}.join(", ")} ]"
  s << ', '
  s << "pName_val: #{defi["pName_val"].inspect}"
  s << ', '
  s << "pDescription_val: #{defi["pDescription_val"].inspect}"
  s << ', '
  s << "pMetricHandleCount_val: #{defi["pMetricHandleCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricCreateFromProgrammableExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pMetricHandleCount_val: #{defi["pMetricHandleCount_val"]}"
  s << ', '
  s << "phMetricHandles_vals: [ #{defi["phMetricHandles_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetDeviceCreateMetricGroupsFromMetricsExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "metricCount: #{defi["metricCount"]}"
  s << ', '
  s << "phMetrics: #{"0x%016x" % defi["phMetrics"]}"
  s << ', '
  s << "pMetricGroupNamePrefix: #{"0x%016x" % defi["pMetricGroupNamePrefix"]}"
  s << ', '
  s << "pDescription: #{"0x%016x" % defi["pDescription"]}"
  s << ', '
  s << "pMetricGroupCount: #{"0x%016x" % defi["pMetricGroupCount"]}"
  s << ', '
  s << "phMetricGroup: #{"0x%016x" % defi["phMetricGroup"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetDeviceCreateMetricGroupsFromMetricsExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricGroupCreateExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pName: #{"0x%016x" % defi["pName"]}"
  s << ', '
  s << "pDescription: #{"0x%016x" % defi["pDescription"]}"
  s << ', '
  s << "samplingType: [ #{ZE::ZETMetricGroupSamplingTypeFlags.from_native(defi["samplingType"], nil).join(", ")} ]"
  s << ', '
  s << "phMetricGroup: #{"0x%016x" % defi["phMetricGroup"]}"
  s << ', '
  s << "pName_val: #{defi["pName_val"].inspect}"
  s << ', '
  s << "pDescription_val: #{defi["pDescription_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricGroupCreateExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phMetricGroup_val: #{"0x%016x" % defi["phMetricGroup_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricGroupAddMetricExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hMetricGroup: #{"0x%016x" % defi["hMetricGroup"]}"
  s << ', '
  s << "hMetric: #{"0x%016x" % defi["hMetric"]}"
  s << ', '
  s << "pErrorStringSize: #{"0x%016x" % defi["pErrorStringSize"]}"
  s << ', '
  s << "pErrorString: #{"0x%016x" % defi["pErrorString"]}"
  s << ', '
  s << "pErrorStringSize_val: #{defi["pErrorStringSize_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricGroupAddMetricExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pErrorStringSize_val: #{defi["pErrorStringSize_val"]}"
  s << ', '
  s << "pErrorString_vals: #{defi["pErrorString_vals"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricGroupRemoveMetricExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hMetricGroup: #{"0x%016x" % defi["hMetricGroup"]}"
  s << ', '
  s << "hMetric: #{"0x%016x" % defi["hMetric"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricGroupRemoveMetricExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricGroupCloseExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hMetricGroup: #{"0x%016x" % defi["hMetricGroup"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricGroupCloseExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricGroupDestroyExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hMetricGroup: #{"0x%016x" % defi["hMetricGroup"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricGroupDestroyExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricDestroyExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hMetric: #{"0x%016x" % defi["hMetric"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetMetricDestroyExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetMetricProgrammableExpProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetMetricProgrammableExpProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetMetricTracerExpProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetMetricTracerExpProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetMetricDecoderExpProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetMetricDecoderExpProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetDeviceProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetDeviceProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetDeviceExpProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetDeviceExpProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetContextProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetContextProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetCommandListProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetCommandListProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetCommandListExpProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetCommandListExpProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetModuleProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetModuleProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetKernelProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetKernelProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetMetricProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetMetricProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetMetricExpProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetMetricExpProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetMetricGroupProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetMetricGroupProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetMetricGroupExpProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetMetricGroupExpProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetMetricStreamerProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetMetricStreamerProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetMetricQueryPoolProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetMetricQueryPoolProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetMetricQueryProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetMetricQueryProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetTracerExpProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetTracerExpProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetDebugProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zet:zetGetDebugProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesInit_entry"] = lambda { |defi|
  s = "{ "
  s << "flags: [ #{ZE::ZESInitFlags.from_native(defi["flags"], nil).join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesInit_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDriverGet_entry"] = lambda { |defi|
  s = "{ "
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "phDrivers: #{"0x%016x" % defi["phDrivers"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDriverGet_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "phDrivers_vals: [ #{defi["phDrivers_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDriverGetExtensionProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hDriver: #{"0x%016x" % defi["hDriver"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "pExtensionProperties: #{"0x%016x" % defi["pExtensionProperties"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDriverGetExtensionProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "pExtensionProperties_vals: [ #{p = FFI::MemoryPointer.from_string(defi["pExtensionProperties_vals"]); sz = ZE::ZESDriverExtensionProperties.size; n = p.size / sz; (0...n).collect { |i| ZE::ZESDriverExtensionProperties.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDriverGetExtensionFunctionAddress_entry"] = lambda { |defi|
  s = "{ "
  s << "hDriver: #{"0x%016x" % defi["hDriver"]}"
  s << ', '
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "ppFunctionAddress: #{"0x%016x" % defi["ppFunctionAddress"]}"
  s << ', '
  s << "name_val: #{defi["name_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDriverGetExtensionFunctionAddress_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "ppFunctionAddress_val: #{"0x%016x" % defi["ppFunctionAddress_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceGet_entry"] = lambda { |defi|
  s = "{ "
  s << "hDriver: #{"0x%016x" % defi["hDriver"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "phDevices: #{"0x%016x" % defi["phDevices"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceGet_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "phDevices_vals: [ #{defi["phDevices_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceGetProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pProperties: #{"0x%016x" % defi["pProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceGetProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pProperties_val: #{defi["pProperties_val"].size > 0 ? ZE::ZESDeviceProperties.new(FFI::MemoryPointer.from_string(defi["pProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceGetState_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pState: #{"0x%016x" % defi["pState"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceGetState_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pState_val: #{defi["pState_val"].size > 0 ? ZE::ZESDeviceState.new(FFI::MemoryPointer.from_string(defi["pState_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceReset_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "force: #{defi["force"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceReset_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceResetExt_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pProperties: #{"0x%016x" % defi["pProperties"]}"
  s << ', '
  s << "pProperties_val: #{defi["pProperties_val"].size > 0 ? ZE::ZESResetProperties.new(FFI::MemoryPointer.from_string(defi["pProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceResetExt_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceProcessesGetState_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "pProcesses: #{"0x%016x" % defi["pProcesses"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceProcessesGetState_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "pProcesses_vals: [ #{p = FFI::MemoryPointer.from_string(defi["pProcesses_vals"]); sz = ZE::ZESProcessState.size; n = p.size / sz; (0...n).collect { |i| ZE::ZESProcessState.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDevicePciGetProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pProperties: #{"0x%016x" % defi["pProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDevicePciGetProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pProperties_val: #{defi["pProperties_val"].size > 0 ? ZE::ZESPciProperties.new(FFI::MemoryPointer.from_string(defi["pProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDevicePciGetState_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pState: #{"0x%016x" % defi["pState"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDevicePciGetState_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pState_val: #{defi["pState_val"].size > 0 ? ZE::ZESPciState.new(FFI::MemoryPointer.from_string(defi["pState_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDevicePciGetBars_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "pProperties: #{"0x%016x" % defi["pProperties"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDevicePciGetBars_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "pProperties_vals: [ #{p = FFI::MemoryPointer.from_string(defi["pProperties_vals"]); sz = ZE::ZESPciBarProperties.size; n = p.size / sz; (0...n).collect { |i| ZE::ZESPciBarProperties.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDevicePciGetStats_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pStats: #{"0x%016x" % defi["pStats"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDevicePciGetStats_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pStats_val: #{defi["pStats_val"].size > 0 ? ZE::ZESPciStats.new(FFI::MemoryPointer.from_string(defi["pStats_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceSetOverclockWaiver_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceSetOverclockWaiver_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceGetOverclockDomains_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pOverclockDomains: #{"0x%016x" % defi["pOverclockDomains"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceGetOverclockDomains_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pOverclockDomains_val: #{defi["pOverclockDomains_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceGetOverclockControls_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "domainType: #{ZE::ZESOverclockDomain.from_native(defi["domainType"], nil)}"
  s << ', '
  s << "pAvailableControls: #{"0x%016x" % defi["pAvailableControls"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceGetOverclockControls_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pAvailableControls_val: #{defi["pAvailableControls_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceResetOverclockSettings_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "onShippedState: #{defi["onShippedState"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceResetOverclockSettings_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceReadOverclockState_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pOverclockMode: #{"0x%016x" % defi["pOverclockMode"]}"
  s << ', '
  s << "pWaiverSetting: #{"0x%016x" % defi["pWaiverSetting"]}"
  s << ', '
  s << "pOverclockState: #{"0x%016x" % defi["pOverclockState"]}"
  s << ', '
  s << "pPendingAction: #{"0x%016x" % defi["pPendingAction"]}"
  s << ', '
  s << "pPendingReset: #{"0x%016x" % defi["pPendingReset"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceReadOverclockState_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pOverclockMode_val: #{ZE::ZESOverclockMode.from_native(defi["pOverclockMode_val"], nil)}"
  s << ', '
  s << "pWaiverSetting_val: #{defi["pWaiverSetting_val"]}"
  s << ', '
  s << "pOverclockState_val: #{defi["pOverclockState_val"]}"
  s << ', '
  s << "pPendingAction_val: #{ZE::ZESPendingAction.from_native(defi["pPendingAction_val"], nil)}"
  s << ', '
  s << "pPendingReset_val: #{defi["pPendingReset_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEnumOverclockDomains_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "phDomainHandle: #{"0x%016x" % defi["phDomainHandle"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEnumOverclockDomains_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "phDomainHandle_vals: [ #{defi["phDomainHandle_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesOverclockGetDomainProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hDomainHandle: #{"0x%016x" % defi["hDomainHandle"]}"
  s << ', '
  s << "pDomainProperties: #{"0x%016x" % defi["pDomainProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesOverclockGetDomainProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pDomainProperties_val: #{defi["pDomainProperties_val"].size > 0 ? ZE::ZESOverclockProperties.new(FFI::MemoryPointer.from_string(defi["pDomainProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesOverclockGetDomainVFProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hDomainHandle: #{"0x%016x" % defi["hDomainHandle"]}"
  s << ', '
  s << "pVFProperties: #{"0x%016x" % defi["pVFProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesOverclockGetDomainVFProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pVFProperties_val: #{defi["pVFProperties_val"].size > 0 ? ZE::ZESVfProperty.new(FFI::MemoryPointer.from_string(defi["pVFProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesOverclockGetDomainControlProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hDomainHandle: #{"0x%016x" % defi["hDomainHandle"]}"
  s << ', '
  s << "DomainControl: #{ZE::ZESOverclockControl.from_native(defi["DomainControl"], nil)}"
  s << ', '
  s << "pControlProperties: #{"0x%016x" % defi["pControlProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesOverclockGetDomainControlProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pControlProperties_val: #{defi["pControlProperties_val"].size > 0 ? ZE::ZESControlProperty.new(FFI::MemoryPointer.from_string(defi["pControlProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesOverclockGetControlCurrentValue_entry"] = lambda { |defi|
  s = "{ "
  s << "hDomainHandle: #{"0x%016x" % defi["hDomainHandle"]}"
  s << ', '
  s << "DomainControl: #{ZE::ZESOverclockControl.from_native(defi["DomainControl"], nil)}"
  s << ', '
  s << "pValue: #{"0x%016x" % defi["pValue"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesOverclockGetControlCurrentValue_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pValue_val: #{defi["pValue_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesOverclockGetControlPendingValue_entry"] = lambda { |defi|
  s = "{ "
  s << "hDomainHandle: #{"0x%016x" % defi["hDomainHandle"]}"
  s << ', '
  s << "DomainControl: #{ZE::ZESOverclockControl.from_native(defi["DomainControl"], nil)}"
  s << ', '
  s << "pValue: #{"0x%016x" % defi["pValue"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesOverclockGetControlPendingValue_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pValue_val: #{defi["pValue_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesOverclockSetControlUserValue_entry"] = lambda { |defi|
  s = "{ "
  s << "hDomainHandle: #{"0x%016x" % defi["hDomainHandle"]}"
  s << ', '
  s << "DomainControl: #{ZE::ZESOverclockControl.from_native(defi["DomainControl"], nil)}"
  s << ', '
  s << "pValue: #{defi["pValue"]}"
  s << ', '
  s << "pPendingAction: #{"0x%016x" % defi["pPendingAction"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesOverclockSetControlUserValue_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pPendingAction_val: #{ZE::ZESPendingAction.from_native(defi["pPendingAction_val"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesOverclockGetControlState_entry"] = lambda { |defi|
  s = "{ "
  s << "hDomainHandle: #{"0x%016x" % defi["hDomainHandle"]}"
  s << ', '
  s << "DomainControl: #{ZE::ZESOverclockControl.from_native(defi["DomainControl"], nil)}"
  s << ', '
  s << "pControlState: #{"0x%016x" % defi["pControlState"]}"
  s << ', '
  s << "pPendingAction: #{"0x%016x" % defi["pPendingAction"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesOverclockGetControlState_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pControlState_val: #{ZE::ZESControlState.from_native(defi["pControlState_val"], nil)}"
  s << ', '
  s << "pPendingAction_val: #{ZE::ZESPendingAction.from_native(defi["pPendingAction_val"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesOverclockGetVFPointValues_entry"] = lambda { |defi|
  s = "{ "
  s << "hDomainHandle: #{"0x%016x" % defi["hDomainHandle"]}"
  s << ', '
  s << "VFType: #{ZE::ZESVfType.from_native(defi["VFType"], nil)}"
  s << ', '
  s << "VFArrayType: #{ZE::ZESVfArrayType.from_native(defi["VFArrayType"], nil)}"
  s << ', '
  s << "PointIndex: #{defi["PointIndex"]}"
  s << ', '
  s << "PointValue: #{"0x%016x" % defi["PointValue"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesOverclockGetVFPointValues_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "PointValue_val: #{defi["PointValue_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesOverclockSetVFPointValues_entry"] = lambda { |defi|
  s = "{ "
  s << "hDomainHandle: #{"0x%016x" % defi["hDomainHandle"]}"
  s << ', '
  s << "VFType: #{ZE::ZESVfType.from_native(defi["VFType"], nil)}"
  s << ', '
  s << "PointIndex: #{defi["PointIndex"]}"
  s << ', '
  s << "PointValue: #{defi["PointValue"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesOverclockSetVFPointValues_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEnumDiagnosticTestSuites_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "phDiagnostics: #{"0x%016x" % defi["phDiagnostics"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEnumDiagnosticTestSuites_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "phDiagnostics_vals: [ #{defi["phDiagnostics_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDiagnosticsGetProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hDiagnostics: #{"0x%016x" % defi["hDiagnostics"]}"
  s << ', '
  s << "pProperties: #{"0x%016x" % defi["pProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDiagnosticsGetProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pProperties_val: #{defi["pProperties_val"].size > 0 ? ZE::ZESDiagProperties.new(FFI::MemoryPointer.from_string(defi["pProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDiagnosticsGetTests_entry"] = lambda { |defi|
  s = "{ "
  s << "hDiagnostics: #{"0x%016x" % defi["hDiagnostics"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "pTests: #{"0x%016x" % defi["pTests"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDiagnosticsGetTests_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "pTests_vals: [ #{p = FFI::MemoryPointer.from_string(defi["pTests_vals"]); sz = ZE::ZESDiagTest.size; n = p.size / sz; (0...n).collect { |i| ZE::ZESDiagTest.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDiagnosticsRunTests_entry"] = lambda { |defi|
  s = "{ "
  s << "hDiagnostics: #{"0x%016x" % defi["hDiagnostics"]}"
  s << ', '
  s << "startIndex: #{defi["startIndex"]}"
  s << ', '
  s << "endIndex: #{defi["endIndex"]}"
  s << ', '
  s << "pResult: #{"0x%016x" % defi["pResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDiagnosticsRunTests_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pResult_val: #{ZE::ZESDiagResult.from_native(defi["pResult_val"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEccAvailable_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pAvailable: #{"0x%016x" % defi["pAvailable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEccAvailable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pAvailable_val: #{defi["pAvailable_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEccConfigurable_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pConfigurable: #{"0x%016x" % defi["pConfigurable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEccConfigurable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pConfigurable_val: #{defi["pConfigurable_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceGetEccState_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pState: #{"0x%016x" % defi["pState"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceGetEccState_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pState_val: #{defi["pState_val"].size > 0 ? ZE::ZESDeviceEccProperties.new(FFI::MemoryPointer.from_string(defi["pState_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceSetEccState_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "newState: #{"0x%016x" % defi["newState"]}"
  s << ', '
  s << "pState: #{"0x%016x" % defi["pState"]}"
  s << ', '
  s << "newState_val: #{defi["newState_val"].size > 0 ? ZE::ZESDeviceEccDesc.new(FFI::MemoryPointer.from_string(defi["newState_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceSetEccState_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pState_val: #{defi["pState_val"].size > 0 ? ZE::ZESDeviceEccProperties.new(FFI::MemoryPointer.from_string(defi["pState_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEnumEngineGroups_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "phEngine: #{"0x%016x" % defi["phEngine"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEnumEngineGroups_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "phEngine_vals: [ #{defi["phEngine_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesEngineGetProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hEngine: #{"0x%016x" % defi["hEngine"]}"
  s << ', '
  s << "pProperties: #{"0x%016x" % defi["pProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesEngineGetProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pProperties_val: #{defi["pProperties_val"].size > 0 ? ZE::ZESEngineProperties.new(FFI::MemoryPointer.from_string(defi["pProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesEngineGetActivity_entry"] = lambda { |defi|
  s = "{ "
  s << "hEngine: #{"0x%016x" % defi["hEngine"]}"
  s << ', '
  s << "pStats: #{"0x%016x" % defi["pStats"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesEngineGetActivity_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pStats_val: #{defi["pStats_val"].size > 0 ? ZE::ZESEngineStats.new(FFI::MemoryPointer.from_string(defi["pStats_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEventRegister_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "events: [ #{ZE::ZESEventTypeFlags.from_native(defi["events"], nil).join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEventRegister_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDriverEventListen_entry"] = lambda { |defi|
  s = "{ "
  s << "hDriver: #{"0x%016x" % defi["hDriver"]}"
  s << ', '
  s << "timeout: #{defi["timeout"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "phDevices: #{"0x%016x" % defi["phDevices"]}"
  s << ', '
  s << "pNumDeviceEvents: #{"0x%016x" % defi["pNumDeviceEvents"]}"
  s << ', '
  s << "pEvents: #{"0x%016x" % defi["pEvents"]}"
  s << ', '
  s << "phDevices_vals: [ #{defi["phDevices_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDriverEventListen_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pNumDeviceEvents_val: #{defi["pNumDeviceEvents_val"]}"
  s << ', '
  s << "pEvents_vals: #{defi["pEvents_vals"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDriverEventListenEx_entry"] = lambda { |defi|
  s = "{ "
  s << "hDriver: #{"0x%016x" % defi["hDriver"]}"
  s << ', '
  s << "timeout: #{defi["timeout"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "phDevices: #{"0x%016x" % defi["phDevices"]}"
  s << ', '
  s << "pNumDeviceEvents: #{"0x%016x" % defi["pNumDeviceEvents"]}"
  s << ', '
  s << "pEvents: #{"0x%016x" % defi["pEvents"]}"
  s << ', '
  s << "phDevices_vals: [ #{defi["phDevices_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDriverEventListenEx_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pNumDeviceEvents_val: #{defi["pNumDeviceEvents_val"]}"
  s << ', '
  s << "pEvents_vals: #{defi["pEvents_vals"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEnumFabricPorts_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "phPort: #{"0x%016x" % defi["phPort"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEnumFabricPorts_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "phPort_vals: [ #{defi["phPort_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFabricPortGetProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hPort: #{"0x%016x" % defi["hPort"]}"
  s << ', '
  s << "pProperties: #{"0x%016x" % defi["pProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFabricPortGetProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pProperties_val: #{defi["pProperties_val"].size > 0 ? ZE::ZESFabricPortProperties.new(FFI::MemoryPointer.from_string(defi["pProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFabricPortGetLinkType_entry"] = lambda { |defi|
  s = "{ "
  s << "hPort: #{"0x%016x" % defi["hPort"]}"
  s << ', '
  s << "pLinkType: #{"0x%016x" % defi["pLinkType"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFabricPortGetLinkType_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pLinkType_val: #{defi["pLinkType_val"].size > 0 ? ZE::ZESFabricLinkType.new(FFI::MemoryPointer.from_string(defi["pLinkType_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFabricPortGetConfig_entry"] = lambda { |defi|
  s = "{ "
  s << "hPort: #{"0x%016x" % defi["hPort"]}"
  s << ', '
  s << "pConfig: #{"0x%016x" % defi["pConfig"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFabricPortGetConfig_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pConfig_val: #{defi["pConfig_val"].size > 0 ? ZE::ZESFabricPortConfig.new(FFI::MemoryPointer.from_string(defi["pConfig_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFabricPortSetConfig_entry"] = lambda { |defi|
  s = "{ "
  s << "hPort: #{"0x%016x" % defi["hPort"]}"
  s << ', '
  s << "pConfig: #{"0x%016x" % defi["pConfig"]}"
  s << ', '
  s << "pConfig_val: #{defi["pConfig_val"].size > 0 ? ZE::ZESFabricPortConfig.new(FFI::MemoryPointer.from_string(defi["pConfig_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFabricPortSetConfig_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFabricPortGetState_entry"] = lambda { |defi|
  s = "{ "
  s << "hPort: #{"0x%016x" % defi["hPort"]}"
  s << ', '
  s << "pState: #{"0x%016x" % defi["pState"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFabricPortGetState_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pState_val: #{defi["pState_val"].size > 0 ? ZE::ZESFabricPortState.new(FFI::MemoryPointer.from_string(defi["pState_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFabricPortGetThroughput_entry"] = lambda { |defi|
  s = "{ "
  s << "hPort: #{"0x%016x" % defi["hPort"]}"
  s << ', '
  s << "pThroughput: #{"0x%016x" % defi["pThroughput"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFabricPortGetThroughput_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pThroughput_val: #{defi["pThroughput_val"].size > 0 ? ZE::ZESFabricPortThroughput.new(FFI::MemoryPointer.from_string(defi["pThroughput_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFabricPortGetFabricErrorCounters_entry"] = lambda { |defi|
  s = "{ "
  s << "hPort: #{"0x%016x" % defi["hPort"]}"
  s << ', '
  s << "pErrors: #{"0x%016x" % defi["pErrors"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFabricPortGetFabricErrorCounters_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pErrors_val: #{defi["pErrors_val"].size > 0 ? ZE::ZESFabricPortErrorCounters.new(FFI::MemoryPointer.from_string(defi["pErrors_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFabricPortGetMultiPortThroughput_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "numPorts: #{defi["numPorts"]}"
  s << ', '
  s << "phPort: #{"0x%016x" % defi["phPort"]}"
  s << ', '
  s << "pThroughput: #{"0x%016x" % defi["pThroughput"]}"
  s << ', '
  s << "phPort_vals: [ #{defi["phPort_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFabricPortGetMultiPortThroughput_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pThroughput_vals: [ #{defi["pThroughput_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEnumFans_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "phFan: #{"0x%016x" % defi["phFan"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEnumFans_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "phFan_vals: [ #{defi["phFan_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFanGetProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hFan: #{"0x%016x" % defi["hFan"]}"
  s << ', '
  s << "pProperties: #{"0x%016x" % defi["pProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFanGetProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pProperties_val: #{defi["pProperties_val"].size > 0 ? ZE::ZESFanProperties.new(FFI::MemoryPointer.from_string(defi["pProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFanGetConfig_entry"] = lambda { |defi|
  s = "{ "
  s << "hFan: #{"0x%016x" % defi["hFan"]}"
  s << ', '
  s << "pConfig: #{"0x%016x" % defi["pConfig"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFanGetConfig_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pConfig_val: #{defi["pConfig_val"].size > 0 ? ZE::ZESFanConfig.new(FFI::MemoryPointer.from_string(defi["pConfig_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFanSetDefaultMode_entry"] = lambda { |defi|
  s = "{ "
  s << "hFan: #{"0x%016x" % defi["hFan"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFanSetDefaultMode_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFanSetFixedSpeedMode_entry"] = lambda { |defi|
  s = "{ "
  s << "hFan: #{"0x%016x" % defi["hFan"]}"
  s << ', '
  s << "speed: #{"0x%016x" % defi["speed"]}"
  s << ', '
  s << "speed_val: #{defi["speed_val"].size > 0 ? ZE::ZESFanSpeed.new(FFI::MemoryPointer.from_string(defi["speed_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFanSetFixedSpeedMode_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFanSetSpeedTableMode_entry"] = lambda { |defi|
  s = "{ "
  s << "hFan: #{"0x%016x" % defi["hFan"]}"
  s << ', '
  s << "speedTable: #{"0x%016x" % defi["speedTable"]}"
  s << ', '
  s << "speedTable_val: #{defi["speedTable_val"].size > 0 ? ZE::ZESFanSpeedTable.new(FFI::MemoryPointer.from_string(defi["speedTable_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFanSetSpeedTableMode_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFanGetState_entry"] = lambda { |defi|
  s = "{ "
  s << "hFan: #{"0x%016x" % defi["hFan"]}"
  s << ', '
  s << "units: #{ZE::ZESFanSpeedUnits.from_native(defi["units"], nil)}"
  s << ', '
  s << "pSpeed: #{"0x%016x" % defi["pSpeed"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFanGetState_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pSpeed_val: #{defi["pSpeed_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEnumFirmwares_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "phFirmware: #{"0x%016x" % defi["phFirmware"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEnumFirmwares_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "phFirmware_vals: [ #{defi["phFirmware_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFirmwareGetProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hFirmware: #{"0x%016x" % defi["hFirmware"]}"
  s << ', '
  s << "pProperties: #{"0x%016x" % defi["pProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFirmwareGetProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pProperties_val: #{defi["pProperties_val"].size > 0 ? ZE::ZESFirmwareProperties.new(FFI::MemoryPointer.from_string(defi["pProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFirmwareFlash_entry"] = lambda { |defi|
  s = "{ "
  s << "hFirmware: #{"0x%016x" % defi["hFirmware"]}"
  s << ', '
  s << "pImage: #{"0x%016x" % defi["pImage"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFirmwareFlash_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFirmwareGetFlashProgress_entry"] = lambda { |defi|
  s = "{ "
  s << "hFirmware: #{"0x%016x" % defi["hFirmware"]}"
  s << ', '
  s << "pCompletionPercent: #{"0x%016x" % defi["pCompletionPercent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFirmwareGetFlashProgress_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCompletionPercent_val: #{defi["pCompletionPercent_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFirmwareGetConsoleLogs_entry"] = lambda { |defi|
  s = "{ "
  s << "hFirmware: #{"0x%016x" % defi["hFirmware"]}"
  s << ', '
  s << "pSize: #{"0x%016x" % defi["pSize"]}"
  s << ', '
  s << "pFirmwareLog: #{"0x%016x" % defi["pFirmwareLog"]}"
  s << ', '
  s << "pSize_val: #{defi["pSize_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFirmwareGetConsoleLogs_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pSize_val: #{defi["pSize_val"]}"
  s << ', '
  s << "pFirmwareLog_vals: #{defi["pFirmwareLog_vals"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEnumFrequencyDomains_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "phFrequency: #{"0x%016x" % defi["phFrequency"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEnumFrequencyDomains_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "phFrequency_vals: [ #{defi["phFrequency_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFrequencyGetProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hFrequency: #{"0x%016x" % defi["hFrequency"]}"
  s << ', '
  s << "pProperties: #{"0x%016x" % defi["pProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFrequencyGetProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pProperties_val: #{defi["pProperties_val"].size > 0 ? ZE::ZESFreqProperties.new(FFI::MemoryPointer.from_string(defi["pProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFrequencyGetAvailableClocks_entry"] = lambda { |defi|
  s = "{ "
  s << "hFrequency: #{"0x%016x" % defi["hFrequency"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "phFrequency: #{"0x%016x" % defi["phFrequency"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFrequencyGetAvailableClocks_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "phFrequency_vals: [ #{defi["phFrequency_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFrequencyGetRange_entry"] = lambda { |defi|
  s = "{ "
  s << "hFrequency: #{"0x%016x" % defi["hFrequency"]}"
  s << ', '
  s << "pLimits: #{"0x%016x" % defi["pLimits"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFrequencyGetRange_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pLimits_val: #{defi["pLimits_val"].size > 0 ? ZE::ZESFreqRange.new(FFI::MemoryPointer.from_string(defi["pLimits_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFrequencySetRange_entry"] = lambda { |defi|
  s = "{ "
  s << "hFrequency: #{"0x%016x" % defi["hFrequency"]}"
  s << ', '
  s << "pLimits: #{"0x%016x" % defi["pLimits"]}"
  s << ', '
  s << "pLimits_val: #{defi["pLimits_val"].size > 0 ? ZE::ZESFreqRange.new(FFI::MemoryPointer.from_string(defi["pLimits_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFrequencySetRange_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFrequencyGetState_entry"] = lambda { |defi|
  s = "{ "
  s << "hFrequency: #{"0x%016x" % defi["hFrequency"]}"
  s << ', '
  s << "pState: #{"0x%016x" % defi["pState"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFrequencyGetState_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pState_val: #{defi["pState_val"].size > 0 ? ZE::ZESFreqState.new(FFI::MemoryPointer.from_string(defi["pState_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFrequencyGetThrottleTime_entry"] = lambda { |defi|
  s = "{ "
  s << "hFrequency: #{"0x%016x" % defi["hFrequency"]}"
  s << ', '
  s << "pThrottleTime: #{"0x%016x" % defi["pThrottleTime"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFrequencyGetThrottleTime_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pThrottleTime_val: #{defi["pThrottleTime_val"].size > 0 ? ZE::ZESFreqThrottleTime.new(FFI::MemoryPointer.from_string(defi["pThrottleTime_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFrequencyOcGetCapabilities_entry"] = lambda { |defi|
  s = "{ "
  s << "hFrequency: #{"0x%016x" % defi["hFrequency"]}"
  s << ', '
  s << "pOcCapabilities: #{"0x%016x" % defi["pOcCapabilities"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFrequencyOcGetCapabilities_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pOcCapabilities_val: #{defi["pOcCapabilities_val"].size > 0 ? ZE::ZESOcCapabilities.new(FFI::MemoryPointer.from_string(defi["pOcCapabilities_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFrequencyOcGetFrequencyTarget_entry"] = lambda { |defi|
  s = "{ "
  s << "hFrequency: #{"0x%016x" % defi["hFrequency"]}"
  s << ', '
  s << "pCurrentOcFrequency: #{"0x%016x" % defi["pCurrentOcFrequency"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFrequencyOcGetFrequencyTarget_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCurrentOcFrequency_val: #{defi["pCurrentOcFrequency_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFrequencyOcSetFrequencyTarget_entry"] = lambda { |defi|
  s = "{ "
  s << "hFrequency: #{"0x%016x" % defi["hFrequency"]}"
  s << ', '
  s << "CurrentOcFrequency: #{defi["CurrentOcFrequency"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFrequencyOcSetFrequencyTarget_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFrequencyOcGetVoltageTarget_entry"] = lambda { |defi|
  s = "{ "
  s << "hFrequency: #{"0x%016x" % defi["hFrequency"]}"
  s << ', '
  s << "pCurrentVoltageTarget: #{"0x%016x" % defi["pCurrentVoltageTarget"]}"
  s << ', '
  s << "pCurrentVoltageOffset: #{"0x%016x" % defi["pCurrentVoltageOffset"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFrequencyOcGetVoltageTarget_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCurrentVoltageTarget_val: #{defi["pCurrentVoltageTarget_val"]}"
  s << ', '
  s << "pCurrentVoltageOffset_val: #{defi["pCurrentVoltageOffset_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFrequencyOcSetVoltageTarget_entry"] = lambda { |defi|
  s = "{ "
  s << "hFrequency: #{"0x%016x" % defi["hFrequency"]}"
  s << ', '
  s << "CurrentVoltageTarget: #{defi["CurrentVoltageTarget"]}"
  s << ', '
  s << "CurrentVoltageOffset: #{defi["CurrentVoltageOffset"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFrequencyOcSetVoltageTarget_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFrequencyOcSetMode_entry"] = lambda { |defi|
  s = "{ "
  s << "hFrequency: #{"0x%016x" % defi["hFrequency"]}"
  s << ', '
  s << "CurrentOcMode: #{ZE::ZESOcMode.from_native(defi["CurrentOcMode"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFrequencyOcSetMode_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFrequencyOcGetMode_entry"] = lambda { |defi|
  s = "{ "
  s << "hFrequency: #{"0x%016x" % defi["hFrequency"]}"
  s << ', '
  s << "pCurrentOcMode: #{"0x%016x" % defi["pCurrentOcMode"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFrequencyOcGetMode_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCurrentOcMode_val: #{ZE::ZESOcMode.from_native(defi["pCurrentOcMode_val"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFrequencyOcGetIccMax_entry"] = lambda { |defi|
  s = "{ "
  s << "hFrequency: #{"0x%016x" % defi["hFrequency"]}"
  s << ', '
  s << "pOcIccMax: #{"0x%016x" % defi["pOcIccMax"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFrequencyOcGetIccMax_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pOcIccMax_val: #{defi["pOcIccMax_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFrequencyOcSetIccMax_entry"] = lambda { |defi|
  s = "{ "
  s << "hFrequency: #{"0x%016x" % defi["hFrequency"]}"
  s << ', '
  s << "ocIccMax: #{defi["ocIccMax"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFrequencyOcSetIccMax_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFrequencyOcGetTjMax_entry"] = lambda { |defi|
  s = "{ "
  s << "hFrequency: #{"0x%016x" % defi["hFrequency"]}"
  s << ', '
  s << "pOcTjMax: #{"0x%016x" % defi["pOcTjMax"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFrequencyOcGetTjMax_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pOcTjMax_val: #{defi["pOcTjMax_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFrequencyOcSetTjMax_entry"] = lambda { |defi|
  s = "{ "
  s << "hFrequency: #{"0x%016x" % defi["hFrequency"]}"
  s << ', '
  s << "ocTjMax: #{defi["ocTjMax"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFrequencyOcSetTjMax_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEnumLeds_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "phLed: #{"0x%016x" % defi["phLed"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEnumLeds_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "phLed_vals: [ #{defi["phLed_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesLedGetProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hLed: #{"0x%016x" % defi["hLed"]}"
  s << ', '
  s << "pProperties: #{"0x%016x" % defi["pProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesLedGetProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pProperties_val: #{defi["pProperties_val"].size > 0 ? ZE::ZESLedProperties.new(FFI::MemoryPointer.from_string(defi["pProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesLedGetState_entry"] = lambda { |defi|
  s = "{ "
  s << "hLed: #{"0x%016x" % defi["hLed"]}"
  s << ', '
  s << "pState: #{"0x%016x" % defi["pState"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesLedGetState_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pState_val: #{defi["pState_val"].size > 0 ? ZE::ZESLedState.new(FFI::MemoryPointer.from_string(defi["pState_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesLedSetState_entry"] = lambda { |defi|
  s = "{ "
  s << "hLed: #{"0x%016x" % defi["hLed"]}"
  s << ', '
  s << "enable: #{defi["enable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesLedSetState_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesLedSetColor_entry"] = lambda { |defi|
  s = "{ "
  s << "hLed: #{"0x%016x" % defi["hLed"]}"
  s << ', '
  s << "pColor: #{"0x%016x" % defi["pColor"]}"
  s << ', '
  s << "pColor_val: #{defi["pColor_val"].size > 0 ? ZE::ZESLedColor.new(FFI::MemoryPointer.from_string(defi["pColor_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesLedSetColor_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEnumMemoryModules_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "phMemory: #{"0x%016x" % defi["phMemory"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEnumMemoryModules_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "phMemory_vals: [ #{defi["phMemory_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesMemoryGetProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hMemory: #{"0x%016x" % defi["hMemory"]}"
  s << ', '
  s << "pProperties: #{"0x%016x" % defi["pProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesMemoryGetProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pProperties_val: #{defi["pProperties_val"].size > 0 ? ZE::ZESMemProperties.new(FFI::MemoryPointer.from_string(defi["pProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesMemoryGetState_entry"] = lambda { |defi|
  s = "{ "
  s << "hMemory: #{"0x%016x" % defi["hMemory"]}"
  s << ', '
  s << "pState: #{"0x%016x" % defi["pState"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesMemoryGetState_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pState_val: #{defi["pState_val"].size > 0 ? ZE::ZESMemState.new(FFI::MemoryPointer.from_string(defi["pState_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesMemoryGetBandwidth_entry"] = lambda { |defi|
  s = "{ "
  s << "hMemory: #{"0x%016x" % defi["hMemory"]}"
  s << ', '
  s << "pBandwidth: #{"0x%016x" % defi["pBandwidth"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesMemoryGetBandwidth_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pBandwidth_val: #{defi["pBandwidth_val"].size > 0 ? ZE::ZESMemBandwidth.new(FFI::MemoryPointer.from_string(defi["pBandwidth_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEnumPerformanceFactorDomains_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "phPerf: #{"0x%016x" % defi["phPerf"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEnumPerformanceFactorDomains_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "phPerf_vals: [ #{defi["phPerf_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesPerformanceFactorGetProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hPerf: #{"0x%016x" % defi["hPerf"]}"
  s << ', '
  s << "pProperties: #{"0x%016x" % defi["pProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesPerformanceFactorGetProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pProperties_val: #{defi["pProperties_val"].size > 0 ? ZE::ZESPerfProperties.new(FFI::MemoryPointer.from_string(defi["pProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesPerformanceFactorGetConfig_entry"] = lambda { |defi|
  s = "{ "
  s << "hPerf: #{"0x%016x" % defi["hPerf"]}"
  s << ', '
  s << "pFactor: #{"0x%016x" % defi["pFactor"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesPerformanceFactorGetConfig_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pFactor_val: #{defi["pFactor_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesPerformanceFactorSetConfig_entry"] = lambda { |defi|
  s = "{ "
  s << "hPerf: #{"0x%016x" % defi["hPerf"]}"
  s << ', '
  s << "factor: #{defi["factor"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesPerformanceFactorSetConfig_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEnumPowerDomains_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "phPower: #{"0x%016x" % defi["phPower"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEnumPowerDomains_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "phPower_vals: [ #{defi["phPower_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceGetCardPowerDomain_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "phPower: #{"0x%016x" % defi["phPower"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceGetCardPowerDomain_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phPower_val: #{"0x%016x" % defi["phPower_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesPowerGetProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hPower: #{"0x%016x" % defi["hPower"]}"
  s << ', '
  s << "pProperties: #{"0x%016x" % defi["pProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesPowerGetProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pProperties_val: #{defi["pProperties_val"].size > 0 ? ZE::ZESPowerProperties.new(FFI::MemoryPointer.from_string(defi["pProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesPowerGetEnergyCounter_entry"] = lambda { |defi|
  s = "{ "
  s << "hPower: #{"0x%016x" % defi["hPower"]}"
  s << ', '
  s << "pEnergy: #{"0x%016x" % defi["pEnergy"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesPowerGetEnergyCounter_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pEnergy_val: #{defi["pEnergy_val"].size > 0 ? ZE::ZESPowerEnergyCounter.new(FFI::MemoryPointer.from_string(defi["pEnergy_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesPowerGetLimits_entry"] = lambda { |defi|
  s = "{ "
  s << "hPower: #{"0x%016x" % defi["hPower"]}"
  s << ', '
  s << "pSustained: #{"0x%016x" % defi["pSustained"]}"
  s << ', '
  s << "pBurst: #{"0x%016x" % defi["pBurst"]}"
  s << ', '
  s << "pPeak: #{"0x%016x" % defi["pPeak"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesPowerGetLimits_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pSustained_val: #{defi["pSustained_val"].size > 0 ? ZE::ZESPowerSustainedLimit.new(FFI::MemoryPointer.from_string(defi["pSustained_val"])) : nil}"
  s << ', '
  s << "pBurst_val: #{defi["pBurst_val"].size > 0 ? ZE::ZESPowerBurstLimit.new(FFI::MemoryPointer.from_string(defi["pBurst_val"])) : nil}"
  s << ', '
  s << "pPeak_val: #{defi["pPeak_val"].size > 0 ? ZE::ZESPowerPeakLimit.new(FFI::MemoryPointer.from_string(defi["pPeak_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesPowerSetLimits_entry"] = lambda { |defi|
  s = "{ "
  s << "hPower: #{"0x%016x" % defi["hPower"]}"
  s << ', '
  s << "pSustained: #{"0x%016x" % defi["pSustained"]}"
  s << ', '
  s << "pBurst: #{"0x%016x" % defi["pBurst"]}"
  s << ', '
  s << "pPeak: #{"0x%016x" % defi["pPeak"]}"
  s << ', '
  s << "pSustained_val: #{defi["pSustained_val"].size > 0 ? ZE::ZESPowerSustainedLimit.new(FFI::MemoryPointer.from_string(defi["pSustained_val"])) : nil}"
  s << ', '
  s << "pBurst_val: #{defi["pBurst_val"].size > 0 ? ZE::ZESPowerBurstLimit.new(FFI::MemoryPointer.from_string(defi["pBurst_val"])) : nil}"
  s << ', '
  s << "pPeak_val: #{defi["pPeak_val"].size > 0 ? ZE::ZESPowerPeakLimit.new(FFI::MemoryPointer.from_string(defi["pPeak_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesPowerSetLimits_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesPowerGetEnergyThreshold_entry"] = lambda { |defi|
  s = "{ "
  s << "hPower: #{"0x%016x" % defi["hPower"]}"
  s << ', '
  s << "pThreshold: #{"0x%016x" % defi["pThreshold"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesPowerGetEnergyThreshold_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pThreshold_val: #{defi["pThreshold_val"].size > 0 ? ZE::ZESEnergyThreshold.new(FFI::MemoryPointer.from_string(defi["pThreshold_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesPowerSetEnergyThreshold_entry"] = lambda { |defi|
  s = "{ "
  s << "hPower: #{"0x%016x" % defi["hPower"]}"
  s << ', '
  s << "threshold: #{defi["threshold"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesPowerSetEnergyThreshold_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEnumPsus_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "phPsu: #{"0x%016x" % defi["phPsu"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEnumPsus_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "phPsu_vals: [ #{defi["phPsu_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesPsuGetProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hPsu: #{"0x%016x" % defi["hPsu"]}"
  s << ', '
  s << "pProperties: #{"0x%016x" % defi["pProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesPsuGetProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pProperties_val: #{defi["pProperties_val"].size > 0 ? ZE::ZESPsuProperties.new(FFI::MemoryPointer.from_string(defi["pProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesPsuGetState_entry"] = lambda { |defi|
  s = "{ "
  s << "hPsu: #{"0x%016x" % defi["hPsu"]}"
  s << ', '
  s << "pState: #{"0x%016x" % defi["pState"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesPsuGetState_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pState_val: #{defi["pState_val"].size > 0 ? ZE::ZESPsuState.new(FFI::MemoryPointer.from_string(defi["pState_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEnumRasErrorSets_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "phRas: #{"0x%016x" % defi["phRas"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEnumRasErrorSets_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "phRas_vals: [ #{defi["phRas_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesRasGetProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hRas: #{"0x%016x" % defi["hRas"]}"
  s << ', '
  s << "pProperties: #{"0x%016x" % defi["pProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesRasGetProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pProperties_val: #{defi["pProperties_val"].size > 0 ? ZE::ZESRasProperties.new(FFI::MemoryPointer.from_string(defi["pProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesRasGetConfig_entry"] = lambda { |defi|
  s = "{ "
  s << "hRas: #{"0x%016x" % defi["hRas"]}"
  s << ', '
  s << "pConfig: #{"0x%016x" % defi["pConfig"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesRasGetConfig_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pConfig_val: #{defi["pConfig_val"].size > 0 ? ZE::ZESRasConfig.new(FFI::MemoryPointer.from_string(defi["pConfig_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesRasSetConfig_entry"] = lambda { |defi|
  s = "{ "
  s << "hRas: #{"0x%016x" % defi["hRas"]}"
  s << ', '
  s << "pConfig: #{"0x%016x" % defi["pConfig"]}"
  s << ', '
  s << "pConfig_val: #{defi["pConfig_val"].size > 0 ? ZE::ZESRasConfig.new(FFI::MemoryPointer.from_string(defi["pConfig_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesRasSetConfig_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesRasGetState_entry"] = lambda { |defi|
  s = "{ "
  s << "hRas: #{"0x%016x" % defi["hRas"]}"
  s << ', '
  s << "clear: #{defi["clear"]}"
  s << ', '
  s << "pState: #{"0x%016x" % defi["pState"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesRasGetState_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pState_val: #{defi["pState_val"].size > 0 ? ZE::ZESRasState.new(FFI::MemoryPointer.from_string(defi["pState_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEnumSchedulers_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "phScheduler: #{"0x%016x" % defi["phScheduler"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEnumSchedulers_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "phScheduler_vals: [ #{defi["phScheduler_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesSchedulerGetProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hScheduler: #{"0x%016x" % defi["hScheduler"]}"
  s << ', '
  s << "pProperties: #{"0x%016x" % defi["pProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesSchedulerGetProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pProperties_val: #{defi["pProperties_val"].size > 0 ? ZE::ZESSchedProperties.new(FFI::MemoryPointer.from_string(defi["pProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesSchedulerGetCurrentMode_entry"] = lambda { |defi|
  s = "{ "
  s << "hScheduler: #{"0x%016x" % defi["hScheduler"]}"
  s << ', '
  s << "pMode: #{"0x%016x" % defi["pMode"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesSchedulerGetCurrentMode_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pMode_val: #{ZE::ZESSchedMode.from_native(defi["pMode_val"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesSchedulerGetTimeoutModeProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hScheduler: #{"0x%016x" % defi["hScheduler"]}"
  s << ', '
  s << "getDefaults: #{defi["getDefaults"]}"
  s << ', '
  s << "pConfig: #{"0x%016x" % defi["pConfig"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesSchedulerGetTimeoutModeProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pConfig_val: #{defi["pConfig_val"].size > 0 ? ZE::ZESSchedTimeoutProperties.new(FFI::MemoryPointer.from_string(defi["pConfig_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesSchedulerGetTimesliceModeProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hScheduler: #{"0x%016x" % defi["hScheduler"]}"
  s << ', '
  s << "getDefaults: #{defi["getDefaults"]}"
  s << ', '
  s << "pConfig: #{"0x%016x" % defi["pConfig"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesSchedulerGetTimesliceModeProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pConfig_val: #{defi["pConfig_val"].size > 0 ? ZE::ZESSchedTimesliceProperties.new(FFI::MemoryPointer.from_string(defi["pConfig_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesSchedulerSetTimeoutMode_entry"] = lambda { |defi|
  s = "{ "
  s << "hScheduler: #{"0x%016x" % defi["hScheduler"]}"
  s << ', '
  s << "pProperties: #{"0x%016x" % defi["pProperties"]}"
  s << ', '
  s << "pNeedReload: #{"0x%016x" % defi["pNeedReload"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesSchedulerSetTimeoutMode_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pProperties_val: #{defi["pProperties_val"].size > 0 ? ZE::ZESSchedTimeoutProperties.new(FFI::MemoryPointer.from_string(defi["pProperties_val"])) : nil}"
  s << ', '
  s << "pNeedReload_val: #{defi["pNeedReload_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesSchedulerSetTimesliceMode_entry"] = lambda { |defi|
  s = "{ "
  s << "hScheduler: #{"0x%016x" % defi["hScheduler"]}"
  s << ', '
  s << "pProperties: #{"0x%016x" % defi["pProperties"]}"
  s << ', '
  s << "pNeedReload: #{"0x%016x" % defi["pNeedReload"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesSchedulerSetTimesliceMode_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pProperties_val: #{defi["pProperties_val"].size > 0 ? ZE::ZESSchedTimesliceProperties.new(FFI::MemoryPointer.from_string(defi["pProperties_val"])) : nil}"
  s << ', '
  s << "pNeedReload_val: #{defi["pNeedReload_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesSchedulerSetExclusiveMode_entry"] = lambda { |defi|
  s = "{ "
  s << "hScheduler: #{"0x%016x" % defi["hScheduler"]}"
  s << ', '
  s << "pNeedReload: #{"0x%016x" % defi["pNeedReload"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesSchedulerSetExclusiveMode_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pNeedReload_val: #{defi["pNeedReload_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesSchedulerSetComputeUnitDebugMode_entry"] = lambda { |defi|
  s = "{ "
  s << "hScheduler: #{"0x%016x" % defi["hScheduler"]}"
  s << ', '
  s << "pNeedReload: #{"0x%016x" % defi["pNeedReload"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesSchedulerSetComputeUnitDebugMode_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pNeedReload_val: #{defi["pNeedReload_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEnumStandbyDomains_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "phStandby: #{"0x%016x" % defi["phStandby"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEnumStandbyDomains_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "phStandby_vals: [ #{defi["phStandby_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesStandbyGetProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hStandby: #{"0x%016x" % defi["hStandby"]}"
  s << ', '
  s << "pProperties: #{"0x%016x" % defi["pProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesStandbyGetProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pProperties_val: #{defi["pProperties_val"].size > 0 ? ZE::ZESStandbyProperties.new(FFI::MemoryPointer.from_string(defi["pProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesStandbyGetMode_entry"] = lambda { |defi|
  s = "{ "
  s << "hStandby: #{"0x%016x" % defi["hStandby"]}"
  s << ', '
  s << "pMode: #{"0x%016x" % defi["pMode"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesStandbyGetMode_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pMode_val: #{ZE::ZESStandbyPromoMode.from_native(defi["pMode_val"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesStandbySetMode_entry"] = lambda { |defi|
  s = "{ "
  s << "hStandby: #{"0x%016x" % defi["hStandby"]}"
  s << ', '
  s << "mode: #{ZE::ZESStandbyPromoMode.from_native(defi["mode"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesStandbySetMode_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEnumTemperatureSensors_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "phTemperature: #{"0x%016x" % defi["phTemperature"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEnumTemperatureSensors_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "phTemperature_vals: [ #{defi["phTemperature_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesTemperatureGetProperties_entry"] = lambda { |defi|
  s = "{ "
  s << "hTemperature: #{"0x%016x" % defi["hTemperature"]}"
  s << ', '
  s << "pProperties: #{"0x%016x" % defi["pProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesTemperatureGetProperties_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pProperties_val: #{defi["pProperties_val"].size > 0 ? ZE::ZESTempProperties.new(FFI::MemoryPointer.from_string(defi["pProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesTemperatureGetConfig_entry"] = lambda { |defi|
  s = "{ "
  s << "hTemperature: #{"0x%016x" % defi["hTemperature"]}"
  s << ', '
  s << "pConfig: #{"0x%016x" % defi["pConfig"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesTemperatureGetConfig_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pConfig_val: #{defi["pConfig_val"].size > 0 ? ZE::ZESTempConfig.new(FFI::MemoryPointer.from_string(defi["pConfig_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesTemperatureSetConfig_entry"] = lambda { |defi|
  s = "{ "
  s << "hTemperature: #{"0x%016x" % defi["hTemperature"]}"
  s << ', '
  s << "pConfig: #{"0x%016x" % defi["pConfig"]}"
  s << ', '
  s << "pConfig_val: #{defi["pConfig_val"].size > 0 ? ZE::ZESTempConfig.new(FFI::MemoryPointer.from_string(defi["pConfig_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesTemperatureSetConfig_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesTemperatureGetState_entry"] = lambda { |defi|
  s = "{ "
  s << "hTemperature: #{"0x%016x" % defi["hTemperature"]}"
  s << ', '
  s << "pTemperature: #{"0x%016x" % defi["pTemperature"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesTemperatureGetState_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pTemperature_val: #{defi["pTemperature_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesPowerGetLimitsExt_entry"] = lambda { |defi|
  s = "{ "
  s << "hPower: #{"0x%016x" % defi["hPower"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "pSustained: #{"0x%016x" % defi["pSustained"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesPowerGetLimitsExt_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "pSustained_vals: [ #{p = FFI::MemoryPointer.from_string(defi["pSustained_vals"]); sz = ZE::ZESPowerLimitExtDesc.size; n = p.size / sz; (0...n).collect { |i| ZE::ZESPowerLimitExtDesc.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesPowerSetLimitsExt_entry"] = lambda { |defi|
  s = "{ "
  s << "hPower: #{"0x%016x" % defi["hPower"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "pSustained: #{"0x%016x" % defi["pSustained"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "pSustained_vals: [ #{p = FFI::MemoryPointer.from_string(defi["pSustained_vals"]); sz = ZE::ZESPowerLimitExtDesc.size; n = p.size / sz; (0...n).collect { |i| ZE::ZESPowerLimitExtDesc.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesPowerSetLimitsExt_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesEngineGetActivityExt_entry"] = lambda { |defi|
  s = "{ "
  s << "hEngine: #{"0x%016x" % defi["hEngine"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "pStats: #{"0x%016x" % defi["pStats"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesEngineGetActivityExt_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "pStats_vals: [ #{p = FFI::MemoryPointer.from_string(defi["pStats_vals"]); sz = ZE::ZESEngineStats.size; n = p.size / sz; (0...n).collect { |i| ZE::ZESEngineStats.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesRasGetStateExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hRas: #{"0x%016x" % defi["hRas"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "pState: #{"0x%016x" % defi["pState"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesRasGetStateExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "pState_vals: [ #{p = FFI::MemoryPointer.from_string(defi["pState_vals"]); sz = ZE::ZESRasStateExp.size; n = p.size / sz; (0...n).collect { |i| ZE::ZESRasStateExp.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesRasClearStateExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hRas: #{"0x%016x" % defi["hRas"]}"
  s << ', '
  s << "category: #{ZE::ZESRasErrorCategoryExp.from_native(defi["category"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesRasClearStateExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFirmwareGetSecurityVersionExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hFirmware: #{"0x%016x" % defi["hFirmware"]}"
  s << ', '
  s << "pVersion: #{"0x%016x" % defi["pVersion"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFirmwareGetSecurityVersionExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pVersion_val: #{defi["pVersion_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFirmwareSetSecurityVersionExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hFirmware: #{"0x%016x" % defi["hFirmware"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesFirmwareSetSecurityVersionExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceGetSubDevicePropertiesExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "pSubdeviceProps: #{"0x%016x" % defi["pSubdeviceProps"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceGetSubDevicePropertiesExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "pSubdeviceProps_vals: [ #{p = FFI::MemoryPointer.from_string(defi["pSubdeviceProps_vals"]); sz = ZE::ZESSubdeviceExpProperties.size; n = p.size / sz; (0...n).collect { |i| ZE::ZESSubdeviceExpProperties.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDriverGetDeviceByUuidExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hDriver: #{"0x%016x" % defi["hDriver"]}"
  s << ', '
  s << "uuid: #{defi["uuid"].size > 0 ? ZE::ZESUUID.new(FFI::MemoryPointer.from_string(defi["uuid"])) : nil}"
  s << ', '
  s << "phDevice: #{"0x%016x" % defi["phDevice"]}"
  s << ', '
  s << "onSubdevice: #{"0x%016x" % defi["onSubdevice"]}"
  s << ', '
  s << "subdeviceId: #{"0x%016x" % defi["subdeviceId"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDriverGetDeviceByUuidExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "phDevice_val: #{"0x%016x" % defi["phDevice_val"]}"
  s << ', '
  s << "onSubdevice_val: #{defi["onSubdevice_val"]}"
  s << ', '
  s << "subdeviceId_val: #{defi["subdeviceId_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEnumActiveVFExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "phVFhandle: #{"0x%016x" % defi["phVFhandle"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEnumActiveVFExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "phVFhandle_vals: [ #{defi["phVFhandle_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesVFManagementGetVFPropertiesExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hVFhandle: #{"0x%016x" % defi["hVFhandle"]}"
  s << ', '
  s << "pProperties: #{"0x%016x" % defi["pProperties"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesVFManagementGetVFPropertiesExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pProperties_val: #{defi["pProperties_val"].size > 0 ? ZE::ZESVfExpProperties.new(FFI::MemoryPointer.from_string(defi["pProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesVFManagementGetVFMemoryUtilizationExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hVFhandle: #{"0x%016x" % defi["hVFhandle"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "pMemUtil: #{"0x%016x" % defi["pMemUtil"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesVFManagementGetVFMemoryUtilizationExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "pMemUtil_vals: [ #{p = FFI::MemoryPointer.from_string(defi["pMemUtil_vals"]); sz = ZE::ZESVfUtilMemExp.size; n = p.size / sz; (0...n).collect { |i| ZE::ZESVfUtilMemExp.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesVFManagementGetVFEngineUtilizationExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hVFhandle: #{"0x%016x" % defi["hVFhandle"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "pEngineUtil: #{"0x%016x" % defi["pEngineUtil"]}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesVFManagementGetVFEngineUtilizationExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pCount_val: #{defi["pCount_val"]}"
  s << ', '
  s << "pEngineUtil_vals: [ #{p = FFI::MemoryPointer.from_string(defi["pEngineUtil_vals"]); sz = ZE::ZESVfUtilEngineExp.size; n = p.size / sz; (0...n).collect { |i| ZE::ZESVfUtilEngineExp.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesVFManagementSetVFTelemetryModeExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hVFhandle: #{"0x%016x" % defi["hVFhandle"]}"
  s << ', '
  s << "flags: [ #{ZE::ZESVfInfoUtilExpFlags.from_native(defi["flags"], nil).join(", ")} ]"
  s << ', '
  s << "enable: #{defi["enable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesVFManagementSetVFTelemetryModeExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesVFManagementSetVFTelemetrySamplingIntervalExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hVFhandle: #{"0x%016x" % defi["hVFhandle"]}"
  s << ', '
  s << "flag: [ #{ZE::ZESVfInfoUtilExpFlags.from_native(defi["flag"], nil).join(", ")} ]"
  s << ', '
  s << "samplingInterval: #{defi["samplingInterval"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesVFManagementSetVFTelemetrySamplingIntervalExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEnumEnabledVFExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "phVFhandle: #{"0x%016x" % defi["phVFhandle"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesDeviceEnumEnabledVFExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesVFManagementGetVFCapabilitiesExp_entry"] = lambda { |defi|
  s = "{ "
  s << "hVFhandle: #{"0x%016x" % defi["hVFhandle"]}"
  s << ', '
  s << "pCapability: #{"0x%016x" % defi["pCapability"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesVFManagementGetVFCapabilitiesExp_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesVFManagementGetVFMemoryUtilizationExp2_entry"] = lambda { |defi|
  s = "{ "
  s << "hVFhandle: #{"0x%016x" % defi["hVFhandle"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "pMemUtil: #{"0x%016x" % defi["pMemUtil"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesVFManagementGetVFMemoryUtilizationExp2_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesVFManagementGetVFEngineUtilizationExp2_entry"] = lambda { |defi|
  s = "{ "
  s << "hVFhandle: #{"0x%016x" % defi["hVFhandle"]}"
  s << ', '
  s << "pCount: #{"0x%016x" % defi["pCount"]}"
  s << ', '
  s << "pEngineUtil: #{"0x%016x" % defi["pEngineUtil"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesVFManagementGetVFEngineUtilizationExp2_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesVFManagementGetVFCapabilitiesExp2_entry"] = lambda { |defi|
  s = "{ "
  s << "hVFhandle: #{"0x%016x" % defi["hVFhandle"]}"
  s << ', '
  s << "pCapability: #{"0x%016x" % defi["pCapability"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesVFManagementGetVFCapabilitiesExp2_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetGlobalProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetGlobalProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetDeviceProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetDeviceProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetDeviceExpProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetDeviceExpProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetDriverProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetDriverProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetDriverExpProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetDriverExpProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetOverclockProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetOverclockProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetSchedulerProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetSchedulerProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetPerformanceFactorProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetPerformanceFactorProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetPowerProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetPowerProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetFrequencyProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetFrequencyProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetEngineProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetEngineProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetStandbyProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetStandbyProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetFirmwareProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetFirmwareProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetFirmwareExpProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetFirmwareExpProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetMemoryProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetMemoryProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetFabricPortProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetFabricPortProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetTemperatureProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetTemperatureProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetPsuProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetPsuProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetFanProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetFanProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetLedProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetLedProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetRasProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetRasProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetRasExpProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetRasExpProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetDiagnosticsProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetDiagnosticsProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetVFManagementExpProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zes:zesGetVFManagementExpProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "phTracer: #{"0x%016x" % defi["phTracer"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].size > 0 ? ZE::ZELTracerDesc.new(FFI::MemoryPointer.from_string(defi["desc_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDestroy_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDestroy_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerSetPrologues_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "pCoreCbs: #{"0x%016x" % defi["pCoreCbs"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerSetPrologues_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerSetEpilogues_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "pCoreCbs: #{"0x%016x" % defi["pCoreCbs"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerSetEpilogues_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerSetEnabled_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "enable: #{defi["enable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerSetEnabled_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelGetTracerApiProcAddrTable_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{ZE::ZEApiVersion.from_native(defi["version"], nil)}"
  s << ', '
  s << "pDdiTable: #{"0x%016x" % defi["pDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelGetTracerApiProcAddrTable_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerInitRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnInitCb: #{"0x%016x" % defi["pfnInitCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerInitRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDriverGetRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetCb: #{"0x%016x" % defi["pfnGetCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDriverGetRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerInitDriversRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnInitDriversCb: #{"0x%016x" % defi["pfnInitDriversCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerInitDriversRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDriverGetApiVersionRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetApiVersionCb: #{"0x%016x" % defi["pfnGetApiVersionCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDriverGetApiVersionRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDriverGetPropertiesRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetPropertiesCb: #{"0x%016x" % defi["pfnGetPropertiesCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDriverGetPropertiesRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDriverGetIpcPropertiesRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetIpcPropertiesCb: #{"0x%016x" % defi["pfnGetIpcPropertiesCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDriverGetIpcPropertiesRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDriverGetExtensionPropertiesRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetExtensionPropertiesCb: #{"0x%016x" % defi["pfnGetExtensionPropertiesCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDriverGetExtensionPropertiesRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDriverGetExtensionFunctionAddressRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetExtensionFunctionAddressCb: #{"0x%016x" % defi["pfnGetExtensionFunctionAddressCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDriverGetExtensionFunctionAddressRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDriverGetLastErrorDescriptionRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetLastErrorDescriptionCb: #{"0x%016x" % defi["pfnGetLastErrorDescriptionCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDriverGetLastErrorDescriptionRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceGetRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetCb: #{"0x%016x" % defi["pfnGetCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceGetRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceGetRootDeviceRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetRootDeviceCb: #{"0x%016x" % defi["pfnGetRootDeviceCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceGetRootDeviceRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceGetSubDevicesRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetSubDevicesCb: #{"0x%016x" % defi["pfnGetSubDevicesCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceGetSubDevicesRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceGetPropertiesRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetPropertiesCb: #{"0x%016x" % defi["pfnGetPropertiesCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceGetPropertiesRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceGetComputePropertiesRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetComputePropertiesCb: #{"0x%016x" % defi["pfnGetComputePropertiesCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceGetComputePropertiesRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceGetModulePropertiesRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetModulePropertiesCb: #{"0x%016x" % defi["pfnGetModulePropertiesCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceGetModulePropertiesRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceGetCommandQueueGroupPropertiesRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetCommandQueueGroupPropertiesCb: #{"0x%016x" % defi["pfnGetCommandQueueGroupPropertiesCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceGetCommandQueueGroupPropertiesRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceGetMemoryPropertiesRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetMemoryPropertiesCb: #{"0x%016x" % defi["pfnGetMemoryPropertiesCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceGetMemoryPropertiesRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceGetMemoryAccessPropertiesRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetMemoryAccessPropertiesCb: #{"0x%016x" % defi["pfnGetMemoryAccessPropertiesCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceGetMemoryAccessPropertiesRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceGetCachePropertiesRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetCachePropertiesCb: #{"0x%016x" % defi["pfnGetCachePropertiesCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceGetCachePropertiesRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceGetImagePropertiesRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetImagePropertiesCb: #{"0x%016x" % defi["pfnGetImagePropertiesCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceGetImagePropertiesRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceGetExternalMemoryPropertiesRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetExternalMemoryPropertiesCb: #{"0x%016x" % defi["pfnGetExternalMemoryPropertiesCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceGetExternalMemoryPropertiesRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceGetP2PPropertiesRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetP2PPropertiesCb: #{"0x%016x" % defi["pfnGetP2PPropertiesCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceGetP2PPropertiesRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceCanAccessPeerRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnCanAccessPeerCb: #{"0x%016x" % defi["pfnCanAccessPeerCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceCanAccessPeerRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceGetStatusRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetStatusCb: #{"0x%016x" % defi["pfnGetStatusCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceGetStatusRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceGetGlobalTimestampsRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetGlobalTimestampsCb: #{"0x%016x" % defi["pfnGetGlobalTimestampsCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceGetGlobalTimestampsRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerContextCreateRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnCreateCb: #{"0x%016x" % defi["pfnCreateCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerContextCreateRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerContextCreateExRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnCreateExCb: #{"0x%016x" % defi["pfnCreateExCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerContextCreateExRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerContextDestroyRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnDestroyCb: #{"0x%016x" % defi["pfnDestroyCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerContextDestroyRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerContextGetStatusRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetStatusCb: #{"0x%016x" % defi["pfnGetStatusCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerContextGetStatusRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandQueueCreateRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnCreateCb: #{"0x%016x" % defi["pfnCreateCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandQueueCreateRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandQueueDestroyRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnDestroyCb: #{"0x%016x" % defi["pfnDestroyCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandQueueDestroyRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandQueueExecuteCommandListsRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnExecuteCommandListsCb: #{"0x%016x" % defi["pfnExecuteCommandListsCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandQueueExecuteCommandListsRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandQueueSynchronizeRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnSynchronizeCb: #{"0x%016x" % defi["pfnSynchronizeCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandQueueSynchronizeRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandQueueGetOrdinalRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetOrdinalCb: #{"0x%016x" % defi["pfnGetOrdinalCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandQueueGetOrdinalRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandQueueGetIndexRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetIndexCb: #{"0x%016x" % defi["pfnGetIndexCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandQueueGetIndexRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListCreateRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnCreateCb: #{"0x%016x" % defi["pfnCreateCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListCreateRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListCreateImmediateRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnCreateImmediateCb: #{"0x%016x" % defi["pfnCreateImmediateCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListCreateImmediateRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListDestroyRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnDestroyCb: #{"0x%016x" % defi["pfnDestroyCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListDestroyRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListCloseRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnCloseCb: #{"0x%016x" % defi["pfnCloseCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListCloseRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListResetRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnResetCb: #{"0x%016x" % defi["pfnResetCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListResetRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendWriteGlobalTimestampRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnAppendWriteGlobalTimestampCb: #{"0x%016x" % defi["pfnAppendWriteGlobalTimestampCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendWriteGlobalTimestampRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListHostSynchronizeRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnHostSynchronizeCb: #{"0x%016x" % defi["pfnHostSynchronizeCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListHostSynchronizeRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListGetDeviceHandleRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetDeviceHandleCb: #{"0x%016x" % defi["pfnGetDeviceHandleCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListGetDeviceHandleRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListGetContextHandleRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetContextHandleCb: #{"0x%016x" % defi["pfnGetContextHandleCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListGetContextHandleRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListGetOrdinalRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetOrdinalCb: #{"0x%016x" % defi["pfnGetOrdinalCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListGetOrdinalRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListImmediateGetIndexRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnImmediateGetIndexCb: #{"0x%016x" % defi["pfnImmediateGetIndexCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListImmediateGetIndexRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListIsImmediateRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnIsImmediateCb: #{"0x%016x" % defi["pfnIsImmediateCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListIsImmediateRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendBarrierRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnAppendBarrierCb: #{"0x%016x" % defi["pfnAppendBarrierCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendBarrierRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendMemoryRangesBarrierRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnAppendMemoryRangesBarrierCb: #{"0x%016x" % defi["pfnAppendMemoryRangesBarrierCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendMemoryRangesBarrierRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerContextSystemBarrierRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnSystemBarrierCb: #{"0x%016x" % defi["pfnSystemBarrierCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerContextSystemBarrierRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendMemoryCopyRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnAppendMemoryCopyCb: #{"0x%016x" % defi["pfnAppendMemoryCopyCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendMemoryCopyRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendMemoryFillRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnAppendMemoryFillCb: #{"0x%016x" % defi["pfnAppendMemoryFillCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendMemoryFillRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendMemoryCopyRegionRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnAppendMemoryCopyRegionCb: #{"0x%016x" % defi["pfnAppendMemoryCopyRegionCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendMemoryCopyRegionRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendMemoryCopyFromContextRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnAppendMemoryCopyFromContextCb: #{"0x%016x" % defi["pfnAppendMemoryCopyFromContextCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendMemoryCopyFromContextRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendImageCopyRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnAppendImageCopyCb: #{"0x%016x" % defi["pfnAppendImageCopyCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendImageCopyRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendImageCopyRegionRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnAppendImageCopyRegionCb: #{"0x%016x" % defi["pfnAppendImageCopyRegionCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendImageCopyRegionRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendImageCopyToMemoryRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnAppendImageCopyToMemoryCb: #{"0x%016x" % defi["pfnAppendImageCopyToMemoryCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendImageCopyToMemoryRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendImageCopyFromMemoryRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnAppendImageCopyFromMemoryCb: #{"0x%016x" % defi["pfnAppendImageCopyFromMemoryCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendImageCopyFromMemoryRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendMemoryPrefetchRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnAppendMemoryPrefetchCb: #{"0x%016x" % defi["pfnAppendMemoryPrefetchCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendMemoryPrefetchRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendMemAdviseRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnAppendMemAdviseCb: #{"0x%016x" % defi["pfnAppendMemAdviseCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendMemAdviseRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventPoolCreateRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnCreateCb: #{"0x%016x" % defi["pfnCreateCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventPoolCreateRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventPoolDestroyRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnDestroyCb: #{"0x%016x" % defi["pfnDestroyCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventPoolDestroyRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventCreateRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnCreateCb: #{"0x%016x" % defi["pfnCreateCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventCreateRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventDestroyRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnDestroyCb: #{"0x%016x" % defi["pfnDestroyCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventDestroyRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventPoolGetIpcHandleRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetIpcHandleCb: #{"0x%016x" % defi["pfnGetIpcHandleCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventPoolGetIpcHandleRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventPoolPutIpcHandleRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnPutIpcHandleCb: #{"0x%016x" % defi["pfnPutIpcHandleCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventPoolPutIpcHandleRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventPoolOpenIpcHandleRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnOpenIpcHandleCb: #{"0x%016x" % defi["pfnOpenIpcHandleCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventPoolOpenIpcHandleRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventPoolCloseIpcHandleRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnCloseIpcHandleCb: #{"0x%016x" % defi["pfnCloseIpcHandleCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventPoolCloseIpcHandleRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendSignalEventRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnAppendSignalEventCb: #{"0x%016x" % defi["pfnAppendSignalEventCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendSignalEventRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendWaitOnEventsRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnAppendWaitOnEventsCb: #{"0x%016x" % defi["pfnAppendWaitOnEventsCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendWaitOnEventsRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventHostSignalRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnHostSignalCb: #{"0x%016x" % defi["pfnHostSignalCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventHostSignalRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventHostSynchronizeRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnHostSynchronizeCb: #{"0x%016x" % defi["pfnHostSynchronizeCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventHostSynchronizeRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventQueryStatusRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnQueryStatusCb: #{"0x%016x" % defi["pfnQueryStatusCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventQueryStatusRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendEventResetRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnAppendEventResetCb: #{"0x%016x" % defi["pfnAppendEventResetCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendEventResetRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventHostResetRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnHostResetCb: #{"0x%016x" % defi["pfnHostResetCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventHostResetRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventQueryKernelTimestampRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnQueryKernelTimestampCb: #{"0x%016x" % defi["pfnQueryKernelTimestampCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventQueryKernelTimestampRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendQueryKernelTimestampsRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnAppendQueryKernelTimestampsCb: #{"0x%016x" % defi["pfnAppendQueryKernelTimestampsCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendQueryKernelTimestampsRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventGetEventPoolRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetEventPoolCb: #{"0x%016x" % defi["pfnGetEventPoolCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventGetEventPoolRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventGetSignalScopeRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetSignalScopeCb: #{"0x%016x" % defi["pfnGetSignalScopeCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventGetSignalScopeRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventGetWaitScopeRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetWaitScopeCb: #{"0x%016x" % defi["pfnGetWaitScopeCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventGetWaitScopeRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventPoolGetContextHandleRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetContextHandleCb: #{"0x%016x" % defi["pfnGetContextHandleCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventPoolGetContextHandleRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventPoolGetFlagsRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetFlagsCb: #{"0x%016x" % defi["pfnGetFlagsCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventPoolGetFlagsRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerFenceCreateRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnCreateCb: #{"0x%016x" % defi["pfnCreateCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerFenceCreateRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerFenceDestroyRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnDestroyCb: #{"0x%016x" % defi["pfnDestroyCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerFenceDestroyRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerFenceHostSynchronizeRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnHostSynchronizeCb: #{"0x%016x" % defi["pfnHostSynchronizeCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerFenceHostSynchronizeRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerFenceQueryStatusRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnQueryStatusCb: #{"0x%016x" % defi["pfnQueryStatusCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerFenceQueryStatusRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerFenceResetRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnResetCb: #{"0x%016x" % defi["pfnResetCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerFenceResetRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerImageGetPropertiesRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetPropertiesCb: #{"0x%016x" % defi["pfnGetPropertiesCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerImageGetPropertiesRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerImageCreateRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnCreateCb: #{"0x%016x" % defi["pfnCreateCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerImageCreateRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerImageDestroyRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnDestroyCb: #{"0x%016x" % defi["pfnDestroyCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerImageDestroyRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerMemAllocSharedRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnAllocSharedCb: #{"0x%016x" % defi["pfnAllocSharedCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerMemAllocSharedRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerMemAllocDeviceRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnAllocDeviceCb: #{"0x%016x" % defi["pfnAllocDeviceCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerMemAllocDeviceRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerMemAllocHostRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnAllocHostCb: #{"0x%016x" % defi["pfnAllocHostCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerMemAllocHostRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerMemFreeRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnFreeCb: #{"0x%016x" % defi["pfnFreeCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerMemFreeRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerMemGetAllocPropertiesRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetAllocPropertiesCb: #{"0x%016x" % defi["pfnGetAllocPropertiesCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerMemGetAllocPropertiesRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerMemGetAddressRangeRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetAddressRangeCb: #{"0x%016x" % defi["pfnGetAddressRangeCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerMemGetAddressRangeRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerMemGetIpcHandleRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetIpcHandleCb: #{"0x%016x" % defi["pfnGetIpcHandleCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerMemGetIpcHandleRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerMemGetIpcHandleFromFileDescriptorExpRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetIpcHandleFromFileDescriptorExpCb: #{"0x%016x" % defi["pfnGetIpcHandleFromFileDescriptorExpCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerMemGetIpcHandleFromFileDescriptorExpRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerMemGetFileDescriptorFromIpcHandleExpRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetFileDescriptorFromIpcHandleExpCb: #{"0x%016x" % defi["pfnGetFileDescriptorFromIpcHandleExpCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerMemGetFileDescriptorFromIpcHandleExpRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerMemPutIpcHandleRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnPutIpcHandleCb: #{"0x%016x" % defi["pfnPutIpcHandleCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerMemPutIpcHandleRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerMemOpenIpcHandleRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnOpenIpcHandleCb: #{"0x%016x" % defi["pfnOpenIpcHandleCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerMemOpenIpcHandleRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerMemCloseIpcHandleRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnCloseIpcHandleCb: #{"0x%016x" % defi["pfnCloseIpcHandleCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerMemCloseIpcHandleRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerMemSetAtomicAccessAttributeExpRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnSetAtomicAccessAttributeExpCb: #{"0x%016x" % defi["pfnSetAtomicAccessAttributeExpCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerMemSetAtomicAccessAttributeExpRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerMemGetAtomicAccessAttributeExpRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetAtomicAccessAttributeExpCb: #{"0x%016x" % defi["pfnGetAtomicAccessAttributeExpCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerMemGetAtomicAccessAttributeExpRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerModuleCreateRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnCreateCb: #{"0x%016x" % defi["pfnCreateCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerModuleCreateRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerModuleDestroyRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnDestroyCb: #{"0x%016x" % defi["pfnDestroyCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerModuleDestroyRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerModuleDynamicLinkRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnDynamicLinkCb: #{"0x%016x" % defi["pfnDynamicLinkCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerModuleDynamicLinkRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerModuleBuildLogDestroyRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnDestroyCb: #{"0x%016x" % defi["pfnDestroyCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerModuleBuildLogDestroyRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerModuleBuildLogGetStringRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetStringCb: #{"0x%016x" % defi["pfnGetStringCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerModuleBuildLogGetStringRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerModuleGetNativeBinaryRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetNativeBinaryCb: #{"0x%016x" % defi["pfnGetNativeBinaryCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerModuleGetNativeBinaryRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerModuleGetGlobalPointerRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetGlobalPointerCb: #{"0x%016x" % defi["pfnGetGlobalPointerCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerModuleGetGlobalPointerRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerModuleGetKernelNamesRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetKernelNamesCb: #{"0x%016x" % defi["pfnGetKernelNamesCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerModuleGetKernelNamesRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerModuleGetPropertiesRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetPropertiesCb: #{"0x%016x" % defi["pfnGetPropertiesCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerModuleGetPropertiesRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerKernelCreateRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnCreateCb: #{"0x%016x" % defi["pfnCreateCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerKernelCreateRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerKernelDestroyRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnDestroyCb: #{"0x%016x" % defi["pfnDestroyCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerKernelDestroyRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerModuleGetFunctionPointerRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetFunctionPointerCb: #{"0x%016x" % defi["pfnGetFunctionPointerCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerModuleGetFunctionPointerRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerKernelSetGroupSizeRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnSetGroupSizeCb: #{"0x%016x" % defi["pfnSetGroupSizeCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerKernelSetGroupSizeRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerKernelSuggestGroupSizeRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnSuggestGroupSizeCb: #{"0x%016x" % defi["pfnSuggestGroupSizeCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerKernelSuggestGroupSizeRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerKernelSuggestMaxCooperativeGroupCountRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnSuggestMaxCooperativeGroupCountCb: #{"0x%016x" % defi["pfnSuggestMaxCooperativeGroupCountCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerKernelSuggestMaxCooperativeGroupCountRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerKernelSetArgumentValueRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnSetArgumentValueCb: #{"0x%016x" % defi["pfnSetArgumentValueCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerKernelSetArgumentValueRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerKernelSetIndirectAccessRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnSetIndirectAccessCb: #{"0x%016x" % defi["pfnSetIndirectAccessCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerKernelSetIndirectAccessRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerKernelGetIndirectAccessRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetIndirectAccessCb: #{"0x%016x" % defi["pfnGetIndirectAccessCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerKernelGetIndirectAccessRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerKernelGetSourceAttributesRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetSourceAttributesCb: #{"0x%016x" % defi["pfnGetSourceAttributesCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerKernelGetSourceAttributesRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerKernelSetCacheConfigRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnSetCacheConfigCb: #{"0x%016x" % defi["pfnSetCacheConfigCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerKernelSetCacheConfigRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerKernelGetPropertiesRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetPropertiesCb: #{"0x%016x" % defi["pfnGetPropertiesCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerKernelGetPropertiesRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerKernelGetNameRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetNameCb: #{"0x%016x" % defi["pfnGetNameCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerKernelGetNameRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendLaunchKernelRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnAppendLaunchKernelCb: #{"0x%016x" % defi["pfnAppendLaunchKernelCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendLaunchKernelRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendLaunchCooperativeKernelRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnAppendLaunchCooperativeKernelCb: #{"0x%016x" % defi["pfnAppendLaunchCooperativeKernelCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendLaunchCooperativeKernelRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendLaunchKernelIndirectRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnAppendLaunchKernelIndirectCb: #{"0x%016x" % defi["pfnAppendLaunchKernelIndirectCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendLaunchKernelIndirectRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendLaunchMultipleKernelsIndirectRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnAppendLaunchMultipleKernelsIndirectCb: #{"0x%016x" % defi["pfnAppendLaunchMultipleKernelsIndirectCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendLaunchMultipleKernelsIndirectRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerContextMakeMemoryResidentRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnMakeMemoryResidentCb: #{"0x%016x" % defi["pfnMakeMemoryResidentCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerContextMakeMemoryResidentRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerContextEvictMemoryRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnEvictMemoryCb: #{"0x%016x" % defi["pfnEvictMemoryCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerContextEvictMemoryRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerContextMakeImageResidentRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnMakeImageResidentCb: #{"0x%016x" % defi["pfnMakeImageResidentCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerContextMakeImageResidentRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerContextEvictImageRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnEvictImageCb: #{"0x%016x" % defi["pfnEvictImageCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerContextEvictImageRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerSamplerCreateRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnCreateCb: #{"0x%016x" % defi["pfnCreateCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerSamplerCreateRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerSamplerDestroyRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnDestroyCb: #{"0x%016x" % defi["pfnDestroyCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerSamplerDestroyRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerVirtualMemReserveRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnReserveCb: #{"0x%016x" % defi["pfnReserveCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerVirtualMemReserveRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerVirtualMemFreeRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnFreeCb: #{"0x%016x" % defi["pfnFreeCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerVirtualMemFreeRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerVirtualMemQueryPageSizeRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnQueryPageSizeCb: #{"0x%016x" % defi["pfnQueryPageSizeCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerVirtualMemQueryPageSizeRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerPhysicalMemCreateRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnCreateCb: #{"0x%016x" % defi["pfnCreateCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerPhysicalMemCreateRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerPhysicalMemDestroyRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnDestroyCb: #{"0x%016x" % defi["pfnDestroyCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerPhysicalMemDestroyRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerVirtualMemMapRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnMapCb: #{"0x%016x" % defi["pfnMapCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerVirtualMemMapRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerVirtualMemUnmapRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnUnmapCb: #{"0x%016x" % defi["pfnUnmapCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerVirtualMemUnmapRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerVirtualMemSetAccessAttributeRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnSetAccessAttributeCb: #{"0x%016x" % defi["pfnSetAccessAttributeCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerVirtualMemSetAccessAttributeRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerVirtualMemGetAccessAttributeRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetAccessAttributeCb: #{"0x%016x" % defi["pfnGetAccessAttributeCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerVirtualMemGetAccessAttributeRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerKernelSetGlobalOffsetExpRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnSetGlobalOffsetExpCb: #{"0x%016x" % defi["pfnSetGlobalOffsetExpCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerKernelSetGlobalOffsetExpRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerKernelGetBinaryExpRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetBinaryExpCb: #{"0x%016x" % defi["pfnGetBinaryExpCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerKernelGetBinaryExpRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceImportExternalSemaphoreExtRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnImportExternalSemaphoreExtCb: #{"0x%016x" % defi["pfnImportExternalSemaphoreExtCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceImportExternalSemaphoreExtRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceReleaseExternalSemaphoreExtRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnReleaseExternalSemaphoreExtCb: #{"0x%016x" % defi["pfnReleaseExternalSemaphoreExtCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceReleaseExternalSemaphoreExtRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendSignalExternalSemaphoreExtRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnAppendSignalExternalSemaphoreExtCb: #{"0x%016x" % defi["pfnAppendSignalExternalSemaphoreExtCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendSignalExternalSemaphoreExtRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendWaitExternalSemaphoreExtRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnAppendWaitExternalSemaphoreExtCb: #{"0x%016x" % defi["pfnAppendWaitExternalSemaphoreExtCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendWaitExternalSemaphoreExtRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerRTASBuilderCreateExtRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnCreateExtCb: #{"0x%016x" % defi["pfnCreateExtCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerRTASBuilderCreateExtRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerRTASBuilderGetBuildPropertiesExtRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetBuildPropertiesExtCb: #{"0x%016x" % defi["pfnGetBuildPropertiesExtCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerRTASBuilderGetBuildPropertiesExtRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDriverRTASFormatCompatibilityCheckExtRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnRTASFormatCompatibilityCheckExtCb: #{"0x%016x" % defi["pfnRTASFormatCompatibilityCheckExtCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDriverRTASFormatCompatibilityCheckExtRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerRTASBuilderBuildExtRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnBuildExtCb: #{"0x%016x" % defi["pfnBuildExtCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerRTASBuilderBuildExtRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerRTASBuilderCommandListAppendCopyExtRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnCommandListAppendCopyExtCb: #{"0x%016x" % defi["pfnCommandListAppendCopyExtCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerRTASBuilderCommandListAppendCopyExtRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerRTASBuilderDestroyExtRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnDestroyExtCb: #{"0x%016x" % defi["pfnDestroyExtCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerRTASBuilderDestroyExtRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerRTASParallelOperationCreateExtRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnCreateExtCb: #{"0x%016x" % defi["pfnCreateExtCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerRTASParallelOperationCreateExtRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerRTASParallelOperationGetPropertiesExtRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetPropertiesExtCb: #{"0x%016x" % defi["pfnGetPropertiesExtCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerRTASParallelOperationGetPropertiesExtRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerRTASParallelOperationJoinExtRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnJoinExtCb: #{"0x%016x" % defi["pfnJoinExtCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerRTASParallelOperationJoinExtRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerRTASParallelOperationDestroyExtRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnDestroyExtCb: #{"0x%016x" % defi["pfnDestroyExtCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerRTASParallelOperationDestroyExtRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceGetVectorWidthPropertiesExtRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetVectorWidthPropertiesExtCb: #{"0x%016x" % defi["pfnGetVectorWidthPropertiesExtCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceGetVectorWidthPropertiesExtRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceReserveCacheExtRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnReserveCacheExtCb: #{"0x%016x" % defi["pfnReserveCacheExtCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceReserveCacheExtRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceSetCacheAdviceExtRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnSetCacheAdviceExtCb: #{"0x%016x" % defi["pfnSetCacheAdviceExtCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceSetCacheAdviceExtRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventQueryTimestampsExpRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnQueryTimestampsExpCb: #{"0x%016x" % defi["pfnQueryTimestampsExpCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventQueryTimestampsExpRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerImageGetMemoryPropertiesExpRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetMemoryPropertiesExpCb: #{"0x%016x" % defi["pfnGetMemoryPropertiesExpCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerImageGetMemoryPropertiesExpRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerImageViewCreateExtRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnViewCreateExtCb: #{"0x%016x" % defi["pfnViewCreateExtCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerImageViewCreateExtRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerImageViewCreateExpRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnViewCreateExpCb: #{"0x%016x" % defi["pfnViewCreateExpCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerImageViewCreateExpRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerKernelSchedulingHintExpRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnSchedulingHintExpCb: #{"0x%016x" % defi["pfnSchedulingHintExpCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerKernelSchedulingHintExpRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDevicePciGetPropertiesExtRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnPciGetPropertiesExtCb: #{"0x%016x" % defi["pfnPciGetPropertiesExtCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDevicePciGetPropertiesExtRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendImageCopyToMemoryExtRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnAppendImageCopyToMemoryExtCb: #{"0x%016x" % defi["pfnAppendImageCopyToMemoryExtCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendImageCopyToMemoryExtRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendImageCopyFromMemoryExtRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnAppendImageCopyFromMemoryExtCb: #{"0x%016x" % defi["pfnAppendImageCopyFromMemoryExtCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListAppendImageCopyFromMemoryExtRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerImageGetAllocPropertiesExtRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetAllocPropertiesExtCb: #{"0x%016x" % defi["pfnGetAllocPropertiesExtCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerImageGetAllocPropertiesExtRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerModuleInspectLinkageExtRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnInspectLinkageExtCb: #{"0x%016x" % defi["pfnInspectLinkageExtCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerModuleInspectLinkageExtRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerMemFreeExtRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnFreeExtCb: #{"0x%016x" % defi["pfnFreeExtCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerMemFreeExtRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerFabricVertexGetExpRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetExpCb: #{"0x%016x" % defi["pfnGetExpCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerFabricVertexGetExpRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerFabricVertexGetSubVerticesExpRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetSubVerticesExpCb: #{"0x%016x" % defi["pfnGetSubVerticesExpCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerFabricVertexGetSubVerticesExpRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerFabricVertexGetPropertiesExpRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetPropertiesExpCb: #{"0x%016x" % defi["pfnGetPropertiesExpCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerFabricVertexGetPropertiesExpRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerFabricVertexGetDeviceExpRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetDeviceExpCb: #{"0x%016x" % defi["pfnGetDeviceExpCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerFabricVertexGetDeviceExpRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceGetFabricVertexExpRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetFabricVertexExpCb: #{"0x%016x" % defi["pfnGetFabricVertexExpCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDeviceGetFabricVertexExpRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerFabricEdgeGetExpRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetExpCb: #{"0x%016x" % defi["pfnGetExpCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerFabricEdgeGetExpRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerFabricEdgeGetVerticesExpRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetVerticesExpCb: #{"0x%016x" % defi["pfnGetVerticesExpCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerFabricEdgeGetVerticesExpRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerFabricEdgeGetPropertiesExpRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetPropertiesExpCb: #{"0x%016x" % defi["pfnGetPropertiesExpCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerFabricEdgeGetPropertiesExpRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventQueryKernelTimestampsExtRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnQueryKernelTimestampsExtCb: #{"0x%016x" % defi["pfnQueryKernelTimestampsExtCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerEventQueryKernelTimestampsExtRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerRTASBuilderCreateExpRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnCreateExpCb: #{"0x%016x" % defi["pfnCreateExpCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerRTASBuilderCreateExpRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerRTASBuilderGetBuildPropertiesExpRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetBuildPropertiesExpCb: #{"0x%016x" % defi["pfnGetBuildPropertiesExpCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerRTASBuilderGetBuildPropertiesExpRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDriverRTASFormatCompatibilityCheckExpRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnRTASFormatCompatibilityCheckExpCb: #{"0x%016x" % defi["pfnRTASFormatCompatibilityCheckExpCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerDriverRTASFormatCompatibilityCheckExpRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerRTASBuilderBuildExpRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnBuildExpCb: #{"0x%016x" % defi["pfnBuildExpCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerRTASBuilderBuildExpRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerRTASBuilderDestroyExpRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnDestroyExpCb: #{"0x%016x" % defi["pfnDestroyExpCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerRTASBuilderDestroyExpRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerRTASParallelOperationCreateExpRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnCreateExpCb: #{"0x%016x" % defi["pfnCreateExpCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerRTASParallelOperationCreateExpRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerRTASParallelOperationGetPropertiesExpRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetPropertiesExpCb: #{"0x%016x" % defi["pfnGetPropertiesExpCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerRTASParallelOperationGetPropertiesExpRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerRTASParallelOperationJoinExpRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnJoinExpCb: #{"0x%016x" % defi["pfnJoinExpCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerRTASParallelOperationJoinExpRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerRTASParallelOperationDestroyExpRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnDestroyExpCb: #{"0x%016x" % defi["pfnDestroyExpCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerRTASParallelOperationDestroyExpRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerMemGetPitchFor2dImageRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetPitchFor2dImageCb: #{"0x%016x" % defi["pfnGetPitchFor2dImageCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerMemGetPitchFor2dImageRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerImageGetDeviceOffsetExpRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetDeviceOffsetExpCb: #{"0x%016x" % defi["pfnGetDeviceOffsetExpCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerImageGetDeviceOffsetExpRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListCreateCloneExpRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnCreateCloneExpCb: #{"0x%016x" % defi["pfnCreateCloneExpCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListCreateCloneExpRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListImmediateAppendCommandListsExpRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnImmediateAppendCommandListsExpCb: #{"0x%016x" % defi["pfnImmediateAppendCommandListsExpCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListImmediateAppendCommandListsExpRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListGetNextCommandIdExpRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetNextCommandIdExpCb: #{"0x%016x" % defi["pfnGetNextCommandIdExpCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListGetNextCommandIdExpRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListGetNextCommandIdWithKernelsExpRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnGetNextCommandIdWithKernelsExpCb: #{"0x%016x" % defi["pfnGetNextCommandIdWithKernelsExpCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListGetNextCommandIdWithKernelsExpRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListUpdateMutableCommandsExpRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnUpdateMutableCommandsExpCb: #{"0x%016x" % defi["pfnUpdateMutableCommandsExpCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListUpdateMutableCommandsExpRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListUpdateMutableCommandSignalEventExpRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnUpdateMutableCommandSignalEventExpCb: #{"0x%016x" % defi["pfnUpdateMutableCommandSignalEventExpCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListUpdateMutableCommandSignalEventExpRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListUpdateMutableCommandWaitEventsExpRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnUpdateMutableCommandWaitEventsExpCb: #{"0x%016x" % defi["pfnUpdateMutableCommandWaitEventsExpCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListUpdateMutableCommandWaitEventsExpRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListUpdateMutableCommandKernelsExpRegisterCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "hTracer: #{"0x%016x" % defi["hTracer"]}"
  s << ', '
  s << "callback_type: #{ZE::ZELTracerReg.from_native(defi["callback_type"], nil)}"
  s << ', '
  s << "pfnUpdateMutableCommandKernelsExpCb: #{"0x%016x" % defi["pfnUpdateMutableCommandKernelsExpCb"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelTracerCommandListUpdateMutableCommandKernelsExpRegisterCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelLoaderGetVersions_entry"] = lambda { |defi|
  s = "{ "
  s << "num_elems: #{"0x%016x" % defi["num_elems"]}"
  s << ', '
  s << "versions: #{"0x%016x" % defi["versions"]}"
  s << ', '
  s << "num_elems_val: #{defi["num_elems_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelLoaderGetVersions_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "num_elems_val: #{defi["num_elems_val"]}"
  s << ', '
  s << "versions_vals: [ #{p = FFI::MemoryPointer.from_string(defi["versions_vals"]); sz = ZE::ZELComponentVersion.size; n = p.size / sz; (0...n).collect { |i| ZE::ZELComponentVersion.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelLoaderTranslateHandle_entry"] = lambda { |defi|
  s = "{ "
  s << "handleType: #{ZE::ZELHandleType.from_native(defi["handleType"], nil)}"
  s << ', '
  s << "handleIn: #{"0x%016x" % defi["handleIn"]}"
  s << ', '
  s << "handleOut: #{"0x%016x" % defi["handleOut"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelLoaderTranslateHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "handleOut_val: #{"0x%016x" % defi["handleOut_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelSetDriverTeardown_entry"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelSetDriverTeardown_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelSetDelayLoaderContextTeardown_entry"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelSetDelayLoaderContextTeardown_exit"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelLoaderContextTeardown_entry"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelLoaderContextTeardown_exit"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelEnableTracingLayer_entry"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelEnableTracingLayer_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelCheckIsLoaderInTearDown_entry"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelCheckIsLoaderInTearDown_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{defi["zeResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelRegisterTeardownCallback_entry"] = lambda { |defi|
  s = "{ "
  s << "application_callback: #{"0x%016x" % defi["application_callback"]}"
  s << ', '
  s << "loader_callback: #{"0x%016x" % defi["loader_callback"]}"
  s << ', '
  s << "index: #{"0x%016x" % defi["index"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelRegisterTeardownCallback_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelDisableTracingLayer_entry"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelDisableTracingLayer_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelLoaderDriverCheck_entry"] = lambda { |defi|
  s = "{ "
  s << "flags: [ #{ZE::ZEInitFlags.from_native(defi["flags"], nil).join(", ")} ]"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "globalInitStored: #{"0x%016x" % defi["globalInitStored"]}"
  s << ', '
  s << "sysmanGlobalInitStored: #{"0x%016x" % defi["sysmanGlobalInitStored"]}"
  s << ', '
  s << "requireDdiReinit: #{"0x%016x" % defi["requireDdiReinit"]}"
  s << ', '
  s << "sysmanOnly: #{defi["sysmanOnly"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelLoaderDriverCheck_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelLoaderTracingLayerInit_entry"] = lambda { |defi|
  s = "{ "
  s << "zeDdiTable: #{"0x%016x" % defi["zeDdiTable"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelLoaderTracingLayerInit_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zeLoaderGetTracingHandle_entry"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_zel:zeLoaderGetTracingHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{"0x%016x" % defi["zeResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelLoaderGetContext_entry"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelLoaderGetContext_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{"0x%016x" % defi["zeResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelLoaderGetVersionsInternal_entry"] = lambda { |defi|
  s = "{ "
  s << "num_elems: #{"0x%016x" % defi["num_elems"]}"
  s << ', '
  s << "versions: #{"0x%016x" % defi["versions"]}"
  s << ', '
  s << "num_elems_val: #{defi["num_elems_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelLoaderGetVersionsInternal_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "num_elems_val: #{defi["num_elems_val"]}"
  s << ', '
  s << "versions_vals: [ #{p = FFI::MemoryPointer.from_string(defi["versions_vals"]); sz = ZE::ZELComponentVersion.size; n = p.size / sz; (0...n).collect { |i| ZE::ZELComponentVersion.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelLoaderTranslateHandleInternal_entry"] = lambda { |defi|
  s = "{ "
  s << "handleType: #{ZE::ZELHandleType.from_native(defi["handleType"], nil)}"
  s << ', '
  s << "handleIn: #{"0x%016x" % defi["handleIn"]}"
  s << ', '
  s << "handleOut: #{"0x%016x" % defi["handleOut"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zel:zelLoaderTranslateHandleInternal_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "handleOut_val: #{"0x%016x" % defi["handleOut_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zex:zexKernelGetBaseAddress_entry"] = lambda { |defi|
  s = "{ "
  s << "hKernel: #{"0x%016x" % defi["hKernel"]}"
  s << ', '
  s << "baseAddress: #{"0x%016x" % defi["baseAddress"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zex:zexKernelGetBaseAddress_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zex:zexKernelGetArgumentSize_entry"] = lambda { |defi|
  s = "{ "
  s << "hKernel: #{"0x%016x" % defi["hKernel"]}"
  s << ', '
  s << "argIndex: #{defi["argIndex"]}"
  s << ', '
  s << "pArgSize: #{"0x%016x" % defi["pArgSize"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zex:zexKernelGetArgumentSize_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zex:zexKernelGetArgumentType_entry"] = lambda { |defi|
  s = "{ "
  s << "hKernel: #{"0x%016x" % defi["hKernel"]}"
  s << ', '
  s << "argIndex: #{defi["argIndex"]}"
  s << ', '
  s << "pSize: #{"0x%016x" % defi["pSize"]}"
  s << ', '
  s << "pString: #{"0x%016x" % defi["pString"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zex:zexKernelGetArgumentType_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zex:zexDriverImportExternalPointer_entry"] = lambda { |defi|
  s = "{ "
  s << "hDriver: #{"0x%016x" % defi["hDriver"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zex:zexDriverImportExternalPointer_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zex:zexDriverReleaseImportedPointer_entry"] = lambda { |defi|
  s = "{ "
  s << "hDriver: #{"0x%016x" % defi["hDriver"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zex:zexDriverReleaseImportedPointer_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zex:zexDriverGetHostPointerBaseAddress_entry"] = lambda { |defi|
  s = "{ "
  s << "hDriver: #{"0x%016x" % defi["hDriver"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "baseAddress: #{"0x%016x" % defi["baseAddress"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zex:zexDriverGetHostPointerBaseAddress_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zex:zexMemGetIpcHandles_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "numIpcHandles: #{"0x%016x" % defi["numIpcHandles"]}"
  s << ', '
  s << "pIpcHandles: #{"0x%016x" % defi["pIpcHandles"]}"
  s << ', '
  s << "numIpcHandles_val: #{defi["numIpcHandles_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zex:zexMemGetIpcHandles_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "numIpcHandles_val: #{defi["numIpcHandles_val"]}"
  s << ', '
  s << "pIpcHandles_vals: [ #{p = FFI::MemoryPointer.from_string(defi["pIpcHandles_vals"]); sz = ZE::ZEIpcMemHandle.size; n = p.size / sz; (0...n).collect { |i| ZE::ZEIpcMemHandle.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zex:zexMemOpenIpcHandles_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "numIpcHandles: #{defi["numIpcHandles"]}"
  s << ', '
  s << "pIpcHandles: #{"0x%016x" % defi["pIpcHandles"]}"
  s << ', '
  s << "flags: [ #{ZE::ZEIpcMemoryFlags.from_native(defi["flags"], nil).join(", ")} ]"
  s << ', '
  s << "pptr: #{"0x%016x" % defi["pptr"]}"
  s << ', '
  s << "pIpcHandles_vals: [ #{p = FFI::MemoryPointer.from_string(defi["pIpcHandles_vals"]); sz = ZE::ZEIpcMemHandle.size; n = p.size / sz; (0...n).collect { |i| ZE::ZEIpcMemHandle.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_zex:zexMemOpenIpcHandles_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << ', '
  s << "pptr_val: #{"0x%016x" % defi["pptr_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zex:zexCommandListAppendWaitOnMemory_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "data: #{defi["data"]}"
  s << ', '
  s << "hSignalEvent: #{"0x%016x" % defi["hSignalEvent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zex:zexCommandListAppendWaitOnMemory_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zex:zexCommandListAppendWriteToMemory_entry"] = lambda { |defi|
  s = "{ "
  s << "hCommandList: #{"0x%016x" % defi["hCommandList"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "data: #{defi["data"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zex:zexCommandListAppendWriteToMemory_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zex:zexEventGetDeviceAddress_entry"] = lambda { |defi|
  s = "{ "
  s << "event: #{"0x%016x" % defi["event"]}"
  s << ', '
  s << "completionValue: #{"0x%016x" % defi["completionValue"]}"
  s << ', '
  s << "address: #{"0x%016x" % defi["address"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zex:zexEventGetDeviceAddress_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zex:zexCounterBasedEventCreate_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "deviceAddress: #{"0x%016x" % defi["deviceAddress"]}"
  s << ', '
  s << "hostAddress: #{"0x%016x" % defi["hostAddress"]}"
  s << ', '
  s << "completionValue: #{defi["completionValue"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "phEvent: #{"0x%016x" % defi["phEvent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zex:zexCounterBasedEventCreate_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zex:zexCounterBasedEventGetIpcHandle_entry"] = lambda { |defi|
  s = "{ "
  s << "hEvent: #{"0x%016x" % defi["hEvent"]}"
  s << ', '
  s << "phIpc: #{"0x%016x" % defi["phIpc"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zex:zexCounterBasedEventGetIpcHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zex:zexCounterBasedEventCloseIpcHandle_entry"] = lambda { |defi|
  s = "{ "
  s << "hEvent: #{"0x%016x" % defi["hEvent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zex:zexCounterBasedEventCloseIpcHandle_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zex:zexIntelAllocateNetworkInterrupt_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "networkInterruptId: #{"0x%016x" % defi["networkInterruptId"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zex:zexIntelAllocateNetworkInterrupt_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_zex:zexIntelReleaseNetworkInterrupt_entry"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "networkInterruptId: #{defi["networkInterruptId"]}"
  s << " }"
}
$event_lambdas["lttng_ust_zex:zexIntelReleaseNetworkInterrupt_exit"] = lambda { |defi|
  s = "{ "
  s << "zeResult: #{ZE::ZEResult.from_native(defi["zeResult"], nil)}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_sampling:deviceProperties"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "deviceIdx: #{defi["deviceIdx"]}"
  s << ', '
  s << "pDeviceProperties_val: #{defi["pDeviceProperties_val"].size > 0 ? ZE::ZESDeviceProperties.new(FFI::MemoryPointer.from_string(defi["pDeviceProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_sampling:engineProperties"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "hEngines: #{"0x%016x" % defi["hEngines"]}"
  s << ', '
  s << "pEngineProperties_val: #{defi["pEngineProperties_val"].size > 0 ? ZE::ZESEngineProperties.new(FFI::MemoryPointer.from_string(defi["pEngineProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_sampling:engineStats"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "hEngines: #{"0x%016x" % defi["hEngines"]}"
  s << ', '
  s << "pEngineStats_val: #{defi["pEngineStats_val"].size > 0 ? ZE::ZESEngineStats.new(FFI::MemoryPointer.from_string(defi["pEngineStats_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_sampling:powerProperties"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "hPowers: #{"0x%016x" % defi["hPowers"]}"
  s << ', '
  s << "pPowerProperties_val: #{defi["pPowerProperties_val"].size > 0 ? ZE::ZESPowerProperties.new(FFI::MemoryPointer.from_string(defi["pPowerProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_sampling:gpu_energy"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "hPowers: #{"0x%016x" % defi["hPowers"]}"
  s << ', '
  s << "domainIdx: #{defi["domainIdx"]}"
  s << ', '
  s << "pEnergyCounter_val: #{defi["pEnergyCounter_val"].size > 0 ? ZE::ZESPowerEnergyCounter.new(FFI::MemoryPointer.from_string(defi["pEnergyCounter_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_sampling:freqProperties"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "hFrequency: #{"0x%016x" % defi["hFrequency"]}"
  s << ', '
  s << "pFreqProperties_val: #{defi["pFreqProperties_val"].size > 0 ? ZE::ZESFreqProperties.new(FFI::MemoryPointer.from_string(defi["pFreqProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_sampling:gpu_frequency"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "hFrequency: #{"0x%016x" % defi["hFrequency"]}"
  s << ', '
  s << "domainIdx: #{defi["domainIdx"]}"
  s << ', '
  s << "pFreqState_val: #{defi["pFreqState_val"].size > 0 ? ZE::ZESFreqState.new(FFI::MemoryPointer.from_string(defi["pFreqState_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_sampling:fabricPortProperties"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "hFabricPort: #{"0x%016x" % defi["hFabricPort"]}"
  s << ', '
  s << "pFabricPortProperties_val: #{defi["pFabricPortProperties_val"].size > 0 ? ZE::ZESFabricPortProperties.new(FFI::MemoryPointer.from_string(defi["pFabricPortProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_sampling:fabricPort"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "hFabricPort: #{"0x%016x" % defi["hFabricPort"]}"
  s << ', '
  s << "pFabricPortState_val: #{defi["pFabricPortState_val"].size > 0 ? ZE::ZESFabricPortState.new(FFI::MemoryPointer.from_string(defi["pFabricPortState_val"])) : nil}"
  s << ', '
  s << "pFabricPortThroughput_val: #{defi["pFabricPortThroughput_val"].size > 0 ? ZE::ZESFabricPortThroughput.new(FFI::MemoryPointer.from_string(defi["pFabricPortThroughput_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_sampling:memoryProperties"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "hMemModule: #{"0x%016x" % defi["hMemModule"]}"
  s << ', '
  s << "pMemModuleProperties_val: #{defi["pMemModuleProperties_val"].size > 0 ? ZE::ZESMemProperties.new(FFI::MemoryPointer.from_string(defi["pMemModuleProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_sampling:memStats"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "hMemModule: #{"0x%016x" % defi["hMemModule"]}"
  s << ', '
  s << "pMemState_val: #{defi["pMemState_val"].size > 0 ? ZE::ZESMemState.new(FFI::MemoryPointer.from_string(defi["pMemState_val"])) : nil}"
  s << ', '
  s << "pMemBandwidth_val: #{defi["pMemBandwidth_val"].size > 0 ? ZE::ZESMemBandwidth.new(FFI::MemoryPointer.from_string(defi["pMemBandwidth_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_profiling:event_profiling"] = lambda { |defi|
  s = "{ "
  s << "hEvent: #{"0x%016x" % defi["hEvent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_profiling:event_profiling_results"] = lambda { |defi|
  s = "{ "
  s << "hEvent: #{"0x%016x" % defi["hEvent"]}"
  s << ', '
  s << "status: #{ZE::ZEResult.from_native(defi["status"], nil)}"
  s << ', '
  s << "timestampStatus: #{ZE::ZEResult.from_native(defi["timestampStatus"], nil)}"
  s << ', '
  s << "globalStart: #{defi["globalStart"]}"
  s << ', '
  s << "globalEnd: #{defi["globalEnd"]}"
  s << ', '
  s << "contextStart: #{defi["contextStart"]}"
  s << ', '
  s << "contextEnd: #{defi["contextEnd"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_properties:driver"] = lambda { |defi|
  s = "{ "
  s << "hDriver: #{"0x%016x" % defi["hDriver"]}"
  s << ', '
  s << "pDriverProperties_val: #{defi["pDriverProperties_val"].size > 0 ? ZE::ZEDriverProperties.new(FFI::MemoryPointer.from_string(defi["pDriverProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_properties:device"] = lambda { |defi|
  s = "{ "
  s << "hDriver: #{"0x%016x" % defi["hDriver"]}"
  s << ', '
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pDeviceProperties_val: #{defi["pDeviceProperties_val"].size > 0 ? ZE::ZEDeviceProperties.new(FFI::MemoryPointer.from_string(defi["pDeviceProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_properties:subdevice"] = lambda { |defi|
  s = "{ "
  s << "hDriver: #{"0x%016x" % defi["hDriver"]}"
  s << ', '
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "hSubDevice: #{"0x%016x" % defi["hSubDevice"]}"
  s << ', '
  s << "pDeviceProperties_val: #{defi["pDeviceProperties_val"].size > 0 ? ZE::ZEDeviceProperties.new(FFI::MemoryPointer.from_string(defi["pDeviceProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_properties:command_queue_group"] = lambda { |defi|
  s = "{ "
  s << "hDriver: #{"0x%016x" % defi["hDriver"]}"
  s << ', '
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "pCount: #{defi["pCount"]}"
  s << ', '
  s << "pGroupProperties_vals: [ #{p = FFI::MemoryPointer.from_string(defi["pGroupProperties_vals"]); sz = ZE::ZECommandQueueGroupProperties.size; n = p.size / sz; (0...n).collect { |i| ZE::ZECommandQueueGroupProperties.new(p + i*sz).to_s}.join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ze_properties:device_timer"] = lambda { |defi|
  s = "{ "
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << ', '
  s << "hostTimestamp: #{defi["hostTimestamp"]}"
  s << ', '
  s << "deviceTimestamp: #{defi["deviceTimestamp"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_properties:memory_info_properties"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "pMemAllocProperties_val: #{defi["pMemAllocProperties_val"].size > 0 ? ZE::ZEMemoryAllocationProperties.new(FFI::MemoryPointer.from_string(defi["pMemAllocProperties_val"])) : nil}"
  s << ', '
  s << "hDevice: #{"0x%016x" % defi["hDevice"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_properties:memory_info_range"] = lambda { |defi|
  s = "{ "
  s << "hContext: #{"0x%016x" % defi["hContext"]}"
  s << ', '
  s << "ptr: #{"0x%016x" % defi["ptr"]}"
  s << ', '
  s << "base: #{"0x%016x" % defi["base"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_properties:kernel"] = lambda { |defi|
  s = "{ "
  s << "hKernel: #{"0x%016x" % defi["hKernel"]}"
  s << ', '
  s << "pKernelProperties_val: #{defi["pKernelProperties_val"].size > 0 ? ZE::ZEKernelProperties.new(FFI::MemoryPointer.from_string(defi["pKernelProperties_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_build:log"] = lambda { |defi|
  s = "{ "
  s << "buildLog: #{defi["buildLog"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_init_driver_type_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEInitDriverTypeDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_driver_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEDriverProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_driver_ipc_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEDriverIpcProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_device_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEDeviceProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_device_compute_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEDeviceComputeProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_device_module_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEDeviceModuleProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_command_queue_group_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZECommandQueueGroupProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_device_memory_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEDeviceMemoryProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_device_memory_access_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEDeviceMemoryAccessProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_device_cache_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEDeviceCacheProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_device_image_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEDeviceImageProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_device_external_memory_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEDeviceExternalMemoryProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_device_p2p_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEDeviceP2PProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_context_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEContextDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_command_queue_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZECommandQueueDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_command_list_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZECommandListDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_event_pool_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEEventPoolDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_event_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEEventDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_fence_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEFenceDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_image_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEImageDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_image_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEImageProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_device_mem_alloc_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEDeviceMemAllocDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_host_mem_alloc_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEHostMemAllocDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_memory_allocation_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEMemoryAllocationProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_external_memory_export_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEExternalMemoryExportDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_external_memory_import_fd_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEExternalMemoryImportFd.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_external_memory_export_fd_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEExternalMemoryExportFd.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_external_memory_import_win32_handle_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEExternalMemoryImportWin32Handle.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_external_memory_export_win32_handle_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEExternalMemoryExportWin32Handle.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_module_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEModuleDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_module_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEModuleProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_kernel_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEKernelDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_kernel_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEKernelProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_kernel_preferred_group_size_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEKernelPreferredGroupSizeProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_module_program_exp_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEModuleProgramExpDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_device_raytracing_ext_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEDeviceRaytracingExtProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_raytracing_mem_alloc_ext_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZERaytracingMemAllocExtDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_sampler_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESamplerDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_physical_mem_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEPhysicalMemDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_float_atomic_ext_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEFloatAtomicExtProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_relaxed_allocation_limits_exp_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZERelaxedAllocationLimitsExpDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_driver_ddi_handles_ext_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEDriverDdiHandlesExtProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_external_semaphore_ext_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEExternalSemaphoreExtDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_external_semaphore_win32_ext_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEExternalSemaphoreWin32ExtDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_external_semaphore_fd_ext_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEExternalSemaphoreFdExtDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_external_semaphore_signal_params_ext_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEExternalSemaphoreSignalParamsExt.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_external_semaphore_wait_params_ext_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEExternalSemaphoreWaitParamsExt.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_device_cache_line_size_ext_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEDeviceCacheLineSizeExt.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_rtas_builder_ext_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZERtasBuilderExtDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_rtas_builder_ext_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZERtasBuilderExtProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_rtas_parallel_operation_ext_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZERtasParallelOperationExtProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_rtas_device_ext_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZERtasDeviceExtProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_rtas_geometry_aabbs_ext_cb_params_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZERtasGeometryAabbsExtCbParams.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_rtas_builder_build_op_ext_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZERtasBuilderBuildOpExtDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_device_vector_width_properties_ext_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEDeviceVectorWidthPropertiesExt.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_cache_reservation_ext_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZECacheReservationExtDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_image_memory_properties_exp_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEImageMemoryPropertiesExp.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_image_view_planar_ext_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEImageViewPlanarExtDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_image_view_planar_exp_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEImageViewPlanarExpDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_scheduling_hint_exp_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESchedulingHintExpProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_scheduling_hint_exp_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESchedulingHintExpDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_context_power_saving_hint_exp_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEContextPowerSavingHintExpDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_eu_count_ext_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEEuCountExt.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_pci_ext_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEPciExtProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_srgb_ext_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESrgbExtDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_image_allocation_ext_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEImageAllocationExtProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_linkage_inspection_ext_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZELinkageInspectionExtDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_memory_compression_hints_ext_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEMemoryCompressionHintsExtDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_driver_memory_free_ext_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEDriverMemoryFreeExtProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_memory_free_ext_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEMemoryFreeExtDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_device_p2p_bandwidth_exp_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEDeviceP2PBandwidthExpProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_copy_bandwidth_exp_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZECopyBandwidthExpProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_device_luid_ext_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEDeviceLuidExtProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_fabric_vertex_exp_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEFabricVertexExpProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_fabric_edge_exp_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEFabricEdgeExpProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_device_memory_ext_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEDeviceMemoryExtProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_device_ip_version_ext_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEDeviceIpVersionExt.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_kernel_max_group_size_properties_ext_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEKernelMaxGroupSizePropertiesExt.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_memory_sub_allocations_exp_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEMemorySubAllocationsExpProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_event_query_kernel_timestamps_ext_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEEventQueryKernelTimestampsExtProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_event_query_kernel_timestamps_results_ext_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEEventQueryKernelTimestampsResultsExtProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_rtas_builder_exp_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZERtasBuilderExpDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_rtas_builder_exp_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZERtasBuilderExpProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_rtas_parallel_operation_exp_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZERtasParallelOperationExpProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_rtas_device_exp_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZERtasDeviceExpProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_rtas_geometry_aabbs_exp_cb_params_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZERtasGeometryAabbsExpCbParams.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_rtas_builder_build_op_exp_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZERtasBuilderBuildOpExpDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_event_pool_counter_based_exp_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEEventPoolCounterBasedExpDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_image_bindless_exp_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEImageBindlessExpDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_image_pitched_exp_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEImagePitchedExpDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_device_pitched_alloc_exp_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEDevicePitchedAllocExpProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_mutable_command_id_exp_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEMutableCommandIdExpDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_mutable_command_list_exp_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEMutableCommandListExpProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_mutable_command_list_exp_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEMutableCommandListExpDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_mutable_commands_exp_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEMutableCommandsExpDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_mutable_kernel_argument_exp_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEMutableKernelArgumentExpDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_mutable_group_count_exp_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEMutableGroupCountExpDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_mutable_group_size_exp_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEMutableGroupSizeExpDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_mutable_global_offset_exp_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEMutableGlobalOffsetExpDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_ze_structs:ze_mutable_graph_argument_exp_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZEMutableGraphArgumentExpDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zet_structs:zet_device_debug_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZETDeviceDebugProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zet_structs:zet_debug_memory_space_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZETDebugMemorySpaceDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zet_structs:zet_debug_regset_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZETDebugRegsetProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zet_structs:zet_metric_group_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZETMetricGroupProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zet_structs:zet_metric_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZETMetricProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zet_structs:zet_metric_streamer_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZETMetricStreamerDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zet_structs:zet_metric_query_pool_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZETMetricQueryPoolDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zet_structs:zet_profile_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZETProfileProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zet_structs:zet_tracer_exp_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZETTracerExpDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zet_structs:zet_metric_tracer_exp_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZETMetricTracerExpDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zet_structs:zet_metric_group_type_exp_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZETMetricGroupTypeExp.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zet_structs:zet_export_dma_buf_exp_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZETExportDmaBufExpProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zet_structs:zet_metric_global_timestamps_resolution_exp_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZETMetricGlobalTimestampsResolutionExp.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zet_structs:zet_metric_calculate_exp_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZETMetricCalculateExpDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zet_structs:zet_metric_programmable_exp_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZETMetricProgrammableExpProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zet_structs:zet_metric_programmable_param_info_exp_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZETMetricProgrammableParamInfoExp.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zet_structs:zet_metric_programmable_param_value_info_exp_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZETMetricProgrammableParamValueInfoExp.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_base_state_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESBaseState.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_device_state_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESDeviceState.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_reset_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESResetProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_device_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESDeviceProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_device_ext_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESDeviceExtProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_process_state_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESProcessState.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_pci_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESPciProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_pci_state_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESPciState.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_pci_bar_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESPciBarProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_pci_bar_properties_1_2_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESPciBarProperties12.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_overclock_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESOverclockProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_diag_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESDiagProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_device_ecc_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESDeviceEccDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_device_ecc_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESDeviceEccProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_engine_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESEngineProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_fabric_port_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESFabricPortProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_fabric_port_config_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESFabricPortConfig.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_fabric_port_state_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESFabricPortState.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_fabric_port_error_counters_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESFabricPortErrorCounters.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_fan_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESFanProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_fan_config_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESFanConfig.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_firmware_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESFirmwareProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_freq_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESFreqProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_freq_state_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESFreqState.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_oc_capabilities_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESOcCapabilities.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_led_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESLedProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_led_state_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESLedState.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_mem_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESMemProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_mem_state_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESMemState.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_perf_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESPerfProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_power_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESPowerProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_psu_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESPsuProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_psu_state_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESPsuState.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_ras_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESRasProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_ras_state_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESRasState.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_ras_config_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESRasConfig.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_sched_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESSchedProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_sched_timeout_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESSchedTimeoutProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_sched_timeslice_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESSchedTimesliceProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_standby_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESStandbyProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_temp_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESTempProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_temp_config_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESTempConfig.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_device_ecc_default_properties_ext_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESDeviceEccDefaultPropertiesExt.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_power_limit_ext_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESPowerLimitExtDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_power_ext_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESPowerExtProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_engine_ext_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESEngineExtProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_mem_page_offline_state_exp_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESMemPageOfflineStateExp.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_mem_bandwidth_counter_bits_exp_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESMemBandwidthCounterBitsExpProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_power_domain_exp_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESPowerDomainExpProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_subdevice_exp_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESSubdeviceExpProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_vf_exp_properties_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESVfExpProperties.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_vf_util_mem_exp_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESVfUtilMemExp.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_vf_util_engine_exp_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESVfUtilEngineExp.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_vf_exp_capabilities_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESVfExpCapabilities.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_vf_exp2_capabilities_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESVfExp2Capabilities.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_vf_util_mem_exp2_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESVfUtilMemExp2.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zes_structs:zes_vf_util_engine_exp2_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZESVfUtilEngineExp2.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_zel_structs:zel_tracer_desc_t"] = lambda { |defi|
  s = "{ "
  s << "p: #{"0x%016x" % defi["p"]}"
  s << ', '
  s << "p_val: #{defi["p_val"].size > 0 ? ZE::ZELTracerDesc.new(FFI::MemoryPointer.from_string(defi["p_val"])) : nil}"
  s << " }"
}
