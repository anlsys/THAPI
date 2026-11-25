
#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER lttng_ust_opencl_devices

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "./opencl_devices.h"

#if !defined(OPENCL_DEVICES_H) || defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define OPENCL_DEVICES_H

#include <lttng/tracepoint.h>

#include "lttng/tracepoint_gen.h"
#include "cl.h.include"

TRACEPOINT_EVENT(
  lttng_ust_opencl_devices,
  device_name,
  TP_ARGS(
    cl_device_id, device,
    char *, name
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, device, (uintptr_t)device)
    ctf_string(name, name)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl_devices,
  device_timer,
  TP_ARGS(
    cl_device_id, device,
    cl_ulong, device_timestamp,
    cl_ulong, host_timestamp
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, device, (uintptr_t)device)
    ctf_integer(cl_ulong, device_timestamp, device_timestamp)
    ctf_integer(cl_ulong, host_timestamp, host_timestamp)
  )
)


#endif /* OPENCL_DEVICES_H */

#include <lttng/tracepoint-event.h>
