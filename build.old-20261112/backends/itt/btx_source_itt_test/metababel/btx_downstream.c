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
    bt_stream_class_set_name(_trace_class_sc_0, "thapi_itt");
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
      bt_event_class_set_name(_trace_class_sc_0_ec_0, "lttng_ust_itt:__itt_domain_create");
      {
        bt_field_class *_trace_class_sc_0_ec_0_p_fc;
        _trace_class_sc_0_ec_0_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_0_p_fc_m_0;
          _trace_class_sc_0_ec_0_p_fc_m_0 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_0_p_fc_m_0, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_0_p_fc_m_0, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_0_p_fc, "ittResult", _trace_class_sc_0_ec_0_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_0_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_0_p_fc_m_1;
          _trace_class_sc_0_ec_0_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_0_p_fc_m_1, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_0_p_fc_m_1, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_0_p_fc, "name", _trace_class_sc_0_ec_0_p_fc_m_1);
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
      bt_event_class_set_name(_trace_class_sc_0_ec_1, "lttng_ust_itt:__itt_string_handle_create");
      {
        bt_field_class *_trace_class_sc_0_ec_1_p_fc;
        _trace_class_sc_0_ec_1_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_1_p_fc_m_0;
          _trace_class_sc_0_ec_1_p_fc_m_0 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_1_p_fc_m_0, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_1_p_fc_m_0, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_1_p_fc, "ittResult", _trace_class_sc_0_ec_1_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_1_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_1_p_fc_m_1;
          _trace_class_sc_0_ec_1_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_1_p_fc_m_1, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_1_p_fc_m_1, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_1_p_fc, "name", _trace_class_sc_0_ec_1_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_1_p_fc_m_1);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_1, _trace_class_sc_0_ec_1_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_1_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_1);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_2;
      _trace_class_sc_0_ec_2 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_2, "lttng_ust_itt:__itt_task_begin");
      {
        bt_field_class *_trace_class_sc_0_ec_2_p_fc;
        _trace_class_sc_0_ec_2_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_2_p_fc_m_0;
          _trace_class_sc_0_ec_2_p_fc_m_0 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_2_p_fc_m_0, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_2_p_fc_m_0, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_2_p_fc, "domain", _trace_class_sc_0_ec_2_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_2_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_2_p_fc_m_1;
          _trace_class_sc_0_ec_2_p_fc_m_1 = bt_field_class_string_create(_trace_class);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_2_p_fc, "taskid", _trace_class_sc_0_ec_2_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_2_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_2_p_fc_m_2;
          _trace_class_sc_0_ec_2_p_fc_m_2 = bt_field_class_string_create(_trace_class);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_2_p_fc, "parentid", _trace_class_sc_0_ec_2_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_0_ec_2_p_fc_m_2);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_2_p_fc_m_3;
          _trace_class_sc_0_ec_2_p_fc_m_3 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_2_p_fc_m_3, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_2_p_fc_m_3, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_2_p_fc, "name", _trace_class_sc_0_ec_2_p_fc_m_3);
          bt_field_class_put_ref(_trace_class_sc_0_ec_2_p_fc_m_3);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_2_p_fc_m_4;
          _trace_class_sc_0_ec_2_p_fc_m_4 = bt_field_class_string_create(_trace_class);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_2_p_fc, "domain__nameA_val", _trace_class_sc_0_ec_2_p_fc_m_4);
          bt_field_class_put_ref(_trace_class_sc_0_ec_2_p_fc_m_4);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_2_p_fc_m_5;
          _trace_class_sc_0_ec_2_p_fc_m_5 = bt_field_class_string_create(_trace_class);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_2_p_fc, "name__strA_val", _trace_class_sc_0_ec_2_p_fc_m_5);
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
      bt_event_class_set_name(_trace_class_sc_0_ec_3, "lttng_ust_itt:__itt_task_end");
      {
        bt_field_class *_trace_class_sc_0_ec_3_p_fc;
        _trace_class_sc_0_ec_3_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_3_p_fc_m_0;
          _trace_class_sc_0_ec_3_p_fc_m_0 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_3_p_fc_m_0, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_3_p_fc_m_0, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_3_p_fc, "domain", _trace_class_sc_0_ec_3_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_3_p_fc_m_0);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_3, _trace_class_sc_0_ec_3_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_3_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_3);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_4;
      _trace_class_sc_0_ec_4 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_4, "lttng_ust_itt:__itt_metadata_add");
      {
        bt_field_class *_trace_class_sc_0_ec_4_p_fc;
        _trace_class_sc_0_ec_4_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_4_p_fc_m_0;
          _trace_class_sc_0_ec_4_p_fc_m_0 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_4_p_fc_m_0, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_4_p_fc_m_0, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_4_p_fc, "domain", _trace_class_sc_0_ec_4_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_4_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_4_p_fc_m_1;
          _trace_class_sc_0_ec_4_p_fc_m_1 = bt_field_class_string_create(_trace_class);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_4_p_fc, "id", _trace_class_sc_0_ec_4_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_4_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_4_p_fc_m_2;
          _trace_class_sc_0_ec_4_p_fc_m_2 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_4_p_fc_m_2, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_4_p_fc_m_2, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_4_p_fc, "key", _trace_class_sc_0_ec_4_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_0_ec_4_p_fc_m_2);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_4_p_fc_m_3;
          _trace_class_sc_0_ec_4_p_fc_m_3 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_4_p_fc_m_3, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_4_p_fc, "type", _trace_class_sc_0_ec_4_p_fc_m_3);
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
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_4_p_fc, "data", _trace_class_sc_0_ec_4_p_fc_m_5);
          bt_field_class_put_ref(_trace_class_sc_0_ec_4_p_fc_m_5);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_4_p_fc_m_6;
          _trace_class_sc_0_ec_4_p_fc_m_6 = bt_field_class_string_create(_trace_class);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_4_p_fc, "key__strA_val", _trace_class_sc_0_ec_4_p_fc_m_6);
          bt_field_class_put_ref(_trace_class_sc_0_ec_4_p_fc_m_6);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_4, _trace_class_sc_0_ec_4_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_4_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_4);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_5;
      _trace_class_sc_0_ec_5 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_5, "lttng_ust_itt:__itt_event_create");
      {
        bt_field_class *_trace_class_sc_0_ec_5_p_fc;
        _trace_class_sc_0_ec_5_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_5_p_fc_m_0;
          _trace_class_sc_0_ec_5_p_fc_m_0 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_5_p_fc_m_0, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_5_p_fc, "ittResult", _trace_class_sc_0_ec_5_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_5_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_5_p_fc_m_1;
          _trace_class_sc_0_ec_5_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_5_p_fc_m_1, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_5_p_fc_m_1, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_5_p_fc, "name", _trace_class_sc_0_ec_5_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_5_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_5_p_fc_m_2;
          _trace_class_sc_0_ec_5_p_fc_m_2 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_5_p_fc_m_2, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_5_p_fc, "namelen", _trace_class_sc_0_ec_5_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_0_ec_5_p_fc_m_2);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_5_p_fc_m_3;
          _trace_class_sc_0_ec_5_p_fc_m_3 = bt_field_class_string_create(_trace_class);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_5_p_fc, "name_val", _trace_class_sc_0_ec_5_p_fc_m_3);
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
      bt_event_class_set_name(_trace_class_sc_0_ec_6, "lttng_ust_itt:__itt_event_start");
      {
        bt_field_class *_trace_class_sc_0_ec_6_p_fc;
        _trace_class_sc_0_ec_6_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_6_p_fc_m_0;
          _trace_class_sc_0_ec_6_p_fc_m_0 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_6_p_fc_m_0, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_6_p_fc, "ittResult", _trace_class_sc_0_ec_6_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_6_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_6_p_fc_m_1;
          _trace_class_sc_0_ec_6_p_fc_m_1 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_6_p_fc_m_1, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_6_p_fc, "event", _trace_class_sc_0_ec_6_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_6_p_fc_m_1);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_6, _trace_class_sc_0_ec_6_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_6_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_6);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_7;
      _trace_class_sc_0_ec_7 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_7, "lttng_ust_itt:__itt_event_end");
      {
        bt_field_class *_trace_class_sc_0_ec_7_p_fc;
        _trace_class_sc_0_ec_7_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_7_p_fc_m_0;
          _trace_class_sc_0_ec_7_p_fc_m_0 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_7_p_fc_m_0, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_7_p_fc, "ittResult", _trace_class_sc_0_ec_7_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_7_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_7_p_fc_m_1;
          _trace_class_sc_0_ec_7_p_fc_m_1 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_7_p_fc_m_1, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_7_p_fc, "event", _trace_class_sc_0_ec_7_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_7_p_fc_m_1);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_7, _trace_class_sc_0_ec_7_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_7_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_7);
    }
    {
      bt_event_class *_trace_class_sc_0_ec_8;
      _trace_class_sc_0_ec_8 = bt_event_class_create(_trace_class_sc_0);
      bt_event_class_set_name(_trace_class_sc_0_ec_8, "lttng_ust_itt_metadata:metadata");
      {
        bt_field_class *_trace_class_sc_0_ec_8_p_fc;
        _trace_class_sc_0_ec_8_p_fc = bt_field_class_structure_create(_trace_class);
        {
          bt_field_class *_trace_class_sc_0_ec_8_p_fc_m_0;
          _trace_class_sc_0_ec_8_p_fc_m_0 = bt_field_class_integer_signed_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_8_p_fc_m_0, 32);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_8_p_fc, "type", _trace_class_sc_0_ec_8_p_fc_m_0);
          bt_field_class_put_ref(_trace_class_sc_0_ec_8_p_fc_m_0);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_8_p_fc_m_1;
          _trace_class_sc_0_ec_8_p_fc_m_1 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_8_p_fc_m_1, 64);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_8_p_fc, "count", _trace_class_sc_0_ec_8_p_fc_m_1);
          bt_field_class_put_ref(_trace_class_sc_0_ec_8_p_fc_m_1);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_8_p_fc_m_2;
          _trace_class_sc_0_ec_8_p_fc_m_2 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_8_p_fc_m_2, 64);
          bt_field_class_integer_set_preferred_display_base(_trace_class_sc_0_ec_8_p_fc_m_2, 16);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_8_p_fc, "data", _trace_class_sc_0_ec_8_p_fc_m_2);
          bt_field_class_put_ref(_trace_class_sc_0_ec_8_p_fc_m_2);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_8_p_fc_m_3;
          _trace_class_sc_0_ec_8_p_fc_m_3 = bt_field_class_integer_unsigned_create(_trace_class);
          bt_field_class_integer_set_field_value_range(_trace_class_sc_0_ec_8_p_fc_m_3, 64);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_8_p_fc, "_data_val_length", _trace_class_sc_0_ec_8_p_fc_m_3);
          bt_field_class_put_ref(_trace_class_sc_0_ec_8_p_fc_m_3);
        }
        {
          bt_field_class *_trace_class_sc_0_ec_8_p_fc_m_4;
          _trace_class_sc_0_ec_8_p_fc_m_4 = bt_field_class_string_create(_trace_class);
          bt_field_class_structure_append_member(_trace_class_sc_0_ec_8_p_fc, "data_val", _trace_class_sc_0_ec_8_p_fc_m_4);
          bt_field_class_put_ref(_trace_class_sc_0_ec_8_p_fc_m_4);
        }
        bt_event_class_set_payload_field_class(_trace_class_sc_0_ec_8, _trace_class_sc_0_ec_8_p_fc);
        bt_field_class_put_ref(_trace_class_sc_0_ec_8_p_fc);
      }
      bt_event_class_put_ref(_trace_class_sc_0_ec_8);
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

static void btx_set_message_lttng_ust_itt___itt_domain_create(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, __itt_domain * ittResult, char * name) {
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
      bt_field_integer_unsigned_set_value(_event_p_f_m_0, (uint64_t)ittResult);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)name);
    }
  }

}

void btx_push_message_lttng_ust_itt___itt_domain_create(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, __itt_domain * ittResult, char * name) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 0);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_itt___itt_domain_create(
      _downstream_event, _timestamp, vpid, vtid, ittResult, name);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_itt___itt_string_handle_create(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, __itt_string_handle * ittResult, char * name) {
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
      bt_field_integer_unsigned_set_value(_event_p_f_m_0, (uint64_t)ittResult);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)name);
    }
  }

}

void btx_push_message_lttng_ust_itt___itt_string_handle_create(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, __itt_string_handle * ittResult, char * name) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 1);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_itt___itt_string_handle_create(
      _downstream_event, _timestamp, vpid, vtid, ittResult, name);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_itt___itt_task_begin(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, __itt_domain * domain, __itt_id taskid, __itt_id parentid, __itt_string_handle * name, char * domain__nameA_val, char * name__strA_val) {
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
      bt_field_integer_unsigned_set_value(_event_p_f_m_0, (uint64_t)domain);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      // Dump data to a temporal string.
      char *_event_p_f_m_1_temp = (char *)malloc(sizeof(taskid));
      assert(_event_p_f_m_1_temp != NULL && "Out of memory");
      memcpy(_event_p_f_m_1_temp, &taskid, sizeof(taskid));
      // Set string field with dumped data.
      bt_field_string_clear(_event_p_f_m_1);
      bt_field_string_append_status _event_p_f_m_1_status = bt_field_string_append_with_length(_event_p_f_m_1, _event_p_f_m_1_temp, sizeof(taskid));
      assert(_event_p_f_m_1_status == BT_FIELD_STRING_APPEND_STATUS_OK && "Out of memory");
      free(_event_p_f_m_1_temp);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      // Dump data to a temporal string.
      char *_event_p_f_m_2_temp = (char *)malloc(sizeof(parentid));
      assert(_event_p_f_m_2_temp != NULL && "Out of memory");
      memcpy(_event_p_f_m_2_temp, &parentid, sizeof(parentid));
      // Set string field with dumped data.
      bt_field_string_clear(_event_p_f_m_2);
      bt_field_string_append_status _event_p_f_m_2_status = bt_field_string_append_with_length(_event_p_f_m_2, _event_p_f_m_2_temp, sizeof(parentid));
      assert(_event_p_f_m_2_status == BT_FIELD_STRING_APPEND_STATUS_OK && "Out of memory");
      free(_event_p_f_m_2_temp);
    }
    {
      bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 3);
      bt_field_integer_unsigned_set_value(_event_p_f_m_3, (uint64_t)name);
    }
    {
      bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 4);
      bt_field_string_set_value(_event_p_f_m_4, (const char*)domain__nameA_val);
    }
    {
      bt_field *_event_p_f_m_5 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 5);
      bt_field_string_set_value(_event_p_f_m_5, (const char*)name__strA_val);
    }
  }

}

void btx_push_message_lttng_ust_itt___itt_task_begin(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, __itt_domain * domain, __itt_id taskid, __itt_id parentid, __itt_string_handle * name, char * domain__nameA_val, char * name__strA_val) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 2);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_itt___itt_task_begin(
      _downstream_event, _timestamp, vpid, vtid, domain, taskid, parentid, name, domain__nameA_val, name__strA_val);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_itt___itt_task_end(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, __itt_domain * domain) {
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
      bt_field_integer_unsigned_set_value(_event_p_f_m_0, (uint64_t)domain);
    }
  }

}

void btx_push_message_lttng_ust_itt___itt_task_end(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, __itt_domain * domain) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 3);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_itt___itt_task_end(
      _downstream_event, _timestamp, vpid, vtid, domain);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_itt___itt_metadata_add(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, __itt_domain * domain, __itt_id id, __itt_string_handle * key, __itt_metadata_type type, size_t count, void * data, char * key__strA_val) {
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
      bt_field_integer_unsigned_set_value(_event_p_f_m_0, (uint64_t)domain);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      // Dump data to a temporal string.
      char *_event_p_f_m_1_temp = (char *)malloc(sizeof(id));
      assert(_event_p_f_m_1_temp != NULL && "Out of memory");
      memcpy(_event_p_f_m_1_temp, &id, sizeof(id));
      // Set string field with dumped data.
      bt_field_string_clear(_event_p_f_m_1);
      bt_field_string_append_status _event_p_f_m_1_status = bt_field_string_append_with_length(_event_p_f_m_1, _event_p_f_m_1_temp, sizeof(id));
      assert(_event_p_f_m_1_status == BT_FIELD_STRING_APPEND_STATUS_OK && "Out of memory");
      free(_event_p_f_m_1_temp);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_unsigned_set_value(_event_p_f_m_2, (uint64_t)key);
    }
    {
      bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 3);
      bt_field_integer_signed_set_value(_event_p_f_m_3, (int64_t)type);
    }
    {
      bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 4);
      bt_field_integer_unsigned_set_value(_event_p_f_m_4, (uint64_t)count);
    }
    {
      bt_field *_event_p_f_m_5 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 5);
      bt_field_integer_unsigned_set_value(_event_p_f_m_5, (uint64_t)data);
    }
    {
      bt_field *_event_p_f_m_6 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 6);
      bt_field_string_set_value(_event_p_f_m_6, (const char*)key__strA_val);
    }
  }

}

void btx_push_message_lttng_ust_itt___itt_metadata_add(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, __itt_domain * domain, __itt_id id, __itt_string_handle * key, __itt_metadata_type type, size_t count, void * data, char * key__strA_val) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 4);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_itt___itt_metadata_add(
      _downstream_event, _timestamp, vpid, vtid, domain, id, key, type, count, data, key__strA_val);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_itt___itt_event_create(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, __itt_event ittResult, char * name, int namelen, char * name_val) {
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
      bt_field_integer_signed_set_value(_event_p_f_m_0, (int64_t)ittResult);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)name);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_signed_set_value(_event_p_f_m_2, (int64_t)namelen);
    }
    {
      bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 3);
      bt_field_string_set_value(_event_p_f_m_3, (const char*)name_val);
    }
  }

}

void btx_push_message_lttng_ust_itt___itt_event_create(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, __itt_event ittResult, char * name, int namelen, char * name_val) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 5);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_itt___itt_event_create(
      _downstream_event, _timestamp, vpid, vtid, ittResult, name, namelen, name_val);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_itt___itt_event_start(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, int ittResult, __itt_event event) {
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
      bt_field_integer_signed_set_value(_event_p_f_m_0, (int64_t)ittResult);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_signed_set_value(_event_p_f_m_1, (int64_t)event);
    }
  }

}

void btx_push_message_lttng_ust_itt___itt_event_start(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int ittResult, __itt_event event) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 6);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_itt___itt_event_start(
      _downstream_event, _timestamp, vpid, vtid, ittResult, event);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_itt___itt_event_end(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, int ittResult, __itt_event event) {
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
      bt_field_integer_signed_set_value(_event_p_f_m_0, (int64_t)ittResult);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_signed_set_value(_event_p_f_m_1, (int64_t)event);
    }
  }

}

void btx_push_message_lttng_ust_itt___itt_event_end(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int ittResult, __itt_event event) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 7);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_itt___itt_event_end(
      _downstream_event, _timestamp, vpid, vtid, ittResult, event);

  btx_message_iterator_t *_message_iterator_private_data =
      (btx_message_iterator_t *)bt_self_message_iterator_get_data(
          common_data->self_message_iterator);
  btx_downstream_push_message(_message_iterator_private_data, _message);
}
static void btx_set_message_lttng_ust_itt_metadata_metadata(
    bt_event *
        _event, int64_t _timestamp, int64_t vpid, uint64_t vtid, __itt_metadata_type type, size_t count, void* data, size_t _data_val_length, void* data_val) {
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
      bt_field_integer_signed_set_value(_event_p_f_m_0, (int64_t)type);
    }
    {
      bt_field *_event_p_f_m_1 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 1);
      bt_field_integer_unsigned_set_value(_event_p_f_m_1, (uint64_t)count);
    }
    {
      bt_field *_event_p_f_m_2 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 2);
      bt_field_integer_unsigned_set_value(_event_p_f_m_2, (uint64_t)data);
    }
    {
      bt_field *_event_p_f_m_3 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 3);
      bt_field_integer_unsigned_set_value(_event_p_f_m_3, (uint64_t)_data_val_length);
    }
    {
      bt_field *_event_p_f_m_4 = bt_field_structure_borrow_member_field_by_index(_event_p_f, 4);
      bt_field_string_set_value(_event_p_f_m_4, (const char*)data_val);
    }
  }

}

void btx_push_message_lttng_ust_itt_metadata_metadata(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, __itt_metadata_type type, size_t count, void* data, size_t _data_val_length, void* data_val) {

  common_data_t *common_data = (common_data_t *)btx_handle;

  bt_stream *_stream = bt_trace_borrow_stream_by_index(
      common_data->downstream_trace, 0);
  bt_stream_class *_stream_class = bt_stream_borrow_class(_stream);
  bt_event_class *_event_class = bt_stream_class_borrow_event_class_by_index(
      _stream_class, 8);
  bt_message *_message = bt_message_event_create_with_default_clock_snapshot(
      common_data->self_message_iterator, _event_class, _stream, _timestamp);

  bt_event *_downstream_event = bt_message_event_borrow_event(_message);

  btx_set_message_lttng_ust_itt_metadata_metadata(
      _downstream_event, _timestamp, vpid, vtid, type, count, data, _data_val_length, data_val);

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
