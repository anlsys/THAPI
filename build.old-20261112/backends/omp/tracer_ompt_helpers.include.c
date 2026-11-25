
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
