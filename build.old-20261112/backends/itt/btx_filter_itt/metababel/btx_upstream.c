#include "utarray.h"
#include "uthash.h"
#include <assert.h>
#include <babeltrace2/babeltrace.h>
#include <metababel/btx_component.h>
#include <metababel/btx_upstream.h>
#include <stdbool.h>
#include <stdlib.h>

static void btx_dispatch_lttng_ust_itt___itt_domain_create(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  __itt_domain * ittResult;
  char * name;

  const bt_event *_event =
      bt_message_event_borrow_event_const(upstream_message);
  {
    const bt_stream *stream = bt_event_borrow_stream_const(_event);
    const bt_trace *trace = bt_stream_borrow_trace_const(stream);
    {
      const bt_value *hostname_value = bt_trace_borrow_environment_entry_value_by_name_const(trace, "hostname");
      hostname = bt_value_string_get(hostname_value);
    }
  }
  {
    const bt_field *_event_cc_f = bt_event_borrow_common_context_field_const(_event);
    {
      const bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 0);
      vpid = (int64_t)bt_field_integer_signed_get_value(_event_cc_f_m_0);
    }
    {
      const bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 1);
      vtid = (uint64_t)bt_field_integer_unsigned_get_value(_event_cc_f_m_1);
    }
  }
  {
    const bt_field *_event_p_f = bt_event_borrow_payload_field_const(_event);
    {
      const bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 0);
      ittResult = (__itt_domain *)bt_field_integer_unsigned_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      name = (char *)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
    }
  }

  const bt_clock_snapshot *clock_snapshot =
      bt_message_event_borrow_default_clock_snapshot_const(upstream_message);
  bt_clock_snapshot_get_ns_from_origin(clock_snapshot, &_timestamp);

  // Call registered matching callbacks
  {
    if (callbacks->automatic) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->automatic, _p))) {
        (*((lttng_ust_itt___itt_domain_create_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, ittResult, name);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_itt___itt_string_handle_create(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  __itt_string_handle * ittResult;
  char * name;

  const bt_event *_event =
      bt_message_event_borrow_event_const(upstream_message);
  {
    const bt_stream *stream = bt_event_borrow_stream_const(_event);
    const bt_trace *trace = bt_stream_borrow_trace_const(stream);
    {
      const bt_value *hostname_value = bt_trace_borrow_environment_entry_value_by_name_const(trace, "hostname");
      hostname = bt_value_string_get(hostname_value);
    }
  }
  {
    const bt_field *_event_cc_f = bt_event_borrow_common_context_field_const(_event);
    {
      const bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 0);
      vpid = (int64_t)bt_field_integer_signed_get_value(_event_cc_f_m_0);
    }
    {
      const bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 1);
      vtid = (uint64_t)bt_field_integer_unsigned_get_value(_event_cc_f_m_1);
    }
  }
  {
    const bt_field *_event_p_f = bt_event_borrow_payload_field_const(_event);
    {
      const bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 0);
      ittResult = (__itt_string_handle *)bt_field_integer_unsigned_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      name = (char *)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
    }
  }

  const bt_clock_snapshot *clock_snapshot =
      bt_message_event_borrow_default_clock_snapshot_const(upstream_message);
  bt_clock_snapshot_get_ns_from_origin(clock_snapshot, &_timestamp);

  // Call registered matching callbacks
  {
    if (callbacks->automatic) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->automatic, _p))) {
        (*((lttng_ust_itt___itt_string_handle_create_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, ittResult, name);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_itt___itt_task_begin(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  __itt_domain * domain;
  __itt_id taskid;
  __itt_id parentid;
  __itt_string_handle * name;
  char * domain__nameA_val;
  char * name__strA_val;

  const bt_event *_event =
      bt_message_event_borrow_event_const(upstream_message);
  {
    const bt_stream *stream = bt_event_borrow_stream_const(_event);
    const bt_trace *trace = bt_stream_borrow_trace_const(stream);
    {
      const bt_value *hostname_value = bt_trace_borrow_environment_entry_value_by_name_const(trace, "hostname");
      hostname = bt_value_string_get(hostname_value);
    }
  }
  {
    const bt_field *_event_cc_f = bt_event_borrow_common_context_field_const(_event);
    {
      const bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 0);
      vpid = (int64_t)bt_field_integer_signed_get_value(_event_cc_f_m_0);
    }
    {
      const bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 1);
      vtid = (uint64_t)bt_field_integer_unsigned_get_value(_event_cc_f_m_1);
    }
  }
  {
    const bt_field *_event_p_f = bt_event_borrow_payload_field_const(_event);
    {
      const bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 0);
      domain = (__itt_domain *)bt_field_integer_unsigned_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      // Dump string data to the struct.
      memcpy(&taskid, bt_field_string_get_value(_event_p_f_m_1), sizeof(taskid));
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      // Dump string data to the struct.
      memcpy(&parentid, bt_field_string_get_value(_event_p_f_m_2), sizeof(parentid));
    }
    {
      const bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 3);
      name = (__itt_string_handle *)bt_field_integer_unsigned_get_value(_event_p_f_m_3);
    }
    {
      const bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 4);
      domain__nameA_val = (char *)bt_field_string_get_value(_event_p_f_m_4);
    }
    {
      const bt_field *_event_p_f_m_5 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 5);
      name__strA_val = (char *)bt_field_string_get_value(_event_p_f_m_5);
    }
  }

  const bt_clock_snapshot *clock_snapshot =
      bt_message_event_borrow_default_clock_snapshot_const(upstream_message);
  bt_clock_snapshot_get_ns_from_origin(clock_snapshot, &_timestamp);

  // Call registered matching callbacks
  {
    if (callbacks->automatic) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->automatic, _p))) {
        (*((lttng_ust_itt___itt_task_begin_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, domain, taskid, parentid, name, domain__nameA_val, name__strA_val);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_itt___itt_task_end(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  __itt_domain * domain;

  const bt_event *_event =
      bt_message_event_borrow_event_const(upstream_message);
  {
    const bt_stream *stream = bt_event_borrow_stream_const(_event);
    const bt_trace *trace = bt_stream_borrow_trace_const(stream);
    {
      const bt_value *hostname_value = bt_trace_borrow_environment_entry_value_by_name_const(trace, "hostname");
      hostname = bt_value_string_get(hostname_value);
    }
  }
  {
    const bt_field *_event_cc_f = bt_event_borrow_common_context_field_const(_event);
    {
      const bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 0);
      vpid = (int64_t)bt_field_integer_signed_get_value(_event_cc_f_m_0);
    }
    {
      const bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 1);
      vtid = (uint64_t)bt_field_integer_unsigned_get_value(_event_cc_f_m_1);
    }
  }
  {
    const bt_field *_event_p_f = bt_event_borrow_payload_field_const(_event);
    {
      const bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 0);
      domain = (__itt_domain *)bt_field_integer_unsigned_get_value(_event_p_f_m_0);
    }
  }

  const bt_clock_snapshot *clock_snapshot =
      bt_message_event_borrow_default_clock_snapshot_const(upstream_message);
  bt_clock_snapshot_get_ns_from_origin(clock_snapshot, &_timestamp);

  // Call registered matching callbacks
  {
    if (callbacks->automatic) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->automatic, _p))) {
        (*((lttng_ust_itt___itt_task_end_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, domain);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_itt___itt_metadata_add(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  __itt_domain * domain;
  __itt_id id;
  __itt_string_handle * key;
  __itt_metadata_type type;
  size_t count;
  void * data;
  char * key__strA_val;

  const bt_event *_event =
      bt_message_event_borrow_event_const(upstream_message);
  {
    const bt_stream *stream = bt_event_borrow_stream_const(_event);
    const bt_trace *trace = bt_stream_borrow_trace_const(stream);
    {
      const bt_value *hostname_value = bt_trace_borrow_environment_entry_value_by_name_const(trace, "hostname");
      hostname = bt_value_string_get(hostname_value);
    }
  }
  {
    const bt_field *_event_cc_f = bt_event_borrow_common_context_field_const(_event);
    {
      const bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 0);
      vpid = (int64_t)bt_field_integer_signed_get_value(_event_cc_f_m_0);
    }
    {
      const bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 1);
      vtid = (uint64_t)bt_field_integer_unsigned_get_value(_event_cc_f_m_1);
    }
  }
  {
    const bt_field *_event_p_f = bt_event_borrow_payload_field_const(_event);
    {
      const bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 0);
      domain = (__itt_domain *)bt_field_integer_unsigned_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      // Dump string data to the struct.
      memcpy(&id, bt_field_string_get_value(_event_p_f_m_1), sizeof(id));
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      key = (__itt_string_handle *)bt_field_integer_unsigned_get_value(_event_p_f_m_2);
    }
    {
      const bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 3);
      type = (__itt_metadata_type)bt_field_integer_signed_get_value(_event_p_f_m_3);
    }
    {
      const bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 4);
      count = (size_t)bt_field_integer_unsigned_get_value(_event_p_f_m_4);
    }
    {
      const bt_field *_event_p_f_m_5 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 5);
      data = (void *)bt_field_integer_unsigned_get_value(_event_p_f_m_5);
    }
    {
      const bt_field *_event_p_f_m_6 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 6);
      key__strA_val = (char *)bt_field_string_get_value(_event_p_f_m_6);
    }
  }

  const bt_clock_snapshot *clock_snapshot =
      bt_message_event_borrow_default_clock_snapshot_const(upstream_message);
  bt_clock_snapshot_get_ns_from_origin(clock_snapshot, &_timestamp);

  // Call registered matching callbacks
  {
    if (callbacks->automatic) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->automatic, _p))) {
        (*((lttng_ust_itt___itt_metadata_add_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, domain, id, key, type, count, data, key__strA_val);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_itt___itt_event_create(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  __itt_event ittResult;
  char * name;
  int namelen;
  char * name_val;

  const bt_event *_event =
      bt_message_event_borrow_event_const(upstream_message);
  {
    const bt_stream *stream = bt_event_borrow_stream_const(_event);
    const bt_trace *trace = bt_stream_borrow_trace_const(stream);
    {
      const bt_value *hostname_value = bt_trace_borrow_environment_entry_value_by_name_const(trace, "hostname");
      hostname = bt_value_string_get(hostname_value);
    }
  }
  {
    const bt_field *_event_cc_f = bt_event_borrow_common_context_field_const(_event);
    {
      const bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 0);
      vpid = (int64_t)bt_field_integer_signed_get_value(_event_cc_f_m_0);
    }
    {
      const bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 1);
      vtid = (uint64_t)bt_field_integer_unsigned_get_value(_event_cc_f_m_1);
    }
  }
  {
    const bt_field *_event_p_f = bt_event_borrow_payload_field_const(_event);
    {
      const bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 0);
      ittResult = (__itt_event)bt_field_integer_signed_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      name = (char *)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      namelen = (int)bt_field_integer_signed_get_value(_event_p_f_m_2);
    }
    {
      const bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 3);
      name_val = (char *)bt_field_string_get_value(_event_p_f_m_3);
    }
  }

  const bt_clock_snapshot *clock_snapshot =
      bt_message_event_borrow_default_clock_snapshot_const(upstream_message);
  bt_clock_snapshot_get_ns_from_origin(clock_snapshot, &_timestamp);

  // Call registered matching callbacks
  {
    if (callbacks->automatic) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->automatic, _p))) {
        (*((lttng_ust_itt___itt_event_create_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, ittResult, name, namelen, name_val);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_itt___itt_event_start(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  int ittResult;
  __itt_event event;

  const bt_event *_event =
      bt_message_event_borrow_event_const(upstream_message);
  {
    const bt_stream *stream = bt_event_borrow_stream_const(_event);
    const bt_trace *trace = bt_stream_borrow_trace_const(stream);
    {
      const bt_value *hostname_value = bt_trace_borrow_environment_entry_value_by_name_const(trace, "hostname");
      hostname = bt_value_string_get(hostname_value);
    }
  }
  {
    const bt_field *_event_cc_f = bt_event_borrow_common_context_field_const(_event);
    {
      const bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 0);
      vpid = (int64_t)bt_field_integer_signed_get_value(_event_cc_f_m_0);
    }
    {
      const bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 1);
      vtid = (uint64_t)bt_field_integer_unsigned_get_value(_event_cc_f_m_1);
    }
  }
  {
    const bt_field *_event_p_f = bt_event_borrow_payload_field_const(_event);
    {
      const bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 0);
      ittResult = (int)bt_field_integer_signed_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      event = (__itt_event)bt_field_integer_signed_get_value(_event_p_f_m_1);
    }
  }

  const bt_clock_snapshot *clock_snapshot =
      bt_message_event_borrow_default_clock_snapshot_const(upstream_message);
  bt_clock_snapshot_get_ns_from_origin(clock_snapshot, &_timestamp);

  // Call registered matching callbacks
  {
    if (callbacks->automatic) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->automatic, _p))) {
        (*((lttng_ust_itt___itt_event_start_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, ittResult, event);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_itt___itt_event_end(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  int ittResult;
  __itt_event event;

  const bt_event *_event =
      bt_message_event_borrow_event_const(upstream_message);
  {
    const bt_stream *stream = bt_event_borrow_stream_const(_event);
    const bt_trace *trace = bt_stream_borrow_trace_const(stream);
    {
      const bt_value *hostname_value = bt_trace_borrow_environment_entry_value_by_name_const(trace, "hostname");
      hostname = bt_value_string_get(hostname_value);
    }
  }
  {
    const bt_field *_event_cc_f = bt_event_borrow_common_context_field_const(_event);
    {
      const bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 0);
      vpid = (int64_t)bt_field_integer_signed_get_value(_event_cc_f_m_0);
    }
    {
      const bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 1);
      vtid = (uint64_t)bt_field_integer_unsigned_get_value(_event_cc_f_m_1);
    }
  }
  {
    const bt_field *_event_p_f = bt_event_borrow_payload_field_const(_event);
    {
      const bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 0);
      ittResult = (int)bt_field_integer_signed_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      event = (__itt_event)bt_field_integer_signed_get_value(_event_p_f_m_1);
    }
  }

  const bt_clock_snapshot *clock_snapshot =
      bt_message_event_borrow_default_clock_snapshot_const(upstream_message);
  bt_clock_snapshot_get_ns_from_origin(clock_snapshot, &_timestamp);

  // Call registered matching callbacks
  {
    if (callbacks->automatic) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->automatic, _p))) {
        (*((lttng_ust_itt___itt_event_end_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, ittResult, event);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_itt_metadata_metadata(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  __itt_metadata_type type;
  size_t count;
  void* data;
  size_t _data_val_length;
  void* data_val;

  const bt_event *_event =
      bt_message_event_borrow_event_const(upstream_message);
  {
    const bt_stream *stream = bt_event_borrow_stream_const(_event);
    const bt_trace *trace = bt_stream_borrow_trace_const(stream);
    {
      const bt_value *hostname_value = bt_trace_borrow_environment_entry_value_by_name_const(trace, "hostname");
      hostname = bt_value_string_get(hostname_value);
    }
  }
  {
    const bt_field *_event_cc_f = bt_event_borrow_common_context_field_const(_event);
    {
      const bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 0);
      vpid = (int64_t)bt_field_integer_signed_get_value(_event_cc_f_m_0);
    }
    {
      const bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 1);
      vtid = (uint64_t)bt_field_integer_unsigned_get_value(_event_cc_f_m_1);
    }
  }
  {
    const bt_field *_event_p_f = bt_event_borrow_payload_field_const(_event);
    {
      const bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 0);
      type = (__itt_metadata_type)bt_field_integer_signed_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      count = (size_t)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      data = (void*)bt_field_integer_unsigned_get_value(_event_p_f_m_2);
    }
    {
      const bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 3);
      _data_val_length = (size_t)bt_field_integer_unsigned_get_value(_event_p_f_m_3);
    }
    {
      const bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 4);
      data_val = (void*)bt_field_string_get_value(_event_p_f_m_4);
    }
  }

  const bt_clock_snapshot *clock_snapshot =
      bt_message_event_borrow_default_clock_snapshot_const(upstream_message);
  bt_clock_snapshot_get_ns_from_origin(clock_snapshot, &_timestamp);

  // Call registered matching callbacks
  {
    if (callbacks->automatic) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->automatic, _p))) {
        (*((lttng_ust_itt_metadata_metadata_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, type, count, data, _data_val_length, data_val);
      }
    }
  }

}


static void __attribute__((unused))
bt_register_callbacks(void *btx_handle, const char *dispatcher_name,
                      void *btx_dispatch_p, const char *id, void *callback) {

  name_to_dispatcher_t *s = NULL;

  name_to_dispatcher_t **name_to_dispatcher =
      &((common_data_t *)btx_handle)->name_to_dispatcher;
  HASH_FIND_STR(*name_to_dispatcher, dispatcher_name, s);

  if (!s) {
    // We didn't find the dispatcher, so we need to create it.
    s = (name_to_dispatcher_t *)malloc(sizeof(name_to_dispatcher_t));
    s->name = dispatcher_name;
    s->dispatcher = btx_dispatch_p;
    s->callbacks = (callbacks_t *)calloc(1, sizeof(callbacks_t));
    // 2. Register it
    HASH_ADD_KEYPTR(hh, *name_to_dispatcher, s->name, strlen(s->name), s);
  }

  if(strcmp("automatic", id) == 0) {
    // Add the callbacks to the array
    if (!s->callbacks->automatic)
      utarray_new(s->callbacks->automatic, &ut_ptr_icd);
    utarray_push_back(s->callbacks->automatic, &callback);
  }
}

void btx_register_callbacks_lttng_ust_itt___itt_domain_create(
    void *btx_handle,
    lttng_ust_itt___itt_domain_create_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_itt:__itt_domain_create",
                        (void *)&btx_dispatch_lttng_ust_itt___itt_domain_create,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_itt___itt_string_handle_create(
    void *btx_handle,
    lttng_ust_itt___itt_string_handle_create_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_itt:__itt_string_handle_create",
                        (void *)&btx_dispatch_lttng_ust_itt___itt_string_handle_create,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_itt___itt_task_begin(
    void *btx_handle,
    lttng_ust_itt___itt_task_begin_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_itt:__itt_task_begin",
                        (void *)&btx_dispatch_lttng_ust_itt___itt_task_begin,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_itt___itt_task_end(
    void *btx_handle,
    lttng_ust_itt___itt_task_end_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_itt:__itt_task_end",
                        (void *)&btx_dispatch_lttng_ust_itt___itt_task_end,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_itt___itt_metadata_add(
    void *btx_handle,
    lttng_ust_itt___itt_metadata_add_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_itt:__itt_metadata_add",
                        (void *)&btx_dispatch_lttng_ust_itt___itt_metadata_add,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_itt___itt_event_create(
    void *btx_handle,
    lttng_ust_itt___itt_event_create_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_itt:__itt_event_create",
                        (void *)&btx_dispatch_lttng_ust_itt___itt_event_create,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_itt___itt_event_start(
    void *btx_handle,
    lttng_ust_itt___itt_event_start_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_itt:__itt_event_start",
                        (void *)&btx_dispatch_lttng_ust_itt___itt_event_start,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_itt___itt_event_end(
    void *btx_handle,
    lttng_ust_itt___itt_event_end_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_itt:__itt_event_end",
                        (void *)&btx_dispatch_lttng_ust_itt___itt_event_end,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_itt_metadata_metadata(
    void *btx_handle,
    lttng_ust_itt_metadata_metadata_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_itt_metadata:metadata",
                        (void *)&btx_dispatch_lttng_ust_itt_metadata_metadata,
                        "automatic", (void *)callback);
}
