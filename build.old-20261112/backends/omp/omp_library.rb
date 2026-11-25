require 'ffi'
module FFI

  class OMPEnum < Enum
  end
  class OMPBitmask < Bitmask
    def default=(default)
      @default = default
    end

    def []
      if @default && query.size == 1
        if query[0] == 0
          return @default
        elsif query[0] == @default
          return 0
        end
      end
      super
    end

    def to_native(query, ctx)
      return 0 if query.nil?
      flat_query = [query].flatten
      return 0 if flat_query.size == 1 && query[0] == @default
      super
    end

    def from_native(val, ctx)
      return [@default] if val == 0 && @default
      super
    end
  end
  module Library
    def ompbitmask(*args)
      generic_enum(FFI::OMPBitmask, *args)
    end
    def ompenum(*args)
      generic_enum(FFI::OMPEnum, *args)
    end
  end

  class Pointer
    def to_s
      "0x%016x" % address
    end
  end
end

module OMP
  extend FFI::Library

  OMPTCallbacks = ompenum :ompt_callbacks_t,
    [ :ompt_callback_thread_begin, 1,
      :ompt_callback_thread_end, 2,
      :ompt_callback_parallel_begin, 3,
      :ompt_callback_parallel_end, 4,
      :ompt_callback_task_create, 5,
      :ompt_callback_task_schedule, 6,
      :ompt_callback_implicit_task, 7,
      :ompt_callback_target, 8,
      :ompt_callback_target_data_op, 9,
      :ompt_callback_target_submit, 10,
      :ompt_callback_control_tool, 11,
      :ompt_callback_device_initialize, 12,
      :ompt_callback_device_finalize, 13,
      :ompt_callback_device_load, 14,
      :ompt_callback_device_unload, 15,
      :ompt_callback_sync_region_wait, 16,
      :ompt_callback_mutex_released, 17,
      :ompt_callback_dependences, 18,
      :ompt_callback_task_dependence, 19,
      :ompt_callback_work, 20,
      :ompt_callback_masked, 21,
      :ompt_callback_target_map, 22,
      :ompt_callback_sync_region, 23,
      :ompt_callback_lock_init, 24,
      :ompt_callback_lock_destroy, 25,
      :ompt_callback_mutex_acquire, 26,
      :ompt_callback_mutex_acquired, 27,
      :ompt_callback_nest_lock, 28,
      :ompt_callback_flush, 29,
      :ompt_callback_cancel, 30,
      :ompt_callback_reduction, 31,
      :ompt_callback_dispatch, 32,
      :ompt_callback_target_emi, 33,
      :ompt_callback_target_data_op_emi, 34,
      :ompt_callback_target_submit_emi, 35,
      :ompt_callback_target_map_emi, 36,
      :ompt_callback_error, 37 ]

  OMPTRecord = ompenum :ompt_record_t,
    [ :ompt_record_ompt, 1,
      :ompt_record_native, 2,
      :ompt_record_invalid, 3 ]

  OMPTRecordNative = ompenum :ompt_record_native_t,
    [ :ompt_record_native_info, 1,
      :ompt_record_native_event, 2 ]

  OMPTSetResult = ompenum :ompt_set_result_t,
    [ :ompt_set_error, 0,
      :ompt_set_never, 1,
      :ompt_set_impossible, 2,
      :ompt_set_sometimes, 3,
      :ompt_set_sometimes_paired, 4,
      :ompt_set_always, 5 ]

  OMPTThread = ompenum :ompt_thread_t,
    [ :ompt_thread_initial, 1,
      :ompt_thread_worker, 2,
      :ompt_thread_other, 3,
      :ompt_thread_unknown, 4 ]

  OMPTScopeEndpoint = ompenum :ompt_scope_endpoint_t,
    [ :ompt_scope_begin, 1,
      :ompt_scope_end, 2,
      :ompt_scope_beginend, 3 ]

  OMPTDispatch = ompenum :ompt_dispatch_t,
    [ :ompt_dispatch_iteration, 1,
      :ompt_dispatch_section, 2,
      :ompt_dispatch_ws_loop_chunk, 3,
      :ompt_dispatch_taskloop_chunk, 4,
      :ompt_dispatch_distribute_chunk, 5 ]

  OMPTSyncRegion = ompenum :ompt_sync_region_t,
    [ :ompt_sync_region_barrier, 1,
      :ompt_sync_region_barrier_implicit, 2,
      :ompt_sync_region_barrier_explicit, 3,
      :ompt_sync_region_barrier_implementation, 4,
      :ompt_sync_region_taskwait, 5,
      :ompt_sync_region_taskgroup, 6,
      :ompt_sync_region_reduction, 7,
      :ompt_sync_region_barrier_implicit_workshare, 8,
      :ompt_sync_region_barrier_implicit_parallel, 9,
      :ompt_sync_region_barrier_teams, 10 ]

  OMPTTargetDataOp = ompenum :ompt_target_data_op_t,
    [ :ompt_target_data_alloc, 1,
      :ompt_target_data_transfer_to_device, 2,
      :ompt_target_data_transfer_from_device, 3,
      :ompt_target_data_delete, 4,
      :ompt_target_data_associate, 5,
      :ompt_target_data_disassociate, 6,
      :ompt_target_data_alloc_async, 17,
      :ompt_target_data_transfer_to_device_async, 18,
      :ompt_target_data_transfer_from_device_async, 19,
      :ompt_target_data_delete_async, 20 ]

  OMPTWork = ompenum :ompt_work_t,
    [ :ompt_work_loop, 1,
      :ompt_work_sections, 2,
      :ompt_work_single_executor, 3,
      :ompt_work_single_other, 4,
      :ompt_work_workshare, 5,
      :ompt_work_distribute, 6,
      :ompt_work_taskloop, 7,
      :ompt_work_scope, 8,
      :ompt_work_loop_static, 10,
      :ompt_work_loop_dynamic, 11,
      :ompt_work_loop_guided, 12,
      :ompt_work_loop_other, 13 ]

  OMPTMutex = ompenum :ompt_mutex_t,
    [ :ompt_mutex_lock, 1,
      :ompt_mutex_test_lock, 2,
      :ompt_mutex_nest_lock, 3,
      :ompt_mutex_test_nest_lock, 4,
      :ompt_mutex_critical, 5,
      :ompt_mutex_atomic, 6,
      :ompt_mutex_ordered, 7 ]

  OMPTNativeMonFlag = ompbitmask :ompt_native_mon_flag_t,
    [ :ompt_native_data_motion_explicit, 0,
      :ompt_native_data_motion_implicit, 1,
      :ompt_native_kernel_invocation, 2,
      :ompt_native_kernel_execution, 3,
      :ompt_native_driver, 4,
      :ompt_native_runtime, 5,
      :ompt_native_overhead, 6,
      :ompt_native_idleness, 7 ]
  OMPTNativeMonFlags = OMPTNativeMonFlag
  typedef :ompt_native_mon_flag_t, :ompt_native_mon_flags_t

  OMPTTaskFlag = ompbitmask :ompt_task_flag_t,
    [ :ompt_task_initial, 0,
      :ompt_task_implicit, 1,
      :ompt_task_explicit, 2,
      :ompt_task_target, 3,
      :ompt_task_taskwait, 4,
      :ompt_task_undeferred, 27,
      :ompt_task_untied, 28,
      :ompt_task_final, 29,
      :ompt_task_mergeable, 30,
      :ompt_task_merged, 31 ]
  OMPTTaskFlags = OMPTTaskFlag
  typedef :ompt_task_flag_t, :ompt_task_flags_t

  OMPTTaskStatus = ompenum :ompt_task_status_t,
    [ :ompt_task_complete, 1,
      :ompt_task_yield, 2,
      :ompt_task_cancel, 3,
      :ompt_task_detach, 4,
      :ompt_task_early_fulfill, 5,
      :ompt_task_late_fulfill, 6,
      :ompt_task_switch, 7,
      :ompt_taskwait_complete, 8 ]

  OMPTTarget = ompenum :ompt_target_t,
    [ :ompt_target, 1,
      :ompt_target_enter_data, 2,
      :ompt_target_exit_data, 3,
      :ompt_target_update, 4,
      :ompt_target_nowait, 9,
      :ompt_target_enter_data_nowait, 10,
      :ompt_target_exit_data_nowait, 11,
      :ompt_target_update_nowait, 12 ]

  OMPTParallelFlag = ompbitmask :ompt_parallel_flag_t,
    [ :ompt_parallel_invoker_program, 0,
      :ompt_parallel_invoker_runtime, 1,
      :ompt_parallel_league, 30,
      :ompt_parallel_team, 31 ]
  OMPTParallelFlags = OMPTParallelFlag
  typedef :ompt_parallel_flag_t, :ompt_parallel_flags_t

  OMPTTargetMapFlag = ompbitmask :ompt_target_map_flag_t,
    [ :ompt_target_map_flag_to, 0,
      :ompt_target_map_flag_from, 1,
      :ompt_target_map_flag_alloc, 2,
      :ompt_target_map_flag_release, 3,
      :ompt_target_map_flag_delete, 4,
      :ompt_target_map_flag_implicit, 5,
      :ompt_target_map_flag_always, 6,
      :ompt_target_map_flag_present, 7,
      :ompt_target_map_flag_close, 8,
      :ompt_target_map_flag_shared, 9 ]
  OMPTTargetMapFlags = OMPTTargetMapFlag
  typedef :ompt_target_map_flag_t, :ompt_target_map_flags_t

  OMPTDependenceType = ompenum :ompt_dependence_type_t,
    [ :ompt_dependence_type_in, 1,
      :ompt_dependence_type_out, 2,
      :ompt_dependence_type_inout, 3,
      :ompt_dependence_type_mutexinoutset, 4,
      :ompt_dependence_type_source, 5,
      :ompt_dependence_type_sink, 6,
      :ompt_dependence_type_inoutset, 7 ]

  OMPTSeverity = ompenum :ompt_severity_t,
    [ :ompt_warning, 1,
      :ompt_fatal, 2 ]

  OMPTCancelFlag = ompbitmask :ompt_cancel_flag_t,
    [ :ompt_cancel_parallel, 0,
      :ompt_cancel_sections, 1,
      :ompt_cancel_loop, 2,
      :ompt_cancel_taskgroup, 3,
      :ompt_cancel_activated, 4,
      :ompt_cancel_detected, 5,
      :ompt_cancel_discarded_task, 6 ]
  OMPTCancelFlags = OMPTCancelFlag
  typedef :ompt_cancel_flag_t, :ompt_cancel_flags_t

  OMPTState = ompenum :ompt_state_t,
    [ :ompt_state_work_serial, 0x0,
      :ompt_state_work_parallel, 0x1,
      :ompt_state_work_reduction, 0x2,
      :ompt_state_wait_barrier, 0x10,
      :ompt_state_wait_barrier_implicit_parallel, 0x11,
      :ompt_state_wait_barrier_implicit_workshare, 0x12,
      :ompt_state_wait_barrier_implicit, 0x13,
      :ompt_state_wait_barrier_explicit, 0x14,
      :ompt_state_wait_barrier_implementation, 0x15,
      :ompt_state_wait_barrier_teams, 0x16,
      :ompt_state_wait_taskwait, 0x20,
      :ompt_state_wait_taskgroup, 0x21,
      :ompt_state_wait_mutex, 0x40,
      :ompt_state_wait_lock, 0x41,
      :ompt_state_wait_critical, 0x42,
      :ompt_state_wait_atomic, 0x43,
      :ompt_state_wait_ordered, 0x44,
      :ompt_state_wait_target, 0x80,
      :ompt_state_wait_target_map, 0x81,
      :ompt_state_wait_target_update, 0x82,
      :ompt_state_idle, 0x100,
      :ompt_state_overhead, 0x101,
      :ompt_state_undefined, 0x102 ]

  OMPTFrameFlag = ompbitmask :ompt_frame_flag_t,
    [ :ompt_frame_application, 0,
      :ompt_frame_cfa, 4,
      :ompt_frame_framepointer, 5 ]
  OMPTFrameFlag.default = :ompt_frame_runtime
  # :ompt_frame_stackaddress, 0x30
  OMPTFrameFlags = OMPTFrameFlag
  typedef :ompt_frame_flag_t, :ompt_frame_flags_t

  OMPDScope = ompenum :ompd_scope_t,
    [ :ompd_scope_global, 1,
      :ompd_scope_address_space, 2,
      :ompd_scope_thread, 3,
      :ompd_scope_parallel, 4,
      :ompd_scope_implicit_task, 5,
      :ompd_scope_task, 6 ]

  OMPDRc = ompenum :ompd_rc_t,
    [ :ompd_rc_ok, 0,
      :ompd_rc_unavailable, 1,
      :ompd_rc_stale_handle, 2,
      :ompd_rc_bad_input, 3,
      :ompd_rc_error, 4,
      :ompd_rc_unsupported, 5,
      :ompd_rc_needs_state_tracking, 6,
      :ompd_rc_incompatible, 7,
      :ompd_rc_device_read_error, 8,
      :ompd_rc_device_write_error, 9,
      :ompd_rc_nomem, 10,
      :ompd_rc_incomplete, 11,
      :ompd_rc_callback_error, 12 ]

end
