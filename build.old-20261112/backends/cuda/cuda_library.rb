require 'ffi'
module FFI

  class CUDAStruct < Struct
    def self.enclosing_module
      CUDA
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
  class CUDAEnum < Enum
  end
  class CUDAUnion < Union
    def self.enclosing_module
      CUDA
    end
  end
  class CUDABitmask < Bitmask
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
    def cudabitmask(*args)
      generic_enum(FFI::CUDABitmask, *args)
    end
    def cudaenum(*args)
      generic_enum(FFI::CUDAEnum, *args)
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
module CUDA
  CU_COMPUTE_ACCELERATED_TARGET_BASE = 0x10000
  CU_COMPUTE_FAMILY_TARGET_BASE = 0x20000
  CU_TARGET_COMPUTE_90 = 90
  CU_TARGET_COMPUTE_100 = 100
  CU_TARGET_COMPUTE_103 = 103
  CU_TARGET_COMPUTE_110 = 110
  CU_TARGET_COMPUTE_120 = 120
  CU_TARGET_COMPUTE_121 = 121
  CU_TENSOR_MAP_NUM_QWORDS = 16
  CU_IPC_HANDLE_SIZE = 64
  CUDA_IPC_HANDLE_SIZE = 64
  RESOURCE_ABI_EXTERNAL_BYTES = 48
  extend FFI::Library

  module Handle
    def to_s
      s = '{ reserved: "'
      s << self[:reserved].to_a.collect { |v| "\\x%02x" % ((v + 256)%256) }.join
      s << '" }'
    end
  end

  module UUID
    def to_s
      a = self[:bytes].to_a.collect { |v| v < 0 ? 0x100 + v : v }
      s = "{ id: "
      s << "%02x" % a[0]
      s << "%02x" % a[1]
      s << "%02x" % a[2]
      s << "%02x" % a[3]
      s << "-"
      s << "%02x" % a[4]
      s << "%02x" % a[5]
      s << "-"
      s << "%02x" % a[6]
      s << "%02x" % a[7]
      s << "-"
      s << "%02x" % a[8]
      s << "%02x" % a[9]
      s << "-"
      s << "%02x" % a[10]
      s << "%02x" % a[11]
      s << "%02x" % a[12]
      s << "%02x" % a[13]
      s << "%02x" % a[14]
      s << "%02x" % a[15]
      s << " }"
    end
  end

  typedef :uint32, :cuuint32_t
  typedef :uint64, :cuuint64_t
  typedef :pointer, :cu_deviceptr
  typedef :uint32, :cu_deviceptr_v1
  typedef :uint64, :cu_tex_object
  typedef :uint64, :cu_surf_object
  typedef :uint64, :cu_mem_generic_allocation_handle_v1
  typedef :cu_mem_generic_allocation_handle_v1, :cu_mem_generic_allocation_handle
  typedef :uint64, :cu_graph_conditional_handle
  typedef :pointer, :cu_context

  typedef :pointer, :cu_module

  typedef :pointer, :cu_function

  typedef :pointer, :cu_library

  typedef :pointer, :cu_kernel

  typedef :pointer, :cu_array

  typedef :pointer, :cu_mipmapped_array

  typedef :pointer, :cu_texref

  typedef :pointer, :cu_surfref

  typedef :pointer, :cu_event

  typedef :pointer, :cu_stream

  typedef :pointer, :cu_graphics_resource

  typedef :pointer, :cu_external_memory

  typedef :pointer, :cu_external_semaphore

  typedef :pointer, :cu_graph

  typedef :pointer, :cu_graph_node

  typedef :pointer, :cu_graph_exec

  typedef :pointer, :cu_memory_pool

  typedef :pointer, :cu_user_object

  typedef :pointer, :cu_graph_device_node

  typedef :pointer, :cu_async_callback_handle

  typedef :pointer, :cu_green_ctx

  class CUUUID < FFI::CUDAStruct
    prepend UUID
    layout :bytes, [ :char, 16 ]
  end
  typedef CUUUID.by_value, :cu_uuid

  class CUMemFabricHandleV1 < FFI::CUDAStruct
    layout :data, [ :uchar, CU_IPC_HANDLE_SIZE ]
  end
  typedef CUMemFabricHandleV1.by_value, :cu_mem_fabric_handle_v1

  typedef :cu_mem_fabric_handle_v1, :cu_mem_fabric_handle

  class CUIPCEventHandleV1 < FFI::CUDAStruct
    layout :reserved, [ :char, CU_IPC_HANDLE_SIZE ]
  end
  typedef CUIPCEventHandleV1.by_value, :cu_ipcevent_handle_v1

  typedef :cu_ipcevent_handle_v1, :cu_ipcevent_handle

  class CUIPCMemHandleV1 < FFI::CUDAStruct
    layout :reserved, [ :char, CU_IPC_HANDLE_SIZE ]
  end
  typedef CUIPCMemHandleV1.by_value, :cu_ipcmem_handle_v1

  typedef :cu_ipcmem_handle_v1, :cu_ipcmem_handle

  CUIPCMemFlags = cudaenum :cu_ipcmem_flags,
    [ :CU_IPC_MEM_LAZY_ENABLE_PEER_ACCESS, 0x1 ]

  CUMemAttachFlags = cudaenum :cu_mem_attach_flags,
    [ :CU_MEM_ATTACH_GLOBAL, 0x1,
      :CU_MEM_ATTACH_HOST, 0x2,
      :CU_MEM_ATTACH_SINGLE, 0x4 ]

  CUCtxFlags = cudaenum :cu_ctx_flags,
    [ :CU_CTX_SCHED_AUTO, 0x0,
      :CU_CTX_SCHED_SPIN, 0x1,
      :CU_CTX_SCHED_YIELD, 0x2,
      :CU_CTX_SCHED_BLOCKING_SYNC, 0x4,
      :CU_CTX_BLOCKING_SYNC, 0x4,
      :CU_CTX_SCHED_MASK, 0x7,
      :CU_CTX_MAP_HOST, 0x8,
      :CU_CTX_LMEM_RESIZE_TO_MAX, 0x10,
      :CU_CTX_COREDUMP_ENABLE, 0x20,
      :CU_CTX_USER_COREDUMP_ENABLE, 0x40,
      :CU_CTX_SYNC_MEMOPS, 0x80,
      :CU_CTX_FLAGS_MASK, 0xff ]

  CUEventSchedFlags = cudaenum :cu_event_sched_flags,
    [ :CU_EVENT_SCHED_AUTO, 0x0,
      :CU_EVENT_SCHED_SPIN, 0x1,
      :CU_EVENT_SCHED_YIELD, 0x2,
      :CU_EVENT_SCHED_BLOCKING_SYNC, 0x4 ]

  ClEventFlags = cudaenum :cl_event_flags,
    [ :NVCL_EVENT_SCHED_AUTO, 0x0,
      :NVCL_EVENT_SCHED_SPIN, 0x1,
      :NVCL_EVENT_SCHED_YIELD, 0x2,
      :NVCL_EVENT_SCHED_BLOCKING_SYNC, 0x4 ]

  ClContextFlags = cudaenum :cl_context_flags,
    [ :NVCL_CTX_SCHED_AUTO, 0x0,
      :NVCL_CTX_SCHED_SPIN, 0x1,
      :NVCL_CTX_SCHED_YIELD, 0x2,
      :NVCL_CTX_SCHED_BLOCKING_SYNC, 0x4 ]

  CUStreamFlags = cudaenum :cu_stream_flags,
    [ :CU_STREAM_DEFAULT, 0x0,
      :CU_STREAM_NON_BLOCKING, 0x1 ]

  CUEventFlags = cudaenum :cu_event_flags,
    [ :CU_EVENT_DEFAULT, 0x0,
      :CU_EVENT_BLOCKING_SYNC, 0x1,
      :CU_EVENT_DISABLE_TIMING, 0x2,
      :CU_EVENT_INTERPROCESS, 0x4 ]

  CUEventRecordFlags = cudaenum :cu_event_record_flags,
    [ :CU_EVENT_RECORD_DEFAULT, 0x0,
      :CU_EVENT_RECORD_EXTERNAL, 0x1 ]

  CUEventWaitFlags = cudaenum :cu_event_wait_flags,
    [ :CU_EVENT_WAIT_DEFAULT, 0x0,
      :CU_EVENT_WAIT_EXTERNAL, 0x1 ]

  CUStreamWaitValueFlags = cudaenum :cu_stream_wait_value_flags,
    [ :CU_STREAM_WAIT_VALUE_GEQ, 0x0,
      :CU_STREAM_WAIT_VALUE_EQ, 0x1,
      :CU_STREAM_WAIT_VALUE_AND, 0x2,
      :CU_STREAM_WAIT_VALUE_NOR, 0x3,
      :CU_STREAM_WAIT_VALUE_FLUSH, 1 << 30 ]

  CUStreamWriteValueFlags = cudaenum :cu_stream_write_value_flags,
    [ :CU_STREAM_WRITE_VALUE_DEFAULT, 0x0,
      :CU_STREAM_WRITE_VALUE_NO_MEMORY_BARRIER, 0x1 ]

  CUStreamBatchMemOpType = cudaenum :cu_stream_batch_mem_op_type,
    [ :CU_STREAM_MEM_OP_WAIT_VALUE_32, 1,
      :CU_STREAM_MEM_OP_WRITE_VALUE_32, 2,
      :CU_STREAM_MEM_OP_WAIT_VALUE_64, 4,
      :CU_STREAM_MEM_OP_WRITE_VALUE_64, 5,
      :CU_STREAM_MEM_OP_BARRIER, 6,
      :CU_STREAM_MEM_OP_FLUSH_REMOTE_WRITES, 3 ]

  CUStreamMemoryBarrierFlags = cudaenum :cu_stream_memory_barrier_flags,
    [ :CU_STREAM_MEMORY_BARRIER_TYPE_SYS, 0x0,
      :CU_STREAM_MEMORY_BARRIER_TYPE_GPU, 0x1 ]

  class CUStreamBatchMemOpParamsV1 < FFI::CUDAUnion
    layout :operation, :cu_stream_batch_mem_op_type,
           :waitValue, (Class::new(FFI::CUDAStruct) { layout :operation, :cu_stream_batch_mem_op_type, :address, :cu_deviceptr, :_unamed_1, (Class::new(FFI::CUDAUnion) { layout :value, :cuuint32_t, :value64, :cuuint64_t }.by_value), :flags, :uint, :alias, :cu_deviceptr }.by_value),
           :writeValue, (Class::new(FFI::CUDAStruct) { layout :operation, :cu_stream_batch_mem_op_type, :address, :cu_deviceptr, :_unamed_1, (Class::new(FFI::CUDAUnion) { layout :value, :cuuint32_t, :value64, :cuuint64_t }.by_value), :flags, :uint, :alias, :cu_deviceptr }.by_value),
           :flushRemoteWrites, (Class::new(FFI::CUDAStruct) { layout :operation, :cu_stream_batch_mem_op_type, :flags, :uint }.by_value),
           :memoryBarrier, (Class::new(FFI::CUDAStruct) { layout :operation, :cu_stream_batch_mem_op_type, :flags, :uint }.by_value),
           :pad, [ :cuuint64_t, 6 ]
  end
  typedef CUStreamBatchMemOpParamsV1.by_value, :cu_stream_batch_mem_op_params_v1

  class CUDABATCHMEMOPNODEPARAMSV1 < FFI::CUDAStruct
    layout :ctx, :cu_context,
           :count, :uint,
           :paramArray, :pointer,
           :flags, :uint
  end
  typedef CUDABATCHMEMOPNODEPARAMSV1.by_value, :cuda_batchmemopnodeparamsv1

  typedef :cuda_batchmemopnodeparamsv1, :cuda_batchmemopnodeparams

  class CUDABATCHMEMOPNODEPARAMSV2 < FFI::CUDAStruct
    layout :ctx, :cu_context,
           :count, :uint,
           :paramArray, :pointer,
           :flags, :uint
  end
  typedef CUDABATCHMEMOPNODEPARAMSV2.by_value, :cuda_batchmemopnodeparamsv2

  CUOccupancyFlags = cudaenum :cu_occupancy_flags,
    [ :CU_OCCUPANCY_DEFAULT, 0x0,
      :CU_OCCUPANCY_DISABLE_CACHING_OVERRIDE, 0x1 ]

  CUStreamUpdateCaptureDependenciesFlags = cudaenum :cu_stream_update_capture_dependencies_flags,
    [ :CU_STREAM_ADD_CAPTURE_DEPENDENCIES, 0x0,
      :CU_STREAM_SET_CAPTURE_DEPENDENCIES, 0x1 ]

  CUAsyncNotificationType = cudaenum :cu_async_notification_type,
    [ :CU_ASYNC_NOTIFICATION_TYPE_OVER_BUDGET, 0x1 ]

  class CUAsyncNotificationInfo < FFI::CUDAStruct
    layout :type, :cu_async_notification_type,
           :info, (Class::new(FFI::CUDAUnion) { layout :overBudget, (Class::new(FFI::CUDAStruct) { layout :bytesOverBudget, :uint64 }.by_value) }.by_value)
  end
  typedef CUAsyncNotificationInfo.by_value, :cu_async_notification_info

  callback :cu_async_callback,
           [ CUAsyncNotificationInfo.ptr,
             :pointer,
             :cu_async_callback_handle ],
           :void

  CUArrayFormat = cudaenum :cu_array_format,
    [ :CU_AD_FORMAT_UNSIGNED_INT8, 0x1,
      :CU_AD_FORMAT_UNSIGNED_INT16, 0x2,
      :CU_AD_FORMAT_UNSIGNED_INT32, 0x3,
      :CU_AD_FORMAT_SIGNED_INT8, 0x8,
      :CU_AD_FORMAT_SIGNED_INT16, 0x9,
      :CU_AD_FORMAT_SIGNED_INT32, 0xa,
      :CU_AD_FORMAT_HALF, 0x10,
      :CU_AD_FORMAT_FLOAT, 0x20,
      :CU_AD_FORMAT_NV12, 0xb0,
      :CU_AD_FORMAT_UNORM_INT8X1, 0xc0,
      :CU_AD_FORMAT_UNORM_INT8X2, 0xc1,
      :CU_AD_FORMAT_UNORM_INT8X4, 0xc2,
      :CU_AD_FORMAT_UNORM_INT16X1, 0xc3,
      :CU_AD_FORMAT_UNORM_INT16X2, 0xc4,
      :CU_AD_FORMAT_UNORM_INT16X4, 0xc5,
      :CU_AD_FORMAT_SNORM_INT8X1, 0xc6,
      :CU_AD_FORMAT_SNORM_INT8X2, 0xc7,
      :CU_AD_FORMAT_SNORM_INT8X4, 0xc8,
      :CU_AD_FORMAT_SNORM_INT16X1, 0xc9,
      :CU_AD_FORMAT_SNORM_INT16X2, 0xca,
      :CU_AD_FORMAT_SNORM_INT16X4, 0xcb,
      :CU_AD_FORMAT_BC1_UNORM, 0x91,
      :CU_AD_FORMAT_BC1_UNORM_SRGB, 0x92,
      :CU_AD_FORMAT_BC2_UNORM, 0x93,
      :CU_AD_FORMAT_BC2_UNORM_SRGB, 0x94,
      :CU_AD_FORMAT_BC3_UNORM, 0x95,
      :CU_AD_FORMAT_BC3_UNORM_SRGB, 0x96,
      :CU_AD_FORMAT_BC4_UNORM, 0x97,
      :CU_AD_FORMAT_BC4_SNORM, 0x98,
      :CU_AD_FORMAT_BC5_UNORM, 0x99,
      :CU_AD_FORMAT_BC5_SNORM, 0x9a,
      :CU_AD_FORMAT_BC6H_UF16, 0x9b,
      :CU_AD_FORMAT_BC6H_SF16, 0x9c,
      :CU_AD_FORMAT_BC7_UNORM, 0x9d,
      :CU_AD_FORMAT_BC7_UNORM_SRGB, 0x9e,
      :CU_AD_FORMAT_P010, 0x9f,
      :CU_AD_FORMAT_P016, 0xa1,
      :CU_AD_FORMAT_NV16, 0xa2,
      :CU_AD_FORMAT_P210, 0xa3,
      :CU_AD_FORMAT_P216, 0xa4,
      :CU_AD_FORMAT_YUY2, 0xa5,
      :CU_AD_FORMAT_Y210, 0xa6,
      :CU_AD_FORMAT_Y216, 0xa7,
      :CU_AD_FORMAT_AYUV, 0xa8,
      :CU_AD_FORMAT_Y410, 0xa9,
      :CU_AD_FORMAT_Y416, 0xb1,
      :CU_AD_FORMAT_Y444_PLANAR8, 0xb2,
      :CU_AD_FORMAT_Y444_PLANAR10, 0xb3,
      :CU_AD_FORMAT_YUV444_8bit_SemiPlanar, 0xb4,
      :CU_AD_FORMAT_YUV444_16bit_SemiPlanar, 0xb5,
      :CU_AD_FORMAT_UNORM_INT_101010_2, 0x50,
      :CU_AD_FORMAT_MAX, 0x7fffffff ]

  CUAddressMode = cudaenum :cu_address_mode,
    [ :CU_TR_ADDRESS_MODE_WRAP, 0,
      :CU_TR_ADDRESS_MODE_CLAMP, 1,
      :CU_TR_ADDRESS_MODE_MIRROR, 2,
      :CU_TR_ADDRESS_MODE_BORDER, 3 ]

  CUFilterMode = cudaenum :cu_filter_mode,
    [ :CU_TR_FILTER_MODE_POINT, 0,
      :CU_TR_FILTER_MODE_LINEAR, 1 ]

  CUDeviceAttribute = cudaenum :cu_device_attribute,
    [ :CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_BLOCK, 1,
      :CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_X, 2,
      :CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Y, 3,
      :CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Z, 4,
      :CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_X, 5,
      :CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Y, 6,
      :CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Z, 7,
      :CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK, 8,
      :CU_DEVICE_ATTRIBUTE_SHARED_MEMORY_PER_BLOCK, 8,
      :CU_DEVICE_ATTRIBUTE_TOTAL_CONSTANT_MEMORY, 9,
      :CU_DEVICE_ATTRIBUTE_WARP_SIZE, 10,
      :CU_DEVICE_ATTRIBUTE_MAX_PITCH, 11,
      :CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_BLOCK, 12,
      :CU_DEVICE_ATTRIBUTE_REGISTERS_PER_BLOCK, 12,
      :CU_DEVICE_ATTRIBUTE_CLOCK_RATE, 13,
      :CU_DEVICE_ATTRIBUTE_TEXTURE_ALIGNMENT, 14,
      :CU_DEVICE_ATTRIBUTE_GPU_OVERLAP, 15,
      :CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT, 16,
      :CU_DEVICE_ATTRIBUTE_KERNEL_EXEC_TIMEOUT, 17,
      :CU_DEVICE_ATTRIBUTE_INTEGRATED, 18,
      :CU_DEVICE_ATTRIBUTE_CAN_MAP_HOST_MEMORY, 19,
      :CU_DEVICE_ATTRIBUTE_COMPUTE_MODE, 20,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_WIDTH, 21,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_WIDTH, 22,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_HEIGHT, 23,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_WIDTH, 24,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_HEIGHT, 25,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_DEPTH, 26,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_WIDTH, 27,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_HEIGHT, 28,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_LAYERS, 29,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_WIDTH, 27,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_HEIGHT, 28,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_NUMSLICES, 29,
      :CU_DEVICE_ATTRIBUTE_SURFACE_ALIGNMENT, 30,
      :CU_DEVICE_ATTRIBUTE_CONCURRENT_KERNELS, 31,
      :CU_DEVICE_ATTRIBUTE_ECC_ENABLED, 32,
      :CU_DEVICE_ATTRIBUTE_PCI_BUS_ID, 33,
      :CU_DEVICE_ATTRIBUTE_PCI_DEVICE_ID, 34,
      :CU_DEVICE_ATTRIBUTE_TCC_DRIVER, 35,
      :CU_DEVICE_ATTRIBUTE_MEMORY_CLOCK_RATE, 36,
      :CU_DEVICE_ATTRIBUTE_GLOBAL_MEMORY_BUS_WIDTH, 37,
      :CU_DEVICE_ATTRIBUTE_L2_CACHE_SIZE, 38,
      :CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_MULTIPROCESSOR, 39,
      :CU_DEVICE_ATTRIBUTE_ASYNC_ENGINE_COUNT, 40,
      :CU_DEVICE_ATTRIBUTE_UNIFIED_ADDRESSING, 41,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_LAYERED_WIDTH, 42,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_LAYERED_LAYERS, 43,
      :CU_DEVICE_ATTRIBUTE_CAN_TEX2D_GATHER, 44,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_GATHER_WIDTH, 45,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_GATHER_HEIGHT, 46,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_WIDTH_ALTERNATE, 47,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_HEIGHT_ALTERNATE, 48,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_DEPTH_ALTERNATE, 49,
      :CU_DEVICE_ATTRIBUTE_PCI_DOMAIN_ID, 50,
      :CU_DEVICE_ATTRIBUTE_TEXTURE_PITCH_ALIGNMENT, 51,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURECUBEMAP_WIDTH, 52,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURECUBEMAP_LAYERED_WIDTH, 53,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURECUBEMAP_LAYERED_LAYERS, 54,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE1D_WIDTH, 55,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_WIDTH, 56,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_HEIGHT, 57,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE3D_WIDTH, 58,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE3D_HEIGHT, 59,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE3D_DEPTH, 60,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE1D_LAYERED_WIDTH, 61,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE1D_LAYERED_LAYERS, 62,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_LAYERED_WIDTH, 63,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_LAYERED_HEIGHT, 64,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_LAYERED_LAYERS, 65,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACECUBEMAP_WIDTH, 66,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACECUBEMAP_LAYERED_WIDTH, 67,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACECUBEMAP_LAYERED_LAYERS, 68,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_LINEAR_WIDTH, 69,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LINEAR_WIDTH, 70,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LINEAR_HEIGHT, 71,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LINEAR_PITCH, 72,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_MIPMAPPED_WIDTH, 73,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_MIPMAPPED_HEIGHT, 74,
      :CU_DEVICE_ATTRIBUTE_COMPUTE_CAPABILITY_MAJOR, 75,
      :CU_DEVICE_ATTRIBUTE_COMPUTE_CAPABILITY_MINOR, 76,
      :CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_MIPMAPPED_WIDTH, 77,
      :CU_DEVICE_ATTRIBUTE_STREAM_PRIORITIES_SUPPORTED, 78,
      :CU_DEVICE_ATTRIBUTE_GLOBAL_L1_CACHE_SUPPORTED, 79,
      :CU_DEVICE_ATTRIBUTE_LOCAL_L1_CACHE_SUPPORTED, 80,
      :CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_MULTIPROCESSOR, 81,
      :CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_MULTIPROCESSOR, 82,
      :CU_DEVICE_ATTRIBUTE_MANAGED_MEMORY, 83,
      :CU_DEVICE_ATTRIBUTE_MULTI_GPU_BOARD, 84,
      :CU_DEVICE_ATTRIBUTE_MULTI_GPU_BOARD_GROUP_ID, 85,
      :CU_DEVICE_ATTRIBUTE_HOST_NATIVE_ATOMIC_SUPPORTED, 86,
      :CU_DEVICE_ATTRIBUTE_SINGLE_TO_DOUBLE_PRECISION_PERF_RATIO, 87,
      :CU_DEVICE_ATTRIBUTE_PAGEABLE_MEMORY_ACCESS, 88,
      :CU_DEVICE_ATTRIBUTE_CONCURRENT_MANAGED_ACCESS, 89,
      :CU_DEVICE_ATTRIBUTE_COMPUTE_PREEMPTION_SUPPORTED, 90,
      :CU_DEVICE_ATTRIBUTE_CAN_USE_HOST_POINTER_FOR_REGISTERED_MEM, 91,
      :CU_DEVICE_ATTRIBUTE_CAN_USE_STREAM_MEM_OPS_V1, 92,
      :CU_DEVICE_ATTRIBUTE_CAN_USE_64_BIT_STREAM_MEM_OPS_V1, 93,
      :CU_DEVICE_ATTRIBUTE_CAN_USE_STREAM_WAIT_VALUE_NOR_V1, 94,
      :CU_DEVICE_ATTRIBUTE_COOPERATIVE_LAUNCH, 95,
      :CU_DEVICE_ATTRIBUTE_COOPERATIVE_MULTI_DEVICE_LAUNCH, 96,
      :CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK_OPTIN, 97,
      :CU_DEVICE_ATTRIBUTE_CAN_FLUSH_REMOTE_WRITES, 98,
      :CU_DEVICE_ATTRIBUTE_HOST_REGISTER_SUPPORTED, 99,
      :CU_DEVICE_ATTRIBUTE_PAGEABLE_MEMORY_ACCESS_USES_HOST_PAGE_TABLES, 100,
      :CU_DEVICE_ATTRIBUTE_DIRECT_MANAGED_MEM_ACCESS_FROM_HOST, 101,
      :CU_DEVICE_ATTRIBUTE_VIRTUAL_ADDRESS_MANAGEMENT_SUPPORTED, 102,
      :CU_DEVICE_ATTRIBUTE_VIRTUAL_MEMORY_MANAGEMENT_SUPPORTED, 102,
      :CU_DEVICE_ATTRIBUTE_HANDLE_TYPE_POSIX_FILE_DESCRIPTOR_SUPPORTED, 103,
      :CU_DEVICE_ATTRIBUTE_HANDLE_TYPE_WIN32_HANDLE_SUPPORTED, 104,
      :CU_DEVICE_ATTRIBUTE_HANDLE_TYPE_WIN32_KMT_HANDLE_SUPPORTED, 105,
      :CU_DEVICE_ATTRIBUTE_MAX_BLOCKS_PER_MULTIPROCESSOR, 106,
      :CU_DEVICE_ATTRIBUTE_GENERIC_COMPRESSION_SUPPORTED, 107,
      :CU_DEVICE_ATTRIBUTE_MAX_PERSISTING_L2_CACHE_SIZE, 108,
      :CU_DEVICE_ATTRIBUTE_MAX_ACCESS_POLICY_WINDOW_SIZE, 109,
      :CU_DEVICE_ATTRIBUTE_GPU_DIRECT_RDMA_WITH_CUDA_VMM_SUPPORTED, 110,
      :CU_DEVICE_ATTRIBUTE_RESERVED_SHARED_MEMORY_PER_BLOCK, 111,
      :CU_DEVICE_ATTRIBUTE_SPARSE_CUDA_ARRAY_SUPPORTED, 112,
      :CU_DEVICE_ATTRIBUTE_READ_ONLY_HOST_REGISTER_SUPPORTED, 113,
      :CU_DEVICE_ATTRIBUTE_TIMELINE_SEMAPHORE_INTEROP_SUPPORTED, 114,
      :CU_DEVICE_ATTRIBUTE_MEMORY_POOLS_SUPPORTED, 115,
      :CU_DEVICE_ATTRIBUTE_GPU_DIRECT_RDMA_SUPPORTED, 116,
      :CU_DEVICE_ATTRIBUTE_GPU_DIRECT_RDMA_FLUSH_WRITES_OPTIONS, 117,
      :CU_DEVICE_ATTRIBUTE_GPU_DIRECT_RDMA_WRITES_ORDERING, 118,
      :CU_DEVICE_ATTRIBUTE_MEMPOOL_SUPPORTED_HANDLE_TYPES, 119,
      :CU_DEVICE_ATTRIBUTE_CLUSTER_LAUNCH, 120,
      :CU_DEVICE_ATTRIBUTE_DEFERRED_MAPPING_CUDA_ARRAY_SUPPORTED, 121,
      :CU_DEVICE_ATTRIBUTE_CAN_USE_64_BIT_STREAM_MEM_OPS, 122,
      :CU_DEVICE_ATTRIBUTE_CAN_USE_STREAM_WAIT_VALUE_NOR, 123,
      :CU_DEVICE_ATTRIBUTE_DMA_BUF_SUPPORTED, 124,
      :CU_DEVICE_ATTRIBUTE_IPC_EVENT_SUPPORTED, 125,
      :CU_DEVICE_ATTRIBUTE_MEM_SYNC_DOMAIN_COUNT, 126,
      :CU_DEVICE_ATTRIBUTE_TENSOR_MAP_ACCESS_SUPPORTED, 127,
      :CU_DEVICE_ATTRIBUTE_HANDLE_TYPE_FABRIC_SUPPORTED, 128,
      :CU_DEVICE_ATTRIBUTE_UNIFIED_FUNCTION_POINTERS, 129,
      :CU_DEVICE_ATTRIBUTE_NUMA_CONFIG, 130,
      :CU_DEVICE_ATTRIBUTE_NUMA_ID, 131,
      :CU_DEVICE_ATTRIBUTE_MULTICAST_SUPPORTED, 132,
      :CU_DEVICE_ATTRIBUTE_MPS_ENABLED, 133,
      :CU_DEVICE_ATTRIBUTE_HOST_NUMA_ID, 134,
      :CU_DEVICE_ATTRIBUTE_D3D12_CIG_SUPPORTED, 135,
      :CU_DEVICE_ATTRIBUTE_MEM_DECOMPRESS_ALGORITHM_MASK, 136,
      :CU_DEVICE_ATTRIBUTE_MEM_DECOMPRESS_MAXIMUM_LENGTH, 137,
      :CU_DEVICE_ATTRIBUTE_VULKAN_CIG_SUPPORTED, 138,
      :CU_DEVICE_ATTRIBUTE_GPU_PCI_DEVICE_ID, 139,
      :CU_DEVICE_ATTRIBUTE_GPU_PCI_SUBSYSTEM_ID, 140,
      :CU_DEVICE_ATTRIBUTE_HOST_NUMA_VIRTUAL_MEMORY_MANAGEMENT_SUPPORTED, 141,
      :CU_DEVICE_ATTRIBUTE_HOST_NUMA_MEMORY_POOLS_SUPPORTED, 142,
      :CU_DEVICE_ATTRIBUTE_HOST_NUMA_MULTINODE_IPC_SUPPORTED, 143,
      :CU_DEVICE_ATTRIBUTE_HOST_MEMORY_POOLS_SUPPORTED, 144,
      :CU_DEVICE_ATTRIBUTE_HOST_VIRTUAL_MEMORY_MANAGEMENT_SUPPORTED, 145,
      :CU_DEVICE_ATTRIBUTE_HOST_ALLOC_DMA_BUF_SUPPORTED, 146,
      :CU_DEVICE_ATTRIBUTE_ONLY_PARTIAL_HOST_NATIVE_ATOMIC_SUPPORTED, 147,
      :CU_DEVICE_ATTRIBUTE_MAX ]

  class CUDevpropV1 < FFI::CUDAStruct
    layout :maxThreadsPerBlock, :int,
           :maxThreadsDim, [ :int, 3 ],
           :maxGridSize, [ :int, 3 ],
           :sharedMemPerBlock, :int,
           :totalConstantMemory, :int,
           :SIMDWidth, :int,
           :memPitch, :int,
           :regsPerBlock, :int,
           :clockRate, :int,
           :textureAlign, :int
  end
  typedef CUDevpropV1.by_value, :cu_devprop_v1

  typedef :cu_devprop_v1, :cu_devprop

  CUPointerAttribute = cudaenum :cu_pointer_attribute,
    [ :CU_POINTER_ATTRIBUTE_CONTEXT, 1,
      :CU_POINTER_ATTRIBUTE_MEMORY_TYPE, 2,
      :CU_POINTER_ATTRIBUTE_DEVICE_POINTER, 3,
      :CU_POINTER_ATTRIBUTE_HOST_POINTER, 4,
      :CU_POINTER_ATTRIBUTE_P2P_TOKENS, 5,
      :CU_POINTER_ATTRIBUTE_SYNC_MEMOPS, 6,
      :CU_POINTER_ATTRIBUTE_BUFFER_ID, 7,
      :CU_POINTER_ATTRIBUTE_IS_MANAGED, 8,
      :CU_POINTER_ATTRIBUTE_DEVICE_ORDINAL, 9,
      :CU_POINTER_ATTRIBUTE_IS_LEGACY_CUDA_IPC_CAPABLE, 10,
      :CU_POINTER_ATTRIBUTE_RANGE_START_ADDR, 11,
      :CU_POINTER_ATTRIBUTE_RANGE_SIZE, 12,
      :CU_POINTER_ATTRIBUTE_MAPPED, 13,
      :CU_POINTER_ATTRIBUTE_ALLOWED_HANDLE_TYPES, 14,
      :CU_POINTER_ATTRIBUTE_IS_GPU_DIRECT_RDMA_CAPABLE, 15,
      :CU_POINTER_ATTRIBUTE_ACCESS_FLAGS, 16,
      :CU_POINTER_ATTRIBUTE_MEMPOOL_HANDLE, 17,
      :CU_POINTER_ATTRIBUTE_MAPPING_SIZE, 18,
      :CU_POINTER_ATTRIBUTE_MAPPING_BASE_ADDR, 19,
      :CU_POINTER_ATTRIBUTE_MEMORY_BLOCK_ID, 20,
      :CU_POINTER_ATTRIBUTE_IS_HW_DECOMPRESS_CAPABLE, 21 ]

  CUFunctionAttribute = cudaenum :cu_function_attribute,
    [ :CU_FUNC_ATTRIBUTE_MAX_THREADS_PER_BLOCK, 0,
      :CU_FUNC_ATTRIBUTE_SHARED_SIZE_BYTES, 1,
      :CU_FUNC_ATTRIBUTE_CONST_SIZE_BYTES, 2,
      :CU_FUNC_ATTRIBUTE_LOCAL_SIZE_BYTES, 3,
      :CU_FUNC_ATTRIBUTE_NUM_REGS, 4,
      :CU_FUNC_ATTRIBUTE_PTX_VERSION, 5,
      :CU_FUNC_ATTRIBUTE_BINARY_VERSION, 6,
      :CU_FUNC_ATTRIBUTE_CACHE_MODE_CA, 7,
      :CU_FUNC_ATTRIBUTE_MAX_DYNAMIC_SHARED_SIZE_BYTES, 8,
      :CU_FUNC_ATTRIBUTE_PREFERRED_SHARED_MEMORY_CARVEOUT, 9,
      :CU_FUNC_ATTRIBUTE_CLUSTER_SIZE_MUST_BE_SET, 10,
      :CU_FUNC_ATTRIBUTE_REQUIRED_CLUSTER_WIDTH, 11,
      :CU_FUNC_ATTRIBUTE_REQUIRED_CLUSTER_HEIGHT, 12,
      :CU_FUNC_ATTRIBUTE_REQUIRED_CLUSTER_DEPTH, 13,
      :CU_FUNC_ATTRIBUTE_NON_PORTABLE_CLUSTER_SIZE_ALLOWED, 14,
      :CU_FUNC_ATTRIBUTE_CLUSTER_SCHEDULING_POLICY_PREFERENCE, 15,
      :CU_FUNC_ATTRIBUTE_MAX ]

  CUFuncCache = cudaenum :cu_func_cache,
    [ :CU_FUNC_CACHE_PREFER_NONE, 0x0,
      :CU_FUNC_CACHE_PREFER_SHARED, 0x1,
      :CU_FUNC_CACHE_PREFER_L1, 0x2,
      :CU_FUNC_CACHE_PREFER_EQUAL, 0x3 ]

  CUSharedconfig = cudaenum :cu_sharedconfig,
    [ :CU_SHARED_MEM_CONFIG_DEFAULT_BANK_SIZE, 0x0,
      :CU_SHARED_MEM_CONFIG_FOUR_BYTE_BANK_SIZE, 0x1,
      :CU_SHARED_MEM_CONFIG_EIGHT_BYTE_BANK_SIZE, 0x2 ]

  CUSharedCarveout = cudaenum :cu_shared_carveout,
    [ :CU_SHAREDMEM_CARVEOUT_DEFAULT, -1,
      :CU_SHAREDMEM_CARVEOUT_MAX_SHARED, 100,
      :CU_SHAREDMEM_CARVEOUT_MAX_L1, 0 ]

  CUMemorytype = cudaenum :cu_memorytype,
    [ :CU_MEMORYTYPE_HOST, 0x1,
      :CU_MEMORYTYPE_DEVICE, 0x2,
      :CU_MEMORYTYPE_ARRAY, 0x3,
      :CU_MEMORYTYPE_UNIFIED, 0x4 ]

  CUComputemode = cudaenum :cu_computemode,
    [ :CU_COMPUTEMODE_DEFAULT, 0,
      :CU_COMPUTEMODE_PROHIBITED, 2,
      :CU_COMPUTEMODE_EXCLUSIVE_PROCESS, 3 ]

  CUMemAdvise = cudaenum :cu_mem_advise,
    [ :CU_MEM_ADVISE_SET_READ_MOSTLY, 1,
      :CU_MEM_ADVISE_UNSET_READ_MOSTLY, 2,
      :CU_MEM_ADVISE_SET_PREFERRED_LOCATION, 3,
      :CU_MEM_ADVISE_UNSET_PREFERRED_LOCATION, 4,
      :CU_MEM_ADVISE_SET_ACCESSED_BY, 5,
      :CU_MEM_ADVISE_UNSET_ACCESSED_BY, 6 ]

  CUMemRangeAttribute = cudaenum :cu_mem_range_attribute,
    [ :CU_MEM_RANGE_ATTRIBUTE_READ_MOSTLY, 1,
      :CU_MEM_RANGE_ATTRIBUTE_PREFERRED_LOCATION, 2,
      :CU_MEM_RANGE_ATTRIBUTE_ACCESSED_BY, 3,
      :CU_MEM_RANGE_ATTRIBUTE_LAST_PREFETCH_LOCATION, 4,
      :CU_MEM_RANGE_ATTRIBUTE_PREFERRED_LOCATION_TYPE, 5,
      :CU_MEM_RANGE_ATTRIBUTE_PREFERRED_LOCATION_ID, 6,
      :CU_MEM_RANGE_ATTRIBUTE_LAST_PREFETCH_LOCATION_TYPE, 7,
      :CU_MEM_RANGE_ATTRIBUTE_LAST_PREFETCH_LOCATION_ID, 8 ]

  CUJitOption = cudaenum :cu_jit_option,
    [ :CU_JIT_MAX_REGISTERS, 0,
      :CU_JIT_THREADS_PER_BLOCK, 1,
      :CU_JIT_WALL_TIME, 2,
      :CU_JIT_INFO_LOG_BUFFER, 3,
      :CU_JIT_INFO_LOG_BUFFER_SIZE_BYTES, 4,
      :CU_JIT_ERROR_LOG_BUFFER, 5,
      :CU_JIT_ERROR_LOG_BUFFER_SIZE_BYTES, 6,
      :CU_JIT_OPTIMIZATION_LEVEL, 7,
      :CU_JIT_TARGET_FROM_CUCONTEXT, 8,
      :CU_JIT_TARGET, 9,
      :CU_JIT_FALLBACK_STRATEGY, 10,
      :CU_JIT_GENERATE_DEBUG_INFO, 11,
      :CU_JIT_LOG_VERBOSE, 12,
      :CU_JIT_GENERATE_LINE_INFO, 13,
      :CU_JIT_CACHE_MODE, 14,
      :CU_JIT_NEW_SM3X_OPT, 15,
      :CU_JIT_FAST_COMPILE, 16,
      :CU_JIT_GLOBAL_SYMBOL_NAMES, 17,
      :CU_JIT_GLOBAL_SYMBOL_ADDRESSES, 18,
      :CU_JIT_GLOBAL_SYMBOL_COUNT, 19,
      :CU_JIT_LTO, 20,
      :CU_JIT_FTZ, 21,
      :CU_JIT_PREC_DIV, 22,
      :CU_JIT_PREC_SQRT, 23,
      :CU_JIT_FMA, 24,
      :CU_JIT_REFERENCED_KERNEL_NAMES, 25,
      :CU_JIT_REFERENCED_KERNEL_COUNT, 26,
      :CU_JIT_REFERENCED_VARIABLE_NAMES, 27,
      :CU_JIT_REFERENCED_VARIABLE_COUNT, 28,
      :CU_JIT_OPTIMIZE_UNUSED_DEVICE_VARIABLES, 29,
      :CU_JIT_POSITION_INDEPENDENT_CODE, 30,
      :CU_JIT_MIN_CTA_PER_SM, 31,
      :CU_JIT_MAX_THREADS_PER_BLOCK, 32,
      :CU_JIT_OVERRIDE_DIRECTIVE_VALUES, 33,
      :CU_JIT_SPLIT_COMPILE, 34,
      :CU_JIT_NUM_OPTIONS ]

  CUJitTarget = cudaenum :cu_jit_target,
    [ :CU_TARGET_COMPUTE_30, 30,
      :CU_TARGET_COMPUTE_32, 32,
      :CU_TARGET_COMPUTE_35, 35,
      :CU_TARGET_COMPUTE_37, 37,
      :CU_TARGET_COMPUTE_50, 50,
      :CU_TARGET_COMPUTE_52, 52,
      :CU_TARGET_COMPUTE_53, 53,
      :CU_TARGET_COMPUTE_60, 60,
      :CU_TARGET_COMPUTE_61, 61,
      :CU_TARGET_COMPUTE_62, 62,
      :CU_TARGET_COMPUTE_70, 70,
      :CU_TARGET_COMPUTE_72, 72,
      :CU_TARGET_COMPUTE_75, 75,
      :CU_TARGET_COMPUTE_80, 80,
      :CU_TARGET_COMPUTE_86, 86,
      :CU_TARGET_COMPUTE_87, 87,
      :CU_TARGET_COMPUTE_89, 89,
      :CU_TARGET_COMPUTE_90, 90,
      :CU_TARGET_COMPUTE_100, 100,
      :CU_TARGET_COMPUTE_110, 110,
      :CU_TARGET_COMPUTE_103, 103,
      :CU_TARGET_COMPUTE_120, 120,
      :CU_TARGET_COMPUTE_121, 121,
      :CU_TARGET_COMPUTE_90A, CU_COMPUTE_ACCELERATED_TARGET_BASE + CU_TARGET_COMPUTE_90,
      :CU_TARGET_COMPUTE_100A, CU_COMPUTE_ACCELERATED_TARGET_BASE + CU_TARGET_COMPUTE_100,
      :CU_TARGET_COMPUTE_110A, CU_COMPUTE_ACCELERATED_TARGET_BASE + CU_TARGET_COMPUTE_110,
      :CU_TARGET_COMPUTE_103A, CU_COMPUTE_ACCELERATED_TARGET_BASE + CU_TARGET_COMPUTE_103,
      :CU_TARGET_COMPUTE_120A, CU_COMPUTE_ACCELERATED_TARGET_BASE + CU_TARGET_COMPUTE_120,
      :CU_TARGET_COMPUTE_121A, CU_COMPUTE_ACCELERATED_TARGET_BASE + CU_TARGET_COMPUTE_121,
      :CU_TARGET_COMPUTE_100F, CU_COMPUTE_FAMILY_TARGET_BASE + CU_TARGET_COMPUTE_100,
      :CU_TARGET_COMPUTE_110F, CU_COMPUTE_FAMILY_TARGET_BASE + CU_TARGET_COMPUTE_110,
      :CU_TARGET_COMPUTE_103F, CU_COMPUTE_FAMILY_TARGET_BASE + CU_TARGET_COMPUTE_103,
      :CU_TARGET_COMPUTE_120F, CU_COMPUTE_FAMILY_TARGET_BASE + CU_TARGET_COMPUTE_120,
      :CU_TARGET_COMPUTE_121F, CU_COMPUTE_FAMILY_TARGET_BASE + CU_TARGET_COMPUTE_121 ]

  CUJitFallback = cudaenum :cu_jit_fallback,
    [ :CU_PREFER_PTX, 0,
      :CU_PREFER_BINARY ]

  CUJitCacheMode = cudaenum :cu_jit_cache_mode,
    [ :CU_JIT_CACHE_OPTION_NONE, 0,
      :CU_JIT_CACHE_OPTION_CG,
      :CU_JIT_CACHE_OPTION_CA ]

  CUJitInputType = cudaenum :cu_jit_input_type,
    [ :CU_JIT_INPUT_CUBIN, 0,
      :CU_JIT_INPUT_PTX, 1,
      :CU_JIT_INPUT_FATBINARY, 2,
      :CU_JIT_INPUT_OBJECT, 3,
      :CU_JIT_INPUT_LIBRARY, 4,
      :CU_JIT_INPUT_NVVM, 5,
      :CU_JIT_NUM_INPUT_TYPES, 6 ]

  typedef :pointer, :cu_link_state

  CUGraphicsRegisterFlags = cudaenum :cu_graphics_register_flags,
    [ :CU_GRAPHICS_REGISTER_FLAGS_NONE, 0x0,
      :CU_GRAPHICS_REGISTER_FLAGS_READ_ONLY, 0x1,
      :CU_GRAPHICS_REGISTER_FLAGS_WRITE_DISCARD, 0x2,
      :CU_GRAPHICS_REGISTER_FLAGS_SURFACE_LDST, 0x4,
      :CU_GRAPHICS_REGISTER_FLAGS_TEXTURE_GATHER, 0x8 ]

  CUGraphicsMapResourceFlags = cudaenum :cu_graphics_map_resource_flags,
    [ :CU_GRAPHICS_MAP_RESOURCE_FLAGS_NONE, 0x0,
      :CU_GRAPHICS_MAP_RESOURCE_FLAGS_READ_ONLY, 0x1,
      :CU_GRAPHICS_MAP_RESOURCE_FLAGS_WRITE_DISCARD, 0x2 ]

  CUArrayCubemapFace = cudaenum :cu_array_cubemap_face,
    [ :CU_CUBEMAP_FACE_POSITIVE_X, 0x0,
      :CU_CUBEMAP_FACE_NEGATIVE_X, 0x1,
      :CU_CUBEMAP_FACE_POSITIVE_Y, 0x2,
      :CU_CUBEMAP_FACE_NEGATIVE_Y, 0x3,
      :CU_CUBEMAP_FACE_POSITIVE_Z, 0x4,
      :CU_CUBEMAP_FACE_NEGATIVE_Z, 0x5 ]

  CULimit = cudaenum :cu_limit,
    [ :CU_LIMIT_STACK_SIZE, 0x0,
      :CU_LIMIT_PRINTF_FIFO_SIZE, 0x1,
      :CU_LIMIT_MALLOC_HEAP_SIZE, 0x2,
      :CU_LIMIT_DEV_RUNTIME_SYNC_DEPTH, 0x3,
      :CU_LIMIT_DEV_RUNTIME_PENDING_LAUNCH_COUNT, 0x4,
      :CU_LIMIT_MAX_L2_FETCH_GRANULARITY, 0x5,
      :CU_LIMIT_PERSISTING_L2_CACHE_SIZE, 0x6,
      :CU_LIMIT_SHMEM_SIZE, 0x7,
      :CU_LIMIT_CIG_ENABLED, 0x8,
      :CU_LIMIT_CIG_SHMEM_FALLBACK_ENABLED, 0x9,
      :CU_LIMIT_MAX ]

  CUResourcetype = cudaenum :cu_resourcetype,
    [ :CU_RESOURCE_TYPE_ARRAY, 0x0,
      :CU_RESOURCE_TYPE_MIPMAPPED_ARRAY, 0x1,
      :CU_RESOURCE_TYPE_LINEAR, 0x2,
      :CU_RESOURCE_TYPE_PITCH2D, 0x3 ]

  callback :cu_host_fn,
           [ :pointer ],
           :void

  CUAccessProperty = cudaenum :cu_access_property,
    [ :CU_ACCESS_PROPERTY_NORMAL, 0,
      :CU_ACCESS_PROPERTY_STREAMING, 1,
      :CU_ACCESS_PROPERTY_PERSISTING, 2 ]

  class CUAccessPolicyWindowV1 < FFI::CUDAStruct
    layout :base_ptr, :pointer,
           :num_bytes, :size_t,
           :hitRatio, :float,
           :hitProp, :cu_access_property,
           :missProp, :cu_access_property
  end
  typedef CUAccessPolicyWindowV1.by_value, :cu_access_policy_window_v1

  typedef :cu_access_policy_window_v1, :cu_access_policy_window

  class CUDAKERNELNODEPARAMSV1 < FFI::CUDAStruct
    layout :func, :cu_function,
           :gridDimX, :uint,
           :gridDimY, :uint,
           :gridDimZ, :uint,
           :blockDimX, :uint,
           :blockDimY, :uint,
           :blockDimZ, :uint,
           :sharedMemBytes, :uint,
           :kernelParams, :pointer,
           :extra, :pointer
  end
  typedef CUDAKERNELNODEPARAMSV1.by_value, :cuda_kernelnodeparamsv1

  class CUDAKERNELNODEPARAMSV2 < FFI::CUDAStruct
    layout :func, :cu_function,
           :gridDimX, :uint,
           :gridDimY, :uint,
           :gridDimZ, :uint,
           :blockDimX, :uint,
           :blockDimY, :uint,
           :blockDimZ, :uint,
           :sharedMemBytes, :uint,
           :kernelParams, :pointer,
           :extra, :pointer,
           :kern, :cu_kernel,
           :ctx, :cu_context
  end
  typedef CUDAKERNELNODEPARAMSV2.by_value, :cuda_kernelnodeparamsv2

  typedef :cuda_kernelnodeparamsv2, :cuda_kernelnodeparams

  class CUDAKERNELNODEPARAMSV3 < FFI::CUDAStruct
    layout :func, :cu_function,
           :gridDimX, :uint,
           :gridDimY, :uint,
           :gridDimZ, :uint,
           :blockDimX, :uint,
           :blockDimY, :uint,
           :blockDimZ, :uint,
           :sharedMemBytes, :uint,
           :kernelParams, :pointer,
           :extra, :pointer,
           :kern, :cu_kernel,
           :ctx, :cu_context
  end
  typedef CUDAKERNELNODEPARAMSV3.by_value, :cuda_kernelnodeparamsv3

  class CUDAMEMSETNODEPARAMSV1 < FFI::CUDAStruct
    layout :dst, :cu_deviceptr,
           :pitch, :size_t,
           :value, :uint,
           :elementSize, :uint,
           :width, :size_t,
           :height, :size_t
  end
  typedef CUDAMEMSETNODEPARAMSV1.by_value, :cuda_memsetnodeparamsv1

  typedef :cuda_memsetnodeparamsv1, :cuda_memsetnodeparams

  class CUDAMEMSETNODEPARAMSV2 < FFI::CUDAStruct
    layout :dst, :cu_deviceptr,
           :pitch, :size_t,
           :value, :uint,
           :elementSize, :uint,
           :width, :size_t,
           :height, :size_t,
           :ctx, :cu_context
  end
  typedef CUDAMEMSETNODEPARAMSV2.by_value, :cuda_memsetnodeparamsv2

  class CUDAHOSTNODEPARAMSV1 < FFI::CUDAStruct
    layout :fn, :cu_host_fn,
           :userData, :pointer
  end
  typedef CUDAHOSTNODEPARAMSV1.by_value, :cuda_hostnodeparamsv1

  typedef :cuda_hostnodeparamsv1, :cuda_hostnodeparams

  class CUDAHOSTNODEPARAMSV2 < FFI::CUDAStruct
    layout :fn, :cu_host_fn,
           :userData, :pointer
  end
  typedef CUDAHOSTNODEPARAMSV2.by_value, :cuda_hostnodeparamsv2

  CUGraphConditionalNodeType = cudaenum :cu_graph_conditional_node_type,
    [ :CU_GRAPH_COND_TYPE_IF, 0,
      :CU_GRAPH_COND_TYPE_WHILE, 1,
      :CU_GRAPH_COND_TYPE_SWITCH, 2 ]

  class CUDACONDITIONALNODEPARAMS < FFI::CUDAStruct
    layout :handle, :cu_graph_conditional_handle,
           :type, :cu_graph_conditional_node_type,
           :size, :uint,
           :phGraph_out, :pointer,
           :ctx, :cu_context
  end
  typedef CUDACONDITIONALNODEPARAMS.by_value, :cuda_conditionalnodeparams

  CUGraphNodeType = cudaenum :cu_graph_node_type,
    [ :CU_GRAPH_NODE_TYPE_KERNEL, 0,
      :CU_GRAPH_NODE_TYPE_MEMCPY, 1,
      :CU_GRAPH_NODE_TYPE_MEMSET, 2,
      :CU_GRAPH_NODE_TYPE_HOST, 3,
      :CU_GRAPH_NODE_TYPE_GRAPH, 4,
      :CU_GRAPH_NODE_TYPE_EMPTY, 5,
      :CU_GRAPH_NODE_TYPE_WAIT_EVENT, 6,
      :CU_GRAPH_NODE_TYPE_EVENT_RECORD, 7,
      :CU_GRAPH_NODE_TYPE_EXT_SEMAS_SIGNAL, 8,
      :CU_GRAPH_NODE_TYPE_EXT_SEMAS_WAIT, 9,
      :CU_GRAPH_NODE_TYPE_MEM_ALLOC, 10,
      :CU_GRAPH_NODE_TYPE_MEM_FREE, 11,
      :CU_GRAPH_NODE_TYPE_BATCH_MEM_OP, 12,
      :CU_GRAPH_NODE_TYPE_CONDITIONAL, 13 ]

  CUGraphDependencyType = cudaenum :cu_graph_dependency_type,
    [ :CU_GRAPH_DEPENDENCY_TYPE_DEFAULT, 0,
      :CU_GRAPH_DEPENDENCY_TYPE_PROGRAMMATIC, 1 ]

  class CUGraphEdgeData < FFI::CUDAStruct
    layout :from_port, :uchar,
           :to_port, :uchar,
           :type, :uchar,
           :reserved, [ :uchar, 5 ]
  end
  typedef CUGraphEdgeData.by_value, :cu_graph_edge_data

  CUGraphInstantiateResult = cudaenum :cu_graph_instantiate_result,
    [ :CUDA_GRAPH_INSTANTIATE_SUCCESS, 0,
      :CUDA_GRAPH_INSTANTIATE_ERROR, 1,
      :CUDA_GRAPH_INSTANTIATE_INVALID_STRUCTURE, 2,
      :CUDA_GRAPH_INSTANTIATE_NODE_OPERATION_NOT_SUPPORTED, 3,
      :CUDA_GRAPH_INSTANTIATE_MULTIPLE_CTXS_NOT_SUPPORTED, 4,
      :CUDA_GRAPH_INSTANTIATE_CONDITIONAL_HANDLE_UNUSED, 5 ]

  class CUDAGRAPHINSTANTIATEPARAMS < FFI::CUDAStruct
    layout :flags, :cuuint64_t,
           :hUploadStream, :cu_stream,
           :hErrNode_out, :cu_graph_node,
           :result_out, :cu_graph_instantiate_result
  end
  typedef CUDAGRAPHINSTANTIATEPARAMS.by_value, :cuda_graphinstantiateparams

  CUSynchronizationPolicy = cudaenum :cu_synchronization_policy,
    [ :CU_SYNC_POLICY_AUTO, 1,
      :CU_SYNC_POLICY_SPIN, 2,
      :CU_SYNC_POLICY_YIELD, 3,
      :CU_SYNC_POLICY_BLOCKING_SYNC, 4 ]

  CUClusterSchedulingPolicy = cudaenum :cu_cluster_scheduling_policy,
    [ :CU_CLUSTER_SCHEDULING_POLICY_DEFAULT, 0,
      :CU_CLUSTER_SCHEDULING_POLICY_SPREAD, 1,
      :CU_CLUSTER_SCHEDULING_POLICY_LOAD_BALANCING, 2 ]

  CULaunchMemSyncDomain = cudaenum :cu_launch_mem_sync_domain,
    [ :CU_LAUNCH_MEM_SYNC_DOMAIN_DEFAULT, 0,
      :CU_LAUNCH_MEM_SYNC_DOMAIN_REMOTE, 1 ]

  class CULaunchMemSyncDomainMap < FFI::CUDAStruct
    layout :default_, :uchar,
           :remote, :uchar
  end
  typedef CULaunchMemSyncDomainMap.by_value, :cu_launch_mem_sync_domain_map

  CULaunchAttributeID = cudaenum :cu_launch_attribute_id,
    [ :CU_LAUNCH_ATTRIBUTE_IGNORE, 0,
      :CU_LAUNCH_ATTRIBUTE_ACCESS_POLICY_WINDOW, 1,
      :CU_LAUNCH_ATTRIBUTE_COOPERATIVE, 2,
      :CU_LAUNCH_ATTRIBUTE_SYNCHRONIZATION_POLICY, 3,
      :CU_LAUNCH_ATTRIBUTE_CLUSTER_DIMENSION, 4,
      :CU_LAUNCH_ATTRIBUTE_CLUSTER_SCHEDULING_POLICY_PREFERENCE, 5,
      :CU_LAUNCH_ATTRIBUTE_PROGRAMMATIC_STREAM_SERIALIZATION, 6,
      :CU_LAUNCH_ATTRIBUTE_PROGRAMMATIC_EVENT, 7,
      :CU_LAUNCH_ATTRIBUTE_PRIORITY, 8,
      :CU_LAUNCH_ATTRIBUTE_MEM_SYNC_DOMAIN_MAP, 9,
      :CU_LAUNCH_ATTRIBUTE_MEM_SYNC_DOMAIN, 10,
      :CU_LAUNCH_ATTRIBUTE_PREFERRED_CLUSTER_DIMENSION, 11,
      :CU_LAUNCH_ATTRIBUTE_LAUNCH_COMPLETION_EVENT, 12,
      :CU_LAUNCH_ATTRIBUTE_DEVICE_UPDATABLE_KERNEL_NODE, 13,
      :CU_LAUNCH_ATTRIBUTE_PREFERRED_SHARED_MEMORY_CARVEOUT, 14,
      :CU_LAUNCH_ATTRIBUTE_NVLINK_UTIL_CENTRIC_SCHEDULING, 16,
      :CU_LAUNCH_ATTRIBUTE_MAX ]

  class CULaunchAttributeValue < FFI::CUDAUnion
    layout :pad, [ :char, 64 ],
           :accessPolicyWindow, :cu_access_policy_window,
           :cooperative, :int,
           :syncPolicy, :cu_synchronization_policy,
           :clusterDim, (Class::new(FFI::CUDAStruct) { layout :x, :uint, :y, :uint, :z, :uint }.by_value),
           :clusterSchedulingPolicyPreference, :cu_cluster_scheduling_policy,
           :programmaticStreamSerializationAllowed, :int,
           :programmaticEvent, (Class::new(FFI::CUDAStruct) { layout :event, :cu_event, :flags, :int, :triggerAtBlockStart, :int }.by_value),
           :launchCompletionEvent, (Class::new(FFI::CUDAStruct) { layout :event, :cu_event, :flags, :int }.by_value),
           :priority, :int,
           :memSyncDomainMap, :cu_launch_mem_sync_domain_map,
           :memSyncDomain, :cu_launch_mem_sync_domain,
           :preferredClusterDim, (Class::new(FFI::CUDAStruct) { layout :x, :uint, :y, :uint, :z, :uint }.by_value),
           :deviceUpdatableKernelNode, (Class::new(FFI::CUDAStruct) { layout :deviceUpdatable, :int, :devNode, :cu_graph_device_node }.by_value),
           :sharedMemCarveout, :uint,
           :nvlinkUtilCentricScheduling, :uint
  end
  typedef CULaunchAttributeValue.by_value, :cu_launch_attribute_value

  class CULaunchAttribute < FFI::CUDAStruct
    layout :id, :cu_launch_attribute_id,
           :pad, [ :char, 8 - 4 ],
           :value, :cu_launch_attribute_value
  end
  typedef CULaunchAttribute.by_value, :cu_launch_attribute

  class CULaunchConfig < FFI::CUDAStruct
    layout :gridDimX, :uint,
           :gridDimY, :uint,
           :gridDimZ, :uint,
           :blockDimX, :uint,
           :blockDimY, :uint,
           :blockDimZ, :uint,
           :sharedMemBytes, :uint,
           :hStream, :cu_stream,
           :attrs, :pointer,
           :numAttrs, :uint
  end
  typedef CULaunchConfig.by_value, :cu_launch_config

  CUStreamCaptureStatus = cudaenum :cu_stream_capture_status,
    [ :CU_STREAM_CAPTURE_STATUS_NONE, 0,
      :CU_STREAM_CAPTURE_STATUS_ACTIVE, 1,
      :CU_STREAM_CAPTURE_STATUS_INVALIDATED, 2 ]

  CUStreamCaptureMode = cudaenum :cu_stream_capture_mode,
    [ :CU_STREAM_CAPTURE_MODE_GLOBAL, 0,
      :CU_STREAM_CAPTURE_MODE_THREAD_LOCAL, 1,
      :CU_STREAM_CAPTURE_MODE_RELAXED, 2 ]

  CUDriverProcAddressFlags = cudaenum :cu_driver_proc_address_flags,
    [ :CU_GET_PROC_ADDRESS_DEFAULT, 0,
      :CU_GET_PROC_ADDRESS_LEGACY_STREAM, 1 << 0,
      :CU_GET_PROC_ADDRESS_PER_THREAD_DEFAULT_STREAM, 1 << 1 ]

  CUDriverProcAddressQueryResult = cudaenum :cu_driver_proc_address_query_result,
    [ :CU_GET_PROC_ADDRESS_SUCCESS, 0,
      :CU_GET_PROC_ADDRESS_SYMBOL_NOT_FOUND, 1,
      :CU_GET_PROC_ADDRESS_VERSION_NOT_SUFFICIENT, 2 ]

  CUExecAffinityType = cudaenum :cu_exec_affinity_type,
    [ :CU_EXEC_AFFINITY_TYPE_SM_COUNT, 0,
      :CU_EXEC_AFFINITY_TYPE_MAX ]

  class CUExecAffinitySmCountV1 < FFI::CUDAStruct
    layout :val, :uint
  end
  typedef CUExecAffinitySmCountV1.by_value, :cu_exec_affinity_sm_count_v1

  typedef :cu_exec_affinity_sm_count_v1, :cu_exec_affinity_sm_count

  class CUExecAffinityParamV1 < FFI::CUDAStruct
    layout :type, :cu_exec_affinity_type,
           :param, (Class::new(FFI::CUDAUnion) { layout :smCount, :cu_exec_affinity_sm_count }.by_value)
  end
  typedef CUExecAffinityParamV1.by_value, :cu_exec_affinity_param_v1

  typedef :cu_exec_affinity_param_v1, :cu_exec_affinity_param

  CUCigDataType = cudaenum :cu_cig_data_type,
    [ :CIG_DATA_TYPE_D3D12_COMMAND_QUEUE, 0x1,
      :CIG_DATA_TYPE_NV_BLOB, 0x2 ]

  class CUCtxCigParam < FFI::CUDAStruct
    layout :sharedDataType, :cu_cig_data_type,
           :sharedData, :pointer
  end
  typedef CUCtxCigParam.by_value, :cu_ctx_cig_param

  class CUCtxCreateParams < FFI::CUDAStruct
    layout :execAffinityParams, :pointer,
           :numExecAffinityParams, :int,
           :cigParams, :pointer
  end
  typedef CUCtxCreateParams.by_value, :cu_ctx_create_params

  CULibraryOption = cudaenum :cu_library_option,
    [ :CU_LIBRARY_HOST_UNIVERSAL_FUNCTION_AND_DATA_TABLE, 0,
      :CU_LIBRARY_BINARY_IS_PRESERVED, 1,
      :CU_LIBRARY_NUM_OPTIONS ]

  class CULibraryHostUniversalFunctionAndDataTable < FFI::CUDAStruct
    layout :functionTable, :pointer,
           :functionWindowSize, :size_t,
           :dataTable, :pointer,
           :dataWindowSize, :size_t
  end
  typedef CULibraryHostUniversalFunctionAndDataTable.by_value, :cu_library_host_universal_function_and_data_table

  CUResult = cudaenum :cu_result,
    [ :CUDA_SUCCESS, 0,
      :CUDA_ERROR_INVALID_VALUE, 1,
      :CUDA_ERROR_OUT_OF_MEMORY, 2,
      :CUDA_ERROR_NOT_INITIALIZED, 3,
      :CUDA_ERROR_DEINITIALIZED, 4,
      :CUDA_ERROR_PROFILER_DISABLED, 5,
      :CUDA_ERROR_PROFILER_NOT_INITIALIZED, 6,
      :CUDA_ERROR_PROFILER_ALREADY_STARTED, 7,
      :CUDA_ERROR_PROFILER_ALREADY_STOPPED, 8,
      :CUDA_ERROR_STUB_LIBRARY, 34,
      :CUDA_ERROR_CALL_REQUIRES_NEWER_DRIVER, 36,
      :CUDA_ERROR_DEVICE_UNAVAILABLE, 46,
      :CUDA_ERROR_NO_DEVICE, 100,
      :CUDA_ERROR_INVALID_DEVICE, 101,
      :CUDA_ERROR_DEVICE_NOT_LICENSED, 102,
      :CUDA_ERROR_INVALID_IMAGE, 200,
      :CUDA_ERROR_INVALID_CONTEXT, 201,
      :CUDA_ERROR_CONTEXT_ALREADY_CURRENT, 202,
      :CUDA_ERROR_MAP_FAILED, 205,
      :CUDA_ERROR_UNMAP_FAILED, 206,
      :CUDA_ERROR_ARRAY_IS_MAPPED, 207,
      :CUDA_ERROR_ALREADY_MAPPED, 208,
      :CUDA_ERROR_NO_BINARY_FOR_GPU, 209,
      :CUDA_ERROR_ALREADY_ACQUIRED, 210,
      :CUDA_ERROR_NOT_MAPPED, 211,
      :CUDA_ERROR_NOT_MAPPED_AS_ARRAY, 212,
      :CUDA_ERROR_NOT_MAPPED_AS_POINTER, 213,
      :CUDA_ERROR_ECC_UNCORRECTABLE, 214,
      :CUDA_ERROR_UNSUPPORTED_LIMIT, 215,
      :CUDA_ERROR_CONTEXT_ALREADY_IN_USE, 216,
      :CUDA_ERROR_PEER_ACCESS_UNSUPPORTED, 217,
      :CUDA_ERROR_INVALID_PTX, 218,
      :CUDA_ERROR_INVALID_GRAPHICS_CONTEXT, 219,
      :CUDA_ERROR_NVLINK_UNCORRECTABLE, 220,
      :CUDA_ERROR_JIT_COMPILER_NOT_FOUND, 221,
      :CUDA_ERROR_UNSUPPORTED_PTX_VERSION, 222,
      :CUDA_ERROR_JIT_COMPILATION_DISABLED, 223,
      :CUDA_ERROR_UNSUPPORTED_EXEC_AFFINITY, 224,
      :CUDA_ERROR_UNSUPPORTED_DEVSIDE_SYNC, 225,
      :CUDA_ERROR_CONTAINED, 226,
      :CUDA_ERROR_INVALID_SOURCE, 300,
      :CUDA_ERROR_FILE_NOT_FOUND, 301,
      :CUDA_ERROR_SHARED_OBJECT_SYMBOL_NOT_FOUND, 302,
      :CUDA_ERROR_SHARED_OBJECT_INIT_FAILED, 303,
      :CUDA_ERROR_OPERATING_SYSTEM, 304,
      :CUDA_ERROR_INVALID_HANDLE, 400,
      :CUDA_ERROR_ILLEGAL_STATE, 401,
      :CUDA_ERROR_LOSSY_QUERY, 402,
      :CUDA_ERROR_NOT_FOUND, 500,
      :CUDA_ERROR_NOT_READY, 600,
      :CUDA_ERROR_ILLEGAL_ADDRESS, 700,
      :CUDA_ERROR_LAUNCH_OUT_OF_RESOURCES, 701,
      :CUDA_ERROR_LAUNCH_TIMEOUT, 702,
      :CUDA_ERROR_LAUNCH_INCOMPATIBLE_TEXTURING, 703,
      :CUDA_ERROR_PEER_ACCESS_ALREADY_ENABLED, 704,
      :CUDA_ERROR_PEER_ACCESS_NOT_ENABLED, 705,
      :CUDA_ERROR_PRIMARY_CONTEXT_ACTIVE, 708,
      :CUDA_ERROR_CONTEXT_IS_DESTROYED, 709,
      :CUDA_ERROR_ASSERT, 710,
      :CUDA_ERROR_TOO_MANY_PEERS, 711,
      :CUDA_ERROR_HOST_MEMORY_ALREADY_REGISTERED, 712,
      :CUDA_ERROR_HOST_MEMORY_NOT_REGISTERED, 713,
      :CUDA_ERROR_HARDWARE_STACK_ERROR, 714,
      :CUDA_ERROR_ILLEGAL_INSTRUCTION, 715,
      :CUDA_ERROR_MISALIGNED_ADDRESS, 716,
      :CUDA_ERROR_INVALID_ADDRESS_SPACE, 717,
      :CUDA_ERROR_INVALID_PC, 718,
      :CUDA_ERROR_LAUNCH_FAILED, 719,
      :CUDA_ERROR_COOPERATIVE_LAUNCH_TOO_LARGE, 720,
      :CUDA_ERROR_TENSOR_MEMORY_LEAK, 721,
      :CUDA_ERROR_NOT_PERMITTED, 800,
      :CUDA_ERROR_NOT_SUPPORTED, 801,
      :CUDA_ERROR_SYSTEM_NOT_READY, 802,
      :CUDA_ERROR_SYSTEM_DRIVER_MISMATCH, 803,
      :CUDA_ERROR_COMPAT_NOT_SUPPORTED_ON_DEVICE, 804,
      :CUDA_ERROR_MPS_CONNECTION_FAILED, 805,
      :CUDA_ERROR_MPS_RPC_FAILURE, 806,
      :CUDA_ERROR_MPS_SERVER_NOT_READY, 807,
      :CUDA_ERROR_MPS_MAX_CLIENTS_REACHED, 808,
      :CUDA_ERROR_MPS_MAX_CONNECTIONS_REACHED, 809,
      :CUDA_ERROR_MPS_CLIENT_TERMINATED, 810,
      :CUDA_ERROR_CDP_NOT_SUPPORTED, 811,
      :CUDA_ERROR_CDP_VERSION_MISMATCH, 812,
      :CUDA_ERROR_STREAM_CAPTURE_UNSUPPORTED, 900,
      :CUDA_ERROR_STREAM_CAPTURE_INVALIDATED, 901,
      :CUDA_ERROR_STREAM_CAPTURE_MERGE, 902,
      :CUDA_ERROR_STREAM_CAPTURE_UNMATCHED, 903,
      :CUDA_ERROR_STREAM_CAPTURE_UNJOINED, 904,
      :CUDA_ERROR_STREAM_CAPTURE_ISOLATION, 905,
      :CUDA_ERROR_STREAM_CAPTURE_IMPLICIT, 906,
      :CUDA_ERROR_CAPTURED_EVENT, 907,
      :CUDA_ERROR_STREAM_CAPTURE_WRONG_THREAD, 908,
      :CUDA_ERROR_TIMEOUT, 909,
      :CUDA_ERROR_GRAPH_EXEC_UPDATE_FAILURE, 910,
      :CUDA_ERROR_EXTERNAL_DEVICE, 911,
      :CUDA_ERROR_INVALID_CLUSTER_SIZE, 912,
      :CUDA_ERROR_FUNCTION_NOT_LOADED, 913,
      :CUDA_ERROR_INVALID_RESOURCE_TYPE, 914,
      :CUDA_ERROR_INVALID_RESOURCE_CONFIGURATION, 915,
      :CUDA_ERROR_KEY_ROTATION, 916,
      :CUDA_ERROR_UNKNOWN, 999 ]

  CUDeviceP2PAttribute = cudaenum :cu_device_p2pattribute,
    [ :CU_DEVICE_P2P_ATTRIBUTE_PERFORMANCE_RANK, 0x1,
      :CU_DEVICE_P2P_ATTRIBUTE_ACCESS_SUPPORTED, 0x2,
      :CU_DEVICE_P2P_ATTRIBUTE_NATIVE_ATOMIC_SUPPORTED, 0x3,
      :CU_DEVICE_P2P_ATTRIBUTE_ACCESS_ACCESS_SUPPORTED, 0x4,
      :CU_DEVICE_P2P_ATTRIBUTE_CUDA_ARRAY_ACCESS_SUPPORTED, 0x4,
      :CU_DEVICE_P2P_ATTRIBUTE_ONLY_PARTIAL_NATIVE_ATOMIC_SUPPORTED, 0x5 ]

  CUAtomicOperation = cudaenum :cu_atomic_operation,
    [ :CU_ATOMIC_OPERATION_INTEGER_ADD, 0,
      :CU_ATOMIC_OPERATION_INTEGER_MIN, 1,
      :CU_ATOMIC_OPERATION_INTEGER_MAX, 2,
      :CU_ATOMIC_OPERATION_INTEGER_INCREMENT, 3,
      :CU_ATOMIC_OPERATION_INTEGER_DECREMENT, 4,
      :CU_ATOMIC_OPERATION_AND, 5,
      :CU_ATOMIC_OPERATION_OR, 6,
      :CU_ATOMIC_OPERATION_XOR, 7,
      :CU_ATOMIC_OPERATION_EXCHANGE, 8,
      :CU_ATOMIC_OPERATION_CAS, 9,
      :CU_ATOMIC_OPERATION_FLOAT_ADD, 10,
      :CU_ATOMIC_OPERATION_FLOAT_MIN, 11,
      :CU_ATOMIC_OPERATION_FLOAT_MAX, 12,
      :CU_ATOMIC_OPERATION_MAX ]

  CUAtomicOperationCapability = cudaenum :cu_atomic_operation_capability,
    [ :CU_ATOMIC_CAPABILITY_SIGNED, 1 << 0,
      :CU_ATOMIC_CAPABILITY_UNSIGNED, 1 << 1,
      :CU_ATOMIC_CAPABILITY_REDUCTION, 1 << 2,
      :CU_ATOMIC_CAPABILITY_SCALAR_32, 1 << 3,
      :CU_ATOMIC_CAPABILITY_SCALAR_64, 1 << 4,
      :CU_ATOMIC_CAPABILITY_SCALAR_128, 1 << 5,
      :CU_ATOMIC_CAPABILITY_VECTOR_32x4, 1 << 6 ]

  callback :cu_stream_callback,
           [ :cu_stream,
             :cu_result,
             :pointer ],
           :void

  callback :cu_occupancy_b2dsize,
           [ :int ],
           :size_t

  class CUDAMEMCPY2DV2 < FFI::CUDAStruct
    layout :srcXInBytes, :size_t,
           :srcY, :size_t,
           :srcMemoryType, :cu_memorytype,
           :srcHost, :pointer,
           :srcDevice, :cu_deviceptr,
           :srcArray, :cu_array,
           :srcPitch, :size_t,
           :dstXInBytes, :size_t,
           :dstY, :size_t,
           :dstMemoryType, :cu_memorytype,
           :dstHost, :pointer,
           :dstDevice, :cu_deviceptr,
           :dstArray, :cu_array,
           :dstPitch, :size_t,
           :WidthInBytes, :size_t,
           :Height, :size_t
  end
  typedef CUDAMEMCPY2DV2.by_value, :cuda_memcpy2dv2

  typedef :cuda_memcpy2dv2, :cuda_memcpy2d

  class CUDAMEMCPY3DV2 < FFI::CUDAStruct
    layout :srcXInBytes, :size_t,
           :srcY, :size_t,
           :srcZ, :size_t,
           :srcLOD, :size_t,
           :srcMemoryType, :cu_memorytype,
           :srcHost, :pointer,
           :srcDevice, :cu_deviceptr,
           :srcArray, :cu_array,
           :reserved0, :pointer,
           :srcPitch, :size_t,
           :srcHeight, :size_t,
           :dstXInBytes, :size_t,
           :dstY, :size_t,
           :dstZ, :size_t,
           :dstLOD, :size_t,
           :dstMemoryType, :cu_memorytype,
           :dstHost, :pointer,
           :dstDevice, :cu_deviceptr,
           :dstArray, :cu_array,
           :reserved1, :pointer,
           :dstPitch, :size_t,
           :dstHeight, :size_t,
           :WidthInBytes, :size_t,
           :Height, :size_t,
           :Depth, :size_t
  end
  typedef CUDAMEMCPY3DV2.by_value, :cuda_memcpy3dv2

  typedef :cuda_memcpy3dv2, :cuda_memcpy3d

  class CUDAMEMCPY3DPEERV1 < FFI::CUDAStruct
    layout :srcXInBytes, :size_t,
           :srcY, :size_t,
           :srcZ, :size_t,
           :srcLOD, :size_t,
           :srcMemoryType, :cu_memorytype,
           :srcHost, :pointer,
           :srcDevice, :cu_deviceptr,
           :srcArray, :cu_array,
           :srcContext, :cu_context,
           :srcPitch, :size_t,
           :srcHeight, :size_t,
           :dstXInBytes, :size_t,
           :dstY, :size_t,
           :dstZ, :size_t,
           :dstLOD, :size_t,
           :dstMemoryType, :cu_memorytype,
           :dstHost, :pointer,
           :dstDevice, :cu_deviceptr,
           :dstArray, :cu_array,
           :dstContext, :cu_context,
           :dstPitch, :size_t,
           :dstHeight, :size_t,
           :WidthInBytes, :size_t,
           :Height, :size_t,
           :Depth, :size_t
  end
  typedef CUDAMEMCPY3DPEERV1.by_value, :cuda_memcpy3dpeerv1

  typedef :cuda_memcpy3dpeerv1, :cuda_memcpy3dpeer

  class CUDAMEMCPYNODEPARAMS < FFI::CUDAStruct
    layout :flags, :int,
           :reserved, :int,
           :copyCtx, :cu_context,
           :copyParams, :cuda_memcpy3d
  end
  typedef CUDAMEMCPYNODEPARAMS.by_value, :cuda_memcpynodeparams

  class CUDAARRAYDESCRIPTORV2 < FFI::CUDAStruct
    layout :Width, :size_t,
           :Height, :size_t,
           :Format, :cu_array_format,
           :NumChannels, :uint
  end
  typedef CUDAARRAYDESCRIPTORV2.by_value, :cuda_arraydescriptorv2

  typedef :cuda_arraydescriptorv2, :cuda_arraydescriptor

  class CUDAARRAY3DDESCRIPTORV2 < FFI::CUDAStruct
    layout :Width, :size_t,
           :Height, :size_t,
           :Depth, :size_t,
           :Format, :cu_array_format,
           :NumChannels, :uint,
           :Flags, :uint
  end
  typedef CUDAARRAY3DDESCRIPTORV2.by_value, :cuda_array3ddescriptorv2

  typedef :cuda_array3ddescriptorv2, :cuda_array3ddescriptor

  class CUDAARRAYSPARSEPROPERTIESV1 < FFI::CUDAStruct
    layout :tileExtent, (Class::new(FFI::CUDAStruct) { layout :width, :uint, :height, :uint, :depth, :uint }.by_value),
           :miptailFirstLevel, :uint,
           :miptailSize, :uint64,
           :flags, :uint,
           :reserved, [ :uint, 4 ]
  end
  typedef CUDAARRAYSPARSEPROPERTIESV1.by_value, :cuda_arraysparsepropertiesv1

  typedef :cuda_arraysparsepropertiesv1, :cuda_arraysparseproperties

  class CUDAARRAYMEMORYREQUIREMENTSV1 < FFI::CUDAStruct
    layout :size, :size_t,
           :alignment, :size_t,
           :reserved, [ :uint, 4 ]
  end
  typedef CUDAARRAYMEMORYREQUIREMENTSV1.by_value, :cuda_arraymemoryrequirementsv1

  typedef :cuda_arraymemoryrequirementsv1, :cuda_arraymemoryrequirements

  class CUDARESOURCEDESCV1 < FFI::CUDAStruct
    layout :resType, :cu_resourcetype,
           :res, (Class::new(FFI::CUDAUnion) { layout :array, (Class::new(FFI::CUDAStruct) { layout :hArray, :cu_array }.by_value), :mipmap, (Class::new(FFI::CUDAStruct) { layout :hMipmappedArray, :cu_mipmapped_array }.by_value), :linear, (Class::new(FFI::CUDAStruct) { layout :devPtr, :cu_deviceptr, :format, :cu_array_format, :numChannels, :uint, :sizeInBytes, :size_t }.by_value), :pitch2D, (Class::new(FFI::CUDAStruct) { layout :devPtr, :cu_deviceptr, :format, :cu_array_format, :numChannels, :uint, :width, :size_t, :height, :size_t, :pitchInBytes, :size_t }.by_value), :reserved, (Class::new(FFI::CUDAStruct) { layout :reserved, [ :int, 32 ] }.by_value) }.by_value),
           :flags, :uint
  end
  typedef CUDARESOURCEDESCV1.by_value, :cuda_resourcedescv1

  typedef :cuda_resourcedescv1, :cuda_resourcedesc

  class CUDATEXTUREDESCV1 < FFI::CUDAStruct
    layout :addressMode, [ :cu_address_mode, 3 ],
           :filterMode, :cu_filter_mode,
           :flags, :uint,
           :maxAnisotropy, :uint,
           :mipmapFilterMode, :cu_filter_mode,
           :mipmapLevelBias, :float,
           :minMipmapLevelClamp, :float,
           :maxMipmapLevelClamp, :float,
           :borderColor, [ :float, 4 ],
           :reserved, [ :int, 12 ]
  end
  typedef CUDATEXTUREDESCV1.by_value, :cuda_texturedescv1

  typedef :cuda_texturedescv1, :cuda_texturedesc

  CUResourceViewFormat = cudaenum :cu_resource_view_format,
    [ :CU_RES_VIEW_FORMAT_NONE, 0x0,
      :CU_RES_VIEW_FORMAT_UINT_1X8, 0x1,
      :CU_RES_VIEW_FORMAT_UINT_2X8, 0x2,
      :CU_RES_VIEW_FORMAT_UINT_4X8, 0x3,
      :CU_RES_VIEW_FORMAT_SINT_1X8, 0x4,
      :CU_RES_VIEW_FORMAT_SINT_2X8, 0x5,
      :CU_RES_VIEW_FORMAT_SINT_4X8, 0x6,
      :CU_RES_VIEW_FORMAT_UINT_1X16, 0x7,
      :CU_RES_VIEW_FORMAT_UINT_2X16, 0x8,
      :CU_RES_VIEW_FORMAT_UINT_4X16, 0x9,
      :CU_RES_VIEW_FORMAT_SINT_1X16, 0xa,
      :CU_RES_VIEW_FORMAT_SINT_2X16, 0xb,
      :CU_RES_VIEW_FORMAT_SINT_4X16, 0xc,
      :CU_RES_VIEW_FORMAT_UINT_1X32, 0xd,
      :CU_RES_VIEW_FORMAT_UINT_2X32, 0xe,
      :CU_RES_VIEW_FORMAT_UINT_4X32, 0xf,
      :CU_RES_VIEW_FORMAT_SINT_1X32, 0x10,
      :CU_RES_VIEW_FORMAT_SINT_2X32, 0x11,
      :CU_RES_VIEW_FORMAT_SINT_4X32, 0x12,
      :CU_RES_VIEW_FORMAT_FLOAT_1X16, 0x13,
      :CU_RES_VIEW_FORMAT_FLOAT_2X16, 0x14,
      :CU_RES_VIEW_FORMAT_FLOAT_4X16, 0x15,
      :CU_RES_VIEW_FORMAT_FLOAT_1X32, 0x16,
      :CU_RES_VIEW_FORMAT_FLOAT_2X32, 0x17,
      :CU_RES_VIEW_FORMAT_FLOAT_4X32, 0x18,
      :CU_RES_VIEW_FORMAT_UNSIGNED_BC1, 0x19,
      :CU_RES_VIEW_FORMAT_UNSIGNED_BC2, 0x1a,
      :CU_RES_VIEW_FORMAT_UNSIGNED_BC3, 0x1b,
      :CU_RES_VIEW_FORMAT_UNSIGNED_BC4, 0x1c,
      :CU_RES_VIEW_FORMAT_SIGNED_BC4, 0x1d,
      :CU_RES_VIEW_FORMAT_UNSIGNED_BC5, 0x1e,
      :CU_RES_VIEW_FORMAT_SIGNED_BC5, 0x1f,
      :CU_RES_VIEW_FORMAT_UNSIGNED_BC6H, 0x20,
      :CU_RES_VIEW_FORMAT_SIGNED_BC6H, 0x21,
      :CU_RES_VIEW_FORMAT_UNSIGNED_BC7, 0x22 ]

  class CUDARESOURCEVIEWDESCV1 < FFI::CUDAStruct
    layout :format, :cu_resource_view_format,
           :width, :size_t,
           :height, :size_t,
           :depth, :size_t,
           :firstMipmapLevel, :uint,
           :lastMipmapLevel, :uint,
           :firstLayer, :uint,
           :lastLayer, :uint,
           :reserved, [ :uint, 16 ]
  end
  typedef CUDARESOURCEVIEWDESCV1.by_value, :cuda_resourceviewdescv1

  typedef :cuda_resourceviewdescv1, :cuda_resourceviewdesc

  class CUTensorMap < FFI::CUDAStruct
    layout :opaque, [ :cuuint64_t, CU_TENSOR_MAP_NUM_QWORDS ]
  end
  typedef CUTensorMap.by_value, :cu_tensor_map

  CUTensorMapDataType = cudaenum :cu_tensor_map_data_type,
    [ :CU_TENSOR_MAP_DATA_TYPE_UINT8, 0,
      :CU_TENSOR_MAP_DATA_TYPE_UINT16,
      :CU_TENSOR_MAP_DATA_TYPE_UINT32,
      :CU_TENSOR_MAP_DATA_TYPE_INT32,
      :CU_TENSOR_MAP_DATA_TYPE_UINT64,
      :CU_TENSOR_MAP_DATA_TYPE_INT64,
      :CU_TENSOR_MAP_DATA_TYPE_FLOAT16,
      :CU_TENSOR_MAP_DATA_TYPE_FLOAT32,
      :CU_TENSOR_MAP_DATA_TYPE_FLOAT64,
      :CU_TENSOR_MAP_DATA_TYPE_BFLOAT16,
      :CU_TENSOR_MAP_DATA_TYPE_FLOAT32_FTZ,
      :CU_TENSOR_MAP_DATA_TYPE_TFLOAT32,
      :CU_TENSOR_MAP_DATA_TYPE_TFLOAT32_FTZ,
      :CU_TENSOR_MAP_DATA_TYPE_16U4_ALIGN8B,
      :CU_TENSOR_MAP_DATA_TYPE_16U4_ALIGN16B,
      :CU_TENSOR_MAP_DATA_TYPE_16U6_ALIGN16B ]

  CUTensorMapInterleave = cudaenum :cu_tensor_map_interleave,
    [ :CU_TENSOR_MAP_INTERLEAVE_NONE, 0,
      :CU_TENSOR_MAP_INTERLEAVE_16B,
      :CU_TENSOR_MAP_INTERLEAVE_32B ]

  CUTensorMapSwizzle = cudaenum :cu_tensor_map_swizzle,
    [ :CU_TENSOR_MAP_SWIZZLE_NONE, 0,
      :CU_TENSOR_MAP_SWIZZLE_32B,
      :CU_TENSOR_MAP_SWIZZLE_64B,
      :CU_TENSOR_MAP_SWIZZLE_128B,
      :CU_TENSOR_MAP_SWIZZLE_128B_ATOM_32B,
      :CU_TENSOR_MAP_SWIZZLE_128B_ATOM_32B_FLIP_8B,
      :CU_TENSOR_MAP_SWIZZLE_128B_ATOM_64B ]

  CUTensorMapL2promotion = cudaenum :cu_tensor_map_l2promotion,
    [ :CU_TENSOR_MAP_L2_PROMOTION_NONE, 0,
      :CU_TENSOR_MAP_L2_PROMOTION_L2_64B,
      :CU_TENSOR_MAP_L2_PROMOTION_L2_128B,
      :CU_TENSOR_MAP_L2_PROMOTION_L2_256B ]

  CUTensorMapFloatOOBfill = cudaenum :cu_tensor_map_float_oobfill,
    [ :CU_TENSOR_MAP_FLOAT_OOB_FILL_NONE, 0,
      :CU_TENSOR_MAP_FLOAT_OOB_FILL_NAN_REQUEST_ZERO_FMA ]

  CUTensorMapIm2ColWideMode = cudaenum :cu_tensor_map_im2_col_wide_mode,
    [ :CU_TENSOR_MAP_IM2COL_WIDE_MODE_W, 0,
      :CU_TENSOR_MAP_IM2COL_WIDE_MODE_W128 ]

  class CUDAPOINTERATTRIBUTEP2PTOKENSV1 < FFI::CUDAStruct
    layout :p2pToken, :uint64,
           :vaSpaceToken, :uint
  end
  typedef CUDAPOINTERATTRIBUTEP2PTOKENSV1.by_value, :cuda_pointerattributep2ptokensv1

  typedef :cuda_pointerattributep2ptokensv1, :cuda_pointerattributep2ptokens

  CUDAPOINTERATTRIBUTEACCESSFLAGS = cudaenum :cuda_pointerattributeaccessflags,
    [ :CU_POINTER_ATTRIBUTE_ACCESS_FLAG_NONE, 0x0,
      :CU_POINTER_ATTRIBUTE_ACCESS_FLAG_READ, 0x1,
      :CU_POINTER_ATTRIBUTE_ACCESS_FLAG_READWRITE, 0x3 ]

  class CUDALAUNCHPARAMSV1 < FFI::CUDAStruct
    layout :function, :cu_function,
           :gridDimX, :uint,
           :gridDimY, :uint,
           :gridDimZ, :uint,
           :blockDimX, :uint,
           :blockDimY, :uint,
           :blockDimZ, :uint,
           :sharedMemBytes, :uint,
           :hStream, :cu_stream,
           :kernelParams, :pointer
  end
  typedef CUDALAUNCHPARAMSV1.by_value, :cuda_launchparamsv1

  typedef :cuda_launchparamsv1, :cuda_launchparams

  CUExternalMemoryHandleType = cudaenum :cu_external_memory_handle_type,
    [ :CU_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD, 1,
      :CU_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32, 2,
      :CU_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT, 3,
      :CU_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_HEAP, 4,
      :CU_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_RESOURCE, 5,
      :CU_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_RESOURCE, 6,
      :CU_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_RESOURCE_KMT, 7,
      :CU_EXTERNAL_MEMORY_HANDLE_TYPE_NVSCIBUF, 8,
      :CU_EXTERNAL_MEMORY_HANDLE_TYPE_DMABUF_FD, 9 ]

  class CUDAEXTERNALMEMORYHANDLEDESCV1 < FFI::CUDAStruct
    layout :type, :cu_external_memory_handle_type,
           :handle, (Class::new(FFI::CUDAUnion) { layout :fd, :int, :win32, (Class::new(FFI::CUDAStruct) { layout :handle, :pointer, :name, :pointer }.by_value), :nvSciBufObject, :pointer }.by_value),
           :size, :uint64,
           :flags, :uint,
           :reserved, [ :uint, 16 ]
  end
  typedef CUDAEXTERNALMEMORYHANDLEDESCV1.by_value, :cuda_externalmemoryhandledescv1

  typedef :cuda_externalmemoryhandledescv1, :cuda_externalmemoryhandledesc

  class CUDAEXTERNALMEMORYBUFFERDESCV1 < FFI::CUDAStruct
    layout :offset, :uint64,
           :size, :uint64,
           :flags, :uint,
           :reserved, [ :uint, 16 ]
  end
  typedef CUDAEXTERNALMEMORYBUFFERDESCV1.by_value, :cuda_externalmemorybufferdescv1

  typedef :cuda_externalmemorybufferdescv1, :cuda_externalmemorybufferdesc

  class CUDAEXTERNALMEMORYMIPMAPPEDARRAYDESCV1 < FFI::CUDAStruct
    layout :offset, :uint64,
           :arrayDesc, :cuda_array3ddescriptor,
           :numLevels, :uint,
           :reserved, [ :uint, 16 ]
  end
  typedef CUDAEXTERNALMEMORYMIPMAPPEDARRAYDESCV1.by_value, :cuda_externalmemorymipmappedarraydescv1

  typedef :cuda_externalmemorymipmappedarraydescv1, :cuda_externalmemorymipmappedarraydesc

  CUExternalSemaphoreHandleType = cudaenum :cu_external_semaphore_handle_type,
    [ :CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD, 1,
      :CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32, 2,
      :CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT, 3,
      :CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE, 4,
      :CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D11_FENCE, 5,
      :CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_NVSCISYNC, 6,
      :CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D11_KEYED_MUTEX, 7,
      :CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D11_KEYED_MUTEX_KMT, 8,
      :CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_TIMELINE_SEMAPHORE_FD, 9,
      :CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_TIMELINE_SEMAPHORE_WIN32, 10 ]

  class CUDAEXTERNALSEMAPHOREHANDLEDESCV1 < FFI::CUDAStruct
    layout :type, :cu_external_semaphore_handle_type,
           :handle, (Class::new(FFI::CUDAUnion) { layout :fd, :int, :win32, (Class::new(FFI::CUDAStruct) { layout :handle, :pointer, :name, :pointer }.by_value), :nvSciSyncObj, :pointer }.by_value),
           :flags, :uint,
           :reserved, [ :uint, 16 ]
  end
  typedef CUDAEXTERNALSEMAPHOREHANDLEDESCV1.by_value, :cuda_externalsemaphorehandledescv1

  typedef :cuda_externalsemaphorehandledescv1, :cuda_externalsemaphorehandledesc

  class CUDAEXTERNALSEMAPHORESIGNALPARAMSV1 < FFI::CUDAStruct
    layout :params, (Class::new(FFI::CUDAStruct) { layout :fence, (Class::new(FFI::CUDAStruct) { layout :value, :uint64 }.by_value), :nvSciSync, (Class::new(FFI::CUDAUnion) { layout :fence, :pointer, :reserved, :uint64 }.by_value), :keyedMutex, (Class::new(FFI::CUDAStruct) { layout :key, :uint64 }.by_value), :reserved, [ :uint, 12 ] }.by_value),
           :flags, :uint,
           :reserved, [ :uint, 16 ]
  end
  typedef CUDAEXTERNALSEMAPHORESIGNALPARAMSV1.by_value, :cuda_externalsemaphoresignalparamsv1

  typedef :cuda_externalsemaphoresignalparamsv1, :cuda_externalsemaphoresignalparams

  class CUDAEXTERNALSEMAPHOREWAITPARAMSV1 < FFI::CUDAStruct
    layout :params, (Class::new(FFI::CUDAStruct) { layout :fence, (Class::new(FFI::CUDAStruct) { layout :value, :uint64 }.by_value), :nvSciSync, (Class::new(FFI::CUDAUnion) { layout :fence, :pointer, :reserved, :uint64 }.by_value), :keyedMutex, (Class::new(FFI::CUDAStruct) { layout :key, :uint64, :timeoutMs, :uint }.by_value), :reserved, [ :uint, 10 ] }.by_value),
           :flags, :uint,
           :reserved, [ :uint, 16 ]
  end
  typedef CUDAEXTERNALSEMAPHOREWAITPARAMSV1.by_value, :cuda_externalsemaphorewaitparamsv1

  typedef :cuda_externalsemaphorewaitparamsv1, :cuda_externalsemaphorewaitparams

  class CUDAEXTSEMSIGNALNODEPARAMSV1 < FFI::CUDAStruct
    layout :extSemArray, :pointer,
           :paramsArray, :pointer,
           :numExtSems, :uint
  end
  typedef CUDAEXTSEMSIGNALNODEPARAMSV1.by_value, :cuda_extsemsignalnodeparamsv1

  typedef :cuda_extsemsignalnodeparamsv1, :cuda_extsemsignalnodeparams

  class CUDAEXTSEMSIGNALNODEPARAMSV2 < FFI::CUDAStruct
    layout :extSemArray, :pointer,
           :paramsArray, :pointer,
           :numExtSems, :uint
  end
  typedef CUDAEXTSEMSIGNALNODEPARAMSV2.by_value, :cuda_extsemsignalnodeparamsv2

  class CUDAEXTSEMWAITNODEPARAMSV1 < FFI::CUDAStruct
    layout :extSemArray, :pointer,
           :paramsArray, :pointer,
           :numExtSems, :uint
  end
  typedef CUDAEXTSEMWAITNODEPARAMSV1.by_value, :cuda_extsemwaitnodeparamsv1

  typedef :cuda_extsemwaitnodeparamsv1, :cuda_extsemwaitnodeparams

  class CUDAEXTSEMWAITNODEPARAMSV2 < FFI::CUDAStruct
    layout :extSemArray, :pointer,
           :paramsArray, :pointer,
           :numExtSems, :uint
  end
  typedef CUDAEXTSEMWAITNODEPARAMSV2.by_value, :cuda_extsemwaitnodeparamsv2

  CUMemAllocationHandleType = cudaenum :cu_mem_allocation_handle_type,
    [ :CU_MEM_HANDLE_TYPE_NONE, 0x0,
      :CU_MEM_HANDLE_TYPE_POSIX_FILE_DESCRIPTOR, 0x1,
      :CU_MEM_HANDLE_TYPE_WIN32, 0x2,
      :CU_MEM_HANDLE_TYPE_WIN32_KMT, 0x4,
      :CU_MEM_HANDLE_TYPE_FABRIC, 0x8,
      :CU_MEM_HANDLE_TYPE_MAX, 0x7fffffff ]

  CUMemAccessFlags = cudaenum :cu_mem_access_flags,
    [ :CU_MEM_ACCESS_FLAGS_PROT_NONE, 0x0,
      :CU_MEM_ACCESS_FLAGS_PROT_READ, 0x1,
      :CU_MEM_ACCESS_FLAGS_PROT_READWRITE, 0x3,
      :CU_MEM_ACCESS_FLAGS_PROT_MAX, 0x7fffffff ]

  CUMemLocationType = cudaenum :cu_mem_location_type,
    [ :CU_MEM_LOCATION_TYPE_INVALID, 0x0,
      :CU_MEM_LOCATION_TYPE_NONE, 0x0,
      :CU_MEM_LOCATION_TYPE_DEVICE, 0x1,
      :CU_MEM_LOCATION_TYPE_HOST, 0x2,
      :CU_MEM_LOCATION_TYPE_HOST_NUMA, 0x3,
      :CU_MEM_LOCATION_TYPE_HOST_NUMA_CURRENT, 0x4,
      :CU_MEM_LOCATION_TYPE_MAX, 0x7fffffff ]

  CUMemAllocationType = cudaenum :cu_mem_allocation_type,
    [ :CU_MEM_ALLOCATION_TYPE_INVALID, 0x0,
      :CU_MEM_ALLOCATION_TYPE_PINNED, 0x1,
      :CU_MEM_ALLOCATION_TYPE_MANAGED, 0x2,
      :CU_MEM_ALLOCATION_TYPE_MAX, 0x7fffffff ]

  CUMemAllocationGranularityFlags = cudaenum :cu_mem_allocation_granularity_flags,
    [ :CU_MEM_ALLOC_GRANULARITY_MINIMUM, 0x0,
      :CU_MEM_ALLOC_GRANULARITY_RECOMMENDED, 0x1 ]

  CUMemRangeHandleType = cudaenum :cu_mem_range_handle_type,
    [ :CU_MEM_RANGE_HANDLE_TYPE_DMA_BUF_FD, 0x1,
      :CU_MEM_RANGE_HANDLE_TYPE_MAX, 0x7fffffff ]

  CUMemRangeFlags = cudaenum :cu_mem_range_flags,
    [ :CU_MEM_RANGE_FLAG_DMA_BUF_MAPPING_TYPE_PCIE, 0x1 ]

  CUArraySparseSubresourceType = cudaenum :cu_array_sparse_subresource_type,
    [ :CU_ARRAY_SPARSE_SUBRESOURCE_TYPE_SPARSE_LEVEL, 0,
      :CU_ARRAY_SPARSE_SUBRESOURCE_TYPE_MIPTAIL, 1 ]

  CUMemOperationType = cudaenum :cu_mem_operation_type,
    [ :CU_MEM_OPERATION_TYPE_MAP, 1,
      :CU_MEM_OPERATION_TYPE_UNMAP, 2 ]

  CUMemHandleType = cudaenum :cu_mem_handle_type,
    [ :CU_MEM_HANDLE_TYPE_GENERIC, 0 ]

  class CUArrayMapInfoV1 < FFI::CUDAStruct
    layout :resourceType, :cu_resourcetype,
           :resource, (Class::new(FFI::CUDAUnion) { layout :mipmap, :cu_mipmapped_array, :array, :cu_array }.by_value),
           :subresourceType, :cu_array_sparse_subresource_type,
           :subresource, (Class::new(FFI::CUDAUnion) { layout :sparseLevel, (Class::new(FFI::CUDAStruct) { layout :level, :uint, :layer, :uint, :offsetX, :uint, :offsetY, :uint, :offsetZ, :uint, :extentWidth, :uint, :extentHeight, :uint, :extentDepth, :uint }.by_value), :miptail, (Class::new(FFI::CUDAStruct) { layout :layer, :uint, :offset, :uint64, :size, :uint64 }.by_value) }.by_value),
           :memOperationType, :cu_mem_operation_type,
           :memHandleType, :cu_mem_handle_type,
           :memHandle, (Class::new(FFI::CUDAUnion) { layout :memHandle, :cu_mem_generic_allocation_handle }.by_value),
           :offset, :uint64,
           :deviceBitMask, :uint,
           :flags, :uint,
           :reserved, [ :uint, 2 ]
  end
  typedef CUArrayMapInfoV1.by_value, :cu_array_map_info_v1

  typedef :cu_array_map_info_v1, :cu_array_map_info

  class CUMemLocationV1 < FFI::CUDAStruct
    layout :type, :cu_mem_location_type,
           :id, :int
  end
  typedef CUMemLocationV1.by_value, :cu_mem_location_v1

  typedef :cu_mem_location_v1, :cu_mem_location

  CUMemAllocationCompType = cudaenum :cu_mem_allocation_comp_type,
    [ :CU_MEM_ALLOCATION_COMP_NONE, 0x0,
      :CU_MEM_ALLOCATION_COMP_GENERIC, 0x1 ]

  class CUMemAllocationPropV1 < FFI::CUDAStruct
    layout :type, :cu_mem_allocation_type,
           :requestedHandleTypes, :cu_mem_allocation_handle_type,
           :location, :cu_mem_location,
           :win32HandleMetaData, :pointer,
           :allocFlags, (Class::new(FFI::CUDAStruct) { layout :compressionType, :uchar, :gpuDirectRDMACapable, :uchar, :usage, :ushort, :reserved, [ :uchar, 4 ] }.by_value)
  end
  typedef CUMemAllocationPropV1.by_value, :cu_mem_allocation_prop_v1

  typedef :cu_mem_allocation_prop_v1, :cu_mem_allocation_prop

  CUMulticastGranularityFlags = cudaenum :cu_multicast_granularity_flags,
    [ :CU_MULTICAST_GRANULARITY_MINIMUM, 0x0,
      :CU_MULTICAST_GRANULARITY_RECOMMENDED, 0x1 ]

  class CUMulticastObjectPropV1 < FFI::CUDAStruct
    layout :numDevices, :uint,
           :size, :size_t,
           :handleTypes, :uint64,
           :flags, :uint64
  end
  typedef CUMulticastObjectPropV1.by_value, :cu_multicast_object_prop_v1

  typedef :cu_multicast_object_prop_v1, :cu_multicast_object_prop

  class CUMemAccessDescV1 < FFI::CUDAStruct
    layout :location, :cu_mem_location,
           :flags, :cu_mem_access_flags
  end
  typedef CUMemAccessDescV1.by_value, :cu_mem_access_desc_v1

  typedef :cu_mem_access_desc_v1, :cu_mem_access_desc

  CUGraphExecUpdateResult = cudaenum :cu_graph_exec_update_result,
    [ :CU_GRAPH_EXEC_UPDATE_SUCCESS, 0x0,
      :CU_GRAPH_EXEC_UPDATE_ERROR, 0x1,
      :CU_GRAPH_EXEC_UPDATE_ERROR_TOPOLOGY_CHANGED, 0x2,
      :CU_GRAPH_EXEC_UPDATE_ERROR_NODE_TYPE_CHANGED, 0x3,
      :CU_GRAPH_EXEC_UPDATE_ERROR_FUNCTION_CHANGED, 0x4,
      :CU_GRAPH_EXEC_UPDATE_ERROR_PARAMETERS_CHANGED, 0x5,
      :CU_GRAPH_EXEC_UPDATE_ERROR_NOT_SUPPORTED, 0x6,
      :CU_GRAPH_EXEC_UPDATE_ERROR_UNSUPPORTED_FUNCTION_CHANGE, 0x7,
      :CU_GRAPH_EXEC_UPDATE_ERROR_ATTRIBUTES_CHANGED, 0x8 ]

  class CUGraphExecUpdateResultInfoV1 < FFI::CUDAStruct
    layout :result, :cu_graph_exec_update_result,
           :errorNode, :cu_graph_node,
           :errorFromNode, :cu_graph_node
  end
  typedef CUGraphExecUpdateResultInfoV1.by_value, :cu_graph_exec_update_result_info_v1

  typedef :cu_graph_exec_update_result_info_v1, :cu_graph_exec_update_result_info

  CUMemPoolAttribute = cudaenum :cu_mem_pool_attribute,
    [ :CU_MEMPOOL_ATTR_REUSE_FOLLOW_EVENT_DEPENDENCIES, 1,
      :CU_MEMPOOL_ATTR_REUSE_ALLOW_OPPORTUNISTIC,
      :CU_MEMPOOL_ATTR_REUSE_ALLOW_INTERNAL_DEPENDENCIES,
      :CU_MEMPOOL_ATTR_RELEASE_THRESHOLD,
      :CU_MEMPOOL_ATTR_RESERVED_MEM_CURRENT,
      :CU_MEMPOOL_ATTR_RESERVED_MEM_HIGH,
      :CU_MEMPOOL_ATTR_USED_MEM_CURRENT,
      :CU_MEMPOOL_ATTR_USED_MEM_HIGH ]

  class CUMemPoolPropsV1 < FFI::CUDAStruct
    layout :allocType, :cu_mem_allocation_type,
           :handleTypes, :cu_mem_allocation_handle_type,
           :location, :cu_mem_location,
           :win32SecurityAttributes, :pointer,
           :maxSize, :size_t,
           :usage, :ushort,
           :reserved, [ :uchar, 54 ]
  end
  typedef CUMemPoolPropsV1.by_value, :cu_mem_pool_props_v1

  typedef :cu_mem_pool_props_v1, :cu_mem_pool_props

  class CUMemPoolPtrExportDataV1 < FFI::CUDAStruct
    layout :reserved, [ :uchar, 64 ]
  end
  typedef CUMemPoolPtrExportDataV1.by_value, :cu_mem_pool_ptr_export_data_v1

  typedef :cu_mem_pool_ptr_export_data_v1, :cu_mem_pool_ptr_export_data

  CUMemcpyFlags = cudaenum :cu_memcpy_flags,
    [ :CU_MEMCPY_FLAG_DEFAULT, 0x0,
      :CU_MEMCPY_FLAG_PREFER_OVERLAP_WITH_COMPUTE, 0x1 ]

  CUMemcpySrcAccessOrder = cudaenum :cu_memcpy_src_access_order,
    [ :CU_MEMCPY_SRC_ACCESS_ORDER_INVALID, 0x0,
      :CU_MEMCPY_SRC_ACCESS_ORDER_STREAM, 0x1,
      :CU_MEMCPY_SRC_ACCESS_ORDER_DURING_API_CALL, 0x2,
      :CU_MEMCPY_SRC_ACCESS_ORDER_ANY, 0x3,
      :CU_MEMCPY_SRC_ACCESS_ORDER_MAX, 0x7fffffff ]

  class CUMemcpyAttributesV1 < FFI::CUDAStruct
    layout :srcAccessOrder, :cu_memcpy_src_access_order,
           :srcLocHint, :cu_mem_location,
           :dstLocHint, :cu_mem_location,
           :flags, :uint
  end
  typedef CUMemcpyAttributesV1.by_value, :cu_memcpy_attributes_v1

  typedef :cu_memcpy_attributes_v1, :cu_memcpy_attributes

  CUMemcpy3DOperandType = cudaenum :cu_memcpy3_doperand_type,
    [ :CU_MEMCPY_OPERAND_TYPE_POINTER, 0x1,
      :CU_MEMCPY_OPERAND_TYPE_ARRAY, 0x2,
      :CU_MEMCPY_OPERAND_TYPE_MAX, 0x7fffffff ]

  class CUOffset3DV1 < FFI::CUDAStruct
    layout :x, :size_t,
           :y, :size_t,
           :z, :size_t
  end
  typedef CUOffset3DV1.by_value, :cu_offset3_dv1

  typedef :cu_offset3_dv1, :cu_offset3_d

  class CUExtent3DV1 < FFI::CUDAStruct
    layout :width, :size_t,
           :height, :size_t,
           :depth, :size_t
  end
  typedef CUExtent3DV1.by_value, :cu_extent3_dv1

  typedef :cu_extent3_dv1, :cu_extent3_d

  class CUMemcpy3DOperandV1 < FFI::CUDAStruct
    layout :type, :cu_memcpy3_doperand_type,
           :op, (Class::new(FFI::CUDAUnion) { layout :ptr, (Class::new(FFI::CUDAStruct) { layout :ptr, :cu_deviceptr, :rowLength, :size_t, :layerHeight, :size_t, :locHint, :cu_mem_location }.by_value), :array, (Class::new(FFI::CUDAStruct) { layout :array, :cu_array, :offset, :cu_offset3_d }.by_value) }.by_value)
  end
  typedef CUMemcpy3DOperandV1.by_value, :cu_memcpy3_doperand_v1

  typedef :cu_memcpy3_doperand_v1, :cu_memcpy3_doperand

  class CUDAMEMCPY3DBATCHOPV1 < FFI::CUDAStruct
    layout :src, :cu_memcpy3_doperand,
           :dst, :cu_memcpy3_doperand,
           :extent, :cu_extent3_d,
           :srcAccessOrder, :cu_memcpy_src_access_order,
           :flags, :uint
  end
  typedef CUDAMEMCPY3DBATCHOPV1.by_value, :cuda_memcpy3dbatchopv1

  typedef :cuda_memcpy3dbatchopv1, :cuda_memcpy3dbatchop

  class CUDAMEMALLOCNODEPARAMSV1 < FFI::CUDAStruct
    layout :poolProps, :cu_mem_pool_props,
           :accessDescs, :pointer,
           :accessDescCount, :size_t,
           :bytesize, :size_t,
           :dptr, :cu_deviceptr
  end
  typedef CUDAMEMALLOCNODEPARAMSV1.by_value, :cuda_memallocnodeparamsv1

  typedef :cuda_memallocnodeparamsv1, :cuda_memallocnodeparams

  class CUDAMEMALLOCNODEPARAMSV2 < FFI::CUDAStruct
    layout :poolProps, :cu_mem_pool_props,
           :accessDescs, :pointer,
           :accessDescCount, :size_t,
           :bytesize, :size_t,
           :dptr, :cu_deviceptr
  end
  typedef CUDAMEMALLOCNODEPARAMSV2.by_value, :cuda_memallocnodeparamsv2

  class CUDAMEMFREENODEPARAMS < FFI::CUDAStruct
    layout :dptr, :cu_deviceptr
  end
  typedef CUDAMEMFREENODEPARAMS.by_value, :cuda_memfreenodeparams

  CUGraphMemAttribute = cudaenum :cu_graph_mem_attribute,
    [ :CU_GRAPH_MEM_ATTR_USED_MEM_CURRENT,
      :CU_GRAPH_MEM_ATTR_USED_MEM_HIGH,
      :CU_GRAPH_MEM_ATTR_RESERVED_MEM_CURRENT,
      :CU_GRAPH_MEM_ATTR_RESERVED_MEM_HIGH ]

  CUGraphChildGraphNodeOwnership = cudaenum :cu_graph_child_graph_node_ownership,
    [ :CU_GRAPH_CHILD_GRAPH_OWNERSHIP_CLONE, 0,
      :CU_GRAPH_CHILD_GRAPH_OWNERSHIP_MOVE, 1 ]

  class CUDACHILDGRAPHNODEPARAMS < FFI::CUDAStruct
    layout :graph, :cu_graph,
           :ownership, :cu_graph_child_graph_node_ownership
  end
  typedef CUDACHILDGRAPHNODEPARAMS.by_value, :cuda_childgraphnodeparams

  class CUDAEVENTRECORDNODEPARAMS < FFI::CUDAStruct
    layout :event, :cu_event
  end
  typedef CUDAEVENTRECORDNODEPARAMS.by_value, :cuda_eventrecordnodeparams

  class CUDAEVENTWAITNODEPARAMS < FFI::CUDAStruct
    layout :event, :cu_event
  end
  typedef CUDAEVENTWAITNODEPARAMS.by_value, :cuda_eventwaitnodeparams

  class CUGraphNodeParams < FFI::CUDAStruct
    layout :type, :cu_graph_node_type,
           :reserved0, [ :int, 3 ],
           :_unamed_1, (Class::new(FFI::CUDAUnion) { layout :reserved1, [ :int64, 29 ], :kernel, :cuda_kernelnodeparamsv3, :memcpy, :cuda_memcpynodeparams, :memset, :cuda_memsetnodeparamsv2, :host, :cuda_hostnodeparamsv2, :graph, :cuda_childgraphnodeparams, :eventWait, :cuda_eventwaitnodeparams, :eventRecord, :cuda_eventrecordnodeparams, :extSemSignal, :cuda_extsemsignalnodeparamsv2, :extSemWait, :cuda_extsemwaitnodeparamsv2, :alloc, :cuda_memallocnodeparamsv2, :free, :cuda_memfreenodeparams, :memOp, :cuda_batchmemopnodeparamsv2, :conditional, :cuda_conditionalnodeparams }.by_value),
           :reserved2, :int64
  end
  typedef CUGraphNodeParams.by_value, :cu_graph_node_params

  CUFlushGPUDirectRDMAWritesOptions = cudaenum :cu_flush_gpudirect_rdmawrites_options,
    [ :CU_FLUSH_GPU_DIRECT_RDMA_WRITES_OPTION_HOST, 1 << 0,
      :CU_FLUSH_GPU_DIRECT_RDMA_WRITES_OPTION_MEMOPS, 1 << 1 ]

  CUGPUDirectRDMAWritesOrdering = cudaenum :cu_gpudirect_rdmawrites_ordering,
    [ :CU_GPU_DIRECT_RDMA_WRITES_ORDERING_NONE, 0,
      :CU_GPU_DIRECT_RDMA_WRITES_ORDERING_OWNER, 100,
      :CU_GPU_DIRECT_RDMA_WRITES_ORDERING_ALL_DEVICES, 200 ]

  CUFlushGPUDirectRDMAWritesScope = cudaenum :cu_flush_gpudirect_rdmawrites_scope,
    [ :CU_FLUSH_GPU_DIRECT_RDMA_WRITES_TO_OWNER, 100,
      :CU_FLUSH_GPU_DIRECT_RDMA_WRITES_TO_ALL_DEVICES, 200 ]

  CUFlushGPUDirectRDMAWritesTarget = cudaenum :cu_flush_gpudirect_rdmawrites_target,
    [ :CU_FLUSH_GPU_DIRECT_RDMA_WRITES_TARGET_CURRENT_CTX, 0 ]

  CUGraphDebugDotFlags = cudaenum :cu_graph_debug_dot_flags,
    [ :CU_GRAPH_DEBUG_DOT_FLAGS_VERBOSE, 1 << 0,
      :CU_GRAPH_DEBUG_DOT_FLAGS_RUNTIME_TYPES, 1 << 1,
      :CU_GRAPH_DEBUG_DOT_FLAGS_KERNEL_NODE_PARAMS, 1 << 2,
      :CU_GRAPH_DEBUG_DOT_FLAGS_MEMCPY_NODE_PARAMS, 1 << 3,
      :CU_GRAPH_DEBUG_DOT_FLAGS_MEMSET_NODE_PARAMS, 1 << 4,
      :CU_GRAPH_DEBUG_DOT_FLAGS_HOST_NODE_PARAMS, 1 << 5,
      :CU_GRAPH_DEBUG_DOT_FLAGS_EVENT_NODE_PARAMS, 1 << 6,
      :CU_GRAPH_DEBUG_DOT_FLAGS_EXT_SEMAS_SIGNAL_NODE_PARAMS, 1 << 7,
      :CU_GRAPH_DEBUG_DOT_FLAGS_EXT_SEMAS_WAIT_NODE_PARAMS, 1 << 8,
      :CU_GRAPH_DEBUG_DOT_FLAGS_KERNEL_NODE_ATTRIBUTES, 1 << 9,
      :CU_GRAPH_DEBUG_DOT_FLAGS_HANDLES, 1 << 10,
      :CU_GRAPH_DEBUG_DOT_FLAGS_MEM_ALLOC_NODE_PARAMS, 1 << 11,
      :CU_GRAPH_DEBUG_DOT_FLAGS_MEM_FREE_NODE_PARAMS, 1 << 12,
      :CU_GRAPH_DEBUG_DOT_FLAGS_BATCH_MEM_OP_NODE_PARAMS, 1 << 13,
      :CU_GRAPH_DEBUG_DOT_FLAGS_EXTRA_TOPO_INFO, 1 << 14,
      :CU_GRAPH_DEBUG_DOT_FLAGS_CONDITIONAL_NODE_PARAMS, 1 << 15 ]

  CUUserObjectFlags = cudaenum :cu_user_object_flags,
    [ :CU_USER_OBJECT_NO_DESTRUCTOR_SYNC, 1 ]

  CUUserObjectRetainFlags = cudaenum :cu_user_object_retain_flags,
    [ :CU_GRAPH_USER_OBJECT_MOVE, 1 ]

  CUGraphInstantiateFlags = cudaenum :cu_graph_instantiate_flags,
    [ :CUDA_GRAPH_INSTANTIATE_FLAG_AUTO_FREE_ON_LAUNCH, 1,
      :CUDA_GRAPH_INSTANTIATE_FLAG_UPLOAD, 2,
      :CUDA_GRAPH_INSTANTIATE_FLAG_DEVICE_LAUNCH, 4,
      :CUDA_GRAPH_INSTANTIATE_FLAG_USE_NODE_PRIORITY, 8 ]

  CUDeviceNumaConfig = cudaenum :cu_device_numa_config,
    [ :CU_DEVICE_NUMA_CONFIG_NONE, 0,
      :CU_DEVICE_NUMA_CONFIG_NUMA_NODE ]

  CUProcessState = cudaenum :cu_process_state,
    [ :CU_PROCESS_STATE_RUNNING, 0,
      :CU_PROCESS_STATE_LOCKED,
      :CU_PROCESS_STATE_CHECKPOINTED,
      :CU_PROCESS_STATE_FAILED ]

  class CUCheckpointLockArgs < FFI::CUDAStruct
    layout :timeoutMs, :uint,
           :reserved0, :uint,
           :reserved1, [ :cuuint64_t, 7 ]
  end
  typedef CUCheckpointLockArgs.by_value, :cu_checkpoint_lock_args

  class CUCheckpointCheckpointArgs < FFI::CUDAStruct
    layout :reserved, [ :cuuint64_t, 8 ]
  end
  typedef CUCheckpointCheckpointArgs.by_value, :cu_checkpoint_checkpoint_args

  class CUCheckpointGpuPair < FFI::CUDAStruct
    layout :oldUuid, :cu_uuid,
           :newUuid, :cu_uuid
  end
  typedef CUCheckpointGpuPair.by_value, :cu_checkpoint_gpu_pair

  class CUCheckpointRestoreArgs < FFI::CUDAStruct
    layout :gpuPairs, :pointer,
           :gpuPairsCount, :uint,
           :reserved, [ :char, 52 - 8 ],
           :reserved1, :cuuint64_t
  end
  typedef CUCheckpointRestoreArgs.by_value, :cu_checkpoint_restore_args

  class CUCheckpointUnlockArgs < FFI::CUDAStruct
    layout :reserved, [ :cuuint64_t, 8 ]
  end
  typedef CUCheckpointUnlockArgs.by_value, :cu_checkpoint_unlock_args

  CUModuleLoadingMode = cudaenum :cu_module_loading_mode,
    [ :CU_MODULE_EAGER_LOADING, 0x1,
      :CU_MODULE_LAZY_LOADING, 0x2 ]

  CUMemDecompressAlgorithm = cudaenum :cu_mem_decompress_algorithm,
    [ :CU_MEM_DECOMPRESS_UNSUPPORTED, 0,
      :CU_MEM_DECOMPRESS_ALGORITHM_DEFLATE, 1 << 0,
      :CU_MEM_DECOMPRESS_ALGORITHM_SNAPPY, 1 << 1,
      :CU_MEM_DECOMPRESS_ALGORITHM_LZ4, 1 << 2 ]

  class CUMemDecompressParams < FFI::CUDAStruct
    layout :srcNumBytes, :size_t,
           :dstNumBytes, :size_t,
           :dstActBytes, :pointer,
           :src, :pointer,
           :dst, :pointer,
           :algo, :cu_mem_decompress_algorithm,
           :padding, [ :uchar, 20 ]
  end
  typedef CUMemDecompressParams.by_value, :cu_mem_decompress_params

  CUFunctionLoadingState = cudaenum :cu_function_loading_state,
    [ :CU_FUNCTION_LOADING_STATE_UNLOADED, 0,
      :CU_FUNCTION_LOADING_STATE_LOADED, 1,
      :CU_FUNCTION_LOADING_STATE_MAX ]

  CUCoredumpSettings = cudaenum :cu_coredump_settings,
    [ :CU_COREDUMP_ENABLE_ON_EXCEPTION, 1,
      :CU_COREDUMP_TRIGGER_HOST,
      :CU_COREDUMP_LIGHTWEIGHT,
      :CU_COREDUMP_ENABLE_USER_TRIGGER,
      :CU_COREDUMP_FILE,
      :CU_COREDUMP_PIPE,
      :CU_COREDUMP_GENERATION_FLAGS,
      :CU_COREDUMP_MAX ]

  CUCoredumpGenerationFlags = cudaenum :cu_coredump_generation_flags,
    [ :CU_COREDUMP_DEFAULT_FLAGS, 0,
      :CU_COREDUMP_SKIP_NONRELOCATED_ELF_IMAGES, 1 << 0,
      :CU_COREDUMP_SKIP_GLOBAL_MEMORY, 1 << 1,
      :CU_COREDUMP_SKIP_SHARED_MEMORY, 1 << 2,
      :CU_COREDUMP_SKIP_LOCAL_MEMORY, 1 << 3,
      :CU_COREDUMP_SKIP_ABORT, 1 << 4,
      :CU_COREDUMP_SKIP_CONSTBANK_MEMORY, 1 << 5 ]

  typedef :pointer, :cu_dev_resource_desc

  CUGreenCtxCreateFlags = cudaenum :cu_green_ctx_create_flags,
    [ :CU_GREEN_CTX_DEFAULT_STREAM, 0x1 ]

  CUDevSmResourceSplitFlags = cudaenum :cu_dev_sm_resource_split_flags,
    [ :CU_DEV_SM_RESOURCE_SPLIT_IGNORE_SM_COSCHEDULING, 0x1,
      :CU_DEV_SM_RESOURCE_SPLIT_MAX_POTENTIAL_CLUSTER_SIZE, 0x2 ]

  CUDevResourceType = cudaenum :cu_dev_resource_type,
    [ :CU_DEV_RESOURCE_TYPE_INVALID, 0,
      :CU_DEV_RESOURCE_TYPE_SM, 1,
      :CU_DEV_RESOURCE_TYPE_MAX ]

  class CUDevSmResource < FFI::CUDAStruct
    layout :smCount, :uint,
           :minSmPartitionSize, :uint,
           :smCoscheduledAlignment, :uint
  end
  typedef CUDevSmResource.by_value, :cu_dev_sm_resource

  class CUDevResourceV1 < FFI::CUDAStruct
    layout :type, :cu_dev_resource_type,
           :_internal_padding, [ :uchar, 92 ],
           :_unamed_1, (Class::new(FFI::CUDAUnion) { layout :sm, :cu_dev_sm_resource, :_oversize, [ :uchar, RESOURCE_ABI_EXTERNAL_BYTES ] }.by_value)
  end
  typedef CUDevResourceV1.by_value, :cu_dev_resource_v1

  typedef :cu_dev_resource_v1, :cu_dev_resource

  CULogLevel = cudaenum :cu_log_level,
    [ :CU_LOG_LEVEL_ERROR, 0,
      :CU_LOG_LEVEL_WARNING, 1 ]

  typedef :pointer, :cu_logs_callback_handle

  callback :cu_logs_callback,
           [ :pointer,
             :cu_log_level,
             :pointer,
             :size_t ],
           :void

  class CUDAMEMCPY2DV1 < FFI::CUDAStruct
    layout :srcXInBytes, :uint,
           :srcY, :uint,
           :srcMemoryType, :cu_memorytype,
           :srcHost, :pointer,
           :srcDevice, :cu_deviceptr_v1,
           :srcArray, :cu_array,
           :srcPitch, :uint,
           :dstXInBytes, :uint,
           :dstY, :uint,
           :dstMemoryType, :cu_memorytype,
           :dstHost, :pointer,
           :dstDevice, :cu_deviceptr_v1,
           :dstArray, :cu_array,
           :dstPitch, :uint,
           :WidthInBytes, :uint,
           :Height, :uint
  end
  typedef CUDAMEMCPY2DV1.by_value, :cuda_memcpy2dv1

  class CUDAMEMCPY3DV1 < FFI::CUDAStruct
    layout :srcXInBytes, :uint,
           :srcY, :uint,
           :srcZ, :uint,
           :srcLOD, :uint,
           :srcMemoryType, :cu_memorytype,
           :srcHost, :pointer,
           :srcDevice, :cu_deviceptr_v1,
           :srcArray, :cu_array,
           :reserved0, :pointer,
           :srcPitch, :uint,
           :srcHeight, :uint,
           :dstXInBytes, :uint,
           :dstY, :uint,
           :dstZ, :uint,
           :dstLOD, :uint,
           :dstMemoryType, :cu_memorytype,
           :dstHost, :pointer,
           :dstDevice, :cu_deviceptr_v1,
           :dstArray, :cu_array,
           :reserved1, :pointer,
           :dstPitch, :uint,
           :dstHeight, :uint,
           :WidthInBytes, :uint,
           :Height, :uint,
           :Depth, :uint
  end
  typedef CUDAMEMCPY3DV1.by_value, :cuda_memcpy3dv1

  class CUDAARRAYDESCRIPTORV1 < FFI::CUDAStruct
    layout :Width, :uint,
           :Height, :uint,
           :Format, :cu_array_format,
           :NumChannels, :uint
  end
  typedef CUDAARRAYDESCRIPTORV1.by_value, :cuda_arraydescriptorv1

  class CUDAARRAY3DDESCRIPTORV1 < FFI::CUDAStruct
    layout :Width, :uint,
           :Height, :uint,
           :Depth, :uint,
           :Format, :cu_array_format,
           :NumChannels, :uint,
           :Flags, :uint
  end
  typedef CUDAARRAY3DDESCRIPTORV1.by_value, :cuda_array3ddescriptorv1

  CUOutputMode = cudaenum :cu_output_mode,
    [ :CU_OUT_KEY_VALUE_PAIR, 0x0,
      :CU_OUT_CSV, 0x1 ]

  class CuexpFunctionArgDescQuery < FFI::CUDAStruct
    layout :sz, :size_t,
           :argSize, :size_t,
           :argOffset, :size_t,
           :u1, :size_t,
           :u2, :size_t
  end
  typedef CuexpFunctionArgDescQuery.by_value, :cuexp_function_arg_desc_query

  class Cuexp7cb63f9b1e0Struct < FFI::CUDAStruct
    layout :unknown, :int,
           :stride, :uint,
           :countOut, :uint,
           :capacity, :uint,
           :data, :pointer
  end
  typedef Cuexp7cb63f9b1e0Struct.by_value, :cuexp7cb63f9b1e0_struct

end
