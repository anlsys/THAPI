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
    bt_stream_class_set_name(_trace_class_sc_0, "interval_aggreg");
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
        _trace_class_sc_0_ecc_fc_m_3 = bt_field_class_string_create(_trace_class);
        bt_field_class_structure_append_member(_trace_class_sc_0_ecc_fc, "name", _trace_class_sc_0_ecc_fc_m_3);
        bt_field_class_put_ref(_trace_class_sc_0_ecc_fc_m_3);
      }
      {
        bt_field_class *_trace_class_sc_0_ecc_fc_m_4;
        _trace_class_sc_0_ecc_fc_m_4 = bt_field_class_integer_unsigned_create(_trace_class);
        bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ecc_fc_m_4, 64);
        bt_field_class_structure_append_member(_trace_class_sc_0_ecc_fc, "min", _trace_class_sc_0_ecc_fc_m_4);
        bt_field_class_put_ref(_trace_class_sc_0_ecc_fc_m_4);
      }
      {
        bt_field_class *_trace_class_sc_0_ecc_fc_m_5;
        _trace_class_sc_0_ecc_fc_m_5 = bt_field_class_integer_unsigned_create(_trace_class);
        bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ecc_fc_m_5, 64);
        bt_field_class_structure_append_member(_trace_class_sc_0_ecc_fc, "max", _trace_class_sc_0_ecc_fc_m_5);
        bt_field_class_put_ref(_trace_class_sc_0_ecc_fc_m_5);
      }
      {
        bt_field_class *_trace_class_sc_0_ecc_fc_m_6;
        _trace_class_sc_0_ecc_fc_m_6 = bt_field_class_integer_unsigned_create(_trace_class);
        bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ecc_fc_m_6, 64);
        bt_field_class_structure_append_member(_trace_class_sc_0_ecc_fc, "total", _trace_class_sc_0_ecc_fc_m_6);
        bt_field_class_put_ref(_trace_class_sc_0_ecc_fc_m_6);
      }
      {
        bt_field_class *_trace_class_sc_0_ecc_fc_m_7;
        _trace_class_sc_0_ecc_fc_m_7 = bt_field_class_integer_unsigned_create(_trace_class);
        bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ecc_fc_m_7, 64);
        bt_field_class_structure_append_member(_trace_class_sc_0_ecc_fc, "count", _trace_class_sc_0_ecc_fc_m_7);
        bt_field_class_put_ref(_trace_class_sc_0_ecc_fc_m_7);
      }
      bt_stream_class_set_event_common_context_field_class(_trace_class_sc_0, _trace_class_sc_0_ecc_fc);
      bt_field_class_put_ref(_trace_class_sc_0_ecc_fc);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_0;
      _trace_class_sc_0_ec_0 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_0, "aggreg:host");
      {
        bt_field_class *_trace_class_sc_0_ec_0_p_fc;
        _trace_class_sc_0_ec_0_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_0_p_fc_m_0;
          _trace_class_sc_0_ec_0_p_fc_m_0 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_0_p_fc_m_0, 64);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_0_p_fc, "backend", _trace_class_sc_0_ec_0_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_0_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_0_p_fc_m_1;
          _trace_class_sc_0_ec_0_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_0_p_fc_m_1, 64);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_0_p_fc, "err_count", _trace_class_sc_0_ec_0_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_0_p_fc_m_1);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_0, _trace_class_sc_0_ec_0_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_0_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_0);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_1;
      _trace_class_sc_0_ec_1 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_1, "aggreg:device");
      {
        bt_field_class *_trace_class_sc_0_ec_1_p_fc;
        _trace_class_sc_0_ec_1_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_1_p_fc_m_0;
          _trace_class_sc_0_ec_1_p_fc_m_0 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_1_p_fc_m_0, 64);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_1_p_fc, "did", _trace_class_sc_0_ec_1_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_1_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_1_p_fc_m_1;
          _trace_class_sc_0_ec_1_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_1_p_fc_m_1, 64);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_1_p_fc, "sdid", _trace_class_sc_0_ec_1_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_1_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_1_p_fc_m_2;
          _trace_class_sc_0_ec_1_p_fc_m_2 = bt_field_class_string_create(_trace_class);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_1_p_fc, "metadata", _trace_class_sc_0_ec_1_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_0_ec_1_p_fc_m_2);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_1, _trace_class_sc_0_ec_1_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_1_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_1);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_2;
      _trace_class_sc_0_ec_2 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_2, "aggreg:traffic");
      {
        bt_field_class *_trace_class_sc_0_ec_2_p_fc;
        _trace_class_sc_0_ec_2_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_2_p_fc_m_0;
          _trace_class_sc_0_ec_2_p_fc_m_0 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_2_p_fc_m_0, 64);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_2_p_fc, "backend", _trace_class_sc_0_ec_2_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_2_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_2_p_fc_m_1;
          _trace_class_sc_0_ec_2_p_fc_m_1 = bt_field_class_string_create(_trace_class);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_2_p_fc, "metadata", _trace_class_sc_0_ec_2_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_2_p_fc_m_1);
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
    bt_stream_class_set_name(_trace_class_sc_1, "interval");
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
        bt_field_class_structure_append_member(_trace_class_sc_1_ecc_fc, "vpid", _trace_class_sc_1_ecc_fc_m_1);
        bt_field_class_put_ref(_trace_class_sc_1_ecc_fc_m_1);
      }
      {
        bt_field_class *_trace_class_sc_1_ecc_fc_m_2;
        _trace_class_sc_1_ecc_fc_m_2 = bt_field_class_integer_unsigned_create(_trace_class);
        bt_field_class_integer_set_field_value_range(_trace_class_sc_1_ecc_fc_m_2, 64);
        bt_field_class_structure_append_member(_trace_class_sc_1_ecc_fc, "vtid", _trace_class_sc_1_ecc_fc_m_2);
        bt_field_class_put_ref(_trace_class_sc_1_ecc_fc_m_2);
      }
      {
        bt_field_class *_trace_class_sc_1_ecc_fc_m_3;
        _trace_class_sc_1_ecc_fc_m_3 = bt_field_class_integer_signed_create(_trace_class);
        bt_field_class_integer_set_field_value_range(_trace_class_sc_1_ecc_fc_m_3, 64);
        bt_field_class_structure_append_member(_trace_class_sc_1_ecc_fc, "ts", _trace_class_sc_1_ecc_fc_m_3);
        bt_field_class_put_ref(_trace_class_sc_1_ecc_fc_m_3);
      }
      {
        bt_field_class *_trace_class_sc_1_ecc_fc_m_4;
        _trace_class_sc_1_ecc_fc_m_4 = bt_field_class_integer_signed_create(_trace_class);
        bt_field_class_integer_set_field_value_range(_trace_class_sc_1_ecc_fc_m_4, 64);
        bt_field_class_structure_append_member(_trace_class_sc_1_ecc_fc, "backend", _trace_class_sc_1_ecc_fc_m_4);
        bt_field_class_put_ref(_trace_class_sc_1_ecc_fc_m_4);
      }
      bt_stream_class_set_event_common_context_field_class(_trace_class_sc_1, _trace_class_sc_1_ecc_fc);
      bt_field_class_put_ref(_trace_class_sc_1_ecc_fc);
    }
    {
      bt_event_class *_trace_class_sc_1_ec_0;
      _trace_class_sc_1_ec_0 = bt_event_class_create(_trace_class_sc_1);
      bt_event_class_set_name(_trace_class_sc_1_ec_0, "lttng:device_name");
      {
        bt_field_class *_trace_class_sc_1_ec_0_p_fc;
        _trace_class_sc_1_ec_0_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_1_ec_0_p_fc_m_0;
          _trace_class_sc_1_ec_0_p_fc_m_0 = bt_field_class_string_create(_trace_class);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_0_p_fc, "name", _trace_class_sc_1_ec_0_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_1_ec_0_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_1_ec_0_p_fc_m_1;
          _trace_class_sc_1_ec_0_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_1_ec_0_p_fc_m_1, 64);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_0_p_fc, "did", _trace_class_sc_1_ec_0_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_1_ec_0_p_fc_m_1);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_1_ec_0, _trace_class_sc_1_ec_0_p_fc);
        bt_field_class_put_ref(_trace_class_sc_1_ec_0_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_1_ec_0);
    }
    {
      bt_event_class *_trace_class_sc_1_ec_1;
      _trace_class_sc_1_ec_1 = bt_event_class_create(_trace_class_sc_1);
      bt_event_class_set_name(_trace_class_sc_1_ec_1, "lttng_ust_thapi:metadata");
      {
        bt_field_class *_trace_class_sc_1_ec_1_p_fc;
        _trace_class_sc_1_ec_1_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_1_ec_1_p_fc_m_0;
          _trace_class_sc_1_ec_1_p_fc_m_0 = bt_field_class_string_create(_trace_class);
          bt_field_class_structure_append_member(_trace_class_sc_1_ec_1_p_fc, "metadata", _trace_class_sc_1_ec_1_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_1_ec_1_p_fc_m_0);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_1_ec_1, _trace_class_sc_1_ec_1_p_fc);
        bt_field_class_put_ref(_trace_class_sc_1_ec_1_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_1_ec_1);
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

static void btx_set_message_aggreg_host(
    bt_event *
        _event, const char* hostname, int64_t vpid, uint64_t vtid, const char* name, uint64_t min, uint64_t max, uint64_t total, uint64_t count, uint64_t backend, uint64_t err_count) {
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
      bt_field_string_set_value(_event_cc_f_m_3, (const char*)name);
    }
    {
      bt_field *_event_cc_f_m_4 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 4);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_4, (uint64_t)min);
    }
    {
      bt_field *_event_cc_f_m_5 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 5);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_5, (uint64_t)max);
    }
    {
      bt_field *_event_cc_f_m_6 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 6);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_6, (uint64_t)total);
    }
    {
      bt_field *_event_cc_f_m_7 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 7);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_7, (uint64_t)count);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_unsigned_set_value(_event_p_f_m_0, (uint64_t)backend);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)err_count);
    }
  }

}

void btx_push_message_aggreg_host(
    void *
        btx_handle, const char* hostname, int64_t vpid, uint64_t vtid, const char* name, uint64_t min, uint64_t max, uint64_t total, uint64_t count, uint64_t backend, uint64_t err_count) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 0);
  bt_message *_message = bt_message_event_create(
      common_data->self_message_iterator, _event_class, _stream);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_aggreg_host(
      _downstream_event, hostname, vpid, vtid, name, min, max, total, count, backend, err_count);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_aggreg_device(
    bt_event *
        _event, const char* hostname, int64_t vpid, uint64_t vtid, const char* name, uint64_t min, uint64_t max, uint64_t total, uint64_t count, uint64_t did, uint64_t sdid, const char* metadata) {
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
      bt_field_string_set_value(_event_cc_f_m_3, (const char*)name);
    }
    {
      bt_field *_event_cc_f_m_4 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 4);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_4, (uint64_t)min);
    }
    {
      bt_field *_event_cc_f_m_5 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 5);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_5, (uint64_t)max);
    }
    {
      bt_field *_event_cc_f_m_6 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 6);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_6, (uint64_t)total);
    }
    {
      bt_field *_event_cc_f_m_7 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 7);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_7, (uint64_t)count);
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
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)sdid);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_string_set_value(_event_p_f_m_2, (const char*)metadata);
    }
  }

}

void btx_push_message_aggreg_device(
    void *
        btx_handle, const char* hostname, int64_t vpid, uint64_t vtid, const char* name, uint64_t min, uint64_t max, uint64_t total, uint64_t count, uint64_t did, uint64_t sdid, const char* metadata) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 1);
  bt_message *_message = bt_message_event_create(
      common_data->self_message_iterator, _event_class, _stream);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_aggreg_device(
      _downstream_event, hostname, vpid, vtid, name, min, max, total, count, did, sdid, metadata);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_aggreg_traffic(
    bt_event *
        _event, const char* hostname, int64_t vpid, uint64_t vtid, const char* name, uint64_t min, uint64_t max, uint64_t total, uint64_t count, uint64_t backend, const char* metadata) {
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
      bt_field_string_set_value(_event_cc_f_m_3, (const char*)name);
    }
    {
      bt_field *_event_cc_f_m_4 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 4);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_4, (uint64_t)min);
    }
    {
      bt_field *_event_cc_f_m_5 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 5);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_5, (uint64_t)max);
    }
    {
      bt_field *_event_cc_f_m_6 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 6);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_6, (uint64_t)total);
    }
    {
      bt_field *_event_cc_f_m_7 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 7);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_7, (uint64_t)count);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_unsigned_set_value(_event_p_f_m_0, (uint64_t)backend);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_string_set_value(_event_p_f_m_1, (const char*)metadata);
    }
  }

}

void btx_push_message_aggreg_traffic(
    void *
        btx_handle, const char* hostname, int64_t vpid, uint64_t vtid, const char* name, uint64_t min, uint64_t max, uint64_t total, uint64_t count, uint64_t backend, const char* metadata) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 2);
  bt_message *_message = bt_message_event_create(
      common_data->self_message_iterator, _event_class, _stream);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_aggreg_traffic(
      _downstream_event, hostname, vpid, vtid, name, min, max, total, count, backend, metadata);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_device_name(
    bt_event *
        _event, const char* hostname, int64_t vpid, uint64_t vtid, int64_t ts, int64_t backend, const char* name, uint64_t did) {
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
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)did);
    }
  }

}

void btx_push_message_lttng_device_name(
    void *
        btx_handle, const char* hostname, int64_t vpid, uint64_t vtid, int64_t ts, int64_t backend, const char* name, uint64_t did) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 1);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 0);
  bt_message *_message = bt_message_event_create(
      common_data->self_message_iterator, _event_class, _stream);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_device_name(
      _downstream_event, hostname, vpid, vtid, ts, backend, name, did);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_thapi_metadata(
    bt_event *
        _event, const char* hostname, int64_t vpid, uint64_t vtid, int64_t ts, int64_t backend, const char* metadata) {
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
      bt_field_string_set_value(_event_p_f_m_0, (const char*)metadata);
    }
  }

}

void btx_push_message_lttng_ust_thapi_metadata(
    void *
        btx_handle, const char* hostname, int64_t vpid, uint64_t vtid, int64_t ts, int64_t backend, const char* metadata) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 1);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 1);
  bt_message *_message = bt_message_event_create(
      common_data->self_message_iterator, _event_class, _stream);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_thapi_metadata(
      _downstream_event, hostname, vpid, vtid, ts, backend, metadata);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}

