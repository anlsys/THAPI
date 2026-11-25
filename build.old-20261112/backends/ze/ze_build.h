
#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER lttng_ust_ze_build

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "./ze_build.h"

#if !defined(ZE_BUILD_H) || defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define ZE_BUILD_H

#include <lttng/tracepoint.h>

#include "lttng/tracepoint_gen.h"
#include "ze.h.include"

TRACEPOINT_EVENT(
  lttng_ust_ze_build,
  log,
  TP_ARGS(
    const char *, buildLog
  ),
  TP_FIELDS(
    ctf_string(buildLog, buildLog)
  )
)


#endif /* ZE_BUILD_H */

#include <lttng/tracepoint-event.h>
