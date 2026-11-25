
#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER lttng_ust_cudart

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "./cudart_tracepoints.h"

#if !defined(CUDART_TRACEPOINTS_H) || defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define CUDART_TRACEPOINTS_H

#include <lttng/tracepoint.h>

#include "lttng/tracepoint_gen.h"
#include <cudart.h.include>
TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceReset_entry,
  TP_ARGS(
    void
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceReset_exit,
  TP_ARGS(
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceSynchronize_entry,
  TP_ARGS(
    void
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceSynchronize_exit,
  TP_ARGS(
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceSetLimit_entry,
  TP_ARGS(
    enum cudaLimit, limit,
    size_t, value
  ),
  TP_FIELDS(
    ctf_integer(enum cudaLimit, limit, limit)
    ctf_integer(size_t, value, value)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceSetLimit_exit,
  TP_ARGS(
    enum cudaLimit, limit,
    size_t, value,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceGetLimit_entry,
  TP_ARGS(
    size_t *, pValue,
    enum cudaLimit, limit
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pValue, (uintptr_t)(pValue))
    ctf_integer(enum cudaLimit, limit, limit)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceGetLimit_exit,
  TP_ARGS(
    size_t *, pValue,
    enum cudaLimit, limit,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceGetTexture1DLinearMaxWidth_entry,
  TP_ARGS(
    size_t *, maxWidthInElements,
    const struct cudaChannelFormatDesc *, fmtDesc,
    int, device
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, maxWidthInElements, (uintptr_t)(maxWidthInElements))
    ctf_integer_hex(uintptr_t, fmtDesc, (uintptr_t)(fmtDesc))
    ctf_integer(int, device, device)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceGetTexture1DLinearMaxWidth_exit,
  TP_ARGS(
    size_t *, maxWidthInElements,
    const struct cudaChannelFormatDesc *, fmtDesc,
    int, device,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceGetCacheConfig_entry,
  TP_ARGS(
    enum cudaFuncCache *, pCacheConfig
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pCacheConfig, (uintptr_t)(pCacheConfig))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceGetCacheConfig_exit,
  TP_ARGS(
    enum cudaFuncCache *, pCacheConfig,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceGetStreamPriorityRange_entry,
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
  lttng_ust_cudart,
  cudaDeviceGetStreamPriorityRange_exit,
  TP_ARGS(
    int *, leastPriority,
    int *, greatestPriority,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceSetCacheConfig_entry,
  TP_ARGS(
    enum cudaFuncCache, cacheConfig
  ),
  TP_FIELDS(
    ctf_integer(enum cudaFuncCache, cacheConfig, cacheConfig)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceSetCacheConfig_exit,
  TP_ARGS(
    enum cudaFuncCache, cacheConfig,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceGetByPCIBusId_entry,
  TP_ARGS(
    int *, device,
    const char *, pciBusId
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, device, (uintptr_t)(device))
    ctf_integer_hex(uintptr_t, pciBusId, (uintptr_t)(pciBusId))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceGetByPCIBusId_exit,
  TP_ARGS(
    int *, device,
    const char *, pciBusId,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceGetPCIBusId_entry,
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
  lttng_ust_cudart,
  cudaDeviceGetPCIBusId_exit,
  TP_ARGS(
    char *, pciBusId,
    int, len,
    int, device,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaIpcGetEventHandle_entry,
  TP_ARGS(
    cudaIpcEventHandle_t *, handle,
    cudaEvent_t, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, handle, (uintptr_t)(handle))
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaIpcGetEventHandle_exit,
  TP_ARGS(
    cudaIpcEventHandle_t *, handle,
    cudaEvent_t, event,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaIpcOpenEventHandle_entry,
  TP_ARGS(
    cudaEvent_t *, event,
    cudaIpcEventHandle_t, handle
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
    ctf_array_text(uint8_t, handle, &handle, sizeof(cudaIpcEventHandle_t))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaIpcOpenEventHandle_exit,
  TP_ARGS(
    cudaEvent_t *, event,
    cudaIpcEventHandle_t, handle,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaIpcGetMemHandle_entry,
  TP_ARGS(
    cudaIpcMemHandle_t *, handle,
    void *, devPtr
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, handle, (uintptr_t)(handle))
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaIpcGetMemHandle_exit,
  TP_ARGS(
    cudaIpcMemHandle_t *, handle,
    void *, devPtr,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaIpcOpenMemHandle_entry,
  TP_ARGS(
    void **, devPtr,
    cudaIpcMemHandle_t, handle,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
    ctf_array_text(uint8_t, handle, &handle, sizeof(cudaIpcMemHandle_t))
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaIpcOpenMemHandle_exit,
  TP_ARGS(
    void **, devPtr,
    cudaIpcMemHandle_t, handle,
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaIpcCloseMemHandle_entry,
  TP_ARGS(
    void *, devPtr
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaIpcCloseMemHandle_exit,
  TP_ARGS(
    void *, devPtr,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceFlushGPUDirectRDMAWrites_entry,
  TP_ARGS(
    enum cudaFlushGPUDirectRDMAWritesTarget, target,
    enum cudaFlushGPUDirectRDMAWritesScope, scope
  ),
  TP_FIELDS(
    ctf_integer(enum cudaFlushGPUDirectRDMAWritesTarget, target, target)
    ctf_integer(enum cudaFlushGPUDirectRDMAWritesScope, scope, scope)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceFlushGPUDirectRDMAWrites_exit,
  TP_ARGS(
    enum cudaFlushGPUDirectRDMAWritesTarget, target,
    enum cudaFlushGPUDirectRDMAWritesScope, scope,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceRegisterAsyncNotification_entry,
  TP_ARGS(
    int, device,
    cudaAsyncCallback, callbackFunc,
    void *, userData,
    cudaAsyncCallbackHandle_t *, callback
  ),
  TP_FIELDS(
    ctf_integer(int, device, device)
    ctf_integer_hex(uintptr_t, callbackFunc, (uintptr_t)(callbackFunc))
    ctf_integer_hex(uintptr_t, userData, (uintptr_t)(userData))
    ctf_integer_hex(uintptr_t, callback, (uintptr_t)(callback))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceRegisterAsyncNotification_exit,
  TP_ARGS(
    int, device,
    cudaAsyncCallback, callbackFunc,
    void *, userData,
    cudaAsyncCallbackHandle_t *, callback,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceUnregisterAsyncNotification_entry,
  TP_ARGS(
    int, device,
    cudaAsyncCallbackHandle_t, callback
  ),
  TP_FIELDS(
    ctf_integer(int, device, device)
    ctf_integer_hex(uintptr_t, callback, (uintptr_t)(callback))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceUnregisterAsyncNotification_exit,
  TP_ARGS(
    int, device,
    cudaAsyncCallbackHandle_t, callback,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceGetSharedMemConfig_entry,
  TP_ARGS(
    enum cudaSharedMemConfig *, pConfig
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pConfig, (uintptr_t)(pConfig))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceGetSharedMemConfig_exit,
  TP_ARGS(
    enum cudaSharedMemConfig *, pConfig,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceSetSharedMemConfig_entry,
  TP_ARGS(
    enum cudaSharedMemConfig, config
  ),
  TP_FIELDS(
    ctf_integer(enum cudaSharedMemConfig, config, config)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceSetSharedMemConfig_exit,
  TP_ARGS(
    enum cudaSharedMemConfig, config,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetLastError_entry,
  TP_ARGS(
    void
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetLastError_exit,
  TP_ARGS(
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaPeekAtLastError_entry,
  TP_ARGS(
    void
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaPeekAtLastError_exit,
  TP_ARGS(
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetErrorName_entry,
  TP_ARGS(
    cudaError_t, error
  ),
  TP_FIELDS(
    ctf_integer(int32_t, error, error)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetErrorName_exit,
  TP_ARGS(
    cudaError_t, error,
    const char *, cudaResult
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, cudaResult, (uintptr_t)(cudaResult))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetErrorString_entry,
  TP_ARGS(
    cudaError_t, error
  ),
  TP_FIELDS(
    ctf_integer(int32_t, error, error)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetErrorString_exit,
  TP_ARGS(
    cudaError_t, error,
    const char *, cudaResult
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, cudaResult, (uintptr_t)(cudaResult))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetDeviceCount_entry,
  TP_ARGS(
    int *, count
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, count, (uintptr_t)(count))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetDeviceCount_exit,
  TP_ARGS(
    int *, count,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetDeviceProperties_entry,
  TP_ARGS(
    struct cudaDeviceProp *, prop,
    int, device
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, prop, (uintptr_t)(prop))
    ctf_integer(int, device, device)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetDeviceProperties_exit,
  TP_ARGS(
    struct cudaDeviceProp *, prop,
    int, device,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceGetAttribute_entry,
  TP_ARGS(
    int *, value,
    enum cudaDeviceAttr, attr,
    int, device
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, value, (uintptr_t)(value))
    ctf_integer(enum cudaDeviceAttr, attr, attr)
    ctf_integer(int, device, device)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceGetAttribute_exit,
  TP_ARGS(
    int *, value,
    enum cudaDeviceAttr, attr,
    int, device,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceGetHostAtomicCapabilities_entry,
  TP_ARGS(
    unsigned int *, capabilities,
    const enum cudaAtomicOperation *, operations,
    unsigned int, count,
    int, device
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, capabilities, (uintptr_t)(capabilities))
    ctf_integer_hex(uintptr_t, operations, (uintptr_t)(operations))
    ctf_integer(unsigned int, count, count)
    ctf_integer(int, device, device)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceGetHostAtomicCapabilities_exit,
  TP_ARGS(
    unsigned int *, capabilities,
    const enum cudaAtomicOperation *, operations,
    unsigned int, count,
    int, device,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceGetDefaultMemPool_entry,
  TP_ARGS(
    cudaMemPool_t *, memPool,
    int, device
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, memPool, (uintptr_t)(memPool))
    ctf_integer(int, device, device)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceGetDefaultMemPool_exit,
  TP_ARGS(
    cudaMemPool_t *, memPool,
    int, device,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceSetMemPool_entry,
  TP_ARGS(
    int, device,
    cudaMemPool_t, memPool
  ),
  TP_FIELDS(
    ctf_integer(int, device, device)
    ctf_integer_hex(uintptr_t, memPool, (uintptr_t)(memPool))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceSetMemPool_exit,
  TP_ARGS(
    int, device,
    cudaMemPool_t, memPool,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceGetMemPool_entry,
  TP_ARGS(
    cudaMemPool_t *, memPool,
    int, device
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, memPool, (uintptr_t)(memPool))
    ctf_integer(int, device, device)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceGetMemPool_exit,
  TP_ARGS(
    cudaMemPool_t *, memPool,
    int, device,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceGetNvSciSyncAttributes_entry,
  TP_ARGS(
    void *, nvSciSyncAttrList,
    int, device,
    int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, nvSciSyncAttrList, (uintptr_t)(nvSciSyncAttrList))
    ctf_integer(int, device, device)
    ctf_integer(int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceGetNvSciSyncAttributes_exit,
  TP_ARGS(
    void *, nvSciSyncAttrList,
    int, device,
    int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceGetP2PAttribute_entry,
  TP_ARGS(
    int *, value,
    enum cudaDeviceP2PAttr, attr,
    int, srcDevice,
    int, dstDevice
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, value, (uintptr_t)(value))
    ctf_integer(enum cudaDeviceP2PAttr, attr, attr)
    ctf_integer(int, srcDevice, srcDevice)
    ctf_integer(int, dstDevice, dstDevice)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceGetP2PAttribute_exit,
  TP_ARGS(
    int *, value,
    enum cudaDeviceP2PAttr, attr,
    int, srcDevice,
    int, dstDevice,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceGetP2PAtomicCapabilities_entry,
  TP_ARGS(
    unsigned int *, capabilities,
    const enum cudaAtomicOperation *, operations,
    unsigned int, count,
    int, srcDevice,
    int, dstDevice
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, capabilities, (uintptr_t)(capabilities))
    ctf_integer_hex(uintptr_t, operations, (uintptr_t)(operations))
    ctf_integer(unsigned int, count, count)
    ctf_integer(int, srcDevice, srcDevice)
    ctf_integer(int, dstDevice, dstDevice)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceGetP2PAtomicCapabilities_exit,
  TP_ARGS(
    unsigned int *, capabilities,
    const enum cudaAtomicOperation *, operations,
    unsigned int, count,
    int, srcDevice,
    int, dstDevice,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaChooseDevice_entry,
  TP_ARGS(
    int *, device,
    const struct cudaDeviceProp *, prop
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, device, (uintptr_t)(device))
    ctf_integer_hex(uintptr_t, prop, (uintptr_t)(prop))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaChooseDevice_exit,
  TP_ARGS(
    int *, device,
    const struct cudaDeviceProp *, prop,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaInitDevice_entry,
  TP_ARGS(
    int, device,
    unsigned int, deviceFlags,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer(int, device, device)
    ctf_integer(unsigned int, deviceFlags, deviceFlags)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaInitDevice_exit,
  TP_ARGS(
    int, device,
    unsigned int, deviceFlags,
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaSetDevice_entry,
  TP_ARGS(
    int, device
  ),
  TP_FIELDS(
    ctf_integer(int, device, device)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaSetDevice_exit,
  TP_ARGS(
    int, device,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetDevice_entry,
  TP_ARGS(
    int *, device
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, device, (uintptr_t)(device))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetDevice_exit,
  TP_ARGS(
    int *, device,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaSetValidDevices_entry,
  TP_ARGS(
    int *, device_arr,
    int, len
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, device_arr, (uintptr_t)(device_arr))
    ctf_integer(int, len, len)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaSetValidDevices_exit,
  TP_ARGS(
    int *, device_arr,
    int, len,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaSetDeviceFlags_entry,
  TP_ARGS(
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaSetDeviceFlags_exit,
  TP_ARGS(
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetDeviceFlags_entry,
  TP_ARGS(
    unsigned int *, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, flags, (uintptr_t)(flags))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetDeviceFlags_exit,
  TP_ARGS(
    unsigned int *, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamCreate_entry,
  TP_ARGS(
    cudaStream_t *, pStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pStream, (uintptr_t)(pStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamCreate_exit,
  TP_ARGS(
    cudaStream_t *, pStream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamCreateWithFlags_entry,
  TP_ARGS(
    cudaStream_t *, pStream,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pStream, (uintptr_t)(pStream))
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamCreateWithFlags_exit,
  TP_ARGS(
    cudaStream_t *, pStream,
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamCreateWithPriority_entry,
  TP_ARGS(
    cudaStream_t *, pStream,
    unsigned int, flags,
    int, priority
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pStream, (uintptr_t)(pStream))
    ctf_integer(unsigned int, flags, flags)
    ctf_integer(int, priority, priority)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamCreateWithPriority_exit,
  TP_ARGS(
    cudaStream_t *, pStream,
    unsigned int, flags,
    int, priority,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamGetPriority_ptsz_entry,
  TP_ARGS(
    cudaStream_t, hStream,
    int *, priority
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, priority, (uintptr_t)(priority))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamGetPriority_ptsz_exit,
  TP_ARGS(
    cudaStream_t, hStream,
    int *, priority,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamGetFlags_ptsz_entry,
  TP_ARGS(
    cudaStream_t, hStream,
    unsigned int *, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, flags, (uintptr_t)(flags))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamGetFlags_ptsz_exit,
  TP_ARGS(
    cudaStream_t, hStream,
    unsigned int *, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamGetId_ptsz_entry,
  TP_ARGS(
    cudaStream_t, hStream,
    unsigned long long int *, streamId
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, streamId, (uintptr_t)(streamId))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamGetId_ptsz_exit,
  TP_ARGS(
    cudaStream_t, hStream,
    unsigned long long int *, streamId,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamGetDevice_ptsz_entry,
  TP_ARGS(
    cudaStream_t, hStream,
    int *, device
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, device, (uintptr_t)(device))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamGetDevice_ptsz_exit,
  TP_ARGS(
    cudaStream_t, hStream,
    int *, device,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaCtxResetPersistingL2Cache_entry,
  TP_ARGS(
    void
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaCtxResetPersistingL2Cache_exit,
  TP_ARGS(
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamCopyAttributes_ptsz_entry,
  TP_ARGS(
    cudaStream_t, dst,
    cudaStream_t, src
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamCopyAttributes_ptsz_exit,
  TP_ARGS(
    cudaStream_t, dst,
    cudaStream_t, src,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamGetAttribute_ptsz_entry,
  TP_ARGS(
    cudaStream_t, hStream,
    cudaLaunchAttributeID, attr,
    cudaLaunchAttributeValue *, value_out
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer(int32_t, attr, attr)
    ctf_integer_hex(uintptr_t, value_out, (uintptr_t)(value_out))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamGetAttribute_ptsz_exit,
  TP_ARGS(
    cudaStream_t, hStream,
    cudaLaunchAttributeID, attr,
    cudaLaunchAttributeValue *, value_out,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamSetAttribute_ptsz_entry,
  TP_ARGS(
    cudaStream_t, hStream,
    cudaLaunchAttributeID, attr,
    const cudaLaunchAttributeValue *, value
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer(int32_t, attr, attr)
    ctf_integer_hex(uintptr_t, value, (uintptr_t)(value))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamSetAttribute_ptsz_exit,
  TP_ARGS(
    cudaStream_t, hStream,
    cudaLaunchAttributeID, attr,
    const cudaLaunchAttributeValue *, value,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamDestroy_entry,
  TP_ARGS(
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamDestroy_exit,
  TP_ARGS(
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamWaitEvent_ptsz_entry,
  TP_ARGS(
    cudaStream_t, stream,
    cudaEvent_t, event,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamWaitEvent_ptsz_exit,
  TP_ARGS(
    cudaStream_t, stream,
    cudaEvent_t, event,
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamAddCallback_ptsz_entry,
  TP_ARGS(
    cudaStream_t, stream,
    cudaStreamCallback_t, callback,
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
  lttng_ust_cudart,
  cudaStreamAddCallback_ptsz_exit,
  TP_ARGS(
    cudaStream_t, stream,
    cudaStreamCallback_t, callback,
    void *, userData,
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamSynchronize_ptsz_entry,
  TP_ARGS(
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamSynchronize_ptsz_exit,
  TP_ARGS(
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamQuery_ptsz_entry,
  TP_ARGS(
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamQuery_ptsz_exit,
  TP_ARGS(
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamAttachMemAsync_ptsz_entry,
  TP_ARGS(
    cudaStream_t, stream,
    void *, devPtr,
    size_t, length,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
    ctf_integer(size_t, length, length)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamAttachMemAsync_ptsz_exit,
  TP_ARGS(
    cudaStream_t, stream,
    void *, devPtr,
    size_t, length,
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamBeginCapture_ptsz_entry,
  TP_ARGS(
    cudaStream_t, stream,
    enum cudaStreamCaptureMode, mode
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer(enum cudaStreamCaptureMode, mode, mode)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamBeginCapture_ptsz_exit,
  TP_ARGS(
    cudaStream_t, stream,
    enum cudaStreamCaptureMode, mode,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamBeginCaptureToGraph_ptsz_entry,
  TP_ARGS(
    cudaStream_t, stream,
    cudaGraph_t, graph,
    const cudaGraphNode_t *, dependencies,
    const cudaGraphEdgeData *, dependencyData,
    size_t, numDependencies,
    enum cudaStreamCaptureMode, mode
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, dependencies, (uintptr_t)(dependencies))
    ctf_integer_hex(uintptr_t, dependencyData, (uintptr_t)(dependencyData))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer(enum cudaStreamCaptureMode, mode, mode)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamBeginCaptureToGraph_ptsz_exit,
  TP_ARGS(
    cudaStream_t, stream,
    cudaGraph_t, graph,
    const cudaGraphNode_t *, dependencies,
    const cudaGraphEdgeData *, dependencyData,
    size_t, numDependencies,
    enum cudaStreamCaptureMode, mode,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaThreadExchangeStreamCaptureMode_entry,
  TP_ARGS(
    enum cudaStreamCaptureMode *, mode
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mode, (uintptr_t)(mode))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaThreadExchangeStreamCaptureMode_exit,
  TP_ARGS(
    enum cudaStreamCaptureMode *, mode,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamEndCapture_ptsz_entry,
  TP_ARGS(
    cudaStream_t, stream,
    cudaGraph_t *, pGraph
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, pGraph, (uintptr_t)(pGraph))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamEndCapture_ptsz_exit,
  TP_ARGS(
    cudaStream_t, stream,
    cudaGraph_t *, pGraph,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamIsCapturing_ptsz_entry,
  TP_ARGS(
    cudaStream_t, stream,
    enum cudaStreamCaptureStatus *, pCaptureStatus
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, pCaptureStatus, (uintptr_t)(pCaptureStatus))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamIsCapturing_ptsz_exit,
  TP_ARGS(
    cudaStream_t, stream,
    enum cudaStreamCaptureStatus *, pCaptureStatus,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamGetCaptureInfo_ptsz_entry,
  TP_ARGS(
    cudaStream_t, stream,
    enum cudaStreamCaptureStatus *, captureStatus_out,
    unsigned long long int *, id_out,
    cudaGraph_t *, graph_out,
    const cudaGraphNode_t **, dependencies_out,
    const cudaGraphEdgeData **, edgeData_out,
    size_t *, numDependencies_out
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, captureStatus_out, (uintptr_t)(captureStatus_out))
    ctf_integer_hex(uintptr_t, id_out, (uintptr_t)(id_out))
    ctf_integer_hex(uintptr_t, graph_out, (uintptr_t)(graph_out))
    ctf_integer_hex(uintptr_t, dependencies_out, (uintptr_t)(dependencies_out))
    ctf_integer_hex(uintptr_t, edgeData_out, (uintptr_t)(edgeData_out))
    ctf_integer_hex(uintptr_t, numDependencies_out, (uintptr_t)(numDependencies_out))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamGetCaptureInfo_ptsz_exit,
  TP_ARGS(
    cudaStream_t, stream,
    enum cudaStreamCaptureStatus *, captureStatus_out,
    unsigned long long int *, id_out,
    cudaGraph_t *, graph_out,
    const cudaGraphNode_t **, dependencies_out,
    const cudaGraphEdgeData **, edgeData_out,
    size_t *, numDependencies_out,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamUpdateCaptureDependencies_ptsz_entry,
  TP_ARGS(
    cudaStream_t, stream,
    cudaGraphNode_t *, dependencies,
    const cudaGraphEdgeData *, dependencyData,
    size_t, numDependencies,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, dependencies, (uintptr_t)(dependencies))
    ctf_integer_hex(uintptr_t, dependencyData, (uintptr_t)(dependencyData))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamUpdateCaptureDependencies_ptsz_exit,
  TP_ARGS(
    cudaStream_t, stream,
    cudaGraphNode_t *, dependencies,
    const cudaGraphEdgeData *, dependencyData,
    size_t, numDependencies,
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaEventCreate_entry,
  TP_ARGS(
    cudaEvent_t *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaEventCreate_exit,
  TP_ARGS(
    cudaEvent_t *, event,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaEventCreateWithFlags_entry,
  TP_ARGS(
    cudaEvent_t *, event,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaEventCreateWithFlags_exit,
  TP_ARGS(
    cudaEvent_t *, event,
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaEventRecord_ptsz_entry,
  TP_ARGS(
    cudaEvent_t, event,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaEventRecord_ptsz_exit,
  TP_ARGS(
    cudaEvent_t, event,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaEventRecordWithFlags_ptsz_entry,
  TP_ARGS(
    cudaEvent_t, event,
    cudaStream_t, stream,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaEventRecordWithFlags_ptsz_exit,
  TP_ARGS(
    cudaEvent_t, event,
    cudaStream_t, stream,
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaEventQuery_entry,
  TP_ARGS(
    cudaEvent_t, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaEventQuery_exit,
  TP_ARGS(
    cudaEvent_t, event,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaEventSynchronize_entry,
  TP_ARGS(
    cudaEvent_t, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaEventSynchronize_exit,
  TP_ARGS(
    cudaEvent_t, event,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaEventDestroy_entry,
  TP_ARGS(
    cudaEvent_t, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaEventDestroy_exit,
  TP_ARGS(
    cudaEvent_t, event,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaEventElapsedTime_entry,
  TP_ARGS(
    float *, ms,
    cudaEvent_t, start,
    cudaEvent_t, end
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ms, (uintptr_t)(ms))
    ctf_integer_hex(uintptr_t, start, (uintptr_t)(start))
    ctf_integer_hex(uintptr_t, end, (uintptr_t)(end))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaEventElapsedTime_exit,
  TP_ARGS(
    float *, ms,
    cudaEvent_t, start,
    cudaEvent_t, end,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaImportExternalMemory_entry,
  TP_ARGS(
    cudaExternalMemory_t *, extMem_out,
    const struct cudaExternalMemoryHandleDesc *, memHandleDesc
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, extMem_out, (uintptr_t)(extMem_out))
    ctf_integer_hex(uintptr_t, memHandleDesc, (uintptr_t)(memHandleDesc))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaImportExternalMemory_exit,
  TP_ARGS(
    cudaExternalMemory_t *, extMem_out,
    const struct cudaExternalMemoryHandleDesc *, memHandleDesc,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaExternalMemoryGetMappedBuffer_entry,
  TP_ARGS(
    void **, devPtr,
    cudaExternalMemory_t, extMem,
    const struct cudaExternalMemoryBufferDesc *, bufferDesc
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
    ctf_integer_hex(uintptr_t, extMem, (uintptr_t)(extMem))
    ctf_integer_hex(uintptr_t, bufferDesc, (uintptr_t)(bufferDesc))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaExternalMemoryGetMappedBuffer_exit,
  TP_ARGS(
    void **, devPtr,
    cudaExternalMemory_t, extMem,
    const struct cudaExternalMemoryBufferDesc *, bufferDesc,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaExternalMemoryGetMappedMipmappedArray_entry,
  TP_ARGS(
    cudaMipmappedArray_t *, mipmap,
    cudaExternalMemory_t, extMem,
    const struct cudaExternalMemoryMipmappedArrayDesc *, mipmapDesc
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mipmap, (uintptr_t)(mipmap))
    ctf_integer_hex(uintptr_t, extMem, (uintptr_t)(extMem))
    ctf_integer_hex(uintptr_t, mipmapDesc, (uintptr_t)(mipmapDesc))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaExternalMemoryGetMappedMipmappedArray_exit,
  TP_ARGS(
    cudaMipmappedArray_t *, mipmap,
    cudaExternalMemory_t, extMem,
    const struct cudaExternalMemoryMipmappedArrayDesc *, mipmapDesc,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDestroyExternalMemory_entry,
  TP_ARGS(
    cudaExternalMemory_t, extMem
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, extMem, (uintptr_t)(extMem))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDestroyExternalMemory_exit,
  TP_ARGS(
    cudaExternalMemory_t, extMem,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaImportExternalSemaphore_entry,
  TP_ARGS(
    cudaExternalSemaphore_t *, extSem_out,
    const struct cudaExternalSemaphoreHandleDesc *, semHandleDesc
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, extSem_out, (uintptr_t)(extSem_out))
    ctf_integer_hex(uintptr_t, semHandleDesc, (uintptr_t)(semHandleDesc))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaImportExternalSemaphore_exit,
  TP_ARGS(
    cudaExternalSemaphore_t *, extSem_out,
    const struct cudaExternalSemaphoreHandleDesc *, semHandleDesc,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaSignalExternalSemaphoresAsync_ptsz_entry,
  TP_ARGS(
    const cudaExternalSemaphore_t *, extSemArray,
    const struct cudaExternalSemaphoreSignalParams *, paramsArray,
    unsigned int, numExtSems,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, extSemArray, (uintptr_t)(extSemArray))
    ctf_integer_hex(uintptr_t, paramsArray, (uintptr_t)(paramsArray))
    ctf_integer(unsigned int, numExtSems, numExtSems)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaSignalExternalSemaphoresAsync_ptsz_exit,
  TP_ARGS(
    const cudaExternalSemaphore_t *, extSemArray,
    const struct cudaExternalSemaphoreSignalParams *, paramsArray,
    unsigned int, numExtSems,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaWaitExternalSemaphoresAsync_ptsz_entry,
  TP_ARGS(
    const cudaExternalSemaphore_t *, extSemArray,
    const struct cudaExternalSemaphoreWaitParams *, paramsArray,
    unsigned int, numExtSems,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, extSemArray, (uintptr_t)(extSemArray))
    ctf_integer_hex(uintptr_t, paramsArray, (uintptr_t)(paramsArray))
    ctf_integer(unsigned int, numExtSems, numExtSems)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaWaitExternalSemaphoresAsync_ptsz_exit,
  TP_ARGS(
    const cudaExternalSemaphore_t *, extSemArray,
    const struct cudaExternalSemaphoreWaitParams *, paramsArray,
    unsigned int, numExtSems,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDestroyExternalSemaphore_entry,
  TP_ARGS(
    cudaExternalSemaphore_t, extSem
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, extSem, (uintptr_t)(extSem))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDestroyExternalSemaphore_exit,
  TP_ARGS(
    cudaExternalSemaphore_t, extSem,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLaunchKernel_ptsz_entry,
  TP_ARGS(
    const void *, func,
    dim3, gridDim,
    dim3, blockDim,
    void **, args,
    size_t, sharedMem,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, func, (uintptr_t)(func))
    ctf_array_text(uint8_t, gridDim, &gridDim, sizeof(dim3))
    ctf_array_text(uint8_t, blockDim, &blockDim, sizeof(dim3))
    ctf_integer_hex(uintptr_t, args, (uintptr_t)(args))
    ctf_integer(size_t, sharedMem, sharedMem)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLaunchKernel_ptsz_exit,
  TP_ARGS(
    const void *, func,
    dim3, gridDim,
    dim3, blockDim,
    void **, args,
    size_t, sharedMem,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLaunchKernelExC_ptsz_entry,
  TP_ARGS(
    const cudaLaunchConfig_t *, config,
    const void *, func,
    void **, args
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, config, (uintptr_t)(config))
    ctf_integer_hex(uintptr_t, func, (uintptr_t)(func))
    ctf_integer_hex(uintptr_t, args, (uintptr_t)(args))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLaunchKernelExC_ptsz_exit,
  TP_ARGS(
    const cudaLaunchConfig_t *, config,
    const void *, func,
    void **, args,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLaunchCooperativeKernel_ptsz_entry,
  TP_ARGS(
    const void *, func,
    dim3, gridDim,
    dim3, blockDim,
    void **, args,
    size_t, sharedMem,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, func, (uintptr_t)(func))
    ctf_array_text(uint8_t, gridDim, &gridDim, sizeof(dim3))
    ctf_array_text(uint8_t, blockDim, &blockDim, sizeof(dim3))
    ctf_integer_hex(uintptr_t, args, (uintptr_t)(args))
    ctf_integer(size_t, sharedMem, sharedMem)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLaunchCooperativeKernel_ptsz_exit,
  TP_ARGS(
    const void *, func,
    dim3, gridDim,
    dim3, blockDim,
    void **, args,
    size_t, sharedMem,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaFuncSetCacheConfig_entry,
  TP_ARGS(
    const void *, func,
    enum cudaFuncCache, cacheConfig
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, func, (uintptr_t)(func))
    ctf_integer(enum cudaFuncCache, cacheConfig, cacheConfig)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaFuncSetCacheConfig_exit,
  TP_ARGS(
    const void *, func,
    enum cudaFuncCache, cacheConfig,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaFuncGetAttributes_entry,
  TP_ARGS(
    struct cudaFuncAttributes *, attr,
    const void *, func
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, attr, (uintptr_t)(attr))
    ctf_integer_hex(uintptr_t, func, (uintptr_t)(func))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaFuncGetAttributes_exit,
  TP_ARGS(
    struct cudaFuncAttributes *, attr,
    const void *, func,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaFuncSetAttribute_entry,
  TP_ARGS(
    const void *, func,
    enum cudaFuncAttribute, attr,
    int, value
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, func, (uintptr_t)(func))
    ctf_integer(enum cudaFuncAttribute, attr, attr)
    ctf_integer(int, value, value)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaFuncSetAttribute_exit,
  TP_ARGS(
    const void *, func,
    enum cudaFuncAttribute, attr,
    int, value,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaFuncGetName_entry,
  TP_ARGS(
    const char **, name,
    const void *, func
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, name, (uintptr_t)(name))
    ctf_integer_hex(uintptr_t, func, (uintptr_t)(func))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaFuncGetName_exit,
  TP_ARGS(
    const char **, name,
    const void *, func,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaFuncGetParamInfo_entry,
  TP_ARGS(
    const void *, func,
    size_t, paramIndex,
    size_t *, paramOffset,
    size_t *, paramSize
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, func, (uintptr_t)(func))
    ctf_integer(size_t, paramIndex, paramIndex)
    ctf_integer_hex(uintptr_t, paramOffset, (uintptr_t)(paramOffset))
    ctf_integer_hex(uintptr_t, paramSize, (uintptr_t)(paramSize))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaFuncGetParamInfo_exit,
  TP_ARGS(
    const void *, func,
    size_t, paramIndex,
    size_t *, paramOffset,
    size_t *, paramSize,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLaunchHostFunc_ptsz_entry,
  TP_ARGS(
    cudaStream_t, stream,
    cudaHostFn_t, fn,
    void *, userData
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, fn, (uintptr_t)(fn))
    ctf_integer_hex(uintptr_t, userData, (uintptr_t)(userData))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLaunchHostFunc_ptsz_exit,
  TP_ARGS(
    cudaStream_t, stream,
    cudaHostFn_t, fn,
    void *, userData,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaFuncSetSharedMemConfig_entry,
  TP_ARGS(
    const void *, func,
    enum cudaSharedMemConfig, config
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, func, (uintptr_t)(func))
    ctf_integer(enum cudaSharedMemConfig, config, config)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaFuncSetSharedMemConfig_exit,
  TP_ARGS(
    const void *, func,
    enum cudaSharedMemConfig, config,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaOccupancyMaxActiveBlocksPerMultiprocessor_entry,
  TP_ARGS(
    int *, numBlocks,
    const void *, func,
    int, blockSize,
    size_t, dynamicSMemSize
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, numBlocks, (uintptr_t)(numBlocks))
    ctf_integer_hex(uintptr_t, func, (uintptr_t)(func))
    ctf_integer(int, blockSize, blockSize)
    ctf_integer(size_t, dynamicSMemSize, dynamicSMemSize)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaOccupancyMaxActiveBlocksPerMultiprocessor_exit,
  TP_ARGS(
    int *, numBlocks,
    const void *, func,
    int, blockSize,
    size_t, dynamicSMemSize,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaOccupancyAvailableDynamicSMemPerBlock_entry,
  TP_ARGS(
    size_t *, dynamicSmemSize,
    const void *, func,
    int, numBlocks,
    int, blockSize
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dynamicSmemSize, (uintptr_t)(dynamicSmemSize))
    ctf_integer_hex(uintptr_t, func, (uintptr_t)(func))
    ctf_integer(int, numBlocks, numBlocks)
    ctf_integer(int, blockSize, blockSize)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaOccupancyAvailableDynamicSMemPerBlock_exit,
  TP_ARGS(
    size_t *, dynamicSmemSize,
    const void *, func,
    int, numBlocks,
    int, blockSize,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_entry,
  TP_ARGS(
    int *, numBlocks,
    const void *, func,
    int, blockSize,
    size_t, dynamicSMemSize,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, numBlocks, (uintptr_t)(numBlocks))
    ctf_integer_hex(uintptr_t, func, (uintptr_t)(func))
    ctf_integer(int, blockSize, blockSize)
    ctf_integer(size_t, dynamicSMemSize, dynamicSMemSize)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_exit,
  TP_ARGS(
    int *, numBlocks,
    const void *, func,
    int, blockSize,
    size_t, dynamicSMemSize,
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaOccupancyMaxPotentialClusterSize_entry,
  TP_ARGS(
    int *, clusterSize,
    const void *, func,
    const cudaLaunchConfig_t *, launchConfig
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, clusterSize, (uintptr_t)(clusterSize))
    ctf_integer_hex(uintptr_t, func, (uintptr_t)(func))
    ctf_integer_hex(uintptr_t, launchConfig, (uintptr_t)(launchConfig))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaOccupancyMaxPotentialClusterSize_exit,
  TP_ARGS(
    int *, clusterSize,
    const void *, func,
    const cudaLaunchConfig_t *, launchConfig,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaOccupancyMaxActiveClusters_entry,
  TP_ARGS(
    int *, numClusters,
    const void *, func,
    const cudaLaunchConfig_t *, launchConfig
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, numClusters, (uintptr_t)(numClusters))
    ctf_integer_hex(uintptr_t, func, (uintptr_t)(func))
    ctf_integer_hex(uintptr_t, launchConfig, (uintptr_t)(launchConfig))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaOccupancyMaxActiveClusters_exit,
  TP_ARGS(
    int *, numClusters,
    const void *, func,
    const cudaLaunchConfig_t *, launchConfig,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMallocManaged_entry,
  TP_ARGS(
    void **, devPtr,
    size_t, size,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
    ctf_integer(size_t, size, size)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMallocManaged_exit,
  TP_ARGS(
    void **, devPtr,
    size_t, size,
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMalloc_entry,
  TP_ARGS(
    void **, devPtr,
    size_t, size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
    ctf_integer(size_t, size, size)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMalloc_exit,
  TP_ARGS(
    void **, devPtr,
    size_t, size,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMallocHost_entry,
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
  lttng_ust_cudart,
  cudaMallocHost_exit,
  TP_ARGS(
    void **, ptr,
    size_t, size,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMallocPitch_entry,
  TP_ARGS(
    void **, devPtr,
    size_t *, pitch,
    size_t, width,
    size_t, height
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
    ctf_integer_hex(uintptr_t, pitch, (uintptr_t)(pitch))
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMallocPitch_exit,
  TP_ARGS(
    void **, devPtr,
    size_t *, pitch,
    size_t, width,
    size_t, height,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMallocArray_entry,
  TP_ARGS(
    cudaArray_t *, array,
    const struct cudaChannelFormatDesc *, desc,
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
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMallocArray_exit,
  TP_ARGS(
    cudaArray_t *, array,
    const struct cudaChannelFormatDesc *, desc,
    size_t, width,
    size_t, height,
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaFree_entry,
  TP_ARGS(
    void *, devPtr
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaFree_exit,
  TP_ARGS(
    void *, devPtr,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaFreeHost_entry,
  TP_ARGS(
    void *, ptr
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)(ptr))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaFreeHost_exit,
  TP_ARGS(
    void *, ptr,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaFreeArray_entry,
  TP_ARGS(
    cudaArray_t, array
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, array, (uintptr_t)(array))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaFreeArray_exit,
  TP_ARGS(
    cudaArray_t, array,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaFreeMipmappedArray_entry,
  TP_ARGS(
    cudaMipmappedArray_t, mipmappedArray
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mipmappedArray, (uintptr_t)(mipmappedArray))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaFreeMipmappedArray_exit,
  TP_ARGS(
    cudaMipmappedArray_t, mipmappedArray,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaHostAlloc_entry,
  TP_ARGS(
    void **, pHost,
    size_t, size,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pHost, (uintptr_t)(pHost))
    ctf_integer(size_t, size, size)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaHostAlloc_exit,
  TP_ARGS(
    void **, pHost,
    size_t, size,
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaHostRegister_entry,
  TP_ARGS(
    void *, ptr,
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
  lttng_ust_cudart,
  cudaHostRegister_exit,
  TP_ARGS(
    void *, ptr,
    size_t, size,
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaHostUnregister_entry,
  TP_ARGS(
    void *, ptr
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)(ptr))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaHostUnregister_exit,
  TP_ARGS(
    void *, ptr,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaHostGetDevicePointer_entry,
  TP_ARGS(
    void **, pDevice,
    void *, pHost,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pDevice, (uintptr_t)(pDevice))
    ctf_integer_hex(uintptr_t, pHost, (uintptr_t)(pHost))
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaHostGetDevicePointer_exit,
  TP_ARGS(
    void **, pDevice,
    void *, pHost,
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaHostGetFlags_entry,
  TP_ARGS(
    unsigned int *, pFlags,
    void *, pHost
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pFlags, (uintptr_t)(pFlags))
    ctf_integer_hex(uintptr_t, pHost, (uintptr_t)(pHost))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaHostGetFlags_exit,
  TP_ARGS(
    unsigned int *, pFlags,
    void *, pHost,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMalloc3D_entry,
  TP_ARGS(
    struct cudaPitchedPtr *, pitchedDevPtr,
    struct cudaExtent, extent
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pitchedDevPtr, (uintptr_t)(pitchedDevPtr))
    ctf_array_text(uint8_t, extent, &extent, sizeof(struct cudaExtent))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMalloc3D_exit,
  TP_ARGS(
    struct cudaPitchedPtr *, pitchedDevPtr,
    struct cudaExtent, extent,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMalloc3DArray_entry,
  TP_ARGS(
    cudaArray_t *, array,
    const struct cudaChannelFormatDesc *, desc,
    struct cudaExtent, extent,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, array, (uintptr_t)(array))
    ctf_integer_hex(uintptr_t, desc, (uintptr_t)(desc))
    ctf_array_text(uint8_t, extent, &extent, sizeof(struct cudaExtent))
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMalloc3DArray_exit,
  TP_ARGS(
    cudaArray_t *, array,
    const struct cudaChannelFormatDesc *, desc,
    struct cudaExtent, extent,
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMallocMipmappedArray_entry,
  TP_ARGS(
    cudaMipmappedArray_t *, mipmappedArray,
    const struct cudaChannelFormatDesc *, desc,
    struct cudaExtent, extent,
    unsigned int, numLevels,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mipmappedArray, (uintptr_t)(mipmappedArray))
    ctf_integer_hex(uintptr_t, desc, (uintptr_t)(desc))
    ctf_array_text(uint8_t, extent, &extent, sizeof(struct cudaExtent))
    ctf_integer(unsigned int, numLevels, numLevels)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMallocMipmappedArray_exit,
  TP_ARGS(
    cudaMipmappedArray_t *, mipmappedArray,
    const struct cudaChannelFormatDesc *, desc,
    struct cudaExtent, extent,
    unsigned int, numLevels,
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetMipmappedArrayLevel_entry,
  TP_ARGS(
    cudaArray_t *, levelArray,
    cudaMipmappedArray_const_t, mipmappedArray,
    unsigned int, level
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, levelArray, (uintptr_t)(levelArray))
    ctf_integer_hex(uintptr_t, mipmappedArray, (uintptr_t)(mipmappedArray))
    ctf_integer(unsigned int, level, level)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetMipmappedArrayLevel_exit,
  TP_ARGS(
    cudaArray_t *, levelArray,
    cudaMipmappedArray_const_t, mipmappedArray,
    unsigned int, level,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy3D_ptds_entry,
  TP_ARGS(
    const struct cudaMemcpy3DParms *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy3D_ptds_exit,
  TP_ARGS(
    const struct cudaMemcpy3DParms *, p,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy3DPeer_ptds_entry,
  TP_ARGS(
    const struct cudaMemcpy3DPeerParms *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy3DPeer_ptds_exit,
  TP_ARGS(
    const struct cudaMemcpy3DPeerParms *, p,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy3DAsync_ptsz_entry,
  TP_ARGS(
    const struct cudaMemcpy3DParms *, p,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy3DAsync_ptsz_exit,
  TP_ARGS(
    const struct cudaMemcpy3DParms *, p,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy3DPeerAsync_ptsz_entry,
  TP_ARGS(
    const struct cudaMemcpy3DPeerParms *, p,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy3DPeerAsync_ptsz_exit,
  TP_ARGS(
    const struct cudaMemcpy3DPeerParms *, p,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemGetInfo_entry,
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
  lttng_ust_cudart,
  cudaMemGetInfo_exit,
  TP_ARGS(
    size_t *, free,
    size_t *, total,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaArrayGetInfo_entry,
  TP_ARGS(
    struct cudaChannelFormatDesc *, desc,
    struct cudaExtent *, extent,
    unsigned int *, flags,
    cudaArray_t, array
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, desc, (uintptr_t)(desc))
    ctf_integer_hex(uintptr_t, extent, (uintptr_t)(extent))
    ctf_integer_hex(uintptr_t, flags, (uintptr_t)(flags))
    ctf_integer_hex(uintptr_t, array, (uintptr_t)(array))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaArrayGetInfo_exit,
  TP_ARGS(
    struct cudaChannelFormatDesc *, desc,
    struct cudaExtent *, extent,
    unsigned int *, flags,
    cudaArray_t, array,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaArrayGetPlane_entry,
  TP_ARGS(
    cudaArray_t *, pPlaneArray,
    cudaArray_t, hArray,
    unsigned int, planeIdx
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pPlaneArray, (uintptr_t)(pPlaneArray))
    ctf_integer_hex(uintptr_t, hArray, (uintptr_t)(hArray))
    ctf_integer(unsigned int, planeIdx, planeIdx)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaArrayGetPlane_exit,
  TP_ARGS(
    cudaArray_t *, pPlaneArray,
    cudaArray_t, hArray,
    unsigned int, planeIdx,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaArrayGetMemoryRequirements_entry,
  TP_ARGS(
    struct cudaArrayMemoryRequirements *, memoryRequirements,
    cudaArray_t, array,
    int, device
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, memoryRequirements, (uintptr_t)(memoryRequirements))
    ctf_integer_hex(uintptr_t, array, (uintptr_t)(array))
    ctf_integer(int, device, device)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaArrayGetMemoryRequirements_exit,
  TP_ARGS(
    struct cudaArrayMemoryRequirements *, memoryRequirements,
    cudaArray_t, array,
    int, device,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMipmappedArrayGetMemoryRequirements_entry,
  TP_ARGS(
    struct cudaArrayMemoryRequirements *, memoryRequirements,
    cudaMipmappedArray_t, mipmap,
    int, device
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, memoryRequirements, (uintptr_t)(memoryRequirements))
    ctf_integer_hex(uintptr_t, mipmap, (uintptr_t)(mipmap))
    ctf_integer(int, device, device)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMipmappedArrayGetMemoryRequirements_exit,
  TP_ARGS(
    struct cudaArrayMemoryRequirements *, memoryRequirements,
    cudaMipmappedArray_t, mipmap,
    int, device,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaArrayGetSparseProperties_entry,
  TP_ARGS(
    struct cudaArraySparseProperties *, sparseProperties,
    cudaArray_t, array
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, sparseProperties, (uintptr_t)(sparseProperties))
    ctf_integer_hex(uintptr_t, array, (uintptr_t)(array))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaArrayGetSparseProperties_exit,
  TP_ARGS(
    struct cudaArraySparseProperties *, sparseProperties,
    cudaArray_t, array,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMipmappedArrayGetSparseProperties_entry,
  TP_ARGS(
    struct cudaArraySparseProperties *, sparseProperties,
    cudaMipmappedArray_t, mipmap
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, sparseProperties, (uintptr_t)(sparseProperties))
    ctf_integer_hex(uintptr_t, mipmap, (uintptr_t)(mipmap))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMipmappedArrayGetSparseProperties_exit,
  TP_ARGS(
    struct cudaArraySparseProperties *, sparseProperties,
    cudaMipmappedArray_t, mipmap,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy_ptds_entry,
  TP_ARGS(
    void *, dst,
    const void *, src,
    size_t, count,
    enum cudaMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, count, count)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy_ptds_exit,
  TP_ARGS(
    void *, dst,
    const void *, src,
    size_t, count,
    enum cudaMemcpyKind, kind,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyPeer_entry,
  TP_ARGS(
    void *, dst,
    int, dstDevice,
    const void *, src,
    int, srcDevice,
    size_t, count
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(int, dstDevice, dstDevice)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(int, srcDevice, srcDevice)
    ctf_integer(size_t, count, count)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyPeer_exit,
  TP_ARGS(
    void *, dst,
    int, dstDevice,
    const void *, src,
    int, srcDevice,
    size_t, count,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy2D_ptds_entry,
  TP_ARGS(
    void *, dst,
    size_t, dpitch,
    const void *, src,
    size_t, spitch,
    size_t, width,
    size_t, height,
    enum cudaMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, dpitch, dpitch)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, spitch, spitch)
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy2D_ptds_exit,
  TP_ARGS(
    void *, dst,
    size_t, dpitch,
    const void *, src,
    size_t, spitch,
    size_t, width,
    size_t, height,
    enum cudaMemcpyKind, kind,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy2DToArray_ptds_entry,
  TP_ARGS(
    cudaArray_t, dst,
    size_t, wOffset,
    size_t, hOffset,
    const void *, src,
    size_t, spitch,
    size_t, width,
    size_t, height,
    enum cudaMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, wOffset, wOffset)
    ctf_integer(size_t, hOffset, hOffset)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, spitch, spitch)
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy2DToArray_ptds_exit,
  TP_ARGS(
    cudaArray_t, dst,
    size_t, wOffset,
    size_t, hOffset,
    const void *, src,
    size_t, spitch,
    size_t, width,
    size_t, height,
    enum cudaMemcpyKind, kind,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy2DFromArray_ptds_entry,
  TP_ARGS(
    void *, dst,
    size_t, dpitch,
    cudaArray_const_t, src,
    size_t, wOffset,
    size_t, hOffset,
    size_t, width,
    size_t, height,
    enum cudaMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, dpitch, dpitch)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, wOffset, wOffset)
    ctf_integer(size_t, hOffset, hOffset)
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy2DFromArray_ptds_exit,
  TP_ARGS(
    void *, dst,
    size_t, dpitch,
    cudaArray_const_t, src,
    size_t, wOffset,
    size_t, hOffset,
    size_t, width,
    size_t, height,
    enum cudaMemcpyKind, kind,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy2DArrayToArray_ptds_entry,
  TP_ARGS(
    cudaArray_t, dst,
    size_t, wOffsetDst,
    size_t, hOffsetDst,
    cudaArray_const_t, src,
    size_t, wOffsetSrc,
    size_t, hOffsetSrc,
    size_t, width,
    size_t, height,
    enum cudaMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, wOffsetDst, wOffsetDst)
    ctf_integer(size_t, hOffsetDst, hOffsetDst)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, wOffsetSrc, wOffsetSrc)
    ctf_integer(size_t, hOffsetSrc, hOffsetSrc)
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy2DArrayToArray_ptds_exit,
  TP_ARGS(
    cudaArray_t, dst,
    size_t, wOffsetDst,
    size_t, hOffsetDst,
    cudaArray_const_t, src,
    size_t, wOffsetSrc,
    size_t, hOffsetSrc,
    size_t, width,
    size_t, height,
    enum cudaMemcpyKind, kind,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyToSymbol_ptds_entry,
  TP_ARGS(
    const void *, symbol,
    const void *, src,
    size_t, count,
    size_t, offset,
    enum cudaMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, count, count)
    ctf_integer(size_t, offset, offset)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyToSymbol_ptds_exit,
  TP_ARGS(
    const void *, symbol,
    const void *, src,
    size_t, count,
    size_t, offset,
    enum cudaMemcpyKind, kind,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyFromSymbol_ptds_entry,
  TP_ARGS(
    void *, dst,
    const void *, symbol,
    size_t, count,
    size_t, offset,
    enum cudaMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
    ctf_integer(size_t, count, count)
    ctf_integer(size_t, offset, offset)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyFromSymbol_ptds_exit,
  TP_ARGS(
    void *, dst,
    const void *, symbol,
    size_t, count,
    size_t, offset,
    enum cudaMemcpyKind, kind,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyAsync_ptsz_entry,
  TP_ARGS(
    void *, dst,
    const void *, src,
    size_t, count,
    enum cudaMemcpyKind, kind,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, count, count)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyAsync_ptsz_exit,
  TP_ARGS(
    void *, dst,
    const void *, src,
    size_t, count,
    enum cudaMemcpyKind, kind,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyPeerAsync_entry,
  TP_ARGS(
    void *, dst,
    int, dstDevice,
    const void *, src,
    int, srcDevice,
    size_t, count,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(int, dstDevice, dstDevice)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(int, srcDevice, srcDevice)
    ctf_integer(size_t, count, count)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyPeerAsync_exit,
  TP_ARGS(
    void *, dst,
    int, dstDevice,
    const void *, src,
    int, srcDevice,
    size_t, count,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyBatchAsync_ptsz_entry,
  TP_ARGS(
    void *const *, dsts,
    const void *const *, srcs,
    const size_t *, sizes,
    size_t, count,
    struct cudaMemcpyAttributes *, attrs,
    size_t *, attrsIdxs,
    size_t, numAttrs,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dsts, (uintptr_t)(dsts))
    ctf_integer_hex(uintptr_t, srcs, (uintptr_t)(srcs))
    ctf_integer_hex(uintptr_t, sizes, (uintptr_t)(sizes))
    ctf_integer(size_t, count, count)
    ctf_integer_hex(uintptr_t, attrs, (uintptr_t)(attrs))
    ctf_integer_hex(uintptr_t, attrsIdxs, (uintptr_t)(attrsIdxs))
    ctf_integer(size_t, numAttrs, numAttrs)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyBatchAsync_ptsz_exit,
  TP_ARGS(
    void *const *, dsts,
    const void *const *, srcs,
    const size_t *, sizes,
    size_t, count,
    struct cudaMemcpyAttributes *, attrs,
    size_t *, attrsIdxs,
    size_t, numAttrs,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy3DBatchAsync_ptsz_entry,
  TP_ARGS(
    size_t, numOps,
    struct cudaMemcpy3DBatchOp *, opList,
    unsigned long long int, flags,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer(size_t, numOps, numOps)
    ctf_integer_hex(uintptr_t, opList, (uintptr_t)(opList))
    ctf_integer(unsigned long long int, flags, flags)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy3DBatchAsync_ptsz_exit,
  TP_ARGS(
    size_t, numOps,
    struct cudaMemcpy3DBatchOp *, opList,
    unsigned long long int, flags,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy2DAsync_ptsz_entry,
  TP_ARGS(
    void *, dst,
    size_t, dpitch,
    const void *, src,
    size_t, spitch,
    size_t, width,
    size_t, height,
    enum cudaMemcpyKind, kind,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, dpitch, dpitch)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, spitch, spitch)
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy2DAsync_ptsz_exit,
  TP_ARGS(
    void *, dst,
    size_t, dpitch,
    const void *, src,
    size_t, spitch,
    size_t, width,
    size_t, height,
    enum cudaMemcpyKind, kind,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy2DToArrayAsync_ptsz_entry,
  TP_ARGS(
    cudaArray_t, dst,
    size_t, wOffset,
    size_t, hOffset,
    const void *, src,
    size_t, spitch,
    size_t, width,
    size_t, height,
    enum cudaMemcpyKind, kind,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, wOffset, wOffset)
    ctf_integer(size_t, hOffset, hOffset)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, spitch, spitch)
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy2DToArrayAsync_ptsz_exit,
  TP_ARGS(
    cudaArray_t, dst,
    size_t, wOffset,
    size_t, hOffset,
    const void *, src,
    size_t, spitch,
    size_t, width,
    size_t, height,
    enum cudaMemcpyKind, kind,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy2DFromArrayAsync_ptsz_entry,
  TP_ARGS(
    void *, dst,
    size_t, dpitch,
    cudaArray_const_t, src,
    size_t, wOffset,
    size_t, hOffset,
    size_t, width,
    size_t, height,
    enum cudaMemcpyKind, kind,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, dpitch, dpitch)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, wOffset, wOffset)
    ctf_integer(size_t, hOffset, hOffset)
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy2DFromArrayAsync_ptsz_exit,
  TP_ARGS(
    void *, dst,
    size_t, dpitch,
    cudaArray_const_t, src,
    size_t, wOffset,
    size_t, hOffset,
    size_t, width,
    size_t, height,
    enum cudaMemcpyKind, kind,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyToSymbolAsync_ptsz_entry,
  TP_ARGS(
    const void *, symbol,
    const void *, src,
    size_t, count,
    size_t, offset,
    enum cudaMemcpyKind, kind,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, count, count)
    ctf_integer(size_t, offset, offset)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyToSymbolAsync_ptsz_exit,
  TP_ARGS(
    const void *, symbol,
    const void *, src,
    size_t, count,
    size_t, offset,
    enum cudaMemcpyKind, kind,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyFromSymbolAsync_ptsz_entry,
  TP_ARGS(
    void *, dst,
    const void *, symbol,
    size_t, count,
    size_t, offset,
    enum cudaMemcpyKind, kind,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
    ctf_integer(size_t, count, count)
    ctf_integer(size_t, offset, offset)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyFromSymbolAsync_ptsz_exit,
  TP_ARGS(
    void *, dst,
    const void *, symbol,
    size_t, count,
    size_t, offset,
    enum cudaMemcpyKind, kind,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemset_ptds_entry,
  TP_ARGS(
    void *, devPtr,
    int, value,
    size_t, count
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
    ctf_integer(int, value, value)
    ctf_integer(size_t, count, count)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemset_ptds_exit,
  TP_ARGS(
    void *, devPtr,
    int, value,
    size_t, count,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemset2D_ptds_entry,
  TP_ARGS(
    void *, devPtr,
    size_t, pitch,
    int, value,
    size_t, width,
    size_t, height
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
    ctf_integer(size_t, pitch, pitch)
    ctf_integer(int, value, value)
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemset2D_ptds_exit,
  TP_ARGS(
    void *, devPtr,
    size_t, pitch,
    int, value,
    size_t, width,
    size_t, height,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemset3D_ptds_entry,
  TP_ARGS(
    struct cudaPitchedPtr, pitchedDevPtr,
    int, value,
    struct cudaExtent, extent
  ),
  TP_FIELDS(
    ctf_array_text(uint8_t, pitchedDevPtr, &pitchedDevPtr, sizeof(struct cudaPitchedPtr))
    ctf_integer(int, value, value)
    ctf_array_text(uint8_t, extent, &extent, sizeof(struct cudaExtent))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemset3D_ptds_exit,
  TP_ARGS(
    struct cudaPitchedPtr, pitchedDevPtr,
    int, value,
    struct cudaExtent, extent,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemsetAsync_ptsz_entry,
  TP_ARGS(
    void *, devPtr,
    int, value,
    size_t, count,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
    ctf_integer(int, value, value)
    ctf_integer(size_t, count, count)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemsetAsync_ptsz_exit,
  TP_ARGS(
    void *, devPtr,
    int, value,
    size_t, count,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemset2DAsync_ptsz_entry,
  TP_ARGS(
    void *, devPtr,
    size_t, pitch,
    int, value,
    size_t, width,
    size_t, height,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
    ctf_integer(size_t, pitch, pitch)
    ctf_integer(int, value, value)
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemset2DAsync_ptsz_exit,
  TP_ARGS(
    void *, devPtr,
    size_t, pitch,
    int, value,
    size_t, width,
    size_t, height,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemset3DAsync_ptsz_entry,
  TP_ARGS(
    struct cudaPitchedPtr, pitchedDevPtr,
    int, value,
    struct cudaExtent, extent,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_array_text(uint8_t, pitchedDevPtr, &pitchedDevPtr, sizeof(struct cudaPitchedPtr))
    ctf_integer(int, value, value)
    ctf_array_text(uint8_t, extent, &extent, sizeof(struct cudaExtent))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemset3DAsync_ptsz_exit,
  TP_ARGS(
    struct cudaPitchedPtr, pitchedDevPtr,
    int, value,
    struct cudaExtent, extent,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetSymbolAddress_entry,
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
  lttng_ust_cudart,
  cudaGetSymbolAddress_exit,
  TP_ARGS(
    void **, devPtr,
    const void *, symbol,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetSymbolSize_entry,
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
  lttng_ust_cudart,
  cudaGetSymbolSize_exit,
  TP_ARGS(
    size_t *, size,
    const void *, symbol,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemPrefetchAsync_ptsz_entry,
  TP_ARGS(
    const void *, devPtr,
    size_t, count,
    struct cudaMemLocation, location,
    unsigned int, flags,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
    ctf_integer(size_t, count, count)
    ctf_array_text(uint8_t, location, &location, sizeof(struct cudaMemLocation))
    ctf_integer(unsigned int, flags, flags)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemPrefetchAsync_ptsz_exit,
  TP_ARGS(
    const void *, devPtr,
    size_t, count,
    struct cudaMemLocation, location,
    unsigned int, flags,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemPrefetchBatchAsync_ptsz_entry,
  TP_ARGS(
    void **, dptrs,
    size_t *, sizes,
    size_t, count,
    struct cudaMemLocation *, prefetchLocs,
    size_t *, prefetchLocIdxs,
    size_t, numPrefetchLocs,
    unsigned long long int, flags,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dptrs, (uintptr_t)(dptrs))
    ctf_integer_hex(uintptr_t, sizes, (uintptr_t)(sizes))
    ctf_integer(size_t, count, count)
    ctf_integer_hex(uintptr_t, prefetchLocs, (uintptr_t)(prefetchLocs))
    ctf_integer_hex(uintptr_t, prefetchLocIdxs, (uintptr_t)(prefetchLocIdxs))
    ctf_integer(size_t, numPrefetchLocs, numPrefetchLocs)
    ctf_integer(unsigned long long int, flags, flags)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemPrefetchBatchAsync_ptsz_exit,
  TP_ARGS(
    void **, dptrs,
    size_t *, sizes,
    size_t, count,
    struct cudaMemLocation *, prefetchLocs,
    size_t *, prefetchLocIdxs,
    size_t, numPrefetchLocs,
    unsigned long long int, flags,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemDiscardBatchAsync_ptsz_entry,
  TP_ARGS(
    void **, dptrs,
    size_t *, sizes,
    size_t, count,
    unsigned long long int, flags,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dptrs, (uintptr_t)(dptrs))
    ctf_integer_hex(uintptr_t, sizes, (uintptr_t)(sizes))
    ctf_integer(size_t, count, count)
    ctf_integer(unsigned long long int, flags, flags)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemDiscardBatchAsync_ptsz_exit,
  TP_ARGS(
    void **, dptrs,
    size_t *, sizes,
    size_t, count,
    unsigned long long int, flags,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemDiscardAndPrefetchBatchAsync_ptsz_entry,
  TP_ARGS(
    void **, dptrs,
    size_t *, sizes,
    size_t, count,
    struct cudaMemLocation *, prefetchLocs,
    size_t *, prefetchLocIdxs,
    size_t, numPrefetchLocs,
    unsigned long long int, flags,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dptrs, (uintptr_t)(dptrs))
    ctf_integer_hex(uintptr_t, sizes, (uintptr_t)(sizes))
    ctf_integer(size_t, count, count)
    ctf_integer_hex(uintptr_t, prefetchLocs, (uintptr_t)(prefetchLocs))
    ctf_integer_hex(uintptr_t, prefetchLocIdxs, (uintptr_t)(prefetchLocIdxs))
    ctf_integer(size_t, numPrefetchLocs, numPrefetchLocs)
    ctf_integer(unsigned long long int, flags, flags)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemDiscardAndPrefetchBatchAsync_ptsz_exit,
  TP_ARGS(
    void **, dptrs,
    size_t *, sizes,
    size_t, count,
    struct cudaMemLocation *, prefetchLocs,
    size_t *, prefetchLocIdxs,
    size_t, numPrefetchLocs,
    unsigned long long int, flags,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemAdvise_entry,
  TP_ARGS(
    const void *, devPtr,
    size_t, count,
    enum cudaMemoryAdvise, advice,
    struct cudaMemLocation, location
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
    ctf_integer(size_t, count, count)
    ctf_integer(enum cudaMemoryAdvise, advice, advice)
    ctf_array_text(uint8_t, location, &location, sizeof(struct cudaMemLocation))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemAdvise_exit,
  TP_ARGS(
    const void *, devPtr,
    size_t, count,
    enum cudaMemoryAdvise, advice,
    struct cudaMemLocation, location,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemRangeGetAttribute_entry,
  TP_ARGS(
    void *, data,
    size_t, dataSize,
    enum cudaMemRangeAttribute, attribute,
    const void *, devPtr,
    size_t, count
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, data, (uintptr_t)(data))
    ctf_integer(size_t, dataSize, dataSize)
    ctf_integer(enum cudaMemRangeAttribute, attribute, attribute)
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
    ctf_integer(size_t, count, count)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemRangeGetAttribute_exit,
  TP_ARGS(
    void *, data,
    size_t, dataSize,
    enum cudaMemRangeAttribute, attribute,
    const void *, devPtr,
    size_t, count,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemRangeGetAttributes_entry,
  TP_ARGS(
    void **, data,
    size_t *, dataSizes,
    enum cudaMemRangeAttribute *, attributes,
    size_t, numAttributes,
    const void *, devPtr,
    size_t, count
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, data, (uintptr_t)(data))
    ctf_integer_hex(uintptr_t, dataSizes, (uintptr_t)(dataSizes))
    ctf_integer_hex(uintptr_t, attributes, (uintptr_t)(attributes))
    ctf_integer(size_t, numAttributes, numAttributes)
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
    ctf_integer(size_t, count, count)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemRangeGetAttributes_exit,
  TP_ARGS(
    void **, data,
    size_t *, dataSizes,
    enum cudaMemRangeAttribute *, attributes,
    size_t, numAttributes,
    const void *, devPtr,
    size_t, count,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyToArray_ptds_entry,
  TP_ARGS(
    cudaArray_t, dst,
    size_t, wOffset,
    size_t, hOffset,
    const void *, src,
    size_t, count,
    enum cudaMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, wOffset, wOffset)
    ctf_integer(size_t, hOffset, hOffset)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, count, count)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyToArray_ptds_exit,
  TP_ARGS(
    cudaArray_t, dst,
    size_t, wOffset,
    size_t, hOffset,
    const void *, src,
    size_t, count,
    enum cudaMemcpyKind, kind,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyFromArray_ptds_entry,
  TP_ARGS(
    void *, dst,
    cudaArray_const_t, src,
    size_t, wOffset,
    size_t, hOffset,
    size_t, count,
    enum cudaMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, wOffset, wOffset)
    ctf_integer(size_t, hOffset, hOffset)
    ctf_integer(size_t, count, count)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyFromArray_ptds_exit,
  TP_ARGS(
    void *, dst,
    cudaArray_const_t, src,
    size_t, wOffset,
    size_t, hOffset,
    size_t, count,
    enum cudaMemcpyKind, kind,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyArrayToArray_ptds_entry,
  TP_ARGS(
    cudaArray_t, dst,
    size_t, wOffsetDst,
    size_t, hOffsetDst,
    cudaArray_const_t, src,
    size_t, wOffsetSrc,
    size_t, hOffsetSrc,
    size_t, count,
    enum cudaMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, wOffsetDst, wOffsetDst)
    ctf_integer(size_t, hOffsetDst, hOffsetDst)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, wOffsetSrc, wOffsetSrc)
    ctf_integer(size_t, hOffsetSrc, hOffsetSrc)
    ctf_integer(size_t, count, count)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyArrayToArray_ptds_exit,
  TP_ARGS(
    cudaArray_t, dst,
    size_t, wOffsetDst,
    size_t, hOffsetDst,
    cudaArray_const_t, src,
    size_t, wOffsetSrc,
    size_t, hOffsetSrc,
    size_t, count,
    enum cudaMemcpyKind, kind,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyToArrayAsync_ptsz_entry,
  TP_ARGS(
    cudaArray_t, dst,
    size_t, wOffset,
    size_t, hOffset,
    const void *, src,
    size_t, count,
    enum cudaMemcpyKind, kind,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, wOffset, wOffset)
    ctf_integer(size_t, hOffset, hOffset)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, count, count)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyToArrayAsync_ptsz_exit,
  TP_ARGS(
    cudaArray_t, dst,
    size_t, wOffset,
    size_t, hOffset,
    const void *, src,
    size_t, count,
    enum cudaMemcpyKind, kind,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyFromArrayAsync_ptsz_entry,
  TP_ARGS(
    void *, dst,
    cudaArray_const_t, src,
    size_t, wOffset,
    size_t, hOffset,
    size_t, count,
    enum cudaMemcpyKind, kind,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, wOffset, wOffset)
    ctf_integer(size_t, hOffset, hOffset)
    ctf_integer(size_t, count, count)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyFromArrayAsync_ptsz_exit,
  TP_ARGS(
    void *, dst,
    cudaArray_const_t, src,
    size_t, wOffset,
    size_t, hOffset,
    size_t, count,
    enum cudaMemcpyKind, kind,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMallocAsync_ptsz_entry,
  TP_ARGS(
    void **, devPtr,
    size_t, size,
    cudaStream_t, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
    ctf_integer(size_t, size, size)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMallocAsync_ptsz_exit,
  TP_ARGS(
    void **, devPtr,
    size_t, size,
    cudaStream_t, hStream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaFreeAsync_ptsz_entry,
  TP_ARGS(
    void *, devPtr,
    cudaStream_t, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaFreeAsync_ptsz_exit,
  TP_ARGS(
    void *, devPtr,
    cudaStream_t, hStream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemPoolTrimTo_entry,
  TP_ARGS(
    cudaMemPool_t, memPool,
    size_t, minBytesToKeep
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, memPool, (uintptr_t)(memPool))
    ctf_integer(size_t, minBytesToKeep, minBytesToKeep)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemPoolTrimTo_exit,
  TP_ARGS(
    cudaMemPool_t, memPool,
    size_t, minBytesToKeep,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemPoolSetAttribute_entry,
  TP_ARGS(
    cudaMemPool_t, memPool,
    enum cudaMemPoolAttr, attr,
    void *, value
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, memPool, (uintptr_t)(memPool))
    ctf_integer(enum cudaMemPoolAttr, attr, attr)
    ctf_integer_hex(uintptr_t, value, (uintptr_t)(value))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemPoolSetAttribute_exit,
  TP_ARGS(
    cudaMemPool_t, memPool,
    enum cudaMemPoolAttr, attr,
    void *, value,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemPoolGetAttribute_entry,
  TP_ARGS(
    cudaMemPool_t, memPool,
    enum cudaMemPoolAttr, attr,
    void *, value
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, memPool, (uintptr_t)(memPool))
    ctf_integer(enum cudaMemPoolAttr, attr, attr)
    ctf_integer_hex(uintptr_t, value, (uintptr_t)(value))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemPoolGetAttribute_exit,
  TP_ARGS(
    cudaMemPool_t, memPool,
    enum cudaMemPoolAttr, attr,
    void *, value,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemPoolSetAccess_entry,
  TP_ARGS(
    cudaMemPool_t, memPool,
    const struct cudaMemAccessDesc *, descList,
    size_t, count
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, memPool, (uintptr_t)(memPool))
    ctf_integer_hex(uintptr_t, descList, (uintptr_t)(descList))
    ctf_integer(size_t, count, count)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemPoolSetAccess_exit,
  TP_ARGS(
    cudaMemPool_t, memPool,
    const struct cudaMemAccessDesc *, descList,
    size_t, count,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemPoolGetAccess_entry,
  TP_ARGS(
    enum cudaMemAccessFlags *, flags,
    cudaMemPool_t, memPool,
    struct cudaMemLocation *, location
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, flags, (uintptr_t)(flags))
    ctf_integer_hex(uintptr_t, memPool, (uintptr_t)(memPool))
    ctf_integer_hex(uintptr_t, location, (uintptr_t)(location))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemPoolGetAccess_exit,
  TP_ARGS(
    enum cudaMemAccessFlags *, flags,
    cudaMemPool_t, memPool,
    struct cudaMemLocation *, location,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemPoolCreate_entry,
  TP_ARGS(
    cudaMemPool_t *, memPool,
    const struct cudaMemPoolProps *, poolProps
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, memPool, (uintptr_t)(memPool))
    ctf_integer_hex(uintptr_t, poolProps, (uintptr_t)(poolProps))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemPoolCreate_exit,
  TP_ARGS(
    cudaMemPool_t *, memPool,
    const struct cudaMemPoolProps *, poolProps,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemPoolDestroy_entry,
  TP_ARGS(
    cudaMemPool_t, memPool
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, memPool, (uintptr_t)(memPool))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemPoolDestroy_exit,
  TP_ARGS(
    cudaMemPool_t, memPool,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemGetDefaultMemPool_entry,
  TP_ARGS(
    cudaMemPool_t *, memPool,
    struct cudaMemLocation *, location,
    enum cudaMemAllocationType, type
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, memPool, (uintptr_t)(memPool))
    ctf_integer_hex(uintptr_t, location, (uintptr_t)(location))
    ctf_integer(enum cudaMemAllocationType, type, type)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemGetDefaultMemPool_exit,
  TP_ARGS(
    cudaMemPool_t *, memPool,
    struct cudaMemLocation *, location,
    enum cudaMemAllocationType, type,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemGetMemPool_entry,
  TP_ARGS(
    cudaMemPool_t *, memPool,
    struct cudaMemLocation *, location,
    enum cudaMemAllocationType, type
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, memPool, (uintptr_t)(memPool))
    ctf_integer_hex(uintptr_t, location, (uintptr_t)(location))
    ctf_integer(enum cudaMemAllocationType, type, type)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemGetMemPool_exit,
  TP_ARGS(
    cudaMemPool_t *, memPool,
    struct cudaMemLocation *, location,
    enum cudaMemAllocationType, type,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemSetMemPool_entry,
  TP_ARGS(
    struct cudaMemLocation *, location,
    enum cudaMemAllocationType, type,
    cudaMemPool_t, memPool
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, location, (uintptr_t)(location))
    ctf_integer(enum cudaMemAllocationType, type, type)
    ctf_integer_hex(uintptr_t, memPool, (uintptr_t)(memPool))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemSetMemPool_exit,
  TP_ARGS(
    struct cudaMemLocation *, location,
    enum cudaMemAllocationType, type,
    cudaMemPool_t, memPool,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMallocFromPoolAsync_ptsz_entry,
  TP_ARGS(
    void **, ptr,
    size_t, size,
    cudaMemPool_t, memPool,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)(ptr))
    ctf_integer(size_t, size, size)
    ctf_integer_hex(uintptr_t, memPool, (uintptr_t)(memPool))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMallocFromPoolAsync_ptsz_exit,
  TP_ARGS(
    void **, ptr,
    size_t, size,
    cudaMemPool_t, memPool,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemPoolExportToShareableHandle_entry,
  TP_ARGS(
    void *, shareableHandle,
    cudaMemPool_t, memPool,
    enum cudaMemAllocationHandleType, handleType,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, shareableHandle, (uintptr_t)(shareableHandle))
    ctf_integer_hex(uintptr_t, memPool, (uintptr_t)(memPool))
    ctf_integer(enum cudaMemAllocationHandleType, handleType, handleType)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemPoolExportToShareableHandle_exit,
  TP_ARGS(
    void *, shareableHandle,
    cudaMemPool_t, memPool,
    enum cudaMemAllocationHandleType, handleType,
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemPoolImportFromShareableHandle_entry,
  TP_ARGS(
    cudaMemPool_t *, memPool,
    void *, shareableHandle,
    enum cudaMemAllocationHandleType, handleType,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, memPool, (uintptr_t)(memPool))
    ctf_integer_hex(uintptr_t, shareableHandle, (uintptr_t)(shareableHandle))
    ctf_integer(enum cudaMemAllocationHandleType, handleType, handleType)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemPoolImportFromShareableHandle_exit,
  TP_ARGS(
    cudaMemPool_t *, memPool,
    void *, shareableHandle,
    enum cudaMemAllocationHandleType, handleType,
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemPoolExportPointer_entry,
  TP_ARGS(
    struct cudaMemPoolPtrExportData *, exportData,
    void *, ptr
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, exportData, (uintptr_t)(exportData))
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)(ptr))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemPoolExportPointer_exit,
  TP_ARGS(
    struct cudaMemPoolPtrExportData *, exportData,
    void *, ptr,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemPoolImportPointer_entry,
  TP_ARGS(
    void **, ptr,
    cudaMemPool_t, memPool,
    struct cudaMemPoolPtrExportData *, exportData
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)(ptr))
    ctf_integer_hex(uintptr_t, memPool, (uintptr_t)(memPool))
    ctf_integer_hex(uintptr_t, exportData, (uintptr_t)(exportData))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemPoolImportPointer_exit,
  TP_ARGS(
    void **, ptr,
    cudaMemPool_t, memPool,
    struct cudaMemPoolPtrExportData *, exportData,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaPointerGetAttributes_entry,
  TP_ARGS(
    struct cudaPointerAttributes *, attributes,
    const void *, ptr
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, attributes, (uintptr_t)(attributes))
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)(ptr))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaPointerGetAttributes_exit,
  TP_ARGS(
    struct cudaPointerAttributes *, attributes,
    const void *, ptr,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceCanAccessPeer_entry,
  TP_ARGS(
    int *, canAccessPeer,
    int, device,
    int, peerDevice
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, canAccessPeer, (uintptr_t)(canAccessPeer))
    ctf_integer(int, device, device)
    ctf_integer(int, peerDevice, peerDevice)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceCanAccessPeer_exit,
  TP_ARGS(
    int *, canAccessPeer,
    int, device,
    int, peerDevice,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceEnablePeerAccess_entry,
  TP_ARGS(
    int, peerDevice,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer(int, peerDevice, peerDevice)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceEnablePeerAccess_exit,
  TP_ARGS(
    int, peerDevice,
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceDisablePeerAccess_entry,
  TP_ARGS(
    int, peerDevice
  ),
  TP_FIELDS(
    ctf_integer(int, peerDevice, peerDevice)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceDisablePeerAccess_exit,
  TP_ARGS(
    int, peerDevice,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphicsUnregisterResource_entry,
  TP_ARGS(
    cudaGraphicsResource_t, resource
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, resource, (uintptr_t)(resource))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphicsUnregisterResource_exit,
  TP_ARGS(
    cudaGraphicsResource_t, resource,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphicsResourceSetMapFlags_entry,
  TP_ARGS(
    cudaGraphicsResource_t, resource,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, resource, (uintptr_t)(resource))
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphicsResourceSetMapFlags_exit,
  TP_ARGS(
    cudaGraphicsResource_t, resource,
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphicsMapResources_entry,
  TP_ARGS(
    int, count,
    cudaGraphicsResource_t *, resources,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer(int, count, count)
    ctf_integer_hex(uintptr_t, resources, (uintptr_t)(resources))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphicsMapResources_exit,
  TP_ARGS(
    int, count,
    cudaGraphicsResource_t *, resources,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphicsUnmapResources_entry,
  TP_ARGS(
    int, count,
    cudaGraphicsResource_t *, resources,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer(int, count, count)
    ctf_integer_hex(uintptr_t, resources, (uintptr_t)(resources))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphicsUnmapResources_exit,
  TP_ARGS(
    int, count,
    cudaGraphicsResource_t *, resources,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphicsResourceGetMappedPointer_entry,
  TP_ARGS(
    void **, devPtr,
    size_t *, size,
    cudaGraphicsResource_t, resource
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
    ctf_integer_hex(uintptr_t, size, (uintptr_t)(size))
    ctf_integer_hex(uintptr_t, resource, (uintptr_t)(resource))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphicsResourceGetMappedPointer_exit,
  TP_ARGS(
    void **, devPtr,
    size_t *, size,
    cudaGraphicsResource_t, resource,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphicsSubResourceGetMappedArray_entry,
  TP_ARGS(
    cudaArray_t *, array,
    cudaGraphicsResource_t, resource,
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
  lttng_ust_cudart,
  cudaGraphicsSubResourceGetMappedArray_exit,
  TP_ARGS(
    cudaArray_t *, array,
    cudaGraphicsResource_t, resource,
    unsigned int, arrayIndex,
    unsigned int, mipLevel,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphicsResourceGetMappedMipmappedArray_entry,
  TP_ARGS(
    cudaMipmappedArray_t *, mipmappedArray,
    cudaGraphicsResource_t, resource
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mipmappedArray, (uintptr_t)(mipmappedArray))
    ctf_integer_hex(uintptr_t, resource, (uintptr_t)(resource))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphicsResourceGetMappedMipmappedArray_exit,
  TP_ARGS(
    cudaMipmappedArray_t *, mipmappedArray,
    cudaGraphicsResource_t, resource,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetChannelDesc_entry,
  TP_ARGS(
    struct cudaChannelFormatDesc *, desc,
    cudaArray_const_t, array
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, desc, (uintptr_t)(desc))
    ctf_integer_hex(uintptr_t, array, (uintptr_t)(array))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetChannelDesc_exit,
  TP_ARGS(
    struct cudaChannelFormatDesc *, desc,
    cudaArray_const_t, array,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaCreateChannelDesc_entry,
  TP_ARGS(
    int, x,
    int, y,
    int, z,
    int, w,
    enum cudaChannelFormatKind, f
  ),
  TP_FIELDS(
    ctf_integer(int, x, x)
    ctf_integer(int, y, y)
    ctf_integer(int, z, z)
    ctf_integer(int, w, w)
    ctf_integer(enum cudaChannelFormatKind, f, f)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaCreateChannelDesc_exit,
  TP_ARGS(
    int, x,
    int, y,
    int, z,
    int, w,
    enum cudaChannelFormatKind, f,
    struct cudaChannelFormatDesc, cudaResult
  ),
  TP_FIELDS(
    ctf_array_text(uint8_t, cudaResult, &cudaResult, sizeof(struct cudaChannelFormatDesc))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaCreateTextureObject_entry,
  TP_ARGS(
    cudaTextureObject_t *, pTexObject,
    const struct cudaResourceDesc *, pResDesc,
    const struct cudaTextureDesc *, pTexDesc,
    const struct cudaResourceViewDesc *, pResViewDesc
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pTexObject, (uintptr_t)(pTexObject))
    ctf_integer_hex(uintptr_t, pResDesc, (uintptr_t)(pResDesc))
    ctf_integer_hex(uintptr_t, pTexDesc, (uintptr_t)(pTexDesc))
    ctf_integer_hex(uintptr_t, pResViewDesc, (uintptr_t)(pResViewDesc))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaCreateTextureObject_exit,
  TP_ARGS(
    cudaTextureObject_t *, pTexObject,
    const struct cudaResourceDesc *, pResDesc,
    const struct cudaTextureDesc *, pTexDesc,
    const struct cudaResourceViewDesc *, pResViewDesc,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDestroyTextureObject_entry,
  TP_ARGS(
    cudaTextureObject_t, texObject
  ),
  TP_FIELDS(
    ctf_integer(cudaTextureObject_t, texObject, texObject)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDestroyTextureObject_exit,
  TP_ARGS(
    cudaTextureObject_t, texObject,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetTextureObjectResourceDesc_entry,
  TP_ARGS(
    struct cudaResourceDesc *, pResDesc,
    cudaTextureObject_t, texObject
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pResDesc, (uintptr_t)(pResDesc))
    ctf_integer(cudaTextureObject_t, texObject, texObject)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetTextureObjectResourceDesc_exit,
  TP_ARGS(
    struct cudaResourceDesc *, pResDesc,
    cudaTextureObject_t, texObject,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetTextureObjectTextureDesc_entry,
  TP_ARGS(
    struct cudaTextureDesc *, pTexDesc,
    cudaTextureObject_t, texObject
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pTexDesc, (uintptr_t)(pTexDesc))
    ctf_integer(cudaTextureObject_t, texObject, texObject)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetTextureObjectTextureDesc_exit,
  TP_ARGS(
    struct cudaTextureDesc *, pTexDesc,
    cudaTextureObject_t, texObject,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetTextureObjectResourceViewDesc_entry,
  TP_ARGS(
    struct cudaResourceViewDesc *, pResViewDesc,
    cudaTextureObject_t, texObject
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pResViewDesc, (uintptr_t)(pResViewDesc))
    ctf_integer(cudaTextureObject_t, texObject, texObject)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetTextureObjectResourceViewDesc_exit,
  TP_ARGS(
    struct cudaResourceViewDesc *, pResViewDesc,
    cudaTextureObject_t, texObject,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaCreateSurfaceObject_entry,
  TP_ARGS(
    cudaSurfaceObject_t *, pSurfObject,
    const struct cudaResourceDesc *, pResDesc
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pSurfObject, (uintptr_t)(pSurfObject))
    ctf_integer_hex(uintptr_t, pResDesc, (uintptr_t)(pResDesc))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaCreateSurfaceObject_exit,
  TP_ARGS(
    cudaSurfaceObject_t *, pSurfObject,
    const struct cudaResourceDesc *, pResDesc,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDestroySurfaceObject_entry,
  TP_ARGS(
    cudaSurfaceObject_t, surfObject
  ),
  TP_FIELDS(
    ctf_integer(cudaSurfaceObject_t, surfObject, surfObject)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDestroySurfaceObject_exit,
  TP_ARGS(
    cudaSurfaceObject_t, surfObject,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetSurfaceObjectResourceDesc_entry,
  TP_ARGS(
    struct cudaResourceDesc *, pResDesc,
    cudaSurfaceObject_t, surfObject
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pResDesc, (uintptr_t)(pResDesc))
    ctf_integer(cudaSurfaceObject_t, surfObject, surfObject)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetSurfaceObjectResourceDesc_exit,
  TP_ARGS(
    struct cudaResourceDesc *, pResDesc,
    cudaSurfaceObject_t, surfObject,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDriverGetVersion_entry,
  TP_ARGS(
    int *, driverVersion
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, driverVersion, (uintptr_t)(driverVersion))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDriverGetVersion_exit,
  TP_ARGS(
    int *, driverVersion,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaRuntimeGetVersion_entry,
  TP_ARGS(
    int *, runtimeVersion
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, runtimeVersion, (uintptr_t)(runtimeVersion))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaRuntimeGetVersion_exit,
  TP_ARGS(
    int *, runtimeVersion,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLogsRegisterCallback_entry,
  TP_ARGS(
    cudaLogsCallback_t, callbackFunc,
    void *, userData,
    cudaLogsCallbackHandle *, callback_out
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, callbackFunc, (uintptr_t)(callbackFunc))
    ctf_integer_hex(uintptr_t, userData, (uintptr_t)(userData))
    ctf_integer_hex(uintptr_t, callback_out, (uintptr_t)(callback_out))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLogsRegisterCallback_exit,
  TP_ARGS(
    cudaLogsCallback_t, callbackFunc,
    void *, userData,
    cudaLogsCallbackHandle *, callback_out,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLogsUnregisterCallback_entry,
  TP_ARGS(
    cudaLogsCallbackHandle, callback
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, callback, (uintptr_t)(callback))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLogsUnregisterCallback_exit,
  TP_ARGS(
    cudaLogsCallbackHandle, callback,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLogsCurrent_entry,
  TP_ARGS(
    cudaLogIterator *, iterator_out,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, iterator_out, (uintptr_t)(iterator_out))
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLogsCurrent_exit,
  TP_ARGS(
    cudaLogIterator *, iterator_out,
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLogsDumpToFile_entry,
  TP_ARGS(
    cudaLogIterator *, iterator,
    const char *, pathToFile,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, iterator, (uintptr_t)(iterator))
    ctf_integer_hex(uintptr_t, pathToFile, (uintptr_t)(pathToFile))
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLogsDumpToFile_exit,
  TP_ARGS(
    cudaLogIterator *, iterator,
    const char *, pathToFile,
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLogsDumpToMemory_entry,
  TP_ARGS(
    cudaLogIterator *, iterator,
    char *, buffer,
    size_t *, size,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, iterator, (uintptr_t)(iterator))
    ctf_integer_hex(uintptr_t, buffer, (uintptr_t)(buffer))
    ctf_integer_hex(uintptr_t, size, (uintptr_t)(size))
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLogsDumpToMemory_exit,
  TP_ARGS(
    cudaLogIterator *, iterator,
    char *, buffer,
    size_t *, size,
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphCreate_entry,
  TP_ARGS(
    cudaGraph_t *, pGraph,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pGraph, (uintptr_t)(pGraph))
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphCreate_exit,
  TP_ARGS(
    cudaGraph_t *, pGraph,
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphAddKernelNode_entry,
  TP_ARGS(
    cudaGraphNode_t *, pGraphNode,
    cudaGraph_t, graph,
    const cudaGraphNode_t *, pDependencies,
    size_t, numDependencies,
    const struct cudaKernelNodeParams *, pNodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pGraphNode, (uintptr_t)(pGraphNode))
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, pDependencies, (uintptr_t)(pDependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, pNodeParams, (uintptr_t)(pNodeParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphAddKernelNode_exit,
  TP_ARGS(
    cudaGraphNode_t *, pGraphNode,
    cudaGraph_t, graph,
    const cudaGraphNode_t *, pDependencies,
    size_t, numDependencies,
    const struct cudaKernelNodeParams *, pNodeParams,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphKernelNodeGetParams_entry,
  TP_ARGS(
    cudaGraphNode_t, node,
    struct cudaKernelNodeParams *, pNodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, pNodeParams, (uintptr_t)(pNodeParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphKernelNodeGetParams_exit,
  TP_ARGS(
    cudaGraphNode_t, node,
    struct cudaKernelNodeParams *, pNodeParams,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphKernelNodeSetParams_entry,
  TP_ARGS(
    cudaGraphNode_t, node,
    const struct cudaKernelNodeParams *, pNodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, pNodeParams, (uintptr_t)(pNodeParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphKernelNodeSetParams_exit,
  TP_ARGS(
    cudaGraphNode_t, node,
    const struct cudaKernelNodeParams *, pNodeParams,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphKernelNodeCopyAttributes_entry,
  TP_ARGS(
    cudaGraphNode_t, hDst,
    cudaGraphNode_t, hSrc
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDst, (uintptr_t)(hDst))
    ctf_integer_hex(uintptr_t, hSrc, (uintptr_t)(hSrc))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphKernelNodeCopyAttributes_exit,
  TP_ARGS(
    cudaGraphNode_t, hDst,
    cudaGraphNode_t, hSrc,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphKernelNodeGetAttribute_entry,
  TP_ARGS(
    cudaGraphNode_t, hNode,
    cudaLaunchAttributeID, attr,
    cudaLaunchAttributeValue *, value_out
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer(int32_t, attr, attr)
    ctf_integer_hex(uintptr_t, value_out, (uintptr_t)(value_out))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphKernelNodeGetAttribute_exit,
  TP_ARGS(
    cudaGraphNode_t, hNode,
    cudaLaunchAttributeID, attr,
    cudaLaunchAttributeValue *, value_out,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphKernelNodeSetAttribute_entry,
  TP_ARGS(
    cudaGraphNode_t, hNode,
    cudaLaunchAttributeID, attr,
    const cudaLaunchAttributeValue *, value
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer(int32_t, attr, attr)
    ctf_integer_hex(uintptr_t, value, (uintptr_t)(value))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphKernelNodeSetAttribute_exit,
  TP_ARGS(
    cudaGraphNode_t, hNode,
    cudaLaunchAttributeID, attr,
    const cudaLaunchAttributeValue *, value,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphAddMemcpyNode_entry,
  TP_ARGS(
    cudaGraphNode_t *, pGraphNode,
    cudaGraph_t, graph,
    const cudaGraphNode_t *, pDependencies,
    size_t, numDependencies,
    const struct cudaMemcpy3DParms *, pCopyParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pGraphNode, (uintptr_t)(pGraphNode))
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, pDependencies, (uintptr_t)(pDependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, pCopyParams, (uintptr_t)(pCopyParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphAddMemcpyNode_exit,
  TP_ARGS(
    cudaGraphNode_t *, pGraphNode,
    cudaGraph_t, graph,
    const cudaGraphNode_t *, pDependencies,
    size_t, numDependencies,
    const struct cudaMemcpy3DParms *, pCopyParams,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphAddMemcpyNodeToSymbol_entry,
  TP_ARGS(
    cudaGraphNode_t *, pGraphNode,
    cudaGraph_t, graph,
    const cudaGraphNode_t *, pDependencies,
    size_t, numDependencies,
    const void *, symbol,
    const void *, src,
    size_t, count,
    size_t, offset,
    enum cudaMemcpyKind, kind
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
    ctf_integer(enum cudaMemcpyKind, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphAddMemcpyNodeToSymbol_exit,
  TP_ARGS(
    cudaGraphNode_t *, pGraphNode,
    cudaGraph_t, graph,
    const cudaGraphNode_t *, pDependencies,
    size_t, numDependencies,
    const void *, symbol,
    const void *, src,
    size_t, count,
    size_t, offset,
    enum cudaMemcpyKind, kind,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphAddMemcpyNodeFromSymbol_entry,
  TP_ARGS(
    cudaGraphNode_t *, pGraphNode,
    cudaGraph_t, graph,
    const cudaGraphNode_t *, pDependencies,
    size_t, numDependencies,
    void *, dst,
    const void *, symbol,
    size_t, count,
    size_t, offset,
    enum cudaMemcpyKind, kind
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
    ctf_integer(enum cudaMemcpyKind, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphAddMemcpyNodeFromSymbol_exit,
  TP_ARGS(
    cudaGraphNode_t *, pGraphNode,
    cudaGraph_t, graph,
    const cudaGraphNode_t *, pDependencies,
    size_t, numDependencies,
    void *, dst,
    const void *, symbol,
    size_t, count,
    size_t, offset,
    enum cudaMemcpyKind, kind,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphAddMemcpyNode1D_entry,
  TP_ARGS(
    cudaGraphNode_t *, pGraphNode,
    cudaGraph_t, graph,
    const cudaGraphNode_t *, pDependencies,
    size_t, numDependencies,
    void *, dst,
    const void *, src,
    size_t, count,
    enum cudaMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pGraphNode, (uintptr_t)(pGraphNode))
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, pDependencies, (uintptr_t)(pDependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, count, count)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphAddMemcpyNode1D_exit,
  TP_ARGS(
    cudaGraphNode_t *, pGraphNode,
    cudaGraph_t, graph,
    const cudaGraphNode_t *, pDependencies,
    size_t, numDependencies,
    void *, dst,
    const void *, src,
    size_t, count,
    enum cudaMemcpyKind, kind,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphMemcpyNodeGetParams_entry,
  TP_ARGS(
    cudaGraphNode_t, node,
    struct cudaMemcpy3DParms *, pNodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, pNodeParams, (uintptr_t)(pNodeParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphMemcpyNodeGetParams_exit,
  TP_ARGS(
    cudaGraphNode_t, node,
    struct cudaMemcpy3DParms *, pNodeParams,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphMemcpyNodeSetParams_entry,
  TP_ARGS(
    cudaGraphNode_t, node,
    const struct cudaMemcpy3DParms *, pNodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, pNodeParams, (uintptr_t)(pNodeParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphMemcpyNodeSetParams_exit,
  TP_ARGS(
    cudaGraphNode_t, node,
    const struct cudaMemcpy3DParms *, pNodeParams,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphMemcpyNodeSetParamsToSymbol_entry,
  TP_ARGS(
    cudaGraphNode_t, node,
    const void *, symbol,
    const void *, src,
    size_t, count,
    size_t, offset,
    enum cudaMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, count, count)
    ctf_integer(size_t, offset, offset)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphMemcpyNodeSetParamsToSymbol_exit,
  TP_ARGS(
    cudaGraphNode_t, node,
    const void *, symbol,
    const void *, src,
    size_t, count,
    size_t, offset,
    enum cudaMemcpyKind, kind,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphMemcpyNodeSetParamsFromSymbol_entry,
  TP_ARGS(
    cudaGraphNode_t, node,
    void *, dst,
    const void *, symbol,
    size_t, count,
    size_t, offset,
    enum cudaMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
    ctf_integer(size_t, count, count)
    ctf_integer(size_t, offset, offset)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphMemcpyNodeSetParamsFromSymbol_exit,
  TP_ARGS(
    cudaGraphNode_t, node,
    void *, dst,
    const void *, symbol,
    size_t, count,
    size_t, offset,
    enum cudaMemcpyKind, kind,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphMemcpyNodeSetParams1D_entry,
  TP_ARGS(
    cudaGraphNode_t, node,
    void *, dst,
    const void *, src,
    size_t, count,
    enum cudaMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, count, count)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphMemcpyNodeSetParams1D_exit,
  TP_ARGS(
    cudaGraphNode_t, node,
    void *, dst,
    const void *, src,
    size_t, count,
    enum cudaMemcpyKind, kind,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphAddMemsetNode_entry,
  TP_ARGS(
    cudaGraphNode_t *, pGraphNode,
    cudaGraph_t, graph,
    const cudaGraphNode_t *, pDependencies,
    size_t, numDependencies,
    const struct cudaMemsetParams *, pMemsetParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pGraphNode, (uintptr_t)(pGraphNode))
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, pDependencies, (uintptr_t)(pDependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, pMemsetParams, (uintptr_t)(pMemsetParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphAddMemsetNode_exit,
  TP_ARGS(
    cudaGraphNode_t *, pGraphNode,
    cudaGraph_t, graph,
    const cudaGraphNode_t *, pDependencies,
    size_t, numDependencies,
    const struct cudaMemsetParams *, pMemsetParams,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphMemsetNodeGetParams_entry,
  TP_ARGS(
    cudaGraphNode_t, node,
    struct cudaMemsetParams *, pNodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, pNodeParams, (uintptr_t)(pNodeParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphMemsetNodeGetParams_exit,
  TP_ARGS(
    cudaGraphNode_t, node,
    struct cudaMemsetParams *, pNodeParams,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphMemsetNodeSetParams_entry,
  TP_ARGS(
    cudaGraphNode_t, node,
    const struct cudaMemsetParams *, pNodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, pNodeParams, (uintptr_t)(pNodeParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphMemsetNodeSetParams_exit,
  TP_ARGS(
    cudaGraphNode_t, node,
    const struct cudaMemsetParams *, pNodeParams,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphAddHostNode_entry,
  TP_ARGS(
    cudaGraphNode_t *, pGraphNode,
    cudaGraph_t, graph,
    const cudaGraphNode_t *, pDependencies,
    size_t, numDependencies,
    const struct cudaHostNodeParams *, pNodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pGraphNode, (uintptr_t)(pGraphNode))
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, pDependencies, (uintptr_t)(pDependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, pNodeParams, (uintptr_t)(pNodeParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphAddHostNode_exit,
  TP_ARGS(
    cudaGraphNode_t *, pGraphNode,
    cudaGraph_t, graph,
    const cudaGraphNode_t *, pDependencies,
    size_t, numDependencies,
    const struct cudaHostNodeParams *, pNodeParams,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphHostNodeGetParams_entry,
  TP_ARGS(
    cudaGraphNode_t, node,
    struct cudaHostNodeParams *, pNodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, pNodeParams, (uintptr_t)(pNodeParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphHostNodeGetParams_exit,
  TP_ARGS(
    cudaGraphNode_t, node,
    struct cudaHostNodeParams *, pNodeParams,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphHostNodeSetParams_entry,
  TP_ARGS(
    cudaGraphNode_t, node,
    const struct cudaHostNodeParams *, pNodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, pNodeParams, (uintptr_t)(pNodeParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphHostNodeSetParams_exit,
  TP_ARGS(
    cudaGraphNode_t, node,
    const struct cudaHostNodeParams *, pNodeParams,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphAddChildGraphNode_entry,
  TP_ARGS(
    cudaGraphNode_t *, pGraphNode,
    cudaGraph_t, graph,
    const cudaGraphNode_t *, pDependencies,
    size_t, numDependencies,
    cudaGraph_t, childGraph
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pGraphNode, (uintptr_t)(pGraphNode))
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, pDependencies, (uintptr_t)(pDependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, childGraph, (uintptr_t)(childGraph))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphAddChildGraphNode_exit,
  TP_ARGS(
    cudaGraphNode_t *, pGraphNode,
    cudaGraph_t, graph,
    const cudaGraphNode_t *, pDependencies,
    size_t, numDependencies,
    cudaGraph_t, childGraph,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphChildGraphNodeGetGraph_entry,
  TP_ARGS(
    cudaGraphNode_t, node,
    cudaGraph_t *, pGraph
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, pGraph, (uintptr_t)(pGraph))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphChildGraphNodeGetGraph_exit,
  TP_ARGS(
    cudaGraphNode_t, node,
    cudaGraph_t *, pGraph,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphAddEmptyNode_entry,
  TP_ARGS(
    cudaGraphNode_t *, pGraphNode,
    cudaGraph_t, graph,
    const cudaGraphNode_t *, pDependencies,
    size_t, numDependencies
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pGraphNode, (uintptr_t)(pGraphNode))
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, pDependencies, (uintptr_t)(pDependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphAddEmptyNode_exit,
  TP_ARGS(
    cudaGraphNode_t *, pGraphNode,
    cudaGraph_t, graph,
    const cudaGraphNode_t *, pDependencies,
    size_t, numDependencies,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphAddEventRecordNode_entry,
  TP_ARGS(
    cudaGraphNode_t *, pGraphNode,
    cudaGraph_t, graph,
    const cudaGraphNode_t *, pDependencies,
    size_t, numDependencies,
    cudaEvent_t, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pGraphNode, (uintptr_t)(pGraphNode))
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, pDependencies, (uintptr_t)(pDependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphAddEventRecordNode_exit,
  TP_ARGS(
    cudaGraphNode_t *, pGraphNode,
    cudaGraph_t, graph,
    const cudaGraphNode_t *, pDependencies,
    size_t, numDependencies,
    cudaEvent_t, event,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphEventRecordNodeGetEvent_entry,
  TP_ARGS(
    cudaGraphNode_t, node,
    cudaEvent_t *, event_out
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, event_out, (uintptr_t)(event_out))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphEventRecordNodeGetEvent_exit,
  TP_ARGS(
    cudaGraphNode_t, node,
    cudaEvent_t *, event_out,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphEventRecordNodeSetEvent_entry,
  TP_ARGS(
    cudaGraphNode_t, node,
    cudaEvent_t, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphEventRecordNodeSetEvent_exit,
  TP_ARGS(
    cudaGraphNode_t, node,
    cudaEvent_t, event,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphAddEventWaitNode_entry,
  TP_ARGS(
    cudaGraphNode_t *, pGraphNode,
    cudaGraph_t, graph,
    const cudaGraphNode_t *, pDependencies,
    size_t, numDependencies,
    cudaEvent_t, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pGraphNode, (uintptr_t)(pGraphNode))
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, pDependencies, (uintptr_t)(pDependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphAddEventWaitNode_exit,
  TP_ARGS(
    cudaGraphNode_t *, pGraphNode,
    cudaGraph_t, graph,
    const cudaGraphNode_t *, pDependencies,
    size_t, numDependencies,
    cudaEvent_t, event,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphEventWaitNodeGetEvent_entry,
  TP_ARGS(
    cudaGraphNode_t, node,
    cudaEvent_t *, event_out
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, event_out, (uintptr_t)(event_out))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphEventWaitNodeGetEvent_exit,
  TP_ARGS(
    cudaGraphNode_t, node,
    cudaEvent_t *, event_out,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphEventWaitNodeSetEvent_entry,
  TP_ARGS(
    cudaGraphNode_t, node,
    cudaEvent_t, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphEventWaitNodeSetEvent_exit,
  TP_ARGS(
    cudaGraphNode_t, node,
    cudaEvent_t, event,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphAddExternalSemaphoresSignalNode_entry,
  TP_ARGS(
    cudaGraphNode_t *, pGraphNode,
    cudaGraph_t, graph,
    const cudaGraphNode_t *, pDependencies,
    size_t, numDependencies,
    const struct cudaExternalSemaphoreSignalNodeParams *, nodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pGraphNode, (uintptr_t)(pGraphNode))
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, pDependencies, (uintptr_t)(pDependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphAddExternalSemaphoresSignalNode_exit,
  TP_ARGS(
    cudaGraphNode_t *, pGraphNode,
    cudaGraph_t, graph,
    const cudaGraphNode_t *, pDependencies,
    size_t, numDependencies,
    const struct cudaExternalSemaphoreSignalNodeParams *, nodeParams,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExternalSemaphoresSignalNodeGetParams_entry,
  TP_ARGS(
    cudaGraphNode_t, hNode,
    struct cudaExternalSemaphoreSignalNodeParams *, params_out
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, params_out, (uintptr_t)(params_out))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExternalSemaphoresSignalNodeGetParams_exit,
  TP_ARGS(
    cudaGraphNode_t, hNode,
    struct cudaExternalSemaphoreSignalNodeParams *, params_out,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExternalSemaphoresSignalNodeSetParams_entry,
  TP_ARGS(
    cudaGraphNode_t, hNode,
    const struct cudaExternalSemaphoreSignalNodeParams *, nodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExternalSemaphoresSignalNodeSetParams_exit,
  TP_ARGS(
    cudaGraphNode_t, hNode,
    const struct cudaExternalSemaphoreSignalNodeParams *, nodeParams,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphAddExternalSemaphoresWaitNode_entry,
  TP_ARGS(
    cudaGraphNode_t *, pGraphNode,
    cudaGraph_t, graph,
    const cudaGraphNode_t *, pDependencies,
    size_t, numDependencies,
    const struct cudaExternalSemaphoreWaitNodeParams *, nodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pGraphNode, (uintptr_t)(pGraphNode))
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, pDependencies, (uintptr_t)(pDependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphAddExternalSemaphoresWaitNode_exit,
  TP_ARGS(
    cudaGraphNode_t *, pGraphNode,
    cudaGraph_t, graph,
    const cudaGraphNode_t *, pDependencies,
    size_t, numDependencies,
    const struct cudaExternalSemaphoreWaitNodeParams *, nodeParams,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExternalSemaphoresWaitNodeGetParams_entry,
  TP_ARGS(
    cudaGraphNode_t, hNode,
    struct cudaExternalSemaphoreWaitNodeParams *, params_out
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, params_out, (uintptr_t)(params_out))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExternalSemaphoresWaitNodeGetParams_exit,
  TP_ARGS(
    cudaGraphNode_t, hNode,
    struct cudaExternalSemaphoreWaitNodeParams *, params_out,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExternalSemaphoresWaitNodeSetParams_entry,
  TP_ARGS(
    cudaGraphNode_t, hNode,
    const struct cudaExternalSemaphoreWaitNodeParams *, nodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExternalSemaphoresWaitNodeSetParams_exit,
  TP_ARGS(
    cudaGraphNode_t, hNode,
    const struct cudaExternalSemaphoreWaitNodeParams *, nodeParams,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphAddMemAllocNode_entry,
  TP_ARGS(
    cudaGraphNode_t *, pGraphNode,
    cudaGraph_t, graph,
    const cudaGraphNode_t *, pDependencies,
    size_t, numDependencies,
    struct cudaMemAllocNodeParams *, nodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pGraphNode, (uintptr_t)(pGraphNode))
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, pDependencies, (uintptr_t)(pDependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphAddMemAllocNode_exit,
  TP_ARGS(
    cudaGraphNode_t *, pGraphNode,
    cudaGraph_t, graph,
    const cudaGraphNode_t *, pDependencies,
    size_t, numDependencies,
    struct cudaMemAllocNodeParams *, nodeParams,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphMemAllocNodeGetParams_entry,
  TP_ARGS(
    cudaGraphNode_t, node,
    struct cudaMemAllocNodeParams *, params_out
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, params_out, (uintptr_t)(params_out))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphMemAllocNodeGetParams_exit,
  TP_ARGS(
    cudaGraphNode_t, node,
    struct cudaMemAllocNodeParams *, params_out,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphAddMemFreeNode_entry,
  TP_ARGS(
    cudaGraphNode_t *, pGraphNode,
    cudaGraph_t, graph,
    const cudaGraphNode_t *, pDependencies,
    size_t, numDependencies,
    void *, dptr
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pGraphNode, (uintptr_t)(pGraphNode))
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, pDependencies, (uintptr_t)(pDependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, dptr, (uintptr_t)(dptr))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphAddMemFreeNode_exit,
  TP_ARGS(
    cudaGraphNode_t *, pGraphNode,
    cudaGraph_t, graph,
    const cudaGraphNode_t *, pDependencies,
    size_t, numDependencies,
    void *, dptr,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphMemFreeNodeGetParams_entry,
  TP_ARGS(
    cudaGraphNode_t, node,
    void *, dptr_out
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, dptr_out, (uintptr_t)(dptr_out))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphMemFreeNodeGetParams_exit,
  TP_ARGS(
    cudaGraphNode_t, node,
    void *, dptr_out,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceGraphMemTrim_entry,
  TP_ARGS(
    int, device
  ),
  TP_FIELDS(
    ctf_integer(int, device, device)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceGraphMemTrim_exit,
  TP_ARGS(
    int, device,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceGetGraphMemAttribute_entry,
  TP_ARGS(
    int, device,
    enum cudaGraphMemAttributeType, attr,
    void *, value
  ),
  TP_FIELDS(
    ctf_integer(int, device, device)
    ctf_integer(enum cudaGraphMemAttributeType, attr, attr)
    ctf_integer_hex(uintptr_t, value, (uintptr_t)(value))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceGetGraphMemAttribute_exit,
  TP_ARGS(
    int, device,
    enum cudaGraphMemAttributeType, attr,
    void *, value,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceSetGraphMemAttribute_entry,
  TP_ARGS(
    int, device,
    enum cudaGraphMemAttributeType, attr,
    void *, value
  ),
  TP_FIELDS(
    ctf_integer(int, device, device)
    ctf_integer(enum cudaGraphMemAttributeType, attr, attr)
    ctf_integer_hex(uintptr_t, value, (uintptr_t)(value))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaDeviceSetGraphMemAttribute_exit,
  TP_ARGS(
    int, device,
    enum cudaGraphMemAttributeType, attr,
    void *, value,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphClone_entry,
  TP_ARGS(
    cudaGraph_t *, pGraphClone,
    cudaGraph_t, originalGraph
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pGraphClone, (uintptr_t)(pGraphClone))
    ctf_integer_hex(uintptr_t, originalGraph, (uintptr_t)(originalGraph))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphClone_exit,
  TP_ARGS(
    cudaGraph_t *, pGraphClone,
    cudaGraph_t, originalGraph,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphNodeFindInClone_entry,
  TP_ARGS(
    cudaGraphNode_t *, pNode,
    cudaGraphNode_t, originalNode,
    cudaGraph_t, clonedGraph
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pNode, (uintptr_t)(pNode))
    ctf_integer_hex(uintptr_t, originalNode, (uintptr_t)(originalNode))
    ctf_integer_hex(uintptr_t, clonedGraph, (uintptr_t)(clonedGraph))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphNodeFindInClone_exit,
  TP_ARGS(
    cudaGraphNode_t *, pNode,
    cudaGraphNode_t, originalNode,
    cudaGraph_t, clonedGraph,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphNodeGetType_entry,
  TP_ARGS(
    cudaGraphNode_t, node,
    enum cudaGraphNodeType *, pType
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, pType, (uintptr_t)(pType))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphNodeGetType_exit,
  TP_ARGS(
    cudaGraphNode_t, node,
    enum cudaGraphNodeType *, pType,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphGetNodes_entry,
  TP_ARGS(
    cudaGraph_t, graph,
    cudaGraphNode_t *, nodes,
    size_t *, numNodes
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, nodes, (uintptr_t)(nodes))
    ctf_integer_hex(uintptr_t, numNodes, (uintptr_t)(numNodes))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphGetNodes_exit,
  TP_ARGS(
    cudaGraph_t, graph,
    cudaGraphNode_t *, nodes,
    size_t *, numNodes,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphGetRootNodes_entry,
  TP_ARGS(
    cudaGraph_t, graph,
    cudaGraphNode_t *, pRootNodes,
    size_t *, pNumRootNodes
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, pRootNodes, (uintptr_t)(pRootNodes))
    ctf_integer_hex(uintptr_t, pNumRootNodes, (uintptr_t)(pNumRootNodes))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphGetRootNodes_exit,
  TP_ARGS(
    cudaGraph_t, graph,
    cudaGraphNode_t *, pRootNodes,
    size_t *, pNumRootNodes,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphGetEdges_entry,
  TP_ARGS(
    cudaGraph_t, graph,
    cudaGraphNode_t *, from,
    cudaGraphNode_t *, to,
    cudaGraphEdgeData *, edgeData,
    size_t *, numEdges
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, from, (uintptr_t)(from))
    ctf_integer_hex(uintptr_t, to, (uintptr_t)(to))
    ctf_integer_hex(uintptr_t, edgeData, (uintptr_t)(edgeData))
    ctf_integer_hex(uintptr_t, numEdges, (uintptr_t)(numEdges))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphGetEdges_exit,
  TP_ARGS(
    cudaGraph_t, graph,
    cudaGraphNode_t *, from,
    cudaGraphNode_t *, to,
    cudaGraphEdgeData *, edgeData,
    size_t *, numEdges,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphNodeGetDependencies_entry,
  TP_ARGS(
    cudaGraphNode_t, node,
    cudaGraphNode_t *, pDependencies,
    cudaGraphEdgeData *, edgeData,
    size_t *, pNumDependencies
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, pDependencies, (uintptr_t)(pDependencies))
    ctf_integer_hex(uintptr_t, edgeData, (uintptr_t)(edgeData))
    ctf_integer_hex(uintptr_t, pNumDependencies, (uintptr_t)(pNumDependencies))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphNodeGetDependencies_exit,
  TP_ARGS(
    cudaGraphNode_t, node,
    cudaGraphNode_t *, pDependencies,
    cudaGraphEdgeData *, edgeData,
    size_t *, pNumDependencies,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphNodeGetDependentNodes_entry,
  TP_ARGS(
    cudaGraphNode_t, node,
    cudaGraphNode_t *, pDependentNodes,
    cudaGraphEdgeData *, edgeData,
    size_t *, pNumDependentNodes
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, pDependentNodes, (uintptr_t)(pDependentNodes))
    ctf_integer_hex(uintptr_t, edgeData, (uintptr_t)(edgeData))
    ctf_integer_hex(uintptr_t, pNumDependentNodes, (uintptr_t)(pNumDependentNodes))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphNodeGetDependentNodes_exit,
  TP_ARGS(
    cudaGraphNode_t, node,
    cudaGraphNode_t *, pDependentNodes,
    cudaGraphEdgeData *, edgeData,
    size_t *, pNumDependentNodes,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphAddDependencies_entry,
  TP_ARGS(
    cudaGraph_t, graph,
    const cudaGraphNode_t *, from,
    const cudaGraphNode_t *, to,
    const cudaGraphEdgeData *, edgeData,
    size_t, numDependencies
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, from, (uintptr_t)(from))
    ctf_integer_hex(uintptr_t, to, (uintptr_t)(to))
    ctf_integer_hex(uintptr_t, edgeData, (uintptr_t)(edgeData))
    ctf_integer(size_t, numDependencies, numDependencies)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphAddDependencies_exit,
  TP_ARGS(
    cudaGraph_t, graph,
    const cudaGraphNode_t *, from,
    const cudaGraphNode_t *, to,
    const cudaGraphEdgeData *, edgeData,
    size_t, numDependencies,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphRemoveDependencies_entry,
  TP_ARGS(
    cudaGraph_t, graph,
    const cudaGraphNode_t *, from,
    const cudaGraphNode_t *, to,
    const cudaGraphEdgeData *, edgeData,
    size_t, numDependencies
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, from, (uintptr_t)(from))
    ctf_integer_hex(uintptr_t, to, (uintptr_t)(to))
    ctf_integer_hex(uintptr_t, edgeData, (uintptr_t)(edgeData))
    ctf_integer(size_t, numDependencies, numDependencies)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphRemoveDependencies_exit,
  TP_ARGS(
    cudaGraph_t, graph,
    const cudaGraphNode_t *, from,
    const cudaGraphNode_t *, to,
    const cudaGraphEdgeData *, edgeData,
    size_t, numDependencies,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphDestroyNode_entry,
  TP_ARGS(
    cudaGraphNode_t, node
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphDestroyNode_exit,
  TP_ARGS(
    cudaGraphNode_t, node,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphInstantiate_entry,
  TP_ARGS(
    cudaGraphExec_t *, pGraphExec,
    cudaGraph_t, graph,
    unsigned long long int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pGraphExec, (uintptr_t)(pGraphExec))
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer(unsigned long long int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphInstantiate_exit,
  TP_ARGS(
    cudaGraphExec_t *, pGraphExec,
    cudaGraph_t, graph,
    unsigned long long int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphInstantiateWithFlags_entry,
  TP_ARGS(
    cudaGraphExec_t *, pGraphExec,
    cudaGraph_t, graph,
    unsigned long long int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pGraphExec, (uintptr_t)(pGraphExec))
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer(unsigned long long int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphInstantiateWithFlags_exit,
  TP_ARGS(
    cudaGraphExec_t *, pGraphExec,
    cudaGraph_t, graph,
    unsigned long long int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphInstantiateWithParams_ptsz_entry,
  TP_ARGS(
    cudaGraphExec_t *, pGraphExec,
    cudaGraph_t, graph,
    cudaGraphInstantiateParams *, instantiateParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pGraphExec, (uintptr_t)(pGraphExec))
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, instantiateParams, (uintptr_t)(instantiateParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphInstantiateWithParams_ptsz_exit,
  TP_ARGS(
    cudaGraphExec_t *, pGraphExec,
    cudaGraph_t, graph,
    cudaGraphInstantiateParams *, instantiateParams,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExecGetFlags_entry,
  TP_ARGS(
    cudaGraphExec_t, graphExec,
    unsigned long long int *, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, graphExec, (uintptr_t)(graphExec))
    ctf_integer_hex(uintptr_t, flags, (uintptr_t)(flags))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExecGetFlags_exit,
  TP_ARGS(
    cudaGraphExec_t, graphExec,
    unsigned long long int *, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExecKernelNodeSetParams_entry,
  TP_ARGS(
    cudaGraphExec_t, hGraphExec,
    cudaGraphNode_t, node,
    const struct cudaKernelNodeParams *, pNodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, pNodeParams, (uintptr_t)(pNodeParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExecKernelNodeSetParams_exit,
  TP_ARGS(
    cudaGraphExec_t, hGraphExec,
    cudaGraphNode_t, node,
    const struct cudaKernelNodeParams *, pNodeParams,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExecMemcpyNodeSetParams_entry,
  TP_ARGS(
    cudaGraphExec_t, hGraphExec,
    cudaGraphNode_t, node,
    const struct cudaMemcpy3DParms *, pNodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, pNodeParams, (uintptr_t)(pNodeParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExecMemcpyNodeSetParams_exit,
  TP_ARGS(
    cudaGraphExec_t, hGraphExec,
    cudaGraphNode_t, node,
    const struct cudaMemcpy3DParms *, pNodeParams,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExecMemcpyNodeSetParamsToSymbol_entry,
  TP_ARGS(
    cudaGraphExec_t, hGraphExec,
    cudaGraphNode_t, node,
    const void *, symbol,
    const void *, src,
    size_t, count,
    size_t, offset,
    enum cudaMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, count, count)
    ctf_integer(size_t, offset, offset)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExecMemcpyNodeSetParamsToSymbol_exit,
  TP_ARGS(
    cudaGraphExec_t, hGraphExec,
    cudaGraphNode_t, node,
    const void *, symbol,
    const void *, src,
    size_t, count,
    size_t, offset,
    enum cudaMemcpyKind, kind,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExecMemcpyNodeSetParamsFromSymbol_entry,
  TP_ARGS(
    cudaGraphExec_t, hGraphExec,
    cudaGraphNode_t, node,
    void *, dst,
    const void *, symbol,
    size_t, count,
    size_t, offset,
    enum cudaMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
    ctf_integer(size_t, count, count)
    ctf_integer(size_t, offset, offset)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExecMemcpyNodeSetParamsFromSymbol_exit,
  TP_ARGS(
    cudaGraphExec_t, hGraphExec,
    cudaGraphNode_t, node,
    void *, dst,
    const void *, symbol,
    size_t, count,
    size_t, offset,
    enum cudaMemcpyKind, kind,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExecMemcpyNodeSetParams1D_entry,
  TP_ARGS(
    cudaGraphExec_t, hGraphExec,
    cudaGraphNode_t, node,
    void *, dst,
    const void *, src,
    size_t, count,
    enum cudaMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, count, count)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExecMemcpyNodeSetParams1D_exit,
  TP_ARGS(
    cudaGraphExec_t, hGraphExec,
    cudaGraphNode_t, node,
    void *, dst,
    const void *, src,
    size_t, count,
    enum cudaMemcpyKind, kind,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExecMemsetNodeSetParams_entry,
  TP_ARGS(
    cudaGraphExec_t, hGraphExec,
    cudaGraphNode_t, node,
    const struct cudaMemsetParams *, pNodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, pNodeParams, (uintptr_t)(pNodeParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExecMemsetNodeSetParams_exit,
  TP_ARGS(
    cudaGraphExec_t, hGraphExec,
    cudaGraphNode_t, node,
    const struct cudaMemsetParams *, pNodeParams,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExecHostNodeSetParams_entry,
  TP_ARGS(
    cudaGraphExec_t, hGraphExec,
    cudaGraphNode_t, node,
    const struct cudaHostNodeParams *, pNodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, pNodeParams, (uintptr_t)(pNodeParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExecHostNodeSetParams_exit,
  TP_ARGS(
    cudaGraphExec_t, hGraphExec,
    cudaGraphNode_t, node,
    const struct cudaHostNodeParams *, pNodeParams,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExecChildGraphNodeSetParams_entry,
  TP_ARGS(
    cudaGraphExec_t, hGraphExec,
    cudaGraphNode_t, node,
    cudaGraph_t, childGraph
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, childGraph, (uintptr_t)(childGraph))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExecChildGraphNodeSetParams_exit,
  TP_ARGS(
    cudaGraphExec_t, hGraphExec,
    cudaGraphNode_t, node,
    cudaGraph_t, childGraph,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExecEventRecordNodeSetEvent_entry,
  TP_ARGS(
    cudaGraphExec_t, hGraphExec,
    cudaGraphNode_t, hNode,
    cudaEvent_t, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExecEventRecordNodeSetEvent_exit,
  TP_ARGS(
    cudaGraphExec_t, hGraphExec,
    cudaGraphNode_t, hNode,
    cudaEvent_t, event,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExecEventWaitNodeSetEvent_entry,
  TP_ARGS(
    cudaGraphExec_t, hGraphExec,
    cudaGraphNode_t, hNode,
    cudaEvent_t, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExecEventWaitNodeSetEvent_exit,
  TP_ARGS(
    cudaGraphExec_t, hGraphExec,
    cudaGraphNode_t, hNode,
    cudaEvent_t, event,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExecExternalSemaphoresSignalNodeSetParams_entry,
  TP_ARGS(
    cudaGraphExec_t, hGraphExec,
    cudaGraphNode_t, hNode,
    const struct cudaExternalSemaphoreSignalNodeParams *, nodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExecExternalSemaphoresSignalNodeSetParams_exit,
  TP_ARGS(
    cudaGraphExec_t, hGraphExec,
    cudaGraphNode_t, hNode,
    const struct cudaExternalSemaphoreSignalNodeParams *, nodeParams,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExecExternalSemaphoresWaitNodeSetParams_entry,
  TP_ARGS(
    cudaGraphExec_t, hGraphExec,
    cudaGraphNode_t, hNode,
    const struct cudaExternalSemaphoreWaitNodeParams *, nodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExecExternalSemaphoresWaitNodeSetParams_exit,
  TP_ARGS(
    cudaGraphExec_t, hGraphExec,
    cudaGraphNode_t, hNode,
    const struct cudaExternalSemaphoreWaitNodeParams *, nodeParams,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphNodeSetEnabled_entry,
  TP_ARGS(
    cudaGraphExec_t, hGraphExec,
    cudaGraphNode_t, hNode,
    unsigned int, isEnabled
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer(unsigned int, isEnabled, isEnabled)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphNodeSetEnabled_exit,
  TP_ARGS(
    cudaGraphExec_t, hGraphExec,
    cudaGraphNode_t, hNode,
    unsigned int, isEnabled,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphNodeGetEnabled_entry,
  TP_ARGS(
    cudaGraphExec_t, hGraphExec,
    cudaGraphNode_t, hNode,
    unsigned int *, isEnabled
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, isEnabled, (uintptr_t)(isEnabled))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphNodeGetEnabled_exit,
  TP_ARGS(
    cudaGraphExec_t, hGraphExec,
    cudaGraphNode_t, hNode,
    unsigned int *, isEnabled,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExecUpdate_entry,
  TP_ARGS(
    cudaGraphExec_t, hGraphExec,
    cudaGraph_t, hGraph,
    cudaGraphExecUpdateResultInfo *, resultInfo
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, resultInfo, (uintptr_t)(resultInfo))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExecUpdate_exit,
  TP_ARGS(
    cudaGraphExec_t, hGraphExec,
    cudaGraph_t, hGraph,
    cudaGraphExecUpdateResultInfo *, resultInfo,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphUpload_ptsz_entry,
  TP_ARGS(
    cudaGraphExec_t, graphExec,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, graphExec, (uintptr_t)(graphExec))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphUpload_ptsz_exit,
  TP_ARGS(
    cudaGraphExec_t, graphExec,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphLaunch_ptsz_entry,
  TP_ARGS(
    cudaGraphExec_t, graphExec,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, graphExec, (uintptr_t)(graphExec))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphLaunch_ptsz_exit,
  TP_ARGS(
    cudaGraphExec_t, graphExec,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExecDestroy_entry,
  TP_ARGS(
    cudaGraphExec_t, graphExec
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, graphExec, (uintptr_t)(graphExec))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExecDestroy_exit,
  TP_ARGS(
    cudaGraphExec_t, graphExec,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphDestroy_entry,
  TP_ARGS(
    cudaGraph_t, graph
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphDestroy_exit,
  TP_ARGS(
    cudaGraph_t, graph,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphDebugDotPrint_entry,
  TP_ARGS(
    cudaGraph_t, graph,
    const char *, path,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, path, (uintptr_t)(path))
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphDebugDotPrint_exit,
  TP_ARGS(
    cudaGraph_t, graph,
    const char *, path,
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaUserObjectCreate_entry,
  TP_ARGS(
    cudaUserObject_t *, object_out,
    void *, ptr,
    cudaHostFn_t, destroy,
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
  lttng_ust_cudart,
  cudaUserObjectCreate_exit,
  TP_ARGS(
    cudaUserObject_t *, object_out,
    void *, ptr,
    cudaHostFn_t, destroy,
    unsigned int, initialRefcount,
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaUserObjectRetain_entry,
  TP_ARGS(
    cudaUserObject_t, object,
    unsigned int, count
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, object, (uintptr_t)(object))
    ctf_integer(unsigned int, count, count)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaUserObjectRetain_exit,
  TP_ARGS(
    cudaUserObject_t, object,
    unsigned int, count,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaUserObjectRelease_entry,
  TP_ARGS(
    cudaUserObject_t, object,
    unsigned int, count
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, object, (uintptr_t)(object))
    ctf_integer(unsigned int, count, count)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaUserObjectRelease_exit,
  TP_ARGS(
    cudaUserObject_t, object,
    unsigned int, count,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphRetainUserObject_entry,
  TP_ARGS(
    cudaGraph_t, graph,
    cudaUserObject_t, object,
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
  lttng_ust_cudart,
  cudaGraphRetainUserObject_exit,
  TP_ARGS(
    cudaGraph_t, graph,
    cudaUserObject_t, object,
    unsigned int, count,
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphReleaseUserObject_entry,
  TP_ARGS(
    cudaGraph_t, graph,
    cudaUserObject_t, object,
    unsigned int, count
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, object, (uintptr_t)(object))
    ctf_integer(unsigned int, count, count)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphReleaseUserObject_exit,
  TP_ARGS(
    cudaGraph_t, graph,
    cudaUserObject_t, object,
    unsigned int, count,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphAddNode_entry,
  TP_ARGS(
    cudaGraphNode_t *, pGraphNode,
    cudaGraph_t, graph,
    const cudaGraphNode_t *, pDependencies,
    const cudaGraphEdgeData *, dependencyData,
    size_t, numDependencies,
    struct cudaGraphNodeParams *, nodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pGraphNode, (uintptr_t)(pGraphNode))
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, pDependencies, (uintptr_t)(pDependencies))
    ctf_integer_hex(uintptr_t, dependencyData, (uintptr_t)(dependencyData))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphAddNode_exit,
  TP_ARGS(
    cudaGraphNode_t *, pGraphNode,
    cudaGraph_t, graph,
    const cudaGraphNode_t *, pDependencies,
    const cudaGraphEdgeData *, dependencyData,
    size_t, numDependencies,
    struct cudaGraphNodeParams *, nodeParams,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphNodeSetParams_entry,
  TP_ARGS(
    cudaGraphNode_t, node,
    struct cudaGraphNodeParams *, nodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphNodeSetParams_exit,
  TP_ARGS(
    cudaGraphNode_t, node,
    struct cudaGraphNodeParams *, nodeParams,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExecNodeSetParams_entry,
  TP_ARGS(
    cudaGraphExec_t, graphExec,
    cudaGraphNode_t, node,
    struct cudaGraphNodeParams *, nodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, graphExec, (uintptr_t)(graphExec))
    ctf_integer_hex(uintptr_t, node, (uintptr_t)(node))
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphExecNodeSetParams_exit,
  TP_ARGS(
    cudaGraphExec_t, graphExec,
    cudaGraphNode_t, node,
    struct cudaGraphNodeParams *, nodeParams,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphConditionalHandleCreate_entry,
  TP_ARGS(
    cudaGraphConditionalHandle *, pHandle_out,
    cudaGraph_t, graph,
    unsigned int, defaultLaunchValue,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pHandle_out, (uintptr_t)(pHandle_out))
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer(unsigned int, defaultLaunchValue, defaultLaunchValue)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphConditionalHandleCreate_exit,
  TP_ARGS(
    cudaGraphConditionalHandle *, pHandle_out,
    cudaGraph_t, graph,
    unsigned int, defaultLaunchValue,
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetDriverEntryPoint_ptsz_entry,
  TP_ARGS(
    const char *, symbol,
    void **, funcPtr,
    unsigned long long int, flags,
    enum cudaDriverEntryPointQueryResult *, driverStatus
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
    ctf_integer_hex(uintptr_t, funcPtr, (uintptr_t)(funcPtr))
    ctf_integer(unsigned long long int, flags, flags)
    ctf_integer_hex(uintptr_t, driverStatus, (uintptr_t)(driverStatus))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetDriverEntryPoint_ptsz_exit,
  TP_ARGS(
    const char *, symbol,
    void **, funcPtr,
    unsigned long long int, flags,
    enum cudaDriverEntryPointQueryResult *, driverStatus,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetDriverEntryPointByVersion_ptsz_entry,
  TP_ARGS(
    const char *, symbol,
    void **, funcPtr,
    unsigned int, cudaVersion,
    unsigned long long int, flags,
    enum cudaDriverEntryPointQueryResult *, driverStatus
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
    ctf_integer_hex(uintptr_t, funcPtr, (uintptr_t)(funcPtr))
    ctf_integer(unsigned int, cudaVersion, cudaVersion)
    ctf_integer(unsigned long long int, flags, flags)
    ctf_integer_hex(uintptr_t, driverStatus, (uintptr_t)(driverStatus))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetDriverEntryPointByVersion_ptsz_exit,
  TP_ARGS(
    const char *, symbol,
    void **, funcPtr,
    unsigned int, cudaVersion,
    unsigned long long int, flags,
    enum cudaDriverEntryPointQueryResult *, driverStatus,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLibraryLoadData_entry,
  TP_ARGS(
    cudaLibrary_t *, library,
    const void *, code,
    enum cudaJitOption *, jitOptions,
    void **, jitOptionsValues,
    unsigned int, numJitOptions,
    enum cudaLibraryOption *, libraryOptions,
    void **, libraryOptionValues,
    unsigned int, numLibraryOptions
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, library, (uintptr_t)(library))
    ctf_integer_hex(uintptr_t, code, (uintptr_t)(code))
    ctf_integer_hex(uintptr_t, jitOptions, (uintptr_t)(jitOptions))
    ctf_integer_hex(uintptr_t, jitOptionsValues, (uintptr_t)(jitOptionsValues))
    ctf_integer(unsigned int, numJitOptions, numJitOptions)
    ctf_integer_hex(uintptr_t, libraryOptions, (uintptr_t)(libraryOptions))
    ctf_integer_hex(uintptr_t, libraryOptionValues, (uintptr_t)(libraryOptionValues))
    ctf_integer(unsigned int, numLibraryOptions, numLibraryOptions)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLibraryLoadData_exit,
  TP_ARGS(
    cudaLibrary_t *, library,
    const void *, code,
    enum cudaJitOption *, jitOptions,
    void **, jitOptionsValues,
    unsigned int, numJitOptions,
    enum cudaLibraryOption *, libraryOptions,
    void **, libraryOptionValues,
    unsigned int, numLibraryOptions,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLibraryLoadFromFile_entry,
  TP_ARGS(
    cudaLibrary_t *, library,
    const char *, fileName,
    enum cudaJitOption *, jitOptions,
    void **, jitOptionsValues,
    unsigned int, numJitOptions,
    enum cudaLibraryOption *, libraryOptions,
    void **, libraryOptionValues,
    unsigned int, numLibraryOptions
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, library, (uintptr_t)(library))
    ctf_integer_hex(uintptr_t, fileName, (uintptr_t)(fileName))
    ctf_integer_hex(uintptr_t, jitOptions, (uintptr_t)(jitOptions))
    ctf_integer_hex(uintptr_t, jitOptionsValues, (uintptr_t)(jitOptionsValues))
    ctf_integer(unsigned int, numJitOptions, numJitOptions)
    ctf_integer_hex(uintptr_t, libraryOptions, (uintptr_t)(libraryOptions))
    ctf_integer_hex(uintptr_t, libraryOptionValues, (uintptr_t)(libraryOptionValues))
    ctf_integer(unsigned int, numLibraryOptions, numLibraryOptions)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLibraryLoadFromFile_exit,
  TP_ARGS(
    cudaLibrary_t *, library,
    const char *, fileName,
    enum cudaJitOption *, jitOptions,
    void **, jitOptionsValues,
    unsigned int, numJitOptions,
    enum cudaLibraryOption *, libraryOptions,
    void **, libraryOptionValues,
    unsigned int, numLibraryOptions,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLibraryUnload_entry,
  TP_ARGS(
    cudaLibrary_t, library
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, library, (uintptr_t)(library))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLibraryUnload_exit,
  TP_ARGS(
    cudaLibrary_t, library,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLibraryGetKernel_entry,
  TP_ARGS(
    cudaKernel_t *, pKernel,
    cudaLibrary_t, library,
    const char *, name
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pKernel, (uintptr_t)(pKernel))
    ctf_integer_hex(uintptr_t, library, (uintptr_t)(library))
    ctf_integer_hex(uintptr_t, name, (uintptr_t)(name))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLibraryGetKernel_exit,
  TP_ARGS(
    cudaKernel_t *, pKernel,
    cudaLibrary_t, library,
    const char *, name,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLibraryGetGlobal_entry,
  TP_ARGS(
    void **, dptr,
    size_t *, bytes,
    cudaLibrary_t, library,
    const char *, name
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dptr, (uintptr_t)(dptr))
    ctf_integer_hex(uintptr_t, bytes, (uintptr_t)(bytes))
    ctf_integer_hex(uintptr_t, library, (uintptr_t)(library))
    ctf_integer_hex(uintptr_t, name, (uintptr_t)(name))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLibraryGetGlobal_exit,
  TP_ARGS(
    void **, dptr,
    size_t *, bytes,
    cudaLibrary_t, library,
    const char *, name,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLibraryGetManaged_entry,
  TP_ARGS(
    void **, dptr,
    size_t *, bytes,
    cudaLibrary_t, library,
    const char *, name
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dptr, (uintptr_t)(dptr))
    ctf_integer_hex(uintptr_t, bytes, (uintptr_t)(bytes))
    ctf_integer_hex(uintptr_t, library, (uintptr_t)(library))
    ctf_integer_hex(uintptr_t, name, (uintptr_t)(name))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLibraryGetManaged_exit,
  TP_ARGS(
    void **, dptr,
    size_t *, bytes,
    cudaLibrary_t, library,
    const char *, name,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLibraryGetUnifiedFunction_entry,
  TP_ARGS(
    void **, fptr,
    cudaLibrary_t, library,
    const char *, symbol
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, fptr, (uintptr_t)(fptr))
    ctf_integer_hex(uintptr_t, library, (uintptr_t)(library))
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLibraryGetUnifiedFunction_exit,
  TP_ARGS(
    void **, fptr,
    cudaLibrary_t, library,
    const char *, symbol,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLibraryGetKernelCount_entry,
  TP_ARGS(
    unsigned int *, count,
    cudaLibrary_t, lib
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, count, (uintptr_t)(count))
    ctf_integer_hex(uintptr_t, lib, (uintptr_t)(lib))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLibraryGetKernelCount_exit,
  TP_ARGS(
    unsigned int *, count,
    cudaLibrary_t, lib,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLibraryEnumerateKernels_entry,
  TP_ARGS(
    cudaKernel_t *, kernels,
    unsigned int, numKernels,
    cudaLibrary_t, lib
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, kernels, (uintptr_t)(kernels))
    ctf_integer(unsigned int, numKernels, numKernels)
    ctf_integer_hex(uintptr_t, lib, (uintptr_t)(lib))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLibraryEnumerateKernels_exit,
  TP_ARGS(
    cudaKernel_t *, kernels,
    unsigned int, numKernels,
    cudaLibrary_t, lib,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaKernelSetAttributeForDevice_entry,
  TP_ARGS(
    cudaKernel_t, kernel,
    enum cudaFuncAttribute, attr,
    int, value,
    int, device
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, kernel, (uintptr_t)(kernel))
    ctf_integer(enum cudaFuncAttribute, attr, attr)
    ctf_integer(int, value, value)
    ctf_integer(int, device, device)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaKernelSetAttributeForDevice_exit,
  TP_ARGS(
    cudaKernel_t, kernel,
    enum cudaFuncAttribute, attr,
    int, value,
    int, device,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetExportTable_entry,
  TP_ARGS(
    const void **, ppExportTable,
    const cudaUUID_t *, pExportTableId
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ppExportTable, (uintptr_t)(ppExportTable))
    ctf_integer_hex(uintptr_t, pExportTableId, (uintptr_t)(pExportTableId))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetExportTable_exit,
  TP_ARGS(
    const void **, ppExportTable,
    const cudaUUID_t *, pExportTableId,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetFuncBySymbol_entry,
  TP_ARGS(
    cudaFunction_t *, functionPtr,
    const void *, symbolPtr
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, functionPtr, (uintptr_t)(functionPtr))
    ctf_integer_hex(uintptr_t, symbolPtr, (uintptr_t)(symbolPtr))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetFuncBySymbol_exit,
  TP_ARGS(
    cudaFunction_t *, functionPtr,
    const void *, symbolPtr,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetKernel_entry,
  TP_ARGS(
    cudaKernel_t *, kernelPtr,
    const void *, entryFuncAddr
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, kernelPtr, (uintptr_t)(kernelPtr))
    ctf_integer_hex(uintptr_t, entryFuncAddr, (uintptr_t)(entryFuncAddr))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetKernel_exit,
  TP_ARGS(
    cudaKernel_t *, kernelPtr,
    const void *, entryFuncAddr,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy_entry,
  TP_ARGS(
    void *, dst,
    const void *, src,
    size_t, count,
    enum cudaMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, count, count)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy_exit,
  TP_ARGS(
    void *, dst,
    const void *, src,
    size_t, count,
    enum cudaMemcpyKind, kind,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyToSymbol_entry,
  TP_ARGS(
    const void *, symbol,
    const void *, src,
    size_t, count,
    size_t, offset,
    enum cudaMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, count, count)
    ctf_integer(size_t, offset, offset)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyToSymbol_exit,
  TP_ARGS(
    const void *, symbol,
    const void *, src,
    size_t, count,
    size_t, offset,
    enum cudaMemcpyKind, kind,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyFromSymbol_entry,
  TP_ARGS(
    void *, dst,
    const void *, symbol,
    size_t, count,
    size_t, offset,
    enum cudaMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
    ctf_integer(size_t, count, count)
    ctf_integer(size_t, offset, offset)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyFromSymbol_exit,
  TP_ARGS(
    void *, dst,
    const void *, symbol,
    size_t, count,
    size_t, offset,
    enum cudaMemcpyKind, kind,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy2D_entry,
  TP_ARGS(
    void *, dst,
    size_t, dpitch,
    const void *, src,
    size_t, spitch,
    size_t, width,
    size_t, height,
    enum cudaMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, dpitch, dpitch)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, spitch, spitch)
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy2D_exit,
  TP_ARGS(
    void *, dst,
    size_t, dpitch,
    const void *, src,
    size_t, spitch,
    size_t, width,
    size_t, height,
    enum cudaMemcpyKind, kind,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyToArray_entry,
  TP_ARGS(
    cudaArray_t, dst,
    size_t, wOffset,
    size_t, hOffset,
    const void *, src,
    size_t, count,
    enum cudaMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, wOffset, wOffset)
    ctf_integer(size_t, hOffset, hOffset)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, count, count)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyToArray_exit,
  TP_ARGS(
    cudaArray_t, dst,
    size_t, wOffset,
    size_t, hOffset,
    const void *, src,
    size_t, count,
    enum cudaMemcpyKind, kind,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy2DToArray_entry,
  TP_ARGS(
    cudaArray_t, dst,
    size_t, wOffset,
    size_t, hOffset,
    const void *, src,
    size_t, spitch,
    size_t, width,
    size_t, height,
    enum cudaMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, wOffset, wOffset)
    ctf_integer(size_t, hOffset, hOffset)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, spitch, spitch)
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy2DToArray_exit,
  TP_ARGS(
    cudaArray_t, dst,
    size_t, wOffset,
    size_t, hOffset,
    const void *, src,
    size_t, spitch,
    size_t, width,
    size_t, height,
    enum cudaMemcpyKind, kind,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyFromArray_entry,
  TP_ARGS(
    void *, dst,
    cudaArray_const_t, src,
    size_t, wOffset,
    size_t, hOffset,
    size_t, count,
    enum cudaMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, wOffset, wOffset)
    ctf_integer(size_t, hOffset, hOffset)
    ctf_integer(size_t, count, count)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyFromArray_exit,
  TP_ARGS(
    void *, dst,
    cudaArray_const_t, src,
    size_t, wOffset,
    size_t, hOffset,
    size_t, count,
    enum cudaMemcpyKind, kind,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy2DFromArray_entry,
  TP_ARGS(
    void *, dst,
    size_t, dpitch,
    cudaArray_const_t, src,
    size_t, wOffset,
    size_t, hOffset,
    size_t, width,
    size_t, height,
    enum cudaMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, dpitch, dpitch)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, wOffset, wOffset)
    ctf_integer(size_t, hOffset, hOffset)
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy2DFromArray_exit,
  TP_ARGS(
    void *, dst,
    size_t, dpitch,
    cudaArray_const_t, src,
    size_t, wOffset,
    size_t, hOffset,
    size_t, width,
    size_t, height,
    enum cudaMemcpyKind, kind,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyArrayToArray_entry,
  TP_ARGS(
    cudaArray_t, dst,
    size_t, wOffsetDst,
    size_t, hOffsetDst,
    cudaArray_const_t, src,
    size_t, wOffsetSrc,
    size_t, hOffsetSrc,
    size_t, count,
    enum cudaMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, wOffsetDst, wOffsetDst)
    ctf_integer(size_t, hOffsetDst, hOffsetDst)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, wOffsetSrc, wOffsetSrc)
    ctf_integer(size_t, hOffsetSrc, hOffsetSrc)
    ctf_integer(size_t, count, count)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyArrayToArray_exit,
  TP_ARGS(
    cudaArray_t, dst,
    size_t, wOffsetDst,
    size_t, hOffsetDst,
    cudaArray_const_t, src,
    size_t, wOffsetSrc,
    size_t, hOffsetSrc,
    size_t, count,
    enum cudaMemcpyKind, kind,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy2DArrayToArray_entry,
  TP_ARGS(
    cudaArray_t, dst,
    size_t, wOffsetDst,
    size_t, hOffsetDst,
    cudaArray_const_t, src,
    size_t, wOffsetSrc,
    size_t, hOffsetSrc,
    size_t, width,
    size_t, height,
    enum cudaMemcpyKind, kind
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, wOffsetDst, wOffsetDst)
    ctf_integer(size_t, hOffsetDst, hOffsetDst)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, wOffsetSrc, wOffsetSrc)
    ctf_integer(size_t, hOffsetSrc, hOffsetSrc)
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy2DArrayToArray_exit,
  TP_ARGS(
    cudaArray_t, dst,
    size_t, wOffsetDst,
    size_t, hOffsetDst,
    cudaArray_const_t, src,
    size_t, wOffsetSrc,
    size_t, hOffsetSrc,
    size_t, width,
    size_t, height,
    enum cudaMemcpyKind, kind,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy3D_entry,
  TP_ARGS(
    const struct cudaMemcpy3DParms *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy3D_exit,
  TP_ARGS(
    const struct cudaMemcpy3DParms *, p,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy3DPeer_entry,
  TP_ARGS(
    const struct cudaMemcpy3DPeerParms *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy3DPeer_exit,
  TP_ARGS(
    const struct cudaMemcpy3DPeerParms *, p,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyBatchAsync_entry,
  TP_ARGS(
    void *const *, dsts,
    const void *const *, srcs,
    const size_t *, sizes,
    size_t, count,
    struct cudaMemcpyAttributes *, attrs,
    size_t *, attrsIdxs,
    size_t, numAttrs,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dsts, (uintptr_t)(dsts))
    ctf_integer_hex(uintptr_t, srcs, (uintptr_t)(srcs))
    ctf_integer_hex(uintptr_t, sizes, (uintptr_t)(sizes))
    ctf_integer(size_t, count, count)
    ctf_integer_hex(uintptr_t, attrs, (uintptr_t)(attrs))
    ctf_integer_hex(uintptr_t, attrsIdxs, (uintptr_t)(attrsIdxs))
    ctf_integer(size_t, numAttrs, numAttrs)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyBatchAsync_exit,
  TP_ARGS(
    void *const *, dsts,
    const void *const *, srcs,
    const size_t *, sizes,
    size_t, count,
    struct cudaMemcpyAttributes *, attrs,
    size_t *, attrsIdxs,
    size_t, numAttrs,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy3DBatchAsync_entry,
  TP_ARGS(
    size_t, numOps,
    struct cudaMemcpy3DBatchOp *, opList,
    unsigned long long int, flags,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer(size_t, numOps, numOps)
    ctf_integer_hex(uintptr_t, opList, (uintptr_t)(opList))
    ctf_integer(unsigned long long int, flags, flags)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy3DBatchAsync_exit,
  TP_ARGS(
    size_t, numOps,
    struct cudaMemcpy3DBatchOp *, opList,
    unsigned long long int, flags,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemset_entry,
  TP_ARGS(
    void *, devPtr,
    int, value,
    size_t, count
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
    ctf_integer(int, value, value)
    ctf_integer(size_t, count, count)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemset_exit,
  TP_ARGS(
    void *, devPtr,
    int, value,
    size_t, count,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemset2D_entry,
  TP_ARGS(
    void *, devPtr,
    size_t, pitch,
    int, value,
    size_t, width,
    size_t, height
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
    ctf_integer(size_t, pitch, pitch)
    ctf_integer(int, value, value)
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemset2D_exit,
  TP_ARGS(
    void *, devPtr,
    size_t, pitch,
    int, value,
    size_t, width,
    size_t, height,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemset3D_entry,
  TP_ARGS(
    struct cudaPitchedPtr, pitchedDevPtr,
    int, value,
    struct cudaExtent, extent
  ),
  TP_FIELDS(
    ctf_array_text(uint8_t, pitchedDevPtr, &pitchedDevPtr, sizeof(struct cudaPitchedPtr))
    ctf_integer(int, value, value)
    ctf_array_text(uint8_t, extent, &extent, sizeof(struct cudaExtent))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemset3D_exit,
  TP_ARGS(
    struct cudaPitchedPtr, pitchedDevPtr,
    int, value,
    struct cudaExtent, extent,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyAsync_entry,
  TP_ARGS(
    void *, dst,
    const void *, src,
    size_t, count,
    enum cudaMemcpyKind, kind,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, count, count)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyAsync_exit,
  TP_ARGS(
    void *, dst,
    const void *, src,
    size_t, count,
    enum cudaMemcpyKind, kind,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyToSymbolAsync_entry,
  TP_ARGS(
    const void *, symbol,
    const void *, src,
    size_t, count,
    size_t, offset,
    enum cudaMemcpyKind, kind,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, count, count)
    ctf_integer(size_t, offset, offset)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyToSymbolAsync_exit,
  TP_ARGS(
    const void *, symbol,
    const void *, src,
    size_t, count,
    size_t, offset,
    enum cudaMemcpyKind, kind,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyFromSymbolAsync_entry,
  TP_ARGS(
    void *, dst,
    const void *, symbol,
    size_t, count,
    size_t, offset,
    enum cudaMemcpyKind, kind,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
    ctf_integer(size_t, count, count)
    ctf_integer(size_t, offset, offset)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyFromSymbolAsync_exit,
  TP_ARGS(
    void *, dst,
    const void *, symbol,
    size_t, count,
    size_t, offset,
    enum cudaMemcpyKind, kind,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy2DAsync_entry,
  TP_ARGS(
    void *, dst,
    size_t, dpitch,
    const void *, src,
    size_t, spitch,
    size_t, width,
    size_t, height,
    enum cudaMemcpyKind, kind,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, dpitch, dpitch)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, spitch, spitch)
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy2DAsync_exit,
  TP_ARGS(
    void *, dst,
    size_t, dpitch,
    const void *, src,
    size_t, spitch,
    size_t, width,
    size_t, height,
    enum cudaMemcpyKind, kind,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyToArrayAsync_entry,
  TP_ARGS(
    cudaArray_t, dst,
    size_t, wOffset,
    size_t, hOffset,
    const void *, src,
    size_t, count,
    enum cudaMemcpyKind, kind,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, wOffset, wOffset)
    ctf_integer(size_t, hOffset, hOffset)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, count, count)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyToArrayAsync_exit,
  TP_ARGS(
    cudaArray_t, dst,
    size_t, wOffset,
    size_t, hOffset,
    const void *, src,
    size_t, count,
    enum cudaMemcpyKind, kind,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy2DToArrayAsync_entry,
  TP_ARGS(
    cudaArray_t, dst,
    size_t, wOffset,
    size_t, hOffset,
    const void *, src,
    size_t, spitch,
    size_t, width,
    size_t, height,
    enum cudaMemcpyKind, kind,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, wOffset, wOffset)
    ctf_integer(size_t, hOffset, hOffset)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, spitch, spitch)
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy2DToArrayAsync_exit,
  TP_ARGS(
    cudaArray_t, dst,
    size_t, wOffset,
    size_t, hOffset,
    const void *, src,
    size_t, spitch,
    size_t, width,
    size_t, height,
    enum cudaMemcpyKind, kind,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyFromArrayAsync_entry,
  TP_ARGS(
    void *, dst,
    cudaArray_const_t, src,
    size_t, wOffset,
    size_t, hOffset,
    size_t, count,
    enum cudaMemcpyKind, kind,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, wOffset, wOffset)
    ctf_integer(size_t, hOffset, hOffset)
    ctf_integer(size_t, count, count)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpyFromArrayAsync_exit,
  TP_ARGS(
    void *, dst,
    cudaArray_const_t, src,
    size_t, wOffset,
    size_t, hOffset,
    size_t, count,
    enum cudaMemcpyKind, kind,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy2DFromArrayAsync_entry,
  TP_ARGS(
    void *, dst,
    size_t, dpitch,
    cudaArray_const_t, src,
    size_t, wOffset,
    size_t, hOffset,
    size_t, width,
    size_t, height,
    enum cudaMemcpyKind, kind,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer(size_t, dpitch, dpitch)
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
    ctf_integer(size_t, wOffset, wOffset)
    ctf_integer(size_t, hOffset, hOffset)
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
    ctf_integer(enum cudaMemcpyKind, kind, kind)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy2DFromArrayAsync_exit,
  TP_ARGS(
    void *, dst,
    size_t, dpitch,
    cudaArray_const_t, src,
    size_t, wOffset,
    size_t, hOffset,
    size_t, width,
    size_t, height,
    enum cudaMemcpyKind, kind,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy3DAsync_entry,
  TP_ARGS(
    const struct cudaMemcpy3DParms *, p,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy3DAsync_exit,
  TP_ARGS(
    const struct cudaMemcpy3DParms *, p,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy3DPeerAsync_entry,
  TP_ARGS(
    const struct cudaMemcpy3DPeerParms *, p,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemcpy3DPeerAsync_exit,
  TP_ARGS(
    const struct cudaMemcpy3DPeerParms *, p,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemsetAsync_entry,
  TP_ARGS(
    void *, devPtr,
    int, value,
    size_t, count,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
    ctf_integer(int, value, value)
    ctf_integer(size_t, count, count)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemsetAsync_exit,
  TP_ARGS(
    void *, devPtr,
    int, value,
    size_t, count,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemset2DAsync_entry,
  TP_ARGS(
    void *, devPtr,
    size_t, pitch,
    int, value,
    size_t, width,
    size_t, height,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
    ctf_integer(size_t, pitch, pitch)
    ctf_integer(int, value, value)
    ctf_integer(size_t, width, width)
    ctf_integer(size_t, height, height)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemset2DAsync_exit,
  TP_ARGS(
    void *, devPtr,
    size_t, pitch,
    int, value,
    size_t, width,
    size_t, height,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemset3DAsync_entry,
  TP_ARGS(
    struct cudaPitchedPtr, pitchedDevPtr,
    int, value,
    struct cudaExtent, extent,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_array_text(uint8_t, pitchedDevPtr, &pitchedDevPtr, sizeof(struct cudaPitchedPtr))
    ctf_integer(int, value, value)
    ctf_array_text(uint8_t, extent, &extent, sizeof(struct cudaExtent))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemset3DAsync_exit,
  TP_ARGS(
    struct cudaPitchedPtr, pitchedDevPtr,
    int, value,
    struct cudaExtent, extent,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamQuery_entry,
  TP_ARGS(
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamQuery_exit,
  TP_ARGS(
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamGetDevice_entry,
  TP_ARGS(
    cudaStream_t, hStream,
    int *, device
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, device, (uintptr_t)(device))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamGetDevice_exit,
  TP_ARGS(
    cudaStream_t, hStream,
    int *, device,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamGetFlags_entry,
  TP_ARGS(
    cudaStream_t, hStream,
    unsigned int *, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, flags, (uintptr_t)(flags))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamGetFlags_exit,
  TP_ARGS(
    cudaStream_t, hStream,
    unsigned int *, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamGetId_entry,
  TP_ARGS(
    cudaStream_t, hStream,
    unsigned long long int *, streamId
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, streamId, (uintptr_t)(streamId))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamGetId_exit,
  TP_ARGS(
    cudaStream_t, hStream,
    unsigned long long int *, streamId,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamGetPriority_entry,
  TP_ARGS(
    cudaStream_t, hStream,
    int *, priority
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, priority, (uintptr_t)(priority))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamGetPriority_exit,
  TP_ARGS(
    cudaStream_t, hStream,
    int *, priority,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaEventRecord_entry,
  TP_ARGS(
    cudaEvent_t, event,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaEventRecord_exit,
  TP_ARGS(
    cudaEvent_t, event,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaEventRecordWithFlags_entry,
  TP_ARGS(
    cudaEvent_t, event,
    cudaStream_t, stream,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaEventRecordWithFlags_exit,
  TP_ARGS(
    cudaEvent_t, event,
    cudaStream_t, stream,
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamWaitEvent_entry,
  TP_ARGS(
    cudaStream_t, stream,
    cudaEvent_t, event,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamWaitEvent_exit,
  TP_ARGS(
    cudaStream_t, stream,
    cudaEvent_t, event,
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamAddCallback_entry,
  TP_ARGS(
    cudaStream_t, stream,
    cudaStreamCallback_t, callback,
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
  lttng_ust_cudart,
  cudaStreamAddCallback_exit,
  TP_ARGS(
    cudaStream_t, stream,
    cudaStreamCallback_t, callback,
    void *, userData,
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamAttachMemAsync_entry,
  TP_ARGS(
    cudaStream_t, stream,
    void *, devPtr,
    size_t, length,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
    ctf_integer(size_t, length, length)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamAttachMemAsync_exit,
  TP_ARGS(
    cudaStream_t, stream,
    void *, devPtr,
    size_t, length,
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamSynchronize_entry,
  TP_ARGS(
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamSynchronize_exit,
  TP_ARGS(
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLaunchKernel_entry,
  TP_ARGS(
    const void *, func,
    dim3, gridDim,
    dim3, blockDim,
    void **, args,
    size_t, sharedMem,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, func, (uintptr_t)(func))
    ctf_array_text(uint8_t, gridDim, &gridDim, sizeof(dim3))
    ctf_array_text(uint8_t, blockDim, &blockDim, sizeof(dim3))
    ctf_integer_hex(uintptr_t, args, (uintptr_t)(args))
    ctf_integer(size_t, sharedMem, sharedMem)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLaunchKernel_exit,
  TP_ARGS(
    const void *, func,
    dim3, gridDim,
    dim3, blockDim,
    void **, args,
    size_t, sharedMem,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLaunchKernelExC_entry,
  TP_ARGS(
    const cudaLaunchConfig_t *, config,
    const void *, func,
    void **, args
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, config, (uintptr_t)(config))
    ctf_integer_hex(uintptr_t, func, (uintptr_t)(func))
    ctf_integer_hex(uintptr_t, args, (uintptr_t)(args))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLaunchKernelExC_exit,
  TP_ARGS(
    const cudaLaunchConfig_t *, config,
    const void *, func,
    void **, args,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLaunchCooperativeKernel_entry,
  TP_ARGS(
    const void *, func,
    dim3, gridDim,
    dim3, blockDim,
    void **, args,
    size_t, sharedMem,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, func, (uintptr_t)(func))
    ctf_array_text(uint8_t, gridDim, &gridDim, sizeof(dim3))
    ctf_array_text(uint8_t, blockDim, &blockDim, sizeof(dim3))
    ctf_integer_hex(uintptr_t, args, (uintptr_t)(args))
    ctf_integer(size_t, sharedMem, sharedMem)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLaunchCooperativeKernel_exit,
  TP_ARGS(
    const void *, func,
    dim3, gridDim,
    dim3, blockDim,
    void **, args,
    size_t, sharedMem,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLaunchHostFunc_entry,
  TP_ARGS(
    cudaStream_t, stream,
    cudaHostFn_t, fn,
    void *, userData
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, fn, (uintptr_t)(fn))
    ctf_integer_hex(uintptr_t, userData, (uintptr_t)(userData))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaLaunchHostFunc_exit,
  TP_ARGS(
    cudaStream_t, stream,
    cudaHostFn_t, fn,
    void *, userData,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemPrefetchAsync_entry,
  TP_ARGS(
    const void *, devPtr,
    size_t, count,
    struct cudaMemLocation, location,
    unsigned int, flags,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
    ctf_integer(size_t, count, count)
    ctf_array_text(uint8_t, location, &location, sizeof(struct cudaMemLocation))
    ctf_integer(unsigned int, flags, flags)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemPrefetchAsync_exit,
  TP_ARGS(
    const void *, devPtr,
    size_t, count,
    struct cudaMemLocation, location,
    unsigned int, flags,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemPrefetchBatchAsync_entry,
  TP_ARGS(
    void **, dptrs,
    size_t *, sizes,
    size_t, count,
    struct cudaMemLocation *, prefetchLocs,
    size_t *, prefetchLocIdxs,
    size_t, numPrefetchLocs,
    unsigned long long int, flags,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dptrs, (uintptr_t)(dptrs))
    ctf_integer_hex(uintptr_t, sizes, (uintptr_t)(sizes))
    ctf_integer(size_t, count, count)
    ctf_integer_hex(uintptr_t, prefetchLocs, (uintptr_t)(prefetchLocs))
    ctf_integer_hex(uintptr_t, prefetchLocIdxs, (uintptr_t)(prefetchLocIdxs))
    ctf_integer(size_t, numPrefetchLocs, numPrefetchLocs)
    ctf_integer(unsigned long long int, flags, flags)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemPrefetchBatchAsync_exit,
  TP_ARGS(
    void **, dptrs,
    size_t *, sizes,
    size_t, count,
    struct cudaMemLocation *, prefetchLocs,
    size_t *, prefetchLocIdxs,
    size_t, numPrefetchLocs,
    unsigned long long int, flags,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemDiscardBatchAsync_entry,
  TP_ARGS(
    void **, dptrs,
    size_t *, sizes,
    size_t, count,
    unsigned long long int, flags,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dptrs, (uintptr_t)(dptrs))
    ctf_integer_hex(uintptr_t, sizes, (uintptr_t)(sizes))
    ctf_integer(size_t, count, count)
    ctf_integer(unsigned long long int, flags, flags)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemDiscardBatchAsync_exit,
  TP_ARGS(
    void **, dptrs,
    size_t *, sizes,
    size_t, count,
    unsigned long long int, flags,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemDiscardAndPrefetchBatchAsync_entry,
  TP_ARGS(
    void **, dptrs,
    size_t *, sizes,
    size_t, count,
    struct cudaMemLocation *, prefetchLocs,
    size_t *, prefetchLocIdxs,
    size_t, numPrefetchLocs,
    unsigned long long int, flags,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dptrs, (uintptr_t)(dptrs))
    ctf_integer_hex(uintptr_t, sizes, (uintptr_t)(sizes))
    ctf_integer(size_t, count, count)
    ctf_integer_hex(uintptr_t, prefetchLocs, (uintptr_t)(prefetchLocs))
    ctf_integer_hex(uintptr_t, prefetchLocIdxs, (uintptr_t)(prefetchLocIdxs))
    ctf_integer(size_t, numPrefetchLocs, numPrefetchLocs)
    ctf_integer(unsigned long long int, flags, flags)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMemDiscardAndPrefetchBatchAsync_exit,
  TP_ARGS(
    void **, dptrs,
    size_t *, sizes,
    size_t, count,
    struct cudaMemLocation *, prefetchLocs,
    size_t *, prefetchLocIdxs,
    size_t, numPrefetchLocs,
    unsigned long long int, flags,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaSignalExternalSemaphoresAsync_entry,
  TP_ARGS(
    const cudaExternalSemaphore_t *, extSemArray,
    const struct cudaExternalSemaphoreSignalParams *, paramsArray,
    unsigned int, numExtSems,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, extSemArray, (uintptr_t)(extSemArray))
    ctf_integer_hex(uintptr_t, paramsArray, (uintptr_t)(paramsArray))
    ctf_integer(unsigned int, numExtSems, numExtSems)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaSignalExternalSemaphoresAsync_exit,
  TP_ARGS(
    const cudaExternalSemaphore_t *, extSemArray,
    const struct cudaExternalSemaphoreSignalParams *, paramsArray,
    unsigned int, numExtSems,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaWaitExternalSemaphoresAsync_entry,
  TP_ARGS(
    const cudaExternalSemaphore_t *, extSemArray,
    const struct cudaExternalSemaphoreWaitParams *, paramsArray,
    unsigned int, numExtSems,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, extSemArray, (uintptr_t)(extSemArray))
    ctf_integer_hex(uintptr_t, paramsArray, (uintptr_t)(paramsArray))
    ctf_integer(unsigned int, numExtSems, numExtSems)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaWaitExternalSemaphoresAsync_exit,
  TP_ARGS(
    const cudaExternalSemaphore_t *, extSemArray,
    const struct cudaExternalSemaphoreWaitParams *, paramsArray,
    unsigned int, numExtSems,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphInstantiateWithParams_entry,
  TP_ARGS(
    cudaGraphExec_t *, pGraphExec,
    cudaGraph_t, graph,
    cudaGraphInstantiateParams *, instantiateParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pGraphExec, (uintptr_t)(pGraphExec))
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, instantiateParams, (uintptr_t)(instantiateParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphInstantiateWithParams_exit,
  TP_ARGS(
    cudaGraphExec_t *, pGraphExec,
    cudaGraph_t, graph,
    cudaGraphInstantiateParams *, instantiateParams,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphUpload_entry,
  TP_ARGS(
    cudaGraphExec_t, graphExec,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, graphExec, (uintptr_t)(graphExec))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphUpload_exit,
  TP_ARGS(
    cudaGraphExec_t, graphExec,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphLaunch_entry,
  TP_ARGS(
    cudaGraphExec_t, graphExec,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, graphExec, (uintptr_t)(graphExec))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphLaunch_exit,
  TP_ARGS(
    cudaGraphExec_t, graphExec,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamBeginCapture_entry,
  TP_ARGS(
    cudaStream_t, stream,
    enum cudaStreamCaptureMode, mode
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer(enum cudaStreamCaptureMode, mode, mode)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamBeginCapture_exit,
  TP_ARGS(
    cudaStream_t, stream,
    enum cudaStreamCaptureMode, mode,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamBeginCaptureToGraph_entry,
  TP_ARGS(
    cudaStream_t, stream,
    cudaGraph_t, graph,
    const cudaGraphNode_t *, dependencies,
    const cudaGraphEdgeData *, dependencyData,
    size_t, numDependencies,
    enum cudaStreamCaptureMode, mode
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, dependencies, (uintptr_t)(dependencies))
    ctf_integer_hex(uintptr_t, dependencyData, (uintptr_t)(dependencyData))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer(enum cudaStreamCaptureMode, mode, mode)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamBeginCaptureToGraph_exit,
  TP_ARGS(
    cudaStream_t, stream,
    cudaGraph_t, graph,
    const cudaGraphNode_t *, dependencies,
    const cudaGraphEdgeData *, dependencyData,
    size_t, numDependencies,
    enum cudaStreamCaptureMode, mode,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamEndCapture_entry,
  TP_ARGS(
    cudaStream_t, stream,
    cudaGraph_t *, pGraph
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, pGraph, (uintptr_t)(pGraph))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamEndCapture_exit,
  TP_ARGS(
    cudaStream_t, stream,
    cudaGraph_t *, pGraph,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamIsCapturing_entry,
  TP_ARGS(
    cudaStream_t, stream,
    enum cudaStreamCaptureStatus *, pCaptureStatus
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, pCaptureStatus, (uintptr_t)(pCaptureStatus))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamIsCapturing_exit,
  TP_ARGS(
    cudaStream_t, stream,
    enum cudaStreamCaptureStatus *, pCaptureStatus,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamGetCaptureInfo_entry,
  TP_ARGS(
    cudaStream_t, stream,
    enum cudaStreamCaptureStatus *, captureStatus_out,
    unsigned long long int *, id_out,
    cudaGraph_t *, graph_out,
    const cudaGraphNode_t **, dependencies_out,
    const cudaGraphEdgeData **, edgeData_out,
    size_t *, numDependencies_out
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, captureStatus_out, (uintptr_t)(captureStatus_out))
    ctf_integer_hex(uintptr_t, id_out, (uintptr_t)(id_out))
    ctf_integer_hex(uintptr_t, graph_out, (uintptr_t)(graph_out))
    ctf_integer_hex(uintptr_t, dependencies_out, (uintptr_t)(dependencies_out))
    ctf_integer_hex(uintptr_t, edgeData_out, (uintptr_t)(edgeData_out))
    ctf_integer_hex(uintptr_t, numDependencies_out, (uintptr_t)(numDependencies_out))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamGetCaptureInfo_exit,
  TP_ARGS(
    cudaStream_t, stream,
    enum cudaStreamCaptureStatus *, captureStatus_out,
    unsigned long long int *, id_out,
    cudaGraph_t *, graph_out,
    const cudaGraphNode_t **, dependencies_out,
    const cudaGraphEdgeData **, edgeData_out,
    size_t *, numDependencies_out,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamUpdateCaptureDependencies_entry,
  TP_ARGS(
    cudaStream_t, stream,
    cudaGraphNode_t *, dependencies,
    const cudaGraphEdgeData *, dependencyData,
    size_t, numDependencies,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(uintptr_t, dependencies, (uintptr_t)(dependencies))
    ctf_integer_hex(uintptr_t, dependencyData, (uintptr_t)(dependencyData))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamUpdateCaptureDependencies_exit,
  TP_ARGS(
    cudaStream_t, stream,
    cudaGraphNode_t *, dependencies,
    const cudaGraphEdgeData *, dependencyData,
    size_t, numDependencies,
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamCopyAttributes_entry,
  TP_ARGS(
    cudaStream_t, dstStream,
    cudaStream_t, srcStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dstStream, (uintptr_t)(dstStream))
    ctf_integer_hex(uintptr_t, srcStream, (uintptr_t)(srcStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamCopyAttributes_exit,
  TP_ARGS(
    cudaStream_t, dstStream,
    cudaStream_t, srcStream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamGetAttribute_entry,
  TP_ARGS(
    cudaStream_t, stream,
    cudaLaunchAttributeID, attr,
    cudaLaunchAttributeValue *, value
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer(int32_t, attr, attr)
    ctf_integer_hex(uintptr_t, value, (uintptr_t)(value))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamGetAttribute_exit,
  TP_ARGS(
    cudaStream_t, stream,
    cudaLaunchAttributeID, attr,
    cudaLaunchAttributeValue *, value,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamSetAttribute_entry,
  TP_ARGS(
    cudaStream_t, stream,
    cudaLaunchAttributeID, attr,
    const cudaLaunchAttributeValue *, param
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer(int32_t, attr, attr)
    ctf_integer_hex(uintptr_t, param, (uintptr_t)(param))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaStreamSetAttribute_exit,
  TP_ARGS(
    cudaStream_t, stream,
    cudaLaunchAttributeID, attr,
    const cudaLaunchAttributeValue *, param,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMallocAsync_entry,
  TP_ARGS(
    void **, devPtr,
    size_t, size,
    cudaStream_t, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
    ctf_integer(size_t, size, size)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMallocAsync_exit,
  TP_ARGS(
    void **, devPtr,
    size_t, size,
    cudaStream_t, hStream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaFreeAsync_entry,
  TP_ARGS(
    void *, devPtr,
    cudaStream_t, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaFreeAsync_exit,
  TP_ARGS(
    void *, devPtr,
    cudaStream_t, hStream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMallocFromPoolAsync_entry,
  TP_ARGS(
    void **, ptr,
    size_t, size,
    cudaMemPool_t, memPool,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)(ptr))
    ctf_integer(size_t, size, size)
    ctf_integer_hex(uintptr_t, memPool, (uintptr_t)(memPool))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaMallocFromPoolAsync_exit,
  TP_ARGS(
    void **, ptr,
    size_t, size,
    cudaMemPool_t, memPool,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetDriverEntryPoint_entry,
  TP_ARGS(
    const char *, symbol,
    void **, funcPtr,
    unsigned long long int, flags,
    enum cudaDriverEntryPointQueryResult *, driverStatus
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
    ctf_integer_hex(uintptr_t, funcPtr, (uintptr_t)(funcPtr))
    ctf_integer(unsigned long long int, flags, flags)
    ctf_integer_hex(uintptr_t, driverStatus, (uintptr_t)(driverStatus))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetDriverEntryPoint_exit,
  TP_ARGS(
    const char *, symbol,
    void **, funcPtr,
    unsigned long long int, flags,
    enum cudaDriverEntryPointQueryResult *, driverStatus,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetDriverEntryPointByVersion_entry,
  TP_ARGS(
    const char *, symbol,
    void **, funcPtr,
    unsigned int, cudaVersion,
    unsigned long long int, flags,
    enum cudaDriverEntryPointQueryResult *, driverStatus
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
    ctf_integer_hex(uintptr_t, funcPtr, (uintptr_t)(funcPtr))
    ctf_integer(unsigned int, cudaVersion, cudaVersion)
    ctf_integer(unsigned long long int, flags, flags)
    ctf_integer_hex(uintptr_t, driverStatus, (uintptr_t)(driverStatus))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGetDriverEntryPointByVersion_exit,
  TP_ARGS(
    const char *, symbol,
    void **, funcPtr,
    unsigned int, cudaVersion,
    unsigned long long int, flags,
    enum cudaDriverEntryPointQueryResult *, driverStatus,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  __cudaPopCallConfiguration_entry,
  TP_ARGS(
    dim3 *, gridDim,
    dim3 *, blockDim,
    size_t *, sharedMem,
    cudaStream_t *, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, gridDim, (uintptr_t)(gridDim))
    ctf_integer_hex(uintptr_t, blockDim, (uintptr_t)(blockDim))
    ctf_integer_hex(uintptr_t, sharedMem, (uintptr_t)(sharedMem))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  __cudaPopCallConfiguration_exit,
  TP_ARGS(
    dim3 *, gridDim,
    dim3 *, blockDim,
    size_t *, sharedMem,
    cudaStream_t *, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  __cudaPushCallConfiguration_entry,
  TP_ARGS(
    dim3, gridDim,
    dim3, blockDim,
    size_t, sharedMem,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_array_text(uint8_t, gridDim, &gridDim, sizeof(dim3))
    ctf_array_text(uint8_t, blockDim, &blockDim, sizeof(dim3))
    ctf_integer(size_t, sharedMem, sharedMem)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  __cudaPushCallConfiguration_exit,
  TP_ARGS(
    dim3, gridDim,
    dim3, blockDim,
    size_t, sharedMem,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  __cudaRegisterFatBinary_entry,
  TP_ARGS(
    void *, fatCubin
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, fatCubin, (uintptr_t)(fatCubin))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  __cudaRegisterFatBinary_exit,
  TP_ARGS(
    void *, fatCubin,
    void **, cudaResult
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, cudaResult, (uintptr_t)(cudaResult))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  __cudaRegisterFatBinaryEnd_entry,
  TP_ARGS(
    void **, fatCubinHandle
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, fatCubinHandle, (uintptr_t)(fatCubinHandle))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  __cudaRegisterFatBinaryEnd_exit,
  TP_ARGS(
    void **, fatCubinHandle
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  __cudaUnregisterFatBinary_entry,
  TP_ARGS(
    void **, fatCubinHandle
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, fatCubinHandle, (uintptr_t)(fatCubinHandle))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  __cudaUnregisterFatBinary_exit,
  TP_ARGS(
    void **, fatCubinHandle
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  __cudaGetKernel_entry,
  TP_ARGS(
    void **, pKernelRet,
    void *, pFun
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pKernelRet, (uintptr_t)(pKernelRet))
    ctf_integer_hex(uintptr_t, pFun, (uintptr_t)(pFun))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  __cudaGetKernel_exit,
  TP_ARGS(
    void **, pKernelRet,
    void *, pFun,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  __cudaLaunchKernel_ptsz_entry,
  TP_ARGS(
    const void *, func,
    dim3, gridDim,
    dim3, blockDim,
    void **, args,
    size_t, sharedMem,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, func, (uintptr_t)(func))
    ctf_array_text(uint8_t, gridDim, &gridDim, sizeof(dim3))
    ctf_array_text(uint8_t, blockDim, &blockDim, sizeof(dim3))
    ctf_integer_hex(uintptr_t, args, (uintptr_t)(args))
    ctf_integer(size_t, sharedMem, sharedMem)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  __cudaLaunchKernel_ptsz_exit,
  TP_ARGS(
    const void *, func,
    dim3, gridDim,
    dim3, blockDim,
    void **, args,
    size_t, sharedMem,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  __cudaLaunchKernel_entry,
  TP_ARGS(
    const void *, func,
    dim3, gridDim,
    dim3, blockDim,
    void **, args,
    size_t, sharedMem,
    cudaStream_t, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, func, (uintptr_t)(func))
    ctf_array_text(uint8_t, gridDim, &gridDim, sizeof(dim3))
    ctf_array_text(uint8_t, blockDim, &blockDim, sizeof(dim3))
    ctf_integer_hex(uintptr_t, args, (uintptr_t)(args))
    ctf_integer(size_t, sharedMem, sharedMem)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  __cudaLaunchKernel_exit,
  TP_ARGS(
    const void *, func,
    dim3, gridDim,
    dim3, blockDim,
    void **, args,
    size_t, sharedMem,
    cudaStream_t, stream,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  __cudaRegisterHostVar_entry,
  TP_ARGS(
    void **, fatCubinHandle,
    const char *, deviceName,
    char *, hostVar,
    size_t, size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, fatCubinHandle, (uintptr_t)(fatCubinHandle))
    ctf_integer_hex(uintptr_t, deviceName, (uintptr_t)(deviceName))
    ctf_integer_hex(uintptr_t, hostVar, (uintptr_t)(hostVar))
    ctf_integer(size_t, size, size)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  __cudaRegisterHostVar_exit,
  TP_ARGS(
    void **, fatCubinHandle,
    const char *, deviceName,
    char *, hostVar,
    size_t, size
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  __cudaRegisterVar_entry,
  TP_ARGS(
    void **, fatCubinHandle,
    char *, hostVar,
    char *, deviceAddress,
    const char *, deviceName,
    int, ext,
    size_t, size,
    int, constant,
    int, global
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, fatCubinHandle, (uintptr_t)(fatCubinHandle))
    ctf_integer_hex(uintptr_t, hostVar, (uintptr_t)(hostVar))
    ctf_integer_hex(uintptr_t, deviceAddress, (uintptr_t)(deviceAddress))
    ctf_integer_hex(uintptr_t, deviceName, (uintptr_t)(deviceName))
    ctf_integer(int, ext, ext)
    ctf_integer(size_t, size, size)
    ctf_integer(int, constant, constant)
    ctf_integer(int, global, global)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  __cudaRegisterVar_exit,
  TP_ARGS(
    void **, fatCubinHandle,
    char *, hostVar,
    char *, deviceAddress,
    const char *, deviceName,
    int, ext,
    size_t, size,
    int, constant,
    int, global
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  __cudaRegisterManagedVar_entry,
  TP_ARGS(
    void **, fatCubinHandle,
    void **, hostVarPtrAddress,
    char *, deviceAddress,
    const char *, deviceName,
    int, ext,
    size_t, size,
    int, constant,
    int, global
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, fatCubinHandle, (uintptr_t)(fatCubinHandle))
    ctf_integer_hex(uintptr_t, hostVarPtrAddress, (uintptr_t)(hostVarPtrAddress))
    ctf_integer_hex(uintptr_t, deviceAddress, (uintptr_t)(deviceAddress))
    ctf_integer_hex(uintptr_t, deviceName, (uintptr_t)(deviceName))
    ctf_integer(int, ext, ext)
    ctf_integer(size_t, size, size)
    ctf_integer(int, constant, constant)
    ctf_integer(int, global, global)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  __cudaRegisterManagedVar_exit,
  TP_ARGS(
    void **, fatCubinHandle,
    void **, hostVarPtrAddress,
    char *, deviceAddress,
    const char *, deviceName,
    int, ext,
    size_t, size,
    int, constant,
    int, global
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  __cudaInitModule_entry,
  TP_ARGS(
    void **, fatCubinHandle
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, fatCubinHandle, (uintptr_t)(fatCubinHandle))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  __cudaInitModule_exit,
  TP_ARGS(
    void **, fatCubinHandle,
    char, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(char, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  __cudaRegisterFunction_entry,
  TP_ARGS(
    void **, fatCubinHandle,
    const char *, hostFun,
    char *, deviceFun,
    const char *, deviceName,
    int, thread_limit,
    uint3 *, tid,
    uint3 *, bid,
    dim3 *, bDim,
    dim3 *, gDim,
    int *, wSize
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, fatCubinHandle, (uintptr_t)(fatCubinHandle))
    ctf_integer_hex(uintptr_t, hostFun, (uintptr_t)(hostFun))
    ctf_integer_hex(uintptr_t, deviceFun, (uintptr_t)(deviceFun))
    ctf_integer_hex(uintptr_t, deviceName, (uintptr_t)(deviceName))
    ctf_integer(int, thread_limit, thread_limit)
    ctf_integer_hex(uintptr_t, tid, (uintptr_t)(tid))
    ctf_integer_hex(uintptr_t, bid, (uintptr_t)(bid))
    ctf_integer_hex(uintptr_t, bDim, (uintptr_t)(bDim))
    ctf_integer_hex(uintptr_t, gDim, (uintptr_t)(gDim))
    ctf_integer_hex(uintptr_t, wSize, (uintptr_t)(wSize))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  __cudaRegisterFunction_exit,
  TP_ARGS(
    void **, fatCubinHandle,
    const char *, hostFun,
    char *, deviceFun,
    const char *, deviceName,
    int, thread_limit,
    uint3 *, tid,
    uint3 *, bid,
    dim3 *, bDim,
    dim3 *, gDim,
    int *, wSize
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  __cudaRegisterUnifiedTable_entry,
  TP_ARGS(
    void *, table,
    void *, ptr1,
    void *, ptr2,
    void *, ptr3,
    void *, ptr4
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, table, (uintptr_t)(table))
    ctf_integer_hex(uintptr_t, ptr1, (uintptr_t)(ptr1))
    ctf_integer_hex(uintptr_t, ptr2, (uintptr_t)(ptr2))
    ctf_integer_hex(uintptr_t, ptr3, (uintptr_t)(ptr3))
    ctf_integer_hex(uintptr_t, ptr4, (uintptr_t)(ptr4))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  __cudaRegisterUnifiedTable_exit,
  TP_ARGS(
    void *, table,
    void *, ptr1,
    void *, ptr2,
    void *, ptr3,
    void *, ptr4
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaVDPAUGetDevice_entry,
  TP_ARGS(
    int *, device,
    VdpDevice, vdpDevice,
    VdpGetProcAddress *, vdpGetProcAddress
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, device, (uintptr_t)(device))
    ctf_integer(VdpDevice, vdpDevice, vdpDevice)
    ctf_integer_hex(uintptr_t, vdpGetProcAddress, (uintptr_t)(vdpGetProcAddress))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaVDPAUGetDevice_exit,
  TP_ARGS(
    int *, device,
    VdpDevice, vdpDevice,
    VdpGetProcAddress *, vdpGetProcAddress,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaVDPAUSetVDPAUDevice_entry,
  TP_ARGS(
    int, device,
    VdpDevice, vdpDevice,
    VdpGetProcAddress *, vdpGetProcAddress
  ),
  TP_FIELDS(
    ctf_integer(int, device, device)
    ctf_integer(VdpDevice, vdpDevice, vdpDevice)
    ctf_integer_hex(uintptr_t, vdpGetProcAddress, (uintptr_t)(vdpGetProcAddress))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaVDPAUSetVDPAUDevice_exit,
  TP_ARGS(
    int, device,
    VdpDevice, vdpDevice,
    VdpGetProcAddress *, vdpGetProcAddress,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphicsVDPAURegisterVideoSurface_entry,
  TP_ARGS(
    struct cudaGraphicsResource **, resource,
    VdpVideoSurface, vdpSurface,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, resource, (uintptr_t)(resource))
    ctf_integer(VdpVideoSurface, vdpSurface, vdpSurface)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphicsVDPAURegisterVideoSurface_exit,
  TP_ARGS(
    struct cudaGraphicsResource **, resource,
    VdpVideoSurface, vdpSurface,
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphicsVDPAURegisterOutputSurface_entry,
  TP_ARGS(
    struct cudaGraphicsResource **, resource,
    VdpOutputSurface, vdpSurface,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, resource, (uintptr_t)(resource))
    ctf_integer(VdpOutputSurface, vdpSurface, vdpSurface)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaGraphicsVDPAURegisterOutputSurface_exit,
  TP_ARGS(
    struct cudaGraphicsResource **, resource,
    VdpOutputSurface, vdpSurface,
    unsigned int, flags,
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaProfilerStart_entry,
  TP_ARGS(
    void
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaProfilerStart_exit,
  TP_ARGS(
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaProfilerStop_entry,
  TP_ARGS(
    void
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cudart,
  cudaProfilerStop_exit,
  TP_ARGS(
    cudaError_t, cudaResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cudaResult, cudaResult)
  )
)


#endif /* CUDART_TRACEPOINTS_H */

#include <lttng/tracepoint-event.h>
