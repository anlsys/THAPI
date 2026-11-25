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

void btx_push_message_lttng_ust_hip_hipCreateChannelDesc_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int x, int y, int z, int w, enum hipChannelFormatKind f);
void btx_push_message_lttng_ust_hip_hipCreateChannelDesc_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, struct hipChannelFormatDesc hipResult);
void btx_push_message_lttng_ust_hip___hipGetPCH_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, char ** pch, unsigned int * size);
void btx_push_message_lttng_ust_hip___hipGetPCH_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_hip_hipInit_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, unsigned int flags);
void btx_push_message_lttng_ust_hip_hipInit_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipDriverGetVersion_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * driverVersion);
void btx_push_message_lttng_ust_hip_hipDriverGetVersion_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, int driverVersion_val);
void btx_push_message_lttng_ust_hip_hipRuntimeGetVersion_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * runtimeVersion);
void btx_push_message_lttng_ust_hip_hipRuntimeGetVersion_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, int runtimeVersion_val);
void btx_push_message_lttng_ust_hip_hipDeviceGet_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipDevice_t * device, int ordinal);
void btx_push_message_lttng_ust_hip_hipDeviceGet_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipDevice_t device_val);
void btx_push_message_lttng_ust_hip_hipDeviceComputeCapability_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * major, int * minor, hipDevice_t device);
void btx_push_message_lttng_ust_hip_hipDeviceComputeCapability_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, int major_val, int minor_val);
void btx_push_message_lttng_ust_hip_hipDeviceGetName_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, char * name, int len, hipDevice_t device);
void btx_push_message_lttng_ust_hip_hipDeviceGetName_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, char * name_val);
void btx_push_message_lttng_ust_hip_hipDeviceGetUuid_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipUUID * uuid, hipDevice_t device);
void btx_push_message_lttng_ust_hip_hipDeviceGetUuid_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t _uuid_val_length, hipUUID * uuid_val);
void btx_push_message_lttng_ust_hip_hipDeviceGetP2PAttribute_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * value, hipDeviceP2PAttr attr, int srcDevice, int dstDevice);
void btx_push_message_lttng_ust_hip_hipDeviceGetP2PAttribute_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, int value_val);
void btx_push_message_lttng_ust_hip_hipDeviceGetPCIBusId_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, char * pciBusId, int len, int device);
void btx_push_message_lttng_ust_hip_hipDeviceGetPCIBusId_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, char * pciBusId_val);
void btx_push_message_lttng_ust_hip_hipDeviceGetByPCIBusId_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * device, char * pciBusId, char * pciBusId_val);
void btx_push_message_lttng_ust_hip_hipDeviceGetByPCIBusId_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, int device_val);
void btx_push_message_lttng_ust_hip_hipDeviceTotalMem_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, size_t * bytes, hipDevice_t device);
void btx_push_message_lttng_ust_hip_hipDeviceTotalMem_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t bytes_val);
void btx_push_message_lttng_ust_hip_hipDeviceSynchronize_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_hip_hipDeviceSynchronize_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipDeviceReset_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_hip_hipDeviceReset_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipSetDevice_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int deviceId);
void btx_push_message_lttng_ust_hip_hipSetDevice_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGetDevice_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * deviceId);
void btx_push_message_lttng_ust_hip_hipGetDevice_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, int deviceId_val);
void btx_push_message_lttng_ust_hip_hipGetDeviceCount_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * count);
void btx_push_message_lttng_ust_hip_hipGetDeviceCount_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, int count_val);
void btx_push_message_lttng_ust_hip_hipDeviceGetAttribute_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * pi, hipDeviceAttribute_t attr, int deviceId);
void btx_push_message_lttng_ust_hip_hipDeviceGetAttribute_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, int pi_val);
void btx_push_message_lttng_ust_hip_hipDeviceGetDefaultMemPool_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipMemPool_t * mem_pool, int device);
void btx_push_message_lttng_ust_hip_hipDeviceGetDefaultMemPool_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipMemPool_t mem_pool_val);
void btx_push_message_lttng_ust_hip_hipDeviceSetMemPool_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int device, hipMemPool_t mem_pool);
void btx_push_message_lttng_ust_hip_hipDeviceSetMemPool_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipDeviceGetMemPool_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipMemPool_t * mem_pool, int device);
void btx_push_message_lttng_ust_hip_hipDeviceGetMemPool_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipMemPool_t mem_pool_val);
void btx_push_message_lttng_ust_hip_hipGetDeviceProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipDeviceProp_t * prop, int deviceId);
void btx_push_message_lttng_ust_hip_hipGetDeviceProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t _prop_val_length, hipDeviceProp_t * prop_val);
void btx_push_message_lttng_ust_hip_hipDeviceSetCacheConfig_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipFuncCache_t cacheConfig);
void btx_push_message_lttng_ust_hip_hipDeviceSetCacheConfig_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipDeviceGetCacheConfig_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipFuncCache_t * cacheConfig);
void btx_push_message_lttng_ust_hip_hipDeviceGetCacheConfig_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipFuncCache_t cacheConfig_val);
void btx_push_message_lttng_ust_hip_hipDeviceGetLimit_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, size_t * pValue, enum hipLimit_t limit);
void btx_push_message_lttng_ust_hip_hipDeviceGetLimit_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t pValue_val);
void btx_push_message_lttng_ust_hip_hipDeviceSetLimit_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, enum hipLimit_t limit, size_t value);
void btx_push_message_lttng_ust_hip_hipDeviceSetLimit_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipDeviceGetSharedMemConfig_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipSharedMemConfig * pConfig);
void btx_push_message_lttng_ust_hip_hipDeviceGetSharedMemConfig_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipSharedMemConfig pConfig_val);
void btx_push_message_lttng_ust_hip_hipGetDeviceFlags_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, unsigned int * flags);
void btx_push_message_lttng_ust_hip_hipGetDeviceFlags_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, unsigned int flags_val);
void btx_push_message_lttng_ust_hip_hipDeviceSetSharedMemConfig_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipSharedMemConfig config);
void btx_push_message_lttng_ust_hip_hipDeviceSetSharedMemConfig_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipSetDeviceFlags_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, unsigned int flags);
void btx_push_message_lttng_ust_hip_hipSetDeviceFlags_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipChooseDevice_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * device, hipDeviceProp_t * prop, size_t _prop_val_length, hipDeviceProp_t * prop_val);
void btx_push_message_lttng_ust_hip_hipChooseDevice_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, int device_val);
void btx_push_message_lttng_ust_hip_hipExtGetLinkTypeAndHopCount_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int device1, int device2, uint32_t * linktype, uint32_t * hopcount);
void btx_push_message_lttng_ust_hip_hipExtGetLinkTypeAndHopCount_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, uint32_t linktype_val, uint32_t hopcount_val);
void btx_push_message_lttng_ust_hip_hipIpcGetMemHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipIpcMemHandle_t * handle, void * devPtr);
void btx_push_message_lttng_ust_hip_hipIpcGetMemHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t _handle_val_length, hipIpcMemHandle_t * handle_val);
void btx_push_message_lttng_ust_hip_hipIpcOpenMemHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void ** devPtr, hipIpcMemHandle_t handle, unsigned int flags);
void btx_push_message_lttng_ust_hip_hipIpcOpenMemHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, void * devPtr_val);
void btx_push_message_lttng_ust_hip_hipIpcCloseMemHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * devPtr);
void btx_push_message_lttng_ust_hip_hipIpcCloseMemHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipIpcGetEventHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipIpcEventHandle_t * handle, hipEvent_t event);
void btx_push_message_lttng_ust_hip_hipIpcGetEventHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t _handle_val_length, hipIpcEventHandle_t * handle_val);
void btx_push_message_lttng_ust_hip_hipIpcOpenEventHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipEvent_t * event, hipIpcEventHandle_t handle);
void btx_push_message_lttng_ust_hip_hipIpcOpenEventHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipEvent_t event_val);
void btx_push_message_lttng_ust_hip_hipFuncSetAttribute_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * func, hipFuncAttribute attr, int value);
void btx_push_message_lttng_ust_hip_hipFuncSetAttribute_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipFuncSetCacheConfig_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * func, hipFuncCache_t config);
void btx_push_message_lttng_ust_hip_hipFuncSetCacheConfig_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipFuncSetSharedMemConfig_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * func, hipSharedMemConfig config);
void btx_push_message_lttng_ust_hip_hipFuncSetSharedMemConfig_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGetLastError_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_hip_hipGetLastError_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipPeekAtLastError_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_hip_hipPeekAtLastError_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGetErrorName_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hip_error);
void btx_push_message_lttng_ust_hip_hipGetErrorName_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, char * hipResult, char * hipResult_val);
void btx_push_message_lttng_ust_hip_hipGetErrorString_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipError);
void btx_push_message_lttng_ust_hip_hipGetErrorString_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, char * hipResult, char * hipResult_val);
void btx_push_message_lttng_ust_hip_hipDrvGetErrorName_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipError, char ** errorString);
void btx_push_message_lttng_ust_hip_hipDrvGetErrorName_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, char * errorString_val, char * errorString_val_val);
void btx_push_message_lttng_ust_hip_hipDrvGetErrorString_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipError, char ** errorString);
void btx_push_message_lttng_ust_hip_hipDrvGetErrorString_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, char * errorString_val, char * errorString_val_val);
void btx_push_message_lttng_ust_hip_hipStreamCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t * stream);
void btx_push_message_lttng_ust_hip_hipStreamCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipStream_t stream_val);
void btx_push_message_lttng_ust_hip_hipStreamCreateWithFlags_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t * stream, unsigned int flags);
void btx_push_message_lttng_ust_hip_hipStreamCreateWithFlags_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipStream_t stream_val);
void btx_push_message_lttng_ust_hip_hipStreamCreateWithPriority_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t * stream, unsigned int flags, int priority);
void btx_push_message_lttng_ust_hip_hipStreamCreateWithPriority_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipStream_t stream_val);
void btx_push_message_lttng_ust_hip_hipDeviceGetStreamPriorityRange_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * leastPriority, int * greatestPriority);
void btx_push_message_lttng_ust_hip_hipDeviceGetStreamPriorityRange_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, int leastPriority_val, int greatestPriority_val);
void btx_push_message_lttng_ust_hip_hipStreamDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipStreamDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipStreamQuery_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipStreamQuery_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipStreamSynchronize_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipStreamSynchronize_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipStreamWaitEvent_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t stream, hipEvent_t event, unsigned int flags);
void btx_push_message_lttng_ust_hip_hipStreamWaitEvent_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipStreamGetFlags_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t stream, unsigned int * flags);
void btx_push_message_lttng_ust_hip_hipStreamGetFlags_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, unsigned int flags_val);
void btx_push_message_lttng_ust_hip_hipStreamGetPriority_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t stream, int * priority);
void btx_push_message_lttng_ust_hip_hipStreamGetPriority_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, int priority_val);
void btx_push_message_lttng_ust_hip_hipExtStreamCreateWithCUMask_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t * stream, uint32_t cuMaskSize, uint32_t * cuMask, size_t _cuMask_vals_length, uint32_t * cuMask_vals);
void btx_push_message_lttng_ust_hip_hipExtStreamCreateWithCUMask_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipStream_t stream_val);
void btx_push_message_lttng_ust_hip_hipExtStreamGetCUMask_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t stream, uint32_t cuMaskSize, uint32_t * cuMask);
void btx_push_message_lttng_ust_hip_hipExtStreamGetCUMask_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t _cuMask_vals_length, uint32_t * cuMask_vals);
void btx_push_message_lttng_ust_hip_hipStreamAddCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t stream, hipStreamCallback_t callback, void * userData, unsigned int flags);
void btx_push_message_lttng_ust_hip_hipStreamAddCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipStreamWaitValue32_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t stream, void * ptr, uint32_t value, unsigned int flags, uint32_t mask);
void btx_push_message_lttng_ust_hip_hipStreamWaitValue32_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipStreamWaitValue64_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t stream, void * ptr, uint64_t value, unsigned int flags, uint64_t mask);
void btx_push_message_lttng_ust_hip_hipStreamWaitValue64_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipStreamWriteValue32_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t stream, void * ptr, uint32_t value, unsigned int flags);
void btx_push_message_lttng_ust_hip_hipStreamWriteValue32_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipStreamWriteValue64_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t stream, void * ptr, uint64_t value, unsigned int flags);
void btx_push_message_lttng_ust_hip_hipStreamWriteValue64_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipEventCreateWithFlags_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipEvent_t * event, unsigned int flags);
void btx_push_message_lttng_ust_hip_hipEventCreateWithFlags_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipEvent_t event_val);
void btx_push_message_lttng_ust_hip_hipEventCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipEvent_t * event);
void btx_push_message_lttng_ust_hip_hipEventCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipEvent_t event_val);
void btx_push_message_lttng_ust_hip_hipEventRecord_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipEvent_t event, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipEventRecord_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipEventDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipEvent_t event);
void btx_push_message_lttng_ust_hip_hipEventDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipEventSynchronize_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipEvent_t event);
void btx_push_message_lttng_ust_hip_hipEventSynchronize_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipEventElapsedTime_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, float * ms, hipEvent_t start, hipEvent_t stop);
void btx_push_message_lttng_ust_hip_hipEventElapsedTime_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, float ms_val);
void btx_push_message_lttng_ust_hip_hipEventQuery_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipEvent_t event);
void btx_push_message_lttng_ust_hip_hipEventQuery_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipPointerGetAttributes_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipPointerAttribute_t * attributes, void * ptr);
void btx_push_message_lttng_ust_hip_hipPointerGetAttributes_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t _attributes_val_length, hipPointerAttribute_t * attributes_val);
void btx_push_message_lttng_ust_hip_hipPointerGetAttribute_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * data, hipPointer_attribute attribute, hipDeviceptr_t ptr);
void btx_push_message_lttng_ust_hip_hipPointerGetAttribute_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t _data_val_length, void * data_val);
void btx_push_message_lttng_ust_hip_hipDrvPointerGetAttributes_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, unsigned int numAttributes, hipPointer_attribute * attributes, void ** data, hipDeviceptr_t ptr);
void btx_push_message_lttng_ust_hip_hipDrvPointerGetAttributes_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipImportExternalSemaphore_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipExternalSemaphore_t * extSem_out, hipExternalSemaphoreHandleDesc * semHandleDesc, size_t _semHandleDesc_val_length, hipExternalSemaphoreHandleDesc * semHandleDesc_val);
void btx_push_message_lttng_ust_hip_hipImportExternalSemaphore_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipExternalSemaphore_t extSem_out_val);
void btx_push_message_lttng_ust_hip_hipSignalExternalSemaphoresAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipExternalSemaphore_t * extSemArray, hipExternalSemaphoreSignalParams * paramsArray, unsigned int numExtSems, hipStream_t stream, size_t _extSemArray_vals_length, hipExternalSemaphore_t * extSemArray_vals, size_t _paramsArray_vals_length, hipExternalSemaphoreSignalParams * paramsArray_vals);
void btx_push_message_lttng_ust_hip_hipSignalExternalSemaphoresAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipWaitExternalSemaphoresAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipExternalSemaphore_t * extSemArray, hipExternalSemaphoreWaitParams * paramsArray, unsigned int numExtSems, hipStream_t stream, size_t _extSemArray_vals_length, hipExternalSemaphore_t * extSemArray_vals, size_t _paramsArray_vals_length, hipExternalSemaphoreWaitParams * paramsArray_vals);
void btx_push_message_lttng_ust_hip_hipWaitExternalSemaphoresAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipDestroyExternalSemaphore_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipExternalSemaphore_t extSem);
void btx_push_message_lttng_ust_hip_hipDestroyExternalSemaphore_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipImportExternalMemory_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipExternalMemory_t * extMem_out, hipExternalMemoryHandleDesc * memHandleDesc, size_t _memHandleDesc_val_length, hipExternalMemoryHandleDesc * memHandleDesc_val);
void btx_push_message_lttng_ust_hip_hipImportExternalMemory_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipExternalMemory_t extMem_out_val);
void btx_push_message_lttng_ust_hip_hipExternalMemoryGetMappedBuffer_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void ** devPtr, hipExternalMemory_t extMem, hipExternalMemoryBufferDesc * bufferDesc, size_t _bufferDesc_val_length, hipExternalMemoryBufferDesc * bufferDesc_val);
void btx_push_message_lttng_ust_hip_hipExternalMemoryGetMappedBuffer_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, void * devPtr_val);
void btx_push_message_lttng_ust_hip_hipDestroyExternalMemory_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipExternalMemory_t extMem);
void btx_push_message_lttng_ust_hip_hipDestroyExternalMemory_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMalloc_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void ** ptr, size_t size);
void btx_push_message_lttng_ust_hip_hipMalloc_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, void * ptr_val);
void btx_push_message_lttng_ust_hip_hipExtMallocWithFlags_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void ** ptr, size_t sizeBytes, unsigned int flags);
void btx_push_message_lttng_ust_hip_hipExtMallocWithFlags_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, void * ptr_val);
void btx_push_message_lttng_ust_hip_hipMallocHost_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void ** ptr, size_t size);
void btx_push_message_lttng_ust_hip_hipMallocHost_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, void * ptr_val);
void btx_push_message_lttng_ust_hip_hipMemAllocHost_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void ** ptr, size_t size);
void btx_push_message_lttng_ust_hip_hipMemAllocHost_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, void * ptr_val);
void btx_push_message_lttng_ust_hip_hipHostMalloc_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void ** ptr, size_t size, unsigned int flags);
void btx_push_message_lttng_ust_hip_hipHostMalloc_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, void * ptr_val);
void btx_push_message_lttng_ust_hip_hipMallocManaged_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void ** dev_ptr, size_t size, unsigned int flags);
void btx_push_message_lttng_ust_hip_hipMallocManaged_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, void * dev_ptr_val);
void btx_push_message_lttng_ust_hip_hipMemPrefetchAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dev_ptr, size_t count, int device, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipMemPrefetchAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemAdvise_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dev_ptr, size_t count, hipMemoryAdvise advice, int device);
void btx_push_message_lttng_ust_hip_hipMemAdvise_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemRangeGetAttribute_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * data, size_t data_size, hipMemRangeAttribute attribute, void * dev_ptr, size_t count);
void btx_push_message_lttng_ust_hip_hipMemRangeGetAttribute_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t _data_vals_length, void * data_vals);
void btx_push_message_lttng_ust_hip_hipMemRangeGetAttributes_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void ** data, size_t * data_sizes, hipMemRangeAttribute * attributes, size_t num_attributes, void * dev_ptr, size_t count, size_t _attributes_vals_length, hipMemRangeAttribute * attributes_vals, size_t _data_sizes_vals_length, size_t * data_sizes_vals);
void btx_push_message_lttng_ust_hip_hipMemRangeGetAttributes_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipStreamAttachMemAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t stream, void * dev_ptr, size_t length, unsigned int flags);
void btx_push_message_lttng_ust_hip_hipStreamAttachMemAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMallocAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void ** dev_ptr, size_t size, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipMallocAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, void * dev_ptr_val);
void btx_push_message_lttng_ust_hip_hipFreeAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dev_ptr, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipFreeAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemPoolTrimTo_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipMemPool_t mem_pool, size_t min_bytes_to_hold);
void btx_push_message_lttng_ust_hip_hipMemPoolTrimTo_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemPoolSetAttribute_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipMemPool_t mem_pool, hipMemPoolAttr attr, void * value, size_t _value_val_length, void * value_val);
void btx_push_message_lttng_ust_hip_hipMemPoolSetAttribute_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemPoolGetAttribute_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipMemPool_t mem_pool, hipMemPoolAttr attr, void * value);
void btx_push_message_lttng_ust_hip_hipMemPoolGetAttribute_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t _value_val_length, void * value_val);
void btx_push_message_lttng_ust_hip_hipMemPoolSetAccess_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipMemPool_t mem_pool, hipMemAccessDesc * desc_list, size_t count, size_t _desc_list_vals_length, hipMemAccessDesc * desc_list_vals);
void btx_push_message_lttng_ust_hip_hipMemPoolSetAccess_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemPoolGetAccess_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipMemAccessFlags * flags, hipMemPool_t mem_pool, hipMemLocation * location, size_t _location_val_length, hipMemLocation * location_val);
void btx_push_message_lttng_ust_hip_hipMemPoolGetAccess_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipMemAccessFlags flags_val);
void btx_push_message_lttng_ust_hip_hipMemPoolCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipMemPool_t * mem_pool, hipMemPoolProps * pool_props, size_t _pool_props_val_length, hipMemPoolProps * pool_props_val);
void btx_push_message_lttng_ust_hip_hipMemPoolCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipMemPool_t mem_pool_val);
void btx_push_message_lttng_ust_hip_hipMemPoolDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipMemPool_t mem_pool);
void btx_push_message_lttng_ust_hip_hipMemPoolDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMallocFromPoolAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void ** dev_ptr, size_t size, hipMemPool_t mem_pool, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipMallocFromPoolAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, void * dev_ptr_val);
void btx_push_message_lttng_ust_hip_hipMemPoolExportToShareableHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * shared_handle, hipMemPool_t mem_pool, hipMemAllocationHandleType handle_type, unsigned int flags);
void btx_push_message_lttng_ust_hip_hipMemPoolExportToShareableHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t _shared_handle_val_length, void * shared_handle_val);
void btx_push_message_lttng_ust_hip_hipMemPoolImportFromShareableHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipMemPool_t * mem_pool, void * shared_handle, hipMemAllocationHandleType handle_type, unsigned int flags, size_t _shared_handle_val_length, void * shared_handle_val);
void btx_push_message_lttng_ust_hip_hipMemPoolImportFromShareableHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipMemPool_t mem_pool_val);
void btx_push_message_lttng_ust_hip_hipMemPoolExportPointer_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipMemPoolPtrExportData * export_data, void * dev_ptr);
void btx_push_message_lttng_ust_hip_hipMemPoolExportPointer_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t _export_data_val_length, hipMemPoolPtrExportData * export_data_val);
void btx_push_message_lttng_ust_hip_hipMemPoolImportPointer_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void ** dev_ptr, hipMemPool_t mem_pool, hipMemPoolPtrExportData * export_data, size_t _export_data_val_length, hipMemPoolPtrExportData * export_data_val);
void btx_push_message_lttng_ust_hip_hipMemPoolImportPointer_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, void * dev_ptr_val);
void btx_push_message_lttng_ust_hip_hipHostAlloc_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void ** ptr, size_t size, unsigned int flags);
void btx_push_message_lttng_ust_hip_hipHostAlloc_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, void * ptr_val);
void btx_push_message_lttng_ust_hip_hipHostGetDevicePointer_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void ** devPtr, void * hstPtr, unsigned int flags);
void btx_push_message_lttng_ust_hip_hipHostGetDevicePointer_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, void * devPtr_val);
void btx_push_message_lttng_ust_hip_hipHostGetFlags_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, unsigned int * flagsPtr, void * hostPtr);
void btx_push_message_lttng_ust_hip_hipHostGetFlags_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, unsigned int flagsPtr_val);
void btx_push_message_lttng_ust_hip_hipHostRegister_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * hostPtr, size_t sizeBytes, unsigned int flags);
void btx_push_message_lttng_ust_hip_hipHostRegister_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipHostUnregister_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * hostPtr);
void btx_push_message_lttng_ust_hip_hipHostUnregister_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMallocPitch_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void ** ptr, size_t * pitch, size_t width, size_t height);
void btx_push_message_lttng_ust_hip_hipMallocPitch_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, void * ptr_val, size_t pitch_val);
void btx_push_message_lttng_ust_hip_hipMemAllocPitch_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipDeviceptr_t * dptr, size_t * pitch, size_t widthInBytes, size_t height, unsigned int elementSizeBytes);
void btx_push_message_lttng_ust_hip_hipMemAllocPitch_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipDeviceptr_t dptr_val, size_t pitch_val);
void btx_push_message_lttng_ust_hip_hipFree_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * ptr);
void btx_push_message_lttng_ust_hip_hipFree_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipFreeHost_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * ptr);
void btx_push_message_lttng_ust_hip_hipFreeHost_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipHostFree_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * ptr);
void btx_push_message_lttng_ust_hip_hipHostFree_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dst, void * src, size_t sizeBytes, hipMemcpyKind kind);
void btx_push_message_lttng_ust_hip_hipMemcpy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpyWithStream_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dst, void * src, size_t sizeBytes, hipMemcpyKind kind, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipMemcpyWithStream_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpyHtoD_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipDeviceptr_t dst, void * src, size_t sizeBytes);
void btx_push_message_lttng_ust_hip_hipMemcpyHtoD_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpyDtoH_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dst, hipDeviceptr_t src, size_t sizeBytes);
void btx_push_message_lttng_ust_hip_hipMemcpyDtoH_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpyDtoD_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipDeviceptr_t dst, hipDeviceptr_t src, size_t sizeBytes);
void btx_push_message_lttng_ust_hip_hipMemcpyDtoD_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpyHtoDAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipDeviceptr_t dst, void * src, size_t sizeBytes, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipMemcpyHtoDAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpyDtoHAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dst, hipDeviceptr_t src, size_t sizeBytes, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipMemcpyDtoHAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpyDtoDAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipDeviceptr_t dst, hipDeviceptr_t src, size_t sizeBytes, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipMemcpyDtoDAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipModuleGetGlobal_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipDeviceptr_t * dptr, size_t * bytes, hipModule_t hmod, char * name, char * name_val);
void btx_push_message_lttng_ust_hip_hipModuleGetGlobal_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipDeviceptr_t dptr_val, size_t bytes_val);
void btx_push_message_lttng_ust_hip_hipGetSymbolAddress_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void ** devPtr, void * symbol);
void btx_push_message_lttng_ust_hip_hipGetSymbolAddress_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, void * devPtr_val);
void btx_push_message_lttng_ust_hip_hipGetSymbolSize_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, size_t * size, void * symbol);
void btx_push_message_lttng_ust_hip_hipGetSymbolSize_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t size_val);
void btx_push_message_lttng_ust_hip_hipMemcpyToSymbol_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * symbol, void * src, size_t sizeBytes, size_t offset, hipMemcpyKind kind);
void btx_push_message_lttng_ust_hip_hipMemcpyToSymbol_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpyToSymbolAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * symbol, void * src, size_t sizeBytes, size_t offset, hipMemcpyKind kind, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipMemcpyToSymbolAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpyFromSymbol_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dst, void * symbol, size_t sizeBytes, size_t offset, hipMemcpyKind kind);
void btx_push_message_lttng_ust_hip_hipMemcpyFromSymbol_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpyFromSymbolAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dst, void * symbol, size_t sizeBytes, size_t offset, hipMemcpyKind kind, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipMemcpyFromSymbolAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpyAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dst, void * src, size_t sizeBytes, hipMemcpyKind kind, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipMemcpyAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemset_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dst, int value, size_t sizeBytes);
void btx_push_message_lttng_ust_hip_hipMemset_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemsetD8_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipDeviceptr_t dest, unsigned char value, size_t count);
void btx_push_message_lttng_ust_hip_hipMemsetD8_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemsetD8Async_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipDeviceptr_t dest, unsigned char value, size_t count, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipMemsetD8Async_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemsetD16_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipDeviceptr_t dest, unsigned short int value, size_t count);
void btx_push_message_lttng_ust_hip_hipMemsetD16_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemsetD16Async_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipDeviceptr_t dest, unsigned short int value, size_t count, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipMemsetD16Async_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemsetD32_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipDeviceptr_t dest, int value, size_t count);
void btx_push_message_lttng_ust_hip_hipMemsetD32_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemsetAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dst, int value, size_t sizeBytes, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipMemsetAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemsetD32Async_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipDeviceptr_t dst, int value, size_t count, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipMemsetD32Async_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemset2D_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dst, size_t pitch, int value, size_t width, size_t height);
void btx_push_message_lttng_ust_hip_hipMemset2D_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemset2DAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dst, size_t pitch, int value, size_t width, size_t height, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipMemset2DAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemset3D_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipPitchedPtr pitchedDevPtr, int value, hipExtent extent);
void btx_push_message_lttng_ust_hip_hipMemset3D_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemset3DAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipPitchedPtr pitchedDevPtr, int value, hipExtent extent, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipMemset3DAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemGetInfo_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, size_t * free, size_t * total);
void btx_push_message_lttng_ust_hip_hipMemGetInfo_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t free_val, size_t total_val);
void btx_push_message_lttng_ust_hip_hipMemPtrGetInfo_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * ptr, size_t * size);
void btx_push_message_lttng_ust_hip_hipMemPtrGetInfo_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t size_val);
void btx_push_message_lttng_ust_hip_hipMallocArray_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipArray ** array, hipChannelFormatDesc * desc, size_t width, size_t height, unsigned int flags, size_t _desc_val_length, hipChannelFormatDesc * desc_val);
void btx_push_message_lttng_ust_hip_hipMallocArray_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipArray * array_val);
void btx_push_message_lttng_ust_hip_hipArrayCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipArray ** pHandle, HIP_ARRAY_DESCRIPTOR * pAllocateArray, size_t _pAllocateArray_val_length, HIP_ARRAY_DESCRIPTOR * pAllocateArray_val);
void btx_push_message_lttng_ust_hip_hipArrayCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipArray * pHandle_val);
void btx_push_message_lttng_ust_hip_hipArrayDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipArray * array);
void btx_push_message_lttng_ust_hip_hipArrayDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipArray3DCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipArray ** array, HIP_ARRAY3D_DESCRIPTOR * pAllocateArray);
void btx_push_message_lttng_ust_hip_hipArray3DCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMalloc3D_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipPitchedPtr * pitchedDevPtr, hipExtent extent);
void btx_push_message_lttng_ust_hip_hipMalloc3D_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t _pitchedDevPtr_val_length, hipPitchedPtr * pitchedDevPtr_val);
void btx_push_message_lttng_ust_hip_hipFreeArray_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipArray * array);
void btx_push_message_lttng_ust_hip_hipFreeArray_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipFreeMipmappedArray_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipMipmappedArray_t mipmappedArray);
void btx_push_message_lttng_ust_hip_hipFreeMipmappedArray_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMalloc3DArray_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipArray ** array, struct hipChannelFormatDesc * desc, struct hipExtent extent, unsigned int flags, size_t _desc_val_length, struct hipChannelFormatDesc * desc_val);
void btx_push_message_lttng_ust_hip_hipMalloc3DArray_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipArray * array_val);
void btx_push_message_lttng_ust_hip_hipMallocMipmappedArray_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipMipmappedArray_t * mipmappedArray, struct hipChannelFormatDesc * desc, struct hipExtent extent, unsigned int numLevels, unsigned int flags, size_t _desc_val_length, struct hipChannelFormatDesc * desc_val);
void btx_push_message_lttng_ust_hip_hipMallocMipmappedArray_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipMipmappedArray_t mipmappedArray_val);
void btx_push_message_lttng_ust_hip_hipGetMipmappedArrayLevel_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipArray_t * levelArray, hipMipmappedArray_const_t mipmappedArray, unsigned int level);
void btx_push_message_lttng_ust_hip_hipGetMipmappedArrayLevel_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipArray_t levelArray_val);
void btx_push_message_lttng_ust_hip_hipMemcpy2D_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dst, size_t dpitch, void * src, size_t spitch, size_t width, size_t height, hipMemcpyKind kind);
void btx_push_message_lttng_ust_hip_hipMemcpy2D_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpyParam2D_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hip_Memcpy2D * pCopy, size_t _pCopy_val_length, hip_Memcpy2D * pCopy_val);
void btx_push_message_lttng_ust_hip_hipMemcpyParam2D_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpyParam2DAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hip_Memcpy2D * pCopy, hipStream_t stream, size_t _pCopy_val_length, hip_Memcpy2D * pCopy_val);
void btx_push_message_lttng_ust_hip_hipMemcpyParam2DAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpy2DAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dst, size_t dpitch, void * src, size_t spitch, size_t width, size_t height, hipMemcpyKind kind, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipMemcpy2DAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpy2DToArray_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipArray * dst, size_t wOffset, size_t hOffset, void * src, size_t spitch, size_t width, size_t height, hipMemcpyKind kind);
void btx_push_message_lttng_ust_hip_hipMemcpy2DToArray_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpy2DToArrayAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipArray * dst, size_t wOffset, size_t hOffset, void * src, size_t spitch, size_t width, size_t height, hipMemcpyKind kind, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipMemcpy2DToArrayAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpyToArray_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipArray * dst, size_t wOffset, size_t hOffset, void * src, size_t count, hipMemcpyKind kind);
void btx_push_message_lttng_ust_hip_hipMemcpyToArray_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpyFromArray_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dst, hipArray_const_t srcArray, size_t wOffset, size_t hOffset, size_t count, hipMemcpyKind kind);
void btx_push_message_lttng_ust_hip_hipMemcpyFromArray_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpy2DFromArray_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dst, size_t dpitch, hipArray_const_t src, size_t wOffset, size_t hOffset, size_t width, size_t height, hipMemcpyKind kind);
void btx_push_message_lttng_ust_hip_hipMemcpy2DFromArray_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpy2DFromArrayAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dst, size_t dpitch, hipArray_const_t src, size_t wOffset, size_t hOffset, size_t width, size_t height, hipMemcpyKind kind, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipMemcpy2DFromArrayAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpyAtoH_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dst, hipArray * srcArray, size_t srcOffset, size_t count);
void btx_push_message_lttng_ust_hip_hipMemcpyAtoH_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpyHtoA_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipArray * dstArray, size_t dstOffset, void * srcHost, size_t count);
void btx_push_message_lttng_ust_hip_hipMemcpyHtoA_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpy3D_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, struct hipMemcpy3DParms * p, size_t _p_val_length, struct hipMemcpy3DParms * p_val);
void btx_push_message_lttng_ust_hip_hipMemcpy3D_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpy3DAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, struct hipMemcpy3DParms * p, hipStream_t stream, size_t _p_val_length, struct hipMemcpy3DParms * p_val);
void btx_push_message_lttng_ust_hip_hipMemcpy3DAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipDrvMemcpy3D_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, HIP_MEMCPY3D * pCopy, size_t _pCopy_val_length, HIP_MEMCPY3D * pCopy_val);
void btx_push_message_lttng_ust_hip_hipDrvMemcpy3D_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipDrvMemcpy3DAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, HIP_MEMCPY3D * pCopy, hipStream_t stream, size_t _pCopy_val_length, HIP_MEMCPY3D * pCopy_val);
void btx_push_message_lttng_ust_hip_hipDrvMemcpy3DAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipDeviceCanAccessPeer_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * canAccessPeer, int deviceId, int peerDeviceId);
void btx_push_message_lttng_ust_hip_hipDeviceCanAccessPeer_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, int canAccessPeer_val);
void btx_push_message_lttng_ust_hip_hipDeviceEnablePeerAccess_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int peerDeviceId, unsigned int flags);
void btx_push_message_lttng_ust_hip_hipDeviceEnablePeerAccess_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipDeviceDisablePeerAccess_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int peerDeviceId);
void btx_push_message_lttng_ust_hip_hipDeviceDisablePeerAccess_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemGetAddressRange_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipDeviceptr_t * pbase, size_t * psize, hipDeviceptr_t dptr);
void btx_push_message_lttng_ust_hip_hipMemGetAddressRange_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipDeviceptr_t pbase_val, size_t psize_val);
void btx_push_message_lttng_ust_hip_hipMemcpyPeer_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dst, int dstDeviceId, void * src, int srcDeviceId, size_t sizeBytes);
void btx_push_message_lttng_ust_hip_hipMemcpyPeer_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpyPeerAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dst, int dstDeviceId, void * src, int srcDevice, size_t sizeBytes, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipMemcpyPeerAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipCtxCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipCtx_t * ctx, unsigned int flags, hipDevice_t device);
void btx_push_message_lttng_ust_hip_hipCtxCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipCtx_t ctx_val);
void btx_push_message_lttng_ust_hip_hipCtxDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipCtx_t ctx);
void btx_push_message_lttng_ust_hip_hipCtxDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipCtxPopCurrent_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipCtx_t * ctx);
void btx_push_message_lttng_ust_hip_hipCtxPopCurrent_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipCtx_t ctx_val);
void btx_push_message_lttng_ust_hip_hipCtxPushCurrent_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipCtx_t ctx);
void btx_push_message_lttng_ust_hip_hipCtxPushCurrent_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipCtxSetCurrent_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipCtx_t ctx);
void btx_push_message_lttng_ust_hip_hipCtxSetCurrent_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipCtxGetCurrent_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipCtx_t * ctx);
void btx_push_message_lttng_ust_hip_hipCtxGetCurrent_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipCtx_t ctx_val);
void btx_push_message_lttng_ust_hip_hipCtxGetDevice_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipDevice_t * device);
void btx_push_message_lttng_ust_hip_hipCtxGetDevice_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipDevice_t device_val);
void btx_push_message_lttng_ust_hip_hipCtxGetApiVersion_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipCtx_t ctx, int * apiVersion);
void btx_push_message_lttng_ust_hip_hipCtxGetApiVersion_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, int apiVersion_val);
void btx_push_message_lttng_ust_hip_hipCtxGetCacheConfig_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipFuncCache_t * cacheConfig);
void btx_push_message_lttng_ust_hip_hipCtxGetCacheConfig_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipFuncCache_t cacheConfig_val);
void btx_push_message_lttng_ust_hip_hipCtxSetCacheConfig_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipFuncCache_t cacheConfig);
void btx_push_message_lttng_ust_hip_hipCtxSetCacheConfig_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipCtxSetSharedMemConfig_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipSharedMemConfig config);
void btx_push_message_lttng_ust_hip_hipCtxSetSharedMemConfig_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipCtxGetSharedMemConfig_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipSharedMemConfig * pConfig);
void btx_push_message_lttng_ust_hip_hipCtxGetSharedMemConfig_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipSharedMemConfig pConfig_val);
void btx_push_message_lttng_ust_hip_hipCtxSynchronize_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_hip_hipCtxSynchronize_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipCtxGetFlags_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, unsigned int * flags);
void btx_push_message_lttng_ust_hip_hipCtxGetFlags_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, unsigned int flags_val);
void btx_push_message_lttng_ust_hip_hipCtxEnablePeerAccess_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipCtx_t peerCtx, unsigned int flags);
void btx_push_message_lttng_ust_hip_hipCtxEnablePeerAccess_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipCtxDisablePeerAccess_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipCtx_t peerCtx);
void btx_push_message_lttng_ust_hip_hipCtxDisablePeerAccess_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipDevicePrimaryCtxGetState_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipDevice_t dev, unsigned int * flags, int * active);
void btx_push_message_lttng_ust_hip_hipDevicePrimaryCtxGetState_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, unsigned int flags_val, int active_val);
void btx_push_message_lttng_ust_hip_hipDevicePrimaryCtxRelease_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipDevice_t dev);
void btx_push_message_lttng_ust_hip_hipDevicePrimaryCtxRelease_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipDevicePrimaryCtxRetain_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipCtx_t * pctx, hipDevice_t dev);
void btx_push_message_lttng_ust_hip_hipDevicePrimaryCtxRetain_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipCtx_t pctx_val);
void btx_push_message_lttng_ust_hip_hipDevicePrimaryCtxReset_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipDevice_t dev);
void btx_push_message_lttng_ust_hip_hipDevicePrimaryCtxReset_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipDevicePrimaryCtxSetFlags_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipDevice_t dev, unsigned int flags);
void btx_push_message_lttng_ust_hip_hipDevicePrimaryCtxSetFlags_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipModuleLoad_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipModule_t * module, char * fname, char * fname_val);
void btx_push_message_lttng_ust_hip_hipModuleLoad_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipModule_t module_val);
void btx_push_message_lttng_ust_hip_hipModuleUnload_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipModule_t module);
void btx_push_message_lttng_ust_hip_hipModuleUnload_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipModuleGetFunction_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipFunction_t * function, hipModule_t module, char * kname, char * kname_val);
void btx_push_message_lttng_ust_hip_hipModuleGetFunction_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipFunction_t function_val);
void btx_push_message_lttng_ust_hip_hipFuncGetAttributes_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, struct hipFuncAttributes * attr, void * func);
void btx_push_message_lttng_ust_hip_hipFuncGetAttributes_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t _attr_val_length, struct hipFuncAttributes * attr_val);
void btx_push_message_lttng_ust_hip_hipFuncGetAttribute_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * value, hipFunction_attribute attrib, hipFunction_t hfunc);
void btx_push_message_lttng_ust_hip_hipFuncGetAttribute_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, int value_val);
void btx_push_message_lttng_ust_hip_hipModuleGetTexRef_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, textureReference ** texRef, hipModule_t hmod, char * name, char * name_val);
void btx_push_message_lttng_ust_hip_hipModuleGetTexRef_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, textureReference * texRef_val);
void btx_push_message_lttng_ust_hip_hipModuleLoadData_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipModule_t * module, void * image);
void btx_push_message_lttng_ust_hip_hipModuleLoadData_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipModule_t module_val);
void btx_push_message_lttng_ust_hip_hipModuleLoadDataEx_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipModule_t * module, void * image, unsigned int numOptions, hipJitOption * options, void ** optionValues, size_t _options_vals_length, hipJitOption * options_vals, size_t _optionValues_vals_length, void * * optionValues_vals);
void btx_push_message_lttng_ust_hip_hipModuleLoadDataEx_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipModule_t module_val);
void btx_push_message_lttng_ust_hip_hipModuleLaunchKernel_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipFunction_t f, unsigned int gridDimX, unsigned int gridDimY, unsigned int gridDimZ, unsigned int blockDimX, unsigned int blockDimY, unsigned int blockDimZ, unsigned int sharedMemBytes, hipStream_t stream, void ** kernelParams, void ** extra);
void btx_push_message_lttng_ust_hip_hipModuleLaunchKernel_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipLaunchCooperativeKernel_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * f, dim3 gridDim, dim3 blockDimX, void ** kernelParams, unsigned int sharedMemBytes, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipLaunchCooperativeKernel_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipLaunchCooperativeKernelMultiDevice_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipLaunchParams * launchParamsList, int numDevices, unsigned int flags, size_t _launchParamsList_vals_length, hipLaunchParams * launchParamsList_vals);
void btx_push_message_lttng_ust_hip_hipLaunchCooperativeKernelMultiDevice_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipExtLaunchMultiKernelMultiDevice_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipLaunchParams * launchParamsList, int numDevices, unsigned int flags, size_t _launchParamsList_vals_length, hipLaunchParams * launchParamsList_vals);
void btx_push_message_lttng_ust_hip_hipExtLaunchMultiKernelMultiDevice_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipModuleOccupancyMaxPotentialBlockSize_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * gridSize, int * blockSize, hipFunction_t f, size_t dynSharedMemPerBlk, int blockSizeLimit);
void btx_push_message_lttng_ust_hip_hipModuleOccupancyMaxPotentialBlockSize_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, int gridSize_val, int blockSize_val);
void btx_push_message_lttng_ust_hip_hipModuleOccupancyMaxPotentialBlockSizeWithFlags_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * gridSize, int * blockSize, hipFunction_t f, size_t dynSharedMemPerBlk, int blockSizeLimit, unsigned int flags);
void btx_push_message_lttng_ust_hip_hipModuleOccupancyMaxPotentialBlockSizeWithFlags_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, int gridSize_val, int blockSize_val);
void btx_push_message_lttng_ust_hip_hipModuleOccupancyMaxActiveBlocksPerMultiprocessor_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * numBlocks, hipFunction_t f, int blockSize, size_t dynSharedMemPerBlk);
void btx_push_message_lttng_ust_hip_hipModuleOccupancyMaxActiveBlocksPerMultiprocessor_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, int numBlocks_val);
void btx_push_message_lttng_ust_hip_hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * numBlocks, hipFunction_t f, int blockSize, size_t dynSharedMemPerBlk, unsigned int flags);
void btx_push_message_lttng_ust_hip_hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, int numBlocks_val);
void btx_push_message_lttng_ust_hip_hipOccupancyMaxActiveBlocksPerMultiprocessor_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * numBlocks, void * f, int blockSize, size_t dynSharedMemPerBlk);
void btx_push_message_lttng_ust_hip_hipOccupancyMaxActiveBlocksPerMultiprocessor_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, int numBlocks_val);
void btx_push_message_lttng_ust_hip_hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * numBlocks, void * f, int blockSize, size_t dynSharedMemPerBlk, unsigned int flags);
void btx_push_message_lttng_ust_hip_hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, int numBlocks_val);
void btx_push_message_lttng_ust_hip_hipOccupancyMaxPotentialBlockSize_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * gridSize, int * blockSize, void * f, size_t dynSharedMemPerBlk, int blockSizeLimit);
void btx_push_message_lttng_ust_hip_hipOccupancyMaxPotentialBlockSize_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, int gridSize_val, int blockSize_val);
void btx_push_message_lttng_ust_hip_hipProfilerStart_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_hip_hipProfilerStart_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipProfilerStop_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_hip_hipProfilerStop_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipConfigureCall_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, dim3 gridDim, dim3 blockDim, size_t sharedMem, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipConfigureCall_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipSetupArgument_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * arg, size_t size, size_t offset, size_t _arg_vals_length, void * arg_vals);
void btx_push_message_lttng_ust_hip_hipSetupArgument_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipLaunchByPtr_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * func);
void btx_push_message_lttng_ust_hip_hipLaunchByPtr_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip___hipPushCallConfiguration_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, dim3 gridDim, dim3 blockDim, size_t sharedMem, hipStream_t stream);
void btx_push_message_lttng_ust_hip___hipPushCallConfiguration_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip___hipPopCallConfiguration_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, dim3 * gridDim, dim3 * blockDim, size_t * sharedMem, hipStream_t * stream);
void btx_push_message_lttng_ust_hip___hipPopCallConfiguration_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t _gridDim_val_length, dim3 * gridDim_val, size_t _blockDim_val_length, dim3 * blockDim_val, size_t sharedMem_val, hipStream_t stream_val);
void btx_push_message_lttng_ust_hip_hipLaunchKernel_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * function_address, dim3 numBlocks, dim3 dimBlocks, void ** args, size_t sharedMemBytes, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipLaunchKernel_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipDrvMemcpy2DUnaligned_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hip_Memcpy2D * pCopy, size_t _pCopy_val_length, hip_Memcpy2D * pCopy_val);
void btx_push_message_lttng_ust_hip_hipDrvMemcpy2DUnaligned_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipExtLaunchKernel_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * function_address, dim3 numBlocks, dim3 dimBlocks, void ** args, size_t sharedMemBytes, hipStream_t stream, hipEvent_t startEvent, hipEvent_t stopEvent, int flags);
void btx_push_message_lttng_ust_hip_hipExtLaunchKernel_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipBindTextureToMipmappedArray_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, textureReference * tex, hipMipmappedArray_const_t mipmappedArray, hipChannelFormatDesc * desc, size_t _desc_val_length, hipChannelFormatDesc * desc_val);
void btx_push_message_lttng_ust_hip_hipBindTextureToMipmappedArray_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipCreateTextureObject_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipTextureObject_t * pTexObject, hipResourceDesc * pResDesc, hipTextureDesc * pTexDesc, struct hipResourceViewDesc * pResViewDesc, size_t _pResDesc_val_length, hipResourceDesc * pResDesc_val, size_t _pTexDesc_val_length, hipTextureDesc * pTexDesc_val, size_t _pResViewDesc_val_length, struct hipResourceViewDesc * pResViewDesc_val);
void btx_push_message_lttng_ust_hip_hipCreateTextureObject_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipTextureObject_t pTexObject_val);
void btx_push_message_lttng_ust_hip_hipDestroyTextureObject_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipTextureObject_t textureObject);
void btx_push_message_lttng_ust_hip_hipDestroyTextureObject_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGetChannelDesc_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipChannelFormatDesc * desc, hipArray_const_t array);
void btx_push_message_lttng_ust_hip_hipGetChannelDesc_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t _desc_val_length, hipChannelFormatDesc * desc_val);
void btx_push_message_lttng_ust_hip_hipGetTextureObjectResourceDesc_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipResourceDesc * pResDesc, hipTextureObject_t textureObject);
void btx_push_message_lttng_ust_hip_hipGetTextureObjectResourceDesc_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t _pResDesc_val_length, hipResourceDesc * pResDesc_val);
void btx_push_message_lttng_ust_hip_hipGetTextureObjectResourceViewDesc_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, struct hipResourceViewDesc * pResViewDesc, hipTextureObject_t textureObject);
void btx_push_message_lttng_ust_hip_hipGetTextureObjectResourceViewDesc_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t _pResViewDesc_val_length, struct hipResourceViewDesc * pResViewDesc_val);
void btx_push_message_lttng_ust_hip_hipGetTextureObjectTextureDesc_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipTextureDesc * pTexDesc, hipTextureObject_t textureObject);
void btx_push_message_lttng_ust_hip_hipGetTextureObjectTextureDesc_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t _pTexDesc_val_length, hipTextureDesc * pTexDesc_val);
void btx_push_message_lttng_ust_hip_hipTexObjectCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipTextureObject_t * pTexObject, HIP_RESOURCE_DESC * pResDesc, HIP_TEXTURE_DESC * pTexDesc, HIP_RESOURCE_VIEW_DESC * pResViewDesc, size_t _pResDesc_val_length, HIP_RESOURCE_DESC * pResDesc_val, size_t _pTexDesc_val_length, HIP_TEXTURE_DESC * pTexDesc_val, size_t _pResViewDesc_val_length, HIP_RESOURCE_VIEW_DESC * pResViewDesc_val);
void btx_push_message_lttng_ust_hip_hipTexObjectCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipTextureObject_t pTexObject_val);
void btx_push_message_lttng_ust_hip_hipTexObjectDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipTextureObject_t texObject);
void btx_push_message_lttng_ust_hip_hipTexObjectDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipTexObjectGetResourceDesc_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, HIP_RESOURCE_DESC * pResDesc, hipTextureObject_t texObject);
void btx_push_message_lttng_ust_hip_hipTexObjectGetResourceDesc_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t _pResDesc_val_length, HIP_RESOURCE_DESC * pResDesc_val);
void btx_push_message_lttng_ust_hip_hipTexObjectGetResourceViewDesc_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, HIP_RESOURCE_VIEW_DESC * pResViewDesc, hipTextureObject_t texObject);
void btx_push_message_lttng_ust_hip_hipTexObjectGetResourceViewDesc_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t _pResViewDesc_val_length, HIP_RESOURCE_VIEW_DESC * pResViewDesc_val);
void btx_push_message_lttng_ust_hip_hipTexObjectGetTextureDesc_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, HIP_TEXTURE_DESC * pTexDesc, hipTextureObject_t texObject);
void btx_push_message_lttng_ust_hip_hipTexObjectGetTextureDesc_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t _pTexDesc_val_length, HIP_TEXTURE_DESC * pTexDesc_val);
void btx_push_message_lttng_ust_hip_hipGetTextureReference_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, textureReference ** texref, void * symbol);
void btx_push_message_lttng_ust_hip_hipGetTextureReference_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, textureReference * texref_val);
void btx_push_message_lttng_ust_hip_hipTexRefSetAddressMode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, textureReference * texRef, int dim, enum hipTextureAddressMode am);
void btx_push_message_lttng_ust_hip_hipTexRefSetAddressMode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipTexRefSetArray_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, textureReference * tex, hipArray_const_t array, unsigned int flags);
void btx_push_message_lttng_ust_hip_hipTexRefSetArray_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipTexRefSetFilterMode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, textureReference * texRef, enum hipTextureFilterMode fm);
void btx_push_message_lttng_ust_hip_hipTexRefSetFilterMode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipTexRefSetFlags_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, textureReference * texRef, unsigned int Flags);
void btx_push_message_lttng_ust_hip_hipTexRefSetFlags_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipTexRefSetFormat_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, textureReference * texRef, hipArray_Format fmt, int NumPackedComponents);
void btx_push_message_lttng_ust_hip_hipTexRefSetFormat_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipBindTexture_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, size_t * offset, textureReference * tex, void * devPtr, hipChannelFormatDesc * desc, size_t size, size_t _desc_val_length, hipChannelFormatDesc * desc_val);
void btx_push_message_lttng_ust_hip_hipBindTexture_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t offset_val);
void btx_push_message_lttng_ust_hip_hipBindTexture2D_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, size_t * offset, textureReference * tex, void * devPtr, hipChannelFormatDesc * desc, size_t width, size_t height, size_t pitch, size_t _desc_val_length, hipChannelFormatDesc * desc_val);
void btx_push_message_lttng_ust_hip_hipBindTexture2D_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t offset_val);
void btx_push_message_lttng_ust_hip_hipBindTextureToArray_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, textureReference * tex, hipArray_const_t array, hipChannelFormatDesc * desc, size_t _desc_val_length, hipChannelFormatDesc * desc_val);
void btx_push_message_lttng_ust_hip_hipBindTextureToArray_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGetTextureAlignmentOffset_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, size_t * offset, textureReference * texref);
void btx_push_message_lttng_ust_hip_hipGetTextureAlignmentOffset_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t offset_val);
void btx_push_message_lttng_ust_hip_hipUnbindTexture_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, textureReference * tex);
void btx_push_message_lttng_ust_hip_hipUnbindTexture_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipTexRefGetAddress_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipDeviceptr_t * dev_ptr, textureReference * texRef);
void btx_push_message_lttng_ust_hip_hipTexRefGetAddress_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipDeviceptr_t dev_ptr_val);
void btx_push_message_lttng_ust_hip_hipTexRefGetAddressMode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, enum hipTextureAddressMode * pam, textureReference * texRef, int dim);
void btx_push_message_lttng_ust_hip_hipTexRefGetAddressMode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, enum hipTextureAddressMode pam_val);
void btx_push_message_lttng_ust_hip_hipTexRefGetFilterMode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, enum hipTextureFilterMode * pfm, textureReference * texRef);
void btx_push_message_lttng_ust_hip_hipTexRefGetFilterMode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, enum hipTextureFilterMode pfm_val);
void btx_push_message_lttng_ust_hip_hipTexRefGetFlags_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, unsigned int * pFlags, textureReference * texRef);
void btx_push_message_lttng_ust_hip_hipTexRefGetFlags_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, unsigned int pFlags_val);
void btx_push_message_lttng_ust_hip_hipTexRefGetFormat_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipArray_Format * pFormat, int * pNumChannels, textureReference * texRef);
void btx_push_message_lttng_ust_hip_hipTexRefGetFormat_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipArray_Format pFormat_val, int pNumChannels_val);
void btx_push_message_lttng_ust_hip_hipTexRefGetMaxAnisotropy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * pmaxAnsio, textureReference * texRef);
void btx_push_message_lttng_ust_hip_hipTexRefGetMaxAnisotropy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, int pmaxAnsio_val);
void btx_push_message_lttng_ust_hip_hipTexRefGetMipmapFilterMode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, enum hipTextureFilterMode * pfm, textureReference * texRef);
void btx_push_message_lttng_ust_hip_hipTexRefGetMipmapFilterMode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, enum hipTextureFilterMode pfm_val);
void btx_push_message_lttng_ust_hip_hipTexRefGetMipmapLevelBias_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, float * pbias, textureReference * texRef);
void btx_push_message_lttng_ust_hip_hipTexRefGetMipmapLevelBias_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, float pbias_val);
void btx_push_message_lttng_ust_hip_hipTexRefGetMipmapLevelClamp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, float * pminMipmapLevelClamp, float * pmaxMipmapLevelClamp, textureReference * texRef);
void btx_push_message_lttng_ust_hip_hipTexRefGetMipmapLevelClamp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, float pminMipmapLevelClamp_val, float pmaxMipmapLevelClamp_val);
void btx_push_message_lttng_ust_hip_hipTexRefGetMipMappedArray_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipMipmappedArray_t * pArray, textureReference * texRef);
void btx_push_message_lttng_ust_hip_hipTexRefGetMipMappedArray_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipMipmappedArray_t pArray_val);
void btx_push_message_lttng_ust_hip_hipTexRefSetAddress_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, size_t * ByteOffset, textureReference * texRef, hipDeviceptr_t dptr, size_t bytes);
void btx_push_message_lttng_ust_hip_hipTexRefSetAddress_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t ByteOffset_val);
void btx_push_message_lttng_ust_hip_hipTexRefSetAddress2D_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, textureReference * texRef, HIP_ARRAY_DESCRIPTOR * desc, hipDeviceptr_t dptr, size_t Pitch, size_t _desc_val_length, HIP_ARRAY_DESCRIPTOR * desc_val);
void btx_push_message_lttng_ust_hip_hipTexRefSetAddress2D_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipTexRefSetMaxAnisotropy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, textureReference * texRef, unsigned int maxAniso);
void btx_push_message_lttng_ust_hip_hipTexRefSetMaxAnisotropy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipTexRefSetBorderColor_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, textureReference * texRef, float * pBorderColor);
void btx_push_message_lttng_ust_hip_hipTexRefSetBorderColor_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipTexRefSetMipmapFilterMode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, textureReference * texRef, enum hipTextureFilterMode fm);
void btx_push_message_lttng_ust_hip_hipTexRefSetMipmapFilterMode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipTexRefSetMipmapLevelBias_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, textureReference * texRef, float bias);
void btx_push_message_lttng_ust_hip_hipTexRefSetMipmapLevelBias_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipTexRefSetMipmapLevelClamp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, textureReference * texRef, float minMipMapLevelClamp, float maxMipMapLevelClamp);
void btx_push_message_lttng_ust_hip_hipTexRefSetMipmapLevelClamp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipTexRefSetMipmappedArray_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, textureReference * texRef, struct hipMipmappedArray * mipmappedArray, unsigned int Flags);
void btx_push_message_lttng_ust_hip_hipTexRefSetMipmappedArray_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMipmappedArrayCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipMipmappedArray_t * pHandle, HIP_ARRAY3D_DESCRIPTOR * pMipmappedArrayDesc, unsigned int numMipmapLevels, size_t _pMipmappedArrayDesc_val_length, HIP_ARRAY3D_DESCRIPTOR * pMipmappedArrayDesc_val);
void btx_push_message_lttng_ust_hip_hipMipmappedArrayCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipMipmappedArray_t pHandle_val);
void btx_push_message_lttng_ust_hip_hipMipmappedArrayDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipMipmappedArray_t hMipmappedArray);
void btx_push_message_lttng_ust_hip_hipMipmappedArrayDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMipmappedArrayGetLevel_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipArray_t * pLevelArray, hipMipmappedArray_t hMipMappedArray, unsigned int level);
void btx_push_message_lttng_ust_hip_hipMipmappedArrayGetLevel_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipArray_t pLevelArray_val);
void btx_push_message_lttng_ust_hip_hipApiName_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, uint32_t id);
void btx_push_message_lttng_ust_hip_hipApiName_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, char * hipResult, char * hipResult_val);
void btx_push_message_lttng_ust_hip_hipKernelNameRef_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipFunction_t f);
void btx_push_message_lttng_ust_hip_hipKernelNameRef_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, char * hipResult, char * hipResult_val);
void btx_push_message_lttng_ust_hip_hipKernelNameRefByPtr_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * hostFunction, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipKernelNameRefByPtr_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, char * hipResult, char * hipResult_val);
void btx_push_message_lttng_ust_hip_hipGetStreamDeviceId_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipGetStreamDeviceId_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int hipResult);
void btx_push_message_lttng_ust_hip_hipStreamBeginCapture_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t stream, hipStreamCaptureMode mode);
void btx_push_message_lttng_ust_hip_hipStreamBeginCapture_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipStreamEndCapture_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t stream, hipGraph_t * pGraph);
void btx_push_message_lttng_ust_hip_hipStreamEndCapture_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipGraph_t pGraph_val);
void btx_push_message_lttng_ust_hip_hipStreamGetCaptureInfo_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t stream, hipStreamCaptureStatus * pCaptureStatus, unsigned long long int * pId);
void btx_push_message_lttng_ust_hip_hipStreamGetCaptureInfo_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipStreamCaptureStatus pCaptureStatus_val, unsigned long long int pId_val);
void btx_push_message_lttng_ust_hip_hipStreamGetCaptureInfo_v2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t stream, hipStreamCaptureStatus * captureStatus_out, unsigned long long int * id_out, hipGraph_t * graph_out, hipGraphNode_t ** dependencies_out, size_t * numDependencies_out);
void btx_push_message_lttng_ust_hip_hipStreamGetCaptureInfo_v2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipStreamCaptureStatus captureStatus_out_val, unsigned long long int id_out_val, hipGraph_t graph_out_val, size_t numDependencies_out_val, size_t _dependencies_out_vals_length, hipGraphNode_t * * dependencies_out_vals);
void btx_push_message_lttng_ust_hip_hipStreamIsCapturing_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t stream, hipStreamCaptureStatus * pCaptureStatus);
void btx_push_message_lttng_ust_hip_hipStreamIsCapturing_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipStreamCaptureStatus pCaptureStatus_val);
void btx_push_message_lttng_ust_hip_hipStreamUpdateCaptureDependencies_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t stream, hipGraphNode_t * dependencies, size_t numDependencies, unsigned int flags, size_t _dependencies_vals_length, hipGraphNode_t * dependencies_vals);
void btx_push_message_lttng_ust_hip_hipStreamUpdateCaptureDependencies_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipLaunchHostFunc_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t stream, hipHostFn_t fn, void * userData);
void btx_push_message_lttng_ust_hip_hipLaunchHostFunc_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipThreadExchangeStreamCaptureMode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStreamCaptureMode * mode, hipStreamCaptureMode mode_val);
void btx_push_message_lttng_ust_hip_hipThreadExchangeStreamCaptureMode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipStreamCaptureMode mode_val);
void btx_push_message_lttng_ust_hip_hipGraphCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraph_t * pGraph, unsigned int flags);
void btx_push_message_lttng_ust_hip_hipGraphCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipGraph_t pGraph_val);
void btx_push_message_lttng_ust_hip_hipGraphDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraph_t graph);
void btx_push_message_lttng_ust_hip_hipGraphDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGraphAddDependencies_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraph_t graph, hipGraphNode_t * from, hipGraphNode_t * to, size_t numDependencies, size_t _from_vals_length, hipGraphNode_t * from_vals, size_t _to_vals_length, hipGraphNode_t * to_vals);
void btx_push_message_lttng_ust_hip_hipGraphAddDependencies_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGraphRemoveDependencies_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraph_t graph, hipGraphNode_t * from, hipGraphNode_t * to, size_t numDependencies, size_t _from_vals_length, hipGraphNode_t * from_vals, size_t _to_vals_length, hipGraphNode_t * to_vals);
void btx_push_message_lttng_ust_hip_hipGraphRemoveDependencies_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGraphGetEdges_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraph_t graph, hipGraphNode_t * from, hipGraphNode_t * to, size_t * numEdges);
void btx_push_message_lttng_ust_hip_hipGraphGetEdges_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t numEdges_val, size_t _from_vals_length, hipGraphNode_t * from_vals, size_t _to_vals_length, hipGraphNode_t * to_vals);
void btx_push_message_lttng_ust_hip_hipGraphGetNodes_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraph_t graph, hipGraphNode_t * nodes, size_t * numNodes);
void btx_push_message_lttng_ust_hip_hipGraphGetNodes_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t numNodes_val, size_t _nodes_vals_length, hipGraphNode_t * nodes_vals);
void btx_push_message_lttng_ust_hip_hipGraphGetRootNodes_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraph_t graph, hipGraphNode_t * pRootNodes, size_t * pNumRootNodes);
void btx_push_message_lttng_ust_hip_hipGraphGetRootNodes_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t pNumRootNodes_val, size_t _pRootNodes_vals_length, hipGraphNode_t * pRootNodes_vals);
void btx_push_message_lttng_ust_hip_hipGraphNodeGetDependencies_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphNode_t node, hipGraphNode_t * pDependencies, size_t * pNumDependencies);
void btx_push_message_lttng_ust_hip_hipGraphNodeGetDependencies_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t pNumDependencies_val, size_t _pDependencies_vals_length, hipGraphNode_t * pDependencies_vals);
void btx_push_message_lttng_ust_hip_hipGraphNodeGetDependentNodes_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphNode_t node, hipGraphNode_t * pDependentNodes, size_t * pNumDependentNodes);
void btx_push_message_lttng_ust_hip_hipGraphNodeGetDependentNodes_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t pNumDependentNodes_val, size_t _pDependentNodes_vals_length, hipGraphNode_t * pDependentNodes_vals);
void btx_push_message_lttng_ust_hip_hipGraphNodeGetType_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphNode_t node, hipGraphNodeType * pType);
void btx_push_message_lttng_ust_hip_hipGraphNodeGetType_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipGraphNodeType pType_val);
void btx_push_message_lttng_ust_hip_hipGraphDestroyNode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphNode_t node);
void btx_push_message_lttng_ust_hip_hipGraphDestroyNode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGraphClone_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraph_t * pGraphClone, hipGraph_t originalGraph);
void btx_push_message_lttng_ust_hip_hipGraphClone_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipGraph_t pGraphClone_val);
void btx_push_message_lttng_ust_hip_hipGraphNodeFindInClone_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphNode_t * pNode, hipGraphNode_t originalNode, hipGraph_t clonedGraph);
void btx_push_message_lttng_ust_hip_hipGraphNodeFindInClone_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipGraphNode_t pNode_val);
void btx_push_message_lttng_ust_hip_hipGraphInstantiate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphExec_t * pGraphExec, hipGraph_t graph, hipGraphNode_t * pErrorNode, char * pLogBuffer, size_t bufferSize);
void btx_push_message_lttng_ust_hip_hipGraphInstantiate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipGraphExec_t pGraphExec_val, hipGraphNode_t pErrorNode_val, size_t _pLogBuffer_vals_length, char * pLogBuffer_vals);
void btx_push_message_lttng_ust_hip_hipGraphInstantiateWithFlags_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphExec_t * pGraphExec, hipGraph_t graph, unsigned long long int flags);
void btx_push_message_lttng_ust_hip_hipGraphInstantiateWithFlags_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipGraphExec_t pGraphExec_val);
void btx_push_message_lttng_ust_hip_hipGraphLaunch_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphExec_t graphExec, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipGraphLaunch_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGraphUpload_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphExec_t graphExec, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipGraphUpload_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGraphExecDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphExec_t graphExec);
void btx_push_message_lttng_ust_hip_hipGraphExecDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGraphExecUpdate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphExec_t hGraphExec, hipGraph_t hGraph, hipGraphNode_t * hErrorNode_out, hipGraphExecUpdateResult * updateResult_out);
void btx_push_message_lttng_ust_hip_hipGraphExecUpdate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipGraphNode_t hErrorNode_out_val, hipGraphExecUpdateResult updateResult_out_val);
void btx_push_message_lttng_ust_hip_hipGraphAddKernelNode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphNode_t * pGraphNode, hipGraph_t graph, hipGraphNode_t * pDependencies, size_t numDependencies, hipKernelNodeParams * pNodeParams, size_t _pDependencies_vals_length, hipGraphNode_t * pDependencies_vals, size_t _pNodeParams_val_length, hipKernelNodeParams * pNodeParams_val);
void btx_push_message_lttng_ust_hip_hipGraphAddKernelNode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipGraphNode_t pGraphNode_val);
void btx_push_message_lttng_ust_hip_hipGraphKernelNodeGetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphNode_t node, hipKernelNodeParams * pNodeParams);
void btx_push_message_lttng_ust_hip_hipGraphKernelNodeGetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t _pNodeParams_val_length, hipKernelNodeParams * pNodeParams_val);
void btx_push_message_lttng_ust_hip_hipGraphKernelNodeSetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphNode_t node, hipKernelNodeParams * pNodeParams, size_t _pNodeParams_val_length, hipKernelNodeParams * pNodeParams_val);
void btx_push_message_lttng_ust_hip_hipGraphKernelNodeSetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGraphExecKernelNodeSetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphExec_t hGraphExec, hipGraphNode_t node, hipKernelNodeParams * pNodeParams);
void btx_push_message_lttng_ust_hip_hipGraphExecKernelNodeSetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGraphAddMemcpyNode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphNode_t * pGraphNode, hipGraph_t graph, hipGraphNode_t * pDependencies, size_t numDependencies, hipMemcpy3DParms * pCopyParams, size_t _pDependencies_vals_length, hipGraphNode_t * pDependencies_vals, size_t _pCopyParams_val_length, hipMemcpy3DParms * pCopyParams_val);
void btx_push_message_lttng_ust_hip_hipGraphAddMemcpyNode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipGraphNode_t pGraphNode_val);
void btx_push_message_lttng_ust_hip_hipGraphMemcpyNodeGetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphNode_t node, hipMemcpy3DParms * pNodeParams);
void btx_push_message_lttng_ust_hip_hipGraphMemcpyNodeGetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t _pNodeParams_val_length, hipMemcpy3DParms * pNodeParams_val);
void btx_push_message_lttng_ust_hip_hipGraphMemcpyNodeSetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphNode_t node, hipMemcpy3DParms * pNodeParams, size_t _pNodeParams_val_length, hipMemcpy3DParms * pNodeParams_val);
void btx_push_message_lttng_ust_hip_hipGraphMemcpyNodeSetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGraphKernelNodeSetAttribute_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphNode_t hNode, hipKernelNodeAttrID attr, hipKernelNodeAttrValue * value, size_t _value_val_length, hipKernelNodeAttrValue * value_val);
void btx_push_message_lttng_ust_hip_hipGraphKernelNodeSetAttribute_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGraphKernelNodeGetAttribute_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphNode_t hNode, hipKernelNodeAttrID attr, hipKernelNodeAttrValue * value);
void btx_push_message_lttng_ust_hip_hipGraphKernelNodeGetAttribute_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t _value_val_length, hipKernelNodeAttrValue * value_val);
void btx_push_message_lttng_ust_hip_hipGraphExecMemcpyNodeSetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphExec_t hGraphExec, hipGraphNode_t node, hipMemcpy3DParms * pNodeParams, size_t _pNodeParams_val_length, hipMemcpy3DParms * pNodeParams_val);
void btx_push_message_lttng_ust_hip_hipGraphExecMemcpyNodeSetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGraphAddMemcpyNode1D_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphNode_t * pGraphNode, hipGraph_t graph, hipGraphNode_t * pDependencies, size_t numDependencies, void * dst, void * src, size_t count, hipMemcpyKind kind, size_t _pDependencies_vals_length, hipGraphNode_t * pDependencies_vals);
void btx_push_message_lttng_ust_hip_hipGraphAddMemcpyNode1D_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipGraphNode_t pGraphNode_val);
void btx_push_message_lttng_ust_hip_hipGraphMemcpyNodeSetParams1D_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphNode_t node, void * dst, void * src, size_t count, hipMemcpyKind kind);
void btx_push_message_lttng_ust_hip_hipGraphMemcpyNodeSetParams1D_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGraphExecMemcpyNodeSetParams1D_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphExec_t hGraphExec, hipGraphNode_t node, void * dst, void * src, size_t count, hipMemcpyKind kind);
void btx_push_message_lttng_ust_hip_hipGraphExecMemcpyNodeSetParams1D_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGraphAddMemcpyNodeFromSymbol_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphNode_t * pGraphNode, hipGraph_t graph, hipGraphNode_t * pDependencies, size_t numDependencies, void * dst, void * symbol, size_t count, size_t offset, hipMemcpyKind kind, size_t _pDependencies_vals_length, hipGraphNode_t * pDependencies_vals);
void btx_push_message_lttng_ust_hip_hipGraphAddMemcpyNodeFromSymbol_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipGraphNode_t pGraphNode_val);
void btx_push_message_lttng_ust_hip_hipGraphMemcpyNodeSetParamsFromSymbol_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphNode_t node, void * dst, void * symbol, size_t count, size_t offset, hipMemcpyKind kind);
void btx_push_message_lttng_ust_hip_hipGraphMemcpyNodeSetParamsFromSymbol_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGraphExecMemcpyNodeSetParamsFromSymbol_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphExec_t hGraphExec, hipGraphNode_t node, void * dst, void * symbol, size_t count, size_t offset, hipMemcpyKind kind);
void btx_push_message_lttng_ust_hip_hipGraphExecMemcpyNodeSetParamsFromSymbol_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGraphAddMemcpyNodeToSymbol_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphNode_t * pGraphNode, hipGraph_t graph, hipGraphNode_t * pDependencies, size_t numDependencies, void * symbol, void * src, size_t count, size_t offset, hipMemcpyKind kind, size_t _pDependencies_vals_length, hipGraphNode_t * pDependencies_vals);
void btx_push_message_lttng_ust_hip_hipGraphAddMemcpyNodeToSymbol_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipGraphNode_t pGraphNode_val);
void btx_push_message_lttng_ust_hip_hipGraphMemcpyNodeSetParamsToSymbol_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphNode_t node, void * symbol, void * src, size_t count, size_t offset, hipMemcpyKind kind);
void btx_push_message_lttng_ust_hip_hipGraphMemcpyNodeSetParamsToSymbol_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGraphExecMemcpyNodeSetParamsToSymbol_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphExec_t hGraphExec, hipGraphNode_t node, void * symbol, void * src, size_t count, size_t offset, hipMemcpyKind kind);
void btx_push_message_lttng_ust_hip_hipGraphExecMemcpyNodeSetParamsToSymbol_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGraphAddMemsetNode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphNode_t * pGraphNode, hipGraph_t graph, hipGraphNode_t * pDependencies, size_t numDependencies, hipMemsetParams * pMemsetParams, size_t _pDependencies_vals_length, hipGraphNode_t * pDependencies_vals, size_t _pMemsetParams_val_length, hipMemsetParams * pMemsetParams_val);
void btx_push_message_lttng_ust_hip_hipGraphAddMemsetNode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipGraphNode_t pGraphNode_val);
void btx_push_message_lttng_ust_hip_hipGraphMemsetNodeGetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphNode_t node, hipMemsetParams * pNodeParams);
void btx_push_message_lttng_ust_hip_hipGraphMemsetNodeGetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t _pNodeParams_val_length, hipMemsetParams * pNodeParams_val);
void btx_push_message_lttng_ust_hip_hipGraphMemsetNodeSetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphNode_t node, hipMemsetParams * pNodeParams, size_t _pNodeParams_val_length, hipMemsetParams * pNodeParams_val);
void btx_push_message_lttng_ust_hip_hipGraphMemsetNodeSetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGraphExecMemsetNodeSetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphExec_t hGraphExec, hipGraphNode_t node, hipMemsetParams * pNodeParams, size_t _pNodeParams_val_length, hipMemsetParams * pNodeParams_val);
void btx_push_message_lttng_ust_hip_hipGraphExecMemsetNodeSetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGraphAddHostNode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphNode_t * pGraphNode, hipGraph_t graph, hipGraphNode_t * pDependencies, size_t numDependencies, hipHostNodeParams * pNodeParams, size_t _pDependencies_vals_length, hipGraphNode_t * pDependencies_vals, size_t _pNodeParams_val_length, hipHostNodeParams * pNodeParams_val);
void btx_push_message_lttng_ust_hip_hipGraphAddHostNode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipGraphNode_t pGraphNode_val);
void btx_push_message_lttng_ust_hip_hipGraphHostNodeGetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphNode_t node, hipHostNodeParams * pNodeParams);
void btx_push_message_lttng_ust_hip_hipGraphHostNodeGetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t _pNodeParams_val_length, hipHostNodeParams * pNodeParams_val);
void btx_push_message_lttng_ust_hip_hipGraphHostNodeSetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphNode_t node, hipHostNodeParams * pNodeParams, size_t _pNodeParams_val_length, hipHostNodeParams * pNodeParams_val);
void btx_push_message_lttng_ust_hip_hipGraphHostNodeSetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGraphExecHostNodeSetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphExec_t hGraphExec, hipGraphNode_t node, hipHostNodeParams * pNodeParams, size_t _pNodeParams_val_length, hipHostNodeParams * pNodeParams_val);
void btx_push_message_lttng_ust_hip_hipGraphExecHostNodeSetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGraphAddChildGraphNode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphNode_t * pGraphNode, hipGraph_t graph, hipGraphNode_t * pDependencies, size_t numDependencies, hipGraph_t childGraph, size_t _pDependencies_vals_length, hipGraphNode_t * pDependencies_vals);
void btx_push_message_lttng_ust_hip_hipGraphAddChildGraphNode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipGraphNode_t pGraphNode_val);
void btx_push_message_lttng_ust_hip_hipGraphChildGraphNodeGetGraph_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphNode_t node, hipGraph_t * pGraph);
void btx_push_message_lttng_ust_hip_hipGraphChildGraphNodeGetGraph_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipGraph_t pGraph_val);
void btx_push_message_lttng_ust_hip_hipGraphExecChildGraphNodeSetParams_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphExec_t hGraphExec, hipGraphNode_t node, hipGraph_t childGraph);
void btx_push_message_lttng_ust_hip_hipGraphExecChildGraphNodeSetParams_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGraphAddEmptyNode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphNode_t * pGraphNode, hipGraph_t graph, hipGraphNode_t * pDependencies, size_t numDependencies, size_t _pDependencies_vals_length, hipGraphNode_t * pDependencies_vals);
void btx_push_message_lttng_ust_hip_hipGraphAddEmptyNode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipGraphNode_t pGraphNode_val);
void btx_push_message_lttng_ust_hip_hipGraphAddEventRecordNode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphNode_t * pGraphNode, hipGraph_t graph, hipGraphNode_t * pDependencies, size_t numDependencies, hipEvent_t event, size_t _pDependencies_vals_length, hipGraphNode_t * pDependencies_vals);
void btx_push_message_lttng_ust_hip_hipGraphAddEventRecordNode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipGraphNode_t pGraphNode_val);
void btx_push_message_lttng_ust_hip_hipGraphEventRecordNodeGetEvent_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphNode_t node, hipEvent_t * event_out);
void btx_push_message_lttng_ust_hip_hipGraphEventRecordNodeGetEvent_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipEvent_t event_out_val);
void btx_push_message_lttng_ust_hip_hipGraphEventRecordNodeSetEvent_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphNode_t node, hipEvent_t event);
void btx_push_message_lttng_ust_hip_hipGraphEventRecordNodeSetEvent_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGraphExecEventRecordNodeSetEvent_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphExec_t hGraphExec, hipGraphNode_t hNode, hipEvent_t event);
void btx_push_message_lttng_ust_hip_hipGraphExecEventRecordNodeSetEvent_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGraphAddEventWaitNode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphNode_t * pGraphNode, hipGraph_t graph, hipGraphNode_t * pDependencies, size_t numDependencies, hipEvent_t event, size_t _pDependencies_vals_length, hipGraphNode_t * pDependencies_vals);
void btx_push_message_lttng_ust_hip_hipGraphAddEventWaitNode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipGraphNode_t pGraphNode_val);
void btx_push_message_lttng_ust_hip_hipGraphEventWaitNodeGetEvent_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphNode_t node, hipEvent_t * event_out);
void btx_push_message_lttng_ust_hip_hipGraphEventWaitNodeGetEvent_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipEvent_t event_out_val);
void btx_push_message_lttng_ust_hip_hipGraphEventWaitNodeSetEvent_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphNode_t node, hipEvent_t event);
void btx_push_message_lttng_ust_hip_hipGraphEventWaitNodeSetEvent_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGraphExecEventWaitNodeSetEvent_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphExec_t hGraphExec, hipGraphNode_t hNode, hipEvent_t event);
void btx_push_message_lttng_ust_hip_hipGraphExecEventWaitNodeSetEvent_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipDeviceGetGraphMemAttribute_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int device, hipGraphMemAttributeType attr, void * value);
void btx_push_message_lttng_ust_hip_hipDeviceGetGraphMemAttribute_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t _value_val_length, void * value_val);
void btx_push_message_lttng_ust_hip_hipDeviceSetGraphMemAttribute_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int device, hipGraphMemAttributeType attr, void * value, size_t _value_val_length, void * value_val);
void btx_push_message_lttng_ust_hip_hipDeviceSetGraphMemAttribute_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipDeviceGraphMemTrim_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int device);
void btx_push_message_lttng_ust_hip_hipDeviceGraphMemTrim_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipUserObjectCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipUserObject_t * object_out, void * ptr, hipHostFn_t destroy, unsigned int initialRefcount, unsigned int flags);
void btx_push_message_lttng_ust_hip_hipUserObjectCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipUserObject_t object_out_val);
void btx_push_message_lttng_ust_hip_hipUserObjectRelease_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipUserObject_t object, unsigned int count);
void btx_push_message_lttng_ust_hip_hipUserObjectRelease_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipUserObjectRetain_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipUserObject_t object, unsigned int count);
void btx_push_message_lttng_ust_hip_hipUserObjectRetain_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGraphRetainUserObject_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraph_t graph, hipUserObject_t object, unsigned int count, unsigned int flags);
void btx_push_message_lttng_ust_hip_hipGraphRetainUserObject_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGraphReleaseUserObject_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraph_t graph, hipUserObject_t object, unsigned int count);
void btx_push_message_lttng_ust_hip_hipGraphReleaseUserObject_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemAddressFree_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * devPtr, size_t size);
void btx_push_message_lttng_ust_hip_hipMemAddressFree_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemAddressReserve_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void ** ptr, size_t size, size_t alignment, void * addr, unsigned long long int flags);
void btx_push_message_lttng_ust_hip_hipMemAddressReserve_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, void * ptr_val);
void btx_push_message_lttng_ust_hip_hipMemCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipMemGenericAllocationHandle_t * handle, size_t size, hipMemAllocationProp * prop, unsigned long long int flags, size_t _prop_val_length, hipMemAllocationProp * prop_val);
void btx_push_message_lttng_ust_hip_hipMemCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipMemGenericAllocationHandle_t handle_val);
void btx_push_message_lttng_ust_hip_hipMemExportToShareableHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * shareableHandle, hipMemGenericAllocationHandle_t handle, hipMemAllocationHandleType handleType, unsigned long long int flags);
void btx_push_message_lttng_ust_hip_hipMemExportToShareableHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t _shareableHandle_val_length, void * shareableHandle_val);
void btx_push_message_lttng_ust_hip_hipMemGetAccess_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, unsigned long long int * flags, hipMemLocation * location, void * ptr, size_t _location_val_length, hipMemLocation * location_val);
void btx_push_message_lttng_ust_hip_hipMemGetAccess_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, unsigned long long int flags_val);
void btx_push_message_lttng_ust_hip_hipMemGetAllocationGranularity_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, size_t * granularity, hipMemAllocationProp * prop, hipMemAllocationGranularity_flags option, size_t _prop_val_length, hipMemAllocationProp * prop_val);
void btx_push_message_lttng_ust_hip_hipMemGetAllocationGranularity_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t granularity_val);
void btx_push_message_lttng_ust_hip_hipMemGetAllocationPropertiesFromHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipMemAllocationProp * prop, hipMemGenericAllocationHandle_t handle);
void btx_push_message_lttng_ust_hip_hipMemGetAllocationPropertiesFromHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, size_t _prop_val_length, hipMemAllocationProp * prop_val);
void btx_push_message_lttng_ust_hip_hipMemImportFromShareableHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipMemGenericAllocationHandle_t * handle, void * osHandle, hipMemAllocationHandleType shHandleType, size_t _osHandle_val_length, void * osHandle_val);
void btx_push_message_lttng_ust_hip_hipMemImportFromShareableHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipMemGenericAllocationHandle_t handle_val);
void btx_push_message_lttng_ust_hip_hipMemMap_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * ptr, size_t size, size_t offset, hipMemGenericAllocationHandle_t handle, unsigned long long int flags);
void btx_push_message_lttng_ust_hip_hipMemMap_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemMapArrayAsync_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipArrayMapInfo * mapInfoList, unsigned int count, hipStream_t stream, size_t _mapInfoList_val_length, hipArrayMapInfo * mapInfoList_val);
void btx_push_message_lttng_ust_hip_hipMemMapArrayAsync_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemRelease_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipMemGenericAllocationHandle_t handle);
void btx_push_message_lttng_ust_hip_hipMemRelease_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemRetainAllocationHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipMemGenericAllocationHandle_t * handle, void * addr);
void btx_push_message_lttng_ust_hip_hipMemRetainAllocationHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipMemGenericAllocationHandle_t handle_val);
void btx_push_message_lttng_ust_hip_hipMemSetAccess_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * ptr, size_t size, hipMemAccessDesc * desc, size_t count, size_t _desc_vals_length, hipMemAccessDesc * desc_vals);
void btx_push_message_lttng_ust_hip_hipMemSetAccess_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemUnmap_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * ptr, size_t size);
void btx_push_message_lttng_ust_hip_hipMemUnmap_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGLGetDevices_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, unsigned int * pHipDeviceCount, int * pHipDevices, unsigned int hipDeviceCount, hipGLDeviceList deviceList);
void btx_push_message_lttng_ust_hip_hipGLGetDevices_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, unsigned int pHipDeviceCount_val, size_t _pHipDevices_vals_length, int * pHipDevices_vals);
void btx_push_message_lttng_ust_hip_hipGraphicsGLRegisterBuffer_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphicsResource ** resource, GLuint buffer, unsigned int flags);
void btx_push_message_lttng_ust_hip_hipGraphicsGLRegisterBuffer_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipGraphicsResource * resource_val);
void btx_push_message_lttng_ust_hip_hipGraphicsGLRegisterImage_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphicsResource ** resource, GLuint image, GLenum target, unsigned int flags);
void btx_push_message_lttng_ust_hip_hipGraphicsGLRegisterImage_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipGraphicsResource * resource_val);
void btx_push_message_lttng_ust_hip_hipGraphicsMapResources_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int count, hipGraphicsResource_t * resources, hipStream_t stream, size_t _resources_vals_length, hipGraphicsResource_t * resources_vals);
void btx_push_message_lttng_ust_hip_hipGraphicsMapResources_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGraphicsSubResourceGetMappedArray_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipArray_t * array, hipGraphicsResource_t resource, unsigned int arrayIndex, unsigned int mipLevel);
void btx_push_message_lttng_ust_hip_hipGraphicsSubResourceGetMappedArray_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipArray_t array_val);
void btx_push_message_lttng_ust_hip_hipGraphicsResourceGetMappedPointer_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void ** devPtr, size_t * size, hipGraphicsResource_t resource);
void btx_push_message_lttng_ust_hip_hipGraphicsResourceGetMappedPointer_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, void * devPtr_val, size_t size_val);
void btx_push_message_lttng_ust_hip_hipGraphicsUnmapResources_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int count, hipGraphicsResource_t * resources, hipStream_t stream, size_t _resources_vals_length, hipGraphicsResource_t * resources_vals);
void btx_push_message_lttng_ust_hip_hipGraphicsUnmapResources_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGraphicsUnregisterResource_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphicsResource_t resource);
void btx_push_message_lttng_ust_hip_hipGraphicsUnregisterResource_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpy_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dst, void * src, size_t sizeBytes, hipMemcpyKind kind);
void btx_push_message_lttng_ust_hip_hipMemcpy_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpyToSymbol_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * symbol, void * src, size_t sizeBytes, size_t offset, hipMemcpyKind kind);
void btx_push_message_lttng_ust_hip_hipMemcpyToSymbol_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpyFromSymbol_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dst, void * symbol, size_t sizeBytes, size_t offset, hipMemcpyKind kind);
void btx_push_message_lttng_ust_hip_hipMemcpyFromSymbol_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpy2D_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dst, size_t dpitch, void * src, size_t spitch, size_t width, size_t height, hipMemcpyKind kind);
void btx_push_message_lttng_ust_hip_hipMemcpy2D_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpy2DFromArray_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dst, size_t dpitch, hipArray_const_t src, size_t wOffset, size_t hOffset, size_t width, size_t height, hipMemcpyKind kind);
void btx_push_message_lttng_ust_hip_hipMemcpy2DFromArray_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpy3D_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, struct hipMemcpy3DParms * p);
void btx_push_message_lttng_ust_hip_hipMemcpy3D_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemset_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dst, int value, size_t sizeBytes);
void btx_push_message_lttng_ust_hip_hipMemset_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemsetAsync_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dst, int value, size_t sizeBytes, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipMemsetAsync_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemset2D_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dst, size_t pitch, int value, size_t width, size_t height);
void btx_push_message_lttng_ust_hip_hipMemset2D_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemset2DAsync_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dst, size_t pitch, int value, size_t width, size_t height, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipMemset2DAsync_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemset3DAsync_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipPitchedPtr pitchedDevPtr, int value, hipExtent extent, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipMemset3DAsync_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemset3D_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipPitchedPtr pitchedDevPtr, int value, hipExtent extent);
void btx_push_message_lttng_ust_hip_hipMemset3D_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpyAsync_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dst, void * src, size_t sizeBytes, hipMemcpyKind kind, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipMemcpyAsync_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpy3DAsync_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipMemcpy3DParms * p, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipMemcpy3DAsync_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpy2DAsync_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dst, size_t dpitch, void * src, size_t spitch, size_t width, size_t height, hipMemcpyKind kind, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipMemcpy2DAsync_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpyFromSymbolAsync_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dst, void * symbol, size_t sizeBytes, size_t offset, hipMemcpyKind kind, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipMemcpyFromSymbolAsync_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpyToSymbolAsync_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * symbol, void * src, size_t sizeBytes, size_t offset, hipMemcpyKind kind, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipMemcpyToSymbolAsync_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpyFromArray_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dst, hipArray_const_t src, size_t wOffsetSrc, size_t hOffset, size_t count, hipMemcpyKind kind);
void btx_push_message_lttng_ust_hip_hipMemcpyFromArray_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpy2DToArray_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipArray * dst, size_t wOffset, size_t hOffset, void * src, size_t spitch, size_t width, size_t height, hipMemcpyKind kind);
void btx_push_message_lttng_ust_hip_hipMemcpy2DToArray_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpy2DFromArrayAsync_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * dst, size_t dpitch, hipArray_const_t src, size_t wOffsetSrc, size_t hOffsetSrc, size_t width, size_t height, hipMemcpyKind kind, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipMemcpy2DFromArrayAsync_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipMemcpy2DToArrayAsync_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipArray * dst, size_t wOffset, size_t hOffset, void * src, size_t spitch, size_t width, size_t height, hipMemcpyKind kind, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipMemcpy2DToArrayAsync_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipStreamQuery_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipStreamQuery_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipStreamSynchronize_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipStreamSynchronize_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipStreamGetPriority_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t stream, int * priority);
void btx_push_message_lttng_ust_hip_hipStreamGetPriority_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipStreamWaitEvent_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t stream, hipEvent_t event, unsigned int flags);
void btx_push_message_lttng_ust_hip_hipStreamWaitEvent_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipStreamGetFlags_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t stream, unsigned int * flags);
void btx_push_message_lttng_ust_hip_hipStreamGetFlags_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipStreamAddCallback_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t stream, hipStreamCallback_t callback, void * userData, unsigned int flags);
void btx_push_message_lttng_ust_hip_hipStreamAddCallback_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipEventRecord_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipEvent_t event, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipEventRecord_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipLaunchCooperativeKernel_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * f, dim3 gridDim, dim3 blockDim, void ** kernelParams, uint32_t sharedMemBytes, hipStream_t hStream);
void btx_push_message_lttng_ust_hip_hipLaunchCooperativeKernel_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipLaunchKernel_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * function_address, dim3 numBlocks, dim3 dimBlocks, void ** args, size_t sharedMemBytes, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipLaunchKernel_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGraphLaunch_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraphExec_t graphExec, hipStream_t stream);
void btx_push_message_lttng_ust_hip_hipGraphLaunch_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipStreamBeginCapture_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t stream, hipStreamCaptureMode mode);
void btx_push_message_lttng_ust_hip_hipStreamBeginCapture_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipStreamEndCapture_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t stream, hipGraph_t * pGraph);
void btx_push_message_lttng_ust_hip_hipStreamEndCapture_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipStreamIsCapturing_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t stream, hipStreamCaptureStatus * pCaptureStatus);
void btx_push_message_lttng_ust_hip_hipStreamIsCapturing_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipStreamGetCaptureInfo_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t stream, hipStreamCaptureStatus * pCaptureStatus, unsigned long long int * pId);
void btx_push_message_lttng_ust_hip_hipStreamGetCaptureInfo_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipStreamGetCaptureInfo_v2_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t stream, hipStreamCaptureStatus * captureStatus_out, unsigned long long int * id_out, hipGraph_t * graph_out, hipGraphNode_t ** dependencies_out, size_t * numDependencies_out);
void btx_push_message_lttng_ust_hip_hipStreamGetCaptureInfo_v2_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipLaunchHostFunc_spt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipStream_t stream, hipHostFn_t fn, void * userData);
void btx_push_message_lttng_ust_hip_hipLaunchHostFunc_spt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hiprtcGetErrorString_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hiprtcResult result);
void btx_push_message_lttng_ust_hip_hiprtcGetErrorString_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, char * hipResult);
void btx_push_message_lttng_ust_hip_hiprtcVersion_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int * major, int * minor);
void btx_push_message_lttng_ust_hip_hiprtcVersion_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hiprtcResult hipResult);
void btx_push_message_lttng_ust_hip_hiprtcAddNameExpression_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hiprtcProgram prog, char * name_expression);
void btx_push_message_lttng_ust_hip_hiprtcAddNameExpression_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hiprtcResult hipResult);
void btx_push_message_lttng_ust_hip_hiprtcCompileProgram_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hiprtcProgram prog, int numOptions, char ** options);
void btx_push_message_lttng_ust_hip_hiprtcCompileProgram_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hiprtcResult hipResult);
void btx_push_message_lttng_ust_hip_hiprtcCreateProgram_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hiprtcProgram * prog, char * src, char * name, int numHeaders, char ** headers, char ** includeNames);
void btx_push_message_lttng_ust_hip_hiprtcCreateProgram_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hiprtcResult hipResult);
void btx_push_message_lttng_ust_hip_hiprtcDestroyProgram_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hiprtcProgram * prog);
void btx_push_message_lttng_ust_hip_hiprtcDestroyProgram_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hiprtcResult hipResult);
void btx_push_message_lttng_ust_hip_hiprtcGetLoweredName_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hiprtcProgram prog, char * name_expression, char ** lowered_name);
void btx_push_message_lttng_ust_hip_hiprtcGetLoweredName_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hiprtcResult hipResult);
void btx_push_message_lttng_ust_hip_hiprtcGetProgramLog_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hiprtcProgram prog, char * log);
void btx_push_message_lttng_ust_hip_hiprtcGetProgramLog_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hiprtcResult hipResult);
void btx_push_message_lttng_ust_hip_hiprtcGetProgramLogSize_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hiprtcProgram prog, size_t * logSizeRet);
void btx_push_message_lttng_ust_hip_hiprtcGetProgramLogSize_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hiprtcResult hipResult);
void btx_push_message_lttng_ust_hip_hiprtcGetCode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hiprtcProgram prog, char * code);
void btx_push_message_lttng_ust_hip_hiprtcGetCode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hiprtcResult hipResult);
void btx_push_message_lttng_ust_hip_hiprtcGetCodeSize_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hiprtcProgram prog, size_t * codeSizeRet);
void btx_push_message_lttng_ust_hip_hiprtcGetCodeSize_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hiprtcResult hipResult);
void btx_push_message_lttng_ust_hip_hiprtcGetBitcode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hiprtcProgram prog, char * bitcode);
void btx_push_message_lttng_ust_hip_hiprtcGetBitcode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hiprtcResult hipResult);
void btx_push_message_lttng_ust_hip_hiprtcGetBitcodeSize_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hiprtcProgram prog, size_t * bitcode_size);
void btx_push_message_lttng_ust_hip_hiprtcGetBitcodeSize_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hiprtcResult hipResult);
void btx_push_message_lttng_ust_hip_hiprtcLinkCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, unsigned int num_options, hiprtcJIT_option * option_ptr, void ** option_vals_pptr, hiprtcLinkState * hip_link_state_ptr);
void btx_push_message_lttng_ust_hip_hiprtcLinkCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hiprtcResult hipResult);
void btx_push_message_lttng_ust_hip_hiprtcLinkAddFile_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hiprtcLinkState hip_link_state, hiprtcJITInputType input_type, char * file_path, unsigned int num_options, hiprtcJIT_option * options_ptr, void ** option_values);
void btx_push_message_lttng_ust_hip_hiprtcLinkAddFile_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hiprtcResult hipResult);
void btx_push_message_lttng_ust_hip_hiprtcLinkAddData_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hiprtcLinkState hip_link_state, hiprtcJITInputType input_type, void * image, size_t image_size, char * name, unsigned int num_options, hiprtcJIT_option * options_ptr, void ** option_values);
void btx_push_message_lttng_ust_hip_hiprtcLinkAddData_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hiprtcResult hipResult);
void btx_push_message_lttng_ust_hip_hiprtcLinkComplete_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hiprtcLinkState hip_link_state, void ** bin_out, size_t * size_out);
void btx_push_message_lttng_ust_hip_hiprtcLinkComplete_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hiprtcResult hipResult);
void btx_push_message_lttng_ust_hip_hiprtcLinkDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hiprtcLinkState hip_link_state);
void btx_push_message_lttng_ust_hip_hiprtcLinkDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hiprtcResult hipResult);
void btx_push_message_lttng_ust_hip_amd_dbgapi_get_build_name_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_hip_amd_dbgapi_get_build_name_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, char * hipResult, char * hipResult_val);
void btx_push_message_lttng_ust_hip_amd_dbgapi_get_git_hash_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_hip_amd_dbgapi_get_git_hash_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, char * hipResult, char * hipResult_val);
void btx_push_message_lttng_ust_hip_amd_dbgapi_get_build_id_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_hip_amd_dbgapi_get_build_id_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, size_t hipResult);
void btx_push_message_lttng_ust_hip_hipExtModuleLaunchKernel_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipFunction_t f, uint32_t globalWorkSizeX, uint32_t globalWorkSizeY, uint32_t globalWorkSizeZ, uint32_t localWorkSizeX, uint32_t localWorkSizeY, uint32_t localWorkSizeZ, size_t sharedMemBytes, hipStream_t hStream, void ** kernelParams, void ** extra, hipEvent_t startEvent, hipEvent_t stopEvent, uint32_t flags);
void btx_push_message_lttng_ust_hip_hipExtModuleLaunchKernel_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipHccModuleLaunchKernel_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipFunction_t f, uint32_t globalWorkSizeX, uint32_t globalWorkSizeY, uint32_t globalWorkSizeZ, uint32_t localWorkSizeX, uint32_t localWorkSizeY, uint32_t localWorkSizeZ, size_t sharedMemBytes, hipStream_t hStream, void ** kernelParams, void ** extra, hipEvent_t startEvent, hipEvent_t stopEvent);
void btx_push_message_lttng_ust_hip_hipHccModuleLaunchKernel_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip__ZN8hip_impl22hipLaunchKernelGGLImplEmRK4dim3S2_jP12ihipStream_tPPv_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, uintptr_t function_address, dim3 * numBlocks, dim3 * dimBlocks, uint32_t sharedMemBytes, hipStream_t stream, void ** kernarg, size_t _numBlocks_val_length, dim3 * numBlocks_val, size_t _dimBlocks_val_length, dim3 * dimBlocks_val);
void btx_push_message_lttng_ust_hip__ZN8hip_impl22hipLaunchKernelGGLImplEmRK4dim3S2_jP12ihipStream_tPPv_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_hip__Z22hipCreateSurfaceObjectPP13__hip_surfacePK15hipResourceDesc_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipSurfaceObject_t * pSurfObject, hipResourceDesc * pResDesc, size_t _pResDesc_val_length, hipResourceDesc * pResDesc_val);
void btx_push_message_lttng_ust_hip__Z22hipCreateSurfaceObjectPP13__hip_surfacePK15hipResourceDesc_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult, hipSurfaceObject_t pSurfObject_val);
void btx_push_message_lttng_ust_hip__Z23hipDestroySurfaceObjectP13__hip_surface_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipSurfaceObject_t surfaceObject);
void btx_push_message_lttng_ust_hip__Z23hipDestroySurfaceObjectP13__hip_surface_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip__Z24hipHccModuleLaunchKernelP18ihipModuleSymbol_tjjjjjjmP12ihipStream_tPPvS4_P11ihipEvent_tS6__entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipFunction_t f, uint32_t globalWorkSizeX, uint32_t globalWorkSizeY, uint32_t globalWorkSizeZ, uint32_t localWorkSizeX, uint32_t localWorkSizeY, uint32_t localWorkSizeZ, size_t sharedMemBytes, hipStream_t hStream, void ** kernelParams, void ** extra, hipEvent_t startEvent, hipEvent_t stopEvent);
void btx_push_message_lttng_ust_hip__Z24hipHccModuleLaunchKernelP18ihipModuleSymbol_tjjjjjjmP12ihipStream_tPPvS4_P11ihipEvent_tS6__exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip__Z24hipExtModuleLaunchKernelP18ihipModuleSymbol_tjjjjjjmP12ihipStream_tPPvS4_P11ihipEvent_tS6_j_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipFunction_t f, uint32_t globalWorkSizeX, uint32_t globalWorkSizeY, uint32_t globalWorkSizeZ, uint32_t localWorkSizeX, uint32_t localWorkSizeY, uint32_t localWorkSizeZ, size_t sharedMemBytes, hipStream_t hStream, void ** kernelParams, void ** extra, hipEvent_t startEvent, hipEvent_t stopEvent, uint32_t flags);
void btx_push_message_lttng_ust_hip__Z24hipExtModuleLaunchKernelP18ihipModuleSymbol_tjjjjjjmP12ihipStream_tPPvS4_P11ihipEvent_tS6_j_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip_hipGraphDebugDotPrint_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipGraph_t graph, char * fName, unsigned int flag, char * fName_val);
void btx_push_message_lttng_ust_hip_hipGraphDebugDotPrint_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipError_t hipResult);
void btx_push_message_lttng_ust_hip___hipRegisterFatBinary_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * data);
void btx_push_message_lttng_ust_hip___hipRegisterFatBinary_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void ** hipResult);
void btx_push_message_lttng_ust_hip___hipRegisterFunction_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void ** modules, void * hostFunction, char * deviceFunction, char * deviceName, unsigned int threadLimit, uint3 * tid, uint3 * bid, dim3 * blockDim, dim3 * gridDim, int * wSize);
void btx_push_message_lttng_ust_hip___hipRegisterFunction_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_hip___hipRegisterManagedVar_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void ** modules, void ** pointer, void * init_value, char * name, size_t size, unsigned int align);
void btx_push_message_lttng_ust_hip___hipRegisterManagedVar_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_hip___hipRegisterSurface_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void ** modules, void * var, char * hostVar, char * deviceVar, int type, int ext);
void btx_push_message_lttng_ust_hip___hipRegisterSurface_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_hip___hipRegisterTexture_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void ** modules, void * var, char * hostVar, char * deviceVar, int type, int norm, int ext);
void btx_push_message_lttng_ust_hip___hipRegisterTexture_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_hip___hipRegisterVar_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void ** modules, void * var, char * hostVar, char * deviceVar, int ext, size_t size, int constant, int global);
void btx_push_message_lttng_ust_hip___hipRegisterVar_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_hip___hipUnregisterFatBinary_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void ** modules);
void btx_push_message_lttng_ust_hip___hipUnregisterFatBinary_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_hip_hipGetCmdName_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, uint32_t id);
void btx_push_message_lttng_ust_hip_hipGetCmdName_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, char * hipResult);
void btx_push_message_lttng_ust_hip_hipRegisterTracerCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, hipRegisterTracerCallback_callback_t * function);
void btx_push_message_lttng_ust_hip_hipRegisterTracerCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);


void btx_downstream_set_environment_hostname(
    void *btx_handle, const char* hostname);

#ifdef __cplusplus
}
#endif
