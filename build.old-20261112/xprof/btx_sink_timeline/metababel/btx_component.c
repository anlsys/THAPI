#include <babeltrace2/babeltrace.h>
#include <metababel/btx_component.h>
// stdio needed because `params_definition` contain fprintf
#include <stdio.h>

void btx_populate_params(common_data_t *common_data) {
  const bt_value *_params = common_data->params;
  btx_params_t *_usr_params = common_data->btx_params;
    {
    const bt_value *val = bt_value_map_borrow_entry_value_const(_params, "output_path");
    if (val != NULL) {
      if (bt_value_is_string(val) != BT_TRUE) {
        fprintf(stderr,"Bad value for command line argument '%s' the value must be '%s'. \n","output_path","string");
        exit(1);
      }
      _usr_params->output_path = bt_value_string_get(val);
    } else {
      _usr_params->output_path = "";
    }
  }
  {
    const bt_value *val = bt_value_map_borrow_entry_value_const(_params, "offset");
    if (val != NULL) {
      _usr_params->offset = bt_value_integer_unsigned_get(val);
    } else {
      _usr_params->offset = 0;
    }
  }

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
