#pragma once
#include <metababel/btx_component.h>
#ifdef __cplusplus
extern "C" {
#endif

// Dispatcher
typedef void(dispatcher_t)(callbacks_t *callbacks, common_data_t *common_data,
                           const bt_message *upstream_message);

typedef void lttng_ust_hip_hipCreateChannelDesc_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, int, int, enum hipChannelFormatKind);

void btx_register_callbacks_lttng_ust_hip_hipCreateChannelDesc_entry(
    void *btx_handle, lttng_ust_hip_hipCreateChannelDesc_entry_callback_f *callback);

typedef void lttng_ust_hip_hipCreateChannelDesc_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, struct hipChannelFormatDesc);

void btx_register_callbacks_lttng_ust_hip_hipCreateChannelDesc_exit(
    void *btx_handle, lttng_ust_hip_hipCreateChannelDesc_exit_callback_f *callback);

typedef void lttng_ust_hip___hipGetPCH_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char **, unsigned int *);

void btx_register_callbacks_lttng_ust_hip___hipGetPCH_entry(
    void *btx_handle, lttng_ust_hip___hipGetPCH_entry_callback_f *callback);

typedef void lttng_ust_hip___hipGetPCH_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_hip___hipGetPCH_exit(
    void *btx_handle, lttng_ust_hip___hipGetPCH_exit_callback_f *callback);

typedef void lttng_ust_hip_hipInit_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipInit_entry(
    void *btx_handle, lttng_ust_hip_hipInit_entry_callback_f *callback);

typedef void lttng_ust_hip_hipInit_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipInit_exit(
    void *btx_handle, lttng_ust_hip_hipInit_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDriverGetVersion_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *);

void btx_register_callbacks_lttng_ust_hip_hipDriverGetVersion_entry(
    void *btx_handle, lttng_ust_hip_hipDriverGetVersion_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDriverGetVersion_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, int);

void btx_register_callbacks_lttng_ust_hip_hipDriverGetVersion_exit(
    void *btx_handle, lttng_ust_hip_hipDriverGetVersion_exit_callback_f *callback);

typedef void lttng_ust_hip_hipRuntimeGetVersion_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *);

void btx_register_callbacks_lttng_ust_hip_hipRuntimeGetVersion_entry(
    void *btx_handle, lttng_ust_hip_hipRuntimeGetVersion_entry_callback_f *callback);

typedef void lttng_ust_hip_hipRuntimeGetVersion_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, int);

void btx_register_callbacks_lttng_ust_hip_hipRuntimeGetVersion_exit(
    void *btx_handle, lttng_ust_hip_hipRuntimeGetVersion_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceGet_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipDevice_t *, int);

void btx_register_callbacks_lttng_ust_hip_hipDeviceGet_entry(
    void *btx_handle, lttng_ust_hip_hipDeviceGet_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceGet_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipDevice_t);

void btx_register_callbacks_lttng_ust_hip_hipDeviceGet_exit(
    void *btx_handle, lttng_ust_hip_hipDeviceGet_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceComputeCapability_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, int *, hipDevice_t);

void btx_register_callbacks_lttng_ust_hip_hipDeviceComputeCapability_entry(
    void *btx_handle, lttng_ust_hip_hipDeviceComputeCapability_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceComputeCapability_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, int, int);

void btx_register_callbacks_lttng_ust_hip_hipDeviceComputeCapability_exit(
    void *btx_handle, lttng_ust_hip_hipDeviceComputeCapability_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceGetName_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, int, hipDevice_t);

void btx_register_callbacks_lttng_ust_hip_hipDeviceGetName_entry(
    void *btx_handle, lttng_ust_hip_hipDeviceGetName_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceGetName_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, char *);

void btx_register_callbacks_lttng_ust_hip_hipDeviceGetName_exit(
    void *btx_handle, lttng_ust_hip_hipDeviceGetName_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceGetUuid_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipUUID *, hipDevice_t);

void btx_register_callbacks_lttng_ust_hip_hipDeviceGetUuid_entry(
    void *btx_handle, lttng_ust_hip_hipDeviceGetUuid_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceGetUuid_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t, hipUUID *);

void btx_register_callbacks_lttng_ust_hip_hipDeviceGetUuid_exit(
    void *btx_handle, lttng_ust_hip_hipDeviceGetUuid_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceGetP2PAttribute_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, hipDeviceP2PAttr, int, int);

void btx_register_callbacks_lttng_ust_hip_hipDeviceGetP2PAttribute_entry(
    void *btx_handle, lttng_ust_hip_hipDeviceGetP2PAttribute_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceGetP2PAttribute_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, int);

void btx_register_callbacks_lttng_ust_hip_hipDeviceGetP2PAttribute_exit(
    void *btx_handle, lttng_ust_hip_hipDeviceGetP2PAttribute_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceGetPCIBusId_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, int, int);

void btx_register_callbacks_lttng_ust_hip_hipDeviceGetPCIBusId_entry(
    void *btx_handle, lttng_ust_hip_hipDeviceGetPCIBusId_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceGetPCIBusId_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, char *);

void btx_register_callbacks_lttng_ust_hip_hipDeviceGetPCIBusId_exit(
    void *btx_handle, lttng_ust_hip_hipDeviceGetPCIBusId_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceGetByPCIBusId_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, char *, char *);

void btx_register_callbacks_lttng_ust_hip_hipDeviceGetByPCIBusId_entry(
    void *btx_handle, lttng_ust_hip_hipDeviceGetByPCIBusId_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceGetByPCIBusId_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, int);

void btx_register_callbacks_lttng_ust_hip_hipDeviceGetByPCIBusId_exit(
    void *btx_handle, lttng_ust_hip_hipDeviceGetByPCIBusId_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceTotalMem_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, size_t *, hipDevice_t);

void btx_register_callbacks_lttng_ust_hip_hipDeviceTotalMem_entry(
    void *btx_handle, lttng_ust_hip_hipDeviceTotalMem_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceTotalMem_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t);

void btx_register_callbacks_lttng_ust_hip_hipDeviceTotalMem_exit(
    void *btx_handle, lttng_ust_hip_hipDeviceTotalMem_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceSynchronize_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_hip_hipDeviceSynchronize_entry(
    void *btx_handle, lttng_ust_hip_hipDeviceSynchronize_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceSynchronize_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipDeviceSynchronize_exit(
    void *btx_handle, lttng_ust_hip_hipDeviceSynchronize_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceReset_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_hip_hipDeviceReset_entry(
    void *btx_handle, lttng_ust_hip_hipDeviceReset_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceReset_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipDeviceReset_exit(
    void *btx_handle, lttng_ust_hip_hipDeviceReset_exit_callback_f *callback);

typedef void lttng_ust_hip_hipSetDevice_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_hip_hipSetDevice_entry(
    void *btx_handle, lttng_ust_hip_hipSetDevice_entry_callback_f *callback);

typedef void lttng_ust_hip_hipSetDevice_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipSetDevice_exit(
    void *btx_handle, lttng_ust_hip_hipSetDevice_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGetDevice_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *);

void btx_register_callbacks_lttng_ust_hip_hipGetDevice_entry(
    void *btx_handle, lttng_ust_hip_hipGetDevice_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGetDevice_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, int);

void btx_register_callbacks_lttng_ust_hip_hipGetDevice_exit(
    void *btx_handle, lttng_ust_hip_hipGetDevice_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGetDeviceCount_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *);

void btx_register_callbacks_lttng_ust_hip_hipGetDeviceCount_entry(
    void *btx_handle, lttng_ust_hip_hipGetDeviceCount_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGetDeviceCount_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, int);

void btx_register_callbacks_lttng_ust_hip_hipGetDeviceCount_exit(
    void *btx_handle, lttng_ust_hip_hipGetDeviceCount_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceGetAttribute_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, hipDeviceAttribute_t, int);

void btx_register_callbacks_lttng_ust_hip_hipDeviceGetAttribute_entry(
    void *btx_handle, lttng_ust_hip_hipDeviceGetAttribute_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceGetAttribute_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, int);

void btx_register_callbacks_lttng_ust_hip_hipDeviceGetAttribute_exit(
    void *btx_handle, lttng_ust_hip_hipDeviceGetAttribute_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceGetDefaultMemPool_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipMemPool_t *, int);

void btx_register_callbacks_lttng_ust_hip_hipDeviceGetDefaultMemPool_entry(
    void *btx_handle, lttng_ust_hip_hipDeviceGetDefaultMemPool_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceGetDefaultMemPool_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipMemPool_t);

void btx_register_callbacks_lttng_ust_hip_hipDeviceGetDefaultMemPool_exit(
    void *btx_handle, lttng_ust_hip_hipDeviceGetDefaultMemPool_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceSetMemPool_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, hipMemPool_t);

void btx_register_callbacks_lttng_ust_hip_hipDeviceSetMemPool_entry(
    void *btx_handle, lttng_ust_hip_hipDeviceSetMemPool_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceSetMemPool_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipDeviceSetMemPool_exit(
    void *btx_handle, lttng_ust_hip_hipDeviceSetMemPool_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceGetMemPool_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipMemPool_t *, int);

void btx_register_callbacks_lttng_ust_hip_hipDeviceGetMemPool_entry(
    void *btx_handle, lttng_ust_hip_hipDeviceGetMemPool_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceGetMemPool_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipMemPool_t);

void btx_register_callbacks_lttng_ust_hip_hipDeviceGetMemPool_exit(
    void *btx_handle, lttng_ust_hip_hipDeviceGetMemPool_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGetDeviceProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipDeviceProp_t *, int);

void btx_register_callbacks_lttng_ust_hip_hipGetDeviceProperties_entry(
    void *btx_handle, lttng_ust_hip_hipGetDeviceProperties_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGetDeviceProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t, hipDeviceProp_t *);

void btx_register_callbacks_lttng_ust_hip_hipGetDeviceProperties_exit(
    void *btx_handle, lttng_ust_hip_hipGetDeviceProperties_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceSetCacheConfig_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipFuncCache_t);

void btx_register_callbacks_lttng_ust_hip_hipDeviceSetCacheConfig_entry(
    void *btx_handle, lttng_ust_hip_hipDeviceSetCacheConfig_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceSetCacheConfig_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipDeviceSetCacheConfig_exit(
    void *btx_handle, lttng_ust_hip_hipDeviceSetCacheConfig_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceGetCacheConfig_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipFuncCache_t *);

void btx_register_callbacks_lttng_ust_hip_hipDeviceGetCacheConfig_entry(
    void *btx_handle, lttng_ust_hip_hipDeviceGetCacheConfig_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceGetCacheConfig_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipFuncCache_t);

void btx_register_callbacks_lttng_ust_hip_hipDeviceGetCacheConfig_exit(
    void *btx_handle, lttng_ust_hip_hipDeviceGetCacheConfig_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceGetLimit_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, size_t *, enum hipLimit_t);

void btx_register_callbacks_lttng_ust_hip_hipDeviceGetLimit_entry(
    void *btx_handle, lttng_ust_hip_hipDeviceGetLimit_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceGetLimit_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t);

void btx_register_callbacks_lttng_ust_hip_hipDeviceGetLimit_exit(
    void *btx_handle, lttng_ust_hip_hipDeviceGetLimit_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceSetLimit_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, enum hipLimit_t, size_t);

void btx_register_callbacks_lttng_ust_hip_hipDeviceSetLimit_entry(
    void *btx_handle, lttng_ust_hip_hipDeviceSetLimit_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceSetLimit_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipDeviceSetLimit_exit(
    void *btx_handle, lttng_ust_hip_hipDeviceSetLimit_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceGetSharedMemConfig_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipSharedMemConfig *);

void btx_register_callbacks_lttng_ust_hip_hipDeviceGetSharedMemConfig_entry(
    void *btx_handle, lttng_ust_hip_hipDeviceGetSharedMemConfig_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceGetSharedMemConfig_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipSharedMemConfig);

void btx_register_callbacks_lttng_ust_hip_hipDeviceGetSharedMemConfig_exit(
    void *btx_handle, lttng_ust_hip_hipDeviceGetSharedMemConfig_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGetDeviceFlags_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, unsigned int *);

void btx_register_callbacks_lttng_ust_hip_hipGetDeviceFlags_entry(
    void *btx_handle, lttng_ust_hip_hipGetDeviceFlags_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGetDeviceFlags_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipGetDeviceFlags_exit(
    void *btx_handle, lttng_ust_hip_hipGetDeviceFlags_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceSetSharedMemConfig_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipSharedMemConfig);

void btx_register_callbacks_lttng_ust_hip_hipDeviceSetSharedMemConfig_entry(
    void *btx_handle, lttng_ust_hip_hipDeviceSetSharedMemConfig_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceSetSharedMemConfig_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipDeviceSetSharedMemConfig_exit(
    void *btx_handle, lttng_ust_hip_hipDeviceSetSharedMemConfig_exit_callback_f *callback);

typedef void lttng_ust_hip_hipSetDeviceFlags_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipSetDeviceFlags_entry(
    void *btx_handle, lttng_ust_hip_hipSetDeviceFlags_entry_callback_f *callback);

typedef void lttng_ust_hip_hipSetDeviceFlags_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipSetDeviceFlags_exit(
    void *btx_handle, lttng_ust_hip_hipSetDeviceFlags_exit_callback_f *callback);

typedef void lttng_ust_hip_hipChooseDevice_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, hipDeviceProp_t *, size_t, hipDeviceProp_t *);

void btx_register_callbacks_lttng_ust_hip_hipChooseDevice_entry(
    void *btx_handle, lttng_ust_hip_hipChooseDevice_entry_callback_f *callback);

typedef void lttng_ust_hip_hipChooseDevice_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, int);

void btx_register_callbacks_lttng_ust_hip_hipChooseDevice_exit(
    void *btx_handle, lttng_ust_hip_hipChooseDevice_exit_callback_f *callback);

typedef void lttng_ust_hip_hipExtGetLinkTypeAndHopCount_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, uint32_t *, uint32_t *);

void btx_register_callbacks_lttng_ust_hip_hipExtGetLinkTypeAndHopCount_entry(
    void *btx_handle, lttng_ust_hip_hipExtGetLinkTypeAndHopCount_entry_callback_f *callback);

typedef void lttng_ust_hip_hipExtGetLinkTypeAndHopCount_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, uint32_t, uint32_t);

void btx_register_callbacks_lttng_ust_hip_hipExtGetLinkTypeAndHopCount_exit(
    void *btx_handle, lttng_ust_hip_hipExtGetLinkTypeAndHopCount_exit_callback_f *callback);

typedef void lttng_ust_hip_hipIpcGetMemHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipIpcMemHandle_t *, void *);

void btx_register_callbacks_lttng_ust_hip_hipIpcGetMemHandle_entry(
    void *btx_handle, lttng_ust_hip_hipIpcGetMemHandle_entry_callback_f *callback);

typedef void lttng_ust_hip_hipIpcGetMemHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t, hipIpcMemHandle_t *);

void btx_register_callbacks_lttng_ust_hip_hipIpcGetMemHandle_exit(
    void *btx_handle, lttng_ust_hip_hipIpcGetMemHandle_exit_callback_f *callback);

typedef void lttng_ust_hip_hipIpcOpenMemHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void **, hipIpcMemHandle_t, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipIpcOpenMemHandle_entry(
    void *btx_handle, lttng_ust_hip_hipIpcOpenMemHandle_entry_callback_f *callback);

typedef void lttng_ust_hip_hipIpcOpenMemHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, void *);

void btx_register_callbacks_lttng_ust_hip_hipIpcOpenMemHandle_exit(
    void *btx_handle, lttng_ust_hip_hipIpcOpenMemHandle_exit_callback_f *callback);

typedef void lttng_ust_hip_hipIpcCloseMemHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *);

void btx_register_callbacks_lttng_ust_hip_hipIpcCloseMemHandle_entry(
    void *btx_handle, lttng_ust_hip_hipIpcCloseMemHandle_entry_callback_f *callback);

typedef void lttng_ust_hip_hipIpcCloseMemHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipIpcCloseMemHandle_exit(
    void *btx_handle, lttng_ust_hip_hipIpcCloseMemHandle_exit_callback_f *callback);

typedef void lttng_ust_hip_hipIpcGetEventHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipIpcEventHandle_t *, hipEvent_t);

void btx_register_callbacks_lttng_ust_hip_hipIpcGetEventHandle_entry(
    void *btx_handle, lttng_ust_hip_hipIpcGetEventHandle_entry_callback_f *callback);

typedef void lttng_ust_hip_hipIpcGetEventHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t, hipIpcEventHandle_t *);

void btx_register_callbacks_lttng_ust_hip_hipIpcGetEventHandle_exit(
    void *btx_handle, lttng_ust_hip_hipIpcGetEventHandle_exit_callback_f *callback);

typedef void lttng_ust_hip_hipIpcOpenEventHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipEvent_t *, hipIpcEventHandle_t);

void btx_register_callbacks_lttng_ust_hip_hipIpcOpenEventHandle_entry(
    void *btx_handle, lttng_ust_hip_hipIpcOpenEventHandle_entry_callback_f *callback);

typedef void lttng_ust_hip_hipIpcOpenEventHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipEvent_t);

void btx_register_callbacks_lttng_ust_hip_hipIpcOpenEventHandle_exit(
    void *btx_handle, lttng_ust_hip_hipIpcOpenEventHandle_exit_callback_f *callback);

typedef void lttng_ust_hip_hipFuncSetAttribute_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, hipFuncAttribute, int);

void btx_register_callbacks_lttng_ust_hip_hipFuncSetAttribute_entry(
    void *btx_handle, lttng_ust_hip_hipFuncSetAttribute_entry_callback_f *callback);

typedef void lttng_ust_hip_hipFuncSetAttribute_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipFuncSetAttribute_exit(
    void *btx_handle, lttng_ust_hip_hipFuncSetAttribute_exit_callback_f *callback);

typedef void lttng_ust_hip_hipFuncSetCacheConfig_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, hipFuncCache_t);

void btx_register_callbacks_lttng_ust_hip_hipFuncSetCacheConfig_entry(
    void *btx_handle, lttng_ust_hip_hipFuncSetCacheConfig_entry_callback_f *callback);

typedef void lttng_ust_hip_hipFuncSetCacheConfig_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipFuncSetCacheConfig_exit(
    void *btx_handle, lttng_ust_hip_hipFuncSetCacheConfig_exit_callback_f *callback);

typedef void lttng_ust_hip_hipFuncSetSharedMemConfig_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, hipSharedMemConfig);

void btx_register_callbacks_lttng_ust_hip_hipFuncSetSharedMemConfig_entry(
    void *btx_handle, lttng_ust_hip_hipFuncSetSharedMemConfig_entry_callback_f *callback);

typedef void lttng_ust_hip_hipFuncSetSharedMemConfig_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipFuncSetSharedMemConfig_exit(
    void *btx_handle, lttng_ust_hip_hipFuncSetSharedMemConfig_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGetLastError_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_hip_hipGetLastError_entry(
    void *btx_handle, lttng_ust_hip_hipGetLastError_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGetLastError_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGetLastError_exit(
    void *btx_handle, lttng_ust_hip_hipGetLastError_exit_callback_f *callback);

typedef void lttng_ust_hip_hipPeekAtLastError_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_hip_hipPeekAtLastError_entry(
    void *btx_handle, lttng_ust_hip_hipPeekAtLastError_entry_callback_f *callback);

typedef void lttng_ust_hip_hipPeekAtLastError_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipPeekAtLastError_exit(
    void *btx_handle, lttng_ust_hip_hipPeekAtLastError_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGetErrorName_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGetErrorName_entry(
    void *btx_handle, lttng_ust_hip_hipGetErrorName_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGetErrorName_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, char *);

void btx_register_callbacks_lttng_ust_hip_hipGetErrorName_exit(
    void *btx_handle, lttng_ust_hip_hipGetErrorName_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGetErrorString_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGetErrorString_entry(
    void *btx_handle, lttng_ust_hip_hipGetErrorString_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGetErrorString_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, char *);

void btx_register_callbacks_lttng_ust_hip_hipGetErrorString_exit(
    void *btx_handle, lttng_ust_hip_hipGetErrorString_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDrvGetErrorName_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, char **);

void btx_register_callbacks_lttng_ust_hip_hipDrvGetErrorName_entry(
    void *btx_handle, lttng_ust_hip_hipDrvGetErrorName_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDrvGetErrorName_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, char *, char *);

void btx_register_callbacks_lttng_ust_hip_hipDrvGetErrorName_exit(
    void *btx_handle, lttng_ust_hip_hipDrvGetErrorName_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDrvGetErrorString_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, char **);

void btx_register_callbacks_lttng_ust_hip_hipDrvGetErrorString_entry(
    void *btx_handle, lttng_ust_hip_hipDrvGetErrorString_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDrvGetErrorString_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, char *, char *);

void btx_register_callbacks_lttng_ust_hip_hipDrvGetErrorString_exit(
    void *btx_handle, lttng_ust_hip_hipDrvGetErrorString_exit_callback_f *callback);

typedef void lttng_ust_hip_hipStreamCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t *);

void btx_register_callbacks_lttng_ust_hip_hipStreamCreate_entry(
    void *btx_handle, lttng_ust_hip_hipStreamCreate_entry_callback_f *callback);

typedef void lttng_ust_hip_hipStreamCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipStreamCreate_exit(
    void *btx_handle, lttng_ust_hip_hipStreamCreate_exit_callback_f *callback);

typedef void lttng_ust_hip_hipStreamCreateWithFlags_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t *, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipStreamCreateWithFlags_entry(
    void *btx_handle, lttng_ust_hip_hipStreamCreateWithFlags_entry_callback_f *callback);

typedef void lttng_ust_hip_hipStreamCreateWithFlags_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipStreamCreateWithFlags_exit(
    void *btx_handle, lttng_ust_hip_hipStreamCreateWithFlags_exit_callback_f *callback);

typedef void lttng_ust_hip_hipStreamCreateWithPriority_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t *, unsigned int, int);

void btx_register_callbacks_lttng_ust_hip_hipStreamCreateWithPriority_entry(
    void *btx_handle, lttng_ust_hip_hipStreamCreateWithPriority_entry_callback_f *callback);

typedef void lttng_ust_hip_hipStreamCreateWithPriority_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipStreamCreateWithPriority_exit(
    void *btx_handle, lttng_ust_hip_hipStreamCreateWithPriority_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceGetStreamPriorityRange_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, int *);

void btx_register_callbacks_lttng_ust_hip_hipDeviceGetStreamPriorityRange_entry(
    void *btx_handle, lttng_ust_hip_hipDeviceGetStreamPriorityRange_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceGetStreamPriorityRange_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, int, int);

void btx_register_callbacks_lttng_ust_hip_hipDeviceGetStreamPriorityRange_exit(
    void *btx_handle, lttng_ust_hip_hipDeviceGetStreamPriorityRange_exit_callback_f *callback);

typedef void lttng_ust_hip_hipStreamDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipStreamDestroy_entry(
    void *btx_handle, lttng_ust_hip_hipStreamDestroy_entry_callback_f *callback);

typedef void lttng_ust_hip_hipStreamDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipStreamDestroy_exit(
    void *btx_handle, lttng_ust_hip_hipStreamDestroy_exit_callback_f *callback);

typedef void lttng_ust_hip_hipStreamQuery_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipStreamQuery_entry(
    void *btx_handle, lttng_ust_hip_hipStreamQuery_entry_callback_f *callback);

typedef void lttng_ust_hip_hipStreamQuery_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipStreamQuery_exit(
    void *btx_handle, lttng_ust_hip_hipStreamQuery_exit_callback_f *callback);

typedef void lttng_ust_hip_hipStreamSynchronize_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipStreamSynchronize_entry(
    void *btx_handle, lttng_ust_hip_hipStreamSynchronize_entry_callback_f *callback);

typedef void lttng_ust_hip_hipStreamSynchronize_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipStreamSynchronize_exit(
    void *btx_handle, lttng_ust_hip_hipStreamSynchronize_exit_callback_f *callback);

typedef void lttng_ust_hip_hipStreamWaitEvent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t, hipEvent_t, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipStreamWaitEvent_entry(
    void *btx_handle, lttng_ust_hip_hipStreamWaitEvent_entry_callback_f *callback);

typedef void lttng_ust_hip_hipStreamWaitEvent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipStreamWaitEvent_exit(
    void *btx_handle, lttng_ust_hip_hipStreamWaitEvent_exit_callback_f *callback);

typedef void lttng_ust_hip_hipStreamGetFlags_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t, unsigned int *);

void btx_register_callbacks_lttng_ust_hip_hipStreamGetFlags_entry(
    void *btx_handle, lttng_ust_hip_hipStreamGetFlags_entry_callback_f *callback);

typedef void lttng_ust_hip_hipStreamGetFlags_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipStreamGetFlags_exit(
    void *btx_handle, lttng_ust_hip_hipStreamGetFlags_exit_callback_f *callback);

typedef void lttng_ust_hip_hipStreamGetPriority_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t, int *);

void btx_register_callbacks_lttng_ust_hip_hipStreamGetPriority_entry(
    void *btx_handle, lttng_ust_hip_hipStreamGetPriority_entry_callback_f *callback);

typedef void lttng_ust_hip_hipStreamGetPriority_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, int);

void btx_register_callbacks_lttng_ust_hip_hipStreamGetPriority_exit(
    void *btx_handle, lttng_ust_hip_hipStreamGetPriority_exit_callback_f *callback);

typedef void lttng_ust_hip_hipExtStreamCreateWithCUMask_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t *, uint32_t, uint32_t *, size_t, uint32_t *);

void btx_register_callbacks_lttng_ust_hip_hipExtStreamCreateWithCUMask_entry(
    void *btx_handle, lttng_ust_hip_hipExtStreamCreateWithCUMask_entry_callback_f *callback);

typedef void lttng_ust_hip_hipExtStreamCreateWithCUMask_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipExtStreamCreateWithCUMask_exit(
    void *btx_handle, lttng_ust_hip_hipExtStreamCreateWithCUMask_exit_callback_f *callback);

typedef void lttng_ust_hip_hipExtStreamGetCUMask_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t, uint32_t, uint32_t *);

void btx_register_callbacks_lttng_ust_hip_hipExtStreamGetCUMask_entry(
    void *btx_handle, lttng_ust_hip_hipExtStreamGetCUMask_entry_callback_f *callback);

typedef void lttng_ust_hip_hipExtStreamGetCUMask_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t, uint32_t *);

void btx_register_callbacks_lttng_ust_hip_hipExtStreamGetCUMask_exit(
    void *btx_handle, lttng_ust_hip_hipExtStreamGetCUMask_exit_callback_f *callback);

typedef void lttng_ust_hip_hipStreamAddCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t, hipStreamCallback_t, void *, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipStreamAddCallback_entry(
    void *btx_handle, lttng_ust_hip_hipStreamAddCallback_entry_callback_f *callback);

typedef void lttng_ust_hip_hipStreamAddCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipStreamAddCallback_exit(
    void *btx_handle, lttng_ust_hip_hipStreamAddCallback_exit_callback_f *callback);

typedef void lttng_ust_hip_hipStreamWaitValue32_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t, void *, uint32_t, unsigned int, uint32_t);

void btx_register_callbacks_lttng_ust_hip_hipStreamWaitValue32_entry(
    void *btx_handle, lttng_ust_hip_hipStreamWaitValue32_entry_callback_f *callback);

typedef void lttng_ust_hip_hipStreamWaitValue32_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipStreamWaitValue32_exit(
    void *btx_handle, lttng_ust_hip_hipStreamWaitValue32_exit_callback_f *callback);

typedef void lttng_ust_hip_hipStreamWaitValue64_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t, void *, uint64_t, unsigned int, uint64_t);

void btx_register_callbacks_lttng_ust_hip_hipStreamWaitValue64_entry(
    void *btx_handle, lttng_ust_hip_hipStreamWaitValue64_entry_callback_f *callback);

typedef void lttng_ust_hip_hipStreamWaitValue64_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipStreamWaitValue64_exit(
    void *btx_handle, lttng_ust_hip_hipStreamWaitValue64_exit_callback_f *callback);

typedef void lttng_ust_hip_hipStreamWriteValue32_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t, void *, uint32_t, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipStreamWriteValue32_entry(
    void *btx_handle, lttng_ust_hip_hipStreamWriteValue32_entry_callback_f *callback);

typedef void lttng_ust_hip_hipStreamWriteValue32_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipStreamWriteValue32_exit(
    void *btx_handle, lttng_ust_hip_hipStreamWriteValue32_exit_callback_f *callback);

typedef void lttng_ust_hip_hipStreamWriteValue64_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t, void *, uint64_t, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipStreamWriteValue64_entry(
    void *btx_handle, lttng_ust_hip_hipStreamWriteValue64_entry_callback_f *callback);

typedef void lttng_ust_hip_hipStreamWriteValue64_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipStreamWriteValue64_exit(
    void *btx_handle, lttng_ust_hip_hipStreamWriteValue64_exit_callback_f *callback);

typedef void lttng_ust_hip_hipEventCreateWithFlags_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipEvent_t *, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipEventCreateWithFlags_entry(
    void *btx_handle, lttng_ust_hip_hipEventCreateWithFlags_entry_callback_f *callback);

typedef void lttng_ust_hip_hipEventCreateWithFlags_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipEvent_t);

void btx_register_callbacks_lttng_ust_hip_hipEventCreateWithFlags_exit(
    void *btx_handle, lttng_ust_hip_hipEventCreateWithFlags_exit_callback_f *callback);

typedef void lttng_ust_hip_hipEventCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipEvent_t *);

void btx_register_callbacks_lttng_ust_hip_hipEventCreate_entry(
    void *btx_handle, lttng_ust_hip_hipEventCreate_entry_callback_f *callback);

typedef void lttng_ust_hip_hipEventCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipEvent_t);

void btx_register_callbacks_lttng_ust_hip_hipEventCreate_exit(
    void *btx_handle, lttng_ust_hip_hipEventCreate_exit_callback_f *callback);

typedef void lttng_ust_hip_hipEventRecord_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipEvent_t, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipEventRecord_entry(
    void *btx_handle, lttng_ust_hip_hipEventRecord_entry_callback_f *callback);

typedef void lttng_ust_hip_hipEventRecord_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipEventRecord_exit(
    void *btx_handle, lttng_ust_hip_hipEventRecord_exit_callback_f *callback);

typedef void lttng_ust_hip_hipEventDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipEvent_t);

void btx_register_callbacks_lttng_ust_hip_hipEventDestroy_entry(
    void *btx_handle, lttng_ust_hip_hipEventDestroy_entry_callback_f *callback);

typedef void lttng_ust_hip_hipEventDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipEventDestroy_exit(
    void *btx_handle, lttng_ust_hip_hipEventDestroy_exit_callback_f *callback);

typedef void lttng_ust_hip_hipEventSynchronize_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipEvent_t);

void btx_register_callbacks_lttng_ust_hip_hipEventSynchronize_entry(
    void *btx_handle, lttng_ust_hip_hipEventSynchronize_entry_callback_f *callback);

typedef void lttng_ust_hip_hipEventSynchronize_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipEventSynchronize_exit(
    void *btx_handle, lttng_ust_hip_hipEventSynchronize_exit_callback_f *callback);

typedef void lttng_ust_hip_hipEventElapsedTime_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, float *, hipEvent_t, hipEvent_t);

void btx_register_callbacks_lttng_ust_hip_hipEventElapsedTime_entry(
    void *btx_handle, lttng_ust_hip_hipEventElapsedTime_entry_callback_f *callback);

typedef void lttng_ust_hip_hipEventElapsedTime_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, float);

void btx_register_callbacks_lttng_ust_hip_hipEventElapsedTime_exit(
    void *btx_handle, lttng_ust_hip_hipEventElapsedTime_exit_callback_f *callback);

typedef void lttng_ust_hip_hipEventQuery_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipEvent_t);

void btx_register_callbacks_lttng_ust_hip_hipEventQuery_entry(
    void *btx_handle, lttng_ust_hip_hipEventQuery_entry_callback_f *callback);

typedef void lttng_ust_hip_hipEventQuery_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipEventQuery_exit(
    void *btx_handle, lttng_ust_hip_hipEventQuery_exit_callback_f *callback);

typedef void lttng_ust_hip_hipPointerGetAttributes_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipPointerAttribute_t *, void *);

void btx_register_callbacks_lttng_ust_hip_hipPointerGetAttributes_entry(
    void *btx_handle, lttng_ust_hip_hipPointerGetAttributes_entry_callback_f *callback);

typedef void lttng_ust_hip_hipPointerGetAttributes_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t, hipPointerAttribute_t *);

void btx_register_callbacks_lttng_ust_hip_hipPointerGetAttributes_exit(
    void *btx_handle, lttng_ust_hip_hipPointerGetAttributes_exit_callback_f *callback);

typedef void lttng_ust_hip_hipPointerGetAttribute_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, hipPointer_attribute, hipDeviceptr_t);

void btx_register_callbacks_lttng_ust_hip_hipPointerGetAttribute_entry(
    void *btx_handle, lttng_ust_hip_hipPointerGetAttribute_entry_callback_f *callback);

typedef void lttng_ust_hip_hipPointerGetAttribute_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t, void *);

void btx_register_callbacks_lttng_ust_hip_hipPointerGetAttribute_exit(
    void *btx_handle, lttng_ust_hip_hipPointerGetAttribute_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDrvPointerGetAttributes_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, unsigned int, hipPointer_attribute *, void **, hipDeviceptr_t);

void btx_register_callbacks_lttng_ust_hip_hipDrvPointerGetAttributes_entry(
    void *btx_handle, lttng_ust_hip_hipDrvPointerGetAttributes_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDrvPointerGetAttributes_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipDrvPointerGetAttributes_exit(
    void *btx_handle, lttng_ust_hip_hipDrvPointerGetAttributes_exit_callback_f *callback);

typedef void lttng_ust_hip_hipImportExternalSemaphore_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipExternalSemaphore_t *, hipExternalSemaphoreHandleDesc *, size_t, hipExternalSemaphoreHandleDesc *);

void btx_register_callbacks_lttng_ust_hip_hipImportExternalSemaphore_entry(
    void *btx_handle, lttng_ust_hip_hipImportExternalSemaphore_entry_callback_f *callback);

typedef void lttng_ust_hip_hipImportExternalSemaphore_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipExternalSemaphore_t);

void btx_register_callbacks_lttng_ust_hip_hipImportExternalSemaphore_exit(
    void *btx_handle, lttng_ust_hip_hipImportExternalSemaphore_exit_callback_f *callback);

typedef void lttng_ust_hip_hipSignalExternalSemaphoresAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipExternalSemaphore_t *, hipExternalSemaphoreSignalParams *, unsigned int, hipStream_t, size_t, hipExternalSemaphore_t *, size_t, hipExternalSemaphoreSignalParams *);

void btx_register_callbacks_lttng_ust_hip_hipSignalExternalSemaphoresAsync_entry(
    void *btx_handle, lttng_ust_hip_hipSignalExternalSemaphoresAsync_entry_callback_f *callback);

typedef void lttng_ust_hip_hipSignalExternalSemaphoresAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipSignalExternalSemaphoresAsync_exit(
    void *btx_handle, lttng_ust_hip_hipSignalExternalSemaphoresAsync_exit_callback_f *callback);

typedef void lttng_ust_hip_hipWaitExternalSemaphoresAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipExternalSemaphore_t *, hipExternalSemaphoreWaitParams *, unsigned int, hipStream_t, size_t, hipExternalSemaphore_t *, size_t, hipExternalSemaphoreWaitParams *);

void btx_register_callbacks_lttng_ust_hip_hipWaitExternalSemaphoresAsync_entry(
    void *btx_handle, lttng_ust_hip_hipWaitExternalSemaphoresAsync_entry_callback_f *callback);

typedef void lttng_ust_hip_hipWaitExternalSemaphoresAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipWaitExternalSemaphoresAsync_exit(
    void *btx_handle, lttng_ust_hip_hipWaitExternalSemaphoresAsync_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDestroyExternalSemaphore_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipExternalSemaphore_t);

void btx_register_callbacks_lttng_ust_hip_hipDestroyExternalSemaphore_entry(
    void *btx_handle, lttng_ust_hip_hipDestroyExternalSemaphore_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDestroyExternalSemaphore_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipDestroyExternalSemaphore_exit(
    void *btx_handle, lttng_ust_hip_hipDestroyExternalSemaphore_exit_callback_f *callback);

typedef void lttng_ust_hip_hipImportExternalMemory_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipExternalMemory_t *, hipExternalMemoryHandleDesc *, size_t, hipExternalMemoryHandleDesc *);

void btx_register_callbacks_lttng_ust_hip_hipImportExternalMemory_entry(
    void *btx_handle, lttng_ust_hip_hipImportExternalMemory_entry_callback_f *callback);

typedef void lttng_ust_hip_hipImportExternalMemory_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipExternalMemory_t);

void btx_register_callbacks_lttng_ust_hip_hipImportExternalMemory_exit(
    void *btx_handle, lttng_ust_hip_hipImportExternalMemory_exit_callback_f *callback);

typedef void lttng_ust_hip_hipExternalMemoryGetMappedBuffer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void **, hipExternalMemory_t, hipExternalMemoryBufferDesc *, size_t, hipExternalMemoryBufferDesc *);

void btx_register_callbacks_lttng_ust_hip_hipExternalMemoryGetMappedBuffer_entry(
    void *btx_handle, lttng_ust_hip_hipExternalMemoryGetMappedBuffer_entry_callback_f *callback);

typedef void lttng_ust_hip_hipExternalMemoryGetMappedBuffer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, void *);

void btx_register_callbacks_lttng_ust_hip_hipExternalMemoryGetMappedBuffer_exit(
    void *btx_handle, lttng_ust_hip_hipExternalMemoryGetMappedBuffer_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDestroyExternalMemory_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipExternalMemory_t);

void btx_register_callbacks_lttng_ust_hip_hipDestroyExternalMemory_entry(
    void *btx_handle, lttng_ust_hip_hipDestroyExternalMemory_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDestroyExternalMemory_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipDestroyExternalMemory_exit(
    void *btx_handle, lttng_ust_hip_hipDestroyExternalMemory_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMalloc_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void **, size_t);

void btx_register_callbacks_lttng_ust_hip_hipMalloc_entry(
    void *btx_handle, lttng_ust_hip_hipMalloc_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMalloc_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, void *);

void btx_register_callbacks_lttng_ust_hip_hipMalloc_exit(
    void *btx_handle, lttng_ust_hip_hipMalloc_exit_callback_f *callback);

typedef void lttng_ust_hip_hipExtMallocWithFlags_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void **, size_t, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipExtMallocWithFlags_entry(
    void *btx_handle, lttng_ust_hip_hipExtMallocWithFlags_entry_callback_f *callback);

typedef void lttng_ust_hip_hipExtMallocWithFlags_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, void *);

void btx_register_callbacks_lttng_ust_hip_hipExtMallocWithFlags_exit(
    void *btx_handle, lttng_ust_hip_hipExtMallocWithFlags_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMallocHost_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void **, size_t);

void btx_register_callbacks_lttng_ust_hip_hipMallocHost_entry(
    void *btx_handle, lttng_ust_hip_hipMallocHost_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMallocHost_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, void *);

void btx_register_callbacks_lttng_ust_hip_hipMallocHost_exit(
    void *btx_handle, lttng_ust_hip_hipMallocHost_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemAllocHost_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void **, size_t);

void btx_register_callbacks_lttng_ust_hip_hipMemAllocHost_entry(
    void *btx_handle, lttng_ust_hip_hipMemAllocHost_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemAllocHost_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, void *);

void btx_register_callbacks_lttng_ust_hip_hipMemAllocHost_exit(
    void *btx_handle, lttng_ust_hip_hipMemAllocHost_exit_callback_f *callback);

typedef void lttng_ust_hip_hipHostMalloc_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void **, size_t, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipHostMalloc_entry(
    void *btx_handle, lttng_ust_hip_hipHostMalloc_entry_callback_f *callback);

typedef void lttng_ust_hip_hipHostMalloc_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, void *);

void btx_register_callbacks_lttng_ust_hip_hipHostMalloc_exit(
    void *btx_handle, lttng_ust_hip_hipHostMalloc_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMallocManaged_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void **, size_t, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipMallocManaged_entry(
    void *btx_handle, lttng_ust_hip_hipMallocManaged_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMallocManaged_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, void *);

void btx_register_callbacks_lttng_ust_hip_hipMallocManaged_exit(
    void *btx_handle, lttng_ust_hip_hipMallocManaged_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemPrefetchAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, size_t, int, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipMemPrefetchAsync_entry(
    void *btx_handle, lttng_ust_hip_hipMemPrefetchAsync_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemPrefetchAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemPrefetchAsync_exit(
    void *btx_handle, lttng_ust_hip_hipMemPrefetchAsync_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemAdvise_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, size_t, hipMemoryAdvise, int);

void btx_register_callbacks_lttng_ust_hip_hipMemAdvise_entry(
    void *btx_handle, lttng_ust_hip_hipMemAdvise_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemAdvise_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemAdvise_exit(
    void *btx_handle, lttng_ust_hip_hipMemAdvise_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemRangeGetAttribute_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, size_t, hipMemRangeAttribute, void *, size_t);

void btx_register_callbacks_lttng_ust_hip_hipMemRangeGetAttribute_entry(
    void *btx_handle, lttng_ust_hip_hipMemRangeGetAttribute_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemRangeGetAttribute_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t, void *);

void btx_register_callbacks_lttng_ust_hip_hipMemRangeGetAttribute_exit(
    void *btx_handle, lttng_ust_hip_hipMemRangeGetAttribute_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemRangeGetAttributes_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void **, size_t *, hipMemRangeAttribute *, size_t, void *, size_t, size_t, hipMemRangeAttribute *, size_t, size_t *);

void btx_register_callbacks_lttng_ust_hip_hipMemRangeGetAttributes_entry(
    void *btx_handle, lttng_ust_hip_hipMemRangeGetAttributes_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemRangeGetAttributes_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemRangeGetAttributes_exit(
    void *btx_handle, lttng_ust_hip_hipMemRangeGetAttributes_exit_callback_f *callback);

typedef void lttng_ust_hip_hipStreamAttachMemAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t, void *, size_t, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipStreamAttachMemAsync_entry(
    void *btx_handle, lttng_ust_hip_hipStreamAttachMemAsync_entry_callback_f *callback);

typedef void lttng_ust_hip_hipStreamAttachMemAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipStreamAttachMemAsync_exit(
    void *btx_handle, lttng_ust_hip_hipStreamAttachMemAsync_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMallocAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void **, size_t, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipMallocAsync_entry(
    void *btx_handle, lttng_ust_hip_hipMallocAsync_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMallocAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, void *);

void btx_register_callbacks_lttng_ust_hip_hipMallocAsync_exit(
    void *btx_handle, lttng_ust_hip_hipMallocAsync_exit_callback_f *callback);

typedef void lttng_ust_hip_hipFreeAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipFreeAsync_entry(
    void *btx_handle, lttng_ust_hip_hipFreeAsync_entry_callback_f *callback);

typedef void lttng_ust_hip_hipFreeAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipFreeAsync_exit(
    void *btx_handle, lttng_ust_hip_hipFreeAsync_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemPoolTrimTo_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipMemPool_t, size_t);

void btx_register_callbacks_lttng_ust_hip_hipMemPoolTrimTo_entry(
    void *btx_handle, lttng_ust_hip_hipMemPoolTrimTo_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemPoolTrimTo_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemPoolTrimTo_exit(
    void *btx_handle, lttng_ust_hip_hipMemPoolTrimTo_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemPoolSetAttribute_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipMemPool_t, hipMemPoolAttr, void *, size_t, void *);

void btx_register_callbacks_lttng_ust_hip_hipMemPoolSetAttribute_entry(
    void *btx_handle, lttng_ust_hip_hipMemPoolSetAttribute_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemPoolSetAttribute_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemPoolSetAttribute_exit(
    void *btx_handle, lttng_ust_hip_hipMemPoolSetAttribute_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemPoolGetAttribute_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipMemPool_t, hipMemPoolAttr, void *);

void btx_register_callbacks_lttng_ust_hip_hipMemPoolGetAttribute_entry(
    void *btx_handle, lttng_ust_hip_hipMemPoolGetAttribute_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemPoolGetAttribute_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t, void *);

void btx_register_callbacks_lttng_ust_hip_hipMemPoolGetAttribute_exit(
    void *btx_handle, lttng_ust_hip_hipMemPoolGetAttribute_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemPoolSetAccess_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipMemPool_t, hipMemAccessDesc *, size_t, size_t, hipMemAccessDesc *);

void btx_register_callbacks_lttng_ust_hip_hipMemPoolSetAccess_entry(
    void *btx_handle, lttng_ust_hip_hipMemPoolSetAccess_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemPoolSetAccess_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemPoolSetAccess_exit(
    void *btx_handle, lttng_ust_hip_hipMemPoolSetAccess_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemPoolGetAccess_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipMemAccessFlags *, hipMemPool_t, hipMemLocation *, size_t, hipMemLocation *);

void btx_register_callbacks_lttng_ust_hip_hipMemPoolGetAccess_entry(
    void *btx_handle, lttng_ust_hip_hipMemPoolGetAccess_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemPoolGetAccess_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipMemAccessFlags);

void btx_register_callbacks_lttng_ust_hip_hipMemPoolGetAccess_exit(
    void *btx_handle, lttng_ust_hip_hipMemPoolGetAccess_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemPoolCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipMemPool_t *, hipMemPoolProps *, size_t, hipMemPoolProps *);

void btx_register_callbacks_lttng_ust_hip_hipMemPoolCreate_entry(
    void *btx_handle, lttng_ust_hip_hipMemPoolCreate_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemPoolCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipMemPool_t);

void btx_register_callbacks_lttng_ust_hip_hipMemPoolCreate_exit(
    void *btx_handle, lttng_ust_hip_hipMemPoolCreate_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemPoolDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipMemPool_t);

void btx_register_callbacks_lttng_ust_hip_hipMemPoolDestroy_entry(
    void *btx_handle, lttng_ust_hip_hipMemPoolDestroy_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemPoolDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemPoolDestroy_exit(
    void *btx_handle, lttng_ust_hip_hipMemPoolDestroy_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMallocFromPoolAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void **, size_t, hipMemPool_t, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipMallocFromPoolAsync_entry(
    void *btx_handle, lttng_ust_hip_hipMallocFromPoolAsync_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMallocFromPoolAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, void *);

void btx_register_callbacks_lttng_ust_hip_hipMallocFromPoolAsync_exit(
    void *btx_handle, lttng_ust_hip_hipMallocFromPoolAsync_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemPoolExportToShareableHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, hipMemPool_t, hipMemAllocationHandleType, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipMemPoolExportToShareableHandle_entry(
    void *btx_handle, lttng_ust_hip_hipMemPoolExportToShareableHandle_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemPoolExportToShareableHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t, void *);

void btx_register_callbacks_lttng_ust_hip_hipMemPoolExportToShareableHandle_exit(
    void *btx_handle, lttng_ust_hip_hipMemPoolExportToShareableHandle_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemPoolImportFromShareableHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipMemPool_t *, void *, hipMemAllocationHandleType, unsigned int, size_t, void *);

void btx_register_callbacks_lttng_ust_hip_hipMemPoolImportFromShareableHandle_entry(
    void *btx_handle, lttng_ust_hip_hipMemPoolImportFromShareableHandle_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemPoolImportFromShareableHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipMemPool_t);

void btx_register_callbacks_lttng_ust_hip_hipMemPoolImportFromShareableHandle_exit(
    void *btx_handle, lttng_ust_hip_hipMemPoolImportFromShareableHandle_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemPoolExportPointer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipMemPoolPtrExportData *, void *);

void btx_register_callbacks_lttng_ust_hip_hipMemPoolExportPointer_entry(
    void *btx_handle, lttng_ust_hip_hipMemPoolExportPointer_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemPoolExportPointer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t, hipMemPoolPtrExportData *);

void btx_register_callbacks_lttng_ust_hip_hipMemPoolExportPointer_exit(
    void *btx_handle, lttng_ust_hip_hipMemPoolExportPointer_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemPoolImportPointer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void **, hipMemPool_t, hipMemPoolPtrExportData *, size_t, hipMemPoolPtrExportData *);

void btx_register_callbacks_lttng_ust_hip_hipMemPoolImportPointer_entry(
    void *btx_handle, lttng_ust_hip_hipMemPoolImportPointer_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemPoolImportPointer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, void *);

void btx_register_callbacks_lttng_ust_hip_hipMemPoolImportPointer_exit(
    void *btx_handle, lttng_ust_hip_hipMemPoolImportPointer_exit_callback_f *callback);

typedef void lttng_ust_hip_hipHostAlloc_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void **, size_t, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipHostAlloc_entry(
    void *btx_handle, lttng_ust_hip_hipHostAlloc_entry_callback_f *callback);

typedef void lttng_ust_hip_hipHostAlloc_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, void *);

void btx_register_callbacks_lttng_ust_hip_hipHostAlloc_exit(
    void *btx_handle, lttng_ust_hip_hipHostAlloc_exit_callback_f *callback);

typedef void lttng_ust_hip_hipHostGetDevicePointer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void **, void *, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipHostGetDevicePointer_entry(
    void *btx_handle, lttng_ust_hip_hipHostGetDevicePointer_entry_callback_f *callback);

typedef void lttng_ust_hip_hipHostGetDevicePointer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, void *);

void btx_register_callbacks_lttng_ust_hip_hipHostGetDevicePointer_exit(
    void *btx_handle, lttng_ust_hip_hipHostGetDevicePointer_exit_callback_f *callback);

typedef void lttng_ust_hip_hipHostGetFlags_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, unsigned int *, void *);

void btx_register_callbacks_lttng_ust_hip_hipHostGetFlags_entry(
    void *btx_handle, lttng_ust_hip_hipHostGetFlags_entry_callback_f *callback);

typedef void lttng_ust_hip_hipHostGetFlags_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipHostGetFlags_exit(
    void *btx_handle, lttng_ust_hip_hipHostGetFlags_exit_callback_f *callback);

typedef void lttng_ust_hip_hipHostRegister_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, size_t, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipHostRegister_entry(
    void *btx_handle, lttng_ust_hip_hipHostRegister_entry_callback_f *callback);

typedef void lttng_ust_hip_hipHostRegister_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipHostRegister_exit(
    void *btx_handle, lttng_ust_hip_hipHostRegister_exit_callback_f *callback);

typedef void lttng_ust_hip_hipHostUnregister_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *);

void btx_register_callbacks_lttng_ust_hip_hipHostUnregister_entry(
    void *btx_handle, lttng_ust_hip_hipHostUnregister_entry_callback_f *callback);

typedef void lttng_ust_hip_hipHostUnregister_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipHostUnregister_exit(
    void *btx_handle, lttng_ust_hip_hipHostUnregister_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMallocPitch_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void **, size_t *, size_t, size_t);

void btx_register_callbacks_lttng_ust_hip_hipMallocPitch_entry(
    void *btx_handle, lttng_ust_hip_hipMallocPitch_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMallocPitch_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, void *, size_t);

void btx_register_callbacks_lttng_ust_hip_hipMallocPitch_exit(
    void *btx_handle, lttng_ust_hip_hipMallocPitch_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemAllocPitch_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipDeviceptr_t *, size_t *, size_t, size_t, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipMemAllocPitch_entry(
    void *btx_handle, lttng_ust_hip_hipMemAllocPitch_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemAllocPitch_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipDeviceptr_t, size_t);

void btx_register_callbacks_lttng_ust_hip_hipMemAllocPitch_exit(
    void *btx_handle, lttng_ust_hip_hipMemAllocPitch_exit_callback_f *callback);

typedef void lttng_ust_hip_hipFree_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *);

void btx_register_callbacks_lttng_ust_hip_hipFree_entry(
    void *btx_handle, lttng_ust_hip_hipFree_entry_callback_f *callback);

typedef void lttng_ust_hip_hipFree_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipFree_exit(
    void *btx_handle, lttng_ust_hip_hipFree_exit_callback_f *callback);

typedef void lttng_ust_hip_hipFreeHost_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *);

void btx_register_callbacks_lttng_ust_hip_hipFreeHost_entry(
    void *btx_handle, lttng_ust_hip_hipFreeHost_entry_callback_f *callback);

typedef void lttng_ust_hip_hipFreeHost_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipFreeHost_exit(
    void *btx_handle, lttng_ust_hip_hipFreeHost_exit_callback_f *callback);

typedef void lttng_ust_hip_hipHostFree_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *);

void btx_register_callbacks_lttng_ust_hip_hipHostFree_entry(
    void *btx_handle, lttng_ust_hip_hipHostFree_entry_callback_f *callback);

typedef void lttng_ust_hip_hipHostFree_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipHostFree_exit(
    void *btx_handle, lttng_ust_hip_hipHostFree_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, size_t, hipMemcpyKind);

void btx_register_callbacks_lttng_ust_hip_hipMemcpy_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpy_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpy_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpy_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyWithStream_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, size_t, hipMemcpyKind, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyWithStream_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpyWithStream_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyWithStream_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyWithStream_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpyWithStream_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyHtoD_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipDeviceptr_t, void *, size_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyHtoD_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpyHtoD_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyHtoD_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyHtoD_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpyHtoD_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyDtoH_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, hipDeviceptr_t, size_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyDtoH_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpyDtoH_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyDtoH_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyDtoH_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpyDtoH_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyDtoD_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipDeviceptr_t, hipDeviceptr_t, size_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyDtoD_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpyDtoD_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyDtoD_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyDtoD_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpyDtoD_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyHtoDAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipDeviceptr_t, void *, size_t, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyHtoDAsync_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpyHtoDAsync_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyHtoDAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyHtoDAsync_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpyHtoDAsync_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyDtoHAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, hipDeviceptr_t, size_t, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyDtoHAsync_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpyDtoHAsync_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyDtoHAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyDtoHAsync_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpyDtoHAsync_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyDtoDAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipDeviceptr_t, hipDeviceptr_t, size_t, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyDtoDAsync_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpyDtoDAsync_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyDtoDAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyDtoDAsync_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpyDtoDAsync_exit_callback_f *callback);

typedef void lttng_ust_hip_hipModuleGetGlobal_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipDeviceptr_t *, size_t *, hipModule_t, char *, char *);

void btx_register_callbacks_lttng_ust_hip_hipModuleGetGlobal_entry(
    void *btx_handle, lttng_ust_hip_hipModuleGetGlobal_entry_callback_f *callback);

typedef void lttng_ust_hip_hipModuleGetGlobal_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipDeviceptr_t, size_t);

void btx_register_callbacks_lttng_ust_hip_hipModuleGetGlobal_exit(
    void *btx_handle, lttng_ust_hip_hipModuleGetGlobal_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGetSymbolAddress_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void **, void *);

void btx_register_callbacks_lttng_ust_hip_hipGetSymbolAddress_entry(
    void *btx_handle, lttng_ust_hip_hipGetSymbolAddress_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGetSymbolAddress_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, void *);

void btx_register_callbacks_lttng_ust_hip_hipGetSymbolAddress_exit(
    void *btx_handle, lttng_ust_hip_hipGetSymbolAddress_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGetSymbolSize_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, size_t *, void *);

void btx_register_callbacks_lttng_ust_hip_hipGetSymbolSize_entry(
    void *btx_handle, lttng_ust_hip_hipGetSymbolSize_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGetSymbolSize_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t);

void btx_register_callbacks_lttng_ust_hip_hipGetSymbolSize_exit(
    void *btx_handle, lttng_ust_hip_hipGetSymbolSize_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyToSymbol_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, size_t, size_t, hipMemcpyKind);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyToSymbol_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpyToSymbol_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyToSymbol_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyToSymbol_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpyToSymbol_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyToSymbolAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, size_t, size_t, hipMemcpyKind, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyToSymbolAsync_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpyToSymbolAsync_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyToSymbolAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyToSymbolAsync_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpyToSymbolAsync_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyFromSymbol_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, size_t, size_t, hipMemcpyKind);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyFromSymbol_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpyFromSymbol_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyFromSymbol_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyFromSymbol_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpyFromSymbol_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyFromSymbolAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, size_t, size_t, hipMemcpyKind, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyFromSymbolAsync_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpyFromSymbolAsync_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyFromSymbolAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyFromSymbolAsync_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpyFromSymbolAsync_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, size_t, hipMemcpyKind, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyAsync_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpyAsync_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyAsync_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpyAsync_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemset_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, size_t);

void btx_register_callbacks_lttng_ust_hip_hipMemset_entry(
    void *btx_handle, lttng_ust_hip_hipMemset_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemset_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemset_exit(
    void *btx_handle, lttng_ust_hip_hipMemset_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemsetD8_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipDeviceptr_t, unsigned char, size_t);

void btx_register_callbacks_lttng_ust_hip_hipMemsetD8_entry(
    void *btx_handle, lttng_ust_hip_hipMemsetD8_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemsetD8_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemsetD8_exit(
    void *btx_handle, lttng_ust_hip_hipMemsetD8_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemsetD8Async_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipDeviceptr_t, unsigned char, size_t, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipMemsetD8Async_entry(
    void *btx_handle, lttng_ust_hip_hipMemsetD8Async_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemsetD8Async_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemsetD8Async_exit(
    void *btx_handle, lttng_ust_hip_hipMemsetD8Async_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemsetD16_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipDeviceptr_t, unsigned short int, size_t);

void btx_register_callbacks_lttng_ust_hip_hipMemsetD16_entry(
    void *btx_handle, lttng_ust_hip_hipMemsetD16_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemsetD16_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemsetD16_exit(
    void *btx_handle, lttng_ust_hip_hipMemsetD16_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemsetD16Async_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipDeviceptr_t, unsigned short int, size_t, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipMemsetD16Async_entry(
    void *btx_handle, lttng_ust_hip_hipMemsetD16Async_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemsetD16Async_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemsetD16Async_exit(
    void *btx_handle, lttng_ust_hip_hipMemsetD16Async_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemsetD32_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipDeviceptr_t, int, size_t);

void btx_register_callbacks_lttng_ust_hip_hipMemsetD32_entry(
    void *btx_handle, lttng_ust_hip_hipMemsetD32_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemsetD32_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemsetD32_exit(
    void *btx_handle, lttng_ust_hip_hipMemsetD32_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemsetAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, size_t, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipMemsetAsync_entry(
    void *btx_handle, lttng_ust_hip_hipMemsetAsync_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemsetAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemsetAsync_exit(
    void *btx_handle, lttng_ust_hip_hipMemsetAsync_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemsetD32Async_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipDeviceptr_t, int, size_t, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipMemsetD32Async_entry(
    void *btx_handle, lttng_ust_hip_hipMemsetD32Async_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemsetD32Async_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemsetD32Async_exit(
    void *btx_handle, lttng_ust_hip_hipMemsetD32Async_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemset2D_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, size_t, int, size_t, size_t);

void btx_register_callbacks_lttng_ust_hip_hipMemset2D_entry(
    void *btx_handle, lttng_ust_hip_hipMemset2D_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemset2D_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemset2D_exit(
    void *btx_handle, lttng_ust_hip_hipMemset2D_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemset2DAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, size_t, int, size_t, size_t, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipMemset2DAsync_entry(
    void *btx_handle, lttng_ust_hip_hipMemset2DAsync_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemset2DAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemset2DAsync_exit(
    void *btx_handle, lttng_ust_hip_hipMemset2DAsync_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemset3D_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipPitchedPtr, int, hipExtent);

void btx_register_callbacks_lttng_ust_hip_hipMemset3D_entry(
    void *btx_handle, lttng_ust_hip_hipMemset3D_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemset3D_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemset3D_exit(
    void *btx_handle, lttng_ust_hip_hipMemset3D_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemset3DAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipPitchedPtr, int, hipExtent, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipMemset3DAsync_entry(
    void *btx_handle, lttng_ust_hip_hipMemset3DAsync_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemset3DAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemset3DAsync_exit(
    void *btx_handle, lttng_ust_hip_hipMemset3DAsync_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemGetInfo_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, size_t *, size_t *);

void btx_register_callbacks_lttng_ust_hip_hipMemGetInfo_entry(
    void *btx_handle, lttng_ust_hip_hipMemGetInfo_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemGetInfo_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t, size_t);

void btx_register_callbacks_lttng_ust_hip_hipMemGetInfo_exit(
    void *btx_handle, lttng_ust_hip_hipMemGetInfo_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemPtrGetInfo_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, size_t *);

void btx_register_callbacks_lttng_ust_hip_hipMemPtrGetInfo_entry(
    void *btx_handle, lttng_ust_hip_hipMemPtrGetInfo_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemPtrGetInfo_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t);

void btx_register_callbacks_lttng_ust_hip_hipMemPtrGetInfo_exit(
    void *btx_handle, lttng_ust_hip_hipMemPtrGetInfo_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMallocArray_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipArray **, hipChannelFormatDesc *, size_t, size_t, unsigned int, size_t, hipChannelFormatDesc *);

void btx_register_callbacks_lttng_ust_hip_hipMallocArray_entry(
    void *btx_handle, lttng_ust_hip_hipMallocArray_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMallocArray_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipArray *);

void btx_register_callbacks_lttng_ust_hip_hipMallocArray_exit(
    void *btx_handle, lttng_ust_hip_hipMallocArray_exit_callback_f *callback);

typedef void lttng_ust_hip_hipArrayCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipArray **, HIP_ARRAY_DESCRIPTOR *, size_t, HIP_ARRAY_DESCRIPTOR *);

void btx_register_callbacks_lttng_ust_hip_hipArrayCreate_entry(
    void *btx_handle, lttng_ust_hip_hipArrayCreate_entry_callback_f *callback);

typedef void lttng_ust_hip_hipArrayCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipArray *);

void btx_register_callbacks_lttng_ust_hip_hipArrayCreate_exit(
    void *btx_handle, lttng_ust_hip_hipArrayCreate_exit_callback_f *callback);

typedef void lttng_ust_hip_hipArrayDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipArray *);

void btx_register_callbacks_lttng_ust_hip_hipArrayDestroy_entry(
    void *btx_handle, lttng_ust_hip_hipArrayDestroy_entry_callback_f *callback);

typedef void lttng_ust_hip_hipArrayDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipArrayDestroy_exit(
    void *btx_handle, lttng_ust_hip_hipArrayDestroy_exit_callback_f *callback);

typedef void lttng_ust_hip_hipArray3DCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipArray **, HIP_ARRAY3D_DESCRIPTOR *);

void btx_register_callbacks_lttng_ust_hip_hipArray3DCreate_entry(
    void *btx_handle, lttng_ust_hip_hipArray3DCreate_entry_callback_f *callback);

typedef void lttng_ust_hip_hipArray3DCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipArray3DCreate_exit(
    void *btx_handle, lttng_ust_hip_hipArray3DCreate_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMalloc3D_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipPitchedPtr *, hipExtent);

void btx_register_callbacks_lttng_ust_hip_hipMalloc3D_entry(
    void *btx_handle, lttng_ust_hip_hipMalloc3D_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMalloc3D_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t, hipPitchedPtr *);

void btx_register_callbacks_lttng_ust_hip_hipMalloc3D_exit(
    void *btx_handle, lttng_ust_hip_hipMalloc3D_exit_callback_f *callback);

typedef void lttng_ust_hip_hipFreeArray_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipArray *);

void btx_register_callbacks_lttng_ust_hip_hipFreeArray_entry(
    void *btx_handle, lttng_ust_hip_hipFreeArray_entry_callback_f *callback);

typedef void lttng_ust_hip_hipFreeArray_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipFreeArray_exit(
    void *btx_handle, lttng_ust_hip_hipFreeArray_exit_callback_f *callback);

typedef void lttng_ust_hip_hipFreeMipmappedArray_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipMipmappedArray_t);

void btx_register_callbacks_lttng_ust_hip_hipFreeMipmappedArray_entry(
    void *btx_handle, lttng_ust_hip_hipFreeMipmappedArray_entry_callback_f *callback);

typedef void lttng_ust_hip_hipFreeMipmappedArray_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipFreeMipmappedArray_exit(
    void *btx_handle, lttng_ust_hip_hipFreeMipmappedArray_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMalloc3DArray_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipArray **, struct hipChannelFormatDesc *, struct hipExtent, unsigned int, size_t, struct hipChannelFormatDesc *);

void btx_register_callbacks_lttng_ust_hip_hipMalloc3DArray_entry(
    void *btx_handle, lttng_ust_hip_hipMalloc3DArray_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMalloc3DArray_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipArray *);

void btx_register_callbacks_lttng_ust_hip_hipMalloc3DArray_exit(
    void *btx_handle, lttng_ust_hip_hipMalloc3DArray_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMallocMipmappedArray_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipMipmappedArray_t *, struct hipChannelFormatDesc *, struct hipExtent, unsigned int, unsigned int, size_t, struct hipChannelFormatDesc *);

void btx_register_callbacks_lttng_ust_hip_hipMallocMipmappedArray_entry(
    void *btx_handle, lttng_ust_hip_hipMallocMipmappedArray_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMallocMipmappedArray_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipMipmappedArray_t);

void btx_register_callbacks_lttng_ust_hip_hipMallocMipmappedArray_exit(
    void *btx_handle, lttng_ust_hip_hipMallocMipmappedArray_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGetMipmappedArrayLevel_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipArray_t *, hipMipmappedArray_const_t, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipGetMipmappedArrayLevel_entry(
    void *btx_handle, lttng_ust_hip_hipGetMipmappedArrayLevel_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGetMipmappedArrayLevel_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipArray_t);

void btx_register_callbacks_lttng_ust_hip_hipGetMipmappedArrayLevel_exit(
    void *btx_handle, lttng_ust_hip_hipGetMipmappedArrayLevel_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpy2D_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, size_t, void *, size_t, size_t, size_t, hipMemcpyKind);

void btx_register_callbacks_lttng_ust_hip_hipMemcpy2D_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpy2D_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpy2D_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpy2D_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpy2D_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyParam2D_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hip_Memcpy2D *, size_t, hip_Memcpy2D *);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyParam2D_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpyParam2D_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyParam2D_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyParam2D_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpyParam2D_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyParam2DAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hip_Memcpy2D *, hipStream_t, size_t, hip_Memcpy2D *);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyParam2DAsync_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpyParam2DAsync_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyParam2DAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyParam2DAsync_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpyParam2DAsync_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpy2DAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, size_t, void *, size_t, size_t, size_t, hipMemcpyKind, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpy2DAsync_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpy2DAsync_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpy2DAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpy2DAsync_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpy2DAsync_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpy2DToArray_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipArray *, size_t, size_t, void *, size_t, size_t, size_t, hipMemcpyKind);

void btx_register_callbacks_lttng_ust_hip_hipMemcpy2DToArray_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpy2DToArray_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpy2DToArray_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpy2DToArray_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpy2DToArray_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpy2DToArrayAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipArray *, size_t, size_t, void *, size_t, size_t, size_t, hipMemcpyKind, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpy2DToArrayAsync_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpy2DToArrayAsync_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpy2DToArrayAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpy2DToArrayAsync_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpy2DToArrayAsync_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyToArray_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipArray *, size_t, size_t, void *, size_t, hipMemcpyKind);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyToArray_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpyToArray_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyToArray_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyToArray_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpyToArray_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyFromArray_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, hipArray_const_t, size_t, size_t, size_t, hipMemcpyKind);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyFromArray_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpyFromArray_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyFromArray_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyFromArray_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpyFromArray_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpy2DFromArray_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, size_t, hipArray_const_t, size_t, size_t, size_t, size_t, hipMemcpyKind);

void btx_register_callbacks_lttng_ust_hip_hipMemcpy2DFromArray_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpy2DFromArray_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpy2DFromArray_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpy2DFromArray_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpy2DFromArray_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpy2DFromArrayAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, size_t, hipArray_const_t, size_t, size_t, size_t, size_t, hipMemcpyKind, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpy2DFromArrayAsync_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpy2DFromArrayAsync_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpy2DFromArrayAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpy2DFromArrayAsync_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpy2DFromArrayAsync_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyAtoH_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, hipArray *, size_t, size_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyAtoH_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpyAtoH_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyAtoH_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyAtoH_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpyAtoH_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyHtoA_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipArray *, size_t, void *, size_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyHtoA_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpyHtoA_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyHtoA_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyHtoA_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpyHtoA_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpy3D_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, struct hipMemcpy3DParms *, size_t, struct hipMemcpy3DParms *);

void btx_register_callbacks_lttng_ust_hip_hipMemcpy3D_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpy3D_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpy3D_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpy3D_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpy3D_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpy3DAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, struct hipMemcpy3DParms *, hipStream_t, size_t, struct hipMemcpy3DParms *);

void btx_register_callbacks_lttng_ust_hip_hipMemcpy3DAsync_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpy3DAsync_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpy3DAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpy3DAsync_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpy3DAsync_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDrvMemcpy3D_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, HIP_MEMCPY3D *, size_t, HIP_MEMCPY3D *);

void btx_register_callbacks_lttng_ust_hip_hipDrvMemcpy3D_entry(
    void *btx_handle, lttng_ust_hip_hipDrvMemcpy3D_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDrvMemcpy3D_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipDrvMemcpy3D_exit(
    void *btx_handle, lttng_ust_hip_hipDrvMemcpy3D_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDrvMemcpy3DAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, HIP_MEMCPY3D *, hipStream_t, size_t, HIP_MEMCPY3D *);

void btx_register_callbacks_lttng_ust_hip_hipDrvMemcpy3DAsync_entry(
    void *btx_handle, lttng_ust_hip_hipDrvMemcpy3DAsync_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDrvMemcpy3DAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipDrvMemcpy3DAsync_exit(
    void *btx_handle, lttng_ust_hip_hipDrvMemcpy3DAsync_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceCanAccessPeer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, int, int);

void btx_register_callbacks_lttng_ust_hip_hipDeviceCanAccessPeer_entry(
    void *btx_handle, lttng_ust_hip_hipDeviceCanAccessPeer_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceCanAccessPeer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, int);

void btx_register_callbacks_lttng_ust_hip_hipDeviceCanAccessPeer_exit(
    void *btx_handle, lttng_ust_hip_hipDeviceCanAccessPeer_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceEnablePeerAccess_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipDeviceEnablePeerAccess_entry(
    void *btx_handle, lttng_ust_hip_hipDeviceEnablePeerAccess_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceEnablePeerAccess_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipDeviceEnablePeerAccess_exit(
    void *btx_handle, lttng_ust_hip_hipDeviceEnablePeerAccess_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceDisablePeerAccess_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_hip_hipDeviceDisablePeerAccess_entry(
    void *btx_handle, lttng_ust_hip_hipDeviceDisablePeerAccess_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceDisablePeerAccess_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipDeviceDisablePeerAccess_exit(
    void *btx_handle, lttng_ust_hip_hipDeviceDisablePeerAccess_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemGetAddressRange_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipDeviceptr_t *, size_t *, hipDeviceptr_t);

void btx_register_callbacks_lttng_ust_hip_hipMemGetAddressRange_entry(
    void *btx_handle, lttng_ust_hip_hipMemGetAddressRange_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemGetAddressRange_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipDeviceptr_t, size_t);

void btx_register_callbacks_lttng_ust_hip_hipMemGetAddressRange_exit(
    void *btx_handle, lttng_ust_hip_hipMemGetAddressRange_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyPeer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, void *, int, size_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyPeer_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpyPeer_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyPeer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyPeer_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpyPeer_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyPeerAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, void *, int, size_t, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyPeerAsync_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpyPeerAsync_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyPeerAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyPeerAsync_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpyPeerAsync_exit_callback_f *callback);

typedef void lttng_ust_hip_hipCtxCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipCtx_t *, unsigned int, hipDevice_t);

void btx_register_callbacks_lttng_ust_hip_hipCtxCreate_entry(
    void *btx_handle, lttng_ust_hip_hipCtxCreate_entry_callback_f *callback);

typedef void lttng_ust_hip_hipCtxCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipCtx_t);

void btx_register_callbacks_lttng_ust_hip_hipCtxCreate_exit(
    void *btx_handle, lttng_ust_hip_hipCtxCreate_exit_callback_f *callback);

typedef void lttng_ust_hip_hipCtxDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipCtx_t);

void btx_register_callbacks_lttng_ust_hip_hipCtxDestroy_entry(
    void *btx_handle, lttng_ust_hip_hipCtxDestroy_entry_callback_f *callback);

typedef void lttng_ust_hip_hipCtxDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipCtxDestroy_exit(
    void *btx_handle, lttng_ust_hip_hipCtxDestroy_exit_callback_f *callback);

typedef void lttng_ust_hip_hipCtxPopCurrent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipCtx_t *);

void btx_register_callbacks_lttng_ust_hip_hipCtxPopCurrent_entry(
    void *btx_handle, lttng_ust_hip_hipCtxPopCurrent_entry_callback_f *callback);

typedef void lttng_ust_hip_hipCtxPopCurrent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipCtx_t);

void btx_register_callbacks_lttng_ust_hip_hipCtxPopCurrent_exit(
    void *btx_handle, lttng_ust_hip_hipCtxPopCurrent_exit_callback_f *callback);

typedef void lttng_ust_hip_hipCtxPushCurrent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipCtx_t);

void btx_register_callbacks_lttng_ust_hip_hipCtxPushCurrent_entry(
    void *btx_handle, lttng_ust_hip_hipCtxPushCurrent_entry_callback_f *callback);

typedef void lttng_ust_hip_hipCtxPushCurrent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipCtxPushCurrent_exit(
    void *btx_handle, lttng_ust_hip_hipCtxPushCurrent_exit_callback_f *callback);

typedef void lttng_ust_hip_hipCtxSetCurrent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipCtx_t);

void btx_register_callbacks_lttng_ust_hip_hipCtxSetCurrent_entry(
    void *btx_handle, lttng_ust_hip_hipCtxSetCurrent_entry_callback_f *callback);

typedef void lttng_ust_hip_hipCtxSetCurrent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipCtxSetCurrent_exit(
    void *btx_handle, lttng_ust_hip_hipCtxSetCurrent_exit_callback_f *callback);

typedef void lttng_ust_hip_hipCtxGetCurrent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipCtx_t *);

void btx_register_callbacks_lttng_ust_hip_hipCtxGetCurrent_entry(
    void *btx_handle, lttng_ust_hip_hipCtxGetCurrent_entry_callback_f *callback);

typedef void lttng_ust_hip_hipCtxGetCurrent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipCtx_t);

void btx_register_callbacks_lttng_ust_hip_hipCtxGetCurrent_exit(
    void *btx_handle, lttng_ust_hip_hipCtxGetCurrent_exit_callback_f *callback);

typedef void lttng_ust_hip_hipCtxGetDevice_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipDevice_t *);

void btx_register_callbacks_lttng_ust_hip_hipCtxGetDevice_entry(
    void *btx_handle, lttng_ust_hip_hipCtxGetDevice_entry_callback_f *callback);

typedef void lttng_ust_hip_hipCtxGetDevice_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipDevice_t);

void btx_register_callbacks_lttng_ust_hip_hipCtxGetDevice_exit(
    void *btx_handle, lttng_ust_hip_hipCtxGetDevice_exit_callback_f *callback);

typedef void lttng_ust_hip_hipCtxGetApiVersion_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipCtx_t, int *);

void btx_register_callbacks_lttng_ust_hip_hipCtxGetApiVersion_entry(
    void *btx_handle, lttng_ust_hip_hipCtxGetApiVersion_entry_callback_f *callback);

typedef void lttng_ust_hip_hipCtxGetApiVersion_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, int);

void btx_register_callbacks_lttng_ust_hip_hipCtxGetApiVersion_exit(
    void *btx_handle, lttng_ust_hip_hipCtxGetApiVersion_exit_callback_f *callback);

typedef void lttng_ust_hip_hipCtxGetCacheConfig_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipFuncCache_t *);

void btx_register_callbacks_lttng_ust_hip_hipCtxGetCacheConfig_entry(
    void *btx_handle, lttng_ust_hip_hipCtxGetCacheConfig_entry_callback_f *callback);

typedef void lttng_ust_hip_hipCtxGetCacheConfig_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipFuncCache_t);

void btx_register_callbacks_lttng_ust_hip_hipCtxGetCacheConfig_exit(
    void *btx_handle, lttng_ust_hip_hipCtxGetCacheConfig_exit_callback_f *callback);

typedef void lttng_ust_hip_hipCtxSetCacheConfig_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipFuncCache_t);

void btx_register_callbacks_lttng_ust_hip_hipCtxSetCacheConfig_entry(
    void *btx_handle, lttng_ust_hip_hipCtxSetCacheConfig_entry_callback_f *callback);

typedef void lttng_ust_hip_hipCtxSetCacheConfig_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipCtxSetCacheConfig_exit(
    void *btx_handle, lttng_ust_hip_hipCtxSetCacheConfig_exit_callback_f *callback);

typedef void lttng_ust_hip_hipCtxSetSharedMemConfig_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipSharedMemConfig);

void btx_register_callbacks_lttng_ust_hip_hipCtxSetSharedMemConfig_entry(
    void *btx_handle, lttng_ust_hip_hipCtxSetSharedMemConfig_entry_callback_f *callback);

typedef void lttng_ust_hip_hipCtxSetSharedMemConfig_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipCtxSetSharedMemConfig_exit(
    void *btx_handle, lttng_ust_hip_hipCtxSetSharedMemConfig_exit_callback_f *callback);

typedef void lttng_ust_hip_hipCtxGetSharedMemConfig_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipSharedMemConfig *);

void btx_register_callbacks_lttng_ust_hip_hipCtxGetSharedMemConfig_entry(
    void *btx_handle, lttng_ust_hip_hipCtxGetSharedMemConfig_entry_callback_f *callback);

typedef void lttng_ust_hip_hipCtxGetSharedMemConfig_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipSharedMemConfig);

void btx_register_callbacks_lttng_ust_hip_hipCtxGetSharedMemConfig_exit(
    void *btx_handle, lttng_ust_hip_hipCtxGetSharedMemConfig_exit_callback_f *callback);

typedef void lttng_ust_hip_hipCtxSynchronize_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_hip_hipCtxSynchronize_entry(
    void *btx_handle, lttng_ust_hip_hipCtxSynchronize_entry_callback_f *callback);

typedef void lttng_ust_hip_hipCtxSynchronize_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipCtxSynchronize_exit(
    void *btx_handle, lttng_ust_hip_hipCtxSynchronize_exit_callback_f *callback);

typedef void lttng_ust_hip_hipCtxGetFlags_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, unsigned int *);

void btx_register_callbacks_lttng_ust_hip_hipCtxGetFlags_entry(
    void *btx_handle, lttng_ust_hip_hipCtxGetFlags_entry_callback_f *callback);

typedef void lttng_ust_hip_hipCtxGetFlags_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipCtxGetFlags_exit(
    void *btx_handle, lttng_ust_hip_hipCtxGetFlags_exit_callback_f *callback);

typedef void lttng_ust_hip_hipCtxEnablePeerAccess_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipCtx_t, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipCtxEnablePeerAccess_entry(
    void *btx_handle, lttng_ust_hip_hipCtxEnablePeerAccess_entry_callback_f *callback);

typedef void lttng_ust_hip_hipCtxEnablePeerAccess_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipCtxEnablePeerAccess_exit(
    void *btx_handle, lttng_ust_hip_hipCtxEnablePeerAccess_exit_callback_f *callback);

typedef void lttng_ust_hip_hipCtxDisablePeerAccess_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipCtx_t);

void btx_register_callbacks_lttng_ust_hip_hipCtxDisablePeerAccess_entry(
    void *btx_handle, lttng_ust_hip_hipCtxDisablePeerAccess_entry_callback_f *callback);

typedef void lttng_ust_hip_hipCtxDisablePeerAccess_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipCtxDisablePeerAccess_exit(
    void *btx_handle, lttng_ust_hip_hipCtxDisablePeerAccess_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDevicePrimaryCtxGetState_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipDevice_t, unsigned int *, int *);

void btx_register_callbacks_lttng_ust_hip_hipDevicePrimaryCtxGetState_entry(
    void *btx_handle, lttng_ust_hip_hipDevicePrimaryCtxGetState_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDevicePrimaryCtxGetState_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, unsigned int, int);

void btx_register_callbacks_lttng_ust_hip_hipDevicePrimaryCtxGetState_exit(
    void *btx_handle, lttng_ust_hip_hipDevicePrimaryCtxGetState_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDevicePrimaryCtxRelease_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipDevice_t);

void btx_register_callbacks_lttng_ust_hip_hipDevicePrimaryCtxRelease_entry(
    void *btx_handle, lttng_ust_hip_hipDevicePrimaryCtxRelease_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDevicePrimaryCtxRelease_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipDevicePrimaryCtxRelease_exit(
    void *btx_handle, lttng_ust_hip_hipDevicePrimaryCtxRelease_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDevicePrimaryCtxRetain_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipCtx_t *, hipDevice_t);

void btx_register_callbacks_lttng_ust_hip_hipDevicePrimaryCtxRetain_entry(
    void *btx_handle, lttng_ust_hip_hipDevicePrimaryCtxRetain_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDevicePrimaryCtxRetain_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipCtx_t);

void btx_register_callbacks_lttng_ust_hip_hipDevicePrimaryCtxRetain_exit(
    void *btx_handle, lttng_ust_hip_hipDevicePrimaryCtxRetain_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDevicePrimaryCtxReset_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipDevice_t);

void btx_register_callbacks_lttng_ust_hip_hipDevicePrimaryCtxReset_entry(
    void *btx_handle, lttng_ust_hip_hipDevicePrimaryCtxReset_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDevicePrimaryCtxReset_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipDevicePrimaryCtxReset_exit(
    void *btx_handle, lttng_ust_hip_hipDevicePrimaryCtxReset_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDevicePrimaryCtxSetFlags_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipDevice_t, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipDevicePrimaryCtxSetFlags_entry(
    void *btx_handle, lttng_ust_hip_hipDevicePrimaryCtxSetFlags_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDevicePrimaryCtxSetFlags_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipDevicePrimaryCtxSetFlags_exit(
    void *btx_handle, lttng_ust_hip_hipDevicePrimaryCtxSetFlags_exit_callback_f *callback);

typedef void lttng_ust_hip_hipModuleLoad_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipModule_t *, char *, char *);

void btx_register_callbacks_lttng_ust_hip_hipModuleLoad_entry(
    void *btx_handle, lttng_ust_hip_hipModuleLoad_entry_callback_f *callback);

typedef void lttng_ust_hip_hipModuleLoad_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipModule_t);

void btx_register_callbacks_lttng_ust_hip_hipModuleLoad_exit(
    void *btx_handle, lttng_ust_hip_hipModuleLoad_exit_callback_f *callback);

typedef void lttng_ust_hip_hipModuleUnload_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipModule_t);

void btx_register_callbacks_lttng_ust_hip_hipModuleUnload_entry(
    void *btx_handle, lttng_ust_hip_hipModuleUnload_entry_callback_f *callback);

typedef void lttng_ust_hip_hipModuleUnload_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipModuleUnload_exit(
    void *btx_handle, lttng_ust_hip_hipModuleUnload_exit_callback_f *callback);

typedef void lttng_ust_hip_hipModuleGetFunction_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipFunction_t *, hipModule_t, char *, char *);

void btx_register_callbacks_lttng_ust_hip_hipModuleGetFunction_entry(
    void *btx_handle, lttng_ust_hip_hipModuleGetFunction_entry_callback_f *callback);

typedef void lttng_ust_hip_hipModuleGetFunction_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipFunction_t);

void btx_register_callbacks_lttng_ust_hip_hipModuleGetFunction_exit(
    void *btx_handle, lttng_ust_hip_hipModuleGetFunction_exit_callback_f *callback);

typedef void lttng_ust_hip_hipFuncGetAttributes_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, struct hipFuncAttributes *, void *);

void btx_register_callbacks_lttng_ust_hip_hipFuncGetAttributes_entry(
    void *btx_handle, lttng_ust_hip_hipFuncGetAttributes_entry_callback_f *callback);

typedef void lttng_ust_hip_hipFuncGetAttributes_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t, struct hipFuncAttributes *);

void btx_register_callbacks_lttng_ust_hip_hipFuncGetAttributes_exit(
    void *btx_handle, lttng_ust_hip_hipFuncGetAttributes_exit_callback_f *callback);

typedef void lttng_ust_hip_hipFuncGetAttribute_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, hipFunction_attribute, hipFunction_t);

void btx_register_callbacks_lttng_ust_hip_hipFuncGetAttribute_entry(
    void *btx_handle, lttng_ust_hip_hipFuncGetAttribute_entry_callback_f *callback);

typedef void lttng_ust_hip_hipFuncGetAttribute_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, int);

void btx_register_callbacks_lttng_ust_hip_hipFuncGetAttribute_exit(
    void *btx_handle, lttng_ust_hip_hipFuncGetAttribute_exit_callback_f *callback);

typedef void lttng_ust_hip_hipModuleGetTexRef_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, textureReference **, hipModule_t, char *, char *);

void btx_register_callbacks_lttng_ust_hip_hipModuleGetTexRef_entry(
    void *btx_handle, lttng_ust_hip_hipModuleGetTexRef_entry_callback_f *callback);

typedef void lttng_ust_hip_hipModuleGetTexRef_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, textureReference *);

void btx_register_callbacks_lttng_ust_hip_hipModuleGetTexRef_exit(
    void *btx_handle, lttng_ust_hip_hipModuleGetTexRef_exit_callback_f *callback);

typedef void lttng_ust_hip_hipModuleLoadData_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipModule_t *, void *);

void btx_register_callbacks_lttng_ust_hip_hipModuleLoadData_entry(
    void *btx_handle, lttng_ust_hip_hipModuleLoadData_entry_callback_f *callback);

typedef void lttng_ust_hip_hipModuleLoadData_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipModule_t);

void btx_register_callbacks_lttng_ust_hip_hipModuleLoadData_exit(
    void *btx_handle, lttng_ust_hip_hipModuleLoadData_exit_callback_f *callback);

typedef void lttng_ust_hip_hipModuleLoadDataEx_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipModule_t *, void *, unsigned int, hipJitOption *, void **, size_t, hipJitOption *, size_t, void * *);

void btx_register_callbacks_lttng_ust_hip_hipModuleLoadDataEx_entry(
    void *btx_handle, lttng_ust_hip_hipModuleLoadDataEx_entry_callback_f *callback);

typedef void lttng_ust_hip_hipModuleLoadDataEx_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipModule_t);

void btx_register_callbacks_lttng_ust_hip_hipModuleLoadDataEx_exit(
    void *btx_handle, lttng_ust_hip_hipModuleLoadDataEx_exit_callback_f *callback);

typedef void lttng_ust_hip_hipModuleLaunchKernel_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipFunction_t, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, hipStream_t, void **, void **);

void btx_register_callbacks_lttng_ust_hip_hipModuleLaunchKernel_entry(
    void *btx_handle, lttng_ust_hip_hipModuleLaunchKernel_entry_callback_f *callback);

typedef void lttng_ust_hip_hipModuleLaunchKernel_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipModuleLaunchKernel_exit(
    void *btx_handle, lttng_ust_hip_hipModuleLaunchKernel_exit_callback_f *callback);

typedef void lttng_ust_hip_hipLaunchCooperativeKernel_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, dim3, dim3, void **, unsigned int, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipLaunchCooperativeKernel_entry(
    void *btx_handle, lttng_ust_hip_hipLaunchCooperativeKernel_entry_callback_f *callback);

typedef void lttng_ust_hip_hipLaunchCooperativeKernel_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipLaunchCooperativeKernel_exit(
    void *btx_handle, lttng_ust_hip_hipLaunchCooperativeKernel_exit_callback_f *callback);

typedef void lttng_ust_hip_hipLaunchCooperativeKernelMultiDevice_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipLaunchParams *, int, unsigned int, size_t, hipLaunchParams *);

void btx_register_callbacks_lttng_ust_hip_hipLaunchCooperativeKernelMultiDevice_entry(
    void *btx_handle, lttng_ust_hip_hipLaunchCooperativeKernelMultiDevice_entry_callback_f *callback);

typedef void lttng_ust_hip_hipLaunchCooperativeKernelMultiDevice_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipLaunchCooperativeKernelMultiDevice_exit(
    void *btx_handle, lttng_ust_hip_hipLaunchCooperativeKernelMultiDevice_exit_callback_f *callback);

typedef void lttng_ust_hip_hipExtLaunchMultiKernelMultiDevice_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipLaunchParams *, int, unsigned int, size_t, hipLaunchParams *);

void btx_register_callbacks_lttng_ust_hip_hipExtLaunchMultiKernelMultiDevice_entry(
    void *btx_handle, lttng_ust_hip_hipExtLaunchMultiKernelMultiDevice_entry_callback_f *callback);

typedef void lttng_ust_hip_hipExtLaunchMultiKernelMultiDevice_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipExtLaunchMultiKernelMultiDevice_exit(
    void *btx_handle, lttng_ust_hip_hipExtLaunchMultiKernelMultiDevice_exit_callback_f *callback);

typedef void lttng_ust_hip_hipModuleOccupancyMaxPotentialBlockSize_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, int *, hipFunction_t, size_t, int);

void btx_register_callbacks_lttng_ust_hip_hipModuleOccupancyMaxPotentialBlockSize_entry(
    void *btx_handle, lttng_ust_hip_hipModuleOccupancyMaxPotentialBlockSize_entry_callback_f *callback);

typedef void lttng_ust_hip_hipModuleOccupancyMaxPotentialBlockSize_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, int, int);

void btx_register_callbacks_lttng_ust_hip_hipModuleOccupancyMaxPotentialBlockSize_exit(
    void *btx_handle, lttng_ust_hip_hipModuleOccupancyMaxPotentialBlockSize_exit_callback_f *callback);

typedef void lttng_ust_hip_hipModuleOccupancyMaxPotentialBlockSizeWithFlags_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, int *, hipFunction_t, size_t, int, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipModuleOccupancyMaxPotentialBlockSizeWithFlags_entry(
    void *btx_handle, lttng_ust_hip_hipModuleOccupancyMaxPotentialBlockSizeWithFlags_entry_callback_f *callback);

typedef void lttng_ust_hip_hipModuleOccupancyMaxPotentialBlockSizeWithFlags_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, int, int);

void btx_register_callbacks_lttng_ust_hip_hipModuleOccupancyMaxPotentialBlockSizeWithFlags_exit(
    void *btx_handle, lttng_ust_hip_hipModuleOccupancyMaxPotentialBlockSizeWithFlags_exit_callback_f *callback);

typedef void lttng_ust_hip_hipModuleOccupancyMaxActiveBlocksPerMultiprocessor_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, hipFunction_t, int, size_t);

void btx_register_callbacks_lttng_ust_hip_hipModuleOccupancyMaxActiveBlocksPerMultiprocessor_entry(
    void *btx_handle, lttng_ust_hip_hipModuleOccupancyMaxActiveBlocksPerMultiprocessor_entry_callback_f *callback);

typedef void lttng_ust_hip_hipModuleOccupancyMaxActiveBlocksPerMultiprocessor_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, int);

void btx_register_callbacks_lttng_ust_hip_hipModuleOccupancyMaxActiveBlocksPerMultiprocessor_exit(
    void *btx_handle, lttng_ust_hip_hipModuleOccupancyMaxActiveBlocksPerMultiprocessor_exit_callback_f *callback);

typedef void lttng_ust_hip_hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, hipFunction_t, int, size_t, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_entry(
    void *btx_handle, lttng_ust_hip_hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_entry_callback_f *callback);

typedef void lttng_ust_hip_hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, int);

void btx_register_callbacks_lttng_ust_hip_hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_exit(
    void *btx_handle, lttng_ust_hip_hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_exit_callback_f *callback);

typedef void lttng_ust_hip_hipOccupancyMaxActiveBlocksPerMultiprocessor_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, void *, int, size_t);

void btx_register_callbacks_lttng_ust_hip_hipOccupancyMaxActiveBlocksPerMultiprocessor_entry(
    void *btx_handle, lttng_ust_hip_hipOccupancyMaxActiveBlocksPerMultiprocessor_entry_callback_f *callback);

typedef void lttng_ust_hip_hipOccupancyMaxActiveBlocksPerMultiprocessor_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, int);

void btx_register_callbacks_lttng_ust_hip_hipOccupancyMaxActiveBlocksPerMultiprocessor_exit(
    void *btx_handle, lttng_ust_hip_hipOccupancyMaxActiveBlocksPerMultiprocessor_exit_callback_f *callback);

typedef void lttng_ust_hip_hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, void *, int, size_t, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_entry(
    void *btx_handle, lttng_ust_hip_hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_entry_callback_f *callback);

typedef void lttng_ust_hip_hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, int);

void btx_register_callbacks_lttng_ust_hip_hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_exit(
    void *btx_handle, lttng_ust_hip_hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_exit_callback_f *callback);

typedef void lttng_ust_hip_hipOccupancyMaxPotentialBlockSize_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, int *, void *, size_t, int);

void btx_register_callbacks_lttng_ust_hip_hipOccupancyMaxPotentialBlockSize_entry(
    void *btx_handle, lttng_ust_hip_hipOccupancyMaxPotentialBlockSize_entry_callback_f *callback);

typedef void lttng_ust_hip_hipOccupancyMaxPotentialBlockSize_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, int, int);

void btx_register_callbacks_lttng_ust_hip_hipOccupancyMaxPotentialBlockSize_exit(
    void *btx_handle, lttng_ust_hip_hipOccupancyMaxPotentialBlockSize_exit_callback_f *callback);

typedef void lttng_ust_hip_hipProfilerStart_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_hip_hipProfilerStart_entry(
    void *btx_handle, lttng_ust_hip_hipProfilerStart_entry_callback_f *callback);

typedef void lttng_ust_hip_hipProfilerStart_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipProfilerStart_exit(
    void *btx_handle, lttng_ust_hip_hipProfilerStart_exit_callback_f *callback);

typedef void lttng_ust_hip_hipProfilerStop_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_hip_hipProfilerStop_entry(
    void *btx_handle, lttng_ust_hip_hipProfilerStop_entry_callback_f *callback);

typedef void lttng_ust_hip_hipProfilerStop_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipProfilerStop_exit(
    void *btx_handle, lttng_ust_hip_hipProfilerStop_exit_callback_f *callback);

typedef void lttng_ust_hip_hipConfigureCall_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, dim3, dim3, size_t, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipConfigureCall_entry(
    void *btx_handle, lttng_ust_hip_hipConfigureCall_entry_callback_f *callback);

typedef void lttng_ust_hip_hipConfigureCall_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipConfigureCall_exit(
    void *btx_handle, lttng_ust_hip_hipConfigureCall_exit_callback_f *callback);

typedef void lttng_ust_hip_hipSetupArgument_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, size_t, size_t, size_t, void *);

void btx_register_callbacks_lttng_ust_hip_hipSetupArgument_entry(
    void *btx_handle, lttng_ust_hip_hipSetupArgument_entry_callback_f *callback);

typedef void lttng_ust_hip_hipSetupArgument_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipSetupArgument_exit(
    void *btx_handle, lttng_ust_hip_hipSetupArgument_exit_callback_f *callback);

typedef void lttng_ust_hip_hipLaunchByPtr_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *);

void btx_register_callbacks_lttng_ust_hip_hipLaunchByPtr_entry(
    void *btx_handle, lttng_ust_hip_hipLaunchByPtr_entry_callback_f *callback);

typedef void lttng_ust_hip_hipLaunchByPtr_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipLaunchByPtr_exit(
    void *btx_handle, lttng_ust_hip_hipLaunchByPtr_exit_callback_f *callback);

typedef void lttng_ust_hip___hipPushCallConfiguration_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, dim3, dim3, size_t, hipStream_t);

void btx_register_callbacks_lttng_ust_hip___hipPushCallConfiguration_entry(
    void *btx_handle, lttng_ust_hip___hipPushCallConfiguration_entry_callback_f *callback);

typedef void lttng_ust_hip___hipPushCallConfiguration_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip___hipPushCallConfiguration_exit(
    void *btx_handle, lttng_ust_hip___hipPushCallConfiguration_exit_callback_f *callback);

typedef void lttng_ust_hip___hipPopCallConfiguration_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, dim3 *, dim3 *, size_t *, hipStream_t *);

void btx_register_callbacks_lttng_ust_hip___hipPopCallConfiguration_entry(
    void *btx_handle, lttng_ust_hip___hipPopCallConfiguration_entry_callback_f *callback);

typedef void lttng_ust_hip___hipPopCallConfiguration_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t, dim3 *, size_t, dim3 *, size_t, hipStream_t);

void btx_register_callbacks_lttng_ust_hip___hipPopCallConfiguration_exit(
    void *btx_handle, lttng_ust_hip___hipPopCallConfiguration_exit_callback_f *callback);

typedef void lttng_ust_hip_hipLaunchKernel_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, dim3, dim3, void **, size_t, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipLaunchKernel_entry(
    void *btx_handle, lttng_ust_hip_hipLaunchKernel_entry_callback_f *callback);

typedef void lttng_ust_hip_hipLaunchKernel_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipLaunchKernel_exit(
    void *btx_handle, lttng_ust_hip_hipLaunchKernel_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDrvMemcpy2DUnaligned_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hip_Memcpy2D *, size_t, hip_Memcpy2D *);

void btx_register_callbacks_lttng_ust_hip_hipDrvMemcpy2DUnaligned_entry(
    void *btx_handle, lttng_ust_hip_hipDrvMemcpy2DUnaligned_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDrvMemcpy2DUnaligned_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipDrvMemcpy2DUnaligned_exit(
    void *btx_handle, lttng_ust_hip_hipDrvMemcpy2DUnaligned_exit_callback_f *callback);

typedef void lttng_ust_hip_hipExtLaunchKernel_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, dim3, dim3, void **, size_t, hipStream_t, hipEvent_t, hipEvent_t, int);

void btx_register_callbacks_lttng_ust_hip_hipExtLaunchKernel_entry(
    void *btx_handle, lttng_ust_hip_hipExtLaunchKernel_entry_callback_f *callback);

typedef void lttng_ust_hip_hipExtLaunchKernel_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipExtLaunchKernel_exit(
    void *btx_handle, lttng_ust_hip_hipExtLaunchKernel_exit_callback_f *callback);

typedef void lttng_ust_hip_hipBindTextureToMipmappedArray_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, textureReference *, hipMipmappedArray_const_t, hipChannelFormatDesc *, size_t, hipChannelFormatDesc *);

void btx_register_callbacks_lttng_ust_hip_hipBindTextureToMipmappedArray_entry(
    void *btx_handle, lttng_ust_hip_hipBindTextureToMipmappedArray_entry_callback_f *callback);

typedef void lttng_ust_hip_hipBindTextureToMipmappedArray_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipBindTextureToMipmappedArray_exit(
    void *btx_handle, lttng_ust_hip_hipBindTextureToMipmappedArray_exit_callback_f *callback);

typedef void lttng_ust_hip_hipCreateTextureObject_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipTextureObject_t *, hipResourceDesc *, hipTextureDesc *, struct hipResourceViewDesc *, size_t, hipResourceDesc *, size_t, hipTextureDesc *, size_t, struct hipResourceViewDesc *);

void btx_register_callbacks_lttng_ust_hip_hipCreateTextureObject_entry(
    void *btx_handle, lttng_ust_hip_hipCreateTextureObject_entry_callback_f *callback);

typedef void lttng_ust_hip_hipCreateTextureObject_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipTextureObject_t);

void btx_register_callbacks_lttng_ust_hip_hipCreateTextureObject_exit(
    void *btx_handle, lttng_ust_hip_hipCreateTextureObject_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDestroyTextureObject_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipTextureObject_t);

void btx_register_callbacks_lttng_ust_hip_hipDestroyTextureObject_entry(
    void *btx_handle, lttng_ust_hip_hipDestroyTextureObject_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDestroyTextureObject_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipDestroyTextureObject_exit(
    void *btx_handle, lttng_ust_hip_hipDestroyTextureObject_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGetChannelDesc_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipChannelFormatDesc *, hipArray_const_t);

void btx_register_callbacks_lttng_ust_hip_hipGetChannelDesc_entry(
    void *btx_handle, lttng_ust_hip_hipGetChannelDesc_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGetChannelDesc_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t, hipChannelFormatDesc *);

void btx_register_callbacks_lttng_ust_hip_hipGetChannelDesc_exit(
    void *btx_handle, lttng_ust_hip_hipGetChannelDesc_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGetTextureObjectResourceDesc_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipResourceDesc *, hipTextureObject_t);

void btx_register_callbacks_lttng_ust_hip_hipGetTextureObjectResourceDesc_entry(
    void *btx_handle, lttng_ust_hip_hipGetTextureObjectResourceDesc_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGetTextureObjectResourceDesc_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t, hipResourceDesc *);

void btx_register_callbacks_lttng_ust_hip_hipGetTextureObjectResourceDesc_exit(
    void *btx_handle, lttng_ust_hip_hipGetTextureObjectResourceDesc_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGetTextureObjectResourceViewDesc_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, struct hipResourceViewDesc *, hipTextureObject_t);

void btx_register_callbacks_lttng_ust_hip_hipGetTextureObjectResourceViewDesc_entry(
    void *btx_handle, lttng_ust_hip_hipGetTextureObjectResourceViewDesc_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGetTextureObjectResourceViewDesc_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t, struct hipResourceViewDesc *);

void btx_register_callbacks_lttng_ust_hip_hipGetTextureObjectResourceViewDesc_exit(
    void *btx_handle, lttng_ust_hip_hipGetTextureObjectResourceViewDesc_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGetTextureObjectTextureDesc_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipTextureDesc *, hipTextureObject_t);

void btx_register_callbacks_lttng_ust_hip_hipGetTextureObjectTextureDesc_entry(
    void *btx_handle, lttng_ust_hip_hipGetTextureObjectTextureDesc_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGetTextureObjectTextureDesc_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t, hipTextureDesc *);

void btx_register_callbacks_lttng_ust_hip_hipGetTextureObjectTextureDesc_exit(
    void *btx_handle, lttng_ust_hip_hipGetTextureObjectTextureDesc_exit_callback_f *callback);

typedef void lttng_ust_hip_hipTexObjectCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipTextureObject_t *, HIP_RESOURCE_DESC *, HIP_TEXTURE_DESC *, HIP_RESOURCE_VIEW_DESC *, size_t, HIP_RESOURCE_DESC *, size_t, HIP_TEXTURE_DESC *, size_t, HIP_RESOURCE_VIEW_DESC *);

void btx_register_callbacks_lttng_ust_hip_hipTexObjectCreate_entry(
    void *btx_handle, lttng_ust_hip_hipTexObjectCreate_entry_callback_f *callback);

typedef void lttng_ust_hip_hipTexObjectCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipTextureObject_t);

void btx_register_callbacks_lttng_ust_hip_hipTexObjectCreate_exit(
    void *btx_handle, lttng_ust_hip_hipTexObjectCreate_exit_callback_f *callback);

typedef void lttng_ust_hip_hipTexObjectDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipTextureObject_t);

void btx_register_callbacks_lttng_ust_hip_hipTexObjectDestroy_entry(
    void *btx_handle, lttng_ust_hip_hipTexObjectDestroy_entry_callback_f *callback);

typedef void lttng_ust_hip_hipTexObjectDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipTexObjectDestroy_exit(
    void *btx_handle, lttng_ust_hip_hipTexObjectDestroy_exit_callback_f *callback);

typedef void lttng_ust_hip_hipTexObjectGetResourceDesc_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, HIP_RESOURCE_DESC *, hipTextureObject_t);

void btx_register_callbacks_lttng_ust_hip_hipTexObjectGetResourceDesc_entry(
    void *btx_handle, lttng_ust_hip_hipTexObjectGetResourceDesc_entry_callback_f *callback);

typedef void lttng_ust_hip_hipTexObjectGetResourceDesc_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t, HIP_RESOURCE_DESC *);

void btx_register_callbacks_lttng_ust_hip_hipTexObjectGetResourceDesc_exit(
    void *btx_handle, lttng_ust_hip_hipTexObjectGetResourceDesc_exit_callback_f *callback);

typedef void lttng_ust_hip_hipTexObjectGetResourceViewDesc_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, HIP_RESOURCE_VIEW_DESC *, hipTextureObject_t);

void btx_register_callbacks_lttng_ust_hip_hipTexObjectGetResourceViewDesc_entry(
    void *btx_handle, lttng_ust_hip_hipTexObjectGetResourceViewDesc_entry_callback_f *callback);

typedef void lttng_ust_hip_hipTexObjectGetResourceViewDesc_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t, HIP_RESOURCE_VIEW_DESC *);

void btx_register_callbacks_lttng_ust_hip_hipTexObjectGetResourceViewDesc_exit(
    void *btx_handle, lttng_ust_hip_hipTexObjectGetResourceViewDesc_exit_callback_f *callback);

typedef void lttng_ust_hip_hipTexObjectGetTextureDesc_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, HIP_TEXTURE_DESC *, hipTextureObject_t);

void btx_register_callbacks_lttng_ust_hip_hipTexObjectGetTextureDesc_entry(
    void *btx_handle, lttng_ust_hip_hipTexObjectGetTextureDesc_entry_callback_f *callback);

typedef void lttng_ust_hip_hipTexObjectGetTextureDesc_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t, HIP_TEXTURE_DESC *);

void btx_register_callbacks_lttng_ust_hip_hipTexObjectGetTextureDesc_exit(
    void *btx_handle, lttng_ust_hip_hipTexObjectGetTextureDesc_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGetTextureReference_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, textureReference **, void *);

void btx_register_callbacks_lttng_ust_hip_hipGetTextureReference_entry(
    void *btx_handle, lttng_ust_hip_hipGetTextureReference_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGetTextureReference_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, textureReference *);

void btx_register_callbacks_lttng_ust_hip_hipGetTextureReference_exit(
    void *btx_handle, lttng_ust_hip_hipGetTextureReference_exit_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefSetAddressMode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, textureReference *, int, enum hipTextureAddressMode);

void btx_register_callbacks_lttng_ust_hip_hipTexRefSetAddressMode_entry(
    void *btx_handle, lttng_ust_hip_hipTexRefSetAddressMode_entry_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefSetAddressMode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipTexRefSetAddressMode_exit(
    void *btx_handle, lttng_ust_hip_hipTexRefSetAddressMode_exit_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefSetArray_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, textureReference *, hipArray_const_t, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipTexRefSetArray_entry(
    void *btx_handle, lttng_ust_hip_hipTexRefSetArray_entry_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefSetArray_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipTexRefSetArray_exit(
    void *btx_handle, lttng_ust_hip_hipTexRefSetArray_exit_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefSetFilterMode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, textureReference *, enum hipTextureFilterMode);

void btx_register_callbacks_lttng_ust_hip_hipTexRefSetFilterMode_entry(
    void *btx_handle, lttng_ust_hip_hipTexRefSetFilterMode_entry_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefSetFilterMode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipTexRefSetFilterMode_exit(
    void *btx_handle, lttng_ust_hip_hipTexRefSetFilterMode_exit_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefSetFlags_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, textureReference *, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipTexRefSetFlags_entry(
    void *btx_handle, lttng_ust_hip_hipTexRefSetFlags_entry_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefSetFlags_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipTexRefSetFlags_exit(
    void *btx_handle, lttng_ust_hip_hipTexRefSetFlags_exit_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefSetFormat_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, textureReference *, hipArray_Format, int);

void btx_register_callbacks_lttng_ust_hip_hipTexRefSetFormat_entry(
    void *btx_handle, lttng_ust_hip_hipTexRefSetFormat_entry_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefSetFormat_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipTexRefSetFormat_exit(
    void *btx_handle, lttng_ust_hip_hipTexRefSetFormat_exit_callback_f *callback);

typedef void lttng_ust_hip_hipBindTexture_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, size_t *, textureReference *, void *, hipChannelFormatDesc *, size_t, size_t, hipChannelFormatDesc *);

void btx_register_callbacks_lttng_ust_hip_hipBindTexture_entry(
    void *btx_handle, lttng_ust_hip_hipBindTexture_entry_callback_f *callback);

typedef void lttng_ust_hip_hipBindTexture_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t);

void btx_register_callbacks_lttng_ust_hip_hipBindTexture_exit(
    void *btx_handle, lttng_ust_hip_hipBindTexture_exit_callback_f *callback);

typedef void lttng_ust_hip_hipBindTexture2D_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, size_t *, textureReference *, void *, hipChannelFormatDesc *, size_t, size_t, size_t, size_t, hipChannelFormatDesc *);

void btx_register_callbacks_lttng_ust_hip_hipBindTexture2D_entry(
    void *btx_handle, lttng_ust_hip_hipBindTexture2D_entry_callback_f *callback);

typedef void lttng_ust_hip_hipBindTexture2D_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t);

void btx_register_callbacks_lttng_ust_hip_hipBindTexture2D_exit(
    void *btx_handle, lttng_ust_hip_hipBindTexture2D_exit_callback_f *callback);

typedef void lttng_ust_hip_hipBindTextureToArray_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, textureReference *, hipArray_const_t, hipChannelFormatDesc *, size_t, hipChannelFormatDesc *);

void btx_register_callbacks_lttng_ust_hip_hipBindTextureToArray_entry(
    void *btx_handle, lttng_ust_hip_hipBindTextureToArray_entry_callback_f *callback);

typedef void lttng_ust_hip_hipBindTextureToArray_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipBindTextureToArray_exit(
    void *btx_handle, lttng_ust_hip_hipBindTextureToArray_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGetTextureAlignmentOffset_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, size_t *, textureReference *);

void btx_register_callbacks_lttng_ust_hip_hipGetTextureAlignmentOffset_entry(
    void *btx_handle, lttng_ust_hip_hipGetTextureAlignmentOffset_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGetTextureAlignmentOffset_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t);

void btx_register_callbacks_lttng_ust_hip_hipGetTextureAlignmentOffset_exit(
    void *btx_handle, lttng_ust_hip_hipGetTextureAlignmentOffset_exit_callback_f *callback);

typedef void lttng_ust_hip_hipUnbindTexture_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, textureReference *);

void btx_register_callbacks_lttng_ust_hip_hipUnbindTexture_entry(
    void *btx_handle, lttng_ust_hip_hipUnbindTexture_entry_callback_f *callback);

typedef void lttng_ust_hip_hipUnbindTexture_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipUnbindTexture_exit(
    void *btx_handle, lttng_ust_hip_hipUnbindTexture_exit_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefGetAddress_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipDeviceptr_t *, textureReference *);

void btx_register_callbacks_lttng_ust_hip_hipTexRefGetAddress_entry(
    void *btx_handle, lttng_ust_hip_hipTexRefGetAddress_entry_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefGetAddress_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipDeviceptr_t);

void btx_register_callbacks_lttng_ust_hip_hipTexRefGetAddress_exit(
    void *btx_handle, lttng_ust_hip_hipTexRefGetAddress_exit_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefGetAddressMode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, enum hipTextureAddressMode *, textureReference *, int);

void btx_register_callbacks_lttng_ust_hip_hipTexRefGetAddressMode_entry(
    void *btx_handle, lttng_ust_hip_hipTexRefGetAddressMode_entry_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefGetAddressMode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, enum hipTextureAddressMode);

void btx_register_callbacks_lttng_ust_hip_hipTexRefGetAddressMode_exit(
    void *btx_handle, lttng_ust_hip_hipTexRefGetAddressMode_exit_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefGetFilterMode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, enum hipTextureFilterMode *, textureReference *);

void btx_register_callbacks_lttng_ust_hip_hipTexRefGetFilterMode_entry(
    void *btx_handle, lttng_ust_hip_hipTexRefGetFilterMode_entry_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefGetFilterMode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, enum hipTextureFilterMode);

void btx_register_callbacks_lttng_ust_hip_hipTexRefGetFilterMode_exit(
    void *btx_handle, lttng_ust_hip_hipTexRefGetFilterMode_exit_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefGetFlags_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, unsigned int *, textureReference *);

void btx_register_callbacks_lttng_ust_hip_hipTexRefGetFlags_entry(
    void *btx_handle, lttng_ust_hip_hipTexRefGetFlags_entry_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefGetFlags_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipTexRefGetFlags_exit(
    void *btx_handle, lttng_ust_hip_hipTexRefGetFlags_exit_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefGetFormat_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipArray_Format *, int *, textureReference *);

void btx_register_callbacks_lttng_ust_hip_hipTexRefGetFormat_entry(
    void *btx_handle, lttng_ust_hip_hipTexRefGetFormat_entry_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefGetFormat_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipArray_Format, int);

void btx_register_callbacks_lttng_ust_hip_hipTexRefGetFormat_exit(
    void *btx_handle, lttng_ust_hip_hipTexRefGetFormat_exit_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefGetMaxAnisotropy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, textureReference *);

void btx_register_callbacks_lttng_ust_hip_hipTexRefGetMaxAnisotropy_entry(
    void *btx_handle, lttng_ust_hip_hipTexRefGetMaxAnisotropy_entry_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefGetMaxAnisotropy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, int);

void btx_register_callbacks_lttng_ust_hip_hipTexRefGetMaxAnisotropy_exit(
    void *btx_handle, lttng_ust_hip_hipTexRefGetMaxAnisotropy_exit_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefGetMipmapFilterMode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, enum hipTextureFilterMode *, textureReference *);

void btx_register_callbacks_lttng_ust_hip_hipTexRefGetMipmapFilterMode_entry(
    void *btx_handle, lttng_ust_hip_hipTexRefGetMipmapFilterMode_entry_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefGetMipmapFilterMode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, enum hipTextureFilterMode);

void btx_register_callbacks_lttng_ust_hip_hipTexRefGetMipmapFilterMode_exit(
    void *btx_handle, lttng_ust_hip_hipTexRefGetMipmapFilterMode_exit_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefGetMipmapLevelBias_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, float *, textureReference *);

void btx_register_callbacks_lttng_ust_hip_hipTexRefGetMipmapLevelBias_entry(
    void *btx_handle, lttng_ust_hip_hipTexRefGetMipmapLevelBias_entry_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefGetMipmapLevelBias_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, float);

void btx_register_callbacks_lttng_ust_hip_hipTexRefGetMipmapLevelBias_exit(
    void *btx_handle, lttng_ust_hip_hipTexRefGetMipmapLevelBias_exit_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefGetMipmapLevelClamp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, float *, float *, textureReference *);

void btx_register_callbacks_lttng_ust_hip_hipTexRefGetMipmapLevelClamp_entry(
    void *btx_handle, lttng_ust_hip_hipTexRefGetMipmapLevelClamp_entry_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefGetMipmapLevelClamp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, float, float);

void btx_register_callbacks_lttng_ust_hip_hipTexRefGetMipmapLevelClamp_exit(
    void *btx_handle, lttng_ust_hip_hipTexRefGetMipmapLevelClamp_exit_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefGetMipMappedArray_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipMipmappedArray_t *, textureReference *);

void btx_register_callbacks_lttng_ust_hip_hipTexRefGetMipMappedArray_entry(
    void *btx_handle, lttng_ust_hip_hipTexRefGetMipMappedArray_entry_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefGetMipMappedArray_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipMipmappedArray_t);

void btx_register_callbacks_lttng_ust_hip_hipTexRefGetMipMappedArray_exit(
    void *btx_handle, lttng_ust_hip_hipTexRefGetMipMappedArray_exit_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefSetAddress_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, size_t *, textureReference *, hipDeviceptr_t, size_t);

void btx_register_callbacks_lttng_ust_hip_hipTexRefSetAddress_entry(
    void *btx_handle, lttng_ust_hip_hipTexRefSetAddress_entry_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefSetAddress_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t);

void btx_register_callbacks_lttng_ust_hip_hipTexRefSetAddress_exit(
    void *btx_handle, lttng_ust_hip_hipTexRefSetAddress_exit_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefSetAddress2D_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, textureReference *, HIP_ARRAY_DESCRIPTOR *, hipDeviceptr_t, size_t, size_t, HIP_ARRAY_DESCRIPTOR *);

void btx_register_callbacks_lttng_ust_hip_hipTexRefSetAddress2D_entry(
    void *btx_handle, lttng_ust_hip_hipTexRefSetAddress2D_entry_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefSetAddress2D_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipTexRefSetAddress2D_exit(
    void *btx_handle, lttng_ust_hip_hipTexRefSetAddress2D_exit_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefSetMaxAnisotropy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, textureReference *, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipTexRefSetMaxAnisotropy_entry(
    void *btx_handle, lttng_ust_hip_hipTexRefSetMaxAnisotropy_entry_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefSetMaxAnisotropy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipTexRefSetMaxAnisotropy_exit(
    void *btx_handle, lttng_ust_hip_hipTexRefSetMaxAnisotropy_exit_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefSetBorderColor_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, textureReference *, float *);

void btx_register_callbacks_lttng_ust_hip_hipTexRefSetBorderColor_entry(
    void *btx_handle, lttng_ust_hip_hipTexRefSetBorderColor_entry_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefSetBorderColor_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipTexRefSetBorderColor_exit(
    void *btx_handle, lttng_ust_hip_hipTexRefSetBorderColor_exit_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefSetMipmapFilterMode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, textureReference *, enum hipTextureFilterMode);

void btx_register_callbacks_lttng_ust_hip_hipTexRefSetMipmapFilterMode_entry(
    void *btx_handle, lttng_ust_hip_hipTexRefSetMipmapFilterMode_entry_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefSetMipmapFilterMode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipTexRefSetMipmapFilterMode_exit(
    void *btx_handle, lttng_ust_hip_hipTexRefSetMipmapFilterMode_exit_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefSetMipmapLevelBias_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, textureReference *, float);

void btx_register_callbacks_lttng_ust_hip_hipTexRefSetMipmapLevelBias_entry(
    void *btx_handle, lttng_ust_hip_hipTexRefSetMipmapLevelBias_entry_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefSetMipmapLevelBias_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipTexRefSetMipmapLevelBias_exit(
    void *btx_handle, lttng_ust_hip_hipTexRefSetMipmapLevelBias_exit_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefSetMipmapLevelClamp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, textureReference *, float, float);

void btx_register_callbacks_lttng_ust_hip_hipTexRefSetMipmapLevelClamp_entry(
    void *btx_handle, lttng_ust_hip_hipTexRefSetMipmapLevelClamp_entry_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefSetMipmapLevelClamp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipTexRefSetMipmapLevelClamp_exit(
    void *btx_handle, lttng_ust_hip_hipTexRefSetMipmapLevelClamp_exit_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefSetMipmappedArray_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, textureReference *, struct hipMipmappedArray *, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipTexRefSetMipmappedArray_entry(
    void *btx_handle, lttng_ust_hip_hipTexRefSetMipmappedArray_entry_callback_f *callback);

typedef void lttng_ust_hip_hipTexRefSetMipmappedArray_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipTexRefSetMipmappedArray_exit(
    void *btx_handle, lttng_ust_hip_hipTexRefSetMipmappedArray_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMipmappedArrayCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipMipmappedArray_t *, HIP_ARRAY3D_DESCRIPTOR *, unsigned int, size_t, HIP_ARRAY3D_DESCRIPTOR *);

void btx_register_callbacks_lttng_ust_hip_hipMipmappedArrayCreate_entry(
    void *btx_handle, lttng_ust_hip_hipMipmappedArrayCreate_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMipmappedArrayCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipMipmappedArray_t);

void btx_register_callbacks_lttng_ust_hip_hipMipmappedArrayCreate_exit(
    void *btx_handle, lttng_ust_hip_hipMipmappedArrayCreate_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMipmappedArrayDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipMipmappedArray_t);

void btx_register_callbacks_lttng_ust_hip_hipMipmappedArrayDestroy_entry(
    void *btx_handle, lttng_ust_hip_hipMipmappedArrayDestroy_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMipmappedArrayDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMipmappedArrayDestroy_exit(
    void *btx_handle, lttng_ust_hip_hipMipmappedArrayDestroy_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMipmappedArrayGetLevel_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipArray_t *, hipMipmappedArray_t, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipMipmappedArrayGetLevel_entry(
    void *btx_handle, lttng_ust_hip_hipMipmappedArrayGetLevel_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMipmappedArrayGetLevel_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipArray_t);

void btx_register_callbacks_lttng_ust_hip_hipMipmappedArrayGetLevel_exit(
    void *btx_handle, lttng_ust_hip_hipMipmappedArrayGetLevel_exit_callback_f *callback);

typedef void lttng_ust_hip_hipApiName_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, uint32_t);

void btx_register_callbacks_lttng_ust_hip_hipApiName_entry(
    void *btx_handle, lttng_ust_hip_hipApiName_entry_callback_f *callback);

typedef void lttng_ust_hip_hipApiName_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, char *);

void btx_register_callbacks_lttng_ust_hip_hipApiName_exit(
    void *btx_handle, lttng_ust_hip_hipApiName_exit_callback_f *callback);

typedef void lttng_ust_hip_hipKernelNameRef_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipFunction_t);

void btx_register_callbacks_lttng_ust_hip_hipKernelNameRef_entry(
    void *btx_handle, lttng_ust_hip_hipKernelNameRef_entry_callback_f *callback);

typedef void lttng_ust_hip_hipKernelNameRef_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, char *);

void btx_register_callbacks_lttng_ust_hip_hipKernelNameRef_exit(
    void *btx_handle, lttng_ust_hip_hipKernelNameRef_exit_callback_f *callback);

typedef void lttng_ust_hip_hipKernelNameRefByPtr_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipKernelNameRefByPtr_entry(
    void *btx_handle, lttng_ust_hip_hipKernelNameRefByPtr_entry_callback_f *callback);

typedef void lttng_ust_hip_hipKernelNameRefByPtr_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, char *);

void btx_register_callbacks_lttng_ust_hip_hipKernelNameRefByPtr_exit(
    void *btx_handle, lttng_ust_hip_hipKernelNameRefByPtr_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGetStreamDeviceId_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipGetStreamDeviceId_entry(
    void *btx_handle, lttng_ust_hip_hipGetStreamDeviceId_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGetStreamDeviceId_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_hip_hipGetStreamDeviceId_exit(
    void *btx_handle, lttng_ust_hip_hipGetStreamDeviceId_exit_callback_f *callback);

typedef void lttng_ust_hip_hipStreamBeginCapture_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t, hipStreamCaptureMode);

void btx_register_callbacks_lttng_ust_hip_hipStreamBeginCapture_entry(
    void *btx_handle, lttng_ust_hip_hipStreamBeginCapture_entry_callback_f *callback);

typedef void lttng_ust_hip_hipStreamBeginCapture_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipStreamBeginCapture_exit(
    void *btx_handle, lttng_ust_hip_hipStreamBeginCapture_exit_callback_f *callback);

typedef void lttng_ust_hip_hipStreamEndCapture_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t, hipGraph_t *);

void btx_register_callbacks_lttng_ust_hip_hipStreamEndCapture_entry(
    void *btx_handle, lttng_ust_hip_hipStreamEndCapture_entry_callback_f *callback);

typedef void lttng_ust_hip_hipStreamEndCapture_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipGraph_t);

void btx_register_callbacks_lttng_ust_hip_hipStreamEndCapture_exit(
    void *btx_handle, lttng_ust_hip_hipStreamEndCapture_exit_callback_f *callback);

typedef void lttng_ust_hip_hipStreamGetCaptureInfo_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t, hipStreamCaptureStatus *, unsigned long long int *);

void btx_register_callbacks_lttng_ust_hip_hipStreamGetCaptureInfo_entry(
    void *btx_handle, lttng_ust_hip_hipStreamGetCaptureInfo_entry_callback_f *callback);

typedef void lttng_ust_hip_hipStreamGetCaptureInfo_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipStreamCaptureStatus, unsigned long long int);

void btx_register_callbacks_lttng_ust_hip_hipStreamGetCaptureInfo_exit(
    void *btx_handle, lttng_ust_hip_hipStreamGetCaptureInfo_exit_callback_f *callback);

typedef void lttng_ust_hip_hipStreamGetCaptureInfo_v2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t, hipStreamCaptureStatus *, unsigned long long int *, hipGraph_t *, hipGraphNode_t **, size_t *);

void btx_register_callbacks_lttng_ust_hip_hipStreamGetCaptureInfo_v2_entry(
    void *btx_handle, lttng_ust_hip_hipStreamGetCaptureInfo_v2_entry_callback_f *callback);

typedef void lttng_ust_hip_hipStreamGetCaptureInfo_v2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipStreamCaptureStatus, unsigned long long int, hipGraph_t, size_t, size_t, hipGraphNode_t * *);

void btx_register_callbacks_lttng_ust_hip_hipStreamGetCaptureInfo_v2_exit(
    void *btx_handle, lttng_ust_hip_hipStreamGetCaptureInfo_v2_exit_callback_f *callback);

typedef void lttng_ust_hip_hipStreamIsCapturing_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t, hipStreamCaptureStatus *);

void btx_register_callbacks_lttng_ust_hip_hipStreamIsCapturing_entry(
    void *btx_handle, lttng_ust_hip_hipStreamIsCapturing_entry_callback_f *callback);

typedef void lttng_ust_hip_hipStreamIsCapturing_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipStreamCaptureStatus);

void btx_register_callbacks_lttng_ust_hip_hipStreamIsCapturing_exit(
    void *btx_handle, lttng_ust_hip_hipStreamIsCapturing_exit_callback_f *callback);

typedef void lttng_ust_hip_hipStreamUpdateCaptureDependencies_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t, hipGraphNode_t *, size_t, unsigned int, size_t, hipGraphNode_t *);

void btx_register_callbacks_lttng_ust_hip_hipStreamUpdateCaptureDependencies_entry(
    void *btx_handle, lttng_ust_hip_hipStreamUpdateCaptureDependencies_entry_callback_f *callback);

typedef void lttng_ust_hip_hipStreamUpdateCaptureDependencies_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipStreamUpdateCaptureDependencies_exit(
    void *btx_handle, lttng_ust_hip_hipStreamUpdateCaptureDependencies_exit_callback_f *callback);

typedef void lttng_ust_hip_hipLaunchHostFunc_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t, hipHostFn_t, void *);

void btx_register_callbacks_lttng_ust_hip_hipLaunchHostFunc_entry(
    void *btx_handle, lttng_ust_hip_hipLaunchHostFunc_entry_callback_f *callback);

typedef void lttng_ust_hip_hipLaunchHostFunc_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipLaunchHostFunc_exit(
    void *btx_handle, lttng_ust_hip_hipLaunchHostFunc_exit_callback_f *callback);

typedef void lttng_ust_hip_hipThreadExchangeStreamCaptureMode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStreamCaptureMode *, hipStreamCaptureMode);

void btx_register_callbacks_lttng_ust_hip_hipThreadExchangeStreamCaptureMode_entry(
    void *btx_handle, lttng_ust_hip_hipThreadExchangeStreamCaptureMode_entry_callback_f *callback);

typedef void lttng_ust_hip_hipThreadExchangeStreamCaptureMode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipStreamCaptureMode);

void btx_register_callbacks_lttng_ust_hip_hipThreadExchangeStreamCaptureMode_exit(
    void *btx_handle, lttng_ust_hip_hipThreadExchangeStreamCaptureMode_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraph_t *, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipGraphCreate_entry(
    void *btx_handle, lttng_ust_hip_hipGraphCreate_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipGraph_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphCreate_exit(
    void *btx_handle, lttng_ust_hip_hipGraphCreate_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraph_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphDestroy_entry(
    void *btx_handle, lttng_ust_hip_hipGraphDestroy_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphDestroy_exit(
    void *btx_handle, lttng_ust_hip_hipGraphDestroy_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphAddDependencies_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraph_t, hipGraphNode_t *, hipGraphNode_t *, size_t, size_t, hipGraphNode_t *, size_t, hipGraphNode_t *);

void btx_register_callbacks_lttng_ust_hip_hipGraphAddDependencies_entry(
    void *btx_handle, lttng_ust_hip_hipGraphAddDependencies_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphAddDependencies_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphAddDependencies_exit(
    void *btx_handle, lttng_ust_hip_hipGraphAddDependencies_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphRemoveDependencies_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraph_t, hipGraphNode_t *, hipGraphNode_t *, size_t, size_t, hipGraphNode_t *, size_t, hipGraphNode_t *);

void btx_register_callbacks_lttng_ust_hip_hipGraphRemoveDependencies_entry(
    void *btx_handle, lttng_ust_hip_hipGraphRemoveDependencies_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphRemoveDependencies_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphRemoveDependencies_exit(
    void *btx_handle, lttng_ust_hip_hipGraphRemoveDependencies_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphGetEdges_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraph_t, hipGraphNode_t *, hipGraphNode_t *, size_t *);

void btx_register_callbacks_lttng_ust_hip_hipGraphGetEdges_entry(
    void *btx_handle, lttng_ust_hip_hipGraphGetEdges_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphGetEdges_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t, size_t, hipGraphNode_t *, size_t, hipGraphNode_t *);

void btx_register_callbacks_lttng_ust_hip_hipGraphGetEdges_exit(
    void *btx_handle, lttng_ust_hip_hipGraphGetEdges_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphGetNodes_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraph_t, hipGraphNode_t *, size_t *);

void btx_register_callbacks_lttng_ust_hip_hipGraphGetNodes_entry(
    void *btx_handle, lttng_ust_hip_hipGraphGetNodes_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphGetNodes_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t, size_t, hipGraphNode_t *);

void btx_register_callbacks_lttng_ust_hip_hipGraphGetNodes_exit(
    void *btx_handle, lttng_ust_hip_hipGraphGetNodes_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphGetRootNodes_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraph_t, hipGraphNode_t *, size_t *);

void btx_register_callbacks_lttng_ust_hip_hipGraphGetRootNodes_entry(
    void *btx_handle, lttng_ust_hip_hipGraphGetRootNodes_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphGetRootNodes_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t, size_t, hipGraphNode_t *);

void btx_register_callbacks_lttng_ust_hip_hipGraphGetRootNodes_exit(
    void *btx_handle, lttng_ust_hip_hipGraphGetRootNodes_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphNodeGetDependencies_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphNode_t, hipGraphNode_t *, size_t *);

void btx_register_callbacks_lttng_ust_hip_hipGraphNodeGetDependencies_entry(
    void *btx_handle, lttng_ust_hip_hipGraphNodeGetDependencies_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphNodeGetDependencies_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t, size_t, hipGraphNode_t *);

void btx_register_callbacks_lttng_ust_hip_hipGraphNodeGetDependencies_exit(
    void *btx_handle, lttng_ust_hip_hipGraphNodeGetDependencies_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphNodeGetDependentNodes_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphNode_t, hipGraphNode_t *, size_t *);

void btx_register_callbacks_lttng_ust_hip_hipGraphNodeGetDependentNodes_entry(
    void *btx_handle, lttng_ust_hip_hipGraphNodeGetDependentNodes_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphNodeGetDependentNodes_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t, size_t, hipGraphNode_t *);

void btx_register_callbacks_lttng_ust_hip_hipGraphNodeGetDependentNodes_exit(
    void *btx_handle, lttng_ust_hip_hipGraphNodeGetDependentNodes_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphNodeGetType_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphNode_t, hipGraphNodeType *);

void btx_register_callbacks_lttng_ust_hip_hipGraphNodeGetType_entry(
    void *btx_handle, lttng_ust_hip_hipGraphNodeGetType_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphNodeGetType_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipGraphNodeType);

void btx_register_callbacks_lttng_ust_hip_hipGraphNodeGetType_exit(
    void *btx_handle, lttng_ust_hip_hipGraphNodeGetType_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphDestroyNode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphNode_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphDestroyNode_entry(
    void *btx_handle, lttng_ust_hip_hipGraphDestroyNode_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphDestroyNode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphDestroyNode_exit(
    void *btx_handle, lttng_ust_hip_hipGraphDestroyNode_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphClone_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraph_t *, hipGraph_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphClone_entry(
    void *btx_handle, lttng_ust_hip_hipGraphClone_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphClone_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipGraph_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphClone_exit(
    void *btx_handle, lttng_ust_hip_hipGraphClone_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphNodeFindInClone_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphNode_t *, hipGraphNode_t, hipGraph_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphNodeFindInClone_entry(
    void *btx_handle, lttng_ust_hip_hipGraphNodeFindInClone_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphNodeFindInClone_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipGraphNode_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphNodeFindInClone_exit(
    void *btx_handle, lttng_ust_hip_hipGraphNodeFindInClone_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphInstantiate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphExec_t *, hipGraph_t, hipGraphNode_t *, char *, size_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphInstantiate_entry(
    void *btx_handle, lttng_ust_hip_hipGraphInstantiate_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphInstantiate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipGraphExec_t, hipGraphNode_t, size_t, char *);

void btx_register_callbacks_lttng_ust_hip_hipGraphInstantiate_exit(
    void *btx_handle, lttng_ust_hip_hipGraphInstantiate_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphInstantiateWithFlags_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphExec_t *, hipGraph_t, unsigned long long int);

void btx_register_callbacks_lttng_ust_hip_hipGraphInstantiateWithFlags_entry(
    void *btx_handle, lttng_ust_hip_hipGraphInstantiateWithFlags_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphInstantiateWithFlags_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipGraphExec_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphInstantiateWithFlags_exit(
    void *btx_handle, lttng_ust_hip_hipGraphInstantiateWithFlags_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphLaunch_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphExec_t, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphLaunch_entry(
    void *btx_handle, lttng_ust_hip_hipGraphLaunch_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphLaunch_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphLaunch_exit(
    void *btx_handle, lttng_ust_hip_hipGraphLaunch_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphUpload_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphExec_t, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphUpload_entry(
    void *btx_handle, lttng_ust_hip_hipGraphUpload_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphUpload_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphUpload_exit(
    void *btx_handle, lttng_ust_hip_hipGraphUpload_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphExecDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphExec_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphExecDestroy_entry(
    void *btx_handle, lttng_ust_hip_hipGraphExecDestroy_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphExecDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphExecDestroy_exit(
    void *btx_handle, lttng_ust_hip_hipGraphExecDestroy_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphExecUpdate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphExec_t, hipGraph_t, hipGraphNode_t *, hipGraphExecUpdateResult *);

void btx_register_callbacks_lttng_ust_hip_hipGraphExecUpdate_entry(
    void *btx_handle, lttng_ust_hip_hipGraphExecUpdate_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphExecUpdate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipGraphNode_t, hipGraphExecUpdateResult);

void btx_register_callbacks_lttng_ust_hip_hipGraphExecUpdate_exit(
    void *btx_handle, lttng_ust_hip_hipGraphExecUpdate_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphAddKernelNode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphNode_t *, hipGraph_t, hipGraphNode_t *, size_t, hipKernelNodeParams *, size_t, hipGraphNode_t *, size_t, hipKernelNodeParams *);

void btx_register_callbacks_lttng_ust_hip_hipGraphAddKernelNode_entry(
    void *btx_handle, lttng_ust_hip_hipGraphAddKernelNode_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphAddKernelNode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipGraphNode_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphAddKernelNode_exit(
    void *btx_handle, lttng_ust_hip_hipGraphAddKernelNode_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphKernelNodeGetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphNode_t, hipKernelNodeParams *);

void btx_register_callbacks_lttng_ust_hip_hipGraphKernelNodeGetParams_entry(
    void *btx_handle, lttng_ust_hip_hipGraphKernelNodeGetParams_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphKernelNodeGetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t, hipKernelNodeParams *);

void btx_register_callbacks_lttng_ust_hip_hipGraphKernelNodeGetParams_exit(
    void *btx_handle, lttng_ust_hip_hipGraphKernelNodeGetParams_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphKernelNodeSetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphNode_t, hipKernelNodeParams *, size_t, hipKernelNodeParams *);

void btx_register_callbacks_lttng_ust_hip_hipGraphKernelNodeSetParams_entry(
    void *btx_handle, lttng_ust_hip_hipGraphKernelNodeSetParams_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphKernelNodeSetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphKernelNodeSetParams_exit(
    void *btx_handle, lttng_ust_hip_hipGraphKernelNodeSetParams_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphExecKernelNodeSetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphExec_t, hipGraphNode_t, hipKernelNodeParams *);

void btx_register_callbacks_lttng_ust_hip_hipGraphExecKernelNodeSetParams_entry(
    void *btx_handle, lttng_ust_hip_hipGraphExecKernelNodeSetParams_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphExecKernelNodeSetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphExecKernelNodeSetParams_exit(
    void *btx_handle, lttng_ust_hip_hipGraphExecKernelNodeSetParams_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphAddMemcpyNode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphNode_t *, hipGraph_t, hipGraphNode_t *, size_t, hipMemcpy3DParms *, size_t, hipGraphNode_t *, size_t, hipMemcpy3DParms *);

void btx_register_callbacks_lttng_ust_hip_hipGraphAddMemcpyNode_entry(
    void *btx_handle, lttng_ust_hip_hipGraphAddMemcpyNode_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphAddMemcpyNode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipGraphNode_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphAddMemcpyNode_exit(
    void *btx_handle, lttng_ust_hip_hipGraphAddMemcpyNode_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphMemcpyNodeGetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphNode_t, hipMemcpy3DParms *);

void btx_register_callbacks_lttng_ust_hip_hipGraphMemcpyNodeGetParams_entry(
    void *btx_handle, lttng_ust_hip_hipGraphMemcpyNodeGetParams_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphMemcpyNodeGetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t, hipMemcpy3DParms *);

void btx_register_callbacks_lttng_ust_hip_hipGraphMemcpyNodeGetParams_exit(
    void *btx_handle, lttng_ust_hip_hipGraphMemcpyNodeGetParams_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphMemcpyNodeSetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphNode_t, hipMemcpy3DParms *, size_t, hipMemcpy3DParms *);

void btx_register_callbacks_lttng_ust_hip_hipGraphMemcpyNodeSetParams_entry(
    void *btx_handle, lttng_ust_hip_hipGraphMemcpyNodeSetParams_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphMemcpyNodeSetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphMemcpyNodeSetParams_exit(
    void *btx_handle, lttng_ust_hip_hipGraphMemcpyNodeSetParams_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphKernelNodeSetAttribute_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphNode_t, hipKernelNodeAttrID, hipKernelNodeAttrValue *, size_t, hipKernelNodeAttrValue *);

void btx_register_callbacks_lttng_ust_hip_hipGraphKernelNodeSetAttribute_entry(
    void *btx_handle, lttng_ust_hip_hipGraphKernelNodeSetAttribute_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphKernelNodeSetAttribute_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphKernelNodeSetAttribute_exit(
    void *btx_handle, lttng_ust_hip_hipGraphKernelNodeSetAttribute_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphKernelNodeGetAttribute_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphNode_t, hipKernelNodeAttrID, hipKernelNodeAttrValue *);

void btx_register_callbacks_lttng_ust_hip_hipGraphKernelNodeGetAttribute_entry(
    void *btx_handle, lttng_ust_hip_hipGraphKernelNodeGetAttribute_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphKernelNodeGetAttribute_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t, hipKernelNodeAttrValue *);

void btx_register_callbacks_lttng_ust_hip_hipGraphKernelNodeGetAttribute_exit(
    void *btx_handle, lttng_ust_hip_hipGraphKernelNodeGetAttribute_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphExecMemcpyNodeSetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphExec_t, hipGraphNode_t, hipMemcpy3DParms *, size_t, hipMemcpy3DParms *);

void btx_register_callbacks_lttng_ust_hip_hipGraphExecMemcpyNodeSetParams_entry(
    void *btx_handle, lttng_ust_hip_hipGraphExecMemcpyNodeSetParams_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphExecMemcpyNodeSetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphExecMemcpyNodeSetParams_exit(
    void *btx_handle, lttng_ust_hip_hipGraphExecMemcpyNodeSetParams_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphAddMemcpyNode1D_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphNode_t *, hipGraph_t, hipGraphNode_t *, size_t, void *, void *, size_t, hipMemcpyKind, size_t, hipGraphNode_t *);

void btx_register_callbacks_lttng_ust_hip_hipGraphAddMemcpyNode1D_entry(
    void *btx_handle, lttng_ust_hip_hipGraphAddMemcpyNode1D_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphAddMemcpyNode1D_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipGraphNode_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphAddMemcpyNode1D_exit(
    void *btx_handle, lttng_ust_hip_hipGraphAddMemcpyNode1D_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphMemcpyNodeSetParams1D_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphNode_t, void *, void *, size_t, hipMemcpyKind);

void btx_register_callbacks_lttng_ust_hip_hipGraphMemcpyNodeSetParams1D_entry(
    void *btx_handle, lttng_ust_hip_hipGraphMemcpyNodeSetParams1D_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphMemcpyNodeSetParams1D_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphMemcpyNodeSetParams1D_exit(
    void *btx_handle, lttng_ust_hip_hipGraphMemcpyNodeSetParams1D_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphExecMemcpyNodeSetParams1D_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphExec_t, hipGraphNode_t, void *, void *, size_t, hipMemcpyKind);

void btx_register_callbacks_lttng_ust_hip_hipGraphExecMemcpyNodeSetParams1D_entry(
    void *btx_handle, lttng_ust_hip_hipGraphExecMemcpyNodeSetParams1D_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphExecMemcpyNodeSetParams1D_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphExecMemcpyNodeSetParams1D_exit(
    void *btx_handle, lttng_ust_hip_hipGraphExecMemcpyNodeSetParams1D_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphAddMemcpyNodeFromSymbol_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphNode_t *, hipGraph_t, hipGraphNode_t *, size_t, void *, void *, size_t, size_t, hipMemcpyKind, size_t, hipGraphNode_t *);

void btx_register_callbacks_lttng_ust_hip_hipGraphAddMemcpyNodeFromSymbol_entry(
    void *btx_handle, lttng_ust_hip_hipGraphAddMemcpyNodeFromSymbol_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphAddMemcpyNodeFromSymbol_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipGraphNode_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphAddMemcpyNodeFromSymbol_exit(
    void *btx_handle, lttng_ust_hip_hipGraphAddMemcpyNodeFromSymbol_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphMemcpyNodeSetParamsFromSymbol_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphNode_t, void *, void *, size_t, size_t, hipMemcpyKind);

void btx_register_callbacks_lttng_ust_hip_hipGraphMemcpyNodeSetParamsFromSymbol_entry(
    void *btx_handle, lttng_ust_hip_hipGraphMemcpyNodeSetParamsFromSymbol_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphMemcpyNodeSetParamsFromSymbol_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphMemcpyNodeSetParamsFromSymbol_exit(
    void *btx_handle, lttng_ust_hip_hipGraphMemcpyNodeSetParamsFromSymbol_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphExecMemcpyNodeSetParamsFromSymbol_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphExec_t, hipGraphNode_t, void *, void *, size_t, size_t, hipMemcpyKind);

void btx_register_callbacks_lttng_ust_hip_hipGraphExecMemcpyNodeSetParamsFromSymbol_entry(
    void *btx_handle, lttng_ust_hip_hipGraphExecMemcpyNodeSetParamsFromSymbol_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphExecMemcpyNodeSetParamsFromSymbol_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphExecMemcpyNodeSetParamsFromSymbol_exit(
    void *btx_handle, lttng_ust_hip_hipGraphExecMemcpyNodeSetParamsFromSymbol_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphAddMemcpyNodeToSymbol_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphNode_t *, hipGraph_t, hipGraphNode_t *, size_t, void *, void *, size_t, size_t, hipMemcpyKind, size_t, hipGraphNode_t *);

void btx_register_callbacks_lttng_ust_hip_hipGraphAddMemcpyNodeToSymbol_entry(
    void *btx_handle, lttng_ust_hip_hipGraphAddMemcpyNodeToSymbol_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphAddMemcpyNodeToSymbol_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipGraphNode_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphAddMemcpyNodeToSymbol_exit(
    void *btx_handle, lttng_ust_hip_hipGraphAddMemcpyNodeToSymbol_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphMemcpyNodeSetParamsToSymbol_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphNode_t, void *, void *, size_t, size_t, hipMemcpyKind);

void btx_register_callbacks_lttng_ust_hip_hipGraphMemcpyNodeSetParamsToSymbol_entry(
    void *btx_handle, lttng_ust_hip_hipGraphMemcpyNodeSetParamsToSymbol_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphMemcpyNodeSetParamsToSymbol_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphMemcpyNodeSetParamsToSymbol_exit(
    void *btx_handle, lttng_ust_hip_hipGraphMemcpyNodeSetParamsToSymbol_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphExecMemcpyNodeSetParamsToSymbol_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphExec_t, hipGraphNode_t, void *, void *, size_t, size_t, hipMemcpyKind);

void btx_register_callbacks_lttng_ust_hip_hipGraphExecMemcpyNodeSetParamsToSymbol_entry(
    void *btx_handle, lttng_ust_hip_hipGraphExecMemcpyNodeSetParamsToSymbol_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphExecMemcpyNodeSetParamsToSymbol_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphExecMemcpyNodeSetParamsToSymbol_exit(
    void *btx_handle, lttng_ust_hip_hipGraphExecMemcpyNodeSetParamsToSymbol_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphAddMemsetNode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphNode_t *, hipGraph_t, hipGraphNode_t *, size_t, hipMemsetParams *, size_t, hipGraphNode_t *, size_t, hipMemsetParams *);

void btx_register_callbacks_lttng_ust_hip_hipGraphAddMemsetNode_entry(
    void *btx_handle, lttng_ust_hip_hipGraphAddMemsetNode_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphAddMemsetNode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipGraphNode_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphAddMemsetNode_exit(
    void *btx_handle, lttng_ust_hip_hipGraphAddMemsetNode_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphMemsetNodeGetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphNode_t, hipMemsetParams *);

void btx_register_callbacks_lttng_ust_hip_hipGraphMemsetNodeGetParams_entry(
    void *btx_handle, lttng_ust_hip_hipGraphMemsetNodeGetParams_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphMemsetNodeGetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t, hipMemsetParams *);

void btx_register_callbacks_lttng_ust_hip_hipGraphMemsetNodeGetParams_exit(
    void *btx_handle, lttng_ust_hip_hipGraphMemsetNodeGetParams_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphMemsetNodeSetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphNode_t, hipMemsetParams *, size_t, hipMemsetParams *);

void btx_register_callbacks_lttng_ust_hip_hipGraphMemsetNodeSetParams_entry(
    void *btx_handle, lttng_ust_hip_hipGraphMemsetNodeSetParams_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphMemsetNodeSetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphMemsetNodeSetParams_exit(
    void *btx_handle, lttng_ust_hip_hipGraphMemsetNodeSetParams_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphExecMemsetNodeSetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphExec_t, hipGraphNode_t, hipMemsetParams *, size_t, hipMemsetParams *);

void btx_register_callbacks_lttng_ust_hip_hipGraphExecMemsetNodeSetParams_entry(
    void *btx_handle, lttng_ust_hip_hipGraphExecMemsetNodeSetParams_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphExecMemsetNodeSetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphExecMemsetNodeSetParams_exit(
    void *btx_handle, lttng_ust_hip_hipGraphExecMemsetNodeSetParams_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphAddHostNode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphNode_t *, hipGraph_t, hipGraphNode_t *, size_t, hipHostNodeParams *, size_t, hipGraphNode_t *, size_t, hipHostNodeParams *);

void btx_register_callbacks_lttng_ust_hip_hipGraphAddHostNode_entry(
    void *btx_handle, lttng_ust_hip_hipGraphAddHostNode_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphAddHostNode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipGraphNode_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphAddHostNode_exit(
    void *btx_handle, lttng_ust_hip_hipGraphAddHostNode_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphHostNodeGetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphNode_t, hipHostNodeParams *);

void btx_register_callbacks_lttng_ust_hip_hipGraphHostNodeGetParams_entry(
    void *btx_handle, lttng_ust_hip_hipGraphHostNodeGetParams_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphHostNodeGetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t, hipHostNodeParams *);

void btx_register_callbacks_lttng_ust_hip_hipGraphHostNodeGetParams_exit(
    void *btx_handle, lttng_ust_hip_hipGraphHostNodeGetParams_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphHostNodeSetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphNode_t, hipHostNodeParams *, size_t, hipHostNodeParams *);

void btx_register_callbacks_lttng_ust_hip_hipGraphHostNodeSetParams_entry(
    void *btx_handle, lttng_ust_hip_hipGraphHostNodeSetParams_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphHostNodeSetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphHostNodeSetParams_exit(
    void *btx_handle, lttng_ust_hip_hipGraphHostNodeSetParams_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphExecHostNodeSetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphExec_t, hipGraphNode_t, hipHostNodeParams *, size_t, hipHostNodeParams *);

void btx_register_callbacks_lttng_ust_hip_hipGraphExecHostNodeSetParams_entry(
    void *btx_handle, lttng_ust_hip_hipGraphExecHostNodeSetParams_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphExecHostNodeSetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphExecHostNodeSetParams_exit(
    void *btx_handle, lttng_ust_hip_hipGraphExecHostNodeSetParams_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphAddChildGraphNode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphNode_t *, hipGraph_t, hipGraphNode_t *, size_t, hipGraph_t, size_t, hipGraphNode_t *);

void btx_register_callbacks_lttng_ust_hip_hipGraphAddChildGraphNode_entry(
    void *btx_handle, lttng_ust_hip_hipGraphAddChildGraphNode_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphAddChildGraphNode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipGraphNode_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphAddChildGraphNode_exit(
    void *btx_handle, lttng_ust_hip_hipGraphAddChildGraphNode_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphChildGraphNodeGetGraph_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphNode_t, hipGraph_t *);

void btx_register_callbacks_lttng_ust_hip_hipGraphChildGraphNodeGetGraph_entry(
    void *btx_handle, lttng_ust_hip_hipGraphChildGraphNodeGetGraph_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphChildGraphNodeGetGraph_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipGraph_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphChildGraphNodeGetGraph_exit(
    void *btx_handle, lttng_ust_hip_hipGraphChildGraphNodeGetGraph_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphExecChildGraphNodeSetParams_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphExec_t, hipGraphNode_t, hipGraph_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphExecChildGraphNodeSetParams_entry(
    void *btx_handle, lttng_ust_hip_hipGraphExecChildGraphNodeSetParams_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphExecChildGraphNodeSetParams_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphExecChildGraphNodeSetParams_exit(
    void *btx_handle, lttng_ust_hip_hipGraphExecChildGraphNodeSetParams_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphAddEmptyNode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphNode_t *, hipGraph_t, hipGraphNode_t *, size_t, size_t, hipGraphNode_t *);

void btx_register_callbacks_lttng_ust_hip_hipGraphAddEmptyNode_entry(
    void *btx_handle, lttng_ust_hip_hipGraphAddEmptyNode_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphAddEmptyNode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipGraphNode_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphAddEmptyNode_exit(
    void *btx_handle, lttng_ust_hip_hipGraphAddEmptyNode_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphAddEventRecordNode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphNode_t *, hipGraph_t, hipGraphNode_t *, size_t, hipEvent_t, size_t, hipGraphNode_t *);

void btx_register_callbacks_lttng_ust_hip_hipGraphAddEventRecordNode_entry(
    void *btx_handle, lttng_ust_hip_hipGraphAddEventRecordNode_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphAddEventRecordNode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipGraphNode_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphAddEventRecordNode_exit(
    void *btx_handle, lttng_ust_hip_hipGraphAddEventRecordNode_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphEventRecordNodeGetEvent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphNode_t, hipEvent_t *);

void btx_register_callbacks_lttng_ust_hip_hipGraphEventRecordNodeGetEvent_entry(
    void *btx_handle, lttng_ust_hip_hipGraphEventRecordNodeGetEvent_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphEventRecordNodeGetEvent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipEvent_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphEventRecordNodeGetEvent_exit(
    void *btx_handle, lttng_ust_hip_hipGraphEventRecordNodeGetEvent_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphEventRecordNodeSetEvent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphNode_t, hipEvent_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphEventRecordNodeSetEvent_entry(
    void *btx_handle, lttng_ust_hip_hipGraphEventRecordNodeSetEvent_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphEventRecordNodeSetEvent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphEventRecordNodeSetEvent_exit(
    void *btx_handle, lttng_ust_hip_hipGraphEventRecordNodeSetEvent_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphExecEventRecordNodeSetEvent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphExec_t, hipGraphNode_t, hipEvent_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphExecEventRecordNodeSetEvent_entry(
    void *btx_handle, lttng_ust_hip_hipGraphExecEventRecordNodeSetEvent_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphExecEventRecordNodeSetEvent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphExecEventRecordNodeSetEvent_exit(
    void *btx_handle, lttng_ust_hip_hipGraphExecEventRecordNodeSetEvent_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphAddEventWaitNode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphNode_t *, hipGraph_t, hipGraphNode_t *, size_t, hipEvent_t, size_t, hipGraphNode_t *);

void btx_register_callbacks_lttng_ust_hip_hipGraphAddEventWaitNode_entry(
    void *btx_handle, lttng_ust_hip_hipGraphAddEventWaitNode_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphAddEventWaitNode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipGraphNode_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphAddEventWaitNode_exit(
    void *btx_handle, lttng_ust_hip_hipGraphAddEventWaitNode_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphEventWaitNodeGetEvent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphNode_t, hipEvent_t *);

void btx_register_callbacks_lttng_ust_hip_hipGraphEventWaitNodeGetEvent_entry(
    void *btx_handle, lttng_ust_hip_hipGraphEventWaitNodeGetEvent_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphEventWaitNodeGetEvent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipEvent_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphEventWaitNodeGetEvent_exit(
    void *btx_handle, lttng_ust_hip_hipGraphEventWaitNodeGetEvent_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphEventWaitNodeSetEvent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphNode_t, hipEvent_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphEventWaitNodeSetEvent_entry(
    void *btx_handle, lttng_ust_hip_hipGraphEventWaitNodeSetEvent_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphEventWaitNodeSetEvent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphEventWaitNodeSetEvent_exit(
    void *btx_handle, lttng_ust_hip_hipGraphEventWaitNodeSetEvent_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphExecEventWaitNodeSetEvent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphExec_t, hipGraphNode_t, hipEvent_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphExecEventWaitNodeSetEvent_entry(
    void *btx_handle, lttng_ust_hip_hipGraphExecEventWaitNodeSetEvent_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphExecEventWaitNodeSetEvent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphExecEventWaitNodeSetEvent_exit(
    void *btx_handle, lttng_ust_hip_hipGraphExecEventWaitNodeSetEvent_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceGetGraphMemAttribute_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, hipGraphMemAttributeType, void *);

void btx_register_callbacks_lttng_ust_hip_hipDeviceGetGraphMemAttribute_entry(
    void *btx_handle, lttng_ust_hip_hipDeviceGetGraphMemAttribute_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceGetGraphMemAttribute_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t, void *);

void btx_register_callbacks_lttng_ust_hip_hipDeviceGetGraphMemAttribute_exit(
    void *btx_handle, lttng_ust_hip_hipDeviceGetGraphMemAttribute_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceSetGraphMemAttribute_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, hipGraphMemAttributeType, void *, size_t, void *);

void btx_register_callbacks_lttng_ust_hip_hipDeviceSetGraphMemAttribute_entry(
    void *btx_handle, lttng_ust_hip_hipDeviceSetGraphMemAttribute_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceSetGraphMemAttribute_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipDeviceSetGraphMemAttribute_exit(
    void *btx_handle, lttng_ust_hip_hipDeviceSetGraphMemAttribute_exit_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceGraphMemTrim_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_hip_hipDeviceGraphMemTrim_entry(
    void *btx_handle, lttng_ust_hip_hipDeviceGraphMemTrim_entry_callback_f *callback);

typedef void lttng_ust_hip_hipDeviceGraphMemTrim_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipDeviceGraphMemTrim_exit(
    void *btx_handle, lttng_ust_hip_hipDeviceGraphMemTrim_exit_callback_f *callback);

typedef void lttng_ust_hip_hipUserObjectCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipUserObject_t *, void *, hipHostFn_t, unsigned int, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipUserObjectCreate_entry(
    void *btx_handle, lttng_ust_hip_hipUserObjectCreate_entry_callback_f *callback);

typedef void lttng_ust_hip_hipUserObjectCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipUserObject_t);

void btx_register_callbacks_lttng_ust_hip_hipUserObjectCreate_exit(
    void *btx_handle, lttng_ust_hip_hipUserObjectCreate_exit_callback_f *callback);

typedef void lttng_ust_hip_hipUserObjectRelease_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipUserObject_t, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipUserObjectRelease_entry(
    void *btx_handle, lttng_ust_hip_hipUserObjectRelease_entry_callback_f *callback);

typedef void lttng_ust_hip_hipUserObjectRelease_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipUserObjectRelease_exit(
    void *btx_handle, lttng_ust_hip_hipUserObjectRelease_exit_callback_f *callback);

typedef void lttng_ust_hip_hipUserObjectRetain_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipUserObject_t, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipUserObjectRetain_entry(
    void *btx_handle, lttng_ust_hip_hipUserObjectRetain_entry_callback_f *callback);

typedef void lttng_ust_hip_hipUserObjectRetain_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipUserObjectRetain_exit(
    void *btx_handle, lttng_ust_hip_hipUserObjectRetain_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphRetainUserObject_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraph_t, hipUserObject_t, unsigned int, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipGraphRetainUserObject_entry(
    void *btx_handle, lttng_ust_hip_hipGraphRetainUserObject_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphRetainUserObject_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphRetainUserObject_exit(
    void *btx_handle, lttng_ust_hip_hipGraphRetainUserObject_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphReleaseUserObject_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraph_t, hipUserObject_t, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipGraphReleaseUserObject_entry(
    void *btx_handle, lttng_ust_hip_hipGraphReleaseUserObject_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphReleaseUserObject_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphReleaseUserObject_exit(
    void *btx_handle, lttng_ust_hip_hipGraphReleaseUserObject_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemAddressFree_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, size_t);

void btx_register_callbacks_lttng_ust_hip_hipMemAddressFree_entry(
    void *btx_handle, lttng_ust_hip_hipMemAddressFree_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemAddressFree_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemAddressFree_exit(
    void *btx_handle, lttng_ust_hip_hipMemAddressFree_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemAddressReserve_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void **, size_t, size_t, void *, unsigned long long int);

void btx_register_callbacks_lttng_ust_hip_hipMemAddressReserve_entry(
    void *btx_handle, lttng_ust_hip_hipMemAddressReserve_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemAddressReserve_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, void *);

void btx_register_callbacks_lttng_ust_hip_hipMemAddressReserve_exit(
    void *btx_handle, lttng_ust_hip_hipMemAddressReserve_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipMemGenericAllocationHandle_t *, size_t, hipMemAllocationProp *, unsigned long long int, size_t, hipMemAllocationProp *);

void btx_register_callbacks_lttng_ust_hip_hipMemCreate_entry(
    void *btx_handle, lttng_ust_hip_hipMemCreate_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipMemGenericAllocationHandle_t);

void btx_register_callbacks_lttng_ust_hip_hipMemCreate_exit(
    void *btx_handle, lttng_ust_hip_hipMemCreate_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemExportToShareableHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, hipMemGenericAllocationHandle_t, hipMemAllocationHandleType, unsigned long long int);

void btx_register_callbacks_lttng_ust_hip_hipMemExportToShareableHandle_entry(
    void *btx_handle, lttng_ust_hip_hipMemExportToShareableHandle_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemExportToShareableHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t, void *);

void btx_register_callbacks_lttng_ust_hip_hipMemExportToShareableHandle_exit(
    void *btx_handle, lttng_ust_hip_hipMemExportToShareableHandle_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemGetAccess_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, unsigned long long int *, hipMemLocation *, void *, size_t, hipMemLocation *);

void btx_register_callbacks_lttng_ust_hip_hipMemGetAccess_entry(
    void *btx_handle, lttng_ust_hip_hipMemGetAccess_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemGetAccess_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, unsigned long long int);

void btx_register_callbacks_lttng_ust_hip_hipMemGetAccess_exit(
    void *btx_handle, lttng_ust_hip_hipMemGetAccess_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemGetAllocationGranularity_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, size_t *, hipMemAllocationProp *, hipMemAllocationGranularity_flags, size_t, hipMemAllocationProp *);

void btx_register_callbacks_lttng_ust_hip_hipMemGetAllocationGranularity_entry(
    void *btx_handle, lttng_ust_hip_hipMemGetAllocationGranularity_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemGetAllocationGranularity_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t);

void btx_register_callbacks_lttng_ust_hip_hipMemGetAllocationGranularity_exit(
    void *btx_handle, lttng_ust_hip_hipMemGetAllocationGranularity_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemGetAllocationPropertiesFromHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipMemAllocationProp *, hipMemGenericAllocationHandle_t);

void btx_register_callbacks_lttng_ust_hip_hipMemGetAllocationPropertiesFromHandle_entry(
    void *btx_handle, lttng_ust_hip_hipMemGetAllocationPropertiesFromHandle_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemGetAllocationPropertiesFromHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, size_t, hipMemAllocationProp *);

void btx_register_callbacks_lttng_ust_hip_hipMemGetAllocationPropertiesFromHandle_exit(
    void *btx_handle, lttng_ust_hip_hipMemGetAllocationPropertiesFromHandle_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemImportFromShareableHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipMemGenericAllocationHandle_t *, void *, hipMemAllocationHandleType, size_t, void *);

void btx_register_callbacks_lttng_ust_hip_hipMemImportFromShareableHandle_entry(
    void *btx_handle, lttng_ust_hip_hipMemImportFromShareableHandle_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemImportFromShareableHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipMemGenericAllocationHandle_t);

void btx_register_callbacks_lttng_ust_hip_hipMemImportFromShareableHandle_exit(
    void *btx_handle, lttng_ust_hip_hipMemImportFromShareableHandle_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemMap_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, size_t, size_t, hipMemGenericAllocationHandle_t, unsigned long long int);

void btx_register_callbacks_lttng_ust_hip_hipMemMap_entry(
    void *btx_handle, lttng_ust_hip_hipMemMap_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemMap_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemMap_exit(
    void *btx_handle, lttng_ust_hip_hipMemMap_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemMapArrayAsync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipArrayMapInfo *, unsigned int, hipStream_t, size_t, hipArrayMapInfo *);

void btx_register_callbacks_lttng_ust_hip_hipMemMapArrayAsync_entry(
    void *btx_handle, lttng_ust_hip_hipMemMapArrayAsync_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemMapArrayAsync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemMapArrayAsync_exit(
    void *btx_handle, lttng_ust_hip_hipMemMapArrayAsync_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemRelease_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipMemGenericAllocationHandle_t);

void btx_register_callbacks_lttng_ust_hip_hipMemRelease_entry(
    void *btx_handle, lttng_ust_hip_hipMemRelease_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemRelease_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemRelease_exit(
    void *btx_handle, lttng_ust_hip_hipMemRelease_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemRetainAllocationHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipMemGenericAllocationHandle_t *, void *);

void btx_register_callbacks_lttng_ust_hip_hipMemRetainAllocationHandle_entry(
    void *btx_handle, lttng_ust_hip_hipMemRetainAllocationHandle_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemRetainAllocationHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipMemGenericAllocationHandle_t);

void btx_register_callbacks_lttng_ust_hip_hipMemRetainAllocationHandle_exit(
    void *btx_handle, lttng_ust_hip_hipMemRetainAllocationHandle_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemSetAccess_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, size_t, hipMemAccessDesc *, size_t, size_t, hipMemAccessDesc *);

void btx_register_callbacks_lttng_ust_hip_hipMemSetAccess_entry(
    void *btx_handle, lttng_ust_hip_hipMemSetAccess_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemSetAccess_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemSetAccess_exit(
    void *btx_handle, lttng_ust_hip_hipMemSetAccess_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemUnmap_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, size_t);

void btx_register_callbacks_lttng_ust_hip_hipMemUnmap_entry(
    void *btx_handle, lttng_ust_hip_hipMemUnmap_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemUnmap_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemUnmap_exit(
    void *btx_handle, lttng_ust_hip_hipMemUnmap_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGLGetDevices_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, unsigned int *, int *, unsigned int, hipGLDeviceList);

void btx_register_callbacks_lttng_ust_hip_hipGLGetDevices_entry(
    void *btx_handle, lttng_ust_hip_hipGLGetDevices_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGLGetDevices_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, unsigned int, size_t, int *);

void btx_register_callbacks_lttng_ust_hip_hipGLGetDevices_exit(
    void *btx_handle, lttng_ust_hip_hipGLGetDevices_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphicsGLRegisterBuffer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphicsResource **, GLuint, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipGraphicsGLRegisterBuffer_entry(
    void *btx_handle, lttng_ust_hip_hipGraphicsGLRegisterBuffer_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphicsGLRegisterBuffer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipGraphicsResource *);

void btx_register_callbacks_lttng_ust_hip_hipGraphicsGLRegisterBuffer_exit(
    void *btx_handle, lttng_ust_hip_hipGraphicsGLRegisterBuffer_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphicsGLRegisterImage_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphicsResource **, GLuint, GLenum, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipGraphicsGLRegisterImage_entry(
    void *btx_handle, lttng_ust_hip_hipGraphicsGLRegisterImage_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphicsGLRegisterImage_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipGraphicsResource *);

void btx_register_callbacks_lttng_ust_hip_hipGraphicsGLRegisterImage_exit(
    void *btx_handle, lttng_ust_hip_hipGraphicsGLRegisterImage_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphicsMapResources_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, hipGraphicsResource_t *, hipStream_t, size_t, hipGraphicsResource_t *);

void btx_register_callbacks_lttng_ust_hip_hipGraphicsMapResources_entry(
    void *btx_handle, lttng_ust_hip_hipGraphicsMapResources_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphicsMapResources_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphicsMapResources_exit(
    void *btx_handle, lttng_ust_hip_hipGraphicsMapResources_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphicsSubResourceGetMappedArray_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipArray_t *, hipGraphicsResource_t, unsigned int, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipGraphicsSubResourceGetMappedArray_entry(
    void *btx_handle, lttng_ust_hip_hipGraphicsSubResourceGetMappedArray_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphicsSubResourceGetMappedArray_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipArray_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphicsSubResourceGetMappedArray_exit(
    void *btx_handle, lttng_ust_hip_hipGraphicsSubResourceGetMappedArray_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphicsResourceGetMappedPointer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void **, size_t *, hipGraphicsResource_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphicsResourceGetMappedPointer_entry(
    void *btx_handle, lttng_ust_hip_hipGraphicsResourceGetMappedPointer_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphicsResourceGetMappedPointer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, void *, size_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphicsResourceGetMappedPointer_exit(
    void *btx_handle, lttng_ust_hip_hipGraphicsResourceGetMappedPointer_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphicsUnmapResources_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, hipGraphicsResource_t *, hipStream_t, size_t, hipGraphicsResource_t *);

void btx_register_callbacks_lttng_ust_hip_hipGraphicsUnmapResources_entry(
    void *btx_handle, lttng_ust_hip_hipGraphicsUnmapResources_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphicsUnmapResources_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphicsUnmapResources_exit(
    void *btx_handle, lttng_ust_hip_hipGraphicsUnmapResources_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphicsUnregisterResource_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphicsResource_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphicsUnregisterResource_entry(
    void *btx_handle, lttng_ust_hip_hipGraphicsUnregisterResource_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphicsUnregisterResource_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphicsUnregisterResource_exit(
    void *btx_handle, lttng_ust_hip_hipGraphicsUnregisterResource_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpy_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, size_t, hipMemcpyKind);

void btx_register_callbacks_lttng_ust_hip_hipMemcpy_spt_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpy_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpy_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpy_spt_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpy_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyToSymbol_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, size_t, size_t, hipMemcpyKind);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyToSymbol_spt_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpyToSymbol_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyToSymbol_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyToSymbol_spt_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpyToSymbol_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyFromSymbol_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, size_t, size_t, hipMemcpyKind);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyFromSymbol_spt_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpyFromSymbol_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyFromSymbol_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyFromSymbol_spt_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpyFromSymbol_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpy2D_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, size_t, void *, size_t, size_t, size_t, hipMemcpyKind);

void btx_register_callbacks_lttng_ust_hip_hipMemcpy2D_spt_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpy2D_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpy2D_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpy2D_spt_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpy2D_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpy2DFromArray_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, size_t, hipArray_const_t, size_t, size_t, size_t, size_t, hipMemcpyKind);

void btx_register_callbacks_lttng_ust_hip_hipMemcpy2DFromArray_spt_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpy2DFromArray_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpy2DFromArray_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpy2DFromArray_spt_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpy2DFromArray_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpy3D_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, struct hipMemcpy3DParms *);

void btx_register_callbacks_lttng_ust_hip_hipMemcpy3D_spt_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpy3D_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpy3D_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpy3D_spt_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpy3D_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemset_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, size_t);

void btx_register_callbacks_lttng_ust_hip_hipMemset_spt_entry(
    void *btx_handle, lttng_ust_hip_hipMemset_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemset_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemset_spt_exit(
    void *btx_handle, lttng_ust_hip_hipMemset_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemsetAsync_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, size_t, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipMemsetAsync_spt_entry(
    void *btx_handle, lttng_ust_hip_hipMemsetAsync_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemsetAsync_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemsetAsync_spt_exit(
    void *btx_handle, lttng_ust_hip_hipMemsetAsync_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemset2D_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, size_t, int, size_t, size_t);

void btx_register_callbacks_lttng_ust_hip_hipMemset2D_spt_entry(
    void *btx_handle, lttng_ust_hip_hipMemset2D_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemset2D_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemset2D_spt_exit(
    void *btx_handle, lttng_ust_hip_hipMemset2D_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemset2DAsync_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, size_t, int, size_t, size_t, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipMemset2DAsync_spt_entry(
    void *btx_handle, lttng_ust_hip_hipMemset2DAsync_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemset2DAsync_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemset2DAsync_spt_exit(
    void *btx_handle, lttng_ust_hip_hipMemset2DAsync_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemset3DAsync_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipPitchedPtr, int, hipExtent, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipMemset3DAsync_spt_entry(
    void *btx_handle, lttng_ust_hip_hipMemset3DAsync_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemset3DAsync_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemset3DAsync_spt_exit(
    void *btx_handle, lttng_ust_hip_hipMemset3DAsync_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemset3D_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipPitchedPtr, int, hipExtent);

void btx_register_callbacks_lttng_ust_hip_hipMemset3D_spt_entry(
    void *btx_handle, lttng_ust_hip_hipMemset3D_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemset3D_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemset3D_spt_exit(
    void *btx_handle, lttng_ust_hip_hipMemset3D_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyAsync_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, size_t, hipMemcpyKind, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyAsync_spt_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpyAsync_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyAsync_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyAsync_spt_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpyAsync_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpy3DAsync_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipMemcpy3DParms *, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpy3DAsync_spt_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpy3DAsync_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpy3DAsync_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpy3DAsync_spt_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpy3DAsync_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpy2DAsync_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, size_t, void *, size_t, size_t, size_t, hipMemcpyKind, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpy2DAsync_spt_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpy2DAsync_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpy2DAsync_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpy2DAsync_spt_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpy2DAsync_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyFromSymbolAsync_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, size_t, size_t, hipMemcpyKind, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyFromSymbolAsync_spt_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpyFromSymbolAsync_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyFromSymbolAsync_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyFromSymbolAsync_spt_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpyFromSymbolAsync_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyToSymbolAsync_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, size_t, size_t, hipMemcpyKind, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyToSymbolAsync_spt_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpyToSymbolAsync_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyToSymbolAsync_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyToSymbolAsync_spt_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpyToSymbolAsync_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyFromArray_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, hipArray_const_t, size_t, size_t, size_t, hipMemcpyKind);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyFromArray_spt_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpyFromArray_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpyFromArray_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpyFromArray_spt_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpyFromArray_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpy2DToArray_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipArray *, size_t, size_t, void *, size_t, size_t, size_t, hipMemcpyKind);

void btx_register_callbacks_lttng_ust_hip_hipMemcpy2DToArray_spt_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpy2DToArray_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpy2DToArray_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpy2DToArray_spt_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpy2DToArray_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpy2DFromArrayAsync_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, size_t, hipArray_const_t, size_t, size_t, size_t, size_t, hipMemcpyKind, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpy2DFromArrayAsync_spt_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpy2DFromArrayAsync_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpy2DFromArrayAsync_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpy2DFromArrayAsync_spt_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpy2DFromArrayAsync_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpy2DToArrayAsync_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipArray *, size_t, size_t, void *, size_t, size_t, size_t, hipMemcpyKind, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpy2DToArrayAsync_spt_entry(
    void *btx_handle, lttng_ust_hip_hipMemcpy2DToArrayAsync_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipMemcpy2DToArrayAsync_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipMemcpy2DToArrayAsync_spt_exit(
    void *btx_handle, lttng_ust_hip_hipMemcpy2DToArrayAsync_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hipStreamQuery_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipStreamQuery_spt_entry(
    void *btx_handle, lttng_ust_hip_hipStreamQuery_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipStreamQuery_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipStreamQuery_spt_exit(
    void *btx_handle, lttng_ust_hip_hipStreamQuery_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hipStreamSynchronize_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipStreamSynchronize_spt_entry(
    void *btx_handle, lttng_ust_hip_hipStreamSynchronize_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipStreamSynchronize_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipStreamSynchronize_spt_exit(
    void *btx_handle, lttng_ust_hip_hipStreamSynchronize_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hipStreamGetPriority_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t, int *);

void btx_register_callbacks_lttng_ust_hip_hipStreamGetPriority_spt_entry(
    void *btx_handle, lttng_ust_hip_hipStreamGetPriority_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipStreamGetPriority_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipStreamGetPriority_spt_exit(
    void *btx_handle, lttng_ust_hip_hipStreamGetPriority_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hipStreamWaitEvent_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t, hipEvent_t, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipStreamWaitEvent_spt_entry(
    void *btx_handle, lttng_ust_hip_hipStreamWaitEvent_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipStreamWaitEvent_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipStreamWaitEvent_spt_exit(
    void *btx_handle, lttng_ust_hip_hipStreamWaitEvent_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hipStreamGetFlags_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t, unsigned int *);

void btx_register_callbacks_lttng_ust_hip_hipStreamGetFlags_spt_entry(
    void *btx_handle, lttng_ust_hip_hipStreamGetFlags_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipStreamGetFlags_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipStreamGetFlags_spt_exit(
    void *btx_handle, lttng_ust_hip_hipStreamGetFlags_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hipStreamAddCallback_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t, hipStreamCallback_t, void *, unsigned int);

void btx_register_callbacks_lttng_ust_hip_hipStreamAddCallback_spt_entry(
    void *btx_handle, lttng_ust_hip_hipStreamAddCallback_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipStreamAddCallback_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipStreamAddCallback_spt_exit(
    void *btx_handle, lttng_ust_hip_hipStreamAddCallback_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hipEventRecord_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipEvent_t, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipEventRecord_spt_entry(
    void *btx_handle, lttng_ust_hip_hipEventRecord_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipEventRecord_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipEventRecord_spt_exit(
    void *btx_handle, lttng_ust_hip_hipEventRecord_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hipLaunchCooperativeKernel_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, dim3, dim3, void **, uint32_t, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipLaunchCooperativeKernel_spt_entry(
    void *btx_handle, lttng_ust_hip_hipLaunchCooperativeKernel_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipLaunchCooperativeKernel_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipLaunchCooperativeKernel_spt_exit(
    void *btx_handle, lttng_ust_hip_hipLaunchCooperativeKernel_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hipLaunchKernel_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, dim3, dim3, void **, size_t, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipLaunchKernel_spt_entry(
    void *btx_handle, lttng_ust_hip_hipLaunchKernel_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipLaunchKernel_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipLaunchKernel_spt_exit(
    void *btx_handle, lttng_ust_hip_hipLaunchKernel_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphLaunch_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraphExec_t, hipStream_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphLaunch_spt_entry(
    void *btx_handle, lttng_ust_hip_hipGraphLaunch_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphLaunch_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphLaunch_spt_exit(
    void *btx_handle, lttng_ust_hip_hipGraphLaunch_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hipStreamBeginCapture_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t, hipStreamCaptureMode);

void btx_register_callbacks_lttng_ust_hip_hipStreamBeginCapture_spt_entry(
    void *btx_handle, lttng_ust_hip_hipStreamBeginCapture_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipStreamBeginCapture_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipStreamBeginCapture_spt_exit(
    void *btx_handle, lttng_ust_hip_hipStreamBeginCapture_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hipStreamEndCapture_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t, hipGraph_t *);

void btx_register_callbacks_lttng_ust_hip_hipStreamEndCapture_spt_entry(
    void *btx_handle, lttng_ust_hip_hipStreamEndCapture_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipStreamEndCapture_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipStreamEndCapture_spt_exit(
    void *btx_handle, lttng_ust_hip_hipStreamEndCapture_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hipStreamIsCapturing_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t, hipStreamCaptureStatus *);

void btx_register_callbacks_lttng_ust_hip_hipStreamIsCapturing_spt_entry(
    void *btx_handle, lttng_ust_hip_hipStreamIsCapturing_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipStreamIsCapturing_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipStreamIsCapturing_spt_exit(
    void *btx_handle, lttng_ust_hip_hipStreamIsCapturing_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hipStreamGetCaptureInfo_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t, hipStreamCaptureStatus *, unsigned long long int *);

void btx_register_callbacks_lttng_ust_hip_hipStreamGetCaptureInfo_spt_entry(
    void *btx_handle, lttng_ust_hip_hipStreamGetCaptureInfo_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipStreamGetCaptureInfo_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipStreamGetCaptureInfo_spt_exit(
    void *btx_handle, lttng_ust_hip_hipStreamGetCaptureInfo_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hipStreamGetCaptureInfo_v2_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t, hipStreamCaptureStatus *, unsigned long long int *, hipGraph_t *, hipGraphNode_t **, size_t *);

void btx_register_callbacks_lttng_ust_hip_hipStreamGetCaptureInfo_v2_spt_entry(
    void *btx_handle, lttng_ust_hip_hipStreamGetCaptureInfo_v2_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipStreamGetCaptureInfo_v2_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipStreamGetCaptureInfo_v2_spt_exit(
    void *btx_handle, lttng_ust_hip_hipStreamGetCaptureInfo_v2_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hipLaunchHostFunc_spt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipStream_t, hipHostFn_t, void *);

void btx_register_callbacks_lttng_ust_hip_hipLaunchHostFunc_spt_entry(
    void *btx_handle, lttng_ust_hip_hipLaunchHostFunc_spt_entry_callback_f *callback);

typedef void lttng_ust_hip_hipLaunchHostFunc_spt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipLaunchHostFunc_spt_exit(
    void *btx_handle, lttng_ust_hip_hipLaunchHostFunc_spt_exit_callback_f *callback);

typedef void lttng_ust_hip_hiprtcGetErrorString_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hiprtcResult);

void btx_register_callbacks_lttng_ust_hip_hiprtcGetErrorString_entry(
    void *btx_handle, lttng_ust_hip_hiprtcGetErrorString_entry_callback_f *callback);

typedef void lttng_ust_hip_hiprtcGetErrorString_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *);

void btx_register_callbacks_lttng_ust_hip_hiprtcGetErrorString_exit(
    void *btx_handle, lttng_ust_hip_hiprtcGetErrorString_exit_callback_f *callback);

typedef void lttng_ust_hip_hiprtcVersion_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, int *);

void btx_register_callbacks_lttng_ust_hip_hiprtcVersion_entry(
    void *btx_handle, lttng_ust_hip_hiprtcVersion_entry_callback_f *callback);

typedef void lttng_ust_hip_hiprtcVersion_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hiprtcResult);

void btx_register_callbacks_lttng_ust_hip_hiprtcVersion_exit(
    void *btx_handle, lttng_ust_hip_hiprtcVersion_exit_callback_f *callback);

typedef void lttng_ust_hip_hiprtcAddNameExpression_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hiprtcProgram, char *);

void btx_register_callbacks_lttng_ust_hip_hiprtcAddNameExpression_entry(
    void *btx_handle, lttng_ust_hip_hiprtcAddNameExpression_entry_callback_f *callback);

typedef void lttng_ust_hip_hiprtcAddNameExpression_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hiprtcResult);

void btx_register_callbacks_lttng_ust_hip_hiprtcAddNameExpression_exit(
    void *btx_handle, lttng_ust_hip_hiprtcAddNameExpression_exit_callback_f *callback);

typedef void lttng_ust_hip_hiprtcCompileProgram_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hiprtcProgram, int, char **);

void btx_register_callbacks_lttng_ust_hip_hiprtcCompileProgram_entry(
    void *btx_handle, lttng_ust_hip_hiprtcCompileProgram_entry_callback_f *callback);

typedef void lttng_ust_hip_hiprtcCompileProgram_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hiprtcResult);

void btx_register_callbacks_lttng_ust_hip_hiprtcCompileProgram_exit(
    void *btx_handle, lttng_ust_hip_hiprtcCompileProgram_exit_callback_f *callback);

typedef void lttng_ust_hip_hiprtcCreateProgram_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hiprtcProgram *, char *, char *, int, char **, char **);

void btx_register_callbacks_lttng_ust_hip_hiprtcCreateProgram_entry(
    void *btx_handle, lttng_ust_hip_hiprtcCreateProgram_entry_callback_f *callback);

typedef void lttng_ust_hip_hiprtcCreateProgram_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hiprtcResult);

void btx_register_callbacks_lttng_ust_hip_hiprtcCreateProgram_exit(
    void *btx_handle, lttng_ust_hip_hiprtcCreateProgram_exit_callback_f *callback);

typedef void lttng_ust_hip_hiprtcDestroyProgram_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hiprtcProgram *);

void btx_register_callbacks_lttng_ust_hip_hiprtcDestroyProgram_entry(
    void *btx_handle, lttng_ust_hip_hiprtcDestroyProgram_entry_callback_f *callback);

typedef void lttng_ust_hip_hiprtcDestroyProgram_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hiprtcResult);

void btx_register_callbacks_lttng_ust_hip_hiprtcDestroyProgram_exit(
    void *btx_handle, lttng_ust_hip_hiprtcDestroyProgram_exit_callback_f *callback);

typedef void lttng_ust_hip_hiprtcGetLoweredName_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hiprtcProgram, char *, char **);

void btx_register_callbacks_lttng_ust_hip_hiprtcGetLoweredName_entry(
    void *btx_handle, lttng_ust_hip_hiprtcGetLoweredName_entry_callback_f *callback);

typedef void lttng_ust_hip_hiprtcGetLoweredName_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hiprtcResult);

void btx_register_callbacks_lttng_ust_hip_hiprtcGetLoweredName_exit(
    void *btx_handle, lttng_ust_hip_hiprtcGetLoweredName_exit_callback_f *callback);

typedef void lttng_ust_hip_hiprtcGetProgramLog_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hiprtcProgram, char *);

void btx_register_callbacks_lttng_ust_hip_hiprtcGetProgramLog_entry(
    void *btx_handle, lttng_ust_hip_hiprtcGetProgramLog_entry_callback_f *callback);

typedef void lttng_ust_hip_hiprtcGetProgramLog_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hiprtcResult);

void btx_register_callbacks_lttng_ust_hip_hiprtcGetProgramLog_exit(
    void *btx_handle, lttng_ust_hip_hiprtcGetProgramLog_exit_callback_f *callback);

typedef void lttng_ust_hip_hiprtcGetProgramLogSize_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hiprtcProgram, size_t *);

void btx_register_callbacks_lttng_ust_hip_hiprtcGetProgramLogSize_entry(
    void *btx_handle, lttng_ust_hip_hiprtcGetProgramLogSize_entry_callback_f *callback);

typedef void lttng_ust_hip_hiprtcGetProgramLogSize_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hiprtcResult);

void btx_register_callbacks_lttng_ust_hip_hiprtcGetProgramLogSize_exit(
    void *btx_handle, lttng_ust_hip_hiprtcGetProgramLogSize_exit_callback_f *callback);

typedef void lttng_ust_hip_hiprtcGetCode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hiprtcProgram, char *);

void btx_register_callbacks_lttng_ust_hip_hiprtcGetCode_entry(
    void *btx_handle, lttng_ust_hip_hiprtcGetCode_entry_callback_f *callback);

typedef void lttng_ust_hip_hiprtcGetCode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hiprtcResult);

void btx_register_callbacks_lttng_ust_hip_hiprtcGetCode_exit(
    void *btx_handle, lttng_ust_hip_hiprtcGetCode_exit_callback_f *callback);

typedef void lttng_ust_hip_hiprtcGetCodeSize_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hiprtcProgram, size_t *);

void btx_register_callbacks_lttng_ust_hip_hiprtcGetCodeSize_entry(
    void *btx_handle, lttng_ust_hip_hiprtcGetCodeSize_entry_callback_f *callback);

typedef void lttng_ust_hip_hiprtcGetCodeSize_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hiprtcResult);

void btx_register_callbacks_lttng_ust_hip_hiprtcGetCodeSize_exit(
    void *btx_handle, lttng_ust_hip_hiprtcGetCodeSize_exit_callback_f *callback);

typedef void lttng_ust_hip_hiprtcGetBitcode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hiprtcProgram, char *);

void btx_register_callbacks_lttng_ust_hip_hiprtcGetBitcode_entry(
    void *btx_handle, lttng_ust_hip_hiprtcGetBitcode_entry_callback_f *callback);

typedef void lttng_ust_hip_hiprtcGetBitcode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hiprtcResult);

void btx_register_callbacks_lttng_ust_hip_hiprtcGetBitcode_exit(
    void *btx_handle, lttng_ust_hip_hiprtcGetBitcode_exit_callback_f *callback);

typedef void lttng_ust_hip_hiprtcGetBitcodeSize_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hiprtcProgram, size_t *);

void btx_register_callbacks_lttng_ust_hip_hiprtcGetBitcodeSize_entry(
    void *btx_handle, lttng_ust_hip_hiprtcGetBitcodeSize_entry_callback_f *callback);

typedef void lttng_ust_hip_hiprtcGetBitcodeSize_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hiprtcResult);

void btx_register_callbacks_lttng_ust_hip_hiprtcGetBitcodeSize_exit(
    void *btx_handle, lttng_ust_hip_hiprtcGetBitcodeSize_exit_callback_f *callback);

typedef void lttng_ust_hip_hiprtcLinkCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, unsigned int, hiprtcJIT_option *, void **, hiprtcLinkState *);

void btx_register_callbacks_lttng_ust_hip_hiprtcLinkCreate_entry(
    void *btx_handle, lttng_ust_hip_hiprtcLinkCreate_entry_callback_f *callback);

typedef void lttng_ust_hip_hiprtcLinkCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hiprtcResult);

void btx_register_callbacks_lttng_ust_hip_hiprtcLinkCreate_exit(
    void *btx_handle, lttng_ust_hip_hiprtcLinkCreate_exit_callback_f *callback);

typedef void lttng_ust_hip_hiprtcLinkAddFile_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hiprtcLinkState, hiprtcJITInputType, char *, unsigned int, hiprtcJIT_option *, void **);

void btx_register_callbacks_lttng_ust_hip_hiprtcLinkAddFile_entry(
    void *btx_handle, lttng_ust_hip_hiprtcLinkAddFile_entry_callback_f *callback);

typedef void lttng_ust_hip_hiprtcLinkAddFile_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hiprtcResult);

void btx_register_callbacks_lttng_ust_hip_hiprtcLinkAddFile_exit(
    void *btx_handle, lttng_ust_hip_hiprtcLinkAddFile_exit_callback_f *callback);

typedef void lttng_ust_hip_hiprtcLinkAddData_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hiprtcLinkState, hiprtcJITInputType, void *, size_t, char *, unsigned int, hiprtcJIT_option *, void **);

void btx_register_callbacks_lttng_ust_hip_hiprtcLinkAddData_entry(
    void *btx_handle, lttng_ust_hip_hiprtcLinkAddData_entry_callback_f *callback);

typedef void lttng_ust_hip_hiprtcLinkAddData_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hiprtcResult);

void btx_register_callbacks_lttng_ust_hip_hiprtcLinkAddData_exit(
    void *btx_handle, lttng_ust_hip_hiprtcLinkAddData_exit_callback_f *callback);

typedef void lttng_ust_hip_hiprtcLinkComplete_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hiprtcLinkState, void **, size_t *);

void btx_register_callbacks_lttng_ust_hip_hiprtcLinkComplete_entry(
    void *btx_handle, lttng_ust_hip_hiprtcLinkComplete_entry_callback_f *callback);

typedef void lttng_ust_hip_hiprtcLinkComplete_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hiprtcResult);

void btx_register_callbacks_lttng_ust_hip_hiprtcLinkComplete_exit(
    void *btx_handle, lttng_ust_hip_hiprtcLinkComplete_exit_callback_f *callback);

typedef void lttng_ust_hip_hiprtcLinkDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hiprtcLinkState);

void btx_register_callbacks_lttng_ust_hip_hiprtcLinkDestroy_entry(
    void *btx_handle, lttng_ust_hip_hiprtcLinkDestroy_entry_callback_f *callback);

typedef void lttng_ust_hip_hiprtcLinkDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hiprtcResult);

void btx_register_callbacks_lttng_ust_hip_hiprtcLinkDestroy_exit(
    void *btx_handle, lttng_ust_hip_hiprtcLinkDestroy_exit_callback_f *callback);

typedef void lttng_ust_hip_amd_dbgapi_get_build_name_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_hip_amd_dbgapi_get_build_name_entry(
    void *btx_handle, lttng_ust_hip_amd_dbgapi_get_build_name_entry_callback_f *callback);

typedef void lttng_ust_hip_amd_dbgapi_get_build_name_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, char *);

void btx_register_callbacks_lttng_ust_hip_amd_dbgapi_get_build_name_exit(
    void *btx_handle, lttng_ust_hip_amd_dbgapi_get_build_name_exit_callback_f *callback);

typedef void lttng_ust_hip_amd_dbgapi_get_git_hash_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_hip_amd_dbgapi_get_git_hash_entry(
    void *btx_handle, lttng_ust_hip_amd_dbgapi_get_git_hash_entry_callback_f *callback);

typedef void lttng_ust_hip_amd_dbgapi_get_git_hash_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, char *);

void btx_register_callbacks_lttng_ust_hip_amd_dbgapi_get_git_hash_exit(
    void *btx_handle, lttng_ust_hip_amd_dbgapi_get_git_hash_exit_callback_f *callback);

typedef void lttng_ust_hip_amd_dbgapi_get_build_id_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_hip_amd_dbgapi_get_build_id_entry(
    void *btx_handle, lttng_ust_hip_amd_dbgapi_get_build_id_entry_callback_f *callback);

typedef void lttng_ust_hip_amd_dbgapi_get_build_id_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, size_t);

void btx_register_callbacks_lttng_ust_hip_amd_dbgapi_get_build_id_exit(
    void *btx_handle, lttng_ust_hip_amd_dbgapi_get_build_id_exit_callback_f *callback);

typedef void lttng_ust_hip_hipExtModuleLaunchKernel_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipFunction_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, size_t, hipStream_t, void **, void **, hipEvent_t, hipEvent_t, uint32_t);

void btx_register_callbacks_lttng_ust_hip_hipExtModuleLaunchKernel_entry(
    void *btx_handle, lttng_ust_hip_hipExtModuleLaunchKernel_entry_callback_f *callback);

typedef void lttng_ust_hip_hipExtModuleLaunchKernel_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipExtModuleLaunchKernel_exit(
    void *btx_handle, lttng_ust_hip_hipExtModuleLaunchKernel_exit_callback_f *callback);

typedef void lttng_ust_hip_hipHccModuleLaunchKernel_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipFunction_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, size_t, hipStream_t, void **, void **, hipEvent_t, hipEvent_t);

void btx_register_callbacks_lttng_ust_hip_hipHccModuleLaunchKernel_entry(
    void *btx_handle, lttng_ust_hip_hipHccModuleLaunchKernel_entry_callback_f *callback);

typedef void lttng_ust_hip_hipHccModuleLaunchKernel_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipHccModuleLaunchKernel_exit(
    void *btx_handle, lttng_ust_hip_hipHccModuleLaunchKernel_exit_callback_f *callback);

typedef void lttng_ust_hip__ZN8hip_impl22hipLaunchKernelGGLImplEmRK4dim3S2_jP12ihipStream_tPPv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, uintptr_t, dim3 *, dim3 *, uint32_t, hipStream_t, void **, size_t, dim3 *, size_t, dim3 *);

void btx_register_callbacks_lttng_ust_hip__ZN8hip_impl22hipLaunchKernelGGLImplEmRK4dim3S2_jP12ihipStream_tPPv_entry(
    void *btx_handle, lttng_ust_hip__ZN8hip_impl22hipLaunchKernelGGLImplEmRK4dim3S2_jP12ihipStream_tPPv_entry_callback_f *callback);

typedef void lttng_ust_hip__ZN8hip_impl22hipLaunchKernelGGLImplEmRK4dim3S2_jP12ihipStream_tPPv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_hip__ZN8hip_impl22hipLaunchKernelGGLImplEmRK4dim3S2_jP12ihipStream_tPPv_exit(
    void *btx_handle, lttng_ust_hip__ZN8hip_impl22hipLaunchKernelGGLImplEmRK4dim3S2_jP12ihipStream_tPPv_exit_callback_f *callback);

typedef void lttng_ust_hip__Z22hipCreateSurfaceObjectPP13__hip_surfacePK15hipResourceDesc_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipSurfaceObject_t *, hipResourceDesc *, size_t, hipResourceDesc *);

void btx_register_callbacks_lttng_ust_hip__Z22hipCreateSurfaceObjectPP13__hip_surfacePK15hipResourceDesc_entry(
    void *btx_handle, lttng_ust_hip__Z22hipCreateSurfaceObjectPP13__hip_surfacePK15hipResourceDesc_entry_callback_f *callback);

typedef void lttng_ust_hip__Z22hipCreateSurfaceObjectPP13__hip_surfacePK15hipResourceDesc_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t, hipSurfaceObject_t);

void btx_register_callbacks_lttng_ust_hip__Z22hipCreateSurfaceObjectPP13__hip_surfacePK15hipResourceDesc_exit(
    void *btx_handle, lttng_ust_hip__Z22hipCreateSurfaceObjectPP13__hip_surfacePK15hipResourceDesc_exit_callback_f *callback);

typedef void lttng_ust_hip__Z23hipDestroySurfaceObjectP13__hip_surface_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipSurfaceObject_t);

void btx_register_callbacks_lttng_ust_hip__Z23hipDestroySurfaceObjectP13__hip_surface_entry(
    void *btx_handle, lttng_ust_hip__Z23hipDestroySurfaceObjectP13__hip_surface_entry_callback_f *callback);

typedef void lttng_ust_hip__Z23hipDestroySurfaceObjectP13__hip_surface_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip__Z23hipDestroySurfaceObjectP13__hip_surface_exit(
    void *btx_handle, lttng_ust_hip__Z23hipDestroySurfaceObjectP13__hip_surface_exit_callback_f *callback);

typedef void lttng_ust_hip__Z24hipHccModuleLaunchKernelP18ihipModuleSymbol_tjjjjjjmP12ihipStream_tPPvS4_P11ihipEvent_tS6__entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipFunction_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, size_t, hipStream_t, void **, void **, hipEvent_t, hipEvent_t);

void btx_register_callbacks_lttng_ust_hip__Z24hipHccModuleLaunchKernelP18ihipModuleSymbol_tjjjjjjmP12ihipStream_tPPvS4_P11ihipEvent_tS6__entry(
    void *btx_handle, lttng_ust_hip__Z24hipHccModuleLaunchKernelP18ihipModuleSymbol_tjjjjjjmP12ihipStream_tPPvS4_P11ihipEvent_tS6__entry_callback_f *callback);

typedef void lttng_ust_hip__Z24hipHccModuleLaunchKernelP18ihipModuleSymbol_tjjjjjjmP12ihipStream_tPPvS4_P11ihipEvent_tS6__exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip__Z24hipHccModuleLaunchKernelP18ihipModuleSymbol_tjjjjjjmP12ihipStream_tPPvS4_P11ihipEvent_tS6__exit(
    void *btx_handle, lttng_ust_hip__Z24hipHccModuleLaunchKernelP18ihipModuleSymbol_tjjjjjjmP12ihipStream_tPPvS4_P11ihipEvent_tS6__exit_callback_f *callback);

typedef void lttng_ust_hip__Z24hipExtModuleLaunchKernelP18ihipModuleSymbol_tjjjjjjmP12ihipStream_tPPvS4_P11ihipEvent_tS6_j_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipFunction_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, size_t, hipStream_t, void **, void **, hipEvent_t, hipEvent_t, uint32_t);

void btx_register_callbacks_lttng_ust_hip__Z24hipExtModuleLaunchKernelP18ihipModuleSymbol_tjjjjjjmP12ihipStream_tPPvS4_P11ihipEvent_tS6_j_entry(
    void *btx_handle, lttng_ust_hip__Z24hipExtModuleLaunchKernelP18ihipModuleSymbol_tjjjjjjmP12ihipStream_tPPvS4_P11ihipEvent_tS6_j_entry_callback_f *callback);

typedef void lttng_ust_hip__Z24hipExtModuleLaunchKernelP18ihipModuleSymbol_tjjjjjjmP12ihipStream_tPPvS4_P11ihipEvent_tS6_j_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip__Z24hipExtModuleLaunchKernelP18ihipModuleSymbol_tjjjjjjmP12ihipStream_tPPvS4_P11ihipEvent_tS6_j_exit(
    void *btx_handle, lttng_ust_hip__Z24hipExtModuleLaunchKernelP18ihipModuleSymbol_tjjjjjjmP12ihipStream_tPPvS4_P11ihipEvent_tS6_j_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGraphDebugDotPrint_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipGraph_t, char *, unsigned int, char *);

void btx_register_callbacks_lttng_ust_hip_hipGraphDebugDotPrint_entry(
    void *btx_handle, lttng_ust_hip_hipGraphDebugDotPrint_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGraphDebugDotPrint_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_lttng_ust_hip_hipGraphDebugDotPrint_exit(
    void *btx_handle, lttng_ust_hip_hipGraphDebugDotPrint_exit_callback_f *callback);

typedef void lttng_ust_hip___hipRegisterFatBinary_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *);

void btx_register_callbacks_lttng_ust_hip___hipRegisterFatBinary_entry(
    void *btx_handle, lttng_ust_hip___hipRegisterFatBinary_entry_callback_f *callback);

typedef void lttng_ust_hip___hipRegisterFatBinary_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void **);

void btx_register_callbacks_lttng_ust_hip___hipRegisterFatBinary_exit(
    void *btx_handle, lttng_ust_hip___hipRegisterFatBinary_exit_callback_f *callback);

typedef void lttng_ust_hip___hipRegisterFunction_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void **, void *, char *, char *, unsigned int, uint3 *, uint3 *, dim3 *, dim3 *, int *);

void btx_register_callbacks_lttng_ust_hip___hipRegisterFunction_entry(
    void *btx_handle, lttng_ust_hip___hipRegisterFunction_entry_callback_f *callback);

typedef void lttng_ust_hip___hipRegisterFunction_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_hip___hipRegisterFunction_exit(
    void *btx_handle, lttng_ust_hip___hipRegisterFunction_exit_callback_f *callback);

typedef void lttng_ust_hip___hipRegisterManagedVar_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void **, void **, void *, char *, size_t, unsigned int);

void btx_register_callbacks_lttng_ust_hip___hipRegisterManagedVar_entry(
    void *btx_handle, lttng_ust_hip___hipRegisterManagedVar_entry_callback_f *callback);

typedef void lttng_ust_hip___hipRegisterManagedVar_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_hip___hipRegisterManagedVar_exit(
    void *btx_handle, lttng_ust_hip___hipRegisterManagedVar_exit_callback_f *callback);

typedef void lttng_ust_hip___hipRegisterSurface_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void **, void *, char *, char *, int, int);

void btx_register_callbacks_lttng_ust_hip___hipRegisterSurface_entry(
    void *btx_handle, lttng_ust_hip___hipRegisterSurface_entry_callback_f *callback);

typedef void lttng_ust_hip___hipRegisterSurface_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_hip___hipRegisterSurface_exit(
    void *btx_handle, lttng_ust_hip___hipRegisterSurface_exit_callback_f *callback);

typedef void lttng_ust_hip___hipRegisterTexture_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void **, void *, char *, char *, int, int, int);

void btx_register_callbacks_lttng_ust_hip___hipRegisterTexture_entry(
    void *btx_handle, lttng_ust_hip___hipRegisterTexture_entry_callback_f *callback);

typedef void lttng_ust_hip___hipRegisterTexture_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_hip___hipRegisterTexture_exit(
    void *btx_handle, lttng_ust_hip___hipRegisterTexture_exit_callback_f *callback);

typedef void lttng_ust_hip___hipRegisterVar_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void **, void *, char *, char *, int, size_t, int, int);

void btx_register_callbacks_lttng_ust_hip___hipRegisterVar_entry(
    void *btx_handle, lttng_ust_hip___hipRegisterVar_entry_callback_f *callback);

typedef void lttng_ust_hip___hipRegisterVar_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_hip___hipRegisterVar_exit(
    void *btx_handle, lttng_ust_hip___hipRegisterVar_exit_callback_f *callback);

typedef void lttng_ust_hip___hipUnregisterFatBinary_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void **);

void btx_register_callbacks_lttng_ust_hip___hipUnregisterFatBinary_entry(
    void *btx_handle, lttng_ust_hip___hipUnregisterFatBinary_entry_callback_f *callback);

typedef void lttng_ust_hip___hipUnregisterFatBinary_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_hip___hipUnregisterFatBinary_exit(
    void *btx_handle, lttng_ust_hip___hipUnregisterFatBinary_exit_callback_f *callback);

typedef void lttng_ust_hip_hipGetCmdName_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, uint32_t);

void btx_register_callbacks_lttng_ust_hip_hipGetCmdName_entry(
    void *btx_handle, lttng_ust_hip_hipGetCmdName_entry_callback_f *callback);

typedef void lttng_ust_hip_hipGetCmdName_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *);

void btx_register_callbacks_lttng_ust_hip_hipGetCmdName_exit(
    void *btx_handle, lttng_ust_hip_hipGetCmdName_exit_callback_f *callback);

typedef void lttng_ust_hip_hipRegisterTracerCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, hipRegisterTracerCallback_callback_t *);

void btx_register_callbacks_lttng_ust_hip_hipRegisterTracerCallback_entry(
    void *btx_handle, lttng_ust_hip_hipRegisterTracerCallback_entry_callback_f *callback);

typedef void lttng_ust_hip_hipRegisterTracerCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_hip_hipRegisterTracerCallback_exit(
    void *btx_handle, lttng_ust_hip_hipRegisterTracerCallback_exit_callback_f *callback);

typedef void entries_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t);

void btx_register_callbacks_entries(
    void *btx_handle, entries_callback_f *callback);

typedef void exits_hipError_present_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, hipError_t);

void btx_register_callbacks_exits_hipError_present(
    void *btx_handle, exits_hipError_present_callback_f *callback);

typedef void exits_hipError_absent_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t);

void btx_register_callbacks_exits_hipError_absent(
    void *btx_handle, exits_hipError_absent_callback_f *callback);

void btx_unregister_callbacks(common_data_t *common_data);

#ifdef __cplusplus
}
#endif
