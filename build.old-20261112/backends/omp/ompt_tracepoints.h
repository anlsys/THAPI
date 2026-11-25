
#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER lttng_ust_ompt

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "./ompt_tracepoints.h"

#if !defined(OMPT_TRACEPOINTS_H) || defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define OMPT_TRACEPOINTS_H

#include <lttng/tracepoint.h>

#include "lttng/tracepoint_gen.h"
#include <ompt.h.include>
TRACEPOINT_EVENT(
  lttng_ust_ompt,
  ompt_callback_thread_begin,
  TP_ARGS(
    ompt_thread_t, thread_type,
    ompt_data_t *, thread_data
  ),
  TP_FIELDS(
    ctf_integer(int32_t, thread_type, thread_type)
    ctf_integer_hex(uintptr_t, thread_data, (uintptr_t)(thread_data))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ompt,
  ompt_callback_thread_end,
  TP_ARGS(
    ompt_data_t *, thread_data
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, thread_data, (uintptr_t)(thread_data))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ompt,
  ompt_callback_parallel_begin,
  TP_ARGS(
    ompt_data_t *, encountering_task_data,
    const ompt_frame_t *, encountering_task_frame,
    ompt_data_t *, parallel_data,
    unsigned int, requested_parallelism,
    ompt_parallel_flags_t, flags,
    const void *, codeptr_ra
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, encountering_task_data, (uintptr_t)(encountering_task_data))
    ctf_integer_hex(uintptr_t, encountering_task_frame, (uintptr_t)(encountering_task_frame))
    ctf_integer_hex(uintptr_t, parallel_data, (uintptr_t)(parallel_data))
    ctf_integer(unsigned int, requested_parallelism, requested_parallelism)
    ctf_integer(ompt_parallel_flags_t, flags, flags)
    ctf_integer_hex(uintptr_t, codeptr_ra, (uintptr_t)(codeptr_ra))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ompt,
  ompt_callback_parallel_end,
  TP_ARGS(
    ompt_data_t *, parallel_data,
    ompt_data_t *, encountering_task_data,
    ompt_parallel_flags_t, flags,
    const void *, codeptr_ra
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, parallel_data, (uintptr_t)(parallel_data))
    ctf_integer_hex(uintptr_t, encountering_task_data, (uintptr_t)(encountering_task_data))
    ctf_integer(ompt_parallel_flags_t, flags, flags)
    ctf_integer_hex(uintptr_t, codeptr_ra, (uintptr_t)(codeptr_ra))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ompt,
  ompt_callback_work,
  TP_ARGS(
    ompt_work_t, work_type,
    ompt_scope_endpoint_t, endpoint,
    ompt_data_t *, parallel_data,
    ompt_data_t *, task_data,
    uint64_t, count,
    const void *, codeptr_ra
  ),
  TP_FIELDS(
    ctf_integer(int32_t, work_type, work_type)
    ctf_integer(int32_t, endpoint, endpoint)
    ctf_integer_hex(uintptr_t, parallel_data, (uintptr_t)(parallel_data))
    ctf_integer_hex(uintptr_t, task_data, (uintptr_t)(task_data))
    ctf_integer(uint64_t, count, count)
    ctf_integer_hex(uintptr_t, codeptr_ra, (uintptr_t)(codeptr_ra))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ompt,
  ompt_callback_dispatch,
  TP_ARGS(
    ompt_data_t *, parallel_data,
    ompt_data_t *, task_data,
    ompt_dispatch_t, kind,
    ompt_data_t, instance
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, parallel_data, (uintptr_t)(parallel_data))
    ctf_integer_hex(uintptr_t, task_data, (uintptr_t)(task_data))
    ctf_integer(int32_t, kind, kind)
    ctf_array_text(uint8_t, instance, &instance, sizeof(ompt_data_t))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ompt,
  ompt_callback_task_create,
  TP_ARGS(
    ompt_data_t *, encountering_task_data,
    const ompt_frame_t *, encountering_task_frame,
    ompt_data_t *, new_task_data,
    ompt_task_flags_t, flags,
    int, has_dependences,
    const void *, codeptr_ra
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, encountering_task_data, (uintptr_t)(encountering_task_data))
    ctf_integer_hex(uintptr_t, encountering_task_frame, (uintptr_t)(encountering_task_frame))
    ctf_integer_hex(uintptr_t, new_task_data, (uintptr_t)(new_task_data))
    ctf_integer(ompt_task_flags_t, flags, flags)
    ctf_integer(int, has_dependences, has_dependences)
    ctf_integer_hex(uintptr_t, codeptr_ra, (uintptr_t)(codeptr_ra))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ompt,
  ompt_callback_dependences,
  TP_ARGS(
    ompt_data_t *, task_data,
    const ompt_dependence_t *, deps,
    int, ndeps
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, task_data, (uintptr_t)(task_data))
    ctf_integer_hex(uintptr_t, deps, (uintptr_t)(deps))
    ctf_integer(int, ndeps, ndeps)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ompt,
  ompt_callback_task_dependence,
  TP_ARGS(
    ompt_data_t *, src_task_data,
    ompt_data_t *, sink_task_data
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, src_task_data, (uintptr_t)(src_task_data))
    ctf_integer_hex(uintptr_t, sink_task_data, (uintptr_t)(sink_task_data))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ompt,
  ompt_callback_task_schedule,
  TP_ARGS(
    ompt_data_t *, prior_task_data,
    ompt_task_status_t, prior_task_status,
    ompt_data_t *, next_task_data
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, prior_task_data, (uintptr_t)(prior_task_data))
    ctf_integer(int32_t, prior_task_status, prior_task_status)
    ctf_integer_hex(uintptr_t, next_task_data, (uintptr_t)(next_task_data))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ompt,
  ompt_callback_implicit_task,
  TP_ARGS(
    ompt_scope_endpoint_t, endpoint,
    ompt_data_t *, parallel_data,
    ompt_data_t *, task_data,
    unsigned int, actual_parallelism,
    unsigned int, index,
    ompt_task_flags_t, flags
  ),
  TP_FIELDS(
    ctf_integer(int32_t, endpoint, endpoint)
    ctf_integer_hex(uintptr_t, parallel_data, (uintptr_t)(parallel_data))
    ctf_integer_hex(uintptr_t, task_data, (uintptr_t)(task_data))
    ctf_integer(unsigned int, actual_parallelism, actual_parallelism)
    ctf_integer(unsigned int, index, index)
    ctf_integer(ompt_task_flags_t, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ompt,
  ompt_callback_masked,
  TP_ARGS(
    ompt_scope_endpoint_t, endpoint,
    ompt_data_t *, parallel_data,
    ompt_data_t *, task_data,
    const void *, codeptr_ra
  ),
  TP_FIELDS(
    ctf_integer(int32_t, endpoint, endpoint)
    ctf_integer_hex(uintptr_t, parallel_data, (uintptr_t)(parallel_data))
    ctf_integer_hex(uintptr_t, task_data, (uintptr_t)(task_data))
    ctf_integer_hex(uintptr_t, codeptr_ra, (uintptr_t)(codeptr_ra))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ompt,
  ompt_callback_sync_region,
  TP_ARGS(
    ompt_sync_region_t, kind,
    ompt_scope_endpoint_t, endpoint,
    ompt_data_t *, parallel_data,
    ompt_data_t *, task_data,
    const void *, codeptr_ra
  ),
  TP_FIELDS(
    ctf_integer(int32_t, kind, kind)
    ctf_integer(int32_t, endpoint, endpoint)
    ctf_integer_hex(uintptr_t, parallel_data, (uintptr_t)(parallel_data))
    ctf_integer_hex(uintptr_t, task_data, (uintptr_t)(task_data))
    ctf_integer_hex(uintptr_t, codeptr_ra, (uintptr_t)(codeptr_ra))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ompt,
  ompt_callback_mutex_acquire,
  TP_ARGS(
    ompt_mutex_t, kind,
    unsigned int, hint,
    unsigned int, impl,
    ompt_wait_id_t, wait_id,
    const void *, codeptr_ra
  ),
  TP_FIELDS(
    ctf_integer(int32_t, kind, kind)
    ctf_integer(unsigned int, hint, hint)
    ctf_integer(unsigned int, impl, impl)
    ctf_integer(ompt_wait_id_t, wait_id, wait_id)
    ctf_integer_hex(uintptr_t, codeptr_ra, (uintptr_t)(codeptr_ra))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ompt,
  ompt_callback_mutex,
  TP_ARGS(
    ompt_mutex_t, kind,
    ompt_wait_id_t, wait_id,
    const void *, codeptr_ra
  ),
  TP_FIELDS(
    ctf_integer(int32_t, kind, kind)
    ctf_integer(ompt_wait_id_t, wait_id, wait_id)
    ctf_integer_hex(uintptr_t, codeptr_ra, (uintptr_t)(codeptr_ra))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ompt,
  ompt_callback_nest_lock,
  TP_ARGS(
    ompt_scope_endpoint_t, endpoint,
    ompt_wait_id_t, wait_id,
    const void *, codeptr_ra
  ),
  TP_FIELDS(
    ctf_integer(int32_t, endpoint, endpoint)
    ctf_integer(ompt_wait_id_t, wait_id, wait_id)
    ctf_integer_hex(uintptr_t, codeptr_ra, (uintptr_t)(codeptr_ra))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ompt,
  ompt_callback_flush,
  TP_ARGS(
    ompt_data_t *, thread_data,
    const void *, codeptr_ra
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, thread_data, (uintptr_t)(thread_data))
    ctf_integer_hex(uintptr_t, codeptr_ra, (uintptr_t)(codeptr_ra))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ompt,
  ompt_callback_cancel,
  TP_ARGS(
    ompt_data_t *, task_data,
    ompt_cancel_flags_t, flags,
    const void *, codeptr_ra
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, task_data, (uintptr_t)(task_data))
    ctf_integer(ompt_cancel_flags_t, flags, flags)
    ctf_integer_hex(uintptr_t, codeptr_ra, (uintptr_t)(codeptr_ra))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ompt,
  ompt_callback_device_initialize,
  TP_ARGS(
    int, device_num,
    const char *, type,
    ompt_device_t *, device,
    ompt_function_lookup_t, lookup,
    const char *, documentation
  ),
  TP_FIELDS(
    ctf_integer(int, device_num, device_num)
    ctf_integer_hex(uintptr_t, type, (uintptr_t)(type))
    ctf_integer_hex(uintptr_t, device, (uintptr_t)(device))
    ctf_integer_hex(uintptr_t, lookup, (uintptr_t)(lookup))
    ctf_integer_hex(uintptr_t, documentation, (uintptr_t)(documentation))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ompt,
  ompt_callback_device_finalize,
  TP_ARGS(
    int, device_num
  ),
  TP_FIELDS(
    ctf_integer(int, device_num, device_num)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ompt,
  ompt_callback_device_load,
  TP_ARGS(
    int, device_num,
    const char *, filename,
    int64_t, offset_in_file,
    void *, vma_in_file,
    size_t, bytes,
    void *, host_addr,
    void *, device_addr,
    uint64_t, module_id
  ),
  TP_FIELDS(
    ctf_integer(int, device_num, device_num)
    ctf_integer_hex(uintptr_t, filename, (uintptr_t)(filename))
    ctf_integer(int64_t, offset_in_file, offset_in_file)
    ctf_integer_hex(uintptr_t, vma_in_file, (uintptr_t)(vma_in_file))
    ctf_integer(size_t, bytes, bytes)
    ctf_integer_hex(uintptr_t, host_addr, (uintptr_t)(host_addr))
    ctf_integer_hex(uintptr_t, device_addr, (uintptr_t)(device_addr))
    ctf_integer(uint64_t, module_id, module_id)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ompt,
  ompt_callback_device_unload,
  TP_ARGS(
    int, device_num,
    uint64_t, module_id
  ),
  TP_FIELDS(
    ctf_integer(int, device_num, device_num)
    ctf_integer(uint64_t, module_id, module_id)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ompt,
  ompt_callback_target_data_op_emi,
  TP_ARGS(
    ompt_scope_endpoint_t, endpoint,
    ompt_data_t *, target_task_data,
    ompt_data_t *, target_data,
    ompt_id_t *, host_op_id,
    ompt_target_data_op_t, optype,
    void *, src_addr,
    int, src_device_num,
    void *, dest_addr,
    int, dest_device_num,
    size_t, bytes,
    const void *, codeptr_ra
  ),
  TP_FIELDS(
    ctf_integer(int32_t, endpoint, endpoint)
    ctf_integer_hex(uintptr_t, target_task_data, (uintptr_t)(target_task_data))
    ctf_integer_hex(uintptr_t, target_data, (uintptr_t)(target_data))
    ctf_integer_hex(uintptr_t, host_op_id, (uintptr_t)(host_op_id))
    ctf_integer(int32_t, optype, optype)
    ctf_integer_hex(uintptr_t, src_addr, (uintptr_t)(src_addr))
    ctf_integer(int, src_device_num, src_device_num)
    ctf_integer_hex(uintptr_t, dest_addr, (uintptr_t)(dest_addr))
    ctf_integer(int, dest_device_num, dest_device_num)
    ctf_integer(size_t, bytes, bytes)
    ctf_integer_hex(uintptr_t, codeptr_ra, (uintptr_t)(codeptr_ra))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ompt,
  ompt_callback_target_data_op,
  TP_ARGS(
    ompt_id_t, target_id,
    ompt_id_t, host_op_id,
    ompt_target_data_op_t, optype,
    void *, src_addr,
    int, src_device_num,
    void *, dest_addr,
    int, dest_device_num,
    size_t, bytes,
    const void *, codeptr_ra
  ),
  TP_FIELDS(
    ctf_integer(ompt_id_t, target_id, target_id)
    ctf_integer(ompt_id_t, host_op_id, host_op_id)
    ctf_integer(int32_t, optype, optype)
    ctf_integer_hex(uintptr_t, src_addr, (uintptr_t)(src_addr))
    ctf_integer(int, src_device_num, src_device_num)
    ctf_integer_hex(uintptr_t, dest_addr, (uintptr_t)(dest_addr))
    ctf_integer(int, dest_device_num, dest_device_num)
    ctf_integer(size_t, bytes, bytes)
    ctf_integer_hex(uintptr_t, codeptr_ra, (uintptr_t)(codeptr_ra))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ompt,
  ompt_callback_target_emi,
  TP_ARGS(
    ompt_target_t, kind,
    ompt_scope_endpoint_t, endpoint,
    int, device_num,
    ompt_data_t *, task_data,
    ompt_data_t *, target_task_data,
    ompt_data_t *, target_data,
    const void *, codeptr_ra
  ),
  TP_FIELDS(
    ctf_integer(int32_t, kind, kind)
    ctf_integer(int32_t, endpoint, endpoint)
    ctf_integer(int, device_num, device_num)
    ctf_integer_hex(uintptr_t, task_data, (uintptr_t)(task_data))
    ctf_integer_hex(uintptr_t, target_task_data, (uintptr_t)(target_task_data))
    ctf_integer_hex(uintptr_t, target_data, (uintptr_t)(target_data))
    ctf_integer_hex(uintptr_t, codeptr_ra, (uintptr_t)(codeptr_ra))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ompt,
  ompt_callback_target,
  TP_ARGS(
    ompt_target_t, kind,
    ompt_scope_endpoint_t, endpoint,
    int, device_num,
    ompt_data_t *, task_data,
    ompt_id_t, target_id,
    const void *, codeptr_ra
  ),
  TP_FIELDS(
    ctf_integer(int32_t, kind, kind)
    ctf_integer(int32_t, endpoint, endpoint)
    ctf_integer(int, device_num, device_num)
    ctf_integer_hex(uintptr_t, task_data, (uintptr_t)(task_data))
    ctf_integer(ompt_id_t, target_id, target_id)
    ctf_integer_hex(uintptr_t, codeptr_ra, (uintptr_t)(codeptr_ra))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ompt,
  ompt_callback_target_map_emi,
  TP_ARGS(
    ompt_data_t *, target_data,
    unsigned int, nitems,
    void **, host_addr,
    void **, device_addr,
    size_t *, bytes,
    unsigned int *, mapping_flags,
    const void *, codeptr_ra
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, target_data, (uintptr_t)(target_data))
    ctf_integer(unsigned int, nitems, nitems)
    ctf_integer_hex(uintptr_t, host_addr, (uintptr_t)(host_addr))
    ctf_integer_hex(uintptr_t, device_addr, (uintptr_t)(device_addr))
    ctf_integer_hex(uintptr_t, bytes, (uintptr_t)(bytes))
    ctf_integer_hex(uintptr_t, mapping_flags, (uintptr_t)(mapping_flags))
    ctf_integer_hex(uintptr_t, codeptr_ra, (uintptr_t)(codeptr_ra))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ompt,
  ompt_callback_target_map,
  TP_ARGS(
    ompt_id_t, target_id,
    unsigned int, nitems,
    void **, host_addr,
    void **, device_addr,
    size_t *, bytes,
    ompt_target_map_flags_t *, mapping_flags,
    const void *, codeptr_ra
  ),
  TP_FIELDS(
    ctf_integer(ompt_id_t, target_id, target_id)
    ctf_integer(unsigned int, nitems, nitems)
    ctf_integer_hex(uintptr_t, host_addr, (uintptr_t)(host_addr))
    ctf_integer_hex(uintptr_t, device_addr, (uintptr_t)(device_addr))
    ctf_integer_hex(uintptr_t, bytes, (uintptr_t)(bytes))
    ctf_integer_hex(uintptr_t, mapping_flags, (uintptr_t)(mapping_flags))
    ctf_integer_hex(uintptr_t, codeptr_ra, (uintptr_t)(codeptr_ra))
    ctf_sequence_hex(uintptr_t, host_addr_vals, host_addr, unsigned int, (host_addr ? nitems : 0))
    ctf_sequence_hex(uintptr_t, device_addr_vals, device_addr, unsigned int, (device_addr ? nitems : 0))
    ctf_sequence(size_t, bytes_vals, bytes, unsigned int, (bytes ? nitems : 0))
    ctf_sequence(ompt_target_map_flags_t, mapping_flags_vals, mapping_flags, unsigned int, (mapping_flags ? nitems : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ompt,
  ompt_callback_target_submit,
  TP_ARGS(
    ompt_id_t, target_id,
    ompt_id_t, host_op_id,
    unsigned int, requested_num_teams
  ),
  TP_FIELDS(
    ctf_integer(ompt_id_t, target_id, target_id)
    ctf_integer(ompt_id_t, host_op_id, host_op_id)
    ctf_integer(unsigned int, requested_num_teams, requested_num_teams)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ompt,
  ompt_callback_target_submit_emi,
  TP_ARGS(
    ompt_scope_endpoint_t, endpoint,
    ompt_data_t *, target_data,
    ompt_id_t *, host_op_id,
    unsigned int, requested_num_teams
  ),
  TP_FIELDS(
    ctf_integer(int32_t, endpoint, endpoint)
    ctf_integer_hex(uintptr_t, target_data, (uintptr_t)(target_data))
    ctf_integer_hex(uintptr_t, host_op_id, (uintptr_t)(host_op_id))
    ctf_integer(unsigned int, requested_num_teams, requested_num_teams)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ompt,
  ompt_callback_control_tool,
  TP_ARGS(
    uint64_t, command,
    uint64_t, modifier,
    void *, arg,
    const void *, codeptr_ra,
    int, ompResult
  ),
  TP_FIELDS(
    ctf_integer(int, ompResult, ompResult)
    ctf_integer(uint64_t, command, command)
    ctf_integer(uint64_t, modifier, modifier)
    ctf_integer_hex(uintptr_t, arg, (uintptr_t)(arg))
    ctf_integer_hex(uintptr_t, codeptr_ra, (uintptr_t)(codeptr_ra))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ompt,
  ompt_callback_error,
  TP_ARGS(
    ompt_severity_t, severity,
    const char *, message,
    size_t, length,
    const void *, codeptr_ra
  ),
  TP_FIELDS(
    ctf_integer(int32_t, severity, severity)
    ctf_integer_hex(uintptr_t, message, (uintptr_t)(message))
    ctf_integer(size_t, length, length)
    ctf_integer_hex(uintptr_t, codeptr_ra, (uintptr_t)(codeptr_ra))
  )
)


#endif /* OMPT_TRACEPOINTS_H */

#include <lttng/tracepoint-event.h>
