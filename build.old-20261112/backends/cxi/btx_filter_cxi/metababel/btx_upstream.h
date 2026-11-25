#pragma once
#include <metababel/btx_component.h>
#ifdef __cplusplus
extern "C" {
#endif

// Dispatcher
typedef void(dispatcher_t)(callbacks_t *callbacks, common_data_t *common_data,
                           const bt_message *upstream_message);

typedef void lttng_ust_cxi_sampling_cxi_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, char *, uint64_t);

void btx_register_callbacks_lttng_ust_cxi_sampling_cxi(
    void *btx_handle, lttng_ust_cxi_sampling_cxi_callback_f *callback);

void btx_unregister_callbacks(common_data_t *common_data);

#ifdef __cplusplus
}
#endif
