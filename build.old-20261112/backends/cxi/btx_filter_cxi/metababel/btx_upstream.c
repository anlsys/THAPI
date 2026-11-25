#include "utarray.h"
#include "uthash.h"
#include <assert.h>
#include <babeltrace2/babeltrace.h>
#include <metababel/btx_component.h>
#include <metababel/btx_upstream.h>
#include <stdbool.h>
#include <stdlib.h>

static void btx_dispatch_lttng_ust_cxi_sampling_cxi(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  int64_t _timestamp;
  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  char * interface_name;
  char * counter;
  uint64_t value;

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
      interface_name = (char *)bt_field_string_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      counter = (char *)bt_field_string_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      value = (uint64_t)bt_field_integer_unsigned_get_value(_event_p_f_m_2);
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
        (*((lttng_ust_cxi_sampling_cxi_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, _timestamp, hostname, vpid, vtid, interface_name, counter, value);
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

void btx_register_callbacks_lttng_ust_cxi_sampling_cxi(
    void *btx_handle,
    lttng_ust_cxi_sampling_cxi_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_cxi_sampling:cxi",
                        (void *)&btx_dispatch_lttng_ust_cxi_sampling_cxi,
                        "automatic", (void *)callback);
}
