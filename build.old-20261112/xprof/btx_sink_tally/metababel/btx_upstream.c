#include "utarray.h"
#include "uthash.h"
#include <assert.h>
#include <babeltrace2/babeltrace.h>
#include <metababel/btx_component.h>
#include <metababel/btx_upstream.h>
#include <stdbool.h>
#include <stdlib.h>

static void btx_dispatch_aggreg_host(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  const char* name;
  uint64_t min;
  uint64_t max;
  uint64_t total;
  uint64_t count;
  uint64_t backend;
  uint64_t err_count;

  const bt_event *_event =
      bt_message_event_borrow_event_const(upstream_message);
  {
    const bt_field *_event_cc_f = bt_event_borrow_common_context_field_const(_event);
    {
      const bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 0);
      hostname = (const char*)bt_field_string_get_value(_event_cc_f_m_0);
    }
    {
      const bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 1);
      vpid = (int64_t)bt_field_integer_signed_get_value(_event_cc_f_m_1);
    }
    {
      const bt_field *_event_cc_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 2);
      vtid = (uint64_t)bt_field_integer_unsigned_get_value(_event_cc_f_m_2);
    }
    {
      const bt_field *_event_cc_f_m_3 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 3);
      name = (const char*)bt_field_string_get_value(_event_cc_f_m_3);
    }
    {
      const bt_field *_event_cc_f_m_4 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 4);
      min = (uint64_t)bt_field_integer_unsigned_get_value(_event_cc_f_m_4);
    }
    {
      const bt_field *_event_cc_f_m_5 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 5);
      max = (uint64_t)bt_field_integer_unsigned_get_value(_event_cc_f_m_5);
    }
    {
      const bt_field *_event_cc_f_m_6 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 6);
      total = (uint64_t)bt_field_integer_unsigned_get_value(_event_cc_f_m_6);
    }
    {
      const bt_field *_event_cc_f_m_7 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 7);
      count = (uint64_t)bt_field_integer_unsigned_get_value(_event_cc_f_m_7);
    }
  }
  {
    const bt_field *_event_p_f = bt_event_borrow_payload_field_const(_event);
    {
      const bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 0);
      backend = (uint64_t)bt_field_integer_unsigned_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      err_count = (uint64_t)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
    }
  }


  // Call registered matching callbacks
  {
    if (callbacks->automatic) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->automatic, _p))) {
        (*((aggreg_host_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, hostname, vpid, vtid, name, min, max, total, count, backend, err_count);
      }
    }
  }

}

static void btx_dispatch_aggreg_device(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  const char* name;
  uint64_t min;
  uint64_t max;
  uint64_t total;
  uint64_t count;
  uint64_t did;
  uint64_t sdid;
  const char* metadata;

  const bt_event *_event =
      bt_message_event_borrow_event_const(upstream_message);
  {
    const bt_field *_event_cc_f = bt_event_borrow_common_context_field_const(_event);
    {
      const bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 0);
      hostname = (const char*)bt_field_string_get_value(_event_cc_f_m_0);
    }
    {
      const bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 1);
      vpid = (int64_t)bt_field_integer_signed_get_value(_event_cc_f_m_1);
    }
    {
      const bt_field *_event_cc_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 2);
      vtid = (uint64_t)bt_field_integer_unsigned_get_value(_event_cc_f_m_2);
    }
    {
      const bt_field *_event_cc_f_m_3 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 3);
      name = (const char*)bt_field_string_get_value(_event_cc_f_m_3);
    }
    {
      const bt_field *_event_cc_f_m_4 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 4);
      min = (uint64_t)bt_field_integer_unsigned_get_value(_event_cc_f_m_4);
    }
    {
      const bt_field *_event_cc_f_m_5 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 5);
      max = (uint64_t)bt_field_integer_unsigned_get_value(_event_cc_f_m_5);
    }
    {
      const bt_field *_event_cc_f_m_6 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 6);
      total = (uint64_t)bt_field_integer_unsigned_get_value(_event_cc_f_m_6);
    }
    {
      const bt_field *_event_cc_f_m_7 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 7);
      count = (uint64_t)bt_field_integer_unsigned_get_value(_event_cc_f_m_7);
    }
  }
  {
    const bt_field *_event_p_f = bt_event_borrow_payload_field_const(_event);
    {
      const bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 0);
      did = (uint64_t)bt_field_integer_unsigned_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      sdid = (uint64_t)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      metadata = (const char*)bt_field_string_get_value(_event_p_f_m_2);
    }
  }


  // Call registered matching callbacks
  {
    if (callbacks->automatic) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->automatic, _p))) {
        (*((aggreg_device_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, hostname, vpid, vtid, name, min, max, total, count, did, sdid, metadata);
      }
    }
  }

}

static void btx_dispatch_aggreg_traffic(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  const char* name;
  uint64_t min;
  uint64_t max;
  uint64_t total;
  uint64_t count;
  uint64_t backend;
  const char* metadata;

  const bt_event *_event =
      bt_message_event_borrow_event_const(upstream_message);
  {
    const bt_field *_event_cc_f = bt_event_borrow_common_context_field_const(_event);
    {
      const bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 0);
      hostname = (const char*)bt_field_string_get_value(_event_cc_f_m_0);
    }
    {
      const bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 1);
      vpid = (int64_t)bt_field_integer_signed_get_value(_event_cc_f_m_1);
    }
    {
      const bt_field *_event_cc_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 2);
      vtid = (uint64_t)bt_field_integer_unsigned_get_value(_event_cc_f_m_2);
    }
    {
      const bt_field *_event_cc_f_m_3 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 3);
      name = (const char*)bt_field_string_get_value(_event_cc_f_m_3);
    }
    {
      const bt_field *_event_cc_f_m_4 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 4);
      min = (uint64_t)bt_field_integer_unsigned_get_value(_event_cc_f_m_4);
    }
    {
      const bt_field *_event_cc_f_m_5 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 5);
      max = (uint64_t)bt_field_integer_unsigned_get_value(_event_cc_f_m_5);
    }
    {
      const bt_field *_event_cc_f_m_6 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 6);
      total = (uint64_t)bt_field_integer_unsigned_get_value(_event_cc_f_m_6);
    }
    {
      const bt_field *_event_cc_f_m_7 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 7);
      count = (uint64_t)bt_field_integer_unsigned_get_value(_event_cc_f_m_7);
    }
  }
  {
    const bt_field *_event_p_f = bt_event_borrow_payload_field_const(_event);
    {
      const bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 0);
      backend = (uint64_t)bt_field_integer_unsigned_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      metadata = (const char*)bt_field_string_get_value(_event_p_f_m_1);
    }
  }


  // Call registered matching callbacks
  {
    if (callbacks->automatic) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->automatic, _p))) {
        (*((aggreg_traffic_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, hostname, vpid, vtid, name, min, max, total, count, backend, metadata);
      }
    }
  }

}

static void btx_dispatch_lttng_device_name(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  int64_t ts;
  int64_t backend;
  const char* name;
  uint64_t did;

  const bt_event *_event =
      bt_message_event_borrow_event_const(upstream_message);
  {
    const bt_field *_event_cc_f = bt_event_borrow_common_context_field_const(_event);
    {
      const bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 0);
      hostname = (const char*)bt_field_string_get_value(_event_cc_f_m_0);
    }
    {
      const bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 1);
      vpid = (int64_t)bt_field_integer_signed_get_value(_event_cc_f_m_1);
    }
    {
      const bt_field *_event_cc_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 2);
      vtid = (uint64_t)bt_field_integer_unsigned_get_value(_event_cc_f_m_2);
    }
    {
      const bt_field *_event_cc_f_m_3 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 3);
      ts = (int64_t)bt_field_integer_signed_get_value(_event_cc_f_m_3);
    }
    {
      const bt_field *_event_cc_f_m_4 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 4);
      backend = (int64_t)bt_field_integer_signed_get_value(_event_cc_f_m_4);
    }
  }
  {
    const bt_field *_event_p_f = bt_event_borrow_payload_field_const(_event);
    {
      const bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 0);
      name = (const char*)bt_field_string_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      did = (uint64_t)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
    }
  }


  // Call registered matching callbacks
  {
    if (callbacks->automatic) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->automatic, _p))) {
        (*((lttng_device_name_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, hostname, vpid, vtid, ts, backend, name, did);
      }
    }
  }

}

static void btx_dispatch_lttng_ust_thapi_metadata(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  int64_t ts;
  int64_t backend;
  const char* metadata;

  const bt_event *_event =
      bt_message_event_borrow_event_const(upstream_message);
  {
    const bt_field *_event_cc_f = bt_event_borrow_common_context_field_const(_event);
    {
      const bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 0);
      hostname = (const char*)bt_field_string_get_value(_event_cc_f_m_0);
    }
    {
      const bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 1);
      vpid = (int64_t)bt_field_integer_signed_get_value(_event_cc_f_m_1);
    }
    {
      const bt_field *_event_cc_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 2);
      vtid = (uint64_t)bt_field_integer_unsigned_get_value(_event_cc_f_m_2);
    }
    {
      const bt_field *_event_cc_f_m_3 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 3);
      ts = (int64_t)bt_field_integer_signed_get_value(_event_cc_f_m_3);
    }
    {
      const bt_field *_event_cc_f_m_4 = bt_field_structure_borrow_member_field_by_index_const(_event_cc_f, 4);
      backend = (int64_t)bt_field_integer_signed_get_value(_event_cc_f_m_4);
    }
  }
  {
    const bt_field *_event_p_f = bt_event_borrow_payload_field_const(_event);
    {
      const bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 0);
      metadata = (const char*)bt_field_string_get_value(_event_p_f_m_0);
    }
  }


  // Call registered matching callbacks
  {
    if (callbacks->automatic) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->automatic, _p))) {
        (*((lttng_ust_thapi_metadata_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, hostname, vpid, vtid, ts, backend, metadata);
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

void btx_register_callbacks_aggreg_host(
    void *btx_handle,
    aggreg_host_callback_f *callback) {
  bt_register_callbacks(btx_handle, "aggreg:host",
                        (void *)&btx_dispatch_aggreg_host,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_aggreg_device(
    void *btx_handle,
    aggreg_device_callback_f *callback) {
  bt_register_callbacks(btx_handle, "aggreg:device",
                        (void *)&btx_dispatch_aggreg_device,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_aggreg_traffic(
    void *btx_handle,
    aggreg_traffic_callback_f *callback) {
  bt_register_callbacks(btx_handle, "aggreg:traffic",
                        (void *)&btx_dispatch_aggreg_traffic,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_device_name(
    void *btx_handle,
    lttng_device_name_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng:device_name",
                        (void *)&btx_dispatch_lttng_device_name,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_ust_thapi_metadata(
    void *btx_handle,
    lttng_ust_thapi_metadata_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng_ust_thapi:metadata",
                        (void *)&btx_dispatch_lttng_ust_thapi_metadata,
                        "automatic", (void *)callback);
}
