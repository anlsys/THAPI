
#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER lttng_ust_cuda_profiling

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "./cuda_profiling.h"

#if !defined(CUDA_PROFILING_H) || defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define CUDA_PROFILING_H

#include <lttng/tracepoint.h>

#include "lttng/tracepoint_gen.h"
#include <cuda.h>

TRACEPOINT_EVENT(
  lttng_ust_cuda_profiling,
  event_profiling,
  TP_ARGS(
    CUevent, hStart,
    CUevent, hStop
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStart, (uintptr_t)hStart)
    ctf_integer_hex(uintptr_t, hStop, (uintptr_t)hStop)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda_profiling,
  event_profiling_results,
  TP_ARGS(
    CUevent, hStart,
    CUevent, hStop,
    CUresult, startStatus,
    CUresult, stopStatus,
    CUresult, status,
    float, milliseconds
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStart, (uintptr_t)hStart)
    ctf_integer_hex(uintptr_t, hStop, (uintptr_t)hStop)
    ctf_integer(CUresult, startStatus, startStatus)
    ctf_integer(CUresult, stopStatus, stopStatus)
    ctf_integer(CUresult, status, status)
    ctf_float(float, milliseconds, milliseconds)
  )
)


#endif /* CUDA_PROFILING_H */

#include <lttng/tracepoint-event.h>
