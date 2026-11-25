#include <babeltrace2/babeltrace.h>
#include <metababel/btx_component.h>
// stdio needed because `params_definition` contain fprintf

void btx_populate_params(common_data_t *common_data) {
}

void btx_register_callbacks_initialize_component(
    void *btx_handle, initialize_component_static_callback_f *callback) {
  ((common_data_t *)btx_handle)->static_callbacks->initialize_component =
      callback;
}

void btx_call_callbacks_initialize_component(
    common_data_t *common_data,
    void ** usr_data_p) {

  initialize_component_static_callback_f *p =
      common_data->static_callbacks->initialize_component;
  if (p)
    p(
          usr_data_p);
}
void btx_register_callbacks_finalize_component(
    void *btx_handle, finalize_component_static_callback_f *callback) {
  ((common_data_t *)btx_handle)->static_callbacks->finalize_component =
      callback;
}

void btx_call_callbacks_finalize_component(
    common_data_t *common_data,
    void * usr_data) {

  finalize_component_static_callback_f *p =
      common_data->static_callbacks->finalize_component;
  if (p)
    p(
          usr_data);
}
void btx_register_callbacks_read_params(
    void *btx_handle, read_params_static_callback_f *callback) {
  ((common_data_t *)btx_handle)->static_callbacks->read_params =
      callback;
}

void btx_call_callbacks_read_params(
    common_data_t *common_data,
    void * usr_data, btx_params_t * usr_params) {

  read_params_static_callback_f *p =
      common_data->static_callbacks->read_params;
  if (p)
    p(
          usr_data, usr_params);
}
void btx_register_callbacks_initialize_processing(
    void *btx_handle, initialize_processing_static_callback_f *callback) {
  ((common_data_t *)btx_handle)->static_callbacks->initialize_processing =
      callback;
}

void btx_call_callbacks_initialize_processing(
    common_data_t *common_data,
    void * usr_data_p) {

  initialize_processing_static_callback_f *p =
      common_data->static_callbacks->initialize_processing;
  if (p)
    p((void *)common_data,
          usr_data_p);
}
void btx_register_callbacks_finalize_processing(
    void *btx_handle, finalize_processing_static_callback_f *callback) {
  ((common_data_t *)btx_handle)->static_callbacks->finalize_processing =
      callback;
}

void btx_call_callbacks_finalize_processing(
    common_data_t *common_data,
    void * usr_data) {

  finalize_processing_static_callback_f *p =
      common_data->static_callbacks->finalize_processing;
  if (p)
    p((void *)common_data,
          usr_data);
}
void btx_register_callbacks_push_usr_messages(
    void *btx_handle, push_usr_messages_static_callback_f *callback) {
  ((common_data_t *)btx_handle)->static_callbacks->push_usr_messages =
      callback;
}

void btx_call_callbacks_push_usr_messages(
    common_data_t *common_data,
    void * usr_data, btx_source_status_t* status) {

  push_usr_messages_static_callback_f *p =
      common_data->static_callbacks->push_usr_messages;
  if (p)
    p((void *)common_data,
          usr_data, status);
}

void btx_unregister_callbacks(common_data_t *common_data) {
  name_to_dispatcher_t *current, *tmp;
  HASH_ITER(hh, common_data->name_to_dispatcher, current, tmp) {
    HASH_DEL(common_data->name_to_dispatcher, current);
    if (current->callbacks->automatic)
      utarray_free(current->callbacks->automatic);
    free(current->callbacks);
    free(current);
  }
}
