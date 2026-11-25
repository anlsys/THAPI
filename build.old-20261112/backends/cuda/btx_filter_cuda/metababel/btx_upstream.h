#pragma once
#include <metababel/btx_component.h>
#ifdef __cplusplus
extern "C" {
#endif

// Dispatcher
typedef void(dispatcher_t)(callbacks_t *callbacks, common_data_t *common_data,
                           const bt_message *upstream_message);

typedef void lttng_ust_cuda_cuGetErrorString_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, char **);

void btx_register_callbacks_lttng_ust_cuda_cuGetErrorString_entry(
    void *btx_handle, lttng_ust_cuda_cuGetErrorString_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGetErrorString_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, char *, char *);

void btx_register_callbacks_lttng_ust_cuda_cuGetErrorString_exit(
    void *btx_handle, lttng_ust_cuda_cuGetErrorString_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGetErrorName_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, char **);

void btx_register_callbacks_lttng_ust_cuda_cuGetErrorName_entry(
    void *btx_handle, lttng_ust_cuda_cuGetErrorName_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGetErrorName_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, char *, char *);

void btx_register_callbacks_lttng_ust_cuda_cuGetErrorName_exit(
    void *btx_handle, lttng_ust_cuda_cuGetErrorName_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuInit_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuInit_entry(
    void *btx_handle, lttng_ust_cuda_cuInit_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuInit_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuInit_exit(
    void *btx_handle, lttng_ust_cuda_cuInit_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDriverGetVersion_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *);

void btx_register_callbacks_lttng_ust_cuda_cuDriverGetVersion_entry(
    void *btx_handle, lttng_ust_cuda_cuDriverGetVersion_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDriverGetVersion_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, int);

void btx_register_callbacks_lttng_ust_cuda_cuDriverGetVersion_exit(
    void *btx_handle, lttng_ust_cuda_cuDriverGetVersion_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGet_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdevice *, int);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGet_entry(
    void *btx_handle, lttng_ust_cuda_cuDeviceGet_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGet_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGet_exit(
    void *btx_handle, lttng_ust_cuda_cuDeviceGet_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetCount_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetCount_entry(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetCount_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetCount_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, int);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetCount_exit(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetCount_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetName_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, int, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetName_entry(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetName_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetName_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, char *);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetName_exit(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetName_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetUuid_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUuuid *, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetUuid_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetUuid_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetUuid_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUuuid *);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetUuid_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetUuid_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetLuid_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, unsigned int *, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetLuid_entry(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetLuid_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetLuid_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, char *, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetLuid_exit(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetLuid_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceTotalMem_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, size_t *, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceTotalMem_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuDeviceTotalMem_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceTotalMem_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceTotalMem_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuDeviceTotalMem_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetTexture1DLinearMaxWidth_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, size_t *, CUarray_format, unsigned int, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetTexture1DLinearMaxWidth_entry(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetTexture1DLinearMaxWidth_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetTexture1DLinearMaxWidth_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetTexture1DLinearMaxWidth_exit(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetTexture1DLinearMaxWidth_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetAttribute_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, CUdevice_attribute, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetAttribute_entry(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetAttribute_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetAttribute_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, int);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetAttribute_exit(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetAttribute_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetHostAtomicCapabilities_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, unsigned int *, CUatomicOperation *, unsigned int, CUdevice, size_t, CUatomicOperation *);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetHostAtomicCapabilities_entry(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetHostAtomicCapabilities_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetHostAtomicCapabilities_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, unsigned int *);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetHostAtomicCapabilities_exit(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetHostAtomicCapabilities_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetNvSciSyncAttributes_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, CUdevice, int);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetNvSciSyncAttributes_entry(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetNvSciSyncAttributes_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetNvSciSyncAttributes_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetNvSciSyncAttributes_exit(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetNvSciSyncAttributes_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceSetMemPool_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdevice, CUmemoryPool);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceSetMemPool_entry(
    void *btx_handle, lttng_ust_cuda_cuDeviceSetMemPool_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceSetMemPool_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceSetMemPool_exit(
    void *btx_handle, lttng_ust_cuda_cuDeviceSetMemPool_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetMemPool_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmemoryPool *, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetMemPool_entry(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetMemPool_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetMemPool_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUmemoryPool);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetMemPool_exit(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetMemPool_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetDefaultMemPool_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmemoryPool *, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetDefaultMemPool_entry(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetDefaultMemPool_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetDefaultMemPool_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUmemoryPool);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetDefaultMemPool_exit(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetDefaultMemPool_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetExecAffinitySupport_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, CUexecAffinityType, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetExecAffinitySupport_entry(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetExecAffinitySupport_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetExecAffinitySupport_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, int);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetExecAffinitySupport_exit(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetExecAffinitySupport_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuFlushGPUDirectRDMAWrites_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUflushGPUDirectRDMAWritesTarget, CUflushGPUDirectRDMAWritesScope);

void btx_register_callbacks_lttng_ust_cuda_cuFlushGPUDirectRDMAWrites_entry(
    void *btx_handle, lttng_ust_cuda_cuFlushGPUDirectRDMAWrites_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuFlushGPUDirectRDMAWrites_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuFlushGPUDirectRDMAWrites_exit(
    void *btx_handle, lttng_ust_cuda_cuFlushGPUDirectRDMAWrites_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdevprop *, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetProperties_entry(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetProperties_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUdevprop *);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetProperties_exit(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetProperties_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceComputeCapability_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, int *, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceComputeCapability_entry(
    void *btx_handle, lttng_ust_cuda_cuDeviceComputeCapability_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceComputeCapability_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, int, int);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceComputeCapability_exit(
    void *btx_handle, lttng_ust_cuda_cuDeviceComputeCapability_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDevicePrimaryCtxRetain_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext *, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuDevicePrimaryCtxRetain_entry(
    void *btx_handle, lttng_ust_cuda_cuDevicePrimaryCtxRetain_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDevicePrimaryCtxRetain_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUcontext);

void btx_register_callbacks_lttng_ust_cuda_cuDevicePrimaryCtxRetain_exit(
    void *btx_handle, lttng_ust_cuda_cuDevicePrimaryCtxRetain_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDevicePrimaryCtxRelease_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuDevicePrimaryCtxRelease_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuDevicePrimaryCtxRelease_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDevicePrimaryCtxRelease_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuDevicePrimaryCtxRelease_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuDevicePrimaryCtxRelease_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDevicePrimaryCtxSetFlags_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdevice, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuDevicePrimaryCtxSetFlags_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuDevicePrimaryCtxSetFlags_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDevicePrimaryCtxSetFlags_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuDevicePrimaryCtxSetFlags_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuDevicePrimaryCtxSetFlags_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDevicePrimaryCtxGetState_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdevice, unsigned int *, int *);

void btx_register_callbacks_lttng_ust_cuda_cuDevicePrimaryCtxGetState_entry(
    void *btx_handle, lttng_ust_cuda_cuDevicePrimaryCtxGetState_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDevicePrimaryCtxGetState_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, unsigned int, int);

void btx_register_callbacks_lttng_ust_cuda_cuDevicePrimaryCtxGetState_exit(
    void *btx_handle, lttng_ust_cuda_cuDevicePrimaryCtxGetState_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDevicePrimaryCtxReset_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuDevicePrimaryCtxReset_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuDevicePrimaryCtxReset_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDevicePrimaryCtxReset_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuDevicePrimaryCtxReset_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuDevicePrimaryCtxReset_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxCreate_v4_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext *, CUctxCreateParams *, unsigned int, CUdevice, size_t, CUctxCreateParams *, size_t, CUexecAffinityParam *, size_t, CUctxCigParam *);

void btx_register_callbacks_lttng_ust_cuda_cuCtxCreate_v4_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxCreate_v4_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxCreate_v4_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUcontext);

void btx_register_callbacks_lttng_ust_cuda_cuCtxCreate_v4_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxCreate_v4_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxDestroy_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext);

void btx_register_callbacks_lttng_ust_cuda_cuCtxDestroy_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxDestroy_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxDestroy_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuCtxDestroy_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxDestroy_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxPushCurrent_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext);

void btx_register_callbacks_lttng_ust_cuda_cuCtxPushCurrent_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxPushCurrent_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxPushCurrent_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuCtxPushCurrent_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxPushCurrent_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxPopCurrent_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext *);

void btx_register_callbacks_lttng_ust_cuda_cuCtxPopCurrent_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxPopCurrent_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxPopCurrent_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUcontext);

void btx_register_callbacks_lttng_ust_cuda_cuCtxPopCurrent_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxPopCurrent_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxSetCurrent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext);

void btx_register_callbacks_lttng_ust_cuda_cuCtxSetCurrent_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxSetCurrent_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxSetCurrent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuCtxSetCurrent_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxSetCurrent_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxGetCurrent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext *);

void btx_register_callbacks_lttng_ust_cuda_cuCtxGetCurrent_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxGetCurrent_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxGetCurrent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUcontext);

void btx_register_callbacks_lttng_ust_cuda_cuCtxGetCurrent_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxGetCurrent_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxGetDevice_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdevice *);

void btx_register_callbacks_lttng_ust_cuda_cuCtxGetDevice_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxGetDevice_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxGetDevice_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuCtxGetDevice_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxGetDevice_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxGetDevice_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdevice *, CUcontext);

void btx_register_callbacks_lttng_ust_cuda_cuCtxGetDevice_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxGetDevice_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxGetDevice_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuCtxGetDevice_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxGetDevice_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxGetFlags_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, unsigned int *);

void btx_register_callbacks_lttng_ust_cuda_cuCtxGetFlags_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxGetFlags_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxGetFlags_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuCtxGetFlags_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxGetFlags_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxSetFlags_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuCtxSetFlags_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxSetFlags_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxSetFlags_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuCtxSetFlags_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxSetFlags_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxGetId_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext, unsigned long long int *);

void btx_register_callbacks_lttng_ust_cuda_cuCtxGetId_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxGetId_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxGetId_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, unsigned long long int);

void btx_register_callbacks_lttng_ust_cuda_cuCtxGetId_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxGetId_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxSynchronize_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_cuda_cuCtxSynchronize_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxSynchronize_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxSynchronize_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuCtxSynchronize_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxSynchronize_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxSynchronize_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext);

void btx_register_callbacks_lttng_ust_cuda_cuCtxSynchronize_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxSynchronize_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxSynchronize_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuCtxSynchronize_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxSynchronize_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxSetLimit_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUlimit, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuCtxSetLimit_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxSetLimit_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxSetLimit_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuCtxSetLimit_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxSetLimit_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxGetLimit_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, size_t *, CUlimit);

void btx_register_callbacks_lttng_ust_cuda_cuCtxGetLimit_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxGetLimit_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxGetLimit_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuCtxGetLimit_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxGetLimit_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxGetCacheConfig_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUfunc_cache *);

void btx_register_callbacks_lttng_ust_cuda_cuCtxGetCacheConfig_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxGetCacheConfig_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxGetCacheConfig_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUfunc_cache);

void btx_register_callbacks_lttng_ust_cuda_cuCtxGetCacheConfig_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxGetCacheConfig_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxSetCacheConfig_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUfunc_cache);

void btx_register_callbacks_lttng_ust_cuda_cuCtxSetCacheConfig_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxSetCacheConfig_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxSetCacheConfig_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuCtxSetCacheConfig_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxSetCacheConfig_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxGetApiVersion_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext, unsigned int *);

void btx_register_callbacks_lttng_ust_cuda_cuCtxGetApiVersion_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxGetApiVersion_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxGetApiVersion_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuCtxGetApiVersion_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxGetApiVersion_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxGetStreamPriorityRange_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, int *);

void btx_register_callbacks_lttng_ust_cuda_cuCtxGetStreamPriorityRange_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxGetStreamPriorityRange_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxGetStreamPriorityRange_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, int, int);

void btx_register_callbacks_lttng_ust_cuda_cuCtxGetStreamPriorityRange_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxGetStreamPriorityRange_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxResetPersistingL2Cache_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_cuda_cuCtxResetPersistingL2Cache_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxResetPersistingL2Cache_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxResetPersistingL2Cache_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuCtxResetPersistingL2Cache_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxResetPersistingL2Cache_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxGetExecAffinity_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUexecAffinityParam *, CUexecAffinityType);

void btx_register_callbacks_lttng_ust_cuda_cuCtxGetExecAffinity_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxGetExecAffinity_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxGetExecAffinity_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUexecAffinityParam *);

void btx_register_callbacks_lttng_ust_cuda_cuCtxGetExecAffinity_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxGetExecAffinity_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxRecordEvent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext, CUevent);

void btx_register_callbacks_lttng_ust_cuda_cuCtxRecordEvent_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxRecordEvent_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxRecordEvent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuCtxRecordEvent_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxRecordEvent_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxWaitEvent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext, CUevent);

void btx_register_callbacks_lttng_ust_cuda_cuCtxWaitEvent_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxWaitEvent_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxWaitEvent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuCtxWaitEvent_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxWaitEvent_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxAttach_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext *, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuCtxAttach_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxAttach_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxAttach_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUcontext);

void btx_register_callbacks_lttng_ust_cuda_cuCtxAttach_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxAttach_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxDetach_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext);

void btx_register_callbacks_lttng_ust_cuda_cuCtxDetach_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxDetach_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxDetach_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuCtxDetach_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxDetach_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxGetSharedMemConfig_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUsharedconfig *);

void btx_register_callbacks_lttng_ust_cuda_cuCtxGetSharedMemConfig_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxGetSharedMemConfig_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxGetSharedMemConfig_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUsharedconfig);

void btx_register_callbacks_lttng_ust_cuda_cuCtxGetSharedMemConfig_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxGetSharedMemConfig_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxSetSharedMemConfig_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUsharedconfig);

void btx_register_callbacks_lttng_ust_cuda_cuCtxSetSharedMemConfig_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxSetSharedMemConfig_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxSetSharedMemConfig_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuCtxSetSharedMemConfig_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxSetSharedMemConfig_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuModuleLoad_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmodule *, char *, char *);

void btx_register_callbacks_lttng_ust_cuda_cuModuleLoad_entry(
    void *btx_handle, lttng_ust_cuda_cuModuleLoad_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuModuleLoad_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUmodule);

void btx_register_callbacks_lttng_ust_cuda_cuModuleLoad_exit(
    void *btx_handle, lttng_ust_cuda_cuModuleLoad_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuModuleLoadData_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmodule *, void *);

void btx_register_callbacks_lttng_ust_cuda_cuModuleLoadData_entry(
    void *btx_handle, lttng_ust_cuda_cuModuleLoadData_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuModuleLoadData_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUmodule);

void btx_register_callbacks_lttng_ust_cuda_cuModuleLoadData_exit(
    void *btx_handle, lttng_ust_cuda_cuModuleLoadData_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuModuleLoadDataEx_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmodule *, void *, unsigned int, CUjit_option *, void **, size_t, CUjit_option *, size_t, void * *);

void btx_register_callbacks_lttng_ust_cuda_cuModuleLoadDataEx_entry(
    void *btx_handle, lttng_ust_cuda_cuModuleLoadDataEx_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuModuleLoadDataEx_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUmodule);

void btx_register_callbacks_lttng_ust_cuda_cuModuleLoadDataEx_exit(
    void *btx_handle, lttng_ust_cuda_cuModuleLoadDataEx_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuModuleLoadFatBinary_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmodule *, void *);

void btx_register_callbacks_lttng_ust_cuda_cuModuleLoadFatBinary_entry(
    void *btx_handle, lttng_ust_cuda_cuModuleLoadFatBinary_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuModuleLoadFatBinary_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUmodule);

void btx_register_callbacks_lttng_ust_cuda_cuModuleLoadFatBinary_exit(
    void *btx_handle, lttng_ust_cuda_cuModuleLoadFatBinary_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuModuleUnload_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmodule);

void btx_register_callbacks_lttng_ust_cuda_cuModuleUnload_entry(
    void *btx_handle, lttng_ust_cuda_cuModuleUnload_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuModuleUnload_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuModuleUnload_exit(
    void *btx_handle, lttng_ust_cuda_cuModuleUnload_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuModuleGetLoadingMode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmoduleLoadingMode *);

void btx_register_callbacks_lttng_ust_cuda_cuModuleGetLoadingMode_entry(
    void *btx_handle, lttng_ust_cuda_cuModuleGetLoadingMode_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuModuleGetLoadingMode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUmoduleLoadingMode);

void btx_register_callbacks_lttng_ust_cuda_cuModuleGetLoadingMode_exit(
    void *btx_handle, lttng_ust_cuda_cuModuleGetLoadingMode_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuModuleGetFunction_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUfunction *, CUmodule, char *, char *);

void btx_register_callbacks_lttng_ust_cuda_cuModuleGetFunction_entry(
    void *btx_handle, lttng_ust_cuda_cuModuleGetFunction_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuModuleGetFunction_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUfunction);

void btx_register_callbacks_lttng_ust_cuda_cuModuleGetFunction_exit(
    void *btx_handle, lttng_ust_cuda_cuModuleGetFunction_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuModuleGetFunctionCount_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, unsigned int *, CUmodule);

void btx_register_callbacks_lttng_ust_cuda_cuModuleGetFunctionCount_entry(
    void *btx_handle, lttng_ust_cuda_cuModuleGetFunctionCount_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuModuleGetFunctionCount_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuModuleGetFunctionCount_exit(
    void *btx_handle, lttng_ust_cuda_cuModuleGetFunctionCount_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuModuleEnumerateFunctions_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUfunction *, unsigned int, CUmodule);

void btx_register_callbacks_lttng_ust_cuda_cuModuleEnumerateFunctions_entry(
    void *btx_handle, lttng_ust_cuda_cuModuleEnumerateFunctions_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuModuleEnumerateFunctions_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUfunction *);

void btx_register_callbacks_lttng_ust_cuda_cuModuleEnumerateFunctions_exit(
    void *btx_handle, lttng_ust_cuda_cuModuleEnumerateFunctions_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuModuleGetGlobal_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr *, size_t *, CUmodule, char *, char *);

void btx_register_callbacks_lttng_ust_cuda_cuModuleGetGlobal_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuModuleGetGlobal_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuModuleGetGlobal_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUdeviceptr, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuModuleGetGlobal_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuModuleGetGlobal_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuLinkCreate_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, unsigned int, CUjit_option *, void **, CUlinkState *, size_t, CUjit_option *, size_t, void * *);

void btx_register_callbacks_lttng_ust_cuda_cuLinkCreate_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuLinkCreate_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuLinkCreate_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUlinkState);

void btx_register_callbacks_lttng_ust_cuda_cuLinkCreate_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuLinkCreate_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuLinkAddData_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUlinkState, CUjitInputType, void *, size_t, char *, unsigned int, CUjit_option *, void **, char *, size_t, CUjit_option *, size_t, void * *);

void btx_register_callbacks_lttng_ust_cuda_cuLinkAddData_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuLinkAddData_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuLinkAddData_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuLinkAddData_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuLinkAddData_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuLinkAddFile_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUlinkState, CUjitInputType, char *, unsigned int, CUjit_option *, void **, char *, size_t, CUjit_option *, size_t, void * *);

void btx_register_callbacks_lttng_ust_cuda_cuLinkAddFile_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuLinkAddFile_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuLinkAddFile_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuLinkAddFile_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuLinkAddFile_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuLinkComplete_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUlinkState, void **, size_t *);

void btx_register_callbacks_lttng_ust_cuda_cuLinkComplete_entry(
    void *btx_handle, lttng_ust_cuda_cuLinkComplete_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuLinkComplete_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, void *, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuLinkComplete_exit(
    void *btx_handle, lttng_ust_cuda_cuLinkComplete_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuLinkDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUlinkState);

void btx_register_callbacks_lttng_ust_cuda_cuLinkDestroy_entry(
    void *btx_handle, lttng_ust_cuda_cuLinkDestroy_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuLinkDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuLinkDestroy_exit(
    void *btx_handle, lttng_ust_cuda_cuLinkDestroy_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuModuleGetTexRef_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUtexref *, CUmodule, char *, char *);

void btx_register_callbacks_lttng_ust_cuda_cuModuleGetTexRef_entry(
    void *btx_handle, lttng_ust_cuda_cuModuleGetTexRef_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuModuleGetTexRef_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUtexref);

void btx_register_callbacks_lttng_ust_cuda_cuModuleGetTexRef_exit(
    void *btx_handle, lttng_ust_cuda_cuModuleGetTexRef_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuModuleGetSurfRef_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUsurfref *, CUmodule, char *, char *);

void btx_register_callbacks_lttng_ust_cuda_cuModuleGetSurfRef_entry(
    void *btx_handle, lttng_ust_cuda_cuModuleGetSurfRef_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuModuleGetSurfRef_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUsurfref);

void btx_register_callbacks_lttng_ust_cuda_cuModuleGetSurfRef_exit(
    void *btx_handle, lttng_ust_cuda_cuModuleGetSurfRef_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuLibraryLoadData_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUlibrary *, void *, CUjit_option *, void **, unsigned int, CUlibraryOption *, void **, unsigned int, size_t, CUjit_option *, size_t, void * *, size_t, CUlibraryOption *, size_t, void * *);

void btx_register_callbacks_lttng_ust_cuda_cuLibraryLoadData_entry(
    void *btx_handle, lttng_ust_cuda_cuLibraryLoadData_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuLibraryLoadData_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUlibrary);

void btx_register_callbacks_lttng_ust_cuda_cuLibraryLoadData_exit(
    void *btx_handle, lttng_ust_cuda_cuLibraryLoadData_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuLibraryLoadFromFile_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUlibrary *, char *, CUjit_option *, void **, unsigned int, CUlibraryOption *, void **, unsigned int, char *, size_t, CUjit_option *, size_t, void * *, size_t, CUlibraryOption *, size_t, void * *);

void btx_register_callbacks_lttng_ust_cuda_cuLibraryLoadFromFile_entry(
    void *btx_handle, lttng_ust_cuda_cuLibraryLoadFromFile_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuLibraryLoadFromFile_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUlibrary);

void btx_register_callbacks_lttng_ust_cuda_cuLibraryLoadFromFile_exit(
    void *btx_handle, lttng_ust_cuda_cuLibraryLoadFromFile_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuLibraryUnload_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUlibrary);

void btx_register_callbacks_lttng_ust_cuda_cuLibraryUnload_entry(
    void *btx_handle, lttng_ust_cuda_cuLibraryUnload_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuLibraryUnload_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuLibraryUnload_exit(
    void *btx_handle, lttng_ust_cuda_cuLibraryUnload_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuLibraryGetKernel_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUkernel *, CUlibrary, char *, char *);

void btx_register_callbacks_lttng_ust_cuda_cuLibraryGetKernel_entry(
    void *btx_handle, lttng_ust_cuda_cuLibraryGetKernel_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuLibraryGetKernel_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUkernel);

void btx_register_callbacks_lttng_ust_cuda_cuLibraryGetKernel_exit(
    void *btx_handle, lttng_ust_cuda_cuLibraryGetKernel_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuLibraryGetKernelCount_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, unsigned int *, CUlibrary);

void btx_register_callbacks_lttng_ust_cuda_cuLibraryGetKernelCount_entry(
    void *btx_handle, lttng_ust_cuda_cuLibraryGetKernelCount_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuLibraryGetKernelCount_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuLibraryGetKernelCount_exit(
    void *btx_handle, lttng_ust_cuda_cuLibraryGetKernelCount_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuLibraryEnumerateKernels_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUkernel *, unsigned int, CUlibrary);

void btx_register_callbacks_lttng_ust_cuda_cuLibraryEnumerateKernels_entry(
    void *btx_handle, lttng_ust_cuda_cuLibraryEnumerateKernels_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuLibraryEnumerateKernels_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUkernel *);

void btx_register_callbacks_lttng_ust_cuda_cuLibraryEnumerateKernels_exit(
    void *btx_handle, lttng_ust_cuda_cuLibraryEnumerateKernels_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuLibraryGetModule_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmodule *, CUlibrary);

void btx_register_callbacks_lttng_ust_cuda_cuLibraryGetModule_entry(
    void *btx_handle, lttng_ust_cuda_cuLibraryGetModule_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuLibraryGetModule_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUmodule);

void btx_register_callbacks_lttng_ust_cuda_cuLibraryGetModule_exit(
    void *btx_handle, lttng_ust_cuda_cuLibraryGetModule_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuKernelGetFunction_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUfunction *, CUkernel);

void btx_register_callbacks_lttng_ust_cuda_cuKernelGetFunction_entry(
    void *btx_handle, lttng_ust_cuda_cuKernelGetFunction_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuKernelGetFunction_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUfunction);

void btx_register_callbacks_lttng_ust_cuda_cuKernelGetFunction_exit(
    void *btx_handle, lttng_ust_cuda_cuKernelGetFunction_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuKernelGetLibrary_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUlibrary *, CUkernel);

void btx_register_callbacks_lttng_ust_cuda_cuKernelGetLibrary_entry(
    void *btx_handle, lttng_ust_cuda_cuKernelGetLibrary_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuKernelGetLibrary_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUlibrary);

void btx_register_callbacks_lttng_ust_cuda_cuKernelGetLibrary_exit(
    void *btx_handle, lttng_ust_cuda_cuKernelGetLibrary_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuLibraryGetGlobal_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr *, size_t *, CUlibrary, char *, char *);

void btx_register_callbacks_lttng_ust_cuda_cuLibraryGetGlobal_entry(
    void *btx_handle, lttng_ust_cuda_cuLibraryGetGlobal_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuLibraryGetGlobal_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUdeviceptr, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuLibraryGetGlobal_exit(
    void *btx_handle, lttng_ust_cuda_cuLibraryGetGlobal_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuLibraryGetManaged_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr *, size_t *, CUlibrary, char *, char *);

void btx_register_callbacks_lttng_ust_cuda_cuLibraryGetManaged_entry(
    void *btx_handle, lttng_ust_cuda_cuLibraryGetManaged_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuLibraryGetManaged_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUdeviceptr, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuLibraryGetManaged_exit(
    void *btx_handle, lttng_ust_cuda_cuLibraryGetManaged_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuLibraryGetUnifiedFunction_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void **, CUlibrary, char *, char *);

void btx_register_callbacks_lttng_ust_cuda_cuLibraryGetUnifiedFunction_entry(
    void *btx_handle, lttng_ust_cuda_cuLibraryGetUnifiedFunction_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuLibraryGetUnifiedFunction_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, void *);

void btx_register_callbacks_lttng_ust_cuda_cuLibraryGetUnifiedFunction_exit(
    void *btx_handle, lttng_ust_cuda_cuLibraryGetUnifiedFunction_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuKernelGetAttribute_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, CUfunction_attribute, CUkernel, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuKernelGetAttribute_entry(
    void *btx_handle, lttng_ust_cuda_cuKernelGetAttribute_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuKernelGetAttribute_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, int);

void btx_register_callbacks_lttng_ust_cuda_cuKernelGetAttribute_exit(
    void *btx_handle, lttng_ust_cuda_cuKernelGetAttribute_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuKernelSetAttribute_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUfunction_attribute, int, CUkernel, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuKernelSetAttribute_entry(
    void *btx_handle, lttng_ust_cuda_cuKernelSetAttribute_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuKernelSetAttribute_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuKernelSetAttribute_exit(
    void *btx_handle, lttng_ust_cuda_cuKernelSetAttribute_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuKernelSetCacheConfig_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUkernel, CUfunc_cache, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuKernelSetCacheConfig_entry(
    void *btx_handle, lttng_ust_cuda_cuKernelSetCacheConfig_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuKernelSetCacheConfig_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuKernelSetCacheConfig_exit(
    void *btx_handle, lttng_ust_cuda_cuKernelSetCacheConfig_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuKernelGetName_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char **, CUkernel);

void btx_register_callbacks_lttng_ust_cuda_cuKernelGetName_entry(
    void *btx_handle, lttng_ust_cuda_cuKernelGetName_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuKernelGetName_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, char *);

void btx_register_callbacks_lttng_ust_cuda_cuKernelGetName_exit(
    void *btx_handle, lttng_ust_cuda_cuKernelGetName_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuKernelGetParamInfo_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUkernel, size_t, size_t *, size_t *);

void btx_register_callbacks_lttng_ust_cuda_cuKernelGetParamInfo_entry(
    void *btx_handle, lttng_ust_cuda_cuKernelGetParamInfo_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuKernelGetParamInfo_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuKernelGetParamInfo_exit(
    void *btx_handle, lttng_ust_cuda_cuKernelGetParamInfo_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemGetInfo_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, size_t *, size_t *);

void btx_register_callbacks_lttng_ust_cuda_cuMemGetInfo_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuMemGetInfo_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemGetInfo_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemGetInfo_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuMemGetInfo_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemAlloc_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr *, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemAlloc_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuMemAlloc_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemAlloc_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUdeviceptr);

void btx_register_callbacks_lttng_ust_cuda_cuMemAlloc_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuMemAlloc_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemAllocPitch_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr *, size_t *, size_t, size_t, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuMemAllocPitch_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuMemAllocPitch_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemAllocPitch_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUdeviceptr, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemAllocPitch_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuMemAllocPitch_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemFree_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr);

void btx_register_callbacks_lttng_ust_cuda_cuMemFree_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuMemFree_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemFree_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemFree_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuMemFree_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemGetAddressRange_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr *, size_t *, CUdeviceptr);

void btx_register_callbacks_lttng_ust_cuda_cuMemGetAddressRange_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuMemGetAddressRange_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemGetAddressRange_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUdeviceptr, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemGetAddressRange_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuMemGetAddressRange_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemAllocHost_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void **, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemAllocHost_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuMemAllocHost_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemAllocHost_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, void *);

void btx_register_callbacks_lttng_ust_cuda_cuMemAllocHost_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuMemAllocHost_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemFreeHost_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *);

void btx_register_callbacks_lttng_ust_cuda_cuMemFreeHost_entry(
    void *btx_handle, lttng_ust_cuda_cuMemFreeHost_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemFreeHost_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemFreeHost_exit(
    void *btx_handle, lttng_ust_cuda_cuMemFreeHost_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemHostAlloc_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void **, size_t, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuMemHostAlloc_entry(
    void *btx_handle, lttng_ust_cuda_cuMemHostAlloc_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemHostAlloc_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, void *);

void btx_register_callbacks_lttng_ust_cuda_cuMemHostAlloc_exit(
    void *btx_handle, lttng_ust_cuda_cuMemHostAlloc_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemHostGetDevicePointer_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr *, void *, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuMemHostGetDevicePointer_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuMemHostGetDevicePointer_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemHostGetDevicePointer_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUdeviceptr);

void btx_register_callbacks_lttng_ust_cuda_cuMemHostGetDevicePointer_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuMemHostGetDevicePointer_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemHostGetFlags_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, unsigned int *, void *);

void btx_register_callbacks_lttng_ust_cuda_cuMemHostGetFlags_entry(
    void *btx_handle, lttng_ust_cuda_cuMemHostGetFlags_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemHostGetFlags_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuMemHostGetFlags_exit(
    void *btx_handle, lttng_ust_cuda_cuMemHostGetFlags_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemAllocManaged_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr *, size_t, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuMemAllocManaged_entry(
    void *btx_handle, lttng_ust_cuda_cuMemAllocManaged_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemAllocManaged_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUdeviceptr);

void btx_register_callbacks_lttng_ust_cuda_cuMemAllocManaged_exit(
    void *btx_handle, lttng_ust_cuda_cuMemAllocManaged_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceRegisterAsyncNotification_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdevice, CUasyncCallback, void *, CUasyncCallbackHandle *);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceRegisterAsyncNotification_entry(
    void *btx_handle, lttng_ust_cuda_cuDeviceRegisterAsyncNotification_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceRegisterAsyncNotification_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUasyncCallbackHandle);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceRegisterAsyncNotification_exit(
    void *btx_handle, lttng_ust_cuda_cuDeviceRegisterAsyncNotification_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceUnregisterAsyncNotification_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdevice, CUasyncCallbackHandle);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceUnregisterAsyncNotification_entry(
    void *btx_handle, lttng_ust_cuda_cuDeviceUnregisterAsyncNotification_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceUnregisterAsyncNotification_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceUnregisterAsyncNotification_exit(
    void *btx_handle, lttng_ust_cuda_cuDeviceUnregisterAsyncNotification_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetByPCIBusId_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdevice *, char *, char *);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetByPCIBusId_entry(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetByPCIBusId_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetByPCIBusId_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetByPCIBusId_exit(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetByPCIBusId_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetPCIBusId_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, int, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetPCIBusId_entry(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetPCIBusId_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetPCIBusId_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, char *);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetPCIBusId_exit(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetPCIBusId_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuIpcGetEventHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUipcEventHandle *, CUevent);

void btx_register_callbacks_lttng_ust_cuda_cuIpcGetEventHandle_entry(
    void *btx_handle, lttng_ust_cuda_cuIpcGetEventHandle_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuIpcGetEventHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUipcEventHandle *);

void btx_register_callbacks_lttng_ust_cuda_cuIpcGetEventHandle_exit(
    void *btx_handle, lttng_ust_cuda_cuIpcGetEventHandle_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuIpcOpenEventHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUevent *, CUipcEventHandle);

void btx_register_callbacks_lttng_ust_cuda_cuIpcOpenEventHandle_entry(
    void *btx_handle, lttng_ust_cuda_cuIpcOpenEventHandle_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuIpcOpenEventHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUevent);

void btx_register_callbacks_lttng_ust_cuda_cuIpcOpenEventHandle_exit(
    void *btx_handle, lttng_ust_cuda_cuIpcOpenEventHandle_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuIpcGetMemHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUipcMemHandle *, CUdeviceptr);

void btx_register_callbacks_lttng_ust_cuda_cuIpcGetMemHandle_entry(
    void *btx_handle, lttng_ust_cuda_cuIpcGetMemHandle_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuIpcGetMemHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUipcMemHandle *);

void btx_register_callbacks_lttng_ust_cuda_cuIpcGetMemHandle_exit(
    void *btx_handle, lttng_ust_cuda_cuIpcGetMemHandle_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuIpcOpenMemHandle_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr *, CUipcMemHandle, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuIpcOpenMemHandle_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuIpcOpenMemHandle_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuIpcOpenMemHandle_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUdeviceptr);

void btx_register_callbacks_lttng_ust_cuda_cuIpcOpenMemHandle_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuIpcOpenMemHandle_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuIpcCloseMemHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr);

void btx_register_callbacks_lttng_ust_cuda_cuIpcCloseMemHandle_entry(
    void *btx_handle, lttng_ust_cuda_cuIpcCloseMemHandle_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuIpcCloseMemHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuIpcCloseMemHandle_exit(
    void *btx_handle, lttng_ust_cuda_cuIpcCloseMemHandle_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemHostRegister_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, size_t, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuMemHostRegister_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuMemHostRegister_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemHostRegister_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemHostRegister_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuMemHostRegister_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemHostUnregister_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *);

void btx_register_callbacks_lttng_ust_cuda_cuMemHostUnregister_entry(
    void *btx_handle, lttng_ust_cuda_cuMemHostUnregister_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemHostUnregister_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemHostUnregister_exit(
    void *btx_handle, lttng_ust_cuda_cuMemHostUnregister_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy_ptds_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, CUdeviceptr, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy_ptds_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpy_ptds_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy_ptds_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy_ptds_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpy_ptds_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyPeer_ptds_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, CUcontext, CUdeviceptr, CUcontext, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyPeer_ptds_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyPeer_ptds_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyPeer_ptds_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyPeer_ptds_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyPeer_ptds_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyHtoD_v2_ptds_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, void *, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyHtoD_v2_ptds_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyHtoD_v2_ptds_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyHtoD_v2_ptds_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyHtoD_v2_ptds_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyHtoD_v2_ptds_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyDtoH_v2_ptds_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, CUdeviceptr, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyDtoH_v2_ptds_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyDtoH_v2_ptds_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyDtoH_v2_ptds_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyDtoH_v2_ptds_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyDtoH_v2_ptds_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyDtoD_v2_ptds_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, CUdeviceptr, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyDtoD_v2_ptds_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyDtoD_v2_ptds_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyDtoD_v2_ptds_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyDtoD_v2_ptds_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyDtoD_v2_ptds_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyDtoA_v2_ptds_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUarray, size_t, CUdeviceptr, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyDtoA_v2_ptds_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyDtoA_v2_ptds_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyDtoA_v2_ptds_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyDtoA_v2_ptds_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyDtoA_v2_ptds_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyAtoD_v2_ptds_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, CUarray, size_t, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyAtoD_v2_ptds_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyAtoD_v2_ptds_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyAtoD_v2_ptds_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyAtoD_v2_ptds_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyAtoD_v2_ptds_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyHtoA_v2_ptds_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUarray, size_t, void *, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyHtoA_v2_ptds_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyHtoA_v2_ptds_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyHtoA_v2_ptds_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyHtoA_v2_ptds_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyHtoA_v2_ptds_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyAtoH_v2_ptds_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, CUarray, size_t, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyAtoH_v2_ptds_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyAtoH_v2_ptds_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyAtoH_v2_ptds_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyAtoH_v2_ptds_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyAtoH_v2_ptds_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyAtoA_v2_ptds_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUarray, size_t, CUarray, size_t, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyAtoA_v2_ptds_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyAtoA_v2_ptds_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyAtoA_v2_ptds_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyAtoA_v2_ptds_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyAtoA_v2_ptds_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy2D_v2_ptds_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUDA_MEMCPY2D *, size_t, CUDA_MEMCPY2D *);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy2D_v2_ptds_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpy2D_v2_ptds_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy2D_v2_ptds_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy2D_v2_ptds_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpy2D_v2_ptds_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy2DUnaligned_v2_ptds_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUDA_MEMCPY2D *, size_t, CUDA_MEMCPY2D *);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy2DUnaligned_v2_ptds_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpy2DUnaligned_v2_ptds_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy2DUnaligned_v2_ptds_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy2DUnaligned_v2_ptds_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpy2DUnaligned_v2_ptds_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy3D_v2_ptds_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUDA_MEMCPY3D *, size_t, CUDA_MEMCPY3D *);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy3D_v2_ptds_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpy3D_v2_ptds_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy3D_v2_ptds_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy3D_v2_ptds_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpy3D_v2_ptds_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy3DPeer_ptds_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUDA_MEMCPY3D_PEER *, size_t, CUDA_MEMCPY3D_PEER *);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy3DPeer_ptds_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpy3DPeer_ptds_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy3DPeer_ptds_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy3DPeer_ptds_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpy3DPeer_ptds_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyAsync_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, CUdeviceptr, size_t, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyAsync_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyAsync_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyAsync_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyAsync_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyAsync_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyPeerAsync_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, CUcontext, CUdeviceptr, CUcontext, size_t, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyPeerAsync_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyPeerAsync_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyPeerAsync_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyPeerAsync_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyPeerAsync_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyHtoDAsync_v2_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, void *, size_t, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyHtoDAsync_v2_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyHtoDAsync_v2_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyHtoDAsync_v2_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyHtoDAsync_v2_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyHtoDAsync_v2_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyDtoHAsync_v2_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, CUdeviceptr, size_t, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyDtoHAsync_v2_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyDtoHAsync_v2_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyDtoHAsync_v2_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyDtoHAsync_v2_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyDtoHAsync_v2_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyDtoDAsync_v2_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, CUdeviceptr, size_t, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyDtoDAsync_v2_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyDtoDAsync_v2_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyDtoDAsync_v2_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyDtoDAsync_v2_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyDtoDAsync_v2_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyHtoAAsync_v2_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUarray, size_t, void *, size_t, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyHtoAAsync_v2_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyHtoAAsync_v2_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyHtoAAsync_v2_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyHtoAAsync_v2_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyHtoAAsync_v2_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyAtoHAsync_v2_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, CUarray, size_t, size_t, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyAtoHAsync_v2_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyAtoHAsync_v2_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyAtoHAsync_v2_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyAtoHAsync_v2_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyAtoHAsync_v2_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy2DAsync_v2_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUDA_MEMCPY2D *, CUstream, size_t, CUDA_MEMCPY2D *);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy2DAsync_v2_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpy2DAsync_v2_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy2DAsync_v2_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy2DAsync_v2_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpy2DAsync_v2_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy3DAsync_v2_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUDA_MEMCPY3D *, CUstream, size_t, CUDA_MEMCPY3D *);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy3DAsync_v2_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpy3DAsync_v2_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy3DAsync_v2_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy3DAsync_v2_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpy3DAsync_v2_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy3DPeerAsync_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUDA_MEMCPY3D_PEER *, CUstream, size_t, CUDA_MEMCPY3D_PEER *);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy3DPeerAsync_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpy3DPeerAsync_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy3DPeerAsync_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy3DPeerAsync_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpy3DPeerAsync_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyBatchAsync_v2_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr *, CUdeviceptr *, size_t *, size_t, CUmemcpyAttributes *, size_t *, size_t, CUstream, size_t, CUdeviceptr *, size_t, CUdeviceptr *, size_t, size_t *, size_t, CUmemcpyAttributes *, size_t, size_t *);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyBatchAsync_v2_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyBatchAsync_v2_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyBatchAsync_v2_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyBatchAsync_v2_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyBatchAsync_v2_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy3DBatchAsync_v2_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, size_t, CUDA_MEMCPY3D_BATCH_OP *, unsigned long long int, CUstream, size_t, CUDA_MEMCPY3D_BATCH_OP *);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy3DBatchAsync_v2_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpy3DBatchAsync_v2_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy3DBatchAsync_v2_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy3DBatchAsync_v2_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpy3DBatchAsync_v2_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD8_v2_ptds_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, unsigned char, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD8_v2_ptds_entry(
    void *btx_handle, lttng_ust_cuda_cuMemsetD8_v2_ptds_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD8_v2_ptds_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD8_v2_ptds_exit(
    void *btx_handle, lttng_ust_cuda_cuMemsetD8_v2_ptds_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD16_v2_ptds_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, unsigned short int, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD16_v2_ptds_entry(
    void *btx_handle, lttng_ust_cuda_cuMemsetD16_v2_ptds_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD16_v2_ptds_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD16_v2_ptds_exit(
    void *btx_handle, lttng_ust_cuda_cuMemsetD16_v2_ptds_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD32_v2_ptds_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, unsigned int, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD32_v2_ptds_entry(
    void *btx_handle, lttng_ust_cuda_cuMemsetD32_v2_ptds_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD32_v2_ptds_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD32_v2_ptds_exit(
    void *btx_handle, lttng_ust_cuda_cuMemsetD32_v2_ptds_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD2D8_v2_ptds_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, size_t, unsigned char, size_t, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD2D8_v2_ptds_entry(
    void *btx_handle, lttng_ust_cuda_cuMemsetD2D8_v2_ptds_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD2D8_v2_ptds_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD2D8_v2_ptds_exit(
    void *btx_handle, lttng_ust_cuda_cuMemsetD2D8_v2_ptds_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD2D16_v2_ptds_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, size_t, unsigned short int, size_t, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD2D16_v2_ptds_entry(
    void *btx_handle, lttng_ust_cuda_cuMemsetD2D16_v2_ptds_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD2D16_v2_ptds_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD2D16_v2_ptds_exit(
    void *btx_handle, lttng_ust_cuda_cuMemsetD2D16_v2_ptds_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD2D32_v2_ptds_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, size_t, unsigned int, size_t, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD2D32_v2_ptds_entry(
    void *btx_handle, lttng_ust_cuda_cuMemsetD2D32_v2_ptds_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD2D32_v2_ptds_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD2D32_v2_ptds_exit(
    void *btx_handle, lttng_ust_cuda_cuMemsetD2D32_v2_ptds_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD8Async_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, unsigned char, size_t, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD8Async_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuMemsetD8Async_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD8Async_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD8Async_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuMemsetD8Async_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD16Async_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, unsigned short int, size_t, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD16Async_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuMemsetD16Async_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD16Async_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD16Async_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuMemsetD16Async_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD32Async_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, unsigned int, size_t, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD32Async_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuMemsetD32Async_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD32Async_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD32Async_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuMemsetD32Async_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD2D8Async_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, size_t, unsigned char, size_t, size_t, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD2D8Async_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuMemsetD2D8Async_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD2D8Async_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD2D8Async_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuMemsetD2D8Async_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD2D16Async_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, size_t, unsigned short int, size_t, size_t, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD2D16Async_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuMemsetD2D16Async_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD2D16Async_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD2D16Async_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuMemsetD2D16Async_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD2D32Async_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, size_t, unsigned int, size_t, size_t, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD2D32Async_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuMemsetD2D32Async_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD2D32Async_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD2D32Async_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuMemsetD2D32Async_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuArrayCreate_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUarray *, CUDA_ARRAY_DESCRIPTOR *, size_t, CUDA_ARRAY_DESCRIPTOR *);

void btx_register_callbacks_lttng_ust_cuda_cuArrayCreate_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuArrayCreate_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuArrayCreate_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUarray);

void btx_register_callbacks_lttng_ust_cuda_cuArrayCreate_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuArrayCreate_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuArrayGetDescriptor_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUDA_ARRAY_DESCRIPTOR *, CUarray);

void btx_register_callbacks_lttng_ust_cuda_cuArrayGetDescriptor_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuArrayGetDescriptor_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuArrayGetDescriptor_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUDA_ARRAY_DESCRIPTOR *);

void btx_register_callbacks_lttng_ust_cuda_cuArrayGetDescriptor_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuArrayGetDescriptor_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuArrayGetSparseProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUDA_ARRAY_SPARSE_PROPERTIES *, CUarray);

void btx_register_callbacks_lttng_ust_cuda_cuArrayGetSparseProperties_entry(
    void *btx_handle, lttng_ust_cuda_cuArrayGetSparseProperties_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuArrayGetSparseProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUDA_ARRAY_SPARSE_PROPERTIES *);

void btx_register_callbacks_lttng_ust_cuda_cuArrayGetSparseProperties_exit(
    void *btx_handle, lttng_ust_cuda_cuArrayGetSparseProperties_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMipmappedArrayGetSparseProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUDA_ARRAY_SPARSE_PROPERTIES *, CUmipmappedArray);

void btx_register_callbacks_lttng_ust_cuda_cuMipmappedArrayGetSparseProperties_entry(
    void *btx_handle, lttng_ust_cuda_cuMipmappedArrayGetSparseProperties_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMipmappedArrayGetSparseProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUDA_ARRAY_SPARSE_PROPERTIES *);

void btx_register_callbacks_lttng_ust_cuda_cuMipmappedArrayGetSparseProperties_exit(
    void *btx_handle, lttng_ust_cuda_cuMipmappedArrayGetSparseProperties_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuArrayGetMemoryRequirements_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUDA_ARRAY_MEMORY_REQUIREMENTS *, CUarray, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuArrayGetMemoryRequirements_entry(
    void *btx_handle, lttng_ust_cuda_cuArrayGetMemoryRequirements_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuArrayGetMemoryRequirements_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUDA_ARRAY_MEMORY_REQUIREMENTS *);

void btx_register_callbacks_lttng_ust_cuda_cuArrayGetMemoryRequirements_exit(
    void *btx_handle, lttng_ust_cuda_cuArrayGetMemoryRequirements_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMipmappedArrayGetMemoryRequirements_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUDA_ARRAY_MEMORY_REQUIREMENTS *, CUmipmappedArray, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuMipmappedArrayGetMemoryRequirements_entry(
    void *btx_handle, lttng_ust_cuda_cuMipmappedArrayGetMemoryRequirements_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMipmappedArrayGetMemoryRequirements_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUDA_ARRAY_MEMORY_REQUIREMENTS *);

void btx_register_callbacks_lttng_ust_cuda_cuMipmappedArrayGetMemoryRequirements_exit(
    void *btx_handle, lttng_ust_cuda_cuMipmappedArrayGetMemoryRequirements_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuArrayGetPlane_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUarray *, CUarray, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuArrayGetPlane_entry(
    void *btx_handle, lttng_ust_cuda_cuArrayGetPlane_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuArrayGetPlane_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUarray);

void btx_register_callbacks_lttng_ust_cuda_cuArrayGetPlane_exit(
    void *btx_handle, lttng_ust_cuda_cuArrayGetPlane_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuArrayDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUarray);

void btx_register_callbacks_lttng_ust_cuda_cuArrayDestroy_entry(
    void *btx_handle, lttng_ust_cuda_cuArrayDestroy_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuArrayDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuArrayDestroy_exit(
    void *btx_handle, lttng_ust_cuda_cuArrayDestroy_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuArray3DCreate_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUarray *, CUDA_ARRAY3D_DESCRIPTOR *, size_t, CUDA_ARRAY3D_DESCRIPTOR *);

void btx_register_callbacks_lttng_ust_cuda_cuArray3DCreate_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuArray3DCreate_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuArray3DCreate_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUarray);

void btx_register_callbacks_lttng_ust_cuda_cuArray3DCreate_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuArray3DCreate_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuArray3DGetDescriptor_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUDA_ARRAY3D_DESCRIPTOR *, CUarray);

void btx_register_callbacks_lttng_ust_cuda_cuArray3DGetDescriptor_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuArray3DGetDescriptor_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuArray3DGetDescriptor_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUDA_ARRAY3D_DESCRIPTOR *);

void btx_register_callbacks_lttng_ust_cuda_cuArray3DGetDescriptor_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuArray3DGetDescriptor_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMipmappedArrayCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmipmappedArray *, CUDA_ARRAY3D_DESCRIPTOR *, unsigned int, size_t, CUDA_ARRAY3D_DESCRIPTOR *);

void btx_register_callbacks_lttng_ust_cuda_cuMipmappedArrayCreate_entry(
    void *btx_handle, lttng_ust_cuda_cuMipmappedArrayCreate_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMipmappedArrayCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUmipmappedArray);

void btx_register_callbacks_lttng_ust_cuda_cuMipmappedArrayCreate_exit(
    void *btx_handle, lttng_ust_cuda_cuMipmappedArrayCreate_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMipmappedArrayGetLevel_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUarray *, CUmipmappedArray, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuMipmappedArrayGetLevel_entry(
    void *btx_handle, lttng_ust_cuda_cuMipmappedArrayGetLevel_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMipmappedArrayGetLevel_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUarray);

void btx_register_callbacks_lttng_ust_cuda_cuMipmappedArrayGetLevel_exit(
    void *btx_handle, lttng_ust_cuda_cuMipmappedArrayGetLevel_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMipmappedArrayDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmipmappedArray);

void btx_register_callbacks_lttng_ust_cuda_cuMipmappedArrayDestroy_entry(
    void *btx_handle, lttng_ust_cuda_cuMipmappedArrayDestroy_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMipmappedArrayDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMipmappedArrayDestroy_exit(
    void *btx_handle, lttng_ust_cuda_cuMipmappedArrayDestroy_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemGetHandleForAddressRange_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, CUdeviceptr, size_t, CUmemRangeHandleType, unsigned long long int);

void btx_register_callbacks_lttng_ust_cuda_cuMemGetHandleForAddressRange_entry(
    void *btx_handle, lttng_ust_cuda_cuMemGetHandleForAddressRange_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemGetHandleForAddressRange_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, void *);

void btx_register_callbacks_lttng_ust_cuda_cuMemGetHandleForAddressRange_exit(
    void *btx_handle, lttng_ust_cuda_cuMemGetHandleForAddressRange_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemBatchDecompressAsync_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmemDecompressParams *, size_t, unsigned int, size_t *, CUstream, size_t, CUmemDecompressParams *);

void btx_register_callbacks_lttng_ust_cuda_cuMemBatchDecompressAsync_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuMemBatchDecompressAsync_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemBatchDecompressAsync_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemBatchDecompressAsync_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuMemBatchDecompressAsync_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemAddressReserve_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr *, size_t, size_t, CUdeviceptr, unsigned long long int);

void btx_register_callbacks_lttng_ust_cuda_cuMemAddressReserve_entry(
    void *btx_handle, lttng_ust_cuda_cuMemAddressReserve_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemAddressReserve_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUdeviceptr);

void btx_register_callbacks_lttng_ust_cuda_cuMemAddressReserve_exit(
    void *btx_handle, lttng_ust_cuda_cuMemAddressReserve_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemAddressFree_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemAddressFree_entry(
    void *btx_handle, lttng_ust_cuda_cuMemAddressFree_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemAddressFree_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemAddressFree_exit(
    void *btx_handle, lttng_ust_cuda_cuMemAddressFree_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmemGenericAllocationHandle *, size_t, CUmemAllocationProp *, unsigned long long int, size_t, CUmemAllocationProp *);

void btx_register_callbacks_lttng_ust_cuda_cuMemCreate_entry(
    void *btx_handle, lttng_ust_cuda_cuMemCreate_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUmemGenericAllocationHandle);

void btx_register_callbacks_lttng_ust_cuda_cuMemCreate_exit(
    void *btx_handle, lttng_ust_cuda_cuMemCreate_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemRelease_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmemGenericAllocationHandle);

void btx_register_callbacks_lttng_ust_cuda_cuMemRelease_entry(
    void *btx_handle, lttng_ust_cuda_cuMemRelease_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemRelease_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemRelease_exit(
    void *btx_handle, lttng_ust_cuda_cuMemRelease_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemMap_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, size_t, size_t, CUmemGenericAllocationHandle, unsigned long long int);

void btx_register_callbacks_lttng_ust_cuda_cuMemMap_entry(
    void *btx_handle, lttng_ust_cuda_cuMemMap_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemMap_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemMap_exit(
    void *btx_handle, lttng_ust_cuda_cuMemMap_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemMapArrayAsync_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUarrayMapInfo *, unsigned int, CUstream, size_t, CUarrayMapInfo *);

void btx_register_callbacks_lttng_ust_cuda_cuMemMapArrayAsync_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuMemMapArrayAsync_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemMapArrayAsync_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemMapArrayAsync_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuMemMapArrayAsync_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemUnmap_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemUnmap_entry(
    void *btx_handle, lttng_ust_cuda_cuMemUnmap_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemUnmap_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemUnmap_exit(
    void *btx_handle, lttng_ust_cuda_cuMemUnmap_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemSetAccess_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, size_t, CUmemAccessDesc *, size_t, size_t, CUmemAccessDesc *);

void btx_register_callbacks_lttng_ust_cuda_cuMemSetAccess_entry(
    void *btx_handle, lttng_ust_cuda_cuMemSetAccess_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemSetAccess_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemSetAccess_exit(
    void *btx_handle, lttng_ust_cuda_cuMemSetAccess_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemGetAccess_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, unsigned long long int *, CUmemLocation *, CUdeviceptr, size_t, CUmemLocation *);

void btx_register_callbacks_lttng_ust_cuda_cuMemGetAccess_entry(
    void *btx_handle, lttng_ust_cuda_cuMemGetAccess_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemGetAccess_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, unsigned long long int);

void btx_register_callbacks_lttng_ust_cuda_cuMemGetAccess_exit(
    void *btx_handle, lttng_ust_cuda_cuMemGetAccess_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemExportToShareableHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, CUmemGenericAllocationHandle, CUmemAllocationHandleType, unsigned long long int);

void btx_register_callbacks_lttng_ust_cuda_cuMemExportToShareableHandle_entry(
    void *btx_handle, lttng_ust_cuda_cuMemExportToShareableHandle_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemExportToShareableHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, void *);

void btx_register_callbacks_lttng_ust_cuda_cuMemExportToShareableHandle_exit(
    void *btx_handle, lttng_ust_cuda_cuMemExportToShareableHandle_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemImportFromShareableHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmemGenericAllocationHandle *, void *, CUmemAllocationHandleType, size_t, void *);

void btx_register_callbacks_lttng_ust_cuda_cuMemImportFromShareableHandle_entry(
    void *btx_handle, lttng_ust_cuda_cuMemImportFromShareableHandle_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemImportFromShareableHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUmemGenericAllocationHandle);

void btx_register_callbacks_lttng_ust_cuda_cuMemImportFromShareableHandle_exit(
    void *btx_handle, lttng_ust_cuda_cuMemImportFromShareableHandle_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemGetAllocationGranularity_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, size_t *, CUmemAllocationProp *, CUmemAllocationGranularity_flags, size_t, CUmemAllocationProp *);

void btx_register_callbacks_lttng_ust_cuda_cuMemGetAllocationGranularity_entry(
    void *btx_handle, lttng_ust_cuda_cuMemGetAllocationGranularity_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemGetAllocationGranularity_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemGetAllocationGranularity_exit(
    void *btx_handle, lttng_ust_cuda_cuMemGetAllocationGranularity_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemGetAllocationPropertiesFromHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmemAllocationProp *, CUmemGenericAllocationHandle);

void btx_register_callbacks_lttng_ust_cuda_cuMemGetAllocationPropertiesFromHandle_entry(
    void *btx_handle, lttng_ust_cuda_cuMemGetAllocationPropertiesFromHandle_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemGetAllocationPropertiesFromHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUmemAllocationProp *);

void btx_register_callbacks_lttng_ust_cuda_cuMemGetAllocationPropertiesFromHandle_exit(
    void *btx_handle, lttng_ust_cuda_cuMemGetAllocationPropertiesFromHandle_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemRetainAllocationHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmemGenericAllocationHandle *, void *);

void btx_register_callbacks_lttng_ust_cuda_cuMemRetainAllocationHandle_entry(
    void *btx_handle, lttng_ust_cuda_cuMemRetainAllocationHandle_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemRetainAllocationHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUmemGenericAllocationHandle);

void btx_register_callbacks_lttng_ust_cuda_cuMemRetainAllocationHandle_exit(
    void *btx_handle, lttng_ust_cuda_cuMemRetainAllocationHandle_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemFreeAsync_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemFreeAsync_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuMemFreeAsync_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemFreeAsync_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemFreeAsync_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuMemFreeAsync_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemAllocAsync_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr *, size_t, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemAllocAsync_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuMemAllocAsync_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemAllocAsync_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUdeviceptr);

void btx_register_callbacks_lttng_ust_cuda_cuMemAllocAsync_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuMemAllocAsync_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemPoolTrimTo_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmemoryPool, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemPoolTrimTo_entry(
    void *btx_handle, lttng_ust_cuda_cuMemPoolTrimTo_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemPoolTrimTo_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemPoolTrimTo_exit(
    void *btx_handle, lttng_ust_cuda_cuMemPoolTrimTo_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemPoolSetAttribute_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmemoryPool, CUmemPool_attribute, void *, size_t, void *);

void btx_register_callbacks_lttng_ust_cuda_cuMemPoolSetAttribute_entry(
    void *btx_handle, lttng_ust_cuda_cuMemPoolSetAttribute_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemPoolSetAttribute_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemPoolSetAttribute_exit(
    void *btx_handle, lttng_ust_cuda_cuMemPoolSetAttribute_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemPoolGetAttribute_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmemoryPool, CUmemPool_attribute, void *);

void btx_register_callbacks_lttng_ust_cuda_cuMemPoolGetAttribute_entry(
    void *btx_handle, lttng_ust_cuda_cuMemPoolGetAttribute_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemPoolGetAttribute_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, void *);

void btx_register_callbacks_lttng_ust_cuda_cuMemPoolGetAttribute_exit(
    void *btx_handle, lttng_ust_cuda_cuMemPoolGetAttribute_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemPoolSetAccess_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmemoryPool, CUmemAccessDesc *, size_t, size_t, CUmemAccessDesc *);

void btx_register_callbacks_lttng_ust_cuda_cuMemPoolSetAccess_entry(
    void *btx_handle, lttng_ust_cuda_cuMemPoolSetAccess_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemPoolSetAccess_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemPoolSetAccess_exit(
    void *btx_handle, lttng_ust_cuda_cuMemPoolSetAccess_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemPoolGetAccess_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmemAccess_flags *, CUmemoryPool, CUmemLocation *, size_t, CUmemLocation *);

void btx_register_callbacks_lttng_ust_cuda_cuMemPoolGetAccess_entry(
    void *btx_handle, lttng_ust_cuda_cuMemPoolGetAccess_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemPoolGetAccess_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUmemAccess_flags);

void btx_register_callbacks_lttng_ust_cuda_cuMemPoolGetAccess_exit(
    void *btx_handle, lttng_ust_cuda_cuMemPoolGetAccess_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemPoolCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmemoryPool *, CUmemPoolProps *, size_t, CUmemPoolProps *);

void btx_register_callbacks_lttng_ust_cuda_cuMemPoolCreate_entry(
    void *btx_handle, lttng_ust_cuda_cuMemPoolCreate_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemPoolCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUmemoryPool);

void btx_register_callbacks_lttng_ust_cuda_cuMemPoolCreate_exit(
    void *btx_handle, lttng_ust_cuda_cuMemPoolCreate_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemPoolDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmemoryPool);

void btx_register_callbacks_lttng_ust_cuda_cuMemPoolDestroy_entry(
    void *btx_handle, lttng_ust_cuda_cuMemPoolDestroy_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemPoolDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemPoolDestroy_exit(
    void *btx_handle, lttng_ust_cuda_cuMemPoolDestroy_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemGetDefaultMemPool_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmemoryPool *, CUmemLocation *, CUmemAllocationType, size_t, CUmemLocation *);

void btx_register_callbacks_lttng_ust_cuda_cuMemGetDefaultMemPool_entry(
    void *btx_handle, lttng_ust_cuda_cuMemGetDefaultMemPool_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemGetDefaultMemPool_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUmemoryPool);

void btx_register_callbacks_lttng_ust_cuda_cuMemGetDefaultMemPool_exit(
    void *btx_handle, lttng_ust_cuda_cuMemGetDefaultMemPool_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemGetMemPool_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmemoryPool *, CUmemLocation *, CUmemAllocationType, size_t, CUmemLocation *);

void btx_register_callbacks_lttng_ust_cuda_cuMemGetMemPool_entry(
    void *btx_handle, lttng_ust_cuda_cuMemGetMemPool_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemGetMemPool_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUmemoryPool);

void btx_register_callbacks_lttng_ust_cuda_cuMemGetMemPool_exit(
    void *btx_handle, lttng_ust_cuda_cuMemGetMemPool_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemSetMemPool_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmemLocation *, CUmemAllocationType, CUmemoryPool, size_t, CUmemLocation *);

void btx_register_callbacks_lttng_ust_cuda_cuMemSetMemPool_entry(
    void *btx_handle, lttng_ust_cuda_cuMemSetMemPool_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemSetMemPool_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemSetMemPool_exit(
    void *btx_handle, lttng_ust_cuda_cuMemSetMemPool_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemAllocFromPoolAsync_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr *, size_t, CUmemoryPool, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemAllocFromPoolAsync_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuMemAllocFromPoolAsync_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemAllocFromPoolAsync_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUdeviceptr);

void btx_register_callbacks_lttng_ust_cuda_cuMemAllocFromPoolAsync_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuMemAllocFromPoolAsync_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemPoolExportToShareableHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, CUmemoryPool, CUmemAllocationHandleType, unsigned long long int);

void btx_register_callbacks_lttng_ust_cuda_cuMemPoolExportToShareableHandle_entry(
    void *btx_handle, lttng_ust_cuda_cuMemPoolExportToShareableHandle_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemPoolExportToShareableHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, void *);

void btx_register_callbacks_lttng_ust_cuda_cuMemPoolExportToShareableHandle_exit(
    void *btx_handle, lttng_ust_cuda_cuMemPoolExportToShareableHandle_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemPoolImportFromShareableHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmemoryPool *, void *, CUmemAllocationHandleType, unsigned long long int, size_t, void *);

void btx_register_callbacks_lttng_ust_cuda_cuMemPoolImportFromShareableHandle_entry(
    void *btx_handle, lttng_ust_cuda_cuMemPoolImportFromShareableHandle_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemPoolImportFromShareableHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUmemoryPool);

void btx_register_callbacks_lttng_ust_cuda_cuMemPoolImportFromShareableHandle_exit(
    void *btx_handle, lttng_ust_cuda_cuMemPoolImportFromShareableHandle_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemPoolExportPointer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmemPoolPtrExportData *, CUdeviceptr);

void btx_register_callbacks_lttng_ust_cuda_cuMemPoolExportPointer_entry(
    void *btx_handle, lttng_ust_cuda_cuMemPoolExportPointer_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemPoolExportPointer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUmemPoolPtrExportData *);

void btx_register_callbacks_lttng_ust_cuda_cuMemPoolExportPointer_exit(
    void *btx_handle, lttng_ust_cuda_cuMemPoolExportPointer_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemPoolImportPointer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr *, CUmemoryPool, CUmemPoolPtrExportData *, size_t, CUmemPoolPtrExportData *);

void btx_register_callbacks_lttng_ust_cuda_cuMemPoolImportPointer_entry(
    void *btx_handle, lttng_ust_cuda_cuMemPoolImportPointer_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemPoolImportPointer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUdeviceptr);

void btx_register_callbacks_lttng_ust_cuda_cuMemPoolImportPointer_exit(
    void *btx_handle, lttng_ust_cuda_cuMemPoolImportPointer_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMulticastCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmemGenericAllocationHandle *, CUmulticastObjectProp *, size_t, CUmulticastObjectProp *);

void btx_register_callbacks_lttng_ust_cuda_cuMulticastCreate_entry(
    void *btx_handle, lttng_ust_cuda_cuMulticastCreate_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMulticastCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUmemGenericAllocationHandle);

void btx_register_callbacks_lttng_ust_cuda_cuMulticastCreate_exit(
    void *btx_handle, lttng_ust_cuda_cuMulticastCreate_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMulticastAddDevice_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmemGenericAllocationHandle, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuMulticastAddDevice_entry(
    void *btx_handle, lttng_ust_cuda_cuMulticastAddDevice_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMulticastAddDevice_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMulticastAddDevice_exit(
    void *btx_handle, lttng_ust_cuda_cuMulticastAddDevice_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMulticastBindMem_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmemGenericAllocationHandle, size_t, CUmemGenericAllocationHandle, size_t, size_t, unsigned long long int);

void btx_register_callbacks_lttng_ust_cuda_cuMulticastBindMem_entry(
    void *btx_handle, lttng_ust_cuda_cuMulticastBindMem_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMulticastBindMem_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMulticastBindMem_exit(
    void *btx_handle, lttng_ust_cuda_cuMulticastBindMem_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMulticastBindAddr_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmemGenericAllocationHandle, size_t, CUdeviceptr, size_t, unsigned long long int);

void btx_register_callbacks_lttng_ust_cuda_cuMulticastBindAddr_entry(
    void *btx_handle, lttng_ust_cuda_cuMulticastBindAddr_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMulticastBindAddr_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMulticastBindAddr_exit(
    void *btx_handle, lttng_ust_cuda_cuMulticastBindAddr_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMulticastUnbind_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmemGenericAllocationHandle, CUdevice, size_t, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMulticastUnbind_entry(
    void *btx_handle, lttng_ust_cuda_cuMulticastUnbind_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMulticastUnbind_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMulticastUnbind_exit(
    void *btx_handle, lttng_ust_cuda_cuMulticastUnbind_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMulticastGetGranularity_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, size_t *, CUmulticastObjectProp *, CUmulticastGranularity_flags, size_t, CUmulticastObjectProp *);

void btx_register_callbacks_lttng_ust_cuda_cuMulticastGetGranularity_entry(
    void *btx_handle, lttng_ust_cuda_cuMulticastGetGranularity_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMulticastGetGranularity_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMulticastGetGranularity_exit(
    void *btx_handle, lttng_ust_cuda_cuMulticastGetGranularity_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuPointerGetAttribute_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, CUpointer_attribute, CUdeviceptr);

void btx_register_callbacks_lttng_ust_cuda_cuPointerGetAttribute_entry(
    void *btx_handle, lttng_ust_cuda_cuPointerGetAttribute_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuPointerGetAttribute_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, void *);

void btx_register_callbacks_lttng_ust_cuda_cuPointerGetAttribute_exit(
    void *btx_handle, lttng_ust_cuda_cuPointerGetAttribute_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemPrefetchAsync_v2_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, size_t, CUmemLocation, unsigned int, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemPrefetchAsync_v2_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuMemPrefetchAsync_v2_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemPrefetchAsync_v2_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemPrefetchAsync_v2_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuMemPrefetchAsync_v2_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemAdvise_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, size_t, CUmem_advise, CUmemLocation);

void btx_register_callbacks_lttng_ust_cuda_cuMemAdvise_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuMemAdvise_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemAdvise_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemAdvise_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuMemAdvise_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemPrefetchBatchAsync_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr *, size_t *, size_t, CUmemLocation *, size_t *, size_t, unsigned long long int, CUstream, size_t, CUdeviceptr *, size_t, size_t *, size_t, CUmemLocation *, size_t, size_t *);

void btx_register_callbacks_lttng_ust_cuda_cuMemPrefetchBatchAsync_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuMemPrefetchBatchAsync_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemPrefetchBatchAsync_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemPrefetchBatchAsync_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuMemPrefetchBatchAsync_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemDiscardBatchAsync_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr *, size_t *, size_t, unsigned long long int, CUstream, size_t, CUdeviceptr *, size_t, size_t *);

void btx_register_callbacks_lttng_ust_cuda_cuMemDiscardBatchAsync_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuMemDiscardBatchAsync_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemDiscardBatchAsync_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemDiscardBatchAsync_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuMemDiscardBatchAsync_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemDiscardAndPrefetchBatchAsync_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr *, size_t *, size_t, CUmemLocation *, size_t *, size_t, unsigned long long int, CUstream, size_t, CUdeviceptr *, size_t, size_t *, size_t, CUmemLocation *, size_t, size_t *);

void btx_register_callbacks_lttng_ust_cuda_cuMemDiscardAndPrefetchBatchAsync_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuMemDiscardAndPrefetchBatchAsync_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemDiscardAndPrefetchBatchAsync_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemDiscardAndPrefetchBatchAsync_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuMemDiscardAndPrefetchBatchAsync_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemRangeGetAttribute_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, size_t, CUmem_range_attribute, CUdeviceptr, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemRangeGetAttribute_entry(
    void *btx_handle, lttng_ust_cuda_cuMemRangeGetAttribute_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemRangeGetAttribute_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, void *);

void btx_register_callbacks_lttng_ust_cuda_cuMemRangeGetAttribute_exit(
    void *btx_handle, lttng_ust_cuda_cuMemRangeGetAttribute_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemRangeGetAttributes_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void **, size_t *, CUmem_range_attribute *, size_t, CUdeviceptr, size_t, size_t, CUmem_range_attribute *, size_t, size_t *);

void btx_register_callbacks_lttng_ust_cuda_cuMemRangeGetAttributes_entry(
    void *btx_handle, lttng_ust_cuda_cuMemRangeGetAttributes_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemRangeGetAttributes_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemRangeGetAttributes_exit(
    void *btx_handle, lttng_ust_cuda_cuMemRangeGetAttributes_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuPointerSetAttribute_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, CUpointer_attribute, CUdeviceptr, size_t, void *);

void btx_register_callbacks_lttng_ust_cuda_cuPointerSetAttribute_entry(
    void *btx_handle, lttng_ust_cuda_cuPointerSetAttribute_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuPointerSetAttribute_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuPointerSetAttribute_exit(
    void *btx_handle, lttng_ust_cuda_cuPointerSetAttribute_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuPointerGetAttributes_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, unsigned int, CUpointer_attribute *, void **, CUdeviceptr, size_t, CUpointer_attribute *);

void btx_register_callbacks_lttng_ust_cuda_cuPointerGetAttributes_entry(
    void *btx_handle, lttng_ust_cuda_cuPointerGetAttributes_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuPointerGetAttributes_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, void * *);

void btx_register_callbacks_lttng_ust_cuda_cuPointerGetAttributes_exit(
    void *btx_handle, lttng_ust_cuda_cuPointerGetAttributes_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream *, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuStreamCreate_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamCreate_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuStreamCreate_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamCreate_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamCreateWithPriority_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream *, unsigned int, int);

void btx_register_callbacks_lttng_ust_cuda_cuStreamCreateWithPriority_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamCreateWithPriority_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamCreateWithPriority_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuStreamCreateWithPriority_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamCreateWithPriority_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetPriority_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, int *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetPriority_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamGetPriority_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetPriority_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, int);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetPriority_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamGetPriority_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetDevice_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUdevice *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetDevice_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamGetDevice_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetDevice_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetDevice_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamGetDevice_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetFlags_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, unsigned int *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetFlags_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamGetFlags_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetFlags_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetFlags_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamGetFlags_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetId_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, unsigned long long int *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetId_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamGetId_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetId_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, unsigned long long int);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetId_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamGetId_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetCtx_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUcontext *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetCtx_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamGetCtx_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetCtx_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUcontext);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetCtx_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamGetCtx_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetCtx_v2_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUcontext *, CUgreenCtx *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetCtx_v2_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamGetCtx_v2_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetCtx_v2_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUcontext, CUgreenCtx);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetCtx_v2_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamGetCtx_v2_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamWaitEvent_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUevent, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuStreamWaitEvent_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamWaitEvent_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamWaitEvent_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamWaitEvent_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamWaitEvent_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamAddCallback_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUstreamCallback, void *, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuStreamAddCallback_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamAddCallback_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamAddCallback_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamAddCallback_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamAddCallback_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamBeginCapture_v2_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUstreamCaptureMode);

void btx_register_callbacks_lttng_ust_cuda_cuStreamBeginCapture_v2_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamBeginCapture_v2_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamBeginCapture_v2_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamBeginCapture_v2_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamBeginCapture_v2_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamBeginCaptureToGraph_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUgraph, CUgraphNode *, CUgraphEdgeData *, size_t, CUstreamCaptureMode, size_t, CUgraphNode *, size_t, CUgraphEdgeData *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamBeginCaptureToGraph_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamBeginCaptureToGraph_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamBeginCaptureToGraph_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamBeginCaptureToGraph_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamBeginCaptureToGraph_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuThreadExchangeStreamCaptureMode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstreamCaptureMode *, CUstreamCaptureMode);

void btx_register_callbacks_lttng_ust_cuda_cuThreadExchangeStreamCaptureMode_entry(
    void *btx_handle, lttng_ust_cuda_cuThreadExchangeStreamCaptureMode_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuThreadExchangeStreamCaptureMode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUstreamCaptureMode);

void btx_register_callbacks_lttng_ust_cuda_cuThreadExchangeStreamCaptureMode_exit(
    void *btx_handle, lttng_ust_cuda_cuThreadExchangeStreamCaptureMode_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamEndCapture_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUgraph *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamEndCapture_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamEndCapture_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamEndCapture_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUgraph);

void btx_register_callbacks_lttng_ust_cuda_cuStreamEndCapture_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamEndCapture_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamIsCapturing_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUstreamCaptureStatus *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamIsCapturing_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamIsCapturing_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamIsCapturing_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUstreamCaptureStatus);

void btx_register_callbacks_lttng_ust_cuda_cuStreamIsCapturing_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamIsCapturing_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetCaptureInfo_v3_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUstreamCaptureStatus *, cuuint64_t *, CUgraph *, CUgraphNode **, CUgraphEdgeData **, size_t *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetCaptureInfo_v3_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamGetCaptureInfo_v3_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetCaptureInfo_v3_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUstreamCaptureStatus, cuuint64_t, CUgraph, size_t, size_t, CUgraphNode *, size_t, CUgraphEdgeData *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetCaptureInfo_v3_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamGetCaptureInfo_v3_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamUpdateCaptureDependencies_v2_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUgraphNode *, CUgraphEdgeData *, size_t, unsigned int, size_t, CUgraphNode *, size_t, CUgraphEdgeData *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamUpdateCaptureDependencies_v2_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamUpdateCaptureDependencies_v2_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamUpdateCaptureDependencies_v2_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamUpdateCaptureDependencies_v2_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamUpdateCaptureDependencies_v2_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamAttachMemAsync_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUdeviceptr, size_t, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuStreamAttachMemAsync_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamAttachMemAsync_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamAttachMemAsync_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamAttachMemAsync_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamAttachMemAsync_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamQuery_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuStreamQuery_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamQuery_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamQuery_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamQuery_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamQuery_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamSynchronize_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuStreamSynchronize_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamSynchronize_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamSynchronize_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamSynchronize_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamSynchronize_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamDestroy_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuStreamDestroy_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamDestroy_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamDestroy_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamDestroy_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamDestroy_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamCopyAttributes_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuStreamCopyAttributes_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamCopyAttributes_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamCopyAttributes_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamCopyAttributes_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamCopyAttributes_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetAttribute_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUstreamAttrID, CUstreamAttrValue *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetAttribute_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamGetAttribute_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetAttribute_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUstreamAttrValue *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetAttribute_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamGetAttribute_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamSetAttribute_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUstreamAttrID, CUstreamAttrValue *, size_t, CUstreamAttrValue *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamSetAttribute_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamSetAttribute_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamSetAttribute_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamSetAttribute_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamSetAttribute_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuEventCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUevent *, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuEventCreate_entry(
    void *btx_handle, lttng_ust_cuda_cuEventCreate_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuEventCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUevent);

void btx_register_callbacks_lttng_ust_cuda_cuEventCreate_exit(
    void *btx_handle, lttng_ust_cuda_cuEventCreate_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuEventRecord_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUevent, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuEventRecord_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuEventRecord_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuEventRecord_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuEventRecord_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuEventRecord_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuEventRecordWithFlags_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUevent, CUstream, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuEventRecordWithFlags_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuEventRecordWithFlags_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuEventRecordWithFlags_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuEventRecordWithFlags_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuEventRecordWithFlags_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuEventQuery_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUevent);

void btx_register_callbacks_lttng_ust_cuda_cuEventQuery_entry(
    void *btx_handle, lttng_ust_cuda_cuEventQuery_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuEventQuery_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuEventQuery_exit(
    void *btx_handle, lttng_ust_cuda_cuEventQuery_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuEventSynchronize_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUevent);

void btx_register_callbacks_lttng_ust_cuda_cuEventSynchronize_entry(
    void *btx_handle, lttng_ust_cuda_cuEventSynchronize_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuEventSynchronize_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuEventSynchronize_exit(
    void *btx_handle, lttng_ust_cuda_cuEventSynchronize_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuEventDestroy_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUevent);

void btx_register_callbacks_lttng_ust_cuda_cuEventDestroy_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuEventDestroy_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuEventDestroy_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuEventDestroy_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuEventDestroy_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuEventElapsedTime_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, float *, CUevent, CUevent);

void btx_register_callbacks_lttng_ust_cuda_cuEventElapsedTime_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuEventElapsedTime_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuEventElapsedTime_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, float);

void btx_register_callbacks_lttng_ust_cuda_cuEventElapsedTime_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuEventElapsedTime_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuImportExternalMemory_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUexternalMemory *, CUDA_EXTERNAL_MEMORY_HANDLE_DESC *, size_t, CUDA_EXTERNAL_MEMORY_HANDLE_DESC *);

void btx_register_callbacks_lttng_ust_cuda_cuImportExternalMemory_entry(
    void *btx_handle, lttng_ust_cuda_cuImportExternalMemory_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuImportExternalMemory_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUexternalMemory);

void btx_register_callbacks_lttng_ust_cuda_cuImportExternalMemory_exit(
    void *btx_handle, lttng_ust_cuda_cuImportExternalMemory_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuExternalMemoryGetMappedBuffer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr *, CUexternalMemory, CUDA_EXTERNAL_MEMORY_BUFFER_DESC *, size_t, CUDA_EXTERNAL_MEMORY_BUFFER_DESC *);

void btx_register_callbacks_lttng_ust_cuda_cuExternalMemoryGetMappedBuffer_entry(
    void *btx_handle, lttng_ust_cuda_cuExternalMemoryGetMappedBuffer_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuExternalMemoryGetMappedBuffer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUdeviceptr);

void btx_register_callbacks_lttng_ust_cuda_cuExternalMemoryGetMappedBuffer_exit(
    void *btx_handle, lttng_ust_cuda_cuExternalMemoryGetMappedBuffer_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuExternalMemoryGetMappedMipmappedArray_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmipmappedArray *, CUexternalMemory, CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC *, size_t, CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC *);

void btx_register_callbacks_lttng_ust_cuda_cuExternalMemoryGetMappedMipmappedArray_entry(
    void *btx_handle, lttng_ust_cuda_cuExternalMemoryGetMappedMipmappedArray_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuExternalMemoryGetMappedMipmappedArray_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUmipmappedArray);

void btx_register_callbacks_lttng_ust_cuda_cuExternalMemoryGetMappedMipmappedArray_exit(
    void *btx_handle, lttng_ust_cuda_cuExternalMemoryGetMappedMipmappedArray_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDestroyExternalMemory_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUexternalMemory);

void btx_register_callbacks_lttng_ust_cuda_cuDestroyExternalMemory_entry(
    void *btx_handle, lttng_ust_cuda_cuDestroyExternalMemory_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDestroyExternalMemory_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuDestroyExternalMemory_exit(
    void *btx_handle, lttng_ust_cuda_cuDestroyExternalMemory_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuImportExternalSemaphore_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUexternalSemaphore *, CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC *, size_t, CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC *);

void btx_register_callbacks_lttng_ust_cuda_cuImportExternalSemaphore_entry(
    void *btx_handle, lttng_ust_cuda_cuImportExternalSemaphore_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuImportExternalSemaphore_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUexternalSemaphore);

void btx_register_callbacks_lttng_ust_cuda_cuImportExternalSemaphore_exit(
    void *btx_handle, lttng_ust_cuda_cuImportExternalSemaphore_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuSignalExternalSemaphoresAsync_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUexternalSemaphore *, CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS *, unsigned int, CUstream, size_t, CUexternalSemaphore *, size_t, CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS *);

void btx_register_callbacks_lttng_ust_cuda_cuSignalExternalSemaphoresAsync_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuSignalExternalSemaphoresAsync_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuSignalExternalSemaphoresAsync_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuSignalExternalSemaphoresAsync_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuSignalExternalSemaphoresAsync_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuWaitExternalSemaphoresAsync_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUexternalSemaphore *, CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS *, unsigned int, CUstream, size_t, CUexternalSemaphore *, size_t, CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS *);

void btx_register_callbacks_lttng_ust_cuda_cuWaitExternalSemaphoresAsync_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuWaitExternalSemaphoresAsync_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuWaitExternalSemaphoresAsync_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuWaitExternalSemaphoresAsync_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuWaitExternalSemaphoresAsync_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDestroyExternalSemaphore_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUexternalSemaphore);

void btx_register_callbacks_lttng_ust_cuda_cuDestroyExternalSemaphore_entry(
    void *btx_handle, lttng_ust_cuda_cuDestroyExternalSemaphore_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDestroyExternalSemaphore_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuDestroyExternalSemaphore_exit(
    void *btx_handle, lttng_ust_cuda_cuDestroyExternalSemaphore_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamWaitValue32_v2_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUdeviceptr, cuuint32_t, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuStreamWaitValue32_v2_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamWaitValue32_v2_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamWaitValue32_v2_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamWaitValue32_v2_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamWaitValue32_v2_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamWaitValue64_v2_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUdeviceptr, cuuint64_t, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuStreamWaitValue64_v2_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamWaitValue64_v2_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamWaitValue64_v2_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamWaitValue64_v2_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamWaitValue64_v2_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamWriteValue32_v2_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUdeviceptr, cuuint32_t, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuStreamWriteValue32_v2_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamWriteValue32_v2_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamWriteValue32_v2_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamWriteValue32_v2_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamWriteValue32_v2_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamWriteValue64_v2_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUdeviceptr, cuuint64_t, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuStreamWriteValue64_v2_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamWriteValue64_v2_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamWriteValue64_v2_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamWriteValue64_v2_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamWriteValue64_v2_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamBatchMemOp_v2_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, unsigned int, CUstreamBatchMemOpParams *, unsigned int, size_t, CUstreamBatchMemOpParams *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamBatchMemOp_v2_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamBatchMemOp_v2_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamBatchMemOp_v2_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamBatchMemOp_v2_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamBatchMemOp_v2_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuFuncGetAttribute_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, CUfunction_attribute, CUfunction);

void btx_register_callbacks_lttng_ust_cuda_cuFuncGetAttribute_entry(
    void *btx_handle, lttng_ust_cuda_cuFuncGetAttribute_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuFuncGetAttribute_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, int);

void btx_register_callbacks_lttng_ust_cuda_cuFuncGetAttribute_exit(
    void *btx_handle, lttng_ust_cuda_cuFuncGetAttribute_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuFuncSetAttribute_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUfunction, CUfunction_attribute, int);

void btx_register_callbacks_lttng_ust_cuda_cuFuncSetAttribute_entry(
    void *btx_handle, lttng_ust_cuda_cuFuncSetAttribute_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuFuncSetAttribute_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuFuncSetAttribute_exit(
    void *btx_handle, lttng_ust_cuda_cuFuncSetAttribute_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuFuncSetCacheConfig_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUfunction, CUfunc_cache);

void btx_register_callbacks_lttng_ust_cuda_cuFuncSetCacheConfig_entry(
    void *btx_handle, lttng_ust_cuda_cuFuncSetCacheConfig_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuFuncSetCacheConfig_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuFuncSetCacheConfig_exit(
    void *btx_handle, lttng_ust_cuda_cuFuncSetCacheConfig_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuFuncGetModule_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmodule *, CUfunction);

void btx_register_callbacks_lttng_ust_cuda_cuFuncGetModule_entry(
    void *btx_handle, lttng_ust_cuda_cuFuncGetModule_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuFuncGetModule_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUmodule);

void btx_register_callbacks_lttng_ust_cuda_cuFuncGetModule_exit(
    void *btx_handle, lttng_ust_cuda_cuFuncGetModule_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuFuncGetName_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char **, CUfunction);

void btx_register_callbacks_lttng_ust_cuda_cuFuncGetName_entry(
    void *btx_handle, lttng_ust_cuda_cuFuncGetName_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuFuncGetName_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, char *);

void btx_register_callbacks_lttng_ust_cuda_cuFuncGetName_exit(
    void *btx_handle, lttng_ust_cuda_cuFuncGetName_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuFuncGetParamInfo_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUfunction, size_t, size_t *, size_t *);

void btx_register_callbacks_lttng_ust_cuda_cuFuncGetParamInfo_entry(
    void *btx_handle, lttng_ust_cuda_cuFuncGetParamInfo_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuFuncGetParamInfo_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuFuncGetParamInfo_exit(
    void *btx_handle, lttng_ust_cuda_cuFuncGetParamInfo_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuFuncIsLoaded_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUfunctionLoadingState *, CUfunction);

void btx_register_callbacks_lttng_ust_cuda_cuFuncIsLoaded_entry(
    void *btx_handle, lttng_ust_cuda_cuFuncIsLoaded_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuFuncIsLoaded_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUfunctionLoadingState);

void btx_register_callbacks_lttng_ust_cuda_cuFuncIsLoaded_exit(
    void *btx_handle, lttng_ust_cuda_cuFuncIsLoaded_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuFuncLoad_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUfunction);

void btx_register_callbacks_lttng_ust_cuda_cuFuncLoad_entry(
    void *btx_handle, lttng_ust_cuda_cuFuncLoad_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuFuncLoad_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuFuncLoad_exit(
    void *btx_handle, lttng_ust_cuda_cuFuncLoad_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuLaunchKernel_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUfunction, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, CUstream, void **, void **, size_t, void * *);

void btx_register_callbacks_lttng_ust_cuda_cuLaunchKernel_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuLaunchKernel_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuLaunchKernel_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuLaunchKernel_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuLaunchKernel_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuLaunchKernelEx_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUlaunchConfig *, CUfunction, void **, void **, size_t, CUlaunchConfig *, size_t, CUlaunchAttribute *, size_t, void * *);

void btx_register_callbacks_lttng_ust_cuda_cuLaunchKernelEx_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuLaunchKernelEx_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuLaunchKernelEx_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuLaunchKernelEx_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuLaunchKernelEx_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuLaunchCooperativeKernel_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUfunction, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, CUstream, void **);

void btx_register_callbacks_lttng_ust_cuda_cuLaunchCooperativeKernel_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuLaunchCooperativeKernel_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuLaunchCooperativeKernel_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuLaunchCooperativeKernel_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuLaunchCooperativeKernel_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuLaunchCooperativeKernelMultiDevice_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUDA_LAUNCH_PARAMS *, unsigned int, unsigned int, size_t, CUDA_LAUNCH_PARAMS *);

void btx_register_callbacks_lttng_ust_cuda_cuLaunchCooperativeKernelMultiDevice_entry(
    void *btx_handle, lttng_ust_cuda_cuLaunchCooperativeKernelMultiDevice_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuLaunchCooperativeKernelMultiDevice_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuLaunchCooperativeKernelMultiDevice_exit(
    void *btx_handle, lttng_ust_cuda_cuLaunchCooperativeKernelMultiDevice_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuLaunchHostFunc_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUhostFn, void *);

void btx_register_callbacks_lttng_ust_cuda_cuLaunchHostFunc_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuLaunchHostFunc_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuLaunchHostFunc_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuLaunchHostFunc_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuLaunchHostFunc_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuFuncSetBlockShape_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUfunction, int, int, int);

void btx_register_callbacks_lttng_ust_cuda_cuFuncSetBlockShape_entry(
    void *btx_handle, lttng_ust_cuda_cuFuncSetBlockShape_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuFuncSetBlockShape_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuFuncSetBlockShape_exit(
    void *btx_handle, lttng_ust_cuda_cuFuncSetBlockShape_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuFuncSetSharedSize_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUfunction, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuFuncSetSharedSize_entry(
    void *btx_handle, lttng_ust_cuda_cuFuncSetSharedSize_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuFuncSetSharedSize_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuFuncSetSharedSize_exit(
    void *btx_handle, lttng_ust_cuda_cuFuncSetSharedSize_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuParamSetSize_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUfunction, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuParamSetSize_entry(
    void *btx_handle, lttng_ust_cuda_cuParamSetSize_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuParamSetSize_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuParamSetSize_exit(
    void *btx_handle, lttng_ust_cuda_cuParamSetSize_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuParamSeti_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUfunction, int, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuParamSeti_entry(
    void *btx_handle, lttng_ust_cuda_cuParamSeti_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuParamSeti_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuParamSeti_exit(
    void *btx_handle, lttng_ust_cuda_cuParamSeti_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuParamSetf_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUfunction, int, float);

void btx_register_callbacks_lttng_ust_cuda_cuParamSetf_entry(
    void *btx_handle, lttng_ust_cuda_cuParamSetf_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuParamSetf_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuParamSetf_exit(
    void *btx_handle, lttng_ust_cuda_cuParamSetf_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuParamSetv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUfunction, int, void *, unsigned int, size_t, void *);

void btx_register_callbacks_lttng_ust_cuda_cuParamSetv_entry(
    void *btx_handle, lttng_ust_cuda_cuParamSetv_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuParamSetv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuParamSetv_exit(
    void *btx_handle, lttng_ust_cuda_cuParamSetv_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuLaunch_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUfunction);

void btx_register_callbacks_lttng_ust_cuda_cuLaunch_entry(
    void *btx_handle, lttng_ust_cuda_cuLaunch_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuLaunch_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuLaunch_exit(
    void *btx_handle, lttng_ust_cuda_cuLaunch_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuLaunchGrid_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUfunction, int, int);

void btx_register_callbacks_lttng_ust_cuda_cuLaunchGrid_entry(
    void *btx_handle, lttng_ust_cuda_cuLaunchGrid_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuLaunchGrid_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuLaunchGrid_exit(
    void *btx_handle, lttng_ust_cuda_cuLaunchGrid_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuLaunchGridAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUfunction, int, int, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuLaunchGridAsync_entry(
    void *btx_handle, lttng_ust_cuda_cuLaunchGridAsync_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuLaunchGridAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuLaunchGridAsync_exit(
    void *btx_handle, lttng_ust_cuda_cuLaunchGridAsync_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuParamSetTexRef_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUfunction, int, CUtexref);

void btx_register_callbacks_lttng_ust_cuda_cuParamSetTexRef_entry(
    void *btx_handle, lttng_ust_cuda_cuParamSetTexRef_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuParamSetTexRef_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuParamSetTexRef_exit(
    void *btx_handle, lttng_ust_cuda_cuParamSetTexRef_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuFuncSetSharedMemConfig_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUfunction, CUsharedconfig);

void btx_register_callbacks_lttng_ust_cuda_cuFuncSetSharedMemConfig_entry(
    void *btx_handle, lttng_ust_cuda_cuFuncSetSharedMemConfig_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuFuncSetSharedMemConfig_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuFuncSetSharedMemConfig_exit(
    void *btx_handle, lttng_ust_cuda_cuFuncSetSharedMemConfig_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraph *, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuGraphCreate_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphCreate_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUgraph);

void btx_register_callbacks_lttng_ust_cuda_cuGraphCreate_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphCreate_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphAddKernelNode_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode *, CUgraph, CUgraphNode *, size_t, CUDA_KERNEL_NODE_PARAMS *, size_t, CUgraphNode *, size_t, CUDA_KERNEL_NODE_PARAMS *, size_t, void * *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphAddKernelNode_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphAddKernelNode_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphAddKernelNode_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUgraphNode);

void btx_register_callbacks_lttng_ust_cuda_cuGraphAddKernelNode_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphAddKernelNode_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphKernelNodeGetParams_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode, CUDA_KERNEL_NODE_PARAMS *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphKernelNodeGetParams_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphKernelNodeGetParams_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphKernelNodeGetParams_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUDA_KERNEL_NODE_PARAMS *, size_t, void * *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphKernelNodeGetParams_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphKernelNodeGetParams_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphKernelNodeSetParams_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode, CUDA_KERNEL_NODE_PARAMS *, size_t, CUDA_KERNEL_NODE_PARAMS *, size_t, void * *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphKernelNodeSetParams_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphKernelNodeSetParams_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphKernelNodeSetParams_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphKernelNodeSetParams_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphKernelNodeSetParams_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphAddMemcpyNode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode *, CUgraph, CUgraphNode *, size_t, CUDA_MEMCPY3D *, CUcontext, size_t, CUgraphNode *, size_t, CUDA_MEMCPY3D *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphAddMemcpyNode_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphAddMemcpyNode_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphAddMemcpyNode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUgraphNode);

void btx_register_callbacks_lttng_ust_cuda_cuGraphAddMemcpyNode_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphAddMemcpyNode_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphMemcpyNodeGetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode, CUDA_MEMCPY3D *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphMemcpyNodeGetParams_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphMemcpyNodeGetParams_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphMemcpyNodeGetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUDA_MEMCPY3D *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphMemcpyNodeGetParams_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphMemcpyNodeGetParams_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphMemcpyNodeSetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode, CUDA_MEMCPY3D *, size_t, CUDA_MEMCPY3D *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphMemcpyNodeSetParams_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphMemcpyNodeSetParams_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphMemcpyNodeSetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphMemcpyNodeSetParams_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphMemcpyNodeSetParams_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphAddMemsetNode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode *, CUgraph, CUgraphNode *, size_t, CUDA_MEMSET_NODE_PARAMS *, CUcontext, size_t, CUgraphNode *, size_t, CUDA_MEMSET_NODE_PARAMS *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphAddMemsetNode_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphAddMemsetNode_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphAddMemsetNode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUgraphNode);

void btx_register_callbacks_lttng_ust_cuda_cuGraphAddMemsetNode_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphAddMemsetNode_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphMemsetNodeGetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode, CUDA_MEMSET_NODE_PARAMS *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphMemsetNodeGetParams_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphMemsetNodeGetParams_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphMemsetNodeGetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUDA_MEMSET_NODE_PARAMS *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphMemsetNodeGetParams_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphMemsetNodeGetParams_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphMemsetNodeSetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode, CUDA_MEMSET_NODE_PARAMS *, size_t, CUDA_MEMSET_NODE_PARAMS *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphMemsetNodeSetParams_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphMemsetNodeSetParams_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphMemsetNodeSetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphMemsetNodeSetParams_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphMemsetNodeSetParams_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphAddHostNode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode *, CUgraph, CUgraphNode *, size_t, CUDA_HOST_NODE_PARAMS *, size_t, CUgraphNode *, size_t, CUDA_HOST_NODE_PARAMS *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphAddHostNode_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphAddHostNode_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphAddHostNode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUgraphNode);

void btx_register_callbacks_lttng_ust_cuda_cuGraphAddHostNode_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphAddHostNode_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphHostNodeGetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode, CUDA_HOST_NODE_PARAMS *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphHostNodeGetParams_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphHostNodeGetParams_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphHostNodeGetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUDA_HOST_NODE_PARAMS *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphHostNodeGetParams_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphHostNodeGetParams_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphHostNodeSetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode, CUDA_HOST_NODE_PARAMS *, size_t, CUDA_HOST_NODE_PARAMS *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphHostNodeSetParams_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphHostNodeSetParams_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphHostNodeSetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphHostNodeSetParams_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphHostNodeSetParams_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphAddChildGraphNode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode *, CUgraph, CUgraphNode *, size_t, CUgraph, size_t, CUgraphNode *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphAddChildGraphNode_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphAddChildGraphNode_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphAddChildGraphNode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphAddChildGraphNode_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphAddChildGraphNode_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphChildGraphNodeGetGraph_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode, CUgraph *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphChildGraphNodeGetGraph_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphChildGraphNodeGetGraph_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphChildGraphNodeGetGraph_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUgraph);

void btx_register_callbacks_lttng_ust_cuda_cuGraphChildGraphNodeGetGraph_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphChildGraphNodeGetGraph_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphAddEmptyNode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode *, CUgraph, CUgraphNode *, size_t, size_t, CUgraphNode *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphAddEmptyNode_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphAddEmptyNode_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphAddEmptyNode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUgraphNode);

void btx_register_callbacks_lttng_ust_cuda_cuGraphAddEmptyNode_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphAddEmptyNode_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphAddEventRecordNode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode *, CUgraph, CUgraphNode *, size_t, CUevent, size_t, CUgraphNode *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphAddEventRecordNode_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphAddEventRecordNode_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphAddEventRecordNode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUgraphNode);

void btx_register_callbacks_lttng_ust_cuda_cuGraphAddEventRecordNode_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphAddEventRecordNode_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphEventRecordNodeGetEvent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode, CUevent *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphEventRecordNodeGetEvent_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphEventRecordNodeGetEvent_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphEventRecordNodeGetEvent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUevent);

void btx_register_callbacks_lttng_ust_cuda_cuGraphEventRecordNodeGetEvent_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphEventRecordNodeGetEvent_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphEventRecordNodeSetEvent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode, CUevent);

void btx_register_callbacks_lttng_ust_cuda_cuGraphEventRecordNodeSetEvent_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphEventRecordNodeSetEvent_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphEventRecordNodeSetEvent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphEventRecordNodeSetEvent_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphEventRecordNodeSetEvent_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphAddEventWaitNode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode *, CUgraph, CUgraphNode *, size_t, CUevent, size_t, CUgraphNode *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphAddEventWaitNode_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphAddEventWaitNode_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphAddEventWaitNode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUgraphNode);

void btx_register_callbacks_lttng_ust_cuda_cuGraphAddEventWaitNode_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphAddEventWaitNode_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphEventWaitNodeGetEvent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode, CUevent *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphEventWaitNodeGetEvent_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphEventWaitNodeGetEvent_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphEventWaitNodeGetEvent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUevent);

void btx_register_callbacks_lttng_ust_cuda_cuGraphEventWaitNodeGetEvent_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphEventWaitNodeGetEvent_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphEventWaitNodeSetEvent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode, CUevent);

void btx_register_callbacks_lttng_ust_cuda_cuGraphEventWaitNodeSetEvent_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphEventWaitNodeSetEvent_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphEventWaitNodeSetEvent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphEventWaitNodeSetEvent_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphEventWaitNodeSetEvent_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphAddExternalSemaphoresSignalNode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode *, CUgraph, CUgraphNode *, size_t, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *, size_t, CUgraphNode *, size_t, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphAddExternalSemaphoresSignalNode_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphAddExternalSemaphoresSignalNode_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphAddExternalSemaphoresSignalNode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUgraphNode);

void btx_register_callbacks_lttng_ust_cuda_cuGraphAddExternalSemaphoresSignalNode_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphAddExternalSemaphoresSignalNode_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExternalSemaphoresSignalNodeGetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExternalSemaphoresSignalNodeGetParams_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphExternalSemaphoresSignalNodeGetParams_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExternalSemaphoresSignalNodeGetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExternalSemaphoresSignalNodeGetParams_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphExternalSemaphoresSignalNodeGetParams_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExternalSemaphoresSignalNodeSetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *, size_t, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExternalSemaphoresSignalNodeSetParams_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphExternalSemaphoresSignalNodeSetParams_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExternalSemaphoresSignalNodeSetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExternalSemaphoresSignalNodeSetParams_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphExternalSemaphoresSignalNodeSetParams_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphAddExternalSemaphoresWaitNode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode *, CUgraph, CUgraphNode *, size_t, CUDA_EXT_SEM_WAIT_NODE_PARAMS *, size_t, CUgraphNode *, size_t, CUDA_EXT_SEM_WAIT_NODE_PARAMS *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphAddExternalSemaphoresWaitNode_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphAddExternalSemaphoresWaitNode_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphAddExternalSemaphoresWaitNode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUgraphNode);

void btx_register_callbacks_lttng_ust_cuda_cuGraphAddExternalSemaphoresWaitNode_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphAddExternalSemaphoresWaitNode_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExternalSemaphoresWaitNodeGetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode, CUDA_EXT_SEM_WAIT_NODE_PARAMS *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExternalSemaphoresWaitNodeGetParams_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphExternalSemaphoresWaitNodeGetParams_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExternalSemaphoresWaitNodeGetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUDA_EXT_SEM_WAIT_NODE_PARAMS *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExternalSemaphoresWaitNodeGetParams_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphExternalSemaphoresWaitNodeGetParams_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExternalSemaphoresWaitNodeSetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode, CUDA_EXT_SEM_WAIT_NODE_PARAMS *, size_t, CUDA_EXT_SEM_WAIT_NODE_PARAMS *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExternalSemaphoresWaitNodeSetParams_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphExternalSemaphoresWaitNodeSetParams_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExternalSemaphoresWaitNodeSetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExternalSemaphoresWaitNodeSetParams_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphExternalSemaphoresWaitNodeSetParams_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphAddBatchMemOpNode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode *, CUgraph, CUgraphNode *, size_t, CUDA_BATCH_MEM_OP_NODE_PARAMS *, size_t, CUgraphNode *, size_t, CUDA_BATCH_MEM_OP_NODE_PARAMS *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphAddBatchMemOpNode_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphAddBatchMemOpNode_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphAddBatchMemOpNode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUgraphNode);

void btx_register_callbacks_lttng_ust_cuda_cuGraphAddBatchMemOpNode_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphAddBatchMemOpNode_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphBatchMemOpNodeGetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode, CUDA_BATCH_MEM_OP_NODE_PARAMS *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphBatchMemOpNodeGetParams_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphBatchMemOpNodeGetParams_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphBatchMemOpNodeGetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUDA_BATCH_MEM_OP_NODE_PARAMS *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphBatchMemOpNodeGetParams_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphBatchMemOpNodeGetParams_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphBatchMemOpNodeSetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode, CUDA_BATCH_MEM_OP_NODE_PARAMS *, size_t, CUDA_BATCH_MEM_OP_NODE_PARAMS *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphBatchMemOpNodeSetParams_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphBatchMemOpNodeSetParams_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphBatchMemOpNodeSetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphBatchMemOpNodeSetParams_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphBatchMemOpNodeSetParams_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExecBatchMemOpNodeSetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphExec, CUgraphNode, CUDA_BATCH_MEM_OP_NODE_PARAMS *, size_t, CUDA_BATCH_MEM_OP_NODE_PARAMS *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExecBatchMemOpNodeSetParams_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphExecBatchMemOpNodeSetParams_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExecBatchMemOpNodeSetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExecBatchMemOpNodeSetParams_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphExecBatchMemOpNodeSetParams_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphAddMemAllocNode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode *, CUgraph, CUgraphNode *, size_t, CUDA_MEM_ALLOC_NODE_PARAMS *, size_t, CUgraphNode *, size_t, CUDA_MEM_ALLOC_NODE_PARAMS *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphAddMemAllocNode_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphAddMemAllocNode_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphAddMemAllocNode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUgraphNode);

void btx_register_callbacks_lttng_ust_cuda_cuGraphAddMemAllocNode_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphAddMemAllocNode_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphMemAllocNodeGetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode, CUDA_MEM_ALLOC_NODE_PARAMS *, size_t, CUDA_MEM_ALLOC_NODE_PARAMS *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphMemAllocNodeGetParams_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphMemAllocNodeGetParams_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphMemAllocNodeGetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphMemAllocNodeGetParams_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphMemAllocNodeGetParams_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphAddMemFreeNode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode *, CUgraph, CUgraphNode *, size_t, CUdeviceptr, size_t, CUgraphNode *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphAddMemFreeNode_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphAddMemFreeNode_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphAddMemFreeNode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUgraphNode);

void btx_register_callbacks_lttng_ust_cuda_cuGraphAddMemFreeNode_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphAddMemFreeNode_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphMemFreeNodeGetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode, CUdeviceptr *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphMemFreeNodeGetParams_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphMemFreeNodeGetParams_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphMemFreeNodeGetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUdeviceptr);

void btx_register_callbacks_lttng_ust_cuda_cuGraphMemFreeNodeGetParams_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphMemFreeNodeGetParams_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGraphMemTrim_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGraphMemTrim_entry(
    void *btx_handle, lttng_ust_cuda_cuDeviceGraphMemTrim_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGraphMemTrim_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGraphMemTrim_exit(
    void *btx_handle, lttng_ust_cuda_cuDeviceGraphMemTrim_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetGraphMemAttribute_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdevice, CUgraphMem_attribute, void *);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetGraphMemAttribute_entry(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetGraphMemAttribute_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetGraphMemAttribute_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, void *);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetGraphMemAttribute_exit(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetGraphMemAttribute_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceSetGraphMemAttribute_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdevice, CUgraphMem_attribute, void *, size_t, void *);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceSetGraphMemAttribute_entry(
    void *btx_handle, lttng_ust_cuda_cuDeviceSetGraphMemAttribute_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceSetGraphMemAttribute_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceSetGraphMemAttribute_exit(
    void *btx_handle, lttng_ust_cuda_cuDeviceSetGraphMemAttribute_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphClone_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraph *, CUgraph);

void btx_register_callbacks_lttng_ust_cuda_cuGraphClone_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphClone_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphClone_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUgraph);

void btx_register_callbacks_lttng_ust_cuda_cuGraphClone_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphClone_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphNodeFindInClone_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode *, CUgraphNode, CUgraph);

void btx_register_callbacks_lttng_ust_cuda_cuGraphNodeFindInClone_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphNodeFindInClone_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphNodeFindInClone_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUgraphNode);

void btx_register_callbacks_lttng_ust_cuda_cuGraphNodeFindInClone_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphNodeFindInClone_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphNodeGetType_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode, CUgraphNodeType *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphNodeGetType_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphNodeGetType_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphNodeGetType_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUgraphNodeType);

void btx_register_callbacks_lttng_ust_cuda_cuGraphNodeGetType_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphNodeGetType_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphGetNodes_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraph, CUgraphNode *, size_t *, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuGraphGetNodes_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphGetNodes_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphGetNodes_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, size_t, CUgraphNode *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphGetNodes_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphGetNodes_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphGetRootNodes_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraph, CUgraphNode *, size_t *, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuGraphGetRootNodes_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphGetRootNodes_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphGetRootNodes_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, size_t, CUgraphNode *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphGetRootNodes_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphGetRootNodes_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphGetEdges_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraph, CUgraphNode *, CUgraphNode *, CUgraphEdgeData *, size_t *, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuGraphGetEdges_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphGetEdges_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphGetEdges_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, size_t, CUgraphNode *, size_t, CUgraphNode *, size_t, CUgraphEdgeData *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphGetEdges_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphGetEdges_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphNodeGetDependencies_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode, CUgraphNode *, CUgraphEdgeData *, size_t *, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuGraphNodeGetDependencies_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphNodeGetDependencies_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphNodeGetDependencies_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, size_t, CUgraphNode *, size_t, CUgraphEdgeData *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphNodeGetDependencies_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphNodeGetDependencies_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphNodeGetDependentNodes_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode, CUgraphNode *, CUgraphEdgeData *, size_t *, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuGraphNodeGetDependentNodes_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphNodeGetDependentNodes_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphNodeGetDependentNodes_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, size_t, CUgraphNode *, size_t, CUgraphEdgeData *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphNodeGetDependentNodes_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphNodeGetDependentNodes_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphAddDependencies_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraph, CUgraphNode *, CUgraphNode *, CUgraphEdgeData *, size_t, size_t, CUgraphNode *, size_t, CUgraphNode *, size_t, CUgraphEdgeData *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphAddDependencies_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphAddDependencies_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphAddDependencies_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphAddDependencies_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphAddDependencies_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphRemoveDependencies_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraph, CUgraphNode *, CUgraphNode *, CUgraphEdgeData *, size_t, size_t, CUgraphNode *, size_t, CUgraphNode *, size_t, CUgraphEdgeData *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphRemoveDependencies_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphRemoveDependencies_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphRemoveDependencies_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphRemoveDependencies_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphRemoveDependencies_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphDestroyNode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode);

void btx_register_callbacks_lttng_ust_cuda_cuGraphDestroyNode_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphDestroyNode_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphDestroyNode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphDestroyNode_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphDestroyNode_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphInstantiateWithFlags_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphExec *, CUgraph, unsigned long long int);

void btx_register_callbacks_lttng_ust_cuda_cuGraphInstantiateWithFlags_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphInstantiateWithFlags_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphInstantiateWithFlags_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUgraphExec);

void btx_register_callbacks_lttng_ust_cuda_cuGraphInstantiateWithFlags_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphInstantiateWithFlags_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphInstantiateWithParams_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphExec *, CUgraph, CUDA_GRAPH_INSTANTIATE_PARAMS *, size_t, CUDA_GRAPH_INSTANTIATE_PARAMS *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphInstantiateWithParams_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphInstantiateWithParams_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphInstantiateWithParams_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUgraphExec);

void btx_register_callbacks_lttng_ust_cuda_cuGraphInstantiateWithParams_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphInstantiateWithParams_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExecGetFlags_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphExec, cuuint64_t *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExecGetFlags_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphExecGetFlags_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExecGetFlags_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, cuuint64_t);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExecGetFlags_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphExecGetFlags_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExecKernelNodeSetParams_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphExec, CUgraphNode, CUDA_KERNEL_NODE_PARAMS *, size_t, CUDA_KERNEL_NODE_PARAMS *, size_t, void * *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExecKernelNodeSetParams_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphExecKernelNodeSetParams_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExecKernelNodeSetParams_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExecKernelNodeSetParams_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphExecKernelNodeSetParams_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExecMemcpyNodeSetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphExec, CUgraphNode, CUDA_MEMCPY3D *, CUcontext, size_t, CUDA_MEMCPY3D *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExecMemcpyNodeSetParams_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphExecMemcpyNodeSetParams_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExecMemcpyNodeSetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExecMemcpyNodeSetParams_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphExecMemcpyNodeSetParams_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExecMemsetNodeSetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphExec, CUgraphNode, CUDA_MEMSET_NODE_PARAMS *, CUcontext, size_t, CUDA_MEMSET_NODE_PARAMS *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExecMemsetNodeSetParams_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphExecMemsetNodeSetParams_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExecMemsetNodeSetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExecMemsetNodeSetParams_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphExecMemsetNodeSetParams_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExecHostNodeSetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphExec, CUgraphNode, CUDA_HOST_NODE_PARAMS *, size_t, CUDA_HOST_NODE_PARAMS *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExecHostNodeSetParams_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphExecHostNodeSetParams_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExecHostNodeSetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExecHostNodeSetParams_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphExecHostNodeSetParams_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExecChildGraphNodeSetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphExec, CUgraphNode, CUgraph);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExecChildGraphNodeSetParams_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphExecChildGraphNodeSetParams_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExecChildGraphNodeSetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExecChildGraphNodeSetParams_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphExecChildGraphNodeSetParams_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExecEventRecordNodeSetEvent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphExec, CUgraphNode, CUevent);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExecEventRecordNodeSetEvent_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphExecEventRecordNodeSetEvent_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExecEventRecordNodeSetEvent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExecEventRecordNodeSetEvent_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphExecEventRecordNodeSetEvent_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExecEventWaitNodeSetEvent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphExec, CUgraphNode, CUevent);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExecEventWaitNodeSetEvent_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphExecEventWaitNodeSetEvent_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExecEventWaitNodeSetEvent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExecEventWaitNodeSetEvent_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphExecEventWaitNodeSetEvent_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExecExternalSemaphoresSignalNodeSetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphExec, CUgraphNode, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *, size_t, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExecExternalSemaphoresSignalNodeSetParams_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphExecExternalSemaphoresSignalNodeSetParams_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExecExternalSemaphoresSignalNodeSetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExecExternalSemaphoresSignalNodeSetParams_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphExecExternalSemaphoresSignalNodeSetParams_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExecExternalSemaphoresWaitNodeSetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphExec, CUgraphNode, CUDA_EXT_SEM_WAIT_NODE_PARAMS *, size_t, CUDA_EXT_SEM_WAIT_NODE_PARAMS *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExecExternalSemaphoresWaitNodeSetParams_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphExecExternalSemaphoresWaitNodeSetParams_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExecExternalSemaphoresWaitNodeSetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExecExternalSemaphoresWaitNodeSetParams_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphExecExternalSemaphoresWaitNodeSetParams_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphNodeSetEnabled_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphExec, CUgraphNode, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuGraphNodeSetEnabled_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphNodeSetEnabled_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphNodeSetEnabled_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphNodeSetEnabled_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphNodeSetEnabled_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphNodeGetEnabled_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphExec, CUgraphNode, unsigned int *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphNodeGetEnabled_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphNodeGetEnabled_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphNodeGetEnabled_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuGraphNodeGetEnabled_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphNodeGetEnabled_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphUpload_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphExec, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuGraphUpload_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphUpload_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphUpload_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphUpload_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphUpload_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphLaunch_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphExec, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuGraphLaunch_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphLaunch_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphLaunch_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphLaunch_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphLaunch_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExecDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphExec);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExecDestroy_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphExecDestroy_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExecDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExecDestroy_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphExecDestroy_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraph);

void btx_register_callbacks_lttng_ust_cuda_cuGraphDestroy_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphDestroy_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphDestroy_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphDestroy_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExecUpdate_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphExec, CUgraph, CUgraphExecUpdateResultInfo *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExecUpdate_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphExecUpdate_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExecUpdate_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUgraphExecUpdateResultInfo *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExecUpdate_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphExecUpdate_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphKernelNodeCopyAttributes_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode, CUgraphNode);

void btx_register_callbacks_lttng_ust_cuda_cuGraphKernelNodeCopyAttributes_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphKernelNodeCopyAttributes_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphKernelNodeCopyAttributes_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphKernelNodeCopyAttributes_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphKernelNodeCopyAttributes_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphKernelNodeGetAttribute_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode, CUkernelNodeAttrID, CUkernelNodeAttrValue *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphKernelNodeGetAttribute_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphKernelNodeGetAttribute_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphKernelNodeGetAttribute_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUkernelNodeAttrValue *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphKernelNodeGetAttribute_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphKernelNodeGetAttribute_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphKernelNodeSetAttribute_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode, CUkernelNodeAttrID, CUkernelNodeAttrValue *, size_t, CUkernelNodeAttrValue *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphKernelNodeSetAttribute_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphKernelNodeSetAttribute_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphKernelNodeSetAttribute_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphKernelNodeSetAttribute_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphKernelNodeSetAttribute_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphDebugDotPrint_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraph, char *, unsigned int, char *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphDebugDotPrint_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphDebugDotPrint_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphDebugDotPrint_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphDebugDotPrint_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphDebugDotPrint_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuUserObjectCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUuserObject *, void *, CUhostFn, unsigned int, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuUserObjectCreate_entry(
    void *btx_handle, lttng_ust_cuda_cuUserObjectCreate_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuUserObjectCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUuserObject);

void btx_register_callbacks_lttng_ust_cuda_cuUserObjectCreate_exit(
    void *btx_handle, lttng_ust_cuda_cuUserObjectCreate_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuUserObjectRetain_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUuserObject, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuUserObjectRetain_entry(
    void *btx_handle, lttng_ust_cuda_cuUserObjectRetain_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuUserObjectRetain_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuUserObjectRetain_exit(
    void *btx_handle, lttng_ust_cuda_cuUserObjectRetain_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuUserObjectRelease_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUuserObject, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuUserObjectRelease_entry(
    void *btx_handle, lttng_ust_cuda_cuUserObjectRelease_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuUserObjectRelease_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuUserObjectRelease_exit(
    void *btx_handle, lttng_ust_cuda_cuUserObjectRelease_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphRetainUserObject_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraph, CUuserObject, unsigned int, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuGraphRetainUserObject_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphRetainUserObject_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphRetainUserObject_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphRetainUserObject_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphRetainUserObject_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphReleaseUserObject_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraph, CUuserObject, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuGraphReleaseUserObject_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphReleaseUserObject_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphReleaseUserObject_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphReleaseUserObject_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphReleaseUserObject_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphAddNode_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode *, CUgraph, CUgraphNode *, CUgraphEdgeData *, size_t, CUgraphNodeParams *, size_t, CUgraphNode *, size_t, CUgraphEdgeData *, size_t, CUgraphNodeParams *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphAddNode_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphAddNode_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphAddNode_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUgraphNode);

void btx_register_callbacks_lttng_ust_cuda_cuGraphAddNode_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphAddNode_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphNodeSetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode, CUgraphNodeParams *, size_t, CUgraphNodeParams *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphNodeSetParams_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphNodeSetParams_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphNodeSetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphNodeSetParams_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphNodeSetParams_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExecNodeSetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphExec, CUgraphNode, CUgraphNodeParams *, size_t, CUgraphNodeParams *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExecNodeSetParams_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphExecNodeSetParams_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExecNodeSetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExecNodeSetParams_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphExecNodeSetParams_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphConditionalHandleCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphConditionalHandle *, CUgraph, CUcontext, unsigned int, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuGraphConditionalHandleCreate_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphConditionalHandleCreate_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphConditionalHandleCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUgraphConditionalHandle);

void btx_register_callbacks_lttng_ust_cuda_cuGraphConditionalHandleCreate_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphConditionalHandleCreate_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuOccupancyMaxActiveBlocksPerMultiprocessor_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, CUfunction, int, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuOccupancyMaxActiveBlocksPerMultiprocessor_entry(
    void *btx_handle, lttng_ust_cuda_cuOccupancyMaxActiveBlocksPerMultiprocessor_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuOccupancyMaxActiveBlocksPerMultiprocessor_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, int);

void btx_register_callbacks_lttng_ust_cuda_cuOccupancyMaxActiveBlocksPerMultiprocessor_exit(
    void *btx_handle, lttng_ust_cuda_cuOccupancyMaxActiveBlocksPerMultiprocessor_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, CUfunction, int, size_t, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_entry(
    void *btx_handle, lttng_ust_cuda_cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, int);

void btx_register_callbacks_lttng_ust_cuda_cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_exit(
    void *btx_handle, lttng_ust_cuda_cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuOccupancyMaxPotentialBlockSize_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, int *, CUfunction, CUoccupancyB2DSize, size_t, int);

void btx_register_callbacks_lttng_ust_cuda_cuOccupancyMaxPotentialBlockSize_entry(
    void *btx_handle, lttng_ust_cuda_cuOccupancyMaxPotentialBlockSize_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuOccupancyMaxPotentialBlockSize_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, int, int);

void btx_register_callbacks_lttng_ust_cuda_cuOccupancyMaxPotentialBlockSize_exit(
    void *btx_handle, lttng_ust_cuda_cuOccupancyMaxPotentialBlockSize_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuOccupancyMaxPotentialBlockSizeWithFlags_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, int *, CUfunction, CUoccupancyB2DSize, size_t, int, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuOccupancyMaxPotentialBlockSizeWithFlags_entry(
    void *btx_handle, lttng_ust_cuda_cuOccupancyMaxPotentialBlockSizeWithFlags_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuOccupancyMaxPotentialBlockSizeWithFlags_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, int, int);

void btx_register_callbacks_lttng_ust_cuda_cuOccupancyMaxPotentialBlockSizeWithFlags_exit(
    void *btx_handle, lttng_ust_cuda_cuOccupancyMaxPotentialBlockSizeWithFlags_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuOccupancyAvailableDynamicSMemPerBlock_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, size_t *, CUfunction, int, int);

void btx_register_callbacks_lttng_ust_cuda_cuOccupancyAvailableDynamicSMemPerBlock_entry(
    void *btx_handle, lttng_ust_cuda_cuOccupancyAvailableDynamicSMemPerBlock_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuOccupancyAvailableDynamicSMemPerBlock_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuOccupancyAvailableDynamicSMemPerBlock_exit(
    void *btx_handle, lttng_ust_cuda_cuOccupancyAvailableDynamicSMemPerBlock_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuOccupancyMaxPotentialClusterSize_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, CUfunction, CUlaunchConfig *, size_t, CUlaunchConfig *);

void btx_register_callbacks_lttng_ust_cuda_cuOccupancyMaxPotentialClusterSize_entry(
    void *btx_handle, lttng_ust_cuda_cuOccupancyMaxPotentialClusterSize_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuOccupancyMaxPotentialClusterSize_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, int);

void btx_register_callbacks_lttng_ust_cuda_cuOccupancyMaxPotentialClusterSize_exit(
    void *btx_handle, lttng_ust_cuda_cuOccupancyMaxPotentialClusterSize_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuOccupancyMaxActiveClusters_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, CUfunction, CUlaunchConfig *, size_t, CUlaunchConfig *);

void btx_register_callbacks_lttng_ust_cuda_cuOccupancyMaxActiveClusters_entry(
    void *btx_handle, lttng_ust_cuda_cuOccupancyMaxActiveClusters_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuOccupancyMaxActiveClusters_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, int);

void btx_register_callbacks_lttng_ust_cuda_cuOccupancyMaxActiveClusters_exit(
    void *btx_handle, lttng_ust_cuda_cuOccupancyMaxActiveClusters_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefSetArray_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUtexref, CUarray, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefSetArray_entry(
    void *btx_handle, lttng_ust_cuda_cuTexRefSetArray_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefSetArray_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefSetArray_exit(
    void *btx_handle, lttng_ust_cuda_cuTexRefSetArray_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefSetMipmappedArray_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUtexref, CUmipmappedArray, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefSetMipmappedArray_entry(
    void *btx_handle, lttng_ust_cuda_cuTexRefSetMipmappedArray_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefSetMipmappedArray_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefSetMipmappedArray_exit(
    void *btx_handle, lttng_ust_cuda_cuTexRefSetMipmappedArray_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefSetAddress_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, size_t *, CUtexref, CUdeviceptr, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefSetAddress_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuTexRefSetAddress_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefSetAddress_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefSetAddress_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuTexRefSetAddress_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefSetAddress2D_v3_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUtexref, CUDA_ARRAY_DESCRIPTOR *, CUdeviceptr, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefSetAddress2D_v3_entry(
    void *btx_handle, lttng_ust_cuda_cuTexRefSetAddress2D_v3_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefSetAddress2D_v3_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefSetAddress2D_v3_exit(
    void *btx_handle, lttng_ust_cuda_cuTexRefSetAddress2D_v3_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefSetFormat_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUtexref, CUarray_format, int);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefSetFormat_entry(
    void *btx_handle, lttng_ust_cuda_cuTexRefSetFormat_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefSetFormat_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefSetFormat_exit(
    void *btx_handle, lttng_ust_cuda_cuTexRefSetFormat_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefSetAddressMode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUtexref, int, CUaddress_mode);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefSetAddressMode_entry(
    void *btx_handle, lttng_ust_cuda_cuTexRefSetAddressMode_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefSetAddressMode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefSetAddressMode_exit(
    void *btx_handle, lttng_ust_cuda_cuTexRefSetAddressMode_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefSetFilterMode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUtexref, CUfilter_mode);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefSetFilterMode_entry(
    void *btx_handle, lttng_ust_cuda_cuTexRefSetFilterMode_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefSetFilterMode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefSetFilterMode_exit(
    void *btx_handle, lttng_ust_cuda_cuTexRefSetFilterMode_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefSetMipmapFilterMode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUtexref, CUfilter_mode);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefSetMipmapFilterMode_entry(
    void *btx_handle, lttng_ust_cuda_cuTexRefSetMipmapFilterMode_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefSetMipmapFilterMode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefSetMipmapFilterMode_exit(
    void *btx_handle, lttng_ust_cuda_cuTexRefSetMipmapFilterMode_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefSetMipmapLevelBias_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUtexref, float);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefSetMipmapLevelBias_entry(
    void *btx_handle, lttng_ust_cuda_cuTexRefSetMipmapLevelBias_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefSetMipmapLevelBias_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefSetMipmapLevelBias_exit(
    void *btx_handle, lttng_ust_cuda_cuTexRefSetMipmapLevelBias_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefSetMipmapLevelClamp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUtexref, float, float);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefSetMipmapLevelClamp_entry(
    void *btx_handle, lttng_ust_cuda_cuTexRefSetMipmapLevelClamp_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefSetMipmapLevelClamp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefSetMipmapLevelClamp_exit(
    void *btx_handle, lttng_ust_cuda_cuTexRefSetMipmapLevelClamp_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefSetMaxAnisotropy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUtexref, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefSetMaxAnisotropy_entry(
    void *btx_handle, lttng_ust_cuda_cuTexRefSetMaxAnisotropy_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefSetMaxAnisotropy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefSetMaxAnisotropy_exit(
    void *btx_handle, lttng_ust_cuda_cuTexRefSetMaxAnisotropy_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefSetBorderColor_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUtexref, float *, float *);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefSetBorderColor_entry(
    void *btx_handle, lttng_ust_cuda_cuTexRefSetBorderColor_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefSetBorderColor_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefSetBorderColor_exit(
    void *btx_handle, lttng_ust_cuda_cuTexRefSetBorderColor_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefSetFlags_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUtexref, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefSetFlags_entry(
    void *btx_handle, lttng_ust_cuda_cuTexRefSetFlags_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefSetFlags_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefSetFlags_exit(
    void *btx_handle, lttng_ust_cuda_cuTexRefSetFlags_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefGetAddress_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr *, CUtexref);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefGetAddress_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuTexRefGetAddress_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefGetAddress_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUdeviceptr);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefGetAddress_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuTexRefGetAddress_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefGetArray_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUarray *, CUtexref);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefGetArray_entry(
    void *btx_handle, lttng_ust_cuda_cuTexRefGetArray_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefGetArray_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUarray);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefGetArray_exit(
    void *btx_handle, lttng_ust_cuda_cuTexRefGetArray_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefGetMipmappedArray_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmipmappedArray *, CUtexref);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefGetMipmappedArray_entry(
    void *btx_handle, lttng_ust_cuda_cuTexRefGetMipmappedArray_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefGetMipmappedArray_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUmipmappedArray);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefGetMipmappedArray_exit(
    void *btx_handle, lttng_ust_cuda_cuTexRefGetMipmappedArray_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefGetAddressMode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUaddress_mode *, CUtexref, int);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefGetAddressMode_entry(
    void *btx_handle, lttng_ust_cuda_cuTexRefGetAddressMode_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefGetAddressMode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUaddress_mode);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefGetAddressMode_exit(
    void *btx_handle, lttng_ust_cuda_cuTexRefGetAddressMode_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefGetFilterMode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUfilter_mode *, CUtexref);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefGetFilterMode_entry(
    void *btx_handle, lttng_ust_cuda_cuTexRefGetFilterMode_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefGetFilterMode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUfilter_mode);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefGetFilterMode_exit(
    void *btx_handle, lttng_ust_cuda_cuTexRefGetFilterMode_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefGetFormat_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUarray_format *, int *, CUtexref);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefGetFormat_entry(
    void *btx_handle, lttng_ust_cuda_cuTexRefGetFormat_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefGetFormat_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUarray_format, int);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefGetFormat_exit(
    void *btx_handle, lttng_ust_cuda_cuTexRefGetFormat_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefGetMipmapFilterMode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUfilter_mode *, CUtexref);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefGetMipmapFilterMode_entry(
    void *btx_handle, lttng_ust_cuda_cuTexRefGetMipmapFilterMode_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefGetMipmapFilterMode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUfilter_mode);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefGetMipmapFilterMode_exit(
    void *btx_handle, lttng_ust_cuda_cuTexRefGetMipmapFilterMode_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefGetMipmapLevelBias_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, float *, CUtexref);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefGetMipmapLevelBias_entry(
    void *btx_handle, lttng_ust_cuda_cuTexRefGetMipmapLevelBias_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefGetMipmapLevelBias_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, float);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefGetMipmapLevelBias_exit(
    void *btx_handle, lttng_ust_cuda_cuTexRefGetMipmapLevelBias_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefGetMipmapLevelClamp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, float *, float *, CUtexref);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefGetMipmapLevelClamp_entry(
    void *btx_handle, lttng_ust_cuda_cuTexRefGetMipmapLevelClamp_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefGetMipmapLevelClamp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, float, float);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefGetMipmapLevelClamp_exit(
    void *btx_handle, lttng_ust_cuda_cuTexRefGetMipmapLevelClamp_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefGetMaxAnisotropy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, CUtexref);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefGetMaxAnisotropy_entry(
    void *btx_handle, lttng_ust_cuda_cuTexRefGetMaxAnisotropy_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefGetMaxAnisotropy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, int);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefGetMaxAnisotropy_exit(
    void *btx_handle, lttng_ust_cuda_cuTexRefGetMaxAnisotropy_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefGetBorderColor_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, float *, CUtexref);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefGetBorderColor_entry(
    void *btx_handle, lttng_ust_cuda_cuTexRefGetBorderColor_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefGetBorderColor_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, float);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefGetBorderColor_exit(
    void *btx_handle, lttng_ust_cuda_cuTexRefGetBorderColor_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefGetFlags_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, unsigned int *, CUtexref);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefGetFlags_entry(
    void *btx_handle, lttng_ust_cuda_cuTexRefGetFlags_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefGetFlags_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefGetFlags_exit(
    void *btx_handle, lttng_ust_cuda_cuTexRefGetFlags_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUtexref *);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefCreate_entry(
    void *btx_handle, lttng_ust_cuda_cuTexRefCreate_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUtexref);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefCreate_exit(
    void *btx_handle, lttng_ust_cuda_cuTexRefCreate_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUtexref);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefDestroy_entry(
    void *btx_handle, lttng_ust_cuda_cuTexRefDestroy_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefDestroy_exit(
    void *btx_handle, lttng_ust_cuda_cuTexRefDestroy_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuSurfRefSetArray_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUsurfref, CUarray, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuSurfRefSetArray_entry(
    void *btx_handle, lttng_ust_cuda_cuSurfRefSetArray_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuSurfRefSetArray_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuSurfRefSetArray_exit(
    void *btx_handle, lttng_ust_cuda_cuSurfRefSetArray_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuSurfRefGetArray_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUarray *, CUsurfref);

void btx_register_callbacks_lttng_ust_cuda_cuSurfRefGetArray_entry(
    void *btx_handle, lttng_ust_cuda_cuSurfRefGetArray_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuSurfRefGetArray_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUarray);

void btx_register_callbacks_lttng_ust_cuda_cuSurfRefGetArray_exit(
    void *btx_handle, lttng_ust_cuda_cuSurfRefGetArray_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTexObjectCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUtexObject *, CUDA_RESOURCE_DESC *, CUDA_TEXTURE_DESC *, CUDA_RESOURCE_VIEW_DESC *, size_t, CUDA_RESOURCE_DESC *, size_t, CUDA_TEXTURE_DESC *, size_t, CUDA_RESOURCE_VIEW_DESC *);

void btx_register_callbacks_lttng_ust_cuda_cuTexObjectCreate_entry(
    void *btx_handle, lttng_ust_cuda_cuTexObjectCreate_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTexObjectCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUtexObject);

void btx_register_callbacks_lttng_ust_cuda_cuTexObjectCreate_exit(
    void *btx_handle, lttng_ust_cuda_cuTexObjectCreate_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTexObjectDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUtexObject);

void btx_register_callbacks_lttng_ust_cuda_cuTexObjectDestroy_entry(
    void *btx_handle, lttng_ust_cuda_cuTexObjectDestroy_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTexObjectDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuTexObjectDestroy_exit(
    void *btx_handle, lttng_ust_cuda_cuTexObjectDestroy_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTexObjectGetResourceDesc_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUDA_RESOURCE_DESC *, CUtexObject);

void btx_register_callbacks_lttng_ust_cuda_cuTexObjectGetResourceDesc_entry(
    void *btx_handle, lttng_ust_cuda_cuTexObjectGetResourceDesc_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTexObjectGetResourceDesc_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUDA_RESOURCE_DESC *);

void btx_register_callbacks_lttng_ust_cuda_cuTexObjectGetResourceDesc_exit(
    void *btx_handle, lttng_ust_cuda_cuTexObjectGetResourceDesc_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTexObjectGetTextureDesc_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUDA_TEXTURE_DESC *, CUtexObject);

void btx_register_callbacks_lttng_ust_cuda_cuTexObjectGetTextureDesc_entry(
    void *btx_handle, lttng_ust_cuda_cuTexObjectGetTextureDesc_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTexObjectGetTextureDesc_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUDA_TEXTURE_DESC *);

void btx_register_callbacks_lttng_ust_cuda_cuTexObjectGetTextureDesc_exit(
    void *btx_handle, lttng_ust_cuda_cuTexObjectGetTextureDesc_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTexObjectGetResourceViewDesc_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUDA_RESOURCE_VIEW_DESC *, CUtexObject);

void btx_register_callbacks_lttng_ust_cuda_cuTexObjectGetResourceViewDesc_entry(
    void *btx_handle, lttng_ust_cuda_cuTexObjectGetResourceViewDesc_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTexObjectGetResourceViewDesc_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUDA_RESOURCE_VIEW_DESC *);

void btx_register_callbacks_lttng_ust_cuda_cuTexObjectGetResourceViewDesc_exit(
    void *btx_handle, lttng_ust_cuda_cuTexObjectGetResourceViewDesc_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuSurfObjectCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUsurfObject *, CUDA_RESOURCE_DESC *, size_t, CUDA_RESOURCE_DESC *);

void btx_register_callbacks_lttng_ust_cuda_cuSurfObjectCreate_entry(
    void *btx_handle, lttng_ust_cuda_cuSurfObjectCreate_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuSurfObjectCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUsurfObject);

void btx_register_callbacks_lttng_ust_cuda_cuSurfObjectCreate_exit(
    void *btx_handle, lttng_ust_cuda_cuSurfObjectCreate_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuSurfObjectDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUsurfObject);

void btx_register_callbacks_lttng_ust_cuda_cuSurfObjectDestroy_entry(
    void *btx_handle, lttng_ust_cuda_cuSurfObjectDestroy_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuSurfObjectDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuSurfObjectDestroy_exit(
    void *btx_handle, lttng_ust_cuda_cuSurfObjectDestroy_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuSurfObjectGetResourceDesc_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUDA_RESOURCE_DESC *, CUsurfObject);

void btx_register_callbacks_lttng_ust_cuda_cuSurfObjectGetResourceDesc_entry(
    void *btx_handle, lttng_ust_cuda_cuSurfObjectGetResourceDesc_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuSurfObjectGetResourceDesc_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUDA_RESOURCE_DESC *);

void btx_register_callbacks_lttng_ust_cuda_cuSurfObjectGetResourceDesc_exit(
    void *btx_handle, lttng_ust_cuda_cuSurfObjectGetResourceDesc_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTensorMapEncodeTiled_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUtensorMap *, CUtensorMapDataType, cuuint32_t, void *, cuuint64_t *, cuuint64_t *, cuuint32_t *, cuuint32_t *, CUtensorMapInterleave, CUtensorMapSwizzle, CUtensorMapL2promotion, CUtensorMapFloatOOBfill, size_t, cuuint64_t *, size_t, cuuint64_t *, size_t, cuuint32_t *, size_t, cuuint32_t *);

void btx_register_callbacks_lttng_ust_cuda_cuTensorMapEncodeTiled_entry(
    void *btx_handle, lttng_ust_cuda_cuTensorMapEncodeTiled_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTensorMapEncodeTiled_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUtensorMap *);

void btx_register_callbacks_lttng_ust_cuda_cuTensorMapEncodeTiled_exit(
    void *btx_handle, lttng_ust_cuda_cuTensorMapEncodeTiled_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTensorMapEncodeIm2col_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUtensorMap *, CUtensorMapDataType, cuuint32_t, void *, cuuint64_t *, cuuint64_t *, int *, int *, cuuint32_t, cuuint32_t, cuuint32_t *, CUtensorMapInterleave, CUtensorMapSwizzle, CUtensorMapL2promotion, CUtensorMapFloatOOBfill, size_t, cuuint64_t *, size_t, cuuint64_t *, int *, int *);

void btx_register_callbacks_lttng_ust_cuda_cuTensorMapEncodeIm2col_entry(
    void *btx_handle, lttng_ust_cuda_cuTensorMapEncodeIm2col_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTensorMapEncodeIm2col_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUtensorMap *);

void btx_register_callbacks_lttng_ust_cuda_cuTensorMapEncodeIm2col_exit(
    void *btx_handle, lttng_ust_cuda_cuTensorMapEncodeIm2col_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTensorMapEncodeIm2colWide_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUtensorMap *, CUtensorMapDataType, cuuint32_t, void *, cuuint64_t *, cuuint64_t *, int, int, cuuint32_t, cuuint32_t, cuuint32_t *, CUtensorMapInterleave, CUtensorMapIm2ColWideMode, CUtensorMapSwizzle, CUtensorMapL2promotion, CUtensorMapFloatOOBfill, size_t, cuuint64_t *, size_t, cuuint64_t *, size_t, cuuint32_t *);

void btx_register_callbacks_lttng_ust_cuda_cuTensorMapEncodeIm2colWide_entry(
    void *btx_handle, lttng_ust_cuda_cuTensorMapEncodeIm2colWide_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTensorMapEncodeIm2colWide_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUtensorMap *);

void btx_register_callbacks_lttng_ust_cuda_cuTensorMapEncodeIm2colWide_exit(
    void *btx_handle, lttng_ust_cuda_cuTensorMapEncodeIm2colWide_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTensorMapReplaceAddress_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUtensorMap *, void *, size_t, CUtensorMap *);

void btx_register_callbacks_lttng_ust_cuda_cuTensorMapReplaceAddress_entry(
    void *btx_handle, lttng_ust_cuda_cuTensorMapReplaceAddress_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTensorMapReplaceAddress_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuTensorMapReplaceAddress_exit(
    void *btx_handle, lttng_ust_cuda_cuTensorMapReplaceAddress_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceCanAccessPeer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, CUdevice, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceCanAccessPeer_entry(
    void *btx_handle, lttng_ust_cuda_cuDeviceCanAccessPeer_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceCanAccessPeer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, int);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceCanAccessPeer_exit(
    void *btx_handle, lttng_ust_cuda_cuDeviceCanAccessPeer_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxEnablePeerAccess_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuCtxEnablePeerAccess_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxEnablePeerAccess_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxEnablePeerAccess_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuCtxEnablePeerAccess_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxEnablePeerAccess_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxDisablePeerAccess_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext);

void btx_register_callbacks_lttng_ust_cuda_cuCtxDisablePeerAccess_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxDisablePeerAccess_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxDisablePeerAccess_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuCtxDisablePeerAccess_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxDisablePeerAccess_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetP2PAttribute_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, CUdevice_P2PAttribute, CUdevice, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetP2PAttribute_entry(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetP2PAttribute_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetP2PAttribute_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, int);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetP2PAttribute_exit(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetP2PAttribute_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetP2PAtomicCapabilities_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, unsigned int *, CUatomicOperation *, unsigned int, CUdevice, CUdevice, size_t, CUatomicOperation *);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetP2PAtomicCapabilities_entry(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetP2PAtomicCapabilities_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetP2PAtomicCapabilities_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, unsigned int *);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetP2PAtomicCapabilities_exit(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetP2PAtomicCapabilities_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphicsUnregisterResource_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphicsResource);

void btx_register_callbacks_lttng_ust_cuda_cuGraphicsUnregisterResource_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphicsUnregisterResource_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphicsUnregisterResource_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphicsUnregisterResource_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphicsUnregisterResource_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphicsSubResourceGetMappedArray_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUarray *, CUgraphicsResource, unsigned int, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuGraphicsSubResourceGetMappedArray_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphicsSubResourceGetMappedArray_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphicsSubResourceGetMappedArray_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUarray);

void btx_register_callbacks_lttng_ust_cuda_cuGraphicsSubResourceGetMappedArray_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphicsSubResourceGetMappedArray_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphicsResourceGetMappedMipmappedArray_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmipmappedArray *, CUgraphicsResource);

void btx_register_callbacks_lttng_ust_cuda_cuGraphicsResourceGetMappedMipmappedArray_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphicsResourceGetMappedMipmappedArray_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphicsResourceGetMappedMipmappedArray_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUmipmappedArray);

void btx_register_callbacks_lttng_ust_cuda_cuGraphicsResourceGetMappedMipmappedArray_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphicsResourceGetMappedMipmappedArray_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphicsResourceGetMappedPointer_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr *, size_t *, CUgraphicsResource);

void btx_register_callbacks_lttng_ust_cuda_cuGraphicsResourceGetMappedPointer_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphicsResourceGetMappedPointer_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphicsResourceGetMappedPointer_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUdeviceptr, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuGraphicsResourceGetMappedPointer_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphicsResourceGetMappedPointer_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphicsResourceSetMapFlags_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphicsResource, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuGraphicsResourceSetMapFlags_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphicsResourceSetMapFlags_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphicsResourceSetMapFlags_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphicsResourceSetMapFlags_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphicsResourceSetMapFlags_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphicsMapResources_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, unsigned int, CUgraphicsResource *, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuGraphicsMapResources_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphicsMapResources_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphicsMapResources_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphicsMapResources_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphicsMapResources_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphicsUnmapResources_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, unsigned int, CUgraphicsResource *, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuGraphicsUnmapResources_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphicsUnmapResources_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphicsUnmapResources_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphicsUnmapResources_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphicsUnmapResources_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGetProcAddress_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, void **, int, cuuint64_t, CUdriverProcAddressQueryResult *, char *);

void btx_register_callbacks_lttng_ust_cuda_cuGetProcAddress_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuGetProcAddress_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGetProcAddress_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, void *, CUdriverProcAddressQueryResult);

void btx_register_callbacks_lttng_ust_cuda_cuGetProcAddress_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuGetProcAddress_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCoredumpGetAttribute_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcoredumpSettings, void *, size_t *, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuCoredumpGetAttribute_entry(
    void *btx_handle, lttng_ust_cuda_cuCoredumpGetAttribute_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCoredumpGetAttribute_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, size_t, void *);

void btx_register_callbacks_lttng_ust_cuda_cuCoredumpGetAttribute_exit(
    void *btx_handle, lttng_ust_cuda_cuCoredumpGetAttribute_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCoredumpGetAttributeGlobal_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcoredumpSettings, void *, size_t *, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuCoredumpGetAttributeGlobal_entry(
    void *btx_handle, lttng_ust_cuda_cuCoredumpGetAttributeGlobal_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCoredumpGetAttributeGlobal_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, size_t, void *);

void btx_register_callbacks_lttng_ust_cuda_cuCoredumpGetAttributeGlobal_exit(
    void *btx_handle, lttng_ust_cuda_cuCoredumpGetAttributeGlobal_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCoredumpSetAttribute_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcoredumpSettings, void *, size_t *, size_t, size_t, void *);

void btx_register_callbacks_lttng_ust_cuda_cuCoredumpSetAttribute_entry(
    void *btx_handle, lttng_ust_cuda_cuCoredumpSetAttribute_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCoredumpSetAttribute_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuCoredumpSetAttribute_exit(
    void *btx_handle, lttng_ust_cuda_cuCoredumpSetAttribute_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCoredumpSetAttributeGlobal_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcoredumpSettings, void *, size_t *, size_t, size_t, void *);

void btx_register_callbacks_lttng_ust_cuda_cuCoredumpSetAttributeGlobal_entry(
    void *btx_handle, lttng_ust_cuda_cuCoredumpSetAttributeGlobal_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCoredumpSetAttributeGlobal_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuCoredumpSetAttributeGlobal_exit(
    void *btx_handle, lttng_ust_cuda_cuCoredumpSetAttributeGlobal_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGetExportTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void **, CUuuid *, size_t, CUuuid *);

void btx_register_callbacks_lttng_ust_cuda_cuGetExportTable_entry(
    void *btx_handle, lttng_ust_cuda_cuGetExportTable_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGetExportTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, void *);

void btx_register_callbacks_lttng_ust_cuda_cuGetExportTable_exit(
    void *btx_handle, lttng_ust_cuda_cuGetExportTable_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGreenCtxCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgreenCtx *, CUdevResourceDesc, CUdevice, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuGreenCtxCreate_entry(
    void *btx_handle, lttng_ust_cuda_cuGreenCtxCreate_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGreenCtxCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUgreenCtx);

void btx_register_callbacks_lttng_ust_cuda_cuGreenCtxCreate_exit(
    void *btx_handle, lttng_ust_cuda_cuGreenCtxCreate_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGreenCtxDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgreenCtx);

void btx_register_callbacks_lttng_ust_cuda_cuGreenCtxDestroy_entry(
    void *btx_handle, lttng_ust_cuda_cuGreenCtxDestroy_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGreenCtxDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGreenCtxDestroy_exit(
    void *btx_handle, lttng_ust_cuda_cuGreenCtxDestroy_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxFromGreenCtx_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext *, CUgreenCtx);

void btx_register_callbacks_lttng_ust_cuda_cuCtxFromGreenCtx_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxFromGreenCtx_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxFromGreenCtx_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUcontext);

void btx_register_callbacks_lttng_ust_cuda_cuCtxFromGreenCtx_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxFromGreenCtx_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetDevResource_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdevice, CUdevResource *, CUdevResourceType);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetDevResource_entry(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetDevResource_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetDevResource_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUdevResource *);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetDevResource_exit(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetDevResource_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxGetDevResource_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext, CUdevResource *, CUdevResourceType);

void btx_register_callbacks_lttng_ust_cuda_cuCtxGetDevResource_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxGetDevResource_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxGetDevResource_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUdevResource *);

void btx_register_callbacks_lttng_ust_cuda_cuCtxGetDevResource_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxGetDevResource_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGreenCtxGetDevResource_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgreenCtx, CUdevResource *, CUdevResourceType);

void btx_register_callbacks_lttng_ust_cuda_cuGreenCtxGetDevResource_entry(
    void *btx_handle, lttng_ust_cuda_cuGreenCtxGetDevResource_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGreenCtxGetDevResource_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUdevResource *);

void btx_register_callbacks_lttng_ust_cuda_cuGreenCtxGetDevResource_exit(
    void *btx_handle, lttng_ust_cuda_cuGreenCtxGetDevResource_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDevSmResourceSplitByCount_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdevResource *, unsigned int *, CUdevResource *, CUdevResource *, unsigned int, unsigned int, unsigned int, size_t, CUdevResource *);

void btx_register_callbacks_lttng_ust_cuda_cuDevSmResourceSplitByCount_entry(
    void *btx_handle, lttng_ust_cuda_cuDevSmResourceSplitByCount_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDevSmResourceSplitByCount_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, unsigned int, size_t, CUdevResource *, size_t, CUdevResource *);

void btx_register_callbacks_lttng_ust_cuda_cuDevSmResourceSplitByCount_exit(
    void *btx_handle, lttng_ust_cuda_cuDevSmResourceSplitByCount_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDevResourceGenerateDesc_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdevResourceDesc *, CUdevResource *, unsigned int, size_t, CUdevResource *);

void btx_register_callbacks_lttng_ust_cuda_cuDevResourceGenerateDesc_entry(
    void *btx_handle, lttng_ust_cuda_cuDevResourceGenerateDesc_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDevResourceGenerateDesc_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUdevResourceDesc);

void btx_register_callbacks_lttng_ust_cuda_cuDevResourceGenerateDesc_exit(
    void *btx_handle, lttng_ust_cuda_cuDevResourceGenerateDesc_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGreenCtxRecordEvent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgreenCtx, CUevent);

void btx_register_callbacks_lttng_ust_cuda_cuGreenCtxRecordEvent_entry(
    void *btx_handle, lttng_ust_cuda_cuGreenCtxRecordEvent_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGreenCtxRecordEvent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGreenCtxRecordEvent_exit(
    void *btx_handle, lttng_ust_cuda_cuGreenCtxRecordEvent_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGreenCtxWaitEvent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgreenCtx, CUevent);

void btx_register_callbacks_lttng_ust_cuda_cuGreenCtxWaitEvent_entry(
    void *btx_handle, lttng_ust_cuda_cuGreenCtxWaitEvent_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGreenCtxWaitEvent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGreenCtxWaitEvent_exit(
    void *btx_handle, lttng_ust_cuda_cuGreenCtxWaitEvent_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetGreenCtx_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUgreenCtx *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetGreenCtx_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamGetGreenCtx_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetGreenCtx_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUgreenCtx);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetGreenCtx_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamGetGreenCtx_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGreenCtxStreamCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream *, CUgreenCtx, unsigned int, int);

void btx_register_callbacks_lttng_ust_cuda_cuGreenCtxStreamCreate_entry(
    void *btx_handle, lttng_ust_cuda_cuGreenCtxStreamCreate_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGreenCtxStreamCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuGreenCtxStreamCreate_exit(
    void *btx_handle, lttng_ust_cuda_cuGreenCtxStreamCreate_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGreenCtxGetId_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgreenCtx, unsigned long long int *);

void btx_register_callbacks_lttng_ust_cuda_cuGreenCtxGetId_entry(
    void *btx_handle, lttng_ust_cuda_cuGreenCtxGetId_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGreenCtxGetId_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, unsigned long long int);

void btx_register_callbacks_lttng_ust_cuda_cuGreenCtxGetId_exit(
    void *btx_handle, lttng_ust_cuda_cuGreenCtxGetId_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuLogsRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUlogsCallback, void *, CUlogsCallbackHandle *);

void btx_register_callbacks_lttng_ust_cuda_cuLogsRegisterCallback_entry(
    void *btx_handle, lttng_ust_cuda_cuLogsRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuLogsRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUlogsCallbackHandle);

void btx_register_callbacks_lttng_ust_cuda_cuLogsRegisterCallback_exit(
    void *btx_handle, lttng_ust_cuda_cuLogsRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuLogsUnregisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUlogsCallbackHandle);

void btx_register_callbacks_lttng_ust_cuda_cuLogsUnregisterCallback_entry(
    void *btx_handle, lttng_ust_cuda_cuLogsUnregisterCallback_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuLogsUnregisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuLogsUnregisterCallback_exit(
    void *btx_handle, lttng_ust_cuda_cuLogsUnregisterCallback_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuLogsCurrent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUlogIterator *, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuLogsCurrent_entry(
    void *btx_handle, lttng_ust_cuda_cuLogsCurrent_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuLogsCurrent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUlogIterator);

void btx_register_callbacks_lttng_ust_cuda_cuLogsCurrent_exit(
    void *btx_handle, lttng_ust_cuda_cuLogsCurrent_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuLogsDumpToFile_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUlogIterator *, char *, unsigned int, CUlogIterator, char *);

void btx_register_callbacks_lttng_ust_cuda_cuLogsDumpToFile_entry(
    void *btx_handle, lttng_ust_cuda_cuLogsDumpToFile_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuLogsDumpToFile_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuLogsDumpToFile_exit(
    void *btx_handle, lttng_ust_cuda_cuLogsDumpToFile_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuLogsDumpToMemory_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUlogIterator *, char *, size_t *, unsigned int, CUlogIterator, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuLogsDumpToMemory_entry(
    void *btx_handle, lttng_ust_cuda_cuLogsDumpToMemory_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuLogsDumpToMemory_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, size_t, char *);

void btx_register_callbacks_lttng_ust_cuda_cuLogsDumpToMemory_exit(
    void *btx_handle, lttng_ust_cuda_cuLogsDumpToMemory_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemHostRegister_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, size_t, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuMemHostRegister_entry(
    void *btx_handle, lttng_ust_cuda_cuMemHostRegister_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemHostRegister_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemHostRegister_exit(
    void *btx_handle, lttng_ust_cuda_cuMemHostRegister_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphicsResourceSetMapFlags_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphicsResource, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuGraphicsResourceSetMapFlags_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphicsResourceSetMapFlags_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphicsResourceSetMapFlags_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphicsResourceSetMapFlags_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphicsResourceSetMapFlags_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuLinkCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, unsigned int, CUjit_option *, void **, CUlinkState *, size_t, CUjit_option *, size_t, void * *);

void btx_register_callbacks_lttng_ust_cuda_cuLinkCreate_entry(
    void *btx_handle, lttng_ust_cuda_cuLinkCreate_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuLinkCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUlinkState);

void btx_register_callbacks_lttng_ust_cuda_cuLinkCreate_exit(
    void *btx_handle, lttng_ust_cuda_cuLinkCreate_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuLinkAddData_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUlinkState, CUjitInputType, void *, size_t, char *, unsigned int, CUjit_option *, void **, char *, size_t, CUjit_option *, size_t, void * *);

void btx_register_callbacks_lttng_ust_cuda_cuLinkAddData_entry(
    void *btx_handle, lttng_ust_cuda_cuLinkAddData_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuLinkAddData_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuLinkAddData_exit(
    void *btx_handle, lttng_ust_cuda_cuLinkAddData_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuLinkAddFile_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUlinkState, CUjitInputType, char *, unsigned int, CUjit_option *, void **, char *, size_t, CUjit_option *, size_t, void * *);

void btx_register_callbacks_lttng_ust_cuda_cuLinkAddFile_entry(
    void *btx_handle, lttng_ust_cuda_cuLinkAddFile_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuLinkAddFile_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuLinkAddFile_exit(
    void *btx_handle, lttng_ust_cuda_cuLinkAddFile_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefSetAddress2D_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUtexref, CUDA_ARRAY_DESCRIPTOR *, CUdeviceptr, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefSetAddress2D_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuTexRefSetAddress2D_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefSetAddress2D_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefSetAddress2D_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuTexRefSetAddress2D_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceTotalMem_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, unsigned int *, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceTotalMem_entry(
    void *btx_handle, lttng_ust_cuda_cuDeviceTotalMem_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceTotalMem_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceTotalMem_exit(
    void *btx_handle, lttng_ust_cuda_cuDeviceTotalMem_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext *, unsigned int, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuCtxCreate_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxCreate_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUcontext);

void btx_register_callbacks_lttng_ust_cuda_cuCtxCreate_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxCreate_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxCreate_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext *, unsigned int, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuCtxCreate_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxCreate_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxCreate_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUcontext);

void btx_register_callbacks_lttng_ust_cuda_cuCtxCreate_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxCreate_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxCreate_v3_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext *, CUexecAffinityParam *, int, unsigned int, CUdevice, size_t, CUexecAffinityParam *);

void btx_register_callbacks_lttng_ust_cuda_cuCtxCreate_v3_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxCreate_v3_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxCreate_v3_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUcontext);

void btx_register_callbacks_lttng_ust_cuda_cuCtxCreate_v3_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxCreate_v3_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuModuleGetGlobal_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr_v1 *, unsigned int *, CUmodule, char *, char *);

void btx_register_callbacks_lttng_ust_cuda_cuModuleGetGlobal_entry(
    void *btx_handle, lttng_ust_cuda_cuModuleGetGlobal_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuModuleGetGlobal_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUdeviceptr_v1, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuModuleGetGlobal_exit(
    void *btx_handle, lttng_ust_cuda_cuModuleGetGlobal_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemGetInfo_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, unsigned int *, unsigned int *);

void btx_register_callbacks_lttng_ust_cuda_cuMemGetInfo_entry(
    void *btx_handle, lttng_ust_cuda_cuMemGetInfo_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemGetInfo_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, unsigned int, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuMemGetInfo_exit(
    void *btx_handle, lttng_ust_cuda_cuMemGetInfo_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemAlloc_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr_v1 *, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuMemAlloc_entry(
    void *btx_handle, lttng_ust_cuda_cuMemAlloc_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemAlloc_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUdeviceptr_v1);

void btx_register_callbacks_lttng_ust_cuda_cuMemAlloc_exit(
    void *btx_handle, lttng_ust_cuda_cuMemAlloc_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemAllocPitch_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr_v1 *, unsigned int *, unsigned int, unsigned int, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuMemAllocPitch_entry(
    void *btx_handle, lttng_ust_cuda_cuMemAllocPitch_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemAllocPitch_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUdeviceptr_v1, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuMemAllocPitch_exit(
    void *btx_handle, lttng_ust_cuda_cuMemAllocPitch_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemFree_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr_v1);

void btx_register_callbacks_lttng_ust_cuda_cuMemFree_entry(
    void *btx_handle, lttng_ust_cuda_cuMemFree_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemFree_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemFree_exit(
    void *btx_handle, lttng_ust_cuda_cuMemFree_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemGetAddressRange_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr_v1 *, unsigned int *, CUdeviceptr_v1);

void btx_register_callbacks_lttng_ust_cuda_cuMemGetAddressRange_entry(
    void *btx_handle, lttng_ust_cuda_cuMemGetAddressRange_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemGetAddressRange_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUdeviceptr_v1, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuMemGetAddressRange_exit(
    void *btx_handle, lttng_ust_cuda_cuMemGetAddressRange_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemAllocHost_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void **, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuMemAllocHost_entry(
    void *btx_handle, lttng_ust_cuda_cuMemAllocHost_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemAllocHost_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, void *);

void btx_register_callbacks_lttng_ust_cuda_cuMemAllocHost_exit(
    void *btx_handle, lttng_ust_cuda_cuMemAllocHost_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemHostGetDevicePointer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr_v1 *, void *, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuMemHostGetDevicePointer_entry(
    void *btx_handle, lttng_ust_cuda_cuMemHostGetDevicePointer_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemHostGetDevicePointer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUdeviceptr_v1);

void btx_register_callbacks_lttng_ust_cuda_cuMemHostGetDevicePointer_exit(
    void *btx_handle, lttng_ust_cuda_cuMemHostGetDevicePointer_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyHtoD_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr_v1, void *, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyHtoD_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyHtoD_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyHtoD_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyHtoD_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyHtoD_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyDtoH_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, CUdeviceptr_v1, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyDtoH_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyDtoH_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyDtoH_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyDtoH_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyDtoH_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyDtoD_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr_v1, CUdeviceptr_v1, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyDtoD_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyDtoD_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyDtoD_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyDtoD_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyDtoD_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyDtoA_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUarray, unsigned int, CUdeviceptr_v1, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyDtoA_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyDtoA_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyDtoA_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyDtoA_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyDtoA_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyAtoD_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr_v1, CUarray, unsigned int, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyAtoD_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyAtoD_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyAtoD_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyAtoD_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyAtoD_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyHtoA_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUarray, unsigned int, void *, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyHtoA_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyHtoA_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyHtoA_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyHtoA_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyHtoA_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyAtoH_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, CUarray, unsigned int, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyAtoH_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyAtoH_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyAtoH_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyAtoH_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyAtoH_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyAtoA_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUarray, unsigned int, CUarray, unsigned int, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyAtoA_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyAtoA_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyAtoA_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyAtoA_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyAtoA_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyHtoAAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUarray, unsigned int, void *, unsigned int, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyHtoAAsync_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyHtoAAsync_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyHtoAAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyHtoAAsync_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyHtoAAsync_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyAtoHAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, CUarray, unsigned int, unsigned int, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyAtoHAsync_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyAtoHAsync_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyAtoHAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyAtoHAsync_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyAtoHAsync_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy2D_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUDA_MEMCPY2D_v1 *, size_t, CUDA_MEMCPY2D_v1 *);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy2D_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpy2D_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy2D_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy2D_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpy2D_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy2DUnaligned_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUDA_MEMCPY2D_v1 *, size_t, CUDA_MEMCPY2D_v1 *);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy2DUnaligned_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpy2DUnaligned_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy2DUnaligned_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy2DUnaligned_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpy2DUnaligned_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy3D_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUDA_MEMCPY3D_v1 *, size_t, CUDA_MEMCPY3D_v1 *);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy3D_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpy3D_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy3D_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy3D_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpy3D_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyHtoDAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr_v1, void *, unsigned int, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyHtoDAsync_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyHtoDAsync_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyHtoDAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyHtoDAsync_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyHtoDAsync_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyDtoHAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, CUdeviceptr_v1, unsigned int, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyDtoHAsync_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyDtoHAsync_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyDtoHAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyDtoHAsync_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyDtoHAsync_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyDtoDAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr_v1, CUdeviceptr_v1, unsigned int, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyDtoDAsync_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyDtoDAsync_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyDtoDAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyDtoDAsync_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyDtoDAsync_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy2DAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUDA_MEMCPY2D_v1 *, CUstream, size_t, CUDA_MEMCPY2D_v1 *);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy2DAsync_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpy2DAsync_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy2DAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy2DAsync_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpy2DAsync_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy3DAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUDA_MEMCPY3D_v1 *, CUstream, size_t, CUDA_MEMCPY3D_v1 *);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy3DAsync_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpy3DAsync_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy3DAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy3DAsync_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpy3DAsync_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD8_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr_v1, unsigned char, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD8_entry(
    void *btx_handle, lttng_ust_cuda_cuMemsetD8_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD8_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD8_exit(
    void *btx_handle, lttng_ust_cuda_cuMemsetD8_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD16_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr_v1, unsigned short int, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD16_entry(
    void *btx_handle, lttng_ust_cuda_cuMemsetD16_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD16_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD16_exit(
    void *btx_handle, lttng_ust_cuda_cuMemsetD16_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD32_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr_v1, unsigned int, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD32_entry(
    void *btx_handle, lttng_ust_cuda_cuMemsetD32_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD32_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD32_exit(
    void *btx_handle, lttng_ust_cuda_cuMemsetD32_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD2D8_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr_v1, unsigned int, unsigned char, unsigned int, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD2D8_entry(
    void *btx_handle, lttng_ust_cuda_cuMemsetD2D8_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD2D8_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD2D8_exit(
    void *btx_handle, lttng_ust_cuda_cuMemsetD2D8_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD2D16_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr_v1, unsigned int, unsigned short int, unsigned int, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD2D16_entry(
    void *btx_handle, lttng_ust_cuda_cuMemsetD2D16_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD2D16_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD2D16_exit(
    void *btx_handle, lttng_ust_cuda_cuMemsetD2D16_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD2D32_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr_v1, unsigned int, unsigned int, unsigned int, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD2D32_entry(
    void *btx_handle, lttng_ust_cuda_cuMemsetD2D32_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD2D32_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD2D32_exit(
    void *btx_handle, lttng_ust_cuda_cuMemsetD2D32_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuArrayCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUarray *, CUDA_ARRAY_DESCRIPTOR_v1 *, size_t, CUDA_ARRAY_DESCRIPTOR_v1 *);

void btx_register_callbacks_lttng_ust_cuda_cuArrayCreate_entry(
    void *btx_handle, lttng_ust_cuda_cuArrayCreate_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuArrayCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUarray);

void btx_register_callbacks_lttng_ust_cuda_cuArrayCreate_exit(
    void *btx_handle, lttng_ust_cuda_cuArrayCreate_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuArrayGetDescriptor_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUDA_ARRAY_DESCRIPTOR_v1 *, CUarray);

void btx_register_callbacks_lttng_ust_cuda_cuArrayGetDescriptor_entry(
    void *btx_handle, lttng_ust_cuda_cuArrayGetDescriptor_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuArrayGetDescriptor_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUDA_ARRAY_DESCRIPTOR_v1 *);

void btx_register_callbacks_lttng_ust_cuda_cuArrayGetDescriptor_exit(
    void *btx_handle, lttng_ust_cuda_cuArrayGetDescriptor_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuArray3DCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUarray *, CUDA_ARRAY3D_DESCRIPTOR_v1 *, size_t, CUDA_ARRAY3D_DESCRIPTOR_v1 *);

void btx_register_callbacks_lttng_ust_cuda_cuArray3DCreate_entry(
    void *btx_handle, lttng_ust_cuda_cuArray3DCreate_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuArray3DCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUarray);

void btx_register_callbacks_lttng_ust_cuda_cuArray3DCreate_exit(
    void *btx_handle, lttng_ust_cuda_cuArray3DCreate_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuArray3DGetDescriptor_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUDA_ARRAY3D_DESCRIPTOR_v1 *, CUarray);

void btx_register_callbacks_lttng_ust_cuda_cuArray3DGetDescriptor_entry(
    void *btx_handle, lttng_ust_cuda_cuArray3DGetDescriptor_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuArray3DGetDescriptor_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUDA_ARRAY3D_DESCRIPTOR_v1 *);

void btx_register_callbacks_lttng_ust_cuda_cuArray3DGetDescriptor_exit(
    void *btx_handle, lttng_ust_cuda_cuArray3DGetDescriptor_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefSetAddress_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, unsigned int *, CUtexref, CUdeviceptr_v1, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefSetAddress_entry(
    void *btx_handle, lttng_ust_cuda_cuTexRefSetAddress_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefSetAddress_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefSetAddress_exit(
    void *btx_handle, lttng_ust_cuda_cuTexRefSetAddress_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefSetAddress2D_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUtexref, CUDA_ARRAY_DESCRIPTOR_v1 *, CUdeviceptr_v1, unsigned int, size_t, CUDA_ARRAY_DESCRIPTOR_v1 *);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefSetAddress2D_entry(
    void *btx_handle, lttng_ust_cuda_cuTexRefSetAddress2D_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefSetAddress2D_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefSetAddress2D_exit(
    void *btx_handle, lttng_ust_cuda_cuTexRefSetAddress2D_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefGetAddress_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr_v1 *, CUtexref);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefGetAddress_entry(
    void *btx_handle, lttng_ust_cuda_cuTexRefGetAddress_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuTexRefGetAddress_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUdeviceptr_v1);

void btx_register_callbacks_lttng_ust_cuda_cuTexRefGetAddress_exit(
    void *btx_handle, lttng_ust_cuda_cuTexRefGetAddress_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphicsResourceGetMappedPointer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr_v1 *, unsigned int *, CUgraphicsResource);

void btx_register_callbacks_lttng_ust_cuda_cuGraphicsResourceGetMappedPointer_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphicsResourceGetMappedPointer_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphicsResourceGetMappedPointer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUdeviceptr_v1, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuGraphicsResourceGetMappedPointer_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphicsResourceGetMappedPointer_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext);

void btx_register_callbacks_lttng_ust_cuda_cuCtxDestroy_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxDestroy_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuCtxDestroy_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxDestroy_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxPopCurrent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext *);

void btx_register_callbacks_lttng_ust_cuda_cuCtxPopCurrent_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxPopCurrent_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxPopCurrent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUcontext);

void btx_register_callbacks_lttng_ust_cuda_cuCtxPopCurrent_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxPopCurrent_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxPushCurrent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext);

void btx_register_callbacks_lttng_ust_cuda_cuCtxPushCurrent_entry(
    void *btx_handle, lttng_ust_cuda_cuCtxPushCurrent_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCtxPushCurrent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuCtxPushCurrent_exit(
    void *btx_handle, lttng_ust_cuda_cuCtxPushCurrent_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuStreamDestroy_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamDestroy_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamDestroy_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamDestroy_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuEventDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUevent);

void btx_register_callbacks_lttng_ust_cuda_cuEventDestroy_entry(
    void *btx_handle, lttng_ust_cuda_cuEventDestroy_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuEventDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuEventDestroy_exit(
    void *btx_handle, lttng_ust_cuda_cuEventDestroy_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuEventElapsedTime_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, float *, CUevent, CUevent);

void btx_register_callbacks_lttng_ust_cuda_cuEventElapsedTime_entry(
    void *btx_handle, lttng_ust_cuda_cuEventElapsedTime_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuEventElapsedTime_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, float);

void btx_register_callbacks_lttng_ust_cuda_cuEventElapsedTime_exit(
    void *btx_handle, lttng_ust_cuda_cuEventElapsedTime_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDevicePrimaryCtxRelease_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuDevicePrimaryCtxRelease_entry(
    void *btx_handle, lttng_ust_cuda_cuDevicePrimaryCtxRelease_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDevicePrimaryCtxRelease_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuDevicePrimaryCtxRelease_exit(
    void *btx_handle, lttng_ust_cuda_cuDevicePrimaryCtxRelease_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDevicePrimaryCtxReset_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuDevicePrimaryCtxReset_entry(
    void *btx_handle, lttng_ust_cuda_cuDevicePrimaryCtxReset_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDevicePrimaryCtxReset_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuDevicePrimaryCtxReset_exit(
    void *btx_handle, lttng_ust_cuda_cuDevicePrimaryCtxReset_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDevicePrimaryCtxSetFlags_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdevice, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuDevicePrimaryCtxSetFlags_entry(
    void *btx_handle, lttng_ust_cuda_cuDevicePrimaryCtxSetFlags_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDevicePrimaryCtxSetFlags_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuDevicePrimaryCtxSetFlags_exit(
    void *btx_handle, lttng_ust_cuda_cuDevicePrimaryCtxSetFlags_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetUuid_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUuuid *, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetUuid_entry(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetUuid_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuDeviceGetUuid_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUuuid *);

void btx_register_callbacks_lttng_ust_cuda_cuDeviceGetUuid_exit(
    void *btx_handle, lttng_ust_cuda_cuDeviceGetUuid_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyHtoD_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, void *, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyHtoD_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyHtoD_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyHtoD_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyHtoD_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyHtoD_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyDtoH_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, CUdeviceptr, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyDtoH_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyDtoH_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyDtoH_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyDtoH_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyDtoH_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyDtoD_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, CUdeviceptr, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyDtoD_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyDtoD_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyDtoD_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyDtoD_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyDtoD_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyDtoA_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUarray, size_t, CUdeviceptr, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyDtoA_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyDtoA_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyDtoA_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyDtoA_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyDtoA_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyAtoD_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, CUarray, size_t, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyAtoD_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyAtoD_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyAtoD_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyAtoD_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyAtoD_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyHtoA_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUarray, size_t, void *, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyHtoA_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyHtoA_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyHtoA_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyHtoA_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyHtoA_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyAtoH_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, CUarray, size_t, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyAtoH_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyAtoH_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyAtoH_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyAtoH_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyAtoH_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyAtoA_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUarray, size_t, CUarray, size_t, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyAtoA_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyAtoA_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyAtoA_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyAtoA_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyAtoA_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyHtoAAsync_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUarray, size_t, void *, size_t, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyHtoAAsync_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyHtoAAsync_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyHtoAAsync_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyHtoAAsync_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyHtoAAsync_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyAtoHAsync_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, CUarray, size_t, size_t, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyAtoHAsync_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyAtoHAsync_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyAtoHAsync_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyAtoHAsync_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyAtoHAsync_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy2D_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUDA_MEMCPY2D *, size_t, CUDA_MEMCPY2D *);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy2D_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpy2D_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy2D_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy2D_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpy2D_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy2DUnaligned_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUDA_MEMCPY2D *, size_t, CUDA_MEMCPY2D *);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy2DUnaligned_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpy2DUnaligned_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy2DUnaligned_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy2DUnaligned_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpy2DUnaligned_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy3D_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUDA_MEMCPY3D *, size_t, CUDA_MEMCPY3D *);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy3D_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpy3D_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy3D_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy3D_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpy3D_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyHtoDAsync_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, void *, size_t, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyHtoDAsync_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyHtoDAsync_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyHtoDAsync_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyHtoDAsync_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyHtoDAsync_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyDtoHAsync_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, CUdeviceptr, size_t, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyDtoHAsync_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyDtoHAsync_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyDtoHAsync_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyDtoHAsync_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyDtoHAsync_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyDtoDAsync_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, CUdeviceptr, size_t, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyDtoDAsync_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyDtoDAsync_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyDtoDAsync_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyDtoDAsync_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyDtoDAsync_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy2DAsync_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUDA_MEMCPY2D *, CUstream, size_t, CUDA_MEMCPY2D *);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy2DAsync_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpy2DAsync_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy2DAsync_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy2DAsync_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpy2DAsync_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy3DAsync_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUDA_MEMCPY3D *, CUstream, size_t, CUDA_MEMCPY3D *);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy3DAsync_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpy3DAsync_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy3DAsync_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy3DAsync_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpy3DAsync_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD8_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, unsigned char, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD8_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuMemsetD8_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD8_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD8_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuMemsetD8_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD16_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, unsigned short int, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD16_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuMemsetD16_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD16_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD16_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuMemsetD16_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD32_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, unsigned int, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD32_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuMemsetD32_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD32_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD32_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuMemsetD32_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD2D8_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, size_t, unsigned char, size_t, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD2D8_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuMemsetD2D8_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD2D8_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD2D8_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuMemsetD2D8_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD2D16_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, size_t, unsigned short int, size_t, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD2D16_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuMemsetD2D16_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD2D16_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD2D16_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuMemsetD2D16_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD2D32_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, size_t, unsigned int, size_t, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD2D32_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuMemsetD2D32_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD2D32_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD2D32_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuMemsetD2D32_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, CUdeviceptr, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpy_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpy_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, CUdeviceptr, size_t, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyAsync_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyAsync_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyAsync_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyAsync_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyPeer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, CUcontext, CUdeviceptr, CUcontext, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyPeer_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyPeer_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyPeer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyPeer_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyPeer_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyPeerAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, CUcontext, CUdeviceptr, CUcontext, size_t, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyPeerAsync_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyPeerAsync_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyPeerAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyPeerAsync_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyPeerAsync_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy3DPeer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUDA_MEMCPY3D_PEER *, size_t, CUDA_MEMCPY3D_PEER *);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy3DPeer_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpy3DPeer_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy3DPeer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy3DPeer_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpy3DPeer_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy3DPeerAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUDA_MEMCPY3D_PEER *, CUstream, size_t, CUDA_MEMCPY3D_PEER *);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy3DPeerAsync_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpy3DPeerAsync_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy3DPeerAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy3DPeerAsync_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpy3DPeerAsync_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyBatchAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr *, CUdeviceptr *, size_t *, size_t, CUmemcpyAttributes *, size_t *, size_t, size_t *, CUstream, size_t, CUdeviceptr *, size_t, CUdeviceptr *, size_t, size_t *, size_t, CUmemcpyAttributes *, size_t, size_t *);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyBatchAsync_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyBatchAsync_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyBatchAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyBatchAsync_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyBatchAsync_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy3DBatchAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, size_t, CUDA_MEMCPY3D_BATCH_OP *, size_t *, unsigned long long int, CUstream, size_t, CUDA_MEMCPY3D_BATCH_OP *);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy3DBatchAsync_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpy3DBatchAsync_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy3DBatchAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy3DBatchAsync_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpy3DBatchAsync_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyBatchAsync_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr *, CUdeviceptr *, size_t *, size_t, CUmemcpyAttributes *, size_t *, size_t, size_t *, CUstream, size_t, CUdeviceptr *, size_t, CUdeviceptr *, size_t, size_t *, size_t, CUmemcpyAttributes *, size_t, size_t *);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyBatchAsync_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyBatchAsync_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyBatchAsync_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyBatchAsync_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyBatchAsync_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy3DBatchAsync_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, size_t, CUDA_MEMCPY3D_BATCH_OP *, size_t *, unsigned long long int, CUstream, size_t, CUDA_MEMCPY3D_BATCH_OP *);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy3DBatchAsync_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpy3DBatchAsync_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy3DBatchAsync_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy3DBatchAsync_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpy3DBatchAsync_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyBatchAsync_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr *, CUdeviceptr *, size_t *, size_t, CUmemcpyAttributes *, size_t *, size_t, CUstream, size_t, CUdeviceptr *, size_t, CUdeviceptr *, size_t, size_t *, size_t, CUmemcpyAttributes *, size_t, size_t *);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyBatchAsync_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpyBatchAsync_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpyBatchAsync_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpyBatchAsync_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpyBatchAsync_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy3DBatchAsync_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, size_t, CUDA_MEMCPY3D_BATCH_OP *, unsigned long long int, CUstream, size_t, CUDA_MEMCPY3D_BATCH_OP *);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy3DBatchAsync_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuMemcpy3DBatchAsync_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemcpy3DBatchAsync_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemcpy3DBatchAsync_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuMemcpy3DBatchAsync_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD8Async_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, unsigned char, size_t, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD8Async_entry(
    void *btx_handle, lttng_ust_cuda_cuMemsetD8Async_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD8Async_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD8Async_exit(
    void *btx_handle, lttng_ust_cuda_cuMemsetD8Async_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD16Async_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, unsigned short int, size_t, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD16Async_entry(
    void *btx_handle, lttng_ust_cuda_cuMemsetD16Async_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD16Async_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD16Async_exit(
    void *btx_handle, lttng_ust_cuda_cuMemsetD16Async_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD32Async_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, unsigned int, size_t, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD32Async_entry(
    void *btx_handle, lttng_ust_cuda_cuMemsetD32Async_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD32Async_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD32Async_exit(
    void *btx_handle, lttng_ust_cuda_cuMemsetD32Async_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD2D8Async_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, size_t, unsigned char, size_t, size_t, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD2D8Async_entry(
    void *btx_handle, lttng_ust_cuda_cuMemsetD2D8Async_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD2D8Async_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD2D8Async_exit(
    void *btx_handle, lttng_ust_cuda_cuMemsetD2D8Async_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD2D16Async_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, size_t, unsigned short int, size_t, size_t, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD2D16Async_entry(
    void *btx_handle, lttng_ust_cuda_cuMemsetD2D16Async_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD2D16Async_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD2D16Async_exit(
    void *btx_handle, lttng_ust_cuda_cuMemsetD2D16Async_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD2D32Async_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, size_t, unsigned int, size_t, size_t, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD2D32Async_entry(
    void *btx_handle, lttng_ust_cuda_cuMemsetD2D32Async_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemsetD2D32Async_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemsetD2D32Async_exit(
    void *btx_handle, lttng_ust_cuda_cuMemsetD2D32Async_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetPriority_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, int *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetPriority_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamGetPriority_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetPriority_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, int);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetPriority_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamGetPriority_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetId_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, unsigned long long int *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetId_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamGetId_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetId_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, unsigned long long int);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetId_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamGetId_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetFlags_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, unsigned int *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetFlags_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamGetFlags_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetFlags_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetFlags_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamGetFlags_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetDevice_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUdevice *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetDevice_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamGetDevice_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetDevice_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetDevice_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamGetDevice_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetCtx_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUcontext *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetCtx_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamGetCtx_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetCtx_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUcontext);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetCtx_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamGetCtx_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetCtx_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUcontext *, CUgreenCtx *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetCtx_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamGetCtx_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetCtx_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUcontext, CUgreenCtx);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetCtx_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamGetCtx_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamWaitEvent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUevent, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuStreamWaitEvent_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamWaitEvent_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamWaitEvent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamWaitEvent_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamWaitEvent_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamAddCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUstreamCallback, void *, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuStreamAddCallback_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamAddCallback_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamAddCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamAddCallback_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamAddCallback_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamAttachMemAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUdeviceptr, size_t, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuStreamAttachMemAsync_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamAttachMemAsync_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamAttachMemAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamAttachMemAsync_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamAttachMemAsync_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamQuery_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuStreamQuery_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamQuery_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamQuery_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamQuery_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamQuery_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamSynchronize_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuStreamSynchronize_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamSynchronize_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamSynchronize_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamSynchronize_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamSynchronize_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuEventRecord_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUevent, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuEventRecord_entry(
    void *btx_handle, lttng_ust_cuda_cuEventRecord_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuEventRecord_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuEventRecord_exit(
    void *btx_handle, lttng_ust_cuda_cuEventRecord_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuEventRecordWithFlags_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUevent, CUstream, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuEventRecordWithFlags_entry(
    void *btx_handle, lttng_ust_cuda_cuEventRecordWithFlags_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuEventRecordWithFlags_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuEventRecordWithFlags_exit(
    void *btx_handle, lttng_ust_cuda_cuEventRecordWithFlags_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuLaunchKernel_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUfunction, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, CUstream, void **, void **, size_t, void * *);

void btx_register_callbacks_lttng_ust_cuda_cuLaunchKernel_entry(
    void *btx_handle, lttng_ust_cuda_cuLaunchKernel_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuLaunchKernel_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuLaunchKernel_exit(
    void *btx_handle, lttng_ust_cuda_cuLaunchKernel_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuLaunchKernelEx_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUlaunchConfig *, CUfunction, void **, void **, size_t, CUlaunchConfig *, size_t, CUlaunchAttribute *, size_t, void * *);

void btx_register_callbacks_lttng_ust_cuda_cuLaunchKernelEx_entry(
    void *btx_handle, lttng_ust_cuda_cuLaunchKernelEx_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuLaunchKernelEx_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuLaunchKernelEx_exit(
    void *btx_handle, lttng_ust_cuda_cuLaunchKernelEx_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuLaunchHostFunc_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUhostFn, void *);

void btx_register_callbacks_lttng_ust_cuda_cuLaunchHostFunc_entry(
    void *btx_handle, lttng_ust_cuda_cuLaunchHostFunc_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuLaunchHostFunc_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuLaunchHostFunc_exit(
    void *btx_handle, lttng_ust_cuda_cuLaunchHostFunc_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphicsMapResources_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, unsigned int, CUgraphicsResource *, CUstream, size_t, CUgraphicsResource *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphicsMapResources_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphicsMapResources_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphicsMapResources_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphicsMapResources_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphicsMapResources_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphicsUnmapResources_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, unsigned int, CUgraphicsResource *, CUstream, size_t, CUgraphicsResource *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphicsUnmapResources_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphicsUnmapResources_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphicsUnmapResources_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphicsUnmapResources_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphicsUnmapResources_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamWriteValue32_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUdeviceptr, cuuint32_t, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuStreamWriteValue32_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamWriteValue32_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamWriteValue32_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamWriteValue32_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamWriteValue32_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamWaitValue32_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUdeviceptr, cuuint32_t, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuStreamWaitValue32_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamWaitValue32_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamWaitValue32_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamWaitValue32_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamWaitValue32_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamWriteValue64_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUdeviceptr, cuuint64_t, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuStreamWriteValue64_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamWriteValue64_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamWriteValue64_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamWriteValue64_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamWriteValue64_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamWaitValue64_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUdeviceptr, cuuint64_t, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuStreamWaitValue64_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamWaitValue64_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamWaitValue64_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamWaitValue64_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamWaitValue64_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamBatchMemOp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, unsigned int, CUstreamBatchMemOpParams *, unsigned int, size_t, CUstreamBatchMemOpParams *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamBatchMemOp_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamBatchMemOp_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamBatchMemOp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamBatchMemOp_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamBatchMemOp_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamWriteValue32_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUdeviceptr, cuuint32_t, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuStreamWriteValue32_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamWriteValue32_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamWriteValue32_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamWriteValue32_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamWriteValue32_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamWaitValue32_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUdeviceptr, cuuint32_t, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuStreamWaitValue32_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamWaitValue32_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamWaitValue32_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamWaitValue32_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamWaitValue32_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamWriteValue64_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUdeviceptr, cuuint64_t, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuStreamWriteValue64_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamWriteValue64_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamWriteValue64_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamWriteValue64_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamWriteValue64_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamWaitValue64_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUdeviceptr, cuuint64_t, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuStreamWaitValue64_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamWaitValue64_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamWaitValue64_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamWaitValue64_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamWaitValue64_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamBatchMemOp_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, unsigned int, CUstreamBatchMemOpParams *, unsigned int, size_t, CUstreamBatchMemOpParams *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamBatchMemOp_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamBatchMemOp_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamBatchMemOp_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamBatchMemOp_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamBatchMemOp_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamWriteValue32_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUdeviceptr, cuuint32_t, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuStreamWriteValue32_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamWriteValue32_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamWriteValue32_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamWriteValue32_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamWriteValue32_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamWaitValue32_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUdeviceptr, cuuint32_t, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuStreamWaitValue32_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamWaitValue32_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamWaitValue32_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamWaitValue32_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamWaitValue32_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamWriteValue64_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUdeviceptr, cuuint64_t, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuStreamWriteValue64_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamWriteValue64_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamWriteValue64_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamWriteValue64_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamWriteValue64_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamWaitValue64_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUdeviceptr, cuuint64_t, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuStreamWaitValue64_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamWaitValue64_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamWaitValue64_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamWaitValue64_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamWaitValue64_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamBatchMemOp_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, unsigned int, CUstreamBatchMemOpParams *, unsigned int, size_t, CUstreamBatchMemOpParams *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamBatchMemOp_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamBatchMemOp_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamBatchMemOp_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamBatchMemOp_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamBatchMemOp_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemPrefetchAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, size_t, CUdevice, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemPrefetchAsync_entry(
    void *btx_handle, lttng_ust_cuda_cuMemPrefetchAsync_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemPrefetchAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemPrefetchAsync_exit(
    void *btx_handle, lttng_ust_cuda_cuMemPrefetchAsync_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemPrefetchAsync_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, size_t, CUdevice, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemPrefetchAsync_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuMemPrefetchAsync_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemPrefetchAsync_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemPrefetchAsync_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuMemPrefetchAsync_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemPrefetchAsync_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, size_t, CUmemLocation, unsigned int, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemPrefetchAsync_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuMemPrefetchAsync_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemPrefetchAsync_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemPrefetchAsync_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuMemPrefetchAsync_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemAdvise_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, size_t, CUmem_advise, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_cuMemAdvise_entry(
    void *btx_handle, lttng_ust_cuda_cuMemAdvise_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemAdvise_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemAdvise_exit(
    void *btx_handle, lttng_ust_cuda_cuMemAdvise_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemPrefetchBatchAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr *, size_t *, size_t, CUmemLocation *, size_t *, size_t, unsigned long long int, CUstream, size_t, CUdeviceptr *, size_t, size_t *, size_t, CUmemLocation *, size_t, size_t *);

void btx_register_callbacks_lttng_ust_cuda_cuMemPrefetchBatchAsync_entry(
    void *btx_handle, lttng_ust_cuda_cuMemPrefetchBatchAsync_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemPrefetchBatchAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemPrefetchBatchAsync_exit(
    void *btx_handle, lttng_ust_cuda_cuMemPrefetchBatchAsync_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemDiscardBatchAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr *, size_t *, size_t, unsigned long long int, CUstream, size_t, CUdeviceptr *, size_t, size_t *);

void btx_register_callbacks_lttng_ust_cuda_cuMemDiscardBatchAsync_entry(
    void *btx_handle, lttng_ust_cuda_cuMemDiscardBatchAsync_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemDiscardBatchAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemDiscardBatchAsync_exit(
    void *btx_handle, lttng_ust_cuda_cuMemDiscardBatchAsync_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemDiscardAndPrefetchBatchAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr *, size_t *, size_t, CUmemLocation *, size_t *, size_t, unsigned long long int, CUstream, size_t, CUdeviceptr *, size_t, size_t *, size_t, CUmemLocation *, size_t, size_t *);

void btx_register_callbacks_lttng_ust_cuda_cuMemDiscardAndPrefetchBatchAsync_entry(
    void *btx_handle, lttng_ust_cuda_cuMemDiscardAndPrefetchBatchAsync_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemDiscardAndPrefetchBatchAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemDiscardAndPrefetchBatchAsync_exit(
    void *btx_handle, lttng_ust_cuda_cuMemDiscardAndPrefetchBatchAsync_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuLaunchCooperativeKernel_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUfunction, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, CUstream, void **);

void btx_register_callbacks_lttng_ust_cuda_cuLaunchCooperativeKernel_entry(
    void *btx_handle, lttng_ust_cuda_cuLaunchCooperativeKernel_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuLaunchCooperativeKernel_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuLaunchCooperativeKernel_exit(
    void *btx_handle, lttng_ust_cuda_cuLaunchCooperativeKernel_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuSignalExternalSemaphoresAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUexternalSemaphore *, CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS *, unsigned int, CUstream, size_t, CUexternalSemaphore *, size_t, CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS *);

void btx_register_callbacks_lttng_ust_cuda_cuSignalExternalSemaphoresAsync_entry(
    void *btx_handle, lttng_ust_cuda_cuSignalExternalSemaphoresAsync_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuSignalExternalSemaphoresAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuSignalExternalSemaphoresAsync_exit(
    void *btx_handle, lttng_ust_cuda_cuSignalExternalSemaphoresAsync_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuWaitExternalSemaphoresAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUexternalSemaphore *, CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS *, unsigned int, CUstream, size_t, CUexternalSemaphore *, size_t, CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS *);

void btx_register_callbacks_lttng_ust_cuda_cuWaitExternalSemaphoresAsync_entry(
    void *btx_handle, lttng_ust_cuda_cuWaitExternalSemaphoresAsync_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuWaitExternalSemaphoresAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuWaitExternalSemaphoresAsync_exit(
    void *btx_handle, lttng_ust_cuda_cuWaitExternalSemaphoresAsync_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamBeginCapture_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuStreamBeginCapture_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamBeginCapture_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamBeginCapture_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamBeginCapture_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamBeginCapture_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamBeginCapture_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuStreamBeginCapture_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamBeginCapture_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamBeginCapture_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamBeginCapture_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamBeginCapture_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamBeginCapture_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUstreamCaptureMode);

void btx_register_callbacks_lttng_ust_cuda_cuStreamBeginCapture_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamBeginCapture_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamBeginCapture_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamBeginCapture_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamBeginCapture_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamBeginCaptureToGraph_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUgraph, CUgraphNode *, CUgraphEdgeData *, size_t, CUstreamCaptureMode, size_t, CUgraphNode *, size_t, CUgraphEdgeData *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamBeginCaptureToGraph_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamBeginCaptureToGraph_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamBeginCaptureToGraph_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamBeginCaptureToGraph_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamBeginCaptureToGraph_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamEndCapture_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUgraph *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamEndCapture_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamEndCapture_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamEndCapture_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUgraph);

void btx_register_callbacks_lttng_ust_cuda_cuStreamEndCapture_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamEndCapture_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamIsCapturing_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUstreamCaptureStatus *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamIsCapturing_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamIsCapturing_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamIsCapturing_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUstreamCaptureStatus);

void btx_register_callbacks_lttng_ust_cuda_cuStreamIsCapturing_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamIsCapturing_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetCaptureInfo_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUstreamCaptureStatus *, cuuint64_t *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetCaptureInfo_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamGetCaptureInfo_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetCaptureInfo_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUstreamCaptureStatus, cuuint64_t);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetCaptureInfo_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamGetCaptureInfo_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetCaptureInfo_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUstreamCaptureStatus *, cuuint64_t *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetCaptureInfo_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamGetCaptureInfo_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetCaptureInfo_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUstreamCaptureStatus, cuuint64_t);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetCaptureInfo_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamGetCaptureInfo_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetCaptureInfo_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUstreamCaptureStatus *, cuuint64_t *, CUgraph *, CUgraphNode **, size_t *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetCaptureInfo_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamGetCaptureInfo_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetCaptureInfo_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUstreamCaptureStatus, cuuint64_t, CUgraph, CUgraphNode *, size_t, size_t, CUgraphNode *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetCaptureInfo_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamGetCaptureInfo_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetCaptureInfo_v2_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUstreamCaptureStatus *, cuuint64_t *, CUgraph *, CUgraphNode **, size_t *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetCaptureInfo_v2_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamGetCaptureInfo_v2_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetCaptureInfo_v2_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUstreamCaptureStatus, cuuint64_t, CUgraph, CUgraphNode *, size_t, size_t, CUgraphNode *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetCaptureInfo_v2_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamGetCaptureInfo_v2_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetCaptureInfo_v3_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUstreamCaptureStatus *, cuuint64_t *, CUgraph *, CUgraphNode **, CUgraphEdgeData **, size_t *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetCaptureInfo_v3_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamGetCaptureInfo_v3_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetCaptureInfo_v3_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUstreamCaptureStatus, cuuint64_t, CUgraph, size_t, size_t, CUgraphNode *, size_t, CUgraphEdgeData *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetCaptureInfo_v3_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamGetCaptureInfo_v3_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphAddKernelNode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode *, CUgraph, CUgraphNode *, size_t, CUDA_KERNEL_NODE_PARAMS_v1 *, size_t, CUgraphNode *, size_t, CUDA_KERNEL_NODE_PARAMS_v1 *, size_t, void * *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphAddKernelNode_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphAddKernelNode_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphAddKernelNode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUgraphNode);

void btx_register_callbacks_lttng_ust_cuda_cuGraphAddKernelNode_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphAddKernelNode_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphKernelNodeGetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode, CUDA_KERNEL_NODE_PARAMS_v1 *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphKernelNodeGetParams_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphKernelNodeGetParams_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphKernelNodeGetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUDA_KERNEL_NODE_PARAMS_v1 *, size_t, void * *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphKernelNodeGetParams_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphKernelNodeGetParams_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphKernelNodeSetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode, CUDA_KERNEL_NODE_PARAMS_v1 *, size_t, CUDA_KERNEL_NODE_PARAMS_v1 *, size_t, void * *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphKernelNodeSetParams_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphKernelNodeSetParams_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphKernelNodeSetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphKernelNodeSetParams_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphKernelNodeSetParams_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExecKernelNodeSetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphExec, CUgraphNode, CUDA_KERNEL_NODE_PARAMS_v1 *, size_t, CUDA_KERNEL_NODE_PARAMS_v1 *, size_t, void * *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExecKernelNodeSetParams_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphExecKernelNodeSetParams_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExecKernelNodeSetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExecKernelNodeSetParams_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphExecKernelNodeSetParams_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphInstantiateWithParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphExec *, CUgraph, CUDA_GRAPH_INSTANTIATE_PARAMS *, size_t, CUDA_GRAPH_INSTANTIATE_PARAMS *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphInstantiateWithParams_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphInstantiateWithParams_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphInstantiateWithParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUgraphExec);

void btx_register_callbacks_lttng_ust_cuda_cuGraphInstantiateWithParams_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphInstantiateWithParams_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExecUpdate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphExec, CUgraph, CUgraphNode *, CUgraphExecUpdateResult *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExecUpdate_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphExecUpdate_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphExecUpdate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUgraphNode, CUgraphExecUpdateResult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphExecUpdate_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphExecUpdate_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphUpload_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphExec, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuGraphUpload_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphUpload_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphUpload_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphUpload_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphUpload_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphLaunch_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphExec, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuGraphLaunch_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphLaunch_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphLaunch_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphLaunch_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphLaunch_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphGetEdges_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraph, CUgraphNode *, CUgraphNode *, size_t *, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuGraphGetEdges_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphGetEdges_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphGetEdges_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, size_t, CUgraphNode *, size_t, CUgraphNode *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphGetEdges_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphGetEdges_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphNodeGetDependencies_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode, CUgraphNode *, size_t *, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuGraphNodeGetDependencies_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphNodeGetDependencies_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphNodeGetDependencies_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, size_t, CUgraphNode *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphNodeGetDependencies_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphNodeGetDependencies_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphNodeGetDependentNodes_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode, CUgraphNode *, size_t *, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuGraphNodeGetDependentNodes_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphNodeGetDependentNodes_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphNodeGetDependentNodes_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, size_t, CUgraphNode *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphNodeGetDependentNodes_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphNodeGetDependentNodes_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphAddDependencies_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraph, CUgraphNode *, CUgraphNode *, size_t, size_t, CUgraphNode *, size_t, CUgraphNode *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphAddDependencies_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphAddDependencies_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphAddDependencies_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphAddDependencies_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphAddDependencies_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphRemoveDependencies_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraph, CUgraphNode *, CUgraphNode *, size_t, size_t, CUgraphNode *, size_t, CUgraphNode *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphRemoveDependencies_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphRemoveDependencies_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphRemoveDependencies_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphRemoveDependencies_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphRemoveDependencies_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphAddNode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphNode *, CUgraph, CUgraphNode *, size_t, CUgraphNodeParams *, size_t, CUgraphNode *, size_t, CUgraphNodeParams *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphAddNode_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphAddNode_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphAddNode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUgraphNode);

void btx_register_callbacks_lttng_ust_cuda_cuGraphAddNode_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphAddNode_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamCopyAttributes_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuStreamCopyAttributes_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamCopyAttributes_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamCopyAttributes_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamCopyAttributes_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamCopyAttributes_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetAttribute_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUstreamAttrID, CUstreamAttrValue *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetAttribute_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamGetAttribute_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamGetAttribute_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, CUstreamAttrValue *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamGetAttribute_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamGetAttribute_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamSetAttribute_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUstreamAttrID, CUstreamAttrValue *, size_t, CUstreamAttrValue *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamSetAttribute_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamSetAttribute_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamSetAttribute_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamSetAttribute_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamSetAttribute_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuIpcOpenMemHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr *, CUipcMemHandle, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuIpcOpenMemHandle_entry(
    void *btx_handle, lttng_ust_cuda_cuIpcOpenMemHandle_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuIpcOpenMemHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUdeviceptr);

void btx_register_callbacks_lttng_ust_cuda_cuIpcOpenMemHandle_exit(
    void *btx_handle, lttng_ust_cuda_cuIpcOpenMemHandle_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphInstantiate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphExec *, CUgraph, CUgraphNode *, char *, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuGraphInstantiate_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphInstantiate_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphInstantiate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUgraphExec, CUgraphNode, size_t, char *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphInstantiate_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphInstantiate_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphInstantiate_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphExec *, CUgraph, CUgraphNode *, char *, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuGraphInstantiate_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphInstantiate_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphInstantiate_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUgraphExec, CUgraphNode, size_t, char *);

void btx_register_callbacks_lttng_ust_cuda_cuGraphInstantiate_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphInstantiate_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemMapArrayAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUarrayMapInfo *, unsigned int, CUstream, size_t, CUarrayMapInfo *);

void btx_register_callbacks_lttng_ust_cuda_cuMemMapArrayAsync_entry(
    void *btx_handle, lttng_ust_cuda_cuMemMapArrayAsync_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemMapArrayAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemMapArrayAsync_exit(
    void *btx_handle, lttng_ust_cuda_cuMemMapArrayAsync_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemFreeAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemFreeAsync_entry(
    void *btx_handle, lttng_ust_cuda_cuMemFreeAsync_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemFreeAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuMemFreeAsync_exit(
    void *btx_handle, lttng_ust_cuda_cuMemFreeAsync_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemAllocAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr *, size_t, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemAllocAsync_entry(
    void *btx_handle, lttng_ust_cuda_cuMemAllocAsync_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemAllocAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUdeviceptr);

void btx_register_callbacks_lttng_ust_cuda_cuMemAllocAsync_exit(
    void *btx_handle, lttng_ust_cuda_cuMemAllocAsync_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemAllocFromPoolAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdeviceptr *, size_t, CUmemoryPool, CUstream);

void btx_register_callbacks_lttng_ust_cuda_cuMemAllocFromPoolAsync_entry(
    void *btx_handle, lttng_ust_cuda_cuMemAllocFromPoolAsync_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemAllocFromPoolAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUdeviceptr);

void btx_register_callbacks_lttng_ust_cuda_cuMemAllocFromPoolAsync_exit(
    void *btx_handle, lttng_ust_cuda_cuMemAllocFromPoolAsync_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamUpdateCaptureDependencies_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUgraphNode *, size_t, unsigned int, size_t, CUgraphNode *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamUpdateCaptureDependencies_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamUpdateCaptureDependencies_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamUpdateCaptureDependencies_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamUpdateCaptureDependencies_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamUpdateCaptureDependencies_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamUpdateCaptureDependencies_ptsz_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUgraphNode *, size_t, unsigned int, size_t, CUgraphNode *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamUpdateCaptureDependencies_ptsz_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamUpdateCaptureDependencies_ptsz_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamUpdateCaptureDependencies_ptsz_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamUpdateCaptureDependencies_ptsz_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamUpdateCaptureDependencies_ptsz_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamUpdateCaptureDependencies_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUstream, CUgraphNode *, CUgraphEdgeData *, size_t, unsigned int, size_t, CUgraphNode *, size_t, CUgraphEdgeData *);

void btx_register_callbacks_lttng_ust_cuda_cuStreamUpdateCaptureDependencies_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuStreamUpdateCaptureDependencies_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuStreamUpdateCaptureDependencies_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuStreamUpdateCaptureDependencies_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuStreamUpdateCaptureDependencies_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuMemBatchDecompressAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmemDecompressParams *, size_t, unsigned int, size_t *, CUstream, size_t, CUmemDecompressParams *);

void btx_register_callbacks_lttng_ust_cuda_cuMemBatchDecompressAsync_entry(
    void *btx_handle, lttng_ust_cuda_cuMemBatchDecompressAsync_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuMemBatchDecompressAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t);

void btx_register_callbacks_lttng_ust_cuda_cuMemBatchDecompressAsync_exit(
    void *btx_handle, lttng_ust_cuda_cuMemBatchDecompressAsync_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGetProcAddress_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, void **, int, cuuint64_t, char *);

void btx_register_callbacks_lttng_ust_cuda_cuGetProcAddress_entry(
    void *btx_handle, lttng_ust_cuda_cuGetProcAddress_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGetProcAddress_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, void *);

void btx_register_callbacks_lttng_ust_cuda_cuGetProcAddress_exit(
    void *btx_handle, lttng_ust_cuda_cuGetProcAddress_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCheckpointProcessGetRestoreThreadId_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int *);

void btx_register_callbacks_lttng_ust_cuda_cuCheckpointProcessGetRestoreThreadId_entry(
    void *btx_handle, lttng_ust_cuda_cuCheckpointProcessGetRestoreThreadId_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCheckpointProcessGetRestoreThreadId_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, int);

void btx_register_callbacks_lttng_ust_cuda_cuCheckpointProcessGetRestoreThreadId_exit(
    void *btx_handle, lttng_ust_cuda_cuCheckpointProcessGetRestoreThreadId_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCheckpointProcessGetState_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, CUprocessState *);

void btx_register_callbacks_lttng_ust_cuda_cuCheckpointProcessGetState_entry(
    void *btx_handle, lttng_ust_cuda_cuCheckpointProcessGetState_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCheckpointProcessGetState_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUprocessState);

void btx_register_callbacks_lttng_ust_cuda_cuCheckpointProcessGetState_exit(
    void *btx_handle, lttng_ust_cuda_cuCheckpointProcessGetState_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCheckpointProcessLock_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, CUcheckpointLockArgs *, size_t, CUcheckpointLockArgs *);

void btx_register_callbacks_lttng_ust_cuda_cuCheckpointProcessLock_entry(
    void *btx_handle, lttng_ust_cuda_cuCheckpointProcessLock_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCheckpointProcessLock_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuCheckpointProcessLock_exit(
    void *btx_handle, lttng_ust_cuda_cuCheckpointProcessLock_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCheckpointProcessCheckpoint_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, CUcheckpointCheckpointArgs *, size_t, CUcheckpointCheckpointArgs *);

void btx_register_callbacks_lttng_ust_cuda_cuCheckpointProcessCheckpoint_entry(
    void *btx_handle, lttng_ust_cuda_cuCheckpointProcessCheckpoint_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCheckpointProcessCheckpoint_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuCheckpointProcessCheckpoint_exit(
    void *btx_handle, lttng_ust_cuda_cuCheckpointProcessCheckpoint_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCheckpointProcessRestore_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, CUcheckpointRestoreArgs *, size_t, CUcheckpointRestoreArgs *, size_t, CUcheckpointGpuPair *);

void btx_register_callbacks_lttng_ust_cuda_cuCheckpointProcessRestore_entry(
    void *btx_handle, lttng_ust_cuda_cuCheckpointProcessRestore_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCheckpointProcessRestore_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuCheckpointProcessRestore_exit(
    void *btx_handle, lttng_ust_cuda_cuCheckpointProcessRestore_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuCheckpointProcessUnlock_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, CUcheckpointUnlockArgs *, size_t, CUcheckpointUnlockArgs *);

void btx_register_callbacks_lttng_ust_cuda_cuCheckpointProcessUnlock_entry(
    void *btx_handle, lttng_ust_cuda_cuCheckpointProcessUnlock_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuCheckpointProcessUnlock_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuCheckpointProcessUnlock_exit(
    void *btx_handle, lttng_ust_cuda_cuCheckpointProcessUnlock_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuVDPAUGetDevice_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdevice *, VdpDevice, VdpGetProcAddress *);

void btx_register_callbacks_lttng_ust_cuda_cuVDPAUGetDevice_entry(
    void *btx_handle, lttng_ust_cuda_cuVDPAUGetDevice_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuVDPAUGetDevice_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuVDPAUGetDevice_exit(
    void *btx_handle, lttng_ust_cuda_cuVDPAUGetDevice_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuVDPAUCtxCreate_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext *, unsigned int, CUdevice, VdpDevice, VdpGetProcAddress *);

void btx_register_callbacks_lttng_ust_cuda_cuVDPAUCtxCreate_v2_entry(
    void *btx_handle, lttng_ust_cuda_cuVDPAUCtxCreate_v2_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuVDPAUCtxCreate_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuVDPAUCtxCreate_v2_exit(
    void *btx_handle, lttng_ust_cuda_cuVDPAUCtxCreate_v2_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphicsVDPAURegisterVideoSurface_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphicsResource *, VdpVideoSurface, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuGraphicsVDPAURegisterVideoSurface_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphicsVDPAURegisterVideoSurface_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphicsVDPAURegisterVideoSurface_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphicsVDPAURegisterVideoSurface_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphicsVDPAURegisterVideoSurface_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphicsVDPAURegisterOutputSurface_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUgraphicsResource *, VdpOutputSurface, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_cuGraphicsVDPAURegisterOutputSurface_entry(
    void *btx_handle, lttng_ust_cuda_cuGraphicsVDPAURegisterOutputSurface_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuGraphicsVDPAURegisterOutputSurface_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuGraphicsVDPAURegisterOutputSurface_exit(
    void *btx_handle, lttng_ust_cuda_cuGraphicsVDPAURegisterOutputSurface_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuVDPAUCtxCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext *, unsigned int, CUdevice, VdpDevice, VdpGetProcAddress *);

void btx_register_callbacks_lttng_ust_cuda_cuVDPAUCtxCreate_entry(
    void *btx_handle, lttng_ust_cuda_cuVDPAUCtxCreate_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuVDPAUCtxCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuVDPAUCtxCreate_exit(
    void *btx_handle, lttng_ust_cuda_cuVDPAUCtxCreate_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuProfilerInitialize_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, char *, CUoutput_mode);

void btx_register_callbacks_lttng_ust_cuda_cuProfilerInitialize_entry(
    void *btx_handle, lttng_ust_cuda_cuProfilerInitialize_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuProfilerInitialize_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuProfilerInitialize_exit(
    void *btx_handle, lttng_ust_cuda_cuProfilerInitialize_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuProfilerStart_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_cuda_cuProfilerStart_entry(
    void *btx_handle, lttng_ust_cuda_cuProfilerStart_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuProfilerStart_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuProfilerStart_exit(
    void *btx_handle, lttng_ust_cuda_cuProfilerStart_exit_callback_f *callback);

typedef void lttng_ust_cuda_cuProfilerStop_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_cuda_cuProfilerStop_entry(
    void *btx_handle, lttng_ust_cuda_cuProfilerStop_entry_callback_f *callback);

typedef void lttng_ust_cuda_cuProfilerStop_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_cuProfilerStop_exit(
    void *btx_handle, lttng_ust_cuda_cuProfilerStop_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_function_get_name_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext, CUfunction, char **);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_function_get_name_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_function_get_name_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_function_get_name_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, char *, char *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_function_get_name_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_function_get_name_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexpFunction_setCacheConfig_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUfunction, CUfunc_cache);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexpFunction_setCacheConfig_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexpFunction_setCacheConfig_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexpFunction_setCacheConfig_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexpFunction_setCacheConfig_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexpFunction_setCacheConfig_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_6e163fbe_d8_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmodule, int *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_6e163fbe_d8_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_6e163fbe_d8_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_6e163fbe_d8_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, int);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_6e163fbe_d8_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_6e163fbe_d8_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexpFunction_get_arg_count_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUfunction, size_t *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexpFunction_get_arg_count_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexpFunction_get_arg_count_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexpFunction_get_arg_count_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexpFunction_get_arg_count_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexpFunction_get_arg_count_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexpFunction_get_arg_descriptor_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUfunction, size_t, cuexp_function_arg_desc_query *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexpFunction_get_arg_descriptor_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexpFunction_get_arg_descriptor_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexpFunction_get_arg_descriptor_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, cuexp_function_arg_desc_query *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexpFunction_get_arg_descriptor_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexpFunction_get_arg_descriptor_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_6e163fbe_130_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void **, CUfunction);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_6e163fbe_130_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_6e163fbe_130_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_6e163fbe_130_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, void *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_6e163fbe_130_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_6e163fbe_130_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_module_iterate_on_functions_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext, CUmodule, void *, void *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_module_iterate_on_functions_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_module_iterate_on_functions_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_module_iterate_on_functions_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_module_iterate_on_functions_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_module_iterate_on_functions_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_6e163fbe_1a8_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUfunction, int *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_6e163fbe_1a8_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_6e163fbe_1a8_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_6e163fbe_1a8_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, int);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_6e163fbe_1a8_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_6e163fbe_1a8_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_6e163fbe_1b8_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUfunction, unsigned long int *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_6e163fbe_1b8_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_6e163fbe_1b8_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_6e163fbe_1b8_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, unsigned long int);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_6e163fbe_1b8_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_6e163fbe_1b8_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexpDevice_get_primary_context_refcount_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexpDevice_get_primary_context_refcount_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexpDevice_get_primary_context_refcount_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexpDevice_get_primary_context_refcount_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexpDevice_get_primary_context_refcount_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexpDevice_get_primary_context_refcount_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_get_thread_context_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_get_thread_context_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_get_thread_context_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_get_thread_context_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUcontext);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_get_thread_context_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_get_thread_context_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_a094798c_08_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, unsigned int, void **, void *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_a094798c_08_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_a094798c_08_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_a094798c_08_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, void *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_a094798c_08_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_a094798c_08_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_a094798c_10_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void **, size_t *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_a094798c_10_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_a094798c_10_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_a094798c_10_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, size_t);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_a094798c_10_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_a094798c_10_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_a094798c_18_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext, void *, void **);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_a094798c_18_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_a094798c_18_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_a094798c_18_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, void *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_a094798c_18_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_a094798c_18_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_a094798c_20_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext, uint64_t *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_a094798c_20_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_a094798c_20_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_a094798c_20_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, uint64_t);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_a094798c_20_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_a094798c_20_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_a094798c_28_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, unsigned int, void *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_a094798c_28_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_a094798c_28_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_a094798c_28_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_a094798c_28_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_a094798c_28_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_a094798c_30_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void **, size_t *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_a094798c_30_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_a094798c_30_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_a094798c_30_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, size_t);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_a094798c_30_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_a094798c_30_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexpContext_kvstore_add_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext, void *, void *, void *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexpContext_kvstore_add_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexpContext_kvstore_add_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexpContext_kvstore_add_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexpContext_kvstore_add_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexpContext_kvstore_add_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexpContext_kvstore_delete_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext, void *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexpContext_kvstore_delete_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexpContext_kvstore_delete_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexpContext_kvstore_delete_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexpContext_kvstore_delete_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexpContext_kvstore_delete_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexpContext_kvstore_get_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void **, CUcontext, void *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexpContext_kvstore_get_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexpContext_kvstore_get_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexpContext_kvstore_get_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, void *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexpContext_kvstore_get_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexpContext_kvstore_get_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_get_primary_context_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext *, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_get_primary_context_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_get_primary_context_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_get_primary_context_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUcontext);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_get_primary_context_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_get_primary_context_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_register_module_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUmodule *, int *, void *, void *, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_register_module_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_register_module_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_register_module_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUmodule);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_register_module_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_register_module_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_unregister_module_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_unregister_module_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_unregister_module_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_unregister_module_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_unregister_module_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_unregister_module_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexpContext_getDevice_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext, CUdevice *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexpContext_getDevice_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexpContext_getDevice_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexpContext_getDevice_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexpContext_getDevice_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexpContext_getDevice_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexpContext_getContextNumber_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext, unsigned long int *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexpContext_getContextNumber_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexpContext_getContextNumber_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexpContext_getContextNumber_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, unsigned long int);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexpContext_getContextNumber_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexpContext_getContextNumber_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_21318c60_80_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void **);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_21318c60_80_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_21318c60_80_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_21318c60_80_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, void *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_21318c60_80_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_21318c60_80_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_21318c60_138_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUcontext, void *, void **);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_21318c60_138_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_21318c60_138_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_21318c60_138_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, void *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_21318c60_138_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_21318c60_138_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexpDevice_get_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdevice *, int);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexpDevice_get_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexpDevice_get_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexpDevice_get_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexpDevice_get_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexpDevice_get_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexpDevice_getCount_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, unsigned int *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexpDevice_getCount_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexpDevice_getCount_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexpDevice_getCount_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexpDevice_getCount_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexpDevice_getCount_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexpDevice_getAttribute_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, CUdevice_attribute, int, long int *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexpDevice_getAttribute_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexpDevice_getAttribute_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexpDevice_getAttribute_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, long int);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexpDevice_getAttribute_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexpDevice_getAttribute_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_b10541e1_30_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdevice, void **);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_b10541e1_30_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_b10541e1_30_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_b10541e1_30_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, void *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_b10541e1_30_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_b10541e1_30_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_b10541e1_40_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, unsigned int *, CUdevice);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_b10541e1_40_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_b10541e1_40_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_b10541e1_40_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_b10541e1_40_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_b10541e1_40_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_a6b1ff99_28_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void **, CUcontext);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_a6b1ff99_28_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_a6b1ff99_28_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_a6b1ff99_28_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, void *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_a6b1ff99_28_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_a6b1ff99_28_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_127d4831_28_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, void **, void *, void *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_127d4831_28_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_127d4831_28_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_127d4831_28_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, void *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_127d4831_28_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_127d4831_28_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_127d4831_30_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, void **, void *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_127d4831_30_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_127d4831_30_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_127d4831_30_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, void *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_127d4831_30_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_127d4831_30_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexpCUPTI_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexpCUPTI_init_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexpCUPTI_init_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexpCUPTI_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexpCUPTI_init_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexpCUPTI_init_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_7cb63f9b_1e0_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUdevice, cuexp_7cb63f9b_1e0_struct *, size_t, cuexp_7cb63f9b_1e0_struct *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_7cb63f9b_1e0_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_7cb63f9b_1e0_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_7cb63f9b_1e0_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, size_t, cuexp_7cb63f9b_1e0_struct *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_7cb63f9b_1e0_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_7cb63f9b_1e0_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_2c8e0ad8_18_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, void *, void *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_2c8e0ad8_18_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_2c8e0ad8_18_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_2c8e0ad8_18_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, int);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_2c8e0ad8_18_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_2c8e0ad8_18_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_2c8e0ad8_38_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, unsigned int);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_2c8e0ad8_38_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_2c8e0ad8_38_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_2c8e0ad8_38_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_2c8e0ad8_38_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_2c8e0ad8_38_exit_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_getCudaState_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_getCudaState_entry(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_getCudaState_entry_callback_f *callback);

typedef void lttng_ust_cuda_exports_cuexp_getCudaState_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUresult, int);

void btx_register_callbacks_lttng_ust_cuda_exports_cuexp_getCudaState_exit(
    void *btx_handle, lttng_ust_cuda_exports_cuexp_getCudaState_exit_callback_f *callback);

typedef void lttng_ust_cuda_args_arg_count_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUfunction, size_t);

void btx_register_callbacks_lttng_ust_cuda_args_arg_count(
    void *btx_handle, lttng_ust_cuda_args_arg_count_callback_f *callback);

typedef void lttng_ust_cuda_args_arg_value_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUfunction, size_t, void *, size_t, void *);

void btx_register_callbacks_lttng_ust_cuda_args_arg_value(
    void *btx_handle, lttng_ust_cuda_args_arg_value_callback_f *callback);

typedef void lttng_ust_cuda_profiling_event_profiling_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUevent, CUevent);

void btx_register_callbacks_lttng_ust_cuda_profiling_event_profiling(
    void *btx_handle, lttng_ust_cuda_profiling_event_profiling_callback_f *callback);

typedef void lttng_ust_cuda_profiling_event_profiling_results_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUevent, CUevent, CUresult, CUresult, CUresult, float);

void btx_register_callbacks_lttng_ust_cuda_profiling_event_profiling_results(
    void *btx_handle, lttng_ust_cuda_profiling_event_profiling_results_callback_f *callback);

typedef void lttng_ust_cuda_exports_export_called_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, CUuuid *, size_t, size_t, CUuuid *);

void btx_register_callbacks_lttng_ust_cuda_exports_export_called(
    void *btx_handle, lttng_ust_cuda_exports_export_called_callback_f *callback);

typedef void lttng_ust_cuda_properties_device_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, CUdevice, char *, size_t, CUuuid *);

void btx_register_callbacks_lttng_ust_cuda_properties_device(
    void *btx_handle, lttng_ust_cuda_properties_device_callback_f *callback);

typedef void entries_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t);

void btx_register_callbacks_entries(
    void *btx_handle, entries_callback_f *callback);

typedef void exits_cudaError_present_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_exits_cudaError_present(
    void *btx_handle, exits_cudaError_present_callback_f *callback);

typedef void exits_cudaError_absent_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t);

void btx_register_callbacks_exits_cudaError_absent(
    void *btx_handle, exits_cudaError_absent_callback_f *callback);

typedef void entries_traffic_v2_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, size_t);

void btx_register_callbacks_entries_traffic_v2(
    void *btx_handle, entries_traffic_v2_callback_f *callback);

typedef void entries_traffic_v1_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, unsigned int);

void btx_register_callbacks_entries_traffic_v1(
    void *btx_handle, entries_traffic_v1_callback_f *callback);

typedef void entries_traffic_2d_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, CUDA_MEMCPY2D *);

void btx_register_callbacks_entries_traffic_2d(
    void *btx_handle, entries_traffic_2d_callback_f *callback);

typedef void entries_traffic_2d_v1_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, CUDA_MEMCPY2D_v1 *);

void btx_register_callbacks_entries_traffic_2d_v1(
    void *btx_handle, entries_traffic_2d_v1_callback_f *callback);

typedef void entries_traffic_3d_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, CUDA_MEMCPY3D *);

void btx_register_callbacks_entries_traffic_3d(
    void *btx_handle, entries_traffic_3d_callback_f *callback);

typedef void entries_traffic_3d_v1_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, CUDA_MEMCPY3D_v1 *);

void btx_register_callbacks_entries_traffic_3d_v1(
    void *btx_handle, entries_traffic_3d_v1_callback_f *callback);

typedef void entries_traffic_3d_peer_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, CUDA_MEMCPY3D_PEER *);

void btx_register_callbacks_entries_traffic_3d_peer(
    void *btx_handle, entries_traffic_3d_peer_callback_f *callback);

typedef void exits_traffic_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_exits_traffic(
    void *btx_handle, exits_traffic_callback_f *callback);

typedef void ctx_create_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, CUdevice);

void btx_register_callbacks_ctx_create_entry(
    void *btx_handle, ctx_create_entry_callback_f *callback);

typedef void ctx_create_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, CUresult, CUcontext);

void btx_register_callbacks_ctx_create_exit(
    void *btx_handle, ctx_create_exit_callback_f *callback);

typedef void ctx_destroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, CUcontext);

void btx_register_callbacks_ctx_destroy_entry(
    void *btx_handle, ctx_destroy_entry_callback_f *callback);

typedef void ctx_destroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_ctx_destroy_exit(
    void *btx_handle, ctx_destroy_exit_callback_f *callback);

typedef void ctx_set_current_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, CUcontext);

void btx_register_callbacks_ctx_set_current_entry(
    void *btx_handle, ctx_set_current_entry_callback_f *callback);

typedef void ctx_set_current_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_ctx_set_current_exit(
    void *btx_handle, ctx_set_current_exit_callback_f *callback);

typedef void ctx_push_current_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, CUcontext);

void btx_register_callbacks_ctx_push_current_entry(
    void *btx_handle, ctx_push_current_entry_callback_f *callback);

typedef void ctx_push_current_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, CUresult);

void btx_register_callbacks_ctx_push_current_exit(
    void *btx_handle, ctx_push_current_exit_callback_f *callback);

typedef void ctx_pop_current_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t);

void btx_register_callbacks_ctx_pop_current_entry(
    void *btx_handle, ctx_pop_current_entry_callback_f *callback);

typedef void ctx_pop_current_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, CUresult, CUcontext);

void btx_register_callbacks_ctx_pop_current_exit(
    void *btx_handle, ctx_pop_current_exit_callback_f *callback);

typedef void primary_ctx_retain_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, CUdevice);

void btx_register_callbacks_primary_ctx_retain_entry(
    void *btx_handle, primary_ctx_retain_entry_callback_f *callback);

typedef void primary_ctx_retain_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, CUresult, CUcontext);

void btx_register_callbacks_primary_ctx_retain_exit(
    void *btx_handle, primary_ctx_retain_exit_callback_f *callback);

typedef void stream_create_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, CUresult, CUstream);

void btx_register_callbacks_stream_create_exit(
    void *btx_handle, stream_create_exit_callback_f *callback);

typedef void module_get_function_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, char *);

void btx_register_callbacks_module_get_function_entry(
    void *btx_handle, module_get_function_entry_callback_f *callback);

typedef void module_get_function_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, CUresult, CUfunction);

void btx_register_callbacks_module_get_function_exit(
    void *btx_handle, module_get_function_exit_callback_f *callback);

typedef void kernel_task_stream_present_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, CUstream, CUfunction);

void btx_register_callbacks_kernel_task_stream_present_entry(
    void *btx_handle, kernel_task_stream_present_entry_callback_f *callback);

typedef void kernel_task_stream_absent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, CUfunction);

void btx_register_callbacks_kernel_task_stream_absent_entry(
    void *btx_handle, kernel_task_stream_absent_entry_callback_f *callback);

typedef void non_kernel_task_stream_present_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, CUstream);

void btx_register_callbacks_non_kernel_task_stream_present_entry(
    void *btx_handle, non_kernel_task_stream_present_entry_callback_f *callback);

typedef void non_kernel_task_stream_absent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t);

void btx_register_callbacks_non_kernel_task_stream_absent_entry(
    void *btx_handle, non_kernel_task_stream_absent_entry_callback_f *callback);

void btx_unregister_callbacks(common_data_t *common_data);

#ifdef __cplusplus
}
#endif
