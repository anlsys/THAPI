
#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER lttng_ust_cxi_sampling

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "./cxi_sampling.h"

#if !defined(CXI_SAMPLING_H) || defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define CXI_SAMPLING_H

#include <lttng/tracepoint.h>

#include "lttng/tracepoint_gen.h"

TRACEPOINT_EVENT(
  lttng_ust_cxi_sampling,
  cxi,
  TP_ARGS(
    const char *, interface_name,
    const char *, counter,
    uint64_t, value
  ),
  TP_FIELDS(
    ctf_string(interface_name, interface_name)
    ctf_string(counter, counter)
    ctf_integer(uint64_t, value, value)
  )
)


#endif /* CXI_SAMPLING_H */

#include <lttng/tracepoint-event.h>
