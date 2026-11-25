
#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER lttng_ust_itt_metadata

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "./itt_metadata.h"

#if !defined(ITT_METADATA_H) || defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define ITT_METADATA_H

#include <lttng/tracepoint.h>

#include "lttng/tracepoint_gen.h"
#include "ittnotify.h"

TRACEPOINT_EVENT(
  lttng_ust_itt_metadata,
  metadata,
  TP_ARGS(
    __itt_metadata_type, type,
    size_t, count,
    uint64_t, size,
    void*, data
  ),
  TP_FIELDS(
    ctf_integer(int32_t, type, type)
    ctf_integer(size_t, count, count)
    ctf_integer_hex(uintptr_t, data, (uintptr_t)data)
    ctf_sequence_text(char, data_val, (const char*)data, size_t, size)
  )
)


#endif /* ITT_METADATA_H */

#include <lttng/tracepoint-event.h>
