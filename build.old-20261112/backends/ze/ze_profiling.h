
#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER lttng_ust_ze_profiling

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "./ze_profiling.h"

#if !defined(ZE_PROFILING_H) || defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define ZE_PROFILING_H

#include <lttng/tracepoint.h>

#include "lttng/tracepoint_gen.h"
#include "ze.h.include"

TRACEPOINT_EVENT(
  lttng_ust_ze_profiling,
  event_profiling,
  TP_ARGS(
    ze_event_handle_t, hEvent
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hEvent, (uintptr_t)hEvent)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_profiling,
  event_profiling_results,
  TP_ARGS(
    ze_event_handle_t, hEvent,
    ze_result_t, status,
    ze_result_t, timestampStatus,
    uint64_t, globalStart,
    uint64_t, globalEnd,
    uint64_t, contextStart,
    uint64_t, contextEnd
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hEvent, (uintptr_t)hEvent)
    ctf_integer(ze_result_t, status, status)
    ctf_integer(ze_result_t, timestampStatus, timestampStatus)
    ctf_integer(uint64_t, globalStart, globalStart)
    ctf_integer(uint64_t, globalEnd, globalEnd)
    ctf_integer(uint64_t, contextStart, contextStart)
    ctf_integer(uint64_t, contextEnd, contextEnd)
  )
)


#endif /* ZE_PROFILING_H */

#include <lttng/tracepoint-event.h>
