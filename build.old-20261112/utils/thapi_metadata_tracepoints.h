
#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER lttng_ust_thapi

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "./thapi_metadata_tracepoints.h"

#if !defined(THAPI_METADATA_TRACEPOINTS_H) || defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define THAPI_METADATA_TRACEPOINTS_H

#include <lttng/tracepoint.h>

TRACEPOINT_EVENT(
  lttng_ust_thapi,
  metadata,
  TP_ARGS(
    char *, value
  ),
  TP_FIELDS(
    ctf_string(value, value)
  )
)

#endif /* THAPI_METADATA_TRACEPOINTS_H */

#include <lttng/tracepoint-event.h>
