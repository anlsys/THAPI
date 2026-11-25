#pragma once
#include <babeltrace2/babeltrace.h>
#include <metababel/btx_component.h>
#ifdef __cplusplus
extern "C" {
#endif
void btx_downstream_move_messages(
    btx_message_iterator_t *message_iterator_private_data,
    bt_message_array_const messages, uint64_t capacity, uint64_t *count);

void btx_downstream_push_message(
    btx_message_iterator_t *message_iterator_private_data,
    const bt_message *message);

bt_trace_class *
btx_downstream_trace_class_create_rec(bt_self_component *self_component);

bt_trace *btx_downstream_trace_create_rec(bt_trace_class *trace_class);

void btx_streams_get_ref(bt_trace *trace);
void btx_streams_put_ref(bt_trace *trace);

void btx_push_messages_stream_beginning(
    bt_self_message_iterator *self_message_iterator,
    btx_message_iterator_t *message_iterator_private_data);
void btx_push_messages_stream_end(
    bt_self_message_iterator *self_message_iterator,
    btx_message_iterator_t *message_iterator_private_data);

void btx_push_message_lttng_ust_cuda_cuGetErrorString_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult error, char ** pStr);
void btx_push_message_lttng_ust_cuda_cuGetErrorString_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, char * pStr_val, char * pStr_val_val);
void btx_push_message_lttng_ust_cuda_cuGetErrorName_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult error, char ** pStr);
void btx_push_message_lttng_ust_cuda_cuGetErrorName_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, char * pStr_val, char * pStr_val_val);
void btx_push_message_lttng_ust_cuda_cuInit_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, unsigned int Flags);
void btx_push_message_lttng_ust_cuda_cuInit_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuDriverGetVersion_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * driverVersion);
void btx_push_message_lttng_ust_cuda_cuDriverGetVersion_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, int driverVersion_val);
void btx_push_message_lttng_ust_cuda_cuDeviceGet_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdevice * device, int ordinal);
void btx_push_message_lttng_ust_cuda_cuDeviceGet_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUdevice device_val);
void btx_push_message_lttng_ust_cuda_cuDeviceGetCount_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * count);
void btx_push_message_lttng_ust_cuda_cuDeviceGetCount_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, int count_val);
void btx_push_message_lttng_ust_cuda_cuDeviceGetName_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, char * name, int len, CUdevice dev);
void btx_push_message_lttng_ust_cuda_cuDeviceGetName_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, char * name_val);
void btx_push_message_lttng_ust_cuda_cuDeviceGetUuid_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUuuid * uuid, CUdevice dev);
void btx_push_message_lttng_ust_cuda_cuDeviceGetUuid_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _uuid_val_length, CUuuid * uuid_val);
void btx_push_message_lttng_ust_cuda_cuDeviceGetLuid_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, char * luid, unsigned int * deviceNodeMask, CUdevice dev);
void btx_push_message_lttng_ust_cuda_cuDeviceGetLuid_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, char * luid_vals, unsigned int deviceNodeMask_val);
void btx_push_message_lttng_ust_cuda_cuDeviceTotalMem_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, size_t * bytes, CUdevice dev);
void btx_push_message_lttng_ust_cuda_cuDeviceTotalMem_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t bytes_val);
void btx_push_message_lttng_ust_cuda_cuDeviceGetTexture1DLinearMaxWidth_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, size_t * maxWidthInElements, CUarray_format format, unsigned int numChannels, CUdevice dev);
void btx_push_message_lttng_ust_cuda_cuDeviceGetTexture1DLinearMaxWidth_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t maxWidthInElements_val);
void btx_push_message_lttng_ust_cuda_cuDeviceGetAttribute_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * pi, CUdevice_attribute attrib, CUdevice dev);
void btx_push_message_lttng_ust_cuda_cuDeviceGetAttribute_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, int pi_val);
void btx_push_message_lttng_ust_cuda_cuDeviceGetHostAtomicCapabilities_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, unsigned int * capabilities, CUatomicOperation * operations, unsigned int count, CUdevice dev, size_t _operations_vals_length, CUatomicOperation * operations_vals);
void btx_push_message_lttng_ust_cuda_cuDeviceGetHostAtomicCapabilities_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _capabilities_vals_length, unsigned int * capabilities_vals);
void btx_push_message_lttng_ust_cuda_cuDeviceGetNvSciSyncAttributes_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * nvSciSyncAttrList, CUdevice dev, int flags);
void btx_push_message_lttng_ust_cuda_cuDeviceGetNvSciSyncAttributes_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuDeviceSetMemPool_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdevice dev, CUmemoryPool pool);
void btx_push_message_lttng_ust_cuda_cuDeviceSetMemPool_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuDeviceGetMemPool_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmemoryPool * pool, CUdevice dev);
void btx_push_message_lttng_ust_cuda_cuDeviceGetMemPool_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUmemoryPool pool_val);
void btx_push_message_lttng_ust_cuda_cuDeviceGetDefaultMemPool_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmemoryPool * pool_out, CUdevice dev);
void btx_push_message_lttng_ust_cuda_cuDeviceGetDefaultMemPool_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUmemoryPool pool_out_val);
void btx_push_message_lttng_ust_cuda_cuDeviceGetExecAffinitySupport_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * pi, CUexecAffinityType type, CUdevice dev);
void btx_push_message_lttng_ust_cuda_cuDeviceGetExecAffinitySupport_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, int pi_val);
void btx_push_message_lttng_ust_cuda_cuFlushGPUDirectRDMAWrites_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUflushGPUDirectRDMAWritesTarget target, CUflushGPUDirectRDMAWritesScope scope);
void btx_push_message_lttng_ust_cuda_cuFlushGPUDirectRDMAWrites_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuDeviceGetProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdevprop * prop, CUdevice dev);
void btx_push_message_lttng_ust_cuda_cuDeviceGetProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _prop_val_length, CUdevprop * prop_val);
void btx_push_message_lttng_ust_cuda_cuDeviceComputeCapability_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * major, int * minor, CUdevice dev);
void btx_push_message_lttng_ust_cuda_cuDeviceComputeCapability_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, int major_val, int minor_val);
void btx_push_message_lttng_ust_cuda_cuDevicePrimaryCtxRetain_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext * pctx, CUdevice dev);
void btx_push_message_lttng_ust_cuda_cuDevicePrimaryCtxRetain_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUcontext pctx_val);
void btx_push_message_lttng_ust_cuda_cuDevicePrimaryCtxRelease_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdevice dev);
void btx_push_message_lttng_ust_cuda_cuDevicePrimaryCtxRelease_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuDevicePrimaryCtxSetFlags_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdevice dev, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuDevicePrimaryCtxSetFlags_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuDevicePrimaryCtxGetState_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdevice dev, unsigned int * flags, int * active);
void btx_push_message_lttng_ust_cuda_cuDevicePrimaryCtxGetState_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, unsigned int flags_val, int active_val);
void btx_push_message_lttng_ust_cuda_cuDevicePrimaryCtxReset_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdevice dev);
void btx_push_message_lttng_ust_cuda_cuDevicePrimaryCtxReset_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuCtxCreate_v4_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext * pctx, CUctxCreateParams * ctxCreateParams, unsigned int flags, CUdevice dev, size_t _ctxCreateParams_val_length, CUctxCreateParams * ctxCreateParams_val, size_t _ctxCreateParams__execAffinityParams_vals_length, CUexecAffinityParam * ctxCreateParams__execAffinityParams_vals, size_t _ctxCreateParams__cigParams_val_length, CUctxCigParam * ctxCreateParams__cigParams_val);
void btx_push_message_lttng_ust_cuda_cuCtxCreate_v4_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUcontext pctx_val);
void btx_push_message_lttng_ust_cuda_cuCtxDestroy_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext ctx);
void btx_push_message_lttng_ust_cuda_cuCtxDestroy_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuCtxPushCurrent_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext ctx);
void btx_push_message_lttng_ust_cuda_cuCtxPushCurrent_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuCtxPopCurrent_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext * pctx);
void btx_push_message_lttng_ust_cuda_cuCtxPopCurrent_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUcontext pctx_val);
void btx_push_message_lttng_ust_cuda_cuCtxSetCurrent_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext ctx);
void btx_push_message_lttng_ust_cuda_cuCtxSetCurrent_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuCtxGetCurrent_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext * pctx);
void btx_push_message_lttng_ust_cuda_cuCtxGetCurrent_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUcontext pctx_val);
void btx_push_message_lttng_ust_cuda_cuCtxGetDevice_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdevice * device);
void btx_push_message_lttng_ust_cuda_cuCtxGetDevice_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUdevice device_val);
void btx_push_message_lttng_ust_cuda_cuCtxGetDevice_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdevice * device, CUcontext ctx);
void btx_push_message_lttng_ust_cuda_cuCtxGetDevice_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUdevice device_val);
void btx_push_message_lttng_ust_cuda_cuCtxGetFlags_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, unsigned int * flags);
void btx_push_message_lttng_ust_cuda_cuCtxGetFlags_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, unsigned int flags_val);
void btx_push_message_lttng_ust_cuda_cuCtxSetFlags_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuCtxSetFlags_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuCtxGetId_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext ctx, unsigned long long int * ctxId);
void btx_push_message_lttng_ust_cuda_cuCtxGetId_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, unsigned long long int ctxId_val);
void btx_push_message_lttng_ust_cuda_cuCtxSynchronize_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_cuda_cuCtxSynchronize_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuCtxSynchronize_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext ctx);
void btx_push_message_lttng_ust_cuda_cuCtxSynchronize_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuCtxSetLimit_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUlimit limit, size_t value);
void btx_push_message_lttng_ust_cuda_cuCtxSetLimit_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuCtxGetLimit_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, size_t * pvalue, CUlimit limit);
void btx_push_message_lttng_ust_cuda_cuCtxGetLimit_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t pvalue_val);
void btx_push_message_lttng_ust_cuda_cuCtxGetCacheConfig_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUfunc_cache * pconfig);
void btx_push_message_lttng_ust_cuda_cuCtxGetCacheConfig_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUfunc_cache pconfig_val);
void btx_push_message_lttng_ust_cuda_cuCtxSetCacheConfig_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUfunc_cache config);
void btx_push_message_lttng_ust_cuda_cuCtxSetCacheConfig_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuCtxGetApiVersion_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext ctx, unsigned int * version);
void btx_push_message_lttng_ust_cuda_cuCtxGetApiVersion_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, unsigned int version_val);
void btx_push_message_lttng_ust_cuda_cuCtxGetStreamPriorityRange_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * leastPriority, int * greatestPriority);
void btx_push_message_lttng_ust_cuda_cuCtxGetStreamPriorityRange_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, int leastPriority_val, int greatestPriority_val);
void btx_push_message_lttng_ust_cuda_cuCtxResetPersistingL2Cache_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_cuda_cuCtxResetPersistingL2Cache_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuCtxGetExecAffinity_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUexecAffinityParam * pExecAffinity, CUexecAffinityType type);
void btx_push_message_lttng_ust_cuda_cuCtxGetExecAffinity_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _pExecAffinity_val_length, CUexecAffinityParam * pExecAffinity_val);
void btx_push_message_lttng_ust_cuda_cuCtxRecordEvent_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext hCtx, CUevent hEvent);
void btx_push_message_lttng_ust_cuda_cuCtxRecordEvent_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuCtxWaitEvent_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext hCtx, CUevent hEvent);
void btx_push_message_lttng_ust_cuda_cuCtxWaitEvent_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuCtxAttach_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext * pctx, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuCtxAttach_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUcontext pctx_val);
void btx_push_message_lttng_ust_cuda_cuCtxDetach_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext ctx);
void btx_push_message_lttng_ust_cuda_cuCtxDetach_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuCtxGetSharedMemConfig_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUsharedconfig * pConfig);
void btx_push_message_lttng_ust_cuda_cuCtxGetSharedMemConfig_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUsharedconfig pConfig_val);
void btx_push_message_lttng_ust_cuda_cuCtxSetSharedMemConfig_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUsharedconfig config);
void btx_push_message_lttng_ust_cuda_cuCtxSetSharedMemConfig_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuModuleLoad_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmodule * module, char * fname, char * fname_val);
void btx_push_message_lttng_ust_cuda_cuModuleLoad_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUmodule module_val);
void btx_push_message_lttng_ust_cuda_cuModuleLoadData_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmodule * module, void * image);
void btx_push_message_lttng_ust_cuda_cuModuleLoadData_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUmodule module_val);
void btx_push_message_lttng_ust_cuda_cuModuleLoadDataEx_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmodule * module, void * image, unsigned int numOptions, CUjit_option * options, void ** optionValues, size_t _options_vals_length, CUjit_option * options_vals, size_t _optionValues_vals_length, void * * optionValues_vals);
void btx_push_message_lttng_ust_cuda_cuModuleLoadDataEx_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUmodule module_val);
void btx_push_message_lttng_ust_cuda_cuModuleLoadFatBinary_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmodule * module, void * fatCubin);
void btx_push_message_lttng_ust_cuda_cuModuleLoadFatBinary_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUmodule module_val);
void btx_push_message_lttng_ust_cuda_cuModuleUnload_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmodule hmod);
void btx_push_message_lttng_ust_cuda_cuModuleUnload_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuModuleGetLoadingMode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmoduleLoadingMode * mode);
void btx_push_message_lttng_ust_cuda_cuModuleGetLoadingMode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUmoduleLoadingMode mode_val);
void btx_push_message_lttng_ust_cuda_cuModuleGetFunction_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUfunction * hfunc, CUmodule hmod, char * name, char * name_val);
void btx_push_message_lttng_ust_cuda_cuModuleGetFunction_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUfunction hfunc_val);
void btx_push_message_lttng_ust_cuda_cuModuleGetFunctionCount_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, unsigned int * count, CUmodule mod);
void btx_push_message_lttng_ust_cuda_cuModuleGetFunctionCount_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, unsigned int count_val);
void btx_push_message_lttng_ust_cuda_cuModuleEnumerateFunctions_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUfunction * functions, unsigned int numFunctions, CUmodule mod);
void btx_push_message_lttng_ust_cuda_cuModuleEnumerateFunctions_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _functions_vals_length, CUfunction * functions_vals);
void btx_push_message_lttng_ust_cuda_cuModuleGetGlobal_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr * dptr, size_t * bytes, CUmodule hmod, char * name, char * name_val);
void btx_push_message_lttng_ust_cuda_cuModuleGetGlobal_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUdeviceptr dptr_val, size_t bytes_val);
void btx_push_message_lttng_ust_cuda_cuLinkCreate_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, unsigned int numOptions, CUjit_option * options, void ** optionValues, CUlinkState * stateOut, size_t _options_vals_length, CUjit_option * options_vals, size_t _optionValues_vals_length, void * * optionValues_vals);
void btx_push_message_lttng_ust_cuda_cuLinkCreate_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUlinkState stateOut_val);
void btx_push_message_lttng_ust_cuda_cuLinkAddData_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUlinkState state, CUjitInputType type, void * data, size_t size, char * name, unsigned int numOptions, CUjit_option * options, void ** optionValues, char * name_val, size_t _options_vals_length, CUjit_option * options_vals, size_t _optionValues_vals_length, void * * optionValues_vals);
void btx_push_message_lttng_ust_cuda_cuLinkAddData_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuLinkAddFile_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUlinkState state, CUjitInputType type, char * path, unsigned int numOptions, CUjit_option * options, void ** optionValues, char * path_val, size_t _options_vals_length, CUjit_option * options_vals, size_t _optionValues_vals_length, void * * optionValues_vals);
void btx_push_message_lttng_ust_cuda_cuLinkAddFile_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuLinkComplete_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUlinkState state, void ** cubinOut, size_t * sizeOut);
void btx_push_message_lttng_ust_cuda_cuLinkComplete_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, void * cubinOut_val, size_t sizeOut_val);
void btx_push_message_lttng_ust_cuda_cuLinkDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUlinkState state);
void btx_push_message_lttng_ust_cuda_cuLinkDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuModuleGetTexRef_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUtexref * pTexRef, CUmodule hmod, char * name, char * name_val);
void btx_push_message_lttng_ust_cuda_cuModuleGetTexRef_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUtexref pTexRef_val);
void btx_push_message_lttng_ust_cuda_cuModuleGetSurfRef_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUsurfref * pSurfRef, CUmodule hmod, char * name, char * name_val);
void btx_push_message_lttng_ust_cuda_cuModuleGetSurfRef_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUsurfref pSurfRef_val);
void btx_push_message_lttng_ust_cuda_cuLibraryLoadData_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUlibrary * library, void * code, CUjit_option * jitOptions, void ** jitOptionsValues, unsigned int numJitOptions, CUlibraryOption * libraryOptions, void ** libraryOptionValues, unsigned int numLibraryOptions, size_t _jitOptions_vals_length, CUjit_option * jitOptions_vals, size_t _jitOptionsValues_vals_length, void * * jitOptionsValues_vals, size_t _libraryOptions_vals_length, CUlibraryOption * libraryOptions_vals, size_t _libraryOptionValues_vals_length, void * * libraryOptionValues_vals);
void btx_push_message_lttng_ust_cuda_cuLibraryLoadData_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUlibrary library_val);
void btx_push_message_lttng_ust_cuda_cuLibraryLoadFromFile_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUlibrary * library, char * fileName, CUjit_option * jitOptions, void ** jitOptionsValues, unsigned int numJitOptions, CUlibraryOption * libraryOptions, void ** libraryOptionValues, unsigned int numLibraryOptions, char * fileName_val, size_t _jitOptions_vals_length, CUjit_option * jitOptions_vals, size_t _jitOptionsValues_vals_length, void * * jitOptionsValues_vals, size_t _libraryOptions_vals_length, CUlibraryOption * libraryOptions_vals, size_t _libraryOptionValues_vals_length, void * * libraryOptionValues_vals);
void btx_push_message_lttng_ust_cuda_cuLibraryLoadFromFile_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUlibrary library_val);
void btx_push_message_lttng_ust_cuda_cuLibraryUnload_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUlibrary library);
void btx_push_message_lttng_ust_cuda_cuLibraryUnload_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuLibraryGetKernel_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUkernel * pKernel, CUlibrary library, char * name, char * name_val);
void btx_push_message_lttng_ust_cuda_cuLibraryGetKernel_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUkernel pKernel_val);
void btx_push_message_lttng_ust_cuda_cuLibraryGetKernelCount_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, unsigned int * count, CUlibrary lib);
void btx_push_message_lttng_ust_cuda_cuLibraryGetKernelCount_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, unsigned int count_val);
void btx_push_message_lttng_ust_cuda_cuLibraryEnumerateKernels_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUkernel * kernels, unsigned int numKernels, CUlibrary lib);
void btx_push_message_lttng_ust_cuda_cuLibraryEnumerateKernels_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _kernels_vals_length, CUkernel * kernels_vals);
void btx_push_message_lttng_ust_cuda_cuLibraryGetModule_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmodule * pMod, CUlibrary library);
void btx_push_message_lttng_ust_cuda_cuLibraryGetModule_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUmodule pMod_val);
void btx_push_message_lttng_ust_cuda_cuKernelGetFunction_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUfunction * pFunc, CUkernel kernel);
void btx_push_message_lttng_ust_cuda_cuKernelGetFunction_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUfunction pFunc_val);
void btx_push_message_lttng_ust_cuda_cuKernelGetLibrary_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUlibrary * pLib, CUkernel kernel);
void btx_push_message_lttng_ust_cuda_cuKernelGetLibrary_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUlibrary pLib_val);
void btx_push_message_lttng_ust_cuda_cuLibraryGetGlobal_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr * dptr, size_t * bytes, CUlibrary library, char * name, char * name_val);
void btx_push_message_lttng_ust_cuda_cuLibraryGetGlobal_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUdeviceptr dptr_val, size_t bytes_val);
void btx_push_message_lttng_ust_cuda_cuLibraryGetManaged_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr * dptr, size_t * bytes, CUlibrary library, char * name, char * name_val);
void btx_push_message_lttng_ust_cuda_cuLibraryGetManaged_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUdeviceptr dptr_val, size_t bytes_val);
void btx_push_message_lttng_ust_cuda_cuLibraryGetUnifiedFunction_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void ** fptr, CUlibrary library, char * symbol, char * symbol_val);
void btx_push_message_lttng_ust_cuda_cuLibraryGetUnifiedFunction_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, void * fptr_val);
void btx_push_message_lttng_ust_cuda_cuKernelGetAttribute_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * pi, CUfunction_attribute attrib, CUkernel kernel, CUdevice dev);
void btx_push_message_lttng_ust_cuda_cuKernelGetAttribute_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, int pi_val);
void btx_push_message_lttng_ust_cuda_cuKernelSetAttribute_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUfunction_attribute attrib, int val, CUkernel kernel, CUdevice dev);
void btx_push_message_lttng_ust_cuda_cuKernelSetAttribute_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuKernelSetCacheConfig_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUkernel kernel, CUfunc_cache config, CUdevice dev);
void btx_push_message_lttng_ust_cuda_cuKernelSetCacheConfig_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuKernelGetName_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, char ** name, CUkernel hfunc);
void btx_push_message_lttng_ust_cuda_cuKernelGetName_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, char * name_val_val);
void btx_push_message_lttng_ust_cuda_cuKernelGetParamInfo_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUkernel kernel, size_t paramIndex, size_t * paramOffset, size_t * paramSize);
void btx_push_message_lttng_ust_cuda_cuKernelGetParamInfo_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t paramOffset_val, size_t paramSize_val);
void btx_push_message_lttng_ust_cuda_cuMemGetInfo_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, size_t * free, size_t * total);
void btx_push_message_lttng_ust_cuda_cuMemGetInfo_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t free_val, size_t total_val);
void btx_push_message_lttng_ust_cuda_cuMemAlloc_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr * dptr, size_t bytesize);
void btx_push_message_lttng_ust_cuda_cuMemAlloc_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUdeviceptr dptr_val);
void btx_push_message_lttng_ust_cuda_cuMemAllocPitch_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr * dptr, size_t * pPitch, size_t WidthInBytes, size_t Height, unsigned int ElementSizeBytes);
void btx_push_message_lttng_ust_cuda_cuMemAllocPitch_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUdeviceptr dptr_val, size_t pPitch_val);
void btx_push_message_lttng_ust_cuda_cuMemFree_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dptr);
void btx_push_message_lttng_ust_cuda_cuMemFree_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemGetAddressRange_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr * pbase, size_t * psize, CUdeviceptr dptr);
void btx_push_message_lttng_ust_cuda_cuMemGetAddressRange_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUdeviceptr pbase_val, size_t psize_val);
void btx_push_message_lttng_ust_cuda_cuMemAllocHost_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void ** pp, size_t bytesize);
void btx_push_message_lttng_ust_cuda_cuMemAllocHost_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, void * pp_val);
void btx_push_message_lttng_ust_cuda_cuMemFreeHost_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * p);
void btx_push_message_lttng_ust_cuda_cuMemFreeHost_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemHostAlloc_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void ** pp, size_t bytesize, unsigned int Flags);
void btx_push_message_lttng_ust_cuda_cuMemHostAlloc_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, void * pp_val);
void btx_push_message_lttng_ust_cuda_cuMemHostGetDevicePointer_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr * pdptr, void * p, unsigned int Flags);
void btx_push_message_lttng_ust_cuda_cuMemHostGetDevicePointer_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUdeviceptr pdptr_val);
void btx_push_message_lttng_ust_cuda_cuMemHostGetFlags_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, unsigned int * pFlags, void * p);
void btx_push_message_lttng_ust_cuda_cuMemHostGetFlags_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, unsigned int pFlags_val);
void btx_push_message_lttng_ust_cuda_cuMemAllocManaged_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr * dptr, size_t bytesize, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuMemAllocManaged_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUdeviceptr dptr_val);
void btx_push_message_lttng_ust_cuda_cuDeviceRegisterAsyncNotification_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdevice device, CUasyncCallback callbackFunc, void * userData, CUasyncCallbackHandle * callback);
void btx_push_message_lttng_ust_cuda_cuDeviceRegisterAsyncNotification_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUasyncCallbackHandle callback_val);
void btx_push_message_lttng_ust_cuda_cuDeviceUnregisterAsyncNotification_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdevice device, CUasyncCallbackHandle callback);
void btx_push_message_lttng_ust_cuda_cuDeviceUnregisterAsyncNotification_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuDeviceGetByPCIBusId_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdevice * dev, char * pciBusId, char * pciBusId_val);
void btx_push_message_lttng_ust_cuda_cuDeviceGetByPCIBusId_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUdevice dev_val);
void btx_push_message_lttng_ust_cuda_cuDeviceGetPCIBusId_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, char * pciBusId, int len, CUdevice dev);
void btx_push_message_lttng_ust_cuda_cuDeviceGetPCIBusId_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, char * pciBusId_val);
void btx_push_message_lttng_ust_cuda_cuIpcGetEventHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUipcEventHandle * pHandle, CUevent event);
void btx_push_message_lttng_ust_cuda_cuIpcGetEventHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _pHandle_val_length, CUipcEventHandle * pHandle_val);
void btx_push_message_lttng_ust_cuda_cuIpcOpenEventHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUevent * phEvent, CUipcEventHandle handle);
void btx_push_message_lttng_ust_cuda_cuIpcOpenEventHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUevent phEvent_val);
void btx_push_message_lttng_ust_cuda_cuIpcGetMemHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUipcMemHandle * pHandle, CUdeviceptr dptr);
void btx_push_message_lttng_ust_cuda_cuIpcGetMemHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _pHandle_val_length, CUipcMemHandle * pHandle_val);
void btx_push_message_lttng_ust_cuda_cuIpcOpenMemHandle_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr * pdptr, CUipcMemHandle handle, unsigned int Flags);
void btx_push_message_lttng_ust_cuda_cuIpcOpenMemHandle_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUdeviceptr pdptr_val);
void btx_push_message_lttng_ust_cuda_cuIpcCloseMemHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dptr);
void btx_push_message_lttng_ust_cuda_cuIpcCloseMemHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemHostRegister_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * p, size_t bytesize, unsigned int Flags);
void btx_push_message_lttng_ust_cuda_cuMemHostRegister_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemHostUnregister_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * p);
void btx_push_message_lttng_ust_cuda_cuMemHostUnregister_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpy_ptds_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dst, CUdeviceptr src, size_t ByteCount);
void btx_push_message_lttng_ust_cuda_cuMemcpy_ptds_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyPeer_ptds_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, CUcontext dstContext, CUdeviceptr srcDevice, CUcontext srcContext, size_t ByteCount);
void btx_push_message_lttng_ust_cuda_cuMemcpyPeer_ptds_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyHtoD_v2_ptds_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, void * srcHost, size_t ByteCount);
void btx_push_message_lttng_ust_cuda_cuMemcpyHtoD_v2_ptds_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyDtoH_v2_ptds_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dstHost, CUdeviceptr srcDevice, size_t ByteCount);
void btx_push_message_lttng_ust_cuda_cuMemcpyDtoH_v2_ptds_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyDtoD_v2_ptds_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, CUdeviceptr srcDevice, size_t ByteCount);
void btx_push_message_lttng_ust_cuda_cuMemcpyDtoD_v2_ptds_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyDtoA_v2_ptds_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUarray dstArray, size_t dstOffset, CUdeviceptr srcDevice, size_t ByteCount);
void btx_push_message_lttng_ust_cuda_cuMemcpyDtoA_v2_ptds_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyAtoD_v2_ptds_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, CUarray srcArray, size_t srcOffset, size_t ByteCount);
void btx_push_message_lttng_ust_cuda_cuMemcpyAtoD_v2_ptds_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyHtoA_v2_ptds_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUarray dstArray, size_t dstOffset, void * srcHost, size_t ByteCount);
void btx_push_message_lttng_ust_cuda_cuMemcpyHtoA_v2_ptds_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyAtoH_v2_ptds_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dstHost, CUarray srcArray, size_t srcOffset, size_t ByteCount);
void btx_push_message_lttng_ust_cuda_cuMemcpyAtoH_v2_ptds_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyAtoA_v2_ptds_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUarray dstArray, size_t dstOffset, CUarray srcArray, size_t srcOffset, size_t ByteCount);
void btx_push_message_lttng_ust_cuda_cuMemcpyAtoA_v2_ptds_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpy2D_v2_ptds_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUDA_MEMCPY2D * pCopy, size_t _pCopy_val_length, CUDA_MEMCPY2D * pCopy_val);
void btx_push_message_lttng_ust_cuda_cuMemcpy2D_v2_ptds_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpy2DUnaligned_v2_ptds_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUDA_MEMCPY2D * pCopy, size_t _pCopy_val_length, CUDA_MEMCPY2D * pCopy_val);
void btx_push_message_lttng_ust_cuda_cuMemcpy2DUnaligned_v2_ptds_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpy3D_v2_ptds_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUDA_MEMCPY3D * pCopy, size_t _pCopy_val_length, CUDA_MEMCPY3D * pCopy_val);
void btx_push_message_lttng_ust_cuda_cuMemcpy3D_v2_ptds_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpy3DPeer_ptds_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUDA_MEMCPY3D_PEER * pCopy, size_t _pCopy_val_length, CUDA_MEMCPY3D_PEER * pCopy_val);
void btx_push_message_lttng_ust_cuda_cuMemcpy3DPeer_ptds_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyAsync_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dst, CUdeviceptr src, size_t ByteCount, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemcpyAsync_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyPeerAsync_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, CUcontext dstContext, CUdeviceptr srcDevice, CUcontext srcContext, size_t ByteCount, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemcpyPeerAsync_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyHtoDAsync_v2_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, void * srcHost, size_t ByteCount, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemcpyHtoDAsync_v2_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyDtoHAsync_v2_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dstHost, CUdeviceptr srcDevice, size_t ByteCount, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemcpyDtoHAsync_v2_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyDtoDAsync_v2_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, CUdeviceptr srcDevice, size_t ByteCount, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemcpyDtoDAsync_v2_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyHtoAAsync_v2_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUarray dstArray, size_t dstOffset, void * srcHost, size_t ByteCount, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemcpyHtoAAsync_v2_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyAtoHAsync_v2_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dstHost, CUarray srcArray, size_t srcOffset, size_t ByteCount, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemcpyAtoHAsync_v2_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpy2DAsync_v2_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUDA_MEMCPY2D * pCopy, CUstream hStream, size_t _pCopy_val_length, CUDA_MEMCPY2D * pCopy_val);
void btx_push_message_lttng_ust_cuda_cuMemcpy2DAsync_v2_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpy3DAsync_v2_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUDA_MEMCPY3D * pCopy, CUstream hStream, size_t _pCopy_val_length, CUDA_MEMCPY3D * pCopy_val);
void btx_push_message_lttng_ust_cuda_cuMemcpy3DAsync_v2_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpy3DPeerAsync_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUDA_MEMCPY3D_PEER * pCopy, CUstream hStream, size_t _pCopy_val_length, CUDA_MEMCPY3D_PEER * pCopy_val);
void btx_push_message_lttng_ust_cuda_cuMemcpy3DPeerAsync_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyBatchAsync_v2_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr * dsts, CUdeviceptr * srcs, size_t * sizes, size_t count, CUmemcpyAttributes * attrs, size_t * attrsIdxs, size_t numAttrs, CUstream hStream, size_t _dsts_vals_length, CUdeviceptr * dsts_vals, size_t _srcs_vals_length, CUdeviceptr * srcs_vals, size_t _sizes_vals_length, size_t * sizes_vals, size_t _attrs_vals_length, CUmemcpyAttributes * attrs_vals, size_t _attrsIdxs_vals_length, size_t * attrsIdxs_vals);
void btx_push_message_lttng_ust_cuda_cuMemcpyBatchAsync_v2_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpy3DBatchAsync_v2_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, size_t numOps, CUDA_MEMCPY3D_BATCH_OP * opList, unsigned long long int flags, CUstream hStream, size_t _opList_vals_length, CUDA_MEMCPY3D_BATCH_OP * opList_vals);
void btx_push_message_lttng_ust_cuda_cuMemcpy3DBatchAsync_v2_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemsetD8_v2_ptds_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, unsigned char uc, size_t N);
void btx_push_message_lttng_ust_cuda_cuMemsetD8_v2_ptds_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemsetD16_v2_ptds_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, unsigned short int us, size_t N);
void btx_push_message_lttng_ust_cuda_cuMemsetD16_v2_ptds_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemsetD32_v2_ptds_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, unsigned int ui, size_t N);
void btx_push_message_lttng_ust_cuda_cuMemsetD32_v2_ptds_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemsetD2D8_v2_ptds_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, size_t dstPitch, unsigned char uc, size_t Width, size_t Height);
void btx_push_message_lttng_ust_cuda_cuMemsetD2D8_v2_ptds_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemsetD2D16_v2_ptds_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, size_t dstPitch, unsigned short int us, size_t Width, size_t Height);
void btx_push_message_lttng_ust_cuda_cuMemsetD2D16_v2_ptds_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemsetD2D32_v2_ptds_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, size_t dstPitch, unsigned int ui, size_t Width, size_t Height);
void btx_push_message_lttng_ust_cuda_cuMemsetD2D32_v2_ptds_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemsetD8Async_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, unsigned char uc, size_t N, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemsetD8Async_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemsetD16Async_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, unsigned short int us, size_t N, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemsetD16Async_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemsetD32Async_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, unsigned int ui, size_t N, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemsetD32Async_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemsetD2D8Async_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, size_t dstPitch, unsigned char uc, size_t Width, size_t Height, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemsetD2D8Async_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemsetD2D16Async_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, size_t dstPitch, unsigned short int us, size_t Width, size_t Height, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemsetD2D16Async_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemsetD2D32Async_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, size_t dstPitch, unsigned int ui, size_t Width, size_t Height, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemsetD2D32Async_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuArrayCreate_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUarray * pHandle, CUDA_ARRAY_DESCRIPTOR * pAllocateArray, size_t _pAllocateArray_val_length, CUDA_ARRAY_DESCRIPTOR * pAllocateArray_val);
void btx_push_message_lttng_ust_cuda_cuArrayCreate_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUarray pHandle_val);
void btx_push_message_lttng_ust_cuda_cuArrayGetDescriptor_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUDA_ARRAY_DESCRIPTOR * pArrayDescriptor, CUarray hArray);
void btx_push_message_lttng_ust_cuda_cuArrayGetDescriptor_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _pArrayDescriptor_val_length, CUDA_ARRAY_DESCRIPTOR * pArrayDescriptor_val);
void btx_push_message_lttng_ust_cuda_cuArrayGetSparseProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUDA_ARRAY_SPARSE_PROPERTIES * sparseProperties, CUarray array);
void btx_push_message_lttng_ust_cuda_cuArrayGetSparseProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _sparseProperties_val_length, CUDA_ARRAY_SPARSE_PROPERTIES * sparseProperties_val);
void btx_push_message_lttng_ust_cuda_cuMipmappedArrayGetSparseProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUDA_ARRAY_SPARSE_PROPERTIES * sparseProperties, CUmipmappedArray mipmap);
void btx_push_message_lttng_ust_cuda_cuMipmappedArrayGetSparseProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _sparseProperties_val_length, CUDA_ARRAY_SPARSE_PROPERTIES * sparseProperties_val);
void btx_push_message_lttng_ust_cuda_cuArrayGetMemoryRequirements_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUDA_ARRAY_MEMORY_REQUIREMENTS * memoryRequirements, CUarray array, CUdevice device);
void btx_push_message_lttng_ust_cuda_cuArrayGetMemoryRequirements_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _memoryRequirements_val_length, CUDA_ARRAY_MEMORY_REQUIREMENTS * memoryRequirements_val);
void btx_push_message_lttng_ust_cuda_cuMipmappedArrayGetMemoryRequirements_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUDA_ARRAY_MEMORY_REQUIREMENTS * memoryRequirements, CUmipmappedArray mipmap, CUdevice device);
void btx_push_message_lttng_ust_cuda_cuMipmappedArrayGetMemoryRequirements_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _memoryRequirements_val_length, CUDA_ARRAY_MEMORY_REQUIREMENTS * memoryRequirements_val);
void btx_push_message_lttng_ust_cuda_cuArrayGetPlane_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUarray * pPlaneArray, CUarray hArray, unsigned int planeIdx);
void btx_push_message_lttng_ust_cuda_cuArrayGetPlane_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUarray pPlaneArray_val);
void btx_push_message_lttng_ust_cuda_cuArrayDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUarray hArray);
void btx_push_message_lttng_ust_cuda_cuArrayDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuArray3DCreate_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUarray * pHandle, CUDA_ARRAY3D_DESCRIPTOR * pAllocateArray, size_t _pAllocateArray_val_length, CUDA_ARRAY3D_DESCRIPTOR * pAllocateArray_val);
void btx_push_message_lttng_ust_cuda_cuArray3DCreate_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUarray pHandle_val);
void btx_push_message_lttng_ust_cuda_cuArray3DGetDescriptor_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUDA_ARRAY3D_DESCRIPTOR * pArrayDescriptor, CUarray hArray);
void btx_push_message_lttng_ust_cuda_cuArray3DGetDescriptor_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _pArrayDescriptor_val_length, CUDA_ARRAY3D_DESCRIPTOR * pArrayDescriptor_val);
void btx_push_message_lttng_ust_cuda_cuMipmappedArrayCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmipmappedArray * pHandle, CUDA_ARRAY3D_DESCRIPTOR * pMipmappedArrayDesc, unsigned int numMipmapLevels, size_t _pMipmappedArrayDesc_val_length, CUDA_ARRAY3D_DESCRIPTOR * pMipmappedArrayDesc_val);
void btx_push_message_lttng_ust_cuda_cuMipmappedArrayCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUmipmappedArray pHandle_val);
void btx_push_message_lttng_ust_cuda_cuMipmappedArrayGetLevel_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUarray * pLevelArray, CUmipmappedArray hMipmappedArray, unsigned int level);
void btx_push_message_lttng_ust_cuda_cuMipmappedArrayGetLevel_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUarray pLevelArray_val);
void btx_push_message_lttng_ust_cuda_cuMipmappedArrayDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmipmappedArray hMipmappedArray);
void btx_push_message_lttng_ust_cuda_cuMipmappedArrayDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemGetHandleForAddressRange_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * handle, CUdeviceptr dptr, size_t size, CUmemRangeHandleType handleType, unsigned long long int flags);
void btx_push_message_lttng_ust_cuda_cuMemGetHandleForAddressRange_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _handle_val_length, void * handle_val);
void btx_push_message_lttng_ust_cuda_cuMemBatchDecompressAsync_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmemDecompressParams * paramsArray, size_t count, unsigned int flags, size_t * errorIndex, CUstream stream, size_t _paramsArray_vals_length, CUmemDecompressParams * paramsArray_vals);
void btx_push_message_lttng_ust_cuda_cuMemBatchDecompressAsync_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t errorIndex_val);
void btx_push_message_lttng_ust_cuda_cuMemAddressReserve_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr * ptr, size_t size, size_t alignment, CUdeviceptr addr, unsigned long long int flags);
void btx_push_message_lttng_ust_cuda_cuMemAddressReserve_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUdeviceptr ptr_val);
void btx_push_message_lttng_ust_cuda_cuMemAddressFree_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr ptr, size_t size);
void btx_push_message_lttng_ust_cuda_cuMemAddressFree_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmemGenericAllocationHandle * handle, size_t size, CUmemAllocationProp * prop, unsigned long long int flags, size_t _prop_val_length, CUmemAllocationProp * prop_val);
void btx_push_message_lttng_ust_cuda_cuMemCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUmemGenericAllocationHandle handle_val);
void btx_push_message_lttng_ust_cuda_cuMemRelease_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmemGenericAllocationHandle handle);
void btx_push_message_lttng_ust_cuda_cuMemRelease_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemMap_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr ptr, size_t size, size_t offset, CUmemGenericAllocationHandle handle, unsigned long long int flags);
void btx_push_message_lttng_ust_cuda_cuMemMap_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemMapArrayAsync_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUarrayMapInfo * mapInfoList, unsigned int count, CUstream hStream, size_t _mapInfoList_vals_length, CUarrayMapInfo * mapInfoList_vals);
void btx_push_message_lttng_ust_cuda_cuMemMapArrayAsync_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemUnmap_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr ptr, size_t size);
void btx_push_message_lttng_ust_cuda_cuMemUnmap_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemSetAccess_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr ptr, size_t size, CUmemAccessDesc * desc, size_t count, size_t _desc_val_length, CUmemAccessDesc * desc_val);
void btx_push_message_lttng_ust_cuda_cuMemSetAccess_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemGetAccess_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, unsigned long long int * flags, CUmemLocation * location, CUdeviceptr ptr, size_t _location_val_length, CUmemLocation * location_val);
void btx_push_message_lttng_ust_cuda_cuMemGetAccess_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, unsigned long long int flags_val);
void btx_push_message_lttng_ust_cuda_cuMemExportToShareableHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * shareableHandle, CUmemGenericAllocationHandle handle, CUmemAllocationHandleType handleType, unsigned long long int flags);
void btx_push_message_lttng_ust_cuda_cuMemExportToShareableHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _shareableHandle_val_length, void * shareableHandle_val);
void btx_push_message_lttng_ust_cuda_cuMemImportFromShareableHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmemGenericAllocationHandle * handle, void * osHandle, CUmemAllocationHandleType shHandleType, size_t _osHandle_val_length, void * osHandle_val);
void btx_push_message_lttng_ust_cuda_cuMemImportFromShareableHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUmemGenericAllocationHandle handle_val);
void btx_push_message_lttng_ust_cuda_cuMemGetAllocationGranularity_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, size_t * granularity, CUmemAllocationProp * prop, CUmemAllocationGranularity_flags option, size_t _prop_val_length, CUmemAllocationProp * prop_val);
void btx_push_message_lttng_ust_cuda_cuMemGetAllocationGranularity_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t granularity_val);
void btx_push_message_lttng_ust_cuda_cuMemGetAllocationPropertiesFromHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmemAllocationProp * prop, CUmemGenericAllocationHandle handle);
void btx_push_message_lttng_ust_cuda_cuMemGetAllocationPropertiesFromHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _prop_val_length, CUmemAllocationProp * prop_val);
void btx_push_message_lttng_ust_cuda_cuMemRetainAllocationHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmemGenericAllocationHandle * handle, void * addr);
void btx_push_message_lttng_ust_cuda_cuMemRetainAllocationHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUmemGenericAllocationHandle handle_val);
void btx_push_message_lttng_ust_cuda_cuMemFreeAsync_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dptr, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemFreeAsync_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemAllocAsync_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr * dptr, size_t bytesize, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemAllocAsync_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUdeviceptr dptr_val);
void btx_push_message_lttng_ust_cuda_cuMemPoolTrimTo_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmemoryPool pool, size_t minBytesToKeep);
void btx_push_message_lttng_ust_cuda_cuMemPoolTrimTo_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemPoolSetAttribute_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmemoryPool pool, CUmemPool_attribute attr, void * value, size_t _value_val_length, void * value_val);
void btx_push_message_lttng_ust_cuda_cuMemPoolSetAttribute_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemPoolGetAttribute_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmemoryPool pool, CUmemPool_attribute attr, void * value);
void btx_push_message_lttng_ust_cuda_cuMemPoolGetAttribute_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _value_val_length, void * value_val);
void btx_push_message_lttng_ust_cuda_cuMemPoolSetAccess_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmemoryPool pool, CUmemAccessDesc * map, size_t count, size_t _map_vals_length, CUmemAccessDesc * map_vals);
void btx_push_message_lttng_ust_cuda_cuMemPoolSetAccess_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemPoolGetAccess_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmemAccess_flags * flags, CUmemoryPool memPool, CUmemLocation * location, size_t _location_val_length, CUmemLocation * location_val);
void btx_push_message_lttng_ust_cuda_cuMemPoolGetAccess_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUmemAccess_flags flags_val);
void btx_push_message_lttng_ust_cuda_cuMemPoolCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmemoryPool * pool, CUmemPoolProps * poolProps, size_t _poolProps_val_length, CUmemPoolProps * poolProps_val);
void btx_push_message_lttng_ust_cuda_cuMemPoolCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUmemoryPool pool_val);
void btx_push_message_lttng_ust_cuda_cuMemPoolDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmemoryPool pool);
void btx_push_message_lttng_ust_cuda_cuMemPoolDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemGetDefaultMemPool_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmemoryPool * pool_out, CUmemLocation * location, CUmemAllocationType type, size_t _location_val_length, CUmemLocation * location_val);
void btx_push_message_lttng_ust_cuda_cuMemGetDefaultMemPool_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUmemoryPool pool_out_val);
void btx_push_message_lttng_ust_cuda_cuMemGetMemPool_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmemoryPool * pool, CUmemLocation * location, CUmemAllocationType type, size_t _location_val_length, CUmemLocation * location_val);
void btx_push_message_lttng_ust_cuda_cuMemGetMemPool_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUmemoryPool pool_val);
void btx_push_message_lttng_ust_cuda_cuMemSetMemPool_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmemLocation * location, CUmemAllocationType type, CUmemoryPool pool, size_t _location_val_length, CUmemLocation * location_val);
void btx_push_message_lttng_ust_cuda_cuMemSetMemPool_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemAllocFromPoolAsync_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr * dptr, size_t bytesize, CUmemoryPool pool, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemAllocFromPoolAsync_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUdeviceptr dptr_val);
void btx_push_message_lttng_ust_cuda_cuMemPoolExportToShareableHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * handle_out, CUmemoryPool pool, CUmemAllocationHandleType handleType, unsigned long long int flags);
void btx_push_message_lttng_ust_cuda_cuMemPoolExportToShareableHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _handle_out_val_length, void * handle_out_val);
void btx_push_message_lttng_ust_cuda_cuMemPoolImportFromShareableHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmemoryPool * pool_out, void * handle, CUmemAllocationHandleType handleType, unsigned long long int flags, size_t _handle_val_length, void * handle_val);
void btx_push_message_lttng_ust_cuda_cuMemPoolImportFromShareableHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUmemoryPool pool_out_val);
void btx_push_message_lttng_ust_cuda_cuMemPoolExportPointer_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmemPoolPtrExportData * shareData_out, CUdeviceptr ptr);
void btx_push_message_lttng_ust_cuda_cuMemPoolExportPointer_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _shareData_out_val_length, CUmemPoolPtrExportData * shareData_out_val);
void btx_push_message_lttng_ust_cuda_cuMemPoolImportPointer_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr * ptr_out, CUmemoryPool pool, CUmemPoolPtrExportData * shareData, size_t _shareData_val_length, CUmemPoolPtrExportData * shareData_val);
void btx_push_message_lttng_ust_cuda_cuMemPoolImportPointer_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUdeviceptr ptr_out_val);
void btx_push_message_lttng_ust_cuda_cuMulticastCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmemGenericAllocationHandle * mcHandle, CUmulticastObjectProp * prop, size_t _prop_val_length, CUmulticastObjectProp * prop_val);
void btx_push_message_lttng_ust_cuda_cuMulticastCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUmemGenericAllocationHandle mcHandle_val);
void btx_push_message_lttng_ust_cuda_cuMulticastAddDevice_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmemGenericAllocationHandle mcHandle, CUdevice dev);
void btx_push_message_lttng_ust_cuda_cuMulticastAddDevice_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMulticastBindMem_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmemGenericAllocationHandle mcHandle, size_t mcOffset, CUmemGenericAllocationHandle memHandle, size_t memOffset, size_t size, unsigned long long int flags);
void btx_push_message_lttng_ust_cuda_cuMulticastBindMem_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMulticastBindAddr_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmemGenericAllocationHandle mcHandle, size_t mcOffset, CUdeviceptr memptr, size_t size, unsigned long long int flags);
void btx_push_message_lttng_ust_cuda_cuMulticastBindAddr_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMulticastUnbind_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmemGenericAllocationHandle mcHandle, CUdevice dev, size_t mcOffset, size_t size);
void btx_push_message_lttng_ust_cuda_cuMulticastUnbind_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMulticastGetGranularity_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, size_t * granularity, CUmulticastObjectProp * prop, CUmulticastGranularity_flags option, size_t _prop_val_length, CUmulticastObjectProp * prop_val);
void btx_push_message_lttng_ust_cuda_cuMulticastGetGranularity_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t granularity_val);
void btx_push_message_lttng_ust_cuda_cuPointerGetAttribute_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * data, CUpointer_attribute attribute, CUdeviceptr ptr);
void btx_push_message_lttng_ust_cuda_cuPointerGetAttribute_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _data_val_length, void * data_val);
void btx_push_message_lttng_ust_cuda_cuMemPrefetchAsync_v2_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr devPtr, size_t count, CUmemLocation location, unsigned int flags, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemPrefetchAsync_v2_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemAdvise_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr devPtr, size_t count, CUmem_advise advice, CUmemLocation location);
void btx_push_message_lttng_ust_cuda_cuMemAdvise_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemPrefetchBatchAsync_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr * dptrs, size_t * sizes, size_t count, CUmemLocation * prefetchLocs, size_t * prefetchLocIdxs, size_t numPrefetchLocs, unsigned long long int flags, CUstream hStream, size_t _dptrs_vals_length, CUdeviceptr * dptrs_vals, size_t _sizes_vals_length, size_t * sizes_vals, size_t _prefetchLocs_vals_length, CUmemLocation * prefetchLocs_vals, size_t _prefetchLocIdxs_vals_length, size_t * prefetchLocIdxs_vals);
void btx_push_message_lttng_ust_cuda_cuMemPrefetchBatchAsync_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemDiscardBatchAsync_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr * dptrs, size_t * sizes, size_t count, unsigned long long int flags, CUstream hStream, size_t _dptrs_vals_length, CUdeviceptr * dptrs_vals, size_t _sizes_vals_length, size_t * sizes_vals);
void btx_push_message_lttng_ust_cuda_cuMemDiscardBatchAsync_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemDiscardAndPrefetchBatchAsync_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr * dptrs, size_t * sizes, size_t count, CUmemLocation * prefetchLocs, size_t * prefetchLocIdxs, size_t numPrefetchLocs, unsigned long long int flags, CUstream hStream, size_t _dptrs_vals_length, CUdeviceptr * dptrs_vals, size_t _sizes_vals_length, size_t * sizes_vals, size_t _prefetchLocs_vals_length, CUmemLocation * prefetchLocs_vals, size_t _prefetchLocIdxs_vals_length, size_t * prefetchLocIdxs_vals);
void btx_push_message_lttng_ust_cuda_cuMemDiscardAndPrefetchBatchAsync_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemRangeGetAttribute_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * data, size_t dataSize, CUmem_range_attribute attribute, CUdeviceptr devPtr, size_t count);
void btx_push_message_lttng_ust_cuda_cuMemRangeGetAttribute_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _data_vals_length, void * data_vals);
void btx_push_message_lttng_ust_cuda_cuMemRangeGetAttributes_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void ** data, size_t * dataSizes, CUmem_range_attribute * attributes, size_t numAttributes, CUdeviceptr devPtr, size_t count, size_t _attributes_vals_length, CUmem_range_attribute * attributes_vals, size_t _dataSizes_vals_length, size_t * dataSizes_vals);
void btx_push_message_lttng_ust_cuda_cuMemRangeGetAttributes_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuPointerSetAttribute_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * value, CUpointer_attribute attribute, CUdeviceptr ptr, size_t _value_val_length, void * value_val);
void btx_push_message_lttng_ust_cuda_cuPointerSetAttribute_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuPointerGetAttributes_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, unsigned int numAttributes, CUpointer_attribute * attributes, void ** data, CUdeviceptr ptr, size_t _attributes_vals_length, CUpointer_attribute * attributes_vals);
void btx_push_message_lttng_ust_cuda_cuPointerGetAttributes_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _data_vals_length, void * * data_vals);
void btx_push_message_lttng_ust_cuda_cuStreamCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream * phStream, unsigned int Flags);
void btx_push_message_lttng_ust_cuda_cuStreamCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUstream phStream_val);
void btx_push_message_lttng_ust_cuda_cuStreamCreateWithPriority_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream * phStream, unsigned int flags, int priority);
void btx_push_message_lttng_ust_cuda_cuStreamCreateWithPriority_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUstream phStream_val);
void btx_push_message_lttng_ust_cuda_cuStreamGetPriority_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, int * priority);
void btx_push_message_lttng_ust_cuda_cuStreamGetPriority_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, int priority_val);
void btx_push_message_lttng_ust_cuda_cuStreamGetDevice_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUdevice * device);
void btx_push_message_lttng_ust_cuda_cuStreamGetDevice_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUdevice device_val);
void btx_push_message_lttng_ust_cuda_cuStreamGetFlags_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, unsigned int * flags);
void btx_push_message_lttng_ust_cuda_cuStreamGetFlags_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, unsigned int flags_val);
void btx_push_message_lttng_ust_cuda_cuStreamGetId_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, unsigned long long int * streamId);
void btx_push_message_lttng_ust_cuda_cuStreamGetId_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, unsigned long long int streamId_val);
void btx_push_message_lttng_ust_cuda_cuStreamGetCtx_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUcontext * pctx);
void btx_push_message_lttng_ust_cuda_cuStreamGetCtx_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUcontext pctx_val);
void btx_push_message_lttng_ust_cuda_cuStreamGetCtx_v2_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUcontext * pCtx, CUgreenCtx * pGreenCtx);
void btx_push_message_lttng_ust_cuda_cuStreamGetCtx_v2_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUcontext pCtx_val, CUgreenCtx pGreenCtx_val);
void btx_push_message_lttng_ust_cuda_cuStreamWaitEvent_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUevent hEvent, unsigned int Flags);
void btx_push_message_lttng_ust_cuda_cuStreamWaitEvent_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamAddCallback_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUstreamCallback callback, void * userData, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuStreamAddCallback_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamBeginCapture_v2_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUstreamCaptureMode mode);
void btx_push_message_lttng_ust_cuda_cuStreamBeginCapture_v2_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamBeginCaptureToGraph_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUgraph hGraph, CUgraphNode * dependencies, CUgraphEdgeData * dependencyData, size_t numDependencies, CUstreamCaptureMode mode, size_t _dependencies_vals_length, CUgraphNode * dependencies_vals, size_t _dependencyData_vals_length, CUgraphEdgeData * dependencyData_vals);
void btx_push_message_lttng_ust_cuda_cuStreamBeginCaptureToGraph_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuThreadExchangeStreamCaptureMode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstreamCaptureMode * mode, CUstreamCaptureMode mode_val);
void btx_push_message_lttng_ust_cuda_cuThreadExchangeStreamCaptureMode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUstreamCaptureMode mode_val);
void btx_push_message_lttng_ust_cuda_cuStreamEndCapture_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUgraph * phGraph);
void btx_push_message_lttng_ust_cuda_cuStreamEndCapture_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUgraph phGraph_val);
void btx_push_message_lttng_ust_cuda_cuStreamIsCapturing_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUstreamCaptureStatus * captureStatus);
void btx_push_message_lttng_ust_cuda_cuStreamIsCapturing_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUstreamCaptureStatus captureStatus_val);
void btx_push_message_lttng_ust_cuda_cuStreamGetCaptureInfo_v3_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUstreamCaptureStatus * captureStatus_out, cuuint64_t * id_out, CUgraph * graph_out, CUgraphNode ** dependencies_out, CUgraphEdgeData ** edgeData_out, size_t * numDependencies_out);
void btx_push_message_lttng_ust_cuda_cuStreamGetCaptureInfo_v3_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUstreamCaptureStatus captureStatus_out_val, cuuint64_t id_out_val, CUgraph graph_out_val, size_t numDependencies_out_val, size_t _dependencies_out_val_vals_length, CUgraphNode * dependencies_out_val_vals, size_t _edgeData_out_val_vals_length, CUgraphEdgeData * edgeData_out_val_vals);
void btx_push_message_lttng_ust_cuda_cuStreamUpdateCaptureDependencies_v2_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUgraphNode * dependencies, CUgraphEdgeData * dependencyData, size_t numDependencies, unsigned int flags, size_t _dependencies_vals_length, CUgraphNode * dependencies_vals, size_t _dependencyData_vals_length, CUgraphEdgeData * dependencyData_vals);
void btx_push_message_lttng_ust_cuda_cuStreamUpdateCaptureDependencies_v2_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamAttachMemAsync_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUdeviceptr dptr, size_t length, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuStreamAttachMemAsync_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamQuery_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuStreamQuery_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamSynchronize_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuStreamSynchronize_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamDestroy_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuStreamDestroy_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamCopyAttributes_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream dst, CUstream src);
void btx_push_message_lttng_ust_cuda_cuStreamCopyAttributes_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamGetAttribute_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUstreamAttrID attr, CUstreamAttrValue * value_out);
void btx_push_message_lttng_ust_cuda_cuStreamGetAttribute_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _value_out_val_length, CUstreamAttrValue * value_out_val);
void btx_push_message_lttng_ust_cuda_cuStreamSetAttribute_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUstreamAttrID attr, CUstreamAttrValue * value, size_t _value_val_length, CUstreamAttrValue * value_val);
void btx_push_message_lttng_ust_cuda_cuStreamSetAttribute_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuEventCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUevent * phEvent, unsigned int Flags);
void btx_push_message_lttng_ust_cuda_cuEventCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUevent phEvent_val);
void btx_push_message_lttng_ust_cuda_cuEventRecord_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUevent hEvent, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuEventRecord_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuEventRecordWithFlags_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUevent hEvent, CUstream hStream, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuEventRecordWithFlags_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuEventQuery_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUevent hEvent);
void btx_push_message_lttng_ust_cuda_cuEventQuery_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuEventSynchronize_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUevent hEvent);
void btx_push_message_lttng_ust_cuda_cuEventSynchronize_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuEventDestroy_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUevent hEvent);
void btx_push_message_lttng_ust_cuda_cuEventDestroy_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuEventElapsedTime_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, float * pMilliseconds, CUevent hStart, CUevent hEnd);
void btx_push_message_lttng_ust_cuda_cuEventElapsedTime_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, float pMilliseconds_val);
void btx_push_message_lttng_ust_cuda_cuImportExternalMemory_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUexternalMemory * extMem_out, CUDA_EXTERNAL_MEMORY_HANDLE_DESC * memHandleDesc, size_t _memHandleDesc_val_length, CUDA_EXTERNAL_MEMORY_HANDLE_DESC * memHandleDesc_val);
void btx_push_message_lttng_ust_cuda_cuImportExternalMemory_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUexternalMemory extMem_out_val);
void btx_push_message_lttng_ust_cuda_cuExternalMemoryGetMappedBuffer_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr * devPtr, CUexternalMemory extMem, CUDA_EXTERNAL_MEMORY_BUFFER_DESC * bufferDesc, size_t _bufferDesc_val_length, CUDA_EXTERNAL_MEMORY_BUFFER_DESC * bufferDesc_val);
void btx_push_message_lttng_ust_cuda_cuExternalMemoryGetMappedBuffer_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUdeviceptr devPtr_val);
void btx_push_message_lttng_ust_cuda_cuExternalMemoryGetMappedMipmappedArray_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmipmappedArray * mipmap, CUexternalMemory extMem, CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC * mipmapDesc, size_t _mipmapDesc_val_length, CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC * mipmapDesc_val);
void btx_push_message_lttng_ust_cuda_cuExternalMemoryGetMappedMipmappedArray_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUmipmappedArray mipmap_val);
void btx_push_message_lttng_ust_cuda_cuDestroyExternalMemory_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUexternalMemory extMem);
void btx_push_message_lttng_ust_cuda_cuDestroyExternalMemory_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuImportExternalSemaphore_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUexternalSemaphore * extSem_out, CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC * semHandleDesc, size_t _semHandleDesc_val_length, CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC * semHandleDesc_val);
void btx_push_message_lttng_ust_cuda_cuImportExternalSemaphore_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUexternalSemaphore extSem_out_val);
void btx_push_message_lttng_ust_cuda_cuSignalExternalSemaphoresAsync_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUexternalSemaphore * extSemArray, CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS * paramsArray, unsigned int numExtSems, CUstream stream, size_t _extSemArray_vals_length, CUexternalSemaphore * extSemArray_vals, size_t _paramsArray_vals_length, CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS * paramsArray_vals);
void btx_push_message_lttng_ust_cuda_cuSignalExternalSemaphoresAsync_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuWaitExternalSemaphoresAsync_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUexternalSemaphore * extSemArray, CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS * paramsArray, unsigned int numExtSems, CUstream stream, size_t _extSemArray_vals_length, CUexternalSemaphore * extSemArray_vals, size_t _paramsArray_vals_length, CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS * paramsArray_vals);
void btx_push_message_lttng_ust_cuda_cuWaitExternalSemaphoresAsync_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuDestroyExternalSemaphore_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUexternalSemaphore extSem);
void btx_push_message_lttng_ust_cuda_cuDestroyExternalSemaphore_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamWaitValue32_v2_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuStreamWaitValue32_v2_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamWaitValue64_v2_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuStreamWaitValue64_v2_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamWriteValue32_v2_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuStreamWriteValue32_v2_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamWriteValue64_v2_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuStreamWriteValue64_v2_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamBatchMemOp_v2_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream stream, unsigned int count, CUstreamBatchMemOpParams * paramArray, unsigned int flags, size_t _paramArray_vals_length, CUstreamBatchMemOpParams * paramArray_vals);
void btx_push_message_lttng_ust_cuda_cuStreamBatchMemOp_v2_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuFuncGetAttribute_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * pi, CUfunction_attribute attrib, CUfunction hfunc);
void btx_push_message_lttng_ust_cuda_cuFuncGetAttribute_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, int pi_val);
void btx_push_message_lttng_ust_cuda_cuFuncSetAttribute_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUfunction hfunc, CUfunction_attribute attrib, int value);
void btx_push_message_lttng_ust_cuda_cuFuncSetAttribute_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuFuncSetCacheConfig_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUfunction hfunc, CUfunc_cache config);
void btx_push_message_lttng_ust_cuda_cuFuncSetCacheConfig_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuFuncGetModule_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmodule * hmod, CUfunction hfunc);
void btx_push_message_lttng_ust_cuda_cuFuncGetModule_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUmodule hmod_val);
void btx_push_message_lttng_ust_cuda_cuFuncGetName_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, char ** name, CUfunction hfunc);
void btx_push_message_lttng_ust_cuda_cuFuncGetName_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, char * name_val_val);
void btx_push_message_lttng_ust_cuda_cuFuncGetParamInfo_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUfunction func, size_t paramIndex, size_t * paramOffset, size_t * paramSize);
void btx_push_message_lttng_ust_cuda_cuFuncGetParamInfo_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t paramOffset_val, size_t paramSize_val);
void btx_push_message_lttng_ust_cuda_cuFuncIsLoaded_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUfunctionLoadingState * state, CUfunction function);
void btx_push_message_lttng_ust_cuda_cuFuncIsLoaded_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUfunctionLoadingState state_val);
void btx_push_message_lttng_ust_cuda_cuFuncLoad_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUfunction function);
void btx_push_message_lttng_ust_cuda_cuFuncLoad_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuLaunchKernel_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUfunction f, unsigned int gridDimX, unsigned int gridDimY, unsigned int gridDimZ, unsigned int blockDimX, unsigned int blockDimY, unsigned int blockDimZ, unsigned int sharedMemBytes, CUstream hStream, void ** kernelParams, void ** extra, size_t _extra_vals_length, void * * extra_vals);
void btx_push_message_lttng_ust_cuda_cuLaunchKernel_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuLaunchKernelEx_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUlaunchConfig * config, CUfunction f, void ** kernelParams, void ** extra, size_t _config_val_length, CUlaunchConfig * config_val, size_t _config__attrs_vals_length, CUlaunchAttribute * config__attrs_vals, size_t _extra_vals_length, void * * extra_vals);
void btx_push_message_lttng_ust_cuda_cuLaunchKernelEx_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuLaunchCooperativeKernel_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUfunction f, unsigned int gridDimX, unsigned int gridDimY, unsigned int gridDimZ, unsigned int blockDimX, unsigned int blockDimY, unsigned int blockDimZ, unsigned int sharedMemBytes, CUstream hStream, void ** kernelParams);
void btx_push_message_lttng_ust_cuda_cuLaunchCooperativeKernel_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuLaunchCooperativeKernelMultiDevice_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUDA_LAUNCH_PARAMS * launchParamsList, unsigned int numDevices, unsigned int flags, size_t _launchParamsList_vals_length, CUDA_LAUNCH_PARAMS * launchParamsList_vals);
void btx_push_message_lttng_ust_cuda_cuLaunchCooperativeKernelMultiDevice_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuLaunchHostFunc_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUhostFn fn, void * userData);
void btx_push_message_lttng_ust_cuda_cuLaunchHostFunc_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuFuncSetBlockShape_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUfunction hfunc, int x, int y, int z);
void btx_push_message_lttng_ust_cuda_cuFuncSetBlockShape_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuFuncSetSharedSize_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUfunction hfunc, unsigned int bytes);
void btx_push_message_lttng_ust_cuda_cuFuncSetSharedSize_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuParamSetSize_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUfunction hfunc, unsigned int numbytes);
void btx_push_message_lttng_ust_cuda_cuParamSetSize_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuParamSeti_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUfunction hfunc, int offset, unsigned int value);
void btx_push_message_lttng_ust_cuda_cuParamSeti_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuParamSetf_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUfunction hfunc, int offset, float value);
void btx_push_message_lttng_ust_cuda_cuParamSetf_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuParamSetv_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUfunction hfunc, int offset, void * ptr, unsigned int numbytes, size_t _ptr_vals_length, void * ptr_vals);
void btx_push_message_lttng_ust_cuda_cuParamSetv_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuLaunch_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUfunction f);
void btx_push_message_lttng_ust_cuda_cuLaunch_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuLaunchGrid_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUfunction f, int grid_width, int grid_height);
void btx_push_message_lttng_ust_cuda_cuLaunchGrid_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuLaunchGridAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUfunction f, int grid_width, int grid_height, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuLaunchGridAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuParamSetTexRef_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUfunction hfunc, int texunit, CUtexref hTexRef);
void btx_push_message_lttng_ust_cuda_cuParamSetTexRef_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuFuncSetSharedMemConfig_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUfunction hfunc, CUsharedconfig config);
void btx_push_message_lttng_ust_cuda_cuFuncSetSharedMemConfig_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraph * phGraph, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuGraphCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUgraph phGraph_val);
void btx_push_message_lttng_ust_cuda_cuGraphAddKernelNode_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode * phGraphNode, CUgraph hGraph, CUgraphNode * dependencies, size_t numDependencies, CUDA_KERNEL_NODE_PARAMS * nodeParams, size_t _dependencies_vals_length, CUgraphNode * dependencies_vals, size_t _nodeParams_val_length, CUDA_KERNEL_NODE_PARAMS * nodeParams_val, size_t _nodeParams__extra_vals_length, void * * nodeParams__extra_vals);
void btx_push_message_lttng_ust_cuda_cuGraphAddKernelNode_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUgraphNode phGraphNode_val);
void btx_push_message_lttng_ust_cuda_cuGraphKernelNodeGetParams_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode hNode, CUDA_KERNEL_NODE_PARAMS * nodeParams);
void btx_push_message_lttng_ust_cuda_cuGraphKernelNodeGetParams_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _nodeParams_val_length, CUDA_KERNEL_NODE_PARAMS * nodeParams_val, size_t _nodeParams__extra_vals_length, void * * nodeParams__extra_vals);
void btx_push_message_lttng_ust_cuda_cuGraphKernelNodeSetParams_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode hNode, CUDA_KERNEL_NODE_PARAMS * nodeParams, size_t _nodeParams_val_length, CUDA_KERNEL_NODE_PARAMS * nodeParams_val, size_t _nodeParams__extra_vals_length, void * * nodeParams__extra_vals);
void btx_push_message_lttng_ust_cuda_cuGraphKernelNodeSetParams_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphAddMemcpyNode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode * phGraphNode, CUgraph hGraph, CUgraphNode * dependencies, size_t numDependencies, CUDA_MEMCPY3D * copyParams, CUcontext ctx, size_t _dependencies_vals_length, CUgraphNode * dependencies_vals, size_t _copyParams_val_length, CUDA_MEMCPY3D * copyParams_val);
void btx_push_message_lttng_ust_cuda_cuGraphAddMemcpyNode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUgraphNode phGraphNode_val);
void btx_push_message_lttng_ust_cuda_cuGraphMemcpyNodeGetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode hNode, CUDA_MEMCPY3D * nodeParams);
void btx_push_message_lttng_ust_cuda_cuGraphMemcpyNodeGetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _nodeParams_val_length, CUDA_MEMCPY3D * nodeParams_val);
void btx_push_message_lttng_ust_cuda_cuGraphMemcpyNodeSetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode hNode, CUDA_MEMCPY3D * nodeParams, size_t _nodeParams_val_length, CUDA_MEMCPY3D * nodeParams_val);
void btx_push_message_lttng_ust_cuda_cuGraphMemcpyNodeSetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphAddMemsetNode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode * phGraphNode, CUgraph hGraph, CUgraphNode * dependencies, size_t numDependencies, CUDA_MEMSET_NODE_PARAMS * memsetParams, CUcontext ctx, size_t _dependencies_vals_length, CUgraphNode * dependencies_vals, size_t _memsetParams_val_length, CUDA_MEMSET_NODE_PARAMS * memsetParams_val);
void btx_push_message_lttng_ust_cuda_cuGraphAddMemsetNode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUgraphNode phGraphNode_val);
void btx_push_message_lttng_ust_cuda_cuGraphMemsetNodeGetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode hNode, CUDA_MEMSET_NODE_PARAMS * nodeParams);
void btx_push_message_lttng_ust_cuda_cuGraphMemsetNodeGetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _nodeParams_val_length, CUDA_MEMSET_NODE_PARAMS * nodeParams_val);
void btx_push_message_lttng_ust_cuda_cuGraphMemsetNodeSetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode hNode, CUDA_MEMSET_NODE_PARAMS * nodeParams, size_t _nodeParams_val_length, CUDA_MEMSET_NODE_PARAMS * nodeParams_val);
void btx_push_message_lttng_ust_cuda_cuGraphMemsetNodeSetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphAddHostNode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode * phGraphNode, CUgraph hGraph, CUgraphNode * dependencies, size_t numDependencies, CUDA_HOST_NODE_PARAMS * nodeParams, size_t _dependencies_vals_length, CUgraphNode * dependencies_vals, size_t _nodeParams_val_length, CUDA_HOST_NODE_PARAMS * nodeParams_val);
void btx_push_message_lttng_ust_cuda_cuGraphAddHostNode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUgraphNode phGraphNode_val);
void btx_push_message_lttng_ust_cuda_cuGraphHostNodeGetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode hNode, CUDA_HOST_NODE_PARAMS * nodeParams);
void btx_push_message_lttng_ust_cuda_cuGraphHostNodeGetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _nodeParams_val_length, CUDA_HOST_NODE_PARAMS * nodeParams_val);
void btx_push_message_lttng_ust_cuda_cuGraphHostNodeSetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode hNode, CUDA_HOST_NODE_PARAMS * nodeParams, size_t _nodeParams_val_length, CUDA_HOST_NODE_PARAMS * nodeParams_val);
void btx_push_message_lttng_ust_cuda_cuGraphHostNodeSetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphAddChildGraphNode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode * phGraphNode, CUgraph hGraph, CUgraphNode * dependencies, size_t numDependencies, CUgraph childGraph, size_t _dependencies_vals_length, CUgraphNode * dependencies_vals);
void btx_push_message_lttng_ust_cuda_cuGraphAddChildGraphNode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphChildGraphNodeGetGraph_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode hNode, CUgraph * phGraph);
void btx_push_message_lttng_ust_cuda_cuGraphChildGraphNodeGetGraph_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUgraph phGraph_val);
void btx_push_message_lttng_ust_cuda_cuGraphAddEmptyNode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode * phGraphNode, CUgraph hGraph, CUgraphNode * dependencies, size_t numDependencies, size_t _dependencies_vals_length, CUgraphNode * dependencies_vals);
void btx_push_message_lttng_ust_cuda_cuGraphAddEmptyNode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUgraphNode phGraphNode_val);
void btx_push_message_lttng_ust_cuda_cuGraphAddEventRecordNode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode * phGraphNode, CUgraph hGraph, CUgraphNode * dependencies, size_t numDependencies, CUevent event, size_t _dependencies_vals_length, CUgraphNode * dependencies_vals);
void btx_push_message_lttng_ust_cuda_cuGraphAddEventRecordNode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUgraphNode phGraphNode_val);
void btx_push_message_lttng_ust_cuda_cuGraphEventRecordNodeGetEvent_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode hNode, CUevent * event_out);
void btx_push_message_lttng_ust_cuda_cuGraphEventRecordNodeGetEvent_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUevent event_out_val);
void btx_push_message_lttng_ust_cuda_cuGraphEventRecordNodeSetEvent_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode hNode, CUevent event);
void btx_push_message_lttng_ust_cuda_cuGraphEventRecordNodeSetEvent_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphAddEventWaitNode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode * phGraphNode, CUgraph hGraph, CUgraphNode * dependencies, size_t numDependencies, CUevent event, size_t _dependencies_vals_length, CUgraphNode * dependencies_vals);
void btx_push_message_lttng_ust_cuda_cuGraphAddEventWaitNode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUgraphNode phGraphNode_val);
void btx_push_message_lttng_ust_cuda_cuGraphEventWaitNodeGetEvent_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode hNode, CUevent * event_out);
void btx_push_message_lttng_ust_cuda_cuGraphEventWaitNodeGetEvent_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUevent event_out_val);
void btx_push_message_lttng_ust_cuda_cuGraphEventWaitNodeSetEvent_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode hNode, CUevent event);
void btx_push_message_lttng_ust_cuda_cuGraphEventWaitNodeSetEvent_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphAddExternalSemaphoresSignalNode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode * phGraphNode, CUgraph hGraph, CUgraphNode * dependencies, size_t numDependencies, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS * nodeParams, size_t _dependencies_vals_length, CUgraphNode * dependencies_vals, size_t _nodeParams_val_length, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS * nodeParams_val);
void btx_push_message_lttng_ust_cuda_cuGraphAddExternalSemaphoresSignalNode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUgraphNode phGraphNode_val);
void btx_push_message_lttng_ust_cuda_cuGraphExternalSemaphoresSignalNodeGetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode hNode, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS * params_out);
void btx_push_message_lttng_ust_cuda_cuGraphExternalSemaphoresSignalNodeGetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _params_out_val_length, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS * params_out_val);
void btx_push_message_lttng_ust_cuda_cuGraphExternalSemaphoresSignalNodeSetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode hNode, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS * nodeParams, size_t _nodeParams_val_length, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS * nodeParams_val);
void btx_push_message_lttng_ust_cuda_cuGraphExternalSemaphoresSignalNodeSetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphAddExternalSemaphoresWaitNode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode * phGraphNode, CUgraph hGraph, CUgraphNode * dependencies, size_t numDependencies, CUDA_EXT_SEM_WAIT_NODE_PARAMS * nodeParams, size_t _dependencies_vals_length, CUgraphNode * dependencies_vals, size_t _nodeParams_val_length, CUDA_EXT_SEM_WAIT_NODE_PARAMS * nodeParams_val);
void btx_push_message_lttng_ust_cuda_cuGraphAddExternalSemaphoresWaitNode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUgraphNode phGraphNode_val);
void btx_push_message_lttng_ust_cuda_cuGraphExternalSemaphoresWaitNodeGetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode hNode, CUDA_EXT_SEM_WAIT_NODE_PARAMS * params_out);
void btx_push_message_lttng_ust_cuda_cuGraphExternalSemaphoresWaitNodeGetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _params_out_val_length, CUDA_EXT_SEM_WAIT_NODE_PARAMS * params_out_val);
void btx_push_message_lttng_ust_cuda_cuGraphExternalSemaphoresWaitNodeSetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode hNode, CUDA_EXT_SEM_WAIT_NODE_PARAMS * nodeParams, size_t _nodeParams_val_length, CUDA_EXT_SEM_WAIT_NODE_PARAMS * nodeParams_val);
void btx_push_message_lttng_ust_cuda_cuGraphExternalSemaphoresWaitNodeSetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphAddBatchMemOpNode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode * phGraphNode, CUgraph hGraph, CUgraphNode * dependencies, size_t numDependencies, CUDA_BATCH_MEM_OP_NODE_PARAMS * nodeParams, size_t _dependencies_vals_length, CUgraphNode * dependencies_vals, size_t _nodeParams_val_length, CUDA_BATCH_MEM_OP_NODE_PARAMS * nodeParams_val);
void btx_push_message_lttng_ust_cuda_cuGraphAddBatchMemOpNode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUgraphNode phGraphNode_val);
void btx_push_message_lttng_ust_cuda_cuGraphBatchMemOpNodeGetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode hNode, CUDA_BATCH_MEM_OP_NODE_PARAMS * nodeParams_out);
void btx_push_message_lttng_ust_cuda_cuGraphBatchMemOpNodeGetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _nodeParams_out_val_length, CUDA_BATCH_MEM_OP_NODE_PARAMS * nodeParams_out_val);
void btx_push_message_lttng_ust_cuda_cuGraphBatchMemOpNodeSetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode hNode, CUDA_BATCH_MEM_OP_NODE_PARAMS * nodeParams, size_t _nodeParams_val_length, CUDA_BATCH_MEM_OP_NODE_PARAMS * nodeParams_val);
void btx_push_message_lttng_ust_cuda_cuGraphBatchMemOpNodeSetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphExecBatchMemOpNodeSetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphExec hGraphExec, CUgraphNode hNode, CUDA_BATCH_MEM_OP_NODE_PARAMS * nodeParams, size_t _nodeParams_val_length, CUDA_BATCH_MEM_OP_NODE_PARAMS * nodeParams_val);
void btx_push_message_lttng_ust_cuda_cuGraphExecBatchMemOpNodeSetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphAddMemAllocNode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode * phGraphNode, CUgraph hGraph, CUgraphNode * dependencies, size_t numDependencies, CUDA_MEM_ALLOC_NODE_PARAMS * nodeParams, size_t _dependencies_vals_length, CUgraphNode * dependencies_vals, size_t _nodeParams_val_length, CUDA_MEM_ALLOC_NODE_PARAMS * nodeParams_val);
void btx_push_message_lttng_ust_cuda_cuGraphAddMemAllocNode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUgraphNode phGraphNode_val);
void btx_push_message_lttng_ust_cuda_cuGraphMemAllocNodeGetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode hNode, CUDA_MEM_ALLOC_NODE_PARAMS * params_out, size_t _params_out_val_length, CUDA_MEM_ALLOC_NODE_PARAMS * params_out_val);
void btx_push_message_lttng_ust_cuda_cuGraphMemAllocNodeGetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphAddMemFreeNode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode * phGraphNode, CUgraph hGraph, CUgraphNode * dependencies, size_t numDependencies, CUdeviceptr dptr, size_t _dependencies_vals_length, CUgraphNode * dependencies_vals);
void btx_push_message_lttng_ust_cuda_cuGraphAddMemFreeNode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUgraphNode phGraphNode_val);
void btx_push_message_lttng_ust_cuda_cuGraphMemFreeNodeGetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode hNode, CUdeviceptr * dptr_out);
void btx_push_message_lttng_ust_cuda_cuGraphMemFreeNodeGetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUdeviceptr dptr_out_val);
void btx_push_message_lttng_ust_cuda_cuDeviceGraphMemTrim_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdevice device);
void btx_push_message_lttng_ust_cuda_cuDeviceGraphMemTrim_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuDeviceGetGraphMemAttribute_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdevice device, CUgraphMem_attribute attr, void * value);
void btx_push_message_lttng_ust_cuda_cuDeviceGetGraphMemAttribute_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _value_val_length, void * value_val);
void btx_push_message_lttng_ust_cuda_cuDeviceSetGraphMemAttribute_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdevice device, CUgraphMem_attribute attr, void * value, size_t _value_val_length, void * value_val);
void btx_push_message_lttng_ust_cuda_cuDeviceSetGraphMemAttribute_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphClone_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraph * phGraphClone, CUgraph originalGraph);
void btx_push_message_lttng_ust_cuda_cuGraphClone_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUgraph phGraphClone_val);
void btx_push_message_lttng_ust_cuda_cuGraphNodeFindInClone_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode * phNode, CUgraphNode hOriginalNode, CUgraph hClonedGraph);
void btx_push_message_lttng_ust_cuda_cuGraphNodeFindInClone_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUgraphNode phNode_val);
void btx_push_message_lttng_ust_cuda_cuGraphNodeGetType_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode hNode, CUgraphNodeType * type);
void btx_push_message_lttng_ust_cuda_cuGraphNodeGetType_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUgraphNodeType type_val);
void btx_push_message_lttng_ust_cuda_cuGraphGetNodes_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraph hGraph, CUgraphNode * nodes, size_t * numNodes, size_t numNodes_val);
void btx_push_message_lttng_ust_cuda_cuGraphGetNodes_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t numNodes_val, size_t _nodes_vals_length, CUgraphNode * nodes_vals);
void btx_push_message_lttng_ust_cuda_cuGraphGetRootNodes_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraph hGraph, CUgraphNode * rootNodes, size_t * numRootNodes, size_t numRootNodes_val);
void btx_push_message_lttng_ust_cuda_cuGraphGetRootNodes_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t numRootNodes_val, size_t _rootNodes_vals_length, CUgraphNode * rootNodes_vals);
void btx_push_message_lttng_ust_cuda_cuGraphGetEdges_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraph hGraph, CUgraphNode * from, CUgraphNode * to, CUgraphEdgeData * edgeData, size_t * numEdges, size_t numEdges_val);
void btx_push_message_lttng_ust_cuda_cuGraphGetEdges_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t numEdges_val, size_t _from_vals_length, CUgraphNode * from_vals, size_t _to_vals_length, CUgraphNode * to_vals, size_t _edgeData_vals_length, CUgraphEdgeData * edgeData_vals);
void btx_push_message_lttng_ust_cuda_cuGraphNodeGetDependencies_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode hNode, CUgraphNode * dependencies, CUgraphEdgeData * edgeData, size_t * numDependencies, size_t numDependencies_val);
void btx_push_message_lttng_ust_cuda_cuGraphNodeGetDependencies_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t numDependencies_val, size_t _dependencies_vals_length, CUgraphNode * dependencies_vals, size_t _edgeData_vals_length, CUgraphEdgeData * edgeData_vals);
void btx_push_message_lttng_ust_cuda_cuGraphNodeGetDependentNodes_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode hNode, CUgraphNode * dependentNodes, CUgraphEdgeData * edgeData, size_t * numDependentNodes, size_t numDependentNodes_val);
void btx_push_message_lttng_ust_cuda_cuGraphNodeGetDependentNodes_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t numDependentNodes_val, size_t _dependentNodes_vals_length, CUgraphNode * dependentNodes_vals, size_t _edgeData_vals_length, CUgraphEdgeData * edgeData_vals);
void btx_push_message_lttng_ust_cuda_cuGraphAddDependencies_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraph hGraph, CUgraphNode * from, CUgraphNode * to, CUgraphEdgeData * edgeData, size_t numDependencies, size_t _from_vals_length, CUgraphNode * from_vals, size_t _to_vals_length, CUgraphNode * to_vals, size_t _edgeData_vals_length, CUgraphEdgeData * edgeData_vals);
void btx_push_message_lttng_ust_cuda_cuGraphAddDependencies_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphRemoveDependencies_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraph hGraph, CUgraphNode * from, CUgraphNode * to, CUgraphEdgeData * edgeData, size_t numDependencies, size_t _from_vals_length, CUgraphNode * from_vals, size_t _to_vals_length, CUgraphNode * to_vals, size_t _edgeData_vals_length, CUgraphEdgeData * edgeData_vals);
void btx_push_message_lttng_ust_cuda_cuGraphRemoveDependencies_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphDestroyNode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode hNode);
void btx_push_message_lttng_ust_cuda_cuGraphDestroyNode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphInstantiateWithFlags_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphExec * phGraphExec, CUgraph hGraph, unsigned long long int flags);
void btx_push_message_lttng_ust_cuda_cuGraphInstantiateWithFlags_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUgraphExec phGraphExec_val);
void btx_push_message_lttng_ust_cuda_cuGraphInstantiateWithParams_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphExec * phGraphExec, CUgraph hGraph, CUDA_GRAPH_INSTANTIATE_PARAMS * instantiateParams, size_t _instantiateParams_val_length, CUDA_GRAPH_INSTANTIATE_PARAMS * instantiateParams_val);
void btx_push_message_lttng_ust_cuda_cuGraphInstantiateWithParams_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUgraphExec phGraphExec_val);
void btx_push_message_lttng_ust_cuda_cuGraphExecGetFlags_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphExec hGraphExec, cuuint64_t * flags);
void btx_push_message_lttng_ust_cuda_cuGraphExecGetFlags_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, cuuint64_t flags_val);
void btx_push_message_lttng_ust_cuda_cuGraphExecKernelNodeSetParams_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphExec hGraphExec, CUgraphNode hNode, CUDA_KERNEL_NODE_PARAMS * nodeParams, size_t _nodeParams_val_length, CUDA_KERNEL_NODE_PARAMS * nodeParams_val, size_t _nodeParams__extra_vals_length, void * * nodeParams__extra_vals);
void btx_push_message_lttng_ust_cuda_cuGraphExecKernelNodeSetParams_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphExecMemcpyNodeSetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphExec hGraphExec, CUgraphNode hNode, CUDA_MEMCPY3D * copyParams, CUcontext ctx, size_t _copyParams_val_length, CUDA_MEMCPY3D * copyParams_val);
void btx_push_message_lttng_ust_cuda_cuGraphExecMemcpyNodeSetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphExecMemsetNodeSetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphExec hGraphExec, CUgraphNode hNode, CUDA_MEMSET_NODE_PARAMS * memsetParams, CUcontext ctx, size_t _memsetParams_val_length, CUDA_MEMSET_NODE_PARAMS * memsetParams_val);
void btx_push_message_lttng_ust_cuda_cuGraphExecMemsetNodeSetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphExecHostNodeSetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphExec hGraphExec, CUgraphNode hNode, CUDA_HOST_NODE_PARAMS * nodeParams, size_t _nodeParams_val_length, CUDA_HOST_NODE_PARAMS * nodeParams_val);
void btx_push_message_lttng_ust_cuda_cuGraphExecHostNodeSetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphExecChildGraphNodeSetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphExec hGraphExec, CUgraphNode hNode, CUgraph childGraph);
void btx_push_message_lttng_ust_cuda_cuGraphExecChildGraphNodeSetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphExecEventRecordNodeSetEvent_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphExec hGraphExec, CUgraphNode hNode, CUevent event);
void btx_push_message_lttng_ust_cuda_cuGraphExecEventRecordNodeSetEvent_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphExecEventWaitNodeSetEvent_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphExec hGraphExec, CUgraphNode hNode, CUevent event);
void btx_push_message_lttng_ust_cuda_cuGraphExecEventWaitNodeSetEvent_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphExecExternalSemaphoresSignalNodeSetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphExec hGraphExec, CUgraphNode hNode, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS * nodeParams, size_t _nodeParams_val_length, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS * nodeParams_val);
void btx_push_message_lttng_ust_cuda_cuGraphExecExternalSemaphoresSignalNodeSetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphExecExternalSemaphoresWaitNodeSetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphExec hGraphExec, CUgraphNode hNode, CUDA_EXT_SEM_WAIT_NODE_PARAMS * nodeParams, size_t _nodeParams_val_length, CUDA_EXT_SEM_WAIT_NODE_PARAMS * nodeParams_val);
void btx_push_message_lttng_ust_cuda_cuGraphExecExternalSemaphoresWaitNodeSetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphNodeSetEnabled_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphExec hGraphExec, CUgraphNode hNode, unsigned int isEnabled);
void btx_push_message_lttng_ust_cuda_cuGraphNodeSetEnabled_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphNodeGetEnabled_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphExec hGraphExec, CUgraphNode hNode, unsigned int * isEnabled);
void btx_push_message_lttng_ust_cuda_cuGraphNodeGetEnabled_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, unsigned int isEnabled_val);
void btx_push_message_lttng_ust_cuda_cuGraphUpload_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphExec hGraphExec, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuGraphUpload_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphLaunch_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphExec hGraphExec, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuGraphLaunch_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphExecDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphExec hGraphExec);
void btx_push_message_lttng_ust_cuda_cuGraphExecDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraph hGraph);
void btx_push_message_lttng_ust_cuda_cuGraphDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphExecUpdate_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphExec hGraphExec, CUgraph hGraph, CUgraphExecUpdateResultInfo * resultInfo);
void btx_push_message_lttng_ust_cuda_cuGraphExecUpdate_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _resultInfo_val_length, CUgraphExecUpdateResultInfo * resultInfo_val);
void btx_push_message_lttng_ust_cuda_cuGraphKernelNodeCopyAttributes_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode dst, CUgraphNode src);
void btx_push_message_lttng_ust_cuda_cuGraphKernelNodeCopyAttributes_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphKernelNodeGetAttribute_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode hNode, CUkernelNodeAttrID attr, CUkernelNodeAttrValue * value_out);
void btx_push_message_lttng_ust_cuda_cuGraphKernelNodeGetAttribute_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _value_out_val_length, CUkernelNodeAttrValue * value_out_val);
void btx_push_message_lttng_ust_cuda_cuGraphKernelNodeSetAttribute_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode hNode, CUkernelNodeAttrID attr, CUkernelNodeAttrValue * value, size_t _value_val_length, CUkernelNodeAttrValue * value_val);
void btx_push_message_lttng_ust_cuda_cuGraphKernelNodeSetAttribute_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphDebugDotPrint_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraph hGraph, char * path, unsigned int flags, char * path_val);
void btx_push_message_lttng_ust_cuda_cuGraphDebugDotPrint_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuUserObjectCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUuserObject * object_out, void * ptr, CUhostFn destroy, unsigned int initialRefcount, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuUserObjectCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUuserObject object_out_val);
void btx_push_message_lttng_ust_cuda_cuUserObjectRetain_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUuserObject object, unsigned int count);
void btx_push_message_lttng_ust_cuda_cuUserObjectRetain_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuUserObjectRelease_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUuserObject object, unsigned int count);
void btx_push_message_lttng_ust_cuda_cuUserObjectRelease_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphRetainUserObject_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraph graph, CUuserObject object, unsigned int count, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuGraphRetainUserObject_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphReleaseUserObject_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraph graph, CUuserObject object, unsigned int count);
void btx_push_message_lttng_ust_cuda_cuGraphReleaseUserObject_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphAddNode_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode * phGraphNode, CUgraph hGraph, CUgraphNode * dependencies, CUgraphEdgeData * dependencyData, size_t numDependencies, CUgraphNodeParams * nodeParams, size_t _dependencies_vals_length, CUgraphNode * dependencies_vals, size_t _dependencyData_vals_length, CUgraphEdgeData * dependencyData_vals, size_t _nodeParams_val_length, CUgraphNodeParams * nodeParams_val);
void btx_push_message_lttng_ust_cuda_cuGraphAddNode_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUgraphNode phGraphNode_val);
void btx_push_message_lttng_ust_cuda_cuGraphNodeSetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode hNode, CUgraphNodeParams * nodeParams, size_t _nodeParams_val_length, CUgraphNodeParams * nodeParams_val);
void btx_push_message_lttng_ust_cuda_cuGraphNodeSetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphExecNodeSetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphExec hGraphExec, CUgraphNode hNode, CUgraphNodeParams * nodeParams, size_t _nodeParams_val_length, CUgraphNodeParams * nodeParams_val);
void btx_push_message_lttng_ust_cuda_cuGraphExecNodeSetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphConditionalHandleCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphConditionalHandle * pHandle_out, CUgraph hGraph, CUcontext ctx, unsigned int defaultLaunchValue, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuGraphConditionalHandleCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUgraphConditionalHandle pHandle_out_val);
void btx_push_message_lttng_ust_cuda_cuOccupancyMaxActiveBlocksPerMultiprocessor_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * numBlocks, CUfunction func, int blockSize, size_t dynamicSMemSize);
void btx_push_message_lttng_ust_cuda_cuOccupancyMaxActiveBlocksPerMultiprocessor_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, int numBlocks_val);
void btx_push_message_lttng_ust_cuda_cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * numBlocks, CUfunction func, int blockSize, size_t dynamicSMemSize, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, int numBlocks_val);
void btx_push_message_lttng_ust_cuda_cuOccupancyMaxPotentialBlockSize_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * minGridSize, int * blockSize, CUfunction func, CUoccupancyB2DSize blockSizeToDynamicSMemSize, size_t dynamicSMemSize, int blockSizeLimit);
void btx_push_message_lttng_ust_cuda_cuOccupancyMaxPotentialBlockSize_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, int minGridSize_val, int blockSize_val);
void btx_push_message_lttng_ust_cuda_cuOccupancyMaxPotentialBlockSizeWithFlags_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * minGridSize, int * blockSize, CUfunction func, CUoccupancyB2DSize blockSizeToDynamicSMemSize, size_t dynamicSMemSize, int blockSizeLimit, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuOccupancyMaxPotentialBlockSizeWithFlags_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, int minGridSize_val, int blockSize_val);
void btx_push_message_lttng_ust_cuda_cuOccupancyAvailableDynamicSMemPerBlock_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, size_t * dynamicSmemSize, CUfunction func, int numBlocks, int blockSize);
void btx_push_message_lttng_ust_cuda_cuOccupancyAvailableDynamicSMemPerBlock_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t dynamicSmemSize_val);
void btx_push_message_lttng_ust_cuda_cuOccupancyMaxPotentialClusterSize_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * clusterSize, CUfunction func, CUlaunchConfig * config, size_t _config_val_length, CUlaunchConfig * config_val);
void btx_push_message_lttng_ust_cuda_cuOccupancyMaxPotentialClusterSize_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, int clusterSize_val);
void btx_push_message_lttng_ust_cuda_cuOccupancyMaxActiveClusters_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * numClusters, CUfunction func, CUlaunchConfig * config, size_t _config_val_length, CUlaunchConfig * config_val);
void btx_push_message_lttng_ust_cuda_cuOccupancyMaxActiveClusters_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, int numClusters_val);
void btx_push_message_lttng_ust_cuda_cuTexRefSetArray_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUtexref hTexRef, CUarray hArray, unsigned int Flags);
void btx_push_message_lttng_ust_cuda_cuTexRefSetArray_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuTexRefSetMipmappedArray_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUtexref hTexRef, CUmipmappedArray hMipmappedArray, unsigned int Flags);
void btx_push_message_lttng_ust_cuda_cuTexRefSetMipmappedArray_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuTexRefSetAddress_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, size_t * ByteOffset, CUtexref hTexRef, CUdeviceptr dptr, size_t bytes);
void btx_push_message_lttng_ust_cuda_cuTexRefSetAddress_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuTexRefSetAddress2D_v3_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUtexref hTexRef, CUDA_ARRAY_DESCRIPTOR * desc, CUdeviceptr dptr, size_t Pitch);
void btx_push_message_lttng_ust_cuda_cuTexRefSetAddress2D_v3_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuTexRefSetFormat_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUtexref hTexRef, CUarray_format fmt, int NumPackedComponents);
void btx_push_message_lttng_ust_cuda_cuTexRefSetFormat_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuTexRefSetAddressMode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUtexref hTexRef, int dim, CUaddress_mode am);
void btx_push_message_lttng_ust_cuda_cuTexRefSetAddressMode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuTexRefSetFilterMode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUtexref hTexRef, CUfilter_mode fm);
void btx_push_message_lttng_ust_cuda_cuTexRefSetFilterMode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuTexRefSetMipmapFilterMode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUtexref hTexRef, CUfilter_mode fm);
void btx_push_message_lttng_ust_cuda_cuTexRefSetMipmapFilterMode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuTexRefSetMipmapLevelBias_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUtexref hTexRef, float bias);
void btx_push_message_lttng_ust_cuda_cuTexRefSetMipmapLevelBias_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuTexRefSetMipmapLevelClamp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUtexref hTexRef, float minMipmapLevelClamp, float maxMipmapLevelClamp);
void btx_push_message_lttng_ust_cuda_cuTexRefSetMipmapLevelClamp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuTexRefSetMaxAnisotropy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUtexref hTexRef, unsigned int maxAniso);
void btx_push_message_lttng_ust_cuda_cuTexRefSetMaxAnisotropy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuTexRefSetBorderColor_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUtexref hTexRef, float * pBorderColor, float * pBorderColor_vals);
void btx_push_message_lttng_ust_cuda_cuTexRefSetBorderColor_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuTexRefSetFlags_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUtexref hTexRef, unsigned int Flags);
void btx_push_message_lttng_ust_cuda_cuTexRefSetFlags_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuTexRefGetAddress_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr * pdptr, CUtexref hTexRef);
void btx_push_message_lttng_ust_cuda_cuTexRefGetAddress_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUdeviceptr pdptr_val);
void btx_push_message_lttng_ust_cuda_cuTexRefGetArray_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUarray * phArray, CUtexref hTexRef);
void btx_push_message_lttng_ust_cuda_cuTexRefGetArray_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUarray phArray_val);
void btx_push_message_lttng_ust_cuda_cuTexRefGetMipmappedArray_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmipmappedArray * phMipmappedArray, CUtexref hTexRef);
void btx_push_message_lttng_ust_cuda_cuTexRefGetMipmappedArray_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUmipmappedArray phMipmappedArray_val);
void btx_push_message_lttng_ust_cuda_cuTexRefGetAddressMode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUaddress_mode * pam, CUtexref hTexRef, int dim);
void btx_push_message_lttng_ust_cuda_cuTexRefGetAddressMode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUaddress_mode pam_val);
void btx_push_message_lttng_ust_cuda_cuTexRefGetFilterMode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUfilter_mode * pfm, CUtexref hTexRef);
void btx_push_message_lttng_ust_cuda_cuTexRefGetFilterMode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUfilter_mode pfm_val);
void btx_push_message_lttng_ust_cuda_cuTexRefGetFormat_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUarray_format * pFormat, int * pNumChannels, CUtexref hTexRef);
void btx_push_message_lttng_ust_cuda_cuTexRefGetFormat_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUarray_format pFormat_val, int pNumChannels_val);
void btx_push_message_lttng_ust_cuda_cuTexRefGetMipmapFilterMode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUfilter_mode * pfm, CUtexref hTexRef);
void btx_push_message_lttng_ust_cuda_cuTexRefGetMipmapFilterMode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUfilter_mode pfm_val);
void btx_push_message_lttng_ust_cuda_cuTexRefGetMipmapLevelBias_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, float * pbias, CUtexref hTexRef);
void btx_push_message_lttng_ust_cuda_cuTexRefGetMipmapLevelBias_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, float pbias_val);
void btx_push_message_lttng_ust_cuda_cuTexRefGetMipmapLevelClamp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, float * pminMipmapLevelClamp, float * pmaxMipmapLevelClamp, CUtexref hTexRef);
void btx_push_message_lttng_ust_cuda_cuTexRefGetMipmapLevelClamp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, float pminMipmapLevelClamp_val, float pmaxMipmapLevelClamp_val);
void btx_push_message_lttng_ust_cuda_cuTexRefGetMaxAnisotropy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * pmaxAniso, CUtexref hTexRef);
void btx_push_message_lttng_ust_cuda_cuTexRefGetMaxAnisotropy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, int pmaxAniso_val);
void btx_push_message_lttng_ust_cuda_cuTexRefGetBorderColor_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, float * pBorderColor, CUtexref hTexRef);
void btx_push_message_lttng_ust_cuda_cuTexRefGetBorderColor_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, float pBorderColor_val);
void btx_push_message_lttng_ust_cuda_cuTexRefGetFlags_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, unsigned int * pFlags, CUtexref hTexRef);
void btx_push_message_lttng_ust_cuda_cuTexRefGetFlags_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, unsigned int pFlags_val);
void btx_push_message_lttng_ust_cuda_cuTexRefCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUtexref * pTexRef);
void btx_push_message_lttng_ust_cuda_cuTexRefCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUtexref pTexRef_val);
void btx_push_message_lttng_ust_cuda_cuTexRefDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUtexref hTexRef);
void btx_push_message_lttng_ust_cuda_cuTexRefDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuSurfRefSetArray_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUsurfref hSurfRef, CUarray hArray, unsigned int Flags);
void btx_push_message_lttng_ust_cuda_cuSurfRefSetArray_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuSurfRefGetArray_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUarray * phArray, CUsurfref hSurfRef);
void btx_push_message_lttng_ust_cuda_cuSurfRefGetArray_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUarray phArray_val);
void btx_push_message_lttng_ust_cuda_cuTexObjectCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUtexObject * pTexObject, CUDA_RESOURCE_DESC * pResDesc, CUDA_TEXTURE_DESC * pTexDesc, CUDA_RESOURCE_VIEW_DESC * pResViewDesc, size_t _pResDesc_val_length, CUDA_RESOURCE_DESC * pResDesc_val, size_t _pTexDesc_val_length, CUDA_TEXTURE_DESC * pTexDesc_val, size_t _pResViewDesc_val_length, CUDA_RESOURCE_VIEW_DESC * pResViewDesc_val);
void btx_push_message_lttng_ust_cuda_cuTexObjectCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUtexObject pTexObject_val);
void btx_push_message_lttng_ust_cuda_cuTexObjectDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUtexObject texObject);
void btx_push_message_lttng_ust_cuda_cuTexObjectDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuTexObjectGetResourceDesc_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUDA_RESOURCE_DESC * pResDesc, CUtexObject texObject);
void btx_push_message_lttng_ust_cuda_cuTexObjectGetResourceDesc_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _pResDesc_val_length, CUDA_RESOURCE_DESC * pResDesc_val);
void btx_push_message_lttng_ust_cuda_cuTexObjectGetTextureDesc_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUDA_TEXTURE_DESC * pTexDesc, CUtexObject texObject);
void btx_push_message_lttng_ust_cuda_cuTexObjectGetTextureDesc_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _pTexDesc_val_length, CUDA_TEXTURE_DESC * pTexDesc_val);
void btx_push_message_lttng_ust_cuda_cuTexObjectGetResourceViewDesc_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUDA_RESOURCE_VIEW_DESC * pResViewDesc, CUtexObject texObject);
void btx_push_message_lttng_ust_cuda_cuTexObjectGetResourceViewDesc_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _pResViewDesc_val_length, CUDA_RESOURCE_VIEW_DESC * pResViewDesc_val);
void btx_push_message_lttng_ust_cuda_cuSurfObjectCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUsurfObject * pSurfObject, CUDA_RESOURCE_DESC * pResDesc, size_t _pResDesc_val_length, CUDA_RESOURCE_DESC * pResDesc_val);
void btx_push_message_lttng_ust_cuda_cuSurfObjectCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUsurfObject pSurfObject_val);
void btx_push_message_lttng_ust_cuda_cuSurfObjectDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUsurfObject surfObject);
void btx_push_message_lttng_ust_cuda_cuSurfObjectDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuSurfObjectGetResourceDesc_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUDA_RESOURCE_DESC * pResDesc, CUsurfObject surfObject);
void btx_push_message_lttng_ust_cuda_cuSurfObjectGetResourceDesc_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _pResDesc_val_length, CUDA_RESOURCE_DESC * pResDesc_val);
void btx_push_message_lttng_ust_cuda_cuTensorMapEncodeTiled_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUtensorMap * tensorMap, CUtensorMapDataType tensorDataType, cuuint32_t tensorRank, void * globalAddress, cuuint64_t * globalDim, cuuint64_t * globalStrides, cuuint32_t * boxDim, cuuint32_t * elementStrides, CUtensorMapInterleave interleave, CUtensorMapSwizzle swizzle, CUtensorMapL2promotion l2Promotion, CUtensorMapFloatOOBfill oobFill, size_t _globalDim_vals_length, cuuint64_t * globalDim_vals, size_t _globalStrides_val_length, cuuint64_t * globalStrides_val, size_t _boxDim_vals_length, cuuint32_t * boxDim_vals, size_t _elementStrides_vals_length, cuuint32_t * elementStrides_vals);
void btx_push_message_lttng_ust_cuda_cuTensorMapEncodeTiled_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _tensorMap_val_length, CUtensorMap * tensorMap_val);
void btx_push_message_lttng_ust_cuda_cuTensorMapEncodeIm2col_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUtensorMap * tensorMap, CUtensorMapDataType tensorDataType, cuuint32_t tensorRank, void * globalAddress, cuuint64_t * globalDim, cuuint64_t * globalStrides, int * pixelBoxLowerCorner, int * pixelBoxUpperCorner, cuuint32_t channelsPerPixel, cuuint32_t pixelsPerColumn, cuuint32_t * elementStrides, CUtensorMapInterleave interleave, CUtensorMapSwizzle swizzle, CUtensorMapL2promotion l2Promotion, CUtensorMapFloatOOBfill oobFill, size_t _globalDim_vals_length, cuuint64_t * globalDim_vals, size_t _globalStrides_val_length, cuuint64_t * globalStrides_val, int * pixelBoxLowerCorner_vals, int * pixelBoxUpperCorner_vals);
void btx_push_message_lttng_ust_cuda_cuTensorMapEncodeIm2col_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _tensorMap_val_length, CUtensorMap * tensorMap_val);
void btx_push_message_lttng_ust_cuda_cuTensorMapEncodeIm2colWide_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUtensorMap * tensorMap, CUtensorMapDataType tensorDataType, cuuint32_t tensorRank, void * globalAddress, cuuint64_t * globalDim, cuuint64_t * globalStrides, int pixelBoxLowerCornerWidth, int pixelBoxUpperCornerWidth, cuuint32_t channelsPerPixel, cuuint32_t pixelsPerColumn, cuuint32_t * elementStrides, CUtensorMapInterleave interleave, CUtensorMapIm2ColWideMode mode, CUtensorMapSwizzle swizzle, CUtensorMapL2promotion l2Promotion, CUtensorMapFloatOOBfill oobFill, size_t _globalDim_vals_length, cuuint64_t * globalDim_vals, size_t _globalStrides_vals_length, cuuint64_t * globalStrides_vals, size_t _elementStrides_vals_length, cuuint32_t * elementStrides_vals);
void btx_push_message_lttng_ust_cuda_cuTensorMapEncodeIm2colWide_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _tensorMap_val_length, CUtensorMap * tensorMap_val);
void btx_push_message_lttng_ust_cuda_cuTensorMapReplaceAddress_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUtensorMap * tensorMap, void * globalAddress, size_t _tensorMap_val_length, CUtensorMap * tensorMap_val);
void btx_push_message_lttng_ust_cuda_cuTensorMapReplaceAddress_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuDeviceCanAccessPeer_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * canAccessPeer, CUdevice dev, CUdevice peerDev);
void btx_push_message_lttng_ust_cuda_cuDeviceCanAccessPeer_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, int canAccessPeer_val);
void btx_push_message_lttng_ust_cuda_cuCtxEnablePeerAccess_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext peerContext, unsigned int Flags);
void btx_push_message_lttng_ust_cuda_cuCtxEnablePeerAccess_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuCtxDisablePeerAccess_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext peerContext);
void btx_push_message_lttng_ust_cuda_cuCtxDisablePeerAccess_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuDeviceGetP2PAttribute_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * value, CUdevice_P2PAttribute attrib, CUdevice srcDevice, CUdevice dstDevice);
void btx_push_message_lttng_ust_cuda_cuDeviceGetP2PAttribute_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, int value_val);
void btx_push_message_lttng_ust_cuda_cuDeviceGetP2PAtomicCapabilities_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, unsigned int * capabilities, CUatomicOperation * operations, unsigned int count, CUdevice srcDevice, CUdevice dstDevice, size_t _operations_vals_length, CUatomicOperation * operations_vals);
void btx_push_message_lttng_ust_cuda_cuDeviceGetP2PAtomicCapabilities_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _capabilities_vals_length, unsigned int * capabilities_vals);
void btx_push_message_lttng_ust_cuda_cuGraphicsUnregisterResource_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphicsResource resource);
void btx_push_message_lttng_ust_cuda_cuGraphicsUnregisterResource_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphicsSubResourceGetMappedArray_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUarray * pArray, CUgraphicsResource resource, unsigned int arrayIndex, unsigned int mipLevel);
void btx_push_message_lttng_ust_cuda_cuGraphicsSubResourceGetMappedArray_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUarray pArray_val);
void btx_push_message_lttng_ust_cuda_cuGraphicsResourceGetMappedMipmappedArray_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmipmappedArray * pMipmappedArray, CUgraphicsResource resource);
void btx_push_message_lttng_ust_cuda_cuGraphicsResourceGetMappedMipmappedArray_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUmipmappedArray pMipmappedArray_val);
void btx_push_message_lttng_ust_cuda_cuGraphicsResourceGetMappedPointer_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr * pDevPtr, size_t * pSize, CUgraphicsResource resource);
void btx_push_message_lttng_ust_cuda_cuGraphicsResourceGetMappedPointer_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUdeviceptr pDevPtr_val, size_t pSize_val);
void btx_push_message_lttng_ust_cuda_cuGraphicsResourceSetMapFlags_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphicsResource resource, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuGraphicsResourceSetMapFlags_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphicsMapResources_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, unsigned int count, CUgraphicsResource * resources, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuGraphicsMapResources_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphicsUnmapResources_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, unsigned int count, CUgraphicsResource * resources, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuGraphicsUnmapResources_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGetProcAddress_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, char * symbol, void ** pfn, int cudaVersion, cuuint64_t flags, CUdriverProcAddressQueryResult * symbolStatus, char * symbol_val);
void btx_push_message_lttng_ust_cuda_cuGetProcAddress_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, void * pfn_val, CUdriverProcAddressQueryResult symbolStatus_val);
void btx_push_message_lttng_ust_cuda_cuCoredumpGetAttribute_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcoredumpSettings attrib, void * value, size_t * size, size_t size_val);
void btx_push_message_lttng_ust_cuda_cuCoredumpGetAttribute_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t size_val, size_t _value_vals_length, void * value_vals);
void btx_push_message_lttng_ust_cuda_cuCoredumpGetAttributeGlobal_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcoredumpSettings attrib, void * value, size_t * size, size_t size_val);
void btx_push_message_lttng_ust_cuda_cuCoredumpGetAttributeGlobal_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t size_val, size_t _value_vals_length, void * value_vals);
void btx_push_message_lttng_ust_cuda_cuCoredumpSetAttribute_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcoredumpSettings attrib, void * value, size_t * size, size_t size_val, size_t _value_vals_length, void * value_vals);
void btx_push_message_lttng_ust_cuda_cuCoredumpSetAttribute_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t size_val);
void btx_push_message_lttng_ust_cuda_cuCoredumpSetAttributeGlobal_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcoredumpSettings attrib, void * value, size_t * size, size_t size_val, size_t _value_vals_length, void * value_vals);
void btx_push_message_lttng_ust_cuda_cuCoredumpSetAttributeGlobal_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t size_val);
void btx_push_message_lttng_ust_cuda_cuGetExportTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void ** ppExportTable, CUuuid * pExportTableId, size_t _pExportTableId_val_length, CUuuid * pExportTableId_val);
void btx_push_message_lttng_ust_cuda_cuGetExportTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, void * ppExportTable_val);
void btx_push_message_lttng_ust_cuda_cuGreenCtxCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgreenCtx * phCtx, CUdevResourceDesc desc, CUdevice dev, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuGreenCtxCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUgreenCtx phCtx_val);
void btx_push_message_lttng_ust_cuda_cuGreenCtxDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgreenCtx hCtx);
void btx_push_message_lttng_ust_cuda_cuGreenCtxDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuCtxFromGreenCtx_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext * pContext, CUgreenCtx hCtx);
void btx_push_message_lttng_ust_cuda_cuCtxFromGreenCtx_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUcontext pContext_val);
void btx_push_message_lttng_ust_cuda_cuDeviceGetDevResource_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdevice device, CUdevResource * resource, CUdevResourceType type);
void btx_push_message_lttng_ust_cuda_cuDeviceGetDevResource_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _resource_val_length, CUdevResource * resource_val);
void btx_push_message_lttng_ust_cuda_cuCtxGetDevResource_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext hCtx, CUdevResource * resource, CUdevResourceType type);
void btx_push_message_lttng_ust_cuda_cuCtxGetDevResource_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _resource_val_length, CUdevResource * resource_val);
void btx_push_message_lttng_ust_cuda_cuGreenCtxGetDevResource_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgreenCtx hCtx, CUdevResource * resource, CUdevResourceType type);
void btx_push_message_lttng_ust_cuda_cuGreenCtxGetDevResource_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _resource_val_length, CUdevResource * resource_val);
void btx_push_message_lttng_ust_cuda_cuDevSmResourceSplitByCount_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdevResource * result, unsigned int * nbGroups, CUdevResource * input, CUdevResource * remaining, unsigned int useFlags, unsigned int minCount, unsigned int nbGroups_val, size_t _input_val_length, CUdevResource * input_val);
void btx_push_message_lttng_ust_cuda_cuDevSmResourceSplitByCount_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, unsigned int nbGroups_val, size_t _result_vals_length, CUdevResource * result_vals, size_t _remaining_val_length, CUdevResource * remaining_val);
void btx_push_message_lttng_ust_cuda_cuDevResourceGenerateDesc_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdevResourceDesc * phDesc, CUdevResource * resources, unsigned int nbResources, size_t _resources_vals_length, CUdevResource * resources_vals);
void btx_push_message_lttng_ust_cuda_cuDevResourceGenerateDesc_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUdevResourceDesc phDesc_val);
void btx_push_message_lttng_ust_cuda_cuGreenCtxRecordEvent_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgreenCtx hCtx, CUevent hEvent);
void btx_push_message_lttng_ust_cuda_cuGreenCtxRecordEvent_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGreenCtxWaitEvent_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgreenCtx hCtx, CUevent hEvent);
void btx_push_message_lttng_ust_cuda_cuGreenCtxWaitEvent_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamGetGreenCtx_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUgreenCtx * phCtx);
void btx_push_message_lttng_ust_cuda_cuStreamGetGreenCtx_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUgreenCtx phCtx_val);
void btx_push_message_lttng_ust_cuda_cuGreenCtxStreamCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream * phStream, CUgreenCtx greenCtx, unsigned int flags, int priority);
void btx_push_message_lttng_ust_cuda_cuGreenCtxStreamCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUstream phStream_val);
void btx_push_message_lttng_ust_cuda_cuGreenCtxGetId_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgreenCtx greenCtx, unsigned long long int * greenCtxId);
void btx_push_message_lttng_ust_cuda_cuGreenCtxGetId_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, unsigned long long int greenCtxId_val);
void btx_push_message_lttng_ust_cuda_cuLogsRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUlogsCallback callbackFunc, void * userData, CUlogsCallbackHandle * callback_out);
void btx_push_message_lttng_ust_cuda_cuLogsRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUlogsCallbackHandle callback_out_val);
void btx_push_message_lttng_ust_cuda_cuLogsUnregisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUlogsCallbackHandle callback);
void btx_push_message_lttng_ust_cuda_cuLogsUnregisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuLogsCurrent_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUlogIterator * iterator_out, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuLogsCurrent_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUlogIterator iterator_out_val);
void btx_push_message_lttng_ust_cuda_cuLogsDumpToFile_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUlogIterator * iterator, char * pathToFile, unsigned int flags, CUlogIterator iterator_val, char * pathToFile_val);
void btx_push_message_lttng_ust_cuda_cuLogsDumpToFile_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuLogsDumpToMemory_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUlogIterator * iterator, char * buffer, size_t * size, unsigned int flags, CUlogIterator iterator_val, size_t size_val);
void btx_push_message_lttng_ust_cuda_cuLogsDumpToMemory_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t size_val, size_t _buffer_vals_length, char * buffer_vals);
void btx_push_message_lttng_ust_cuda_cuMemHostRegister_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * p, size_t bytesize, unsigned int Flags);
void btx_push_message_lttng_ust_cuda_cuMemHostRegister_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphicsResourceSetMapFlags_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphicsResource resource, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuGraphicsResourceSetMapFlags_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuLinkCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, unsigned int numOptions, CUjit_option * options, void ** optionValues, CUlinkState * stateOut, size_t _options_vals_length, CUjit_option * options_vals, size_t _optionValues_vals_length, void * * optionValues_vals);
void btx_push_message_lttng_ust_cuda_cuLinkCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUlinkState stateOut_val);
void btx_push_message_lttng_ust_cuda_cuLinkAddData_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUlinkState state, CUjitInputType type, void * data, size_t size, char * name, unsigned int numOptions, CUjit_option * options, void ** optionValues, char * name_val, size_t _options_vals_length, CUjit_option * options_vals, size_t _optionValues_vals_length, void * * optionValues_vals);
void btx_push_message_lttng_ust_cuda_cuLinkAddData_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuLinkAddFile_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUlinkState state, CUjitInputType type, char * path, unsigned int numOptions, CUjit_option * options, void ** optionValues, char * path_val, size_t _options_vals_length, CUjit_option * options_vals, size_t _optionValues_vals_length, void * * optionValues_vals);
void btx_push_message_lttng_ust_cuda_cuLinkAddFile_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuTexRefSetAddress2D_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUtexref hTexRef, CUDA_ARRAY_DESCRIPTOR * desc, CUdeviceptr dptr, size_t Pitch);
void btx_push_message_lttng_ust_cuda_cuTexRefSetAddress2D_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuDeviceTotalMem_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, unsigned int * bytes, CUdevice dev);
void btx_push_message_lttng_ust_cuda_cuDeviceTotalMem_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, unsigned int bytes_val);
void btx_push_message_lttng_ust_cuda_cuCtxCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext * pctx, unsigned int flags, CUdevice dev);
void btx_push_message_lttng_ust_cuda_cuCtxCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUcontext pctx_val);
void btx_push_message_lttng_ust_cuda_cuCtxCreate_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext * pctx, unsigned int flags, CUdevice dev);
void btx_push_message_lttng_ust_cuda_cuCtxCreate_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUcontext pctx_val);
void btx_push_message_lttng_ust_cuda_cuCtxCreate_v3_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext * pctx, CUexecAffinityParam * paramsArray, int numParams, unsigned int flags, CUdevice dev, size_t _paramsArray_vals_length, CUexecAffinityParam * paramsArray_vals);
void btx_push_message_lttng_ust_cuda_cuCtxCreate_v3_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUcontext pctx_val);
void btx_push_message_lttng_ust_cuda_cuModuleGetGlobal_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr_v1 * dptr, unsigned int * bytes, CUmodule hmod, char * name, char * name_val);
void btx_push_message_lttng_ust_cuda_cuModuleGetGlobal_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUdeviceptr_v1 dptr_val, unsigned int bytes_val);
void btx_push_message_lttng_ust_cuda_cuMemGetInfo_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, unsigned int * free, unsigned int * total);
void btx_push_message_lttng_ust_cuda_cuMemGetInfo_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, unsigned int free_val, unsigned int total_val);
void btx_push_message_lttng_ust_cuda_cuMemAlloc_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr_v1 * dptr, unsigned int bytesize);
void btx_push_message_lttng_ust_cuda_cuMemAlloc_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUdeviceptr_v1 dptr_val);
void btx_push_message_lttng_ust_cuda_cuMemAllocPitch_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr_v1 * dptr, unsigned int * pPitch, unsigned int WidthInBytes, unsigned int Height, unsigned int ElementSizeBytes);
void btx_push_message_lttng_ust_cuda_cuMemAllocPitch_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUdeviceptr_v1 dptr_val, unsigned int pPitch_val);
void btx_push_message_lttng_ust_cuda_cuMemFree_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr_v1 dptr);
void btx_push_message_lttng_ust_cuda_cuMemFree_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemGetAddressRange_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr_v1 * pbase, unsigned int * psize, CUdeviceptr_v1 dptr);
void btx_push_message_lttng_ust_cuda_cuMemGetAddressRange_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUdeviceptr_v1 pbase_val, unsigned int psize_val);
void btx_push_message_lttng_ust_cuda_cuMemAllocHost_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void ** pp, unsigned int bytesize);
void btx_push_message_lttng_ust_cuda_cuMemAllocHost_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, void * pp_val);
void btx_push_message_lttng_ust_cuda_cuMemHostGetDevicePointer_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr_v1 * pdptr, void * p, unsigned int Flags);
void btx_push_message_lttng_ust_cuda_cuMemHostGetDevicePointer_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUdeviceptr_v1 pdptr_val);
void btx_push_message_lttng_ust_cuda_cuMemcpyHtoD_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr_v1 dstDevice, void * srcHost, unsigned int ByteCount);
void btx_push_message_lttng_ust_cuda_cuMemcpyHtoD_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyDtoH_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dstHost, CUdeviceptr_v1 srcDevice, unsigned int ByteCount);
void btx_push_message_lttng_ust_cuda_cuMemcpyDtoH_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyDtoD_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr_v1 dstDevice, CUdeviceptr_v1 srcDevice, unsigned int ByteCount);
void btx_push_message_lttng_ust_cuda_cuMemcpyDtoD_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyDtoA_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUarray dstArray, unsigned int dstOffset, CUdeviceptr_v1 srcDevice, unsigned int ByteCount);
void btx_push_message_lttng_ust_cuda_cuMemcpyDtoA_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyAtoD_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr_v1 dstDevice, CUarray srcArray, unsigned int srcOffset, unsigned int ByteCount);
void btx_push_message_lttng_ust_cuda_cuMemcpyAtoD_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyHtoA_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUarray dstArray, unsigned int dstOffset, void * srcHost, unsigned int ByteCount);
void btx_push_message_lttng_ust_cuda_cuMemcpyHtoA_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyAtoH_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dstHost, CUarray srcArray, unsigned int srcOffset, unsigned int ByteCount);
void btx_push_message_lttng_ust_cuda_cuMemcpyAtoH_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyAtoA_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUarray dstArray, unsigned int dstOffset, CUarray srcArray, unsigned int srcOffset, unsigned int ByteCount);
void btx_push_message_lttng_ust_cuda_cuMemcpyAtoA_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyHtoAAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUarray dstArray, unsigned int dstOffset, void * srcHost, unsigned int ByteCount, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemcpyHtoAAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyAtoHAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dstHost, CUarray srcArray, unsigned int srcOffset, unsigned int ByteCount, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemcpyAtoHAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpy2D_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUDA_MEMCPY2D_v1 * pCopy, size_t _pCopy_val_length, CUDA_MEMCPY2D_v1 * pCopy_val);
void btx_push_message_lttng_ust_cuda_cuMemcpy2D_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpy2DUnaligned_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUDA_MEMCPY2D_v1 * pCopy, size_t _pCopy_val_length, CUDA_MEMCPY2D_v1 * pCopy_val);
void btx_push_message_lttng_ust_cuda_cuMemcpy2DUnaligned_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpy3D_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUDA_MEMCPY3D_v1 * pCopy, size_t _pCopy_val_length, CUDA_MEMCPY3D_v1 * pCopy_val);
void btx_push_message_lttng_ust_cuda_cuMemcpy3D_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyHtoDAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr_v1 dstDevice, void * srcHost, unsigned int ByteCount, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemcpyHtoDAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyDtoHAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dstHost, CUdeviceptr_v1 srcDevice, unsigned int ByteCount, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemcpyDtoHAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyDtoDAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr_v1 dstDevice, CUdeviceptr_v1 srcDevice, unsigned int ByteCount, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemcpyDtoDAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpy2DAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUDA_MEMCPY2D_v1 * pCopy, CUstream hStream, size_t _pCopy_val_length, CUDA_MEMCPY2D_v1 * pCopy_val);
void btx_push_message_lttng_ust_cuda_cuMemcpy2DAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpy3DAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUDA_MEMCPY3D_v1 * pCopy, CUstream hStream, size_t _pCopy_val_length, CUDA_MEMCPY3D_v1 * pCopy_val);
void btx_push_message_lttng_ust_cuda_cuMemcpy3DAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemsetD8_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr_v1 dstDevice, unsigned char uc, unsigned int N);
void btx_push_message_lttng_ust_cuda_cuMemsetD8_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemsetD16_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr_v1 dstDevice, unsigned short int us, unsigned int N);
void btx_push_message_lttng_ust_cuda_cuMemsetD16_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemsetD32_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr_v1 dstDevice, unsigned int ui, unsigned int N);
void btx_push_message_lttng_ust_cuda_cuMemsetD32_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemsetD2D8_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr_v1 dstDevice, unsigned int dstPitch, unsigned char uc, unsigned int Width, unsigned int Height);
void btx_push_message_lttng_ust_cuda_cuMemsetD2D8_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemsetD2D16_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr_v1 dstDevice, unsigned int dstPitch, unsigned short int us, unsigned int Width, unsigned int Height);
void btx_push_message_lttng_ust_cuda_cuMemsetD2D16_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemsetD2D32_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr_v1 dstDevice, unsigned int dstPitch, unsigned int ui, unsigned int Width, unsigned int Height);
void btx_push_message_lttng_ust_cuda_cuMemsetD2D32_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuArrayCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUarray * pHandle, CUDA_ARRAY_DESCRIPTOR_v1 * pAllocateArray, size_t _pAllocateArray_val_length, CUDA_ARRAY_DESCRIPTOR_v1 * pAllocateArray_val);
void btx_push_message_lttng_ust_cuda_cuArrayCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUarray pHandle_val);
void btx_push_message_lttng_ust_cuda_cuArrayGetDescriptor_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUDA_ARRAY_DESCRIPTOR_v1 * pArrayDescriptor, CUarray hArray);
void btx_push_message_lttng_ust_cuda_cuArrayGetDescriptor_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _pArrayDescriptor_val_length, CUDA_ARRAY_DESCRIPTOR_v1 * pArrayDescriptor_val);
void btx_push_message_lttng_ust_cuda_cuArray3DCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUarray * pHandle, CUDA_ARRAY3D_DESCRIPTOR_v1 * pAllocateArray, size_t _pAllocateArray_val_length, CUDA_ARRAY3D_DESCRIPTOR_v1 * pAllocateArray_val);
void btx_push_message_lttng_ust_cuda_cuArray3DCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUarray pHandle_val);
void btx_push_message_lttng_ust_cuda_cuArray3DGetDescriptor_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUDA_ARRAY3D_DESCRIPTOR_v1 * pArrayDescriptor, CUarray hArray);
void btx_push_message_lttng_ust_cuda_cuArray3DGetDescriptor_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _pArrayDescriptor_val_length, CUDA_ARRAY3D_DESCRIPTOR_v1 * pArrayDescriptor_val);
void btx_push_message_lttng_ust_cuda_cuTexRefSetAddress_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, unsigned int * ByteOffset, CUtexref hTexRef, CUdeviceptr_v1 dptr, unsigned int bytes);
void btx_push_message_lttng_ust_cuda_cuTexRefSetAddress_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, unsigned int ByteOffset_val);
void btx_push_message_lttng_ust_cuda_cuTexRefSetAddress2D_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUtexref hTexRef, CUDA_ARRAY_DESCRIPTOR_v1 * desc, CUdeviceptr_v1 dptr, unsigned int Pitch, size_t _desc_val_length, CUDA_ARRAY_DESCRIPTOR_v1 * desc_val);
void btx_push_message_lttng_ust_cuda_cuTexRefSetAddress2D_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuTexRefGetAddress_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr_v1 * pdptr, CUtexref hTexRef);
void btx_push_message_lttng_ust_cuda_cuTexRefGetAddress_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUdeviceptr_v1 pdptr_val);
void btx_push_message_lttng_ust_cuda_cuGraphicsResourceGetMappedPointer_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr_v1 * pDevPtr, unsigned int * pSize, CUgraphicsResource resource);
void btx_push_message_lttng_ust_cuda_cuGraphicsResourceGetMappedPointer_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUdeviceptr_v1 pDevPtr_val, unsigned int pSize_val);
void btx_push_message_lttng_ust_cuda_cuCtxDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext ctx);
void btx_push_message_lttng_ust_cuda_cuCtxDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuCtxPopCurrent_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext * pctx);
void btx_push_message_lttng_ust_cuda_cuCtxPopCurrent_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUcontext pctx_val);
void btx_push_message_lttng_ust_cuda_cuCtxPushCurrent_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext ctx);
void btx_push_message_lttng_ust_cuda_cuCtxPushCurrent_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuStreamDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuEventDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUevent hEvent);
void btx_push_message_lttng_ust_cuda_cuEventDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuEventElapsedTime_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, float * pMilliseconds, CUevent hStart, CUevent hEnd);
void btx_push_message_lttng_ust_cuda_cuEventElapsedTime_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, float pMilliseconds_val);
void btx_push_message_lttng_ust_cuda_cuDevicePrimaryCtxRelease_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdevice dev);
void btx_push_message_lttng_ust_cuda_cuDevicePrimaryCtxRelease_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuDevicePrimaryCtxReset_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdevice dev);
void btx_push_message_lttng_ust_cuda_cuDevicePrimaryCtxReset_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuDevicePrimaryCtxSetFlags_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdevice dev, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuDevicePrimaryCtxSetFlags_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuDeviceGetUuid_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUuuid * uuid, CUdevice dev);
void btx_push_message_lttng_ust_cuda_cuDeviceGetUuid_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _uuid_val_length, CUuuid * uuid_val);
void btx_push_message_lttng_ust_cuda_cuMemcpyHtoD_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, void * srcHost, size_t ByteCount);
void btx_push_message_lttng_ust_cuda_cuMemcpyHtoD_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyDtoH_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dstHost, CUdeviceptr srcDevice, size_t ByteCount);
void btx_push_message_lttng_ust_cuda_cuMemcpyDtoH_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyDtoD_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, CUdeviceptr srcDevice, size_t ByteCount);
void btx_push_message_lttng_ust_cuda_cuMemcpyDtoD_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyDtoA_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUarray dstArray, size_t dstOffset, CUdeviceptr srcDevice, size_t ByteCount);
void btx_push_message_lttng_ust_cuda_cuMemcpyDtoA_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyAtoD_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, CUarray srcArray, size_t srcOffset, size_t ByteCount);
void btx_push_message_lttng_ust_cuda_cuMemcpyAtoD_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyHtoA_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUarray dstArray, size_t dstOffset, void * srcHost, size_t ByteCount);
void btx_push_message_lttng_ust_cuda_cuMemcpyHtoA_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyAtoH_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dstHost, CUarray srcArray, size_t srcOffset, size_t ByteCount);
void btx_push_message_lttng_ust_cuda_cuMemcpyAtoH_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyAtoA_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUarray dstArray, size_t dstOffset, CUarray srcArray, size_t srcOffset, size_t ByteCount);
void btx_push_message_lttng_ust_cuda_cuMemcpyAtoA_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyHtoAAsync_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUarray dstArray, size_t dstOffset, void * srcHost, size_t ByteCount, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemcpyHtoAAsync_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyAtoHAsync_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dstHost, CUarray srcArray, size_t srcOffset, size_t ByteCount, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemcpyAtoHAsync_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpy2D_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUDA_MEMCPY2D * pCopy, size_t _pCopy_val_length, CUDA_MEMCPY2D * pCopy_val);
void btx_push_message_lttng_ust_cuda_cuMemcpy2D_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpy2DUnaligned_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUDA_MEMCPY2D * pCopy, size_t _pCopy_val_length, CUDA_MEMCPY2D * pCopy_val);
void btx_push_message_lttng_ust_cuda_cuMemcpy2DUnaligned_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpy3D_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUDA_MEMCPY3D * pCopy, size_t _pCopy_val_length, CUDA_MEMCPY3D * pCopy_val);
void btx_push_message_lttng_ust_cuda_cuMemcpy3D_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyHtoDAsync_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, void * srcHost, size_t ByteCount, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemcpyHtoDAsync_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyDtoHAsync_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dstHost, CUdeviceptr srcDevice, size_t ByteCount, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemcpyDtoHAsync_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyDtoDAsync_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, CUdeviceptr srcDevice, size_t ByteCount, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemcpyDtoDAsync_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpy2DAsync_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUDA_MEMCPY2D * pCopy, CUstream hStream, size_t _pCopy_val_length, CUDA_MEMCPY2D * pCopy_val);
void btx_push_message_lttng_ust_cuda_cuMemcpy2DAsync_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpy3DAsync_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUDA_MEMCPY3D * pCopy, CUstream hStream, size_t _pCopy_val_length, CUDA_MEMCPY3D * pCopy_val);
void btx_push_message_lttng_ust_cuda_cuMemcpy3DAsync_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemsetD8_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, unsigned char uc, size_t N);
void btx_push_message_lttng_ust_cuda_cuMemsetD8_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemsetD16_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, unsigned short int us, size_t N);
void btx_push_message_lttng_ust_cuda_cuMemsetD16_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemsetD32_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, unsigned int ui, size_t N);
void btx_push_message_lttng_ust_cuda_cuMemsetD32_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemsetD2D8_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, size_t dstPitch, unsigned char uc, size_t Width, size_t Height);
void btx_push_message_lttng_ust_cuda_cuMemsetD2D8_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemsetD2D16_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, size_t dstPitch, unsigned short int us, size_t Width, size_t Height);
void btx_push_message_lttng_ust_cuda_cuMemsetD2D16_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemsetD2D32_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, size_t dstPitch, unsigned int ui, size_t Width, size_t Height);
void btx_push_message_lttng_ust_cuda_cuMemsetD2D32_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dst, CUdeviceptr src, size_t ByteCount);
void btx_push_message_lttng_ust_cuda_cuMemcpy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dst, CUdeviceptr src, size_t ByteCount, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemcpyAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyPeer_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, CUcontext dstContext, CUdeviceptr srcDevice, CUcontext srcContext, size_t ByteCount);
void btx_push_message_lttng_ust_cuda_cuMemcpyPeer_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyPeerAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, CUcontext dstContext, CUdeviceptr srcDevice, CUcontext srcContext, size_t ByteCount, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemcpyPeerAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpy3DPeer_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUDA_MEMCPY3D_PEER * pCopy, size_t _pCopy_val_length, CUDA_MEMCPY3D_PEER * pCopy_val);
void btx_push_message_lttng_ust_cuda_cuMemcpy3DPeer_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpy3DPeerAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUDA_MEMCPY3D_PEER * pCopy, CUstream hStream, size_t _pCopy_val_length, CUDA_MEMCPY3D_PEER * pCopy_val);
void btx_push_message_lttng_ust_cuda_cuMemcpy3DPeerAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpyBatchAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr * dsts, CUdeviceptr * srcs, size_t * sizes, size_t count, CUmemcpyAttributes * attrs, size_t * attrsIdxs, size_t numAttrs, size_t * failIdx, CUstream hStream, size_t _dsts_vals_length, CUdeviceptr * dsts_vals, size_t _srcs_vals_length, CUdeviceptr * srcs_vals, size_t _sizes_vals_length, size_t * sizes_vals, size_t _attrs_vals_length, CUmemcpyAttributes * attrs_vals, size_t _attrsIdxs_vals_length, size_t * attrsIdxs_vals);
void btx_push_message_lttng_ust_cuda_cuMemcpyBatchAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t failIdx_val);
void btx_push_message_lttng_ust_cuda_cuMemcpy3DBatchAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, size_t numOps, CUDA_MEMCPY3D_BATCH_OP * opList, size_t * failIdx, unsigned long long int flags, CUstream hStream, size_t _opList_vals_length, CUDA_MEMCPY3D_BATCH_OP * opList_vals);
void btx_push_message_lttng_ust_cuda_cuMemcpy3DBatchAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t failIdx_val);
void btx_push_message_lttng_ust_cuda_cuMemcpyBatchAsync_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr * dsts, CUdeviceptr * srcs, size_t * sizes, size_t count, CUmemcpyAttributes * attrs, size_t * attrsIdxs, size_t numAttrs, size_t * failIdx, CUstream hStream, size_t _dsts_vals_length, CUdeviceptr * dsts_vals, size_t _srcs_vals_length, CUdeviceptr * srcs_vals, size_t _sizes_vals_length, size_t * sizes_vals, size_t _attrs_vals_length, CUmemcpyAttributes * attrs_vals, size_t _attrsIdxs_vals_length, size_t * attrsIdxs_vals);
void btx_push_message_lttng_ust_cuda_cuMemcpyBatchAsync_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t failIdx_val);
void btx_push_message_lttng_ust_cuda_cuMemcpy3DBatchAsync_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, size_t numOps, CUDA_MEMCPY3D_BATCH_OP * opList, size_t * failIdx, unsigned long long int flags, CUstream hStream, size_t _opList_vals_length, CUDA_MEMCPY3D_BATCH_OP * opList_vals);
void btx_push_message_lttng_ust_cuda_cuMemcpy3DBatchAsync_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t failIdx_val);
void btx_push_message_lttng_ust_cuda_cuMemcpyBatchAsync_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr * dsts, CUdeviceptr * srcs, size_t * sizes, size_t count, CUmemcpyAttributes * attrs, size_t * attrsIdxs, size_t numAttrs, CUstream hStream, size_t _dsts_vals_length, CUdeviceptr * dsts_vals, size_t _srcs_vals_length, CUdeviceptr * srcs_vals, size_t _sizes_vals_length, size_t * sizes_vals, size_t _attrs_vals_length, CUmemcpyAttributes * attrs_vals, size_t _attrsIdxs_vals_length, size_t * attrsIdxs_vals);
void btx_push_message_lttng_ust_cuda_cuMemcpyBatchAsync_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemcpy3DBatchAsync_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, size_t numOps, CUDA_MEMCPY3D_BATCH_OP * opList, unsigned long long int flags, CUstream hStream, size_t _opList_vals_length, CUDA_MEMCPY3D_BATCH_OP * opList_vals);
void btx_push_message_lttng_ust_cuda_cuMemcpy3DBatchAsync_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemsetD8Async_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, unsigned char uc, size_t N, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemsetD8Async_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemsetD16Async_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, unsigned short int us, size_t N, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemsetD16Async_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemsetD32Async_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, unsigned int ui, size_t N, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemsetD32Async_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemsetD2D8Async_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, size_t dstPitch, unsigned char uc, size_t Width, size_t Height, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemsetD2D8Async_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemsetD2D16Async_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, size_t dstPitch, unsigned short int us, size_t Width, size_t Height, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemsetD2D16Async_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemsetD2D32Async_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dstDevice, size_t dstPitch, unsigned int ui, size_t Width, size_t Height, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemsetD2D32Async_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamGetPriority_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, int * priority);
void btx_push_message_lttng_ust_cuda_cuStreamGetPriority_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, int priority_val);
void btx_push_message_lttng_ust_cuda_cuStreamGetId_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, unsigned long long int * streamId);
void btx_push_message_lttng_ust_cuda_cuStreamGetId_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, unsigned long long int streamId_val);
void btx_push_message_lttng_ust_cuda_cuStreamGetFlags_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, unsigned int * flags);
void btx_push_message_lttng_ust_cuda_cuStreamGetFlags_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, unsigned int flags_val);
void btx_push_message_lttng_ust_cuda_cuStreamGetDevice_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUdevice * device);
void btx_push_message_lttng_ust_cuda_cuStreamGetDevice_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUdevice device_val);
void btx_push_message_lttng_ust_cuda_cuStreamGetCtx_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUcontext * pctx);
void btx_push_message_lttng_ust_cuda_cuStreamGetCtx_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUcontext pctx_val);
void btx_push_message_lttng_ust_cuda_cuStreamGetCtx_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUcontext * pCtx, CUgreenCtx * pGreenCtx);
void btx_push_message_lttng_ust_cuda_cuStreamGetCtx_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUcontext pCtx_val, CUgreenCtx pGreenCtx_val);
void btx_push_message_lttng_ust_cuda_cuStreamWaitEvent_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUevent hEvent, unsigned int Flags);
void btx_push_message_lttng_ust_cuda_cuStreamWaitEvent_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamAddCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUstreamCallback callback, void * userData, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuStreamAddCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamAttachMemAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUdeviceptr dptr, size_t length, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuStreamAttachMemAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamQuery_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuStreamQuery_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamSynchronize_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuStreamSynchronize_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuEventRecord_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUevent hEvent, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuEventRecord_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuEventRecordWithFlags_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUevent hEvent, CUstream hStream, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuEventRecordWithFlags_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuLaunchKernel_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUfunction f, unsigned int gridDimX, unsigned int gridDimY, unsigned int gridDimZ, unsigned int blockDimX, unsigned int blockDimY, unsigned int blockDimZ, unsigned int sharedMemBytes, CUstream hStream, void ** kernelParams, void ** extra, size_t _extra_vals_length, void * * extra_vals);
void btx_push_message_lttng_ust_cuda_cuLaunchKernel_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuLaunchKernelEx_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUlaunchConfig * config, CUfunction f, void ** kernelParams, void ** extra, size_t _config_val_length, CUlaunchConfig * config_val, size_t _config__attrs_vals_length, CUlaunchAttribute * config__attrs_vals, size_t _extra_vals_length, void * * extra_vals);
void btx_push_message_lttng_ust_cuda_cuLaunchKernelEx_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuLaunchHostFunc_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUhostFn fn, void * userData);
void btx_push_message_lttng_ust_cuda_cuLaunchHostFunc_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphicsMapResources_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, unsigned int count, CUgraphicsResource * resources, CUstream hStream, size_t _resources_vals_length, CUgraphicsResource * resources_vals);
void btx_push_message_lttng_ust_cuda_cuGraphicsMapResources_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphicsUnmapResources_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, unsigned int count, CUgraphicsResource * resources, CUstream hStream, size_t _resources_vals_length, CUgraphicsResource * resources_vals);
void btx_push_message_lttng_ust_cuda_cuGraphicsUnmapResources_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamWriteValue32_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuStreamWriteValue32_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamWaitValue32_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuStreamWaitValue32_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamWriteValue64_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuStreamWriteValue64_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamWaitValue64_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuStreamWaitValue64_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamBatchMemOp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream stream, unsigned int count, CUstreamBatchMemOpParams * paramArray, unsigned int flags, size_t _paramArray_vals_length, CUstreamBatchMemOpParams * paramArray_vals);
void btx_push_message_lttng_ust_cuda_cuStreamBatchMemOp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamWriteValue32_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuStreamWriteValue32_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamWaitValue32_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuStreamWaitValue32_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamWriteValue64_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuStreamWriteValue64_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamWaitValue64_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuStreamWaitValue64_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamBatchMemOp_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream stream, unsigned int count, CUstreamBatchMemOpParams * paramArray, unsigned int flags, size_t _paramArray_vals_length, CUstreamBatchMemOpParams * paramArray_vals);
void btx_push_message_lttng_ust_cuda_cuStreamBatchMemOp_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamWriteValue32_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuStreamWriteValue32_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamWaitValue32_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuStreamWaitValue32_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamWriteValue64_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuStreamWriteValue64_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamWaitValue64_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuStreamWaitValue64_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamBatchMemOp_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream stream, unsigned int count, CUstreamBatchMemOpParams * paramArray, unsigned int flags, size_t _paramArray_vals_length, CUstreamBatchMemOpParams * paramArray_vals);
void btx_push_message_lttng_ust_cuda_cuStreamBatchMemOp_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemPrefetchAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr devPtr, size_t count, CUdevice dstDevice, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemPrefetchAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemPrefetchAsync_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr devPtr, size_t count, CUdevice dstDevice, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemPrefetchAsync_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemPrefetchAsync_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr devPtr, size_t count, CUmemLocation location, unsigned int flags, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemPrefetchAsync_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemAdvise_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr devPtr, size_t count, CUmem_advise advice, CUdevice device);
void btx_push_message_lttng_ust_cuda_cuMemAdvise_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemPrefetchBatchAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr * dptrs, size_t * sizes, size_t count, CUmemLocation * prefetchLocs, size_t * prefetchLocIdxs, size_t numPrefetchLocs, unsigned long long int flags, CUstream hStream, size_t _dptrs_vals_length, CUdeviceptr * dptrs_vals, size_t _sizes_vals_length, size_t * sizes_vals, size_t _prefetchLocs_vals_length, CUmemLocation * prefetchLocs_vals, size_t _prefetchLocIdxs_vals_length, size_t * prefetchLocIdxs_vals);
void btx_push_message_lttng_ust_cuda_cuMemPrefetchBatchAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemDiscardBatchAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr * dptrs, size_t * sizes, size_t count, unsigned long long int flags, CUstream hStream, size_t _dptrs_vals_length, CUdeviceptr * dptrs_vals, size_t _sizes_vals_length, size_t * sizes_vals);
void btx_push_message_lttng_ust_cuda_cuMemDiscardBatchAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemDiscardAndPrefetchBatchAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr * dptrs, size_t * sizes, size_t count, CUmemLocation * prefetchLocs, size_t * prefetchLocIdxs, size_t numPrefetchLocs, unsigned long long int flags, CUstream hStream, size_t _dptrs_vals_length, CUdeviceptr * dptrs_vals, size_t _sizes_vals_length, size_t * sizes_vals, size_t _prefetchLocs_vals_length, CUmemLocation * prefetchLocs_vals, size_t _prefetchLocIdxs_vals_length, size_t * prefetchLocIdxs_vals);
void btx_push_message_lttng_ust_cuda_cuMemDiscardAndPrefetchBatchAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuLaunchCooperativeKernel_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUfunction f, unsigned int gridDimX, unsigned int gridDimY, unsigned int gridDimZ, unsigned int blockDimX, unsigned int blockDimY, unsigned int blockDimZ, unsigned int sharedMemBytes, CUstream hStream, void ** kernelParams);
void btx_push_message_lttng_ust_cuda_cuLaunchCooperativeKernel_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuSignalExternalSemaphoresAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUexternalSemaphore * extSemArray, CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS * paramsArray, unsigned int numExtSems, CUstream stream, size_t _extSemArray_vals_length, CUexternalSemaphore * extSemArray_vals, size_t _paramsArray_vals_length, CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS * paramsArray_vals);
void btx_push_message_lttng_ust_cuda_cuSignalExternalSemaphoresAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuWaitExternalSemaphoresAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUexternalSemaphore * extSemArray, CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS * paramsArray, unsigned int numExtSems, CUstream stream, size_t _extSemArray_vals_length, CUexternalSemaphore * extSemArray_vals, size_t _paramsArray_vals_length, CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS * paramsArray_vals);
void btx_push_message_lttng_ust_cuda_cuWaitExternalSemaphoresAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamBeginCapture_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuStreamBeginCapture_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamBeginCapture_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuStreamBeginCapture_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamBeginCapture_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUstreamCaptureMode mode);
void btx_push_message_lttng_ust_cuda_cuStreamBeginCapture_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamBeginCaptureToGraph_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUgraph hGraph, CUgraphNode * dependencies, CUgraphEdgeData * dependencyData, size_t numDependencies, CUstreamCaptureMode mode, size_t _dependencies_vals_length, CUgraphNode * dependencies_vals, size_t _dependencyData_vals_length, CUgraphEdgeData * dependencyData_vals);
void btx_push_message_lttng_ust_cuda_cuStreamBeginCaptureToGraph_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamEndCapture_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUgraph * phGraph);
void btx_push_message_lttng_ust_cuda_cuStreamEndCapture_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUgraph phGraph_val);
void btx_push_message_lttng_ust_cuda_cuStreamIsCapturing_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUstreamCaptureStatus * captureStatus);
void btx_push_message_lttng_ust_cuda_cuStreamIsCapturing_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUstreamCaptureStatus captureStatus_val);
void btx_push_message_lttng_ust_cuda_cuStreamGetCaptureInfo_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUstreamCaptureStatus * captureStatus_out, cuuint64_t * id_out);
void btx_push_message_lttng_ust_cuda_cuStreamGetCaptureInfo_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUstreamCaptureStatus captureStatus_out_val, cuuint64_t id_out_val);
void btx_push_message_lttng_ust_cuda_cuStreamGetCaptureInfo_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUstreamCaptureStatus * captureStatus_out, cuuint64_t * id_out);
void btx_push_message_lttng_ust_cuda_cuStreamGetCaptureInfo_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUstreamCaptureStatus captureStatus_out_val, cuuint64_t id_out_val);
void btx_push_message_lttng_ust_cuda_cuStreamGetCaptureInfo_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUstreamCaptureStatus * captureStatus_out, cuuint64_t * id_out, CUgraph * graph_out, CUgraphNode ** dependencies_out, size_t * numDependencies_out);
void btx_push_message_lttng_ust_cuda_cuStreamGetCaptureInfo_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUstreamCaptureStatus captureStatus_out_val, cuuint64_t id_out_val, CUgraph graph_out_val, CUgraphNode * dependencies_out_val, size_t numDependencies_out_val, size_t _dependencies_out_val_vals_length, CUgraphNode * dependencies_out_val_vals);
void btx_push_message_lttng_ust_cuda_cuStreamGetCaptureInfo_v2_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUstreamCaptureStatus * captureStatus_out, cuuint64_t * id_out, CUgraph * graph_out, CUgraphNode ** dependencies_out, size_t * numDependencies_out);
void btx_push_message_lttng_ust_cuda_cuStreamGetCaptureInfo_v2_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUstreamCaptureStatus captureStatus_out_val, cuuint64_t id_out_val, CUgraph graph_out_val, CUgraphNode * dependencies_out_val, size_t numDependencies_out_val, size_t _dependencies_out_val_vals_length, CUgraphNode * dependencies_out_val_vals);
void btx_push_message_lttng_ust_cuda_cuStreamGetCaptureInfo_v3_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUstreamCaptureStatus * captureStatus_out, cuuint64_t * id_out, CUgraph * graph_out, CUgraphNode ** dependencies_out, CUgraphEdgeData ** edgeData_out, size_t * numDependencies_out);
void btx_push_message_lttng_ust_cuda_cuStreamGetCaptureInfo_v3_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUstreamCaptureStatus captureStatus_out_val, cuuint64_t id_out_val, CUgraph graph_out_val, size_t numDependencies_out_val, size_t _dependencies_out_val_vals_length, CUgraphNode * dependencies_out_val_vals, size_t _edgeData_out_val_vals_length, CUgraphEdgeData * edgeData_out_val_vals);
void btx_push_message_lttng_ust_cuda_cuGraphAddKernelNode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode * phGraphNode, CUgraph hGraph, CUgraphNode * dependencies, size_t numDependencies, CUDA_KERNEL_NODE_PARAMS_v1 * nodeParams, size_t _dependencies_vals_length, CUgraphNode * dependencies_vals, size_t _nodeParams_val_length, CUDA_KERNEL_NODE_PARAMS_v1 * nodeParams_val, size_t _nodeParams__extra_vals_length, void * * nodeParams__extra_vals);
void btx_push_message_lttng_ust_cuda_cuGraphAddKernelNode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUgraphNode phGraphNode_val);
void btx_push_message_lttng_ust_cuda_cuGraphKernelNodeGetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode hNode, CUDA_KERNEL_NODE_PARAMS_v1 * nodeParams);
void btx_push_message_lttng_ust_cuda_cuGraphKernelNodeGetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _nodeParams_val_length, CUDA_KERNEL_NODE_PARAMS_v1 * nodeParams_val, size_t _nodeParams__extra_vals_length, void * * nodeParams__extra_vals);
void btx_push_message_lttng_ust_cuda_cuGraphKernelNodeSetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode hNode, CUDA_KERNEL_NODE_PARAMS_v1 * nodeParams, size_t _nodeParams_val_length, CUDA_KERNEL_NODE_PARAMS_v1 * nodeParams_val, size_t _nodeParams__extra_vals_length, void * * nodeParams__extra_vals);
void btx_push_message_lttng_ust_cuda_cuGraphKernelNodeSetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphExecKernelNodeSetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphExec hGraphExec, CUgraphNode hNode, CUDA_KERNEL_NODE_PARAMS_v1 * nodeParams, size_t _nodeParams_val_length, CUDA_KERNEL_NODE_PARAMS_v1 * nodeParams_val, size_t _nodeParams__extra_vals_length, void * * nodeParams__extra_vals);
void btx_push_message_lttng_ust_cuda_cuGraphExecKernelNodeSetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphInstantiateWithParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphExec * phGraphExec, CUgraph hGraph, CUDA_GRAPH_INSTANTIATE_PARAMS * instantiateParams, size_t _instantiateParams_val_length, CUDA_GRAPH_INSTANTIATE_PARAMS * instantiateParams_val);
void btx_push_message_lttng_ust_cuda_cuGraphInstantiateWithParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUgraphExec phGraphExec_val);
void btx_push_message_lttng_ust_cuda_cuGraphExecUpdate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphExec hGraphExec, CUgraph hGraph, CUgraphNode * hErrorNode_out, CUgraphExecUpdateResult * updateResult_out);
void btx_push_message_lttng_ust_cuda_cuGraphExecUpdate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUgraphNode hErrorNode_out_val, CUgraphExecUpdateResult updateResult_out_val);
void btx_push_message_lttng_ust_cuda_cuGraphUpload_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphExec hGraph, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuGraphUpload_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphLaunch_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphExec hGraph, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuGraphLaunch_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphGetEdges_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraph hGraph, CUgraphNode * from, CUgraphNode * to, size_t * numEdges, size_t numEdges_val);
void btx_push_message_lttng_ust_cuda_cuGraphGetEdges_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t numEdges_val, size_t _from_vals_length, CUgraphNode * from_vals, size_t _to_vals_length, CUgraphNode * to_vals);
void btx_push_message_lttng_ust_cuda_cuGraphNodeGetDependencies_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode hNode, CUgraphNode * dependencies, size_t * numDependencies, size_t numDependencies_val);
void btx_push_message_lttng_ust_cuda_cuGraphNodeGetDependencies_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t numDependencies_val, size_t _dependencies_vals_length, CUgraphNode * dependencies_vals);
void btx_push_message_lttng_ust_cuda_cuGraphNodeGetDependentNodes_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode hNode, CUgraphNode * dependentNodes, size_t * numDependentNodes, size_t numDependentNodes_val);
void btx_push_message_lttng_ust_cuda_cuGraphNodeGetDependentNodes_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t numDependentNodes_val, size_t _dependentNodes_vals_length, CUgraphNode * dependentNodes_vals);
void btx_push_message_lttng_ust_cuda_cuGraphAddDependencies_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraph hGraph, CUgraphNode * from, CUgraphNode * to, size_t numDependencies, size_t _from_vals_length, CUgraphNode * from_vals, size_t _to_vals_length, CUgraphNode * to_vals);
void btx_push_message_lttng_ust_cuda_cuGraphAddDependencies_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphRemoveDependencies_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraph hGraph, CUgraphNode * from, CUgraphNode * to, size_t numDependencies, size_t _from_vals_length, CUgraphNode * from_vals, size_t _to_vals_length, CUgraphNode * to_vals);
void btx_push_message_lttng_ust_cuda_cuGraphRemoveDependencies_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphAddNode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphNode * phGraphNode, CUgraph hGraph, CUgraphNode * dependencies, size_t numDependencies, CUgraphNodeParams * nodeParams, size_t _dependencies_vals_length, CUgraphNode * dependencies_vals, size_t _nodeParams_val_length, CUgraphNodeParams * nodeParams_val);
void btx_push_message_lttng_ust_cuda_cuGraphAddNode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUgraphNode phGraphNode_val);
void btx_push_message_lttng_ust_cuda_cuStreamCopyAttributes_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream dstStream, CUstream srcStream);
void btx_push_message_lttng_ust_cuda_cuStreamCopyAttributes_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamGetAttribute_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUstreamAttrID attr, CUstreamAttrValue * value);
void btx_push_message_lttng_ust_cuda_cuStreamGetAttribute_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _value_val_length, CUstreamAttrValue * value_val);
void btx_push_message_lttng_ust_cuda_cuStreamSetAttribute_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUstreamAttrID attr, CUstreamAttrValue * param, size_t _param_val_length, CUstreamAttrValue * param_val);
void btx_push_message_lttng_ust_cuda_cuStreamSetAttribute_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuIpcOpenMemHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr * pdptr, CUipcMemHandle handle, unsigned int Flags);
void btx_push_message_lttng_ust_cuda_cuIpcOpenMemHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUdeviceptr pdptr_val);
void btx_push_message_lttng_ust_cuda_cuGraphInstantiate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphExec * phGraphExec, CUgraph hGraph, CUgraphNode * phErrorNode, char * logBuffer, size_t bufferSize);
void btx_push_message_lttng_ust_cuda_cuGraphInstantiate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUgraphExec phGraphExec_val, CUgraphNode phErrorNode_val, size_t _logBuffer_vals_length, char * logBuffer_vals);
void btx_push_message_lttng_ust_cuda_cuGraphInstantiate_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphExec * phGraphExec, CUgraph hGraph, CUgraphNode * phErrorNode, char * logBuffer, size_t bufferSize);
void btx_push_message_lttng_ust_cuda_cuGraphInstantiate_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUgraphExec phGraphExec_val, CUgraphNode phErrorNode_val, size_t _logBuffer_vals_length, char * logBuffer_vals);
void btx_push_message_lttng_ust_cuda_cuMemMapArrayAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUarrayMapInfo * mapInfoList, unsigned int count, CUstream hStream, size_t _mapInfoList_vals_length, CUarrayMapInfo * mapInfoList_vals);
void btx_push_message_lttng_ust_cuda_cuMemMapArrayAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemFreeAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr dptr, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemFreeAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemAllocAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr * dptr, size_t bytesize, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemAllocAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUdeviceptr dptr_val);
void btx_push_message_lttng_ust_cuda_cuMemAllocFromPoolAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdeviceptr * dptr, size_t bytesize, CUmemoryPool pool, CUstream hStream);
void btx_push_message_lttng_ust_cuda_cuMemAllocFromPoolAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUdeviceptr dptr_val);
void btx_push_message_lttng_ust_cuda_cuStreamUpdateCaptureDependencies_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUgraphNode * dependencies, size_t numDependencies, unsigned int flags, size_t _dependencies_vals_length, CUgraphNode * dependencies_vals);
void btx_push_message_lttng_ust_cuda_cuStreamUpdateCaptureDependencies_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamUpdateCaptureDependencies_ptsz_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUgraphNode * dependencies, size_t numDependencies, unsigned int flags, size_t _dependencies_vals_length, CUgraphNode * dependencies_vals);
void btx_push_message_lttng_ust_cuda_cuStreamUpdateCaptureDependencies_ptsz_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuStreamUpdateCaptureDependencies_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUstream hStream, CUgraphNode * dependencies, CUgraphEdgeData * dependencyData, size_t numDependencies, unsigned int flags, size_t _dependencies_vals_length, CUgraphNode * dependencies_vals, size_t _dependencyData_vals_length, CUgraphEdgeData * dependencyData_vals);
void btx_push_message_lttng_ust_cuda_cuStreamUpdateCaptureDependencies_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuMemBatchDecompressAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmemDecompressParams * paramsArray, size_t count, unsigned int flags, size_t * errorIndex, CUstream stream, size_t _paramsArray_vals_length, CUmemDecompressParams * paramsArray_vals);
void btx_push_message_lttng_ust_cuda_cuMemBatchDecompressAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t errorIndex_val);
void btx_push_message_lttng_ust_cuda_cuGetProcAddress_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, char * symbol, void ** pfn, int cudaVersion, cuuint64_t flags, char * symbol_val);
void btx_push_message_lttng_ust_cuda_cuGetProcAddress_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, void * pfn_val);
void btx_push_message_lttng_ust_cuda_cuCheckpointProcessGetRestoreThreadId_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int pid, int * tid);
void btx_push_message_lttng_ust_cuda_cuCheckpointProcessGetRestoreThreadId_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, int tid_val);
void btx_push_message_lttng_ust_cuda_cuCheckpointProcessGetState_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int pid, CUprocessState * state);
void btx_push_message_lttng_ust_cuda_cuCheckpointProcessGetState_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUprocessState state_val);
void btx_push_message_lttng_ust_cuda_cuCheckpointProcessLock_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int pid, CUcheckpointLockArgs * args, size_t _args_val_length, CUcheckpointLockArgs * args_val);
void btx_push_message_lttng_ust_cuda_cuCheckpointProcessLock_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuCheckpointProcessCheckpoint_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int pid, CUcheckpointCheckpointArgs * args, size_t _args_val_length, CUcheckpointCheckpointArgs * args_val);
void btx_push_message_lttng_ust_cuda_cuCheckpointProcessCheckpoint_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuCheckpointProcessRestore_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int pid, CUcheckpointRestoreArgs * args, size_t _args_val_length, CUcheckpointRestoreArgs * args_val, size_t _args__gpuPairs_vals_length, CUcheckpointGpuPair * args__gpuPairs_vals);
void btx_push_message_lttng_ust_cuda_cuCheckpointProcessRestore_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuCheckpointProcessUnlock_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int pid, CUcheckpointUnlockArgs * args, size_t _args_val_length, CUcheckpointUnlockArgs * args_val);
void btx_push_message_lttng_ust_cuda_cuCheckpointProcessUnlock_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuVDPAUGetDevice_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdevice * pDevice, VdpDevice vdpDevice, VdpGetProcAddress * vdpGetProcAddress);
void btx_push_message_lttng_ust_cuda_cuVDPAUGetDevice_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuVDPAUCtxCreate_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext * pCtx, unsigned int flags, CUdevice device, VdpDevice vdpDevice, VdpGetProcAddress * vdpGetProcAddress);
void btx_push_message_lttng_ust_cuda_cuVDPAUCtxCreate_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphicsVDPAURegisterVideoSurface_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphicsResource * pCudaResource, VdpVideoSurface vdpSurface, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuGraphicsVDPAURegisterVideoSurface_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuGraphicsVDPAURegisterOutputSurface_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUgraphicsResource * pCudaResource, VdpOutputSurface vdpSurface, unsigned int flags);
void btx_push_message_lttng_ust_cuda_cuGraphicsVDPAURegisterOutputSurface_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuVDPAUCtxCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext * pCtx, unsigned int flags, CUdevice device, VdpDevice vdpDevice, VdpGetProcAddress * vdpGetProcAddress);
void btx_push_message_lttng_ust_cuda_cuVDPAUCtxCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuProfilerInitialize_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, char * configFile, char * outputFile, CUoutput_mode outputMode);
void btx_push_message_lttng_ust_cuda_cuProfilerInitialize_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuProfilerStart_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_cuda_cuProfilerStart_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_cuProfilerStop_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_cuda_cuProfilerStop_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_exports_cuexp_function_get_name_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext hContext, CUfunction hFunction, char ** pName);
void btx_push_message_lttng_ust_cuda_exports_cuexp_function_get_name_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, char * pName_val, char * pName_val_val);
void btx_push_message_lttng_ust_cuda_exports_cuexpFunction_setCacheConfig_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUfunction hFunction, CUfunc_cache config);
void btx_push_message_lttng_ust_cuda_exports_cuexpFunction_setCacheConfig_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_exports_cuexp_6e163fbe_d8_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmodule hModule, int * pB);
void btx_push_message_lttng_ust_cuda_exports_cuexp_6e163fbe_d8_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, int pB_val);
void btx_push_message_lttng_ust_cuda_exports_cuexpFunction_get_arg_count_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUfunction hFunction, size_t * pArgCount);
void btx_push_message_lttng_ust_cuda_exports_cuexpFunction_get_arg_count_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t pArgCount_val);
void btx_push_message_lttng_ust_cuda_exports_cuexpFunction_get_arg_descriptor_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUfunction hFunction, size_t argIndex, cuexp_function_arg_desc_query * pArgDescQuery);
void btx_push_message_lttng_ust_cuda_exports_cuexpFunction_get_arg_descriptor_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _pArgDescQuery_val_length, cuexp_function_arg_desc_query * pArgDescQuery_val);
void btx_push_message_lttng_ust_cuda_exports_cuexp_6e163fbe_130_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void ** pA, CUfunction hFunction);
void btx_push_message_lttng_ust_cuda_exports_cuexp_6e163fbe_130_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, void * pA_val);
void btx_push_message_lttng_ust_cuda_exports_cuexp_module_iterate_on_functions_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext hContext, CUmodule hModule, void * pFunc, void * userData);
void btx_push_message_lttng_ust_cuda_exports_cuexp_module_iterate_on_functions_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_exports_cuexp_6e163fbe_1a8_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUfunction hFunction, int * pB);
void btx_push_message_lttng_ust_cuda_exports_cuexp_6e163fbe_1a8_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, int pB_val);
void btx_push_message_lttng_ust_cuda_exports_cuexp_6e163fbe_1b8_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUfunction hFunction, unsigned long int * pB);
void btx_push_message_lttng_ust_cuda_exports_cuexp_6e163fbe_1b8_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, unsigned long int pB_val);
void btx_push_message_lttng_ust_cuda_exports_cuexpDevice_get_primary_context_refcount_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdevice device);
void btx_push_message_lttng_ust_cuda_exports_cuexpDevice_get_primary_context_refcount_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, unsigned int cuResult);
void btx_push_message_lttng_ust_cuda_exports_cuexp_get_thread_context_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext * phContext);
void btx_push_message_lttng_ust_cuda_exports_cuexp_get_thread_context_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUcontext phContext_val);
void btx_push_message_lttng_ust_cuda_exports_cuexp_a094798c_08_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, unsigned int a, void ** b, void * b_val);
void btx_push_message_lttng_ust_cuda_exports_cuexp_a094798c_08_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, void * b_val);
void btx_push_message_lttng_ust_cuda_exports_cuexp_a094798c_10_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void ** a, size_t * b);
void btx_push_message_lttng_ust_cuda_exports_cuexp_a094798c_10_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * a_val, size_t b_val);
void btx_push_message_lttng_ust_cuda_exports_cuexp_a094798c_18_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext hContext, void * a, void ** b);
void btx_push_message_lttng_ust_cuda_exports_cuexp_a094798c_18_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, void * b_val);
void btx_push_message_lttng_ust_cuda_exports_cuexp_a094798c_20_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext hContext, uint64_t * b);
void btx_push_message_lttng_ust_cuda_exports_cuexp_a094798c_20_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, uint64_t b_val);
void btx_push_message_lttng_ust_cuda_exports_cuexp_a094798c_28_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, unsigned int a, void * b);
void btx_push_message_lttng_ust_cuda_exports_cuexp_a094798c_28_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_exports_cuexp_a094798c_30_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void ** a, size_t * b);
void btx_push_message_lttng_ust_cuda_exports_cuexp_a094798c_30_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * a_val, size_t b_val);
void btx_push_message_lttng_ust_cuda_exports_cuexpContext_kvstore_add_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext hContext, void * handle, void * value, void * unknown);
void btx_push_message_lttng_ust_cuda_exports_cuexpContext_kvstore_add_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_exports_cuexpContext_kvstore_delete_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext hContext, void * handle);
void btx_push_message_lttng_ust_cuda_exports_cuexpContext_kvstore_delete_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_exports_cuexpContext_kvstore_get_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void ** value, CUcontext hContext, void * handle);
void btx_push_message_lttng_ust_cuda_exports_cuexpContext_kvstore_get_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, void * value_val);
void btx_push_message_lttng_ust_cuda_exports_cuexp_get_primary_context_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext * phContext, unsigned int ordinal);
void btx_push_message_lttng_ust_cuda_exports_cuexp_get_primary_context_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUcontext phContext_val);
void btx_push_message_lttng_ust_cuda_exports_cuexp_register_module_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUmodule * phModule, int * fatBinary, void * a, void * b, unsigned int ordinal);
void btx_push_message_lttng_ust_cuda_exports_cuexp_register_module_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUmodule phModule_val);
void btx_push_message_lttng_ust_cuda_exports_cuexp_unregister_module_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * fatBinary);
void btx_push_message_lttng_ust_cuda_exports_cuexp_unregister_module_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_cuda_exports_cuexpContext_getDevice_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext hContext, CUdevice * pDevice);
void btx_push_message_lttng_ust_cuda_exports_cuexpContext_getDevice_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUdevice pDevice_val);
void btx_push_message_lttng_ust_cuda_exports_cuexpContext_getContextNumber_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext hContext, unsigned long int * contextNumber);
void btx_push_message_lttng_ust_cuda_exports_cuexpContext_getContextNumber_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, unsigned long int contextNumber_val);
void btx_push_message_lttng_ust_cuda_exports_cuexp_21318c60_80_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * a, void ** pB);
void btx_push_message_lttng_ust_cuda_exports_cuexp_21318c60_80_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, void * pB_val);
void btx_push_message_lttng_ust_cuda_exports_cuexp_21318c60_138_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUcontext hContext, void * b, void ** pC);
void btx_push_message_lttng_ust_cuda_exports_cuexp_21318c60_138_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, void * pC_val);
void btx_push_message_lttng_ust_cuda_exports_cuexpDevice_get_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdevice * pDevice, int ordinal);
void btx_push_message_lttng_ust_cuda_exports_cuexpDevice_get_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, CUdevice pDevice_val);
void btx_push_message_lttng_ust_cuda_exports_cuexpDevice_getCount_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, unsigned int * pCount);
void btx_push_message_lttng_ust_cuda_exports_cuexpDevice_getCount_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, unsigned int pCount_val);
void btx_push_message_lttng_ust_cuda_exports_cuexpDevice_getAttribute_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int ordinal, CUdevice_attribute attrib, int flag, long int * pl);
void btx_push_message_lttng_ust_cuda_exports_cuexpDevice_getAttribute_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, long int pl_val);
void btx_push_message_lttng_ust_cuda_exports_cuexp_b10541e1_30_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdevice device, void ** pB);
void btx_push_message_lttng_ust_cuda_exports_cuexp_b10541e1_30_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, void * pB_val);
void btx_push_message_lttng_ust_cuda_exports_cuexp_b10541e1_40_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, unsigned int * pRes, CUdevice device);
void btx_push_message_lttng_ust_cuda_exports_cuexp_b10541e1_40_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, unsigned int pRes_val);
void btx_push_message_lttng_ust_cuda_exports_cuexp_a6b1ff99_28_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void ** a, CUcontext hContext);
void btx_push_message_lttng_ust_cuda_exports_cuexp_a6b1ff99_28_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, void * a_val);
void btx_push_message_lttng_ust_cuda_exports_cuexp_127d4831_28_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * h, int a, void ** pB, void * param_4, void * pB_val);
void btx_push_message_lttng_ust_cuda_exports_cuexp_127d4831_28_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, void * pB_val);
void btx_push_message_lttng_ust_cuda_exports_cuexp_127d4831_30_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * h, int a, void ** pB, void * pB_val);
void btx_push_message_lttng_ust_cuda_exports_cuexp_127d4831_30_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, void * pB_val);
void btx_push_message_lttng_ust_cuda_exports_cuexpCUPTI_init_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_cuda_exports_cuexpCUPTI_init_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_exports_cuexp_7cb63f9b_1e0_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUdevice device, cuexp_7cb63f9b_1e0_struct * b, size_t _b_val_length, cuexp_7cb63f9b_1e0_struct * b_val);
void btx_push_message_lttng_ust_cuda_exports_cuexp_7cb63f9b_1e0_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, size_t _b_val_length, cuexp_7cb63f9b_1e0_struct * b_val);
void btx_push_message_lttng_ust_cuda_exports_cuexp_2c8e0ad8_18_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * pRes, void * a, void * b);
void btx_push_message_lttng_ust_cuda_exports_cuexp_2c8e0ad8_18_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, int pRes_val);
void btx_push_message_lttng_ust_cuda_exports_cuexp_2c8e0ad8_38_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int a, int b, unsigned int c);
void btx_push_message_lttng_ust_cuda_exports_cuexp_2c8e0ad8_38_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult);
void btx_push_message_lttng_ust_cuda_exports_cuexp_getCudaState_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * pState);
void btx_push_message_lttng_ust_cuda_exports_cuexp_getCudaState_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUresult cuResult, int pState_val);
void btx_push_message_lttng_ust_cuda_args_arg_count(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUfunction f, size_t argCount);
void btx_push_message_lttng_ust_cuda_args_arg_value(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUfunction f, size_t argIndex, void * kernelParam, size_t _kernelParam_val_length, void * kernelParam_val);
void btx_push_message_lttng_ust_cuda_profiling_event_profiling(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUevent hStart, CUevent hStop);
void btx_push_message_lttng_ust_cuda_profiling_event_profiling_results(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUevent hStart, CUevent hStop, CUresult startStatus, CUresult stopStatus, CUresult status, float milliseconds);
void btx_push_message_lttng_ust_cuda_exports_export_called(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, CUuuid * pExportTableId, size_t exportOffset, size_t _pExportTableId_val_length, CUuuid * pExportTableId_val);
void btx_push_message_lttng_ust_cuda_properties_device(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int ordinal, CUdevice device, char * name, size_t _uuid_length, CUuuid * uuid);


void btx_downstream_set_environment_hostname(
    void *btx_handle, const char* hostname);

#ifdef __cplusplus
}
#endif
