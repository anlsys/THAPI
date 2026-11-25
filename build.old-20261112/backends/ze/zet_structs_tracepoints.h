
#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER lttng_ust_zet_structs

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "./zet_structs_tracepoints.h"

#if !defined(ZET_STRUCTS_TRACEPOINTS_H) || defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define ZET_STRUCTS_TRACEPOINTS_H

#include <lttng/tracepoint.h>

#include "lttng/tracepoint_gen.h"
#include "ze.h.include"
TRACEPOINT_EVENT(
  lttng_ust_zet_structs,
  zet_device_debug_properties_t,
  TP_ARGS(
    zet_device_debug_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(zet_device_debug_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zet_structs,
  zet_debug_memory_space_desc_t,
  TP_ARGS(
    zet_debug_memory_space_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(zet_debug_memory_space_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zet_structs,
  zet_debug_regset_properties_t,
  TP_ARGS(
    zet_debug_regset_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(zet_debug_regset_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zet_structs,
  zet_metric_group_properties_t,
  TP_ARGS(
    zet_metric_group_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(zet_metric_group_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zet_structs,
  zet_metric_properties_t,
  TP_ARGS(
    zet_metric_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(zet_metric_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zet_structs,
  zet_metric_streamer_desc_t,
  TP_ARGS(
    zet_metric_streamer_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(zet_metric_streamer_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zet_structs,
  zet_metric_query_pool_desc_t,
  TP_ARGS(
    zet_metric_query_pool_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(zet_metric_query_pool_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zet_structs,
  zet_profile_properties_t,
  TP_ARGS(
    zet_profile_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(zet_profile_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zet_structs,
  zet_tracer_exp_desc_t,
  TP_ARGS(
    zet_tracer_exp_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(zet_tracer_exp_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zet_structs,
  zet_metric_tracer_exp_desc_t,
  TP_ARGS(
    zet_metric_tracer_exp_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(zet_metric_tracer_exp_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zet_structs,
  zet_metric_group_type_exp_t,
  TP_ARGS(
    zet_metric_group_type_exp_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(zet_metric_group_type_exp_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zet_structs,
  zet_export_dma_buf_exp_properties_t,
  TP_ARGS(
    zet_export_dma_buf_exp_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(zet_export_dma_buf_exp_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zet_structs,
  zet_metric_global_timestamps_resolution_exp_t,
  TP_ARGS(
    zet_metric_global_timestamps_resolution_exp_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(zet_metric_global_timestamps_resolution_exp_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zet_structs,
  zet_metric_calculate_exp_desc_t,
  TP_ARGS(
    zet_metric_calculate_exp_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(zet_metric_calculate_exp_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zet_structs,
  zet_metric_programmable_exp_properties_t,
  TP_ARGS(
    zet_metric_programmable_exp_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(zet_metric_programmable_exp_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zet_structs,
  zet_metric_programmable_param_info_exp_t,
  TP_ARGS(
    zet_metric_programmable_param_info_exp_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(zet_metric_programmable_param_info_exp_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zet_structs,
  zet_metric_programmable_param_value_info_exp_t,
  TP_ARGS(
    zet_metric_programmable_param_value_info_exp_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(zet_metric_programmable_param_value_info_exp_t) : 0))
  )
)


#endif /* ZET_STRUCTS_TRACEPOINTS_H */

#include <lttng/tracepoint-event.h>
