
#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER lttng_ust_ze_structs

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "./ze_structs_tracepoints.h"

#if !defined(ZE_STRUCTS_TRACEPOINTS_H) || defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define ZE_STRUCTS_TRACEPOINTS_H

#include <lttng/tracepoint.h>

#include "lttng/tracepoint_gen.h"
#include "ze.h.include"
TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_init_driver_type_desc_t,
  TP_ARGS(
    ze_init_driver_type_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_init_driver_type_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_driver_properties_t,
  TP_ARGS(
    ze_driver_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_driver_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_driver_ipc_properties_t,
  TP_ARGS(
    ze_driver_ipc_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_driver_ipc_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_device_properties_t,
  TP_ARGS(
    ze_device_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_device_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_device_compute_properties_t,
  TP_ARGS(
    ze_device_compute_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_device_compute_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_device_module_properties_t,
  TP_ARGS(
    ze_device_module_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_device_module_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_command_queue_group_properties_t,
  TP_ARGS(
    ze_command_queue_group_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_command_queue_group_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_device_memory_properties_t,
  TP_ARGS(
    ze_device_memory_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_device_memory_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_device_memory_access_properties_t,
  TP_ARGS(
    ze_device_memory_access_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_device_memory_access_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_device_cache_properties_t,
  TP_ARGS(
    ze_device_cache_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_device_cache_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_device_image_properties_t,
  TP_ARGS(
    ze_device_image_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_device_image_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_device_external_memory_properties_t,
  TP_ARGS(
    ze_device_external_memory_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_device_external_memory_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_device_p2p_properties_t,
  TP_ARGS(
    ze_device_p2p_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_device_p2p_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_context_desc_t,
  TP_ARGS(
    ze_context_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_context_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_command_queue_desc_t,
  TP_ARGS(
    ze_command_queue_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_command_queue_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_command_list_desc_t,
  TP_ARGS(
    ze_command_list_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_command_list_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_event_pool_desc_t,
  TP_ARGS(
    ze_event_pool_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_event_pool_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_event_desc_t,
  TP_ARGS(
    ze_event_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_event_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_fence_desc_t,
  TP_ARGS(
    ze_fence_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_fence_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_image_desc_t,
  TP_ARGS(
    ze_image_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_image_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_image_properties_t,
  TP_ARGS(
    ze_image_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_image_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_device_mem_alloc_desc_t,
  TP_ARGS(
    ze_device_mem_alloc_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_device_mem_alloc_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_host_mem_alloc_desc_t,
  TP_ARGS(
    ze_host_mem_alloc_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_host_mem_alloc_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_memory_allocation_properties_t,
  TP_ARGS(
    ze_memory_allocation_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_memory_allocation_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_external_memory_export_desc_t,
  TP_ARGS(
    ze_external_memory_export_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_external_memory_export_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_external_memory_import_fd_t,
  TP_ARGS(
    ze_external_memory_import_fd_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_external_memory_import_fd_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_external_memory_export_fd_t,
  TP_ARGS(
    ze_external_memory_export_fd_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_external_memory_export_fd_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_external_memory_import_win32_handle_t,
  TP_ARGS(
    ze_external_memory_import_win32_handle_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_external_memory_import_win32_handle_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_external_memory_export_win32_handle_t,
  TP_ARGS(
    ze_external_memory_export_win32_handle_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_external_memory_export_win32_handle_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_module_desc_t,
  TP_ARGS(
    ze_module_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_module_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_module_properties_t,
  TP_ARGS(
    ze_module_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_module_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_kernel_desc_t,
  TP_ARGS(
    ze_kernel_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_kernel_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_kernel_properties_t,
  TP_ARGS(
    ze_kernel_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_kernel_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_kernel_preferred_group_size_properties_t,
  TP_ARGS(
    ze_kernel_preferred_group_size_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_kernel_preferred_group_size_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_module_program_exp_desc_t,
  TP_ARGS(
    ze_module_program_exp_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_module_program_exp_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_device_raytracing_ext_properties_t,
  TP_ARGS(
    ze_device_raytracing_ext_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_device_raytracing_ext_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_raytracing_mem_alloc_ext_desc_t,
  TP_ARGS(
    ze_raytracing_mem_alloc_ext_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_raytracing_mem_alloc_ext_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_sampler_desc_t,
  TP_ARGS(
    ze_sampler_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_sampler_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_physical_mem_desc_t,
  TP_ARGS(
    ze_physical_mem_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_physical_mem_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_float_atomic_ext_properties_t,
  TP_ARGS(
    ze_float_atomic_ext_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_float_atomic_ext_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_relaxed_allocation_limits_exp_desc_t,
  TP_ARGS(
    ze_relaxed_allocation_limits_exp_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_relaxed_allocation_limits_exp_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_driver_ddi_handles_ext_properties_t,
  TP_ARGS(
    ze_driver_ddi_handles_ext_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_driver_ddi_handles_ext_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_external_semaphore_ext_desc_t,
  TP_ARGS(
    ze_external_semaphore_ext_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_external_semaphore_ext_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_external_semaphore_win32_ext_desc_t,
  TP_ARGS(
    ze_external_semaphore_win32_ext_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_external_semaphore_win32_ext_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_external_semaphore_fd_ext_desc_t,
  TP_ARGS(
    ze_external_semaphore_fd_ext_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_external_semaphore_fd_ext_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_external_semaphore_signal_params_ext_t,
  TP_ARGS(
    ze_external_semaphore_signal_params_ext_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_external_semaphore_signal_params_ext_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_external_semaphore_wait_params_ext_t,
  TP_ARGS(
    ze_external_semaphore_wait_params_ext_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_external_semaphore_wait_params_ext_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_device_cache_line_size_ext_t,
  TP_ARGS(
    ze_device_cache_line_size_ext_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_device_cache_line_size_ext_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_rtas_builder_ext_desc_t,
  TP_ARGS(
    ze_rtas_builder_ext_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_rtas_builder_ext_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_rtas_builder_ext_properties_t,
  TP_ARGS(
    ze_rtas_builder_ext_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_rtas_builder_ext_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_rtas_parallel_operation_ext_properties_t,
  TP_ARGS(
    ze_rtas_parallel_operation_ext_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_rtas_parallel_operation_ext_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_rtas_device_ext_properties_t,
  TP_ARGS(
    ze_rtas_device_ext_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_rtas_device_ext_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_rtas_geometry_aabbs_ext_cb_params_t,
  TP_ARGS(
    ze_rtas_geometry_aabbs_ext_cb_params_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_rtas_geometry_aabbs_ext_cb_params_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_rtas_builder_build_op_ext_desc_t,
  TP_ARGS(
    ze_rtas_builder_build_op_ext_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_rtas_builder_build_op_ext_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_device_vector_width_properties_ext_t,
  TP_ARGS(
    ze_device_vector_width_properties_ext_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_device_vector_width_properties_ext_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_cache_reservation_ext_desc_t,
  TP_ARGS(
    ze_cache_reservation_ext_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_cache_reservation_ext_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_image_memory_properties_exp_t,
  TP_ARGS(
    ze_image_memory_properties_exp_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_image_memory_properties_exp_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_image_view_planar_ext_desc_t,
  TP_ARGS(
    ze_image_view_planar_ext_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_image_view_planar_ext_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_image_view_planar_exp_desc_t,
  TP_ARGS(
    ze_image_view_planar_exp_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_image_view_planar_exp_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_scheduling_hint_exp_properties_t,
  TP_ARGS(
    ze_scheduling_hint_exp_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_scheduling_hint_exp_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_scheduling_hint_exp_desc_t,
  TP_ARGS(
    ze_scheduling_hint_exp_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_scheduling_hint_exp_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_context_power_saving_hint_exp_desc_t,
  TP_ARGS(
    ze_context_power_saving_hint_exp_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_context_power_saving_hint_exp_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_eu_count_ext_t,
  TP_ARGS(
    ze_eu_count_ext_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_eu_count_ext_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_pci_ext_properties_t,
  TP_ARGS(
    ze_pci_ext_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_pci_ext_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_srgb_ext_desc_t,
  TP_ARGS(
    ze_srgb_ext_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_srgb_ext_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_image_allocation_ext_properties_t,
  TP_ARGS(
    ze_image_allocation_ext_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_image_allocation_ext_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_linkage_inspection_ext_desc_t,
  TP_ARGS(
    ze_linkage_inspection_ext_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_linkage_inspection_ext_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_memory_compression_hints_ext_desc_t,
  TP_ARGS(
    ze_memory_compression_hints_ext_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_memory_compression_hints_ext_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_driver_memory_free_ext_properties_t,
  TP_ARGS(
    ze_driver_memory_free_ext_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_driver_memory_free_ext_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_memory_free_ext_desc_t,
  TP_ARGS(
    ze_memory_free_ext_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_memory_free_ext_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_device_p2p_bandwidth_exp_properties_t,
  TP_ARGS(
    ze_device_p2p_bandwidth_exp_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_device_p2p_bandwidth_exp_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_copy_bandwidth_exp_properties_t,
  TP_ARGS(
    ze_copy_bandwidth_exp_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_copy_bandwidth_exp_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_device_luid_ext_properties_t,
  TP_ARGS(
    ze_device_luid_ext_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_device_luid_ext_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_fabric_vertex_exp_properties_t,
  TP_ARGS(
    ze_fabric_vertex_exp_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_fabric_vertex_exp_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_fabric_edge_exp_properties_t,
  TP_ARGS(
    ze_fabric_edge_exp_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_fabric_edge_exp_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_device_memory_ext_properties_t,
  TP_ARGS(
    ze_device_memory_ext_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_device_memory_ext_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_device_ip_version_ext_t,
  TP_ARGS(
    ze_device_ip_version_ext_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_device_ip_version_ext_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_kernel_max_group_size_properties_ext_t,
  TP_ARGS(
    ze_kernel_max_group_size_properties_ext_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_kernel_max_group_size_properties_ext_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_memory_sub_allocations_exp_properties_t,
  TP_ARGS(
    ze_memory_sub_allocations_exp_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_memory_sub_allocations_exp_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_event_query_kernel_timestamps_ext_properties_t,
  TP_ARGS(
    ze_event_query_kernel_timestamps_ext_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_event_query_kernel_timestamps_ext_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_event_query_kernel_timestamps_results_ext_properties_t,
  TP_ARGS(
    ze_event_query_kernel_timestamps_results_ext_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_event_query_kernel_timestamps_results_ext_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_rtas_builder_exp_desc_t,
  TP_ARGS(
    ze_rtas_builder_exp_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_rtas_builder_exp_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_rtas_builder_exp_properties_t,
  TP_ARGS(
    ze_rtas_builder_exp_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_rtas_builder_exp_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_rtas_parallel_operation_exp_properties_t,
  TP_ARGS(
    ze_rtas_parallel_operation_exp_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_rtas_parallel_operation_exp_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_rtas_device_exp_properties_t,
  TP_ARGS(
    ze_rtas_device_exp_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_rtas_device_exp_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_rtas_geometry_aabbs_exp_cb_params_t,
  TP_ARGS(
    ze_rtas_geometry_aabbs_exp_cb_params_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_rtas_geometry_aabbs_exp_cb_params_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_rtas_builder_build_op_exp_desc_t,
  TP_ARGS(
    ze_rtas_builder_build_op_exp_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_rtas_builder_build_op_exp_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_event_pool_counter_based_exp_desc_t,
  TP_ARGS(
    ze_event_pool_counter_based_exp_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_event_pool_counter_based_exp_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_image_bindless_exp_desc_t,
  TP_ARGS(
    ze_image_bindless_exp_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_image_bindless_exp_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_image_pitched_exp_desc_t,
  TP_ARGS(
    ze_image_pitched_exp_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_image_pitched_exp_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_device_pitched_alloc_exp_properties_t,
  TP_ARGS(
    ze_device_pitched_alloc_exp_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_device_pitched_alloc_exp_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_mutable_command_id_exp_desc_t,
  TP_ARGS(
    ze_mutable_command_id_exp_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_mutable_command_id_exp_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_mutable_command_list_exp_properties_t,
  TP_ARGS(
    ze_mutable_command_list_exp_properties_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_mutable_command_list_exp_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_mutable_command_list_exp_desc_t,
  TP_ARGS(
    ze_mutable_command_list_exp_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_mutable_command_list_exp_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_mutable_commands_exp_desc_t,
  TP_ARGS(
    ze_mutable_commands_exp_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_mutable_commands_exp_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_mutable_kernel_argument_exp_desc_t,
  TP_ARGS(
    ze_mutable_kernel_argument_exp_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_mutable_kernel_argument_exp_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_mutable_group_count_exp_desc_t,
  TP_ARGS(
    ze_mutable_group_count_exp_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_mutable_group_count_exp_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_mutable_group_size_exp_desc_t,
  TP_ARGS(
    ze_mutable_group_size_exp_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_mutable_group_size_exp_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_mutable_global_offset_exp_desc_t,
  TP_ARGS(
    ze_mutable_global_offset_exp_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_mutable_global_offset_exp_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_structs,
  ze_mutable_graph_argument_exp_desc_t,
  TP_ARGS(
    ze_mutable_graph_argument_exp_desc_t *, p
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, p, (uintptr_t)(p))
    ctf_sequence_text(uint8_t, p_val, p, size_t, (p ? sizeof(ze_mutable_graph_argument_exp_desc_t) : 0))
  )
)


#endif /* ZE_STRUCTS_TRACEPOINTS_H */

#include <lttng/tracepoint-event.h>
