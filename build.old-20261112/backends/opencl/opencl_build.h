
#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER lttng_ust_opencl_build

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "./opencl_build.h"

#if !defined(OPENCL_BUILD_H) || defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define OPENCL_BUILD_H

#include <lttng/tracepoint.h>

#include "lttng/tracepoint_gen.h"
#include "cl.h.include"

TRACEPOINT_EVENT(
  lttng_ust_opencl_build,
  objects,
  TP_ARGS(
    cl_program, program,
    cl_device_id, device,
    size_t, size,
    char *, path
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, program, (uintptr_t)program)
    ctf_integer_hex(uintptr_t, device, (uintptr_t)device)
    ctf_integer(size_t, size, size)
    ctf_string(path, path)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl_build,
  binaries,
  TP_ARGS(
    cl_program, program,
    cl_device_id, device,
    size_t, size,
    char *, path
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, program, (uintptr_t)program)
    ctf_integer_hex(uintptr_t, device, (uintptr_t)device)
    ctf_integer(size_t, size, size)
    ctf_string(path, path)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl_build,
  infos,
  TP_ARGS(
    cl_program, program,
    cl_device_id, device,
    cl_build_status, build_status,
    char *, build_options,
    char *, build_log
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, program, (uintptr_t)program)
    ctf_integer_hex(uintptr_t, device, (uintptr_t)device)
    ctf_integer(cl_build_status, build_status, build_status)
    ctf_string(build_options, build_options)
    ctf_string(build_log, build_log)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl_build,
  infos_1_2,
  TP_ARGS(
    cl_program, program,
    cl_device_id, device,
    cl_program_binary_type, binary_type
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, program, (uintptr_t)program)
    ctf_integer_hex(uintptr_t, device, (uintptr_t)device)
    ctf_integer(cl_program_binary_type, binary_type, binary_type)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl_build,
  infos_2_0,
  TP_ARGS(
    cl_program, program,
    cl_device_id, device,
    size_t, build_global_variable_total_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, program, (uintptr_t)program)
    ctf_integer_hex(uintptr_t, device, (uintptr_t)device)
    ctf_integer(size_t, build_global_variable_total_size, build_global_variable_total_size)
  )
)


#endif /* OPENCL_BUILD_H */

#include <lttng/tracepoint-event.h>
