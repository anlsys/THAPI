
#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER lttng_ust_hip

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "./hip_tracepoints.h"

#if !defined(HIP_TRACEPOINTS_H) || defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define HIP_TRACEPOINTS_H

#include <lttng/tracepoint.h>

#include "lttng/tracepoint_gen.h"
#include <hip.h.include>
TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipCreateChannelDesc_entry,
  TP_ARGS(
    int, x,
    int, y,
    int, z,
    int, w,
    enum hipChannelFormatKind, f
  ),
  TP_FIELDS(
    ctf_integer(int, x, x)
    ctf_integer(int, y, y)
    ctf_integer(int, z, z)
    ctf_integer(int, w, w)
    ctf_integer(enum hipChannelFormatKind, f, f)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipCreateChannelDesc_exit,
  TP_ARGS(
    int, x,
    int, y,
    int, z,
    int, w,
    enum hipChannelFormatKind, f,
    struct hipChannelFormatDesc, hipResult
  ),
  TP_FIELDS(
    ctf_array_text(uint8_t, hipResult, &hipResult, sizeof(struct hipChannelFormatDesc))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  __hipGetPCH_entry,
  TP_ARGS(
    const char **, pch,
    unsigned int *, size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pch, (uintptr_t)(pch))
    ctf_integer_hex(uintptr_t, size, (uintptr_t)(size))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  __hipGetPCH_exit,
  TP_ARGS(
    const char **, pch,
    unsigned int *, size
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipInit_entry,
  TP_ARGS(
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipInit_exit,
  TP_ARGS(
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDriverGetVersion_entry,
  TP_ARGS(
    int *, driverVersion
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, driverVersion, (uintptr_t)(driverVersion))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDriverGetVersion_exit,
  TP_ARGS(
    int *, driverVersion,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(int, driverVersion_val, (driverVersion ? *driverVersion : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipRuntimeGetVersion_entry,
  TP_ARGS(
    int *, runtimeVersion
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, runtimeVersion, (uintptr_t)(runtimeVersion))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipRuntimeGetVersion_exit,
  TP_ARGS(
    int *, runtimeVersion,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(int, runtimeVersion_val, (runtimeVersion ? *runtimeVersion : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceGet_entry,
  TP_ARGS(
    hipDevice_t *, device,
    int, ordinal
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, device, (uintptr_t)(device))
    ctf_integer(int, ordinal, ordinal)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceGet_exit,
  TP_ARGS(
    hipDevice_t *, device,
    int, ordinal,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(hipDevice_t, device_val, (device ? *device : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceComputeCapability_entry,
  TP_ARGS(
    int *, major,
    int *, minor,
    hipDevice_t, device
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, major, (uintptr_t)(major))
    ctf_integer_hex(uintptr_t, minor, (uintptr_t)(minor))
    ctf_integer(hipDevice_t, device, device)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceComputeCapability_exit,
  TP_ARGS(
    int *, major,
    int *, minor,
    hipDevice_t, device,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(int, major_val, (major ? *major : 0))
    ctf_integer(int, minor_val, (minor ? *minor : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceGetName_entry,
  TP_ARGS(
    char *, name,
    int, len,
    hipDevice_t, device
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, name, (uintptr_t)(name))
    ctf_integer(int, len, len)
    ctf_integer(hipDevice_t, device, device)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceGetName_exit,
  TP_ARGS(
    char *, name,
    int, len,
    hipDevice_t, device,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_string(name_val, name)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceGetUuid_entry,
  TP_ARGS(
    hipUUID *, uuid,
    hipDevice_t, device
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, uuid, (uintptr_t)(uuid))
    ctf_integer(hipDevice_t, device, device)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceGetUuid_exit,
  TP_ARGS(
    hipUUID *, uuid,
    hipDevice_t, device,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_sequence_text(uint8_t, uuid_val, uuid, size_t, (uuid ? sizeof(hipUUID) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceGetP2PAttribute_entry,
  TP_ARGS(
    int *, value,
    hipDeviceP2PAttr, attr,
    int, srcDevice,
    int, dstDevice
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, value, (uintptr_t)(value))
    ctf_integer(int32_t, attr, attr)
    ctf_integer(int, srcDevice, srcDevice)
    ctf_integer(int, dstDevice, dstDevice)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceGetP2PAttribute_exit,
  TP_ARGS(
    int *, value,
    hipDeviceP2PAttr, attr,
    int, srcDevice,
    int, dstDevice,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(int, value_val, (value ? *value : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceGetPCIBusId_entry,
  TP_ARGS(
    char *, pciBusId,
    int, len,
    int, device
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pciBusId, (uintptr_t)(pciBusId))
    ctf_integer(int, len, len)
    ctf_integer(int, device, device)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceGetPCIBusId_exit,
  TP_ARGS(
    char *, pciBusId,
    int, len,
    int, device,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_string(pciBusId_val, pciBusId)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceGetByPCIBusId_entry,
  TP_ARGS(
    int *, device,
    const char *, pciBusId
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, device, (uintptr_t)(device))
    ctf_integer_hex(uintptr_t, pciBusId, (uintptr_t)(pciBusId))
    ctf_string(pciBusId_val, pciBusId)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceGetByPCIBusId_exit,
  TP_ARGS(
    int *, device,
    const char *, pciBusId,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(int, device_val, (device ? *device : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceTotalMem_entry,
  TP_ARGS(
    size_t *, bytes,
    hipDevice_t, device
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, bytes, (uintptr_t)(bytes))
    ctf_integer(hipDevice_t, device, device)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceTotalMem_exit,
  TP_ARGS(
    size_t *, bytes,
    hipDevice_t, device,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(size_t, bytes_val, (bytes ? *bytes : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceSynchronize_entry,
  TP_ARGS(
    void
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceSynchronize_exit,
  TP_ARGS(
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceReset_entry,
  TP_ARGS(
    void
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceReset_exit,
  TP_ARGS(
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipSetDevice_entry,
  TP_ARGS(
    int, deviceId
  ),
  TP_FIELDS(
    ctf_integer(int, deviceId, deviceId)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipSetDevice_exit,
  TP_ARGS(
    int, deviceId,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGetDevice_entry,
  TP_ARGS(
    int *, deviceId
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, deviceId, (uintptr_t)(deviceId))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGetDevice_exit,
  TP_ARGS(
    int *, deviceId,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(int, deviceId_val, (deviceId ? *deviceId : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGetDeviceCount_entry,
  TP_ARGS(
    int *, count
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, count, (uintptr_t)(count))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGetDeviceCount_exit,
  TP_ARGS(
    int *, count,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(int, count_val, (count ? *count : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceGetAttribute_entry,
  TP_ARGS(
    int *, pi,
    hipDeviceAttribute_t, attr,
    int, deviceId
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pi, (uintptr_t)(pi))
    ctf_integer(int32_t, attr, attr)
    ctf_integer(int, deviceId, deviceId)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceGetAttribute_exit,
  TP_ARGS(
    int *, pi,
    hipDeviceAttribute_t, attr,
    int, deviceId,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(int, pi_val, (pi ? *pi : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceGetDefaultMemPool_entry,
  TP_ARGS(
    hipMemPool_t *, mem_pool,
    int, device
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mem_pool, (uintptr_t)(mem_pool))
    ctf_integer(int, device, device)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceGetDefaultMemPool_exit,
  TP_ARGS(
    hipMemPool_t *, mem_pool,
    int, device,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, mem_pool_val, (uintptr_t)((mem_pool ? *mem_pool : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceSetMemPool_entry,
  TP_ARGS(
    int, device,
    hipMemPool_t, mem_pool
  ),
  TP_FIELDS(
    ctf_integer(int, device, device)
    ctf_integer_hex(uintptr_t, mem_pool, (uintptr_t)(mem_pool))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceSetMemPool_exit,
  TP_ARGS(
    int, device,
    hipMemPool_t, mem_pool,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceGetMemPool_entry,
  TP_ARGS(
    hipMemPool_t *, mem_pool,
    int, device
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mem_pool, (uintptr_t)(mem_pool))
    ctf_integer(int, device, device)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceGetMemPool_exit,
  TP_ARGS(
    hipMemPool_t *, mem_pool,
    int, device,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, mem_pool_val, (uintptr_t)((mem_pool ? *mem_pool : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGetDeviceProperties_entry,
  TP_ARGS(
    hipDeviceProp_t *, prop,
    int, deviceId
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, prop, (uintptr_t)(prop))
    ctf_integer(int, deviceId, deviceId)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGetDeviceProperties_exit,
  TP_ARGS(
    hipDeviceProp_t *, prop,
    int, deviceId,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_sequence_text(uint8_t, prop_val, prop, size_t, (prop ? sizeof(hipDeviceProp_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceSetCacheConfig_entry,
  TP_ARGS(
    hipFuncCache_t, cacheConfig
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cacheConfig, cacheConfig)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceSetCacheConfig_exit,
  TP_ARGS(
    hipFuncCache_t, cacheConfig,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceGetCacheConfig_entry,
  TP_ARGS(
    hipFuncCache_t *, cacheConfig
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, cacheConfig, (uintptr_t)(cacheConfig))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceGetCacheConfig_exit,
  TP_ARGS(
    hipFuncCache_t *, cacheConfig,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(int32_t, cacheConfig_val, (cacheConfig ? *cacheConfig : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceGetLimit_entry,
  TP_ARGS(
    size_t *, pValue,
    enum hipLimit_t, limit
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pValue, (uintptr_t)(pValue))
    ctf_integer(enum hipLimit_t, limit, limit)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceGetLimit_exit,
  TP_ARGS(
    size_t *, pValue,
    enum hipLimit_t, limit,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(size_t, pValue_val, (pValue ? *pValue : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceSetLimit_entry,
  TP_ARGS(
    enum hipLimit_t, limit,
    size_t, value
  ),
  TP_FIELDS(
    ctf_integer(enum hipLimit_t, limit, limit)
    ctf_integer(size_t, value, value)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceSetLimit_exit,
  TP_ARGS(
    enum hipLimit_t, limit,
    size_t, value,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceGetSharedMemConfig_entry,
  TP_ARGS(
    hipSharedMemConfig *, pConfig
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pConfig, (uintptr_t)(pConfig))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceGetSharedMemConfig_exit,
  TP_ARGS(
    hipSharedMemConfig *, pConfig,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(int32_t, pConfig_val, (pConfig ? *pConfig : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGetDeviceFlags_entry,
  TP_ARGS(
    unsigned int *, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, flags, (uintptr_t)(flags))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGetDeviceFlags_exit,
  TP_ARGS(
    unsigned int *, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(unsigned int, flags_val, (flags ? *flags : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceSetSharedMemConfig_entry,
  TP_ARGS(
    hipSharedMemConfig, config
  ),
  TP_FIELDS(
    ctf_integer(int32_t, config, config)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceSetSharedMemConfig_exit,
  TP_ARGS(
    hipSharedMemConfig, config,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipSetDeviceFlags_entry,
  TP_ARGS(
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipSetDeviceFlags_exit,
  TP_ARGS(
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipChooseDevice_entry,
  TP_ARGS(
    int *, device,
    const hipDeviceProp_t *, prop
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, device, (uintptr_t)(device))
    ctf_integer_hex(uintptr_t, prop, (uintptr_t)(prop))
    ctf_sequence_text(uint8_t, prop_val, prop, size_t, (prop ? sizeof(hipDeviceProp_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipChooseDevice_exit,
  TP_ARGS(
    int *, device,
    const hipDeviceProp_t *, prop,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(int, device_val, (device ? *device : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipExtGetLinkTypeAndHopCount_entry,
  TP_ARGS(
    int, device1,
    int, device2,
    uint32_t *, linktype,
    uint32_t *, hopcount
  ),
  TP_FIELDS(
    ctf_integer(int, device1, device1)
    ctf_integer(int, device2, device2)
    ctf_integer_hex(uintptr_t, linktype, (uintptr_t)(linktype))
    ctf_integer_hex(uintptr_t, hopcount, (uintptr_t)(hopcount))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipExtGetLinkTypeAndHopCount_exit,
  TP_ARGS(
    int, device1,
    int, device2,
    uint32_t *, linktype,
    uint32_t *, hopcount,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(uint32_t, linktype_val, (linktype ? *linktype : 0))
    ctf_integer(uint32_t, hopcount_val, (hopcount ? *hopcount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipIpcGetMemHandle_entry,
  TP_ARGS(
    hipIpcMemHandle_t *, handle,
    void *, devPtr
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, handle, (uintptr_t)(handle))
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipIpcGetMemHandle_exit,
  TP_ARGS(
    hipIpcMemHandle_t *, handle,
    void *, devPtr,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_sequence_text(uint8_t, handle_val, handle, size_t, (handle ? sizeof(hipIpcMemHandle_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipIpcOpenMemHandle_entry,
  TP_ARGS(
    void **, devPtr,
    hipIpcMemHandle_t, handle,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
    ctf_array_text(uint8_t, handle, &handle, sizeof(hipIpcMemHandle_t))
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipIpcOpenMemHandle_exit,
  TP_ARGS(
    void **, devPtr,
    hipIpcMemHandle_t, handle,
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, devPtr_val, (uintptr_t)((devPtr ? *devPtr : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipIpcCloseMemHandle_entry,
  TP_ARGS(
    void *, devPtr
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipIpcCloseMemHandle_exit,
  TP_ARGS(
    void *, devPtr,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipIpcGetEventHandle_entry,
  TP_ARGS(
    hipIpcEventHandle_t *, handle,
    hipEvent_t, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, handle, (uintptr_t)(handle))
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipIpcGetEventHandle_exit,
  TP_ARGS(
    hipIpcEventHandle_t *, handle,
    hipEvent_t, event,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_sequence_text(uint8_t, handle_val, handle, size_t, (handle ? sizeof(hipIpcEventHandle_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipIpcOpenEventHandle_entry,
  TP_ARGS(
    hipEvent_t *, event,
    hipIpcEventHandle_t, handle
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
    ctf_array_text(uint8_t, handle, &handle, sizeof(hipIpcEventHandle_t))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipIpcOpenEventHandle_exit,
  TP_ARGS(
    hipEvent_t *, event,
    hipIpcEventHandle_t, handle,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)((event ? *event : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipFuncSetAttribute_entry,
  TP_ARGS(
    const void *, func,
    hipFuncAttribute, attr,
    int, value
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, func, (uintptr_t)(func))
    ctf_integer(int32_t, attr, attr)
    ctf_integer(int, value, value)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipFuncSetAttribute_exit,
  TP_ARGS(
    const void *, func,
    hipFuncAttribute, attr,
    int, value,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipFuncSetCacheConfig_entry,
  TP_ARGS(
    const void *, func,
    hipFuncCache_t, config
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, func, (uintptr_t)(func))
    ctf_integer(int32_t, config, config)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipFuncSetCacheConfig_exit,
  TP_ARGS(
    const void *, func,
    hipFuncCache_t, config,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipFuncSetSharedMemConfig_entry,
  TP_ARGS(
    const void *, func,
    hipSharedMemConfig, config
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, func, (uintptr_t)(func))
    ctf_integer(int32_t, config, config)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipFuncSetSharedMemConfig_exit,
  TP_ARGS(
    const void *, func,
    hipSharedMemConfig, config,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGetLastError_entry,
  TP_ARGS(
    void
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGetLastError_exit,
  TP_ARGS(
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipPeekAtLastError_entry,
  TP_ARGS(
    void
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipPeekAtLastError_exit,
  TP_ARGS(
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGetErrorName_entry,
  TP_ARGS(
    hipError_t, hip_error
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hip_error, hip_error)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGetErrorName_exit,
  TP_ARGS(
    hipError_t, hip_error,
    const char *, hipResult
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hipResult, (uintptr_t)(hipResult))
    ctf_string(hipResult_val, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGetErrorString_entry,
  TP_ARGS(
    hipError_t, hipError
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipError, hipError)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGetErrorString_exit,
  TP_ARGS(
    hipError_t, hipError,
    const char *, hipResult
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hipResult, (uintptr_t)(hipResult))
    ctf_string(hipResult_val, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDrvGetErrorName_entry,
  TP_ARGS(
    hipError_t, hipError,
    const char **, errorString
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipError, hipError)
    ctf_integer_hex(uintptr_t, errorString, (uintptr_t)(errorString))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDrvGetErrorName_exit,
  TP_ARGS(
    hipError_t, hipError,
    const char **, errorString,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, errorString_val, (uintptr_t)((errorString ? *errorString : 0)))
    ctf_string(errorString_val_val, *errorString)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDrvGetErrorString_entry,
  TP_ARGS(
    hipError_t, hipError,
    const char **, errorString
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipError, hipError)
    ctf_integer_hex(uintptr_t, errorString, (uintptr_t)(errorString))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDrvGetErrorString_exit,
  TP_ARGS(
    hipError_t, hipError,
    const char **, errorString,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, errorString_val, (uintptr_t)((errorString ? *errorString : 0)))
    ctf_string(errorString_val_val, *errorString)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamCreate_entry,
  TP_ARGS(
    hipStream_t *, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamCreate_exit,
  TP_ARGS(
    hipStream_t *, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, stream_val, (uintptr_t)((stream ? *stream : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamCreateWithFlags_entry,
  TP_ARGS(
    hipStream_t *, stream,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamCreateWithFlags_exit,
  TP_ARGS(
    hipStream_t *, stream,
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, stream_val, (uintptr_t)((stream ? *stream : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamCreateWithPriority_entry,
  TP_ARGS(
    hipStream_t *, stream,
    unsigned int, flags,
    int, priority
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer(unsigned int, flags, flags)
    ctf_integer(int, priority, priority)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamCreateWithPriority_exit,
  TP_ARGS(
    hipStream_t *, stream,
    unsigned int, flags,
    int, priority,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, stream_val, (uintptr_t)((stream ? *stream : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceGetStreamPriorityRange_entry,
  TP_ARGS(
    int *, leastPriority,
    int *, greatestPriority
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, leastPriority, (uintptr_t)(leastPriority))
    ctf_integer_hex(uintptr_t, greatestPriority, (uintptr_t)(greatestPriority))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceGetStreamPriorityRange_exit,
  TP_ARGS(
    int *, leastPriority,
    int *, greatestPriority,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(int, leastPriority_val, (leastPriority ? *leastPriority : 0))
    ctf_integer(int, greatestPriority_val, (greatestPriority ? *greatestPriority : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamDestroy_entry,
  TP_ARGS(
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamDestroy_exit,
  TP_ARGS(
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamQuery_entry,
  TP_ARGS(
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamQuery_exit,
  TP_ARGS(
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamSynchronize_entry,
  TP_ARGS(
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamSynchronize_exit,
  TP_ARGS(
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamWaitEvent_entry,
  TP_ARGS(
    hipStream_t, stream,
    hipEvent_t, event,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamWaitEvent_exit,
  TP_ARGS(
    hipStream_t, stream,
    hipEvent_t, event,
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamGetFlags_entry,
  TP_ARGS(
    hipStream_t, stream,
    unsigned int *, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, flags, (uintptr_t)(flags))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamGetFlags_exit,
  TP_ARGS(
    hipStream_t, stream,
    unsigned int *, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(unsigned int, flags_val, (flags ? *flags : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamGetPriority_entry,
  TP_ARGS(
    hipStream_t, stream,
    int *, priority
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, priority, (uintptr_t)(priority))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamGetPriority_exit,
  TP_ARGS(
    hipStream_t, stream,
    int *, priority,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(int, priority_val, (priority ? *priority : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipExtStreamCreateWithCUMask_entry,
  TP_ARGS(
    hipStream_t *, stream,
    uint32_t, cuMaskSize,
    const uint32_t *, cuMask
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer(uint32_t, cuMaskSize, cuMaskSize)
    ctf_integer_hex(uintptr_t, cuMask, (uintptr_t)(cuMask))
    ctf_sequence(uint32_t, cuMask_vals, cuMask, uint32_t, (cuMask ? cuMaskSize : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipExtStreamCreateWithCUMask_exit,
  TP_ARGS(
    hipStream_t *, stream,
    uint32_t, cuMaskSize,
    const uint32_t *, cuMask,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, stream_val, (uintptr_t)((stream ? *stream : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipExtStreamGetCUMask_entry,
  TP_ARGS(
    hipStream_t, stream,
    uint32_t, cuMaskSize,
    uint32_t *, cuMask
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer(uint32_t, cuMaskSize, cuMaskSize)
    ctf_integer_hex(uintptr_t, cuMask, (uintptr_t)(cuMask))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipExtStreamGetCUMask_exit,
  TP_ARGS(
    hipStream_t, stream,
    uint32_t, cuMaskSize,
    uint32_t *, cuMask,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_sequence(uint32_t, cuMask_vals, cuMask, uint32_t, (cuMask ? cuMaskSize : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamAddCallback_entry,
  TP_ARGS(
    hipStream_t, stream,
    hipStreamCallback_t, callback,
    void *, userData,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, callback, (uintptr_t)(callback))
    ctf_integer_hex(uintptr_t, userData, (uintptr_t)(userData))
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamAddCallback_exit,
  TP_ARGS(
    hipStream_t, stream,
    hipStreamCallback_t, callback,
    void *, userData,
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamWaitValue32_entry,
  TP_ARGS(
    hipStream_t, stream,
    void *, ptr,
    uint32_t, value,
    unsigned int, flags,
    uint32_t, mask
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)(ptr))
    ctf_integer(uint32_t, value, value)
    ctf_integer(unsigned int, flags, flags)
    ctf_integer(uint32_t, mask, mask)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamWaitValue32_exit,
  TP_ARGS(
    hipStream_t, stream,
    void *, ptr,
    uint32_t, value,
    unsigned int, flags,
    uint32_t, mask,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamWaitValue64_entry,
  TP_ARGS(
    hipStream_t, stream,
    void *, ptr,
    uint64_t, value,
    unsigned int, flags,
    uint64_t, mask
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)(ptr))
    ctf_integer(uint64_t, value, value)
    ctf_integer(unsigned int, flags, flags)
    ctf_integer(uint64_t, mask, mask)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamWaitValue64_exit,
  TP_ARGS(
    hipStream_t, stream,
    void *, ptr,
    uint64_t, value,
    unsigned int, flags,
    uint64_t, mask,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamWriteValue32_entry,
  TP_ARGS(
    hipStream_t, stream,
    void *, ptr,
    uint32_t, value,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)(ptr))
    ctf_integer(uint32_t, value, value)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamWriteValue32_exit,
  TP_ARGS(
    hipStream_t, stream,
    void *, ptr,
    uint32_t, value,
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamWriteValue64_entry,
  TP_ARGS(
    hipStream_t, stream,
    void *, ptr,
    uint64_t, value,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)(ptr))
    ctf_integer(uint64_t, value, value)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamWriteValue64_exit,
  TP_ARGS(
    hipStream_t, stream,
    void *, ptr,
    uint64_t, value,
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipEventCreateWithFlags_entry,
  TP_ARGS(
    hipEvent_t *, event,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipEventCreateWithFlags_exit,
  TP_ARGS(
    hipEvent_t *, event,
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)((event ? *event : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipEventCreate_entry,
  TP_ARGS(
    hipEvent_t *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipEventCreate_exit,
  TP_ARGS(
    hipEvent_t *, event,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)((event ? *event : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipEventRecord_entry,
  TP_ARGS(
    hipEvent_t, event,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipEventRecord_exit,
  TP_ARGS(
    hipEvent_t, event,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipEventDestroy_entry,
  TP_ARGS(
    hipEvent_t, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipEventDestroy_exit,
  TP_ARGS(
    hipEvent_t, event,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipEventSynchronize_entry,
  TP_ARGS(
    hipEvent_t, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipEventSynchronize_exit,
  TP_ARGS(
    hipEvent_t, event,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipEventElapsedTime_entry,
  TP_ARGS(
    float *, ms,
    hipEvent_t, start,
    hipEvent_t, stop
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ms, (uintptr_t)(ms))
    ctf_integer_hex(uintptr_t, start, (uintptr_t)(start))
    ctf_integer_hex(uintptr_t, stop, (uintptr_t)(stop))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipEventElapsedTime_exit,
  TP_ARGS(
    float *, ms,
    hipEvent_t, start,
    hipEvent_t, stop,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_float(float, ms_val, (ms ? *ms : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipEventQuery_entry,
  TP_ARGS(
    hipEvent_t, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipEventQuery_exit,
  TP_ARGS(
    hipEvent_t, event,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipPointerGetAttributes_entry,
  TP_ARGS(
    hipPointerAttribute_t *, attributes,
    const void *, ptr
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, attributes, (uintptr_t)(attributes))
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)(ptr))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipPointerGetAttributes_exit,
  TP_ARGS(
    hipPointerAttribute_t *, attributes,
    const void *, ptr,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_sequence_text(uint8_t, attributes_val, attributes, size_t, (attributes ? sizeof(hipPointerAttribute_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipPointerGetAttribute_entry,
  TP_ARGS(
    void *, data,
    hipPointer_attribute, attribute,
    hipDeviceptr_t, ptr
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, data, (uintptr_t)(data))
    ctf_integer(int32_t, attribute, attribute)
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)(ptr))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipPointerGetAttribute_exit,
  TP_ARGS(
    void *, data,
    hipPointer_attribute, attribute,
    hipDeviceptr_t, ptr,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_sequence_text(uint8_t, data_val, data, size_t, attribute == HIP_POINTER_ATTRIBUTE_CONTEXT ? 0 : attribute == HIP_POINTER_ATTRIBUTE_MEMORY_TYPE ? sizeof(unsigned int) : attribute == HIP_POINTER_ATTRIBUTE_DEVICE_POINTER ? sizeof(hipDeviceptr_t) : attribute == HIP_POINTER_ATTRIBUTE_HOST_POINTER ? sizeof(void *) : attribute == HIP_POINTER_ATTRIBUTE_P2P_TOKENS ? 0 : attribute == HIP_POINTER_ATTRIBUTE_SYNC_MEMOPS ? sizeof(int) : attribute == HIP_POINTER_ATTRIBUTE_BUFFER_ID ? sizeof(unsigned long long) : attribute == HIP_POINTER_ATTRIBUTE_IS_MANAGED ? sizeof(int) : attribute == HIP_POINTER_ATTRIBUTE_DEVICE_ORDINAL ? sizeof(int) : attribute == HIP_POINTER_ATTRIBUTE_IS_LEGACY_HIP_IPC_CAPABLE ? 0 : attribute == HIP_POINTER_ATTRIBUTE_RANGE_START_ADDR ? sizeof(void *) : attribute == HIP_POINTER_ATTRIBUTE_RANGE_SIZE ? sizeof(size_t) : attribute == HIP_POINTER_ATTRIBUTE_MAPPED ? sizeof(int) : attribute == HIP_POINTER_ATTRIBUTE_ALLOWED_HANDLE_TYPES ? 0 : attribute == HIP_POINTER_ATTRIBUTE_IS_GPU_DIRECT_RDMA_CAPABLE ? 0 : attribute == HIP_POINTER_ATTRIBUTE_ACCESS_FLAGS ? sizeof(hipMemAccessFlags) : attribute == HIP_POINTER_ATTRIBUTE_MEMPOOL_HANDLE ? 0 : 0)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDrvPointerGetAttributes_entry,
  TP_ARGS(
    unsigned int, numAttributes,
    hipPointer_attribute *, attributes,
    void **, data,
    hipDeviceptr_t, ptr
  ),
  TP_FIELDS(
    ctf_integer(unsigned int, numAttributes, numAttributes)
    ctf_integer_hex(uintptr_t, attributes, (uintptr_t)(attributes))
    ctf_integer_hex(uintptr_t, data, (uintptr_t)(data))
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)(ptr))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDrvPointerGetAttributes_exit,
  TP_ARGS(
    unsigned int, numAttributes,
    hipPointer_attribute *, attributes,
    void **, data,
    hipDeviceptr_t, ptr,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipImportExternalSemaphore_entry,
  TP_ARGS(
    hipExternalSemaphore_t *, extSem_out,
    const hipExternalSemaphoreHandleDesc *, semHandleDesc
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, extSem_out, (uintptr_t)(extSem_out))
    ctf_integer_hex(uintptr_t, semHandleDesc, (uintptr_t)(semHandleDesc))
    ctf_sequence_text(uint8_t, semHandleDesc_val, semHandleDesc, size_t, (semHandleDesc ? sizeof(hipExternalSemaphoreHandleDesc) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipImportExternalSemaphore_exit,
  TP_ARGS(
    hipExternalSemaphore_t *, extSem_out,
    const hipExternalSemaphoreHandleDesc *, semHandleDesc,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, extSem_out_val, (uintptr_t)((extSem_out ? *extSem_out : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipSignalExternalSemaphoresAsync_entry,
  TP_ARGS(
    const hipExternalSemaphore_t *, extSemArray,
    const hipExternalSemaphoreSignalParams *, paramsArray,
    unsigned int, numExtSems,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, extSemArray, (uintptr_t)(extSemArray))
    ctf_integer_hex(uintptr_t, paramsArray, (uintptr_t)(paramsArray))
    ctf_integer(unsigned int, numExtSems, numExtSems)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_sequence_hex(uintptr_t, extSemArray_vals, extSemArray, unsigned int, (extSemArray ? numExtSems : 0))
    ctf_sequence_text(uint8_t, paramsArray_vals, paramsArray, size_t, ((paramsArray ? numExtSems : 0)) * sizeof(hipExternalSemaphoreSignalParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipSignalExternalSemaphoresAsync_exit,
  TP_ARGS(
    const hipExternalSemaphore_t *, extSemArray,
    const hipExternalSemaphoreSignalParams *, paramsArray,
    unsigned int, numExtSems,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipWaitExternalSemaphoresAsync_entry,
  TP_ARGS(
    const hipExternalSemaphore_t *, extSemArray,
    const hipExternalSemaphoreWaitParams *, paramsArray,
    unsigned int, numExtSems,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, extSemArray, (uintptr_t)(extSemArray))
    ctf_integer_hex(uintptr_t, paramsArray, (uintptr_t)(paramsArray))
    ctf_integer(unsigned int, numExtSems, numExtSems)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_sequence_hex(uintptr_t, extSemArray_vals, extSemArray, unsigned int, (extSemArray ? numExtSems : 0))
    ctf_sequence_text(uint8_t, paramsArray_vals, paramsArray, size_t, ((paramsArray ? numExtSems : 0)) * sizeof(hipExternalSemaphoreWaitParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipWaitExternalSemaphoresAsync_exit,
  TP_ARGS(
    const hipExternalSemaphore_t *, extSemArray,
    const hipExternalSemaphoreWaitParams *, paramsArray,
    unsigned int, numExtSems,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDestroyExternalSemaphore_entry,
  TP_ARGS(
    hipExternalSemaphore_t, extSem
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, extSem, (uintptr_t)(extSem))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDestroyExternalSemaphore_exit,
  TP_ARGS(
    hipExternalSemaphore_t, extSem,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipImportExternalMemory_entry,
  TP_ARGS(
    hipExternalMemory_t *, extMem_out,
    const hipExternalMemoryHandleDesc *, memHandleDesc
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, extMem_out, (uintptr_t)(extMem_out))
    ctf_integer_hex(uintptr_t, memHandleDesc, (uintptr_t)(memHandleDesc))
    ctf_sequence_text(uint8_t, memHandleDesc_val, memHandleDesc, size_t, (memHandleDesc ? sizeof(hipExternalMemoryHandleDesc) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipImportExternalMemory_exit,
  TP_ARGS(
    hipExternalMemory_t *, extMem_out,
    const hipExternalMemoryHandleDesc *, memHandleDesc,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, extMem_out_val, (uintptr_t)((extMem_out ? *extMem_out : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipExternalMemoryGetMappedBuffer_entry,
  TP_ARGS(
    void **, devPtr,
    hipExternalMemory_t, extMem,
    const hipExternalMemoryBufferDesc *, bufferDesc
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
    ctf_integer_hex(uintptr_t, extMem, (uintptr_t)(extMem))
    ctf_integer_hex(uintptr_t, bufferDesc, (uintptr_t)(bufferDesc))
    ctf_sequence_text(uint8_t, bufferDesc_val, bufferDesc, size_t, (bufferDesc ? sizeof(hipExternalMemoryBufferDesc) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipExternalMemoryGetMappedBuffer_exit,
  TP_ARGS(
    void **, devPtr,
    hipExternalMemory_t, extMem,
    const hipExternalMemoryBufferDesc *, bufferDesc,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, devPtr_val, (uintptr_t)((devPtr ? *devPtr : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDestroyExternalMemory_entry,
  TP_ARGS(
    hipExternalMemory_t, extMem
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, extMem, (uintptr_t)(extMem))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDestroyExternalMemory_exit,
  TP_ARGS(
    hipExternalMemory_t, extMem,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMalloc_entry,
  TP_ARGS(
    void **, ptr,
    size_t, size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)(ptr))
    ctf_integer(size_t, size, size)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMalloc_exit,
  TP_ARGS(
    void **, ptr,
    size_t, size,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, ptr_val, (uintptr_t)((ptr ? *ptr : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipExtMallocWithFlags_entry,
  TP_ARGS(
    void **, ptr,
    size_t, sizeBytes,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)(ptr))
    ctf_integer(size_t, sizeBytes, sizeBytes)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipExtMallocWithFlags_exit,
  TP_ARGS(
    void **, ptr,
    size_t, sizeBytes,
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, ptr_val, (uintptr_t)((ptr ? *ptr : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMallocHost_entry,
  TP_ARGS(
    void **, ptr,
    size_t, size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)(ptr))
    ctf_integer(size_t, size, size)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMallocHost_exit,
  TP_ARGS(
    void **, ptr,
    size_t, size,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, ptr_val, (uintptr_t)((ptr ? *ptr : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemAllocHost_entry,
  TP_ARGS(
    void **, ptr,
    size_t, size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)(ptr))
    ctf_integer(size_t, size, size)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemAllocHost_exit,
  TP_ARGS(
    void **, ptr,
    size_t, size,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, ptr_val, (uintptr_t)((ptr ? *ptr : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipHostMalloc_entry,
  TP_ARGS(
    void **, ptr,
    size_t, size,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)(ptr))
    ctf_integer(size_t, size, size)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipHostMalloc_exit,
  TP_ARGS(
    void **, ptr,
    size_t, size,
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, ptr_val, (uintptr_t)((ptr ? *ptr : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMallocManaged_entry,
  TP_ARGS(
    void **, dev_ptr,
    size_t, size,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dev_ptr, (uintptr_t)(dev_ptr))
    ctf_integer(size_t, size, size)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMallocManaged_exit,
  TP_ARGS(
    void **, dev_ptr,
    size_t, size,
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, dev_ptr_val, (uintptr_t)((dev_ptr ? *dev_ptr : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemPrefetchAsync_entry,
  TP_ARGS(
    const void *, dev_ptr,
    size_t, count,
    int, device,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dev_ptr, (uintptr_t)(dev_ptr))
    ctf_integer(size_t, count, count)
    ctf_integer(int, device, device)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemPrefetchAsync_exit,
  TP_ARGS(
    const void *, dev_ptr,
    size_t, count,
    int, device,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemAdvise_entry,
  TP_ARGS(
    const void *, dev_ptr,
    size_t, count,
    hipMemoryAdvise, advice,
    int, device
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dev_ptr, (uintptr_t)(dev_ptr))
    ctf_integer(size_t, count, count)
    ctf_integer(int32_t, advice, advice)
    ctf_integer(int, device, device)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemAdvise_exit,
  TP_ARGS(
    const void *, dev_ptr,
    size_t, count,
    hipMemoryAdvise, advice,
    int, device,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemRangeGetAttribute_entry,
  TP_ARGS(
    void *, data,
    size_t, data_size,
    hipMemRangeAttribute, attribute,
    const void *, dev_ptr,
    size_t, count
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, data, (uintptr_t)(data))
    ctf_integer(size_t, data_size, data_size)
    ctf_integer(int32_t, attribute, attribute)
    ctf_integer_hex(uintptr_t, dev_ptr, (uintptr_t)(dev_ptr))
    ctf_integer(size_t, count, count)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemRangeGetAttribute_exit,
  TP_ARGS(
    void *, data,
    size_t, data_size,
    hipMemRangeAttribute, attribute,
    const void *, dev_ptr,
    size_t, count,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_sequence_text(uint8_t, data_vals, data, size_t, ((data ? data_size : 0)) * sizeof(uint8_t))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemRangeGetAttributes_entry,
  TP_ARGS(
    void **, data,
    size_t *, data_sizes,
    hipMemRangeAttribute *, attributes,
    size_t, num_attributes,
    const void *, dev_ptr,
    size_t, count
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, data, (uintptr_t)(data))
    ctf_integer_hex(uintptr_t, data_sizes, (uintptr_t)(data_sizes))
    ctf_integer_hex(uintptr_t, attributes, (uintptr_t)(attributes))
    ctf_integer(size_t, num_attributes, num_attributes)
    ctf_integer_hex(uintptr_t, dev_ptr, (uintptr_t)(dev_ptr))
    ctf_integer(size_t, count, count)
    ctf_sequence(int32_t, attributes_vals, attributes, size_t, (attributes ? num_attributes : 0))
    ctf_sequence(size_t, data_sizes_vals, data_sizes, size_t, (data_sizes ? num_attributes : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemRangeGetAttributes_exit,
  TP_ARGS(
    void **, data,
    size_t *, data_sizes,
    hipMemRangeAttribute *, attributes,
    size_t, num_attributes,
    const void *, dev_ptr,
    size_t, count,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamAttachMemAsync_entry,
  TP_ARGS(
    hipStream_t, stream,
    void *, dev_ptr,
    size_t, length,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, dev_ptr, (uintptr_t)(dev_ptr))
    ctf_integer(size_t, length, length)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamAttachMemAsync_exit,
  TP_ARGS(
    hipStream_t, stream,
    void *, dev_ptr,
    size_t, length,
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMallocAsync_entry,
  TP_ARGS(
    void **, dev_ptr,
    size_t, size,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dev_ptr, (uintptr_t)(dev_ptr))
    ctf_integer(size_t, size, size)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMallocAsync_exit,
  TP_ARGS(
    void **, dev_ptr,
    size_t, size,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, dev_ptr_val, (uintptr_t)((dev_ptr ? *dev_ptr : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipFreeAsync_entry,
  TP_ARGS(
    void *, dev_ptr,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dev_ptr, (uintptr_t)(dev_ptr))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipFreeAsync_exit,
  TP_ARGS(
    void *, dev_ptr,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemPoolTrimTo_entry,
  TP_ARGS(
    hipMemPool_t, mem_pool,
    size_t, min_bytes_to_hold
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mem_pool, (uintptr_t)(mem_pool))
    ctf_integer(size_t, min_bytes_to_hold, min_bytes_to_hold)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemPoolTrimTo_exit,
  TP_ARGS(
    hipMemPool_t, mem_pool,
    size_t, min_bytes_to_hold,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemPoolSetAttribute_entry,
  TP_ARGS(
    hipMemPool_t, mem_pool,
    hipMemPoolAttr, attr,
    void *, value
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mem_pool, (uintptr_t)(mem_pool))
    ctf_integer(int32_t, attr, attr)
    ctf_integer_hex(uintptr_t, value, (uintptr_t)(value))
    ctf_sequence_text(uint8_t, value_val, value, size_t, attr == hipMemPoolReuseFollowEventDependencies ? sizeof(int) : attr == hipMemPoolReuseAllowOpportunistic ? sizeof(int) : attr == hipMemPoolReuseAllowInternalDependencies ? sizeof(int) : attr == hipMemPoolAttrReleaseThreshold ? sizeof(uint64_t) : attr == hipMemPoolAttrReservedMemCurrent ? 0 : attr == hipMemPoolAttrReservedMemHigh ? 0 : attr == hipMemPoolAttrUsedMemCurrent ? 0 : attr == hipMemPoolAttrUsedMemHigh ? 0 : 0)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemPoolSetAttribute_exit,
  TP_ARGS(
    hipMemPool_t, mem_pool,
    hipMemPoolAttr, attr,
    void *, value,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemPoolGetAttribute_entry,
  TP_ARGS(
    hipMemPool_t, mem_pool,
    hipMemPoolAttr, attr,
    void *, value
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mem_pool, (uintptr_t)(mem_pool))
    ctf_integer(int32_t, attr, attr)
    ctf_integer_hex(uintptr_t, value, (uintptr_t)(value))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemPoolGetAttribute_exit,
  TP_ARGS(
    hipMemPool_t, mem_pool,
    hipMemPoolAttr, attr,
    void *, value,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_sequence_text(uint8_t, value_val, value, size_t, attr == hipMemPoolReuseFollowEventDependencies ? sizeof(int) : attr == hipMemPoolReuseAllowOpportunistic ? sizeof(int) : attr == hipMemPoolReuseAllowInternalDependencies ? sizeof(int) : attr == hipMemPoolAttrReleaseThreshold ? sizeof(uint64_t) : attr == hipMemPoolAttrReservedMemCurrent ? 0 : attr == hipMemPoolAttrReservedMemHigh ? 0 : attr == hipMemPoolAttrUsedMemCurrent ? 0 : attr == hipMemPoolAttrUsedMemHigh ? 0 : 0)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemPoolSetAccess_entry,
  TP_ARGS(
    hipMemPool_t, mem_pool,
    const hipMemAccessDesc *, desc_list,
    size_t, count
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mem_pool, (uintptr_t)(mem_pool))
    ctf_integer_hex(uintptr_t, desc_list, (uintptr_t)(desc_list))
    ctf_integer(size_t, count, count)
    ctf_sequence_text(uint8_t, desc_list_vals, desc_list, size_t, ((desc_list ? count : 0)) * sizeof(hipMemAccessDesc))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemPoolSetAccess_exit,
  TP_ARGS(
    hipMemPool_t, mem_pool,
    const hipMemAccessDesc *, desc_list,
    size_t, count,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemPoolGetAccess_entry,
  TP_ARGS(
    hipMemAccessFlags *, flags,
    hipMemPool_t, mem_pool,
    hipMemLocation *, location
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, flags, (uintptr_t)(flags))
    ctf_integer_hex(uintptr_t, mem_pool, (uintptr_t)(mem_pool))
    ctf_integer_hex(uintptr_t, location, (uintptr_t)(location))
    ctf_sequence_text(uint8_t, location_val, location, size_t, (location ? sizeof(hipMemLocation) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemPoolGetAccess_exit,
  TP_ARGS(
    hipMemAccessFlags *, flags,
    hipMemPool_t, mem_pool,
    hipMemLocation *, location,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(int32_t, flags_val, (flags ? *flags : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemPoolCreate_entry,
  TP_ARGS(
    hipMemPool_t *, mem_pool,
    const hipMemPoolProps *, pool_props
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mem_pool, (uintptr_t)(mem_pool))
    ctf_integer_hex(uintptr_t, pool_props, (uintptr_t)(pool_props))
    ctf_sequence_text(uint8_t, pool_props_val, pool_props, size_t, (pool_props ? sizeof(hipMemPoolProps) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemPoolCreate_exit,
  TP_ARGS(
    hipMemPool_t *, mem_pool,
    const hipMemPoolProps *, pool_props,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, mem_pool_val, (uintptr_t)((mem_pool ? *mem_pool : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemPoolDestroy_entry,
  TP_ARGS(
    hipMemPool_t, mem_pool
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mem_pool, (uintptr_t)(mem_pool))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemPoolDestroy_exit,
  TP_ARGS(
    hipMemPool_t, mem_pool,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMallocFromPoolAsync_entry,
  TP_ARGS(
    void **, dev_ptr,
    size_t, size,
    hipMemPool_t, mem_pool,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dev_ptr, (uintptr_t)(dev_ptr))
    ctf_integer(size_t, size, size)
    ctf_integer_hex(uintptr_t, mem_pool, (uintptr_t)(mem_pool))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMallocFromPoolAsync_exit,
  TP_ARGS(
    void **, dev_ptr,
    size_t, size,
    hipMemPool_t, mem_pool,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, dev_ptr_val, (uintptr_t)((dev_ptr ? *dev_ptr : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemPoolExportToShareableHandle_entry,
  TP_ARGS(
    void *, shared_handle,
    hipMemPool_t, mem_pool,
    hipMemAllocationHandleType, handle_type,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, shared_handle, (uintptr_t)(shared_handle))
    ctf_integer_hex(uintptr_t, mem_pool, (uintptr_t)(mem_pool))
    ctf_integer(int32_t, handle_type, handle_type)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemPoolExportToShareableHandle_exit,
  TP_ARGS(
    void *, shared_handle,
    hipMemPool_t, mem_pool,
    hipMemAllocationHandleType, handle_type,
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_sequence_text(uint8_t, shared_handle_val, shared_handle, size_t, handle_type == hipMemHandleTypePosixFileDescriptor ? sizeof(int) : 0)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemPoolImportFromShareableHandle_entry,
  TP_ARGS(
    hipMemPool_t *, mem_pool,
    void *, shared_handle,
    hipMemAllocationHandleType, handle_type,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mem_pool, (uintptr_t)(mem_pool))
    ctf_integer_hex(uintptr_t, shared_handle, (uintptr_t)(shared_handle))
    ctf_integer(int32_t, handle_type, handle_type)
    ctf_integer(unsigned int, flags, flags)
    ctf_sequence_text(uint8_t, shared_handle_val, shared_handle, size_t, handle_type == hipMemHandleTypePosixFileDescriptor ? sizeof(int) : 0)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemPoolImportFromShareableHandle_exit,
  TP_ARGS(
    hipMemPool_t *, mem_pool,
    void *, shared_handle,
    hipMemAllocationHandleType, handle_type,
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, mem_pool_val, (uintptr_t)((mem_pool ? *mem_pool : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemPoolExportPointer_entry,
  TP_ARGS(
    hipMemPoolPtrExportData *, export_data,
    void *, dev_ptr
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, export_data, (uintptr_t)(export_data))
    ctf_integer_hex(uintptr_t, dev_ptr, (uintptr_t)(dev_ptr))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemPoolExportPointer_exit,
  TP_ARGS(
    hipMemPoolPtrExportData *, export_data,
    void *, dev_ptr,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_sequence_text(uint8_t, export_data_val, export_data, size_t, (export_data ? sizeof(hipMemPoolPtrExportData) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemPoolImportPointer_entry,
  TP_ARGS(
    void **, dev_ptr,
    hipMemPool_t, mem_pool,
    hipMemPoolPtrExportData *, export_data
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dev_ptr, (uintptr_t)(dev_ptr))
    ctf_integer_hex(uintptr_t, mem_pool, (uintptr_t)(mem_pool))
    ctf_integer_hex(uintptr_t, export_data, (uintptr_t)(export_data))
    ctf_sequence_text(uint8_t, export_data_val, export_data, size_t, (export_data ? sizeof(hipMemPoolPtrExportData) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemPoolImportPointer_exit,
  TP_ARGS(
    void **, dev_ptr,
    hipMemPool_t, mem_pool,
    hipMemPoolPtrExportData *, export_data,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, dev_ptr_val, (uintptr_t)((dev_ptr ? *dev_ptr : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipHostAlloc_entry,
  TP_ARGS(
    void **, ptr,
    size_t, size,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)(ptr))
    ctf_integer(size_t, size, size)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipHostAlloc_exit,
  TP_ARGS(
    void **, ptr,
    size_t, size,
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, ptr_val, (uintptr_t)((ptr ? *ptr : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipHostGetDevicePointer_entry,
  TP_ARGS(
    void **, devPtr,
    void *, hstPtr,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
    ctf_integer_hex(uintptr_t, hstPtr, (uintptr_t)(hstPtr))
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipHostGetDevicePointer_exit,
  TP_ARGS(
    void **, devPtr,
    void *, hstPtr,
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, devPtr_val, (uintptr_t)((devPtr ? *devPtr : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipHostGetFlags_entry,
  TP_ARGS(
    unsigned int *, flagsPtr,
    void *, hostPtr
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, flagsPtr, (uintptr_t)(flagsPtr))
    ctf_integer_hex(uintptr_t, hostPtr, (uintptr_t)(hostPtr))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipHostGetFlags_exit,
  TP_ARGS(
    unsigned int *, flagsPtr,
    void *, hostPtr,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(unsigned int, flagsPtr_val, (flagsPtr ? *flagsPtr : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipHostRegister_entry,
  TP_ARGS(
    void *, hostPtr,
    size_t, sizeBytes,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hostPtr, (uintptr_t)(hostPtr))
    ctf_integer(size_t, sizeBytes, sizeBytes)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipHostRegister_exit,
  TP_ARGS(
    void *, hostPtr,
    size_t, sizeBytes,
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipHostUnregister_entry,
  TP_ARGS(
    void *, hostPtr
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hostPtr, (uintptr_t)(hostPtr))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipHostUnregister_exit,
  TP_ARGS(
    void *, hostPtr,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMallocPitch_entry,
  TP_ARGS(
    void **, ptr,
    size_t *, pitch,
    size_t, width,
    size_t, height
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)(ptr))
    ctf_integer_hex(uintptr_t, pitch, (uintptr_t)(pitch))
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMallocPitch_exit,
  TP_ARGS(
    void **, ptr,
    size_t *, pitch,
    size_t, width,
    size_t, height,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, ptr_val, (uintptr_t)((ptr ? *ptr : 0)))
    ctf_integer(size_t, pitch_val, (pitch ? *pitch : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemAllocPitch_entry,
  TP_ARGS(
    hipDeviceptr_t *, dptr,
    size_t *, pitch,
    size_t, widthInBytes,
    size_t, height,
    unsigned int, elementSizeBytes
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dptr, (uintptr_t)(dptr))
    ctf_integer_hex(uintptr_t, pitch, (uintptr_t)(pitch))
    ctf_integer(size_t, widthInBytes, widthInBytes)
    ctf_integer(size_t, height, height)
    ctf_integer(unsigned int, elementSizeBytes, elementSizeBytes)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemAllocPitch_exit,
  TP_ARGS(
    hipDeviceptr_t *, dptr,
    size_t *, pitch,
    size_t, widthInBytes,
    size_t, height,
    unsigned int, elementSizeBytes,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, dptr_val, (uintptr_t)((dptr ? *dptr : 0)))
    ctf_integer(size_t, pitch_val, (pitch ? *pitch : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipFree_entry,
  TP_ARGS(
    void *, ptr
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)(ptr))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipFree_exit,
  TP_ARGS(
    void *, ptr,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipFreeHost_entry,
  TP_ARGS(
    void *, ptr
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)(ptr))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipFreeHost_exit,
  TP_ARGS(
    void *, ptr,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipHostFree_entry,
  TP_ARGS(
    void *, ptr
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)(ptr))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipHostFree_exit,
  TP_ARGS(
    void *, ptr,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpy_entry,
  TP_ARGS(
    void *, dst,
    const void *, src,
    size_t, sizeBytes,
    hipMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, sizeBytes, sizeBytes)
    ctf_integer(int32_t, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpy_exit,
  TP_ARGS(
    void *, dst,
    const void *, src,
    size_t, sizeBytes,
    hipMemcpyKind, kind,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyWithStream_entry,
  TP_ARGS(
    void *, dst,
    const void *, src,
    size_t, sizeBytes,
    hipMemcpyKind, kind,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, sizeBytes, sizeBytes)
    ctf_integer(int32_t, kind, kind)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyWithStream_exit,
  TP_ARGS(
    void *, dst,
    const void *, src,
    size_t, sizeBytes,
    hipMemcpyKind, kind,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyHtoD_entry,
  TP_ARGS(
    hipDeviceptr_t, dst,
    void *, src,
    size_t, sizeBytes
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, sizeBytes, sizeBytes)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyHtoD_exit,
  TP_ARGS(
    hipDeviceptr_t, dst,
    void *, src,
    size_t, sizeBytes,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyDtoH_entry,
  TP_ARGS(
    void *, dst,
    hipDeviceptr_t, src,
    size_t, sizeBytes
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, sizeBytes, sizeBytes)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyDtoH_exit,
  TP_ARGS(
    void *, dst,
    hipDeviceptr_t, src,
    size_t, sizeBytes,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyDtoD_entry,
  TP_ARGS(
    hipDeviceptr_t, dst,
    hipDeviceptr_t, src,
    size_t, sizeBytes
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, sizeBytes, sizeBytes)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyDtoD_exit,
  TP_ARGS(
    hipDeviceptr_t, dst,
    hipDeviceptr_t, src,
    size_t, sizeBytes,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyHtoDAsync_entry,
  TP_ARGS(
    hipDeviceptr_t, dst,
    void *, src,
    size_t, sizeBytes,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, sizeBytes, sizeBytes)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyHtoDAsync_exit,
  TP_ARGS(
    hipDeviceptr_t, dst,
    void *, src,
    size_t, sizeBytes,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyDtoHAsync_entry,
  TP_ARGS(
    void *, dst,
    hipDeviceptr_t, src,
    size_t, sizeBytes,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, sizeBytes, sizeBytes)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyDtoHAsync_exit,
  TP_ARGS(
    void *, dst,
    hipDeviceptr_t, src,
    size_t, sizeBytes,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyDtoDAsync_entry,
  TP_ARGS(
    hipDeviceptr_t, dst,
    hipDeviceptr_t, src,
    size_t, sizeBytes,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, sizeBytes, sizeBytes)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyDtoDAsync_exit,
  TP_ARGS(
    hipDeviceptr_t, dst,
    hipDeviceptr_t, src,
    size_t, sizeBytes,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipModuleGetGlobal_entry,
  TP_ARGS(
    hipDeviceptr_t *, dptr,
    size_t *, bytes,
    hipModule_t, hmod,
    const char *, name
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dptr, (uintptr_t)(dptr))
    ctf_integer_hex(uintptr_t, bytes, (uintptr_t)(bytes))
    ctf_integer_hex(uintptr_t, hmod, (uintptr_t)(hmod))
    ctf_integer_hex(uintptr_t, name, (uintptr_t)(name))
    ctf_string(name_val, name)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipModuleGetGlobal_exit,
  TP_ARGS(
    hipDeviceptr_t *, dptr,
    size_t *, bytes,
    hipModule_t, hmod,
    const char *, name,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, dptr_val, (uintptr_t)((dptr ? *dptr : 0)))
    ctf_integer(size_t, bytes_val, (bytes ? *bytes : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGetSymbolAddress_entry,
  TP_ARGS(
    void **, devPtr,
    const void *, symbol
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGetSymbolAddress_exit,
  TP_ARGS(
    void **, devPtr,
    const void *, symbol,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, devPtr_val, (uintptr_t)((devPtr ? *devPtr : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGetSymbolSize_entry,
  TP_ARGS(
    size_t *, size,
    const void *, symbol
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, size, (uintptr_t)(size))
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGetSymbolSize_exit,
  TP_ARGS(
    size_t *, size,
    const void *, symbol,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(size_t, size_val, (size ? *size : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyToSymbol_entry,
  TP_ARGS(
    const void *, symbol,
    const void *, src,
    size_t, sizeBytes,
    size_t, offset,
    hipMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, sizeBytes, sizeBytes)
    ctf_integer(size_t, offset, offset)
    ctf_integer(int32_t, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyToSymbol_exit,
  TP_ARGS(
    const void *, symbol,
    const void *, src,
    size_t, sizeBytes,
    size_t, offset,
    hipMemcpyKind, kind,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyToSymbolAsync_entry,
  TP_ARGS(
    const void *, symbol,
    const void *, src,
    size_t, sizeBytes,
    size_t, offset,
    hipMemcpyKind, kind,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, sizeBytes, sizeBytes)
    ctf_integer(size_t, offset, offset)
    ctf_integer(int32_t, kind, kind)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyToSymbolAsync_exit,
  TP_ARGS(
    const void *, symbol,
    const void *, src,
    size_t, sizeBytes,
    size_t, offset,
    hipMemcpyKind, kind,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyFromSymbol_entry,
  TP_ARGS(
    void *, dst,
    const void *, symbol,
    size_t, sizeBytes,
    size_t, offset,
    hipMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
    ctf_integer(size_t, sizeBytes, sizeBytes)
    ctf_integer(size_t, offset, offset)
    ctf_integer(int32_t, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyFromSymbol_exit,
  TP_ARGS(
    void *, dst,
    const void *, symbol,
    size_t, sizeBytes,
    size_t, offset,
    hipMemcpyKind, kind,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyFromSymbolAsync_entry,
  TP_ARGS(
    void *, dst,
    const void *, symbol,
    size_t, sizeBytes,
    size_t, offset,
    hipMemcpyKind, kind,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
    ctf_integer(size_t, sizeBytes, sizeBytes)
    ctf_integer(size_t, offset, offset)
    ctf_integer(int32_t, kind, kind)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyFromSymbolAsync_exit,
  TP_ARGS(
    void *, dst,
    const void *, symbol,
    size_t, sizeBytes,
    size_t, offset,
    hipMemcpyKind, kind,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyAsync_entry,
  TP_ARGS(
    void *, dst,
    const void *, src,
    size_t, sizeBytes,
    hipMemcpyKind, kind,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, sizeBytes, sizeBytes)
    ctf_integer(int32_t, kind, kind)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyAsync_exit,
  TP_ARGS(
    void *, dst,
    const void *, src,
    size_t, sizeBytes,
    hipMemcpyKind, kind,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemset_entry,
  TP_ARGS(
    void *, dst,
    int, value,
    size_t, sizeBytes
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(int, value, value)
    ctf_integer(size_t, sizeBytes, sizeBytes)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemset_exit,
  TP_ARGS(
    void *, dst,
    int, value,
    size_t, sizeBytes,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemsetD8_entry,
  TP_ARGS(
    hipDeviceptr_t, dest,
    unsigned char, value,
    size_t, count
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dest, (uintptr_t)(dest))
    ctf_integer(unsigned char, value, value)
    ctf_integer(size_t, count, count)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemsetD8_exit,
  TP_ARGS(
    hipDeviceptr_t, dest,
    unsigned char, value,
    size_t, count,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemsetD8Async_entry,
  TP_ARGS(
    hipDeviceptr_t, dest,
    unsigned char, value,
    size_t, count,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dest, (uintptr_t)(dest))
    ctf_integer(unsigned char, value, value)
    ctf_integer(size_t, count, count)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemsetD8Async_exit,
  TP_ARGS(
    hipDeviceptr_t, dest,
    unsigned char, value,
    size_t, count,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemsetD16_entry,
  TP_ARGS(
    hipDeviceptr_t, dest,
    unsigned short int, value,
    size_t, count
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dest, (uintptr_t)(dest))
    ctf_integer(unsigned short int, value, value)
    ctf_integer(size_t, count, count)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemsetD16_exit,
  TP_ARGS(
    hipDeviceptr_t, dest,
    unsigned short int, value,
    size_t, count,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemsetD16Async_entry,
  TP_ARGS(
    hipDeviceptr_t, dest,
    unsigned short int, value,
    size_t, count,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dest, (uintptr_t)(dest))
    ctf_integer(unsigned short int, value, value)
    ctf_integer(size_t, count, count)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemsetD16Async_exit,
  TP_ARGS(
    hipDeviceptr_t, dest,
    unsigned short int, value,
    size_t, count,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemsetD32_entry,
  TP_ARGS(
    hipDeviceptr_t, dest,
    int, value,
    size_t, count
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dest, (uintptr_t)(dest))
    ctf_integer(int, value, value)
    ctf_integer(size_t, count, count)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemsetD32_exit,
  TP_ARGS(
    hipDeviceptr_t, dest,
    int, value,
    size_t, count,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemsetAsync_entry,
  TP_ARGS(
    void *, dst,
    int, value,
    size_t, sizeBytes,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(int, value, value)
    ctf_integer(size_t, sizeBytes, sizeBytes)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemsetAsync_exit,
  TP_ARGS(
    void *, dst,
    int, value,
    size_t, sizeBytes,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemsetD32Async_entry,
  TP_ARGS(
    hipDeviceptr_t, dst,
    int, value,
    size_t, count,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(int, value, value)
    ctf_integer(size_t, count, count)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemsetD32Async_exit,
  TP_ARGS(
    hipDeviceptr_t, dst,
    int, value,
    size_t, count,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemset2D_entry,
  TP_ARGS(
    void *, dst,
    size_t, pitch,
    int, value,
    size_t, width,
    size_t, height
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, pitch, pitch)
    ctf_integer(int, value, value)
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemset2D_exit,
  TP_ARGS(
    void *, dst,
    size_t, pitch,
    int, value,
    size_t, width,
    size_t, height,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemset2DAsync_entry,
  TP_ARGS(
    void *, dst,
    size_t, pitch,
    int, value,
    size_t, width,
    size_t, height,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, pitch, pitch)
    ctf_integer(int, value, value)
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemset2DAsync_exit,
  TP_ARGS(
    void *, dst,
    size_t, pitch,
    int, value,
    size_t, width,
    size_t, height,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemset3D_entry,
  TP_ARGS(
    hipPitchedPtr, pitchedDevPtr,
    int, value,
    hipExtent, extent
  ),
  TP_FIELDS(
    ctf_array_text(uint8_t, pitchedDevPtr, &pitchedDevPtr, sizeof(hipPitchedPtr))
    ctf_integer(int, value, value)
    ctf_array_text(uint8_t, extent, &extent, sizeof(hipExtent))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemset3D_exit,
  TP_ARGS(
    hipPitchedPtr, pitchedDevPtr,
    int, value,
    hipExtent, extent,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemset3DAsync_entry,
  TP_ARGS(
    hipPitchedPtr, pitchedDevPtr,
    int, value,
    hipExtent, extent,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_array_text(uint8_t, pitchedDevPtr, &pitchedDevPtr, sizeof(hipPitchedPtr))
    ctf_integer(int, value, value)
    ctf_array_text(uint8_t, extent, &extent, sizeof(hipExtent))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemset3DAsync_exit,
  TP_ARGS(
    hipPitchedPtr, pitchedDevPtr,
    int, value,
    hipExtent, extent,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemGetInfo_entry,
  TP_ARGS(
    size_t *, free,
    size_t *, total
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, free, (uintptr_t)(free))
    ctf_integer_hex(uintptr_t, total, (uintptr_t)(total))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemGetInfo_exit,
  TP_ARGS(
    size_t *, free,
    size_t *, total,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(size_t, free_val, (free ? *free : 0))
    ctf_integer(size_t, total_val, (total ? *total : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemPtrGetInfo_entry,
  TP_ARGS(
    void *, ptr,
    size_t *, size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)(ptr))
    ctf_integer_hex(uintptr_t, size, (uintptr_t)(size))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemPtrGetInfo_exit,
  TP_ARGS(
    void *, ptr,
    size_t *, size,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(size_t, size_val, (size ? *size : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMallocArray_entry,
  TP_ARGS(
    hipArray **, array,
    const hipChannelFormatDesc *, desc,
    size_t, width,
    size_t, height,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, array, (uintptr_t)(array))
    ctf_integer_hex(uintptr_t, desc, (uintptr_t)(desc))
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
    ctf_integer(unsigned int, flags, flags)
    ctf_sequence_text(uint8_t, desc_val, desc, size_t, (desc ? sizeof(hipChannelFormatDesc) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMallocArray_exit,
  TP_ARGS(
    hipArray **, array,
    const hipChannelFormatDesc *, desc,
    size_t, width,
    size_t, height,
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, array_val, (uintptr_t)((array ? *array : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipArrayCreate_entry,
  TP_ARGS(
    hipArray **, pHandle,
    const HIP_ARRAY_DESCRIPTOR *, pAllocateArray
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pHandle, (uintptr_t)(pHandle))
    ctf_integer_hex(uintptr_t, pAllocateArray, (uintptr_t)(pAllocateArray))
    ctf_sequence_text(uint8_t, pAllocateArray_val, pAllocateArray, size_t, (pAllocateArray ? sizeof(HIP_ARRAY_DESCRIPTOR) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipArrayCreate_exit,
  TP_ARGS(
    hipArray **, pHandle,
    const HIP_ARRAY_DESCRIPTOR *, pAllocateArray,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, pHandle_val, (uintptr_t)((pHandle ? *pHandle : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipArrayDestroy_entry,
  TP_ARGS(
    hipArray *, array
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, array, (uintptr_t)(array))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipArrayDestroy_exit,
  TP_ARGS(
    hipArray *, array,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipArray3DCreate_entry,
  TP_ARGS(
    hipArray **, array,
    const HIP_ARRAY3D_DESCRIPTOR *, pAllocateArray
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, array, (uintptr_t)(array))
    ctf_integer_hex(uintptr_t, pAllocateArray, (uintptr_t)(pAllocateArray))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipArray3DCreate_exit,
  TP_ARGS(
    hipArray **, array,
    const HIP_ARRAY3D_DESCRIPTOR *, pAllocateArray,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMalloc3D_entry,
  TP_ARGS(
    hipPitchedPtr *, pitchedDevPtr,
    hipExtent, extent
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pitchedDevPtr, (uintptr_t)(pitchedDevPtr))
    ctf_array_text(uint8_t, extent, &extent, sizeof(hipExtent))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMalloc3D_exit,
  TP_ARGS(
    hipPitchedPtr *, pitchedDevPtr,
    hipExtent, extent,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_sequence_text(uint8_t, pitchedDevPtr_val, pitchedDevPtr, size_t, (pitchedDevPtr ? sizeof(hipPitchedPtr) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipFreeArray_entry,
  TP_ARGS(
    hipArray *, array
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, array, (uintptr_t)(array))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipFreeArray_exit,
  TP_ARGS(
    hipArray *, array,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipFreeMipmappedArray_entry,
  TP_ARGS(
    hipMipmappedArray_t, mipmappedArray
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mipmappedArray, (uintptr_t)(mipmappedArray))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipFreeMipmappedArray_exit,
  TP_ARGS(
    hipMipmappedArray_t, mipmappedArray,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMalloc3DArray_entry,
  TP_ARGS(
    hipArray **, array,
    const struct hipChannelFormatDesc *, desc,
    struct hipExtent, extent,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, array, (uintptr_t)(array))
    ctf_integer_hex(uintptr_t, desc, (uintptr_t)(desc))
    ctf_array_text(uint8_t, extent, &extent, sizeof(struct hipExtent))
    ctf_integer(unsigned int, flags, flags)
    ctf_sequence_text(uint8_t, desc_val, desc, size_t, (desc ? sizeof(struct hipChannelFormatDesc) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMalloc3DArray_exit,
  TP_ARGS(
    hipArray **, array,
    const struct hipChannelFormatDesc *, desc,
    struct hipExtent, extent,
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, array_val, (uintptr_t)((array ? *array : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMallocMipmappedArray_entry,
  TP_ARGS(
    hipMipmappedArray_t *, mipmappedArray,
    const struct hipChannelFormatDesc *, desc,
    struct hipExtent, extent,
    unsigned int, numLevels,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mipmappedArray, (uintptr_t)(mipmappedArray))
    ctf_integer_hex(uintptr_t, desc, (uintptr_t)(desc))
    ctf_array_text(uint8_t, extent, &extent, sizeof(struct hipExtent))
    ctf_integer(unsigned int, numLevels, numLevels)
    ctf_integer(unsigned int, flags, flags)
    ctf_sequence_text(uint8_t, desc_val, desc, size_t, (desc ? sizeof(struct hipChannelFormatDesc) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMallocMipmappedArray_exit,
  TP_ARGS(
    hipMipmappedArray_t *, mipmappedArray,
    const struct hipChannelFormatDesc *, desc,
    struct hipExtent, extent,
    unsigned int, numLevels,
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, mipmappedArray_val, (uintptr_t)((mipmappedArray ? *mipmappedArray : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGetMipmappedArrayLevel_entry,
  TP_ARGS(
    hipArray_t *, levelArray,
    hipMipmappedArray_const_t, mipmappedArray,
    unsigned int, level
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, levelArray, (uintptr_t)(levelArray))
    ctf_integer_hex(uintptr_t, mipmappedArray, (uintptr_t)(mipmappedArray))
    ctf_integer(unsigned int, level, level)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGetMipmappedArrayLevel_exit,
  TP_ARGS(
    hipArray_t *, levelArray,
    hipMipmappedArray_const_t, mipmappedArray,
    unsigned int, level,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, levelArray_val, (uintptr_t)((levelArray ? *levelArray : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpy2D_entry,
  TP_ARGS(
    void *, dst,
    size_t, dpitch,
    const void *, src,
    size_t, spitch,
    size_t, width,
    size_t, height,
    hipMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, dpitch, dpitch)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, spitch, spitch)
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
    ctf_integer(int32_t, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpy2D_exit,
  TP_ARGS(
    void *, dst,
    size_t, dpitch,
    const void *, src,
    size_t, spitch,
    size_t, width,
    size_t, height,
    hipMemcpyKind, kind,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyParam2D_entry,
  TP_ARGS(
    const hip_Memcpy2D *, pCopy
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pCopy, (uintptr_t)(pCopy))
    ctf_sequence_text(uint8_t, pCopy_val, pCopy, size_t, (pCopy ? sizeof(hip_Memcpy2D) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyParam2D_exit,
  TP_ARGS(
    const hip_Memcpy2D *, pCopy,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyParam2DAsync_entry,
  TP_ARGS(
    const hip_Memcpy2D *, pCopy,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pCopy, (uintptr_t)(pCopy))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_sequence_text(uint8_t, pCopy_val, pCopy, size_t, (pCopy ? sizeof(hip_Memcpy2D) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyParam2DAsync_exit,
  TP_ARGS(
    const hip_Memcpy2D *, pCopy,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpy2DAsync_entry,
  TP_ARGS(
    void *, dst,
    size_t, dpitch,
    const void *, src,
    size_t, spitch,
    size_t, width,
    size_t, height,
    hipMemcpyKind, kind,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, dpitch, dpitch)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, spitch, spitch)
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
    ctf_integer(int32_t, kind, kind)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpy2DAsync_exit,
  TP_ARGS(
    void *, dst,
    size_t, dpitch,
    const void *, src,
    size_t, spitch,
    size_t, width,
    size_t, height,
    hipMemcpyKind, kind,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpy2DToArray_entry,
  TP_ARGS(
    hipArray *, dst,
    size_t, wOffset,
    size_t, hOffset,
    const void *, src,
    size_t, spitch,
    size_t, width,
    size_t, height,
    hipMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, wOffset, wOffset)
    ctf_integer(size_t, hOffset, hOffset)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, spitch, spitch)
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
    ctf_integer(int32_t, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpy2DToArray_exit,
  TP_ARGS(
    hipArray *, dst,
    size_t, wOffset,
    size_t, hOffset,
    const void *, src,
    size_t, spitch,
    size_t, width,
    size_t, height,
    hipMemcpyKind, kind,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpy2DToArrayAsync_entry,
  TP_ARGS(
    hipArray *, dst,
    size_t, wOffset,
    size_t, hOffset,
    const void *, src,
    size_t, spitch,
    size_t, width,
    size_t, height,
    hipMemcpyKind, kind,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, wOffset, wOffset)
    ctf_integer(size_t, hOffset, hOffset)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, spitch, spitch)
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
    ctf_integer(int32_t, kind, kind)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpy2DToArrayAsync_exit,
  TP_ARGS(
    hipArray *, dst,
    size_t, wOffset,
    size_t, hOffset,
    const void *, src,
    size_t, spitch,
    size_t, width,
    size_t, height,
    hipMemcpyKind, kind,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyToArray_entry,
  TP_ARGS(
    hipArray *, dst,
    size_t, wOffset,
    size_t, hOffset,
    const void *, src,
    size_t, count,
    hipMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, wOffset, wOffset)
    ctf_integer(size_t, hOffset, hOffset)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, count, count)
    ctf_integer(int32_t, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyToArray_exit,
  TP_ARGS(
    hipArray *, dst,
    size_t, wOffset,
    size_t, hOffset,
    const void *, src,
    size_t, count,
    hipMemcpyKind, kind,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyFromArray_entry,
  TP_ARGS(
    void *, dst,
    hipArray_const_t, srcArray,
    size_t, wOffset,
    size_t, hOffset,
    size_t, count,
    hipMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, srcArray, (uintptr_t)(srcArray))
    ctf_integer(size_t, wOffset, wOffset)
    ctf_integer(size_t, hOffset, hOffset)
    ctf_integer(size_t, count, count)
    ctf_integer(int32_t, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyFromArray_exit,
  TP_ARGS(
    void *, dst,
    hipArray_const_t, srcArray,
    size_t, wOffset,
    size_t, hOffset,
    size_t, count,
    hipMemcpyKind, kind,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpy2DFromArray_entry,
  TP_ARGS(
    void *, dst,
    size_t, dpitch,
    hipArray_const_t, src,
    size_t, wOffset,
    size_t, hOffset,
    size_t, width,
    size_t, height,
    hipMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, dpitch, dpitch)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, wOffset, wOffset)
    ctf_integer(size_t, hOffset, hOffset)
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
    ctf_integer(int32_t, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpy2DFromArray_exit,
  TP_ARGS(
    void *, dst,
    size_t, dpitch,
    hipArray_const_t, src,
    size_t, wOffset,
    size_t, hOffset,
    size_t, width,
    size_t, height,
    hipMemcpyKind, kind,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpy2DFromArrayAsync_entry,
  TP_ARGS(
    void *, dst,
    size_t, dpitch,
    hipArray_const_t, src,
    size_t, wOffset,
    size_t, hOffset,
    size_t, width,
    size_t, height,
    hipMemcpyKind, kind,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, dpitch, dpitch)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, wOffset, wOffset)
    ctf_integer(size_t, hOffset, hOffset)
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
    ctf_integer(int32_t, kind, kind)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpy2DFromArrayAsync_exit,
  TP_ARGS(
    void *, dst,
    size_t, dpitch,
    hipArray_const_t, src,
    size_t, wOffset,
    size_t, hOffset,
    size_t, width,
    size_t, height,
    hipMemcpyKind, kind,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyAtoH_entry,
  TP_ARGS(
    void *, dst,
    hipArray *, srcArray,
    size_t, srcOffset,
    size_t, count
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, srcArray, (uintptr_t)(srcArray))
    ctf_integer(size_t, srcOffset, srcOffset)
    ctf_integer(size_t, count, count)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyAtoH_exit,
  TP_ARGS(
    void *, dst,
    hipArray *, srcArray,
    size_t, srcOffset,
    size_t, count,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyHtoA_entry,
  TP_ARGS(
    hipArray *, dstArray,
    size_t, dstOffset,
    const void *, srcHost,
    size_t, count
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dstArray, (uintptr_t)(dstArray))
    ctf_integer(size_t, dstOffset, dstOffset)
    ctf_integer_hex(uintptr_t, srcHost, (uintptr_t)(srcHost))
    ctf_integer(size_t, count, count)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyHtoA_exit,
  TP_ARGS(
    hipArray *, dstArray,
    size_t, dstOffset,
    const void *, srcHost,
    size_t, count,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpy3D_entry,
  TP_ARGS(
    const struct hipMemcpy3DParms *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(struct hipMemcpy3DParms) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpy3D_exit,
  TP_ARGS(
    const struct hipMemcpy3DParms *, p,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpy3DAsync_entry,
  TP_ARGS(
    const struct hipMemcpy3DParms *, p,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(struct hipMemcpy3DParms) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpy3DAsync_exit,
  TP_ARGS(
    const struct hipMemcpy3DParms *, p,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDrvMemcpy3D_entry,
  TP_ARGS(
    const HIP_MEMCPY3D *, pCopy
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pCopy, (uintptr_t)(pCopy))
    ctf_sequence_text(uint8_t, pCopy_val, pCopy, size_t, (pCopy ? sizeof(HIP_MEMCPY3D) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDrvMemcpy3D_exit,
  TP_ARGS(
    const HIP_MEMCPY3D *, pCopy,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDrvMemcpy3DAsync_entry,
  TP_ARGS(
    const HIP_MEMCPY3D *, pCopy,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pCopy, (uintptr_t)(pCopy))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_sequence_text(uint8_t, pCopy_val, pCopy, size_t, (pCopy ? sizeof(HIP_MEMCPY3D) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDrvMemcpy3DAsync_exit,
  TP_ARGS(
    const HIP_MEMCPY3D *, pCopy,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceCanAccessPeer_entry,
  TP_ARGS(
    int *, canAccessPeer,
    int, deviceId,
    int, peerDeviceId
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, canAccessPeer, (uintptr_t)(canAccessPeer))
    ctf_integer(int, deviceId, deviceId)
    ctf_integer(int, peerDeviceId, peerDeviceId)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceCanAccessPeer_exit,
  TP_ARGS(
    int *, canAccessPeer,
    int, deviceId,
    int, peerDeviceId,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(int, canAccessPeer_val, (canAccessPeer ? *canAccessPeer : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceEnablePeerAccess_entry,
  TP_ARGS(
    int, peerDeviceId,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer(int, peerDeviceId, peerDeviceId)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceEnablePeerAccess_exit,
  TP_ARGS(
    int, peerDeviceId,
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceDisablePeerAccess_entry,
  TP_ARGS(
    int, peerDeviceId
  ),
  TP_FIELDS(
    ctf_integer(int, peerDeviceId, peerDeviceId)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceDisablePeerAccess_exit,
  TP_ARGS(
    int, peerDeviceId,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemGetAddressRange_entry,
  TP_ARGS(
    hipDeviceptr_t *, pbase,
    size_t *, psize,
    hipDeviceptr_t, dptr
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pbase, (uintptr_t)(pbase))
    ctf_integer_hex(uintptr_t, psize, (uintptr_t)(psize))
    ctf_integer_hex(uintptr_t, dptr, (uintptr_t)(dptr))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemGetAddressRange_exit,
  TP_ARGS(
    hipDeviceptr_t *, pbase,
    size_t *, psize,
    hipDeviceptr_t, dptr,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, pbase_val, (uintptr_t)((pbase ? *pbase : 0)))
    ctf_integer(size_t, psize_val, (psize ? *psize : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyPeer_entry,
  TP_ARGS(
    void *, dst,
    int, dstDeviceId,
    const void *, src,
    int, srcDeviceId,
    size_t, sizeBytes
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(int, dstDeviceId, dstDeviceId)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(int, srcDeviceId, srcDeviceId)
    ctf_integer(size_t, sizeBytes, sizeBytes)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyPeer_exit,
  TP_ARGS(
    void *, dst,
    int, dstDeviceId,
    const void *, src,
    int, srcDeviceId,
    size_t, sizeBytes,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyPeerAsync_entry,
  TP_ARGS(
    void *, dst,
    int, dstDeviceId,
    const void *, src,
    int, srcDevice,
    size_t, sizeBytes,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(int, dstDeviceId, dstDeviceId)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(int, srcDevice, srcDevice)
    ctf_integer(size_t, sizeBytes, sizeBytes)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyPeerAsync_exit,
  TP_ARGS(
    void *, dst,
    int, dstDeviceId,
    const void *, src,
    int, srcDevice,
    size_t, sizeBytes,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipCtxCreate_entry,
  TP_ARGS(
    hipCtx_t *, ctx,
    unsigned int, flags,
    hipDevice_t, device
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ctx, (uintptr_t)(ctx))
    ctf_integer(unsigned int, flags, flags)
    ctf_integer(hipDevice_t, device, device)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipCtxCreate_exit,
  TP_ARGS(
    hipCtx_t *, ctx,
    unsigned int, flags,
    hipDevice_t, device,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, ctx_val, (uintptr_t)((ctx ? *ctx : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipCtxDestroy_entry,
  TP_ARGS(
    hipCtx_t, ctx
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ctx, (uintptr_t)(ctx))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipCtxDestroy_exit,
  TP_ARGS(
    hipCtx_t, ctx,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipCtxPopCurrent_entry,
  TP_ARGS(
    hipCtx_t *, ctx
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ctx, (uintptr_t)(ctx))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipCtxPopCurrent_exit,
  TP_ARGS(
    hipCtx_t *, ctx,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, ctx_val, (uintptr_t)((ctx ? *ctx : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipCtxPushCurrent_entry,
  TP_ARGS(
    hipCtx_t, ctx
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ctx, (uintptr_t)(ctx))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipCtxPushCurrent_exit,
  TP_ARGS(
    hipCtx_t, ctx,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipCtxSetCurrent_entry,
  TP_ARGS(
    hipCtx_t, ctx
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ctx, (uintptr_t)(ctx))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipCtxSetCurrent_exit,
  TP_ARGS(
    hipCtx_t, ctx,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipCtxGetCurrent_entry,
  TP_ARGS(
    hipCtx_t *, ctx
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ctx, (uintptr_t)(ctx))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipCtxGetCurrent_exit,
  TP_ARGS(
    hipCtx_t *, ctx,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, ctx_val, (uintptr_t)((ctx ? *ctx : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipCtxGetDevice_entry,
  TP_ARGS(
    hipDevice_t *, device
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, device, (uintptr_t)(device))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipCtxGetDevice_exit,
  TP_ARGS(
    hipDevice_t *, device,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(hipDevice_t, device_val, (device ? *device : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipCtxGetApiVersion_entry,
  TP_ARGS(
    hipCtx_t, ctx,
    int *, apiVersion
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ctx, (uintptr_t)(ctx))
    ctf_integer_hex(uintptr_t, apiVersion, (uintptr_t)(apiVersion))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipCtxGetApiVersion_exit,
  TP_ARGS(
    hipCtx_t, ctx,
    int *, apiVersion,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(int, apiVersion_val, (apiVersion ? *apiVersion : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipCtxGetCacheConfig_entry,
  TP_ARGS(
    hipFuncCache_t *, cacheConfig
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, cacheConfig, (uintptr_t)(cacheConfig))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipCtxGetCacheConfig_exit,
  TP_ARGS(
    hipFuncCache_t *, cacheConfig,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(int32_t, cacheConfig_val, (cacheConfig ? *cacheConfig : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipCtxSetCacheConfig_entry,
  TP_ARGS(
    hipFuncCache_t, cacheConfig
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cacheConfig, cacheConfig)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipCtxSetCacheConfig_exit,
  TP_ARGS(
    hipFuncCache_t, cacheConfig,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipCtxSetSharedMemConfig_entry,
  TP_ARGS(
    hipSharedMemConfig, config
  ),
  TP_FIELDS(
    ctf_integer(int32_t, config, config)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipCtxSetSharedMemConfig_exit,
  TP_ARGS(
    hipSharedMemConfig, config,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipCtxGetSharedMemConfig_entry,
  TP_ARGS(
    hipSharedMemConfig *, pConfig
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pConfig, (uintptr_t)(pConfig))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipCtxGetSharedMemConfig_exit,
  TP_ARGS(
    hipSharedMemConfig *, pConfig,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(int32_t, pConfig_val, (pConfig ? *pConfig : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipCtxSynchronize_entry,
  TP_ARGS(
    void
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipCtxSynchronize_exit,
  TP_ARGS(
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipCtxGetFlags_entry,
  TP_ARGS(
    unsigned int *, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, flags, (uintptr_t)(flags))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipCtxGetFlags_exit,
  TP_ARGS(
    unsigned int *, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(unsigned int, flags_val, (flags ? *flags : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipCtxEnablePeerAccess_entry,
  TP_ARGS(
    hipCtx_t, peerCtx,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, peerCtx, (uintptr_t)(peerCtx))
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipCtxEnablePeerAccess_exit,
  TP_ARGS(
    hipCtx_t, peerCtx,
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipCtxDisablePeerAccess_entry,
  TP_ARGS(
    hipCtx_t, peerCtx
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, peerCtx, (uintptr_t)(peerCtx))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipCtxDisablePeerAccess_exit,
  TP_ARGS(
    hipCtx_t, peerCtx,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDevicePrimaryCtxGetState_entry,
  TP_ARGS(
    hipDevice_t, dev,
    unsigned int *, flags,
    int *, active
  ),
  TP_FIELDS(
    ctf_integer(hipDevice_t, dev, dev)
    ctf_integer_hex(uintptr_t, flags, (uintptr_t)(flags))
    ctf_integer_hex(uintptr_t, active, (uintptr_t)(active))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDevicePrimaryCtxGetState_exit,
  TP_ARGS(
    hipDevice_t, dev,
    unsigned int *, flags,
    int *, active,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(unsigned int, flags_val, (flags ? *flags : 0))
    ctf_integer(int, active_val, (active ? *active : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDevicePrimaryCtxRelease_entry,
  TP_ARGS(
    hipDevice_t, dev
  ),
  TP_FIELDS(
    ctf_integer(hipDevice_t, dev, dev)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDevicePrimaryCtxRelease_exit,
  TP_ARGS(
    hipDevice_t, dev,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDevicePrimaryCtxRetain_entry,
  TP_ARGS(
    hipCtx_t *, pctx,
    hipDevice_t, dev
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pctx, (uintptr_t)(pctx))
    ctf_integer(hipDevice_t, dev, dev)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDevicePrimaryCtxRetain_exit,
  TP_ARGS(
    hipCtx_t *, pctx,
    hipDevice_t, dev,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, pctx_val, (uintptr_t)((pctx ? *pctx : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDevicePrimaryCtxReset_entry,
  TP_ARGS(
    hipDevice_t, dev
  ),
  TP_FIELDS(
    ctf_integer(hipDevice_t, dev, dev)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDevicePrimaryCtxReset_exit,
  TP_ARGS(
    hipDevice_t, dev,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDevicePrimaryCtxSetFlags_entry,
  TP_ARGS(
    hipDevice_t, dev,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer(hipDevice_t, dev, dev)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDevicePrimaryCtxSetFlags_exit,
  TP_ARGS(
    hipDevice_t, dev,
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipModuleLoad_entry,
  TP_ARGS(
    hipModule_t *, module,
    const char *, fname
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, module, (uintptr_t)(module))
    ctf_integer_hex(uintptr_t, fname, (uintptr_t)(fname))
    ctf_string(fname_val, fname)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipModuleLoad_exit,
  TP_ARGS(
    hipModule_t *, module,
    const char *, fname,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, module_val, (uintptr_t)((module ? *module : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipModuleUnload_entry,
  TP_ARGS(
    hipModule_t, module
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, module, (uintptr_t)(module))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipModuleUnload_exit,
  TP_ARGS(
    hipModule_t, module,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipModuleGetFunction_entry,
  TP_ARGS(
    hipFunction_t *, function,
    hipModule_t, module,
    const char *, kname
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, function, (uintptr_t)(function))
    ctf_integer_hex(uintptr_t, module, (uintptr_t)(module))
    ctf_integer_hex(uintptr_t, kname, (uintptr_t)(kname))
    ctf_string(kname_val, kname)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipModuleGetFunction_exit,
  TP_ARGS(
    hipFunction_t *, function,
    hipModule_t, module,
    const char *, kname,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, function_val, (uintptr_t)((function ? *function : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipFuncGetAttributes_entry,
  TP_ARGS(
    struct hipFuncAttributes *, attr,
    const void *, func
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, attr, (uintptr_t)(attr))
    ctf_integer_hex(uintptr_t, func, (uintptr_t)(func))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipFuncGetAttributes_exit,
  TP_ARGS(
    struct hipFuncAttributes *, attr,
    const void *, func,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_sequence_text(uint8_t, attr_val, attr, size_t, (attr ? sizeof(struct hipFuncAttributes) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipFuncGetAttribute_entry,
  TP_ARGS(
    int *, value,
    hipFunction_attribute, attrib,
    hipFunction_t, hfunc
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, value, (uintptr_t)(value))
    ctf_integer(int32_t, attrib, attrib)
    ctf_integer_hex(uintptr_t, hfunc, (uintptr_t)(hfunc))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipFuncGetAttribute_exit,
  TP_ARGS(
    int *, value,
    hipFunction_attribute, attrib,
    hipFunction_t, hfunc,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(int, value_val, (value ? *value : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipModuleGetTexRef_entry,
  TP_ARGS(
    textureReference **, texRef,
    hipModule_t, hmod,
    const char *, name
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, texRef, (uintptr_t)(texRef))
    ctf_integer_hex(uintptr_t, hmod, (uintptr_t)(hmod))
    ctf_integer_hex(uintptr_t, name, (uintptr_t)(name))
    ctf_string(name_val, name)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipModuleGetTexRef_exit,
  TP_ARGS(
    textureReference **, texRef,
    hipModule_t, hmod,
    const char *, name,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, texRef_val, (uintptr_t)((texRef ? *texRef : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipModuleLoadData_entry,
  TP_ARGS(
    hipModule_t *, module,
    const void *, image
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, module, (uintptr_t)(module))
    ctf_integer_hex(uintptr_t, image, (uintptr_t)(image))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipModuleLoadData_exit,
  TP_ARGS(
    hipModule_t *, module,
    const void *, image,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, module_val, (uintptr_t)((module ? *module : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipModuleLoadDataEx_entry,
  TP_ARGS(
    hipModule_t *, module,
    const void *, image,
    unsigned int, numOptions,
    hipJitOption *, options,
    void **, optionValues
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, module, (uintptr_t)(module))
    ctf_integer_hex(uintptr_t, image, (uintptr_t)(image))
    ctf_integer(unsigned int, numOptions, numOptions)
    ctf_integer_hex(uintptr_t, options, (uintptr_t)(options))
    ctf_integer_hex(uintptr_t, optionValues, (uintptr_t)(optionValues))
    ctf_sequence(int32_t, options_vals, options, unsigned int, (options ? numOptions : 0))
    ctf_sequence_hex(uintptr_t, optionValues_vals, optionValues, unsigned int, (optionValues ? numOptions : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipModuleLoadDataEx_exit,
  TP_ARGS(
    hipModule_t *, module,
    const void *, image,
    unsigned int, numOptions,
    hipJitOption *, options,
    void **, optionValues,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, module_val, (uintptr_t)((module ? *module : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipModuleLaunchKernel_entry,
  TP_ARGS(
    hipFunction_t, f,
    unsigned int, gridDimX,
    unsigned int, gridDimY,
    unsigned int, gridDimZ,
    unsigned int, blockDimX,
    unsigned int, blockDimY,
    unsigned int, blockDimZ,
    unsigned int, sharedMemBytes,
    hipStream_t, stream,
    void **, kernelParams,
    void **, extra
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, f, (uintptr_t)(f))
    ctf_integer(unsigned int, gridDimX, gridDimX)
    ctf_integer(unsigned int, gridDimY, gridDimY)
    ctf_integer(unsigned int, gridDimZ, gridDimZ)
    ctf_integer(unsigned int, blockDimX, blockDimX)
    ctf_integer(unsigned int, blockDimY, blockDimY)
    ctf_integer(unsigned int, blockDimZ, blockDimZ)
    ctf_integer(unsigned int, sharedMemBytes, sharedMemBytes)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, kernelParams, (uintptr_t)(kernelParams))
    ctf_integer_hex(uintptr_t, extra, (uintptr_t)(extra))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipModuleLaunchKernel_exit,
  TP_ARGS(
    hipFunction_t, f,
    unsigned int, gridDimX,
    unsigned int, gridDimY,
    unsigned int, gridDimZ,
    unsigned int, blockDimX,
    unsigned int, blockDimY,
    unsigned int, blockDimZ,
    unsigned int, sharedMemBytes,
    hipStream_t, stream,
    void **, kernelParams,
    void **, extra,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipLaunchCooperativeKernel_entry,
  TP_ARGS(
    const void *, f,
    dim3, gridDim,
    dim3, blockDimX,
    void **, kernelParams,
    unsigned int, sharedMemBytes,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, f, (uintptr_t)(f))
    ctf_array_text(uint8_t, gridDim, &gridDim, sizeof(dim3))
    ctf_array_text(uint8_t, blockDimX, &blockDimX, sizeof(dim3))
    ctf_integer_hex(uintptr_t, kernelParams, (uintptr_t)(kernelParams))
    ctf_integer(unsigned int, sharedMemBytes, sharedMemBytes)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipLaunchCooperativeKernel_exit,
  TP_ARGS(
    const void *, f,
    dim3, gridDim,
    dim3, blockDimX,
    void **, kernelParams,
    unsigned int, sharedMemBytes,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipLaunchCooperativeKernelMultiDevice_entry,
  TP_ARGS(
    hipLaunchParams *, launchParamsList,
    int, numDevices,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, launchParamsList, (uintptr_t)(launchParamsList))
    ctf_integer(int, numDevices, numDevices)
    ctf_integer(unsigned int, flags, flags)
    ctf_sequence_text(uint8_t, launchParamsList_vals, launchParamsList, size_t, ((launchParamsList ? (numDevices < 0 ? 0 : (size_t)numDevices) : 0)) * sizeof(hipLaunchParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipLaunchCooperativeKernelMultiDevice_exit,
  TP_ARGS(
    hipLaunchParams *, launchParamsList,
    int, numDevices,
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipExtLaunchMultiKernelMultiDevice_entry,
  TP_ARGS(
    hipLaunchParams *, launchParamsList,
    int, numDevices,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, launchParamsList, (uintptr_t)(launchParamsList))
    ctf_integer(int, numDevices, numDevices)
    ctf_integer(unsigned int, flags, flags)
    ctf_sequence_text(uint8_t, launchParamsList_vals, launchParamsList, size_t, ((launchParamsList ? (numDevices < 0 ? 0 : (size_t)numDevices) : 0)) * sizeof(hipLaunchParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipExtLaunchMultiKernelMultiDevice_exit,
  TP_ARGS(
    hipLaunchParams *, launchParamsList,
    int, numDevices,
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipModuleOccupancyMaxPotentialBlockSize_entry,
  TP_ARGS(
    int *, gridSize,
    int *, blockSize,
    hipFunction_t, f,
    size_t, dynSharedMemPerBlk,
    int, blockSizeLimit
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, gridSize, (uintptr_t)(gridSize))
    ctf_integer_hex(uintptr_t, blockSize, (uintptr_t)(blockSize))
    ctf_integer_hex(uintptr_t, f, (uintptr_t)(f))
    ctf_integer(size_t, dynSharedMemPerBlk, dynSharedMemPerBlk)
    ctf_integer(int, blockSizeLimit, blockSizeLimit)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipModuleOccupancyMaxPotentialBlockSize_exit,
  TP_ARGS(
    int *, gridSize,
    int *, blockSize,
    hipFunction_t, f,
    size_t, dynSharedMemPerBlk,
    int, blockSizeLimit,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(int, gridSize_val, (gridSize ? *gridSize : 0))
    ctf_integer(int, blockSize_val, (blockSize ? *blockSize : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipModuleOccupancyMaxPotentialBlockSizeWithFlags_entry,
  TP_ARGS(
    int *, gridSize,
    int *, blockSize,
    hipFunction_t, f,
    size_t, dynSharedMemPerBlk,
    int, blockSizeLimit,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, gridSize, (uintptr_t)(gridSize))
    ctf_integer_hex(uintptr_t, blockSize, (uintptr_t)(blockSize))
    ctf_integer_hex(uintptr_t, f, (uintptr_t)(f))
    ctf_integer(size_t, dynSharedMemPerBlk, dynSharedMemPerBlk)
    ctf_integer(int, blockSizeLimit, blockSizeLimit)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipModuleOccupancyMaxPotentialBlockSizeWithFlags_exit,
  TP_ARGS(
    int *, gridSize,
    int *, blockSize,
    hipFunction_t, f,
    size_t, dynSharedMemPerBlk,
    int, blockSizeLimit,
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(int, gridSize_val, (gridSize ? *gridSize : 0))
    ctf_integer(int, blockSize_val, (blockSize ? *blockSize : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipModuleOccupancyMaxActiveBlocksPerMultiprocessor_entry,
  TP_ARGS(
    int *, numBlocks,
    hipFunction_t, f,
    int, blockSize,
    size_t, dynSharedMemPerBlk
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, numBlocks, (uintptr_t)(numBlocks))
    ctf_integer_hex(uintptr_t, f, (uintptr_t)(f))
    ctf_integer(int, blockSize, blockSize)
    ctf_integer(size_t, dynSharedMemPerBlk, dynSharedMemPerBlk)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipModuleOccupancyMaxActiveBlocksPerMultiprocessor_exit,
  TP_ARGS(
    int *, numBlocks,
    hipFunction_t, f,
    int, blockSize,
    size_t, dynSharedMemPerBlk,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(int, numBlocks_val, (numBlocks ? *numBlocks : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_entry,
  TP_ARGS(
    int *, numBlocks,
    hipFunction_t, f,
    int, blockSize,
    size_t, dynSharedMemPerBlk,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, numBlocks, (uintptr_t)(numBlocks))
    ctf_integer_hex(uintptr_t, f, (uintptr_t)(f))
    ctf_integer(int, blockSize, blockSize)
    ctf_integer(size_t, dynSharedMemPerBlk, dynSharedMemPerBlk)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_exit,
  TP_ARGS(
    int *, numBlocks,
    hipFunction_t, f,
    int, blockSize,
    size_t, dynSharedMemPerBlk,
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(int, numBlocks_val, (numBlocks ? *numBlocks : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipOccupancyMaxActiveBlocksPerMultiprocessor_entry,
  TP_ARGS(
    int *, numBlocks,
    const void *, f,
    int, blockSize,
    size_t, dynSharedMemPerBlk
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, numBlocks, (uintptr_t)(numBlocks))
    ctf_integer_hex(uintptr_t, f, (uintptr_t)(f))
    ctf_integer(int, blockSize, blockSize)
    ctf_integer(size_t, dynSharedMemPerBlk, dynSharedMemPerBlk)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipOccupancyMaxActiveBlocksPerMultiprocessor_exit,
  TP_ARGS(
    int *, numBlocks,
    const void *, f,
    int, blockSize,
    size_t, dynSharedMemPerBlk,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(int, numBlocks_val, (numBlocks ? *numBlocks : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_entry,
  TP_ARGS(
    int *, numBlocks,
    const void *, f,
    int, blockSize,
    size_t, dynSharedMemPerBlk,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, numBlocks, (uintptr_t)(numBlocks))
    ctf_integer_hex(uintptr_t, f, (uintptr_t)(f))
    ctf_integer(int, blockSize, blockSize)
    ctf_integer(size_t, dynSharedMemPerBlk, dynSharedMemPerBlk)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_exit,
  TP_ARGS(
    int *, numBlocks,
    const void *, f,
    int, blockSize,
    size_t, dynSharedMemPerBlk,
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(int, numBlocks_val, (numBlocks ? *numBlocks : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipOccupancyMaxPotentialBlockSize_entry,
  TP_ARGS(
    int *, gridSize,
    int *, blockSize,
    const void *, f,
    size_t, dynSharedMemPerBlk,
    int, blockSizeLimit
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, gridSize, (uintptr_t)(gridSize))
    ctf_integer_hex(uintptr_t, blockSize, (uintptr_t)(blockSize))
    ctf_integer_hex(uintptr_t, f, (uintptr_t)(f))
    ctf_integer(size_t, dynSharedMemPerBlk, dynSharedMemPerBlk)
    ctf_integer(int, blockSizeLimit, blockSizeLimit)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipOccupancyMaxPotentialBlockSize_exit,
  TP_ARGS(
    int *, gridSize,
    int *, blockSize,
    const void *, f,
    size_t, dynSharedMemPerBlk,
    int, blockSizeLimit,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(int, gridSize_val, (gridSize ? *gridSize : 0))
    ctf_integer(int, blockSize_val, (blockSize ? *blockSize : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipProfilerStart_entry,
  TP_ARGS(
    void
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipProfilerStart_exit,
  TP_ARGS(
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipProfilerStop_entry,
  TP_ARGS(
    void
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipProfilerStop_exit,
  TP_ARGS(
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipConfigureCall_entry,
  TP_ARGS(
    dim3, gridDim,
    dim3, blockDim,
    size_t, sharedMem,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_array_text(uint8_t, gridDim, &gridDim, sizeof(dim3))
    ctf_array_text(uint8_t, blockDim, &blockDim, sizeof(dim3))
    ctf_integer(size_t, sharedMem, sharedMem)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipConfigureCall_exit,
  TP_ARGS(
    dim3, gridDim,
    dim3, blockDim,
    size_t, sharedMem,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipSetupArgument_entry,
  TP_ARGS(
    const void *, arg,
    size_t, size,
    size_t, offset
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, arg, (uintptr_t)(arg))
    ctf_integer(size_t, size, size)
    ctf_integer(size_t, offset, offset)
    ctf_sequence_text(uint8_t, arg_vals, arg, size_t, ((arg ? size : 0)) * sizeof(uint8_t))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipSetupArgument_exit,
  TP_ARGS(
    const void *, arg,
    size_t, size,
    size_t, offset,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipLaunchByPtr_entry,
  TP_ARGS(
    const void *, func
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, func, (uintptr_t)(func))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipLaunchByPtr_exit,
  TP_ARGS(
    const void *, func,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  __hipPushCallConfiguration_entry,
  TP_ARGS(
    dim3, gridDim,
    dim3, blockDim,
    size_t, sharedMem,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_array_text(uint8_t, gridDim, &gridDim, sizeof(dim3))
    ctf_array_text(uint8_t, blockDim, &blockDim, sizeof(dim3))
    ctf_integer(size_t, sharedMem, sharedMem)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  __hipPushCallConfiguration_exit,
  TP_ARGS(
    dim3, gridDim,
    dim3, blockDim,
    size_t, sharedMem,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  __hipPopCallConfiguration_entry,
  TP_ARGS(
    dim3 *, gridDim,
    dim3 *, blockDim,
    size_t *, sharedMem,
    hipStream_t *, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, gridDim, (uintptr_t)(gridDim))
    ctf_integer_hex(uintptr_t, blockDim, (uintptr_t)(blockDim))
    ctf_integer_hex(uintptr_t, sharedMem, (uintptr_t)(sharedMem))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  __hipPopCallConfiguration_exit,
  TP_ARGS(
    dim3 *, gridDim,
    dim3 *, blockDim,
    size_t *, sharedMem,
    hipStream_t *, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_sequence_text(uint8_t, gridDim_val, gridDim, size_t, (gridDim ? sizeof(dim3) : 0))
    ctf_sequence_text(uint8_t, blockDim_val, blockDim, size_t, (blockDim ? sizeof(dim3) : 0))
    ctf_integer(size_t, sharedMem_val, (sharedMem ? *sharedMem : 0))
    ctf_integer_hex(uintptr_t, stream_val, (uintptr_t)((stream ? *stream : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipLaunchKernel_entry,
  TP_ARGS(
    const void *, function_address,
    dim3, numBlocks,
    dim3, dimBlocks,
    void **, args,
    size_t, sharedMemBytes,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, function_address, (uintptr_t)(function_address))
    ctf_array_text(uint8_t, numBlocks, &numBlocks, sizeof(dim3))
    ctf_array_text(uint8_t, dimBlocks, &dimBlocks, sizeof(dim3))
    ctf_integer_hex(uintptr_t, args, (uintptr_t)(args))
    ctf_integer(size_t, sharedMemBytes, sharedMemBytes)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipLaunchKernel_exit,
  TP_ARGS(
    const void *, function_address,
    dim3, numBlocks,
    dim3, dimBlocks,
    void **, args,
    size_t, sharedMemBytes,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDrvMemcpy2DUnaligned_entry,
  TP_ARGS(
    const hip_Memcpy2D *, pCopy
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pCopy, (uintptr_t)(pCopy))
    ctf_sequence_text(uint8_t, pCopy_val, pCopy, size_t, (pCopy ? sizeof(hip_Memcpy2D) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDrvMemcpy2DUnaligned_exit,
  TP_ARGS(
    const hip_Memcpy2D *, pCopy,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipExtLaunchKernel_entry,
  TP_ARGS(
    const void *, function_address,
    dim3, numBlocks,
    dim3, dimBlocks,
    void **, args,
    size_t, sharedMemBytes,
    hipStream_t, stream,
    hipEvent_t, startEvent,
    hipEvent_t, stopEvent,
    int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, function_address, (uintptr_t)(function_address))
    ctf_array_text(uint8_t, numBlocks, &numBlocks, sizeof(dim3))
    ctf_array_text(uint8_t, dimBlocks, &dimBlocks, sizeof(dim3))
    ctf_integer_hex(uintptr_t, args, (uintptr_t)(args))
    ctf_integer(size_t, sharedMemBytes, sharedMemBytes)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, startEvent, (uintptr_t)(startEvent))
    ctf_integer_hex(uintptr_t, stopEvent, (uintptr_t)(stopEvent))
    ctf_integer(int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipExtLaunchKernel_exit,
  TP_ARGS(
    const void *, function_address,
    dim3, numBlocks,
    dim3, dimBlocks,
    void **, args,
    size_t, sharedMemBytes,
    hipStream_t, stream,
    hipEvent_t, startEvent,
    hipEvent_t, stopEvent,
    int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipBindTextureToMipmappedArray_entry,
  TP_ARGS(
    const textureReference *, tex,
    hipMipmappedArray_const_t, mipmappedArray,
    const hipChannelFormatDesc *, desc
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, tex, (uintptr_t)(tex))
    ctf_integer_hex(uintptr_t, mipmappedArray, (uintptr_t)(mipmappedArray))
    ctf_integer_hex(uintptr_t, desc, (uintptr_t)(desc))
    ctf_sequence_text(uint8_t, desc_val, desc, size_t, (desc ? sizeof(hipChannelFormatDesc) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipBindTextureToMipmappedArray_exit,
  TP_ARGS(
    const textureReference *, tex,
    hipMipmappedArray_const_t, mipmappedArray,
    const hipChannelFormatDesc *, desc,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipCreateTextureObject_entry,
  TP_ARGS(
    hipTextureObject_t *, pTexObject,
    const hipResourceDesc *, pResDesc,
    const hipTextureDesc *, pTexDesc,
    const struct hipResourceViewDesc *, pResViewDesc
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pTexObject, (uintptr_t)(pTexObject))
    ctf_integer_hex(uintptr_t, pResDesc, (uintptr_t)(pResDesc))
    ctf_integer_hex(uintptr_t, pTexDesc, (uintptr_t)(pTexDesc))
    ctf_integer_hex(uintptr_t, pResViewDesc, (uintptr_t)(pResViewDesc))
    ctf_sequence_text(uint8_t, pResDesc_val, pResDesc, size_t, (pResDesc ? sizeof(hipResourceDesc) : 0))
    ctf_sequence_text(uint8_t, pTexDesc_val, pTexDesc, size_t, (pTexDesc ? sizeof(hipTextureDesc) : 0))
    ctf_sequence_text(uint8_t, pResViewDesc_val, pResViewDesc, size_t, (pResViewDesc ? sizeof(struct hipResourceViewDesc) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipCreateTextureObject_exit,
  TP_ARGS(
    hipTextureObject_t *, pTexObject,
    const hipResourceDesc *, pResDesc,
    const hipTextureDesc *, pTexDesc,
    const struct hipResourceViewDesc *, pResViewDesc,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, pTexObject_val, (uintptr_t)((pTexObject ? *pTexObject : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDestroyTextureObject_entry,
  TP_ARGS(
    hipTextureObject_t, textureObject
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, textureObject, (uintptr_t)(textureObject))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDestroyTextureObject_exit,
  TP_ARGS(
    hipTextureObject_t, textureObject,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGetChannelDesc_entry,
  TP_ARGS(
    hipChannelFormatDesc *, desc,
    hipArray_const_t, array
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, desc, (uintptr_t)(desc))
    ctf_integer_hex(uintptr_t, array, (uintptr_t)(array))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGetChannelDesc_exit,
  TP_ARGS(
    hipChannelFormatDesc *, desc,
    hipArray_const_t, array,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_sequence_text(uint8_t, desc_val, desc, size_t, (desc ? sizeof(hipChannelFormatDesc) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGetTextureObjectResourceDesc_entry,
  TP_ARGS(
    hipResourceDesc *, pResDesc,
    hipTextureObject_t, textureObject
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pResDesc, (uintptr_t)(pResDesc))
    ctf_integer_hex(uintptr_t, textureObject, (uintptr_t)(textureObject))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGetTextureObjectResourceDesc_exit,
  TP_ARGS(
    hipResourceDesc *, pResDesc,
    hipTextureObject_t, textureObject,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_sequence_text(uint8_t, pResDesc_val, pResDesc, size_t, (pResDesc ? sizeof(hipResourceDesc) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGetTextureObjectResourceViewDesc_entry,
  TP_ARGS(
    struct hipResourceViewDesc *, pResViewDesc,
    hipTextureObject_t, textureObject
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pResViewDesc, (uintptr_t)(pResViewDesc))
    ctf_integer_hex(uintptr_t, textureObject, (uintptr_t)(textureObject))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGetTextureObjectResourceViewDesc_exit,
  TP_ARGS(
    struct hipResourceViewDesc *, pResViewDesc,
    hipTextureObject_t, textureObject,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_sequence_text(uint8_t, pResViewDesc_val, pResViewDesc, size_t, (pResViewDesc ? sizeof(struct hipResourceViewDesc) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGetTextureObjectTextureDesc_entry,
  TP_ARGS(
    hipTextureDesc *, pTexDesc,
    hipTextureObject_t, textureObject
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pTexDesc, (uintptr_t)(pTexDesc))
    ctf_integer_hex(uintptr_t, textureObject, (uintptr_t)(textureObject))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGetTextureObjectTextureDesc_exit,
  TP_ARGS(
    hipTextureDesc *, pTexDesc,
    hipTextureObject_t, textureObject,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_sequence_text(uint8_t, pTexDesc_val, pTexDesc, size_t, (pTexDesc ? sizeof(hipTextureDesc) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexObjectCreate_entry,
  TP_ARGS(
    hipTextureObject_t *, pTexObject,
    const HIP_RESOURCE_DESC *, pResDesc,
    const HIP_TEXTURE_DESC *, pTexDesc,
    const HIP_RESOURCE_VIEW_DESC *, pResViewDesc
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pTexObject, (uintptr_t)(pTexObject))
    ctf_integer_hex(uintptr_t, pResDesc, (uintptr_t)(pResDesc))
    ctf_integer_hex(uintptr_t, pTexDesc, (uintptr_t)(pTexDesc))
    ctf_integer_hex(uintptr_t, pResViewDesc, (uintptr_t)(pResViewDesc))
    ctf_sequence_text(uint8_t, pResDesc_val, pResDesc, size_t, (pResDesc ? sizeof(HIP_RESOURCE_DESC) : 0))
    ctf_sequence_text(uint8_t, pTexDesc_val, pTexDesc, size_t, (pTexDesc ? sizeof(HIP_TEXTURE_DESC) : 0))
    ctf_sequence_text(uint8_t, pResViewDesc_val, pResViewDesc, size_t, (pResViewDesc ? sizeof(HIP_RESOURCE_VIEW_DESC) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexObjectCreate_exit,
  TP_ARGS(
    hipTextureObject_t *, pTexObject,
    const HIP_RESOURCE_DESC *, pResDesc,
    const HIP_TEXTURE_DESC *, pTexDesc,
    const HIP_RESOURCE_VIEW_DESC *, pResViewDesc,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, pTexObject_val, (uintptr_t)((pTexObject ? *pTexObject : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexObjectDestroy_entry,
  TP_ARGS(
    hipTextureObject_t, texObject
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, texObject, (uintptr_t)(texObject))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexObjectDestroy_exit,
  TP_ARGS(
    hipTextureObject_t, texObject,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexObjectGetResourceDesc_entry,
  TP_ARGS(
    HIP_RESOURCE_DESC *, pResDesc,
    hipTextureObject_t, texObject
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pResDesc, (uintptr_t)(pResDesc))
    ctf_integer_hex(uintptr_t, texObject, (uintptr_t)(texObject))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexObjectGetResourceDesc_exit,
  TP_ARGS(
    HIP_RESOURCE_DESC *, pResDesc,
    hipTextureObject_t, texObject,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_sequence_text(uint8_t, pResDesc_val, pResDesc, size_t, (pResDesc ? sizeof(HIP_RESOURCE_DESC) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexObjectGetResourceViewDesc_entry,
  TP_ARGS(
    HIP_RESOURCE_VIEW_DESC *, pResViewDesc,
    hipTextureObject_t, texObject
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pResViewDesc, (uintptr_t)(pResViewDesc))
    ctf_integer_hex(uintptr_t, texObject, (uintptr_t)(texObject))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexObjectGetResourceViewDesc_exit,
  TP_ARGS(
    HIP_RESOURCE_VIEW_DESC *, pResViewDesc,
    hipTextureObject_t, texObject,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_sequence_text(uint8_t, pResViewDesc_val, pResViewDesc, size_t, (pResViewDesc ? sizeof(HIP_RESOURCE_VIEW_DESC) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexObjectGetTextureDesc_entry,
  TP_ARGS(
    HIP_TEXTURE_DESC *, pTexDesc,
    hipTextureObject_t, texObject
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pTexDesc, (uintptr_t)(pTexDesc))
    ctf_integer_hex(uintptr_t, texObject, (uintptr_t)(texObject))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexObjectGetTextureDesc_exit,
  TP_ARGS(
    HIP_TEXTURE_DESC *, pTexDesc,
    hipTextureObject_t, texObject,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_sequence_text(uint8_t, pTexDesc_val, pTexDesc, size_t, (pTexDesc ? sizeof(HIP_TEXTURE_DESC) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGetTextureReference_entry,
  TP_ARGS(
    const textureReference **, texref,
    const void *, symbol
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, texref, (uintptr_t)(texref))
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGetTextureReference_exit,
  TP_ARGS(
    const textureReference **, texref,
    const void *, symbol,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, texref_val, (uintptr_t)((texref ? *texref : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefSetAddressMode_entry,
  TP_ARGS(
    textureReference *, texRef,
    int, dim,
    enum hipTextureAddressMode, am
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, texRef, (uintptr_t)(texRef))
    ctf_integer(int, dim, dim)
    ctf_integer(enum hipTextureAddressMode, am, am)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefSetAddressMode_exit,
  TP_ARGS(
    textureReference *, texRef,
    int, dim,
    enum hipTextureAddressMode, am,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefSetArray_entry,
  TP_ARGS(
    textureReference *, tex,
    hipArray_const_t, array,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, tex, (uintptr_t)(tex))
    ctf_integer_hex(uintptr_t, array, (uintptr_t)(array))
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefSetArray_exit,
  TP_ARGS(
    textureReference *, tex,
    hipArray_const_t, array,
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefSetFilterMode_entry,
  TP_ARGS(
    textureReference *, texRef,
    enum hipTextureFilterMode, fm
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, texRef, (uintptr_t)(texRef))
    ctf_integer(enum hipTextureFilterMode, fm, fm)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefSetFilterMode_exit,
  TP_ARGS(
    textureReference *, texRef,
    enum hipTextureFilterMode, fm,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefSetFlags_entry,
  TP_ARGS(
    textureReference *, texRef,
    unsigned int, Flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, texRef, (uintptr_t)(texRef))
    ctf_integer(unsigned int, Flags, Flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefSetFlags_exit,
  TP_ARGS(
    textureReference *, texRef,
    unsigned int, Flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefSetFormat_entry,
  TP_ARGS(
    textureReference *, texRef,
    hipArray_Format, fmt,
    int, NumPackedComponents
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, texRef, (uintptr_t)(texRef))
    ctf_integer(int32_t, fmt, fmt)
    ctf_integer(int, NumPackedComponents, NumPackedComponents)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefSetFormat_exit,
  TP_ARGS(
    textureReference *, texRef,
    hipArray_Format, fmt,
    int, NumPackedComponents,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipBindTexture_entry,
  TP_ARGS(
    size_t *, offset,
    const textureReference *, tex,
    const void *, devPtr,
    const hipChannelFormatDesc *, desc,
    size_t, size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, offset, (uintptr_t)(offset))
    ctf_integer_hex(uintptr_t, tex, (uintptr_t)(tex))
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
    ctf_integer_hex(uintptr_t, desc, (uintptr_t)(desc))
    ctf_integer(size_t, size, size)
    ctf_sequence_text(uint8_t, desc_val, desc, size_t, (desc ? sizeof(hipChannelFormatDesc) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipBindTexture_exit,
  TP_ARGS(
    size_t *, offset,
    const textureReference *, tex,
    const void *, devPtr,
    const hipChannelFormatDesc *, desc,
    size_t, size,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(size_t, offset_val, (offset ? *offset : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipBindTexture2D_entry,
  TP_ARGS(
    size_t *, offset,
    const textureReference *, tex,
    const void *, devPtr,
    const hipChannelFormatDesc *, desc,
    size_t, width,
    size_t, height,
    size_t, pitch
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, offset, (uintptr_t)(offset))
    ctf_integer_hex(uintptr_t, tex, (uintptr_t)(tex))
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
    ctf_integer_hex(uintptr_t, desc, (uintptr_t)(desc))
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
    ctf_integer(size_t, pitch, pitch)
    ctf_sequence_text(uint8_t, desc_val, desc, size_t, (desc ? sizeof(hipChannelFormatDesc) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipBindTexture2D_exit,
  TP_ARGS(
    size_t *, offset,
    const textureReference *, tex,
    const void *, devPtr,
    const hipChannelFormatDesc *, desc,
    size_t, width,
    size_t, height,
    size_t, pitch,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(size_t, offset_val, (offset ? *offset : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipBindTextureToArray_entry,
  TP_ARGS(
    const textureReference *, tex,
    hipArray_const_t, array,
    const hipChannelFormatDesc *, desc
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, tex, (uintptr_t)(tex))
    ctf_integer_hex(uintptr_t, array, (uintptr_t)(array))
    ctf_integer_hex(uintptr_t, desc, (uintptr_t)(desc))
    ctf_sequence_text(uint8_t, desc_val, desc, size_t, (desc ? sizeof(hipChannelFormatDesc) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipBindTextureToArray_exit,
  TP_ARGS(
    const textureReference *, tex,
    hipArray_const_t, array,
    const hipChannelFormatDesc *, desc,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGetTextureAlignmentOffset_entry,
  TP_ARGS(
    size_t *, offset,
    const textureReference *, texref
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, offset, (uintptr_t)(offset))
    ctf_integer_hex(uintptr_t, texref, (uintptr_t)(texref))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGetTextureAlignmentOffset_exit,
  TP_ARGS(
    size_t *, offset,
    const textureReference *, texref,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(size_t, offset_val, (offset ? *offset : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipUnbindTexture_entry,
  TP_ARGS(
    const textureReference *, tex
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, tex, (uintptr_t)(tex))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipUnbindTexture_exit,
  TP_ARGS(
    const textureReference *, tex,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefGetAddress_entry,
  TP_ARGS(
    hipDeviceptr_t *, dev_ptr,
    const textureReference *, texRef
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dev_ptr, (uintptr_t)(dev_ptr))
    ctf_integer_hex(uintptr_t, texRef, (uintptr_t)(texRef))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefGetAddress_exit,
  TP_ARGS(
    hipDeviceptr_t *, dev_ptr,
    const textureReference *, texRef,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, dev_ptr_val, (uintptr_t)((dev_ptr ? *dev_ptr : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefGetAddressMode_entry,
  TP_ARGS(
    enum hipTextureAddressMode *, pam,
    const textureReference *, texRef,
    int, dim
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pam, (uintptr_t)(pam))
    ctf_integer_hex(uintptr_t, texRef, (uintptr_t)(texRef))
    ctf_integer(int, dim, dim)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefGetAddressMode_exit,
  TP_ARGS(
    enum hipTextureAddressMode *, pam,
    const textureReference *, texRef,
    int, dim,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(enum hipTextureAddressMode, pam_val, (pam ? *pam : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefGetFilterMode_entry,
  TP_ARGS(
    enum hipTextureFilterMode *, pfm,
    const textureReference *, texRef
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pfm, (uintptr_t)(pfm))
    ctf_integer_hex(uintptr_t, texRef, (uintptr_t)(texRef))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefGetFilterMode_exit,
  TP_ARGS(
    enum hipTextureFilterMode *, pfm,
    const textureReference *, texRef,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(enum hipTextureFilterMode, pfm_val, (pfm ? *pfm : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefGetFlags_entry,
  TP_ARGS(
    unsigned int *, pFlags,
    const textureReference *, texRef
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pFlags, (uintptr_t)(pFlags))
    ctf_integer_hex(uintptr_t, texRef, (uintptr_t)(texRef))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefGetFlags_exit,
  TP_ARGS(
    unsigned int *, pFlags,
    const textureReference *, texRef,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(unsigned int, pFlags_val, (pFlags ? *pFlags : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefGetFormat_entry,
  TP_ARGS(
    hipArray_Format *, pFormat,
    int *, pNumChannels,
    const textureReference *, texRef
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pFormat, (uintptr_t)(pFormat))
    ctf_integer_hex(uintptr_t, pNumChannels, (uintptr_t)(pNumChannels))
    ctf_integer_hex(uintptr_t, texRef, (uintptr_t)(texRef))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefGetFormat_exit,
  TP_ARGS(
    hipArray_Format *, pFormat,
    int *, pNumChannels,
    const textureReference *, texRef,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(int32_t, pFormat_val, (pFormat ? *pFormat : 0))
    ctf_integer(int, pNumChannels_val, (pNumChannels ? *pNumChannels : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefGetMaxAnisotropy_entry,
  TP_ARGS(
    int *, pmaxAnsio,
    const textureReference *, texRef
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pmaxAnsio, (uintptr_t)(pmaxAnsio))
    ctf_integer_hex(uintptr_t, texRef, (uintptr_t)(texRef))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefGetMaxAnisotropy_exit,
  TP_ARGS(
    int *, pmaxAnsio,
    const textureReference *, texRef,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(int, pmaxAnsio_val, (pmaxAnsio ? *pmaxAnsio : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefGetMipmapFilterMode_entry,
  TP_ARGS(
    enum hipTextureFilterMode *, pfm,
    const textureReference *, texRef
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pfm, (uintptr_t)(pfm))
    ctf_integer_hex(uintptr_t, texRef, (uintptr_t)(texRef))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefGetMipmapFilterMode_exit,
  TP_ARGS(
    enum hipTextureFilterMode *, pfm,
    const textureReference *, texRef,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(enum hipTextureFilterMode, pfm_val, (pfm ? *pfm : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefGetMipmapLevelBias_entry,
  TP_ARGS(
    float *, pbias,
    const textureReference *, texRef
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pbias, (uintptr_t)(pbias))
    ctf_integer_hex(uintptr_t, texRef, (uintptr_t)(texRef))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefGetMipmapLevelBias_exit,
  TP_ARGS(
    float *, pbias,
    const textureReference *, texRef,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_float(float, pbias_val, (pbias ? *pbias : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefGetMipmapLevelClamp_entry,
  TP_ARGS(
    float *, pminMipmapLevelClamp,
    float *, pmaxMipmapLevelClamp,
    const textureReference *, texRef
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pminMipmapLevelClamp, (uintptr_t)(pminMipmapLevelClamp))
    ctf_integer_hex(uintptr_t, pmaxMipmapLevelClamp, (uintptr_t)(pmaxMipmapLevelClamp))
    ctf_integer_hex(uintptr_t, texRef, (uintptr_t)(texRef))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefGetMipmapLevelClamp_exit,
  TP_ARGS(
    float *, pminMipmapLevelClamp,
    float *, pmaxMipmapLevelClamp,
    const textureReference *, texRef,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_float(float, pminMipmapLevelClamp_val, (pminMipmapLevelClamp ? *pminMipmapLevelClamp : 0))
    ctf_float(float, pmaxMipmapLevelClamp_val, (pmaxMipmapLevelClamp ? *pmaxMipmapLevelClamp : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefGetMipMappedArray_entry,
  TP_ARGS(
    hipMipmappedArray_t *, pArray,
    const textureReference *, texRef
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pArray, (uintptr_t)(pArray))
    ctf_integer_hex(uintptr_t, texRef, (uintptr_t)(texRef))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefGetMipMappedArray_exit,
  TP_ARGS(
    hipMipmappedArray_t *, pArray,
    const textureReference *, texRef,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, pArray_val, (uintptr_t)((pArray ? *pArray : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefSetAddress_entry,
  TP_ARGS(
    size_t *, ByteOffset,
    textureReference *, texRef,
    hipDeviceptr_t, dptr,
    size_t, bytes
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ByteOffset, (uintptr_t)(ByteOffset))
    ctf_integer_hex(uintptr_t, texRef, (uintptr_t)(texRef))
    ctf_integer_hex(uintptr_t, dptr, (uintptr_t)(dptr))
    ctf_integer(size_t, bytes, bytes)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefSetAddress_exit,
  TP_ARGS(
    size_t *, ByteOffset,
    textureReference *, texRef,
    hipDeviceptr_t, dptr,
    size_t, bytes,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(size_t, ByteOffset_val, (ByteOffset ? *ByteOffset : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefSetAddress2D_entry,
  TP_ARGS(
    textureReference *, texRef,
    const HIP_ARRAY_DESCRIPTOR *, desc,
    hipDeviceptr_t, dptr,
    size_t, Pitch
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, texRef, (uintptr_t)(texRef))
    ctf_integer_hex(uintptr_t, desc, (uintptr_t)(desc))
    ctf_integer_hex(uintptr_t, dptr, (uintptr_t)(dptr))
    ctf_integer(size_t, Pitch, Pitch)
    ctf_sequence_text(uint8_t, desc_val, desc, size_t, (desc ? sizeof(HIP_ARRAY_DESCRIPTOR) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefSetAddress2D_exit,
  TP_ARGS(
    textureReference *, texRef,
    const HIP_ARRAY_DESCRIPTOR *, desc,
    hipDeviceptr_t, dptr,
    size_t, Pitch,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefSetMaxAnisotropy_entry,
  TP_ARGS(
    textureReference *, texRef,
    unsigned int, maxAniso
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, texRef, (uintptr_t)(texRef))
    ctf_integer(unsigned int, maxAniso, maxAniso)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefSetMaxAnisotropy_exit,
  TP_ARGS(
    textureReference *, texRef,
    unsigned int, maxAniso,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefSetBorderColor_entry,
  TP_ARGS(
    textureReference *, texRef,
    float *, pBorderColor
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, texRef, (uintptr_t)(texRef))
    ctf_integer_hex(uintptr_t, pBorderColor, (uintptr_t)(pBorderColor))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefSetBorderColor_exit,
  TP_ARGS(
    textureReference *, texRef,
    float *, pBorderColor,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefSetMipmapFilterMode_entry,
  TP_ARGS(
    textureReference *, texRef,
    enum hipTextureFilterMode, fm
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, texRef, (uintptr_t)(texRef))
    ctf_integer(enum hipTextureFilterMode, fm, fm)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefSetMipmapFilterMode_exit,
  TP_ARGS(
    textureReference *, texRef,
    enum hipTextureFilterMode, fm,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefSetMipmapLevelBias_entry,
  TP_ARGS(
    textureReference *, texRef,
    float, bias
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, texRef, (uintptr_t)(texRef))
    ctf_float(float, bias, bias)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefSetMipmapLevelBias_exit,
  TP_ARGS(
    textureReference *, texRef,
    float, bias,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefSetMipmapLevelClamp_entry,
  TP_ARGS(
    textureReference *, texRef,
    float, minMipMapLevelClamp,
    float, maxMipMapLevelClamp
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, texRef, (uintptr_t)(texRef))
    ctf_float(float, minMipMapLevelClamp, minMipMapLevelClamp)
    ctf_float(float, maxMipMapLevelClamp, maxMipMapLevelClamp)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefSetMipmapLevelClamp_exit,
  TP_ARGS(
    textureReference *, texRef,
    float, minMipMapLevelClamp,
    float, maxMipMapLevelClamp,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefSetMipmappedArray_entry,
  TP_ARGS(
    textureReference *, texRef,
    struct hipMipmappedArray *, mipmappedArray,
    unsigned int, Flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, texRef, (uintptr_t)(texRef))
    ctf_integer_hex(uintptr_t, mipmappedArray, (uintptr_t)(mipmappedArray))
    ctf_integer(unsigned int, Flags, Flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipTexRefSetMipmappedArray_exit,
  TP_ARGS(
    textureReference *, texRef,
    struct hipMipmappedArray *, mipmappedArray,
    unsigned int, Flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMipmappedArrayCreate_entry,
  TP_ARGS(
    hipMipmappedArray_t *, pHandle,
    HIP_ARRAY3D_DESCRIPTOR *, pMipmappedArrayDesc,
    unsigned int, numMipmapLevels
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pHandle, (uintptr_t)(pHandle))
    ctf_integer_hex(uintptr_t, pMipmappedArrayDesc, (uintptr_t)(pMipmappedArrayDesc))
    ctf_integer(unsigned int, numMipmapLevels, numMipmapLevels)
    ctf_sequence_text(uint8_t, pMipmappedArrayDesc_val, pMipmappedArrayDesc, size_t, (pMipmappedArrayDesc ? sizeof(HIP_ARRAY3D_DESCRIPTOR) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMipmappedArrayCreate_exit,
  TP_ARGS(
    hipMipmappedArray_t *, pHandle,
    HIP_ARRAY3D_DESCRIPTOR *, pMipmappedArrayDesc,
    unsigned int, numMipmapLevels,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, pHandle_val, (uintptr_t)((pHandle ? *pHandle : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMipmappedArrayDestroy_entry,
  TP_ARGS(
    hipMipmappedArray_t, hMipmappedArray
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hMipmappedArray, (uintptr_t)(hMipmappedArray))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMipmappedArrayDestroy_exit,
  TP_ARGS(
    hipMipmappedArray_t, hMipmappedArray,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMipmappedArrayGetLevel_entry,
  TP_ARGS(
    hipArray_t *, pLevelArray,
    hipMipmappedArray_t, hMipMappedArray,
    unsigned int, level
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pLevelArray, (uintptr_t)(pLevelArray))
    ctf_integer_hex(uintptr_t, hMipMappedArray, (uintptr_t)(hMipMappedArray))
    ctf_integer(unsigned int, level, level)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMipmappedArrayGetLevel_exit,
  TP_ARGS(
    hipArray_t *, pLevelArray,
    hipMipmappedArray_t, hMipMappedArray,
    unsigned int, level,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, pLevelArray_val, (uintptr_t)((pLevelArray ? *pLevelArray : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipApiName_entry,
  TP_ARGS(
    uint32_t, id
  ),
  TP_FIELDS(
    ctf_integer(uint32_t, id, id)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipApiName_exit,
  TP_ARGS(
    uint32_t, id,
    const char *, hipResult
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hipResult, (uintptr_t)(hipResult))
    ctf_string(hipResult_val, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipKernelNameRef_entry,
  TP_ARGS(
    const hipFunction_t, f
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, f, (uintptr_t)(f))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipKernelNameRef_exit,
  TP_ARGS(
    const hipFunction_t, f,
    const char *, hipResult
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hipResult, (uintptr_t)(hipResult))
    ctf_string(hipResult_val, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipKernelNameRefByPtr_entry,
  TP_ARGS(
    const void *, hostFunction,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hostFunction, (uintptr_t)(hostFunction))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipKernelNameRefByPtr_exit,
  TP_ARGS(
    const void *, hostFunction,
    hipStream_t, stream,
    const char *, hipResult
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hipResult, (uintptr_t)(hipResult))
    ctf_string(hipResult_val, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGetStreamDeviceId_entry,
  TP_ARGS(
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGetStreamDeviceId_exit,
  TP_ARGS(
    hipStream_t, stream,
    int, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamBeginCapture_entry,
  TP_ARGS(
    hipStream_t, stream,
    hipStreamCaptureMode, mode
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer(int32_t, mode, mode)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamBeginCapture_exit,
  TP_ARGS(
    hipStream_t, stream,
    hipStreamCaptureMode, mode,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamEndCapture_entry,
  TP_ARGS(
    hipStream_t, stream,
    hipGraph_t *, pGraph
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, pGraph, (uintptr_t)(pGraph))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamEndCapture_exit,
  TP_ARGS(
    hipStream_t, stream,
    hipGraph_t *, pGraph,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, pGraph_val, (uintptr_t)((pGraph ? *pGraph : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamGetCaptureInfo_entry,
  TP_ARGS(
    hipStream_t, stream,
    hipStreamCaptureStatus *, pCaptureStatus,
    unsigned long long int *, pId
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, pCaptureStatus, (uintptr_t)(pCaptureStatus))
    ctf_integer_hex(uintptr_t, pId, (uintptr_t)(pId))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamGetCaptureInfo_exit,
  TP_ARGS(
    hipStream_t, stream,
    hipStreamCaptureStatus *, pCaptureStatus,
    unsigned long long int *, pId,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(int32_t, pCaptureStatus_val, (pCaptureStatus ? *pCaptureStatus : 0))
    ctf_integer(unsigned long long int, pId_val, (pId ? *pId : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamGetCaptureInfo_v2_entry,
  TP_ARGS(
    hipStream_t, stream,
    hipStreamCaptureStatus *, captureStatus_out,
    unsigned long long int *, id_out,
    hipGraph_t *, graph_out,
    const hipGraphNode_t **, dependencies_out,
    size_t *, numDependencies_out
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, captureStatus_out, (uintptr_t)(captureStatus_out))
    ctf_integer_hex(uintptr_t, id_out, (uintptr_t)(id_out))
    ctf_integer_hex(uintptr_t, graph_out, (uintptr_t)(graph_out))
    ctf_integer_hex(uintptr_t, dependencies_out, (uintptr_t)(dependencies_out))
    ctf_integer_hex(uintptr_t, numDependencies_out, (uintptr_t)(numDependencies_out))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamGetCaptureInfo_v2_exit,
  TP_ARGS(
    hipStream_t, stream,
    hipStreamCaptureStatus *, captureStatus_out,
    unsigned long long int *, id_out,
    hipGraph_t *, graph_out,
    const hipGraphNode_t **, dependencies_out,
    size_t *, numDependencies_out,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(int32_t, captureStatus_out_val, (captureStatus_out ? *captureStatus_out : 0))
    ctf_integer(unsigned long long int, id_out_val, (id_out ? *id_out : 0))
    ctf_integer_hex(uintptr_t, graph_out_val, (uintptr_t)((graph_out ? *graph_out : 0)))
    ctf_integer(size_t, numDependencies_out_val, (numDependencies_out ? *numDependencies_out : 0))
    ctf_sequence_hex(uintptr_t, dependencies_out_vals, dependencies_out, size_t, (numDependencies_out && dependencies_out ? *numDependencies_out : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamIsCapturing_entry,
  TP_ARGS(
    hipStream_t, stream,
    hipStreamCaptureStatus *, pCaptureStatus
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, pCaptureStatus, (uintptr_t)(pCaptureStatus))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamIsCapturing_exit,
  TP_ARGS(
    hipStream_t, stream,
    hipStreamCaptureStatus *, pCaptureStatus,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(int32_t, pCaptureStatus_val, (pCaptureStatus ? *pCaptureStatus : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamUpdateCaptureDependencies_entry,
  TP_ARGS(
    hipStream_t, stream,
    hipGraphNode_t *, dependencies,
    size_t, numDependencies,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, dependencies, (uintptr_t)(dependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer(unsigned int, flags, flags)
    ctf_sequence_hex(uintptr_t, dependencies_vals, dependencies, size_t, (dependencies ? numDependencies : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamUpdateCaptureDependencies_exit,
  TP_ARGS(
    hipStream_t, stream,
    hipGraphNode_t *, dependencies,
    size_t, numDependencies,
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipLaunchHostFunc_entry,
  TP_ARGS(
    hipStream_t, stream,
    hipHostFn_t, fn,
    void *, userData
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, fn, (uintptr_t)(fn))
    ctf_integer_hex(uintptr_t, userData, (uintptr_t)(userData))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipLaunchHostFunc_exit,
  TP_ARGS(
    hipStream_t, stream,
    hipHostFn_t, fn,
    void *, userData,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipThreadExchangeStreamCaptureMode_entry,
  TP_ARGS(
    hipStreamCaptureMode *, mode
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mode, (uintptr_t)(mode))
    ctf_integer(int32_t, mode_val, (mode ? *mode : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipThreadExchangeStreamCaptureMode_exit,
  TP_ARGS(
    hipStreamCaptureMode *, mode,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(int32_t, mode_val, (mode ? *mode : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphCreate_entry,
  TP_ARGS(
    hipGraph_t *, pGraph,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pGraph, (uintptr_t)(pGraph))
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphCreate_exit,
  TP_ARGS(
    hipGraph_t *, pGraph,
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, pGraph_val, (uintptr_t)((pGraph ? *pGraph : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphDestroy_entry,
  TP_ARGS(
    hipGraph_t, graph
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphDestroy_exit,
  TP_ARGS(
    hipGraph_t, graph,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphAddDependencies_entry,
  TP_ARGS(
    hipGraph_t, graph,
    const hipGraphNode_t *, from,
    const hipGraphNode_t *, to,
    size_t, numDependencies
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, from, (uintptr_t)(from))
    ctf_integer_hex(uintptr_t, to, (uintptr_t)(to))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_sequence_hex(uintptr_t, from_vals, from, size_t, (from ? numDependencies : 0))
    ctf_sequence_hex(uintptr_t, to_vals, to, size_t, (to ? numDependencies : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphAddDependencies_exit,
  TP_ARGS(
    hipGraph_t, graph,
    const hipGraphNode_t *, from,
    const hipGraphNode_t *, to,
    size_t, numDependencies,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphRemoveDependencies_entry,
  TP_ARGS(
    hipGraph_t, graph,
    const hipGraphNode_t *, from,
    const hipGraphNode_t *, to,
    size_t, numDependencies
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, from, (uintptr_t)(from))
    ctf_integer_hex(uintptr_t, to, (uintptr_t)(to))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_sequence_hex(uintptr_t, from_vals, from, size_t, (from ? numDependencies : 0))
    ctf_sequence_hex(uintptr_t, to_vals, to, size_t, (to ? numDependencies : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphRemoveDependencies_exit,
  TP_ARGS(
    hipGraph_t, graph,
    const hipGraphNode_t *, from,
    const hipGraphNode_t *, to,
    size_t, numDependencies,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphGetEdges_entry,
  TP_ARGS(
    hipGraph_t, graph,
    hipGraphNode_t *, from,
    hipGraphNode_t *, to,
    size_t *, numEdges
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, from, (uintptr_t)(from))
    ctf_integer_hex(uintptr_t, to, (uintptr_t)(to))
    ctf_integer_hex(uintptr_t, numEdges, (uintptr_t)(numEdges))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphGetEdges_exit,
  TP_ARGS(
    hipGraph_t, graph,
    hipGraphNode_t *, from,
    hipGraphNode_t *, to,
    size_t *, numEdges,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(size_t, numEdges_val, (numEdges ? *numEdges : 0))
    ctf_sequence_hex(uintptr_t, from_vals, from, size_t, (numEdges && from ? *numEdges : 0))
    ctf_sequence_hex(uintptr_t, to_vals, to, size_t, (numEdges && to ? *numEdges : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphGetNodes_entry,
  TP_ARGS(
    hipGraph_t, graph,
    hipGraphNode_t *, nodes,
    size_t *, numNodes
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, nodes, (uintptr_t)(nodes))
    ctf_integer_hex(uintptr_t, numNodes, (uintptr_t)(numNodes))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphGetNodes_exit,
  TP_ARGS(
    hipGraph_t, graph,
    hipGraphNode_t *, nodes,
    size_t *, numNodes,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(size_t, numNodes_val, (numNodes ? *numNodes : 0))
    ctf_sequence_hex(uintptr_t, nodes_vals, nodes, size_t, (numNodes && nodes ? *numNodes : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphGetRootNodes_entry,
  TP_ARGS(
    hipGraph_t, graph,
    hipGraphNode_t *, pRootNodes,
    size_t *, pNumRootNodes
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, pRootNodes, (uintptr_t)(pRootNodes))
    ctf_integer_hex(uintptr_t, pNumRootNodes, (uintptr_t)(pNumRootNodes))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphGetRootNodes_exit,
  TP_ARGS(
    hipGraph_t, graph,
    hipGraphNode_t *, pRootNodes,
    size_t *, pNumRootNodes,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(size_t, pNumRootNodes_val, (pNumRootNodes ? *pNumRootNodes : 0))
    ctf_sequence_hex(uintptr_t, pRootNodes_vals, pRootNodes, size_t, (pNumRootNodes && pRootNodes ? *pNumRootNodes : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphNodeGetDependencies_entry,
  TP_ARGS(
    hipGraphNode_t, node,
    hipGraphNode_t *, pDependencies,
    size_t *, pNumDependencies
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, pDependencies, (uintptr_t)(pDependencies))
    ctf_integer_hex(uintptr_t, pNumDependencies, (uintptr_t)(pNumDependencies))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphNodeGetDependencies_exit,
  TP_ARGS(
    hipGraphNode_t, node,
    hipGraphNode_t *, pDependencies,
    size_t *, pNumDependencies,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(size_t, pNumDependencies_val, (pNumDependencies ? *pNumDependencies : 0))
    ctf_sequence_hex(uintptr_t, pDependencies_vals, pDependencies, size_t, (pNumDependencies && pDependencies ? *pNumDependencies : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphNodeGetDependentNodes_entry,
  TP_ARGS(
    hipGraphNode_t, node,
    hipGraphNode_t *, pDependentNodes,
    size_t *, pNumDependentNodes
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, pDependentNodes, (uintptr_t)(pDependentNodes))
    ctf_integer_hex(uintptr_t, pNumDependentNodes, (uintptr_t)(pNumDependentNodes))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphNodeGetDependentNodes_exit,
  TP_ARGS(
    hipGraphNode_t, node,
    hipGraphNode_t *, pDependentNodes,
    size_t *, pNumDependentNodes,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(size_t, pNumDependentNodes_val, (pNumDependentNodes ? *pNumDependentNodes : 0))
    ctf_sequence_hex(uintptr_t, pDependentNodes_vals, pDependentNodes, size_t, (pNumDependentNodes && pDependentNodes ? *pNumDependentNodes : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphNodeGetType_entry,
  TP_ARGS(
    hipGraphNode_t, node,
    hipGraphNodeType *, pType
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, pType, (uintptr_t)(pType))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphNodeGetType_exit,
  TP_ARGS(
    hipGraphNode_t, node,
    hipGraphNodeType *, pType,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(int32_t, pType_val, (pType ? *pType : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphDestroyNode_entry,
  TP_ARGS(
    hipGraphNode_t, node
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphDestroyNode_exit,
  TP_ARGS(
    hipGraphNode_t, node,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphClone_entry,
  TP_ARGS(
    hipGraph_t *, pGraphClone,
    hipGraph_t, originalGraph
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pGraphClone, (uintptr_t)(pGraphClone))
    ctf_integer_hex(uintptr_t, originalGraph, (uintptr_t)(originalGraph))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphClone_exit,
  TP_ARGS(
    hipGraph_t *, pGraphClone,
    hipGraph_t, originalGraph,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, pGraphClone_val, (uintptr_t)((pGraphClone ? *pGraphClone : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphNodeFindInClone_entry,
  TP_ARGS(
    hipGraphNode_t *, pNode,
    hipGraphNode_t, originalNode,
    hipGraph_t, clonedGraph
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pNode, (uintptr_t)(pNode))
    ctf_integer_hex(uintptr_t, originalNode, (uintptr_t)(originalNode))
    ctf_integer_hex(uintptr_t, clonedGraph, (uintptr_t)(clonedGraph))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphNodeFindInClone_exit,
  TP_ARGS(
    hipGraphNode_t *, pNode,
    hipGraphNode_t, originalNode,
    hipGraph_t, clonedGraph,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, pNode_val, (uintptr_t)((pNode ? *pNode : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphInstantiate_entry,
  TP_ARGS(
    hipGraphExec_t *, pGraphExec,
    hipGraph_t, graph,
    hipGraphNode_t *, pErrorNode,
    char *, pLogBuffer,
    size_t, bufferSize
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pGraphExec, (uintptr_t)(pGraphExec))
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, pErrorNode, (uintptr_t)(pErrorNode))
    ctf_integer_hex(uintptr_t, pLogBuffer, (uintptr_t)(pLogBuffer))
    ctf_integer(size_t, bufferSize, bufferSize)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphInstantiate_exit,
  TP_ARGS(
    hipGraphExec_t *, pGraphExec,
    hipGraph_t, graph,
    hipGraphNode_t *, pErrorNode,
    char *, pLogBuffer,
    size_t, bufferSize,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, pGraphExec_val, (uintptr_t)((pGraphExec ? *pGraphExec : 0)))
    ctf_integer_hex(uintptr_t, pErrorNode_val, (uintptr_t)((pErrorNode ? *pErrorNode : 0)))
    ctf_sequence_text(char, pLogBuffer_vals, pLogBuffer, size_t, (pLogBuffer ? bufferSize : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphInstantiateWithFlags_entry,
  TP_ARGS(
    hipGraphExec_t *, pGraphExec,
    hipGraph_t, graph,
    unsigned long long int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pGraphExec, (uintptr_t)(pGraphExec))
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer(unsigned long long int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphInstantiateWithFlags_exit,
  TP_ARGS(
    hipGraphExec_t *, pGraphExec,
    hipGraph_t, graph,
    unsigned long long int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, pGraphExec_val, (uintptr_t)((pGraphExec ? *pGraphExec : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphLaunch_entry,
  TP_ARGS(
    hipGraphExec_t, graphExec,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, graphExec, (uintptr_t)(graphExec))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphLaunch_exit,
  TP_ARGS(
    hipGraphExec_t, graphExec,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphUpload_entry,
  TP_ARGS(
    hipGraphExec_t, graphExec,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, graphExec, (uintptr_t)(graphExec))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphUpload_exit,
  TP_ARGS(
    hipGraphExec_t, graphExec,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphExecDestroy_entry,
  TP_ARGS(
    hipGraphExec_t, graphExec
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, graphExec, (uintptr_t)(graphExec))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphExecDestroy_exit,
  TP_ARGS(
    hipGraphExec_t, graphExec,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphExecUpdate_entry,
  TP_ARGS(
    hipGraphExec_t, hGraphExec,
    hipGraph_t, hGraph,
    hipGraphNode_t *, hErrorNode_out,
    hipGraphExecUpdateResult *, updateResult_out
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, hErrorNode_out, (uintptr_t)(hErrorNode_out))
    ctf_integer_hex(uintptr_t, updateResult_out, (uintptr_t)(updateResult_out))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphExecUpdate_exit,
  TP_ARGS(
    hipGraphExec_t, hGraphExec,
    hipGraph_t, hGraph,
    hipGraphNode_t *, hErrorNode_out,
    hipGraphExecUpdateResult *, updateResult_out,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, hErrorNode_out_val, (uintptr_t)((hErrorNode_out ? *hErrorNode_out : 0)))
    ctf_integer(int32_t, updateResult_out_val, (updateResult_out ? *updateResult_out : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphAddKernelNode_entry,
  TP_ARGS(
    hipGraphNode_t *, pGraphNode,
    hipGraph_t, graph,
    const hipGraphNode_t *, pDependencies,
    size_t, numDependencies,
    const hipKernelNodeParams *, pNodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pGraphNode, (uintptr_t)(pGraphNode))
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, pDependencies, (uintptr_t)(pDependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, pNodeParams, (uintptr_t)(pNodeParams))
    ctf_sequence_hex(uintptr_t, pDependencies_vals, pDependencies, size_t, (pDependencies ? numDependencies : 0))
    ctf_sequence_text(uint8_t, pNodeParams_val, pNodeParams, size_t, (pNodeParams ? sizeof(hipKernelNodeParams) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphAddKernelNode_exit,
  TP_ARGS(
    hipGraphNode_t *, pGraphNode,
    hipGraph_t, graph,
    const hipGraphNode_t *, pDependencies,
    size_t, numDependencies,
    const hipKernelNodeParams *, pNodeParams,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, pGraphNode_val, (uintptr_t)((pGraphNode ? *pGraphNode : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphKernelNodeGetParams_entry,
  TP_ARGS(
    hipGraphNode_t, node,
    hipKernelNodeParams *, pNodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, pNodeParams, (uintptr_t)(pNodeParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphKernelNodeGetParams_exit,
  TP_ARGS(
    hipGraphNode_t, node,
    hipKernelNodeParams *, pNodeParams,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_sequence_text(uint8_t, pNodeParams_val, pNodeParams, size_t, (pNodeParams ? sizeof(hipKernelNodeParams) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphKernelNodeSetParams_entry,
  TP_ARGS(
    hipGraphNode_t, node,
    const hipKernelNodeParams *, pNodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, pNodeParams, (uintptr_t)(pNodeParams))
    ctf_sequence_text(uint8_t, pNodeParams_val, pNodeParams, size_t, (pNodeParams ? sizeof(hipKernelNodeParams) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphKernelNodeSetParams_exit,
  TP_ARGS(
    hipGraphNode_t, node,
    const hipKernelNodeParams *, pNodeParams,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphExecKernelNodeSetParams_entry,
  TP_ARGS(
    hipGraphExec_t, hGraphExec,
    hipGraphNode_t, node,
    const hipKernelNodeParams *, pNodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, pNodeParams, (uintptr_t)(pNodeParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphExecKernelNodeSetParams_exit,
  TP_ARGS(
    hipGraphExec_t, hGraphExec,
    hipGraphNode_t, node,
    const hipKernelNodeParams *, pNodeParams,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphAddMemcpyNode_entry,
  TP_ARGS(
    hipGraphNode_t *, pGraphNode,
    hipGraph_t, graph,
    const hipGraphNode_t *, pDependencies,
    size_t, numDependencies,
    const hipMemcpy3DParms *, pCopyParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pGraphNode, (uintptr_t)(pGraphNode))
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, pDependencies, (uintptr_t)(pDependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, pCopyParams, (uintptr_t)(pCopyParams))
    ctf_sequence_hex(uintptr_t, pDependencies_vals, pDependencies, size_t, (pDependencies ? numDependencies : 0))
    ctf_sequence_text(uint8_t, pCopyParams_val, pCopyParams, size_t, (pCopyParams ? sizeof(hipMemcpy3DParms) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphAddMemcpyNode_exit,
  TP_ARGS(
    hipGraphNode_t *, pGraphNode,
    hipGraph_t, graph,
    const hipGraphNode_t *, pDependencies,
    size_t, numDependencies,
    const hipMemcpy3DParms *, pCopyParams,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, pGraphNode_val, (uintptr_t)((pGraphNode ? *pGraphNode : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphMemcpyNodeGetParams_entry,
  TP_ARGS(
    hipGraphNode_t, node,
    hipMemcpy3DParms *, pNodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, pNodeParams, (uintptr_t)(pNodeParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphMemcpyNodeGetParams_exit,
  TP_ARGS(
    hipGraphNode_t, node,
    hipMemcpy3DParms *, pNodeParams,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_sequence_text(uint8_t, pNodeParams_val, pNodeParams, size_t, (pNodeParams ? sizeof(hipMemcpy3DParms) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphMemcpyNodeSetParams_entry,
  TP_ARGS(
    hipGraphNode_t, node,
    const hipMemcpy3DParms *, pNodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, pNodeParams, (uintptr_t)(pNodeParams))
    ctf_sequence_text(uint8_t, pNodeParams_val, pNodeParams, size_t, (pNodeParams ? sizeof(hipMemcpy3DParms) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphMemcpyNodeSetParams_exit,
  TP_ARGS(
    hipGraphNode_t, node,
    const hipMemcpy3DParms *, pNodeParams,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphKernelNodeSetAttribute_entry,
  TP_ARGS(
    hipGraphNode_t, hNode,
    hipKernelNodeAttrID, attr,
    const hipKernelNodeAttrValue *, value
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer(int32_t, attr, attr)
    ctf_integer_hex(uintptr_t, value, (uintptr_t)(value))
    ctf_sequence_text(uint8_t, value_val, value, size_t, (value ? sizeof(hipKernelNodeAttrValue) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphKernelNodeSetAttribute_exit,
  TP_ARGS(
    hipGraphNode_t, hNode,
    hipKernelNodeAttrID, attr,
    const hipKernelNodeAttrValue *, value,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphKernelNodeGetAttribute_entry,
  TP_ARGS(
    hipGraphNode_t, hNode,
    hipKernelNodeAttrID, attr,
    hipKernelNodeAttrValue *, value
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer(int32_t, attr, attr)
    ctf_integer_hex(uintptr_t, value, (uintptr_t)(value))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphKernelNodeGetAttribute_exit,
  TP_ARGS(
    hipGraphNode_t, hNode,
    hipKernelNodeAttrID, attr,
    hipKernelNodeAttrValue *, value,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_sequence_text(uint8_t, value_val, value, size_t, (value ? sizeof(hipKernelNodeAttrValue) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphExecMemcpyNodeSetParams_entry,
  TP_ARGS(
    hipGraphExec_t, hGraphExec,
    hipGraphNode_t, node,
    hipMemcpy3DParms *, pNodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, pNodeParams, (uintptr_t)(pNodeParams))
    ctf_sequence_text(uint8_t, pNodeParams_val, pNodeParams, size_t, (pNodeParams ? sizeof(hipMemcpy3DParms) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphExecMemcpyNodeSetParams_exit,
  TP_ARGS(
    hipGraphExec_t, hGraphExec,
    hipGraphNode_t, node,
    hipMemcpy3DParms *, pNodeParams,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphAddMemcpyNode1D_entry,
  TP_ARGS(
    hipGraphNode_t *, pGraphNode,
    hipGraph_t, graph,
    const hipGraphNode_t *, pDependencies,
    size_t, numDependencies,
    void *, dst,
    const void *, src,
    size_t, count,
    hipMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pGraphNode, (uintptr_t)(pGraphNode))
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, pDependencies, (uintptr_t)(pDependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, count, count)
    ctf_integer(int32_t, kind, kind)
    ctf_sequence_hex(uintptr_t, pDependencies_vals, pDependencies, size_t, (pDependencies ? numDependencies : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphAddMemcpyNode1D_exit,
  TP_ARGS(
    hipGraphNode_t *, pGraphNode,
    hipGraph_t, graph,
    const hipGraphNode_t *, pDependencies,
    size_t, numDependencies,
    void *, dst,
    const void *, src,
    size_t, count,
    hipMemcpyKind, kind,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, pGraphNode_val, (uintptr_t)((pGraphNode ? *pGraphNode : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphMemcpyNodeSetParams1D_entry,
  TP_ARGS(
    hipGraphNode_t, node,
    void *, dst,
    const void *, src,
    size_t, count,
    hipMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, count, count)
    ctf_integer(int32_t, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphMemcpyNodeSetParams1D_exit,
  TP_ARGS(
    hipGraphNode_t, node,
    void *, dst,
    const void *, src,
    size_t, count,
    hipMemcpyKind, kind,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphExecMemcpyNodeSetParams1D_entry,
  TP_ARGS(
    hipGraphExec_t, hGraphExec,
    hipGraphNode_t, node,
    void *, dst,
    const void *, src,
    size_t, count,
    hipMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, count, count)
    ctf_integer(int32_t, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphExecMemcpyNodeSetParams1D_exit,
  TP_ARGS(
    hipGraphExec_t, hGraphExec,
    hipGraphNode_t, node,
    void *, dst,
    const void *, src,
    size_t, count,
    hipMemcpyKind, kind,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphAddMemcpyNodeFromSymbol_entry,
  TP_ARGS(
    hipGraphNode_t *, pGraphNode,
    hipGraph_t, graph,
    const hipGraphNode_t *, pDependencies,
    size_t, numDependencies,
    void *, dst,
    const void *, symbol,
    size_t, count,
    size_t, offset,
    hipMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pGraphNode, (uintptr_t)(pGraphNode))
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, pDependencies, (uintptr_t)(pDependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
    ctf_integer(size_t, count, count)
    ctf_integer(size_t, offset, offset)
    ctf_integer(int32_t, kind, kind)
    ctf_sequence_hex(uintptr_t, pDependencies_vals, pDependencies, size_t, (pDependencies ? numDependencies : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphAddMemcpyNodeFromSymbol_exit,
  TP_ARGS(
    hipGraphNode_t *, pGraphNode,
    hipGraph_t, graph,
    const hipGraphNode_t *, pDependencies,
    size_t, numDependencies,
    void *, dst,
    const void *, symbol,
    size_t, count,
    size_t, offset,
    hipMemcpyKind, kind,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, pGraphNode_val, (uintptr_t)((pGraphNode ? *pGraphNode : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphMemcpyNodeSetParamsFromSymbol_entry,
  TP_ARGS(
    hipGraphNode_t, node,
    void *, dst,
    const void *, symbol,
    size_t, count,
    size_t, offset,
    hipMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
    ctf_integer(size_t, count, count)
    ctf_integer(size_t, offset, offset)
    ctf_integer(int32_t, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphMemcpyNodeSetParamsFromSymbol_exit,
  TP_ARGS(
    hipGraphNode_t, node,
    void *, dst,
    const void *, symbol,
    size_t, count,
    size_t, offset,
    hipMemcpyKind, kind,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphExecMemcpyNodeSetParamsFromSymbol_entry,
  TP_ARGS(
    hipGraphExec_t, hGraphExec,
    hipGraphNode_t, node,
    void *, dst,
    const void *, symbol,
    size_t, count,
    size_t, offset,
    hipMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
    ctf_integer(size_t, count, count)
    ctf_integer(size_t, offset, offset)
    ctf_integer(int32_t, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphExecMemcpyNodeSetParamsFromSymbol_exit,
  TP_ARGS(
    hipGraphExec_t, hGraphExec,
    hipGraphNode_t, node,
    void *, dst,
    const void *, symbol,
    size_t, count,
    size_t, offset,
    hipMemcpyKind, kind,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphAddMemcpyNodeToSymbol_entry,
  TP_ARGS(
    hipGraphNode_t *, pGraphNode,
    hipGraph_t, graph,
    const hipGraphNode_t *, pDependencies,
    size_t, numDependencies,
    const void *, symbol,
    const void *, src,
    size_t, count,
    size_t, offset,
    hipMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pGraphNode, (uintptr_t)(pGraphNode))
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, pDependencies, (uintptr_t)(pDependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, count, count)
    ctf_integer(size_t, offset, offset)
    ctf_integer(int32_t, kind, kind)
    ctf_sequence_hex(uintptr_t, pDependencies_vals, pDependencies, size_t, (pDependencies ? numDependencies : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphAddMemcpyNodeToSymbol_exit,
  TP_ARGS(
    hipGraphNode_t *, pGraphNode,
    hipGraph_t, graph,
    const hipGraphNode_t *, pDependencies,
    size_t, numDependencies,
    const void *, symbol,
    const void *, src,
    size_t, count,
    size_t, offset,
    hipMemcpyKind, kind,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, pGraphNode_val, (uintptr_t)((pGraphNode ? *pGraphNode : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphMemcpyNodeSetParamsToSymbol_entry,
  TP_ARGS(
    hipGraphNode_t, node,
    const void *, symbol,
    const void *, src,
    size_t, count,
    size_t, offset,
    hipMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, count, count)
    ctf_integer(size_t, offset, offset)
    ctf_integer(int32_t, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphMemcpyNodeSetParamsToSymbol_exit,
  TP_ARGS(
    hipGraphNode_t, node,
    const void *, symbol,
    const void *, src,
    size_t, count,
    size_t, offset,
    hipMemcpyKind, kind,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphExecMemcpyNodeSetParamsToSymbol_entry,
  TP_ARGS(
    hipGraphExec_t, hGraphExec,
    hipGraphNode_t, node,
    const void *, symbol,
    const void *, src,
    size_t, count,
    size_t, offset,
    hipMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, count, count)
    ctf_integer(size_t, offset, offset)
    ctf_integer(int32_t, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphExecMemcpyNodeSetParamsToSymbol_exit,
  TP_ARGS(
    hipGraphExec_t, hGraphExec,
    hipGraphNode_t, node,
    const void *, symbol,
    const void *, src,
    size_t, count,
    size_t, offset,
    hipMemcpyKind, kind,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphAddMemsetNode_entry,
  TP_ARGS(
    hipGraphNode_t *, pGraphNode,
    hipGraph_t, graph,
    const hipGraphNode_t *, pDependencies,
    size_t, numDependencies,
    const hipMemsetParams *, pMemsetParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pGraphNode, (uintptr_t)(pGraphNode))
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, pDependencies, (uintptr_t)(pDependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, pMemsetParams, (uintptr_t)(pMemsetParams))
    ctf_sequence_hex(uintptr_t, pDependencies_vals, pDependencies, size_t, (pDependencies ? numDependencies : 0))
    ctf_sequence_text(uint8_t, pMemsetParams_val, pMemsetParams, size_t, (pMemsetParams ? sizeof(hipMemsetParams) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphAddMemsetNode_exit,
  TP_ARGS(
    hipGraphNode_t *, pGraphNode,
    hipGraph_t, graph,
    const hipGraphNode_t *, pDependencies,
    size_t, numDependencies,
    const hipMemsetParams *, pMemsetParams,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, pGraphNode_val, (uintptr_t)((pGraphNode ? *pGraphNode : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphMemsetNodeGetParams_entry,
  TP_ARGS(
    hipGraphNode_t, node,
    hipMemsetParams *, pNodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, pNodeParams, (uintptr_t)(pNodeParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphMemsetNodeGetParams_exit,
  TP_ARGS(
    hipGraphNode_t, node,
    hipMemsetParams *, pNodeParams,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_sequence_text(uint8_t, pNodeParams_val, pNodeParams, size_t, (pNodeParams ? sizeof(hipMemsetParams) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphMemsetNodeSetParams_entry,
  TP_ARGS(
    hipGraphNode_t, node,
    const hipMemsetParams *, pNodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, pNodeParams, (uintptr_t)(pNodeParams))
    ctf_sequence_text(uint8_t, pNodeParams_val, pNodeParams, size_t, (pNodeParams ? sizeof(hipMemsetParams) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphMemsetNodeSetParams_exit,
  TP_ARGS(
    hipGraphNode_t, node,
    const hipMemsetParams *, pNodeParams,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphExecMemsetNodeSetParams_entry,
  TP_ARGS(
    hipGraphExec_t, hGraphExec,
    hipGraphNode_t, node,
    const hipMemsetParams *, pNodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, pNodeParams, (uintptr_t)(pNodeParams))
    ctf_sequence_text(uint8_t, pNodeParams_val, pNodeParams, size_t, (pNodeParams ? sizeof(hipMemsetParams) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphExecMemsetNodeSetParams_exit,
  TP_ARGS(
    hipGraphExec_t, hGraphExec,
    hipGraphNode_t, node,
    const hipMemsetParams *, pNodeParams,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphAddHostNode_entry,
  TP_ARGS(
    hipGraphNode_t *, pGraphNode,
    hipGraph_t, graph,
    const hipGraphNode_t *, pDependencies,
    size_t, numDependencies,
    const hipHostNodeParams *, pNodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pGraphNode, (uintptr_t)(pGraphNode))
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, pDependencies, (uintptr_t)(pDependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, pNodeParams, (uintptr_t)(pNodeParams))
    ctf_sequence_hex(uintptr_t, pDependencies_vals, pDependencies, size_t, (pDependencies ? numDependencies : 0))
    ctf_sequence_text(uint8_t, pNodeParams_val, pNodeParams, size_t, (pNodeParams ? sizeof(hipHostNodeParams) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphAddHostNode_exit,
  TP_ARGS(
    hipGraphNode_t *, pGraphNode,
    hipGraph_t, graph,
    const hipGraphNode_t *, pDependencies,
    size_t, numDependencies,
    const hipHostNodeParams *, pNodeParams,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, pGraphNode_val, (uintptr_t)((pGraphNode ? *pGraphNode : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphHostNodeGetParams_entry,
  TP_ARGS(
    hipGraphNode_t, node,
    hipHostNodeParams *, pNodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, pNodeParams, (uintptr_t)(pNodeParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphHostNodeGetParams_exit,
  TP_ARGS(
    hipGraphNode_t, node,
    hipHostNodeParams *, pNodeParams,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_sequence_text(uint8_t, pNodeParams_val, pNodeParams, size_t, (pNodeParams ? sizeof(hipHostNodeParams) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphHostNodeSetParams_entry,
  TP_ARGS(
    hipGraphNode_t, node,
    const hipHostNodeParams *, pNodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, pNodeParams, (uintptr_t)(pNodeParams))
    ctf_sequence_text(uint8_t, pNodeParams_val, pNodeParams, size_t, (pNodeParams ? sizeof(hipHostNodeParams) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphHostNodeSetParams_exit,
  TP_ARGS(
    hipGraphNode_t, node,
    const hipHostNodeParams *, pNodeParams,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphExecHostNodeSetParams_entry,
  TP_ARGS(
    hipGraphExec_t, hGraphExec,
    hipGraphNode_t, node,
    const hipHostNodeParams *, pNodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, pNodeParams, (uintptr_t)(pNodeParams))
    ctf_sequence_text(uint8_t, pNodeParams_val, pNodeParams, size_t, (pNodeParams ? sizeof(hipHostNodeParams) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphExecHostNodeSetParams_exit,
  TP_ARGS(
    hipGraphExec_t, hGraphExec,
    hipGraphNode_t, node,
    const hipHostNodeParams *, pNodeParams,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphAddChildGraphNode_entry,
  TP_ARGS(
    hipGraphNode_t *, pGraphNode,
    hipGraph_t, graph,
    const hipGraphNode_t *, pDependencies,
    size_t, numDependencies,
    hipGraph_t, childGraph
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pGraphNode, (uintptr_t)(pGraphNode))
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, pDependencies, (uintptr_t)(pDependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, childGraph, (uintptr_t)(childGraph))
    ctf_sequence_hex(uintptr_t, pDependencies_vals, pDependencies, size_t, (pDependencies ? numDependencies : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphAddChildGraphNode_exit,
  TP_ARGS(
    hipGraphNode_t *, pGraphNode,
    hipGraph_t, graph,
    const hipGraphNode_t *, pDependencies,
    size_t, numDependencies,
    hipGraph_t, childGraph,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, pGraphNode_val, (uintptr_t)((pGraphNode ? *pGraphNode : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphChildGraphNodeGetGraph_entry,
  TP_ARGS(
    hipGraphNode_t, node,
    hipGraph_t *, pGraph
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, pGraph, (uintptr_t)(pGraph))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphChildGraphNodeGetGraph_exit,
  TP_ARGS(
    hipGraphNode_t, node,
    hipGraph_t *, pGraph,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, pGraph_val, (uintptr_t)((pGraph ? *pGraph : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphExecChildGraphNodeSetParams_entry,
  TP_ARGS(
    hipGraphExec_t, hGraphExec,
    hipGraphNode_t, node,
    hipGraph_t, childGraph
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, childGraph, (uintptr_t)(childGraph))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphExecChildGraphNodeSetParams_exit,
  TP_ARGS(
    hipGraphExec_t, hGraphExec,
    hipGraphNode_t, node,
    hipGraph_t, childGraph,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphAddEmptyNode_entry,
  TP_ARGS(
    hipGraphNode_t *, pGraphNode,
    hipGraph_t, graph,
    const hipGraphNode_t *, pDependencies,
    size_t, numDependencies
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pGraphNode, (uintptr_t)(pGraphNode))
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, pDependencies, (uintptr_t)(pDependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_sequence_hex(uintptr_t, pDependencies_vals, pDependencies, size_t, (pDependencies ? numDependencies : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphAddEmptyNode_exit,
  TP_ARGS(
    hipGraphNode_t *, pGraphNode,
    hipGraph_t, graph,
    const hipGraphNode_t *, pDependencies,
    size_t, numDependencies,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, pGraphNode_val, (uintptr_t)((pGraphNode ? *pGraphNode : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphAddEventRecordNode_entry,
  TP_ARGS(
    hipGraphNode_t *, pGraphNode,
    hipGraph_t, graph,
    const hipGraphNode_t *, pDependencies,
    size_t, numDependencies,
    hipEvent_t, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pGraphNode, (uintptr_t)(pGraphNode))
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, pDependencies, (uintptr_t)(pDependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
    ctf_sequence_hex(uintptr_t, pDependencies_vals, pDependencies, size_t, (pDependencies ? numDependencies : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphAddEventRecordNode_exit,
  TP_ARGS(
    hipGraphNode_t *, pGraphNode,
    hipGraph_t, graph,
    const hipGraphNode_t *, pDependencies,
    size_t, numDependencies,
    hipEvent_t, event,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, pGraphNode_val, (uintptr_t)((pGraphNode ? *pGraphNode : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphEventRecordNodeGetEvent_entry,
  TP_ARGS(
    hipGraphNode_t, node,
    hipEvent_t *, event_out
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, event_out, (uintptr_t)(event_out))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphEventRecordNodeGetEvent_exit,
  TP_ARGS(
    hipGraphNode_t, node,
    hipEvent_t *, event_out,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, event_out_val, (uintptr_t)((event_out ? *event_out : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphEventRecordNodeSetEvent_entry,
  TP_ARGS(
    hipGraphNode_t, node,
    hipEvent_t, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphEventRecordNodeSetEvent_exit,
  TP_ARGS(
    hipGraphNode_t, node,
    hipEvent_t, event,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphExecEventRecordNodeSetEvent_entry,
  TP_ARGS(
    hipGraphExec_t, hGraphExec,
    hipGraphNode_t, hNode,
    hipEvent_t, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphExecEventRecordNodeSetEvent_exit,
  TP_ARGS(
    hipGraphExec_t, hGraphExec,
    hipGraphNode_t, hNode,
    hipEvent_t, event,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphAddEventWaitNode_entry,
  TP_ARGS(
    hipGraphNode_t *, pGraphNode,
    hipGraph_t, graph,
    const hipGraphNode_t *, pDependencies,
    size_t, numDependencies,
    hipEvent_t, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pGraphNode, (uintptr_t)(pGraphNode))
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, pDependencies, (uintptr_t)(pDependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
    ctf_sequence_hex(uintptr_t, pDependencies_vals, pDependencies, size_t, (pDependencies ? numDependencies : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphAddEventWaitNode_exit,
  TP_ARGS(
    hipGraphNode_t *, pGraphNode,
    hipGraph_t, graph,
    const hipGraphNode_t *, pDependencies,
    size_t, numDependencies,
    hipEvent_t, event,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, pGraphNode_val, (uintptr_t)((pGraphNode ? *pGraphNode : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphEventWaitNodeGetEvent_entry,
  TP_ARGS(
    hipGraphNode_t, node,
    hipEvent_t *, event_out
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, event_out, (uintptr_t)(event_out))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphEventWaitNodeGetEvent_exit,
  TP_ARGS(
    hipGraphNode_t, node,
    hipEvent_t *, event_out,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, event_out_val, (uintptr_t)((event_out ? *event_out : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphEventWaitNodeSetEvent_entry,
  TP_ARGS(
    hipGraphNode_t, node,
    hipEvent_t, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphEventWaitNodeSetEvent_exit,
  TP_ARGS(
    hipGraphNode_t, node,
    hipEvent_t, event,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphExecEventWaitNodeSetEvent_entry,
  TP_ARGS(
    hipGraphExec_t, hGraphExec,
    hipGraphNode_t, hNode,
    hipEvent_t, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphExecEventWaitNodeSetEvent_exit,
  TP_ARGS(
    hipGraphExec_t, hGraphExec,
    hipGraphNode_t, hNode,
    hipEvent_t, event,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceGetGraphMemAttribute_entry,
  TP_ARGS(
    int, device,
    hipGraphMemAttributeType, attr,
    void *, value
  ),
  TP_FIELDS(
    ctf_integer(int, device, device)
    ctf_integer(int32_t, attr, attr)
    ctf_integer_hex(uintptr_t, value, (uintptr_t)(value))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceGetGraphMemAttribute_exit,
  TP_ARGS(
    int, device,
    hipGraphMemAttributeType, attr,
    void *, value,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_sequence_text(uint8_t, value_val, value, size_t, attr == hipGraphMemAttrUsedMemCurrent ? sizeof(uint64_t) : attr == hipGraphMemAttrUsedMemHigh ? sizeof(uint64_t) : attr == hipGraphMemAttrReservedMemCurrent ? sizeof(uint64_t) : attr == hipGraphMemAttrReservedMemHigh ? sizeof(uint64_t) : 0)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceSetGraphMemAttribute_entry,
  TP_ARGS(
    int, device,
    hipGraphMemAttributeType, attr,
    void *, value
  ),
  TP_FIELDS(
    ctf_integer(int, device, device)
    ctf_integer(int32_t, attr, attr)
    ctf_integer_hex(uintptr_t, value, (uintptr_t)(value))
    ctf_sequence_text(uint8_t, value_val, value, size_t, attr == hipGraphMemAttrUsedMemHigh ? sizeof(uint64_t) : attr == hipGraphMemAttrReservedMemHigh ? sizeof(uint64_t) : 0)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceSetGraphMemAttribute_exit,
  TP_ARGS(
    int, device,
    hipGraphMemAttributeType, attr,
    void *, value,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceGraphMemTrim_entry,
  TP_ARGS(
    int, device
  ),
  TP_FIELDS(
    ctf_integer(int, device, device)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipDeviceGraphMemTrim_exit,
  TP_ARGS(
    int, device,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipUserObjectCreate_entry,
  TP_ARGS(
    hipUserObject_t *, object_out,
    void *, ptr,
    hipHostFn_t, destroy,
    unsigned int, initialRefcount,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, object_out, (uintptr_t)(object_out))
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)(ptr))
    ctf_integer_hex(uintptr_t, destroy, (uintptr_t)(destroy))
    ctf_integer(unsigned int, initialRefcount, initialRefcount)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipUserObjectCreate_exit,
  TP_ARGS(
    hipUserObject_t *, object_out,
    void *, ptr,
    hipHostFn_t, destroy,
    unsigned int, initialRefcount,
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, object_out_val, (uintptr_t)((object_out ? *object_out : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipUserObjectRelease_entry,
  TP_ARGS(
    hipUserObject_t, object,
    unsigned int, count
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, object, (uintptr_t)(object))
    ctf_integer(unsigned int, count, count)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipUserObjectRelease_exit,
  TP_ARGS(
    hipUserObject_t, object,
    unsigned int, count,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipUserObjectRetain_entry,
  TP_ARGS(
    hipUserObject_t, object,
    unsigned int, count
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, object, (uintptr_t)(object))
    ctf_integer(unsigned int, count, count)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipUserObjectRetain_exit,
  TP_ARGS(
    hipUserObject_t, object,
    unsigned int, count,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphRetainUserObject_entry,
  TP_ARGS(
    hipGraph_t, graph,
    hipUserObject_t, object,
    unsigned int, count,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, object, (uintptr_t)(object))
    ctf_integer(unsigned int, count, count)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphRetainUserObject_exit,
  TP_ARGS(
    hipGraph_t, graph,
    hipUserObject_t, object,
    unsigned int, count,
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphReleaseUserObject_entry,
  TP_ARGS(
    hipGraph_t, graph,
    hipUserObject_t, object,
    unsigned int, count
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, object, (uintptr_t)(object))
    ctf_integer(unsigned int, count, count)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphReleaseUserObject_exit,
  TP_ARGS(
    hipGraph_t, graph,
    hipUserObject_t, object,
    unsigned int, count,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemAddressFree_entry,
  TP_ARGS(
    void *, devPtr,
    size_t, size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
    ctf_integer(size_t, size, size)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemAddressFree_exit,
  TP_ARGS(
    void *, devPtr,
    size_t, size,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemAddressReserve_entry,
  TP_ARGS(
    void **, ptr,
    size_t, size,
    size_t, alignment,
    void *, addr,
    unsigned long long int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)(ptr))
    ctf_integer(size_t, size, size)
    ctf_integer(size_t, alignment, alignment)
    ctf_integer_hex(uintptr_t, addr, (uintptr_t)(addr))
    ctf_integer(unsigned long long int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemAddressReserve_exit,
  TP_ARGS(
    void **, ptr,
    size_t, size,
    size_t, alignment,
    void *, addr,
    unsigned long long int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, ptr_val, (uintptr_t)((ptr ? *ptr : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemCreate_entry,
  TP_ARGS(
    hipMemGenericAllocationHandle_t *, handle,
    size_t, size,
    const hipMemAllocationProp *, prop,
    unsigned long long int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, handle, (uintptr_t)(handle))
    ctf_integer(size_t, size, size)
    ctf_integer_hex(uintptr_t, prop, (uintptr_t)(prop))
    ctf_integer(unsigned long long int, flags, flags)
    ctf_sequence_text(uint8_t, prop_val, prop, size_t, (prop ? sizeof(hipMemAllocationProp) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemCreate_exit,
  TP_ARGS(
    hipMemGenericAllocationHandle_t *, handle,
    size_t, size,
    const hipMemAllocationProp *, prop,
    unsigned long long int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, handle_val, (uintptr_t)((handle ? *handle : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemExportToShareableHandle_entry,
  TP_ARGS(
    void *, shareableHandle,
    hipMemGenericAllocationHandle_t, handle,
    hipMemAllocationHandleType, handleType,
    unsigned long long int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, shareableHandle, (uintptr_t)(shareableHandle))
    ctf_integer_hex(uintptr_t, handle, (uintptr_t)(handle))
    ctf_integer(int32_t, handleType, handleType)
    ctf_integer(unsigned long long int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemExportToShareableHandle_exit,
  TP_ARGS(
    void *, shareableHandle,
    hipMemGenericAllocationHandle_t, handle,
    hipMemAllocationHandleType, handleType,
    unsigned long long int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_sequence_text(uint8_t, shareableHandle_val, shareableHandle, size_t, handleType == hipMemHandleTypePosixFileDescriptor ? sizeof(int) : 0)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemGetAccess_entry,
  TP_ARGS(
    unsigned long long int *, flags,
    const hipMemLocation *, location,
    void *, ptr
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, flags, (uintptr_t)(flags))
    ctf_integer_hex(uintptr_t, location, (uintptr_t)(location))
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)(ptr))
    ctf_sequence_text(uint8_t, location_val, location, size_t, (location ? sizeof(hipMemLocation) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemGetAccess_exit,
  TP_ARGS(
    unsigned long long int *, flags,
    const hipMemLocation *, location,
    void *, ptr,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(unsigned long long int, flags_val, (flags ? *flags : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemGetAllocationGranularity_entry,
  TP_ARGS(
    size_t *, granularity,
    const hipMemAllocationProp *, prop,
    hipMemAllocationGranularity_flags, option
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, granularity, (uintptr_t)(granularity))
    ctf_integer_hex(uintptr_t, prop, (uintptr_t)(prop))
    ctf_integer(int32_t, option, option)
    ctf_sequence_text(uint8_t, prop_val, prop, size_t, (prop ? sizeof(hipMemAllocationProp) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemGetAllocationGranularity_exit,
  TP_ARGS(
    size_t *, granularity,
    const hipMemAllocationProp *, prop,
    hipMemAllocationGranularity_flags, option,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(size_t, granularity_val, (granularity ? *granularity : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemGetAllocationPropertiesFromHandle_entry,
  TP_ARGS(
    hipMemAllocationProp *, prop,
    hipMemGenericAllocationHandle_t, handle
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, prop, (uintptr_t)(prop))
    ctf_integer_hex(uintptr_t, handle, (uintptr_t)(handle))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemGetAllocationPropertiesFromHandle_exit,
  TP_ARGS(
    hipMemAllocationProp *, prop,
    hipMemGenericAllocationHandle_t, handle,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_sequence_text(uint8_t, prop_val, prop, size_t, (prop ? sizeof(hipMemAllocationProp) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemImportFromShareableHandle_entry,
  TP_ARGS(
    hipMemGenericAllocationHandle_t *, handle,
    void *, osHandle,
    hipMemAllocationHandleType, shHandleType
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, handle, (uintptr_t)(handle))
    ctf_integer_hex(uintptr_t, osHandle, (uintptr_t)(osHandle))
    ctf_integer(int32_t, shHandleType, shHandleType)
    ctf_sequence_text(uint8_t, osHandle_val, osHandle, size_t, shHandleType == hipMemHandleTypePosixFileDescriptor ? sizeof(int) : 0)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemImportFromShareableHandle_exit,
  TP_ARGS(
    hipMemGenericAllocationHandle_t *, handle,
    void *, osHandle,
    hipMemAllocationHandleType, shHandleType,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, handle_val, (uintptr_t)((handle ? *handle : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemMap_entry,
  TP_ARGS(
    void *, ptr,
    size_t, size,
    size_t, offset,
    hipMemGenericAllocationHandle_t, handle,
    unsigned long long int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)(ptr))
    ctf_integer(size_t, size, size)
    ctf_integer(size_t, offset, offset)
    ctf_integer_hex(uintptr_t, handle, (uintptr_t)(handle))
    ctf_integer(unsigned long long int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemMap_exit,
  TP_ARGS(
    void *, ptr,
    size_t, size,
    size_t, offset,
    hipMemGenericAllocationHandle_t, handle,
    unsigned long long int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemMapArrayAsync_entry,
  TP_ARGS(
    hipArrayMapInfo *, mapInfoList,
    unsigned int, count,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mapInfoList, (uintptr_t)(mapInfoList))
    ctf_integer(unsigned int, count, count)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_sequence_text(uint8_t, mapInfoList_val, mapInfoList, size_t, (mapInfoList ? sizeof(hipArrayMapInfo) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemMapArrayAsync_exit,
  TP_ARGS(
    hipArrayMapInfo *, mapInfoList,
    unsigned int, count,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemRelease_entry,
  TP_ARGS(
    hipMemGenericAllocationHandle_t, handle
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, handle, (uintptr_t)(handle))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemRelease_exit,
  TP_ARGS(
    hipMemGenericAllocationHandle_t, handle,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemRetainAllocationHandle_entry,
  TP_ARGS(
    hipMemGenericAllocationHandle_t *, handle,
    void *, addr
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, handle, (uintptr_t)(handle))
    ctf_integer_hex(uintptr_t, addr, (uintptr_t)(addr))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemRetainAllocationHandle_exit,
  TP_ARGS(
    hipMemGenericAllocationHandle_t *, handle,
    void *, addr,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, handle_val, (uintptr_t)((handle ? *handle : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemSetAccess_entry,
  TP_ARGS(
    void *, ptr,
    size_t, size,
    const hipMemAccessDesc *, desc,
    size_t, count
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)(ptr))
    ctf_integer(size_t, size, size)
    ctf_integer_hex(uintptr_t, desc, (uintptr_t)(desc))
    ctf_integer(size_t, count, count)
    ctf_sequence_text(uint8_t, desc_vals, desc, size_t, ((desc ? count : 0)) * sizeof(hipMemAccessDesc))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemSetAccess_exit,
  TP_ARGS(
    void *, ptr,
    size_t, size,
    const hipMemAccessDesc *, desc,
    size_t, count,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemUnmap_entry,
  TP_ARGS(
    void *, ptr,
    size_t, size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)(ptr))
    ctf_integer(size_t, size, size)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemUnmap_exit,
  TP_ARGS(
    void *, ptr,
    size_t, size,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGLGetDevices_entry,
  TP_ARGS(
    unsigned int *, pHipDeviceCount,
    int *, pHipDevices,
    unsigned int, hipDeviceCount,
    hipGLDeviceList, deviceList
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pHipDeviceCount, (uintptr_t)(pHipDeviceCount))
    ctf_integer_hex(uintptr_t, pHipDevices, (uintptr_t)(pHipDevices))
    ctf_integer(unsigned int, hipDeviceCount, hipDeviceCount)
    ctf_integer(int32_t, deviceList, deviceList)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGLGetDevices_exit,
  TP_ARGS(
    unsigned int *, pHipDeviceCount,
    int *, pHipDevices,
    unsigned int, hipDeviceCount,
    hipGLDeviceList, deviceList,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer(unsigned int, pHipDeviceCount_val, (pHipDeviceCount ? *pHipDeviceCount : 0))
    ctf_sequence(int, pHipDevices_vals, pHipDevices, unsigned int, (pHipDevices ? hipDeviceCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphicsGLRegisterBuffer_entry,
  TP_ARGS(
    hipGraphicsResource **, resource,
    GLuint, buffer,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, resource, (uintptr_t)(resource))
    ctf_integer(GLuint, buffer, buffer)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphicsGLRegisterBuffer_exit,
  TP_ARGS(
    hipGraphicsResource **, resource,
    GLuint, buffer,
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, resource_val, (uintptr_t)((resource ? *resource : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphicsGLRegisterImage_entry,
  TP_ARGS(
    hipGraphicsResource **, resource,
    GLuint, image,
    GLenum, target,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, resource, (uintptr_t)(resource))
    ctf_integer(GLuint, image, image)
    ctf_integer(GLenum, target, target)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphicsGLRegisterImage_exit,
  TP_ARGS(
    hipGraphicsResource **, resource,
    GLuint, image,
    GLenum, target,
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, resource_val, (uintptr_t)((resource ? *resource : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphicsMapResources_entry,
  TP_ARGS(
    int, count,
    hipGraphicsResource_t *, resources,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer(int, count, count)
    ctf_integer_hex(uintptr_t, resources, (uintptr_t)(resources))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_sequence_hex(uintptr_t, resources_vals, resources, size_t, (resources ? (count < 0 ? 0 : (size_t)count) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphicsMapResources_exit,
  TP_ARGS(
    int, count,
    hipGraphicsResource_t *, resources,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphicsSubResourceGetMappedArray_entry,
  TP_ARGS(
    hipArray_t *, array,
    hipGraphicsResource_t, resource,
    unsigned int, arrayIndex,
    unsigned int, mipLevel
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, array, (uintptr_t)(array))
    ctf_integer_hex(uintptr_t, resource, (uintptr_t)(resource))
    ctf_integer(unsigned int, arrayIndex, arrayIndex)
    ctf_integer(unsigned int, mipLevel, mipLevel)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphicsSubResourceGetMappedArray_exit,
  TP_ARGS(
    hipArray_t *, array,
    hipGraphicsResource_t, resource,
    unsigned int, arrayIndex,
    unsigned int, mipLevel,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, array_val, (uintptr_t)((array ? *array : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphicsResourceGetMappedPointer_entry,
  TP_ARGS(
    void **, devPtr,
    size_t *, size,
    hipGraphicsResource_t, resource
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
    ctf_integer_hex(uintptr_t, size, (uintptr_t)(size))
    ctf_integer_hex(uintptr_t, resource, (uintptr_t)(resource))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphicsResourceGetMappedPointer_exit,
  TP_ARGS(
    void **, devPtr,
    size_t *, size,
    hipGraphicsResource_t, resource,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, devPtr_val, (uintptr_t)((devPtr ? *devPtr : 0)))
    ctf_integer(size_t, size_val, (size ? *size : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphicsUnmapResources_entry,
  TP_ARGS(
    int, count,
    hipGraphicsResource_t *, resources,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer(int, count, count)
    ctf_integer_hex(uintptr_t, resources, (uintptr_t)(resources))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_sequence_hex(uintptr_t, resources_vals, resources, size_t, (resources ? (count < 0 ? 0 : (size_t)count) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphicsUnmapResources_exit,
  TP_ARGS(
    int, count,
    hipGraphicsResource_t *, resources,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphicsUnregisterResource_entry,
  TP_ARGS(
    hipGraphicsResource_t, resource
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, resource, (uintptr_t)(resource))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphicsUnregisterResource_exit,
  TP_ARGS(
    hipGraphicsResource_t, resource,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpy_spt_entry,
  TP_ARGS(
    void *, dst,
    const void *, src,
    size_t, sizeBytes,
    hipMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, sizeBytes, sizeBytes)
    ctf_integer(int32_t, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpy_spt_exit,
  TP_ARGS(
    void *, dst,
    const void *, src,
    size_t, sizeBytes,
    hipMemcpyKind, kind,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyToSymbol_spt_entry,
  TP_ARGS(
    const void *, symbol,
    const void *, src,
    size_t, sizeBytes,
    size_t, offset,
    hipMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, sizeBytes, sizeBytes)
    ctf_integer(size_t, offset, offset)
    ctf_integer(int32_t, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyToSymbol_spt_exit,
  TP_ARGS(
    const void *, symbol,
    const void *, src,
    size_t, sizeBytes,
    size_t, offset,
    hipMemcpyKind, kind,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyFromSymbol_spt_entry,
  TP_ARGS(
    void *, dst,
    const void *, symbol,
    size_t, sizeBytes,
    size_t, offset,
    hipMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
    ctf_integer(size_t, sizeBytes, sizeBytes)
    ctf_integer(size_t, offset, offset)
    ctf_integer(int32_t, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyFromSymbol_spt_exit,
  TP_ARGS(
    void *, dst,
    const void *, symbol,
    size_t, sizeBytes,
    size_t, offset,
    hipMemcpyKind, kind,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpy2D_spt_entry,
  TP_ARGS(
    void *, dst,
    size_t, dpitch,
    const void *, src,
    size_t, spitch,
    size_t, width,
    size_t, height,
    hipMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, dpitch, dpitch)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, spitch, spitch)
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
    ctf_integer(int32_t, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpy2D_spt_exit,
  TP_ARGS(
    void *, dst,
    size_t, dpitch,
    const void *, src,
    size_t, spitch,
    size_t, width,
    size_t, height,
    hipMemcpyKind, kind,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpy2DFromArray_spt_entry,
  TP_ARGS(
    void *, dst,
    size_t, dpitch,
    hipArray_const_t, src,
    size_t, wOffset,
    size_t, hOffset,
    size_t, width,
    size_t, height,
    hipMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, dpitch, dpitch)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, wOffset, wOffset)
    ctf_integer(size_t, hOffset, hOffset)
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
    ctf_integer(int32_t, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpy2DFromArray_spt_exit,
  TP_ARGS(
    void *, dst,
    size_t, dpitch,
    hipArray_const_t, src,
    size_t, wOffset,
    size_t, hOffset,
    size_t, width,
    size_t, height,
    hipMemcpyKind, kind,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpy3D_spt_entry,
  TP_ARGS(
    const struct hipMemcpy3DParms *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpy3D_spt_exit,
  TP_ARGS(
    const struct hipMemcpy3DParms *, p,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemset_spt_entry,
  TP_ARGS(
    void *, dst,
    int, value,
    size_t, sizeBytes
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(int, value, value)
    ctf_integer(size_t, sizeBytes, sizeBytes)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemset_spt_exit,
  TP_ARGS(
    void *, dst,
    int, value,
    size_t, sizeBytes,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemsetAsync_spt_entry,
  TP_ARGS(
    void *, dst,
    int, value,
    size_t, sizeBytes,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(int, value, value)
    ctf_integer(size_t, sizeBytes, sizeBytes)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemsetAsync_spt_exit,
  TP_ARGS(
    void *, dst,
    int, value,
    size_t, sizeBytes,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemset2D_spt_entry,
  TP_ARGS(
    void *, dst,
    size_t, pitch,
    int, value,
    size_t, width,
    size_t, height
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, pitch, pitch)
    ctf_integer(int, value, value)
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemset2D_spt_exit,
  TP_ARGS(
    void *, dst,
    size_t, pitch,
    int, value,
    size_t, width,
    size_t, height,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemset2DAsync_spt_entry,
  TP_ARGS(
    void *, dst,
    size_t, pitch,
    int, value,
    size_t, width,
    size_t, height,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, pitch, pitch)
    ctf_integer(int, value, value)
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemset2DAsync_spt_exit,
  TP_ARGS(
    void *, dst,
    size_t, pitch,
    int, value,
    size_t, width,
    size_t, height,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemset3DAsync_spt_entry,
  TP_ARGS(
    hipPitchedPtr, pitchedDevPtr,
    int, value,
    hipExtent, extent,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_array_text(uint8_t, pitchedDevPtr, &pitchedDevPtr, sizeof(hipPitchedPtr))
    ctf_integer(int, value, value)
    ctf_array_text(uint8_t, extent, &extent, sizeof(hipExtent))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemset3DAsync_spt_exit,
  TP_ARGS(
    hipPitchedPtr, pitchedDevPtr,
    int, value,
    hipExtent, extent,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemset3D_spt_entry,
  TP_ARGS(
    hipPitchedPtr, pitchedDevPtr,
    int, value,
    hipExtent, extent
  ),
  TP_FIELDS(
    ctf_array_text(uint8_t, pitchedDevPtr, &pitchedDevPtr, sizeof(hipPitchedPtr))
    ctf_integer(int, value, value)
    ctf_array_text(uint8_t, extent, &extent, sizeof(hipExtent))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemset3D_spt_exit,
  TP_ARGS(
    hipPitchedPtr, pitchedDevPtr,
    int, value,
    hipExtent, extent,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyAsync_spt_entry,
  TP_ARGS(
    void *, dst,
    const void *, src,
    size_t, sizeBytes,
    hipMemcpyKind, kind,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, sizeBytes, sizeBytes)
    ctf_integer(int32_t, kind, kind)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyAsync_spt_exit,
  TP_ARGS(
    void *, dst,
    const void *, src,
    size_t, sizeBytes,
    hipMemcpyKind, kind,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpy3DAsync_spt_entry,
  TP_ARGS(
    const hipMemcpy3DParms *, p,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpy3DAsync_spt_exit,
  TP_ARGS(
    const hipMemcpy3DParms *, p,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpy2DAsync_spt_entry,
  TP_ARGS(
    void *, dst,
    size_t, dpitch,
    const void *, src,
    size_t, spitch,
    size_t, width,
    size_t, height,
    hipMemcpyKind, kind,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, dpitch, dpitch)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, spitch, spitch)
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
    ctf_integer(int32_t, kind, kind)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpy2DAsync_spt_exit,
  TP_ARGS(
    void *, dst,
    size_t, dpitch,
    const void *, src,
    size_t, spitch,
    size_t, width,
    size_t, height,
    hipMemcpyKind, kind,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyFromSymbolAsync_spt_entry,
  TP_ARGS(
    void *, dst,
    const void *, symbol,
    size_t, sizeBytes,
    size_t, offset,
    hipMemcpyKind, kind,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
    ctf_integer(size_t, sizeBytes, sizeBytes)
    ctf_integer(size_t, offset, offset)
    ctf_integer(int32_t, kind, kind)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyFromSymbolAsync_spt_exit,
  TP_ARGS(
    void *, dst,
    const void *, symbol,
    size_t, sizeBytes,
    size_t, offset,
    hipMemcpyKind, kind,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyToSymbolAsync_spt_entry,
  TP_ARGS(
    const void *, symbol,
    const void *, src,
    size_t, sizeBytes,
    size_t, offset,
    hipMemcpyKind, kind,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, sizeBytes, sizeBytes)
    ctf_integer(size_t, offset, offset)
    ctf_integer(int32_t, kind, kind)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyToSymbolAsync_spt_exit,
  TP_ARGS(
    const void *, symbol,
    const void *, src,
    size_t, sizeBytes,
    size_t, offset,
    hipMemcpyKind, kind,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyFromArray_spt_entry,
  TP_ARGS(
    void *, dst,
    hipArray_const_t, src,
    size_t, wOffsetSrc,
    size_t, hOffset,
    size_t, count,
    hipMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, wOffsetSrc, wOffsetSrc)
    ctf_integer(size_t, hOffset, hOffset)
    ctf_integer(size_t, count, count)
    ctf_integer(int32_t, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpyFromArray_spt_exit,
  TP_ARGS(
    void *, dst,
    hipArray_const_t, src,
    size_t, wOffsetSrc,
    size_t, hOffset,
    size_t, count,
    hipMemcpyKind, kind,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpy2DToArray_spt_entry,
  TP_ARGS(
    hipArray *, dst,
    size_t, wOffset,
    size_t, hOffset,
    const void *, src,
    size_t, spitch,
    size_t, width,
    size_t, height,
    hipMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, wOffset, wOffset)
    ctf_integer(size_t, hOffset, hOffset)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, spitch, spitch)
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
    ctf_integer(int32_t, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpy2DToArray_spt_exit,
  TP_ARGS(
    hipArray *, dst,
    size_t, wOffset,
    size_t, hOffset,
    const void *, src,
    size_t, spitch,
    size_t, width,
    size_t, height,
    hipMemcpyKind, kind,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpy2DFromArrayAsync_spt_entry,
  TP_ARGS(
    void *, dst,
    size_t, dpitch,
    hipArray_const_t, src,
    size_t, wOffsetSrc,
    size_t, hOffsetSrc,
    size_t, width,
    size_t, height,
    hipMemcpyKind, kind,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, dpitch, dpitch)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, wOffsetSrc, wOffsetSrc)
    ctf_integer(size_t, hOffsetSrc, hOffsetSrc)
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
    ctf_integer(int32_t, kind, kind)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpy2DFromArrayAsync_spt_exit,
  TP_ARGS(
    void *, dst,
    size_t, dpitch,
    hipArray_const_t, src,
    size_t, wOffsetSrc,
    size_t, hOffsetSrc,
    size_t, width,
    size_t, height,
    hipMemcpyKind, kind,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpy2DToArrayAsync_spt_entry,
  TP_ARGS(
    hipArray *, dst,
    size_t, wOffset,
    size_t, hOffset,
    const void *, src,
    size_t, spitch,
    size_t, width,
    size_t, height,
    hipMemcpyKind, kind,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, wOffset, wOffset)
    ctf_integer(size_t, hOffset, hOffset)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, spitch, spitch)
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
    ctf_integer(int32_t, kind, kind)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipMemcpy2DToArrayAsync_spt_exit,
  TP_ARGS(
    hipArray *, dst,
    size_t, wOffset,
    size_t, hOffset,
    const void *, src,
    size_t, spitch,
    size_t, width,
    size_t, height,
    hipMemcpyKind, kind,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamQuery_spt_entry,
  TP_ARGS(
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamQuery_spt_exit,
  TP_ARGS(
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamSynchronize_spt_entry,
  TP_ARGS(
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamSynchronize_spt_exit,
  TP_ARGS(
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamGetPriority_spt_entry,
  TP_ARGS(
    hipStream_t, stream,
    int *, priority
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, priority, (uintptr_t)(priority))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamGetPriority_spt_exit,
  TP_ARGS(
    hipStream_t, stream,
    int *, priority,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamWaitEvent_spt_entry,
  TP_ARGS(
    hipStream_t, stream,
    hipEvent_t, event,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamWaitEvent_spt_exit,
  TP_ARGS(
    hipStream_t, stream,
    hipEvent_t, event,
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamGetFlags_spt_entry,
  TP_ARGS(
    hipStream_t, stream,
    unsigned int *, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, flags, (uintptr_t)(flags))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamGetFlags_spt_exit,
  TP_ARGS(
    hipStream_t, stream,
    unsigned int *, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamAddCallback_spt_entry,
  TP_ARGS(
    hipStream_t, stream,
    hipStreamCallback_t, callback,
    void *, userData,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, callback, (uintptr_t)(callback))
    ctf_integer_hex(uintptr_t, userData, (uintptr_t)(userData))
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamAddCallback_spt_exit,
  TP_ARGS(
    hipStream_t, stream,
    hipStreamCallback_t, callback,
    void *, userData,
    unsigned int, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipEventRecord_spt_entry,
  TP_ARGS(
    hipEvent_t, event,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipEventRecord_spt_exit,
  TP_ARGS(
    hipEvent_t, event,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipLaunchCooperativeKernel_spt_entry,
  TP_ARGS(
    const void *, f,
    dim3, gridDim,
    dim3, blockDim,
    void **, kernelParams,
    uint32_t, sharedMemBytes,
    hipStream_t, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, f, (uintptr_t)(f))
    ctf_array_text(uint8_t, gridDim, &gridDim, sizeof(dim3))
    ctf_array_text(uint8_t, blockDim, &blockDim, sizeof(dim3))
    ctf_integer_hex(uintptr_t, kernelParams, (uintptr_t)(kernelParams))
    ctf_integer(uint32_t, sharedMemBytes, sharedMemBytes)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipLaunchCooperativeKernel_spt_exit,
  TP_ARGS(
    const void *, f,
    dim3, gridDim,
    dim3, blockDim,
    void **, kernelParams,
    uint32_t, sharedMemBytes,
    hipStream_t, hStream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipLaunchKernel_spt_entry,
  TP_ARGS(
    const void *, function_address,
    dim3, numBlocks,
    dim3, dimBlocks,
    void **, args,
    size_t, sharedMemBytes,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, function_address, (uintptr_t)(function_address))
    ctf_array_text(uint8_t, numBlocks, &numBlocks, sizeof(dim3))
    ctf_array_text(uint8_t, dimBlocks, &dimBlocks, sizeof(dim3))
    ctf_integer_hex(uintptr_t, args, (uintptr_t)(args))
    ctf_integer(size_t, sharedMemBytes, sharedMemBytes)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipLaunchKernel_spt_exit,
  TP_ARGS(
    const void *, function_address,
    dim3, numBlocks,
    dim3, dimBlocks,
    void **, args,
    size_t, sharedMemBytes,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphLaunch_spt_entry,
  TP_ARGS(
    hipGraphExec_t, graphExec,
    hipStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, graphExec, (uintptr_t)(graphExec))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphLaunch_spt_exit,
  TP_ARGS(
    hipGraphExec_t, graphExec,
    hipStream_t, stream,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamBeginCapture_spt_entry,
  TP_ARGS(
    hipStream_t, stream,
    hipStreamCaptureMode, mode
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer(int32_t, mode, mode)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamBeginCapture_spt_exit,
  TP_ARGS(
    hipStream_t, stream,
    hipStreamCaptureMode, mode,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamEndCapture_spt_entry,
  TP_ARGS(
    hipStream_t, stream,
    hipGraph_t *, pGraph
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, pGraph, (uintptr_t)(pGraph))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamEndCapture_spt_exit,
  TP_ARGS(
    hipStream_t, stream,
    hipGraph_t *, pGraph,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamIsCapturing_spt_entry,
  TP_ARGS(
    hipStream_t, stream,
    hipStreamCaptureStatus *, pCaptureStatus
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, pCaptureStatus, (uintptr_t)(pCaptureStatus))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamIsCapturing_spt_exit,
  TP_ARGS(
    hipStream_t, stream,
    hipStreamCaptureStatus *, pCaptureStatus,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamGetCaptureInfo_spt_entry,
  TP_ARGS(
    hipStream_t, stream,
    hipStreamCaptureStatus *, pCaptureStatus,
    unsigned long long int *, pId
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, pCaptureStatus, (uintptr_t)(pCaptureStatus))
    ctf_integer_hex(uintptr_t, pId, (uintptr_t)(pId))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamGetCaptureInfo_spt_exit,
  TP_ARGS(
    hipStream_t, stream,
    hipStreamCaptureStatus *, pCaptureStatus,
    unsigned long long int *, pId,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamGetCaptureInfo_v2_spt_entry,
  TP_ARGS(
    hipStream_t, stream,
    hipStreamCaptureStatus *, captureStatus_out,
    unsigned long long int *, id_out,
    hipGraph_t *, graph_out,
    const hipGraphNode_t **, dependencies_out,
    size_t *, numDependencies_out
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, captureStatus_out, (uintptr_t)(captureStatus_out))
    ctf_integer_hex(uintptr_t, id_out, (uintptr_t)(id_out))
    ctf_integer_hex(uintptr_t, graph_out, (uintptr_t)(graph_out))
    ctf_integer_hex(uintptr_t, dependencies_out, (uintptr_t)(dependencies_out))
    ctf_integer_hex(uintptr_t, numDependencies_out, (uintptr_t)(numDependencies_out))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipStreamGetCaptureInfo_v2_spt_exit,
  TP_ARGS(
    hipStream_t, stream,
    hipStreamCaptureStatus *, captureStatus_out,
    unsigned long long int *, id_out,
    hipGraph_t *, graph_out,
    const hipGraphNode_t **, dependencies_out,
    size_t *, numDependencies_out,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipLaunchHostFunc_spt_entry,
  TP_ARGS(
    hipStream_t, stream,
    hipHostFn_t, fn,
    void *, userData
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, fn, (uintptr_t)(fn))
    ctf_integer_hex(uintptr_t, userData, (uintptr_t)(userData))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipLaunchHostFunc_spt_exit,
  TP_ARGS(
    hipStream_t, stream,
    hipHostFn_t, fn,
    void *, userData,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hiprtcGetErrorString_entry,
  TP_ARGS(
    hiprtcResult, result
  ),
  TP_FIELDS(
    ctf_integer(int32_t, result, result)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hiprtcGetErrorString_exit,
  TP_ARGS(
    hiprtcResult, result,
    const char *, hipResult
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hipResult, (uintptr_t)(hipResult))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hiprtcVersion_entry,
  TP_ARGS(
    int *, major,
    int *, minor
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, major, (uintptr_t)(major))
    ctf_integer_hex(uintptr_t, minor, (uintptr_t)(minor))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hiprtcVersion_exit,
  TP_ARGS(
    int *, major,
    int *, minor,
    hiprtcResult, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hiprtcAddNameExpression_entry,
  TP_ARGS(
    hiprtcProgram, prog,
    const char *, name_expression
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, prog, (uintptr_t)(prog))
    ctf_integer_hex(uintptr_t, name_expression, (uintptr_t)(name_expression))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hiprtcAddNameExpression_exit,
  TP_ARGS(
    hiprtcProgram, prog,
    const char *, name_expression,
    hiprtcResult, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hiprtcCompileProgram_entry,
  TP_ARGS(
    hiprtcProgram, prog,
    int, numOptions,
    const char **, options
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, prog, (uintptr_t)(prog))
    ctf_integer(int, numOptions, numOptions)
    ctf_integer_hex(uintptr_t, options, (uintptr_t)(options))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hiprtcCompileProgram_exit,
  TP_ARGS(
    hiprtcProgram, prog,
    int, numOptions,
    const char **, options,
    hiprtcResult, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hiprtcCreateProgram_entry,
  TP_ARGS(
    hiprtcProgram *, prog,
    const char *, src,
    const char *, name,
    int, numHeaders,
    const char **, headers,
    const char **, includeNames
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, prog, (uintptr_t)(prog))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer_hex(uintptr_t, name, (uintptr_t)(name))
    ctf_integer(int, numHeaders, numHeaders)
    ctf_integer_hex(uintptr_t, headers, (uintptr_t)(headers))
    ctf_integer_hex(uintptr_t, includeNames, (uintptr_t)(includeNames))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hiprtcCreateProgram_exit,
  TP_ARGS(
    hiprtcProgram *, prog,
    const char *, src,
    const char *, name,
    int, numHeaders,
    const char **, headers,
    const char **, includeNames,
    hiprtcResult, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hiprtcDestroyProgram_entry,
  TP_ARGS(
    hiprtcProgram *, prog
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, prog, (uintptr_t)(prog))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hiprtcDestroyProgram_exit,
  TP_ARGS(
    hiprtcProgram *, prog,
    hiprtcResult, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hiprtcGetLoweredName_entry,
  TP_ARGS(
    hiprtcProgram, prog,
    const char *, name_expression,
    const char **, lowered_name
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, prog, (uintptr_t)(prog))
    ctf_integer_hex(uintptr_t, name_expression, (uintptr_t)(name_expression))
    ctf_integer_hex(uintptr_t, lowered_name, (uintptr_t)(lowered_name))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hiprtcGetLoweredName_exit,
  TP_ARGS(
    hiprtcProgram, prog,
    const char *, name_expression,
    const char **, lowered_name,
    hiprtcResult, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hiprtcGetProgramLog_entry,
  TP_ARGS(
    hiprtcProgram, prog,
    char *, log
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, prog, (uintptr_t)(prog))
    ctf_integer_hex(uintptr_t, log, (uintptr_t)(log))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hiprtcGetProgramLog_exit,
  TP_ARGS(
    hiprtcProgram, prog,
    char *, log,
    hiprtcResult, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hiprtcGetProgramLogSize_entry,
  TP_ARGS(
    hiprtcProgram, prog,
    size_t *, logSizeRet
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, prog, (uintptr_t)(prog))
    ctf_integer_hex(uintptr_t, logSizeRet, (uintptr_t)(logSizeRet))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hiprtcGetProgramLogSize_exit,
  TP_ARGS(
    hiprtcProgram, prog,
    size_t *, logSizeRet,
    hiprtcResult, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hiprtcGetCode_entry,
  TP_ARGS(
    hiprtcProgram, prog,
    char *, code
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, prog, (uintptr_t)(prog))
    ctf_integer_hex(uintptr_t, code, (uintptr_t)(code))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hiprtcGetCode_exit,
  TP_ARGS(
    hiprtcProgram, prog,
    char *, code,
    hiprtcResult, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hiprtcGetCodeSize_entry,
  TP_ARGS(
    hiprtcProgram, prog,
    size_t *, codeSizeRet
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, prog, (uintptr_t)(prog))
    ctf_integer_hex(uintptr_t, codeSizeRet, (uintptr_t)(codeSizeRet))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hiprtcGetCodeSize_exit,
  TP_ARGS(
    hiprtcProgram, prog,
    size_t *, codeSizeRet,
    hiprtcResult, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hiprtcGetBitcode_entry,
  TP_ARGS(
    hiprtcProgram, prog,
    char *, bitcode
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, prog, (uintptr_t)(prog))
    ctf_integer_hex(uintptr_t, bitcode, (uintptr_t)(bitcode))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hiprtcGetBitcode_exit,
  TP_ARGS(
    hiprtcProgram, prog,
    char *, bitcode,
    hiprtcResult, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hiprtcGetBitcodeSize_entry,
  TP_ARGS(
    hiprtcProgram, prog,
    size_t *, bitcode_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, prog, (uintptr_t)(prog))
    ctf_integer_hex(uintptr_t, bitcode_size, (uintptr_t)(bitcode_size))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hiprtcGetBitcodeSize_exit,
  TP_ARGS(
    hiprtcProgram, prog,
    size_t *, bitcode_size,
    hiprtcResult, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hiprtcLinkCreate_entry,
  TP_ARGS(
    unsigned int, num_options,
    hiprtcJIT_option *, option_ptr,
    void **, option_vals_pptr,
    hiprtcLinkState *, hip_link_state_ptr
  ),
  TP_FIELDS(
    ctf_integer(unsigned int, num_options, num_options)
    ctf_integer_hex(uintptr_t, option_ptr, (uintptr_t)(option_ptr))
    ctf_integer_hex(uintptr_t, option_vals_pptr, (uintptr_t)(option_vals_pptr))
    ctf_integer_hex(uintptr_t, hip_link_state_ptr, (uintptr_t)(hip_link_state_ptr))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hiprtcLinkCreate_exit,
  TP_ARGS(
    unsigned int, num_options,
    hiprtcJIT_option *, option_ptr,
    void **, option_vals_pptr,
    hiprtcLinkState *, hip_link_state_ptr,
    hiprtcResult, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hiprtcLinkAddFile_entry,
  TP_ARGS(
    hiprtcLinkState, hip_link_state,
    hiprtcJITInputType, input_type,
    const char *, file_path,
    unsigned int, num_options,
    hiprtcJIT_option *, options_ptr,
    void **, option_values
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hip_link_state, (uintptr_t)(hip_link_state))
    ctf_integer(int32_t, input_type, input_type)
    ctf_integer_hex(uintptr_t, file_path, (uintptr_t)(file_path))
    ctf_integer(unsigned int, num_options, num_options)
    ctf_integer_hex(uintptr_t, options_ptr, (uintptr_t)(options_ptr))
    ctf_integer_hex(uintptr_t, option_values, (uintptr_t)(option_values))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hiprtcLinkAddFile_exit,
  TP_ARGS(
    hiprtcLinkState, hip_link_state,
    hiprtcJITInputType, input_type,
    const char *, file_path,
    unsigned int, num_options,
    hiprtcJIT_option *, options_ptr,
    void **, option_values,
    hiprtcResult, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hiprtcLinkAddData_entry,
  TP_ARGS(
    hiprtcLinkState, hip_link_state,
    hiprtcJITInputType, input_type,
    void *, image,
    size_t, image_size,
    const char *, name,
    unsigned int, num_options,
    hiprtcJIT_option *, options_ptr,
    void **, option_values
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hip_link_state, (uintptr_t)(hip_link_state))
    ctf_integer(int32_t, input_type, input_type)
    ctf_integer_hex(uintptr_t, image, (uintptr_t)(image))
    ctf_integer(size_t, image_size, image_size)
    ctf_integer_hex(uintptr_t, name, (uintptr_t)(name))
    ctf_integer(unsigned int, num_options, num_options)
    ctf_integer_hex(uintptr_t, options_ptr, (uintptr_t)(options_ptr))
    ctf_integer_hex(uintptr_t, option_values, (uintptr_t)(option_values))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hiprtcLinkAddData_exit,
  TP_ARGS(
    hiprtcLinkState, hip_link_state,
    hiprtcJITInputType, input_type,
    void *, image,
    size_t, image_size,
    const char *, name,
    unsigned int, num_options,
    hiprtcJIT_option *, options_ptr,
    void **, option_values,
    hiprtcResult, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hiprtcLinkComplete_entry,
  TP_ARGS(
    hiprtcLinkState, hip_link_state,
    void **, bin_out,
    size_t *, size_out
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hip_link_state, (uintptr_t)(hip_link_state))
    ctf_integer_hex(uintptr_t, bin_out, (uintptr_t)(bin_out))
    ctf_integer_hex(uintptr_t, size_out, (uintptr_t)(size_out))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hiprtcLinkComplete_exit,
  TP_ARGS(
    hiprtcLinkState, hip_link_state,
    void **, bin_out,
    size_t *, size_out,
    hiprtcResult, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hiprtcLinkDestroy_entry,
  TP_ARGS(
    hiprtcLinkState, hip_link_state
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hip_link_state, (uintptr_t)(hip_link_state))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hiprtcLinkDestroy_exit,
  TP_ARGS(
    hiprtcLinkState, hip_link_state,
    hiprtcResult, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  amd_dbgapi_get_build_name_entry,
  TP_ARGS(
    void
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  amd_dbgapi_get_build_name_exit,
  TP_ARGS(
    const char *, hipResult
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hipResult, (uintptr_t)(hipResult))
    ctf_string(hipResult_val, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  amd_dbgapi_get_git_hash_entry,
  TP_ARGS(
    void
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  amd_dbgapi_get_git_hash_exit,
  TP_ARGS(
    const char *, hipResult
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hipResult, (uintptr_t)(hipResult))
    ctf_string(hipResult_val, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  amd_dbgapi_get_build_id_entry,
  TP_ARGS(
    void
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  amd_dbgapi_get_build_id_exit,
  TP_ARGS(
    size_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(size_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipExtModuleLaunchKernel_entry,
  TP_ARGS(
    hipFunction_t, f,
    uint32_t, globalWorkSizeX,
    uint32_t, globalWorkSizeY,
    uint32_t, globalWorkSizeZ,
    uint32_t, localWorkSizeX,
    uint32_t, localWorkSizeY,
    uint32_t, localWorkSizeZ,
    size_t, sharedMemBytes,
    hipStream_t, hStream,
    void **, kernelParams,
    void **, extra,
    hipEvent_t, startEvent,
    hipEvent_t, stopEvent,
    uint32_t, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, f, (uintptr_t)(f))
    ctf_integer(uint32_t, globalWorkSizeX, globalWorkSizeX)
    ctf_integer(uint32_t, globalWorkSizeY, globalWorkSizeY)
    ctf_integer(uint32_t, globalWorkSizeZ, globalWorkSizeZ)
    ctf_integer(uint32_t, localWorkSizeX, localWorkSizeX)
    ctf_integer(uint32_t, localWorkSizeY, localWorkSizeY)
    ctf_integer(uint32_t, localWorkSizeZ, localWorkSizeZ)
    ctf_integer(size_t, sharedMemBytes, sharedMemBytes)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, kernelParams, (uintptr_t)(kernelParams))
    ctf_integer_hex(uintptr_t, extra, (uintptr_t)(extra))
    ctf_integer_hex(uintptr_t, startEvent, (uintptr_t)(startEvent))
    ctf_integer_hex(uintptr_t, stopEvent, (uintptr_t)(stopEvent))
    ctf_integer(uint32_t, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipExtModuleLaunchKernel_exit,
  TP_ARGS(
    hipFunction_t, f,
    uint32_t, globalWorkSizeX,
    uint32_t, globalWorkSizeY,
    uint32_t, globalWorkSizeZ,
    uint32_t, localWorkSizeX,
    uint32_t, localWorkSizeY,
    uint32_t, localWorkSizeZ,
    size_t, sharedMemBytes,
    hipStream_t, hStream,
    void **, kernelParams,
    void **, extra,
    hipEvent_t, startEvent,
    hipEvent_t, stopEvent,
    uint32_t, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipHccModuleLaunchKernel_entry,
  TP_ARGS(
    hipFunction_t, f,
    uint32_t, globalWorkSizeX,
    uint32_t, globalWorkSizeY,
    uint32_t, globalWorkSizeZ,
    uint32_t, localWorkSizeX,
    uint32_t, localWorkSizeY,
    uint32_t, localWorkSizeZ,
    size_t, sharedMemBytes,
    hipStream_t, hStream,
    void **, kernelParams,
    void **, extra,
    hipEvent_t, startEvent,
    hipEvent_t, stopEvent
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, f, (uintptr_t)(f))
    ctf_integer(uint32_t, globalWorkSizeX, globalWorkSizeX)
    ctf_integer(uint32_t, globalWorkSizeY, globalWorkSizeY)
    ctf_integer(uint32_t, globalWorkSizeZ, globalWorkSizeZ)
    ctf_integer(uint32_t, localWorkSizeX, localWorkSizeX)
    ctf_integer(uint32_t, localWorkSizeY, localWorkSizeY)
    ctf_integer(uint32_t, localWorkSizeZ, localWorkSizeZ)
    ctf_integer(size_t, sharedMemBytes, sharedMemBytes)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, kernelParams, (uintptr_t)(kernelParams))
    ctf_integer_hex(uintptr_t, extra, (uintptr_t)(extra))
    ctf_integer_hex(uintptr_t, startEvent, (uintptr_t)(startEvent))
    ctf_integer_hex(uintptr_t, stopEvent, (uintptr_t)(stopEvent))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipHccModuleLaunchKernel_exit,
  TP_ARGS(
    hipFunction_t, f,
    uint32_t, globalWorkSizeX,
    uint32_t, globalWorkSizeY,
    uint32_t, globalWorkSizeZ,
    uint32_t, localWorkSizeX,
    uint32_t, localWorkSizeY,
    uint32_t, localWorkSizeZ,
    size_t, sharedMemBytes,
    hipStream_t, hStream,
    void **, kernelParams,
    void **, extra,
    hipEvent_t, startEvent,
    hipEvent_t, stopEvent,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  _ZN8hip_impl22hipLaunchKernelGGLImplEmRK4dim3S2_jP12ihipStream_tPPv_entry,
  TP_ARGS(
    uintptr_t, function_address,
    const dim3 *, numBlocks,
    const dim3 *, dimBlocks,
    uint32_t, sharedMemBytes,
    hipStream_t, stream,
    void **, kernarg
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, function_address, function_address)
    ctf_integer_hex(uintptr_t, numBlocks, (uintptr_t)(numBlocks))
    ctf_integer_hex(uintptr_t, dimBlocks, (uintptr_t)(dimBlocks))
    ctf_integer(uint32_t, sharedMemBytes, sharedMemBytes)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, kernarg, (uintptr_t)(kernarg))
    ctf_sequence_text(uint8_t, numBlocks_val, numBlocks, size_t, (numBlocks ? sizeof(dim3) : 0))
    ctf_sequence_text(uint8_t, dimBlocks_val, dimBlocks, size_t, (dimBlocks ? sizeof(dim3) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  _ZN8hip_impl22hipLaunchKernelGGLImplEmRK4dim3S2_jP12ihipStream_tPPv_exit,
  TP_ARGS(
    uintptr_t, function_address,
    const dim3 *, numBlocks,
    const dim3 *, dimBlocks,
    uint32_t, sharedMemBytes,
    hipStream_t, stream,
    void **, kernarg
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  _Z22hipCreateSurfaceObjectPP13__hip_surfacePK15hipResourceDesc_entry,
  TP_ARGS(
    hipSurfaceObject_t *, pSurfObject,
    const hipResourceDesc *, pResDesc
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pSurfObject, (uintptr_t)(pSurfObject))
    ctf_integer_hex(uintptr_t, pResDesc, (uintptr_t)(pResDesc))
    ctf_sequence_text(uint8_t, pResDesc_val, pResDesc, size_t, (pResDesc ? sizeof(hipResourceDesc) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  _Z22hipCreateSurfaceObjectPP13__hip_surfacePK15hipResourceDesc_exit,
  TP_ARGS(
    hipSurfaceObject_t *, pSurfObject,
    const hipResourceDesc *, pResDesc,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
    ctf_integer_hex(uintptr_t, pSurfObject_val, (uintptr_t)((pSurfObject ? *pSurfObject : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  _Z23hipDestroySurfaceObjectP13__hip_surface_entry,
  TP_ARGS(
    hipSurfaceObject_t, surfaceObject
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, surfaceObject, (uintptr_t)(surfaceObject))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  _Z23hipDestroySurfaceObjectP13__hip_surface_exit,
  TP_ARGS(
    hipSurfaceObject_t, surfaceObject,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  _Z24hipHccModuleLaunchKernelP18ihipModuleSymbol_tjjjjjjmP12ihipStream_tPPvS4_P11ihipEvent_tS6__entry,
  TP_ARGS(
    hipFunction_t, f,
    uint32_t, globalWorkSizeX,
    uint32_t, globalWorkSizeY,
    uint32_t, globalWorkSizeZ,
    uint32_t, localWorkSizeX,
    uint32_t, localWorkSizeY,
    uint32_t, localWorkSizeZ,
    size_t, sharedMemBytes,
    hipStream_t, hStream,
    void **, kernelParams,
    void **, extra,
    hipEvent_t, startEvent,
    hipEvent_t, stopEvent
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, f, (uintptr_t)(f))
    ctf_integer(uint32_t, globalWorkSizeX, globalWorkSizeX)
    ctf_integer(uint32_t, globalWorkSizeY, globalWorkSizeY)
    ctf_integer(uint32_t, globalWorkSizeZ, globalWorkSizeZ)
    ctf_integer(uint32_t, localWorkSizeX, localWorkSizeX)
    ctf_integer(uint32_t, localWorkSizeY, localWorkSizeY)
    ctf_integer(uint32_t, localWorkSizeZ, localWorkSizeZ)
    ctf_integer(size_t, sharedMemBytes, sharedMemBytes)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, kernelParams, (uintptr_t)(kernelParams))
    ctf_integer_hex(uintptr_t, extra, (uintptr_t)(extra))
    ctf_integer_hex(uintptr_t, startEvent, (uintptr_t)(startEvent))
    ctf_integer_hex(uintptr_t, stopEvent, (uintptr_t)(stopEvent))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  _Z24hipHccModuleLaunchKernelP18ihipModuleSymbol_tjjjjjjmP12ihipStream_tPPvS4_P11ihipEvent_tS6__exit,
  TP_ARGS(
    hipFunction_t, f,
    uint32_t, globalWorkSizeX,
    uint32_t, globalWorkSizeY,
    uint32_t, globalWorkSizeZ,
    uint32_t, localWorkSizeX,
    uint32_t, localWorkSizeY,
    uint32_t, localWorkSizeZ,
    size_t, sharedMemBytes,
    hipStream_t, hStream,
    void **, kernelParams,
    void **, extra,
    hipEvent_t, startEvent,
    hipEvent_t, stopEvent,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  _Z24hipExtModuleLaunchKernelP18ihipModuleSymbol_tjjjjjjmP12ihipStream_tPPvS4_P11ihipEvent_tS6_j_entry,
  TP_ARGS(
    hipFunction_t, f,
    uint32_t, globalWorkSizeX,
    uint32_t, globalWorkSizeY,
    uint32_t, globalWorkSizeZ,
    uint32_t, localWorkSizeX,
    uint32_t, localWorkSizeY,
    uint32_t, localWorkSizeZ,
    size_t, sharedMemBytes,
    hipStream_t, hStream,
    void **, kernelParams,
    void **, extra,
    hipEvent_t, startEvent,
    hipEvent_t, stopEvent,
    uint32_t, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, f, (uintptr_t)(f))
    ctf_integer(uint32_t, globalWorkSizeX, globalWorkSizeX)
    ctf_integer(uint32_t, globalWorkSizeY, globalWorkSizeY)
    ctf_integer(uint32_t, globalWorkSizeZ, globalWorkSizeZ)
    ctf_integer(uint32_t, localWorkSizeX, localWorkSizeX)
    ctf_integer(uint32_t, localWorkSizeY, localWorkSizeY)
    ctf_integer(uint32_t, localWorkSizeZ, localWorkSizeZ)
    ctf_integer(size_t, sharedMemBytes, sharedMemBytes)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, kernelParams, (uintptr_t)(kernelParams))
    ctf_integer_hex(uintptr_t, extra, (uintptr_t)(extra))
    ctf_integer_hex(uintptr_t, startEvent, (uintptr_t)(startEvent))
    ctf_integer_hex(uintptr_t, stopEvent, (uintptr_t)(stopEvent))
    ctf_integer(uint32_t, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  _Z24hipExtModuleLaunchKernelP18ihipModuleSymbol_tjjjjjjmP12ihipStream_tPPvS4_P11ihipEvent_tS6_j_exit,
  TP_ARGS(
    hipFunction_t, f,
    uint32_t, globalWorkSizeX,
    uint32_t, globalWorkSizeY,
    uint32_t, globalWorkSizeZ,
    uint32_t, localWorkSizeX,
    uint32_t, localWorkSizeY,
    uint32_t, localWorkSizeZ,
    size_t, sharedMemBytes,
    hipStream_t, hStream,
    void **, kernelParams,
    void **, extra,
    hipEvent_t, startEvent,
    hipEvent_t, stopEvent,
    uint32_t, flags,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphDebugDotPrint_entry,
  TP_ARGS(
    hipGraph_t, graph,
    const char *, fName,
    unsigned int, flag
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, fName, (uintptr_t)(fName))
    ctf_integer(unsigned int, flag, flag)
    ctf_string(fName_val, fName)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGraphDebugDotPrint_exit,
  TP_ARGS(
    hipGraph_t, graph,
    const char *, fName,
    unsigned int, flag,
    hipError_t, hipResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, hipResult, hipResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  __hipRegisterFatBinary_entry,
  TP_ARGS(
    const void *, data
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, data, (uintptr_t)(data))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  __hipRegisterFatBinary_exit,
  TP_ARGS(
    const void *, data,
    void **, hipResult
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hipResult, (uintptr_t)(hipResult))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  __hipRegisterFunction_entry,
  TP_ARGS(
    void **, modules,
    const void *, hostFunction,
    char *, deviceFunction,
    const char *, deviceName,
    unsigned int, threadLimit,
    uint3 *, tid,
    uint3 *, bid,
    dim3 *, blockDim,
    dim3 *, gridDim,
    int *, wSize
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, modules, (uintptr_t)(modules))
    ctf_integer_hex(uintptr_t, hostFunction, (uintptr_t)(hostFunction))
    ctf_integer_hex(uintptr_t, deviceFunction, (uintptr_t)(deviceFunction))
    ctf_integer_hex(uintptr_t, deviceName, (uintptr_t)(deviceName))
    ctf_integer(unsigned int, threadLimit, threadLimit)
    ctf_integer_hex(uintptr_t, tid, (uintptr_t)(tid))
    ctf_integer_hex(uintptr_t, bid, (uintptr_t)(bid))
    ctf_integer_hex(uintptr_t, blockDim, (uintptr_t)(blockDim))
    ctf_integer_hex(uintptr_t, gridDim, (uintptr_t)(gridDim))
    ctf_integer_hex(uintptr_t, wSize, (uintptr_t)(wSize))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  __hipRegisterFunction_exit,
  TP_ARGS(
    void **, modules,
    const void *, hostFunction,
    char *, deviceFunction,
    const char *, deviceName,
    unsigned int, threadLimit,
    uint3 *, tid,
    uint3 *, bid,
    dim3 *, blockDim,
    dim3 *, gridDim,
    int *, wSize
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  __hipRegisterManagedVar_entry,
  TP_ARGS(
    void **, modules,
    void **, pointer,
    void *, init_value,
    const char *, name,
    size_t, size,
    unsigned int, align
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, modules, (uintptr_t)(modules))
    ctf_integer_hex(uintptr_t, pointer, (uintptr_t)(pointer))
    ctf_integer_hex(uintptr_t, init_value, (uintptr_t)(init_value))
    ctf_integer_hex(uintptr_t, name, (uintptr_t)(name))
    ctf_integer(size_t, size, size)
    ctf_integer(unsigned int, align, align)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  __hipRegisterManagedVar_exit,
  TP_ARGS(
    void **, modules,
    void **, pointer,
    void *, init_value,
    const char *, name,
    size_t, size,
    unsigned int, align
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  __hipRegisterSurface_entry,
  TP_ARGS(
    void **, modules,
    void *, var,
    char *, hostVar,
    char *, deviceVar,
    int, type,
    int, ext
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, modules, (uintptr_t)(modules))
    ctf_integer_hex(uintptr_t, var, (uintptr_t)(var))
    ctf_integer_hex(uintptr_t, hostVar, (uintptr_t)(hostVar))
    ctf_integer_hex(uintptr_t, deviceVar, (uintptr_t)(deviceVar))
    ctf_integer(int, type, type)
    ctf_integer(int, ext, ext)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  __hipRegisterSurface_exit,
  TP_ARGS(
    void **, modules,
    void *, var,
    char *, hostVar,
    char *, deviceVar,
    int, type,
    int, ext
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  __hipRegisterTexture_entry,
  TP_ARGS(
    void **, modules,
    void *, var,
    char *, hostVar,
    char *, deviceVar,
    int, type,
    int, norm,
    int, ext
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, modules, (uintptr_t)(modules))
    ctf_integer_hex(uintptr_t, var, (uintptr_t)(var))
    ctf_integer_hex(uintptr_t, hostVar, (uintptr_t)(hostVar))
    ctf_integer_hex(uintptr_t, deviceVar, (uintptr_t)(deviceVar))
    ctf_integer(int, type, type)
    ctf_integer(int, norm, norm)
    ctf_integer(int, ext, ext)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  __hipRegisterTexture_exit,
  TP_ARGS(
    void **, modules,
    void *, var,
    char *, hostVar,
    char *, deviceVar,
    int, type,
    int, norm,
    int, ext
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  __hipRegisterVar_entry,
  TP_ARGS(
    void **, modules,
    void *, var,
    char *, hostVar,
    char *, deviceVar,
    int, ext,
    size_t, size,
    int, constant,
    int, global
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, modules, (uintptr_t)(modules))
    ctf_integer_hex(uintptr_t, var, (uintptr_t)(var))
    ctf_integer_hex(uintptr_t, hostVar, (uintptr_t)(hostVar))
    ctf_integer_hex(uintptr_t, deviceVar, (uintptr_t)(deviceVar))
    ctf_integer(int, ext, ext)
    ctf_integer(size_t, size, size)
    ctf_integer(int, constant, constant)
    ctf_integer(int, global, global)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  __hipRegisterVar_exit,
  TP_ARGS(
    void **, modules,
    void *, var,
    char *, hostVar,
    char *, deviceVar,
    int, ext,
    size_t, size,
    int, constant,
    int, global
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  __hipUnregisterFatBinary_entry,
  TP_ARGS(
    void **, modules
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, modules, (uintptr_t)(modules))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  __hipUnregisterFatBinary_exit,
  TP_ARGS(
    void **, modules
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGetCmdName_entry,
  TP_ARGS(
    uint32_t, id
  ),
  TP_FIELDS(
    ctf_integer(uint32_t, id, id)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipGetCmdName_exit,
  TP_ARGS(
    uint32_t, id,
    const char *, hipResult
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hipResult, (uintptr_t)(hipResult))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipRegisterTracerCallback_entry,
  TP_ARGS(
    hipRegisterTracerCallback_callback_t *, function
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, function, (uintptr_t)(function))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_hip,
  hipRegisterTracerCallback_exit,
  TP_ARGS(
    hipRegisterTracerCallback_callback_t *, function
  ),
  TP_FIELDS(
  )
)


#endif /* HIP_TRACEPOINTS_H */

#include <lttng/tracepoint-event.h>
