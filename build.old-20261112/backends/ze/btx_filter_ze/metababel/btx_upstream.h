#pragma once
#include <metababel/btx_component.h>
#ifdef __cplusplus
extern "C" {
#endif

// Dispatcher
typedef void(dispatcher_t)(callbacks_t *callbacks, common_data_t *common_data,
                           const bt_message *upstream_message);

typedef void lttng_ust_ze_zeInit_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_init_flags_t);

void btx_register_callbacks_lttng_ust_ze_zeInit_entry(
    void *btx_handle, lttng_ust_ze_zeInit_entry_callback_f *callback);

typedef void lttng_ust_ze_zeInit_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeInit_exit(
    void *btx_handle, lttng_ust_ze_zeInit_exit_callback_f *callback);

typedef void lttng_ust_ze_zeDriverGet_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, uint32_t *, ze_driver_handle_t *, uint32_t);

void btx_register_callbacks_lttng_ust_ze_zeDriverGet_entry(
    void *btx_handle, lttng_ust_ze_zeDriverGet_entry_callback_f *callback);

typedef void lttng_ust_ze_zeDriverGet_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, ze_driver_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeDriverGet_exit(
    void *btx_handle, lttng_ust_ze_zeDriverGet_exit_callback_f *callback);

typedef void lttng_ust_ze_zeInitDrivers_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, uint32_t *, ze_driver_handle_t *, ze_init_driver_type_desc_t *, size_t, ze_init_driver_type_desc_t *, uint32_t);

void btx_register_callbacks_lttng_ust_ze_zeInitDrivers_entry(
    void *btx_handle, lttng_ust_ze_zeInitDrivers_entry_callback_f *callback);

typedef void lttng_ust_ze_zeInitDrivers_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, ze_driver_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeInitDrivers_exit(
    void *btx_handle, lttng_ust_ze_zeInitDrivers_exit_callback_f *callback);

typedef void lttng_ust_ze_zeDriverGetApiVersion_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_driver_handle_t, ze_api_version_t *);

void btx_register_callbacks_lttng_ust_ze_zeDriverGetApiVersion_entry(
    void *btx_handle, lttng_ust_ze_zeDriverGetApiVersion_entry_callback_f *callback);

typedef void lttng_ust_ze_zeDriverGetApiVersion_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_api_version_t);

void btx_register_callbacks_lttng_ust_ze_zeDriverGetApiVersion_exit(
    void *btx_handle, lttng_ust_ze_zeDriverGetApiVersion_exit_callback_f *callback);

typedef void lttng_ust_ze_zeDriverGetProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_driver_handle_t, ze_driver_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeDriverGetProperties_entry(
    void *btx_handle, lttng_ust_ze_zeDriverGetProperties_entry_callback_f *callback);

typedef void lttng_ust_ze_zeDriverGetProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, ze_driver_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeDriverGetProperties_exit(
    void *btx_handle, lttng_ust_ze_zeDriverGetProperties_exit_callback_f *callback);

typedef void lttng_ust_ze_zeDriverGetIpcProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_driver_handle_t, ze_driver_ipc_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeDriverGetIpcProperties_entry(
    void *btx_handle, lttng_ust_ze_zeDriverGetIpcProperties_entry_callback_f *callback);

typedef void lttng_ust_ze_zeDriverGetIpcProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, ze_driver_ipc_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeDriverGetIpcProperties_exit(
    void *btx_handle, lttng_ust_ze_zeDriverGetIpcProperties_exit_callback_f *callback);

typedef void lttng_ust_ze_zeDriverGetExtensionProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_driver_handle_t, uint32_t *, ze_driver_extension_properties_t *, uint32_t);

void btx_register_callbacks_lttng_ust_ze_zeDriverGetExtensionProperties_entry(
    void *btx_handle, lttng_ust_ze_zeDriverGetExtensionProperties_entry_callback_f *callback);

typedef void lttng_ust_ze_zeDriverGetExtensionProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, ze_driver_extension_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeDriverGetExtensionProperties_exit(
    void *btx_handle, lttng_ust_ze_zeDriverGetExtensionProperties_exit_callback_f *callback);

typedef void lttng_ust_ze_zeDriverGetExtensionFunctionAddress_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_driver_handle_t, char *, void **, char *);

void btx_register_callbacks_lttng_ust_ze_zeDriverGetExtensionFunctionAddress_entry(
    void *btx_handle, lttng_ust_ze_zeDriverGetExtensionFunctionAddress_entry_callback_f *callback);

typedef void lttng_ust_ze_zeDriverGetExtensionFunctionAddress_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, void *);

void btx_register_callbacks_lttng_ust_ze_zeDriverGetExtensionFunctionAddress_exit(
    void *btx_handle, lttng_ust_ze_zeDriverGetExtensionFunctionAddress_exit_callback_f *callback);

typedef void lttng_ust_ze_zeDriverGetLastErrorDescription_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_driver_handle_t, char **);

void btx_register_callbacks_lttng_ust_ze_zeDriverGetLastErrorDescription_entry(
    void *btx_handle, lttng_ust_ze_zeDriverGetLastErrorDescription_entry_callback_f *callback);

typedef void lttng_ust_ze_zeDriverGetLastErrorDescription_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, char *);

void btx_register_callbacks_lttng_ust_ze_zeDriverGetLastErrorDescription_exit(
    void *btx_handle, lttng_ust_ze_zeDriverGetLastErrorDescription_exit_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceGet_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_driver_handle_t, uint32_t *, ze_device_handle_t *, uint32_t);

void btx_register_callbacks_lttng_ust_ze_zeDeviceGet_entry(
    void *btx_handle, lttng_ust_ze_zeDeviceGet_entry_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceGet_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, ze_device_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeDeviceGet_exit(
    void *btx_handle, lttng_ust_ze_zeDeviceGet_exit_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceGetRootDevice_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_handle_t, ze_device_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeDeviceGetRootDevice_entry(
    void *btx_handle, lttng_ust_ze_zeDeviceGetRootDevice_entry_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceGetRootDevice_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_device_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeDeviceGetRootDevice_exit(
    void *btx_handle, lttng_ust_ze_zeDeviceGetRootDevice_exit_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceGetSubDevices_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_handle_t, uint32_t *, ze_device_handle_t *, uint32_t);

void btx_register_callbacks_lttng_ust_ze_zeDeviceGetSubDevices_entry(
    void *btx_handle, lttng_ust_ze_zeDeviceGetSubDevices_entry_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceGetSubDevices_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, ze_device_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeDeviceGetSubDevices_exit(
    void *btx_handle, lttng_ust_ze_zeDeviceGetSubDevices_exit_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceGetProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_handle_t, ze_device_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeDeviceGetProperties_entry(
    void *btx_handle, lttng_ust_ze_zeDeviceGetProperties_entry_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceGetProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, ze_device_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeDeviceGetProperties_exit(
    void *btx_handle, lttng_ust_ze_zeDeviceGetProperties_exit_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceGetComputeProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_handle_t, ze_device_compute_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeDeviceGetComputeProperties_entry(
    void *btx_handle, lttng_ust_ze_zeDeviceGetComputeProperties_entry_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceGetComputeProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, ze_device_compute_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeDeviceGetComputeProperties_exit(
    void *btx_handle, lttng_ust_ze_zeDeviceGetComputeProperties_exit_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceGetModuleProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_handle_t, ze_device_module_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeDeviceGetModuleProperties_entry(
    void *btx_handle, lttng_ust_ze_zeDeviceGetModuleProperties_entry_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceGetModuleProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, ze_device_module_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeDeviceGetModuleProperties_exit(
    void *btx_handle, lttng_ust_ze_zeDeviceGetModuleProperties_exit_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceGetCommandQueueGroupProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_handle_t, uint32_t *, ze_command_queue_group_properties_t *, uint32_t);

void btx_register_callbacks_lttng_ust_ze_zeDeviceGetCommandQueueGroupProperties_entry(
    void *btx_handle, lttng_ust_ze_zeDeviceGetCommandQueueGroupProperties_entry_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceGetCommandQueueGroupProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, ze_command_queue_group_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeDeviceGetCommandQueueGroupProperties_exit(
    void *btx_handle, lttng_ust_ze_zeDeviceGetCommandQueueGroupProperties_exit_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceGetMemoryProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_handle_t, uint32_t *, ze_device_memory_properties_t *, uint32_t);

void btx_register_callbacks_lttng_ust_ze_zeDeviceGetMemoryProperties_entry(
    void *btx_handle, lttng_ust_ze_zeDeviceGetMemoryProperties_entry_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceGetMemoryProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, ze_device_memory_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeDeviceGetMemoryProperties_exit(
    void *btx_handle, lttng_ust_ze_zeDeviceGetMemoryProperties_exit_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceGetMemoryAccessProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_handle_t, ze_device_memory_access_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeDeviceGetMemoryAccessProperties_entry(
    void *btx_handle, lttng_ust_ze_zeDeviceGetMemoryAccessProperties_entry_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceGetMemoryAccessProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, ze_device_memory_access_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeDeviceGetMemoryAccessProperties_exit(
    void *btx_handle, lttng_ust_ze_zeDeviceGetMemoryAccessProperties_exit_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceGetCacheProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_handle_t, uint32_t *, ze_device_cache_properties_t *, uint32_t);

void btx_register_callbacks_lttng_ust_ze_zeDeviceGetCacheProperties_entry(
    void *btx_handle, lttng_ust_ze_zeDeviceGetCacheProperties_entry_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceGetCacheProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, ze_device_cache_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeDeviceGetCacheProperties_exit(
    void *btx_handle, lttng_ust_ze_zeDeviceGetCacheProperties_exit_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceGetImageProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_handle_t, ze_device_image_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeDeviceGetImageProperties_entry(
    void *btx_handle, lttng_ust_ze_zeDeviceGetImageProperties_entry_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceGetImageProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, ze_device_image_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeDeviceGetImageProperties_exit(
    void *btx_handle, lttng_ust_ze_zeDeviceGetImageProperties_exit_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceGetExternalMemoryProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_handle_t, ze_device_external_memory_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeDeviceGetExternalMemoryProperties_entry(
    void *btx_handle, lttng_ust_ze_zeDeviceGetExternalMemoryProperties_entry_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceGetExternalMemoryProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, ze_device_external_memory_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeDeviceGetExternalMemoryProperties_exit(
    void *btx_handle, lttng_ust_ze_zeDeviceGetExternalMemoryProperties_exit_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceGetP2PProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_handle_t, ze_device_handle_t, ze_device_p2p_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeDeviceGetP2PProperties_entry(
    void *btx_handle, lttng_ust_ze_zeDeviceGetP2PProperties_entry_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceGetP2PProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, ze_device_p2p_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeDeviceGetP2PProperties_exit(
    void *btx_handle, lttng_ust_ze_zeDeviceGetP2PProperties_exit_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceCanAccessPeer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_handle_t, ze_device_handle_t, ze_bool_t *);

void btx_register_callbacks_lttng_ust_ze_zeDeviceCanAccessPeer_entry(
    void *btx_handle, lttng_ust_ze_zeDeviceCanAccessPeer_entry_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceCanAccessPeer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_bool_t);

void btx_register_callbacks_lttng_ust_ze_zeDeviceCanAccessPeer_exit(
    void *btx_handle, lttng_ust_ze_zeDeviceCanAccessPeer_exit_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceGetStatus_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeDeviceGetStatus_entry(
    void *btx_handle, lttng_ust_ze_zeDeviceGetStatus_entry_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceGetStatus_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeDeviceGetStatus_exit(
    void *btx_handle, lttng_ust_ze_zeDeviceGetStatus_exit_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceGetGlobalTimestamps_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_handle_t, uint64_t *, uint64_t *);

void btx_register_callbacks_lttng_ust_ze_zeDeviceGetGlobalTimestamps_entry(
    void *btx_handle, lttng_ust_ze_zeDeviceGetGlobalTimestamps_entry_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceGetGlobalTimestamps_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint64_t, uint64_t);

void btx_register_callbacks_lttng_ust_ze_zeDeviceGetGlobalTimestamps_exit(
    void *btx_handle, lttng_ust_ze_zeDeviceGetGlobalTimestamps_exit_callback_f *callback);

typedef void lttng_ust_ze_zeContextCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_driver_handle_t, ze_context_desc_t *, ze_context_handle_t *, size_t, ze_context_desc_t *);

void btx_register_callbacks_lttng_ust_ze_zeContextCreate_entry(
    void *btx_handle, lttng_ust_ze_zeContextCreate_entry_callback_f *callback);

typedef void lttng_ust_ze_zeContextCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_context_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeContextCreate_exit(
    void *btx_handle, lttng_ust_ze_zeContextCreate_exit_callback_f *callback);

typedef void lttng_ust_ze_zeContextCreateEx_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_driver_handle_t, ze_context_desc_t *, uint32_t, ze_device_handle_t *, ze_context_handle_t *, size_t, ze_context_desc_t *, size_t, ze_device_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeContextCreateEx_entry(
    void *btx_handle, lttng_ust_ze_zeContextCreateEx_entry_callback_f *callback);

typedef void lttng_ust_ze_zeContextCreateEx_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_context_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeContextCreateEx_exit(
    void *btx_handle, lttng_ust_ze_zeContextCreateEx_exit_callback_f *callback);

typedef void lttng_ust_ze_zeContextDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeContextDestroy_entry(
    void *btx_handle, lttng_ust_ze_zeContextDestroy_entry_callback_f *callback);

typedef void lttng_ust_ze_zeContextDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeContextDestroy_exit(
    void *btx_handle, lttng_ust_ze_zeContextDestroy_exit_callback_f *callback);

typedef void lttng_ust_ze_zeContextGetStatus_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeContextGetStatus_entry(
    void *btx_handle, lttng_ust_ze_zeContextGetStatus_entry_callback_f *callback);

typedef void lttng_ust_ze_zeContextGetStatus_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeContextGetStatus_exit(
    void *btx_handle, lttng_ust_ze_zeContextGetStatus_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandQueueCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, ze_device_handle_t, ze_command_queue_desc_t *, ze_command_queue_handle_t *, size_t, ze_command_queue_desc_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandQueueCreate_entry(
    void *btx_handle, lttng_ust_ze_zeCommandQueueCreate_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandQueueCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_command_queue_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandQueueCreate_exit(
    void *btx_handle, lttng_ust_ze_zeCommandQueueCreate_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandQueueDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_queue_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandQueueDestroy_entry(
    void *btx_handle, lttng_ust_ze_zeCommandQueueDestroy_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandQueueDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandQueueDestroy_exit(
    void *btx_handle, lttng_ust_ze_zeCommandQueueDestroy_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandQueueExecuteCommandLists_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_queue_handle_t, uint32_t, ze_command_list_handle_t *, ze_fence_handle_t, size_t, ze_command_list_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandQueueExecuteCommandLists_entry(
    void *btx_handle, lttng_ust_ze_zeCommandQueueExecuteCommandLists_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandQueueExecuteCommandLists_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandQueueExecuteCommandLists_exit(
    void *btx_handle, lttng_ust_ze_zeCommandQueueExecuteCommandLists_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandQueueSynchronize_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_queue_handle_t, uint64_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandQueueSynchronize_entry(
    void *btx_handle, lttng_ust_ze_zeCommandQueueSynchronize_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandQueueSynchronize_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandQueueSynchronize_exit(
    void *btx_handle, lttng_ust_ze_zeCommandQueueSynchronize_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandQueueGetOrdinal_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_queue_handle_t, uint32_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandQueueGetOrdinal_entry(
    void *btx_handle, lttng_ust_ze_zeCommandQueueGetOrdinal_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandQueueGetOrdinal_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandQueueGetOrdinal_exit(
    void *btx_handle, lttng_ust_ze_zeCommandQueueGetOrdinal_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandQueueGetIndex_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_queue_handle_t, uint32_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandQueueGetIndex_entry(
    void *btx_handle, lttng_ust_ze_zeCommandQueueGetIndex_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandQueueGetIndex_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandQueueGetIndex_exit(
    void *btx_handle, lttng_ust_ze_zeCommandQueueGetIndex_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, ze_device_handle_t, ze_command_list_desc_t *, ze_command_list_handle_t *, size_t, ze_command_list_desc_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandListCreate_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListCreate_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_command_list_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListCreate_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListCreate_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListCreateImmediate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, ze_device_handle_t, ze_command_queue_desc_t *, ze_command_list_handle_t *, size_t, ze_command_queue_desc_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandListCreateImmediate_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListCreateImmediate_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListCreateImmediate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_command_list_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListCreateImmediate_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListCreateImmediate_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListDestroy_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListDestroy_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListDestroy_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListDestroy_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListClose_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListClose_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListClose_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListClose_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListClose_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListClose_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListReset_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListReset_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListReset_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListReset_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListReset_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListReset_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendWriteGlobalTimestamp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, uint64_t *, ze_event_handle_t, uint32_t, ze_event_handle_t *, size_t, ze_event_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendWriteGlobalTimestamp_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendWriteGlobalTimestamp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendWriteGlobalTimestamp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendWriteGlobalTimestamp_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendWriteGlobalTimestamp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListHostSynchronize_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, uint64_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListHostSynchronize_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListHostSynchronize_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListHostSynchronize_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListHostSynchronize_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListHostSynchronize_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListGetDeviceHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, ze_device_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandListGetDeviceHandle_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListGetDeviceHandle_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListGetDeviceHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_device_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListGetDeviceHandle_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListGetDeviceHandle_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListGetContextHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, ze_context_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandListGetContextHandle_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListGetContextHandle_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListGetContextHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_context_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListGetContextHandle_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListGetContextHandle_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListGetOrdinal_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, uint32_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandListGetOrdinal_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListGetOrdinal_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListGetOrdinal_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListGetOrdinal_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListGetOrdinal_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListImmediateGetIndex_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, uint32_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandListImmediateGetIndex_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListImmediateGetIndex_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListImmediateGetIndex_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListImmediateGetIndex_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListImmediateGetIndex_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListIsImmediate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, ze_bool_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandListIsImmediate_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListIsImmediate_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListIsImmediate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_bool_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListIsImmediate_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListIsImmediate_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendBarrier_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, ze_event_handle_t, uint32_t, ze_event_handle_t *, size_t, ze_event_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendBarrier_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendBarrier_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendBarrier_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendBarrier_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendBarrier_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendMemoryRangesBarrier_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, uint32_t, size_t *, void **, ze_event_handle_t, uint32_t, ze_event_handle_t *, size_t, size_t *, size_t, void * *, size_t, ze_event_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendMemoryRangesBarrier_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendMemoryRangesBarrier_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendMemoryRangesBarrier_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendMemoryRangesBarrier_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendMemoryRangesBarrier_exit_callback_f *callback);

typedef void lttng_ust_ze_zeContextSystemBarrier_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, ze_device_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeContextSystemBarrier_entry(
    void *btx_handle, lttng_ust_ze_zeContextSystemBarrier_entry_callback_f *callback);

typedef void lttng_ust_ze_zeContextSystemBarrier_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeContextSystemBarrier_exit(
    void *btx_handle, lttng_ust_ze_zeContextSystemBarrier_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendMemoryCopy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, void *, void *, size_t, ze_event_handle_t, uint32_t, ze_event_handle_t *, size_t, ze_event_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendMemoryCopy_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendMemoryCopy_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendMemoryCopy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendMemoryCopy_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendMemoryCopy_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendMemoryFill_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, void *, void *, size_t, size_t, ze_event_handle_t, uint32_t, ze_event_handle_t *, size_t, void *, size_t, ze_event_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendMemoryFill_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendMemoryFill_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendMemoryFill_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendMemoryFill_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendMemoryFill_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendMemoryCopyRegion_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, void *, ze_copy_region_t *, uint32_t, uint32_t, void *, ze_copy_region_t *, uint32_t, uint32_t, ze_event_handle_t, uint32_t, ze_event_handle_t *, size_t, ze_copy_region_t *, size_t, ze_copy_region_t *, size_t, ze_event_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendMemoryCopyRegion_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendMemoryCopyRegion_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendMemoryCopyRegion_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendMemoryCopyRegion_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendMemoryCopyRegion_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendMemoryCopyFromContext_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, void *, ze_context_handle_t, void *, size_t, ze_event_handle_t, uint32_t, ze_event_handle_t *, size_t, ze_event_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendMemoryCopyFromContext_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendMemoryCopyFromContext_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendMemoryCopyFromContext_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendMemoryCopyFromContext_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendMemoryCopyFromContext_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendImageCopy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, ze_image_handle_t, ze_image_handle_t, ze_event_handle_t, uint32_t, ze_event_handle_t *, size_t, ze_event_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendImageCopy_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendImageCopy_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendImageCopy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendImageCopy_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendImageCopy_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendImageCopyRegion_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, ze_image_handle_t, ze_image_handle_t, ze_image_region_t *, ze_image_region_t *, ze_event_handle_t, uint32_t, ze_event_handle_t *, size_t, ze_image_region_t *, size_t, ze_image_region_t *, size_t, ze_event_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendImageCopyRegion_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendImageCopyRegion_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendImageCopyRegion_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendImageCopyRegion_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendImageCopyRegion_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendImageCopyToMemory_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, void *, ze_image_handle_t, ze_image_region_t *, ze_event_handle_t, uint32_t, ze_event_handle_t *, size_t, ze_image_region_t *, size_t, ze_event_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendImageCopyToMemory_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendImageCopyToMemory_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendImageCopyToMemory_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendImageCopyToMemory_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendImageCopyToMemory_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendImageCopyFromMemory_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, ze_image_handle_t, void *, ze_image_region_t *, ze_event_handle_t, uint32_t, ze_event_handle_t *, size_t, ze_image_region_t *, size_t, ze_event_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendImageCopyFromMemory_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendImageCopyFromMemory_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendImageCopyFromMemory_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendImageCopyFromMemory_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendImageCopyFromMemory_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendMemoryPrefetch_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, void *, size_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendMemoryPrefetch_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendMemoryPrefetch_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendMemoryPrefetch_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendMemoryPrefetch_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendMemoryPrefetch_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendMemAdvise_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, ze_device_handle_t, void *, size_t, ze_memory_advice_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendMemAdvise_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendMemAdvise_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendMemAdvise_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendMemAdvise_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendMemAdvise_exit_callback_f *callback);

typedef void lttng_ust_ze_zeEventPoolCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, ze_event_pool_desc_t *, uint32_t, ze_device_handle_t *, ze_event_pool_handle_t *, size_t, ze_event_pool_desc_t *, size_t, ze_device_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeEventPoolCreate_entry(
    void *btx_handle, lttng_ust_ze_zeEventPoolCreate_entry_callback_f *callback);

typedef void lttng_ust_ze_zeEventPoolCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_event_pool_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeEventPoolCreate_exit(
    void *btx_handle, lttng_ust_ze_zeEventPoolCreate_exit_callback_f *callback);

typedef void lttng_ust_ze_zeEventPoolDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_event_pool_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeEventPoolDestroy_entry(
    void *btx_handle, lttng_ust_ze_zeEventPoolDestroy_entry_callback_f *callback);

typedef void lttng_ust_ze_zeEventPoolDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeEventPoolDestroy_exit(
    void *btx_handle, lttng_ust_ze_zeEventPoolDestroy_exit_callback_f *callback);

typedef void lttng_ust_ze_zeEventCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_event_pool_handle_t, ze_event_desc_t *, ze_event_handle_t *, size_t, ze_event_desc_t *);

void btx_register_callbacks_lttng_ust_ze_zeEventCreate_entry(
    void *btx_handle, lttng_ust_ze_zeEventCreate_entry_callback_f *callback);

typedef void lttng_ust_ze_zeEventCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_event_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeEventCreate_exit(
    void *btx_handle, lttng_ust_ze_zeEventCreate_exit_callback_f *callback);

typedef void lttng_ust_ze_zeEventDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_event_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeEventDestroy_entry(
    void *btx_handle, lttng_ust_ze_zeEventDestroy_entry_callback_f *callback);

typedef void lttng_ust_ze_zeEventDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeEventDestroy_exit(
    void *btx_handle, lttng_ust_ze_zeEventDestroy_exit_callback_f *callback);

typedef void lttng_ust_ze_zeEventPoolGetIpcHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_event_pool_handle_t, ze_ipc_event_pool_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeEventPoolGetIpcHandle_entry(
    void *btx_handle, lttng_ust_ze_zeEventPoolGetIpcHandle_entry_callback_f *callback);

typedef void lttng_ust_ze_zeEventPoolGetIpcHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, ze_ipc_event_pool_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeEventPoolGetIpcHandle_exit(
    void *btx_handle, lttng_ust_ze_zeEventPoolGetIpcHandle_exit_callback_f *callback);

typedef void lttng_ust_ze_zeEventPoolPutIpcHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, ze_ipc_event_pool_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeEventPoolPutIpcHandle_entry(
    void *btx_handle, lttng_ust_ze_zeEventPoolPutIpcHandle_entry_callback_f *callback);

typedef void lttng_ust_ze_zeEventPoolPutIpcHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeEventPoolPutIpcHandle_exit(
    void *btx_handle, lttng_ust_ze_zeEventPoolPutIpcHandle_exit_callback_f *callback);

typedef void lttng_ust_ze_zeEventPoolOpenIpcHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, ze_ipc_event_pool_handle_t, ze_event_pool_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeEventPoolOpenIpcHandle_entry(
    void *btx_handle, lttng_ust_ze_zeEventPoolOpenIpcHandle_entry_callback_f *callback);

typedef void lttng_ust_ze_zeEventPoolOpenIpcHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_event_pool_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeEventPoolOpenIpcHandle_exit(
    void *btx_handle, lttng_ust_ze_zeEventPoolOpenIpcHandle_exit_callback_f *callback);

typedef void lttng_ust_ze_zeEventPoolCloseIpcHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_event_pool_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeEventPoolCloseIpcHandle_entry(
    void *btx_handle, lttng_ust_ze_zeEventPoolCloseIpcHandle_entry_callback_f *callback);

typedef void lttng_ust_ze_zeEventPoolCloseIpcHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeEventPoolCloseIpcHandle_exit(
    void *btx_handle, lttng_ust_ze_zeEventPoolCloseIpcHandle_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendSignalEvent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, ze_event_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendSignalEvent_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendSignalEvent_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendSignalEvent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendSignalEvent_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendSignalEvent_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendWaitOnEvents_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, uint32_t, ze_event_handle_t *, size_t, ze_event_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendWaitOnEvents_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendWaitOnEvents_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendWaitOnEvents_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendWaitOnEvents_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendWaitOnEvents_exit_callback_f *callback);

typedef void lttng_ust_ze_zeEventHostSignal_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_event_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeEventHostSignal_entry(
    void *btx_handle, lttng_ust_ze_zeEventHostSignal_entry_callback_f *callback);

typedef void lttng_ust_ze_zeEventHostSignal_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeEventHostSignal_exit(
    void *btx_handle, lttng_ust_ze_zeEventHostSignal_exit_callback_f *callback);

typedef void lttng_ust_ze_zeEventHostSynchronize_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_event_handle_t, uint64_t);

void btx_register_callbacks_lttng_ust_ze_zeEventHostSynchronize_entry(
    void *btx_handle, lttng_ust_ze_zeEventHostSynchronize_entry_callback_f *callback);

typedef void lttng_ust_ze_zeEventHostSynchronize_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeEventHostSynchronize_exit(
    void *btx_handle, lttng_ust_ze_zeEventHostSynchronize_exit_callback_f *callback);

typedef void lttng_ust_ze_zeEventQueryStatus_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_event_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeEventQueryStatus_entry(
    void *btx_handle, lttng_ust_ze_zeEventQueryStatus_entry_callback_f *callback);

typedef void lttng_ust_ze_zeEventQueryStatus_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeEventQueryStatus_exit(
    void *btx_handle, lttng_ust_ze_zeEventQueryStatus_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendEventReset_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, ze_event_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendEventReset_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendEventReset_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendEventReset_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendEventReset_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendEventReset_exit_callback_f *callback);

typedef void lttng_ust_ze_zeEventHostReset_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_event_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeEventHostReset_entry(
    void *btx_handle, lttng_ust_ze_zeEventHostReset_entry_callback_f *callback);

typedef void lttng_ust_ze_zeEventHostReset_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeEventHostReset_exit(
    void *btx_handle, lttng_ust_ze_zeEventHostReset_exit_callback_f *callback);

typedef void lttng_ust_ze_zeEventQueryKernelTimestamp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_event_handle_t, ze_kernel_timestamp_result_t *);

void btx_register_callbacks_lttng_ust_ze_zeEventQueryKernelTimestamp_entry(
    void *btx_handle, lttng_ust_ze_zeEventQueryKernelTimestamp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeEventQueryKernelTimestamp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, ze_kernel_timestamp_result_t *);

void btx_register_callbacks_lttng_ust_ze_zeEventQueryKernelTimestamp_exit(
    void *btx_handle, lttng_ust_ze_zeEventQueryKernelTimestamp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendQueryKernelTimestamps_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, uint32_t, ze_event_handle_t *, void *, size_t *, ze_event_handle_t, uint32_t, ze_event_handle_t *, size_t, ze_event_handle_t *, size_t, size_t *, size_t, ze_event_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendQueryKernelTimestamps_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendQueryKernelTimestamps_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendQueryKernelTimestamps_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendQueryKernelTimestamps_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendQueryKernelTimestamps_exit_callback_f *callback);

typedef void lttng_ust_ze_zeEventGetEventPool_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_event_handle_t, ze_event_pool_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeEventGetEventPool_entry(
    void *btx_handle, lttng_ust_ze_zeEventGetEventPool_entry_callback_f *callback);

typedef void lttng_ust_ze_zeEventGetEventPool_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_event_pool_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeEventGetEventPool_exit(
    void *btx_handle, lttng_ust_ze_zeEventGetEventPool_exit_callback_f *callback);

typedef void lttng_ust_ze_zeEventGetSignalScope_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_event_handle_t, ze_event_scope_flags_t *);

void btx_register_callbacks_lttng_ust_ze_zeEventGetSignalScope_entry(
    void *btx_handle, lttng_ust_ze_zeEventGetSignalScope_entry_callback_f *callback);

typedef void lttng_ust_ze_zeEventGetSignalScope_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_event_scope_flags_t);

void btx_register_callbacks_lttng_ust_ze_zeEventGetSignalScope_exit(
    void *btx_handle, lttng_ust_ze_zeEventGetSignalScope_exit_callback_f *callback);

typedef void lttng_ust_ze_zeEventGetWaitScope_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_event_handle_t, ze_event_scope_flags_t *);

void btx_register_callbacks_lttng_ust_ze_zeEventGetWaitScope_entry(
    void *btx_handle, lttng_ust_ze_zeEventGetWaitScope_entry_callback_f *callback);

typedef void lttng_ust_ze_zeEventGetWaitScope_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_event_scope_flags_t);

void btx_register_callbacks_lttng_ust_ze_zeEventGetWaitScope_exit(
    void *btx_handle, lttng_ust_ze_zeEventGetWaitScope_exit_callback_f *callback);

typedef void lttng_ust_ze_zeEventPoolGetContextHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_event_pool_handle_t, ze_context_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeEventPoolGetContextHandle_entry(
    void *btx_handle, lttng_ust_ze_zeEventPoolGetContextHandle_entry_callback_f *callback);

typedef void lttng_ust_ze_zeEventPoolGetContextHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_context_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeEventPoolGetContextHandle_exit(
    void *btx_handle, lttng_ust_ze_zeEventPoolGetContextHandle_exit_callback_f *callback);

typedef void lttng_ust_ze_zeEventPoolGetFlags_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_event_pool_handle_t, ze_event_pool_flags_t *);

void btx_register_callbacks_lttng_ust_ze_zeEventPoolGetFlags_entry(
    void *btx_handle, lttng_ust_ze_zeEventPoolGetFlags_entry_callback_f *callback);

typedef void lttng_ust_ze_zeEventPoolGetFlags_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_event_pool_flags_t);

void btx_register_callbacks_lttng_ust_ze_zeEventPoolGetFlags_exit(
    void *btx_handle, lttng_ust_ze_zeEventPoolGetFlags_exit_callback_f *callback);

typedef void lttng_ust_ze_zeFenceCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_queue_handle_t, ze_fence_desc_t *, ze_fence_handle_t *, size_t, ze_fence_desc_t *);

void btx_register_callbacks_lttng_ust_ze_zeFenceCreate_entry(
    void *btx_handle, lttng_ust_ze_zeFenceCreate_entry_callback_f *callback);

typedef void lttng_ust_ze_zeFenceCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_fence_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeFenceCreate_exit(
    void *btx_handle, lttng_ust_ze_zeFenceCreate_exit_callback_f *callback);

typedef void lttng_ust_ze_zeFenceDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_fence_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeFenceDestroy_entry(
    void *btx_handle, lttng_ust_ze_zeFenceDestroy_entry_callback_f *callback);

typedef void lttng_ust_ze_zeFenceDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeFenceDestroy_exit(
    void *btx_handle, lttng_ust_ze_zeFenceDestroy_exit_callback_f *callback);

typedef void lttng_ust_ze_zeFenceHostSynchronize_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_fence_handle_t, uint64_t);

void btx_register_callbacks_lttng_ust_ze_zeFenceHostSynchronize_entry(
    void *btx_handle, lttng_ust_ze_zeFenceHostSynchronize_entry_callback_f *callback);

typedef void lttng_ust_ze_zeFenceHostSynchronize_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeFenceHostSynchronize_exit(
    void *btx_handle, lttng_ust_ze_zeFenceHostSynchronize_exit_callback_f *callback);

typedef void lttng_ust_ze_zeFenceQueryStatus_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_fence_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeFenceQueryStatus_entry(
    void *btx_handle, lttng_ust_ze_zeFenceQueryStatus_entry_callback_f *callback);

typedef void lttng_ust_ze_zeFenceQueryStatus_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeFenceQueryStatus_exit(
    void *btx_handle, lttng_ust_ze_zeFenceQueryStatus_exit_callback_f *callback);

typedef void lttng_ust_ze_zeFenceReset_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_fence_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeFenceReset_entry(
    void *btx_handle, lttng_ust_ze_zeFenceReset_entry_callback_f *callback);

typedef void lttng_ust_ze_zeFenceReset_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeFenceReset_exit(
    void *btx_handle, lttng_ust_ze_zeFenceReset_exit_callback_f *callback);

typedef void lttng_ust_ze_zeImageGetProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_handle_t, ze_image_desc_t *, ze_image_properties_t *, size_t, ze_image_desc_t *);

void btx_register_callbacks_lttng_ust_ze_zeImageGetProperties_entry(
    void *btx_handle, lttng_ust_ze_zeImageGetProperties_entry_callback_f *callback);

typedef void lttng_ust_ze_zeImageGetProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, ze_image_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeImageGetProperties_exit(
    void *btx_handle, lttng_ust_ze_zeImageGetProperties_exit_callback_f *callback);

typedef void lttng_ust_ze_zeImageCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, ze_device_handle_t, ze_image_desc_t *, ze_image_handle_t *, size_t, ze_image_desc_t *);

void btx_register_callbacks_lttng_ust_ze_zeImageCreate_entry(
    void *btx_handle, lttng_ust_ze_zeImageCreate_entry_callback_f *callback);

typedef void lttng_ust_ze_zeImageCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_image_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeImageCreate_exit(
    void *btx_handle, lttng_ust_ze_zeImageCreate_exit_callback_f *callback);

typedef void lttng_ust_ze_zeImageDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_image_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeImageDestroy_entry(
    void *btx_handle, lttng_ust_ze_zeImageDestroy_entry_callback_f *callback);

typedef void lttng_ust_ze_zeImageDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeImageDestroy_exit(
    void *btx_handle, lttng_ust_ze_zeImageDestroy_exit_callback_f *callback);

typedef void lttng_ust_ze_zeMemAllocShared_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, ze_device_mem_alloc_desc_t *, ze_host_mem_alloc_desc_t *, size_t, size_t, ze_device_handle_t, void **, size_t, ze_device_mem_alloc_desc_t *, size_t, ze_host_mem_alloc_desc_t *);

void btx_register_callbacks_lttng_ust_ze_zeMemAllocShared_entry(
    void *btx_handle, lttng_ust_ze_zeMemAllocShared_entry_callback_f *callback);

typedef void lttng_ust_ze_zeMemAllocShared_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, void *);

void btx_register_callbacks_lttng_ust_ze_zeMemAllocShared_exit(
    void *btx_handle, lttng_ust_ze_zeMemAllocShared_exit_callback_f *callback);

typedef void lttng_ust_ze_zeMemAllocDevice_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, ze_device_mem_alloc_desc_t *, size_t, size_t, ze_device_handle_t, void **, size_t, ze_device_mem_alloc_desc_t *);

void btx_register_callbacks_lttng_ust_ze_zeMemAllocDevice_entry(
    void *btx_handle, lttng_ust_ze_zeMemAllocDevice_entry_callback_f *callback);

typedef void lttng_ust_ze_zeMemAllocDevice_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, void *);

void btx_register_callbacks_lttng_ust_ze_zeMemAllocDevice_exit(
    void *btx_handle, lttng_ust_ze_zeMemAllocDevice_exit_callback_f *callback);

typedef void lttng_ust_ze_zeMemAllocHost_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, ze_host_mem_alloc_desc_t *, size_t, size_t, void **, size_t, ze_host_mem_alloc_desc_t *);

void btx_register_callbacks_lttng_ust_ze_zeMemAllocHost_entry(
    void *btx_handle, lttng_ust_ze_zeMemAllocHost_entry_callback_f *callback);

typedef void lttng_ust_ze_zeMemAllocHost_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, void *);

void btx_register_callbacks_lttng_ust_ze_zeMemAllocHost_exit(
    void *btx_handle, lttng_ust_ze_zeMemAllocHost_exit_callback_f *callback);

typedef void lttng_ust_ze_zeMemFree_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, void *);

void btx_register_callbacks_lttng_ust_ze_zeMemFree_entry(
    void *btx_handle, lttng_ust_ze_zeMemFree_entry_callback_f *callback);

typedef void lttng_ust_ze_zeMemFree_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeMemFree_exit(
    void *btx_handle, lttng_ust_ze_zeMemFree_exit_callback_f *callback);

typedef void lttng_ust_ze_zeMemGetAllocProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, void *, ze_memory_allocation_properties_t *, ze_device_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeMemGetAllocProperties_entry(
    void *btx_handle, lttng_ust_ze_zeMemGetAllocProperties_entry_callback_f *callback);

typedef void lttng_ust_ze_zeMemGetAllocProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, ze_memory_allocation_properties_t *, ze_device_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeMemGetAllocProperties_exit(
    void *btx_handle, lttng_ust_ze_zeMemGetAllocProperties_exit_callback_f *callback);

typedef void lttng_ust_ze_zeMemGetAddressRange_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, void *, void **, size_t *);

void btx_register_callbacks_lttng_ust_ze_zeMemGetAddressRange_entry(
    void *btx_handle, lttng_ust_ze_zeMemGetAddressRange_entry_callback_f *callback);

typedef void lttng_ust_ze_zeMemGetAddressRange_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, void *, size_t);

void btx_register_callbacks_lttng_ust_ze_zeMemGetAddressRange_exit(
    void *btx_handle, lttng_ust_ze_zeMemGetAddressRange_exit_callback_f *callback);

typedef void lttng_ust_ze_zeMemGetIpcHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, void *, ze_ipc_mem_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeMemGetIpcHandle_entry(
    void *btx_handle, lttng_ust_ze_zeMemGetIpcHandle_entry_callback_f *callback);

typedef void lttng_ust_ze_zeMemGetIpcHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, ze_ipc_mem_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeMemGetIpcHandle_exit(
    void *btx_handle, lttng_ust_ze_zeMemGetIpcHandle_exit_callback_f *callback);

typedef void lttng_ust_ze_zeMemGetIpcHandleFromFileDescriptorExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, uint64_t, ze_ipc_mem_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeMemGetIpcHandleFromFileDescriptorExp_entry(
    void *btx_handle, lttng_ust_ze_zeMemGetIpcHandleFromFileDescriptorExp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeMemGetIpcHandleFromFileDescriptorExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, ze_ipc_mem_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeMemGetIpcHandleFromFileDescriptorExp_exit(
    void *btx_handle, lttng_ust_ze_zeMemGetIpcHandleFromFileDescriptorExp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeMemGetFileDescriptorFromIpcHandleExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, ze_ipc_mem_handle_t, uint64_t *);

void btx_register_callbacks_lttng_ust_ze_zeMemGetFileDescriptorFromIpcHandleExp_entry(
    void *btx_handle, lttng_ust_ze_zeMemGetFileDescriptorFromIpcHandleExp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeMemGetFileDescriptorFromIpcHandleExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint64_t);

void btx_register_callbacks_lttng_ust_ze_zeMemGetFileDescriptorFromIpcHandleExp_exit(
    void *btx_handle, lttng_ust_ze_zeMemGetFileDescriptorFromIpcHandleExp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeMemPutIpcHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, ze_ipc_mem_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeMemPutIpcHandle_entry(
    void *btx_handle, lttng_ust_ze_zeMemPutIpcHandle_entry_callback_f *callback);

typedef void lttng_ust_ze_zeMemPutIpcHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeMemPutIpcHandle_exit(
    void *btx_handle, lttng_ust_ze_zeMemPutIpcHandle_exit_callback_f *callback);

typedef void lttng_ust_ze_zeMemOpenIpcHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, ze_device_handle_t, ze_ipc_mem_handle_t, ze_ipc_memory_flags_t, void **);

void btx_register_callbacks_lttng_ust_ze_zeMemOpenIpcHandle_entry(
    void *btx_handle, lttng_ust_ze_zeMemOpenIpcHandle_entry_callback_f *callback);

typedef void lttng_ust_ze_zeMemOpenIpcHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, void *);

void btx_register_callbacks_lttng_ust_ze_zeMemOpenIpcHandle_exit(
    void *btx_handle, lttng_ust_ze_zeMemOpenIpcHandle_exit_callback_f *callback);

typedef void lttng_ust_ze_zeMemCloseIpcHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, void *);

void btx_register_callbacks_lttng_ust_ze_zeMemCloseIpcHandle_entry(
    void *btx_handle, lttng_ust_ze_zeMemCloseIpcHandle_entry_callback_f *callback);

typedef void lttng_ust_ze_zeMemCloseIpcHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeMemCloseIpcHandle_exit(
    void *btx_handle, lttng_ust_ze_zeMemCloseIpcHandle_exit_callback_f *callback);

typedef void lttng_ust_ze_zeMemSetAtomicAccessAttributeExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, ze_device_handle_t, void *, size_t, ze_memory_atomic_attr_exp_flags_t);

void btx_register_callbacks_lttng_ust_ze_zeMemSetAtomicAccessAttributeExp_entry(
    void *btx_handle, lttng_ust_ze_zeMemSetAtomicAccessAttributeExp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeMemSetAtomicAccessAttributeExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeMemSetAtomicAccessAttributeExp_exit(
    void *btx_handle, lttng_ust_ze_zeMemSetAtomicAccessAttributeExp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeMemGetAtomicAccessAttributeExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, ze_device_handle_t, void *, size_t, ze_memory_atomic_attr_exp_flags_t *);

void btx_register_callbacks_lttng_ust_ze_zeMemGetAtomicAccessAttributeExp_entry(
    void *btx_handle, lttng_ust_ze_zeMemGetAtomicAccessAttributeExp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeMemGetAtomicAccessAttributeExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_memory_atomic_attr_exp_flags_t);

void btx_register_callbacks_lttng_ust_ze_zeMemGetAtomicAccessAttributeExp_exit(
    void *btx_handle, lttng_ust_ze_zeMemGetAtomicAccessAttributeExp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeModuleCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, ze_device_handle_t, ze_module_desc_t *, ze_module_handle_t *, ze_module_build_log_handle_t *, size_t, ze_module_desc_t *, char *, size_t, ze_module_constants_t *, size_t, uint32_t *, size_t, void * *);

void btx_register_callbacks_lttng_ust_ze_zeModuleCreate_entry(
    void *btx_handle, lttng_ust_ze_zeModuleCreate_entry_callback_f *callback);

typedef void lttng_ust_ze_zeModuleCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_module_handle_t, ze_module_build_log_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeModuleCreate_exit(
    void *btx_handle, lttng_ust_ze_zeModuleCreate_exit_callback_f *callback);

typedef void lttng_ust_ze_zeModuleDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_module_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeModuleDestroy_entry(
    void *btx_handle, lttng_ust_ze_zeModuleDestroy_entry_callback_f *callback);

typedef void lttng_ust_ze_zeModuleDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeModuleDestroy_exit(
    void *btx_handle, lttng_ust_ze_zeModuleDestroy_exit_callback_f *callback);

typedef void lttng_ust_ze_zeModuleDynamicLink_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, uint32_t, ze_module_handle_t *, ze_module_build_log_handle_t *, size_t, ze_module_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeModuleDynamicLink_entry(
    void *btx_handle, lttng_ust_ze_zeModuleDynamicLink_entry_callback_f *callback);

typedef void lttng_ust_ze_zeModuleDynamicLink_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_module_build_log_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeModuleDynamicLink_exit(
    void *btx_handle, lttng_ust_ze_zeModuleDynamicLink_exit_callback_f *callback);

typedef void lttng_ust_ze_zeModuleBuildLogDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_module_build_log_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeModuleBuildLogDestroy_entry(
    void *btx_handle, lttng_ust_ze_zeModuleBuildLogDestroy_entry_callback_f *callback);

typedef void lttng_ust_ze_zeModuleBuildLogDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeModuleBuildLogDestroy_exit(
    void *btx_handle, lttng_ust_ze_zeModuleBuildLogDestroy_exit_callback_f *callback);

typedef void lttng_ust_ze_zeModuleBuildLogGetString_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_module_build_log_handle_t, size_t *, char *, size_t);

void btx_register_callbacks_lttng_ust_ze_zeModuleBuildLogGetString_entry(
    void *btx_handle, lttng_ust_ze_zeModuleBuildLogGetString_entry_callback_f *callback);

typedef void lttng_ust_ze_zeModuleBuildLogGetString_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, size_t, char *);

void btx_register_callbacks_lttng_ust_ze_zeModuleBuildLogGetString_exit(
    void *btx_handle, lttng_ust_ze_zeModuleBuildLogGetString_exit_callback_f *callback);

typedef void lttng_ust_ze_zeModuleGetNativeBinary_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_module_handle_t, size_t *, uint8_t *, size_t);

void btx_register_callbacks_lttng_ust_ze_zeModuleGetNativeBinary_entry(
    void *btx_handle, lttng_ust_ze_zeModuleGetNativeBinary_entry_callback_f *callback);

typedef void lttng_ust_ze_zeModuleGetNativeBinary_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t);

void btx_register_callbacks_lttng_ust_ze_zeModuleGetNativeBinary_exit(
    void *btx_handle, lttng_ust_ze_zeModuleGetNativeBinary_exit_callback_f *callback);

typedef void lttng_ust_ze_zeModuleGetGlobalPointer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_module_handle_t, char *, size_t *, void **, char *);

void btx_register_callbacks_lttng_ust_ze_zeModuleGetGlobalPointer_entry(
    void *btx_handle, lttng_ust_ze_zeModuleGetGlobalPointer_entry_callback_f *callback);

typedef void lttng_ust_ze_zeModuleGetGlobalPointer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, void *);

void btx_register_callbacks_lttng_ust_ze_zeModuleGetGlobalPointer_exit(
    void *btx_handle, lttng_ust_ze_zeModuleGetGlobalPointer_exit_callback_f *callback);

typedef void lttng_ust_ze_zeModuleGetKernelNames_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_module_handle_t, uint32_t *, char **, uint32_t);

void btx_register_callbacks_lttng_ust_ze_zeModuleGetKernelNames_entry(
    void *btx_handle, lttng_ust_ze_zeModuleGetKernelNames_entry_callback_f *callback);

typedef void lttng_ust_ze_zeModuleGetKernelNames_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, char * *);

void btx_register_callbacks_lttng_ust_ze_zeModuleGetKernelNames_exit(
    void *btx_handle, lttng_ust_ze_zeModuleGetKernelNames_exit_callback_f *callback);

typedef void lttng_ust_ze_zeModuleGetProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_module_handle_t, ze_module_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeModuleGetProperties_entry(
    void *btx_handle, lttng_ust_ze_zeModuleGetProperties_entry_callback_f *callback);

typedef void lttng_ust_ze_zeModuleGetProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, ze_module_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeModuleGetProperties_exit(
    void *btx_handle, lttng_ust_ze_zeModuleGetProperties_exit_callback_f *callback);

typedef void lttng_ust_ze_zeKernelCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_module_handle_t, ze_kernel_desc_t *, ze_kernel_handle_t *, size_t, ze_kernel_desc_t *, char *);

void btx_register_callbacks_lttng_ust_ze_zeKernelCreate_entry(
    void *btx_handle, lttng_ust_ze_zeKernelCreate_entry_callback_f *callback);

typedef void lttng_ust_ze_zeKernelCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_kernel_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeKernelCreate_exit(
    void *btx_handle, lttng_ust_ze_zeKernelCreate_exit_callback_f *callback);

typedef void lttng_ust_ze_zeKernelDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_kernel_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeKernelDestroy_entry(
    void *btx_handle, lttng_ust_ze_zeKernelDestroy_entry_callback_f *callback);

typedef void lttng_ust_ze_zeKernelDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeKernelDestroy_exit(
    void *btx_handle, lttng_ust_ze_zeKernelDestroy_exit_callback_f *callback);

typedef void lttng_ust_ze_zeModuleGetFunctionPointer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_module_handle_t, char *, void **, char *);

void btx_register_callbacks_lttng_ust_ze_zeModuleGetFunctionPointer_entry(
    void *btx_handle, lttng_ust_ze_zeModuleGetFunctionPointer_entry_callback_f *callback);

typedef void lttng_ust_ze_zeModuleGetFunctionPointer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, void *);

void btx_register_callbacks_lttng_ust_ze_zeModuleGetFunctionPointer_exit(
    void *btx_handle, lttng_ust_ze_zeModuleGetFunctionPointer_exit_callback_f *callback);

typedef void lttng_ust_ze_zeKernelSetGroupSize_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_kernel_handle_t, uint32_t, uint32_t, uint32_t);

void btx_register_callbacks_lttng_ust_ze_zeKernelSetGroupSize_entry(
    void *btx_handle, lttng_ust_ze_zeKernelSetGroupSize_entry_callback_f *callback);

typedef void lttng_ust_ze_zeKernelSetGroupSize_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeKernelSetGroupSize_exit(
    void *btx_handle, lttng_ust_ze_zeKernelSetGroupSize_exit_callback_f *callback);

typedef void lttng_ust_ze_zeKernelSuggestGroupSize_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_kernel_handle_t, uint32_t, uint32_t, uint32_t, uint32_t *, uint32_t *, uint32_t *);

void btx_register_callbacks_lttng_ust_ze_zeKernelSuggestGroupSize_entry(
    void *btx_handle, lttng_ust_ze_zeKernelSuggestGroupSize_entry_callback_f *callback);

typedef void lttng_ust_ze_zeKernelSuggestGroupSize_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, uint32_t, uint32_t);

void btx_register_callbacks_lttng_ust_ze_zeKernelSuggestGroupSize_exit(
    void *btx_handle, lttng_ust_ze_zeKernelSuggestGroupSize_exit_callback_f *callback);

typedef void lttng_ust_ze_zeKernelSuggestMaxCooperativeGroupCount_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_kernel_handle_t, uint32_t *);

void btx_register_callbacks_lttng_ust_ze_zeKernelSuggestMaxCooperativeGroupCount_entry(
    void *btx_handle, lttng_ust_ze_zeKernelSuggestMaxCooperativeGroupCount_entry_callback_f *callback);

typedef void lttng_ust_ze_zeKernelSuggestMaxCooperativeGroupCount_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t);

void btx_register_callbacks_lttng_ust_ze_zeKernelSuggestMaxCooperativeGroupCount_exit(
    void *btx_handle, lttng_ust_ze_zeKernelSuggestMaxCooperativeGroupCount_exit_callback_f *callback);

typedef void lttng_ust_ze_zeKernelSetArgumentValue_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_kernel_handle_t, uint32_t, size_t, void *, size_t, void *);

void btx_register_callbacks_lttng_ust_ze_zeKernelSetArgumentValue_entry(
    void *btx_handle, lttng_ust_ze_zeKernelSetArgumentValue_entry_callback_f *callback);

typedef void lttng_ust_ze_zeKernelSetArgumentValue_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeKernelSetArgumentValue_exit(
    void *btx_handle, lttng_ust_ze_zeKernelSetArgumentValue_exit_callback_f *callback);

typedef void lttng_ust_ze_zeKernelSetIndirectAccess_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_kernel_handle_t, ze_kernel_indirect_access_flags_t);

void btx_register_callbacks_lttng_ust_ze_zeKernelSetIndirectAccess_entry(
    void *btx_handle, lttng_ust_ze_zeKernelSetIndirectAccess_entry_callback_f *callback);

typedef void lttng_ust_ze_zeKernelSetIndirectAccess_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeKernelSetIndirectAccess_exit(
    void *btx_handle, lttng_ust_ze_zeKernelSetIndirectAccess_exit_callback_f *callback);

typedef void lttng_ust_ze_zeKernelGetIndirectAccess_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_kernel_handle_t, ze_kernel_indirect_access_flags_t *);

void btx_register_callbacks_lttng_ust_ze_zeKernelGetIndirectAccess_entry(
    void *btx_handle, lttng_ust_ze_zeKernelGetIndirectAccess_entry_callback_f *callback);

typedef void lttng_ust_ze_zeKernelGetIndirectAccess_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_kernel_indirect_access_flags_t);

void btx_register_callbacks_lttng_ust_ze_zeKernelGetIndirectAccess_exit(
    void *btx_handle, lttng_ust_ze_zeKernelGetIndirectAccess_exit_callback_f *callback);

typedef void lttng_ust_ze_zeKernelGetSourceAttributes_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_kernel_handle_t, uint32_t *, char **, uint32_t, char *);

void btx_register_callbacks_lttng_ust_ze_zeKernelGetSourceAttributes_entry(
    void *btx_handle, lttng_ust_ze_zeKernelGetSourceAttributes_entry_callback_f *callback);

typedef void lttng_ust_ze_zeKernelGetSourceAttributes_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, char *);

void btx_register_callbacks_lttng_ust_ze_zeKernelGetSourceAttributes_exit(
    void *btx_handle, lttng_ust_ze_zeKernelGetSourceAttributes_exit_callback_f *callback);

typedef void lttng_ust_ze_zeKernelSetCacheConfig_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_kernel_handle_t, ze_cache_config_flags_t);

void btx_register_callbacks_lttng_ust_ze_zeKernelSetCacheConfig_entry(
    void *btx_handle, lttng_ust_ze_zeKernelSetCacheConfig_entry_callback_f *callback);

typedef void lttng_ust_ze_zeKernelSetCacheConfig_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeKernelSetCacheConfig_exit(
    void *btx_handle, lttng_ust_ze_zeKernelSetCacheConfig_exit_callback_f *callback);

typedef void lttng_ust_ze_zeKernelGetProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_kernel_handle_t, ze_kernel_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeKernelGetProperties_entry(
    void *btx_handle, lttng_ust_ze_zeKernelGetProperties_entry_callback_f *callback);

typedef void lttng_ust_ze_zeKernelGetProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, ze_kernel_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeKernelGetProperties_exit(
    void *btx_handle, lttng_ust_ze_zeKernelGetProperties_exit_callback_f *callback);

typedef void lttng_ust_ze_zeKernelGetName_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_kernel_handle_t, size_t *, char *, size_t);

void btx_register_callbacks_lttng_ust_ze_zeKernelGetName_entry(
    void *btx_handle, lttng_ust_ze_zeKernelGetName_entry_callback_f *callback);

typedef void lttng_ust_ze_zeKernelGetName_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, size_t, char *);

void btx_register_callbacks_lttng_ust_ze_zeKernelGetName_exit(
    void *btx_handle, lttng_ust_ze_zeKernelGetName_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendLaunchKernel_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, ze_kernel_handle_t, ze_group_count_t *, ze_event_handle_t, uint32_t, ze_event_handle_t *, size_t, ze_group_count_t *, size_t, ze_event_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendLaunchKernel_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendLaunchKernel_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendLaunchKernel_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendLaunchKernel_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendLaunchKernel_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendLaunchCooperativeKernel_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, ze_kernel_handle_t, ze_group_count_t *, ze_event_handle_t, uint32_t, ze_event_handle_t *, size_t, ze_group_count_t *, size_t, ze_event_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendLaunchCooperativeKernel_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendLaunchCooperativeKernel_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendLaunchCooperativeKernel_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendLaunchCooperativeKernel_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendLaunchCooperativeKernel_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendLaunchKernelIndirect_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, ze_kernel_handle_t, ze_group_count_t *, ze_event_handle_t, uint32_t, ze_event_handle_t *, size_t, ze_event_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendLaunchKernelIndirect_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendLaunchKernelIndirect_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendLaunchKernelIndirect_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendLaunchKernelIndirect_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendLaunchKernelIndirect_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendLaunchMultipleKernelsIndirect_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, uint32_t, ze_kernel_handle_t *, uint32_t *, ze_group_count_t *, ze_event_handle_t, uint32_t, ze_event_handle_t *, size_t, ze_kernel_handle_t *, size_t, ze_event_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendLaunchMultipleKernelsIndirect_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendLaunchMultipleKernelsIndirect_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendLaunchMultipleKernelsIndirect_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendLaunchMultipleKernelsIndirect_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendLaunchMultipleKernelsIndirect_exit_callback_f *callback);

typedef void lttng_ust_ze_zeContextMakeMemoryResident_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, ze_device_handle_t, void *, size_t);

void btx_register_callbacks_lttng_ust_ze_zeContextMakeMemoryResident_entry(
    void *btx_handle, lttng_ust_ze_zeContextMakeMemoryResident_entry_callback_f *callback);

typedef void lttng_ust_ze_zeContextMakeMemoryResident_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeContextMakeMemoryResident_exit(
    void *btx_handle, lttng_ust_ze_zeContextMakeMemoryResident_exit_callback_f *callback);

typedef void lttng_ust_ze_zeContextEvictMemory_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, ze_device_handle_t, void *, size_t);

void btx_register_callbacks_lttng_ust_ze_zeContextEvictMemory_entry(
    void *btx_handle, lttng_ust_ze_zeContextEvictMemory_entry_callback_f *callback);

typedef void lttng_ust_ze_zeContextEvictMemory_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeContextEvictMemory_exit(
    void *btx_handle, lttng_ust_ze_zeContextEvictMemory_exit_callback_f *callback);

typedef void lttng_ust_ze_zeContextMakeImageResident_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, ze_device_handle_t, ze_image_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeContextMakeImageResident_entry(
    void *btx_handle, lttng_ust_ze_zeContextMakeImageResident_entry_callback_f *callback);

typedef void lttng_ust_ze_zeContextMakeImageResident_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeContextMakeImageResident_exit(
    void *btx_handle, lttng_ust_ze_zeContextMakeImageResident_exit_callback_f *callback);

typedef void lttng_ust_ze_zeContextEvictImage_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, ze_device_handle_t, ze_image_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeContextEvictImage_entry(
    void *btx_handle, lttng_ust_ze_zeContextEvictImage_entry_callback_f *callback);

typedef void lttng_ust_ze_zeContextEvictImage_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeContextEvictImage_exit(
    void *btx_handle, lttng_ust_ze_zeContextEvictImage_exit_callback_f *callback);

typedef void lttng_ust_ze_zeSamplerCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, ze_device_handle_t, ze_sampler_desc_t *, ze_sampler_handle_t *, size_t, ze_sampler_desc_t *);

void btx_register_callbacks_lttng_ust_ze_zeSamplerCreate_entry(
    void *btx_handle, lttng_ust_ze_zeSamplerCreate_entry_callback_f *callback);

typedef void lttng_ust_ze_zeSamplerCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_sampler_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeSamplerCreate_exit(
    void *btx_handle, lttng_ust_ze_zeSamplerCreate_exit_callback_f *callback);

typedef void lttng_ust_ze_zeSamplerDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_sampler_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeSamplerDestroy_entry(
    void *btx_handle, lttng_ust_ze_zeSamplerDestroy_entry_callback_f *callback);

typedef void lttng_ust_ze_zeSamplerDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeSamplerDestroy_exit(
    void *btx_handle, lttng_ust_ze_zeSamplerDestroy_exit_callback_f *callback);

typedef void lttng_ust_ze_zeVirtualMemReserve_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, void *, size_t, void **);

void btx_register_callbacks_lttng_ust_ze_zeVirtualMemReserve_entry(
    void *btx_handle, lttng_ust_ze_zeVirtualMemReserve_entry_callback_f *callback);

typedef void lttng_ust_ze_zeVirtualMemReserve_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, void *);

void btx_register_callbacks_lttng_ust_ze_zeVirtualMemReserve_exit(
    void *btx_handle, lttng_ust_ze_zeVirtualMemReserve_exit_callback_f *callback);

typedef void lttng_ust_ze_zeVirtualMemFree_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, void *, size_t);

void btx_register_callbacks_lttng_ust_ze_zeVirtualMemFree_entry(
    void *btx_handle, lttng_ust_ze_zeVirtualMemFree_entry_callback_f *callback);

typedef void lttng_ust_ze_zeVirtualMemFree_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeVirtualMemFree_exit(
    void *btx_handle, lttng_ust_ze_zeVirtualMemFree_exit_callback_f *callback);

typedef void lttng_ust_ze_zeVirtualMemQueryPageSize_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, ze_device_handle_t, size_t, size_t *);

void btx_register_callbacks_lttng_ust_ze_zeVirtualMemQueryPageSize_entry(
    void *btx_handle, lttng_ust_ze_zeVirtualMemQueryPageSize_entry_callback_f *callback);

typedef void lttng_ust_ze_zeVirtualMemQueryPageSize_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t);

void btx_register_callbacks_lttng_ust_ze_zeVirtualMemQueryPageSize_exit(
    void *btx_handle, lttng_ust_ze_zeVirtualMemQueryPageSize_exit_callback_f *callback);

typedef void lttng_ust_ze_zePhysicalMemCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, ze_device_handle_t, ze_physical_mem_desc_t *, ze_physical_mem_handle_t *, size_t, ze_physical_mem_desc_t *);

void btx_register_callbacks_lttng_ust_ze_zePhysicalMemCreate_entry(
    void *btx_handle, lttng_ust_ze_zePhysicalMemCreate_entry_callback_f *callback);

typedef void lttng_ust_ze_zePhysicalMemCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_physical_mem_handle_t);

void btx_register_callbacks_lttng_ust_ze_zePhysicalMemCreate_exit(
    void *btx_handle, lttng_ust_ze_zePhysicalMemCreate_exit_callback_f *callback);

typedef void lttng_ust_ze_zePhysicalMemDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, ze_physical_mem_handle_t);

void btx_register_callbacks_lttng_ust_ze_zePhysicalMemDestroy_entry(
    void *btx_handle, lttng_ust_ze_zePhysicalMemDestroy_entry_callback_f *callback);

typedef void lttng_ust_ze_zePhysicalMemDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zePhysicalMemDestroy_exit(
    void *btx_handle, lttng_ust_ze_zePhysicalMemDestroy_exit_callback_f *callback);

typedef void lttng_ust_ze_zeVirtualMemMap_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, void *, size_t, ze_physical_mem_handle_t, size_t, ze_memory_access_attribute_t);

void btx_register_callbacks_lttng_ust_ze_zeVirtualMemMap_entry(
    void *btx_handle, lttng_ust_ze_zeVirtualMemMap_entry_callback_f *callback);

typedef void lttng_ust_ze_zeVirtualMemMap_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeVirtualMemMap_exit(
    void *btx_handle, lttng_ust_ze_zeVirtualMemMap_exit_callback_f *callback);

typedef void lttng_ust_ze_zeVirtualMemUnmap_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, void *, size_t);

void btx_register_callbacks_lttng_ust_ze_zeVirtualMemUnmap_entry(
    void *btx_handle, lttng_ust_ze_zeVirtualMemUnmap_entry_callback_f *callback);

typedef void lttng_ust_ze_zeVirtualMemUnmap_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeVirtualMemUnmap_exit(
    void *btx_handle, lttng_ust_ze_zeVirtualMemUnmap_exit_callback_f *callback);

typedef void lttng_ust_ze_zeVirtualMemSetAccessAttribute_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, void *, size_t, ze_memory_access_attribute_t);

void btx_register_callbacks_lttng_ust_ze_zeVirtualMemSetAccessAttribute_entry(
    void *btx_handle, lttng_ust_ze_zeVirtualMemSetAccessAttribute_entry_callback_f *callback);

typedef void lttng_ust_ze_zeVirtualMemSetAccessAttribute_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeVirtualMemSetAccessAttribute_exit(
    void *btx_handle, lttng_ust_ze_zeVirtualMemSetAccessAttribute_exit_callback_f *callback);

typedef void lttng_ust_ze_zeVirtualMemGetAccessAttribute_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, void *, size_t, ze_memory_access_attribute_t *, size_t *);

void btx_register_callbacks_lttng_ust_ze_zeVirtualMemGetAccessAttribute_entry(
    void *btx_handle, lttng_ust_ze_zeVirtualMemGetAccessAttribute_entry_callback_f *callback);

typedef void lttng_ust_ze_zeVirtualMemGetAccessAttribute_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_memory_access_attribute_t, size_t);

void btx_register_callbacks_lttng_ust_ze_zeVirtualMemGetAccessAttribute_exit(
    void *btx_handle, lttng_ust_ze_zeVirtualMemGetAccessAttribute_exit_callback_f *callback);

typedef void lttng_ust_ze_zeKernelSetGlobalOffsetExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_kernel_handle_t, uint32_t, uint32_t, uint32_t);

void btx_register_callbacks_lttng_ust_ze_zeKernelSetGlobalOffsetExp_entry(
    void *btx_handle, lttng_ust_ze_zeKernelSetGlobalOffsetExp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeKernelSetGlobalOffsetExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeKernelSetGlobalOffsetExp_exit(
    void *btx_handle, lttng_ust_ze_zeKernelSetGlobalOffsetExp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeKernelGetBinaryExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_kernel_handle_t, size_t *, uint8_t *, size_t);

void btx_register_callbacks_lttng_ust_ze_zeKernelGetBinaryExp_entry(
    void *btx_handle, lttng_ust_ze_zeKernelGetBinaryExp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeKernelGetBinaryExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, size_t, uint8_t *);

void btx_register_callbacks_lttng_ust_ze_zeKernelGetBinaryExp_exit(
    void *btx_handle, lttng_ust_ze_zeKernelGetBinaryExp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceImportExternalSemaphoreExt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_handle_t, ze_external_semaphore_ext_desc_t *, ze_external_semaphore_ext_handle_t *, size_t, ze_external_semaphore_ext_desc_t *);

void btx_register_callbacks_lttng_ust_ze_zeDeviceImportExternalSemaphoreExt_entry(
    void *btx_handle, lttng_ust_ze_zeDeviceImportExternalSemaphoreExt_entry_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceImportExternalSemaphoreExt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_external_semaphore_ext_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeDeviceImportExternalSemaphoreExt_exit(
    void *btx_handle, lttng_ust_ze_zeDeviceImportExternalSemaphoreExt_exit_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceReleaseExternalSemaphoreExt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_external_semaphore_ext_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeDeviceReleaseExternalSemaphoreExt_entry(
    void *btx_handle, lttng_ust_ze_zeDeviceReleaseExternalSemaphoreExt_entry_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceReleaseExternalSemaphoreExt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeDeviceReleaseExternalSemaphoreExt_exit(
    void *btx_handle, lttng_ust_ze_zeDeviceReleaseExternalSemaphoreExt_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendSignalExternalSemaphoreExt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, uint32_t, ze_external_semaphore_ext_handle_t *, ze_external_semaphore_signal_params_ext_t *, ze_event_handle_t, uint32_t, ze_event_handle_t *, size_t, ze_external_semaphore_ext_handle_t *, size_t, ze_external_semaphore_signal_params_ext_t *, size_t, ze_event_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendSignalExternalSemaphoreExt_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendSignalExternalSemaphoreExt_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendSignalExternalSemaphoreExt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendSignalExternalSemaphoreExt_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendSignalExternalSemaphoreExt_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendWaitExternalSemaphoreExt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, uint32_t, ze_external_semaphore_ext_handle_t *, ze_external_semaphore_wait_params_ext_t *, ze_event_handle_t, uint32_t, ze_event_handle_t *, size_t, ze_external_semaphore_ext_handle_t *, size_t, ze_external_semaphore_wait_params_ext_t *, size_t, ze_event_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendWaitExternalSemaphoreExt_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendWaitExternalSemaphoreExt_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendWaitExternalSemaphoreExt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendWaitExternalSemaphoreExt_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendWaitExternalSemaphoreExt_exit_callback_f *callback);

typedef void lttng_ust_ze_zeRTASBuilderCreateExt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_driver_handle_t, ze_rtas_builder_ext_desc_t *, ze_rtas_builder_ext_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeRTASBuilderCreateExt_entry(
    void *btx_handle, lttng_ust_ze_zeRTASBuilderCreateExt_entry_callback_f *callback);

typedef void lttng_ust_ze_zeRTASBuilderCreateExt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeRTASBuilderCreateExt_exit(
    void *btx_handle, lttng_ust_ze_zeRTASBuilderCreateExt_exit_callback_f *callback);

typedef void lttng_ust_ze_zeRTASBuilderGetBuildPropertiesExt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_rtas_builder_ext_handle_t, ze_rtas_builder_build_op_ext_desc_t *, ze_rtas_builder_ext_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeRTASBuilderGetBuildPropertiesExt_entry(
    void *btx_handle, lttng_ust_ze_zeRTASBuilderGetBuildPropertiesExt_entry_callback_f *callback);

typedef void lttng_ust_ze_zeRTASBuilderGetBuildPropertiesExt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeRTASBuilderGetBuildPropertiesExt_exit(
    void *btx_handle, lttng_ust_ze_zeRTASBuilderGetBuildPropertiesExt_exit_callback_f *callback);

typedef void lttng_ust_ze_zeDriverRTASFormatCompatibilityCheckExt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_driver_handle_t, ze_rtas_format_ext_t, ze_rtas_format_ext_t);

void btx_register_callbacks_lttng_ust_ze_zeDriverRTASFormatCompatibilityCheckExt_entry(
    void *btx_handle, lttng_ust_ze_zeDriverRTASFormatCompatibilityCheckExt_entry_callback_f *callback);

typedef void lttng_ust_ze_zeDriverRTASFormatCompatibilityCheckExt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeDriverRTASFormatCompatibilityCheckExt_exit(
    void *btx_handle, lttng_ust_ze_zeDriverRTASFormatCompatibilityCheckExt_exit_callback_f *callback);

typedef void lttng_ust_ze_zeRTASBuilderBuildExt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_rtas_builder_ext_handle_t, ze_rtas_builder_build_op_ext_desc_t *, void *, size_t, void *, size_t, ze_rtas_parallel_operation_ext_handle_t, void *, ze_rtas_aabb_ext_t *, size_t *);

void btx_register_callbacks_lttng_ust_ze_zeRTASBuilderBuildExt_entry(
    void *btx_handle, lttng_ust_ze_zeRTASBuilderBuildExt_entry_callback_f *callback);

typedef void lttng_ust_ze_zeRTASBuilderBuildExt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeRTASBuilderBuildExt_exit(
    void *btx_handle, lttng_ust_ze_zeRTASBuilderBuildExt_exit_callback_f *callback);

typedef void lttng_ust_ze_zeRTASBuilderCommandListAppendCopyExt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, void *, void *, size_t, ze_event_handle_t, uint32_t, ze_event_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeRTASBuilderCommandListAppendCopyExt_entry(
    void *btx_handle, lttng_ust_ze_zeRTASBuilderCommandListAppendCopyExt_entry_callback_f *callback);

typedef void lttng_ust_ze_zeRTASBuilderCommandListAppendCopyExt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeRTASBuilderCommandListAppendCopyExt_exit(
    void *btx_handle, lttng_ust_ze_zeRTASBuilderCommandListAppendCopyExt_exit_callback_f *callback);

typedef void lttng_ust_ze_zeRTASBuilderDestroyExt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_rtas_builder_ext_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeRTASBuilderDestroyExt_entry(
    void *btx_handle, lttng_ust_ze_zeRTASBuilderDestroyExt_entry_callback_f *callback);

typedef void lttng_ust_ze_zeRTASBuilderDestroyExt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeRTASBuilderDestroyExt_exit(
    void *btx_handle, lttng_ust_ze_zeRTASBuilderDestroyExt_exit_callback_f *callback);

typedef void lttng_ust_ze_zeRTASParallelOperationCreateExt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_driver_handle_t, ze_rtas_parallel_operation_ext_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeRTASParallelOperationCreateExt_entry(
    void *btx_handle, lttng_ust_ze_zeRTASParallelOperationCreateExt_entry_callback_f *callback);

typedef void lttng_ust_ze_zeRTASParallelOperationCreateExt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeRTASParallelOperationCreateExt_exit(
    void *btx_handle, lttng_ust_ze_zeRTASParallelOperationCreateExt_exit_callback_f *callback);

typedef void lttng_ust_ze_zeRTASParallelOperationGetPropertiesExt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_rtas_parallel_operation_ext_handle_t, ze_rtas_parallel_operation_ext_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeRTASParallelOperationGetPropertiesExt_entry(
    void *btx_handle, lttng_ust_ze_zeRTASParallelOperationGetPropertiesExt_entry_callback_f *callback);

typedef void lttng_ust_ze_zeRTASParallelOperationGetPropertiesExt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeRTASParallelOperationGetPropertiesExt_exit(
    void *btx_handle, lttng_ust_ze_zeRTASParallelOperationGetPropertiesExt_exit_callback_f *callback);

typedef void lttng_ust_ze_zeRTASParallelOperationJoinExt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_rtas_parallel_operation_ext_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeRTASParallelOperationJoinExt_entry(
    void *btx_handle, lttng_ust_ze_zeRTASParallelOperationJoinExt_entry_callback_f *callback);

typedef void lttng_ust_ze_zeRTASParallelOperationJoinExt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeRTASParallelOperationJoinExt_exit(
    void *btx_handle, lttng_ust_ze_zeRTASParallelOperationJoinExt_exit_callback_f *callback);

typedef void lttng_ust_ze_zeRTASParallelOperationDestroyExt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_rtas_parallel_operation_ext_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeRTASParallelOperationDestroyExt_entry(
    void *btx_handle, lttng_ust_ze_zeRTASParallelOperationDestroyExt_entry_callback_f *callback);

typedef void lttng_ust_ze_zeRTASParallelOperationDestroyExt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeRTASParallelOperationDestroyExt_exit(
    void *btx_handle, lttng_ust_ze_zeRTASParallelOperationDestroyExt_exit_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceGetVectorWidthPropertiesExt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_handle_t, uint32_t *, ze_device_vector_width_properties_ext_t *, uint32_t);

void btx_register_callbacks_lttng_ust_ze_zeDeviceGetVectorWidthPropertiesExt_entry(
    void *btx_handle, lttng_ust_ze_zeDeviceGetVectorWidthPropertiesExt_entry_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceGetVectorWidthPropertiesExt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, ze_device_vector_width_properties_ext_t *);

void btx_register_callbacks_lttng_ust_ze_zeDeviceGetVectorWidthPropertiesExt_exit(
    void *btx_handle, lttng_ust_ze_zeDeviceGetVectorWidthPropertiesExt_exit_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceReserveCacheExt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_handle_t, size_t, size_t);

void btx_register_callbacks_lttng_ust_ze_zeDeviceReserveCacheExt_entry(
    void *btx_handle, lttng_ust_ze_zeDeviceReserveCacheExt_entry_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceReserveCacheExt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeDeviceReserveCacheExt_exit(
    void *btx_handle, lttng_ust_ze_zeDeviceReserveCacheExt_exit_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceSetCacheAdviceExt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_handle_t, void *, size_t, ze_cache_ext_region_t);

void btx_register_callbacks_lttng_ust_ze_zeDeviceSetCacheAdviceExt_entry(
    void *btx_handle, lttng_ust_ze_zeDeviceSetCacheAdviceExt_entry_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceSetCacheAdviceExt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeDeviceSetCacheAdviceExt_exit(
    void *btx_handle, lttng_ust_ze_zeDeviceSetCacheAdviceExt_exit_callback_f *callback);

typedef void lttng_ust_ze_zeEventQueryTimestampsExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_event_handle_t, ze_device_handle_t, uint32_t *, ze_kernel_timestamp_result_t *, uint32_t);

void btx_register_callbacks_lttng_ust_ze_zeEventQueryTimestampsExp_entry(
    void *btx_handle, lttng_ust_ze_zeEventQueryTimestampsExp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeEventQueryTimestampsExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, ze_kernel_timestamp_result_t *);

void btx_register_callbacks_lttng_ust_ze_zeEventQueryTimestampsExp_exit(
    void *btx_handle, lttng_ust_ze_zeEventQueryTimestampsExp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeImageGetMemoryPropertiesExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_image_handle_t, ze_image_memory_properties_exp_t *);

void btx_register_callbacks_lttng_ust_ze_zeImageGetMemoryPropertiesExp_entry(
    void *btx_handle, lttng_ust_ze_zeImageGetMemoryPropertiesExp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeImageGetMemoryPropertiesExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, ze_image_memory_properties_exp_t *);

void btx_register_callbacks_lttng_ust_ze_zeImageGetMemoryPropertiesExp_exit(
    void *btx_handle, lttng_ust_ze_zeImageGetMemoryPropertiesExp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeImageViewCreateExt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, ze_device_handle_t, ze_image_desc_t *, ze_image_handle_t, ze_image_handle_t *, size_t, ze_image_desc_t *);

void btx_register_callbacks_lttng_ust_ze_zeImageViewCreateExt_entry(
    void *btx_handle, lttng_ust_ze_zeImageViewCreateExt_entry_callback_f *callback);

typedef void lttng_ust_ze_zeImageViewCreateExt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_image_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeImageViewCreateExt_exit(
    void *btx_handle, lttng_ust_ze_zeImageViewCreateExt_exit_callback_f *callback);

typedef void lttng_ust_ze_zeImageViewCreateExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, ze_device_handle_t, ze_image_desc_t *, ze_image_handle_t, ze_image_handle_t *, size_t, ze_image_desc_t *);

void btx_register_callbacks_lttng_ust_ze_zeImageViewCreateExp_entry(
    void *btx_handle, lttng_ust_ze_zeImageViewCreateExp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeImageViewCreateExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_image_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeImageViewCreateExp_exit(
    void *btx_handle, lttng_ust_ze_zeImageViewCreateExp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeKernelSchedulingHintExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_kernel_handle_t, ze_scheduling_hint_exp_desc_t *, size_t, ze_scheduling_hint_exp_desc_t *);

void btx_register_callbacks_lttng_ust_ze_zeKernelSchedulingHintExp_entry(
    void *btx_handle, lttng_ust_ze_zeKernelSchedulingHintExp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeKernelSchedulingHintExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeKernelSchedulingHintExp_exit(
    void *btx_handle, lttng_ust_ze_zeKernelSchedulingHintExp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeDevicePciGetPropertiesExt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_handle_t, ze_pci_ext_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeDevicePciGetPropertiesExt_entry(
    void *btx_handle, lttng_ust_ze_zeDevicePciGetPropertiesExt_entry_callback_f *callback);

typedef void lttng_ust_ze_zeDevicePciGetPropertiesExt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, ze_pci_ext_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeDevicePciGetPropertiesExt_exit(
    void *btx_handle, lttng_ust_ze_zeDevicePciGetPropertiesExt_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendImageCopyToMemoryExt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, void *, ze_image_handle_t, ze_image_region_t *, uint32_t, uint32_t, ze_event_handle_t, uint32_t, ze_event_handle_t *, size_t, ze_image_region_t *, size_t, ze_event_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendImageCopyToMemoryExt_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendImageCopyToMemoryExt_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendImageCopyToMemoryExt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendImageCopyToMemoryExt_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendImageCopyToMemoryExt_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendImageCopyFromMemoryExt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, ze_image_handle_t, void *, ze_image_region_t *, uint32_t, uint32_t, ze_event_handle_t, uint32_t, ze_event_handle_t *, size_t, ze_image_region_t *, size_t, ze_event_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendImageCopyFromMemoryExt_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendImageCopyFromMemoryExt_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListAppendImageCopyFromMemoryExt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListAppendImageCopyFromMemoryExt_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListAppendImageCopyFromMemoryExt_exit_callback_f *callback);

typedef void lttng_ust_ze_zeImageGetAllocPropertiesExt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, ze_image_handle_t, ze_image_allocation_ext_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeImageGetAllocPropertiesExt_entry(
    void *btx_handle, lttng_ust_ze_zeImageGetAllocPropertiesExt_entry_callback_f *callback);

typedef void lttng_ust_ze_zeImageGetAllocPropertiesExt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, ze_image_allocation_ext_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeImageGetAllocPropertiesExt_exit(
    void *btx_handle, lttng_ust_ze_zeImageGetAllocPropertiesExt_exit_callback_f *callback);

typedef void lttng_ust_ze_zeModuleInspectLinkageExt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_linkage_inspection_ext_desc_t *, uint32_t, ze_module_handle_t *, ze_module_build_log_handle_t *, size_t, ze_linkage_inspection_ext_desc_t *, size_t, ze_module_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeModuleInspectLinkageExt_entry(
    void *btx_handle, lttng_ust_ze_zeModuleInspectLinkageExt_entry_callback_f *callback);

typedef void lttng_ust_ze_zeModuleInspectLinkageExt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_module_build_log_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeModuleInspectLinkageExt_exit(
    void *btx_handle, lttng_ust_ze_zeModuleInspectLinkageExt_exit_callback_f *callback);

typedef void lttng_ust_ze_zeMemFreeExt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, ze_memory_free_ext_desc_t *, void *, size_t, ze_memory_free_ext_desc_t *);

void btx_register_callbacks_lttng_ust_ze_zeMemFreeExt_entry(
    void *btx_handle, lttng_ust_ze_zeMemFreeExt_entry_callback_f *callback);

typedef void lttng_ust_ze_zeMemFreeExt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeMemFreeExt_exit(
    void *btx_handle, lttng_ust_ze_zeMemFreeExt_exit_callback_f *callback);

typedef void lttng_ust_ze_zeFabricVertexGetExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_driver_handle_t, uint32_t *, ze_fabric_vertex_handle_t *, uint32_t);

void btx_register_callbacks_lttng_ust_ze_zeFabricVertexGetExp_entry(
    void *btx_handle, lttng_ust_ze_zeFabricVertexGetExp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeFabricVertexGetExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, ze_fabric_vertex_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeFabricVertexGetExp_exit(
    void *btx_handle, lttng_ust_ze_zeFabricVertexGetExp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeFabricVertexGetSubVerticesExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_fabric_vertex_handle_t, uint32_t *, ze_fabric_vertex_handle_t *, uint32_t);

void btx_register_callbacks_lttng_ust_ze_zeFabricVertexGetSubVerticesExp_entry(
    void *btx_handle, lttng_ust_ze_zeFabricVertexGetSubVerticesExp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeFabricVertexGetSubVerticesExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, ze_fabric_vertex_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeFabricVertexGetSubVerticesExp_exit(
    void *btx_handle, lttng_ust_ze_zeFabricVertexGetSubVerticesExp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeFabricVertexGetPropertiesExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_fabric_vertex_handle_t, ze_fabric_vertex_exp_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeFabricVertexGetPropertiesExp_entry(
    void *btx_handle, lttng_ust_ze_zeFabricVertexGetPropertiesExp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeFabricVertexGetPropertiesExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, ze_fabric_vertex_exp_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeFabricVertexGetPropertiesExp_exit(
    void *btx_handle, lttng_ust_ze_zeFabricVertexGetPropertiesExp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeFabricVertexGetDeviceExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_fabric_vertex_handle_t, ze_device_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeFabricVertexGetDeviceExp_entry(
    void *btx_handle, lttng_ust_ze_zeFabricVertexGetDeviceExp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeFabricVertexGetDeviceExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_device_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeFabricVertexGetDeviceExp_exit(
    void *btx_handle, lttng_ust_ze_zeFabricVertexGetDeviceExp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceGetFabricVertexExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_handle_t, ze_fabric_vertex_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeDeviceGetFabricVertexExp_entry(
    void *btx_handle, lttng_ust_ze_zeDeviceGetFabricVertexExp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeDeviceGetFabricVertexExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_fabric_vertex_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeDeviceGetFabricVertexExp_exit(
    void *btx_handle, lttng_ust_ze_zeDeviceGetFabricVertexExp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeFabricEdgeGetExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_fabric_vertex_handle_t, ze_fabric_vertex_handle_t, uint32_t *, ze_fabric_edge_handle_t *, uint32_t);

void btx_register_callbacks_lttng_ust_ze_zeFabricEdgeGetExp_entry(
    void *btx_handle, lttng_ust_ze_zeFabricEdgeGetExp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeFabricEdgeGetExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, ze_fabric_edge_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeFabricEdgeGetExp_exit(
    void *btx_handle, lttng_ust_ze_zeFabricEdgeGetExp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeFabricEdgeGetVerticesExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_fabric_edge_handle_t, ze_fabric_vertex_handle_t *, ze_fabric_vertex_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeFabricEdgeGetVerticesExp_entry(
    void *btx_handle, lttng_ust_ze_zeFabricEdgeGetVerticesExp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeFabricEdgeGetVerticesExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_fabric_vertex_handle_t, ze_fabric_vertex_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeFabricEdgeGetVerticesExp_exit(
    void *btx_handle, lttng_ust_ze_zeFabricEdgeGetVerticesExp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeFabricEdgeGetPropertiesExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_fabric_edge_handle_t, ze_fabric_edge_exp_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeFabricEdgeGetPropertiesExp_entry(
    void *btx_handle, lttng_ust_ze_zeFabricEdgeGetPropertiesExp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeFabricEdgeGetPropertiesExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, ze_fabric_edge_exp_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeFabricEdgeGetPropertiesExp_exit(
    void *btx_handle, lttng_ust_ze_zeFabricEdgeGetPropertiesExp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeEventQueryKernelTimestampsExt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_event_handle_t, ze_device_handle_t, uint32_t *, ze_event_query_kernel_timestamps_results_ext_properties_t *, uint32_t);

void btx_register_callbacks_lttng_ust_ze_zeEventQueryKernelTimestampsExt_entry(
    void *btx_handle, lttng_ust_ze_zeEventQueryKernelTimestampsExt_entry_callback_f *callback);

typedef void lttng_ust_ze_zeEventQueryKernelTimestampsExt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, ze_event_query_kernel_timestamps_results_ext_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeEventQueryKernelTimestampsExt_exit(
    void *btx_handle, lttng_ust_ze_zeEventQueryKernelTimestampsExt_exit_callback_f *callback);

typedef void lttng_ust_ze_zeRTASBuilderCreateExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_driver_handle_t, ze_rtas_builder_exp_desc_t *, ze_rtas_builder_exp_handle_t *, size_t, ze_rtas_builder_exp_desc_t *);

void btx_register_callbacks_lttng_ust_ze_zeRTASBuilderCreateExp_entry(
    void *btx_handle, lttng_ust_ze_zeRTASBuilderCreateExp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeRTASBuilderCreateExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_rtas_builder_exp_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeRTASBuilderCreateExp_exit(
    void *btx_handle, lttng_ust_ze_zeRTASBuilderCreateExp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeRTASBuilderGetBuildPropertiesExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_rtas_builder_exp_handle_t, ze_rtas_builder_build_op_exp_desc_t *, ze_rtas_builder_exp_properties_t *, size_t, ze_rtas_builder_build_op_exp_desc_t *);

void btx_register_callbacks_lttng_ust_ze_zeRTASBuilderGetBuildPropertiesExp_entry(
    void *btx_handle, lttng_ust_ze_zeRTASBuilderGetBuildPropertiesExp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeRTASBuilderGetBuildPropertiesExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, ze_rtas_builder_exp_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeRTASBuilderGetBuildPropertiesExp_exit(
    void *btx_handle, lttng_ust_ze_zeRTASBuilderGetBuildPropertiesExp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeDriverRTASFormatCompatibilityCheckExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_driver_handle_t, ze_rtas_format_exp_t, ze_rtas_format_exp_t);

void btx_register_callbacks_lttng_ust_ze_zeDriverRTASFormatCompatibilityCheckExp_entry(
    void *btx_handle, lttng_ust_ze_zeDriverRTASFormatCompatibilityCheckExp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeDriverRTASFormatCompatibilityCheckExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeDriverRTASFormatCompatibilityCheckExp_exit(
    void *btx_handle, lttng_ust_ze_zeDriverRTASFormatCompatibilityCheckExp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeRTASBuilderBuildExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_rtas_builder_exp_handle_t, ze_rtas_builder_build_op_exp_desc_t *, void *, size_t, void *, size_t, ze_rtas_parallel_operation_exp_handle_t, void *, ze_rtas_aabb_exp_t *, size_t *, size_t, ze_rtas_builder_build_op_exp_desc_t *);

void btx_register_callbacks_lttng_ust_ze_zeRTASBuilderBuildExp_entry(
    void *btx_handle, lttng_ust_ze_zeRTASBuilderBuildExp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeRTASBuilderBuildExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, ze_rtas_aabb_exp_t *, size_t);

void btx_register_callbacks_lttng_ust_ze_zeRTASBuilderBuildExp_exit(
    void *btx_handle, lttng_ust_ze_zeRTASBuilderBuildExp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeRTASBuilderDestroyExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_rtas_builder_exp_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeRTASBuilderDestroyExp_entry(
    void *btx_handle, lttng_ust_ze_zeRTASBuilderDestroyExp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeRTASBuilderDestroyExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeRTASBuilderDestroyExp_exit(
    void *btx_handle, lttng_ust_ze_zeRTASBuilderDestroyExp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeRTASParallelOperationCreateExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_driver_handle_t, ze_rtas_parallel_operation_exp_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeRTASParallelOperationCreateExp_entry(
    void *btx_handle, lttng_ust_ze_zeRTASParallelOperationCreateExp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeRTASParallelOperationCreateExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_rtas_parallel_operation_exp_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeRTASParallelOperationCreateExp_exit(
    void *btx_handle, lttng_ust_ze_zeRTASParallelOperationCreateExp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeRTASParallelOperationGetPropertiesExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_rtas_parallel_operation_exp_handle_t, ze_rtas_parallel_operation_exp_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeRTASParallelOperationGetPropertiesExp_entry(
    void *btx_handle, lttng_ust_ze_zeRTASParallelOperationGetPropertiesExp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeRTASParallelOperationGetPropertiesExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, ze_rtas_parallel_operation_exp_properties_t *);

void btx_register_callbacks_lttng_ust_ze_zeRTASParallelOperationGetPropertiesExp_exit(
    void *btx_handle, lttng_ust_ze_zeRTASParallelOperationGetPropertiesExp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeRTASParallelOperationJoinExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_rtas_parallel_operation_exp_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeRTASParallelOperationJoinExp_entry(
    void *btx_handle, lttng_ust_ze_zeRTASParallelOperationJoinExp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeRTASParallelOperationJoinExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeRTASParallelOperationJoinExp_exit(
    void *btx_handle, lttng_ust_ze_zeRTASParallelOperationJoinExp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeRTASParallelOperationDestroyExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_rtas_parallel_operation_exp_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeRTASParallelOperationDestroyExp_entry(
    void *btx_handle, lttng_ust_ze_zeRTASParallelOperationDestroyExp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeRTASParallelOperationDestroyExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeRTASParallelOperationDestroyExp_exit(
    void *btx_handle, lttng_ust_ze_zeRTASParallelOperationDestroyExp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeMemGetPitchFor2dImage_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, ze_device_handle_t, size_t, size_t, unsigned int, size_t *);

void btx_register_callbacks_lttng_ust_ze_zeMemGetPitchFor2dImage_entry(
    void *btx_handle, lttng_ust_ze_zeMemGetPitchFor2dImage_entry_callback_f *callback);

typedef void lttng_ust_ze_zeMemGetPitchFor2dImage_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t);

void btx_register_callbacks_lttng_ust_ze_zeMemGetPitchFor2dImage_exit(
    void *btx_handle, lttng_ust_ze_zeMemGetPitchFor2dImage_exit_callback_f *callback);

typedef void lttng_ust_ze_zeImageGetDeviceOffsetExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_image_handle_t, uint64_t *);

void btx_register_callbacks_lttng_ust_ze_zeImageGetDeviceOffsetExp_entry(
    void *btx_handle, lttng_ust_ze_zeImageGetDeviceOffsetExp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeImageGetDeviceOffsetExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint64_t);

void btx_register_callbacks_lttng_ust_ze_zeImageGetDeviceOffsetExp_exit(
    void *btx_handle, lttng_ust_ze_zeImageGetDeviceOffsetExp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListCreateCloneExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, ze_command_list_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandListCreateCloneExp_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListCreateCloneExp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListCreateCloneExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_command_list_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListCreateCloneExp_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListCreateCloneExp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListImmediateAppendCommandListsExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, uint32_t, ze_command_list_handle_t *, ze_event_handle_t, uint32_t, ze_event_handle_t *, size_t, ze_command_list_handle_t *, size_t, ze_event_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandListImmediateAppendCommandListsExp_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListImmediateAppendCommandListsExp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListImmediateAppendCommandListsExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListImmediateAppendCommandListsExp_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListImmediateAppendCommandListsExp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListGetNextCommandIdExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, ze_mutable_command_id_exp_desc_t *, uint64_t *, size_t, ze_mutable_command_id_exp_desc_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandListGetNextCommandIdExp_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListGetNextCommandIdExp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListGetNextCommandIdExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint64_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListGetNextCommandIdExp_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListGetNextCommandIdExp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListGetNextCommandIdWithKernelsExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, ze_mutable_command_id_exp_desc_t *, uint32_t, ze_kernel_handle_t *, uint64_t *, size_t, ze_mutable_command_id_exp_desc_t *, size_t, ze_kernel_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandListGetNextCommandIdWithKernelsExp_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListGetNextCommandIdWithKernelsExp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListGetNextCommandIdWithKernelsExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, ze_mutable_command_id_exp_desc_t *, uint64_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListGetNextCommandIdWithKernelsExp_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListGetNextCommandIdWithKernelsExp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListUpdateMutableCommandsExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, ze_mutable_commands_exp_desc_t *, size_t, ze_mutable_commands_exp_desc_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandListUpdateMutableCommandsExp_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListUpdateMutableCommandsExp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListUpdateMutableCommandsExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListUpdateMutableCommandsExp_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListUpdateMutableCommandsExp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListUpdateMutableCommandSignalEventExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, uint64_t, ze_event_handle_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListUpdateMutableCommandSignalEventExp_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListUpdateMutableCommandSignalEventExp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListUpdateMutableCommandSignalEventExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListUpdateMutableCommandSignalEventExp_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListUpdateMutableCommandSignalEventExp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListUpdateMutableCommandWaitEventsExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, uint64_t, uint32_t, ze_event_handle_t *, size_t, ze_event_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandListUpdateMutableCommandWaitEventsExp_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListUpdateMutableCommandWaitEventsExp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListUpdateMutableCommandWaitEventsExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListUpdateMutableCommandWaitEventsExp_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListUpdateMutableCommandWaitEventsExp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListUpdateMutableCommandKernelsExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, uint32_t, uint64_t *, ze_kernel_handle_t *, size_t, uint64_t *, size_t, ze_kernel_handle_t *);

void btx_register_callbacks_lttng_ust_ze_zeCommandListUpdateMutableCommandKernelsExp_entry(
    void *btx_handle, lttng_ust_ze_zeCommandListUpdateMutableCommandKernelsExp_entry_callback_f *callback);

typedef void lttng_ust_ze_zeCommandListUpdateMutableCommandKernelsExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeCommandListUpdateMutableCommandKernelsExp_exit(
    void *btx_handle, lttng_ust_ze_zeCommandListUpdateMutableCommandKernelsExp_exit_callback_f *callback);

typedef void lttng_ust_ze_zeLoaderInit_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_ze_zeLoaderInit_entry(
    void *btx_handle, lttng_ust_ze_zeLoaderInit_entry_callback_f *callback);

typedef void lttng_ust_ze_zeLoaderInit_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeLoaderInit_exit(
    void *btx_handle, lttng_ust_ze_zeLoaderInit_exit_callback_f *callback);

typedef void lttng_ust_ze_zeGetRTASBuilderProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, ze_rtas_builder_dditable_t *);

void btx_register_callbacks_lttng_ust_ze_zeGetRTASBuilderProcAddrTable_entry(
    void *btx_handle, lttng_ust_ze_zeGetRTASBuilderProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_ze_zeGetRTASBuilderProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeGetRTASBuilderProcAddrTable_exit(
    void *btx_handle, lttng_ust_ze_zeGetRTASBuilderProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_ze_zeGetRTASBuilderExpProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, ze_rtas_builder_exp_dditable_t *);

void btx_register_callbacks_lttng_ust_ze_zeGetRTASBuilderExpProcAddrTable_entry(
    void *btx_handle, lttng_ust_ze_zeGetRTASBuilderExpProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_ze_zeGetRTASBuilderExpProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeGetRTASBuilderExpProcAddrTable_exit(
    void *btx_handle, lttng_ust_ze_zeGetRTASBuilderExpProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_ze_zeGetRTASParallelOperationProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, ze_rtas_parallel_operation_dditable_t *);

void btx_register_callbacks_lttng_ust_ze_zeGetRTASParallelOperationProcAddrTable_entry(
    void *btx_handle, lttng_ust_ze_zeGetRTASParallelOperationProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_ze_zeGetRTASParallelOperationProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeGetRTASParallelOperationProcAddrTable_exit(
    void *btx_handle, lttng_ust_ze_zeGetRTASParallelOperationProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_ze_zeGetRTASParallelOperationExpProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, ze_rtas_parallel_operation_exp_dditable_t *);

void btx_register_callbacks_lttng_ust_ze_zeGetRTASParallelOperationExpProcAddrTable_entry(
    void *btx_handle, lttng_ust_ze_zeGetRTASParallelOperationExpProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_ze_zeGetRTASParallelOperationExpProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeGetRTASParallelOperationExpProcAddrTable_exit(
    void *btx_handle, lttng_ust_ze_zeGetRTASParallelOperationExpProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_ze_zeGetGlobalProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, ze_global_dditable_t *);

void btx_register_callbacks_lttng_ust_ze_zeGetGlobalProcAddrTable_entry(
    void *btx_handle, lttng_ust_ze_zeGetGlobalProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_ze_zeGetGlobalProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeGetGlobalProcAddrTable_exit(
    void *btx_handle, lttng_ust_ze_zeGetGlobalProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_ze_zeGetDriverProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, ze_driver_dditable_t *);

void btx_register_callbacks_lttng_ust_ze_zeGetDriverProcAddrTable_entry(
    void *btx_handle, lttng_ust_ze_zeGetDriverProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_ze_zeGetDriverProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeGetDriverProcAddrTable_exit(
    void *btx_handle, lttng_ust_ze_zeGetDriverProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_ze_zeGetDriverExpProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, ze_driver_exp_dditable_t *);

void btx_register_callbacks_lttng_ust_ze_zeGetDriverExpProcAddrTable_entry(
    void *btx_handle, lttng_ust_ze_zeGetDriverExpProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_ze_zeGetDriverExpProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeGetDriverExpProcAddrTable_exit(
    void *btx_handle, lttng_ust_ze_zeGetDriverExpProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_ze_zeGetDeviceProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, ze_device_dditable_t *);

void btx_register_callbacks_lttng_ust_ze_zeGetDeviceProcAddrTable_entry(
    void *btx_handle, lttng_ust_ze_zeGetDeviceProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_ze_zeGetDeviceProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeGetDeviceProcAddrTable_exit(
    void *btx_handle, lttng_ust_ze_zeGetDeviceProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_ze_zeGetDeviceExpProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, ze_device_exp_dditable_t *);

void btx_register_callbacks_lttng_ust_ze_zeGetDeviceExpProcAddrTable_entry(
    void *btx_handle, lttng_ust_ze_zeGetDeviceExpProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_ze_zeGetDeviceExpProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeGetDeviceExpProcAddrTable_exit(
    void *btx_handle, lttng_ust_ze_zeGetDeviceExpProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_ze_zeGetContextProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, ze_context_dditable_t *);

void btx_register_callbacks_lttng_ust_ze_zeGetContextProcAddrTable_entry(
    void *btx_handle, lttng_ust_ze_zeGetContextProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_ze_zeGetContextProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeGetContextProcAddrTable_exit(
    void *btx_handle, lttng_ust_ze_zeGetContextProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_ze_zeGetCommandQueueProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, ze_command_queue_dditable_t *);

void btx_register_callbacks_lttng_ust_ze_zeGetCommandQueueProcAddrTable_entry(
    void *btx_handle, lttng_ust_ze_zeGetCommandQueueProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_ze_zeGetCommandQueueProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeGetCommandQueueProcAddrTable_exit(
    void *btx_handle, lttng_ust_ze_zeGetCommandQueueProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_ze_zeGetCommandListProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, ze_command_list_dditable_t *);

void btx_register_callbacks_lttng_ust_ze_zeGetCommandListProcAddrTable_entry(
    void *btx_handle, lttng_ust_ze_zeGetCommandListProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_ze_zeGetCommandListProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeGetCommandListProcAddrTable_exit(
    void *btx_handle, lttng_ust_ze_zeGetCommandListProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_ze_zeGetCommandListExpProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, ze_command_list_exp_dditable_t *);

void btx_register_callbacks_lttng_ust_ze_zeGetCommandListExpProcAddrTable_entry(
    void *btx_handle, lttng_ust_ze_zeGetCommandListExpProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_ze_zeGetCommandListExpProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeGetCommandListExpProcAddrTable_exit(
    void *btx_handle, lttng_ust_ze_zeGetCommandListExpProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_ze_zeGetImageProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, ze_image_dditable_t *);

void btx_register_callbacks_lttng_ust_ze_zeGetImageProcAddrTable_entry(
    void *btx_handle, lttng_ust_ze_zeGetImageProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_ze_zeGetImageProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeGetImageProcAddrTable_exit(
    void *btx_handle, lttng_ust_ze_zeGetImageProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_ze_zeGetImageExpProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, ze_image_exp_dditable_t *);

void btx_register_callbacks_lttng_ust_ze_zeGetImageExpProcAddrTable_entry(
    void *btx_handle, lttng_ust_ze_zeGetImageExpProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_ze_zeGetImageExpProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeGetImageExpProcAddrTable_exit(
    void *btx_handle, lttng_ust_ze_zeGetImageExpProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_ze_zeGetMemProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, ze_mem_dditable_t *);

void btx_register_callbacks_lttng_ust_ze_zeGetMemProcAddrTable_entry(
    void *btx_handle, lttng_ust_ze_zeGetMemProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_ze_zeGetMemProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeGetMemProcAddrTable_exit(
    void *btx_handle, lttng_ust_ze_zeGetMemProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_ze_zeGetMemExpProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, ze_mem_exp_dditable_t *);

void btx_register_callbacks_lttng_ust_ze_zeGetMemExpProcAddrTable_entry(
    void *btx_handle, lttng_ust_ze_zeGetMemExpProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_ze_zeGetMemExpProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeGetMemExpProcAddrTable_exit(
    void *btx_handle, lttng_ust_ze_zeGetMemExpProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_ze_zeGetFenceProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, ze_fence_dditable_t *);

void btx_register_callbacks_lttng_ust_ze_zeGetFenceProcAddrTable_entry(
    void *btx_handle, lttng_ust_ze_zeGetFenceProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_ze_zeGetFenceProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeGetFenceProcAddrTable_exit(
    void *btx_handle, lttng_ust_ze_zeGetFenceProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_ze_zeGetEventPoolProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, ze_event_pool_dditable_t *);

void btx_register_callbacks_lttng_ust_ze_zeGetEventPoolProcAddrTable_entry(
    void *btx_handle, lttng_ust_ze_zeGetEventPoolProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_ze_zeGetEventPoolProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeGetEventPoolProcAddrTable_exit(
    void *btx_handle, lttng_ust_ze_zeGetEventPoolProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_ze_zeGetEventProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, ze_event_dditable_t *);

void btx_register_callbacks_lttng_ust_ze_zeGetEventProcAddrTable_entry(
    void *btx_handle, lttng_ust_ze_zeGetEventProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_ze_zeGetEventProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeGetEventProcAddrTable_exit(
    void *btx_handle, lttng_ust_ze_zeGetEventProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_ze_zeGetEventExpProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, ze_event_exp_dditable_t *);

void btx_register_callbacks_lttng_ust_ze_zeGetEventExpProcAddrTable_entry(
    void *btx_handle, lttng_ust_ze_zeGetEventExpProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_ze_zeGetEventExpProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeGetEventExpProcAddrTable_exit(
    void *btx_handle, lttng_ust_ze_zeGetEventExpProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_ze_zeGetModuleProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, ze_module_dditable_t *);

void btx_register_callbacks_lttng_ust_ze_zeGetModuleProcAddrTable_entry(
    void *btx_handle, lttng_ust_ze_zeGetModuleProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_ze_zeGetModuleProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeGetModuleProcAddrTable_exit(
    void *btx_handle, lttng_ust_ze_zeGetModuleProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_ze_zeGetModuleBuildLogProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, ze_module_build_log_dditable_t *);

void btx_register_callbacks_lttng_ust_ze_zeGetModuleBuildLogProcAddrTable_entry(
    void *btx_handle, lttng_ust_ze_zeGetModuleBuildLogProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_ze_zeGetModuleBuildLogProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeGetModuleBuildLogProcAddrTable_exit(
    void *btx_handle, lttng_ust_ze_zeGetModuleBuildLogProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_ze_zeGetKernelProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, ze_kernel_dditable_t *);

void btx_register_callbacks_lttng_ust_ze_zeGetKernelProcAddrTable_entry(
    void *btx_handle, lttng_ust_ze_zeGetKernelProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_ze_zeGetKernelProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeGetKernelProcAddrTable_exit(
    void *btx_handle, lttng_ust_ze_zeGetKernelProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_ze_zeGetKernelExpProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, ze_kernel_exp_dditable_t *);

void btx_register_callbacks_lttng_ust_ze_zeGetKernelExpProcAddrTable_entry(
    void *btx_handle, lttng_ust_ze_zeGetKernelExpProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_ze_zeGetKernelExpProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeGetKernelExpProcAddrTable_exit(
    void *btx_handle, lttng_ust_ze_zeGetKernelExpProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_ze_zeGetSamplerProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, ze_sampler_dditable_t *);

void btx_register_callbacks_lttng_ust_ze_zeGetSamplerProcAddrTable_entry(
    void *btx_handle, lttng_ust_ze_zeGetSamplerProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_ze_zeGetSamplerProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeGetSamplerProcAddrTable_exit(
    void *btx_handle, lttng_ust_ze_zeGetSamplerProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_ze_zeGetPhysicalMemProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, ze_physical_mem_dditable_t *);

void btx_register_callbacks_lttng_ust_ze_zeGetPhysicalMemProcAddrTable_entry(
    void *btx_handle, lttng_ust_ze_zeGetPhysicalMemProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_ze_zeGetPhysicalMemProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeGetPhysicalMemProcAddrTable_exit(
    void *btx_handle, lttng_ust_ze_zeGetPhysicalMemProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_ze_zeGetVirtualMemProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, ze_virtual_mem_dditable_t *);

void btx_register_callbacks_lttng_ust_ze_zeGetVirtualMemProcAddrTable_entry(
    void *btx_handle, lttng_ust_ze_zeGetVirtualMemProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_ze_zeGetVirtualMemProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeGetVirtualMemProcAddrTable_exit(
    void *btx_handle, lttng_ust_ze_zeGetVirtualMemProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_ze_zeGetFabricVertexExpProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, ze_fabric_vertex_exp_dditable_t *);

void btx_register_callbacks_lttng_ust_ze_zeGetFabricVertexExpProcAddrTable_entry(
    void *btx_handle, lttng_ust_ze_zeGetFabricVertexExpProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_ze_zeGetFabricVertexExpProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeGetFabricVertexExpProcAddrTable_exit(
    void *btx_handle, lttng_ust_ze_zeGetFabricVertexExpProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_ze_zeGetFabricEdgeExpProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, ze_fabric_edge_exp_dditable_t *);

void btx_register_callbacks_lttng_ust_ze_zeGetFabricEdgeExpProcAddrTable_entry(
    void *btx_handle, lttng_ust_ze_zeGetFabricEdgeExpProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_ze_zeGetFabricEdgeExpProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_ze_zeGetFabricEdgeExpProcAddrTable_exit(
    void *btx_handle, lttng_ust_ze_zeGetFabricEdgeExpProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zet_zetModuleGetDebugInfo_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_module_handle_t, zet_module_debug_info_format_t, size_t *, uint8_t *, size_t);

void btx_register_callbacks_lttng_ust_zet_zetModuleGetDebugInfo_entry(
    void *btx_handle, lttng_ust_zet_zetModuleGetDebugInfo_entry_callback_f *callback);

typedef void lttng_ust_zet_zetModuleGetDebugInfo_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t);

void btx_register_callbacks_lttng_ust_zet_zetModuleGetDebugInfo_exit(
    void *btx_handle, lttng_ust_zet_zetModuleGetDebugInfo_exit_callback_f *callback);

typedef void lttng_ust_zet_zetDeviceGetDebugProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_device_handle_t, zet_device_debug_properties_t *);

void btx_register_callbacks_lttng_ust_zet_zetDeviceGetDebugProperties_entry(
    void *btx_handle, lttng_ust_zet_zetDeviceGetDebugProperties_entry_callback_f *callback);

typedef void lttng_ust_zet_zetDeviceGetDebugProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zet_device_debug_properties_t *);

void btx_register_callbacks_lttng_ust_zet_zetDeviceGetDebugProperties_exit(
    void *btx_handle, lttng_ust_zet_zetDeviceGetDebugProperties_exit_callback_f *callback);

typedef void lttng_ust_zet_zetDebugAttach_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_device_handle_t, zet_debug_config_t *, zet_debug_session_handle_t *, size_t, zet_debug_config_t *);

void btx_register_callbacks_lttng_ust_zet_zetDebugAttach_entry(
    void *btx_handle, lttng_ust_zet_zetDebugAttach_entry_callback_f *callback);

typedef void lttng_ust_zet_zetDebugAttach_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, zet_debug_session_handle_t);

void btx_register_callbacks_lttng_ust_zet_zetDebugAttach_exit(
    void *btx_handle, lttng_ust_zet_zetDebugAttach_exit_callback_f *callback);

typedef void lttng_ust_zet_zetDebugDetach_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_debug_session_handle_t);

void btx_register_callbacks_lttng_ust_zet_zetDebugDetach_entry(
    void *btx_handle, lttng_ust_zet_zetDebugDetach_entry_callback_f *callback);

typedef void lttng_ust_zet_zetDebugDetach_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetDebugDetach_exit(
    void *btx_handle, lttng_ust_zet_zetDebugDetach_exit_callback_f *callback);

typedef void lttng_ust_zet_zetDebugReadEvent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_debug_session_handle_t, uint64_t, zet_debug_event_t *);

void btx_register_callbacks_lttng_ust_zet_zetDebugReadEvent_entry(
    void *btx_handle, lttng_ust_zet_zetDebugReadEvent_entry_callback_f *callback);

typedef void lttng_ust_zet_zetDebugReadEvent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zet_debug_event_t *);

void btx_register_callbacks_lttng_ust_zet_zetDebugReadEvent_exit(
    void *btx_handle, lttng_ust_zet_zetDebugReadEvent_exit_callback_f *callback);

typedef void lttng_ust_zet_zetDebugAcknowledgeEvent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_debug_session_handle_t, zet_debug_event_t *);

void btx_register_callbacks_lttng_ust_zet_zetDebugAcknowledgeEvent_entry(
    void *btx_handle, lttng_ust_zet_zetDebugAcknowledgeEvent_entry_callback_f *callback);

typedef void lttng_ust_zet_zetDebugAcknowledgeEvent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetDebugAcknowledgeEvent_exit(
    void *btx_handle, lttng_ust_zet_zetDebugAcknowledgeEvent_exit_callback_f *callback);

typedef void lttng_ust_zet_zetDebugInterrupt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_debug_session_handle_t, ze_device_thread_t);

void btx_register_callbacks_lttng_ust_zet_zetDebugInterrupt_entry(
    void *btx_handle, lttng_ust_zet_zetDebugInterrupt_entry_callback_f *callback);

typedef void lttng_ust_zet_zetDebugInterrupt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetDebugInterrupt_exit(
    void *btx_handle, lttng_ust_zet_zetDebugInterrupt_exit_callback_f *callback);

typedef void lttng_ust_zet_zetDebugResume_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_debug_session_handle_t, ze_device_thread_t);

void btx_register_callbacks_lttng_ust_zet_zetDebugResume_entry(
    void *btx_handle, lttng_ust_zet_zetDebugResume_entry_callback_f *callback);

typedef void lttng_ust_zet_zetDebugResume_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetDebugResume_exit(
    void *btx_handle, lttng_ust_zet_zetDebugResume_exit_callback_f *callback);

typedef void lttng_ust_zet_zetDebugReadMemory_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_debug_session_handle_t, ze_device_thread_t, zet_debug_memory_space_desc_t *, size_t, void *, size_t, zet_debug_memory_space_desc_t *);

void btx_register_callbacks_lttng_ust_zet_zetDebugReadMemory_entry(
    void *btx_handle, lttng_ust_zet_zetDebugReadMemory_entry_callback_f *callback);

typedef void lttng_ust_zet_zetDebugReadMemory_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetDebugReadMemory_exit(
    void *btx_handle, lttng_ust_zet_zetDebugReadMemory_exit_callback_f *callback);

typedef void lttng_ust_zet_zetDebugWriteMemory_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_debug_session_handle_t, ze_device_thread_t, zet_debug_memory_space_desc_t *, size_t, void *, size_t, zet_debug_memory_space_desc_t *);

void btx_register_callbacks_lttng_ust_zet_zetDebugWriteMemory_entry(
    void *btx_handle, lttng_ust_zet_zetDebugWriteMemory_entry_callback_f *callback);

typedef void lttng_ust_zet_zetDebugWriteMemory_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetDebugWriteMemory_exit(
    void *btx_handle, lttng_ust_zet_zetDebugWriteMemory_exit_callback_f *callback);

typedef void lttng_ust_zet_zetDebugGetRegisterSetProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_device_handle_t, uint32_t *, zet_debug_regset_properties_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zet_zetDebugGetRegisterSetProperties_entry(
    void *btx_handle, lttng_ust_zet_zetDebugGetRegisterSetProperties_entry_callback_f *callback);

typedef void lttng_ust_zet_zetDebugGetRegisterSetProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zet_debug_regset_properties_t *);

void btx_register_callbacks_lttng_ust_zet_zetDebugGetRegisterSetProperties_exit(
    void *btx_handle, lttng_ust_zet_zetDebugGetRegisterSetProperties_exit_callback_f *callback);

typedef void lttng_ust_zet_zetDebugGetThreadRegisterSetProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_debug_session_handle_t, ze_device_thread_t, uint32_t *, zet_debug_regset_properties_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zet_zetDebugGetThreadRegisterSetProperties_entry(
    void *btx_handle, lttng_ust_zet_zetDebugGetThreadRegisterSetProperties_entry_callback_f *callback);

typedef void lttng_ust_zet_zetDebugGetThreadRegisterSetProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zet_debug_regset_properties_t *);

void btx_register_callbacks_lttng_ust_zet_zetDebugGetThreadRegisterSetProperties_exit(
    void *btx_handle, lttng_ust_zet_zetDebugGetThreadRegisterSetProperties_exit_callback_f *callback);

typedef void lttng_ust_zet_zetDebugReadRegisters_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_debug_session_handle_t, ze_device_thread_t, uint32_t, uint32_t, uint32_t, void *);

void btx_register_callbacks_lttng_ust_zet_zetDebugReadRegisters_entry(
    void *btx_handle, lttng_ust_zet_zetDebugReadRegisters_entry_callback_f *callback);

typedef void lttng_ust_zet_zetDebugReadRegisters_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetDebugReadRegisters_exit(
    void *btx_handle, lttng_ust_zet_zetDebugReadRegisters_exit_callback_f *callback);

typedef void lttng_ust_zet_zetDebugWriteRegisters_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_debug_session_handle_t, ze_device_thread_t, uint32_t, uint32_t, uint32_t, void *);

void btx_register_callbacks_lttng_ust_zet_zetDebugWriteRegisters_entry(
    void *btx_handle, lttng_ust_zet_zetDebugWriteRegisters_entry_callback_f *callback);

typedef void lttng_ust_zet_zetDebugWriteRegisters_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetDebugWriteRegisters_exit(
    void *btx_handle, lttng_ust_zet_zetDebugWriteRegisters_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricGroupGet_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_device_handle_t, uint32_t *, zet_metric_group_handle_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricGroupGet_entry(
    void *btx_handle, lttng_ust_zet_zetMetricGroupGet_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricGroupGet_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zet_metric_group_handle_t *);

void btx_register_callbacks_lttng_ust_zet_zetMetricGroupGet_exit(
    void *btx_handle, lttng_ust_zet_zetMetricGroupGet_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricGroupGetProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_group_handle_t, zet_metric_group_properties_t *);

void btx_register_callbacks_lttng_ust_zet_zetMetricGroupGetProperties_entry(
    void *btx_handle, lttng_ust_zet_zetMetricGroupGetProperties_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricGroupGetProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zet_metric_group_properties_t *);

void btx_register_callbacks_lttng_ust_zet_zetMetricGroupGetProperties_exit(
    void *btx_handle, lttng_ust_zet_zetMetricGroupGetProperties_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricGroupCalculateMetricValues_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_group_handle_t, zet_metric_group_calculation_type_t, size_t, uint8_t *, uint32_t *, zet_typed_value_t *, size_t, uint8_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricGroupCalculateMetricValues_entry(
    void *btx_handle, lttng_ust_zet_zetMetricGroupCalculateMetricValues_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricGroupCalculateMetricValues_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zet_typed_value_t *);

void btx_register_callbacks_lttng_ust_zet_zetMetricGroupCalculateMetricValues_exit(
    void *btx_handle, lttng_ust_zet_zetMetricGroupCalculateMetricValues_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricGet_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_group_handle_t, uint32_t *, zet_metric_handle_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricGet_entry(
    void *btx_handle, lttng_ust_zet_zetMetricGet_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricGet_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zet_metric_handle_t *);

void btx_register_callbacks_lttng_ust_zet_zetMetricGet_exit(
    void *btx_handle, lttng_ust_zet_zetMetricGet_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricGetProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_handle_t, zet_metric_properties_t *);

void btx_register_callbacks_lttng_ust_zet_zetMetricGetProperties_entry(
    void *btx_handle, lttng_ust_zet_zetMetricGetProperties_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricGetProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zet_metric_properties_t *);

void btx_register_callbacks_lttng_ust_zet_zetMetricGetProperties_exit(
    void *btx_handle, lttng_ust_zet_zetMetricGetProperties_exit_callback_f *callback);

typedef void lttng_ust_zet_zetContextActivateMetricGroups_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_context_handle_t, zet_device_handle_t, uint32_t, zet_metric_group_handle_t *, size_t, zet_metric_group_handle_t *);

void btx_register_callbacks_lttng_ust_zet_zetContextActivateMetricGroups_entry(
    void *btx_handle, lttng_ust_zet_zetContextActivateMetricGroups_entry_callback_f *callback);

typedef void lttng_ust_zet_zetContextActivateMetricGroups_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetContextActivateMetricGroups_exit(
    void *btx_handle, lttng_ust_zet_zetContextActivateMetricGroups_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricStreamerOpen_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_context_handle_t, zet_device_handle_t, zet_metric_group_handle_t, zet_metric_streamer_desc_t *, ze_event_handle_t, zet_metric_streamer_handle_t *, size_t, zet_metric_streamer_desc_t *);

void btx_register_callbacks_lttng_ust_zet_zetMetricStreamerOpen_entry(
    void *btx_handle, lttng_ust_zet_zetMetricStreamerOpen_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricStreamerOpen_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, zet_metric_streamer_handle_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricStreamerOpen_exit(
    void *btx_handle, lttng_ust_zet_zetMetricStreamerOpen_exit_callback_f *callback);

typedef void lttng_ust_zet_zetCommandListAppendMetricStreamerMarker_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_command_list_handle_t, zet_metric_streamer_handle_t, uint32_t);

void btx_register_callbacks_lttng_ust_zet_zetCommandListAppendMetricStreamerMarker_entry(
    void *btx_handle, lttng_ust_zet_zetCommandListAppendMetricStreamerMarker_entry_callback_f *callback);

typedef void lttng_ust_zet_zetCommandListAppendMetricStreamerMarker_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetCommandListAppendMetricStreamerMarker_exit(
    void *btx_handle, lttng_ust_zet_zetCommandListAppendMetricStreamerMarker_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricStreamerClose_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_streamer_handle_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricStreamerClose_entry(
    void *btx_handle, lttng_ust_zet_zetMetricStreamerClose_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricStreamerClose_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricStreamerClose_exit(
    void *btx_handle, lttng_ust_zet_zetMetricStreamerClose_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricStreamerReadData_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_streamer_handle_t, uint32_t, size_t *, uint8_t *, size_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricStreamerReadData_entry(
    void *btx_handle, lttng_ust_zet_zetMetricStreamerReadData_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricStreamerReadData_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, size_t, uint8_t *);

void btx_register_callbacks_lttng_ust_zet_zetMetricStreamerReadData_exit(
    void *btx_handle, lttng_ust_zet_zetMetricStreamerReadData_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricQueryPoolCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_context_handle_t, zet_device_handle_t, zet_metric_group_handle_t, zet_metric_query_pool_desc_t *, zet_metric_query_pool_handle_t *, size_t, zet_metric_query_pool_desc_t *);

void btx_register_callbacks_lttng_ust_zet_zetMetricQueryPoolCreate_entry(
    void *btx_handle, lttng_ust_zet_zetMetricQueryPoolCreate_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricQueryPoolCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, zet_metric_query_pool_handle_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricQueryPoolCreate_exit(
    void *btx_handle, lttng_ust_zet_zetMetricQueryPoolCreate_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricQueryPoolDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_query_pool_handle_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricQueryPoolDestroy_entry(
    void *btx_handle, lttng_ust_zet_zetMetricQueryPoolDestroy_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricQueryPoolDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricQueryPoolDestroy_exit(
    void *btx_handle, lttng_ust_zet_zetMetricQueryPoolDestroy_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricQueryCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_query_pool_handle_t, uint32_t, zet_metric_query_handle_t *);

void btx_register_callbacks_lttng_ust_zet_zetMetricQueryCreate_entry(
    void *btx_handle, lttng_ust_zet_zetMetricQueryCreate_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricQueryCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, zet_metric_query_handle_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricQueryCreate_exit(
    void *btx_handle, lttng_ust_zet_zetMetricQueryCreate_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricQueryDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_query_handle_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricQueryDestroy_entry(
    void *btx_handle, lttng_ust_zet_zetMetricQueryDestroy_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricQueryDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricQueryDestroy_exit(
    void *btx_handle, lttng_ust_zet_zetMetricQueryDestroy_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricQueryReset_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_query_handle_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricQueryReset_entry(
    void *btx_handle, lttng_ust_zet_zetMetricQueryReset_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricQueryReset_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricQueryReset_exit(
    void *btx_handle, lttng_ust_zet_zetMetricQueryReset_exit_callback_f *callback);

typedef void lttng_ust_zet_zetCommandListAppendMetricQueryBegin_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_command_list_handle_t, zet_metric_query_handle_t);

void btx_register_callbacks_lttng_ust_zet_zetCommandListAppendMetricQueryBegin_entry(
    void *btx_handle, lttng_ust_zet_zetCommandListAppendMetricQueryBegin_entry_callback_f *callback);

typedef void lttng_ust_zet_zetCommandListAppendMetricQueryBegin_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetCommandListAppendMetricQueryBegin_exit(
    void *btx_handle, lttng_ust_zet_zetCommandListAppendMetricQueryBegin_exit_callback_f *callback);

typedef void lttng_ust_zet_zetCommandListAppendMetricQueryEnd_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_command_list_handle_t, zet_metric_query_handle_t, ze_event_handle_t, uint32_t, ze_event_handle_t *, size_t, ze_event_handle_t *);

void btx_register_callbacks_lttng_ust_zet_zetCommandListAppendMetricQueryEnd_entry(
    void *btx_handle, lttng_ust_zet_zetCommandListAppendMetricQueryEnd_entry_callback_f *callback);

typedef void lttng_ust_zet_zetCommandListAppendMetricQueryEnd_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetCommandListAppendMetricQueryEnd_exit(
    void *btx_handle, lttng_ust_zet_zetCommandListAppendMetricQueryEnd_exit_callback_f *callback);

typedef void lttng_ust_zet_zetCommandListAppendMetricMemoryBarrier_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_command_list_handle_t);

void btx_register_callbacks_lttng_ust_zet_zetCommandListAppendMetricMemoryBarrier_entry(
    void *btx_handle, lttng_ust_zet_zetCommandListAppendMetricMemoryBarrier_entry_callback_f *callback);

typedef void lttng_ust_zet_zetCommandListAppendMetricMemoryBarrier_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetCommandListAppendMetricMemoryBarrier_exit(
    void *btx_handle, lttng_ust_zet_zetCommandListAppendMetricMemoryBarrier_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricQueryGetData_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_query_handle_t, size_t *, uint8_t *, size_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricQueryGetData_entry(
    void *btx_handle, lttng_ust_zet_zetMetricQueryGetData_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricQueryGetData_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, size_t, uint8_t *);

void btx_register_callbacks_lttng_ust_zet_zetMetricQueryGetData_exit(
    void *btx_handle, lttng_ust_zet_zetMetricQueryGetData_exit_callback_f *callback);

typedef void lttng_ust_zet_zetKernelGetProfileInfo_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_kernel_handle_t, zet_profile_properties_t *);

void btx_register_callbacks_lttng_ust_zet_zetKernelGetProfileInfo_entry(
    void *btx_handle, lttng_ust_zet_zetKernelGetProfileInfo_entry_callback_f *callback);

typedef void lttng_ust_zet_zetKernelGetProfileInfo_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zet_profile_properties_t *);

void btx_register_callbacks_lttng_ust_zet_zetKernelGetProfileInfo_exit(
    void *btx_handle, lttng_ust_zet_zetKernelGetProfileInfo_exit_callback_f *callback);

typedef void lttng_ust_zet_zetTracerExpCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_context_handle_t, zet_tracer_exp_desc_t *, zet_tracer_exp_handle_t *, size_t, zet_tracer_exp_desc_t *);

void btx_register_callbacks_lttng_ust_zet_zetTracerExpCreate_entry(
    void *btx_handle, lttng_ust_zet_zetTracerExpCreate_entry_callback_f *callback);

typedef void lttng_ust_zet_zetTracerExpCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, zet_tracer_exp_handle_t);

void btx_register_callbacks_lttng_ust_zet_zetTracerExpCreate_exit(
    void *btx_handle, lttng_ust_zet_zetTracerExpCreate_exit_callback_f *callback);

typedef void lttng_ust_zet_zetTracerExpDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_tracer_exp_handle_t);

void btx_register_callbacks_lttng_ust_zet_zetTracerExpDestroy_entry(
    void *btx_handle, lttng_ust_zet_zetTracerExpDestroy_entry_callback_f *callback);

typedef void lttng_ust_zet_zetTracerExpDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetTracerExpDestroy_exit(
    void *btx_handle, lttng_ust_zet_zetTracerExpDestroy_exit_callback_f *callback);

typedef void lttng_ust_zet_zetTracerExpSetPrologues_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_tracer_exp_handle_t, zet_core_callbacks_t *);

void btx_register_callbacks_lttng_ust_zet_zetTracerExpSetPrologues_entry(
    void *btx_handle, lttng_ust_zet_zetTracerExpSetPrologues_entry_callback_f *callback);

typedef void lttng_ust_zet_zetTracerExpSetPrologues_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetTracerExpSetPrologues_exit(
    void *btx_handle, lttng_ust_zet_zetTracerExpSetPrologues_exit_callback_f *callback);

typedef void lttng_ust_zet_zetTracerExpSetEpilogues_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_tracer_exp_handle_t, zet_core_callbacks_t *);

void btx_register_callbacks_lttng_ust_zet_zetTracerExpSetEpilogues_entry(
    void *btx_handle, lttng_ust_zet_zetTracerExpSetEpilogues_entry_callback_f *callback);

typedef void lttng_ust_zet_zetTracerExpSetEpilogues_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetTracerExpSetEpilogues_exit(
    void *btx_handle, lttng_ust_zet_zetTracerExpSetEpilogues_exit_callback_f *callback);

typedef void lttng_ust_zet_zetTracerExpSetEnabled_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_tracer_exp_handle_t, ze_bool_t);

void btx_register_callbacks_lttng_ust_zet_zetTracerExpSetEnabled_entry(
    void *btx_handle, lttng_ust_zet_zetTracerExpSetEnabled_entry_callback_f *callback);

typedef void lttng_ust_zet_zetTracerExpSetEnabled_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetTracerExpSetEnabled_exit(
    void *btx_handle, lttng_ust_zet_zetTracerExpSetEnabled_exit_callback_f *callback);

typedef void lttng_ust_zet_zetDeviceGetConcurrentMetricGroupsExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_device_handle_t, uint32_t, zet_metric_group_handle_t *, uint32_t *, uint32_t *);

void btx_register_callbacks_lttng_ust_zet_zetDeviceGetConcurrentMetricGroupsExp_entry(
    void *btx_handle, lttng_ust_zet_zetDeviceGetConcurrentMetricGroupsExp_entry_callback_f *callback);

typedef void lttng_ust_zet_zetDeviceGetConcurrentMetricGroupsExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetDeviceGetConcurrentMetricGroupsExp_exit(
    void *btx_handle, lttng_ust_zet_zetDeviceGetConcurrentMetricGroupsExp_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricTracerCreateExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_context_handle_t, zet_device_handle_t, uint32_t, zet_metric_group_handle_t *, zet_metric_tracer_exp_desc_t *, ze_event_handle_t, zet_metric_tracer_exp_handle_t *);

void btx_register_callbacks_lttng_ust_zet_zetMetricTracerCreateExp_entry(
    void *btx_handle, lttng_ust_zet_zetMetricTracerCreateExp_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricTracerCreateExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricTracerCreateExp_exit(
    void *btx_handle, lttng_ust_zet_zetMetricTracerCreateExp_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricTracerDestroyExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_tracer_exp_handle_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricTracerDestroyExp_entry(
    void *btx_handle, lttng_ust_zet_zetMetricTracerDestroyExp_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricTracerDestroyExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricTracerDestroyExp_exit(
    void *btx_handle, lttng_ust_zet_zetMetricTracerDestroyExp_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricTracerEnableExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_tracer_exp_handle_t, ze_bool_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricTracerEnableExp_entry(
    void *btx_handle, lttng_ust_zet_zetMetricTracerEnableExp_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricTracerEnableExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricTracerEnableExp_exit(
    void *btx_handle, lttng_ust_zet_zetMetricTracerEnableExp_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricTracerDisableExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_tracer_exp_handle_t, ze_bool_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricTracerDisableExp_entry(
    void *btx_handle, lttng_ust_zet_zetMetricTracerDisableExp_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricTracerDisableExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricTracerDisableExp_exit(
    void *btx_handle, lttng_ust_zet_zetMetricTracerDisableExp_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricTracerReadDataExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_tracer_exp_handle_t, size_t *, uint8_t *);

void btx_register_callbacks_lttng_ust_zet_zetMetricTracerReadDataExp_entry(
    void *btx_handle, lttng_ust_zet_zetMetricTracerReadDataExp_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricTracerReadDataExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricTracerReadDataExp_exit(
    void *btx_handle, lttng_ust_zet_zetMetricTracerReadDataExp_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricDecoderCreateExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_tracer_exp_handle_t, zet_metric_decoder_exp_handle_t *);

void btx_register_callbacks_lttng_ust_zet_zetMetricDecoderCreateExp_entry(
    void *btx_handle, lttng_ust_zet_zetMetricDecoderCreateExp_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricDecoderCreateExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricDecoderCreateExp_exit(
    void *btx_handle, lttng_ust_zet_zetMetricDecoderCreateExp_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricDecoderDestroyExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_decoder_exp_handle_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricDecoderDestroyExp_entry(
    void *btx_handle, lttng_ust_zet_zetMetricDecoderDestroyExp_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricDecoderDestroyExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricDecoderDestroyExp_exit(
    void *btx_handle, lttng_ust_zet_zetMetricDecoderDestroyExp_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricDecoderGetDecodableMetricsExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_decoder_exp_handle_t, uint32_t *, zet_metric_handle_t *);

void btx_register_callbacks_lttng_ust_zet_zetMetricDecoderGetDecodableMetricsExp_entry(
    void *btx_handle, lttng_ust_zet_zetMetricDecoderGetDecodableMetricsExp_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricDecoderGetDecodableMetricsExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricDecoderGetDecodableMetricsExp_exit(
    void *btx_handle, lttng_ust_zet_zetMetricDecoderGetDecodableMetricsExp_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricTracerDecodeExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_decoder_exp_handle_t, size_t *, uint8_t *, uint32_t, zet_metric_handle_t *, uint32_t *, uint32_t *, uint32_t *, zet_metric_entry_exp_t *);

void btx_register_callbacks_lttng_ust_zet_zetMetricTracerDecodeExp_entry(
    void *btx_handle, lttng_ust_zet_zetMetricTracerDecodeExp_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricTracerDecodeExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricTracerDecodeExp_exit(
    void *btx_handle, lttng_ust_zet_zetMetricTracerDecodeExp_exit_callback_f *callback);

typedef void lttng_ust_zet_zetCommandListAppendMarkerExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_command_list_handle_t, zet_metric_group_handle_t, uint32_t);

void btx_register_callbacks_lttng_ust_zet_zetCommandListAppendMarkerExp_entry(
    void *btx_handle, lttng_ust_zet_zetCommandListAppendMarkerExp_entry_callback_f *callback);

typedef void lttng_ust_zet_zetCommandListAppendMarkerExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetCommandListAppendMarkerExp_exit(
    void *btx_handle, lttng_ust_zet_zetCommandListAppendMarkerExp_exit_callback_f *callback);

typedef void lttng_ust_zet_zetDeviceEnableMetricsExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_device_handle_t);

void btx_register_callbacks_lttng_ust_zet_zetDeviceEnableMetricsExp_entry(
    void *btx_handle, lttng_ust_zet_zetDeviceEnableMetricsExp_entry_callback_f *callback);

typedef void lttng_ust_zet_zetDeviceEnableMetricsExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetDeviceEnableMetricsExp_exit(
    void *btx_handle, lttng_ust_zet_zetDeviceEnableMetricsExp_exit_callback_f *callback);

typedef void lttng_ust_zet_zetDeviceDisableMetricsExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_device_handle_t);

void btx_register_callbacks_lttng_ust_zet_zetDeviceDisableMetricsExp_entry(
    void *btx_handle, lttng_ust_zet_zetDeviceDisableMetricsExp_entry_callback_f *callback);

typedef void lttng_ust_zet_zetDeviceDisableMetricsExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetDeviceDisableMetricsExp_exit(
    void *btx_handle, lttng_ust_zet_zetDeviceDisableMetricsExp_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricGroupCalculateMultipleMetricValuesExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_group_handle_t, zet_metric_group_calculation_type_t, size_t, uint8_t *, uint32_t *, uint32_t *, uint32_t *, zet_typed_value_t *, size_t, uint8_t *, uint32_t, uint32_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricGroupCalculateMultipleMetricValuesExp_entry(
    void *btx_handle, lttng_ust_zet_zetMetricGroupCalculateMultipleMetricValuesExp_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricGroupCalculateMultipleMetricValuesExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, uint32_t, size_t, uint32_t *, size_t, zet_typed_value_t *);

void btx_register_callbacks_lttng_ust_zet_zetMetricGroupCalculateMultipleMetricValuesExp_exit(
    void *btx_handle, lttng_ust_zet_zetMetricGroupCalculateMultipleMetricValuesExp_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricGroupGetGlobalTimestampsExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_group_handle_t, ze_bool_t, uint64_t *, uint64_t *);

void btx_register_callbacks_lttng_ust_zet_zetMetricGroupGetGlobalTimestampsExp_entry(
    void *btx_handle, lttng_ust_zet_zetMetricGroupGetGlobalTimestampsExp_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricGroupGetGlobalTimestampsExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint64_t, uint64_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricGroupGetGlobalTimestampsExp_exit(
    void *btx_handle, lttng_ust_zet_zetMetricGroupGetGlobalTimestampsExp_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricGroupGetExportDataExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_group_handle_t, uint8_t *, size_t, size_t *, uint8_t *, size_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricGroupGetExportDataExp_entry(
    void *btx_handle, lttng_ust_zet_zetMetricGroupGetExportDataExp_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricGroupGetExportDataExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricGroupGetExportDataExp_exit(
    void *btx_handle, lttng_ust_zet_zetMetricGroupGetExportDataExp_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricGroupCalculateMetricExportDataExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_driver_handle_t, zet_metric_group_calculation_type_t, size_t, uint8_t *, zet_metric_calculate_exp_desc_t *, uint32_t *, uint32_t *, uint32_t *, zet_typed_value_t *, size_t, zet_metric_calculate_exp_desc_t *, uint32_t, uint32_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricGroupCalculateMetricExportDataExp_entry(
    void *btx_handle, lttng_ust_zet_zetMetricGroupCalculateMetricExportDataExp_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricGroupCalculateMetricExportDataExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, uint32_t, size_t, uint32_t *, size_t, zet_typed_value_t *);

void btx_register_callbacks_lttng_ust_zet_zetMetricGroupCalculateMetricExportDataExp_exit(
    void *btx_handle, lttng_ust_zet_zetMetricGroupCalculateMetricExportDataExp_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricProgrammableGetExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_device_handle_t, uint32_t *, zet_metric_programmable_exp_handle_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricProgrammableGetExp_entry(
    void *btx_handle, lttng_ust_zet_zetMetricProgrammableGetExp_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricProgrammableGetExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zet_metric_programmable_exp_handle_t *);

void btx_register_callbacks_lttng_ust_zet_zetMetricProgrammableGetExp_exit(
    void *btx_handle, lttng_ust_zet_zetMetricProgrammableGetExp_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricProgrammableGetPropertiesExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_programmable_exp_handle_t, zet_metric_programmable_exp_properties_t *);

void btx_register_callbacks_lttng_ust_zet_zetMetricProgrammableGetPropertiesExp_entry(
    void *btx_handle, lttng_ust_zet_zetMetricProgrammableGetPropertiesExp_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricProgrammableGetPropertiesExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zet_metric_programmable_exp_properties_t *);

void btx_register_callbacks_lttng_ust_zet_zetMetricProgrammableGetPropertiesExp_exit(
    void *btx_handle, lttng_ust_zet_zetMetricProgrammableGetPropertiesExp_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricProgrammableGetParamInfoExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_programmable_exp_handle_t, uint32_t *, zet_metric_programmable_param_info_exp_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricProgrammableGetParamInfoExp_entry(
    void *btx_handle, lttng_ust_zet_zetMetricProgrammableGetParamInfoExp_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricProgrammableGetParamInfoExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zet_metric_programmable_param_info_exp_t *);

void btx_register_callbacks_lttng_ust_zet_zetMetricProgrammableGetParamInfoExp_exit(
    void *btx_handle, lttng_ust_zet_zetMetricProgrammableGetParamInfoExp_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricProgrammableGetParamValueInfoExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_programmable_exp_handle_t, uint32_t, uint32_t *, zet_metric_programmable_param_value_info_exp_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricProgrammableGetParamValueInfoExp_entry(
    void *btx_handle, lttng_ust_zet_zetMetricProgrammableGetParamValueInfoExp_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricProgrammableGetParamValueInfoExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zet_metric_programmable_param_value_info_exp_t *);

void btx_register_callbacks_lttng_ust_zet_zetMetricProgrammableGetParamValueInfoExp_exit(
    void *btx_handle, lttng_ust_zet_zetMetricProgrammableGetParamValueInfoExp_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricCreateFromProgrammableExp2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_programmable_exp_handle_t, uint32_t, zet_metric_programmable_param_value_exp_t *, char *, char *, uint32_t *, zet_metric_handle_t *);

void btx_register_callbacks_lttng_ust_zet_zetMetricCreateFromProgrammableExp2_entry(
    void *btx_handle, lttng_ust_zet_zetMetricCreateFromProgrammableExp2_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricCreateFromProgrammableExp2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricCreateFromProgrammableExp2_exit(
    void *btx_handle, lttng_ust_zet_zetMetricCreateFromProgrammableExp2_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricCreateFromProgrammableExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_programmable_exp_handle_t, zet_metric_programmable_param_value_exp_t *, uint32_t, char *, char *, uint32_t *, zet_metric_handle_t *, size_t, zet_metric_programmable_param_value_exp_t *, char *, char *, uint32_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricCreateFromProgrammableExp_entry(
    void *btx_handle, lttng_ust_zet_zetMetricCreateFromProgrammableExp_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricCreateFromProgrammableExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zet_metric_handle_t *);

void btx_register_callbacks_lttng_ust_zet_zetMetricCreateFromProgrammableExp_exit(
    void *btx_handle, lttng_ust_zet_zetMetricCreateFromProgrammableExp_exit_callback_f *callback);

typedef void lttng_ust_zet_zetDeviceCreateMetricGroupsFromMetricsExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_device_handle_t, uint32_t, zet_metric_handle_t *, char *, char *, uint32_t *, zet_metric_group_handle_t *);

void btx_register_callbacks_lttng_ust_zet_zetDeviceCreateMetricGroupsFromMetricsExp_entry(
    void *btx_handle, lttng_ust_zet_zetDeviceCreateMetricGroupsFromMetricsExp_entry_callback_f *callback);

typedef void lttng_ust_zet_zetDeviceCreateMetricGroupsFromMetricsExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetDeviceCreateMetricGroupsFromMetricsExp_exit(
    void *btx_handle, lttng_ust_zet_zetDeviceCreateMetricGroupsFromMetricsExp_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricGroupCreateExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_device_handle_t, char *, char *, zet_metric_group_sampling_type_flags_t, zet_metric_group_handle_t *, char *, char *);

void btx_register_callbacks_lttng_ust_zet_zetMetricGroupCreateExp_entry(
    void *btx_handle, lttng_ust_zet_zetMetricGroupCreateExp_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricGroupCreateExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, zet_metric_group_handle_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricGroupCreateExp_exit(
    void *btx_handle, lttng_ust_zet_zetMetricGroupCreateExp_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricGroupAddMetricExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_group_handle_t, zet_metric_handle_t, size_t *, char *, size_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricGroupAddMetricExp_entry(
    void *btx_handle, lttng_ust_zet_zetMetricGroupAddMetricExp_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricGroupAddMetricExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, size_t, char *);

void btx_register_callbacks_lttng_ust_zet_zetMetricGroupAddMetricExp_exit(
    void *btx_handle, lttng_ust_zet_zetMetricGroupAddMetricExp_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricGroupRemoveMetricExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_group_handle_t, zet_metric_handle_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricGroupRemoveMetricExp_entry(
    void *btx_handle, lttng_ust_zet_zetMetricGroupRemoveMetricExp_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricGroupRemoveMetricExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricGroupRemoveMetricExp_exit(
    void *btx_handle, lttng_ust_zet_zetMetricGroupRemoveMetricExp_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricGroupCloseExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_group_handle_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricGroupCloseExp_entry(
    void *btx_handle, lttng_ust_zet_zetMetricGroupCloseExp_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricGroupCloseExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricGroupCloseExp_exit(
    void *btx_handle, lttng_ust_zet_zetMetricGroupCloseExp_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricGroupDestroyExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_group_handle_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricGroupDestroyExp_entry(
    void *btx_handle, lttng_ust_zet_zetMetricGroupDestroyExp_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricGroupDestroyExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricGroupDestroyExp_exit(
    void *btx_handle, lttng_ust_zet_zetMetricGroupDestroyExp_exit_callback_f *callback);

typedef void lttng_ust_zet_zetMetricDestroyExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_handle_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricDestroyExp_entry(
    void *btx_handle, lttng_ust_zet_zetMetricDestroyExp_entry_callback_f *callback);

typedef void lttng_ust_zet_zetMetricDestroyExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetMetricDestroyExp_exit(
    void *btx_handle, lttng_ust_zet_zetMetricDestroyExp_exit_callback_f *callback);

typedef void lttng_ust_zet_zetGetMetricProgrammableExpProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zet_metric_programmable_exp_dditable_t *);

void btx_register_callbacks_lttng_ust_zet_zetGetMetricProgrammableExpProcAddrTable_entry(
    void *btx_handle, lttng_ust_zet_zetGetMetricProgrammableExpProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zet_zetGetMetricProgrammableExpProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetGetMetricProgrammableExpProcAddrTable_exit(
    void *btx_handle, lttng_ust_zet_zetGetMetricProgrammableExpProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zet_zetGetMetricTracerExpProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zet_metric_tracer_exp_dditable_t *);

void btx_register_callbacks_lttng_ust_zet_zetGetMetricTracerExpProcAddrTable_entry(
    void *btx_handle, lttng_ust_zet_zetGetMetricTracerExpProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zet_zetGetMetricTracerExpProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetGetMetricTracerExpProcAddrTable_exit(
    void *btx_handle, lttng_ust_zet_zetGetMetricTracerExpProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zet_zetGetMetricDecoderExpProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zet_metric_decoder_exp_dditable_t *);

void btx_register_callbacks_lttng_ust_zet_zetGetMetricDecoderExpProcAddrTable_entry(
    void *btx_handle, lttng_ust_zet_zetGetMetricDecoderExpProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zet_zetGetMetricDecoderExpProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetGetMetricDecoderExpProcAddrTable_exit(
    void *btx_handle, lttng_ust_zet_zetGetMetricDecoderExpProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zet_zetGetDeviceProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zet_device_dditable_t *);

void btx_register_callbacks_lttng_ust_zet_zetGetDeviceProcAddrTable_entry(
    void *btx_handle, lttng_ust_zet_zetGetDeviceProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zet_zetGetDeviceProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetGetDeviceProcAddrTable_exit(
    void *btx_handle, lttng_ust_zet_zetGetDeviceProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zet_zetGetDeviceExpProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zet_device_exp_dditable_t *);

void btx_register_callbacks_lttng_ust_zet_zetGetDeviceExpProcAddrTable_entry(
    void *btx_handle, lttng_ust_zet_zetGetDeviceExpProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zet_zetGetDeviceExpProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetGetDeviceExpProcAddrTable_exit(
    void *btx_handle, lttng_ust_zet_zetGetDeviceExpProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zet_zetGetContextProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zet_context_dditable_t *);

void btx_register_callbacks_lttng_ust_zet_zetGetContextProcAddrTable_entry(
    void *btx_handle, lttng_ust_zet_zetGetContextProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zet_zetGetContextProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetGetContextProcAddrTable_exit(
    void *btx_handle, lttng_ust_zet_zetGetContextProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zet_zetGetCommandListProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zet_command_list_dditable_t *);

void btx_register_callbacks_lttng_ust_zet_zetGetCommandListProcAddrTable_entry(
    void *btx_handle, lttng_ust_zet_zetGetCommandListProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zet_zetGetCommandListProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetGetCommandListProcAddrTable_exit(
    void *btx_handle, lttng_ust_zet_zetGetCommandListProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zet_zetGetCommandListExpProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zet_command_list_exp_dditable_t *);

void btx_register_callbacks_lttng_ust_zet_zetGetCommandListExpProcAddrTable_entry(
    void *btx_handle, lttng_ust_zet_zetGetCommandListExpProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zet_zetGetCommandListExpProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetGetCommandListExpProcAddrTable_exit(
    void *btx_handle, lttng_ust_zet_zetGetCommandListExpProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zet_zetGetModuleProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zet_module_dditable_t *);

void btx_register_callbacks_lttng_ust_zet_zetGetModuleProcAddrTable_entry(
    void *btx_handle, lttng_ust_zet_zetGetModuleProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zet_zetGetModuleProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetGetModuleProcAddrTable_exit(
    void *btx_handle, lttng_ust_zet_zetGetModuleProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zet_zetGetKernelProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zet_kernel_dditable_t *);

void btx_register_callbacks_lttng_ust_zet_zetGetKernelProcAddrTable_entry(
    void *btx_handle, lttng_ust_zet_zetGetKernelProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zet_zetGetKernelProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetGetKernelProcAddrTable_exit(
    void *btx_handle, lttng_ust_zet_zetGetKernelProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zet_zetGetMetricProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zet_metric_dditable_t *);

void btx_register_callbacks_lttng_ust_zet_zetGetMetricProcAddrTable_entry(
    void *btx_handle, lttng_ust_zet_zetGetMetricProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zet_zetGetMetricProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetGetMetricProcAddrTable_exit(
    void *btx_handle, lttng_ust_zet_zetGetMetricProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zet_zetGetMetricExpProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zet_metric_exp_dditable_t *);

void btx_register_callbacks_lttng_ust_zet_zetGetMetricExpProcAddrTable_entry(
    void *btx_handle, lttng_ust_zet_zetGetMetricExpProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zet_zetGetMetricExpProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetGetMetricExpProcAddrTable_exit(
    void *btx_handle, lttng_ust_zet_zetGetMetricExpProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zet_zetGetMetricGroupProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zet_metric_group_dditable_t *);

void btx_register_callbacks_lttng_ust_zet_zetGetMetricGroupProcAddrTable_entry(
    void *btx_handle, lttng_ust_zet_zetGetMetricGroupProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zet_zetGetMetricGroupProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetGetMetricGroupProcAddrTable_exit(
    void *btx_handle, lttng_ust_zet_zetGetMetricGroupProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zet_zetGetMetricGroupExpProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zet_metric_group_exp_dditable_t *);

void btx_register_callbacks_lttng_ust_zet_zetGetMetricGroupExpProcAddrTable_entry(
    void *btx_handle, lttng_ust_zet_zetGetMetricGroupExpProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zet_zetGetMetricGroupExpProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetGetMetricGroupExpProcAddrTable_exit(
    void *btx_handle, lttng_ust_zet_zetGetMetricGroupExpProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zet_zetGetMetricStreamerProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zet_metric_streamer_dditable_t *);

void btx_register_callbacks_lttng_ust_zet_zetGetMetricStreamerProcAddrTable_entry(
    void *btx_handle, lttng_ust_zet_zetGetMetricStreamerProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zet_zetGetMetricStreamerProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetGetMetricStreamerProcAddrTable_exit(
    void *btx_handle, lttng_ust_zet_zetGetMetricStreamerProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zet_zetGetMetricQueryPoolProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zet_metric_query_pool_dditable_t *);

void btx_register_callbacks_lttng_ust_zet_zetGetMetricQueryPoolProcAddrTable_entry(
    void *btx_handle, lttng_ust_zet_zetGetMetricQueryPoolProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zet_zetGetMetricQueryPoolProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetGetMetricQueryPoolProcAddrTable_exit(
    void *btx_handle, lttng_ust_zet_zetGetMetricQueryPoolProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zet_zetGetMetricQueryProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zet_metric_query_dditable_t *);

void btx_register_callbacks_lttng_ust_zet_zetGetMetricQueryProcAddrTable_entry(
    void *btx_handle, lttng_ust_zet_zetGetMetricQueryProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zet_zetGetMetricQueryProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetGetMetricQueryProcAddrTable_exit(
    void *btx_handle, lttng_ust_zet_zetGetMetricQueryProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zet_zetGetTracerExpProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zet_tracer_exp_dditable_t *);

void btx_register_callbacks_lttng_ust_zet_zetGetTracerExpProcAddrTable_entry(
    void *btx_handle, lttng_ust_zet_zetGetTracerExpProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zet_zetGetTracerExpProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetGetTracerExpProcAddrTable_exit(
    void *btx_handle, lttng_ust_zet_zetGetTracerExpProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zet_zetGetDebugProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zet_debug_dditable_t *);

void btx_register_callbacks_lttng_ust_zet_zetGetDebugProcAddrTable_entry(
    void *btx_handle, lttng_ust_zet_zetGetDebugProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zet_zetGetDebugProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zet_zetGetDebugProcAddrTable_exit(
    void *btx_handle, lttng_ust_zet_zetGetDebugProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zes_zesInit_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_init_flags_t);

void btx_register_callbacks_lttng_ust_zes_zesInit_entry(
    void *btx_handle, lttng_ust_zes_zesInit_entry_callback_f *callback);

typedef void lttng_ust_zes_zesInit_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesInit_exit(
    void *btx_handle, lttng_ust_zes_zesInit_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDriverGet_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, uint32_t *, zes_driver_handle_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesDriverGet_entry(
    void *btx_handle, lttng_ust_zes_zesDriverGet_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDriverGet_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zes_driver_handle_t *);

void btx_register_callbacks_lttng_ust_zes_zesDriverGet_exit(
    void *btx_handle, lttng_ust_zes_zesDriverGet_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDriverGetExtensionProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_driver_handle_t, uint32_t *, zes_driver_extension_properties_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesDriverGetExtensionProperties_entry(
    void *btx_handle, lttng_ust_zes_zesDriverGetExtensionProperties_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDriverGetExtensionProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zes_driver_extension_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesDriverGetExtensionProperties_exit(
    void *btx_handle, lttng_ust_zes_zesDriverGetExtensionProperties_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDriverGetExtensionFunctionAddress_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_driver_handle_t, char *, void **, char *);

void btx_register_callbacks_lttng_ust_zes_zesDriverGetExtensionFunctionAddress_entry(
    void *btx_handle, lttng_ust_zes_zesDriverGetExtensionFunctionAddress_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDriverGetExtensionFunctionAddress_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, void *);

void btx_register_callbacks_lttng_ust_zes_zesDriverGetExtensionFunctionAddress_exit(
    void *btx_handle, lttng_ust_zes_zesDriverGetExtensionFunctionAddress_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceGet_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_driver_handle_t, uint32_t *, zes_device_handle_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesDeviceGet_entry(
    void *btx_handle, lttng_ust_zes_zesDeviceGet_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceGet_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zes_device_handle_t *);

void btx_register_callbacks_lttng_ust_zes_zesDeviceGet_exit(
    void *btx_handle, lttng_ust_zes_zesDeviceGet_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceGetProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, zes_device_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesDeviceGetProperties_entry(
    void *btx_handle, lttng_ust_zes_zesDeviceGetProperties_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceGetProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_device_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesDeviceGetProperties_exit(
    void *btx_handle, lttng_ust_zes_zesDeviceGetProperties_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceGetState_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, zes_device_state_t *);

void btx_register_callbacks_lttng_ust_zes_zesDeviceGetState_entry(
    void *btx_handle, lttng_ust_zes_zesDeviceGetState_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceGetState_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_device_state_t *);

void btx_register_callbacks_lttng_ust_zes_zesDeviceGetState_exit(
    void *btx_handle, lttng_ust_zes_zesDeviceGetState_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceReset_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, ze_bool_t);

void btx_register_callbacks_lttng_ust_zes_zesDeviceReset_entry(
    void *btx_handle, lttng_ust_zes_zesDeviceReset_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceReset_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesDeviceReset_exit(
    void *btx_handle, lttng_ust_zes_zesDeviceReset_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceResetExt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, zes_reset_properties_t *, size_t, zes_reset_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesDeviceResetExt_entry(
    void *btx_handle, lttng_ust_zes_zesDeviceResetExt_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceResetExt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesDeviceResetExt_exit(
    void *btx_handle, lttng_ust_zes_zesDeviceResetExt_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceProcessesGetState_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, uint32_t *, zes_process_state_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesDeviceProcessesGetState_entry(
    void *btx_handle, lttng_ust_zes_zesDeviceProcessesGetState_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceProcessesGetState_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zes_process_state_t *);

void btx_register_callbacks_lttng_ust_zes_zesDeviceProcessesGetState_exit(
    void *btx_handle, lttng_ust_zes_zesDeviceProcessesGetState_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDevicePciGetProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, zes_pci_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesDevicePciGetProperties_entry(
    void *btx_handle, lttng_ust_zes_zesDevicePciGetProperties_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDevicePciGetProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_pci_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesDevicePciGetProperties_exit(
    void *btx_handle, lttng_ust_zes_zesDevicePciGetProperties_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDevicePciGetState_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, zes_pci_state_t *);

void btx_register_callbacks_lttng_ust_zes_zesDevicePciGetState_entry(
    void *btx_handle, lttng_ust_zes_zesDevicePciGetState_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDevicePciGetState_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_pci_state_t *);

void btx_register_callbacks_lttng_ust_zes_zesDevicePciGetState_exit(
    void *btx_handle, lttng_ust_zes_zesDevicePciGetState_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDevicePciGetBars_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, uint32_t *, zes_pci_bar_properties_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesDevicePciGetBars_entry(
    void *btx_handle, lttng_ust_zes_zesDevicePciGetBars_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDevicePciGetBars_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zes_pci_bar_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesDevicePciGetBars_exit(
    void *btx_handle, lttng_ust_zes_zesDevicePciGetBars_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDevicePciGetStats_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, zes_pci_stats_t *);

void btx_register_callbacks_lttng_ust_zes_zesDevicePciGetStats_entry(
    void *btx_handle, lttng_ust_zes_zesDevicePciGetStats_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDevicePciGetStats_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_pci_stats_t *);

void btx_register_callbacks_lttng_ust_zes_zesDevicePciGetStats_exit(
    void *btx_handle, lttng_ust_zes_zesDevicePciGetStats_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceSetOverclockWaiver_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t);

void btx_register_callbacks_lttng_ust_zes_zesDeviceSetOverclockWaiver_entry(
    void *btx_handle, lttng_ust_zes_zesDeviceSetOverclockWaiver_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceSetOverclockWaiver_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesDeviceSetOverclockWaiver_exit(
    void *btx_handle, lttng_ust_zes_zesDeviceSetOverclockWaiver_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceGetOverclockDomains_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, uint32_t *);

void btx_register_callbacks_lttng_ust_zes_zesDeviceGetOverclockDomains_entry(
    void *btx_handle, lttng_ust_zes_zesDeviceGetOverclockDomains_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceGetOverclockDomains_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesDeviceGetOverclockDomains_exit(
    void *btx_handle, lttng_ust_zes_zesDeviceGetOverclockDomains_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceGetOverclockControls_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, zes_overclock_domain_t, uint32_t *);

void btx_register_callbacks_lttng_ust_zes_zesDeviceGetOverclockControls_entry(
    void *btx_handle, lttng_ust_zes_zesDeviceGetOverclockControls_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceGetOverclockControls_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesDeviceGetOverclockControls_exit(
    void *btx_handle, lttng_ust_zes_zesDeviceGetOverclockControls_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceResetOverclockSettings_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, ze_bool_t);

void btx_register_callbacks_lttng_ust_zes_zesDeviceResetOverclockSettings_entry(
    void *btx_handle, lttng_ust_zes_zesDeviceResetOverclockSettings_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceResetOverclockSettings_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesDeviceResetOverclockSettings_exit(
    void *btx_handle, lttng_ust_zes_zesDeviceResetOverclockSettings_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceReadOverclockState_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, zes_overclock_mode_t *, ze_bool_t *, ze_bool_t *, zes_pending_action_t *, ze_bool_t *);

void btx_register_callbacks_lttng_ust_zes_zesDeviceReadOverclockState_entry(
    void *btx_handle, lttng_ust_zes_zesDeviceReadOverclockState_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceReadOverclockState_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, zes_overclock_mode_t, ze_bool_t, ze_bool_t, zes_pending_action_t, ze_bool_t);

void btx_register_callbacks_lttng_ust_zes_zesDeviceReadOverclockState_exit(
    void *btx_handle, lttng_ust_zes_zesDeviceReadOverclockState_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEnumOverclockDomains_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, uint32_t *, zes_overclock_handle_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEnumOverclockDomains_entry(
    void *btx_handle, lttng_ust_zes_zesDeviceEnumOverclockDomains_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEnumOverclockDomains_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zes_overclock_handle_t *);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEnumOverclockDomains_exit(
    void *btx_handle, lttng_ust_zes_zesDeviceEnumOverclockDomains_exit_callback_f *callback);

typedef void lttng_ust_zes_zesOverclockGetDomainProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_overclock_handle_t, zes_overclock_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesOverclockGetDomainProperties_entry(
    void *btx_handle, lttng_ust_zes_zesOverclockGetDomainProperties_entry_callback_f *callback);

typedef void lttng_ust_zes_zesOverclockGetDomainProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_overclock_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesOverclockGetDomainProperties_exit(
    void *btx_handle, lttng_ust_zes_zesOverclockGetDomainProperties_exit_callback_f *callback);

typedef void lttng_ust_zes_zesOverclockGetDomainVFProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_overclock_handle_t, zes_vf_property_t *);

void btx_register_callbacks_lttng_ust_zes_zesOverclockGetDomainVFProperties_entry(
    void *btx_handle, lttng_ust_zes_zesOverclockGetDomainVFProperties_entry_callback_f *callback);

typedef void lttng_ust_zes_zesOverclockGetDomainVFProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_vf_property_t *);

void btx_register_callbacks_lttng_ust_zes_zesOverclockGetDomainVFProperties_exit(
    void *btx_handle, lttng_ust_zes_zesOverclockGetDomainVFProperties_exit_callback_f *callback);

typedef void lttng_ust_zes_zesOverclockGetDomainControlProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_overclock_handle_t, zes_overclock_control_t, zes_control_property_t *);

void btx_register_callbacks_lttng_ust_zes_zesOverclockGetDomainControlProperties_entry(
    void *btx_handle, lttng_ust_zes_zesOverclockGetDomainControlProperties_entry_callback_f *callback);

typedef void lttng_ust_zes_zesOverclockGetDomainControlProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_control_property_t *);

void btx_register_callbacks_lttng_ust_zes_zesOverclockGetDomainControlProperties_exit(
    void *btx_handle, lttng_ust_zes_zesOverclockGetDomainControlProperties_exit_callback_f *callback);

typedef void lttng_ust_zes_zesOverclockGetControlCurrentValue_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_overclock_handle_t, zes_overclock_control_t, double *);

void btx_register_callbacks_lttng_ust_zes_zesOverclockGetControlCurrentValue_entry(
    void *btx_handle, lttng_ust_zes_zesOverclockGetControlCurrentValue_entry_callback_f *callback);

typedef void lttng_ust_zes_zesOverclockGetControlCurrentValue_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, double);

void btx_register_callbacks_lttng_ust_zes_zesOverclockGetControlCurrentValue_exit(
    void *btx_handle, lttng_ust_zes_zesOverclockGetControlCurrentValue_exit_callback_f *callback);

typedef void lttng_ust_zes_zesOverclockGetControlPendingValue_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_overclock_handle_t, zes_overclock_control_t, double *);

void btx_register_callbacks_lttng_ust_zes_zesOverclockGetControlPendingValue_entry(
    void *btx_handle, lttng_ust_zes_zesOverclockGetControlPendingValue_entry_callback_f *callback);

typedef void lttng_ust_zes_zesOverclockGetControlPendingValue_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, double);

void btx_register_callbacks_lttng_ust_zes_zesOverclockGetControlPendingValue_exit(
    void *btx_handle, lttng_ust_zes_zesOverclockGetControlPendingValue_exit_callback_f *callback);

typedef void lttng_ust_zes_zesOverclockSetControlUserValue_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_overclock_handle_t, zes_overclock_control_t, double, zes_pending_action_t *);

void btx_register_callbacks_lttng_ust_zes_zesOverclockSetControlUserValue_entry(
    void *btx_handle, lttng_ust_zes_zesOverclockSetControlUserValue_entry_callback_f *callback);

typedef void lttng_ust_zes_zesOverclockSetControlUserValue_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, zes_pending_action_t);

void btx_register_callbacks_lttng_ust_zes_zesOverclockSetControlUserValue_exit(
    void *btx_handle, lttng_ust_zes_zesOverclockSetControlUserValue_exit_callback_f *callback);

typedef void lttng_ust_zes_zesOverclockGetControlState_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_overclock_handle_t, zes_overclock_control_t, zes_control_state_t *, zes_pending_action_t *);

void btx_register_callbacks_lttng_ust_zes_zesOverclockGetControlState_entry(
    void *btx_handle, lttng_ust_zes_zesOverclockGetControlState_entry_callback_f *callback);

typedef void lttng_ust_zes_zesOverclockGetControlState_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, zes_control_state_t, zes_pending_action_t);

void btx_register_callbacks_lttng_ust_zes_zesOverclockGetControlState_exit(
    void *btx_handle, lttng_ust_zes_zesOverclockGetControlState_exit_callback_f *callback);

typedef void lttng_ust_zes_zesOverclockGetVFPointValues_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_overclock_handle_t, zes_vf_type_t, zes_vf_array_type_t, uint32_t, uint32_t *);

void btx_register_callbacks_lttng_ust_zes_zesOverclockGetVFPointValues_entry(
    void *btx_handle, lttng_ust_zes_zesOverclockGetVFPointValues_entry_callback_f *callback);

typedef void lttng_ust_zes_zesOverclockGetVFPointValues_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesOverclockGetVFPointValues_exit(
    void *btx_handle, lttng_ust_zes_zesOverclockGetVFPointValues_exit_callback_f *callback);

typedef void lttng_ust_zes_zesOverclockSetVFPointValues_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_overclock_handle_t, zes_vf_type_t, uint32_t, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesOverclockSetVFPointValues_entry(
    void *btx_handle, lttng_ust_zes_zesOverclockSetVFPointValues_entry_callback_f *callback);

typedef void lttng_ust_zes_zesOverclockSetVFPointValues_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesOverclockSetVFPointValues_exit(
    void *btx_handle, lttng_ust_zes_zesOverclockSetVFPointValues_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEnumDiagnosticTestSuites_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, uint32_t *, zes_diag_handle_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEnumDiagnosticTestSuites_entry(
    void *btx_handle, lttng_ust_zes_zesDeviceEnumDiagnosticTestSuites_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEnumDiagnosticTestSuites_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zes_diag_handle_t *);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEnumDiagnosticTestSuites_exit(
    void *btx_handle, lttng_ust_zes_zesDeviceEnumDiagnosticTestSuites_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDiagnosticsGetProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_diag_handle_t, zes_diag_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesDiagnosticsGetProperties_entry(
    void *btx_handle, lttng_ust_zes_zesDiagnosticsGetProperties_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDiagnosticsGetProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_diag_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesDiagnosticsGetProperties_exit(
    void *btx_handle, lttng_ust_zes_zesDiagnosticsGetProperties_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDiagnosticsGetTests_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_diag_handle_t, uint32_t *, zes_diag_test_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesDiagnosticsGetTests_entry(
    void *btx_handle, lttng_ust_zes_zesDiagnosticsGetTests_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDiagnosticsGetTests_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zes_diag_test_t *);

void btx_register_callbacks_lttng_ust_zes_zesDiagnosticsGetTests_exit(
    void *btx_handle, lttng_ust_zes_zesDiagnosticsGetTests_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDiagnosticsRunTests_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_diag_handle_t, uint32_t, uint32_t, zes_diag_result_t *);

void btx_register_callbacks_lttng_ust_zes_zesDiagnosticsRunTests_entry(
    void *btx_handle, lttng_ust_zes_zesDiagnosticsRunTests_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDiagnosticsRunTests_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, zes_diag_result_t);

void btx_register_callbacks_lttng_ust_zes_zesDiagnosticsRunTests_exit(
    void *btx_handle, lttng_ust_zes_zesDiagnosticsRunTests_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEccAvailable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, ze_bool_t *);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEccAvailable_entry(
    void *btx_handle, lttng_ust_zes_zesDeviceEccAvailable_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEccAvailable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_bool_t);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEccAvailable_exit(
    void *btx_handle, lttng_ust_zes_zesDeviceEccAvailable_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEccConfigurable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, ze_bool_t *);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEccConfigurable_entry(
    void *btx_handle, lttng_ust_zes_zesDeviceEccConfigurable_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEccConfigurable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_bool_t);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEccConfigurable_exit(
    void *btx_handle, lttng_ust_zes_zesDeviceEccConfigurable_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceGetEccState_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, zes_device_ecc_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesDeviceGetEccState_entry(
    void *btx_handle, lttng_ust_zes_zesDeviceGetEccState_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceGetEccState_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_device_ecc_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesDeviceGetEccState_exit(
    void *btx_handle, lttng_ust_zes_zesDeviceGetEccState_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceSetEccState_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, zes_device_ecc_desc_t *, zes_device_ecc_properties_t *, size_t, zes_device_ecc_desc_t *);

void btx_register_callbacks_lttng_ust_zes_zesDeviceSetEccState_entry(
    void *btx_handle, lttng_ust_zes_zesDeviceSetEccState_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceSetEccState_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_device_ecc_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesDeviceSetEccState_exit(
    void *btx_handle, lttng_ust_zes_zesDeviceSetEccState_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEnumEngineGroups_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, uint32_t *, zes_engine_handle_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEnumEngineGroups_entry(
    void *btx_handle, lttng_ust_zes_zesDeviceEnumEngineGroups_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEnumEngineGroups_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zes_engine_handle_t *);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEnumEngineGroups_exit(
    void *btx_handle, lttng_ust_zes_zesDeviceEnumEngineGroups_exit_callback_f *callback);

typedef void lttng_ust_zes_zesEngineGetProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_engine_handle_t, zes_engine_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesEngineGetProperties_entry(
    void *btx_handle, lttng_ust_zes_zesEngineGetProperties_entry_callback_f *callback);

typedef void lttng_ust_zes_zesEngineGetProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_engine_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesEngineGetProperties_exit(
    void *btx_handle, lttng_ust_zes_zesEngineGetProperties_exit_callback_f *callback);

typedef void lttng_ust_zes_zesEngineGetActivity_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_engine_handle_t, zes_engine_stats_t *);

void btx_register_callbacks_lttng_ust_zes_zesEngineGetActivity_entry(
    void *btx_handle, lttng_ust_zes_zesEngineGetActivity_entry_callback_f *callback);

typedef void lttng_ust_zes_zesEngineGetActivity_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_engine_stats_t *);

void btx_register_callbacks_lttng_ust_zes_zesEngineGetActivity_exit(
    void *btx_handle, lttng_ust_zes_zesEngineGetActivity_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEventRegister_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, zes_event_type_flags_t);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEventRegister_entry(
    void *btx_handle, lttng_ust_zes_zesDeviceEventRegister_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEventRegister_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEventRegister_exit(
    void *btx_handle, lttng_ust_zes_zesDeviceEventRegister_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDriverEventListen_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_driver_handle_t, uint32_t, uint32_t, zes_device_handle_t *, uint32_t *, zes_event_type_flags_t *, size_t, zes_device_handle_t *);

void btx_register_callbacks_lttng_ust_zes_zesDriverEventListen_entry(
    void *btx_handle, lttng_ust_zes_zesDriverEventListen_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDriverEventListen_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zes_event_type_flags_t *);

void btx_register_callbacks_lttng_ust_zes_zesDriverEventListen_exit(
    void *btx_handle, lttng_ust_zes_zesDriverEventListen_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDriverEventListenEx_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_driver_handle_t, uint64_t, uint32_t, zes_device_handle_t *, uint32_t *, zes_event_type_flags_t *, size_t, zes_device_handle_t *);

void btx_register_callbacks_lttng_ust_zes_zesDriverEventListenEx_entry(
    void *btx_handle, lttng_ust_zes_zesDriverEventListenEx_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDriverEventListenEx_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zes_event_type_flags_t *);

void btx_register_callbacks_lttng_ust_zes_zesDriverEventListenEx_exit(
    void *btx_handle, lttng_ust_zes_zesDriverEventListenEx_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEnumFabricPorts_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, uint32_t *, zes_fabric_port_handle_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEnumFabricPorts_entry(
    void *btx_handle, lttng_ust_zes_zesDeviceEnumFabricPorts_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEnumFabricPorts_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zes_fabric_port_handle_t *);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEnumFabricPorts_exit(
    void *btx_handle, lttng_ust_zes_zesDeviceEnumFabricPorts_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFabricPortGetProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_fabric_port_handle_t, zes_fabric_port_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesFabricPortGetProperties_entry(
    void *btx_handle, lttng_ust_zes_zesFabricPortGetProperties_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFabricPortGetProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_fabric_port_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesFabricPortGetProperties_exit(
    void *btx_handle, lttng_ust_zes_zesFabricPortGetProperties_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFabricPortGetLinkType_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_fabric_port_handle_t, zes_fabric_link_type_t *);

void btx_register_callbacks_lttng_ust_zes_zesFabricPortGetLinkType_entry(
    void *btx_handle, lttng_ust_zes_zesFabricPortGetLinkType_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFabricPortGetLinkType_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_fabric_link_type_t *);

void btx_register_callbacks_lttng_ust_zes_zesFabricPortGetLinkType_exit(
    void *btx_handle, lttng_ust_zes_zesFabricPortGetLinkType_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFabricPortGetConfig_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_fabric_port_handle_t, zes_fabric_port_config_t *);

void btx_register_callbacks_lttng_ust_zes_zesFabricPortGetConfig_entry(
    void *btx_handle, lttng_ust_zes_zesFabricPortGetConfig_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFabricPortGetConfig_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_fabric_port_config_t *);

void btx_register_callbacks_lttng_ust_zes_zesFabricPortGetConfig_exit(
    void *btx_handle, lttng_ust_zes_zesFabricPortGetConfig_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFabricPortSetConfig_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_fabric_port_handle_t, zes_fabric_port_config_t *, size_t, zes_fabric_port_config_t *);

void btx_register_callbacks_lttng_ust_zes_zesFabricPortSetConfig_entry(
    void *btx_handle, lttng_ust_zes_zesFabricPortSetConfig_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFabricPortSetConfig_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesFabricPortSetConfig_exit(
    void *btx_handle, lttng_ust_zes_zesFabricPortSetConfig_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFabricPortGetState_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_fabric_port_handle_t, zes_fabric_port_state_t *);

void btx_register_callbacks_lttng_ust_zes_zesFabricPortGetState_entry(
    void *btx_handle, lttng_ust_zes_zesFabricPortGetState_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFabricPortGetState_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_fabric_port_state_t *);

void btx_register_callbacks_lttng_ust_zes_zesFabricPortGetState_exit(
    void *btx_handle, lttng_ust_zes_zesFabricPortGetState_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFabricPortGetThroughput_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_fabric_port_handle_t, zes_fabric_port_throughput_t *);

void btx_register_callbacks_lttng_ust_zes_zesFabricPortGetThroughput_entry(
    void *btx_handle, lttng_ust_zes_zesFabricPortGetThroughput_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFabricPortGetThroughput_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_fabric_port_throughput_t *);

void btx_register_callbacks_lttng_ust_zes_zesFabricPortGetThroughput_exit(
    void *btx_handle, lttng_ust_zes_zesFabricPortGetThroughput_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFabricPortGetFabricErrorCounters_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_fabric_port_handle_t, zes_fabric_port_error_counters_t *);

void btx_register_callbacks_lttng_ust_zes_zesFabricPortGetFabricErrorCounters_entry(
    void *btx_handle, lttng_ust_zes_zesFabricPortGetFabricErrorCounters_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFabricPortGetFabricErrorCounters_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_fabric_port_error_counters_t *);

void btx_register_callbacks_lttng_ust_zes_zesFabricPortGetFabricErrorCounters_exit(
    void *btx_handle, lttng_ust_zes_zesFabricPortGetFabricErrorCounters_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFabricPortGetMultiPortThroughput_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, uint32_t, zes_fabric_port_handle_t *, zes_fabric_port_throughput_t **, size_t, zes_fabric_port_handle_t *);

void btx_register_callbacks_lttng_ust_zes_zesFabricPortGetMultiPortThroughput_entry(
    void *btx_handle, lttng_ust_zes_zesFabricPortGetMultiPortThroughput_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFabricPortGetMultiPortThroughput_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_fabric_port_throughput_t * *);

void btx_register_callbacks_lttng_ust_zes_zesFabricPortGetMultiPortThroughput_exit(
    void *btx_handle, lttng_ust_zes_zesFabricPortGetMultiPortThroughput_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEnumFans_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, uint32_t *, zes_fan_handle_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEnumFans_entry(
    void *btx_handle, lttng_ust_zes_zesDeviceEnumFans_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEnumFans_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zes_fan_handle_t *);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEnumFans_exit(
    void *btx_handle, lttng_ust_zes_zesDeviceEnumFans_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFanGetProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_fan_handle_t, zes_fan_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesFanGetProperties_entry(
    void *btx_handle, lttng_ust_zes_zesFanGetProperties_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFanGetProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_fan_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesFanGetProperties_exit(
    void *btx_handle, lttng_ust_zes_zesFanGetProperties_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFanGetConfig_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_fan_handle_t, zes_fan_config_t *);

void btx_register_callbacks_lttng_ust_zes_zesFanGetConfig_entry(
    void *btx_handle, lttng_ust_zes_zesFanGetConfig_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFanGetConfig_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_fan_config_t *);

void btx_register_callbacks_lttng_ust_zes_zesFanGetConfig_exit(
    void *btx_handle, lttng_ust_zes_zesFanGetConfig_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFanSetDefaultMode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_fan_handle_t);

void btx_register_callbacks_lttng_ust_zes_zesFanSetDefaultMode_entry(
    void *btx_handle, lttng_ust_zes_zesFanSetDefaultMode_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFanSetDefaultMode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesFanSetDefaultMode_exit(
    void *btx_handle, lttng_ust_zes_zesFanSetDefaultMode_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFanSetFixedSpeedMode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_fan_handle_t, zes_fan_speed_t *, size_t, zes_fan_speed_t *);

void btx_register_callbacks_lttng_ust_zes_zesFanSetFixedSpeedMode_entry(
    void *btx_handle, lttng_ust_zes_zesFanSetFixedSpeedMode_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFanSetFixedSpeedMode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesFanSetFixedSpeedMode_exit(
    void *btx_handle, lttng_ust_zes_zesFanSetFixedSpeedMode_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFanSetSpeedTableMode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_fan_handle_t, zes_fan_speed_table_t *, size_t, zes_fan_speed_table_t *);

void btx_register_callbacks_lttng_ust_zes_zesFanSetSpeedTableMode_entry(
    void *btx_handle, lttng_ust_zes_zesFanSetSpeedTableMode_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFanSetSpeedTableMode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesFanSetSpeedTableMode_exit(
    void *btx_handle, lttng_ust_zes_zesFanSetSpeedTableMode_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFanGetState_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_fan_handle_t, zes_fan_speed_units_t, int32_t *);

void btx_register_callbacks_lttng_ust_zes_zesFanGetState_entry(
    void *btx_handle, lttng_ust_zes_zesFanGetState_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFanGetState_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, int32_t);

void btx_register_callbacks_lttng_ust_zes_zesFanGetState_exit(
    void *btx_handle, lttng_ust_zes_zesFanGetState_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEnumFirmwares_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, uint32_t *, zes_firmware_handle_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEnumFirmwares_entry(
    void *btx_handle, lttng_ust_zes_zesDeviceEnumFirmwares_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEnumFirmwares_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zes_firmware_handle_t *);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEnumFirmwares_exit(
    void *btx_handle, lttng_ust_zes_zesDeviceEnumFirmwares_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFirmwareGetProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_firmware_handle_t, zes_firmware_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesFirmwareGetProperties_entry(
    void *btx_handle, lttng_ust_zes_zesFirmwareGetProperties_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFirmwareGetProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_firmware_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesFirmwareGetProperties_exit(
    void *btx_handle, lttng_ust_zes_zesFirmwareGetProperties_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFirmwareFlash_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_firmware_handle_t, void *, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesFirmwareFlash_entry(
    void *btx_handle, lttng_ust_zes_zesFirmwareFlash_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFirmwareFlash_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesFirmwareFlash_exit(
    void *btx_handle, lttng_ust_zes_zesFirmwareFlash_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFirmwareGetFlashProgress_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_firmware_handle_t, uint32_t *);

void btx_register_callbacks_lttng_ust_zes_zesFirmwareGetFlashProgress_entry(
    void *btx_handle, lttng_ust_zes_zesFirmwareGetFlashProgress_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFirmwareGetFlashProgress_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesFirmwareGetFlashProgress_exit(
    void *btx_handle, lttng_ust_zes_zesFirmwareGetFlashProgress_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFirmwareGetConsoleLogs_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_firmware_handle_t, size_t *, char *, size_t);

void btx_register_callbacks_lttng_ust_zes_zesFirmwareGetConsoleLogs_entry(
    void *btx_handle, lttng_ust_zes_zesFirmwareGetConsoleLogs_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFirmwareGetConsoleLogs_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, size_t, char *);

void btx_register_callbacks_lttng_ust_zes_zesFirmwareGetConsoleLogs_exit(
    void *btx_handle, lttng_ust_zes_zesFirmwareGetConsoleLogs_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEnumFrequencyDomains_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, uint32_t *, zes_freq_handle_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEnumFrequencyDomains_entry(
    void *btx_handle, lttng_ust_zes_zesDeviceEnumFrequencyDomains_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEnumFrequencyDomains_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zes_freq_handle_t *);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEnumFrequencyDomains_exit(
    void *btx_handle, lttng_ust_zes_zesDeviceEnumFrequencyDomains_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFrequencyGetProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_freq_handle_t, zes_freq_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesFrequencyGetProperties_entry(
    void *btx_handle, lttng_ust_zes_zesFrequencyGetProperties_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFrequencyGetProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_freq_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesFrequencyGetProperties_exit(
    void *btx_handle, lttng_ust_zes_zesFrequencyGetProperties_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFrequencyGetAvailableClocks_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_freq_handle_t, uint32_t *, double *, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesFrequencyGetAvailableClocks_entry(
    void *btx_handle, lttng_ust_zes_zesFrequencyGetAvailableClocks_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFrequencyGetAvailableClocks_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, double *);

void btx_register_callbacks_lttng_ust_zes_zesFrequencyGetAvailableClocks_exit(
    void *btx_handle, lttng_ust_zes_zesFrequencyGetAvailableClocks_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFrequencyGetRange_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_freq_handle_t, zes_freq_range_t *);

void btx_register_callbacks_lttng_ust_zes_zesFrequencyGetRange_entry(
    void *btx_handle, lttng_ust_zes_zesFrequencyGetRange_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFrequencyGetRange_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_freq_range_t *);

void btx_register_callbacks_lttng_ust_zes_zesFrequencyGetRange_exit(
    void *btx_handle, lttng_ust_zes_zesFrequencyGetRange_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFrequencySetRange_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_freq_handle_t, zes_freq_range_t *, size_t, zes_freq_range_t *);

void btx_register_callbacks_lttng_ust_zes_zesFrequencySetRange_entry(
    void *btx_handle, lttng_ust_zes_zesFrequencySetRange_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFrequencySetRange_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesFrequencySetRange_exit(
    void *btx_handle, lttng_ust_zes_zesFrequencySetRange_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFrequencyGetState_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_freq_handle_t, zes_freq_state_t *);

void btx_register_callbacks_lttng_ust_zes_zesFrequencyGetState_entry(
    void *btx_handle, lttng_ust_zes_zesFrequencyGetState_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFrequencyGetState_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_freq_state_t *);

void btx_register_callbacks_lttng_ust_zes_zesFrequencyGetState_exit(
    void *btx_handle, lttng_ust_zes_zesFrequencyGetState_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFrequencyGetThrottleTime_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_freq_handle_t, zes_freq_throttle_time_t *);

void btx_register_callbacks_lttng_ust_zes_zesFrequencyGetThrottleTime_entry(
    void *btx_handle, lttng_ust_zes_zesFrequencyGetThrottleTime_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFrequencyGetThrottleTime_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_freq_throttle_time_t *);

void btx_register_callbacks_lttng_ust_zes_zesFrequencyGetThrottleTime_exit(
    void *btx_handle, lttng_ust_zes_zesFrequencyGetThrottleTime_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFrequencyOcGetCapabilities_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_freq_handle_t, zes_oc_capabilities_t *);

void btx_register_callbacks_lttng_ust_zes_zesFrequencyOcGetCapabilities_entry(
    void *btx_handle, lttng_ust_zes_zesFrequencyOcGetCapabilities_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFrequencyOcGetCapabilities_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_oc_capabilities_t *);

void btx_register_callbacks_lttng_ust_zes_zesFrequencyOcGetCapabilities_exit(
    void *btx_handle, lttng_ust_zes_zesFrequencyOcGetCapabilities_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFrequencyOcGetFrequencyTarget_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_freq_handle_t, double *);

void btx_register_callbacks_lttng_ust_zes_zesFrequencyOcGetFrequencyTarget_entry(
    void *btx_handle, lttng_ust_zes_zesFrequencyOcGetFrequencyTarget_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFrequencyOcGetFrequencyTarget_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, double);

void btx_register_callbacks_lttng_ust_zes_zesFrequencyOcGetFrequencyTarget_exit(
    void *btx_handle, lttng_ust_zes_zesFrequencyOcGetFrequencyTarget_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFrequencyOcSetFrequencyTarget_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_freq_handle_t, double);

void btx_register_callbacks_lttng_ust_zes_zesFrequencyOcSetFrequencyTarget_entry(
    void *btx_handle, lttng_ust_zes_zesFrequencyOcSetFrequencyTarget_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFrequencyOcSetFrequencyTarget_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesFrequencyOcSetFrequencyTarget_exit(
    void *btx_handle, lttng_ust_zes_zesFrequencyOcSetFrequencyTarget_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFrequencyOcGetVoltageTarget_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_freq_handle_t, double *, double *);

void btx_register_callbacks_lttng_ust_zes_zesFrequencyOcGetVoltageTarget_entry(
    void *btx_handle, lttng_ust_zes_zesFrequencyOcGetVoltageTarget_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFrequencyOcGetVoltageTarget_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, double, double);

void btx_register_callbacks_lttng_ust_zes_zesFrequencyOcGetVoltageTarget_exit(
    void *btx_handle, lttng_ust_zes_zesFrequencyOcGetVoltageTarget_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFrequencyOcSetVoltageTarget_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_freq_handle_t, double, double);

void btx_register_callbacks_lttng_ust_zes_zesFrequencyOcSetVoltageTarget_entry(
    void *btx_handle, lttng_ust_zes_zesFrequencyOcSetVoltageTarget_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFrequencyOcSetVoltageTarget_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesFrequencyOcSetVoltageTarget_exit(
    void *btx_handle, lttng_ust_zes_zesFrequencyOcSetVoltageTarget_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFrequencyOcSetMode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_freq_handle_t, zes_oc_mode_t);

void btx_register_callbacks_lttng_ust_zes_zesFrequencyOcSetMode_entry(
    void *btx_handle, lttng_ust_zes_zesFrequencyOcSetMode_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFrequencyOcSetMode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesFrequencyOcSetMode_exit(
    void *btx_handle, lttng_ust_zes_zesFrequencyOcSetMode_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFrequencyOcGetMode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_freq_handle_t, zes_oc_mode_t *);

void btx_register_callbacks_lttng_ust_zes_zesFrequencyOcGetMode_entry(
    void *btx_handle, lttng_ust_zes_zesFrequencyOcGetMode_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFrequencyOcGetMode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, zes_oc_mode_t);

void btx_register_callbacks_lttng_ust_zes_zesFrequencyOcGetMode_exit(
    void *btx_handle, lttng_ust_zes_zesFrequencyOcGetMode_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFrequencyOcGetIccMax_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_freq_handle_t, double *);

void btx_register_callbacks_lttng_ust_zes_zesFrequencyOcGetIccMax_entry(
    void *btx_handle, lttng_ust_zes_zesFrequencyOcGetIccMax_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFrequencyOcGetIccMax_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, double);

void btx_register_callbacks_lttng_ust_zes_zesFrequencyOcGetIccMax_exit(
    void *btx_handle, lttng_ust_zes_zesFrequencyOcGetIccMax_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFrequencyOcSetIccMax_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_freq_handle_t, double);

void btx_register_callbacks_lttng_ust_zes_zesFrequencyOcSetIccMax_entry(
    void *btx_handle, lttng_ust_zes_zesFrequencyOcSetIccMax_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFrequencyOcSetIccMax_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesFrequencyOcSetIccMax_exit(
    void *btx_handle, lttng_ust_zes_zesFrequencyOcSetIccMax_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFrequencyOcGetTjMax_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_freq_handle_t, double *);

void btx_register_callbacks_lttng_ust_zes_zesFrequencyOcGetTjMax_entry(
    void *btx_handle, lttng_ust_zes_zesFrequencyOcGetTjMax_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFrequencyOcGetTjMax_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, double);

void btx_register_callbacks_lttng_ust_zes_zesFrequencyOcGetTjMax_exit(
    void *btx_handle, lttng_ust_zes_zesFrequencyOcGetTjMax_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFrequencyOcSetTjMax_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_freq_handle_t, double);

void btx_register_callbacks_lttng_ust_zes_zesFrequencyOcSetTjMax_entry(
    void *btx_handle, lttng_ust_zes_zesFrequencyOcSetTjMax_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFrequencyOcSetTjMax_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesFrequencyOcSetTjMax_exit(
    void *btx_handle, lttng_ust_zes_zesFrequencyOcSetTjMax_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEnumLeds_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, uint32_t *, zes_led_handle_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEnumLeds_entry(
    void *btx_handle, lttng_ust_zes_zesDeviceEnumLeds_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEnumLeds_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zes_led_handle_t *);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEnumLeds_exit(
    void *btx_handle, lttng_ust_zes_zesDeviceEnumLeds_exit_callback_f *callback);

typedef void lttng_ust_zes_zesLedGetProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_led_handle_t, zes_led_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesLedGetProperties_entry(
    void *btx_handle, lttng_ust_zes_zesLedGetProperties_entry_callback_f *callback);

typedef void lttng_ust_zes_zesLedGetProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_led_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesLedGetProperties_exit(
    void *btx_handle, lttng_ust_zes_zesLedGetProperties_exit_callback_f *callback);

typedef void lttng_ust_zes_zesLedGetState_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_led_handle_t, zes_led_state_t *);

void btx_register_callbacks_lttng_ust_zes_zesLedGetState_entry(
    void *btx_handle, lttng_ust_zes_zesLedGetState_entry_callback_f *callback);

typedef void lttng_ust_zes_zesLedGetState_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_led_state_t *);

void btx_register_callbacks_lttng_ust_zes_zesLedGetState_exit(
    void *btx_handle, lttng_ust_zes_zesLedGetState_exit_callback_f *callback);

typedef void lttng_ust_zes_zesLedSetState_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_led_handle_t, ze_bool_t);

void btx_register_callbacks_lttng_ust_zes_zesLedSetState_entry(
    void *btx_handle, lttng_ust_zes_zesLedSetState_entry_callback_f *callback);

typedef void lttng_ust_zes_zesLedSetState_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesLedSetState_exit(
    void *btx_handle, lttng_ust_zes_zesLedSetState_exit_callback_f *callback);

typedef void lttng_ust_zes_zesLedSetColor_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_led_handle_t, zes_led_color_t *, size_t, zes_led_color_t *);

void btx_register_callbacks_lttng_ust_zes_zesLedSetColor_entry(
    void *btx_handle, lttng_ust_zes_zesLedSetColor_entry_callback_f *callback);

typedef void lttng_ust_zes_zesLedSetColor_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesLedSetColor_exit(
    void *btx_handle, lttng_ust_zes_zesLedSetColor_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEnumMemoryModules_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, uint32_t *, zes_mem_handle_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEnumMemoryModules_entry(
    void *btx_handle, lttng_ust_zes_zesDeviceEnumMemoryModules_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEnumMemoryModules_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zes_mem_handle_t *);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEnumMemoryModules_exit(
    void *btx_handle, lttng_ust_zes_zesDeviceEnumMemoryModules_exit_callback_f *callback);

typedef void lttng_ust_zes_zesMemoryGetProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_mem_handle_t, zes_mem_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesMemoryGetProperties_entry(
    void *btx_handle, lttng_ust_zes_zesMemoryGetProperties_entry_callback_f *callback);

typedef void lttng_ust_zes_zesMemoryGetProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_mem_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesMemoryGetProperties_exit(
    void *btx_handle, lttng_ust_zes_zesMemoryGetProperties_exit_callback_f *callback);

typedef void lttng_ust_zes_zesMemoryGetState_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_mem_handle_t, zes_mem_state_t *);

void btx_register_callbacks_lttng_ust_zes_zesMemoryGetState_entry(
    void *btx_handle, lttng_ust_zes_zesMemoryGetState_entry_callback_f *callback);

typedef void lttng_ust_zes_zesMemoryGetState_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_mem_state_t *);

void btx_register_callbacks_lttng_ust_zes_zesMemoryGetState_exit(
    void *btx_handle, lttng_ust_zes_zesMemoryGetState_exit_callback_f *callback);

typedef void lttng_ust_zes_zesMemoryGetBandwidth_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_mem_handle_t, zes_mem_bandwidth_t *);

void btx_register_callbacks_lttng_ust_zes_zesMemoryGetBandwidth_entry(
    void *btx_handle, lttng_ust_zes_zesMemoryGetBandwidth_entry_callback_f *callback);

typedef void lttng_ust_zes_zesMemoryGetBandwidth_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_mem_bandwidth_t *);

void btx_register_callbacks_lttng_ust_zes_zesMemoryGetBandwidth_exit(
    void *btx_handle, lttng_ust_zes_zesMemoryGetBandwidth_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEnumPerformanceFactorDomains_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, uint32_t *, zes_perf_handle_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEnumPerformanceFactorDomains_entry(
    void *btx_handle, lttng_ust_zes_zesDeviceEnumPerformanceFactorDomains_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEnumPerformanceFactorDomains_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zes_perf_handle_t *);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEnumPerformanceFactorDomains_exit(
    void *btx_handle, lttng_ust_zes_zesDeviceEnumPerformanceFactorDomains_exit_callback_f *callback);

typedef void lttng_ust_zes_zesPerformanceFactorGetProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_perf_handle_t, zes_perf_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesPerformanceFactorGetProperties_entry(
    void *btx_handle, lttng_ust_zes_zesPerformanceFactorGetProperties_entry_callback_f *callback);

typedef void lttng_ust_zes_zesPerformanceFactorGetProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_perf_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesPerformanceFactorGetProperties_exit(
    void *btx_handle, lttng_ust_zes_zesPerformanceFactorGetProperties_exit_callback_f *callback);

typedef void lttng_ust_zes_zesPerformanceFactorGetConfig_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_perf_handle_t, double *);

void btx_register_callbacks_lttng_ust_zes_zesPerformanceFactorGetConfig_entry(
    void *btx_handle, lttng_ust_zes_zesPerformanceFactorGetConfig_entry_callback_f *callback);

typedef void lttng_ust_zes_zesPerformanceFactorGetConfig_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, double);

void btx_register_callbacks_lttng_ust_zes_zesPerformanceFactorGetConfig_exit(
    void *btx_handle, lttng_ust_zes_zesPerformanceFactorGetConfig_exit_callback_f *callback);

typedef void lttng_ust_zes_zesPerformanceFactorSetConfig_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_perf_handle_t, double);

void btx_register_callbacks_lttng_ust_zes_zesPerformanceFactorSetConfig_entry(
    void *btx_handle, lttng_ust_zes_zesPerformanceFactorSetConfig_entry_callback_f *callback);

typedef void lttng_ust_zes_zesPerformanceFactorSetConfig_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesPerformanceFactorSetConfig_exit(
    void *btx_handle, lttng_ust_zes_zesPerformanceFactorSetConfig_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEnumPowerDomains_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, uint32_t *, zes_pwr_handle_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEnumPowerDomains_entry(
    void *btx_handle, lttng_ust_zes_zesDeviceEnumPowerDomains_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEnumPowerDomains_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zes_pwr_handle_t *);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEnumPowerDomains_exit(
    void *btx_handle, lttng_ust_zes_zesDeviceEnumPowerDomains_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceGetCardPowerDomain_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, zes_pwr_handle_t *);

void btx_register_callbacks_lttng_ust_zes_zesDeviceGetCardPowerDomain_entry(
    void *btx_handle, lttng_ust_zes_zesDeviceGetCardPowerDomain_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceGetCardPowerDomain_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, zes_pwr_handle_t);

void btx_register_callbacks_lttng_ust_zes_zesDeviceGetCardPowerDomain_exit(
    void *btx_handle, lttng_ust_zes_zesDeviceGetCardPowerDomain_exit_callback_f *callback);

typedef void lttng_ust_zes_zesPowerGetProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_pwr_handle_t, zes_power_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesPowerGetProperties_entry(
    void *btx_handle, lttng_ust_zes_zesPowerGetProperties_entry_callback_f *callback);

typedef void lttng_ust_zes_zesPowerGetProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_power_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesPowerGetProperties_exit(
    void *btx_handle, lttng_ust_zes_zesPowerGetProperties_exit_callback_f *callback);

typedef void lttng_ust_zes_zesPowerGetEnergyCounter_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_pwr_handle_t, zes_power_energy_counter_t *);

void btx_register_callbacks_lttng_ust_zes_zesPowerGetEnergyCounter_entry(
    void *btx_handle, lttng_ust_zes_zesPowerGetEnergyCounter_entry_callback_f *callback);

typedef void lttng_ust_zes_zesPowerGetEnergyCounter_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_power_energy_counter_t *);

void btx_register_callbacks_lttng_ust_zes_zesPowerGetEnergyCounter_exit(
    void *btx_handle, lttng_ust_zes_zesPowerGetEnergyCounter_exit_callback_f *callback);

typedef void lttng_ust_zes_zesPowerGetLimits_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_pwr_handle_t, zes_power_sustained_limit_t *, zes_power_burst_limit_t *, zes_power_peak_limit_t *);

void btx_register_callbacks_lttng_ust_zes_zesPowerGetLimits_entry(
    void *btx_handle, lttng_ust_zes_zesPowerGetLimits_entry_callback_f *callback);

typedef void lttng_ust_zes_zesPowerGetLimits_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_power_sustained_limit_t *, size_t, zes_power_burst_limit_t *, size_t, zes_power_peak_limit_t *);

void btx_register_callbacks_lttng_ust_zes_zesPowerGetLimits_exit(
    void *btx_handle, lttng_ust_zes_zesPowerGetLimits_exit_callback_f *callback);

typedef void lttng_ust_zes_zesPowerSetLimits_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_pwr_handle_t, zes_power_sustained_limit_t *, zes_power_burst_limit_t *, zes_power_peak_limit_t *, size_t, zes_power_sustained_limit_t *, size_t, zes_power_burst_limit_t *, size_t, zes_power_peak_limit_t *);

void btx_register_callbacks_lttng_ust_zes_zesPowerSetLimits_entry(
    void *btx_handle, lttng_ust_zes_zesPowerSetLimits_entry_callback_f *callback);

typedef void lttng_ust_zes_zesPowerSetLimits_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesPowerSetLimits_exit(
    void *btx_handle, lttng_ust_zes_zesPowerSetLimits_exit_callback_f *callback);

typedef void lttng_ust_zes_zesPowerGetEnergyThreshold_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_pwr_handle_t, zes_energy_threshold_t *);

void btx_register_callbacks_lttng_ust_zes_zesPowerGetEnergyThreshold_entry(
    void *btx_handle, lttng_ust_zes_zesPowerGetEnergyThreshold_entry_callback_f *callback);

typedef void lttng_ust_zes_zesPowerGetEnergyThreshold_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_energy_threshold_t *);

void btx_register_callbacks_lttng_ust_zes_zesPowerGetEnergyThreshold_exit(
    void *btx_handle, lttng_ust_zes_zesPowerGetEnergyThreshold_exit_callback_f *callback);

typedef void lttng_ust_zes_zesPowerSetEnergyThreshold_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_pwr_handle_t, double);

void btx_register_callbacks_lttng_ust_zes_zesPowerSetEnergyThreshold_entry(
    void *btx_handle, lttng_ust_zes_zesPowerSetEnergyThreshold_entry_callback_f *callback);

typedef void lttng_ust_zes_zesPowerSetEnergyThreshold_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesPowerSetEnergyThreshold_exit(
    void *btx_handle, lttng_ust_zes_zesPowerSetEnergyThreshold_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEnumPsus_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, uint32_t *, zes_psu_handle_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEnumPsus_entry(
    void *btx_handle, lttng_ust_zes_zesDeviceEnumPsus_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEnumPsus_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zes_psu_handle_t *);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEnumPsus_exit(
    void *btx_handle, lttng_ust_zes_zesDeviceEnumPsus_exit_callback_f *callback);

typedef void lttng_ust_zes_zesPsuGetProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_psu_handle_t, zes_psu_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesPsuGetProperties_entry(
    void *btx_handle, lttng_ust_zes_zesPsuGetProperties_entry_callback_f *callback);

typedef void lttng_ust_zes_zesPsuGetProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_psu_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesPsuGetProperties_exit(
    void *btx_handle, lttng_ust_zes_zesPsuGetProperties_exit_callback_f *callback);

typedef void lttng_ust_zes_zesPsuGetState_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_psu_handle_t, zes_psu_state_t *);

void btx_register_callbacks_lttng_ust_zes_zesPsuGetState_entry(
    void *btx_handle, lttng_ust_zes_zesPsuGetState_entry_callback_f *callback);

typedef void lttng_ust_zes_zesPsuGetState_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_psu_state_t *);

void btx_register_callbacks_lttng_ust_zes_zesPsuGetState_exit(
    void *btx_handle, lttng_ust_zes_zesPsuGetState_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEnumRasErrorSets_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, uint32_t *, zes_ras_handle_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEnumRasErrorSets_entry(
    void *btx_handle, lttng_ust_zes_zesDeviceEnumRasErrorSets_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEnumRasErrorSets_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zes_ras_handle_t *);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEnumRasErrorSets_exit(
    void *btx_handle, lttng_ust_zes_zesDeviceEnumRasErrorSets_exit_callback_f *callback);

typedef void lttng_ust_zes_zesRasGetProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_ras_handle_t, zes_ras_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesRasGetProperties_entry(
    void *btx_handle, lttng_ust_zes_zesRasGetProperties_entry_callback_f *callback);

typedef void lttng_ust_zes_zesRasGetProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_ras_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesRasGetProperties_exit(
    void *btx_handle, lttng_ust_zes_zesRasGetProperties_exit_callback_f *callback);

typedef void lttng_ust_zes_zesRasGetConfig_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_ras_handle_t, zes_ras_config_t *);

void btx_register_callbacks_lttng_ust_zes_zesRasGetConfig_entry(
    void *btx_handle, lttng_ust_zes_zesRasGetConfig_entry_callback_f *callback);

typedef void lttng_ust_zes_zesRasGetConfig_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_ras_config_t *);

void btx_register_callbacks_lttng_ust_zes_zesRasGetConfig_exit(
    void *btx_handle, lttng_ust_zes_zesRasGetConfig_exit_callback_f *callback);

typedef void lttng_ust_zes_zesRasSetConfig_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_ras_handle_t, zes_ras_config_t *, size_t, zes_ras_config_t *);

void btx_register_callbacks_lttng_ust_zes_zesRasSetConfig_entry(
    void *btx_handle, lttng_ust_zes_zesRasSetConfig_entry_callback_f *callback);

typedef void lttng_ust_zes_zesRasSetConfig_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesRasSetConfig_exit(
    void *btx_handle, lttng_ust_zes_zesRasSetConfig_exit_callback_f *callback);

typedef void lttng_ust_zes_zesRasGetState_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_ras_handle_t, ze_bool_t, zes_ras_state_t *);

void btx_register_callbacks_lttng_ust_zes_zesRasGetState_entry(
    void *btx_handle, lttng_ust_zes_zesRasGetState_entry_callback_f *callback);

typedef void lttng_ust_zes_zesRasGetState_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_ras_state_t *);

void btx_register_callbacks_lttng_ust_zes_zesRasGetState_exit(
    void *btx_handle, lttng_ust_zes_zesRasGetState_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEnumSchedulers_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, uint32_t *, zes_sched_handle_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEnumSchedulers_entry(
    void *btx_handle, lttng_ust_zes_zesDeviceEnumSchedulers_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEnumSchedulers_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zes_sched_handle_t *);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEnumSchedulers_exit(
    void *btx_handle, lttng_ust_zes_zesDeviceEnumSchedulers_exit_callback_f *callback);

typedef void lttng_ust_zes_zesSchedulerGetProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_sched_handle_t, zes_sched_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesSchedulerGetProperties_entry(
    void *btx_handle, lttng_ust_zes_zesSchedulerGetProperties_entry_callback_f *callback);

typedef void lttng_ust_zes_zesSchedulerGetProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_sched_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesSchedulerGetProperties_exit(
    void *btx_handle, lttng_ust_zes_zesSchedulerGetProperties_exit_callback_f *callback);

typedef void lttng_ust_zes_zesSchedulerGetCurrentMode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_sched_handle_t, zes_sched_mode_t *);

void btx_register_callbacks_lttng_ust_zes_zesSchedulerGetCurrentMode_entry(
    void *btx_handle, lttng_ust_zes_zesSchedulerGetCurrentMode_entry_callback_f *callback);

typedef void lttng_ust_zes_zesSchedulerGetCurrentMode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, zes_sched_mode_t);

void btx_register_callbacks_lttng_ust_zes_zesSchedulerGetCurrentMode_exit(
    void *btx_handle, lttng_ust_zes_zesSchedulerGetCurrentMode_exit_callback_f *callback);

typedef void lttng_ust_zes_zesSchedulerGetTimeoutModeProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_sched_handle_t, ze_bool_t, zes_sched_timeout_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesSchedulerGetTimeoutModeProperties_entry(
    void *btx_handle, lttng_ust_zes_zesSchedulerGetTimeoutModeProperties_entry_callback_f *callback);

typedef void lttng_ust_zes_zesSchedulerGetTimeoutModeProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_sched_timeout_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesSchedulerGetTimeoutModeProperties_exit(
    void *btx_handle, lttng_ust_zes_zesSchedulerGetTimeoutModeProperties_exit_callback_f *callback);

typedef void lttng_ust_zes_zesSchedulerGetTimesliceModeProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_sched_handle_t, ze_bool_t, zes_sched_timeslice_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesSchedulerGetTimesliceModeProperties_entry(
    void *btx_handle, lttng_ust_zes_zesSchedulerGetTimesliceModeProperties_entry_callback_f *callback);

typedef void lttng_ust_zes_zesSchedulerGetTimesliceModeProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_sched_timeslice_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesSchedulerGetTimesliceModeProperties_exit(
    void *btx_handle, lttng_ust_zes_zesSchedulerGetTimesliceModeProperties_exit_callback_f *callback);

typedef void lttng_ust_zes_zesSchedulerSetTimeoutMode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_sched_handle_t, zes_sched_timeout_properties_t *, ze_bool_t *);

void btx_register_callbacks_lttng_ust_zes_zesSchedulerSetTimeoutMode_entry(
    void *btx_handle, lttng_ust_zes_zesSchedulerSetTimeoutMode_entry_callback_f *callback);

typedef void lttng_ust_zes_zesSchedulerSetTimeoutMode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_sched_timeout_properties_t *, ze_bool_t);

void btx_register_callbacks_lttng_ust_zes_zesSchedulerSetTimeoutMode_exit(
    void *btx_handle, lttng_ust_zes_zesSchedulerSetTimeoutMode_exit_callback_f *callback);

typedef void lttng_ust_zes_zesSchedulerSetTimesliceMode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_sched_handle_t, zes_sched_timeslice_properties_t *, ze_bool_t *);

void btx_register_callbacks_lttng_ust_zes_zesSchedulerSetTimesliceMode_entry(
    void *btx_handle, lttng_ust_zes_zesSchedulerSetTimesliceMode_entry_callback_f *callback);

typedef void lttng_ust_zes_zesSchedulerSetTimesliceMode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_sched_timeslice_properties_t *, ze_bool_t);

void btx_register_callbacks_lttng_ust_zes_zesSchedulerSetTimesliceMode_exit(
    void *btx_handle, lttng_ust_zes_zesSchedulerSetTimesliceMode_exit_callback_f *callback);

typedef void lttng_ust_zes_zesSchedulerSetExclusiveMode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_sched_handle_t, ze_bool_t *);

void btx_register_callbacks_lttng_ust_zes_zesSchedulerSetExclusiveMode_entry(
    void *btx_handle, lttng_ust_zes_zesSchedulerSetExclusiveMode_entry_callback_f *callback);

typedef void lttng_ust_zes_zesSchedulerSetExclusiveMode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_bool_t);

void btx_register_callbacks_lttng_ust_zes_zesSchedulerSetExclusiveMode_exit(
    void *btx_handle, lttng_ust_zes_zesSchedulerSetExclusiveMode_exit_callback_f *callback);

typedef void lttng_ust_zes_zesSchedulerSetComputeUnitDebugMode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_sched_handle_t, ze_bool_t *);

void btx_register_callbacks_lttng_ust_zes_zesSchedulerSetComputeUnitDebugMode_entry(
    void *btx_handle, lttng_ust_zes_zesSchedulerSetComputeUnitDebugMode_entry_callback_f *callback);

typedef void lttng_ust_zes_zesSchedulerSetComputeUnitDebugMode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, ze_bool_t);

void btx_register_callbacks_lttng_ust_zes_zesSchedulerSetComputeUnitDebugMode_exit(
    void *btx_handle, lttng_ust_zes_zesSchedulerSetComputeUnitDebugMode_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEnumStandbyDomains_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, uint32_t *, zes_standby_handle_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEnumStandbyDomains_entry(
    void *btx_handle, lttng_ust_zes_zesDeviceEnumStandbyDomains_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEnumStandbyDomains_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zes_standby_handle_t *);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEnumStandbyDomains_exit(
    void *btx_handle, lttng_ust_zes_zesDeviceEnumStandbyDomains_exit_callback_f *callback);

typedef void lttng_ust_zes_zesStandbyGetProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_standby_handle_t, zes_standby_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesStandbyGetProperties_entry(
    void *btx_handle, lttng_ust_zes_zesStandbyGetProperties_entry_callback_f *callback);

typedef void lttng_ust_zes_zesStandbyGetProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_standby_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesStandbyGetProperties_exit(
    void *btx_handle, lttng_ust_zes_zesStandbyGetProperties_exit_callback_f *callback);

typedef void lttng_ust_zes_zesStandbyGetMode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_standby_handle_t, zes_standby_promo_mode_t *);

void btx_register_callbacks_lttng_ust_zes_zesStandbyGetMode_entry(
    void *btx_handle, lttng_ust_zes_zesStandbyGetMode_entry_callback_f *callback);

typedef void lttng_ust_zes_zesStandbyGetMode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, zes_standby_promo_mode_t);

void btx_register_callbacks_lttng_ust_zes_zesStandbyGetMode_exit(
    void *btx_handle, lttng_ust_zes_zesStandbyGetMode_exit_callback_f *callback);

typedef void lttng_ust_zes_zesStandbySetMode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_standby_handle_t, zes_standby_promo_mode_t);

void btx_register_callbacks_lttng_ust_zes_zesStandbySetMode_entry(
    void *btx_handle, lttng_ust_zes_zesStandbySetMode_entry_callback_f *callback);

typedef void lttng_ust_zes_zesStandbySetMode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesStandbySetMode_exit(
    void *btx_handle, lttng_ust_zes_zesStandbySetMode_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEnumTemperatureSensors_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, uint32_t *, zes_temp_handle_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEnumTemperatureSensors_entry(
    void *btx_handle, lttng_ust_zes_zesDeviceEnumTemperatureSensors_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEnumTemperatureSensors_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zes_temp_handle_t *);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEnumTemperatureSensors_exit(
    void *btx_handle, lttng_ust_zes_zesDeviceEnumTemperatureSensors_exit_callback_f *callback);

typedef void lttng_ust_zes_zesTemperatureGetProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_temp_handle_t, zes_temp_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesTemperatureGetProperties_entry(
    void *btx_handle, lttng_ust_zes_zesTemperatureGetProperties_entry_callback_f *callback);

typedef void lttng_ust_zes_zesTemperatureGetProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_temp_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesTemperatureGetProperties_exit(
    void *btx_handle, lttng_ust_zes_zesTemperatureGetProperties_exit_callback_f *callback);

typedef void lttng_ust_zes_zesTemperatureGetConfig_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_temp_handle_t, zes_temp_config_t *);

void btx_register_callbacks_lttng_ust_zes_zesTemperatureGetConfig_entry(
    void *btx_handle, lttng_ust_zes_zesTemperatureGetConfig_entry_callback_f *callback);

typedef void lttng_ust_zes_zesTemperatureGetConfig_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_temp_config_t *);

void btx_register_callbacks_lttng_ust_zes_zesTemperatureGetConfig_exit(
    void *btx_handle, lttng_ust_zes_zesTemperatureGetConfig_exit_callback_f *callback);

typedef void lttng_ust_zes_zesTemperatureSetConfig_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_temp_handle_t, zes_temp_config_t *, size_t, zes_temp_config_t *);

void btx_register_callbacks_lttng_ust_zes_zesTemperatureSetConfig_entry(
    void *btx_handle, lttng_ust_zes_zesTemperatureSetConfig_entry_callback_f *callback);

typedef void lttng_ust_zes_zesTemperatureSetConfig_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesTemperatureSetConfig_exit(
    void *btx_handle, lttng_ust_zes_zesTemperatureSetConfig_exit_callback_f *callback);

typedef void lttng_ust_zes_zesTemperatureGetState_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_temp_handle_t, double *);

void btx_register_callbacks_lttng_ust_zes_zesTemperatureGetState_entry(
    void *btx_handle, lttng_ust_zes_zesTemperatureGetState_entry_callback_f *callback);

typedef void lttng_ust_zes_zesTemperatureGetState_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, double);

void btx_register_callbacks_lttng_ust_zes_zesTemperatureGetState_exit(
    void *btx_handle, lttng_ust_zes_zesTemperatureGetState_exit_callback_f *callback);

typedef void lttng_ust_zes_zesPowerGetLimitsExt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_pwr_handle_t, uint32_t *, zes_power_limit_ext_desc_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesPowerGetLimitsExt_entry(
    void *btx_handle, lttng_ust_zes_zesPowerGetLimitsExt_entry_callback_f *callback);

typedef void lttng_ust_zes_zesPowerGetLimitsExt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zes_power_limit_ext_desc_t *);

void btx_register_callbacks_lttng_ust_zes_zesPowerGetLimitsExt_exit(
    void *btx_handle, lttng_ust_zes_zesPowerGetLimitsExt_exit_callback_f *callback);

typedef void lttng_ust_zes_zesPowerSetLimitsExt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_pwr_handle_t, uint32_t *, zes_power_limit_ext_desc_t *, uint32_t, size_t, zes_power_limit_ext_desc_t *);

void btx_register_callbacks_lttng_ust_zes_zesPowerSetLimitsExt_entry(
    void *btx_handle, lttng_ust_zes_zesPowerSetLimitsExt_entry_callback_f *callback);

typedef void lttng_ust_zes_zesPowerSetLimitsExt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesPowerSetLimitsExt_exit(
    void *btx_handle, lttng_ust_zes_zesPowerSetLimitsExt_exit_callback_f *callback);

typedef void lttng_ust_zes_zesEngineGetActivityExt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_engine_handle_t, uint32_t *, zes_engine_stats_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesEngineGetActivityExt_entry(
    void *btx_handle, lttng_ust_zes_zesEngineGetActivityExt_entry_callback_f *callback);

typedef void lttng_ust_zes_zesEngineGetActivityExt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zes_engine_stats_t *);

void btx_register_callbacks_lttng_ust_zes_zesEngineGetActivityExt_exit(
    void *btx_handle, lttng_ust_zes_zesEngineGetActivityExt_exit_callback_f *callback);

typedef void lttng_ust_zes_zesRasGetStateExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_ras_handle_t, uint32_t *, zes_ras_state_exp_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesRasGetStateExp_entry(
    void *btx_handle, lttng_ust_zes_zesRasGetStateExp_entry_callback_f *callback);

typedef void lttng_ust_zes_zesRasGetStateExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zes_ras_state_exp_t *);

void btx_register_callbacks_lttng_ust_zes_zesRasGetStateExp_exit(
    void *btx_handle, lttng_ust_zes_zesRasGetStateExp_exit_callback_f *callback);

typedef void lttng_ust_zes_zesRasClearStateExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_ras_handle_t, zes_ras_error_category_exp_t);

void btx_register_callbacks_lttng_ust_zes_zesRasClearStateExp_entry(
    void *btx_handle, lttng_ust_zes_zesRasClearStateExp_entry_callback_f *callback);

typedef void lttng_ust_zes_zesRasClearStateExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesRasClearStateExp_exit(
    void *btx_handle, lttng_ust_zes_zesRasClearStateExp_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFirmwareGetSecurityVersionExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_firmware_handle_t, char *);

void btx_register_callbacks_lttng_ust_zes_zesFirmwareGetSecurityVersionExp_entry(
    void *btx_handle, lttng_ust_zes_zesFirmwareGetSecurityVersionExp_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFirmwareGetSecurityVersionExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, char *);

void btx_register_callbacks_lttng_ust_zes_zesFirmwareGetSecurityVersionExp_exit(
    void *btx_handle, lttng_ust_zes_zesFirmwareGetSecurityVersionExp_exit_callback_f *callback);

typedef void lttng_ust_zes_zesFirmwareSetSecurityVersionExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_firmware_handle_t);

void btx_register_callbacks_lttng_ust_zes_zesFirmwareSetSecurityVersionExp_entry(
    void *btx_handle, lttng_ust_zes_zesFirmwareSetSecurityVersionExp_entry_callback_f *callback);

typedef void lttng_ust_zes_zesFirmwareSetSecurityVersionExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesFirmwareSetSecurityVersionExp_exit(
    void *btx_handle, lttng_ust_zes_zesFirmwareSetSecurityVersionExp_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceGetSubDevicePropertiesExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, uint32_t *, zes_subdevice_exp_properties_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesDeviceGetSubDevicePropertiesExp_entry(
    void *btx_handle, lttng_ust_zes_zesDeviceGetSubDevicePropertiesExp_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceGetSubDevicePropertiesExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zes_subdevice_exp_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesDeviceGetSubDevicePropertiesExp_exit(
    void *btx_handle, lttng_ust_zes_zesDeviceGetSubDevicePropertiesExp_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDriverGetDeviceByUuidExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_driver_handle_t, zes_uuid_t, zes_device_handle_t *, ze_bool_t *, uint32_t *);

void btx_register_callbacks_lttng_ust_zes_zesDriverGetDeviceByUuidExp_entry(
    void *btx_handle, lttng_ust_zes_zesDriverGetDeviceByUuidExp_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDriverGetDeviceByUuidExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, zes_device_handle_t, ze_bool_t, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesDriverGetDeviceByUuidExp_exit(
    void *btx_handle, lttng_ust_zes_zesDriverGetDeviceByUuidExp_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEnumActiveVFExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, uint32_t *, zes_vf_handle_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEnumActiveVFExp_entry(
    void *btx_handle, lttng_ust_zes_zesDeviceEnumActiveVFExp_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEnumActiveVFExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zes_vf_handle_t *);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEnumActiveVFExp_exit(
    void *btx_handle, lttng_ust_zes_zesDeviceEnumActiveVFExp_exit_callback_f *callback);

typedef void lttng_ust_zes_zesVFManagementGetVFPropertiesExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_vf_handle_t, zes_vf_exp_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesVFManagementGetVFPropertiesExp_entry(
    void *btx_handle, lttng_ust_zes_zesVFManagementGetVFPropertiesExp_entry_callback_f *callback);

typedef void lttng_ust_zes_zesVFManagementGetVFPropertiesExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, zes_vf_exp_properties_t *);

void btx_register_callbacks_lttng_ust_zes_zesVFManagementGetVFPropertiesExp_exit(
    void *btx_handle, lttng_ust_zes_zesVFManagementGetVFPropertiesExp_exit_callback_f *callback);

typedef void lttng_ust_zes_zesVFManagementGetVFMemoryUtilizationExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_vf_handle_t, uint32_t *, zes_vf_util_mem_exp_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesVFManagementGetVFMemoryUtilizationExp_entry(
    void *btx_handle, lttng_ust_zes_zesVFManagementGetVFMemoryUtilizationExp_entry_callback_f *callback);

typedef void lttng_ust_zes_zesVFManagementGetVFMemoryUtilizationExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zes_vf_util_mem_exp_t *);

void btx_register_callbacks_lttng_ust_zes_zesVFManagementGetVFMemoryUtilizationExp_exit(
    void *btx_handle, lttng_ust_zes_zesVFManagementGetVFMemoryUtilizationExp_exit_callback_f *callback);

typedef void lttng_ust_zes_zesVFManagementGetVFEngineUtilizationExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_vf_handle_t, uint32_t *, zes_vf_util_engine_exp_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zes_zesVFManagementGetVFEngineUtilizationExp_entry(
    void *btx_handle, lttng_ust_zes_zesVFManagementGetVFEngineUtilizationExp_entry_callback_f *callback);

typedef void lttng_ust_zes_zesVFManagementGetVFEngineUtilizationExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, zes_vf_util_engine_exp_t *);

void btx_register_callbacks_lttng_ust_zes_zesVFManagementGetVFEngineUtilizationExp_exit(
    void *btx_handle, lttng_ust_zes_zesVFManagementGetVFEngineUtilizationExp_exit_callback_f *callback);

typedef void lttng_ust_zes_zesVFManagementSetVFTelemetryModeExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_vf_handle_t, zes_vf_info_util_exp_flags_t, ze_bool_t);

void btx_register_callbacks_lttng_ust_zes_zesVFManagementSetVFTelemetryModeExp_entry(
    void *btx_handle, lttng_ust_zes_zesVFManagementSetVFTelemetryModeExp_entry_callback_f *callback);

typedef void lttng_ust_zes_zesVFManagementSetVFTelemetryModeExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesVFManagementSetVFTelemetryModeExp_exit(
    void *btx_handle, lttng_ust_zes_zesVFManagementSetVFTelemetryModeExp_exit_callback_f *callback);

typedef void lttng_ust_zes_zesVFManagementSetVFTelemetrySamplingIntervalExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_vf_handle_t, zes_vf_info_util_exp_flags_t, uint64_t);

void btx_register_callbacks_lttng_ust_zes_zesVFManagementSetVFTelemetrySamplingIntervalExp_entry(
    void *btx_handle, lttng_ust_zes_zesVFManagementSetVFTelemetrySamplingIntervalExp_entry_callback_f *callback);

typedef void lttng_ust_zes_zesVFManagementSetVFTelemetrySamplingIntervalExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesVFManagementSetVFTelemetrySamplingIntervalExp_exit(
    void *btx_handle, lttng_ust_zes_zesVFManagementSetVFTelemetrySamplingIntervalExp_exit_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEnumEnabledVFExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, uint32_t *, zes_vf_handle_t *);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEnumEnabledVFExp_entry(
    void *btx_handle, lttng_ust_zes_zesDeviceEnumEnabledVFExp_entry_callback_f *callback);

typedef void lttng_ust_zes_zesDeviceEnumEnabledVFExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesDeviceEnumEnabledVFExp_exit(
    void *btx_handle, lttng_ust_zes_zesDeviceEnumEnabledVFExp_exit_callback_f *callback);

typedef void lttng_ust_zes_zesVFManagementGetVFCapabilitiesExp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_vf_handle_t, zes_vf_exp_capabilities_t *);

void btx_register_callbacks_lttng_ust_zes_zesVFManagementGetVFCapabilitiesExp_entry(
    void *btx_handle, lttng_ust_zes_zesVFManagementGetVFCapabilitiesExp_entry_callback_f *callback);

typedef void lttng_ust_zes_zesVFManagementGetVFCapabilitiesExp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesVFManagementGetVFCapabilitiesExp_exit(
    void *btx_handle, lttng_ust_zes_zesVFManagementGetVFCapabilitiesExp_exit_callback_f *callback);

typedef void lttng_ust_zes_zesVFManagementGetVFMemoryUtilizationExp2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_vf_handle_t, uint32_t *, zes_vf_util_mem_exp2_t *);

void btx_register_callbacks_lttng_ust_zes_zesVFManagementGetVFMemoryUtilizationExp2_entry(
    void *btx_handle, lttng_ust_zes_zesVFManagementGetVFMemoryUtilizationExp2_entry_callback_f *callback);

typedef void lttng_ust_zes_zesVFManagementGetVFMemoryUtilizationExp2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesVFManagementGetVFMemoryUtilizationExp2_exit(
    void *btx_handle, lttng_ust_zes_zesVFManagementGetVFMemoryUtilizationExp2_exit_callback_f *callback);

typedef void lttng_ust_zes_zesVFManagementGetVFEngineUtilizationExp2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_vf_handle_t, uint32_t *, zes_vf_util_engine_exp2_t *);

void btx_register_callbacks_lttng_ust_zes_zesVFManagementGetVFEngineUtilizationExp2_entry(
    void *btx_handle, lttng_ust_zes_zesVFManagementGetVFEngineUtilizationExp2_entry_callback_f *callback);

typedef void lttng_ust_zes_zesVFManagementGetVFEngineUtilizationExp2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesVFManagementGetVFEngineUtilizationExp2_exit(
    void *btx_handle, lttng_ust_zes_zesVFManagementGetVFEngineUtilizationExp2_exit_callback_f *callback);

typedef void lttng_ust_zes_zesVFManagementGetVFCapabilitiesExp2_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_vf_handle_t, zes_vf_exp2_capabilities_t *);

void btx_register_callbacks_lttng_ust_zes_zesVFManagementGetVFCapabilitiesExp2_entry(
    void *btx_handle, lttng_ust_zes_zesVFManagementGetVFCapabilitiesExp2_entry_callback_f *callback);

typedef void lttng_ust_zes_zesVFManagementGetVFCapabilitiesExp2_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesVFManagementGetVFCapabilitiesExp2_exit(
    void *btx_handle, lttng_ust_zes_zesVFManagementGetVFCapabilitiesExp2_exit_callback_f *callback);

typedef void lttng_ust_zes_zesGetGlobalProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zes_global_dditable_t *);

void btx_register_callbacks_lttng_ust_zes_zesGetGlobalProcAddrTable_entry(
    void *btx_handle, lttng_ust_zes_zesGetGlobalProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zes_zesGetGlobalProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesGetGlobalProcAddrTable_exit(
    void *btx_handle, lttng_ust_zes_zesGetGlobalProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zes_zesGetDeviceProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zes_device_dditable_t *);

void btx_register_callbacks_lttng_ust_zes_zesGetDeviceProcAddrTable_entry(
    void *btx_handle, lttng_ust_zes_zesGetDeviceProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zes_zesGetDeviceProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesGetDeviceProcAddrTable_exit(
    void *btx_handle, lttng_ust_zes_zesGetDeviceProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zes_zesGetDeviceExpProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zes_device_exp_dditable_t *);

void btx_register_callbacks_lttng_ust_zes_zesGetDeviceExpProcAddrTable_entry(
    void *btx_handle, lttng_ust_zes_zesGetDeviceExpProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zes_zesGetDeviceExpProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesGetDeviceExpProcAddrTable_exit(
    void *btx_handle, lttng_ust_zes_zesGetDeviceExpProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zes_zesGetDriverProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zes_driver_dditable_t *);

void btx_register_callbacks_lttng_ust_zes_zesGetDriverProcAddrTable_entry(
    void *btx_handle, lttng_ust_zes_zesGetDriverProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zes_zesGetDriverProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesGetDriverProcAddrTable_exit(
    void *btx_handle, lttng_ust_zes_zesGetDriverProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zes_zesGetDriverExpProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zes_driver_exp_dditable_t *);

void btx_register_callbacks_lttng_ust_zes_zesGetDriverExpProcAddrTable_entry(
    void *btx_handle, lttng_ust_zes_zesGetDriverExpProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zes_zesGetDriverExpProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesGetDriverExpProcAddrTable_exit(
    void *btx_handle, lttng_ust_zes_zesGetDriverExpProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zes_zesGetOverclockProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zes_overclock_dditable_t *);

void btx_register_callbacks_lttng_ust_zes_zesGetOverclockProcAddrTable_entry(
    void *btx_handle, lttng_ust_zes_zesGetOverclockProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zes_zesGetOverclockProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesGetOverclockProcAddrTable_exit(
    void *btx_handle, lttng_ust_zes_zesGetOverclockProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zes_zesGetSchedulerProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zes_scheduler_dditable_t *);

void btx_register_callbacks_lttng_ust_zes_zesGetSchedulerProcAddrTable_entry(
    void *btx_handle, lttng_ust_zes_zesGetSchedulerProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zes_zesGetSchedulerProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesGetSchedulerProcAddrTable_exit(
    void *btx_handle, lttng_ust_zes_zesGetSchedulerProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zes_zesGetPerformanceFactorProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zes_performance_factor_dditable_t *);

void btx_register_callbacks_lttng_ust_zes_zesGetPerformanceFactorProcAddrTable_entry(
    void *btx_handle, lttng_ust_zes_zesGetPerformanceFactorProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zes_zesGetPerformanceFactorProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesGetPerformanceFactorProcAddrTable_exit(
    void *btx_handle, lttng_ust_zes_zesGetPerformanceFactorProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zes_zesGetPowerProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zes_power_dditable_t *);

void btx_register_callbacks_lttng_ust_zes_zesGetPowerProcAddrTable_entry(
    void *btx_handle, lttng_ust_zes_zesGetPowerProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zes_zesGetPowerProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesGetPowerProcAddrTable_exit(
    void *btx_handle, lttng_ust_zes_zesGetPowerProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zes_zesGetFrequencyProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zes_frequency_dditable_t *);

void btx_register_callbacks_lttng_ust_zes_zesGetFrequencyProcAddrTable_entry(
    void *btx_handle, lttng_ust_zes_zesGetFrequencyProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zes_zesGetFrequencyProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesGetFrequencyProcAddrTable_exit(
    void *btx_handle, lttng_ust_zes_zesGetFrequencyProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zes_zesGetEngineProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zes_engine_dditable_t *);

void btx_register_callbacks_lttng_ust_zes_zesGetEngineProcAddrTable_entry(
    void *btx_handle, lttng_ust_zes_zesGetEngineProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zes_zesGetEngineProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesGetEngineProcAddrTable_exit(
    void *btx_handle, lttng_ust_zes_zesGetEngineProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zes_zesGetStandbyProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zes_standby_dditable_t *);

void btx_register_callbacks_lttng_ust_zes_zesGetStandbyProcAddrTable_entry(
    void *btx_handle, lttng_ust_zes_zesGetStandbyProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zes_zesGetStandbyProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesGetStandbyProcAddrTable_exit(
    void *btx_handle, lttng_ust_zes_zesGetStandbyProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zes_zesGetFirmwareProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zes_firmware_dditable_t *);

void btx_register_callbacks_lttng_ust_zes_zesGetFirmwareProcAddrTable_entry(
    void *btx_handle, lttng_ust_zes_zesGetFirmwareProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zes_zesGetFirmwareProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesGetFirmwareProcAddrTable_exit(
    void *btx_handle, lttng_ust_zes_zesGetFirmwareProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zes_zesGetFirmwareExpProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zes_firmware_exp_dditable_t *);

void btx_register_callbacks_lttng_ust_zes_zesGetFirmwareExpProcAddrTable_entry(
    void *btx_handle, lttng_ust_zes_zesGetFirmwareExpProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zes_zesGetFirmwareExpProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesGetFirmwareExpProcAddrTable_exit(
    void *btx_handle, lttng_ust_zes_zesGetFirmwareExpProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zes_zesGetMemoryProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zes_memory_dditable_t *);

void btx_register_callbacks_lttng_ust_zes_zesGetMemoryProcAddrTable_entry(
    void *btx_handle, lttng_ust_zes_zesGetMemoryProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zes_zesGetMemoryProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesGetMemoryProcAddrTable_exit(
    void *btx_handle, lttng_ust_zes_zesGetMemoryProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zes_zesGetFabricPortProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zes_fabric_port_dditable_t *);

void btx_register_callbacks_lttng_ust_zes_zesGetFabricPortProcAddrTable_entry(
    void *btx_handle, lttng_ust_zes_zesGetFabricPortProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zes_zesGetFabricPortProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesGetFabricPortProcAddrTable_exit(
    void *btx_handle, lttng_ust_zes_zesGetFabricPortProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zes_zesGetTemperatureProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zes_temperature_dditable_t *);

void btx_register_callbacks_lttng_ust_zes_zesGetTemperatureProcAddrTable_entry(
    void *btx_handle, lttng_ust_zes_zesGetTemperatureProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zes_zesGetTemperatureProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesGetTemperatureProcAddrTable_exit(
    void *btx_handle, lttng_ust_zes_zesGetTemperatureProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zes_zesGetPsuProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zes_psu_dditable_t *);

void btx_register_callbacks_lttng_ust_zes_zesGetPsuProcAddrTable_entry(
    void *btx_handle, lttng_ust_zes_zesGetPsuProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zes_zesGetPsuProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesGetPsuProcAddrTable_exit(
    void *btx_handle, lttng_ust_zes_zesGetPsuProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zes_zesGetFanProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zes_fan_dditable_t *);

void btx_register_callbacks_lttng_ust_zes_zesGetFanProcAddrTable_entry(
    void *btx_handle, lttng_ust_zes_zesGetFanProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zes_zesGetFanProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesGetFanProcAddrTable_exit(
    void *btx_handle, lttng_ust_zes_zesGetFanProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zes_zesGetLedProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zes_led_dditable_t *);

void btx_register_callbacks_lttng_ust_zes_zesGetLedProcAddrTable_entry(
    void *btx_handle, lttng_ust_zes_zesGetLedProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zes_zesGetLedProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesGetLedProcAddrTable_exit(
    void *btx_handle, lttng_ust_zes_zesGetLedProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zes_zesGetRasProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zes_ras_dditable_t *);

void btx_register_callbacks_lttng_ust_zes_zesGetRasProcAddrTable_entry(
    void *btx_handle, lttng_ust_zes_zesGetRasProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zes_zesGetRasProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesGetRasProcAddrTable_exit(
    void *btx_handle, lttng_ust_zes_zesGetRasProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zes_zesGetRasExpProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zes_ras_exp_dditable_t *);

void btx_register_callbacks_lttng_ust_zes_zesGetRasExpProcAddrTable_entry(
    void *btx_handle, lttng_ust_zes_zesGetRasExpProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zes_zesGetRasExpProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesGetRasExpProcAddrTable_exit(
    void *btx_handle, lttng_ust_zes_zesGetRasExpProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zes_zesGetDiagnosticsProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zes_diagnostics_dditable_t *);

void btx_register_callbacks_lttng_ust_zes_zesGetDiagnosticsProcAddrTable_entry(
    void *btx_handle, lttng_ust_zes_zesGetDiagnosticsProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zes_zesGetDiagnosticsProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesGetDiagnosticsProcAddrTable_exit(
    void *btx_handle, lttng_ust_zes_zesGetDiagnosticsProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zes_zesGetVFManagementExpProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zes_vf_management_exp_dditable_t *);

void btx_register_callbacks_lttng_ust_zes_zesGetVFManagementExpProcAddrTable_entry(
    void *btx_handle, lttng_ust_zes_zesGetVFManagementExpProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zes_zesGetVFManagementExpProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zes_zesGetVFManagementExpProcAddrTable_exit(
    void *btx_handle, lttng_ust_zes_zesGetVFManagementExpProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_desc_t *, zel_tracer_handle_t *, size_t, zel_tracer_desc_t *);

void btx_register_callbacks_lttng_ust_zel_zelTracerCreate_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCreate_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCreate_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCreate_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDestroy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDestroy_entry(
    void *btx_handle, lttng_ust_zel_zelTracerDestroy_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDestroy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDestroy_exit(
    void *btx_handle, lttng_ust_zel_zelTracerDestroy_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerSetPrologues_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_core_callbacks_t *);

void btx_register_callbacks_lttng_ust_zel_zelTracerSetPrologues_entry(
    void *btx_handle, lttng_ust_zel_zelTracerSetPrologues_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerSetPrologues_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerSetPrologues_exit(
    void *btx_handle, lttng_ust_zel_zelTracerSetPrologues_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerSetEpilogues_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_core_callbacks_t *);

void btx_register_callbacks_lttng_ust_zel_zelTracerSetEpilogues_entry(
    void *btx_handle, lttng_ust_zel_zelTracerSetEpilogues_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerSetEpilogues_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerSetEpilogues_exit(
    void *btx_handle, lttng_ust_zel_zelTracerSetEpilogues_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerSetEnabled_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, ze_bool_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerSetEnabled_entry(
    void *btx_handle, lttng_ust_zel_zelTracerSetEnabled_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerSetEnabled_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerSetEnabled_exit(
    void *btx_handle, lttng_ust_zel_zelTracerSetEnabled_exit_callback_f *callback);

typedef void lttng_ust_zel_zelGetTracerApiProcAddrTable_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_api_version_t, zel_tracer_dditable_t *);

void btx_register_callbacks_lttng_ust_zel_zelGetTracerApiProcAddrTable_entry(
    void *btx_handle, lttng_ust_zel_zelGetTracerApiProcAddrTable_entry_callback_f *callback);

typedef void lttng_ust_zel_zelGetTracerApiProcAddrTable_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelGetTracerApiProcAddrTable_exit(
    void *btx_handle, lttng_ust_zel_zelGetTracerApiProcAddrTable_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerInitRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnInitCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerInitRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerInitRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerInitRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerInitRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerInitRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDriverGetRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnDriverGetCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDriverGetRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerDriverGetRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDriverGetRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDriverGetRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerDriverGetRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerInitDriversRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnInitDriversCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerInitDriversRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerInitDriversRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerInitDriversRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerInitDriversRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerInitDriversRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDriverGetApiVersionRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnDriverGetApiVersionCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDriverGetApiVersionRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerDriverGetApiVersionRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDriverGetApiVersionRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDriverGetApiVersionRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerDriverGetApiVersionRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDriverGetPropertiesRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnDriverGetPropertiesCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDriverGetPropertiesRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerDriverGetPropertiesRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDriverGetPropertiesRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDriverGetPropertiesRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerDriverGetPropertiesRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDriverGetIpcPropertiesRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnDriverGetIpcPropertiesCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDriverGetIpcPropertiesRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerDriverGetIpcPropertiesRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDriverGetIpcPropertiesRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDriverGetIpcPropertiesRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerDriverGetIpcPropertiesRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDriverGetExtensionPropertiesRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnDriverGetExtensionPropertiesCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDriverGetExtensionPropertiesRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerDriverGetExtensionPropertiesRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDriverGetExtensionPropertiesRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDriverGetExtensionPropertiesRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerDriverGetExtensionPropertiesRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDriverGetExtensionFunctionAddressRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnDriverGetExtensionFunctionAddressCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDriverGetExtensionFunctionAddressRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerDriverGetExtensionFunctionAddressRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDriverGetExtensionFunctionAddressRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDriverGetExtensionFunctionAddressRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerDriverGetExtensionFunctionAddressRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDriverGetLastErrorDescriptionRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnDriverGetLastErrorDescriptionCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDriverGetLastErrorDescriptionRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerDriverGetLastErrorDescriptionRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDriverGetLastErrorDescriptionRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDriverGetLastErrorDescriptionRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerDriverGetLastErrorDescriptionRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceGetRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnDeviceGetCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceGetRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceGetRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceGetRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceGetRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceGetRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceGetRootDeviceRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnDeviceGetRootDeviceCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceGetRootDeviceRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceGetRootDeviceRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceGetRootDeviceRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceGetRootDeviceRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceGetRootDeviceRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceGetSubDevicesRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnDeviceGetSubDevicesCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceGetSubDevicesRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceGetSubDevicesRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceGetSubDevicesRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceGetSubDevicesRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceGetSubDevicesRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceGetPropertiesRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnDeviceGetPropertiesCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceGetPropertiesRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceGetPropertiesRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceGetPropertiesRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceGetPropertiesRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceGetPropertiesRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceGetComputePropertiesRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnDeviceGetComputePropertiesCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceGetComputePropertiesRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceGetComputePropertiesRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceGetComputePropertiesRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceGetComputePropertiesRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceGetComputePropertiesRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceGetModulePropertiesRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnDeviceGetModulePropertiesCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceGetModulePropertiesRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceGetModulePropertiesRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceGetModulePropertiesRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceGetModulePropertiesRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceGetModulePropertiesRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceGetCommandQueueGroupPropertiesRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnDeviceGetCommandQueueGroupPropertiesCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceGetCommandQueueGroupPropertiesRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceGetCommandQueueGroupPropertiesRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceGetCommandQueueGroupPropertiesRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceGetCommandQueueGroupPropertiesRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceGetCommandQueueGroupPropertiesRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceGetMemoryPropertiesRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnDeviceGetMemoryPropertiesCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceGetMemoryPropertiesRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceGetMemoryPropertiesRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceGetMemoryPropertiesRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceGetMemoryPropertiesRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceGetMemoryPropertiesRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceGetMemoryAccessPropertiesRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnDeviceGetMemoryAccessPropertiesCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceGetMemoryAccessPropertiesRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceGetMemoryAccessPropertiesRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceGetMemoryAccessPropertiesRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceGetMemoryAccessPropertiesRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceGetMemoryAccessPropertiesRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceGetCachePropertiesRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnDeviceGetCachePropertiesCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceGetCachePropertiesRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceGetCachePropertiesRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceGetCachePropertiesRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceGetCachePropertiesRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceGetCachePropertiesRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceGetImagePropertiesRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnDeviceGetImagePropertiesCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceGetImagePropertiesRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceGetImagePropertiesRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceGetImagePropertiesRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceGetImagePropertiesRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceGetImagePropertiesRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceGetExternalMemoryPropertiesRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnDeviceGetExternalMemoryPropertiesCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceGetExternalMemoryPropertiesRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceGetExternalMemoryPropertiesRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceGetExternalMemoryPropertiesRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceGetExternalMemoryPropertiesRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceGetExternalMemoryPropertiesRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceGetP2PPropertiesRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnDeviceGetP2PPropertiesCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceGetP2PPropertiesRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceGetP2PPropertiesRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceGetP2PPropertiesRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceGetP2PPropertiesRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceGetP2PPropertiesRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceCanAccessPeerRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnDeviceCanAccessPeerCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceCanAccessPeerRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceCanAccessPeerRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceCanAccessPeerRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceCanAccessPeerRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceCanAccessPeerRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceGetStatusRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnDeviceGetStatusCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceGetStatusRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceGetStatusRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceGetStatusRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceGetStatusRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceGetStatusRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceGetGlobalTimestampsRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnDeviceGetGlobalTimestampsCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceGetGlobalTimestampsRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceGetGlobalTimestampsRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceGetGlobalTimestampsRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceGetGlobalTimestampsRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceGetGlobalTimestampsRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerContextCreateRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnContextCreateCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerContextCreateRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerContextCreateRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerContextCreateRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerContextCreateRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerContextCreateRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerContextCreateExRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnContextCreateExCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerContextCreateExRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerContextCreateExRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerContextCreateExRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerContextCreateExRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerContextCreateExRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerContextDestroyRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnContextDestroyCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerContextDestroyRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerContextDestroyRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerContextDestroyRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerContextDestroyRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerContextDestroyRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerContextGetStatusRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnContextGetStatusCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerContextGetStatusRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerContextGetStatusRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerContextGetStatusRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerContextGetStatusRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerContextGetStatusRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandQueueCreateRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandQueueCreateCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandQueueCreateRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandQueueCreateRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandQueueCreateRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandQueueCreateRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandQueueCreateRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandQueueDestroyRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandQueueDestroyCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandQueueDestroyRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandQueueDestroyRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandQueueDestroyRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandQueueDestroyRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandQueueDestroyRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandQueueExecuteCommandListsRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandQueueExecuteCommandListsCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandQueueExecuteCommandListsRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandQueueExecuteCommandListsRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandQueueExecuteCommandListsRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandQueueExecuteCommandListsRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandQueueExecuteCommandListsRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandQueueSynchronizeRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandQueueSynchronizeCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandQueueSynchronizeRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandQueueSynchronizeRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandQueueSynchronizeRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandQueueSynchronizeRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandQueueSynchronizeRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandQueueGetOrdinalRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandQueueGetOrdinalCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandQueueGetOrdinalRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandQueueGetOrdinalRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandQueueGetOrdinalRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandQueueGetOrdinalRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandQueueGetOrdinalRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandQueueGetIndexRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandQueueGetIndexCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandQueueGetIndexRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandQueueGetIndexRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandQueueGetIndexRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandQueueGetIndexRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandQueueGetIndexRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListCreateRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListCreateCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListCreateRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListCreateRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListCreateRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListCreateRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListCreateRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListCreateImmediateRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListCreateImmediateCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListCreateImmediateRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListCreateImmediateRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListCreateImmediateRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListCreateImmediateRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListCreateImmediateRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListDestroyRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListDestroyCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListDestroyRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListDestroyRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListDestroyRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListDestroyRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListDestroyRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListCloseRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListCloseCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListCloseRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListCloseRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListCloseRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListCloseRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListCloseRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListResetRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListResetCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListResetRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListResetRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListResetRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListResetRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListResetRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendWriteGlobalTimestampRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListAppendWriteGlobalTimestampCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendWriteGlobalTimestampRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendWriteGlobalTimestampRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendWriteGlobalTimestampRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendWriteGlobalTimestampRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendWriteGlobalTimestampRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListHostSynchronizeRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListHostSynchronizeCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListHostSynchronizeRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListHostSynchronizeRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListHostSynchronizeRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListHostSynchronizeRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListHostSynchronizeRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListGetDeviceHandleRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListGetDeviceHandleCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListGetDeviceHandleRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListGetDeviceHandleRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListGetDeviceHandleRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListGetDeviceHandleRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListGetDeviceHandleRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListGetContextHandleRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListGetContextHandleCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListGetContextHandleRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListGetContextHandleRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListGetContextHandleRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListGetContextHandleRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListGetContextHandleRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListGetOrdinalRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListGetOrdinalCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListGetOrdinalRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListGetOrdinalRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListGetOrdinalRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListGetOrdinalRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListGetOrdinalRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListImmediateGetIndexRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListImmediateGetIndexCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListImmediateGetIndexRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListImmediateGetIndexRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListImmediateGetIndexRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListImmediateGetIndexRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListImmediateGetIndexRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListIsImmediateRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListIsImmediateCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListIsImmediateRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListIsImmediateRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListIsImmediateRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListIsImmediateRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListIsImmediateRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendBarrierRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListAppendBarrierCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendBarrierRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendBarrierRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendBarrierRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendBarrierRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendBarrierRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendMemoryRangesBarrierRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListAppendMemoryRangesBarrierCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendMemoryRangesBarrierRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendMemoryRangesBarrierRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendMemoryRangesBarrierRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendMemoryRangesBarrierRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendMemoryRangesBarrierRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerContextSystemBarrierRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnContextSystemBarrierCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerContextSystemBarrierRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerContextSystemBarrierRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerContextSystemBarrierRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerContextSystemBarrierRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerContextSystemBarrierRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendMemoryCopyRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListAppendMemoryCopyCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendMemoryCopyRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendMemoryCopyRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendMemoryCopyRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendMemoryCopyRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendMemoryCopyRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendMemoryFillRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListAppendMemoryFillCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendMemoryFillRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendMemoryFillRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendMemoryFillRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendMemoryFillRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendMemoryFillRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendMemoryCopyRegionRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListAppendMemoryCopyRegionCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendMemoryCopyRegionRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendMemoryCopyRegionRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendMemoryCopyRegionRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendMemoryCopyRegionRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendMemoryCopyRegionRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendMemoryCopyFromContextRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListAppendMemoryCopyFromContextCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendMemoryCopyFromContextRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendMemoryCopyFromContextRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendMemoryCopyFromContextRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendMemoryCopyFromContextRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendMemoryCopyFromContextRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendImageCopyRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListAppendImageCopyCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendImageCopyRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendImageCopyRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendImageCopyRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendImageCopyRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendImageCopyRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendImageCopyRegionRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListAppendImageCopyRegionCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendImageCopyRegionRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendImageCopyRegionRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendImageCopyRegionRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendImageCopyRegionRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendImageCopyRegionRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendImageCopyToMemoryRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListAppendImageCopyToMemoryCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendImageCopyToMemoryRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendImageCopyToMemoryRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendImageCopyToMemoryRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendImageCopyToMemoryRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendImageCopyToMemoryRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendImageCopyFromMemoryRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListAppendImageCopyFromMemoryCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendImageCopyFromMemoryRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendImageCopyFromMemoryRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendImageCopyFromMemoryRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendImageCopyFromMemoryRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendImageCopyFromMemoryRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendMemoryPrefetchRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListAppendMemoryPrefetchCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendMemoryPrefetchRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendMemoryPrefetchRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendMemoryPrefetchRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendMemoryPrefetchRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendMemoryPrefetchRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendMemAdviseRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListAppendMemAdviseCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendMemAdviseRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendMemAdviseRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendMemAdviseRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendMemAdviseRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendMemAdviseRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventPoolCreateRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnEventPoolCreateCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventPoolCreateRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerEventPoolCreateRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventPoolCreateRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventPoolCreateRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerEventPoolCreateRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventPoolDestroyRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnEventPoolDestroyCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventPoolDestroyRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerEventPoolDestroyRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventPoolDestroyRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventPoolDestroyRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerEventPoolDestroyRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventCreateRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnEventCreateCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventCreateRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerEventCreateRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventCreateRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventCreateRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerEventCreateRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventDestroyRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnEventDestroyCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventDestroyRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerEventDestroyRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventDestroyRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventDestroyRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerEventDestroyRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventPoolGetIpcHandleRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnEventPoolGetIpcHandleCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventPoolGetIpcHandleRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerEventPoolGetIpcHandleRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventPoolGetIpcHandleRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventPoolGetIpcHandleRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerEventPoolGetIpcHandleRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventPoolPutIpcHandleRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnEventPoolPutIpcHandleCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventPoolPutIpcHandleRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerEventPoolPutIpcHandleRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventPoolPutIpcHandleRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventPoolPutIpcHandleRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerEventPoolPutIpcHandleRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventPoolOpenIpcHandleRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnEventPoolOpenIpcHandleCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventPoolOpenIpcHandleRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerEventPoolOpenIpcHandleRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventPoolOpenIpcHandleRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventPoolOpenIpcHandleRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerEventPoolOpenIpcHandleRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventPoolCloseIpcHandleRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnEventPoolCloseIpcHandleCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventPoolCloseIpcHandleRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerEventPoolCloseIpcHandleRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventPoolCloseIpcHandleRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventPoolCloseIpcHandleRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerEventPoolCloseIpcHandleRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendSignalEventRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListAppendSignalEventCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendSignalEventRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendSignalEventRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendSignalEventRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendSignalEventRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendSignalEventRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendWaitOnEventsRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListAppendWaitOnEventsCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendWaitOnEventsRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendWaitOnEventsRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendWaitOnEventsRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendWaitOnEventsRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendWaitOnEventsRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventHostSignalRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnEventHostSignalCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventHostSignalRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerEventHostSignalRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventHostSignalRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventHostSignalRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerEventHostSignalRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventHostSynchronizeRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnEventHostSynchronizeCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventHostSynchronizeRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerEventHostSynchronizeRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventHostSynchronizeRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventHostSynchronizeRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerEventHostSynchronizeRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventQueryStatusRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnEventQueryStatusCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventQueryStatusRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerEventQueryStatusRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventQueryStatusRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventQueryStatusRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerEventQueryStatusRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendEventResetRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListAppendEventResetCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendEventResetRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendEventResetRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendEventResetRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendEventResetRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendEventResetRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventHostResetRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnEventHostResetCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventHostResetRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerEventHostResetRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventHostResetRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventHostResetRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerEventHostResetRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventQueryKernelTimestampRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnEventQueryKernelTimestampCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventQueryKernelTimestampRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerEventQueryKernelTimestampRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventQueryKernelTimestampRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventQueryKernelTimestampRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerEventQueryKernelTimestampRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendQueryKernelTimestampsRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListAppendQueryKernelTimestampsCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendQueryKernelTimestampsRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendQueryKernelTimestampsRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendQueryKernelTimestampsRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendQueryKernelTimestampsRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendQueryKernelTimestampsRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventGetEventPoolRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnEventGetEventPoolCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventGetEventPoolRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerEventGetEventPoolRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventGetEventPoolRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventGetEventPoolRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerEventGetEventPoolRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventGetSignalScopeRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnEventGetSignalScopeCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventGetSignalScopeRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerEventGetSignalScopeRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventGetSignalScopeRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventGetSignalScopeRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerEventGetSignalScopeRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventGetWaitScopeRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnEventGetWaitScopeCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventGetWaitScopeRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerEventGetWaitScopeRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventGetWaitScopeRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventGetWaitScopeRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerEventGetWaitScopeRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventPoolGetContextHandleRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnEventPoolGetContextHandleCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventPoolGetContextHandleRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerEventPoolGetContextHandleRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventPoolGetContextHandleRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventPoolGetContextHandleRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerEventPoolGetContextHandleRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventPoolGetFlagsRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnEventPoolGetFlagsCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventPoolGetFlagsRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerEventPoolGetFlagsRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventPoolGetFlagsRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventPoolGetFlagsRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerEventPoolGetFlagsRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerFenceCreateRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnFenceCreateCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerFenceCreateRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerFenceCreateRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerFenceCreateRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerFenceCreateRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerFenceCreateRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerFenceDestroyRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnFenceDestroyCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerFenceDestroyRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerFenceDestroyRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerFenceDestroyRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerFenceDestroyRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerFenceDestroyRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerFenceHostSynchronizeRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnFenceHostSynchronizeCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerFenceHostSynchronizeRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerFenceHostSynchronizeRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerFenceHostSynchronizeRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerFenceHostSynchronizeRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerFenceHostSynchronizeRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerFenceQueryStatusRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnFenceQueryStatusCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerFenceQueryStatusRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerFenceQueryStatusRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerFenceQueryStatusRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerFenceQueryStatusRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerFenceQueryStatusRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerFenceResetRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnFenceResetCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerFenceResetRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerFenceResetRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerFenceResetRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerFenceResetRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerFenceResetRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerImageGetPropertiesRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnImageGetPropertiesCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerImageGetPropertiesRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerImageGetPropertiesRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerImageGetPropertiesRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerImageGetPropertiesRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerImageGetPropertiesRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerImageCreateRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnImageCreateCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerImageCreateRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerImageCreateRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerImageCreateRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerImageCreateRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerImageCreateRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerImageDestroyRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnImageDestroyCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerImageDestroyRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerImageDestroyRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerImageDestroyRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerImageDestroyRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerImageDestroyRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerMemAllocSharedRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnMemAllocSharedCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerMemAllocSharedRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerMemAllocSharedRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerMemAllocSharedRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerMemAllocSharedRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerMemAllocSharedRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerMemAllocDeviceRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnMemAllocDeviceCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerMemAllocDeviceRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerMemAllocDeviceRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerMemAllocDeviceRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerMemAllocDeviceRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerMemAllocDeviceRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerMemAllocHostRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnMemAllocHostCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerMemAllocHostRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerMemAllocHostRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerMemAllocHostRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerMemAllocHostRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerMemAllocHostRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerMemFreeRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnMemFreeCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerMemFreeRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerMemFreeRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerMemFreeRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerMemFreeRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerMemFreeRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerMemGetAllocPropertiesRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnMemGetAllocPropertiesCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerMemGetAllocPropertiesRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerMemGetAllocPropertiesRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerMemGetAllocPropertiesRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerMemGetAllocPropertiesRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerMemGetAllocPropertiesRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerMemGetAddressRangeRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnMemGetAddressRangeCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerMemGetAddressRangeRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerMemGetAddressRangeRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerMemGetAddressRangeRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerMemGetAddressRangeRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerMemGetAddressRangeRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerMemGetIpcHandleRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnMemGetIpcHandleCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerMemGetIpcHandleRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerMemGetIpcHandleRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerMemGetIpcHandleRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerMemGetIpcHandleRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerMemGetIpcHandleRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerMemGetIpcHandleFromFileDescriptorExpRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnMemGetIpcHandleFromFileDescriptorExpCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerMemGetIpcHandleFromFileDescriptorExpRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerMemGetIpcHandleFromFileDescriptorExpRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerMemGetIpcHandleFromFileDescriptorExpRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerMemGetIpcHandleFromFileDescriptorExpRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerMemGetIpcHandleFromFileDescriptorExpRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerMemGetFileDescriptorFromIpcHandleExpRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnMemGetFileDescriptorFromIpcHandleExpCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerMemGetFileDescriptorFromIpcHandleExpRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerMemGetFileDescriptorFromIpcHandleExpRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerMemGetFileDescriptorFromIpcHandleExpRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerMemGetFileDescriptorFromIpcHandleExpRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerMemGetFileDescriptorFromIpcHandleExpRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerMemPutIpcHandleRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnMemPutIpcHandleCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerMemPutIpcHandleRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerMemPutIpcHandleRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerMemPutIpcHandleRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerMemPutIpcHandleRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerMemPutIpcHandleRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerMemOpenIpcHandleRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnMemOpenIpcHandleCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerMemOpenIpcHandleRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerMemOpenIpcHandleRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerMemOpenIpcHandleRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerMemOpenIpcHandleRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerMemOpenIpcHandleRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerMemCloseIpcHandleRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnMemCloseIpcHandleCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerMemCloseIpcHandleRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerMemCloseIpcHandleRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerMemCloseIpcHandleRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerMemCloseIpcHandleRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerMemCloseIpcHandleRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerMemSetAtomicAccessAttributeExpRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnMemSetAtomicAccessAttributeExpCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerMemSetAtomicAccessAttributeExpRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerMemSetAtomicAccessAttributeExpRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerMemSetAtomicAccessAttributeExpRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerMemSetAtomicAccessAttributeExpRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerMemSetAtomicAccessAttributeExpRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerMemGetAtomicAccessAttributeExpRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnMemGetAtomicAccessAttributeExpCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerMemGetAtomicAccessAttributeExpRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerMemGetAtomicAccessAttributeExpRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerMemGetAtomicAccessAttributeExpRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerMemGetAtomicAccessAttributeExpRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerMemGetAtomicAccessAttributeExpRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerModuleCreateRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnModuleCreateCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerModuleCreateRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerModuleCreateRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerModuleCreateRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerModuleCreateRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerModuleCreateRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerModuleDestroyRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnModuleDestroyCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerModuleDestroyRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerModuleDestroyRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerModuleDestroyRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerModuleDestroyRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerModuleDestroyRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerModuleDynamicLinkRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnModuleDynamicLinkCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerModuleDynamicLinkRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerModuleDynamicLinkRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerModuleDynamicLinkRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerModuleDynamicLinkRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerModuleDynamicLinkRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerModuleBuildLogDestroyRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnModuleBuildLogDestroyCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerModuleBuildLogDestroyRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerModuleBuildLogDestroyRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerModuleBuildLogDestroyRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerModuleBuildLogDestroyRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerModuleBuildLogDestroyRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerModuleBuildLogGetStringRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnModuleBuildLogGetStringCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerModuleBuildLogGetStringRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerModuleBuildLogGetStringRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerModuleBuildLogGetStringRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerModuleBuildLogGetStringRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerModuleBuildLogGetStringRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerModuleGetNativeBinaryRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnModuleGetNativeBinaryCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerModuleGetNativeBinaryRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerModuleGetNativeBinaryRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerModuleGetNativeBinaryRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerModuleGetNativeBinaryRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerModuleGetNativeBinaryRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerModuleGetGlobalPointerRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnModuleGetGlobalPointerCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerModuleGetGlobalPointerRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerModuleGetGlobalPointerRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerModuleGetGlobalPointerRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerModuleGetGlobalPointerRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerModuleGetGlobalPointerRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerModuleGetKernelNamesRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnModuleGetKernelNamesCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerModuleGetKernelNamesRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerModuleGetKernelNamesRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerModuleGetKernelNamesRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerModuleGetKernelNamesRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerModuleGetKernelNamesRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerModuleGetPropertiesRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnModuleGetPropertiesCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerModuleGetPropertiesRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerModuleGetPropertiesRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerModuleGetPropertiesRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerModuleGetPropertiesRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerModuleGetPropertiesRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerKernelCreateRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnKernelCreateCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerKernelCreateRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerKernelCreateRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerKernelCreateRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerKernelCreateRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerKernelCreateRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerKernelDestroyRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnKernelDestroyCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerKernelDestroyRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerKernelDestroyRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerKernelDestroyRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerKernelDestroyRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerKernelDestroyRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerModuleGetFunctionPointerRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnModuleGetFunctionPointerCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerModuleGetFunctionPointerRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerModuleGetFunctionPointerRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerModuleGetFunctionPointerRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerModuleGetFunctionPointerRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerModuleGetFunctionPointerRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerKernelSetGroupSizeRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnKernelSetGroupSizeCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerKernelSetGroupSizeRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerKernelSetGroupSizeRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerKernelSetGroupSizeRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerKernelSetGroupSizeRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerKernelSetGroupSizeRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerKernelSuggestGroupSizeRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnKernelSuggestGroupSizeCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerKernelSuggestGroupSizeRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerKernelSuggestGroupSizeRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerKernelSuggestGroupSizeRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerKernelSuggestGroupSizeRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerKernelSuggestGroupSizeRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerKernelSuggestMaxCooperativeGroupCountRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnKernelSuggestMaxCooperativeGroupCountCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerKernelSuggestMaxCooperativeGroupCountRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerKernelSuggestMaxCooperativeGroupCountRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerKernelSuggestMaxCooperativeGroupCountRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerKernelSuggestMaxCooperativeGroupCountRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerKernelSuggestMaxCooperativeGroupCountRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerKernelSetArgumentValueRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnKernelSetArgumentValueCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerKernelSetArgumentValueRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerKernelSetArgumentValueRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerKernelSetArgumentValueRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerKernelSetArgumentValueRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerKernelSetArgumentValueRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerKernelSetIndirectAccessRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnKernelSetIndirectAccessCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerKernelSetIndirectAccessRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerKernelSetIndirectAccessRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerKernelSetIndirectAccessRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerKernelSetIndirectAccessRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerKernelSetIndirectAccessRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerKernelGetIndirectAccessRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnKernelGetIndirectAccessCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerKernelGetIndirectAccessRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerKernelGetIndirectAccessRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerKernelGetIndirectAccessRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerKernelGetIndirectAccessRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerKernelGetIndirectAccessRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerKernelGetSourceAttributesRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnKernelGetSourceAttributesCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerKernelGetSourceAttributesRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerKernelGetSourceAttributesRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerKernelGetSourceAttributesRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerKernelGetSourceAttributesRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerKernelGetSourceAttributesRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerKernelSetCacheConfigRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnKernelSetCacheConfigCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerKernelSetCacheConfigRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerKernelSetCacheConfigRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerKernelSetCacheConfigRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerKernelSetCacheConfigRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerKernelSetCacheConfigRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerKernelGetPropertiesRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnKernelGetPropertiesCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerKernelGetPropertiesRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerKernelGetPropertiesRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerKernelGetPropertiesRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerKernelGetPropertiesRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerKernelGetPropertiesRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerKernelGetNameRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnKernelGetNameCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerKernelGetNameRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerKernelGetNameRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerKernelGetNameRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerKernelGetNameRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerKernelGetNameRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendLaunchKernelRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListAppendLaunchKernelCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendLaunchKernelRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendLaunchKernelRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendLaunchKernelRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendLaunchKernelRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendLaunchKernelRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendLaunchCooperativeKernelRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListAppendLaunchCooperativeKernelCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendLaunchCooperativeKernelRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendLaunchCooperativeKernelRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendLaunchCooperativeKernelRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendLaunchCooperativeKernelRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendLaunchCooperativeKernelRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendLaunchKernelIndirectRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListAppendLaunchKernelIndirectCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendLaunchKernelIndirectRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendLaunchKernelIndirectRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendLaunchKernelIndirectRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendLaunchKernelIndirectRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendLaunchKernelIndirectRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendLaunchMultipleKernelsIndirectRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListAppendLaunchMultipleKernelsIndirectCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendLaunchMultipleKernelsIndirectRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendLaunchMultipleKernelsIndirectRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendLaunchMultipleKernelsIndirectRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendLaunchMultipleKernelsIndirectRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendLaunchMultipleKernelsIndirectRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerContextMakeMemoryResidentRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnContextMakeMemoryResidentCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerContextMakeMemoryResidentRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerContextMakeMemoryResidentRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerContextMakeMemoryResidentRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerContextMakeMemoryResidentRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerContextMakeMemoryResidentRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerContextEvictMemoryRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnContextEvictMemoryCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerContextEvictMemoryRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerContextEvictMemoryRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerContextEvictMemoryRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerContextEvictMemoryRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerContextEvictMemoryRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerContextMakeImageResidentRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnContextMakeImageResidentCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerContextMakeImageResidentRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerContextMakeImageResidentRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerContextMakeImageResidentRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerContextMakeImageResidentRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerContextMakeImageResidentRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerContextEvictImageRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnContextEvictImageCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerContextEvictImageRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerContextEvictImageRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerContextEvictImageRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerContextEvictImageRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerContextEvictImageRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerSamplerCreateRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnSamplerCreateCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerSamplerCreateRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerSamplerCreateRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerSamplerCreateRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerSamplerCreateRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerSamplerCreateRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerSamplerDestroyRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnSamplerDestroyCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerSamplerDestroyRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerSamplerDestroyRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerSamplerDestroyRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerSamplerDestroyRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerSamplerDestroyRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerVirtualMemReserveRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnVirtualMemReserveCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerVirtualMemReserveRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerVirtualMemReserveRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerVirtualMemReserveRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerVirtualMemReserveRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerVirtualMemReserveRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerVirtualMemFreeRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnVirtualMemFreeCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerVirtualMemFreeRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerVirtualMemFreeRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerVirtualMemFreeRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerVirtualMemFreeRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerVirtualMemFreeRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerVirtualMemQueryPageSizeRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnVirtualMemQueryPageSizeCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerVirtualMemQueryPageSizeRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerVirtualMemQueryPageSizeRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerVirtualMemQueryPageSizeRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerVirtualMemQueryPageSizeRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerVirtualMemQueryPageSizeRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerPhysicalMemCreateRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnPhysicalMemCreateCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerPhysicalMemCreateRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerPhysicalMemCreateRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerPhysicalMemCreateRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerPhysicalMemCreateRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerPhysicalMemCreateRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerPhysicalMemDestroyRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnPhysicalMemDestroyCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerPhysicalMemDestroyRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerPhysicalMemDestroyRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerPhysicalMemDestroyRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerPhysicalMemDestroyRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerPhysicalMemDestroyRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerVirtualMemMapRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnVirtualMemMapCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerVirtualMemMapRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerVirtualMemMapRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerVirtualMemMapRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerVirtualMemMapRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerVirtualMemMapRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerVirtualMemUnmapRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnVirtualMemUnmapCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerVirtualMemUnmapRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerVirtualMemUnmapRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerVirtualMemUnmapRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerVirtualMemUnmapRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerVirtualMemUnmapRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerVirtualMemSetAccessAttributeRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnVirtualMemSetAccessAttributeCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerVirtualMemSetAccessAttributeRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerVirtualMemSetAccessAttributeRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerVirtualMemSetAccessAttributeRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerVirtualMemSetAccessAttributeRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerVirtualMemSetAccessAttributeRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerVirtualMemGetAccessAttributeRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnVirtualMemGetAccessAttributeCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerVirtualMemGetAccessAttributeRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerVirtualMemGetAccessAttributeRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerVirtualMemGetAccessAttributeRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerVirtualMemGetAccessAttributeRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerVirtualMemGetAccessAttributeRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerKernelSetGlobalOffsetExpRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnKernelSetGlobalOffsetExpCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerKernelSetGlobalOffsetExpRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerKernelSetGlobalOffsetExpRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerKernelSetGlobalOffsetExpRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerKernelSetGlobalOffsetExpRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerKernelSetGlobalOffsetExpRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerKernelGetBinaryExpRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnKernelGetBinaryExpCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerKernelGetBinaryExpRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerKernelGetBinaryExpRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerKernelGetBinaryExpRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerKernelGetBinaryExpRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerKernelGetBinaryExpRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceImportExternalSemaphoreExtRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnDeviceImportExternalSemaphoreExtCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceImportExternalSemaphoreExtRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceImportExternalSemaphoreExtRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceImportExternalSemaphoreExtRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceImportExternalSemaphoreExtRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceImportExternalSemaphoreExtRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceReleaseExternalSemaphoreExtRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnDeviceReleaseExternalSemaphoreExtCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceReleaseExternalSemaphoreExtRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceReleaseExternalSemaphoreExtRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceReleaseExternalSemaphoreExtRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceReleaseExternalSemaphoreExtRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceReleaseExternalSemaphoreExtRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendSignalExternalSemaphoreExtRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListAppendSignalExternalSemaphoreExtCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendSignalExternalSemaphoreExtRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendSignalExternalSemaphoreExtRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendSignalExternalSemaphoreExtRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendSignalExternalSemaphoreExtRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendSignalExternalSemaphoreExtRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendWaitExternalSemaphoreExtRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListAppendWaitExternalSemaphoreExtCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendWaitExternalSemaphoreExtRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendWaitExternalSemaphoreExtRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendWaitExternalSemaphoreExtRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendWaitExternalSemaphoreExtRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendWaitExternalSemaphoreExtRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerRTASBuilderCreateExtRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnRTASBuilderCreateExtCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerRTASBuilderCreateExtRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerRTASBuilderCreateExtRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerRTASBuilderCreateExtRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerRTASBuilderCreateExtRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerRTASBuilderCreateExtRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerRTASBuilderGetBuildPropertiesExtRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnRTASBuilderGetBuildPropertiesExtCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerRTASBuilderGetBuildPropertiesExtRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerRTASBuilderGetBuildPropertiesExtRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerRTASBuilderGetBuildPropertiesExtRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerRTASBuilderGetBuildPropertiesExtRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerRTASBuilderGetBuildPropertiesExtRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDriverRTASFormatCompatibilityCheckExtRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnDriverRTASFormatCompatibilityCheckExtCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDriverRTASFormatCompatibilityCheckExtRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerDriverRTASFormatCompatibilityCheckExtRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDriverRTASFormatCompatibilityCheckExtRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDriverRTASFormatCompatibilityCheckExtRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerDriverRTASFormatCompatibilityCheckExtRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerRTASBuilderBuildExtRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnRTASBuilderBuildExtCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerRTASBuilderBuildExtRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerRTASBuilderBuildExtRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerRTASBuilderBuildExtRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerRTASBuilderBuildExtRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerRTASBuilderBuildExtRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerRTASBuilderCommandListAppendCopyExtRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnRTASBuilderCommandListAppendCopyExtCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerRTASBuilderCommandListAppendCopyExtRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerRTASBuilderCommandListAppendCopyExtRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerRTASBuilderCommandListAppendCopyExtRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerRTASBuilderCommandListAppendCopyExtRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerRTASBuilderCommandListAppendCopyExtRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerRTASBuilderDestroyExtRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnRTASBuilderDestroyExtCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerRTASBuilderDestroyExtRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerRTASBuilderDestroyExtRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerRTASBuilderDestroyExtRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerRTASBuilderDestroyExtRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerRTASBuilderDestroyExtRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerRTASParallelOperationCreateExtRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnRTASParallelOperationCreateExtCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerRTASParallelOperationCreateExtRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerRTASParallelOperationCreateExtRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerRTASParallelOperationCreateExtRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerRTASParallelOperationCreateExtRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerRTASParallelOperationCreateExtRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerRTASParallelOperationGetPropertiesExtRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnRTASParallelOperationGetPropertiesExtCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerRTASParallelOperationGetPropertiesExtRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerRTASParallelOperationGetPropertiesExtRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerRTASParallelOperationGetPropertiesExtRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerRTASParallelOperationGetPropertiesExtRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerRTASParallelOperationGetPropertiesExtRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerRTASParallelOperationJoinExtRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnRTASParallelOperationJoinExtCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerRTASParallelOperationJoinExtRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerRTASParallelOperationJoinExtRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerRTASParallelOperationJoinExtRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerRTASParallelOperationJoinExtRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerRTASParallelOperationJoinExtRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerRTASParallelOperationDestroyExtRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnRTASParallelOperationDestroyExtCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerRTASParallelOperationDestroyExtRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerRTASParallelOperationDestroyExtRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerRTASParallelOperationDestroyExtRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerRTASParallelOperationDestroyExtRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerRTASParallelOperationDestroyExtRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceGetVectorWidthPropertiesExtRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnDeviceGetVectorWidthPropertiesExtCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceGetVectorWidthPropertiesExtRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceGetVectorWidthPropertiesExtRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceGetVectorWidthPropertiesExtRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceGetVectorWidthPropertiesExtRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceGetVectorWidthPropertiesExtRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceReserveCacheExtRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnDeviceReserveCacheExtCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceReserveCacheExtRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceReserveCacheExtRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceReserveCacheExtRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceReserveCacheExtRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceReserveCacheExtRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceSetCacheAdviceExtRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnDeviceSetCacheAdviceExtCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceSetCacheAdviceExtRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceSetCacheAdviceExtRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceSetCacheAdviceExtRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceSetCacheAdviceExtRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceSetCacheAdviceExtRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventQueryTimestampsExpRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnEventQueryTimestampsExpCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventQueryTimestampsExpRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerEventQueryTimestampsExpRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventQueryTimestampsExpRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventQueryTimestampsExpRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerEventQueryTimestampsExpRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerImageGetMemoryPropertiesExpRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnImageGetMemoryPropertiesExpCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerImageGetMemoryPropertiesExpRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerImageGetMemoryPropertiesExpRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerImageGetMemoryPropertiesExpRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerImageGetMemoryPropertiesExpRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerImageGetMemoryPropertiesExpRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerImageViewCreateExtRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnImageViewCreateExtCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerImageViewCreateExtRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerImageViewCreateExtRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerImageViewCreateExtRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerImageViewCreateExtRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerImageViewCreateExtRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerImageViewCreateExpRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnImageViewCreateExpCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerImageViewCreateExpRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerImageViewCreateExpRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerImageViewCreateExpRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerImageViewCreateExpRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerImageViewCreateExpRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerKernelSchedulingHintExpRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnKernelSchedulingHintExpCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerKernelSchedulingHintExpRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerKernelSchedulingHintExpRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerKernelSchedulingHintExpRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerKernelSchedulingHintExpRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerKernelSchedulingHintExpRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDevicePciGetPropertiesExtRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnDevicePciGetPropertiesExtCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDevicePciGetPropertiesExtRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerDevicePciGetPropertiesExtRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDevicePciGetPropertiesExtRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDevicePciGetPropertiesExtRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerDevicePciGetPropertiesExtRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendImageCopyToMemoryExtRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListAppendImageCopyToMemoryExtCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendImageCopyToMemoryExtRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendImageCopyToMemoryExtRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendImageCopyToMemoryExtRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendImageCopyToMemoryExtRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendImageCopyToMemoryExtRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendImageCopyFromMemoryExtRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListAppendImageCopyFromMemoryExtCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendImageCopyFromMemoryExtRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendImageCopyFromMemoryExtRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListAppendImageCopyFromMemoryExtRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListAppendImageCopyFromMemoryExtRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListAppendImageCopyFromMemoryExtRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerImageGetAllocPropertiesExtRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnImageGetAllocPropertiesExtCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerImageGetAllocPropertiesExtRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerImageGetAllocPropertiesExtRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerImageGetAllocPropertiesExtRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerImageGetAllocPropertiesExtRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerImageGetAllocPropertiesExtRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerModuleInspectLinkageExtRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnModuleInspectLinkageExtCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerModuleInspectLinkageExtRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerModuleInspectLinkageExtRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerModuleInspectLinkageExtRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerModuleInspectLinkageExtRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerModuleInspectLinkageExtRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerMemFreeExtRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnMemFreeExtCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerMemFreeExtRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerMemFreeExtRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerMemFreeExtRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerMemFreeExtRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerMemFreeExtRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerFabricVertexGetExpRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnFabricVertexGetExpCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerFabricVertexGetExpRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerFabricVertexGetExpRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerFabricVertexGetExpRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerFabricVertexGetExpRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerFabricVertexGetExpRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerFabricVertexGetSubVerticesExpRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnFabricVertexGetSubVerticesExpCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerFabricVertexGetSubVerticesExpRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerFabricVertexGetSubVerticesExpRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerFabricVertexGetSubVerticesExpRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerFabricVertexGetSubVerticesExpRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerFabricVertexGetSubVerticesExpRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerFabricVertexGetPropertiesExpRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnFabricVertexGetPropertiesExpCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerFabricVertexGetPropertiesExpRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerFabricVertexGetPropertiesExpRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerFabricVertexGetPropertiesExpRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerFabricVertexGetPropertiesExpRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerFabricVertexGetPropertiesExpRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerFabricVertexGetDeviceExpRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnFabricVertexGetDeviceExpCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerFabricVertexGetDeviceExpRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerFabricVertexGetDeviceExpRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerFabricVertexGetDeviceExpRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerFabricVertexGetDeviceExpRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerFabricVertexGetDeviceExpRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceGetFabricVertexExpRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnDeviceGetFabricVertexExpCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceGetFabricVertexExpRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceGetFabricVertexExpRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDeviceGetFabricVertexExpRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDeviceGetFabricVertexExpRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerDeviceGetFabricVertexExpRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerFabricEdgeGetExpRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnFabricEdgeGetExpCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerFabricEdgeGetExpRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerFabricEdgeGetExpRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerFabricEdgeGetExpRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerFabricEdgeGetExpRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerFabricEdgeGetExpRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerFabricEdgeGetVerticesExpRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnFabricEdgeGetVerticesExpCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerFabricEdgeGetVerticesExpRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerFabricEdgeGetVerticesExpRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerFabricEdgeGetVerticesExpRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerFabricEdgeGetVerticesExpRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerFabricEdgeGetVerticesExpRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerFabricEdgeGetPropertiesExpRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnFabricEdgeGetPropertiesExpCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerFabricEdgeGetPropertiesExpRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerFabricEdgeGetPropertiesExpRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerFabricEdgeGetPropertiesExpRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerFabricEdgeGetPropertiesExpRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerFabricEdgeGetPropertiesExpRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventQueryKernelTimestampsExtRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnEventQueryKernelTimestampsExtCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventQueryKernelTimestampsExtRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerEventQueryKernelTimestampsExtRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerEventQueryKernelTimestampsExtRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerEventQueryKernelTimestampsExtRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerEventQueryKernelTimestampsExtRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerRTASBuilderCreateExpRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnRTASBuilderCreateExpCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerRTASBuilderCreateExpRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerRTASBuilderCreateExpRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerRTASBuilderCreateExpRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerRTASBuilderCreateExpRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerRTASBuilderCreateExpRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerRTASBuilderGetBuildPropertiesExpRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnRTASBuilderGetBuildPropertiesExpCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerRTASBuilderGetBuildPropertiesExpRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerRTASBuilderGetBuildPropertiesExpRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerRTASBuilderGetBuildPropertiesExpRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerRTASBuilderGetBuildPropertiesExpRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerRTASBuilderGetBuildPropertiesExpRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDriverRTASFormatCompatibilityCheckExpRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnDriverRTASFormatCompatibilityCheckExpCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDriverRTASFormatCompatibilityCheckExpRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerDriverRTASFormatCompatibilityCheckExpRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerDriverRTASFormatCompatibilityCheckExpRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerDriverRTASFormatCompatibilityCheckExpRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerDriverRTASFormatCompatibilityCheckExpRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerRTASBuilderBuildExpRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnRTASBuilderBuildExpCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerRTASBuilderBuildExpRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerRTASBuilderBuildExpRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerRTASBuilderBuildExpRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerRTASBuilderBuildExpRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerRTASBuilderBuildExpRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerRTASBuilderDestroyExpRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnRTASBuilderDestroyExpCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerRTASBuilderDestroyExpRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerRTASBuilderDestroyExpRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerRTASBuilderDestroyExpRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerRTASBuilderDestroyExpRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerRTASBuilderDestroyExpRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerRTASParallelOperationCreateExpRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnRTASParallelOperationCreateExpCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerRTASParallelOperationCreateExpRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerRTASParallelOperationCreateExpRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerRTASParallelOperationCreateExpRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerRTASParallelOperationCreateExpRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerRTASParallelOperationCreateExpRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerRTASParallelOperationGetPropertiesExpRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnRTASParallelOperationGetPropertiesExpCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerRTASParallelOperationGetPropertiesExpRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerRTASParallelOperationGetPropertiesExpRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerRTASParallelOperationGetPropertiesExpRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerRTASParallelOperationGetPropertiesExpRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerRTASParallelOperationGetPropertiesExpRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerRTASParallelOperationJoinExpRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnRTASParallelOperationJoinExpCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerRTASParallelOperationJoinExpRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerRTASParallelOperationJoinExpRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerRTASParallelOperationJoinExpRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerRTASParallelOperationJoinExpRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerRTASParallelOperationJoinExpRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerRTASParallelOperationDestroyExpRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnRTASParallelOperationDestroyExpCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerRTASParallelOperationDestroyExpRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerRTASParallelOperationDestroyExpRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerRTASParallelOperationDestroyExpRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerRTASParallelOperationDestroyExpRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerRTASParallelOperationDestroyExpRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerMemGetPitchFor2dImageRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnMemGetPitchFor2dImageCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerMemGetPitchFor2dImageRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerMemGetPitchFor2dImageRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerMemGetPitchFor2dImageRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerMemGetPitchFor2dImageRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerMemGetPitchFor2dImageRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerImageGetDeviceOffsetExpRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnImageGetDeviceOffsetExpCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerImageGetDeviceOffsetExpRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerImageGetDeviceOffsetExpRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerImageGetDeviceOffsetExpRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerImageGetDeviceOffsetExpRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerImageGetDeviceOffsetExpRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListCreateCloneExpRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListCreateCloneExpCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListCreateCloneExpRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListCreateCloneExpRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListCreateCloneExpRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListCreateCloneExpRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListCreateCloneExpRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListImmediateAppendCommandListsExpRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListImmediateAppendCommandListsExpCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListImmediateAppendCommandListsExpRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListImmediateAppendCommandListsExpRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListImmediateAppendCommandListsExpRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListImmediateAppendCommandListsExpRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListImmediateAppendCommandListsExpRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListGetNextCommandIdExpRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListGetNextCommandIdExpCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListGetNextCommandIdExpRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListGetNextCommandIdExpRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListGetNextCommandIdExpRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListGetNextCommandIdExpRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListGetNextCommandIdExpRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListGetNextCommandIdWithKernelsExpRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListGetNextCommandIdWithKernelsExpCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListGetNextCommandIdWithKernelsExpRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListGetNextCommandIdWithKernelsExpRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListGetNextCommandIdWithKernelsExpRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListGetNextCommandIdWithKernelsExpRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListGetNextCommandIdWithKernelsExpRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListUpdateMutableCommandsExpRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListUpdateMutableCommandsExpCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListUpdateMutableCommandsExpRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListUpdateMutableCommandsExpRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListUpdateMutableCommandsExpRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListUpdateMutableCommandsExpRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListUpdateMutableCommandsExpRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListUpdateMutableCommandSignalEventExpRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListUpdateMutableCommandSignalEventExpCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListUpdateMutableCommandSignalEventExpRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListUpdateMutableCommandSignalEventExpRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListUpdateMutableCommandSignalEventExpRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListUpdateMutableCommandSignalEventExpRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListUpdateMutableCommandSignalEventExpRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListUpdateMutableCommandWaitEventsExpRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListUpdateMutableCommandWaitEventsExpCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListUpdateMutableCommandWaitEventsExpRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListUpdateMutableCommandWaitEventsExpRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListUpdateMutableCommandWaitEventsExpRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListUpdateMutableCommandWaitEventsExpRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListUpdateMutableCommandWaitEventsExpRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListUpdateMutableCommandKernelsExpRegisterCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_handle_t, zel_tracer_reg_t, ze_pfnCommandListUpdateMutableCommandKernelsExpCb_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListUpdateMutableCommandKernelsExpRegisterCallback_entry(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListUpdateMutableCommandKernelsExpRegisterCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelTracerCommandListUpdateMutableCommandKernelsExpRegisterCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelTracerCommandListUpdateMutableCommandKernelsExpRegisterCallback_exit(
    void *btx_handle, lttng_ust_zel_zelTracerCommandListUpdateMutableCommandKernelsExpRegisterCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelLoaderGetVersions_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, size_t *, zel_component_version_t *, size_t);

void btx_register_callbacks_lttng_ust_zel_zelLoaderGetVersions_entry(
    void *btx_handle, lttng_ust_zel_zelLoaderGetVersions_entry_callback_f *callback);

typedef void lttng_ust_zel_zelLoaderGetVersions_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, size_t, zel_component_version_t *);

void btx_register_callbacks_lttng_ust_zel_zelLoaderGetVersions_exit(
    void *btx_handle, lttng_ust_zel_zelLoaderGetVersions_exit_callback_f *callback);

typedef void lttng_ust_zel_zelLoaderTranslateHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_handle_type_t, void *, void **);

void btx_register_callbacks_lttng_ust_zel_zelLoaderTranslateHandle_entry(
    void *btx_handle, lttng_ust_zel_zelLoaderTranslateHandle_entry_callback_f *callback);

typedef void lttng_ust_zel_zelLoaderTranslateHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, void *);

void btx_register_callbacks_lttng_ust_zel_zelLoaderTranslateHandle_exit(
    void *btx_handle, lttng_ust_zel_zelLoaderTranslateHandle_exit_callback_f *callback);

typedef void lttng_ust_zel_zelSetDriverTeardown_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_zel_zelSetDriverTeardown_entry(
    void *btx_handle, lttng_ust_zel_zelSetDriverTeardown_entry_callback_f *callback);

typedef void lttng_ust_zel_zelSetDriverTeardown_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelSetDriverTeardown_exit(
    void *btx_handle, lttng_ust_zel_zelSetDriverTeardown_exit_callback_f *callback);

typedef void lttng_ust_zel_zelSetDelayLoaderContextTeardown_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_zel_zelSetDelayLoaderContextTeardown_entry(
    void *btx_handle, lttng_ust_zel_zelSetDelayLoaderContextTeardown_entry_callback_f *callback);

typedef void lttng_ust_zel_zelSetDelayLoaderContextTeardown_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_zel_zelSetDelayLoaderContextTeardown_exit(
    void *btx_handle, lttng_ust_zel_zelSetDelayLoaderContextTeardown_exit_callback_f *callback);

typedef void lttng_ust_zel_zelLoaderContextTeardown_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_zel_zelLoaderContextTeardown_entry(
    void *btx_handle, lttng_ust_zel_zelLoaderContextTeardown_entry_callback_f *callback);

typedef void lttng_ust_zel_zelLoaderContextTeardown_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_zel_zelLoaderContextTeardown_exit(
    void *btx_handle, lttng_ust_zel_zelLoaderContextTeardown_exit_callback_f *callback);

typedef void lttng_ust_zel_zelEnableTracingLayer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_zel_zelEnableTracingLayer_entry(
    void *btx_handle, lttng_ust_zel_zelEnableTracingLayer_entry_callback_f *callback);

typedef void lttng_ust_zel_zelEnableTracingLayer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelEnableTracingLayer_exit(
    void *btx_handle, lttng_ust_zel_zelEnableTracingLayer_exit_callback_f *callback);

typedef void lttng_ust_zel_zelCheckIsLoaderInTearDown_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_zel_zelCheckIsLoaderInTearDown_entry(
    void *btx_handle, lttng_ust_zel_zelCheckIsLoaderInTearDown_entry_callback_f *callback);

typedef void lttng_ust_zel_zelCheckIsLoaderInTearDown_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, _Bool);

void btx_register_callbacks_lttng_ust_zel_zelCheckIsLoaderInTearDown_exit(
    void *btx_handle, lttng_ust_zel_zelCheckIsLoaderInTearDown_exit_callback_f *callback);

typedef void lttng_ust_zel_zelRegisterTeardownCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_loader_teardown_callback_t, zel_application_teardown_callback_t *, uint32_t *);

void btx_register_callbacks_lttng_ust_zel_zelRegisterTeardownCallback_entry(
    void *btx_handle, lttng_ust_zel_zelRegisterTeardownCallback_entry_callback_f *callback);

typedef void lttng_ust_zel_zelRegisterTeardownCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelRegisterTeardownCallback_exit(
    void *btx_handle, lttng_ust_zel_zelRegisterTeardownCallback_exit_callback_f *callback);

typedef void lttng_ust_zel_zelDisableTracingLayer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_zel_zelDisableTracingLayer_entry(
    void *btx_handle, lttng_ust_zel_zelDisableTracingLayer_entry_callback_f *callback);

typedef void lttng_ust_zel_zelDisableTracingLayer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelDisableTracingLayer_exit(
    void *btx_handle, lttng_ust_zel_zelDisableTracingLayer_exit_callback_f *callback);

typedef void lttng_ust_zel_zelLoaderDriverCheck_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_init_flags_t, ze_init_driver_type_desc_t *, ze_global_dditable_t *, void *, _Bool *, _Bool);

void btx_register_callbacks_lttng_ust_zel_zelLoaderDriverCheck_entry(
    void *btx_handle, lttng_ust_zel_zelLoaderDriverCheck_entry_callback_f *callback);

typedef void lttng_ust_zel_zelLoaderDriverCheck_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelLoaderDriverCheck_exit(
    void *btx_handle, lttng_ust_zel_zelLoaderDriverCheck_exit_callback_f *callback);

typedef void lttng_ust_zel_zelLoaderTracingLayerInit_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *);

void btx_register_callbacks_lttng_ust_zel_zelLoaderTracingLayerInit_entry(
    void *btx_handle, lttng_ust_zel_zelLoaderTracingLayerInit_entry_callback_f *callback);

typedef void lttng_ust_zel_zelLoaderTracingLayerInit_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zel_zelLoaderTracingLayerInit_exit(
    void *btx_handle, lttng_ust_zel_zelLoaderTracingLayerInit_exit_callback_f *callback);

typedef void lttng_ust_zel_zeLoaderGetTracingHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_zel_zeLoaderGetTracingHandle_entry(
    void *btx_handle, lttng_ust_zel_zeLoaderGetTracingHandle_entry_callback_f *callback);

typedef void lttng_ust_zel_zeLoaderGetTracingHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *);

void btx_register_callbacks_lttng_ust_zel_zeLoaderGetTracingHandle_exit(
    void *btx_handle, lttng_ust_zel_zeLoaderGetTracingHandle_exit_callback_f *callback);

typedef void lttng_ust_zel_zelLoaderGetContext_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_zel_zelLoaderGetContext_entry(
    void *btx_handle, lttng_ust_zel_zelLoaderGetContext_entry_callback_f *callback);

typedef void lttng_ust_zel_zelLoaderGetContext_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *);

void btx_register_callbacks_lttng_ust_zel_zelLoaderGetContext_exit(
    void *btx_handle, lttng_ust_zel_zelLoaderGetContext_exit_callback_f *callback);

typedef void lttng_ust_zel_zelLoaderGetVersionsInternal_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, size_t *, zel_component_version_t *, size_t);

void btx_register_callbacks_lttng_ust_zel_zelLoaderGetVersionsInternal_entry(
    void *btx_handle, lttng_ust_zel_zelLoaderGetVersionsInternal_entry_callback_f *callback);

typedef void lttng_ust_zel_zelLoaderGetVersionsInternal_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, size_t, size_t, zel_component_version_t *);

void btx_register_callbacks_lttng_ust_zel_zelLoaderGetVersionsInternal_exit(
    void *btx_handle, lttng_ust_zel_zelLoaderGetVersionsInternal_exit_callback_f *callback);

typedef void lttng_ust_zel_zelLoaderTranslateHandleInternal_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_handle_type_t, void *, void **);

void btx_register_callbacks_lttng_ust_zel_zelLoaderTranslateHandleInternal_entry(
    void *btx_handle, lttng_ust_zel_zelLoaderTranslateHandleInternal_entry_callback_f *callback);

typedef void lttng_ust_zel_zelLoaderTranslateHandleInternal_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, void *);

void btx_register_callbacks_lttng_ust_zel_zelLoaderTranslateHandleInternal_exit(
    void *btx_handle, lttng_ust_zel_zelLoaderTranslateHandleInternal_exit_callback_f *callback);

typedef void lttng_ust_zex_zexKernelGetBaseAddress_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_kernel_handle_t, uint64_t *);

void btx_register_callbacks_lttng_ust_zex_zexKernelGetBaseAddress_entry(
    void *btx_handle, lttng_ust_zex_zexKernelGetBaseAddress_entry_callback_f *callback);

typedef void lttng_ust_zex_zexKernelGetBaseAddress_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zex_zexKernelGetBaseAddress_exit(
    void *btx_handle, lttng_ust_zex_zexKernelGetBaseAddress_exit_callback_f *callback);

typedef void lttng_ust_zex_zexKernelGetArgumentSize_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_kernel_handle_t, uint32_t, uint32_t *);

void btx_register_callbacks_lttng_ust_zex_zexKernelGetArgumentSize_entry(
    void *btx_handle, lttng_ust_zex_zexKernelGetArgumentSize_entry_callback_f *callback);

typedef void lttng_ust_zex_zexKernelGetArgumentSize_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zex_zexKernelGetArgumentSize_exit(
    void *btx_handle, lttng_ust_zex_zexKernelGetArgumentSize_exit_callback_f *callback);

typedef void lttng_ust_zex_zexKernelGetArgumentType_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_kernel_handle_t, uint32_t, uint32_t *, char *);

void btx_register_callbacks_lttng_ust_zex_zexKernelGetArgumentType_entry(
    void *btx_handle, lttng_ust_zex_zexKernelGetArgumentType_entry_callback_f *callback);

typedef void lttng_ust_zex_zexKernelGetArgumentType_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zex_zexKernelGetArgumentType_exit(
    void *btx_handle, lttng_ust_zex_zexKernelGetArgumentType_exit_callback_f *callback);

typedef void lttng_ust_zex_zexDriverImportExternalPointer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_driver_handle_t, void *, size_t);

void btx_register_callbacks_lttng_ust_zex_zexDriverImportExternalPointer_entry(
    void *btx_handle, lttng_ust_zex_zexDriverImportExternalPointer_entry_callback_f *callback);

typedef void lttng_ust_zex_zexDriverImportExternalPointer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zex_zexDriverImportExternalPointer_exit(
    void *btx_handle, lttng_ust_zex_zexDriverImportExternalPointer_exit_callback_f *callback);

typedef void lttng_ust_zex_zexDriverReleaseImportedPointer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_driver_handle_t, void *);

void btx_register_callbacks_lttng_ust_zex_zexDriverReleaseImportedPointer_entry(
    void *btx_handle, lttng_ust_zex_zexDriverReleaseImportedPointer_entry_callback_f *callback);

typedef void lttng_ust_zex_zexDriverReleaseImportedPointer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zex_zexDriverReleaseImportedPointer_exit(
    void *btx_handle, lttng_ust_zex_zexDriverReleaseImportedPointer_exit_callback_f *callback);

typedef void lttng_ust_zex_zexDriverGetHostPointerBaseAddress_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_driver_handle_t, void *, void **);

void btx_register_callbacks_lttng_ust_zex_zexDriverGetHostPointerBaseAddress_entry(
    void *btx_handle, lttng_ust_zex_zexDriverGetHostPointerBaseAddress_entry_callback_f *callback);

typedef void lttng_ust_zex_zexDriverGetHostPointerBaseAddress_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zex_zexDriverGetHostPointerBaseAddress_exit(
    void *btx_handle, lttng_ust_zex_zexDriverGetHostPointerBaseAddress_exit_callback_f *callback);

typedef void lttng_ust_zex_zexMemGetIpcHandles_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, void *, uint32_t *, ze_ipc_mem_handle_t *, uint32_t);

void btx_register_callbacks_lttng_ust_zex_zexMemGetIpcHandles_entry(
    void *btx_handle, lttng_ust_zex_zexMemGetIpcHandles_entry_callback_f *callback);

typedef void lttng_ust_zex_zexMemGetIpcHandles_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, uint32_t, size_t, ze_ipc_mem_handle_t *);

void btx_register_callbacks_lttng_ust_zex_zexMemGetIpcHandles_exit(
    void *btx_handle, lttng_ust_zex_zexMemGetIpcHandles_exit_callback_f *callback);

typedef void lttng_ust_zex_zexMemOpenIpcHandles_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, ze_device_handle_t, uint32_t, ze_ipc_mem_handle_t *, ze_ipc_memory_flags_t, void **, size_t, ze_ipc_mem_handle_t *);

void btx_register_callbacks_lttng_ust_zex_zexMemOpenIpcHandles_entry(
    void *btx_handle, lttng_ust_zex_zexMemOpenIpcHandles_entry_callback_f *callback);

typedef void lttng_ust_zex_zexMemOpenIpcHandles_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t, void *);

void btx_register_callbacks_lttng_ust_zex_zexMemOpenIpcHandles_exit(
    void *btx_handle, lttng_ust_zex_zexMemOpenIpcHandles_exit_callback_f *callback);

typedef void lttng_ust_zex_zexCommandListAppendWaitOnMemory_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, zex_wait_on_mem_desc_t *, void *, uint32_t, ze_event_handle_t);

void btx_register_callbacks_lttng_ust_zex_zexCommandListAppendWaitOnMemory_entry(
    void *btx_handle, lttng_ust_zex_zexCommandListAppendWaitOnMemory_entry_callback_f *callback);

typedef void lttng_ust_zex_zexCommandListAppendWaitOnMemory_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zex_zexCommandListAppendWaitOnMemory_exit(
    void *btx_handle, lttng_ust_zex_zexCommandListAppendWaitOnMemory_exit_callback_f *callback);

typedef void lttng_ust_zex_zexCommandListAppendWriteToMemory_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_handle_t, zex_write_to_mem_desc_t *, void *, uint64_t);

void btx_register_callbacks_lttng_ust_zex_zexCommandListAppendWriteToMemory_entry(
    void *btx_handle, lttng_ust_zex_zexCommandListAppendWriteToMemory_entry_callback_f *callback);

typedef void lttng_ust_zex_zexCommandListAppendWriteToMemory_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zex_zexCommandListAppendWriteToMemory_exit(
    void *btx_handle, lttng_ust_zex_zexCommandListAppendWriteToMemory_exit_callback_f *callback);

typedef void lttng_ust_zex_zexEventGetDeviceAddress_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_event_handle_t, uint64_t *, uint64_t *);

void btx_register_callbacks_lttng_ust_zex_zexEventGetDeviceAddress_entry(
    void *btx_handle, lttng_ust_zex_zexEventGetDeviceAddress_entry_callback_f *callback);

typedef void lttng_ust_zex_zexEventGetDeviceAddress_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zex_zexEventGetDeviceAddress_exit(
    void *btx_handle, lttng_ust_zex_zexEventGetDeviceAddress_exit_callback_f *callback);

typedef void lttng_ust_zex_zexCounterBasedEventCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, ze_device_handle_t, uint64_t *, uint64_t *, uint64_t, ze_event_desc_t *, ze_event_handle_t *);

void btx_register_callbacks_lttng_ust_zex_zexCounterBasedEventCreate_entry(
    void *btx_handle, lttng_ust_zex_zexCounterBasedEventCreate_entry_callback_f *callback);

typedef void lttng_ust_zex_zexCounterBasedEventCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zex_zexCounterBasedEventCreate_exit(
    void *btx_handle, lttng_ust_zex_zexCounterBasedEventCreate_exit_callback_f *callback);

typedef void lttng_ust_zex_zexCounterBasedEventGetIpcHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_event_handle_t, zex_ipc_counter_based_event_handle_t *);

void btx_register_callbacks_lttng_ust_zex_zexCounterBasedEventGetIpcHandle_entry(
    void *btx_handle, lttng_ust_zex_zexCounterBasedEventGetIpcHandle_entry_callback_f *callback);

typedef void lttng_ust_zex_zexCounterBasedEventGetIpcHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zex_zexCounterBasedEventGetIpcHandle_exit(
    void *btx_handle, lttng_ust_zex_zexCounterBasedEventGetIpcHandle_exit_callback_f *callback);

typedef void lttng_ust_zex_zexCounterBasedEventCloseIpcHandle_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_event_handle_t);

void btx_register_callbacks_lttng_ust_zex_zexCounterBasedEventCloseIpcHandle_entry(
    void *btx_handle, lttng_ust_zex_zexCounterBasedEventCloseIpcHandle_entry_callback_f *callback);

typedef void lttng_ust_zex_zexCounterBasedEventCloseIpcHandle_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zex_zexCounterBasedEventCloseIpcHandle_exit(
    void *btx_handle, lttng_ust_zex_zexCounterBasedEventCloseIpcHandle_exit_callback_f *callback);

typedef void lttng_ust_zex_zexIntelAllocateNetworkInterrupt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, uint32_t *);

void btx_register_callbacks_lttng_ust_zex_zexIntelAllocateNetworkInterrupt_entry(
    void *btx_handle, lttng_ust_zex_zexIntelAllocateNetworkInterrupt_entry_callback_f *callback);

typedef void lttng_ust_zex_zexIntelAllocateNetworkInterrupt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zex_zexIntelAllocateNetworkInterrupt_exit(
    void *btx_handle, lttng_ust_zex_zexIntelAllocateNetworkInterrupt_exit_callback_f *callback);

typedef void lttng_ust_zex_zexIntelReleaseNetworkInterrupt_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, uint32_t);

void btx_register_callbacks_lttng_ust_zex_zexIntelReleaseNetworkInterrupt_entry(
    void *btx_handle, lttng_ust_zex_zexIntelReleaseNetworkInterrupt_entry_callback_f *callback);

typedef void lttng_ust_zex_zexIntelReleaseNetworkInterrupt_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_lttng_ust_zex_zexIntelReleaseNetworkInterrupt_exit(
    void *btx_handle, lttng_ust_zex_zexIntelReleaseNetworkInterrupt_exit_callback_f *callback);

typedef void lttng_ust_ze_sampling_deviceProperties_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, uint32_t, size_t, zes_device_properties_t *);

void btx_register_callbacks_lttng_ust_ze_sampling_deviceProperties(
    void *btx_handle, lttng_ust_ze_sampling_deviceProperties_callback_f *callback);

typedef void lttng_ust_ze_sampling_engineProperties_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, zes_engine_handle_t, size_t, zes_engine_properties_t *);

void btx_register_callbacks_lttng_ust_ze_sampling_engineProperties(
    void *btx_handle, lttng_ust_ze_sampling_engineProperties_callback_f *callback);

typedef void lttng_ust_ze_sampling_engineStats_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, zes_engine_handle_t, size_t, zes_engine_stats_t *);

void btx_register_callbacks_lttng_ust_ze_sampling_engineStats(
    void *btx_handle, lttng_ust_ze_sampling_engineStats_callback_f *callback);

typedef void lttng_ust_ze_sampling_powerProperties_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, zes_pwr_handle_t, size_t, zes_power_properties_t *);

void btx_register_callbacks_lttng_ust_ze_sampling_powerProperties(
    void *btx_handle, lttng_ust_ze_sampling_powerProperties_callback_f *callback);

typedef void lttng_ust_ze_sampling_gpu_energy_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, zes_pwr_handle_t, uint32_t, size_t, zes_power_energy_counter_t *);

void btx_register_callbacks_lttng_ust_ze_sampling_gpu_energy(
    void *btx_handle, lttng_ust_ze_sampling_gpu_energy_callback_f *callback);

typedef void lttng_ust_ze_sampling_freqProperties_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, zes_freq_handle_t, size_t, zes_freq_properties_t *);

void btx_register_callbacks_lttng_ust_ze_sampling_freqProperties(
    void *btx_handle, lttng_ust_ze_sampling_freqProperties_callback_f *callback);

typedef void lttng_ust_ze_sampling_gpu_frequency_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, zes_freq_handle_t, uint32_t, size_t, zes_freq_state_t *);

void btx_register_callbacks_lttng_ust_ze_sampling_gpu_frequency(
    void *btx_handle, lttng_ust_ze_sampling_gpu_frequency_callback_f *callback);

typedef void lttng_ust_ze_sampling_fabricPortProperties_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, zes_fabric_port_handle_t, size_t, zes_fabric_port_properties_t *);

void btx_register_callbacks_lttng_ust_ze_sampling_fabricPortProperties(
    void *btx_handle, lttng_ust_ze_sampling_fabricPortProperties_callback_f *callback);

typedef void lttng_ust_ze_sampling_fabricPort_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, zes_fabric_port_handle_t, size_t, zes_fabric_port_state_t *, size_t, zes_fabric_port_throughput_t *);

void btx_register_callbacks_lttng_ust_ze_sampling_fabricPort(
    void *btx_handle, lttng_ust_ze_sampling_fabricPort_callback_f *callback);

typedef void lttng_ust_ze_sampling_memoryProperties_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, zes_mem_handle_t, size_t, zes_mem_properties_t *);

void btx_register_callbacks_lttng_ust_ze_sampling_memoryProperties(
    void *btx_handle, lttng_ust_ze_sampling_memoryProperties_callback_f *callback);

typedef void lttng_ust_ze_sampling_memStats_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_handle_t, zes_mem_handle_t, size_t, zes_mem_state_t *, size_t, zes_mem_bandwidth_t *);

void btx_register_callbacks_lttng_ust_ze_sampling_memStats(
    void *btx_handle, lttng_ust_ze_sampling_memStats_callback_f *callback);

typedef void lttng_ust_ze_profiling_event_profiling_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_event_handle_t);

void btx_register_callbacks_lttng_ust_ze_profiling_event_profiling(
    void *btx_handle, lttng_ust_ze_profiling_event_profiling_callback_f *callback);

typedef void lttng_ust_ze_profiling_event_profiling_results_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_event_handle_t, ze_result_t, ze_result_t, uint64_t, uint64_t, uint64_t, uint64_t);

void btx_register_callbacks_lttng_ust_ze_profiling_event_profiling_results(
    void *btx_handle, lttng_ust_ze_profiling_event_profiling_results_callback_f *callback);

typedef void lttng_ust_ze_properties_driver_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_driver_handle_t, size_t, ze_driver_properties_t *);

void btx_register_callbacks_lttng_ust_ze_properties_driver(
    void *btx_handle, lttng_ust_ze_properties_driver_callback_f *callback);

typedef void lttng_ust_ze_properties_device_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_driver_handle_t, ze_device_handle_t, size_t, ze_device_properties_t *);

void btx_register_callbacks_lttng_ust_ze_properties_device(
    void *btx_handle, lttng_ust_ze_properties_device_callback_f *callback);

typedef void lttng_ust_ze_properties_subdevice_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_driver_handle_t, ze_device_handle_t, ze_device_handle_t, size_t, ze_device_properties_t *);

void btx_register_callbacks_lttng_ust_ze_properties_subdevice(
    void *btx_handle, lttng_ust_ze_properties_subdevice_callback_f *callback);

typedef void lttng_ust_ze_properties_command_queue_group_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_driver_handle_t, ze_device_handle_t, uint32_t, size_t, ze_command_queue_group_properties_t *);

void btx_register_callbacks_lttng_ust_ze_properties_command_queue_group(
    void *btx_handle, lttng_ust_ze_properties_command_queue_group_callback_f *callback);

typedef void lttng_ust_ze_properties_device_timer_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_handle_t, uint64_t, uint64_t);

void btx_register_callbacks_lttng_ust_ze_properties_device_timer(
    void *btx_handle, lttng_ust_ze_properties_device_timer_callback_f *callback);

typedef void lttng_ust_ze_properties_memory_info_properties_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, void *, size_t, ze_memory_allocation_properties_t *, ze_device_handle_t);

void btx_register_callbacks_lttng_ust_ze_properties_memory_info_properties(
    void *btx_handle, lttng_ust_ze_properties_memory_info_properties_callback_f *callback);

typedef void lttng_ust_ze_properties_memory_info_range_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_handle_t, void *, void *, size_t);

void btx_register_callbacks_lttng_ust_ze_properties_memory_info_range(
    void *btx_handle, lttng_ust_ze_properties_memory_info_range_callback_f *callback);

typedef void lttng_ust_ze_properties_kernel_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_kernel_handle_t, size_t, ze_kernel_properties_t *);

void btx_register_callbacks_lttng_ust_ze_properties_kernel(
    void *btx_handle, lttng_ust_ze_properties_kernel_callback_f *callback);

typedef void lttng_ust_ze_build_log_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *);

void btx_register_callbacks_lttng_ust_ze_build_log(
    void *btx_handle, lttng_ust_ze_build_log_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_init_driver_type_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_init_driver_type_desc_t *, size_t, ze_init_driver_type_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_init_driver_type_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_init_driver_type_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_driver_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_driver_properties_t *, size_t, ze_driver_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_driver_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_driver_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_driver_ipc_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_driver_ipc_properties_t *, size_t, ze_driver_ipc_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_driver_ipc_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_driver_ipc_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_device_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_properties_t *, size_t, ze_device_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_device_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_device_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_device_compute_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_compute_properties_t *, size_t, ze_device_compute_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_device_compute_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_device_compute_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_device_module_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_module_properties_t *, size_t, ze_device_module_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_device_module_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_device_module_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_command_queue_group_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_queue_group_properties_t *, size_t, ze_command_queue_group_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_command_queue_group_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_command_queue_group_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_device_memory_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_memory_properties_t *, size_t, ze_device_memory_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_device_memory_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_device_memory_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_device_memory_access_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_memory_access_properties_t *, size_t, ze_device_memory_access_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_device_memory_access_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_device_memory_access_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_device_cache_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_cache_properties_t *, size_t, ze_device_cache_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_device_cache_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_device_cache_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_device_image_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_image_properties_t *, size_t, ze_device_image_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_device_image_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_device_image_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_device_external_memory_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_external_memory_properties_t *, size_t, ze_device_external_memory_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_device_external_memory_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_device_external_memory_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_device_p2p_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_p2p_properties_t *, size_t, ze_device_p2p_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_device_p2p_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_device_p2p_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_context_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_desc_t *, size_t, ze_context_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_context_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_context_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_command_queue_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_queue_desc_t *, size_t, ze_command_queue_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_command_queue_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_command_queue_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_command_list_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_command_list_desc_t *, size_t, ze_command_list_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_command_list_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_command_list_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_event_pool_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_event_pool_desc_t *, size_t, ze_event_pool_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_event_pool_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_event_pool_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_event_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_event_desc_t *, size_t, ze_event_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_event_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_event_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_fence_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_fence_desc_t *, size_t, ze_fence_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_fence_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_fence_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_image_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_image_desc_t *, size_t, ze_image_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_image_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_image_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_image_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_image_properties_t *, size_t, ze_image_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_image_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_image_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_device_mem_alloc_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_mem_alloc_desc_t *, size_t, ze_device_mem_alloc_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_device_mem_alloc_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_device_mem_alloc_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_host_mem_alloc_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_host_mem_alloc_desc_t *, size_t, ze_host_mem_alloc_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_host_mem_alloc_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_host_mem_alloc_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_memory_allocation_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_memory_allocation_properties_t *, size_t, ze_memory_allocation_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_memory_allocation_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_memory_allocation_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_external_memory_export_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_external_memory_export_desc_t *, size_t, ze_external_memory_export_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_external_memory_export_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_external_memory_export_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_external_memory_import_fd_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_external_memory_import_fd_t *, size_t, ze_external_memory_import_fd_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_external_memory_import_fd_t(
    void *btx_handle, lttng_ust_ze_structs_ze_external_memory_import_fd_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_external_memory_export_fd_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_external_memory_export_fd_t *, size_t, ze_external_memory_export_fd_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_external_memory_export_fd_t(
    void *btx_handle, lttng_ust_ze_structs_ze_external_memory_export_fd_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_external_memory_import_win32_handle_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_external_memory_import_win32_handle_t *, size_t, ze_external_memory_import_win32_handle_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_external_memory_import_win32_handle_t(
    void *btx_handle, lttng_ust_ze_structs_ze_external_memory_import_win32_handle_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_external_memory_export_win32_handle_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_external_memory_export_win32_handle_t *, size_t, ze_external_memory_export_win32_handle_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_external_memory_export_win32_handle_t(
    void *btx_handle, lttng_ust_ze_structs_ze_external_memory_export_win32_handle_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_module_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_module_desc_t *, size_t, ze_module_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_module_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_module_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_module_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_module_properties_t *, size_t, ze_module_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_module_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_module_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_kernel_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_kernel_desc_t *, size_t, ze_kernel_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_kernel_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_kernel_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_kernel_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_kernel_properties_t *, size_t, ze_kernel_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_kernel_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_kernel_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_kernel_preferred_group_size_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_kernel_preferred_group_size_properties_t *, size_t, ze_kernel_preferred_group_size_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_kernel_preferred_group_size_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_kernel_preferred_group_size_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_module_program_exp_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_module_program_exp_desc_t *, size_t, ze_module_program_exp_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_module_program_exp_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_module_program_exp_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_device_raytracing_ext_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_raytracing_ext_properties_t *, size_t, ze_device_raytracing_ext_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_device_raytracing_ext_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_device_raytracing_ext_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_raytracing_mem_alloc_ext_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_raytracing_mem_alloc_ext_desc_t *, size_t, ze_raytracing_mem_alloc_ext_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_raytracing_mem_alloc_ext_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_raytracing_mem_alloc_ext_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_sampler_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_sampler_desc_t *, size_t, ze_sampler_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_sampler_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_sampler_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_physical_mem_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_physical_mem_desc_t *, size_t, ze_physical_mem_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_physical_mem_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_physical_mem_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_float_atomic_ext_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_float_atomic_ext_properties_t *, size_t, ze_float_atomic_ext_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_float_atomic_ext_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_float_atomic_ext_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_relaxed_allocation_limits_exp_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_relaxed_allocation_limits_exp_desc_t *, size_t, ze_relaxed_allocation_limits_exp_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_relaxed_allocation_limits_exp_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_relaxed_allocation_limits_exp_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_driver_ddi_handles_ext_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_driver_ddi_handles_ext_properties_t *, size_t, ze_driver_ddi_handles_ext_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_driver_ddi_handles_ext_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_driver_ddi_handles_ext_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_external_semaphore_ext_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_external_semaphore_ext_desc_t *, size_t, ze_external_semaphore_ext_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_external_semaphore_ext_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_external_semaphore_ext_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_external_semaphore_win32_ext_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_external_semaphore_win32_ext_desc_t *, size_t, ze_external_semaphore_win32_ext_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_external_semaphore_win32_ext_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_external_semaphore_win32_ext_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_external_semaphore_fd_ext_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_external_semaphore_fd_ext_desc_t *, size_t, ze_external_semaphore_fd_ext_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_external_semaphore_fd_ext_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_external_semaphore_fd_ext_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_external_semaphore_signal_params_ext_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_external_semaphore_signal_params_ext_t *, size_t, ze_external_semaphore_signal_params_ext_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_external_semaphore_signal_params_ext_t(
    void *btx_handle, lttng_ust_ze_structs_ze_external_semaphore_signal_params_ext_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_external_semaphore_wait_params_ext_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_external_semaphore_wait_params_ext_t *, size_t, ze_external_semaphore_wait_params_ext_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_external_semaphore_wait_params_ext_t(
    void *btx_handle, lttng_ust_ze_structs_ze_external_semaphore_wait_params_ext_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_device_cache_line_size_ext_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_cache_line_size_ext_t *, size_t, ze_device_cache_line_size_ext_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_device_cache_line_size_ext_t(
    void *btx_handle, lttng_ust_ze_structs_ze_device_cache_line_size_ext_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_rtas_builder_ext_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_rtas_builder_ext_desc_t *, size_t, ze_rtas_builder_ext_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_rtas_builder_ext_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_rtas_builder_ext_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_rtas_builder_ext_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_rtas_builder_ext_properties_t *, size_t, ze_rtas_builder_ext_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_rtas_builder_ext_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_rtas_builder_ext_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_rtas_parallel_operation_ext_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_rtas_parallel_operation_ext_properties_t *, size_t, ze_rtas_parallel_operation_ext_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_rtas_parallel_operation_ext_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_rtas_parallel_operation_ext_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_rtas_device_ext_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_rtas_device_ext_properties_t *, size_t, ze_rtas_device_ext_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_rtas_device_ext_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_rtas_device_ext_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_rtas_geometry_aabbs_ext_cb_params_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_rtas_geometry_aabbs_ext_cb_params_t *, size_t, ze_rtas_geometry_aabbs_ext_cb_params_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_rtas_geometry_aabbs_ext_cb_params_t(
    void *btx_handle, lttng_ust_ze_structs_ze_rtas_geometry_aabbs_ext_cb_params_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_rtas_builder_build_op_ext_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_rtas_builder_build_op_ext_desc_t *, size_t, ze_rtas_builder_build_op_ext_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_rtas_builder_build_op_ext_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_rtas_builder_build_op_ext_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_device_vector_width_properties_ext_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_vector_width_properties_ext_t *, size_t, ze_device_vector_width_properties_ext_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_device_vector_width_properties_ext_t(
    void *btx_handle, lttng_ust_ze_structs_ze_device_vector_width_properties_ext_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_cache_reservation_ext_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_cache_reservation_ext_desc_t *, size_t, ze_cache_reservation_ext_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_cache_reservation_ext_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_cache_reservation_ext_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_image_memory_properties_exp_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_image_memory_properties_exp_t *, size_t, ze_image_memory_properties_exp_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_image_memory_properties_exp_t(
    void *btx_handle, lttng_ust_ze_structs_ze_image_memory_properties_exp_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_image_view_planar_ext_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_image_view_planar_ext_desc_t *, size_t, ze_image_view_planar_ext_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_image_view_planar_ext_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_image_view_planar_ext_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_image_view_planar_exp_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_image_view_planar_exp_desc_t *, size_t, ze_image_view_planar_exp_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_image_view_planar_exp_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_image_view_planar_exp_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_scheduling_hint_exp_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_scheduling_hint_exp_properties_t *, size_t, ze_scheduling_hint_exp_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_scheduling_hint_exp_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_scheduling_hint_exp_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_scheduling_hint_exp_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_scheduling_hint_exp_desc_t *, size_t, ze_scheduling_hint_exp_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_scheduling_hint_exp_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_scheduling_hint_exp_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_context_power_saving_hint_exp_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_context_power_saving_hint_exp_desc_t *, size_t, ze_context_power_saving_hint_exp_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_context_power_saving_hint_exp_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_context_power_saving_hint_exp_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_eu_count_ext_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_eu_count_ext_t *, size_t, ze_eu_count_ext_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_eu_count_ext_t(
    void *btx_handle, lttng_ust_ze_structs_ze_eu_count_ext_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_pci_ext_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_pci_ext_properties_t *, size_t, ze_pci_ext_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_pci_ext_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_pci_ext_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_srgb_ext_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_srgb_ext_desc_t *, size_t, ze_srgb_ext_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_srgb_ext_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_srgb_ext_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_image_allocation_ext_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_image_allocation_ext_properties_t *, size_t, ze_image_allocation_ext_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_image_allocation_ext_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_image_allocation_ext_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_linkage_inspection_ext_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_linkage_inspection_ext_desc_t *, size_t, ze_linkage_inspection_ext_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_linkage_inspection_ext_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_linkage_inspection_ext_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_memory_compression_hints_ext_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_memory_compression_hints_ext_desc_t *, size_t, ze_memory_compression_hints_ext_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_memory_compression_hints_ext_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_memory_compression_hints_ext_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_driver_memory_free_ext_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_driver_memory_free_ext_properties_t *, size_t, ze_driver_memory_free_ext_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_driver_memory_free_ext_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_driver_memory_free_ext_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_memory_free_ext_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_memory_free_ext_desc_t *, size_t, ze_memory_free_ext_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_memory_free_ext_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_memory_free_ext_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_device_p2p_bandwidth_exp_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_p2p_bandwidth_exp_properties_t *, size_t, ze_device_p2p_bandwidth_exp_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_device_p2p_bandwidth_exp_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_device_p2p_bandwidth_exp_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_copy_bandwidth_exp_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_copy_bandwidth_exp_properties_t *, size_t, ze_copy_bandwidth_exp_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_copy_bandwidth_exp_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_copy_bandwidth_exp_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_device_luid_ext_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_luid_ext_properties_t *, size_t, ze_device_luid_ext_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_device_luid_ext_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_device_luid_ext_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_fabric_vertex_exp_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_fabric_vertex_exp_properties_t *, size_t, ze_fabric_vertex_exp_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_fabric_vertex_exp_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_fabric_vertex_exp_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_fabric_edge_exp_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_fabric_edge_exp_properties_t *, size_t, ze_fabric_edge_exp_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_fabric_edge_exp_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_fabric_edge_exp_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_device_memory_ext_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_memory_ext_properties_t *, size_t, ze_device_memory_ext_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_device_memory_ext_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_device_memory_ext_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_device_ip_version_ext_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_ip_version_ext_t *, size_t, ze_device_ip_version_ext_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_device_ip_version_ext_t(
    void *btx_handle, lttng_ust_ze_structs_ze_device_ip_version_ext_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_kernel_max_group_size_properties_ext_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_kernel_max_group_size_properties_ext_t *, size_t, ze_kernel_max_group_size_properties_ext_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_kernel_max_group_size_properties_ext_t(
    void *btx_handle, lttng_ust_ze_structs_ze_kernel_max_group_size_properties_ext_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_memory_sub_allocations_exp_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_memory_sub_allocations_exp_properties_t *, size_t, ze_memory_sub_allocations_exp_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_memory_sub_allocations_exp_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_memory_sub_allocations_exp_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_event_query_kernel_timestamps_ext_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_event_query_kernel_timestamps_ext_properties_t *, size_t, ze_event_query_kernel_timestamps_ext_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_event_query_kernel_timestamps_ext_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_event_query_kernel_timestamps_ext_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_event_query_kernel_timestamps_results_ext_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_event_query_kernel_timestamps_results_ext_properties_t *, size_t, ze_event_query_kernel_timestamps_results_ext_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_event_query_kernel_timestamps_results_ext_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_event_query_kernel_timestamps_results_ext_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_rtas_builder_exp_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_rtas_builder_exp_desc_t *, size_t, ze_rtas_builder_exp_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_rtas_builder_exp_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_rtas_builder_exp_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_rtas_builder_exp_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_rtas_builder_exp_properties_t *, size_t, ze_rtas_builder_exp_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_rtas_builder_exp_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_rtas_builder_exp_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_rtas_parallel_operation_exp_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_rtas_parallel_operation_exp_properties_t *, size_t, ze_rtas_parallel_operation_exp_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_rtas_parallel_operation_exp_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_rtas_parallel_operation_exp_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_rtas_device_exp_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_rtas_device_exp_properties_t *, size_t, ze_rtas_device_exp_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_rtas_device_exp_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_rtas_device_exp_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_rtas_geometry_aabbs_exp_cb_params_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_rtas_geometry_aabbs_exp_cb_params_t *, size_t, ze_rtas_geometry_aabbs_exp_cb_params_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_rtas_geometry_aabbs_exp_cb_params_t(
    void *btx_handle, lttng_ust_ze_structs_ze_rtas_geometry_aabbs_exp_cb_params_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_rtas_builder_build_op_exp_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_rtas_builder_build_op_exp_desc_t *, size_t, ze_rtas_builder_build_op_exp_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_rtas_builder_build_op_exp_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_rtas_builder_build_op_exp_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_event_pool_counter_based_exp_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_event_pool_counter_based_exp_desc_t *, size_t, ze_event_pool_counter_based_exp_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_event_pool_counter_based_exp_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_event_pool_counter_based_exp_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_image_bindless_exp_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_image_bindless_exp_desc_t *, size_t, ze_image_bindless_exp_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_image_bindless_exp_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_image_bindless_exp_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_image_pitched_exp_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_image_pitched_exp_desc_t *, size_t, ze_image_pitched_exp_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_image_pitched_exp_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_image_pitched_exp_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_device_pitched_alloc_exp_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_device_pitched_alloc_exp_properties_t *, size_t, ze_device_pitched_alloc_exp_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_device_pitched_alloc_exp_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_device_pitched_alloc_exp_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_mutable_command_id_exp_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_mutable_command_id_exp_desc_t *, size_t, ze_mutable_command_id_exp_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_mutable_command_id_exp_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_mutable_command_id_exp_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_mutable_command_list_exp_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_mutable_command_list_exp_properties_t *, size_t, ze_mutable_command_list_exp_properties_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_mutable_command_list_exp_properties_t(
    void *btx_handle, lttng_ust_ze_structs_ze_mutable_command_list_exp_properties_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_mutable_command_list_exp_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_mutable_command_list_exp_desc_t *, size_t, ze_mutable_command_list_exp_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_mutable_command_list_exp_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_mutable_command_list_exp_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_mutable_commands_exp_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_mutable_commands_exp_desc_t *, size_t, ze_mutable_commands_exp_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_mutable_commands_exp_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_mutable_commands_exp_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_mutable_kernel_argument_exp_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_mutable_kernel_argument_exp_desc_t *, size_t, ze_mutable_kernel_argument_exp_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_mutable_kernel_argument_exp_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_mutable_kernel_argument_exp_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_mutable_group_count_exp_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_mutable_group_count_exp_desc_t *, size_t, ze_mutable_group_count_exp_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_mutable_group_count_exp_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_mutable_group_count_exp_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_mutable_group_size_exp_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_mutable_group_size_exp_desc_t *, size_t, ze_mutable_group_size_exp_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_mutable_group_size_exp_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_mutable_group_size_exp_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_mutable_global_offset_exp_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_mutable_global_offset_exp_desc_t *, size_t, ze_mutable_global_offset_exp_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_mutable_global_offset_exp_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_mutable_global_offset_exp_desc_t_callback_f *callback);

typedef void lttng_ust_ze_structs_ze_mutable_graph_argument_exp_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ze_mutable_graph_argument_exp_desc_t *, size_t, ze_mutable_graph_argument_exp_desc_t *);

void btx_register_callbacks_lttng_ust_ze_structs_ze_mutable_graph_argument_exp_desc_t(
    void *btx_handle, lttng_ust_ze_structs_ze_mutable_graph_argument_exp_desc_t_callback_f *callback);

typedef void lttng_ust_zet_structs_zet_device_debug_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_device_debug_properties_t *, size_t, zet_device_debug_properties_t *);

void btx_register_callbacks_lttng_ust_zet_structs_zet_device_debug_properties_t(
    void *btx_handle, lttng_ust_zet_structs_zet_device_debug_properties_t_callback_f *callback);

typedef void lttng_ust_zet_structs_zet_debug_memory_space_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_debug_memory_space_desc_t *, size_t, zet_debug_memory_space_desc_t *);

void btx_register_callbacks_lttng_ust_zet_structs_zet_debug_memory_space_desc_t(
    void *btx_handle, lttng_ust_zet_structs_zet_debug_memory_space_desc_t_callback_f *callback);

typedef void lttng_ust_zet_structs_zet_debug_regset_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_debug_regset_properties_t *, size_t, zet_debug_regset_properties_t *);

void btx_register_callbacks_lttng_ust_zet_structs_zet_debug_regset_properties_t(
    void *btx_handle, lttng_ust_zet_structs_zet_debug_regset_properties_t_callback_f *callback);

typedef void lttng_ust_zet_structs_zet_metric_group_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_group_properties_t *, size_t, zet_metric_group_properties_t *);

void btx_register_callbacks_lttng_ust_zet_structs_zet_metric_group_properties_t(
    void *btx_handle, lttng_ust_zet_structs_zet_metric_group_properties_t_callback_f *callback);

typedef void lttng_ust_zet_structs_zet_metric_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_properties_t *, size_t, zet_metric_properties_t *);

void btx_register_callbacks_lttng_ust_zet_structs_zet_metric_properties_t(
    void *btx_handle, lttng_ust_zet_structs_zet_metric_properties_t_callback_f *callback);

typedef void lttng_ust_zet_structs_zet_metric_streamer_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_streamer_desc_t *, size_t, zet_metric_streamer_desc_t *);

void btx_register_callbacks_lttng_ust_zet_structs_zet_metric_streamer_desc_t(
    void *btx_handle, lttng_ust_zet_structs_zet_metric_streamer_desc_t_callback_f *callback);

typedef void lttng_ust_zet_structs_zet_metric_query_pool_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_query_pool_desc_t *, size_t, zet_metric_query_pool_desc_t *);

void btx_register_callbacks_lttng_ust_zet_structs_zet_metric_query_pool_desc_t(
    void *btx_handle, lttng_ust_zet_structs_zet_metric_query_pool_desc_t_callback_f *callback);

typedef void lttng_ust_zet_structs_zet_profile_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_profile_properties_t *, size_t, zet_profile_properties_t *);

void btx_register_callbacks_lttng_ust_zet_structs_zet_profile_properties_t(
    void *btx_handle, lttng_ust_zet_structs_zet_profile_properties_t_callback_f *callback);

typedef void lttng_ust_zet_structs_zet_tracer_exp_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_tracer_exp_desc_t *, size_t, zet_tracer_exp_desc_t *);

void btx_register_callbacks_lttng_ust_zet_structs_zet_tracer_exp_desc_t(
    void *btx_handle, lttng_ust_zet_structs_zet_tracer_exp_desc_t_callback_f *callback);

typedef void lttng_ust_zet_structs_zet_metric_tracer_exp_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_tracer_exp_desc_t *, size_t, zet_metric_tracer_exp_desc_t *);

void btx_register_callbacks_lttng_ust_zet_structs_zet_metric_tracer_exp_desc_t(
    void *btx_handle, lttng_ust_zet_structs_zet_metric_tracer_exp_desc_t_callback_f *callback);

typedef void lttng_ust_zet_structs_zet_metric_group_type_exp_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_group_type_exp_t *, size_t, zet_metric_group_type_exp_t *);

void btx_register_callbacks_lttng_ust_zet_structs_zet_metric_group_type_exp_t(
    void *btx_handle, lttng_ust_zet_structs_zet_metric_group_type_exp_t_callback_f *callback);

typedef void lttng_ust_zet_structs_zet_export_dma_buf_exp_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_export_dma_buf_exp_properties_t *, size_t, zet_export_dma_buf_exp_properties_t *);

void btx_register_callbacks_lttng_ust_zet_structs_zet_export_dma_buf_exp_properties_t(
    void *btx_handle, lttng_ust_zet_structs_zet_export_dma_buf_exp_properties_t_callback_f *callback);

typedef void lttng_ust_zet_structs_zet_metric_global_timestamps_resolution_exp_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_global_timestamps_resolution_exp_t *, size_t, zet_metric_global_timestamps_resolution_exp_t *);

void btx_register_callbacks_lttng_ust_zet_structs_zet_metric_global_timestamps_resolution_exp_t(
    void *btx_handle, lttng_ust_zet_structs_zet_metric_global_timestamps_resolution_exp_t_callback_f *callback);

typedef void lttng_ust_zet_structs_zet_metric_calculate_exp_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_calculate_exp_desc_t *, size_t, zet_metric_calculate_exp_desc_t *);

void btx_register_callbacks_lttng_ust_zet_structs_zet_metric_calculate_exp_desc_t(
    void *btx_handle, lttng_ust_zet_structs_zet_metric_calculate_exp_desc_t_callback_f *callback);

typedef void lttng_ust_zet_structs_zet_metric_programmable_exp_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_programmable_exp_properties_t *, size_t, zet_metric_programmable_exp_properties_t *);

void btx_register_callbacks_lttng_ust_zet_structs_zet_metric_programmable_exp_properties_t(
    void *btx_handle, lttng_ust_zet_structs_zet_metric_programmable_exp_properties_t_callback_f *callback);

typedef void lttng_ust_zet_structs_zet_metric_programmable_param_info_exp_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_programmable_param_info_exp_t *, size_t, zet_metric_programmable_param_info_exp_t *);

void btx_register_callbacks_lttng_ust_zet_structs_zet_metric_programmable_param_info_exp_t(
    void *btx_handle, lttng_ust_zet_structs_zet_metric_programmable_param_info_exp_t_callback_f *callback);

typedef void lttng_ust_zet_structs_zet_metric_programmable_param_value_info_exp_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zet_metric_programmable_param_value_info_exp_t *, size_t, zet_metric_programmable_param_value_info_exp_t *);

void btx_register_callbacks_lttng_ust_zet_structs_zet_metric_programmable_param_value_info_exp_t(
    void *btx_handle, lttng_ust_zet_structs_zet_metric_programmable_param_value_info_exp_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_base_state_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_base_state_t *, size_t, zes_base_state_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_base_state_t(
    void *btx_handle, lttng_ust_zes_structs_zes_base_state_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_device_state_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_state_t *, size_t, zes_device_state_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_device_state_t(
    void *btx_handle, lttng_ust_zes_structs_zes_device_state_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_reset_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_reset_properties_t *, size_t, zes_reset_properties_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_reset_properties_t(
    void *btx_handle, lttng_ust_zes_structs_zes_reset_properties_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_device_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_properties_t *, size_t, zes_device_properties_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_device_properties_t(
    void *btx_handle, lttng_ust_zes_structs_zes_device_properties_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_device_ext_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_ext_properties_t *, size_t, zes_device_ext_properties_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_device_ext_properties_t(
    void *btx_handle, lttng_ust_zes_structs_zes_device_ext_properties_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_process_state_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_process_state_t *, size_t, zes_process_state_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_process_state_t(
    void *btx_handle, lttng_ust_zes_structs_zes_process_state_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_pci_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_pci_properties_t *, size_t, zes_pci_properties_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_pci_properties_t(
    void *btx_handle, lttng_ust_zes_structs_zes_pci_properties_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_pci_state_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_pci_state_t *, size_t, zes_pci_state_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_pci_state_t(
    void *btx_handle, lttng_ust_zes_structs_zes_pci_state_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_pci_bar_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_pci_bar_properties_t *, size_t, zes_pci_bar_properties_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_pci_bar_properties_t(
    void *btx_handle, lttng_ust_zes_structs_zes_pci_bar_properties_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_pci_bar_properties_1_2_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_pci_bar_properties_1_2_t *, size_t, zes_pci_bar_properties_1_2_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_pci_bar_properties_1_2_t(
    void *btx_handle, lttng_ust_zes_structs_zes_pci_bar_properties_1_2_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_overclock_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_overclock_properties_t *, size_t, zes_overclock_properties_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_overclock_properties_t(
    void *btx_handle, lttng_ust_zes_structs_zes_overclock_properties_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_diag_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_diag_properties_t *, size_t, zes_diag_properties_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_diag_properties_t(
    void *btx_handle, lttng_ust_zes_structs_zes_diag_properties_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_device_ecc_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_ecc_desc_t *, size_t, zes_device_ecc_desc_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_device_ecc_desc_t(
    void *btx_handle, lttng_ust_zes_structs_zes_device_ecc_desc_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_device_ecc_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_ecc_properties_t *, size_t, zes_device_ecc_properties_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_device_ecc_properties_t(
    void *btx_handle, lttng_ust_zes_structs_zes_device_ecc_properties_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_engine_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_engine_properties_t *, size_t, zes_engine_properties_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_engine_properties_t(
    void *btx_handle, lttng_ust_zes_structs_zes_engine_properties_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_fabric_port_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_fabric_port_properties_t *, size_t, zes_fabric_port_properties_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_fabric_port_properties_t(
    void *btx_handle, lttng_ust_zes_structs_zes_fabric_port_properties_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_fabric_port_config_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_fabric_port_config_t *, size_t, zes_fabric_port_config_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_fabric_port_config_t(
    void *btx_handle, lttng_ust_zes_structs_zes_fabric_port_config_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_fabric_port_state_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_fabric_port_state_t *, size_t, zes_fabric_port_state_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_fabric_port_state_t(
    void *btx_handle, lttng_ust_zes_structs_zes_fabric_port_state_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_fabric_port_error_counters_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_fabric_port_error_counters_t *, size_t, zes_fabric_port_error_counters_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_fabric_port_error_counters_t(
    void *btx_handle, lttng_ust_zes_structs_zes_fabric_port_error_counters_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_fan_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_fan_properties_t *, size_t, zes_fan_properties_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_fan_properties_t(
    void *btx_handle, lttng_ust_zes_structs_zes_fan_properties_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_fan_config_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_fan_config_t *, size_t, zes_fan_config_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_fan_config_t(
    void *btx_handle, lttng_ust_zes_structs_zes_fan_config_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_firmware_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_firmware_properties_t *, size_t, zes_firmware_properties_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_firmware_properties_t(
    void *btx_handle, lttng_ust_zes_structs_zes_firmware_properties_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_freq_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_freq_properties_t *, size_t, zes_freq_properties_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_freq_properties_t(
    void *btx_handle, lttng_ust_zes_structs_zes_freq_properties_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_freq_state_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_freq_state_t *, size_t, zes_freq_state_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_freq_state_t(
    void *btx_handle, lttng_ust_zes_structs_zes_freq_state_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_oc_capabilities_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_oc_capabilities_t *, size_t, zes_oc_capabilities_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_oc_capabilities_t(
    void *btx_handle, lttng_ust_zes_structs_zes_oc_capabilities_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_led_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_led_properties_t *, size_t, zes_led_properties_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_led_properties_t(
    void *btx_handle, lttng_ust_zes_structs_zes_led_properties_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_led_state_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_led_state_t *, size_t, zes_led_state_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_led_state_t(
    void *btx_handle, lttng_ust_zes_structs_zes_led_state_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_mem_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_mem_properties_t *, size_t, zes_mem_properties_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_mem_properties_t(
    void *btx_handle, lttng_ust_zes_structs_zes_mem_properties_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_mem_state_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_mem_state_t *, size_t, zes_mem_state_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_mem_state_t(
    void *btx_handle, lttng_ust_zes_structs_zes_mem_state_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_perf_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_perf_properties_t *, size_t, zes_perf_properties_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_perf_properties_t(
    void *btx_handle, lttng_ust_zes_structs_zes_perf_properties_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_power_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_power_properties_t *, size_t, zes_power_properties_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_power_properties_t(
    void *btx_handle, lttng_ust_zes_structs_zes_power_properties_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_psu_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_psu_properties_t *, size_t, zes_psu_properties_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_psu_properties_t(
    void *btx_handle, lttng_ust_zes_structs_zes_psu_properties_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_psu_state_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_psu_state_t *, size_t, zes_psu_state_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_psu_state_t(
    void *btx_handle, lttng_ust_zes_structs_zes_psu_state_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_ras_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_ras_properties_t *, size_t, zes_ras_properties_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_ras_properties_t(
    void *btx_handle, lttng_ust_zes_structs_zes_ras_properties_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_ras_state_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_ras_state_t *, size_t, zes_ras_state_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_ras_state_t(
    void *btx_handle, lttng_ust_zes_structs_zes_ras_state_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_ras_config_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_ras_config_t *, size_t, zes_ras_config_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_ras_config_t(
    void *btx_handle, lttng_ust_zes_structs_zes_ras_config_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_sched_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_sched_properties_t *, size_t, zes_sched_properties_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_sched_properties_t(
    void *btx_handle, lttng_ust_zes_structs_zes_sched_properties_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_sched_timeout_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_sched_timeout_properties_t *, size_t, zes_sched_timeout_properties_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_sched_timeout_properties_t(
    void *btx_handle, lttng_ust_zes_structs_zes_sched_timeout_properties_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_sched_timeslice_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_sched_timeslice_properties_t *, size_t, zes_sched_timeslice_properties_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_sched_timeslice_properties_t(
    void *btx_handle, lttng_ust_zes_structs_zes_sched_timeslice_properties_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_standby_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_standby_properties_t *, size_t, zes_standby_properties_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_standby_properties_t(
    void *btx_handle, lttng_ust_zes_structs_zes_standby_properties_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_temp_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_temp_properties_t *, size_t, zes_temp_properties_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_temp_properties_t(
    void *btx_handle, lttng_ust_zes_structs_zes_temp_properties_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_temp_config_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_temp_config_t *, size_t, zes_temp_config_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_temp_config_t(
    void *btx_handle, lttng_ust_zes_structs_zes_temp_config_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_device_ecc_default_properties_ext_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_device_ecc_default_properties_ext_t *, size_t, zes_device_ecc_default_properties_ext_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_device_ecc_default_properties_ext_t(
    void *btx_handle, lttng_ust_zes_structs_zes_device_ecc_default_properties_ext_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_power_limit_ext_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_power_limit_ext_desc_t *, size_t, zes_power_limit_ext_desc_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_power_limit_ext_desc_t(
    void *btx_handle, lttng_ust_zes_structs_zes_power_limit_ext_desc_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_power_ext_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_power_ext_properties_t *, size_t, zes_power_ext_properties_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_power_ext_properties_t(
    void *btx_handle, lttng_ust_zes_structs_zes_power_ext_properties_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_engine_ext_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_engine_ext_properties_t *, size_t, zes_engine_ext_properties_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_engine_ext_properties_t(
    void *btx_handle, lttng_ust_zes_structs_zes_engine_ext_properties_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_mem_page_offline_state_exp_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_mem_page_offline_state_exp_t *, size_t, zes_mem_page_offline_state_exp_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_mem_page_offline_state_exp_t(
    void *btx_handle, lttng_ust_zes_structs_zes_mem_page_offline_state_exp_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_mem_bandwidth_counter_bits_exp_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_mem_bandwidth_counter_bits_exp_properties_t *, size_t, zes_mem_bandwidth_counter_bits_exp_properties_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_mem_bandwidth_counter_bits_exp_properties_t(
    void *btx_handle, lttng_ust_zes_structs_zes_mem_bandwidth_counter_bits_exp_properties_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_power_domain_exp_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_power_domain_exp_properties_t *, size_t, zes_power_domain_exp_properties_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_power_domain_exp_properties_t(
    void *btx_handle, lttng_ust_zes_structs_zes_power_domain_exp_properties_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_subdevice_exp_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_subdevice_exp_properties_t *, size_t, zes_subdevice_exp_properties_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_subdevice_exp_properties_t(
    void *btx_handle, lttng_ust_zes_structs_zes_subdevice_exp_properties_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_vf_exp_properties_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_vf_exp_properties_t *, size_t, zes_vf_exp_properties_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_vf_exp_properties_t(
    void *btx_handle, lttng_ust_zes_structs_zes_vf_exp_properties_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_vf_util_mem_exp_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_vf_util_mem_exp_t *, size_t, zes_vf_util_mem_exp_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_vf_util_mem_exp_t(
    void *btx_handle, lttng_ust_zes_structs_zes_vf_util_mem_exp_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_vf_util_engine_exp_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_vf_util_engine_exp_t *, size_t, zes_vf_util_engine_exp_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_vf_util_engine_exp_t(
    void *btx_handle, lttng_ust_zes_structs_zes_vf_util_engine_exp_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_vf_exp_capabilities_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_vf_exp_capabilities_t *, size_t, zes_vf_exp_capabilities_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_vf_exp_capabilities_t(
    void *btx_handle, lttng_ust_zes_structs_zes_vf_exp_capabilities_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_vf_exp2_capabilities_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_vf_exp2_capabilities_t *, size_t, zes_vf_exp2_capabilities_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_vf_exp2_capabilities_t(
    void *btx_handle, lttng_ust_zes_structs_zes_vf_exp2_capabilities_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_vf_util_mem_exp2_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_vf_util_mem_exp2_t *, size_t, zes_vf_util_mem_exp2_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_vf_util_mem_exp2_t(
    void *btx_handle, lttng_ust_zes_structs_zes_vf_util_mem_exp2_t_callback_f *callback);

typedef void lttng_ust_zes_structs_zes_vf_util_engine_exp2_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zes_vf_util_engine_exp2_t *, size_t, zes_vf_util_engine_exp2_t *);

void btx_register_callbacks_lttng_ust_zes_structs_zes_vf_util_engine_exp2_t(
    void *btx_handle, lttng_ust_zes_structs_zes_vf_util_engine_exp2_t_callback_f *callback);

typedef void lttng_ust_zel_structs_zel_tracer_desc_t_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, zel_tracer_desc_t *, size_t, zel_tracer_desc_t *);

void btx_register_callbacks_lttng_ust_zel_structs_zel_tracer_desc_t(
    void *btx_handle, lttng_ust_zel_structs_zel_tracer_desc_t_callback_f *callback);

typedef void entries_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t);

void btx_register_callbacks_entries(
    void *btx_handle, entries_callback_f *callback);

typedef void exits_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_exits(
    void *btx_handle, exits_callback_f *callback);

typedef void command_list_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, ze_device_handle_t);

void btx_register_callbacks_command_list_entry(
    void *btx_handle, command_list_entry_callback_f *callback);

typedef void command_list_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, ze_command_list_handle_t);

void btx_register_callbacks_command_list_exit(
    void *btx_handle, command_list_exit_callback_f *callback);

typedef void zeKernelCreate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, char *);

void btx_register_callbacks_zeKernelCreate_entry(
    void *btx_handle, zeKernelCreate_entry_callback_f *callback);

typedef void zeKernelCreate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, ze_kernel_handle_t);

void btx_register_callbacks_zeKernelCreate_exit(
    void *btx_handle, zeKernelCreate_exit_callback_f *callback);

typedef void zeKernelGetName_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, ze_kernel_handle_t, size_t);

void btx_register_callbacks_zeKernelGetName_entry(
    void *btx_handle, zeKernelGetName_entry_callback_f *callback);

typedef void zeKernelGetName_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, size_t, char *);

void btx_register_callbacks_zeKernelGetName_exit(
    void *btx_handle, zeKernelGetName_exit_callback_f *callback);

typedef void entries_alloc_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, size_t);

void btx_register_callbacks_entries_alloc(
    void *btx_handle, entries_alloc_callback_f *callback);

typedef void exits_alloc_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, ze_result_t, void *);

void btx_register_callbacks_exits_alloc(
    void *btx_handle, exits_alloc_callback_f *callback);

typedef void zeModule_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, ze_module_handle_t);

void btx_register_callbacks_zeModule_entry(
    void *btx_handle, zeModule_entry_callback_f *callback);

typedef void hSignalEvent_hKernel_with_group_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, ze_command_list_handle_t, ze_kernel_handle_t, ze_group_count_t *);

void btx_register_callbacks_hSignalEvent_hKernel_with_group_entry(
    void *btx_handle, hSignalEvent_hKernel_with_group_entry_callback_f *callback);

typedef void hSignalEvent_hKernel_without_group_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, ze_command_list_handle_t, ze_kernel_handle_t);

void btx_register_callbacks_hSignalEvent_hKernel_without_group_entry(
    void *btx_handle, hSignalEvent_hKernel_without_group_entry_callback_f *callback);

typedef void hSignalEvent_eventMemory_2ptr_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, ze_command_list_handle_t, void *, void *, size_t);

void btx_register_callbacks_hSignalEvent_eventMemory_2ptr_entry(
    void *btx_handle, hSignalEvent_eventMemory_2ptr_entry_callback_f *callback);

typedef void hSignalEvent_eventMemory_1ptr_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, ze_command_list_handle_t, void *, size_t);

void btx_register_callbacks_hSignalEvent_eventMemory_1ptr_entry(
    void *btx_handle, hSignalEvent_eventMemory_1ptr_entry_callback_f *callback);

typedef void hSignalEvent_eventMemory_region_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, ze_command_list_handle_t, void *, void *, ze_copy_region_t *);

void btx_register_callbacks_hSignalEvent_eventMemory_region_entry(
    void *btx_handle, hSignalEvent_eventMemory_region_entry_callback_f *callback);

typedef void eventMemory_without_hSignalEvent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, size_t);

void btx_register_callbacks_eventMemory_without_hSignalEvent_entry(
    void *btx_handle, eventMemory_without_hSignalEvent_entry_callback_f *callback);

typedef void eventMemory_without_hSignalEvent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_eventMemory_without_hSignalEvent_exit(
    void *btx_handle, eventMemory_without_hSignalEvent_exit_callback_f *callback);

typedef void hSignalEvent_rest_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, ze_command_list_handle_t);

void btx_register_callbacks_hSignalEvent_rest_entry(
    void *btx_handle, hSignalEvent_rest_entry_callback_f *callback);

typedef void memFree_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, void *);

void btx_register_callbacks_memFree_entry(
    void *btx_handle, memFree_entry_callback_f *callback);

typedef void memFree_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, ze_result_t);

void btx_register_callbacks_memFree_exit(
    void *btx_handle, memFree_exit_callback_f *callback);

void btx_unregister_callbacks(common_data_t *common_data);

#ifdef __cplusplus
}
#endif
