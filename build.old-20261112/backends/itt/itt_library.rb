require 'ffi'
module FFI

  class ITTStruct < Struct
    def self.enclosing_module
      ITT
    end

    def to_h
      members.zip(values).to_h
    end

    def to_s
      s = "{ "
      s << to_h.each.collect { |k, v|
        if v.kind_of? Array
          "#{k}: [ #{v.join(", ")} ]"
        else
          "#{k}: #{v}"
        end
      }.join(", ")
      s << " }"
      s
    end
  end
  class ITTEnum < Enum
  end
  class ITTUnion < Union
    def self.enclosing_module
      ITT
    end
  end
  class ITTBitmask < Bitmask
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
    def ittbitmask(*args)
      generic_enum(FFI::ITTBitmask, *args)
    end
    def ittenum(*args)
      generic_enum(FFI::ITTEnum, *args)
    end
  end

  class Struct::InlineArray
    def to_s
      s = "[ "
      s << to_a.join(", ")
      s << " ]"
    end
  end

  class Pointer
    def to_s
      "0x%016x" % address
    end
  end
end
module ITT
  extend FFI::Library

ITT::IttCollectionScope = ittenum :__itt_collection_scope,
  [ :__itt_collection_scope_host, 1,
        :__itt_collection_scope_offload, 2,
        :__itt_collection_scope_all, 2147483647 ]
  typedef :uchar, :__itt_pt_region
ITT::IttSuppressMode = ittenum :__itt_suppress_mode_t,
  [ :__itt_unsuppress_range, 0,
        :__itt_suppress_range, 1 ]
ITT::IttCollectionState = ittenum :__itt_collection_state,
  [ :__itt_collection_uninitialized, 0,
        :__itt_collection_init_fail, 1,
        :__itt_collection_collector_absent, 2,
        :__itt_collection_collector_exists, 3,
        :__itt_collection_init_successful, 4 ]
  typedef :pointer, :__itt_model_site

  typedef :pointer, :__itt_model_site_instance

  typedef :pointer, :__itt_model_task

  typedef :pointer, :__itt_model_task_instance

ITT::IttModelDisable = ittenum :__itt_model_disable,
  [ :__itt_model_disable_observation, 0,
        :__itt_model_disable_collection, 1 ]
  typedef :pointer, :__itt_heap_function

  class ITT::IttDomain < FFI::ITTStruct
    layout :flags, :int,
           :nameA, :pointer,
           :nameW, :pointer,
           :extra1, :int,
           :extra2, :pointer,
           :next, :pointer
  end
  typedef ITT::IttDomain.by_value, :__itt_domain

  class ITT::IttId < FFI::ITTStruct
    layout :d1, :uint64,
           :d2, :uint64,
           :d3, :uint64
  end
  typedef ITT::IttId.by_value, :__itt_id

  class ITT::IttStringHandle < FFI::ITTStruct
    layout :strA, :pointer,
           :strW, :pointer,
           :extra1, :int,
           :extra2, :pointer,
           :next, :pointer
  end
  typedef ITT::IttStringHandle.by_value, :__itt_string_handle

  typedef :uint64, :__itt_timestamp
ITT::IttScope = ittenum :__itt_scope,
  [ :__itt_scope_unknown, 0,
        :__itt_scope_global, 1,
        :__itt_scope_track_group, 2,
        :__itt_scope_track, 3,
        :__itt_scope_task, 4,
        :__itt_scope_marker, 5 ]
ITT::IttMetadataType = ittenum :__itt_metadata_type,
  [ :__itt_metadata_unknown, 0,
        :__itt_metadata_u64, 1,
        :__itt_metadata_s64, 2,
        :__itt_metadata_u32, 3,
        :__itt_metadata_s32, 4,
        :__itt_metadata_u16, 5,
        :__itt_metadata_s16, 6,
        :__itt_metadata_float, 7,
        :__itt_metadata_double, 8 ]
ITT::IttRelation = ittenum :__itt_relation,
  [ :__itt_relation_is_unknown, 0,
        :__itt_relation_is_dependent_on, 1,
        :__itt_relation_is_sibling_of, 2,
        :__itt_relation_is_parent_of, 3,
        :__itt_relation_is_continuation_of, 4,
        :__itt_relation_is_child_of, 5,
        :__itt_relation_is_continued_by, 6,
        :__itt_relation_is_predecessor_to, 7 ]
  class ITT::IttClockInfo < FFI::ITTStruct
    layout :clock_freq, :uint64,
           :clock_base, :uint64
  end
  typedef ITT::IttClockInfo.by_value, :__itt_clock_info

  class ITT::IttClockDomain < FFI::ITTStruct
    layout :info, :__itt_clock_info,
           :fn, :pointer,
           :fn_data, :pointer,
           :extra1, :int,
           :extra2, :pointer,
           :next, :pointer
  end
  typedef ITT::IttClockDomain.by_value, :__itt_clock_domain

  typedef :pointer, :__itt_counter

ITT::IttTrackGroupType = ittenum :__itt_track_group_type,
  [ :__itt_track_group_type_normal, 0 ]
  class ITT::IttTrackGroup < FFI::ITTStruct
    layout :name, :pointer,
           :track, :pointer,
           :tgtype, :__itt_track_group_type,
           :extra1, :int,
           :extra2, :pointer,
           :next, :pointer
  end
  typedef ITT::IttTrackGroup.by_value, :__itt_track_group

ITT::IttTrackType = ittenum :__itt_track_type,
  [ :__itt_track_type_normal, 0 ]
  class ITT::IttTrack < FFI::ITTStruct
    layout :name, :pointer,
           :group, :pointer,
           :ttype, :__itt_track_type,
           :extra1, :int,
           :extra2, :pointer,
           :next, :pointer
  end
  typedef ITT::IttTrack.by_value, :__itt_track

  typedef :int, :__itt_event
ITT::IttAvDataType = ittenum :__itt_av_data_type,
  [ :__itt_e_first, 0,
        :__itt_e_char, 0,
        :__itt_e_uchar, 1,
        :__itt_e_int16, 2,
        :__itt_e_uint16, 3,
        :__itt_e_int32, 4,
        :__itt_e_uint32, 5,
        :__itt_e_int64, 6,
        :__itt_e_uint64, 7,
        :__itt_e_float, 8,
        :__itt_e_double, 9,
        :__itt_e_last, 9 ]
ITT::IttModuleType = ittenum :__itt_module_type,
  [ :__itt_module_type_unknown, 0,
        :__itt_module_type_elf, 1,
        :__itt_module_type_coff, 2 ]
ITT::IttSectionType = ittenum :__itt_section_type,
  [ :itt_section_type_unknown, 0,
        :itt_section_type_bss, 1,
        :itt_section_type_data, 2,
        :itt_section_type_text, 3 ]
  class ITT::IttSectionInfo < FFI::ITTStruct
    layout :name, :pointer,
           :type, :__itt_section_type,
           :flags, :size_t,
           :start_addr, :pointer,
           :size, :size_t,
           :file_offset, :size_t
  end
  typedef ITT::IttSectionInfo.by_value, :__itt_section_info

  class ITT::IttModuleObject < FFI::ITTStruct
    layout :version, :uint,
           :module_id, :__itt_id,
           :module_type, :__itt_module_type,
           :module_name, :pointer,
           :module_buffer, :pointer,
           :module_size, :size_t,
           :section_array, :pointer,
           :section_number, :size_t
  end
  typedef ITT::IttModuleObject.by_value, :__itt_module_object

  class ITT::IttHistogram < FFI::ITTStruct
    layout :domain, :pointer,
           :nameA, :pointer,
           :nameW, :pointer,
           :x_type, :__itt_metadata_type,
           :y_type, :__itt_metadata_type,
           :extra1, :int,
           :extra2, :pointer,
           :next, :pointer
  end
  typedef ITT::IttHistogram.by_value, :__itt_histogram

ITT::IttContextType = ittenum :__itt_context_type,
  [ :__itt_context_unknown, 0,
        :__itt_context_nameA, 1,
        :__itt_context_nameW, 2,
        :__itt_context_deviceA, 3,
        :__itt_context_deviceW, 4,
        :__itt_context_unitsA, 5,
        :__itt_context_unitsW, 6,
        :__itt_context_pci_addrA, 7,
        :__itt_context_pci_addrW, 8,
        :__itt_context_tid, 9,
        :__itt_context_max_val, 10,
        :__itt_context_bandwidth_flag, 11,
        :__itt_context_latency_flag, 12,
        :__itt_context_occupancy_flag, 13,
        :__itt_context_on_thread_flag, 14,
        :__itt_context_is_abs_val_flag, 15,
        :__itt_context_cpu_instructions_flag, 16,
        :__itt_context_cpu_cycles_flag, 17 ]
  class ITT::IttContextMetadata < FFI::ITTStruct
    layout :type, :__itt_context_type,
           :value, :pointer
  end
  typedef ITT::IttContextMetadata.by_value, :__itt_context_metadata

  class ITT::IttCounterMetadata < FFI::ITTStruct
    layout :counter, :__itt_counter,
           :type, :__itt_context_type,
           :str_valueA, :pointer,
           :str_valueW, :pointer,
           :value, :uint64,
           :extra1, :int,
           :extra2, :pointer,
           :next, :pointer
  end
  typedef ITT::IttCounterMetadata.by_value, :__itt_counter_metadata

  callback :__itt_pause_ptr__3_0_t,
           [  ],
           :void

  callback :__itt_pause_scoped_ptr__3_0_t,
           [ :__itt_collection_scope ],
           :void

  callback :__itt_resume_ptr__3_0_t,
           [  ],
           :void

  callback :__itt_resume_scoped_ptr__3_0_t,
           [ :__itt_collection_scope ],
           :void

  callback :__itt_detach_ptr__3_0_t,
           [  ],
           :void

  callback :__itt_pt_region_create_ptr__3_0_t,
           [ :pointer ],
           :__itt_pt_region

  callback :__itt_thread_set_name_ptr__3_0_t,
           [ :pointer ],
           :void

  callback :__itt_thread_ignore_ptr__3_0_t,
           [  ],
           :void

  callback :__itt_suppress_push_ptr__3_0_t,
           [ :uint ],
           :void

  callback :__itt_suppress_pop_ptr__3_0_t,
           [  ],
           :void

  callback :__itt_suppress_mark_range_ptr__3_0_t,
           [ :__itt_suppress_mode_t,
             :uint,
             :pointer,
             :size_t ],
           :void

  callback :__itt_suppress_clear_range_ptr__3_0_t,
           [ :__itt_suppress_mode_t,
             :uint,
             :pointer,
             :size_t ],
           :void

  callback :__itt_sync_create_ptr__3_0_t,
           [ :pointer,
             :pointer,
             :pointer,
             :int ],
           :void

  callback :__itt_sync_rename_ptr__3_0_t,
           [ :pointer,
             :pointer ],
           :void

  callback :__itt_sync_destroy_ptr__3_0_t,
           [ :pointer ],
           :void

  callback :__itt_sync_prepare_ptr__3_0_t,
           [ :pointer ],
           :void

  callback :__itt_sync_cancel_ptr__3_0_t,
           [ :pointer ],
           :void

  callback :__itt_sync_acquired_ptr__3_0_t,
           [ :pointer ],
           :void

  callback :__itt_sync_releasing_ptr__3_0_t,
           [ :pointer ],
           :void

  callback :__itt_fsync_prepare_ptr__3_0_t,
           [ :pointer ],
           :void

  callback :__itt_fsync_cancel_ptr__3_0_t,
           [ :pointer ],
           :void

  callback :__itt_fsync_acquired_ptr__3_0_t,
           [ :pointer ],
           :void

  callback :__itt_fsync_releasing_ptr__3_0_t,
           [ :pointer ],
           :void

  callback :__itt_model_site_begin_ptr__3_0_t,
           [ :pointer,
             :pointer,
             :pointer ],
           :void

  callback :__itt_model_site_beginA_ptr__3_0_t,
           [ :pointer ],
           :void

  callback :__itt_model_site_beginAL_ptr__3_0_t,
           [ :pointer,
             :size_t ],
           :void

  callback :__itt_model_site_end_ptr__3_0_t,
           [ :pointer,
             :pointer ],
           :void

  callback :__itt_model_site_end_2_ptr__3_0_t,
           [  ],
           :void

  callback :__itt_model_task_begin_ptr__3_0_t,
           [ :pointer,
             :pointer,
             :pointer ],
           :void

  callback :__itt_model_task_beginA_ptr__3_0_t,
           [ :pointer ],
           :void

  callback :__itt_model_task_beginAL_ptr__3_0_t,
           [ :pointer,
             :size_t ],
           :void

  callback :__itt_model_iteration_taskA_ptr__3_0_t,
           [ :pointer ],
           :void

  callback :__itt_model_iteration_taskAL_ptr__3_0_t,
           [ :pointer,
             :size_t ],
           :void

  callback :__itt_model_task_end_ptr__3_0_t,
           [ :pointer,
             :pointer ],
           :void

  callback :__itt_model_task_end_2_ptr__3_0_t,
           [  ],
           :void

  callback :__itt_model_lock_acquire_ptr__3_0_t,
           [ :pointer ],
           :void

  callback :__itt_model_lock_acquire_2_ptr__3_0_t,
           [ :pointer ],
           :void

  callback :__itt_model_lock_release_ptr__3_0_t,
           [ :pointer ],
           :void

  callback :__itt_model_lock_release_2_ptr__3_0_t,
           [ :pointer ],
           :void

  callback :__itt_model_record_allocation_ptr__3_0_t,
           [ :pointer,
             :size_t ],
           :void

  callback :__itt_model_record_deallocation_ptr__3_0_t,
           [ :pointer ],
           :void

  callback :__itt_model_induction_uses_ptr__3_0_t,
           [ :pointer,
             :size_t ],
           :void

  callback :__itt_model_reduction_uses_ptr__3_0_t,
           [ :pointer,
             :size_t ],
           :void

  callback :__itt_model_observe_uses_ptr__3_0_t,
           [ :pointer,
             :size_t ],
           :void

  callback :__itt_model_clear_uses_ptr__3_0_t,
           [ :pointer ],
           :void

  callback :__itt_model_disable_push_ptr__3_0_t,
           [ :__itt_model_disable ],
           :void

  callback :__itt_model_disable_pop_ptr__3_0_t,
           [  ],
           :void

  callback :__itt_model_aggregate_task_ptr__3_0_t,
           [ :size_t ],
           :void

  callback :__itt_heap_function_create_ptr__3_0_t,
           [ :pointer,
             :pointer ],
           :__itt_heap_function

  callback :__itt_heap_allocate_begin_ptr__3_0_t,
           [ :__itt_heap_function,
             :size_t,
             :int ],
           :void

  callback :__itt_heap_allocate_end_ptr__3_0_t,
           [ :__itt_heap_function,
             :pointer,
             :size_t,
             :int ],
           :void

  callback :__itt_heap_free_begin_ptr__3_0_t,
           [ :__itt_heap_function,
             :pointer ],
           :void

  callback :__itt_heap_free_end_ptr__3_0_t,
           [ :__itt_heap_function,
             :pointer ],
           :void

  callback :__itt_heap_reallocate_begin_ptr__3_0_t,
           [ :__itt_heap_function,
             :pointer,
             :size_t,
             :int ],
           :void

  callback :__itt_heap_reallocate_end_ptr__3_0_t,
           [ :__itt_heap_function,
             :pointer,
             :pointer,
             :size_t,
             :int ],
           :void

  callback :__itt_heap_internal_access_begin_ptr__3_0_t,
           [  ],
           :void

  callback :__itt_heap_internal_access_end_ptr__3_0_t,
           [  ],
           :void

  callback :__itt_heap_record_memory_growth_begin_ptr__3_0_t,
           [  ],
           :void

  callback :__itt_heap_record_memory_growth_end_ptr__3_0_t,
           [  ],
           :void

  callback :__itt_heap_reset_detection_ptr__3_0_t,
           [ :uint ],
           :void

  callback :__itt_heap_record_ptr__3_0_t,
           [ :uint ],
           :void

  callback :__itt_domain_create_ptr__3_0_t,
           [ :pointer ],
           :pointer

  callback :__itt_id_create_ptr__3_0_t,
           [ ITT::IttDomain.ptr,
             :__itt_id ],
           :void

  callback :__itt_id_destroy_ptr__3_0_t,
           [ ITT::IttDomain.ptr,
             :__itt_id ],
           :void

  callback :__itt_string_handle_create_ptr__3_0_t,
           [ :pointer ],
           :pointer

  callback :__itt_get_timestamp_ptr__3_0_t,
           [  ],
           :__itt_timestamp

  callback :__itt_region_begin_ptr__3_0_t,
           [ ITT::IttDomain.ptr,
             :__itt_id,
             :__itt_id,
             ITT::IttStringHandle.ptr ],
           :void

  callback :__itt_region_end_ptr__3_0_t,
           [ ITT::IttDomain.ptr,
             :__itt_id ],
           :void

  callback :__itt_frame_begin_v3_ptr__3_0_t,
           [ ITT::IttDomain.ptr,
             ITT::IttId.ptr ],
           :void

  callback :__itt_frame_end_v3_ptr__3_0_t,
           [ ITT::IttDomain.ptr,
             ITT::IttId.ptr ],
           :void

  callback :__itt_frame_submit_v3_ptr__3_0_t,
           [ ITT::IttDomain.ptr,
             ITT::IttId.ptr,
             :__itt_timestamp,
             :__itt_timestamp ],
           :void

  callback :__itt_task_group_ptr__3_0_t,
           [ ITT::IttDomain.ptr,
             :__itt_id,
             :__itt_id,
             ITT::IttStringHandle.ptr ],
           :void

  callback :__itt_task_begin_ptr__3_0_t,
           [ ITT::IttDomain.ptr,
             :__itt_id,
             :__itt_id,
             ITT::IttStringHandle.ptr ],
           :void

  callback :__itt_task_begin_fn_ptr__3_0_t,
           [ ITT::IttDomain.ptr,
             :__itt_id,
             :__itt_id,
             :pointer ],
           :void

  callback :__itt_task_end_ptr__3_0_t,
           [ ITT::IttDomain.ptr ],
           :void

  callback :__itt_task_begin_overlapped_ptr__3_0_t,
           [ ITT::IttDomain.ptr,
             :__itt_id,
             :__itt_id,
             ITT::IttStringHandle.ptr ],
           :void

  callback :__itt_task_end_overlapped_ptr__3_0_t,
           [ ITT::IttDomain.ptr,
             :__itt_id ],
           :void

  callback :__itt_marker_ptr__3_0_t,
           [ ITT::IttDomain.ptr,
             :__itt_id,
             ITT::IttStringHandle.ptr,
             :__itt_scope ],
           :void

  callback :__itt_formatted_metadata_add_ptr__3_0_t,
           [ ITT::IttDomain.ptr,
             ITT::IttStringHandle.ptr ],
           :void

  callback :__itt_formatted_metadata_add_overlapped_ptr__3_0_t,
           [ ITT::IttDomain.ptr,
             :__itt_id,
             ITT::IttStringHandle.ptr ],
           :void

  callback :__itt_metadata_add_ptr__3_0_t,
           [ ITT::IttDomain.ptr,
             :__itt_id,
             ITT::IttStringHandle.ptr,
             :__itt_metadata_type,
             :size_t,
             :pointer ],
           :void

  callback :__itt_metadata_str_add_ptr__3_0_t,
           [ ITT::IttDomain.ptr,
             :__itt_id,
             ITT::IttStringHandle.ptr,
             :pointer,
             :size_t ],
           :void

  callback :__itt_metadata_add_with_scope_ptr__3_0_t,
           [ ITT::IttDomain.ptr,
             :__itt_scope,
             ITT::IttStringHandle.ptr,
             :__itt_metadata_type,
             :size_t,
             :pointer ],
           :void

  callback :__itt_metadata_str_add_with_scope_ptr__3_0_t,
           [ ITT::IttDomain.ptr,
             :__itt_scope,
             ITT::IttStringHandle.ptr,
             :pointer,
             :size_t ],
           :void

  callback :__itt_relation_add_to_current_ptr__3_0_t,
           [ ITT::IttDomain.ptr,
             :__itt_relation,
             :__itt_id ],
           :void

  callback :__itt_relation_add_ptr__3_0_t,
           [ ITT::IttDomain.ptr,
             :__itt_id,
             :__itt_relation,
             :__itt_id ],
           :void

  callback :__itt_get_clock_info_fn,
           [ ITT::IttClockInfo.ptr,
             :pointer ],
           :void

  callback :__itt_clock_domain_create_ptr__3_0_t,
           [ :__itt_get_clock_info_fn,
             :pointer ],
           :pointer

  callback :__itt_clock_domain_reset_ptr__3_0_t,
           [  ],
           :void

  callback :__itt_id_create_ex_ptr__3_0_t,
           [ ITT::IttDomain.ptr,
             ITT::IttClockDomain.ptr,
             :uint64,
             :__itt_id ],
           :void

  callback :__itt_id_destroy_ex_ptr__3_0_t,
           [ ITT::IttDomain.ptr,
             ITT::IttClockDomain.ptr,
             :uint64,
             :__itt_id ],
           :void

  callback :__itt_task_begin_ex_ptr__3_0_t,
           [ ITT::IttDomain.ptr,
             ITT::IttClockDomain.ptr,
             :uint64,
             :__itt_id,
             :__itt_id,
             ITT::IttStringHandle.ptr ],
           :void

  callback :__itt_task_begin_fn_ex_ptr__3_0_t,
           [ ITT::IttDomain.ptr,
             ITT::IttClockDomain.ptr,
             :uint64,
             :__itt_id,
             :__itt_id,
             :pointer ],
           :void

  callback :__itt_task_end_ex_ptr__3_0_t,
           [ ITT::IttDomain.ptr,
             ITT::IttClockDomain.ptr,
             :uint64 ],
           :void

  callback :__itt_counter_create_ptr__3_0_t,
           [ :pointer,
             :pointer ],
           :__itt_counter

  callback :__itt_counter_inc_ptr__3_0_t,
           [ :__itt_counter ],
           :void

  callback :__itt_counter_inc_delta_ptr__3_0_t,
           [ :__itt_counter,
             :uint64 ],
           :void

  callback :__itt_counter_dec_ptr__3_0_t,
           [ :__itt_counter ],
           :void

  callback :__itt_counter_dec_delta_ptr__3_0_t,
           [ :__itt_counter,
             :uint64 ],
           :void

  callback :__itt_counter_inc_v3_ptr__3_0_t,
           [ ITT::IttDomain.ptr,
             ITT::IttStringHandle.ptr ],
           :void

  callback :__itt_counter_inc_delta_v3_ptr__3_0_t,
           [ ITT::IttDomain.ptr,
             ITT::IttStringHandle.ptr,
             :uint64 ],
           :void

  callback :__itt_counter_dec_v3_ptr__3_0_t,
           [ ITT::IttDomain.ptr,
             ITT::IttStringHandle.ptr ],
           :void

  callback :__itt_counter_dec_delta_v3_ptr__3_0_t,
           [ ITT::IttDomain.ptr,
             ITT::IttStringHandle.ptr,
             :uint64 ],
           :void

  callback :__itt_counter_set_value_ptr__3_0_t,
           [ :__itt_counter,
             :pointer ],
           :void

  callback :__itt_counter_set_value_ex_ptr__3_0_t,
           [ :__itt_counter,
             ITT::IttClockDomain.ptr,
             :uint64,
             :pointer ],
           :void

  callback :__itt_counter_create_typed_ptr__3_0_t,
           [ :pointer,
             :pointer,
             :__itt_metadata_type ],
           :__itt_counter

  callback :__itt_counter_destroy_ptr__3_0_t,
           [ :__itt_counter ],
           :void

  callback :__itt_marker_ex_ptr__3_0_t,
           [ ITT::IttDomain.ptr,
             ITT::IttClockDomain.ptr,
             :uint64,
             :__itt_id,
             ITT::IttStringHandle.ptr,
             :__itt_scope ],
           :void

  callback :__itt_relation_add_to_current_ex_ptr__3_0_t,
           [ ITT::IttDomain.ptr,
             ITT::IttClockDomain.ptr,
             :uint64,
             :__itt_relation,
             :__itt_id ],
           :void

  callback :__itt_relation_add_ex_ptr__3_0_t,
           [ ITT::IttDomain.ptr,
             ITT::IttClockDomain.ptr,
             :uint64,
             :__itt_id,
             :__itt_relation,
             :__itt_id ],
           :void

  callback :__itt_track_group_create_ptr__3_0_t,
           [ ITT::IttStringHandle.ptr,
             :__itt_track_group_type ],
           :pointer

  callback :__itt_track_create_ptr__3_0_t,
           [ ITT::IttTrackGroup.ptr,
             ITT::IttStringHandle.ptr,
             :__itt_track_type ],
           :pointer

  callback :__itt_set_track_ptr__3_0_t,
           [ ITT::IttTrack.ptr ],
           :void

  callback :__itt_event_create_ptr__3_0_t,
           [ :pointer,
             :int ],
           :__itt_event

  callback :__itt_event_start_ptr__3_0_t,
           [ :__itt_event ],
           :int

  callback :__itt_event_end_ptr__3_0_t,
           [ :__itt_event ],
           :int

  callback :__itt_av_save_ptr__3_0_t,
           [ :pointer,
             :int,
             :pointer,
             :int,
             :pointer,
             :int ],
           :int

  callback :__itt_enable_attach_ptr__3_0_t,
           [  ],
           :void

  callback :__itt_module_load_ptr__3_0_t,
           [ :pointer,
             :pointer,
             :pointer ],
           :void

  callback :__itt_module_unload_ptr__3_0_t,
           [ :pointer ],
           :void

  callback :__itt_module_load_with_sections_ptr__3_0_t,
           [ ITT::IttModuleObject.ptr ],
           :void

  callback :__itt_module_unload_with_sections_ptr__3_0_t,
           [ ITT::IttModuleObject.ptr ],
           :void

  callback :__itt_histogram_create_ptr__3_0_t,
           [ ITT::IttDomain.ptr,
             :pointer,
             :__itt_metadata_type,
             :__itt_metadata_type ],
           :pointer

  callback :__itt_histogram_submit_ptr__3_0_t,
           [ ITT::IttHistogram.ptr,
             :size_t,
             :pointer,
             :pointer ],
           :void

  callback :__itt_counter_create_v3_ptr__3_0_t,
           [ ITT::IttDomain.ptr,
             :pointer,
             :__itt_metadata_type ],
           :__itt_counter

  callback :__itt_counter_set_value_v3_ptr__3_0_t,
           [ :__itt_counter,
             :pointer ],
           :void

  callback :__itt_bind_context_metadata_to_counter_ptr__3_0_t,
           [ :__itt_counter,
             :size_t,
             ITT::IttContextMetadata.ptr ],
           :void

end
