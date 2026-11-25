
#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER lttng_ust_mpi_type

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "./mpi_type.h"

#if !defined(MPI_TYPE_H) || defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define MPI_TYPE_H

#include <lttng/tracepoint.h>

#include "lttng/tracepoint_gen.h"
#include "mpi.h.include"

TRACEPOINT_EVENT(
  lttng_ust_mpi_type,
  property,
  TP_ARGS(
    MPI_Datatype, datatype,
    int, size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, datatype, (uintptr_t)datatype)
    ctf_integer(int, size, size)
  )
)


#endif /* MPI_TYPE_H */

#include <lttng/tracepoint-event.h>
