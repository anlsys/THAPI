#pragma once
#include <metababel/btx_component.h>
#ifdef __cplusplus
extern "C" {
#endif

// Dispatcher
typedef void(dispatcher_t)(callbacks_t *callbacks, common_data_t *common_data,
                           const bt_message *upstream_message);

typedef void lttng_ust_itt___itt_domain_create_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, __itt_domain *, char *);

void btx_register_callbacks_lttng_ust_itt___itt_domain_create(
    void *btx_handle, lttng_ust_itt___itt_domain_create_callback_f *callback);

typedef void lttng_ust_itt___itt_string_handle_create_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, __itt_string_handle *, char *);

void btx_register_callbacks_lttng_ust_itt___itt_string_handle_create(
    void *btx_handle, lttng_ust_itt___itt_string_handle_create_callback_f *callback);

typedef void lttng_ust_itt___itt_task_begin_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, __itt_domain *, __itt_id, __itt_id, __itt_string_handle *, char *, char *);

void btx_register_callbacks_lttng_ust_itt___itt_task_begin(
    void *btx_handle, lttng_ust_itt___itt_task_begin_callback_f *callback);

typedef void lttng_ust_itt___itt_task_end_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, __itt_domain *);

void btx_register_callbacks_lttng_ust_itt___itt_task_end(
    void *btx_handle, lttng_ust_itt___itt_task_end_callback_f *callback);

typedef void lttng_ust_itt___itt_metadata_add_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, __itt_domain *, __itt_id, __itt_string_handle *, __itt_metadata_type, size_t, void *, char *);

void btx_register_callbacks_lttng_ust_itt___itt_metadata_add(
    void *btx_handle, lttng_ust_itt___itt_metadata_add_callback_f *callback);

typedef void lttng_ust_itt___itt_event_create_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, __itt_event, char *, int, char *);

void btx_register_callbacks_lttng_ust_itt___itt_event_create(
    void *btx_handle, lttng_ust_itt___itt_event_create_callback_f *callback);

typedef void lttng_ust_itt___itt_event_start_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, __itt_event);

void btx_register_callbacks_lttng_ust_itt___itt_event_start(
    void *btx_handle, lttng_ust_itt___itt_event_start_callback_f *callback);

typedef void lttng_ust_itt___itt_event_end_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, __itt_event);

void btx_register_callbacks_lttng_ust_itt___itt_event_end(
    void *btx_handle, lttng_ust_itt___itt_event_end_callback_f *callback);

typedef void lttng_ust_itt_metadata_metadata_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, __itt_metadata_type, size_t, void*, size_t, void*);

void btx_register_callbacks_lttng_ust_itt_metadata_metadata(
    void *btx_handle, lttng_ust_itt_metadata_metadata_callback_f *callback);

void btx_unregister_callbacks(common_data_t *common_data);

#ifdef __cplusplus
}
#endif
