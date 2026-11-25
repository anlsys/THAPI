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

void btx_push_message_lttng_ust_ompt_ompt_callback_thread_begin(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_thread_t thread_type, ompt_data_t * thread_data);
void btx_push_message_lttng_ust_ompt_ompt_callback_thread_end(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_data_t * thread_data);
void btx_push_message_lttng_ust_ompt_ompt_callback_parallel_begin(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_data_t * encountering_task_data, ompt_frame_t * encountering_task_frame, ompt_data_t * parallel_data, unsigned int requested_parallelism, ompt_parallel_flags_t flags, void * codeptr_ra);
void btx_push_message_lttng_ust_ompt_ompt_callback_parallel_end(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_data_t * parallel_data, ompt_data_t * encountering_task_data, ompt_parallel_flags_t flags, void * codeptr_ra);
void btx_push_message_lttng_ust_ompt_ompt_callback_work(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_work_t work_type, ompt_scope_endpoint_t endpoint, ompt_data_t * parallel_data, ompt_data_t * task_data, uint64_t count, void * codeptr_ra);
void btx_push_message_lttng_ust_ompt_ompt_callback_dispatch(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_data_t * parallel_data, ompt_data_t * task_data, ompt_dispatch_t kind, ompt_data_t instance);
void btx_push_message_lttng_ust_ompt_ompt_callback_task_create(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_data_t * encountering_task_data, ompt_frame_t * encountering_task_frame, ompt_data_t * new_task_data, ompt_task_flags_t flags, int has_dependences, void * codeptr_ra);
void btx_push_message_lttng_ust_ompt_ompt_callback_dependences(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_data_t * task_data, ompt_dependence_t * deps, int ndeps);
void btx_push_message_lttng_ust_ompt_ompt_callback_task_dependence(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_data_t * src_task_data, ompt_data_t * sink_task_data);
void btx_push_message_lttng_ust_ompt_ompt_callback_task_schedule(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_data_t * prior_task_data, ompt_task_status_t prior_task_status, ompt_data_t * next_task_data);
void btx_push_message_lttng_ust_ompt_ompt_callback_implicit_task(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_scope_endpoint_t endpoint, ompt_data_t * parallel_data, ompt_data_t * task_data, unsigned int actual_parallelism, unsigned int index, ompt_task_flags_t flags);
void btx_push_message_lttng_ust_ompt_ompt_callback_masked(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_scope_endpoint_t endpoint, ompt_data_t * parallel_data, ompt_data_t * task_data, void * codeptr_ra);
void btx_push_message_lttng_ust_ompt_ompt_callback_sync_region(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_sync_region_t kind, ompt_scope_endpoint_t endpoint, ompt_data_t * parallel_data, ompt_data_t * task_data, void * codeptr_ra);
void btx_push_message_lttng_ust_ompt_ompt_callback_mutex_acquire(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_mutex_t kind, unsigned int hint, unsigned int impl, ompt_wait_id_t wait_id, void * codeptr_ra);
void btx_push_message_lttng_ust_ompt_ompt_callback_mutex(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_mutex_t kind, ompt_wait_id_t wait_id, void * codeptr_ra);
void btx_push_message_lttng_ust_ompt_ompt_callback_nest_lock(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_scope_endpoint_t endpoint, ompt_wait_id_t wait_id, void * codeptr_ra);
void btx_push_message_lttng_ust_ompt_ompt_callback_flush(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_data_t * thread_data, void * codeptr_ra);
void btx_push_message_lttng_ust_ompt_ompt_callback_cancel(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_data_t * task_data, ompt_cancel_flags_t flags, void * codeptr_ra);
void btx_push_message_lttng_ust_ompt_ompt_callback_device_initialize(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int device_num, char * type, ompt_device_t * device, ompt_function_lookup_t lookup, char * documentation);
void btx_push_message_lttng_ust_ompt_ompt_callback_device_finalize(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int device_num);
void btx_push_message_lttng_ust_ompt_ompt_callback_device_load(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int device_num, char * filename, int64_t offset_in_file, void * vma_in_file, size_t bytes, void * host_addr, void * device_addr, uint64_t module_id);
void btx_push_message_lttng_ust_ompt_ompt_callback_device_unload(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int device_num, uint64_t module_id);
void btx_push_message_lttng_ust_ompt_ompt_callback_target_data_op_emi(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_scope_endpoint_t endpoint, ompt_data_t * target_task_data, ompt_data_t * target_data, ompt_id_t * host_op_id, ompt_target_data_op_t optype, void * src_addr, int src_device_num, void * dest_addr, int dest_device_num, size_t bytes, void * codeptr_ra);
void btx_push_message_lttng_ust_ompt_ompt_callback_target_data_op(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_id_t target_id, ompt_id_t host_op_id, ompt_target_data_op_t optype, void * src_addr, int src_device_num, void * dest_addr, int dest_device_num, size_t bytes, void * codeptr_ra);
void btx_push_message_lttng_ust_ompt_ompt_callback_target_emi(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_target_t kind, ompt_scope_endpoint_t endpoint, int device_num, ompt_data_t * task_data, ompt_data_t * target_task_data, ompt_data_t * target_data, void * codeptr_ra);
void btx_push_message_lttng_ust_ompt_ompt_callback_target(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_target_t kind, ompt_scope_endpoint_t endpoint, int device_num, ompt_data_t * task_data, ompt_id_t target_id, void * codeptr_ra);
void btx_push_message_lttng_ust_ompt_ompt_callback_target_map_emi(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_data_t * target_data, unsigned int nitems, void ** host_addr, void ** device_addr, size_t * bytes, unsigned int * mapping_flags, void * codeptr_ra);
void btx_push_message_lttng_ust_ompt_ompt_callback_target_map(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_id_t target_id, unsigned int nitems, void ** host_addr, void ** device_addr, size_t * bytes, ompt_target_map_flags_t * mapping_flags, void * codeptr_ra, size_t _host_addr_vals_length, void * * host_addr_vals, size_t _device_addr_vals_length, void * * device_addr_vals, size_t _bytes_vals_length, size_t * bytes_vals, size_t _mapping_flags_vals_length, ompt_target_map_flags_t * mapping_flags_vals);
void btx_push_message_lttng_ust_ompt_ompt_callback_target_submit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_id_t target_id, ompt_id_t host_op_id, unsigned int requested_num_teams);
void btx_push_message_lttng_ust_ompt_ompt_callback_target_submit_emi(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_scope_endpoint_t endpoint, ompt_data_t * target_data, ompt_id_t * host_op_id, unsigned int requested_num_teams);
void btx_push_message_lttng_ust_ompt_ompt_callback_control_tool(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int ompResult, uint64_t command, uint64_t modifier, void * arg, void * codeptr_ra);
void btx_push_message_lttng_ust_ompt_ompt_callback_error(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_severity_t severity, char * message, size_t length, void * codeptr_ra);


void btx_downstream_set_environment_hostname(
    void *btx_handle, const char* hostname);

#ifdef __cplusplus
}
#endif
