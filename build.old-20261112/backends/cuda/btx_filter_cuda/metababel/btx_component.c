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

void btx_unregister_callbacks(common_data_t *common_data) {
  name_to_dispatcher_t *current, *tmp;
  HASH_ITER(hh, common_data->name_to_dispatcher, current, tmp) {
    HASH_DEL(common_data->name_to_dispatcher, current);
    if (current->callbacks->automatic)
      utarray_free(current->callbacks->automatic);
    if (current->callbacks->matching_entries)
      utarray_free(current->callbacks->matching_entries);
    if (current->callbacks->matching_exits_cudaError_present)
      utarray_free(current->callbacks->matching_exits_cudaError_present);
    if (current->callbacks->matching_exits_cudaError_absent)
      utarray_free(current->callbacks->matching_exits_cudaError_absent);
    if (current->callbacks->matching_entries_traffic_v2)
      utarray_free(current->callbacks->matching_entries_traffic_v2);
    if (current->callbacks->matching_entries_traffic_v1)
      utarray_free(current->callbacks->matching_entries_traffic_v1);
    if (current->callbacks->matching_entries_traffic_2d)
      utarray_free(current->callbacks->matching_entries_traffic_2d);
    if (current->callbacks->matching_entries_traffic_2d_v1)
      utarray_free(current->callbacks->matching_entries_traffic_2d_v1);
    if (current->callbacks->matching_entries_traffic_3d)
      utarray_free(current->callbacks->matching_entries_traffic_3d);
    if (current->callbacks->matching_entries_traffic_3d_v1)
      utarray_free(current->callbacks->matching_entries_traffic_3d_v1);
    if (current->callbacks->matching_entries_traffic_3d_peer)
      utarray_free(current->callbacks->matching_entries_traffic_3d_peer);
    if (current->callbacks->matching_exits_traffic)
      utarray_free(current->callbacks->matching_exits_traffic);
    if (current->callbacks->matching_ctx_create_entry)
      utarray_free(current->callbacks->matching_ctx_create_entry);
    if (current->callbacks->matching_ctx_create_exit)
      utarray_free(current->callbacks->matching_ctx_create_exit);
    if (current->callbacks->matching_ctx_destroy_entry)
      utarray_free(current->callbacks->matching_ctx_destroy_entry);
    if (current->callbacks->matching_ctx_destroy_exit)
      utarray_free(current->callbacks->matching_ctx_destroy_exit);
    if (current->callbacks->matching_ctx_set_current_entry)
      utarray_free(current->callbacks->matching_ctx_set_current_entry);
    if (current->callbacks->matching_ctx_set_current_exit)
      utarray_free(current->callbacks->matching_ctx_set_current_exit);
    if (current->callbacks->matching_ctx_push_current_entry)
      utarray_free(current->callbacks->matching_ctx_push_current_entry);
    if (current->callbacks->matching_ctx_push_current_exit)
      utarray_free(current->callbacks->matching_ctx_push_current_exit);
    if (current->callbacks->matching_ctx_pop_current_entry)
      utarray_free(current->callbacks->matching_ctx_pop_current_entry);
    if (current->callbacks->matching_ctx_pop_current_exit)
      utarray_free(current->callbacks->matching_ctx_pop_current_exit);
    if (current->callbacks->matching_primary_ctx_retain_entry)
      utarray_free(current->callbacks->matching_primary_ctx_retain_entry);
    if (current->callbacks->matching_primary_ctx_retain_exit)
      utarray_free(current->callbacks->matching_primary_ctx_retain_exit);
    if (current->callbacks->matching_stream_create_exit)
      utarray_free(current->callbacks->matching_stream_create_exit);
    if (current->callbacks->matching_module_get_function_entry)
      utarray_free(current->callbacks->matching_module_get_function_entry);
    if (current->callbacks->matching_module_get_function_exit)
      utarray_free(current->callbacks->matching_module_get_function_exit);
    if (current->callbacks->matching_kernel_task_stream_present_entry)
      utarray_free(current->callbacks->matching_kernel_task_stream_present_entry);
    if (current->callbacks->matching_kernel_task_stream_absent_entry)
      utarray_free(current->callbacks->matching_kernel_task_stream_absent_entry);
    if (current->callbacks->matching_non_kernel_task_stream_present_entry)
      utarray_free(current->callbacks->matching_non_kernel_task_stream_present_entry);
    if (current->callbacks->matching_non_kernel_task_stream_absent_entry)
      utarray_free(current->callbacks->matching_non_kernel_task_stream_absent_entry);
    free(current->callbacks);
    free(current);
  }
}
