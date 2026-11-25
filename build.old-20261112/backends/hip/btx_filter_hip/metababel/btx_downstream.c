#include "utlist.h"
#include <babeltrace2/babeltrace.h>
#include <metababel/btx_component.h>
#include <metababel/btx_downstream.h>
#include <stdlib.h>

void btx_downstream_move_messages(
    btx_message_iterator_t *message_iterator_private_data,
    bt_message_array_const messages, uint64_t capacity, uint64_t *count) {

  // Set count to min(capacity, common_data->queue.size())
  // Count time, pop the head of the queue and put it in messages
  for (*count = 0; *count < capacity && message_iterator_private_data->queue;
       (*count)++) {
    struct el *elt = message_iterator_private_data->queue;
    messages[*count] = elt->message;
    DL_DELETE(message_iterator_private_data->queue, elt);
    // Put it back to the bool of chain for reuse
    DL_APPEND(message_iterator_private_data->pool, elt);
  }
}

static inline void
_btx_push_message(btx_message_iterator_t *message_iterator_private_data,
                  const bt_message *message) {

  struct el *elt;
  if (message_iterator_private_data->pool) {
    elt = message_iterator_private_data->pool;
    DL_DELETE(message_iterator_private_data->pool, elt);
  } else {
    elt = (struct el *)malloc(sizeof *elt);
  }
  elt->message = message;
  DL_APPEND(message_iterator_private_data->queue, elt);
}

// Used internally to push messages downstreams
void btx_downstream_push_message(
    btx_message_iterator_t *message_iterator_private_data,
    const bt_message *message) {

  _btx_push_message(message_iterator_private_data, message);
}

// Register callbacks
bt_trace_class *
btx_downstream_trace_class_create_rec(bt_self_component *_self_component) {
  bt_trace_class *_trace_class;
  _trace_class = bt_trace_class_create(_self_component);
  {
    bt_stream_class *_trace_class_sc_0;
    _trace_class_sc_0 = bt_stream_class_create(_trace_class);
    bt_stream_class_set_name(_trace_class_sc_0, "interval");
    {
      bt_field_class *_trace_class_sc_0_ecc_fc;
      _trace_class_sc_0_ecc_fc = bt_field_class_structure_create(_trace_class);
      {
        bt_field_class *_trace_class_sc_0_ecc_fc_m_0;
        _trace_class_sc_0_ecc_fc_m_0 = bt_field_class_string_create(_trace_class);
        bt_field_class_structure_append_member(_trace_class_sc_0_ecc_fc, "hostname", _trace_class_sc_0_ecc_fc_m_0);
        bt_field_class_put_ref(_trace_class_sc_0_ecc_fc_m_0);
      }
      {
        bt_field_class *_trace_class_sc_0_ecc_fc_m_1;
        _trace_class_sc_0_ecc_fc_m_1 = bt_field_class_integer_signed_create(_trace_class);
        bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ecc_fc_m_1, 64);
        bt_field_class_structure_append_member(_trace_class_sc_0_ecc_fc, "vpid", _trace_class_sc_0_ecc_fc_m_1);
        bt_field_class_put_ref(_trace_class_sc_0_ecc_fc_m_1);
      }
      {
        bt_field_class *_trace_class_sc_0_ecc_fc_m_2;
        _trace_class_sc_0_ecc_fc_m_2 = bt_field_class_integer_unsigned_create(_trace_class);
        bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ecc_fc_m_2, 64);
        bt_field_class_structure_append_member(_trace_class_sc_0_ecc_fc, "vtid", _trace_class_sc_0_ecc_fc_m_2);
        bt_field_class_put_ref(_trace_class_sc_0_ecc_fc_m_2);
      }
      {
        bt_field_class *_trace_class_sc_0_ecc_fc_m_3;
        _trace_class_sc_0_ecc_fc_m_3 = bt_field_class_integer_signed_create(_trace_class);
        bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ecc_fc_m_3, 64);
        bt_field_class_structure_append_member(_trace_class_sc_0_ecc_fc, "ts", _trace_class_sc_0_ecc_fc_m_3);
        bt_field_class_put_ref(_trace_class_sc_0_ecc_fc_m_3);
      }
      {
        bt_field_class *_trace_class_sc_0_ecc_fc_m_4;
        _trace_class_sc_0_ecc_fc_m_4 = bt_field_class_integer_signed_create(_trace_class);
        bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ecc_fc_m_4, 64);
        bt_field_class_structure_append_member(_trace_class_sc_0_ecc_fc, "backend", _trace_class_sc_0_ecc_fc_m_4);
        bt_field_class_put_ref(_trace_class_sc_0_ecc_fc_m_4);
      }
      bt_stream_class_set_event_common_context_field_class(_trace_class_sc_0, _trace_class_sc_0_ecc_fc);
      bt_field_class_put_ref(_trace_class_sc_0_ecc_fc);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_0;
      _trace_class_sc_0_ec_0 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_0, "lttng:host");
      {
        bt_field_class *_trace_class_sc_0_ec_0_p_fc;
        _trace_class_sc_0_ec_0_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_0_p_fc_m_0;
          _trace_class_sc_0_ec_0_p_fc_m_0 = bt_field_class_string_create(_trace_class);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_0_p_fc, "name", _trace_class_sc_0_ec_0_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_0_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_0_p_fc_m_1;
          _trace_class_sc_0_ec_0_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_0_p_fc_m_1, 64);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_0_p_fc, "dur", _trace_class_sc_0_ec_0_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_0_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_0_p_fc_m_2;
          _trace_class_sc_0_ec_0_p_fc_m_2 = bt_field_class_bool_create(_trace_class);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_0_p_fc, "err", _trace_class_sc_0_ec_0_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_0_ec_0_p_fc_m_2);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_0, _trace_class_sc_0_ec_0_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_0_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_0);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_1;
      _trace_class_sc_0_ec_1 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_1, "lttng:device");
      {
        bt_field_class *_trace_class_sc_0_ec_1_p_fc;
        _trace_class_sc_0_ec_1_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_1_p_fc_m_0;
          _trace_class_sc_0_ec_1_p_fc_m_0 = bt_field_class_string_create(_trace_class);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_1_p_fc, "name", _trace_class_sc_0_ec_1_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_1_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_1_p_fc_m_1;
          _trace_class_sc_0_ec_1_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_1_p_fc_m_1, 64);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_1_p_fc, "dur", _trace_class_sc_0_ec_1_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_1_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_1_p_fc_m_2;
          _trace_class_sc_0_ec_1_p_fc_m_2 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_1_p_fc_m_2, 64);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_1_p_fc, "did", _trace_class_sc_0_ec_1_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_0_ec_1_p_fc_m_2);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_1_p_fc_m_3;
          _trace_class_sc_0_ec_1_p_fc_m_3 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_1_p_fc_m_3, 64);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_1_p_fc, "sdid", _trace_class_sc_0_ec_1_p_fc_m_3);
          bt_field_class_put_ref(_trace_class_sc_0_ec_1_p_fc_m_3);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_1_p_fc_m_4;
          _trace_class_sc_0_ec_1_p_fc_m_4 = bt_field_class_bool_create(_trace_class);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_1_p_fc, "err", _trace_class_sc_0_ec_1_p_fc_m_4);
          bt_field_class_put_ref(_trace_class_sc_0_ec_1_p_fc_m_4);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_1_p_fc_m_5;
          _trace_class_sc_0_ec_1_p_fc_m_5 = bt_field_class_string_create(_trace_class);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_1_p_fc, "metadata", _trace_class_sc_0_ec_1_p_fc_m_5);
          bt_field_class_put_ref(_trace_class_sc_0_ec_1_p_fc_m_5);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_1, _trace_class_sc_0_ec_1_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_1_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_1);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_2;
      _trace_class_sc_0_ec_2 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_2, "lttng:traffic");
      {
        bt_field_class *_trace_class_sc_0_ec_2_p_fc;
        _trace_class_sc_0_ec_2_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_2_p_fc_m_0;
          _trace_class_sc_0_ec_2_p_fc_m_0 = bt_field_class_string_create(_trace_class);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_2_p_fc, "name", _trace_class_sc_0_ec_2_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_2_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_2_p_fc_m_1;
          _trace_class_sc_0_ec_2_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_2_p_fc_m_1, 64);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_2_p_fc, "size", _trace_class_sc_0_ec_2_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_2_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_2_p_fc_m_2;
          _trace_class_sc_0_ec_2_p_fc_m_2 = bt_field_class_string_create(_trace_class);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_2_p_fc, "metadata", _trace_class_sc_0_ec_2_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_0_ec_2_p_fc_m_2);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_2, _trace_class_sc_0_ec_2_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_2_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_2);
    }
    bt_stream_class_put_ref(_trace_class_sc_0);
  }
  {
    bt_stream_class *_trace_class_sc_1;
    _trace_class_sc_1 = bt_stream_class_create(_trace_class);
    bt_stream_class_set_name(_trace_class_sc_1, "interval_sampling");
    {
      bt_field_class *_trace_class_sc_1_ecc_fc;
      _trace_class_sc_1_ecc_fc = bt_field_class_structure_create(_trace_class);
      {
        bt_field_class *_trace_class_sc_1_ecc_fc_m_0;
        _trace_class_sc_1_ecc_fc_m_0 = bt_field_class_string_create(_trace_class);
        bt_field_class_structure_append_member(_trace_class_sc_1_ecc_fc, "hostname", _trace_class_sc_1_ecc_fc_m_0);
        bt_field_class_put_ref(_trace_class_sc_1_ecc_fc_m_0);
      }
      {
        bt_field_class *_trace_class_sc_1_ecc_fc_m_1;
        _trace_class_sc_1_ecc_fc_m_1 = bt_field_class_integer_signed_create(_trace_class);
        bt_field_class_integer_set_field_value_range(_trace_class_sc_1_ecc_fc_m_1, 64);
        bt_field_class_structure_append_member(_trace_class_sc_1_ecc_fc, "ts", _trace_class_sc_1_ecc_fc_m_1);
        bt_field_class_put_ref(_trace_class_sc_1_ecc_fc_m_1);
      }
      bt_stream_class_set_event_common_context_field_class(_trace_class_sc_1, _trace_class_sc_1_ecc_fc);
      bt_field_class_put_ref(_trace_class_sc_1_ecc_fc);
    }
    {
      bt_event_class *_trace_class_sc_1_ec_0;
      _trace_class_sc_1_ec_0 = bt_event_class_create(_trace_class_sc_1);
      bt_event_class_set_name(_trace_class_sc_1_ec_0, "sampling:frequency");
      {
        bt_field_class *_trace_class_sc_1_ec_0_p_fc;
        _trace_class_sc_1_ec_0_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_1_ec_0_p_fc_m_0;
          _trace_class_sc_1_ec_0_p_fc_m_0 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_1_ec_0_p_fc_m_0, 64);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_0_p_fc, "did", _trace_class_sc_1_ec_0_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_1_ec_0_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_1_ec_0_p_fc_m_1;
          _trace_class_sc_1_ec_0_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_1_ec_0_p_fc_m_1, 32);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_0_p_fc, "deviceIdx", _trace_class_sc_1_ec_0_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_1_ec_0_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_1_ec_0_p_fc_m_2;
          _trace_class_sc_1_ec_0_p_fc_m_2 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_1_ec_0_p_fc_m_2, 64);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_0_p_fc, "hFrequency", _trace_class_sc_1_ec_0_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_1_ec_0_p_fc_m_2);
        }
        {
          bt_field_class *_trace_class_sc_1_ec_0_p_fc_m_3;
          _trace_class_sc_1_ec_0_p_fc_m_3 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_1_ec_0_p_fc_m_3, 32);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_0_p_fc, "domain", _trace_class_sc_1_ec_0_p_fc_m_3);
          bt_field_class_put_ref(_trace_class_sc_1_ec_0_p_fc_m_3);
        }
        {
          bt_field_class *_trace_class_sc_1_ec_0_p_fc_m_4;
          _trace_class_sc_1_ec_0_p_fc_m_4 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_1_ec_0_p_fc_m_4, 64);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_0_p_fc, "frequency", _trace_class_sc_1_ec_0_p_fc_m_4);
          bt_field_class_put_ref(_trace_class_sc_1_ec_0_p_fc_m_4);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_1_ec_0, _trace_class_sc_1_ec_0_p_fc);
        bt_field_class_put_ref(_trace_class_sc_1_ec_0_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_1_ec_0);
    }
    {
      bt_event_class *_trace_class_sc_1_ec_1;
      _trace_class_sc_1_ec_1 = bt_event_class_create(_trace_class_sc_1);
      bt_event_class_set_name(_trace_class_sc_1_ec_1, "sampling:power");
      {
        bt_field_class *_trace_class_sc_1_ec_1_p_fc;
        _trace_class_sc_1_ec_1_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_1_ec_1_p_fc_m_0;
          _trace_class_sc_1_ec_1_p_fc_m_0 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_1_ec_1_p_fc_m_0, 64);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_1_p_fc, "did", _trace_class_sc_1_ec_1_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_1_ec_1_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_1_ec_1_p_fc_m_1;
          _trace_class_sc_1_ec_1_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_1_ec_1_p_fc_m_1, 32);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_1_p_fc, "deviceIdx", _trace_class_sc_1_ec_1_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_1_ec_1_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_1_ec_1_p_fc_m_2;
          _trace_class_sc_1_ec_1_p_fc_m_2 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_1_ec_1_p_fc_m_2, 64);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_1_p_fc, "hPower", _trace_class_sc_1_ec_1_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_1_ec_1_p_fc_m_2);
        }
        {
          bt_field_class *_trace_class_sc_1_ec_1_p_fc_m_3;
          _trace_class_sc_1_ec_1_p_fc_m_3 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_1_ec_1_p_fc_m_3, 32);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_1_p_fc, "domain", _trace_class_sc_1_ec_1_p_fc_m_3);
          bt_field_class_put_ref(_trace_class_sc_1_ec_1_p_fc_m_3);
        }
        {
          bt_field_class *_trace_class_sc_1_ec_1_p_fc_m_4;
          _trace_class_sc_1_ec_1_p_fc_m_4 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_1_ec_1_p_fc_m_4, 64);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_1_p_fc, "power", _trace_class_sc_1_ec_1_p_fc_m_4);
          bt_field_class_put_ref(_trace_class_sc_1_ec_1_p_fc_m_4);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_1_ec_1, _trace_class_sc_1_ec_1_p_fc);
        bt_field_class_put_ref(_trace_class_sc_1_ec_1_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_1_ec_1);
    }
    {
      bt_event_class *_trace_class_sc_1_ec_2;
      _trace_class_sc_1_ec_2 = bt_event_class_create(_trace_class_sc_1);
      bt_event_class_set_name(_trace_class_sc_1_ec_2, "sampling:computeEU");
      {
        bt_field_class *_trace_class_sc_1_ec_2_p_fc;
        _trace_class_sc_1_ec_2_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_1_ec_2_p_fc_m_0;
          _trace_class_sc_1_ec_2_p_fc_m_0 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_1_ec_2_p_fc_m_0, 64);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_2_p_fc, "did", _trace_class_sc_1_ec_2_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_1_ec_2_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_1_ec_2_p_fc_m_1;
          _trace_class_sc_1_ec_2_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_1_ec_2_p_fc_m_1, 32);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_2_p_fc, "deviceIdx", _trace_class_sc_1_ec_2_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_1_ec_2_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_1_ec_2_p_fc_m_2;
          _trace_class_sc_1_ec_2_p_fc_m_2 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_1_ec_2_p_fc_m_2, 64);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_2_p_fc, "hEngine", _trace_class_sc_1_ec_2_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_1_ec_2_p_fc_m_2);
        }
        {
          bt_field_class *_trace_class_sc_1_ec_2_p_fc_m_3;
          _trace_class_sc_1_ec_2_p_fc_m_3 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_1_ec_2_p_fc_m_3, 32);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_2_p_fc, "subDevice", _trace_class_sc_1_ec_2_p_fc_m_3);
          bt_field_class_put_ref(_trace_class_sc_1_ec_2_p_fc_m_3);
        }
        {
          bt_field_class *_trace_class_sc_1_ec_2_p_fc_m_4;
          _trace_class_sc_1_ec_2_p_fc_m_4 = bt_field_class_real_single_precision_create(_trace_class);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_2_p_fc, "activeTime", _trace_class_sc_1_ec_2_p_fc_m_4);
          bt_field_class_put_ref(_trace_class_sc_1_ec_2_p_fc_m_4);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_1_ec_2, _trace_class_sc_1_ec_2_p_fc);
        bt_field_class_put_ref(_trace_class_sc_1_ec_2_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_1_ec_2);
    }
    {
      bt_event_class *_trace_class_sc_1_ec_3;
      _trace_class_sc_1_ec_3 = bt_event_class_create(_trace_class_sc_1);
      bt_event_class_set_name(_trace_class_sc_1_ec_3, "sampling:copyEU");
      {
        bt_field_class *_trace_class_sc_1_ec_3_p_fc;
        _trace_class_sc_1_ec_3_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_1_ec_3_p_fc_m_0;
          _trace_class_sc_1_ec_3_p_fc_m_0 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_1_ec_3_p_fc_m_0, 64);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_3_p_fc, "did", _trace_class_sc_1_ec_3_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_1_ec_3_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_1_ec_3_p_fc_m_1;
          _trace_class_sc_1_ec_3_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_1_ec_3_p_fc_m_1, 32);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_3_p_fc, "deviceIdx", _trace_class_sc_1_ec_3_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_1_ec_3_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_1_ec_3_p_fc_m_2;
          _trace_class_sc_1_ec_3_p_fc_m_2 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_1_ec_3_p_fc_m_2, 64);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_3_p_fc, "hEngine", _trace_class_sc_1_ec_3_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_1_ec_3_p_fc_m_2);
        }
        {
          bt_field_class *_trace_class_sc_1_ec_3_p_fc_m_3;
          _trace_class_sc_1_ec_3_p_fc_m_3 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_1_ec_3_p_fc_m_3, 32);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_3_p_fc, "subDevice", _trace_class_sc_1_ec_3_p_fc_m_3);
          bt_field_class_put_ref(_trace_class_sc_1_ec_3_p_fc_m_3);
        }
        {
          bt_field_class *_trace_class_sc_1_ec_3_p_fc_m_4;
          _trace_class_sc_1_ec_3_p_fc_m_4 = bt_field_class_real_single_precision_create(_trace_class);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_3_p_fc, "activeTime", _trace_class_sc_1_ec_3_p_fc_m_4);
          bt_field_class_put_ref(_trace_class_sc_1_ec_3_p_fc_m_4);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_1_ec_3, _trace_class_sc_1_ec_3_p_fc);
        bt_field_class_put_ref(_trace_class_sc_1_ec_3_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_1_ec_3);
    }
    {
      bt_event_class *_trace_class_sc_1_ec_4;
      _trace_class_sc_1_ec_4 = bt_event_class_create(_trace_class_sc_1);
      bt_event_class_set_name(_trace_class_sc_1_ec_4, "sampling:fabricPort");
      {
        bt_field_class *_trace_class_sc_1_ec_4_p_fc;
        _trace_class_sc_1_ec_4_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_1_ec_4_p_fc_m_0;
          _trace_class_sc_1_ec_4_p_fc_m_0 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_1_ec_4_p_fc_m_0, 64);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_4_p_fc, "did", _trace_class_sc_1_ec_4_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_1_ec_4_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_1_ec_4_p_fc_m_1;
          _trace_class_sc_1_ec_4_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_1_ec_4_p_fc_m_1, 32);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_4_p_fc, "deviceIdx", _trace_class_sc_1_ec_4_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_1_ec_4_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_1_ec_4_p_fc_m_2;
          _trace_class_sc_1_ec_4_p_fc_m_2 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_1_ec_4_p_fc_m_2, 64);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_4_p_fc, "hFabricPort", _trace_class_sc_1_ec_4_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_1_ec_4_p_fc_m_2);
        }
        {
          bt_field_class *_trace_class_sc_1_ec_4_p_fc_m_3;
          _trace_class_sc_1_ec_4_p_fc_m_3 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_1_ec_4_p_fc_m_3, 32);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_4_p_fc, "subDevice", _trace_class_sc_1_ec_4_p_fc_m_3);
          bt_field_class_put_ref(_trace_class_sc_1_ec_4_p_fc_m_3);
        }
        {
          bt_field_class *_trace_class_sc_1_ec_4_p_fc_m_4;
          _trace_class_sc_1_ec_4_p_fc_m_4 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_1_ec_4_p_fc_m_4, 32);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_4_p_fc, "portId", _trace_class_sc_1_ec_4_p_fc_m_4);
          bt_field_class_put_ref(_trace_class_sc_1_ec_4_p_fc_m_4);
        }
        {
          bt_field_class *_trace_class_sc_1_ec_4_p_fc_m_5;
          _trace_class_sc_1_ec_4_p_fc_m_5 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_1_ec_4_p_fc_m_5, 32);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_4_p_fc, "remotePortId", _trace_class_sc_1_ec_4_p_fc_m_5);
          bt_field_class_put_ref(_trace_class_sc_1_ec_4_p_fc_m_5);
        }
        {
          bt_field_class *_trace_class_sc_1_ec_4_p_fc_m_6;
          _trace_class_sc_1_ec_4_p_fc_m_6 = bt_field_class_real_double_precision_create(_trace_class);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_4_p_fc, "rxThroughput", _trace_class_sc_1_ec_4_p_fc_m_6);
          bt_field_class_put_ref(_trace_class_sc_1_ec_4_p_fc_m_6);
        }
        {
          bt_field_class *_trace_class_sc_1_ec_4_p_fc_m_7;
          _trace_class_sc_1_ec_4_p_fc_m_7 = bt_field_class_real_double_precision_create(_trace_class);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_4_p_fc, "txThroughput", _trace_class_sc_1_ec_4_p_fc_m_7);
          bt_field_class_put_ref(_trace_class_sc_1_ec_4_p_fc_m_7);
        }
        {
          bt_field_class *_trace_class_sc_1_ec_4_p_fc_m_8;
          _trace_class_sc_1_ec_4_p_fc_m_8 = bt_field_class_real_double_precision_create(_trace_class);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_4_p_fc, "rxSpeed", _trace_class_sc_1_ec_4_p_fc_m_8);
          bt_field_class_put_ref(_trace_class_sc_1_ec_4_p_fc_m_8);
        }
        {
          bt_field_class *_trace_class_sc_1_ec_4_p_fc_m_9;
          _trace_class_sc_1_ec_4_p_fc_m_9 = bt_field_class_real_double_precision_create(_trace_class);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_4_p_fc, "txSpeed", _trace_class_sc_1_ec_4_p_fc_m_9);
          bt_field_class_put_ref(_trace_class_sc_1_ec_4_p_fc_m_9);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_1_ec_4, _trace_class_sc_1_ec_4_p_fc);
        bt_field_class_put_ref(_trace_class_sc_1_ec_4_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_1_ec_4);
    }
    {
      bt_event_class *_trace_class_sc_1_ec_5;
      _trace_class_sc_1_ec_5 = bt_event_class_create(_trace_class_sc_1);
      bt_event_class_set_name(_trace_class_sc_1_ec_5, "sampling:memModule");
      {
        bt_field_class *_trace_class_sc_1_ec_5_p_fc;
        _trace_class_sc_1_ec_5_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_1_ec_5_p_fc_m_0;
          _trace_class_sc_1_ec_5_p_fc_m_0 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_1_ec_5_p_fc_m_0, 64);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_5_p_fc, "did", _trace_class_sc_1_ec_5_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_1_ec_5_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_1_ec_5_p_fc_m_1;
          _trace_class_sc_1_ec_5_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_1_ec_5_p_fc_m_1, 32);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_5_p_fc, "deviceIdx", _trace_class_sc_1_ec_5_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_1_ec_5_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_1_ec_5_p_fc_m_2;
          _trace_class_sc_1_ec_5_p_fc_m_2 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_1_ec_5_p_fc_m_2, 64);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_5_p_fc, "hMemModule", _trace_class_sc_1_ec_5_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_1_ec_5_p_fc_m_2);
        }
        {
          bt_field_class *_trace_class_sc_1_ec_5_p_fc_m_3;
          _trace_class_sc_1_ec_5_p_fc_m_3 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_1_ec_5_p_fc_m_3, 32);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_5_p_fc, "subDevice", _trace_class_sc_1_ec_5_p_fc_m_3);
          bt_field_class_put_ref(_trace_class_sc_1_ec_5_p_fc_m_3);
        }
        {
          bt_field_class *_trace_class_sc_1_ec_5_p_fc_m_4;
          _trace_class_sc_1_ec_5_p_fc_m_4 = bt_field_class_real_double_precision_create(_trace_class);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_5_p_fc, "pBandwidth", _trace_class_sc_1_ec_5_p_fc_m_4);
          bt_field_class_put_ref(_trace_class_sc_1_ec_5_p_fc_m_4);
        }
        {
          bt_field_class *_trace_class_sc_1_ec_5_p_fc_m_5;
          _trace_class_sc_1_ec_5_p_fc_m_5 = bt_field_class_real_double_precision_create(_trace_class);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_5_p_fc, "rdBandwidth", _trace_class_sc_1_ec_5_p_fc_m_5);
          bt_field_class_put_ref(_trace_class_sc_1_ec_5_p_fc_m_5);
        }
        {
          bt_field_class *_trace_class_sc_1_ec_5_p_fc_m_6;
          _trace_class_sc_1_ec_5_p_fc_m_6 = bt_field_class_real_double_precision_create(_trace_class);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_5_p_fc, "wtBandwidth", _trace_class_sc_1_ec_5_p_fc_m_6);
          bt_field_class_put_ref(_trace_class_sc_1_ec_5_p_fc_m_6);
        }
        {
          bt_field_class *_trace_class_sc_1_ec_5_p_fc_m_7;
          _trace_class_sc_1_ec_5_p_fc_m_7 = bt_field_class_real_double_precision_create(_trace_class);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_5_p_fc, "occupancy", _trace_class_sc_1_ec_5_p_fc_m_7);
          bt_field_class_put_ref(_trace_class_sc_1_ec_5_p_fc_m_7);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_1_ec_5, _trace_class_sc_1_ec_5_p_fc);
        bt_field_class_put_ref(_trace_class_sc_1_ec_5_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_1_ec_5);
    }
    {
      bt_event_class *_trace_class_sc_1_ec_6;
      _trace_class_sc_1_ec_6 = bt_event_class_create(_trace_class_sc_1);
      bt_event_class_set_name(_trace_class_sc_1_ec_6, "sampling:nic");
      {
        bt_field_class *_trace_class_sc_1_ec_6_p_fc;
        _trace_class_sc_1_ec_6_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_1_ec_6_p_fc_m_0;
          _trace_class_sc_1_ec_6_p_fc_m_0 = bt_field_class_string_create(_trace_class);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_6_p_fc, "interface_name", _trace_class_sc_1_ec_6_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_1_ec_6_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_1_ec_6_p_fc_m_1;
          _trace_class_sc_1_ec_6_p_fc_m_1 = bt_field_class_string_create(_trace_class);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_6_p_fc, "counter", _trace_class_sc_1_ec_6_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_1_ec_6_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_1_ec_6_p_fc_m_2;
          _trace_class_sc_1_ec_6_p_fc_m_2 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_1_ec_6_p_fc_m_2, 64);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_6_p_fc, "value", _trace_class_sc_1_ec_6_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_1_ec_6_p_fc_m_2);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_1_ec_6, _trace_class_sc_1_ec_6_p_fc);
        bt_field_class_put_ref(_trace_class_sc_1_ec_6_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_1_ec_6);
    }
    bt_stream_class_put_ref(_trace_class_sc_1);
  }

  return _trace_class;
}

bt_trace *btx_downstream_trace_create_rec(bt_trace_class *trace_class) {
  bt_trace *trace = bt_trace_create(trace_class);
  {
    bt_stream_class *stream_class =
        bt_trace_class_borrow_stream_class_by_index(trace_class, 0);
    bt_stream_put_ref(bt_stream_create(stream_class, trace));
  }
  {
    bt_stream_class *stream_class =
        bt_trace_class_borrow_stream_class_by_index(trace_class, 1);
    bt_stream_put_ref(bt_stream_create(stream_class, trace));
  }
  return trace;
}

// Workaround of a bug where gepping trace alive (and not the stream) provoke
// some segfault
void btx_streams_get_ref(bt_trace *trace) {
  {
    bt_stream *stream = bt_trace_borrow_stream_by_index(trace, 0);
    bt_stream_get_ref(stream);
  }
  {
    bt_stream *stream = bt_trace_borrow_stream_by_index(trace, 1);
    bt_stream_get_ref(stream);
  }
}

void btx_streams_put_ref(bt_trace *trace) {
  {
    bt_stream *stream = bt_trace_borrow_stream_by_index(trace, 0);
    bt_stream_put_ref(stream);
  }
  {
    bt_stream *stream = bt_trace_borrow_stream_by_index(trace, 1);
    bt_stream_put_ref(stream);
  }
}

void btx_push_messages_stream_beginning(
    bt_self_message_iterator *self_message_iterator,
    btx_message_iterator_t *message_iterator_private_data) {

  bt_trace *trace =
      message_iterator_private_data->common_data->downstream_trace;
  {
    bt_stream *stream = bt_trace_borrow_stream_by_index(trace, 0);
    bt_message *message =
        bt_message_stream_beginning_create(self_message_iterator, stream);
    btx_downstream_push_message(message_iterator_private_data, message);
  }
  {
    bt_stream *stream = bt_trace_borrow_stream_by_index(trace, 1);
    bt_message *message =
        bt_message_stream_beginning_create(self_message_iterator, stream);
    btx_downstream_push_message(message_iterator_private_data, message);
  }
  (void)trace;
}

void btx_push_messages_stream_end(
    bt_self_message_iterator *self_message_iterator,
    btx_message_iterator_t *message_iterator_private_data) {

  bt_trace *trace =
      message_iterator_private_data->common_data->downstream_trace;
  {
    bt_stream *stream = bt_trace_borrow_stream_by_index(trace, 0);
    bt_message *message =
        bt_message_stream_end_create(self_message_iterator, stream);
    btx_downstream_push_message(message_iterator_private_data, message);
  }
  {
    bt_stream *stream = bt_trace_borrow_stream_by_index(trace, 1);
    bt_message *message =
        bt_message_stream_end_create(self_message_iterator, stream);
    btx_downstream_push_message(message_iterator_private_data, message);
  }
  (void)trace;
}

static void btx_set_message_lttng_host(
    bt_event *
        _event, const char* hostname, int64_t vpid, uint64_t vtid, int64_t ts, int64_t backend, const char* name, uint64_t dur, bt_bool err) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_string_set_value(_event_cc_f_m_0, (const char*)hostname);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_signed_set_value(_event_cc_f_m_1, (int64_t)vpid);
    }
    {
      bt_field *_event_cc_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 2);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_2, (uint64_t)vtid);
    }
    {
      bt_field *_event_cc_f_m_3 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 3);
      bt_field_integer_signed_set_value(_event_cc_f_m_3, (int64_t)ts);
    }
    {
      bt_field *_event_cc_f_m_4 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 4);
      bt_field_integer_signed_set_value(_event_cc_f_m_4, (int64_t)backend);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_string_set_value(_event_p_f_m_0, (const char*)name);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)dur);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_bool_set_value(_event_p_f_m_2, (bt_bool)err);
    }
  }

}

void btx_push_message_lttng_host(
    void *
        btx_handle, const char* hostname, int64_t vpid, uint64_t vtid, int64_t ts, int64_t backend, const char* name, uint64_t dur, bt_bool err) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 0);
  bt_message *_message = bt_message_event_create(
      common_data->self_message_iterator, _event_class, _stream);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_host(
      _downstream_event, hostname, vpid, vtid, ts, backend, name, dur, err);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_device(
    bt_event *
        _event, const char* hostname, int64_t vpid, uint64_t vtid, int64_t ts, int64_t backend, const char* name, uint64_t dur, uint64_t did, uint64_t sdid, bt_bool err, const char* metadata) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_string_set_value(_event_cc_f_m_0, (const char*)hostname);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_signed_set_value(_event_cc_f_m_1, (int64_t)vpid);
    }
    {
      bt_field *_event_cc_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 2);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_2, (uint64_t)vtid);
    }
    {
      bt_field *_event_cc_f_m_3 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 3);
      bt_field_integer_signed_set_value(_event_cc_f_m_3, (int64_t)ts);
    }
    {
      bt_field *_event_cc_f_m_4 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 4);
      bt_field_integer_signed_set_value(_event_cc_f_m_4, (int64_t)backend);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_string_set_value(_event_p_f_m_0, (const char*)name);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)dur);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_unsigned_set_value(_event_p_f_m_2, (uint64_t)did);
    }
    {
      bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 3);
      bt_field_integer_unsigned_set_value(_event_p_f_m_3, (uint64_t)sdid);
    }
    {
      bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 4);
      bt_field_bool_set_value(_event_p_f_m_4, (bt_bool)err);
    }
    {
      bt_field *_event_p_f_m_5 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 5);
      bt_field_string_set_value(_event_p_f_m_5, (const char*)metadata);
    }
  }

}

void btx_push_message_lttng_device(
    void *
        btx_handle, const char* hostname, int64_t vpid, uint64_t vtid, int64_t ts, int64_t backend, const char* name, uint64_t dur, uint64_t did, uint64_t sdid, bt_bool err, const char* metadata) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 1);
  bt_message *_message = bt_message_event_create(
      common_data->self_message_iterator, _event_class, _stream);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_device(
      _downstream_event, hostname, vpid, vtid, ts, backend, name, dur, did, sdid, err, metadata);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_traffic(
    bt_event *
        _event, const char* hostname, int64_t vpid, uint64_t vtid, int64_t ts, int64_t backend, const char* name, uint64_t size, const char* metadata) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_string_set_value(_event_cc_f_m_0, (const char*)hostname);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_signed_set_value(_event_cc_f_m_1, (int64_t)vpid);
    }
    {
      bt_field *_event_cc_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 2);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_2, (uint64_t)vtid);
    }
    {
      bt_field *_event_cc_f_m_3 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 3);
      bt_field_integer_signed_set_value(_event_cc_f_m_3, (int64_t)ts);
    }
    {
      bt_field *_event_cc_f_m_4 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 4);
      bt_field_integer_signed_set_value(_event_cc_f_m_4, (int64_t)backend);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_string_set_value(_event_p_f_m_0, (const char*)name);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)size);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_string_set_value(_event_p_f_m_2, (const char*)metadata);
    }
  }

}

void btx_push_message_lttng_traffic(
    void *
        btx_handle, const char* hostname, int64_t vpid, uint64_t vtid, int64_t ts, int64_t backend, const char* name, uint64_t size, const char* metadata) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 2);
  bt_message *_message = bt_message_event_create(
      common_data->self_message_iterator, _event_class, _stream);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_traffic(
      _downstream_event, hostname, vpid, vtid, ts, backend, name, size, metadata);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_sampling_frequency(
    bt_event *
        _event, const char* hostname, int64_t ts, uint64_t did, uint32_t deviceIdx, uint64_t hFrequency, uint32_t domain, uint64_t frequency) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_string_set_value(_event_cc_f_m_0, (const char*)hostname);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_signed_set_value(_event_cc_f_m_1, (int64_t)ts);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_unsigned_set_value(_event_p_f_m_0, (uint64_t)did);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)deviceIdx);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_unsigned_set_value(_event_p_f_m_2, (uint64_t)hFrequency);
    }
    {
      bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 3);
      bt_field_integer_unsigned_set_value(_event_p_f_m_3, (uint64_t)domain);
    }
    {
      bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 4);
      bt_field_integer_unsigned_set_value(_event_p_f_m_4, (uint64_t)frequency);
    }
  }

}

void btx_push_message_sampling_frequency(
    void *
        btx_handle, const char* hostname, int64_t ts, uint64_t did, uint32_t deviceIdx, uint64_t hFrequency, uint32_t domain, uint64_t frequency) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 1);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 0);
  bt_message *_message = bt_message_event_create(
      common_data->self_message_iterator, _event_class, _stream);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_sampling_frequency(
      _downstream_event, hostname, ts, did, deviceIdx, hFrequency, domain, frequency);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_sampling_power(
    bt_event *
        _event, const char* hostname, int64_t ts, uint64_t did, uint32_t deviceIdx, uint64_t hPower, uint32_t domain, uint64_t power) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_string_set_value(_event_cc_f_m_0, (const char*)hostname);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_signed_set_value(_event_cc_f_m_1, (int64_t)ts);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_unsigned_set_value(_event_p_f_m_0, (uint64_t)did);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)deviceIdx);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_unsigned_set_value(_event_p_f_m_2, (uint64_t)hPower);
    }
    {
      bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 3);
      bt_field_integer_unsigned_set_value(_event_p_f_m_3, (uint64_t)domain);
    }
    {
      bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 4);
      bt_field_integer_unsigned_set_value(_event_p_f_m_4, (uint64_t)power);
    }
  }

}

void btx_push_message_sampling_power(
    void *
        btx_handle, const char* hostname, int64_t ts, uint64_t did, uint32_t deviceIdx, uint64_t hPower, uint32_t domain, uint64_t power) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 1);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 1);
  bt_message *_message = bt_message_event_create(
      common_data->self_message_iterator, _event_class, _stream);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_sampling_power(
      _downstream_event, hostname, ts, did, deviceIdx, hPower, domain, power);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_sampling_computeEU(
    bt_event *
        _event, const char* hostname, int64_t ts, uint64_t did, uint32_t deviceIdx, uint64_t hEngine, uint32_t subDevice, float activeTime) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_string_set_value(_event_cc_f_m_0, (const char*)hostname);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_signed_set_value(_event_cc_f_m_1, (int64_t)ts);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_unsigned_set_value(_event_p_f_m_0, (uint64_t)did);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)deviceIdx);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_unsigned_set_value(_event_p_f_m_2, (uint64_t)hEngine);
    }
    {
      bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 3);
      bt_field_integer_unsigned_set_value(_event_p_f_m_3, (uint64_t)subDevice);
    }
    {
      bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 4);
      bt_field_real_single_precision_set_value(_event_p_f_m_4, (float)activeTime);
    }
  }

}

void btx_push_message_sampling_computeEU(
    void *
        btx_handle, const char* hostname, int64_t ts, uint64_t did, uint32_t deviceIdx, uint64_t hEngine, uint32_t subDevice, float activeTime) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 1);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 2);
  bt_message *_message = bt_message_event_create(
      common_data->self_message_iterator, _event_class, _stream);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_sampling_computeEU(
      _downstream_event, hostname, ts, did, deviceIdx, hEngine, subDevice, activeTime);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_sampling_copyEU(
    bt_event *
        _event, const char* hostname, int64_t ts, uint64_t did, uint32_t deviceIdx, uint64_t hEngine, uint32_t subDevice, float activeTime) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_string_set_value(_event_cc_f_m_0, (const char*)hostname);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_signed_set_value(_event_cc_f_m_1, (int64_t)ts);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_unsigned_set_value(_event_p_f_m_0, (uint64_t)did);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)deviceIdx);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_unsigned_set_value(_event_p_f_m_2, (uint64_t)hEngine);
    }
    {
      bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 3);
      bt_field_integer_unsigned_set_value(_event_p_f_m_3, (uint64_t)subDevice);
    }
    {
      bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 4);
      bt_field_real_single_precision_set_value(_event_p_f_m_4, (float)activeTime);
    }
  }

}

void btx_push_message_sampling_copyEU(
    void *
        btx_handle, const char* hostname, int64_t ts, uint64_t did, uint32_t deviceIdx, uint64_t hEngine, uint32_t subDevice, float activeTime) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 1);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 3);
  bt_message *_message = bt_message_event_create(
      common_data->self_message_iterator, _event_class, _stream);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_sampling_copyEU(
      _downstream_event, hostname, ts, did, deviceIdx, hEngine, subDevice, activeTime);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_sampling_fabricPort(
    bt_event *
        _event, const char* hostname, int64_t ts, uint64_t did, uint32_t deviceIdx, uint64_t hFabricPort, uint32_t subDevice, uint32_t portId, uint32_t remotePortId, float rxThroughput, float txThroughput, float rxSpeed, float txSpeed) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_string_set_value(_event_cc_f_m_0, (const char*)hostname);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_signed_set_value(_event_cc_f_m_1, (int64_t)ts);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_unsigned_set_value(_event_p_f_m_0, (uint64_t)did);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)deviceIdx);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_unsigned_set_value(_event_p_f_m_2, (uint64_t)hFabricPort);
    }
    {
      bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 3);
      bt_field_integer_unsigned_set_value(_event_p_f_m_3, (uint64_t)subDevice);
    }
    {
      bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 4);
      bt_field_integer_unsigned_set_value(_event_p_f_m_4, (uint64_t)portId);
    }
    {
      bt_field *_event_p_f_m_5 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 5);
      bt_field_integer_unsigned_set_value(_event_p_f_m_5, (uint64_t)remotePortId);
    }
    {
      bt_field *_event_p_f_m_6 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 6);
      bt_field_real_double_precision_set_value(_event_p_f_m_6, (double)rxThroughput);
    }
    {
      bt_field *_event_p_f_m_7 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 7);
      bt_field_real_double_precision_set_value(_event_p_f_m_7, (double)txThroughput);
    }
    {
      bt_field *_event_p_f_m_8 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 8);
      bt_field_real_double_precision_set_value(_event_p_f_m_8, (double)rxSpeed);
    }
    {
      bt_field *_event_p_f_m_9 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 9);
      bt_field_real_double_precision_set_value(_event_p_f_m_9, (double)txSpeed);
    }
  }

}

void btx_push_message_sampling_fabricPort(
    void *
        btx_handle, const char* hostname, int64_t ts, uint64_t did, uint32_t deviceIdx, uint64_t hFabricPort, uint32_t subDevice, uint32_t portId, uint32_t remotePortId, float rxThroughput, float txThroughput, float rxSpeed, float txSpeed) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 1);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 4);
  bt_message *_message = bt_message_event_create(
      common_data->self_message_iterator, _event_class, _stream);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_sampling_fabricPort(
      _downstream_event, hostname, ts, did, deviceIdx, hFabricPort, subDevice, portId, remotePortId, rxThroughput, txThroughput, rxSpeed, txSpeed);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_sampling_memModule(
    bt_event *
        _event, const char* hostname, int64_t ts, uint64_t did, uint32_t deviceIdx, uint64_t hMemModule, uint32_t subDevice, float pBandwidth, float rdBandwidth, float wtBandwidth, float occupancy) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_string_set_value(_event_cc_f_m_0, (const char*)hostname);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_signed_set_value(_event_cc_f_m_1, (int64_t)ts);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_unsigned_set_value(_event_p_f_m_0, (uint64_t)did);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)deviceIdx);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_unsigned_set_value(_event_p_f_m_2, (uint64_t)hMemModule);
    }
    {
      bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 3);
      bt_field_integer_unsigned_set_value(_event_p_f_m_3, (uint64_t)subDevice);
    }
    {
      bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 4);
      bt_field_real_double_precision_set_value(_event_p_f_m_4, (double)pBandwidth);
    }
    {
      bt_field *_event_p_f_m_5 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 5);
      bt_field_real_double_precision_set_value(_event_p_f_m_5, (double)rdBandwidth);
    }
    {
      bt_field *_event_p_f_m_6 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 6);
      bt_field_real_double_precision_set_value(_event_p_f_m_6, (double)wtBandwidth);
    }
    {
      bt_field *_event_p_f_m_7 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 7);
      bt_field_real_double_precision_set_value(_event_p_f_m_7, (double)occupancy);
    }
  }

}

void btx_push_message_sampling_memModule(
    void *
        btx_handle, const char* hostname, int64_t ts, uint64_t did, uint32_t deviceIdx, uint64_t hMemModule, uint32_t subDevice, float pBandwidth, float rdBandwidth, float wtBandwidth, float occupancy) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 1);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 5);
  bt_message *_message = bt_message_event_create(
      common_data->self_message_iterator, _event_class, _stream);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_sampling_memModule(
      _downstream_event, hostname, ts, did, deviceIdx, hMemModule, subDevice, pBandwidth, rdBandwidth, wtBandwidth, occupancy);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_sampling_nic(
    bt_event *
        _event, const char* hostname, int64_t ts, const char* interface_name, const char* counter, uint64_t value) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_string_set_value(_event_cc_f_m_0, (const char*)hostname);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_signed_set_value(_event_cc_f_m_1, (int64_t)ts);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_string_set_value(_event_p_f_m_0, (const char*)interface_name);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_string_set_value(_event_p_f_m_1, (const char*)counter);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_unsigned_set_value(_event_p_f_m_2, (uint64_t)value);
    }
  }

}

void btx_push_message_sampling_nic(
    void *
        btx_handle, const char* hostname, int64_t ts, const char* interface_name, const char* counter, uint64_t value) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 1);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 6);
  bt_message *_message = bt_message_event_create(
      common_data->self_message_iterator, _event_class, _stream);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_sampling_nic(
      _downstream_event, hostname, ts, interface_name, counter, value);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}

