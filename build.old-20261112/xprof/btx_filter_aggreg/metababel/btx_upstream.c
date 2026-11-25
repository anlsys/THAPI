#include "utarray.h"
#include "uthash.h"
#include <assert.h>
#include <babeltrace2/babeltrace.h>
#include <metababel/btx_component.h>
#include <metababel/btx_upstream.h>
#include <stdbool.h>
#include <stdlib.h>

static void btx_dispatch_lttng_host(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  int64_t ts;
  int64_t backend;
  const char* name;
  uint64_t dur;
  bt_bool err;

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
      dur = (uint64_t)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      err = (bt_bool)bt_field_bool_get_value(_event_p_f_m_2);
    }
  }


  // Call registered matching callbacks
  {
    if (callbacks->automatic) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->automatic, _p))) {
        (*((lttng_host_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, hostname, vpid, vtid, ts, backend, name, dur, err);
      }
    }
  }

}

static void btx_dispatch_lttng_device(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  int64_t ts;
  int64_t backend;
  const char* name;
  uint64_t dur;
  uint64_t did;
  uint64_t sdid;
  bt_bool err;
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
      name = (const char*)bt_field_string_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      dur = (uint64_t)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      did = (uint64_t)bt_field_integer_unsigned_get_value(_event_p_f_m_2);
    }
    {
      const bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 3);
      sdid = (uint64_t)bt_field_integer_unsigned_get_value(_event_p_f_m_3);
    }
    {
      const bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 4);
      err = (bt_bool)bt_field_bool_get_value(_event_p_f_m_4);
    }
    {
      const bt_field *_event_p_f_m_5 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 5);
      metadata = (const char*)bt_field_string_get_value(_event_p_f_m_5);
    }
  }


  // Call registered matching callbacks
  {
    if (callbacks->automatic) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->automatic, _p))) {
        (*((lttng_device_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, hostname, vpid, vtid, ts, backend, name, dur, did, sdid, err, metadata);
      }
    }
  }

}

static void btx_dispatch_lttng_traffic(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  const char* hostname;
  int64_t vpid;
  uint64_t vtid;
  int64_t ts;
  int64_t backend;
  const char* name;
  uint64_t size;
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
      name = (const char*)bt_field_string_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      size = (uint64_t)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
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
        (*((lttng_traffic_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, hostname, vpid, vtid, ts, backend, name, size, metadata);
      }
    }
  }

}

static void btx_dispatch_sampling_frequency(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  const char* hostname;
  int64_t ts;
  uint64_t did;
  uint32_t deviceIdx;
  uint64_t hFrequency;
  uint32_t domain;
  uint64_t frequency;

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
      ts = (int64_t)bt_field_integer_signed_get_value(_event_cc_f_m_1);
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
      deviceIdx = (uint32_t)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      hFrequency = (uint64_t)bt_field_integer_unsigned_get_value(_event_p_f_m_2);
    }
    {
      const bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 3);
      domain = (uint32_t)bt_field_integer_unsigned_get_value(_event_p_f_m_3);
    }
    {
      const bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 4);
      frequency = (uint64_t)bt_field_integer_unsigned_get_value(_event_p_f_m_4);
    }
  }


  // Call registered matching callbacks
  {
    if (callbacks->automatic) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->automatic, _p))) {
        (*((sampling_frequency_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, hostname, ts, did, deviceIdx, hFrequency, domain, frequency);
      }
    }
  }

}

static void btx_dispatch_sampling_power(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  const char* hostname;
  int64_t ts;
  uint64_t did;
  uint32_t deviceIdx;
  uint64_t hPower;
  uint32_t domain;
  uint64_t power;

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
      ts = (int64_t)bt_field_integer_signed_get_value(_event_cc_f_m_1);
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
      deviceIdx = (uint32_t)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      hPower = (uint64_t)bt_field_integer_unsigned_get_value(_event_p_f_m_2);
    }
    {
      const bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 3);
      domain = (uint32_t)bt_field_integer_unsigned_get_value(_event_p_f_m_3);
    }
    {
      const bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 4);
      power = (uint64_t)bt_field_integer_unsigned_get_value(_event_p_f_m_4);
    }
  }


  // Call registered matching callbacks
  {
    if (callbacks->automatic) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->automatic, _p))) {
        (*((sampling_power_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, hostname, ts, did, deviceIdx, hPower, domain, power);
      }
    }
  }

}

static void btx_dispatch_sampling_computeEU(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  const char* hostname;
  int64_t ts;
  uint64_t did;
  uint32_t deviceIdx;
  uint64_t hEngine;
  uint32_t subDevice;
  float activeTime;

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
      ts = (int64_t)bt_field_integer_signed_get_value(_event_cc_f_m_1);
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
      deviceIdx = (uint32_t)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      hEngine = (uint64_t)bt_field_integer_unsigned_get_value(_event_p_f_m_2);
    }
    {
      const bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 3);
      subDevice = (uint32_t)bt_field_integer_unsigned_get_value(_event_p_f_m_3);
    }
    {
      const bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 4);
      activeTime = (float)bt_field_real_single_precision_get_value(_event_p_f_m_4);
    }
  }


  // Call registered matching callbacks
  {
    if (callbacks->automatic) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->automatic, _p))) {
        (*((sampling_computeEU_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, hostname, ts, did, deviceIdx, hEngine, subDevice, activeTime);
      }
    }
  }

}

static void btx_dispatch_sampling_copyEU(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  const char* hostname;
  int64_t ts;
  uint64_t did;
  uint32_t deviceIdx;
  uint64_t hEngine;
  uint32_t subDevice;
  float activeTime;

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
      ts = (int64_t)bt_field_integer_signed_get_value(_event_cc_f_m_1);
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
      deviceIdx = (uint32_t)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      hEngine = (uint64_t)bt_field_integer_unsigned_get_value(_event_p_f_m_2);
    }
    {
      const bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 3);
      subDevice = (uint32_t)bt_field_integer_unsigned_get_value(_event_p_f_m_3);
    }
    {
      const bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 4);
      activeTime = (float)bt_field_real_single_precision_get_value(_event_p_f_m_4);
    }
  }


  // Call registered matching callbacks
  {
    if (callbacks->automatic) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->automatic, _p))) {
        (*((sampling_copyEU_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, hostname, ts, did, deviceIdx, hEngine, subDevice, activeTime);
      }
    }
  }

}

static void btx_dispatch_sampling_fabricPort(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  const char* hostname;
  int64_t ts;
  uint64_t did;
  uint32_t deviceIdx;
  uint64_t hFabricPort;
  uint32_t subDevice;
  uint32_t portId;
  uint32_t remotePortId;
  float rxThroughput;
  float txThroughput;
  float rxSpeed;
  float txSpeed;

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
      ts = (int64_t)bt_field_integer_signed_get_value(_event_cc_f_m_1);
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
      deviceIdx = (uint32_t)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      hFabricPort = (uint64_t)bt_field_integer_unsigned_get_value(_event_p_f_m_2);
    }
    {
      const bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 3);
      subDevice = (uint32_t)bt_field_integer_unsigned_get_value(_event_p_f_m_3);
    }
    {
      const bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 4);
      portId = (uint32_t)bt_field_integer_unsigned_get_value(_event_p_f_m_4);
    }
    {
      const bt_field *_event_p_f_m_5 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 5);
      remotePortId = (uint32_t)bt_field_integer_unsigned_get_value(_event_p_f_m_5);
    }
    {
      const bt_field *_event_p_f_m_6 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 6);
      rxThroughput = (float)bt_field_real_double_precision_get_value(_event_p_f_m_6);
    }
    {
      const bt_field *_event_p_f_m_7 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 7);
      txThroughput = (float)bt_field_real_double_precision_get_value(_event_p_f_m_7);
    }
    {
      const bt_field *_event_p_f_m_8 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 8);
      rxSpeed = (float)bt_field_real_double_precision_get_value(_event_p_f_m_8);
    }
    {
      const bt_field *_event_p_f_m_9 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 9);
      txSpeed = (float)bt_field_real_double_precision_get_value(_event_p_f_m_9);
    }
  }


  // Call registered matching callbacks
  {
    if (callbacks->automatic) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->automatic, _p))) {
        (*((sampling_fabricPort_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, hostname, ts, did, deviceIdx, hFabricPort, subDevice, portId, remotePortId, rxThroughput, txThroughput, rxSpeed, txSpeed);
      }
    }
  }

}

static void btx_dispatch_sampling_memModule(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  const char* hostname;
  int64_t ts;
  uint64_t did;
  uint32_t deviceIdx;
  uint64_t hMemModule;
  uint32_t subDevice;
  float pBandwidth;
  float rdBandwidth;
  float wtBandwidth;
  float occupancy;

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
      ts = (int64_t)bt_field_integer_signed_get_value(_event_cc_f_m_1);
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
      deviceIdx = (uint32_t)bt_field_integer_unsigned_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      hMemModule = (uint64_t)bt_field_integer_unsigned_get_value(_event_p_f_m_2);
    }
    {
      const bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 3);
      subDevice = (uint32_t)bt_field_integer_unsigned_get_value(_event_p_f_m_3);
    }
    {
      const bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 4);
      pBandwidth = (float)bt_field_real_double_precision_get_value(_event_p_f_m_4);
    }
    {
      const bt_field *_event_p_f_m_5 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 5);
      rdBandwidth = (float)bt_field_real_double_precision_get_value(_event_p_f_m_5);
    }
    {
      const bt_field *_event_p_f_m_6 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 6);
      wtBandwidth = (float)bt_field_real_double_precision_get_value(_event_p_f_m_6);
    }
    {
      const bt_field *_event_p_f_m_7 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 7);
      occupancy = (float)bt_field_real_double_precision_get_value(_event_p_f_m_7);
    }
  }


  // Call registered matching callbacks
  {
    if (callbacks->automatic) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->automatic, _p))) {
        (*((sampling_memModule_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, hostname, ts, did, deviceIdx, hMemModule, subDevice, pBandwidth, rdBandwidth, wtBandwidth, occupancy);
      }
    }
  }

}

static void btx_dispatch_sampling_nic(
    callbacks_t *callbacks, common_data_t *common_data,
    const bt_message *upstream_message) {

  const char* hostname;
  int64_t ts;
  const char* interface_name;
  const char* counter;
  uint64_t value;

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
      ts = (int64_t)bt_field_integer_signed_get_value(_event_cc_f_m_1);
    }
  }
  {
    const bt_field *_event_p_f = bt_event_borrow_payload_field_const(_event);
    {
      const bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 0);
      interface_name = (const char*)bt_field_string_get_value(_event_p_f_m_0);
    }
    {
      const bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 1);
      counter = (const char*)bt_field_string_get_value(_event_p_f_m_1);
    }
    {
      const bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index_const(_event_p_f, 2);
      value = (uint64_t)bt_field_integer_unsigned_get_value(_event_p_f_m_2);
    }
  }


  // Call registered matching callbacks
  {
    if (callbacks->automatic) {
      void **_p = NULL;
      while ((
          _p = (void **)utarray_next(callbacks->automatic, _p))) {
        (*((sampling_nic_callback_f **)(_p)))(
            (void *)common_data,
            common_data
                ->usr_data, hostname, ts, interface_name, counter, value);
      }
    }
  }

}

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

void btx_register_callbacks_lttng_host(
    void *btx_handle,
    lttng_host_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng:host",
                        (void *)&btx_dispatch_lttng_host,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_device(
    void *btx_handle,
    lttng_device_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng:device",
                        (void *)&btx_dispatch_lttng_device,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_lttng_traffic(
    void *btx_handle,
    lttng_traffic_callback_f *callback) {
  bt_register_callbacks(btx_handle, "lttng:traffic",
                        (void *)&btx_dispatch_lttng_traffic,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_sampling_frequency(
    void *btx_handle,
    sampling_frequency_callback_f *callback) {
  bt_register_callbacks(btx_handle, "sampling:frequency",
                        (void *)&btx_dispatch_sampling_frequency,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_sampling_power(
    void *btx_handle,
    sampling_power_callback_f *callback) {
  bt_register_callbacks(btx_handle, "sampling:power",
                        (void *)&btx_dispatch_sampling_power,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_sampling_computeEU(
    void *btx_handle,
    sampling_computeEU_callback_f *callback) {
  bt_register_callbacks(btx_handle, "sampling:computeEU",
                        (void *)&btx_dispatch_sampling_computeEU,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_sampling_copyEU(
    void *btx_handle,
    sampling_copyEU_callback_f *callback) {
  bt_register_callbacks(btx_handle, "sampling:copyEU",
                        (void *)&btx_dispatch_sampling_copyEU,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_sampling_fabricPort(
    void *btx_handle,
    sampling_fabricPort_callback_f *callback) {
  bt_register_callbacks(btx_handle, "sampling:fabricPort",
                        (void *)&btx_dispatch_sampling_fabricPort,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_sampling_memModule(
    void *btx_handle,
    sampling_memModule_callback_f *callback) {
  bt_register_callbacks(btx_handle, "sampling:memModule",
                        (void *)&btx_dispatch_sampling_memModule,
                        "automatic", (void *)callback);
}
void btx_register_callbacks_sampling_nic(
    void *btx_handle,
    sampling_nic_callback_f *callback) {
  bt_register_callbacks(btx_handle, "sampling:nic",
                        (void *)&btx_dispatch_sampling_nic,
                        "automatic", (void *)callback);
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
