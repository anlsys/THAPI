
#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER lttng_ust_opencl_source

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "./opencl_source.h"

#if !defined(OPENCL_SOURCE_H) || defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define OPENCL_SOURCE_H

#include <lttng/tracepoint.h>

#include "lttng/tracepoint_gen.h"
#include "cl.h.include"

TRACEPOINT_EVENT(
  lttng_ust_opencl_source,
  program_string,
  TP_ARGS(
    int, index,
    size_t, length,
    char *, path
  ),
  TP_FIELDS(
    ctf_integer(int, index, index)
    ctf_integer(size_t, length, length)
    ctf_string(path, path)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl_source,
  program_binary,
  TP_ARGS(
    int, index,
    size_t, length,
    char *, path
  ),
  TP_FIELDS(
    ctf_integer(int, index, index)
    ctf_integer(size_t, length, length)
    ctf_string(path, path)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl_source,
  program_il,
  TP_ARGS(
    size_t, length,
    char *, path
  ),
  TP_FIELDS(
    ctf_integer(size_t, length, length)
    ctf_string(path, path)
  )
)


#endif /* OPENCL_SOURCE_H */

#include <lttng/tracepoint-event.h>
