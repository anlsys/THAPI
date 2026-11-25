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

void btx_push_message_lttng_ust_ze_zeInit_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_init_flags_t flags);
void btx_push_message_lttng_ust_ze_zeInit_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeDriverGet_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, uint32_t * pCount, ze_driver_handle_t * phDrivers, uint32_t pCount_val);
void btx_push_message_lttng_ust_ze_zeDriverGet_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _phDrivers_vals_length, ze_driver_handle_t * phDrivers_vals);
void btx_push_message_lttng_ust_ze_zeInitDrivers_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, uint32_t * pCount, ze_driver_handle_t * phDrivers, ze_init_driver_type_desc_t * desc, size_t _desc_val_length, ze_init_driver_type_desc_t * desc_val, uint32_t pCount_val);
void btx_push_message_lttng_ust_ze_zeInitDrivers_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _phDrivers_vals_length, ze_driver_handle_t * phDrivers_vals);
void btx_push_message_lttng_ust_ze_zeDriverGetApiVersion_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_driver_handle_t hDriver, ze_api_version_t * version);
void btx_push_message_lttng_ust_ze_zeDriverGetApiVersion_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_api_version_t version_val);
void btx_push_message_lttng_ust_ze_zeDriverGetProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_driver_handle_t hDriver, ze_driver_properties_t * pDriverProperties);
void btx_push_message_lttng_ust_ze_zeDriverGetProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pDriverProperties_val_length, ze_driver_properties_t * pDriverProperties_val);
void btx_push_message_lttng_ust_ze_zeDriverGetIpcProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_driver_handle_t hDriver, ze_driver_ipc_properties_t * pIpcProperties);
void btx_push_message_lttng_ust_ze_zeDriverGetIpcProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pIpcProperties_val_length, ze_driver_ipc_properties_t * pIpcProperties_val);
void btx_push_message_lttng_ust_ze_zeDriverGetExtensionProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_driver_handle_t hDriver, uint32_t * pCount, ze_driver_extension_properties_t * pExtensionProperties, uint32_t pCount_val);
void btx_push_message_lttng_ust_ze_zeDriverGetExtensionProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _pExtensionProperties_vals_length, ze_driver_extension_properties_t * pExtensionProperties_vals);
void btx_push_message_lttng_ust_ze_zeDriverGetExtensionFunctionAddress_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_driver_handle_t hDriver, char * name, void ** ppFunctionAddress, char * name_val);
void btx_push_message_lttng_ust_ze_zeDriverGetExtensionFunctionAddress_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, void * ppFunctionAddress_val);
void btx_push_message_lttng_ust_ze_zeDriverGetLastErrorDescription_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_driver_handle_t hDriver, char ** ppString);
void btx_push_message_lttng_ust_ze_zeDriverGetLastErrorDescription_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, char * ppString_val_val);
void btx_push_message_lttng_ust_ze_zeDeviceGet_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_driver_handle_t hDriver, uint32_t * pCount, ze_device_handle_t * phDevices, uint32_t pCount_val);
void btx_push_message_lttng_ust_ze_zeDeviceGet_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _phDevices_vals_length, ze_device_handle_t * phDevices_vals);
void btx_push_message_lttng_ust_ze_zeDeviceGetRootDevice_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_handle_t hDevice, ze_device_handle_t * phRootDevice);
void btx_push_message_lttng_ust_ze_zeDeviceGetRootDevice_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_device_handle_t phRootDevice_val);
void btx_push_message_lttng_ust_ze_zeDeviceGetSubDevices_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_handle_t hDevice, uint32_t * pCount, ze_device_handle_t * phSubdevices, uint32_t pCount_val);
void btx_push_message_lttng_ust_ze_zeDeviceGetSubDevices_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _phSubdevices_vals_length, ze_device_handle_t * phSubdevices_vals);
void btx_push_message_lttng_ust_ze_zeDeviceGetProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_handle_t hDevice, ze_device_properties_t * pDeviceProperties);
void btx_push_message_lttng_ust_ze_zeDeviceGetProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pDeviceProperties_val_length, ze_device_properties_t * pDeviceProperties_val);
void btx_push_message_lttng_ust_ze_zeDeviceGetComputeProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_handle_t hDevice, ze_device_compute_properties_t * pComputeProperties);
void btx_push_message_lttng_ust_ze_zeDeviceGetComputeProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pComputeProperties_val_length, ze_device_compute_properties_t * pComputeProperties_val);
void btx_push_message_lttng_ust_ze_zeDeviceGetModuleProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_handle_t hDevice, ze_device_module_properties_t * pModuleProperties);
void btx_push_message_lttng_ust_ze_zeDeviceGetModuleProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pModuleProperties_val_length, ze_device_module_properties_t * pModuleProperties_val);
void btx_push_message_lttng_ust_ze_zeDeviceGetCommandQueueGroupProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_handle_t hDevice, uint32_t * pCount, ze_command_queue_group_properties_t * pCommandQueueGroupProperties, uint32_t pCount_val);
void btx_push_message_lttng_ust_ze_zeDeviceGetCommandQueueGroupProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _pCommandQueueGroupProperties_vals_length, ze_command_queue_group_properties_t * pCommandQueueGroupProperties_vals);
void btx_push_message_lttng_ust_ze_zeDeviceGetMemoryProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_handle_t hDevice, uint32_t * pCount, ze_device_memory_properties_t * pMemProperties, uint32_t pCount_val);
void btx_push_message_lttng_ust_ze_zeDeviceGetMemoryProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _pMemProperties_vals_length, ze_device_memory_properties_t * pMemProperties_vals);
void btx_push_message_lttng_ust_ze_zeDeviceGetMemoryAccessProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_handle_t hDevice, ze_device_memory_access_properties_t * pMemAccessProperties);
void btx_push_message_lttng_ust_ze_zeDeviceGetMemoryAccessProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pMemAccessProperties_val_length, ze_device_memory_access_properties_t * pMemAccessProperties_val);
void btx_push_message_lttng_ust_ze_zeDeviceGetCacheProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_handle_t hDevice, uint32_t * pCount, ze_device_cache_properties_t * pCacheProperties, uint32_t pCount_val);
void btx_push_message_lttng_ust_ze_zeDeviceGetCacheProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _pCacheProperties_vals_length, ze_device_cache_properties_t * pCacheProperties_vals);
void btx_push_message_lttng_ust_ze_zeDeviceGetImageProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_handle_t hDevice, ze_device_image_properties_t * pImageProperties);
void btx_push_message_lttng_ust_ze_zeDeviceGetImageProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pImageProperties_val_length, ze_device_image_properties_t * pImageProperties_val);
void btx_push_message_lttng_ust_ze_zeDeviceGetExternalMemoryProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_handle_t hDevice, ze_device_external_memory_properties_t * pExternalMemoryProperties);
void btx_push_message_lttng_ust_ze_zeDeviceGetExternalMemoryProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pExternalMemoryProperties_val_length, ze_device_external_memory_properties_t * pExternalMemoryProperties_val);
void btx_push_message_lttng_ust_ze_zeDeviceGetP2PProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_handle_t hDevice, ze_device_handle_t hPeerDevice, ze_device_p2p_properties_t * pP2PProperties);
void btx_push_message_lttng_ust_ze_zeDeviceGetP2PProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pP2PProperties_val_length, ze_device_p2p_properties_t * pP2PProperties_val);
void btx_push_message_lttng_ust_ze_zeDeviceCanAccessPeer_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_handle_t hDevice, ze_device_handle_t hPeerDevice, ze_bool_t * value);
void btx_push_message_lttng_ust_ze_zeDeviceCanAccessPeer_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_bool_t value_val);
void btx_push_message_lttng_ust_ze_zeDeviceGetStatus_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_handle_t hDevice);
void btx_push_message_lttng_ust_ze_zeDeviceGetStatus_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeDeviceGetGlobalTimestamps_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_handle_t hDevice, uint64_t * hostTimestamp, uint64_t * deviceTimestamp);
void btx_push_message_lttng_ust_ze_zeDeviceGetGlobalTimestamps_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint64_t hostTimestamp_val, uint64_t deviceTimestamp_val);
void btx_push_message_lttng_ust_ze_zeContextCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_driver_handle_t hDriver, ze_context_desc_t * desc, ze_context_handle_t * phContext, size_t _desc_val_length, ze_context_desc_t * desc_val);
void btx_push_message_lttng_ust_ze_zeContextCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_context_handle_t phContext_val);
void btx_push_message_lttng_ust_ze_zeContextCreateEx_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_driver_handle_t hDriver, ze_context_desc_t * desc, uint32_t numDevices, ze_device_handle_t * phDevices, ze_context_handle_t * phContext, size_t _desc_val_length, ze_context_desc_t * desc_val, size_t _phDevices_vals_length, ze_device_handle_t * phDevices_vals);
void btx_push_message_lttng_ust_ze_zeContextCreateEx_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_context_handle_t phContext_val);
void btx_push_message_lttng_ust_ze_zeContextDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext);
void btx_push_message_lttng_ust_ze_zeContextDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeContextGetStatus_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext);
void btx_push_message_lttng_ust_ze_zeContextGetStatus_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeCommandQueueCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, ze_device_handle_t hDevice, ze_command_queue_desc_t * desc, ze_command_queue_handle_t * phCommandQueue, size_t _desc_val_length, ze_command_queue_desc_t * desc_val);
void btx_push_message_lttng_ust_ze_zeCommandQueueCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_command_queue_handle_t phCommandQueue_val);
void btx_push_message_lttng_ust_ze_zeCommandQueueDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_queue_handle_t hCommandQueue);
void btx_push_message_lttng_ust_ze_zeCommandQueueDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeCommandQueueExecuteCommandLists_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_queue_handle_t hCommandQueue, uint32_t numCommandLists, ze_command_list_handle_t * phCommandLists, ze_fence_handle_t hFence, size_t _phCommandLists_vals_length, ze_command_list_handle_t * phCommandLists_vals);
void btx_push_message_lttng_ust_ze_zeCommandQueueExecuteCommandLists_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeCommandQueueSynchronize_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_queue_handle_t hCommandQueue, uint64_t timeout);
void btx_push_message_lttng_ust_ze_zeCommandQueueSynchronize_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeCommandQueueGetOrdinal_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_queue_handle_t hCommandQueue, uint32_t * pOrdinal);
void btx_push_message_lttng_ust_ze_zeCommandQueueGetOrdinal_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pOrdinal_val);
void btx_push_message_lttng_ust_ze_zeCommandQueueGetIndex_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_queue_handle_t hCommandQueue, uint32_t * pIndex);
void btx_push_message_lttng_ust_ze_zeCommandQueueGetIndex_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pIndex_val);
void btx_push_message_lttng_ust_ze_zeCommandListCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, ze_device_handle_t hDevice, ze_command_list_desc_t * desc, ze_command_list_handle_t * phCommandList, size_t _desc_val_length, ze_command_list_desc_t * desc_val);
void btx_push_message_lttng_ust_ze_zeCommandListCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_command_list_handle_t phCommandList_val);
void btx_push_message_lttng_ust_ze_zeCommandListCreateImmediate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, ze_device_handle_t hDevice, ze_command_queue_desc_t * altdesc, ze_command_list_handle_t * phCommandList, size_t _altdesc_val_length, ze_command_queue_desc_t * altdesc_val);
void btx_push_message_lttng_ust_ze_zeCommandListCreateImmediate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_command_list_handle_t phCommandList_val);
void btx_push_message_lttng_ust_ze_zeCommandListDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList);
void btx_push_message_lttng_ust_ze_zeCommandListDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeCommandListClose_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList);
void btx_push_message_lttng_ust_ze_zeCommandListClose_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeCommandListReset_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList);
void btx_push_message_lttng_ust_ze_zeCommandListReset_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeCommandListAppendWriteGlobalTimestamp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, uint64_t * dstptr, ze_event_handle_t hSignalEvent, uint32_t numWaitEvents, ze_event_handle_t * phWaitEvents, size_t _phWaitEvents_vals_length, ze_event_handle_t * phWaitEvents_vals);
void btx_push_message_lttng_ust_ze_zeCommandListAppendWriteGlobalTimestamp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeCommandListHostSynchronize_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, uint64_t timeout);
void btx_push_message_lttng_ust_ze_zeCommandListHostSynchronize_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeCommandListGetDeviceHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, ze_device_handle_t * phDevice);
void btx_push_message_lttng_ust_ze_zeCommandListGetDeviceHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_device_handle_t phDevice_val);
void btx_push_message_lttng_ust_ze_zeCommandListGetContextHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, ze_context_handle_t * phContext);
void btx_push_message_lttng_ust_ze_zeCommandListGetContextHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_context_handle_t phContext_val);
void btx_push_message_lttng_ust_ze_zeCommandListGetOrdinal_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, uint32_t * pOrdinal);
void btx_push_message_lttng_ust_ze_zeCommandListGetOrdinal_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pOrdinal_val);
void btx_push_message_lttng_ust_ze_zeCommandListImmediateGetIndex_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandListImmediate, uint32_t * pIndex);
void btx_push_message_lttng_ust_ze_zeCommandListImmediateGetIndex_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pIndex_val);
void btx_push_message_lttng_ust_ze_zeCommandListIsImmediate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, ze_bool_t * pIsImmediate);
void btx_push_message_lttng_ust_ze_zeCommandListIsImmediate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_bool_t pIsImmediate_val);
void btx_push_message_lttng_ust_ze_zeCommandListAppendBarrier_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, ze_event_handle_t hSignalEvent, uint32_t numWaitEvents, ze_event_handle_t * phWaitEvents, size_t _phWaitEvents_vals_length, ze_event_handle_t * phWaitEvents_vals);
void btx_push_message_lttng_ust_ze_zeCommandListAppendBarrier_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeCommandListAppendMemoryRangesBarrier_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, uint32_t numRanges, size_t * pRangeSizes, void ** pRanges, ze_event_handle_t hSignalEvent, uint32_t numWaitEvents, ze_event_handle_t * phWaitEvents, size_t _pRangeSizes_vals_length, size_t * pRangeSizes_vals, size_t _pRanges_vals_length, void * * pRanges_vals, size_t _phWaitEvents_vals_length, ze_event_handle_t * phWaitEvents_vals);
void btx_push_message_lttng_ust_ze_zeCommandListAppendMemoryRangesBarrier_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeContextSystemBarrier_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, ze_device_handle_t hDevice);
void btx_push_message_lttng_ust_ze_zeContextSystemBarrier_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeCommandListAppendMemoryCopy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, void * dstptr, void * srcptr, size_t size, ze_event_handle_t hSignalEvent, uint32_t numWaitEvents, ze_event_handle_t * phWaitEvents, size_t _phWaitEvents_vals_length, ze_event_handle_t * phWaitEvents_vals);
void btx_push_message_lttng_ust_ze_zeCommandListAppendMemoryCopy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeCommandListAppendMemoryFill_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, void * ptr, void * pattern, size_t pattern_size, size_t size, ze_event_handle_t hSignalEvent, uint32_t numWaitEvents, ze_event_handle_t * phWaitEvents, size_t _pattern_vals_length, void * pattern_vals, size_t _phWaitEvents_vals_length, ze_event_handle_t * phWaitEvents_vals);
void btx_push_message_lttng_ust_ze_zeCommandListAppendMemoryFill_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeCommandListAppendMemoryCopyRegion_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, void * dstptr, ze_copy_region_t * dstRegion, uint32_t dstPitch, uint32_t dstSlicePitch, void * srcptr, ze_copy_region_t * srcRegion, uint32_t srcPitch, uint32_t srcSlicePitch, ze_event_handle_t hSignalEvent, uint32_t numWaitEvents, ze_event_handle_t * phWaitEvents, size_t _dstRegion_val_length, ze_copy_region_t * dstRegion_val, size_t _srcRegion_val_length, ze_copy_region_t * srcRegion_val, size_t _phWaitEvents_vals_length, ze_event_handle_t * phWaitEvents_vals);
void btx_push_message_lttng_ust_ze_zeCommandListAppendMemoryCopyRegion_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeCommandListAppendMemoryCopyFromContext_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, void * dstptr, ze_context_handle_t hContextSrc, void * srcptr, size_t size, ze_event_handle_t hSignalEvent, uint32_t numWaitEvents, ze_event_handle_t * phWaitEvents, size_t _phWaitEvents_vals_length, ze_event_handle_t * phWaitEvents_vals);
void btx_push_message_lttng_ust_ze_zeCommandListAppendMemoryCopyFromContext_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeCommandListAppendImageCopy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, ze_image_handle_t hDstImage, ze_image_handle_t hSrcImage, ze_event_handle_t hSignalEvent, uint32_t numWaitEvents, ze_event_handle_t * phWaitEvents, size_t _phWaitEvents_vals_length, ze_event_handle_t * phWaitEvents_vals);
void btx_push_message_lttng_ust_ze_zeCommandListAppendImageCopy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeCommandListAppendImageCopyRegion_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, ze_image_handle_t hDstImage, ze_image_handle_t hSrcImage, ze_image_region_t * pDstRegion, ze_image_region_t * pSrcRegion, ze_event_handle_t hSignalEvent, uint32_t numWaitEvents, ze_event_handle_t * phWaitEvents, size_t _pDstRegion_val_length, ze_image_region_t * pDstRegion_val, size_t _pSrcRegion_val_length, ze_image_region_t * pSrcRegion_val, size_t _phWaitEvents_vals_length, ze_event_handle_t * phWaitEvents_vals);
void btx_push_message_lttng_ust_ze_zeCommandListAppendImageCopyRegion_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeCommandListAppendImageCopyToMemory_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, void * dstptr, ze_image_handle_t hSrcImage, ze_image_region_t * pSrcRegion, ze_event_handle_t hSignalEvent, uint32_t numWaitEvents, ze_event_handle_t * phWaitEvents, size_t _pSrcRegion_val_length, ze_image_region_t * pSrcRegion_val, size_t _phWaitEvents_vals_length, ze_event_handle_t * phWaitEvents_vals);
void btx_push_message_lttng_ust_ze_zeCommandListAppendImageCopyToMemory_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeCommandListAppendImageCopyFromMemory_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, ze_image_handle_t hDstImage, void * srcptr, ze_image_region_t * pDstRegion, ze_event_handle_t hSignalEvent, uint32_t numWaitEvents, ze_event_handle_t * phWaitEvents, size_t _pDstRegion_val_length, ze_image_region_t * pDstRegion_val, size_t _phWaitEvents_vals_length, ze_event_handle_t * phWaitEvents_vals);
void btx_push_message_lttng_ust_ze_zeCommandListAppendImageCopyFromMemory_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeCommandListAppendMemoryPrefetch_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, void * ptr, size_t size);
void btx_push_message_lttng_ust_ze_zeCommandListAppendMemoryPrefetch_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeCommandListAppendMemAdvise_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, ze_device_handle_t hDevice, void * ptr, size_t size, ze_memory_advice_t advice);
void btx_push_message_lttng_ust_ze_zeCommandListAppendMemAdvise_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeEventPoolCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, ze_event_pool_desc_t * desc, uint32_t numDevices, ze_device_handle_t * phDevices, ze_event_pool_handle_t * phEventPool, size_t _desc_val_length, ze_event_pool_desc_t * desc_val, size_t _phDevices_vals_length, ze_device_handle_t * phDevices_vals);
void btx_push_message_lttng_ust_ze_zeEventPoolCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_event_pool_handle_t phEventPool_val);
void btx_push_message_lttng_ust_ze_zeEventPoolDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_event_pool_handle_t hEventPool);
void btx_push_message_lttng_ust_ze_zeEventPoolDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeEventCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_event_pool_handle_t hEventPool, ze_event_desc_t * desc, ze_event_handle_t * phEvent, size_t _desc_val_length, ze_event_desc_t * desc_val);
void btx_push_message_lttng_ust_ze_zeEventCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_event_handle_t phEvent_val);
void btx_push_message_lttng_ust_ze_zeEventDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_event_handle_t hEvent);
void btx_push_message_lttng_ust_ze_zeEventDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeEventPoolGetIpcHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_event_pool_handle_t hEventPool, ze_ipc_event_pool_handle_t * phIpc);
void btx_push_message_lttng_ust_ze_zeEventPoolGetIpcHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _phIpc_val_length, ze_ipc_event_pool_handle_t * phIpc_val);
void btx_push_message_lttng_ust_ze_zeEventPoolPutIpcHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, ze_ipc_event_pool_handle_t hIpc);
void btx_push_message_lttng_ust_ze_zeEventPoolPutIpcHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeEventPoolOpenIpcHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, ze_ipc_event_pool_handle_t hIpc, ze_event_pool_handle_t * phEventPool);
void btx_push_message_lttng_ust_ze_zeEventPoolOpenIpcHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_event_pool_handle_t phEventPool_val);
void btx_push_message_lttng_ust_ze_zeEventPoolCloseIpcHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_event_pool_handle_t hEventPool);
void btx_push_message_lttng_ust_ze_zeEventPoolCloseIpcHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeCommandListAppendSignalEvent_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, ze_event_handle_t hEvent);
void btx_push_message_lttng_ust_ze_zeCommandListAppendSignalEvent_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeCommandListAppendWaitOnEvents_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, uint32_t numEvents, ze_event_handle_t * phEvents, size_t _phEvents_vals_length, ze_event_handle_t * phEvents_vals);
void btx_push_message_lttng_ust_ze_zeCommandListAppendWaitOnEvents_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeEventHostSignal_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_event_handle_t hEvent);
void btx_push_message_lttng_ust_ze_zeEventHostSignal_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeEventHostSynchronize_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_event_handle_t hEvent, uint64_t timeout);
void btx_push_message_lttng_ust_ze_zeEventHostSynchronize_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeEventQueryStatus_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_event_handle_t hEvent);
void btx_push_message_lttng_ust_ze_zeEventQueryStatus_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeCommandListAppendEventReset_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, ze_event_handle_t hEvent);
void btx_push_message_lttng_ust_ze_zeCommandListAppendEventReset_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeEventHostReset_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_event_handle_t hEvent);
void btx_push_message_lttng_ust_ze_zeEventHostReset_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeEventQueryKernelTimestamp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_event_handle_t hEvent, ze_kernel_timestamp_result_t * dstptr);
void btx_push_message_lttng_ust_ze_zeEventQueryKernelTimestamp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _dstptr_val_length, ze_kernel_timestamp_result_t * dstptr_val);
void btx_push_message_lttng_ust_ze_zeCommandListAppendQueryKernelTimestamps_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, uint32_t numEvents, ze_event_handle_t * phEvents, void * dstptr, size_t * pOffsets, ze_event_handle_t hSignalEvent, uint32_t numWaitEvents, ze_event_handle_t * phWaitEvents, size_t _phEvents_vals_length, ze_event_handle_t * phEvents_vals, size_t _pOffsets_vals_length, size_t * pOffsets_vals, size_t _phWaitEvents_vals_length, ze_event_handle_t * phWaitEvents_vals);
void btx_push_message_lttng_ust_ze_zeCommandListAppendQueryKernelTimestamps_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeEventGetEventPool_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_event_handle_t hEvent, ze_event_pool_handle_t * phEventPool);
void btx_push_message_lttng_ust_ze_zeEventGetEventPool_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_event_pool_handle_t phEventPool_val);
void btx_push_message_lttng_ust_ze_zeEventGetSignalScope_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_event_handle_t hEvent, ze_event_scope_flags_t * pSignalScope);
void btx_push_message_lttng_ust_ze_zeEventGetSignalScope_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_event_scope_flags_t pSignalScope_val);
void btx_push_message_lttng_ust_ze_zeEventGetWaitScope_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_event_handle_t hEvent, ze_event_scope_flags_t * pWaitScope);
void btx_push_message_lttng_ust_ze_zeEventGetWaitScope_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_event_scope_flags_t pWaitScope_val);
void btx_push_message_lttng_ust_ze_zeEventPoolGetContextHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_event_pool_handle_t hEventPool, ze_context_handle_t * phContext);
void btx_push_message_lttng_ust_ze_zeEventPoolGetContextHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_context_handle_t phContext_val);
void btx_push_message_lttng_ust_ze_zeEventPoolGetFlags_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_event_pool_handle_t hEventPool, ze_event_pool_flags_t * pFlags);
void btx_push_message_lttng_ust_ze_zeEventPoolGetFlags_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_event_pool_flags_t pFlags_val);
void btx_push_message_lttng_ust_ze_zeFenceCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_queue_handle_t hCommandQueue, ze_fence_desc_t * desc, ze_fence_handle_t * phFence, size_t _desc_val_length, ze_fence_desc_t * desc_val);
void btx_push_message_lttng_ust_ze_zeFenceCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_fence_handle_t phFence_val);
void btx_push_message_lttng_ust_ze_zeFenceDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_fence_handle_t hFence);
void btx_push_message_lttng_ust_ze_zeFenceDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeFenceHostSynchronize_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_fence_handle_t hFence, uint64_t timeout);
void btx_push_message_lttng_ust_ze_zeFenceHostSynchronize_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeFenceQueryStatus_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_fence_handle_t hFence);
void btx_push_message_lttng_ust_ze_zeFenceQueryStatus_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeFenceReset_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_fence_handle_t hFence);
void btx_push_message_lttng_ust_ze_zeFenceReset_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeImageGetProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_handle_t hDevice, ze_image_desc_t * desc, ze_image_properties_t * pImageProperties, size_t _desc_val_length, ze_image_desc_t * desc_val);
void btx_push_message_lttng_ust_ze_zeImageGetProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pImageProperties_val_length, ze_image_properties_t * pImageProperties_val);
void btx_push_message_lttng_ust_ze_zeImageCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, ze_device_handle_t hDevice, ze_image_desc_t * desc, ze_image_handle_t * phImage, size_t _desc_val_length, ze_image_desc_t * desc_val);
void btx_push_message_lttng_ust_ze_zeImageCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_image_handle_t phImage_val);
void btx_push_message_lttng_ust_ze_zeImageDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_image_handle_t hImage);
void btx_push_message_lttng_ust_ze_zeImageDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeMemAllocShared_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, ze_device_mem_alloc_desc_t * device_desc, ze_host_mem_alloc_desc_t * host_desc, size_t size, size_t alignment, ze_device_handle_t hDevice, void ** pptr, size_t _device_desc_val_length, ze_device_mem_alloc_desc_t * device_desc_val, size_t _host_desc_val_length, ze_host_mem_alloc_desc_t * host_desc_val);
void btx_push_message_lttng_ust_ze_zeMemAllocShared_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, void * pptr_val);
void btx_push_message_lttng_ust_ze_zeMemAllocDevice_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, ze_device_mem_alloc_desc_t * device_desc, size_t size, size_t alignment, ze_device_handle_t hDevice, void ** pptr, size_t _device_desc_val_length, ze_device_mem_alloc_desc_t * device_desc_val);
void btx_push_message_lttng_ust_ze_zeMemAllocDevice_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, void * pptr_val);
void btx_push_message_lttng_ust_ze_zeMemAllocHost_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, ze_host_mem_alloc_desc_t * host_desc, size_t size, size_t alignment, void ** pptr, size_t _host_desc_val_length, ze_host_mem_alloc_desc_t * host_desc_val);
void btx_push_message_lttng_ust_ze_zeMemAllocHost_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, void * pptr_val);
void btx_push_message_lttng_ust_ze_zeMemFree_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, void * ptr);
void btx_push_message_lttng_ust_ze_zeMemFree_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeMemGetAllocProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, void * ptr, ze_memory_allocation_properties_t * pMemAllocProperties, ze_device_handle_t * phDevice);
void btx_push_message_lttng_ust_ze_zeMemGetAllocProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pMemAllocProperties_val_length, ze_memory_allocation_properties_t * pMemAllocProperties_val, ze_device_handle_t phDevice_val);
void btx_push_message_lttng_ust_ze_zeMemGetAddressRange_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, void * ptr, void ** pBase, size_t * pSize);
void btx_push_message_lttng_ust_ze_zeMemGetAddressRange_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, void * pBase_val, size_t pSize_val);
void btx_push_message_lttng_ust_ze_zeMemGetIpcHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, void * ptr, ze_ipc_mem_handle_t * pIpcHandle);
void btx_push_message_lttng_ust_ze_zeMemGetIpcHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pIpcHandle_val_length, ze_ipc_mem_handle_t * pIpcHandle_val);
void btx_push_message_lttng_ust_ze_zeMemGetIpcHandleFromFileDescriptorExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, uint64_t handle, ze_ipc_mem_handle_t * pIpcHandle);
void btx_push_message_lttng_ust_ze_zeMemGetIpcHandleFromFileDescriptorExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pIpcHandle_val_length, ze_ipc_mem_handle_t * pIpcHandle_val);
void btx_push_message_lttng_ust_ze_zeMemGetFileDescriptorFromIpcHandleExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, ze_ipc_mem_handle_t ipcHandle, uint64_t * pHandle);
void btx_push_message_lttng_ust_ze_zeMemGetFileDescriptorFromIpcHandleExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint64_t pHandle_val);
void btx_push_message_lttng_ust_ze_zeMemPutIpcHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, ze_ipc_mem_handle_t handle);
void btx_push_message_lttng_ust_ze_zeMemPutIpcHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeMemOpenIpcHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, ze_device_handle_t hDevice, ze_ipc_mem_handle_t handle, ze_ipc_memory_flags_t flags, void ** pptr);
void btx_push_message_lttng_ust_ze_zeMemOpenIpcHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, void * pptr_val);
void btx_push_message_lttng_ust_ze_zeMemCloseIpcHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, void * ptr);
void btx_push_message_lttng_ust_ze_zeMemCloseIpcHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeMemSetAtomicAccessAttributeExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, ze_device_handle_t hDevice, void * ptr, size_t size, ze_memory_atomic_attr_exp_flags_t attr);
void btx_push_message_lttng_ust_ze_zeMemSetAtomicAccessAttributeExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeMemGetAtomicAccessAttributeExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, ze_device_handle_t hDevice, void * ptr, size_t size, ze_memory_atomic_attr_exp_flags_t * pAttr);
void btx_push_message_lttng_ust_ze_zeMemGetAtomicAccessAttributeExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_memory_atomic_attr_exp_flags_t pAttr_val);
void btx_push_message_lttng_ust_ze_zeModuleCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, ze_device_handle_t hDevice, ze_module_desc_t * desc, ze_module_handle_t * phModule, ze_module_build_log_handle_t * phBuildLog, size_t _desc_val_length, ze_module_desc_t * desc_val, char * desc__pBuildFlags_val, size_t _desc__pConstants_val_length, ze_module_constants_t * desc__pConstants_val, size_t _desc__pConstants__pConstantIds_vals_length, uint32_t * desc__pConstants__pConstantIds_vals, size_t _desc__pConstants__pConstantValues_vals_length, void * * desc__pConstants__pConstantValues_vals);
void btx_push_message_lttng_ust_ze_zeModuleCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_module_handle_t phModule_val, ze_module_build_log_handle_t phBuildLog_val);
void btx_push_message_lttng_ust_ze_zeModuleDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_module_handle_t hModule);
void btx_push_message_lttng_ust_ze_zeModuleDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeModuleDynamicLink_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, uint32_t numModules, ze_module_handle_t * phModules, ze_module_build_log_handle_t * phLinkLog, size_t _phModules_vals_length, ze_module_handle_t * phModules_vals);
void btx_push_message_lttng_ust_ze_zeModuleDynamicLink_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_module_build_log_handle_t phLinkLog_val);
void btx_push_message_lttng_ust_ze_zeModuleBuildLogDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_module_build_log_handle_t hModuleBuildLog);
void btx_push_message_lttng_ust_ze_zeModuleBuildLogDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeModuleBuildLogGetString_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_module_build_log_handle_t hModuleBuildLog, size_t * pSize, char * pBuildLog, size_t pSize_val);
void btx_push_message_lttng_ust_ze_zeModuleBuildLogGetString_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t pSize_val, size_t _pBuildLog_vals_length, char * pBuildLog_vals);
void btx_push_message_lttng_ust_ze_zeModuleGetNativeBinary_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_module_handle_t hModule, size_t * pSize, uint8_t * pModuleNativeBinary, size_t pSize_val);
void btx_push_message_lttng_ust_ze_zeModuleGetNativeBinary_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t pSize_val);
void btx_push_message_lttng_ust_ze_zeModuleGetGlobalPointer_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_module_handle_t hModule, char * pGlobalName, size_t * pSize, void ** pptr, char * pGlobalName_val);
void btx_push_message_lttng_ust_ze_zeModuleGetGlobalPointer_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t pSize_val, void * pptr_val);
void btx_push_message_lttng_ust_ze_zeModuleGetKernelNames_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_module_handle_t hModule, uint32_t * pCount, char ** pNames, uint32_t pCount_val);
void btx_push_message_lttng_ust_ze_zeModuleGetKernelNames_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _pNames_vals_length, char * * pNames_vals);
void btx_push_message_lttng_ust_ze_zeModuleGetProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_module_handle_t hModule, ze_module_properties_t * pModuleProperties);
void btx_push_message_lttng_ust_ze_zeModuleGetProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pModuleProperties_val_length, ze_module_properties_t * pModuleProperties_val);
void btx_push_message_lttng_ust_ze_zeKernelCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_module_handle_t hModule, ze_kernel_desc_t * desc, ze_kernel_handle_t * phKernel, size_t _desc_val_length, ze_kernel_desc_t * desc_val, char * desc__pKernelName_val);
void btx_push_message_lttng_ust_ze_zeKernelCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_kernel_handle_t phKernel_val);
void btx_push_message_lttng_ust_ze_zeKernelDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_kernel_handle_t hKernel);
void btx_push_message_lttng_ust_ze_zeKernelDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeModuleGetFunctionPointer_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_module_handle_t hModule, char * pFunctionName, void ** pfnFunction, char * pFunctionName_val);
void btx_push_message_lttng_ust_ze_zeModuleGetFunctionPointer_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, void * pfnFunction_val);
void btx_push_message_lttng_ust_ze_zeKernelSetGroupSize_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_kernel_handle_t hKernel, uint32_t groupSizeX, uint32_t groupSizeY, uint32_t groupSizeZ);
void btx_push_message_lttng_ust_ze_zeKernelSetGroupSize_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeKernelSuggestGroupSize_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_kernel_handle_t hKernel, uint32_t globalSizeX, uint32_t globalSizeY, uint32_t globalSizeZ, uint32_t * groupSizeX, uint32_t * groupSizeY, uint32_t * groupSizeZ);
void btx_push_message_lttng_ust_ze_zeKernelSuggestGroupSize_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t groupSizeX_val, uint32_t groupSizeY_val, uint32_t groupSizeZ_val);
void btx_push_message_lttng_ust_ze_zeKernelSuggestMaxCooperativeGroupCount_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_kernel_handle_t hKernel, uint32_t * totalGroupCount);
void btx_push_message_lttng_ust_ze_zeKernelSuggestMaxCooperativeGroupCount_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t totalGroupCount_val);
void btx_push_message_lttng_ust_ze_zeKernelSetArgumentValue_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_kernel_handle_t hKernel, uint32_t argIndex, size_t argSize, void * pArgValue, size_t _pArgValue_vals_length, void * pArgValue_vals);
void btx_push_message_lttng_ust_ze_zeKernelSetArgumentValue_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeKernelSetIndirectAccess_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_kernel_handle_t hKernel, ze_kernel_indirect_access_flags_t flags);
void btx_push_message_lttng_ust_ze_zeKernelSetIndirectAccess_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeKernelGetIndirectAccess_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_kernel_handle_t hKernel, ze_kernel_indirect_access_flags_t * pFlags);
void btx_push_message_lttng_ust_ze_zeKernelGetIndirectAccess_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_kernel_indirect_access_flags_t pFlags_val);
void btx_push_message_lttng_ust_ze_zeKernelGetSourceAttributes_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_kernel_handle_t hKernel, uint32_t * pSize, char ** pString, uint32_t pSize_val, char * pString_val);
void btx_push_message_lttng_ust_ze_zeKernelGetSourceAttributes_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pSize_val, char * pString_val);
void btx_push_message_lttng_ust_ze_zeKernelSetCacheConfig_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_kernel_handle_t hKernel, ze_cache_config_flags_t flags);
void btx_push_message_lttng_ust_ze_zeKernelSetCacheConfig_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeKernelGetProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_kernel_handle_t hKernel, ze_kernel_properties_t * pKernelProperties);
void btx_push_message_lttng_ust_ze_zeKernelGetProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pKernelProperties_val_length, ze_kernel_properties_t * pKernelProperties_val);
void btx_push_message_lttng_ust_ze_zeKernelGetName_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_kernel_handle_t hKernel, size_t * pSize, char * pName, size_t pSize_val);
void btx_push_message_lttng_ust_ze_zeKernelGetName_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t pSize_val, size_t _pName_val_length, char * pName_val);
void btx_push_message_lttng_ust_ze_zeCommandListAppendLaunchKernel_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, ze_kernel_handle_t hKernel, ze_group_count_t * pLaunchFuncArgs, ze_event_handle_t hSignalEvent, uint32_t numWaitEvents, ze_event_handle_t * phWaitEvents, size_t _pLaunchFuncArgs_val_length, ze_group_count_t * pLaunchFuncArgs_val, size_t _phWaitEvents_vals_length, ze_event_handle_t * phWaitEvents_vals);
void btx_push_message_lttng_ust_ze_zeCommandListAppendLaunchKernel_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeCommandListAppendLaunchCooperativeKernel_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, ze_kernel_handle_t hKernel, ze_group_count_t * pLaunchFuncArgs, ze_event_handle_t hSignalEvent, uint32_t numWaitEvents, ze_event_handle_t * phWaitEvents, size_t _pLaunchFuncArgs_val_length, ze_group_count_t * pLaunchFuncArgs_val, size_t _phWaitEvents_vals_length, ze_event_handle_t * phWaitEvents_vals);
void btx_push_message_lttng_ust_ze_zeCommandListAppendLaunchCooperativeKernel_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeCommandListAppendLaunchKernelIndirect_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, ze_kernel_handle_t hKernel, ze_group_count_t * pLaunchArgumentsBuffer, ze_event_handle_t hSignalEvent, uint32_t numWaitEvents, ze_event_handle_t * phWaitEvents, size_t _phWaitEvents_vals_length, ze_event_handle_t * phWaitEvents_vals);
void btx_push_message_lttng_ust_ze_zeCommandListAppendLaunchKernelIndirect_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeCommandListAppendLaunchMultipleKernelsIndirect_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, uint32_t numKernels, ze_kernel_handle_t * phKernels, uint32_t * pCountBuffer, ze_group_count_t * pLaunchArgumentsBuffer, ze_event_handle_t hSignalEvent, uint32_t numWaitEvents, ze_event_handle_t * phWaitEvents, size_t _phKernels_vals_length, ze_kernel_handle_t * phKernels_vals, size_t _phWaitEvents_vals_length, ze_event_handle_t * phWaitEvents_vals);
void btx_push_message_lttng_ust_ze_zeCommandListAppendLaunchMultipleKernelsIndirect_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeContextMakeMemoryResident_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, ze_device_handle_t hDevice, void * ptr, size_t size);
void btx_push_message_lttng_ust_ze_zeContextMakeMemoryResident_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeContextEvictMemory_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, ze_device_handle_t hDevice, void * ptr, size_t size);
void btx_push_message_lttng_ust_ze_zeContextEvictMemory_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeContextMakeImageResident_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, ze_device_handle_t hDevice, ze_image_handle_t hImage);
void btx_push_message_lttng_ust_ze_zeContextMakeImageResident_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeContextEvictImage_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, ze_device_handle_t hDevice, ze_image_handle_t hImage);
void btx_push_message_lttng_ust_ze_zeContextEvictImage_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeSamplerCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, ze_device_handle_t hDevice, ze_sampler_desc_t * desc, ze_sampler_handle_t * phSampler, size_t _desc_val_length, ze_sampler_desc_t * desc_val);
void btx_push_message_lttng_ust_ze_zeSamplerCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_sampler_handle_t phSampler_val);
void btx_push_message_lttng_ust_ze_zeSamplerDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_sampler_handle_t hSampler);
void btx_push_message_lttng_ust_ze_zeSamplerDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeVirtualMemReserve_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, void * pStart, size_t size, void ** pptr);
void btx_push_message_lttng_ust_ze_zeVirtualMemReserve_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, void * pptr_val);
void btx_push_message_lttng_ust_ze_zeVirtualMemFree_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, void * ptr, size_t size);
void btx_push_message_lttng_ust_ze_zeVirtualMemFree_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeVirtualMemQueryPageSize_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, ze_device_handle_t hDevice, size_t size, size_t * pagesize);
void btx_push_message_lttng_ust_ze_zeVirtualMemQueryPageSize_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t pagesize_val);
void btx_push_message_lttng_ust_ze_zePhysicalMemCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, ze_device_handle_t hDevice, ze_physical_mem_desc_t * desc, ze_physical_mem_handle_t * phPhysicalMemory, size_t _desc_val_length, ze_physical_mem_desc_t * desc_val);
void btx_push_message_lttng_ust_ze_zePhysicalMemCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_physical_mem_handle_t phPhysicalMemory_val);
void btx_push_message_lttng_ust_ze_zePhysicalMemDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, ze_physical_mem_handle_t hPhysicalMemory);
void btx_push_message_lttng_ust_ze_zePhysicalMemDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeVirtualMemMap_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, void * ptr, size_t size, ze_physical_mem_handle_t hPhysicalMemory, size_t offset, ze_memory_access_attribute_t access);
void btx_push_message_lttng_ust_ze_zeVirtualMemMap_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeVirtualMemUnmap_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, void * ptr, size_t size);
void btx_push_message_lttng_ust_ze_zeVirtualMemUnmap_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeVirtualMemSetAccessAttribute_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, void * ptr, size_t size, ze_memory_access_attribute_t access);
void btx_push_message_lttng_ust_ze_zeVirtualMemSetAccessAttribute_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeVirtualMemGetAccessAttribute_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, void * ptr, size_t size, ze_memory_access_attribute_t * access, size_t * outSize);
void btx_push_message_lttng_ust_ze_zeVirtualMemGetAccessAttribute_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_memory_access_attribute_t access_val, size_t outSize_val);
void btx_push_message_lttng_ust_ze_zeKernelSetGlobalOffsetExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_kernel_handle_t hKernel, uint32_t offsetX, uint32_t offsetY, uint32_t offsetZ);
void btx_push_message_lttng_ust_ze_zeKernelSetGlobalOffsetExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeKernelGetBinaryExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_kernel_handle_t hKernel, size_t * pSize, uint8_t * pKernelBinary, size_t pSize_val);
void btx_push_message_lttng_ust_ze_zeKernelGetBinaryExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t pSize_val, size_t _pKernelBinary_vals_length, uint8_t * pKernelBinary_vals);
void btx_push_message_lttng_ust_ze_zeDeviceImportExternalSemaphoreExt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_handle_t hDevice, ze_external_semaphore_ext_desc_t * desc, ze_external_semaphore_ext_handle_t * phSemaphore, size_t _desc_val_length, ze_external_semaphore_ext_desc_t * desc_val);
void btx_push_message_lttng_ust_ze_zeDeviceImportExternalSemaphoreExt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_external_semaphore_ext_handle_t phSemaphore_val);
void btx_push_message_lttng_ust_ze_zeDeviceReleaseExternalSemaphoreExt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_external_semaphore_ext_handle_t hSemaphore);
void btx_push_message_lttng_ust_ze_zeDeviceReleaseExternalSemaphoreExt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeCommandListAppendSignalExternalSemaphoreExt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, uint32_t numSemaphores, ze_external_semaphore_ext_handle_t * phSemaphores, ze_external_semaphore_signal_params_ext_t * signalParams, ze_event_handle_t hSignalEvent, uint32_t numWaitEvents, ze_event_handle_t * phWaitEvents, size_t _phSemaphores_vals_length, ze_external_semaphore_ext_handle_t * phSemaphores_vals, size_t _signalParams_vals_length, ze_external_semaphore_signal_params_ext_t * signalParams_vals, size_t _phWaitEvents_vals_length, ze_event_handle_t * phWaitEvents_vals);
void btx_push_message_lttng_ust_ze_zeCommandListAppendSignalExternalSemaphoreExt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeCommandListAppendWaitExternalSemaphoreExt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, uint32_t numSemaphores, ze_external_semaphore_ext_handle_t * phSemaphores, ze_external_semaphore_wait_params_ext_t * waitParams, ze_event_handle_t hSignalEvent, uint32_t numWaitEvents, ze_event_handle_t * phWaitEvents, size_t _phSemaphores_vals_length, ze_external_semaphore_ext_handle_t * phSemaphores_vals, size_t _waitParams_vals_length, ze_external_semaphore_wait_params_ext_t * waitParams_vals, size_t _phWaitEvents_vals_length, ze_event_handle_t * phWaitEvents_vals);
void btx_push_message_lttng_ust_ze_zeCommandListAppendWaitExternalSemaphoreExt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeRTASBuilderCreateExt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_driver_handle_t hDriver, ze_rtas_builder_ext_desc_t * pDescriptor, ze_rtas_builder_ext_handle_t * phBuilder);
void btx_push_message_lttng_ust_ze_zeRTASBuilderCreateExt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeRTASBuilderGetBuildPropertiesExt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_rtas_builder_ext_handle_t hBuilder, ze_rtas_builder_build_op_ext_desc_t * pBuildOpDescriptor, ze_rtas_builder_ext_properties_t * pProperties);
void btx_push_message_lttng_ust_ze_zeRTASBuilderGetBuildPropertiesExt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeDriverRTASFormatCompatibilityCheckExt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_driver_handle_t hDriver, ze_rtas_format_ext_t rtasFormatA, ze_rtas_format_ext_t rtasFormatB);
void btx_push_message_lttng_ust_ze_zeDriverRTASFormatCompatibilityCheckExt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeRTASBuilderBuildExt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_rtas_builder_ext_handle_t hBuilder, ze_rtas_builder_build_op_ext_desc_t * pBuildOpDescriptor, void * pScratchBuffer, size_t scratchBufferSizeBytes, void * pRtasBuffer, size_t rtasBufferSizeBytes, ze_rtas_parallel_operation_ext_handle_t hParallelOperation, void * pBuildUserPtr, ze_rtas_aabb_ext_t * pBounds, size_t * pRtasBufferSizeBytes);
void btx_push_message_lttng_ust_ze_zeRTASBuilderBuildExt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeRTASBuilderCommandListAppendCopyExt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, void * dstptr, void * srcptr, size_t size, ze_event_handle_t hSignalEvent, uint32_t numWaitEvents, ze_event_handle_t * phWaitEvents);
void btx_push_message_lttng_ust_ze_zeRTASBuilderCommandListAppendCopyExt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeRTASBuilderDestroyExt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_rtas_builder_ext_handle_t hBuilder);
void btx_push_message_lttng_ust_ze_zeRTASBuilderDestroyExt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeRTASParallelOperationCreateExt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_driver_handle_t hDriver, ze_rtas_parallel_operation_ext_handle_t * phParallelOperation);
void btx_push_message_lttng_ust_ze_zeRTASParallelOperationCreateExt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeRTASParallelOperationGetPropertiesExt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_rtas_parallel_operation_ext_handle_t hParallelOperation, ze_rtas_parallel_operation_ext_properties_t * pProperties);
void btx_push_message_lttng_ust_ze_zeRTASParallelOperationGetPropertiesExt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeRTASParallelOperationJoinExt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_rtas_parallel_operation_ext_handle_t hParallelOperation);
void btx_push_message_lttng_ust_ze_zeRTASParallelOperationJoinExt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeRTASParallelOperationDestroyExt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_rtas_parallel_operation_ext_handle_t hParallelOperation);
void btx_push_message_lttng_ust_ze_zeRTASParallelOperationDestroyExt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeDeviceGetVectorWidthPropertiesExt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_handle_t hDevice, uint32_t * pCount, ze_device_vector_width_properties_ext_t * pVectorWidthProperties, uint32_t pCount_val);
void btx_push_message_lttng_ust_ze_zeDeviceGetVectorWidthPropertiesExt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _pVectorWidthProperties_vals_length, ze_device_vector_width_properties_ext_t * pVectorWidthProperties_vals);
void btx_push_message_lttng_ust_ze_zeDeviceReserveCacheExt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_handle_t hDevice, size_t cacheLevel, size_t cacheReservationSize);
void btx_push_message_lttng_ust_ze_zeDeviceReserveCacheExt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeDeviceSetCacheAdviceExt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_handle_t hDevice, void * ptr, size_t regionSize, ze_cache_ext_region_t cacheRegion);
void btx_push_message_lttng_ust_ze_zeDeviceSetCacheAdviceExt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeEventQueryTimestampsExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_event_handle_t hEvent, ze_device_handle_t hDevice, uint32_t * pCount, ze_kernel_timestamp_result_t * pTimestamps, uint32_t pCount_val);
void btx_push_message_lttng_ust_ze_zeEventQueryTimestampsExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _pTimestamps_vals_length, ze_kernel_timestamp_result_t * pTimestamps_vals);
void btx_push_message_lttng_ust_ze_zeImageGetMemoryPropertiesExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_image_handle_t hImage, ze_image_memory_properties_exp_t * pMemoryProperties);
void btx_push_message_lttng_ust_ze_zeImageGetMemoryPropertiesExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pMemoryProperties_val_length, ze_image_memory_properties_exp_t * pMemoryProperties_val);
void btx_push_message_lttng_ust_ze_zeImageViewCreateExt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, ze_device_handle_t hDevice, ze_image_desc_t * desc, ze_image_handle_t hImage, ze_image_handle_t * phImageView, size_t _desc_val_length, ze_image_desc_t * desc_val);
void btx_push_message_lttng_ust_ze_zeImageViewCreateExt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_image_handle_t phImageView_val);
void btx_push_message_lttng_ust_ze_zeImageViewCreateExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, ze_device_handle_t hDevice, ze_image_desc_t * desc, ze_image_handle_t hImage, ze_image_handle_t * phImageView, size_t _desc_val_length, ze_image_desc_t * desc_val);
void btx_push_message_lttng_ust_ze_zeImageViewCreateExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_image_handle_t phImageView_val);
void btx_push_message_lttng_ust_ze_zeKernelSchedulingHintExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_kernel_handle_t hKernel, ze_scheduling_hint_exp_desc_t * pHint, size_t _pHint_val_length, ze_scheduling_hint_exp_desc_t * pHint_val);
void btx_push_message_lttng_ust_ze_zeKernelSchedulingHintExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeDevicePciGetPropertiesExt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_handle_t hDevice, ze_pci_ext_properties_t * pPciProperties);
void btx_push_message_lttng_ust_ze_zeDevicePciGetPropertiesExt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pPciProperties_val_length, ze_pci_ext_properties_t * pPciProperties_val);
void btx_push_message_lttng_ust_ze_zeCommandListAppendImageCopyToMemoryExt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, void * dstptr, ze_image_handle_t hSrcImage, ze_image_region_t * pSrcRegion, uint32_t destRowPitch, uint32_t destSlicePitch, ze_event_handle_t hSignalEvent, uint32_t numWaitEvents, ze_event_handle_t * phWaitEvents, size_t _pSrcRegion_val_length, ze_image_region_t * pSrcRegion_val, size_t _phWaitEvents_vals_length, ze_event_handle_t * phWaitEvents_vals);
void btx_push_message_lttng_ust_ze_zeCommandListAppendImageCopyToMemoryExt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeCommandListAppendImageCopyFromMemoryExt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, ze_image_handle_t hDstImage, void * srcptr, ze_image_region_t * pDstRegion, uint32_t srcRowPitch, uint32_t srcSlicePitch, ze_event_handle_t hSignalEvent, uint32_t numWaitEvents, ze_event_handle_t * phWaitEvents, size_t _pDstRegion_val_length, ze_image_region_t * pDstRegion_val, size_t _phWaitEvents_vals_length, ze_event_handle_t * phWaitEvents_vals);
void btx_push_message_lttng_ust_ze_zeCommandListAppendImageCopyFromMemoryExt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeImageGetAllocPropertiesExt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, ze_image_handle_t hImage, ze_image_allocation_ext_properties_t * pImageAllocProperties);
void btx_push_message_lttng_ust_ze_zeImageGetAllocPropertiesExt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pImageAllocProperties_val_length, ze_image_allocation_ext_properties_t * pImageAllocProperties_val);
void btx_push_message_lttng_ust_ze_zeModuleInspectLinkageExt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_linkage_inspection_ext_desc_t * pInspectDesc, uint32_t numModules, ze_module_handle_t * phModules, ze_module_build_log_handle_t * phLog, size_t _pInspectDesc_val_length, ze_linkage_inspection_ext_desc_t * pInspectDesc_val, size_t _phModules_vals_length, ze_module_handle_t * phModules_vals);
void btx_push_message_lttng_ust_ze_zeModuleInspectLinkageExt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_module_build_log_handle_t phLog_val);
void btx_push_message_lttng_ust_ze_zeMemFreeExt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, ze_memory_free_ext_desc_t * pMemFreeDesc, void * ptr, size_t _pMemFreeDesc_val_length, ze_memory_free_ext_desc_t * pMemFreeDesc_val);
void btx_push_message_lttng_ust_ze_zeMemFreeExt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeFabricVertexGetExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_driver_handle_t hDriver, uint32_t * pCount, ze_fabric_vertex_handle_t * phVertices, uint32_t pCount_val);
void btx_push_message_lttng_ust_ze_zeFabricVertexGetExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _phVertices_vals_length, ze_fabric_vertex_handle_t * phVertices_vals);
void btx_push_message_lttng_ust_ze_zeFabricVertexGetSubVerticesExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_fabric_vertex_handle_t hVertex, uint32_t * pCount, ze_fabric_vertex_handle_t * phSubvertices, uint32_t pCount_val);
void btx_push_message_lttng_ust_ze_zeFabricVertexGetSubVerticesExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _phSubvertices_vals_length, ze_fabric_vertex_handle_t * phSubvertices_vals);
void btx_push_message_lttng_ust_ze_zeFabricVertexGetPropertiesExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_fabric_vertex_handle_t hVertex, ze_fabric_vertex_exp_properties_t * pVertexProperties);
void btx_push_message_lttng_ust_ze_zeFabricVertexGetPropertiesExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pVertexProperties_val_length, ze_fabric_vertex_exp_properties_t * pVertexProperties_val);
void btx_push_message_lttng_ust_ze_zeFabricVertexGetDeviceExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_fabric_vertex_handle_t hVertex, ze_device_handle_t * phDevice);
void btx_push_message_lttng_ust_ze_zeFabricVertexGetDeviceExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_device_handle_t phDevice_val);
void btx_push_message_lttng_ust_ze_zeDeviceGetFabricVertexExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_handle_t hDevice, ze_fabric_vertex_handle_t * phVertex);
void btx_push_message_lttng_ust_ze_zeDeviceGetFabricVertexExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_fabric_vertex_handle_t phVertex_val);
void btx_push_message_lttng_ust_ze_zeFabricEdgeGetExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_fabric_vertex_handle_t hVertexA, ze_fabric_vertex_handle_t hVertexB, uint32_t * pCount, ze_fabric_edge_handle_t * phEdges, uint32_t pCount_val);
void btx_push_message_lttng_ust_ze_zeFabricEdgeGetExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _phEdges_vals_length, ze_fabric_edge_handle_t * phEdges_vals);
void btx_push_message_lttng_ust_ze_zeFabricEdgeGetVerticesExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_fabric_edge_handle_t hEdge, ze_fabric_vertex_handle_t * phVertexA, ze_fabric_vertex_handle_t * phVertexB);
void btx_push_message_lttng_ust_ze_zeFabricEdgeGetVerticesExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_fabric_vertex_handle_t phVertexA_val, ze_fabric_vertex_handle_t phVertexB_val);
void btx_push_message_lttng_ust_ze_zeFabricEdgeGetPropertiesExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_fabric_edge_handle_t hEdge, ze_fabric_edge_exp_properties_t * pEdgeProperties);
void btx_push_message_lttng_ust_ze_zeFabricEdgeGetPropertiesExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pEdgeProperties_val_length, ze_fabric_edge_exp_properties_t * pEdgeProperties_val);
void btx_push_message_lttng_ust_ze_zeEventQueryKernelTimestampsExt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_event_handle_t hEvent, ze_device_handle_t hDevice, uint32_t * pCount, ze_event_query_kernel_timestamps_results_ext_properties_t * pResults, uint32_t pCount_val);
void btx_push_message_lttng_ust_ze_zeEventQueryKernelTimestampsExt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _pResults_vals_length, ze_event_query_kernel_timestamps_results_ext_properties_t * pResults_vals);
void btx_push_message_lttng_ust_ze_zeRTASBuilderCreateExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_driver_handle_t hDriver, ze_rtas_builder_exp_desc_t * pDescriptor, ze_rtas_builder_exp_handle_t * phBuilder, size_t _pDescriptor_val_length, ze_rtas_builder_exp_desc_t * pDescriptor_val);
void btx_push_message_lttng_ust_ze_zeRTASBuilderCreateExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_rtas_builder_exp_handle_t phBuilder_val);
void btx_push_message_lttng_ust_ze_zeRTASBuilderGetBuildPropertiesExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_rtas_builder_exp_handle_t hBuilder, ze_rtas_builder_build_op_exp_desc_t * pBuildOpDescriptor, ze_rtas_builder_exp_properties_t * pProperties, size_t _pBuildOpDescriptor_val_length, ze_rtas_builder_build_op_exp_desc_t * pBuildOpDescriptor_val);
void btx_push_message_lttng_ust_ze_zeRTASBuilderGetBuildPropertiesExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pProperties_val_length, ze_rtas_builder_exp_properties_t * pProperties_val);
void btx_push_message_lttng_ust_ze_zeDriverRTASFormatCompatibilityCheckExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_driver_handle_t hDriver, ze_rtas_format_exp_t rtasFormatA, ze_rtas_format_exp_t rtasFormatB);
void btx_push_message_lttng_ust_ze_zeDriverRTASFormatCompatibilityCheckExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeRTASBuilderBuildExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_rtas_builder_exp_handle_t hBuilder, ze_rtas_builder_build_op_exp_desc_t * pBuildOpDescriptor, void * pScratchBuffer, size_t scratchBufferSizeBytes, void * pRtasBuffer, size_t rtasBufferSizeBytes, ze_rtas_parallel_operation_exp_handle_t hParallelOperation, void * pBuildUserPtr, ze_rtas_aabb_exp_t * pBounds, size_t * pRtasBufferSizeBytes, size_t _pBuildOpDescriptor_val_length, ze_rtas_builder_build_op_exp_desc_t * pBuildOpDescriptor_val);
void btx_push_message_lttng_ust_ze_zeRTASBuilderBuildExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pBounds_val_length, ze_rtas_aabb_exp_t * pBounds_val, size_t pRtasBufferSizeBytes_val);
void btx_push_message_lttng_ust_ze_zeRTASBuilderDestroyExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_rtas_builder_exp_handle_t hBuilder);
void btx_push_message_lttng_ust_ze_zeRTASBuilderDestroyExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeRTASParallelOperationCreateExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_driver_handle_t hDriver, ze_rtas_parallel_operation_exp_handle_t * phParallelOperation);
void btx_push_message_lttng_ust_ze_zeRTASParallelOperationCreateExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_rtas_parallel_operation_exp_handle_t phParallelOperation_val);
void btx_push_message_lttng_ust_ze_zeRTASParallelOperationGetPropertiesExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_rtas_parallel_operation_exp_handle_t hParallelOperation, ze_rtas_parallel_operation_exp_properties_t * pProperties);
void btx_push_message_lttng_ust_ze_zeRTASParallelOperationGetPropertiesExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pProperties_val_length, ze_rtas_parallel_operation_exp_properties_t * pProperties_val);
void btx_push_message_lttng_ust_ze_zeRTASParallelOperationJoinExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_rtas_parallel_operation_exp_handle_t hParallelOperation);
void btx_push_message_lttng_ust_ze_zeRTASParallelOperationJoinExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeRTASParallelOperationDestroyExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_rtas_parallel_operation_exp_handle_t hParallelOperation);
void btx_push_message_lttng_ust_ze_zeRTASParallelOperationDestroyExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeMemGetPitchFor2dImage_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, ze_device_handle_t hDevice, size_t imageWidth, size_t imageHeight, unsigned int elementSizeInBytes, size_t * rowPitch);
void btx_push_message_lttng_ust_ze_zeMemGetPitchFor2dImage_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t rowPitch_val);
void btx_push_message_lttng_ust_ze_zeImageGetDeviceOffsetExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_image_handle_t hImage, uint64_t * pDeviceOffset);
void btx_push_message_lttng_ust_ze_zeImageGetDeviceOffsetExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint64_t pDeviceOffset_val);
void btx_push_message_lttng_ust_ze_zeCommandListCreateCloneExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, ze_command_list_handle_t * phClonedCommandList);
void btx_push_message_lttng_ust_ze_zeCommandListCreateCloneExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_command_list_handle_t phClonedCommandList_val);
void btx_push_message_lttng_ust_ze_zeCommandListImmediateAppendCommandListsExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandListImmediate, uint32_t numCommandLists, ze_command_list_handle_t * phCommandLists, ze_event_handle_t hSignalEvent, uint32_t numWaitEvents, ze_event_handle_t * phWaitEvents, size_t _phCommandLists_vals_length, ze_command_list_handle_t * phCommandLists_vals, size_t _phWaitEvents_vals_length, ze_event_handle_t * phWaitEvents_vals);
void btx_push_message_lttng_ust_ze_zeCommandListImmediateAppendCommandListsExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeCommandListGetNextCommandIdExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, ze_mutable_command_id_exp_desc_t * desc, uint64_t * pCommandId, size_t _desc_val_length, ze_mutable_command_id_exp_desc_t * desc_val);
void btx_push_message_lttng_ust_ze_zeCommandListGetNextCommandIdExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint64_t pCommandId_val);
void btx_push_message_lttng_ust_ze_zeCommandListGetNextCommandIdWithKernelsExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, ze_mutable_command_id_exp_desc_t * desc, uint32_t numKernels, ze_kernel_handle_t * phKernels, uint64_t * pCommandId, size_t _desc_val_length, ze_mutable_command_id_exp_desc_t * desc_val, size_t _phKernels_vals_length, ze_kernel_handle_t * phKernels_vals);
void btx_push_message_lttng_ust_ze_zeCommandListGetNextCommandIdWithKernelsExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _desc_val_length, ze_mutable_command_id_exp_desc_t * desc_val, uint64_t pCommandId_val);
void btx_push_message_lttng_ust_ze_zeCommandListUpdateMutableCommandsExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, ze_mutable_commands_exp_desc_t * desc, size_t _desc_val_length, ze_mutable_commands_exp_desc_t * desc_val);
void btx_push_message_lttng_ust_ze_zeCommandListUpdateMutableCommandsExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeCommandListUpdateMutableCommandSignalEventExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, uint64_t commandId, ze_event_handle_t hSignalEvent);
void btx_push_message_lttng_ust_ze_zeCommandListUpdateMutableCommandSignalEventExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeCommandListUpdateMutableCommandWaitEventsExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, uint64_t commandId, uint32_t numWaitEvents, ze_event_handle_t * phWaitEvents, size_t _phWaitEvents_vals_length, ze_event_handle_t * phWaitEvents_vals);
void btx_push_message_lttng_ust_ze_zeCommandListUpdateMutableCommandWaitEventsExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeCommandListUpdateMutableCommandKernelsExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, uint32_t numKernels, uint64_t * pCommandId, ze_kernel_handle_t * phKernels, size_t _pCommandId_vals_length, uint64_t * pCommandId_vals, size_t _phKernels_vals_length, ze_kernel_handle_t * phKernels_vals);
void btx_push_message_lttng_ust_ze_zeCommandListUpdateMutableCommandKernelsExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeLoaderInit_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_ze_zeLoaderInit_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeGetRTASBuilderProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, ze_rtas_builder_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_ze_zeGetRTASBuilderProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeGetRTASBuilderExpProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, ze_rtas_builder_exp_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_ze_zeGetRTASBuilderExpProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeGetRTASParallelOperationProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, ze_rtas_parallel_operation_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_ze_zeGetRTASParallelOperationProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeGetRTASParallelOperationExpProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, ze_rtas_parallel_operation_exp_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_ze_zeGetRTASParallelOperationExpProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeGetGlobalProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, ze_global_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_ze_zeGetGlobalProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeGetDriverProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, ze_driver_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_ze_zeGetDriverProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeGetDriverExpProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, ze_driver_exp_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_ze_zeGetDriverExpProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeGetDeviceProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, ze_device_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_ze_zeGetDeviceProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeGetDeviceExpProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, ze_device_exp_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_ze_zeGetDeviceExpProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeGetContextProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, ze_context_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_ze_zeGetContextProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeGetCommandQueueProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, ze_command_queue_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_ze_zeGetCommandQueueProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeGetCommandListProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, ze_command_list_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_ze_zeGetCommandListProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeGetCommandListExpProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, ze_command_list_exp_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_ze_zeGetCommandListExpProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeGetImageProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, ze_image_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_ze_zeGetImageProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeGetImageExpProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, ze_image_exp_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_ze_zeGetImageExpProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeGetMemProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, ze_mem_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_ze_zeGetMemProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeGetMemExpProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, ze_mem_exp_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_ze_zeGetMemExpProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeGetFenceProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, ze_fence_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_ze_zeGetFenceProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeGetEventPoolProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, ze_event_pool_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_ze_zeGetEventPoolProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeGetEventProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, ze_event_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_ze_zeGetEventProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeGetEventExpProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, ze_event_exp_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_ze_zeGetEventExpProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeGetModuleProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, ze_module_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_ze_zeGetModuleProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeGetModuleBuildLogProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, ze_module_build_log_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_ze_zeGetModuleBuildLogProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeGetKernelProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, ze_kernel_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_ze_zeGetKernelProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeGetKernelExpProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, ze_kernel_exp_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_ze_zeGetKernelExpProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeGetSamplerProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, ze_sampler_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_ze_zeGetSamplerProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeGetPhysicalMemProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, ze_physical_mem_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_ze_zeGetPhysicalMemProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeGetVirtualMemProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, ze_virtual_mem_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_ze_zeGetVirtualMemProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeGetFabricVertexExpProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, ze_fabric_vertex_exp_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_ze_zeGetFabricVertexExpProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_zeGetFabricEdgeExpProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, ze_fabric_edge_exp_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_ze_zeGetFabricEdgeExpProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetModuleGetDebugInfo_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_module_handle_t hModule, zet_module_debug_info_format_t format, size_t * pSize, uint8_t * pDebugInfo, size_t pSize_val);
void btx_push_message_lttng_ust_zet_zetModuleGetDebugInfo_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t pSize_val);
void btx_push_message_lttng_ust_zet_zetDeviceGetDebugProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_device_handle_t hDevice, zet_device_debug_properties_t * pDebugProperties);
void btx_push_message_lttng_ust_zet_zetDeviceGetDebugProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pDebugProperties_val_length, zet_device_debug_properties_t * pDebugProperties_val);
void btx_push_message_lttng_ust_zet_zetDebugAttach_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_device_handle_t hDevice, zet_debug_config_t * config, zet_debug_session_handle_t * phDebug, size_t _config_val_length, zet_debug_config_t * config_val);
void btx_push_message_lttng_ust_zet_zetDebugAttach_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, zet_debug_session_handle_t phDebug_val);
void btx_push_message_lttng_ust_zet_zetDebugDetach_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_debug_session_handle_t hDebug);
void btx_push_message_lttng_ust_zet_zetDebugDetach_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetDebugReadEvent_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_debug_session_handle_t hDebug, uint64_t timeout, zet_debug_event_t * event);
void btx_push_message_lttng_ust_zet_zetDebugReadEvent_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _event_val_length, zet_debug_event_t * event_val);
void btx_push_message_lttng_ust_zet_zetDebugAcknowledgeEvent_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_debug_session_handle_t hDebug, zet_debug_event_t * event);
void btx_push_message_lttng_ust_zet_zetDebugAcknowledgeEvent_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetDebugInterrupt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_debug_session_handle_t hDebug, ze_device_thread_t thread);
void btx_push_message_lttng_ust_zet_zetDebugInterrupt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetDebugResume_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_debug_session_handle_t hDebug, ze_device_thread_t thread);
void btx_push_message_lttng_ust_zet_zetDebugResume_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetDebugReadMemory_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_debug_session_handle_t hDebug, ze_device_thread_t thread, zet_debug_memory_space_desc_t * desc, size_t size, void * buffer, size_t _desc_val_length, zet_debug_memory_space_desc_t * desc_val);
void btx_push_message_lttng_ust_zet_zetDebugReadMemory_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetDebugWriteMemory_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_debug_session_handle_t hDebug, ze_device_thread_t thread, zet_debug_memory_space_desc_t * desc, size_t size, void * buffer, size_t _desc_val_length, zet_debug_memory_space_desc_t * desc_val);
void btx_push_message_lttng_ust_zet_zetDebugWriteMemory_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetDebugGetRegisterSetProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_device_handle_t hDevice, uint32_t * pCount, zet_debug_regset_properties_t * pRegisterSetProperties, uint32_t pCount_val);
void btx_push_message_lttng_ust_zet_zetDebugGetRegisterSetProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _pRegisterSetProperties_vals_length, zet_debug_regset_properties_t * pRegisterSetProperties_vals);
void btx_push_message_lttng_ust_zet_zetDebugGetThreadRegisterSetProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_debug_session_handle_t hDebug, ze_device_thread_t thread, uint32_t * pCount, zet_debug_regset_properties_t * pRegisterSetProperties, uint32_t pCount_val);
void btx_push_message_lttng_ust_zet_zetDebugGetThreadRegisterSetProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _pRegisterSetProperties_vals_length, zet_debug_regset_properties_t * pRegisterSetProperties_vals);
void btx_push_message_lttng_ust_zet_zetDebugReadRegisters_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_debug_session_handle_t hDebug, ze_device_thread_t thread, uint32_t type, uint32_t start, uint32_t count, void * pRegisterValues);
void btx_push_message_lttng_ust_zet_zetDebugReadRegisters_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetDebugWriteRegisters_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_debug_session_handle_t hDebug, ze_device_thread_t thread, uint32_t type, uint32_t start, uint32_t count, void * pRegisterValues);
void btx_push_message_lttng_ust_zet_zetDebugWriteRegisters_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetMetricGroupGet_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_device_handle_t hDevice, uint32_t * pCount, zet_metric_group_handle_t * phMetricGroups, uint32_t pCount_val);
void btx_push_message_lttng_ust_zet_zetMetricGroupGet_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _phMetricGroups_vals_length, zet_metric_group_handle_t * phMetricGroups_vals);
void btx_push_message_lttng_ust_zet_zetMetricGroupGetProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_group_handle_t hMetricGroup, zet_metric_group_properties_t * pProperties);
void btx_push_message_lttng_ust_zet_zetMetricGroupGetProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pProperties_val_length, zet_metric_group_properties_t * pProperties_val);
void btx_push_message_lttng_ust_zet_zetMetricGroupCalculateMetricValues_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_group_handle_t hMetricGroup, zet_metric_group_calculation_type_t type, size_t rawDataSize, uint8_t * pRawData, uint32_t * pMetricValueCount, zet_typed_value_t * pMetricValues, size_t _pRawData_vals_length, uint8_t * pRawData_vals, uint32_t pMetricValueCount_val);
void btx_push_message_lttng_ust_zet_zetMetricGroupCalculateMetricValues_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pMetricValueCount_val, size_t _pMetricValues_vals_length, zet_typed_value_t * pMetricValues_vals);
void btx_push_message_lttng_ust_zet_zetMetricGet_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_group_handle_t hMetricGroup, uint32_t * pCount, zet_metric_handle_t * phMetrics, uint32_t pCount_val);
void btx_push_message_lttng_ust_zet_zetMetricGet_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _phMetrics_vals_length, zet_metric_handle_t * phMetrics_vals);
void btx_push_message_lttng_ust_zet_zetMetricGetProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_handle_t hMetric, zet_metric_properties_t * pProperties);
void btx_push_message_lttng_ust_zet_zetMetricGetProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pProperties_val_length, zet_metric_properties_t * pProperties_val);
void btx_push_message_lttng_ust_zet_zetContextActivateMetricGroups_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_context_handle_t hContext, zet_device_handle_t hDevice, uint32_t count, zet_metric_group_handle_t * phMetricGroups, size_t _phMetricGroups_vals_length, zet_metric_group_handle_t * phMetricGroups_vals);
void btx_push_message_lttng_ust_zet_zetContextActivateMetricGroups_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetMetricStreamerOpen_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_context_handle_t hContext, zet_device_handle_t hDevice, zet_metric_group_handle_t hMetricGroup, zet_metric_streamer_desc_t * desc, ze_event_handle_t hNotificationEvent, zet_metric_streamer_handle_t * phMetricStreamer, size_t _desc_val_length, zet_metric_streamer_desc_t * desc_val);
void btx_push_message_lttng_ust_zet_zetMetricStreamerOpen_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, zet_metric_streamer_handle_t phMetricStreamer_val);
void btx_push_message_lttng_ust_zet_zetCommandListAppendMetricStreamerMarker_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_command_list_handle_t hCommandList, zet_metric_streamer_handle_t hMetricStreamer, uint32_t value);
void btx_push_message_lttng_ust_zet_zetCommandListAppendMetricStreamerMarker_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetMetricStreamerClose_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_streamer_handle_t hMetricStreamer);
void btx_push_message_lttng_ust_zet_zetMetricStreamerClose_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetMetricStreamerReadData_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_streamer_handle_t hMetricStreamer, uint32_t maxReportCount, size_t * pRawDataSize, uint8_t * pRawData, size_t pRawDataSize_val);
void btx_push_message_lttng_ust_zet_zetMetricStreamerReadData_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t pRawDataSize_val, size_t _pRawData_vals_length, uint8_t * pRawData_vals);
void btx_push_message_lttng_ust_zet_zetMetricQueryPoolCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_context_handle_t hContext, zet_device_handle_t hDevice, zet_metric_group_handle_t hMetricGroup, zet_metric_query_pool_desc_t * desc, zet_metric_query_pool_handle_t * phMetricQueryPool, size_t _desc_val_length, zet_metric_query_pool_desc_t * desc_val);
void btx_push_message_lttng_ust_zet_zetMetricQueryPoolCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, zet_metric_query_pool_handle_t phMetricQueryPool_val);
void btx_push_message_lttng_ust_zet_zetMetricQueryPoolDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_query_pool_handle_t hMetricQueryPool);
void btx_push_message_lttng_ust_zet_zetMetricQueryPoolDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetMetricQueryCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_query_pool_handle_t hMetricQueryPool, uint32_t index, zet_metric_query_handle_t * phMetricQuery);
void btx_push_message_lttng_ust_zet_zetMetricQueryCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, zet_metric_query_handle_t phMetricQuery_val);
void btx_push_message_lttng_ust_zet_zetMetricQueryDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_query_handle_t hMetricQuery);
void btx_push_message_lttng_ust_zet_zetMetricQueryDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetMetricQueryReset_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_query_handle_t hMetricQuery);
void btx_push_message_lttng_ust_zet_zetMetricQueryReset_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetCommandListAppendMetricQueryBegin_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_command_list_handle_t hCommandList, zet_metric_query_handle_t hMetricQuery);
void btx_push_message_lttng_ust_zet_zetCommandListAppendMetricQueryBegin_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetCommandListAppendMetricQueryEnd_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_command_list_handle_t hCommandList, zet_metric_query_handle_t hMetricQuery, ze_event_handle_t hSignalEvent, uint32_t numWaitEvents, ze_event_handle_t * phWaitEvents, size_t _phWaitEvents_vals_length, ze_event_handle_t * phWaitEvents_vals);
void btx_push_message_lttng_ust_zet_zetCommandListAppendMetricQueryEnd_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetCommandListAppendMetricMemoryBarrier_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_command_list_handle_t hCommandList);
void btx_push_message_lttng_ust_zet_zetCommandListAppendMetricMemoryBarrier_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetMetricQueryGetData_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_query_handle_t hMetricQuery, size_t * pRawDataSize, uint8_t * pRawData, size_t pRawDataSize_val);
void btx_push_message_lttng_ust_zet_zetMetricQueryGetData_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t pRawDataSize_val, size_t _pRawData_vals_length, uint8_t * pRawData_vals);
void btx_push_message_lttng_ust_zet_zetKernelGetProfileInfo_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_kernel_handle_t hKernel, zet_profile_properties_t * pProfileProperties);
void btx_push_message_lttng_ust_zet_zetKernelGetProfileInfo_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pProfileProperties_val_length, zet_profile_properties_t * pProfileProperties_val);
void btx_push_message_lttng_ust_zet_zetTracerExpCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_context_handle_t hContext, zet_tracer_exp_desc_t * desc, zet_tracer_exp_handle_t * phTracer, size_t _desc_val_length, zet_tracer_exp_desc_t * desc_val);
void btx_push_message_lttng_ust_zet_zetTracerExpCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, zet_tracer_exp_handle_t phTracer_val);
void btx_push_message_lttng_ust_zet_zetTracerExpDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_tracer_exp_handle_t hTracer);
void btx_push_message_lttng_ust_zet_zetTracerExpDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetTracerExpSetPrologues_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_tracer_exp_handle_t hTracer, zet_core_callbacks_t * pCoreCbs);
void btx_push_message_lttng_ust_zet_zetTracerExpSetPrologues_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetTracerExpSetEpilogues_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_tracer_exp_handle_t hTracer, zet_core_callbacks_t * pCoreCbs);
void btx_push_message_lttng_ust_zet_zetTracerExpSetEpilogues_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetTracerExpSetEnabled_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_tracer_exp_handle_t hTracer, ze_bool_t enable);
void btx_push_message_lttng_ust_zet_zetTracerExpSetEnabled_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetDeviceGetConcurrentMetricGroupsExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_device_handle_t hDevice, uint32_t metricGroupCount, zet_metric_group_handle_t * phMetricGroups, uint32_t * pMetricGroupsCountPerConcurrentGroup, uint32_t * pConcurrentGroupCount);
void btx_push_message_lttng_ust_zet_zetDeviceGetConcurrentMetricGroupsExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetMetricTracerCreateExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_context_handle_t hContext, zet_device_handle_t hDevice, uint32_t metricGroupCount, zet_metric_group_handle_t * phMetricGroups, zet_metric_tracer_exp_desc_t * desc, ze_event_handle_t hNotificationEvent, zet_metric_tracer_exp_handle_t * phMetricTracer);
void btx_push_message_lttng_ust_zet_zetMetricTracerCreateExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetMetricTracerDestroyExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_tracer_exp_handle_t hMetricTracer);
void btx_push_message_lttng_ust_zet_zetMetricTracerDestroyExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetMetricTracerEnableExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_tracer_exp_handle_t hMetricTracer, ze_bool_t synchronous);
void btx_push_message_lttng_ust_zet_zetMetricTracerEnableExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetMetricTracerDisableExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_tracer_exp_handle_t hMetricTracer, ze_bool_t synchronous);
void btx_push_message_lttng_ust_zet_zetMetricTracerDisableExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetMetricTracerReadDataExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_tracer_exp_handle_t hMetricTracer, size_t * pRawDataSize, uint8_t * pRawData);
void btx_push_message_lttng_ust_zet_zetMetricTracerReadDataExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetMetricDecoderCreateExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_tracer_exp_handle_t hMetricTracer, zet_metric_decoder_exp_handle_t * phMetricDecoder);
void btx_push_message_lttng_ust_zet_zetMetricDecoderCreateExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetMetricDecoderDestroyExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_decoder_exp_handle_t phMetricDecoder);
void btx_push_message_lttng_ust_zet_zetMetricDecoderDestroyExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetMetricDecoderGetDecodableMetricsExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_decoder_exp_handle_t hMetricDecoder, uint32_t * pCount, zet_metric_handle_t * phMetrics);
void btx_push_message_lttng_ust_zet_zetMetricDecoderGetDecodableMetricsExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetMetricTracerDecodeExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_decoder_exp_handle_t phMetricDecoder, size_t * pRawDataSize, uint8_t * pRawData, uint32_t metricsCount, zet_metric_handle_t * phMetrics, uint32_t * pSetCount, uint32_t * pMetricEntriesCountPerSet, uint32_t * pMetricEntriesCount, zet_metric_entry_exp_t * pMetricEntries);
void btx_push_message_lttng_ust_zet_zetMetricTracerDecodeExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetCommandListAppendMarkerExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_command_list_handle_t hCommandList, zet_metric_group_handle_t hMetricGroup, uint32_t value);
void btx_push_message_lttng_ust_zet_zetCommandListAppendMarkerExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetDeviceEnableMetricsExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_device_handle_t hDevice);
void btx_push_message_lttng_ust_zet_zetDeviceEnableMetricsExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetDeviceDisableMetricsExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_device_handle_t hDevice);
void btx_push_message_lttng_ust_zet_zetDeviceDisableMetricsExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetMetricGroupCalculateMultipleMetricValuesExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_group_handle_t hMetricGroup, zet_metric_group_calculation_type_t type, size_t rawDataSize, uint8_t * pRawData, uint32_t * pSetCount, uint32_t * pTotalMetricValueCount, uint32_t * pMetricCounts, zet_typed_value_t * pMetricValues, size_t _pRawData_vals_length, uint8_t * pRawData_vals, uint32_t pSetCount_val, uint32_t pTotalMetricValueCount_val);
void btx_push_message_lttng_ust_zet_zetMetricGroupCalculateMultipleMetricValuesExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pSetCount_val, uint32_t pTotalMetricValueCount_val, size_t _pMetricCounts_vals_length, uint32_t * pMetricCounts_vals, size_t _pMetricValues_vals_length, zet_typed_value_t * pMetricValues_vals);
void btx_push_message_lttng_ust_zet_zetMetricGroupGetGlobalTimestampsExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_group_handle_t hMetricGroup, ze_bool_t synchronizedWithHost, uint64_t * globalTimestamp, uint64_t * metricTimestamp);
void btx_push_message_lttng_ust_zet_zetMetricGroupGetGlobalTimestampsExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint64_t globalTimestamp_val, uint64_t metricTimestamp_val);
void btx_push_message_lttng_ust_zet_zetMetricGroupGetExportDataExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_group_handle_t hMetricGroup, uint8_t * pRawData, size_t rawDataSize, size_t * pExportDataSize, uint8_t * pExportData, size_t pExportDataSize_val);
void btx_push_message_lttng_ust_zet_zetMetricGroupGetExportDataExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t pExportDataSize_val);
void btx_push_message_lttng_ust_zet_zetMetricGroupCalculateMetricExportDataExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_driver_handle_t hDriver, zet_metric_group_calculation_type_t type, size_t exportDataSize, uint8_t * pExportData, zet_metric_calculate_exp_desc_t * pCalculateDescriptor, uint32_t * pSetCount, uint32_t * pTotalMetricValueCount, uint32_t * pMetricCounts, zet_typed_value_t * pMetricValues, size_t _pCalculateDescriptor_val_length, zet_metric_calculate_exp_desc_t * pCalculateDescriptor_val, uint32_t pSetCount_val, uint32_t pTotalMetricValueCount_val);
void btx_push_message_lttng_ust_zet_zetMetricGroupCalculateMetricExportDataExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pSetCount_val, uint32_t pTotalMetricValueCount_val, size_t _pMetricCounts_vals_length, uint32_t * pMetricCounts_vals, size_t _pMetricValues_vals_length, zet_typed_value_t * pMetricValues_vals);
void btx_push_message_lttng_ust_zet_zetMetricProgrammableGetExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_device_handle_t hDevice, uint32_t * pCount, zet_metric_programmable_exp_handle_t * phMetricProgrammables, uint32_t pCount_val);
void btx_push_message_lttng_ust_zet_zetMetricProgrammableGetExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _phMetricProgrammables_vals_length, zet_metric_programmable_exp_handle_t * phMetricProgrammables_vals);
void btx_push_message_lttng_ust_zet_zetMetricProgrammableGetPropertiesExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_programmable_exp_handle_t hMetricProgrammable, zet_metric_programmable_exp_properties_t * pProperties);
void btx_push_message_lttng_ust_zet_zetMetricProgrammableGetPropertiesExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pProperties_val_length, zet_metric_programmable_exp_properties_t * pProperties_val);
void btx_push_message_lttng_ust_zet_zetMetricProgrammableGetParamInfoExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_programmable_exp_handle_t hMetricProgrammable, uint32_t * pParameterCount, zet_metric_programmable_param_info_exp_t * pParameterInfo, uint32_t pParameterCount_val);
void btx_push_message_lttng_ust_zet_zetMetricProgrammableGetParamInfoExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pParameterCount_val, size_t _pParameterInfo_vals_length, zet_metric_programmable_param_info_exp_t * pParameterInfo_vals);
void btx_push_message_lttng_ust_zet_zetMetricProgrammableGetParamValueInfoExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_programmable_exp_handle_t hMetricProgrammable, uint32_t parameterOrdinal, uint32_t * pValueInfoCount, zet_metric_programmable_param_value_info_exp_t * pValueInfo, uint32_t pValueInfoCount_val);
void btx_push_message_lttng_ust_zet_zetMetricProgrammableGetParamValueInfoExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pValueInfoCount_val, size_t _pValueInfo_vals_length, zet_metric_programmable_param_value_info_exp_t * pValueInfo_vals);
void btx_push_message_lttng_ust_zet_zetMetricCreateFromProgrammableExp2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_programmable_exp_handle_t hMetricProgrammable, uint32_t parameterCount, zet_metric_programmable_param_value_exp_t * pParameterValues, char * pName, char * pDescription, uint32_t * pMetricHandleCount, zet_metric_handle_t * phMetricHandles);
void btx_push_message_lttng_ust_zet_zetMetricCreateFromProgrammableExp2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetMetricCreateFromProgrammableExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_programmable_exp_handle_t hMetricProgrammable, zet_metric_programmable_param_value_exp_t * pParameterValues, uint32_t parameterCount, char * pName, char * pDescription, uint32_t * pMetricHandleCount, zet_metric_handle_t * phMetricHandles, size_t _pParameterValues_vals_length, zet_metric_programmable_param_value_exp_t * pParameterValues_vals, char * pName_val, char * pDescription_val, uint32_t pMetricHandleCount_val);
void btx_push_message_lttng_ust_zet_zetMetricCreateFromProgrammableExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pMetricHandleCount_val, size_t _phMetricHandles_vals_length, zet_metric_handle_t * phMetricHandles_vals);
void btx_push_message_lttng_ust_zet_zetDeviceCreateMetricGroupsFromMetricsExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_device_handle_t hDevice, uint32_t metricCount, zet_metric_handle_t * phMetrics, char * pMetricGroupNamePrefix, char * pDescription, uint32_t * pMetricGroupCount, zet_metric_group_handle_t * phMetricGroup);
void btx_push_message_lttng_ust_zet_zetDeviceCreateMetricGroupsFromMetricsExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetMetricGroupCreateExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_device_handle_t hDevice, char * pName, char * pDescription, zet_metric_group_sampling_type_flags_t samplingType, zet_metric_group_handle_t * phMetricGroup, char * pName_val, char * pDescription_val);
void btx_push_message_lttng_ust_zet_zetMetricGroupCreateExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, zet_metric_group_handle_t phMetricGroup_val);
void btx_push_message_lttng_ust_zet_zetMetricGroupAddMetricExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_group_handle_t hMetricGroup, zet_metric_handle_t hMetric, size_t * pErrorStringSize, char * pErrorString, size_t pErrorStringSize_val);
void btx_push_message_lttng_ust_zet_zetMetricGroupAddMetricExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t pErrorStringSize_val, size_t _pErrorString_vals_length, char * pErrorString_vals);
void btx_push_message_lttng_ust_zet_zetMetricGroupRemoveMetricExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_group_handle_t hMetricGroup, zet_metric_handle_t hMetric);
void btx_push_message_lttng_ust_zet_zetMetricGroupRemoveMetricExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetMetricGroupCloseExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_group_handle_t hMetricGroup);
void btx_push_message_lttng_ust_zet_zetMetricGroupCloseExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetMetricGroupDestroyExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_group_handle_t hMetricGroup);
void btx_push_message_lttng_ust_zet_zetMetricGroupDestroyExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetMetricDestroyExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_handle_t hMetric);
void btx_push_message_lttng_ust_zet_zetMetricDestroyExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetGetMetricProgrammableExpProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zet_metric_programmable_exp_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zet_zetGetMetricProgrammableExpProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetGetMetricTracerExpProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zet_metric_tracer_exp_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zet_zetGetMetricTracerExpProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetGetMetricDecoderExpProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zet_metric_decoder_exp_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zet_zetGetMetricDecoderExpProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetGetDeviceProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zet_device_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zet_zetGetDeviceProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetGetDeviceExpProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zet_device_exp_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zet_zetGetDeviceExpProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetGetContextProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zet_context_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zet_zetGetContextProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetGetCommandListProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zet_command_list_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zet_zetGetCommandListProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetGetCommandListExpProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zet_command_list_exp_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zet_zetGetCommandListExpProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetGetModuleProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zet_module_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zet_zetGetModuleProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetGetKernelProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zet_kernel_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zet_zetGetKernelProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetGetMetricProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zet_metric_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zet_zetGetMetricProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetGetMetricExpProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zet_metric_exp_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zet_zetGetMetricExpProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetGetMetricGroupProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zet_metric_group_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zet_zetGetMetricGroupProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetGetMetricGroupExpProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zet_metric_group_exp_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zet_zetGetMetricGroupExpProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetGetMetricStreamerProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zet_metric_streamer_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zet_zetGetMetricStreamerProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetGetMetricQueryPoolProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zet_metric_query_pool_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zet_zetGetMetricQueryPoolProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetGetMetricQueryProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zet_metric_query_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zet_zetGetMetricQueryProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetGetTracerExpProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zet_tracer_exp_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zet_zetGetTracerExpProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zet_zetGetDebugProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zet_debug_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zet_zetGetDebugProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesInit_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_init_flags_t flags);
void btx_push_message_lttng_ust_zes_zesInit_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesDriverGet_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, uint32_t * pCount, zes_driver_handle_t * phDrivers, uint32_t pCount_val);
void btx_push_message_lttng_ust_zes_zesDriverGet_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _phDrivers_vals_length, zes_driver_handle_t * phDrivers_vals);
void btx_push_message_lttng_ust_zes_zesDriverGetExtensionProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_driver_handle_t hDriver, uint32_t * pCount, zes_driver_extension_properties_t * pExtensionProperties, uint32_t pCount_val);
void btx_push_message_lttng_ust_zes_zesDriverGetExtensionProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _pExtensionProperties_vals_length, zes_driver_extension_properties_t * pExtensionProperties_vals);
void btx_push_message_lttng_ust_zes_zesDriverGetExtensionFunctionAddress_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_driver_handle_t hDriver, char * name, void ** ppFunctionAddress, char * name_val);
void btx_push_message_lttng_ust_zes_zesDriverGetExtensionFunctionAddress_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, void * ppFunctionAddress_val);
void btx_push_message_lttng_ust_zes_zesDeviceGet_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_driver_handle_t hDriver, uint32_t * pCount, zes_device_handle_t * phDevices, uint32_t pCount_val);
void btx_push_message_lttng_ust_zes_zesDeviceGet_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _phDevices_vals_length, zes_device_handle_t * phDevices_vals);
void btx_push_message_lttng_ust_zes_zesDeviceGetProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, zes_device_properties_t * pProperties);
void btx_push_message_lttng_ust_zes_zesDeviceGetProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pProperties_val_length, zes_device_properties_t * pProperties_val);
void btx_push_message_lttng_ust_zes_zesDeviceGetState_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, zes_device_state_t * pState);
void btx_push_message_lttng_ust_zes_zesDeviceGetState_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pState_val_length, zes_device_state_t * pState_val);
void btx_push_message_lttng_ust_zes_zesDeviceReset_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, ze_bool_t force);
void btx_push_message_lttng_ust_zes_zesDeviceReset_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesDeviceResetExt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, zes_reset_properties_t * pProperties, size_t _pProperties_val_length, zes_reset_properties_t * pProperties_val);
void btx_push_message_lttng_ust_zes_zesDeviceResetExt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesDeviceProcessesGetState_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, uint32_t * pCount, zes_process_state_t * pProcesses, uint32_t pCount_val);
void btx_push_message_lttng_ust_zes_zesDeviceProcessesGetState_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _pProcesses_vals_length, zes_process_state_t * pProcesses_vals);
void btx_push_message_lttng_ust_zes_zesDevicePciGetProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, zes_pci_properties_t * pProperties);
void btx_push_message_lttng_ust_zes_zesDevicePciGetProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pProperties_val_length, zes_pci_properties_t * pProperties_val);
void btx_push_message_lttng_ust_zes_zesDevicePciGetState_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, zes_pci_state_t * pState);
void btx_push_message_lttng_ust_zes_zesDevicePciGetState_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pState_val_length, zes_pci_state_t * pState_val);
void btx_push_message_lttng_ust_zes_zesDevicePciGetBars_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, uint32_t * pCount, zes_pci_bar_properties_t * pProperties, uint32_t pCount_val);
void btx_push_message_lttng_ust_zes_zesDevicePciGetBars_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _pProperties_vals_length, zes_pci_bar_properties_t * pProperties_vals);
void btx_push_message_lttng_ust_zes_zesDevicePciGetStats_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, zes_pci_stats_t * pStats);
void btx_push_message_lttng_ust_zes_zesDevicePciGetStats_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pStats_val_length, zes_pci_stats_t * pStats_val);
void btx_push_message_lttng_ust_zes_zesDeviceSetOverclockWaiver_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice);
void btx_push_message_lttng_ust_zes_zesDeviceSetOverclockWaiver_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesDeviceGetOverclockDomains_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, uint32_t * pOverclockDomains);
void btx_push_message_lttng_ust_zes_zesDeviceGetOverclockDomains_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pOverclockDomains_val);
void btx_push_message_lttng_ust_zes_zesDeviceGetOverclockControls_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, zes_overclock_domain_t domainType, uint32_t * pAvailableControls);
void btx_push_message_lttng_ust_zes_zesDeviceGetOverclockControls_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pAvailableControls_val);
void btx_push_message_lttng_ust_zes_zesDeviceResetOverclockSettings_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, ze_bool_t onShippedState);
void btx_push_message_lttng_ust_zes_zesDeviceResetOverclockSettings_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesDeviceReadOverclockState_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, zes_overclock_mode_t * pOverclockMode, ze_bool_t * pWaiverSetting, ze_bool_t * pOverclockState, zes_pending_action_t * pPendingAction, ze_bool_t * pPendingReset);
void btx_push_message_lttng_ust_zes_zesDeviceReadOverclockState_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, zes_overclock_mode_t pOverclockMode_val, ze_bool_t pWaiverSetting_val, ze_bool_t pOverclockState_val, zes_pending_action_t pPendingAction_val, ze_bool_t pPendingReset_val);
void btx_push_message_lttng_ust_zes_zesDeviceEnumOverclockDomains_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, uint32_t * pCount, zes_overclock_handle_t * phDomainHandle, uint32_t pCount_val);
void btx_push_message_lttng_ust_zes_zesDeviceEnumOverclockDomains_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _phDomainHandle_vals_length, zes_overclock_handle_t * phDomainHandle_vals);
void btx_push_message_lttng_ust_zes_zesOverclockGetDomainProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_overclock_handle_t hDomainHandle, zes_overclock_properties_t * pDomainProperties);
void btx_push_message_lttng_ust_zes_zesOverclockGetDomainProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pDomainProperties_val_length, zes_overclock_properties_t * pDomainProperties_val);
void btx_push_message_lttng_ust_zes_zesOverclockGetDomainVFProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_overclock_handle_t hDomainHandle, zes_vf_property_t * pVFProperties);
void btx_push_message_lttng_ust_zes_zesOverclockGetDomainVFProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pVFProperties_val_length, zes_vf_property_t * pVFProperties_val);
void btx_push_message_lttng_ust_zes_zesOverclockGetDomainControlProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_overclock_handle_t hDomainHandle, zes_overclock_control_t DomainControl, zes_control_property_t * pControlProperties);
void btx_push_message_lttng_ust_zes_zesOverclockGetDomainControlProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pControlProperties_val_length, zes_control_property_t * pControlProperties_val);
void btx_push_message_lttng_ust_zes_zesOverclockGetControlCurrentValue_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_overclock_handle_t hDomainHandle, zes_overclock_control_t DomainControl, double * pValue);
void btx_push_message_lttng_ust_zes_zesOverclockGetControlCurrentValue_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, double pValue_val);
void btx_push_message_lttng_ust_zes_zesOverclockGetControlPendingValue_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_overclock_handle_t hDomainHandle, zes_overclock_control_t DomainControl, double * pValue);
void btx_push_message_lttng_ust_zes_zesOverclockGetControlPendingValue_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, double pValue_val);
void btx_push_message_lttng_ust_zes_zesOverclockSetControlUserValue_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_overclock_handle_t hDomainHandle, zes_overclock_control_t DomainControl, double pValue, zes_pending_action_t * pPendingAction);
void btx_push_message_lttng_ust_zes_zesOverclockSetControlUserValue_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, zes_pending_action_t pPendingAction_val);
void btx_push_message_lttng_ust_zes_zesOverclockGetControlState_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_overclock_handle_t hDomainHandle, zes_overclock_control_t DomainControl, zes_control_state_t * pControlState, zes_pending_action_t * pPendingAction);
void btx_push_message_lttng_ust_zes_zesOverclockGetControlState_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, zes_control_state_t pControlState_val, zes_pending_action_t pPendingAction_val);
void btx_push_message_lttng_ust_zes_zesOverclockGetVFPointValues_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_overclock_handle_t hDomainHandle, zes_vf_type_t VFType, zes_vf_array_type_t VFArrayType, uint32_t PointIndex, uint32_t * PointValue);
void btx_push_message_lttng_ust_zes_zesOverclockGetVFPointValues_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t PointValue_val);
void btx_push_message_lttng_ust_zes_zesOverclockSetVFPointValues_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_overclock_handle_t hDomainHandle, zes_vf_type_t VFType, uint32_t PointIndex, uint32_t PointValue);
void btx_push_message_lttng_ust_zes_zesOverclockSetVFPointValues_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesDeviceEnumDiagnosticTestSuites_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, uint32_t * pCount, zes_diag_handle_t * phDiagnostics, uint32_t pCount_val);
void btx_push_message_lttng_ust_zes_zesDeviceEnumDiagnosticTestSuites_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _phDiagnostics_vals_length, zes_diag_handle_t * phDiagnostics_vals);
void btx_push_message_lttng_ust_zes_zesDiagnosticsGetProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_diag_handle_t hDiagnostics, zes_diag_properties_t * pProperties);
void btx_push_message_lttng_ust_zes_zesDiagnosticsGetProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pProperties_val_length, zes_diag_properties_t * pProperties_val);
void btx_push_message_lttng_ust_zes_zesDiagnosticsGetTests_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_diag_handle_t hDiagnostics, uint32_t * pCount, zes_diag_test_t * pTests, uint32_t pCount_val);
void btx_push_message_lttng_ust_zes_zesDiagnosticsGetTests_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _pTests_vals_length, zes_diag_test_t * pTests_vals);
void btx_push_message_lttng_ust_zes_zesDiagnosticsRunTests_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_diag_handle_t hDiagnostics, uint32_t startIndex, uint32_t endIndex, zes_diag_result_t * pResult);
void btx_push_message_lttng_ust_zes_zesDiagnosticsRunTests_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, zes_diag_result_t pResult_val);
void btx_push_message_lttng_ust_zes_zesDeviceEccAvailable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, ze_bool_t * pAvailable);
void btx_push_message_lttng_ust_zes_zesDeviceEccAvailable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_bool_t pAvailable_val);
void btx_push_message_lttng_ust_zes_zesDeviceEccConfigurable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, ze_bool_t * pConfigurable);
void btx_push_message_lttng_ust_zes_zesDeviceEccConfigurable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_bool_t pConfigurable_val);
void btx_push_message_lttng_ust_zes_zesDeviceGetEccState_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, zes_device_ecc_properties_t * pState);
void btx_push_message_lttng_ust_zes_zesDeviceGetEccState_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pState_val_length, zes_device_ecc_properties_t * pState_val);
void btx_push_message_lttng_ust_zes_zesDeviceSetEccState_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, zes_device_ecc_desc_t * newState, zes_device_ecc_properties_t * pState, size_t _newState_val_length, zes_device_ecc_desc_t * newState_val);
void btx_push_message_lttng_ust_zes_zesDeviceSetEccState_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pState_val_length, zes_device_ecc_properties_t * pState_val);
void btx_push_message_lttng_ust_zes_zesDeviceEnumEngineGroups_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, uint32_t * pCount, zes_engine_handle_t * phEngine, uint32_t pCount_val);
void btx_push_message_lttng_ust_zes_zesDeviceEnumEngineGroups_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _phEngine_vals_length, zes_engine_handle_t * phEngine_vals);
void btx_push_message_lttng_ust_zes_zesEngineGetProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_engine_handle_t hEngine, zes_engine_properties_t * pProperties);
void btx_push_message_lttng_ust_zes_zesEngineGetProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pProperties_val_length, zes_engine_properties_t * pProperties_val);
void btx_push_message_lttng_ust_zes_zesEngineGetActivity_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_engine_handle_t hEngine, zes_engine_stats_t * pStats);
void btx_push_message_lttng_ust_zes_zesEngineGetActivity_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pStats_val_length, zes_engine_stats_t * pStats_val);
void btx_push_message_lttng_ust_zes_zesDeviceEventRegister_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, zes_event_type_flags_t events);
void btx_push_message_lttng_ust_zes_zesDeviceEventRegister_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesDriverEventListen_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_driver_handle_t hDriver, uint32_t timeout, uint32_t count, zes_device_handle_t * phDevices, uint32_t * pNumDeviceEvents, zes_event_type_flags_t * pEvents, size_t _phDevices_vals_length, zes_device_handle_t * phDevices_vals);
void btx_push_message_lttng_ust_zes_zesDriverEventListen_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pNumDeviceEvents_val, size_t _pEvents_vals_length, zes_event_type_flags_t * pEvents_vals);
void btx_push_message_lttng_ust_zes_zesDriverEventListenEx_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_driver_handle_t hDriver, uint64_t timeout, uint32_t count, zes_device_handle_t * phDevices, uint32_t * pNumDeviceEvents, zes_event_type_flags_t * pEvents, size_t _phDevices_vals_length, zes_device_handle_t * phDevices_vals);
void btx_push_message_lttng_ust_zes_zesDriverEventListenEx_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pNumDeviceEvents_val, size_t _pEvents_vals_length, zes_event_type_flags_t * pEvents_vals);
void btx_push_message_lttng_ust_zes_zesDeviceEnumFabricPorts_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, uint32_t * pCount, zes_fabric_port_handle_t * phPort, uint32_t pCount_val);
void btx_push_message_lttng_ust_zes_zesDeviceEnumFabricPorts_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _phPort_vals_length, zes_fabric_port_handle_t * phPort_vals);
void btx_push_message_lttng_ust_zes_zesFabricPortGetProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_fabric_port_handle_t hPort, zes_fabric_port_properties_t * pProperties);
void btx_push_message_lttng_ust_zes_zesFabricPortGetProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pProperties_val_length, zes_fabric_port_properties_t * pProperties_val);
void btx_push_message_lttng_ust_zes_zesFabricPortGetLinkType_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_fabric_port_handle_t hPort, zes_fabric_link_type_t * pLinkType);
void btx_push_message_lttng_ust_zes_zesFabricPortGetLinkType_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pLinkType_val_length, zes_fabric_link_type_t * pLinkType_val);
void btx_push_message_lttng_ust_zes_zesFabricPortGetConfig_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_fabric_port_handle_t hPort, zes_fabric_port_config_t * pConfig);
void btx_push_message_lttng_ust_zes_zesFabricPortGetConfig_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pConfig_val_length, zes_fabric_port_config_t * pConfig_val);
void btx_push_message_lttng_ust_zes_zesFabricPortSetConfig_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_fabric_port_handle_t hPort, zes_fabric_port_config_t * pConfig, size_t _pConfig_val_length, zes_fabric_port_config_t * pConfig_val);
void btx_push_message_lttng_ust_zes_zesFabricPortSetConfig_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesFabricPortGetState_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_fabric_port_handle_t hPort, zes_fabric_port_state_t * pState);
void btx_push_message_lttng_ust_zes_zesFabricPortGetState_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pState_val_length, zes_fabric_port_state_t * pState_val);
void btx_push_message_lttng_ust_zes_zesFabricPortGetThroughput_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_fabric_port_handle_t hPort, zes_fabric_port_throughput_t * pThroughput);
void btx_push_message_lttng_ust_zes_zesFabricPortGetThroughput_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pThroughput_val_length, zes_fabric_port_throughput_t * pThroughput_val);
void btx_push_message_lttng_ust_zes_zesFabricPortGetFabricErrorCounters_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_fabric_port_handle_t hPort, zes_fabric_port_error_counters_t * pErrors);
void btx_push_message_lttng_ust_zes_zesFabricPortGetFabricErrorCounters_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pErrors_val_length, zes_fabric_port_error_counters_t * pErrors_val);
void btx_push_message_lttng_ust_zes_zesFabricPortGetMultiPortThroughput_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, uint32_t numPorts, zes_fabric_port_handle_t * phPort, zes_fabric_port_throughput_t ** pThroughput, size_t _phPort_vals_length, zes_fabric_port_handle_t * phPort_vals);
void btx_push_message_lttng_ust_zes_zesFabricPortGetMultiPortThroughput_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pThroughput_vals_length, zes_fabric_port_throughput_t * * pThroughput_vals);
void btx_push_message_lttng_ust_zes_zesDeviceEnumFans_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, uint32_t * pCount, zes_fan_handle_t * phFan, uint32_t pCount_val);
void btx_push_message_lttng_ust_zes_zesDeviceEnumFans_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _phFan_vals_length, zes_fan_handle_t * phFan_vals);
void btx_push_message_lttng_ust_zes_zesFanGetProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_fan_handle_t hFan, zes_fan_properties_t * pProperties);
void btx_push_message_lttng_ust_zes_zesFanGetProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pProperties_val_length, zes_fan_properties_t * pProperties_val);
void btx_push_message_lttng_ust_zes_zesFanGetConfig_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_fan_handle_t hFan, zes_fan_config_t * pConfig);
void btx_push_message_lttng_ust_zes_zesFanGetConfig_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pConfig_val_length, zes_fan_config_t * pConfig_val);
void btx_push_message_lttng_ust_zes_zesFanSetDefaultMode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_fan_handle_t hFan);
void btx_push_message_lttng_ust_zes_zesFanSetDefaultMode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesFanSetFixedSpeedMode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_fan_handle_t hFan, zes_fan_speed_t * speed, size_t _speed_val_length, zes_fan_speed_t * speed_val);
void btx_push_message_lttng_ust_zes_zesFanSetFixedSpeedMode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesFanSetSpeedTableMode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_fan_handle_t hFan, zes_fan_speed_table_t * speedTable, size_t _speedTable_val_length, zes_fan_speed_table_t * speedTable_val);
void btx_push_message_lttng_ust_zes_zesFanSetSpeedTableMode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesFanGetState_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_fan_handle_t hFan, zes_fan_speed_units_t units, int32_t * pSpeed);
void btx_push_message_lttng_ust_zes_zesFanGetState_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, int32_t pSpeed_val);
void btx_push_message_lttng_ust_zes_zesDeviceEnumFirmwares_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, uint32_t * pCount, zes_firmware_handle_t * phFirmware, uint32_t pCount_val);
void btx_push_message_lttng_ust_zes_zesDeviceEnumFirmwares_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _phFirmware_vals_length, zes_firmware_handle_t * phFirmware_vals);
void btx_push_message_lttng_ust_zes_zesFirmwareGetProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_firmware_handle_t hFirmware, zes_firmware_properties_t * pProperties);
void btx_push_message_lttng_ust_zes_zesFirmwareGetProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pProperties_val_length, zes_firmware_properties_t * pProperties_val);
void btx_push_message_lttng_ust_zes_zesFirmwareFlash_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_firmware_handle_t hFirmware, void * pImage, uint32_t size);
void btx_push_message_lttng_ust_zes_zesFirmwareFlash_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesFirmwareGetFlashProgress_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_firmware_handle_t hFirmware, uint32_t * pCompletionPercent);
void btx_push_message_lttng_ust_zes_zesFirmwareGetFlashProgress_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCompletionPercent_val);
void btx_push_message_lttng_ust_zes_zesFirmwareGetConsoleLogs_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_firmware_handle_t hFirmware, size_t * pSize, char * pFirmwareLog, size_t pSize_val);
void btx_push_message_lttng_ust_zes_zesFirmwareGetConsoleLogs_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t pSize_val, size_t _pFirmwareLog_vals_length, char * pFirmwareLog_vals);
void btx_push_message_lttng_ust_zes_zesDeviceEnumFrequencyDomains_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, uint32_t * pCount, zes_freq_handle_t * phFrequency, uint32_t pCount_val);
void btx_push_message_lttng_ust_zes_zesDeviceEnumFrequencyDomains_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _phFrequency_vals_length, zes_freq_handle_t * phFrequency_vals);
void btx_push_message_lttng_ust_zes_zesFrequencyGetProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_freq_handle_t hFrequency, zes_freq_properties_t * pProperties);
void btx_push_message_lttng_ust_zes_zesFrequencyGetProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pProperties_val_length, zes_freq_properties_t * pProperties_val);
void btx_push_message_lttng_ust_zes_zesFrequencyGetAvailableClocks_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_freq_handle_t hFrequency, uint32_t * pCount, double * phFrequency, uint32_t pCount_val);
void btx_push_message_lttng_ust_zes_zesFrequencyGetAvailableClocks_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _phFrequency_vals_length, double * phFrequency_vals);
void btx_push_message_lttng_ust_zes_zesFrequencyGetRange_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_freq_handle_t hFrequency, zes_freq_range_t * pLimits);
void btx_push_message_lttng_ust_zes_zesFrequencyGetRange_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pLimits_val_length, zes_freq_range_t * pLimits_val);
void btx_push_message_lttng_ust_zes_zesFrequencySetRange_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_freq_handle_t hFrequency, zes_freq_range_t * pLimits, size_t _pLimits_val_length, zes_freq_range_t * pLimits_val);
void btx_push_message_lttng_ust_zes_zesFrequencySetRange_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesFrequencyGetState_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_freq_handle_t hFrequency, zes_freq_state_t * pState);
void btx_push_message_lttng_ust_zes_zesFrequencyGetState_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pState_val_length, zes_freq_state_t * pState_val);
void btx_push_message_lttng_ust_zes_zesFrequencyGetThrottleTime_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_freq_handle_t hFrequency, zes_freq_throttle_time_t * pThrottleTime);
void btx_push_message_lttng_ust_zes_zesFrequencyGetThrottleTime_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pThrottleTime_val_length, zes_freq_throttle_time_t * pThrottleTime_val);
void btx_push_message_lttng_ust_zes_zesFrequencyOcGetCapabilities_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_freq_handle_t hFrequency, zes_oc_capabilities_t * pOcCapabilities);
void btx_push_message_lttng_ust_zes_zesFrequencyOcGetCapabilities_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pOcCapabilities_val_length, zes_oc_capabilities_t * pOcCapabilities_val);
void btx_push_message_lttng_ust_zes_zesFrequencyOcGetFrequencyTarget_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_freq_handle_t hFrequency, double * pCurrentOcFrequency);
void btx_push_message_lttng_ust_zes_zesFrequencyOcGetFrequencyTarget_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, double pCurrentOcFrequency_val);
void btx_push_message_lttng_ust_zes_zesFrequencyOcSetFrequencyTarget_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_freq_handle_t hFrequency, double CurrentOcFrequency);
void btx_push_message_lttng_ust_zes_zesFrequencyOcSetFrequencyTarget_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesFrequencyOcGetVoltageTarget_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_freq_handle_t hFrequency, double * pCurrentVoltageTarget, double * pCurrentVoltageOffset);
void btx_push_message_lttng_ust_zes_zesFrequencyOcGetVoltageTarget_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, double pCurrentVoltageTarget_val, double pCurrentVoltageOffset_val);
void btx_push_message_lttng_ust_zes_zesFrequencyOcSetVoltageTarget_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_freq_handle_t hFrequency, double CurrentVoltageTarget, double CurrentVoltageOffset);
void btx_push_message_lttng_ust_zes_zesFrequencyOcSetVoltageTarget_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesFrequencyOcSetMode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_freq_handle_t hFrequency, zes_oc_mode_t CurrentOcMode);
void btx_push_message_lttng_ust_zes_zesFrequencyOcSetMode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesFrequencyOcGetMode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_freq_handle_t hFrequency, zes_oc_mode_t * pCurrentOcMode);
void btx_push_message_lttng_ust_zes_zesFrequencyOcGetMode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, zes_oc_mode_t pCurrentOcMode_val);
void btx_push_message_lttng_ust_zes_zesFrequencyOcGetIccMax_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_freq_handle_t hFrequency, double * pOcIccMax);
void btx_push_message_lttng_ust_zes_zesFrequencyOcGetIccMax_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, double pOcIccMax_val);
void btx_push_message_lttng_ust_zes_zesFrequencyOcSetIccMax_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_freq_handle_t hFrequency, double ocIccMax);
void btx_push_message_lttng_ust_zes_zesFrequencyOcSetIccMax_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesFrequencyOcGetTjMax_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_freq_handle_t hFrequency, double * pOcTjMax);
void btx_push_message_lttng_ust_zes_zesFrequencyOcGetTjMax_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, double pOcTjMax_val);
void btx_push_message_lttng_ust_zes_zesFrequencyOcSetTjMax_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_freq_handle_t hFrequency, double ocTjMax);
void btx_push_message_lttng_ust_zes_zesFrequencyOcSetTjMax_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesDeviceEnumLeds_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, uint32_t * pCount, zes_led_handle_t * phLed, uint32_t pCount_val);
void btx_push_message_lttng_ust_zes_zesDeviceEnumLeds_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _phLed_vals_length, zes_led_handle_t * phLed_vals);
void btx_push_message_lttng_ust_zes_zesLedGetProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_led_handle_t hLed, zes_led_properties_t * pProperties);
void btx_push_message_lttng_ust_zes_zesLedGetProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pProperties_val_length, zes_led_properties_t * pProperties_val);
void btx_push_message_lttng_ust_zes_zesLedGetState_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_led_handle_t hLed, zes_led_state_t * pState);
void btx_push_message_lttng_ust_zes_zesLedGetState_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pState_val_length, zes_led_state_t * pState_val);
void btx_push_message_lttng_ust_zes_zesLedSetState_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_led_handle_t hLed, ze_bool_t enable);
void btx_push_message_lttng_ust_zes_zesLedSetState_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesLedSetColor_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_led_handle_t hLed, zes_led_color_t * pColor, size_t _pColor_val_length, zes_led_color_t * pColor_val);
void btx_push_message_lttng_ust_zes_zesLedSetColor_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesDeviceEnumMemoryModules_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, uint32_t * pCount, zes_mem_handle_t * phMemory, uint32_t pCount_val);
void btx_push_message_lttng_ust_zes_zesDeviceEnumMemoryModules_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _phMemory_vals_length, zes_mem_handle_t * phMemory_vals);
void btx_push_message_lttng_ust_zes_zesMemoryGetProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_mem_handle_t hMemory, zes_mem_properties_t * pProperties);
void btx_push_message_lttng_ust_zes_zesMemoryGetProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pProperties_val_length, zes_mem_properties_t * pProperties_val);
void btx_push_message_lttng_ust_zes_zesMemoryGetState_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_mem_handle_t hMemory, zes_mem_state_t * pState);
void btx_push_message_lttng_ust_zes_zesMemoryGetState_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pState_val_length, zes_mem_state_t * pState_val);
void btx_push_message_lttng_ust_zes_zesMemoryGetBandwidth_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_mem_handle_t hMemory, zes_mem_bandwidth_t * pBandwidth);
void btx_push_message_lttng_ust_zes_zesMemoryGetBandwidth_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pBandwidth_val_length, zes_mem_bandwidth_t * pBandwidth_val);
void btx_push_message_lttng_ust_zes_zesDeviceEnumPerformanceFactorDomains_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, uint32_t * pCount, zes_perf_handle_t * phPerf, uint32_t pCount_val);
void btx_push_message_lttng_ust_zes_zesDeviceEnumPerformanceFactorDomains_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _phPerf_vals_length, zes_perf_handle_t * phPerf_vals);
void btx_push_message_lttng_ust_zes_zesPerformanceFactorGetProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_perf_handle_t hPerf, zes_perf_properties_t * pProperties);
void btx_push_message_lttng_ust_zes_zesPerformanceFactorGetProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pProperties_val_length, zes_perf_properties_t * pProperties_val);
void btx_push_message_lttng_ust_zes_zesPerformanceFactorGetConfig_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_perf_handle_t hPerf, double * pFactor);
void btx_push_message_lttng_ust_zes_zesPerformanceFactorGetConfig_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, double pFactor_val);
void btx_push_message_lttng_ust_zes_zesPerformanceFactorSetConfig_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_perf_handle_t hPerf, double factor);
void btx_push_message_lttng_ust_zes_zesPerformanceFactorSetConfig_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesDeviceEnumPowerDomains_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, uint32_t * pCount, zes_pwr_handle_t * phPower, uint32_t pCount_val);
void btx_push_message_lttng_ust_zes_zesDeviceEnumPowerDomains_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _phPower_vals_length, zes_pwr_handle_t * phPower_vals);
void btx_push_message_lttng_ust_zes_zesDeviceGetCardPowerDomain_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, zes_pwr_handle_t * phPower);
void btx_push_message_lttng_ust_zes_zesDeviceGetCardPowerDomain_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, zes_pwr_handle_t phPower_val);
void btx_push_message_lttng_ust_zes_zesPowerGetProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_pwr_handle_t hPower, zes_power_properties_t * pProperties);
void btx_push_message_lttng_ust_zes_zesPowerGetProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pProperties_val_length, zes_power_properties_t * pProperties_val);
void btx_push_message_lttng_ust_zes_zesPowerGetEnergyCounter_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_pwr_handle_t hPower, zes_power_energy_counter_t * pEnergy);
void btx_push_message_lttng_ust_zes_zesPowerGetEnergyCounter_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pEnergy_val_length, zes_power_energy_counter_t * pEnergy_val);
void btx_push_message_lttng_ust_zes_zesPowerGetLimits_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_pwr_handle_t hPower, zes_power_sustained_limit_t * pSustained, zes_power_burst_limit_t * pBurst, zes_power_peak_limit_t * pPeak);
void btx_push_message_lttng_ust_zes_zesPowerGetLimits_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pSustained_val_length, zes_power_sustained_limit_t * pSustained_val, size_t _pBurst_val_length, zes_power_burst_limit_t * pBurst_val, size_t _pPeak_val_length, zes_power_peak_limit_t * pPeak_val);
void btx_push_message_lttng_ust_zes_zesPowerSetLimits_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_pwr_handle_t hPower, zes_power_sustained_limit_t * pSustained, zes_power_burst_limit_t * pBurst, zes_power_peak_limit_t * pPeak, size_t _pSustained_val_length, zes_power_sustained_limit_t * pSustained_val, size_t _pBurst_val_length, zes_power_burst_limit_t * pBurst_val, size_t _pPeak_val_length, zes_power_peak_limit_t * pPeak_val);
void btx_push_message_lttng_ust_zes_zesPowerSetLimits_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesPowerGetEnergyThreshold_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_pwr_handle_t hPower, zes_energy_threshold_t * pThreshold);
void btx_push_message_lttng_ust_zes_zesPowerGetEnergyThreshold_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pThreshold_val_length, zes_energy_threshold_t * pThreshold_val);
void btx_push_message_lttng_ust_zes_zesPowerSetEnergyThreshold_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_pwr_handle_t hPower, double threshold);
void btx_push_message_lttng_ust_zes_zesPowerSetEnergyThreshold_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesDeviceEnumPsus_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, uint32_t * pCount, zes_psu_handle_t * phPsu, uint32_t pCount_val);
void btx_push_message_lttng_ust_zes_zesDeviceEnumPsus_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _phPsu_vals_length, zes_psu_handle_t * phPsu_vals);
void btx_push_message_lttng_ust_zes_zesPsuGetProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_psu_handle_t hPsu, zes_psu_properties_t * pProperties);
void btx_push_message_lttng_ust_zes_zesPsuGetProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pProperties_val_length, zes_psu_properties_t * pProperties_val);
void btx_push_message_lttng_ust_zes_zesPsuGetState_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_psu_handle_t hPsu, zes_psu_state_t * pState);
void btx_push_message_lttng_ust_zes_zesPsuGetState_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pState_val_length, zes_psu_state_t * pState_val);
void btx_push_message_lttng_ust_zes_zesDeviceEnumRasErrorSets_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, uint32_t * pCount, zes_ras_handle_t * phRas, uint32_t pCount_val);
void btx_push_message_lttng_ust_zes_zesDeviceEnumRasErrorSets_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _phRas_vals_length, zes_ras_handle_t * phRas_vals);
void btx_push_message_lttng_ust_zes_zesRasGetProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_ras_handle_t hRas, zes_ras_properties_t * pProperties);
void btx_push_message_lttng_ust_zes_zesRasGetProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pProperties_val_length, zes_ras_properties_t * pProperties_val);
void btx_push_message_lttng_ust_zes_zesRasGetConfig_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_ras_handle_t hRas, zes_ras_config_t * pConfig);
void btx_push_message_lttng_ust_zes_zesRasGetConfig_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pConfig_val_length, zes_ras_config_t * pConfig_val);
void btx_push_message_lttng_ust_zes_zesRasSetConfig_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_ras_handle_t hRas, zes_ras_config_t * pConfig, size_t _pConfig_val_length, zes_ras_config_t * pConfig_val);
void btx_push_message_lttng_ust_zes_zesRasSetConfig_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesRasGetState_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_ras_handle_t hRas, ze_bool_t clear, zes_ras_state_t * pState);
void btx_push_message_lttng_ust_zes_zesRasGetState_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pState_val_length, zes_ras_state_t * pState_val);
void btx_push_message_lttng_ust_zes_zesDeviceEnumSchedulers_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, uint32_t * pCount, zes_sched_handle_t * phScheduler, uint32_t pCount_val);
void btx_push_message_lttng_ust_zes_zesDeviceEnumSchedulers_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _phScheduler_vals_length, zes_sched_handle_t * phScheduler_vals);
void btx_push_message_lttng_ust_zes_zesSchedulerGetProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_sched_handle_t hScheduler, zes_sched_properties_t * pProperties);
void btx_push_message_lttng_ust_zes_zesSchedulerGetProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pProperties_val_length, zes_sched_properties_t * pProperties_val);
void btx_push_message_lttng_ust_zes_zesSchedulerGetCurrentMode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_sched_handle_t hScheduler, zes_sched_mode_t * pMode);
void btx_push_message_lttng_ust_zes_zesSchedulerGetCurrentMode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, zes_sched_mode_t pMode_val);
void btx_push_message_lttng_ust_zes_zesSchedulerGetTimeoutModeProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_sched_handle_t hScheduler, ze_bool_t getDefaults, zes_sched_timeout_properties_t * pConfig);
void btx_push_message_lttng_ust_zes_zesSchedulerGetTimeoutModeProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pConfig_val_length, zes_sched_timeout_properties_t * pConfig_val);
void btx_push_message_lttng_ust_zes_zesSchedulerGetTimesliceModeProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_sched_handle_t hScheduler, ze_bool_t getDefaults, zes_sched_timeslice_properties_t * pConfig);
void btx_push_message_lttng_ust_zes_zesSchedulerGetTimesliceModeProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pConfig_val_length, zes_sched_timeslice_properties_t * pConfig_val);
void btx_push_message_lttng_ust_zes_zesSchedulerSetTimeoutMode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_sched_handle_t hScheduler, zes_sched_timeout_properties_t * pProperties, ze_bool_t * pNeedReload);
void btx_push_message_lttng_ust_zes_zesSchedulerSetTimeoutMode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pProperties_val_length, zes_sched_timeout_properties_t * pProperties_val, ze_bool_t pNeedReload_val);
void btx_push_message_lttng_ust_zes_zesSchedulerSetTimesliceMode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_sched_handle_t hScheduler, zes_sched_timeslice_properties_t * pProperties, ze_bool_t * pNeedReload);
void btx_push_message_lttng_ust_zes_zesSchedulerSetTimesliceMode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pProperties_val_length, zes_sched_timeslice_properties_t * pProperties_val, ze_bool_t pNeedReload_val);
void btx_push_message_lttng_ust_zes_zesSchedulerSetExclusiveMode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_sched_handle_t hScheduler, ze_bool_t * pNeedReload);
void btx_push_message_lttng_ust_zes_zesSchedulerSetExclusiveMode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_bool_t pNeedReload_val);
void btx_push_message_lttng_ust_zes_zesSchedulerSetComputeUnitDebugMode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_sched_handle_t hScheduler, ze_bool_t * pNeedReload);
void btx_push_message_lttng_ust_zes_zesSchedulerSetComputeUnitDebugMode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, ze_bool_t pNeedReload_val);
void btx_push_message_lttng_ust_zes_zesDeviceEnumStandbyDomains_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, uint32_t * pCount, zes_standby_handle_t * phStandby, uint32_t pCount_val);
void btx_push_message_lttng_ust_zes_zesDeviceEnumStandbyDomains_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _phStandby_vals_length, zes_standby_handle_t * phStandby_vals);
void btx_push_message_lttng_ust_zes_zesStandbyGetProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_standby_handle_t hStandby, zes_standby_properties_t * pProperties);
void btx_push_message_lttng_ust_zes_zesStandbyGetProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pProperties_val_length, zes_standby_properties_t * pProperties_val);
void btx_push_message_lttng_ust_zes_zesStandbyGetMode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_standby_handle_t hStandby, zes_standby_promo_mode_t * pMode);
void btx_push_message_lttng_ust_zes_zesStandbyGetMode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, zes_standby_promo_mode_t pMode_val);
void btx_push_message_lttng_ust_zes_zesStandbySetMode_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_standby_handle_t hStandby, zes_standby_promo_mode_t mode);
void btx_push_message_lttng_ust_zes_zesStandbySetMode_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesDeviceEnumTemperatureSensors_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, uint32_t * pCount, zes_temp_handle_t * phTemperature, uint32_t pCount_val);
void btx_push_message_lttng_ust_zes_zesDeviceEnumTemperatureSensors_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _phTemperature_vals_length, zes_temp_handle_t * phTemperature_vals);
void btx_push_message_lttng_ust_zes_zesTemperatureGetProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_temp_handle_t hTemperature, zes_temp_properties_t * pProperties);
void btx_push_message_lttng_ust_zes_zesTemperatureGetProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pProperties_val_length, zes_temp_properties_t * pProperties_val);
void btx_push_message_lttng_ust_zes_zesTemperatureGetConfig_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_temp_handle_t hTemperature, zes_temp_config_t * pConfig);
void btx_push_message_lttng_ust_zes_zesTemperatureGetConfig_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pConfig_val_length, zes_temp_config_t * pConfig_val);
void btx_push_message_lttng_ust_zes_zesTemperatureSetConfig_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_temp_handle_t hTemperature, zes_temp_config_t * pConfig, size_t _pConfig_val_length, zes_temp_config_t * pConfig_val);
void btx_push_message_lttng_ust_zes_zesTemperatureSetConfig_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesTemperatureGetState_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_temp_handle_t hTemperature, double * pTemperature);
void btx_push_message_lttng_ust_zes_zesTemperatureGetState_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, double pTemperature_val);
void btx_push_message_lttng_ust_zes_zesPowerGetLimitsExt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_pwr_handle_t hPower, uint32_t * pCount, zes_power_limit_ext_desc_t * pSustained, uint32_t pCount_val);
void btx_push_message_lttng_ust_zes_zesPowerGetLimitsExt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _pSustained_vals_length, zes_power_limit_ext_desc_t * pSustained_vals);
void btx_push_message_lttng_ust_zes_zesPowerSetLimitsExt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_pwr_handle_t hPower, uint32_t * pCount, zes_power_limit_ext_desc_t * pSustained, uint32_t pCount_val, size_t _pSustained_vals_length, zes_power_limit_ext_desc_t * pSustained_vals);
void btx_push_message_lttng_ust_zes_zesPowerSetLimitsExt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesEngineGetActivityExt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_engine_handle_t hEngine, uint32_t * pCount, zes_engine_stats_t * pStats, uint32_t pCount_val);
void btx_push_message_lttng_ust_zes_zesEngineGetActivityExt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _pStats_vals_length, zes_engine_stats_t * pStats_vals);
void btx_push_message_lttng_ust_zes_zesRasGetStateExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_ras_handle_t hRas, uint32_t * pCount, zes_ras_state_exp_t * pState, uint32_t pCount_val);
void btx_push_message_lttng_ust_zes_zesRasGetStateExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _pState_vals_length, zes_ras_state_exp_t * pState_vals);
void btx_push_message_lttng_ust_zes_zesRasClearStateExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_ras_handle_t hRas, zes_ras_error_category_exp_t category);
void btx_push_message_lttng_ust_zes_zesRasClearStateExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesFirmwareGetSecurityVersionExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_firmware_handle_t hFirmware, char * pVersion);
void btx_push_message_lttng_ust_zes_zesFirmwareGetSecurityVersionExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, char * pVersion_val);
void btx_push_message_lttng_ust_zes_zesFirmwareSetSecurityVersionExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_firmware_handle_t hFirmware);
void btx_push_message_lttng_ust_zes_zesFirmwareSetSecurityVersionExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesDeviceGetSubDevicePropertiesExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, uint32_t * pCount, zes_subdevice_exp_properties_t * pSubdeviceProps, uint32_t pCount_val);
void btx_push_message_lttng_ust_zes_zesDeviceGetSubDevicePropertiesExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _pSubdeviceProps_vals_length, zes_subdevice_exp_properties_t * pSubdeviceProps_vals);
void btx_push_message_lttng_ust_zes_zesDriverGetDeviceByUuidExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_driver_handle_t hDriver, zes_uuid_t uuid, zes_device_handle_t * phDevice, ze_bool_t * onSubdevice, uint32_t * subdeviceId);
void btx_push_message_lttng_ust_zes_zesDriverGetDeviceByUuidExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, zes_device_handle_t phDevice_val, ze_bool_t onSubdevice_val, uint32_t subdeviceId_val);
void btx_push_message_lttng_ust_zes_zesDeviceEnumActiveVFExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, uint32_t * pCount, zes_vf_handle_t * phVFhandle, uint32_t pCount_val);
void btx_push_message_lttng_ust_zes_zesDeviceEnumActiveVFExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _phVFhandle_vals_length, zes_vf_handle_t * phVFhandle_vals);
void btx_push_message_lttng_ust_zes_zesVFManagementGetVFPropertiesExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_vf_handle_t hVFhandle, zes_vf_exp_properties_t * pProperties);
void btx_push_message_lttng_ust_zes_zesVFManagementGetVFPropertiesExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t _pProperties_val_length, zes_vf_exp_properties_t * pProperties_val);
void btx_push_message_lttng_ust_zes_zesVFManagementGetVFMemoryUtilizationExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_vf_handle_t hVFhandle, uint32_t * pCount, zes_vf_util_mem_exp_t * pMemUtil, uint32_t pCount_val);
void btx_push_message_lttng_ust_zes_zesVFManagementGetVFMemoryUtilizationExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _pMemUtil_vals_length, zes_vf_util_mem_exp_t * pMemUtil_vals);
void btx_push_message_lttng_ust_zes_zesVFManagementGetVFEngineUtilizationExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_vf_handle_t hVFhandle, uint32_t * pCount, zes_vf_util_engine_exp_t * pEngineUtil, uint32_t pCount_val);
void btx_push_message_lttng_ust_zes_zesVFManagementGetVFEngineUtilizationExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t pCount_val, size_t _pEngineUtil_vals_length, zes_vf_util_engine_exp_t * pEngineUtil_vals);
void btx_push_message_lttng_ust_zes_zesVFManagementSetVFTelemetryModeExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_vf_handle_t hVFhandle, zes_vf_info_util_exp_flags_t flags, ze_bool_t enable);
void btx_push_message_lttng_ust_zes_zesVFManagementSetVFTelemetryModeExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesVFManagementSetVFTelemetrySamplingIntervalExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_vf_handle_t hVFhandle, zes_vf_info_util_exp_flags_t flag, uint64_t samplingInterval);
void btx_push_message_lttng_ust_zes_zesVFManagementSetVFTelemetrySamplingIntervalExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesDeviceEnumEnabledVFExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, uint32_t * pCount, zes_vf_handle_t * phVFhandle);
void btx_push_message_lttng_ust_zes_zesDeviceEnumEnabledVFExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesVFManagementGetVFCapabilitiesExp_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_vf_handle_t hVFhandle, zes_vf_exp_capabilities_t * pCapability);
void btx_push_message_lttng_ust_zes_zesVFManagementGetVFCapabilitiesExp_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesVFManagementGetVFMemoryUtilizationExp2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_vf_handle_t hVFhandle, uint32_t * pCount, zes_vf_util_mem_exp2_t * pMemUtil);
void btx_push_message_lttng_ust_zes_zesVFManagementGetVFMemoryUtilizationExp2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesVFManagementGetVFEngineUtilizationExp2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_vf_handle_t hVFhandle, uint32_t * pCount, zes_vf_util_engine_exp2_t * pEngineUtil);
void btx_push_message_lttng_ust_zes_zesVFManagementGetVFEngineUtilizationExp2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesVFManagementGetVFCapabilitiesExp2_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_vf_handle_t hVFhandle, zes_vf_exp2_capabilities_t * pCapability);
void btx_push_message_lttng_ust_zes_zesVFManagementGetVFCapabilitiesExp2_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesGetGlobalProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zes_global_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zes_zesGetGlobalProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesGetDeviceProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zes_device_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zes_zesGetDeviceProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesGetDeviceExpProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zes_device_exp_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zes_zesGetDeviceExpProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesGetDriverProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zes_driver_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zes_zesGetDriverProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesGetDriverExpProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zes_driver_exp_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zes_zesGetDriverExpProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesGetOverclockProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zes_overclock_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zes_zesGetOverclockProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesGetSchedulerProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zes_scheduler_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zes_zesGetSchedulerProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesGetPerformanceFactorProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zes_performance_factor_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zes_zesGetPerformanceFactorProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesGetPowerProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zes_power_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zes_zesGetPowerProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesGetFrequencyProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zes_frequency_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zes_zesGetFrequencyProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesGetEngineProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zes_engine_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zes_zesGetEngineProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesGetStandbyProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zes_standby_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zes_zesGetStandbyProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesGetFirmwareProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zes_firmware_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zes_zesGetFirmwareProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesGetFirmwareExpProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zes_firmware_exp_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zes_zesGetFirmwareExpProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesGetMemoryProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zes_memory_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zes_zesGetMemoryProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesGetFabricPortProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zes_fabric_port_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zes_zesGetFabricPortProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesGetTemperatureProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zes_temperature_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zes_zesGetTemperatureProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesGetPsuProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zes_psu_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zes_zesGetPsuProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesGetFanProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zes_fan_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zes_zesGetFanProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesGetLedProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zes_led_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zes_zesGetLedProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesGetRasProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zes_ras_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zes_zesGetRasProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesGetRasExpProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zes_ras_exp_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zes_zesGetRasExpProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesGetDiagnosticsProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zes_diagnostics_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zes_zesGetDiagnosticsProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zes_zesGetVFManagementExpProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zes_vf_management_exp_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zes_zesGetVFManagementExpProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_desc_t * desc, zel_tracer_handle_t * phTracer, size_t _desc_val_length, zel_tracer_desc_t * desc_val);
void btx_push_message_lttng_ust_zel_zelTracerCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerDestroy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer);
void btx_push_message_lttng_ust_zel_zelTracerDestroy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerSetPrologues_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_core_callbacks_t * pCoreCbs);
void btx_push_message_lttng_ust_zel_zelTracerSetPrologues_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerSetEpilogues_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_core_callbacks_t * pCoreCbs);
void btx_push_message_lttng_ust_zel_zelTracerSetEpilogues_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerSetEnabled_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, ze_bool_t enable);
void btx_push_message_lttng_ust_zel_zelTracerSetEnabled_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelGetTracerApiProcAddrTable_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_api_version_t version, zel_tracer_dditable_t * pDdiTable);
void btx_push_message_lttng_ust_zel_zelGetTracerApiProcAddrTable_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerInitRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnInitCb_t pfnInitCb);
void btx_push_message_lttng_ust_zel_zelTracerInitRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerDriverGetRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnDriverGetCb_t pfnGetCb);
void btx_push_message_lttng_ust_zel_zelTracerDriverGetRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerInitDriversRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnInitDriversCb_t pfnInitDriversCb);
void btx_push_message_lttng_ust_zel_zelTracerInitDriversRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerDriverGetApiVersionRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnDriverGetApiVersionCb_t pfnGetApiVersionCb);
void btx_push_message_lttng_ust_zel_zelTracerDriverGetApiVersionRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerDriverGetPropertiesRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnDriverGetPropertiesCb_t pfnGetPropertiesCb);
void btx_push_message_lttng_ust_zel_zelTracerDriverGetPropertiesRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerDriverGetIpcPropertiesRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnDriverGetIpcPropertiesCb_t pfnGetIpcPropertiesCb);
void btx_push_message_lttng_ust_zel_zelTracerDriverGetIpcPropertiesRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerDriverGetExtensionPropertiesRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnDriverGetExtensionPropertiesCb_t pfnGetExtensionPropertiesCb);
void btx_push_message_lttng_ust_zel_zelTracerDriverGetExtensionPropertiesRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerDriverGetExtensionFunctionAddressRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnDriverGetExtensionFunctionAddressCb_t pfnGetExtensionFunctionAddressCb);
void btx_push_message_lttng_ust_zel_zelTracerDriverGetExtensionFunctionAddressRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerDriverGetLastErrorDescriptionRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnDriverGetLastErrorDescriptionCb_t pfnGetLastErrorDescriptionCb);
void btx_push_message_lttng_ust_zel_zelTracerDriverGetLastErrorDescriptionRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerDeviceGetRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnDeviceGetCb_t pfnGetCb);
void btx_push_message_lttng_ust_zel_zelTracerDeviceGetRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerDeviceGetRootDeviceRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnDeviceGetRootDeviceCb_t pfnGetRootDeviceCb);
void btx_push_message_lttng_ust_zel_zelTracerDeviceGetRootDeviceRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerDeviceGetSubDevicesRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnDeviceGetSubDevicesCb_t pfnGetSubDevicesCb);
void btx_push_message_lttng_ust_zel_zelTracerDeviceGetSubDevicesRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerDeviceGetPropertiesRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnDeviceGetPropertiesCb_t pfnGetPropertiesCb);
void btx_push_message_lttng_ust_zel_zelTracerDeviceGetPropertiesRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerDeviceGetComputePropertiesRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnDeviceGetComputePropertiesCb_t pfnGetComputePropertiesCb);
void btx_push_message_lttng_ust_zel_zelTracerDeviceGetComputePropertiesRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerDeviceGetModulePropertiesRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnDeviceGetModulePropertiesCb_t pfnGetModulePropertiesCb);
void btx_push_message_lttng_ust_zel_zelTracerDeviceGetModulePropertiesRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerDeviceGetCommandQueueGroupPropertiesRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnDeviceGetCommandQueueGroupPropertiesCb_t pfnGetCommandQueueGroupPropertiesCb);
void btx_push_message_lttng_ust_zel_zelTracerDeviceGetCommandQueueGroupPropertiesRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerDeviceGetMemoryPropertiesRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnDeviceGetMemoryPropertiesCb_t pfnGetMemoryPropertiesCb);
void btx_push_message_lttng_ust_zel_zelTracerDeviceGetMemoryPropertiesRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerDeviceGetMemoryAccessPropertiesRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnDeviceGetMemoryAccessPropertiesCb_t pfnGetMemoryAccessPropertiesCb);
void btx_push_message_lttng_ust_zel_zelTracerDeviceGetMemoryAccessPropertiesRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerDeviceGetCachePropertiesRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnDeviceGetCachePropertiesCb_t pfnGetCachePropertiesCb);
void btx_push_message_lttng_ust_zel_zelTracerDeviceGetCachePropertiesRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerDeviceGetImagePropertiesRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnDeviceGetImagePropertiesCb_t pfnGetImagePropertiesCb);
void btx_push_message_lttng_ust_zel_zelTracerDeviceGetImagePropertiesRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerDeviceGetExternalMemoryPropertiesRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnDeviceGetExternalMemoryPropertiesCb_t pfnGetExternalMemoryPropertiesCb);
void btx_push_message_lttng_ust_zel_zelTracerDeviceGetExternalMemoryPropertiesRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerDeviceGetP2PPropertiesRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnDeviceGetP2PPropertiesCb_t pfnGetP2PPropertiesCb);
void btx_push_message_lttng_ust_zel_zelTracerDeviceGetP2PPropertiesRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerDeviceCanAccessPeerRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnDeviceCanAccessPeerCb_t pfnCanAccessPeerCb);
void btx_push_message_lttng_ust_zel_zelTracerDeviceCanAccessPeerRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerDeviceGetStatusRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnDeviceGetStatusCb_t pfnGetStatusCb);
void btx_push_message_lttng_ust_zel_zelTracerDeviceGetStatusRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerDeviceGetGlobalTimestampsRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnDeviceGetGlobalTimestampsCb_t pfnGetGlobalTimestampsCb);
void btx_push_message_lttng_ust_zel_zelTracerDeviceGetGlobalTimestampsRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerContextCreateRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnContextCreateCb_t pfnCreateCb);
void btx_push_message_lttng_ust_zel_zelTracerContextCreateRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerContextCreateExRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnContextCreateExCb_t pfnCreateExCb);
void btx_push_message_lttng_ust_zel_zelTracerContextCreateExRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerContextDestroyRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnContextDestroyCb_t pfnDestroyCb);
void btx_push_message_lttng_ust_zel_zelTracerContextDestroyRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerContextGetStatusRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnContextGetStatusCb_t pfnGetStatusCb);
void btx_push_message_lttng_ust_zel_zelTracerContextGetStatusRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandQueueCreateRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandQueueCreateCb_t pfnCreateCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandQueueCreateRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandQueueDestroyRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandQueueDestroyCb_t pfnDestroyCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandQueueDestroyRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandQueueExecuteCommandListsRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandQueueExecuteCommandListsCb_t pfnExecuteCommandListsCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandQueueExecuteCommandListsRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandQueueSynchronizeRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandQueueSynchronizeCb_t pfnSynchronizeCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandQueueSynchronizeRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandQueueGetOrdinalRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandQueueGetOrdinalCb_t pfnGetOrdinalCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandQueueGetOrdinalRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandQueueGetIndexRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandQueueGetIndexCb_t pfnGetIndexCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandQueueGetIndexRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListCreateRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListCreateCb_t pfnCreateCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListCreateRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListCreateImmediateRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListCreateImmediateCb_t pfnCreateImmediateCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListCreateImmediateRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListDestroyRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListDestroyCb_t pfnDestroyCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListDestroyRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListCloseRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListCloseCb_t pfnCloseCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListCloseRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListResetRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListResetCb_t pfnResetCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListResetRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendWriteGlobalTimestampRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListAppendWriteGlobalTimestampCb_t pfnAppendWriteGlobalTimestampCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendWriteGlobalTimestampRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListHostSynchronizeRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListHostSynchronizeCb_t pfnHostSynchronizeCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListHostSynchronizeRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListGetDeviceHandleRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListGetDeviceHandleCb_t pfnGetDeviceHandleCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListGetDeviceHandleRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListGetContextHandleRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListGetContextHandleCb_t pfnGetContextHandleCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListGetContextHandleRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListGetOrdinalRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListGetOrdinalCb_t pfnGetOrdinalCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListGetOrdinalRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListImmediateGetIndexRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListImmediateGetIndexCb_t pfnImmediateGetIndexCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListImmediateGetIndexRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListIsImmediateRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListIsImmediateCb_t pfnIsImmediateCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListIsImmediateRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendBarrierRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListAppendBarrierCb_t pfnAppendBarrierCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendBarrierRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendMemoryRangesBarrierRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListAppendMemoryRangesBarrierCb_t pfnAppendMemoryRangesBarrierCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendMemoryRangesBarrierRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerContextSystemBarrierRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnContextSystemBarrierCb_t pfnSystemBarrierCb);
void btx_push_message_lttng_ust_zel_zelTracerContextSystemBarrierRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendMemoryCopyRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListAppendMemoryCopyCb_t pfnAppendMemoryCopyCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendMemoryCopyRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendMemoryFillRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListAppendMemoryFillCb_t pfnAppendMemoryFillCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendMemoryFillRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendMemoryCopyRegionRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListAppendMemoryCopyRegionCb_t pfnAppendMemoryCopyRegionCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendMemoryCopyRegionRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendMemoryCopyFromContextRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListAppendMemoryCopyFromContextCb_t pfnAppendMemoryCopyFromContextCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendMemoryCopyFromContextRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendImageCopyRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListAppendImageCopyCb_t pfnAppendImageCopyCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendImageCopyRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendImageCopyRegionRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListAppendImageCopyRegionCb_t pfnAppendImageCopyRegionCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendImageCopyRegionRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendImageCopyToMemoryRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListAppendImageCopyToMemoryCb_t pfnAppendImageCopyToMemoryCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendImageCopyToMemoryRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendImageCopyFromMemoryRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListAppendImageCopyFromMemoryCb_t pfnAppendImageCopyFromMemoryCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendImageCopyFromMemoryRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendMemoryPrefetchRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListAppendMemoryPrefetchCb_t pfnAppendMemoryPrefetchCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendMemoryPrefetchRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendMemAdviseRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListAppendMemAdviseCb_t pfnAppendMemAdviseCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendMemAdviseRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerEventPoolCreateRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnEventPoolCreateCb_t pfnCreateCb);
void btx_push_message_lttng_ust_zel_zelTracerEventPoolCreateRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerEventPoolDestroyRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnEventPoolDestroyCb_t pfnDestroyCb);
void btx_push_message_lttng_ust_zel_zelTracerEventPoolDestroyRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerEventCreateRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnEventCreateCb_t pfnCreateCb);
void btx_push_message_lttng_ust_zel_zelTracerEventCreateRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerEventDestroyRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnEventDestroyCb_t pfnDestroyCb);
void btx_push_message_lttng_ust_zel_zelTracerEventDestroyRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerEventPoolGetIpcHandleRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnEventPoolGetIpcHandleCb_t pfnGetIpcHandleCb);
void btx_push_message_lttng_ust_zel_zelTracerEventPoolGetIpcHandleRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerEventPoolPutIpcHandleRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnEventPoolPutIpcHandleCb_t pfnPutIpcHandleCb);
void btx_push_message_lttng_ust_zel_zelTracerEventPoolPutIpcHandleRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerEventPoolOpenIpcHandleRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnEventPoolOpenIpcHandleCb_t pfnOpenIpcHandleCb);
void btx_push_message_lttng_ust_zel_zelTracerEventPoolOpenIpcHandleRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerEventPoolCloseIpcHandleRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnEventPoolCloseIpcHandleCb_t pfnCloseIpcHandleCb);
void btx_push_message_lttng_ust_zel_zelTracerEventPoolCloseIpcHandleRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendSignalEventRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListAppendSignalEventCb_t pfnAppendSignalEventCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendSignalEventRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendWaitOnEventsRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListAppendWaitOnEventsCb_t pfnAppendWaitOnEventsCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendWaitOnEventsRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerEventHostSignalRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnEventHostSignalCb_t pfnHostSignalCb);
void btx_push_message_lttng_ust_zel_zelTracerEventHostSignalRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerEventHostSynchronizeRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnEventHostSynchronizeCb_t pfnHostSynchronizeCb);
void btx_push_message_lttng_ust_zel_zelTracerEventHostSynchronizeRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerEventQueryStatusRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnEventQueryStatusCb_t pfnQueryStatusCb);
void btx_push_message_lttng_ust_zel_zelTracerEventQueryStatusRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendEventResetRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListAppendEventResetCb_t pfnAppendEventResetCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendEventResetRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerEventHostResetRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnEventHostResetCb_t pfnHostResetCb);
void btx_push_message_lttng_ust_zel_zelTracerEventHostResetRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerEventQueryKernelTimestampRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnEventQueryKernelTimestampCb_t pfnQueryKernelTimestampCb);
void btx_push_message_lttng_ust_zel_zelTracerEventQueryKernelTimestampRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendQueryKernelTimestampsRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListAppendQueryKernelTimestampsCb_t pfnAppendQueryKernelTimestampsCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendQueryKernelTimestampsRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerEventGetEventPoolRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnEventGetEventPoolCb_t pfnGetEventPoolCb);
void btx_push_message_lttng_ust_zel_zelTracerEventGetEventPoolRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerEventGetSignalScopeRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnEventGetSignalScopeCb_t pfnGetSignalScopeCb);
void btx_push_message_lttng_ust_zel_zelTracerEventGetSignalScopeRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerEventGetWaitScopeRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnEventGetWaitScopeCb_t pfnGetWaitScopeCb);
void btx_push_message_lttng_ust_zel_zelTracerEventGetWaitScopeRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerEventPoolGetContextHandleRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnEventPoolGetContextHandleCb_t pfnGetContextHandleCb);
void btx_push_message_lttng_ust_zel_zelTracerEventPoolGetContextHandleRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerEventPoolGetFlagsRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnEventPoolGetFlagsCb_t pfnGetFlagsCb);
void btx_push_message_lttng_ust_zel_zelTracerEventPoolGetFlagsRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerFenceCreateRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnFenceCreateCb_t pfnCreateCb);
void btx_push_message_lttng_ust_zel_zelTracerFenceCreateRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerFenceDestroyRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnFenceDestroyCb_t pfnDestroyCb);
void btx_push_message_lttng_ust_zel_zelTracerFenceDestroyRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerFenceHostSynchronizeRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnFenceHostSynchronizeCb_t pfnHostSynchronizeCb);
void btx_push_message_lttng_ust_zel_zelTracerFenceHostSynchronizeRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerFenceQueryStatusRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnFenceQueryStatusCb_t pfnQueryStatusCb);
void btx_push_message_lttng_ust_zel_zelTracerFenceQueryStatusRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerFenceResetRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnFenceResetCb_t pfnResetCb);
void btx_push_message_lttng_ust_zel_zelTracerFenceResetRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerImageGetPropertiesRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnImageGetPropertiesCb_t pfnGetPropertiesCb);
void btx_push_message_lttng_ust_zel_zelTracerImageGetPropertiesRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerImageCreateRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnImageCreateCb_t pfnCreateCb);
void btx_push_message_lttng_ust_zel_zelTracerImageCreateRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerImageDestroyRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnImageDestroyCb_t pfnDestroyCb);
void btx_push_message_lttng_ust_zel_zelTracerImageDestroyRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerMemAllocSharedRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnMemAllocSharedCb_t pfnAllocSharedCb);
void btx_push_message_lttng_ust_zel_zelTracerMemAllocSharedRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerMemAllocDeviceRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnMemAllocDeviceCb_t pfnAllocDeviceCb);
void btx_push_message_lttng_ust_zel_zelTracerMemAllocDeviceRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerMemAllocHostRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnMemAllocHostCb_t pfnAllocHostCb);
void btx_push_message_lttng_ust_zel_zelTracerMemAllocHostRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerMemFreeRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnMemFreeCb_t pfnFreeCb);
void btx_push_message_lttng_ust_zel_zelTracerMemFreeRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerMemGetAllocPropertiesRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnMemGetAllocPropertiesCb_t pfnGetAllocPropertiesCb);
void btx_push_message_lttng_ust_zel_zelTracerMemGetAllocPropertiesRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerMemGetAddressRangeRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnMemGetAddressRangeCb_t pfnGetAddressRangeCb);
void btx_push_message_lttng_ust_zel_zelTracerMemGetAddressRangeRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerMemGetIpcHandleRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnMemGetIpcHandleCb_t pfnGetIpcHandleCb);
void btx_push_message_lttng_ust_zel_zelTracerMemGetIpcHandleRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerMemGetIpcHandleFromFileDescriptorExpRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnMemGetIpcHandleFromFileDescriptorExpCb_t pfnGetIpcHandleFromFileDescriptorExpCb);
void btx_push_message_lttng_ust_zel_zelTracerMemGetIpcHandleFromFileDescriptorExpRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerMemGetFileDescriptorFromIpcHandleExpRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnMemGetFileDescriptorFromIpcHandleExpCb_t pfnGetFileDescriptorFromIpcHandleExpCb);
void btx_push_message_lttng_ust_zel_zelTracerMemGetFileDescriptorFromIpcHandleExpRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerMemPutIpcHandleRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnMemPutIpcHandleCb_t pfnPutIpcHandleCb);
void btx_push_message_lttng_ust_zel_zelTracerMemPutIpcHandleRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerMemOpenIpcHandleRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnMemOpenIpcHandleCb_t pfnOpenIpcHandleCb);
void btx_push_message_lttng_ust_zel_zelTracerMemOpenIpcHandleRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerMemCloseIpcHandleRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnMemCloseIpcHandleCb_t pfnCloseIpcHandleCb);
void btx_push_message_lttng_ust_zel_zelTracerMemCloseIpcHandleRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerMemSetAtomicAccessAttributeExpRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnMemSetAtomicAccessAttributeExpCb_t pfnSetAtomicAccessAttributeExpCb);
void btx_push_message_lttng_ust_zel_zelTracerMemSetAtomicAccessAttributeExpRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerMemGetAtomicAccessAttributeExpRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnMemGetAtomicAccessAttributeExpCb_t pfnGetAtomicAccessAttributeExpCb);
void btx_push_message_lttng_ust_zel_zelTracerMemGetAtomicAccessAttributeExpRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerModuleCreateRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnModuleCreateCb_t pfnCreateCb);
void btx_push_message_lttng_ust_zel_zelTracerModuleCreateRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerModuleDestroyRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnModuleDestroyCb_t pfnDestroyCb);
void btx_push_message_lttng_ust_zel_zelTracerModuleDestroyRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerModuleDynamicLinkRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnModuleDynamicLinkCb_t pfnDynamicLinkCb);
void btx_push_message_lttng_ust_zel_zelTracerModuleDynamicLinkRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerModuleBuildLogDestroyRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnModuleBuildLogDestroyCb_t pfnDestroyCb);
void btx_push_message_lttng_ust_zel_zelTracerModuleBuildLogDestroyRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerModuleBuildLogGetStringRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnModuleBuildLogGetStringCb_t pfnGetStringCb);
void btx_push_message_lttng_ust_zel_zelTracerModuleBuildLogGetStringRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerModuleGetNativeBinaryRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnModuleGetNativeBinaryCb_t pfnGetNativeBinaryCb);
void btx_push_message_lttng_ust_zel_zelTracerModuleGetNativeBinaryRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerModuleGetGlobalPointerRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnModuleGetGlobalPointerCb_t pfnGetGlobalPointerCb);
void btx_push_message_lttng_ust_zel_zelTracerModuleGetGlobalPointerRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerModuleGetKernelNamesRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnModuleGetKernelNamesCb_t pfnGetKernelNamesCb);
void btx_push_message_lttng_ust_zel_zelTracerModuleGetKernelNamesRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerModuleGetPropertiesRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnModuleGetPropertiesCb_t pfnGetPropertiesCb);
void btx_push_message_lttng_ust_zel_zelTracerModuleGetPropertiesRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerKernelCreateRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnKernelCreateCb_t pfnCreateCb);
void btx_push_message_lttng_ust_zel_zelTracerKernelCreateRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerKernelDestroyRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnKernelDestroyCb_t pfnDestroyCb);
void btx_push_message_lttng_ust_zel_zelTracerKernelDestroyRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerModuleGetFunctionPointerRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnModuleGetFunctionPointerCb_t pfnGetFunctionPointerCb);
void btx_push_message_lttng_ust_zel_zelTracerModuleGetFunctionPointerRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerKernelSetGroupSizeRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnKernelSetGroupSizeCb_t pfnSetGroupSizeCb);
void btx_push_message_lttng_ust_zel_zelTracerKernelSetGroupSizeRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerKernelSuggestGroupSizeRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnKernelSuggestGroupSizeCb_t pfnSuggestGroupSizeCb);
void btx_push_message_lttng_ust_zel_zelTracerKernelSuggestGroupSizeRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerKernelSuggestMaxCooperativeGroupCountRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnKernelSuggestMaxCooperativeGroupCountCb_t pfnSuggestMaxCooperativeGroupCountCb);
void btx_push_message_lttng_ust_zel_zelTracerKernelSuggestMaxCooperativeGroupCountRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerKernelSetArgumentValueRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnKernelSetArgumentValueCb_t pfnSetArgumentValueCb);
void btx_push_message_lttng_ust_zel_zelTracerKernelSetArgumentValueRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerKernelSetIndirectAccessRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnKernelSetIndirectAccessCb_t pfnSetIndirectAccessCb);
void btx_push_message_lttng_ust_zel_zelTracerKernelSetIndirectAccessRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerKernelGetIndirectAccessRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnKernelGetIndirectAccessCb_t pfnGetIndirectAccessCb);
void btx_push_message_lttng_ust_zel_zelTracerKernelGetIndirectAccessRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerKernelGetSourceAttributesRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnKernelGetSourceAttributesCb_t pfnGetSourceAttributesCb);
void btx_push_message_lttng_ust_zel_zelTracerKernelGetSourceAttributesRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerKernelSetCacheConfigRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnKernelSetCacheConfigCb_t pfnSetCacheConfigCb);
void btx_push_message_lttng_ust_zel_zelTracerKernelSetCacheConfigRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerKernelGetPropertiesRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnKernelGetPropertiesCb_t pfnGetPropertiesCb);
void btx_push_message_lttng_ust_zel_zelTracerKernelGetPropertiesRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerKernelGetNameRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnKernelGetNameCb_t pfnGetNameCb);
void btx_push_message_lttng_ust_zel_zelTracerKernelGetNameRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendLaunchKernelRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListAppendLaunchKernelCb_t pfnAppendLaunchKernelCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendLaunchKernelRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendLaunchCooperativeKernelRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListAppendLaunchCooperativeKernelCb_t pfnAppendLaunchCooperativeKernelCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendLaunchCooperativeKernelRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendLaunchKernelIndirectRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListAppendLaunchKernelIndirectCb_t pfnAppendLaunchKernelIndirectCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendLaunchKernelIndirectRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendLaunchMultipleKernelsIndirectRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListAppendLaunchMultipleKernelsIndirectCb_t pfnAppendLaunchMultipleKernelsIndirectCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendLaunchMultipleKernelsIndirectRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerContextMakeMemoryResidentRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnContextMakeMemoryResidentCb_t pfnMakeMemoryResidentCb);
void btx_push_message_lttng_ust_zel_zelTracerContextMakeMemoryResidentRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerContextEvictMemoryRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnContextEvictMemoryCb_t pfnEvictMemoryCb);
void btx_push_message_lttng_ust_zel_zelTracerContextEvictMemoryRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerContextMakeImageResidentRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnContextMakeImageResidentCb_t pfnMakeImageResidentCb);
void btx_push_message_lttng_ust_zel_zelTracerContextMakeImageResidentRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerContextEvictImageRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnContextEvictImageCb_t pfnEvictImageCb);
void btx_push_message_lttng_ust_zel_zelTracerContextEvictImageRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerSamplerCreateRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnSamplerCreateCb_t pfnCreateCb);
void btx_push_message_lttng_ust_zel_zelTracerSamplerCreateRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerSamplerDestroyRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnSamplerDestroyCb_t pfnDestroyCb);
void btx_push_message_lttng_ust_zel_zelTracerSamplerDestroyRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerVirtualMemReserveRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnVirtualMemReserveCb_t pfnReserveCb);
void btx_push_message_lttng_ust_zel_zelTracerVirtualMemReserveRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerVirtualMemFreeRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnVirtualMemFreeCb_t pfnFreeCb);
void btx_push_message_lttng_ust_zel_zelTracerVirtualMemFreeRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerVirtualMemQueryPageSizeRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnVirtualMemQueryPageSizeCb_t pfnQueryPageSizeCb);
void btx_push_message_lttng_ust_zel_zelTracerVirtualMemQueryPageSizeRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerPhysicalMemCreateRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnPhysicalMemCreateCb_t pfnCreateCb);
void btx_push_message_lttng_ust_zel_zelTracerPhysicalMemCreateRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerPhysicalMemDestroyRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnPhysicalMemDestroyCb_t pfnDestroyCb);
void btx_push_message_lttng_ust_zel_zelTracerPhysicalMemDestroyRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerVirtualMemMapRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnVirtualMemMapCb_t pfnMapCb);
void btx_push_message_lttng_ust_zel_zelTracerVirtualMemMapRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerVirtualMemUnmapRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnVirtualMemUnmapCb_t pfnUnmapCb);
void btx_push_message_lttng_ust_zel_zelTracerVirtualMemUnmapRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerVirtualMemSetAccessAttributeRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnVirtualMemSetAccessAttributeCb_t pfnSetAccessAttributeCb);
void btx_push_message_lttng_ust_zel_zelTracerVirtualMemSetAccessAttributeRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerVirtualMemGetAccessAttributeRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnVirtualMemGetAccessAttributeCb_t pfnGetAccessAttributeCb);
void btx_push_message_lttng_ust_zel_zelTracerVirtualMemGetAccessAttributeRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerKernelSetGlobalOffsetExpRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnKernelSetGlobalOffsetExpCb_t pfnSetGlobalOffsetExpCb);
void btx_push_message_lttng_ust_zel_zelTracerKernelSetGlobalOffsetExpRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerKernelGetBinaryExpRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnKernelGetBinaryExpCb_t pfnGetBinaryExpCb);
void btx_push_message_lttng_ust_zel_zelTracerKernelGetBinaryExpRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerDeviceImportExternalSemaphoreExtRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnDeviceImportExternalSemaphoreExtCb_t pfnImportExternalSemaphoreExtCb);
void btx_push_message_lttng_ust_zel_zelTracerDeviceImportExternalSemaphoreExtRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerDeviceReleaseExternalSemaphoreExtRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnDeviceReleaseExternalSemaphoreExtCb_t pfnReleaseExternalSemaphoreExtCb);
void btx_push_message_lttng_ust_zel_zelTracerDeviceReleaseExternalSemaphoreExtRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendSignalExternalSemaphoreExtRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListAppendSignalExternalSemaphoreExtCb_t pfnAppendSignalExternalSemaphoreExtCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendSignalExternalSemaphoreExtRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendWaitExternalSemaphoreExtRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListAppendWaitExternalSemaphoreExtCb_t pfnAppendWaitExternalSemaphoreExtCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendWaitExternalSemaphoreExtRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerRTASBuilderCreateExtRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnRTASBuilderCreateExtCb_t pfnCreateExtCb);
void btx_push_message_lttng_ust_zel_zelTracerRTASBuilderCreateExtRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerRTASBuilderGetBuildPropertiesExtRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnRTASBuilderGetBuildPropertiesExtCb_t pfnGetBuildPropertiesExtCb);
void btx_push_message_lttng_ust_zel_zelTracerRTASBuilderGetBuildPropertiesExtRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerDriverRTASFormatCompatibilityCheckExtRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnDriverRTASFormatCompatibilityCheckExtCb_t pfnRTASFormatCompatibilityCheckExtCb);
void btx_push_message_lttng_ust_zel_zelTracerDriverRTASFormatCompatibilityCheckExtRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerRTASBuilderBuildExtRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnRTASBuilderBuildExtCb_t pfnBuildExtCb);
void btx_push_message_lttng_ust_zel_zelTracerRTASBuilderBuildExtRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerRTASBuilderCommandListAppendCopyExtRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnRTASBuilderCommandListAppendCopyExtCb_t pfnCommandListAppendCopyExtCb);
void btx_push_message_lttng_ust_zel_zelTracerRTASBuilderCommandListAppendCopyExtRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerRTASBuilderDestroyExtRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnRTASBuilderDestroyExtCb_t pfnDestroyExtCb);
void btx_push_message_lttng_ust_zel_zelTracerRTASBuilderDestroyExtRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerRTASParallelOperationCreateExtRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnRTASParallelOperationCreateExtCb_t pfnCreateExtCb);
void btx_push_message_lttng_ust_zel_zelTracerRTASParallelOperationCreateExtRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerRTASParallelOperationGetPropertiesExtRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnRTASParallelOperationGetPropertiesExtCb_t pfnGetPropertiesExtCb);
void btx_push_message_lttng_ust_zel_zelTracerRTASParallelOperationGetPropertiesExtRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerRTASParallelOperationJoinExtRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnRTASParallelOperationJoinExtCb_t pfnJoinExtCb);
void btx_push_message_lttng_ust_zel_zelTracerRTASParallelOperationJoinExtRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerRTASParallelOperationDestroyExtRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnRTASParallelOperationDestroyExtCb_t pfnDestroyExtCb);
void btx_push_message_lttng_ust_zel_zelTracerRTASParallelOperationDestroyExtRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerDeviceGetVectorWidthPropertiesExtRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnDeviceGetVectorWidthPropertiesExtCb_t pfnGetVectorWidthPropertiesExtCb);
void btx_push_message_lttng_ust_zel_zelTracerDeviceGetVectorWidthPropertiesExtRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerDeviceReserveCacheExtRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnDeviceReserveCacheExtCb_t pfnReserveCacheExtCb);
void btx_push_message_lttng_ust_zel_zelTracerDeviceReserveCacheExtRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerDeviceSetCacheAdviceExtRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnDeviceSetCacheAdviceExtCb_t pfnSetCacheAdviceExtCb);
void btx_push_message_lttng_ust_zel_zelTracerDeviceSetCacheAdviceExtRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerEventQueryTimestampsExpRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnEventQueryTimestampsExpCb_t pfnQueryTimestampsExpCb);
void btx_push_message_lttng_ust_zel_zelTracerEventQueryTimestampsExpRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerImageGetMemoryPropertiesExpRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnImageGetMemoryPropertiesExpCb_t pfnGetMemoryPropertiesExpCb);
void btx_push_message_lttng_ust_zel_zelTracerImageGetMemoryPropertiesExpRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerImageViewCreateExtRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnImageViewCreateExtCb_t pfnViewCreateExtCb);
void btx_push_message_lttng_ust_zel_zelTracerImageViewCreateExtRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerImageViewCreateExpRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnImageViewCreateExpCb_t pfnViewCreateExpCb);
void btx_push_message_lttng_ust_zel_zelTracerImageViewCreateExpRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerKernelSchedulingHintExpRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnKernelSchedulingHintExpCb_t pfnSchedulingHintExpCb);
void btx_push_message_lttng_ust_zel_zelTracerKernelSchedulingHintExpRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerDevicePciGetPropertiesExtRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnDevicePciGetPropertiesExtCb_t pfnPciGetPropertiesExtCb);
void btx_push_message_lttng_ust_zel_zelTracerDevicePciGetPropertiesExtRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendImageCopyToMemoryExtRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListAppendImageCopyToMemoryExtCb_t pfnAppendImageCopyToMemoryExtCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendImageCopyToMemoryExtRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendImageCopyFromMemoryExtRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListAppendImageCopyFromMemoryExtCb_t pfnAppendImageCopyFromMemoryExtCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListAppendImageCopyFromMemoryExtRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerImageGetAllocPropertiesExtRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnImageGetAllocPropertiesExtCb_t pfnGetAllocPropertiesExtCb);
void btx_push_message_lttng_ust_zel_zelTracerImageGetAllocPropertiesExtRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerModuleInspectLinkageExtRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnModuleInspectLinkageExtCb_t pfnInspectLinkageExtCb);
void btx_push_message_lttng_ust_zel_zelTracerModuleInspectLinkageExtRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerMemFreeExtRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnMemFreeExtCb_t pfnFreeExtCb);
void btx_push_message_lttng_ust_zel_zelTracerMemFreeExtRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerFabricVertexGetExpRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnFabricVertexGetExpCb_t pfnGetExpCb);
void btx_push_message_lttng_ust_zel_zelTracerFabricVertexGetExpRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerFabricVertexGetSubVerticesExpRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnFabricVertexGetSubVerticesExpCb_t pfnGetSubVerticesExpCb);
void btx_push_message_lttng_ust_zel_zelTracerFabricVertexGetSubVerticesExpRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerFabricVertexGetPropertiesExpRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnFabricVertexGetPropertiesExpCb_t pfnGetPropertiesExpCb);
void btx_push_message_lttng_ust_zel_zelTracerFabricVertexGetPropertiesExpRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerFabricVertexGetDeviceExpRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnFabricVertexGetDeviceExpCb_t pfnGetDeviceExpCb);
void btx_push_message_lttng_ust_zel_zelTracerFabricVertexGetDeviceExpRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerDeviceGetFabricVertexExpRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnDeviceGetFabricVertexExpCb_t pfnGetFabricVertexExpCb);
void btx_push_message_lttng_ust_zel_zelTracerDeviceGetFabricVertexExpRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerFabricEdgeGetExpRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnFabricEdgeGetExpCb_t pfnGetExpCb);
void btx_push_message_lttng_ust_zel_zelTracerFabricEdgeGetExpRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerFabricEdgeGetVerticesExpRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnFabricEdgeGetVerticesExpCb_t pfnGetVerticesExpCb);
void btx_push_message_lttng_ust_zel_zelTracerFabricEdgeGetVerticesExpRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerFabricEdgeGetPropertiesExpRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnFabricEdgeGetPropertiesExpCb_t pfnGetPropertiesExpCb);
void btx_push_message_lttng_ust_zel_zelTracerFabricEdgeGetPropertiesExpRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerEventQueryKernelTimestampsExtRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnEventQueryKernelTimestampsExtCb_t pfnQueryKernelTimestampsExtCb);
void btx_push_message_lttng_ust_zel_zelTracerEventQueryKernelTimestampsExtRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerRTASBuilderCreateExpRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnRTASBuilderCreateExpCb_t pfnCreateExpCb);
void btx_push_message_lttng_ust_zel_zelTracerRTASBuilderCreateExpRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerRTASBuilderGetBuildPropertiesExpRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnRTASBuilderGetBuildPropertiesExpCb_t pfnGetBuildPropertiesExpCb);
void btx_push_message_lttng_ust_zel_zelTracerRTASBuilderGetBuildPropertiesExpRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerDriverRTASFormatCompatibilityCheckExpRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnDriverRTASFormatCompatibilityCheckExpCb_t pfnRTASFormatCompatibilityCheckExpCb);
void btx_push_message_lttng_ust_zel_zelTracerDriverRTASFormatCompatibilityCheckExpRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerRTASBuilderBuildExpRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnRTASBuilderBuildExpCb_t pfnBuildExpCb);
void btx_push_message_lttng_ust_zel_zelTracerRTASBuilderBuildExpRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerRTASBuilderDestroyExpRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnRTASBuilderDestroyExpCb_t pfnDestroyExpCb);
void btx_push_message_lttng_ust_zel_zelTracerRTASBuilderDestroyExpRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerRTASParallelOperationCreateExpRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnRTASParallelOperationCreateExpCb_t pfnCreateExpCb);
void btx_push_message_lttng_ust_zel_zelTracerRTASParallelOperationCreateExpRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerRTASParallelOperationGetPropertiesExpRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnRTASParallelOperationGetPropertiesExpCb_t pfnGetPropertiesExpCb);
void btx_push_message_lttng_ust_zel_zelTracerRTASParallelOperationGetPropertiesExpRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerRTASParallelOperationJoinExpRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnRTASParallelOperationJoinExpCb_t pfnJoinExpCb);
void btx_push_message_lttng_ust_zel_zelTracerRTASParallelOperationJoinExpRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerRTASParallelOperationDestroyExpRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnRTASParallelOperationDestroyExpCb_t pfnDestroyExpCb);
void btx_push_message_lttng_ust_zel_zelTracerRTASParallelOperationDestroyExpRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerMemGetPitchFor2dImageRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnMemGetPitchFor2dImageCb_t pfnGetPitchFor2dImageCb);
void btx_push_message_lttng_ust_zel_zelTracerMemGetPitchFor2dImageRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerImageGetDeviceOffsetExpRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnImageGetDeviceOffsetExpCb_t pfnGetDeviceOffsetExpCb);
void btx_push_message_lttng_ust_zel_zelTracerImageGetDeviceOffsetExpRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListCreateCloneExpRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListCreateCloneExpCb_t pfnCreateCloneExpCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListCreateCloneExpRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListImmediateAppendCommandListsExpRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListImmediateAppendCommandListsExpCb_t pfnImmediateAppendCommandListsExpCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListImmediateAppendCommandListsExpRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListGetNextCommandIdExpRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListGetNextCommandIdExpCb_t pfnGetNextCommandIdExpCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListGetNextCommandIdExpRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListGetNextCommandIdWithKernelsExpRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListGetNextCommandIdWithKernelsExpCb_t pfnGetNextCommandIdWithKernelsExpCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListGetNextCommandIdWithKernelsExpRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListUpdateMutableCommandsExpRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListUpdateMutableCommandsExpCb_t pfnUpdateMutableCommandsExpCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListUpdateMutableCommandsExpRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListUpdateMutableCommandSignalEventExpRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListUpdateMutableCommandSignalEventExpCb_t pfnUpdateMutableCommandSignalEventExpCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListUpdateMutableCommandSignalEventExpRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListUpdateMutableCommandWaitEventsExpRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListUpdateMutableCommandWaitEventsExpCb_t pfnUpdateMutableCommandWaitEventsExpCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListUpdateMutableCommandWaitEventsExpRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelTracerCommandListUpdateMutableCommandKernelsExpRegisterCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_handle_t hTracer, zel_tracer_reg_t callback_type, ze_pfnCommandListUpdateMutableCommandKernelsExpCb_t pfnUpdateMutableCommandKernelsExpCb);
void btx_push_message_lttng_ust_zel_zelTracerCommandListUpdateMutableCommandKernelsExpRegisterCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelLoaderGetVersions_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, size_t * num_elems, zel_component_version_t * versions, size_t num_elems_val);
void btx_push_message_lttng_ust_zel_zelLoaderGetVersions_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t num_elems_val, size_t _versions_vals_length, zel_component_version_t * versions_vals);
void btx_push_message_lttng_ust_zel_zelLoaderTranslateHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_handle_type_t handleType, void * handleIn, void ** handleOut);
void btx_push_message_lttng_ust_zel_zelLoaderTranslateHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, void * handleOut_val);
void btx_push_message_lttng_ust_zel_zelSetDriverTeardown_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_zel_zelSetDriverTeardown_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelSetDelayLoaderContextTeardown_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_zel_zelSetDelayLoaderContextTeardown_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_zel_zelLoaderContextTeardown_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_zel_zelLoaderContextTeardown_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_zel_zelEnableTracingLayer_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_zel_zelEnableTracingLayer_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelCheckIsLoaderInTearDown_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_zel_zelCheckIsLoaderInTearDown_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, _Bool zeResult);
void btx_push_message_lttng_ust_zel_zelRegisterTeardownCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_loader_teardown_callback_t application_callback, zel_application_teardown_callback_t * loader_callback, uint32_t * index);
void btx_push_message_lttng_ust_zel_zelRegisterTeardownCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelDisableTracingLayer_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_zel_zelDisableTracingLayer_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelLoaderDriverCheck_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_init_flags_t flags, ze_init_driver_type_desc_t * desc, ze_global_dditable_t * globalInitStored, void * sysmanGlobalInitStored, _Bool * requireDdiReinit, _Bool sysmanOnly);
void btx_push_message_lttng_ust_zel_zelLoaderDriverCheck_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zelLoaderTracingLayerInit_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * zeDdiTable);
void btx_push_message_lttng_ust_zel_zelLoaderTracingLayerInit_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zel_zeLoaderGetTracingHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_zel_zeLoaderGetTracingHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * zeResult);
void btx_push_message_lttng_ust_zel_zelLoaderGetContext_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_zel_zelLoaderGetContext_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * zeResult);
void btx_push_message_lttng_ust_zel_zelLoaderGetVersionsInternal_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, size_t * num_elems, zel_component_version_t * versions, size_t num_elems_val);
void btx_push_message_lttng_ust_zel_zelLoaderGetVersionsInternal_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, size_t num_elems_val, size_t _versions_vals_length, zel_component_version_t * versions_vals);
void btx_push_message_lttng_ust_zel_zelLoaderTranslateHandleInternal_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_handle_type_t handleType, void * handleIn, void ** handleOut);
void btx_push_message_lttng_ust_zel_zelLoaderTranslateHandleInternal_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, void * handleOut_val);
void btx_push_message_lttng_ust_zex_zexKernelGetBaseAddress_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_kernel_handle_t hKernel, uint64_t * baseAddress);
void btx_push_message_lttng_ust_zex_zexKernelGetBaseAddress_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zex_zexKernelGetArgumentSize_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_kernel_handle_t hKernel, uint32_t argIndex, uint32_t * pArgSize);
void btx_push_message_lttng_ust_zex_zexKernelGetArgumentSize_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zex_zexKernelGetArgumentType_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_kernel_handle_t hKernel, uint32_t argIndex, uint32_t * pSize, char * pString);
void btx_push_message_lttng_ust_zex_zexKernelGetArgumentType_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zex_zexDriverImportExternalPointer_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_driver_handle_t hDriver, void * ptr, size_t size);
void btx_push_message_lttng_ust_zex_zexDriverImportExternalPointer_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zex_zexDriverReleaseImportedPointer_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_driver_handle_t hDriver, void * ptr);
void btx_push_message_lttng_ust_zex_zexDriverReleaseImportedPointer_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zex_zexDriverGetHostPointerBaseAddress_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_driver_handle_t hDriver, void * ptr, void ** baseAddress);
void btx_push_message_lttng_ust_zex_zexDriverGetHostPointerBaseAddress_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zex_zexMemGetIpcHandles_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, void * ptr, uint32_t * numIpcHandles, ze_ipc_mem_handle_t * pIpcHandles, uint32_t numIpcHandles_val);
void btx_push_message_lttng_ust_zex_zexMemGetIpcHandles_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, uint32_t numIpcHandles_val, size_t _pIpcHandles_vals_length, ze_ipc_mem_handle_t * pIpcHandles_vals);
void btx_push_message_lttng_ust_zex_zexMemOpenIpcHandles_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, ze_device_handle_t hDevice, uint32_t numIpcHandles, ze_ipc_mem_handle_t * pIpcHandles, ze_ipc_memory_flags_t flags, void ** pptr, size_t _pIpcHandles_vals_length, ze_ipc_mem_handle_t * pIpcHandles_vals);
void btx_push_message_lttng_ust_zex_zexMemOpenIpcHandles_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult, void * pptr_val);
void btx_push_message_lttng_ust_zex_zexCommandListAppendWaitOnMemory_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, zex_wait_on_mem_desc_t * desc, void * ptr, uint32_t data, ze_event_handle_t hSignalEvent);
void btx_push_message_lttng_ust_zex_zexCommandListAppendWaitOnMemory_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zex_zexCommandListAppendWriteToMemory_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_handle_t hCommandList, zex_write_to_mem_desc_t * desc, void * ptr, uint64_t data);
void btx_push_message_lttng_ust_zex_zexCommandListAppendWriteToMemory_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zex_zexEventGetDeviceAddress_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_event_handle_t event, uint64_t * completionValue, uint64_t * address);
void btx_push_message_lttng_ust_zex_zexEventGetDeviceAddress_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zex_zexCounterBasedEventCreate_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, ze_device_handle_t hDevice, uint64_t * deviceAddress, uint64_t * hostAddress, uint64_t completionValue, ze_event_desc_t * desc, ze_event_handle_t * phEvent);
void btx_push_message_lttng_ust_zex_zexCounterBasedEventCreate_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zex_zexCounterBasedEventGetIpcHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_event_handle_t hEvent, zex_ipc_counter_based_event_handle_t * phIpc);
void btx_push_message_lttng_ust_zex_zexCounterBasedEventGetIpcHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zex_zexCounterBasedEventCloseIpcHandle_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_event_handle_t hEvent);
void btx_push_message_lttng_ust_zex_zexCounterBasedEventCloseIpcHandle_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zex_zexIntelAllocateNetworkInterrupt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, uint32_t * networkInterruptId);
void btx_push_message_lttng_ust_zex_zexIntelAllocateNetworkInterrupt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_zex_zexIntelReleaseNetworkInterrupt_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, uint32_t networkInterruptId);
void btx_push_message_lttng_ust_zex_zexIntelReleaseNetworkInterrupt_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_result_t zeResult);
void btx_push_message_lttng_ust_ze_sampling_deviceProperties(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, uint32_t deviceIdx, size_t _pDeviceProperties_val_length, zes_device_properties_t * pDeviceProperties_val);
void btx_push_message_lttng_ust_ze_sampling_engineProperties(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, zes_engine_handle_t hEngines, size_t _pEngineProperties_val_length, zes_engine_properties_t * pEngineProperties_val);
void btx_push_message_lttng_ust_ze_sampling_engineStats(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, zes_engine_handle_t hEngines, size_t _pEngineStats_val_length, zes_engine_stats_t * pEngineStats_val);
void btx_push_message_lttng_ust_ze_sampling_powerProperties(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, zes_pwr_handle_t hPowers, size_t _pPowerProperties_val_length, zes_power_properties_t * pPowerProperties_val);
void btx_push_message_lttng_ust_ze_sampling_gpu_energy(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, zes_pwr_handle_t hPowers, uint32_t domainIdx, size_t _pEnergyCounter_val_length, zes_power_energy_counter_t * pEnergyCounter_val);
void btx_push_message_lttng_ust_ze_sampling_freqProperties(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, zes_freq_handle_t hFrequency, size_t _pFreqProperties_val_length, zes_freq_properties_t * pFreqProperties_val);
void btx_push_message_lttng_ust_ze_sampling_gpu_frequency(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, zes_freq_handle_t hFrequency, uint32_t domainIdx, size_t _pFreqState_val_length, zes_freq_state_t * pFreqState_val);
void btx_push_message_lttng_ust_ze_sampling_fabricPortProperties(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, zes_fabric_port_handle_t hFabricPort, size_t _pFabricPortProperties_val_length, zes_fabric_port_properties_t * pFabricPortProperties_val);
void btx_push_message_lttng_ust_ze_sampling_fabricPort(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, zes_fabric_port_handle_t hFabricPort, size_t _pFabricPortState_val_length, zes_fabric_port_state_t * pFabricPortState_val, size_t _pFabricPortThroughput_val_length, zes_fabric_port_throughput_t * pFabricPortThroughput_val);
void btx_push_message_lttng_ust_ze_sampling_memoryProperties(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, zes_mem_handle_t hMemModule, size_t _pMemModuleProperties_val_length, zes_mem_properties_t * pMemModuleProperties_val);
void btx_push_message_lttng_ust_ze_sampling_memStats(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_handle_t hDevice, zes_mem_handle_t hMemModule, size_t _pMemState_val_length, zes_mem_state_t * pMemState_val, size_t _pMemBandwidth_val_length, zes_mem_bandwidth_t * pMemBandwidth_val);
void btx_push_message_lttng_ust_ze_profiling_event_profiling(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_event_handle_t hEvent);
void btx_push_message_lttng_ust_ze_profiling_event_profiling_results(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_event_handle_t hEvent, ze_result_t status, ze_result_t timestampStatus, uint64_t globalStart, uint64_t globalEnd, uint64_t contextStart, uint64_t contextEnd);
void btx_push_message_lttng_ust_ze_properties_driver(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_driver_handle_t hDriver, size_t _pDriverProperties_val_length, ze_driver_properties_t * pDriverProperties_val);
void btx_push_message_lttng_ust_ze_properties_device(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_driver_handle_t hDriver, ze_device_handle_t hDevice, size_t _pDeviceProperties_val_length, ze_device_properties_t * pDeviceProperties_val);
void btx_push_message_lttng_ust_ze_properties_subdevice(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_driver_handle_t hDriver, ze_device_handle_t hDevice, ze_device_handle_t hSubDevice, size_t _pDeviceProperties_val_length, ze_device_properties_t * pDeviceProperties_val);
void btx_push_message_lttng_ust_ze_properties_command_queue_group(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_driver_handle_t hDriver, ze_device_handle_t hDevice, uint32_t pCount, size_t _pGroupProperties_vals_length, ze_command_queue_group_properties_t * pGroupProperties_vals);
void btx_push_message_lttng_ust_ze_properties_device_timer(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_handle_t hDevice, uint64_t hostTimestamp, uint64_t deviceTimestamp);
void btx_push_message_lttng_ust_ze_properties_memory_info_properties(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, void * ptr, size_t _pMemAllocProperties_val_length, ze_memory_allocation_properties_t * pMemAllocProperties_val, ze_device_handle_t hDevice);
void btx_push_message_lttng_ust_ze_properties_memory_info_range(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_handle_t hContext, void * ptr, void * base, size_t size);
void btx_push_message_lttng_ust_ze_properties_kernel(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_kernel_handle_t hKernel, size_t _pKernelProperties_val_length, ze_kernel_properties_t * pKernelProperties_val);
void btx_push_message_lttng_ust_ze_build_log(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, char * buildLog);
void btx_push_message_lttng_ust_ze_structs_ze_init_driver_type_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_init_driver_type_desc_t * p, size_t _p_val_length, ze_init_driver_type_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_driver_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_driver_properties_t * p, size_t _p_val_length, ze_driver_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_driver_ipc_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_driver_ipc_properties_t * p, size_t _p_val_length, ze_driver_ipc_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_device_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_properties_t * p, size_t _p_val_length, ze_device_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_device_compute_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_compute_properties_t * p, size_t _p_val_length, ze_device_compute_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_device_module_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_module_properties_t * p, size_t _p_val_length, ze_device_module_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_command_queue_group_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_queue_group_properties_t * p, size_t _p_val_length, ze_command_queue_group_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_device_memory_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_memory_properties_t * p, size_t _p_val_length, ze_device_memory_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_device_memory_access_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_memory_access_properties_t * p, size_t _p_val_length, ze_device_memory_access_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_device_cache_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_cache_properties_t * p, size_t _p_val_length, ze_device_cache_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_device_image_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_image_properties_t * p, size_t _p_val_length, ze_device_image_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_device_external_memory_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_external_memory_properties_t * p, size_t _p_val_length, ze_device_external_memory_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_device_p2p_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_p2p_properties_t * p, size_t _p_val_length, ze_device_p2p_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_context_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_desc_t * p, size_t _p_val_length, ze_context_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_command_queue_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_queue_desc_t * p, size_t _p_val_length, ze_command_queue_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_command_list_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_command_list_desc_t * p, size_t _p_val_length, ze_command_list_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_event_pool_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_event_pool_desc_t * p, size_t _p_val_length, ze_event_pool_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_event_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_event_desc_t * p, size_t _p_val_length, ze_event_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_fence_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_fence_desc_t * p, size_t _p_val_length, ze_fence_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_image_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_image_desc_t * p, size_t _p_val_length, ze_image_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_image_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_image_properties_t * p, size_t _p_val_length, ze_image_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_device_mem_alloc_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_mem_alloc_desc_t * p, size_t _p_val_length, ze_device_mem_alloc_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_host_mem_alloc_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_host_mem_alloc_desc_t * p, size_t _p_val_length, ze_host_mem_alloc_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_memory_allocation_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_memory_allocation_properties_t * p, size_t _p_val_length, ze_memory_allocation_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_external_memory_export_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_external_memory_export_desc_t * p, size_t _p_val_length, ze_external_memory_export_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_external_memory_import_fd_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_external_memory_import_fd_t * p, size_t _p_val_length, ze_external_memory_import_fd_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_external_memory_export_fd_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_external_memory_export_fd_t * p, size_t _p_val_length, ze_external_memory_export_fd_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_external_memory_import_win32_handle_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_external_memory_import_win32_handle_t * p, size_t _p_val_length, ze_external_memory_import_win32_handle_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_external_memory_export_win32_handle_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_external_memory_export_win32_handle_t * p, size_t _p_val_length, ze_external_memory_export_win32_handle_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_module_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_module_desc_t * p, size_t _p_val_length, ze_module_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_module_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_module_properties_t * p, size_t _p_val_length, ze_module_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_kernel_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_kernel_desc_t * p, size_t _p_val_length, ze_kernel_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_kernel_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_kernel_properties_t * p, size_t _p_val_length, ze_kernel_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_kernel_preferred_group_size_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_kernel_preferred_group_size_properties_t * p, size_t _p_val_length, ze_kernel_preferred_group_size_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_module_program_exp_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_module_program_exp_desc_t * p, size_t _p_val_length, ze_module_program_exp_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_device_raytracing_ext_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_raytracing_ext_properties_t * p, size_t _p_val_length, ze_device_raytracing_ext_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_raytracing_mem_alloc_ext_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_raytracing_mem_alloc_ext_desc_t * p, size_t _p_val_length, ze_raytracing_mem_alloc_ext_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_sampler_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_sampler_desc_t * p, size_t _p_val_length, ze_sampler_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_physical_mem_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_physical_mem_desc_t * p, size_t _p_val_length, ze_physical_mem_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_float_atomic_ext_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_float_atomic_ext_properties_t * p, size_t _p_val_length, ze_float_atomic_ext_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_relaxed_allocation_limits_exp_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_relaxed_allocation_limits_exp_desc_t * p, size_t _p_val_length, ze_relaxed_allocation_limits_exp_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_driver_ddi_handles_ext_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_driver_ddi_handles_ext_properties_t * p, size_t _p_val_length, ze_driver_ddi_handles_ext_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_external_semaphore_ext_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_external_semaphore_ext_desc_t * p, size_t _p_val_length, ze_external_semaphore_ext_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_external_semaphore_win32_ext_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_external_semaphore_win32_ext_desc_t * p, size_t _p_val_length, ze_external_semaphore_win32_ext_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_external_semaphore_fd_ext_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_external_semaphore_fd_ext_desc_t * p, size_t _p_val_length, ze_external_semaphore_fd_ext_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_external_semaphore_signal_params_ext_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_external_semaphore_signal_params_ext_t * p, size_t _p_val_length, ze_external_semaphore_signal_params_ext_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_external_semaphore_wait_params_ext_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_external_semaphore_wait_params_ext_t * p, size_t _p_val_length, ze_external_semaphore_wait_params_ext_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_device_cache_line_size_ext_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_cache_line_size_ext_t * p, size_t _p_val_length, ze_device_cache_line_size_ext_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_rtas_builder_ext_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_rtas_builder_ext_desc_t * p, size_t _p_val_length, ze_rtas_builder_ext_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_rtas_builder_ext_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_rtas_builder_ext_properties_t * p, size_t _p_val_length, ze_rtas_builder_ext_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_rtas_parallel_operation_ext_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_rtas_parallel_operation_ext_properties_t * p, size_t _p_val_length, ze_rtas_parallel_operation_ext_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_rtas_device_ext_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_rtas_device_ext_properties_t * p, size_t _p_val_length, ze_rtas_device_ext_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_rtas_geometry_aabbs_ext_cb_params_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_rtas_geometry_aabbs_ext_cb_params_t * p, size_t _p_val_length, ze_rtas_geometry_aabbs_ext_cb_params_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_rtas_builder_build_op_ext_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_rtas_builder_build_op_ext_desc_t * p, size_t _p_val_length, ze_rtas_builder_build_op_ext_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_device_vector_width_properties_ext_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_vector_width_properties_ext_t * p, size_t _p_val_length, ze_device_vector_width_properties_ext_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_cache_reservation_ext_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_cache_reservation_ext_desc_t * p, size_t _p_val_length, ze_cache_reservation_ext_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_image_memory_properties_exp_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_image_memory_properties_exp_t * p, size_t _p_val_length, ze_image_memory_properties_exp_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_image_view_planar_ext_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_image_view_planar_ext_desc_t * p, size_t _p_val_length, ze_image_view_planar_ext_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_image_view_planar_exp_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_image_view_planar_exp_desc_t * p, size_t _p_val_length, ze_image_view_planar_exp_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_scheduling_hint_exp_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_scheduling_hint_exp_properties_t * p, size_t _p_val_length, ze_scheduling_hint_exp_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_scheduling_hint_exp_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_scheduling_hint_exp_desc_t * p, size_t _p_val_length, ze_scheduling_hint_exp_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_context_power_saving_hint_exp_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_context_power_saving_hint_exp_desc_t * p, size_t _p_val_length, ze_context_power_saving_hint_exp_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_eu_count_ext_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_eu_count_ext_t * p, size_t _p_val_length, ze_eu_count_ext_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_pci_ext_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_pci_ext_properties_t * p, size_t _p_val_length, ze_pci_ext_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_srgb_ext_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_srgb_ext_desc_t * p, size_t _p_val_length, ze_srgb_ext_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_image_allocation_ext_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_image_allocation_ext_properties_t * p, size_t _p_val_length, ze_image_allocation_ext_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_linkage_inspection_ext_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_linkage_inspection_ext_desc_t * p, size_t _p_val_length, ze_linkage_inspection_ext_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_memory_compression_hints_ext_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_memory_compression_hints_ext_desc_t * p, size_t _p_val_length, ze_memory_compression_hints_ext_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_driver_memory_free_ext_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_driver_memory_free_ext_properties_t * p, size_t _p_val_length, ze_driver_memory_free_ext_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_memory_free_ext_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_memory_free_ext_desc_t * p, size_t _p_val_length, ze_memory_free_ext_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_device_p2p_bandwidth_exp_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_p2p_bandwidth_exp_properties_t * p, size_t _p_val_length, ze_device_p2p_bandwidth_exp_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_copy_bandwidth_exp_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_copy_bandwidth_exp_properties_t * p, size_t _p_val_length, ze_copy_bandwidth_exp_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_device_luid_ext_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_luid_ext_properties_t * p, size_t _p_val_length, ze_device_luid_ext_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_fabric_vertex_exp_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_fabric_vertex_exp_properties_t * p, size_t _p_val_length, ze_fabric_vertex_exp_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_fabric_edge_exp_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_fabric_edge_exp_properties_t * p, size_t _p_val_length, ze_fabric_edge_exp_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_device_memory_ext_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_memory_ext_properties_t * p, size_t _p_val_length, ze_device_memory_ext_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_device_ip_version_ext_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_ip_version_ext_t * p, size_t _p_val_length, ze_device_ip_version_ext_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_kernel_max_group_size_properties_ext_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_kernel_max_group_size_properties_ext_t * p, size_t _p_val_length, ze_kernel_max_group_size_properties_ext_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_memory_sub_allocations_exp_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_memory_sub_allocations_exp_properties_t * p, size_t _p_val_length, ze_memory_sub_allocations_exp_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_event_query_kernel_timestamps_ext_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_event_query_kernel_timestamps_ext_properties_t * p, size_t _p_val_length, ze_event_query_kernel_timestamps_ext_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_event_query_kernel_timestamps_results_ext_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_event_query_kernel_timestamps_results_ext_properties_t * p, size_t _p_val_length, ze_event_query_kernel_timestamps_results_ext_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_rtas_builder_exp_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_rtas_builder_exp_desc_t * p, size_t _p_val_length, ze_rtas_builder_exp_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_rtas_builder_exp_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_rtas_builder_exp_properties_t * p, size_t _p_val_length, ze_rtas_builder_exp_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_rtas_parallel_operation_exp_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_rtas_parallel_operation_exp_properties_t * p, size_t _p_val_length, ze_rtas_parallel_operation_exp_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_rtas_device_exp_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_rtas_device_exp_properties_t * p, size_t _p_val_length, ze_rtas_device_exp_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_rtas_geometry_aabbs_exp_cb_params_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_rtas_geometry_aabbs_exp_cb_params_t * p, size_t _p_val_length, ze_rtas_geometry_aabbs_exp_cb_params_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_rtas_builder_build_op_exp_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_rtas_builder_build_op_exp_desc_t * p, size_t _p_val_length, ze_rtas_builder_build_op_exp_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_event_pool_counter_based_exp_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_event_pool_counter_based_exp_desc_t * p, size_t _p_val_length, ze_event_pool_counter_based_exp_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_image_bindless_exp_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_image_bindless_exp_desc_t * p, size_t _p_val_length, ze_image_bindless_exp_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_image_pitched_exp_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_image_pitched_exp_desc_t * p, size_t _p_val_length, ze_image_pitched_exp_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_device_pitched_alloc_exp_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_device_pitched_alloc_exp_properties_t * p, size_t _p_val_length, ze_device_pitched_alloc_exp_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_mutable_command_id_exp_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_mutable_command_id_exp_desc_t * p, size_t _p_val_length, ze_mutable_command_id_exp_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_mutable_command_list_exp_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_mutable_command_list_exp_properties_t * p, size_t _p_val_length, ze_mutable_command_list_exp_properties_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_mutable_command_list_exp_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_mutable_command_list_exp_desc_t * p, size_t _p_val_length, ze_mutable_command_list_exp_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_mutable_commands_exp_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_mutable_commands_exp_desc_t * p, size_t _p_val_length, ze_mutable_commands_exp_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_mutable_kernel_argument_exp_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_mutable_kernel_argument_exp_desc_t * p, size_t _p_val_length, ze_mutable_kernel_argument_exp_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_mutable_group_count_exp_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_mutable_group_count_exp_desc_t * p, size_t _p_val_length, ze_mutable_group_count_exp_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_mutable_group_size_exp_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_mutable_group_size_exp_desc_t * p, size_t _p_val_length, ze_mutable_group_size_exp_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_mutable_global_offset_exp_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_mutable_global_offset_exp_desc_t * p, size_t _p_val_length, ze_mutable_global_offset_exp_desc_t * p_val);
void btx_push_message_lttng_ust_ze_structs_ze_mutable_graph_argument_exp_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ze_mutable_graph_argument_exp_desc_t * p, size_t _p_val_length, ze_mutable_graph_argument_exp_desc_t * p_val);
void btx_push_message_lttng_ust_zet_structs_zet_device_debug_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_device_debug_properties_t * p, size_t _p_val_length, zet_device_debug_properties_t * p_val);
void btx_push_message_lttng_ust_zet_structs_zet_debug_memory_space_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_debug_memory_space_desc_t * p, size_t _p_val_length, zet_debug_memory_space_desc_t * p_val);
void btx_push_message_lttng_ust_zet_structs_zet_debug_regset_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_debug_regset_properties_t * p, size_t _p_val_length, zet_debug_regset_properties_t * p_val);
void btx_push_message_lttng_ust_zet_structs_zet_metric_group_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_group_properties_t * p, size_t _p_val_length, zet_metric_group_properties_t * p_val);
void btx_push_message_lttng_ust_zet_structs_zet_metric_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_properties_t * p, size_t _p_val_length, zet_metric_properties_t * p_val);
void btx_push_message_lttng_ust_zet_structs_zet_metric_streamer_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_streamer_desc_t * p, size_t _p_val_length, zet_metric_streamer_desc_t * p_val);
void btx_push_message_lttng_ust_zet_structs_zet_metric_query_pool_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_query_pool_desc_t * p, size_t _p_val_length, zet_metric_query_pool_desc_t * p_val);
void btx_push_message_lttng_ust_zet_structs_zet_profile_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_profile_properties_t * p, size_t _p_val_length, zet_profile_properties_t * p_val);
void btx_push_message_lttng_ust_zet_structs_zet_tracer_exp_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_tracer_exp_desc_t * p, size_t _p_val_length, zet_tracer_exp_desc_t * p_val);
void btx_push_message_lttng_ust_zet_structs_zet_metric_tracer_exp_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_tracer_exp_desc_t * p, size_t _p_val_length, zet_metric_tracer_exp_desc_t * p_val);
void btx_push_message_lttng_ust_zet_structs_zet_metric_group_type_exp_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_group_type_exp_t * p, size_t _p_val_length, zet_metric_group_type_exp_t * p_val);
void btx_push_message_lttng_ust_zet_structs_zet_export_dma_buf_exp_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_export_dma_buf_exp_properties_t * p, size_t _p_val_length, zet_export_dma_buf_exp_properties_t * p_val);
void btx_push_message_lttng_ust_zet_structs_zet_metric_global_timestamps_resolution_exp_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_global_timestamps_resolution_exp_t * p, size_t _p_val_length, zet_metric_global_timestamps_resolution_exp_t * p_val);
void btx_push_message_lttng_ust_zet_structs_zet_metric_calculate_exp_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_calculate_exp_desc_t * p, size_t _p_val_length, zet_metric_calculate_exp_desc_t * p_val);
void btx_push_message_lttng_ust_zet_structs_zet_metric_programmable_exp_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_programmable_exp_properties_t * p, size_t _p_val_length, zet_metric_programmable_exp_properties_t * p_val);
void btx_push_message_lttng_ust_zet_structs_zet_metric_programmable_param_info_exp_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_programmable_param_info_exp_t * p, size_t _p_val_length, zet_metric_programmable_param_info_exp_t * p_val);
void btx_push_message_lttng_ust_zet_structs_zet_metric_programmable_param_value_info_exp_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zet_metric_programmable_param_value_info_exp_t * p, size_t _p_val_length, zet_metric_programmable_param_value_info_exp_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_base_state_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_base_state_t * p, size_t _p_val_length, zes_base_state_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_device_state_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_state_t * p, size_t _p_val_length, zes_device_state_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_reset_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_reset_properties_t * p, size_t _p_val_length, zes_reset_properties_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_device_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_properties_t * p, size_t _p_val_length, zes_device_properties_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_device_ext_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_ext_properties_t * p, size_t _p_val_length, zes_device_ext_properties_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_process_state_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_process_state_t * p, size_t _p_val_length, zes_process_state_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_pci_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_pci_properties_t * p, size_t _p_val_length, zes_pci_properties_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_pci_state_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_pci_state_t * p, size_t _p_val_length, zes_pci_state_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_pci_bar_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_pci_bar_properties_t * p, size_t _p_val_length, zes_pci_bar_properties_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_pci_bar_properties_1_2_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_pci_bar_properties_1_2_t * p, size_t _p_val_length, zes_pci_bar_properties_1_2_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_overclock_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_overclock_properties_t * p, size_t _p_val_length, zes_overclock_properties_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_diag_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_diag_properties_t * p, size_t _p_val_length, zes_diag_properties_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_device_ecc_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_ecc_desc_t * p, size_t _p_val_length, zes_device_ecc_desc_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_device_ecc_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_ecc_properties_t * p, size_t _p_val_length, zes_device_ecc_properties_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_engine_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_engine_properties_t * p, size_t _p_val_length, zes_engine_properties_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_fabric_port_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_fabric_port_properties_t * p, size_t _p_val_length, zes_fabric_port_properties_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_fabric_port_config_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_fabric_port_config_t * p, size_t _p_val_length, zes_fabric_port_config_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_fabric_port_state_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_fabric_port_state_t * p, size_t _p_val_length, zes_fabric_port_state_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_fabric_port_error_counters_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_fabric_port_error_counters_t * p, size_t _p_val_length, zes_fabric_port_error_counters_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_fan_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_fan_properties_t * p, size_t _p_val_length, zes_fan_properties_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_fan_config_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_fan_config_t * p, size_t _p_val_length, zes_fan_config_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_firmware_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_firmware_properties_t * p, size_t _p_val_length, zes_firmware_properties_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_freq_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_freq_properties_t * p, size_t _p_val_length, zes_freq_properties_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_freq_state_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_freq_state_t * p, size_t _p_val_length, zes_freq_state_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_oc_capabilities_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_oc_capabilities_t * p, size_t _p_val_length, zes_oc_capabilities_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_led_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_led_properties_t * p, size_t _p_val_length, zes_led_properties_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_led_state_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_led_state_t * p, size_t _p_val_length, zes_led_state_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_mem_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_mem_properties_t * p, size_t _p_val_length, zes_mem_properties_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_mem_state_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_mem_state_t * p, size_t _p_val_length, zes_mem_state_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_perf_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_perf_properties_t * p, size_t _p_val_length, zes_perf_properties_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_power_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_power_properties_t * p, size_t _p_val_length, zes_power_properties_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_psu_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_psu_properties_t * p, size_t _p_val_length, zes_psu_properties_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_psu_state_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_psu_state_t * p, size_t _p_val_length, zes_psu_state_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_ras_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_ras_properties_t * p, size_t _p_val_length, zes_ras_properties_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_ras_state_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_ras_state_t * p, size_t _p_val_length, zes_ras_state_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_ras_config_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_ras_config_t * p, size_t _p_val_length, zes_ras_config_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_sched_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_sched_properties_t * p, size_t _p_val_length, zes_sched_properties_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_sched_timeout_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_sched_timeout_properties_t * p, size_t _p_val_length, zes_sched_timeout_properties_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_sched_timeslice_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_sched_timeslice_properties_t * p, size_t _p_val_length, zes_sched_timeslice_properties_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_standby_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_standby_properties_t * p, size_t _p_val_length, zes_standby_properties_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_temp_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_temp_properties_t * p, size_t _p_val_length, zes_temp_properties_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_temp_config_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_temp_config_t * p, size_t _p_val_length, zes_temp_config_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_device_ecc_default_properties_ext_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_device_ecc_default_properties_ext_t * p, size_t _p_val_length, zes_device_ecc_default_properties_ext_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_power_limit_ext_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_power_limit_ext_desc_t * p, size_t _p_val_length, zes_power_limit_ext_desc_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_power_ext_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_power_ext_properties_t * p, size_t _p_val_length, zes_power_ext_properties_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_engine_ext_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_engine_ext_properties_t * p, size_t _p_val_length, zes_engine_ext_properties_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_mem_page_offline_state_exp_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_mem_page_offline_state_exp_t * p, size_t _p_val_length, zes_mem_page_offline_state_exp_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_mem_bandwidth_counter_bits_exp_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_mem_bandwidth_counter_bits_exp_properties_t * p, size_t _p_val_length, zes_mem_bandwidth_counter_bits_exp_properties_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_power_domain_exp_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_power_domain_exp_properties_t * p, size_t _p_val_length, zes_power_domain_exp_properties_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_subdevice_exp_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_subdevice_exp_properties_t * p, size_t _p_val_length, zes_subdevice_exp_properties_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_vf_exp_properties_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_vf_exp_properties_t * p, size_t _p_val_length, zes_vf_exp_properties_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_vf_util_mem_exp_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_vf_util_mem_exp_t * p, size_t _p_val_length, zes_vf_util_mem_exp_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_vf_util_engine_exp_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_vf_util_engine_exp_t * p, size_t _p_val_length, zes_vf_util_engine_exp_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_vf_exp_capabilities_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_vf_exp_capabilities_t * p, size_t _p_val_length, zes_vf_exp_capabilities_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_vf_exp2_capabilities_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_vf_exp2_capabilities_t * p, size_t _p_val_length, zes_vf_exp2_capabilities_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_vf_util_mem_exp2_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_vf_util_mem_exp2_t * p, size_t _p_val_length, zes_vf_util_mem_exp2_t * p_val);
void btx_push_message_lttng_ust_zes_structs_zes_vf_util_engine_exp2_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zes_vf_util_engine_exp2_t * p, size_t _p_val_length, zes_vf_util_engine_exp2_t * p_val);
void btx_push_message_lttng_ust_zel_structs_zel_tracer_desc_t(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, zel_tracer_desc_t * p, size_t _p_val_length, zel_tracer_desc_t * p_val);


void btx_downstream_set_environment_hostname(
    void *btx_handle, const char* hostname);

#ifdef __cplusplus
}
#endif
