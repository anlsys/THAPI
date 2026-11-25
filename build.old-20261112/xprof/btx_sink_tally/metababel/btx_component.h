#pragma once

#include "utarray.h"
#include "uthash.h"
#include <babeltrace2/babeltrace.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// Forward declaration of common_data
struct common_data_s;
typedef struct common_data_s common_data_t;

// Params
// Avoid icx error: empty struct has size 0 in C, size 1 in C++
// [-Werror,-Wextern-c-compat]
struct btx_params_s {
    const char* display;
  const char* name;
  const char* display_mode;
  bt_bool display_metadata;
  int64_t display_name_max_size;
  bt_bool display_kernel_verbose;
  const char* backend_levels;

}; 
typedef struct btx_params_s btx_params_t;

void btx_populate_params(common_data_t *common_data_t);

struct callbacks_s {
  UT_array *automatic;
};
typedef struct callbacks_s callbacks_t;

struct static_callbacks_s;
typedef struct static_callbacks_s static_callbacks_t;

struct name_to_dispatcher_s {
  const char *name;
  void *dispatcher;
  callbacks_t *callbacks;
  UT_hash_handle hh;
};
typedef struct name_to_dispatcher_s name_to_dispatcher_t;

// Struct stored in the component via `bt_self_component_set_data`
struct common_data_s {
  name_to_dispatcher_t *name_to_dispatcher;
  static_callbacks_t *static_callbacks;

  void *usr_data;
  const bt_value *params;
  btx_params_t *btx_params;
  /* Upstream message iterator (owned by this) */
  bt_message_iterator *message_iterator;
};

void btx_register_usr_callbacks(void *btx_handle);
void btx_unregister_callbacks(common_data_t *common_data);

typedef void initialize_component_static_callback_f(
        void **);

void btx_register_callbacks_initialize_component(
    void *btx_handle, initialize_component_static_callback_f *callback);

void btx_call_callbacks_initialize_component(
    common_data_t *common_data, void **);
typedef void finalize_component_static_callback_f(
        void *);

void btx_register_callbacks_finalize_component(
    void *btx_handle, finalize_component_static_callback_f *callback);

void btx_call_callbacks_finalize_component(
    common_data_t *common_data, void *);
typedef void read_params_static_callback_f(
        void *, btx_params_t *);

void btx_register_callbacks_read_params(
    void *btx_handle, read_params_static_callback_f *callback);

void btx_call_callbacks_read_params(
    common_data_t *common_data, void *, btx_params_t *);

struct static_callbacks_s {
  initialize_component_static_callback_f *initialize_component;
  finalize_component_static_callback_f *finalize_component;
  read_params_static_callback_f *read_params;
};

#ifdef __cplusplus
}
#endif
