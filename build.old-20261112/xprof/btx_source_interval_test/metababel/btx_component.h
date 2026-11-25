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
  char _dummy;

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

// Structure for Downstream Message
struct el {
  const bt_message *message;
  struct el *next, *prev;
};

// Struct stored in the component via `bt_self_component_set_data`
struct common_data_s {
  name_to_dispatcher_t *name_to_dispatcher;
  static_callbacks_t *static_callbacks;
  void *usr_data;
  const bt_value *params;
  btx_params_t *btx_params;
  bt_trace *downstream_trace;
  /* Used by downstream.c */
  bt_self_message_iterator *self_message_iterator;
};

enum btx_source_state_e {
  BTX_SOURCE_STATE_INITIALIZING,
  BTX_SOURCE_STATE_PROCESSING,
  BTX_SOURCE_STATE_FINALIZING,
  BTX_SOURCE_STATE_FINISHED,
  BTX_SOURCE_STATE_ERROR,
};
typedef enum btx_source_state_e btx_source_state_t;

/* Message iterator's private data */
struct btx_message_iterator_s {
  /* (Weak) link to the component's private data */
  common_data_t *common_data;
  btx_source_state_t state;

  /* Handling the downstream message queue */
  struct el *queue;
  struct el *pool;
};
typedef struct btx_message_iterator_s btx_message_iterator_t;

enum btx_source_status_e {
  BTX_SOURCE_END,
  BTX_SOURCE_OK,
};
typedef enum btx_source_status_e btx_source_status_t;


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
typedef void initialize_processing_static_callback_f(
    void *btx_handle,
        void *);

void btx_register_callbacks_initialize_processing(
    void *btx_handle, initialize_processing_static_callback_f *callback);

void btx_call_callbacks_initialize_processing(
    common_data_t *common_data, void *);
typedef void finalize_processing_static_callback_f(
    void *btx_handle,
        void *);

void btx_register_callbacks_finalize_processing(
    void *btx_handle, finalize_processing_static_callback_f *callback);

void btx_call_callbacks_finalize_processing(
    common_data_t *common_data, void *);
typedef void push_usr_messages_static_callback_f(
    void *btx_handle,
        void *, btx_source_status_t*);

void btx_register_callbacks_push_usr_messages(
    void *btx_handle, push_usr_messages_static_callback_f *callback);

void btx_call_callbacks_push_usr_messages(
    common_data_t *common_data, void *, btx_source_status_t*);

struct static_callbacks_s {
  initialize_component_static_callback_f *initialize_component;
  finalize_component_static_callback_f *finalize_component;
  read_params_static_callback_f *read_params;
  initialize_processing_static_callback_f *initialize_processing;
  finalize_processing_static_callback_f *finalize_processing;
  push_usr_messages_static_callback_f *push_usr_messages;
};

#ifdef __cplusplus
}
#endif
