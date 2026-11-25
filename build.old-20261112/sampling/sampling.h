
#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER lttng_ust_sampling

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "./sampling.h"

#if !defined(SAMPLING_H) || defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define SAMPLING_H

#include <lttng/tracepoint.h>

#include "lttng/tracepoint_gen.h"

TRACEPOINT_EVENT(
  lttng_ust_sampling,
  heartbeat,
  TP_ARGS(
    uint64_t, foo
  ),
  TP_FIELDS(
    ctf_integer(uint64_t, foo, foo)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_sampling,
  heartbeat2,
  TP_ARGS(
    void
  ),
  TP_FIELDS(
  )
)


#endif /* SAMPLING_H */

#include <lttng/tracepoint-event.h>
