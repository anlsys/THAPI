
#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER lttng_ust_cuda

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "./cuda_tracepoints.h"

#if !defined(CUDA_TRACEPOINTS_H) || defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define CUDA_TRACEPOINTS_H

#include <lttng/tracepoint.h>

#include "lttng/tracepoint_gen.h"
#include <cuda.h.include>
TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGetErrorString_entry,
  TP_ARGS(
    CUresult, error,
    const char **, pStr
  ),
  TP_FIELDS(
    ctf_integer(int32_t, error, error)
    ctf_integer_hex(uintptr_t, pStr, (uintptr_t)(pStr))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGetErrorString_exit,
  TP_ARGS(
    CUresult, error,
    const char **, pStr,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pStr_val, (uintptr_t)((pStr ? *pStr : 0)))
    ctf_string(pStr_val_val, *pStr)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGetErrorName_entry,
  TP_ARGS(
    CUresult, error,
    const char **, pStr
  ),
  TP_FIELDS(
    ctf_integer(int32_t, error, error)
    ctf_integer_hex(uintptr_t, pStr, (uintptr_t)(pStr))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGetErrorName_exit,
  TP_ARGS(
    CUresult, error,
    const char **, pStr,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pStr_val, (uintptr_t)((pStr ? *pStr : 0)))
    ctf_string(pStr_val_val, *pStr)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuInit_entry,
  TP_ARGS(
    unsigned int, Flags
  ),
  TP_FIELDS(
    ctf_integer(unsigned int, Flags, Flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuInit_exit,
  TP_ARGS(
    unsigned int, Flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDriverGetVersion_entry,
  TP_ARGS(
    int *, driverVersion
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, driverVersion, (uintptr_t)(driverVersion))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDriverGetVersion_exit,
  TP_ARGS(
    int *, driverVersion,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int, driverVersion_val, (driverVersion ? *driverVersion : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGet_entry,
  TP_ARGS(
    CUdevice *, device,
    int, ordinal
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, device, (uintptr_t)(device))
    ctf_integer(int, ordinal, ordinal)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGet_exit,
  TP_ARGS(
    CUdevice *, device,
    int, ordinal,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(CUdevice, device_val, (device ? *device : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetCount_entry,
  TP_ARGS(
    int *, count
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, count, (uintptr_t)(count))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetCount_exit,
  TP_ARGS(
    int *, count,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int, count_val, (count ? *count : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetName_entry,
  TP_ARGS(
    char *, name,
    int, len,
    CUdevice, dev
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, name, (uintptr_t)(name))
    ctf_integer(int, len, len)
    ctf_integer(CUdevice, dev, dev)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetName_exit,
  TP_ARGS(
    char *, name,
    int, len,
    CUdevice, dev,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_string(name_val, name)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetUuid_v2_entry,
  TP_ARGS(
    CUuuid *, uuid,
    CUdevice, dev
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, uuid, (uintptr_t)(uuid))
    ctf_integer(CUdevice, dev, dev)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetUuid_v2_exit,
  TP_ARGS(
    CUuuid *, uuid,
    CUdevice, dev,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, uuid_val, uuid, size_t, (uuid ? sizeof(CUuuid) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetLuid_entry,
  TP_ARGS(
    char *, luid,
    unsigned int *, deviceNodeMask,
    CUdevice, dev
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, luid, (uintptr_t)(luid))
    ctf_integer_hex(uintptr_t, deviceNodeMask, (uintptr_t)(deviceNodeMask))
    ctf_integer(CUdevice, dev, dev)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetLuid_exit,
  TP_ARGS(
    char *, luid,
    unsigned int *, deviceNodeMask,
    CUdevice, dev,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_array_text(char, luid_vals, luid, 8)
    ctf_integer(unsigned int, deviceNodeMask_val, (deviceNodeMask ? *deviceNodeMask : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceTotalMem_v2_entry,
  TP_ARGS(
    size_t *, bytes,
    CUdevice, dev
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, bytes, (uintptr_t)(bytes))
    ctf_integer(CUdevice, dev, dev)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceTotalMem_v2_exit,
  TP_ARGS(
    size_t *, bytes,
    CUdevice, dev,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(size_t, bytes_val, (bytes ? *bytes : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetTexture1DLinearMaxWidth_entry,
  TP_ARGS(
    size_t *, maxWidthInElements,
    CUarray_format, format,
    unsigned int, numChannels,
    CUdevice, dev
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, maxWidthInElements, (uintptr_t)(maxWidthInElements))
    ctf_integer(int32_t, format, format)
    ctf_integer(unsigned int, numChannels, numChannels)
    ctf_integer(CUdevice, dev, dev)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetTexture1DLinearMaxWidth_exit,
  TP_ARGS(
    size_t *, maxWidthInElements,
    CUarray_format, format,
    unsigned int, numChannels,
    CUdevice, dev,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(size_t, maxWidthInElements_val, (maxWidthInElements ? *maxWidthInElements : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetAttribute_entry,
  TP_ARGS(
    int *, pi,
    CUdevice_attribute, attrib,
    CUdevice, dev
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pi, (uintptr_t)(pi))
    ctf_integer(int32_t, attrib, attrib)
    ctf_integer(CUdevice, dev, dev)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetAttribute_exit,
  TP_ARGS(
    int *, pi,
    CUdevice_attribute, attrib,
    CUdevice, dev,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int, pi_val, (pi ? *pi : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetHostAtomicCapabilities_entry,
  TP_ARGS(
    unsigned int *, capabilities,
    const CUatomicOperation *, operations,
    unsigned int, count,
    CUdevice, dev
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, capabilities, (uintptr_t)(capabilities))
    ctf_integer_hex(uintptr_t, operations, (uintptr_t)(operations))
    ctf_integer(unsigned int, count, count)
    ctf_integer(CUdevice, dev, dev)
    ctf_sequence(int32_t, operations_vals, operations, unsigned int, (operations ? count : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetHostAtomicCapabilities_exit,
  TP_ARGS(
    unsigned int *, capabilities,
    const CUatomicOperation *, operations,
    unsigned int, count,
    CUdevice, dev,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence(unsigned int, capabilities_vals, capabilities, unsigned int, (capabilities ? count : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetNvSciSyncAttributes_entry,
  TP_ARGS(
    void *, nvSciSyncAttrList,
    CUdevice, dev,
    int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, nvSciSyncAttrList, (uintptr_t)(nvSciSyncAttrList))
    ctf_integer(CUdevice, dev, dev)
    ctf_integer(int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetNvSciSyncAttributes_exit,
  TP_ARGS(
    void *, nvSciSyncAttrList,
    CUdevice, dev,
    int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceSetMemPool_entry,
  TP_ARGS(
    CUdevice, dev,
    CUmemoryPool, pool
  ),
  TP_FIELDS(
    ctf_integer(CUdevice, dev, dev)
    ctf_integer_hex(uintptr_t, pool, (uintptr_t)(pool))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceSetMemPool_exit,
  TP_ARGS(
    CUdevice, dev,
    CUmemoryPool, pool,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetMemPool_entry,
  TP_ARGS(
    CUmemoryPool *, pool,
    CUdevice, dev
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pool, (uintptr_t)(pool))
    ctf_integer(CUdevice, dev, dev)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetMemPool_exit,
  TP_ARGS(
    CUmemoryPool *, pool,
    CUdevice, dev,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pool_val, (uintptr_t)((pool ? *pool : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetDefaultMemPool_entry,
  TP_ARGS(
    CUmemoryPool *, pool_out,
    CUdevice, dev
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pool_out, (uintptr_t)(pool_out))
    ctf_integer(CUdevice, dev, dev)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetDefaultMemPool_exit,
  TP_ARGS(
    CUmemoryPool *, pool_out,
    CUdevice, dev,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pool_out_val, (uintptr_t)((pool_out ? *pool_out : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetExecAffinitySupport_entry,
  TP_ARGS(
    int *, pi,
    CUexecAffinityType, type,
    CUdevice, dev
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pi, (uintptr_t)(pi))
    ctf_integer(int32_t, type, type)
    ctf_integer(CUdevice, dev, dev)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetExecAffinitySupport_exit,
  TP_ARGS(
    int *, pi,
    CUexecAffinityType, type,
    CUdevice, dev,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int, pi_val, (pi ? *pi : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuFlushGPUDirectRDMAWrites_entry,
  TP_ARGS(
    CUflushGPUDirectRDMAWritesTarget, target,
    CUflushGPUDirectRDMAWritesScope, scope
  ),
  TP_FIELDS(
    ctf_integer(int32_t, target, target)
    ctf_integer(int32_t, scope, scope)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuFlushGPUDirectRDMAWrites_exit,
  TP_ARGS(
    CUflushGPUDirectRDMAWritesTarget, target,
    CUflushGPUDirectRDMAWritesScope, scope,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetProperties_entry,
  TP_ARGS(
    CUdevprop *, prop,
    CUdevice, dev
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, prop, (uintptr_t)(prop))
    ctf_integer(CUdevice, dev, dev)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetProperties_exit,
  TP_ARGS(
    CUdevprop *, prop,
    CUdevice, dev,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, prop_val, prop, size_t, (prop ? sizeof(CUdevprop) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceComputeCapability_entry,
  TP_ARGS(
    int *, major,
    int *, minor,
    CUdevice, dev
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, major, (uintptr_t)(major))
    ctf_integer_hex(uintptr_t, minor, (uintptr_t)(minor))
    ctf_integer(CUdevice, dev, dev)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceComputeCapability_exit,
  TP_ARGS(
    int *, major,
    int *, minor,
    CUdevice, dev,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int, major_val, (major ? *major : 0))
    ctf_integer(int, minor_val, (minor ? *minor : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDevicePrimaryCtxRetain_entry,
  TP_ARGS(
    CUcontext *, pctx,
    CUdevice, dev
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pctx, (uintptr_t)(pctx))
    ctf_integer(CUdevice, dev, dev)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDevicePrimaryCtxRetain_exit,
  TP_ARGS(
    CUcontext *, pctx,
    CUdevice, dev,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pctx_val, (uintptr_t)((pctx ? *pctx : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDevicePrimaryCtxRelease_v2_entry,
  TP_ARGS(
    CUdevice, dev
  ),
  TP_FIELDS(
    ctf_integer(CUdevice, dev, dev)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDevicePrimaryCtxRelease_v2_exit,
  TP_ARGS(
    CUdevice, dev,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDevicePrimaryCtxSetFlags_v2_entry,
  TP_ARGS(
    CUdevice, dev,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer(CUdevice, dev, dev)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDevicePrimaryCtxSetFlags_v2_exit,
  TP_ARGS(
    CUdevice, dev,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDevicePrimaryCtxGetState_entry,
  TP_ARGS(
    CUdevice, dev,
    unsigned int *, flags,
    int *, active
  ),
  TP_FIELDS(
    ctf_integer(CUdevice, dev, dev)
    ctf_integer_hex(uintptr_t, flags, (uintptr_t)(flags))
    ctf_integer_hex(uintptr_t, active, (uintptr_t)(active))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDevicePrimaryCtxGetState_exit,
  TP_ARGS(
    CUdevice, dev,
    unsigned int *, flags,
    int *, active,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(unsigned int, flags_val, (flags ? *flags : 0))
    ctf_integer(int, active_val, (active ? *active : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDevicePrimaryCtxReset_v2_entry,
  TP_ARGS(
    CUdevice, dev
  ),
  TP_FIELDS(
    ctf_integer(CUdevice, dev, dev)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDevicePrimaryCtxReset_v2_exit,
  TP_ARGS(
    CUdevice, dev,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxCreate_v4_entry,
  TP_ARGS(
    CUcontext *, pctx,
    CUctxCreateParams *, ctxCreateParams,
    unsigned int, flags,
    CUdevice, dev
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pctx, (uintptr_t)(pctx))
    ctf_integer_hex(uintptr_t, ctxCreateParams, (uintptr_t)(ctxCreateParams))
    ctf_integer(unsigned int, flags, flags)
    ctf_integer(CUdevice, dev, dev)
    ctf_sequence_text(uint8_t, ctxCreateParams_val, ctxCreateParams, size_t, (ctxCreateParams ? sizeof(CUctxCreateParams) : 0))
    ctf_sequence_text(uint8_t, ctxCreateParams__execAffinityParams_vals, (ctxCreateParams ? ctxCreateParams->execAffinityParams : 0), size_t, ((ctxCreateParams && ctxCreateParams->execAffinityParams ? (ctxCreateParams->numExecAffinityParams < 0 ? 0 : (size_t)ctxCreateParams->numExecAffinityParams) : 0)) * sizeof(CUexecAffinityParam))
    ctf_sequence_text(uint8_t, ctxCreateParams__cigParams_val, (ctxCreateParams ? ctxCreateParams->cigParams : 0), size_t, (ctxCreateParams && ctxCreateParams->cigParams ? sizeof(CUctxCigParam) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxCreate_v4_exit,
  TP_ARGS(
    CUcontext *, pctx,
    CUctxCreateParams *, ctxCreateParams,
    unsigned int, flags,
    CUdevice, dev,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pctx_val, (uintptr_t)((pctx ? *pctx : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxDestroy_v2_entry,
  TP_ARGS(
    CUcontext, ctx
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ctx, (uintptr_t)(ctx))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxDestroy_v2_exit,
  TP_ARGS(
    CUcontext, ctx,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxPushCurrent_v2_entry,
  TP_ARGS(
    CUcontext, ctx
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ctx, (uintptr_t)(ctx))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxPushCurrent_v2_exit,
  TP_ARGS(
    CUcontext, ctx,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxPopCurrent_v2_entry,
  TP_ARGS(
    CUcontext *, pctx
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pctx, (uintptr_t)(pctx))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxPopCurrent_v2_exit,
  TP_ARGS(
    CUcontext *, pctx,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pctx_val, (uintptr_t)((pctx ? *pctx : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxSetCurrent_entry,
  TP_ARGS(
    CUcontext, ctx
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ctx, (uintptr_t)(ctx))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxSetCurrent_exit,
  TP_ARGS(
    CUcontext, ctx,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxGetCurrent_entry,
  TP_ARGS(
    CUcontext *, pctx
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pctx, (uintptr_t)(pctx))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxGetCurrent_exit,
  TP_ARGS(
    CUcontext *, pctx,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pctx_val, (uintptr_t)((pctx ? *pctx : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxGetDevice_entry,
  TP_ARGS(
    CUdevice *, device
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, device, (uintptr_t)(device))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxGetDevice_exit,
  TP_ARGS(
    CUdevice *, device,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(CUdevice, device_val, (device ? *device : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxGetDevice_v2_entry,
  TP_ARGS(
    CUdevice *, device,
    CUcontext, ctx
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, device, (uintptr_t)(device))
    ctf_integer_hex(uintptr_t, ctx, (uintptr_t)(ctx))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxGetDevice_v2_exit,
  TP_ARGS(
    CUdevice *, device,
    CUcontext, ctx,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(CUdevice, device_val, (device ? *device : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxGetFlags_entry,
  TP_ARGS(
    unsigned int *, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, flags, (uintptr_t)(flags))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxGetFlags_exit,
  TP_ARGS(
    unsigned int *, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(unsigned int, flags_val, (flags ? *flags : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxSetFlags_entry,
  TP_ARGS(
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxSetFlags_exit,
  TP_ARGS(
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxGetId_entry,
  TP_ARGS(
    CUcontext, ctx,
    unsigned long long int *, ctxId
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ctx, (uintptr_t)(ctx))
    ctf_integer_hex(uintptr_t, ctxId, (uintptr_t)(ctxId))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxGetId_exit,
  TP_ARGS(
    CUcontext, ctx,
    unsigned long long int *, ctxId,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(unsigned long long int, ctxId_val, (ctxId ? *ctxId : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxSynchronize_entry,
  TP_ARGS(
    void
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxSynchronize_exit,
  TP_ARGS(
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxSynchronize_v2_entry,
  TP_ARGS(
    CUcontext, ctx
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ctx, (uintptr_t)(ctx))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxSynchronize_v2_exit,
  TP_ARGS(
    CUcontext, ctx,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxSetLimit_entry,
  TP_ARGS(
    CUlimit, limit,
    size_t, value
  ),
  TP_FIELDS(
    ctf_integer(int32_t, limit, limit)
    ctf_integer(size_t, value, value)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxSetLimit_exit,
  TP_ARGS(
    CUlimit, limit,
    size_t, value,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxGetLimit_entry,
  TP_ARGS(
    size_t *, pvalue,
    CUlimit, limit
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pvalue, (uintptr_t)(pvalue))
    ctf_integer(int32_t, limit, limit)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxGetLimit_exit,
  TP_ARGS(
    size_t *, pvalue,
    CUlimit, limit,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(size_t, pvalue_val, (pvalue ? *pvalue : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxGetCacheConfig_entry,
  TP_ARGS(
    CUfunc_cache *, pconfig
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pconfig, (uintptr_t)(pconfig))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxGetCacheConfig_exit,
  TP_ARGS(
    CUfunc_cache *, pconfig,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int32_t, pconfig_val, (pconfig ? *pconfig : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxSetCacheConfig_entry,
  TP_ARGS(
    CUfunc_cache, config
  ),
  TP_FIELDS(
    ctf_integer(int32_t, config, config)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxSetCacheConfig_exit,
  TP_ARGS(
    CUfunc_cache, config,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxGetApiVersion_entry,
  TP_ARGS(
    CUcontext, ctx,
    unsigned int *, version
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ctx, (uintptr_t)(ctx))
    ctf_integer_hex(uintptr_t, version, (uintptr_t)(version))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxGetApiVersion_exit,
  TP_ARGS(
    CUcontext, ctx,
    unsigned int *, version,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(unsigned int, version_val, (version ? *version : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxGetStreamPriorityRange_entry,
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
  lttng_ust_cuda,
  cuCtxGetStreamPriorityRange_exit,
  TP_ARGS(
    int *, leastPriority,
    int *, greatestPriority,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int, leastPriority_val, (leastPriority ? *leastPriority : 0))
    ctf_integer(int, greatestPriority_val, (greatestPriority ? *greatestPriority : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxResetPersistingL2Cache_entry,
  TP_ARGS(
    void
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxResetPersistingL2Cache_exit,
  TP_ARGS(
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxGetExecAffinity_entry,
  TP_ARGS(
    CUexecAffinityParam *, pExecAffinity,
    CUexecAffinityType, type
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pExecAffinity, (uintptr_t)(pExecAffinity))
    ctf_integer(int32_t, type, type)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxGetExecAffinity_exit,
  TP_ARGS(
    CUexecAffinityParam *, pExecAffinity,
    CUexecAffinityType, type,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, pExecAffinity_val, pExecAffinity, size_t, (pExecAffinity ? sizeof(CUexecAffinityParam) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxRecordEvent_entry,
  TP_ARGS(
    CUcontext, hCtx,
    CUevent, hEvent
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hCtx, (uintptr_t)(hCtx))
    ctf_integer_hex(uintptr_t, hEvent, (uintptr_t)(hEvent))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxRecordEvent_exit,
  TP_ARGS(
    CUcontext, hCtx,
    CUevent, hEvent,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxWaitEvent_entry,
  TP_ARGS(
    CUcontext, hCtx,
    CUevent, hEvent
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hCtx, (uintptr_t)(hCtx))
    ctf_integer_hex(uintptr_t, hEvent, (uintptr_t)(hEvent))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxWaitEvent_exit,
  TP_ARGS(
    CUcontext, hCtx,
    CUevent, hEvent,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxAttach_entry,
  TP_ARGS(
    CUcontext *, pctx,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pctx, (uintptr_t)(pctx))
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxAttach_exit,
  TP_ARGS(
    CUcontext *, pctx,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pctx_val, (uintptr_t)((pctx ? *pctx : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxDetach_entry,
  TP_ARGS(
    CUcontext, ctx
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ctx, (uintptr_t)(ctx))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxDetach_exit,
  TP_ARGS(
    CUcontext, ctx,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxGetSharedMemConfig_entry,
  TP_ARGS(
    CUsharedconfig *, pConfig
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pConfig, (uintptr_t)(pConfig))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxGetSharedMemConfig_exit,
  TP_ARGS(
    CUsharedconfig *, pConfig,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int32_t, pConfig_val, (pConfig ? *pConfig : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxSetSharedMemConfig_entry,
  TP_ARGS(
    CUsharedconfig, config
  ),
  TP_FIELDS(
    ctf_integer(int32_t, config, config)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxSetSharedMemConfig_exit,
  TP_ARGS(
    CUsharedconfig, config,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuModuleLoad_entry,
  TP_ARGS(
    CUmodule *, module,
    const char *, fname
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, module, (uintptr_t)(module))
    ctf_integer_hex(uintptr_t, fname, (uintptr_t)(fname))
    ctf_string(fname_val, fname)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuModuleLoad_exit,
  TP_ARGS(
    CUmodule *, module,
    const char *, fname,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, module_val, (uintptr_t)((module ? *module : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuModuleLoadData_entry,
  TP_ARGS(
    CUmodule *, module,
    const void *, image
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, module, (uintptr_t)(module))
    ctf_integer_hex(uintptr_t, image, (uintptr_t)(image))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuModuleLoadData_exit,
  TP_ARGS(
    CUmodule *, module,
    const void *, image,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, module_val, (uintptr_t)((module ? *module : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuModuleLoadDataEx_entry,
  TP_ARGS(
    CUmodule *, module,
    const void *, image,
    unsigned int, numOptions,
    CUjit_option *, options,
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
  lttng_ust_cuda,
  cuModuleLoadDataEx_exit,
  TP_ARGS(
    CUmodule *, module,
    const void *, image,
    unsigned int, numOptions,
    CUjit_option *, options,
    void **, optionValues,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, module_val, (uintptr_t)((module ? *module : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuModuleLoadFatBinary_entry,
  TP_ARGS(
    CUmodule *, module,
    const void *, fatCubin
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, module, (uintptr_t)(module))
    ctf_integer_hex(uintptr_t, fatCubin, (uintptr_t)(fatCubin))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuModuleLoadFatBinary_exit,
  TP_ARGS(
    CUmodule *, module,
    const void *, fatCubin,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, module_val, (uintptr_t)((module ? *module : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuModuleUnload_entry,
  TP_ARGS(
    CUmodule, hmod
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hmod, (uintptr_t)(hmod))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuModuleUnload_exit,
  TP_ARGS(
    CUmodule, hmod,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuModuleGetLoadingMode_entry,
  TP_ARGS(
    CUmoduleLoadingMode *, mode
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mode, (uintptr_t)(mode))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuModuleGetLoadingMode_exit,
  TP_ARGS(
    CUmoduleLoadingMode *, mode,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int32_t, mode_val, (mode ? *mode : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuModuleGetFunction_entry,
  TP_ARGS(
    CUfunction *, hfunc,
    CUmodule, hmod,
    const char *, name
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hfunc, (uintptr_t)(hfunc))
    ctf_integer_hex(uintptr_t, hmod, (uintptr_t)(hmod))
    ctf_integer_hex(uintptr_t, name, (uintptr_t)(name))
    ctf_string(name_val, name)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuModuleGetFunction_exit,
  TP_ARGS(
    CUfunction *, hfunc,
    CUmodule, hmod,
    const char *, name,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, hfunc_val, (uintptr_t)((hfunc ? *hfunc : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuModuleGetFunctionCount_entry,
  TP_ARGS(
    unsigned int *, count,
    CUmodule, mod
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, count, (uintptr_t)(count))
    ctf_integer_hex(uintptr_t, mod, (uintptr_t)(mod))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuModuleGetFunctionCount_exit,
  TP_ARGS(
    unsigned int *, count,
    CUmodule, mod,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(unsigned int, count_val, (count ? *count : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuModuleEnumerateFunctions_entry,
  TP_ARGS(
    CUfunction *, functions,
    unsigned int, numFunctions,
    CUmodule, mod
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, functions, (uintptr_t)(functions))
    ctf_integer(unsigned int, numFunctions, numFunctions)
    ctf_integer_hex(uintptr_t, mod, (uintptr_t)(mod))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuModuleEnumerateFunctions_exit,
  TP_ARGS(
    CUfunction *, functions,
    unsigned int, numFunctions,
    CUmodule, mod,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_hex(uintptr_t, functions_vals, functions, unsigned int, (functions ? numFunctions : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuModuleGetGlobal_v2_entry,
  TP_ARGS(
    CUdeviceptr *, dptr,
    size_t *, bytes,
    CUmodule, hmod,
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
  lttng_ust_cuda,
  cuModuleGetGlobal_v2_exit,
  TP_ARGS(
    CUdeviceptr *, dptr,
    size_t *, bytes,
    CUmodule, hmod,
    const char *, name,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(CUdeviceptr, dptr_val, (dptr ? *dptr : 0))
    ctf_integer(size_t, bytes_val, (bytes ? *bytes : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLinkCreate_v2_entry,
  TP_ARGS(
    unsigned int, numOptions,
    CUjit_option *, options,
    void **, optionValues,
    CUlinkState *, stateOut
  ),
  TP_FIELDS(
    ctf_integer(unsigned int, numOptions, numOptions)
    ctf_integer_hex(uintptr_t, options, (uintptr_t)(options))
    ctf_integer_hex(uintptr_t, optionValues, (uintptr_t)(optionValues))
    ctf_integer_hex(uintptr_t, stateOut, (uintptr_t)(stateOut))
    ctf_sequence(int32_t, options_vals, options, unsigned int, (options ? numOptions : 0))
    ctf_sequence_hex(uintptr_t, optionValues_vals, optionValues, unsigned int, (optionValues ? numOptions : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLinkCreate_v2_exit,
  TP_ARGS(
    unsigned int, numOptions,
    CUjit_option *, options,
    void **, optionValues,
    CUlinkState *, stateOut,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, stateOut_val, (uintptr_t)((stateOut ? *stateOut : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLinkAddData_v2_entry,
  TP_ARGS(
    CUlinkState, state,
    CUjitInputType, type,
    void *, data,
    size_t, size,
    const char *, name,
    unsigned int, numOptions,
    CUjit_option *, options,
    void **, optionValues
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, state, (uintptr_t)(state))
    ctf_integer(int32_t, type, type)
    ctf_integer_hex(uintptr_t, data, (uintptr_t)(data))
    ctf_integer(size_t, size, size)
    ctf_integer_hex(uintptr_t, name, (uintptr_t)(name))
    ctf_integer(unsigned int, numOptions, numOptions)
    ctf_integer_hex(uintptr_t, options, (uintptr_t)(options))
    ctf_integer_hex(uintptr_t, optionValues, (uintptr_t)(optionValues))
    ctf_string(name_val, name)
    ctf_sequence(int32_t, options_vals, options, unsigned int, (options ? numOptions : 0))
    ctf_sequence_hex(uintptr_t, optionValues_vals, optionValues, unsigned int, (optionValues ? numOptions : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLinkAddData_v2_exit,
  TP_ARGS(
    CUlinkState, state,
    CUjitInputType, type,
    void *, data,
    size_t, size,
    const char *, name,
    unsigned int, numOptions,
    CUjit_option *, options,
    void **, optionValues,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLinkAddFile_v2_entry,
  TP_ARGS(
    CUlinkState, state,
    CUjitInputType, type,
    const char *, path,
    unsigned int, numOptions,
    CUjit_option *, options,
    void **, optionValues
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, state, (uintptr_t)(state))
    ctf_integer(int32_t, type, type)
    ctf_integer_hex(uintptr_t, path, (uintptr_t)(path))
    ctf_integer(unsigned int, numOptions, numOptions)
    ctf_integer_hex(uintptr_t, options, (uintptr_t)(options))
    ctf_integer_hex(uintptr_t, optionValues, (uintptr_t)(optionValues))
    ctf_string(path_val, path)
    ctf_sequence(int32_t, options_vals, options, unsigned int, (options ? numOptions : 0))
    ctf_sequence_hex(uintptr_t, optionValues_vals, optionValues, unsigned int, (optionValues ? numOptions : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLinkAddFile_v2_exit,
  TP_ARGS(
    CUlinkState, state,
    CUjitInputType, type,
    const char *, path,
    unsigned int, numOptions,
    CUjit_option *, options,
    void **, optionValues,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLinkComplete_entry,
  TP_ARGS(
    CUlinkState, state,
    void **, cubinOut,
    size_t *, sizeOut
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, state, (uintptr_t)(state))
    ctf_integer_hex(uintptr_t, cubinOut, (uintptr_t)(cubinOut))
    ctf_integer_hex(uintptr_t, sizeOut, (uintptr_t)(sizeOut))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLinkComplete_exit,
  TP_ARGS(
    CUlinkState, state,
    void **, cubinOut,
    size_t *, sizeOut,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, cubinOut_val, (uintptr_t)((cubinOut ? *cubinOut : 0)))
    ctf_integer(size_t, sizeOut_val, (sizeOut ? *sizeOut : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLinkDestroy_entry,
  TP_ARGS(
    CUlinkState, state
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, state, (uintptr_t)(state))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLinkDestroy_exit,
  TP_ARGS(
    CUlinkState, state,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuModuleGetTexRef_entry,
  TP_ARGS(
    CUtexref *, pTexRef,
    CUmodule, hmod,
    const char *, name
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pTexRef, (uintptr_t)(pTexRef))
    ctf_integer_hex(uintptr_t, hmod, (uintptr_t)(hmod))
    ctf_integer_hex(uintptr_t, name, (uintptr_t)(name))
    ctf_string(name_val, name)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuModuleGetTexRef_exit,
  TP_ARGS(
    CUtexref *, pTexRef,
    CUmodule, hmod,
    const char *, name,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pTexRef_val, (uintptr_t)((pTexRef ? *pTexRef : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuModuleGetSurfRef_entry,
  TP_ARGS(
    CUsurfref *, pSurfRef,
    CUmodule, hmod,
    const char *, name
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pSurfRef, (uintptr_t)(pSurfRef))
    ctf_integer_hex(uintptr_t, hmod, (uintptr_t)(hmod))
    ctf_integer_hex(uintptr_t, name, (uintptr_t)(name))
    ctf_string(name_val, name)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuModuleGetSurfRef_exit,
  TP_ARGS(
    CUsurfref *, pSurfRef,
    CUmodule, hmod,
    const char *, name,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pSurfRef_val, (uintptr_t)((pSurfRef ? *pSurfRef : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLibraryLoadData_entry,
  TP_ARGS(
    CUlibrary *, library,
    const void *, code,
    CUjit_option *, jitOptions,
    void **, jitOptionsValues,
    unsigned int, numJitOptions,
    CUlibraryOption *, libraryOptions,
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
    ctf_sequence(int32_t, jitOptions_vals, jitOptions, unsigned int, (jitOptions ? numJitOptions : 0))
    ctf_sequence_hex(uintptr_t, jitOptionsValues_vals, jitOptionsValues, unsigned int, (jitOptionsValues ? numJitOptions : 0))
    ctf_sequence(int32_t, libraryOptions_vals, libraryOptions, unsigned int, (libraryOptions ? numLibraryOptions : 0))
    ctf_sequence_hex(uintptr_t, libraryOptionValues_vals, libraryOptionValues, unsigned int, (libraryOptionValues ? numLibraryOptions : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLibraryLoadData_exit,
  TP_ARGS(
    CUlibrary *, library,
    const void *, code,
    CUjit_option *, jitOptions,
    void **, jitOptionsValues,
    unsigned int, numJitOptions,
    CUlibraryOption *, libraryOptions,
    void **, libraryOptionValues,
    unsigned int, numLibraryOptions,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, library_val, (uintptr_t)((library ? *library : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLibraryLoadFromFile_entry,
  TP_ARGS(
    CUlibrary *, library,
    const char *, fileName,
    CUjit_option *, jitOptions,
    void **, jitOptionsValues,
    unsigned int, numJitOptions,
    CUlibraryOption *, libraryOptions,
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
    ctf_string(fileName_val, fileName)
    ctf_sequence(int32_t, jitOptions_vals, jitOptions, unsigned int, (jitOptions ? numJitOptions : 0))
    ctf_sequence_hex(uintptr_t, jitOptionsValues_vals, jitOptionsValues, unsigned int, (jitOptionsValues ? numJitOptions : 0))
    ctf_sequence(int32_t, libraryOptions_vals, libraryOptions, unsigned int, (libraryOptions ? numLibraryOptions : 0))
    ctf_sequence_hex(uintptr_t, libraryOptionValues_vals, libraryOptionValues, unsigned int, (libraryOptionValues ? numLibraryOptions : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLibraryLoadFromFile_exit,
  TP_ARGS(
    CUlibrary *, library,
    const char *, fileName,
    CUjit_option *, jitOptions,
    void **, jitOptionsValues,
    unsigned int, numJitOptions,
    CUlibraryOption *, libraryOptions,
    void **, libraryOptionValues,
    unsigned int, numLibraryOptions,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, library_val, (uintptr_t)((library ? *library : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLibraryUnload_entry,
  TP_ARGS(
    CUlibrary, library
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, library, (uintptr_t)(library))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLibraryUnload_exit,
  TP_ARGS(
    CUlibrary, library,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLibraryGetKernel_entry,
  TP_ARGS(
    CUkernel *, pKernel,
    CUlibrary, library,
    const char *, name
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pKernel, (uintptr_t)(pKernel))
    ctf_integer_hex(uintptr_t, library, (uintptr_t)(library))
    ctf_integer_hex(uintptr_t, name, (uintptr_t)(name))
    ctf_string(name_val, name)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLibraryGetKernel_exit,
  TP_ARGS(
    CUkernel *, pKernel,
    CUlibrary, library,
    const char *, name,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pKernel_val, (uintptr_t)((pKernel ? *pKernel : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLibraryGetKernelCount_entry,
  TP_ARGS(
    unsigned int *, count,
    CUlibrary, lib
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, count, (uintptr_t)(count))
    ctf_integer_hex(uintptr_t, lib, (uintptr_t)(lib))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLibraryGetKernelCount_exit,
  TP_ARGS(
    unsigned int *, count,
    CUlibrary, lib,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(unsigned int, count_val, (count ? *count : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLibraryEnumerateKernels_entry,
  TP_ARGS(
    CUkernel *, kernels,
    unsigned int, numKernels,
    CUlibrary, lib
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, kernels, (uintptr_t)(kernels))
    ctf_integer(unsigned int, numKernels, numKernels)
    ctf_integer_hex(uintptr_t, lib, (uintptr_t)(lib))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLibraryEnumerateKernels_exit,
  TP_ARGS(
    CUkernel *, kernels,
    unsigned int, numKernels,
    CUlibrary, lib,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_hex(uintptr_t, kernels_vals, kernels, unsigned int, (kernels ? numKernels : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLibraryGetModule_entry,
  TP_ARGS(
    CUmodule *, pMod,
    CUlibrary, library
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pMod, (uintptr_t)(pMod))
    ctf_integer_hex(uintptr_t, library, (uintptr_t)(library))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLibraryGetModule_exit,
  TP_ARGS(
    CUmodule *, pMod,
    CUlibrary, library,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pMod_val, (uintptr_t)((pMod ? *pMod : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuKernelGetFunction_entry,
  TP_ARGS(
    CUfunction *, pFunc,
    CUkernel, kernel
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pFunc, (uintptr_t)(pFunc))
    ctf_integer_hex(uintptr_t, kernel, (uintptr_t)(kernel))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuKernelGetFunction_exit,
  TP_ARGS(
    CUfunction *, pFunc,
    CUkernel, kernel,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pFunc_val, (uintptr_t)((pFunc ? *pFunc : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuKernelGetLibrary_entry,
  TP_ARGS(
    CUlibrary *, pLib,
    CUkernel, kernel
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pLib, (uintptr_t)(pLib))
    ctf_integer_hex(uintptr_t, kernel, (uintptr_t)(kernel))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuKernelGetLibrary_exit,
  TP_ARGS(
    CUlibrary *, pLib,
    CUkernel, kernel,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pLib_val, (uintptr_t)((pLib ? *pLib : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLibraryGetGlobal_entry,
  TP_ARGS(
    CUdeviceptr *, dptr,
    size_t *, bytes,
    CUlibrary, library,
    const char *, name
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dptr, (uintptr_t)(dptr))
    ctf_integer_hex(uintptr_t, bytes, (uintptr_t)(bytes))
    ctf_integer_hex(uintptr_t, library, (uintptr_t)(library))
    ctf_integer_hex(uintptr_t, name, (uintptr_t)(name))
    ctf_string(name_val, name)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLibraryGetGlobal_exit,
  TP_ARGS(
    CUdeviceptr *, dptr,
    size_t *, bytes,
    CUlibrary, library,
    const char *, name,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(CUdeviceptr, dptr_val, (dptr ? *dptr : 0))
    ctf_integer(size_t, bytes_val, (bytes ? *bytes : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLibraryGetManaged_entry,
  TP_ARGS(
    CUdeviceptr *, dptr,
    size_t *, bytes,
    CUlibrary, library,
    const char *, name
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dptr, (uintptr_t)(dptr))
    ctf_integer_hex(uintptr_t, bytes, (uintptr_t)(bytes))
    ctf_integer_hex(uintptr_t, library, (uintptr_t)(library))
    ctf_integer_hex(uintptr_t, name, (uintptr_t)(name))
    ctf_string(name_val, name)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLibraryGetManaged_exit,
  TP_ARGS(
    CUdeviceptr *, dptr,
    size_t *, bytes,
    CUlibrary, library,
    const char *, name,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(CUdeviceptr, dptr_val, (dptr ? *dptr : 0))
    ctf_integer(size_t, bytes_val, (bytes ? *bytes : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLibraryGetUnifiedFunction_entry,
  TP_ARGS(
    void **, fptr,
    CUlibrary, library,
    const char *, symbol
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, fptr, (uintptr_t)(fptr))
    ctf_integer_hex(uintptr_t, library, (uintptr_t)(library))
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
    ctf_string(symbol_val, symbol)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLibraryGetUnifiedFunction_exit,
  TP_ARGS(
    void **, fptr,
    CUlibrary, library,
    const char *, symbol,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, fptr_val, (uintptr_t)((fptr ? *fptr : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuKernelGetAttribute_entry,
  TP_ARGS(
    int *, pi,
    CUfunction_attribute, attrib,
    CUkernel, kernel,
    CUdevice, dev
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pi, (uintptr_t)(pi))
    ctf_integer(int32_t, attrib, attrib)
    ctf_integer_hex(uintptr_t, kernel, (uintptr_t)(kernel))
    ctf_integer(CUdevice, dev, dev)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuKernelGetAttribute_exit,
  TP_ARGS(
    int *, pi,
    CUfunction_attribute, attrib,
    CUkernel, kernel,
    CUdevice, dev,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int, pi_val, (pi ? *pi : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuKernelSetAttribute_entry,
  TP_ARGS(
    CUfunction_attribute, attrib,
    int, val,
    CUkernel, kernel,
    CUdevice, dev
  ),
  TP_FIELDS(
    ctf_integer(int32_t, attrib, attrib)
    ctf_integer(int, val, val)
    ctf_integer_hex(uintptr_t, kernel, (uintptr_t)(kernel))
    ctf_integer(CUdevice, dev, dev)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuKernelSetAttribute_exit,
  TP_ARGS(
    CUfunction_attribute, attrib,
    int, val,
    CUkernel, kernel,
    CUdevice, dev,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuKernelSetCacheConfig_entry,
  TP_ARGS(
    CUkernel, kernel,
    CUfunc_cache, config,
    CUdevice, dev
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, kernel, (uintptr_t)(kernel))
    ctf_integer(int32_t, config, config)
    ctf_integer(CUdevice, dev, dev)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuKernelSetCacheConfig_exit,
  TP_ARGS(
    CUkernel, kernel,
    CUfunc_cache, config,
    CUdevice, dev,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuKernelGetName_entry,
  TP_ARGS(
    const char **, name,
    CUkernel, hfunc
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, name, (uintptr_t)(name))
    ctf_integer_hex(uintptr_t, hfunc, (uintptr_t)(hfunc))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuKernelGetName_exit,
  TP_ARGS(
    const char **, name,
    CUkernel, hfunc,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_string(name_val_val, *name)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuKernelGetParamInfo_entry,
  TP_ARGS(
    CUkernel, kernel,
    size_t, paramIndex,
    size_t *, paramOffset,
    size_t *, paramSize
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, kernel, (uintptr_t)(kernel))
    ctf_integer(size_t, paramIndex, paramIndex)
    ctf_integer_hex(uintptr_t, paramOffset, (uintptr_t)(paramOffset))
    ctf_integer_hex(uintptr_t, paramSize, (uintptr_t)(paramSize))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuKernelGetParamInfo_exit,
  TP_ARGS(
    CUkernel, kernel,
    size_t, paramIndex,
    size_t *, paramOffset,
    size_t *, paramSize,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(size_t, paramOffset_val, (paramOffset ? *paramOffset : 0))
    ctf_integer(size_t, paramSize_val, (paramSize ? *paramSize : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemGetInfo_v2_entry,
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
  lttng_ust_cuda,
  cuMemGetInfo_v2_exit,
  TP_ARGS(
    size_t *, free,
    size_t *, total,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(size_t, free_val, (free ? *free : 0))
    ctf_integer(size_t, total_val, (total ? *total : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemAlloc_v2_entry,
  TP_ARGS(
    CUdeviceptr *, dptr,
    size_t, bytesize
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dptr, (uintptr_t)(dptr))
    ctf_integer(size_t, bytesize, bytesize)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemAlloc_v2_exit,
  TP_ARGS(
    CUdeviceptr *, dptr,
    size_t, bytesize,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(CUdeviceptr, dptr_val, (dptr ? *dptr : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemAllocPitch_v2_entry,
  TP_ARGS(
    CUdeviceptr *, dptr,
    size_t *, pPitch,
    size_t, WidthInBytes,
    size_t, Height,
    unsigned int, ElementSizeBytes
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dptr, (uintptr_t)(dptr))
    ctf_integer_hex(uintptr_t, pPitch, (uintptr_t)(pPitch))
    ctf_integer(size_t, WidthInBytes, WidthInBytes)
    ctf_integer(size_t, Height, Height)
    ctf_integer(unsigned int, ElementSizeBytes, ElementSizeBytes)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemAllocPitch_v2_exit,
  TP_ARGS(
    CUdeviceptr *, dptr,
    size_t *, pPitch,
    size_t, WidthInBytes,
    size_t, Height,
    unsigned int, ElementSizeBytes,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(CUdeviceptr, dptr_val, (dptr ? *dptr : 0))
    ctf_integer(size_t, pPitch_val, (pPitch ? *pPitch : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemFree_v2_entry,
  TP_ARGS(
    CUdeviceptr, dptr
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dptr, dptr)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemFree_v2_exit,
  TP_ARGS(
    CUdeviceptr, dptr,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemGetAddressRange_v2_entry,
  TP_ARGS(
    CUdeviceptr *, pbase,
    size_t *, psize,
    CUdeviceptr, dptr
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pbase, (uintptr_t)(pbase))
    ctf_integer_hex(uintptr_t, psize, (uintptr_t)(psize))
    ctf_integer_hex(CUdeviceptr, dptr, dptr)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemGetAddressRange_v2_exit,
  TP_ARGS(
    CUdeviceptr *, pbase,
    size_t *, psize,
    CUdeviceptr, dptr,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(CUdeviceptr, pbase_val, (pbase ? *pbase : 0))
    ctf_integer(size_t, psize_val, (psize ? *psize : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemAllocHost_v2_entry,
  TP_ARGS(
    void **, pp,
    size_t, bytesize
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pp, (uintptr_t)(pp))
    ctf_integer(size_t, bytesize, bytesize)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemAllocHost_v2_exit,
  TP_ARGS(
    void **, pp,
    size_t, bytesize,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pp_val, (uintptr_t)((pp ? *pp : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemFreeHost_entry,
  TP_ARGS(
    void *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemFreeHost_exit,
  TP_ARGS(
    void *, p,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemHostAlloc_entry,
  TP_ARGS(
    void **, pp,
    size_t, bytesize,
    unsigned int, Flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pp, (uintptr_t)(pp))
    ctf_integer(size_t, bytesize, bytesize)
    ctf_integer(unsigned int, Flags, Flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemHostAlloc_exit,
  TP_ARGS(
    void **, pp,
    size_t, bytesize,
    unsigned int, Flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pp_val, (uintptr_t)((pp ? *pp : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemHostGetDevicePointer_v2_entry,
  TP_ARGS(
    CUdeviceptr *, pdptr,
    void *, p,
    unsigned int, Flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pdptr, (uintptr_t)(pdptr))
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_integer(unsigned int, Flags, Flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemHostGetDevicePointer_v2_exit,
  TP_ARGS(
    CUdeviceptr *, pdptr,
    void *, p,
    unsigned int, Flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(CUdeviceptr, pdptr_val, (pdptr ? *pdptr : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemHostGetFlags_entry,
  TP_ARGS(
    unsigned int *, pFlags,
    void *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pFlags, (uintptr_t)(pFlags))
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemHostGetFlags_exit,
  TP_ARGS(
    unsigned int *, pFlags,
    void *, p,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(unsigned int, pFlags_val, (pFlags ? *pFlags : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemAllocManaged_entry,
  TP_ARGS(
    CUdeviceptr *, dptr,
    size_t, bytesize,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dptr, (uintptr_t)(dptr))
    ctf_integer(size_t, bytesize, bytesize)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemAllocManaged_exit,
  TP_ARGS(
    CUdeviceptr *, dptr,
    size_t, bytesize,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(CUdeviceptr, dptr_val, (dptr ? *dptr : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceRegisterAsyncNotification_entry,
  TP_ARGS(
    CUdevice, device,
    CUasyncCallback, callbackFunc,
    void *, userData,
    CUasyncCallbackHandle *, callback
  ),
  TP_FIELDS(
    ctf_integer(CUdevice, device, device)
    ctf_integer_hex(uintptr_t, callbackFunc, (uintptr_t)(callbackFunc))
    ctf_integer_hex(uintptr_t, userData, (uintptr_t)(userData))
    ctf_integer_hex(uintptr_t, callback, (uintptr_t)(callback))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceRegisterAsyncNotification_exit,
  TP_ARGS(
    CUdevice, device,
    CUasyncCallback, callbackFunc,
    void *, userData,
    CUasyncCallbackHandle *, callback,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, callback_val, (uintptr_t)((callback ? *callback : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceUnregisterAsyncNotification_entry,
  TP_ARGS(
    CUdevice, device,
    CUasyncCallbackHandle, callback
  ),
  TP_FIELDS(
    ctf_integer(CUdevice, device, device)
    ctf_integer_hex(uintptr_t, callback, (uintptr_t)(callback))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceUnregisterAsyncNotification_exit,
  TP_ARGS(
    CUdevice, device,
    CUasyncCallbackHandle, callback,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetByPCIBusId_entry,
  TP_ARGS(
    CUdevice *, dev,
    const char *, pciBusId
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dev, (uintptr_t)(dev))
    ctf_integer_hex(uintptr_t, pciBusId, (uintptr_t)(pciBusId))
    ctf_string(pciBusId_val, pciBusId)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetByPCIBusId_exit,
  TP_ARGS(
    CUdevice *, dev,
    const char *, pciBusId,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(CUdevice, dev_val, (dev ? *dev : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetPCIBusId_entry,
  TP_ARGS(
    char *, pciBusId,
    int, len,
    CUdevice, dev
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pciBusId, (uintptr_t)(pciBusId))
    ctf_integer(int, len, len)
    ctf_integer(CUdevice, dev, dev)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetPCIBusId_exit,
  TP_ARGS(
    char *, pciBusId,
    int, len,
    CUdevice, dev,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_string(pciBusId_val, pciBusId)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuIpcGetEventHandle_entry,
  TP_ARGS(
    CUipcEventHandle *, pHandle,
    CUevent, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pHandle, (uintptr_t)(pHandle))
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuIpcGetEventHandle_exit,
  TP_ARGS(
    CUipcEventHandle *, pHandle,
    CUevent, event,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, pHandle_val, pHandle, size_t, (pHandle ? sizeof(CUipcEventHandle) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuIpcOpenEventHandle_entry,
  TP_ARGS(
    CUevent *, phEvent,
    CUipcEventHandle, handle
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, phEvent, (uintptr_t)(phEvent))
    ctf_array_text(uint8_t, handle, &handle, sizeof(CUipcEventHandle))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuIpcOpenEventHandle_exit,
  TP_ARGS(
    CUevent *, phEvent,
    CUipcEventHandle, handle,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phEvent_val, (uintptr_t)((phEvent ? *phEvent : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuIpcGetMemHandle_entry,
  TP_ARGS(
    CUipcMemHandle *, pHandle,
    CUdeviceptr, dptr
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pHandle, (uintptr_t)(pHandle))
    ctf_integer_hex(CUdeviceptr, dptr, dptr)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuIpcGetMemHandle_exit,
  TP_ARGS(
    CUipcMemHandle *, pHandle,
    CUdeviceptr, dptr,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, pHandle_val, pHandle, size_t, (pHandle ? sizeof(CUipcMemHandle) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuIpcOpenMemHandle_v2_entry,
  TP_ARGS(
    CUdeviceptr *, pdptr,
    CUipcMemHandle, handle,
    unsigned int, Flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pdptr, (uintptr_t)(pdptr))
    ctf_array_text(uint8_t, handle, &handle, sizeof(CUipcMemHandle))
    ctf_integer(unsigned int, Flags, Flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuIpcOpenMemHandle_v2_exit,
  TP_ARGS(
    CUdeviceptr *, pdptr,
    CUipcMemHandle, handle,
    unsigned int, Flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(CUdeviceptr, pdptr_val, (pdptr ? *pdptr : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuIpcCloseMemHandle_entry,
  TP_ARGS(
    CUdeviceptr, dptr
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dptr, dptr)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuIpcCloseMemHandle_exit,
  TP_ARGS(
    CUdeviceptr, dptr,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemHostRegister_v2_entry,
  TP_ARGS(
    void *, p,
    size_t, bytesize,
    unsigned int, Flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_integer(size_t, bytesize, bytesize)
    ctf_integer(unsigned int, Flags, Flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemHostRegister_v2_exit,
  TP_ARGS(
    void *, p,
    size_t, bytesize,
    unsigned int, Flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemHostUnregister_entry,
  TP_ARGS(
    void *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemHostUnregister_exit,
  TP_ARGS(
    void *, p,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy_ptds_entry,
  TP_ARGS(
    CUdeviceptr, dst,
    CUdeviceptr, src,
    size_t, ByteCount
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dst, dst)
    ctf_integer_hex(CUdeviceptr, src, src)
    ctf_integer(size_t, ByteCount, ByteCount)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy_ptds_exit,
  TP_ARGS(
    CUdeviceptr, dst,
    CUdeviceptr, src,
    size_t, ByteCount,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyPeer_ptds_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    CUcontext, dstContext,
    CUdeviceptr, srcDevice,
    CUcontext, srcContext,
    size_t, ByteCount
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer_hex(uintptr_t, dstContext, (uintptr_t)(dstContext))
    ctf_integer_hex(CUdeviceptr, srcDevice, srcDevice)
    ctf_integer_hex(uintptr_t, srcContext, (uintptr_t)(srcContext))
    ctf_integer(size_t, ByteCount, ByteCount)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyPeer_ptds_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    CUcontext, dstContext,
    CUdeviceptr, srcDevice,
    CUcontext, srcContext,
    size_t, ByteCount,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyHtoD_v2_ptds_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    const void *, srcHost,
    size_t, ByteCount
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer_hex(uintptr_t, srcHost, (uintptr_t)(srcHost))
    ctf_integer(size_t, ByteCount, ByteCount)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyHtoD_v2_ptds_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    const void *, srcHost,
    size_t, ByteCount,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyDtoH_v2_ptds_entry,
  TP_ARGS(
    void *, dstHost,
    CUdeviceptr, srcDevice,
    size_t, ByteCount
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dstHost, (uintptr_t)(dstHost))
    ctf_integer_hex(CUdeviceptr, srcDevice, srcDevice)
    ctf_integer(size_t, ByteCount, ByteCount)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyDtoH_v2_ptds_exit,
  TP_ARGS(
    void *, dstHost,
    CUdeviceptr, srcDevice,
    size_t, ByteCount,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyDtoD_v2_ptds_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    CUdeviceptr, srcDevice,
    size_t, ByteCount
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer_hex(CUdeviceptr, srcDevice, srcDevice)
    ctf_integer(size_t, ByteCount, ByteCount)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyDtoD_v2_ptds_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    CUdeviceptr, srcDevice,
    size_t, ByteCount,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyDtoA_v2_ptds_entry,
  TP_ARGS(
    CUarray, dstArray,
    size_t, dstOffset,
    CUdeviceptr, srcDevice,
    size_t, ByteCount
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dstArray, (uintptr_t)(dstArray))
    ctf_integer(size_t, dstOffset, dstOffset)
    ctf_integer_hex(CUdeviceptr, srcDevice, srcDevice)
    ctf_integer(size_t, ByteCount, ByteCount)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyDtoA_v2_ptds_exit,
  TP_ARGS(
    CUarray, dstArray,
    size_t, dstOffset,
    CUdeviceptr, srcDevice,
    size_t, ByteCount,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyAtoD_v2_ptds_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    CUarray, srcArray,
    size_t, srcOffset,
    size_t, ByteCount
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer_hex(uintptr_t, srcArray, (uintptr_t)(srcArray))
    ctf_integer(size_t, srcOffset, srcOffset)
    ctf_integer(size_t, ByteCount, ByteCount)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyAtoD_v2_ptds_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    CUarray, srcArray,
    size_t, srcOffset,
    size_t, ByteCount,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyHtoA_v2_ptds_entry,
  TP_ARGS(
    CUarray, dstArray,
    size_t, dstOffset,
    const void *, srcHost,
    size_t, ByteCount
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dstArray, (uintptr_t)(dstArray))
    ctf_integer(size_t, dstOffset, dstOffset)
    ctf_integer_hex(uintptr_t, srcHost, (uintptr_t)(srcHost))
    ctf_integer(size_t, ByteCount, ByteCount)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyHtoA_v2_ptds_exit,
  TP_ARGS(
    CUarray, dstArray,
    size_t, dstOffset,
    const void *, srcHost,
    size_t, ByteCount,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyAtoH_v2_ptds_entry,
  TP_ARGS(
    void *, dstHost,
    CUarray, srcArray,
    size_t, srcOffset,
    size_t, ByteCount
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dstHost, (uintptr_t)(dstHost))
    ctf_integer_hex(uintptr_t, srcArray, (uintptr_t)(srcArray))
    ctf_integer(size_t, srcOffset, srcOffset)
    ctf_integer(size_t, ByteCount, ByteCount)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyAtoH_v2_ptds_exit,
  TP_ARGS(
    void *, dstHost,
    CUarray, srcArray,
    size_t, srcOffset,
    size_t, ByteCount,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyAtoA_v2_ptds_entry,
  TP_ARGS(
    CUarray, dstArray,
    size_t, dstOffset,
    CUarray, srcArray,
    size_t, srcOffset,
    size_t, ByteCount
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dstArray, (uintptr_t)(dstArray))
    ctf_integer(size_t, dstOffset, dstOffset)
    ctf_integer_hex(uintptr_t, srcArray, (uintptr_t)(srcArray))
    ctf_integer(size_t, srcOffset, srcOffset)
    ctf_integer(size_t, ByteCount, ByteCount)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyAtoA_v2_ptds_exit,
  TP_ARGS(
    CUarray, dstArray,
    size_t, dstOffset,
    CUarray, srcArray,
    size_t, srcOffset,
    size_t, ByteCount,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy2D_v2_ptds_entry,
  TP_ARGS(
    const CUDA_MEMCPY2D *, pCopy
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pCopy, (uintptr_t)(pCopy))
    ctf_sequence_text(uint8_t, pCopy_val, pCopy, size_t, (pCopy ? sizeof(CUDA_MEMCPY2D) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy2D_v2_ptds_exit,
  TP_ARGS(
    const CUDA_MEMCPY2D *, pCopy,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy2DUnaligned_v2_ptds_entry,
  TP_ARGS(
    const CUDA_MEMCPY2D *, pCopy
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pCopy, (uintptr_t)(pCopy))
    ctf_sequence_text(uint8_t, pCopy_val, pCopy, size_t, (pCopy ? sizeof(CUDA_MEMCPY2D) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy2DUnaligned_v2_ptds_exit,
  TP_ARGS(
    const CUDA_MEMCPY2D *, pCopy,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy3D_v2_ptds_entry,
  TP_ARGS(
    const CUDA_MEMCPY3D *, pCopy
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pCopy, (uintptr_t)(pCopy))
    ctf_sequence_text(uint8_t, pCopy_val, pCopy, size_t, (pCopy ? sizeof(CUDA_MEMCPY3D) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy3D_v2_ptds_exit,
  TP_ARGS(
    const CUDA_MEMCPY3D *, pCopy,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy3DPeer_ptds_entry,
  TP_ARGS(
    const CUDA_MEMCPY3D_PEER *, pCopy
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pCopy, (uintptr_t)(pCopy))
    ctf_sequence_text(uint8_t, pCopy_val, pCopy, size_t, (pCopy ? sizeof(CUDA_MEMCPY3D_PEER) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy3DPeer_ptds_exit,
  TP_ARGS(
    const CUDA_MEMCPY3D_PEER *, pCopy,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyAsync_ptsz_entry,
  TP_ARGS(
    CUdeviceptr, dst,
    CUdeviceptr, src,
    size_t, ByteCount,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dst, dst)
    ctf_integer_hex(CUdeviceptr, src, src)
    ctf_integer(size_t, ByteCount, ByteCount)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyAsync_ptsz_exit,
  TP_ARGS(
    CUdeviceptr, dst,
    CUdeviceptr, src,
    size_t, ByteCount,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyPeerAsync_ptsz_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    CUcontext, dstContext,
    CUdeviceptr, srcDevice,
    CUcontext, srcContext,
    size_t, ByteCount,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer_hex(uintptr_t, dstContext, (uintptr_t)(dstContext))
    ctf_integer_hex(CUdeviceptr, srcDevice, srcDevice)
    ctf_integer_hex(uintptr_t, srcContext, (uintptr_t)(srcContext))
    ctf_integer(size_t, ByteCount, ByteCount)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyPeerAsync_ptsz_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    CUcontext, dstContext,
    CUdeviceptr, srcDevice,
    CUcontext, srcContext,
    size_t, ByteCount,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyHtoDAsync_v2_ptsz_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    const void *, srcHost,
    size_t, ByteCount,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer_hex(uintptr_t, srcHost, (uintptr_t)(srcHost))
    ctf_integer(size_t, ByteCount, ByteCount)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyHtoDAsync_v2_ptsz_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    const void *, srcHost,
    size_t, ByteCount,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyDtoHAsync_v2_ptsz_entry,
  TP_ARGS(
    void *, dstHost,
    CUdeviceptr, srcDevice,
    size_t, ByteCount,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dstHost, (uintptr_t)(dstHost))
    ctf_integer_hex(CUdeviceptr, srcDevice, srcDevice)
    ctf_integer(size_t, ByteCount, ByteCount)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyDtoHAsync_v2_ptsz_exit,
  TP_ARGS(
    void *, dstHost,
    CUdeviceptr, srcDevice,
    size_t, ByteCount,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyDtoDAsync_v2_ptsz_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    CUdeviceptr, srcDevice,
    size_t, ByteCount,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer_hex(CUdeviceptr, srcDevice, srcDevice)
    ctf_integer(size_t, ByteCount, ByteCount)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyDtoDAsync_v2_ptsz_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    CUdeviceptr, srcDevice,
    size_t, ByteCount,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyHtoAAsync_v2_ptsz_entry,
  TP_ARGS(
    CUarray, dstArray,
    size_t, dstOffset,
    const void *, srcHost,
    size_t, ByteCount,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dstArray, (uintptr_t)(dstArray))
    ctf_integer(size_t, dstOffset, dstOffset)
    ctf_integer_hex(uintptr_t, srcHost, (uintptr_t)(srcHost))
    ctf_integer(size_t, ByteCount, ByteCount)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyHtoAAsync_v2_ptsz_exit,
  TP_ARGS(
    CUarray, dstArray,
    size_t, dstOffset,
    const void *, srcHost,
    size_t, ByteCount,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyAtoHAsync_v2_ptsz_entry,
  TP_ARGS(
    void *, dstHost,
    CUarray, srcArray,
    size_t, srcOffset,
    size_t, ByteCount,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dstHost, (uintptr_t)(dstHost))
    ctf_integer_hex(uintptr_t, srcArray, (uintptr_t)(srcArray))
    ctf_integer(size_t, srcOffset, srcOffset)
    ctf_integer(size_t, ByteCount, ByteCount)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyAtoHAsync_v2_ptsz_exit,
  TP_ARGS(
    void *, dstHost,
    CUarray, srcArray,
    size_t, srcOffset,
    size_t, ByteCount,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy2DAsync_v2_ptsz_entry,
  TP_ARGS(
    const CUDA_MEMCPY2D *, pCopy,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pCopy, (uintptr_t)(pCopy))
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_sequence_text(uint8_t, pCopy_val, pCopy, size_t, (pCopy ? sizeof(CUDA_MEMCPY2D) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy2DAsync_v2_ptsz_exit,
  TP_ARGS(
    const CUDA_MEMCPY2D *, pCopy,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy3DAsync_v2_ptsz_entry,
  TP_ARGS(
    const CUDA_MEMCPY3D *, pCopy,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pCopy, (uintptr_t)(pCopy))
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_sequence_text(uint8_t, pCopy_val, pCopy, size_t, (pCopy ? sizeof(CUDA_MEMCPY3D) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy3DAsync_v2_ptsz_exit,
  TP_ARGS(
    const CUDA_MEMCPY3D *, pCopy,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy3DPeerAsync_ptsz_entry,
  TP_ARGS(
    const CUDA_MEMCPY3D_PEER *, pCopy,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pCopy, (uintptr_t)(pCopy))
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_sequence_text(uint8_t, pCopy_val, pCopy, size_t, (pCopy ? sizeof(CUDA_MEMCPY3D_PEER) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy3DPeerAsync_ptsz_exit,
  TP_ARGS(
    const CUDA_MEMCPY3D_PEER *, pCopy,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyBatchAsync_v2_ptsz_entry,
  TP_ARGS(
    CUdeviceptr *, dsts,
    CUdeviceptr *, srcs,
    size_t *, sizes,
    size_t, count,
    CUmemcpyAttributes *, attrs,
    size_t *, attrsIdxs,
    size_t, numAttrs,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dsts, (uintptr_t)(dsts))
    ctf_integer_hex(uintptr_t, srcs, (uintptr_t)(srcs))
    ctf_integer_hex(uintptr_t, sizes, (uintptr_t)(sizes))
    ctf_integer(size_t, count, count)
    ctf_integer_hex(uintptr_t, attrs, (uintptr_t)(attrs))
    ctf_integer_hex(uintptr_t, attrsIdxs, (uintptr_t)(attrsIdxs))
    ctf_integer(size_t, numAttrs, numAttrs)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_sequence_hex(CUdeviceptr, dsts_vals, dsts, size_t, (dsts ? count : 0))
    ctf_sequence_hex(CUdeviceptr, srcs_vals, srcs, size_t, (srcs ? count : 0))
    ctf_sequence(size_t, sizes_vals, sizes, size_t, (sizes ? count : 0))
    ctf_sequence_text(uint8_t, attrs_vals, attrs, size_t, ((attrs ? numAttrs : 0)) * sizeof(CUmemcpyAttributes))
    ctf_sequence(size_t, attrsIdxs_vals, attrsIdxs, size_t, (attrsIdxs ? numAttrs : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyBatchAsync_v2_ptsz_exit,
  TP_ARGS(
    CUdeviceptr *, dsts,
    CUdeviceptr *, srcs,
    size_t *, sizes,
    size_t, count,
    CUmemcpyAttributes *, attrs,
    size_t *, attrsIdxs,
    size_t, numAttrs,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy3DBatchAsync_v2_ptsz_entry,
  TP_ARGS(
    size_t, numOps,
    CUDA_MEMCPY3D_BATCH_OP *, opList,
    unsigned long long int, flags,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer(size_t, numOps, numOps)
    ctf_integer_hex(uintptr_t, opList, (uintptr_t)(opList))
    ctf_integer(unsigned long long int, flags, flags)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_sequence_text(uint8_t, opList_vals, opList, size_t, ((opList ? numOps : 0)) * sizeof(CUDA_MEMCPY3D_BATCH_OP))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy3DBatchAsync_v2_ptsz_exit,
  TP_ARGS(
    size_t, numOps,
    CUDA_MEMCPY3D_BATCH_OP *, opList,
    unsigned long long int, flags,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD8_v2_ptds_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    unsigned char, uc,
    size_t, N
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer(unsigned char, uc, uc)
    ctf_integer(size_t, N, N)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD8_v2_ptds_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    unsigned char, uc,
    size_t, N,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD16_v2_ptds_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    unsigned short int, us,
    size_t, N
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer(unsigned short int, us, us)
    ctf_integer(size_t, N, N)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD16_v2_ptds_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    unsigned short int, us,
    size_t, N,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD32_v2_ptds_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    unsigned int, ui,
    size_t, N
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer(unsigned int, ui, ui)
    ctf_integer(size_t, N, N)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD32_v2_ptds_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    unsigned int, ui,
    size_t, N,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD2D8_v2_ptds_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    size_t, dstPitch,
    unsigned char, uc,
    size_t, Width,
    size_t, Height
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer(size_t, dstPitch, dstPitch)
    ctf_integer(unsigned char, uc, uc)
    ctf_integer(size_t, Width, Width)
    ctf_integer(size_t, Height, Height)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD2D8_v2_ptds_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    size_t, dstPitch,
    unsigned char, uc,
    size_t, Width,
    size_t, Height,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD2D16_v2_ptds_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    size_t, dstPitch,
    unsigned short int, us,
    size_t, Width,
    size_t, Height
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer(size_t, dstPitch, dstPitch)
    ctf_integer(unsigned short int, us, us)
    ctf_integer(size_t, Width, Width)
    ctf_integer(size_t, Height, Height)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD2D16_v2_ptds_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    size_t, dstPitch,
    unsigned short int, us,
    size_t, Width,
    size_t, Height,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD2D32_v2_ptds_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    size_t, dstPitch,
    unsigned int, ui,
    size_t, Width,
    size_t, Height
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer(size_t, dstPitch, dstPitch)
    ctf_integer(unsigned int, ui, ui)
    ctf_integer(size_t, Width, Width)
    ctf_integer(size_t, Height, Height)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD2D32_v2_ptds_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    size_t, dstPitch,
    unsigned int, ui,
    size_t, Width,
    size_t, Height,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD8Async_ptsz_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    unsigned char, uc,
    size_t, N,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer(unsigned char, uc, uc)
    ctf_integer(size_t, N, N)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD8Async_ptsz_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    unsigned char, uc,
    size_t, N,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD16Async_ptsz_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    unsigned short int, us,
    size_t, N,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer(unsigned short int, us, us)
    ctf_integer(size_t, N, N)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD16Async_ptsz_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    unsigned short int, us,
    size_t, N,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD32Async_ptsz_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    unsigned int, ui,
    size_t, N,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer(unsigned int, ui, ui)
    ctf_integer(size_t, N, N)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD32Async_ptsz_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    unsigned int, ui,
    size_t, N,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD2D8Async_ptsz_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    size_t, dstPitch,
    unsigned char, uc,
    size_t, Width,
    size_t, Height,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer(size_t, dstPitch, dstPitch)
    ctf_integer(unsigned char, uc, uc)
    ctf_integer(size_t, Width, Width)
    ctf_integer(size_t, Height, Height)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD2D8Async_ptsz_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    size_t, dstPitch,
    unsigned char, uc,
    size_t, Width,
    size_t, Height,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD2D16Async_ptsz_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    size_t, dstPitch,
    unsigned short int, us,
    size_t, Width,
    size_t, Height,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer(size_t, dstPitch, dstPitch)
    ctf_integer(unsigned short int, us, us)
    ctf_integer(size_t, Width, Width)
    ctf_integer(size_t, Height, Height)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD2D16Async_ptsz_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    size_t, dstPitch,
    unsigned short int, us,
    size_t, Width,
    size_t, Height,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD2D32Async_ptsz_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    size_t, dstPitch,
    unsigned int, ui,
    size_t, Width,
    size_t, Height,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer(size_t, dstPitch, dstPitch)
    ctf_integer(unsigned int, ui, ui)
    ctf_integer(size_t, Width, Width)
    ctf_integer(size_t, Height, Height)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD2D32Async_ptsz_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    size_t, dstPitch,
    unsigned int, ui,
    size_t, Width,
    size_t, Height,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuArrayCreate_v2_entry,
  TP_ARGS(
    CUarray *, pHandle,
    const CUDA_ARRAY_DESCRIPTOR *, pAllocateArray
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pHandle, (uintptr_t)(pHandle))
    ctf_integer_hex(uintptr_t, pAllocateArray, (uintptr_t)(pAllocateArray))
    ctf_sequence_text(uint8_t, pAllocateArray_val, pAllocateArray, size_t, (pAllocateArray ? sizeof(CUDA_ARRAY_DESCRIPTOR) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuArrayCreate_v2_exit,
  TP_ARGS(
    CUarray *, pHandle,
    const CUDA_ARRAY_DESCRIPTOR *, pAllocateArray,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pHandle_val, (uintptr_t)((pHandle ? *pHandle : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuArrayGetDescriptor_v2_entry,
  TP_ARGS(
    CUDA_ARRAY_DESCRIPTOR *, pArrayDescriptor,
    CUarray, hArray
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pArrayDescriptor, (uintptr_t)(pArrayDescriptor))
    ctf_integer_hex(uintptr_t, hArray, (uintptr_t)(hArray))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuArrayGetDescriptor_v2_exit,
  TP_ARGS(
    CUDA_ARRAY_DESCRIPTOR *, pArrayDescriptor,
    CUarray, hArray,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, pArrayDescriptor_val, pArrayDescriptor, size_t, (pArrayDescriptor ? sizeof(CUDA_ARRAY_DESCRIPTOR) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuArrayGetSparseProperties_entry,
  TP_ARGS(
    CUDA_ARRAY_SPARSE_PROPERTIES *, sparseProperties,
    CUarray, array
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, sparseProperties, (uintptr_t)(sparseProperties))
    ctf_integer_hex(uintptr_t, array, (uintptr_t)(array))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuArrayGetSparseProperties_exit,
  TP_ARGS(
    CUDA_ARRAY_SPARSE_PROPERTIES *, sparseProperties,
    CUarray, array,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, sparseProperties_val, sparseProperties, size_t, (sparseProperties ? sizeof(CUDA_ARRAY_SPARSE_PROPERTIES) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMipmappedArrayGetSparseProperties_entry,
  TP_ARGS(
    CUDA_ARRAY_SPARSE_PROPERTIES *, sparseProperties,
    CUmipmappedArray, mipmap
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, sparseProperties, (uintptr_t)(sparseProperties))
    ctf_integer_hex(uintptr_t, mipmap, (uintptr_t)(mipmap))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMipmappedArrayGetSparseProperties_exit,
  TP_ARGS(
    CUDA_ARRAY_SPARSE_PROPERTIES *, sparseProperties,
    CUmipmappedArray, mipmap,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, sparseProperties_val, sparseProperties, size_t, (sparseProperties ? sizeof(CUDA_ARRAY_SPARSE_PROPERTIES) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuArrayGetMemoryRequirements_entry,
  TP_ARGS(
    CUDA_ARRAY_MEMORY_REQUIREMENTS *, memoryRequirements,
    CUarray, array,
    CUdevice, device
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, memoryRequirements, (uintptr_t)(memoryRequirements))
    ctf_integer_hex(uintptr_t, array, (uintptr_t)(array))
    ctf_integer(CUdevice, device, device)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuArrayGetMemoryRequirements_exit,
  TP_ARGS(
    CUDA_ARRAY_MEMORY_REQUIREMENTS *, memoryRequirements,
    CUarray, array,
    CUdevice, device,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, memoryRequirements_val, memoryRequirements, size_t, (memoryRequirements ? sizeof(CUDA_ARRAY_MEMORY_REQUIREMENTS) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMipmappedArrayGetMemoryRequirements_entry,
  TP_ARGS(
    CUDA_ARRAY_MEMORY_REQUIREMENTS *, memoryRequirements,
    CUmipmappedArray, mipmap,
    CUdevice, device
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, memoryRequirements, (uintptr_t)(memoryRequirements))
    ctf_integer_hex(uintptr_t, mipmap, (uintptr_t)(mipmap))
    ctf_integer(CUdevice, device, device)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMipmappedArrayGetMemoryRequirements_exit,
  TP_ARGS(
    CUDA_ARRAY_MEMORY_REQUIREMENTS *, memoryRequirements,
    CUmipmappedArray, mipmap,
    CUdevice, device,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, memoryRequirements_val, memoryRequirements, size_t, (memoryRequirements ? sizeof(CUDA_ARRAY_MEMORY_REQUIREMENTS) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuArrayGetPlane_entry,
  TP_ARGS(
    CUarray *, pPlaneArray,
    CUarray, hArray,
    unsigned int, planeIdx
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pPlaneArray, (uintptr_t)(pPlaneArray))
    ctf_integer_hex(uintptr_t, hArray, (uintptr_t)(hArray))
    ctf_integer(unsigned int, planeIdx, planeIdx)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuArrayGetPlane_exit,
  TP_ARGS(
    CUarray *, pPlaneArray,
    CUarray, hArray,
    unsigned int, planeIdx,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pPlaneArray_val, (uintptr_t)((pPlaneArray ? *pPlaneArray : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuArrayDestroy_entry,
  TP_ARGS(
    CUarray, hArray
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hArray, (uintptr_t)(hArray))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuArrayDestroy_exit,
  TP_ARGS(
    CUarray, hArray,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuArray3DCreate_v2_entry,
  TP_ARGS(
    CUarray *, pHandle,
    const CUDA_ARRAY3D_DESCRIPTOR *, pAllocateArray
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pHandle, (uintptr_t)(pHandle))
    ctf_integer_hex(uintptr_t, pAllocateArray, (uintptr_t)(pAllocateArray))
    ctf_sequence_text(uint8_t, pAllocateArray_val, pAllocateArray, size_t, (pAllocateArray ? sizeof(CUDA_ARRAY3D_DESCRIPTOR) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuArray3DCreate_v2_exit,
  TP_ARGS(
    CUarray *, pHandle,
    const CUDA_ARRAY3D_DESCRIPTOR *, pAllocateArray,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pHandle_val, (uintptr_t)((pHandle ? *pHandle : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuArray3DGetDescriptor_v2_entry,
  TP_ARGS(
    CUDA_ARRAY3D_DESCRIPTOR *, pArrayDescriptor,
    CUarray, hArray
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pArrayDescriptor, (uintptr_t)(pArrayDescriptor))
    ctf_integer_hex(uintptr_t, hArray, (uintptr_t)(hArray))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuArray3DGetDescriptor_v2_exit,
  TP_ARGS(
    CUDA_ARRAY3D_DESCRIPTOR *, pArrayDescriptor,
    CUarray, hArray,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, pArrayDescriptor_val, pArrayDescriptor, size_t, (pArrayDescriptor ? sizeof(CUDA_ARRAY3D_DESCRIPTOR) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMipmappedArrayCreate_entry,
  TP_ARGS(
    CUmipmappedArray *, pHandle,
    const CUDA_ARRAY3D_DESCRIPTOR *, pMipmappedArrayDesc,
    unsigned int, numMipmapLevels
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pHandle, (uintptr_t)(pHandle))
    ctf_integer_hex(uintptr_t, pMipmappedArrayDesc, (uintptr_t)(pMipmappedArrayDesc))
    ctf_integer(unsigned int, numMipmapLevels, numMipmapLevels)
    ctf_sequence_text(uint8_t, pMipmappedArrayDesc_val, pMipmappedArrayDesc, size_t, (pMipmappedArrayDesc ? sizeof(CUDA_ARRAY3D_DESCRIPTOR) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMipmappedArrayCreate_exit,
  TP_ARGS(
    CUmipmappedArray *, pHandle,
    const CUDA_ARRAY3D_DESCRIPTOR *, pMipmappedArrayDesc,
    unsigned int, numMipmapLevels,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pHandle_val, (uintptr_t)((pHandle ? *pHandle : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMipmappedArrayGetLevel_entry,
  TP_ARGS(
    CUarray *, pLevelArray,
    CUmipmappedArray, hMipmappedArray,
    unsigned int, level
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pLevelArray, (uintptr_t)(pLevelArray))
    ctf_integer_hex(uintptr_t, hMipmappedArray, (uintptr_t)(hMipmappedArray))
    ctf_integer(unsigned int, level, level)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMipmappedArrayGetLevel_exit,
  TP_ARGS(
    CUarray *, pLevelArray,
    CUmipmappedArray, hMipmappedArray,
    unsigned int, level,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pLevelArray_val, (uintptr_t)((pLevelArray ? *pLevelArray : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMipmappedArrayDestroy_entry,
  TP_ARGS(
    CUmipmappedArray, hMipmappedArray
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hMipmappedArray, (uintptr_t)(hMipmappedArray))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMipmappedArrayDestroy_exit,
  TP_ARGS(
    CUmipmappedArray, hMipmappedArray,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemGetHandleForAddressRange_entry,
  TP_ARGS(
    void *, handle,
    CUdeviceptr, dptr,
    size_t, size,
    CUmemRangeHandleType, handleType,
    unsigned long long int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, handle, (uintptr_t)(handle))
    ctf_integer_hex(CUdeviceptr, dptr, dptr)
    ctf_integer(size_t, size, size)
    ctf_integer(int32_t, handleType, handleType)
    ctf_integer(unsigned long long int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemGetHandleForAddressRange_exit,
  TP_ARGS(
    void *, handle,
    CUdeviceptr, dptr,
    size_t, size,
    CUmemRangeHandleType, handleType,
    unsigned long long int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, handle_val, handle, size_t, handleType == CU_MEM_RANGE_HANDLE_TYPE_DMA_BUF_FD ? sizeof(int) : 0)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemBatchDecompressAsync_ptsz_entry,
  TP_ARGS(
    CUmemDecompressParams *, paramsArray,
    size_t, count,
    unsigned int, flags,
    size_t *, errorIndex,
    CUstream, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, paramsArray, (uintptr_t)(paramsArray))
    ctf_integer(size_t, count, count)
    ctf_integer(unsigned int, flags, flags)
    ctf_integer_hex(uintptr_t, errorIndex, (uintptr_t)(errorIndex))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_sequence_text(uint8_t, paramsArray_vals, paramsArray, size_t, ((paramsArray ? count : 0)) * sizeof(CUmemDecompressParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemBatchDecompressAsync_ptsz_exit,
  TP_ARGS(
    CUmemDecompressParams *, paramsArray,
    size_t, count,
    unsigned int, flags,
    size_t *, errorIndex,
    CUstream, stream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(size_t, errorIndex_val, (errorIndex ? *errorIndex : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemAddressReserve_entry,
  TP_ARGS(
    CUdeviceptr *, ptr,
    size_t, size,
    size_t, alignment,
    CUdeviceptr, addr,
    unsigned long long int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)(ptr))
    ctf_integer(size_t, size, size)
    ctf_integer(size_t, alignment, alignment)
    ctf_integer_hex(CUdeviceptr, addr, addr)
    ctf_integer(unsigned long long int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemAddressReserve_exit,
  TP_ARGS(
    CUdeviceptr *, ptr,
    size_t, size,
    size_t, alignment,
    CUdeviceptr, addr,
    unsigned long long int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(CUdeviceptr, ptr_val, (ptr ? *ptr : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemAddressFree_entry,
  TP_ARGS(
    CUdeviceptr, ptr,
    size_t, size
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, ptr, ptr)
    ctf_integer(size_t, size, size)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemAddressFree_exit,
  TP_ARGS(
    CUdeviceptr, ptr,
    size_t, size,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemCreate_entry,
  TP_ARGS(
    CUmemGenericAllocationHandle *, handle,
    size_t, size,
    const CUmemAllocationProp *, prop,
    unsigned long long int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, handle, (uintptr_t)(handle))
    ctf_integer(size_t, size, size)
    ctf_integer_hex(uintptr_t, prop, (uintptr_t)(prop))
    ctf_integer(unsigned long long int, flags, flags)
    ctf_sequence_text(uint8_t, prop_val, prop, size_t, (prop ? sizeof(CUmemAllocationProp) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemCreate_exit,
  TP_ARGS(
    CUmemGenericAllocationHandle *, handle,
    size_t, size,
    const CUmemAllocationProp *, prop,
    unsigned long long int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(CUmemGenericAllocationHandle, handle_val, (handle ? *handle : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemRelease_entry,
  TP_ARGS(
    CUmemGenericAllocationHandle, handle
  ),
  TP_FIELDS(
    ctf_integer(CUmemGenericAllocationHandle, handle, handle)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemRelease_exit,
  TP_ARGS(
    CUmemGenericAllocationHandle, handle,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemMap_entry,
  TP_ARGS(
    CUdeviceptr, ptr,
    size_t, size,
    size_t, offset,
    CUmemGenericAllocationHandle, handle,
    unsigned long long int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, ptr, ptr)
    ctf_integer(size_t, size, size)
    ctf_integer(size_t, offset, offset)
    ctf_integer(CUmemGenericAllocationHandle, handle, handle)
    ctf_integer(unsigned long long int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemMap_exit,
  TP_ARGS(
    CUdeviceptr, ptr,
    size_t, size,
    size_t, offset,
    CUmemGenericAllocationHandle, handle,
    unsigned long long int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemMapArrayAsync_ptsz_entry,
  TP_ARGS(
    CUarrayMapInfo *, mapInfoList,
    unsigned int, count,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mapInfoList, (uintptr_t)(mapInfoList))
    ctf_integer(unsigned int, count, count)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_sequence_text(uint8_t, mapInfoList_vals, mapInfoList, size_t, ((mapInfoList ? count : 0)) * sizeof(CUarrayMapInfo))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemMapArrayAsync_ptsz_exit,
  TP_ARGS(
    CUarrayMapInfo *, mapInfoList,
    unsigned int, count,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemUnmap_entry,
  TP_ARGS(
    CUdeviceptr, ptr,
    size_t, size
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, ptr, ptr)
    ctf_integer(size_t, size, size)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemUnmap_exit,
  TP_ARGS(
    CUdeviceptr, ptr,
    size_t, size,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemSetAccess_entry,
  TP_ARGS(
    CUdeviceptr, ptr,
    size_t, size,
    const CUmemAccessDesc *, desc,
    size_t, count
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, ptr, ptr)
    ctf_integer(size_t, size, size)
    ctf_integer_hex(uintptr_t, desc, (uintptr_t)(desc))
    ctf_integer(size_t, count, count)
    ctf_sequence_text(uint8_t, desc_val, desc, size_t, (desc ? sizeof(CUmemAccessDesc) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemSetAccess_exit,
  TP_ARGS(
    CUdeviceptr, ptr,
    size_t, size,
    const CUmemAccessDesc *, desc,
    size_t, count,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemGetAccess_entry,
  TP_ARGS(
    unsigned long long int *, flags,
    const CUmemLocation *, location,
    CUdeviceptr, ptr
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, flags, (uintptr_t)(flags))
    ctf_integer_hex(uintptr_t, location, (uintptr_t)(location))
    ctf_integer_hex(CUdeviceptr, ptr, ptr)
    ctf_sequence_text(uint8_t, location_val, location, size_t, (location ? sizeof(CUmemLocation) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemGetAccess_exit,
  TP_ARGS(
    unsigned long long int *, flags,
    const CUmemLocation *, location,
    CUdeviceptr, ptr,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(unsigned long long int, flags_val, (flags ? *flags : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemExportToShareableHandle_entry,
  TP_ARGS(
    void *, shareableHandle,
    CUmemGenericAllocationHandle, handle,
    CUmemAllocationHandleType, handleType,
    unsigned long long int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, shareableHandle, (uintptr_t)(shareableHandle))
    ctf_integer(CUmemGenericAllocationHandle, handle, handle)
    ctf_integer(int32_t, handleType, handleType)
    ctf_integer(unsigned long long int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemExportToShareableHandle_exit,
  TP_ARGS(
    void *, shareableHandle,
    CUmemGenericAllocationHandle, handle,
    CUmemAllocationHandleType, handleType,
    unsigned long long int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, shareableHandle_val, shareableHandle, size_t, handleType == CU_MEM_HANDLE_TYPE_POSIX_FILE_DESCRIPTOR ? sizeof(int) : 0)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemImportFromShareableHandle_entry,
  TP_ARGS(
    CUmemGenericAllocationHandle *, handle,
    void *, osHandle,
    CUmemAllocationHandleType, shHandleType
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, handle, (uintptr_t)(handle))
    ctf_integer_hex(uintptr_t, osHandle, (uintptr_t)(osHandle))
    ctf_integer(int32_t, shHandleType, shHandleType)
    ctf_sequence_text(uint8_t, osHandle_val, osHandle, size_t, shHandleType == CU_MEM_HANDLE_TYPE_POSIX_FILE_DESCRIPTOR ? sizeof(int) : 0)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemImportFromShareableHandle_exit,
  TP_ARGS(
    CUmemGenericAllocationHandle *, handle,
    void *, osHandle,
    CUmemAllocationHandleType, shHandleType,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(CUmemGenericAllocationHandle, handle_val, (handle ? *handle : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemGetAllocationGranularity_entry,
  TP_ARGS(
    size_t *, granularity,
    const CUmemAllocationProp *, prop,
    CUmemAllocationGranularity_flags, option
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, granularity, (uintptr_t)(granularity))
    ctf_integer_hex(uintptr_t, prop, (uintptr_t)(prop))
    ctf_integer(int32_t, option, option)
    ctf_sequence_text(uint8_t, prop_val, prop, size_t, (prop ? sizeof(CUmemAllocationProp) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemGetAllocationGranularity_exit,
  TP_ARGS(
    size_t *, granularity,
    const CUmemAllocationProp *, prop,
    CUmemAllocationGranularity_flags, option,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(size_t, granularity_val, (granularity ? *granularity : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemGetAllocationPropertiesFromHandle_entry,
  TP_ARGS(
    CUmemAllocationProp *, prop,
    CUmemGenericAllocationHandle, handle
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, prop, (uintptr_t)(prop))
    ctf_integer(CUmemGenericAllocationHandle, handle, handle)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemGetAllocationPropertiesFromHandle_exit,
  TP_ARGS(
    CUmemAllocationProp *, prop,
    CUmemGenericAllocationHandle, handle,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, prop_val, prop, size_t, (prop ? sizeof(CUmemAllocationProp) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemRetainAllocationHandle_entry,
  TP_ARGS(
    CUmemGenericAllocationHandle *, handle,
    void *, addr
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, handle, (uintptr_t)(handle))
    ctf_integer_hex(uintptr_t, addr, (uintptr_t)(addr))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemRetainAllocationHandle_exit,
  TP_ARGS(
    CUmemGenericAllocationHandle *, handle,
    void *, addr,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(CUmemGenericAllocationHandle, handle_val, (handle ? *handle : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemFreeAsync_ptsz_entry,
  TP_ARGS(
    CUdeviceptr, dptr,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dptr, dptr)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemFreeAsync_ptsz_exit,
  TP_ARGS(
    CUdeviceptr, dptr,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemAllocAsync_ptsz_entry,
  TP_ARGS(
    CUdeviceptr *, dptr,
    size_t, bytesize,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dptr, (uintptr_t)(dptr))
    ctf_integer(size_t, bytesize, bytesize)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemAllocAsync_ptsz_exit,
  TP_ARGS(
    CUdeviceptr *, dptr,
    size_t, bytesize,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(CUdeviceptr, dptr_val, (dptr ? *dptr : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemPoolTrimTo_entry,
  TP_ARGS(
    CUmemoryPool, pool,
    size_t, minBytesToKeep
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pool, (uintptr_t)(pool))
    ctf_integer(size_t, minBytesToKeep, minBytesToKeep)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemPoolTrimTo_exit,
  TP_ARGS(
    CUmemoryPool, pool,
    size_t, minBytesToKeep,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemPoolSetAttribute_entry,
  TP_ARGS(
    CUmemoryPool, pool,
    CUmemPool_attribute, attr,
    void *, value
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pool, (uintptr_t)(pool))
    ctf_integer(int32_t, attr, attr)
    ctf_integer_hex(uintptr_t, value, (uintptr_t)(value))
    ctf_sequence_text(uint8_t, value_val, value, size_t, attr == CU_MEMPOOL_ATTR_REUSE_FOLLOW_EVENT_DEPENDENCIES ? sizeof(int) : attr == CU_MEMPOOL_ATTR_REUSE_ALLOW_OPPORTUNISTIC ? sizeof(int) : attr == CU_MEMPOOL_ATTR_REUSE_ALLOW_INTERNAL_DEPENDENCIES ? sizeof(int) : attr == CU_MEMPOOL_ATTR_RELEASE_THRESHOLD ? sizeof(cuuint64_t) : attr == CU_MEMPOOL_ATTR_RESERVED_MEM_HIGH ? sizeof(cuuint64_t) : attr == CU_MEMPOOL_ATTR_USED_MEM_HIGH ? sizeof(cuuint64_t) : 0)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemPoolSetAttribute_exit,
  TP_ARGS(
    CUmemoryPool, pool,
    CUmemPool_attribute, attr,
    void *, value,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemPoolGetAttribute_entry,
  TP_ARGS(
    CUmemoryPool, pool,
    CUmemPool_attribute, attr,
    void *, value
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pool, (uintptr_t)(pool))
    ctf_integer(int32_t, attr, attr)
    ctf_integer_hex(uintptr_t, value, (uintptr_t)(value))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemPoolGetAttribute_exit,
  TP_ARGS(
    CUmemoryPool, pool,
    CUmemPool_attribute, attr,
    void *, value,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, value_val, value, size_t, attr == CU_MEMPOOL_ATTR_REUSE_FOLLOW_EVENT_DEPENDENCIES ? sizeof(int) : attr == CU_MEMPOOL_ATTR_REUSE_ALLOW_OPPORTUNISTIC ? sizeof(int) : attr == CU_MEMPOOL_ATTR_REUSE_ALLOW_INTERNAL_DEPENDENCIES ? sizeof(int) : attr == CU_MEMPOOL_ATTR_RELEASE_THRESHOLD ? sizeof(cuuint64_t) : attr == CU_MEMPOOL_ATTR_RESERVED_MEM_CURRENT ? sizeof(cuuint64_t) : attr == CU_MEMPOOL_ATTR_RESERVED_MEM_HIGH ? sizeof(cuuint64_t) : attr == CU_MEMPOOL_ATTR_USED_MEM_CURRENT ? sizeof(cuuint64_t) : attr == CU_MEMPOOL_ATTR_USED_MEM_HIGH ? sizeof(cuuint64_t) : 0)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemPoolSetAccess_entry,
  TP_ARGS(
    CUmemoryPool, pool,
    const CUmemAccessDesc *, map,
    size_t, count
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pool, (uintptr_t)(pool))
    ctf_integer_hex(uintptr_t, map, (uintptr_t)(map))
    ctf_integer(size_t, count, count)
    ctf_sequence_text(uint8_t, map_vals, map, size_t, ((map ? count : 0)) * sizeof(CUmemAccessDesc))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemPoolSetAccess_exit,
  TP_ARGS(
    CUmemoryPool, pool,
    const CUmemAccessDesc *, map,
    size_t, count,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemPoolGetAccess_entry,
  TP_ARGS(
    CUmemAccess_flags *, flags,
    CUmemoryPool, memPool,
    CUmemLocation *, location
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, flags, (uintptr_t)(flags))
    ctf_integer_hex(uintptr_t, memPool, (uintptr_t)(memPool))
    ctf_integer_hex(uintptr_t, location, (uintptr_t)(location))
    ctf_sequence_text(uint8_t, location_val, location, size_t, (location ? sizeof(CUmemLocation) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemPoolGetAccess_exit,
  TP_ARGS(
    CUmemAccess_flags *, flags,
    CUmemoryPool, memPool,
    CUmemLocation *, location,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int32_t, flags_val, (flags ? *flags : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemPoolCreate_entry,
  TP_ARGS(
    CUmemoryPool *, pool,
    const CUmemPoolProps *, poolProps
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pool, (uintptr_t)(pool))
    ctf_integer_hex(uintptr_t, poolProps, (uintptr_t)(poolProps))
    ctf_sequence_text(uint8_t, poolProps_val, poolProps, size_t, (poolProps ? sizeof(CUmemPoolProps) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemPoolCreate_exit,
  TP_ARGS(
    CUmemoryPool *, pool,
    const CUmemPoolProps *, poolProps,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pool_val, (uintptr_t)((pool ? *pool : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemPoolDestroy_entry,
  TP_ARGS(
    CUmemoryPool, pool
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pool, (uintptr_t)(pool))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemPoolDestroy_exit,
  TP_ARGS(
    CUmemoryPool, pool,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemGetDefaultMemPool_entry,
  TP_ARGS(
    CUmemoryPool *, pool_out,
    CUmemLocation *, location,
    CUmemAllocationType, type
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pool_out, (uintptr_t)(pool_out))
    ctf_integer_hex(uintptr_t, location, (uintptr_t)(location))
    ctf_integer(int32_t, type, type)
    ctf_sequence_text(uint8_t, location_val, location, size_t, (location ? sizeof(CUmemLocation) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemGetDefaultMemPool_exit,
  TP_ARGS(
    CUmemoryPool *, pool_out,
    CUmemLocation *, location,
    CUmemAllocationType, type,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pool_out_val, (uintptr_t)((pool_out ? *pool_out : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemGetMemPool_entry,
  TP_ARGS(
    CUmemoryPool *, pool,
    CUmemLocation *, location,
    CUmemAllocationType, type
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pool, (uintptr_t)(pool))
    ctf_integer_hex(uintptr_t, location, (uintptr_t)(location))
    ctf_integer(int32_t, type, type)
    ctf_sequence_text(uint8_t, location_val, location, size_t, (location ? sizeof(CUmemLocation) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemGetMemPool_exit,
  TP_ARGS(
    CUmemoryPool *, pool,
    CUmemLocation *, location,
    CUmemAllocationType, type,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pool_val, (uintptr_t)((pool ? *pool : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemSetMemPool_entry,
  TP_ARGS(
    CUmemLocation *, location,
    CUmemAllocationType, type,
    CUmemoryPool, pool
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, location, (uintptr_t)(location))
    ctf_integer(int32_t, type, type)
    ctf_integer_hex(uintptr_t, pool, (uintptr_t)(pool))
    ctf_sequence_text(uint8_t, location_val, location, size_t, (location ? sizeof(CUmemLocation) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemSetMemPool_exit,
  TP_ARGS(
    CUmemLocation *, location,
    CUmemAllocationType, type,
    CUmemoryPool, pool,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemAllocFromPoolAsync_ptsz_entry,
  TP_ARGS(
    CUdeviceptr *, dptr,
    size_t, bytesize,
    CUmemoryPool, pool,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dptr, (uintptr_t)(dptr))
    ctf_integer(size_t, bytesize, bytesize)
    ctf_integer_hex(uintptr_t, pool, (uintptr_t)(pool))
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemAllocFromPoolAsync_ptsz_exit,
  TP_ARGS(
    CUdeviceptr *, dptr,
    size_t, bytesize,
    CUmemoryPool, pool,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(CUdeviceptr, dptr_val, (dptr ? *dptr : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemPoolExportToShareableHandle_entry,
  TP_ARGS(
    void *, handle_out,
    CUmemoryPool, pool,
    CUmemAllocationHandleType, handleType,
    unsigned long long int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, handle_out, (uintptr_t)(handle_out))
    ctf_integer_hex(uintptr_t, pool, (uintptr_t)(pool))
    ctf_integer(int32_t, handleType, handleType)
    ctf_integer(unsigned long long int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemPoolExportToShareableHandle_exit,
  TP_ARGS(
    void *, handle_out,
    CUmemoryPool, pool,
    CUmemAllocationHandleType, handleType,
    unsigned long long int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, handle_out_val, handle_out, size_t, handleType == CU_MEM_HANDLE_TYPE_POSIX_FILE_DESCRIPTOR ? sizeof(int) : 0)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemPoolImportFromShareableHandle_entry,
  TP_ARGS(
    CUmemoryPool *, pool_out,
    void *, handle,
    CUmemAllocationHandleType, handleType,
    unsigned long long int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pool_out, (uintptr_t)(pool_out))
    ctf_integer_hex(uintptr_t, handle, (uintptr_t)(handle))
    ctf_integer(int32_t, handleType, handleType)
    ctf_integer(unsigned long long int, flags, flags)
    ctf_sequence_text(uint8_t, handle_val, handle, size_t, handleType == CU_MEM_HANDLE_TYPE_POSIX_FILE_DESCRIPTOR ? sizeof(int) : 0)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemPoolImportFromShareableHandle_exit,
  TP_ARGS(
    CUmemoryPool *, pool_out,
    void *, handle,
    CUmemAllocationHandleType, handleType,
    unsigned long long int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pool_out_val, (uintptr_t)((pool_out ? *pool_out : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemPoolExportPointer_entry,
  TP_ARGS(
    CUmemPoolPtrExportData *, shareData_out,
    CUdeviceptr, ptr
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, shareData_out, (uintptr_t)(shareData_out))
    ctf_integer_hex(CUdeviceptr, ptr, ptr)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemPoolExportPointer_exit,
  TP_ARGS(
    CUmemPoolPtrExportData *, shareData_out,
    CUdeviceptr, ptr,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, shareData_out_val, shareData_out, size_t, (shareData_out ? sizeof(CUmemPoolPtrExportData) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemPoolImportPointer_entry,
  TP_ARGS(
    CUdeviceptr *, ptr_out,
    CUmemoryPool, pool,
    CUmemPoolPtrExportData *, shareData
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ptr_out, (uintptr_t)(ptr_out))
    ctf_integer_hex(uintptr_t, pool, (uintptr_t)(pool))
    ctf_integer_hex(uintptr_t, shareData, (uintptr_t)(shareData))
    ctf_sequence_text(uint8_t, shareData_val, shareData, size_t, (shareData ? sizeof(CUmemPoolPtrExportData) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemPoolImportPointer_exit,
  TP_ARGS(
    CUdeviceptr *, ptr_out,
    CUmemoryPool, pool,
    CUmemPoolPtrExportData *, shareData,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(CUdeviceptr, ptr_out_val, (ptr_out ? *ptr_out : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMulticastCreate_entry,
  TP_ARGS(
    CUmemGenericAllocationHandle *, mcHandle,
    const CUmulticastObjectProp *, prop
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mcHandle, (uintptr_t)(mcHandle))
    ctf_integer_hex(uintptr_t, prop, (uintptr_t)(prop))
    ctf_sequence_text(uint8_t, prop_val, prop, size_t, (prop ? sizeof(CUmulticastObjectProp) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMulticastCreate_exit,
  TP_ARGS(
    CUmemGenericAllocationHandle *, mcHandle,
    const CUmulticastObjectProp *, prop,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(CUmemGenericAllocationHandle, mcHandle_val, (mcHandle ? *mcHandle : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMulticastAddDevice_entry,
  TP_ARGS(
    CUmemGenericAllocationHandle, mcHandle,
    CUdevice, dev
  ),
  TP_FIELDS(
    ctf_integer(CUmemGenericAllocationHandle, mcHandle, mcHandle)
    ctf_integer(CUdevice, dev, dev)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMulticastAddDevice_exit,
  TP_ARGS(
    CUmemGenericAllocationHandle, mcHandle,
    CUdevice, dev,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMulticastBindMem_entry,
  TP_ARGS(
    CUmemGenericAllocationHandle, mcHandle,
    size_t, mcOffset,
    CUmemGenericAllocationHandle, memHandle,
    size_t, memOffset,
    size_t, size,
    unsigned long long int, flags
  ),
  TP_FIELDS(
    ctf_integer(CUmemGenericAllocationHandle, mcHandle, mcHandle)
    ctf_integer(size_t, mcOffset, mcOffset)
    ctf_integer(CUmemGenericAllocationHandle, memHandle, memHandle)
    ctf_integer(size_t, memOffset, memOffset)
    ctf_integer(size_t, size, size)
    ctf_integer(unsigned long long int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMulticastBindMem_exit,
  TP_ARGS(
    CUmemGenericAllocationHandle, mcHandle,
    size_t, mcOffset,
    CUmemGenericAllocationHandle, memHandle,
    size_t, memOffset,
    size_t, size,
    unsigned long long int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMulticastBindAddr_entry,
  TP_ARGS(
    CUmemGenericAllocationHandle, mcHandle,
    size_t, mcOffset,
    CUdeviceptr, memptr,
    size_t, size,
    unsigned long long int, flags
  ),
  TP_FIELDS(
    ctf_integer(CUmemGenericAllocationHandle, mcHandle, mcHandle)
    ctf_integer(size_t, mcOffset, mcOffset)
    ctf_integer_hex(CUdeviceptr, memptr, memptr)
    ctf_integer(size_t, size, size)
    ctf_integer(unsigned long long int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMulticastBindAddr_exit,
  TP_ARGS(
    CUmemGenericAllocationHandle, mcHandle,
    size_t, mcOffset,
    CUdeviceptr, memptr,
    size_t, size,
    unsigned long long int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMulticastUnbind_entry,
  TP_ARGS(
    CUmemGenericAllocationHandle, mcHandle,
    CUdevice, dev,
    size_t, mcOffset,
    size_t, size
  ),
  TP_FIELDS(
    ctf_integer(CUmemGenericAllocationHandle, mcHandle, mcHandle)
    ctf_integer(CUdevice, dev, dev)
    ctf_integer(size_t, mcOffset, mcOffset)
    ctf_integer(size_t, size, size)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMulticastUnbind_exit,
  TP_ARGS(
    CUmemGenericAllocationHandle, mcHandle,
    CUdevice, dev,
    size_t, mcOffset,
    size_t, size,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMulticastGetGranularity_entry,
  TP_ARGS(
    size_t *, granularity,
    const CUmulticastObjectProp *, prop,
    CUmulticastGranularity_flags, option
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, granularity, (uintptr_t)(granularity))
    ctf_integer_hex(uintptr_t, prop, (uintptr_t)(prop))
    ctf_integer(int32_t, option, option)
    ctf_sequence_text(uint8_t, prop_val, prop, size_t, (prop ? sizeof(CUmulticastObjectProp) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMulticastGetGranularity_exit,
  TP_ARGS(
    size_t *, granularity,
    const CUmulticastObjectProp *, prop,
    CUmulticastGranularity_flags, option,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(size_t, granularity_val, (granularity ? *granularity : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuPointerGetAttribute_entry,
  TP_ARGS(
    void *, data,
    CUpointer_attribute, attribute,
    CUdeviceptr, ptr
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, data, (uintptr_t)(data))
    ctf_integer(int32_t, attribute, attribute)
    ctf_integer_hex(CUdeviceptr, ptr, ptr)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuPointerGetAttribute_exit,
  TP_ARGS(
    void *, data,
    CUpointer_attribute, attribute,
    CUdeviceptr, ptr,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, data_val, data, size_t, attribute == CU_POINTER_ATTRIBUTE_CONTEXT ? sizeof(CUcontext) : attribute == CU_POINTER_ATTRIBUTE_MEMORY_TYPE ? sizeof(unsigned int) : attribute == CU_POINTER_ATTRIBUTE_DEVICE_POINTER ? sizeof(CUdeviceptr) : attribute == CU_POINTER_ATTRIBUTE_HOST_POINTER ? sizeof(void *) : attribute == CU_POINTER_ATTRIBUTE_P2P_TOKENS ? sizeof(CUDA_POINTER_ATTRIBUTE_P2P_TOKENS) : attribute == CU_POINTER_ATTRIBUTE_SYNC_MEMOPS ? sizeof(int) : attribute == CU_POINTER_ATTRIBUTE_BUFFER_ID ? sizeof(unsigned long long) : attribute == CU_POINTER_ATTRIBUTE_IS_MANAGED ? sizeof(int) : attribute == CU_POINTER_ATTRIBUTE_DEVICE_ORDINAL ? sizeof(int) : attribute == CU_POINTER_ATTRIBUTE_IS_LEGACY_CUDA_IPC_CAPABLE ? sizeof(int) : attribute == CU_POINTER_ATTRIBUTE_RANGE_START_ADDR ? sizeof(void *) : attribute == CU_POINTER_ATTRIBUTE_RANGE_SIZE ? sizeof(size_t) : attribute == CU_POINTER_ATTRIBUTE_MAPPED ? sizeof(int) : attribute == CU_POINTER_ATTRIBUTE_ALLOWED_HANDLE_TYPES ? sizeof(CUmemAllocationHandleType) : attribute == CU_POINTER_ATTRIBUTE_IS_GPU_DIRECT_RDMA_CAPABLE ? sizeof(int) : attribute == CU_POINTER_ATTRIBUTE_ACCESS_FLAGS ? sizeof(CUDA_POINTER_ATTRIBUTE_ACCESS_FLAGS) : attribute == CU_POINTER_ATTRIBUTE_MEMPOOL_HANDLE ? sizeof(CUmemoryPool) : attribute == CU_POINTER_ATTRIBUTE_MAPPING_SIZE ? sizeof(size_t) : attribute == CU_POINTER_ATTRIBUTE_MAPPING_BASE_ADDR ? sizeof(void *) : attribute == CU_POINTER_ATTRIBUTE_MEMORY_BLOCK_ID ? sizeof(unsigned long long) : 0)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemPrefetchAsync_v2_ptsz_entry,
  TP_ARGS(
    CUdeviceptr, devPtr,
    size_t, count,
    CUmemLocation, location,
    unsigned int, flags,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, devPtr, devPtr)
    ctf_integer(size_t, count, count)
    ctf_array_text(uint8_t, location, &location, sizeof(CUmemLocation))
    ctf_integer(unsigned int, flags, flags)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemPrefetchAsync_v2_ptsz_exit,
  TP_ARGS(
    CUdeviceptr, devPtr,
    size_t, count,
    CUmemLocation, location,
    unsigned int, flags,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemAdvise_v2_entry,
  TP_ARGS(
    CUdeviceptr, devPtr,
    size_t, count,
    CUmem_advise, advice,
    CUmemLocation, location
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, devPtr, devPtr)
    ctf_integer(size_t, count, count)
    ctf_integer(int32_t, advice, advice)
    ctf_array_text(uint8_t, location, &location, sizeof(CUmemLocation))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemAdvise_v2_exit,
  TP_ARGS(
    CUdeviceptr, devPtr,
    size_t, count,
    CUmem_advise, advice,
    CUmemLocation, location,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemPrefetchBatchAsync_ptsz_entry,
  TP_ARGS(
    CUdeviceptr *, dptrs,
    size_t *, sizes,
    size_t, count,
    CUmemLocation *, prefetchLocs,
    size_t *, prefetchLocIdxs,
    size_t, numPrefetchLocs,
    unsigned long long int, flags,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dptrs, (uintptr_t)(dptrs))
    ctf_integer_hex(uintptr_t, sizes, (uintptr_t)(sizes))
    ctf_integer(size_t, count, count)
    ctf_integer_hex(uintptr_t, prefetchLocs, (uintptr_t)(prefetchLocs))
    ctf_integer_hex(uintptr_t, prefetchLocIdxs, (uintptr_t)(prefetchLocIdxs))
    ctf_integer(size_t, numPrefetchLocs, numPrefetchLocs)
    ctf_integer(unsigned long long int, flags, flags)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_sequence_hex(CUdeviceptr, dptrs_vals, dptrs, size_t, (dptrs ? count : 0))
    ctf_sequence(size_t, sizes_vals, sizes, size_t, (sizes ? count : 0))
    ctf_sequence_text(uint8_t, prefetchLocs_vals, prefetchLocs, size_t, ((prefetchLocs ? numPrefetchLocs : 0)) * sizeof(CUmemLocation))
    ctf_sequence(size_t, prefetchLocIdxs_vals, prefetchLocIdxs, size_t, (prefetchLocIdxs ? numPrefetchLocs : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemPrefetchBatchAsync_ptsz_exit,
  TP_ARGS(
    CUdeviceptr *, dptrs,
    size_t *, sizes,
    size_t, count,
    CUmemLocation *, prefetchLocs,
    size_t *, prefetchLocIdxs,
    size_t, numPrefetchLocs,
    unsigned long long int, flags,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemDiscardBatchAsync_ptsz_entry,
  TP_ARGS(
    CUdeviceptr *, dptrs,
    size_t *, sizes,
    size_t, count,
    unsigned long long int, flags,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dptrs, (uintptr_t)(dptrs))
    ctf_integer_hex(uintptr_t, sizes, (uintptr_t)(sizes))
    ctf_integer(size_t, count, count)
    ctf_integer(unsigned long long int, flags, flags)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_sequence_hex(CUdeviceptr, dptrs_vals, dptrs, size_t, (dptrs ? count : 0))
    ctf_sequence(size_t, sizes_vals, sizes, size_t, (sizes ? count : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemDiscardBatchAsync_ptsz_exit,
  TP_ARGS(
    CUdeviceptr *, dptrs,
    size_t *, sizes,
    size_t, count,
    unsigned long long int, flags,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemDiscardAndPrefetchBatchAsync_ptsz_entry,
  TP_ARGS(
    CUdeviceptr *, dptrs,
    size_t *, sizes,
    size_t, count,
    CUmemLocation *, prefetchLocs,
    size_t *, prefetchLocIdxs,
    size_t, numPrefetchLocs,
    unsigned long long int, flags,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dptrs, (uintptr_t)(dptrs))
    ctf_integer_hex(uintptr_t, sizes, (uintptr_t)(sizes))
    ctf_integer(size_t, count, count)
    ctf_integer_hex(uintptr_t, prefetchLocs, (uintptr_t)(prefetchLocs))
    ctf_integer_hex(uintptr_t, prefetchLocIdxs, (uintptr_t)(prefetchLocIdxs))
    ctf_integer(size_t, numPrefetchLocs, numPrefetchLocs)
    ctf_integer(unsigned long long int, flags, flags)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_sequence_hex(CUdeviceptr, dptrs_vals, dptrs, size_t, (dptrs ? count : 0))
    ctf_sequence(size_t, sizes_vals, sizes, size_t, (sizes ? count : 0))
    ctf_sequence_text(uint8_t, prefetchLocs_vals, prefetchLocs, size_t, ((prefetchLocs ? numPrefetchLocs : 0)) * sizeof(CUmemLocation))
    ctf_sequence(size_t, prefetchLocIdxs_vals, prefetchLocIdxs, size_t, (prefetchLocIdxs ? numPrefetchLocs : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemDiscardAndPrefetchBatchAsync_ptsz_exit,
  TP_ARGS(
    CUdeviceptr *, dptrs,
    size_t *, sizes,
    size_t, count,
    CUmemLocation *, prefetchLocs,
    size_t *, prefetchLocIdxs,
    size_t, numPrefetchLocs,
    unsigned long long int, flags,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemRangeGetAttribute_entry,
  TP_ARGS(
    void *, data,
    size_t, dataSize,
    CUmem_range_attribute, attribute,
    CUdeviceptr, devPtr,
    size_t, count
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, data, (uintptr_t)(data))
    ctf_integer(size_t, dataSize, dataSize)
    ctf_integer(int32_t, attribute, attribute)
    ctf_integer_hex(CUdeviceptr, devPtr, devPtr)
    ctf_integer(size_t, count, count)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemRangeGetAttribute_exit,
  TP_ARGS(
    void *, data,
    size_t, dataSize,
    CUmem_range_attribute, attribute,
    CUdeviceptr, devPtr,
    size_t, count,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, data_vals, data, size_t, ((data ? dataSize : 0)) * sizeof(uint8_t))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemRangeGetAttributes_entry,
  TP_ARGS(
    void **, data,
    size_t *, dataSizes,
    CUmem_range_attribute *, attributes,
    size_t, numAttributes,
    CUdeviceptr, devPtr,
    size_t, count
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, data, (uintptr_t)(data))
    ctf_integer_hex(uintptr_t, dataSizes, (uintptr_t)(dataSizes))
    ctf_integer_hex(uintptr_t, attributes, (uintptr_t)(attributes))
    ctf_integer(size_t, numAttributes, numAttributes)
    ctf_integer_hex(CUdeviceptr, devPtr, devPtr)
    ctf_integer(size_t, count, count)
    ctf_sequence(int32_t, attributes_vals, attributes, size_t, (attributes ? numAttributes : 0))
    ctf_sequence(size_t, dataSizes_vals, dataSizes, size_t, (dataSizes ? numAttributes : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemRangeGetAttributes_exit,
  TP_ARGS(
    void **, data,
    size_t *, dataSizes,
    CUmem_range_attribute *, attributes,
    size_t, numAttributes,
    CUdeviceptr, devPtr,
    size_t, count,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuPointerSetAttribute_entry,
  TP_ARGS(
    const void *, value,
    CUpointer_attribute, attribute,
    CUdeviceptr, ptr
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, value, (uintptr_t)(value))
    ctf_integer(int32_t, attribute, attribute)
    ctf_integer_hex(CUdeviceptr, ptr, ptr)
    ctf_sequence_text(uint8_t, value_val, value, size_t, attribute == CU_POINTER_ATTRIBUTE_SYNC_MEMOPS ? sizeof(uint8_t) : 0)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuPointerSetAttribute_exit,
  TP_ARGS(
    const void *, value,
    CUpointer_attribute, attribute,
    CUdeviceptr, ptr,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuPointerGetAttributes_entry,
  TP_ARGS(
    unsigned int, numAttributes,
    CUpointer_attribute *, attributes,
    void **, data,
    CUdeviceptr, ptr
  ),
  TP_FIELDS(
    ctf_integer(unsigned int, numAttributes, numAttributes)
    ctf_integer_hex(uintptr_t, attributes, (uintptr_t)(attributes))
    ctf_integer_hex(uintptr_t, data, (uintptr_t)(data))
    ctf_integer_hex(CUdeviceptr, ptr, ptr)
    ctf_sequence(int32_t, attributes_vals, attributes, unsigned int, (attributes ? numAttributes : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuPointerGetAttributes_exit,
  TP_ARGS(
    unsigned int, numAttributes,
    CUpointer_attribute *, attributes,
    void **, data,
    CUdeviceptr, ptr,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_hex(uintptr_t, data_vals, data, unsigned int, (data ? numAttributes : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamCreate_entry,
  TP_ARGS(
    CUstream *, phStream,
    unsigned int, Flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, phStream, (uintptr_t)(phStream))
    ctf_integer(unsigned int, Flags, Flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamCreate_exit,
  TP_ARGS(
    CUstream *, phStream,
    unsigned int, Flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phStream_val, (uintptr_t)((phStream ? *phStream : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamCreateWithPriority_entry,
  TP_ARGS(
    CUstream *, phStream,
    unsigned int, flags,
    int, priority
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, phStream, (uintptr_t)(phStream))
    ctf_integer(unsigned int, flags, flags)
    ctf_integer(int, priority, priority)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamCreateWithPriority_exit,
  TP_ARGS(
    CUstream *, phStream,
    unsigned int, flags,
    int, priority,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phStream_val, (uintptr_t)((phStream ? *phStream : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetPriority_ptsz_entry,
  TP_ARGS(
    CUstream, hStream,
    int *, priority
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, priority, (uintptr_t)(priority))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetPriority_ptsz_exit,
  TP_ARGS(
    CUstream, hStream,
    int *, priority,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int, priority_val, (priority ? *priority : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetDevice_ptsz_entry,
  TP_ARGS(
    CUstream, hStream,
    CUdevice *, device
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, device, (uintptr_t)(device))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetDevice_ptsz_exit,
  TP_ARGS(
    CUstream, hStream,
    CUdevice *, device,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(CUdevice, device_val, (device ? *device : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetFlags_ptsz_entry,
  TP_ARGS(
    CUstream, hStream,
    unsigned int *, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, flags, (uintptr_t)(flags))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetFlags_ptsz_exit,
  TP_ARGS(
    CUstream, hStream,
    unsigned int *, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(unsigned int, flags_val, (flags ? *flags : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetId_ptsz_entry,
  TP_ARGS(
    CUstream, hStream,
    unsigned long long int *, streamId
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, streamId, (uintptr_t)(streamId))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetId_ptsz_exit,
  TP_ARGS(
    CUstream, hStream,
    unsigned long long int *, streamId,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(unsigned long long int, streamId_val, (streamId ? *streamId : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetCtx_ptsz_entry,
  TP_ARGS(
    CUstream, hStream,
    CUcontext *, pctx
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, pctx, (uintptr_t)(pctx))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetCtx_ptsz_exit,
  TP_ARGS(
    CUstream, hStream,
    CUcontext *, pctx,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pctx_val, (uintptr_t)((pctx ? *pctx : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetCtx_v2_ptsz_entry,
  TP_ARGS(
    CUstream, hStream,
    CUcontext *, pCtx,
    CUgreenCtx *, pGreenCtx
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, pCtx, (uintptr_t)(pCtx))
    ctf_integer_hex(uintptr_t, pGreenCtx, (uintptr_t)(pGreenCtx))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetCtx_v2_ptsz_exit,
  TP_ARGS(
    CUstream, hStream,
    CUcontext *, pCtx,
    CUgreenCtx *, pGreenCtx,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pCtx_val, (uintptr_t)((pCtx ? *pCtx : 0)))
    ctf_integer_hex(uintptr_t, pGreenCtx_val, (uintptr_t)((pGreenCtx ? *pGreenCtx : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamWaitEvent_ptsz_entry,
  TP_ARGS(
    CUstream, hStream,
    CUevent, hEvent,
    unsigned int, Flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, hEvent, (uintptr_t)(hEvent))
    ctf_integer(unsigned int, Flags, Flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamWaitEvent_ptsz_exit,
  TP_ARGS(
    CUstream, hStream,
    CUevent, hEvent,
    unsigned int, Flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamAddCallback_ptsz_entry,
  TP_ARGS(
    CUstream, hStream,
    CUstreamCallback, callback,
    void *, userData,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, callback, (uintptr_t)(callback))
    ctf_integer_hex(uintptr_t, userData, (uintptr_t)(userData))
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamAddCallback_ptsz_exit,
  TP_ARGS(
    CUstream, hStream,
    CUstreamCallback, callback,
    void *, userData,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamBeginCapture_v2_ptsz_entry,
  TP_ARGS(
    CUstream, hStream,
    CUstreamCaptureMode, mode
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer(int32_t, mode, mode)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamBeginCapture_v2_ptsz_exit,
  TP_ARGS(
    CUstream, hStream,
    CUstreamCaptureMode, mode,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamBeginCaptureToGraph_ptsz_entry,
  TP_ARGS(
    CUstream, hStream,
    CUgraph, hGraph,
    const CUgraphNode *, dependencies,
    const CUgraphEdgeData *, dependencyData,
    size_t, numDependencies,
    CUstreamCaptureMode, mode
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, dependencies, (uintptr_t)(dependencies))
    ctf_integer_hex(uintptr_t, dependencyData, (uintptr_t)(dependencyData))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer(int32_t, mode, mode)
    ctf_sequence_hex(uintptr_t, dependencies_vals, dependencies, size_t, (dependencies ? numDependencies : 0))
    ctf_sequence_text(uint8_t, dependencyData_vals, dependencyData, size_t, ((dependencyData ? numDependencies : 0)) * sizeof(CUgraphEdgeData))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamBeginCaptureToGraph_ptsz_exit,
  TP_ARGS(
    CUstream, hStream,
    CUgraph, hGraph,
    const CUgraphNode *, dependencies,
    const CUgraphEdgeData *, dependencyData,
    size_t, numDependencies,
    CUstreamCaptureMode, mode,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuThreadExchangeStreamCaptureMode_entry,
  TP_ARGS(
    CUstreamCaptureMode *, mode
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mode, (uintptr_t)(mode))
    ctf_integer(int32_t, mode_val, (mode ? *mode : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuThreadExchangeStreamCaptureMode_exit,
  TP_ARGS(
    CUstreamCaptureMode *, mode,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int32_t, mode_val, (mode ? *mode : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamEndCapture_ptsz_entry,
  TP_ARGS(
    CUstream, hStream,
    CUgraph *, phGraph
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, phGraph, (uintptr_t)(phGraph))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamEndCapture_ptsz_exit,
  TP_ARGS(
    CUstream, hStream,
    CUgraph *, phGraph,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phGraph_val, (uintptr_t)((phGraph ? *phGraph : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamIsCapturing_ptsz_entry,
  TP_ARGS(
    CUstream, hStream,
    CUstreamCaptureStatus *, captureStatus
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, captureStatus, (uintptr_t)(captureStatus))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamIsCapturing_ptsz_exit,
  TP_ARGS(
    CUstream, hStream,
    CUstreamCaptureStatus *, captureStatus,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int32_t, captureStatus_val, (captureStatus ? *captureStatus : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetCaptureInfo_v3_ptsz_entry,
  TP_ARGS(
    CUstream, hStream,
    CUstreamCaptureStatus *, captureStatus_out,
    cuuint64_t *, id_out,
    CUgraph *, graph_out,
    const CUgraphNode **, dependencies_out,
    const CUgraphEdgeData **, edgeData_out,
    size_t *, numDependencies_out
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, captureStatus_out, (uintptr_t)(captureStatus_out))
    ctf_integer_hex(uintptr_t, id_out, (uintptr_t)(id_out))
    ctf_integer_hex(uintptr_t, graph_out, (uintptr_t)(graph_out))
    ctf_integer_hex(uintptr_t, dependencies_out, (uintptr_t)(dependencies_out))
    ctf_integer_hex(uintptr_t, edgeData_out, (uintptr_t)(edgeData_out))
    ctf_integer_hex(uintptr_t, numDependencies_out, (uintptr_t)(numDependencies_out))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetCaptureInfo_v3_ptsz_exit,
  TP_ARGS(
    CUstream, hStream,
    CUstreamCaptureStatus *, captureStatus_out,
    cuuint64_t *, id_out,
    CUgraph *, graph_out,
    const CUgraphNode **, dependencies_out,
    const CUgraphEdgeData **, edgeData_out,
    size_t *, numDependencies_out,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int32_t, captureStatus_out_val, (captureStatus_out ? *captureStatus_out : 0))
    ctf_integer(cuuint64_t, id_out_val, (id_out ? *id_out : 0))
    ctf_integer_hex(uintptr_t, graph_out_val, (uintptr_t)((graph_out ? *graph_out : 0)))
    ctf_integer(size_t, numDependencies_out_val, (numDependencies_out ? *numDependencies_out : 0))
    ctf_sequence_hex(uintptr_t, dependencies_out_val_vals, *dependencies_out, size_t, (numDependencies_out && dependencies_out && *dependencies_out ? *numDependencies_out : 0))
    ctf_sequence_text(uint8_t, edgeData_out_val_vals, *edgeData_out, size_t, ((numDependencies_out && edgeData_out && *edgeData_out ? *numDependencies_out : 0)) * sizeof(CUgraphEdgeData))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamUpdateCaptureDependencies_v2_ptsz_entry,
  TP_ARGS(
    CUstream, hStream,
    CUgraphNode *, dependencies,
    const CUgraphEdgeData *, dependencyData,
    size_t, numDependencies,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, dependencies, (uintptr_t)(dependencies))
    ctf_integer_hex(uintptr_t, dependencyData, (uintptr_t)(dependencyData))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer(unsigned int, flags, flags)
    ctf_sequence_hex(uintptr_t, dependencies_vals, dependencies, size_t, (dependencies ? numDependencies : 0))
    ctf_sequence_text(uint8_t, dependencyData_vals, dependencyData, size_t, ((dependencyData ? numDependencies : 0)) * sizeof(CUgraphEdgeData))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamUpdateCaptureDependencies_v2_ptsz_exit,
  TP_ARGS(
    CUstream, hStream,
    CUgraphNode *, dependencies,
    const CUgraphEdgeData *, dependencyData,
    size_t, numDependencies,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamAttachMemAsync_ptsz_entry,
  TP_ARGS(
    CUstream, hStream,
    CUdeviceptr, dptr,
    size_t, length,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(CUdeviceptr, dptr, dptr)
    ctf_integer(size_t, length, length)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamAttachMemAsync_ptsz_exit,
  TP_ARGS(
    CUstream, hStream,
    CUdeviceptr, dptr,
    size_t, length,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamQuery_ptsz_entry,
  TP_ARGS(
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamQuery_ptsz_exit,
  TP_ARGS(
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamSynchronize_ptsz_entry,
  TP_ARGS(
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamSynchronize_ptsz_exit,
  TP_ARGS(
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamDestroy_v2_entry,
  TP_ARGS(
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamDestroy_v2_exit,
  TP_ARGS(
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamCopyAttributes_ptsz_entry,
  TP_ARGS(
    CUstream, dst,
    CUstream, src
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamCopyAttributes_ptsz_exit,
  TP_ARGS(
    CUstream, dst,
    CUstream, src,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetAttribute_ptsz_entry,
  TP_ARGS(
    CUstream, hStream,
    CUstreamAttrID, attr,
    CUstreamAttrValue *, value_out
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer(int32_t, attr, attr)
    ctf_integer_hex(uintptr_t, value_out, (uintptr_t)(value_out))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetAttribute_ptsz_exit,
  TP_ARGS(
    CUstream, hStream,
    CUstreamAttrID, attr,
    CUstreamAttrValue *, value_out,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, value_out_val, value_out, size_t, (value_out ? sizeof(CUstreamAttrValue) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamSetAttribute_ptsz_entry,
  TP_ARGS(
    CUstream, hStream,
    CUstreamAttrID, attr,
    const CUstreamAttrValue *, value
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer(int32_t, attr, attr)
    ctf_integer_hex(uintptr_t, value, (uintptr_t)(value))
    ctf_sequence_text(uint8_t, value_val, value, size_t, (value ? sizeof(CUstreamAttrValue) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamSetAttribute_ptsz_exit,
  TP_ARGS(
    CUstream, hStream,
    CUstreamAttrID, attr,
    const CUstreamAttrValue *, value,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuEventCreate_entry,
  TP_ARGS(
    CUevent *, phEvent,
    unsigned int, Flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, phEvent, (uintptr_t)(phEvent))
    ctf_integer(unsigned int, Flags, Flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuEventCreate_exit,
  TP_ARGS(
    CUevent *, phEvent,
    unsigned int, Flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phEvent_val, (uintptr_t)((phEvent ? *phEvent : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuEventRecord_ptsz_entry,
  TP_ARGS(
    CUevent, hEvent,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hEvent, (uintptr_t)(hEvent))
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuEventRecord_ptsz_exit,
  TP_ARGS(
    CUevent, hEvent,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuEventRecordWithFlags_ptsz_entry,
  TP_ARGS(
    CUevent, hEvent,
    CUstream, hStream,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hEvent, (uintptr_t)(hEvent))
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuEventRecordWithFlags_ptsz_exit,
  TP_ARGS(
    CUevent, hEvent,
    CUstream, hStream,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuEventQuery_entry,
  TP_ARGS(
    CUevent, hEvent
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hEvent, (uintptr_t)(hEvent))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuEventQuery_exit,
  TP_ARGS(
    CUevent, hEvent,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuEventSynchronize_entry,
  TP_ARGS(
    CUevent, hEvent
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hEvent, (uintptr_t)(hEvent))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuEventSynchronize_exit,
  TP_ARGS(
    CUevent, hEvent,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuEventDestroy_v2_entry,
  TP_ARGS(
    CUevent, hEvent
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hEvent, (uintptr_t)(hEvent))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuEventDestroy_v2_exit,
  TP_ARGS(
    CUevent, hEvent,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuEventElapsedTime_v2_entry,
  TP_ARGS(
    float *, pMilliseconds,
    CUevent, hStart,
    CUevent, hEnd
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pMilliseconds, (uintptr_t)(pMilliseconds))
    ctf_integer_hex(uintptr_t, hStart, (uintptr_t)(hStart))
    ctf_integer_hex(uintptr_t, hEnd, (uintptr_t)(hEnd))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuEventElapsedTime_v2_exit,
  TP_ARGS(
    float *, pMilliseconds,
    CUevent, hStart,
    CUevent, hEnd,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_float(float, pMilliseconds_val, (pMilliseconds ? *pMilliseconds : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuImportExternalMemory_entry,
  TP_ARGS(
    CUexternalMemory *, extMem_out,
    const CUDA_EXTERNAL_MEMORY_HANDLE_DESC *, memHandleDesc
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, extMem_out, (uintptr_t)(extMem_out))
    ctf_integer_hex(uintptr_t, memHandleDesc, (uintptr_t)(memHandleDesc))
    ctf_sequence_text(uint8_t, memHandleDesc_val, memHandleDesc, size_t, (memHandleDesc ? sizeof(CUDA_EXTERNAL_MEMORY_HANDLE_DESC) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuImportExternalMemory_exit,
  TP_ARGS(
    CUexternalMemory *, extMem_out,
    const CUDA_EXTERNAL_MEMORY_HANDLE_DESC *, memHandleDesc,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, extMem_out_val, (uintptr_t)((extMem_out ? *extMem_out : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuExternalMemoryGetMappedBuffer_entry,
  TP_ARGS(
    CUdeviceptr *, devPtr,
    CUexternalMemory, extMem,
    const CUDA_EXTERNAL_MEMORY_BUFFER_DESC *, bufferDesc
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, devPtr, (uintptr_t)(devPtr))
    ctf_integer_hex(uintptr_t, extMem, (uintptr_t)(extMem))
    ctf_integer_hex(uintptr_t, bufferDesc, (uintptr_t)(bufferDesc))
    ctf_sequence_text(uint8_t, bufferDesc_val, bufferDesc, size_t, (bufferDesc ? sizeof(CUDA_EXTERNAL_MEMORY_BUFFER_DESC) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuExternalMemoryGetMappedBuffer_exit,
  TP_ARGS(
    CUdeviceptr *, devPtr,
    CUexternalMemory, extMem,
    const CUDA_EXTERNAL_MEMORY_BUFFER_DESC *, bufferDesc,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(CUdeviceptr, devPtr_val, (devPtr ? *devPtr : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuExternalMemoryGetMappedMipmappedArray_entry,
  TP_ARGS(
    CUmipmappedArray *, mipmap,
    CUexternalMemory, extMem,
    const CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC *, mipmapDesc
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mipmap, (uintptr_t)(mipmap))
    ctf_integer_hex(uintptr_t, extMem, (uintptr_t)(extMem))
    ctf_integer_hex(uintptr_t, mipmapDesc, (uintptr_t)(mipmapDesc))
    ctf_sequence_text(uint8_t, mipmapDesc_val, mipmapDesc, size_t, (mipmapDesc ? sizeof(CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuExternalMemoryGetMappedMipmappedArray_exit,
  TP_ARGS(
    CUmipmappedArray *, mipmap,
    CUexternalMemory, extMem,
    const CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC *, mipmapDesc,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, mipmap_val, (uintptr_t)((mipmap ? *mipmap : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDestroyExternalMemory_entry,
  TP_ARGS(
    CUexternalMemory, extMem
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, extMem, (uintptr_t)(extMem))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDestroyExternalMemory_exit,
  TP_ARGS(
    CUexternalMemory, extMem,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuImportExternalSemaphore_entry,
  TP_ARGS(
    CUexternalSemaphore *, extSem_out,
    const CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC *, semHandleDesc
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, extSem_out, (uintptr_t)(extSem_out))
    ctf_integer_hex(uintptr_t, semHandleDesc, (uintptr_t)(semHandleDesc))
    ctf_sequence_text(uint8_t, semHandleDesc_val, semHandleDesc, size_t, (semHandleDesc ? sizeof(CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuImportExternalSemaphore_exit,
  TP_ARGS(
    CUexternalSemaphore *, extSem_out,
    const CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC *, semHandleDesc,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, extSem_out_val, (uintptr_t)((extSem_out ? *extSem_out : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuSignalExternalSemaphoresAsync_ptsz_entry,
  TP_ARGS(
    const CUexternalSemaphore *, extSemArray,
    const CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS *, paramsArray,
    unsigned int, numExtSems,
    CUstream, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, extSemArray, (uintptr_t)(extSemArray))
    ctf_integer_hex(uintptr_t, paramsArray, (uintptr_t)(paramsArray))
    ctf_integer(unsigned int, numExtSems, numExtSems)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_sequence_hex(uintptr_t, extSemArray_vals, extSemArray, unsigned int, (extSemArray ? numExtSems : 0))
    ctf_sequence_text(uint8_t, paramsArray_vals, paramsArray, size_t, ((paramsArray ? numExtSems : 0)) * sizeof(CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuSignalExternalSemaphoresAsync_ptsz_exit,
  TP_ARGS(
    const CUexternalSemaphore *, extSemArray,
    const CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS *, paramsArray,
    unsigned int, numExtSems,
    CUstream, stream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuWaitExternalSemaphoresAsync_ptsz_entry,
  TP_ARGS(
    const CUexternalSemaphore *, extSemArray,
    const CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS *, paramsArray,
    unsigned int, numExtSems,
    CUstream, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, extSemArray, (uintptr_t)(extSemArray))
    ctf_integer_hex(uintptr_t, paramsArray, (uintptr_t)(paramsArray))
    ctf_integer(unsigned int, numExtSems, numExtSems)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_sequence_hex(uintptr_t, extSemArray_vals, extSemArray, unsigned int, (extSemArray ? numExtSems : 0))
    ctf_sequence_text(uint8_t, paramsArray_vals, paramsArray, size_t, ((paramsArray ? numExtSems : 0)) * sizeof(CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuWaitExternalSemaphoresAsync_ptsz_exit,
  TP_ARGS(
    const CUexternalSemaphore *, extSemArray,
    const CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS *, paramsArray,
    unsigned int, numExtSems,
    CUstream, stream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDestroyExternalSemaphore_entry,
  TP_ARGS(
    CUexternalSemaphore, extSem
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, extSem, (uintptr_t)(extSem))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDestroyExternalSemaphore_exit,
  TP_ARGS(
    CUexternalSemaphore, extSem,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamWaitValue32_v2_ptsz_entry,
  TP_ARGS(
    CUstream, stream,
    CUdeviceptr, addr,
    cuuint32_t, value,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(CUdeviceptr, addr, addr)
    ctf_integer(cuuint32_t, value, value)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamWaitValue32_v2_ptsz_exit,
  TP_ARGS(
    CUstream, stream,
    CUdeviceptr, addr,
    cuuint32_t, value,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamWaitValue64_v2_ptsz_entry,
  TP_ARGS(
    CUstream, stream,
    CUdeviceptr, addr,
    cuuint64_t, value,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(CUdeviceptr, addr, addr)
    ctf_integer(cuuint64_t, value, value)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamWaitValue64_v2_ptsz_exit,
  TP_ARGS(
    CUstream, stream,
    CUdeviceptr, addr,
    cuuint64_t, value,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamWriteValue32_v2_ptsz_entry,
  TP_ARGS(
    CUstream, stream,
    CUdeviceptr, addr,
    cuuint32_t, value,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(CUdeviceptr, addr, addr)
    ctf_integer(cuuint32_t, value, value)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamWriteValue32_v2_ptsz_exit,
  TP_ARGS(
    CUstream, stream,
    CUdeviceptr, addr,
    cuuint32_t, value,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamWriteValue64_v2_ptsz_entry,
  TP_ARGS(
    CUstream, stream,
    CUdeviceptr, addr,
    cuuint64_t, value,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(CUdeviceptr, addr, addr)
    ctf_integer(cuuint64_t, value, value)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamWriteValue64_v2_ptsz_exit,
  TP_ARGS(
    CUstream, stream,
    CUdeviceptr, addr,
    cuuint64_t, value,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamBatchMemOp_v2_ptsz_entry,
  TP_ARGS(
    CUstream, stream,
    unsigned int, count,
    CUstreamBatchMemOpParams *, paramArray,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer(unsigned int, count, count)
    ctf_integer_hex(uintptr_t, paramArray, (uintptr_t)(paramArray))
    ctf_integer(unsigned int, flags, flags)
    ctf_sequence_text(uint8_t, paramArray_vals, paramArray, size_t, ((paramArray ? count : 0)) * sizeof(CUstreamBatchMemOpParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamBatchMemOp_v2_ptsz_exit,
  TP_ARGS(
    CUstream, stream,
    unsigned int, count,
    CUstreamBatchMemOpParams *, paramArray,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuFuncGetAttribute_entry,
  TP_ARGS(
    int *, pi,
    CUfunction_attribute, attrib,
    CUfunction, hfunc
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pi, (uintptr_t)(pi))
    ctf_integer(int32_t, attrib, attrib)
    ctf_integer_hex(uintptr_t, hfunc, (uintptr_t)(hfunc))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuFuncGetAttribute_exit,
  TP_ARGS(
    int *, pi,
    CUfunction_attribute, attrib,
    CUfunction, hfunc,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int, pi_val, (pi ? *pi : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuFuncSetAttribute_entry,
  TP_ARGS(
    CUfunction, hfunc,
    CUfunction_attribute, attrib,
    int, value
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hfunc, (uintptr_t)(hfunc))
    ctf_integer(int32_t, attrib, attrib)
    ctf_integer(int, value, value)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuFuncSetAttribute_exit,
  TP_ARGS(
    CUfunction, hfunc,
    CUfunction_attribute, attrib,
    int, value,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuFuncSetCacheConfig_entry,
  TP_ARGS(
    CUfunction, hfunc,
    CUfunc_cache, config
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hfunc, (uintptr_t)(hfunc))
    ctf_integer(int32_t, config, config)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuFuncSetCacheConfig_exit,
  TP_ARGS(
    CUfunction, hfunc,
    CUfunc_cache, config,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuFuncGetModule_entry,
  TP_ARGS(
    CUmodule *, hmod,
    CUfunction, hfunc
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hmod, (uintptr_t)(hmod))
    ctf_integer_hex(uintptr_t, hfunc, (uintptr_t)(hfunc))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuFuncGetModule_exit,
  TP_ARGS(
    CUmodule *, hmod,
    CUfunction, hfunc,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, hmod_val, (uintptr_t)((hmod ? *hmod : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuFuncGetName_entry,
  TP_ARGS(
    const char **, name,
    CUfunction, hfunc
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, name, (uintptr_t)(name))
    ctf_integer_hex(uintptr_t, hfunc, (uintptr_t)(hfunc))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuFuncGetName_exit,
  TP_ARGS(
    const char **, name,
    CUfunction, hfunc,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_string(name_val_val, *name)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuFuncGetParamInfo_entry,
  TP_ARGS(
    CUfunction, func,
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
  lttng_ust_cuda,
  cuFuncGetParamInfo_exit,
  TP_ARGS(
    CUfunction, func,
    size_t, paramIndex,
    size_t *, paramOffset,
    size_t *, paramSize,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(size_t, paramOffset_val, (paramOffset ? *paramOffset : 0))
    ctf_integer(size_t, paramSize_val, (paramSize ? *paramSize : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuFuncIsLoaded_entry,
  TP_ARGS(
    CUfunctionLoadingState *, state,
    CUfunction, function
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, state, (uintptr_t)(state))
    ctf_integer_hex(uintptr_t, function, (uintptr_t)(function))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuFuncIsLoaded_exit,
  TP_ARGS(
    CUfunctionLoadingState *, state,
    CUfunction, function,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int32_t, state_val, (state ? *state : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuFuncLoad_entry,
  TP_ARGS(
    CUfunction, function
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, function, (uintptr_t)(function))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuFuncLoad_exit,
  TP_ARGS(
    CUfunction, function,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLaunchKernel_ptsz_entry,
  TP_ARGS(
    CUfunction, f,
    unsigned int, gridDimX,
    unsigned int, gridDimY,
    unsigned int, gridDimZ,
    unsigned int, blockDimX,
    unsigned int, blockDimY,
    unsigned int, blockDimZ,
    unsigned int, sharedMemBytes,
    CUstream, hStream,
    void **, kernelParams,
    void **, extra,
    size_t, _extra_size
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
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, kernelParams, (uintptr_t)(kernelParams))
    ctf_integer_hex(uintptr_t, extra, (uintptr_t)(extra))
    ctf_sequence_hex(uintptr_t, extra_vals, extra, size_t, (extra ? _extra_size : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLaunchKernel_ptsz_exit,
  TP_ARGS(
    CUfunction, f,
    unsigned int, gridDimX,
    unsigned int, gridDimY,
    unsigned int, gridDimZ,
    unsigned int, blockDimX,
    unsigned int, blockDimY,
    unsigned int, blockDimZ,
    unsigned int, sharedMemBytes,
    CUstream, hStream,
    void **, kernelParams,
    void **, extra,
    CUresult, cuResult,
    size_t, _extra_size
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLaunchKernelEx_ptsz_entry,
  TP_ARGS(
    const CUlaunchConfig *, config,
    CUfunction, f,
    void **, kernelParams,
    void **, extra,
    size_t, _extra_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, config, (uintptr_t)(config))
    ctf_integer_hex(uintptr_t, f, (uintptr_t)(f))
    ctf_integer_hex(uintptr_t, kernelParams, (uintptr_t)(kernelParams))
    ctf_integer_hex(uintptr_t, extra, (uintptr_t)(extra))
    ctf_sequence_text(uint8_t, config_val, config, size_t, (config ? sizeof(CUlaunchConfig) : 0))
    ctf_sequence_text(uint8_t, config__attrs_vals, (config ? config->attrs : 0), size_t, ((config && config->attrs ? config->numAttrs : 0)) * sizeof(CUlaunchAttribute))
    ctf_sequence_hex(uintptr_t, extra_vals, extra, size_t, (extra ? _extra_size : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLaunchKernelEx_ptsz_exit,
  TP_ARGS(
    const CUlaunchConfig *, config,
    CUfunction, f,
    void **, kernelParams,
    void **, extra,
    CUresult, cuResult,
    size_t, _extra_size
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLaunchCooperativeKernel_ptsz_entry,
  TP_ARGS(
    CUfunction, f,
    unsigned int, gridDimX,
    unsigned int, gridDimY,
    unsigned int, gridDimZ,
    unsigned int, blockDimX,
    unsigned int, blockDimY,
    unsigned int, blockDimZ,
    unsigned int, sharedMemBytes,
    CUstream, hStream,
    void **, kernelParams
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
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, kernelParams, (uintptr_t)(kernelParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLaunchCooperativeKernel_ptsz_exit,
  TP_ARGS(
    CUfunction, f,
    unsigned int, gridDimX,
    unsigned int, gridDimY,
    unsigned int, gridDimZ,
    unsigned int, blockDimX,
    unsigned int, blockDimY,
    unsigned int, blockDimZ,
    unsigned int, sharedMemBytes,
    CUstream, hStream,
    void **, kernelParams,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLaunchCooperativeKernelMultiDevice_entry,
  TP_ARGS(
    CUDA_LAUNCH_PARAMS *, launchParamsList,
    unsigned int, numDevices,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, launchParamsList, (uintptr_t)(launchParamsList))
    ctf_integer(unsigned int, numDevices, numDevices)
    ctf_integer(unsigned int, flags, flags)
    ctf_sequence_text(uint8_t, launchParamsList_vals, launchParamsList, size_t, ((launchParamsList ? numDevices : 0)) * sizeof(CUDA_LAUNCH_PARAMS))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLaunchCooperativeKernelMultiDevice_exit,
  TP_ARGS(
    CUDA_LAUNCH_PARAMS *, launchParamsList,
    unsigned int, numDevices,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLaunchHostFunc_ptsz_entry,
  TP_ARGS(
    CUstream, hStream,
    CUhostFn, fn,
    void *, userData
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, fn, (uintptr_t)(fn))
    ctf_integer_hex(uintptr_t, userData, (uintptr_t)(userData))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLaunchHostFunc_ptsz_exit,
  TP_ARGS(
    CUstream, hStream,
    CUhostFn, fn,
    void *, userData,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuFuncSetBlockShape_entry,
  TP_ARGS(
    CUfunction, hfunc,
    int, x,
    int, y,
    int, z
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hfunc, (uintptr_t)(hfunc))
    ctf_integer(int, x, x)
    ctf_integer(int, y, y)
    ctf_integer(int, z, z)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuFuncSetBlockShape_exit,
  TP_ARGS(
    CUfunction, hfunc,
    int, x,
    int, y,
    int, z,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuFuncSetSharedSize_entry,
  TP_ARGS(
    CUfunction, hfunc,
    unsigned int, bytes
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hfunc, (uintptr_t)(hfunc))
    ctf_integer(unsigned int, bytes, bytes)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuFuncSetSharedSize_exit,
  TP_ARGS(
    CUfunction, hfunc,
    unsigned int, bytes,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuParamSetSize_entry,
  TP_ARGS(
    CUfunction, hfunc,
    unsigned int, numbytes
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hfunc, (uintptr_t)(hfunc))
    ctf_integer(unsigned int, numbytes, numbytes)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuParamSetSize_exit,
  TP_ARGS(
    CUfunction, hfunc,
    unsigned int, numbytes,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuParamSeti_entry,
  TP_ARGS(
    CUfunction, hfunc,
    int, offset,
    unsigned int, value
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hfunc, (uintptr_t)(hfunc))
    ctf_integer(int, offset, offset)
    ctf_integer(unsigned int, value, value)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuParamSeti_exit,
  TP_ARGS(
    CUfunction, hfunc,
    int, offset,
    unsigned int, value,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuParamSetf_entry,
  TP_ARGS(
    CUfunction, hfunc,
    int, offset,
    float, value
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hfunc, (uintptr_t)(hfunc))
    ctf_integer(int, offset, offset)
    ctf_float(float, value, value)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuParamSetf_exit,
  TP_ARGS(
    CUfunction, hfunc,
    int, offset,
    float, value,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuParamSetv_entry,
  TP_ARGS(
    CUfunction, hfunc,
    int, offset,
    void *, ptr,
    unsigned int, numbytes
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hfunc, (uintptr_t)(hfunc))
    ctf_integer(int, offset, offset)
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)(ptr))
    ctf_integer(unsigned int, numbytes, numbytes)
    ctf_sequence_text(uint8_t, ptr_vals, ptr, size_t, ((ptr ? numbytes : 0)) * sizeof(uint8_t))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuParamSetv_exit,
  TP_ARGS(
    CUfunction, hfunc,
    int, offset,
    void *, ptr,
    unsigned int, numbytes,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLaunch_entry,
  TP_ARGS(
    CUfunction, f
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, f, (uintptr_t)(f))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLaunch_exit,
  TP_ARGS(
    CUfunction, f,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLaunchGrid_entry,
  TP_ARGS(
    CUfunction, f,
    int, grid_width,
    int, grid_height
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, f, (uintptr_t)(f))
    ctf_integer(int, grid_width, grid_width)
    ctf_integer(int, grid_height, grid_height)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLaunchGrid_exit,
  TP_ARGS(
    CUfunction, f,
    int, grid_width,
    int, grid_height,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLaunchGridAsync_entry,
  TP_ARGS(
    CUfunction, f,
    int, grid_width,
    int, grid_height,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, f, (uintptr_t)(f))
    ctf_integer(int, grid_width, grid_width)
    ctf_integer(int, grid_height, grid_height)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLaunchGridAsync_exit,
  TP_ARGS(
    CUfunction, f,
    int, grid_width,
    int, grid_height,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuParamSetTexRef_entry,
  TP_ARGS(
    CUfunction, hfunc,
    int, texunit,
    CUtexref, hTexRef
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hfunc, (uintptr_t)(hfunc))
    ctf_integer(int, texunit, texunit)
    ctf_integer_hex(uintptr_t, hTexRef, (uintptr_t)(hTexRef))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuParamSetTexRef_exit,
  TP_ARGS(
    CUfunction, hfunc,
    int, texunit,
    CUtexref, hTexRef,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuFuncSetSharedMemConfig_entry,
  TP_ARGS(
    CUfunction, hfunc,
    CUsharedconfig, config
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hfunc, (uintptr_t)(hfunc))
    ctf_integer(int32_t, config, config)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuFuncSetSharedMemConfig_exit,
  TP_ARGS(
    CUfunction, hfunc,
    CUsharedconfig, config,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphCreate_entry,
  TP_ARGS(
    CUgraph *, phGraph,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, phGraph, (uintptr_t)(phGraph))
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphCreate_exit,
  TP_ARGS(
    CUgraph *, phGraph,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phGraph_val, (uintptr_t)((phGraph ? *phGraph : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphAddKernelNode_v2_entry,
  TP_ARGS(
    CUgraphNode *, phGraphNode,
    CUgraph, hGraph,
    const CUgraphNode *, dependencies,
    size_t, numDependencies,
    const CUDA_KERNEL_NODE_PARAMS *, nodeParams,
    size_t, _nodeParams__extra_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, phGraphNode, (uintptr_t)(phGraphNode))
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, dependencies, (uintptr_t)(dependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
    ctf_sequence_hex(uintptr_t, dependencies_vals, dependencies, size_t, (dependencies ? numDependencies : 0))
    ctf_sequence_text(uint8_t, nodeParams_val, nodeParams, size_t, (nodeParams ? sizeof(CUDA_KERNEL_NODE_PARAMS) : 0))
    ctf_sequence_hex(uintptr_t, nodeParams__extra_vals, (nodeParams ? nodeParams->extra : 0), size_t, (nodeParams && nodeParams->extra ? _nodeParams__extra_size : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphAddKernelNode_v2_exit,
  TP_ARGS(
    CUgraphNode *, phGraphNode,
    CUgraph, hGraph,
    const CUgraphNode *, dependencies,
    size_t, numDependencies,
    const CUDA_KERNEL_NODE_PARAMS *, nodeParams,
    CUresult, cuResult,
    size_t, _nodeParams__extra_size
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phGraphNode_val, (uintptr_t)((phGraphNode ? *phGraphNode : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphKernelNodeGetParams_v2_entry,
  TP_ARGS(
    CUgraphNode, hNode,
    CUDA_KERNEL_NODE_PARAMS *, nodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphKernelNodeGetParams_v2_exit,
  TP_ARGS(
    CUgraphNode, hNode,
    CUDA_KERNEL_NODE_PARAMS *, nodeParams,
    CUresult, cuResult,
    size_t, _nodeParams__extra_size
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, nodeParams_val, nodeParams, size_t, (nodeParams ? sizeof(CUDA_KERNEL_NODE_PARAMS) : 0))
    ctf_sequence_hex(uintptr_t, nodeParams__extra_vals, (nodeParams ? nodeParams->extra : 0), size_t, (nodeParams && nodeParams->extra ? _nodeParams__extra_size : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphKernelNodeSetParams_v2_entry,
  TP_ARGS(
    CUgraphNode, hNode,
    const CUDA_KERNEL_NODE_PARAMS *, nodeParams,
    size_t, _nodeParams__extra_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
    ctf_sequence_text(uint8_t, nodeParams_val, nodeParams, size_t, (nodeParams ? sizeof(CUDA_KERNEL_NODE_PARAMS) : 0))
    ctf_sequence_hex(uintptr_t, nodeParams__extra_vals, (nodeParams ? nodeParams->extra : 0), size_t, (nodeParams && nodeParams->extra ? _nodeParams__extra_size : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphKernelNodeSetParams_v2_exit,
  TP_ARGS(
    CUgraphNode, hNode,
    const CUDA_KERNEL_NODE_PARAMS *, nodeParams,
    CUresult, cuResult,
    size_t, _nodeParams__extra_size
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphAddMemcpyNode_entry,
  TP_ARGS(
    CUgraphNode *, phGraphNode,
    CUgraph, hGraph,
    const CUgraphNode *, dependencies,
    size_t, numDependencies,
    const CUDA_MEMCPY3D *, copyParams,
    CUcontext, ctx
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, phGraphNode, (uintptr_t)(phGraphNode))
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, dependencies, (uintptr_t)(dependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, copyParams, (uintptr_t)(copyParams))
    ctf_integer_hex(uintptr_t, ctx, (uintptr_t)(ctx))
    ctf_sequence_hex(uintptr_t, dependencies_vals, dependencies, size_t, (dependencies ? numDependencies : 0))
    ctf_sequence_text(uint8_t, copyParams_val, copyParams, size_t, (copyParams ? sizeof(CUDA_MEMCPY3D) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphAddMemcpyNode_exit,
  TP_ARGS(
    CUgraphNode *, phGraphNode,
    CUgraph, hGraph,
    const CUgraphNode *, dependencies,
    size_t, numDependencies,
    const CUDA_MEMCPY3D *, copyParams,
    CUcontext, ctx,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phGraphNode_val, (uintptr_t)((phGraphNode ? *phGraphNode : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphMemcpyNodeGetParams_entry,
  TP_ARGS(
    CUgraphNode, hNode,
    CUDA_MEMCPY3D *, nodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphMemcpyNodeGetParams_exit,
  TP_ARGS(
    CUgraphNode, hNode,
    CUDA_MEMCPY3D *, nodeParams,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, nodeParams_val, nodeParams, size_t, (nodeParams ? sizeof(CUDA_MEMCPY3D) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphMemcpyNodeSetParams_entry,
  TP_ARGS(
    CUgraphNode, hNode,
    const CUDA_MEMCPY3D *, nodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
    ctf_sequence_text(uint8_t, nodeParams_val, nodeParams, size_t, (nodeParams ? sizeof(CUDA_MEMCPY3D) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphMemcpyNodeSetParams_exit,
  TP_ARGS(
    CUgraphNode, hNode,
    const CUDA_MEMCPY3D *, nodeParams,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphAddMemsetNode_entry,
  TP_ARGS(
    CUgraphNode *, phGraphNode,
    CUgraph, hGraph,
    const CUgraphNode *, dependencies,
    size_t, numDependencies,
    const CUDA_MEMSET_NODE_PARAMS *, memsetParams,
    CUcontext, ctx
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, phGraphNode, (uintptr_t)(phGraphNode))
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, dependencies, (uintptr_t)(dependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, memsetParams, (uintptr_t)(memsetParams))
    ctf_integer_hex(uintptr_t, ctx, (uintptr_t)(ctx))
    ctf_sequence_hex(uintptr_t, dependencies_vals, dependencies, size_t, (dependencies ? numDependencies : 0))
    ctf_sequence_text(uint8_t, memsetParams_val, memsetParams, size_t, (memsetParams ? sizeof(CUDA_MEMSET_NODE_PARAMS) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphAddMemsetNode_exit,
  TP_ARGS(
    CUgraphNode *, phGraphNode,
    CUgraph, hGraph,
    const CUgraphNode *, dependencies,
    size_t, numDependencies,
    const CUDA_MEMSET_NODE_PARAMS *, memsetParams,
    CUcontext, ctx,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phGraphNode_val, (uintptr_t)((phGraphNode ? *phGraphNode : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphMemsetNodeGetParams_entry,
  TP_ARGS(
    CUgraphNode, hNode,
    CUDA_MEMSET_NODE_PARAMS *, nodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphMemsetNodeGetParams_exit,
  TP_ARGS(
    CUgraphNode, hNode,
    CUDA_MEMSET_NODE_PARAMS *, nodeParams,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, nodeParams_val, nodeParams, size_t, (nodeParams ? sizeof(CUDA_MEMSET_NODE_PARAMS) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphMemsetNodeSetParams_entry,
  TP_ARGS(
    CUgraphNode, hNode,
    const CUDA_MEMSET_NODE_PARAMS *, nodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
    ctf_sequence_text(uint8_t, nodeParams_val, nodeParams, size_t, (nodeParams ? sizeof(CUDA_MEMSET_NODE_PARAMS) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphMemsetNodeSetParams_exit,
  TP_ARGS(
    CUgraphNode, hNode,
    const CUDA_MEMSET_NODE_PARAMS *, nodeParams,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphAddHostNode_entry,
  TP_ARGS(
    CUgraphNode *, phGraphNode,
    CUgraph, hGraph,
    const CUgraphNode *, dependencies,
    size_t, numDependencies,
    const CUDA_HOST_NODE_PARAMS *, nodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, phGraphNode, (uintptr_t)(phGraphNode))
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, dependencies, (uintptr_t)(dependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
    ctf_sequence_hex(uintptr_t, dependencies_vals, dependencies, size_t, (dependencies ? numDependencies : 0))
    ctf_sequence_text(uint8_t, nodeParams_val, nodeParams, size_t, (nodeParams ? sizeof(CUDA_HOST_NODE_PARAMS) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphAddHostNode_exit,
  TP_ARGS(
    CUgraphNode *, phGraphNode,
    CUgraph, hGraph,
    const CUgraphNode *, dependencies,
    size_t, numDependencies,
    const CUDA_HOST_NODE_PARAMS *, nodeParams,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phGraphNode_val, (uintptr_t)((phGraphNode ? *phGraphNode : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphHostNodeGetParams_entry,
  TP_ARGS(
    CUgraphNode, hNode,
    CUDA_HOST_NODE_PARAMS *, nodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphHostNodeGetParams_exit,
  TP_ARGS(
    CUgraphNode, hNode,
    CUDA_HOST_NODE_PARAMS *, nodeParams,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, nodeParams_val, nodeParams, size_t, (nodeParams ? sizeof(CUDA_HOST_NODE_PARAMS) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphHostNodeSetParams_entry,
  TP_ARGS(
    CUgraphNode, hNode,
    const CUDA_HOST_NODE_PARAMS *, nodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
    ctf_sequence_text(uint8_t, nodeParams_val, nodeParams, size_t, (nodeParams ? sizeof(CUDA_HOST_NODE_PARAMS) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphHostNodeSetParams_exit,
  TP_ARGS(
    CUgraphNode, hNode,
    const CUDA_HOST_NODE_PARAMS *, nodeParams,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphAddChildGraphNode_entry,
  TP_ARGS(
    CUgraphNode *, phGraphNode,
    CUgraph, hGraph,
    const CUgraphNode *, dependencies,
    size_t, numDependencies,
    CUgraph, childGraph
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, phGraphNode, (uintptr_t)(phGraphNode))
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, dependencies, (uintptr_t)(dependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, childGraph, (uintptr_t)(childGraph))
    ctf_sequence_hex(uintptr_t, dependencies_vals, dependencies, size_t, (dependencies ? numDependencies : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphAddChildGraphNode_exit,
  TP_ARGS(
    CUgraphNode *, phGraphNode,
    CUgraph, hGraph,
    const CUgraphNode *, dependencies,
    size_t, numDependencies,
    CUgraph, childGraph,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphChildGraphNodeGetGraph_entry,
  TP_ARGS(
    CUgraphNode, hNode,
    CUgraph *, phGraph
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, phGraph, (uintptr_t)(phGraph))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphChildGraphNodeGetGraph_exit,
  TP_ARGS(
    CUgraphNode, hNode,
    CUgraph *, phGraph,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phGraph_val, (uintptr_t)((phGraph ? *phGraph : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphAddEmptyNode_entry,
  TP_ARGS(
    CUgraphNode *, phGraphNode,
    CUgraph, hGraph,
    const CUgraphNode *, dependencies,
    size_t, numDependencies
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, phGraphNode, (uintptr_t)(phGraphNode))
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, dependencies, (uintptr_t)(dependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_sequence_hex(uintptr_t, dependencies_vals, dependencies, size_t, (dependencies ? numDependencies : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphAddEmptyNode_exit,
  TP_ARGS(
    CUgraphNode *, phGraphNode,
    CUgraph, hGraph,
    const CUgraphNode *, dependencies,
    size_t, numDependencies,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phGraphNode_val, (uintptr_t)((phGraphNode ? *phGraphNode : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphAddEventRecordNode_entry,
  TP_ARGS(
    CUgraphNode *, phGraphNode,
    CUgraph, hGraph,
    const CUgraphNode *, dependencies,
    size_t, numDependencies,
    CUevent, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, phGraphNode, (uintptr_t)(phGraphNode))
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, dependencies, (uintptr_t)(dependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
    ctf_sequence_hex(uintptr_t, dependencies_vals, dependencies, size_t, (dependencies ? numDependencies : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphAddEventRecordNode_exit,
  TP_ARGS(
    CUgraphNode *, phGraphNode,
    CUgraph, hGraph,
    const CUgraphNode *, dependencies,
    size_t, numDependencies,
    CUevent, event,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phGraphNode_val, (uintptr_t)((phGraphNode ? *phGraphNode : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphEventRecordNodeGetEvent_entry,
  TP_ARGS(
    CUgraphNode, hNode,
    CUevent *, event_out
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, event_out, (uintptr_t)(event_out))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphEventRecordNodeGetEvent_exit,
  TP_ARGS(
    CUgraphNode, hNode,
    CUevent *, event_out,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, event_out_val, (uintptr_t)((event_out ? *event_out : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphEventRecordNodeSetEvent_entry,
  TP_ARGS(
    CUgraphNode, hNode,
    CUevent, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphEventRecordNodeSetEvent_exit,
  TP_ARGS(
    CUgraphNode, hNode,
    CUevent, event,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphAddEventWaitNode_entry,
  TP_ARGS(
    CUgraphNode *, phGraphNode,
    CUgraph, hGraph,
    const CUgraphNode *, dependencies,
    size_t, numDependencies,
    CUevent, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, phGraphNode, (uintptr_t)(phGraphNode))
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, dependencies, (uintptr_t)(dependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
    ctf_sequence_hex(uintptr_t, dependencies_vals, dependencies, size_t, (dependencies ? numDependencies : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphAddEventWaitNode_exit,
  TP_ARGS(
    CUgraphNode *, phGraphNode,
    CUgraph, hGraph,
    const CUgraphNode *, dependencies,
    size_t, numDependencies,
    CUevent, event,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phGraphNode_val, (uintptr_t)((phGraphNode ? *phGraphNode : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphEventWaitNodeGetEvent_entry,
  TP_ARGS(
    CUgraphNode, hNode,
    CUevent *, event_out
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, event_out, (uintptr_t)(event_out))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphEventWaitNodeGetEvent_exit,
  TP_ARGS(
    CUgraphNode, hNode,
    CUevent *, event_out,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, event_out_val, (uintptr_t)((event_out ? *event_out : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphEventWaitNodeSetEvent_entry,
  TP_ARGS(
    CUgraphNode, hNode,
    CUevent, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphEventWaitNodeSetEvent_exit,
  TP_ARGS(
    CUgraphNode, hNode,
    CUevent, event,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphAddExternalSemaphoresSignalNode_entry,
  TP_ARGS(
    CUgraphNode *, phGraphNode,
    CUgraph, hGraph,
    const CUgraphNode *, dependencies,
    size_t, numDependencies,
    const CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *, nodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, phGraphNode, (uintptr_t)(phGraphNode))
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, dependencies, (uintptr_t)(dependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
    ctf_sequence_hex(uintptr_t, dependencies_vals, dependencies, size_t, (dependencies ? numDependencies : 0))
    ctf_sequence_text(uint8_t, nodeParams_val, nodeParams, size_t, (nodeParams ? sizeof(CUDA_EXT_SEM_SIGNAL_NODE_PARAMS) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphAddExternalSemaphoresSignalNode_exit,
  TP_ARGS(
    CUgraphNode *, phGraphNode,
    CUgraph, hGraph,
    const CUgraphNode *, dependencies,
    size_t, numDependencies,
    const CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *, nodeParams,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phGraphNode_val, (uintptr_t)((phGraphNode ? *phGraphNode : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExternalSemaphoresSignalNodeGetParams_entry,
  TP_ARGS(
    CUgraphNode, hNode,
    CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *, params_out
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, params_out, (uintptr_t)(params_out))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExternalSemaphoresSignalNodeGetParams_exit,
  TP_ARGS(
    CUgraphNode, hNode,
    CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *, params_out,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, params_out_val, params_out, size_t, (params_out ? sizeof(CUDA_EXT_SEM_SIGNAL_NODE_PARAMS) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExternalSemaphoresSignalNodeSetParams_entry,
  TP_ARGS(
    CUgraphNode, hNode,
    const CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *, nodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
    ctf_sequence_text(uint8_t, nodeParams_val, nodeParams, size_t, (nodeParams ? sizeof(CUDA_EXT_SEM_SIGNAL_NODE_PARAMS) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExternalSemaphoresSignalNodeSetParams_exit,
  TP_ARGS(
    CUgraphNode, hNode,
    const CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *, nodeParams,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphAddExternalSemaphoresWaitNode_entry,
  TP_ARGS(
    CUgraphNode *, phGraphNode,
    CUgraph, hGraph,
    const CUgraphNode *, dependencies,
    size_t, numDependencies,
    const CUDA_EXT_SEM_WAIT_NODE_PARAMS *, nodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, phGraphNode, (uintptr_t)(phGraphNode))
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, dependencies, (uintptr_t)(dependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
    ctf_sequence_hex(uintptr_t, dependencies_vals, dependencies, size_t, (dependencies ? numDependencies : 0))
    ctf_sequence_text(uint8_t, nodeParams_val, nodeParams, size_t, (nodeParams ? sizeof(CUDA_EXT_SEM_WAIT_NODE_PARAMS) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphAddExternalSemaphoresWaitNode_exit,
  TP_ARGS(
    CUgraphNode *, phGraphNode,
    CUgraph, hGraph,
    const CUgraphNode *, dependencies,
    size_t, numDependencies,
    const CUDA_EXT_SEM_WAIT_NODE_PARAMS *, nodeParams,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phGraphNode_val, (uintptr_t)((phGraphNode ? *phGraphNode : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExternalSemaphoresWaitNodeGetParams_entry,
  TP_ARGS(
    CUgraphNode, hNode,
    CUDA_EXT_SEM_WAIT_NODE_PARAMS *, params_out
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, params_out, (uintptr_t)(params_out))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExternalSemaphoresWaitNodeGetParams_exit,
  TP_ARGS(
    CUgraphNode, hNode,
    CUDA_EXT_SEM_WAIT_NODE_PARAMS *, params_out,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, params_out_val, params_out, size_t, (params_out ? sizeof(CUDA_EXT_SEM_WAIT_NODE_PARAMS) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExternalSemaphoresWaitNodeSetParams_entry,
  TP_ARGS(
    CUgraphNode, hNode,
    const CUDA_EXT_SEM_WAIT_NODE_PARAMS *, nodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
    ctf_sequence_text(uint8_t, nodeParams_val, nodeParams, size_t, (nodeParams ? sizeof(CUDA_EXT_SEM_WAIT_NODE_PARAMS) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExternalSemaphoresWaitNodeSetParams_exit,
  TP_ARGS(
    CUgraphNode, hNode,
    const CUDA_EXT_SEM_WAIT_NODE_PARAMS *, nodeParams,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphAddBatchMemOpNode_entry,
  TP_ARGS(
    CUgraphNode *, phGraphNode,
    CUgraph, hGraph,
    const CUgraphNode *, dependencies,
    size_t, numDependencies,
    const CUDA_BATCH_MEM_OP_NODE_PARAMS *, nodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, phGraphNode, (uintptr_t)(phGraphNode))
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, dependencies, (uintptr_t)(dependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
    ctf_sequence_hex(uintptr_t, dependencies_vals, dependencies, size_t, (dependencies ? numDependencies : 0))
    ctf_sequence_text(uint8_t, nodeParams_val, nodeParams, size_t, (nodeParams ? sizeof(CUDA_BATCH_MEM_OP_NODE_PARAMS) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphAddBatchMemOpNode_exit,
  TP_ARGS(
    CUgraphNode *, phGraphNode,
    CUgraph, hGraph,
    const CUgraphNode *, dependencies,
    size_t, numDependencies,
    const CUDA_BATCH_MEM_OP_NODE_PARAMS *, nodeParams,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phGraphNode_val, (uintptr_t)((phGraphNode ? *phGraphNode : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphBatchMemOpNodeGetParams_entry,
  TP_ARGS(
    CUgraphNode, hNode,
    CUDA_BATCH_MEM_OP_NODE_PARAMS *, nodeParams_out
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, nodeParams_out, (uintptr_t)(nodeParams_out))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphBatchMemOpNodeGetParams_exit,
  TP_ARGS(
    CUgraphNode, hNode,
    CUDA_BATCH_MEM_OP_NODE_PARAMS *, nodeParams_out,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, nodeParams_out_val, nodeParams_out, size_t, (nodeParams_out ? sizeof(CUDA_BATCH_MEM_OP_NODE_PARAMS) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphBatchMemOpNodeSetParams_entry,
  TP_ARGS(
    CUgraphNode, hNode,
    const CUDA_BATCH_MEM_OP_NODE_PARAMS *, nodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
    ctf_sequence_text(uint8_t, nodeParams_val, nodeParams, size_t, (nodeParams ? sizeof(CUDA_BATCH_MEM_OP_NODE_PARAMS) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphBatchMemOpNodeSetParams_exit,
  TP_ARGS(
    CUgraphNode, hNode,
    const CUDA_BATCH_MEM_OP_NODE_PARAMS *, nodeParams,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExecBatchMemOpNodeSetParams_entry,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUgraphNode, hNode,
    const CUDA_BATCH_MEM_OP_NODE_PARAMS *, nodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
    ctf_sequence_text(uint8_t, nodeParams_val, nodeParams, size_t, (nodeParams ? sizeof(CUDA_BATCH_MEM_OP_NODE_PARAMS) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExecBatchMemOpNodeSetParams_exit,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUgraphNode, hNode,
    const CUDA_BATCH_MEM_OP_NODE_PARAMS *, nodeParams,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphAddMemAllocNode_entry,
  TP_ARGS(
    CUgraphNode *, phGraphNode,
    CUgraph, hGraph,
    const CUgraphNode *, dependencies,
    size_t, numDependencies,
    CUDA_MEM_ALLOC_NODE_PARAMS *, nodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, phGraphNode, (uintptr_t)(phGraphNode))
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, dependencies, (uintptr_t)(dependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
    ctf_sequence_hex(uintptr_t, dependencies_vals, dependencies, size_t, (dependencies ? numDependencies : 0))
    ctf_sequence_text(uint8_t, nodeParams_val, nodeParams, size_t, (nodeParams ? sizeof(CUDA_MEM_ALLOC_NODE_PARAMS) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphAddMemAllocNode_exit,
  TP_ARGS(
    CUgraphNode *, phGraphNode,
    CUgraph, hGraph,
    const CUgraphNode *, dependencies,
    size_t, numDependencies,
    CUDA_MEM_ALLOC_NODE_PARAMS *, nodeParams,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phGraphNode_val, (uintptr_t)((phGraphNode ? *phGraphNode : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphMemAllocNodeGetParams_entry,
  TP_ARGS(
    CUgraphNode, hNode,
    CUDA_MEM_ALLOC_NODE_PARAMS *, params_out
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, params_out, (uintptr_t)(params_out))
    ctf_sequence_text(uint8_t, params_out_val, params_out, size_t, (params_out ? sizeof(CUDA_MEM_ALLOC_NODE_PARAMS) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphMemAllocNodeGetParams_exit,
  TP_ARGS(
    CUgraphNode, hNode,
    CUDA_MEM_ALLOC_NODE_PARAMS *, params_out,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphAddMemFreeNode_entry,
  TP_ARGS(
    CUgraphNode *, phGraphNode,
    CUgraph, hGraph,
    const CUgraphNode *, dependencies,
    size_t, numDependencies,
    CUdeviceptr, dptr
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, phGraphNode, (uintptr_t)(phGraphNode))
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, dependencies, (uintptr_t)(dependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(CUdeviceptr, dptr, dptr)
    ctf_sequence_hex(uintptr_t, dependencies_vals, dependencies, size_t, (dependencies ? numDependencies : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphAddMemFreeNode_exit,
  TP_ARGS(
    CUgraphNode *, phGraphNode,
    CUgraph, hGraph,
    const CUgraphNode *, dependencies,
    size_t, numDependencies,
    CUdeviceptr, dptr,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phGraphNode_val, (uintptr_t)((phGraphNode ? *phGraphNode : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphMemFreeNodeGetParams_entry,
  TP_ARGS(
    CUgraphNode, hNode,
    CUdeviceptr *, dptr_out
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, dptr_out, (uintptr_t)(dptr_out))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphMemFreeNodeGetParams_exit,
  TP_ARGS(
    CUgraphNode, hNode,
    CUdeviceptr *, dptr_out,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(CUdeviceptr, dptr_out_val, (dptr_out ? *dptr_out : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGraphMemTrim_entry,
  TP_ARGS(
    CUdevice, device
  ),
  TP_FIELDS(
    ctf_integer(CUdevice, device, device)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGraphMemTrim_exit,
  TP_ARGS(
    CUdevice, device,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetGraphMemAttribute_entry,
  TP_ARGS(
    CUdevice, device,
    CUgraphMem_attribute, attr,
    void *, value
  ),
  TP_FIELDS(
    ctf_integer(CUdevice, device, device)
    ctf_integer(int32_t, attr, attr)
    ctf_integer_hex(uintptr_t, value, (uintptr_t)(value))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetGraphMemAttribute_exit,
  TP_ARGS(
    CUdevice, device,
    CUgraphMem_attribute, attr,
    void *, value,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, value_val, value, size_t, attr == CU_GRAPH_MEM_ATTR_USED_MEM_CURRENT ? sizeof(cuuint64_t) : attr == CU_GRAPH_MEM_ATTR_USED_MEM_HIGH ? sizeof(cuuint64_t) : attr == CU_GRAPH_MEM_ATTR_RESERVED_MEM_CURRENT ? sizeof(cuuint64_t) : attr == CU_GRAPH_MEM_ATTR_RESERVED_MEM_HIGH ? sizeof(cuuint64_t) : 0)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceSetGraphMemAttribute_entry,
  TP_ARGS(
    CUdevice, device,
    CUgraphMem_attribute, attr,
    void *, value
  ),
  TP_FIELDS(
    ctf_integer(CUdevice, device, device)
    ctf_integer(int32_t, attr, attr)
    ctf_integer_hex(uintptr_t, value, (uintptr_t)(value))
    ctf_sequence_text(uint8_t, value_val, value, size_t, attr == CU_GRAPH_MEM_ATTR_USED_MEM_HIGH ? sizeof(cuuint64_t) : attr == CU_GRAPH_MEM_ATTR_RESERVED_MEM_HIGH ? sizeof(cuuint64_t) : 0)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceSetGraphMemAttribute_exit,
  TP_ARGS(
    CUdevice, device,
    CUgraphMem_attribute, attr,
    void *, value,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphClone_entry,
  TP_ARGS(
    CUgraph *, phGraphClone,
    CUgraph, originalGraph
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, phGraphClone, (uintptr_t)(phGraphClone))
    ctf_integer_hex(uintptr_t, originalGraph, (uintptr_t)(originalGraph))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphClone_exit,
  TP_ARGS(
    CUgraph *, phGraphClone,
    CUgraph, originalGraph,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phGraphClone_val, (uintptr_t)((phGraphClone ? *phGraphClone : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphNodeFindInClone_entry,
  TP_ARGS(
    CUgraphNode *, phNode,
    CUgraphNode, hOriginalNode,
    CUgraph, hClonedGraph
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, phNode, (uintptr_t)(phNode))
    ctf_integer_hex(uintptr_t, hOriginalNode, (uintptr_t)(hOriginalNode))
    ctf_integer_hex(uintptr_t, hClonedGraph, (uintptr_t)(hClonedGraph))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphNodeFindInClone_exit,
  TP_ARGS(
    CUgraphNode *, phNode,
    CUgraphNode, hOriginalNode,
    CUgraph, hClonedGraph,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phNode_val, (uintptr_t)((phNode ? *phNode : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphNodeGetType_entry,
  TP_ARGS(
    CUgraphNode, hNode,
    CUgraphNodeType *, type
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, type, (uintptr_t)(type))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphNodeGetType_exit,
  TP_ARGS(
    CUgraphNode, hNode,
    CUgraphNodeType *, type,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int32_t, type_val, (type ? *type : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphGetNodes_entry,
  TP_ARGS(
    CUgraph, hGraph,
    CUgraphNode *, nodes,
    size_t *, numNodes
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, nodes, (uintptr_t)(nodes))
    ctf_integer_hex(uintptr_t, numNodes, (uintptr_t)(numNodes))
    ctf_integer(size_t, numNodes_val, (numNodes ? *numNodes : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphGetNodes_exit,
  TP_ARGS(
    CUgraph, hGraph,
    CUgraphNode *, nodes,
    size_t *, numNodes,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(size_t, numNodes_val, (numNodes ? *numNodes : 0))
    ctf_sequence_hex(uintptr_t, nodes_vals, nodes, size_t, (numNodes && nodes ? *numNodes : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphGetRootNodes_entry,
  TP_ARGS(
    CUgraph, hGraph,
    CUgraphNode *, rootNodes,
    size_t *, numRootNodes
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, rootNodes, (uintptr_t)(rootNodes))
    ctf_integer_hex(uintptr_t, numRootNodes, (uintptr_t)(numRootNodes))
    ctf_integer(size_t, numRootNodes_val, (numRootNodes ? *numRootNodes : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphGetRootNodes_exit,
  TP_ARGS(
    CUgraph, hGraph,
    CUgraphNode *, rootNodes,
    size_t *, numRootNodes,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(size_t, numRootNodes_val, (numRootNodes ? *numRootNodes : 0))
    ctf_sequence_hex(uintptr_t, rootNodes_vals, rootNodes, size_t, (numRootNodes && rootNodes ? *numRootNodes : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphGetEdges_v2_entry,
  TP_ARGS(
    CUgraph, hGraph,
    CUgraphNode *, from,
    CUgraphNode *, to,
    CUgraphEdgeData *, edgeData,
    size_t *, numEdges
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, from, (uintptr_t)(from))
    ctf_integer_hex(uintptr_t, to, (uintptr_t)(to))
    ctf_integer_hex(uintptr_t, edgeData, (uintptr_t)(edgeData))
    ctf_integer_hex(uintptr_t, numEdges, (uintptr_t)(numEdges))
    ctf_integer(size_t, numEdges_val, (numEdges ? *numEdges : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphGetEdges_v2_exit,
  TP_ARGS(
    CUgraph, hGraph,
    CUgraphNode *, from,
    CUgraphNode *, to,
    CUgraphEdgeData *, edgeData,
    size_t *, numEdges,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(size_t, numEdges_val, (numEdges ? *numEdges : 0))
    ctf_sequence_hex(uintptr_t, from_vals, from, size_t, (numEdges && from ? *numEdges : 0))
    ctf_sequence_hex(uintptr_t, to_vals, to, size_t, (numEdges && to ? *numEdges : 0))
    ctf_sequence_text(uint8_t, edgeData_vals, edgeData, size_t, ((numEdges && edgeData ? *numEdges : 0)) * sizeof(CUgraphEdgeData))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphNodeGetDependencies_v2_entry,
  TP_ARGS(
    CUgraphNode, hNode,
    CUgraphNode *, dependencies,
    CUgraphEdgeData *, edgeData,
    size_t *, numDependencies
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, dependencies, (uintptr_t)(dependencies))
    ctf_integer_hex(uintptr_t, edgeData, (uintptr_t)(edgeData))
    ctf_integer_hex(uintptr_t, numDependencies, (uintptr_t)(numDependencies))
    ctf_integer(size_t, numDependencies_val, (numDependencies ? *numDependencies : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphNodeGetDependencies_v2_exit,
  TP_ARGS(
    CUgraphNode, hNode,
    CUgraphNode *, dependencies,
    CUgraphEdgeData *, edgeData,
    size_t *, numDependencies,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(size_t, numDependencies_val, (numDependencies ? *numDependencies : 0))
    ctf_sequence_hex(uintptr_t, dependencies_vals, dependencies, size_t, (numDependencies && dependencies ? *numDependencies : 0))
    ctf_sequence_text(uint8_t, edgeData_vals, edgeData, size_t, ((numDependencies && edgeData ? *numDependencies : 0)) * sizeof(CUgraphEdgeData))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphNodeGetDependentNodes_v2_entry,
  TP_ARGS(
    CUgraphNode, hNode,
    CUgraphNode *, dependentNodes,
    CUgraphEdgeData *, edgeData,
    size_t *, numDependentNodes
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, dependentNodes, (uintptr_t)(dependentNodes))
    ctf_integer_hex(uintptr_t, edgeData, (uintptr_t)(edgeData))
    ctf_integer_hex(uintptr_t, numDependentNodes, (uintptr_t)(numDependentNodes))
    ctf_integer(size_t, numDependentNodes_val, (numDependentNodes ? *numDependentNodes : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphNodeGetDependentNodes_v2_exit,
  TP_ARGS(
    CUgraphNode, hNode,
    CUgraphNode *, dependentNodes,
    CUgraphEdgeData *, edgeData,
    size_t *, numDependentNodes,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(size_t, numDependentNodes_val, (numDependentNodes ? *numDependentNodes : 0))
    ctf_sequence_hex(uintptr_t, dependentNodes_vals, dependentNodes, size_t, (numDependentNodes && dependentNodes ? *numDependentNodes : 0))
    ctf_sequence_text(uint8_t, edgeData_vals, edgeData, size_t, ((numDependentNodes && edgeData ? *numDependentNodes : 0)) * sizeof(CUgraphEdgeData))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphAddDependencies_v2_entry,
  TP_ARGS(
    CUgraph, hGraph,
    const CUgraphNode *, from,
    const CUgraphNode *, to,
    const CUgraphEdgeData *, edgeData,
    size_t, numDependencies
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, from, (uintptr_t)(from))
    ctf_integer_hex(uintptr_t, to, (uintptr_t)(to))
    ctf_integer_hex(uintptr_t, edgeData, (uintptr_t)(edgeData))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_sequence_hex(uintptr_t, from_vals, from, size_t, (from ? numDependencies : 0))
    ctf_sequence_hex(uintptr_t, to_vals, to, size_t, (to ? numDependencies : 0))
    ctf_sequence_text(uint8_t, edgeData_vals, edgeData, size_t, ((edgeData ? numDependencies : 0)) * sizeof(CUgraphEdgeData))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphAddDependencies_v2_exit,
  TP_ARGS(
    CUgraph, hGraph,
    const CUgraphNode *, from,
    const CUgraphNode *, to,
    const CUgraphEdgeData *, edgeData,
    size_t, numDependencies,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphRemoveDependencies_v2_entry,
  TP_ARGS(
    CUgraph, hGraph,
    const CUgraphNode *, from,
    const CUgraphNode *, to,
    const CUgraphEdgeData *, edgeData,
    size_t, numDependencies
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, from, (uintptr_t)(from))
    ctf_integer_hex(uintptr_t, to, (uintptr_t)(to))
    ctf_integer_hex(uintptr_t, edgeData, (uintptr_t)(edgeData))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_sequence_hex(uintptr_t, from_vals, from, size_t, (from ? numDependencies : 0))
    ctf_sequence_hex(uintptr_t, to_vals, to, size_t, (to ? numDependencies : 0))
    ctf_sequence_text(uint8_t, edgeData_vals, edgeData, size_t, ((edgeData ? numDependencies : 0)) * sizeof(CUgraphEdgeData))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphRemoveDependencies_v2_exit,
  TP_ARGS(
    CUgraph, hGraph,
    const CUgraphNode *, from,
    const CUgraphNode *, to,
    const CUgraphEdgeData *, edgeData,
    size_t, numDependencies,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphDestroyNode_entry,
  TP_ARGS(
    CUgraphNode, hNode
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphDestroyNode_exit,
  TP_ARGS(
    CUgraphNode, hNode,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphInstantiateWithFlags_entry,
  TP_ARGS(
    CUgraphExec *, phGraphExec,
    CUgraph, hGraph,
    unsigned long long int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, phGraphExec, (uintptr_t)(phGraphExec))
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer(unsigned long long int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphInstantiateWithFlags_exit,
  TP_ARGS(
    CUgraphExec *, phGraphExec,
    CUgraph, hGraph,
    unsigned long long int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phGraphExec_val, (uintptr_t)((phGraphExec ? *phGraphExec : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphInstantiateWithParams_ptsz_entry,
  TP_ARGS(
    CUgraphExec *, phGraphExec,
    CUgraph, hGraph,
    CUDA_GRAPH_INSTANTIATE_PARAMS *, instantiateParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, phGraphExec, (uintptr_t)(phGraphExec))
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, instantiateParams, (uintptr_t)(instantiateParams))
    ctf_sequence_text(uint8_t, instantiateParams_val, instantiateParams, size_t, (instantiateParams ? sizeof(CUDA_GRAPH_INSTANTIATE_PARAMS) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphInstantiateWithParams_ptsz_exit,
  TP_ARGS(
    CUgraphExec *, phGraphExec,
    CUgraph, hGraph,
    CUDA_GRAPH_INSTANTIATE_PARAMS *, instantiateParams,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phGraphExec_val, (uintptr_t)((phGraphExec ? *phGraphExec : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExecGetFlags_entry,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    cuuint64_t *, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, flags, (uintptr_t)(flags))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExecGetFlags_exit,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    cuuint64_t *, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(cuuint64_t, flags_val, (flags ? *flags : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExecKernelNodeSetParams_v2_entry,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUgraphNode, hNode,
    const CUDA_KERNEL_NODE_PARAMS *, nodeParams,
    size_t, _nodeParams__extra_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
    ctf_sequence_text(uint8_t, nodeParams_val, nodeParams, size_t, (nodeParams ? sizeof(CUDA_KERNEL_NODE_PARAMS) : 0))
    ctf_sequence_hex(uintptr_t, nodeParams__extra_vals, (nodeParams ? nodeParams->extra : 0), size_t, (nodeParams && nodeParams->extra ? _nodeParams__extra_size : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExecKernelNodeSetParams_v2_exit,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUgraphNode, hNode,
    const CUDA_KERNEL_NODE_PARAMS *, nodeParams,
    CUresult, cuResult,
    size_t, _nodeParams__extra_size
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExecMemcpyNodeSetParams_entry,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUgraphNode, hNode,
    const CUDA_MEMCPY3D *, copyParams,
    CUcontext, ctx
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, copyParams, (uintptr_t)(copyParams))
    ctf_integer_hex(uintptr_t, ctx, (uintptr_t)(ctx))
    ctf_sequence_text(uint8_t, copyParams_val, copyParams, size_t, (copyParams ? sizeof(CUDA_MEMCPY3D) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExecMemcpyNodeSetParams_exit,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUgraphNode, hNode,
    const CUDA_MEMCPY3D *, copyParams,
    CUcontext, ctx,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExecMemsetNodeSetParams_entry,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUgraphNode, hNode,
    const CUDA_MEMSET_NODE_PARAMS *, memsetParams,
    CUcontext, ctx
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, memsetParams, (uintptr_t)(memsetParams))
    ctf_integer_hex(uintptr_t, ctx, (uintptr_t)(ctx))
    ctf_sequence_text(uint8_t, memsetParams_val, memsetParams, size_t, (memsetParams ? sizeof(CUDA_MEMSET_NODE_PARAMS) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExecMemsetNodeSetParams_exit,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUgraphNode, hNode,
    const CUDA_MEMSET_NODE_PARAMS *, memsetParams,
    CUcontext, ctx,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExecHostNodeSetParams_entry,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUgraphNode, hNode,
    const CUDA_HOST_NODE_PARAMS *, nodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
    ctf_sequence_text(uint8_t, nodeParams_val, nodeParams, size_t, (nodeParams ? sizeof(CUDA_HOST_NODE_PARAMS) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExecHostNodeSetParams_exit,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUgraphNode, hNode,
    const CUDA_HOST_NODE_PARAMS *, nodeParams,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExecChildGraphNodeSetParams_entry,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUgraphNode, hNode,
    CUgraph, childGraph
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, childGraph, (uintptr_t)(childGraph))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExecChildGraphNodeSetParams_exit,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUgraphNode, hNode,
    CUgraph, childGraph,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExecEventRecordNodeSetEvent_entry,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUgraphNode, hNode,
    CUevent, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExecEventRecordNodeSetEvent_exit,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUgraphNode, hNode,
    CUevent, event,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExecEventWaitNodeSetEvent_entry,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUgraphNode, hNode,
    CUevent, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, event, (uintptr_t)(event))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExecEventWaitNodeSetEvent_exit,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUgraphNode, hNode,
    CUevent, event,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExecExternalSemaphoresSignalNodeSetParams_entry,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUgraphNode, hNode,
    const CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *, nodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
    ctf_sequence_text(uint8_t, nodeParams_val, nodeParams, size_t, (nodeParams ? sizeof(CUDA_EXT_SEM_SIGNAL_NODE_PARAMS) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExecExternalSemaphoresSignalNodeSetParams_exit,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUgraphNode, hNode,
    const CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *, nodeParams,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExecExternalSemaphoresWaitNodeSetParams_entry,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUgraphNode, hNode,
    const CUDA_EXT_SEM_WAIT_NODE_PARAMS *, nodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
    ctf_sequence_text(uint8_t, nodeParams_val, nodeParams, size_t, (nodeParams ? sizeof(CUDA_EXT_SEM_WAIT_NODE_PARAMS) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExecExternalSemaphoresWaitNodeSetParams_exit,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUgraphNode, hNode,
    const CUDA_EXT_SEM_WAIT_NODE_PARAMS *, nodeParams,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphNodeSetEnabled_entry,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUgraphNode, hNode,
    unsigned int, isEnabled
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer(unsigned int, isEnabled, isEnabled)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphNodeSetEnabled_exit,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUgraphNode, hNode,
    unsigned int, isEnabled,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphNodeGetEnabled_entry,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUgraphNode, hNode,
    unsigned int *, isEnabled
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, isEnabled, (uintptr_t)(isEnabled))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphNodeGetEnabled_exit,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUgraphNode, hNode,
    unsigned int *, isEnabled,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(unsigned int, isEnabled_val, (isEnabled ? *isEnabled : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphUpload_ptsz_entry,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphUpload_ptsz_exit,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphLaunch_ptsz_entry,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphLaunch_ptsz_exit,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExecDestroy_entry,
  TP_ARGS(
    CUgraphExec, hGraphExec
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExecDestroy_exit,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphDestroy_entry,
  TP_ARGS(
    CUgraph, hGraph
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphDestroy_exit,
  TP_ARGS(
    CUgraph, hGraph,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExecUpdate_v2_entry,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUgraph, hGraph,
    CUgraphExecUpdateResultInfo *, resultInfo
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, resultInfo, (uintptr_t)(resultInfo))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExecUpdate_v2_exit,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUgraph, hGraph,
    CUgraphExecUpdateResultInfo *, resultInfo,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, resultInfo_val, resultInfo, size_t, (resultInfo ? sizeof(CUgraphExecUpdateResultInfo) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphKernelNodeCopyAttributes_entry,
  TP_ARGS(
    CUgraphNode, dst,
    CUgraphNode, src
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dst, (uintptr_t)(dst))
    ctf_integer_hex(uintptr_t, src, (uintptr_t)(src))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphKernelNodeCopyAttributes_exit,
  TP_ARGS(
    CUgraphNode, dst,
    CUgraphNode, src,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphKernelNodeGetAttribute_entry,
  TP_ARGS(
    CUgraphNode, hNode,
    CUkernelNodeAttrID, attr,
    CUkernelNodeAttrValue *, value_out
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer(int32_t, attr, attr)
    ctf_integer_hex(uintptr_t, value_out, (uintptr_t)(value_out))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphKernelNodeGetAttribute_exit,
  TP_ARGS(
    CUgraphNode, hNode,
    CUkernelNodeAttrID, attr,
    CUkernelNodeAttrValue *, value_out,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, value_out_val, value_out, size_t, (value_out ? sizeof(CUkernelNodeAttrValue) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphKernelNodeSetAttribute_entry,
  TP_ARGS(
    CUgraphNode, hNode,
    CUkernelNodeAttrID, attr,
    const CUkernelNodeAttrValue *, value
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer(int32_t, attr, attr)
    ctf_integer_hex(uintptr_t, value, (uintptr_t)(value))
    ctf_sequence_text(uint8_t, value_val, value, size_t, (value ? sizeof(CUkernelNodeAttrValue) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphKernelNodeSetAttribute_exit,
  TP_ARGS(
    CUgraphNode, hNode,
    CUkernelNodeAttrID, attr,
    const CUkernelNodeAttrValue *, value,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphDebugDotPrint_entry,
  TP_ARGS(
    CUgraph, hGraph,
    const char *, path,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, path, (uintptr_t)(path))
    ctf_integer(unsigned int, flags, flags)
    ctf_string(path_val, path)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphDebugDotPrint_exit,
  TP_ARGS(
    CUgraph, hGraph,
    const char *, path,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuUserObjectCreate_entry,
  TP_ARGS(
    CUuserObject *, object_out,
    void *, ptr,
    CUhostFn, destroy,
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
  lttng_ust_cuda,
  cuUserObjectCreate_exit,
  TP_ARGS(
    CUuserObject *, object_out,
    void *, ptr,
    CUhostFn, destroy,
    unsigned int, initialRefcount,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, object_out_val, (uintptr_t)((object_out ? *object_out : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuUserObjectRetain_entry,
  TP_ARGS(
    CUuserObject, object,
    unsigned int, count
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, object, (uintptr_t)(object))
    ctf_integer(unsigned int, count, count)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuUserObjectRetain_exit,
  TP_ARGS(
    CUuserObject, object,
    unsigned int, count,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuUserObjectRelease_entry,
  TP_ARGS(
    CUuserObject, object,
    unsigned int, count
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, object, (uintptr_t)(object))
    ctf_integer(unsigned int, count, count)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuUserObjectRelease_exit,
  TP_ARGS(
    CUuserObject, object,
    unsigned int, count,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphRetainUserObject_entry,
  TP_ARGS(
    CUgraph, graph,
    CUuserObject, object,
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
  lttng_ust_cuda,
  cuGraphRetainUserObject_exit,
  TP_ARGS(
    CUgraph, graph,
    CUuserObject, object,
    unsigned int, count,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphReleaseUserObject_entry,
  TP_ARGS(
    CUgraph, graph,
    CUuserObject, object,
    unsigned int, count
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, graph, (uintptr_t)(graph))
    ctf_integer_hex(uintptr_t, object, (uintptr_t)(object))
    ctf_integer(unsigned int, count, count)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphReleaseUserObject_exit,
  TP_ARGS(
    CUgraph, graph,
    CUuserObject, object,
    unsigned int, count,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphAddNode_v2_entry,
  TP_ARGS(
    CUgraphNode *, phGraphNode,
    CUgraph, hGraph,
    const CUgraphNode *, dependencies,
    const CUgraphEdgeData *, dependencyData,
    size_t, numDependencies,
    CUgraphNodeParams *, nodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, phGraphNode, (uintptr_t)(phGraphNode))
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, dependencies, (uintptr_t)(dependencies))
    ctf_integer_hex(uintptr_t, dependencyData, (uintptr_t)(dependencyData))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
    ctf_sequence_hex(uintptr_t, dependencies_vals, dependencies, size_t, (dependencies ? numDependencies : 0))
    ctf_sequence_text(uint8_t, dependencyData_vals, dependencyData, size_t, ((dependencyData ? numDependencies : 0)) * sizeof(CUgraphEdgeData))
    ctf_sequence_text(uint8_t, nodeParams_val, nodeParams, size_t, (nodeParams ? sizeof(CUgraphNodeParams) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphAddNode_v2_exit,
  TP_ARGS(
    CUgraphNode *, phGraphNode,
    CUgraph, hGraph,
    const CUgraphNode *, dependencies,
    const CUgraphEdgeData *, dependencyData,
    size_t, numDependencies,
    CUgraphNodeParams *, nodeParams,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phGraphNode_val, (uintptr_t)((phGraphNode ? *phGraphNode : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphNodeSetParams_entry,
  TP_ARGS(
    CUgraphNode, hNode,
    CUgraphNodeParams *, nodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
    ctf_sequence_text(uint8_t, nodeParams_val, nodeParams, size_t, (nodeParams ? sizeof(CUgraphNodeParams) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphNodeSetParams_exit,
  TP_ARGS(
    CUgraphNode, hNode,
    CUgraphNodeParams *, nodeParams,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExecNodeSetParams_entry,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUgraphNode, hNode,
    CUgraphNodeParams *, nodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
    ctf_sequence_text(uint8_t, nodeParams_val, nodeParams, size_t, (nodeParams ? sizeof(CUgraphNodeParams) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExecNodeSetParams_exit,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUgraphNode, hNode,
    CUgraphNodeParams *, nodeParams,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphConditionalHandleCreate_entry,
  TP_ARGS(
    CUgraphConditionalHandle *, pHandle_out,
    CUgraph, hGraph,
    CUcontext, ctx,
    unsigned int, defaultLaunchValue,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pHandle_out, (uintptr_t)(pHandle_out))
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, ctx, (uintptr_t)(ctx))
    ctf_integer(unsigned int, defaultLaunchValue, defaultLaunchValue)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphConditionalHandleCreate_exit,
  TP_ARGS(
    CUgraphConditionalHandle *, pHandle_out,
    CUgraph, hGraph,
    CUcontext, ctx,
    unsigned int, defaultLaunchValue,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(CUgraphConditionalHandle, pHandle_out_val, (pHandle_out ? *pHandle_out : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuOccupancyMaxActiveBlocksPerMultiprocessor_entry,
  TP_ARGS(
    int *, numBlocks,
    CUfunction, func,
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
  lttng_ust_cuda,
  cuOccupancyMaxActiveBlocksPerMultiprocessor_exit,
  TP_ARGS(
    int *, numBlocks,
    CUfunction, func,
    int, blockSize,
    size_t, dynamicSMemSize,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int, numBlocks_val, (numBlocks ? *numBlocks : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_entry,
  TP_ARGS(
    int *, numBlocks,
    CUfunction, func,
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
  lttng_ust_cuda,
  cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_exit,
  TP_ARGS(
    int *, numBlocks,
    CUfunction, func,
    int, blockSize,
    size_t, dynamicSMemSize,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int, numBlocks_val, (numBlocks ? *numBlocks : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuOccupancyMaxPotentialBlockSize_entry,
  TP_ARGS(
    int *, minGridSize,
    int *, blockSize,
    CUfunction, func,
    CUoccupancyB2DSize, blockSizeToDynamicSMemSize,
    size_t, dynamicSMemSize,
    int, blockSizeLimit
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, minGridSize, (uintptr_t)(minGridSize))
    ctf_integer_hex(uintptr_t, blockSize, (uintptr_t)(blockSize))
    ctf_integer_hex(uintptr_t, func, (uintptr_t)(func))
    ctf_integer_hex(uintptr_t, blockSizeToDynamicSMemSize, (uintptr_t)(blockSizeToDynamicSMemSize))
    ctf_integer(size_t, dynamicSMemSize, dynamicSMemSize)
    ctf_integer(int, blockSizeLimit, blockSizeLimit)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuOccupancyMaxPotentialBlockSize_exit,
  TP_ARGS(
    int *, minGridSize,
    int *, blockSize,
    CUfunction, func,
    CUoccupancyB2DSize, blockSizeToDynamicSMemSize,
    size_t, dynamicSMemSize,
    int, blockSizeLimit,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int, minGridSize_val, (minGridSize ? *minGridSize : 0))
    ctf_integer(int, blockSize_val, (blockSize ? *blockSize : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuOccupancyMaxPotentialBlockSizeWithFlags_entry,
  TP_ARGS(
    int *, minGridSize,
    int *, blockSize,
    CUfunction, func,
    CUoccupancyB2DSize, blockSizeToDynamicSMemSize,
    size_t, dynamicSMemSize,
    int, blockSizeLimit,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, minGridSize, (uintptr_t)(minGridSize))
    ctf_integer_hex(uintptr_t, blockSize, (uintptr_t)(blockSize))
    ctf_integer_hex(uintptr_t, func, (uintptr_t)(func))
    ctf_integer_hex(uintptr_t, blockSizeToDynamicSMemSize, (uintptr_t)(blockSizeToDynamicSMemSize))
    ctf_integer(size_t, dynamicSMemSize, dynamicSMemSize)
    ctf_integer(int, blockSizeLimit, blockSizeLimit)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuOccupancyMaxPotentialBlockSizeWithFlags_exit,
  TP_ARGS(
    int *, minGridSize,
    int *, blockSize,
    CUfunction, func,
    CUoccupancyB2DSize, blockSizeToDynamicSMemSize,
    size_t, dynamicSMemSize,
    int, blockSizeLimit,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int, minGridSize_val, (minGridSize ? *minGridSize : 0))
    ctf_integer(int, blockSize_val, (blockSize ? *blockSize : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuOccupancyAvailableDynamicSMemPerBlock_entry,
  TP_ARGS(
    size_t *, dynamicSmemSize,
    CUfunction, func,
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
  lttng_ust_cuda,
  cuOccupancyAvailableDynamicSMemPerBlock_exit,
  TP_ARGS(
    size_t *, dynamicSmemSize,
    CUfunction, func,
    int, numBlocks,
    int, blockSize,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(size_t, dynamicSmemSize_val, (dynamicSmemSize ? *dynamicSmemSize : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuOccupancyMaxPotentialClusterSize_entry,
  TP_ARGS(
    int *, clusterSize,
    CUfunction, func,
    const CUlaunchConfig *, config
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, clusterSize, (uintptr_t)(clusterSize))
    ctf_integer_hex(uintptr_t, func, (uintptr_t)(func))
    ctf_integer_hex(uintptr_t, config, (uintptr_t)(config))
    ctf_sequence_text(uint8_t, config_val, config, size_t, (config ? sizeof(CUlaunchConfig) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuOccupancyMaxPotentialClusterSize_exit,
  TP_ARGS(
    int *, clusterSize,
    CUfunction, func,
    const CUlaunchConfig *, config,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int, clusterSize_val, (clusterSize ? *clusterSize : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuOccupancyMaxActiveClusters_entry,
  TP_ARGS(
    int *, numClusters,
    CUfunction, func,
    const CUlaunchConfig *, config
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, numClusters, (uintptr_t)(numClusters))
    ctf_integer_hex(uintptr_t, func, (uintptr_t)(func))
    ctf_integer_hex(uintptr_t, config, (uintptr_t)(config))
    ctf_sequence_text(uint8_t, config_val, config, size_t, (config ? sizeof(CUlaunchConfig) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuOccupancyMaxActiveClusters_exit,
  TP_ARGS(
    int *, numClusters,
    CUfunction, func,
    const CUlaunchConfig *, config,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int, numClusters_val, (numClusters ? *numClusters : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefSetArray_entry,
  TP_ARGS(
    CUtexref, hTexRef,
    CUarray, hArray,
    unsigned int, Flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hTexRef, (uintptr_t)(hTexRef))
    ctf_integer_hex(uintptr_t, hArray, (uintptr_t)(hArray))
    ctf_integer(unsigned int, Flags, Flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefSetArray_exit,
  TP_ARGS(
    CUtexref, hTexRef,
    CUarray, hArray,
    unsigned int, Flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefSetMipmappedArray_entry,
  TP_ARGS(
    CUtexref, hTexRef,
    CUmipmappedArray, hMipmappedArray,
    unsigned int, Flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hTexRef, (uintptr_t)(hTexRef))
    ctf_integer_hex(uintptr_t, hMipmappedArray, (uintptr_t)(hMipmappedArray))
    ctf_integer(unsigned int, Flags, Flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefSetMipmappedArray_exit,
  TP_ARGS(
    CUtexref, hTexRef,
    CUmipmappedArray, hMipmappedArray,
    unsigned int, Flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefSetAddress_v2_entry,
  TP_ARGS(
    size_t *, ByteOffset,
    CUtexref, hTexRef,
    CUdeviceptr, dptr,
    size_t, bytes
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ByteOffset, (uintptr_t)(ByteOffset))
    ctf_integer_hex(uintptr_t, hTexRef, (uintptr_t)(hTexRef))
    ctf_integer_hex(CUdeviceptr, dptr, dptr)
    ctf_integer(size_t, bytes, bytes)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefSetAddress_v2_exit,
  TP_ARGS(
    size_t *, ByteOffset,
    CUtexref, hTexRef,
    CUdeviceptr, dptr,
    size_t, bytes,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefSetAddress2D_v3_entry,
  TP_ARGS(
    CUtexref, hTexRef,
    const CUDA_ARRAY_DESCRIPTOR *, desc,
    CUdeviceptr, dptr,
    size_t, Pitch
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hTexRef, (uintptr_t)(hTexRef))
    ctf_integer_hex(uintptr_t, desc, (uintptr_t)(desc))
    ctf_integer_hex(CUdeviceptr, dptr, dptr)
    ctf_integer(size_t, Pitch, Pitch)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefSetAddress2D_v3_exit,
  TP_ARGS(
    CUtexref, hTexRef,
    const CUDA_ARRAY_DESCRIPTOR *, desc,
    CUdeviceptr, dptr,
    size_t, Pitch,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefSetFormat_entry,
  TP_ARGS(
    CUtexref, hTexRef,
    CUarray_format, fmt,
    int, NumPackedComponents
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hTexRef, (uintptr_t)(hTexRef))
    ctf_integer(int32_t, fmt, fmt)
    ctf_integer(int, NumPackedComponents, NumPackedComponents)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefSetFormat_exit,
  TP_ARGS(
    CUtexref, hTexRef,
    CUarray_format, fmt,
    int, NumPackedComponents,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefSetAddressMode_entry,
  TP_ARGS(
    CUtexref, hTexRef,
    int, dim,
    CUaddress_mode, am
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hTexRef, (uintptr_t)(hTexRef))
    ctf_integer(int, dim, dim)
    ctf_integer(int32_t, am, am)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefSetAddressMode_exit,
  TP_ARGS(
    CUtexref, hTexRef,
    int, dim,
    CUaddress_mode, am,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefSetFilterMode_entry,
  TP_ARGS(
    CUtexref, hTexRef,
    CUfilter_mode, fm
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hTexRef, (uintptr_t)(hTexRef))
    ctf_integer(int32_t, fm, fm)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefSetFilterMode_exit,
  TP_ARGS(
    CUtexref, hTexRef,
    CUfilter_mode, fm,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefSetMipmapFilterMode_entry,
  TP_ARGS(
    CUtexref, hTexRef,
    CUfilter_mode, fm
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hTexRef, (uintptr_t)(hTexRef))
    ctf_integer(int32_t, fm, fm)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefSetMipmapFilterMode_exit,
  TP_ARGS(
    CUtexref, hTexRef,
    CUfilter_mode, fm,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefSetMipmapLevelBias_entry,
  TP_ARGS(
    CUtexref, hTexRef,
    float, bias
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hTexRef, (uintptr_t)(hTexRef))
    ctf_float(float, bias, bias)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefSetMipmapLevelBias_exit,
  TP_ARGS(
    CUtexref, hTexRef,
    float, bias,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefSetMipmapLevelClamp_entry,
  TP_ARGS(
    CUtexref, hTexRef,
    float, minMipmapLevelClamp,
    float, maxMipmapLevelClamp
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hTexRef, (uintptr_t)(hTexRef))
    ctf_float(float, minMipmapLevelClamp, minMipmapLevelClamp)
    ctf_float(float, maxMipmapLevelClamp, maxMipmapLevelClamp)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefSetMipmapLevelClamp_exit,
  TP_ARGS(
    CUtexref, hTexRef,
    float, minMipmapLevelClamp,
    float, maxMipmapLevelClamp,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefSetMaxAnisotropy_entry,
  TP_ARGS(
    CUtexref, hTexRef,
    unsigned int, maxAniso
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hTexRef, (uintptr_t)(hTexRef))
    ctf_integer(unsigned int, maxAniso, maxAniso)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefSetMaxAnisotropy_exit,
  TP_ARGS(
    CUtexref, hTexRef,
    unsigned int, maxAniso,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefSetBorderColor_entry,
  TP_ARGS(
    CUtexref, hTexRef,
    float *, pBorderColor
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hTexRef, (uintptr_t)(hTexRef))
    ctf_integer_hex(uintptr_t, pBorderColor, (uintptr_t)(pBorderColor))
    ctf_array_hex(uint32_t, pBorderColor_vals, pBorderColor, 4)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefSetBorderColor_exit,
  TP_ARGS(
    CUtexref, hTexRef,
    float *, pBorderColor,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefSetFlags_entry,
  TP_ARGS(
    CUtexref, hTexRef,
    unsigned int, Flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hTexRef, (uintptr_t)(hTexRef))
    ctf_integer(unsigned int, Flags, Flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefSetFlags_exit,
  TP_ARGS(
    CUtexref, hTexRef,
    unsigned int, Flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefGetAddress_v2_entry,
  TP_ARGS(
    CUdeviceptr *, pdptr,
    CUtexref, hTexRef
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pdptr, (uintptr_t)(pdptr))
    ctf_integer_hex(uintptr_t, hTexRef, (uintptr_t)(hTexRef))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefGetAddress_v2_exit,
  TP_ARGS(
    CUdeviceptr *, pdptr,
    CUtexref, hTexRef,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(CUdeviceptr, pdptr_val, (pdptr ? *pdptr : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefGetArray_entry,
  TP_ARGS(
    CUarray *, phArray,
    CUtexref, hTexRef
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, phArray, (uintptr_t)(phArray))
    ctf_integer_hex(uintptr_t, hTexRef, (uintptr_t)(hTexRef))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefGetArray_exit,
  TP_ARGS(
    CUarray *, phArray,
    CUtexref, hTexRef,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phArray_val, (uintptr_t)((phArray ? *phArray : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefGetMipmappedArray_entry,
  TP_ARGS(
    CUmipmappedArray *, phMipmappedArray,
    CUtexref, hTexRef
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, phMipmappedArray, (uintptr_t)(phMipmappedArray))
    ctf_integer_hex(uintptr_t, hTexRef, (uintptr_t)(hTexRef))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefGetMipmappedArray_exit,
  TP_ARGS(
    CUmipmappedArray *, phMipmappedArray,
    CUtexref, hTexRef,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phMipmappedArray_val, (uintptr_t)((phMipmappedArray ? *phMipmappedArray : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefGetAddressMode_entry,
  TP_ARGS(
    CUaddress_mode *, pam,
    CUtexref, hTexRef,
    int, dim
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pam, (uintptr_t)(pam))
    ctf_integer_hex(uintptr_t, hTexRef, (uintptr_t)(hTexRef))
    ctf_integer(int, dim, dim)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefGetAddressMode_exit,
  TP_ARGS(
    CUaddress_mode *, pam,
    CUtexref, hTexRef,
    int, dim,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int32_t, pam_val, (pam ? *pam : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefGetFilterMode_entry,
  TP_ARGS(
    CUfilter_mode *, pfm,
    CUtexref, hTexRef
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pfm, (uintptr_t)(pfm))
    ctf_integer_hex(uintptr_t, hTexRef, (uintptr_t)(hTexRef))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefGetFilterMode_exit,
  TP_ARGS(
    CUfilter_mode *, pfm,
    CUtexref, hTexRef,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int32_t, pfm_val, (pfm ? *pfm : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefGetFormat_entry,
  TP_ARGS(
    CUarray_format *, pFormat,
    int *, pNumChannels,
    CUtexref, hTexRef
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pFormat, (uintptr_t)(pFormat))
    ctf_integer_hex(uintptr_t, pNumChannels, (uintptr_t)(pNumChannels))
    ctf_integer_hex(uintptr_t, hTexRef, (uintptr_t)(hTexRef))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefGetFormat_exit,
  TP_ARGS(
    CUarray_format *, pFormat,
    int *, pNumChannels,
    CUtexref, hTexRef,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int32_t, pFormat_val, (pFormat ? *pFormat : 0))
    ctf_integer(int, pNumChannels_val, (pNumChannels ? *pNumChannels : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefGetMipmapFilterMode_entry,
  TP_ARGS(
    CUfilter_mode *, pfm,
    CUtexref, hTexRef
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pfm, (uintptr_t)(pfm))
    ctf_integer_hex(uintptr_t, hTexRef, (uintptr_t)(hTexRef))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefGetMipmapFilterMode_exit,
  TP_ARGS(
    CUfilter_mode *, pfm,
    CUtexref, hTexRef,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int32_t, pfm_val, (pfm ? *pfm : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefGetMipmapLevelBias_entry,
  TP_ARGS(
    float *, pbias,
    CUtexref, hTexRef
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pbias, (uintptr_t)(pbias))
    ctf_integer_hex(uintptr_t, hTexRef, (uintptr_t)(hTexRef))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefGetMipmapLevelBias_exit,
  TP_ARGS(
    float *, pbias,
    CUtexref, hTexRef,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_float(float, pbias_val, (pbias ? *pbias : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefGetMipmapLevelClamp_entry,
  TP_ARGS(
    float *, pminMipmapLevelClamp,
    float *, pmaxMipmapLevelClamp,
    CUtexref, hTexRef
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pminMipmapLevelClamp, (uintptr_t)(pminMipmapLevelClamp))
    ctf_integer_hex(uintptr_t, pmaxMipmapLevelClamp, (uintptr_t)(pmaxMipmapLevelClamp))
    ctf_integer_hex(uintptr_t, hTexRef, (uintptr_t)(hTexRef))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefGetMipmapLevelClamp_exit,
  TP_ARGS(
    float *, pminMipmapLevelClamp,
    float *, pmaxMipmapLevelClamp,
    CUtexref, hTexRef,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_float(float, pminMipmapLevelClamp_val, (pminMipmapLevelClamp ? *pminMipmapLevelClamp : 0))
    ctf_float(float, pmaxMipmapLevelClamp_val, (pmaxMipmapLevelClamp ? *pmaxMipmapLevelClamp : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefGetMaxAnisotropy_entry,
  TP_ARGS(
    int *, pmaxAniso,
    CUtexref, hTexRef
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pmaxAniso, (uintptr_t)(pmaxAniso))
    ctf_integer_hex(uintptr_t, hTexRef, (uintptr_t)(hTexRef))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefGetMaxAnisotropy_exit,
  TP_ARGS(
    int *, pmaxAniso,
    CUtexref, hTexRef,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int, pmaxAniso_val, (pmaxAniso ? *pmaxAniso : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefGetBorderColor_entry,
  TP_ARGS(
    float *, pBorderColor,
    CUtexref, hTexRef
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pBorderColor, (uintptr_t)(pBorderColor))
    ctf_integer_hex(uintptr_t, hTexRef, (uintptr_t)(hTexRef))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefGetBorderColor_exit,
  TP_ARGS(
    float *, pBorderColor,
    CUtexref, hTexRef,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_float(float, pBorderColor_val, (pBorderColor ? *pBorderColor : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefGetFlags_entry,
  TP_ARGS(
    unsigned int *, pFlags,
    CUtexref, hTexRef
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pFlags, (uintptr_t)(pFlags))
    ctf_integer_hex(uintptr_t, hTexRef, (uintptr_t)(hTexRef))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefGetFlags_exit,
  TP_ARGS(
    unsigned int *, pFlags,
    CUtexref, hTexRef,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(unsigned int, pFlags_val, (pFlags ? *pFlags : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefCreate_entry,
  TP_ARGS(
    CUtexref *, pTexRef
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pTexRef, (uintptr_t)(pTexRef))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefCreate_exit,
  TP_ARGS(
    CUtexref *, pTexRef,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pTexRef_val, (uintptr_t)((pTexRef ? *pTexRef : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefDestroy_entry,
  TP_ARGS(
    CUtexref, hTexRef
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hTexRef, (uintptr_t)(hTexRef))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefDestroy_exit,
  TP_ARGS(
    CUtexref, hTexRef,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuSurfRefSetArray_entry,
  TP_ARGS(
    CUsurfref, hSurfRef,
    CUarray, hArray,
    unsigned int, Flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hSurfRef, (uintptr_t)(hSurfRef))
    ctf_integer_hex(uintptr_t, hArray, (uintptr_t)(hArray))
    ctf_integer(unsigned int, Flags, Flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuSurfRefSetArray_exit,
  TP_ARGS(
    CUsurfref, hSurfRef,
    CUarray, hArray,
    unsigned int, Flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuSurfRefGetArray_entry,
  TP_ARGS(
    CUarray *, phArray,
    CUsurfref, hSurfRef
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, phArray, (uintptr_t)(phArray))
    ctf_integer_hex(uintptr_t, hSurfRef, (uintptr_t)(hSurfRef))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuSurfRefGetArray_exit,
  TP_ARGS(
    CUarray *, phArray,
    CUsurfref, hSurfRef,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phArray_val, (uintptr_t)((phArray ? *phArray : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexObjectCreate_entry,
  TP_ARGS(
    CUtexObject *, pTexObject,
    const CUDA_RESOURCE_DESC *, pResDesc,
    const CUDA_TEXTURE_DESC *, pTexDesc,
    const CUDA_RESOURCE_VIEW_DESC *, pResViewDesc
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pTexObject, (uintptr_t)(pTexObject))
    ctf_integer_hex(uintptr_t, pResDesc, (uintptr_t)(pResDesc))
    ctf_integer_hex(uintptr_t, pTexDesc, (uintptr_t)(pTexDesc))
    ctf_integer_hex(uintptr_t, pResViewDesc, (uintptr_t)(pResViewDesc))
    ctf_sequence_text(uint8_t, pResDesc_val, pResDesc, size_t, (pResDesc ? sizeof(CUDA_RESOURCE_DESC) : 0))
    ctf_sequence_text(uint8_t, pTexDesc_val, pTexDesc, size_t, (pTexDesc ? sizeof(CUDA_TEXTURE_DESC) : 0))
    ctf_sequence_text(uint8_t, pResViewDesc_val, pResViewDesc, size_t, (pResViewDesc ? sizeof(CUDA_RESOURCE_VIEW_DESC) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexObjectCreate_exit,
  TP_ARGS(
    CUtexObject *, pTexObject,
    const CUDA_RESOURCE_DESC *, pResDesc,
    const CUDA_TEXTURE_DESC *, pTexDesc,
    const CUDA_RESOURCE_VIEW_DESC *, pResViewDesc,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(CUtexObject, pTexObject_val, (pTexObject ? *pTexObject : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexObjectDestroy_entry,
  TP_ARGS(
    CUtexObject, texObject
  ),
  TP_FIELDS(
    ctf_integer(CUtexObject, texObject, texObject)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexObjectDestroy_exit,
  TP_ARGS(
    CUtexObject, texObject,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexObjectGetResourceDesc_entry,
  TP_ARGS(
    CUDA_RESOURCE_DESC *, pResDesc,
    CUtexObject, texObject
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pResDesc, (uintptr_t)(pResDesc))
    ctf_integer(CUtexObject, texObject, texObject)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexObjectGetResourceDesc_exit,
  TP_ARGS(
    CUDA_RESOURCE_DESC *, pResDesc,
    CUtexObject, texObject,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, pResDesc_val, pResDesc, size_t, (pResDesc ? sizeof(CUDA_RESOURCE_DESC) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexObjectGetTextureDesc_entry,
  TP_ARGS(
    CUDA_TEXTURE_DESC *, pTexDesc,
    CUtexObject, texObject
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pTexDesc, (uintptr_t)(pTexDesc))
    ctf_integer(CUtexObject, texObject, texObject)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexObjectGetTextureDesc_exit,
  TP_ARGS(
    CUDA_TEXTURE_DESC *, pTexDesc,
    CUtexObject, texObject,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, pTexDesc_val, pTexDesc, size_t, (pTexDesc ? sizeof(CUDA_TEXTURE_DESC) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexObjectGetResourceViewDesc_entry,
  TP_ARGS(
    CUDA_RESOURCE_VIEW_DESC *, pResViewDesc,
    CUtexObject, texObject
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pResViewDesc, (uintptr_t)(pResViewDesc))
    ctf_integer(CUtexObject, texObject, texObject)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexObjectGetResourceViewDesc_exit,
  TP_ARGS(
    CUDA_RESOURCE_VIEW_DESC *, pResViewDesc,
    CUtexObject, texObject,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, pResViewDesc_val, pResViewDesc, size_t, (pResViewDesc ? sizeof(CUDA_RESOURCE_VIEW_DESC) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuSurfObjectCreate_entry,
  TP_ARGS(
    CUsurfObject *, pSurfObject,
    const CUDA_RESOURCE_DESC *, pResDesc
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pSurfObject, (uintptr_t)(pSurfObject))
    ctf_integer_hex(uintptr_t, pResDesc, (uintptr_t)(pResDesc))
    ctf_sequence_text(uint8_t, pResDesc_val, pResDesc, size_t, (pResDesc ? sizeof(CUDA_RESOURCE_DESC) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuSurfObjectCreate_exit,
  TP_ARGS(
    CUsurfObject *, pSurfObject,
    const CUDA_RESOURCE_DESC *, pResDesc,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(CUsurfObject, pSurfObject_val, (pSurfObject ? *pSurfObject : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuSurfObjectDestroy_entry,
  TP_ARGS(
    CUsurfObject, surfObject
  ),
  TP_FIELDS(
    ctf_integer(CUsurfObject, surfObject, surfObject)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuSurfObjectDestroy_exit,
  TP_ARGS(
    CUsurfObject, surfObject,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuSurfObjectGetResourceDesc_entry,
  TP_ARGS(
    CUDA_RESOURCE_DESC *, pResDesc,
    CUsurfObject, surfObject
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pResDesc, (uintptr_t)(pResDesc))
    ctf_integer(CUsurfObject, surfObject, surfObject)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuSurfObjectGetResourceDesc_exit,
  TP_ARGS(
    CUDA_RESOURCE_DESC *, pResDesc,
    CUsurfObject, surfObject,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, pResDesc_val, pResDesc, size_t, (pResDesc ? sizeof(CUDA_RESOURCE_DESC) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTensorMapEncodeTiled_entry,
  TP_ARGS(
    CUtensorMap *, tensorMap,
    CUtensorMapDataType, tensorDataType,
    cuuint32_t, tensorRank,
    void *, globalAddress,
    const cuuint64_t *, globalDim,
    const cuuint64_t *, globalStrides,
    const cuuint32_t *, boxDim,
    const cuuint32_t *, elementStrides,
    CUtensorMapInterleave, interleave,
    CUtensorMapSwizzle, swizzle,
    CUtensorMapL2promotion, l2Promotion,
    CUtensorMapFloatOOBfill, oobFill
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, tensorMap, (uintptr_t)(tensorMap))
    ctf_integer(int32_t, tensorDataType, tensorDataType)
    ctf_integer(cuuint32_t, tensorRank, tensorRank)
    ctf_integer_hex(uintptr_t, globalAddress, (uintptr_t)(globalAddress))
    ctf_integer_hex(uintptr_t, globalDim, (uintptr_t)(globalDim))
    ctf_integer_hex(uintptr_t, globalStrides, (uintptr_t)(globalStrides))
    ctf_integer_hex(uintptr_t, boxDim, (uintptr_t)(boxDim))
    ctf_integer_hex(uintptr_t, elementStrides, (uintptr_t)(elementStrides))
    ctf_integer(int32_t, interleave, interleave)
    ctf_integer(int32_t, swizzle, swizzle)
    ctf_integer(int32_t, l2Promotion, l2Promotion)
    ctf_integer(int32_t, oobFill, oobFill)
    ctf_sequence(cuuint64_t, globalDim_vals, globalDim, cuuint32_t, (globalDim ? tensorRank : 0))
    ctf_sequence(cuuint64_t, globalStrides_val, globalStrides, cuuint32_t, (tensorRank - 1))
    ctf_sequence(cuuint32_t, boxDim_vals, boxDim, cuuint32_t, (boxDim ? tensorRank : 0))
    ctf_sequence(cuuint32_t, elementStrides_vals, elementStrides, cuuint32_t, (elementStrides ? tensorRank : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTensorMapEncodeTiled_exit,
  TP_ARGS(
    CUtensorMap *, tensorMap,
    CUtensorMapDataType, tensorDataType,
    cuuint32_t, tensorRank,
    void *, globalAddress,
    const cuuint64_t *, globalDim,
    const cuuint64_t *, globalStrides,
    const cuuint32_t *, boxDim,
    const cuuint32_t *, elementStrides,
    CUtensorMapInterleave, interleave,
    CUtensorMapSwizzle, swizzle,
    CUtensorMapL2promotion, l2Promotion,
    CUtensorMapFloatOOBfill, oobFill,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, tensorMap_val, tensorMap, size_t, (tensorMap ? sizeof(CUtensorMap) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTensorMapEncodeIm2col_entry,
  TP_ARGS(
    CUtensorMap *, tensorMap,
    CUtensorMapDataType, tensorDataType,
    cuuint32_t, tensorRank,
    void *, globalAddress,
    const cuuint64_t *, globalDim,
    const cuuint64_t *, globalStrides,
    const int *, pixelBoxLowerCorner,
    const int *, pixelBoxUpperCorner,
    cuuint32_t, channelsPerPixel,
    cuuint32_t, pixelsPerColumn,
    const cuuint32_t *, elementStrides,
    CUtensorMapInterleave, interleave,
    CUtensorMapSwizzle, swizzle,
    CUtensorMapL2promotion, l2Promotion,
    CUtensorMapFloatOOBfill, oobFill
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, tensorMap, (uintptr_t)(tensorMap))
    ctf_integer(int32_t, tensorDataType, tensorDataType)
    ctf_integer(cuuint32_t, tensorRank, tensorRank)
    ctf_integer_hex(uintptr_t, globalAddress, (uintptr_t)(globalAddress))
    ctf_integer_hex(uintptr_t, globalDim, (uintptr_t)(globalDim))
    ctf_integer_hex(uintptr_t, globalStrides, (uintptr_t)(globalStrides))
    ctf_integer_hex(uintptr_t, pixelBoxLowerCorner, (uintptr_t)(pixelBoxLowerCorner))
    ctf_integer_hex(uintptr_t, pixelBoxUpperCorner, (uintptr_t)(pixelBoxUpperCorner))
    ctf_integer(cuuint32_t, channelsPerPixel, channelsPerPixel)
    ctf_integer(cuuint32_t, pixelsPerColumn, pixelsPerColumn)
    ctf_integer_hex(uintptr_t, elementStrides, (uintptr_t)(elementStrides))
    ctf_integer(int32_t, interleave, interleave)
    ctf_integer(int32_t, swizzle, swizzle)
    ctf_integer(int32_t, l2Promotion, l2Promotion)
    ctf_integer(int32_t, oobFill, oobFill)
    ctf_sequence(cuuint64_t, globalDim_vals, globalDim, cuuint32_t, (globalDim ? tensorRank : 0))
    ctf_sequence(cuuint64_t, globalStrides_val, globalStrides, cuuint32_t, (tensorRank - 1))
    ctf_array(int, pixelBoxLowerCorner_vals, pixelBoxLowerCorner, 3)
    ctf_array(int, pixelBoxUpperCorner_vals, pixelBoxUpperCorner, 3)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTensorMapEncodeIm2col_exit,
  TP_ARGS(
    CUtensorMap *, tensorMap,
    CUtensorMapDataType, tensorDataType,
    cuuint32_t, tensorRank,
    void *, globalAddress,
    const cuuint64_t *, globalDim,
    const cuuint64_t *, globalStrides,
    const int *, pixelBoxLowerCorner,
    const int *, pixelBoxUpperCorner,
    cuuint32_t, channelsPerPixel,
    cuuint32_t, pixelsPerColumn,
    const cuuint32_t *, elementStrides,
    CUtensorMapInterleave, interleave,
    CUtensorMapSwizzle, swizzle,
    CUtensorMapL2promotion, l2Promotion,
    CUtensorMapFloatOOBfill, oobFill,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, tensorMap_val, tensorMap, size_t, (tensorMap ? sizeof(CUtensorMap) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTensorMapEncodeIm2colWide_entry,
  TP_ARGS(
    CUtensorMap *, tensorMap,
    CUtensorMapDataType, tensorDataType,
    cuuint32_t, tensorRank,
    void *, globalAddress,
    const cuuint64_t *, globalDim,
    const cuuint64_t *, globalStrides,
    int, pixelBoxLowerCornerWidth,
    int, pixelBoxUpperCornerWidth,
    cuuint32_t, channelsPerPixel,
    cuuint32_t, pixelsPerColumn,
    const cuuint32_t *, elementStrides,
    CUtensorMapInterleave, interleave,
    CUtensorMapIm2ColWideMode, mode,
    CUtensorMapSwizzle, swizzle,
    CUtensorMapL2promotion, l2Promotion,
    CUtensorMapFloatOOBfill, oobFill
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, tensorMap, (uintptr_t)(tensorMap))
    ctf_integer(int32_t, tensorDataType, tensorDataType)
    ctf_integer(cuuint32_t, tensorRank, tensorRank)
    ctf_integer_hex(uintptr_t, globalAddress, (uintptr_t)(globalAddress))
    ctf_integer_hex(uintptr_t, globalDim, (uintptr_t)(globalDim))
    ctf_integer_hex(uintptr_t, globalStrides, (uintptr_t)(globalStrides))
    ctf_integer(int, pixelBoxLowerCornerWidth, pixelBoxLowerCornerWidth)
    ctf_integer(int, pixelBoxUpperCornerWidth, pixelBoxUpperCornerWidth)
    ctf_integer(cuuint32_t, channelsPerPixel, channelsPerPixel)
    ctf_integer(cuuint32_t, pixelsPerColumn, pixelsPerColumn)
    ctf_integer_hex(uintptr_t, elementStrides, (uintptr_t)(elementStrides))
    ctf_integer(int32_t, interleave, interleave)
    ctf_integer(int32_t, mode, mode)
    ctf_integer(int32_t, swizzle, swizzle)
    ctf_integer(int32_t, l2Promotion, l2Promotion)
    ctf_integer(int32_t, oobFill, oobFill)
    ctf_sequence(cuuint64_t, globalDim_vals, globalDim, cuuint32_t, (globalDim ? tensorRank : 0))
    ctf_sequence(cuuint64_t, globalStrides_vals, globalStrides, cuuint32_t, (globalStrides ? tensorRank : 0))
    ctf_sequence(cuuint32_t, elementStrides_vals, elementStrides, cuuint32_t, (elementStrides ? tensorRank : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTensorMapEncodeIm2colWide_exit,
  TP_ARGS(
    CUtensorMap *, tensorMap,
    CUtensorMapDataType, tensorDataType,
    cuuint32_t, tensorRank,
    void *, globalAddress,
    const cuuint64_t *, globalDim,
    const cuuint64_t *, globalStrides,
    int, pixelBoxLowerCornerWidth,
    int, pixelBoxUpperCornerWidth,
    cuuint32_t, channelsPerPixel,
    cuuint32_t, pixelsPerColumn,
    const cuuint32_t *, elementStrides,
    CUtensorMapInterleave, interleave,
    CUtensorMapIm2ColWideMode, mode,
    CUtensorMapSwizzle, swizzle,
    CUtensorMapL2promotion, l2Promotion,
    CUtensorMapFloatOOBfill, oobFill,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, tensorMap_val, tensorMap, size_t, (tensorMap ? sizeof(CUtensorMap) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTensorMapReplaceAddress_entry,
  TP_ARGS(
    CUtensorMap *, tensorMap,
    void *, globalAddress
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, tensorMap, (uintptr_t)(tensorMap))
    ctf_integer_hex(uintptr_t, globalAddress, (uintptr_t)(globalAddress))
    ctf_sequence_text(uint8_t, tensorMap_val, tensorMap, size_t, (tensorMap ? sizeof(CUtensorMap) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTensorMapReplaceAddress_exit,
  TP_ARGS(
    CUtensorMap *, tensorMap,
    void *, globalAddress,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceCanAccessPeer_entry,
  TP_ARGS(
    int *, canAccessPeer,
    CUdevice, dev,
    CUdevice, peerDev
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, canAccessPeer, (uintptr_t)(canAccessPeer))
    ctf_integer(CUdevice, dev, dev)
    ctf_integer(CUdevice, peerDev, peerDev)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceCanAccessPeer_exit,
  TP_ARGS(
    int *, canAccessPeer,
    CUdevice, dev,
    CUdevice, peerDev,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int, canAccessPeer_val, (canAccessPeer ? *canAccessPeer : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxEnablePeerAccess_entry,
  TP_ARGS(
    CUcontext, peerContext,
    unsigned int, Flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, peerContext, (uintptr_t)(peerContext))
    ctf_integer(unsigned int, Flags, Flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxEnablePeerAccess_exit,
  TP_ARGS(
    CUcontext, peerContext,
    unsigned int, Flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxDisablePeerAccess_entry,
  TP_ARGS(
    CUcontext, peerContext
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, peerContext, (uintptr_t)(peerContext))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxDisablePeerAccess_exit,
  TP_ARGS(
    CUcontext, peerContext,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetP2PAttribute_entry,
  TP_ARGS(
    int *, value,
    CUdevice_P2PAttribute, attrib,
    CUdevice, srcDevice,
    CUdevice, dstDevice
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, value, (uintptr_t)(value))
    ctf_integer(int32_t, attrib, attrib)
    ctf_integer(CUdevice, srcDevice, srcDevice)
    ctf_integer(CUdevice, dstDevice, dstDevice)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetP2PAttribute_exit,
  TP_ARGS(
    int *, value,
    CUdevice_P2PAttribute, attrib,
    CUdevice, srcDevice,
    CUdevice, dstDevice,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int, value_val, (value ? *value : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetP2PAtomicCapabilities_entry,
  TP_ARGS(
    unsigned int *, capabilities,
    const CUatomicOperation *, operations,
    unsigned int, count,
    CUdevice, srcDevice,
    CUdevice, dstDevice
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, capabilities, (uintptr_t)(capabilities))
    ctf_integer_hex(uintptr_t, operations, (uintptr_t)(operations))
    ctf_integer(unsigned int, count, count)
    ctf_integer(CUdevice, srcDevice, srcDevice)
    ctf_integer(CUdevice, dstDevice, dstDevice)
    ctf_sequence(int32_t, operations_vals, operations, unsigned int, (operations ? count : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetP2PAtomicCapabilities_exit,
  TP_ARGS(
    unsigned int *, capabilities,
    const CUatomicOperation *, operations,
    unsigned int, count,
    CUdevice, srcDevice,
    CUdevice, dstDevice,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence(unsigned int, capabilities_vals, capabilities, unsigned int, (capabilities ? count : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphicsUnregisterResource_entry,
  TP_ARGS(
    CUgraphicsResource, resource
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, resource, (uintptr_t)(resource))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphicsUnregisterResource_exit,
  TP_ARGS(
    CUgraphicsResource, resource,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphicsSubResourceGetMappedArray_entry,
  TP_ARGS(
    CUarray *, pArray,
    CUgraphicsResource, resource,
    unsigned int, arrayIndex,
    unsigned int, mipLevel
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pArray, (uintptr_t)(pArray))
    ctf_integer_hex(uintptr_t, resource, (uintptr_t)(resource))
    ctf_integer(unsigned int, arrayIndex, arrayIndex)
    ctf_integer(unsigned int, mipLevel, mipLevel)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphicsSubResourceGetMappedArray_exit,
  TP_ARGS(
    CUarray *, pArray,
    CUgraphicsResource, resource,
    unsigned int, arrayIndex,
    unsigned int, mipLevel,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pArray_val, (uintptr_t)((pArray ? *pArray : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphicsResourceGetMappedMipmappedArray_entry,
  TP_ARGS(
    CUmipmappedArray *, pMipmappedArray,
    CUgraphicsResource, resource
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pMipmappedArray, (uintptr_t)(pMipmappedArray))
    ctf_integer_hex(uintptr_t, resource, (uintptr_t)(resource))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphicsResourceGetMappedMipmappedArray_exit,
  TP_ARGS(
    CUmipmappedArray *, pMipmappedArray,
    CUgraphicsResource, resource,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pMipmappedArray_val, (uintptr_t)((pMipmappedArray ? *pMipmappedArray : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphicsResourceGetMappedPointer_v2_entry,
  TP_ARGS(
    CUdeviceptr *, pDevPtr,
    size_t *, pSize,
    CUgraphicsResource, resource
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pDevPtr, (uintptr_t)(pDevPtr))
    ctf_integer_hex(uintptr_t, pSize, (uintptr_t)(pSize))
    ctf_integer_hex(uintptr_t, resource, (uintptr_t)(resource))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphicsResourceGetMappedPointer_v2_exit,
  TP_ARGS(
    CUdeviceptr *, pDevPtr,
    size_t *, pSize,
    CUgraphicsResource, resource,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(CUdeviceptr, pDevPtr_val, (pDevPtr ? *pDevPtr : 0))
    ctf_integer(size_t, pSize_val, (pSize ? *pSize : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphicsResourceSetMapFlags_v2_entry,
  TP_ARGS(
    CUgraphicsResource, resource,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, resource, (uintptr_t)(resource))
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphicsResourceSetMapFlags_v2_exit,
  TP_ARGS(
    CUgraphicsResource, resource,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphicsMapResources_ptsz_entry,
  TP_ARGS(
    unsigned int, count,
    CUgraphicsResource *, resources,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer(unsigned int, count, count)
    ctf_integer_hex(uintptr_t, resources, (uintptr_t)(resources))
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphicsMapResources_ptsz_exit,
  TP_ARGS(
    unsigned int, count,
    CUgraphicsResource *, resources,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphicsUnmapResources_ptsz_entry,
  TP_ARGS(
    unsigned int, count,
    CUgraphicsResource *, resources,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer(unsigned int, count, count)
    ctf_integer_hex(uintptr_t, resources, (uintptr_t)(resources))
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphicsUnmapResources_ptsz_exit,
  TP_ARGS(
    unsigned int, count,
    CUgraphicsResource *, resources,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGetProcAddress_v2_entry,
  TP_ARGS(
    const char *, symbol,
    void **, pfn,
    int, cudaVersion,
    cuuint64_t, flags,
    CUdriverProcAddressQueryResult *, symbolStatus
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
    ctf_integer_hex(uintptr_t, pfn, (uintptr_t)(pfn))
    ctf_integer(int, cudaVersion, cudaVersion)
    ctf_integer(cuuint64_t, flags, flags)
    ctf_integer_hex(uintptr_t, symbolStatus, (uintptr_t)(symbolStatus))
    ctf_string(symbol_val, symbol)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGetProcAddress_v2_exit,
  TP_ARGS(
    const char *, symbol,
    void **, pfn,
    int, cudaVersion,
    cuuint64_t, flags,
    CUdriverProcAddressQueryResult *, symbolStatus,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pfn_val, (uintptr_t)((pfn ? *pfn : 0)))
    ctf_integer(int32_t, symbolStatus_val, (symbolStatus ? *symbolStatus : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCoredumpGetAttribute_entry,
  TP_ARGS(
    CUcoredumpSettings, attrib,
    void *, value,
    size_t *, size
  ),
  TP_FIELDS(
    ctf_integer(int32_t, attrib, attrib)
    ctf_integer_hex(uintptr_t, value, (uintptr_t)(value))
    ctf_integer_hex(uintptr_t, size, (uintptr_t)(size))
    ctf_integer(size_t, size_val, (size ? *size : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCoredumpGetAttribute_exit,
  TP_ARGS(
    CUcoredumpSettings, attrib,
    void *, value,
    size_t *, size,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(size_t, size_val, (size ? *size : 0))
    ctf_sequence_text(uint8_t, value_vals, value, size_t, ((size && value ? *size : 0)) * sizeof(uint8_t))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCoredumpGetAttributeGlobal_entry,
  TP_ARGS(
    CUcoredumpSettings, attrib,
    void *, value,
    size_t *, size
  ),
  TP_FIELDS(
    ctf_integer(int32_t, attrib, attrib)
    ctf_integer_hex(uintptr_t, value, (uintptr_t)(value))
    ctf_integer_hex(uintptr_t, size, (uintptr_t)(size))
    ctf_integer(size_t, size_val, (size ? *size : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCoredumpGetAttributeGlobal_exit,
  TP_ARGS(
    CUcoredumpSettings, attrib,
    void *, value,
    size_t *, size,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(size_t, size_val, (size ? *size : 0))
    ctf_sequence_text(uint8_t, value_vals, value, size_t, ((size && value ? *size : 0)) * sizeof(uint8_t))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCoredumpSetAttribute_entry,
  TP_ARGS(
    CUcoredumpSettings, attrib,
    void *, value,
    size_t *, size
  ),
  TP_FIELDS(
    ctf_integer(int32_t, attrib, attrib)
    ctf_integer_hex(uintptr_t, value, (uintptr_t)(value))
    ctf_integer_hex(uintptr_t, size, (uintptr_t)(size))
    ctf_integer(size_t, size_val, (size ? *size : 0))
    ctf_sequence_text(uint8_t, value_vals, value, size_t, ((size && value ? *size : 0)) * sizeof(uint8_t))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCoredumpSetAttribute_exit,
  TP_ARGS(
    CUcoredumpSettings, attrib,
    void *, value,
    size_t *, size,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(size_t, size_val, (size ? *size : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCoredumpSetAttributeGlobal_entry,
  TP_ARGS(
    CUcoredumpSettings, attrib,
    void *, value,
    size_t *, size
  ),
  TP_FIELDS(
    ctf_integer(int32_t, attrib, attrib)
    ctf_integer_hex(uintptr_t, value, (uintptr_t)(value))
    ctf_integer_hex(uintptr_t, size, (uintptr_t)(size))
    ctf_integer(size_t, size_val, (size ? *size : 0))
    ctf_sequence_text(uint8_t, value_vals, value, size_t, ((size && value ? *size : 0)) * sizeof(uint8_t))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCoredumpSetAttributeGlobal_exit,
  TP_ARGS(
    CUcoredumpSettings, attrib,
    void *, value,
    size_t *, size,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(size_t, size_val, (size ? *size : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGetExportTable_entry,
  TP_ARGS(
    const void **, ppExportTable,
    const CUuuid *, pExportTableId
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ppExportTable, (uintptr_t)(ppExportTable))
    ctf_integer_hex(uintptr_t, pExportTableId, (uintptr_t)(pExportTableId))
    ctf_sequence_text(uint8_t, pExportTableId_val, pExportTableId, size_t, (pExportTableId ? sizeof(CUuuid) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGetExportTable_exit,
  TP_ARGS(
    const void **, ppExportTable,
    const CUuuid *, pExportTableId,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, ppExportTable_val, (uintptr_t)((ppExportTable ? *ppExportTable : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGreenCtxCreate_entry,
  TP_ARGS(
    CUgreenCtx *, phCtx,
    CUdevResourceDesc, desc,
    CUdevice, dev,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, phCtx, (uintptr_t)(phCtx))
    ctf_integer_hex(uintptr_t, desc, (uintptr_t)(desc))
    ctf_integer(CUdevice, dev, dev)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGreenCtxCreate_exit,
  TP_ARGS(
    CUgreenCtx *, phCtx,
    CUdevResourceDesc, desc,
    CUdevice, dev,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phCtx_val, (uintptr_t)((phCtx ? *phCtx : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGreenCtxDestroy_entry,
  TP_ARGS(
    CUgreenCtx, hCtx
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hCtx, (uintptr_t)(hCtx))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGreenCtxDestroy_exit,
  TP_ARGS(
    CUgreenCtx, hCtx,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxFromGreenCtx_entry,
  TP_ARGS(
    CUcontext *, pContext,
    CUgreenCtx, hCtx
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pContext, (uintptr_t)(pContext))
    ctf_integer_hex(uintptr_t, hCtx, (uintptr_t)(hCtx))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxFromGreenCtx_exit,
  TP_ARGS(
    CUcontext *, pContext,
    CUgreenCtx, hCtx,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pContext_val, (uintptr_t)((pContext ? *pContext : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetDevResource_entry,
  TP_ARGS(
    CUdevice, device,
    CUdevResource *, resource,
    CUdevResourceType, type
  ),
  TP_FIELDS(
    ctf_integer(CUdevice, device, device)
    ctf_integer_hex(uintptr_t, resource, (uintptr_t)(resource))
    ctf_integer(int32_t, type, type)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetDevResource_exit,
  TP_ARGS(
    CUdevice, device,
    CUdevResource *, resource,
    CUdevResourceType, type,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, resource_val, resource, size_t, (resource ? sizeof(CUdevResource) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxGetDevResource_entry,
  TP_ARGS(
    CUcontext, hCtx,
    CUdevResource *, resource,
    CUdevResourceType, type
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hCtx, (uintptr_t)(hCtx))
    ctf_integer_hex(uintptr_t, resource, (uintptr_t)(resource))
    ctf_integer(int32_t, type, type)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxGetDevResource_exit,
  TP_ARGS(
    CUcontext, hCtx,
    CUdevResource *, resource,
    CUdevResourceType, type,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, resource_val, resource, size_t, (resource ? sizeof(CUdevResource) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGreenCtxGetDevResource_entry,
  TP_ARGS(
    CUgreenCtx, hCtx,
    CUdevResource *, resource,
    CUdevResourceType, type
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hCtx, (uintptr_t)(hCtx))
    ctf_integer_hex(uintptr_t, resource, (uintptr_t)(resource))
    ctf_integer(int32_t, type, type)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGreenCtxGetDevResource_exit,
  TP_ARGS(
    CUgreenCtx, hCtx,
    CUdevResource *, resource,
    CUdevResourceType, type,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, resource_val, resource, size_t, (resource ? sizeof(CUdevResource) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDevSmResourceSplitByCount_entry,
  TP_ARGS(
    CUdevResource *, result,
    unsigned int *, nbGroups,
    const CUdevResource *, input,
    CUdevResource *, remaining,
    unsigned int, useFlags,
    unsigned int, minCount
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, result, (uintptr_t)(result))
    ctf_integer_hex(uintptr_t, nbGroups, (uintptr_t)(nbGroups))
    ctf_integer_hex(uintptr_t, input, (uintptr_t)(input))
    ctf_integer_hex(uintptr_t, remaining, (uintptr_t)(remaining))
    ctf_integer(unsigned int, useFlags, useFlags)
    ctf_integer(unsigned int, minCount, minCount)
    ctf_integer(unsigned int, nbGroups_val, (nbGroups ? *nbGroups : 0))
    ctf_sequence_text(uint8_t, input_val, input, size_t, (input ? sizeof(CUdevResource) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDevSmResourceSplitByCount_exit,
  TP_ARGS(
    CUdevResource *, result,
    unsigned int *, nbGroups,
    const CUdevResource *, input,
    CUdevResource *, remaining,
    unsigned int, useFlags,
    unsigned int, minCount,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(unsigned int, nbGroups_val, (nbGroups ? *nbGroups : 0))
    ctf_sequence_text(uint8_t, result_vals, result, size_t, ((nbGroups && result ? *nbGroups : 0)) * sizeof(CUdevResource))
    ctf_sequence_text(uint8_t, remaining_val, remaining, size_t, (remaining ? sizeof(CUdevResource) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDevResourceGenerateDesc_entry,
  TP_ARGS(
    CUdevResourceDesc *, phDesc,
    CUdevResource *, resources,
    unsigned int, nbResources
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, phDesc, (uintptr_t)(phDesc))
    ctf_integer_hex(uintptr_t, resources, (uintptr_t)(resources))
    ctf_integer(unsigned int, nbResources, nbResources)
    ctf_sequence_text(uint8_t, resources_vals, resources, size_t, ((resources ? nbResources : 0)) * sizeof(CUdevResource))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDevResourceGenerateDesc_exit,
  TP_ARGS(
    CUdevResourceDesc *, phDesc,
    CUdevResource *, resources,
    unsigned int, nbResources,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phDesc_val, (uintptr_t)((phDesc ? *phDesc : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGreenCtxRecordEvent_entry,
  TP_ARGS(
    CUgreenCtx, hCtx,
    CUevent, hEvent
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hCtx, (uintptr_t)(hCtx))
    ctf_integer_hex(uintptr_t, hEvent, (uintptr_t)(hEvent))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGreenCtxRecordEvent_exit,
  TP_ARGS(
    CUgreenCtx, hCtx,
    CUevent, hEvent,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGreenCtxWaitEvent_entry,
  TP_ARGS(
    CUgreenCtx, hCtx,
    CUevent, hEvent
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hCtx, (uintptr_t)(hCtx))
    ctf_integer_hex(uintptr_t, hEvent, (uintptr_t)(hEvent))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGreenCtxWaitEvent_exit,
  TP_ARGS(
    CUgreenCtx, hCtx,
    CUevent, hEvent,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetGreenCtx_entry,
  TP_ARGS(
    CUstream, hStream,
    CUgreenCtx *, phCtx
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, phCtx, (uintptr_t)(phCtx))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetGreenCtx_exit,
  TP_ARGS(
    CUstream, hStream,
    CUgreenCtx *, phCtx,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phCtx_val, (uintptr_t)((phCtx ? *phCtx : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGreenCtxStreamCreate_entry,
  TP_ARGS(
    CUstream *, phStream,
    CUgreenCtx, greenCtx,
    unsigned int, flags,
    int, priority
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, phStream, (uintptr_t)(phStream))
    ctf_integer_hex(uintptr_t, greenCtx, (uintptr_t)(greenCtx))
    ctf_integer(unsigned int, flags, flags)
    ctf_integer(int, priority, priority)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGreenCtxStreamCreate_exit,
  TP_ARGS(
    CUstream *, phStream,
    CUgreenCtx, greenCtx,
    unsigned int, flags,
    int, priority,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phStream_val, (uintptr_t)((phStream ? *phStream : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGreenCtxGetId_entry,
  TP_ARGS(
    CUgreenCtx, greenCtx,
    unsigned long long int *, greenCtxId
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, greenCtx, (uintptr_t)(greenCtx))
    ctf_integer_hex(uintptr_t, greenCtxId, (uintptr_t)(greenCtxId))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGreenCtxGetId_exit,
  TP_ARGS(
    CUgreenCtx, greenCtx,
    unsigned long long int *, greenCtxId,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(unsigned long long int, greenCtxId_val, (greenCtxId ? *greenCtxId : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLogsRegisterCallback_entry,
  TP_ARGS(
    CUlogsCallback, callbackFunc,
    void *, userData,
    CUlogsCallbackHandle *, callback_out
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, callbackFunc, (uintptr_t)(callbackFunc))
    ctf_integer_hex(uintptr_t, userData, (uintptr_t)(userData))
    ctf_integer_hex(uintptr_t, callback_out, (uintptr_t)(callback_out))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLogsRegisterCallback_exit,
  TP_ARGS(
    CUlogsCallback, callbackFunc,
    void *, userData,
    CUlogsCallbackHandle *, callback_out,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, callback_out_val, (uintptr_t)((callback_out ? *callback_out : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLogsUnregisterCallback_entry,
  TP_ARGS(
    CUlogsCallbackHandle, callback
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, callback, (uintptr_t)(callback))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLogsUnregisterCallback_exit,
  TP_ARGS(
    CUlogsCallbackHandle, callback,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLogsCurrent_entry,
  TP_ARGS(
    CUlogIterator *, iterator_out,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, iterator_out, (uintptr_t)(iterator_out))
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLogsCurrent_exit,
  TP_ARGS(
    CUlogIterator *, iterator_out,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(CUlogIterator, iterator_out_val, (iterator_out ? *iterator_out : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLogsDumpToFile_entry,
  TP_ARGS(
    CUlogIterator *, iterator,
    const char *, pathToFile,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, iterator, (uintptr_t)(iterator))
    ctf_integer_hex(uintptr_t, pathToFile, (uintptr_t)(pathToFile))
    ctf_integer(unsigned int, flags, flags)
    ctf_integer(CUlogIterator, iterator_val, (iterator ? *iterator : 0))
    ctf_string(pathToFile_val, pathToFile)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLogsDumpToFile_exit,
  TP_ARGS(
    CUlogIterator *, iterator,
    const char *, pathToFile,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLogsDumpToMemory_entry,
  TP_ARGS(
    CUlogIterator *, iterator,
    char *, buffer,
    size_t *, size,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, iterator, (uintptr_t)(iterator))
    ctf_integer_hex(uintptr_t, buffer, (uintptr_t)(buffer))
    ctf_integer_hex(uintptr_t, size, (uintptr_t)(size))
    ctf_integer(unsigned int, flags, flags)
    ctf_integer(CUlogIterator, iterator_val, (iterator ? *iterator : 0))
    ctf_integer(size_t, size_val, (size ? *size : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLogsDumpToMemory_exit,
  TP_ARGS(
    CUlogIterator *, iterator,
    char *, buffer,
    size_t *, size,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(size_t, size_val, (size ? *size : 0))
    ctf_sequence_text(char, buffer_vals, buffer, size_t, (size && buffer ? *size : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemHostRegister_entry,
  TP_ARGS(
    void *, p,
    size_t, bytesize,
    unsigned int, Flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_integer(size_t, bytesize, bytesize)
    ctf_integer(unsigned int, Flags, Flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemHostRegister_exit,
  TP_ARGS(
    void *, p,
    size_t, bytesize,
    unsigned int, Flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphicsResourceSetMapFlags_entry,
  TP_ARGS(
    CUgraphicsResource, resource,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, resource, (uintptr_t)(resource))
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphicsResourceSetMapFlags_exit,
  TP_ARGS(
    CUgraphicsResource, resource,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLinkCreate_entry,
  TP_ARGS(
    unsigned int, numOptions,
    CUjit_option *, options,
    void **, optionValues,
    CUlinkState *, stateOut
  ),
  TP_FIELDS(
    ctf_integer(unsigned int, numOptions, numOptions)
    ctf_integer_hex(uintptr_t, options, (uintptr_t)(options))
    ctf_integer_hex(uintptr_t, optionValues, (uintptr_t)(optionValues))
    ctf_integer_hex(uintptr_t, stateOut, (uintptr_t)(stateOut))
    ctf_sequence(int32_t, options_vals, options, unsigned int, (options ? numOptions : 0))
    ctf_sequence_hex(uintptr_t, optionValues_vals, optionValues, unsigned int, (optionValues ? numOptions : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLinkCreate_exit,
  TP_ARGS(
    unsigned int, numOptions,
    CUjit_option *, options,
    void **, optionValues,
    CUlinkState *, stateOut,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, stateOut_val, (uintptr_t)((stateOut ? *stateOut : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLinkAddData_entry,
  TP_ARGS(
    CUlinkState, state,
    CUjitInputType, type,
    void *, data,
    size_t, size,
    const char *, name,
    unsigned int, numOptions,
    CUjit_option *, options,
    void **, optionValues
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, state, (uintptr_t)(state))
    ctf_integer(int32_t, type, type)
    ctf_integer_hex(uintptr_t, data, (uintptr_t)(data))
    ctf_integer(size_t, size, size)
    ctf_integer_hex(uintptr_t, name, (uintptr_t)(name))
    ctf_integer(unsigned int, numOptions, numOptions)
    ctf_integer_hex(uintptr_t, options, (uintptr_t)(options))
    ctf_integer_hex(uintptr_t, optionValues, (uintptr_t)(optionValues))
    ctf_string(name_val, name)
    ctf_sequence(int32_t, options_vals, options, unsigned int, (options ? numOptions : 0))
    ctf_sequence_hex(uintptr_t, optionValues_vals, optionValues, unsigned int, (optionValues ? numOptions : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLinkAddData_exit,
  TP_ARGS(
    CUlinkState, state,
    CUjitInputType, type,
    void *, data,
    size_t, size,
    const char *, name,
    unsigned int, numOptions,
    CUjit_option *, options,
    void **, optionValues,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLinkAddFile_entry,
  TP_ARGS(
    CUlinkState, state,
    CUjitInputType, type,
    const char *, path,
    unsigned int, numOptions,
    CUjit_option *, options,
    void **, optionValues
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, state, (uintptr_t)(state))
    ctf_integer(int32_t, type, type)
    ctf_integer_hex(uintptr_t, path, (uintptr_t)(path))
    ctf_integer(unsigned int, numOptions, numOptions)
    ctf_integer_hex(uintptr_t, options, (uintptr_t)(options))
    ctf_integer_hex(uintptr_t, optionValues, (uintptr_t)(optionValues))
    ctf_string(path_val, path)
    ctf_sequence(int32_t, options_vals, options, unsigned int, (options ? numOptions : 0))
    ctf_sequence_hex(uintptr_t, optionValues_vals, optionValues, unsigned int, (optionValues ? numOptions : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLinkAddFile_exit,
  TP_ARGS(
    CUlinkState, state,
    CUjitInputType, type,
    const char *, path,
    unsigned int, numOptions,
    CUjit_option *, options,
    void **, optionValues,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefSetAddress2D_v2_entry,
  TP_ARGS(
    CUtexref, hTexRef,
    const CUDA_ARRAY_DESCRIPTOR *, desc,
    CUdeviceptr, dptr,
    size_t, Pitch
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hTexRef, (uintptr_t)(hTexRef))
    ctf_integer_hex(uintptr_t, desc, (uintptr_t)(desc))
    ctf_integer_hex(CUdeviceptr, dptr, dptr)
    ctf_integer(size_t, Pitch, Pitch)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefSetAddress2D_v2_exit,
  TP_ARGS(
    CUtexref, hTexRef,
    const CUDA_ARRAY_DESCRIPTOR *, desc,
    CUdeviceptr, dptr,
    size_t, Pitch,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceTotalMem_entry,
  TP_ARGS(
    unsigned int *, bytes,
    CUdevice, dev
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, bytes, (uintptr_t)(bytes))
    ctf_integer(CUdevice, dev, dev)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceTotalMem_exit,
  TP_ARGS(
    unsigned int *, bytes,
    CUdevice, dev,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(unsigned int, bytes_val, (bytes ? *bytes : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxCreate_entry,
  TP_ARGS(
    CUcontext *, pctx,
    unsigned int, flags,
    CUdevice, dev
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pctx, (uintptr_t)(pctx))
    ctf_integer(unsigned int, flags, flags)
    ctf_integer(CUdevice, dev, dev)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxCreate_exit,
  TP_ARGS(
    CUcontext *, pctx,
    unsigned int, flags,
    CUdevice, dev,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pctx_val, (uintptr_t)((pctx ? *pctx : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxCreate_v2_entry,
  TP_ARGS(
    CUcontext *, pctx,
    unsigned int, flags,
    CUdevice, dev
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pctx, (uintptr_t)(pctx))
    ctf_integer(unsigned int, flags, flags)
    ctf_integer(CUdevice, dev, dev)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxCreate_v2_exit,
  TP_ARGS(
    CUcontext *, pctx,
    unsigned int, flags,
    CUdevice, dev,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pctx_val, (uintptr_t)((pctx ? *pctx : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxCreate_v3_entry,
  TP_ARGS(
    CUcontext *, pctx,
    CUexecAffinityParam *, paramsArray,
    int, numParams,
    unsigned int, flags,
    CUdevice, dev
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pctx, (uintptr_t)(pctx))
    ctf_integer_hex(uintptr_t, paramsArray, (uintptr_t)(paramsArray))
    ctf_integer(int, numParams, numParams)
    ctf_integer(unsigned int, flags, flags)
    ctf_integer(CUdevice, dev, dev)
    ctf_sequence_text(uint8_t, paramsArray_vals, paramsArray, size_t, ((paramsArray ? (numParams < 0 ? 0 : (size_t)numParams) : 0)) * sizeof(CUexecAffinityParam))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxCreate_v3_exit,
  TP_ARGS(
    CUcontext *, pctx,
    CUexecAffinityParam *, paramsArray,
    int, numParams,
    unsigned int, flags,
    CUdevice, dev,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pctx_val, (uintptr_t)((pctx ? *pctx : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuModuleGetGlobal_entry,
  TP_ARGS(
    CUdeviceptr_v1 *, dptr,
    unsigned int *, bytes,
    CUmodule, hmod,
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
  lttng_ust_cuda,
  cuModuleGetGlobal_exit,
  TP_ARGS(
    CUdeviceptr_v1 *, dptr,
    unsigned int *, bytes,
    CUmodule, hmod,
    const char *, name,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(CUdeviceptr_v1, dptr_val, (dptr ? *dptr : 0))
    ctf_integer(unsigned int, bytes_val, (bytes ? *bytes : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemGetInfo_entry,
  TP_ARGS(
    unsigned int *, free,
    unsigned int *, total
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, free, (uintptr_t)(free))
    ctf_integer_hex(uintptr_t, total, (uintptr_t)(total))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemGetInfo_exit,
  TP_ARGS(
    unsigned int *, free,
    unsigned int *, total,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(unsigned int, free_val, (free ? *free : 0))
    ctf_integer(unsigned int, total_val, (total ? *total : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemAlloc_entry,
  TP_ARGS(
    CUdeviceptr_v1 *, dptr,
    unsigned int, bytesize
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dptr, (uintptr_t)(dptr))
    ctf_integer(unsigned int, bytesize, bytesize)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemAlloc_exit,
  TP_ARGS(
    CUdeviceptr_v1 *, dptr,
    unsigned int, bytesize,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(CUdeviceptr_v1, dptr_val, (dptr ? *dptr : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemAllocPitch_entry,
  TP_ARGS(
    CUdeviceptr_v1 *, dptr,
    unsigned int *, pPitch,
    unsigned int, WidthInBytes,
    unsigned int, Height,
    unsigned int, ElementSizeBytes
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dptr, (uintptr_t)(dptr))
    ctf_integer_hex(uintptr_t, pPitch, (uintptr_t)(pPitch))
    ctf_integer(unsigned int, WidthInBytes, WidthInBytes)
    ctf_integer(unsigned int, Height, Height)
    ctf_integer(unsigned int, ElementSizeBytes, ElementSizeBytes)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemAllocPitch_exit,
  TP_ARGS(
    CUdeviceptr_v1 *, dptr,
    unsigned int *, pPitch,
    unsigned int, WidthInBytes,
    unsigned int, Height,
    unsigned int, ElementSizeBytes,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(CUdeviceptr_v1, dptr_val, (dptr ? *dptr : 0))
    ctf_integer(unsigned int, pPitch_val, (pPitch ? *pPitch : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemFree_entry,
  TP_ARGS(
    CUdeviceptr_v1, dptr
  ),
  TP_FIELDS(
    ctf_integer(CUdeviceptr_v1, dptr, dptr)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemFree_exit,
  TP_ARGS(
    CUdeviceptr_v1, dptr,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemGetAddressRange_entry,
  TP_ARGS(
    CUdeviceptr_v1 *, pbase,
    unsigned int *, psize,
    CUdeviceptr_v1, dptr
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pbase, (uintptr_t)(pbase))
    ctf_integer_hex(uintptr_t, psize, (uintptr_t)(psize))
    ctf_integer(CUdeviceptr_v1, dptr, dptr)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemGetAddressRange_exit,
  TP_ARGS(
    CUdeviceptr_v1 *, pbase,
    unsigned int *, psize,
    CUdeviceptr_v1, dptr,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(CUdeviceptr_v1, pbase_val, (pbase ? *pbase : 0))
    ctf_integer(unsigned int, psize_val, (psize ? *psize : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemAllocHost_entry,
  TP_ARGS(
    void **, pp,
    unsigned int, bytesize
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pp, (uintptr_t)(pp))
    ctf_integer(unsigned int, bytesize, bytesize)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemAllocHost_exit,
  TP_ARGS(
    void **, pp,
    unsigned int, bytesize,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pp_val, (uintptr_t)((pp ? *pp : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemHostGetDevicePointer_entry,
  TP_ARGS(
    CUdeviceptr_v1 *, pdptr,
    void *, p,
    unsigned int, Flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pdptr, (uintptr_t)(pdptr))
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_integer(unsigned int, Flags, Flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemHostGetDevicePointer_exit,
  TP_ARGS(
    CUdeviceptr_v1 *, pdptr,
    void *, p,
    unsigned int, Flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(CUdeviceptr_v1, pdptr_val, (pdptr ? *pdptr : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyHtoD_entry,
  TP_ARGS(
    CUdeviceptr_v1, dstDevice,
    const void *, srcHost,
    unsigned int, ByteCount
  ),
  TP_FIELDS(
    ctf_integer(CUdeviceptr_v1, dstDevice, dstDevice)
    ctf_integer_hex(uintptr_t, srcHost, (uintptr_t)(srcHost))
    ctf_integer(unsigned int, ByteCount, ByteCount)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyHtoD_exit,
  TP_ARGS(
    CUdeviceptr_v1, dstDevice,
    const void *, srcHost,
    unsigned int, ByteCount,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyDtoH_entry,
  TP_ARGS(
    void *, dstHost,
    CUdeviceptr_v1, srcDevice,
    unsigned int, ByteCount
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dstHost, (uintptr_t)(dstHost))
    ctf_integer(CUdeviceptr_v1, srcDevice, srcDevice)
    ctf_integer(unsigned int, ByteCount, ByteCount)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyDtoH_exit,
  TP_ARGS(
    void *, dstHost,
    CUdeviceptr_v1, srcDevice,
    unsigned int, ByteCount,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyDtoD_entry,
  TP_ARGS(
    CUdeviceptr_v1, dstDevice,
    CUdeviceptr_v1, srcDevice,
    unsigned int, ByteCount
  ),
  TP_FIELDS(
    ctf_integer(CUdeviceptr_v1, dstDevice, dstDevice)
    ctf_integer(CUdeviceptr_v1, srcDevice, srcDevice)
    ctf_integer(unsigned int, ByteCount, ByteCount)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyDtoD_exit,
  TP_ARGS(
    CUdeviceptr_v1, dstDevice,
    CUdeviceptr_v1, srcDevice,
    unsigned int, ByteCount,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyDtoA_entry,
  TP_ARGS(
    CUarray, dstArray,
    unsigned int, dstOffset,
    CUdeviceptr_v1, srcDevice,
    unsigned int, ByteCount
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dstArray, (uintptr_t)(dstArray))
    ctf_integer(unsigned int, dstOffset, dstOffset)
    ctf_integer(CUdeviceptr_v1, srcDevice, srcDevice)
    ctf_integer(unsigned int, ByteCount, ByteCount)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyDtoA_exit,
  TP_ARGS(
    CUarray, dstArray,
    unsigned int, dstOffset,
    CUdeviceptr_v1, srcDevice,
    unsigned int, ByteCount,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyAtoD_entry,
  TP_ARGS(
    CUdeviceptr_v1, dstDevice,
    CUarray, srcArray,
    unsigned int, srcOffset,
    unsigned int, ByteCount
  ),
  TP_FIELDS(
    ctf_integer(CUdeviceptr_v1, dstDevice, dstDevice)
    ctf_integer_hex(uintptr_t, srcArray, (uintptr_t)(srcArray))
    ctf_integer(unsigned int, srcOffset, srcOffset)
    ctf_integer(unsigned int, ByteCount, ByteCount)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyAtoD_exit,
  TP_ARGS(
    CUdeviceptr_v1, dstDevice,
    CUarray, srcArray,
    unsigned int, srcOffset,
    unsigned int, ByteCount,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyHtoA_entry,
  TP_ARGS(
    CUarray, dstArray,
    unsigned int, dstOffset,
    const void *, srcHost,
    unsigned int, ByteCount
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dstArray, (uintptr_t)(dstArray))
    ctf_integer(unsigned int, dstOffset, dstOffset)
    ctf_integer_hex(uintptr_t, srcHost, (uintptr_t)(srcHost))
    ctf_integer(unsigned int, ByteCount, ByteCount)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyHtoA_exit,
  TP_ARGS(
    CUarray, dstArray,
    unsigned int, dstOffset,
    const void *, srcHost,
    unsigned int, ByteCount,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyAtoH_entry,
  TP_ARGS(
    void *, dstHost,
    CUarray, srcArray,
    unsigned int, srcOffset,
    unsigned int, ByteCount
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dstHost, (uintptr_t)(dstHost))
    ctf_integer_hex(uintptr_t, srcArray, (uintptr_t)(srcArray))
    ctf_integer(unsigned int, srcOffset, srcOffset)
    ctf_integer(unsigned int, ByteCount, ByteCount)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyAtoH_exit,
  TP_ARGS(
    void *, dstHost,
    CUarray, srcArray,
    unsigned int, srcOffset,
    unsigned int, ByteCount,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyAtoA_entry,
  TP_ARGS(
    CUarray, dstArray,
    unsigned int, dstOffset,
    CUarray, srcArray,
    unsigned int, srcOffset,
    unsigned int, ByteCount
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dstArray, (uintptr_t)(dstArray))
    ctf_integer(unsigned int, dstOffset, dstOffset)
    ctf_integer_hex(uintptr_t, srcArray, (uintptr_t)(srcArray))
    ctf_integer(unsigned int, srcOffset, srcOffset)
    ctf_integer(unsigned int, ByteCount, ByteCount)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyAtoA_exit,
  TP_ARGS(
    CUarray, dstArray,
    unsigned int, dstOffset,
    CUarray, srcArray,
    unsigned int, srcOffset,
    unsigned int, ByteCount,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyHtoAAsync_entry,
  TP_ARGS(
    CUarray, dstArray,
    unsigned int, dstOffset,
    const void *, srcHost,
    unsigned int, ByteCount,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dstArray, (uintptr_t)(dstArray))
    ctf_integer(unsigned int, dstOffset, dstOffset)
    ctf_integer_hex(uintptr_t, srcHost, (uintptr_t)(srcHost))
    ctf_integer(unsigned int, ByteCount, ByteCount)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyHtoAAsync_exit,
  TP_ARGS(
    CUarray, dstArray,
    unsigned int, dstOffset,
    const void *, srcHost,
    unsigned int, ByteCount,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyAtoHAsync_entry,
  TP_ARGS(
    void *, dstHost,
    CUarray, srcArray,
    unsigned int, srcOffset,
    unsigned int, ByteCount,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dstHost, (uintptr_t)(dstHost))
    ctf_integer_hex(uintptr_t, srcArray, (uintptr_t)(srcArray))
    ctf_integer(unsigned int, srcOffset, srcOffset)
    ctf_integer(unsigned int, ByteCount, ByteCount)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyAtoHAsync_exit,
  TP_ARGS(
    void *, dstHost,
    CUarray, srcArray,
    unsigned int, srcOffset,
    unsigned int, ByteCount,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy2D_entry,
  TP_ARGS(
    const CUDA_MEMCPY2D_v1 *, pCopy
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pCopy, (uintptr_t)(pCopy))
    ctf_sequence_text(uint8_t, pCopy_val, pCopy, size_t, (pCopy ? sizeof(CUDA_MEMCPY2D_v1) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy2D_exit,
  TP_ARGS(
    const CUDA_MEMCPY2D_v1 *, pCopy,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy2DUnaligned_entry,
  TP_ARGS(
    const CUDA_MEMCPY2D_v1 *, pCopy
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pCopy, (uintptr_t)(pCopy))
    ctf_sequence_text(uint8_t, pCopy_val, pCopy, size_t, (pCopy ? sizeof(CUDA_MEMCPY2D_v1) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy2DUnaligned_exit,
  TP_ARGS(
    const CUDA_MEMCPY2D_v1 *, pCopy,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy3D_entry,
  TP_ARGS(
    const CUDA_MEMCPY3D_v1 *, pCopy
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pCopy, (uintptr_t)(pCopy))
    ctf_sequence_text(uint8_t, pCopy_val, pCopy, size_t, (pCopy ? sizeof(CUDA_MEMCPY3D_v1) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy3D_exit,
  TP_ARGS(
    const CUDA_MEMCPY3D_v1 *, pCopy,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyHtoDAsync_entry,
  TP_ARGS(
    CUdeviceptr_v1, dstDevice,
    const void *, srcHost,
    unsigned int, ByteCount,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer(CUdeviceptr_v1, dstDevice, dstDevice)
    ctf_integer_hex(uintptr_t, srcHost, (uintptr_t)(srcHost))
    ctf_integer(unsigned int, ByteCount, ByteCount)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyHtoDAsync_exit,
  TP_ARGS(
    CUdeviceptr_v1, dstDevice,
    const void *, srcHost,
    unsigned int, ByteCount,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyDtoHAsync_entry,
  TP_ARGS(
    void *, dstHost,
    CUdeviceptr_v1, srcDevice,
    unsigned int, ByteCount,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dstHost, (uintptr_t)(dstHost))
    ctf_integer(CUdeviceptr_v1, srcDevice, srcDevice)
    ctf_integer(unsigned int, ByteCount, ByteCount)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyDtoHAsync_exit,
  TP_ARGS(
    void *, dstHost,
    CUdeviceptr_v1, srcDevice,
    unsigned int, ByteCount,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyDtoDAsync_entry,
  TP_ARGS(
    CUdeviceptr_v1, dstDevice,
    CUdeviceptr_v1, srcDevice,
    unsigned int, ByteCount,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer(CUdeviceptr_v1, dstDevice, dstDevice)
    ctf_integer(CUdeviceptr_v1, srcDevice, srcDevice)
    ctf_integer(unsigned int, ByteCount, ByteCount)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyDtoDAsync_exit,
  TP_ARGS(
    CUdeviceptr_v1, dstDevice,
    CUdeviceptr_v1, srcDevice,
    unsigned int, ByteCount,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy2DAsync_entry,
  TP_ARGS(
    const CUDA_MEMCPY2D_v1 *, pCopy,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pCopy, (uintptr_t)(pCopy))
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_sequence_text(uint8_t, pCopy_val, pCopy, size_t, (pCopy ? sizeof(CUDA_MEMCPY2D_v1) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy2DAsync_exit,
  TP_ARGS(
    const CUDA_MEMCPY2D_v1 *, pCopy,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy3DAsync_entry,
  TP_ARGS(
    const CUDA_MEMCPY3D_v1 *, pCopy,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pCopy, (uintptr_t)(pCopy))
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_sequence_text(uint8_t, pCopy_val, pCopy, size_t, (pCopy ? sizeof(CUDA_MEMCPY3D_v1) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy3DAsync_exit,
  TP_ARGS(
    const CUDA_MEMCPY3D_v1 *, pCopy,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD8_entry,
  TP_ARGS(
    CUdeviceptr_v1, dstDevice,
    unsigned char, uc,
    unsigned int, N
  ),
  TP_FIELDS(
    ctf_integer(CUdeviceptr_v1, dstDevice, dstDevice)
    ctf_integer(unsigned char, uc, uc)
    ctf_integer(unsigned int, N, N)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD8_exit,
  TP_ARGS(
    CUdeviceptr_v1, dstDevice,
    unsigned char, uc,
    unsigned int, N,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD16_entry,
  TP_ARGS(
    CUdeviceptr_v1, dstDevice,
    unsigned short int, us,
    unsigned int, N
  ),
  TP_FIELDS(
    ctf_integer(CUdeviceptr_v1, dstDevice, dstDevice)
    ctf_integer(unsigned short int, us, us)
    ctf_integer(unsigned int, N, N)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD16_exit,
  TP_ARGS(
    CUdeviceptr_v1, dstDevice,
    unsigned short int, us,
    unsigned int, N,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD32_entry,
  TP_ARGS(
    CUdeviceptr_v1, dstDevice,
    unsigned int, ui,
    unsigned int, N
  ),
  TP_FIELDS(
    ctf_integer(CUdeviceptr_v1, dstDevice, dstDevice)
    ctf_integer(unsigned int, ui, ui)
    ctf_integer(unsigned int, N, N)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD32_exit,
  TP_ARGS(
    CUdeviceptr_v1, dstDevice,
    unsigned int, ui,
    unsigned int, N,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD2D8_entry,
  TP_ARGS(
    CUdeviceptr_v1, dstDevice,
    unsigned int, dstPitch,
    unsigned char, uc,
    unsigned int, Width,
    unsigned int, Height
  ),
  TP_FIELDS(
    ctf_integer(CUdeviceptr_v1, dstDevice, dstDevice)
    ctf_integer(unsigned int, dstPitch, dstPitch)
    ctf_integer(unsigned char, uc, uc)
    ctf_integer(unsigned int, Width, Width)
    ctf_integer(unsigned int, Height, Height)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD2D8_exit,
  TP_ARGS(
    CUdeviceptr_v1, dstDevice,
    unsigned int, dstPitch,
    unsigned char, uc,
    unsigned int, Width,
    unsigned int, Height,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD2D16_entry,
  TP_ARGS(
    CUdeviceptr_v1, dstDevice,
    unsigned int, dstPitch,
    unsigned short int, us,
    unsigned int, Width,
    unsigned int, Height
  ),
  TP_FIELDS(
    ctf_integer(CUdeviceptr_v1, dstDevice, dstDevice)
    ctf_integer(unsigned int, dstPitch, dstPitch)
    ctf_integer(unsigned short int, us, us)
    ctf_integer(unsigned int, Width, Width)
    ctf_integer(unsigned int, Height, Height)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD2D16_exit,
  TP_ARGS(
    CUdeviceptr_v1, dstDevice,
    unsigned int, dstPitch,
    unsigned short int, us,
    unsigned int, Width,
    unsigned int, Height,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD2D32_entry,
  TP_ARGS(
    CUdeviceptr_v1, dstDevice,
    unsigned int, dstPitch,
    unsigned int, ui,
    unsigned int, Width,
    unsigned int, Height
  ),
  TP_FIELDS(
    ctf_integer(CUdeviceptr_v1, dstDevice, dstDevice)
    ctf_integer(unsigned int, dstPitch, dstPitch)
    ctf_integer(unsigned int, ui, ui)
    ctf_integer(unsigned int, Width, Width)
    ctf_integer(unsigned int, Height, Height)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD2D32_exit,
  TP_ARGS(
    CUdeviceptr_v1, dstDevice,
    unsigned int, dstPitch,
    unsigned int, ui,
    unsigned int, Width,
    unsigned int, Height,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuArrayCreate_entry,
  TP_ARGS(
    CUarray *, pHandle,
    const CUDA_ARRAY_DESCRIPTOR_v1 *, pAllocateArray
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pHandle, (uintptr_t)(pHandle))
    ctf_integer_hex(uintptr_t, pAllocateArray, (uintptr_t)(pAllocateArray))
    ctf_sequence_text(uint8_t, pAllocateArray_val, pAllocateArray, size_t, (pAllocateArray ? sizeof(CUDA_ARRAY_DESCRIPTOR_v1) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuArrayCreate_exit,
  TP_ARGS(
    CUarray *, pHandle,
    const CUDA_ARRAY_DESCRIPTOR_v1 *, pAllocateArray,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pHandle_val, (uintptr_t)((pHandle ? *pHandle : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuArrayGetDescriptor_entry,
  TP_ARGS(
    CUDA_ARRAY_DESCRIPTOR_v1 *, pArrayDescriptor,
    CUarray, hArray
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pArrayDescriptor, (uintptr_t)(pArrayDescriptor))
    ctf_integer_hex(uintptr_t, hArray, (uintptr_t)(hArray))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuArrayGetDescriptor_exit,
  TP_ARGS(
    CUDA_ARRAY_DESCRIPTOR_v1 *, pArrayDescriptor,
    CUarray, hArray,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, pArrayDescriptor_val, pArrayDescriptor, size_t, (pArrayDescriptor ? sizeof(CUDA_ARRAY_DESCRIPTOR_v1) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuArray3DCreate_entry,
  TP_ARGS(
    CUarray *, pHandle,
    const CUDA_ARRAY3D_DESCRIPTOR_v1 *, pAllocateArray
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pHandle, (uintptr_t)(pHandle))
    ctf_integer_hex(uintptr_t, pAllocateArray, (uintptr_t)(pAllocateArray))
    ctf_sequence_text(uint8_t, pAllocateArray_val, pAllocateArray, size_t, (pAllocateArray ? sizeof(CUDA_ARRAY3D_DESCRIPTOR_v1) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuArray3DCreate_exit,
  TP_ARGS(
    CUarray *, pHandle,
    const CUDA_ARRAY3D_DESCRIPTOR_v1 *, pAllocateArray,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pHandle_val, (uintptr_t)((pHandle ? *pHandle : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuArray3DGetDescriptor_entry,
  TP_ARGS(
    CUDA_ARRAY3D_DESCRIPTOR_v1 *, pArrayDescriptor,
    CUarray, hArray
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pArrayDescriptor, (uintptr_t)(pArrayDescriptor))
    ctf_integer_hex(uintptr_t, hArray, (uintptr_t)(hArray))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuArray3DGetDescriptor_exit,
  TP_ARGS(
    CUDA_ARRAY3D_DESCRIPTOR_v1 *, pArrayDescriptor,
    CUarray, hArray,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, pArrayDescriptor_val, pArrayDescriptor, size_t, (pArrayDescriptor ? sizeof(CUDA_ARRAY3D_DESCRIPTOR_v1) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefSetAddress_entry,
  TP_ARGS(
    unsigned int *, ByteOffset,
    CUtexref, hTexRef,
    CUdeviceptr_v1, dptr,
    unsigned int, bytes
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ByteOffset, (uintptr_t)(ByteOffset))
    ctf_integer_hex(uintptr_t, hTexRef, (uintptr_t)(hTexRef))
    ctf_integer(CUdeviceptr_v1, dptr, dptr)
    ctf_integer(unsigned int, bytes, bytes)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefSetAddress_exit,
  TP_ARGS(
    unsigned int *, ByteOffset,
    CUtexref, hTexRef,
    CUdeviceptr_v1, dptr,
    unsigned int, bytes,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(unsigned int, ByteOffset_val, (ByteOffset ? *ByteOffset : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefSetAddress2D_entry,
  TP_ARGS(
    CUtexref, hTexRef,
    const CUDA_ARRAY_DESCRIPTOR_v1 *, desc,
    CUdeviceptr_v1, dptr,
    unsigned int, Pitch
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hTexRef, (uintptr_t)(hTexRef))
    ctf_integer_hex(uintptr_t, desc, (uintptr_t)(desc))
    ctf_integer(CUdeviceptr_v1, dptr, dptr)
    ctf_integer(unsigned int, Pitch, Pitch)
    ctf_sequence_text(uint8_t, desc_val, desc, size_t, (desc ? sizeof(CUDA_ARRAY_DESCRIPTOR_v1) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefSetAddress2D_exit,
  TP_ARGS(
    CUtexref, hTexRef,
    const CUDA_ARRAY_DESCRIPTOR_v1 *, desc,
    CUdeviceptr_v1, dptr,
    unsigned int, Pitch,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefGetAddress_entry,
  TP_ARGS(
    CUdeviceptr_v1 *, pdptr,
    CUtexref, hTexRef
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pdptr, (uintptr_t)(pdptr))
    ctf_integer_hex(uintptr_t, hTexRef, (uintptr_t)(hTexRef))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuTexRefGetAddress_exit,
  TP_ARGS(
    CUdeviceptr_v1 *, pdptr,
    CUtexref, hTexRef,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(CUdeviceptr_v1, pdptr_val, (pdptr ? *pdptr : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphicsResourceGetMappedPointer_entry,
  TP_ARGS(
    CUdeviceptr_v1 *, pDevPtr,
    unsigned int *, pSize,
    CUgraphicsResource, resource
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pDevPtr, (uintptr_t)(pDevPtr))
    ctf_integer_hex(uintptr_t, pSize, (uintptr_t)(pSize))
    ctf_integer_hex(uintptr_t, resource, (uintptr_t)(resource))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphicsResourceGetMappedPointer_exit,
  TP_ARGS(
    CUdeviceptr_v1 *, pDevPtr,
    unsigned int *, pSize,
    CUgraphicsResource, resource,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(CUdeviceptr_v1, pDevPtr_val, (pDevPtr ? *pDevPtr : 0))
    ctf_integer(unsigned int, pSize_val, (pSize ? *pSize : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxDestroy_entry,
  TP_ARGS(
    CUcontext, ctx
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ctx, (uintptr_t)(ctx))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxDestroy_exit,
  TP_ARGS(
    CUcontext, ctx,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxPopCurrent_entry,
  TP_ARGS(
    CUcontext *, pctx
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pctx, (uintptr_t)(pctx))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxPopCurrent_exit,
  TP_ARGS(
    CUcontext *, pctx,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pctx_val, (uintptr_t)((pctx ? *pctx : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxPushCurrent_entry,
  TP_ARGS(
    CUcontext, ctx
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ctx, (uintptr_t)(ctx))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCtxPushCurrent_exit,
  TP_ARGS(
    CUcontext, ctx,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamDestroy_entry,
  TP_ARGS(
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamDestroy_exit,
  TP_ARGS(
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuEventDestroy_entry,
  TP_ARGS(
    CUevent, hEvent
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hEvent, (uintptr_t)(hEvent))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuEventDestroy_exit,
  TP_ARGS(
    CUevent, hEvent,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuEventElapsedTime_entry,
  TP_ARGS(
    float *, pMilliseconds,
    CUevent, hStart,
    CUevent, hEnd
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pMilliseconds, (uintptr_t)(pMilliseconds))
    ctf_integer_hex(uintptr_t, hStart, (uintptr_t)(hStart))
    ctf_integer_hex(uintptr_t, hEnd, (uintptr_t)(hEnd))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuEventElapsedTime_exit,
  TP_ARGS(
    float *, pMilliseconds,
    CUevent, hStart,
    CUevent, hEnd,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_float(float, pMilliseconds_val, (pMilliseconds ? *pMilliseconds : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDevicePrimaryCtxRelease_entry,
  TP_ARGS(
    CUdevice, dev
  ),
  TP_FIELDS(
    ctf_integer(CUdevice, dev, dev)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDevicePrimaryCtxRelease_exit,
  TP_ARGS(
    CUdevice, dev,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDevicePrimaryCtxReset_entry,
  TP_ARGS(
    CUdevice, dev
  ),
  TP_FIELDS(
    ctf_integer(CUdevice, dev, dev)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDevicePrimaryCtxReset_exit,
  TP_ARGS(
    CUdevice, dev,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDevicePrimaryCtxSetFlags_entry,
  TP_ARGS(
    CUdevice, dev,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer(CUdevice, dev, dev)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDevicePrimaryCtxSetFlags_exit,
  TP_ARGS(
    CUdevice, dev,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetUuid_entry,
  TP_ARGS(
    CUuuid *, uuid,
    CUdevice, dev
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, uuid, (uintptr_t)(uuid))
    ctf_integer(CUdevice, dev, dev)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuDeviceGetUuid_exit,
  TP_ARGS(
    CUuuid *, uuid,
    CUdevice, dev,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, uuid_val, uuid, size_t, (uuid ? sizeof(CUuuid) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyHtoD_v2_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    const void *, srcHost,
    size_t, ByteCount
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer_hex(uintptr_t, srcHost, (uintptr_t)(srcHost))
    ctf_integer(size_t, ByteCount, ByteCount)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyHtoD_v2_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    const void *, srcHost,
    size_t, ByteCount,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyDtoH_v2_entry,
  TP_ARGS(
    void *, dstHost,
    CUdeviceptr, srcDevice,
    size_t, ByteCount
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dstHost, (uintptr_t)(dstHost))
    ctf_integer_hex(CUdeviceptr, srcDevice, srcDevice)
    ctf_integer(size_t, ByteCount, ByteCount)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyDtoH_v2_exit,
  TP_ARGS(
    void *, dstHost,
    CUdeviceptr, srcDevice,
    size_t, ByteCount,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyDtoD_v2_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    CUdeviceptr, srcDevice,
    size_t, ByteCount
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer_hex(CUdeviceptr, srcDevice, srcDevice)
    ctf_integer(size_t, ByteCount, ByteCount)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyDtoD_v2_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    CUdeviceptr, srcDevice,
    size_t, ByteCount,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyDtoA_v2_entry,
  TP_ARGS(
    CUarray, dstArray,
    size_t, dstOffset,
    CUdeviceptr, srcDevice,
    size_t, ByteCount
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dstArray, (uintptr_t)(dstArray))
    ctf_integer(size_t, dstOffset, dstOffset)
    ctf_integer_hex(CUdeviceptr, srcDevice, srcDevice)
    ctf_integer(size_t, ByteCount, ByteCount)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyDtoA_v2_exit,
  TP_ARGS(
    CUarray, dstArray,
    size_t, dstOffset,
    CUdeviceptr, srcDevice,
    size_t, ByteCount,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyAtoD_v2_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    CUarray, srcArray,
    size_t, srcOffset,
    size_t, ByteCount
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer_hex(uintptr_t, srcArray, (uintptr_t)(srcArray))
    ctf_integer(size_t, srcOffset, srcOffset)
    ctf_integer(size_t, ByteCount, ByteCount)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyAtoD_v2_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    CUarray, srcArray,
    size_t, srcOffset,
    size_t, ByteCount,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyHtoA_v2_entry,
  TP_ARGS(
    CUarray, dstArray,
    size_t, dstOffset,
    const void *, srcHost,
    size_t, ByteCount
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dstArray, (uintptr_t)(dstArray))
    ctf_integer(size_t, dstOffset, dstOffset)
    ctf_integer_hex(uintptr_t, srcHost, (uintptr_t)(srcHost))
    ctf_integer(size_t, ByteCount, ByteCount)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyHtoA_v2_exit,
  TP_ARGS(
    CUarray, dstArray,
    size_t, dstOffset,
    const void *, srcHost,
    size_t, ByteCount,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyAtoH_v2_entry,
  TP_ARGS(
    void *, dstHost,
    CUarray, srcArray,
    size_t, srcOffset,
    size_t, ByteCount
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dstHost, (uintptr_t)(dstHost))
    ctf_integer_hex(uintptr_t, srcArray, (uintptr_t)(srcArray))
    ctf_integer(size_t, srcOffset, srcOffset)
    ctf_integer(size_t, ByteCount, ByteCount)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyAtoH_v2_exit,
  TP_ARGS(
    void *, dstHost,
    CUarray, srcArray,
    size_t, srcOffset,
    size_t, ByteCount,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyAtoA_v2_entry,
  TP_ARGS(
    CUarray, dstArray,
    size_t, dstOffset,
    CUarray, srcArray,
    size_t, srcOffset,
    size_t, ByteCount
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dstArray, (uintptr_t)(dstArray))
    ctf_integer(size_t, dstOffset, dstOffset)
    ctf_integer_hex(uintptr_t, srcArray, (uintptr_t)(srcArray))
    ctf_integer(size_t, srcOffset, srcOffset)
    ctf_integer(size_t, ByteCount, ByteCount)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyAtoA_v2_exit,
  TP_ARGS(
    CUarray, dstArray,
    size_t, dstOffset,
    CUarray, srcArray,
    size_t, srcOffset,
    size_t, ByteCount,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyHtoAAsync_v2_entry,
  TP_ARGS(
    CUarray, dstArray,
    size_t, dstOffset,
    const void *, srcHost,
    size_t, ByteCount,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dstArray, (uintptr_t)(dstArray))
    ctf_integer(size_t, dstOffset, dstOffset)
    ctf_integer_hex(uintptr_t, srcHost, (uintptr_t)(srcHost))
    ctf_integer(size_t, ByteCount, ByteCount)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyHtoAAsync_v2_exit,
  TP_ARGS(
    CUarray, dstArray,
    size_t, dstOffset,
    const void *, srcHost,
    size_t, ByteCount,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyAtoHAsync_v2_entry,
  TP_ARGS(
    void *, dstHost,
    CUarray, srcArray,
    size_t, srcOffset,
    size_t, ByteCount,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dstHost, (uintptr_t)(dstHost))
    ctf_integer_hex(uintptr_t, srcArray, (uintptr_t)(srcArray))
    ctf_integer(size_t, srcOffset, srcOffset)
    ctf_integer(size_t, ByteCount, ByteCount)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyAtoHAsync_v2_exit,
  TP_ARGS(
    void *, dstHost,
    CUarray, srcArray,
    size_t, srcOffset,
    size_t, ByteCount,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy2D_v2_entry,
  TP_ARGS(
    const CUDA_MEMCPY2D *, pCopy
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pCopy, (uintptr_t)(pCopy))
    ctf_sequence_text(uint8_t, pCopy_val, pCopy, size_t, (pCopy ? sizeof(CUDA_MEMCPY2D) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy2D_v2_exit,
  TP_ARGS(
    const CUDA_MEMCPY2D *, pCopy,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy2DUnaligned_v2_entry,
  TP_ARGS(
    const CUDA_MEMCPY2D *, pCopy
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pCopy, (uintptr_t)(pCopy))
    ctf_sequence_text(uint8_t, pCopy_val, pCopy, size_t, (pCopy ? sizeof(CUDA_MEMCPY2D) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy2DUnaligned_v2_exit,
  TP_ARGS(
    const CUDA_MEMCPY2D *, pCopy,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy3D_v2_entry,
  TP_ARGS(
    const CUDA_MEMCPY3D *, pCopy
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pCopy, (uintptr_t)(pCopy))
    ctf_sequence_text(uint8_t, pCopy_val, pCopy, size_t, (pCopy ? sizeof(CUDA_MEMCPY3D) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy3D_v2_exit,
  TP_ARGS(
    const CUDA_MEMCPY3D *, pCopy,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyHtoDAsync_v2_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    const void *, srcHost,
    size_t, ByteCount,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer_hex(uintptr_t, srcHost, (uintptr_t)(srcHost))
    ctf_integer(size_t, ByteCount, ByteCount)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyHtoDAsync_v2_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    const void *, srcHost,
    size_t, ByteCount,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyDtoHAsync_v2_entry,
  TP_ARGS(
    void *, dstHost,
    CUdeviceptr, srcDevice,
    size_t, ByteCount,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dstHost, (uintptr_t)(dstHost))
    ctf_integer_hex(CUdeviceptr, srcDevice, srcDevice)
    ctf_integer(size_t, ByteCount, ByteCount)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyDtoHAsync_v2_exit,
  TP_ARGS(
    void *, dstHost,
    CUdeviceptr, srcDevice,
    size_t, ByteCount,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyDtoDAsync_v2_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    CUdeviceptr, srcDevice,
    size_t, ByteCount,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer_hex(CUdeviceptr, srcDevice, srcDevice)
    ctf_integer(size_t, ByteCount, ByteCount)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyDtoDAsync_v2_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    CUdeviceptr, srcDevice,
    size_t, ByteCount,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy2DAsync_v2_entry,
  TP_ARGS(
    const CUDA_MEMCPY2D *, pCopy,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pCopy, (uintptr_t)(pCopy))
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_sequence_text(uint8_t, pCopy_val, pCopy, size_t, (pCopy ? sizeof(CUDA_MEMCPY2D) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy2DAsync_v2_exit,
  TP_ARGS(
    const CUDA_MEMCPY2D *, pCopy,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy3DAsync_v2_entry,
  TP_ARGS(
    const CUDA_MEMCPY3D *, pCopy,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pCopy, (uintptr_t)(pCopy))
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_sequence_text(uint8_t, pCopy_val, pCopy, size_t, (pCopy ? sizeof(CUDA_MEMCPY3D) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy3DAsync_v2_exit,
  TP_ARGS(
    const CUDA_MEMCPY3D *, pCopy,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD8_v2_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    unsigned char, uc,
    size_t, N
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer(unsigned char, uc, uc)
    ctf_integer(size_t, N, N)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD8_v2_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    unsigned char, uc,
    size_t, N,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD16_v2_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    unsigned short int, us,
    size_t, N
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer(unsigned short int, us, us)
    ctf_integer(size_t, N, N)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD16_v2_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    unsigned short int, us,
    size_t, N,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD32_v2_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    unsigned int, ui,
    size_t, N
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer(unsigned int, ui, ui)
    ctf_integer(size_t, N, N)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD32_v2_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    unsigned int, ui,
    size_t, N,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD2D8_v2_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    size_t, dstPitch,
    unsigned char, uc,
    size_t, Width,
    size_t, Height
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer(size_t, dstPitch, dstPitch)
    ctf_integer(unsigned char, uc, uc)
    ctf_integer(size_t, Width, Width)
    ctf_integer(size_t, Height, Height)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD2D8_v2_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    size_t, dstPitch,
    unsigned char, uc,
    size_t, Width,
    size_t, Height,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD2D16_v2_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    size_t, dstPitch,
    unsigned short int, us,
    size_t, Width,
    size_t, Height
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer(size_t, dstPitch, dstPitch)
    ctf_integer(unsigned short int, us, us)
    ctf_integer(size_t, Width, Width)
    ctf_integer(size_t, Height, Height)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD2D16_v2_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    size_t, dstPitch,
    unsigned short int, us,
    size_t, Width,
    size_t, Height,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD2D32_v2_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    size_t, dstPitch,
    unsigned int, ui,
    size_t, Width,
    size_t, Height
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer(size_t, dstPitch, dstPitch)
    ctf_integer(unsigned int, ui, ui)
    ctf_integer(size_t, Width, Width)
    ctf_integer(size_t, Height, Height)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD2D32_v2_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    size_t, dstPitch,
    unsigned int, ui,
    size_t, Width,
    size_t, Height,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy_entry,
  TP_ARGS(
    CUdeviceptr, dst,
    CUdeviceptr, src,
    size_t, ByteCount
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dst, dst)
    ctf_integer_hex(CUdeviceptr, src, src)
    ctf_integer(size_t, ByteCount, ByteCount)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy_exit,
  TP_ARGS(
    CUdeviceptr, dst,
    CUdeviceptr, src,
    size_t, ByteCount,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyAsync_entry,
  TP_ARGS(
    CUdeviceptr, dst,
    CUdeviceptr, src,
    size_t, ByteCount,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dst, dst)
    ctf_integer_hex(CUdeviceptr, src, src)
    ctf_integer(size_t, ByteCount, ByteCount)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyAsync_exit,
  TP_ARGS(
    CUdeviceptr, dst,
    CUdeviceptr, src,
    size_t, ByteCount,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyPeer_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    CUcontext, dstContext,
    CUdeviceptr, srcDevice,
    CUcontext, srcContext,
    size_t, ByteCount
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer_hex(uintptr_t, dstContext, (uintptr_t)(dstContext))
    ctf_integer_hex(CUdeviceptr, srcDevice, srcDevice)
    ctf_integer_hex(uintptr_t, srcContext, (uintptr_t)(srcContext))
    ctf_integer(size_t, ByteCount, ByteCount)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyPeer_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    CUcontext, dstContext,
    CUdeviceptr, srcDevice,
    CUcontext, srcContext,
    size_t, ByteCount,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyPeerAsync_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    CUcontext, dstContext,
    CUdeviceptr, srcDevice,
    CUcontext, srcContext,
    size_t, ByteCount,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer_hex(uintptr_t, dstContext, (uintptr_t)(dstContext))
    ctf_integer_hex(CUdeviceptr, srcDevice, srcDevice)
    ctf_integer_hex(uintptr_t, srcContext, (uintptr_t)(srcContext))
    ctf_integer(size_t, ByteCount, ByteCount)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyPeerAsync_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    CUcontext, dstContext,
    CUdeviceptr, srcDevice,
    CUcontext, srcContext,
    size_t, ByteCount,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy3DPeer_entry,
  TP_ARGS(
    const CUDA_MEMCPY3D_PEER *, pCopy
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pCopy, (uintptr_t)(pCopy))
    ctf_sequence_text(uint8_t, pCopy_val, pCopy, size_t, (pCopy ? sizeof(CUDA_MEMCPY3D_PEER) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy3DPeer_exit,
  TP_ARGS(
    const CUDA_MEMCPY3D_PEER *, pCopy,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy3DPeerAsync_entry,
  TP_ARGS(
    const CUDA_MEMCPY3D_PEER *, pCopy,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pCopy, (uintptr_t)(pCopy))
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_sequence_text(uint8_t, pCopy_val, pCopy, size_t, (pCopy ? sizeof(CUDA_MEMCPY3D_PEER) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy3DPeerAsync_exit,
  TP_ARGS(
    const CUDA_MEMCPY3D_PEER *, pCopy,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyBatchAsync_entry,
  TP_ARGS(
    CUdeviceptr *, dsts,
    CUdeviceptr *, srcs,
    size_t *, sizes,
    size_t, count,
    CUmemcpyAttributes *, attrs,
    size_t *, attrsIdxs,
    size_t, numAttrs,
    size_t *, failIdx,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dsts, (uintptr_t)(dsts))
    ctf_integer_hex(uintptr_t, srcs, (uintptr_t)(srcs))
    ctf_integer_hex(uintptr_t, sizes, (uintptr_t)(sizes))
    ctf_integer(size_t, count, count)
    ctf_integer_hex(uintptr_t, attrs, (uintptr_t)(attrs))
    ctf_integer_hex(uintptr_t, attrsIdxs, (uintptr_t)(attrsIdxs))
    ctf_integer(size_t, numAttrs, numAttrs)
    ctf_integer_hex(uintptr_t, failIdx, (uintptr_t)(failIdx))
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_sequence_hex(CUdeviceptr, dsts_vals, dsts, size_t, (dsts ? count : 0))
    ctf_sequence_hex(CUdeviceptr, srcs_vals, srcs, size_t, (srcs ? count : 0))
    ctf_sequence(size_t, sizes_vals, sizes, size_t, (sizes ? count : 0))
    ctf_sequence_text(uint8_t, attrs_vals, attrs, size_t, ((attrs ? numAttrs : 0)) * sizeof(CUmemcpyAttributes))
    ctf_sequence(size_t, attrsIdxs_vals, attrsIdxs, size_t, (attrsIdxs ? numAttrs : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyBatchAsync_exit,
  TP_ARGS(
    CUdeviceptr *, dsts,
    CUdeviceptr *, srcs,
    size_t *, sizes,
    size_t, count,
    CUmemcpyAttributes *, attrs,
    size_t *, attrsIdxs,
    size_t, numAttrs,
    size_t *, failIdx,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(size_t, failIdx_val, (failIdx ? *failIdx : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy3DBatchAsync_entry,
  TP_ARGS(
    size_t, numOps,
    CUDA_MEMCPY3D_BATCH_OP *, opList,
    size_t *, failIdx,
    unsigned long long int, flags,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer(size_t, numOps, numOps)
    ctf_integer_hex(uintptr_t, opList, (uintptr_t)(opList))
    ctf_integer_hex(uintptr_t, failIdx, (uintptr_t)(failIdx))
    ctf_integer(unsigned long long int, flags, flags)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_sequence_text(uint8_t, opList_vals, opList, size_t, ((opList ? numOps : 0)) * sizeof(CUDA_MEMCPY3D_BATCH_OP))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy3DBatchAsync_exit,
  TP_ARGS(
    size_t, numOps,
    CUDA_MEMCPY3D_BATCH_OP *, opList,
    size_t *, failIdx,
    unsigned long long int, flags,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(size_t, failIdx_val, (failIdx ? *failIdx : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyBatchAsync_ptsz_entry,
  TP_ARGS(
    CUdeviceptr *, dsts,
    CUdeviceptr *, srcs,
    size_t *, sizes,
    size_t, count,
    CUmemcpyAttributes *, attrs,
    size_t *, attrsIdxs,
    size_t, numAttrs,
    size_t *, failIdx,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dsts, (uintptr_t)(dsts))
    ctf_integer_hex(uintptr_t, srcs, (uintptr_t)(srcs))
    ctf_integer_hex(uintptr_t, sizes, (uintptr_t)(sizes))
    ctf_integer(size_t, count, count)
    ctf_integer_hex(uintptr_t, attrs, (uintptr_t)(attrs))
    ctf_integer_hex(uintptr_t, attrsIdxs, (uintptr_t)(attrsIdxs))
    ctf_integer(size_t, numAttrs, numAttrs)
    ctf_integer_hex(uintptr_t, failIdx, (uintptr_t)(failIdx))
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_sequence_hex(CUdeviceptr, dsts_vals, dsts, size_t, (dsts ? count : 0))
    ctf_sequence_hex(CUdeviceptr, srcs_vals, srcs, size_t, (srcs ? count : 0))
    ctf_sequence(size_t, sizes_vals, sizes, size_t, (sizes ? count : 0))
    ctf_sequence_text(uint8_t, attrs_vals, attrs, size_t, ((attrs ? numAttrs : 0)) * sizeof(CUmemcpyAttributes))
    ctf_sequence(size_t, attrsIdxs_vals, attrsIdxs, size_t, (attrsIdxs ? numAttrs : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyBatchAsync_ptsz_exit,
  TP_ARGS(
    CUdeviceptr *, dsts,
    CUdeviceptr *, srcs,
    size_t *, sizes,
    size_t, count,
    CUmemcpyAttributes *, attrs,
    size_t *, attrsIdxs,
    size_t, numAttrs,
    size_t *, failIdx,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(size_t, failIdx_val, (failIdx ? *failIdx : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy3DBatchAsync_ptsz_entry,
  TP_ARGS(
    size_t, numOps,
    CUDA_MEMCPY3D_BATCH_OP *, opList,
    size_t *, failIdx,
    unsigned long long int, flags,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer(size_t, numOps, numOps)
    ctf_integer_hex(uintptr_t, opList, (uintptr_t)(opList))
    ctf_integer_hex(uintptr_t, failIdx, (uintptr_t)(failIdx))
    ctf_integer(unsigned long long int, flags, flags)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_sequence_text(uint8_t, opList_vals, opList, size_t, ((opList ? numOps : 0)) * sizeof(CUDA_MEMCPY3D_BATCH_OP))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy3DBatchAsync_ptsz_exit,
  TP_ARGS(
    size_t, numOps,
    CUDA_MEMCPY3D_BATCH_OP *, opList,
    size_t *, failIdx,
    unsigned long long int, flags,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(size_t, failIdx_val, (failIdx ? *failIdx : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyBatchAsync_v2_entry,
  TP_ARGS(
    CUdeviceptr *, dsts,
    CUdeviceptr *, srcs,
    size_t *, sizes,
    size_t, count,
    CUmemcpyAttributes *, attrs,
    size_t *, attrsIdxs,
    size_t, numAttrs,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dsts, (uintptr_t)(dsts))
    ctf_integer_hex(uintptr_t, srcs, (uintptr_t)(srcs))
    ctf_integer_hex(uintptr_t, sizes, (uintptr_t)(sizes))
    ctf_integer(size_t, count, count)
    ctf_integer_hex(uintptr_t, attrs, (uintptr_t)(attrs))
    ctf_integer_hex(uintptr_t, attrsIdxs, (uintptr_t)(attrsIdxs))
    ctf_integer(size_t, numAttrs, numAttrs)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_sequence_hex(CUdeviceptr, dsts_vals, dsts, size_t, (dsts ? count : 0))
    ctf_sequence_hex(CUdeviceptr, srcs_vals, srcs, size_t, (srcs ? count : 0))
    ctf_sequence(size_t, sizes_vals, sizes, size_t, (sizes ? count : 0))
    ctf_sequence_text(uint8_t, attrs_vals, attrs, size_t, ((attrs ? numAttrs : 0)) * sizeof(CUmemcpyAttributes))
    ctf_sequence(size_t, attrsIdxs_vals, attrsIdxs, size_t, (attrsIdxs ? numAttrs : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpyBatchAsync_v2_exit,
  TP_ARGS(
    CUdeviceptr *, dsts,
    CUdeviceptr *, srcs,
    size_t *, sizes,
    size_t, count,
    CUmemcpyAttributes *, attrs,
    size_t *, attrsIdxs,
    size_t, numAttrs,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy3DBatchAsync_v2_entry,
  TP_ARGS(
    size_t, numOps,
    CUDA_MEMCPY3D_BATCH_OP *, opList,
    unsigned long long int, flags,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer(size_t, numOps, numOps)
    ctf_integer_hex(uintptr_t, opList, (uintptr_t)(opList))
    ctf_integer(unsigned long long int, flags, flags)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_sequence_text(uint8_t, opList_vals, opList, size_t, ((opList ? numOps : 0)) * sizeof(CUDA_MEMCPY3D_BATCH_OP))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemcpy3DBatchAsync_v2_exit,
  TP_ARGS(
    size_t, numOps,
    CUDA_MEMCPY3D_BATCH_OP *, opList,
    unsigned long long int, flags,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD8Async_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    unsigned char, uc,
    size_t, N,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer(unsigned char, uc, uc)
    ctf_integer(size_t, N, N)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD8Async_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    unsigned char, uc,
    size_t, N,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD16Async_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    unsigned short int, us,
    size_t, N,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer(unsigned short int, us, us)
    ctf_integer(size_t, N, N)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD16Async_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    unsigned short int, us,
    size_t, N,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD32Async_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    unsigned int, ui,
    size_t, N,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer(unsigned int, ui, ui)
    ctf_integer(size_t, N, N)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD32Async_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    unsigned int, ui,
    size_t, N,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD2D8Async_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    size_t, dstPitch,
    unsigned char, uc,
    size_t, Width,
    size_t, Height,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer(size_t, dstPitch, dstPitch)
    ctf_integer(unsigned char, uc, uc)
    ctf_integer(size_t, Width, Width)
    ctf_integer(size_t, Height, Height)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD2D8Async_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    size_t, dstPitch,
    unsigned char, uc,
    size_t, Width,
    size_t, Height,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD2D16Async_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    size_t, dstPitch,
    unsigned short int, us,
    size_t, Width,
    size_t, Height,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer(size_t, dstPitch, dstPitch)
    ctf_integer(unsigned short int, us, us)
    ctf_integer(size_t, Width, Width)
    ctf_integer(size_t, Height, Height)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD2D16Async_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    size_t, dstPitch,
    unsigned short int, us,
    size_t, Width,
    size_t, Height,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD2D32Async_entry,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    size_t, dstPitch,
    unsigned int, ui,
    size_t, Width,
    size_t, Height,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dstDevice, dstDevice)
    ctf_integer(size_t, dstPitch, dstPitch)
    ctf_integer(unsigned int, ui, ui)
    ctf_integer(size_t, Width, Width)
    ctf_integer(size_t, Height, Height)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemsetD2D32Async_exit,
  TP_ARGS(
    CUdeviceptr, dstDevice,
    size_t, dstPitch,
    unsigned int, ui,
    size_t, Width,
    size_t, Height,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetPriority_entry,
  TP_ARGS(
    CUstream, hStream,
    int *, priority
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, priority, (uintptr_t)(priority))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetPriority_exit,
  TP_ARGS(
    CUstream, hStream,
    int *, priority,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int, priority_val, (priority ? *priority : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetId_entry,
  TP_ARGS(
    CUstream, hStream,
    unsigned long long int *, streamId
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, streamId, (uintptr_t)(streamId))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetId_exit,
  TP_ARGS(
    CUstream, hStream,
    unsigned long long int *, streamId,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(unsigned long long int, streamId_val, (streamId ? *streamId : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetFlags_entry,
  TP_ARGS(
    CUstream, hStream,
    unsigned int *, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, flags, (uintptr_t)(flags))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetFlags_exit,
  TP_ARGS(
    CUstream, hStream,
    unsigned int *, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(unsigned int, flags_val, (flags ? *flags : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetDevice_entry,
  TP_ARGS(
    CUstream, hStream,
    CUdevice *, device
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, device, (uintptr_t)(device))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetDevice_exit,
  TP_ARGS(
    CUstream, hStream,
    CUdevice *, device,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(CUdevice, device_val, (device ? *device : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetCtx_entry,
  TP_ARGS(
    CUstream, hStream,
    CUcontext *, pctx
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, pctx, (uintptr_t)(pctx))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetCtx_exit,
  TP_ARGS(
    CUstream, hStream,
    CUcontext *, pctx,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pctx_val, (uintptr_t)((pctx ? *pctx : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetCtx_v2_entry,
  TP_ARGS(
    CUstream, hStream,
    CUcontext *, pCtx,
    CUgreenCtx *, pGreenCtx
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, pCtx, (uintptr_t)(pCtx))
    ctf_integer_hex(uintptr_t, pGreenCtx, (uintptr_t)(pGreenCtx))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetCtx_v2_exit,
  TP_ARGS(
    CUstream, hStream,
    CUcontext *, pCtx,
    CUgreenCtx *, pGreenCtx,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pCtx_val, (uintptr_t)((pCtx ? *pCtx : 0)))
    ctf_integer_hex(uintptr_t, pGreenCtx_val, (uintptr_t)((pGreenCtx ? *pGreenCtx : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamWaitEvent_entry,
  TP_ARGS(
    CUstream, hStream,
    CUevent, hEvent,
    unsigned int, Flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, hEvent, (uintptr_t)(hEvent))
    ctf_integer(unsigned int, Flags, Flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamWaitEvent_exit,
  TP_ARGS(
    CUstream, hStream,
    CUevent, hEvent,
    unsigned int, Flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamAddCallback_entry,
  TP_ARGS(
    CUstream, hStream,
    CUstreamCallback, callback,
    void *, userData,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, callback, (uintptr_t)(callback))
    ctf_integer_hex(uintptr_t, userData, (uintptr_t)(userData))
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamAddCallback_exit,
  TP_ARGS(
    CUstream, hStream,
    CUstreamCallback, callback,
    void *, userData,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamAttachMemAsync_entry,
  TP_ARGS(
    CUstream, hStream,
    CUdeviceptr, dptr,
    size_t, length,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(CUdeviceptr, dptr, dptr)
    ctf_integer(size_t, length, length)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamAttachMemAsync_exit,
  TP_ARGS(
    CUstream, hStream,
    CUdeviceptr, dptr,
    size_t, length,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamQuery_entry,
  TP_ARGS(
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamQuery_exit,
  TP_ARGS(
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamSynchronize_entry,
  TP_ARGS(
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamSynchronize_exit,
  TP_ARGS(
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuEventRecord_entry,
  TP_ARGS(
    CUevent, hEvent,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hEvent, (uintptr_t)(hEvent))
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuEventRecord_exit,
  TP_ARGS(
    CUevent, hEvent,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuEventRecordWithFlags_entry,
  TP_ARGS(
    CUevent, hEvent,
    CUstream, hStream,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hEvent, (uintptr_t)(hEvent))
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuEventRecordWithFlags_exit,
  TP_ARGS(
    CUevent, hEvent,
    CUstream, hStream,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLaunchKernel_entry,
  TP_ARGS(
    CUfunction, f,
    unsigned int, gridDimX,
    unsigned int, gridDimY,
    unsigned int, gridDimZ,
    unsigned int, blockDimX,
    unsigned int, blockDimY,
    unsigned int, blockDimZ,
    unsigned int, sharedMemBytes,
    CUstream, hStream,
    void **, kernelParams,
    void **, extra,
    size_t, _extra_size
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
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, kernelParams, (uintptr_t)(kernelParams))
    ctf_integer_hex(uintptr_t, extra, (uintptr_t)(extra))
    ctf_sequence_hex(uintptr_t, extra_vals, extra, size_t, (extra ? _extra_size : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLaunchKernel_exit,
  TP_ARGS(
    CUfunction, f,
    unsigned int, gridDimX,
    unsigned int, gridDimY,
    unsigned int, gridDimZ,
    unsigned int, blockDimX,
    unsigned int, blockDimY,
    unsigned int, blockDimZ,
    unsigned int, sharedMemBytes,
    CUstream, hStream,
    void **, kernelParams,
    void **, extra,
    CUresult, cuResult,
    size_t, _extra_size
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLaunchKernelEx_entry,
  TP_ARGS(
    const CUlaunchConfig *, config,
    CUfunction, f,
    void **, kernelParams,
    void **, extra,
    size_t, _extra_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, config, (uintptr_t)(config))
    ctf_integer_hex(uintptr_t, f, (uintptr_t)(f))
    ctf_integer_hex(uintptr_t, kernelParams, (uintptr_t)(kernelParams))
    ctf_integer_hex(uintptr_t, extra, (uintptr_t)(extra))
    ctf_sequence_text(uint8_t, config_val, config, size_t, (config ? sizeof(CUlaunchConfig) : 0))
    ctf_sequence_text(uint8_t, config__attrs_vals, (config ? config->attrs : 0), size_t, ((config && config->attrs ? config->numAttrs : 0)) * sizeof(CUlaunchAttribute))
    ctf_sequence_hex(uintptr_t, extra_vals, extra, size_t, (extra ? _extra_size : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLaunchKernelEx_exit,
  TP_ARGS(
    const CUlaunchConfig *, config,
    CUfunction, f,
    void **, kernelParams,
    void **, extra,
    CUresult, cuResult,
    size_t, _extra_size
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLaunchHostFunc_entry,
  TP_ARGS(
    CUstream, hStream,
    CUhostFn, fn,
    void *, userData
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, fn, (uintptr_t)(fn))
    ctf_integer_hex(uintptr_t, userData, (uintptr_t)(userData))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLaunchHostFunc_exit,
  TP_ARGS(
    CUstream, hStream,
    CUhostFn, fn,
    void *, userData,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphicsMapResources_entry,
  TP_ARGS(
    unsigned int, count,
    CUgraphicsResource *, resources,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer(unsigned int, count, count)
    ctf_integer_hex(uintptr_t, resources, (uintptr_t)(resources))
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_sequence_hex(uintptr_t, resources_vals, resources, unsigned int, (resources ? count : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphicsMapResources_exit,
  TP_ARGS(
    unsigned int, count,
    CUgraphicsResource *, resources,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphicsUnmapResources_entry,
  TP_ARGS(
    unsigned int, count,
    CUgraphicsResource *, resources,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer(unsigned int, count, count)
    ctf_integer_hex(uintptr_t, resources, (uintptr_t)(resources))
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_sequence_hex(uintptr_t, resources_vals, resources, unsigned int, (resources ? count : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphicsUnmapResources_exit,
  TP_ARGS(
    unsigned int, count,
    CUgraphicsResource *, resources,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamWriteValue32_entry,
  TP_ARGS(
    CUstream, stream,
    CUdeviceptr, addr,
    cuuint32_t, value,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(CUdeviceptr, addr, addr)
    ctf_integer(cuuint32_t, value, value)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamWriteValue32_exit,
  TP_ARGS(
    CUstream, stream,
    CUdeviceptr, addr,
    cuuint32_t, value,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamWaitValue32_entry,
  TP_ARGS(
    CUstream, stream,
    CUdeviceptr, addr,
    cuuint32_t, value,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(CUdeviceptr, addr, addr)
    ctf_integer(cuuint32_t, value, value)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamWaitValue32_exit,
  TP_ARGS(
    CUstream, stream,
    CUdeviceptr, addr,
    cuuint32_t, value,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamWriteValue64_entry,
  TP_ARGS(
    CUstream, stream,
    CUdeviceptr, addr,
    cuuint64_t, value,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(CUdeviceptr, addr, addr)
    ctf_integer(cuuint64_t, value, value)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamWriteValue64_exit,
  TP_ARGS(
    CUstream, stream,
    CUdeviceptr, addr,
    cuuint64_t, value,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamWaitValue64_entry,
  TP_ARGS(
    CUstream, stream,
    CUdeviceptr, addr,
    cuuint64_t, value,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(CUdeviceptr, addr, addr)
    ctf_integer(cuuint64_t, value, value)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamWaitValue64_exit,
  TP_ARGS(
    CUstream, stream,
    CUdeviceptr, addr,
    cuuint64_t, value,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamBatchMemOp_entry,
  TP_ARGS(
    CUstream, stream,
    unsigned int, count,
    CUstreamBatchMemOpParams *, paramArray,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer(unsigned int, count, count)
    ctf_integer_hex(uintptr_t, paramArray, (uintptr_t)(paramArray))
    ctf_integer(unsigned int, flags, flags)
    ctf_sequence_text(uint8_t, paramArray_vals, paramArray, size_t, ((paramArray ? count : 0)) * sizeof(CUstreamBatchMemOpParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamBatchMemOp_exit,
  TP_ARGS(
    CUstream, stream,
    unsigned int, count,
    CUstreamBatchMemOpParams *, paramArray,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamWriteValue32_ptsz_entry,
  TP_ARGS(
    CUstream, stream,
    CUdeviceptr, addr,
    cuuint32_t, value,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(CUdeviceptr, addr, addr)
    ctf_integer(cuuint32_t, value, value)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamWriteValue32_ptsz_exit,
  TP_ARGS(
    CUstream, stream,
    CUdeviceptr, addr,
    cuuint32_t, value,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamWaitValue32_ptsz_entry,
  TP_ARGS(
    CUstream, stream,
    CUdeviceptr, addr,
    cuuint32_t, value,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(CUdeviceptr, addr, addr)
    ctf_integer(cuuint32_t, value, value)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamWaitValue32_ptsz_exit,
  TP_ARGS(
    CUstream, stream,
    CUdeviceptr, addr,
    cuuint32_t, value,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamWriteValue64_ptsz_entry,
  TP_ARGS(
    CUstream, stream,
    CUdeviceptr, addr,
    cuuint64_t, value,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(CUdeviceptr, addr, addr)
    ctf_integer(cuuint64_t, value, value)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamWriteValue64_ptsz_exit,
  TP_ARGS(
    CUstream, stream,
    CUdeviceptr, addr,
    cuuint64_t, value,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamWaitValue64_ptsz_entry,
  TP_ARGS(
    CUstream, stream,
    CUdeviceptr, addr,
    cuuint64_t, value,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(CUdeviceptr, addr, addr)
    ctf_integer(cuuint64_t, value, value)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamWaitValue64_ptsz_exit,
  TP_ARGS(
    CUstream, stream,
    CUdeviceptr, addr,
    cuuint64_t, value,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamBatchMemOp_ptsz_entry,
  TP_ARGS(
    CUstream, stream,
    unsigned int, count,
    CUstreamBatchMemOpParams *, paramArray,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer(unsigned int, count, count)
    ctf_integer_hex(uintptr_t, paramArray, (uintptr_t)(paramArray))
    ctf_integer(unsigned int, flags, flags)
    ctf_sequence_text(uint8_t, paramArray_vals, paramArray, size_t, ((paramArray ? count : 0)) * sizeof(CUstreamBatchMemOpParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamBatchMemOp_ptsz_exit,
  TP_ARGS(
    CUstream, stream,
    unsigned int, count,
    CUstreamBatchMemOpParams *, paramArray,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamWriteValue32_v2_entry,
  TP_ARGS(
    CUstream, stream,
    CUdeviceptr, addr,
    cuuint32_t, value,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(CUdeviceptr, addr, addr)
    ctf_integer(cuuint32_t, value, value)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamWriteValue32_v2_exit,
  TP_ARGS(
    CUstream, stream,
    CUdeviceptr, addr,
    cuuint32_t, value,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamWaitValue32_v2_entry,
  TP_ARGS(
    CUstream, stream,
    CUdeviceptr, addr,
    cuuint32_t, value,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(CUdeviceptr, addr, addr)
    ctf_integer(cuuint32_t, value, value)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamWaitValue32_v2_exit,
  TP_ARGS(
    CUstream, stream,
    CUdeviceptr, addr,
    cuuint32_t, value,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamWriteValue64_v2_entry,
  TP_ARGS(
    CUstream, stream,
    CUdeviceptr, addr,
    cuuint64_t, value,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(CUdeviceptr, addr, addr)
    ctf_integer(cuuint64_t, value, value)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamWriteValue64_v2_exit,
  TP_ARGS(
    CUstream, stream,
    CUdeviceptr, addr,
    cuuint64_t, value,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamWaitValue64_v2_entry,
  TP_ARGS(
    CUstream, stream,
    CUdeviceptr, addr,
    cuuint64_t, value,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer_hex(CUdeviceptr, addr, addr)
    ctf_integer(cuuint64_t, value, value)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamWaitValue64_v2_exit,
  TP_ARGS(
    CUstream, stream,
    CUdeviceptr, addr,
    cuuint64_t, value,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamBatchMemOp_v2_entry,
  TP_ARGS(
    CUstream, stream,
    unsigned int, count,
    CUstreamBatchMemOpParams *, paramArray,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_integer(unsigned int, count, count)
    ctf_integer_hex(uintptr_t, paramArray, (uintptr_t)(paramArray))
    ctf_integer(unsigned int, flags, flags)
    ctf_sequence_text(uint8_t, paramArray_vals, paramArray, size_t, ((paramArray ? count : 0)) * sizeof(CUstreamBatchMemOpParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamBatchMemOp_v2_exit,
  TP_ARGS(
    CUstream, stream,
    unsigned int, count,
    CUstreamBatchMemOpParams *, paramArray,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemPrefetchAsync_entry,
  TP_ARGS(
    CUdeviceptr, devPtr,
    size_t, count,
    CUdevice, dstDevice,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, devPtr, devPtr)
    ctf_integer(size_t, count, count)
    ctf_integer(CUdevice, dstDevice, dstDevice)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemPrefetchAsync_exit,
  TP_ARGS(
    CUdeviceptr, devPtr,
    size_t, count,
    CUdevice, dstDevice,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemPrefetchAsync_ptsz_entry,
  TP_ARGS(
    CUdeviceptr, devPtr,
    size_t, count,
    CUdevice, dstDevice,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, devPtr, devPtr)
    ctf_integer(size_t, count, count)
    ctf_integer(CUdevice, dstDevice, dstDevice)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemPrefetchAsync_ptsz_exit,
  TP_ARGS(
    CUdeviceptr, devPtr,
    size_t, count,
    CUdevice, dstDevice,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemPrefetchAsync_v2_entry,
  TP_ARGS(
    CUdeviceptr, devPtr,
    size_t, count,
    CUmemLocation, location,
    unsigned int, flags,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, devPtr, devPtr)
    ctf_integer(size_t, count, count)
    ctf_array_text(uint8_t, location, &location, sizeof(CUmemLocation))
    ctf_integer(unsigned int, flags, flags)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemPrefetchAsync_v2_exit,
  TP_ARGS(
    CUdeviceptr, devPtr,
    size_t, count,
    CUmemLocation, location,
    unsigned int, flags,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemAdvise_entry,
  TP_ARGS(
    CUdeviceptr, devPtr,
    size_t, count,
    CUmem_advise, advice,
    CUdevice, device
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, devPtr, devPtr)
    ctf_integer(size_t, count, count)
    ctf_integer(int32_t, advice, advice)
    ctf_integer(CUdevice, device, device)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemAdvise_exit,
  TP_ARGS(
    CUdeviceptr, devPtr,
    size_t, count,
    CUmem_advise, advice,
    CUdevice, device,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemPrefetchBatchAsync_entry,
  TP_ARGS(
    CUdeviceptr *, dptrs,
    size_t *, sizes,
    size_t, count,
    CUmemLocation *, prefetchLocs,
    size_t *, prefetchLocIdxs,
    size_t, numPrefetchLocs,
    unsigned long long int, flags,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dptrs, (uintptr_t)(dptrs))
    ctf_integer_hex(uintptr_t, sizes, (uintptr_t)(sizes))
    ctf_integer(size_t, count, count)
    ctf_integer_hex(uintptr_t, prefetchLocs, (uintptr_t)(prefetchLocs))
    ctf_integer_hex(uintptr_t, prefetchLocIdxs, (uintptr_t)(prefetchLocIdxs))
    ctf_integer(size_t, numPrefetchLocs, numPrefetchLocs)
    ctf_integer(unsigned long long int, flags, flags)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_sequence_hex(CUdeviceptr, dptrs_vals, dptrs, size_t, (dptrs ? count : 0))
    ctf_sequence(size_t, sizes_vals, sizes, size_t, (sizes ? count : 0))
    ctf_sequence_text(uint8_t, prefetchLocs_vals, prefetchLocs, size_t, ((prefetchLocs ? numPrefetchLocs : 0)) * sizeof(CUmemLocation))
    ctf_sequence(size_t, prefetchLocIdxs_vals, prefetchLocIdxs, size_t, (prefetchLocIdxs ? numPrefetchLocs : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemPrefetchBatchAsync_exit,
  TP_ARGS(
    CUdeviceptr *, dptrs,
    size_t *, sizes,
    size_t, count,
    CUmemLocation *, prefetchLocs,
    size_t *, prefetchLocIdxs,
    size_t, numPrefetchLocs,
    unsigned long long int, flags,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemDiscardBatchAsync_entry,
  TP_ARGS(
    CUdeviceptr *, dptrs,
    size_t *, sizes,
    size_t, count,
    unsigned long long int, flags,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dptrs, (uintptr_t)(dptrs))
    ctf_integer_hex(uintptr_t, sizes, (uintptr_t)(sizes))
    ctf_integer(size_t, count, count)
    ctf_integer(unsigned long long int, flags, flags)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_sequence_hex(CUdeviceptr, dptrs_vals, dptrs, size_t, (dptrs ? count : 0))
    ctf_sequence(size_t, sizes_vals, sizes, size_t, (sizes ? count : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemDiscardBatchAsync_exit,
  TP_ARGS(
    CUdeviceptr *, dptrs,
    size_t *, sizes,
    size_t, count,
    unsigned long long int, flags,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemDiscardAndPrefetchBatchAsync_entry,
  TP_ARGS(
    CUdeviceptr *, dptrs,
    size_t *, sizes,
    size_t, count,
    CUmemLocation *, prefetchLocs,
    size_t *, prefetchLocIdxs,
    size_t, numPrefetchLocs,
    unsigned long long int, flags,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dptrs, (uintptr_t)(dptrs))
    ctf_integer_hex(uintptr_t, sizes, (uintptr_t)(sizes))
    ctf_integer(size_t, count, count)
    ctf_integer_hex(uintptr_t, prefetchLocs, (uintptr_t)(prefetchLocs))
    ctf_integer_hex(uintptr_t, prefetchLocIdxs, (uintptr_t)(prefetchLocIdxs))
    ctf_integer(size_t, numPrefetchLocs, numPrefetchLocs)
    ctf_integer(unsigned long long int, flags, flags)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_sequence_hex(CUdeviceptr, dptrs_vals, dptrs, size_t, (dptrs ? count : 0))
    ctf_sequence(size_t, sizes_vals, sizes, size_t, (sizes ? count : 0))
    ctf_sequence_text(uint8_t, prefetchLocs_vals, prefetchLocs, size_t, ((prefetchLocs ? numPrefetchLocs : 0)) * sizeof(CUmemLocation))
    ctf_sequence(size_t, prefetchLocIdxs_vals, prefetchLocIdxs, size_t, (prefetchLocIdxs ? numPrefetchLocs : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemDiscardAndPrefetchBatchAsync_exit,
  TP_ARGS(
    CUdeviceptr *, dptrs,
    size_t *, sizes,
    size_t, count,
    CUmemLocation *, prefetchLocs,
    size_t *, prefetchLocIdxs,
    size_t, numPrefetchLocs,
    unsigned long long int, flags,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLaunchCooperativeKernel_entry,
  TP_ARGS(
    CUfunction, f,
    unsigned int, gridDimX,
    unsigned int, gridDimY,
    unsigned int, gridDimZ,
    unsigned int, blockDimX,
    unsigned int, blockDimY,
    unsigned int, blockDimZ,
    unsigned int, sharedMemBytes,
    CUstream, hStream,
    void **, kernelParams
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
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, kernelParams, (uintptr_t)(kernelParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuLaunchCooperativeKernel_exit,
  TP_ARGS(
    CUfunction, f,
    unsigned int, gridDimX,
    unsigned int, gridDimY,
    unsigned int, gridDimZ,
    unsigned int, blockDimX,
    unsigned int, blockDimY,
    unsigned int, blockDimZ,
    unsigned int, sharedMemBytes,
    CUstream, hStream,
    void **, kernelParams,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuSignalExternalSemaphoresAsync_entry,
  TP_ARGS(
    const CUexternalSemaphore *, extSemArray,
    const CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS *, paramsArray,
    unsigned int, numExtSems,
    CUstream, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, extSemArray, (uintptr_t)(extSemArray))
    ctf_integer_hex(uintptr_t, paramsArray, (uintptr_t)(paramsArray))
    ctf_integer(unsigned int, numExtSems, numExtSems)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_sequence_hex(uintptr_t, extSemArray_vals, extSemArray, unsigned int, (extSemArray ? numExtSems : 0))
    ctf_sequence_text(uint8_t, paramsArray_vals, paramsArray, size_t, ((paramsArray ? numExtSems : 0)) * sizeof(CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuSignalExternalSemaphoresAsync_exit,
  TP_ARGS(
    const CUexternalSemaphore *, extSemArray,
    const CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS *, paramsArray,
    unsigned int, numExtSems,
    CUstream, stream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuWaitExternalSemaphoresAsync_entry,
  TP_ARGS(
    const CUexternalSemaphore *, extSemArray,
    const CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS *, paramsArray,
    unsigned int, numExtSems,
    CUstream, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, extSemArray, (uintptr_t)(extSemArray))
    ctf_integer_hex(uintptr_t, paramsArray, (uintptr_t)(paramsArray))
    ctf_integer(unsigned int, numExtSems, numExtSems)
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_sequence_hex(uintptr_t, extSemArray_vals, extSemArray, unsigned int, (extSemArray ? numExtSems : 0))
    ctf_sequence_text(uint8_t, paramsArray_vals, paramsArray, size_t, ((paramsArray ? numExtSems : 0)) * sizeof(CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuWaitExternalSemaphoresAsync_exit,
  TP_ARGS(
    const CUexternalSemaphore *, extSemArray,
    const CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS *, paramsArray,
    unsigned int, numExtSems,
    CUstream, stream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamBeginCapture_entry,
  TP_ARGS(
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamBeginCapture_exit,
  TP_ARGS(
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamBeginCapture_ptsz_entry,
  TP_ARGS(
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamBeginCapture_ptsz_exit,
  TP_ARGS(
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamBeginCapture_v2_entry,
  TP_ARGS(
    CUstream, hStream,
    CUstreamCaptureMode, mode
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer(int32_t, mode, mode)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamBeginCapture_v2_exit,
  TP_ARGS(
    CUstream, hStream,
    CUstreamCaptureMode, mode,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamBeginCaptureToGraph_entry,
  TP_ARGS(
    CUstream, hStream,
    CUgraph, hGraph,
    const CUgraphNode *, dependencies,
    const CUgraphEdgeData *, dependencyData,
    size_t, numDependencies,
    CUstreamCaptureMode, mode
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, dependencies, (uintptr_t)(dependencies))
    ctf_integer_hex(uintptr_t, dependencyData, (uintptr_t)(dependencyData))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer(int32_t, mode, mode)
    ctf_sequence_hex(uintptr_t, dependencies_vals, dependencies, size_t, (dependencies ? numDependencies : 0))
    ctf_sequence_text(uint8_t, dependencyData_vals, dependencyData, size_t, ((dependencyData ? numDependencies : 0)) * sizeof(CUgraphEdgeData))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamBeginCaptureToGraph_exit,
  TP_ARGS(
    CUstream, hStream,
    CUgraph, hGraph,
    const CUgraphNode *, dependencies,
    const CUgraphEdgeData *, dependencyData,
    size_t, numDependencies,
    CUstreamCaptureMode, mode,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamEndCapture_entry,
  TP_ARGS(
    CUstream, hStream,
    CUgraph *, phGraph
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, phGraph, (uintptr_t)(phGraph))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamEndCapture_exit,
  TP_ARGS(
    CUstream, hStream,
    CUgraph *, phGraph,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phGraph_val, (uintptr_t)((phGraph ? *phGraph : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamIsCapturing_entry,
  TP_ARGS(
    CUstream, hStream,
    CUstreamCaptureStatus *, captureStatus
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, captureStatus, (uintptr_t)(captureStatus))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamIsCapturing_exit,
  TP_ARGS(
    CUstream, hStream,
    CUstreamCaptureStatus *, captureStatus,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int32_t, captureStatus_val, (captureStatus ? *captureStatus : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetCaptureInfo_entry,
  TP_ARGS(
    CUstream, hStream,
    CUstreamCaptureStatus *, captureStatus_out,
    cuuint64_t *, id_out
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, captureStatus_out, (uintptr_t)(captureStatus_out))
    ctf_integer_hex(uintptr_t, id_out, (uintptr_t)(id_out))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetCaptureInfo_exit,
  TP_ARGS(
    CUstream, hStream,
    CUstreamCaptureStatus *, captureStatus_out,
    cuuint64_t *, id_out,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int32_t, captureStatus_out_val, (captureStatus_out ? *captureStatus_out : 0))
    ctf_integer(cuuint64_t, id_out_val, (id_out ? *id_out : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetCaptureInfo_ptsz_entry,
  TP_ARGS(
    CUstream, hStream,
    CUstreamCaptureStatus *, captureStatus_out,
    cuuint64_t *, id_out
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, captureStatus_out, (uintptr_t)(captureStatus_out))
    ctf_integer_hex(uintptr_t, id_out, (uintptr_t)(id_out))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetCaptureInfo_ptsz_exit,
  TP_ARGS(
    CUstream, hStream,
    CUstreamCaptureStatus *, captureStatus_out,
    cuuint64_t *, id_out,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int32_t, captureStatus_out_val, (captureStatus_out ? *captureStatus_out : 0))
    ctf_integer(cuuint64_t, id_out_val, (id_out ? *id_out : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetCaptureInfo_v2_entry,
  TP_ARGS(
    CUstream, hStream,
    CUstreamCaptureStatus *, captureStatus_out,
    cuuint64_t *, id_out,
    CUgraph *, graph_out,
    const CUgraphNode **, dependencies_out,
    size_t *, numDependencies_out
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, captureStatus_out, (uintptr_t)(captureStatus_out))
    ctf_integer_hex(uintptr_t, id_out, (uintptr_t)(id_out))
    ctf_integer_hex(uintptr_t, graph_out, (uintptr_t)(graph_out))
    ctf_integer_hex(uintptr_t, dependencies_out, (uintptr_t)(dependencies_out))
    ctf_integer_hex(uintptr_t, numDependencies_out, (uintptr_t)(numDependencies_out))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetCaptureInfo_v2_exit,
  TP_ARGS(
    CUstream, hStream,
    CUstreamCaptureStatus *, captureStatus_out,
    cuuint64_t *, id_out,
    CUgraph *, graph_out,
    const CUgraphNode **, dependencies_out,
    size_t *, numDependencies_out,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int32_t, captureStatus_out_val, (captureStatus_out ? *captureStatus_out : 0))
    ctf_integer(cuuint64_t, id_out_val, (id_out ? *id_out : 0))
    ctf_integer_hex(uintptr_t, graph_out_val, (uintptr_t)((graph_out ? *graph_out : 0)))
    ctf_integer_hex(uintptr_t, dependencies_out_val, (uintptr_t)((dependencies_out ? *dependencies_out : 0)))
    ctf_integer(size_t, numDependencies_out_val, (numDependencies_out ? *numDependencies_out : 0))
    ctf_sequence_hex(uintptr_t, dependencies_out_val_vals, *dependencies_out, size_t, (numDependencies_out && dependencies_out && *dependencies_out ? *numDependencies_out : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetCaptureInfo_v2_ptsz_entry,
  TP_ARGS(
    CUstream, hStream,
    CUstreamCaptureStatus *, captureStatus_out,
    cuuint64_t *, id_out,
    CUgraph *, graph_out,
    const CUgraphNode **, dependencies_out,
    size_t *, numDependencies_out
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, captureStatus_out, (uintptr_t)(captureStatus_out))
    ctf_integer_hex(uintptr_t, id_out, (uintptr_t)(id_out))
    ctf_integer_hex(uintptr_t, graph_out, (uintptr_t)(graph_out))
    ctf_integer_hex(uintptr_t, dependencies_out, (uintptr_t)(dependencies_out))
    ctf_integer_hex(uintptr_t, numDependencies_out, (uintptr_t)(numDependencies_out))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetCaptureInfo_v2_ptsz_exit,
  TP_ARGS(
    CUstream, hStream,
    CUstreamCaptureStatus *, captureStatus_out,
    cuuint64_t *, id_out,
    CUgraph *, graph_out,
    const CUgraphNode **, dependencies_out,
    size_t *, numDependencies_out,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int32_t, captureStatus_out_val, (captureStatus_out ? *captureStatus_out : 0))
    ctf_integer(cuuint64_t, id_out_val, (id_out ? *id_out : 0))
    ctf_integer_hex(uintptr_t, graph_out_val, (uintptr_t)((graph_out ? *graph_out : 0)))
    ctf_integer_hex(uintptr_t, dependencies_out_val, (uintptr_t)((dependencies_out ? *dependencies_out : 0)))
    ctf_integer(size_t, numDependencies_out_val, (numDependencies_out ? *numDependencies_out : 0))
    ctf_sequence_hex(uintptr_t, dependencies_out_val_vals, *dependencies_out, size_t, (numDependencies_out && dependencies_out && *dependencies_out ? *numDependencies_out : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetCaptureInfo_v3_entry,
  TP_ARGS(
    CUstream, hStream,
    CUstreamCaptureStatus *, captureStatus_out,
    cuuint64_t *, id_out,
    CUgraph *, graph_out,
    const CUgraphNode **, dependencies_out,
    const CUgraphEdgeData **, edgeData_out,
    size_t *, numDependencies_out
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, captureStatus_out, (uintptr_t)(captureStatus_out))
    ctf_integer_hex(uintptr_t, id_out, (uintptr_t)(id_out))
    ctf_integer_hex(uintptr_t, graph_out, (uintptr_t)(graph_out))
    ctf_integer_hex(uintptr_t, dependencies_out, (uintptr_t)(dependencies_out))
    ctf_integer_hex(uintptr_t, edgeData_out, (uintptr_t)(edgeData_out))
    ctf_integer_hex(uintptr_t, numDependencies_out, (uintptr_t)(numDependencies_out))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetCaptureInfo_v3_exit,
  TP_ARGS(
    CUstream, hStream,
    CUstreamCaptureStatus *, captureStatus_out,
    cuuint64_t *, id_out,
    CUgraph *, graph_out,
    const CUgraphNode **, dependencies_out,
    const CUgraphEdgeData **, edgeData_out,
    size_t *, numDependencies_out,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int32_t, captureStatus_out_val, (captureStatus_out ? *captureStatus_out : 0))
    ctf_integer(cuuint64_t, id_out_val, (id_out ? *id_out : 0))
    ctf_integer_hex(uintptr_t, graph_out_val, (uintptr_t)((graph_out ? *graph_out : 0)))
    ctf_integer(size_t, numDependencies_out_val, (numDependencies_out ? *numDependencies_out : 0))
    ctf_sequence_hex(uintptr_t, dependencies_out_val_vals, *dependencies_out, size_t, (numDependencies_out && dependencies_out && *dependencies_out ? *numDependencies_out : 0))
    ctf_sequence_text(uint8_t, edgeData_out_val_vals, *edgeData_out, size_t, ((numDependencies_out && edgeData_out && *edgeData_out ? *numDependencies_out : 0)) * sizeof(CUgraphEdgeData))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphAddKernelNode_entry,
  TP_ARGS(
    CUgraphNode *, phGraphNode,
    CUgraph, hGraph,
    const CUgraphNode *, dependencies,
    size_t, numDependencies,
    const CUDA_KERNEL_NODE_PARAMS_v1 *, nodeParams,
    size_t, _nodeParams__extra_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, phGraphNode, (uintptr_t)(phGraphNode))
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, dependencies, (uintptr_t)(dependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
    ctf_sequence_hex(uintptr_t, dependencies_vals, dependencies, size_t, (dependencies ? numDependencies : 0))
    ctf_sequence_text(uint8_t, nodeParams_val, nodeParams, size_t, (nodeParams ? sizeof(CUDA_KERNEL_NODE_PARAMS_v1) : 0))
    ctf_sequence_hex(uintptr_t, nodeParams__extra_vals, (nodeParams ? nodeParams->extra : 0), size_t, (nodeParams && nodeParams->extra ? _nodeParams__extra_size : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphAddKernelNode_exit,
  TP_ARGS(
    CUgraphNode *, phGraphNode,
    CUgraph, hGraph,
    const CUgraphNode *, dependencies,
    size_t, numDependencies,
    const CUDA_KERNEL_NODE_PARAMS_v1 *, nodeParams,
    CUresult, cuResult,
    size_t, _nodeParams__extra_size
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phGraphNode_val, (uintptr_t)((phGraphNode ? *phGraphNode : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphKernelNodeGetParams_entry,
  TP_ARGS(
    CUgraphNode, hNode,
    CUDA_KERNEL_NODE_PARAMS_v1 *, nodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphKernelNodeGetParams_exit,
  TP_ARGS(
    CUgraphNode, hNode,
    CUDA_KERNEL_NODE_PARAMS_v1 *, nodeParams,
    CUresult, cuResult,
    size_t, _nodeParams__extra_size
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, nodeParams_val, nodeParams, size_t, (nodeParams ? sizeof(CUDA_KERNEL_NODE_PARAMS_v1) : 0))
    ctf_sequence_hex(uintptr_t, nodeParams__extra_vals, (nodeParams ? nodeParams->extra : 0), size_t, (nodeParams && nodeParams->extra ? _nodeParams__extra_size : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphKernelNodeSetParams_entry,
  TP_ARGS(
    CUgraphNode, hNode,
    const CUDA_KERNEL_NODE_PARAMS_v1 *, nodeParams,
    size_t, _nodeParams__extra_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
    ctf_sequence_text(uint8_t, nodeParams_val, nodeParams, size_t, (nodeParams ? sizeof(CUDA_KERNEL_NODE_PARAMS_v1) : 0))
    ctf_sequence_hex(uintptr_t, nodeParams__extra_vals, (nodeParams ? nodeParams->extra : 0), size_t, (nodeParams && nodeParams->extra ? _nodeParams__extra_size : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphKernelNodeSetParams_exit,
  TP_ARGS(
    CUgraphNode, hNode,
    const CUDA_KERNEL_NODE_PARAMS_v1 *, nodeParams,
    CUresult, cuResult,
    size_t, _nodeParams__extra_size
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExecKernelNodeSetParams_entry,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUgraphNode, hNode,
    const CUDA_KERNEL_NODE_PARAMS_v1 *, nodeParams,
    size_t, _nodeParams__extra_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
    ctf_sequence_text(uint8_t, nodeParams_val, nodeParams, size_t, (nodeParams ? sizeof(CUDA_KERNEL_NODE_PARAMS_v1) : 0))
    ctf_sequence_hex(uintptr_t, nodeParams__extra_vals, (nodeParams ? nodeParams->extra : 0), size_t, (nodeParams && nodeParams->extra ? _nodeParams__extra_size : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExecKernelNodeSetParams_exit,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUgraphNode, hNode,
    const CUDA_KERNEL_NODE_PARAMS_v1 *, nodeParams,
    CUresult, cuResult,
    size_t, _nodeParams__extra_size
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphInstantiateWithParams_entry,
  TP_ARGS(
    CUgraphExec *, phGraphExec,
    CUgraph, hGraph,
    CUDA_GRAPH_INSTANTIATE_PARAMS *, instantiateParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, phGraphExec, (uintptr_t)(phGraphExec))
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, instantiateParams, (uintptr_t)(instantiateParams))
    ctf_sequence_text(uint8_t, instantiateParams_val, instantiateParams, size_t, (instantiateParams ? sizeof(CUDA_GRAPH_INSTANTIATE_PARAMS) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphInstantiateWithParams_exit,
  TP_ARGS(
    CUgraphExec *, phGraphExec,
    CUgraph, hGraph,
    CUDA_GRAPH_INSTANTIATE_PARAMS *, instantiateParams,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phGraphExec_val, (uintptr_t)((phGraphExec ? *phGraphExec : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExecUpdate_entry,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUgraph, hGraph,
    CUgraphNode *, hErrorNode_out,
    CUgraphExecUpdateResult *, updateResult_out
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraphExec, (uintptr_t)(hGraphExec))
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, hErrorNode_out, (uintptr_t)(hErrorNode_out))
    ctf_integer_hex(uintptr_t, updateResult_out, (uintptr_t)(updateResult_out))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphExecUpdate_exit,
  TP_ARGS(
    CUgraphExec, hGraphExec,
    CUgraph, hGraph,
    CUgraphNode *, hErrorNode_out,
    CUgraphExecUpdateResult *, updateResult_out,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, hErrorNode_out_val, (uintptr_t)((hErrorNode_out ? *hErrorNode_out : 0)))
    ctf_integer(int32_t, updateResult_out_val, (updateResult_out ? *updateResult_out : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphUpload_entry,
  TP_ARGS(
    CUgraphExec, hGraph,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphUpload_exit,
  TP_ARGS(
    CUgraphExec, hGraph,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphLaunch_entry,
  TP_ARGS(
    CUgraphExec, hGraph,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphLaunch_exit,
  TP_ARGS(
    CUgraphExec, hGraph,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphGetEdges_entry,
  TP_ARGS(
    CUgraph, hGraph,
    CUgraphNode *, from,
    CUgraphNode *, to,
    size_t *, numEdges
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, from, (uintptr_t)(from))
    ctf_integer_hex(uintptr_t, to, (uintptr_t)(to))
    ctf_integer_hex(uintptr_t, numEdges, (uintptr_t)(numEdges))
    ctf_integer(size_t, numEdges_val, (numEdges ? *numEdges : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphGetEdges_exit,
  TP_ARGS(
    CUgraph, hGraph,
    CUgraphNode *, from,
    CUgraphNode *, to,
    size_t *, numEdges,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(size_t, numEdges_val, (numEdges ? *numEdges : 0))
    ctf_sequence_hex(uintptr_t, from_vals, from, size_t, (numEdges && from ? *numEdges : 0))
    ctf_sequence_hex(uintptr_t, to_vals, to, size_t, (numEdges && to ? *numEdges : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphNodeGetDependencies_entry,
  TP_ARGS(
    CUgraphNode, hNode,
    CUgraphNode *, dependencies,
    size_t *, numDependencies
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, dependencies, (uintptr_t)(dependencies))
    ctf_integer_hex(uintptr_t, numDependencies, (uintptr_t)(numDependencies))
    ctf_integer(size_t, numDependencies_val, (numDependencies ? *numDependencies : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphNodeGetDependencies_exit,
  TP_ARGS(
    CUgraphNode, hNode,
    CUgraphNode *, dependencies,
    size_t *, numDependencies,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(size_t, numDependencies_val, (numDependencies ? *numDependencies : 0))
    ctf_sequence_hex(uintptr_t, dependencies_vals, dependencies, size_t, (numDependencies && dependencies ? *numDependencies : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphNodeGetDependentNodes_entry,
  TP_ARGS(
    CUgraphNode, hNode,
    CUgraphNode *, dependentNodes,
    size_t *, numDependentNodes
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hNode, (uintptr_t)(hNode))
    ctf_integer_hex(uintptr_t, dependentNodes, (uintptr_t)(dependentNodes))
    ctf_integer_hex(uintptr_t, numDependentNodes, (uintptr_t)(numDependentNodes))
    ctf_integer(size_t, numDependentNodes_val, (numDependentNodes ? *numDependentNodes : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphNodeGetDependentNodes_exit,
  TP_ARGS(
    CUgraphNode, hNode,
    CUgraphNode *, dependentNodes,
    size_t *, numDependentNodes,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(size_t, numDependentNodes_val, (numDependentNodes ? *numDependentNodes : 0))
    ctf_sequence_hex(uintptr_t, dependentNodes_vals, dependentNodes, size_t, (numDependentNodes && dependentNodes ? *numDependentNodes : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphAddDependencies_entry,
  TP_ARGS(
    CUgraph, hGraph,
    const CUgraphNode *, from,
    const CUgraphNode *, to,
    size_t, numDependencies
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, from, (uintptr_t)(from))
    ctf_integer_hex(uintptr_t, to, (uintptr_t)(to))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_sequence_hex(uintptr_t, from_vals, from, size_t, (from ? numDependencies : 0))
    ctf_sequence_hex(uintptr_t, to_vals, to, size_t, (to ? numDependencies : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphAddDependencies_exit,
  TP_ARGS(
    CUgraph, hGraph,
    const CUgraphNode *, from,
    const CUgraphNode *, to,
    size_t, numDependencies,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphRemoveDependencies_entry,
  TP_ARGS(
    CUgraph, hGraph,
    const CUgraphNode *, from,
    const CUgraphNode *, to,
    size_t, numDependencies
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, from, (uintptr_t)(from))
    ctf_integer_hex(uintptr_t, to, (uintptr_t)(to))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_sequence_hex(uintptr_t, from_vals, from, size_t, (from ? numDependencies : 0))
    ctf_sequence_hex(uintptr_t, to_vals, to, size_t, (to ? numDependencies : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphRemoveDependencies_exit,
  TP_ARGS(
    CUgraph, hGraph,
    const CUgraphNode *, from,
    const CUgraphNode *, to,
    size_t, numDependencies,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphAddNode_entry,
  TP_ARGS(
    CUgraphNode *, phGraphNode,
    CUgraph, hGraph,
    const CUgraphNode *, dependencies,
    size_t, numDependencies,
    CUgraphNodeParams *, nodeParams
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, phGraphNode, (uintptr_t)(phGraphNode))
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, dependencies, (uintptr_t)(dependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer_hex(uintptr_t, nodeParams, (uintptr_t)(nodeParams))
    ctf_sequence_hex(uintptr_t, dependencies_vals, dependencies, size_t, (dependencies ? numDependencies : 0))
    ctf_sequence_text(uint8_t, nodeParams_val, nodeParams, size_t, (nodeParams ? sizeof(CUgraphNodeParams) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphAddNode_exit,
  TP_ARGS(
    CUgraphNode *, phGraphNode,
    CUgraph, hGraph,
    const CUgraphNode *, dependencies,
    size_t, numDependencies,
    CUgraphNodeParams *, nodeParams,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phGraphNode_val, (uintptr_t)((phGraphNode ? *phGraphNode : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamCopyAttributes_entry,
  TP_ARGS(
    CUstream, dstStream,
    CUstream, srcStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dstStream, (uintptr_t)(dstStream))
    ctf_integer_hex(uintptr_t, srcStream, (uintptr_t)(srcStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamCopyAttributes_exit,
  TP_ARGS(
    CUstream, dstStream,
    CUstream, srcStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetAttribute_entry,
  TP_ARGS(
    CUstream, hStream,
    CUstreamAttrID, attr,
    CUstreamAttrValue *, value
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer(int32_t, attr, attr)
    ctf_integer_hex(uintptr_t, value, (uintptr_t)(value))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamGetAttribute_exit,
  TP_ARGS(
    CUstream, hStream,
    CUstreamAttrID, attr,
    CUstreamAttrValue *, value,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_sequence_text(uint8_t, value_val, value, size_t, (value ? sizeof(CUstreamAttrValue) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamSetAttribute_entry,
  TP_ARGS(
    CUstream, hStream,
    CUstreamAttrID, attr,
    const CUstreamAttrValue *, param
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer(int32_t, attr, attr)
    ctf_integer_hex(uintptr_t, param, (uintptr_t)(param))
    ctf_sequence_text(uint8_t, param_val, param, size_t, (param ? sizeof(CUstreamAttrValue) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamSetAttribute_exit,
  TP_ARGS(
    CUstream, hStream,
    CUstreamAttrID, attr,
    const CUstreamAttrValue *, param,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuIpcOpenMemHandle_entry,
  TP_ARGS(
    CUdeviceptr *, pdptr,
    CUipcMemHandle, handle,
    unsigned int, Flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pdptr, (uintptr_t)(pdptr))
    ctf_array_text(uint8_t, handle, &handle, sizeof(CUipcMemHandle))
    ctf_integer(unsigned int, Flags, Flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuIpcOpenMemHandle_exit,
  TP_ARGS(
    CUdeviceptr *, pdptr,
    CUipcMemHandle, handle,
    unsigned int, Flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(CUdeviceptr, pdptr_val, (pdptr ? *pdptr : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphInstantiate_entry,
  TP_ARGS(
    CUgraphExec *, phGraphExec,
    CUgraph, hGraph,
    CUgraphNode *, phErrorNode,
    char *, logBuffer,
    size_t, bufferSize
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, phGraphExec, (uintptr_t)(phGraphExec))
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, phErrorNode, (uintptr_t)(phErrorNode))
    ctf_integer_hex(uintptr_t, logBuffer, (uintptr_t)(logBuffer))
    ctf_integer(size_t, bufferSize, bufferSize)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphInstantiate_exit,
  TP_ARGS(
    CUgraphExec *, phGraphExec,
    CUgraph, hGraph,
    CUgraphNode *, phErrorNode,
    char *, logBuffer,
    size_t, bufferSize,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phGraphExec_val, (uintptr_t)((phGraphExec ? *phGraphExec : 0)))
    ctf_integer_hex(uintptr_t, phErrorNode_val, (uintptr_t)((phErrorNode ? *phErrorNode : 0)))
    ctf_sequence_text(char, logBuffer_vals, logBuffer, size_t, (logBuffer ? bufferSize : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphInstantiate_v2_entry,
  TP_ARGS(
    CUgraphExec *, phGraphExec,
    CUgraph, hGraph,
    CUgraphNode *, phErrorNode,
    char *, logBuffer,
    size_t, bufferSize
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, phGraphExec, (uintptr_t)(phGraphExec))
    ctf_integer_hex(uintptr_t, hGraph, (uintptr_t)(hGraph))
    ctf_integer_hex(uintptr_t, phErrorNode, (uintptr_t)(phErrorNode))
    ctf_integer_hex(uintptr_t, logBuffer, (uintptr_t)(logBuffer))
    ctf_integer(size_t, bufferSize, bufferSize)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphInstantiate_v2_exit,
  TP_ARGS(
    CUgraphExec *, phGraphExec,
    CUgraph, hGraph,
    CUgraphNode *, phErrorNode,
    char *, logBuffer,
    size_t, bufferSize,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, phGraphExec_val, (uintptr_t)((phGraphExec ? *phGraphExec : 0)))
    ctf_integer_hex(uintptr_t, phErrorNode_val, (uintptr_t)((phErrorNode ? *phErrorNode : 0)))
    ctf_sequence_text(char, logBuffer_vals, logBuffer, size_t, (logBuffer ? bufferSize : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemMapArrayAsync_entry,
  TP_ARGS(
    CUarrayMapInfo *, mapInfoList,
    unsigned int, count,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mapInfoList, (uintptr_t)(mapInfoList))
    ctf_integer(unsigned int, count, count)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_sequence_text(uint8_t, mapInfoList_vals, mapInfoList, size_t, ((mapInfoList ? count : 0)) * sizeof(CUarrayMapInfo))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemMapArrayAsync_exit,
  TP_ARGS(
    CUarrayMapInfo *, mapInfoList,
    unsigned int, count,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemFreeAsync_entry,
  TP_ARGS(
    CUdeviceptr, dptr,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(CUdeviceptr, dptr, dptr)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemFreeAsync_exit,
  TP_ARGS(
    CUdeviceptr, dptr,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemAllocAsync_entry,
  TP_ARGS(
    CUdeviceptr *, dptr,
    size_t, bytesize,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dptr, (uintptr_t)(dptr))
    ctf_integer(size_t, bytesize, bytesize)
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemAllocAsync_exit,
  TP_ARGS(
    CUdeviceptr *, dptr,
    size_t, bytesize,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(CUdeviceptr, dptr_val, (dptr ? *dptr : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemAllocFromPoolAsync_entry,
  TP_ARGS(
    CUdeviceptr *, dptr,
    size_t, bytesize,
    CUmemoryPool, pool,
    CUstream, hStream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, dptr, (uintptr_t)(dptr))
    ctf_integer(size_t, bytesize, bytesize)
    ctf_integer_hex(uintptr_t, pool, (uintptr_t)(pool))
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemAllocFromPoolAsync_exit,
  TP_ARGS(
    CUdeviceptr *, dptr,
    size_t, bytesize,
    CUmemoryPool, pool,
    CUstream, hStream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(CUdeviceptr, dptr_val, (dptr ? *dptr : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamUpdateCaptureDependencies_entry,
  TP_ARGS(
    CUstream, hStream,
    CUgraphNode *, dependencies,
    size_t, numDependencies,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, dependencies, (uintptr_t)(dependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer(unsigned int, flags, flags)
    ctf_sequence_hex(uintptr_t, dependencies_vals, dependencies, size_t, (dependencies ? numDependencies : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamUpdateCaptureDependencies_exit,
  TP_ARGS(
    CUstream, hStream,
    CUgraphNode *, dependencies,
    size_t, numDependencies,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamUpdateCaptureDependencies_ptsz_entry,
  TP_ARGS(
    CUstream, hStream,
    CUgraphNode *, dependencies,
    size_t, numDependencies,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, dependencies, (uintptr_t)(dependencies))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer(unsigned int, flags, flags)
    ctf_sequence_hex(uintptr_t, dependencies_vals, dependencies, size_t, (dependencies ? numDependencies : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamUpdateCaptureDependencies_ptsz_exit,
  TP_ARGS(
    CUstream, hStream,
    CUgraphNode *, dependencies,
    size_t, numDependencies,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamUpdateCaptureDependencies_v2_entry,
  TP_ARGS(
    CUstream, hStream,
    CUgraphNode *, dependencies,
    const CUgraphEdgeData *, dependencyData,
    size_t, numDependencies,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStream, (uintptr_t)(hStream))
    ctf_integer_hex(uintptr_t, dependencies, (uintptr_t)(dependencies))
    ctf_integer_hex(uintptr_t, dependencyData, (uintptr_t)(dependencyData))
    ctf_integer(size_t, numDependencies, numDependencies)
    ctf_integer(unsigned int, flags, flags)
    ctf_sequence_hex(uintptr_t, dependencies_vals, dependencies, size_t, (dependencies ? numDependencies : 0))
    ctf_sequence_text(uint8_t, dependencyData_vals, dependencyData, size_t, ((dependencyData ? numDependencies : 0)) * sizeof(CUgraphEdgeData))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuStreamUpdateCaptureDependencies_v2_exit,
  TP_ARGS(
    CUstream, hStream,
    CUgraphNode *, dependencies,
    const CUgraphEdgeData *, dependencyData,
    size_t, numDependencies,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemBatchDecompressAsync_entry,
  TP_ARGS(
    CUmemDecompressParams *, paramsArray,
    size_t, count,
    unsigned int, flags,
    size_t *, errorIndex,
    CUstream, stream
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, paramsArray, (uintptr_t)(paramsArray))
    ctf_integer(size_t, count, count)
    ctf_integer(unsigned int, flags, flags)
    ctf_integer_hex(uintptr_t, errorIndex, (uintptr_t)(errorIndex))
    ctf_integer_hex(uintptr_t, stream, (uintptr_t)(stream))
    ctf_sequence_text(uint8_t, paramsArray_vals, paramsArray, size_t, ((paramsArray ? count : 0)) * sizeof(CUmemDecompressParams))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuMemBatchDecompressAsync_exit,
  TP_ARGS(
    CUmemDecompressParams *, paramsArray,
    size_t, count,
    unsigned int, flags,
    size_t *, errorIndex,
    CUstream, stream,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(size_t, errorIndex_val, (errorIndex ? *errorIndex : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGetProcAddress_entry,
  TP_ARGS(
    const char *, symbol,
    void **, pfn,
    int, cudaVersion,
    cuuint64_t, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, symbol, (uintptr_t)(symbol))
    ctf_integer_hex(uintptr_t, pfn, (uintptr_t)(pfn))
    ctf_integer(int, cudaVersion, cudaVersion)
    ctf_integer(cuuint64_t, flags, flags)
    ctf_string(symbol_val, symbol)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGetProcAddress_exit,
  TP_ARGS(
    const char *, symbol,
    void **, pfn,
    int, cudaVersion,
    cuuint64_t, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer_hex(uintptr_t, pfn_val, (uintptr_t)((pfn ? *pfn : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCheckpointProcessGetRestoreThreadId_entry,
  TP_ARGS(
    int, pid,
    int *, tid
  ),
  TP_FIELDS(
    ctf_integer(int, pid, pid)
    ctf_integer_hex(uintptr_t, tid, (uintptr_t)(tid))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCheckpointProcessGetRestoreThreadId_exit,
  TP_ARGS(
    int, pid,
    int *, tid,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int, tid_val, (tid ? *tid : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCheckpointProcessGetState_entry,
  TP_ARGS(
    int, pid,
    CUprocessState *, state
  ),
  TP_FIELDS(
    ctf_integer(int, pid, pid)
    ctf_integer_hex(uintptr_t, state, (uintptr_t)(state))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCheckpointProcessGetState_exit,
  TP_ARGS(
    int, pid,
    CUprocessState *, state,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
    ctf_integer(int32_t, state_val, (state ? *state : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCheckpointProcessLock_entry,
  TP_ARGS(
    int, pid,
    CUcheckpointLockArgs *, args
  ),
  TP_FIELDS(
    ctf_integer(int, pid, pid)
    ctf_integer_hex(uintptr_t, args, (uintptr_t)(args))
    ctf_sequence_text(uint8_t, args_val, args, size_t, (args ? sizeof(CUcheckpointLockArgs) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCheckpointProcessLock_exit,
  TP_ARGS(
    int, pid,
    CUcheckpointLockArgs *, args,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCheckpointProcessCheckpoint_entry,
  TP_ARGS(
    int, pid,
    CUcheckpointCheckpointArgs *, args
  ),
  TP_FIELDS(
    ctf_integer(int, pid, pid)
    ctf_integer_hex(uintptr_t, args, (uintptr_t)(args))
    ctf_sequence_text(uint8_t, args_val, args, size_t, (args ? sizeof(CUcheckpointCheckpointArgs) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCheckpointProcessCheckpoint_exit,
  TP_ARGS(
    int, pid,
    CUcheckpointCheckpointArgs *, args,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCheckpointProcessRestore_entry,
  TP_ARGS(
    int, pid,
    CUcheckpointRestoreArgs *, args
  ),
  TP_FIELDS(
    ctf_integer(int, pid, pid)
    ctf_integer_hex(uintptr_t, args, (uintptr_t)(args))
    ctf_sequence_text(uint8_t, args_val, args, size_t, (args ? sizeof(CUcheckpointRestoreArgs) : 0))
    ctf_sequence_text(uint8_t, args__gpuPairs_vals, (args ? args->gpuPairs : 0), size_t, ((args && args->gpuPairs ? args->gpuPairsCount : 0)) * sizeof(CUcheckpointGpuPair))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCheckpointProcessRestore_exit,
  TP_ARGS(
    int, pid,
    CUcheckpointRestoreArgs *, args,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCheckpointProcessUnlock_entry,
  TP_ARGS(
    int, pid,
    CUcheckpointUnlockArgs *, args
  ),
  TP_FIELDS(
    ctf_integer(int, pid, pid)
    ctf_integer_hex(uintptr_t, args, (uintptr_t)(args))
    ctf_sequence_text(uint8_t, args_val, args, size_t, (args ? sizeof(CUcheckpointUnlockArgs) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuCheckpointProcessUnlock_exit,
  TP_ARGS(
    int, pid,
    CUcheckpointUnlockArgs *, args,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuVDPAUGetDevice_entry,
  TP_ARGS(
    CUdevice *, pDevice,
    VdpDevice, vdpDevice,
    VdpGetProcAddress *, vdpGetProcAddress
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pDevice, (uintptr_t)(pDevice))
    ctf_integer(VdpDevice, vdpDevice, vdpDevice)
    ctf_integer_hex(uintptr_t, vdpGetProcAddress, (uintptr_t)(vdpGetProcAddress))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuVDPAUGetDevice_exit,
  TP_ARGS(
    CUdevice *, pDevice,
    VdpDevice, vdpDevice,
    VdpGetProcAddress *, vdpGetProcAddress,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuVDPAUCtxCreate_v2_entry,
  TP_ARGS(
    CUcontext *, pCtx,
    unsigned int, flags,
    CUdevice, device,
    VdpDevice, vdpDevice,
    VdpGetProcAddress *, vdpGetProcAddress
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pCtx, (uintptr_t)(pCtx))
    ctf_integer(unsigned int, flags, flags)
    ctf_integer(CUdevice, device, device)
    ctf_integer(VdpDevice, vdpDevice, vdpDevice)
    ctf_integer_hex(uintptr_t, vdpGetProcAddress, (uintptr_t)(vdpGetProcAddress))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuVDPAUCtxCreate_v2_exit,
  TP_ARGS(
    CUcontext *, pCtx,
    unsigned int, flags,
    CUdevice, device,
    VdpDevice, vdpDevice,
    VdpGetProcAddress *, vdpGetProcAddress,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphicsVDPAURegisterVideoSurface_entry,
  TP_ARGS(
    CUgraphicsResource *, pCudaResource,
    VdpVideoSurface, vdpSurface,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pCudaResource, (uintptr_t)(pCudaResource))
    ctf_integer(VdpVideoSurface, vdpSurface, vdpSurface)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphicsVDPAURegisterVideoSurface_exit,
  TP_ARGS(
    CUgraphicsResource *, pCudaResource,
    VdpVideoSurface, vdpSurface,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphicsVDPAURegisterOutputSurface_entry,
  TP_ARGS(
    CUgraphicsResource *, pCudaResource,
    VdpOutputSurface, vdpSurface,
    unsigned int, flags
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pCudaResource, (uintptr_t)(pCudaResource))
    ctf_integer(VdpOutputSurface, vdpSurface, vdpSurface)
    ctf_integer(unsigned int, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuGraphicsVDPAURegisterOutputSurface_exit,
  TP_ARGS(
    CUgraphicsResource *, pCudaResource,
    VdpOutputSurface, vdpSurface,
    unsigned int, flags,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuVDPAUCtxCreate_entry,
  TP_ARGS(
    CUcontext *, pCtx,
    unsigned int, flags,
    CUdevice, device,
    VdpDevice, vdpDevice,
    VdpGetProcAddress *, vdpGetProcAddress
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pCtx, (uintptr_t)(pCtx))
    ctf_integer(unsigned int, flags, flags)
    ctf_integer(CUdevice, device, device)
    ctf_integer(VdpDevice, vdpDevice, vdpDevice)
    ctf_integer_hex(uintptr_t, vdpGetProcAddress, (uintptr_t)(vdpGetProcAddress))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuVDPAUCtxCreate_exit,
  TP_ARGS(
    CUcontext *, pCtx,
    unsigned int, flags,
    CUdevice, device,
    VdpDevice, vdpDevice,
    VdpGetProcAddress *, vdpGetProcAddress,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuProfilerInitialize_entry,
  TP_ARGS(
    const char *, configFile,
    const char *, outputFile,
    CUoutput_mode, outputMode
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, configFile, (uintptr_t)(configFile))
    ctf_integer_hex(uintptr_t, outputFile, (uintptr_t)(outputFile))
    ctf_integer(int32_t, outputMode, outputMode)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuProfilerInitialize_exit,
  TP_ARGS(
    const char *, configFile,
    const char *, outputFile,
    CUoutput_mode, outputMode,
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuProfilerStart_entry,
  TP_ARGS(
    void
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuProfilerStart_exit,
  TP_ARGS(
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuProfilerStop_entry,
  TP_ARGS(
    void
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda,
  cuProfilerStop_exit,
  TP_ARGS(
    CUresult, cuResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, cuResult, cuResult)
  )
)


#endif /* CUDA_TRACEPOINTS_H */

#include <lttng/tracepoint-event.h>
