
#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER lttng_ust_cuda_properties

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "./cuda_properties.h"

#if !defined(CUDA_PROPERTIES_H) || defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define CUDA_PROPERTIES_H

#include <lttng/tracepoint.h>

#include "lttng/tracepoint_gen.h"
#include <cuda.h>

TRACEPOINT_EVENT(
  lttng_ust_cuda_properties,
  device,
  TP_ARGS(
    int, ordinal,
    CUdevice, device,
    char *, name,
    CUuuid *, uuid
  ),
  TP_FIELDS(
    ctf_integer(int, ordinal, ordinal)
    ctf_integer_hex(int, device, device)
    ctf_string(name, name)
    ctf_sequence_text(uint8_t, uuid, uuid, size_t, sizeof(CUuuid))
  )
)


#endif /* CUDA_PROPERTIES_H */

#include <lttng/tracepoint-event.h>
