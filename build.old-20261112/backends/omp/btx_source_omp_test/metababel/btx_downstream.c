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
    bt_stream_class_set_name(_trace_class_sc_0, "thapi_omp");
    {
      bt_clock_class *_trace_class_sc_0_dcc;
      _trace_class_sc_0_dcc = bt_clock_class_create(_self_component);
      bt_stream_class_set_default_clock_class(_trace_class_sc_0, _trace_class_sc_0_dcc);
      bt_clock_class_put_ref(_trace_class_sc_0_dcc);
    }
    bt_stream_class_set_supports_packets(_trace_class_sc_0, BT_TRUE, BT_FALSE, BT_FALSE);
    {
      bt_field_class *_trace_class_sc_0_pc_fc;
      _trace_class_sc_0_pc_fc = bt_field_class_structure_create(_trace_class);
      {
        bt_field_class *_trace_class_sc_0_pc_fc_m_0;
        _trace_class_sc_0_pc_fc_m_0 = bt_field_class_integer_unsigned_create(_trace_class);
        bt_field_class_integer_set_field_value_range(_trace_class_sc_0_pc_fc_m_0, 32);
        bt_field_class_structure_append_member(_trace_class_sc_0_pc_fc, "cpu_id", _trace_class_sc_0_pc_fc_m_0);
        bt_field_class_put_ref(_trace_class_sc_0_pc_fc_m_0);
      }
      bt_stream_class_set_packet_context_field_class(_trace_class_sc_0, _trace_class_sc_0_pc_fc);
      bt_field_class_put_ref(_trace_class_sc_0_pc_fc);
    }
    {
      bt_field_class *_trace_class_sc_0_ecc_fc;
      _trace_class_sc_0_ecc_fc = bt_field_class_structure_create(_trace_class);
      {
        bt_field_class *_trace_class_sc_0_ecc_fc_m_0;
        _trace_class_sc_0_ecc_fc_m_0 = bt_field_class_integer_signed_create(_trace_class);
        bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ecc_fc_m_0, 64);
        bt_field_class_structure_append_member(_trace_class_sc_0_ecc_fc, "vpid", _trace_class_sc_0_ecc_fc_m_0);
        bt_field_class_put_ref(_trace_class_sc_0_ecc_fc_m_0);
      }
      {
        bt_field_class *_trace_class_sc_0_ecc_fc_m_1;
        _trace_class_sc_0_ecc_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
        bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ecc_fc_m_1, 64);
        bt_field_class_structure_append_member(_trace_class_sc_0_ecc_fc, "vtid", _trace_class_sc_0_ecc_fc_m_1);
        bt_field_class_put_ref(_trace_class_sc_0_ecc_fc_m_1);
      }
      bt_stream_class_set_event_common_context_field_class(_trace_class_sc_0, _trace_class_sc_0_ecc_fc);
      bt_field_class_put_ref(_trace_class_sc_0_ecc_fc);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_0;
      _trace_class_sc_0_ec_0 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_0, "lttng_ust_ompt:ompt_callback_thread_begin");
      {
        bt_field_class *_trace_class_sc_0_ec_0_p_fc;
        _trace_class_sc_0_ec_0_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_0_p_fc_m_0;
          _trace_class_sc_0_ec_0_p_fc_m_0 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_0_p_fc_m_0, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_0_p_fc, "thread_type", _trace_class_sc_0_ec_0_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_0_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_0_p_fc_m_1;
          _trace_class_sc_0_ec_0_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_0_p_fc_m_1, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_0_p_fc_m_1, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_0_p_fc, "thread_data", _trace_class_sc_0_ec_0_p_fc_m_1);
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
      bt_event_class_set_name(_trace_class_sc_0_ec_1, "lttng_ust_ompt:ompt_callback_thread_end");
      {
        bt_field_class *_trace_class_sc_0_ec_1_p_fc;
        _trace_class_sc_0_ec_1_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_1_p_fc_m_0;
          _trace_class_sc_0_ec_1_p_fc_m_0 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_1_p_fc_m_0, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_1_p_fc_m_0, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_1_p_fc, "thread_data", _trace_class_sc_0_ec_1_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_1_p_fc_m_0);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_1, _trace_class_sc_0_ec_1_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_1_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_1);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_2;
      _trace_class_sc_0_ec_2 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_2, "lttng_ust_ompt:ompt_callback_parallel_begin");
      {
        bt_field_class *_trace_class_sc_0_ec_2_p_fc;
        _trace_class_sc_0_ec_2_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_2_p_fc_m_0;
          _trace_class_sc_0_ec_2_p_fc_m_0 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_2_p_fc_m_0, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_2_p_fc_m_0, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_2_p_fc, "encountering_task_data", _trace_class_sc_0_ec_2_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_2_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_2_p_fc_m_1;
          _trace_class_sc_0_ec_2_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_2_p_fc_m_1, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_2_p_fc_m_1, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_2_p_fc, "encountering_task_frame", _trace_class_sc_0_ec_2_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_2_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_2_p_fc_m_2;
          _trace_class_sc_0_ec_2_p_fc_m_2 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_2_p_fc_m_2, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_2_p_fc_m_2, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_2_p_fc, "parallel_data", _trace_class_sc_0_ec_2_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_0_ec_2_p_fc_m_2);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_2_p_fc_m_3;
          _trace_class_sc_0_ec_2_p_fc_m_3 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_2_p_fc_m_3, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_2_p_fc, "requested_parallelism", _trace_class_sc_0_ec_2_p_fc_m_3);
          bt_field_class_put_ref(_trace_class_sc_0_ec_2_p_fc_m_3);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_2_p_fc_m_4;
          _trace_class_sc_0_ec_2_p_fc_m_4 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_2_p_fc_m_4, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_2_p_fc, "flags", _trace_class_sc_0_ec_2_p_fc_m_4);
          bt_field_class_put_ref(_trace_class_sc_0_ec_2_p_fc_m_4);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_2_p_fc_m_5;
          _trace_class_sc_0_ec_2_p_fc_m_5 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_2_p_fc_m_5, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_2_p_fc_m_5, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_2_p_fc, "codeptr_ra", _trace_class_sc_0_ec_2_p_fc_m_5);
          bt_field_class_put_ref(_trace_class_sc_0_ec_2_p_fc_m_5);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_2, _trace_class_sc_0_ec_2_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_2_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_2);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_3;
      _trace_class_sc_0_ec_3 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_3, "lttng_ust_ompt:ompt_callback_parallel_end");
      {
        bt_field_class *_trace_class_sc_0_ec_3_p_fc;
        _trace_class_sc_0_ec_3_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_3_p_fc_m_0;
          _trace_class_sc_0_ec_3_p_fc_m_0 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_3_p_fc_m_0, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_3_p_fc_m_0, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_3_p_fc, "parallel_data", _trace_class_sc_0_ec_3_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_3_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_3_p_fc_m_1;
          _trace_class_sc_0_ec_3_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_3_p_fc_m_1, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_3_p_fc_m_1, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_3_p_fc, "encountering_task_data", _trace_class_sc_0_ec_3_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_3_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_3_p_fc_m_2;
          _trace_class_sc_0_ec_3_p_fc_m_2 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_3_p_fc_m_2, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_3_p_fc, "flags", _trace_class_sc_0_ec_3_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_0_ec_3_p_fc_m_2);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_3_p_fc_m_3;
          _trace_class_sc_0_ec_3_p_fc_m_3 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_3_p_fc_m_3, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_3_p_fc_m_3, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_3_p_fc, "codeptr_ra", _trace_class_sc_0_ec_3_p_fc_m_3);
          bt_field_class_put_ref(_trace_class_sc_0_ec_3_p_fc_m_3);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_3, _trace_class_sc_0_ec_3_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_3_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_3);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_4;
      _trace_class_sc_0_ec_4 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_4, "lttng_ust_ompt:ompt_callback_work");
      {
        bt_field_class *_trace_class_sc_0_ec_4_p_fc;
        _trace_class_sc_0_ec_4_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_4_p_fc_m_0;
          _trace_class_sc_0_ec_4_p_fc_m_0 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_4_p_fc_m_0, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_4_p_fc, "work_type", _trace_class_sc_0_ec_4_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_4_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_4_p_fc_m_1;
          _trace_class_sc_0_ec_4_p_fc_m_1 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_4_p_fc_m_1, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_4_p_fc, "endpoint", _trace_class_sc_0_ec_4_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_4_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_4_p_fc_m_2;
          _trace_class_sc_0_ec_4_p_fc_m_2 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_4_p_fc_m_2, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_4_p_fc_m_2, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_4_p_fc, "parallel_data", _trace_class_sc_0_ec_4_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_0_ec_4_p_fc_m_2);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_4_p_fc_m_3;
          _trace_class_sc_0_ec_4_p_fc_m_3 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_4_p_fc_m_3, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_4_p_fc_m_3, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_4_p_fc, "task_data", _trace_class_sc_0_ec_4_p_fc_m_3);
          bt_field_class_put_ref(_trace_class_sc_0_ec_4_p_fc_m_3);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_4_p_fc_m_4;
          _trace_class_sc_0_ec_4_p_fc_m_4 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_4_p_fc_m_4, 64);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_4_p_fc, "count", _trace_class_sc_0_ec_4_p_fc_m_4);
          bt_field_class_put_ref(_trace_class_sc_0_ec_4_p_fc_m_4);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_4_p_fc_m_5;
          _trace_class_sc_0_ec_4_p_fc_m_5 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_4_p_fc_m_5, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_4_p_fc_m_5, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_4_p_fc, "codeptr_ra", _trace_class_sc_0_ec_4_p_fc_m_5);
          bt_field_class_put_ref(_trace_class_sc_0_ec_4_p_fc_m_5);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_4, _trace_class_sc_0_ec_4_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_4_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_4);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_5;
      _trace_class_sc_0_ec_5 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_5, "lttng_ust_ompt:ompt_callback_dispatch");
      {
        bt_field_class *_trace_class_sc_0_ec_5_p_fc;
        _trace_class_sc_0_ec_5_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_5_p_fc_m_0;
          _trace_class_sc_0_ec_5_p_fc_m_0 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_5_p_fc_m_0, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_5_p_fc_m_0, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_5_p_fc, "parallel_data", _trace_class_sc_0_ec_5_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_5_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_5_p_fc_m_1;
          _trace_class_sc_0_ec_5_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_5_p_fc_m_1, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_5_p_fc_m_1, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_5_p_fc, "task_data", _trace_class_sc_0_ec_5_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_5_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_5_p_fc_m_2;
          _trace_class_sc_0_ec_5_p_fc_m_2 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_5_p_fc_m_2, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_5_p_fc, "kind", _trace_class_sc_0_ec_5_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_0_ec_5_p_fc_m_2);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_5_p_fc_m_3;
          _trace_class_sc_0_ec_5_p_fc_m_3 = bt_field_class_string_create(_trace_class);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_5_p_fc, "instance", _trace_class_sc_0_ec_5_p_fc_m_3);
          bt_field_class_put_ref(_trace_class_sc_0_ec_5_p_fc_m_3);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_5, _trace_class_sc_0_ec_5_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_5_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_5);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_6;
      _trace_class_sc_0_ec_6 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_6, "lttng_ust_ompt:ompt_callback_task_create");
      {
        bt_field_class *_trace_class_sc_0_ec_6_p_fc;
        _trace_class_sc_0_ec_6_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_6_p_fc_m_0;
          _trace_class_sc_0_ec_6_p_fc_m_0 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_6_p_fc_m_0, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_6_p_fc_m_0, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_6_p_fc, "encountering_task_data", _trace_class_sc_0_ec_6_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_6_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_6_p_fc_m_1;
          _trace_class_sc_0_ec_6_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_6_p_fc_m_1, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_6_p_fc_m_1, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_6_p_fc, "encountering_task_frame", _trace_class_sc_0_ec_6_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_6_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_6_p_fc_m_2;
          _trace_class_sc_0_ec_6_p_fc_m_2 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_6_p_fc_m_2, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_6_p_fc_m_2, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_6_p_fc, "new_task_data", _trace_class_sc_0_ec_6_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_0_ec_6_p_fc_m_2);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_6_p_fc_m_3;
          _trace_class_sc_0_ec_6_p_fc_m_3 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_6_p_fc_m_3, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_6_p_fc, "flags", _trace_class_sc_0_ec_6_p_fc_m_3);
          bt_field_class_put_ref(_trace_class_sc_0_ec_6_p_fc_m_3);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_6_p_fc_m_4;
          _trace_class_sc_0_ec_6_p_fc_m_4 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_6_p_fc_m_4, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_6_p_fc, "has_dependences", _trace_class_sc_0_ec_6_p_fc_m_4);
          bt_field_class_put_ref(_trace_class_sc_0_ec_6_p_fc_m_4);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_6_p_fc_m_5;
          _trace_class_sc_0_ec_6_p_fc_m_5 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_6_p_fc_m_5, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_6_p_fc_m_5, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_6_p_fc, "codeptr_ra", _trace_class_sc_0_ec_6_p_fc_m_5);
          bt_field_class_put_ref(_trace_class_sc_0_ec_6_p_fc_m_5);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_6, _trace_class_sc_0_ec_6_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_6_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_6);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_7;
      _trace_class_sc_0_ec_7 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_7, "lttng_ust_ompt:ompt_callback_dependences");
      {
        bt_field_class *_trace_class_sc_0_ec_7_p_fc;
        _trace_class_sc_0_ec_7_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_7_p_fc_m_0;
          _trace_class_sc_0_ec_7_p_fc_m_0 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_7_p_fc_m_0, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_7_p_fc_m_0, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_7_p_fc, "task_data", _trace_class_sc_0_ec_7_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_7_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_7_p_fc_m_1;
          _trace_class_sc_0_ec_7_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_7_p_fc_m_1, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_7_p_fc_m_1, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_7_p_fc, "deps", _trace_class_sc_0_ec_7_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_7_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_7_p_fc_m_2;
          _trace_class_sc_0_ec_7_p_fc_m_2 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_7_p_fc_m_2, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_7_p_fc, "ndeps", _trace_class_sc_0_ec_7_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_0_ec_7_p_fc_m_2);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_7, _trace_class_sc_0_ec_7_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_7_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_7);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_8;
      _trace_class_sc_0_ec_8 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_8, "lttng_ust_ompt:ompt_callback_task_dependence");
      {
        bt_field_class *_trace_class_sc_0_ec_8_p_fc;
        _trace_class_sc_0_ec_8_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_8_p_fc_m_0;
          _trace_class_sc_0_ec_8_p_fc_m_0 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_8_p_fc_m_0, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_8_p_fc_m_0, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_8_p_fc, "src_task_data", _trace_class_sc_0_ec_8_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_8_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_8_p_fc_m_1;
          _trace_class_sc_0_ec_8_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_8_p_fc_m_1, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_8_p_fc_m_1, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_8_p_fc, "sink_task_data", _trace_class_sc_0_ec_8_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_8_p_fc_m_1);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_8, _trace_class_sc_0_ec_8_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_8_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_8);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_9;
      _trace_class_sc_0_ec_9 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_9, "lttng_ust_ompt:ompt_callback_task_schedule");
      {
        bt_field_class *_trace_class_sc_0_ec_9_p_fc;
        _trace_class_sc_0_ec_9_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_9_p_fc_m_0;
          _trace_class_sc_0_ec_9_p_fc_m_0 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_9_p_fc_m_0, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_9_p_fc_m_0, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_9_p_fc, "prior_task_data", _trace_class_sc_0_ec_9_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_9_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_9_p_fc_m_1;
          _trace_class_sc_0_ec_9_p_fc_m_1 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_9_p_fc_m_1, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_9_p_fc, "prior_task_status", _trace_class_sc_0_ec_9_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_9_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_9_p_fc_m_2;
          _trace_class_sc_0_ec_9_p_fc_m_2 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_9_p_fc_m_2, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_9_p_fc_m_2, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_9_p_fc, "next_task_data", _trace_class_sc_0_ec_9_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_0_ec_9_p_fc_m_2);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_9, _trace_class_sc_0_ec_9_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_9_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_9);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_10;
      _trace_class_sc_0_ec_10 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_10, "lttng_ust_ompt:ompt_callback_implicit_task");
      {
        bt_field_class *_trace_class_sc_0_ec_10_p_fc;
        _trace_class_sc_0_ec_10_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_10_p_fc_m_0;
          _trace_class_sc_0_ec_10_p_fc_m_0 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_10_p_fc_m_0, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_10_p_fc, "endpoint", _trace_class_sc_0_ec_10_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_10_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_10_p_fc_m_1;
          _trace_class_sc_0_ec_10_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_10_p_fc_m_1, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_10_p_fc_m_1, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_10_p_fc, "parallel_data", _trace_class_sc_0_ec_10_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_10_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_10_p_fc_m_2;
          _trace_class_sc_0_ec_10_p_fc_m_2 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_10_p_fc_m_2, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_10_p_fc_m_2, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_10_p_fc, "task_data", _trace_class_sc_0_ec_10_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_0_ec_10_p_fc_m_2);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_10_p_fc_m_3;
          _trace_class_sc_0_ec_10_p_fc_m_3 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_10_p_fc_m_3, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_10_p_fc, "actual_parallelism", _trace_class_sc_0_ec_10_p_fc_m_3);
          bt_field_class_put_ref(_trace_class_sc_0_ec_10_p_fc_m_3);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_10_p_fc_m_4;
          _trace_class_sc_0_ec_10_p_fc_m_4 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_10_p_fc_m_4, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_10_p_fc, "index", _trace_class_sc_0_ec_10_p_fc_m_4);
          bt_field_class_put_ref(_trace_class_sc_0_ec_10_p_fc_m_4);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_10_p_fc_m_5;
          _trace_class_sc_0_ec_10_p_fc_m_5 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_10_p_fc_m_5, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_10_p_fc, "flags", _trace_class_sc_0_ec_10_p_fc_m_5);
          bt_field_class_put_ref(_trace_class_sc_0_ec_10_p_fc_m_5);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_10, _trace_class_sc_0_ec_10_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_10_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_10);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_11;
      _trace_class_sc_0_ec_11 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_11, "lttng_ust_ompt:ompt_callback_masked");
      {
        bt_field_class *_trace_class_sc_0_ec_11_p_fc;
        _trace_class_sc_0_ec_11_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_11_p_fc_m_0;
          _trace_class_sc_0_ec_11_p_fc_m_0 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_11_p_fc_m_0, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_11_p_fc, "endpoint", _trace_class_sc_0_ec_11_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_11_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_11_p_fc_m_1;
          _trace_class_sc_0_ec_11_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_11_p_fc_m_1, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_11_p_fc_m_1, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_11_p_fc, "parallel_data", _trace_class_sc_0_ec_11_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_11_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_11_p_fc_m_2;
          _trace_class_sc_0_ec_11_p_fc_m_2 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_11_p_fc_m_2, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_11_p_fc_m_2, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_11_p_fc, "task_data", _trace_class_sc_0_ec_11_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_0_ec_11_p_fc_m_2);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_11_p_fc_m_3;
          _trace_class_sc_0_ec_11_p_fc_m_3 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_11_p_fc_m_3, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_11_p_fc_m_3, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_11_p_fc, "codeptr_ra", _trace_class_sc_0_ec_11_p_fc_m_3);
          bt_field_class_put_ref(_trace_class_sc_0_ec_11_p_fc_m_3);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_11, _trace_class_sc_0_ec_11_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_11_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_11);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_12;
      _trace_class_sc_0_ec_12 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_12, "lttng_ust_ompt:ompt_callback_sync_region");
      {
        bt_field_class *_trace_class_sc_0_ec_12_p_fc;
        _trace_class_sc_0_ec_12_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_12_p_fc_m_0;
          _trace_class_sc_0_ec_12_p_fc_m_0 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_12_p_fc_m_0, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_12_p_fc, "kind", _trace_class_sc_0_ec_12_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_12_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_12_p_fc_m_1;
          _trace_class_sc_0_ec_12_p_fc_m_1 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_12_p_fc_m_1, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_12_p_fc, "endpoint", _trace_class_sc_0_ec_12_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_12_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_12_p_fc_m_2;
          _trace_class_sc_0_ec_12_p_fc_m_2 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_12_p_fc_m_2, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_12_p_fc_m_2, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_12_p_fc, "parallel_data", _trace_class_sc_0_ec_12_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_0_ec_12_p_fc_m_2);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_12_p_fc_m_3;
          _trace_class_sc_0_ec_12_p_fc_m_3 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_12_p_fc_m_3, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_12_p_fc_m_3, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_12_p_fc, "task_data", _trace_class_sc_0_ec_12_p_fc_m_3);
          bt_field_class_put_ref(_trace_class_sc_0_ec_12_p_fc_m_3);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_12_p_fc_m_4;
          _trace_class_sc_0_ec_12_p_fc_m_4 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_12_p_fc_m_4, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_12_p_fc_m_4, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_12_p_fc, "codeptr_ra", _trace_class_sc_0_ec_12_p_fc_m_4);
          bt_field_class_put_ref(_trace_class_sc_0_ec_12_p_fc_m_4);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_12, _trace_class_sc_0_ec_12_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_12_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_12);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_13;
      _trace_class_sc_0_ec_13 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_13, "lttng_ust_ompt:ompt_callback_mutex_acquire");
      {
        bt_field_class *_trace_class_sc_0_ec_13_p_fc;
        _trace_class_sc_0_ec_13_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_13_p_fc_m_0;
          _trace_class_sc_0_ec_13_p_fc_m_0 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_13_p_fc_m_0, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_13_p_fc, "kind", _trace_class_sc_0_ec_13_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_13_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_13_p_fc_m_1;
          _trace_class_sc_0_ec_13_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_13_p_fc_m_1, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_13_p_fc, "hint", _trace_class_sc_0_ec_13_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_13_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_13_p_fc_m_2;
          _trace_class_sc_0_ec_13_p_fc_m_2 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_13_p_fc_m_2, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_13_p_fc, "impl", _trace_class_sc_0_ec_13_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_0_ec_13_p_fc_m_2);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_13_p_fc_m_3;
          _trace_class_sc_0_ec_13_p_fc_m_3 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_13_p_fc_m_3, 64);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_13_p_fc, "wait_id", _trace_class_sc_0_ec_13_p_fc_m_3);
          bt_field_class_put_ref(_trace_class_sc_0_ec_13_p_fc_m_3);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_13_p_fc_m_4;
          _trace_class_sc_0_ec_13_p_fc_m_4 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_13_p_fc_m_4, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_13_p_fc_m_4, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_13_p_fc, "codeptr_ra", _trace_class_sc_0_ec_13_p_fc_m_4);
          bt_field_class_put_ref(_trace_class_sc_0_ec_13_p_fc_m_4);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_13, _trace_class_sc_0_ec_13_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_13_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_13);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_14;
      _trace_class_sc_0_ec_14 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_14, "lttng_ust_ompt:ompt_callback_mutex");
      {
        bt_field_class *_trace_class_sc_0_ec_14_p_fc;
        _trace_class_sc_0_ec_14_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_14_p_fc_m_0;
          _trace_class_sc_0_ec_14_p_fc_m_0 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_14_p_fc_m_0, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_14_p_fc, "kind", _trace_class_sc_0_ec_14_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_14_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_14_p_fc_m_1;
          _trace_class_sc_0_ec_14_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_14_p_fc_m_1, 64);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_14_p_fc, "wait_id", _trace_class_sc_0_ec_14_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_14_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_14_p_fc_m_2;
          _trace_class_sc_0_ec_14_p_fc_m_2 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_14_p_fc_m_2, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_14_p_fc_m_2, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_14_p_fc, "codeptr_ra", _trace_class_sc_0_ec_14_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_0_ec_14_p_fc_m_2);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_14, _trace_class_sc_0_ec_14_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_14_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_14);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_15;
      _trace_class_sc_0_ec_15 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_15, "lttng_ust_ompt:ompt_callback_nest_lock");
      {
        bt_field_class *_trace_class_sc_0_ec_15_p_fc;
        _trace_class_sc_0_ec_15_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_15_p_fc_m_0;
          _trace_class_sc_0_ec_15_p_fc_m_0 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_15_p_fc_m_0, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_15_p_fc, "endpoint", _trace_class_sc_0_ec_15_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_15_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_15_p_fc_m_1;
          _trace_class_sc_0_ec_15_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_15_p_fc_m_1, 64);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_15_p_fc, "wait_id", _trace_class_sc_0_ec_15_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_15_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_15_p_fc_m_2;
          _trace_class_sc_0_ec_15_p_fc_m_2 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_15_p_fc_m_2, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_15_p_fc_m_2, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_15_p_fc, "codeptr_ra", _trace_class_sc_0_ec_15_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_0_ec_15_p_fc_m_2);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_15, _trace_class_sc_0_ec_15_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_15_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_15);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_16;
      _trace_class_sc_0_ec_16 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_16, "lttng_ust_ompt:ompt_callback_flush");
      {
        bt_field_class *_trace_class_sc_0_ec_16_p_fc;
        _trace_class_sc_0_ec_16_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_16_p_fc_m_0;
          _trace_class_sc_0_ec_16_p_fc_m_0 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_16_p_fc_m_0, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_16_p_fc_m_0, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_16_p_fc, "thread_data", _trace_class_sc_0_ec_16_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_16_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_16_p_fc_m_1;
          _trace_class_sc_0_ec_16_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_16_p_fc_m_1, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_16_p_fc_m_1, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_16_p_fc, "codeptr_ra", _trace_class_sc_0_ec_16_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_16_p_fc_m_1);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_16, _trace_class_sc_0_ec_16_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_16_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_16);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_17;
      _trace_class_sc_0_ec_17 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_17, "lttng_ust_ompt:ompt_callback_cancel");
      {
        bt_field_class *_trace_class_sc_0_ec_17_p_fc;
        _trace_class_sc_0_ec_17_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_17_p_fc_m_0;
          _trace_class_sc_0_ec_17_p_fc_m_0 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_17_p_fc_m_0, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_17_p_fc_m_0, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_17_p_fc, "task_data", _trace_class_sc_0_ec_17_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_17_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_17_p_fc_m_1;
          _trace_class_sc_0_ec_17_p_fc_m_1 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_17_p_fc_m_1, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_17_p_fc, "flags", _trace_class_sc_0_ec_17_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_17_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_17_p_fc_m_2;
          _trace_class_sc_0_ec_17_p_fc_m_2 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_17_p_fc_m_2, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_17_p_fc_m_2, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_17_p_fc, "codeptr_ra", _trace_class_sc_0_ec_17_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_0_ec_17_p_fc_m_2);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_17, _trace_class_sc_0_ec_17_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_17_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_17);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_18;
      _trace_class_sc_0_ec_18 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_18, "lttng_ust_ompt:ompt_callback_device_initialize");
      {
        bt_field_class *_trace_class_sc_0_ec_18_p_fc;
        _trace_class_sc_0_ec_18_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_18_p_fc_m_0;
          _trace_class_sc_0_ec_18_p_fc_m_0 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_18_p_fc_m_0, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_18_p_fc, "device_num", _trace_class_sc_0_ec_18_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_18_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_18_p_fc_m_1;
          _trace_class_sc_0_ec_18_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_18_p_fc_m_1, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_18_p_fc_m_1, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_18_p_fc, "type", _trace_class_sc_0_ec_18_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_18_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_18_p_fc_m_2;
          _trace_class_sc_0_ec_18_p_fc_m_2 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_18_p_fc_m_2, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_18_p_fc_m_2, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_18_p_fc, "device", _trace_class_sc_0_ec_18_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_0_ec_18_p_fc_m_2);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_18_p_fc_m_3;
          _trace_class_sc_0_ec_18_p_fc_m_3 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_18_p_fc_m_3, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_18_p_fc_m_3, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_18_p_fc, "lookup", _trace_class_sc_0_ec_18_p_fc_m_3);
          bt_field_class_put_ref(_trace_class_sc_0_ec_18_p_fc_m_3);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_18_p_fc_m_4;
          _trace_class_sc_0_ec_18_p_fc_m_4 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_18_p_fc_m_4, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_18_p_fc_m_4, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_18_p_fc, "documentation", _trace_class_sc_0_ec_18_p_fc_m_4);
          bt_field_class_put_ref(_trace_class_sc_0_ec_18_p_fc_m_4);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_18, _trace_class_sc_0_ec_18_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_18_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_18);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_19;
      _trace_class_sc_0_ec_19 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_19, "lttng_ust_ompt:ompt_callback_device_finalize");
      {
        bt_field_class *_trace_class_sc_0_ec_19_p_fc;
        _trace_class_sc_0_ec_19_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_19_p_fc_m_0;
          _trace_class_sc_0_ec_19_p_fc_m_0 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_19_p_fc_m_0, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_19_p_fc, "device_num", _trace_class_sc_0_ec_19_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_19_p_fc_m_0);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_19, _trace_class_sc_0_ec_19_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_19_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_19);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_20;
      _trace_class_sc_0_ec_20 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_20, "lttng_ust_ompt:ompt_callback_device_load");
      {
        bt_field_class *_trace_class_sc_0_ec_20_p_fc;
        _trace_class_sc_0_ec_20_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_20_p_fc_m_0;
          _trace_class_sc_0_ec_20_p_fc_m_0 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_20_p_fc_m_0, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_20_p_fc, "device_num", _trace_class_sc_0_ec_20_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_20_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_20_p_fc_m_1;
          _trace_class_sc_0_ec_20_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_20_p_fc_m_1, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_20_p_fc_m_1, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_20_p_fc, "filename", _trace_class_sc_0_ec_20_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_20_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_20_p_fc_m_2;
          _trace_class_sc_0_ec_20_p_fc_m_2 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_20_p_fc_m_2, 64);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_20_p_fc, "offset_in_file", _trace_class_sc_0_ec_20_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_0_ec_20_p_fc_m_2);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_20_p_fc_m_3;
          _trace_class_sc_0_ec_20_p_fc_m_3 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_20_p_fc_m_3, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_20_p_fc_m_3, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_20_p_fc, "vma_in_file", _trace_class_sc_0_ec_20_p_fc_m_3);
          bt_field_class_put_ref(_trace_class_sc_0_ec_20_p_fc_m_3);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_20_p_fc_m_4;
          _trace_class_sc_0_ec_20_p_fc_m_4 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_20_p_fc_m_4, 64);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_20_p_fc, "bytes", _trace_class_sc_0_ec_20_p_fc_m_4);
          bt_field_class_put_ref(_trace_class_sc_0_ec_20_p_fc_m_4);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_20_p_fc_m_5;
          _trace_class_sc_0_ec_20_p_fc_m_5 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_20_p_fc_m_5, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_20_p_fc_m_5, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_20_p_fc, "host_addr", _trace_class_sc_0_ec_20_p_fc_m_5);
          bt_field_class_put_ref(_trace_class_sc_0_ec_20_p_fc_m_5);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_20_p_fc_m_6;
          _trace_class_sc_0_ec_20_p_fc_m_6 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_20_p_fc_m_6, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_20_p_fc_m_6, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_20_p_fc, "device_addr", _trace_class_sc_0_ec_20_p_fc_m_6);
          bt_field_class_put_ref(_trace_class_sc_0_ec_20_p_fc_m_6);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_20_p_fc_m_7;
          _trace_class_sc_0_ec_20_p_fc_m_7 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_20_p_fc_m_7, 64);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_20_p_fc, "module_id", _trace_class_sc_0_ec_20_p_fc_m_7);
          bt_field_class_put_ref(_trace_class_sc_0_ec_20_p_fc_m_7);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_20, _trace_class_sc_0_ec_20_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_20_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_20);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_21;
      _trace_class_sc_0_ec_21 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_21, "lttng_ust_ompt:ompt_callback_device_unload");
      {
        bt_field_class *_trace_class_sc_0_ec_21_p_fc;
        _trace_class_sc_0_ec_21_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_21_p_fc_m_0;
          _trace_class_sc_0_ec_21_p_fc_m_0 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_21_p_fc_m_0, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_21_p_fc, "device_num", _trace_class_sc_0_ec_21_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_21_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_21_p_fc_m_1;
          _trace_class_sc_0_ec_21_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_21_p_fc_m_1, 64);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_21_p_fc, "module_id", _trace_class_sc_0_ec_21_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_21_p_fc_m_1);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_21, _trace_class_sc_0_ec_21_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_21_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_21);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_22;
      _trace_class_sc_0_ec_22 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_22, "lttng_ust_ompt:ompt_callback_target_data_op_emi");
      {
        bt_field_class *_trace_class_sc_0_ec_22_p_fc;
        _trace_class_sc_0_ec_22_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_22_p_fc_m_0;
          _trace_class_sc_0_ec_22_p_fc_m_0 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_22_p_fc_m_0, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_22_p_fc, "endpoint", _trace_class_sc_0_ec_22_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_22_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_22_p_fc_m_1;
          _trace_class_sc_0_ec_22_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_22_p_fc_m_1, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_22_p_fc_m_1, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_22_p_fc, "target_task_data", _trace_class_sc_0_ec_22_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_22_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_22_p_fc_m_2;
          _trace_class_sc_0_ec_22_p_fc_m_2 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_22_p_fc_m_2, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_22_p_fc_m_2, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_22_p_fc, "target_data", _trace_class_sc_0_ec_22_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_0_ec_22_p_fc_m_2);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_22_p_fc_m_3;
          _trace_class_sc_0_ec_22_p_fc_m_3 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_22_p_fc_m_3, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_22_p_fc_m_3, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_22_p_fc, "host_op_id", _trace_class_sc_0_ec_22_p_fc_m_3);
          bt_field_class_put_ref(_trace_class_sc_0_ec_22_p_fc_m_3);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_22_p_fc_m_4;
          _trace_class_sc_0_ec_22_p_fc_m_4 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_22_p_fc_m_4, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_22_p_fc, "optype", _trace_class_sc_0_ec_22_p_fc_m_4);
          bt_field_class_put_ref(_trace_class_sc_0_ec_22_p_fc_m_4);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_22_p_fc_m_5;
          _trace_class_sc_0_ec_22_p_fc_m_5 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_22_p_fc_m_5, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_22_p_fc_m_5, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_22_p_fc, "src_addr", _trace_class_sc_0_ec_22_p_fc_m_5);
          bt_field_class_put_ref(_trace_class_sc_0_ec_22_p_fc_m_5);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_22_p_fc_m_6;
          _trace_class_sc_0_ec_22_p_fc_m_6 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_22_p_fc_m_6, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_22_p_fc, "src_device_num", _trace_class_sc_0_ec_22_p_fc_m_6);
          bt_field_class_put_ref(_trace_class_sc_0_ec_22_p_fc_m_6);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_22_p_fc_m_7;
          _trace_class_sc_0_ec_22_p_fc_m_7 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_22_p_fc_m_7, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_22_p_fc_m_7, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_22_p_fc, "dest_addr", _trace_class_sc_0_ec_22_p_fc_m_7);
          bt_field_class_put_ref(_trace_class_sc_0_ec_22_p_fc_m_7);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_22_p_fc_m_8;
          _trace_class_sc_0_ec_22_p_fc_m_8 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_22_p_fc_m_8, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_22_p_fc, "dest_device_num", _trace_class_sc_0_ec_22_p_fc_m_8);
          bt_field_class_put_ref(_trace_class_sc_0_ec_22_p_fc_m_8);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_22_p_fc_m_9;
          _trace_class_sc_0_ec_22_p_fc_m_9 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_22_p_fc_m_9, 64);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_22_p_fc, "bytes", _trace_class_sc_0_ec_22_p_fc_m_9);
          bt_field_class_put_ref(_trace_class_sc_0_ec_22_p_fc_m_9);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_22_p_fc_m_10;
          _trace_class_sc_0_ec_22_p_fc_m_10 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_22_p_fc_m_10, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_22_p_fc_m_10, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_22_p_fc, "codeptr_ra", _trace_class_sc_0_ec_22_p_fc_m_10);
          bt_field_class_put_ref(_trace_class_sc_0_ec_22_p_fc_m_10);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_22, _trace_class_sc_0_ec_22_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_22_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_22);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_23;
      _trace_class_sc_0_ec_23 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_23, "lttng_ust_ompt:ompt_callback_target_data_op");
      {
        bt_field_class *_trace_class_sc_0_ec_23_p_fc;
        _trace_class_sc_0_ec_23_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_23_p_fc_m_0;
          _trace_class_sc_0_ec_23_p_fc_m_0 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_23_p_fc_m_0, 64);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_23_p_fc, "target_id", _trace_class_sc_0_ec_23_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_23_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_23_p_fc_m_1;
          _trace_class_sc_0_ec_23_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_23_p_fc_m_1, 64);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_23_p_fc, "host_op_id", _trace_class_sc_0_ec_23_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_23_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_23_p_fc_m_2;
          _trace_class_sc_0_ec_23_p_fc_m_2 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_23_p_fc_m_2, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_23_p_fc, "optype", _trace_class_sc_0_ec_23_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_0_ec_23_p_fc_m_2);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_23_p_fc_m_3;
          _trace_class_sc_0_ec_23_p_fc_m_3 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_23_p_fc_m_3, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_23_p_fc_m_3, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_23_p_fc, "src_addr", _trace_class_sc_0_ec_23_p_fc_m_3);
          bt_field_class_put_ref(_trace_class_sc_0_ec_23_p_fc_m_3);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_23_p_fc_m_4;
          _trace_class_sc_0_ec_23_p_fc_m_4 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_23_p_fc_m_4, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_23_p_fc, "src_device_num", _trace_class_sc_0_ec_23_p_fc_m_4);
          bt_field_class_put_ref(_trace_class_sc_0_ec_23_p_fc_m_4);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_23_p_fc_m_5;
          _trace_class_sc_0_ec_23_p_fc_m_5 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_23_p_fc_m_5, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_23_p_fc_m_5, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_23_p_fc, "dest_addr", _trace_class_sc_0_ec_23_p_fc_m_5);
          bt_field_class_put_ref(_trace_class_sc_0_ec_23_p_fc_m_5);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_23_p_fc_m_6;
          _trace_class_sc_0_ec_23_p_fc_m_6 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_23_p_fc_m_6, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_23_p_fc, "dest_device_num", _trace_class_sc_0_ec_23_p_fc_m_6);
          bt_field_class_put_ref(_trace_class_sc_0_ec_23_p_fc_m_6);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_23_p_fc_m_7;
          _trace_class_sc_0_ec_23_p_fc_m_7 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_23_p_fc_m_7, 64);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_23_p_fc, "bytes", _trace_class_sc_0_ec_23_p_fc_m_7);
          bt_field_class_put_ref(_trace_class_sc_0_ec_23_p_fc_m_7);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_23_p_fc_m_8;
          _trace_class_sc_0_ec_23_p_fc_m_8 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_23_p_fc_m_8, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_23_p_fc_m_8, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_23_p_fc, "codeptr_ra", _trace_class_sc_0_ec_23_p_fc_m_8);
          bt_field_class_put_ref(_trace_class_sc_0_ec_23_p_fc_m_8);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_23, _trace_class_sc_0_ec_23_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_23_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_23);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_24;
      _trace_class_sc_0_ec_24 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_24, "lttng_ust_ompt:ompt_callback_target_emi");
      {
        bt_field_class *_trace_class_sc_0_ec_24_p_fc;
        _trace_class_sc_0_ec_24_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_24_p_fc_m_0;
          _trace_class_sc_0_ec_24_p_fc_m_0 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_24_p_fc_m_0, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_24_p_fc, "kind", _trace_class_sc_0_ec_24_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_24_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_24_p_fc_m_1;
          _trace_class_sc_0_ec_24_p_fc_m_1 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_24_p_fc_m_1, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_24_p_fc, "endpoint", _trace_class_sc_0_ec_24_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_24_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_24_p_fc_m_2;
          _trace_class_sc_0_ec_24_p_fc_m_2 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_24_p_fc_m_2, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_24_p_fc, "device_num", _trace_class_sc_0_ec_24_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_0_ec_24_p_fc_m_2);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_24_p_fc_m_3;
          _trace_class_sc_0_ec_24_p_fc_m_3 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_24_p_fc_m_3, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_24_p_fc_m_3, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_24_p_fc, "task_data", _trace_class_sc_0_ec_24_p_fc_m_3);
          bt_field_class_put_ref(_trace_class_sc_0_ec_24_p_fc_m_3);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_24_p_fc_m_4;
          _trace_class_sc_0_ec_24_p_fc_m_4 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_24_p_fc_m_4, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_24_p_fc_m_4, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_24_p_fc, "target_task_data", _trace_class_sc_0_ec_24_p_fc_m_4);
          bt_field_class_put_ref(_trace_class_sc_0_ec_24_p_fc_m_4);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_24_p_fc_m_5;
          _trace_class_sc_0_ec_24_p_fc_m_5 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_24_p_fc_m_5, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_24_p_fc_m_5, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_24_p_fc, "target_data", _trace_class_sc_0_ec_24_p_fc_m_5);
          bt_field_class_put_ref(_trace_class_sc_0_ec_24_p_fc_m_5);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_24_p_fc_m_6;
          _trace_class_sc_0_ec_24_p_fc_m_6 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_24_p_fc_m_6, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_24_p_fc_m_6, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_24_p_fc, "codeptr_ra", _trace_class_sc_0_ec_24_p_fc_m_6);
          bt_field_class_put_ref(_trace_class_sc_0_ec_24_p_fc_m_6);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_24, _trace_class_sc_0_ec_24_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_24_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_24);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_25;
      _trace_class_sc_0_ec_25 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_25, "lttng_ust_ompt:ompt_callback_target");
      {
        bt_field_class *_trace_class_sc_0_ec_25_p_fc;
        _trace_class_sc_0_ec_25_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_25_p_fc_m_0;
          _trace_class_sc_0_ec_25_p_fc_m_0 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_25_p_fc_m_0, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_25_p_fc, "kind", _trace_class_sc_0_ec_25_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_25_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_25_p_fc_m_1;
          _trace_class_sc_0_ec_25_p_fc_m_1 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_25_p_fc_m_1, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_25_p_fc, "endpoint", _trace_class_sc_0_ec_25_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_25_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_25_p_fc_m_2;
          _trace_class_sc_0_ec_25_p_fc_m_2 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_25_p_fc_m_2, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_25_p_fc, "device_num", _trace_class_sc_0_ec_25_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_0_ec_25_p_fc_m_2);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_25_p_fc_m_3;
          _trace_class_sc_0_ec_25_p_fc_m_3 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_25_p_fc_m_3, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_25_p_fc_m_3, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_25_p_fc, "task_data", _trace_class_sc_0_ec_25_p_fc_m_3);
          bt_field_class_put_ref(_trace_class_sc_0_ec_25_p_fc_m_3);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_25_p_fc_m_4;
          _trace_class_sc_0_ec_25_p_fc_m_4 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_25_p_fc_m_4, 64);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_25_p_fc, "target_id", _trace_class_sc_0_ec_25_p_fc_m_4);
          bt_field_class_put_ref(_trace_class_sc_0_ec_25_p_fc_m_4);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_25_p_fc_m_5;
          _trace_class_sc_0_ec_25_p_fc_m_5 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_25_p_fc_m_5, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_25_p_fc_m_5, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_25_p_fc, "codeptr_ra", _trace_class_sc_0_ec_25_p_fc_m_5);
          bt_field_class_put_ref(_trace_class_sc_0_ec_25_p_fc_m_5);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_25, _trace_class_sc_0_ec_25_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_25_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_25);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_26;
      _trace_class_sc_0_ec_26 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_26, "lttng_ust_ompt:ompt_callback_target_map_emi");
      {
        bt_field_class *_trace_class_sc_0_ec_26_p_fc;
        _trace_class_sc_0_ec_26_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_26_p_fc_m_0;
          _trace_class_sc_0_ec_26_p_fc_m_0 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_26_p_fc_m_0, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_26_p_fc_m_0, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_26_p_fc, "target_data", _trace_class_sc_0_ec_26_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_26_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_26_p_fc_m_1;
          _trace_class_sc_0_ec_26_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_26_p_fc_m_1, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_26_p_fc, "nitems", _trace_class_sc_0_ec_26_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_26_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_26_p_fc_m_2;
          _trace_class_sc_0_ec_26_p_fc_m_2 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_26_p_fc_m_2, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_26_p_fc_m_2, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_26_p_fc, "host_addr", _trace_class_sc_0_ec_26_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_0_ec_26_p_fc_m_2);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_26_p_fc_m_3;
          _trace_class_sc_0_ec_26_p_fc_m_3 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_26_p_fc_m_3, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_26_p_fc_m_3, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_26_p_fc, "device_addr", _trace_class_sc_0_ec_26_p_fc_m_3);
          bt_field_class_put_ref(_trace_class_sc_0_ec_26_p_fc_m_3);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_26_p_fc_m_4;
          _trace_class_sc_0_ec_26_p_fc_m_4 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_26_p_fc_m_4, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_26_p_fc_m_4, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_26_p_fc, "bytes", _trace_class_sc_0_ec_26_p_fc_m_4);
          bt_field_class_put_ref(_trace_class_sc_0_ec_26_p_fc_m_4);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_26_p_fc_m_5;
          _trace_class_sc_0_ec_26_p_fc_m_5 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_26_p_fc_m_5, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_26_p_fc_m_5, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_26_p_fc, "mapping_flags", _trace_class_sc_0_ec_26_p_fc_m_5);
          bt_field_class_put_ref(_trace_class_sc_0_ec_26_p_fc_m_5);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_26_p_fc_m_6;
          _trace_class_sc_0_ec_26_p_fc_m_6 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_26_p_fc_m_6, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_26_p_fc_m_6, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_26_p_fc, "codeptr_ra", _trace_class_sc_0_ec_26_p_fc_m_6);
          bt_field_class_put_ref(_trace_class_sc_0_ec_26_p_fc_m_6);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_26, _trace_class_sc_0_ec_26_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_26_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_26);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_27;
      _trace_class_sc_0_ec_27 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_27, "lttng_ust_ompt:ompt_callback_target_map");
      {
        bt_field_class *_trace_class_sc_0_ec_27_p_fc;
        _trace_class_sc_0_ec_27_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_27_p_fc_m_0;
          _trace_class_sc_0_ec_27_p_fc_m_0 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_27_p_fc_m_0, 64);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_27_p_fc, "target_id", _trace_class_sc_0_ec_27_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_27_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_27_p_fc_m_1;
          _trace_class_sc_0_ec_27_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_27_p_fc_m_1, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_27_p_fc, "nitems", _trace_class_sc_0_ec_27_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_27_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_27_p_fc_m_2;
          _trace_class_sc_0_ec_27_p_fc_m_2 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_27_p_fc_m_2, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_27_p_fc_m_2, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_27_p_fc, "host_addr", _trace_class_sc_0_ec_27_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_0_ec_27_p_fc_m_2);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_27_p_fc_m_3;
          _trace_class_sc_0_ec_27_p_fc_m_3 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_27_p_fc_m_3, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_27_p_fc_m_3, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_27_p_fc, "device_addr", _trace_class_sc_0_ec_27_p_fc_m_3);
          bt_field_class_put_ref(_trace_class_sc_0_ec_27_p_fc_m_3);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_27_p_fc_m_4;
          _trace_class_sc_0_ec_27_p_fc_m_4 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_27_p_fc_m_4, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_27_p_fc_m_4, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_27_p_fc, "bytes", _trace_class_sc_0_ec_27_p_fc_m_4);
          bt_field_class_put_ref(_trace_class_sc_0_ec_27_p_fc_m_4);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_27_p_fc_m_5;
          _trace_class_sc_0_ec_27_p_fc_m_5 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_27_p_fc_m_5, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_27_p_fc_m_5, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_27_p_fc, "mapping_flags", _trace_class_sc_0_ec_27_p_fc_m_5);
          bt_field_class_put_ref(_trace_class_sc_0_ec_27_p_fc_m_5);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_27_p_fc_m_6;
          _trace_class_sc_0_ec_27_p_fc_m_6 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_27_p_fc_m_6, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_27_p_fc_m_6, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_27_p_fc, "codeptr_ra", _trace_class_sc_0_ec_27_p_fc_m_6);
          bt_field_class_put_ref(_trace_class_sc_0_ec_27_p_fc_m_6);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_27_p_fc_m_7;
          _trace_class_sc_0_ec_27_p_fc_m_7 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_27_p_fc_m_7, 64);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_27_p_fc, "_host_addr_vals_length", _trace_class_sc_0_ec_27_p_fc_m_7);
          bt_field_class_put_ref(_trace_class_sc_0_ec_27_p_fc_m_7);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_27_p_fc_m_8;
          {
            bt_field_class *_trace_class_sc_0_ec_27_p_fc_m_8_field_class;
            _trace_class_sc_0_ec_27_p_fc_m_8_field_class = bt_field_class_integer_unsigned_create(_trace_class);
            bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_27_p_fc_m_8_field_class, 64);
            bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_27_p_fc_m_8_field_class, 16);
            bt_field_class *_trace_class_sc_0_ec_27_p_fc_m_8_field_class_length;
            {
              bt_field_class_structure_member *_trace_class_sc_0_ec_27_p_fc_m_8_field_class_length_sm;
              _trace_class_sc_0_ec_27_p_fc_m_8_field_class_length_sm = bt_field_class_structure_borrow_member_by_name(_trace_class_sc_0_ec_27_p_fc, "_host_addr_vals_length");
              _trace_class_sc_0_ec_27_p_fc_m_8_field_class_length = bt_field_class_structure_member_borrow_field_class(_trace_class_sc_0_ec_27_p_fc_m_8_field_class_length_sm);
            }
            _trace_class_sc_0_ec_27_p_fc_m_8 = bt_field_class_array_dynamic_create(_trace_class, _trace_class_sc_0_ec_27_p_fc_m_8_field_class, _trace_class_sc_0_ec_27_p_fc_m_8_field_class_length);
            bt_field_class_put_ref(_trace_class_sc_0_ec_27_p_fc_m_8_field_class);
          }
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_27_p_fc, "host_addr_vals", _trace_class_sc_0_ec_27_p_fc_m_8);
          bt_field_class_put_ref(_trace_class_sc_0_ec_27_p_fc_m_8);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_27_p_fc_m_9;
          _trace_class_sc_0_ec_27_p_fc_m_9 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_27_p_fc_m_9, 64);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_27_p_fc, "_device_addr_vals_length", _trace_class_sc_0_ec_27_p_fc_m_9);
          bt_field_class_put_ref(_trace_class_sc_0_ec_27_p_fc_m_9);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_27_p_fc_m_10;
          {
            bt_field_class *_trace_class_sc_0_ec_27_p_fc_m_10_field_class;
            _trace_class_sc_0_ec_27_p_fc_m_10_field_class = bt_field_class_integer_unsigned_create(_trace_class);
            bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_27_p_fc_m_10_field_class, 64);
            bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_27_p_fc_m_10_field_class, 16);
            bt_field_class *_trace_class_sc_0_ec_27_p_fc_m_10_field_class_length;
            {
              bt_field_class_structure_member *_trace_class_sc_0_ec_27_p_fc_m_10_field_class_length_sm;
              _trace_class_sc_0_ec_27_p_fc_m_10_field_class_length_sm = bt_field_class_structure_borrow_member_by_name(_trace_class_sc_0_ec_27_p_fc, "_device_addr_vals_length");
              _trace_class_sc_0_ec_27_p_fc_m_10_field_class_length = bt_field_class_structure_member_borrow_field_class(_trace_class_sc_0_ec_27_p_fc_m_10_field_class_length_sm);
            }
            _trace_class_sc_0_ec_27_p_fc_m_10 = bt_field_class_array_dynamic_create(_trace_class, _trace_class_sc_0_ec_27_p_fc_m_10_field_class, _trace_class_sc_0_ec_27_p_fc_m_10_field_class_length);
            bt_field_class_put_ref(_trace_class_sc_0_ec_27_p_fc_m_10_field_class);
          }
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_27_p_fc, "device_addr_vals", _trace_class_sc_0_ec_27_p_fc_m_10);
          bt_field_class_put_ref(_trace_class_sc_0_ec_27_p_fc_m_10);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_27_p_fc_m_11;
          _trace_class_sc_0_ec_27_p_fc_m_11 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_27_p_fc_m_11, 64);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_27_p_fc, "_bytes_vals_length", _trace_class_sc_0_ec_27_p_fc_m_11);
          bt_field_class_put_ref(_trace_class_sc_0_ec_27_p_fc_m_11);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_27_p_fc_m_12;
          {
            bt_field_class *_trace_class_sc_0_ec_27_p_fc_m_12_field_class;
            _trace_class_sc_0_ec_27_p_fc_m_12_field_class = bt_field_class_integer_unsigned_create(_trace_class);
            bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_27_p_fc_m_12_field_class, 64);
            bt_field_class *_trace_class_sc_0_ec_27_p_fc_m_12_field_class_length;
            {
              bt_field_class_structure_member *_trace_class_sc_0_ec_27_p_fc_m_12_field_class_length_sm;
              _trace_class_sc_0_ec_27_p_fc_m_12_field_class_length_sm = bt_field_class_structure_borrow_member_by_name(_trace_class_sc_0_ec_27_p_fc, "_bytes_vals_length");
              _trace_class_sc_0_ec_27_p_fc_m_12_field_class_length = bt_field_class_structure_member_borrow_field_class(_trace_class_sc_0_ec_27_p_fc_m_12_field_class_length_sm);
            }
            _trace_class_sc_0_ec_27_p_fc_m_12 = bt_field_class_array_dynamic_create(_trace_class, _trace_class_sc_0_ec_27_p_fc_m_12_field_class, _trace_class_sc_0_ec_27_p_fc_m_12_field_class_length);
            bt_field_class_put_ref(_trace_class_sc_0_ec_27_p_fc_m_12_field_class);
          }
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_27_p_fc, "bytes_vals", _trace_class_sc_0_ec_27_p_fc_m_12);
          bt_field_class_put_ref(_trace_class_sc_0_ec_27_p_fc_m_12);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_27_p_fc_m_13;
          _trace_class_sc_0_ec_27_p_fc_m_13 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_27_p_fc_m_13, 64);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_27_p_fc, "_mapping_flags_vals_length", _trace_class_sc_0_ec_27_p_fc_m_13);
          bt_field_class_put_ref(_trace_class_sc_0_ec_27_p_fc_m_13);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_27_p_fc_m_14;
          {
            bt_field_class *_trace_class_sc_0_ec_27_p_fc_m_14_field_class;
            _trace_class_sc_0_ec_27_p_fc_m_14_field_class = bt_field_class_integer_unsigned_create(_trace_class);
            bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_27_p_fc_m_14_field_class, 32);
            bt_field_class *_trace_class_sc_0_ec_27_p_fc_m_14_field_class_length;
            {
              bt_field_class_structure_member *_trace_class_sc_0_ec_27_p_fc_m_14_field_class_length_sm;
              _trace_class_sc_0_ec_27_p_fc_m_14_field_class_length_sm = bt_field_class_structure_borrow_member_by_name(_trace_class_sc_0_ec_27_p_fc, "_mapping_flags_vals_length");
              _trace_class_sc_0_ec_27_p_fc_m_14_field_class_length = bt_field_class_structure_member_borrow_field_class(_trace_class_sc_0_ec_27_p_fc_m_14_field_class_length_sm);
            }
            _trace_class_sc_0_ec_27_p_fc_m_14 = bt_field_class_array_dynamic_create(_trace_class, _trace_class_sc_0_ec_27_p_fc_m_14_field_class, _trace_class_sc_0_ec_27_p_fc_m_14_field_class_length);
            bt_field_class_put_ref(_trace_class_sc_0_ec_27_p_fc_m_14_field_class);
          }
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_27_p_fc, "mapping_flags_vals", _trace_class_sc_0_ec_27_p_fc_m_14);
          bt_field_class_put_ref(_trace_class_sc_0_ec_27_p_fc_m_14);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_27, _trace_class_sc_0_ec_27_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_27_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_27);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_28;
      _trace_class_sc_0_ec_28 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_28, "lttng_ust_ompt:ompt_callback_target_submit");
      {
        bt_field_class *_trace_class_sc_0_ec_28_p_fc;
        _trace_class_sc_0_ec_28_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_28_p_fc_m_0;
          _trace_class_sc_0_ec_28_p_fc_m_0 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_28_p_fc_m_0, 64);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_28_p_fc, "target_id", _trace_class_sc_0_ec_28_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_28_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_28_p_fc_m_1;
          _trace_class_sc_0_ec_28_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_28_p_fc_m_1, 64);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_28_p_fc, "host_op_id", _trace_class_sc_0_ec_28_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_28_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_28_p_fc_m_2;
          _trace_class_sc_0_ec_28_p_fc_m_2 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_28_p_fc_m_2, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_28_p_fc, "requested_num_teams", _trace_class_sc_0_ec_28_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_0_ec_28_p_fc_m_2);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_28, _trace_class_sc_0_ec_28_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_28_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_28);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_29;
      _trace_class_sc_0_ec_29 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_29, "lttng_ust_ompt:ompt_callback_target_submit_emi");
      {
        bt_field_class *_trace_class_sc_0_ec_29_p_fc;
        _trace_class_sc_0_ec_29_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_29_p_fc_m_0;
          _trace_class_sc_0_ec_29_p_fc_m_0 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_29_p_fc_m_0, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_29_p_fc, "endpoint", _trace_class_sc_0_ec_29_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_29_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_29_p_fc_m_1;
          _trace_class_sc_0_ec_29_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_29_p_fc_m_1, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_29_p_fc_m_1, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_29_p_fc, "target_data", _trace_class_sc_0_ec_29_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_29_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_29_p_fc_m_2;
          _trace_class_sc_0_ec_29_p_fc_m_2 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_29_p_fc_m_2, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_29_p_fc_m_2, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_29_p_fc, "host_op_id", _trace_class_sc_0_ec_29_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_0_ec_29_p_fc_m_2);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_29_p_fc_m_3;
          _trace_class_sc_0_ec_29_p_fc_m_3 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_29_p_fc_m_3, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_29_p_fc, "requested_num_teams", _trace_class_sc_0_ec_29_p_fc_m_3);
          bt_field_class_put_ref(_trace_class_sc_0_ec_29_p_fc_m_3);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_29, _trace_class_sc_0_ec_29_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_29_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_29);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_30;
      _trace_class_sc_0_ec_30 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_30, "lttng_ust_ompt:ompt_callback_control_tool");
      {
        bt_field_class *_trace_class_sc_0_ec_30_p_fc;
        _trace_class_sc_0_ec_30_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_30_p_fc_m_0;
          _trace_class_sc_0_ec_30_p_fc_m_0 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_30_p_fc_m_0, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_30_p_fc, "ompResult", _trace_class_sc_0_ec_30_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_30_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_30_p_fc_m_1;
          _trace_class_sc_0_ec_30_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_30_p_fc_m_1, 64);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_30_p_fc, "command", _trace_class_sc_0_ec_30_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_30_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_30_p_fc_m_2;
          _trace_class_sc_0_ec_30_p_fc_m_2 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_30_p_fc_m_2, 64);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_30_p_fc, "modifier", _trace_class_sc_0_ec_30_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_0_ec_30_p_fc_m_2);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_30_p_fc_m_3;
          _trace_class_sc_0_ec_30_p_fc_m_3 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_30_p_fc_m_3, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_30_p_fc_m_3, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_30_p_fc, "arg", _trace_class_sc_0_ec_30_p_fc_m_3);
          bt_field_class_put_ref(_trace_class_sc_0_ec_30_p_fc_m_3);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_30_p_fc_m_4;
          _trace_class_sc_0_ec_30_p_fc_m_4 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_30_p_fc_m_4, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_30_p_fc_m_4, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_30_p_fc, "codeptr_ra", _trace_class_sc_0_ec_30_p_fc_m_4);
          bt_field_class_put_ref(_trace_class_sc_0_ec_30_p_fc_m_4);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_30, _trace_class_sc_0_ec_30_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_30_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_30);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_31;
      _trace_class_sc_0_ec_31 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_31, "lttng_ust_ompt:ompt_callback_error");
      {
        bt_field_class *_trace_class_sc_0_ec_31_p_fc;
        _trace_class_sc_0_ec_31_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_31_p_fc_m_0;
          _trace_class_sc_0_ec_31_p_fc_m_0 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_31_p_fc_m_0, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_31_p_fc, "severity", _trace_class_sc_0_ec_31_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_31_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_31_p_fc_m_1;
          _trace_class_sc_0_ec_31_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_31_p_fc_m_1, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_31_p_fc_m_1, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_31_p_fc, "message", _trace_class_sc_0_ec_31_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_31_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_31_p_fc_m_2;
          _trace_class_sc_0_ec_31_p_fc_m_2 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_31_p_fc_m_2, 64);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_31_p_fc, "length", _trace_class_sc_0_ec_31_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_0_ec_31_p_fc_m_2);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_31_p_fc_m_3;
          _trace_class_sc_0_ec_31_p_fc_m_3 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_31_p_fc_m_3, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_31_p_fc_m_3, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_31_p_fc, "codeptr_ra", _trace_class_sc_0_ec_31_p_fc_m_3);
          bt_field_class_put_ref(_trace_class_sc_0_ec_31_p_fc_m_3);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_31, _trace_class_sc_0_ec_31_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_31_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_31);
    }
    bt_stream_class_put_ref(_trace_class_sc_0);
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
  return trace;
}

// Workaround of a bug where gepping trace alive (and not the stream) provoke
// some segfault
void btx_streams_get_ref(bt_trace *trace) {
  {
    bt_stream *stream = bt_trace_borrow_stream_by_index(trace, 0);
    bt_stream_get_ref(stream);
  }
}

void btx_streams_put_ref(bt_trace *trace) {
  {
    bt_stream *stream = bt_trace_borrow_stream_by_index(trace, 0);
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
  (void)trace;
}

static void btx_set_message_lttng_ust_ompt_ompt_callback_thread_begin(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_thread_t thread_type, ompt_data_t * thread_data) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_integer_signed_set_value(_event_cc_f_m_0, (int64_t)vpid);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_1, (uint64_t)vtid);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_signed_set_value(_event_p_f_m_0, (int64_t)thread_type);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)thread_data);
    }
  }

}

void btx_push_message_lttng_ust_ompt_ompt_callback_thread_begin(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_thread_t thread_type, ompt_data_t * thread_data) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 0);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_ompt_ompt_callback_thread_begin(
      _downstream_event, _timestamp, vpid, vtid, thread_type, thread_data);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_ompt_ompt_callback_thread_end(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_data_t * thread_data) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_integer_signed_set_value(_event_cc_f_m_0, (int64_t)vpid);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_1, (uint64_t)vtid);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_unsigned_set_value(_event_p_f_m_0, (uint64_t)thread_data);
    }
  }

}

void btx_push_message_lttng_ust_ompt_ompt_callback_thread_end(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_data_t * thread_data) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 1);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_ompt_ompt_callback_thread_end(
      _downstream_event, _timestamp, vpid, vtid, thread_data);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_ompt_ompt_callback_parallel_begin(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_data_t * encountering_task_data, ompt_frame_t * encountering_task_frame, ompt_data_t * parallel_data, unsigned int requested_parallelism, ompt_parallel_flags_t flags, void * codeptr_ra) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_integer_signed_set_value(_event_cc_f_m_0, (int64_t)vpid);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_1, (uint64_t)vtid);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_unsigned_set_value(_event_p_f_m_0, (uint64_t)encountering_task_data);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)encountering_task_frame);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_unsigned_set_value(_event_p_f_m_2, (uint64_t)parallel_data);
    }
    {
      bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 3);
      bt_field_integer_unsigned_set_value(_event_p_f_m_3, (uint64_t)requested_parallelism);
    }
    {
      bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 4);
      bt_field_integer_signed_set_value(_event_p_f_m_4, (int64_t)flags);
    }
    {
      bt_field *_event_p_f_m_5 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 5);
      bt_field_integer_unsigned_set_value(_event_p_f_m_5, (uint64_t)codeptr_ra);
    }
  }

}

void btx_push_message_lttng_ust_ompt_ompt_callback_parallel_begin(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_data_t * encountering_task_data, ompt_frame_t * encountering_task_frame, ompt_data_t * parallel_data, unsigned int requested_parallelism, ompt_parallel_flags_t flags, void * codeptr_ra) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 2);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_ompt_ompt_callback_parallel_begin(
      _downstream_event, _timestamp, vpid, vtid, encountering_task_data, encountering_task_frame, parallel_data, requested_parallelism, flags, codeptr_ra);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_ompt_ompt_callback_parallel_end(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_data_t * parallel_data, ompt_data_t * encountering_task_data, ompt_parallel_flags_t flags, void * codeptr_ra) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_integer_signed_set_value(_event_cc_f_m_0, (int64_t)vpid);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_1, (uint64_t)vtid);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_unsigned_set_value(_event_p_f_m_0, (uint64_t)parallel_data);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)encountering_task_data);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_signed_set_value(_event_p_f_m_2, (int64_t)flags);
    }
    {
      bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 3);
      bt_field_integer_unsigned_set_value(_event_p_f_m_3, (uint64_t)codeptr_ra);
    }
  }

}

void btx_push_message_lttng_ust_ompt_ompt_callback_parallel_end(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_data_t * parallel_data, ompt_data_t * encountering_task_data, ompt_parallel_flags_t flags, void * codeptr_ra) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 3);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_ompt_ompt_callback_parallel_end(
      _downstream_event, _timestamp, vpid, vtid, parallel_data, encountering_task_data, flags, codeptr_ra);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_ompt_ompt_callback_work(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_work_t work_type, ompt_scope_endpoint_t endpoint, ompt_data_t * parallel_data, ompt_data_t * task_data, uint64_t count, void * codeptr_ra) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_integer_signed_set_value(_event_cc_f_m_0, (int64_t)vpid);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_1, (uint64_t)vtid);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_signed_set_value(_event_p_f_m_0, (int64_t)work_type);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_signed_set_value(_event_p_f_m_1, (int64_t)endpoint);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_unsigned_set_value(_event_p_f_m_2, (uint64_t)parallel_data);
    }
    {
      bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 3);
      bt_field_integer_unsigned_set_value(_event_p_f_m_3, (uint64_t)task_data);
    }
    {
      bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 4);
      bt_field_integer_unsigned_set_value(_event_p_f_m_4, (uint64_t)count);
    }
    {
      bt_field *_event_p_f_m_5 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 5);
      bt_field_integer_unsigned_set_value(_event_p_f_m_5, (uint64_t)codeptr_ra);
    }
  }

}

void btx_push_message_lttng_ust_ompt_ompt_callback_work(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_work_t work_type, ompt_scope_endpoint_t endpoint, ompt_data_t * parallel_data, ompt_data_t * task_data, uint64_t count, void * codeptr_ra) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 4);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_ompt_ompt_callback_work(
      _downstream_event, _timestamp, vpid, vtid, work_type, endpoint, parallel_data, task_data, count, codeptr_ra);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_ompt_ompt_callback_dispatch(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_data_t * parallel_data, ompt_data_t * task_data, ompt_dispatch_t kind, ompt_data_t instance) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_integer_signed_set_value(_event_cc_f_m_0, (int64_t)vpid);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_1, (uint64_t)vtid);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_unsigned_set_value(_event_p_f_m_0, (uint64_t)parallel_data);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)task_data);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_signed_set_value(_event_p_f_m_2, (int64_t)kind);
    }
    {
      bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 3);
      // Dump data to a temporal string.
      char *_event_p_f_m_3_temp = (char *)malloc(sizeof(instance));
      assert(_event_p_f_m_3_temp != NULL && "Out of memory");
      memcpy(_event_p_f_m_3_temp, &instance, sizeof(instance));
      // Set string field with dumped data.
      bt_field_string_clear(_event_p_f_m_3);
      bt_field_string_append_status _event_p_f_m_3_status = bt_field_string_append_with_length(_event_p_f_m_3, _event_p_f_m_3_temp, sizeof(instance));
      assert(_event_p_f_m_3_status == BT_FIELD_STRING_APPEND_STATUS_OK && "Out of memory");
      free(_event_p_f_m_3_temp);
    }
  }

}

void btx_push_message_lttng_ust_ompt_ompt_callback_dispatch(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_data_t * parallel_data, ompt_data_t * task_data, ompt_dispatch_t kind, ompt_data_t instance) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 5);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_ompt_ompt_callback_dispatch(
      _downstream_event, _timestamp, vpid, vtid, parallel_data, task_data, kind, instance);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_ompt_ompt_callback_task_create(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_data_t * encountering_task_data, ompt_frame_t * encountering_task_frame, ompt_data_t * new_task_data, ompt_task_flags_t flags, int has_dependences, void * codeptr_ra) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_integer_signed_set_value(_event_cc_f_m_0, (int64_t)vpid);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_1, (uint64_t)vtid);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_unsigned_set_value(_event_p_f_m_0, (uint64_t)encountering_task_data);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)encountering_task_frame);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_unsigned_set_value(_event_p_f_m_2, (uint64_t)new_task_data);
    }
    {
      bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 3);
      bt_field_integer_signed_set_value(_event_p_f_m_3, (int64_t)flags);
    }
    {
      bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 4);
      bt_field_integer_signed_set_value(_event_p_f_m_4, (int64_t)has_dependences);
    }
    {
      bt_field *_event_p_f_m_5 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 5);
      bt_field_integer_unsigned_set_value(_event_p_f_m_5, (uint64_t)codeptr_ra);
    }
  }

}

void btx_push_message_lttng_ust_ompt_ompt_callback_task_create(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_data_t * encountering_task_data, ompt_frame_t * encountering_task_frame, ompt_data_t * new_task_data, ompt_task_flags_t flags, int has_dependences, void * codeptr_ra) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 6);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_ompt_ompt_callback_task_create(
      _downstream_event, _timestamp, vpid, vtid, encountering_task_data, encountering_task_frame, new_task_data, flags, has_dependences, codeptr_ra);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_ompt_ompt_callback_dependences(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_data_t * task_data, ompt_dependence_t * deps, int ndeps) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_integer_signed_set_value(_event_cc_f_m_0, (int64_t)vpid);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_1, (uint64_t)vtid);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_unsigned_set_value(_event_p_f_m_0, (uint64_t)task_data);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)deps);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_signed_set_value(_event_p_f_m_2, (int64_t)ndeps);
    }
  }

}

void btx_push_message_lttng_ust_ompt_ompt_callback_dependences(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_data_t * task_data, ompt_dependence_t * deps, int ndeps) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 7);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_ompt_ompt_callback_dependences(
      _downstream_event, _timestamp, vpid, vtid, task_data, deps, ndeps);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_ompt_ompt_callback_task_dependence(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_data_t * src_task_data, ompt_data_t * sink_task_data) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_integer_signed_set_value(_event_cc_f_m_0, (int64_t)vpid);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_1, (uint64_t)vtid);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_unsigned_set_value(_event_p_f_m_0, (uint64_t)src_task_data);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)sink_task_data);
    }
  }

}

void btx_push_message_lttng_ust_ompt_ompt_callback_task_dependence(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_data_t * src_task_data, ompt_data_t * sink_task_data) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 8);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_ompt_ompt_callback_task_dependence(
      _downstream_event, _timestamp, vpid, vtid, src_task_data, sink_task_data);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_ompt_ompt_callback_task_schedule(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_data_t * prior_task_data, ompt_task_status_t prior_task_status, ompt_data_t * next_task_data) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_integer_signed_set_value(_event_cc_f_m_0, (int64_t)vpid);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_1, (uint64_t)vtid);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_unsigned_set_value(_event_p_f_m_0, (uint64_t)prior_task_data);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_signed_set_value(_event_p_f_m_1, (int64_t)prior_task_status);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_unsigned_set_value(_event_p_f_m_2, (uint64_t)next_task_data);
    }
  }

}

void btx_push_message_lttng_ust_ompt_ompt_callback_task_schedule(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_data_t * prior_task_data, ompt_task_status_t prior_task_status, ompt_data_t * next_task_data) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 9);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_ompt_ompt_callback_task_schedule(
      _downstream_event, _timestamp, vpid, vtid, prior_task_data, prior_task_status, next_task_data);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_ompt_ompt_callback_implicit_task(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_scope_endpoint_t endpoint, ompt_data_t * parallel_data, ompt_data_t * task_data, unsigned int actual_parallelism, unsigned int index, ompt_task_flags_t flags) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_integer_signed_set_value(_event_cc_f_m_0, (int64_t)vpid);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_1, (uint64_t)vtid);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_signed_set_value(_event_p_f_m_0, (int64_t)endpoint);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)parallel_data);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_unsigned_set_value(_event_p_f_m_2, (uint64_t)task_data);
    }
    {
      bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 3);
      bt_field_integer_unsigned_set_value(_event_p_f_m_3, (uint64_t)actual_parallelism);
    }
    {
      bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 4);
      bt_field_integer_unsigned_set_value(_event_p_f_m_4, (uint64_t)index);
    }
    {
      bt_field *_event_p_f_m_5 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 5);
      bt_field_integer_signed_set_value(_event_p_f_m_5, (int64_t)flags);
    }
  }

}

void btx_push_message_lttng_ust_ompt_ompt_callback_implicit_task(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_scope_endpoint_t endpoint, ompt_data_t * parallel_data, ompt_data_t * task_data, unsigned int actual_parallelism, unsigned int index, ompt_task_flags_t flags) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 10);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_ompt_ompt_callback_implicit_task(
      _downstream_event, _timestamp, vpid, vtid, endpoint, parallel_data, task_data, actual_parallelism, index, flags);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_ompt_ompt_callback_masked(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_scope_endpoint_t endpoint, ompt_data_t * parallel_data, ompt_data_t * task_data, void * codeptr_ra) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_integer_signed_set_value(_event_cc_f_m_0, (int64_t)vpid);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_1, (uint64_t)vtid);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_signed_set_value(_event_p_f_m_0, (int64_t)endpoint);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)parallel_data);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_unsigned_set_value(_event_p_f_m_2, (uint64_t)task_data);
    }
    {
      bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 3);
      bt_field_integer_unsigned_set_value(_event_p_f_m_3, (uint64_t)codeptr_ra);
    }
  }

}

void btx_push_message_lttng_ust_ompt_ompt_callback_masked(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_scope_endpoint_t endpoint, ompt_data_t * parallel_data, ompt_data_t * task_data, void * codeptr_ra) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 11);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_ompt_ompt_callback_masked(
      _downstream_event, _timestamp, vpid, vtid, endpoint, parallel_data, task_data, codeptr_ra);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_ompt_ompt_callback_sync_region(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_sync_region_t kind, ompt_scope_endpoint_t endpoint, ompt_data_t * parallel_data, ompt_data_t * task_data, void * codeptr_ra) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_integer_signed_set_value(_event_cc_f_m_0, (int64_t)vpid);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_1, (uint64_t)vtid);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_signed_set_value(_event_p_f_m_0, (int64_t)kind);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_signed_set_value(_event_p_f_m_1, (int64_t)endpoint);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_unsigned_set_value(_event_p_f_m_2, (uint64_t)parallel_data);
    }
    {
      bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 3);
      bt_field_integer_unsigned_set_value(_event_p_f_m_3, (uint64_t)task_data);
    }
    {
      bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 4);
      bt_field_integer_unsigned_set_value(_event_p_f_m_4, (uint64_t)codeptr_ra);
    }
  }

}

void btx_push_message_lttng_ust_ompt_ompt_callback_sync_region(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_sync_region_t kind, ompt_scope_endpoint_t endpoint, ompt_data_t * parallel_data, ompt_data_t * task_data, void * codeptr_ra) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 12);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_ompt_ompt_callback_sync_region(
      _downstream_event, _timestamp, vpid, vtid, kind, endpoint, parallel_data, task_data, codeptr_ra);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_ompt_ompt_callback_mutex_acquire(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_mutex_t kind, unsigned int hint, unsigned int impl, ompt_wait_id_t wait_id, void * codeptr_ra) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_integer_signed_set_value(_event_cc_f_m_0, (int64_t)vpid);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_1, (uint64_t)vtid);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_signed_set_value(_event_p_f_m_0, (int64_t)kind);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)hint);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_unsigned_set_value(_event_p_f_m_2, (uint64_t)impl);
    }
    {
      bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 3);
      bt_field_integer_unsigned_set_value(_event_p_f_m_3, (uint64_t)wait_id);
    }
    {
      bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 4);
      bt_field_integer_unsigned_set_value(_event_p_f_m_4, (uint64_t)codeptr_ra);
    }
  }

}

void btx_push_message_lttng_ust_ompt_ompt_callback_mutex_acquire(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_mutex_t kind, unsigned int hint, unsigned int impl, ompt_wait_id_t wait_id, void * codeptr_ra) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 13);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_ompt_ompt_callback_mutex_acquire(
      _downstream_event, _timestamp, vpid, vtid, kind, hint, impl, wait_id, codeptr_ra);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_ompt_ompt_callback_mutex(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_mutex_t kind, ompt_wait_id_t wait_id, void * codeptr_ra) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_integer_signed_set_value(_event_cc_f_m_0, (int64_t)vpid);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_1, (uint64_t)vtid);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_signed_set_value(_event_p_f_m_0, (int64_t)kind);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)wait_id);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_unsigned_set_value(_event_p_f_m_2, (uint64_t)codeptr_ra);
    }
  }

}

void btx_push_message_lttng_ust_ompt_ompt_callback_mutex(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_mutex_t kind, ompt_wait_id_t wait_id, void * codeptr_ra) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 14);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_ompt_ompt_callback_mutex(
      _downstream_event, _timestamp, vpid, vtid, kind, wait_id, codeptr_ra);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_ompt_ompt_callback_nest_lock(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_scope_endpoint_t endpoint, ompt_wait_id_t wait_id, void * codeptr_ra) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_integer_signed_set_value(_event_cc_f_m_0, (int64_t)vpid);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_1, (uint64_t)vtid);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_signed_set_value(_event_p_f_m_0, (int64_t)endpoint);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)wait_id);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_unsigned_set_value(_event_p_f_m_2, (uint64_t)codeptr_ra);
    }
  }

}

void btx_push_message_lttng_ust_ompt_ompt_callback_nest_lock(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_scope_endpoint_t endpoint, ompt_wait_id_t wait_id, void * codeptr_ra) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 15);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_ompt_ompt_callback_nest_lock(
      _downstream_event, _timestamp, vpid, vtid, endpoint, wait_id, codeptr_ra);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_ompt_ompt_callback_flush(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_data_t * thread_data, void * codeptr_ra) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_integer_signed_set_value(_event_cc_f_m_0, (int64_t)vpid);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_1, (uint64_t)vtid);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_unsigned_set_value(_event_p_f_m_0, (uint64_t)thread_data);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)codeptr_ra);
    }
  }

}

void btx_push_message_lttng_ust_ompt_ompt_callback_flush(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_data_t * thread_data, void * codeptr_ra) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 16);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_ompt_ompt_callback_flush(
      _downstream_event, _timestamp, vpid, vtid, thread_data, codeptr_ra);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_ompt_ompt_callback_cancel(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_data_t * task_data, ompt_cancel_flags_t flags, void * codeptr_ra) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_integer_signed_set_value(_event_cc_f_m_0, (int64_t)vpid);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_1, (uint64_t)vtid);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_unsigned_set_value(_event_p_f_m_0, (uint64_t)task_data);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_signed_set_value(_event_p_f_m_1, (int64_t)flags);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_unsigned_set_value(_event_p_f_m_2, (uint64_t)codeptr_ra);
    }
  }

}

void btx_push_message_lttng_ust_ompt_ompt_callback_cancel(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_data_t * task_data, ompt_cancel_flags_t flags, void * codeptr_ra) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 17);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_ompt_ompt_callback_cancel(
      _downstream_event, _timestamp, vpid, vtid, task_data, flags, codeptr_ra);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_ompt_ompt_callback_device_initialize(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, int device_num, char * type, ompt_device_t * device, ompt_function_lookup_t lookup, char * documentation) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_integer_signed_set_value(_event_cc_f_m_0, (int64_t)vpid);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_1, (uint64_t)vtid);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_signed_set_value(_event_p_f_m_0, (int64_t)device_num);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)type);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_unsigned_set_value(_event_p_f_m_2, (uint64_t)device);
    }
    {
      bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 3);
      bt_field_integer_unsigned_set_value(_event_p_f_m_3, (uint64_t)lookup);
    }
    {
      bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 4);
      bt_field_integer_unsigned_set_value(_event_p_f_m_4, (uint64_t)documentation);
    }
  }

}

void btx_push_message_lttng_ust_ompt_ompt_callback_device_initialize(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int device_num, char * type, ompt_device_t * device, ompt_function_lookup_t lookup, char * documentation) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 18);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_ompt_ompt_callback_device_initialize(
      _downstream_event, _timestamp, vpid, vtid, device_num, type, device, lookup, documentation);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_ompt_ompt_callback_device_finalize(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, int device_num) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_integer_signed_set_value(_event_cc_f_m_0, (int64_t)vpid);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_1, (uint64_t)vtid);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_signed_set_value(_event_p_f_m_0, (int64_t)device_num);
    }
  }

}

void btx_push_message_lttng_ust_ompt_ompt_callback_device_finalize(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int device_num) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 19);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_ompt_ompt_callback_device_finalize(
      _downstream_event, _timestamp, vpid, vtid, device_num);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_ompt_ompt_callback_device_load(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, int device_num, char * filename, int64_t offset_in_file, void * vma_in_file, size_t bytes, void * host_addr, void * device_addr, uint64_t module_id) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_integer_signed_set_value(_event_cc_f_m_0, (int64_t)vpid);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_1, (uint64_t)vtid);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_signed_set_value(_event_p_f_m_0, (int64_t)device_num);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)filename);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_signed_set_value(_event_p_f_m_2, (int64_t)offset_in_file);
    }
    {
      bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 3);
      bt_field_integer_unsigned_set_value(_event_p_f_m_3, (uint64_t)vma_in_file);
    }
    {
      bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 4);
      bt_field_integer_unsigned_set_value(_event_p_f_m_4, (uint64_t)bytes);
    }
    {
      bt_field *_event_p_f_m_5 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 5);
      bt_field_integer_unsigned_set_value(_event_p_f_m_5, (uint64_t)host_addr);
    }
    {
      bt_field *_event_p_f_m_6 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 6);
      bt_field_integer_unsigned_set_value(_event_p_f_m_6, (uint64_t)device_addr);
    }
    {
      bt_field *_event_p_f_m_7 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 7);
      bt_field_integer_unsigned_set_value(_event_p_f_m_7, (uint64_t)module_id);
    }
  }

}

void btx_push_message_lttng_ust_ompt_ompt_callback_device_load(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int device_num, char * filename, int64_t offset_in_file, void * vma_in_file, size_t bytes, void * host_addr, void * device_addr, uint64_t module_id) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 20);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_ompt_ompt_callback_device_load(
      _downstream_event, _timestamp, vpid, vtid, device_num, filename, offset_in_file, vma_in_file, bytes, host_addr, device_addr, module_id);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_ompt_ompt_callback_device_unload(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, int device_num, uint64_t module_id) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_integer_signed_set_value(_event_cc_f_m_0, (int64_t)vpid);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_1, (uint64_t)vtid);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_signed_set_value(_event_p_f_m_0, (int64_t)device_num);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)module_id);
    }
  }

}

void btx_push_message_lttng_ust_ompt_ompt_callback_device_unload(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int device_num, uint64_t module_id) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 21);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_ompt_ompt_callback_device_unload(
      _downstream_event, _timestamp, vpid, vtid, device_num, module_id);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_ompt_ompt_callback_target_data_op_emi(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_scope_endpoint_t endpoint, ompt_data_t * target_task_data, ompt_data_t * target_data, ompt_id_t * host_op_id, ompt_target_data_op_t optype, void * src_addr, int src_device_num, void * dest_addr, int dest_device_num, size_t bytes, void * codeptr_ra) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_integer_signed_set_value(_event_cc_f_m_0, (int64_t)vpid);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_1, (uint64_t)vtid);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_signed_set_value(_event_p_f_m_0, (int64_t)endpoint);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)target_task_data);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_unsigned_set_value(_event_p_f_m_2, (uint64_t)target_data);
    }
    {
      bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 3);
      bt_field_integer_unsigned_set_value(_event_p_f_m_3, (uint64_t)host_op_id);
    }
    {
      bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 4);
      bt_field_integer_signed_set_value(_event_p_f_m_4, (int64_t)optype);
    }
    {
      bt_field *_event_p_f_m_5 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 5);
      bt_field_integer_unsigned_set_value(_event_p_f_m_5, (uint64_t)src_addr);
    }
    {
      bt_field *_event_p_f_m_6 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 6);
      bt_field_integer_signed_set_value(_event_p_f_m_6, (int64_t)src_device_num);
    }
    {
      bt_field *_event_p_f_m_7 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 7);
      bt_field_integer_unsigned_set_value(_event_p_f_m_7, (uint64_t)dest_addr);
    }
    {
      bt_field *_event_p_f_m_8 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 8);
      bt_field_integer_signed_set_value(_event_p_f_m_8, (int64_t)dest_device_num);
    }
    {
      bt_field *_event_p_f_m_9 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 9);
      bt_field_integer_unsigned_set_value(_event_p_f_m_9, (uint64_t)bytes);
    }
    {
      bt_field *_event_p_f_m_10 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 10);
      bt_field_integer_unsigned_set_value(_event_p_f_m_10, (uint64_t)codeptr_ra);
    }
  }

}

void btx_push_message_lttng_ust_ompt_ompt_callback_target_data_op_emi(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_scope_endpoint_t endpoint, ompt_data_t * target_task_data, ompt_data_t * target_data, ompt_id_t * host_op_id, ompt_target_data_op_t optype, void * src_addr, int src_device_num, void * dest_addr, int dest_device_num, size_t bytes, void * codeptr_ra) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 22);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_ompt_ompt_callback_target_data_op_emi(
      _downstream_event, _timestamp, vpid, vtid, endpoint, target_task_data, target_data, host_op_id, optype, src_addr, src_device_num, dest_addr, dest_device_num, bytes, codeptr_ra);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_ompt_ompt_callback_target_data_op(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_id_t target_id, ompt_id_t host_op_id, ompt_target_data_op_t optype, void * src_addr, int src_device_num, void * dest_addr, int dest_device_num, size_t bytes, void * codeptr_ra) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_integer_signed_set_value(_event_cc_f_m_0, (int64_t)vpid);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_1, (uint64_t)vtid);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_unsigned_set_value(_event_p_f_m_0, (uint64_t)target_id);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)host_op_id);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_signed_set_value(_event_p_f_m_2, (int64_t)optype);
    }
    {
      bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 3);
      bt_field_integer_unsigned_set_value(_event_p_f_m_3, (uint64_t)src_addr);
    }
    {
      bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 4);
      bt_field_integer_signed_set_value(_event_p_f_m_4, (int64_t)src_device_num);
    }
    {
      bt_field *_event_p_f_m_5 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 5);
      bt_field_integer_unsigned_set_value(_event_p_f_m_5, (uint64_t)dest_addr);
    }
    {
      bt_field *_event_p_f_m_6 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 6);
      bt_field_integer_signed_set_value(_event_p_f_m_6, (int64_t)dest_device_num);
    }
    {
      bt_field *_event_p_f_m_7 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 7);
      bt_field_integer_unsigned_set_value(_event_p_f_m_7, (uint64_t)bytes);
    }
    {
      bt_field *_event_p_f_m_8 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 8);
      bt_field_integer_unsigned_set_value(_event_p_f_m_8, (uint64_t)codeptr_ra);
    }
  }

}

void btx_push_message_lttng_ust_ompt_ompt_callback_target_data_op(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_id_t target_id, ompt_id_t host_op_id, ompt_target_data_op_t optype, void * src_addr, int src_device_num, void * dest_addr, int dest_device_num, size_t bytes, void * codeptr_ra) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 23);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_ompt_ompt_callback_target_data_op(
      _downstream_event, _timestamp, vpid, vtid, target_id, host_op_id, optype, src_addr, src_device_num, dest_addr, dest_device_num, bytes, codeptr_ra);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_ompt_ompt_callback_target_emi(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_target_t kind, ompt_scope_endpoint_t endpoint, int device_num, ompt_data_t * task_data, ompt_data_t * target_task_data, ompt_data_t * target_data, void * codeptr_ra) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_integer_signed_set_value(_event_cc_f_m_0, (int64_t)vpid);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_1, (uint64_t)vtid);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_signed_set_value(_event_p_f_m_0, (int64_t)kind);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_signed_set_value(_event_p_f_m_1, (int64_t)endpoint);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_signed_set_value(_event_p_f_m_2, (int64_t)device_num);
    }
    {
      bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 3);
      bt_field_integer_unsigned_set_value(_event_p_f_m_3, (uint64_t)task_data);
    }
    {
      bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 4);
      bt_field_integer_unsigned_set_value(_event_p_f_m_4, (uint64_t)target_task_data);
    }
    {
      bt_field *_event_p_f_m_5 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 5);
      bt_field_integer_unsigned_set_value(_event_p_f_m_5, (uint64_t)target_data);
    }
    {
      bt_field *_event_p_f_m_6 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 6);
      bt_field_integer_unsigned_set_value(_event_p_f_m_6, (uint64_t)codeptr_ra);
    }
  }

}

void btx_push_message_lttng_ust_ompt_ompt_callback_target_emi(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_target_t kind, ompt_scope_endpoint_t endpoint, int device_num, ompt_data_t * task_data, ompt_data_t * target_task_data, ompt_data_t * target_data, void * codeptr_ra) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 24);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_ompt_ompt_callback_target_emi(
      _downstream_event, _timestamp, vpid, vtid, kind, endpoint, device_num, task_data, target_task_data, target_data, codeptr_ra);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_ompt_ompt_callback_target(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_target_t kind, ompt_scope_endpoint_t endpoint, int device_num, ompt_data_t * task_data, ompt_id_t target_id, void * codeptr_ra) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_integer_signed_set_value(_event_cc_f_m_0, (int64_t)vpid);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_1, (uint64_t)vtid);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_signed_set_value(_event_p_f_m_0, (int64_t)kind);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_signed_set_value(_event_p_f_m_1, (int64_t)endpoint);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_signed_set_value(_event_p_f_m_2, (int64_t)device_num);
    }
    {
      bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 3);
      bt_field_integer_unsigned_set_value(_event_p_f_m_3, (uint64_t)task_data);
    }
    {
      bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 4);
      bt_field_integer_unsigned_set_value(_event_p_f_m_4, (uint64_t)target_id);
    }
    {
      bt_field *_event_p_f_m_5 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 5);
      bt_field_integer_unsigned_set_value(_event_p_f_m_5, (uint64_t)codeptr_ra);
    }
  }

}

void btx_push_message_lttng_ust_ompt_ompt_callback_target(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_target_t kind, ompt_scope_endpoint_t endpoint, int device_num, ompt_data_t * task_data, ompt_id_t target_id, void * codeptr_ra) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 25);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_ompt_ompt_callback_target(
      _downstream_event, _timestamp, vpid, vtid, kind, endpoint, device_num, task_data, target_id, codeptr_ra);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_ompt_ompt_callback_target_map_emi(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_data_t * target_data, unsigned int nitems, void ** host_addr, void ** device_addr, size_t * bytes, unsigned int * mapping_flags, void * codeptr_ra) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_integer_signed_set_value(_event_cc_f_m_0, (int64_t)vpid);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_1, (uint64_t)vtid);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_unsigned_set_value(_event_p_f_m_0, (uint64_t)target_data);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)nitems);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_unsigned_set_value(_event_p_f_m_2, (uint64_t)host_addr);
    }
    {
      bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 3);
      bt_field_integer_unsigned_set_value(_event_p_f_m_3, (uint64_t)device_addr);
    }
    {
      bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 4);
      bt_field_integer_unsigned_set_value(_event_p_f_m_4, (uint64_t)bytes);
    }
    {
      bt_field *_event_p_f_m_5 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 5);
      bt_field_integer_unsigned_set_value(_event_p_f_m_5, (uint64_t)mapping_flags);
    }
    {
      bt_field *_event_p_f_m_6 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 6);
      bt_field_integer_unsigned_set_value(_event_p_f_m_6, (uint64_t)codeptr_ra);
    }
  }

}

void btx_push_message_lttng_ust_ompt_ompt_callback_target_map_emi(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_data_t * target_data, unsigned int nitems, void ** host_addr, void ** device_addr, size_t * bytes, unsigned int * mapping_flags, void * codeptr_ra) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 26);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_ompt_ompt_callback_target_map_emi(
      _downstream_event, _timestamp, vpid, vtid, target_data, nitems, host_addr, device_addr, bytes, mapping_flags, codeptr_ra);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_ompt_ompt_callback_target_map(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_id_t target_id, unsigned int nitems, void ** host_addr, void ** device_addr, size_t * bytes, ompt_target_map_flags_t * mapping_flags, void * codeptr_ra, size_t _host_addr_vals_length, void * * host_addr_vals, size_t _device_addr_vals_length, void * * device_addr_vals, size_t _bytes_vals_length, size_t * bytes_vals, size_t _mapping_flags_vals_length, ompt_target_map_flags_t * mapping_flags_vals) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_integer_signed_set_value(_event_cc_f_m_0, (int64_t)vpid);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_1, (uint64_t)vtid);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_unsigned_set_value(_event_p_f_m_0, (uint64_t)target_id);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)nitems);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_unsigned_set_value(_event_p_f_m_2, (uint64_t)host_addr);
    }
    {
      bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 3);
      bt_field_integer_unsigned_set_value(_event_p_f_m_3, (uint64_t)device_addr);
    }
    {
      bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 4);
      bt_field_integer_unsigned_set_value(_event_p_f_m_4, (uint64_t)bytes);
    }
    {
      bt_field *_event_p_f_m_5 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 5);
      bt_field_integer_unsigned_set_value(_event_p_f_m_5, (uint64_t)mapping_flags);
    }
    {
      bt_field *_event_p_f_m_6 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 6);
      bt_field_integer_unsigned_set_value(_event_p_f_m_6, (uint64_t)codeptr_ra);
    }
    {
      bt_field *_event_p_f_m_7 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 7);
      bt_field_integer_unsigned_set_value(_event_p_f_m_7, (uint64_t)_host_addr_vals_length);
    }
    {
      bt_field *_event_p_f_m_8 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 8);
      bt_field_array_dynamic_set_length(_event_p_f_m_8, _host_addr_vals_length);
      for(uint64_t _i=0; _i < _host_addr_vals_length ; _i++)
      {
        bt_field* _event_p_f_m_8_e = bt_field_array_borrow_element_field_by_index(_event_p_f_m_8, _i);
        bt_field_integer_unsigned_set_value(_event_p_f_m_8_e, (uint64_t)host_addr_vals[_i]);
      }
    }
    {
      bt_field *_event_p_f_m_9 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 9);
      bt_field_integer_unsigned_set_value(_event_p_f_m_9, (uint64_t)_device_addr_vals_length);
    }
    {
      bt_field *_event_p_f_m_10 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 10);
      bt_field_array_dynamic_set_length(_event_p_f_m_10, _device_addr_vals_length);
      for(uint64_t _i=0; _i < _device_addr_vals_length ; _i++)
      {
        bt_field* _event_p_f_m_10_e = bt_field_array_borrow_element_field_by_index(_event_p_f_m_10, _i);
        bt_field_integer_unsigned_set_value(_event_p_f_m_10_e, (uint64_t)device_addr_vals[_i]);
      }
    }
    {
      bt_field *_event_p_f_m_11 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 11);
      bt_field_integer_unsigned_set_value(_event_p_f_m_11, (uint64_t)_bytes_vals_length);
    }
    {
      bt_field *_event_p_f_m_12 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 12);
      bt_field_array_dynamic_set_length(_event_p_f_m_12, _bytes_vals_length);
      for(uint64_t _i=0; _i < _bytes_vals_length ; _i++)
      {
        bt_field* _event_p_f_m_12_e = bt_field_array_borrow_element_field_by_index(_event_p_f_m_12, _i);
        bt_field_integer_unsigned_set_value(_event_p_f_m_12_e, (uint64_t)bytes_vals[_i]);
      }
    }
    {
      bt_field *_event_p_f_m_13 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 13);
      bt_field_integer_unsigned_set_value(_event_p_f_m_13, (uint64_t)_mapping_flags_vals_length);
    }
    {
      bt_field *_event_p_f_m_14 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 14);
      bt_field_array_dynamic_set_length(_event_p_f_m_14, _mapping_flags_vals_length);
      for(uint64_t _i=0; _i < _mapping_flags_vals_length ; _i++)
      {
        bt_field* _event_p_f_m_14_e = bt_field_array_borrow_element_field_by_index(_event_p_f_m_14, _i);
        bt_field_integer_unsigned_set_value(_event_p_f_m_14_e, (uint64_t)mapping_flags_vals[_i]);
      }
    }
  }

}

void btx_push_message_lttng_ust_ompt_ompt_callback_target_map(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_id_t target_id, unsigned int nitems, void ** host_addr, void ** device_addr, size_t * bytes, ompt_target_map_flags_t * mapping_flags, void * codeptr_ra, size_t _host_addr_vals_length, void * * host_addr_vals, size_t _device_addr_vals_length, void * * device_addr_vals, size_t _bytes_vals_length, size_t * bytes_vals, size_t _mapping_flags_vals_length, ompt_target_map_flags_t * mapping_flags_vals) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 27);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_ompt_ompt_callback_target_map(
      _downstream_event, _timestamp, vpid, vtid, target_id, nitems, host_addr, device_addr, bytes, mapping_flags, codeptr_ra, _host_addr_vals_length, host_addr_vals, _device_addr_vals_length, device_addr_vals, _bytes_vals_length, bytes_vals, _mapping_flags_vals_length, mapping_flags_vals);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_ompt_ompt_callback_target_submit(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_id_t target_id, ompt_id_t host_op_id, unsigned int requested_num_teams) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_integer_signed_set_value(_event_cc_f_m_0, (int64_t)vpid);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_1, (uint64_t)vtid);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_unsigned_set_value(_event_p_f_m_0, (uint64_t)target_id);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)host_op_id);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_unsigned_set_value(_event_p_f_m_2, (uint64_t)requested_num_teams);
    }
  }

}

void btx_push_message_lttng_ust_ompt_ompt_callback_target_submit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_id_t target_id, ompt_id_t host_op_id, unsigned int requested_num_teams) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 28);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_ompt_ompt_callback_target_submit(
      _downstream_event, _timestamp, vpid, vtid, target_id, host_op_id, requested_num_teams);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_ompt_ompt_callback_target_submit_emi(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_scope_endpoint_t endpoint, ompt_data_t * target_data, ompt_id_t * host_op_id, unsigned int requested_num_teams) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_integer_signed_set_value(_event_cc_f_m_0, (int64_t)vpid);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_1, (uint64_t)vtid);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_signed_set_value(_event_p_f_m_0, (int64_t)endpoint);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)target_data);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_unsigned_set_value(_event_p_f_m_2, (uint64_t)host_op_id);
    }
    {
      bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 3);
      bt_field_integer_unsigned_set_value(_event_p_f_m_3, (uint64_t)requested_num_teams);
    }
  }

}

void btx_push_message_lttng_ust_ompt_ompt_callback_target_submit_emi(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_scope_endpoint_t endpoint, ompt_data_t * target_data, ompt_id_t * host_op_id, unsigned int requested_num_teams) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 29);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_ompt_ompt_callback_target_submit_emi(
      _downstream_event, _timestamp, vpid, vtid, endpoint, target_data, host_op_id, requested_num_teams);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_ompt_ompt_callback_control_tool(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, int ompResult, uint64_t command, uint64_t modifier, void * arg, void * codeptr_ra) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_integer_signed_set_value(_event_cc_f_m_0, (int64_t)vpid);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_1, (uint64_t)vtid);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_signed_set_value(_event_p_f_m_0, (int64_t)ompResult);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)command);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_unsigned_set_value(_event_p_f_m_2, (uint64_t)modifier);
    }
    {
      bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 3);
      bt_field_integer_unsigned_set_value(_event_p_f_m_3, (uint64_t)arg);
    }
    {
      bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 4);
      bt_field_integer_unsigned_set_value(_event_p_f_m_4, (uint64_t)codeptr_ra);
    }
  }

}

void btx_push_message_lttng_ust_ompt_ompt_callback_control_tool(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int ompResult, uint64_t command, uint64_t modifier, void * arg, void * codeptr_ra) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 30);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_ompt_ompt_callback_control_tool(
      _downstream_event, _timestamp, vpid, vtid, ompResult, command, modifier, arg, codeptr_ra);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_ompt_ompt_callback_error(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_severity_t severity, char * message, size_t length, void * codeptr_ra) {
  {
    bt_field *_event_cc_f = bt_event_borrow_common_context_field(_event);
    {
      bt_field *_event_cc_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 0);
      bt_field_integer_signed_set_value(_event_cc_f_m_0, (int64_t)vpid);
    }
    {
      bt_field *_event_cc_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_cc_f, 1);
      bt_field_integer_unsigned_set_value(_event_cc_f_m_1, (uint64_t)vtid);
    }
  }
  {
    bt_field *_event_p_f = bt_event_borrow_payload_field(_event);
    {
      bt_field *_event_p_f_m_0 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 0);
      bt_field_integer_signed_set_value(_event_p_f_m_0, (int64_t)severity);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)message);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_unsigned_set_value(_event_p_f_m_2, (uint64_t)length);
    }
    {
      bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 3);
      bt_field_integer_unsigned_set_value(_event_p_f_m_3, (uint64_t)codeptr_ra);
    }
  }

}

void btx_push_message_lttng_ust_ompt_ompt_callback_error(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, ompt_severity_t severity, char * message, size_t length, void * codeptr_ra) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 31);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_ompt_ompt_callback_error(
      _downstream_event, _timestamp, vpid, vtid, severity, message, length, codeptr_ra);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}

void btx_downstream_set_environment_hostname(
    void *btx_handle, const char* hostname) {
  common_data_t *common_data = (common_data_t *)btx_handle;
  bt_trace *_trace = common_data->downstream_trace;
  bt_trace_set_environment_entry_string(_trace, "hostname", hostname);

}
