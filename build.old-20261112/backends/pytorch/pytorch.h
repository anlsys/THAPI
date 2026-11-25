
#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER lttng_ust_pytorch

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "./pytorch.h"

#if !defined(PYTORCH_H) || defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define PYTORCH_H

#include <lttng/tracepoint.h>

#include "lttng/tracepoint_gen.h"

TRACEPOINT_EVENT(
  lttng_ust_pytorch,
  op_entry,
  TP_ARGS(
    const char *, name
  ),
  TP_FIELDS(
    ctf_string(name, name)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_pytorch,
  op_exit,
  TP_ARGS(
    const char *, name
  ),
  TP_FIELDS(
    ctf_string(name, name)
  )
)


#endif /* PYTORCH_H */

#include <lttng/tracepoint-event.h>
