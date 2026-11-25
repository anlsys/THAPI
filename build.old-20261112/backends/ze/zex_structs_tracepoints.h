
#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER 

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "./zex_structs_tracepoints.h"

#if !defined(ZEX_STRUCTS_TRACEPOINTS_H) || defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define ZEX_STRUCTS_TRACEPOINTS_H

#include <lttng/tracepoint.h>

#include "lttng/tracepoint_gen.h"
#include "ze.h.include"

#endif /* ZEX_STRUCTS_TRACEPOINTS_H */

#include <lttng/tracepoint-event.h>
