#include <stdint.h>
#include <stddef.h>
#include <omp-tools.h>
#include "ompt_tracepoints.h"
static void ompt_callback_thread_begin_func(ompt_thread_t thread_type, ompt_data_t *thread_data) {
  tracepoint(lttng_ust_ompt, ompt_callback_thread_begin, thread_type, thread_data);
}

static void ompt_callback_thread_end_func(ompt_data_t *thread_data) {
  tracepoint(lttng_ust_ompt, ompt_callback_thread_end, thread_data);
}

static void ompt_callback_parallel_begin_func(ompt_data_t *encountering_task_data, const ompt_frame_t *encountering_task_frame, ompt_data_t *parallel_data, unsigned int requested_parallelism, ompt_parallel_flags_t flags, const void *codeptr_ra) {
  tracepoint(lttng_ust_ompt, ompt_callback_parallel_begin, encountering_task_data, encountering_task_frame, parallel_data, requested_parallelism, flags, codeptr_ra);
}

static void ompt_callback_parallel_end_func(ompt_data_t *parallel_data, ompt_data_t *encountering_task_data, ompt_parallel_flags_t flags, const void *codeptr_ra) {
  tracepoint(lttng_ust_ompt, ompt_callback_parallel_end, parallel_data, encountering_task_data, flags, codeptr_ra);
}

static void ompt_callback_work_func(ompt_work_t work_type, ompt_scope_endpoint_t endpoint, ompt_data_t *parallel_data, ompt_data_t *task_data, uint64_t count, const void *codeptr_ra) {
  tracepoint(lttng_ust_ompt, ompt_callback_work, work_type, endpoint, parallel_data, task_data, count, codeptr_ra);
}

static void ompt_callback_dispatch_func(ompt_data_t *parallel_data, ompt_data_t *task_data, ompt_dispatch_t kind, ompt_data_t instance) {
  tracepoint(lttng_ust_ompt, ompt_callback_dispatch, parallel_data, task_data, kind, instance);
}

static void ompt_callback_task_create_func(ompt_data_t *encountering_task_data, const ompt_frame_t *encountering_task_frame, ompt_data_t *new_task_data, ompt_task_flags_t flags, int has_dependences, const void *codeptr_ra) {
  tracepoint(lttng_ust_ompt, ompt_callback_task_create, encountering_task_data, encountering_task_frame, new_task_data, flags, has_dependences, codeptr_ra);
}

static void ompt_callback_dependences_func(ompt_data_t *task_data, const ompt_dependence_t *deps, int ndeps) {
  tracepoint(lttng_ust_ompt, ompt_callback_dependences, task_data, deps, ndeps);
}

static void ompt_callback_task_dependence_func(ompt_data_t *src_task_data, ompt_data_t *sink_task_data) {
  tracepoint(lttng_ust_ompt, ompt_callback_task_dependence, src_task_data, sink_task_data);
}

static void ompt_callback_task_schedule_func(ompt_data_t *prior_task_data, ompt_task_status_t prior_task_status, ompt_data_t *next_task_data) {
  tracepoint(lttng_ust_ompt, ompt_callback_task_schedule, prior_task_data, prior_task_status, next_task_data);
}

static void ompt_callback_implicit_task_func(ompt_scope_endpoint_t endpoint, ompt_data_t *parallel_data, ompt_data_t *task_data, unsigned int actual_parallelism, unsigned int index, ompt_task_flags_t flags) {
  tracepoint(lttng_ust_ompt, ompt_callback_implicit_task, endpoint, parallel_data, task_data, actual_parallelism, index, flags);
}

static void ompt_callback_masked_func(ompt_scope_endpoint_t endpoint, ompt_data_t *parallel_data, ompt_data_t *task_data, const void *codeptr_ra) {
  tracepoint(lttng_ust_ompt, ompt_callback_masked, endpoint, parallel_data, task_data, codeptr_ra);
}

static void ompt_callback_sync_region_func(ompt_sync_region_t kind, ompt_scope_endpoint_t endpoint, ompt_data_t *parallel_data, ompt_data_t *task_data, const void *codeptr_ra) {
  tracepoint(lttng_ust_ompt, ompt_callback_sync_region, kind, endpoint, parallel_data, task_data, codeptr_ra);
}

static void ompt_callback_mutex_acquire_func(ompt_mutex_t kind, unsigned int hint, unsigned int impl, ompt_wait_id_t wait_id, const void *codeptr_ra) {
  tracepoint(lttng_ust_ompt, ompt_callback_mutex_acquire, kind, hint, impl, wait_id, codeptr_ra);
}

static void ompt_callback_mutex_func(ompt_mutex_t kind, ompt_wait_id_t wait_id, const void *codeptr_ra) {
  tracepoint(lttng_ust_ompt, ompt_callback_mutex, kind, wait_id, codeptr_ra);
}

static void ompt_callback_nest_lock_func(ompt_scope_endpoint_t endpoint, ompt_wait_id_t wait_id, const void *codeptr_ra) {
  tracepoint(lttng_ust_ompt, ompt_callback_nest_lock, endpoint, wait_id, codeptr_ra);
}

static void ompt_callback_flush_func(ompt_data_t *thread_data, const void *codeptr_ra) {
  tracepoint(lttng_ust_ompt, ompt_callback_flush, thread_data, codeptr_ra);
}

static void ompt_callback_cancel_func(ompt_data_t *task_data, ompt_cancel_flags_t flags, const void *codeptr_ra) {
  tracepoint(lttng_ust_ompt, ompt_callback_cancel, task_data, flags, codeptr_ra);
}

static void ompt_callback_device_initialize_func(int device_num, const char *type, ompt_device_t *device, ompt_function_lookup_t lookup, const char *documentation) {
  tracepoint(lttng_ust_ompt, ompt_callback_device_initialize, device_num, type, device, lookup, documentation);
}

static void ompt_callback_device_finalize_func(int device_num) {
  tracepoint(lttng_ust_ompt, ompt_callback_device_finalize, device_num);
}

static void ompt_callback_device_load_func(int device_num, const char *filename, int64_t offset_in_file, void *vma_in_file, size_t bytes, void *host_addr, void *device_addr, uint64_t module_id) {
  tracepoint(lttng_ust_ompt, ompt_callback_device_load, device_num, filename, offset_in_file, vma_in_file, bytes, host_addr, device_addr, module_id);
}

static void ompt_callback_device_unload_func(int device_num, uint64_t module_id) {
  tracepoint(lttng_ust_ompt, ompt_callback_device_unload, device_num, module_id);
}

static void ompt_callback_target_data_op_emi_func(ompt_scope_endpoint_t endpoint, ompt_data_t *target_task_data, ompt_data_t *target_data, ompt_id_t *host_op_id, ompt_target_data_op_t optype, void *src_addr, int src_device_num, void *dest_addr, int dest_device_num, size_t bytes, const void *codeptr_ra) {
  tracepoint(lttng_ust_ompt, ompt_callback_target_data_op_emi, endpoint, target_task_data, target_data, host_op_id, optype, src_addr, src_device_num, dest_addr, dest_device_num, bytes, codeptr_ra);
}

static void ompt_callback_target_data_op_func(ompt_id_t target_id, ompt_id_t host_op_id, ompt_target_data_op_t optype, void *src_addr, int src_device_num, void *dest_addr, int dest_device_num, size_t bytes, const void *codeptr_ra) {
  tracepoint(lttng_ust_ompt, ompt_callback_target_data_op, target_id, host_op_id, optype, src_addr, src_device_num, dest_addr, dest_device_num, bytes, codeptr_ra);
}

static void ompt_callback_target_emi_func(ompt_target_t kind, ompt_scope_endpoint_t endpoint, int device_num, ompt_data_t *task_data, ompt_data_t *target_task_data, ompt_data_t *target_data, const void *codeptr_ra) {
  tracepoint(lttng_ust_ompt, ompt_callback_target_emi, kind, endpoint, device_num, task_data, target_task_data, target_data, codeptr_ra);
}

static void ompt_callback_target_func(ompt_target_t kind, ompt_scope_endpoint_t endpoint, int device_num, ompt_data_t *task_data, ompt_id_t target_id, const void *codeptr_ra) {
  tracepoint(lttng_ust_ompt, ompt_callback_target, kind, endpoint, device_num, task_data, target_id, codeptr_ra);
}

static void ompt_callback_target_map_emi_func(ompt_data_t *target_data, unsigned int nitems, void **host_addr, void **device_addr, size_t *bytes, unsigned int *mapping_flags, const void *codeptr_ra) {
  tracepoint(lttng_ust_ompt, ompt_callback_target_map_emi, target_data, nitems, host_addr, device_addr, bytes, mapping_flags, codeptr_ra);
}

static void ompt_callback_target_map_func(ompt_id_t target_id, unsigned int nitems, void **host_addr, void **device_addr, size_t *bytes, ompt_target_map_flags_t *mapping_flags, const void *codeptr_ra) {
  tracepoint(lttng_ust_ompt, ompt_callback_target_map, target_id, nitems, host_addr, device_addr, bytes, mapping_flags, codeptr_ra);
}

static void ompt_callback_target_submit_func(ompt_id_t target_id, ompt_id_t host_op_id, unsigned int requested_num_teams) {
  tracepoint(lttng_ust_ompt, ompt_callback_target_submit, target_id, host_op_id, requested_num_teams);
}

static void ompt_callback_target_submit_emi_func(ompt_scope_endpoint_t endpoint, ompt_data_t *target_data, ompt_id_t *host_op_id, unsigned int requested_num_teams) {
  tracepoint(lttng_ust_ompt, ompt_callback_target_submit_emi, endpoint, target_data, host_op_id, requested_num_teams);
}

static void ompt_callback_error_func(ompt_severity_t severity, const char *message, size_t length, const void *codeptr_ra) {
  tracepoint(lttng_ust_ompt, ompt_callback_error, severity, message, length, codeptr_ra);
}


#define _OMPT_SET_CALLBACK(value, name) \
do { \
    const ompt_set_result_t _res = ompt_set_callback(value, (ompt_callback_t) name ## _func); \
    if (!verbose) \
        break; \
    switch (_res) { \
    case ompt_set_sometimes: \
    case ompt_set_sometimes_paired: \
        fprintf(stderr, "THAPI Warning: '%s' callback will be called sometimes (error code: %d)\n", #name, _res); \
        break; \
    case ompt_set_error: \
    case ompt_set_never: \
    case ompt_set_impossible: \
        fprintf(stderr, "THAPI Warning: '%s' callback will never be called (error code: %d)\n", #name, _res); \
        break; \
    case ompt_set_always: \
        break; \
    } \
} while (0)

static void _ompt_finalize(ompt_data_t *tool_data) {
    (void) tool_data;
}

static int _ompt_initialize(ompt_function_lookup_t lookup,
                            int initial_device_num,
                            ompt_data_t *tool_data)
{
    (void) initial_device_num;
    (void) tool_data;
    int do_callbacks_emi = 1;
    int verbose = 0;

    /* TODO: enable when oneAPI updates ompt runtime omp_version
    if (tool_data->value < 202011) {
        // Note: version 202011 is 5.1, where the emi callbacks were added
        do_callbacks_emi = 0;
    }
    */
    if (getenv("LTTNG_UST_OMP_NO_EMI"))
        do_callbacks_emi = 0;
    if (getenv("LTTNG_UST_OMP_VERBOSE")) 
        verbose = 1;

    ompt_set_callback_t ompt_set_callback = (ompt_set_callback_t) lookup("ompt_set_callback");
    if (ompt_set_callback == NULL)
        return 0;

              _OMPT_SET_CALLBACK(ompt_callback_thread_begin, ompt_callback_thread_begin);
                    _OMPT_SET_CALLBACK(ompt_callback_thread_end, ompt_callback_thread_end);
                    _OMPT_SET_CALLBACK(ompt_callback_parallel_begin, ompt_callback_parallel_begin);
                    _OMPT_SET_CALLBACK(ompt_callback_parallel_end, ompt_callback_parallel_end);
                    _OMPT_SET_CALLBACK(ompt_callback_task_create, ompt_callback_task_create);
                    _OMPT_SET_CALLBACK(ompt_callback_task_schedule, ompt_callback_task_schedule);
                    _OMPT_SET_CALLBACK(ompt_callback_implicit_task, ompt_callback_implicit_task);
                    _OMPT_SET_CALLBACK(ompt_callback_device_initialize, ompt_callback_device_initialize);
                    _OMPT_SET_CALLBACK(ompt_callback_device_finalize, ompt_callback_device_finalize);
                    _OMPT_SET_CALLBACK(ompt_callback_device_load, ompt_callback_device_load);
                    _OMPT_SET_CALLBACK(ompt_callback_device_unload, ompt_callback_device_unload);
                    _OMPT_SET_CALLBACK(ompt_callback_sync_region_wait, ompt_callback_sync_region);
                    _OMPT_SET_CALLBACK(ompt_callback_mutex_released, ompt_callback_mutex);
                    _OMPT_SET_CALLBACK(ompt_callback_dependences, ompt_callback_dependences);
                    _OMPT_SET_CALLBACK(ompt_callback_task_dependence, ompt_callback_task_dependence);
                    _OMPT_SET_CALLBACK(ompt_callback_work, ompt_callback_work);
                    _OMPT_SET_CALLBACK(ompt_callback_masked, ompt_callback_masked);
                    _OMPT_SET_CALLBACK(ompt_callback_sync_region, ompt_callback_sync_region);
                    _OMPT_SET_CALLBACK(ompt_callback_lock_init, ompt_callback_mutex);
                    _OMPT_SET_CALLBACK(ompt_callback_lock_destroy, ompt_callback_mutex);
                    _OMPT_SET_CALLBACK(ompt_callback_mutex_acquire, ompt_callback_mutex_acquire);
                    _OMPT_SET_CALLBACK(ompt_callback_mutex_acquired, ompt_callback_mutex);
                    _OMPT_SET_CALLBACK(ompt_callback_nest_lock, ompt_callback_nest_lock);
                    _OMPT_SET_CALLBACK(ompt_callback_flush, ompt_callback_flush);
                    _OMPT_SET_CALLBACK(ompt_callback_cancel, ompt_callback_cancel);
                    _OMPT_SET_CALLBACK(ompt_callback_reduction, ompt_callback_sync_region);
                    _OMPT_SET_CALLBACK(ompt_callback_dispatch, ompt_callback_dispatch);
                    _OMPT_SET_CALLBACK(ompt_callback_error, ompt_callback_error);
          
    if (do_callbacks_emi) {
                      _OMPT_SET_CALLBACK(ompt_callback_target_emi, ompt_callback_target_emi);
                              _OMPT_SET_CALLBACK(ompt_callback_target_data_op_emi, ompt_callback_target_data_op_emi);
                              _OMPT_SET_CALLBACK(ompt_callback_target_submit_emi, ompt_callback_target_submit_emi);
                              _OMPT_SET_CALLBACK(ompt_callback_target_map_emi, ompt_callback_target_map_emi);
                  } else {
                      _OMPT_SET_CALLBACK(ompt_callback_target, ompt_callback_target);
                              _OMPT_SET_CALLBACK(ompt_callback_target_data_op, ompt_callback_target_data_op);
                              _OMPT_SET_CALLBACK(ompt_callback_target_submit, ompt_callback_target_submit);
                              _OMPT_SET_CALLBACK(ompt_callback_target_map, ompt_callback_target_map);
                  }
    return 1;
}

static ompt_start_tool_result_t _ompt_start_tool_result = {&_ompt_initialize, &_ompt_finalize, (ompt_data_t) {.value=0} };

ompt_start_tool_result_t* ompt_start_tool(unsigned int omp_version, const char* runtime_version) {
    (void) runtime_version;
    _ompt_start_tool_result.tool_data.value = omp_version;
    return &_ompt_start_tool_result;
}
