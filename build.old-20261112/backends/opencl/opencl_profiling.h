
#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER lttng_ust_opencl_profiling

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "./opencl_profiling.h"

#if !defined(OPENCL_PROFILING_H) || defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define OPENCL_PROFILING_H

#include <lttng/tracepoint.h>

#include "lttng/tracepoint_gen.h"
#include "cl.h.include"

TRACEPOINT_EVENT(
  lttng_ust_opencl_profiling,
  event_profiling,
  TP_ARGS(
    int, status,
    cl_event, event
  ),
  TP_FIELDS(
    ctf_integer(int, status, status)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl_profiling,
  event_profiling_results,
  TP_ARGS(
    cl_event, event,
    cl_int, event_command_exec_status,
    cl_int, queued_status,
    cl_ulong, queued,
    cl_int, submit_status,
    cl_ulong, submit,
    cl_int, start_status,
    cl_ulong, start,
    cl_int, end_status,
    cl_ulong, end
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_integer(int, event_command_exec_status, event_command_exec_status)
    ctf_integer(cl_int, queued_status, queued_status)
    ctf_integer(cl_ulong, queued, queued)
    ctf_integer(cl_int, submit_status, submit_status)
    ctf_integer(cl_ulong, submit, submit)
    ctf_integer(cl_int, start_status, start_status)
    ctf_integer(cl_ulong, start, start)
    ctf_integer(cl_int, end_status, end_status)
    ctf_integer(cl_ulong, end, end)
  )
)


#endif /* OPENCL_PROFILING_H */

#include <lttng/tracepoint-event.h>
