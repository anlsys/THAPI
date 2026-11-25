
#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER lttng_ust_tracegrind

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "./tracegrind_tracepoints.h"

#if !defined(TRACEGRIND_TRACEPOINTS_H) || defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define TRACEGRIND_TRACEPOINTS_H

#include <lttng/tracepoint.h>

#include "lttng/tracepoint_gen.h"

TRACEPOINT_EVENT(
  lttng_ust_tracegrind,
  mem_accesses,
  TP_ARGS(
    unsigned long, seq,
    unsigned long, user_ctx,
    unsigned int, chunk,
    unsigned int, n_loads,
    unsigned long *, loads,
    unsigned int, n_stores,
    unsigned long *, stores
  ),
  TP_FIELDS(
    ctf_integer(unsigned long, seq, seq)
    ctf_integer_hex(unsigned long, user_ctx, user_ctx)
    ctf_integer(unsigned int, chunk, chunk)
    ctf_integer(unsigned int, n_loads, n_loads)
    ctf_sequence_hex(unsigned long, loads, loads, unsigned int, n_loads * 2)
    ctf_integer(unsigned int, n_stores, n_stores)
    ctf_sequence_hex(unsigned long, stores, stores, unsigned int, n_stores * 2)
  )
)


#endif /* TRACEGRIND_TRACEPOINTS_H */

#include <lttng/tracepoint-event.h>
