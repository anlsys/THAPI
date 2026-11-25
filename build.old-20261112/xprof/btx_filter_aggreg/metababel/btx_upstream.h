#pragma once
#include <metababel/btx_component.h>
#ifdef __cplusplus
extern "C" {
#endif

// Dispatcher
typedef void(dispatcher_t)(callbacks_t *callbacks, common_data_t *common_data,
                           const bt_message *upstream_message);

typedef void lttng_host_callback_f(
    void *btx_handle,
    void *
        usr_data, const char*, int64_t, uint64_t, int64_t, int64_t, const char*, uint64_t, bt_bool);

void btx_register_callbacks_lttng_host(
    void *btx_handle, lttng_host_callback_f *callback);

typedef void lttng_device_callback_f(
    void *btx_handle,
    void *
        usr_data, const char*, int64_t, uint64_t, int64_t, int64_t, const char*, uint64_t, uint64_t, uint64_t, bt_bool, const char*);

void btx_register_callbacks_lttng_device(
    void *btx_handle, lttng_device_callback_f *callback);

typedef void lttng_traffic_callback_f(
    void *btx_handle,
    void *
        usr_data, const char*, int64_t, uint64_t, int64_t, int64_t, const char*, uint64_t, const char*);

void btx_register_callbacks_lttng_traffic(
    void *btx_handle, lttng_traffic_callback_f *callback);

typedef void sampling_frequency_callback_f(
    void *btx_handle,
    void *
        usr_data, const char*, int64_t, uint64_t, uint32_t, uint64_t, uint32_t, uint64_t);

void btx_register_callbacks_sampling_frequency(
    void *btx_handle, sampling_frequency_callback_f *callback);

typedef void sampling_power_callback_f(
    void *btx_handle,
    void *
        usr_data, const char*, int64_t, uint64_t, uint32_t, uint64_t, uint32_t, uint64_t);

void btx_register_callbacks_sampling_power(
    void *btx_handle, sampling_power_callback_f *callback);

typedef void sampling_computeEU_callback_f(
    void *btx_handle,
    void *
        usr_data, const char*, int64_t, uint64_t, uint32_t, uint64_t, uint32_t, float);

void btx_register_callbacks_sampling_computeEU(
    void *btx_handle, sampling_computeEU_callback_f *callback);

typedef void sampling_copyEU_callback_f(
    void *btx_handle,
    void *
        usr_data, const char*, int64_t, uint64_t, uint32_t, uint64_t, uint32_t, float);

void btx_register_callbacks_sampling_copyEU(
    void *btx_handle, sampling_copyEU_callback_f *callback);

typedef void sampling_fabricPort_callback_f(
    void *btx_handle,
    void *
        usr_data, const char*, int64_t, uint64_t, uint32_t, uint64_t, uint32_t, uint32_t, uint32_t, float, float, float, float);

void btx_register_callbacks_sampling_fabricPort(
    void *btx_handle, sampling_fabricPort_callback_f *callback);

typedef void sampling_memModule_callback_f(
    void *btx_handle,
    void *
        usr_data, const char*, int64_t, uint64_t, uint32_t, uint64_t, uint32_t, float, float, float, float);

void btx_register_callbacks_sampling_memModule(
    void *btx_handle, sampling_memModule_callback_f *callback);

typedef void sampling_nic_callback_f(
    void *btx_handle,
    void *
        usr_data, const char*, int64_t, const char*, const char*, uint64_t);

void btx_register_callbacks_sampling_nic(
    void *btx_handle, sampling_nic_callback_f *callback);

typedef void aggreg_host_callback_f(
    void *btx_handle,
    void *
        usr_data, const char*, int64_t, uint64_t, const char*, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t);

void btx_register_callbacks_aggreg_host(
    void *btx_handle, aggreg_host_callback_f *callback);

typedef void aggreg_device_callback_f(
    void *btx_handle,
    void *
        usr_data, const char*, int64_t, uint64_t, const char*, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, const char*);

void btx_register_callbacks_aggreg_device(
    void *btx_handle, aggreg_device_callback_f *callback);

typedef void aggreg_traffic_callback_f(
    void *btx_handle,
    void *
        usr_data, const char*, int64_t, uint64_t, const char*, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, const char*);

void btx_register_callbacks_aggreg_traffic(
    void *btx_handle, aggreg_traffic_callback_f *callback);

typedef void lttng_device_name_callback_f(
    void *btx_handle,
    void *
        usr_data, const char*, int64_t, uint64_t, int64_t, int64_t, const char*, uint64_t);

void btx_register_callbacks_lttng_device_name(
    void *btx_handle, lttng_device_name_callback_f *callback);

typedef void lttng_ust_thapi_metadata_callback_f(
    void *btx_handle,
    void *
        usr_data, const char*, int64_t, uint64_t, int64_t, int64_t, const char*);

void btx_register_callbacks_lttng_ust_thapi_metadata(
    void *btx_handle, lttng_ust_thapi_metadata_callback_f *callback);

void btx_unregister_callbacks(common_data_t *common_data);

#ifdef __cplusplus
}
#endif
