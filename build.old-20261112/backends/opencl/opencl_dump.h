
#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER lttng_ust_opencl_dump

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "./opencl_dump.h"

#if !defined(OPENCL_DUMP_H) || defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define OPENCL_DUMP_H

#include <lttng/tracepoint.h>

#include "lttng/tracepoint_gen.h"
#include "cl.h.include"

TRACEPOINT_ENUM(
  lttng_ust_opencl_dump,
  dump_enum,
  TP_ENUM_VALUES(
    ctf_enum_value("BEFORE", 0)
    ctf_enum_value("AFTER", 1)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl_dump,
  enqueue_counter,
  TP_ARGS(
    uint64_t, enqueue_counter
  ),
  TP_FIELDS(
    ctf_integer(uint64_t, enqueue_counter, enqueue_counter)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl_dump,
  kernel_arg_value,
  TP_ARGS(
    uint64_t, enqueue_counter,
    cl_uint, arg_index,
    size_t, arg_size,
    void *, arg_value
  ),
  TP_FIELDS(
    ctf_integer(uint64_t, enqueue_counter, enqueue_counter)
    ctf_integer(cl_uint, arg_index, arg_index)
    ctf_integer(size_t, arg_size, arg_size)
    ctf_sequence_text(uint8_t, arg_value, arg_value, size_t, arg_value == NULL ? 0 : arg_size)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl_dump,
  svmptr_dump_event,
  TP_ARGS(
    uint64_t, enqueue_counter,
    cl_uint, arg_index,
    int, direction,
    void *, buffer,
    int, status,
    cl_event, event
  ),
  TP_FIELDS(
    ctf_integer(uint64_t, enqueue_counter, enqueue_counter)
    ctf_integer(cl_uint, arg_index, arg_index)
    ctf_enum(lttng_ust_opencl_dump, dump_enum, int, direction, direction)
    ctf_integer_hex(uintptr_t, buffer, (uintptr_t)buffer)
    ctf_integer(int, status, status)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl_dump,
  svmptr_dump_result,
  TP_ARGS(
    uint64_t, enqueue_counter,
    cl_uint, arg_index,
    int, direction,
    cl_event, event,
    cl_int, status,
    size_t, size,
    char *, path
  ),
  TP_FIELDS(
    ctf_integer(uint64_t, enqueue_counter, enqueue_counter)
    ctf_integer(cl_uint, arg_index, arg_index)
    ctf_enum(lttng_ust_opencl_dump, dump_enum, int, direction, direction)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_integer(int, status, status)
    ctf_integer(size_t, size, size)
    ctf_string(path, path)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl_dump,
  buffer_dump_event,
  TP_ARGS(
    uint64_t, enqueue_counter,
    cl_uint, arg_index,
    int, direction,
    cl_mem, buffer,
    int, status,
    cl_event, event
  ),
  TP_FIELDS(
    ctf_integer(uint64_t, enqueue_counter, enqueue_counter)
    ctf_integer(cl_uint, arg_index, arg_index)
    ctf_enum(lttng_ust_opencl_dump, dump_enum, int, direction, direction)
    ctf_integer_hex(uintptr_t, buffer, (uintptr_t)buffer)
    ctf_integer(int, status, status)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl_dump,
  buffer_dump_result,
  TP_ARGS(
    uint64_t, enqueue_counter,
    cl_uint, arg_index,
    int, direction,
    cl_event, event,
    cl_int, status,
    size_t, size,
    char *, path
  ),
  TP_FIELDS(
    ctf_integer(uint64_t, enqueue_counter, enqueue_counter)
    ctf_integer(cl_uint, arg_index, arg_index)
    ctf_enum(lttng_ust_opencl_dump, dump_enum, int, direction, direction)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_integer(int, status, status)
    ctf_integer(size_t, size, size)
    ctf_string(path, path)
  )
)


#endif /* OPENCL_DUMP_H */

#include <lttng/tracepoint-event.h>
