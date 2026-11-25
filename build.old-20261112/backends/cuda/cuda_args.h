
#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER lttng_ust_cuda_args

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "./cuda_args.h"

#if !defined(CUDA_ARGS_H) || defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define CUDA_ARGS_H

#include <lttng/tracepoint.h>

#include "lttng/tracepoint_gen.h"
#include <cuda.h>

TRACEPOINT_EVENT(
  lttng_ust_cuda_args,
  arg_count,
  TP_ARGS(
    CUfunction, f,
    size_t, argCount
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, f, (uintptr_t)f)
    ctf_integer(size_t, argCount, argCount)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_cuda_args,
  arg_value,
  TP_ARGS(
    CUfunction, f,
    size_t, argIndex,
    void *, kernelParam,
    size_t, argSize
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, f, (uintptr_t)f)
    ctf_integer(size_t, argIndex, argIndex)
    ctf_integer_hex(uintptr_t, kernelParam, (uintptr_t)kernelParam)
    ctf_sequence_text(uint8_t, kernelParam_val, (uint8_t *)kernelParam, size_t, kernelParam ? argSize : 0)
  )
)


#endif /* CUDA_ARGS_H */

#include <lttng/tracepoint-event.h>
