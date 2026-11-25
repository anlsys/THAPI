#pragma once
#include <metababel/btx_component.h>
#ifdef __cplusplus
extern "C" {
#endif

// Dispatcher
typedef void(dispatcher_t)(callbacks_t *callbacks, common_data_t *common_data,
                           const bt_message *upstream_message);

typedef void lttng_ust_ompt_ompt_callback_thread_begin_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ompt_thread_t, ompt_data_t *);

void btx_register_callbacks_lttng_ust_ompt_ompt_callback_thread_begin(
    void *btx_handle, lttng_ust_ompt_ompt_callback_thread_begin_callback_f *callback);

typedef void lttng_ust_ompt_ompt_callback_thread_end_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ompt_data_t *);

void btx_register_callbacks_lttng_ust_ompt_ompt_callback_thread_end(
    void *btx_handle, lttng_ust_ompt_ompt_callback_thread_end_callback_f *callback);

typedef void lttng_ust_ompt_ompt_callback_parallel_begin_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ompt_data_t *, ompt_frame_t *, ompt_data_t *, unsigned int, ompt_parallel_flags_t, void *);

void btx_register_callbacks_lttng_ust_ompt_ompt_callback_parallel_begin(
    void *btx_handle, lttng_ust_ompt_ompt_callback_parallel_begin_callback_f *callback);

typedef void lttng_ust_ompt_ompt_callback_parallel_end_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ompt_data_t *, ompt_data_t *, ompt_parallel_flags_t, void *);

void btx_register_callbacks_lttng_ust_ompt_ompt_callback_parallel_end(
    void *btx_handle, lttng_ust_ompt_ompt_callback_parallel_end_callback_f *callback);

typedef void lttng_ust_ompt_ompt_callback_work_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ompt_work_t, ompt_scope_endpoint_t, ompt_data_t *, ompt_data_t *, uint64_t, void *);

void btx_register_callbacks_lttng_ust_ompt_ompt_callback_work(
    void *btx_handle, lttng_ust_ompt_ompt_callback_work_callback_f *callback);

typedef void lttng_ust_ompt_ompt_callback_dispatch_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ompt_data_t *, ompt_data_t *, ompt_dispatch_t, ompt_data_t);

void btx_register_callbacks_lttng_ust_ompt_ompt_callback_dispatch(
    void *btx_handle, lttng_ust_ompt_ompt_callback_dispatch_callback_f *callback);

typedef void lttng_ust_ompt_ompt_callback_task_create_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ompt_data_t *, ompt_frame_t *, ompt_data_t *, ompt_task_flags_t, int, void *);

void btx_register_callbacks_lttng_ust_ompt_ompt_callback_task_create(
    void *btx_handle, lttng_ust_ompt_ompt_callback_task_create_callback_f *callback);

typedef void lttng_ust_ompt_ompt_callback_dependences_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ompt_data_t *, ompt_dependence_t *, int);

void btx_register_callbacks_lttng_ust_ompt_ompt_callback_dependences(
    void *btx_handle, lttng_ust_ompt_ompt_callback_dependences_callback_f *callback);

typedef void lttng_ust_ompt_ompt_callback_task_dependence_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ompt_data_t *, ompt_data_t *);

void btx_register_callbacks_lttng_ust_ompt_ompt_callback_task_dependence(
    void *btx_handle, lttng_ust_ompt_ompt_callback_task_dependence_callback_f *callback);

typedef void lttng_ust_ompt_ompt_callback_task_schedule_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ompt_data_t *, ompt_task_status_t, ompt_data_t *);

void btx_register_callbacks_lttng_ust_ompt_ompt_callback_task_schedule(
    void *btx_handle, lttng_ust_ompt_ompt_callback_task_schedule_callback_f *callback);

typedef void lttng_ust_ompt_ompt_callback_implicit_task_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ompt_scope_endpoint_t, ompt_data_t *, ompt_data_t *, unsigned int, unsigned int, ompt_task_flags_t);

void btx_register_callbacks_lttng_ust_ompt_ompt_callback_implicit_task(
    void *btx_handle, lttng_ust_ompt_ompt_callback_implicit_task_callback_f *callback);

typedef void lttng_ust_ompt_ompt_callback_masked_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ompt_scope_endpoint_t, ompt_data_t *, ompt_data_t *, void *);

void btx_register_callbacks_lttng_ust_ompt_ompt_callback_masked(
    void *btx_handle, lttng_ust_ompt_ompt_callback_masked_callback_f *callback);

typedef void lttng_ust_ompt_ompt_callback_sync_region_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ompt_sync_region_t, ompt_scope_endpoint_t, ompt_data_t *, ompt_data_t *, void *);

void btx_register_callbacks_lttng_ust_ompt_ompt_callback_sync_region(
    void *btx_handle, lttng_ust_ompt_ompt_callback_sync_region_callback_f *callback);

typedef void lttng_ust_ompt_ompt_callback_mutex_acquire_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ompt_mutex_t, unsigned int, unsigned int, ompt_wait_id_t, void *);

void btx_register_callbacks_lttng_ust_ompt_ompt_callback_mutex_acquire(
    void *btx_handle, lttng_ust_ompt_ompt_callback_mutex_acquire_callback_f *callback);

typedef void lttng_ust_ompt_ompt_callback_mutex_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ompt_mutex_t, ompt_wait_id_t, void *);

void btx_register_callbacks_lttng_ust_ompt_ompt_callback_mutex(
    void *btx_handle, lttng_ust_ompt_ompt_callback_mutex_callback_f *callback);

typedef void lttng_ust_ompt_ompt_callback_nest_lock_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ompt_scope_endpoint_t, ompt_wait_id_t, void *);

void btx_register_callbacks_lttng_ust_ompt_ompt_callback_nest_lock(
    void *btx_handle, lttng_ust_ompt_ompt_callback_nest_lock_callback_f *callback);

typedef void lttng_ust_ompt_ompt_callback_flush_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ompt_data_t *, void *);

void btx_register_callbacks_lttng_ust_ompt_ompt_callback_flush(
    void *btx_handle, lttng_ust_ompt_ompt_callback_flush_callback_f *callback);

typedef void lttng_ust_ompt_ompt_callback_cancel_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ompt_data_t *, ompt_cancel_flags_t, void *);

void btx_register_callbacks_lttng_ust_ompt_ompt_callback_cancel(
    void *btx_handle, lttng_ust_ompt_ompt_callback_cancel_callback_f *callback);

typedef void lttng_ust_ompt_ompt_callback_device_initialize_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char *, ompt_device_t *, ompt_function_lookup_t, char *);

void btx_register_callbacks_lttng_ust_ompt_ompt_callback_device_initialize(
    void *btx_handle, lttng_ust_ompt_ompt_callback_device_initialize_callback_f *callback);

typedef void lttng_ust_ompt_ompt_callback_device_finalize_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_ompt_ompt_callback_device_finalize(
    void *btx_handle, lttng_ust_ompt_ompt_callback_device_finalize_callback_f *callback);

typedef void lttng_ust_ompt_ompt_callback_device_load_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char *, int64_t, void *, size_t, void *, void *, uint64_t);

void btx_register_callbacks_lttng_ust_ompt_ompt_callback_device_load(
    void *btx_handle, lttng_ust_ompt_ompt_callback_device_load_callback_f *callback);

typedef void lttng_ust_ompt_ompt_callback_device_unload_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, uint64_t);

void btx_register_callbacks_lttng_ust_ompt_ompt_callback_device_unload(
    void *btx_handle, lttng_ust_ompt_ompt_callback_device_unload_callback_f *callback);

typedef void lttng_ust_ompt_ompt_callback_target_data_op_emi_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ompt_scope_endpoint_t, ompt_data_t *, ompt_data_t *, ompt_id_t *, ompt_target_data_op_t, void *, int, void *, int, size_t, void *);

void btx_register_callbacks_lttng_ust_ompt_ompt_callback_target_data_op_emi(
    void *btx_handle, lttng_ust_ompt_ompt_callback_target_data_op_emi_callback_f *callback);

typedef void lttng_ust_ompt_ompt_callback_target_data_op_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ompt_id_t, ompt_id_t, ompt_target_data_op_t, void *, int, void *, int, size_t, void *);

void btx_register_callbacks_lttng_ust_ompt_ompt_callback_target_data_op(
    void *btx_handle, lttng_ust_ompt_ompt_callback_target_data_op_callback_f *callback);

typedef void lttng_ust_ompt_ompt_callback_target_emi_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ompt_target_t, ompt_scope_endpoint_t, int, ompt_data_t *, ompt_data_t *, ompt_data_t *, void *);

void btx_register_callbacks_lttng_ust_ompt_ompt_callback_target_emi(
    void *btx_handle, lttng_ust_ompt_ompt_callback_target_emi_callback_f *callback);

typedef void lttng_ust_ompt_ompt_callback_target_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ompt_target_t, ompt_scope_endpoint_t, int, ompt_data_t *, ompt_id_t, void *);

void btx_register_callbacks_lttng_ust_ompt_ompt_callback_target(
    void *btx_handle, lttng_ust_ompt_ompt_callback_target_callback_f *callback);

typedef void lttng_ust_ompt_ompt_callback_target_map_emi_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ompt_data_t *, unsigned int, void **, void **, size_t *, unsigned int *, void *);

void btx_register_callbacks_lttng_ust_ompt_ompt_callback_target_map_emi(
    void *btx_handle, lttng_ust_ompt_ompt_callback_target_map_emi_callback_f *callback);

typedef void lttng_ust_ompt_ompt_callback_target_map_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ompt_id_t, unsigned int, void **, void **, size_t *, ompt_target_map_flags_t *, void *, size_t, void * *, size_t, void * *, size_t, size_t *, size_t, ompt_target_map_flags_t *);

void btx_register_callbacks_lttng_ust_ompt_ompt_callback_target_map(
    void *btx_handle, lttng_ust_ompt_ompt_callback_target_map_callback_f *callback);

typedef void lttng_ust_ompt_ompt_callback_target_submit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ompt_id_t, ompt_id_t, unsigned int);

void btx_register_callbacks_lttng_ust_ompt_ompt_callback_target_submit(
    void *btx_handle, lttng_ust_ompt_ompt_callback_target_submit_callback_f *callback);

typedef void lttng_ust_ompt_ompt_callback_target_submit_emi_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ompt_scope_endpoint_t, ompt_data_t *, ompt_id_t *, unsigned int);

void btx_register_callbacks_lttng_ust_ompt_ompt_callback_target_submit_emi(
    void *btx_handle, lttng_ust_ompt_ompt_callback_target_submit_emi_callback_f *callback);

typedef void lttng_ust_ompt_ompt_callback_control_tool_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, uint64_t, uint64_t, void *, void *);

void btx_register_callbacks_lttng_ust_ompt_ompt_callback_control_tool(
    void *btx_handle, lttng_ust_ompt_ompt_callback_control_tool_callback_f *callback);

typedef void lttng_ust_ompt_ompt_callback_error_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, ompt_severity_t, char *, size_t, void *);

void btx_register_callbacks_lttng_ust_ompt_ompt_callback_error(
    void *btx_handle, lttng_ust_ompt_ompt_callback_error_callback_f *callback);

typedef void btx_host_sync_region_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, ompt_sync_region_t, ompt_scope_endpoint_t);

void btx_register_callbacks_btx_host_sync_region(
    void *btx_handle, btx_host_sync_region_callback_f *callback);

typedef void btx_host_target_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, ompt_target_t, ompt_scope_endpoint_t);

void btx_register_callbacks_btx_host_target(
    void *btx_handle, btx_host_target_callback_f *callback);

typedef void btx_host_target_data_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, ompt_scope_endpoint_t, ompt_target_data_op_t);

void btx_register_callbacks_btx_host_target_data(
    void *btx_handle, btx_host_target_data_callback_f *callback);

typedef void btx_host_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, ompt_scope_endpoint_t);

void btx_register_callbacks_btx_host(
    void *btx_handle, btx_host_callback_f *callback);

typedef void btx_traffic_target_data_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, ompt_scope_endpoint_t, ompt_target_data_op_t, size_t);

void btx_register_callbacks_btx_traffic_target_data(
    void *btx_handle, btx_traffic_target_data_callback_f *callback);

void btx_unregister_callbacks(common_data_t *common_data);

#ifdef __cplusplus
}
#endif
