#pragma once
#include <metababel/btx_component.h>
#ifdef __cplusplus
extern "C" {
#endif

// Dispatcher
typedef void(dispatcher_t)(callbacks_t *callbacks, common_data_t *common_data,
                           const bt_message *upstream_message);

void btx_unregister_callbacks(common_data_t *common_data);

#ifdef __cplusplus
}
#endif
