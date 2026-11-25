require 'ffi'
module FFI

  class ZEStruct < Struct
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
  class ZEEnum < Enum
  end
  class ZEUnion < Union
  end
  class ZEBitmask < Bitmask
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
    def zebitmask(*args)
      generic_enum(FFI::ZEBitmask, *args)
    end
    def zeenum(*args)
      generic_enum(FFI::ZEEnum, *args)
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
module ZE
  ZE_MAX_IPC_HANDLE_SIZE = 64
  ZE_MAX_UUID_SIZE = 16
  ZE_MAX_DRIVER_UUID_SIZE = 16
  ZE_MAX_EXTENSION_NAME = 256
  ZE_MAX_DEVICE_UUID_SIZE = 16
  ZE_MAX_DEVICE_NAME = 256
  ZE_SUBGROUPSIZE_COUNT = 8
  ZE_MAX_NATIVE_KERNEL_UUID_SIZE = 16
  ZE_MAX_KERNEL_UUID_SIZE = 16
  ZE_MAX_MODULE_UUID_SIZE = 16
  ZE_MAX_DEVICE_LUID_SIZE_EXT = 8
  ZE_MAX_FABRIC_EDGE_MODEL_EXP_SIZE = 256
  ZES_MAX_EXTENSION_NAME = 256
  ZES_STRING_PROPERTY_SIZE = 64
  ZES_MAX_UUID_SIZE = 16
  ZES_MAX_FABRIC_PORT_MODEL_SIZE = 256
  ZES_MAX_FABRIC_LINK_TYPE_SIZE = 256
  ZES_FAN_TEMP_SPEED_PAIR_COUNT = 32
  ZES_MAX_RAS_ERROR_CATEGORY_COUNT = 7
  ZET_MAX_METRIC_GROUP_NAME = 256
  ZET_MAX_METRIC_GROUP_DESCRIPTION = 256
  ZET_MAX_METRIC_NAME = 256
  ZET_MAX_METRIC_DESCRIPTION = 256
  ZET_MAX_METRIC_COMPONENT = 256
  ZET_MAX_METRIC_RESULT_UNITS = 256
  ZET_MAX_METRIC_EXPORT_DATA_ELEMENT_NAME_EXP = 256
  ZET_MAX_METRIC_EXPORT_DATA_ELEMENT_DESCRIPTION_EXP = 256
  ZET_MAX_PROGRAMMABLE_METRICS_ELEMENT_NAME_EXP = 256
  ZET_MAX_PROGRAMMABLE_METRICS_ELEMENT_DESCRIPTION_EXP = 256
  ZET_MAX_METRIC_PROGRAMMABLE_NAME_EXP = 128
  ZET_MAX_METRIC_PROGRAMMABLE_DESCRIPTION_EXP = 128
  ZET_MAX_METRIC_PROGRAMMABLE_COMPONENT_EXP = 128
  ZET_MAX_METRIC_PROGRAMMABLE_PARAMETER_NAME_EXP = 128
  ZET_MAX_VALUE_INFO_CSTRING_EXP = 128
  ZET_MAX_METRIC_PROGRAMMABLE_VALUE_DESCRIPTION_EXP = 128
  ZEL_COMPONENT_STRING_SIZE = 64
  extend FFI::Library

  def self.ZE_MAKE_VERSION(major, minor)
    (major << 16 )|(minor & 0x0000ffff)
  end

  def self.ZE_BIT(i)
    1 << i
  end

  def self.ZE_MAKE_VERSION(major, minor)
    ( major << 16 )|( minor & 0x0000ffff)
  end

  VERSION_CURRENT = ZE_MAKE_VERSION(0, 91)

  def self.ZE_MAJOR_VERSION(ver = VERSION_CURRENT)
    ver >> 16
  end

  def self.ZE_MINOR_VERSION(ver = VERSION_CURRENT)
    ver & 0x0000ffff
  end

  module Handle
    def to_s
      s = '{ data: "'
      s << self[:data].to_a.collect { |v| "\\x%02x" % ((v + 256)%256) }.join
      s << '" }'
    end
  end

  module UUID
    def to_s
      a = self[:id].to_a
      s = "{ id: "
      s << "%02x" % a[15]
      s << "%02x" % a[14]
      s << "%02x" % a[13]
      s << "%02x" % a[12]
      s << "-"
      s << "%02x" % a[11]
      s << "%02x" % a[10]
      s << "-"
      s << "%02x" % a[9]
      s << "%02x" % a[8]
      s << "-"
      s << "%02x" % a[7]
      s << "%02x" % a[6]
      s << "-"
      s << "%02x" % a[5]
      s << "%02x" % a[4]
      s << "%02x" % a[3]
      s << "%02x" % a[2]
      s << "%02x" % a[1]
      s << "%02x" % a[0]
      s << " }"
    end
  end

  module KUUID
    def to_s
      a = self[:kid].to_a
      s = "{ kid: "
      s << "%02x" % a[15]
      s << "%02x" % a[14]
      s << "%02x" % a[13]
      s << "%02x" % a[12]
      s << "-"
      s << "%02x" % a[11]
      s << "%02x" % a[10]
      s << "-"
      s << "%02x" % a[9]
      s << "%02x" % a[8]
      s << "-"
      s << "%02x" % a[7]
      s << "%02x" % a[6]
      s << "-"
      s << "%02x" % a[5]
      s << "%02x" % a[4]
      s << "%02x" % a[3]
      s << "%02x" % a[2]
      s << "%02x" % a[1]
      s << "%02x" % a[0]
      a = self[:mid].to_a
      s << ", mid: "
      s << "%02x" % a[15]
      s << "%02x" % a[14]
      s << "%02x" % a[13]
      s << "%02x" % a[12]
      s << "-"
      s << "%02x" % a[11]
      s << "%02x" % a[10]
      s << "-"
      s << "%02x" % a[9]
      s << "%02x" % a[8]
      s << "-"
      s << "%02x" % a[7]
      s << "%02x" % a[6]
      s << "-"
      s << "%02x" % a[5]
      s << "%02x" % a[4]
      s << "%02x" % a[3]
      s << "%02x" % a[2]
      s << "%02x" % a[1]
      s << "%02x" % a[0]
      s << " }"
    end
  end

  module Version
    def to_s
      "#{self[:major]}.#{self[:minor]}"
    end

    def to_i
      ZE.ZE_MAKE_VERSION(self[:major], self[:minor])
    end
    alias to_int to_i
  end

  typedef :uint8, :ze_bool_t

  typedef :uint8, :ze_rtas_builder_packed_geometry_ext_flags_t

  typedef :uint8, :ze_rtas_builder_packed_instance_ext_flags_t

  typedef :uint8, :ze_rtas_builder_packed_geometry_type_ext_t

  typedef :uint8, :ze_rtas_builder_packed_input_data_format_ext_t

  typedef :uint8, :ze_rtas_builder_packed_geometry_exp_flags_t

  typedef :uint8, :ze_rtas_builder_packed_instance_exp_flags_t

  typedef :uint8, :ze_rtas_builder_packed_geometry_type_exp_t

  typedef :uint8, :ze_rtas_builder_packed_input_data_format_exp_t

  typedef :pointer, :ze_driver_handle_t

  typedef :pointer, :ze_device_handle_t

  typedef :pointer, :ze_context_handle_t

  typedef :pointer, :ze_command_queue_handle_t

  typedef :pointer, :ze_command_list_handle_t

  typedef :pointer, :ze_fence_handle_t

  typedef :pointer, :ze_event_pool_handle_t

  typedef :pointer, :ze_event_handle_t

  typedef :pointer, :ze_image_handle_t

  typedef :pointer, :ze_module_handle_t

  typedef :pointer, :ze_module_build_log_handle_t

  typedef :pointer, :ze_kernel_handle_t

  typedef :pointer, :ze_sampler_handle_t

  typedef :pointer, :ze_physical_mem_handle_t

  typedef :pointer, :ze_fabric_vertex_handle_t

  typedef :pointer, :ze_fabric_edge_handle_t

  ZEResult = zeenum :ze_result_t,
    [ :ZE_RESULT_SUCCESS, 0,
      :ZE_RESULT_NOT_READY, 1,
      :ZE_RESULT_ERROR_DEVICE_LOST, 0x70000001,
      :ZE_RESULT_ERROR_OUT_OF_HOST_MEMORY, 0x70000002,
      :ZE_RESULT_ERROR_OUT_OF_DEVICE_MEMORY, 0x70000003,
      :ZE_RESULT_ERROR_MODULE_BUILD_FAILURE, 0x70000004,
      :ZE_RESULT_ERROR_MODULE_LINK_FAILURE, 0x70000005,
      :ZE_RESULT_ERROR_DEVICE_REQUIRES_RESET, 0x70000006,
      :ZE_RESULT_ERROR_DEVICE_IN_LOW_POWER_STATE, 0x70000007,
      :ZE_RESULT_EXP_ERROR_DEVICE_IS_NOT_VERTEX, 0x7ff00001,
      :ZE_RESULT_EXP_ERROR_VERTEX_IS_NOT_DEVICE, 0x7ff00002,
      :ZE_RESULT_EXP_ERROR_REMOTE_DEVICE, 0x7ff00003,
      :ZE_RESULT_EXP_ERROR_OPERANDS_INCOMPATIBLE, 0x7ff00004,
      :ZE_RESULT_EXP_RTAS_BUILD_RETRY, 0x7ff00005,
      :ZE_RESULT_EXP_RTAS_BUILD_DEFERRED, 0x7ff00006,
      :ZE_RESULT_ERROR_INSUFFICIENT_PERMISSIONS, 0x70010000,
      :ZE_RESULT_ERROR_NOT_AVAILABLE, 0x70010001,
      :ZE_RESULT_ERROR_DEPENDENCY_UNAVAILABLE, 0x70020000,
      :ZE_RESULT_WARNING_DROPPED_DATA, 0x70020001,
      :ZE_RESULT_ERROR_UNINITIALIZED, 0x78000001,
      :ZE_RESULT_ERROR_UNSUPPORTED_VERSION, 0x78000002,
      :ZE_RESULT_ERROR_UNSUPPORTED_FEATURE, 0x78000003,
      :ZE_RESULT_ERROR_INVALID_ARGUMENT, 0x78000004,
      :ZE_RESULT_ERROR_INVALID_NULL_HANDLE, 0x78000005,
      :ZE_RESULT_ERROR_HANDLE_OBJECT_IN_USE, 0x78000006,
      :ZE_RESULT_ERROR_INVALID_NULL_POINTER, 0x78000007,
      :ZE_RESULT_ERROR_INVALID_SIZE, 0x78000008,
      :ZE_RESULT_ERROR_UNSUPPORTED_SIZE, 0x78000009,
      :ZE_RESULT_ERROR_UNSUPPORTED_ALIGNMENT, 0x7800000a,
      :ZE_RESULT_ERROR_INVALID_SYNCHRONIZATION_OBJECT, 0x7800000b,
      :ZE_RESULT_ERROR_INVALID_ENUMERATION, 0x7800000c,
      :ZE_RESULT_ERROR_UNSUPPORTED_ENUMERATION, 0x7800000d,
      :ZE_RESULT_ERROR_UNSUPPORTED_IMAGE_FORMAT, 0x7800000e,
      :ZE_RESULT_ERROR_INVALID_NATIVE_BINARY, 0x7800000f,
      :ZE_RESULT_ERROR_INVALID_GLOBAL_NAME, 0x78000010,
      :ZE_RESULT_ERROR_INVALID_KERNEL_NAME, 0x78000011,
      :ZE_RESULT_ERROR_INVALID_FUNCTION_NAME, 0x78000012,
      :ZE_RESULT_ERROR_INVALID_GROUP_SIZE_DIMENSION, 0x78000013,
      :ZE_RESULT_ERROR_INVALID_GLOBAL_WIDTH_DIMENSION, 0x78000014,
      :ZE_RESULT_ERROR_INVALID_KERNEL_ARGUMENT_INDEX, 0x78000015,
      :ZE_RESULT_ERROR_INVALID_KERNEL_ARGUMENT_SIZE, 0x78000016,
      :ZE_RESULT_ERROR_INVALID_KERNEL_ATTRIBUTE_VALUE, 0x78000017,
      :ZE_RESULT_ERROR_INVALID_MODULE_UNLINKED, 0x78000018,
      :ZE_RESULT_ERROR_INVALID_COMMAND_LIST_TYPE, 0x78000019,
      :ZE_RESULT_ERROR_OVERLAPPING_REGIONS, 0x7800001a,
      :ZE_RESULT_WARNING_ACTION_REQUIRED, 0x7800001b,
      :ZE_RESULT_ERROR_INVALID_KERNEL_HANDLE, 0x7800001c,
      :ZE_RESULT_EXT_RTAS_BUILD_RETRY, 0x7800001d,
      :ZE_RESULT_EXT_RTAS_BUILD_DEFERRED, 0x7800001e,
      :ZE_RESULT_EXT_ERROR_OPERANDS_INCOMPATIBLE, 0x7800001f,
      :ZE_RESULT_ERROR_SURVIVABILITY_MODE_DETECTED, 0x78000020,
      :ZE_RESULT_ERROR_UNKNOWN, 0x7ffffffe,
      :ZE_RESULT_FORCE_UINT32, 0x7fffffff ]

  ZEStructureType = zeenum :ze_structure_type_t,
    [ :ZE_STRUCTURE_TYPE_DRIVER_PROPERTIES, 0x1,
      :ZE_STRUCTURE_TYPE_DRIVER_IPC_PROPERTIES, 0x2,
      :ZE_STRUCTURE_TYPE_DEVICE_PROPERTIES, 0x3,
      :ZE_STRUCTURE_TYPE_DEVICE_COMPUTE_PROPERTIES, 0x4,
      :ZE_STRUCTURE_TYPE_DEVICE_MODULE_PROPERTIES, 0x5,
      :ZE_STRUCTURE_TYPE_COMMAND_QUEUE_GROUP_PROPERTIES, 0x6,
      :ZE_STRUCTURE_TYPE_DEVICE_MEMORY_PROPERTIES, 0x7,
      :ZE_STRUCTURE_TYPE_DEVICE_MEMORY_ACCESS_PROPERTIES, 0x8,
      :ZE_STRUCTURE_TYPE_DEVICE_CACHE_PROPERTIES, 0x9,
      :ZE_STRUCTURE_TYPE_DEVICE_IMAGE_PROPERTIES, 0xa,
      :ZE_STRUCTURE_TYPE_DEVICE_P2P_PROPERTIES, 0xb,
      :ZE_STRUCTURE_TYPE_DEVICE_EXTERNAL_MEMORY_PROPERTIES, 0xc,
      :ZE_STRUCTURE_TYPE_CONTEXT_DESC, 0xd,
      :ZE_STRUCTURE_TYPE_COMMAND_QUEUE_DESC, 0xe,
      :ZE_STRUCTURE_TYPE_COMMAND_LIST_DESC, 0xf,
      :ZE_STRUCTURE_TYPE_EVENT_POOL_DESC, 0x10,
      :ZE_STRUCTURE_TYPE_EVENT_DESC, 0x11,
      :ZE_STRUCTURE_TYPE_FENCE_DESC, 0x12,
      :ZE_STRUCTURE_TYPE_IMAGE_DESC, 0x13,
      :ZE_STRUCTURE_TYPE_IMAGE_PROPERTIES, 0x14,
      :ZE_STRUCTURE_TYPE_DEVICE_MEM_ALLOC_DESC, 0x15,
      :ZE_STRUCTURE_TYPE_HOST_MEM_ALLOC_DESC, 0x16,
      :ZE_STRUCTURE_TYPE_MEMORY_ALLOCATION_PROPERTIES, 0x17,
      :ZE_STRUCTURE_TYPE_EXTERNAL_MEMORY_EXPORT_DESC, 0x18,
      :ZE_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMPORT_FD, 0x19,
      :ZE_STRUCTURE_TYPE_EXTERNAL_MEMORY_EXPORT_FD, 0x1a,
      :ZE_STRUCTURE_TYPE_MODULE_DESC, 0x1b,
      :ZE_STRUCTURE_TYPE_MODULE_PROPERTIES, 0x1c,
      :ZE_STRUCTURE_TYPE_KERNEL_DESC, 0x1d,
      :ZE_STRUCTURE_TYPE_KERNEL_PROPERTIES, 0x1e,
      :ZE_STRUCTURE_TYPE_SAMPLER_DESC, 0x1f,
      :ZE_STRUCTURE_TYPE_PHYSICAL_MEM_DESC, 0x20,
      :ZE_STRUCTURE_TYPE_KERNEL_PREFERRED_GROUP_SIZE_PROPERTIES, 0x21,
      :ZE_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMPORT_WIN32, 0x22,
      :ZE_STRUCTURE_TYPE_EXTERNAL_MEMORY_EXPORT_WIN32, 0x23,
      :ZE_STRUCTURE_TYPE_DEVICE_RAYTRACING_EXT_PROPERTIES, 0x10001,
      :ZE_STRUCTURE_TYPE_RAYTRACING_MEM_ALLOC_EXT_DESC, 0x10002,
      :ZE_STRUCTURE_TYPE_FLOAT_ATOMIC_EXT_PROPERTIES, 0x10003,
      :ZE_STRUCTURE_TYPE_CACHE_RESERVATION_EXT_DESC, 0x10004,
      :ZE_STRUCTURE_TYPE_EU_COUNT_EXT, 0x10005,
      :ZE_STRUCTURE_TYPE_SRGB_EXT_DESC, 0x10006,
      :ZE_STRUCTURE_TYPE_LINKAGE_INSPECTION_EXT_DESC, 0x10007,
      :ZE_STRUCTURE_TYPE_PCI_EXT_PROPERTIES, 0x10008,
      :ZE_STRUCTURE_TYPE_DRIVER_MEMORY_FREE_EXT_PROPERTIES, 0x10009,
      :ZE_STRUCTURE_TYPE_MEMORY_FREE_EXT_DESC, 0x1000a,
      :ZE_STRUCTURE_TYPE_MEMORY_COMPRESSION_HINTS_EXT_DESC, 0x1000b,
      :ZE_STRUCTURE_TYPE_IMAGE_ALLOCATION_EXT_PROPERTIES, 0x1000c,
      :ZE_STRUCTURE_TYPE_DEVICE_LUID_EXT_PROPERTIES, 0x1000d,
      :ZE_STRUCTURE_TYPE_DEVICE_MEMORY_EXT_PROPERTIES, 0x1000e,
      :ZE_STRUCTURE_TYPE_DEVICE_IP_VERSION_EXT, 0x1000f,
      :ZE_STRUCTURE_TYPE_IMAGE_VIEW_PLANAR_EXT_DESC, 0x10010,
      :ZE_STRUCTURE_TYPE_EVENT_QUERY_KERNEL_TIMESTAMPS_EXT_PROPERTIES, 0x10011,
      :ZE_STRUCTURE_TYPE_EVENT_QUERY_KERNEL_TIMESTAMPS_RESULTS_EXT_PROPERTIES, 0x10012,
      :ZE_STRUCTURE_TYPE_KERNEL_MAX_GROUP_SIZE_EXT_PROPERTIES, 0x10013,
      :ZE_STRUCTURE_TYPE_RELAXED_ALLOCATION_LIMITS_EXP_DESC, 0x20001,
      :ZE_STRUCTURE_TYPE_MODULE_PROGRAM_EXP_DESC, 0x20002,
      :ZE_STRUCTURE_TYPE_SCHEDULING_HINT_EXP_PROPERTIES, 0x20003,
      :ZE_STRUCTURE_TYPE_SCHEDULING_HINT_EXP_DESC, 0x20004,
      :ZE_STRUCTURE_TYPE_IMAGE_VIEW_PLANAR_EXP_DESC, 0x20005,
      :ZE_STRUCTURE_TYPE_DEVICE_PROPERTIES_1_2, 0x20006,
      :ZE_STRUCTURE_TYPE_IMAGE_MEMORY_EXP_PROPERTIES, 0x20007,
      :ZE_STRUCTURE_TYPE_POWER_SAVING_HINT_EXP_DESC, 0x20008,
      :ZE_STRUCTURE_TYPE_COPY_BANDWIDTH_EXP_PROPERTIES, 0x20009,
      :ZE_STRUCTURE_TYPE_DEVICE_P2P_BANDWIDTH_EXP_PROPERTIES, 0x2000a,
      :ZE_STRUCTURE_TYPE_FABRIC_VERTEX_EXP_PROPERTIES, 0x2000b,
      :ZE_STRUCTURE_TYPE_FABRIC_EDGE_EXP_PROPERTIES, 0x2000c,
      :ZE_STRUCTURE_TYPE_MEMORY_SUB_ALLOCATIONS_EXP_PROPERTIES, 0x2000d,
      :ZE_STRUCTURE_TYPE_RTAS_BUILDER_EXP_DESC, 0x2000e,
      :ZE_STRUCTURE_TYPE_RTAS_BUILDER_BUILD_OP_EXP_DESC, 0x2000f,
      :ZE_STRUCTURE_TYPE_RTAS_BUILDER_EXP_PROPERTIES, 0x20010,
      :ZE_STRUCTURE_TYPE_RTAS_PARALLEL_OPERATION_EXP_PROPERTIES, 0x20011,
      :ZE_STRUCTURE_TYPE_RTAS_DEVICE_EXP_PROPERTIES, 0x20012,
      :ZE_STRUCTURE_TYPE_RTAS_GEOMETRY_AABBS_EXP_CB_PARAMS, 0x20013,
      :ZE_STRUCTURE_TYPE_COUNTER_BASED_EVENT_POOL_EXP_DESC, 0x20014,
      :ZE_STRUCTURE_TYPE_MUTABLE_COMMAND_LIST_EXP_PROPERTIES, 0x20015,
      :ZE_STRUCTURE_TYPE_MUTABLE_COMMAND_LIST_EXP_DESC, 0x20016,
      :ZE_STRUCTURE_TYPE_MUTABLE_COMMAND_ID_EXP_DESC, 0x20017,
      :ZE_STRUCTURE_TYPE_MUTABLE_COMMANDS_EXP_DESC, 0x20018,
      :ZE_STRUCTURE_TYPE_MUTABLE_KERNEL_ARGUMENT_EXP_DESC, 0x20019,
      :ZE_STRUCTURE_TYPE_MUTABLE_GROUP_COUNT_EXP_DESC, 0x2001a,
      :ZE_STRUCTURE_TYPE_MUTABLE_GROUP_SIZE_EXP_DESC, 0x2001b,
      :ZE_STRUCTURE_TYPE_MUTABLE_GLOBAL_OFFSET_EXP_DESC, 0x2001c,
      :ZE_STRUCTURE_TYPE_PITCHED_ALLOC_DEVICE_EXP_PROPERTIES, 0x2001d,
      :ZE_STRUCTURE_TYPE_BINDLESS_IMAGE_EXP_DESC, 0x2001e,
      :ZE_STRUCTURE_TYPE_PITCHED_IMAGE_EXP_DESC, 0x2001f,
      :ZE_STRUCTURE_TYPE_MUTABLE_GRAPH_ARGUMENT_EXP_DESC, 0x20020,
      :ZE_STRUCTURE_TYPE_INIT_DRIVER_TYPE_DESC, 0x20021,
      :ZE_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_EXT_DESC, 0x20022,
      :ZE_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_WIN32_EXT_DESC, 0x20023,
      :ZE_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_FD_EXT_DESC, 0x20024,
      :ZE_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS_EXT, 0x20025,
      :ZE_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_WAIT_PARAMS_EXT, 0x20026,
      :ZE_STRUCTURE_TYPE_DRIVER_DDI_HANDLES_EXT_PROPERTIES, 0x20027,
      :ZE_STRUCTURE_TYPE_DEVICE_CACHELINE_SIZE_EXT, 0x20028,
      :ZE_STRUCTURE_TYPE_DEVICE_VECTOR_WIDTH_PROPERTIES_EXT, 0x20029,
      :ZE_STRUCTURE_TYPE_RTAS_BUILDER_EXT_DESC, 0x20030,
      :ZE_STRUCTURE_TYPE_RTAS_BUILDER_BUILD_OP_EXT_DESC, 0x20031,
      :ZE_STRUCTURE_TYPE_RTAS_BUILDER_EXT_PROPERTIES, 0x20032,
      :ZE_STRUCTURE_TYPE_RTAS_PARALLEL_OPERATION_EXT_PROPERTIES, 0x20033,
      :ZE_STRUCTURE_TYPE_RTAS_DEVICE_EXT_PROPERTIES, 0x20034,
      :ZE_STRUCTURE_TYPE_RTAS_GEOMETRY_AABBS_EXT_CB_PARAMS, 0x20035,
      :ZE_STRUCTURE_TYPE_FORCE_UINT32, 0x7fffffff ]

  ZEExternalMemoryTypeFlag = zebitmask :ze_external_memory_type_flag_t,
    [ :ZE_EXTERNAL_MEMORY_TYPE_FLAG_OPAQUE_FD, 0,
      :ZE_EXTERNAL_MEMORY_TYPE_FLAG_DMA_BUF, 1,
      :ZE_EXTERNAL_MEMORY_TYPE_FLAG_OPAQUE_WIN32, 2,
      :ZE_EXTERNAL_MEMORY_TYPE_FLAG_OPAQUE_WIN32_KMT, 3,
      :ZE_EXTERNAL_MEMORY_TYPE_FLAG_D3D11_TEXTURE, 4,
      :ZE_EXTERNAL_MEMORY_TYPE_FLAG_D3D11_TEXTURE_KMT, 5,
      :ZE_EXTERNAL_MEMORY_TYPE_FLAG_D3D12_HEAP, 6,
      :ZE_EXTERNAL_MEMORY_TYPE_FLAG_D3D12_RESOURCE, 7 ]
  # :ZE_EXTERNAL_MEMORY_TYPE_FLAG_FORCE_UINT32, 0x7fffffff
  ZEExternalMemoryTypeFlags = ZEExternalMemoryTypeFlag
  typedef :ze_external_memory_type_flag_t, :ze_external_memory_type_flags_t

  ZEBandwidthUnit = zeenum :ze_bandwidth_unit_t,
    [ :ZE_BANDWIDTH_UNIT_UNKNOWN, 0,
      :ZE_BANDWIDTH_UNIT_BYTES_PER_NANOSEC, 1,
      :ZE_BANDWIDTH_UNIT_BYTES_PER_CLOCK, 2,
      :ZE_BANDWIDTH_UNIT_FORCE_UINT32, 0x7fffffff ]

  ZELatencyUnit = zeenum :ze_latency_unit_t,
    [ :ZE_LATENCY_UNIT_UNKNOWN, 0,
      :ZE_LATENCY_UNIT_NANOSEC, 1,
      :ZE_LATENCY_UNIT_CLOCK, 2,
      :ZE_LATENCY_UNIT_HOP, 3,
      :ZE_LATENCY_UNIT_FORCE_UINT32, 0x7fffffff ]

  ZEInitFlag = zebitmask :ze_init_flag_t,
    [ :ZE_INIT_FLAG_GPU_ONLY, 0,
      :ZE_INIT_FLAG_VPU_ONLY, 1 ]
  # :ZE_INIT_FLAG_FORCE_UINT32, 0x7fffffff
  ZEInitFlags = ZEInitFlag
  typedef :ze_init_flag_t, :ze_init_flags_t

  ZEInitDriverTypeFlag = zebitmask :ze_init_driver_type_flag_t,
    [ :ZE_INIT_DRIVER_TYPE_FLAG_GPU, 0,
      :ZE_INIT_DRIVER_TYPE_FLAG_NPU, 1 ]
  # :ZE_INIT_DRIVER_TYPE_FLAG_FORCE_UINT32, 0x7fffffff
  ZEInitDriverTypeFlags = ZEInitDriverTypeFlag
  typedef :ze_init_driver_type_flag_t, :ze_init_driver_type_flags_t

  class ZEApiVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZEApiVersion.by_value, :ze_api_version_t

  ZEIpcPropertyFlag = zebitmask :ze_ipc_property_flag_t,
    [ :ZE_IPC_PROPERTY_FLAG_MEMORY, 0,
      :ZE_IPC_PROPERTY_FLAG_EVENT_POOL, 1 ]
  # :ZE_IPC_PROPERTY_FLAG_FORCE_UINT32, 0x7fffffff
  ZEIpcPropertyFlags = ZEIpcPropertyFlag
  typedef :ze_ipc_property_flag_t, :ze_ipc_property_flags_t

  ZEDeviceType = zeenum :ze_device_type_t,
    [ :ZE_DEVICE_TYPE_GPU, 1,
      :ZE_DEVICE_TYPE_CPU, 2,
      :ZE_DEVICE_TYPE_FPGA, 3,
      :ZE_DEVICE_TYPE_MCA, 4,
      :ZE_DEVICE_TYPE_VPU, 5,
      :ZE_DEVICE_TYPE_FORCE_UINT32, 0x7fffffff ]

  ZEDevicePropertyFlag = zebitmask :ze_device_property_flag_t,
    [ :ZE_DEVICE_PROPERTY_FLAG_INTEGRATED, 0,
      :ZE_DEVICE_PROPERTY_FLAG_SUBDEVICE, 1,
      :ZE_DEVICE_PROPERTY_FLAG_ECC, 2,
      :ZE_DEVICE_PROPERTY_FLAG_ONDEMANDPAGING, 3 ]
  # :ZE_DEVICE_PROPERTY_FLAG_FORCE_UINT32, 0x7fffffff
  ZEDevicePropertyFlags = ZEDevicePropertyFlag
  typedef :ze_device_property_flag_t, :ze_device_property_flags_t

  ZEDeviceModuleFlag = zebitmask :ze_device_module_flag_t,
    [ :ZE_DEVICE_MODULE_FLAG_FP16, 0,
      :ZE_DEVICE_MODULE_FLAG_FP64, 1,
      :ZE_DEVICE_MODULE_FLAG_INT64_ATOMICS, 2,
      :ZE_DEVICE_MODULE_FLAG_DP4A, 3 ]
  # :ZE_DEVICE_MODULE_FLAG_FORCE_UINT32, 0x7fffffff
  ZEDeviceModuleFlags = ZEDeviceModuleFlag
  typedef :ze_device_module_flag_t, :ze_device_module_flags_t

  ZEDeviceFpFlag = zebitmask :ze_device_fp_flag_t,
    [ :ZE_DEVICE_FP_FLAG_DENORM, 0,
      :ZE_DEVICE_FP_FLAG_INF_NAN, 1,
      :ZE_DEVICE_FP_FLAG_ROUND_TO_NEAREST, 2,
      :ZE_DEVICE_FP_FLAG_ROUND_TO_ZERO, 3,
      :ZE_DEVICE_FP_FLAG_ROUND_TO_INF, 4,
      :ZE_DEVICE_FP_FLAG_FMA, 5,
      :ZE_DEVICE_FP_FLAG_ROUNDED_DIVIDE_SQRT, 6,
      :ZE_DEVICE_FP_FLAG_SOFT_FLOAT, 7 ]
  # :ZE_DEVICE_FP_FLAG_FORCE_UINT32, 0x7fffffff
  ZEDeviceFpFlags = ZEDeviceFpFlag
  typedef :ze_device_fp_flag_t, :ze_device_fp_flags_t

  ZECommandQueueGroupPropertyFlag = zebitmask :ze_command_queue_group_property_flag_t,
    [ :ZE_COMMAND_QUEUE_GROUP_PROPERTY_FLAG_COMPUTE, 0,
      :ZE_COMMAND_QUEUE_GROUP_PROPERTY_FLAG_COPY, 1,
      :ZE_COMMAND_QUEUE_GROUP_PROPERTY_FLAG_COOPERATIVE_KERNELS, 2,
      :ZE_COMMAND_QUEUE_GROUP_PROPERTY_FLAG_METRICS, 3 ]
  # :ZE_COMMAND_QUEUE_GROUP_PROPERTY_FLAG_FORCE_UINT32, 0x7fffffff
  ZECommandQueueGroupPropertyFlags = ZECommandQueueGroupPropertyFlag
  typedef :ze_command_queue_group_property_flag_t, :ze_command_queue_group_property_flags_t

  ZEDeviceMemoryPropertyFlag = zebitmask :ze_device_memory_property_flag_t,
    [ :ZE_DEVICE_MEMORY_PROPERTY_FLAG_TBD, 0 ]
  # :ZE_DEVICE_MEMORY_PROPERTY_FLAG_FORCE_UINT32, 0x7fffffff
  ZEDeviceMemoryPropertyFlags = ZEDeviceMemoryPropertyFlag
  typedef :ze_device_memory_property_flag_t, :ze_device_memory_property_flags_t

  ZEMemoryAccessCapFlag = zebitmask :ze_memory_access_cap_flag_t,
    [ :ZE_MEMORY_ACCESS_CAP_FLAG_RW, 0,
      :ZE_MEMORY_ACCESS_CAP_FLAG_ATOMIC, 1,
      :ZE_MEMORY_ACCESS_CAP_FLAG_CONCURRENT, 2,
      :ZE_MEMORY_ACCESS_CAP_FLAG_CONCURRENT_ATOMIC, 3 ]
  # :ZE_MEMORY_ACCESS_CAP_FLAG_FORCE_UINT32, 0x7fffffff
  ZEMemoryAccessCapFlags = ZEMemoryAccessCapFlag
  typedef :ze_memory_access_cap_flag_t, :ze_memory_access_cap_flags_t

  ZEDeviceCachePropertyFlag = zebitmask :ze_device_cache_property_flag_t,
    [ :ZE_DEVICE_CACHE_PROPERTY_FLAG_USER_CONTROL, 0 ]
  # :ZE_DEVICE_CACHE_PROPERTY_FLAG_FORCE_UINT32, 0x7fffffff
  ZEDeviceCachePropertyFlags = ZEDeviceCachePropertyFlag
  typedef :ze_device_cache_property_flag_t, :ze_device_cache_property_flags_t

  ZEDeviceP2PPropertyFlag = zebitmask :ze_device_p2p_property_flag_t,
    [ :ZE_DEVICE_P2P_PROPERTY_FLAG_ACCESS, 0,
      :ZE_DEVICE_P2P_PROPERTY_FLAG_ATOMICS, 1 ]
  # :ZE_DEVICE_P2P_PROPERTY_FLAG_FORCE_UINT32, 0x7fffffff
  ZEDeviceP2PPropertyFlags = ZEDeviceP2PPropertyFlag
  typedef :ze_device_p2p_property_flag_t, :ze_device_p2p_property_flags_t

  ZEContextFlag = zebitmask :ze_context_flag_t,
    [ :ZE_CONTEXT_FLAG_TBD, 0 ]
  # :ZE_CONTEXT_FLAG_FORCE_UINT32, 0x7fffffff
  ZEContextFlags = ZEContextFlag
  typedef :ze_context_flag_t, :ze_context_flags_t

  ZECommandQueueFlag = zebitmask :ze_command_queue_flag_t,
    [ :ZE_COMMAND_QUEUE_FLAG_EXPLICIT_ONLY, 0,
      :ZE_COMMAND_QUEUE_FLAG_IN_ORDER, 1 ]
  # :ZE_COMMAND_QUEUE_FLAG_FORCE_UINT32, 0x7fffffff
  ZECommandQueueFlags = ZECommandQueueFlag
  typedef :ze_command_queue_flag_t, :ze_command_queue_flags_t

  ZECommandQueueMode = zeenum :ze_command_queue_mode_t,
    [ :ZE_COMMAND_QUEUE_MODE_DEFAULT, 0,
      :ZE_COMMAND_QUEUE_MODE_SYNCHRONOUS, 1,
      :ZE_COMMAND_QUEUE_MODE_ASYNCHRONOUS, 2,
      :ZE_COMMAND_QUEUE_MODE_FORCE_UINT32, 0x7fffffff ]

  ZECommandQueuePriority = zeenum :ze_command_queue_priority_t,
    [ :ZE_COMMAND_QUEUE_PRIORITY_NORMAL, 0,
      :ZE_COMMAND_QUEUE_PRIORITY_PRIORITY_LOW, 1,
      :ZE_COMMAND_QUEUE_PRIORITY_PRIORITY_HIGH, 2,
      :ZE_COMMAND_QUEUE_PRIORITY_FORCE_UINT32, 0x7fffffff ]

  ZECommandListFlag = zebitmask :ze_command_list_flag_t,
    [ :ZE_COMMAND_LIST_FLAG_RELAXED_ORDERING, 0,
      :ZE_COMMAND_LIST_FLAG_MAXIMIZE_THROUGHPUT, 1,
      :ZE_COMMAND_LIST_FLAG_EXPLICIT_ONLY, 2,
      :ZE_COMMAND_LIST_FLAG_IN_ORDER, 3,
      :ZE_COMMAND_LIST_FLAG_EXP_CLONEABLE, 4 ]
  # :ZE_COMMAND_LIST_FLAG_FORCE_UINT32, 0x7fffffff
  ZECommandListFlags = ZECommandListFlag
  typedef :ze_command_list_flag_t, :ze_command_list_flags_t

  ZEMemoryAdvice = zeenum :ze_memory_advice_t,
    [ :ZE_MEMORY_ADVICE_SET_READ_MOSTLY, 0,
      :ZE_MEMORY_ADVICE_CLEAR_READ_MOSTLY, 1,
      :ZE_MEMORY_ADVICE_SET_PREFERRED_LOCATION, 2,
      :ZE_MEMORY_ADVICE_CLEAR_PREFERRED_LOCATION, 3,
      :ZE_MEMORY_ADVICE_SET_NON_ATOMIC_MOSTLY, 4,
      :ZE_MEMORY_ADVICE_CLEAR_NON_ATOMIC_MOSTLY, 5,
      :ZE_MEMORY_ADVICE_BIAS_CACHED, 6,
      :ZE_MEMORY_ADVICE_BIAS_UNCACHED, 7,
      :ZE_MEMORY_ADVICE_SET_SYSTEM_MEMORY_PREFERRED_LOCATION, 8,
      :ZE_MEMORY_ADVICE_CLEAR_SYSTEM_MEMORY_PREFERRED_LOCATION, 9,
      :ZE_MEMORY_ADVICE_FORCE_UINT32, 0x7fffffff ]

  ZEEventPoolFlag = zebitmask :ze_event_pool_flag_t,
    [ :ZE_EVENT_POOL_FLAG_HOST_VISIBLE, 0,
      :ZE_EVENT_POOL_FLAG_IPC, 1,
      :ZE_EVENT_POOL_FLAG_KERNEL_TIMESTAMP, 2,
      :ZE_EVENT_POOL_FLAG_KERNEL_MAPPED_TIMESTAMP, 3 ]
  # :ZE_EVENT_POOL_FLAG_FORCE_UINT32, 0x7fffffff
  ZEEventPoolFlags = ZEEventPoolFlag
  typedef :ze_event_pool_flag_t, :ze_event_pool_flags_t

  ZEEventScopeFlag = zebitmask :ze_event_scope_flag_t,
    [ :ZE_EVENT_SCOPE_FLAG_SUBDEVICE, 0,
      :ZE_EVENT_SCOPE_FLAG_DEVICE, 1,
      :ZE_EVENT_SCOPE_FLAG_HOST, 2 ]
  # :ZE_EVENT_SCOPE_FLAG_FORCE_UINT32, 0x7fffffff
  ZEEventScopeFlags = ZEEventScopeFlag
  typedef :ze_event_scope_flag_t, :ze_event_scope_flags_t

  ZEFenceFlag = zebitmask :ze_fence_flag_t,
    [ :ZE_FENCE_FLAG_SIGNALED, 0 ]
  # :ZE_FENCE_FLAG_FORCE_UINT32, 0x7fffffff
  ZEFenceFlags = ZEFenceFlag
  typedef :ze_fence_flag_t, :ze_fence_flags_t

  ZEImageFlag = zebitmask :ze_image_flag_t,
    [ :ZE_IMAGE_FLAG_KERNEL_WRITE, 0,
      :ZE_IMAGE_FLAG_BIAS_UNCACHED, 1 ]
  # :ZE_IMAGE_FLAG_FORCE_UINT32, 0x7fffffff
  ZEImageFlags = ZEImageFlag
  typedef :ze_image_flag_t, :ze_image_flags_t

  ZEImageType = zeenum :ze_image_type_t,
    [ :ZE_IMAGE_TYPE_1D, 0,
      :ZE_IMAGE_TYPE_1DARRAY, 1,
      :ZE_IMAGE_TYPE_2D, 2,
      :ZE_IMAGE_TYPE_2DARRAY, 3,
      :ZE_IMAGE_TYPE_3D, 4,
      :ZE_IMAGE_TYPE_BUFFER, 5,
      :ZE_IMAGE_TYPE_FORCE_UINT32, 0x7fffffff ]

  ZEImageFormatLayout = zeenum :ze_image_format_layout_t,
    [ :ZE_IMAGE_FORMAT_LAYOUT_8, 0,
      :ZE_IMAGE_FORMAT_LAYOUT_16, 1,
      :ZE_IMAGE_FORMAT_LAYOUT_32, 2,
      :ZE_IMAGE_FORMAT_LAYOUT_8_8, 3,
      :ZE_IMAGE_FORMAT_LAYOUT_8_8_8_8, 4,
      :ZE_IMAGE_FORMAT_LAYOUT_16_16, 5,
      :ZE_IMAGE_FORMAT_LAYOUT_16_16_16_16, 6,
      :ZE_IMAGE_FORMAT_LAYOUT_32_32, 7,
      :ZE_IMAGE_FORMAT_LAYOUT_32_32_32_32, 8,
      :ZE_IMAGE_FORMAT_LAYOUT_10_10_10_2, 9,
      :ZE_IMAGE_FORMAT_LAYOUT_11_11_10, 10,
      :ZE_IMAGE_FORMAT_LAYOUT_5_6_5, 11,
      :ZE_IMAGE_FORMAT_LAYOUT_5_5_5_1, 12,
      :ZE_IMAGE_FORMAT_LAYOUT_4_4_4_4, 13,
      :ZE_IMAGE_FORMAT_LAYOUT_Y8, 14,
      :ZE_IMAGE_FORMAT_LAYOUT_NV12, 15,
      :ZE_IMAGE_FORMAT_LAYOUT_YUYV, 16,
      :ZE_IMAGE_FORMAT_LAYOUT_VYUY, 17,
      :ZE_IMAGE_FORMAT_LAYOUT_YVYU, 18,
      :ZE_IMAGE_FORMAT_LAYOUT_UYVY, 19,
      :ZE_IMAGE_FORMAT_LAYOUT_AYUV, 20,
      :ZE_IMAGE_FORMAT_LAYOUT_P010, 21,
      :ZE_IMAGE_FORMAT_LAYOUT_Y410, 22,
      :ZE_IMAGE_FORMAT_LAYOUT_P012, 23,
      :ZE_IMAGE_FORMAT_LAYOUT_Y16, 24,
      :ZE_IMAGE_FORMAT_LAYOUT_P016, 25,
      :ZE_IMAGE_FORMAT_LAYOUT_Y216, 26,
      :ZE_IMAGE_FORMAT_LAYOUT_P216, 27,
      :ZE_IMAGE_FORMAT_LAYOUT_P8, 28,
      :ZE_IMAGE_FORMAT_LAYOUT_YUY2, 29,
      :ZE_IMAGE_FORMAT_LAYOUT_A8P8, 30,
      :ZE_IMAGE_FORMAT_LAYOUT_IA44, 31,
      :ZE_IMAGE_FORMAT_LAYOUT_AI44, 32,
      :ZE_IMAGE_FORMAT_LAYOUT_Y416, 33,
      :ZE_IMAGE_FORMAT_LAYOUT_Y210, 34,
      :ZE_IMAGE_FORMAT_LAYOUT_I420, 35,
      :ZE_IMAGE_FORMAT_LAYOUT_YV12, 36,
      :ZE_IMAGE_FORMAT_LAYOUT_400P, 37,
      :ZE_IMAGE_FORMAT_LAYOUT_422H, 38,
      :ZE_IMAGE_FORMAT_LAYOUT_422V, 39,
      :ZE_IMAGE_FORMAT_LAYOUT_444P, 40,
      :ZE_IMAGE_FORMAT_LAYOUT_RGBP, 41,
      :ZE_IMAGE_FORMAT_LAYOUT_BRGP, 42,
      :ZE_IMAGE_FORMAT_LAYOUT_8_8_8, 43,
      :ZE_IMAGE_FORMAT_LAYOUT_16_16_16, 44,
      :ZE_IMAGE_FORMAT_LAYOUT_32_32_32, 45,
      :ZE_IMAGE_FORMAT_LAYOUT_FORCE_UINT32, 0x7fffffff ]

  ZEImageFormatType = zeenum :ze_image_format_type_t,
    [ :ZE_IMAGE_FORMAT_TYPE_UINT, 0,
      :ZE_IMAGE_FORMAT_TYPE_SINT, 1,
      :ZE_IMAGE_FORMAT_TYPE_UNORM, 2,
      :ZE_IMAGE_FORMAT_TYPE_SNORM, 3,
      :ZE_IMAGE_FORMAT_TYPE_FLOAT, 4,
      :ZE_IMAGE_FORMAT_TYPE_FORCE_UINT32, 0x7fffffff ]

  ZEImageFormatSwizzle = zeenum :ze_image_format_swizzle_t,
    [ :ZE_IMAGE_FORMAT_SWIZZLE_R, 0,
      :ZE_IMAGE_FORMAT_SWIZZLE_G, 1,
      :ZE_IMAGE_FORMAT_SWIZZLE_B, 2,
      :ZE_IMAGE_FORMAT_SWIZZLE_A, 3,
      :ZE_IMAGE_FORMAT_SWIZZLE_0, 4,
      :ZE_IMAGE_FORMAT_SWIZZLE_1, 5,
      :ZE_IMAGE_FORMAT_SWIZZLE_X, 6,
      :ZE_IMAGE_FORMAT_SWIZZLE_FORCE_UINT32, 0x7fffffff ]

  ZEImageSamplerFilterFlag = zebitmask :ze_image_sampler_filter_flag_t,
    [ :ZE_IMAGE_SAMPLER_FILTER_FLAG_POINT, 0,
      :ZE_IMAGE_SAMPLER_FILTER_FLAG_LINEAR, 1 ]
  # :ZE_IMAGE_SAMPLER_FILTER_FLAG_FORCE_UINT32, 0x7fffffff
  ZEImageSamplerFilterFlags = ZEImageSamplerFilterFlag
  typedef :ze_image_sampler_filter_flag_t, :ze_image_sampler_filter_flags_t

  ZEDeviceMemAllocFlag = zebitmask :ze_device_mem_alloc_flag_t,
    [ :ZE_DEVICE_MEM_ALLOC_FLAG_BIAS_CACHED, 0,
      :ZE_DEVICE_MEM_ALLOC_FLAG_BIAS_UNCACHED, 1,
      :ZE_DEVICE_MEM_ALLOC_FLAG_BIAS_INITIAL_PLACEMENT, 2 ]
  # :ZE_DEVICE_MEM_ALLOC_FLAG_FORCE_UINT32, 0x7fffffff
  ZEDeviceMemAllocFlags = ZEDeviceMemAllocFlag
  typedef :ze_device_mem_alloc_flag_t, :ze_device_mem_alloc_flags_t

  ZEHostMemAllocFlag = zebitmask :ze_host_mem_alloc_flag_t,
    [ :ZE_HOST_MEM_ALLOC_FLAG_BIAS_CACHED, 0,
      :ZE_HOST_MEM_ALLOC_FLAG_BIAS_UNCACHED, 1,
      :ZE_HOST_MEM_ALLOC_FLAG_BIAS_WRITE_COMBINED, 2,
      :ZE_HOST_MEM_ALLOC_FLAG_BIAS_INITIAL_PLACEMENT, 3 ]
  # :ZE_HOST_MEM_ALLOC_FLAG_FORCE_UINT32, 0x7fffffff
  ZEHostMemAllocFlags = ZEHostMemAllocFlag
  typedef :ze_host_mem_alloc_flag_t, :ze_host_mem_alloc_flags_t

  ZEMemoryType = zeenum :ze_memory_type_t,
    [ :ZE_MEMORY_TYPE_UNKNOWN, 0,
      :ZE_MEMORY_TYPE_HOST, 1,
      :ZE_MEMORY_TYPE_DEVICE, 2,
      :ZE_MEMORY_TYPE_SHARED, 3,
      :ZE_MEMORY_TYPE_FORCE_UINT32, 0x7fffffff ]

  ZEIpcMemoryFlag = zebitmask :ze_ipc_memory_flag_t,
    [ :ZE_IPC_MEMORY_FLAG_BIAS_CACHED, 0,
      :ZE_IPC_MEMORY_FLAG_BIAS_UNCACHED, 1 ]
  # :ZE_IPC_MEMORY_FLAG_FORCE_UINT32, 0x7fffffff
  ZEIpcMemoryFlags = ZEIpcMemoryFlag
  typedef :ze_ipc_memory_flag_t, :ze_ipc_memory_flags_t

  ZEMemoryAtomicAttrExpFlag = zebitmask :ze_memory_atomic_attr_exp_flag_t,
    [ :ZE_MEMORY_ATOMIC_ATTR_EXP_FLAG_NO_ATOMICS, 0,
      :ZE_MEMORY_ATOMIC_ATTR_EXP_FLAG_NO_HOST_ATOMICS, 1,
      :ZE_MEMORY_ATOMIC_ATTR_EXP_FLAG_HOST_ATOMICS, 2,
      :ZE_MEMORY_ATOMIC_ATTR_EXP_FLAG_NO_DEVICE_ATOMICS, 3,
      :ZE_MEMORY_ATOMIC_ATTR_EXP_FLAG_DEVICE_ATOMICS, 4,
      :ZE_MEMORY_ATOMIC_ATTR_EXP_FLAG_NO_SYSTEM_ATOMICS, 5,
      :ZE_MEMORY_ATOMIC_ATTR_EXP_FLAG_SYSTEM_ATOMICS, 6 ]
  # :ZE_MEMORY_ATOMIC_ATTR_EXP_FLAG_FORCE_UINT32, 0x7fffffff
  ZEMemoryAtomicAttrExpFlags = ZEMemoryAtomicAttrExpFlag
  typedef :ze_memory_atomic_attr_exp_flag_t, :ze_memory_atomic_attr_exp_flags_t

  ZEModuleFormat = zeenum :ze_module_format_t,
    [ :ZE_MODULE_FORMAT_IL_SPIRV, 0,
      :ZE_MODULE_FORMAT_NATIVE, 1,
      :ZE_MODULE_FORMAT_FORCE_UINT32, 0x7fffffff ]

  ZEModulePropertyFlag = zebitmask :ze_module_property_flag_t,
    [ :ZE_MODULE_PROPERTY_FLAG_IMPORTS, 0 ]
  # :ZE_MODULE_PROPERTY_FLAG_FORCE_UINT32, 0x7fffffff
  ZEModulePropertyFlags = ZEModulePropertyFlag
  typedef :ze_module_property_flag_t, :ze_module_property_flags_t

  ZEKernelFlag = zebitmask :ze_kernel_flag_t,
    [ :ZE_KERNEL_FLAG_FORCE_RESIDENCY, 0,
      :ZE_KERNEL_FLAG_EXPLICIT_RESIDENCY, 1 ]
  # :ZE_KERNEL_FLAG_FORCE_UINT32, 0x7fffffff
  ZEKernelFlags = ZEKernelFlag
  typedef :ze_kernel_flag_t, :ze_kernel_flags_t

  ZEKernelIndirectAccessFlag = zebitmask :ze_kernel_indirect_access_flag_t,
    [ :ZE_KERNEL_INDIRECT_ACCESS_FLAG_HOST, 0,
      :ZE_KERNEL_INDIRECT_ACCESS_FLAG_DEVICE, 1,
      :ZE_KERNEL_INDIRECT_ACCESS_FLAG_SHARED, 2 ]
  # :ZE_KERNEL_INDIRECT_ACCESS_FLAG_FORCE_UINT32, 0x7fffffff
  ZEKernelIndirectAccessFlags = ZEKernelIndirectAccessFlag
  typedef :ze_kernel_indirect_access_flag_t, :ze_kernel_indirect_access_flags_t

  ZECacheConfigFlag = zebitmask :ze_cache_config_flag_t,
    [ :ZE_CACHE_CONFIG_FLAG_LARGE_SLM, 0,
      :ZE_CACHE_CONFIG_FLAG_LARGE_DATA, 1 ]
  # :ZE_CACHE_CONFIG_FLAG_FORCE_UINT32, 0x7fffffff
  ZECacheConfigFlags = ZECacheConfigFlag
  typedef :ze_cache_config_flag_t, :ze_cache_config_flags_t

  class ZEModuleProgramExpVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZEModuleProgramExpVersion.by_value, :ze_module_program_exp_version_t

  class ZERaytracingExtVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZERaytracingExtVersion.by_value, :ze_raytracing_ext_version_t

  ZEDeviceRaytracingExtFlag = zebitmask :ze_device_raytracing_ext_flag_t,
    [ :ZE_DEVICE_RAYTRACING_EXT_FLAG_RAYQUERY, 0 ]
  # :ZE_DEVICE_RAYTRACING_EXT_FLAG_FORCE_UINT32, 0x7fffffff
  ZEDeviceRaytracingExtFlags = ZEDeviceRaytracingExtFlag
  typedef :ze_device_raytracing_ext_flag_t, :ze_device_raytracing_ext_flags_t

  ZERaytracingMemAllocExtFlag = zebitmask :ze_raytracing_mem_alloc_ext_flag_t,
    [ :ZE_RAYTRACING_MEM_ALLOC_EXT_FLAG_TBD, 0 ]
  # :ZE_RAYTRACING_MEM_ALLOC_EXT_FLAG_FORCE_UINT32, 0x7fffffff
  ZERaytracingMemAllocExtFlags = ZERaytracingMemAllocExtFlag
  typedef :ze_raytracing_mem_alloc_ext_flag_t, :ze_raytracing_mem_alloc_ext_flags_t

  ZESamplerAddressMode = zeenum :ze_sampler_address_mode_t,
    [ :ZE_SAMPLER_ADDRESS_MODE_NONE, 0,
      :ZE_SAMPLER_ADDRESS_MODE_REPEAT, 1,
      :ZE_SAMPLER_ADDRESS_MODE_CLAMP, 2,
      :ZE_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER, 3,
      :ZE_SAMPLER_ADDRESS_MODE_MIRROR, 4,
      :ZE_SAMPLER_ADDRESS_MODE_FORCE_UINT32, 0x7fffffff ]

  ZESamplerFilterMode = zeenum :ze_sampler_filter_mode_t,
    [ :ZE_SAMPLER_FILTER_MODE_NEAREST, 0,
      :ZE_SAMPLER_FILTER_MODE_LINEAR, 1,
      :ZE_SAMPLER_FILTER_MODE_FORCE_UINT32, 0x7fffffff ]

  ZEMemoryAccessAttribute = zeenum :ze_memory_access_attribute_t,
    [ :ZE_MEMORY_ACCESS_ATTRIBUTE_NONE, 0,
      :ZE_MEMORY_ACCESS_ATTRIBUTE_READWRITE, 1,
      :ZE_MEMORY_ACCESS_ATTRIBUTE_READONLY, 2,
      :ZE_MEMORY_ACCESS_ATTRIBUTE_FORCE_UINT32, 0x7fffffff ]

  ZEPhysicalMemFlag = zebitmask :ze_physical_mem_flag_t,
    [ :ZE_PHYSICAL_MEM_FLAG_ALLOCATE_ON_DEVICE, 0,
      :ZE_PHYSICAL_MEM_FLAG_ALLOCATE_ON_HOST, 1 ]
  # :ZE_PHYSICAL_MEM_FLAG_FORCE_UINT32, 0x7fffffff
  ZEPhysicalMemFlags = ZEPhysicalMemFlag
  typedef :ze_physical_mem_flag_t, :ze_physical_mem_flags_t

  class ZEFloatAtomicsExtVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZEFloatAtomicsExtVersion.by_value, :ze_float_atomics_ext_version_t

  ZEDeviceFpAtomicExtFlag = zebitmask :ze_device_fp_atomic_ext_flag_t,
    [ :ZE_DEVICE_FP_ATOMIC_EXT_FLAG_GLOBAL_LOAD_STORE, 0,
      :ZE_DEVICE_FP_ATOMIC_EXT_FLAG_GLOBAL_ADD, 1,
      :ZE_DEVICE_FP_ATOMIC_EXT_FLAG_GLOBAL_MIN_MAX, 2,
      :ZE_DEVICE_FP_ATOMIC_EXT_FLAG_LOCAL_LOAD_STORE, 16,
      :ZE_DEVICE_FP_ATOMIC_EXT_FLAG_LOCAL_ADD, 17,
      :ZE_DEVICE_FP_ATOMIC_EXT_FLAG_LOCAL_MIN_MAX, 18 ]
  # :ZE_DEVICE_FP_ATOMIC_EXT_FLAG_FORCE_UINT32, 0x7fffffff
  ZEDeviceFpAtomicExtFlags = ZEDeviceFpAtomicExtFlag
  typedef :ze_device_fp_atomic_ext_flag_t, :ze_device_fp_atomic_ext_flags_t

  class ZEGlobalOffsetExpVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZEGlobalOffsetExpVersion.by_value, :ze_global_offset_exp_version_t

  class ZERelaxedAllocationLimitsExpVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZERelaxedAllocationLimitsExpVersion.by_value, :ze_relaxed_allocation_limits_exp_version_t

  ZERelaxedAllocationLimitsExpFlag = zebitmask :ze_relaxed_allocation_limits_exp_flag_t,
    [ :ZE_RELAXED_ALLOCATION_LIMITS_EXP_FLAG_MAX_SIZE, 0 ]
  # :ZE_RELAXED_ALLOCATION_LIMITS_EXP_FLAG_FORCE_UINT32, 0x7fffffff
  ZERelaxedAllocationLimitsExpFlags = ZERelaxedAllocationLimitsExpFlag
  typedef :ze_relaxed_allocation_limits_exp_flag_t, :ze_relaxed_allocation_limits_exp_flags_t

  class ZEKernelGetBinaryExpVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZEKernelGetBinaryExpVersion.by_value, :ze_kernel_get_binary_exp_version_t

  class ZEDriverDdiHandlesExtVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZEDriverDdiHandlesExtVersion.by_value, :ze_driver_ddi_handles_ext_version_t

  ZEDriverDdiHandleExtFlag = zebitmask :ze_driver_ddi_handle_ext_flag_t,
    [ :ZE_DRIVER_DDI_HANDLE_EXT_FLAG_DDI_HANDLE_EXT_SUPPORTED, 0 ]
  # :ZE_DRIVER_DDI_HANDLE_EXT_FLAG_FORCE_UINT32, 0x7fffffff
  ZEDriverDdiHandleExtFlags = ZEDriverDdiHandleExtFlag
  typedef :ze_driver_ddi_handle_ext_flag_t, :ze_driver_ddi_handle_ext_flags_t

  class ZEExternalSemaphoreExtVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZEExternalSemaphoreExtVersion.by_value, :ze_external_semaphore_ext_version_t

  typedef :pointer, :ze_external_semaphore_ext_handle_t

  ZEExternalSemaphoreExtFlag = zebitmask :ze_external_semaphore_ext_flag_t,
    [ :ZE_EXTERNAL_SEMAPHORE_EXT_FLAG_OPAQUE_FD, 0,
      :ZE_EXTERNAL_SEMAPHORE_EXT_FLAG_OPAQUE_WIN32, 1,
      :ZE_EXTERNAL_SEMAPHORE_EXT_FLAG_OPAQUE_WIN32_KMT, 2,
      :ZE_EXTERNAL_SEMAPHORE_EXT_FLAG_D3D12_FENCE, 3,
      :ZE_EXTERNAL_SEMAPHORE_EXT_FLAG_D3D11_FENCE, 4,
      :ZE_EXTERNAL_SEMAPHORE_EXT_FLAG_KEYED_MUTEX, 5,
      :ZE_EXTERNAL_SEMAPHORE_EXT_FLAG_KEYED_MUTEX_KMT, 6,
      :ZE_EXTERNAL_SEMAPHORE_EXT_FLAG_VK_TIMELINE_SEMAPHORE_FD, 7,
      :ZE_EXTERNAL_SEMAPHORE_EXT_FLAG_VK_TIMELINE_SEMAPHORE_WIN32, 8 ]
  # :ZE_EXTERNAL_SEMAPHORE_EXT_FLAG_FORCE_UINT32, 0x7fffffff
  ZEExternalSemaphoreExtFlags = ZEExternalSemaphoreExtFlag
  typedef :ze_external_semaphore_ext_flag_t, :ze_external_semaphore_ext_flags_t

  class ZEDeviceCacheLineSizeExtVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZEDeviceCacheLineSizeExtVersion.by_value, :ze_device_cache_line_size_ext_version_t

  class ZERtasBuilderExtVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZERtasBuilderExtVersion.by_value, :ze_rtas_builder_ext_version_t

  ZERtasDeviceExtFlag = zebitmask :ze_rtas_device_ext_flag_t,
    [ :ZE_RTAS_DEVICE_EXT_FLAG_RESERVED, 0 ]
  # :ZE_RTAS_DEVICE_EXT_FLAG_FORCE_UINT32, 0x7fffffff
  ZERtasDeviceExtFlags = ZERtasDeviceExtFlag
  typedef :ze_rtas_device_ext_flag_t, :ze_rtas_device_ext_flags_t

  ZERtasFormatExt = zeenum :ze_rtas_format_ext_t,
    [ :ZE_RTAS_FORMAT_EXT_INVALID, 0x0,
      :ZE_RTAS_FORMAT_EXT_MAX, 0x7ffffffe,
      :ZE_RTAS_FORMAT_EXT_FORCE_UINT32, 0x7fffffff ]

  ZERtasBuilderExtFlag = zebitmask :ze_rtas_builder_ext_flag_t,
    [ :ZE_RTAS_BUILDER_EXT_FLAG_RESERVED, 0 ]
  # :ZE_RTAS_BUILDER_EXT_FLAG_FORCE_UINT32, 0x7fffffff
  ZERtasBuilderExtFlags = ZERtasBuilderExtFlag
  typedef :ze_rtas_builder_ext_flag_t, :ze_rtas_builder_ext_flags_t

  ZERtasParallelOperationExtFlag = zebitmask :ze_rtas_parallel_operation_ext_flag_t,
    [ :ZE_RTAS_PARALLEL_OPERATION_EXT_FLAG_RESERVED, 0 ]
  # :ZE_RTAS_PARALLEL_OPERATION_EXT_FLAG_FORCE_UINT32, 0x7fffffff
  ZERtasParallelOperationExtFlags = ZERtasParallelOperationExtFlag
  typedef :ze_rtas_parallel_operation_ext_flag_t, :ze_rtas_parallel_operation_ext_flags_t

  ZERtasBuilderGeometryExtFlag = zebitmask :ze_rtas_builder_geometry_ext_flag_t,
    [ :ZE_RTAS_BUILDER_GEOMETRY_EXT_FLAG_NON_OPAQUE, 0 ]
  # :ZE_RTAS_BUILDER_GEOMETRY_EXT_FLAG_FORCE_UINT32, 0x7fffffff
  ZERtasBuilderGeometryExtFlags = ZERtasBuilderGeometryExtFlag
  typedef :ze_rtas_builder_geometry_ext_flag_t, :ze_rtas_builder_geometry_ext_flags_t

  ZERtasBuilderInstanceExtFlag = zebitmask :ze_rtas_builder_instance_ext_flag_t,
    [ :ZE_RTAS_BUILDER_INSTANCE_EXT_FLAG_TRIANGLE_CULL_DISABLE, 0,
      :ZE_RTAS_BUILDER_INSTANCE_EXT_FLAG_TRIANGLE_FRONT_COUNTERCLOCKWISE, 1,
      :ZE_RTAS_BUILDER_INSTANCE_EXT_FLAG_TRIANGLE_FORCE_OPAQUE, 2,
      :ZE_RTAS_BUILDER_INSTANCE_EXT_FLAG_TRIANGLE_FORCE_NON_OPAQUE, 3 ]
  # :ZE_RTAS_BUILDER_INSTANCE_EXT_FLAG_FORCE_UINT32, 0x7fffffff
  ZERtasBuilderInstanceExtFlags = ZERtasBuilderInstanceExtFlag
  typedef :ze_rtas_builder_instance_ext_flag_t, :ze_rtas_builder_instance_ext_flags_t

  ZERtasBuilderBuildOpExtFlag = zebitmask :ze_rtas_builder_build_op_ext_flag_t,
    [ :ZE_RTAS_BUILDER_BUILD_OP_EXT_FLAG_COMPACT, 0,
      :ZE_RTAS_BUILDER_BUILD_OP_EXT_FLAG_NO_DUPLICATE_ANYHIT_INVOCATION, 1 ]
  # :ZE_RTAS_BUILDER_BUILD_OP_EXT_FLAG_FORCE_UINT32, 0x7fffffff
  ZERtasBuilderBuildOpExtFlags = ZERtasBuilderBuildOpExtFlag
  typedef :ze_rtas_builder_build_op_ext_flag_t, :ze_rtas_builder_build_op_ext_flags_t

  ZERtasBuilderBuildQualityHintExt = zeenum :ze_rtas_builder_build_quality_hint_ext_t,
    [ :ZE_RTAS_BUILDER_BUILD_QUALITY_HINT_EXT_LOW, 0,
      :ZE_RTAS_BUILDER_BUILD_QUALITY_HINT_EXT_MEDIUM, 1,
      :ZE_RTAS_BUILDER_BUILD_QUALITY_HINT_EXT_HIGH, 2,
      :ZE_RTAS_BUILDER_BUILD_QUALITY_HINT_EXT_FORCE_UINT32, 0x7fffffff ]

  ZERtasBuilderGeometryTypeExt = zeenum :ze_rtas_builder_geometry_type_ext_t,
    [ :ZE_RTAS_BUILDER_GEOMETRY_TYPE_EXT_TRIANGLES, 0,
      :ZE_RTAS_BUILDER_GEOMETRY_TYPE_EXT_QUADS, 1,
      :ZE_RTAS_BUILDER_GEOMETRY_TYPE_EXT_PROCEDURAL, 2,
      :ZE_RTAS_BUILDER_GEOMETRY_TYPE_EXT_INSTANCE, 3,
      :ZE_RTAS_BUILDER_GEOMETRY_TYPE_EXT_FORCE_UINT32, 0x7fffffff ]

  ZERtasBuilderInputDataFormatExt = zeenum :ze_rtas_builder_input_data_format_ext_t,
    [ :ZE_RTAS_BUILDER_INPUT_DATA_FORMAT_EXT_FLOAT3, 0,
      :ZE_RTAS_BUILDER_INPUT_DATA_FORMAT_EXT_FLOAT3X4_COLUMN_MAJOR, 1,
      :ZE_RTAS_BUILDER_INPUT_DATA_FORMAT_EXT_FLOAT3X4_ALIGNED_COLUMN_MAJOR, 2,
      :ZE_RTAS_BUILDER_INPUT_DATA_FORMAT_EXT_FLOAT3X4_ROW_MAJOR, 3,
      :ZE_RTAS_BUILDER_INPUT_DATA_FORMAT_EXT_AABB, 4,
      :ZE_RTAS_BUILDER_INPUT_DATA_FORMAT_EXT_TRIANGLE_INDICES_UINT32, 5,
      :ZE_RTAS_BUILDER_INPUT_DATA_FORMAT_EXT_QUAD_INDICES_UINT32, 6,
      :ZE_RTAS_BUILDER_INPUT_DATA_FORMAT_EXT_FORCE_UINT32, 0x7fffffff ]

  typedef :pointer, :ze_rtas_builder_ext_handle_t

  typedef :pointer, :ze_rtas_parallel_operation_ext_handle_t

  class ZEDeviceVectorSizesExtVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZEDeviceVectorSizesExtVersion.by_value, :ze_device_vector_sizes_ext_version_t

  class ZECacheReservationExtVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZECacheReservationExtVersion.by_value, :ze_cache_reservation_ext_version_t

  ZECacheExtRegion = zeenum :ze_cache_ext_region_t,
    [ :ZE_CACHE_EXT_REGION_ZE_CACHE_REGION_DEFAULT, 0,
      :ZE_CACHE_EXT_REGION_ZE_CACHE_RESERVE_REGION, 1,
      :ZE_CACHE_EXT_REGION_ZE_CACHE_NON_RESERVED_REGION, 2,
      :ZE_CACHE_EXT_REGION_DEFAULT, 0,
      :ZE_CACHE_EXT_REGION_RESERVED, 1,
      :ZE_CACHE_EXT_REGION_NON_RESERVED, 2,
      :ZE_CACHE_EXT_REGION_FORCE_UINT32, 0x7fffffff ]

  class ZEEventQueryTimestampsExpVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZEEventQueryTimestampsExpVersion.by_value, :ze_event_query_timestamps_exp_version_t

  class ZEImageMemoryPropertiesExpVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZEImageMemoryPropertiesExpVersion.by_value, :ze_image_memory_properties_exp_version_t

  class ZEImageViewExtVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZEImageViewExtVersion.by_value, :ze_image_view_ext_version_t

  class ZEImageViewExpVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZEImageViewExpVersion.by_value, :ze_image_view_exp_version_t

  class ZEImageViewPlanarExtVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZEImageViewPlanarExtVersion.by_value, :ze_image_view_planar_ext_version_t

  class ZEImageViewPlanarExpVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZEImageViewPlanarExpVersion.by_value, :ze_image_view_planar_exp_version_t

  class ZESchedulingHintsExpVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZESchedulingHintsExpVersion.by_value, :ze_scheduling_hints_exp_version_t

  ZESchedulingHintExpFlag = zebitmask :ze_scheduling_hint_exp_flag_t,
    [ :ZE_SCHEDULING_HINT_EXP_FLAG_OLDEST_FIRST, 0,
      :ZE_SCHEDULING_HINT_EXP_FLAG_ROUND_ROBIN, 1,
      :ZE_SCHEDULING_HINT_EXP_FLAG_STALL_BASED_ROUND_ROBIN, 2 ]
  # :ZE_SCHEDULING_HINT_EXP_FLAG_FORCE_UINT32, 0x7fffffff
  ZESchedulingHintExpFlags = ZESchedulingHintExpFlag
  typedef :ze_scheduling_hint_exp_flag_t, :ze_scheduling_hint_exp_flags_t

  class ZELinkonceOdrExtVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZELinkonceOdrExtVersion.by_value, :ze_linkonce_odr_ext_version_t

  class ZEPowerSavingHintExpVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZEPowerSavingHintExpVersion.by_value, :ze_power_saving_hint_exp_version_t

  ZEPowerSavingHintType = zeenum :ze_power_saving_hint_type_t,
    [ :ZE_POWER_SAVING_HINT_TYPE_MIN, 0,
      :ZE_POWER_SAVING_HINT_TYPE_MAX, 100,
      :ZE_POWER_SAVING_HINT_TYPE_FORCE_UINT32, 0x7fffffff ]

  class ZESubgroupExtVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZESubgroupExtVersion.by_value, :ze_subgroup_ext_version_t

  class ZEEuCountExtVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZEEuCountExtVersion.by_value, :ze_eu_count_ext_version_t

  class ZEPciPropertiesExtVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZEPciPropertiesExtVersion.by_value, :ze_pci_properties_ext_version_t

  class ZESrgbExtVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZESrgbExtVersion.by_value, :ze_srgb_ext_version_t

  class ZEImageCopyExtVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZEImageCopyExtVersion.by_value, :ze_image_copy_ext_version_t

  class ZEImageQueryAllocPropertiesExtVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZEImageQueryAllocPropertiesExtVersion.by_value, :ze_image_query_alloc_properties_ext_version_t

  class ZELinkageInspectionExtVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZELinkageInspectionExtVersion.by_value, :ze_linkage_inspection_ext_version_t

  ZELinkageInspectionExtFlag = zebitmask :ze_linkage_inspection_ext_flag_t,
    [ :ZE_LINKAGE_INSPECTION_EXT_FLAG_IMPORTS, 0,
      :ZE_LINKAGE_INSPECTION_EXT_FLAG_UNRESOLVABLE_IMPORTS, 1,
      :ZE_LINKAGE_INSPECTION_EXT_FLAG_EXPORTS, 2 ]
  # :ZE_LINKAGE_INSPECTION_EXT_FLAG_FORCE_UINT32, 0x7fffffff
  ZELinkageInspectionExtFlags = ZELinkageInspectionExtFlag
  typedef :ze_linkage_inspection_ext_flag_t, :ze_linkage_inspection_ext_flags_t

  class ZEMemoryCompressionHintsExtVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZEMemoryCompressionHintsExtVersion.by_value, :ze_memory_compression_hints_ext_version_t

  ZEMemoryCompressionHintsExtFlag = zebitmask :ze_memory_compression_hints_ext_flag_t,
    [ :ZE_MEMORY_COMPRESSION_HINTS_EXT_FLAG_COMPRESSED, 0,
      :ZE_MEMORY_COMPRESSION_HINTS_EXT_FLAG_UNCOMPRESSED, 1 ]
  # :ZE_MEMORY_COMPRESSION_HINTS_EXT_FLAG_FORCE_UINT32, 0x7fffffff
  ZEMemoryCompressionHintsExtFlags = ZEMemoryCompressionHintsExtFlag
  typedef :ze_memory_compression_hints_ext_flag_t, :ze_memory_compression_hints_ext_flags_t

  class ZEMemoryFreePoliciesExtVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZEMemoryFreePoliciesExtVersion.by_value, :ze_memory_free_policies_ext_version_t

  ZEDriverMemoryFreePolicyExtFlag = zebitmask :ze_driver_memory_free_policy_ext_flag_t,
    [ :ZE_DRIVER_MEMORY_FREE_POLICY_EXT_FLAG_BLOCKING_FREE, 0,
      :ZE_DRIVER_MEMORY_FREE_POLICY_EXT_FLAG_DEFER_FREE, 1 ]
  # :ZE_DRIVER_MEMORY_FREE_POLICY_EXT_FLAG_FORCE_UINT32, 0x7fffffff
  ZEDriverMemoryFreePolicyExtFlags = ZEDriverMemoryFreePolicyExtFlag
  typedef :ze_driver_memory_free_policy_ext_flag_t, :ze_driver_memory_free_policy_ext_flags_t

  class ZEDeviceLuidExtVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZEDeviceLuidExtVersion.by_value, :ze_device_luid_ext_version_t

  ZEFabricVertexExpType = zeenum :ze_fabric_vertex_exp_type_t,
    [ :ZE_FABRIC_VERTEX_EXP_TYPE_UNKNOWN, 0,
      :ZE_FABRIC_VERTEX_EXP_TYPE_DEVICE, 1,
      :ZE_FABRIC_VERTEX_EXP_TYPE_SUBDEVICE, 2,
      :ZE_FABRIC_VERTEX_EXP_TYPE_SWITCH, 3,
      :ZE_FABRIC_VERTEX_EXP_TYPE_FORCE_UINT32, 0x7fffffff ]

  ZEFabricEdgeExpDuplexity = zeenum :ze_fabric_edge_exp_duplexity_t,
    [ :ZE_FABRIC_EDGE_EXP_DUPLEXITY_UNKNOWN, 0,
      :ZE_FABRIC_EDGE_EXP_DUPLEXITY_HALF_DUPLEX, 1,
      :ZE_FABRIC_EDGE_EXP_DUPLEXITY_FULL_DUPLEX, 2,
      :ZE_FABRIC_EDGE_EXP_DUPLEXITY_FORCE_UINT32, 0x7fffffff ]

  class ZEDeviceMemoryPropertiesExtVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZEDeviceMemoryPropertiesExtVersion.by_value, :ze_device_memory_properties_ext_version_t

  ZEDeviceMemoryExtType = zeenum :ze_device_memory_ext_type_t,
    [ :ZE_DEVICE_MEMORY_EXT_TYPE_HBM, 0,
      :ZE_DEVICE_MEMORY_EXT_TYPE_HBM2, 1,
      :ZE_DEVICE_MEMORY_EXT_TYPE_DDR, 2,
      :ZE_DEVICE_MEMORY_EXT_TYPE_DDR2, 3,
      :ZE_DEVICE_MEMORY_EXT_TYPE_DDR3, 4,
      :ZE_DEVICE_MEMORY_EXT_TYPE_DDR4, 5,
      :ZE_DEVICE_MEMORY_EXT_TYPE_DDR5, 6,
      :ZE_DEVICE_MEMORY_EXT_TYPE_LPDDR, 7,
      :ZE_DEVICE_MEMORY_EXT_TYPE_LPDDR3, 8,
      :ZE_DEVICE_MEMORY_EXT_TYPE_LPDDR4, 9,
      :ZE_DEVICE_MEMORY_EXT_TYPE_LPDDR5, 10,
      :ZE_DEVICE_MEMORY_EXT_TYPE_SRAM, 11,
      :ZE_DEVICE_MEMORY_EXT_TYPE_L1, 12,
      :ZE_DEVICE_MEMORY_EXT_TYPE_L3, 13,
      :ZE_DEVICE_MEMORY_EXT_TYPE_GRF, 14,
      :ZE_DEVICE_MEMORY_EXT_TYPE_SLM, 15,
      :ZE_DEVICE_MEMORY_EXT_TYPE_GDDR4, 16,
      :ZE_DEVICE_MEMORY_EXT_TYPE_GDDR5, 17,
      :ZE_DEVICE_MEMORY_EXT_TYPE_GDDR5X, 18,
      :ZE_DEVICE_MEMORY_EXT_TYPE_GDDR6, 19,
      :ZE_DEVICE_MEMORY_EXT_TYPE_GDDR6X, 20,
      :ZE_DEVICE_MEMORY_EXT_TYPE_GDDR7, 21,
      :ZE_DEVICE_MEMORY_EXT_TYPE_FORCE_UINT32, 0x7fffffff ]

  class ZEBfloat16ConversionsExtVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZEBfloat16ConversionsExtVersion.by_value, :ze_bfloat16_conversions_ext_version_t

  class ZEDeviceIpVersionVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZEDeviceIpVersionVersion.by_value, :ze_device_ip_version_version_t

  class ZEKernelMaxGroupSizePropertiesExtVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZEKernelMaxGroupSizePropertiesExtVersion.by_value, :ze_kernel_max_group_size_properties_ext_version_t

  class ZESubAllocationsExpVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZESubAllocationsExpVersion.by_value, :ze_sub_allocations_exp_version_t

  class ZEEventQueryKernelTimestampsExtVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZEEventQueryKernelTimestampsExtVersion.by_value, :ze_event_query_kernel_timestamps_ext_version_t

  ZEEventQueryKernelTimestampsExtFlag = zebitmask :ze_event_query_kernel_timestamps_ext_flag_t,
    [ :ZE_EVENT_QUERY_KERNEL_TIMESTAMPS_EXT_FLAG_KERNEL, 0,
      :ZE_EVENT_QUERY_KERNEL_TIMESTAMPS_EXT_FLAG_SYNCHRONIZED, 1 ]
  # :ZE_EVENT_QUERY_KERNEL_TIMESTAMPS_EXT_FLAG_FORCE_UINT32, 0x7fffffff
  ZEEventQueryKernelTimestampsExtFlags = ZEEventQueryKernelTimestampsExtFlag
  typedef :ze_event_query_kernel_timestamps_ext_flag_t, :ze_event_query_kernel_timestamps_ext_flags_t

  class ZERtasBuilderExpVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZERtasBuilderExpVersion.by_value, :ze_rtas_builder_exp_version_t

  ZERtasDeviceExpFlag = zebitmask :ze_rtas_device_exp_flag_t,
    [ :ZE_RTAS_DEVICE_EXP_FLAG_RESERVED, 0 ]
  # :ZE_RTAS_DEVICE_EXP_FLAG_FORCE_UINT32, 0x7fffffff
  ZERtasDeviceExpFlags = ZERtasDeviceExpFlag
  typedef :ze_rtas_device_exp_flag_t, :ze_rtas_device_exp_flags_t

  ZERtasFormatExp = zeenum :ze_rtas_format_exp_t,
    [ :ZE_RTAS_FORMAT_EXP_INVALID, 0,
      :ZE_RTAS_FORMAT_EXP_MAX, 0x7ffffffe,
      :ZE_RTAS_FORMAT_EXP_FORCE_UINT32, 0x7fffffff ]

  ZERtasBuilderExpFlag = zebitmask :ze_rtas_builder_exp_flag_t,
    [ :ZE_RTAS_BUILDER_EXP_FLAG_RESERVED, 0 ]
  # :ZE_RTAS_BUILDER_EXP_FLAG_FORCE_UINT32, 0x7fffffff
  ZERtasBuilderExpFlags = ZERtasBuilderExpFlag
  typedef :ze_rtas_builder_exp_flag_t, :ze_rtas_builder_exp_flags_t

  ZERtasParallelOperationExpFlag = zebitmask :ze_rtas_parallel_operation_exp_flag_t,
    [ :ZE_RTAS_PARALLEL_OPERATION_EXP_FLAG_RESERVED, 0 ]
  # :ZE_RTAS_PARALLEL_OPERATION_EXP_FLAG_FORCE_UINT32, 0x7fffffff
  ZERtasParallelOperationExpFlags = ZERtasParallelOperationExpFlag
  typedef :ze_rtas_parallel_operation_exp_flag_t, :ze_rtas_parallel_operation_exp_flags_t

  ZERtasBuilderGeometryExpFlag = zebitmask :ze_rtas_builder_geometry_exp_flag_t,
    [ :ZE_RTAS_BUILDER_GEOMETRY_EXP_FLAG_NON_OPAQUE, 0 ]
  # :ZE_RTAS_BUILDER_GEOMETRY_EXP_FLAG_FORCE_UINT32, 0x7fffffff
  ZERtasBuilderGeometryExpFlags = ZERtasBuilderGeometryExpFlag
  typedef :ze_rtas_builder_geometry_exp_flag_t, :ze_rtas_builder_geometry_exp_flags_t

  ZERtasBuilderInstanceExpFlag = zebitmask :ze_rtas_builder_instance_exp_flag_t,
    [ :ZE_RTAS_BUILDER_INSTANCE_EXP_FLAG_TRIANGLE_CULL_DISABLE, 0,
      :ZE_RTAS_BUILDER_INSTANCE_EXP_FLAG_TRIANGLE_FRONT_COUNTERCLOCKWISE, 1,
      :ZE_RTAS_BUILDER_INSTANCE_EXP_FLAG_TRIANGLE_FORCE_OPAQUE, 2,
      :ZE_RTAS_BUILDER_INSTANCE_EXP_FLAG_TRIANGLE_FORCE_NON_OPAQUE, 3 ]
  # :ZE_RTAS_BUILDER_INSTANCE_EXP_FLAG_FORCE_UINT32, 0x7fffffff
  ZERtasBuilderInstanceExpFlags = ZERtasBuilderInstanceExpFlag
  typedef :ze_rtas_builder_instance_exp_flag_t, :ze_rtas_builder_instance_exp_flags_t

  ZERtasBuilderBuildOpExpFlag = zebitmask :ze_rtas_builder_build_op_exp_flag_t,
    [ :ZE_RTAS_BUILDER_BUILD_OP_EXP_FLAG_COMPACT, 0,
      :ZE_RTAS_BUILDER_BUILD_OP_EXP_FLAG_NO_DUPLICATE_ANYHIT_INVOCATION, 1 ]
  # :ZE_RTAS_BUILDER_BUILD_OP_EXP_FLAG_FORCE_UINT32, 0x7fffffff
  ZERtasBuilderBuildOpExpFlags = ZERtasBuilderBuildOpExpFlag
  typedef :ze_rtas_builder_build_op_exp_flag_t, :ze_rtas_builder_build_op_exp_flags_t

  ZERtasBuilderBuildQualityHintExp = zeenum :ze_rtas_builder_build_quality_hint_exp_t,
    [ :ZE_RTAS_BUILDER_BUILD_QUALITY_HINT_EXP_LOW, 0,
      :ZE_RTAS_BUILDER_BUILD_QUALITY_HINT_EXP_MEDIUM, 1,
      :ZE_RTAS_BUILDER_BUILD_QUALITY_HINT_EXP_HIGH, 2,
      :ZE_RTAS_BUILDER_BUILD_QUALITY_HINT_EXP_FORCE_UINT32, 0x7fffffff ]

  ZERtasBuilderGeometryTypeExp = zeenum :ze_rtas_builder_geometry_type_exp_t,
    [ :ZE_RTAS_BUILDER_GEOMETRY_TYPE_EXP_TRIANGLES, 0,
      :ZE_RTAS_BUILDER_GEOMETRY_TYPE_EXP_QUADS, 1,
      :ZE_RTAS_BUILDER_GEOMETRY_TYPE_EXP_PROCEDURAL, 2,
      :ZE_RTAS_BUILDER_GEOMETRY_TYPE_EXP_INSTANCE, 3,
      :ZE_RTAS_BUILDER_GEOMETRY_TYPE_EXP_FORCE_UINT32, 0x7fffffff ]

  ZERtasBuilderInputDataFormatExp = zeenum :ze_rtas_builder_input_data_format_exp_t,
    [ :ZE_RTAS_BUILDER_INPUT_DATA_FORMAT_EXP_FLOAT3, 0,
      :ZE_RTAS_BUILDER_INPUT_DATA_FORMAT_EXP_FLOAT3X4_COLUMN_MAJOR, 1,
      :ZE_RTAS_BUILDER_INPUT_DATA_FORMAT_EXP_FLOAT3X4_ALIGNED_COLUMN_MAJOR, 2,
      :ZE_RTAS_BUILDER_INPUT_DATA_FORMAT_EXP_FLOAT3X4_ROW_MAJOR, 3,
      :ZE_RTAS_BUILDER_INPUT_DATA_FORMAT_EXP_AABB, 4,
      :ZE_RTAS_BUILDER_INPUT_DATA_FORMAT_EXP_TRIANGLE_INDICES_UINT32, 5,
      :ZE_RTAS_BUILDER_INPUT_DATA_FORMAT_EXP_QUAD_INDICES_UINT32, 6,
      :ZE_RTAS_BUILDER_INPUT_DATA_FORMAT_EXP_FORCE_UINT32, 0x7fffffff ]

  typedef :pointer, :ze_rtas_builder_exp_handle_t

  typedef :pointer, :ze_rtas_parallel_operation_exp_handle_t

  class ZEEventPoolCounterBasedExpVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZEEventPoolCounterBasedExpVersion.by_value, :ze_event_pool_counter_based_exp_version_t

  ZEEventPoolCounterBasedExpFlag = zebitmask :ze_event_pool_counter_based_exp_flag_t,
    [ :ZE_EVENT_POOL_COUNTER_BASED_EXP_FLAG_IMMEDIATE, 0,
      :ZE_EVENT_POOL_COUNTER_BASED_EXP_FLAG_NON_IMMEDIATE, 1 ]
  # :ZE_EVENT_POOL_COUNTER_BASED_EXP_FLAG_FORCE_UINT32, 0x7fffffff
  ZEEventPoolCounterBasedExpFlags = ZEEventPoolCounterBasedExpFlag
  typedef :ze_event_pool_counter_based_exp_flag_t, :ze_event_pool_counter_based_exp_flags_t

  class ZEBindlessImageExpVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZEBindlessImageExpVersion.by_value, :ze_bindless_image_exp_version_t

  ZEImageBindlessExpFlag = zebitmask :ze_image_bindless_exp_flag_t,
    [ :ZE_IMAGE_BINDLESS_EXP_FLAG_BINDLESS, 0,
      :ZE_IMAGE_BINDLESS_EXP_FLAG_SAMPLED_IMAGE, 1 ]
  # :ZE_IMAGE_BINDLESS_EXP_FLAG_FORCE_UINT32, 0x7fffffff
  ZEImageBindlessExpFlags = ZEImageBindlessExpFlag
  typedef :ze_image_bindless_exp_flag_t, :ze_image_bindless_exp_flags_t

  class ZECommandListCloneExpVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZECommandListCloneExpVersion.by_value, :ze_command_list_clone_exp_version_t

  class ZEImmediateCommandListAppendExpVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZEImmediateCommandListAppendExpVersion.by_value, :ze_immediate_command_list_append_exp_version_t

  class ZEMutableCommandListExpVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZEMutableCommandListExpVersion.by_value, :ze_mutable_command_list_exp_version_t

  ZEMutableCommandExpFlag = zebitmask :ze_mutable_command_exp_flag_t,
    [ :ZE_MUTABLE_COMMAND_EXP_FLAG_KERNEL_ARGUMENTS, 0,
      :ZE_MUTABLE_COMMAND_EXP_FLAG_GROUP_COUNT, 1,
      :ZE_MUTABLE_COMMAND_EXP_FLAG_GROUP_SIZE, 2,
      :ZE_MUTABLE_COMMAND_EXP_FLAG_GLOBAL_OFFSET, 3,
      :ZE_MUTABLE_COMMAND_EXP_FLAG_SIGNAL_EVENT, 4,
      :ZE_MUTABLE_COMMAND_EXP_FLAG_WAIT_EVENTS, 5,
      :ZE_MUTABLE_COMMAND_EXP_FLAG_KERNEL_INSTRUCTION, 6,
      :ZE_MUTABLE_COMMAND_EXP_FLAG_GRAPH_ARGUMENTS, 7 ]
  # :ZE_MUTABLE_COMMAND_EXP_FLAG_FORCE_UINT32, 0x7fffffff
  ZEMutableCommandExpFlags = ZEMutableCommandExpFlag
  typedef :ze_mutable_command_exp_flag_t, :ze_mutable_command_exp_flags_t

  ZEMutableCommandListExpFlag = zebitmask :ze_mutable_command_list_exp_flag_t,
    [ :ZE_MUTABLE_COMMAND_LIST_EXP_FLAG_RESERVED, 0 ]
  # :ZE_MUTABLE_COMMAND_LIST_EXP_FLAG_FORCE_UINT32, 0x7fffffff
  ZEMutableCommandListExpFlags = ZEMutableCommandListExpFlag
  typedef :ze_mutable_command_list_exp_flag_t, :ze_mutable_command_list_exp_flags_t

  typedef :pointer, :zet_driver_handle_t

  typedef :pointer, :zet_device_handle_t

  typedef :pointer, :zet_context_handle_t

  typedef :pointer, :zet_command_list_handle_t

  typedef :pointer, :zet_module_handle_t

  typedef :pointer, :zet_kernel_handle_t

  typedef :pointer, :zet_metric_group_handle_t

  typedef :pointer, :zet_metric_handle_t

  typedef :pointer, :zet_metric_streamer_handle_t

  typedef :pointer, :zet_metric_query_pool_handle_t

  typedef :pointer, :zet_metric_query_handle_t

  typedef :pointer, :zet_tracer_exp_handle_t

  typedef :pointer, :zet_debug_session_handle_t

  ZETStructureType = zeenum :zet_structure_type_t,
    [ :ZET_STRUCTURE_TYPE_METRIC_GROUP_PROPERTIES, 0x1,
      :ZET_STRUCTURE_TYPE_METRIC_PROPERTIES, 0x2,
      :ZET_STRUCTURE_TYPE_METRIC_STREAMER_DESC, 0x3,
      :ZET_STRUCTURE_TYPE_METRIC_QUERY_POOL_DESC, 0x4,
      :ZET_STRUCTURE_TYPE_PROFILE_PROPERTIES, 0x5,
      :ZET_STRUCTURE_TYPE_DEVICE_DEBUG_PROPERTIES, 0x6,
      :ZET_STRUCTURE_TYPE_DEBUG_MEMORY_SPACE_DESC, 0x7,
      :ZET_STRUCTURE_TYPE_DEBUG_REGSET_PROPERTIES, 0x8,
      :ZET_STRUCTURE_TYPE_GLOBAL_METRICS_TIMESTAMPS_EXP_PROPERTIES, 0x9,
      :ZET_STRUCTURE_TYPE_METRIC_GLOBAL_TIMESTAMPS_RESOLUTION_EXP, 0x9,
      :ZET_STRUCTURE_TYPE_TRACER_EXP_DESC, 0x10001,
      :ZET_STRUCTURE_TYPE_METRICS_CALCULATE_EXP_DESC, 0x10002,
      :ZET_STRUCTURE_TYPE_METRIC_CALCULATE_EXP_DESC, 0x10002,
      :ZET_STRUCTURE_TYPE_METRIC_PROGRAMMABLE_EXP_PROPERTIES, 0x10003,
      :ZET_STRUCTURE_TYPE_METRIC_PROGRAMMABLE_PARAM_INFO_EXP, 0x10004,
      :ZET_STRUCTURE_TYPE_METRIC_PROGRAMMABLE_PARAM_VALUE_INFO_EXP, 0x10005,
      :ZET_STRUCTURE_TYPE_METRIC_GROUP_TYPE_EXP, 0x10006,
      :ZET_STRUCTURE_TYPE_EXPORT_DMA_EXP_PROPERTIES, 0x10007,
      :ZET_STRUCTURE_TYPE_METRIC_TRACER_EXP_DESC, 0x10008,
      :ZET_STRUCTURE_TYPE_FORCE_UINT32, 0x7fffffff ]

  ZETValueType = zeenum :zet_value_type_t,
    [ :ZET_VALUE_TYPE_UINT32, 0,
      :ZET_VALUE_TYPE_UINT64, 1,
      :ZET_VALUE_TYPE_FLOAT32, 2,
      :ZET_VALUE_TYPE_FLOAT64, 3,
      :ZET_VALUE_TYPE_BOOL8, 4,
      :ZET_VALUE_TYPE_STRING, 5,
      :ZET_VALUE_TYPE_UINT8, 6,
      :ZET_VALUE_TYPE_UINT16, 7,
      :ZET_VALUE_TYPE_FORCE_UINT32, 0x7fffffff ]

  ZETModuleDebugInfoFormat = zeenum :zet_module_debug_info_format_t,
    [ :ZET_MODULE_DEBUG_INFO_FORMAT_ELF_DWARF, 0,
      :ZET_MODULE_DEBUG_INFO_FORMAT_FORCE_UINT32, 0x7fffffff ]

  ZETDeviceDebugPropertyFlag = zebitmask :zet_device_debug_property_flag_t,
    [ :ZET_DEVICE_DEBUG_PROPERTY_FLAG_ATTACH, 0 ]
  # :ZET_DEVICE_DEBUG_PROPERTY_FLAG_FORCE_UINT32, 0x7fffffff
  ZETDeviceDebugPropertyFlags = ZETDeviceDebugPropertyFlag
  typedef :zet_device_debug_property_flag_t, :zet_device_debug_property_flags_t

  ZETDebugEventFlag = zebitmask :zet_debug_event_flag_t,
    [ :ZET_DEBUG_EVENT_FLAG_NEED_ACK, 0 ]
  # :ZET_DEBUG_EVENT_FLAG_FORCE_UINT32, 0x7fffffff
  ZETDebugEventFlags = ZETDebugEventFlag
  typedef :zet_debug_event_flag_t, :zet_debug_event_flags_t

  ZETDebugEventType = zeenum :zet_debug_event_type_t,
    [ :ZET_DEBUG_EVENT_TYPE_INVALID, 0,
      :ZET_DEBUG_EVENT_TYPE_DETACHED, 1,
      :ZET_DEBUG_EVENT_TYPE_PROCESS_ENTRY, 2,
      :ZET_DEBUG_EVENT_TYPE_PROCESS_EXIT, 3,
      :ZET_DEBUG_EVENT_TYPE_MODULE_LOAD, 4,
      :ZET_DEBUG_EVENT_TYPE_MODULE_UNLOAD, 5,
      :ZET_DEBUG_EVENT_TYPE_THREAD_STOPPED, 6,
      :ZET_DEBUG_EVENT_TYPE_THREAD_UNAVAILABLE, 7,
      :ZET_DEBUG_EVENT_TYPE_PAGE_FAULT, 8,
      :ZET_DEBUG_EVENT_TYPE_FORCE_UINT32, 0x7fffffff ]

  ZETDebugDetachReason = zeenum :zet_debug_detach_reason_t,
    [ :ZET_DEBUG_DETACH_REASON_INVALID, 0,
      :ZET_DEBUG_DETACH_REASON_HOST_EXIT, 1,
      :ZET_DEBUG_DETACH_REASON_FORCE_UINT32, 0x7fffffff ]

  ZETDebugPageFaultReason = zeenum :zet_debug_page_fault_reason_t,
    [ :ZET_DEBUG_PAGE_FAULT_REASON_INVALID, 0,
      :ZET_DEBUG_PAGE_FAULT_REASON_MAPPING_ERROR, 1,
      :ZET_DEBUG_PAGE_FAULT_REASON_PERMISSION_ERROR, 2,
      :ZET_DEBUG_PAGE_FAULT_REASON_FORCE_UINT32, 0x7fffffff ]

  ZETDebugMemorySpaceType = zeenum :zet_debug_memory_space_type_t,
    [ :ZET_DEBUG_MEMORY_SPACE_TYPE_DEFAULT, 0,
      :ZET_DEBUG_MEMORY_SPACE_TYPE_SLM, 1,
      :ZET_DEBUG_MEMORY_SPACE_TYPE_ELF, 2,
      :ZET_DEBUG_MEMORY_SPACE_TYPE_FORCE_UINT32, 0x7fffffff ]

  ZETDebugRegsetFlag = zebitmask :zet_debug_regset_flag_t,
    [ :ZET_DEBUG_REGSET_FLAG_READABLE, 0,
      :ZET_DEBUG_REGSET_FLAG_WRITEABLE, 1 ]
  # :ZET_DEBUG_REGSET_FLAG_FORCE_UINT32, 0x7fffffff
  ZETDebugRegsetFlags = ZETDebugRegsetFlag
  typedef :zet_debug_regset_flag_t, :zet_debug_regset_flags_t

  ZETMetricGroupSamplingTypeFlag = zebitmask :zet_metric_group_sampling_type_flag_t,
    [ :ZET_METRIC_GROUP_SAMPLING_TYPE_FLAG_EVENT_BASED, 0,
      :ZET_METRIC_GROUP_SAMPLING_TYPE_FLAG_TIME_BASED, 1,
      :ZET_METRIC_GROUP_SAMPLING_TYPE_FLAG_EXP_TRACER_BASED, 2 ]
  # :ZET_METRIC_GROUP_SAMPLING_TYPE_FLAG_FORCE_UINT32, 0x7fffffff
  ZETMetricGroupSamplingTypeFlags = ZETMetricGroupSamplingTypeFlag
  typedef :zet_metric_group_sampling_type_flag_t, :zet_metric_group_sampling_type_flags_t

  ZETMetricType = zeenum :zet_metric_type_t,
    [ :ZET_METRIC_TYPE_DURATION, 0,
      :ZET_METRIC_TYPE_EVENT, 1,
      :ZET_METRIC_TYPE_EVENT_WITH_RANGE, 2,
      :ZET_METRIC_TYPE_THROUGHPUT, 3,
      :ZET_METRIC_TYPE_TIMESTAMP, 4,
      :ZET_METRIC_TYPE_FLAG, 5,
      :ZET_METRIC_TYPE_RATIO, 6,
      :ZET_METRIC_TYPE_RAW, 7,
      :ZET_METRIC_TYPE_EVENT_EXP_TIMESTAMP, 0x7ffffff9,
      :ZET_METRIC_TYPE_EVENT_EXP_START, 0x7ffffffa,
      :ZET_METRIC_TYPE_EVENT_EXP_END, 0x7ffffffb,
      :ZET_METRIC_TYPE_EVENT_EXP_MONOTONIC_WRAPS_VALUE, 0x7ffffffc,
      :ZET_METRIC_TYPE_EXP_EXPORT_DMA_BUF, 0x7ffffffd,
      :ZET_METRIC_TYPE_IP_EXP, 0x7ffffffe,
      :ZET_METRIC_TYPE_IP, 0x7ffffffe,
      :ZET_METRIC_TYPE_FORCE_UINT32, 0x7fffffff ]

  ZETMetricGroupCalculationType = zeenum :zet_metric_group_calculation_type_t,
    [ :ZET_METRIC_GROUP_CALCULATION_TYPE_METRIC_VALUES, 0,
      :ZET_METRIC_GROUP_CALCULATION_TYPE_MAX_METRIC_VALUES, 1,
      :ZET_METRIC_GROUP_CALCULATION_TYPE_FORCE_UINT32, 0x7fffffff ]

  ZETMetricQueryPoolType = zeenum :zet_metric_query_pool_type_t,
    [ :ZET_METRIC_QUERY_POOL_TYPE_PERFORMANCE, 0,
      :ZET_METRIC_QUERY_POOL_TYPE_EXECUTION, 1,
      :ZET_METRIC_QUERY_POOL_TYPE_FORCE_UINT32, 0x7fffffff ]

  ZETProfileFlag = zebitmask :zet_profile_flag_t,
    [ :ZET_PROFILE_FLAG_REGISTER_REALLOCATION, 0,
      :ZET_PROFILE_FLAG_FREE_REGISTER_INFO, 1 ]
  # :ZET_PROFILE_FLAG_FORCE_UINT32, 0x7fffffff
  ZETProfileFlags = ZETProfileFlag
  typedef :zet_profile_flag_t, :zet_profile_flags_t

  ZETProfileTokenType = zeenum :zet_profile_token_type_t,
    [ :ZET_PROFILE_TOKEN_TYPE_FREE_REGISTER, 0,
      :ZET_PROFILE_TOKEN_TYPE_FORCE_UINT32, 0x7fffffff ]

  class ZETApiTracingExpVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZETApiTracingExpVersion.by_value, :zet_api_tracing_exp_version_t

  class ZETConcurrentMetricGroupsExpVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZETConcurrentMetricGroupsExpVersion.by_value, :zet_concurrent_metric_groups_exp_version_t

  class ZETMetricTracerExpVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZETMetricTracerExpVersion.by_value, :zet_metric_tracer_exp_version_t

  typedef :pointer, :zet_metric_tracer_exp_handle_t

  typedef :pointer, :zet_metric_decoder_exp_handle_t

  ZETMetricGroupTypeExpFlag = zebitmask :zet_metric_group_type_exp_flag_t,
    [ :ZET_METRIC_GROUP_TYPE_EXP_FLAG_EXPORT_DMA_BUF, 0,
      :ZET_METRIC_GROUP_TYPE_EXP_FLAG_USER_CREATED, 1,
      :ZET_METRIC_GROUP_TYPE_EXP_FLAG_OTHER, 2,
      :ZET_METRIC_GROUP_TYPE_EXP_FLAG_MARKER, 3 ]
  # :ZET_METRIC_GROUP_TYPE_EXP_FLAG_FORCE_UINT32, 0x7fffffff
  ZETMetricGroupTypeExpFlags = ZETMetricGroupTypeExpFlag
  typedef :zet_metric_group_type_exp_flag_t, :zet_metric_group_type_exp_flags_t

  class ZETMetricGroupMarkerExpVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZETMetricGroupMarkerExpVersion.by_value, :zet_metric_group_marker_exp_version_t

  class ZETMetricsRuntimeEnableDisableExpVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZETMetricsRuntimeEnableDisableExpVersion.by_value, :zet_metrics_runtime_enable_disable_exp_version_t

  class ZECalculateMultipleMetricsExpVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZECalculateMultipleMetricsExpVersion.by_value, :ze_calculate_multiple_metrics_exp_version_t

  class ZEMetricGlobalTimestampsExpVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZEMetricGlobalTimestampsExpVersion.by_value, :ze_metric_global_timestamps_exp_version_t

  class ZETExportMetricDataExpVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZETExportMetricDataExpVersion.by_value, :zet_export_metric_data_exp_version_t

  class ZETMetricProgrammableExpVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZETMetricProgrammableExpVersion.by_value, :zet_metric_programmable_exp_version_t

  typedef :pointer, :zet_metric_programmable_exp_handle_t

  ZETMetricProgrammableParamTypeExp = zeenum :zet_metric_programmable_param_type_exp_t,
    [ :ZET_METRIC_PROGRAMMABLE_PARAM_TYPE_EXP_DISAGGREGATION, 0,
      :ZET_METRIC_PROGRAMMABLE_PARAM_TYPE_EXP_LATENCY, 1,
      :ZET_METRIC_PROGRAMMABLE_PARAM_TYPE_EXP_NORMALIZATION_UTILIZATION, 2,
      :ZET_METRIC_PROGRAMMABLE_PARAM_TYPE_EXP_NORMALIZATION_AVERAGE, 3,
      :ZET_METRIC_PROGRAMMABLE_PARAM_TYPE_EXP_NORMALIZATION_RATE, 4,
      :ZET_METRIC_PROGRAMMABLE_PARAM_TYPE_EXP_NORMALIZATION_BYTES, 5,
      :ZET_METRIC_PROGRAMMABLE_PARAM_TYPE_EXP_GENERIC, 6,
      :ZET_METRIC_PROGRAMMABLE_PARAM_TYPE_EXP_FORCE_UINT32, 0x7fffffff ]

  ZETValueInfoTypeExp = zeenum :zet_value_info_type_exp_t,
    [ :ZET_VALUE_INFO_TYPE_EXP_UINT32, 0,
      :ZET_VALUE_INFO_TYPE_EXP_UINT64, 1,
      :ZET_VALUE_INFO_TYPE_EXP_FLOAT32, 2,
      :ZET_VALUE_INFO_TYPE_EXP_FLOAT64, 3,
      :ZET_VALUE_INFO_TYPE_EXP_BOOL8, 4,
      :ZET_VALUE_INFO_TYPE_EXP_UINT8, 5,
      :ZET_VALUE_INFO_TYPE_EXP_UINT16, 6,
      :ZET_VALUE_INFO_TYPE_EXP_UINT64_RANGE, 7,
      :ZET_VALUE_INFO_TYPE_EXP_FLOAT64_RANGE, 8,
      :ZET_VALUE_INFO_TYPE_EXP_FORCE_UINT32, 0x7fffffff ]

  typedef :pointer, :zes_driver_handle_t

  typedef :pointer, :zes_device_handle_t

  typedef :pointer, :zes_sched_handle_t

  typedef :pointer, :zes_perf_handle_t

  typedef :pointer, :zes_pwr_handle_t

  typedef :pointer, :zes_freq_handle_t

  typedef :pointer, :zes_engine_handle_t

  typedef :pointer, :zes_standby_handle_t

  typedef :pointer, :zes_firmware_handle_t

  typedef :pointer, :zes_mem_handle_t

  typedef :pointer, :zes_fabric_port_handle_t

  typedef :pointer, :zes_temp_handle_t

  typedef :pointer, :zes_psu_handle_t

  typedef :pointer, :zes_fan_handle_t

  typedef :pointer, :zes_led_handle_t

  typedef :pointer, :zes_ras_handle_t

  typedef :pointer, :zes_diag_handle_t

  typedef :pointer, :zes_overclock_handle_t

  typedef :pointer, :zes_vf_handle_t

  ZESStructureType = zeenum :zes_structure_type_t,
    [ :ZES_STRUCTURE_TYPE_DEVICE_PROPERTIES, 0x1,
      :ZES_STRUCTURE_TYPE_PCI_PROPERTIES, 0x2,
      :ZES_STRUCTURE_TYPE_PCI_BAR_PROPERTIES, 0x3,
      :ZES_STRUCTURE_TYPE_DIAG_PROPERTIES, 0x4,
      :ZES_STRUCTURE_TYPE_ENGINE_PROPERTIES, 0x5,
      :ZES_STRUCTURE_TYPE_FABRIC_PORT_PROPERTIES, 0x6,
      :ZES_STRUCTURE_TYPE_FAN_PROPERTIES, 0x7,
      :ZES_STRUCTURE_TYPE_FIRMWARE_PROPERTIES, 0x8,
      :ZES_STRUCTURE_TYPE_FREQ_PROPERTIES, 0x9,
      :ZES_STRUCTURE_TYPE_LED_PROPERTIES, 0xa,
      :ZES_STRUCTURE_TYPE_MEM_PROPERTIES, 0xb,
      :ZES_STRUCTURE_TYPE_PERF_PROPERTIES, 0xc,
      :ZES_STRUCTURE_TYPE_POWER_PROPERTIES, 0xd,
      :ZES_STRUCTURE_TYPE_PSU_PROPERTIES, 0xe,
      :ZES_STRUCTURE_TYPE_RAS_PROPERTIES, 0xf,
      :ZES_STRUCTURE_TYPE_SCHED_PROPERTIES, 0x10,
      :ZES_STRUCTURE_TYPE_SCHED_TIMEOUT_PROPERTIES, 0x11,
      :ZES_STRUCTURE_TYPE_SCHED_TIMESLICE_PROPERTIES, 0x12,
      :ZES_STRUCTURE_TYPE_STANDBY_PROPERTIES, 0x13,
      :ZES_STRUCTURE_TYPE_TEMP_PROPERTIES, 0x14,
      :ZES_STRUCTURE_TYPE_DEVICE_STATE, 0x15,
      :ZES_STRUCTURE_TYPE_PROCESS_STATE, 0x16,
      :ZES_STRUCTURE_TYPE_PCI_STATE, 0x17,
      :ZES_STRUCTURE_TYPE_FABRIC_PORT_CONFIG, 0x18,
      :ZES_STRUCTURE_TYPE_FABRIC_PORT_STATE, 0x19,
      :ZES_STRUCTURE_TYPE_FAN_CONFIG, 0x1a,
      :ZES_STRUCTURE_TYPE_FREQ_STATE, 0x1b,
      :ZES_STRUCTURE_TYPE_OC_CAPABILITIES, 0x1c,
      :ZES_STRUCTURE_TYPE_LED_STATE, 0x1d,
      :ZES_STRUCTURE_TYPE_MEM_STATE, 0x1e,
      :ZES_STRUCTURE_TYPE_PSU_STATE, 0x1f,
      :ZES_STRUCTURE_TYPE_BASE_STATE, 0x20,
      :ZES_STRUCTURE_TYPE_RAS_CONFIG, 0x21,
      :ZES_STRUCTURE_TYPE_RAS_STATE, 0x22,
      :ZES_STRUCTURE_TYPE_TEMP_CONFIG, 0x23,
      :ZES_STRUCTURE_TYPE_PCI_BAR_PROPERTIES_1_2, 0x24,
      :ZES_STRUCTURE_TYPE_DEVICE_ECC_DESC, 0x25,
      :ZES_STRUCTURE_TYPE_DEVICE_ECC_PROPERTIES, 0x26,
      :ZES_STRUCTURE_TYPE_POWER_LIMIT_EXT_DESC, 0x27,
      :ZES_STRUCTURE_TYPE_POWER_EXT_PROPERTIES, 0x28,
      :ZES_STRUCTURE_TYPE_OVERCLOCK_PROPERTIES, 0x29,
      :ZES_STRUCTURE_TYPE_FABRIC_PORT_ERROR_COUNTERS, 0x2a,
      :ZES_STRUCTURE_TYPE_ENGINE_EXT_PROPERTIES, 0x2b,
      :ZES_STRUCTURE_TYPE_RESET_PROPERTIES, 0x2c,
      :ZES_STRUCTURE_TYPE_DEVICE_EXT_PROPERTIES, 0x2d,
      :ZES_STRUCTURE_TYPE_DEVICE_UUID, 0x2e,
      :ZES_STRUCTURE_TYPE_POWER_DOMAIN_EXP_PROPERTIES, 0x20001,
      :ZES_STRUCTURE_TYPE_MEM_BANDWIDTH_COUNTER_BITS_EXP_PROPERTIES, 0x20002,
      :ZES_STRUCTURE_TYPE_MEMORY_PAGE_OFFLINE_STATE_EXP, 0x20003,
      :ZES_STRUCTURE_TYPE_SUBDEVICE_EXP_PROPERTIES, 0x20004,
      :ZES_STRUCTURE_TYPE_VF_EXP_PROPERTIES, 0x20005,
      :ZES_STRUCTURE_TYPE_VF_UTIL_MEM_EXP, 0x20006,
      :ZES_STRUCTURE_TYPE_VF_UTIL_ENGINE_EXP, 0x20007,
      :ZES_STRUCTURE_TYPE_VF_EXP_CAPABILITIES, 0x20008,
      :ZES_STRUCTURE_TYPE_VF_UTIL_MEM_EXP2, 0x20009,
      :ZES_STRUCTURE_TYPE_VF_UTIL_ENGINE_EXP2, 0x20010,
      :ZES_STRUCTURE_TYPE_VF_EXP2_CAPABILITIES, 0x20011,
      :ZES_STRUCTURE_TYPE_DEVICE_ECC_DEFAULT_PROPERTIES_EXT, 0x20012,
      :ZES_STRUCTURE_TYPE_FORCE_UINT32, 0x7fffffff ]

  ZESInitFlag = zebitmask :zes_init_flag_t,
    [ :ZES_INIT_FLAG_PLACEHOLDER, 0 ]
  # :ZES_INIT_FLAG_FORCE_UINT32, 0x7fffffff
  ZESInitFlags = ZESInitFlag
  typedef :zes_init_flag_t, :zes_init_flags_t

  ZESEngineTypeFlag = zebitmask :zes_engine_type_flag_t,
    [ :ZES_ENGINE_TYPE_FLAG_OTHER, 0,
      :ZES_ENGINE_TYPE_FLAG_COMPUTE, 1,
      :ZES_ENGINE_TYPE_FLAG_3D, 2,
      :ZES_ENGINE_TYPE_FLAG_MEDIA, 3,
      :ZES_ENGINE_TYPE_FLAG_DMA, 4,
      :ZES_ENGINE_TYPE_FLAG_RENDER, 5 ]
  # :ZES_ENGINE_TYPE_FLAG_FORCE_UINT32, 0x7fffffff
  ZESEngineTypeFlags = ZESEngineTypeFlag
  typedef :zes_engine_type_flag_t, :zes_engine_type_flags_t

  ZESRepairStatus = zeenum :zes_repair_status_t,
    [ :ZES_REPAIR_STATUS_UNSUPPORTED, 0,
      :ZES_REPAIR_STATUS_NOT_PERFORMED, 1,
      :ZES_REPAIR_STATUS_PERFORMED, 2,
      :ZES_REPAIR_STATUS_FORCE_UINT32, 0x7fffffff ]

  ZESResetReasonFlag = zebitmask :zes_reset_reason_flag_t,
    [ :ZES_RESET_REASON_FLAG_WEDGED, 0,
      :ZES_RESET_REASON_FLAG_REPAIR, 1 ]
  # :ZES_RESET_REASON_FLAG_FORCE_UINT32, 0x7fffffff
  ZESResetReasonFlags = ZESResetReasonFlag
  typedef :zes_reset_reason_flag_t, :zes_reset_reason_flags_t

  ZESResetType = zeenum :zes_reset_type_t,
    [ :ZES_RESET_TYPE_WARM, 0,
      :ZES_RESET_TYPE_COLD, 1,
      :ZES_RESET_TYPE_FLR, 2,
      :ZES_RESET_TYPE_FORCE_UINT32, 0x7fffffff ]

  ZESDeviceType = zeenum :zes_device_type_t,
    [ :ZES_DEVICE_TYPE_GPU, 1,
      :ZES_DEVICE_TYPE_CPU, 2,
      :ZES_DEVICE_TYPE_FPGA, 3,
      :ZES_DEVICE_TYPE_MCA, 4,
      :ZES_DEVICE_TYPE_VPU, 5,
      :ZES_DEVICE_TYPE_FORCE_UINT32, 0x7fffffff ]

  ZESDevicePropertyFlag = zebitmask :zes_device_property_flag_t,
    [ :ZES_DEVICE_PROPERTY_FLAG_INTEGRATED, 0,
      :ZES_DEVICE_PROPERTY_FLAG_SUBDEVICE, 1,
      :ZES_DEVICE_PROPERTY_FLAG_ECC, 2,
      :ZES_DEVICE_PROPERTY_FLAG_ONDEMANDPAGING, 3 ]
  # :ZES_DEVICE_PROPERTY_FLAG_FORCE_UINT32, 0x7fffffff
  ZESDevicePropertyFlags = ZESDevicePropertyFlag
  typedef :zes_device_property_flag_t, :zes_device_property_flags_t

  ZESPciLinkStatus = zeenum :zes_pci_link_status_t,
    [ :ZES_PCI_LINK_STATUS_UNKNOWN, 0,
      :ZES_PCI_LINK_STATUS_GOOD, 1,
      :ZES_PCI_LINK_STATUS_QUALITY_ISSUES, 2,
      :ZES_PCI_LINK_STATUS_STABILITY_ISSUES, 3,
      :ZES_PCI_LINK_STATUS_FORCE_UINT32, 0x7fffffff ]

  ZESPciLinkQualIssueFlag = zebitmask :zes_pci_link_qual_issue_flag_t,
    [ :ZES_PCI_LINK_QUAL_ISSUE_FLAG_REPLAYS, 0,
      :ZES_PCI_LINK_QUAL_ISSUE_FLAG_SPEED, 1 ]
  # :ZES_PCI_LINK_QUAL_ISSUE_FLAG_FORCE_UINT32, 0x7fffffff
  ZESPciLinkQualIssueFlags = ZESPciLinkQualIssueFlag
  typedef :zes_pci_link_qual_issue_flag_t, :zes_pci_link_qual_issue_flags_t

  ZESPciLinkStabIssueFlag = zebitmask :zes_pci_link_stab_issue_flag_t,
    [ :ZES_PCI_LINK_STAB_ISSUE_FLAG_RETRAINING, 0 ]
  # :ZES_PCI_LINK_STAB_ISSUE_FLAG_FORCE_UINT32, 0x7fffffff
  ZESPciLinkStabIssueFlags = ZESPciLinkStabIssueFlag
  typedef :zes_pci_link_stab_issue_flag_t, :zes_pci_link_stab_issue_flags_t

  ZESPciBarType = zeenum :zes_pci_bar_type_t,
    [ :ZES_PCI_BAR_TYPE_MMIO, 0,
      :ZES_PCI_BAR_TYPE_ROM, 1,
      :ZES_PCI_BAR_TYPE_MEM, 2,
      :ZES_PCI_BAR_TYPE_FORCE_UINT32, 0x7fffffff ]

  ZESOverclockDomain = zeenum :zes_overclock_domain_t,
    [ :ZES_OVERCLOCK_DOMAIN_CARD, 1,
      :ZES_OVERCLOCK_DOMAIN_PACKAGE, 2,
      :ZES_OVERCLOCK_DOMAIN_GPU_ALL, 4,
      :ZES_OVERCLOCK_DOMAIN_GPU_RENDER_COMPUTE, 8,
      :ZES_OVERCLOCK_DOMAIN_GPU_RENDER, 16,
      :ZES_OVERCLOCK_DOMAIN_GPU_COMPUTE, 32,
      :ZES_OVERCLOCK_DOMAIN_GPU_MEDIA, 64,
      :ZES_OVERCLOCK_DOMAIN_VRAM, 128,
      :ZES_OVERCLOCK_DOMAIN_ADM, 256,
      :ZES_OVERCLOCK_DOMAIN_FORCE_UINT32, 0x7fffffff ]

  ZESOverclockControl = zeenum :zes_overclock_control_t,
    [ :ZES_OVERCLOCK_CONTROL_VF, 1,
      :ZES_OVERCLOCK_CONTROL_FREQ_OFFSET, 2,
      :ZES_OVERCLOCK_CONTROL_VMAX_OFFSET, 4,
      :ZES_OVERCLOCK_CONTROL_FREQ, 8,
      :ZES_OVERCLOCK_CONTROL_VOLT_LIMIT, 16,
      :ZES_OVERCLOCK_CONTROL_POWER_SUSTAINED_LIMIT, 32,
      :ZES_OVERCLOCK_CONTROL_POWER_BURST_LIMIT, 64,
      :ZES_OVERCLOCK_CONTROL_POWER_PEAK_LIMIT, 128,
      :ZES_OVERCLOCK_CONTROL_ICCMAX_LIMIT, 256,
      :ZES_OVERCLOCK_CONTROL_TEMP_LIMIT, 512,
      :ZES_OVERCLOCK_CONTROL_ITD_DISABLE, 1024,
      :ZES_OVERCLOCK_CONTROL_ACM_DISABLE, 2048,
      :ZES_OVERCLOCK_CONTROL_FORCE_UINT32, 0x7fffffff ]

  ZESOverclockMode = zeenum :zes_overclock_mode_t,
    [ :ZES_OVERCLOCK_MODE_MODE_OFF, 0,
      :ZES_OVERCLOCK_MODE_MODE_STOCK, 2,
      :ZES_OVERCLOCK_MODE_MODE_ON, 3,
      :ZES_OVERCLOCK_MODE_MODE_UNAVAILABLE, 4,
      :ZES_OVERCLOCK_MODE_MODE_DISABLED, 5,
      :ZES_OVERCLOCK_MODE_FORCE_UINT32, 0x7fffffff ]

  ZESControlState = zeenum :zes_control_state_t,
    [ :ZES_CONTROL_STATE_STATE_UNSET, 0,
      :ZES_CONTROL_STATE_STATE_ACTIVE, 2,
      :ZES_CONTROL_STATE_STATE_DISABLED, 3,
      :ZES_CONTROL_STATE_FORCE_UINT32, 0x7fffffff ]

  ZESPendingAction = zeenum :zes_pending_action_t,
    [ :ZES_PENDING_ACTION_PENDING_NONE, 0,
      :ZES_PENDING_ACTION_PENDING_IMMINENT, 1,
      :ZES_PENDING_ACTION_PENDING_COLD_RESET, 2,
      :ZES_PENDING_ACTION_PENDING_WARM_RESET, 3,
      :ZES_PENDING_ACTION_FORCE_UINT32, 0x7fffffff ]

  ZESVfProgramType = zeenum :zes_vf_program_type_t,
    [ :ZES_VF_PROGRAM_TYPE_VF_ARBITRARY, 0,
      :ZES_VF_PROGRAM_TYPE_VF_FREQ_FIXED, 1,
      :ZES_VF_PROGRAM_TYPE_VF_VOLT_FIXED, 2,
      :ZES_VF_PROGRAM_TYPE_FORCE_UINT32, 0x7fffffff ]

  ZESVfType = zeenum :zes_vf_type_t,
    [ :ZES_VF_TYPE_VOLT, 0,
      :ZES_VF_TYPE_FREQ, 1,
      :ZES_VF_TYPE_FORCE_UINT32, 0x7fffffff ]

  ZESVfArrayType = zeenum :zes_vf_array_type_t,
    [ :ZES_VF_ARRAY_TYPE_USER_VF_ARRAY, 0,
      :ZES_VF_ARRAY_TYPE_DEFAULT_VF_ARRAY, 1,
      :ZES_VF_ARRAY_TYPE_LIVE_VF_ARRAY, 2,
      :ZES_VF_ARRAY_TYPE_FORCE_UINT32, 0x7fffffff ]

  ZESDiagResult = zeenum :zes_diag_result_t,
    [ :ZES_DIAG_RESULT_NO_ERRORS, 0,
      :ZES_DIAG_RESULT_ABORT, 1,
      :ZES_DIAG_RESULT_FAIL_CANT_REPAIR, 2,
      :ZES_DIAG_RESULT_REBOOT_FOR_REPAIR, 3,
      :ZES_DIAG_RESULT_FORCE_UINT32, 0x7fffffff ]

  ZESDeviceEccState = zeenum :zes_device_ecc_state_t,
    [ :ZES_DEVICE_ECC_STATE_UNAVAILABLE, 0,
      :ZES_DEVICE_ECC_STATE_ENABLED, 1,
      :ZES_DEVICE_ECC_STATE_DISABLED, 2,
      :ZES_DEVICE_ECC_STATE_FORCE_UINT32, 0x7fffffff ]

  ZESDeviceAction = zeenum :zes_device_action_t,
    [ :ZES_DEVICE_ACTION_NONE, 0,
      :ZES_DEVICE_ACTION_WARM_CARD_RESET, 1,
      :ZES_DEVICE_ACTION_COLD_CARD_RESET, 2,
      :ZES_DEVICE_ACTION_COLD_SYSTEM_REBOOT, 3,
      :ZES_DEVICE_ACTION_FORCE_UINT32, 0x7fffffff ]

  ZESEngineGroup = zeenum :zes_engine_group_t,
    [ :ZES_ENGINE_GROUP_ALL, 0,
      :ZES_ENGINE_GROUP_COMPUTE_ALL, 1,
      :ZES_ENGINE_GROUP_MEDIA_ALL, 2,
      :ZES_ENGINE_GROUP_COPY_ALL, 3,
      :ZES_ENGINE_GROUP_COMPUTE_SINGLE, 4,
      :ZES_ENGINE_GROUP_RENDER_SINGLE, 5,
      :ZES_ENGINE_GROUP_MEDIA_DECODE_SINGLE, 6,
      :ZES_ENGINE_GROUP_MEDIA_ENCODE_SINGLE, 7,
      :ZES_ENGINE_GROUP_COPY_SINGLE, 8,
      :ZES_ENGINE_GROUP_MEDIA_ENHANCEMENT_SINGLE, 9,
      :ZES_ENGINE_GROUP_3D_SINGLE, 10,
      :ZES_ENGINE_GROUP_3D_RENDER_COMPUTE_ALL, 11,
      :ZES_ENGINE_GROUP_RENDER_ALL, 12,
      :ZES_ENGINE_GROUP_3D_ALL, 13,
      :ZES_ENGINE_GROUP_MEDIA_CODEC_SINGLE, 14,
      :ZES_ENGINE_GROUP_FORCE_UINT32, 0x7fffffff ]

  ZESEventTypeFlag = zebitmask :zes_event_type_flag_t,
    [ :ZES_EVENT_TYPE_FLAG_DEVICE_DETACH, 0,
      :ZES_EVENT_TYPE_FLAG_DEVICE_ATTACH, 1,
      :ZES_EVENT_TYPE_FLAG_DEVICE_SLEEP_STATE_ENTER, 2,
      :ZES_EVENT_TYPE_FLAG_DEVICE_SLEEP_STATE_EXIT, 3,
      :ZES_EVENT_TYPE_FLAG_FREQ_THROTTLED, 4,
      :ZES_EVENT_TYPE_FLAG_ENERGY_THRESHOLD_CROSSED, 5,
      :ZES_EVENT_TYPE_FLAG_TEMP_CRITICAL, 6,
      :ZES_EVENT_TYPE_FLAG_TEMP_THRESHOLD1, 7,
      :ZES_EVENT_TYPE_FLAG_TEMP_THRESHOLD2, 8,
      :ZES_EVENT_TYPE_FLAG_MEM_HEALTH, 9,
      :ZES_EVENT_TYPE_FLAG_FABRIC_PORT_HEALTH, 10,
      :ZES_EVENT_TYPE_FLAG_PCI_LINK_HEALTH, 11,
      :ZES_EVENT_TYPE_FLAG_RAS_CORRECTABLE_ERRORS, 12,
      :ZES_EVENT_TYPE_FLAG_RAS_UNCORRECTABLE_ERRORS, 13,
      :ZES_EVENT_TYPE_FLAG_DEVICE_RESET_REQUIRED, 14,
      :ZES_EVENT_TYPE_FLAG_SURVIVABILITY_MODE_DETECTED, 15 ]
  # :ZES_EVENT_TYPE_FLAG_FORCE_UINT32, 0x7fffffff
  ZESEventTypeFlags = ZESEventTypeFlag
  typedef :zes_event_type_flag_t, :zes_event_type_flags_t

  ZESFabricPortStatus = zeenum :zes_fabric_port_status_t,
    [ :ZES_FABRIC_PORT_STATUS_UNKNOWN, 0,
      :ZES_FABRIC_PORT_STATUS_HEALTHY, 1,
      :ZES_FABRIC_PORT_STATUS_DEGRADED, 2,
      :ZES_FABRIC_PORT_STATUS_FAILED, 3,
      :ZES_FABRIC_PORT_STATUS_DISABLED, 4,
      :ZES_FABRIC_PORT_STATUS_FORCE_UINT32, 0x7fffffff ]

  ZESFabricPortQualIssueFlag = zebitmask :zes_fabric_port_qual_issue_flag_t,
    [ :ZES_FABRIC_PORT_QUAL_ISSUE_FLAG_LINK_ERRORS, 0,
      :ZES_FABRIC_PORT_QUAL_ISSUE_FLAG_SPEED, 1 ]
  # :ZES_FABRIC_PORT_QUAL_ISSUE_FLAG_FORCE_UINT32, 0x7fffffff
  ZESFabricPortQualIssueFlags = ZESFabricPortQualIssueFlag
  typedef :zes_fabric_port_qual_issue_flag_t, :zes_fabric_port_qual_issue_flags_t

  ZESFabricPortFailureFlag = zebitmask :zes_fabric_port_failure_flag_t,
    [ :ZES_FABRIC_PORT_FAILURE_FLAG_FAILED, 0,
      :ZES_FABRIC_PORT_FAILURE_FLAG_TRAINING_TIMEOUT, 1,
      :ZES_FABRIC_PORT_FAILURE_FLAG_FLAPPING, 2 ]
  # :ZES_FABRIC_PORT_FAILURE_FLAG_FORCE_UINT32, 0x7fffffff
  ZESFabricPortFailureFlags = ZESFabricPortFailureFlag
  typedef :zes_fabric_port_failure_flag_t, :zes_fabric_port_failure_flags_t

  ZESFanSpeedMode = zeenum :zes_fan_speed_mode_t,
    [ :ZES_FAN_SPEED_MODE_DEFAULT, 0,
      :ZES_FAN_SPEED_MODE_FIXED, 1,
      :ZES_FAN_SPEED_MODE_TABLE, 2,
      :ZES_FAN_SPEED_MODE_FORCE_UINT32, 0x7fffffff ]

  ZESFanSpeedUnits = zeenum :zes_fan_speed_units_t,
    [ :ZES_FAN_SPEED_UNITS_RPM, 0,
      :ZES_FAN_SPEED_UNITS_PERCENT, 1,
      :ZES_FAN_SPEED_UNITS_FORCE_UINT32, 0x7fffffff ]

  ZESFreqDomain = zeenum :zes_freq_domain_t,
    [ :ZES_FREQ_DOMAIN_GPU, 0,
      :ZES_FREQ_DOMAIN_MEMORY, 1,
      :ZES_FREQ_DOMAIN_MEDIA, 2,
      :ZES_FREQ_DOMAIN_FORCE_UINT32, 0x7fffffff ]

  ZESFreqThrottleReasonFlag = zebitmask :zes_freq_throttle_reason_flag_t,
    [ :ZES_FREQ_THROTTLE_REASON_FLAG_AVE_PWR_CAP, 0,
      :ZES_FREQ_THROTTLE_REASON_FLAG_BURST_PWR_CAP, 1,
      :ZES_FREQ_THROTTLE_REASON_FLAG_CURRENT_LIMIT, 2,
      :ZES_FREQ_THROTTLE_REASON_FLAG_THERMAL_LIMIT, 3,
      :ZES_FREQ_THROTTLE_REASON_FLAG_PSU_ALERT, 4,
      :ZES_FREQ_THROTTLE_REASON_FLAG_SW_RANGE, 5,
      :ZES_FREQ_THROTTLE_REASON_FLAG_HW_RANGE, 6 ]
  # :ZES_FREQ_THROTTLE_REASON_FLAG_FORCE_UINT32, 0x7fffffff
  ZESFreqThrottleReasonFlags = ZESFreqThrottleReasonFlag
  typedef :zes_freq_throttle_reason_flag_t, :zes_freq_throttle_reason_flags_t

  ZESOcMode = zeenum :zes_oc_mode_t,
    [ :ZES_OC_MODE_OFF, 0,
      :ZES_OC_MODE_OVERRIDE, 1,
      :ZES_OC_MODE_INTERPOLATIVE, 2,
      :ZES_OC_MODE_FIXED, 3,
      :ZES_OC_MODE_FORCE_UINT32, 0x7fffffff ]

  ZESMemType = zeenum :zes_mem_type_t,
    [ :ZES_MEM_TYPE_HBM, 0,
      :ZES_MEM_TYPE_DDR, 1,
      :ZES_MEM_TYPE_DDR3, 2,
      :ZES_MEM_TYPE_DDR4, 3,
      :ZES_MEM_TYPE_DDR5, 4,
      :ZES_MEM_TYPE_LPDDR, 5,
      :ZES_MEM_TYPE_LPDDR3, 6,
      :ZES_MEM_TYPE_LPDDR4, 7,
      :ZES_MEM_TYPE_LPDDR5, 8,
      :ZES_MEM_TYPE_SRAM, 9,
      :ZES_MEM_TYPE_L1, 10,
      :ZES_MEM_TYPE_L3, 11,
      :ZES_MEM_TYPE_GRF, 12,
      :ZES_MEM_TYPE_SLM, 13,
      :ZES_MEM_TYPE_GDDR4, 14,
      :ZES_MEM_TYPE_GDDR5, 15,
      :ZES_MEM_TYPE_GDDR5X, 16,
      :ZES_MEM_TYPE_GDDR6, 17,
      :ZES_MEM_TYPE_GDDR6X, 18,
      :ZES_MEM_TYPE_GDDR7, 19,
      :ZES_MEM_TYPE_FORCE_UINT32, 0x7fffffff ]

  ZESMemLoc = zeenum :zes_mem_loc_t,
    [ :ZES_MEM_LOC_SYSTEM, 0,
      :ZES_MEM_LOC_DEVICE, 1,
      :ZES_MEM_LOC_FORCE_UINT32, 0x7fffffff ]

  ZESMemHealth = zeenum :zes_mem_health_t,
    [ :ZES_MEM_HEALTH_UNKNOWN, 0,
      :ZES_MEM_HEALTH_OK, 1,
      :ZES_MEM_HEALTH_DEGRADED, 2,
      :ZES_MEM_HEALTH_CRITICAL, 3,
      :ZES_MEM_HEALTH_REPLACE, 4,
      :ZES_MEM_HEALTH_FORCE_UINT32, 0x7fffffff ]

  ZESPowerDomain = zeenum :zes_power_domain_t,
    [ :ZES_POWER_DOMAIN_UNKNOWN, 0,
      :ZES_POWER_DOMAIN_CARD, 1,
      :ZES_POWER_DOMAIN_PACKAGE, 2,
      :ZES_POWER_DOMAIN_STACK, 3,
      :ZES_POWER_DOMAIN_MEMORY, 4,
      :ZES_POWER_DOMAIN_GPU, 5,
      :ZES_POWER_DOMAIN_FORCE_UINT32, 0x7fffffff ]

  ZESPowerLevel = zeenum :zes_power_level_t,
    [ :ZES_POWER_LEVEL_UNKNOWN, 0,
      :ZES_POWER_LEVEL_SUSTAINED, 1,
      :ZES_POWER_LEVEL_BURST, 2,
      :ZES_POWER_LEVEL_PEAK, 3,
      :ZES_POWER_LEVEL_INSTANTANEOUS, 4,
      :ZES_POWER_LEVEL_FORCE_UINT32, 0x7fffffff ]

  ZESPowerSource = zeenum :zes_power_source_t,
    [ :ZES_POWER_SOURCE_ANY, 0,
      :ZES_POWER_SOURCE_MAINS, 1,
      :ZES_POWER_SOURCE_BATTERY, 2,
      :ZES_POWER_SOURCE_FORCE_UINT32, 0x7fffffff ]

  ZESLimitUnit = zeenum :zes_limit_unit_t,
    [ :ZES_LIMIT_UNIT_UNKNOWN, 0,
      :ZES_LIMIT_UNIT_CURRENT, 1,
      :ZES_LIMIT_UNIT_POWER, 2,
      :ZES_LIMIT_UNIT_FORCE_UINT32, 0x7fffffff ]

  ZESPsuVoltageStatus = zeenum :zes_psu_voltage_status_t,
    [ :ZES_PSU_VOLTAGE_STATUS_UNKNOWN, 0,
      :ZES_PSU_VOLTAGE_STATUS_NORMAL, 1,
      :ZES_PSU_VOLTAGE_STATUS_OVER, 2,
      :ZES_PSU_VOLTAGE_STATUS_UNDER, 3,
      :ZES_PSU_VOLTAGE_STATUS_FORCE_UINT32, 0x7fffffff ]

  ZESRasErrorType = zeenum :zes_ras_error_type_t,
    [ :ZES_RAS_ERROR_TYPE_CORRECTABLE, 0,
      :ZES_RAS_ERROR_TYPE_UNCORRECTABLE, 1,
      :ZES_RAS_ERROR_TYPE_FORCE_UINT32, 0x7fffffff ]

  ZESRasErrorCat = zeenum :zes_ras_error_cat_t,
    [ :ZES_RAS_ERROR_CAT_RESET, 0,
      :ZES_RAS_ERROR_CAT_PROGRAMMING_ERRORS, 1,
      :ZES_RAS_ERROR_CAT_DRIVER_ERRORS, 2,
      :ZES_RAS_ERROR_CAT_COMPUTE_ERRORS, 3,
      :ZES_RAS_ERROR_CAT_NON_COMPUTE_ERRORS, 4,
      :ZES_RAS_ERROR_CAT_CACHE_ERRORS, 5,
      :ZES_RAS_ERROR_CAT_DISPLAY_ERRORS, 6,
      :ZES_RAS_ERROR_CAT_FORCE_UINT32, 0x7fffffff ]

  ZESSchedMode = zeenum :zes_sched_mode_t,
    [ :ZES_SCHED_MODE_TIMEOUT, 0,
      :ZES_SCHED_MODE_TIMESLICE, 1,
      :ZES_SCHED_MODE_EXCLUSIVE, 2,
      :ZES_SCHED_MODE_COMPUTE_UNIT_DEBUG, 3,
      :ZES_SCHED_MODE_FORCE_UINT32, 0x7fffffff ]

  ZESStandbyType = zeenum :zes_standby_type_t,
    [ :ZES_STANDBY_TYPE_GLOBAL, 0,
      :ZES_STANDBY_TYPE_FORCE_UINT32, 0x7fffffff ]

  ZESStandbyPromoMode = zeenum :zes_standby_promo_mode_t,
    [ :ZES_STANDBY_PROMO_MODE_DEFAULT, 0,
      :ZES_STANDBY_PROMO_MODE_NEVER, 1,
      :ZES_STANDBY_PROMO_MODE_FORCE_UINT32, 0x7fffffff ]

  ZESTempSensors = zeenum :zes_temp_sensors_t,
    [ :ZES_TEMP_SENSORS_GLOBAL, 0,
      :ZES_TEMP_SENSORS_GPU, 1,
      :ZES_TEMP_SENSORS_MEMORY, 2,
      :ZES_TEMP_SENSORS_GLOBAL_MIN, 3,
      :ZES_TEMP_SENSORS_GPU_MIN, 4,
      :ZES_TEMP_SENSORS_MEMORY_MIN, 5,
      :ZES_TEMP_SENSORS_GPU_BOARD, 6,
      :ZES_TEMP_SENSORS_GPU_BOARD_MIN, 7,
      :ZES_TEMP_SENSORS_VOLTAGE_REGULATOR, 8,
      :ZES_TEMP_SENSORS_FORCE_UINT32, 0x7fffffff ]

  class ZESDeviceEccDefaultPropertiesExtVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZESDeviceEccDefaultPropertiesExtVersion.by_value, :zes_device_ecc_default_properties_ext_version_t

  class ZESPowerLimitsExtVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZESPowerLimitsExtVersion.by_value, :zes_power_limits_ext_version_t

  class ZESEngineActivityExtVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZESEngineActivityExtVersion.by_value, :zes_engine_activity_ext_version_t

  class ZESRasStateExpVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZESRasStateExpVersion.by_value, :zes_ras_state_exp_version_t

  ZESRasErrorCategoryExp = zeenum :zes_ras_error_category_exp_t,
    [ :ZES_RAS_ERROR_CATEGORY_EXP_RESET, 0,
      :ZES_RAS_ERROR_CATEGORY_EXP_PROGRAMMING_ERRORS, 1,
      :ZES_RAS_ERROR_CATEGORY_EXP_DRIVER_ERRORS, 2,
      :ZES_RAS_ERROR_CATEGORY_EXP_COMPUTE_ERRORS, 3,
      :ZES_RAS_ERROR_CATEGORY_EXP_NON_COMPUTE_ERRORS, 4,
      :ZES_RAS_ERROR_CATEGORY_EXP_CACHE_ERRORS, 5,
      :ZES_RAS_ERROR_CATEGORY_EXP_DISPLAY_ERRORS, 6,
      :ZES_RAS_ERROR_CATEGORY_EXP_MEMORY_ERRORS, 7,
      :ZES_RAS_ERROR_CATEGORY_EXP_SCALE_ERRORS, 8,
      :ZES_RAS_ERROR_CATEGORY_EXP_L3FABRIC_ERRORS, 9,
      :ZES_RAS_ERROR_CATEGORY_EXP_FORCE_UINT32, 0x7fffffff ]

  class ZESMemPageOfflineStateExpVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZESMemPageOfflineStateExpVersion.by_value, :zes_mem_page_offline_state_exp_version_t

  class ZESMemBandwidthCounterBitsExpVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZESMemBandwidthCounterBitsExpVersion.by_value, :zes_mem_bandwidth_counter_bits_exp_version_t

  class ZESPowerDomainPropertiesExpVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZESPowerDomainPropertiesExpVersion.by_value, :zes_power_domain_properties_exp_version_t

  class ZESFirmwareSecurityExpVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZESFirmwareSecurityExpVersion.by_value, :zes_firmware_security_exp_version_t

  class ZESSysmanDeviceMappingExpVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZESSysmanDeviceMappingExpVersion.by_value, :zes_sysman_device_mapping_exp_version_t

  class ZESVfManagementExpVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZESVfManagementExpVersion.by_value, :zes_vf_management_exp_version_t

  ZESVfInfoMemTypeExpFlag = zebitmask :zes_vf_info_mem_type_exp_flag_t,
    [ :ZES_VF_INFO_MEM_TYPE_EXP_FLAG_MEM_TYPE_SYSTEM, 0,
      :ZES_VF_INFO_MEM_TYPE_EXP_FLAG_MEM_TYPE_DEVICE, 1 ]
  # :ZES_VF_INFO_MEM_TYPE_EXP_FLAG_FORCE_UINT32, 0x7fffffff
  ZESVfInfoMemTypeExpFlags = ZESVfInfoMemTypeExpFlag
  typedef :zes_vf_info_mem_type_exp_flag_t, :zes_vf_info_mem_type_exp_flags_t

  ZESVfInfoUtilExpFlag = zebitmask :zes_vf_info_util_exp_flag_t,
    [ :ZES_VF_INFO_UTIL_EXP_FLAG_INFO_NONE, 0,
      :ZES_VF_INFO_UTIL_EXP_FLAG_INFO_MEM_CPU, 1,
      :ZES_VF_INFO_UTIL_EXP_FLAG_INFO_MEM_GPU, 2,
      :ZES_VF_INFO_UTIL_EXP_FLAG_INFO_ENGINE, 3 ]
  # :ZES_VF_INFO_UTIL_EXP_FLAG_FORCE_UINT32, 0x7fffffff
  ZESVfInfoUtilExpFlags = ZESVfInfoUtilExpFlag
  typedef :zes_vf_info_util_exp_flag_t, :zes_vf_info_util_exp_flags_t

  typedef :pointer, :zel_tracer_handle_t

  class ZELApiTracingVersion < FFI::ZEStruct
    prepend Version
    layout :minor, :uint16,
           :major, :uint16

    def self.from_native(i, ctx = nil)
      v = self::new
      v[:major] = ZE.ZE_MAJOR_VERSION(i)
      v[:minor] = ZE.ZE_MINOR_VERSION(i)
      v
    end
  end
  typedef ZELApiTracingVersion.by_value, :zel_api_tracing_version_t

  ZELStructureType = zeenum :zel_structure_type_t,
    [ :ZEL_STRUCTURE_TYPE_TRACER_DESC, 0x1,
      :ZEL_STRUCTURE_TYPE_TRACER_EXP_DESC, 0x1,
      :ZEL_STRUCTURE_TYPE_FORCE_UINT32, 0x7fffffff ]

  ZELTracerReg = zeenum :zel_tracer_reg_t,
    [ :ZEL_REGISTER_PROLOGUE, 0,
      :ZEL_REGISTER_EPILOGUE, 1 ]

  ZELHandleType = zeenum :zel_handle_type_t,
    [ :ZEL_HANDLE_DRIVER,
      :ZEL_HANDLE_DEVICE,
      :ZEL_HANDLE_CONTEXT,
      :ZEL_HANDLE_COMMAND_QUEUE,
      :ZEL_HANDLE_COMMAND_LIST,
      :ZEL_HANDLE_FENCE,
      :ZEL_HANDLE_EVENT_POOL,
      :ZEL_HANDLE_EVENT,
      :ZEL_HANDLE_IMAGE,
      :ZEL_HANDLE_MODULE,
      :ZEL_HANDLE_MODULE_BUILD_LOG,
      :ZEL_HANDLE_KERNEL,
      :ZEL_HANDLE_SAMPLER,
      :ZEL_HANDLE_PHYSICAL_MEM ]

  ZEXMemActionScopeFlag = zebitmask :zex_mem_action_scope_flag_t,
    [ :ZEX_MEM_ACTION_SCOPE_FLAG_SUBDEVICE, 0,
      :ZEX_MEM_ACTION_SCOPE_FLAG_DEVICE, 1,
      :ZEX_MEM_ACTION_SCOPE_FLAG_HOST, 2 ]
  # :ZEX_MEM_ACTION_SCOPE_FLAG_FORCE_UINT32, 0x7fffffff
  ZEXMemActionScopeFlags = ZEXMemActionScopeFlag
  typedef :zex_mem_action_scope_flag_t, :zex_mem_action_scope_flags_t

  ZEXWaitOnMemActionFlag = zebitmask :zex_wait_on_mem_action_flag_t,
    [ :ZEX_WAIT_ON_MEMORY_FLAG_EQUAL, 0,
      :ZEX_WAIT_ON_MEMORY_FLAG_NOT_EQUAL, 1,
      :ZEX_WAIT_ON_MEMORY_FLAG_GREATER_THAN, 2,
      :ZEX_WAIT_ON_MEMORY_FLAG_GREATER_THAN_EQUAL, 3,
      :ZEX_WAIT_ON_MEMORY_FLAG_LESSER_THAN, 4,
      :ZEX_WAIT_ON_MEMORY_FLAG_LESSER_THAN_EQUAL, 5 ]
  # :ZEX_WAIT_ON_MEMORY_FLAG_FORCE_UINT32, 0x7fffffff
  ZEXWaitOnMemActionFlags = ZEXWaitOnMemActionFlag
  typedef :zex_wait_on_mem_action_flag_t, :zex_wait_on_mem_action_flags_t

  class ZEIpcMemHandle < FFI::ZEStruct
    prepend Handle
    layout :data, [ :char, ZE_MAX_IPC_HANDLE_SIZE ]
  end
  typedef ZEIpcMemHandle.by_value, :ze_ipc_mem_handle_t

  class ZEIpcEventPoolHandle < FFI::ZEStruct
    prepend Handle
    layout :data, [ :char, ZE_MAX_IPC_HANDLE_SIZE ]
  end
  typedef ZEIpcEventPoolHandle.by_value, :ze_ipc_event_pool_handle_t

  class ZEUUID < FFI::ZEStruct
    prepend UUID
    layout :id, [ :uint8, ZE_MAX_UUID_SIZE ]
  end
  typedef ZEUUID.by_value, :ze_uuid_t

  class ZEBaseCbParams < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer
  end
  typedef ZEBaseCbParams.by_value, :ze_base_cb_params_t

  class ZEBaseProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer
  end
  typedef ZEBaseProperties.by_value, :ze_base_properties_t

  class ZEBaseDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer
  end
  typedef ZEBaseDesc.by_value, :ze_base_desc_t

  class ZEInitDriverTypeDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_init_driver_type_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_INIT_DRIVER_TYPE_DESC
      end
    end
  end
  typedef ZEInitDriverTypeDesc.by_value, :ze_init_driver_type_desc_t

  class ZEDriverUUID < FFI::ZEStruct
    prepend UUID
    layout :id, [ :uint8, ZE_MAX_DRIVER_UUID_SIZE ]
  end
  typedef ZEDriverUUID.by_value, :ze_driver_uuid_t

  class ZEDriverProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :uuid, :ze_driver_uuid_t,
           :driverVersion, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_DRIVER_PROPERTIES
      end
    end
  end
  typedef ZEDriverProperties.by_value, :ze_driver_properties_t

  class ZEDriverIpcProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_ipc_property_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_DRIVER_IPC_PROPERTIES
      end
    end
  end
  typedef ZEDriverIpcProperties.by_value, :ze_driver_ipc_properties_t

  class ZEDriverExtensionProperties < FFI::ZEStruct
    layout :name, [ :char, ZE_MAX_EXTENSION_NAME ],
           :version, :uint32
  end
  typedef ZEDriverExtensionProperties.by_value, :ze_driver_extension_properties_t

  class ZEDeviceUUID < FFI::ZEStruct
    prepend UUID
    layout :id, [ :uint8, ZE_MAX_DEVICE_UUID_SIZE ]
  end
  typedef ZEDeviceUUID.by_value, :ze_device_uuid_t

  class ZEDeviceProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :type, :ze_device_type_t,
           :vendorId, :uint32,
           :deviceId, :uint32,
           :flags, :ze_device_property_flags_t,
           :subdeviceId, :uint32,
           :coreClockRate, :uint32,
           :maxMemAllocSize, :uint64,
           :maxHardwareContexts, :uint32,
           :maxCommandQueuePriority, :uint32,
           :numThreadsPerEU, :uint32,
           :physicalEUSimdWidth, :uint32,
           :numEUsPerSubslice, :uint32,
           :numSubslicesPerSlice, :uint32,
           :numSlices, :uint32,
           :timerResolution, :uint64,
           :timestampValidBits, :uint32,
           :kernelTimestampValidBits, :uint32,
           :uuid, :ze_device_uuid_t,
           :name, [ :char, ZE_MAX_DEVICE_NAME ]

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_DEVICE_PROPERTIES
      end
    end
  end
  typedef ZEDeviceProperties.by_value, :ze_device_properties_t

  class ZEDeviceThread < FFI::ZEStruct
    layout :slice, :uint32,
           :subslice, :uint32,
           :eu, :uint32,
           :thread, :uint32
  end
  typedef ZEDeviceThread.by_value, :ze_device_thread_t

  class ZEDeviceComputeProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :maxTotalGroupSize, :uint32,
           :maxGroupSizeX, :uint32,
           :maxGroupSizeY, :uint32,
           :maxGroupSizeZ, :uint32,
           :maxGroupCountX, :uint32,
           :maxGroupCountY, :uint32,
           :maxGroupCountZ, :uint32,
           :maxSharedLocalMemory, :uint32,
           :numSubGroupSizes, :uint32,
           :subGroupSizes, [ :uint32, ZE_SUBGROUPSIZE_COUNT ]

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_DEVICE_COMPUTE_PROPERTIES
      end
    end
  end
  typedef ZEDeviceComputeProperties.by_value, :ze_device_compute_properties_t

  class ZENativeKernelUUID < FFI::ZEStruct
    prepend UUID
    layout :id, [ :uint8, ZE_MAX_NATIVE_KERNEL_UUID_SIZE ]
  end
  typedef ZENativeKernelUUID.by_value, :ze_native_kernel_uuid_t

  class ZEDeviceModuleProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :spirvVersionSupported, :uint32,
           :flags, :ze_device_module_flags_t,
           :fp16flags, :ze_device_fp_flags_t,
           :fp32flags, :ze_device_fp_flags_t,
           :fp64flags, :ze_device_fp_flags_t,
           :maxArgumentsSize, :uint32,
           :printfBufferSize, :uint32,
           :nativeKernelSupported, :ze_native_kernel_uuid_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_DEVICE_MODULE_PROPERTIES
      end
    end
  end
  typedef ZEDeviceModuleProperties.by_value, :ze_device_module_properties_t

  class ZECommandQueueGroupProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_command_queue_group_property_flags_t,
           :maxMemoryFillPatternSize, :size_t,
           :numQueues, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_COMMAND_QUEUE_GROUP_PROPERTIES
      end
    end
  end
  typedef ZECommandQueueGroupProperties.by_value, :ze_command_queue_group_properties_t

  class ZEDeviceMemoryProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_device_memory_property_flags_t,
           :maxClockRate, :uint32,
           :maxBusWidth, :uint32,
           :totalSize, :uint64,
           :name, [ :char, ZE_MAX_DEVICE_NAME ]

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_DEVICE_MEMORY_PROPERTIES
      end
    end
  end
  typedef ZEDeviceMemoryProperties.by_value, :ze_device_memory_properties_t

  class ZEDeviceMemoryAccessProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :hostAllocCapabilities, :ze_memory_access_cap_flags_t,
           :deviceAllocCapabilities, :ze_memory_access_cap_flags_t,
           :sharedSingleDeviceAllocCapabilities, :ze_memory_access_cap_flags_t,
           :sharedCrossDeviceAllocCapabilities, :ze_memory_access_cap_flags_t,
           :sharedSystemAllocCapabilities, :ze_memory_access_cap_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_DEVICE_MEMORY_ACCESS_PROPERTIES
      end
    end
  end
  typedef ZEDeviceMemoryAccessProperties.by_value, :ze_device_memory_access_properties_t

  class ZEDeviceCacheProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_device_cache_property_flags_t,
           :cacheSize, :size_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_DEVICE_CACHE_PROPERTIES
      end
    end
  end
  typedef ZEDeviceCacheProperties.by_value, :ze_device_cache_properties_t

  class ZEDeviceImageProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :maxImageDims1D, :uint32,
           :maxImageDims2D, :uint32,
           :maxImageDims3D, :uint32,
           :maxImageBufferSize, :uint64,
           :maxImageArraySlices, :uint32,
           :maxSamplers, :uint32,
           :maxReadImageArgs, :uint32,
           :maxWriteImageArgs, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_DEVICE_IMAGE_PROPERTIES
      end
    end
  end
  typedef ZEDeviceImageProperties.by_value, :ze_device_image_properties_t

  class ZEDeviceExternalMemoryProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :memoryAllocationImportTypes, :ze_external_memory_type_flags_t,
           :memoryAllocationExportTypes, :ze_external_memory_type_flags_t,
           :imageImportTypes, :ze_external_memory_type_flags_t,
           :imageExportTypes, :ze_external_memory_type_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_DEVICE_EXTERNAL_MEMORY_PROPERTIES
      end
    end
  end
  typedef ZEDeviceExternalMemoryProperties.by_value, :ze_device_external_memory_properties_t

  class ZEDeviceP2PProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_device_p2p_property_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_DEVICE_P2P_PROPERTIES
      end
    end
  end
  typedef ZEDeviceP2PProperties.by_value, :ze_device_p2p_properties_t

  class ZEContextDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_context_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_CONTEXT_DESC
      end
    end
  end
  typedef ZEContextDesc.by_value, :ze_context_desc_t

  class ZECommandQueueDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :ordinal, :uint32,
           :index, :uint32,
           :flags, :ze_command_queue_flags_t,
           :mode, :ze_command_queue_mode_t,
           :priority, :ze_command_queue_priority_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_COMMAND_QUEUE_DESC
      end
    end
  end
  typedef ZECommandQueueDesc.by_value, :ze_command_queue_desc_t

  class ZECommandListDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :commandQueueGroupOrdinal, :uint32,
           :flags, :ze_command_list_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_COMMAND_LIST_DESC
      end
    end
  end
  typedef ZECommandListDesc.by_value, :ze_command_list_desc_t

  class ZECopyRegion < FFI::ZEStruct
    layout :originX, :uint32,
           :originY, :uint32,
           :originZ, :uint32,
           :width, :uint32,
           :height, :uint32,
           :depth, :uint32
  end
  typedef ZECopyRegion.by_value, :ze_copy_region_t

  class ZEImageRegion < FFI::ZEStruct
    layout :originX, :uint32,
           :originY, :uint32,
           :originZ, :uint32,
           :width, :uint32,
           :height, :uint32,
           :depth, :uint32
  end
  typedef ZEImageRegion.by_value, :ze_image_region_t

  class ZEEventPoolDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_event_pool_flags_t,
           :count, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_EVENT_POOL_DESC
      end
    end
  end
  typedef ZEEventPoolDesc.by_value, :ze_event_pool_desc_t

  class ZEEventDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :index, :uint32,
           :signal, :ze_event_scope_flags_t,
           :wait, :ze_event_scope_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_EVENT_DESC
      end
    end
  end
  typedef ZEEventDesc.by_value, :ze_event_desc_t

  class ZEKernelTimestampData < FFI::ZEStruct
    layout :kernelStart, :uint64,
           :kernelEnd, :uint64
  end
  typedef ZEKernelTimestampData.by_value, :ze_kernel_timestamp_data_t

  class ZEKernelTimestampResult < FFI::ZEStruct
    layout :global, :ze_kernel_timestamp_data_t,
           :context, :ze_kernel_timestamp_data_t
  end
  typedef ZEKernelTimestampResult.by_value, :ze_kernel_timestamp_result_t

  class ZEFenceDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_fence_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_FENCE_DESC
      end
    end
  end
  typedef ZEFenceDesc.by_value, :ze_fence_desc_t

  class ZEImageFormat < FFI::ZEStruct
    layout :layout, :ze_image_format_layout_t,
           :type, :ze_image_format_type_t,
           :x, :ze_image_format_swizzle_t,
           :y, :ze_image_format_swizzle_t,
           :z, :ze_image_format_swizzle_t,
           :w, :ze_image_format_swizzle_t
  end
  typedef ZEImageFormat.by_value, :ze_image_format_t

  class ZEImageDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_image_flags_t,
           :type, :ze_image_type_t,
           :format, :ze_image_format_t,
           :width, :uint64,
           :height, :uint32,
           :depth, :uint32,
           :arraylevels, :uint32,
           :miplevels, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_IMAGE_DESC
      end
    end
  end
  typedef ZEImageDesc.by_value, :ze_image_desc_t

  class ZEImageProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :samplerFilterFlags, :ze_image_sampler_filter_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_IMAGE_PROPERTIES
      end
    end
  end
  typedef ZEImageProperties.by_value, :ze_image_properties_t

  class ZEDeviceMemAllocDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_device_mem_alloc_flags_t,
           :ordinal, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_DEVICE_MEM_ALLOC_DESC
      end
    end
  end
  typedef ZEDeviceMemAllocDesc.by_value, :ze_device_mem_alloc_desc_t

  class ZEHostMemAllocDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_host_mem_alloc_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_HOST_MEM_ALLOC_DESC
      end
    end
  end
  typedef ZEHostMemAllocDesc.by_value, :ze_host_mem_alloc_desc_t

  class ZEMemoryAllocationProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :type, :ze_memory_type_t,
           :id, :uint64,
           :pageSize, :uint64

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_MEMORY_ALLOCATION_PROPERTIES
      end
    end
  end
  typedef ZEMemoryAllocationProperties.by_value, :ze_memory_allocation_properties_t

  class ZEExternalMemoryExportDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_external_memory_type_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_EXTERNAL_MEMORY_EXPORT_DESC
      end
    end
  end
  typedef ZEExternalMemoryExportDesc.by_value, :ze_external_memory_export_desc_t

  class ZEExternalMemoryImportFd < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_external_memory_type_flags_t,
           :fd, :int

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMPORT_FD
      end
    end
  end
  typedef ZEExternalMemoryImportFd.by_value, :ze_external_memory_import_fd_t

  class ZEExternalMemoryExportFd < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_external_memory_type_flags_t,
           :fd, :int

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_EXTERNAL_MEMORY_EXPORT_FD
      end
    end
  end
  typedef ZEExternalMemoryExportFd.by_value, :ze_external_memory_export_fd_t

  class ZEExternalMemoryImportWin32Handle < FFI::ZEStruct
    prepend Handle
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_external_memory_type_flags_t,
           :handle, :pointer,
           :name, :pointer

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMPORT_WIN32
      end
    end
  end
  typedef ZEExternalMemoryImportWin32Handle.by_value, :ze_external_memory_import_win32_handle_t

  class ZEExternalMemoryExportWin32Handle < FFI::ZEStruct
    prepend Handle
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_external_memory_type_flags_t,
           :handle, :pointer

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_EXTERNAL_MEMORY_EXPORT_WIN32
      end
    end
  end
  typedef ZEExternalMemoryExportWin32Handle.by_value, :ze_external_memory_export_win32_handle_t

  class ZEModuleConstants < FFI::ZEStruct
    layout :numConstants, :uint32,
           :pConstantIds, :pointer,
           :pConstantValues, :pointer
  end
  typedef ZEModuleConstants.by_value, :ze_module_constants_t

  class ZEModuleDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :format, :ze_module_format_t,
           :inputSize, :size_t,
           :pInputModule, :pointer,
           :pBuildFlags, :pointer,
           :pConstants, :pointer

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_MODULE_DESC
      end
    end
  end
  typedef ZEModuleDesc.by_value, :ze_module_desc_t

  class ZEModuleProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_module_property_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_MODULE_PROPERTIES
      end
    end
  end
  typedef ZEModuleProperties.by_value, :ze_module_properties_t

  class ZEKernelDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_kernel_flags_t,
           :pKernelName, :pointer

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_KERNEL_DESC
      end
    end
  end
  typedef ZEKernelDesc.by_value, :ze_kernel_desc_t

  class ZEKernelUUID < FFI::ZEStruct
    prepend KUUID
    layout :kid, [ :uint8, ZE_MAX_KERNEL_UUID_SIZE ],
           :mid, [ :uint8, ZE_MAX_MODULE_UUID_SIZE ]
  end
  typedef ZEKernelUUID.by_value, :ze_kernel_uuid_t

  class ZEKernelProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :numKernelArgs, :uint32,
           :requiredGroupSizeX, :uint32,
           :requiredGroupSizeY, :uint32,
           :requiredGroupSizeZ, :uint32,
           :requiredNumSubGroups, :uint32,
           :requiredSubgroupSize, :uint32,
           :maxSubgroupSize, :uint32,
           :maxNumSubgroups, :uint32,
           :localMemSize, :uint32,
           :privateMemSize, :uint32,
           :spillMemSize, :uint32,
           :uuid, :ze_kernel_uuid_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_KERNEL_PROPERTIES
      end
    end
  end
  typedef ZEKernelProperties.by_value, :ze_kernel_properties_t

  class ZEKernelPreferredGroupSizeProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :preferredMultiple, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_KERNEL_PREFERRED_GROUP_SIZE_PROPERTIES
      end
    end
  end
  typedef ZEKernelPreferredGroupSizeProperties.by_value, :ze_kernel_preferred_group_size_properties_t

  class ZEGroupCount < FFI::ZEStruct
    layout :groupCountX, :uint32,
           :groupCountY, :uint32,
           :groupCountZ, :uint32
  end
  typedef ZEGroupCount.by_value, :ze_group_count_t

  class ZEModuleProgramExpDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :count, :uint32,
           :inputSizes, :pointer,
           :pInputModules, :pointer,
           :pBuildFlags, :pointer,
           :pConstants, :pointer

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_MODULE_PROGRAM_EXP_DESC
      end
    end
  end
  typedef ZEModuleProgramExpDesc.by_value, :ze_module_program_exp_desc_t

  class ZEDeviceRaytracingExtProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_device_raytracing_ext_flags_t,
           :maxBVHLevels, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_DEVICE_RAYTRACING_EXT_PROPERTIES
      end
    end
  end
  typedef ZEDeviceRaytracingExtProperties.by_value, :ze_device_raytracing_ext_properties_t

  class ZERaytracingMemAllocExtDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_raytracing_mem_alloc_ext_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_RAYTRACING_MEM_ALLOC_EXT_DESC
      end
    end
  end
  typedef ZERaytracingMemAllocExtDesc.by_value, :ze_raytracing_mem_alloc_ext_desc_t

  class ZESamplerDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :addressMode, :ze_sampler_address_mode_t,
           :filterMode, :ze_sampler_filter_mode_t,
           :isNormalized, :ze_bool_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_SAMPLER_DESC
      end
    end
  end
  typedef ZESamplerDesc.by_value, :ze_sampler_desc_t

  class ZEPhysicalMemDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_physical_mem_flags_t,
           :size, :size_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_PHYSICAL_MEM_DESC
      end
    end
  end
  typedef ZEPhysicalMemDesc.by_value, :ze_physical_mem_desc_t

  class ZEFloatAtomicExtProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :fp16Flags, :ze_device_fp_atomic_ext_flags_t,
           :fp32Flags, :ze_device_fp_atomic_ext_flags_t,
           :fp64Flags, :ze_device_fp_atomic_ext_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_FLOAT_ATOMIC_EXT_PROPERTIES
      end
    end
  end
  typedef ZEFloatAtomicExtProperties.by_value, :ze_float_atomic_ext_properties_t

  class ZERelaxedAllocationLimitsExpDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_relaxed_allocation_limits_exp_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_RELAXED_ALLOCATION_LIMITS_EXP_DESC
      end
    end
  end
  typedef ZERelaxedAllocationLimitsExpDesc.by_value, :ze_relaxed_allocation_limits_exp_desc_t

  class ZEDriverDdiHandlesExtProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_driver_ddi_handle_ext_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_DRIVER_DDI_HANDLES_EXT_PROPERTIES
      end
    end
  end
  typedef ZEDriverDdiHandlesExtProperties.by_value, :ze_driver_ddi_handles_ext_properties_t

  class ZEExternalSemaphoreExtDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_external_semaphore_ext_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_EXT_DESC
      end
    end
  end
  typedef ZEExternalSemaphoreExtDesc.by_value, :ze_external_semaphore_ext_desc_t

  class ZEExternalSemaphoreWin32ExtDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :handle, :pointer,
           :name, :pointer

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_WIN32_EXT_DESC
      end
    end
  end
  typedef ZEExternalSemaphoreWin32ExtDesc.by_value, :ze_external_semaphore_win32_ext_desc_t

  class ZEExternalSemaphoreFdExtDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :fd, :int

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_FD_EXT_DESC
      end
    end
  end
  typedef ZEExternalSemaphoreFdExtDesc.by_value, :ze_external_semaphore_fd_ext_desc_t

  class ZEExternalSemaphoreSignalParamsExt < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :value, :uint64

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS_EXT
      end
    end
  end
  typedef ZEExternalSemaphoreSignalParamsExt.by_value, :ze_external_semaphore_signal_params_ext_t

  class ZEExternalSemaphoreWaitParamsExt < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :value, :uint64

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_WAIT_PARAMS_EXT
      end
    end
  end
  typedef ZEExternalSemaphoreWaitParamsExt.by_value, :ze_external_semaphore_wait_params_ext_t

  class ZEDeviceCacheLineSizeExt < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :cacheLineSize, :size_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_DEVICE_CACHELINE_SIZE_EXT
      end
    end
  end
  typedef ZEDeviceCacheLineSizeExt.by_value, :ze_device_cache_line_size_ext_t

  class ZERtasBuilderExtDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :builderVersion, :ze_rtas_builder_ext_version_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_RTAS_BUILDER_EXT_DESC
      end
    end
  end
  typedef ZERtasBuilderExtDesc.by_value, :ze_rtas_builder_ext_desc_t

  class ZERtasBuilderExtProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_rtas_builder_ext_flags_t,
           :rtasBufferSizeBytesExpected, :size_t,
           :rtasBufferSizeBytesMaxRequired, :size_t,
           :scratchBufferSizeBytes, :size_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_RTAS_BUILDER_EXT_PROPERTIES
      end
    end
  end
  typedef ZERtasBuilderExtProperties.by_value, :ze_rtas_builder_ext_properties_t

  class ZERtasParallelOperationExtProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_rtas_parallel_operation_ext_flags_t,
           :maxConcurrency, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_RTAS_PARALLEL_OPERATION_EXT_PROPERTIES
      end
    end
  end
  typedef ZERtasParallelOperationExtProperties.by_value, :ze_rtas_parallel_operation_ext_properties_t

  class ZERtasDeviceExtProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_rtas_device_ext_flags_t,
           :rtasFormat, :ze_rtas_format_ext_t,
           :rtasBufferAlignment, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_RTAS_DEVICE_EXT_PROPERTIES
      end
    end
  end
  typedef ZERtasDeviceExtProperties.by_value, :ze_rtas_device_ext_properties_t

  class ZERtasFloat3Ext < FFI::ZEStruct
    layout :x, :float,
           :y, :float,
           :z, :float
  end
  typedef ZERtasFloat3Ext.by_value, :ze_rtas_float3_ext_t

  class ZERtasTransformFloat3x4ColumnMajorExt < FFI::ZEStruct
    layout :vx_x, :float,
           :vx_y, :float,
           :vx_z, :float,
           :vy_x, :float,
           :vy_y, :float,
           :vy_z, :float,
           :vz_x, :float,
           :vz_y, :float,
           :vz_z, :float,
           :p_x, :float,
           :p_y, :float,
           :p_z, :float
  end
  typedef ZERtasTransformFloat3x4ColumnMajorExt.by_value, :ze_rtas_transform_float3x4_column_major_ext_t

  class ZERtasTransformFloat3x4AlignedColumnMajorExt < FFI::ZEStruct
    layout :vx_x, :float,
           :vx_y, :float,
           :vx_z, :float,
           :pad0, :float,
           :vy_x, :float,
           :vy_y, :float,
           :vy_z, :float,
           :pad1, :float,
           :vz_x, :float,
           :vz_y, :float,
           :vz_z, :float,
           :pad2, :float,
           :p_x, :float,
           :p_y, :float,
           :p_z, :float,
           :pad3, :float
  end
  typedef ZERtasTransformFloat3x4AlignedColumnMajorExt.by_value, :ze_rtas_transform_float3x4_aligned_column_major_ext_t

  class ZERtasTransformFloat3x4RowMajorExt < FFI::ZEStruct
    layout :vx_x, :float,
           :vy_x, :float,
           :vz_x, :float,
           :p_x, :float,
           :vx_y, :float,
           :vy_y, :float,
           :vz_y, :float,
           :p_y, :float,
           :vx_z, :float,
           :vy_z, :float,
           :vz_z, :float,
           :p_z, :float
  end
  typedef ZERtasTransformFloat3x4RowMajorExt.by_value, :ze_rtas_transform_float3x4_row_major_ext_t

  class ZERtasAabbExt < FFI::ZEStruct
    layout :lower, :ze_rtas_float3_ext_t,
           :upper, :ze_rtas_float3_ext_t
  end
  typedef ZERtasAabbExt.by_value, :ze_rtas_aabb_ext_t

  class ZERtasTriangleIndicesUint32Ext < FFI::ZEStruct
    layout :v0, :uint32,
           :v1, :uint32,
           :v2, :uint32
  end
  typedef ZERtasTriangleIndicesUint32Ext.by_value, :ze_rtas_triangle_indices_uint32_ext_t

  class ZERtasQuadIndicesUint32Ext < FFI::ZEStruct
    layout :v0, :uint32,
           :v1, :uint32,
           :v2, :uint32,
           :v3, :uint32
  end
  typedef ZERtasQuadIndicesUint32Ext.by_value, :ze_rtas_quad_indices_uint32_ext_t

  class ZERtasBuilderGeometryInfoExt < FFI::ZEStruct
    layout :geometryType, :ze_rtas_builder_packed_geometry_type_ext_t
  end
  typedef ZERtasBuilderGeometryInfoExt.by_value, :ze_rtas_builder_geometry_info_ext_t

  class ZERtasBuilderTrianglesGeometryInfoExt < FFI::ZEStruct
    layout :geometryType, :ze_rtas_builder_packed_geometry_type_ext_t,
           :geometryFlags, :ze_rtas_builder_packed_geometry_ext_flags_t,
           :geometryMask, :uint8,
           :triangleFormat, :ze_rtas_builder_packed_input_data_format_ext_t,
           :vertexFormat, :ze_rtas_builder_packed_input_data_format_ext_t,
           :triangleCount, :uint32,
           :vertexCount, :uint32,
           :triangleStride, :uint32,
           :vertexStride, :uint32,
           :pTriangleBuffer, :pointer,
           :pVertexBuffer, :pointer
  end
  typedef ZERtasBuilderTrianglesGeometryInfoExt.by_value, :ze_rtas_builder_triangles_geometry_info_ext_t

  class ZERtasBuilderQuadsGeometryInfoExt < FFI::ZEStruct
    layout :geometryType, :ze_rtas_builder_packed_geometry_type_ext_t,
           :geometryFlags, :ze_rtas_builder_packed_geometry_ext_flags_t,
           :geometryMask, :uint8,
           :quadFormat, :ze_rtas_builder_packed_input_data_format_ext_t,
           :vertexFormat, :ze_rtas_builder_packed_input_data_format_ext_t,
           :quadCount, :uint32,
           :vertexCount, :uint32,
           :quadStride, :uint32,
           :vertexStride, :uint32,
           :pQuadBuffer, :pointer,
           :pVertexBuffer, :pointer
  end
  typedef ZERtasBuilderQuadsGeometryInfoExt.by_value, :ze_rtas_builder_quads_geometry_info_ext_t

  class ZERtasGeometryAabbsExtCbParams < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :primID, :uint32,
           :primIDCount, :uint32,
           :pGeomUserPtr, :pointer,
           :pBuildUserPtr, :pointer,
           :pBoundsOut, :pointer

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_RTAS_GEOMETRY_AABBS_EXT_CB_PARAMS
      end
    end
  end
  typedef ZERtasGeometryAabbsExtCbParams.by_value, :ze_rtas_geometry_aabbs_ext_cb_params_t

  callback :ze_rtas_geometry_aabbs_cb_ext_t,
           [ ZERtasGeometryAabbsExtCbParams.ptr ],
           :void

  class ZERtasBuilderProceduralGeometryInfoExt < FFI::ZEStruct
    layout :geometryType, :ze_rtas_builder_packed_geometry_type_ext_t,
           :geometryFlags, :ze_rtas_builder_packed_geometry_ext_flags_t,
           :geometryMask, :uint8,
           :reserved, :uint8,
           :primCount, :uint32,
           :pfnGetBoundsCb, :ze_rtas_geometry_aabbs_cb_ext_t,
           :pGeomUserPtr, :pointer
  end
  typedef ZERtasBuilderProceduralGeometryInfoExt.by_value, :ze_rtas_builder_procedural_geometry_info_ext_t

  class ZERtasBuilderInstanceGeometryInfoExt < FFI::ZEStruct
    layout :geometryType, :ze_rtas_builder_packed_geometry_type_ext_t,
           :instanceFlags, :ze_rtas_builder_packed_instance_ext_flags_t,
           :geometryMask, :uint8,
           :transformFormat, :ze_rtas_builder_packed_input_data_format_ext_t,
           :instanceUserID, :uint32,
           :pTransform, :pointer,
           :pBounds, :pointer,
           :pAccelerationStructure, :pointer
  end
  typedef ZERtasBuilderInstanceGeometryInfoExt.by_value, :ze_rtas_builder_instance_geometry_info_ext_t

  class ZERtasBuilderBuildOpExtDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :rtasFormat, :ze_rtas_format_ext_t,
           :buildQuality, :ze_rtas_builder_build_quality_hint_ext_t,
           :buildFlags, :ze_rtas_builder_build_op_ext_flags_t,
           :ppGeometries, :pointer,
           :numGeometries, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_RTAS_BUILDER_BUILD_OP_EXT_DESC
      end
    end
  end
  typedef ZERtasBuilderBuildOpExtDesc.by_value, :ze_rtas_builder_build_op_ext_desc_t

  class ZEDeviceVectorWidthPropertiesExt < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :vector_width_size, :uint32,
           :preferred_vector_width_char, :uint32,
           :preferred_vector_width_short, :uint32,
           :preferred_vector_width_int, :uint32,
           :preferred_vector_width_long, :uint32,
           :preferred_vector_width_float, :uint32,
           :preferred_vector_width_double, :uint32,
           :preferred_vector_width_half, :uint32,
           :native_vector_width_char, :uint32,
           :native_vector_width_short, :uint32,
           :native_vector_width_int, :uint32,
           :native_vector_width_long, :uint32,
           :native_vector_width_float, :uint32,
           :native_vector_width_double, :uint32,
           :native_vector_width_half, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_DEVICE_VECTOR_WIDTH_PROPERTIES_EXT
      end
    end
  end
  typedef ZEDeviceVectorWidthPropertiesExt.by_value, :ze_device_vector_width_properties_ext_t

  class ZECacheReservationExtDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :maxCacheReservationSize, :size_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_CACHE_RESERVATION_EXT_DESC
      end
    end
  end
  typedef ZECacheReservationExtDesc.by_value, :ze_cache_reservation_ext_desc_t

  class ZEImageMemoryPropertiesExp < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :size, :uint64,
           :rowPitch, :uint64,
           :slicePitch, :uint64

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_IMAGE_MEMORY_EXP_PROPERTIES
      end
    end
  end
  typedef ZEImageMemoryPropertiesExp.by_value, :ze_image_memory_properties_exp_t

  class ZEImageViewPlanarExtDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :planeIndex, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_IMAGE_VIEW_PLANAR_EXT_DESC
      end
    end
  end
  typedef ZEImageViewPlanarExtDesc.by_value, :ze_image_view_planar_ext_desc_t

  class ZEImageViewPlanarExpDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :planeIndex, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_IMAGE_VIEW_PLANAR_EXP_DESC
      end
    end
  end
  typedef ZEImageViewPlanarExpDesc.by_value, :ze_image_view_planar_exp_desc_t

  class ZESchedulingHintExpProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :schedulingHintFlags, :ze_scheduling_hint_exp_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_SCHEDULING_HINT_EXP_PROPERTIES
      end
    end
  end
  typedef ZESchedulingHintExpProperties.by_value, :ze_scheduling_hint_exp_properties_t

  class ZESchedulingHintExpDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_scheduling_hint_exp_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_SCHEDULING_HINT_EXP_DESC
      end
    end
  end
  typedef ZESchedulingHintExpDesc.by_value, :ze_scheduling_hint_exp_desc_t

  class ZEContextPowerSavingHintExpDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :hint, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_POWER_SAVING_HINT_EXP_DESC
      end
    end
  end
  typedef ZEContextPowerSavingHintExpDesc.by_value, :ze_context_power_saving_hint_exp_desc_t

  class ZEEuCountExt < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :numTotalEUs, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_EU_COUNT_EXT
      end
    end
  end
  typedef ZEEuCountExt.by_value, :ze_eu_count_ext_t

  class ZEPciAddressExt < FFI::ZEStruct
    layout :domain, :uint32,
           :bus, :uint32,
           :device, :uint32,
           :function, :uint32
  end
  typedef ZEPciAddressExt.by_value, :ze_pci_address_ext_t

  class ZEPciSpeedExt < FFI::ZEStruct
    layout :genVersion, :int32,
           :width, :int32,
           :maxBandwidth, :int64
  end
  typedef ZEPciSpeedExt.by_value, :ze_pci_speed_ext_t

  class ZEPciExtProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :address, :ze_pci_address_ext_t,
           :maxSpeed, :ze_pci_speed_ext_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_PCI_EXT_PROPERTIES
      end
    end
  end
  typedef ZEPciExtProperties.by_value, :ze_pci_ext_properties_t

  class ZESrgbExtDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :sRGB, :ze_bool_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_SRGB_EXT_DESC
      end
    end
  end
  typedef ZESrgbExtDesc.by_value, :ze_srgb_ext_desc_t

  class ZEImageAllocationExtProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :id, :uint64

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_IMAGE_ALLOCATION_EXT_PROPERTIES
      end
    end
  end
  typedef ZEImageAllocationExtProperties.by_value, :ze_image_allocation_ext_properties_t

  class ZELinkageInspectionExtDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_linkage_inspection_ext_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_LINKAGE_INSPECTION_EXT_DESC
      end
    end
  end
  typedef ZELinkageInspectionExtDesc.by_value, :ze_linkage_inspection_ext_desc_t

  class ZEMemoryCompressionHintsExtDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_memory_compression_hints_ext_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_MEMORY_COMPRESSION_HINTS_EXT_DESC
      end
    end
  end
  typedef ZEMemoryCompressionHintsExtDesc.by_value, :ze_memory_compression_hints_ext_desc_t

  class ZEDriverMemoryFreeExtProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :freePolicies, :ze_driver_memory_free_policy_ext_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_DRIVER_MEMORY_FREE_EXT_PROPERTIES
      end
    end
  end
  typedef ZEDriverMemoryFreeExtProperties.by_value, :ze_driver_memory_free_ext_properties_t

  class ZEMemoryFreeExtDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :freePolicy, :ze_driver_memory_free_policy_ext_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_MEMORY_FREE_EXT_DESC
      end
    end
  end
  typedef ZEMemoryFreeExtDesc.by_value, :ze_memory_free_ext_desc_t

  class ZEDeviceP2PBandwidthExpProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :logicalBandwidth, :uint32,
           :physicalBandwidth, :uint32,
           :bandwidthUnit, :ze_bandwidth_unit_t,
           :logicalLatency, :uint32,
           :physicalLatency, :uint32,
           :latencyUnit, :ze_latency_unit_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_DEVICE_P2P_BANDWIDTH_EXP_PROPERTIES
      end
    end
  end
  typedef ZEDeviceP2PBandwidthExpProperties.by_value, :ze_device_p2p_bandwidth_exp_properties_t

  class ZECopyBandwidthExpProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :copyBandwidth, :uint32,
           :copyBandwidthUnit, :ze_bandwidth_unit_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_COPY_BANDWIDTH_EXP_PROPERTIES
      end
    end
  end
  typedef ZECopyBandwidthExpProperties.by_value, :ze_copy_bandwidth_exp_properties_t

  class ZEDeviceLuidExt < FFI::ZEStruct
    layout :id, [ :uint8, ZE_MAX_DEVICE_LUID_SIZE_EXT ]
  end
  typedef ZEDeviceLuidExt.by_value, :ze_device_luid_ext_t

  class ZEDeviceLuidExtProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :luid, :ze_device_luid_ext_t,
           :nodeMask, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_DEVICE_LUID_EXT_PROPERTIES
      end
    end
  end
  typedef ZEDeviceLuidExtProperties.by_value, :ze_device_luid_ext_properties_t

  class ZEFabricVertexPciExpAddress < FFI::ZEStruct
    layout :domain, :uint32,
           :bus, :uint32,
           :device, :uint32,
           :function, :uint32
  end
  typedef ZEFabricVertexPciExpAddress.by_value, :ze_fabric_vertex_pci_exp_address_t

  class ZEFabricVertexExpProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :uuid, :ze_uuid_t,
           :type, :ze_fabric_vertex_exp_type_t,
           :remote, :ze_bool_t,
           :address, :ze_fabric_vertex_pci_exp_address_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_FABRIC_VERTEX_EXP_PROPERTIES
      end
    end
  end
  typedef ZEFabricVertexExpProperties.by_value, :ze_fabric_vertex_exp_properties_t

  class ZEFabricEdgeExpProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :uuid, :ze_uuid_t,
           :model, [ :char, ZE_MAX_FABRIC_EDGE_MODEL_EXP_SIZE ],
           :bandwidth, :uint32,
           :bandwidthUnit, :ze_bandwidth_unit_t,
           :latency, :uint32,
           :latencyUnit, :ze_latency_unit_t,
           :duplexity, :ze_fabric_edge_exp_duplexity_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_FABRIC_EDGE_EXP_PROPERTIES
      end
    end
  end
  typedef ZEFabricEdgeExpProperties.by_value, :ze_fabric_edge_exp_properties_t

  class ZEDeviceMemoryExtProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :type, :ze_device_memory_ext_type_t,
           :physicalSize, :uint64,
           :readBandwidth, :uint32,
           :writeBandwidth, :uint32,
           :bandwidthUnit, :ze_bandwidth_unit_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_DEVICE_MEMORY_EXT_PROPERTIES
      end
    end
  end
  typedef ZEDeviceMemoryExtProperties.by_value, :ze_device_memory_ext_properties_t

  class ZEDeviceIpVersionExt < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :ipVersion, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_DEVICE_IP_VERSION_EXT
      end
    end
  end
  typedef ZEDeviceIpVersionExt.by_value, :ze_device_ip_version_ext_t

  class ZEKernelMaxGroupSizePropertiesExt < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :maxGroupSize, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_KERNEL_MAX_GROUP_SIZE_EXT_PROPERTIES
      end
    end
  end
  typedef ZEKernelMaxGroupSizePropertiesExt.by_value, :ze_kernel_max_group_size_properties_ext_t

  class ZESubAllocation < FFI::ZEStruct
    layout :base, :pointer,
           :size, :size_t
  end
  typedef ZESubAllocation.by_value, :ze_sub_allocation_t

  class ZEMemorySubAllocationsExpProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :pCount, :pointer,
           :pSubAllocations, :pointer

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_MEMORY_SUB_ALLOCATIONS_EXP_PROPERTIES
      end
    end
  end
  typedef ZEMemorySubAllocationsExpProperties.by_value, :ze_memory_sub_allocations_exp_properties_t

  class ZEEventQueryKernelTimestampsExtProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_event_query_kernel_timestamps_ext_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_EVENT_QUERY_KERNEL_TIMESTAMPS_EXT_PROPERTIES
      end
    end
  end
  typedef ZEEventQueryKernelTimestampsExtProperties.by_value, :ze_event_query_kernel_timestamps_ext_properties_t

  class ZESynchronizedTimestampDataExt < FFI::ZEStruct
    layout :kernelStart, :uint64,
           :kernelEnd, :uint64
  end
  typedef ZESynchronizedTimestampDataExt.by_value, :ze_synchronized_timestamp_data_ext_t

  class ZESynchronizedTimestampResultExt < FFI::ZEStruct
    layout :global, :ze_synchronized_timestamp_data_ext_t,
           :context, :ze_synchronized_timestamp_data_ext_t
  end
  typedef ZESynchronizedTimestampResultExt.by_value, :ze_synchronized_timestamp_result_ext_t

  class ZEEventQueryKernelTimestampsResultsExtProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :pKernelTimestampsBuffer, :pointer,
           :pSynchronizedTimestampsBuffer, :pointer

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_EVENT_QUERY_KERNEL_TIMESTAMPS_RESULTS_EXT_PROPERTIES
      end
    end
  end
  typedef ZEEventQueryKernelTimestampsResultsExtProperties.by_value, :ze_event_query_kernel_timestamps_results_ext_properties_t

  class ZERtasBuilderExpDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :builderVersion, :ze_rtas_builder_exp_version_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_RTAS_BUILDER_EXP_DESC
      end
    end
  end
  typedef ZERtasBuilderExpDesc.by_value, :ze_rtas_builder_exp_desc_t

  class ZERtasBuilderExpProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_rtas_builder_exp_flags_t,
           :rtasBufferSizeBytesExpected, :size_t,
           :rtasBufferSizeBytesMaxRequired, :size_t,
           :scratchBufferSizeBytes, :size_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_RTAS_BUILDER_EXP_PROPERTIES
      end
    end
  end
  typedef ZERtasBuilderExpProperties.by_value, :ze_rtas_builder_exp_properties_t

  class ZERtasParallelOperationExpProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_rtas_parallel_operation_exp_flags_t,
           :maxConcurrency, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_RTAS_PARALLEL_OPERATION_EXP_PROPERTIES
      end
    end
  end
  typedef ZERtasParallelOperationExpProperties.by_value, :ze_rtas_parallel_operation_exp_properties_t

  class ZERtasDeviceExpProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_rtas_device_exp_flags_t,
           :rtasFormat, :ze_rtas_format_exp_t,
           :rtasBufferAlignment, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_RTAS_DEVICE_EXP_PROPERTIES
      end
    end
  end
  typedef ZERtasDeviceExpProperties.by_value, :ze_rtas_device_exp_properties_t

  class ZERtasFloat3Exp < FFI::ZEStruct
    layout :x, :float,
           :y, :float,
           :z, :float
  end
  typedef ZERtasFloat3Exp.by_value, :ze_rtas_float3_exp_t

  class ZERtasTransformFloat3x4ColumnMajorExp < FFI::ZEStruct
    layout :vx_x, :float,
           :vx_y, :float,
           :vx_z, :float,
           :vy_x, :float,
           :vy_y, :float,
           :vy_z, :float,
           :vz_x, :float,
           :vz_y, :float,
           :vz_z, :float,
           :p_x, :float,
           :p_y, :float,
           :p_z, :float
  end
  typedef ZERtasTransformFloat3x4ColumnMajorExp.by_value, :ze_rtas_transform_float3x4_column_major_exp_t

  class ZERtasTransformFloat3x4AlignedColumnMajorExp < FFI::ZEStruct
    layout :vx_x, :float,
           :vx_y, :float,
           :vx_z, :float,
           :pad0, :float,
           :vy_x, :float,
           :vy_y, :float,
           :vy_z, :float,
           :pad1, :float,
           :vz_x, :float,
           :vz_y, :float,
           :vz_z, :float,
           :pad2, :float,
           :p_x, :float,
           :p_y, :float,
           :p_z, :float,
           :pad3, :float
  end
  typedef ZERtasTransformFloat3x4AlignedColumnMajorExp.by_value, :ze_rtas_transform_float3x4_aligned_column_major_exp_t

  class ZERtasTransformFloat3x4RowMajorExp < FFI::ZEStruct
    layout :vx_x, :float,
           :vy_x, :float,
           :vz_x, :float,
           :p_x, :float,
           :vx_y, :float,
           :vy_y, :float,
           :vz_y, :float,
           :p_y, :float,
           :vx_z, :float,
           :vy_z, :float,
           :vz_z, :float,
           :p_z, :float
  end
  typedef ZERtasTransformFloat3x4RowMajorExp.by_value, :ze_rtas_transform_float3x4_row_major_exp_t

  class ZERtasAabbExp < FFI::ZEStruct
    layout :lower, :ze_rtas_float3_exp_t,
           :upper, :ze_rtas_float3_exp_t
  end
  typedef ZERtasAabbExp.by_value, :ze_rtas_aabb_exp_t

  class ZERtasTriangleIndicesUint32Exp < FFI::ZEStruct
    layout :v0, :uint32,
           :v1, :uint32,
           :v2, :uint32
  end
  typedef ZERtasTriangleIndicesUint32Exp.by_value, :ze_rtas_triangle_indices_uint32_exp_t

  class ZERtasQuadIndicesUint32Exp < FFI::ZEStruct
    layout :v0, :uint32,
           :v1, :uint32,
           :v2, :uint32,
           :v3, :uint32
  end
  typedef ZERtasQuadIndicesUint32Exp.by_value, :ze_rtas_quad_indices_uint32_exp_t

  class ZERtasBuilderGeometryInfoExp < FFI::ZEStruct
    layout :geometryType, :ze_rtas_builder_packed_geometry_type_exp_t
  end
  typedef ZERtasBuilderGeometryInfoExp.by_value, :ze_rtas_builder_geometry_info_exp_t

  class ZERtasBuilderTrianglesGeometryInfoExp < FFI::ZEStruct
    layout :geometryType, :ze_rtas_builder_packed_geometry_type_exp_t,
           :geometryFlags, :ze_rtas_builder_packed_geometry_exp_flags_t,
           :geometryMask, :uint8,
           :triangleFormat, :ze_rtas_builder_packed_input_data_format_exp_t,
           :vertexFormat, :ze_rtas_builder_packed_input_data_format_exp_t,
           :triangleCount, :uint32,
           :vertexCount, :uint32,
           :triangleStride, :uint32,
           :vertexStride, :uint32,
           :pTriangleBuffer, :pointer,
           :pVertexBuffer, :pointer
  end
  typedef ZERtasBuilderTrianglesGeometryInfoExp.by_value, :ze_rtas_builder_triangles_geometry_info_exp_t

  class ZERtasBuilderQuadsGeometryInfoExp < FFI::ZEStruct
    layout :geometryType, :ze_rtas_builder_packed_geometry_type_exp_t,
           :geometryFlags, :ze_rtas_builder_packed_geometry_exp_flags_t,
           :geometryMask, :uint8,
           :quadFormat, :ze_rtas_builder_packed_input_data_format_exp_t,
           :vertexFormat, :ze_rtas_builder_packed_input_data_format_exp_t,
           :quadCount, :uint32,
           :vertexCount, :uint32,
           :quadStride, :uint32,
           :vertexStride, :uint32,
           :pQuadBuffer, :pointer,
           :pVertexBuffer, :pointer
  end
  typedef ZERtasBuilderQuadsGeometryInfoExp.by_value, :ze_rtas_builder_quads_geometry_info_exp_t

  class ZERtasGeometryAabbsExpCbParams < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :primID, :uint32,
           :primIDCount, :uint32,
           :pGeomUserPtr, :pointer,
           :pBuildUserPtr, :pointer,
           :pBoundsOut, :pointer

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_RTAS_GEOMETRY_AABBS_EXP_CB_PARAMS
      end
    end
  end
  typedef ZERtasGeometryAabbsExpCbParams.by_value, :ze_rtas_geometry_aabbs_exp_cb_params_t

  callback :ze_rtas_geometry_aabbs_cb_exp_t,
           [ ZERtasGeometryAabbsExpCbParams.ptr ],
           :void

  class ZERtasBuilderProceduralGeometryInfoExp < FFI::ZEStruct
    layout :geometryType, :ze_rtas_builder_packed_geometry_type_exp_t,
           :geometryFlags, :ze_rtas_builder_packed_geometry_exp_flags_t,
           :geometryMask, :uint8,
           :reserved, :uint8,
           :primCount, :uint32,
           :pfnGetBoundsCb, :ze_rtas_geometry_aabbs_cb_exp_t,
           :pGeomUserPtr, :pointer
  end
  typedef ZERtasBuilderProceduralGeometryInfoExp.by_value, :ze_rtas_builder_procedural_geometry_info_exp_t

  class ZERtasBuilderInstanceGeometryInfoExp < FFI::ZEStruct
    layout :geometryType, :ze_rtas_builder_packed_geometry_type_exp_t,
           :instanceFlags, :ze_rtas_builder_packed_instance_exp_flags_t,
           :geometryMask, :uint8,
           :transformFormat, :ze_rtas_builder_packed_input_data_format_exp_t,
           :instanceUserID, :uint32,
           :pTransform, :pointer,
           :pBounds, :pointer,
           :pAccelerationStructure, :pointer
  end
  typedef ZERtasBuilderInstanceGeometryInfoExp.by_value, :ze_rtas_builder_instance_geometry_info_exp_t

  class ZERtasBuilderBuildOpExpDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :rtasFormat, :ze_rtas_format_exp_t,
           :buildQuality, :ze_rtas_builder_build_quality_hint_exp_t,
           :buildFlags, :ze_rtas_builder_build_op_exp_flags_t,
           :ppGeometries, :pointer,
           :numGeometries, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_RTAS_BUILDER_BUILD_OP_EXP_DESC
      end
    end
  end
  typedef ZERtasBuilderBuildOpExpDesc.by_value, :ze_rtas_builder_build_op_exp_desc_t

  class ZEEventPoolCounterBasedExpDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_event_pool_counter_based_exp_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_COUNTER_BASED_EVENT_POOL_EXP_DESC
      end
    end
  end
  typedef ZEEventPoolCounterBasedExpDesc.by_value, :ze_event_pool_counter_based_exp_desc_t

  class ZEImageBindlessExpDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_image_bindless_exp_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_BINDLESS_IMAGE_EXP_DESC
      end
    end
  end
  typedef ZEImageBindlessExpDesc.by_value, :ze_image_bindless_exp_desc_t

  class ZEImagePitchedExpDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :ptr, :pointer

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_PITCHED_IMAGE_EXP_DESC
      end
    end
  end
  typedef ZEImagePitchedExpDesc.by_value, :ze_image_pitched_exp_desc_t

  class ZEDevicePitchedAllocExpProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :maxImageLinearWidth, :size_t,
           :maxImageLinearHeight, :size_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_PITCHED_ALLOC_DEVICE_EXP_PROPERTIES
      end
    end
  end
  typedef ZEDevicePitchedAllocExpProperties.by_value, :ze_device_pitched_alloc_exp_properties_t

  class ZEMutableCommandIdExpDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_mutable_command_exp_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_MUTABLE_COMMAND_ID_EXP_DESC
      end
    end
  end
  typedef ZEMutableCommandIdExpDesc.by_value, :ze_mutable_command_id_exp_desc_t

  class ZEMutableCommandListExpProperties < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :mutableCommandListFlags, :ze_mutable_command_list_exp_flags_t,
           :mutableCommandFlags, :ze_mutable_command_exp_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_MUTABLE_COMMAND_LIST_EXP_PROPERTIES
      end
    end
  end
  typedef ZEMutableCommandListExpProperties.by_value, :ze_mutable_command_list_exp_properties_t

  class ZEMutableCommandListExpDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :ze_mutable_command_list_exp_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_MUTABLE_COMMAND_LIST_EXP_DESC
      end
    end
  end
  typedef ZEMutableCommandListExpDesc.by_value, :ze_mutable_command_list_exp_desc_t

  class ZEMutableCommandsExpDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :flags, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_MUTABLE_COMMANDS_EXP_DESC
      end
    end
  end
  typedef ZEMutableCommandsExpDesc.by_value, :ze_mutable_commands_exp_desc_t

  class ZEMutableKernelArgumentExpDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :commandId, :uint64,
           :argIndex, :uint32,
           :argSize, :size_t,
           :pArgValue, :pointer

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_MUTABLE_KERNEL_ARGUMENT_EXP_DESC
      end
    end
  end
  typedef ZEMutableKernelArgumentExpDesc.by_value, :ze_mutable_kernel_argument_exp_desc_t

  class ZEMutableGroupCountExpDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :commandId, :uint64,
           :pGroupCount, :pointer

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_MUTABLE_GROUP_COUNT_EXP_DESC
      end
    end
  end
  typedef ZEMutableGroupCountExpDesc.by_value, :ze_mutable_group_count_exp_desc_t

  class ZEMutableGroupSizeExpDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :commandId, :uint64,
           :groupSizeX, :uint32,
           :groupSizeY, :uint32,
           :groupSizeZ, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_MUTABLE_GROUP_SIZE_EXP_DESC
      end
    end
  end
  typedef ZEMutableGroupSizeExpDesc.by_value, :ze_mutable_group_size_exp_desc_t

  class ZEMutableGlobalOffsetExpDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :commandId, :uint64,
           :offsetX, :uint32,
           :offsetY, :uint32,
           :offsetZ, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_MUTABLE_GLOBAL_OFFSET_EXP_DESC
      end
    end
  end
  typedef ZEMutableGlobalOffsetExpDesc.by_value, :ze_mutable_global_offset_exp_desc_t

  class ZEMutableGraphArgumentExpDesc < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :commandId, :uint64,
           :argIndex, :uint32,
           :pArgValue, :pointer

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZE_STRUCTURE_TYPE_MUTABLE_GRAPH_ARGUMENT_EXP_DESC
      end
    end
  end
  typedef ZEMutableGraphArgumentExpDesc.by_value, :ze_mutable_graph_argument_exp_desc_t

  class ZEInitParams < FFI::ZEStruct
    layout :pflags, :pointer
  end
  typedef ZEInitParams.by_value, :ze_init_params_t

  callback :ze_pfnInitCb_t,
           [ ZEInitParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEGlobalCallbacks < FFI::ZEStruct
    layout :pfnInitCb, :ze_pfnInitCb_t
  end
  typedef ZEGlobalCallbacks.by_value, :ze_global_callbacks_t

  class ZEDriverGetParams < FFI::ZEStruct
    layout :ppCount, :pointer,
           :pphDrivers, :pointer
  end
  typedef ZEDriverGetParams.by_value, :ze_driver_get_params_t

  callback :ze_pfnDriverGetCb_t,
           [ ZEDriverGetParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEDriverGetApiVersionParams < FFI::ZEStruct
    layout :phDriver, :pointer,
           :pversion, :pointer
  end
  typedef ZEDriverGetApiVersionParams.by_value, :ze_driver_get_api_version_params_t

  callback :ze_pfnDriverGetApiVersionCb_t,
           [ ZEDriverGetApiVersionParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEDriverGetPropertiesParams < FFI::ZEStruct
    layout :phDriver, :pointer,
           :ppDriverProperties, :pointer
  end
  typedef ZEDriverGetPropertiesParams.by_value, :ze_driver_get_properties_params_t

  callback :ze_pfnDriverGetPropertiesCb_t,
           [ ZEDriverGetPropertiesParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEDriverGetIpcPropertiesParams < FFI::ZEStruct
    layout :phDriver, :pointer,
           :ppIpcProperties, :pointer
  end
  typedef ZEDriverGetIpcPropertiesParams.by_value, :ze_driver_get_ipc_properties_params_t

  callback :ze_pfnDriverGetIpcPropertiesCb_t,
           [ ZEDriverGetIpcPropertiesParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEDriverGetExtensionPropertiesParams < FFI::ZEStruct
    layout :phDriver, :pointer,
           :ppCount, :pointer,
           :ppExtensionProperties, :pointer
  end
  typedef ZEDriverGetExtensionPropertiesParams.by_value, :ze_driver_get_extension_properties_params_t

  callback :ze_pfnDriverGetExtensionPropertiesCb_t,
           [ ZEDriverGetExtensionPropertiesParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEDriverCallbacks < FFI::ZEStruct
    layout :pfnGetCb, :ze_pfnDriverGetCb_t,
           :pfnGetApiVersionCb, :ze_pfnDriverGetApiVersionCb_t,
           :pfnGetPropertiesCb, :ze_pfnDriverGetPropertiesCb_t,
           :pfnGetIpcPropertiesCb, :ze_pfnDriverGetIpcPropertiesCb_t,
           :pfnGetExtensionPropertiesCb, :ze_pfnDriverGetExtensionPropertiesCb_t
  end
  typedef ZEDriverCallbacks.by_value, :ze_driver_callbacks_t

  class ZEDeviceGetParams < FFI::ZEStruct
    layout :phDriver, :pointer,
           :ppCount, :pointer,
           :pphDevices, :pointer
  end
  typedef ZEDeviceGetParams.by_value, :ze_device_get_params_t

  callback :ze_pfnDeviceGetCb_t,
           [ ZEDeviceGetParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEDeviceGetSubDevicesParams < FFI::ZEStruct
    layout :phDevice, :pointer,
           :ppCount, :pointer,
           :pphSubdevices, :pointer
  end
  typedef ZEDeviceGetSubDevicesParams.by_value, :ze_device_get_sub_devices_params_t

  callback :ze_pfnDeviceGetSubDevicesCb_t,
           [ ZEDeviceGetSubDevicesParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEDeviceGetPropertiesParams < FFI::ZEStruct
    layout :phDevice, :pointer,
           :ppDeviceProperties, :pointer
  end
  typedef ZEDeviceGetPropertiesParams.by_value, :ze_device_get_properties_params_t

  callback :ze_pfnDeviceGetPropertiesCb_t,
           [ ZEDeviceGetPropertiesParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEDeviceGetComputePropertiesParams < FFI::ZEStruct
    layout :phDevice, :pointer,
           :ppComputeProperties, :pointer
  end
  typedef ZEDeviceGetComputePropertiesParams.by_value, :ze_device_get_compute_properties_params_t

  callback :ze_pfnDeviceGetComputePropertiesCb_t,
           [ ZEDeviceGetComputePropertiesParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEDeviceGetModulePropertiesParams < FFI::ZEStruct
    layout :phDevice, :pointer,
           :ppModuleProperties, :pointer
  end
  typedef ZEDeviceGetModulePropertiesParams.by_value, :ze_device_get_module_properties_params_t

  callback :ze_pfnDeviceGetModulePropertiesCb_t,
           [ ZEDeviceGetModulePropertiesParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEDeviceGetCommandQueueGroupPropertiesParams < FFI::ZEStruct
    layout :phDevice, :pointer,
           :ppCount, :pointer,
           :ppCommandQueueGroupProperties, :pointer
  end
  typedef ZEDeviceGetCommandQueueGroupPropertiesParams.by_value, :ze_device_get_command_queue_group_properties_params_t

  callback :ze_pfnDeviceGetCommandQueueGroupPropertiesCb_t,
           [ ZEDeviceGetCommandQueueGroupPropertiesParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEDeviceGetMemoryPropertiesParams < FFI::ZEStruct
    layout :phDevice, :pointer,
           :ppCount, :pointer,
           :ppMemProperties, :pointer
  end
  typedef ZEDeviceGetMemoryPropertiesParams.by_value, :ze_device_get_memory_properties_params_t

  callback :ze_pfnDeviceGetMemoryPropertiesCb_t,
           [ ZEDeviceGetMemoryPropertiesParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEDeviceGetMemoryAccessPropertiesParams < FFI::ZEStruct
    layout :phDevice, :pointer,
           :ppMemAccessProperties, :pointer
  end
  typedef ZEDeviceGetMemoryAccessPropertiesParams.by_value, :ze_device_get_memory_access_properties_params_t

  callback :ze_pfnDeviceGetMemoryAccessPropertiesCb_t,
           [ ZEDeviceGetMemoryAccessPropertiesParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEDeviceGetCachePropertiesParams < FFI::ZEStruct
    layout :phDevice, :pointer,
           :ppCount, :pointer,
           :ppCacheProperties, :pointer
  end
  typedef ZEDeviceGetCachePropertiesParams.by_value, :ze_device_get_cache_properties_params_t

  callback :ze_pfnDeviceGetCachePropertiesCb_t,
           [ ZEDeviceGetCachePropertiesParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEDeviceGetImagePropertiesParams < FFI::ZEStruct
    layout :phDevice, :pointer,
           :ppImageProperties, :pointer
  end
  typedef ZEDeviceGetImagePropertiesParams.by_value, :ze_device_get_image_properties_params_t

  callback :ze_pfnDeviceGetImagePropertiesCb_t,
           [ ZEDeviceGetImagePropertiesParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEDeviceGetExternalMemoryPropertiesParams < FFI::ZEStruct
    layout :phDevice, :pointer,
           :ppExternalMemoryProperties, :pointer
  end
  typedef ZEDeviceGetExternalMemoryPropertiesParams.by_value, :ze_device_get_external_memory_properties_params_t

  callback :ze_pfnDeviceGetExternalMemoryPropertiesCb_t,
           [ ZEDeviceGetExternalMemoryPropertiesParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEDeviceGetP2PPropertiesParams < FFI::ZEStruct
    layout :phDevice, :pointer,
           :phPeerDevice, :pointer,
           :ppP2PProperties, :pointer
  end
  typedef ZEDeviceGetP2PPropertiesParams.by_value, :ze_device_get_p2_p_properties_params_t

  callback :ze_pfnDeviceGetP2PPropertiesCb_t,
           [ ZEDeviceGetP2PPropertiesParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEDeviceCanAccessPeerParams < FFI::ZEStruct
    layout :phDevice, :pointer,
           :phPeerDevice, :pointer,
           :pvalue, :pointer
  end
  typedef ZEDeviceCanAccessPeerParams.by_value, :ze_device_can_access_peer_params_t

  callback :ze_pfnDeviceCanAccessPeerCb_t,
           [ ZEDeviceCanAccessPeerParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEDeviceGetStatusParams < FFI::ZEStruct
    layout :phDevice, :pointer
  end
  typedef ZEDeviceGetStatusParams.by_value, :ze_device_get_status_params_t

  callback :ze_pfnDeviceGetStatusCb_t,
           [ ZEDeviceGetStatusParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEDeviceCallbacks < FFI::ZEStruct
    layout :pfnGetCb, :ze_pfnDeviceGetCb_t,
           :pfnGetSubDevicesCb, :ze_pfnDeviceGetSubDevicesCb_t,
           :pfnGetPropertiesCb, :ze_pfnDeviceGetPropertiesCb_t,
           :pfnGetComputePropertiesCb, :ze_pfnDeviceGetComputePropertiesCb_t,
           :pfnGetModulePropertiesCb, :ze_pfnDeviceGetModulePropertiesCb_t,
           :pfnGetCommandQueueGroupPropertiesCb, :ze_pfnDeviceGetCommandQueueGroupPropertiesCb_t,
           :pfnGetMemoryPropertiesCb, :ze_pfnDeviceGetMemoryPropertiesCb_t,
           :pfnGetMemoryAccessPropertiesCb, :ze_pfnDeviceGetMemoryAccessPropertiesCb_t,
           :pfnGetCachePropertiesCb, :ze_pfnDeviceGetCachePropertiesCb_t,
           :pfnGetImagePropertiesCb, :ze_pfnDeviceGetImagePropertiesCb_t,
           :pfnGetExternalMemoryPropertiesCb, :ze_pfnDeviceGetExternalMemoryPropertiesCb_t,
           :pfnGetP2PPropertiesCb, :ze_pfnDeviceGetP2PPropertiesCb_t,
           :pfnCanAccessPeerCb, :ze_pfnDeviceCanAccessPeerCb_t,
           :pfnGetStatusCb, :ze_pfnDeviceGetStatusCb_t
  end
  typedef ZEDeviceCallbacks.by_value, :ze_device_callbacks_t

  class ZEContextCreateParams < FFI::ZEStruct
    layout :phDriver, :pointer,
           :pdesc, :pointer,
           :pphContext, :pointer
  end
  typedef ZEContextCreateParams.by_value, :ze_context_create_params_t

  callback :ze_pfnContextCreateCb_t,
           [ ZEContextCreateParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEContextDestroyParams < FFI::ZEStruct
    layout :phContext, :pointer
  end
  typedef ZEContextDestroyParams.by_value, :ze_context_destroy_params_t

  callback :ze_pfnContextDestroyCb_t,
           [ ZEContextDestroyParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEContextGetStatusParams < FFI::ZEStruct
    layout :phContext, :pointer
  end
  typedef ZEContextGetStatusParams.by_value, :ze_context_get_status_params_t

  callback :ze_pfnContextGetStatusCb_t,
           [ ZEContextGetStatusParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEContextSystemBarrierParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :phDevice, :pointer
  end
  typedef ZEContextSystemBarrierParams.by_value, :ze_context_system_barrier_params_t

  callback :ze_pfnContextSystemBarrierCb_t,
           [ ZEContextSystemBarrierParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEContextMakeMemoryResidentParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :phDevice, :pointer,
           :pptr, :pointer,
           :psize, :pointer
  end
  typedef ZEContextMakeMemoryResidentParams.by_value, :ze_context_make_memory_resident_params_t

  callback :ze_pfnContextMakeMemoryResidentCb_t,
           [ ZEContextMakeMemoryResidentParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEContextEvictMemoryParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :phDevice, :pointer,
           :pptr, :pointer,
           :psize, :pointer
  end
  typedef ZEContextEvictMemoryParams.by_value, :ze_context_evict_memory_params_t

  callback :ze_pfnContextEvictMemoryCb_t,
           [ ZEContextEvictMemoryParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEContextMakeImageResidentParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :phDevice, :pointer,
           :phImage, :pointer
  end
  typedef ZEContextMakeImageResidentParams.by_value, :ze_context_make_image_resident_params_t

  callback :ze_pfnContextMakeImageResidentCb_t,
           [ ZEContextMakeImageResidentParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEContextEvictImageParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :phDevice, :pointer,
           :phImage, :pointer
  end
  typedef ZEContextEvictImageParams.by_value, :ze_context_evict_image_params_t

  callback :ze_pfnContextEvictImageCb_t,
           [ ZEContextEvictImageParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEContextCallbacks < FFI::ZEStruct
    layout :pfnCreateCb, :ze_pfnContextCreateCb_t,
           :pfnDestroyCb, :ze_pfnContextDestroyCb_t,
           :pfnGetStatusCb, :ze_pfnContextGetStatusCb_t,
           :pfnSystemBarrierCb, :ze_pfnContextSystemBarrierCb_t,
           :pfnMakeMemoryResidentCb, :ze_pfnContextMakeMemoryResidentCb_t,
           :pfnEvictMemoryCb, :ze_pfnContextEvictMemoryCb_t,
           :pfnMakeImageResidentCb, :ze_pfnContextMakeImageResidentCb_t,
           :pfnEvictImageCb, :ze_pfnContextEvictImageCb_t
  end
  typedef ZEContextCallbacks.by_value, :ze_context_callbacks_t

  class ZECommandQueueCreateParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :phDevice, :pointer,
           :pdesc, :pointer,
           :pphCommandQueue, :pointer
  end
  typedef ZECommandQueueCreateParams.by_value, :ze_command_queue_create_params_t

  callback :ze_pfnCommandQueueCreateCb_t,
           [ ZECommandQueueCreateParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandQueueDestroyParams < FFI::ZEStruct
    layout :phCommandQueue, :pointer
  end
  typedef ZECommandQueueDestroyParams.by_value, :ze_command_queue_destroy_params_t

  callback :ze_pfnCommandQueueDestroyCb_t,
           [ ZECommandQueueDestroyParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandQueueExecuteCommandListsParams < FFI::ZEStruct
    layout :phCommandQueue, :pointer,
           :pnumCommandLists, :pointer,
           :pphCommandLists, :pointer,
           :phFence, :pointer
  end
  typedef ZECommandQueueExecuteCommandListsParams.by_value, :ze_command_queue_execute_command_lists_params_t

  callback :ze_pfnCommandQueueExecuteCommandListsCb_t,
           [ ZECommandQueueExecuteCommandListsParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandQueueSynchronizeParams < FFI::ZEStruct
    layout :phCommandQueue, :pointer,
           :ptimeout, :pointer
  end
  typedef ZECommandQueueSynchronizeParams.by_value, :ze_command_queue_synchronize_params_t

  callback :ze_pfnCommandQueueSynchronizeCb_t,
           [ ZECommandQueueSynchronizeParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandQueueCallbacks < FFI::ZEStruct
    layout :pfnCreateCb, :ze_pfnCommandQueueCreateCb_t,
           :pfnDestroyCb, :ze_pfnCommandQueueDestroyCb_t,
           :pfnExecuteCommandListsCb, :ze_pfnCommandQueueExecuteCommandListsCb_t,
           :pfnSynchronizeCb, :ze_pfnCommandQueueSynchronizeCb_t
  end
  typedef ZECommandQueueCallbacks.by_value, :ze_command_queue_callbacks_t

  class ZECommandListCreateParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :phDevice, :pointer,
           :pdesc, :pointer,
           :pphCommandList, :pointer
  end
  typedef ZECommandListCreateParams.by_value, :ze_command_list_create_params_t

  callback :ze_pfnCommandListCreateCb_t,
           [ ZECommandListCreateParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListCreateImmediateParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :phDevice, :pointer,
           :paltdesc, :pointer,
           :pphCommandList, :pointer
  end
  typedef ZECommandListCreateImmediateParams.by_value, :ze_command_list_create_immediate_params_t

  callback :ze_pfnCommandListCreateImmediateCb_t,
           [ ZECommandListCreateImmediateParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListDestroyParams < FFI::ZEStruct
    layout :phCommandList, :pointer
  end
  typedef ZECommandListDestroyParams.by_value, :ze_command_list_destroy_params_t

  callback :ze_pfnCommandListDestroyCb_t,
           [ ZECommandListDestroyParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListCloseParams < FFI::ZEStruct
    layout :phCommandList, :pointer
  end
  typedef ZECommandListCloseParams.by_value, :ze_command_list_close_params_t

  callback :ze_pfnCommandListCloseCb_t,
           [ ZECommandListCloseParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListResetParams < FFI::ZEStruct
    layout :phCommandList, :pointer
  end
  typedef ZECommandListResetParams.by_value, :ze_command_list_reset_params_t

  callback :ze_pfnCommandListResetCb_t,
           [ ZECommandListResetParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListAppendWriteGlobalTimestampParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :pdstptr, :pointer,
           :phSignalEvent, :pointer,
           :pnumWaitEvents, :pointer,
           :pphWaitEvents, :pointer
  end
  typedef ZECommandListAppendWriteGlobalTimestampParams.by_value, :ze_command_list_append_write_global_timestamp_params_t

  callback :ze_pfnCommandListAppendWriteGlobalTimestampCb_t,
           [ ZECommandListAppendWriteGlobalTimestampParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListAppendBarrierParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :phSignalEvent, :pointer,
           :pnumWaitEvents, :pointer,
           :pphWaitEvents, :pointer
  end
  typedef ZECommandListAppendBarrierParams.by_value, :ze_command_list_append_barrier_params_t

  callback :ze_pfnCommandListAppendBarrierCb_t,
           [ ZECommandListAppendBarrierParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListAppendMemoryRangesBarrierParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :pnumRanges, :pointer,
           :ppRangeSizes, :pointer,
           :ppRanges, :pointer,
           :phSignalEvent, :pointer,
           :pnumWaitEvents, :pointer,
           :pphWaitEvents, :pointer
  end
  typedef ZECommandListAppendMemoryRangesBarrierParams.by_value, :ze_command_list_append_memory_ranges_barrier_params_t

  callback :ze_pfnCommandListAppendMemoryRangesBarrierCb_t,
           [ ZECommandListAppendMemoryRangesBarrierParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListAppendMemoryCopyParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :pdstptr, :pointer,
           :psrcptr, :pointer,
           :psize, :pointer,
           :phSignalEvent, :pointer,
           :pnumWaitEvents, :pointer,
           :pphWaitEvents, :pointer
  end
  typedef ZECommandListAppendMemoryCopyParams.by_value, :ze_command_list_append_memory_copy_params_t

  callback :ze_pfnCommandListAppendMemoryCopyCb_t,
           [ ZECommandListAppendMemoryCopyParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListAppendMemoryFillParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :pptr, :pointer,
           :ppattern, :pointer,
           :ppattern_size, :pointer,
           :psize, :pointer,
           :phSignalEvent, :pointer,
           :pnumWaitEvents, :pointer,
           :pphWaitEvents, :pointer
  end
  typedef ZECommandListAppendMemoryFillParams.by_value, :ze_command_list_append_memory_fill_params_t

  callback :ze_pfnCommandListAppendMemoryFillCb_t,
           [ ZECommandListAppendMemoryFillParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListAppendMemoryCopyRegionParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :pdstptr, :pointer,
           :pdstRegion, :pointer,
           :pdstPitch, :pointer,
           :pdstSlicePitch, :pointer,
           :psrcptr, :pointer,
           :psrcRegion, :pointer,
           :psrcPitch, :pointer,
           :psrcSlicePitch, :pointer,
           :phSignalEvent, :pointer,
           :pnumWaitEvents, :pointer,
           :pphWaitEvents, :pointer
  end
  typedef ZECommandListAppendMemoryCopyRegionParams.by_value, :ze_command_list_append_memory_copy_region_params_t

  callback :ze_pfnCommandListAppendMemoryCopyRegionCb_t,
           [ ZECommandListAppendMemoryCopyRegionParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListAppendMemoryCopyFromContextParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :pdstptr, :pointer,
           :phContextSrc, :pointer,
           :psrcptr, :pointer,
           :psize, :pointer,
           :phSignalEvent, :pointer,
           :pnumWaitEvents, :pointer,
           :pphWaitEvents, :pointer
  end
  typedef ZECommandListAppendMemoryCopyFromContextParams.by_value, :ze_command_list_append_memory_copy_from_context_params_t

  callback :ze_pfnCommandListAppendMemoryCopyFromContextCb_t,
           [ ZECommandListAppendMemoryCopyFromContextParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListAppendImageCopyParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :phDstImage, :pointer,
           :phSrcImage, :pointer,
           :phSignalEvent, :pointer,
           :pnumWaitEvents, :pointer,
           :pphWaitEvents, :pointer
  end
  typedef ZECommandListAppendImageCopyParams.by_value, :ze_command_list_append_image_copy_params_t

  callback :ze_pfnCommandListAppendImageCopyCb_t,
           [ ZECommandListAppendImageCopyParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListAppendImageCopyRegionParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :phDstImage, :pointer,
           :phSrcImage, :pointer,
           :ppDstRegion, :pointer,
           :ppSrcRegion, :pointer,
           :phSignalEvent, :pointer,
           :pnumWaitEvents, :pointer,
           :pphWaitEvents, :pointer
  end
  typedef ZECommandListAppendImageCopyRegionParams.by_value, :ze_command_list_append_image_copy_region_params_t

  callback :ze_pfnCommandListAppendImageCopyRegionCb_t,
           [ ZECommandListAppendImageCopyRegionParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListAppendImageCopyToMemoryParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :pdstptr, :pointer,
           :phSrcImage, :pointer,
           :ppSrcRegion, :pointer,
           :phSignalEvent, :pointer,
           :pnumWaitEvents, :pointer,
           :pphWaitEvents, :pointer
  end
  typedef ZECommandListAppendImageCopyToMemoryParams.by_value, :ze_command_list_append_image_copy_to_memory_params_t

  callback :ze_pfnCommandListAppendImageCopyToMemoryCb_t,
           [ ZECommandListAppendImageCopyToMemoryParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListAppendImageCopyFromMemoryParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :phDstImage, :pointer,
           :psrcptr, :pointer,
           :ppDstRegion, :pointer,
           :phSignalEvent, :pointer,
           :pnumWaitEvents, :pointer,
           :pphWaitEvents, :pointer
  end
  typedef ZECommandListAppendImageCopyFromMemoryParams.by_value, :ze_command_list_append_image_copy_from_memory_params_t

  callback :ze_pfnCommandListAppendImageCopyFromMemoryCb_t,
           [ ZECommandListAppendImageCopyFromMemoryParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListAppendMemoryPrefetchParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :pptr, :pointer,
           :psize, :pointer
  end
  typedef ZECommandListAppendMemoryPrefetchParams.by_value, :ze_command_list_append_memory_prefetch_params_t

  callback :ze_pfnCommandListAppendMemoryPrefetchCb_t,
           [ ZECommandListAppendMemoryPrefetchParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListAppendMemAdviseParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :phDevice, :pointer,
           :pptr, :pointer,
           :psize, :pointer,
           :padvice, :pointer
  end
  typedef ZECommandListAppendMemAdviseParams.by_value, :ze_command_list_append_mem_advise_params_t

  callback :ze_pfnCommandListAppendMemAdviseCb_t,
           [ ZECommandListAppendMemAdviseParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListAppendSignalEventParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :phEvent, :pointer
  end
  typedef ZECommandListAppendSignalEventParams.by_value, :ze_command_list_append_signal_event_params_t

  callback :ze_pfnCommandListAppendSignalEventCb_t,
           [ ZECommandListAppendSignalEventParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListAppendWaitOnEventsParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :pnumEvents, :pointer,
           :pphEvents, :pointer
  end
  typedef ZECommandListAppendWaitOnEventsParams.by_value, :ze_command_list_append_wait_on_events_params_t

  callback :ze_pfnCommandListAppendWaitOnEventsCb_t,
           [ ZECommandListAppendWaitOnEventsParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListAppendEventResetParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :phEvent, :pointer
  end
  typedef ZECommandListAppendEventResetParams.by_value, :ze_command_list_append_event_reset_params_t

  callback :ze_pfnCommandListAppendEventResetCb_t,
           [ ZECommandListAppendEventResetParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListAppendQueryKernelTimestampsParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :pnumEvents, :pointer,
           :pphEvents, :pointer,
           :pdstptr, :pointer,
           :ppOffsets, :pointer,
           :phSignalEvent, :pointer,
           :pnumWaitEvents, :pointer,
           :pphWaitEvents, :pointer
  end
  typedef ZECommandListAppendQueryKernelTimestampsParams.by_value, :ze_command_list_append_query_kernel_timestamps_params_t

  callback :ze_pfnCommandListAppendQueryKernelTimestampsCb_t,
           [ ZECommandListAppendQueryKernelTimestampsParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListAppendLaunchKernelParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :phKernel, :pointer,
           :ppLaunchFuncArgs, :pointer,
           :phSignalEvent, :pointer,
           :pnumWaitEvents, :pointer,
           :pphWaitEvents, :pointer
  end
  typedef ZECommandListAppendLaunchKernelParams.by_value, :ze_command_list_append_launch_kernel_params_t

  callback :ze_pfnCommandListAppendLaunchKernelCb_t,
           [ ZECommandListAppendLaunchKernelParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListAppendLaunchCooperativeKernelParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :phKernel, :pointer,
           :ppLaunchFuncArgs, :pointer,
           :phSignalEvent, :pointer,
           :pnumWaitEvents, :pointer,
           :pphWaitEvents, :pointer
  end
  typedef ZECommandListAppendLaunchCooperativeKernelParams.by_value, :ze_command_list_append_launch_cooperative_kernel_params_t

  callback :ze_pfnCommandListAppendLaunchCooperativeKernelCb_t,
           [ ZECommandListAppendLaunchCooperativeKernelParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListAppendLaunchKernelIndirectParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :phKernel, :pointer,
           :ppLaunchArgumentsBuffer, :pointer,
           :phSignalEvent, :pointer,
           :pnumWaitEvents, :pointer,
           :pphWaitEvents, :pointer
  end
  typedef ZECommandListAppendLaunchKernelIndirectParams.by_value, :ze_command_list_append_launch_kernel_indirect_params_t

  callback :ze_pfnCommandListAppendLaunchKernelIndirectCb_t,
           [ ZECommandListAppendLaunchKernelIndirectParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListAppendLaunchMultipleKernelsIndirectParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :pnumKernels, :pointer,
           :pphKernels, :pointer,
           :ppCountBuffer, :pointer,
           :ppLaunchArgumentsBuffer, :pointer,
           :phSignalEvent, :pointer,
           :pnumWaitEvents, :pointer,
           :pphWaitEvents, :pointer
  end
  typedef ZECommandListAppendLaunchMultipleKernelsIndirectParams.by_value, :ze_command_list_append_launch_multiple_kernels_indirect_params_t

  callback :ze_pfnCommandListAppendLaunchMultipleKernelsIndirectCb_t,
           [ ZECommandListAppendLaunchMultipleKernelsIndirectParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListCallbacks < FFI::ZEStruct
    layout :pfnCreateCb, :ze_pfnCommandListCreateCb_t,
           :pfnCreateImmediateCb, :ze_pfnCommandListCreateImmediateCb_t,
           :pfnDestroyCb, :ze_pfnCommandListDestroyCb_t,
           :pfnCloseCb, :ze_pfnCommandListCloseCb_t,
           :pfnResetCb, :ze_pfnCommandListResetCb_t,
           :pfnAppendWriteGlobalTimestampCb, :ze_pfnCommandListAppendWriteGlobalTimestampCb_t,
           :pfnAppendBarrierCb, :ze_pfnCommandListAppendBarrierCb_t,
           :pfnAppendMemoryRangesBarrierCb, :ze_pfnCommandListAppendMemoryRangesBarrierCb_t,
           :pfnAppendMemoryCopyCb, :ze_pfnCommandListAppendMemoryCopyCb_t,
           :pfnAppendMemoryFillCb, :ze_pfnCommandListAppendMemoryFillCb_t,
           :pfnAppendMemoryCopyRegionCb, :ze_pfnCommandListAppendMemoryCopyRegionCb_t,
           :pfnAppendMemoryCopyFromContextCb, :ze_pfnCommandListAppendMemoryCopyFromContextCb_t,
           :pfnAppendImageCopyCb, :ze_pfnCommandListAppendImageCopyCb_t,
           :pfnAppendImageCopyRegionCb, :ze_pfnCommandListAppendImageCopyRegionCb_t,
           :pfnAppendImageCopyToMemoryCb, :ze_pfnCommandListAppendImageCopyToMemoryCb_t,
           :pfnAppendImageCopyFromMemoryCb, :ze_pfnCommandListAppendImageCopyFromMemoryCb_t,
           :pfnAppendMemoryPrefetchCb, :ze_pfnCommandListAppendMemoryPrefetchCb_t,
           :pfnAppendMemAdviseCb, :ze_pfnCommandListAppendMemAdviseCb_t,
           :pfnAppendSignalEventCb, :ze_pfnCommandListAppendSignalEventCb_t,
           :pfnAppendWaitOnEventsCb, :ze_pfnCommandListAppendWaitOnEventsCb_t,
           :pfnAppendEventResetCb, :ze_pfnCommandListAppendEventResetCb_t,
           :pfnAppendQueryKernelTimestampsCb, :ze_pfnCommandListAppendQueryKernelTimestampsCb_t,
           :pfnAppendLaunchKernelCb, :ze_pfnCommandListAppendLaunchKernelCb_t,
           :pfnAppendLaunchCooperativeKernelCb, :ze_pfnCommandListAppendLaunchCooperativeKernelCb_t,
           :pfnAppendLaunchKernelIndirectCb, :ze_pfnCommandListAppendLaunchKernelIndirectCb_t,
           :pfnAppendLaunchMultipleKernelsIndirectCb, :ze_pfnCommandListAppendLaunchMultipleKernelsIndirectCb_t
  end
  typedef ZECommandListCallbacks.by_value, :ze_command_list_callbacks_t

  class ZEImageGetPropertiesParams < FFI::ZEStruct
    layout :phDevice, :pointer,
           :pdesc, :pointer,
           :ppImageProperties, :pointer
  end
  typedef ZEImageGetPropertiesParams.by_value, :ze_image_get_properties_params_t

  callback :ze_pfnImageGetPropertiesCb_t,
           [ ZEImageGetPropertiesParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEImageCreateParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :phDevice, :pointer,
           :pdesc, :pointer,
           :pphImage, :pointer
  end
  typedef ZEImageCreateParams.by_value, :ze_image_create_params_t

  callback :ze_pfnImageCreateCb_t,
           [ ZEImageCreateParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEImageDestroyParams < FFI::ZEStruct
    layout :phImage, :pointer
  end
  typedef ZEImageDestroyParams.by_value, :ze_image_destroy_params_t

  callback :ze_pfnImageDestroyCb_t,
           [ ZEImageDestroyParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEImageCallbacks < FFI::ZEStruct
    layout :pfnGetPropertiesCb, :ze_pfnImageGetPropertiesCb_t,
           :pfnCreateCb, :ze_pfnImageCreateCb_t,
           :pfnDestroyCb, :ze_pfnImageDestroyCb_t
  end
  typedef ZEImageCallbacks.by_value, :ze_image_callbacks_t

  class ZEMemAllocSharedParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :pdevice_desc, :pointer,
           :phost_desc, :pointer,
           :psize, :pointer,
           :palignment, :pointer,
           :phDevice, :pointer,
           :ppptr, :pointer
  end
  typedef ZEMemAllocSharedParams.by_value, :ze_mem_alloc_shared_params_t

  callback :ze_pfnMemAllocSharedCb_t,
           [ ZEMemAllocSharedParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEMemAllocDeviceParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :pdevice_desc, :pointer,
           :psize, :pointer,
           :palignment, :pointer,
           :phDevice, :pointer,
           :ppptr, :pointer
  end
  typedef ZEMemAllocDeviceParams.by_value, :ze_mem_alloc_device_params_t

  callback :ze_pfnMemAllocDeviceCb_t,
           [ ZEMemAllocDeviceParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEMemAllocHostParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :phost_desc, :pointer,
           :psize, :pointer,
           :palignment, :pointer,
           :ppptr, :pointer
  end
  typedef ZEMemAllocHostParams.by_value, :ze_mem_alloc_host_params_t

  callback :ze_pfnMemAllocHostCb_t,
           [ ZEMemAllocHostParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEMemFreeParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :pptr, :pointer
  end
  typedef ZEMemFreeParams.by_value, :ze_mem_free_params_t

  callback :ze_pfnMemFreeCb_t,
           [ ZEMemFreeParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEMemGetAllocPropertiesParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :pptr, :pointer,
           :ppMemAllocProperties, :pointer,
           :pphDevice, :pointer
  end
  typedef ZEMemGetAllocPropertiesParams.by_value, :ze_mem_get_alloc_properties_params_t

  callback :ze_pfnMemGetAllocPropertiesCb_t,
           [ ZEMemGetAllocPropertiesParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEMemGetAddressRangeParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :pptr, :pointer,
           :ppBase, :pointer,
           :ppSize, :pointer
  end
  typedef ZEMemGetAddressRangeParams.by_value, :ze_mem_get_address_range_params_t

  callback :ze_pfnMemGetAddressRangeCb_t,
           [ ZEMemGetAddressRangeParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEMemGetIpcHandleParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :pptr, :pointer,
           :ppIpcHandle, :pointer
  end
  typedef ZEMemGetIpcHandleParams.by_value, :ze_mem_get_ipc_handle_params_t

  callback :ze_pfnMemGetIpcHandleCb_t,
           [ ZEMemGetIpcHandleParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEMemOpenIpcHandleParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :phDevice, :pointer,
           :phandle, :pointer,
           :pflags, :pointer,
           :ppptr, :pointer
  end
  typedef ZEMemOpenIpcHandleParams.by_value, :ze_mem_open_ipc_handle_params_t

  callback :ze_pfnMemOpenIpcHandleCb_t,
           [ ZEMemOpenIpcHandleParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEMemCloseIpcHandleParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :pptr, :pointer
  end
  typedef ZEMemCloseIpcHandleParams.by_value, :ze_mem_close_ipc_handle_params_t

  callback :ze_pfnMemCloseIpcHandleCb_t,
           [ ZEMemCloseIpcHandleParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEMemCallbacks < FFI::ZEStruct
    layout :pfnAllocSharedCb, :ze_pfnMemAllocSharedCb_t,
           :pfnAllocDeviceCb, :ze_pfnMemAllocDeviceCb_t,
           :pfnAllocHostCb, :ze_pfnMemAllocHostCb_t,
           :pfnFreeCb, :ze_pfnMemFreeCb_t,
           :pfnGetAllocPropertiesCb, :ze_pfnMemGetAllocPropertiesCb_t,
           :pfnGetAddressRangeCb, :ze_pfnMemGetAddressRangeCb_t,
           :pfnGetIpcHandleCb, :ze_pfnMemGetIpcHandleCb_t,
           :pfnOpenIpcHandleCb, :ze_pfnMemOpenIpcHandleCb_t,
           :pfnCloseIpcHandleCb, :ze_pfnMemCloseIpcHandleCb_t
  end
  typedef ZEMemCallbacks.by_value, :ze_mem_callbacks_t

  class ZEFenceCreateParams < FFI::ZEStruct
    layout :phCommandQueue, :pointer,
           :pdesc, :pointer,
           :pphFence, :pointer
  end
  typedef ZEFenceCreateParams.by_value, :ze_fence_create_params_t

  callback :ze_pfnFenceCreateCb_t,
           [ ZEFenceCreateParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEFenceDestroyParams < FFI::ZEStruct
    layout :phFence, :pointer
  end
  typedef ZEFenceDestroyParams.by_value, :ze_fence_destroy_params_t

  callback :ze_pfnFenceDestroyCb_t,
           [ ZEFenceDestroyParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEFenceHostSynchronizeParams < FFI::ZEStruct
    layout :phFence, :pointer,
           :ptimeout, :pointer
  end
  typedef ZEFenceHostSynchronizeParams.by_value, :ze_fence_host_synchronize_params_t

  callback :ze_pfnFenceHostSynchronizeCb_t,
           [ ZEFenceHostSynchronizeParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEFenceQueryStatusParams < FFI::ZEStruct
    layout :phFence, :pointer
  end
  typedef ZEFenceQueryStatusParams.by_value, :ze_fence_query_status_params_t

  callback :ze_pfnFenceQueryStatusCb_t,
           [ ZEFenceQueryStatusParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEFenceResetParams < FFI::ZEStruct
    layout :phFence, :pointer
  end
  typedef ZEFenceResetParams.by_value, :ze_fence_reset_params_t

  callback :ze_pfnFenceResetCb_t,
           [ ZEFenceResetParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEFenceCallbacks < FFI::ZEStruct
    layout :pfnCreateCb, :ze_pfnFenceCreateCb_t,
           :pfnDestroyCb, :ze_pfnFenceDestroyCb_t,
           :pfnHostSynchronizeCb, :ze_pfnFenceHostSynchronizeCb_t,
           :pfnQueryStatusCb, :ze_pfnFenceQueryStatusCb_t,
           :pfnResetCb, :ze_pfnFenceResetCb_t
  end
  typedef ZEFenceCallbacks.by_value, :ze_fence_callbacks_t

  class ZEEventPoolCreateParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :pdesc, :pointer,
           :pnumDevices, :pointer,
           :pphDevices, :pointer,
           :pphEventPool, :pointer
  end
  typedef ZEEventPoolCreateParams.by_value, :ze_event_pool_create_params_t

  callback :ze_pfnEventPoolCreateCb_t,
           [ ZEEventPoolCreateParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEEventPoolDestroyParams < FFI::ZEStruct
    layout :phEventPool, :pointer
  end
  typedef ZEEventPoolDestroyParams.by_value, :ze_event_pool_destroy_params_t

  callback :ze_pfnEventPoolDestroyCb_t,
           [ ZEEventPoolDestroyParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEEventPoolGetIpcHandleParams < FFI::ZEStruct
    layout :phEventPool, :pointer,
           :pphIpc, :pointer
  end
  typedef ZEEventPoolGetIpcHandleParams.by_value, :ze_event_pool_get_ipc_handle_params_t

  callback :ze_pfnEventPoolGetIpcHandleCb_t,
           [ ZEEventPoolGetIpcHandleParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEEventPoolOpenIpcHandleParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :phIpc, :pointer,
           :pphEventPool, :pointer
  end
  typedef ZEEventPoolOpenIpcHandleParams.by_value, :ze_event_pool_open_ipc_handle_params_t

  callback :ze_pfnEventPoolOpenIpcHandleCb_t,
           [ ZEEventPoolOpenIpcHandleParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEEventPoolCloseIpcHandleParams < FFI::ZEStruct
    layout :phEventPool, :pointer
  end
  typedef ZEEventPoolCloseIpcHandleParams.by_value, :ze_event_pool_close_ipc_handle_params_t

  callback :ze_pfnEventPoolCloseIpcHandleCb_t,
           [ ZEEventPoolCloseIpcHandleParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEEventPoolCallbacks < FFI::ZEStruct
    layout :pfnCreateCb, :ze_pfnEventPoolCreateCb_t,
           :pfnDestroyCb, :ze_pfnEventPoolDestroyCb_t,
           :pfnGetIpcHandleCb, :ze_pfnEventPoolGetIpcHandleCb_t,
           :pfnOpenIpcHandleCb, :ze_pfnEventPoolOpenIpcHandleCb_t,
           :pfnCloseIpcHandleCb, :ze_pfnEventPoolCloseIpcHandleCb_t
  end
  typedef ZEEventPoolCallbacks.by_value, :ze_event_pool_callbacks_t

  class ZEEventCreateParams < FFI::ZEStruct
    layout :phEventPool, :pointer,
           :pdesc, :pointer,
           :pphEvent, :pointer
  end
  typedef ZEEventCreateParams.by_value, :ze_event_create_params_t

  callback :ze_pfnEventCreateCb_t,
           [ ZEEventCreateParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEEventDestroyParams < FFI::ZEStruct
    layout :phEvent, :pointer
  end
  typedef ZEEventDestroyParams.by_value, :ze_event_destroy_params_t

  callback :ze_pfnEventDestroyCb_t,
           [ ZEEventDestroyParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEEventHostSignalParams < FFI::ZEStruct
    layout :phEvent, :pointer
  end
  typedef ZEEventHostSignalParams.by_value, :ze_event_host_signal_params_t

  callback :ze_pfnEventHostSignalCb_t,
           [ ZEEventHostSignalParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEEventHostSynchronizeParams < FFI::ZEStruct
    layout :phEvent, :pointer,
           :ptimeout, :pointer
  end
  typedef ZEEventHostSynchronizeParams.by_value, :ze_event_host_synchronize_params_t

  callback :ze_pfnEventHostSynchronizeCb_t,
           [ ZEEventHostSynchronizeParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEEventQueryStatusParams < FFI::ZEStruct
    layout :phEvent, :pointer
  end
  typedef ZEEventQueryStatusParams.by_value, :ze_event_query_status_params_t

  callback :ze_pfnEventQueryStatusCb_t,
           [ ZEEventQueryStatusParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEEventHostResetParams < FFI::ZEStruct
    layout :phEvent, :pointer
  end
  typedef ZEEventHostResetParams.by_value, :ze_event_host_reset_params_t

  callback :ze_pfnEventHostResetCb_t,
           [ ZEEventHostResetParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEEventQueryKernelTimestampParams < FFI::ZEStruct
    layout :phEvent, :pointer,
           :pdstptr, :pointer
  end
  typedef ZEEventQueryKernelTimestampParams.by_value, :ze_event_query_kernel_timestamp_params_t

  callback :ze_pfnEventQueryKernelTimestampCb_t,
           [ ZEEventQueryKernelTimestampParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEEventCallbacks < FFI::ZEStruct
    layout :pfnCreateCb, :ze_pfnEventCreateCb_t,
           :pfnDestroyCb, :ze_pfnEventDestroyCb_t,
           :pfnHostSignalCb, :ze_pfnEventHostSignalCb_t,
           :pfnHostSynchronizeCb, :ze_pfnEventHostSynchronizeCb_t,
           :pfnQueryStatusCb, :ze_pfnEventQueryStatusCb_t,
           :pfnHostResetCb, :ze_pfnEventHostResetCb_t,
           :pfnQueryKernelTimestampCb, :ze_pfnEventQueryKernelTimestampCb_t
  end
  typedef ZEEventCallbacks.by_value, :ze_event_callbacks_t

  class ZEModuleCreateParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :phDevice, :pointer,
           :pdesc, :pointer,
           :pphModule, :pointer,
           :pphBuildLog, :pointer
  end
  typedef ZEModuleCreateParams.by_value, :ze_module_create_params_t

  callback :ze_pfnModuleCreateCb_t,
           [ ZEModuleCreateParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEModuleDestroyParams < FFI::ZEStruct
    layout :phModule, :pointer
  end
  typedef ZEModuleDestroyParams.by_value, :ze_module_destroy_params_t

  callback :ze_pfnModuleDestroyCb_t,
           [ ZEModuleDestroyParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEModuleDynamicLinkParams < FFI::ZEStruct
    layout :pnumModules, :pointer,
           :pphModules, :pointer,
           :pphLinkLog, :pointer
  end
  typedef ZEModuleDynamicLinkParams.by_value, :ze_module_dynamic_link_params_t

  callback :ze_pfnModuleDynamicLinkCb_t,
           [ ZEModuleDynamicLinkParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEModuleGetNativeBinaryParams < FFI::ZEStruct
    layout :phModule, :pointer,
           :ppSize, :pointer,
           :ppModuleNativeBinary, :pointer
  end
  typedef ZEModuleGetNativeBinaryParams.by_value, :ze_module_get_native_binary_params_t

  callback :ze_pfnModuleGetNativeBinaryCb_t,
           [ ZEModuleGetNativeBinaryParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEModuleGetGlobalPointerParams < FFI::ZEStruct
    layout :phModule, :pointer,
           :ppGlobalName, :pointer,
           :ppSize, :pointer,
           :ppptr, :pointer
  end
  typedef ZEModuleGetGlobalPointerParams.by_value, :ze_module_get_global_pointer_params_t

  callback :ze_pfnModuleGetGlobalPointerCb_t,
           [ ZEModuleGetGlobalPointerParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEModuleGetKernelNamesParams < FFI::ZEStruct
    layout :phModule, :pointer,
           :ppCount, :pointer,
           :ppNames, :pointer
  end
  typedef ZEModuleGetKernelNamesParams.by_value, :ze_module_get_kernel_names_params_t

  callback :ze_pfnModuleGetKernelNamesCb_t,
           [ ZEModuleGetKernelNamesParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEModuleGetPropertiesParams < FFI::ZEStruct
    layout :phModule, :pointer,
           :ppModuleProperties, :pointer
  end
  typedef ZEModuleGetPropertiesParams.by_value, :ze_module_get_properties_params_t

  callback :ze_pfnModuleGetPropertiesCb_t,
           [ ZEModuleGetPropertiesParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEModuleGetFunctionPointerParams < FFI::ZEStruct
    layout :phModule, :pointer,
           :ppFunctionName, :pointer,
           :ppfnFunction, :pointer
  end
  typedef ZEModuleGetFunctionPointerParams.by_value, :ze_module_get_function_pointer_params_t

  callback :ze_pfnModuleGetFunctionPointerCb_t,
           [ ZEModuleGetFunctionPointerParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEModuleCallbacks < FFI::ZEStruct
    layout :pfnCreateCb, :ze_pfnModuleCreateCb_t,
           :pfnDestroyCb, :ze_pfnModuleDestroyCb_t,
           :pfnDynamicLinkCb, :ze_pfnModuleDynamicLinkCb_t,
           :pfnGetNativeBinaryCb, :ze_pfnModuleGetNativeBinaryCb_t,
           :pfnGetGlobalPointerCb, :ze_pfnModuleGetGlobalPointerCb_t,
           :pfnGetKernelNamesCb, :ze_pfnModuleGetKernelNamesCb_t,
           :pfnGetPropertiesCb, :ze_pfnModuleGetPropertiesCb_t,
           :pfnGetFunctionPointerCb, :ze_pfnModuleGetFunctionPointerCb_t
  end
  typedef ZEModuleCallbacks.by_value, :ze_module_callbacks_t

  class ZEModuleBuildLogDestroyParams < FFI::ZEStruct
    layout :phModuleBuildLog, :pointer
  end
  typedef ZEModuleBuildLogDestroyParams.by_value, :ze_module_build_log_destroy_params_t

  callback :ze_pfnModuleBuildLogDestroyCb_t,
           [ ZEModuleBuildLogDestroyParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEModuleBuildLogGetStringParams < FFI::ZEStruct
    layout :phModuleBuildLog, :pointer,
           :ppSize, :pointer,
           :ppBuildLog, :pointer
  end
  typedef ZEModuleBuildLogGetStringParams.by_value, :ze_module_build_log_get_string_params_t

  callback :ze_pfnModuleBuildLogGetStringCb_t,
           [ ZEModuleBuildLogGetStringParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEModuleBuildLogCallbacks < FFI::ZEStruct
    layout :pfnDestroyCb, :ze_pfnModuleBuildLogDestroyCb_t,
           :pfnGetStringCb, :ze_pfnModuleBuildLogGetStringCb_t
  end
  typedef ZEModuleBuildLogCallbacks.by_value, :ze_module_build_log_callbacks_t

  class ZEKernelCreateParams < FFI::ZEStruct
    layout :phModule, :pointer,
           :pdesc, :pointer,
           :pphKernel, :pointer
  end
  typedef ZEKernelCreateParams.by_value, :ze_kernel_create_params_t

  callback :ze_pfnKernelCreateCb_t,
           [ ZEKernelCreateParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEKernelDestroyParams < FFI::ZEStruct
    layout :phKernel, :pointer
  end
  typedef ZEKernelDestroyParams.by_value, :ze_kernel_destroy_params_t

  callback :ze_pfnKernelDestroyCb_t,
           [ ZEKernelDestroyParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEKernelSetCacheConfigParams < FFI::ZEStruct
    layout :phKernel, :pointer,
           :pflags, :pointer
  end
  typedef ZEKernelSetCacheConfigParams.by_value, :ze_kernel_set_cache_config_params_t

  callback :ze_pfnKernelSetCacheConfigCb_t,
           [ ZEKernelSetCacheConfigParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEKernelSetGroupSizeParams < FFI::ZEStruct
    layout :phKernel, :pointer,
           :pgroupSizeX, :pointer,
           :pgroupSizeY, :pointer,
           :pgroupSizeZ, :pointer
  end
  typedef ZEKernelSetGroupSizeParams.by_value, :ze_kernel_set_group_size_params_t

  callback :ze_pfnKernelSetGroupSizeCb_t,
           [ ZEKernelSetGroupSizeParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEKernelSuggestGroupSizeParams < FFI::ZEStruct
    layout :phKernel, :pointer,
           :pglobalSizeX, :pointer,
           :pglobalSizeY, :pointer,
           :pglobalSizeZ, :pointer,
           :pgroupSizeX, :pointer,
           :pgroupSizeY, :pointer,
           :pgroupSizeZ, :pointer
  end
  typedef ZEKernelSuggestGroupSizeParams.by_value, :ze_kernel_suggest_group_size_params_t

  callback :ze_pfnKernelSuggestGroupSizeCb_t,
           [ ZEKernelSuggestGroupSizeParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEKernelSuggestMaxCooperativeGroupCountParams < FFI::ZEStruct
    layout :phKernel, :pointer,
           :ptotalGroupCount, :pointer
  end
  typedef ZEKernelSuggestMaxCooperativeGroupCountParams.by_value, :ze_kernel_suggest_max_cooperative_group_count_params_t

  callback :ze_pfnKernelSuggestMaxCooperativeGroupCountCb_t,
           [ ZEKernelSuggestMaxCooperativeGroupCountParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEKernelSetArgumentValueParams < FFI::ZEStruct
    layout :phKernel, :pointer,
           :pargIndex, :pointer,
           :pargSize, :pointer,
           :ppArgValue, :pointer
  end
  typedef ZEKernelSetArgumentValueParams.by_value, :ze_kernel_set_argument_value_params_t

  callback :ze_pfnKernelSetArgumentValueCb_t,
           [ ZEKernelSetArgumentValueParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEKernelSetIndirectAccessParams < FFI::ZEStruct
    layout :phKernel, :pointer,
           :pflags, :pointer
  end
  typedef ZEKernelSetIndirectAccessParams.by_value, :ze_kernel_set_indirect_access_params_t

  callback :ze_pfnKernelSetIndirectAccessCb_t,
           [ ZEKernelSetIndirectAccessParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEKernelGetIndirectAccessParams < FFI::ZEStruct
    layout :phKernel, :pointer,
           :ppFlags, :pointer
  end
  typedef ZEKernelGetIndirectAccessParams.by_value, :ze_kernel_get_indirect_access_params_t

  callback :ze_pfnKernelGetIndirectAccessCb_t,
           [ ZEKernelGetIndirectAccessParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEKernelGetSourceAttributesParams < FFI::ZEStruct
    layout :phKernel, :pointer,
           :ppSize, :pointer,
           :ppString, :pointer
  end
  typedef ZEKernelGetSourceAttributesParams.by_value, :ze_kernel_get_source_attributes_params_t

  callback :ze_pfnKernelGetSourceAttributesCb_t,
           [ ZEKernelGetSourceAttributesParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEKernelGetPropertiesParams < FFI::ZEStruct
    layout :phKernel, :pointer,
           :ppKernelProperties, :pointer
  end
  typedef ZEKernelGetPropertiesParams.by_value, :ze_kernel_get_properties_params_t

  callback :ze_pfnKernelGetPropertiesCb_t,
           [ ZEKernelGetPropertiesParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEKernelGetNameParams < FFI::ZEStruct
    layout :phKernel, :pointer,
           :ppSize, :pointer,
           :ppName, :pointer
  end
  typedef ZEKernelGetNameParams.by_value, :ze_kernel_get_name_params_t

  callback :ze_pfnKernelGetNameCb_t,
           [ ZEKernelGetNameParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEKernelCallbacks < FFI::ZEStruct
    layout :pfnCreateCb, :ze_pfnKernelCreateCb_t,
           :pfnDestroyCb, :ze_pfnKernelDestroyCb_t,
           :pfnSetCacheConfigCb, :ze_pfnKernelSetCacheConfigCb_t,
           :pfnSetGroupSizeCb, :ze_pfnKernelSetGroupSizeCb_t,
           :pfnSuggestGroupSizeCb, :ze_pfnKernelSuggestGroupSizeCb_t,
           :pfnSuggestMaxCooperativeGroupCountCb, :ze_pfnKernelSuggestMaxCooperativeGroupCountCb_t,
           :pfnSetArgumentValueCb, :ze_pfnKernelSetArgumentValueCb_t,
           :pfnSetIndirectAccessCb, :ze_pfnKernelSetIndirectAccessCb_t,
           :pfnGetIndirectAccessCb, :ze_pfnKernelGetIndirectAccessCb_t,
           :pfnGetSourceAttributesCb, :ze_pfnKernelGetSourceAttributesCb_t,
           :pfnGetPropertiesCb, :ze_pfnKernelGetPropertiesCb_t,
           :pfnGetNameCb, :ze_pfnKernelGetNameCb_t
  end
  typedef ZEKernelCallbacks.by_value, :ze_kernel_callbacks_t

  class ZESamplerCreateParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :phDevice, :pointer,
           :pdesc, :pointer,
           :pphSampler, :pointer
  end
  typedef ZESamplerCreateParams.by_value, :ze_sampler_create_params_t

  callback :ze_pfnSamplerCreateCb_t,
           [ ZESamplerCreateParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZESamplerDestroyParams < FFI::ZEStruct
    layout :phSampler, :pointer
  end
  typedef ZESamplerDestroyParams.by_value, :ze_sampler_destroy_params_t

  callback :ze_pfnSamplerDestroyCb_t,
           [ ZESamplerDestroyParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZESamplerCallbacks < FFI::ZEStruct
    layout :pfnCreateCb, :ze_pfnSamplerCreateCb_t,
           :pfnDestroyCb, :ze_pfnSamplerDestroyCb_t
  end
  typedef ZESamplerCallbacks.by_value, :ze_sampler_callbacks_t

  class ZEPhysicalMemCreateParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :phDevice, :pointer,
           :pdesc, :pointer,
           :pphPhysicalMemory, :pointer
  end
  typedef ZEPhysicalMemCreateParams.by_value, :ze_physical_mem_create_params_t

  callback :ze_pfnPhysicalMemCreateCb_t,
           [ ZEPhysicalMemCreateParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEPhysicalMemDestroyParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :phPhysicalMemory, :pointer
  end
  typedef ZEPhysicalMemDestroyParams.by_value, :ze_physical_mem_destroy_params_t

  callback :ze_pfnPhysicalMemDestroyCb_t,
           [ ZEPhysicalMemDestroyParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEPhysicalMemCallbacks < FFI::ZEStruct
    layout :pfnCreateCb, :ze_pfnPhysicalMemCreateCb_t,
           :pfnDestroyCb, :ze_pfnPhysicalMemDestroyCb_t
  end
  typedef ZEPhysicalMemCallbacks.by_value, :ze_physical_mem_callbacks_t

  class ZEVirtualMemReserveParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :ppStart, :pointer,
           :psize, :pointer,
           :ppptr, :pointer
  end
  typedef ZEVirtualMemReserveParams.by_value, :ze_virtual_mem_reserve_params_t

  callback :ze_pfnVirtualMemReserveCb_t,
           [ ZEVirtualMemReserveParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEVirtualMemFreeParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :pptr, :pointer,
           :psize, :pointer
  end
  typedef ZEVirtualMemFreeParams.by_value, :ze_virtual_mem_free_params_t

  callback :ze_pfnVirtualMemFreeCb_t,
           [ ZEVirtualMemFreeParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEVirtualMemQueryPageSizeParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :phDevice, :pointer,
           :psize, :pointer,
           :ppagesize, :pointer
  end
  typedef ZEVirtualMemQueryPageSizeParams.by_value, :ze_virtual_mem_query_page_size_params_t

  callback :ze_pfnVirtualMemQueryPageSizeCb_t,
           [ ZEVirtualMemQueryPageSizeParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEVirtualMemMapParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :pptr, :pointer,
           :psize, :pointer,
           :phPhysicalMemory, :pointer,
           :poffset, :pointer,
           :paccess, :pointer
  end
  typedef ZEVirtualMemMapParams.by_value, :ze_virtual_mem_map_params_t

  callback :ze_pfnVirtualMemMapCb_t,
           [ ZEVirtualMemMapParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEVirtualMemUnmapParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :pptr, :pointer,
           :psize, :pointer
  end
  typedef ZEVirtualMemUnmapParams.by_value, :ze_virtual_mem_unmap_params_t

  callback :ze_pfnVirtualMemUnmapCb_t,
           [ ZEVirtualMemUnmapParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEVirtualMemSetAccessAttributeParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :pptr, :pointer,
           :psize, :pointer,
           :paccess, :pointer
  end
  typedef ZEVirtualMemSetAccessAttributeParams.by_value, :ze_virtual_mem_set_access_attribute_params_t

  callback :ze_pfnVirtualMemSetAccessAttributeCb_t,
           [ ZEVirtualMemSetAccessAttributeParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEVirtualMemGetAccessAttributeParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :pptr, :pointer,
           :psize, :pointer,
           :paccess, :pointer,
           :poutSize, :pointer
  end
  typedef ZEVirtualMemGetAccessAttributeParams.by_value, :ze_virtual_mem_get_access_attribute_params_t

  callback :ze_pfnVirtualMemGetAccessAttributeCb_t,
           [ ZEVirtualMemGetAccessAttributeParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEVirtualMemCallbacks < FFI::ZEStruct
    layout :pfnReserveCb, :ze_pfnVirtualMemReserveCb_t,
           :pfnFreeCb, :ze_pfnVirtualMemFreeCb_t,
           :pfnQueryPageSizeCb, :ze_pfnVirtualMemQueryPageSizeCb_t,
           :pfnMapCb, :ze_pfnVirtualMemMapCb_t,
           :pfnUnmapCb, :ze_pfnVirtualMemUnmapCb_t,
           :pfnSetAccessAttributeCb, :ze_pfnVirtualMemSetAccessAttributeCb_t,
           :pfnGetAccessAttributeCb, :ze_pfnVirtualMemGetAccessAttributeCb_t
  end
  typedef ZEVirtualMemCallbacks.by_value, :ze_virtual_mem_callbacks_t

  class ZECallbacks < FFI::ZEStruct
    layout :Global, :ze_global_callbacks_t,
           :Driver, :ze_driver_callbacks_t,
           :Device, :ze_device_callbacks_t,
           :Context, :ze_context_callbacks_t,
           :CommandQueue, :ze_command_queue_callbacks_t,
           :CommandList, :ze_command_list_callbacks_t,
           :Fence, :ze_fence_callbacks_t,
           :EventPool, :ze_event_pool_callbacks_t,
           :Event, :ze_event_callbacks_t,
           :Image, :ze_image_callbacks_t,
           :Module, :ze_module_callbacks_t,
           :ModuleBuildLog, :ze_module_build_log_callbacks_t,
           :Kernel, :ze_kernel_callbacks_t,
           :Sampler, :ze_sampler_callbacks_t,
           :PhysicalMem, :ze_physical_mem_callbacks_t,
           :Mem, :ze_mem_callbacks_t,
           :VirtualMem, :ze_virtual_mem_callbacks_t
  end
  typedef ZECallbacks.by_value, :ze_callbacks_t

  callback :ze_pfnRTASBuilderCreateExt_t,
           [ :ze_driver_handle_t,
             ZERtasBuilderExtDesc.ptr,
             :pointer ],
           :ze_result_t

  callback :ze_pfnRTASBuilderGetBuildPropertiesExt_t,
           [ :ze_rtas_builder_ext_handle_t,
             ZERtasBuilderBuildOpExtDesc.ptr,
             ZERtasBuilderExtProperties.ptr ],
           :ze_result_t

  callback :ze_pfnRTASBuilderBuildExt_t,
           [ :ze_rtas_builder_ext_handle_t,
             ZERtasBuilderBuildOpExtDesc.ptr,
             :pointer,
             :size_t,
             :pointer,
             :size_t,
             :ze_rtas_parallel_operation_ext_handle_t,
             :pointer,
             ZERtasAabbExt.ptr,
             :pointer ],
           :ze_result_t

  callback :ze_pfnRTASBuilderCommandListAppendCopyExt_t,
           [ :ze_command_list_handle_t,
             :pointer,
             :pointer,
             :size_t,
             :ze_event_handle_t,
             :uint32,
             :pointer ],
           :ze_result_t

  callback :ze_pfnRTASBuilderDestroyExt_t,
           [ :ze_rtas_builder_ext_handle_t ],
           :ze_result_t

  class ZERtasBuilderDDITable < FFI::ZEStruct
    layout :pfnCreateExt, :ze_pfnRTASBuilderCreateExt_t,
           :pfnGetBuildPropertiesExt, :ze_pfnRTASBuilderGetBuildPropertiesExt_t,
           :pfnBuildExt, :ze_pfnRTASBuilderBuildExt_t,
           :pfnCommandListAppendCopyExt, :ze_pfnRTASBuilderCommandListAppendCopyExt_t,
           :pfnDestroyExt, :ze_pfnRTASBuilderDestroyExt_t
  end
  typedef ZERtasBuilderDDITable.by_value, :ze_rtas_builder_dditable_t

  callback :ze_pfnGetRTASBuilderProcAddrTable_t,
           [ :ze_api_version_t,
             ZERtasBuilderDDITable.ptr ],
           :ze_result_t

  callback :ze_pfnRTASBuilderCreateExp_t,
           [ :ze_driver_handle_t,
             ZERtasBuilderExpDesc.ptr,
             :pointer ],
           :ze_result_t

  callback :ze_pfnRTASBuilderGetBuildPropertiesExp_t,
           [ :ze_rtas_builder_exp_handle_t,
             ZERtasBuilderBuildOpExpDesc.ptr,
             ZERtasBuilderExpProperties.ptr ],
           :ze_result_t

  callback :ze_pfnRTASBuilderBuildExp_t,
           [ :ze_rtas_builder_exp_handle_t,
             ZERtasBuilderBuildOpExpDesc.ptr,
             :pointer,
             :size_t,
             :pointer,
             :size_t,
             :ze_rtas_parallel_operation_exp_handle_t,
             :pointer,
             ZERtasAabbExp.ptr,
             :pointer ],
           :ze_result_t

  callback :ze_pfnRTASBuilderDestroyExp_t,
           [ :ze_rtas_builder_exp_handle_t ],
           :ze_result_t

  class ZERtasBuilderExpDDITable < FFI::ZEStruct
    layout :pfnCreateExp, :ze_pfnRTASBuilderCreateExp_t,
           :pfnGetBuildPropertiesExp, :ze_pfnRTASBuilderGetBuildPropertiesExp_t,
           :pfnBuildExp, :ze_pfnRTASBuilderBuildExp_t,
           :pfnDestroyExp, :ze_pfnRTASBuilderDestroyExp_t
  end
  typedef ZERtasBuilderExpDDITable.by_value, :ze_rtas_builder_exp_dditable_t

  callback :ze_pfnGetRTASBuilderExpProcAddrTable_t,
           [ :ze_api_version_t,
             ZERtasBuilderExpDDITable.ptr ],
           :ze_result_t

  callback :ze_pfnRTASParallelOperationCreateExt_t,
           [ :ze_driver_handle_t,
             :pointer ],
           :ze_result_t

  callback :ze_pfnRTASParallelOperationGetPropertiesExt_t,
           [ :ze_rtas_parallel_operation_ext_handle_t,
             ZERtasParallelOperationExtProperties.ptr ],
           :ze_result_t

  callback :ze_pfnRTASParallelOperationJoinExt_t,
           [ :ze_rtas_parallel_operation_ext_handle_t ],
           :ze_result_t

  callback :ze_pfnRTASParallelOperationDestroyExt_t,
           [ :ze_rtas_parallel_operation_ext_handle_t ],
           :ze_result_t

  class ZERtasParallelOperationDDITable < FFI::ZEStruct
    layout :pfnCreateExt, :ze_pfnRTASParallelOperationCreateExt_t,
           :pfnGetPropertiesExt, :ze_pfnRTASParallelOperationGetPropertiesExt_t,
           :pfnJoinExt, :ze_pfnRTASParallelOperationJoinExt_t,
           :pfnDestroyExt, :ze_pfnRTASParallelOperationDestroyExt_t
  end
  typedef ZERtasParallelOperationDDITable.by_value, :ze_rtas_parallel_operation_dditable_t

  callback :ze_pfnGetRTASParallelOperationProcAddrTable_t,
           [ :ze_api_version_t,
             ZERtasParallelOperationDDITable.ptr ],
           :ze_result_t

  callback :ze_pfnRTASParallelOperationCreateExp_t,
           [ :ze_driver_handle_t,
             :pointer ],
           :ze_result_t

  callback :ze_pfnRTASParallelOperationGetPropertiesExp_t,
           [ :ze_rtas_parallel_operation_exp_handle_t,
             ZERtasParallelOperationExpProperties.ptr ],
           :ze_result_t

  callback :ze_pfnRTASParallelOperationJoinExp_t,
           [ :ze_rtas_parallel_operation_exp_handle_t ],
           :ze_result_t

  callback :ze_pfnRTASParallelOperationDestroyExp_t,
           [ :ze_rtas_parallel_operation_exp_handle_t ],
           :ze_result_t

  class ZERtasParallelOperationExpDDITable < FFI::ZEStruct
    layout :pfnCreateExp, :ze_pfnRTASParallelOperationCreateExp_t,
           :pfnGetPropertiesExp, :ze_pfnRTASParallelOperationGetPropertiesExp_t,
           :pfnJoinExp, :ze_pfnRTASParallelOperationJoinExp_t,
           :pfnDestroyExp, :ze_pfnRTASParallelOperationDestroyExp_t
  end
  typedef ZERtasParallelOperationExpDDITable.by_value, :ze_rtas_parallel_operation_exp_dditable_t

  callback :ze_pfnGetRTASParallelOperationExpProcAddrTable_t,
           [ :ze_api_version_t,
             ZERtasParallelOperationExpDDITable.ptr ],
           :ze_result_t

  callback :ze_pfnInit_t,
           [ :ze_init_flags_t ],
           :ze_result_t

  callback :ze_pfnInitDrivers_t,
           [ :pointer,
             :pointer,
             ZEInitDriverTypeDesc.ptr ],
           :ze_result_t

  class ZEGlobalDDITable < FFI::ZEStruct
    layout :pfnInit, :ze_pfnInit_t,
           :pfnInitDrivers, :ze_pfnInitDrivers_t
  end
  typedef ZEGlobalDDITable.by_value, :ze_global_dditable_t

  callback :ze_pfnGetGlobalProcAddrTable_t,
           [ :ze_api_version_t,
             ZEGlobalDDITable.ptr ],
           :ze_result_t

  callback :ze_pfnDriverGet_t,
           [ :pointer,
             :pointer ],
           :ze_result_t

  callback :ze_pfnDriverGetApiVersion_t,
           [ :ze_driver_handle_t,
             :pointer ],
           :ze_result_t

  callback :ze_pfnDriverGetProperties_t,
           [ :ze_driver_handle_t,
             ZEDriverProperties.ptr ],
           :ze_result_t

  callback :ze_pfnDriverGetIpcProperties_t,
           [ :ze_driver_handle_t,
             ZEDriverIpcProperties.ptr ],
           :ze_result_t

  callback :ze_pfnDriverGetExtensionProperties_t,
           [ :ze_driver_handle_t,
             :pointer,
             ZEDriverExtensionProperties.ptr ],
           :ze_result_t

  callback :ze_pfnDriverGetExtensionFunctionAddress_t,
           [ :ze_driver_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :ze_pfnDriverGetLastErrorDescription_t,
           [ :ze_driver_handle_t,
             :pointer ],
           :ze_result_t

  callback :ze_pfnDriverRTASFormatCompatibilityCheckExt_t,
           [ :ze_driver_handle_t,
             :ze_rtas_format_ext_t,
             :ze_rtas_format_ext_t ],
           :ze_result_t

  class ZEDriverDDITable < FFI::ZEStruct
    layout :pfnGet, :ze_pfnDriverGet_t,
           :pfnGetApiVersion, :ze_pfnDriverGetApiVersion_t,
           :pfnGetProperties, :ze_pfnDriverGetProperties_t,
           :pfnGetIpcProperties, :ze_pfnDriverGetIpcProperties_t,
           :pfnGetExtensionProperties, :ze_pfnDriverGetExtensionProperties_t,
           :pfnGetExtensionFunctionAddress, :ze_pfnDriverGetExtensionFunctionAddress_t,
           :pfnGetLastErrorDescription, :ze_pfnDriverGetLastErrorDescription_t,
           :pfnRTASFormatCompatibilityCheckExt, :ze_pfnDriverRTASFormatCompatibilityCheckExt_t
  end
  typedef ZEDriverDDITable.by_value, :ze_driver_dditable_t

  callback :ze_pfnGetDriverProcAddrTable_t,
           [ :ze_api_version_t,
             ZEDriverDDITable.ptr ],
           :ze_result_t

  callback :ze_pfnDriverRTASFormatCompatibilityCheckExp_t,
           [ :ze_driver_handle_t,
             :ze_rtas_format_exp_t,
             :ze_rtas_format_exp_t ],
           :ze_result_t

  class ZEDriverExpDDITable < FFI::ZEStruct
    layout :pfnRTASFormatCompatibilityCheckExp, :ze_pfnDriverRTASFormatCompatibilityCheckExp_t
  end
  typedef ZEDriverExpDDITable.by_value, :ze_driver_exp_dditable_t

  callback :ze_pfnGetDriverExpProcAddrTable_t,
           [ :ze_api_version_t,
             ZEDriverExpDDITable.ptr ],
           :ze_result_t

  callback :ze_pfnDeviceGet_t,
           [ :ze_driver_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :ze_pfnDeviceGetSubDevices_t,
           [ :ze_device_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :ze_pfnDeviceGetProperties_t,
           [ :ze_device_handle_t,
             ZEDeviceProperties.ptr ],
           :ze_result_t

  callback :ze_pfnDeviceGetComputeProperties_t,
           [ :ze_device_handle_t,
             ZEDeviceComputeProperties.ptr ],
           :ze_result_t

  callback :ze_pfnDeviceGetModuleProperties_t,
           [ :ze_device_handle_t,
             ZEDeviceModuleProperties.ptr ],
           :ze_result_t

  callback :ze_pfnDeviceGetCommandQueueGroupProperties_t,
           [ :ze_device_handle_t,
             :pointer,
             ZECommandQueueGroupProperties.ptr ],
           :ze_result_t

  callback :ze_pfnDeviceGetMemoryProperties_t,
           [ :ze_device_handle_t,
             :pointer,
             ZEDeviceMemoryProperties.ptr ],
           :ze_result_t

  callback :ze_pfnDeviceGetMemoryAccessProperties_t,
           [ :ze_device_handle_t,
             ZEDeviceMemoryAccessProperties.ptr ],
           :ze_result_t

  callback :ze_pfnDeviceGetCacheProperties_t,
           [ :ze_device_handle_t,
             :pointer,
             ZEDeviceCacheProperties.ptr ],
           :ze_result_t

  callback :ze_pfnDeviceGetImageProperties_t,
           [ :ze_device_handle_t,
             ZEDeviceImageProperties.ptr ],
           :ze_result_t

  callback :ze_pfnDeviceGetExternalMemoryProperties_t,
           [ :ze_device_handle_t,
             ZEDeviceExternalMemoryProperties.ptr ],
           :ze_result_t

  callback :ze_pfnDeviceGetP2PProperties_t,
           [ :ze_device_handle_t,
             :ze_device_handle_t,
             ZEDeviceP2PProperties.ptr ],
           :ze_result_t

  callback :ze_pfnDeviceCanAccessPeer_t,
           [ :ze_device_handle_t,
             :ze_device_handle_t,
             :pointer ],
           :ze_result_t

  callback :ze_pfnDeviceGetStatus_t,
           [ :ze_device_handle_t ],
           :ze_result_t

  callback :ze_pfnDeviceGetGlobalTimestamps_t,
           [ :ze_device_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :ze_pfnDeviceReserveCacheExt_t,
           [ :ze_device_handle_t,
             :size_t,
             :size_t ],
           :ze_result_t

  callback :ze_pfnDeviceSetCacheAdviceExt_t,
           [ :ze_device_handle_t,
             :pointer,
             :size_t,
             :ze_cache_ext_region_t ],
           :ze_result_t

  callback :ze_pfnDevicePciGetPropertiesExt_t,
           [ :ze_device_handle_t,
             ZEPciExtProperties.ptr ],
           :ze_result_t

  callback :ze_pfnDeviceGetRootDevice_t,
           [ :ze_device_handle_t,
             :pointer ],
           :ze_result_t

  callback :ze_pfnDeviceImportExternalSemaphoreExt_t,
           [ :ze_device_handle_t,
             ZEExternalSemaphoreExtDesc.ptr,
             :pointer ],
           :ze_result_t

  callback :ze_pfnDeviceReleaseExternalSemaphoreExt_t,
           [ :ze_external_semaphore_ext_handle_t ],
           :ze_result_t

  callback :ze_pfnDeviceGetVectorWidthPropertiesExt_t,
           [ :ze_device_handle_t,
             :pointer,
             ZEDeviceVectorWidthPropertiesExt.ptr ],
           :ze_result_t

  class ZEDeviceDDITable < FFI::ZEStruct
    layout :pfnGet, :ze_pfnDeviceGet_t,
           :pfnGetSubDevices, :ze_pfnDeviceGetSubDevices_t,
           :pfnGetProperties, :ze_pfnDeviceGetProperties_t,
           :pfnGetComputeProperties, :ze_pfnDeviceGetComputeProperties_t,
           :pfnGetModuleProperties, :ze_pfnDeviceGetModuleProperties_t,
           :pfnGetCommandQueueGroupProperties, :ze_pfnDeviceGetCommandQueueGroupProperties_t,
           :pfnGetMemoryProperties, :ze_pfnDeviceGetMemoryProperties_t,
           :pfnGetMemoryAccessProperties, :ze_pfnDeviceGetMemoryAccessProperties_t,
           :pfnGetCacheProperties, :ze_pfnDeviceGetCacheProperties_t,
           :pfnGetImageProperties, :ze_pfnDeviceGetImageProperties_t,
           :pfnGetExternalMemoryProperties, :ze_pfnDeviceGetExternalMemoryProperties_t,
           :pfnGetP2PProperties, :ze_pfnDeviceGetP2PProperties_t,
           :pfnCanAccessPeer, :ze_pfnDeviceCanAccessPeer_t,
           :pfnGetStatus, :ze_pfnDeviceGetStatus_t,
           :pfnGetGlobalTimestamps, :ze_pfnDeviceGetGlobalTimestamps_t,
           :pfnReserveCacheExt, :ze_pfnDeviceReserveCacheExt_t,
           :pfnSetCacheAdviceExt, :ze_pfnDeviceSetCacheAdviceExt_t,
           :pfnPciGetPropertiesExt, :ze_pfnDevicePciGetPropertiesExt_t,
           :pfnGetRootDevice, :ze_pfnDeviceGetRootDevice_t,
           :pfnImportExternalSemaphoreExt, :ze_pfnDeviceImportExternalSemaphoreExt_t,
           :pfnReleaseExternalSemaphoreExt, :ze_pfnDeviceReleaseExternalSemaphoreExt_t,
           :pfnGetVectorWidthPropertiesExt, :ze_pfnDeviceGetVectorWidthPropertiesExt_t
  end
  typedef ZEDeviceDDITable.by_value, :ze_device_dditable_t

  callback :ze_pfnGetDeviceProcAddrTable_t,
           [ :ze_api_version_t,
             ZEDeviceDDITable.ptr ],
           :ze_result_t

  callback :ze_pfnDeviceGetFabricVertexExp_t,
           [ :ze_device_handle_t,
             :pointer ],
           :ze_result_t

  class ZEDeviceExpDDITable < FFI::ZEStruct
    layout :pfnGetFabricVertexExp, :ze_pfnDeviceGetFabricVertexExp_t
  end
  typedef ZEDeviceExpDDITable.by_value, :ze_device_exp_dditable_t

  callback :ze_pfnGetDeviceExpProcAddrTable_t,
           [ :ze_api_version_t,
             ZEDeviceExpDDITable.ptr ],
           :ze_result_t

  callback :ze_pfnContextCreate_t,
           [ :ze_driver_handle_t,
             ZEContextDesc.ptr,
             :pointer ],
           :ze_result_t

  callback :ze_pfnContextDestroy_t,
           [ :ze_context_handle_t ],
           :ze_result_t

  callback :ze_pfnContextGetStatus_t,
           [ :ze_context_handle_t ],
           :ze_result_t

  callback :ze_pfnContextSystemBarrier_t,
           [ :ze_context_handle_t,
             :ze_device_handle_t ],
           :ze_result_t

  callback :ze_pfnContextMakeMemoryResident_t,
           [ :ze_context_handle_t,
             :ze_device_handle_t,
             :pointer,
             :size_t ],
           :ze_result_t

  callback :ze_pfnContextEvictMemory_t,
           [ :ze_context_handle_t,
             :ze_device_handle_t,
             :pointer,
             :size_t ],
           :ze_result_t

  callback :ze_pfnContextMakeImageResident_t,
           [ :ze_context_handle_t,
             :ze_device_handle_t,
             :ze_image_handle_t ],
           :ze_result_t

  callback :ze_pfnContextEvictImage_t,
           [ :ze_context_handle_t,
             :ze_device_handle_t,
             :ze_image_handle_t ],
           :ze_result_t

  callback :ze_pfnContextCreateEx_t,
           [ :ze_driver_handle_t,
             ZEContextDesc.ptr,
             :uint32,
             :pointer,
             :pointer ],
           :ze_result_t

  class ZEContextDDITable < FFI::ZEStruct
    layout :pfnCreate, :ze_pfnContextCreate_t,
           :pfnDestroy, :ze_pfnContextDestroy_t,
           :pfnGetStatus, :ze_pfnContextGetStatus_t,
           :pfnSystemBarrier, :ze_pfnContextSystemBarrier_t,
           :pfnMakeMemoryResident, :ze_pfnContextMakeMemoryResident_t,
           :pfnEvictMemory, :ze_pfnContextEvictMemory_t,
           :pfnMakeImageResident, :ze_pfnContextMakeImageResident_t,
           :pfnEvictImage, :ze_pfnContextEvictImage_t,
           :pfnCreateEx, :ze_pfnContextCreateEx_t
  end
  typedef ZEContextDDITable.by_value, :ze_context_dditable_t

  callback :ze_pfnGetContextProcAddrTable_t,
           [ :ze_api_version_t,
             ZEContextDDITable.ptr ],
           :ze_result_t

  callback :ze_pfnCommandQueueCreate_t,
           [ :ze_context_handle_t,
             :ze_device_handle_t,
             ZECommandQueueDesc.ptr,
             :pointer ],
           :ze_result_t

  callback :ze_pfnCommandQueueDestroy_t,
           [ :ze_command_queue_handle_t ],
           :ze_result_t

  callback :ze_pfnCommandQueueExecuteCommandLists_t,
           [ :ze_command_queue_handle_t,
             :uint32,
             :pointer,
             :ze_fence_handle_t ],
           :ze_result_t

  callback :ze_pfnCommandQueueSynchronize_t,
           [ :ze_command_queue_handle_t,
             :uint64 ],
           :ze_result_t

  callback :ze_pfnCommandQueueGetOrdinal_t,
           [ :ze_command_queue_handle_t,
             :pointer ],
           :ze_result_t

  callback :ze_pfnCommandQueueGetIndex_t,
           [ :ze_command_queue_handle_t,
             :pointer ],
           :ze_result_t

  class ZECommandQueueDDITable < FFI::ZEStruct
    layout :pfnCreate, :ze_pfnCommandQueueCreate_t,
           :pfnDestroy, :ze_pfnCommandQueueDestroy_t,
           :pfnExecuteCommandLists, :ze_pfnCommandQueueExecuteCommandLists_t,
           :pfnSynchronize, :ze_pfnCommandQueueSynchronize_t,
           :pfnGetOrdinal, :ze_pfnCommandQueueGetOrdinal_t,
           :pfnGetIndex, :ze_pfnCommandQueueGetIndex_t
  end
  typedef ZECommandQueueDDITable.by_value, :ze_command_queue_dditable_t

  callback :ze_pfnGetCommandQueueProcAddrTable_t,
           [ :ze_api_version_t,
             ZECommandQueueDDITable.ptr ],
           :ze_result_t

  callback :ze_pfnCommandListCreate_t,
           [ :ze_context_handle_t,
             :ze_device_handle_t,
             ZECommandListDesc.ptr,
             :pointer ],
           :ze_result_t

  callback :ze_pfnCommandListCreateImmediate_t,
           [ :ze_context_handle_t,
             :ze_device_handle_t,
             ZECommandQueueDesc.ptr,
             :pointer ],
           :ze_result_t

  callback :ze_pfnCommandListDestroy_t,
           [ :ze_command_list_handle_t ],
           :ze_result_t

  callback :ze_pfnCommandListClose_t,
           [ :ze_command_list_handle_t ],
           :ze_result_t

  callback :ze_pfnCommandListReset_t,
           [ :ze_command_list_handle_t ],
           :ze_result_t

  callback :ze_pfnCommandListAppendWriteGlobalTimestamp_t,
           [ :ze_command_list_handle_t,
             :pointer,
             :ze_event_handle_t,
             :uint32,
             :pointer ],
           :ze_result_t

  callback :ze_pfnCommandListAppendBarrier_t,
           [ :ze_command_list_handle_t,
             :ze_event_handle_t,
             :uint32,
             :pointer ],
           :ze_result_t

  callback :ze_pfnCommandListAppendMemoryRangesBarrier_t,
           [ :ze_command_list_handle_t,
             :uint32,
             :pointer,
             :pointer,
             :ze_event_handle_t,
             :uint32,
             :pointer ],
           :ze_result_t

  callback :ze_pfnCommandListAppendMemoryCopy_t,
           [ :ze_command_list_handle_t,
             :pointer,
             :pointer,
             :size_t,
             :ze_event_handle_t,
             :uint32,
             :pointer ],
           :ze_result_t

  callback :ze_pfnCommandListAppendMemoryFill_t,
           [ :ze_command_list_handle_t,
             :pointer,
             :pointer,
             :size_t,
             :size_t,
             :ze_event_handle_t,
             :uint32,
             :pointer ],
           :ze_result_t

  callback :ze_pfnCommandListAppendMemoryCopyRegion_t,
           [ :ze_command_list_handle_t,
             :pointer,
             ZECopyRegion.ptr,
             :uint32,
             :uint32,
             :pointer,
             ZECopyRegion.ptr,
             :uint32,
             :uint32,
             :ze_event_handle_t,
             :uint32,
             :pointer ],
           :ze_result_t

  callback :ze_pfnCommandListAppendMemoryCopyFromContext_t,
           [ :ze_command_list_handle_t,
             :pointer,
             :ze_context_handle_t,
             :pointer,
             :size_t,
             :ze_event_handle_t,
             :uint32,
             :pointer ],
           :ze_result_t

  callback :ze_pfnCommandListAppendImageCopy_t,
           [ :ze_command_list_handle_t,
             :ze_image_handle_t,
             :ze_image_handle_t,
             :ze_event_handle_t,
             :uint32,
             :pointer ],
           :ze_result_t

  callback :ze_pfnCommandListAppendImageCopyRegion_t,
           [ :ze_command_list_handle_t,
             :ze_image_handle_t,
             :ze_image_handle_t,
             ZEImageRegion.ptr,
             ZEImageRegion.ptr,
             :ze_event_handle_t,
             :uint32,
             :pointer ],
           :ze_result_t

  callback :ze_pfnCommandListAppendImageCopyToMemory_t,
           [ :ze_command_list_handle_t,
             :pointer,
             :ze_image_handle_t,
             ZEImageRegion.ptr,
             :ze_event_handle_t,
             :uint32,
             :pointer ],
           :ze_result_t

  callback :ze_pfnCommandListAppendImageCopyFromMemory_t,
           [ :ze_command_list_handle_t,
             :ze_image_handle_t,
             :pointer,
             ZEImageRegion.ptr,
             :ze_event_handle_t,
             :uint32,
             :pointer ],
           :ze_result_t

  callback :ze_pfnCommandListAppendMemoryPrefetch_t,
           [ :ze_command_list_handle_t,
             :pointer,
             :size_t ],
           :ze_result_t

  callback :ze_pfnCommandListAppendMemAdvise_t,
           [ :ze_command_list_handle_t,
             :ze_device_handle_t,
             :pointer,
             :size_t,
             :ze_memory_advice_t ],
           :ze_result_t

  callback :ze_pfnCommandListAppendSignalEvent_t,
           [ :ze_command_list_handle_t,
             :ze_event_handle_t ],
           :ze_result_t

  callback :ze_pfnCommandListAppendWaitOnEvents_t,
           [ :ze_command_list_handle_t,
             :uint32,
             :pointer ],
           :ze_result_t

  callback :ze_pfnCommandListAppendEventReset_t,
           [ :ze_command_list_handle_t,
             :ze_event_handle_t ],
           :ze_result_t

  callback :ze_pfnCommandListAppendQueryKernelTimestamps_t,
           [ :ze_command_list_handle_t,
             :uint32,
             :pointer,
             :pointer,
             :pointer,
             :ze_event_handle_t,
             :uint32,
             :pointer ],
           :ze_result_t

  callback :ze_pfnCommandListAppendLaunchKernel_t,
           [ :ze_command_list_handle_t,
             :ze_kernel_handle_t,
             ZEGroupCount.ptr,
             :ze_event_handle_t,
             :uint32,
             :pointer ],
           :ze_result_t

  callback :ze_pfnCommandListAppendLaunchCooperativeKernel_t,
           [ :ze_command_list_handle_t,
             :ze_kernel_handle_t,
             ZEGroupCount.ptr,
             :ze_event_handle_t,
             :uint32,
             :pointer ],
           :ze_result_t

  callback :ze_pfnCommandListAppendLaunchKernelIndirect_t,
           [ :ze_command_list_handle_t,
             :ze_kernel_handle_t,
             ZEGroupCount.ptr,
             :ze_event_handle_t,
             :uint32,
             :pointer ],
           :ze_result_t

  callback :ze_pfnCommandListAppendLaunchMultipleKernelsIndirect_t,
           [ :ze_command_list_handle_t,
             :uint32,
             :pointer,
             :pointer,
             ZEGroupCount.ptr,
             :ze_event_handle_t,
             :uint32,
             :pointer ],
           :ze_result_t

  callback :ze_pfnCommandListAppendImageCopyToMemoryExt_t,
           [ :ze_command_list_handle_t,
             :pointer,
             :ze_image_handle_t,
             ZEImageRegion.ptr,
             :uint32,
             :uint32,
             :ze_event_handle_t,
             :uint32,
             :pointer ],
           :ze_result_t

  callback :ze_pfnCommandListAppendImageCopyFromMemoryExt_t,
           [ :ze_command_list_handle_t,
             :ze_image_handle_t,
             :pointer,
             ZEImageRegion.ptr,
             :uint32,
             :uint32,
             :ze_event_handle_t,
             :uint32,
             :pointer ],
           :ze_result_t

  callback :ze_pfnCommandListHostSynchronize_t,
           [ :ze_command_list_handle_t,
             :uint64 ],
           :ze_result_t

  callback :ze_pfnCommandListGetDeviceHandle_t,
           [ :ze_command_list_handle_t,
             :pointer ],
           :ze_result_t

  callback :ze_pfnCommandListGetContextHandle_t,
           [ :ze_command_list_handle_t,
             :pointer ],
           :ze_result_t

  callback :ze_pfnCommandListGetOrdinal_t,
           [ :ze_command_list_handle_t,
             :pointer ],
           :ze_result_t

  callback :ze_pfnCommandListImmediateGetIndex_t,
           [ :ze_command_list_handle_t,
             :pointer ],
           :ze_result_t

  callback :ze_pfnCommandListIsImmediate_t,
           [ :ze_command_list_handle_t,
             :pointer ],
           :ze_result_t

  callback :ze_pfnCommandListAppendSignalExternalSemaphoreExt_t,
           [ :ze_command_list_handle_t,
             :uint32,
             :pointer,
             ZEExternalSemaphoreSignalParamsExt.ptr,
             :ze_event_handle_t,
             :uint32,
             :pointer ],
           :ze_result_t

  callback :ze_pfnCommandListAppendWaitExternalSemaphoreExt_t,
           [ :ze_command_list_handle_t,
             :uint32,
             :pointer,
             ZEExternalSemaphoreWaitParamsExt.ptr,
             :ze_event_handle_t,
             :uint32,
             :pointer ],
           :ze_result_t

  class ZECommandListDDITable < FFI::ZEStruct
    layout :pfnCreate, :ze_pfnCommandListCreate_t,
           :pfnCreateImmediate, :ze_pfnCommandListCreateImmediate_t,
           :pfnDestroy, :ze_pfnCommandListDestroy_t,
           :pfnClose, :ze_pfnCommandListClose_t,
           :pfnReset, :ze_pfnCommandListReset_t,
           :pfnAppendWriteGlobalTimestamp, :ze_pfnCommandListAppendWriteGlobalTimestamp_t,
           :pfnAppendBarrier, :ze_pfnCommandListAppendBarrier_t,
           :pfnAppendMemoryRangesBarrier, :ze_pfnCommandListAppendMemoryRangesBarrier_t,
           :pfnAppendMemoryCopy, :ze_pfnCommandListAppendMemoryCopy_t,
           :pfnAppendMemoryFill, :ze_pfnCommandListAppendMemoryFill_t,
           :pfnAppendMemoryCopyRegion, :ze_pfnCommandListAppendMemoryCopyRegion_t,
           :pfnAppendMemoryCopyFromContext, :ze_pfnCommandListAppendMemoryCopyFromContext_t,
           :pfnAppendImageCopy, :ze_pfnCommandListAppendImageCopy_t,
           :pfnAppendImageCopyRegion, :ze_pfnCommandListAppendImageCopyRegion_t,
           :pfnAppendImageCopyToMemory, :ze_pfnCommandListAppendImageCopyToMemory_t,
           :pfnAppendImageCopyFromMemory, :ze_pfnCommandListAppendImageCopyFromMemory_t,
           :pfnAppendMemoryPrefetch, :ze_pfnCommandListAppendMemoryPrefetch_t,
           :pfnAppendMemAdvise, :ze_pfnCommandListAppendMemAdvise_t,
           :pfnAppendSignalEvent, :ze_pfnCommandListAppendSignalEvent_t,
           :pfnAppendWaitOnEvents, :ze_pfnCommandListAppendWaitOnEvents_t,
           :pfnAppendEventReset, :ze_pfnCommandListAppendEventReset_t,
           :pfnAppendQueryKernelTimestamps, :ze_pfnCommandListAppendQueryKernelTimestamps_t,
           :pfnAppendLaunchKernel, :ze_pfnCommandListAppendLaunchKernel_t,
           :pfnAppendLaunchCooperativeKernel, :ze_pfnCommandListAppendLaunchCooperativeKernel_t,
           :pfnAppendLaunchKernelIndirect, :ze_pfnCommandListAppendLaunchKernelIndirect_t,
           :pfnAppendLaunchMultipleKernelsIndirect, :ze_pfnCommandListAppendLaunchMultipleKernelsIndirect_t,
           :pfnAppendImageCopyToMemoryExt, :ze_pfnCommandListAppendImageCopyToMemoryExt_t,
           :pfnAppendImageCopyFromMemoryExt, :ze_pfnCommandListAppendImageCopyFromMemoryExt_t,
           :pfnHostSynchronize, :ze_pfnCommandListHostSynchronize_t,
           :pfnGetDeviceHandle, :ze_pfnCommandListGetDeviceHandle_t,
           :pfnGetContextHandle, :ze_pfnCommandListGetContextHandle_t,
           :pfnGetOrdinal, :ze_pfnCommandListGetOrdinal_t,
           :pfnImmediateGetIndex, :ze_pfnCommandListImmediateGetIndex_t,
           :pfnIsImmediate, :ze_pfnCommandListIsImmediate_t,
           :pfnAppendSignalExternalSemaphoreExt, :ze_pfnCommandListAppendSignalExternalSemaphoreExt_t,
           :pfnAppendWaitExternalSemaphoreExt, :ze_pfnCommandListAppendWaitExternalSemaphoreExt_t
  end
  typedef ZECommandListDDITable.by_value, :ze_command_list_dditable_t

  callback :ze_pfnGetCommandListProcAddrTable_t,
           [ :ze_api_version_t,
             ZECommandListDDITable.ptr ],
           :ze_result_t

  callback :ze_pfnCommandListCreateCloneExp_t,
           [ :ze_command_list_handle_t,
             :pointer ],
           :ze_result_t

  callback :ze_pfnCommandListImmediateAppendCommandListsExp_t,
           [ :ze_command_list_handle_t,
             :uint32,
             :pointer,
             :ze_event_handle_t,
             :uint32,
             :pointer ],
           :ze_result_t

  callback :ze_pfnCommandListGetNextCommandIdExp_t,
           [ :ze_command_list_handle_t,
             ZEMutableCommandIdExpDesc.ptr,
             :pointer ],
           :ze_result_t

  callback :ze_pfnCommandListUpdateMutableCommandsExp_t,
           [ :ze_command_list_handle_t,
             ZEMutableCommandsExpDesc.ptr ],
           :ze_result_t

  callback :ze_pfnCommandListUpdateMutableCommandSignalEventExp_t,
           [ :ze_command_list_handle_t,
             :uint64,
             :ze_event_handle_t ],
           :ze_result_t

  callback :ze_pfnCommandListUpdateMutableCommandWaitEventsExp_t,
           [ :ze_command_list_handle_t,
             :uint64,
             :uint32,
             :pointer ],
           :ze_result_t

  callback :ze_pfnCommandListGetNextCommandIdWithKernelsExp_t,
           [ :ze_command_list_handle_t,
             ZEMutableCommandIdExpDesc.ptr,
             :uint32,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :ze_pfnCommandListUpdateMutableCommandKernelsExp_t,
           [ :ze_command_list_handle_t,
             :uint32,
             :pointer,
             :pointer ],
           :ze_result_t

  class ZECommandListExpDDITable < FFI::ZEStruct
    layout :pfnCreateCloneExp, :ze_pfnCommandListCreateCloneExp_t,
           :pfnImmediateAppendCommandListsExp, :ze_pfnCommandListImmediateAppendCommandListsExp_t,
           :pfnGetNextCommandIdExp, :ze_pfnCommandListGetNextCommandIdExp_t,
           :pfnUpdateMutableCommandsExp, :ze_pfnCommandListUpdateMutableCommandsExp_t,
           :pfnUpdateMutableCommandSignalEventExp, :ze_pfnCommandListUpdateMutableCommandSignalEventExp_t,
           :pfnUpdateMutableCommandWaitEventsExp, :ze_pfnCommandListUpdateMutableCommandWaitEventsExp_t,
           :pfnGetNextCommandIdWithKernelsExp, :ze_pfnCommandListGetNextCommandIdWithKernelsExp_t,
           :pfnUpdateMutableCommandKernelsExp, :ze_pfnCommandListUpdateMutableCommandKernelsExp_t
  end
  typedef ZECommandListExpDDITable.by_value, :ze_command_list_exp_dditable_t

  callback :ze_pfnGetCommandListExpProcAddrTable_t,
           [ :ze_api_version_t,
             ZECommandListExpDDITable.ptr ],
           :ze_result_t

  callback :ze_pfnImageGetProperties_t,
           [ :ze_device_handle_t,
             ZEImageDesc.ptr,
             ZEImageProperties.ptr ],
           :ze_result_t

  callback :ze_pfnImageCreate_t,
           [ :ze_context_handle_t,
             :ze_device_handle_t,
             ZEImageDesc.ptr,
             :pointer ],
           :ze_result_t

  callback :ze_pfnImageDestroy_t,
           [ :ze_image_handle_t ],
           :ze_result_t

  callback :ze_pfnImageGetAllocPropertiesExt_t,
           [ :ze_context_handle_t,
             :ze_image_handle_t,
             ZEImageAllocationExtProperties.ptr ],
           :ze_result_t

  callback :ze_pfnImageViewCreateExt_t,
           [ :ze_context_handle_t,
             :ze_device_handle_t,
             ZEImageDesc.ptr,
             :ze_image_handle_t,
             :pointer ],
           :ze_result_t

  class ZEImageDDITable < FFI::ZEStruct
    layout :pfnGetProperties, :ze_pfnImageGetProperties_t,
           :pfnCreate, :ze_pfnImageCreate_t,
           :pfnDestroy, :ze_pfnImageDestroy_t,
           :pfnGetAllocPropertiesExt, :ze_pfnImageGetAllocPropertiesExt_t,
           :pfnViewCreateExt, :ze_pfnImageViewCreateExt_t
  end
  typedef ZEImageDDITable.by_value, :ze_image_dditable_t

  callback :ze_pfnGetImageProcAddrTable_t,
           [ :ze_api_version_t,
             ZEImageDDITable.ptr ],
           :ze_result_t

  callback :ze_pfnImageGetMemoryPropertiesExp_t,
           [ :ze_image_handle_t,
             ZEImageMemoryPropertiesExp.ptr ],
           :ze_result_t

  callback :ze_pfnImageViewCreateExp_t,
           [ :ze_context_handle_t,
             :ze_device_handle_t,
             ZEImageDesc.ptr,
             :ze_image_handle_t,
             :pointer ],
           :ze_result_t

  callback :ze_pfnImageGetDeviceOffsetExp_t,
           [ :ze_image_handle_t,
             :pointer ],
           :ze_result_t

  class ZEImageExpDDITable < FFI::ZEStruct
    layout :pfnGetMemoryPropertiesExp, :ze_pfnImageGetMemoryPropertiesExp_t,
           :pfnViewCreateExp, :ze_pfnImageViewCreateExp_t,
           :pfnGetDeviceOffsetExp, :ze_pfnImageGetDeviceOffsetExp_t
  end
  typedef ZEImageExpDDITable.by_value, :ze_image_exp_dditable_t

  callback :ze_pfnGetImageExpProcAddrTable_t,
           [ :ze_api_version_t,
             ZEImageExpDDITable.ptr ],
           :ze_result_t

  callback :ze_pfnMemAllocShared_t,
           [ :ze_context_handle_t,
             ZEDeviceMemAllocDesc.ptr,
             ZEHostMemAllocDesc.ptr,
             :size_t,
             :size_t,
             :ze_device_handle_t,
             :pointer ],
           :ze_result_t

  callback :ze_pfnMemAllocDevice_t,
           [ :ze_context_handle_t,
             ZEDeviceMemAllocDesc.ptr,
             :size_t,
             :size_t,
             :ze_device_handle_t,
             :pointer ],
           :ze_result_t

  callback :ze_pfnMemAllocHost_t,
           [ :ze_context_handle_t,
             ZEHostMemAllocDesc.ptr,
             :size_t,
             :size_t,
             :pointer ],
           :ze_result_t

  callback :ze_pfnMemFree_t,
           [ :ze_context_handle_t,
             :pointer ],
           :ze_result_t

  callback :ze_pfnMemGetAllocProperties_t,
           [ :ze_context_handle_t,
             :pointer,
             ZEMemoryAllocationProperties.ptr,
             :pointer ],
           :ze_result_t

  callback :ze_pfnMemGetAddressRange_t,
           [ :ze_context_handle_t,
             :pointer,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :ze_pfnMemGetIpcHandle_t,
           [ :ze_context_handle_t,
             :pointer,
             ZEIpcMemHandle.ptr ],
           :ze_result_t

  callback :ze_pfnMemOpenIpcHandle_t,
           [ :ze_context_handle_t,
             :ze_device_handle_t,
             :ze_ipc_mem_handle_t,
             :ze_ipc_memory_flags_t,
             :pointer ],
           :ze_result_t

  callback :ze_pfnMemCloseIpcHandle_t,
           [ :ze_context_handle_t,
             :pointer ],
           :ze_result_t

  callback :ze_pfnMemFreeExt_t,
           [ :ze_context_handle_t,
             ZEMemoryFreeExtDesc.ptr,
             :pointer ],
           :ze_result_t

  callback :ze_pfnMemPutIpcHandle_t,
           [ :ze_context_handle_t,
             :ze_ipc_mem_handle_t ],
           :ze_result_t

  callback :ze_pfnMemGetPitchFor2dImage_t,
           [ :ze_context_handle_t,
             :ze_device_handle_t,
             :size_t,
             :size_t,
             :uint,
             :pointer ],
           :ze_result_t

  class ZEMemDDITable < FFI::ZEStruct
    layout :pfnAllocShared, :ze_pfnMemAllocShared_t,
           :pfnAllocDevice, :ze_pfnMemAllocDevice_t,
           :pfnAllocHost, :ze_pfnMemAllocHost_t,
           :pfnFree, :ze_pfnMemFree_t,
           :pfnGetAllocProperties, :ze_pfnMemGetAllocProperties_t,
           :pfnGetAddressRange, :ze_pfnMemGetAddressRange_t,
           :pfnGetIpcHandle, :ze_pfnMemGetIpcHandle_t,
           :pfnOpenIpcHandle, :ze_pfnMemOpenIpcHandle_t,
           :pfnCloseIpcHandle, :ze_pfnMemCloseIpcHandle_t,
           :pfnFreeExt, :ze_pfnMemFreeExt_t,
           :pfnPutIpcHandle, :ze_pfnMemPutIpcHandle_t,
           :pfnGetPitchFor2dImage, :ze_pfnMemGetPitchFor2dImage_t
  end
  typedef ZEMemDDITable.by_value, :ze_mem_dditable_t

  callback :ze_pfnGetMemProcAddrTable_t,
           [ :ze_api_version_t,
             ZEMemDDITable.ptr ],
           :ze_result_t

  callback :ze_pfnMemGetIpcHandleFromFileDescriptorExp_t,
           [ :ze_context_handle_t,
             :uint64,
             ZEIpcMemHandle.ptr ],
           :ze_result_t

  callback :ze_pfnMemGetFileDescriptorFromIpcHandleExp_t,
           [ :ze_context_handle_t,
             :ze_ipc_mem_handle_t,
             :pointer ],
           :ze_result_t

  callback :ze_pfnMemSetAtomicAccessAttributeExp_t,
           [ :ze_context_handle_t,
             :ze_device_handle_t,
             :pointer,
             :size_t,
             :ze_memory_atomic_attr_exp_flags_t ],
           :ze_result_t

  callback :ze_pfnMemGetAtomicAccessAttributeExp_t,
           [ :ze_context_handle_t,
             :ze_device_handle_t,
             :pointer,
             :size_t,
             :pointer ],
           :ze_result_t

  class ZEMemExpDDITable < FFI::ZEStruct
    layout :pfnGetIpcHandleFromFileDescriptorExp, :ze_pfnMemGetIpcHandleFromFileDescriptorExp_t,
           :pfnGetFileDescriptorFromIpcHandleExp, :ze_pfnMemGetFileDescriptorFromIpcHandleExp_t,
           :pfnSetAtomicAccessAttributeExp, :ze_pfnMemSetAtomicAccessAttributeExp_t,
           :pfnGetAtomicAccessAttributeExp, :ze_pfnMemGetAtomicAccessAttributeExp_t
  end
  typedef ZEMemExpDDITable.by_value, :ze_mem_exp_dditable_t

  callback :ze_pfnGetMemExpProcAddrTable_t,
           [ :ze_api_version_t,
             ZEMemExpDDITable.ptr ],
           :ze_result_t

  callback :ze_pfnFenceCreate_t,
           [ :ze_command_queue_handle_t,
             ZEFenceDesc.ptr,
             :pointer ],
           :ze_result_t

  callback :ze_pfnFenceDestroy_t,
           [ :ze_fence_handle_t ],
           :ze_result_t

  callback :ze_pfnFenceHostSynchronize_t,
           [ :ze_fence_handle_t,
             :uint64 ],
           :ze_result_t

  callback :ze_pfnFenceQueryStatus_t,
           [ :ze_fence_handle_t ],
           :ze_result_t

  callback :ze_pfnFenceReset_t,
           [ :ze_fence_handle_t ],
           :ze_result_t

  class ZEFenceDDITable < FFI::ZEStruct
    layout :pfnCreate, :ze_pfnFenceCreate_t,
           :pfnDestroy, :ze_pfnFenceDestroy_t,
           :pfnHostSynchronize, :ze_pfnFenceHostSynchronize_t,
           :pfnQueryStatus, :ze_pfnFenceQueryStatus_t,
           :pfnReset, :ze_pfnFenceReset_t
  end
  typedef ZEFenceDDITable.by_value, :ze_fence_dditable_t

  callback :ze_pfnGetFenceProcAddrTable_t,
           [ :ze_api_version_t,
             ZEFenceDDITable.ptr ],
           :ze_result_t

  callback :ze_pfnEventPoolCreate_t,
           [ :ze_context_handle_t,
             ZEEventPoolDesc.ptr,
             :uint32,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :ze_pfnEventPoolDestroy_t,
           [ :ze_event_pool_handle_t ],
           :ze_result_t

  callback :ze_pfnEventPoolGetIpcHandle_t,
           [ :ze_event_pool_handle_t,
             ZEIpcEventPoolHandle.ptr ],
           :ze_result_t

  callback :ze_pfnEventPoolOpenIpcHandle_t,
           [ :ze_context_handle_t,
             :ze_ipc_event_pool_handle_t,
             :pointer ],
           :ze_result_t

  callback :ze_pfnEventPoolCloseIpcHandle_t,
           [ :ze_event_pool_handle_t ],
           :ze_result_t

  callback :ze_pfnEventPoolPutIpcHandle_t,
           [ :ze_context_handle_t,
             :ze_ipc_event_pool_handle_t ],
           :ze_result_t

  callback :ze_pfnEventPoolGetContextHandle_t,
           [ :ze_event_pool_handle_t,
             :pointer ],
           :ze_result_t

  callback :ze_pfnEventPoolGetFlags_t,
           [ :ze_event_pool_handle_t,
             :pointer ],
           :ze_result_t

  class ZEEventPoolDDITable < FFI::ZEStruct
    layout :pfnCreate, :ze_pfnEventPoolCreate_t,
           :pfnDestroy, :ze_pfnEventPoolDestroy_t,
           :pfnGetIpcHandle, :ze_pfnEventPoolGetIpcHandle_t,
           :pfnOpenIpcHandle, :ze_pfnEventPoolOpenIpcHandle_t,
           :pfnCloseIpcHandle, :ze_pfnEventPoolCloseIpcHandle_t,
           :pfnPutIpcHandle, :ze_pfnEventPoolPutIpcHandle_t,
           :pfnGetContextHandle, :ze_pfnEventPoolGetContextHandle_t,
           :pfnGetFlags, :ze_pfnEventPoolGetFlags_t
  end
  typedef ZEEventPoolDDITable.by_value, :ze_event_pool_dditable_t

  callback :ze_pfnGetEventPoolProcAddrTable_t,
           [ :ze_api_version_t,
             ZEEventPoolDDITable.ptr ],
           :ze_result_t

  callback :ze_pfnEventCreate_t,
           [ :ze_event_pool_handle_t,
             ZEEventDesc.ptr,
             :pointer ],
           :ze_result_t

  callback :ze_pfnEventDestroy_t,
           [ :ze_event_handle_t ],
           :ze_result_t

  callback :ze_pfnEventHostSignal_t,
           [ :ze_event_handle_t ],
           :ze_result_t

  callback :ze_pfnEventHostSynchronize_t,
           [ :ze_event_handle_t,
             :uint64 ],
           :ze_result_t

  callback :ze_pfnEventQueryStatus_t,
           [ :ze_event_handle_t ],
           :ze_result_t

  callback :ze_pfnEventHostReset_t,
           [ :ze_event_handle_t ],
           :ze_result_t

  callback :ze_pfnEventQueryKernelTimestamp_t,
           [ :ze_event_handle_t,
             ZEKernelTimestampResult.ptr ],
           :ze_result_t

  callback :ze_pfnEventQueryKernelTimestampsExt_t,
           [ :ze_event_handle_t,
             :ze_device_handle_t,
             :pointer,
             ZEEventQueryKernelTimestampsResultsExtProperties.ptr ],
           :ze_result_t

  callback :ze_pfnEventGetEventPool_t,
           [ :ze_event_handle_t,
             :pointer ],
           :ze_result_t

  callback :ze_pfnEventGetSignalScope_t,
           [ :ze_event_handle_t,
             :pointer ],
           :ze_result_t

  callback :ze_pfnEventGetWaitScope_t,
           [ :ze_event_handle_t,
             :pointer ],
           :ze_result_t

  class ZEEventDDITable < FFI::ZEStruct
    layout :pfnCreate, :ze_pfnEventCreate_t,
           :pfnDestroy, :ze_pfnEventDestroy_t,
           :pfnHostSignal, :ze_pfnEventHostSignal_t,
           :pfnHostSynchronize, :ze_pfnEventHostSynchronize_t,
           :pfnQueryStatus, :ze_pfnEventQueryStatus_t,
           :pfnHostReset, :ze_pfnEventHostReset_t,
           :pfnQueryKernelTimestamp, :ze_pfnEventQueryKernelTimestamp_t,
           :pfnQueryKernelTimestampsExt, :ze_pfnEventQueryKernelTimestampsExt_t,
           :pfnGetEventPool, :ze_pfnEventGetEventPool_t,
           :pfnGetSignalScope, :ze_pfnEventGetSignalScope_t,
           :pfnGetWaitScope, :ze_pfnEventGetWaitScope_t
  end
  typedef ZEEventDDITable.by_value, :ze_event_dditable_t

  callback :ze_pfnGetEventProcAddrTable_t,
           [ :ze_api_version_t,
             ZEEventDDITable.ptr ],
           :ze_result_t

  callback :ze_pfnEventQueryTimestampsExp_t,
           [ :ze_event_handle_t,
             :ze_device_handle_t,
             :pointer,
             ZEKernelTimestampResult.ptr ],
           :ze_result_t

  class ZEEventExpDDITable < FFI::ZEStruct
    layout :pfnQueryTimestampsExp, :ze_pfnEventQueryTimestampsExp_t
  end
  typedef ZEEventExpDDITable.by_value, :ze_event_exp_dditable_t

  callback :ze_pfnGetEventExpProcAddrTable_t,
           [ :ze_api_version_t,
             ZEEventExpDDITable.ptr ],
           :ze_result_t

  callback :ze_pfnModuleCreate_t,
           [ :ze_context_handle_t,
             :ze_device_handle_t,
             ZEModuleDesc.ptr,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :ze_pfnModuleDestroy_t,
           [ :ze_module_handle_t ],
           :ze_result_t

  callback :ze_pfnModuleDynamicLink_t,
           [ :uint32,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :ze_pfnModuleGetNativeBinary_t,
           [ :ze_module_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :ze_pfnModuleGetGlobalPointer_t,
           [ :ze_module_handle_t,
             :pointer,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :ze_pfnModuleGetKernelNames_t,
           [ :ze_module_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :ze_pfnModuleGetProperties_t,
           [ :ze_module_handle_t,
             ZEModuleProperties.ptr ],
           :ze_result_t

  callback :ze_pfnModuleGetFunctionPointer_t,
           [ :ze_module_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :ze_pfnModuleInspectLinkageExt_t,
           [ ZELinkageInspectionExtDesc.ptr,
             :uint32,
             :pointer,
             :pointer ],
           :ze_result_t

  class ZEModuleDDITable < FFI::ZEStruct
    layout :pfnCreate, :ze_pfnModuleCreate_t,
           :pfnDestroy, :ze_pfnModuleDestroy_t,
           :pfnDynamicLink, :ze_pfnModuleDynamicLink_t,
           :pfnGetNativeBinary, :ze_pfnModuleGetNativeBinary_t,
           :pfnGetGlobalPointer, :ze_pfnModuleGetGlobalPointer_t,
           :pfnGetKernelNames, :ze_pfnModuleGetKernelNames_t,
           :pfnGetProperties, :ze_pfnModuleGetProperties_t,
           :pfnGetFunctionPointer, :ze_pfnModuleGetFunctionPointer_t,
           :pfnInspectLinkageExt, :ze_pfnModuleInspectLinkageExt_t
  end
  typedef ZEModuleDDITable.by_value, :ze_module_dditable_t

  callback :ze_pfnGetModuleProcAddrTable_t,
           [ :ze_api_version_t,
             ZEModuleDDITable.ptr ],
           :ze_result_t

  callback :ze_pfnModuleBuildLogDestroy_t,
           [ :ze_module_build_log_handle_t ],
           :ze_result_t

  callback :ze_pfnModuleBuildLogGetString_t,
           [ :ze_module_build_log_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  class ZEModuleBuildLogDDITable < FFI::ZEStruct
    layout :pfnDestroy, :ze_pfnModuleBuildLogDestroy_t,
           :pfnGetString, :ze_pfnModuleBuildLogGetString_t
  end
  typedef ZEModuleBuildLogDDITable.by_value, :ze_module_build_log_dditable_t

  callback :ze_pfnGetModuleBuildLogProcAddrTable_t,
           [ :ze_api_version_t,
             ZEModuleBuildLogDDITable.ptr ],
           :ze_result_t

  callback :ze_pfnKernelCreate_t,
           [ :ze_module_handle_t,
             ZEKernelDesc.ptr,
             :pointer ],
           :ze_result_t

  callback :ze_pfnKernelDestroy_t,
           [ :ze_kernel_handle_t ],
           :ze_result_t

  callback :ze_pfnKernelSetCacheConfig_t,
           [ :ze_kernel_handle_t,
             :ze_cache_config_flags_t ],
           :ze_result_t

  callback :ze_pfnKernelSetGroupSize_t,
           [ :ze_kernel_handle_t,
             :uint32,
             :uint32,
             :uint32 ],
           :ze_result_t

  callback :ze_pfnKernelSuggestGroupSize_t,
           [ :ze_kernel_handle_t,
             :uint32,
             :uint32,
             :uint32,
             :pointer,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :ze_pfnKernelSuggestMaxCooperativeGroupCount_t,
           [ :ze_kernel_handle_t,
             :pointer ],
           :ze_result_t

  callback :ze_pfnKernelSetArgumentValue_t,
           [ :ze_kernel_handle_t,
             :uint32,
             :size_t,
             :pointer ],
           :ze_result_t

  callback :ze_pfnKernelSetIndirectAccess_t,
           [ :ze_kernel_handle_t,
             :ze_kernel_indirect_access_flags_t ],
           :ze_result_t

  callback :ze_pfnKernelGetIndirectAccess_t,
           [ :ze_kernel_handle_t,
             :pointer ],
           :ze_result_t

  callback :ze_pfnKernelGetSourceAttributes_t,
           [ :ze_kernel_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :ze_pfnKernelGetProperties_t,
           [ :ze_kernel_handle_t,
             ZEKernelProperties.ptr ],
           :ze_result_t

  callback :ze_pfnKernelGetName_t,
           [ :ze_kernel_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  class ZEKernelDDITable < FFI::ZEStruct
    layout :pfnCreate, :ze_pfnKernelCreate_t,
           :pfnDestroy, :ze_pfnKernelDestroy_t,
           :pfnSetCacheConfig, :ze_pfnKernelSetCacheConfig_t,
           :pfnSetGroupSize, :ze_pfnKernelSetGroupSize_t,
           :pfnSuggestGroupSize, :ze_pfnKernelSuggestGroupSize_t,
           :pfnSuggestMaxCooperativeGroupCount, :ze_pfnKernelSuggestMaxCooperativeGroupCount_t,
           :pfnSetArgumentValue, :ze_pfnKernelSetArgumentValue_t,
           :pfnSetIndirectAccess, :ze_pfnKernelSetIndirectAccess_t,
           :pfnGetIndirectAccess, :ze_pfnKernelGetIndirectAccess_t,
           :pfnGetSourceAttributes, :ze_pfnKernelGetSourceAttributes_t,
           :pfnGetProperties, :ze_pfnKernelGetProperties_t,
           :pfnGetName, :ze_pfnKernelGetName_t
  end
  typedef ZEKernelDDITable.by_value, :ze_kernel_dditable_t

  callback :ze_pfnGetKernelProcAddrTable_t,
           [ :ze_api_version_t,
             ZEKernelDDITable.ptr ],
           :ze_result_t

  callback :ze_pfnKernelSetGlobalOffsetExp_t,
           [ :ze_kernel_handle_t,
             :uint32,
             :uint32,
             :uint32 ],
           :ze_result_t

  callback :ze_pfnKernelSchedulingHintExp_t,
           [ :ze_kernel_handle_t,
             ZESchedulingHintExpDesc.ptr ],
           :ze_result_t

  callback :ze_pfnKernelGetBinaryExp_t,
           [ :ze_kernel_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  class ZEKernelExpDDITable < FFI::ZEStruct
    layout :pfnSetGlobalOffsetExp, :ze_pfnKernelSetGlobalOffsetExp_t,
           :pfnSchedulingHintExp, :ze_pfnKernelSchedulingHintExp_t,
           :pfnGetBinaryExp, :ze_pfnKernelGetBinaryExp_t
  end
  typedef ZEKernelExpDDITable.by_value, :ze_kernel_exp_dditable_t

  callback :ze_pfnGetKernelExpProcAddrTable_t,
           [ :ze_api_version_t,
             ZEKernelExpDDITable.ptr ],
           :ze_result_t

  callback :ze_pfnSamplerCreate_t,
           [ :ze_context_handle_t,
             :ze_device_handle_t,
             ZESamplerDesc.ptr,
             :pointer ],
           :ze_result_t

  callback :ze_pfnSamplerDestroy_t,
           [ :ze_sampler_handle_t ],
           :ze_result_t

  class ZESamplerDDITable < FFI::ZEStruct
    layout :pfnCreate, :ze_pfnSamplerCreate_t,
           :pfnDestroy, :ze_pfnSamplerDestroy_t
  end
  typedef ZESamplerDDITable.by_value, :ze_sampler_dditable_t

  callback :ze_pfnGetSamplerProcAddrTable_t,
           [ :ze_api_version_t,
             ZESamplerDDITable.ptr ],
           :ze_result_t

  callback :ze_pfnPhysicalMemCreate_t,
           [ :ze_context_handle_t,
             :ze_device_handle_t,
             ZEPhysicalMemDesc.ptr,
             :pointer ],
           :ze_result_t

  callback :ze_pfnPhysicalMemDestroy_t,
           [ :ze_context_handle_t,
             :ze_physical_mem_handle_t ],
           :ze_result_t

  class ZEPhysicalMemDDITable < FFI::ZEStruct
    layout :pfnCreate, :ze_pfnPhysicalMemCreate_t,
           :pfnDestroy, :ze_pfnPhysicalMemDestroy_t
  end
  typedef ZEPhysicalMemDDITable.by_value, :ze_physical_mem_dditable_t

  callback :ze_pfnGetPhysicalMemProcAddrTable_t,
           [ :ze_api_version_t,
             ZEPhysicalMemDDITable.ptr ],
           :ze_result_t

  callback :ze_pfnVirtualMemReserve_t,
           [ :ze_context_handle_t,
             :pointer,
             :size_t,
             :pointer ],
           :ze_result_t

  callback :ze_pfnVirtualMemFree_t,
           [ :ze_context_handle_t,
             :pointer,
             :size_t ],
           :ze_result_t

  callback :ze_pfnVirtualMemQueryPageSize_t,
           [ :ze_context_handle_t,
             :ze_device_handle_t,
             :size_t,
             :pointer ],
           :ze_result_t

  callback :ze_pfnVirtualMemMap_t,
           [ :ze_context_handle_t,
             :pointer,
             :size_t,
             :ze_physical_mem_handle_t,
             :size_t,
             :ze_memory_access_attribute_t ],
           :ze_result_t

  callback :ze_pfnVirtualMemUnmap_t,
           [ :ze_context_handle_t,
             :pointer,
             :size_t ],
           :ze_result_t

  callback :ze_pfnVirtualMemSetAccessAttribute_t,
           [ :ze_context_handle_t,
             :pointer,
             :size_t,
             :ze_memory_access_attribute_t ],
           :ze_result_t

  callback :ze_pfnVirtualMemGetAccessAttribute_t,
           [ :ze_context_handle_t,
             :pointer,
             :size_t,
             :pointer,
             :pointer ],
           :ze_result_t

  class ZEVirtualMemDDITable < FFI::ZEStruct
    layout :pfnReserve, :ze_pfnVirtualMemReserve_t,
           :pfnFree, :ze_pfnVirtualMemFree_t,
           :pfnQueryPageSize, :ze_pfnVirtualMemQueryPageSize_t,
           :pfnMap, :ze_pfnVirtualMemMap_t,
           :pfnUnmap, :ze_pfnVirtualMemUnmap_t,
           :pfnSetAccessAttribute, :ze_pfnVirtualMemSetAccessAttribute_t,
           :pfnGetAccessAttribute, :ze_pfnVirtualMemGetAccessAttribute_t
  end
  typedef ZEVirtualMemDDITable.by_value, :ze_virtual_mem_dditable_t

  callback :ze_pfnGetVirtualMemProcAddrTable_t,
           [ :ze_api_version_t,
             ZEVirtualMemDDITable.ptr ],
           :ze_result_t

  callback :ze_pfnFabricVertexGetExp_t,
           [ :ze_driver_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :ze_pfnFabricVertexGetSubVerticesExp_t,
           [ :ze_fabric_vertex_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :ze_pfnFabricVertexGetPropertiesExp_t,
           [ :ze_fabric_vertex_handle_t,
             ZEFabricVertexExpProperties.ptr ],
           :ze_result_t

  callback :ze_pfnFabricVertexGetDeviceExp_t,
           [ :ze_fabric_vertex_handle_t,
             :pointer ],
           :ze_result_t

  class ZEFabricVertexExpDDITable < FFI::ZEStruct
    layout :pfnGetExp, :ze_pfnFabricVertexGetExp_t,
           :pfnGetSubVerticesExp, :ze_pfnFabricVertexGetSubVerticesExp_t,
           :pfnGetPropertiesExp, :ze_pfnFabricVertexGetPropertiesExp_t,
           :pfnGetDeviceExp, :ze_pfnFabricVertexGetDeviceExp_t
  end
  typedef ZEFabricVertexExpDDITable.by_value, :ze_fabric_vertex_exp_dditable_t

  callback :ze_pfnGetFabricVertexExpProcAddrTable_t,
           [ :ze_api_version_t,
             ZEFabricVertexExpDDITable.ptr ],
           :ze_result_t

  callback :ze_pfnFabricEdgeGetExp_t,
           [ :ze_fabric_vertex_handle_t,
             :ze_fabric_vertex_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :ze_pfnFabricEdgeGetVerticesExp_t,
           [ :ze_fabric_edge_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :ze_pfnFabricEdgeGetPropertiesExp_t,
           [ :ze_fabric_edge_handle_t,
             ZEFabricEdgeExpProperties.ptr ],
           :ze_result_t

  class ZEFabricEdgeExpDDITable < FFI::ZEStruct
    layout :pfnGetExp, :ze_pfnFabricEdgeGetExp_t,
           :pfnGetVerticesExp, :ze_pfnFabricEdgeGetVerticesExp_t,
           :pfnGetPropertiesExp, :ze_pfnFabricEdgeGetPropertiesExp_t
  end
  typedef ZEFabricEdgeExpDDITable.by_value, :ze_fabric_edge_exp_dditable_t

  callback :ze_pfnGetFabricEdgeExpProcAddrTable_t,
           [ :ze_api_version_t,
             ZEFabricEdgeExpDDITable.ptr ],
           :ze_result_t

  class ZEDDITable < FFI::ZEStruct
    layout :RTASBuilder, :ze_rtas_builder_dditable_t,
           :RTASBuilderExp, :ze_rtas_builder_exp_dditable_t,
           :RTASParallelOperation, :ze_rtas_parallel_operation_dditable_t,
           :RTASParallelOperationExp, :ze_rtas_parallel_operation_exp_dditable_t,
           :Global, :ze_global_dditable_t,
           :Driver, :ze_driver_dditable_t,
           :DriverExp, :ze_driver_exp_dditable_t,
           :Device, :ze_device_dditable_t,
           :DeviceExp, :ze_device_exp_dditable_t,
           :Context, :ze_context_dditable_t,
           :CommandQueue, :ze_command_queue_dditable_t,
           :CommandList, :ze_command_list_dditable_t,
           :CommandListExp, :ze_command_list_exp_dditable_t,
           :Image, :ze_image_dditable_t,
           :ImageExp, :ze_image_exp_dditable_t,
           :Mem, :ze_mem_dditable_t,
           :MemExp, :ze_mem_exp_dditable_t,
           :Fence, :ze_fence_dditable_t,
           :EventPool, :ze_event_pool_dditable_t,
           :Event, :ze_event_dditable_t,
           :EventExp, :ze_event_exp_dditable_t,
           :Module, :ze_module_dditable_t,
           :ModuleBuildLog, :ze_module_build_log_dditable_t,
           :Kernel, :ze_kernel_dditable_t,
           :KernelExp, :ze_kernel_exp_dditable_t,
           :Sampler, :ze_sampler_dditable_t,
           :PhysicalMem, :ze_physical_mem_dditable_t,
           :VirtualMem, :ze_virtual_mem_dditable_t,
           :FabricVertexExp, :ze_fabric_vertex_exp_dditable_t,
           :FabricEdgeExp, :ze_fabric_edge_exp_dditable_t
  end
  typedef ZEDDITable.by_value, :ze_dditable_t

  class ZEDDITableDriver < FFI::ZEStruct
    layout :version, :ze_api_version_t,
           :isValidFlag, :uint8,
           :RTASBuilder, :pointer,
           :RTASBuilderExp, :pointer,
           :RTASParallelOperation, :pointer,
           :RTASParallelOperationExp, :pointer,
           :Global, :pointer,
           :Driver, :pointer,
           :DriverExp, :pointer,
           :Device, :pointer,
           :DeviceExp, :pointer,
           :Context, :pointer,
           :CommandQueue, :pointer,
           :CommandList, :pointer,
           :CommandListExp, :pointer,
           :Image, :pointer,
           :ImageExp, :pointer,
           :Mem, :pointer,
           :MemExp, :pointer,
           :Fence, :pointer,
           :EventPool, :pointer,
           :Event, :pointer,
           :EventExp, :pointer,
           :Module, :pointer,
           :ModuleBuildLog, :pointer,
           :Kernel, :pointer,
           :KernelExp, :pointer,
           :Sampler, :pointer,
           :PhysicalMem, :pointer,
           :VirtualMem, :pointer,
           :FabricVertexExp, :pointer,
           :FabricEdgeExp, :pointer
  end
  typedef ZEDDITableDriver.by_value, :ze_dditable_driver_t

  class ZERtasBuilderDDITableT113 < FFI::ZEStruct
    layout :pfnCreateExt, :ze_pfnRTASBuilderCreateExt_t,
           :pfnGetBuildPropertiesExt, :ze_pfnRTASBuilderGetBuildPropertiesExt_t,
           :pfnBuildExt, :ze_pfnRTASBuilderBuildExt_t,
           :pfnCommandListAppendCopyExt, :ze_pfnRTASBuilderCommandListAppendCopyExt_t,
           :pfnDestroyExt, :ze_pfnRTASBuilderDestroyExt_t
  end
  typedef ZERtasBuilderDDITableT113.by_value, :ze_rtas_builder_dditable_t_1_13

  class ZERtasBuilderExpDDITableT17 < FFI::ZEStruct
    layout :pfnCreateExp, :ze_pfnRTASBuilderCreateExp_t,
           :pfnGetBuildPropertiesExp, :ze_pfnRTASBuilderGetBuildPropertiesExp_t,
           :pfnBuildExp, :ze_pfnRTASBuilderBuildExp_t,
           :pfnDestroyExp, :ze_pfnRTASBuilderDestroyExp_t
  end
  typedef ZERtasBuilderExpDDITableT17.by_value, :ze_rtas_builder_exp_dditable_t_1_7

  class ZERtasParallelOperationDDITableT113 < FFI::ZEStruct
    layout :pfnCreateExt, :ze_pfnRTASParallelOperationCreateExt_t,
           :pfnGetPropertiesExt, :ze_pfnRTASParallelOperationGetPropertiesExt_t,
           :pfnJoinExt, :ze_pfnRTASParallelOperationJoinExt_t,
           :pfnDestroyExt, :ze_pfnRTASParallelOperationDestroyExt_t
  end
  typedef ZERtasParallelOperationDDITableT113.by_value, :ze_rtas_parallel_operation_dditable_t_1_13

  class ZERtasParallelOperationExpDDITableT17 < FFI::ZEStruct
    layout :pfnCreateExp, :ze_pfnRTASParallelOperationCreateExp_t,
           :pfnGetPropertiesExp, :ze_pfnRTASParallelOperationGetPropertiesExp_t,
           :pfnJoinExp, :ze_pfnRTASParallelOperationJoinExp_t,
           :pfnDestroyExp, :ze_pfnRTASParallelOperationDestroyExp_t
  end
  typedef ZERtasParallelOperationExpDDITableT17.by_value, :ze_rtas_parallel_operation_exp_dditable_t_1_7

  class ZEGlobalDDITableT10 < FFI::ZEStruct
    layout :pfnInit, :ze_pfnInit_t
  end
  typedef ZEGlobalDDITableT10.by_value, :ze_global_dditable_t_1_0

  class ZEGlobalDDITableT11 < FFI::ZEStruct
    layout :pfnInit, :ze_pfnInit_t,
           :pfnInitDrivers, :ze_pfnInitDrivers_t
  end
  typedef ZEGlobalDDITableT11.by_value, :ze_global_dditable_t_1_1

  class ZEDriverDDITableT10 < FFI::ZEStruct
    layout :pfnGet, :ze_pfnDriverGet_t,
           :pfnGetApiVersion, :ze_pfnDriverGetApiVersion_t,
           :pfnGetProperties, :ze_pfnDriverGetProperties_t,
           :pfnGetIpcProperties, :ze_pfnDriverGetIpcProperties_t,
           :pfnGetExtensionProperties, :ze_pfnDriverGetExtensionProperties_t
  end
  typedef ZEDriverDDITableT10.by_value, :ze_driver_dditable_t_1_0

  class ZEDriverDDITableT11 < FFI::ZEStruct
    layout :pfnGet, :ze_pfnDriverGet_t,
           :pfnGetApiVersion, :ze_pfnDriverGetApiVersion_t,
           :pfnGetProperties, :ze_pfnDriverGetProperties_t,
           :pfnGetIpcProperties, :ze_pfnDriverGetIpcProperties_t,
           :pfnGetExtensionProperties, :ze_pfnDriverGetExtensionProperties_t,
           :pfnGetExtensionFunctionAddress, :ze_pfnDriverGetExtensionFunctionAddress_t
  end
  typedef ZEDriverDDITableT11.by_value, :ze_driver_dditable_t_1_1

  class ZEDriverDDITableT113 < FFI::ZEStruct
    layout :pfnGet, :ze_pfnDriverGet_t,
           :pfnGetApiVersion, :ze_pfnDriverGetApiVersion_t,
           :pfnGetProperties, :ze_pfnDriverGetProperties_t,
           :pfnGetIpcProperties, :ze_pfnDriverGetIpcProperties_t,
           :pfnGetExtensionProperties, :ze_pfnDriverGetExtensionProperties_t,
           :pfnGetExtensionFunctionAddress, :ze_pfnDriverGetExtensionFunctionAddress_t,
           :pfnRTASFormatCompatibilityCheckExt, :ze_pfnDriverRTASFormatCompatibilityCheckExt_t
  end
  typedef ZEDriverDDITableT113.by_value, :ze_driver_dditable_t_1_13

  class ZEDriverDDITableT16 < FFI::ZEStruct
    layout :pfnGet, :ze_pfnDriverGet_t,
           :pfnGetApiVersion, :ze_pfnDriverGetApiVersion_t,
           :pfnGetProperties, :ze_pfnDriverGetProperties_t,
           :pfnGetIpcProperties, :ze_pfnDriverGetIpcProperties_t,
           :pfnGetExtensionProperties, :ze_pfnDriverGetExtensionProperties_t,
           :pfnGetExtensionFunctionAddress, :ze_pfnDriverGetExtensionFunctionAddress_t,
           :pfnGetLastErrorDescription, :ze_pfnDriverGetLastErrorDescription_t,
           :pfnRTASFormatCompatibilityCheckExt, :ze_pfnDriverRTASFormatCompatibilityCheckExt_t
  end
  typedef ZEDriverDDITableT16.by_value, :ze_driver_dditable_t_1_6

  class ZEDriverExpDDITableT17 < FFI::ZEStruct
    layout :pfnRTASFormatCompatibilityCheckExp, :ze_pfnDriverRTASFormatCompatibilityCheckExp_t
  end
  typedef ZEDriverExpDDITableT17.by_value, :ze_driver_exp_dditable_t_1_7

  class ZEDeviceDDITableT10 < FFI::ZEStruct
    layout :pfnGet, :ze_pfnDeviceGet_t,
           :pfnGetSubDevices, :ze_pfnDeviceGetSubDevices_t,
           :pfnGetProperties, :ze_pfnDeviceGetProperties_t,
           :pfnGetComputeProperties, :ze_pfnDeviceGetComputeProperties_t,
           :pfnGetModuleProperties, :ze_pfnDeviceGetModuleProperties_t,
           :pfnGetCommandQueueGroupProperties, :ze_pfnDeviceGetCommandQueueGroupProperties_t,
           :pfnGetMemoryProperties, :ze_pfnDeviceGetMemoryProperties_t,
           :pfnGetMemoryAccessProperties, :ze_pfnDeviceGetMemoryAccessProperties_t,
           :pfnGetCacheProperties, :ze_pfnDeviceGetCacheProperties_t,
           :pfnGetImageProperties, :ze_pfnDeviceGetImageProperties_t,
           :pfnGetExternalMemoryProperties, :ze_pfnDeviceGetExternalMemoryProperties_t,
           :pfnGetP2PProperties, :ze_pfnDeviceGetP2PProperties_t,
           :pfnCanAccessPeer, :ze_pfnDeviceCanAccessPeer_t,
           :pfnGetStatus, :ze_pfnDeviceGetStatus_t
  end
  typedef ZEDeviceDDITableT10.by_value, :ze_device_dditable_t_1_0

  class ZEDeviceDDITableT11 < FFI::ZEStruct
    layout :pfnGet, :ze_pfnDeviceGet_t,
           :pfnGetSubDevices, :ze_pfnDeviceGetSubDevices_t,
           :pfnGetProperties, :ze_pfnDeviceGetProperties_t,
           :pfnGetComputeProperties, :ze_pfnDeviceGetComputeProperties_t,
           :pfnGetModuleProperties, :ze_pfnDeviceGetModuleProperties_t,
           :pfnGetCommandQueueGroupProperties, :ze_pfnDeviceGetCommandQueueGroupProperties_t,
           :pfnGetMemoryProperties, :ze_pfnDeviceGetMemoryProperties_t,
           :pfnGetMemoryAccessProperties, :ze_pfnDeviceGetMemoryAccessProperties_t,
           :pfnGetCacheProperties, :ze_pfnDeviceGetCacheProperties_t,
           :pfnGetImageProperties, :ze_pfnDeviceGetImageProperties_t,
           :pfnGetExternalMemoryProperties, :ze_pfnDeviceGetExternalMemoryProperties_t,
           :pfnGetP2PProperties, :ze_pfnDeviceGetP2PProperties_t,
           :pfnCanAccessPeer, :ze_pfnDeviceCanAccessPeer_t,
           :pfnGetStatus, :ze_pfnDeviceGetStatus_t,
           :pfnGetGlobalTimestamps, :ze_pfnDeviceGetGlobalTimestamps_t
  end
  typedef ZEDeviceDDITableT11.by_value, :ze_device_dditable_t_1_1

  class ZEDeviceDDITableT112 < FFI::ZEStruct
    layout :pfnGet, :ze_pfnDeviceGet_t,
           :pfnGetSubDevices, :ze_pfnDeviceGetSubDevices_t,
           :pfnGetProperties, :ze_pfnDeviceGetProperties_t,
           :pfnGetComputeProperties, :ze_pfnDeviceGetComputeProperties_t,
           :pfnGetModuleProperties, :ze_pfnDeviceGetModuleProperties_t,
           :pfnGetCommandQueueGroupProperties, :ze_pfnDeviceGetCommandQueueGroupProperties_t,
           :pfnGetMemoryProperties, :ze_pfnDeviceGetMemoryProperties_t,
           :pfnGetMemoryAccessProperties, :ze_pfnDeviceGetMemoryAccessProperties_t,
           :pfnGetCacheProperties, :ze_pfnDeviceGetCacheProperties_t,
           :pfnGetImageProperties, :ze_pfnDeviceGetImageProperties_t,
           :pfnGetExternalMemoryProperties, :ze_pfnDeviceGetExternalMemoryProperties_t,
           :pfnGetP2PProperties, :ze_pfnDeviceGetP2PProperties_t,
           :pfnCanAccessPeer, :ze_pfnDeviceCanAccessPeer_t,
           :pfnGetStatus, :ze_pfnDeviceGetStatus_t,
           :pfnGetGlobalTimestamps, :ze_pfnDeviceGetGlobalTimestamps_t,
           :pfnImportExternalSemaphoreExt, :ze_pfnDeviceImportExternalSemaphoreExt_t,
           :pfnReleaseExternalSemaphoreExt, :ze_pfnDeviceReleaseExternalSemaphoreExt_t
  end
  typedef ZEDeviceDDITableT112.by_value, :ze_device_dditable_t_1_12

  class ZEDeviceDDITableT113 < FFI::ZEStruct
    layout :pfnGet, :ze_pfnDeviceGet_t,
           :pfnGetSubDevices, :ze_pfnDeviceGetSubDevices_t,
           :pfnGetProperties, :ze_pfnDeviceGetProperties_t,
           :pfnGetComputeProperties, :ze_pfnDeviceGetComputeProperties_t,
           :pfnGetModuleProperties, :ze_pfnDeviceGetModuleProperties_t,
           :pfnGetCommandQueueGroupProperties, :ze_pfnDeviceGetCommandQueueGroupProperties_t,
           :pfnGetMemoryProperties, :ze_pfnDeviceGetMemoryProperties_t,
           :pfnGetMemoryAccessProperties, :ze_pfnDeviceGetMemoryAccessProperties_t,
           :pfnGetCacheProperties, :ze_pfnDeviceGetCacheProperties_t,
           :pfnGetImageProperties, :ze_pfnDeviceGetImageProperties_t,
           :pfnGetExternalMemoryProperties, :ze_pfnDeviceGetExternalMemoryProperties_t,
           :pfnGetP2PProperties, :ze_pfnDeviceGetP2PProperties_t,
           :pfnCanAccessPeer, :ze_pfnDeviceCanAccessPeer_t,
           :pfnGetStatus, :ze_pfnDeviceGetStatus_t,
           :pfnGetGlobalTimestamps, :ze_pfnDeviceGetGlobalTimestamps_t,
           :pfnImportExternalSemaphoreExt, :ze_pfnDeviceImportExternalSemaphoreExt_t,
           :pfnReleaseExternalSemaphoreExt, :ze_pfnDeviceReleaseExternalSemaphoreExt_t,
           :pfnGetVectorWidthPropertiesExt, :ze_pfnDeviceGetVectorWidthPropertiesExt_t
  end
  typedef ZEDeviceDDITableT113.by_value, :ze_device_dditable_t_1_13

  class ZEDeviceDDITableT12 < FFI::ZEStruct
    layout :pfnGet, :ze_pfnDeviceGet_t,
           :pfnGetSubDevices, :ze_pfnDeviceGetSubDevices_t,
           :pfnGetProperties, :ze_pfnDeviceGetProperties_t,
           :pfnGetComputeProperties, :ze_pfnDeviceGetComputeProperties_t,
           :pfnGetModuleProperties, :ze_pfnDeviceGetModuleProperties_t,
           :pfnGetCommandQueueGroupProperties, :ze_pfnDeviceGetCommandQueueGroupProperties_t,
           :pfnGetMemoryProperties, :ze_pfnDeviceGetMemoryProperties_t,
           :pfnGetMemoryAccessProperties, :ze_pfnDeviceGetMemoryAccessProperties_t,
           :pfnGetCacheProperties, :ze_pfnDeviceGetCacheProperties_t,
           :pfnGetImageProperties, :ze_pfnDeviceGetImageProperties_t,
           :pfnGetExternalMemoryProperties, :ze_pfnDeviceGetExternalMemoryProperties_t,
           :pfnGetP2PProperties, :ze_pfnDeviceGetP2PProperties_t,
           :pfnCanAccessPeer, :ze_pfnDeviceCanAccessPeer_t,
           :pfnGetStatus, :ze_pfnDeviceGetStatus_t,
           :pfnGetGlobalTimestamps, :ze_pfnDeviceGetGlobalTimestamps_t,
           :pfnReserveCacheExt, :ze_pfnDeviceReserveCacheExt_t,
           :pfnSetCacheAdviceExt, :ze_pfnDeviceSetCacheAdviceExt_t,
           :pfnImportExternalSemaphoreExt, :ze_pfnDeviceImportExternalSemaphoreExt_t,
           :pfnReleaseExternalSemaphoreExt, :ze_pfnDeviceReleaseExternalSemaphoreExt_t,
           :pfnGetVectorWidthPropertiesExt, :ze_pfnDeviceGetVectorWidthPropertiesExt_t
  end
  typedef ZEDeviceDDITableT12.by_value, :ze_device_dditable_t_1_2

  class ZEDeviceDDITableT13 < FFI::ZEStruct
    layout :pfnGet, :ze_pfnDeviceGet_t,
           :pfnGetSubDevices, :ze_pfnDeviceGetSubDevices_t,
           :pfnGetProperties, :ze_pfnDeviceGetProperties_t,
           :pfnGetComputeProperties, :ze_pfnDeviceGetComputeProperties_t,
           :pfnGetModuleProperties, :ze_pfnDeviceGetModuleProperties_t,
           :pfnGetCommandQueueGroupProperties, :ze_pfnDeviceGetCommandQueueGroupProperties_t,
           :pfnGetMemoryProperties, :ze_pfnDeviceGetMemoryProperties_t,
           :pfnGetMemoryAccessProperties, :ze_pfnDeviceGetMemoryAccessProperties_t,
           :pfnGetCacheProperties, :ze_pfnDeviceGetCacheProperties_t,
           :pfnGetImageProperties, :ze_pfnDeviceGetImageProperties_t,
           :pfnGetExternalMemoryProperties, :ze_pfnDeviceGetExternalMemoryProperties_t,
           :pfnGetP2PProperties, :ze_pfnDeviceGetP2PProperties_t,
           :pfnCanAccessPeer, :ze_pfnDeviceCanAccessPeer_t,
           :pfnGetStatus, :ze_pfnDeviceGetStatus_t,
           :pfnGetGlobalTimestamps, :ze_pfnDeviceGetGlobalTimestamps_t,
           :pfnReserveCacheExt, :ze_pfnDeviceReserveCacheExt_t,
           :pfnSetCacheAdviceExt, :ze_pfnDeviceSetCacheAdviceExt_t,
           :pfnPciGetPropertiesExt, :ze_pfnDevicePciGetPropertiesExt_t,
           :pfnImportExternalSemaphoreExt, :ze_pfnDeviceImportExternalSemaphoreExt_t,
           :pfnReleaseExternalSemaphoreExt, :ze_pfnDeviceReleaseExternalSemaphoreExt_t,
           :pfnGetVectorWidthPropertiesExt, :ze_pfnDeviceGetVectorWidthPropertiesExt_t
  end
  typedef ZEDeviceDDITableT13.by_value, :ze_device_dditable_t_1_3

  class ZEDeviceDDITableT17 < FFI::ZEStruct
    layout :pfnGet, :ze_pfnDeviceGet_t,
           :pfnGetSubDevices, :ze_pfnDeviceGetSubDevices_t,
           :pfnGetProperties, :ze_pfnDeviceGetProperties_t,
           :pfnGetComputeProperties, :ze_pfnDeviceGetComputeProperties_t,
           :pfnGetModuleProperties, :ze_pfnDeviceGetModuleProperties_t,
           :pfnGetCommandQueueGroupProperties, :ze_pfnDeviceGetCommandQueueGroupProperties_t,
           :pfnGetMemoryProperties, :ze_pfnDeviceGetMemoryProperties_t,
           :pfnGetMemoryAccessProperties, :ze_pfnDeviceGetMemoryAccessProperties_t,
           :pfnGetCacheProperties, :ze_pfnDeviceGetCacheProperties_t,
           :pfnGetImageProperties, :ze_pfnDeviceGetImageProperties_t,
           :pfnGetExternalMemoryProperties, :ze_pfnDeviceGetExternalMemoryProperties_t,
           :pfnGetP2PProperties, :ze_pfnDeviceGetP2PProperties_t,
           :pfnCanAccessPeer, :ze_pfnDeviceCanAccessPeer_t,
           :pfnGetStatus, :ze_pfnDeviceGetStatus_t,
           :pfnGetGlobalTimestamps, :ze_pfnDeviceGetGlobalTimestamps_t,
           :pfnReserveCacheExt, :ze_pfnDeviceReserveCacheExt_t,
           :pfnSetCacheAdviceExt, :ze_pfnDeviceSetCacheAdviceExt_t,
           :pfnPciGetPropertiesExt, :ze_pfnDevicePciGetPropertiesExt_t,
           :pfnGetRootDevice, :ze_pfnDeviceGetRootDevice_t,
           :pfnImportExternalSemaphoreExt, :ze_pfnDeviceImportExternalSemaphoreExt_t,
           :pfnReleaseExternalSemaphoreExt, :ze_pfnDeviceReleaseExternalSemaphoreExt_t,
           :pfnGetVectorWidthPropertiesExt, :ze_pfnDeviceGetVectorWidthPropertiesExt_t
  end
  typedef ZEDeviceDDITableT17.by_value, :ze_device_dditable_t_1_7

  class ZEDeviceExpDDITableT14 < FFI::ZEStruct
    layout :pfnGetFabricVertexExp, :ze_pfnDeviceGetFabricVertexExp_t
  end
  typedef ZEDeviceExpDDITableT14.by_value, :ze_device_exp_dditable_t_1_4

  class ZEContextDDITableT10 < FFI::ZEStruct
    layout :pfnCreate, :ze_pfnContextCreate_t,
           :pfnDestroy, :ze_pfnContextDestroy_t,
           :pfnGetStatus, :ze_pfnContextGetStatus_t,
           :pfnSystemBarrier, :ze_pfnContextSystemBarrier_t,
           :pfnMakeMemoryResident, :ze_pfnContextMakeMemoryResident_t,
           :pfnEvictMemory, :ze_pfnContextEvictMemory_t,
           :pfnMakeImageResident, :ze_pfnContextMakeImageResident_t,
           :pfnEvictImage, :ze_pfnContextEvictImage_t
  end
  typedef ZEContextDDITableT10.by_value, :ze_context_dditable_t_1_0

  class ZEContextDDITableT11 < FFI::ZEStruct
    layout :pfnCreate, :ze_pfnContextCreate_t,
           :pfnDestroy, :ze_pfnContextDestroy_t,
           :pfnGetStatus, :ze_pfnContextGetStatus_t,
           :pfnSystemBarrier, :ze_pfnContextSystemBarrier_t,
           :pfnMakeMemoryResident, :ze_pfnContextMakeMemoryResident_t,
           :pfnEvictMemory, :ze_pfnContextEvictMemory_t,
           :pfnMakeImageResident, :ze_pfnContextMakeImageResident_t,
           :pfnEvictImage, :ze_pfnContextEvictImage_t,
           :pfnCreateEx, :ze_pfnContextCreateEx_t
  end
  typedef ZEContextDDITableT11.by_value, :ze_context_dditable_t_1_1

  class ZECommandQueueDDITableT10 < FFI::ZEStruct
    layout :pfnCreate, :ze_pfnCommandQueueCreate_t,
           :pfnDestroy, :ze_pfnCommandQueueDestroy_t,
           :pfnExecuteCommandLists, :ze_pfnCommandQueueExecuteCommandLists_t,
           :pfnSynchronize, :ze_pfnCommandQueueSynchronize_t
  end
  typedef ZECommandQueueDDITableT10.by_value, :ze_command_queue_dditable_t_1_0

  class ZECommandQueueDDITableT19 < FFI::ZEStruct
    layout :pfnCreate, :ze_pfnCommandQueueCreate_t,
           :pfnDestroy, :ze_pfnCommandQueueDestroy_t,
           :pfnExecuteCommandLists, :ze_pfnCommandQueueExecuteCommandLists_t,
           :pfnSynchronize, :ze_pfnCommandQueueSynchronize_t,
           :pfnGetOrdinal, :ze_pfnCommandQueueGetOrdinal_t,
           :pfnGetIndex, :ze_pfnCommandQueueGetIndex_t
  end
  typedef ZECommandQueueDDITableT19.by_value, :ze_command_queue_dditable_t_1_9

  class ZECommandListDDITableT10 < FFI::ZEStruct
    layout :pfnCreate, :ze_pfnCommandListCreate_t,
           :pfnCreateImmediate, :ze_pfnCommandListCreateImmediate_t,
           :pfnDestroy, :ze_pfnCommandListDestroy_t,
           :pfnClose, :ze_pfnCommandListClose_t,
           :pfnReset, :ze_pfnCommandListReset_t,
           :pfnAppendWriteGlobalTimestamp, :ze_pfnCommandListAppendWriteGlobalTimestamp_t,
           :pfnAppendBarrier, :ze_pfnCommandListAppendBarrier_t,
           :pfnAppendMemoryRangesBarrier, :ze_pfnCommandListAppendMemoryRangesBarrier_t,
           :pfnAppendMemoryCopy, :ze_pfnCommandListAppendMemoryCopy_t,
           :pfnAppendMemoryFill, :ze_pfnCommandListAppendMemoryFill_t,
           :pfnAppendMemoryCopyRegion, :ze_pfnCommandListAppendMemoryCopyRegion_t,
           :pfnAppendMemoryCopyFromContext, :ze_pfnCommandListAppendMemoryCopyFromContext_t,
           :pfnAppendImageCopy, :ze_pfnCommandListAppendImageCopy_t,
           :pfnAppendImageCopyRegion, :ze_pfnCommandListAppendImageCopyRegion_t,
           :pfnAppendImageCopyToMemory, :ze_pfnCommandListAppendImageCopyToMemory_t,
           :pfnAppendImageCopyFromMemory, :ze_pfnCommandListAppendImageCopyFromMemory_t,
           :pfnAppendMemoryPrefetch, :ze_pfnCommandListAppendMemoryPrefetch_t,
           :pfnAppendMemAdvise, :ze_pfnCommandListAppendMemAdvise_t,
           :pfnAppendSignalEvent, :ze_pfnCommandListAppendSignalEvent_t,
           :pfnAppendWaitOnEvents, :ze_pfnCommandListAppendWaitOnEvents_t,
           :pfnAppendEventReset, :ze_pfnCommandListAppendEventReset_t,
           :pfnAppendQueryKernelTimestamps, :ze_pfnCommandListAppendQueryKernelTimestamps_t,
           :pfnAppendLaunchKernel, :ze_pfnCommandListAppendLaunchKernel_t,
           :pfnAppendLaunchCooperativeKernel, :ze_pfnCommandListAppendLaunchCooperativeKernel_t,
           :pfnAppendLaunchKernelIndirect, :ze_pfnCommandListAppendLaunchKernelIndirect_t,
           :pfnAppendLaunchMultipleKernelsIndirect, :ze_pfnCommandListAppendLaunchMultipleKernelsIndirect_t
  end
  typedef ZECommandListDDITableT10.by_value, :ze_command_list_dditable_t_1_0

  class ZECommandListDDITableT112 < FFI::ZEStruct
    layout :pfnCreate, :ze_pfnCommandListCreate_t,
           :pfnCreateImmediate, :ze_pfnCommandListCreateImmediate_t,
           :pfnDestroy, :ze_pfnCommandListDestroy_t,
           :pfnClose, :ze_pfnCommandListClose_t,
           :pfnReset, :ze_pfnCommandListReset_t,
           :pfnAppendWriteGlobalTimestamp, :ze_pfnCommandListAppendWriteGlobalTimestamp_t,
           :pfnAppendBarrier, :ze_pfnCommandListAppendBarrier_t,
           :pfnAppendMemoryRangesBarrier, :ze_pfnCommandListAppendMemoryRangesBarrier_t,
           :pfnAppendMemoryCopy, :ze_pfnCommandListAppendMemoryCopy_t,
           :pfnAppendMemoryFill, :ze_pfnCommandListAppendMemoryFill_t,
           :pfnAppendMemoryCopyRegion, :ze_pfnCommandListAppendMemoryCopyRegion_t,
           :pfnAppendMemoryCopyFromContext, :ze_pfnCommandListAppendMemoryCopyFromContext_t,
           :pfnAppendImageCopy, :ze_pfnCommandListAppendImageCopy_t,
           :pfnAppendImageCopyRegion, :ze_pfnCommandListAppendImageCopyRegion_t,
           :pfnAppendImageCopyToMemory, :ze_pfnCommandListAppendImageCopyToMemory_t,
           :pfnAppendImageCopyFromMemory, :ze_pfnCommandListAppendImageCopyFromMemory_t,
           :pfnAppendMemoryPrefetch, :ze_pfnCommandListAppendMemoryPrefetch_t,
           :pfnAppendMemAdvise, :ze_pfnCommandListAppendMemAdvise_t,
           :pfnAppendSignalEvent, :ze_pfnCommandListAppendSignalEvent_t,
           :pfnAppendWaitOnEvents, :ze_pfnCommandListAppendWaitOnEvents_t,
           :pfnAppendEventReset, :ze_pfnCommandListAppendEventReset_t,
           :pfnAppendQueryKernelTimestamps, :ze_pfnCommandListAppendQueryKernelTimestamps_t,
           :pfnAppendLaunchKernel, :ze_pfnCommandListAppendLaunchKernel_t,
           :pfnAppendLaunchCooperativeKernel, :ze_pfnCommandListAppendLaunchCooperativeKernel_t,
           :pfnAppendLaunchKernelIndirect, :ze_pfnCommandListAppendLaunchKernelIndirect_t,
           :pfnAppendLaunchMultipleKernelsIndirect, :ze_pfnCommandListAppendLaunchMultipleKernelsIndirect_t,
           :pfnAppendSignalExternalSemaphoreExt, :ze_pfnCommandListAppendSignalExternalSemaphoreExt_t,
           :pfnAppendWaitExternalSemaphoreExt, :ze_pfnCommandListAppendWaitExternalSemaphoreExt_t
  end
  typedef ZECommandListDDITableT112.by_value, :ze_command_list_dditable_t_1_12

  class ZECommandListDDITableT13 < FFI::ZEStruct
    layout :pfnCreate, :ze_pfnCommandListCreate_t,
           :pfnCreateImmediate, :ze_pfnCommandListCreateImmediate_t,
           :pfnDestroy, :ze_pfnCommandListDestroy_t,
           :pfnClose, :ze_pfnCommandListClose_t,
           :pfnReset, :ze_pfnCommandListReset_t,
           :pfnAppendWriteGlobalTimestamp, :ze_pfnCommandListAppendWriteGlobalTimestamp_t,
           :pfnAppendBarrier, :ze_pfnCommandListAppendBarrier_t,
           :pfnAppendMemoryRangesBarrier, :ze_pfnCommandListAppendMemoryRangesBarrier_t,
           :pfnAppendMemoryCopy, :ze_pfnCommandListAppendMemoryCopy_t,
           :pfnAppendMemoryFill, :ze_pfnCommandListAppendMemoryFill_t,
           :pfnAppendMemoryCopyRegion, :ze_pfnCommandListAppendMemoryCopyRegion_t,
           :pfnAppendMemoryCopyFromContext, :ze_pfnCommandListAppendMemoryCopyFromContext_t,
           :pfnAppendImageCopy, :ze_pfnCommandListAppendImageCopy_t,
           :pfnAppendImageCopyRegion, :ze_pfnCommandListAppendImageCopyRegion_t,
           :pfnAppendImageCopyToMemory, :ze_pfnCommandListAppendImageCopyToMemory_t,
           :pfnAppendImageCopyFromMemory, :ze_pfnCommandListAppendImageCopyFromMemory_t,
           :pfnAppendMemoryPrefetch, :ze_pfnCommandListAppendMemoryPrefetch_t,
           :pfnAppendMemAdvise, :ze_pfnCommandListAppendMemAdvise_t,
           :pfnAppendSignalEvent, :ze_pfnCommandListAppendSignalEvent_t,
           :pfnAppendWaitOnEvents, :ze_pfnCommandListAppendWaitOnEvents_t,
           :pfnAppendEventReset, :ze_pfnCommandListAppendEventReset_t,
           :pfnAppendQueryKernelTimestamps, :ze_pfnCommandListAppendQueryKernelTimestamps_t,
           :pfnAppendLaunchKernel, :ze_pfnCommandListAppendLaunchKernel_t,
           :pfnAppendLaunchCooperativeKernel, :ze_pfnCommandListAppendLaunchCooperativeKernel_t,
           :pfnAppendLaunchKernelIndirect, :ze_pfnCommandListAppendLaunchKernelIndirect_t,
           :pfnAppendLaunchMultipleKernelsIndirect, :ze_pfnCommandListAppendLaunchMultipleKernelsIndirect_t,
           :pfnAppendImageCopyToMemoryExt, :ze_pfnCommandListAppendImageCopyToMemoryExt_t,
           :pfnAppendImageCopyFromMemoryExt, :ze_pfnCommandListAppendImageCopyFromMemoryExt_t,
           :pfnAppendSignalExternalSemaphoreExt, :ze_pfnCommandListAppendSignalExternalSemaphoreExt_t,
           :pfnAppendWaitExternalSemaphoreExt, :ze_pfnCommandListAppendWaitExternalSemaphoreExt_t
  end
  typedef ZECommandListDDITableT13.by_value, :ze_command_list_dditable_t_1_3

  class ZECommandListDDITableT16 < FFI::ZEStruct
    layout :pfnCreate, :ze_pfnCommandListCreate_t,
           :pfnCreateImmediate, :ze_pfnCommandListCreateImmediate_t,
           :pfnDestroy, :ze_pfnCommandListDestroy_t,
           :pfnClose, :ze_pfnCommandListClose_t,
           :pfnReset, :ze_pfnCommandListReset_t,
           :pfnAppendWriteGlobalTimestamp, :ze_pfnCommandListAppendWriteGlobalTimestamp_t,
           :pfnAppendBarrier, :ze_pfnCommandListAppendBarrier_t,
           :pfnAppendMemoryRangesBarrier, :ze_pfnCommandListAppendMemoryRangesBarrier_t,
           :pfnAppendMemoryCopy, :ze_pfnCommandListAppendMemoryCopy_t,
           :pfnAppendMemoryFill, :ze_pfnCommandListAppendMemoryFill_t,
           :pfnAppendMemoryCopyRegion, :ze_pfnCommandListAppendMemoryCopyRegion_t,
           :pfnAppendMemoryCopyFromContext, :ze_pfnCommandListAppendMemoryCopyFromContext_t,
           :pfnAppendImageCopy, :ze_pfnCommandListAppendImageCopy_t,
           :pfnAppendImageCopyRegion, :ze_pfnCommandListAppendImageCopyRegion_t,
           :pfnAppendImageCopyToMemory, :ze_pfnCommandListAppendImageCopyToMemory_t,
           :pfnAppendImageCopyFromMemory, :ze_pfnCommandListAppendImageCopyFromMemory_t,
           :pfnAppendMemoryPrefetch, :ze_pfnCommandListAppendMemoryPrefetch_t,
           :pfnAppendMemAdvise, :ze_pfnCommandListAppendMemAdvise_t,
           :pfnAppendSignalEvent, :ze_pfnCommandListAppendSignalEvent_t,
           :pfnAppendWaitOnEvents, :ze_pfnCommandListAppendWaitOnEvents_t,
           :pfnAppendEventReset, :ze_pfnCommandListAppendEventReset_t,
           :pfnAppendQueryKernelTimestamps, :ze_pfnCommandListAppendQueryKernelTimestamps_t,
           :pfnAppendLaunchKernel, :ze_pfnCommandListAppendLaunchKernel_t,
           :pfnAppendLaunchCooperativeKernel, :ze_pfnCommandListAppendLaunchCooperativeKernel_t,
           :pfnAppendLaunchKernelIndirect, :ze_pfnCommandListAppendLaunchKernelIndirect_t,
           :pfnAppendLaunchMultipleKernelsIndirect, :ze_pfnCommandListAppendLaunchMultipleKernelsIndirect_t,
           :pfnAppendImageCopyToMemoryExt, :ze_pfnCommandListAppendImageCopyToMemoryExt_t,
           :pfnAppendImageCopyFromMemoryExt, :ze_pfnCommandListAppendImageCopyFromMemoryExt_t,
           :pfnHostSynchronize, :ze_pfnCommandListHostSynchronize_t,
           :pfnAppendSignalExternalSemaphoreExt, :ze_pfnCommandListAppendSignalExternalSemaphoreExt_t,
           :pfnAppendWaitExternalSemaphoreExt, :ze_pfnCommandListAppendWaitExternalSemaphoreExt_t
  end
  typedef ZECommandListDDITableT16.by_value, :ze_command_list_dditable_t_1_6

  class ZECommandListDDITableT19 < FFI::ZEStruct
    layout :pfnCreate, :ze_pfnCommandListCreate_t,
           :pfnCreateImmediate, :ze_pfnCommandListCreateImmediate_t,
           :pfnDestroy, :ze_pfnCommandListDestroy_t,
           :pfnClose, :ze_pfnCommandListClose_t,
           :pfnReset, :ze_pfnCommandListReset_t,
           :pfnAppendWriteGlobalTimestamp, :ze_pfnCommandListAppendWriteGlobalTimestamp_t,
           :pfnAppendBarrier, :ze_pfnCommandListAppendBarrier_t,
           :pfnAppendMemoryRangesBarrier, :ze_pfnCommandListAppendMemoryRangesBarrier_t,
           :pfnAppendMemoryCopy, :ze_pfnCommandListAppendMemoryCopy_t,
           :pfnAppendMemoryFill, :ze_pfnCommandListAppendMemoryFill_t,
           :pfnAppendMemoryCopyRegion, :ze_pfnCommandListAppendMemoryCopyRegion_t,
           :pfnAppendMemoryCopyFromContext, :ze_pfnCommandListAppendMemoryCopyFromContext_t,
           :pfnAppendImageCopy, :ze_pfnCommandListAppendImageCopy_t,
           :pfnAppendImageCopyRegion, :ze_pfnCommandListAppendImageCopyRegion_t,
           :pfnAppendImageCopyToMemory, :ze_pfnCommandListAppendImageCopyToMemory_t,
           :pfnAppendImageCopyFromMemory, :ze_pfnCommandListAppendImageCopyFromMemory_t,
           :pfnAppendMemoryPrefetch, :ze_pfnCommandListAppendMemoryPrefetch_t,
           :pfnAppendMemAdvise, :ze_pfnCommandListAppendMemAdvise_t,
           :pfnAppendSignalEvent, :ze_pfnCommandListAppendSignalEvent_t,
           :pfnAppendWaitOnEvents, :ze_pfnCommandListAppendWaitOnEvents_t,
           :pfnAppendEventReset, :ze_pfnCommandListAppendEventReset_t,
           :pfnAppendQueryKernelTimestamps, :ze_pfnCommandListAppendQueryKernelTimestamps_t,
           :pfnAppendLaunchKernel, :ze_pfnCommandListAppendLaunchKernel_t,
           :pfnAppendLaunchCooperativeKernel, :ze_pfnCommandListAppendLaunchCooperativeKernel_t,
           :pfnAppendLaunchKernelIndirect, :ze_pfnCommandListAppendLaunchKernelIndirect_t,
           :pfnAppendLaunchMultipleKernelsIndirect, :ze_pfnCommandListAppendLaunchMultipleKernelsIndirect_t,
           :pfnAppendImageCopyToMemoryExt, :ze_pfnCommandListAppendImageCopyToMemoryExt_t,
           :pfnAppendImageCopyFromMemoryExt, :ze_pfnCommandListAppendImageCopyFromMemoryExt_t,
           :pfnHostSynchronize, :ze_pfnCommandListHostSynchronize_t,
           :pfnGetDeviceHandle, :ze_pfnCommandListGetDeviceHandle_t,
           :pfnGetContextHandle, :ze_pfnCommandListGetContextHandle_t,
           :pfnGetOrdinal, :ze_pfnCommandListGetOrdinal_t,
           :pfnImmediateGetIndex, :ze_pfnCommandListImmediateGetIndex_t,
           :pfnIsImmediate, :ze_pfnCommandListIsImmediate_t,
           :pfnAppendSignalExternalSemaphoreExt, :ze_pfnCommandListAppendSignalExternalSemaphoreExt_t,
           :pfnAppendWaitExternalSemaphoreExt, :ze_pfnCommandListAppendWaitExternalSemaphoreExt_t
  end
  typedef ZECommandListDDITableT19.by_value, :ze_command_list_dditable_t_1_9

  class ZECommandListExpDDITableT11 < FFI::ZEStruct
    layout :pfnGetNextCommandIdWithKernelsExp, :ze_pfnCommandListGetNextCommandIdWithKernelsExp_t,
           :pfnUpdateMutableCommandKernelsExp, :ze_pfnCommandListUpdateMutableCommandKernelsExp_t
  end
  typedef ZECommandListExpDDITableT11.by_value, :ze_command_list_exp_dditable_t_1_1

  class ZECommandListExpDDITableT19 < FFI::ZEStruct
    layout :pfnCreateCloneExp, :ze_pfnCommandListCreateCloneExp_t,
           :pfnImmediateAppendCommandListsExp, :ze_pfnCommandListImmediateAppendCommandListsExp_t,
           :pfnGetNextCommandIdExp, :ze_pfnCommandListGetNextCommandIdExp_t,
           :pfnUpdateMutableCommandsExp, :ze_pfnCommandListUpdateMutableCommandsExp_t,
           :pfnUpdateMutableCommandSignalEventExp, :ze_pfnCommandListUpdateMutableCommandSignalEventExp_t,
           :pfnUpdateMutableCommandWaitEventsExp, :ze_pfnCommandListUpdateMutableCommandWaitEventsExp_t,
           :pfnGetNextCommandIdWithKernelsExp, :ze_pfnCommandListGetNextCommandIdWithKernelsExp_t,
           :pfnUpdateMutableCommandKernelsExp, :ze_pfnCommandListUpdateMutableCommandKernelsExp_t
  end
  typedef ZECommandListExpDDITableT19.by_value, :ze_command_list_exp_dditable_t_1_9

  class ZEImageDDITableT10 < FFI::ZEStruct
    layout :pfnGetProperties, :ze_pfnImageGetProperties_t,
           :pfnCreate, :ze_pfnImageCreate_t,
           :pfnDestroy, :ze_pfnImageDestroy_t
  end
  typedef ZEImageDDITableT10.by_value, :ze_image_dditable_t_1_0

  class ZEImageDDITableT13 < FFI::ZEStruct
    layout :pfnGetProperties, :ze_pfnImageGetProperties_t,
           :pfnCreate, :ze_pfnImageCreate_t,
           :pfnDestroy, :ze_pfnImageDestroy_t,
           :pfnGetAllocPropertiesExt, :ze_pfnImageGetAllocPropertiesExt_t
  end
  typedef ZEImageDDITableT13.by_value, :ze_image_dditable_t_1_3

  class ZEImageDDITableT15 < FFI::ZEStruct
    layout :pfnGetProperties, :ze_pfnImageGetProperties_t,
           :pfnCreate, :ze_pfnImageCreate_t,
           :pfnDestroy, :ze_pfnImageDestroy_t,
           :pfnGetAllocPropertiesExt, :ze_pfnImageGetAllocPropertiesExt_t,
           :pfnViewCreateExt, :ze_pfnImageViewCreateExt_t
  end
  typedef ZEImageDDITableT15.by_value, :ze_image_dditable_t_1_5

  class ZEImageExpDDITableT12 < FFI::ZEStruct
    layout :pfnGetMemoryPropertiesExp, :ze_pfnImageGetMemoryPropertiesExp_t,
           :pfnViewCreateExp, :ze_pfnImageViewCreateExp_t
  end
  typedef ZEImageExpDDITableT12.by_value, :ze_image_exp_dditable_t_1_2

  class ZEImageExpDDITableT19 < FFI::ZEStruct
    layout :pfnGetMemoryPropertiesExp, :ze_pfnImageGetMemoryPropertiesExp_t,
           :pfnViewCreateExp, :ze_pfnImageViewCreateExp_t,
           :pfnGetDeviceOffsetExp, :ze_pfnImageGetDeviceOffsetExp_t
  end
  typedef ZEImageExpDDITableT19.by_value, :ze_image_exp_dditable_t_1_9

  class ZEMemDDITableT10 < FFI::ZEStruct
    layout :pfnAllocShared, :ze_pfnMemAllocShared_t,
           :pfnAllocDevice, :ze_pfnMemAllocDevice_t,
           :pfnAllocHost, :ze_pfnMemAllocHost_t,
           :pfnFree, :ze_pfnMemFree_t,
           :pfnGetAllocProperties, :ze_pfnMemGetAllocProperties_t,
           :pfnGetAddressRange, :ze_pfnMemGetAddressRange_t,
           :pfnGetIpcHandle, :ze_pfnMemGetIpcHandle_t,
           :pfnOpenIpcHandle, :ze_pfnMemOpenIpcHandle_t,
           :pfnCloseIpcHandle, :ze_pfnMemCloseIpcHandle_t
  end
  typedef ZEMemDDITableT10.by_value, :ze_mem_dditable_t_1_0

  class ZEMemDDITableT13 < FFI::ZEStruct
    layout :pfnAllocShared, :ze_pfnMemAllocShared_t,
           :pfnAllocDevice, :ze_pfnMemAllocDevice_t,
           :pfnAllocHost, :ze_pfnMemAllocHost_t,
           :pfnFree, :ze_pfnMemFree_t,
           :pfnGetAllocProperties, :ze_pfnMemGetAllocProperties_t,
           :pfnGetAddressRange, :ze_pfnMemGetAddressRange_t,
           :pfnGetIpcHandle, :ze_pfnMemGetIpcHandle_t,
           :pfnOpenIpcHandle, :ze_pfnMemOpenIpcHandle_t,
           :pfnCloseIpcHandle, :ze_pfnMemCloseIpcHandle_t,
           :pfnFreeExt, :ze_pfnMemFreeExt_t
  end
  typedef ZEMemDDITableT13.by_value, :ze_mem_dditable_t_1_3

  class ZEMemDDITableT16 < FFI::ZEStruct
    layout :pfnAllocShared, :ze_pfnMemAllocShared_t,
           :pfnAllocDevice, :ze_pfnMemAllocDevice_t,
           :pfnAllocHost, :ze_pfnMemAllocHost_t,
           :pfnFree, :ze_pfnMemFree_t,
           :pfnGetAllocProperties, :ze_pfnMemGetAllocProperties_t,
           :pfnGetAddressRange, :ze_pfnMemGetAddressRange_t,
           :pfnGetIpcHandle, :ze_pfnMemGetIpcHandle_t,
           :pfnOpenIpcHandle, :ze_pfnMemOpenIpcHandle_t,
           :pfnCloseIpcHandle, :ze_pfnMemCloseIpcHandle_t,
           :pfnFreeExt, :ze_pfnMemFreeExt_t,
           :pfnPutIpcHandle, :ze_pfnMemPutIpcHandle_t
  end
  typedef ZEMemDDITableT16.by_value, :ze_mem_dditable_t_1_6

  class ZEMemDDITableT19 < FFI::ZEStruct
    layout :pfnAllocShared, :ze_pfnMemAllocShared_t,
           :pfnAllocDevice, :ze_pfnMemAllocDevice_t,
           :pfnAllocHost, :ze_pfnMemAllocHost_t,
           :pfnFree, :ze_pfnMemFree_t,
           :pfnGetAllocProperties, :ze_pfnMemGetAllocProperties_t,
           :pfnGetAddressRange, :ze_pfnMemGetAddressRange_t,
           :pfnGetIpcHandle, :ze_pfnMemGetIpcHandle_t,
           :pfnOpenIpcHandle, :ze_pfnMemOpenIpcHandle_t,
           :pfnCloseIpcHandle, :ze_pfnMemCloseIpcHandle_t,
           :pfnFreeExt, :ze_pfnMemFreeExt_t,
           :pfnPutIpcHandle, :ze_pfnMemPutIpcHandle_t,
           :pfnGetPitchFor2dImage, :ze_pfnMemGetPitchFor2dImage_t
  end
  typedef ZEMemDDITableT19.by_value, :ze_mem_dditable_t_1_9

  class ZEMemExpDDITableT16 < FFI::ZEStruct
    layout :pfnGetIpcHandleFromFileDescriptorExp, :ze_pfnMemGetIpcHandleFromFileDescriptorExp_t,
           :pfnGetFileDescriptorFromIpcHandleExp, :ze_pfnMemGetFileDescriptorFromIpcHandleExp_t
  end
  typedef ZEMemExpDDITableT16.by_value, :ze_mem_exp_dditable_t_1_6

  class ZEMemExpDDITableT17 < FFI::ZEStruct
    layout :pfnGetIpcHandleFromFileDescriptorExp, :ze_pfnMemGetIpcHandleFromFileDescriptorExp_t,
           :pfnGetFileDescriptorFromIpcHandleExp, :ze_pfnMemGetFileDescriptorFromIpcHandleExp_t,
           :pfnSetAtomicAccessAttributeExp, :ze_pfnMemSetAtomicAccessAttributeExp_t,
           :pfnGetAtomicAccessAttributeExp, :ze_pfnMemGetAtomicAccessAttributeExp_t
  end
  typedef ZEMemExpDDITableT17.by_value, :ze_mem_exp_dditable_t_1_7

  class ZEFenceDDITableT10 < FFI::ZEStruct
    layout :pfnCreate, :ze_pfnFenceCreate_t,
           :pfnDestroy, :ze_pfnFenceDestroy_t,
           :pfnHostSynchronize, :ze_pfnFenceHostSynchronize_t,
           :pfnQueryStatus, :ze_pfnFenceQueryStatus_t,
           :pfnReset, :ze_pfnFenceReset_t
  end
  typedef ZEFenceDDITableT10.by_value, :ze_fence_dditable_t_1_0

  class ZEEventPoolDDITableT10 < FFI::ZEStruct
    layout :pfnCreate, :ze_pfnEventPoolCreate_t,
           :pfnDestroy, :ze_pfnEventPoolDestroy_t,
           :pfnGetIpcHandle, :ze_pfnEventPoolGetIpcHandle_t,
           :pfnOpenIpcHandle, :ze_pfnEventPoolOpenIpcHandle_t,
           :pfnCloseIpcHandle, :ze_pfnEventPoolCloseIpcHandle_t
  end
  typedef ZEEventPoolDDITableT10.by_value, :ze_event_pool_dditable_t_1_0

  class ZEEventPoolDDITableT16 < FFI::ZEStruct
    layout :pfnCreate, :ze_pfnEventPoolCreate_t,
           :pfnDestroy, :ze_pfnEventPoolDestroy_t,
           :pfnGetIpcHandle, :ze_pfnEventPoolGetIpcHandle_t,
           :pfnOpenIpcHandle, :ze_pfnEventPoolOpenIpcHandle_t,
           :pfnCloseIpcHandle, :ze_pfnEventPoolCloseIpcHandle_t,
           :pfnPutIpcHandle, :ze_pfnEventPoolPutIpcHandle_t
  end
  typedef ZEEventPoolDDITableT16.by_value, :ze_event_pool_dditable_t_1_6

  class ZEEventPoolDDITableT19 < FFI::ZEStruct
    layout :pfnCreate, :ze_pfnEventPoolCreate_t,
           :pfnDestroy, :ze_pfnEventPoolDestroy_t,
           :pfnGetIpcHandle, :ze_pfnEventPoolGetIpcHandle_t,
           :pfnOpenIpcHandle, :ze_pfnEventPoolOpenIpcHandle_t,
           :pfnCloseIpcHandle, :ze_pfnEventPoolCloseIpcHandle_t,
           :pfnPutIpcHandle, :ze_pfnEventPoolPutIpcHandle_t,
           :pfnGetContextHandle, :ze_pfnEventPoolGetContextHandle_t,
           :pfnGetFlags, :ze_pfnEventPoolGetFlags_t
  end
  typedef ZEEventPoolDDITableT19.by_value, :ze_event_pool_dditable_t_1_9

  class ZEEventDDITableT10 < FFI::ZEStruct
    layout :pfnCreate, :ze_pfnEventCreate_t,
           :pfnDestroy, :ze_pfnEventDestroy_t,
           :pfnHostSignal, :ze_pfnEventHostSignal_t,
           :pfnHostSynchronize, :ze_pfnEventHostSynchronize_t,
           :pfnQueryStatus, :ze_pfnEventQueryStatus_t,
           :pfnHostReset, :ze_pfnEventHostReset_t,
           :pfnQueryKernelTimestamp, :ze_pfnEventQueryKernelTimestamp_t
  end
  typedef ZEEventDDITableT10.by_value, :ze_event_dditable_t_1_0

  class ZEEventDDITableT16 < FFI::ZEStruct
    layout :pfnCreate, :ze_pfnEventCreate_t,
           :pfnDestroy, :ze_pfnEventDestroy_t,
           :pfnHostSignal, :ze_pfnEventHostSignal_t,
           :pfnHostSynchronize, :ze_pfnEventHostSynchronize_t,
           :pfnQueryStatus, :ze_pfnEventQueryStatus_t,
           :pfnHostReset, :ze_pfnEventHostReset_t,
           :pfnQueryKernelTimestamp, :ze_pfnEventQueryKernelTimestamp_t,
           :pfnQueryKernelTimestampsExt, :ze_pfnEventQueryKernelTimestampsExt_t
  end
  typedef ZEEventDDITableT16.by_value, :ze_event_dditable_t_1_6

  class ZEEventDDITableT19 < FFI::ZEStruct
    layout :pfnCreate, :ze_pfnEventCreate_t,
           :pfnDestroy, :ze_pfnEventDestroy_t,
           :pfnHostSignal, :ze_pfnEventHostSignal_t,
           :pfnHostSynchronize, :ze_pfnEventHostSynchronize_t,
           :pfnQueryStatus, :ze_pfnEventQueryStatus_t,
           :pfnHostReset, :ze_pfnEventHostReset_t,
           :pfnQueryKernelTimestamp, :ze_pfnEventQueryKernelTimestamp_t,
           :pfnQueryKernelTimestampsExt, :ze_pfnEventQueryKernelTimestampsExt_t,
           :pfnGetEventPool, :ze_pfnEventGetEventPool_t,
           :pfnGetSignalScope, :ze_pfnEventGetSignalScope_t,
           :pfnGetWaitScope, :ze_pfnEventGetWaitScope_t
  end
  typedef ZEEventDDITableT19.by_value, :ze_event_dditable_t_1_9

  class ZEEventExpDDITableT12 < FFI::ZEStruct
    layout :pfnQueryTimestampsExp, :ze_pfnEventQueryTimestampsExp_t
  end
  typedef ZEEventExpDDITableT12.by_value, :ze_event_exp_dditable_t_1_2

  class ZEModuleDDITableT10 < FFI::ZEStruct
    layout :pfnCreate, :ze_pfnModuleCreate_t,
           :pfnDestroy, :ze_pfnModuleDestroy_t,
           :pfnDynamicLink, :ze_pfnModuleDynamicLink_t,
           :pfnGetNativeBinary, :ze_pfnModuleGetNativeBinary_t,
           :pfnGetGlobalPointer, :ze_pfnModuleGetGlobalPointer_t,
           :pfnGetKernelNames, :ze_pfnModuleGetKernelNames_t,
           :pfnGetProperties, :ze_pfnModuleGetProperties_t,
           :pfnGetFunctionPointer, :ze_pfnModuleGetFunctionPointer_t
  end
  typedef ZEModuleDDITableT10.by_value, :ze_module_dditable_t_1_0

  class ZEModuleDDITableT13 < FFI::ZEStruct
    layout :pfnCreate, :ze_pfnModuleCreate_t,
           :pfnDestroy, :ze_pfnModuleDestroy_t,
           :pfnDynamicLink, :ze_pfnModuleDynamicLink_t,
           :pfnGetNativeBinary, :ze_pfnModuleGetNativeBinary_t,
           :pfnGetGlobalPointer, :ze_pfnModuleGetGlobalPointer_t,
           :pfnGetKernelNames, :ze_pfnModuleGetKernelNames_t,
           :pfnGetProperties, :ze_pfnModuleGetProperties_t,
           :pfnGetFunctionPointer, :ze_pfnModuleGetFunctionPointer_t,
           :pfnInspectLinkageExt, :ze_pfnModuleInspectLinkageExt_t
  end
  typedef ZEModuleDDITableT13.by_value, :ze_module_dditable_t_1_3

  class ZEModuleBuildLogDDITableT10 < FFI::ZEStruct
    layout :pfnDestroy, :ze_pfnModuleBuildLogDestroy_t,
           :pfnGetString, :ze_pfnModuleBuildLogGetString_t
  end
  typedef ZEModuleBuildLogDDITableT10.by_value, :ze_module_build_log_dditable_t_1_0

  class ZEKernelDDITableT10 < FFI::ZEStruct
    layout :pfnCreate, :ze_pfnKernelCreate_t,
           :pfnDestroy, :ze_pfnKernelDestroy_t,
           :pfnSetCacheConfig, :ze_pfnKernelSetCacheConfig_t,
           :pfnSetGroupSize, :ze_pfnKernelSetGroupSize_t,
           :pfnSuggestGroupSize, :ze_pfnKernelSuggestGroupSize_t,
           :pfnSuggestMaxCooperativeGroupCount, :ze_pfnKernelSuggestMaxCooperativeGroupCount_t,
           :pfnSetArgumentValue, :ze_pfnKernelSetArgumentValue_t,
           :pfnSetIndirectAccess, :ze_pfnKernelSetIndirectAccess_t,
           :pfnGetIndirectAccess, :ze_pfnKernelGetIndirectAccess_t,
           :pfnGetSourceAttributes, :ze_pfnKernelGetSourceAttributes_t,
           :pfnGetProperties, :ze_pfnKernelGetProperties_t,
           :pfnGetName, :ze_pfnKernelGetName_t
  end
  typedef ZEKernelDDITableT10.by_value, :ze_kernel_dditable_t_1_0

  class ZEKernelExpDDITableT11 < FFI::ZEStruct
    layout :pfnSetGlobalOffsetExp, :ze_pfnKernelSetGlobalOffsetExp_t
  end
  typedef ZEKernelExpDDITableT11.by_value, :ze_kernel_exp_dditable_t_1_1

  class ZEKernelExpDDITableT111 < FFI::ZEStruct
    layout :pfnSetGlobalOffsetExp, :ze_pfnKernelSetGlobalOffsetExp_t,
           :pfnGetBinaryExp, :ze_pfnKernelGetBinaryExp_t
  end
  typedef ZEKernelExpDDITableT111.by_value, :ze_kernel_exp_dditable_t_1_11

  class ZEKernelExpDDITableT12 < FFI::ZEStruct
    layout :pfnSetGlobalOffsetExp, :ze_pfnKernelSetGlobalOffsetExp_t,
           :pfnSchedulingHintExp, :ze_pfnKernelSchedulingHintExp_t,
           :pfnGetBinaryExp, :ze_pfnKernelGetBinaryExp_t
  end
  typedef ZEKernelExpDDITableT12.by_value, :ze_kernel_exp_dditable_t_1_2

  class ZESamplerDDITableT10 < FFI::ZEStruct
    layout :pfnCreate, :ze_pfnSamplerCreate_t,
           :pfnDestroy, :ze_pfnSamplerDestroy_t
  end
  typedef ZESamplerDDITableT10.by_value, :ze_sampler_dditable_t_1_0

  class ZEPhysicalMemDDITableT10 < FFI::ZEStruct
    layout :pfnCreate, :ze_pfnPhysicalMemCreate_t,
           :pfnDestroy, :ze_pfnPhysicalMemDestroy_t
  end
  typedef ZEPhysicalMemDDITableT10.by_value, :ze_physical_mem_dditable_t_1_0

  class ZEVirtualMemDDITableT10 < FFI::ZEStruct
    layout :pfnReserve, :ze_pfnVirtualMemReserve_t,
           :pfnFree, :ze_pfnVirtualMemFree_t,
           :pfnQueryPageSize, :ze_pfnVirtualMemQueryPageSize_t,
           :pfnMap, :ze_pfnVirtualMemMap_t,
           :pfnUnmap, :ze_pfnVirtualMemUnmap_t,
           :pfnSetAccessAttribute, :ze_pfnVirtualMemSetAccessAttribute_t,
           :pfnGetAccessAttribute, :ze_pfnVirtualMemGetAccessAttribute_t
  end
  typedef ZEVirtualMemDDITableT10.by_value, :ze_virtual_mem_dditable_t_1_0

  class ZEFabricVertexExpDDITableT14 < FFI::ZEStruct
    layout :pfnGetExp, :ze_pfnFabricVertexGetExp_t,
           :pfnGetSubVerticesExp, :ze_pfnFabricVertexGetSubVerticesExp_t,
           :pfnGetPropertiesExp, :ze_pfnFabricVertexGetPropertiesExp_t,
           :pfnGetDeviceExp, :ze_pfnFabricVertexGetDeviceExp_t
  end
  typedef ZEFabricVertexExpDDITableT14.by_value, :ze_fabric_vertex_exp_dditable_t_1_4

  class ZEFabricEdgeExpDDITableT14 < FFI::ZEStruct
    layout :pfnGetExp, :ze_pfnFabricEdgeGetExp_t,
           :pfnGetVerticesExp, :ze_pfnFabricEdgeGetVerticesExp_t,
           :pfnGetPropertiesExp, :ze_pfnFabricEdgeGetPropertiesExp_t
  end
  typedef ZEFabricEdgeExpDDITableT14.by_value, :ze_fabric_edge_exp_dditable_t_1_4

  class ZETBaseProperties < FFI::ZEStruct
    layout :stype, :zet_structure_type_t,
           :pNext, :pointer
  end
  typedef ZETBaseProperties.by_value, :zet_base_properties_t

  class ZETBaseDesc < FFI::ZEStruct
    layout :stype, :zet_structure_type_t,
           :pNext, :pointer
  end
  typedef ZETBaseDesc.by_value, :zet_base_desc_t

  class ZETValue < FFI::ZEUnion
    layout :ui32, :uint32,
           :ui64, :uint64,
           :fp32, :float,
           :fp64, :double,
           :b8, :ze_bool_t
  end
  typedef ZETValue.by_value, :zet_value_t

  class ZETTypedValue < FFI::ZEStruct
    layout :type, :zet_value_type_t,
           :value, :zet_value_t
  end
  typedef ZETTypedValue.by_value, :zet_typed_value_t

  class ZETDeviceDebugProperties < FFI::ZEStruct
    layout :stype, :zet_structure_type_t,
           :pNext, :pointer,
           :flags, :zet_device_debug_property_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZET_STRUCTURE_TYPE_DEVICE_DEBUG_PROPERTIES
      end
    end
  end
  typedef ZETDeviceDebugProperties.by_value, :zet_device_debug_properties_t

  class ZETDebugConfig < FFI::ZEStruct
    layout :pid, :uint32
  end
  typedef ZETDebugConfig.by_value, :zet_debug_config_t

  class ZETDebugEventInfoDetached < FFI::ZEStruct
    layout :reason, :zet_debug_detach_reason_t
  end
  typedef ZETDebugEventInfoDetached.by_value, :zet_debug_event_info_detached_t

  class ZETDebugEventInfoModule < FFI::ZEStruct
    layout :format, :zet_module_debug_info_format_t,
           :moduleBegin, :uint64,
           :moduleEnd, :uint64,
           :load, :uint64
  end
  typedef ZETDebugEventInfoModule.by_value, :zet_debug_event_info_module_t

  class ZETDebugEventInfoThreadStopped < FFI::ZEStruct
    layout :thread, :ze_device_thread_t
  end
  typedef ZETDebugEventInfoThreadStopped.by_value, :zet_debug_event_info_thread_stopped_t

  class ZETDebugEventInfoPageFault < FFI::ZEStruct
    layout :address, :uint64,
           :mask, :uint64,
           :reason, :zet_debug_page_fault_reason_t
  end
  typedef ZETDebugEventInfoPageFault.by_value, :zet_debug_event_info_page_fault_t

  class ZETDebugEventInfo < FFI::ZEUnion
    layout :detached, :zet_debug_event_info_detached_t,
           :module, :zet_debug_event_info_module_t,
           :thread, :zet_debug_event_info_thread_stopped_t,
           :page_fault, :zet_debug_event_info_page_fault_t
  end
  typedef ZETDebugEventInfo.by_value, :zet_debug_event_info_t

  class ZETDebugEvent < FFI::ZEStruct
    layout :type, :zet_debug_event_type_t,
           :flags, :zet_debug_event_flags_t,
           :info, :zet_debug_event_info_t
  end
  typedef ZETDebugEvent.by_value, :zet_debug_event_t

  class ZETDebugMemorySpaceDesc < FFI::ZEStruct
    layout :stype, :zet_structure_type_t,
           :pNext, :pointer,
           :type, :zet_debug_memory_space_type_t,
           :address, :uint64

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZET_STRUCTURE_TYPE_DEBUG_MEMORY_SPACE_DESC
      end
    end
  end
  typedef ZETDebugMemorySpaceDesc.by_value, :zet_debug_memory_space_desc_t

  class ZETDebugRegsetProperties < FFI::ZEStruct
    layout :stype, :zet_structure_type_t,
           :pNext, :pointer,
           :type, :uint32,
           :version, :uint32,
           :generalFlags, :zet_debug_regset_flags_t,
           :deviceFlags, :uint32,
           :count, :uint32,
           :bitSize, :uint32,
           :byteSize, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZET_STRUCTURE_TYPE_DEBUG_REGSET_PROPERTIES
      end
    end
  end
  typedef ZETDebugRegsetProperties.by_value, :zet_debug_regset_properties_t

  class ZETMetricGroupProperties < FFI::ZEStruct
    layout :stype, :zet_structure_type_t,
           :pNext, :pointer,
           :name, [ :char, ZET_MAX_METRIC_GROUP_NAME ],
           :description, [ :char, ZET_MAX_METRIC_GROUP_DESCRIPTION ],
           :samplingType, :zet_metric_group_sampling_type_flags_t,
           :domain, :uint32,
           :metricCount, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZET_STRUCTURE_TYPE_METRIC_GROUP_PROPERTIES
      end
    end
  end
  typedef ZETMetricGroupProperties.by_value, :zet_metric_group_properties_t

  class ZETMetricProperties < FFI::ZEStruct
    layout :stype, :zet_structure_type_t,
           :pNext, :pointer,
           :name, [ :char, ZET_MAX_METRIC_NAME ],
           :description, [ :char, ZET_MAX_METRIC_DESCRIPTION ],
           :component, [ :char, ZET_MAX_METRIC_COMPONENT ],
           :tierNumber, :uint32,
           :metricType, :zet_metric_type_t,
           :resultType, :zet_value_type_t,
           :resultUnits, [ :char, ZET_MAX_METRIC_RESULT_UNITS ]

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZET_STRUCTURE_TYPE_METRIC_PROPERTIES
      end
    end
  end
  typedef ZETMetricProperties.by_value, :zet_metric_properties_t

  class ZETMetricStreamerDesc < FFI::ZEStruct
    layout :stype, :zet_structure_type_t,
           :pNext, :pointer,
           :notifyEveryNReports, :uint32,
           :samplingPeriod, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZET_STRUCTURE_TYPE_METRIC_STREAMER_DESC
      end
    end
  end
  typedef ZETMetricStreamerDesc.by_value, :zet_metric_streamer_desc_t

  class ZETMetricQueryPoolDesc < FFI::ZEStruct
    layout :stype, :zet_structure_type_t,
           :pNext, :pointer,
           :type, :zet_metric_query_pool_type_t,
           :count, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZET_STRUCTURE_TYPE_METRIC_QUERY_POOL_DESC
      end
    end
  end
  typedef ZETMetricQueryPoolDesc.by_value, :zet_metric_query_pool_desc_t

  class ZETProfileProperties < FFI::ZEStruct
    layout :stype, :zet_structure_type_t,
           :pNext, :pointer,
           :flags, :zet_profile_flags_t,
           :numTokens, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZET_STRUCTURE_TYPE_PROFILE_PROPERTIES
      end
    end
  end
  typedef ZETProfileProperties.by_value, :zet_profile_properties_t

  class ZETProfileFreeRegisterToken < FFI::ZEStruct
    layout :type, :zet_profile_token_type_t,
           :size, :uint32,
           :count, :uint32
  end
  typedef ZETProfileFreeRegisterToken.by_value, :zet_profile_free_register_token_t

  class ZETProfileRegisterSequence < FFI::ZEStruct
    layout :start, :uint32,
           :count, :uint32
  end
  typedef ZETProfileRegisterSequence.by_value, :zet_profile_register_sequence_t

  class ZETTracerExpDesc < FFI::ZEStruct
    layout :stype, :zet_structure_type_t,
           :pNext, :pointer,
           :pUserData, :pointer

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZET_STRUCTURE_TYPE_TRACER_EXP_DESC
      end
    end
  end
  typedef ZETTracerExpDesc.by_value, :zet_tracer_exp_desc_t

  class ZETMetricTracerExpDesc < FFI::ZEStruct
    layout :stype, :zet_structure_type_t,
           :pNext, :pointer,
           :notifyEveryNBytes, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZET_STRUCTURE_TYPE_METRIC_TRACER_EXP_DESC
      end
    end
  end
  typedef ZETMetricTracerExpDesc.by_value, :zet_metric_tracer_exp_desc_t

  class ZETMetricEntryExp < FFI::ZEStruct
    layout :value, :zet_value_t,
           :timeStamp, :uint64,
           :metricIndex, :uint32,
           :onSubdevice, :ze_bool_t,
           :subdeviceId, :uint32
  end
  typedef ZETMetricEntryExp.by_value, :zet_metric_entry_exp_t

  class ZETMetricGroupTypeExp < FFI::ZEStruct
    layout :stype, :zet_structure_type_t,
           :pNext, :pointer,
           :type, :zet_metric_group_type_exp_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZET_STRUCTURE_TYPE_METRIC_GROUP_TYPE_EXP
      end
    end
  end
  typedef ZETMetricGroupTypeExp.by_value, :zet_metric_group_type_exp_t

  class ZETExportDmaBufExpProperties < FFI::ZEStruct
    layout :stype, :zet_structure_type_t,
           :pNext, :pointer,
           :fd, :int,
           :size, :size_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZET_STRUCTURE_TYPE_EXPORT_DMA_EXP_PROPERTIES
      end
    end
  end
  typedef ZETExportDmaBufExpProperties.by_value, :zet_export_dma_buf_exp_properties_t

  class ZETMetricSourceIdExp < FFI::ZEStruct
    layout :stype, :zet_structure_type_t,
           :pNext, :pointer,
           :sourceId, :uint32
  end
  typedef ZETMetricSourceIdExp.by_value, :zet_metric_source_id_exp_t

  class ZETMetricGlobalTimestampsResolutionExp < FFI::ZEStruct
    layout :stype, :zet_structure_type_t,
           :pNext, :pointer,
           :timerResolution, :uint64,
           :timestampValidBits, :uint64

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZET_STRUCTURE_TYPE_METRIC_GLOBAL_TIMESTAMPS_RESOLUTION_EXP
      end
    end
  end
  typedef ZETMetricGlobalTimestampsResolutionExp.by_value, :zet_metric_global_timestamps_resolution_exp_t

  class ZETMetricCalculateExpDesc < FFI::ZEStruct
    layout :stype, :zet_structure_type_t,
           :pNext, :pointer,
           :rawReportSkipCount, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZET_STRUCTURE_TYPE_METRIC_CALCULATE_EXP_DESC
      end
    end
  end
  typedef ZETMetricCalculateExpDesc.by_value, :zet_metric_calculate_exp_desc_t

  class ZETMetricProgrammableExpProperties < FFI::ZEStruct
    layout :stype, :zet_structure_type_t,
           :pNext, :pointer,
           :name, [ :char, ZET_MAX_METRIC_PROGRAMMABLE_NAME_EXP ],
           :description, [ :char, ZET_MAX_METRIC_PROGRAMMABLE_DESCRIPTION_EXP ],
           :component, [ :char, ZET_MAX_METRIC_PROGRAMMABLE_COMPONENT_EXP ],
           :tierNumber, :uint32,
           :domain, :uint32,
           :parameterCount, :uint32,
           :samplingType, :zet_metric_group_sampling_type_flags_t,
           :sourceId, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZET_STRUCTURE_TYPE_METRIC_PROGRAMMABLE_EXP_PROPERTIES
      end
    end
  end
  typedef ZETMetricProgrammableExpProperties.by_value, :zet_metric_programmable_exp_properties_t

  class ZETValueUint64RangeExp < FFI::ZEStruct
    layout :ui64Min, :uint64,
           :ui64Max, :uint64
  end
  typedef ZETValueUint64RangeExp.by_value, :zet_value_uint64_range_exp_t

  class ZETValueFp64RangeExp < FFI::ZEStruct
    layout :fp64Min, :double,
           :fp64Max, :double
  end
  typedef ZETValueFp64RangeExp.by_value, :zet_value_fp64_range_exp_t

  class ZETMetricProgrammableParamInfoExp < FFI::ZEStruct
    layout :stype, :zet_structure_type_t,
           :pNext, :pointer,
           :type, :zet_metric_programmable_param_type_exp_t,
           :name, [ :char, ZET_MAX_METRIC_PROGRAMMABLE_PARAMETER_NAME_EXP ],
           :valueInfoType, :zet_value_info_type_exp_t,
           :defaultValue, :zet_value_t,
           :valueInfoCount, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZET_STRUCTURE_TYPE_METRIC_PROGRAMMABLE_PARAM_INFO_EXP
      end
    end
  end
  typedef ZETMetricProgrammableParamInfoExp.by_value, :zet_metric_programmable_param_info_exp_t

  class ZETValueInfoExp < FFI::ZEUnion
    layout :ui32, :uint32,
           :ui64, :uint64,
           :fp32, :float,
           :fp64, :double,
           :b8, :ze_bool_t,
           :ui8, :uint8,
           :ui16, :uint16,
           :ui64Range, :zet_value_uint64_range_exp_t,
           :fp64Range, :zet_value_fp64_range_exp_t
  end
  typedef ZETValueInfoExp.by_value, :zet_value_info_exp_t

  class ZETMetricProgrammableParamValueInfoExp < FFI::ZEStruct
    layout :stype, :zet_structure_type_t,
           :pNext, :pointer,
           :valueInfo, :zet_value_info_exp_t,
           :description, [ :char, ZET_MAX_METRIC_PROGRAMMABLE_VALUE_DESCRIPTION_EXP ]

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZET_STRUCTURE_TYPE_METRIC_PROGRAMMABLE_PARAM_VALUE_INFO_EXP
      end
    end
  end
  typedef ZETMetricProgrammableParamValueInfoExp.by_value, :zet_metric_programmable_param_value_info_exp_t

  class ZETMetricProgrammableParamValueExp < FFI::ZEStruct
    layout :value, :zet_value_t
  end
  typedef ZETMetricProgrammableParamValueExp.by_value, :zet_metric_programmable_param_value_exp_t

  callback :zet_pfnMetricProgrammableGetExp_t,
           [ :zet_device_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :zet_pfnMetricProgrammableGetPropertiesExp_t,
           [ :zet_metric_programmable_exp_handle_t,
             ZETMetricProgrammableExpProperties.ptr ],
           :ze_result_t

  callback :zet_pfnMetricProgrammableGetParamInfoExp_t,
           [ :zet_metric_programmable_exp_handle_t,
             :pointer,
             ZETMetricProgrammableParamInfoExp.ptr ],
           :ze_result_t

  callback :zet_pfnMetricProgrammableGetParamValueInfoExp_t,
           [ :zet_metric_programmable_exp_handle_t,
             :uint32,
             :pointer,
             ZETMetricProgrammableParamValueInfoExp.ptr ],
           :ze_result_t

  class ZETMetricProgrammableExpDDITable < FFI::ZEStruct
    layout :pfnGetExp, :zet_pfnMetricProgrammableGetExp_t,
           :pfnGetPropertiesExp, :zet_pfnMetricProgrammableGetPropertiesExp_t,
           :pfnGetParamInfoExp, :zet_pfnMetricProgrammableGetParamInfoExp_t,
           :pfnGetParamValueInfoExp, :zet_pfnMetricProgrammableGetParamValueInfoExp_t
  end
  typedef ZETMetricProgrammableExpDDITable.by_value, :zet_metric_programmable_exp_dditable_t

  callback :zet_pfnGetMetricProgrammableExpProcAddrTable_t,
           [ :ze_api_version_t,
             ZETMetricProgrammableExpDDITable.ptr ],
           :ze_result_t

  callback :zet_pfnMetricTracerCreateExp_t,
           [ :zet_context_handle_t,
             :zet_device_handle_t,
             :uint32,
             :pointer,
             ZETMetricTracerExpDesc.ptr,
             :ze_event_handle_t,
             :pointer ],
           :ze_result_t

  callback :zet_pfnMetricTracerDestroyExp_t,
           [ :zet_metric_tracer_exp_handle_t ],
           :ze_result_t

  callback :zet_pfnMetricTracerEnableExp_t,
           [ :zet_metric_tracer_exp_handle_t,
             :ze_bool_t ],
           :ze_result_t

  callback :zet_pfnMetricTracerDisableExp_t,
           [ :zet_metric_tracer_exp_handle_t,
             :ze_bool_t ],
           :ze_result_t

  callback :zet_pfnMetricTracerReadDataExp_t,
           [ :zet_metric_tracer_exp_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :zet_pfnMetricTracerDecodeExp_t,
           [ :zet_metric_decoder_exp_handle_t,
             :pointer,
             :pointer,
             :uint32,
             :pointer,
             :pointer,
             :pointer,
             :pointer,
             ZETMetricEntryExp.ptr ],
           :ze_result_t

  class ZETMetricTracerExpDDITable < FFI::ZEStruct
    layout :pfnCreateExp, :zet_pfnMetricTracerCreateExp_t,
           :pfnDestroyExp, :zet_pfnMetricTracerDestroyExp_t,
           :pfnEnableExp, :zet_pfnMetricTracerEnableExp_t,
           :pfnDisableExp, :zet_pfnMetricTracerDisableExp_t,
           :pfnReadDataExp, :zet_pfnMetricTracerReadDataExp_t,
           :pfnDecodeExp, :zet_pfnMetricTracerDecodeExp_t
  end
  typedef ZETMetricTracerExpDDITable.by_value, :zet_metric_tracer_exp_dditable_t

  callback :zet_pfnGetMetricTracerExpProcAddrTable_t,
           [ :ze_api_version_t,
             ZETMetricTracerExpDDITable.ptr ],
           :ze_result_t

  callback :zet_pfnMetricDecoderCreateExp_t,
           [ :zet_metric_tracer_exp_handle_t,
             :pointer ],
           :ze_result_t

  callback :zet_pfnMetricDecoderDestroyExp_t,
           [ :zet_metric_decoder_exp_handle_t ],
           :ze_result_t

  callback :zet_pfnMetricDecoderGetDecodableMetricsExp_t,
           [ :zet_metric_decoder_exp_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  class ZETMetricDecoderExpDDITable < FFI::ZEStruct
    layout :pfnCreateExp, :zet_pfnMetricDecoderCreateExp_t,
           :pfnDestroyExp, :zet_pfnMetricDecoderDestroyExp_t,
           :pfnGetDecodableMetricsExp, :zet_pfnMetricDecoderGetDecodableMetricsExp_t
  end
  typedef ZETMetricDecoderExpDDITable.by_value, :zet_metric_decoder_exp_dditable_t

  callback :zet_pfnGetMetricDecoderExpProcAddrTable_t,
           [ :ze_api_version_t,
             ZETMetricDecoderExpDDITable.ptr ],
           :ze_result_t

  callback :zet_pfnDeviceGetDebugProperties_t,
           [ :zet_device_handle_t,
             ZETDeviceDebugProperties.ptr ],
           :ze_result_t

  class ZETDeviceDDITable < FFI::ZEStruct
    layout :pfnGetDebugProperties, :zet_pfnDeviceGetDebugProperties_t
  end
  typedef ZETDeviceDDITable.by_value, :zet_device_dditable_t

  callback :zet_pfnGetDeviceProcAddrTable_t,
           [ :ze_api_version_t,
             ZETDeviceDDITable.ptr ],
           :ze_result_t

  callback :zet_pfnDeviceGetConcurrentMetricGroupsExp_t,
           [ :zet_device_handle_t,
             :uint32,
             :pointer,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :zet_pfnDeviceCreateMetricGroupsFromMetricsExp_t,
           [ :zet_device_handle_t,
             :uint32,
             :pointer,
             :pointer,
             :pointer,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :zet_pfnDeviceEnableMetricsExp_t,
           [ :zet_device_handle_t ],
           :ze_result_t

  callback :zet_pfnDeviceDisableMetricsExp_t,
           [ :zet_device_handle_t ],
           :ze_result_t

  class ZETDeviceExpDDITable < FFI::ZEStruct
    layout :pfnGetConcurrentMetricGroupsExp, :zet_pfnDeviceGetConcurrentMetricGroupsExp_t,
           :pfnCreateMetricGroupsFromMetricsExp, :zet_pfnDeviceCreateMetricGroupsFromMetricsExp_t,
           :pfnEnableMetricsExp, :zet_pfnDeviceEnableMetricsExp_t,
           :pfnDisableMetricsExp, :zet_pfnDeviceDisableMetricsExp_t
  end
  typedef ZETDeviceExpDDITable.by_value, :zet_device_exp_dditable_t

  callback :zet_pfnGetDeviceExpProcAddrTable_t,
           [ :ze_api_version_t,
             ZETDeviceExpDDITable.ptr ],
           :ze_result_t

  callback :zet_pfnContextActivateMetricGroups_t,
           [ :zet_context_handle_t,
             :zet_device_handle_t,
             :uint32,
             :pointer ],
           :ze_result_t

  class ZETContextDDITable < FFI::ZEStruct
    layout :pfnActivateMetricGroups, :zet_pfnContextActivateMetricGroups_t
  end
  typedef ZETContextDDITable.by_value, :zet_context_dditable_t

  callback :zet_pfnGetContextProcAddrTable_t,
           [ :ze_api_version_t,
             ZETContextDDITable.ptr ],
           :ze_result_t

  callback :zet_pfnCommandListAppendMetricStreamerMarker_t,
           [ :zet_command_list_handle_t,
             :zet_metric_streamer_handle_t,
             :uint32 ],
           :ze_result_t

  callback :zet_pfnCommandListAppendMetricQueryBegin_t,
           [ :zet_command_list_handle_t,
             :zet_metric_query_handle_t ],
           :ze_result_t

  callback :zet_pfnCommandListAppendMetricQueryEnd_t,
           [ :zet_command_list_handle_t,
             :zet_metric_query_handle_t,
             :ze_event_handle_t,
             :uint32,
             :pointer ],
           :ze_result_t

  callback :zet_pfnCommandListAppendMetricMemoryBarrier_t,
           [ :zet_command_list_handle_t ],
           :ze_result_t

  class ZETCommandListDDITable < FFI::ZEStruct
    layout :pfnAppendMetricStreamerMarker, :zet_pfnCommandListAppendMetricStreamerMarker_t,
           :pfnAppendMetricQueryBegin, :zet_pfnCommandListAppendMetricQueryBegin_t,
           :pfnAppendMetricQueryEnd, :zet_pfnCommandListAppendMetricQueryEnd_t,
           :pfnAppendMetricMemoryBarrier, :zet_pfnCommandListAppendMetricMemoryBarrier_t
  end
  typedef ZETCommandListDDITable.by_value, :zet_command_list_dditable_t

  callback :zet_pfnGetCommandListProcAddrTable_t,
           [ :ze_api_version_t,
             ZETCommandListDDITable.ptr ],
           :ze_result_t

  callback :zet_pfnCommandListAppendMarkerExp_t,
           [ :zet_command_list_handle_t,
             :zet_metric_group_handle_t,
             :uint32 ],
           :ze_result_t

  class ZETCommandListExpDDITable < FFI::ZEStruct
    layout :pfnAppendMarkerExp, :zet_pfnCommandListAppendMarkerExp_t
  end
  typedef ZETCommandListExpDDITable.by_value, :zet_command_list_exp_dditable_t

  callback :zet_pfnGetCommandListExpProcAddrTable_t,
           [ :ze_api_version_t,
             ZETCommandListExpDDITable.ptr ],
           :ze_result_t

  callback :zet_pfnModuleGetDebugInfo_t,
           [ :zet_module_handle_t,
             :zet_module_debug_info_format_t,
             :pointer,
             :pointer ],
           :ze_result_t

  class ZETModuleDDITable < FFI::ZEStruct
    layout :pfnGetDebugInfo, :zet_pfnModuleGetDebugInfo_t
  end
  typedef ZETModuleDDITable.by_value, :zet_module_dditable_t

  callback :zet_pfnGetModuleProcAddrTable_t,
           [ :ze_api_version_t,
             ZETModuleDDITable.ptr ],
           :ze_result_t

  callback :zet_pfnKernelGetProfileInfo_t,
           [ :zet_kernel_handle_t,
             ZETProfileProperties.ptr ],
           :ze_result_t

  class ZETKernelDDITable < FFI::ZEStruct
    layout :pfnGetProfileInfo, :zet_pfnKernelGetProfileInfo_t
  end
  typedef ZETKernelDDITable.by_value, :zet_kernel_dditable_t

  callback :zet_pfnGetKernelProcAddrTable_t,
           [ :ze_api_version_t,
             ZETKernelDDITable.ptr ],
           :ze_result_t

  callback :zet_pfnMetricGet_t,
           [ :zet_metric_group_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :zet_pfnMetricGetProperties_t,
           [ :zet_metric_handle_t,
             ZETMetricProperties.ptr ],
           :ze_result_t

  class ZETMetricDDITable < FFI::ZEStruct
    layout :pfnGet, :zet_pfnMetricGet_t,
           :pfnGetProperties, :zet_pfnMetricGetProperties_t
  end
  typedef ZETMetricDDITable.by_value, :zet_metric_dditable_t

  callback :zet_pfnGetMetricProcAddrTable_t,
           [ :ze_api_version_t,
             ZETMetricDDITable.ptr ],
           :ze_result_t

  callback :zet_pfnMetricCreateFromProgrammableExp_t,
           [ :zet_metric_programmable_exp_handle_t,
             ZETMetricProgrammableParamValueExp.ptr,
             :uint32,
             :pointer,
             :pointer,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :zet_pfnMetricDestroyExp_t,
           [ :zet_metric_handle_t ],
           :ze_result_t

  callback :zet_pfnMetricCreateFromProgrammableExp2_t,
           [ :zet_metric_programmable_exp_handle_t,
             :uint32,
             ZETMetricProgrammableParamValueExp.ptr,
             :pointer,
             :pointer,
             :pointer,
             :pointer ],
           :ze_result_t

  class ZETMetricExpDDITable < FFI::ZEStruct
    layout :pfnCreateFromProgrammableExp, :zet_pfnMetricCreateFromProgrammableExp_t,
           :pfnDestroyExp, :zet_pfnMetricDestroyExp_t,
           :pfnCreateFromProgrammableExp2, :zet_pfnMetricCreateFromProgrammableExp2_t
  end
  typedef ZETMetricExpDDITable.by_value, :zet_metric_exp_dditable_t

  callback :zet_pfnGetMetricExpProcAddrTable_t,
           [ :ze_api_version_t,
             ZETMetricExpDDITable.ptr ],
           :ze_result_t

  callback :zet_pfnMetricGroupGet_t,
           [ :zet_device_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :zet_pfnMetricGroupGetProperties_t,
           [ :zet_metric_group_handle_t,
             ZETMetricGroupProperties.ptr ],
           :ze_result_t

  callback :zet_pfnMetricGroupCalculateMetricValues_t,
           [ :zet_metric_group_handle_t,
             :zet_metric_group_calculation_type_t,
             :size_t,
             :pointer,
             :pointer,
             ZETTypedValue.ptr ],
           :ze_result_t

  class ZETMetricGroupDDITable < FFI::ZEStruct
    layout :pfnGet, :zet_pfnMetricGroupGet_t,
           :pfnGetProperties, :zet_pfnMetricGroupGetProperties_t,
           :pfnCalculateMetricValues, :zet_pfnMetricGroupCalculateMetricValues_t
  end
  typedef ZETMetricGroupDDITable.by_value, :zet_metric_group_dditable_t

  callback :zet_pfnGetMetricGroupProcAddrTable_t,
           [ :ze_api_version_t,
             ZETMetricGroupDDITable.ptr ],
           :ze_result_t

  callback :zet_pfnMetricGroupCalculateMultipleMetricValuesExp_t,
           [ :zet_metric_group_handle_t,
             :zet_metric_group_calculation_type_t,
             :size_t,
             :pointer,
             :pointer,
             :pointer,
             :pointer,
             ZETTypedValue.ptr ],
           :ze_result_t

  callback :zet_pfnMetricGroupGetGlobalTimestampsExp_t,
           [ :zet_metric_group_handle_t,
             :ze_bool_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :zet_pfnMetricGroupGetExportDataExp_t,
           [ :zet_metric_group_handle_t,
             :pointer,
             :size_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :zet_pfnMetricGroupCalculateMetricExportDataExp_t,
           [ :ze_driver_handle_t,
             :zet_metric_group_calculation_type_t,
             :size_t,
             :pointer,
             ZETMetricCalculateExpDesc.ptr,
             :pointer,
             :pointer,
             :pointer,
             ZETTypedValue.ptr ],
           :ze_result_t

  callback :zet_pfnMetricGroupCreateExp_t,
           [ :zet_device_handle_t,
             :pointer,
             :pointer,
             :zet_metric_group_sampling_type_flags_t,
             :pointer ],
           :ze_result_t

  callback :zet_pfnMetricGroupAddMetricExp_t,
           [ :zet_metric_group_handle_t,
             :zet_metric_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :zet_pfnMetricGroupRemoveMetricExp_t,
           [ :zet_metric_group_handle_t,
             :zet_metric_handle_t ],
           :ze_result_t

  callback :zet_pfnMetricGroupCloseExp_t,
           [ :zet_metric_group_handle_t ],
           :ze_result_t

  callback :zet_pfnMetricGroupDestroyExp_t,
           [ :zet_metric_group_handle_t ],
           :ze_result_t

  class ZETMetricGroupExpDDITable < FFI::ZEStruct
    layout :pfnCalculateMultipleMetricValuesExp, :zet_pfnMetricGroupCalculateMultipleMetricValuesExp_t,
           :pfnGetGlobalTimestampsExp, :zet_pfnMetricGroupGetGlobalTimestampsExp_t,
           :pfnGetExportDataExp, :zet_pfnMetricGroupGetExportDataExp_t,
           :pfnCalculateMetricExportDataExp, :zet_pfnMetricGroupCalculateMetricExportDataExp_t,
           :pfnCreateExp, :zet_pfnMetricGroupCreateExp_t,
           :pfnAddMetricExp, :zet_pfnMetricGroupAddMetricExp_t,
           :pfnRemoveMetricExp, :zet_pfnMetricGroupRemoveMetricExp_t,
           :pfnCloseExp, :zet_pfnMetricGroupCloseExp_t,
           :pfnDestroyExp, :zet_pfnMetricGroupDestroyExp_t
  end
  typedef ZETMetricGroupExpDDITable.by_value, :zet_metric_group_exp_dditable_t

  callback :zet_pfnGetMetricGroupExpProcAddrTable_t,
           [ :ze_api_version_t,
             ZETMetricGroupExpDDITable.ptr ],
           :ze_result_t

  callback :zet_pfnMetricStreamerOpen_t,
           [ :zet_context_handle_t,
             :zet_device_handle_t,
             :zet_metric_group_handle_t,
             ZETMetricStreamerDesc.ptr,
             :ze_event_handle_t,
             :pointer ],
           :ze_result_t

  callback :zet_pfnMetricStreamerClose_t,
           [ :zet_metric_streamer_handle_t ],
           :ze_result_t

  callback :zet_pfnMetricStreamerReadData_t,
           [ :zet_metric_streamer_handle_t,
             :uint32,
             :pointer,
             :pointer ],
           :ze_result_t

  class ZETMetricStreamerDDITable < FFI::ZEStruct
    layout :pfnOpen, :zet_pfnMetricStreamerOpen_t,
           :pfnClose, :zet_pfnMetricStreamerClose_t,
           :pfnReadData, :zet_pfnMetricStreamerReadData_t
  end
  typedef ZETMetricStreamerDDITable.by_value, :zet_metric_streamer_dditable_t

  callback :zet_pfnGetMetricStreamerProcAddrTable_t,
           [ :ze_api_version_t,
             ZETMetricStreamerDDITable.ptr ],
           :ze_result_t

  callback :zet_pfnMetricQueryPoolCreate_t,
           [ :zet_context_handle_t,
             :zet_device_handle_t,
             :zet_metric_group_handle_t,
             ZETMetricQueryPoolDesc.ptr,
             :pointer ],
           :ze_result_t

  callback :zet_pfnMetricQueryPoolDestroy_t,
           [ :zet_metric_query_pool_handle_t ],
           :ze_result_t

  class ZETMetricQueryPoolDDITable < FFI::ZEStruct
    layout :pfnCreate, :zet_pfnMetricQueryPoolCreate_t,
           :pfnDestroy, :zet_pfnMetricQueryPoolDestroy_t
  end
  typedef ZETMetricQueryPoolDDITable.by_value, :zet_metric_query_pool_dditable_t

  callback :zet_pfnGetMetricQueryPoolProcAddrTable_t,
           [ :ze_api_version_t,
             ZETMetricQueryPoolDDITable.ptr ],
           :ze_result_t

  callback :zet_pfnMetricQueryCreate_t,
           [ :zet_metric_query_pool_handle_t,
             :uint32,
             :pointer ],
           :ze_result_t

  callback :zet_pfnMetricQueryDestroy_t,
           [ :zet_metric_query_handle_t ],
           :ze_result_t

  callback :zet_pfnMetricQueryReset_t,
           [ :zet_metric_query_handle_t ],
           :ze_result_t

  callback :zet_pfnMetricQueryGetData_t,
           [ :zet_metric_query_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  class ZETMetricQueryDDITable < FFI::ZEStruct
    layout :pfnCreate, :zet_pfnMetricQueryCreate_t,
           :pfnDestroy, :zet_pfnMetricQueryDestroy_t,
           :pfnReset, :zet_pfnMetricQueryReset_t,
           :pfnGetData, :zet_pfnMetricQueryGetData_t
  end
  typedef ZETMetricQueryDDITable.by_value, :zet_metric_query_dditable_t

  callback :zet_pfnGetMetricQueryProcAddrTable_t,
           [ :ze_api_version_t,
             ZETMetricQueryDDITable.ptr ],
           :ze_result_t

  callback :zet_pfnTracerExpCreate_t,
           [ :zet_context_handle_t,
             ZETTracerExpDesc.ptr,
             :pointer ],
           :ze_result_t

  callback :zet_pfnTracerExpDestroy_t,
           [ :zet_tracer_exp_handle_t ],
           :ze_result_t

  callback :zet_pfnTracerExpSetPrologues_t,
           [ :zet_tracer_exp_handle_t,
             :pointer ],
           :ze_result_t

  callback :zet_pfnTracerExpSetEpilogues_t,
           [ :zet_tracer_exp_handle_t,
             :pointer ],
           :ze_result_t

  callback :zet_pfnTracerExpSetEnabled_t,
           [ :zet_tracer_exp_handle_t,
             :ze_bool_t ],
           :ze_result_t

  class ZETTracerExpDDITable < FFI::ZEStruct
    layout :pfnCreate, :zet_pfnTracerExpCreate_t,
           :pfnDestroy, :zet_pfnTracerExpDestroy_t,
           :pfnSetPrologues, :zet_pfnTracerExpSetPrologues_t,
           :pfnSetEpilogues, :zet_pfnTracerExpSetEpilogues_t,
           :pfnSetEnabled, :zet_pfnTracerExpSetEnabled_t
  end
  typedef ZETTracerExpDDITable.by_value, :zet_tracer_exp_dditable_t

  callback :zet_pfnGetTracerExpProcAddrTable_t,
           [ :ze_api_version_t,
             ZETTracerExpDDITable.ptr ],
           :ze_result_t

  callback :zet_pfnDebugAttach_t,
           [ :zet_device_handle_t,
             ZETDebugConfig.ptr,
             :pointer ],
           :ze_result_t

  callback :zet_pfnDebugDetach_t,
           [ :zet_debug_session_handle_t ],
           :ze_result_t

  callback :zet_pfnDebugReadEvent_t,
           [ :zet_debug_session_handle_t,
             :uint64,
             ZETDebugEvent.ptr ],
           :ze_result_t

  callback :zet_pfnDebugAcknowledgeEvent_t,
           [ :zet_debug_session_handle_t,
             ZETDebugEvent.ptr ],
           :ze_result_t

  callback :zet_pfnDebugInterrupt_t,
           [ :zet_debug_session_handle_t,
             :ze_device_thread_t ],
           :ze_result_t

  callback :zet_pfnDebugResume_t,
           [ :zet_debug_session_handle_t,
             :ze_device_thread_t ],
           :ze_result_t

  callback :zet_pfnDebugReadMemory_t,
           [ :zet_debug_session_handle_t,
             :ze_device_thread_t,
             ZETDebugMemorySpaceDesc.ptr,
             :size_t,
             :pointer ],
           :ze_result_t

  callback :zet_pfnDebugWriteMemory_t,
           [ :zet_debug_session_handle_t,
             :ze_device_thread_t,
             ZETDebugMemorySpaceDesc.ptr,
             :size_t,
             :pointer ],
           :ze_result_t

  callback :zet_pfnDebugGetRegisterSetProperties_t,
           [ :zet_device_handle_t,
             :pointer,
             ZETDebugRegsetProperties.ptr ],
           :ze_result_t

  callback :zet_pfnDebugReadRegisters_t,
           [ :zet_debug_session_handle_t,
             :ze_device_thread_t,
             :uint32,
             :uint32,
             :uint32,
             :pointer ],
           :ze_result_t

  callback :zet_pfnDebugWriteRegisters_t,
           [ :zet_debug_session_handle_t,
             :ze_device_thread_t,
             :uint32,
             :uint32,
             :uint32,
             :pointer ],
           :ze_result_t

  callback :zet_pfnDebugGetThreadRegisterSetProperties_t,
           [ :zet_debug_session_handle_t,
             :ze_device_thread_t,
             :pointer,
             ZETDebugRegsetProperties.ptr ],
           :ze_result_t

  class ZETDebugDDITable < FFI::ZEStruct
    layout :pfnAttach, :zet_pfnDebugAttach_t,
           :pfnDetach, :zet_pfnDebugDetach_t,
           :pfnReadEvent, :zet_pfnDebugReadEvent_t,
           :pfnAcknowledgeEvent, :zet_pfnDebugAcknowledgeEvent_t,
           :pfnInterrupt, :zet_pfnDebugInterrupt_t,
           :pfnResume, :zet_pfnDebugResume_t,
           :pfnReadMemory, :zet_pfnDebugReadMemory_t,
           :pfnWriteMemory, :zet_pfnDebugWriteMemory_t,
           :pfnGetRegisterSetProperties, :zet_pfnDebugGetRegisterSetProperties_t,
           :pfnReadRegisters, :zet_pfnDebugReadRegisters_t,
           :pfnWriteRegisters, :zet_pfnDebugWriteRegisters_t,
           :pfnGetThreadRegisterSetProperties, :zet_pfnDebugGetThreadRegisterSetProperties_t
  end
  typedef ZETDebugDDITable.by_value, :zet_debug_dditable_t

  callback :zet_pfnGetDebugProcAddrTable_t,
           [ :ze_api_version_t,
             ZETDebugDDITable.ptr ],
           :ze_result_t

  class ZETDDITable < FFI::ZEStruct
    layout :MetricProgrammableExp, :zet_metric_programmable_exp_dditable_t,
           :MetricTracerExp, :zet_metric_tracer_exp_dditable_t,
           :MetricDecoderExp, :zet_metric_decoder_exp_dditable_t,
           :Device, :zet_device_dditable_t,
           :DeviceExp, :zet_device_exp_dditable_t,
           :Context, :zet_context_dditable_t,
           :CommandList, :zet_command_list_dditable_t,
           :CommandListExp, :zet_command_list_exp_dditable_t,
           :Module, :zet_module_dditable_t,
           :Kernel, :zet_kernel_dditable_t,
           :Metric, :zet_metric_dditable_t,
           :MetricExp, :zet_metric_exp_dditable_t,
           :MetricGroup, :zet_metric_group_dditable_t,
           :MetricGroupExp, :zet_metric_group_exp_dditable_t,
           :MetricStreamer, :zet_metric_streamer_dditable_t,
           :MetricQueryPool, :zet_metric_query_pool_dditable_t,
           :MetricQuery, :zet_metric_query_dditable_t,
           :TracerExp, :zet_tracer_exp_dditable_t,
           :Debug, :zet_debug_dditable_t
  end
  typedef ZETDDITable.by_value, :zet_dditable_t

  class ZETDDITableDriver < FFI::ZEStruct
    layout :version, :ze_api_version_t,
           :isValidFlag, :uint8,
           :MetricProgrammableExp, :pointer,
           :MetricTracerExp, :pointer,
           :MetricDecoderExp, :pointer,
           :Device, :pointer,
           :DeviceExp, :pointer,
           :Context, :pointer,
           :CommandList, :pointer,
           :CommandListExp, :pointer,
           :Module, :pointer,
           :Kernel, :pointer,
           :Metric, :pointer,
           :MetricExp, :pointer,
           :MetricGroup, :pointer,
           :MetricGroupExp, :pointer,
           :MetricStreamer, :pointer,
           :MetricQueryPool, :pointer,
           :MetricQuery, :pointer,
           :TracerExp, :pointer,
           :Debug, :pointer
  end
  typedef ZETDDITableDriver.by_value, :zet_dditable_driver_t

  class ZETMetricProgrammableExpDDITableT19 < FFI::ZEStruct
    layout :pfnGetExp, :zet_pfnMetricProgrammableGetExp_t,
           :pfnGetPropertiesExp, :zet_pfnMetricProgrammableGetPropertiesExp_t,
           :pfnGetParamInfoExp, :zet_pfnMetricProgrammableGetParamInfoExp_t,
           :pfnGetParamValueInfoExp, :zet_pfnMetricProgrammableGetParamValueInfoExp_t
  end
  typedef ZETMetricProgrammableExpDDITableT19.by_value, :zet_metric_programmable_exp_dditable_t_1_9

  class ZETMetricTracerExpDDITableT11 < FFI::ZEStruct
    layout :pfnCreateExp, :zet_pfnMetricTracerCreateExp_t,
           :pfnDestroyExp, :zet_pfnMetricTracerDestroyExp_t,
           :pfnEnableExp, :zet_pfnMetricTracerEnableExp_t,
           :pfnDisableExp, :zet_pfnMetricTracerDisableExp_t,
           :pfnReadDataExp, :zet_pfnMetricTracerReadDataExp_t,
           :pfnDecodeExp, :zet_pfnMetricTracerDecodeExp_t
  end
  typedef ZETMetricTracerExpDDITableT11.by_value, :zet_metric_tracer_exp_dditable_t_1_1

  class ZETMetricDecoderExpDDITableT11 < FFI::ZEStruct
    layout :pfnCreateExp, :zet_pfnMetricDecoderCreateExp_t,
           :pfnDestroyExp, :zet_pfnMetricDecoderDestroyExp_t,
           :pfnGetDecodableMetricsExp, :zet_pfnMetricDecoderGetDecodableMetricsExp_t
  end
  typedef ZETMetricDecoderExpDDITableT11.by_value, :zet_metric_decoder_exp_dditable_t_1_1

  class ZETDeviceDDITableT10 < FFI::ZEStruct
    layout :pfnGetDebugProperties, :zet_pfnDeviceGetDebugProperties_t
  end
  typedef ZETDeviceDDITableT10.by_value, :zet_device_dditable_t_1_0

  class ZETDeviceExpDDITableT11 < FFI::ZEStruct
    layout :pfnGetConcurrentMetricGroupsExp, :zet_pfnDeviceGetConcurrentMetricGroupsExp_t,
           :pfnCreateMetricGroupsFromMetricsExp, :zet_pfnDeviceCreateMetricGroupsFromMetricsExp_t
  end
  typedef ZETDeviceExpDDITableT11.by_value, :zet_device_exp_dditable_t_1_1

  class ZETDeviceExpDDITableT113 < FFI::ZEStruct
    layout :pfnGetConcurrentMetricGroupsExp, :zet_pfnDeviceGetConcurrentMetricGroupsExp_t,
           :pfnCreateMetricGroupsFromMetricsExp, :zet_pfnDeviceCreateMetricGroupsFromMetricsExp_t,
           :pfnEnableMetricsExp, :zet_pfnDeviceEnableMetricsExp_t,
           :pfnDisableMetricsExp, :zet_pfnDeviceDisableMetricsExp_t
  end
  typedef ZETDeviceExpDDITableT113.by_value, :zet_device_exp_dditable_t_1_13

  class ZETContextDDITableT10 < FFI::ZEStruct
    layout :pfnActivateMetricGroups, :zet_pfnContextActivateMetricGroups_t
  end
  typedef ZETContextDDITableT10.by_value, :zet_context_dditable_t_1_0

  class ZETCommandListDDITableT10 < FFI::ZEStruct
    layout :pfnAppendMetricStreamerMarker, :zet_pfnCommandListAppendMetricStreamerMarker_t,
           :pfnAppendMetricQueryBegin, :zet_pfnCommandListAppendMetricQueryBegin_t,
           :pfnAppendMetricQueryEnd, :zet_pfnCommandListAppendMetricQueryEnd_t,
           :pfnAppendMetricMemoryBarrier, :zet_pfnCommandListAppendMetricMemoryBarrier_t
  end
  typedef ZETCommandListDDITableT10.by_value, :zet_command_list_dditable_t_1_0

  class ZETCommandListExpDDITableT113 < FFI::ZEStruct
    layout :pfnAppendMarkerExp, :zet_pfnCommandListAppendMarkerExp_t
  end
  typedef ZETCommandListExpDDITableT113.by_value, :zet_command_list_exp_dditable_t_1_13

  class ZETModuleDDITableT10 < FFI::ZEStruct
    layout :pfnGetDebugInfo, :zet_pfnModuleGetDebugInfo_t
  end
  typedef ZETModuleDDITableT10.by_value, :zet_module_dditable_t_1_0

  class ZETKernelDDITableT10 < FFI::ZEStruct
    layout :pfnGetProfileInfo, :zet_pfnKernelGetProfileInfo_t
  end
  typedef ZETKernelDDITableT10.by_value, :zet_kernel_dditable_t_1_0

  class ZETMetricDDITableT10 < FFI::ZEStruct
    layout :pfnGet, :zet_pfnMetricGet_t,
           :pfnGetProperties, :zet_pfnMetricGetProperties_t
  end
  typedef ZETMetricDDITableT10.by_value, :zet_metric_dditable_t_1_0

  class ZETMetricExpDDITableT111 < FFI::ZEStruct
    layout :pfnCreateFromProgrammableExp2, :zet_pfnMetricCreateFromProgrammableExp2_t
  end
  typedef ZETMetricExpDDITableT111.by_value, :zet_metric_exp_dditable_t_1_11

  class ZETMetricExpDDITableT19 < FFI::ZEStruct
    layout :pfnCreateFromProgrammableExp, :zet_pfnMetricCreateFromProgrammableExp_t,
           :pfnDestroyExp, :zet_pfnMetricDestroyExp_t,
           :pfnCreateFromProgrammableExp2, :zet_pfnMetricCreateFromProgrammableExp2_t
  end
  typedef ZETMetricExpDDITableT19.by_value, :zet_metric_exp_dditable_t_1_9

  class ZETMetricGroupDDITableT10 < FFI::ZEStruct
    layout :pfnGet, :zet_pfnMetricGroupGet_t,
           :pfnGetProperties, :zet_pfnMetricGroupGetProperties_t,
           :pfnCalculateMetricValues, :zet_pfnMetricGroupCalculateMetricValues_t
  end
  typedef ZETMetricGroupDDITableT10.by_value, :zet_metric_group_dditable_t_1_0

  class ZETMetricGroupExpDDITableT12 < FFI::ZEStruct
    layout :pfnCalculateMultipleMetricValuesExp, :zet_pfnMetricGroupCalculateMultipleMetricValuesExp_t
  end
  typedef ZETMetricGroupExpDDITableT12.by_value, :zet_metric_group_exp_dditable_t_1_2

  class ZETMetricGroupExpDDITableT15 < FFI::ZEStruct
    layout :pfnCalculateMultipleMetricValuesExp, :zet_pfnMetricGroupCalculateMultipleMetricValuesExp_t,
           :pfnGetGlobalTimestampsExp, :zet_pfnMetricGroupGetGlobalTimestampsExp_t
  end
  typedef ZETMetricGroupExpDDITableT15.by_value, :zet_metric_group_exp_dditable_t_1_5

  class ZETMetricGroupExpDDITableT16 < FFI::ZEStruct
    layout :pfnCalculateMultipleMetricValuesExp, :zet_pfnMetricGroupCalculateMultipleMetricValuesExp_t,
           :pfnGetGlobalTimestampsExp, :zet_pfnMetricGroupGetGlobalTimestampsExp_t,
           :pfnGetExportDataExp, :zet_pfnMetricGroupGetExportDataExp_t,
           :pfnCalculateMetricExportDataExp, :zet_pfnMetricGroupCalculateMetricExportDataExp_t
  end
  typedef ZETMetricGroupExpDDITableT16.by_value, :zet_metric_group_exp_dditable_t_1_6

  class ZETMetricGroupExpDDITableT19 < FFI::ZEStruct
    layout :pfnCalculateMultipleMetricValuesExp, :zet_pfnMetricGroupCalculateMultipleMetricValuesExp_t,
           :pfnGetGlobalTimestampsExp, :zet_pfnMetricGroupGetGlobalTimestampsExp_t,
           :pfnGetExportDataExp, :zet_pfnMetricGroupGetExportDataExp_t,
           :pfnCalculateMetricExportDataExp, :zet_pfnMetricGroupCalculateMetricExportDataExp_t,
           :pfnCreateExp, :zet_pfnMetricGroupCreateExp_t,
           :pfnAddMetricExp, :zet_pfnMetricGroupAddMetricExp_t,
           :pfnRemoveMetricExp, :zet_pfnMetricGroupRemoveMetricExp_t,
           :pfnCloseExp, :zet_pfnMetricGroupCloseExp_t,
           :pfnDestroyExp, :zet_pfnMetricGroupDestroyExp_t
  end
  typedef ZETMetricGroupExpDDITableT19.by_value, :zet_metric_group_exp_dditable_t_1_9

  class ZETMetricStreamerDDITableT10 < FFI::ZEStruct
    layout :pfnOpen, :zet_pfnMetricStreamerOpen_t,
           :pfnClose, :zet_pfnMetricStreamerClose_t,
           :pfnReadData, :zet_pfnMetricStreamerReadData_t
  end
  typedef ZETMetricStreamerDDITableT10.by_value, :zet_metric_streamer_dditable_t_1_0

  class ZETMetricQueryPoolDDITableT10 < FFI::ZEStruct
    layout :pfnCreate, :zet_pfnMetricQueryPoolCreate_t,
           :pfnDestroy, :zet_pfnMetricQueryPoolDestroy_t
  end
  typedef ZETMetricQueryPoolDDITableT10.by_value, :zet_metric_query_pool_dditable_t_1_0

  class ZETMetricQueryDDITableT10 < FFI::ZEStruct
    layout :pfnCreate, :zet_pfnMetricQueryCreate_t,
           :pfnDestroy, :zet_pfnMetricQueryDestroy_t,
           :pfnReset, :zet_pfnMetricQueryReset_t,
           :pfnGetData, :zet_pfnMetricQueryGetData_t
  end
  typedef ZETMetricQueryDDITableT10.by_value, :zet_metric_query_dditable_t_1_0

  class ZETTracerExpDDITableT10 < FFI::ZEStruct
    layout :pfnCreate, :zet_pfnTracerExpCreate_t,
           :pfnDestroy, :zet_pfnTracerExpDestroy_t,
           :pfnSetPrologues, :zet_pfnTracerExpSetPrologues_t,
           :pfnSetEpilogues, :zet_pfnTracerExpSetEpilogues_t,
           :pfnSetEnabled, :zet_pfnTracerExpSetEnabled_t
  end
  typedef ZETTracerExpDDITableT10.by_value, :zet_tracer_exp_dditable_t_1_0

  class ZETDebugDDITableT10 < FFI::ZEStruct
    layout :pfnAttach, :zet_pfnDebugAttach_t,
           :pfnDetach, :zet_pfnDebugDetach_t,
           :pfnReadEvent, :zet_pfnDebugReadEvent_t,
           :pfnAcknowledgeEvent, :zet_pfnDebugAcknowledgeEvent_t,
           :pfnInterrupt, :zet_pfnDebugInterrupt_t,
           :pfnResume, :zet_pfnDebugResume_t,
           :pfnReadMemory, :zet_pfnDebugReadMemory_t,
           :pfnWriteMemory, :zet_pfnDebugWriteMemory_t,
           :pfnGetRegisterSetProperties, :zet_pfnDebugGetRegisterSetProperties_t,
           :pfnReadRegisters, :zet_pfnDebugReadRegisters_t,
           :pfnWriteRegisters, :zet_pfnDebugWriteRegisters_t
  end
  typedef ZETDebugDDITableT10.by_value, :zet_debug_dditable_t_1_0

  class ZETDebugDDITableT15 < FFI::ZEStruct
    layout :pfnAttach, :zet_pfnDebugAttach_t,
           :pfnDetach, :zet_pfnDebugDetach_t,
           :pfnReadEvent, :zet_pfnDebugReadEvent_t,
           :pfnAcknowledgeEvent, :zet_pfnDebugAcknowledgeEvent_t,
           :pfnInterrupt, :zet_pfnDebugInterrupt_t,
           :pfnResume, :zet_pfnDebugResume_t,
           :pfnReadMemory, :zet_pfnDebugReadMemory_t,
           :pfnWriteMemory, :zet_pfnDebugWriteMemory_t,
           :pfnGetRegisterSetProperties, :zet_pfnDebugGetRegisterSetProperties_t,
           :pfnReadRegisters, :zet_pfnDebugReadRegisters_t,
           :pfnWriteRegisters, :zet_pfnDebugWriteRegisters_t,
           :pfnGetThreadRegisterSetProperties, :zet_pfnDebugGetThreadRegisterSetProperties_t
  end
  typedef ZETDebugDDITableT15.by_value, :zet_debug_dditable_t_1_5

  class ZESBaseProperties < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer
  end
  typedef ZESBaseProperties.by_value, :zes_base_properties_t

  class ZESBaseDesc < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer
  end
  typedef ZESBaseDesc.by_value, :zes_base_desc_t

  class ZESBaseState < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_BASE_STATE
      end
    end
  end
  typedef ZESBaseState.by_value, :zes_base_state_t

  class ZESBaseConfig < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer
  end
  typedef ZESBaseConfig.by_value, :zes_base_config_t

  class ZESBaseCapability < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer
  end
  typedef ZESBaseCapability.by_value, :zes_base_capability_t

  class ZESDriverExtensionProperties < FFI::ZEStruct
    layout :name, [ :char, ZES_MAX_EXTENSION_NAME ],
           :version, :uint32
  end
  typedef ZESDriverExtensionProperties.by_value, :zes_driver_extension_properties_t

  class ZESDeviceState < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :reset, :zes_reset_reason_flags_t,
           :repaired, :zes_repair_status_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_DEVICE_STATE
      end
    end
  end
  typedef ZESDeviceState.by_value, :zes_device_state_t

  class ZESResetProperties < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :force, :ze_bool_t,
           :resetType, :zes_reset_type_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_RESET_PROPERTIES
      end
    end
  end
  typedef ZESResetProperties.by_value, :zes_reset_properties_t

  class ZESUUID < FFI::ZEStruct
    prepend UUID
    layout :id, [ :uint8, ZES_MAX_UUID_SIZE ]
  end
  typedef ZESUUID.by_value, :zes_uuid_t

  class ZESDeviceProperties < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :core, :ze_device_properties_t,
           :numSubdevices, :uint32,
           :serialNumber, [ :char, ZES_STRING_PROPERTY_SIZE ],
           :boardNumber, [ :char, ZES_STRING_PROPERTY_SIZE ],
           :brandName, [ :char, ZES_STRING_PROPERTY_SIZE ],
           :modelName, [ :char, ZES_STRING_PROPERTY_SIZE ],
           :vendorName, [ :char, ZES_STRING_PROPERTY_SIZE ],
           :driverVersion, [ :char, ZES_STRING_PROPERTY_SIZE ]

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_DEVICE_PROPERTIES
      end
    end
  end
  typedef ZESDeviceProperties.by_value, :zes_device_properties_t

  class ZESDeviceExtProperties < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :uuid, :zes_uuid_t,
           :type, :zes_device_type_t,
           :flags, :zes_device_property_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_DEVICE_EXT_PROPERTIES
      end
    end
  end
  typedef ZESDeviceExtProperties.by_value, :zes_device_ext_properties_t

  class ZESProcessState < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :processId, :uint32,
           :memSize, :uint64,
           :sharedSize, :uint64,
           :engines, :zes_engine_type_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_PROCESS_STATE
      end
    end
  end
  typedef ZESProcessState.by_value, :zes_process_state_t

  class ZESPciAddress < FFI::ZEStruct
    layout :domain, :uint32,
           :bus, :uint32,
           :device, :uint32,
           :function, :uint32
  end
  typedef ZESPciAddress.by_value, :zes_pci_address_t

  class ZESPciSpeed < FFI::ZEStruct
    layout :gen, :int32,
           :width, :int32,
           :maxBandwidth, :int64
  end
  typedef ZESPciSpeed.by_value, :zes_pci_speed_t

  class ZESPciProperties < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :address, :zes_pci_address_t,
           :maxSpeed, :zes_pci_speed_t,
           :haveBandwidthCounters, :ze_bool_t,
           :havePacketCounters, :ze_bool_t,
           :haveReplayCounters, :ze_bool_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_PCI_PROPERTIES
      end
    end
  end
  typedef ZESPciProperties.by_value, :zes_pci_properties_t

  class ZESPciState < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :status, :zes_pci_link_status_t,
           :qualityIssues, :zes_pci_link_qual_issue_flags_t,
           :stabilityIssues, :zes_pci_link_stab_issue_flags_t,
           :speed, :zes_pci_speed_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_PCI_STATE
      end
    end
  end
  typedef ZESPciState.by_value, :zes_pci_state_t

  class ZESPciBarProperties < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :type, :zes_pci_bar_type_t,
           :index, :uint32,
           :base, :uint64,
           :size, :uint64

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_PCI_BAR_PROPERTIES
      end
    end
  end
  typedef ZESPciBarProperties.by_value, :zes_pci_bar_properties_t

  class ZESPciBarProperties12 < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :type, :zes_pci_bar_type_t,
           :index, :uint32,
           :base, :uint64,
           :size, :uint64,
           :resizableBarSupported, :ze_bool_t,
           :resizableBarEnabled, :ze_bool_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_PCI_BAR_PROPERTIES_1_2
      end
    end
  end
  typedef ZESPciBarProperties12.by_value, :zes_pci_bar_properties_1_2_t

  class ZESPciStats < FFI::ZEStruct
    layout :timestamp, :uint64,
           :replayCounter, :uint64,
           :packetCounter, :uint64,
           :rxCounter, :uint64,
           :txCounter, :uint64,
           :speed, :zes_pci_speed_t
  end
  typedef ZESPciStats.by_value, :zes_pci_stats_t

  class ZESOverclockProperties < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :domainType, :zes_overclock_domain_t,
           :AvailableControls, :uint32,
           :VFProgramType, :zes_vf_program_type_t,
           :NumberOfVFPoints, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_OVERCLOCK_PROPERTIES
      end
    end
  end
  typedef ZESOverclockProperties.by_value, :zes_overclock_properties_t

  class ZESControlProperty < FFI::ZEStruct
    layout :MinValue, :double,
           :MaxValue, :double,
           :StepValue, :double,
           :RefValue, :double,
           :DefaultValue, :double
  end
  typedef ZESControlProperty.by_value, :zes_control_property_t

  class ZESVfProperty < FFI::ZEStruct
    layout :MinFreq, :double,
           :MaxFreq, :double,
           :StepFreq, :double,
           :MinVolt, :double,
           :MaxVolt, :double,
           :StepVolt, :double
  end
  typedef ZESVfProperty.by_value, :zes_vf_property_t

  class ZESDiagTest < FFI::ZEStruct
    layout :index, :uint32,
           :name, [ :char, ZES_STRING_PROPERTY_SIZE ]
  end
  typedef ZESDiagTest.by_value, :zes_diag_test_t

  class ZESDiagProperties < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :onSubdevice, :ze_bool_t,
           :subdeviceId, :uint32,
           :name, [ :char, ZES_STRING_PROPERTY_SIZE ],
           :haveTests, :ze_bool_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_DIAG_PROPERTIES
      end
    end
  end
  typedef ZESDiagProperties.by_value, :zes_diag_properties_t

  class ZESDeviceEccDesc < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :state, :zes_device_ecc_state_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_DEVICE_ECC_DESC
      end
    end
  end
  typedef ZESDeviceEccDesc.by_value, :zes_device_ecc_desc_t

  class ZESDeviceEccProperties < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :currentState, :zes_device_ecc_state_t,
           :pendingState, :zes_device_ecc_state_t,
           :pendingAction, :zes_device_action_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_DEVICE_ECC_PROPERTIES
      end
    end
  end
  typedef ZESDeviceEccProperties.by_value, :zes_device_ecc_properties_t

  class ZESEngineProperties < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :type, :zes_engine_group_t,
           :onSubdevice, :ze_bool_t,
           :subdeviceId, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_ENGINE_PROPERTIES
      end
    end
  end
  typedef ZESEngineProperties.by_value, :zes_engine_properties_t

  class ZESEngineStats < FFI::ZEStruct
    layout :activeTime, :uint64,
           :timestamp, :uint64
  end
  typedef ZESEngineStats.by_value, :zes_engine_stats_t

  class ZESFabricPortId < FFI::ZEStruct
    layout :fabricId, :uint32,
           :attachId, :uint32,
           :portNumber, :uint8
  end
  typedef ZESFabricPortId.by_value, :zes_fabric_port_id_t

  class ZESFabricPortSpeed < FFI::ZEStruct
    layout :bitRate, :int64,
           :width, :int32
  end
  typedef ZESFabricPortSpeed.by_value, :zes_fabric_port_speed_t

  class ZESFabricPortProperties < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :model, [ :char, ZES_MAX_FABRIC_PORT_MODEL_SIZE ],
           :onSubdevice, :ze_bool_t,
           :subdeviceId, :uint32,
           :portId, :zes_fabric_port_id_t,
           :maxRxSpeed, :zes_fabric_port_speed_t,
           :maxTxSpeed, :zes_fabric_port_speed_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_FABRIC_PORT_PROPERTIES
      end
    end
  end
  typedef ZESFabricPortProperties.by_value, :zes_fabric_port_properties_t

  class ZESFabricLinkType < FFI::ZEStruct
    layout :desc, [ :char, ZES_MAX_FABRIC_LINK_TYPE_SIZE ]
  end
  typedef ZESFabricLinkType.by_value, :zes_fabric_link_type_t

  class ZESFabricPortConfig < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :enabled, :ze_bool_t,
           :beaconing, :ze_bool_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_FABRIC_PORT_CONFIG
      end
    end
  end
  typedef ZESFabricPortConfig.by_value, :zes_fabric_port_config_t

  class ZESFabricPortState < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :status, :zes_fabric_port_status_t,
           :qualityIssues, :zes_fabric_port_qual_issue_flags_t,
           :failureReasons, :zes_fabric_port_failure_flags_t,
           :remotePortId, :zes_fabric_port_id_t,
           :rxSpeed, :zes_fabric_port_speed_t,
           :txSpeed, :zes_fabric_port_speed_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_FABRIC_PORT_STATE
      end
    end
  end
  typedef ZESFabricPortState.by_value, :zes_fabric_port_state_t

  class ZESFabricPortThroughput < FFI::ZEStruct
    layout :timestamp, :uint64,
           :rxCounter, :uint64,
           :txCounter, :uint64
  end
  typedef ZESFabricPortThroughput.by_value, :zes_fabric_port_throughput_t

  class ZESFabricPortErrorCounters < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :linkFailureCount, :uint64,
           :fwCommErrorCount, :uint64,
           :fwErrorCount, :uint64,
           :linkDegradeCount, :uint64

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_FABRIC_PORT_ERROR_COUNTERS
      end
    end
  end
  typedef ZESFabricPortErrorCounters.by_value, :zes_fabric_port_error_counters_t

  class ZESFanSpeed < FFI::ZEStruct
    layout :speed, :int32,
           :units, :zes_fan_speed_units_t
  end
  typedef ZESFanSpeed.by_value, :zes_fan_speed_t

  class ZESFanTempSpeed < FFI::ZEStruct
    layout :temperature, :uint32,
           :speed, :zes_fan_speed_t
  end
  typedef ZESFanTempSpeed.by_value, :zes_fan_temp_speed_t

  class ZESFanSpeedTable < FFI::ZEStruct
    layout :numPoints, :int32,
           :table, [ :zes_fan_temp_speed_t, ZES_FAN_TEMP_SPEED_PAIR_COUNT ]
  end
  typedef ZESFanSpeedTable.by_value, :zes_fan_speed_table_t

  class ZESFanProperties < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :onSubdevice, :ze_bool_t,
           :subdeviceId, :uint32,
           :canControl, :ze_bool_t,
           :supportedModes, :uint32,
           :supportedUnits, :uint32,
           :maxRPM, :int32,
           :maxPoints, :int32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_FAN_PROPERTIES
      end
    end
  end
  typedef ZESFanProperties.by_value, :zes_fan_properties_t

  class ZESFanConfig < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :mode, :zes_fan_speed_mode_t,
           :speedFixed, :zes_fan_speed_t,
           :speedTable, :zes_fan_speed_table_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_FAN_CONFIG
      end
    end
  end
  typedef ZESFanConfig.by_value, :zes_fan_config_t

  class ZESFirmwareProperties < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :onSubdevice, :ze_bool_t,
           :subdeviceId, :uint32,
           :canControl, :ze_bool_t,
           :name, [ :char, ZES_STRING_PROPERTY_SIZE ],
           :version, [ :char, ZES_STRING_PROPERTY_SIZE ]

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_FIRMWARE_PROPERTIES
      end
    end
  end
  typedef ZESFirmwareProperties.by_value, :zes_firmware_properties_t

  class ZESFreqProperties < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :type, :zes_freq_domain_t,
           :onSubdevice, :ze_bool_t,
           :subdeviceId, :uint32,
           :canControl, :ze_bool_t,
           :isThrottleEventSupported, :ze_bool_t,
           :min, :double,
           :max, :double

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_FREQ_PROPERTIES
      end
    end
  end
  typedef ZESFreqProperties.by_value, :zes_freq_properties_t

  class ZESFreqRange < FFI::ZEStruct
    layout :min, :double,
           :max, :double
  end
  typedef ZESFreqRange.by_value, :zes_freq_range_t

  class ZESFreqState < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :currentVoltage, :double,
           :request, :double,
           :tdp, :double,
           :efficient, :double,
           :actual, :double,
           :throttleReasons, :zes_freq_throttle_reason_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_FREQ_STATE
      end
    end
  end
  typedef ZESFreqState.by_value, :zes_freq_state_t

  class ZESFreqThrottleTime < FFI::ZEStruct
    layout :throttleTime, :uint64,
           :timestamp, :uint64
  end
  typedef ZESFreqThrottleTime.by_value, :zes_freq_throttle_time_t

  class ZESOcCapabilities < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :isOcSupported, :ze_bool_t,
           :maxFactoryDefaultFrequency, :double,
           :maxFactoryDefaultVoltage, :double,
           :maxOcFrequency, :double,
           :minOcVoltageOffset, :double,
           :maxOcVoltageOffset, :double,
           :maxOcVoltage, :double,
           :isTjMaxSupported, :ze_bool_t,
           :isIccMaxSupported, :ze_bool_t,
           :isHighVoltModeCapable, :ze_bool_t,
           :isHighVoltModeEnabled, :ze_bool_t,
           :isExtendedModeSupported, :ze_bool_t,
           :isFixedModeSupported, :ze_bool_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_OC_CAPABILITIES
      end
    end
  end
  typedef ZESOcCapabilities.by_value, :zes_oc_capabilities_t

  class ZESLedProperties < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :onSubdevice, :ze_bool_t,
           :subdeviceId, :uint32,
           :canControl, :ze_bool_t,
           :haveRGB, :ze_bool_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_LED_PROPERTIES
      end
    end
  end
  typedef ZESLedProperties.by_value, :zes_led_properties_t

  class ZESLedColor < FFI::ZEStruct
    layout :red, :double,
           :green, :double,
           :blue, :double
  end
  typedef ZESLedColor.by_value, :zes_led_color_t

  class ZESLedState < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :isOn, :ze_bool_t,
           :color, :zes_led_color_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_LED_STATE
      end
    end
  end
  typedef ZESLedState.by_value, :zes_led_state_t

  class ZESMemProperties < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :type, :zes_mem_type_t,
           :onSubdevice, :ze_bool_t,
           :subdeviceId, :uint32,
           :location, :zes_mem_loc_t,
           :physicalSize, :uint64,
           :busWidth, :int32,
           :numChannels, :int32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_MEM_PROPERTIES
      end
    end
  end
  typedef ZESMemProperties.by_value, :zes_mem_properties_t

  class ZESMemState < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :health, :zes_mem_health_t,
           :free, :uint64,
           :size, :uint64

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_MEM_STATE
      end
    end
  end
  typedef ZESMemState.by_value, :zes_mem_state_t

  class ZESMemBandwidth < FFI::ZEStruct
    layout :readCounter, :uint64,
           :writeCounter, :uint64,
           :maxBandwidth, :uint64,
           :timestamp, :uint64
  end
  typedef ZESMemBandwidth.by_value, :zes_mem_bandwidth_t

  class ZESMemExtBandwidth < FFI::ZEStruct
    layout :memoryTimestampValidBits, :uint32
  end
  typedef ZESMemExtBandwidth.by_value, :zes_mem_ext_bandwidth_t

  class ZESPerfProperties < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :onSubdevice, :ze_bool_t,
           :subdeviceId, :uint32,
           :engines, :zes_engine_type_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_PERF_PROPERTIES
      end
    end
  end
  typedef ZESPerfProperties.by_value, :zes_perf_properties_t

  class ZESPowerProperties < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :onSubdevice, :ze_bool_t,
           :subdeviceId, :uint32,
           :canControl, :ze_bool_t,
           :isEnergyThresholdSupported, :ze_bool_t,
           :defaultLimit, :int32,
           :minLimit, :int32,
           :maxLimit, :int32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_POWER_PROPERTIES
      end
    end
  end
  typedef ZESPowerProperties.by_value, :zes_power_properties_t

  class ZESPowerEnergyCounter < FFI::ZEStruct
    layout :energy, :uint64,
           :timestamp, :uint64
  end
  typedef ZESPowerEnergyCounter.by_value, :zes_power_energy_counter_t

  class ZESPowerSustainedLimit < FFI::ZEStruct
    layout :enabled, :ze_bool_t,
           :power, :int32,
           :interval, :int32
  end
  typedef ZESPowerSustainedLimit.by_value, :zes_power_sustained_limit_t

  class ZESPowerBurstLimit < FFI::ZEStruct
    layout :enabled, :ze_bool_t,
           :power, :int32
  end
  typedef ZESPowerBurstLimit.by_value, :zes_power_burst_limit_t

  class ZESPowerPeakLimit < FFI::ZEStruct
    layout :powerAC, :int32,
           :powerDC, :int32
  end
  typedef ZESPowerPeakLimit.by_value, :zes_power_peak_limit_t

  class ZESEnergyThreshold < FFI::ZEStruct
    layout :enable, :ze_bool_t,
           :threshold, :double,
           :processId, :uint32
  end
  typedef ZESEnergyThreshold.by_value, :zes_energy_threshold_t

  class ZESPsuProperties < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :onSubdevice, :ze_bool_t,
           :subdeviceId, :uint32,
           :haveFan, :ze_bool_t,
           :ampLimit, :int32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_PSU_PROPERTIES
      end
    end
  end
  typedef ZESPsuProperties.by_value, :zes_psu_properties_t

  class ZESPsuState < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :voltStatus, :zes_psu_voltage_status_t,
           :fanFailed, :ze_bool_t,
           :temperature, :int32,
           :current, :int32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_PSU_STATE
      end
    end
  end
  typedef ZESPsuState.by_value, :zes_psu_state_t

  class ZESRasProperties < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :type, :zes_ras_error_type_t,
           :onSubdevice, :ze_bool_t,
           :subdeviceId, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_RAS_PROPERTIES
      end
    end
  end
  typedef ZESRasProperties.by_value, :zes_ras_properties_t

  class ZESRasState < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :category, [ :uint64, ZES_MAX_RAS_ERROR_CATEGORY_COUNT ]

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_RAS_STATE
      end
    end
  end
  typedef ZESRasState.by_value, :zes_ras_state_t

  class ZESRasConfig < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :totalThreshold, :uint64,
           :detailedThresholds, :zes_ras_state_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_RAS_CONFIG
      end
    end
  end
  typedef ZESRasConfig.by_value, :zes_ras_config_t

  class ZESSchedProperties < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :onSubdevice, :ze_bool_t,
           :subdeviceId, :uint32,
           :canControl, :ze_bool_t,
           :engines, :zes_engine_type_flags_t,
           :supportedModes, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_SCHED_PROPERTIES
      end
    end
  end
  typedef ZESSchedProperties.by_value, :zes_sched_properties_t

  class ZESSchedTimeoutProperties < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :watchdogTimeout, :uint64

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_SCHED_TIMEOUT_PROPERTIES
      end
    end
  end
  typedef ZESSchedTimeoutProperties.by_value, :zes_sched_timeout_properties_t

  class ZESSchedTimesliceProperties < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :interval, :uint64,
           :yieldTimeout, :uint64

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_SCHED_TIMESLICE_PROPERTIES
      end
    end
  end
  typedef ZESSchedTimesliceProperties.by_value, :zes_sched_timeslice_properties_t

  class ZESStandbyProperties < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :type, :zes_standby_type_t,
           :onSubdevice, :ze_bool_t,
           :subdeviceId, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_STANDBY_PROPERTIES
      end
    end
  end
  typedef ZESStandbyProperties.by_value, :zes_standby_properties_t

  class ZESTempProperties < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :type, :zes_temp_sensors_t,
           :onSubdevice, :ze_bool_t,
           :subdeviceId, :uint32,
           :maxTemperature, :double,
           :isCriticalTempSupported, :ze_bool_t,
           :isThreshold1Supported, :ze_bool_t,
           :isThreshold2Supported, :ze_bool_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_TEMP_PROPERTIES
      end
    end
  end
  typedef ZESTempProperties.by_value, :zes_temp_properties_t

  class ZESTempThreshold < FFI::ZEStruct
    layout :enableLowToHigh, :ze_bool_t,
           :enableHighToLow, :ze_bool_t,
           :threshold, :double
  end
  typedef ZESTempThreshold.by_value, :zes_temp_threshold_t

  class ZESTempConfig < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :enableCritical, :ze_bool_t,
           :threshold1, :zes_temp_threshold_t,
           :threshold2, :zes_temp_threshold_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_TEMP_CONFIG
      end
    end
  end
  typedef ZESTempConfig.by_value, :zes_temp_config_t

  class ZESDeviceEccDefaultPropertiesExt < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :defaultState, :zes_device_ecc_state_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_DEVICE_ECC_DEFAULT_PROPERTIES_EXT
      end
    end
  end
  typedef ZESDeviceEccDefaultPropertiesExt.by_value, :zes_device_ecc_default_properties_ext_t

  class ZESPowerLimitExtDesc < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :level, :zes_power_level_t,
           :source, :zes_power_source_t,
           :limitUnit, :zes_limit_unit_t,
           :enabledStateLocked, :ze_bool_t,
           :enabled, :ze_bool_t,
           :intervalValueLocked, :ze_bool_t,
           :interval, :int32,
           :limitValueLocked, :ze_bool_t,
           :limit, :int32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_POWER_LIMIT_EXT_DESC
      end
    end
  end
  typedef ZESPowerLimitExtDesc.by_value, :zes_power_limit_ext_desc_t

  class ZESPowerExtProperties < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :domain, :zes_power_domain_t,
           :defaultLimit, :pointer

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_POWER_EXT_PROPERTIES
      end
    end
  end
  typedef ZESPowerExtProperties.by_value, :zes_power_ext_properties_t

  class ZESEngineExtProperties < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :countOfVirtualFunctionInstance, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_ENGINE_EXT_PROPERTIES
      end
    end
  end
  typedef ZESEngineExtProperties.by_value, :zes_engine_ext_properties_t

  class ZESRasStateExp < FFI::ZEStruct
    layout :category, :zes_ras_error_category_exp_t,
           :errorCounter, :uint64
  end
  typedef ZESRasStateExp.by_value, :zes_ras_state_exp_t

  class ZESMemPageOfflineStateExp < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :memoryPageOffline, :uint32,
           :maxMemoryPageOffline, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_MEMORY_PAGE_OFFLINE_STATE_EXP
      end
    end
  end
  typedef ZESMemPageOfflineStateExp.by_value, :zes_mem_page_offline_state_exp_t

  class ZESMemBandwidthCounterBitsExpProperties < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :validBitsCount, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_MEM_BANDWIDTH_COUNTER_BITS_EXP_PROPERTIES
      end
    end
  end
  typedef ZESMemBandwidthCounterBitsExpProperties.by_value, :zes_mem_bandwidth_counter_bits_exp_properties_t

  class ZESPowerDomainExpProperties < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :powerDomain, :zes_power_domain_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_POWER_DOMAIN_EXP_PROPERTIES
      end
    end
  end
  typedef ZESPowerDomainExpProperties.by_value, :zes_power_domain_exp_properties_t

  class ZESSubdeviceExpProperties < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :subdeviceId, :uint32,
           :uuid, :zes_uuid_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_SUBDEVICE_EXP_PROPERTIES
      end
    end
  end
  typedef ZESSubdeviceExpProperties.by_value, :zes_subdevice_exp_properties_t

  class ZESVfExpProperties < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :address, :zes_pci_address_t,
           :uuid, :zes_uuid_t,
           :flags, :zes_vf_info_util_exp_flags_t

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_VF_EXP_PROPERTIES
      end
    end
  end
  typedef ZESVfExpProperties.by_value, :zes_vf_exp_properties_t

  class ZESVfUtilMemExp < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :memTypeFlags, :zes_vf_info_mem_type_exp_flags_t,
           :free, :uint64,
           :size, :uint64,
           :timestamp, :uint64

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_VF_UTIL_MEM_EXP
      end
    end
  end
  typedef ZESVfUtilMemExp.by_value, :zes_vf_util_mem_exp_t

  class ZESVfUtilEngineExp < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :type, :zes_engine_group_t,
           :activeCounterValue, :uint64,
           :samplingCounterValue, :uint64,
           :timestamp, :uint64

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_VF_UTIL_ENGINE_EXP
      end
    end
  end
  typedef ZESVfUtilEngineExp.by_value, :zes_vf_util_engine_exp_t

  class ZESVfExpCapabilities < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :address, :zes_pci_address_t,
           :vfDeviceMemSize, :uint32,
           :vfID, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_VF_EXP_CAPABILITIES
      end
    end
  end
  typedef ZESVfExpCapabilities.by_value, :zes_vf_exp_capabilities_t

  class ZESVfExp2Capabilities < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :address, :zes_pci_address_t,
           :vfDeviceMemSize, :uint64,
           :vfID, :uint32

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_VF_EXP2_CAPABILITIES
      end
    end
  end
  typedef ZESVfExp2Capabilities.by_value, :zes_vf_exp2_capabilities_t

  class ZESVfUtilMemExp2 < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :vfMemLocation, :zes_mem_loc_t,
           :vfMemUtilized, :uint64

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_VF_UTIL_MEM_EXP2
      end
    end
  end
  typedef ZESVfUtilMemExp2.by_value, :zes_vf_util_mem_exp2_t

  class ZESVfUtilEngineExp2 < FFI::ZEStruct
    layout :stype, :zes_structure_type_t,
           :pNext, :pointer,
           :vfEngineType, :zes_engine_group_t,
           :activeCounterValue, :uint64,
           :samplingCounterValue, :uint64

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZES_STRUCTURE_TYPE_VF_UTIL_ENGINE_EXP2
      end
    end
  end
  typedef ZESVfUtilEngineExp2.by_value, :zes_vf_util_engine_exp2_t

  callback :zes_pfnInit_t,
           [ :zes_init_flags_t ],
           :ze_result_t

  class ZESGlobalDDITable < FFI::ZEStruct
    layout :pfnInit, :zes_pfnInit_t
  end
  typedef ZESGlobalDDITable.by_value, :zes_global_dditable_t

  callback :zes_pfnGetGlobalProcAddrTable_t,
           [ :ze_api_version_t,
             ZESGlobalDDITable.ptr ],
           :ze_result_t

  callback :zes_pfnDeviceGetProperties_t,
           [ :zes_device_handle_t,
             ZESDeviceProperties.ptr ],
           :ze_result_t

  callback :zes_pfnDeviceGetState_t,
           [ :zes_device_handle_t,
             ZESDeviceState.ptr ],
           :ze_result_t

  callback :zes_pfnDeviceReset_t,
           [ :zes_device_handle_t,
             :ze_bool_t ],
           :ze_result_t

  callback :zes_pfnDeviceProcessesGetState_t,
           [ :zes_device_handle_t,
             :pointer,
             ZESProcessState.ptr ],
           :ze_result_t

  callback :zes_pfnDevicePciGetProperties_t,
           [ :zes_device_handle_t,
             ZESPciProperties.ptr ],
           :ze_result_t

  callback :zes_pfnDevicePciGetState_t,
           [ :zes_device_handle_t,
             ZESPciState.ptr ],
           :ze_result_t

  callback :zes_pfnDevicePciGetBars_t,
           [ :zes_device_handle_t,
             :pointer,
             ZESPciBarProperties.ptr ],
           :ze_result_t

  callback :zes_pfnDevicePciGetStats_t,
           [ :zes_device_handle_t,
             ZESPciStats.ptr ],
           :ze_result_t

  callback :zes_pfnDeviceEnumDiagnosticTestSuites_t,
           [ :zes_device_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :zes_pfnDeviceEnumEngineGroups_t,
           [ :zes_device_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :zes_pfnDeviceEventRegister_t,
           [ :zes_device_handle_t,
             :zes_event_type_flags_t ],
           :ze_result_t

  callback :zes_pfnDeviceEnumFabricPorts_t,
           [ :zes_device_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :zes_pfnDeviceEnumFans_t,
           [ :zes_device_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :zes_pfnDeviceEnumFirmwares_t,
           [ :zes_device_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :zes_pfnDeviceEnumFrequencyDomains_t,
           [ :zes_device_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :zes_pfnDeviceEnumLeds_t,
           [ :zes_device_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :zes_pfnDeviceEnumMemoryModules_t,
           [ :zes_device_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :zes_pfnDeviceEnumPerformanceFactorDomains_t,
           [ :zes_device_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :zes_pfnDeviceEnumPowerDomains_t,
           [ :zes_device_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :zes_pfnDeviceGetCardPowerDomain_t,
           [ :zes_device_handle_t,
             :pointer ],
           :ze_result_t

  callback :zes_pfnDeviceEnumPsus_t,
           [ :zes_device_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :zes_pfnDeviceEnumRasErrorSets_t,
           [ :zes_device_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :zes_pfnDeviceEnumSchedulers_t,
           [ :zes_device_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :zes_pfnDeviceEnumStandbyDomains_t,
           [ :zes_device_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :zes_pfnDeviceEnumTemperatureSensors_t,
           [ :zes_device_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :zes_pfnDeviceEccAvailable_t,
           [ :zes_device_handle_t,
             :pointer ],
           :ze_result_t

  callback :zes_pfnDeviceEccConfigurable_t,
           [ :zes_device_handle_t,
             :pointer ],
           :ze_result_t

  callback :zes_pfnDeviceGetEccState_t,
           [ :zes_device_handle_t,
             ZESDeviceEccProperties.ptr ],
           :ze_result_t

  callback :zes_pfnDeviceSetEccState_t,
           [ :zes_device_handle_t,
             ZESDeviceEccDesc.ptr,
             ZESDeviceEccProperties.ptr ],
           :ze_result_t

  callback :zes_pfnDeviceGet_t,
           [ :zes_driver_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :zes_pfnDeviceSetOverclockWaiver_t,
           [ :zes_device_handle_t ],
           :ze_result_t

  callback :zes_pfnDeviceGetOverclockDomains_t,
           [ :zes_device_handle_t,
             :pointer ],
           :ze_result_t

  callback :zes_pfnDeviceGetOverclockControls_t,
           [ :zes_device_handle_t,
             :zes_overclock_domain_t,
             :pointer ],
           :ze_result_t

  callback :zes_pfnDeviceResetOverclockSettings_t,
           [ :zes_device_handle_t,
             :ze_bool_t ],
           :ze_result_t

  callback :zes_pfnDeviceReadOverclockState_t,
           [ :zes_device_handle_t,
             :pointer,
             :pointer,
             :pointer,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :zes_pfnDeviceEnumOverclockDomains_t,
           [ :zes_device_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :zes_pfnDeviceResetExt_t,
           [ :zes_device_handle_t,
             ZESResetProperties.ptr ],
           :ze_result_t

  class ZESDeviceDDITable < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnDeviceGetProperties_t,
           :pfnGetState, :zes_pfnDeviceGetState_t,
           :pfnReset, :zes_pfnDeviceReset_t,
           :pfnProcessesGetState, :zes_pfnDeviceProcessesGetState_t,
           :pfnPciGetProperties, :zes_pfnDevicePciGetProperties_t,
           :pfnPciGetState, :zes_pfnDevicePciGetState_t,
           :pfnPciGetBars, :zes_pfnDevicePciGetBars_t,
           :pfnPciGetStats, :zes_pfnDevicePciGetStats_t,
           :pfnEnumDiagnosticTestSuites, :zes_pfnDeviceEnumDiagnosticTestSuites_t,
           :pfnEnumEngineGroups, :zes_pfnDeviceEnumEngineGroups_t,
           :pfnEventRegister, :zes_pfnDeviceEventRegister_t,
           :pfnEnumFabricPorts, :zes_pfnDeviceEnumFabricPorts_t,
           :pfnEnumFans, :zes_pfnDeviceEnumFans_t,
           :pfnEnumFirmwares, :zes_pfnDeviceEnumFirmwares_t,
           :pfnEnumFrequencyDomains, :zes_pfnDeviceEnumFrequencyDomains_t,
           :pfnEnumLeds, :zes_pfnDeviceEnumLeds_t,
           :pfnEnumMemoryModules, :zes_pfnDeviceEnumMemoryModules_t,
           :pfnEnumPerformanceFactorDomains, :zes_pfnDeviceEnumPerformanceFactorDomains_t,
           :pfnEnumPowerDomains, :zes_pfnDeviceEnumPowerDomains_t,
           :pfnGetCardPowerDomain, :zes_pfnDeviceGetCardPowerDomain_t,
           :pfnEnumPsus, :zes_pfnDeviceEnumPsus_t,
           :pfnEnumRasErrorSets, :zes_pfnDeviceEnumRasErrorSets_t,
           :pfnEnumSchedulers, :zes_pfnDeviceEnumSchedulers_t,
           :pfnEnumStandbyDomains, :zes_pfnDeviceEnumStandbyDomains_t,
           :pfnEnumTemperatureSensors, :zes_pfnDeviceEnumTemperatureSensors_t,
           :pfnEccAvailable, :zes_pfnDeviceEccAvailable_t,
           :pfnEccConfigurable, :zes_pfnDeviceEccConfigurable_t,
           :pfnGetEccState, :zes_pfnDeviceGetEccState_t,
           :pfnSetEccState, :zes_pfnDeviceSetEccState_t,
           :pfnGet, :zes_pfnDeviceGet_t,
           :pfnSetOverclockWaiver, :zes_pfnDeviceSetOverclockWaiver_t,
           :pfnGetOverclockDomains, :zes_pfnDeviceGetOverclockDomains_t,
           :pfnGetOverclockControls, :zes_pfnDeviceGetOverclockControls_t,
           :pfnResetOverclockSettings, :zes_pfnDeviceResetOverclockSettings_t,
           :pfnReadOverclockState, :zes_pfnDeviceReadOverclockState_t,
           :pfnEnumOverclockDomains, :zes_pfnDeviceEnumOverclockDomains_t,
           :pfnResetExt, :zes_pfnDeviceResetExt_t
  end
  typedef ZESDeviceDDITable.by_value, :zes_device_dditable_t

  callback :zes_pfnGetDeviceProcAddrTable_t,
           [ :ze_api_version_t,
             ZESDeviceDDITable.ptr ],
           :ze_result_t

  callback :zes_pfnDeviceGetSubDevicePropertiesExp_t,
           [ :zes_device_handle_t,
             :pointer,
             ZESSubdeviceExpProperties.ptr ],
           :ze_result_t

  callback :zes_pfnDeviceEnumActiveVFExp_t,
           [ :zes_device_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :zes_pfnDeviceEnumEnabledVFExp_t,
           [ :zes_device_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  class ZESDeviceExpDDITable < FFI::ZEStruct
    layout :pfnGetSubDevicePropertiesExp, :zes_pfnDeviceGetSubDevicePropertiesExp_t,
           :pfnEnumActiveVFExp, :zes_pfnDeviceEnumActiveVFExp_t,
           :pfnEnumEnabledVFExp, :zes_pfnDeviceEnumEnabledVFExp_t
  end
  typedef ZESDeviceExpDDITable.by_value, :zes_device_exp_dditable_t

  callback :zes_pfnGetDeviceExpProcAddrTable_t,
           [ :ze_api_version_t,
             ZESDeviceExpDDITable.ptr ],
           :ze_result_t

  callback :zes_pfnDriverEventListen_t,
           [ :ze_driver_handle_t,
             :uint32,
             :uint32,
             :pointer,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :zes_pfnDriverEventListenEx_t,
           [ :ze_driver_handle_t,
             :uint64,
             :uint32,
             :pointer,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :zes_pfnDriverGet_t,
           [ :pointer,
             :pointer ],
           :ze_result_t

  callback :zes_pfnDriverGetExtensionProperties_t,
           [ :zes_driver_handle_t,
             :pointer,
             ZESDriverExtensionProperties.ptr ],
           :ze_result_t

  callback :zes_pfnDriverGetExtensionFunctionAddress_t,
           [ :zes_driver_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  class ZESDriverDDITable < FFI::ZEStruct
    layout :pfnEventListen, :zes_pfnDriverEventListen_t,
           :pfnEventListenEx, :zes_pfnDriverEventListenEx_t,
           :pfnGet, :zes_pfnDriverGet_t,
           :pfnGetExtensionProperties, :zes_pfnDriverGetExtensionProperties_t,
           :pfnGetExtensionFunctionAddress, :zes_pfnDriverGetExtensionFunctionAddress_t
  end
  typedef ZESDriverDDITable.by_value, :zes_driver_dditable_t

  callback :zes_pfnGetDriverProcAddrTable_t,
           [ :ze_api_version_t,
             ZESDriverDDITable.ptr ],
           :ze_result_t

  callback :zes_pfnDriverGetDeviceByUuidExp_t,
           [ :zes_driver_handle_t,
             :zes_uuid_t,
             :pointer,
             :pointer,
             :pointer ],
           :ze_result_t

  class ZESDriverExpDDITable < FFI::ZEStruct
    layout :pfnGetDeviceByUuidExp, :zes_pfnDriverGetDeviceByUuidExp_t
  end
  typedef ZESDriverExpDDITable.by_value, :zes_driver_exp_dditable_t

  callback :zes_pfnGetDriverExpProcAddrTable_t,
           [ :ze_api_version_t,
             ZESDriverExpDDITable.ptr ],
           :ze_result_t

  callback :zes_pfnOverclockGetDomainProperties_t,
           [ :zes_overclock_handle_t,
             ZESOverclockProperties.ptr ],
           :ze_result_t

  callback :zes_pfnOverclockGetDomainVFProperties_t,
           [ :zes_overclock_handle_t,
             ZESVfProperty.ptr ],
           :ze_result_t

  callback :zes_pfnOverclockGetDomainControlProperties_t,
           [ :zes_overclock_handle_t,
             :zes_overclock_control_t,
             ZESControlProperty.ptr ],
           :ze_result_t

  callback :zes_pfnOverclockGetControlCurrentValue_t,
           [ :zes_overclock_handle_t,
             :zes_overclock_control_t,
             :pointer ],
           :ze_result_t

  callback :zes_pfnOverclockGetControlPendingValue_t,
           [ :zes_overclock_handle_t,
             :zes_overclock_control_t,
             :pointer ],
           :ze_result_t

  callback :zes_pfnOverclockSetControlUserValue_t,
           [ :zes_overclock_handle_t,
             :zes_overclock_control_t,
             :double,
             :pointer ],
           :ze_result_t

  callback :zes_pfnOverclockGetControlState_t,
           [ :zes_overclock_handle_t,
             :zes_overclock_control_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :zes_pfnOverclockGetVFPointValues_t,
           [ :zes_overclock_handle_t,
             :zes_vf_type_t,
             :zes_vf_array_type_t,
             :uint32,
             :pointer ],
           :ze_result_t

  callback :zes_pfnOverclockSetVFPointValues_t,
           [ :zes_overclock_handle_t,
             :zes_vf_type_t,
             :uint32,
             :uint32 ],
           :ze_result_t

  class ZESOverclockDDITable < FFI::ZEStruct
    layout :pfnGetDomainProperties, :zes_pfnOverclockGetDomainProperties_t,
           :pfnGetDomainVFProperties, :zes_pfnOverclockGetDomainVFProperties_t,
           :pfnGetDomainControlProperties, :zes_pfnOverclockGetDomainControlProperties_t,
           :pfnGetControlCurrentValue, :zes_pfnOverclockGetControlCurrentValue_t,
           :pfnGetControlPendingValue, :zes_pfnOverclockGetControlPendingValue_t,
           :pfnSetControlUserValue, :zes_pfnOverclockSetControlUserValue_t,
           :pfnGetControlState, :zes_pfnOverclockGetControlState_t,
           :pfnGetVFPointValues, :zes_pfnOverclockGetVFPointValues_t,
           :pfnSetVFPointValues, :zes_pfnOverclockSetVFPointValues_t
  end
  typedef ZESOverclockDDITable.by_value, :zes_overclock_dditable_t

  callback :zes_pfnGetOverclockProcAddrTable_t,
           [ :ze_api_version_t,
             ZESOverclockDDITable.ptr ],
           :ze_result_t

  callback :zes_pfnSchedulerGetProperties_t,
           [ :zes_sched_handle_t,
             ZESSchedProperties.ptr ],
           :ze_result_t

  callback :zes_pfnSchedulerGetCurrentMode_t,
           [ :zes_sched_handle_t,
             :pointer ],
           :ze_result_t

  callback :zes_pfnSchedulerGetTimeoutModeProperties_t,
           [ :zes_sched_handle_t,
             :ze_bool_t,
             ZESSchedTimeoutProperties.ptr ],
           :ze_result_t

  callback :zes_pfnSchedulerGetTimesliceModeProperties_t,
           [ :zes_sched_handle_t,
             :ze_bool_t,
             ZESSchedTimesliceProperties.ptr ],
           :ze_result_t

  callback :zes_pfnSchedulerSetTimeoutMode_t,
           [ :zes_sched_handle_t,
             ZESSchedTimeoutProperties.ptr,
             :pointer ],
           :ze_result_t

  callback :zes_pfnSchedulerSetTimesliceMode_t,
           [ :zes_sched_handle_t,
             ZESSchedTimesliceProperties.ptr,
             :pointer ],
           :ze_result_t

  callback :zes_pfnSchedulerSetExclusiveMode_t,
           [ :zes_sched_handle_t,
             :pointer ],
           :ze_result_t

  callback :zes_pfnSchedulerSetComputeUnitDebugMode_t,
           [ :zes_sched_handle_t,
             :pointer ],
           :ze_result_t

  class ZESSchedulerDDITable < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnSchedulerGetProperties_t,
           :pfnGetCurrentMode, :zes_pfnSchedulerGetCurrentMode_t,
           :pfnGetTimeoutModeProperties, :zes_pfnSchedulerGetTimeoutModeProperties_t,
           :pfnGetTimesliceModeProperties, :zes_pfnSchedulerGetTimesliceModeProperties_t,
           :pfnSetTimeoutMode, :zes_pfnSchedulerSetTimeoutMode_t,
           :pfnSetTimesliceMode, :zes_pfnSchedulerSetTimesliceMode_t,
           :pfnSetExclusiveMode, :zes_pfnSchedulerSetExclusiveMode_t,
           :pfnSetComputeUnitDebugMode, :zes_pfnSchedulerSetComputeUnitDebugMode_t
  end
  typedef ZESSchedulerDDITable.by_value, :zes_scheduler_dditable_t

  callback :zes_pfnGetSchedulerProcAddrTable_t,
           [ :ze_api_version_t,
             ZESSchedulerDDITable.ptr ],
           :ze_result_t

  callback :zes_pfnPerformanceFactorGetProperties_t,
           [ :zes_perf_handle_t,
             ZESPerfProperties.ptr ],
           :ze_result_t

  callback :zes_pfnPerformanceFactorGetConfig_t,
           [ :zes_perf_handle_t,
             :pointer ],
           :ze_result_t

  callback :zes_pfnPerformanceFactorSetConfig_t,
           [ :zes_perf_handle_t,
             :double ],
           :ze_result_t

  class ZESPerformanceFactorDDITable < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnPerformanceFactorGetProperties_t,
           :pfnGetConfig, :zes_pfnPerformanceFactorGetConfig_t,
           :pfnSetConfig, :zes_pfnPerformanceFactorSetConfig_t
  end
  typedef ZESPerformanceFactorDDITable.by_value, :zes_performance_factor_dditable_t

  callback :zes_pfnGetPerformanceFactorProcAddrTable_t,
           [ :ze_api_version_t,
             ZESPerformanceFactorDDITable.ptr ],
           :ze_result_t

  callback :zes_pfnPowerGetProperties_t,
           [ :zes_pwr_handle_t,
             ZESPowerProperties.ptr ],
           :ze_result_t

  callback :zes_pfnPowerGetEnergyCounter_t,
           [ :zes_pwr_handle_t,
             ZESPowerEnergyCounter.ptr ],
           :ze_result_t

  callback :zes_pfnPowerGetLimits_t,
           [ :zes_pwr_handle_t,
             ZESPowerSustainedLimit.ptr,
             ZESPowerBurstLimit.ptr,
             ZESPowerPeakLimit.ptr ],
           :ze_result_t

  callback :zes_pfnPowerSetLimits_t,
           [ :zes_pwr_handle_t,
             ZESPowerSustainedLimit.ptr,
             ZESPowerBurstLimit.ptr,
             ZESPowerPeakLimit.ptr ],
           :ze_result_t

  callback :zes_pfnPowerGetEnergyThreshold_t,
           [ :zes_pwr_handle_t,
             ZESEnergyThreshold.ptr ],
           :ze_result_t

  callback :zes_pfnPowerSetEnergyThreshold_t,
           [ :zes_pwr_handle_t,
             :double ],
           :ze_result_t

  callback :zes_pfnPowerGetLimitsExt_t,
           [ :zes_pwr_handle_t,
             :pointer,
             ZESPowerLimitExtDesc.ptr ],
           :ze_result_t

  callback :zes_pfnPowerSetLimitsExt_t,
           [ :zes_pwr_handle_t,
             :pointer,
             ZESPowerLimitExtDesc.ptr ],
           :ze_result_t

  class ZESPowerDDITable < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnPowerGetProperties_t,
           :pfnGetEnergyCounter, :zes_pfnPowerGetEnergyCounter_t,
           :pfnGetLimits, :zes_pfnPowerGetLimits_t,
           :pfnSetLimits, :zes_pfnPowerSetLimits_t,
           :pfnGetEnergyThreshold, :zes_pfnPowerGetEnergyThreshold_t,
           :pfnSetEnergyThreshold, :zes_pfnPowerSetEnergyThreshold_t,
           :pfnGetLimitsExt, :zes_pfnPowerGetLimitsExt_t,
           :pfnSetLimitsExt, :zes_pfnPowerSetLimitsExt_t
  end
  typedef ZESPowerDDITable.by_value, :zes_power_dditable_t

  callback :zes_pfnGetPowerProcAddrTable_t,
           [ :ze_api_version_t,
             ZESPowerDDITable.ptr ],
           :ze_result_t

  callback :zes_pfnFrequencyGetProperties_t,
           [ :zes_freq_handle_t,
             ZESFreqProperties.ptr ],
           :ze_result_t

  callback :zes_pfnFrequencyGetAvailableClocks_t,
           [ :zes_freq_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :zes_pfnFrequencyGetRange_t,
           [ :zes_freq_handle_t,
             ZESFreqRange.ptr ],
           :ze_result_t

  callback :zes_pfnFrequencySetRange_t,
           [ :zes_freq_handle_t,
             ZESFreqRange.ptr ],
           :ze_result_t

  callback :zes_pfnFrequencyGetState_t,
           [ :zes_freq_handle_t,
             ZESFreqState.ptr ],
           :ze_result_t

  callback :zes_pfnFrequencyGetThrottleTime_t,
           [ :zes_freq_handle_t,
             ZESFreqThrottleTime.ptr ],
           :ze_result_t

  callback :zes_pfnFrequencyOcGetCapabilities_t,
           [ :zes_freq_handle_t,
             ZESOcCapabilities.ptr ],
           :ze_result_t

  callback :zes_pfnFrequencyOcGetFrequencyTarget_t,
           [ :zes_freq_handle_t,
             :pointer ],
           :ze_result_t

  callback :zes_pfnFrequencyOcSetFrequencyTarget_t,
           [ :zes_freq_handle_t,
             :double ],
           :ze_result_t

  callback :zes_pfnFrequencyOcGetVoltageTarget_t,
           [ :zes_freq_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  callback :zes_pfnFrequencyOcSetVoltageTarget_t,
           [ :zes_freq_handle_t,
             :double,
             :double ],
           :ze_result_t

  callback :zes_pfnFrequencyOcSetMode_t,
           [ :zes_freq_handle_t,
             :zes_oc_mode_t ],
           :ze_result_t

  callback :zes_pfnFrequencyOcGetMode_t,
           [ :zes_freq_handle_t,
             :pointer ],
           :ze_result_t

  callback :zes_pfnFrequencyOcGetIccMax_t,
           [ :zes_freq_handle_t,
             :pointer ],
           :ze_result_t

  callback :zes_pfnFrequencyOcSetIccMax_t,
           [ :zes_freq_handle_t,
             :double ],
           :ze_result_t

  callback :zes_pfnFrequencyOcGetTjMax_t,
           [ :zes_freq_handle_t,
             :pointer ],
           :ze_result_t

  callback :zes_pfnFrequencyOcSetTjMax_t,
           [ :zes_freq_handle_t,
             :double ],
           :ze_result_t

  class ZESFrequencyDDITable < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnFrequencyGetProperties_t,
           :pfnGetAvailableClocks, :zes_pfnFrequencyGetAvailableClocks_t,
           :pfnGetRange, :zes_pfnFrequencyGetRange_t,
           :pfnSetRange, :zes_pfnFrequencySetRange_t,
           :pfnGetState, :zes_pfnFrequencyGetState_t,
           :pfnGetThrottleTime, :zes_pfnFrequencyGetThrottleTime_t,
           :pfnOcGetCapabilities, :zes_pfnFrequencyOcGetCapabilities_t,
           :pfnOcGetFrequencyTarget, :zes_pfnFrequencyOcGetFrequencyTarget_t,
           :pfnOcSetFrequencyTarget, :zes_pfnFrequencyOcSetFrequencyTarget_t,
           :pfnOcGetVoltageTarget, :zes_pfnFrequencyOcGetVoltageTarget_t,
           :pfnOcSetVoltageTarget, :zes_pfnFrequencyOcSetVoltageTarget_t,
           :pfnOcSetMode, :zes_pfnFrequencyOcSetMode_t,
           :pfnOcGetMode, :zes_pfnFrequencyOcGetMode_t,
           :pfnOcGetIccMax, :zes_pfnFrequencyOcGetIccMax_t,
           :pfnOcSetIccMax, :zes_pfnFrequencyOcSetIccMax_t,
           :pfnOcGetTjMax, :zes_pfnFrequencyOcGetTjMax_t,
           :pfnOcSetTjMax, :zes_pfnFrequencyOcSetTjMax_t
  end
  typedef ZESFrequencyDDITable.by_value, :zes_frequency_dditable_t

  callback :zes_pfnGetFrequencyProcAddrTable_t,
           [ :ze_api_version_t,
             ZESFrequencyDDITable.ptr ],
           :ze_result_t

  callback :zes_pfnEngineGetProperties_t,
           [ :zes_engine_handle_t,
             ZESEngineProperties.ptr ],
           :ze_result_t

  callback :zes_pfnEngineGetActivity_t,
           [ :zes_engine_handle_t,
             ZESEngineStats.ptr ],
           :ze_result_t

  callback :zes_pfnEngineGetActivityExt_t,
           [ :zes_engine_handle_t,
             :pointer,
             ZESEngineStats.ptr ],
           :ze_result_t

  class ZESEngineDDITable < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnEngineGetProperties_t,
           :pfnGetActivity, :zes_pfnEngineGetActivity_t,
           :pfnGetActivityExt, :zes_pfnEngineGetActivityExt_t
  end
  typedef ZESEngineDDITable.by_value, :zes_engine_dditable_t

  callback :zes_pfnGetEngineProcAddrTable_t,
           [ :ze_api_version_t,
             ZESEngineDDITable.ptr ],
           :ze_result_t

  callback :zes_pfnStandbyGetProperties_t,
           [ :zes_standby_handle_t,
             ZESStandbyProperties.ptr ],
           :ze_result_t

  callback :zes_pfnStandbyGetMode_t,
           [ :zes_standby_handle_t,
             :pointer ],
           :ze_result_t

  callback :zes_pfnStandbySetMode_t,
           [ :zes_standby_handle_t,
             :zes_standby_promo_mode_t ],
           :ze_result_t

  class ZESStandbyDDITable < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnStandbyGetProperties_t,
           :pfnGetMode, :zes_pfnStandbyGetMode_t,
           :pfnSetMode, :zes_pfnStandbySetMode_t
  end
  typedef ZESStandbyDDITable.by_value, :zes_standby_dditable_t

  callback :zes_pfnGetStandbyProcAddrTable_t,
           [ :ze_api_version_t,
             ZESStandbyDDITable.ptr ],
           :ze_result_t

  callback :zes_pfnFirmwareGetProperties_t,
           [ :zes_firmware_handle_t,
             ZESFirmwareProperties.ptr ],
           :ze_result_t

  callback :zes_pfnFirmwareFlash_t,
           [ :zes_firmware_handle_t,
             :pointer,
             :uint32 ],
           :ze_result_t

  callback :zes_pfnFirmwareGetFlashProgress_t,
           [ :zes_firmware_handle_t,
             :pointer ],
           :ze_result_t

  callback :zes_pfnFirmwareGetConsoleLogs_t,
           [ :zes_firmware_handle_t,
             :pointer,
             :pointer ],
           :ze_result_t

  class ZESFirmwareDDITable < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnFirmwareGetProperties_t,
           :pfnFlash, :zes_pfnFirmwareFlash_t,
           :pfnGetFlashProgress, :zes_pfnFirmwareGetFlashProgress_t,
           :pfnGetConsoleLogs, :zes_pfnFirmwareGetConsoleLogs_t
  end
  typedef ZESFirmwareDDITable.by_value, :zes_firmware_dditable_t

  callback :zes_pfnGetFirmwareProcAddrTable_t,
           [ :ze_api_version_t,
             ZESFirmwareDDITable.ptr ],
           :ze_result_t

  callback :zes_pfnFirmwareGetSecurityVersionExp_t,
           [ :zes_firmware_handle_t,
             :pointer ],
           :ze_result_t

  callback :zes_pfnFirmwareSetSecurityVersionExp_t,
           [ :zes_firmware_handle_t ],
           :ze_result_t

  class ZESFirmwareExpDDITable < FFI::ZEStruct
    layout :pfnGetSecurityVersionExp, :zes_pfnFirmwareGetSecurityVersionExp_t,
           :pfnSetSecurityVersionExp, :zes_pfnFirmwareSetSecurityVersionExp_t
  end
  typedef ZESFirmwareExpDDITable.by_value, :zes_firmware_exp_dditable_t

  callback :zes_pfnGetFirmwareExpProcAddrTable_t,
           [ :ze_api_version_t,
             ZESFirmwareExpDDITable.ptr ],
           :ze_result_t

  callback :zes_pfnMemoryGetProperties_t,
           [ :zes_mem_handle_t,
             ZESMemProperties.ptr ],
           :ze_result_t

  callback :zes_pfnMemoryGetState_t,
           [ :zes_mem_handle_t,
             ZESMemState.ptr ],
           :ze_result_t

  callback :zes_pfnMemoryGetBandwidth_t,
           [ :zes_mem_handle_t,
             ZESMemBandwidth.ptr ],
           :ze_result_t

  class ZESMemoryDDITable < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnMemoryGetProperties_t,
           :pfnGetState, :zes_pfnMemoryGetState_t,
           :pfnGetBandwidth, :zes_pfnMemoryGetBandwidth_t
  end
  typedef ZESMemoryDDITable.by_value, :zes_memory_dditable_t

  callback :zes_pfnGetMemoryProcAddrTable_t,
           [ :ze_api_version_t,
             ZESMemoryDDITable.ptr ],
           :ze_result_t

  callback :zes_pfnFabricPortGetProperties_t,
           [ :zes_fabric_port_handle_t,
             ZESFabricPortProperties.ptr ],
           :ze_result_t

  callback :zes_pfnFabricPortGetLinkType_t,
           [ :zes_fabric_port_handle_t,
             ZESFabricLinkType.ptr ],
           :ze_result_t

  callback :zes_pfnFabricPortGetConfig_t,
           [ :zes_fabric_port_handle_t,
             ZESFabricPortConfig.ptr ],
           :ze_result_t

  callback :zes_pfnFabricPortSetConfig_t,
           [ :zes_fabric_port_handle_t,
             ZESFabricPortConfig.ptr ],
           :ze_result_t

  callback :zes_pfnFabricPortGetState_t,
           [ :zes_fabric_port_handle_t,
             ZESFabricPortState.ptr ],
           :ze_result_t

  callback :zes_pfnFabricPortGetThroughput_t,
           [ :zes_fabric_port_handle_t,
             ZESFabricPortThroughput.ptr ],
           :ze_result_t

  callback :zes_pfnFabricPortGetFabricErrorCounters_t,
           [ :zes_fabric_port_handle_t,
             ZESFabricPortErrorCounters.ptr ],
           :ze_result_t

  callback :zes_pfnFabricPortGetMultiPortThroughput_t,
           [ :zes_device_handle_t,
             :uint32,
             :pointer,
             :pointer ],
           :ze_result_t

  class ZESFabricPortDDITable < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnFabricPortGetProperties_t,
           :pfnGetLinkType, :zes_pfnFabricPortGetLinkType_t,
           :pfnGetConfig, :zes_pfnFabricPortGetConfig_t,
           :pfnSetConfig, :zes_pfnFabricPortSetConfig_t,
           :pfnGetState, :zes_pfnFabricPortGetState_t,
           :pfnGetThroughput, :zes_pfnFabricPortGetThroughput_t,
           :pfnGetFabricErrorCounters, :zes_pfnFabricPortGetFabricErrorCounters_t,
           :pfnGetMultiPortThroughput, :zes_pfnFabricPortGetMultiPortThroughput_t
  end
  typedef ZESFabricPortDDITable.by_value, :zes_fabric_port_dditable_t

  callback :zes_pfnGetFabricPortProcAddrTable_t,
           [ :ze_api_version_t,
             ZESFabricPortDDITable.ptr ],
           :ze_result_t

  callback :zes_pfnTemperatureGetProperties_t,
           [ :zes_temp_handle_t,
             ZESTempProperties.ptr ],
           :ze_result_t

  callback :zes_pfnTemperatureGetConfig_t,
           [ :zes_temp_handle_t,
             ZESTempConfig.ptr ],
           :ze_result_t

  callback :zes_pfnTemperatureSetConfig_t,
           [ :zes_temp_handle_t,
             ZESTempConfig.ptr ],
           :ze_result_t

  callback :zes_pfnTemperatureGetState_t,
           [ :zes_temp_handle_t,
             :pointer ],
           :ze_result_t

  class ZESTemperatureDDITable < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnTemperatureGetProperties_t,
           :pfnGetConfig, :zes_pfnTemperatureGetConfig_t,
           :pfnSetConfig, :zes_pfnTemperatureSetConfig_t,
           :pfnGetState, :zes_pfnTemperatureGetState_t
  end
  typedef ZESTemperatureDDITable.by_value, :zes_temperature_dditable_t

  callback :zes_pfnGetTemperatureProcAddrTable_t,
           [ :ze_api_version_t,
             ZESTemperatureDDITable.ptr ],
           :ze_result_t

  callback :zes_pfnPsuGetProperties_t,
           [ :zes_psu_handle_t,
             ZESPsuProperties.ptr ],
           :ze_result_t

  callback :zes_pfnPsuGetState_t,
           [ :zes_psu_handle_t,
             ZESPsuState.ptr ],
           :ze_result_t

  class ZESPsuDDITable < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnPsuGetProperties_t,
           :pfnGetState, :zes_pfnPsuGetState_t
  end
  typedef ZESPsuDDITable.by_value, :zes_psu_dditable_t

  callback :zes_pfnGetPsuProcAddrTable_t,
           [ :ze_api_version_t,
             ZESPsuDDITable.ptr ],
           :ze_result_t

  callback :zes_pfnFanGetProperties_t,
           [ :zes_fan_handle_t,
             ZESFanProperties.ptr ],
           :ze_result_t

  callback :zes_pfnFanGetConfig_t,
           [ :zes_fan_handle_t,
             ZESFanConfig.ptr ],
           :ze_result_t

  callback :zes_pfnFanSetDefaultMode_t,
           [ :zes_fan_handle_t ],
           :ze_result_t

  callback :zes_pfnFanSetFixedSpeedMode_t,
           [ :zes_fan_handle_t,
             ZESFanSpeed.ptr ],
           :ze_result_t

  callback :zes_pfnFanSetSpeedTableMode_t,
           [ :zes_fan_handle_t,
             ZESFanSpeedTable.ptr ],
           :ze_result_t

  callback :zes_pfnFanGetState_t,
           [ :zes_fan_handle_t,
             :zes_fan_speed_units_t,
             :pointer ],
           :ze_result_t

  class ZESFanDDITable < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnFanGetProperties_t,
           :pfnGetConfig, :zes_pfnFanGetConfig_t,
           :pfnSetDefaultMode, :zes_pfnFanSetDefaultMode_t,
           :pfnSetFixedSpeedMode, :zes_pfnFanSetFixedSpeedMode_t,
           :pfnSetSpeedTableMode, :zes_pfnFanSetSpeedTableMode_t,
           :pfnGetState, :zes_pfnFanGetState_t
  end
  typedef ZESFanDDITable.by_value, :zes_fan_dditable_t

  callback :zes_pfnGetFanProcAddrTable_t,
           [ :ze_api_version_t,
             ZESFanDDITable.ptr ],
           :ze_result_t

  callback :zes_pfnLedGetProperties_t,
           [ :zes_led_handle_t,
             ZESLedProperties.ptr ],
           :ze_result_t

  callback :zes_pfnLedGetState_t,
           [ :zes_led_handle_t,
             ZESLedState.ptr ],
           :ze_result_t

  callback :zes_pfnLedSetState_t,
           [ :zes_led_handle_t,
             :ze_bool_t ],
           :ze_result_t

  callback :zes_pfnLedSetColor_t,
           [ :zes_led_handle_t,
             ZESLedColor.ptr ],
           :ze_result_t

  class ZESLedDDITable < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnLedGetProperties_t,
           :pfnGetState, :zes_pfnLedGetState_t,
           :pfnSetState, :zes_pfnLedSetState_t,
           :pfnSetColor, :zes_pfnLedSetColor_t
  end
  typedef ZESLedDDITable.by_value, :zes_led_dditable_t

  callback :zes_pfnGetLedProcAddrTable_t,
           [ :ze_api_version_t,
             ZESLedDDITable.ptr ],
           :ze_result_t

  callback :zes_pfnRasGetProperties_t,
           [ :zes_ras_handle_t,
             ZESRasProperties.ptr ],
           :ze_result_t

  callback :zes_pfnRasGetConfig_t,
           [ :zes_ras_handle_t,
             ZESRasConfig.ptr ],
           :ze_result_t

  callback :zes_pfnRasSetConfig_t,
           [ :zes_ras_handle_t,
             ZESRasConfig.ptr ],
           :ze_result_t

  callback :zes_pfnRasGetState_t,
           [ :zes_ras_handle_t,
             :ze_bool_t,
             ZESRasState.ptr ],
           :ze_result_t

  class ZESRasDDITable < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnRasGetProperties_t,
           :pfnGetConfig, :zes_pfnRasGetConfig_t,
           :pfnSetConfig, :zes_pfnRasSetConfig_t,
           :pfnGetState, :zes_pfnRasGetState_t
  end
  typedef ZESRasDDITable.by_value, :zes_ras_dditable_t

  callback :zes_pfnGetRasProcAddrTable_t,
           [ :ze_api_version_t,
             ZESRasDDITable.ptr ],
           :ze_result_t

  callback :zes_pfnRasGetStateExp_t,
           [ :zes_ras_handle_t,
             :pointer,
             ZESRasStateExp.ptr ],
           :ze_result_t

  callback :zes_pfnRasClearStateExp_t,
           [ :zes_ras_handle_t,
             :zes_ras_error_category_exp_t ],
           :ze_result_t

  class ZESRasExpDDITable < FFI::ZEStruct
    layout :pfnGetStateExp, :zes_pfnRasGetStateExp_t,
           :pfnClearStateExp, :zes_pfnRasClearStateExp_t
  end
  typedef ZESRasExpDDITable.by_value, :zes_ras_exp_dditable_t

  callback :zes_pfnGetRasExpProcAddrTable_t,
           [ :ze_api_version_t,
             ZESRasExpDDITable.ptr ],
           :ze_result_t

  callback :zes_pfnDiagnosticsGetProperties_t,
           [ :zes_diag_handle_t,
             ZESDiagProperties.ptr ],
           :ze_result_t

  callback :zes_pfnDiagnosticsGetTests_t,
           [ :zes_diag_handle_t,
             :pointer,
             ZESDiagTest.ptr ],
           :ze_result_t

  callback :zes_pfnDiagnosticsRunTests_t,
           [ :zes_diag_handle_t,
             :uint32,
             :uint32,
             :pointer ],
           :ze_result_t

  class ZESDiagnosticsDDITable < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnDiagnosticsGetProperties_t,
           :pfnGetTests, :zes_pfnDiagnosticsGetTests_t,
           :pfnRunTests, :zes_pfnDiagnosticsRunTests_t
  end
  typedef ZESDiagnosticsDDITable.by_value, :zes_diagnostics_dditable_t

  callback :zes_pfnGetDiagnosticsProcAddrTable_t,
           [ :ze_api_version_t,
             ZESDiagnosticsDDITable.ptr ],
           :ze_result_t

  callback :zes_pfnVFManagementGetVFPropertiesExp_t,
           [ :zes_vf_handle_t,
             ZESVfExpProperties.ptr ],
           :ze_result_t

  callback :zes_pfnVFManagementGetVFMemoryUtilizationExp_t,
           [ :zes_vf_handle_t,
             :pointer,
             ZESVfUtilMemExp.ptr ],
           :ze_result_t

  callback :zes_pfnVFManagementGetVFEngineUtilizationExp_t,
           [ :zes_vf_handle_t,
             :pointer,
             ZESVfUtilEngineExp.ptr ],
           :ze_result_t

  callback :zes_pfnVFManagementSetVFTelemetryModeExp_t,
           [ :zes_vf_handle_t,
             :zes_vf_info_util_exp_flags_t,
             :ze_bool_t ],
           :ze_result_t

  callback :zes_pfnVFManagementSetVFTelemetrySamplingIntervalExp_t,
           [ :zes_vf_handle_t,
             :zes_vf_info_util_exp_flags_t,
             :uint64 ],
           :ze_result_t

  callback :zes_pfnVFManagementGetVFCapabilitiesExp_t,
           [ :zes_vf_handle_t,
             ZESVfExpCapabilities.ptr ],
           :ze_result_t

  callback :zes_pfnVFManagementGetVFMemoryUtilizationExp2_t,
           [ :zes_vf_handle_t,
             :pointer,
             ZESVfUtilMemExp2.ptr ],
           :ze_result_t

  callback :zes_pfnVFManagementGetVFEngineUtilizationExp2_t,
           [ :zes_vf_handle_t,
             :pointer,
             ZESVfUtilEngineExp2.ptr ],
           :ze_result_t

  callback :zes_pfnVFManagementGetVFCapabilitiesExp2_t,
           [ :zes_vf_handle_t,
             ZESVfExp2Capabilities.ptr ],
           :ze_result_t

  class ZESVfManagementExpDDITable < FFI::ZEStruct
    layout :pfnGetVFPropertiesExp, :zes_pfnVFManagementGetVFPropertiesExp_t,
           :pfnGetVFMemoryUtilizationExp, :zes_pfnVFManagementGetVFMemoryUtilizationExp_t,
           :pfnGetVFEngineUtilizationExp, :zes_pfnVFManagementGetVFEngineUtilizationExp_t,
           :pfnSetVFTelemetryModeExp, :zes_pfnVFManagementSetVFTelemetryModeExp_t,
           :pfnSetVFTelemetrySamplingIntervalExp, :zes_pfnVFManagementSetVFTelemetrySamplingIntervalExp_t,
           :pfnGetVFCapabilitiesExp, :zes_pfnVFManagementGetVFCapabilitiesExp_t,
           :pfnGetVFMemoryUtilizationExp2, :zes_pfnVFManagementGetVFMemoryUtilizationExp2_t,
           :pfnGetVFEngineUtilizationExp2, :zes_pfnVFManagementGetVFEngineUtilizationExp2_t,
           :pfnGetVFCapabilitiesExp2, :zes_pfnVFManagementGetVFCapabilitiesExp2_t
  end
  typedef ZESVfManagementExpDDITable.by_value, :zes_vf_management_exp_dditable_t

  callback :zes_pfnGetVFManagementExpProcAddrTable_t,
           [ :ze_api_version_t,
             ZESVfManagementExpDDITable.ptr ],
           :ze_result_t

  class ZESDDITable < FFI::ZEStruct
    layout :Global, :zes_global_dditable_t,
           :Device, :zes_device_dditable_t,
           :DeviceExp, :zes_device_exp_dditable_t,
           :Driver, :zes_driver_dditable_t,
           :DriverExp, :zes_driver_exp_dditable_t,
           :Overclock, :zes_overclock_dditable_t,
           :Scheduler, :zes_scheduler_dditable_t,
           :PerformanceFactor, :zes_performance_factor_dditable_t,
           :Power, :zes_power_dditable_t,
           :Frequency, :zes_frequency_dditable_t,
           :Engine, :zes_engine_dditable_t,
           :Standby, :zes_standby_dditable_t,
           :Firmware, :zes_firmware_dditable_t,
           :FirmwareExp, :zes_firmware_exp_dditable_t,
           :Memory, :zes_memory_dditable_t,
           :FabricPort, :zes_fabric_port_dditable_t,
           :Temperature, :zes_temperature_dditable_t,
           :Psu, :zes_psu_dditable_t,
           :Fan, :zes_fan_dditable_t,
           :Led, :zes_led_dditable_t,
           :Ras, :zes_ras_dditable_t,
           :RasExp, :zes_ras_exp_dditable_t,
           :Diagnostics, :zes_diagnostics_dditable_t,
           :VFManagementExp, :zes_vf_management_exp_dditable_t
  end
  typedef ZESDDITable.by_value, :zes_dditable_t

  class ZESDDITableDriver < FFI::ZEStruct
    layout :version, :ze_api_version_t,
           :isValidFlag, :uint8,
           :Global, :pointer,
           :Device, :pointer,
           :DeviceExp, :pointer,
           :Driver, :pointer,
           :DriverExp, :pointer,
           :Overclock, :pointer,
           :Scheduler, :pointer,
           :PerformanceFactor, :pointer,
           :Power, :pointer,
           :Frequency, :pointer,
           :Engine, :pointer,
           :Standby, :pointer,
           :Firmware, :pointer,
           :FirmwareExp, :pointer,
           :Memory, :pointer,
           :FabricPort, :pointer,
           :Temperature, :pointer,
           :Psu, :pointer,
           :Fan, :pointer,
           :Led, :pointer,
           :Ras, :pointer,
           :RasExp, :pointer,
           :Diagnostics, :pointer,
           :VFManagementExp, :pointer
  end
  typedef ZESDDITableDriver.by_value, :zes_dditable_driver_t

  class ZESGlobalDDITableT15 < FFI::ZEStruct
    layout :pfnInit, :zes_pfnInit_t
  end
  typedef ZESGlobalDDITableT15.by_value, :zes_global_dditable_t_1_5

  class ZESDeviceDDITableT10 < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnDeviceGetProperties_t,
           :pfnGetState, :zes_pfnDeviceGetState_t,
           :pfnReset, :zes_pfnDeviceReset_t,
           :pfnProcessesGetState, :zes_pfnDeviceProcessesGetState_t,
           :pfnPciGetProperties, :zes_pfnDevicePciGetProperties_t,
           :pfnPciGetState, :zes_pfnDevicePciGetState_t,
           :pfnPciGetBars, :zes_pfnDevicePciGetBars_t,
           :pfnPciGetStats, :zes_pfnDevicePciGetStats_t,
           :pfnEnumDiagnosticTestSuites, :zes_pfnDeviceEnumDiagnosticTestSuites_t,
           :pfnEnumEngineGroups, :zes_pfnDeviceEnumEngineGroups_t,
           :pfnEventRegister, :zes_pfnDeviceEventRegister_t,
           :pfnEnumFabricPorts, :zes_pfnDeviceEnumFabricPorts_t,
           :pfnEnumFans, :zes_pfnDeviceEnumFans_t,
           :pfnEnumFirmwares, :zes_pfnDeviceEnumFirmwares_t,
           :pfnEnumFrequencyDomains, :zes_pfnDeviceEnumFrequencyDomains_t,
           :pfnEnumLeds, :zes_pfnDeviceEnumLeds_t,
           :pfnEnumMemoryModules, :zes_pfnDeviceEnumMemoryModules_t,
           :pfnEnumPerformanceFactorDomains, :zes_pfnDeviceEnumPerformanceFactorDomains_t,
           :pfnEnumPowerDomains, :zes_pfnDeviceEnumPowerDomains_t,
           :pfnGetCardPowerDomain, :zes_pfnDeviceGetCardPowerDomain_t,
           :pfnEnumPsus, :zes_pfnDeviceEnumPsus_t,
           :pfnEnumRasErrorSets, :zes_pfnDeviceEnumRasErrorSets_t,
           :pfnEnumSchedulers, :zes_pfnDeviceEnumSchedulers_t,
           :pfnEnumStandbyDomains, :zes_pfnDeviceEnumStandbyDomains_t,
           :pfnEnumTemperatureSensors, :zes_pfnDeviceEnumTemperatureSensors_t
  end
  typedef ZESDeviceDDITableT10.by_value, :zes_device_dditable_t_1_0

  class ZESDeviceDDITableT14 < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnDeviceGetProperties_t,
           :pfnGetState, :zes_pfnDeviceGetState_t,
           :pfnReset, :zes_pfnDeviceReset_t,
           :pfnProcessesGetState, :zes_pfnDeviceProcessesGetState_t,
           :pfnPciGetProperties, :zes_pfnDevicePciGetProperties_t,
           :pfnPciGetState, :zes_pfnDevicePciGetState_t,
           :pfnPciGetBars, :zes_pfnDevicePciGetBars_t,
           :pfnPciGetStats, :zes_pfnDevicePciGetStats_t,
           :pfnEnumDiagnosticTestSuites, :zes_pfnDeviceEnumDiagnosticTestSuites_t,
           :pfnEnumEngineGroups, :zes_pfnDeviceEnumEngineGroups_t,
           :pfnEventRegister, :zes_pfnDeviceEventRegister_t,
           :pfnEnumFabricPorts, :zes_pfnDeviceEnumFabricPorts_t,
           :pfnEnumFans, :zes_pfnDeviceEnumFans_t,
           :pfnEnumFirmwares, :zes_pfnDeviceEnumFirmwares_t,
           :pfnEnumFrequencyDomains, :zes_pfnDeviceEnumFrequencyDomains_t,
           :pfnEnumLeds, :zes_pfnDeviceEnumLeds_t,
           :pfnEnumMemoryModules, :zes_pfnDeviceEnumMemoryModules_t,
           :pfnEnumPerformanceFactorDomains, :zes_pfnDeviceEnumPerformanceFactorDomains_t,
           :pfnEnumPowerDomains, :zes_pfnDeviceEnumPowerDomains_t,
           :pfnGetCardPowerDomain, :zes_pfnDeviceGetCardPowerDomain_t,
           :pfnEnumPsus, :zes_pfnDeviceEnumPsus_t,
           :pfnEnumRasErrorSets, :zes_pfnDeviceEnumRasErrorSets_t,
           :pfnEnumSchedulers, :zes_pfnDeviceEnumSchedulers_t,
           :pfnEnumStandbyDomains, :zes_pfnDeviceEnumStandbyDomains_t,
           :pfnEnumTemperatureSensors, :zes_pfnDeviceEnumTemperatureSensors_t,
           :pfnEccAvailable, :zes_pfnDeviceEccAvailable_t,
           :pfnEccConfigurable, :zes_pfnDeviceEccConfigurable_t,
           :pfnGetEccState, :zes_pfnDeviceGetEccState_t,
           :pfnSetEccState, :zes_pfnDeviceSetEccState_t
  end
  typedef ZESDeviceDDITableT14.by_value, :zes_device_dditable_t_1_4

  class ZESDeviceDDITableT15 < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnDeviceGetProperties_t,
           :pfnGetState, :zes_pfnDeviceGetState_t,
           :pfnReset, :zes_pfnDeviceReset_t,
           :pfnProcessesGetState, :zes_pfnDeviceProcessesGetState_t,
           :pfnPciGetProperties, :zes_pfnDevicePciGetProperties_t,
           :pfnPciGetState, :zes_pfnDevicePciGetState_t,
           :pfnPciGetBars, :zes_pfnDevicePciGetBars_t,
           :pfnPciGetStats, :zes_pfnDevicePciGetStats_t,
           :pfnEnumDiagnosticTestSuites, :zes_pfnDeviceEnumDiagnosticTestSuites_t,
           :pfnEnumEngineGroups, :zes_pfnDeviceEnumEngineGroups_t,
           :pfnEventRegister, :zes_pfnDeviceEventRegister_t,
           :pfnEnumFabricPorts, :zes_pfnDeviceEnumFabricPorts_t,
           :pfnEnumFans, :zes_pfnDeviceEnumFans_t,
           :pfnEnumFirmwares, :zes_pfnDeviceEnumFirmwares_t,
           :pfnEnumFrequencyDomains, :zes_pfnDeviceEnumFrequencyDomains_t,
           :pfnEnumLeds, :zes_pfnDeviceEnumLeds_t,
           :pfnEnumMemoryModules, :zes_pfnDeviceEnumMemoryModules_t,
           :pfnEnumPerformanceFactorDomains, :zes_pfnDeviceEnumPerformanceFactorDomains_t,
           :pfnEnumPowerDomains, :zes_pfnDeviceEnumPowerDomains_t,
           :pfnGetCardPowerDomain, :zes_pfnDeviceGetCardPowerDomain_t,
           :pfnEnumPsus, :zes_pfnDeviceEnumPsus_t,
           :pfnEnumRasErrorSets, :zes_pfnDeviceEnumRasErrorSets_t,
           :pfnEnumSchedulers, :zes_pfnDeviceEnumSchedulers_t,
           :pfnEnumStandbyDomains, :zes_pfnDeviceEnumStandbyDomains_t,
           :pfnEnumTemperatureSensors, :zes_pfnDeviceEnumTemperatureSensors_t,
           :pfnEccAvailable, :zes_pfnDeviceEccAvailable_t,
           :pfnEccConfigurable, :zes_pfnDeviceEccConfigurable_t,
           :pfnGetEccState, :zes_pfnDeviceGetEccState_t,
           :pfnSetEccState, :zes_pfnDeviceSetEccState_t,
           :pfnGet, :zes_pfnDeviceGet_t,
           :pfnSetOverclockWaiver, :zes_pfnDeviceSetOverclockWaiver_t,
           :pfnGetOverclockDomains, :zes_pfnDeviceGetOverclockDomains_t,
           :pfnGetOverclockControls, :zes_pfnDeviceGetOverclockControls_t,
           :pfnResetOverclockSettings, :zes_pfnDeviceResetOverclockSettings_t,
           :pfnReadOverclockState, :zes_pfnDeviceReadOverclockState_t,
           :pfnEnumOverclockDomains, :zes_pfnDeviceEnumOverclockDomains_t
  end
  typedef ZESDeviceDDITableT15.by_value, :zes_device_dditable_t_1_5

  class ZESDeviceDDITableT17 < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnDeviceGetProperties_t,
           :pfnGetState, :zes_pfnDeviceGetState_t,
           :pfnReset, :zes_pfnDeviceReset_t,
           :pfnProcessesGetState, :zes_pfnDeviceProcessesGetState_t,
           :pfnPciGetProperties, :zes_pfnDevicePciGetProperties_t,
           :pfnPciGetState, :zes_pfnDevicePciGetState_t,
           :pfnPciGetBars, :zes_pfnDevicePciGetBars_t,
           :pfnPciGetStats, :zes_pfnDevicePciGetStats_t,
           :pfnEnumDiagnosticTestSuites, :zes_pfnDeviceEnumDiagnosticTestSuites_t,
           :pfnEnumEngineGroups, :zes_pfnDeviceEnumEngineGroups_t,
           :pfnEventRegister, :zes_pfnDeviceEventRegister_t,
           :pfnEnumFabricPorts, :zes_pfnDeviceEnumFabricPorts_t,
           :pfnEnumFans, :zes_pfnDeviceEnumFans_t,
           :pfnEnumFirmwares, :zes_pfnDeviceEnumFirmwares_t,
           :pfnEnumFrequencyDomains, :zes_pfnDeviceEnumFrequencyDomains_t,
           :pfnEnumLeds, :zes_pfnDeviceEnumLeds_t,
           :pfnEnumMemoryModules, :zes_pfnDeviceEnumMemoryModules_t,
           :pfnEnumPerformanceFactorDomains, :zes_pfnDeviceEnumPerformanceFactorDomains_t,
           :pfnEnumPowerDomains, :zes_pfnDeviceEnumPowerDomains_t,
           :pfnGetCardPowerDomain, :zes_pfnDeviceGetCardPowerDomain_t,
           :pfnEnumPsus, :zes_pfnDeviceEnumPsus_t,
           :pfnEnumRasErrorSets, :zes_pfnDeviceEnumRasErrorSets_t,
           :pfnEnumSchedulers, :zes_pfnDeviceEnumSchedulers_t,
           :pfnEnumStandbyDomains, :zes_pfnDeviceEnumStandbyDomains_t,
           :pfnEnumTemperatureSensors, :zes_pfnDeviceEnumTemperatureSensors_t,
           :pfnEccAvailable, :zes_pfnDeviceEccAvailable_t,
           :pfnEccConfigurable, :zes_pfnDeviceEccConfigurable_t,
           :pfnGetEccState, :zes_pfnDeviceGetEccState_t,
           :pfnSetEccState, :zes_pfnDeviceSetEccState_t,
           :pfnGet, :zes_pfnDeviceGet_t,
           :pfnSetOverclockWaiver, :zes_pfnDeviceSetOverclockWaiver_t,
           :pfnGetOverclockDomains, :zes_pfnDeviceGetOverclockDomains_t,
           :pfnGetOverclockControls, :zes_pfnDeviceGetOverclockControls_t,
           :pfnResetOverclockSettings, :zes_pfnDeviceResetOverclockSettings_t,
           :pfnReadOverclockState, :zes_pfnDeviceReadOverclockState_t,
           :pfnEnumOverclockDomains, :zes_pfnDeviceEnumOverclockDomains_t,
           :pfnResetExt, :zes_pfnDeviceResetExt_t
  end
  typedef ZESDeviceDDITableT17.by_value, :zes_device_dditable_t_1_7

  class ZESDeviceExpDDITableT11 < FFI::ZEStruct
    layout :pfnEnumEnabledVFExp, :zes_pfnDeviceEnumEnabledVFExp_t
  end
  typedef ZESDeviceExpDDITableT11.by_value, :zes_device_exp_dditable_t_1_1

  class ZESDeviceExpDDITableT19 < FFI::ZEStruct
    layout :pfnGetSubDevicePropertiesExp, :zes_pfnDeviceGetSubDevicePropertiesExp_t,
           :pfnEnumActiveVFExp, :zes_pfnDeviceEnumActiveVFExp_t,
           :pfnEnumEnabledVFExp, :zes_pfnDeviceEnumEnabledVFExp_t
  end
  typedef ZESDeviceExpDDITableT19.by_value, :zes_device_exp_dditable_t_1_9

  class ZESDriverDDITableT10 < FFI::ZEStruct
    layout :pfnEventListen, :zes_pfnDriverEventListen_t
  end
  typedef ZESDriverDDITableT10.by_value, :zes_driver_dditable_t_1_0

  class ZESDriverDDITableT11 < FFI::ZEStruct
    layout :pfnEventListen, :zes_pfnDriverEventListen_t,
           :pfnEventListenEx, :zes_pfnDriverEventListenEx_t
  end
  typedef ZESDriverDDITableT11.by_value, :zes_driver_dditable_t_1_1

  class ZESDriverDDITableT15 < FFI::ZEStruct
    layout :pfnEventListen, :zes_pfnDriverEventListen_t,
           :pfnEventListenEx, :zes_pfnDriverEventListenEx_t,
           :pfnGet, :zes_pfnDriverGet_t
  end
  typedef ZESDriverDDITableT15.by_value, :zes_driver_dditable_t_1_5

  class ZESDriverDDITableT18 < FFI::ZEStruct
    layout :pfnEventListen, :zes_pfnDriverEventListen_t,
           :pfnEventListenEx, :zes_pfnDriverEventListenEx_t,
           :pfnGet, :zes_pfnDriverGet_t,
           :pfnGetExtensionProperties, :zes_pfnDriverGetExtensionProperties_t,
           :pfnGetExtensionFunctionAddress, :zes_pfnDriverGetExtensionFunctionAddress_t
  end
  typedef ZESDriverDDITableT18.by_value, :zes_driver_dditable_t_1_8

  class ZESDriverExpDDITableT19 < FFI::ZEStruct
    layout :pfnGetDeviceByUuidExp, :zes_pfnDriverGetDeviceByUuidExp_t
  end
  typedef ZESDriverExpDDITableT19.by_value, :zes_driver_exp_dditable_t_1_9

  class ZESOverclockDDITableT15 < FFI::ZEStruct
    layout :pfnGetDomainProperties, :zes_pfnOverclockGetDomainProperties_t,
           :pfnGetDomainVFProperties, :zes_pfnOverclockGetDomainVFProperties_t,
           :pfnGetDomainControlProperties, :zes_pfnOverclockGetDomainControlProperties_t,
           :pfnGetControlCurrentValue, :zes_pfnOverclockGetControlCurrentValue_t,
           :pfnGetControlPendingValue, :zes_pfnOverclockGetControlPendingValue_t,
           :pfnSetControlUserValue, :zes_pfnOverclockSetControlUserValue_t,
           :pfnGetControlState, :zes_pfnOverclockGetControlState_t,
           :pfnGetVFPointValues, :zes_pfnOverclockGetVFPointValues_t,
           :pfnSetVFPointValues, :zes_pfnOverclockSetVFPointValues_t
  end
  typedef ZESOverclockDDITableT15.by_value, :zes_overclock_dditable_t_1_5

  class ZESSchedulerDDITableT10 < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnSchedulerGetProperties_t,
           :pfnGetCurrentMode, :zes_pfnSchedulerGetCurrentMode_t,
           :pfnGetTimeoutModeProperties, :zes_pfnSchedulerGetTimeoutModeProperties_t,
           :pfnGetTimesliceModeProperties, :zes_pfnSchedulerGetTimesliceModeProperties_t,
           :pfnSetTimeoutMode, :zes_pfnSchedulerSetTimeoutMode_t,
           :pfnSetTimesliceMode, :zes_pfnSchedulerSetTimesliceMode_t,
           :pfnSetExclusiveMode, :zes_pfnSchedulerSetExclusiveMode_t,
           :pfnSetComputeUnitDebugMode, :zes_pfnSchedulerSetComputeUnitDebugMode_t
  end
  typedef ZESSchedulerDDITableT10.by_value, :zes_scheduler_dditable_t_1_0

  class ZESPerformanceFactorDDITableT10 < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnPerformanceFactorGetProperties_t,
           :pfnGetConfig, :zes_pfnPerformanceFactorGetConfig_t,
           :pfnSetConfig, :zes_pfnPerformanceFactorSetConfig_t
  end
  typedef ZESPerformanceFactorDDITableT10.by_value, :zes_performance_factor_dditable_t_1_0

  class ZESPowerDDITableT10 < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnPowerGetProperties_t,
           :pfnGetEnergyCounter, :zes_pfnPowerGetEnergyCounter_t,
           :pfnGetLimits, :zes_pfnPowerGetLimits_t,
           :pfnSetLimits, :zes_pfnPowerSetLimits_t,
           :pfnGetEnergyThreshold, :zes_pfnPowerGetEnergyThreshold_t,
           :pfnSetEnergyThreshold, :zes_pfnPowerSetEnergyThreshold_t,
           :pfnGetLimitsExt, :zes_pfnPowerGetLimitsExt_t,
           :pfnSetLimitsExt, :zes_pfnPowerSetLimitsExt_t
  end
  typedef ZESPowerDDITableT10.by_value, :zes_power_dditable_t_1_0

  class ZESFrequencyDDITableT10 < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnFrequencyGetProperties_t,
           :pfnGetAvailableClocks, :zes_pfnFrequencyGetAvailableClocks_t,
           :pfnGetRange, :zes_pfnFrequencyGetRange_t,
           :pfnSetRange, :zes_pfnFrequencySetRange_t,
           :pfnGetState, :zes_pfnFrequencyGetState_t,
           :pfnGetThrottleTime, :zes_pfnFrequencyGetThrottleTime_t,
           :pfnOcGetCapabilities, :zes_pfnFrequencyOcGetCapabilities_t,
           :pfnOcGetFrequencyTarget, :zes_pfnFrequencyOcGetFrequencyTarget_t,
           :pfnOcSetFrequencyTarget, :zes_pfnFrequencyOcSetFrequencyTarget_t,
           :pfnOcGetVoltageTarget, :zes_pfnFrequencyOcGetVoltageTarget_t,
           :pfnOcSetVoltageTarget, :zes_pfnFrequencyOcSetVoltageTarget_t,
           :pfnOcSetMode, :zes_pfnFrequencyOcSetMode_t,
           :pfnOcGetMode, :zes_pfnFrequencyOcGetMode_t,
           :pfnOcGetIccMax, :zes_pfnFrequencyOcGetIccMax_t,
           :pfnOcSetIccMax, :zes_pfnFrequencyOcSetIccMax_t,
           :pfnOcGetTjMax, :zes_pfnFrequencyOcGetTjMax_t,
           :pfnOcSetTjMax, :zes_pfnFrequencyOcSetTjMax_t
  end
  typedef ZESFrequencyDDITableT10.by_value, :zes_frequency_dditable_t_1_0

  class ZESEngineDDITableT10 < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnEngineGetProperties_t
  end
  typedef ZESEngineDDITableT10.by_value, :zes_engine_dditable_t_1_0

  class ZESEngineDDITableT17 < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnEngineGetProperties_t,
           :pfnGetActivity, :zes_pfnEngineGetActivity_t,
           :pfnGetActivityExt, :zes_pfnEngineGetActivityExt_t
  end
  typedef ZESEngineDDITableT17.by_value, :zes_engine_dditable_t_1_7

  class ZESStandbyDDITableT10 < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnStandbyGetProperties_t,
           :pfnGetMode, :zes_pfnStandbyGetMode_t,
           :pfnSetMode, :zes_pfnStandbySetMode_t
  end
  typedef ZESStandbyDDITableT10.by_value, :zes_standby_dditable_t_1_0

  class ZESFirmwareDDITableT10 < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnFirmwareGetProperties_t,
           :pfnFlash, :zes_pfnFirmwareFlash_t
  end
  typedef ZESFirmwareDDITableT10.by_value, :zes_firmware_dditable_t_1_0

  class ZESFirmwareDDITableT18 < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnFirmwareGetProperties_t,
           :pfnFlash, :zes_pfnFirmwareFlash_t,
           :pfnGetFlashProgress, :zes_pfnFirmwareGetFlashProgress_t
  end
  typedef ZESFirmwareDDITableT18.by_value, :zes_firmware_dditable_t_1_8

  class ZESFirmwareDDITableT19 < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnFirmwareGetProperties_t,
           :pfnFlash, :zes_pfnFirmwareFlash_t,
           :pfnGetFlashProgress, :zes_pfnFirmwareGetFlashProgress_t,
           :pfnGetConsoleLogs, :zes_pfnFirmwareGetConsoleLogs_t
  end
  typedef ZESFirmwareDDITableT19.by_value, :zes_firmware_dditable_t_1_9

  class ZESFirmwareExpDDITableT19 < FFI::ZEStruct
    layout :pfnGetSecurityVersionExp, :zes_pfnFirmwareGetSecurityVersionExp_t,
           :pfnSetSecurityVersionExp, :zes_pfnFirmwareSetSecurityVersionExp_t
  end
  typedef ZESFirmwareExpDDITableT19.by_value, :zes_firmware_exp_dditable_t_1_9

  class ZESMemoryDDITableT10 < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnMemoryGetProperties_t,
           :pfnGetState, :zes_pfnMemoryGetState_t,
           :pfnGetBandwidth, :zes_pfnMemoryGetBandwidth_t
  end
  typedef ZESMemoryDDITableT10.by_value, :zes_memory_dditable_t_1_0

  class ZESFabricPortDDITableT10 < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnFabricPortGetProperties_t,
           :pfnGetLinkType, :zes_pfnFabricPortGetLinkType_t,
           :pfnGetConfig, :zes_pfnFabricPortGetConfig_t,
           :pfnSetConfig, :zes_pfnFabricPortSetConfig_t,
           :pfnGetState, :zes_pfnFabricPortGetState_t,
           :pfnGetThroughput, :zes_pfnFabricPortGetThroughput_t
  end
  typedef ZESFabricPortDDITableT10.by_value, :zes_fabric_port_dditable_t_1_0

  class ZESFabricPortDDITableT17 < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnFabricPortGetProperties_t,
           :pfnGetLinkType, :zes_pfnFabricPortGetLinkType_t,
           :pfnGetConfig, :zes_pfnFabricPortGetConfig_t,
           :pfnSetConfig, :zes_pfnFabricPortSetConfig_t,
           :pfnGetState, :zes_pfnFabricPortGetState_t,
           :pfnGetThroughput, :zes_pfnFabricPortGetThroughput_t,
           :pfnGetFabricErrorCounters, :zes_pfnFabricPortGetFabricErrorCounters_t,
           :pfnGetMultiPortThroughput, :zes_pfnFabricPortGetMultiPortThroughput_t
  end
  typedef ZESFabricPortDDITableT17.by_value, :zes_fabric_port_dditable_t_1_7

  class ZESTemperatureDDITableT10 < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnTemperatureGetProperties_t,
           :pfnGetConfig, :zes_pfnTemperatureGetConfig_t,
           :pfnSetConfig, :zes_pfnTemperatureSetConfig_t,
           :pfnGetState, :zes_pfnTemperatureGetState_t
  end
  typedef ZESTemperatureDDITableT10.by_value, :zes_temperature_dditable_t_1_0

  class ZESPsuDDITableT10 < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnPsuGetProperties_t,
           :pfnGetState, :zes_pfnPsuGetState_t
  end
  typedef ZESPsuDDITableT10.by_value, :zes_psu_dditable_t_1_0

  class ZESFanDDITableT10 < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnFanGetProperties_t,
           :pfnGetConfig, :zes_pfnFanGetConfig_t,
           :pfnSetDefaultMode, :zes_pfnFanSetDefaultMode_t,
           :pfnSetFixedSpeedMode, :zes_pfnFanSetFixedSpeedMode_t,
           :pfnSetSpeedTableMode, :zes_pfnFanSetSpeedTableMode_t,
           :pfnGetState, :zes_pfnFanGetState_t
  end
  typedef ZESFanDDITableT10.by_value, :zes_fan_dditable_t_1_0

  class ZESLedDDITableT10 < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnLedGetProperties_t,
           :pfnGetState, :zes_pfnLedGetState_t,
           :pfnSetState, :zes_pfnLedSetState_t,
           :pfnSetColor, :zes_pfnLedSetColor_t
  end
  typedef ZESLedDDITableT10.by_value, :zes_led_dditable_t_1_0

  class ZESRasDDITableT10 < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnRasGetProperties_t,
           :pfnGetConfig, :zes_pfnRasGetConfig_t,
           :pfnSetConfig, :zes_pfnRasSetConfig_t,
           :pfnGetState, :zes_pfnRasGetState_t
  end
  typedef ZESRasDDITableT10.by_value, :zes_ras_dditable_t_1_0

  class ZESRasExpDDITableT10 < FFI::ZEStruct
    layout :pfnGetStateExp, :zes_pfnRasGetStateExp_t,
           :pfnClearStateExp, :zes_pfnRasClearStateExp_t
  end
  typedef ZESRasExpDDITableT10.by_value, :zes_ras_exp_dditable_t_1_0

  class ZESDiagnosticsDDITableT10 < FFI::ZEStruct
    layout :pfnGetProperties, :zes_pfnDiagnosticsGetProperties_t,
           :pfnGetTests, :zes_pfnDiagnosticsGetTests_t,
           :pfnRunTests, :zes_pfnDiagnosticsRunTests_t
  end
  typedef ZESDiagnosticsDDITableT10.by_value, :zes_diagnostics_dditable_t_1_0

  class ZESVfManagementExpDDITableT11 < FFI::ZEStruct
    layout :pfnGetVFCapabilitiesExp, :zes_pfnVFManagementGetVFCapabilitiesExp_t,
           :pfnGetVFMemoryUtilizationExp2, :zes_pfnVFManagementGetVFMemoryUtilizationExp2_t,
           :pfnGetVFEngineUtilizationExp2, :zes_pfnVFManagementGetVFEngineUtilizationExp2_t
  end
  typedef ZESVfManagementExpDDITableT11.by_value, :zes_vf_management_exp_dditable_t_1_1

  class ZESVfManagementExpDDITableT112 < FFI::ZEStruct
    layout :pfnGetVFCapabilitiesExp, :zes_pfnVFManagementGetVFCapabilitiesExp_t,
           :pfnGetVFMemoryUtilizationExp2, :zes_pfnVFManagementGetVFMemoryUtilizationExp2_t,
           :pfnGetVFEngineUtilizationExp2, :zes_pfnVFManagementGetVFEngineUtilizationExp2_t,
           :pfnGetVFCapabilitiesExp2, :zes_pfnVFManagementGetVFCapabilitiesExp2_t
  end
  typedef ZESVfManagementExpDDITableT112.by_value, :zes_vf_management_exp_dditable_t_1_12

  class ZESVfManagementExpDDITableT19 < FFI::ZEStruct
    layout :pfnGetVFPropertiesExp, :zes_pfnVFManagementGetVFPropertiesExp_t,
           :pfnGetVFMemoryUtilizationExp, :zes_pfnVFManagementGetVFMemoryUtilizationExp_t,
           :pfnGetVFEngineUtilizationExp, :zes_pfnVFManagementGetVFEngineUtilizationExp_t,
           :pfnSetVFTelemetryModeExp, :zes_pfnVFManagementSetVFTelemetryModeExp_t,
           :pfnSetVFTelemetrySamplingIntervalExp, :zes_pfnVFManagementSetVFTelemetrySamplingIntervalExp_t,
           :pfnGetVFCapabilitiesExp, :zes_pfnVFManagementGetVFCapabilitiesExp_t,
           :pfnGetVFMemoryUtilizationExp2, :zes_pfnVFManagementGetVFMemoryUtilizationExp2_t,
           :pfnGetVFEngineUtilizationExp2, :zes_pfnVFManagementGetVFEngineUtilizationExp2_t,
           :pfnGetVFCapabilitiesExp2, :zes_pfnVFManagementGetVFCapabilitiesExp2_t
  end
  typedef ZESVfManagementExpDDITableT19.by_value, :zes_vf_management_exp_dditable_t_1_9

  class ZELTracerDesc < FFI::ZEStruct
    layout :stype, :zel_structure_type_t,
           :pNext, :pointer,
           :pUserData, :pointer

    def initialize(*args)
      super(*args)
      if(args.length == 0)
        self[:stype] = :ZEL_STRUCTURE_TYPE_TRACER_DESC
      end
    end
  end
  typedef ZELTracerDesc.by_value, :zel_tracer_desc_t

  callback :zel_pfnTracerCreate_t,
           [ ZELTracerDesc.ptr,
             :pointer ],
           :ze_result_t

  callback :zel_pfnTracerDestroy_t,
           [ :zel_tracer_handle_t ],
           :ze_result_t

  callback :zel_pfnTracerSetPrologues_t,
           [ :zel_tracer_handle_t,
             :pointer ],
           :ze_result_t

  callback :zel_pfnTracerSetEpilogues_t,
           [ :zel_tracer_handle_t,
             :pointer ],
           :ze_result_t

  callback :zel_pfnTracerSetEnabled_t,
           [ :zel_tracer_handle_t,
             :ze_bool_t ],
           :ze_result_t

  class ZELTracerDDITable < FFI::ZEStruct
    layout :pfnCreate, :zel_pfnTracerCreate_t,
           :pfnDestroy, :zel_pfnTracerDestroy_t,
           :pfnSetPrologues, :zel_pfnTracerSetPrologues_t,
           :pfnSetEpilogues, :zel_pfnTracerSetEpilogues_t,
           :pfnSetEnabled, :zel_pfnTracerSetEnabled_t
  end
  typedef ZELTracerDDITable.by_value, :zel_tracer_dditable_t

  callback :zel_pfnGetTracerApiProcAddrTable_t,
           [ :ze_api_version_t,
             ZELTracerDDITable.ptr ],
           :ze_result_t

  class ZELTracingDDITable < FFI::ZEStruct
    layout :Tracer, :zel_tracer_dditable_t
  end
  typedef ZELTracingDDITable.by_value, :zel_tracing_dditable_t

  class ZELTracerDDITableT10 < FFI::ZEStruct
    layout :pfnCreate, :zel_pfnTracerCreate_t,
           :pfnDestroy, :zel_pfnTracerDestroy_t,
           :pfnSetPrologues, :zel_pfnTracerSetPrologues_t,
           :pfnSetEpilogues, :zel_pfnTracerSetEpilogues_t,
           :pfnSetEnabled, :zel_pfnTracerSetEnabled_t
  end
  typedef ZELTracerDDITableT10.by_value, :zel_tracer_dditable_t_1_0

  class ZEInitDriversParams < FFI::ZEStruct
    layout :ppCount, :pointer,
           :pphDrivers, :pointer,
           :pdesc, :pointer
  end
  typedef ZEInitDriversParams.by_value, :ze_init_drivers_params_t

  callback :ze_pfnInitDriversCb_t,
           [ ZEInitDriversParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZERtasBuilderCreateExtParams < FFI::ZEStruct
    layout :phDriver, :pointer,
           :ppDescriptor, :pointer,
           :pphBuilder, :pointer
  end
  typedef ZERtasBuilderCreateExtParams.by_value, :ze_rtas_builder_create_ext_params_t

  callback :ze_pfnRTASBuilderCreateExtCb_t,
           [ ZERtasBuilderCreateExtParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZERtasBuilderGetBuildPropertiesExtParams < FFI::ZEStruct
    layout :phBuilder, :pointer,
           :ppBuildOpDescriptor, :pointer,
           :ppProperties, :pointer
  end
  typedef ZERtasBuilderGetBuildPropertiesExtParams.by_value, :ze_rtas_builder_get_build_properties_ext_params_t

  callback :ze_pfnRTASBuilderGetBuildPropertiesExtCb_t,
           [ ZERtasBuilderGetBuildPropertiesExtParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZERtasBuilderBuildExtParams < FFI::ZEStruct
    layout :phBuilder, :pointer,
           :ppBuildOpDescriptor, :pointer,
           :ppScratchBuffer, :pointer,
           :pscratchBufferSizeBytes, :pointer,
           :ppRtasBuffer, :pointer,
           :prtasBufferSizeBytes, :pointer,
           :phParallelOperation, :pointer,
           :ppBuildUserPtr, :pointer,
           :ppBounds, :pointer,
           :ppRtasBufferSizeBytes, :pointer
  end
  typedef ZERtasBuilderBuildExtParams.by_value, :ze_rtas_builder_build_ext_params_t

  callback :ze_pfnRTASBuilderBuildExtCb_t,
           [ ZERtasBuilderBuildExtParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZERtasBuilderCommandListAppendCopyExtParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :pdstptr, :pointer,
           :psrcptr, :pointer,
           :psize, :pointer,
           :phSignalEvent, :pointer,
           :pnumWaitEvents, :pointer,
           :pphWaitEvents, :pointer
  end
  typedef ZERtasBuilderCommandListAppendCopyExtParams.by_value, :ze_rtas_builder_command_list_append_copy_ext_params_t

  callback :ze_pfnRTASBuilderCommandListAppendCopyExtCb_t,
           [ ZERtasBuilderCommandListAppendCopyExtParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZERtasBuilderDestroyExtParams < FFI::ZEStruct
    layout :phBuilder, :pointer
  end
  typedef ZERtasBuilderDestroyExtParams.by_value, :ze_rtas_builder_destroy_ext_params_t

  callback :ze_pfnRTASBuilderDestroyExtCb_t,
           [ ZERtasBuilderDestroyExtParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZERtasBuilderCreateExpParams < FFI::ZEStruct
    layout :phDriver, :pointer,
           :ppDescriptor, :pointer,
           :pphBuilder, :pointer
  end
  typedef ZERtasBuilderCreateExpParams.by_value, :ze_rtas_builder_create_exp_params_t

  callback :ze_pfnRTASBuilderCreateExpCb_t,
           [ ZERtasBuilderCreateExpParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZERtasBuilderGetBuildPropertiesExpParams < FFI::ZEStruct
    layout :phBuilder, :pointer,
           :ppBuildOpDescriptor, :pointer,
           :ppProperties, :pointer
  end
  typedef ZERtasBuilderGetBuildPropertiesExpParams.by_value, :ze_rtas_builder_get_build_properties_exp_params_t

  callback :ze_pfnRTASBuilderGetBuildPropertiesExpCb_t,
           [ ZERtasBuilderGetBuildPropertiesExpParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZERtasBuilderBuildExpParams < FFI::ZEStruct
    layout :phBuilder, :pointer,
           :ppBuildOpDescriptor, :pointer,
           :ppScratchBuffer, :pointer,
           :pscratchBufferSizeBytes, :pointer,
           :ppRtasBuffer, :pointer,
           :prtasBufferSizeBytes, :pointer,
           :phParallelOperation, :pointer,
           :ppBuildUserPtr, :pointer,
           :ppBounds, :pointer,
           :ppRtasBufferSizeBytes, :pointer
  end
  typedef ZERtasBuilderBuildExpParams.by_value, :ze_rtas_builder_build_exp_params_t

  callback :ze_pfnRTASBuilderBuildExpCb_t,
           [ ZERtasBuilderBuildExpParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZERtasBuilderDestroyExpParams < FFI::ZEStruct
    layout :phBuilder, :pointer
  end
  typedef ZERtasBuilderDestroyExpParams.by_value, :ze_rtas_builder_destroy_exp_params_t

  callback :ze_pfnRTASBuilderDestroyExpCb_t,
           [ ZERtasBuilderDestroyExpParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZERtasParallelOperationCreateExtParams < FFI::ZEStruct
    layout :phDriver, :pointer,
           :pphParallelOperation, :pointer
  end
  typedef ZERtasParallelOperationCreateExtParams.by_value, :ze_rtas_parallel_operation_create_ext_params_t

  callback :ze_pfnRTASParallelOperationCreateExtCb_t,
           [ ZERtasParallelOperationCreateExtParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZERtasParallelOperationGetPropertiesExtParams < FFI::ZEStruct
    layout :phParallelOperation, :pointer,
           :ppProperties, :pointer
  end
  typedef ZERtasParallelOperationGetPropertiesExtParams.by_value, :ze_rtas_parallel_operation_get_properties_ext_params_t

  callback :ze_pfnRTASParallelOperationGetPropertiesExtCb_t,
           [ ZERtasParallelOperationGetPropertiesExtParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZERtasParallelOperationJoinExtParams < FFI::ZEStruct
    layout :phParallelOperation, :pointer
  end
  typedef ZERtasParallelOperationJoinExtParams.by_value, :ze_rtas_parallel_operation_join_ext_params_t

  callback :ze_pfnRTASParallelOperationJoinExtCb_t,
           [ ZERtasParallelOperationJoinExtParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZERtasParallelOperationDestroyExtParams < FFI::ZEStruct
    layout :phParallelOperation, :pointer
  end
  typedef ZERtasParallelOperationDestroyExtParams.by_value, :ze_rtas_parallel_operation_destroy_ext_params_t

  callback :ze_pfnRTASParallelOperationDestroyExtCb_t,
           [ ZERtasParallelOperationDestroyExtParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZERtasParallelOperationCreateExpParams < FFI::ZEStruct
    layout :phDriver, :pointer,
           :pphParallelOperation, :pointer
  end
  typedef ZERtasParallelOperationCreateExpParams.by_value, :ze_rtas_parallel_operation_create_exp_params_t

  callback :ze_pfnRTASParallelOperationCreateExpCb_t,
           [ ZERtasParallelOperationCreateExpParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZERtasParallelOperationGetPropertiesExpParams < FFI::ZEStruct
    layout :phParallelOperation, :pointer,
           :ppProperties, :pointer
  end
  typedef ZERtasParallelOperationGetPropertiesExpParams.by_value, :ze_rtas_parallel_operation_get_properties_exp_params_t

  callback :ze_pfnRTASParallelOperationGetPropertiesExpCb_t,
           [ ZERtasParallelOperationGetPropertiesExpParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZERtasParallelOperationJoinExpParams < FFI::ZEStruct
    layout :phParallelOperation, :pointer
  end
  typedef ZERtasParallelOperationJoinExpParams.by_value, :ze_rtas_parallel_operation_join_exp_params_t

  callback :ze_pfnRTASParallelOperationJoinExpCb_t,
           [ ZERtasParallelOperationJoinExpParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZERtasParallelOperationDestroyExpParams < FFI::ZEStruct
    layout :phParallelOperation, :pointer
  end
  typedef ZERtasParallelOperationDestroyExpParams.by_value, :ze_rtas_parallel_operation_destroy_exp_params_t

  callback :ze_pfnRTASParallelOperationDestroyExpCb_t,
           [ ZERtasParallelOperationDestroyExpParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEDriverGetExtensionFunctionAddressParams < FFI::ZEStruct
    layout :phDriver, :pointer,
           :pname, :pointer,
           :pppFunctionAddress, :pointer
  end
  typedef ZEDriverGetExtensionFunctionAddressParams.by_value, :ze_driver_get_extension_function_address_params_t

  callback :ze_pfnDriverGetExtensionFunctionAddressCb_t,
           [ ZEDriverGetExtensionFunctionAddressParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEDriverRtasFormatCompatibilityCheckExtParams < FFI::ZEStruct
    layout :phDriver, :pointer,
           :prtasFormatA, :pointer,
           :prtasFormatB, :pointer
  end
  typedef ZEDriverRtasFormatCompatibilityCheckExtParams.by_value, :ze_driver_rtas_format_compatibility_check_ext_params_t

  callback :ze_pfnDriverRTASFormatCompatibilityCheckExtCb_t,
           [ ZEDriverRtasFormatCompatibilityCheckExtParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEDriverGetLastErrorDescriptionParams < FFI::ZEStruct
    layout :phDriver, :pointer,
           :pppString, :pointer
  end
  typedef ZEDriverGetLastErrorDescriptionParams.by_value, :ze_driver_get_last_error_description_params_t

  callback :ze_pfnDriverGetLastErrorDescriptionCb_t,
           [ ZEDriverGetLastErrorDescriptionParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEDriverRtasFormatCompatibilityCheckExpParams < FFI::ZEStruct
    layout :phDriver, :pointer,
           :prtasFormatA, :pointer,
           :prtasFormatB, :pointer
  end
  typedef ZEDriverRtasFormatCompatibilityCheckExpParams.by_value, :ze_driver_rtas_format_compatibility_check_exp_params_t

  callback :ze_pfnDriverRTASFormatCompatibilityCheckExpCb_t,
           [ ZEDriverRtasFormatCompatibilityCheckExpParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEDeviceGetGlobalTimestampsParams < FFI::ZEStruct
    layout :phDevice, :pointer,
           :phostTimestamp, :pointer,
           :pdeviceTimestamp, :pointer
  end
  typedef ZEDeviceGetGlobalTimestampsParams.by_value, :ze_device_get_global_timestamps_params_t

  callback :ze_pfnDeviceGetGlobalTimestampsCb_t,
           [ ZEDeviceGetGlobalTimestampsParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEDeviceImportExternalSemaphoreExtParams < FFI::ZEStruct
    layout :phDevice, :pointer,
           :pdesc, :pointer,
           :pphSemaphore, :pointer
  end
  typedef ZEDeviceImportExternalSemaphoreExtParams.by_value, :ze_device_import_external_semaphore_ext_params_t

  callback :ze_pfnDeviceImportExternalSemaphoreExtCb_t,
           [ ZEDeviceImportExternalSemaphoreExtParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEDeviceReleaseExternalSemaphoreExtParams < FFI::ZEStruct
    layout :phSemaphore, :pointer
  end
  typedef ZEDeviceReleaseExternalSemaphoreExtParams.by_value, :ze_device_release_external_semaphore_ext_params_t

  callback :ze_pfnDeviceReleaseExternalSemaphoreExtCb_t,
           [ ZEDeviceReleaseExternalSemaphoreExtParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEDeviceGetVectorWidthPropertiesExtParams < FFI::ZEStruct
    layout :phDevice, :pointer,
           :ppCount, :pointer,
           :ppVectorWidthProperties, :pointer
  end
  typedef ZEDeviceGetVectorWidthPropertiesExtParams.by_value, :ze_device_get_vector_width_properties_ext_params_t

  callback :ze_pfnDeviceGetVectorWidthPropertiesExtCb_t,
           [ ZEDeviceGetVectorWidthPropertiesExtParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEDeviceReserveCacheExtParams < FFI::ZEStruct
    layout :phDevice, :pointer,
           :pcacheLevel, :pointer,
           :pcacheReservationSize, :pointer
  end
  typedef ZEDeviceReserveCacheExtParams.by_value, :ze_device_reserve_cache_ext_params_t

  callback :ze_pfnDeviceReserveCacheExtCb_t,
           [ ZEDeviceReserveCacheExtParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEDeviceSetCacheAdviceExtParams < FFI::ZEStruct
    layout :phDevice, :pointer,
           :pptr, :pointer,
           :pregionSize, :pointer,
           :pcacheRegion, :pointer
  end
  typedef ZEDeviceSetCacheAdviceExtParams.by_value, :ze_device_set_cache_advice_ext_params_t

  callback :ze_pfnDeviceSetCacheAdviceExtCb_t,
           [ ZEDeviceSetCacheAdviceExtParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEDevicePciGetPropertiesExtParams < FFI::ZEStruct
    layout :phDevice, :pointer,
           :ppPciProperties, :pointer
  end
  typedef ZEDevicePciGetPropertiesExtParams.by_value, :ze_device_pci_get_properties_ext_params_t

  callback :ze_pfnDevicePciGetPropertiesExtCb_t,
           [ ZEDevicePciGetPropertiesExtParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEDeviceGetFabricVertexExpParams < FFI::ZEStruct
    layout :phDevice, :pointer,
           :pphVertex, :pointer
  end
  typedef ZEDeviceGetFabricVertexExpParams.by_value, :ze_device_get_fabric_vertex_exp_params_t

  callback :ze_pfnDeviceGetFabricVertexExpCb_t,
           [ ZEDeviceGetFabricVertexExpParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEDeviceGetRootDeviceParams < FFI::ZEStruct
    layout :phDevice, :pointer,
           :pphRootDevice, :pointer
  end
  typedef ZEDeviceGetRootDeviceParams.by_value, :ze_device_get_root_device_params_t

  callback :ze_pfnDeviceGetRootDeviceCb_t,
           [ ZEDeviceGetRootDeviceParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEContextCreateExParams < FFI::ZEStruct
    layout :phDriver, :pointer,
           :pdesc, :pointer,
           :pnumDevices, :pointer,
           :pphDevices, :pointer,
           :pphContext, :pointer
  end
  typedef ZEContextCreateExParams.by_value, :ze_context_create_ex_params_t

  callback :ze_pfnContextCreateExCb_t,
           [ ZEContextCreateExParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandQueueGetOrdinalParams < FFI::ZEStruct
    layout :phCommandQueue, :pointer,
           :ppOrdinal, :pointer
  end
  typedef ZECommandQueueGetOrdinalParams.by_value, :ze_command_queue_get_ordinal_params_t

  callback :ze_pfnCommandQueueGetOrdinalCb_t,
           [ ZECommandQueueGetOrdinalParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandQueueGetIndexParams < FFI::ZEStruct
    layout :phCommandQueue, :pointer,
           :ppIndex, :pointer
  end
  typedef ZECommandQueueGetIndexParams.by_value, :ze_command_queue_get_index_params_t

  callback :ze_pfnCommandQueueGetIndexCb_t,
           [ ZECommandQueueGetIndexParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListGetNextCommandIdWithKernelsExpParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :pdesc, :pointer,
           :pnumKernels, :pointer,
           :pphKernels, :pointer,
           :ppCommandId, :pointer
  end
  typedef ZECommandListGetNextCommandIdWithKernelsExpParams.by_value, :ze_command_list_get_next_command_id_with_kernels_exp_params_t

  callback :ze_pfnCommandListGetNextCommandIdWithKernelsExpCb_t,
           [ ZECommandListGetNextCommandIdWithKernelsExpParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListUpdateMutableCommandKernelsExpParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :pnumKernels, :pointer,
           :ppCommandId, :pointer,
           :pphKernels, :pointer
  end
  typedef ZECommandListUpdateMutableCommandKernelsExpParams.by_value, :ze_command_list_update_mutable_command_kernels_exp_params_t

  callback :ze_pfnCommandListUpdateMutableCommandKernelsExpCb_t,
           [ ZECommandListUpdateMutableCommandKernelsExpParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListAppendSignalExternalSemaphoreExtParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :pnumSemaphores, :pointer,
           :pphSemaphores, :pointer,
           :psignalParams, :pointer,
           :phSignalEvent, :pointer,
           :pnumWaitEvents, :pointer,
           :pphWaitEvents, :pointer
  end
  typedef ZECommandListAppendSignalExternalSemaphoreExtParams.by_value, :ze_command_list_append_signal_external_semaphore_ext_params_t

  callback :ze_pfnCommandListAppendSignalExternalSemaphoreExtCb_t,
           [ ZECommandListAppendSignalExternalSemaphoreExtParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListAppendWaitExternalSemaphoreExtParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :pnumSemaphores, :pointer,
           :pphSemaphores, :pointer,
           :pwaitParams, :pointer,
           :phSignalEvent, :pointer,
           :pnumWaitEvents, :pointer,
           :pphWaitEvents, :pointer
  end
  typedef ZECommandListAppendWaitExternalSemaphoreExtParams.by_value, :ze_command_list_append_wait_external_semaphore_ext_params_t

  callback :ze_pfnCommandListAppendWaitExternalSemaphoreExtCb_t,
           [ ZECommandListAppendWaitExternalSemaphoreExtParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListAppendImageCopyToMemoryExtParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :pdstptr, :pointer,
           :phSrcImage, :pointer,
           :ppSrcRegion, :pointer,
           :pdestRowPitch, :pointer,
           :pdestSlicePitch, :pointer,
           :phSignalEvent, :pointer,
           :pnumWaitEvents, :pointer,
           :pphWaitEvents, :pointer
  end
  typedef ZECommandListAppendImageCopyToMemoryExtParams.by_value, :ze_command_list_append_image_copy_to_memory_ext_params_t

  callback :ze_pfnCommandListAppendImageCopyToMemoryExtCb_t,
           [ ZECommandListAppendImageCopyToMemoryExtParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListAppendImageCopyFromMemoryExtParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :phDstImage, :pointer,
           :psrcptr, :pointer,
           :ppDstRegion, :pointer,
           :psrcRowPitch, :pointer,
           :psrcSlicePitch, :pointer,
           :phSignalEvent, :pointer,
           :pnumWaitEvents, :pointer,
           :pphWaitEvents, :pointer
  end
  typedef ZECommandListAppendImageCopyFromMemoryExtParams.by_value, :ze_command_list_append_image_copy_from_memory_ext_params_t

  callback :ze_pfnCommandListAppendImageCopyFromMemoryExtCb_t,
           [ ZECommandListAppendImageCopyFromMemoryExtParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListHostSynchronizeParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :ptimeout, :pointer
  end
  typedef ZECommandListHostSynchronizeParams.by_value, :ze_command_list_host_synchronize_params_t

  callback :ze_pfnCommandListHostSynchronizeCb_t,
           [ ZECommandListHostSynchronizeParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListCreateCloneExpParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :pphClonedCommandList, :pointer
  end
  typedef ZECommandListCreateCloneExpParams.by_value, :ze_command_list_create_clone_exp_params_t

  callback :ze_pfnCommandListCreateCloneExpCb_t,
           [ ZECommandListCreateCloneExpParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListGetDeviceHandleParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :pphDevice, :pointer
  end
  typedef ZECommandListGetDeviceHandleParams.by_value, :ze_command_list_get_device_handle_params_t

  callback :ze_pfnCommandListGetDeviceHandleCb_t,
           [ ZECommandListGetDeviceHandleParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListGetContextHandleParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :pphContext, :pointer
  end
  typedef ZECommandListGetContextHandleParams.by_value, :ze_command_list_get_context_handle_params_t

  callback :ze_pfnCommandListGetContextHandleCb_t,
           [ ZECommandListGetContextHandleParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListGetOrdinalParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :ppOrdinal, :pointer
  end
  typedef ZECommandListGetOrdinalParams.by_value, :ze_command_list_get_ordinal_params_t

  callback :ze_pfnCommandListGetOrdinalCb_t,
           [ ZECommandListGetOrdinalParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListImmediateGetIndexParams < FFI::ZEStruct
    layout :phCommandListImmediate, :pointer,
           :ppIndex, :pointer
  end
  typedef ZECommandListImmediateGetIndexParams.by_value, :ze_command_list_immediate_get_index_params_t

  callback :ze_pfnCommandListImmediateGetIndexCb_t,
           [ ZECommandListImmediateGetIndexParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListIsImmediateParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :ppIsImmediate, :pointer
  end
  typedef ZECommandListIsImmediateParams.by_value, :ze_command_list_is_immediate_params_t

  callback :ze_pfnCommandListIsImmediateCb_t,
           [ ZECommandListIsImmediateParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListImmediateAppendCommandListsExpParams < FFI::ZEStruct
    layout :phCommandListImmediate, :pointer,
           :pnumCommandLists, :pointer,
           :pphCommandLists, :pointer,
           :phSignalEvent, :pointer,
           :pnumWaitEvents, :pointer,
           :pphWaitEvents, :pointer
  end
  typedef ZECommandListImmediateAppendCommandListsExpParams.by_value, :ze_command_list_immediate_append_command_lists_exp_params_t

  callback :ze_pfnCommandListImmediateAppendCommandListsExpCb_t,
           [ ZECommandListImmediateAppendCommandListsExpParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListGetNextCommandIdExpParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :pdesc, :pointer,
           :ppCommandId, :pointer
  end
  typedef ZECommandListGetNextCommandIdExpParams.by_value, :ze_command_list_get_next_command_id_exp_params_t

  callback :ze_pfnCommandListGetNextCommandIdExpCb_t,
           [ ZECommandListGetNextCommandIdExpParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListUpdateMutableCommandsExpParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :pdesc, :pointer
  end
  typedef ZECommandListUpdateMutableCommandsExpParams.by_value, :ze_command_list_update_mutable_commands_exp_params_t

  callback :ze_pfnCommandListUpdateMutableCommandsExpCb_t,
           [ ZECommandListUpdateMutableCommandsExpParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListUpdateMutableCommandSignalEventExpParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :pcommandId, :pointer,
           :phSignalEvent, :pointer
  end
  typedef ZECommandListUpdateMutableCommandSignalEventExpParams.by_value, :ze_command_list_update_mutable_command_signal_event_exp_params_t

  callback :ze_pfnCommandListUpdateMutableCommandSignalEventExpCb_t,
           [ ZECommandListUpdateMutableCommandSignalEventExpParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZECommandListUpdateMutableCommandWaitEventsExpParams < FFI::ZEStruct
    layout :phCommandList, :pointer,
           :pcommandId, :pointer,
           :pnumWaitEvents, :pointer,
           :pphWaitEvents, :pointer
  end
  typedef ZECommandListUpdateMutableCommandWaitEventsExpParams.by_value, :ze_command_list_update_mutable_command_wait_events_exp_params_t

  callback :ze_pfnCommandListUpdateMutableCommandWaitEventsExpCb_t,
           [ ZECommandListUpdateMutableCommandWaitEventsExpParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEEventQueryTimestampsExpParams < FFI::ZEStruct
    layout :phEvent, :pointer,
           :phDevice, :pointer,
           :ppCount, :pointer,
           :ppTimestamps, :pointer
  end
  typedef ZEEventQueryTimestampsExpParams.by_value, :ze_event_query_timestamps_exp_params_t

  callback :ze_pfnEventQueryTimestampsExpCb_t,
           [ ZEEventQueryTimestampsExpParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEEventQueryKernelTimestampsExtParams < FFI::ZEStruct
    layout :phEvent, :pointer,
           :phDevice, :pointer,
           :ppCount, :pointer,
           :ppResults, :pointer
  end
  typedef ZEEventQueryKernelTimestampsExtParams.by_value, :ze_event_query_kernel_timestamps_ext_params_t

  callback :ze_pfnEventQueryKernelTimestampsExtCb_t,
           [ ZEEventQueryKernelTimestampsExtParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEEventGetEventPoolParams < FFI::ZEStruct
    layout :phEvent, :pointer,
           :pphEventPool, :pointer
  end
  typedef ZEEventGetEventPoolParams.by_value, :ze_event_get_event_pool_params_t

  callback :ze_pfnEventGetEventPoolCb_t,
           [ ZEEventGetEventPoolParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEEventGetSignalScopeParams < FFI::ZEStruct
    layout :phEvent, :pointer,
           :ppSignalScope, :pointer
  end
  typedef ZEEventGetSignalScopeParams.by_value, :ze_event_get_signal_scope_params_t

  callback :ze_pfnEventGetSignalScopeCb_t,
           [ ZEEventGetSignalScopeParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEEventGetWaitScopeParams < FFI::ZEStruct
    layout :phEvent, :pointer,
           :ppWaitScope, :pointer
  end
  typedef ZEEventGetWaitScopeParams.by_value, :ze_event_get_wait_scope_params_t

  callback :ze_pfnEventGetWaitScopeCb_t,
           [ ZEEventGetWaitScopeParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEEventPoolPutIpcHandleParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :phIpc, :pointer
  end
  typedef ZEEventPoolPutIpcHandleParams.by_value, :ze_event_pool_put_ipc_handle_params_t

  callback :ze_pfnEventPoolPutIpcHandleCb_t,
           [ ZEEventPoolPutIpcHandleParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEEventPoolGetContextHandleParams < FFI::ZEStruct
    layout :phEventPool, :pointer,
           :pphContext, :pointer
  end
  typedef ZEEventPoolGetContextHandleParams.by_value, :ze_event_pool_get_context_handle_params_t

  callback :ze_pfnEventPoolGetContextHandleCb_t,
           [ ZEEventPoolGetContextHandleParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEEventPoolGetFlagsParams < FFI::ZEStruct
    layout :phEventPool, :pointer,
           :ppFlags, :pointer
  end
  typedef ZEEventPoolGetFlagsParams.by_value, :ze_event_pool_get_flags_params_t

  callback :ze_pfnEventPoolGetFlagsCb_t,
           [ ZEEventPoolGetFlagsParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEImageGetMemoryPropertiesExpParams < FFI::ZEStruct
    layout :phImage, :pointer,
           :ppMemoryProperties, :pointer
  end
  typedef ZEImageGetMemoryPropertiesExpParams.by_value, :ze_image_get_memory_properties_exp_params_t

  callback :ze_pfnImageGetMemoryPropertiesExpCb_t,
           [ ZEImageGetMemoryPropertiesExpParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEImageViewCreateExpParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :phDevice, :pointer,
           :pdesc, :pointer,
           :phImage, :pointer,
           :pphImageView, :pointer
  end
  typedef ZEImageViewCreateExpParams.by_value, :ze_image_view_create_exp_params_t

  callback :ze_pfnImageViewCreateExpCb_t,
           [ ZEImageViewCreateExpParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEImageGetAllocPropertiesExtParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :phImage, :pointer,
           :ppImageAllocProperties, :pointer
  end
  typedef ZEImageGetAllocPropertiesExtParams.by_value, :ze_image_get_alloc_properties_ext_params_t

  callback :ze_pfnImageGetAllocPropertiesExtCb_t,
           [ ZEImageGetAllocPropertiesExtParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEImageViewCreateExtParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :phDevice, :pointer,
           :pdesc, :pointer,
           :phImage, :pointer,
           :pphImageView, :pointer
  end
  typedef ZEImageViewCreateExtParams.by_value, :ze_image_view_create_ext_params_t

  callback :ze_pfnImageViewCreateExtCb_t,
           [ ZEImageViewCreateExtParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEImageGetDeviceOffsetExpParams < FFI::ZEStruct
    layout :phImage, :pointer,
           :ppDeviceOffset, :pointer
  end
  typedef ZEImageGetDeviceOffsetExpParams.by_value, :ze_image_get_device_offset_exp_params_t

  callback :ze_pfnImageGetDeviceOffsetExpCb_t,
           [ ZEImageGetDeviceOffsetExpParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEKernelSetGlobalOffsetExpParams < FFI::ZEStruct
    layout :phKernel, :pointer,
           :poffsetX, :pointer,
           :poffsetY, :pointer,
           :poffsetZ, :pointer
  end
  typedef ZEKernelSetGlobalOffsetExpParams.by_value, :ze_kernel_set_global_offset_exp_params_t

  callback :ze_pfnKernelSetGlobalOffsetExpCb_t,
           [ ZEKernelSetGlobalOffsetExpParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEKernelGetBinaryExpParams < FFI::ZEStruct
    layout :phKernel, :pointer,
           :ppSize, :pointer,
           :ppKernelBinary, :pointer
  end
  typedef ZEKernelGetBinaryExpParams.by_value, :ze_kernel_get_binary_exp_params_t

  callback :ze_pfnKernelGetBinaryExpCb_t,
           [ ZEKernelGetBinaryExpParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEKernelSchedulingHintExpParams < FFI::ZEStruct
    layout :phKernel, :pointer,
           :ppHint, :pointer
  end
  typedef ZEKernelSchedulingHintExpParams.by_value, :ze_kernel_scheduling_hint_exp_params_t

  callback :ze_pfnKernelSchedulingHintExpCb_t,
           [ ZEKernelSchedulingHintExpParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEMemFreeExtParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :ppMemFreeDesc, :pointer,
           :pptr, :pointer
  end
  typedef ZEMemFreeExtParams.by_value, :ze_mem_free_ext_params_t

  callback :ze_pfnMemFreeExtCb_t,
           [ ZEMemFreeExtParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEMemGetIpcHandleFromFileDescriptorExpParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :phandle, :pointer,
           :ppIpcHandle, :pointer
  end
  typedef ZEMemGetIpcHandleFromFileDescriptorExpParams.by_value, :ze_mem_get_ipc_handle_from_file_descriptor_exp_params_t

  callback :ze_pfnMemGetIpcHandleFromFileDescriptorExpCb_t,
           [ ZEMemGetIpcHandleFromFileDescriptorExpParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEMemGetFileDescriptorFromIpcHandleExpParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :pipcHandle, :pointer,
           :ppHandle, :pointer
  end
  typedef ZEMemGetFileDescriptorFromIpcHandleExpParams.by_value, :ze_mem_get_file_descriptor_from_ipc_handle_exp_params_t

  callback :ze_pfnMemGetFileDescriptorFromIpcHandleExpCb_t,
           [ ZEMemGetFileDescriptorFromIpcHandleExpParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEMemPutIpcHandleParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :phandle, :pointer
  end
  typedef ZEMemPutIpcHandleParams.by_value, :ze_mem_put_ipc_handle_params_t

  callback :ze_pfnMemPutIpcHandleCb_t,
           [ ZEMemPutIpcHandleParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEMemSetAtomicAccessAttributeExpParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :phDevice, :pointer,
           :pptr, :pointer,
           :psize, :pointer,
           :pattr, :pointer
  end
  typedef ZEMemSetAtomicAccessAttributeExpParams.by_value, :ze_mem_set_atomic_access_attribute_exp_params_t

  callback :ze_pfnMemSetAtomicAccessAttributeExpCb_t,
           [ ZEMemSetAtomicAccessAttributeExpParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEMemGetAtomicAccessAttributeExpParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :phDevice, :pointer,
           :pptr, :pointer,
           :psize, :pointer,
           :ppAttr, :pointer
  end
  typedef ZEMemGetAtomicAccessAttributeExpParams.by_value, :ze_mem_get_atomic_access_attribute_exp_params_t

  callback :ze_pfnMemGetAtomicAccessAttributeExpCb_t,
           [ ZEMemGetAtomicAccessAttributeExpParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEMemGetPitchFor2dImageParams < FFI::ZEStruct
    layout :phContext, :pointer,
           :phDevice, :pointer,
           :pimageWidth, :pointer,
           :pimageHeight, :pointer,
           :pelementSizeInBytes, :pointer,
           :prowPitch, :pointer
  end
  typedef ZEMemGetPitchFor2dImageParams.by_value, :ze_mem_get_pitch_for2d_image_params_t

  callback :ze_pfnMemGetPitchFor2dImageCb_t,
           [ ZEMemGetPitchFor2dImageParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEModuleInspectLinkageExtParams < FFI::ZEStruct
    layout :ppInspectDesc, :pointer,
           :pnumModules, :pointer,
           :pphModules, :pointer,
           :pphLog, :pointer
  end
  typedef ZEModuleInspectLinkageExtParams.by_value, :ze_module_inspect_linkage_ext_params_t

  callback :ze_pfnModuleInspectLinkageExtCb_t,
           [ ZEModuleInspectLinkageExtParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEFabricEdgeGetExpParams < FFI::ZEStruct
    layout :phVertexA, :pointer,
           :phVertexB, :pointer,
           :ppCount, :pointer,
           :pphEdges, :pointer
  end
  typedef ZEFabricEdgeGetExpParams.by_value, :ze_fabric_edge_get_exp_params_t

  callback :ze_pfnFabricEdgeGetExpCb_t,
           [ ZEFabricEdgeGetExpParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEFabricEdgeGetVerticesExpParams < FFI::ZEStruct
    layout :phEdge, :pointer,
           :pphVertexA, :pointer,
           :pphVertexB, :pointer
  end
  typedef ZEFabricEdgeGetVerticesExpParams.by_value, :ze_fabric_edge_get_vertices_exp_params_t

  callback :ze_pfnFabricEdgeGetVerticesExpCb_t,
           [ ZEFabricEdgeGetVerticesExpParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEFabricEdgeGetPropertiesExpParams < FFI::ZEStruct
    layout :phEdge, :pointer,
           :ppEdgeProperties, :pointer
  end
  typedef ZEFabricEdgeGetPropertiesExpParams.by_value, :ze_fabric_edge_get_properties_exp_params_t

  callback :ze_pfnFabricEdgeGetPropertiesExpCb_t,
           [ ZEFabricEdgeGetPropertiesExpParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEFabricVertexGetExpParams < FFI::ZEStruct
    layout :phDriver, :pointer,
           :ppCount, :pointer,
           :pphVertices, :pointer
  end
  typedef ZEFabricVertexGetExpParams.by_value, :ze_fabric_vertex_get_exp_params_t

  callback :ze_pfnFabricVertexGetExpCb_t,
           [ ZEFabricVertexGetExpParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEFabricVertexGetSubVerticesExpParams < FFI::ZEStruct
    layout :phVertex, :pointer,
           :ppCount, :pointer,
           :pphSubvertices, :pointer
  end
  typedef ZEFabricVertexGetSubVerticesExpParams.by_value, :ze_fabric_vertex_get_sub_vertices_exp_params_t

  callback :ze_pfnFabricVertexGetSubVerticesExpCb_t,
           [ ZEFabricVertexGetSubVerticesExpParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEFabricVertexGetPropertiesExpParams < FFI::ZEStruct
    layout :phVertex, :pointer,
           :ppVertexProperties, :pointer
  end
  typedef ZEFabricVertexGetPropertiesExpParams.by_value, :ze_fabric_vertex_get_properties_exp_params_t

  callback :ze_pfnFabricVertexGetPropertiesExpCb_t,
           [ ZEFabricVertexGetPropertiesExpParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZEFabricVertexGetDeviceExpParams < FFI::ZEStruct
    layout :phVertex, :pointer,
           :pphDevice, :pointer
  end
  typedef ZEFabricVertexGetDeviceExpParams.by_value, :ze_fabric_vertex_get_device_exp_params_t

  callback :ze_pfnFabricVertexGetDeviceExpCb_t,
           [ ZEFabricVertexGetDeviceExpParams.ptr,
             :ze_result_t,
             :pointer,
             :pointer ],
           :void

  class ZELVersion < FFI::ZEStruct
    layout :major, :int,
           :minor, :int,
           :patch, :int
  end
  typedef ZELVersion.by_value, :zel_version_t

  class ZELComponentVersion < FFI::ZEStruct
    layout :component_name, [ :char, ZEL_COMPONENT_STRING_SIZE ],
           :spec_version, :ze_api_version_t,
           :component_lib_version, :zel_version_t
  end
  typedef ZELComponentVersion.by_value, :zel_component_version_t

  callback :zel_loader_teardown_callback_t,
           [  ],
           :void

  callback :zel_application_teardown_callback_t,
           [ :uint32 ],
           :void

  class ZEXWaitOnMemDesc < FFI::ZEStruct
    layout :actionFlag, :zex_wait_on_mem_action_flags_t,
           :waitScope, :zex_mem_action_scope_flags_t
  end
  typedef ZEXWaitOnMemDesc.by_value, :zex_wait_on_mem_desc_t

  class ZEXWriteToMemDesc < FFI::ZEStruct
    layout :writeScope, :zex_mem_action_scope_flags_t
  end
  typedef ZEXWriteToMemDesc.by_value, :zex_write_to_mem_desc_t

  class ZEXIpcCounterBasedEventHandle < FFI::ZEStruct
    prepend Handle
    layout :data, [ :char, ZE_MAX_IPC_HANDLE_SIZE ]
  end
  typedef ZEXIpcCounterBasedEventHandle.by_value, :zex_ipc_counter_based_event_handle_t

  class ZEXDeviceModuleRegisterFileExp < FFI::ZEStruct
    layout :stype, :ze_structure_type_t,
           :pNext, :pointer,
           :registerFileSizesCount, :uint32,
           :registerFileSizes, :pointer
  end
  typedef ZEXDeviceModuleRegisterFileExp.by_value, :zex_device_module_register_file_exp_t

  class ZETypedValue
    def to_s
      case self[:type]
      when :ZET_VALUE_TYPE_UINT32
        self[:value][:ui32].to_s
      when :ZET_VALUE_TYPE_UINT64
        self[:value][:ui64].to_s
      when :ZET_VALUE_TYPE_FLOAT32
        self[:value][:fp32].to_s
      when :ZET_VALUE_TYPE_FLOAT64
        self[:value][:fp64].to_s
      when :ZET_VALUE_TYPE_BOOL8
        self[:value][:b8].to_s
      else
        self[:value][:ui64].to_s
      end
    end
  end
end
