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

void btx_push_message(void *btx_handle, const bt_message *message) {
  _btx_push_message((btx_message_iterator_t *)btx_handle, message);
}

void btx_register_on_downstream_message_callback(
    void *btx_handle, on_downstream_message_callback_f *callback) {
  ((common_data_t *)btx_handle)->on_downstream_message_callback =
      (void *)callback;
}
// Used internally to push messages downstreams
void btx_downstream_push_message(
    btx_message_iterator_t *message_iterator_private_data,
    const bt_message *message) {

  on_downstream_message_callback_f *p =
      (on_downstream_message_callback_f *)message_iterator_private_data
          ->common_data->on_downstream_message_callback;
  if (p) {
    p(((void *)message_iterator_private_data),
      message_iterator_private_data->common_data->usr_data, message);
    return;
  }
  _btx_push_message(message_iterator_private_data, message);
}

// Register callbacks
bt_trace_class *
btx_downstream_trace_class_create_rec(bt_self_component *_self_component) {
  bt_trace_class *_trace_class;
  _trace_class = bt_trace_class_create(_self_component);

  return _trace_class;
}

bt_trace *btx_downstream_trace_create_rec(bt_trace_class *trace_class) {
  bt_trace *trace = bt_trace_create(trace_class);
  return trace;
}

// Workaround of a bug where gepping trace alive (and not the stream) provoke
// some segfault
void btx_streams_get_ref(bt_trace *trace) {
}

void btx_streams_put_ref(bt_trace *trace) {
}

void btx_push_messages_stream_beginning(
    bt_self_message_iterator *self_message_iterator,
    btx_message_iterator_t *message_iterator_private_data) {

  bt_trace *trace =
      message_iterator_private_data->common_data->downstream_trace;
  (void)trace;
}

void btx_push_messages_stream_end(
    bt_self_message_iterator *self_message_iterator,
    btx_message_iterator_t *message_iterator_private_data) {

  bt_trace *trace =
      message_iterator_private_data->common_data->downstream_trace;
  (void)trace;
}


