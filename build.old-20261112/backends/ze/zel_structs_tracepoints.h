
#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER lttng_ust_zel_structs

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "./zel_structs_tracepoints.h"

#if !defined(ZEL_STRUCTS_TRACEPOINTS_H) || defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define ZEL_STRUCTS_TRACEPOINTS_H

#include <lttng/tracepoint.h>

#include "lttng/tracepoint_gen.h"
#include "ze.h.include"
TRACEPOINT_EVENT(
  lttng_ust_zel_structs,
  zel_tracer_desc_t,
  TP_ARGS(
    zel_tracer_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(zel_tracer_desc_t) : 0))
  )
)


#endif /* ZEL_STRUCTS_TRACEPOINTS_H */

#include <lttng/tracepoint-event.h>
