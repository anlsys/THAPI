#include "utarray.h"
#include "uthash.h"
#include <assert.h>
#include <babeltrace2/babeltrace.h>
#include <metababel/btx_component.h>
#include <metababel/btx_upstream.h>
#include <stdbool.h>
#include <stdlib.h>

static void btx_dispatch_lttng_ust_ompt_ompt_callback_thread_begin(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  ompt_thread_t thread_type;
  ompt_data_t * thread_data;

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
      thread_type = (ompt_thread_t)bt_field_integer_signed_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      thread_data = (ompt_data_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
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
        (*((lttng_ust_ompt_ompt_callback_thread_begin_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, thread_type, thread_data);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_ompt_ompt_callback_thread_end(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  ompt_data_t * thread_data;

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
      thread_data = (ompt_data_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_0);
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
        (*((lttng_ust_ompt_ompt_callback_thread_end_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, thread_data);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_ompt_ompt_callback_parallel_begin(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  ompt_data_t * encountering_task_data;
  ompt_frame_t * encountering_task_frame;
  ompt_data_t * parallel_data;
  unsigned int requested_parallelism;
  ompt_parallel_flags_t flags;
  void * codeptr_ra;

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
      encountering_task_data = (ompt_data_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      encountering_task_frame = (ompt_frame_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      parallel_data = (ompt_data_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_2);
    }
    {
      const bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 3);
      requested_parallelism = (unsigned int)bt_field_integer_unsigned_get_value(_event_p_f_m_3);
    }
    {
      const bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 4);
      flags = (ompt_parallel_flags_t)bt_field_integer_signed_get_value(_event_p_f_m_4);
    }
    {
      const bt_field *_event_p_f_m_5 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 5);
      codeptr_ra = (void *)bt_field_integer_unsigned_get_value(_event_p_f_m_5);
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
        (*((lttng_ust_ompt_ompt_callback_parallel_begin_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, encountering_task_data, encountering_task_frame, parallel_data, requested_parallelism, flags, codeptr_ra);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_ompt_ompt_callback_parallel_end(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  ompt_data_t * parallel_data;
  ompt_data_t * encountering_task_data;
  ompt_parallel_flags_t flags;
  void * codeptr_ra;

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
      parallel_data = (ompt_data_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      encountering_task_data = (ompt_data_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      flags = (ompt_parallel_flags_t)bt_field_integer_signed_get_value(_event_p_f_m_2);
    }
    {
      const bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 3);
      codeptr_ra = (void *)bt_field_integer_unsigned_get_value(_event_p_f_m_3);
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
        (*((lttng_ust_ompt_ompt_callback_parallel_end_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, parallel_data, encountering_task_data, flags, codeptr_ra);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_ompt_ompt_callback_work(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  ompt_work_t work_type;
  ompt_scope_endpoint_t endpoint;
  ompt_data_t * parallel_data;
  ompt_data_t * task_data;
  uint64_t count;
  void * codeptr_ra;

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
      work_type = (ompt_work_t)bt_field_integer_signed_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      endpoint = (ompt_scope_endpoint_t)bt_field_integer_signed_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      parallel_data = (ompt_data_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_2);
    }
    {
      const bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 3);
      task_data = (ompt_data_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_3);
    }
    {
      const bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 4);
      count = (uint64_t)bt_field_integer_unsigned_get_value(_event_p_f_m_4);
    }
    {
      const bt_field *_event_p_f_m_5 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 5);
      codeptr_ra = (void *)bt_field_integer_unsigned_get_value(_event_p_f_m_5);
    }
  }

  const bt_clock_snapshot *clock_snapshot =
      bt_message_event_borrow_default_clock_snapshot_const(upstream_message);
  bt_clock_snapshot_get_ns_from_origin(clock_snapshot, &_timestamp);
  const char *_event_class_name = "lttng_ust_ompt:ompt_callback_work";

  // Call registered matching callbacks
  {
    if (callbacks->automatic) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->automatic, _p))) {
        (*((lttng_ust_ompt_ompt_callback_work_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, work_type, endpoint, parallel_data, task_data, count, codeptr_ra);
      }
    }
  }

  {
    if (callbacks->matching_btx_host) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->matching_btx_host, _p))) {
        (*((btx_host_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, _event_class_name, hostname, vpid, vtid, endpoint);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_ompt_ompt_callback_dispatch(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  ompt_data_t * parallel_data;
  ompt_data_t * task_data;
  ompt_dispatch_t kind;
  ompt_data_t instance;

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
      parallel_data = (ompt_data_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      task_data = (ompt_data_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      kind = (ompt_dispatch_t)bt_field_integer_signed_get_value(_event_p_f_m_2);
    }
    {
      const bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 3);
      // Dump string data to the struct.
      memcpy(&instance, bt_field_string_get_value(_event_p_f_m_3), sizeof(instance));
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
        (*((lttng_ust_ompt_ompt_callback_dispatch_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, parallel_data, task_data, kind, instance);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_ompt_ompt_callback_task_create(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  ompt_data_t * encountering_task_data;
  ompt_frame_t * encountering_task_frame;
  ompt_data_t * new_task_data;
  ompt_task_flags_t flags;
  int has_dependences;
  void * codeptr_ra;

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
      encountering_task_data = (ompt_data_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      encountering_task_frame = (ompt_frame_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      new_task_data = (ompt_data_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_2);
    }
    {
      const bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 3);
      flags = (ompt_task_flags_t)bt_field_integer_signed_get_value(_event_p_f_m_3);
    }
    {
      const bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 4);
      has_dependences = (int)bt_field_integer_signed_get_value(_event_p_f_m_4);
    }
    {
      const bt_field *_event_p_f_m_5 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 5);
      codeptr_ra = (void *)bt_field_integer_unsigned_get_value(_event_p_f_m_5);
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
        (*((lttng_ust_ompt_ompt_callback_task_create_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, encountering_task_data, encountering_task_frame, new_task_data, flags, has_dependences, codeptr_ra);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_ompt_ompt_callback_dependences(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  ompt_data_t * task_data;
  ompt_dependence_t * deps;
  int ndeps;

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
      task_data = (ompt_data_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      deps = (ompt_dependence_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      ndeps = (int)bt_field_integer_signed_get_value(_event_p_f_m_2);
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
        (*((lttng_ust_ompt_ompt_callback_dependences_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, task_data, deps, ndeps);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_ompt_ompt_callback_task_dependence(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  ompt_data_t * src_task_data;
  ompt_data_t * sink_task_data;

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
      src_task_data = (ompt_data_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      sink_task_data = (ompt_data_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
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
        (*((lttng_ust_ompt_ompt_callback_task_dependence_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, src_task_data, sink_task_data);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_ompt_ompt_callback_task_schedule(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  ompt_data_t * prior_task_data;
  ompt_task_status_t prior_task_status;
  ompt_data_t * next_task_data;

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
      prior_task_data = (ompt_data_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      prior_task_status = (ompt_task_status_t)bt_field_integer_signed_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      next_task_data = (ompt_data_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_2);
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
        (*((lttng_ust_ompt_ompt_callback_task_schedule_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, prior_task_data, prior_task_status, next_task_data);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_ompt_ompt_callback_implicit_task(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  ompt_scope_endpoint_t endpoint;
  ompt_data_t * parallel_data;
  ompt_data_t * task_data;
  unsigned int actual_parallelism;
  unsigned int index;
  ompt_task_flags_t flags;

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
      endpoint = (ompt_scope_endpoint_t)bt_field_integer_signed_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      parallel_data = (ompt_data_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      task_data = (ompt_data_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_2);
    }
    {
      const bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 3);
      actual_parallelism = (unsigned int)bt_field_integer_unsigned_get_value(_event_p_f_m_3);
    }
    {
      const bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 4);
      index = (unsigned int)bt_field_integer_unsigned_get_value(_event_p_f_m_4);
    }
    {
      const bt_field *_event_p_f_m_5 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 5);
      flags = (ompt_task_flags_t)bt_field_integer_signed_get_value(_event_p_f_m_5);
    }
  }

  const bt_clock_snapshot *clock_snapshot =
      bt_message_event_borrow_default_clock_snapshot_const(upstream_message);
  bt_clock_snapshot_get_ns_from_origin(clock_snapshot, &_timestamp);
  const char *_event_class_name = "lttng_ust_ompt:ompt_callback_implicit_task";

  // Call registered matching callbacks
  {
    if (callbacks->automatic) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->automatic, _p))) {
        (*((lttng_ust_ompt_ompt_callback_implicit_task_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, endpoint, parallel_data, task_data, actual_parallelism, index, flags);
      }
    }
  }

  {
    if (callbacks->matching_btx_host) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->matching_btx_host, _p))) {
        (*((btx_host_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, _event_class_name, hostname, vpid, vtid, endpoint);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_ompt_ompt_callback_masked(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  ompt_scope_endpoint_t endpoint;
  ompt_data_t * parallel_data;
  ompt_data_t * task_data;
  void * codeptr_ra;

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
      endpoint = (ompt_scope_endpoint_t)bt_field_integer_signed_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      parallel_data = (ompt_data_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      task_data = (ompt_data_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_2);
    }
    {
      const bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 3);
      codeptr_ra = (void *)bt_field_integer_unsigned_get_value(_event_p_f_m_3);
    }
  }

  const bt_clock_snapshot *clock_snapshot =
      bt_message_event_borrow_default_clock_snapshot_const(upstream_message);
  bt_clock_snapshot_get_ns_from_origin(clock_snapshot, &_timestamp);
  const char *_event_class_name = "lttng_ust_ompt:ompt_callback_masked";

  // Call registered matching callbacks
  {
    if (callbacks->automatic) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->automatic, _p))) {
        (*((lttng_ust_ompt_ompt_callback_masked_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, endpoint, parallel_data, task_data, codeptr_ra);
      }
    }
  }

  {
    if (callbacks->matching_btx_host) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->matching_btx_host, _p))) {
        (*((btx_host_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, _event_class_name, hostname, vpid, vtid, endpoint);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_ompt_ompt_callback_sync_region(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  ompt_sync_region_t kind;
  ompt_scope_endpoint_t endpoint;
  ompt_data_t * parallel_data;
  ompt_data_t * task_data;
  void * codeptr_ra;

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
      kind = (ompt_sync_region_t)bt_field_integer_signed_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      endpoint = (ompt_scope_endpoint_t)bt_field_integer_signed_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      parallel_data = (ompt_data_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_2);
    }
    {
      const bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 3);
      task_data = (ompt_data_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_3);
    }
    {
      const bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 4);
      codeptr_ra = (void *)bt_field_integer_unsigned_get_value(_event_p_f_m_4);
    }
  }

  const bt_clock_snapshot *clock_snapshot =
      bt_message_event_borrow_default_clock_snapshot_const(upstream_message);
  bt_clock_snapshot_get_ns_from_origin(clock_snapshot, &_timestamp);
  const char *_event_class_name = "lttng_ust_ompt:ompt_callback_sync_region";

  // Call registered matching callbacks
  {
    if (callbacks->automatic) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->automatic, _p))) {
        (*((lttng_ust_ompt_ompt_callback_sync_region_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, kind, endpoint, parallel_data, task_data, codeptr_ra);
      }
    }
  }

  {
    if (callbacks->matching_btx_host_sync_region) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->matching_btx_host_sync_region, _p))) {
        (*((btx_host_sync_region_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, _event_class_name, hostname, vpid, vtid, kind, endpoint);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_ompt_ompt_callback_mutex_acquire(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  ompt_mutex_t kind;
  unsigned int hint;
  unsigned int impl;
  ompt_wait_id_t wait_id;
  void * codeptr_ra;

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
      kind = (ompt_mutex_t)bt_field_integer_signed_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      hint = (unsigned int)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      impl = (unsigned int)bt_field_integer_unsigned_get_value(_event_p_f_m_2);
    }
    {
      const bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 3);
      wait_id = (ompt_wait_id_t)bt_field_integer_unsigned_get_value(_event_p_f_m_3);
    }
    {
      const bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 4);
      codeptr_ra = (void *)bt_field_integer_unsigned_get_value(_event_p_f_m_4);
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
        (*((lttng_ust_ompt_ompt_callback_mutex_acquire_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, kind, hint, impl, wait_id, codeptr_ra);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_ompt_ompt_callback_mutex(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  ompt_mutex_t kind;
  ompt_wait_id_t wait_id;
  void * codeptr_ra;

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
      kind = (ompt_mutex_t)bt_field_integer_signed_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      wait_id = (ompt_wait_id_t)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      codeptr_ra = (void *)bt_field_integer_unsigned_get_value(_event_p_f_m_2);
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
        (*((lttng_ust_ompt_ompt_callback_mutex_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, kind, wait_id, codeptr_ra);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_ompt_ompt_callback_nest_lock(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  ompt_scope_endpoint_t endpoint;
  ompt_wait_id_t wait_id;
  void * codeptr_ra;

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
      endpoint = (ompt_scope_endpoint_t)bt_field_integer_signed_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      wait_id = (ompt_wait_id_t)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      codeptr_ra = (void *)bt_field_integer_unsigned_get_value(_event_p_f_m_2);
    }
  }

  const bt_clock_snapshot *clock_snapshot =
      bt_message_event_borrow_default_clock_snapshot_const(upstream_message);
  bt_clock_snapshot_get_ns_from_origin(clock_snapshot, &_timestamp);
  const char *_event_class_name = "lttng_ust_ompt:ompt_callback_nest_lock";

  // Call registered matching callbacks
  {
    if (callbacks->automatic) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->automatic, _p))) {
        (*((lttng_ust_ompt_ompt_callback_nest_lock_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, endpoint, wait_id, codeptr_ra);
      }
    }
  }

  {
    if (callbacks->matching_btx_host) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->matching_btx_host, _p))) {
        (*((btx_host_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, _event_class_name, hostname, vpid, vtid, endpoint);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_ompt_ompt_callback_flush(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  ompt_data_t * thread_data;
  void * codeptr_ra;

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
      thread_data = (ompt_data_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      codeptr_ra = (void *)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
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
        (*((lttng_ust_ompt_ompt_callback_flush_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, thread_data, codeptr_ra);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_ompt_ompt_callback_cancel(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  ompt_data_t * task_data;
  ompt_cancel_flags_t flags;
  void * codeptr_ra;

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
      task_data = (ompt_data_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      flags = (ompt_cancel_flags_t)bt_field_integer_signed_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      codeptr_ra = (void *)bt_field_integer_unsigned_get_value(_event_p_f_m_2);
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
        (*((lttng_ust_ompt_ompt_callback_cancel_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, task_data, flags, codeptr_ra);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_ompt_ompt_callback_device_initialize(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  int device_num;
  char * type;
  ompt_device_t * device;
  ompt_function_lookup_t lookup;
  char * documentation;

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
      device_num = (int)bt_field_integer_signed_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      type = (char *)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      device = (ompt_device_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_2);
    }
    {
      const bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 3);
      lookup = (ompt_function_lookup_t)bt_field_integer_unsigned_get_value(_event_p_f_m_3);
    }
    {
      const bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 4);
      documentation = (char *)bt_field_integer_unsigned_get_value(_event_p_f_m_4);
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
        (*((lttng_ust_ompt_ompt_callback_device_initialize_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, device_num, type, device, lookup, documentation);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_ompt_ompt_callback_device_finalize(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  int device_num;

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
      device_num = (int)bt_field_integer_signed_get_value(_event_p_f_m_0);
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
        (*((lttng_ust_ompt_ompt_callback_device_finalize_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, device_num);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_ompt_ompt_callback_device_load(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  int device_num;
  char * filename;
  int64_t offset_in_file;
  void * vma_in_file;
  size_t bytes;
  void * host_addr;
  void * device_addr;
  uint64_t module_id;

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
      device_num = (int)bt_field_integer_signed_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      filename = (char *)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      offset_in_file = (int64_t)bt_field_integer_signed_get_value(_event_p_f_m_2);
    }
    {
      const bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 3);
      vma_in_file = (void *)bt_field_integer_unsigned_get_value(_event_p_f_m_3);
    }
    {
      const bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 4);
      bytes = (size_t)bt_field_integer_unsigned_get_value(_event_p_f_m_4);
    }
    {
      const bt_field *_event_p_f_m_5 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 5);
      host_addr = (void *)bt_field_integer_unsigned_get_value(_event_p_f_m_5);
    }
    {
      const bt_field *_event_p_f_m_6 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 6);
      device_addr = (void *)bt_field_integer_unsigned_get_value(_event_p_f_m_6);
    }
    {
      const bt_field *_event_p_f_m_7 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 7);
      module_id = (uint64_t)bt_field_integer_unsigned_get_value(_event_p_f_m_7);
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
        (*((lttng_ust_ompt_ompt_callback_device_load_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, device_num, filename, offset_in_file, vma_in_file, bytes, host_addr, device_addr, module_id);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_ompt_ompt_callback_device_unload(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  int device_num;
  uint64_t module_id;

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
      device_num = (int)bt_field_integer_signed_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      module_id = (uint64_t)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
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
        (*((lttng_ust_ompt_ompt_callback_device_unload_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, device_num, module_id);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_ompt_ompt_callback_target_data_op_emi(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  ompt_scope_endpoint_t endpoint;
  ompt_data_t * target_task_data;
  ompt_data_t * target_data;
  ompt_id_t * host_op_id;
  ompt_target_data_op_t optype;
  void * src_addr;
  int src_device_num;
  void * dest_addr;
  int dest_device_num;
  size_t bytes;
  void * codeptr_ra;

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
      endpoint = (ompt_scope_endpoint_t)bt_field_integer_signed_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      target_task_data = (ompt_data_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      target_data = (ompt_data_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_2);
    }
    {
      const bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 3);
      host_op_id = (ompt_id_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_3);
    }
    {
      const bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 4);
      optype = (ompt_target_data_op_t)bt_field_integer_signed_get_value(_event_p_f_m_4);
    }
    {
      const bt_field *_event_p_f_m_5 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 5);
      src_addr = (void *)bt_field_integer_unsigned_get_value(_event_p_f_m_5);
    }
    {
      const bt_field *_event_p_f_m_6 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 6);
      src_device_num = (int)bt_field_integer_signed_get_value(_event_p_f_m_6);
    }
    {
      const bt_field *_event_p_f_m_7 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 7);
      dest_addr = (void *)bt_field_integer_unsigned_get_value(_event_p_f_m_7);
    }
    {
      const bt_field *_event_p_f_m_8 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 8);
      dest_device_num = (int)bt_field_integer_signed_get_value(_event_p_f_m_8);
    }
    {
      const bt_field *_event_p_f_m_9 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 9);
      bytes = (size_t)bt_field_integer_unsigned_get_value(_event_p_f_m_9);
    }
    {
      const bt_field *_event_p_f_m_10 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 10);
      codeptr_ra = (void *)bt_field_integer_unsigned_get_value(_event_p_f_m_10);
    }
  }

  const bt_clock_snapshot *clock_snapshot =
      bt_message_event_borrow_default_clock_snapshot_const(upstream_message);
  bt_clock_snapshot_get_ns_from_origin(clock_snapshot, &_timestamp);
  const char *_event_class_name = "lttng_ust_ompt:ompt_callback_target_data_op_emi";

  // Call registered matching callbacks
  {
    if (callbacks->automatic) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->automatic, _p))) {
        (*((lttng_ust_ompt_ompt_callback_target_data_op_emi_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, endpoint, target_task_data, target_data, host_op_id, optype, src_addr, src_device_num, dest_addr, dest_device_num, bytes, codeptr_ra);
      }
    }
  }

  {
    if (callbacks->matching_btx_host_target_data) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->matching_btx_host_target_data, _p))) {
        (*((btx_host_target_data_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, _event_class_name, hostname, vpid, vtid, endpoint, optype);
      }
    }
  }

  {
    if (callbacks->matching_btx_traffic_target_data) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->matching_btx_traffic_target_data, _p))) {
        (*((btx_traffic_target_data_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, _event_class_name, hostname, vpid, vtid, endpoint, optype, bytes);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_ompt_ompt_callback_target_data_op(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  ompt_id_t target_id;
  ompt_id_t host_op_id;
  ompt_target_data_op_t optype;
  void * src_addr;
  int src_device_num;
  void * dest_addr;
  int dest_device_num;
  size_t bytes;
  void * codeptr_ra;

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
      target_id = (ompt_id_t)bt_field_integer_unsigned_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      host_op_id = (ompt_id_t)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      optype = (ompt_target_data_op_t)bt_field_integer_signed_get_value(_event_p_f_m_2);
    }
    {
      const bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 3);
      src_addr = (void *)bt_field_integer_unsigned_get_value(_event_p_f_m_3);
    }
    {
      const bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 4);
      src_device_num = (int)bt_field_integer_signed_get_value(_event_p_f_m_4);
    }
    {
      const bt_field *_event_p_f_m_5 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 5);
      dest_addr = (void *)bt_field_integer_unsigned_get_value(_event_p_f_m_5);
    }
    {
      const bt_field *_event_p_f_m_6 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 6);
      dest_device_num = (int)bt_field_integer_signed_get_value(_event_p_f_m_6);
    }
    {
      const bt_field *_event_p_f_m_7 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 7);
      bytes = (size_t)bt_field_integer_unsigned_get_value(_event_p_f_m_7);
    }
    {
      const bt_field *_event_p_f_m_8 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 8);
      codeptr_ra = (void *)bt_field_integer_unsigned_get_value(_event_p_f_m_8);
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
        (*((lttng_ust_ompt_ompt_callback_target_data_op_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, target_id, host_op_id, optype, src_addr, src_device_num, dest_addr, dest_device_num, bytes, codeptr_ra);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_ompt_ompt_callback_target_emi(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  ompt_target_t kind;
  ompt_scope_endpoint_t endpoint;
  int device_num;
  ompt_data_t * task_data;
  ompt_data_t * target_task_data;
  ompt_data_t * target_data;
  void * codeptr_ra;

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
      kind = (ompt_target_t)bt_field_integer_signed_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      endpoint = (ompt_scope_endpoint_t)bt_field_integer_signed_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      device_num = (int)bt_field_integer_signed_get_value(_event_p_f_m_2);
    }
    {
      const bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 3);
      task_data = (ompt_data_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_3);
    }
    {
      const bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 4);
      target_task_data = (ompt_data_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_4);
    }
    {
      const bt_field *_event_p_f_m_5 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 5);
      target_data = (ompt_data_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_5);
    }
    {
      const bt_field *_event_p_f_m_6 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 6);
      codeptr_ra = (void *)bt_field_integer_unsigned_get_value(_event_p_f_m_6);
    }
  }

  const bt_clock_snapshot *clock_snapshot =
      bt_message_event_borrow_default_clock_snapshot_const(upstream_message);
  bt_clock_snapshot_get_ns_from_origin(clock_snapshot, &_timestamp);
  const char *_event_class_name = "lttng_ust_ompt:ompt_callback_target_emi";

  // Call registered matching callbacks
  {
    if (callbacks->automatic) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->automatic, _p))) {
        (*((lttng_ust_ompt_ompt_callback_target_emi_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, kind, endpoint, device_num, task_data, target_task_data, target_data, codeptr_ra);
      }
    }
  }

  {
    if (callbacks->matching_btx_host_target) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->matching_btx_host_target, _p))) {
        (*((btx_host_target_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, _event_class_name, hostname, vpid, vtid, kind, endpoint);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_ompt_ompt_callback_target(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  ompt_target_t kind;
  ompt_scope_endpoint_t endpoint;
  int device_num;
  ompt_data_t * task_data;
  ompt_id_t target_id;
  void * codeptr_ra;

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
      kind = (ompt_target_t)bt_field_integer_signed_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      endpoint = (ompt_scope_endpoint_t)bt_field_integer_signed_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      device_num = (int)bt_field_integer_signed_get_value(_event_p_f_m_2);
    }
    {
      const bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 3);
      task_data = (ompt_data_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_3);
    }
    {
      const bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 4);
      target_id = (ompt_id_t)bt_field_integer_unsigned_get_value(_event_p_f_m_4);
    }
    {
      const bt_field *_event_p_f_m_5 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 5);
      codeptr_ra = (void *)bt_field_integer_unsigned_get_value(_event_p_f_m_5);
    }
  }

  const bt_clock_snapshot *clock_snapshot =
      bt_message_event_borrow_default_clock_snapshot_const(upstream_message);
  bt_clock_snapshot_get_ns_from_origin(clock_snapshot, &_timestamp);
  const char *_event_class_name = "lttng_ust_ompt:ompt_callback_target";

  // Call registered matching callbacks
  {
    if (callbacks->automatic) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->automatic, _p))) {
        (*((lttng_ust_ompt_ompt_callback_target_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, kind, endpoint, device_num, task_data, target_id, codeptr_ra);
      }
    }
  }

  {
    if (callbacks->matching_btx_host_target) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->matching_btx_host_target, _p))) {
        (*((btx_host_target_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, _event_class_name, hostname, vpid, vtid, kind, endpoint);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_ompt_ompt_callback_target_map_emi(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  ompt_data_t * target_data;
  unsigned int nitems;
  void ** host_addr;
  void ** device_addr;
  size_t * bytes;
  unsigned int * mapping_flags;
  void * codeptr_ra;

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
      target_data = (ompt_data_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      nitems = (unsigned int)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      host_addr = (void **)bt_field_integer_unsigned_get_value(_event_p_f_m_2);
    }
    {
      const bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 3);
      device_addr = (void **)bt_field_integer_unsigned_get_value(_event_p_f_m_3);
    }
    {
      const bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 4);
      bytes = (size_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_4);
    }
    {
      const bt_field *_event_p_f_m_5 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 5);
      mapping_flags = (unsigned int *)bt_field_integer_unsigned_get_value(_event_p_f_m_5);
    }
    {
      const bt_field *_event_p_f_m_6 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 6);
      codeptr_ra = (void *)bt_field_integer_unsigned_get_value(_event_p_f_m_6);
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
        (*((lttng_ust_ompt_ompt_callback_target_map_emi_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, target_data, nitems, host_addr, device_addr, bytes, mapping_flags, codeptr_ra);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_ompt_ompt_callback_target_map(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  ompt_id_t target_id;
  unsigned int nitems;
  void ** host_addr;
  void ** device_addr;
  size_t * bytes;
  ompt_target_map_flags_t * mapping_flags;
  void * codeptr_ra;
  size_t _host_addr_vals_length;
  void * * host_addr_vals;
  size_t _device_addr_vals_length;
  void * * device_addr_vals;
  size_t _bytes_vals_length;
  size_t * bytes_vals;
  size_t _mapping_flags_vals_length;
  ompt_target_map_flags_t * mapping_flags_vals;

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
      target_id = (ompt_id_t)bt_field_integer_unsigned_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      nitems = (unsigned int)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      host_addr = (void **)bt_field_integer_unsigned_get_value(_event_p_f_m_2);
    }
    {
      const bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 3);
      device_addr = (void **)bt_field_integer_unsigned_get_value(_event_p_f_m_3);
    }
    {
      const bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 4);
      bytes = (size_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_4);
    }
    {
      const bt_field *_event_p_f_m_5 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 5);
      mapping_flags = (ompt_target_map_flags_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_5);
    }
    {
      const bt_field *_event_p_f_m_6 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 6);
      codeptr_ra = (void *)bt_field_integer_unsigned_get_value(_event_p_f_m_6);
    }
    {
      const bt_field *_event_p_f_m_7 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 7);
      _host_addr_vals_length = (size_t)bt_field_integer_unsigned_get_value(_event_p_f_m_7);
    }
    {
      const bt_field *_event_p_f_m_8 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 8);
      uint64_t _event_p_f_m_8_length = bt_field_array_get_length(_event_p_f_m_8);
      host_addr_vals = (void * *) malloc(_event_p_f_m_8_length * sizeof(host_addr_vals));
      for(uint64_t _i=0; _i < _event_p_f_m_8_length ; _i++)
      {
        const bt_field* _event_p_f_m_8_e = bt_field_array_borrow_element_field_by_index_const(_event_p_f_m_8, _i);
        host_addr_vals[_i] = (void *)bt_field_integer_unsigned_get_value(_event_p_f_m_8_e);
      }
    }
    {
      const bt_field *_event_p_f_m_9 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 9);
      _device_addr_vals_length = (size_t)bt_field_integer_unsigned_get_value(_event_p_f_m_9);
    }
    {
      const bt_field *_event_p_f_m_10 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 10);
      uint64_t _event_p_f_m_10_length = bt_field_array_get_length(_event_p_f_m_10);
      device_addr_vals = (void * *) malloc(_event_p_f_m_10_length * sizeof(device_addr_vals));
      for(uint64_t _i=0; _i < _event_p_f_m_10_length ; _i++)
      {
        const bt_field* _event_p_f_m_10_e = bt_field_array_borrow_element_field_by_index_const(_event_p_f_m_10, _i);
        device_addr_vals[_i] = (void *)bt_field_integer_unsigned_get_value(_event_p_f_m_10_e);
      }
    }
    {
      const bt_field *_event_p_f_m_11 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 11);
      _bytes_vals_length = (size_t)bt_field_integer_unsigned_get_value(_event_p_f_m_11);
    }
    {
      const bt_field *_event_p_f_m_12 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 12);
      uint64_t _event_p_f_m_12_length = bt_field_array_get_length(_event_p_f_m_12);
      bytes_vals = (size_t *) malloc(_event_p_f_m_12_length * sizeof(bytes_vals));
      for(uint64_t _i=0; _i < _event_p_f_m_12_length ; _i++)
      {
        const bt_field* _event_p_f_m_12_e = bt_field_array_borrow_element_field_by_index_const(_event_p_f_m_12, _i);
        bytes_vals[_i] = (size_t)bt_field_integer_unsigned_get_value(_event_p_f_m_12_e);
      }
    }
    {
      const bt_field *_event_p_f_m_13 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 13);
      _mapping_flags_vals_length = (size_t)bt_field_integer_unsigned_get_value(_event_p_f_m_13);
    }
    {
      const bt_field *_event_p_f_m_14 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 14);
      uint64_t _event_p_f_m_14_length = bt_field_array_get_length(_event_p_f_m_14);
      mapping_flags_vals = (ompt_target_map_flags_t *) malloc(_event_p_f_m_14_length * sizeof(mapping_flags_vals));
      for(uint64_t _i=0; _i < _event_p_f_m_14_length ; _i++)
      {
        const bt_field* _event_p_f_m_14_e = bt_field_array_borrow_element_field_by_index_const(_event_p_f_m_14, _i);
        mapping_flags_vals[_i] = (ompt_target_map_flags_t)bt_field_integer_unsigned_get_value(_event_p_f_m_14_e);
      }
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
        (*((lttng_ust_ompt_ompt_callback_target_map_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, target_id, nitems, host_addr, device_addr, bytes, mapping_flags, codeptr_ra, _host_addr_vals_length, host_addr_vals, _device_addr_vals_length, device_addr_vals, _bytes_vals_length, bytes_vals, _mapping_flags_vals_length, mapping_flags_vals);
      }
    }
  }

  free(host_addr_vals);
  free(device_addr_vals);
  free(bytes_vals);
  free(mapping_flags_vals);
}

static void btx_dispatch_lttng_ust_ompt_ompt_callback_target_submit(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  ompt_id_t target_id;
  ompt_id_t host_op_id;
  unsigned int requested_num_teams;

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
      target_id = (ompt_id_t)bt_field_integer_unsigned_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      host_op_id = (ompt_id_t)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      requested_num_teams = (unsigned int)bt_field_integer_unsigned_get_value(_event_p_f_m_2);
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
        (*((lttng_ust_ompt_ompt_callback_target_submit_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, target_id, host_op_id, requested_num_teams);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_ompt_ompt_callback_target_submit_emi(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  ompt_scope_endpoint_t endpoint;
  ompt_data_t * target_data;
  ompt_id_t * host_op_id;
  unsigned int requested_num_teams;

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
      endpoint = (ompt_scope_endpoint_t)bt_field_integer_signed_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      target_data = (ompt_data_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      host_op_id = (ompt_id_t *)bt_field_integer_unsigned_get_value(_event_p_f_m_2);
    }
    {
      const bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 3);
      requested_num_teams = (unsigned int)bt_field_integer_unsigned_get_value(_event_p_f_m_3);
    }
  }

  const bt_clock_snapshot *clock_snapshot =
      bt_message_event_borrow_default_clock_snapshot_const(upstream_message);
  bt_clock_snapshot_get_ns_from_origin(clock_snapshot, &_timestamp);
  const char *_event_class_name = "lttng_ust_ompt:ompt_callback_target_submit_emi";

  // Call registered matching callbacks
  {
    if (callbacks->automatic) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->automatic, _p))) {
        (*((lttng_ust_ompt_ompt_callback_target_submit_emi_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, endpoint, target_data, host_op_id, requested_num_teams);
      }
    }
  }

  {
    if (callbacks->matching_btx_host) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->matching_btx_host, _p))) {
        (*((btx_host_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, _event_class_name, hostname, vpid, vtid, endpoint);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_ompt_ompt_callback_control_tool(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  int ompResult;
  uint64_t command;
  uint64_t modifier;
  void * arg;
  void * codeptr_ra;

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
      ompResult = (int)bt_field_integer_signed_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      command = (uint64_t)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      modifier = (uint64_t)bt_field_integer_unsigned_get_value(_event_p_f_m_2);
    }
    {
      const bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 3);
      arg = (void *)bt_field_integer_unsigned_get_value(_event_p_f_m_3);
    }
    {
      const bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 4);
      codeptr_ra = (void *)bt_field_integer_unsigned_get_value(_event_p_f_m_4);
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
        (*((lttng_ust_ompt_ompt_callback_control_tool_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, ompResult, command, modifier, arg, codeptr_ra);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_ompt_ompt_callback_error(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  ompt_severity_t severity;
  char * message;
  size_t length;
  void * codeptr_ra;

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
      severity = (ompt_severity_t)bt_field_integer_signed_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      message = (char *)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      length = (size_t)bt_field_integer_unsigned_get_value(_event_p_f_m_2);
    }
    {
      const bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 3);
      codeptr_ra = (void *)bt_field_integer_unsigned_get_value(_event_p_f_m_3);
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
        (*((lttng_ust_ompt_ompt_callback_error_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, severity, message, length, codeptr_ra);
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
  else if(strcmp("matching_btx_host_sync_region", id) == 0) {
    // Add the callbacks to the array
    if (!s->callbacks->matching_btx_host_sync_region)
      utarray_new(s->callbacks->matching_btx_host_sync_region, &ut_ptr_icd);
    utarray_push_back(s->callbacks->matching_btx_host_sync_region, &callback);
  }
  else if(strcmp("matching_btx_host_target", id) == 0) {
    // Add the callbacks to the array
    if (!s->callbacks->matching_btx_host_target)
      utarray_new(s->callbacks->matching_btx_host_target, &ut_ptr_icd);
    utarray_push_back(s->callbacks->matching_btx_host_target, &callback);
  }
  else if(strcmp("matching_btx_host_target_data", id) == 0) {
    // Add the callbacks to the array
    if (!s->callbacks->matching_btx_host_target_data)
      utarray_new(s->callbacks->matching_btx_host_target_data, &ut_ptr_icd);
    utarray_push_back(s->callbacks->matching_btx_host_target_data, &callback);
  }
  else if(strcmp("matching_btx_host", id) == 0) {
    // Add the callbacks to the array
    if (!s->callbacks->matching_btx_host)
      utarray_new(s->callbacks->matching_btx_host, &ut_ptr_icd);
    utarray_push_back(s->callbacks->matching_btx_host, &callback);
  }
  else if(strcmp("matching_btx_traffic_target_data", id) == 0) {
    // Add the callbacks to the array
    if (!s->callbacks->matching_btx_traffic_target_data)
      utarray_new(s->callbacks->matching_btx_traffic_target_data, &ut_ptr_icd);
    utarray_push_back(s->callbacks->matching_btx_traffic_target_data, &callback);
  }
}

void btx_register_callbacks_lttng_ust_ompt_ompt_callback_thread_begin(
    void *btx_handle,
    lttng_ust_ompt_ompt_callback_thread_begin_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_thread_begin",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_thread_begin,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_ompt_ompt_callback_thread_end(
    void *btx_handle,
    lttng_ust_ompt_ompt_callback_thread_end_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_thread_end",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_thread_end,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_ompt_ompt_callback_parallel_begin(
    void *btx_handle,
    lttng_ust_ompt_ompt_callback_parallel_begin_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_parallel_begin",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_parallel_begin,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_ompt_ompt_callback_parallel_end(
    void *btx_handle,
    lttng_ust_ompt_ompt_callback_parallel_end_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_parallel_end",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_parallel_end,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_ompt_ompt_callback_work(
    void *btx_handle,
    lttng_ust_ompt_ompt_callback_work_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_work",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_work,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_ompt_ompt_callback_dispatch(
    void *btx_handle,
    lttng_ust_ompt_ompt_callback_dispatch_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_dispatch",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_dispatch,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_ompt_ompt_callback_task_create(
    void *btx_handle,
    lttng_ust_ompt_ompt_callback_task_create_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_task_create",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_task_create,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_ompt_ompt_callback_dependences(
    void *btx_handle,
    lttng_ust_ompt_ompt_callback_dependences_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_dependences",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_dependences,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_ompt_ompt_callback_task_dependence(
    void *btx_handle,
    lttng_ust_ompt_ompt_callback_task_dependence_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_task_dependence",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_task_dependence,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_ompt_ompt_callback_task_schedule(
    void *btx_handle,
    lttng_ust_ompt_ompt_callback_task_schedule_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_task_schedule",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_task_schedule,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_ompt_ompt_callback_implicit_task(
    void *btx_handle,
    lttng_ust_ompt_ompt_callback_implicit_task_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_implicit_task",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_implicit_task,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_ompt_ompt_callback_masked(
    void *btx_handle,
    lttng_ust_ompt_ompt_callback_masked_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_masked",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_masked,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_ompt_ompt_callback_sync_region(
    void *btx_handle,
    lttng_ust_ompt_ompt_callback_sync_region_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_sync_region",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_sync_region,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_ompt_ompt_callback_mutex_acquire(
    void *btx_handle,
    lttng_ust_ompt_ompt_callback_mutex_acquire_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_mutex_acquire",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_mutex_acquire,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_ompt_ompt_callback_mutex(
    void *btx_handle,
    lttng_ust_ompt_ompt_callback_mutex_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_mutex",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_mutex,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_ompt_ompt_callback_nest_lock(
    void *btx_handle,
    lttng_ust_ompt_ompt_callback_nest_lock_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_nest_lock",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_nest_lock,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_ompt_ompt_callback_flush(
    void *btx_handle,
    lttng_ust_ompt_ompt_callback_flush_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_flush",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_flush,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_ompt_ompt_callback_cancel(
    void *btx_handle,
    lttng_ust_ompt_ompt_callback_cancel_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_cancel",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_cancel,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_ompt_ompt_callback_device_initialize(
    void *btx_handle,
    lttng_ust_ompt_ompt_callback_device_initialize_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_device_initialize",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_device_initialize,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_ompt_ompt_callback_device_finalize(
    void *btx_handle,
    lttng_ust_ompt_ompt_callback_device_finalize_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_device_finalize",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_device_finalize,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_ompt_ompt_callback_device_load(
    void *btx_handle,
    lttng_ust_ompt_ompt_callback_device_load_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_device_load",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_device_load,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_ompt_ompt_callback_device_unload(
    void *btx_handle,
    lttng_ust_ompt_ompt_callback_device_unload_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_device_unload",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_device_unload,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_ompt_ompt_callback_target_data_op_emi(
    void *btx_handle,
    lttng_ust_ompt_ompt_callback_target_data_op_emi_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_target_data_op_emi",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_target_data_op_emi,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_ompt_ompt_callback_target_data_op(
    void *btx_handle,
    lttng_ust_ompt_ompt_callback_target_data_op_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_target_data_op",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_target_data_op,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_ompt_ompt_callback_target_emi(
    void *btx_handle,
    lttng_ust_ompt_ompt_callback_target_emi_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_target_emi",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_target_emi,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_ompt_ompt_callback_target(
    void *btx_handle,
    lttng_ust_ompt_ompt_callback_target_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_target",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_target,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_ompt_ompt_callback_target_map_emi(
    void *btx_handle,
    lttng_ust_ompt_ompt_callback_target_map_emi_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_target_map_emi",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_target_map_emi,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_ompt_ompt_callback_target_map(
    void *btx_handle,
    lttng_ust_ompt_ompt_callback_target_map_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_target_map",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_target_map,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_ompt_ompt_callback_target_submit(
    void *btx_handle,
    lttng_ust_ompt_ompt_callback_target_submit_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_target_submit",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_target_submit,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_ompt_ompt_callback_target_submit_emi(
    void *btx_handle,
    lttng_ust_ompt_ompt_callback_target_submit_emi_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_target_submit_emi",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_target_submit_emi,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_ompt_ompt_callback_control_tool(
    void *btx_handle,
    lttng_ust_ompt_ompt_callback_control_tool_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_control_tool",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_control_tool,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_ompt_ompt_callback_error(
    void *btx_handle,
    lttng_ust_ompt_ompt_callback_error_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_error",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_error,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_btx_host_sync_region(
    void *btx_handle,
    btx_host_sync_region_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_sync_region",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_sync_region,
                        "matching_btx_host_sync_region", (void *)callback);
}
void btx_register_callbacks_btx_host_target(
    void *btx_handle,
    btx_host_target_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_target_emi",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_target_emi,
                        "matching_btx_host_target", (void *)callback);
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_target",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_target,
                        "matching_btx_host_target", (void *)callback);
}
void btx_register_callbacks_btx_host_target_data(
    void *btx_handle,
    btx_host_target_data_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_target_data_op_emi",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_target_data_op_emi,
                        "matching_btx_host_target_data", (void *)callback);
}
void btx_register_callbacks_btx_host(
    void *btx_handle,
    btx_host_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_work",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_work,
                        "matching_btx_host", (void *)callback);
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_implicit_task",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_implicit_task,
                        "matching_btx_host", (void *)callback);
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_masked",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_masked,
                        "matching_btx_host", (void *)callback);
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_nest_lock",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_nest_lock,
                        "matching_btx_host", (void *)callback);
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_target_submit_emi",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_target_submit_emi,
                        "matching_btx_host", (void *)callback);
}
void btx_register_callbacks_btx_traffic_target_data(
    void *btx_handle,
    btx_traffic_target_data_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_ompt:ompt_callback_target_data_op_emi",
                        (void *)&btx_dispatch_lttng_ust_ompt_ompt_callback_target_data_op_emi,
                        "matching_btx_traffic_target_data", (void *)callback);
}
