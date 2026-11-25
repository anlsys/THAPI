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

void btx_push_message_lttng_ust_itt___itt_domain_create(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, __itt_domain * ittResult, char * name);
void btx_push_message_lttng_ust_itt___itt_string_handle_create(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, __itt_string_handle * ittResult, char * name);
void btx_push_message_lttng_ust_itt___itt_task_begin(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, __itt_domain * domain, __itt_id taskid, __itt_id parentid, __itt_string_handle * name, char * domain__nameA_val, char * name__strA_val);
void btx_push_message_lttng_ust_itt___itt_task_end(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, __itt_domain * domain);
void btx_push_message_lttng_ust_itt___itt_metadata_add(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, __itt_domain * domain, __itt_id id, __itt_string_handle * key, __itt_metadata_type type, size_t count, void * data, char * key__strA_val);
void btx_push_message_lttng_ust_itt___itt_event_create(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, __itt_event ittResult, char * name, int namelen, char * name_val);
void btx_push_message_lttng_ust_itt___itt_event_start(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int ittResult, __itt_event event);
void btx_push_message_lttng_ust_itt___itt_event_end(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int ittResult, __itt_event event);
void btx_push_message_lttng_ust_itt_metadata_metadata(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, __itt_metadata_type type, size_t count, void* data, size_t _data_val_length, void* data_val);


void btx_downstream_set_environment_hostname(
    void *btx_handle, const char* hostname);

#ifdef __cplusplus
}
#endif
